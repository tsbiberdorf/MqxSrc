/**HEADER********************************************************************
* 
* Copyright (c) 2008 Freescale Semiconductor;
* All Rights Reserved
*
* Copyright (c) 1989-2008 ARC International;
* All Rights Reserved
*
*************************************************************************** 
*
* THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR 
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES 
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  
* IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
* THE POSSIBILITY OF SUCH DAMAGE.
*
**************************************************************************
*
* $FileName: cdc_serial.c$
* $Version : 3.8.28.0$
* $Date    : Sep-13-2012$
*
* Comments:
*
*   This file is an example of device drivers for the CDC class. This example
*   demonstrates the virtual serial port capability with abstract control model.
*   Redirects the communication from CDC device, which is connected to the board,
*   to the serial port ttyB.
*
*END************************************************************************/

#include <mqx.h>
#include <lwevent.h>

#include <bsp.h>

#include <usb.h>
#include <hostapi.h>
#include <usb_host_hub_sm.h>
#include <usb_host_cdc.h>

#include "cdc_serial.h"

#if ! BSPCFG_ENABLE_IO_SUBSYSTEM
#error This application requires BSPCFG_ENABLE_IO_SUBSYSTEM defined non-zero in user_config.h. Please recompile BSP with this option.
#endif


#if ! BSPCFG_ENABLE_TTYA
//#error This application requires BSPCFG_ENABLE_TTYA defined non-zero in user_config.h. Please recompile BSP with this option.
#endif

#if ! BSPCFG_ENABLE_ITTYB
//#error This application requires BSPCFG_ENABLE_ITTYB defined non-zero in user_config.h. Please recompile BSP with this option.
#endif


/***************************************
**
** Globals
*/

/* Table of driver capabilities this application wants to use */
static  USB_HOST_DRIVER_INFO DriverInfoTable[] =
{
   {
      {0x00,0x00},                  /* Vendor ID per USB-IF             */
      {0x00,0x00},                  /* Product ID per manufacturer      */
      USB_CLASS_COMMUNICATION,      /* Class code                       */
      USB_SUBCLASS_COM_ABSTRACT,    /* Sub-Class code                   */
      0xFF,                         /* Protocol                         */
      0,                            /* Reserved                         */
      usb_host_cdc_acm_event        /* Application call back function   */
   },
   {
      {0x00,0x00},                  /* Vendor ID per USB-IF             */
      {0x00,0x00},                  /* Product ID per manufacturer      */
      USB_CLASS_DATA,               /* Class code                       */
      0xFF,                         /* Sub-Class code                   */
      0xFF,                         /* Protocol                         */
      0,                            /* Reserved                         */
      usb_host_cdc_data_event           /* Application call back function   */
   },
   /* USB 1.1 hub */
   {

      {0x00,0x00},                  /* Vendor ID per USB-IF             */
      {0x00,0x00},                  /* Product ID per manufacturer      */
      USB_CLASS_HUB,                /* Class code                       */
      USB_SUBCLASS_HUB_NONE,        /* Sub-Class code                   */
      USB_PROTOCOL_HUB_ALL,          /* Protocol                         */
      0,                            /* Reserved                         */
      usb_host_hub_device_event     /* Application call back function   */
   },
   {
      {0x00,0x00},                  /* All-zero entry terminates        */
      {0x00,0x00},                  /* driver info list.                */
      0,
      0,
      0,
      0,
      NULL
   }
};

char_ptr                device_name = "tty0:";
const CDC_SERIAL_INIT   usb_open_param = {
#if CDC_EXAMPLE_USE_HW_FLOW
    USB_UART_NO_BLOCKING | USB_UART_HW_FLOW
#else
    USB_UART_NO_BLOCKING
#endif
};
LWEVENT_STRUCT_PTR               device_registered;
_usb_device_instance_handle      reg_device = 0;

ACM_DEVICE_STRUCT    acm_device;
DATA_DEVICE_STRUCT   data_device;

void Main_Task(uint_32);
void USB2UART_Task(uint_32);
void UART2USB_Task(uint_32);

#define USB2UART_TASK (11)
#define UART2USB_TASK (12)
TASK_TEMPLATE_STRUCT  MQX_template_list[] =
{
   {            10,     Main_Task, 1000L, 10L,     "Main",  MQX_AUTO_START_TASK },
   { USB2UART_TASK, USB2UART_Task, 2000L, 12L, "USB2UART",                   0L },
   { UART2USB_TASK, UART2USB_Task, 2000L, 12L, "UART2USB",                   0L },
   { 0L,            0L,    0L,  0L,         0L,                   0L }
};

/*FUNCTION*----------------------------------------------------------------
*
* Function Name  : Main_Task
* Returned Value : none
* Comments       :
*     Execution starts here
*
*END*--------------------------------------------------------------------*/

void Main_Task ( uint_32 param )
{ /* Body */
   USB_STATUS       status = USB_OK;
   _usb_host_handle host_handle;
   _task_id         usb2uart_id;
   _task_id         uart2usb_id;
   
   if (NULL == (device_registered = _mem_alloc(sizeof(*device_registered))))
   {
       printf("\nMemory allocation failed");
      _task_block();
   }
   if (USB_OK != _lwevent_create(device_registered, 0))
   {
       printf("\nlwevent create failed");
      _task_block();
   }
   if (MQX_OK != _lwevent_create(&acm_device.acm_event, LWEVENT_AUTO_CLEAR)) {
       printf("\nlwevent create failed");
      _task_block();
   }
   if (MQX_OK != _lwevent_create(&data_device.data_event, LWEVENT_AUTO_CLEAR)) {
       printf("\nlwevent create failed");
      _task_block();
   }
   
   /* _usb_otg_init needs to be done with interrupts disabled */
   _int_disable();

   _int_install_unexpected_isr();
   if (MQX_OK != _usb_host_driver_install(USBCFG_DEFAULT_HOST_CONTROLLER)) {
      printf("\n Driver installation failed");
      _task_block();
   }

   /*
   ** It means that we are going to act like host, so we initialize the
   ** host stack. This call will allow USB system to allocate memory for
   ** data structures, it uses later (e.g pipes etc.).
   */
   status = _usb_host_init (USBCFG_DEFAULT_HOST_CONTROLLER, &host_handle);

   if (status != USB_OK) 
   {
      printf("\nUSB Host Initialization failed. STATUS: %x", status);
      _int_enable();
      _task_block();
   }

   /*
   ** since we are going to act as the host driver, register the driver
   ** information for wanted class/subclass/protocols
   */
   status = _usb_host_driver_info_register (
                                    host_handle,
                                    DriverInfoTable
                                    );
   if (status != USB_OK) {
      printf("\nDriver Registration failed. STATUS: %x", status);
      _int_enable();
      _task_block();
   }
          
   _int_enable();
   
   /* We suppose that the standard output is interrupt driven uart device */
   printf("\nNOTE: Please ensure that stdin is interrupt driven uart device.");
   printf("\nInitialization passed. Plug-in CDC device to USB port first.\n");
   printf("This example requires that the CDC device uses HW flow.\n");
   printf("If your device does not support HW flow, then set \n");
   printf("CDC_EXAMPLE_USE_HW_FLOW in cdc_serial.h to zero and rebuild example project.\n");

   usb2uart_id = _task_create(0, USB2UART_TASK, 0);
   if (usb2uart_id == MQX_NULL_TASK_ID) {
      printf("\nCould not create USB2UART_task\n");
   }

   uart2usb_id = _task_create(0, UART2USB_TASK, 0);
   if (uart2usb_id == MQX_NULL_TASK_ID) {
      printf("\nCould not create UART2USB_task\n");
   }
   
   _task_block();
   _lwevent_destroy(&data_device.data_event);
   _lwevent_destroy(&acm_device.acm_event);

}

/*FUNCTION*----------------------------------------------------------------
*
* Function Name  : USB2UART_Task
* Returned Value : none
* Comments       :
*     Execution starts here
*
*END*--------------------------------------------------------------------*/
void USB2UART_Task ( uint_32 param )
{ /* Body */
   MQX_FILE_PTR f_uart, f_usb;
   char buffer[200];
   int num_done, num = 0;
   int i;

   _lwevent_wait_ticks(device_registered, DEVICE_REGISTERED_EVENT, TRUE, 0);
   
   if (NULL == (f_usb = fopen(device_name, (pointer) &usb_open_param))) {
       printf("\nInternal error occured");
       _task_block(); /* internal error occured */
   }
   if (NULL == (f_uart = stdout)) {
       printf("\nInternal error occured");
       _task_block(); /* internal error occured */
   }

   while (1) {
      /* read data from USB */
      num_done = fread(buffer + num, 1, sizeof(buffer) / sizeof(buffer[0]) - num, f_usb); /* read characters from USB */
      if (IO_ERROR == num_done)
      {
         if (ferror(f_usb) != USBERR_NO_INTERFACE)
         {
            printf("\nUnexpected error occured");
            _task_block(); /* unexpected error occured */
         }
         break; /* device was detached */
      }
      num += num_done;
      /* write them to UART */
      while (num)
      {
         num_done = fwrite(buffer, sizeof(buffer[0]), num, f_uart);
         if (IO_ERROR == num_done)
         {
            printf("\nUnexpected error occured");
            _task_block(); /* unexpected error occured */
         }
         for (i = num_done; i < num; i++) /* move buffer data, remove the read ones */
            buffer[i - num_done] = buffer[i];
         num -= num_done;
      }
   }
} /* Endbody */

/*FUNCTION*----------------------------------------------------------------
*
* Function Name  : UART2USB_Task
* Returned Value : none
* Comments       :
*     Execution starts here
*
*END*--------------------------------------------------------------------*/
void UART2USB_Task ( uint_32 param )
{ /* Body */
   MQX_FILE_PTR f_uart, f_usb;
   char buffer[200];
   int num_done, num = 0;
   char i;
   uint_32 flags;

   _lwevent_wait_ticks(device_registered, DEVICE_REGISTERED_EVENT, TRUE, 0);
   
   if (NULL == (f_usb = fopen(device_name, (pointer) &usb_open_param))) {
       printf("\nInternal error occured");
       _task_block(); /* internal error occured */
   }
   if (NULL == (f_uart = stdin)) {
       printf("\nInternal error occured");
       _task_block(); /* internal error occured */
   }

   flags = IO_SERIAL_NON_BLOCKING | IO_SERIAL_ECHO;
   if (IO_OK != ioctl(f_uart, IO_IOCTL_SERIAL_SET_FLAGS, &flags)) {
       printf("\nInternal error occured");
       _task_block(); /* internal error occured */
   }

   while (1) {
      /* read data from UART */
      num_done = fread(buffer + num, 1, sizeof(buffer) / sizeof(buffer[0]) - num, f_uart);
      if (IO_ERROR == num_done)
      {
         printf("\nUnexpected error occured");
         _task_block(); /* unexpected error occured */
         break; /* device was detached */
      }
      num += num_done;

      _time_delay(1);
      /* write them to USB */
      if (num) 
      {
         num_done = fwrite(buffer, sizeof(buffer[0]), num, f_usb);
         if (IO_ERROR == num_done) 
         {
            if (ferror(f_usb) != USBERR_NO_INTERFACE)
            {
               printf("\nUnexpected error occured");
               _task_block(); /* unexpected error occured */
            }
            break; /* device was detached */
         }
         for (i = num_done; i < num; i++) /* move buffer data, remove the written ones */
            buffer[i - num_done] = buffer[i];
         num -= num_done;
      }
   }
} /* Endbody */



/*FUNCTION*----------------------------------------------------------------
*
* Function Name  : usb_host_cdc_acm_event
* Returned Value : None
* Comments       :
*     Called when acm interface has been attached, detached, etc.
*END*--------------------------------------------------------------------*/

void usb_host_cdc_acm_event
   (
      /* [IN] pointer to device instance */
      _usb_device_instance_handle      dev_handle,

      /* [IN] pointer to interface descriptor */
      _usb_interface_descriptor_handle intf_handle,

      /* [IN] code number for event causing callback */
      uint_32                          event_code
   )
{ /* Body */
   INTERFACE_DESCRIPTOR_PTR   intf_ptr = (INTERFACE_DESCRIPTOR_PTR)intf_handle;

//   fflush(stdout);
   switch (event_code) {
      case USB_CONFIG_EVENT:
         /* Drop through into attach, same processing */
      case USB_ATTACH_EVENT: {
         USB_CDC_DESC_ACM_PTR    acm_desc = NULL;
         USB_CDC_DESC_CM_PTR     cm_desc = NULL;
         USB_CDC_DESC_HEADER_PTR header_desc = NULL;
         USB_CDC_DESC_UNION_PTR  union_desc = NULL;

         /* finds all the descriptors in the configuration */
         if (USB_OK != usb_class_cdc_get_acm_descriptors(dev_handle,
             intf_handle,
             &acm_desc,
             &cm_desc,
             &header_desc,
             &union_desc))
            break;

         /* initialize new interface members and select this interface */
         if (USB_OK != _usb_hostdev_select_interface(dev_handle,
            intf_handle, (pointer)&acm_device.CLASS_INTF))
         {
            break;
         }
         /* set all info got from descriptors to the class interface struct */
         usb_class_cdc_set_acm_descriptors((pointer)&acm_device.CLASS_INTF,
            acm_desc, cm_desc, header_desc, union_desc);

         /* link all already registered data interfaces to this ACM control, if needed */
         if (USB_OK != usb_class_cdc_bind_data_interfaces(dev_handle, (pointer)&acm_device.CLASS_INTF)) {
            break;
         }
         
//         printf("----- CDC control interface attach Event -----\n");
//         fflush(stdout);
//         printf("State = attached");
//         printf("  Class = %d", intf_ptr->bInterfaceClass);
//         printf("  SubClass = %d", intf_ptr->bInterfaceSubClass);
//         printf("  Protocol = %d\n", intf_ptr->bInterfaceProtocol);
//         fflush(stdout);

         break;
      }
      case USB_INTF_EVENT: 
      {
         CLASS_CALL_STRUCT_PTR   acm_parser;
         USB_STATUS              status;
         
         if (NULL == (acm_parser = usb_class_cdc_get_ctrl_interface(intf_handle)))
             break;
         if (MQX_OK != usb_class_cdc_acm_use_lwevent(acm_parser, &acm_device.acm_event))
             break;
         status = usb_class_cdc_init_ipipe(acm_parser);
         if ((status != USB_OK) && (status != USBERR_OPEN_PIPE_FAILED))
             break;
         
//         printf("----- CDC control interface selected -----\n");

         break;
      }
         
      case USB_DETACH_EVENT:
      {
         CLASS_CALL_STRUCT_PTR acm_parser;
         
         if (NULL == (acm_parser = usb_class_cdc_get_ctrl_interface(intf_handle)))
             break;
         
         /* Allow tasks waiting for acm to be finished...
         ** We will not wait here - in the interrupt context.
         ** For simplification, we dont use any semaphore to indicate that
         ** all tasks have finished its job with device. Instead, we are just
         ** informed them that device is detached and we rely on USB stack layer
         ** that its check of the available device returns false.
         ** The code that would synchronize tasks to be finished would look like:
         **
         **  _lwsem_wait(tasks_using_device_semaphore);
         **
         **  where the semaphore would be signalled from this interrupt.
         */

         usb_class_cdc_unbind_data_interfaces(acm_parser);

         /* Use only the interface with desired protocol */
//         printf("----- CDC control interface detach event -----\n");
//         fflush(stdout);
//         printf("State = detached");
//         printf("  Class = %d", intf_ptr->bInterfaceClass);
//         printf("  SubClass = %d", intf_ptr->bInterfaceSubClass);
//         printf("  Protocol = %d\n", intf_ptr->bInterfaceProtocol);
//         fflush(stdout);

         break;
      }

      default:
//         printf("CDC device: unknown control event\n");
         //fflush(stdout);
         break;
   } /* EndSwitch */
} /* Endbody */

/*FUNCTION*----------------------------------------------------------------
*
* Function Name  : usb_host_cdc_data_event
* Returned Value : None
* Comments       :
*     Called when data interface has been attached, detached, etc.
*END*--------------------------------------------------------------------*/

void usb_host_cdc_data_event
   (
      /* [IN] pointer to device instance */
      _usb_device_instance_handle      dev_handle,

      /* [IN] pointer to interface descriptor */
      _usb_interface_descriptor_handle intf_handle,

      /* [IN] code number for event causing callback */
      uint_32                          event_code
   )
{ /* Body */
   INTERFACE_DESCRIPTOR_PTR   intf_ptr =
      (INTERFACE_DESCRIPTOR_PTR)intf_handle;

//   fflush(stdout);
   switch (event_code) {
      case USB_CONFIG_EVENT:
         /* Drop through into attach, same processing */
      case USB_ATTACH_EVENT: {
         /* This data interface could be controlled by some control interface,
          * which could be already initialized (or not). We have to find 
          * that interface. Then we need to bind this interface with
          * found control interface. */
         INTERFACE_DESCRIPTOR_PTR   if_desc;
         
         if (USB_OK != usb_class_cdc_get_ctrl_descriptor(dev_handle,
            intf_handle,
            &if_desc))
            break;

         /* initializes interface members and selects it */
         if (USB_OK != _usb_hostdev_select_interface(dev_handle,
            intf_handle, (pointer)&data_device.CLASS_INTF))
         {
            break;
         }
         /* binds this data interface with its control interface, if possible */
         if (USB_OK != usb_class_cdc_bind_acm_interface((pointer)&data_device.CLASS_INTF,
            if_desc))
         {
            break;
         }
         
//         printf("----- CDC data interface attach event -----\n");
//         fflush(stdout);
//         printf("State = attached");
//         printf("  Class = %d", intf_ptr->bInterfaceClass);
//         printf("  SubClass = %d", intf_ptr->bInterfaceSubClass);
//         printf("  Protocol = %d\n", intf_ptr->bInterfaceProtocol);
//         fflush(stdout);

         break;
      }   
      case USB_INTF_EVENT: 
      {
         CLASS_CALL_STRUCT_PTR data_parser;
         
//         fflush(stdout);
         
         if (NULL == (data_parser = usb_class_cdc_get_data_interface(intf_handle)))
             break;
         if (MQX_OK != usb_class_cdc_data_use_lwevent(data_parser, &data_device.data_event))
             break;
         if (USB_OK == usb_class_cdc_install_driver(data_parser, device_name)) 
         {
             if (((USB_DATA_CLASS_INTF_STRUCT_PTR) (data_parser->class_intf_handle))->BOUND_CONTROL_INTERFACE != NULL) {
                 if (reg_device == 0) {
                     reg_device = dev_handle;
                     _lwevent_set(device_registered, 0x01);
                 }
             }
//             printf("----- Device installed -----\n");
         }
//         printf("----- CDC data interface selected -----\n");

         break;
      }
         
      case USB_DETACH_EVENT: 
      {
         CLASS_CALL_STRUCT_PTR data_parser;
         
         if (NULL == (data_parser = usb_class_cdc_get_data_interface(intf_handle)))
             break;

         /* Allow tasks waiting for data to be finished...
         ** This does have sense only if this task will not be active
         ** or scheduler switches to another task.
         ** For simplification, we dont use any semaphore to indicate that
         ** all tasks have finished its job with device. Instead, we have just
         ** informed them that device is detached and we rely on USB stack layer
         ** that it checking if the device is available returns false.
         ** The code that would synchronize tasks to be finished would look like:
         **
         **  _lwsem_wait(if_ptr->device_using_tasks);
         */

         /* unbind data interface */
         if (USB_OK != usb_class_cdc_unbind_acm_interface(data_parser))
             break;
         if (USB_OK != usb_class_cdc_uninstall_driver(data_parser))
             break;
         
         if (reg_device == dev_handle) {
             reg_device = 0;
             _lwevent_clear(device_registered, 0x01);
         }

//         printf("----- CDC data interface detach Event -----\n");
//         fflush(stdout);
//         printf("State = detached");
//         printf("  Class = %d", intf_ptr->bInterfaceClass);
//         printf("  SubClass = %d", intf_ptr->bInterfaceSubClass);
//         printf("  Protocol = %d\n", intf_ptr->bInterfaceProtocol);
//         fflush(stdout);

         break;
      }

      default:
//         printf("CDC device: unknown data event\n");
//         fflush(stdout);
         break;
   } /* EndSwitch */
} /* Endbody */

/* EOF */
