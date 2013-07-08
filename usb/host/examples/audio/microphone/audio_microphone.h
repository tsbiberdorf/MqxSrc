
/**HEADER********************************************************************
*
* Copyright (c) 2011 Freescale Semiconductor;
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
* $FileName: audio_microphone.h$
* $Version :
* $Date    :
*
* Comments:
*
*   This file contains audio types and definitions.
*
*END************************************************************************/
#ifndef __audio_microphone_h__
#define __audio_microphone_h__

#ifdef __USB_OTG__
#include "otgapi.h"
#include "devapi.h"
#else
#include "hostapi.h"
#endif
#include "usb_host_audio.h"

/***************************************
**
** Application-specific definitions
**
****************************************/

#define MAX_SUPPORT_FREQUENCY        48

#define AUDIO_MICROPHONE_FREQUENCY   1000

#define MAX_FRAME_SIZE              1024
#define HOST_CONTROLLER_NUMBER      USBCFG_DEFAULT_HOST_CONTROLLER

#define NUMBER_OF_IT_TYPE 7
#define NUMBER_OF_OT_TYPE 8

#define USB_EVENT_CTRL              0x01
#define USB_EVENT_RECEIVED_DATA     0x02
#define USB_EVENT_SEND_DATA         0x04

#define MAX_ISO_PACKET_SIZE         512

#define USB_AUDIO_DEVICE_DIRECTION_IN                   0x00
#define USB_AUDIO_DEVICE_DIRECTION_OUT                  0x01
#define USB_AUDIO_DEVICE_DIRECTION_UNDEFINE             0xFF

#define USB_TERMINAL_TYPE           0x01
#define INPUT_TERMINAL_TYPE         0x02
#define OUTPUT_TERMINAL_TYPE        0x03

#define  USB_DEVICE_IDLE                   (0)
#define  USB_DEVICE_ATTACHED               (1)
#define  USB_DEVICE_CONFIGURED             (2)
#define  USB_DEVICE_SET_INTERFACE_STARTED  (3)
#define  USB_DEVICE_INTERFACED             (4)
#define  USB_DEVICE_SETTING_PROTOCOL       (5)
#define  USB_DEVICE_INUSE                  (6)
#define  USB_DEVICE_DETACHED               (7)
#define  USB_DEVICE_OTHER                  (8)

#define  TRANSFER_TYPE_NUM                  4
#define  SYNC_TYPE_NUM                      4
#define  DATA_TYPE_NUM                      4


#define  TRANSFER_TYPE_SHIFT                0
#define  SYNC_TYPE_SHIFT                    2
#define  DATA_TYPE_SHIFT                    4

#define BYTE0_SHIFT                         0
#define BYTE1_SHIFT                         8
#define BYTE2_SHIFT                         16

#define HOST_VOLUME_STEP      1
#define HOST_MIN_VOLUME       0
#define HOST_MAX_VOLUME      10
/*
** Following structs contain all states and pointers
** used by the application to control/operate devices.
*/


typedef struct audio_device_struct {
   uint_32                          DEV_STATE;  /* Attach/detach state */
   _usb_device_instance_handle      DEV_HANDLE;
   _usb_interface_descriptor_handle INTF_HANDLE;
   CLASS_CALL_STRUCT                CLASS_INTF; /* Class-specific info */
} AUDIO_CONTROL_DEVICE_STRUCT,  _PTR_ AUDIO_CONTROL_DEVICE_STRUCT_PTR;

typedef struct data_device_struct {
   uint_32                          DEV_STATE;  /* Attach/detach state */
   _usb_device_instance_handle      DEV_HANDLE;
   _usb_interface_descriptor_handle INTF_HANDLE;
   CLASS_CALL_STRUCT                CLASS_INTF; /* Class-specific info */
} AUDIO_STREAM_DEVICE_STRUCT,  _PTR_ AUDIO_STREAM_DEVICE_STRUCT_PTR;

typedef struct feature_control_struct {
    uint_32                          FU;
} FEATURE_CONTROL_STRUCT,  _PTR_ FEATURE_CONTROL_STRUCT_PTR;
/* Alphabetical list of Function Prototypes */

#ifdef __cplusplus
extern "C" {
#endif

void usb_host_audio_control_event(_usb_device_instance_handle,
   _usb_interface_descriptor_handle, uint_32);
void usb_host_audio_stream_event(_usb_device_instance_handle,
   _usb_interface_descriptor_handle, uint_32);
void usb_host_audio_tr_callback(_usb_pipe_handle ,pointer,
    uchar_ptr ,uint_32 ,uint_32 );
void usb_host_audio_mute_ctrl_callback(_usb_pipe_handle,pointer,
    uchar_ptr,uint_32,uint_32);
void usb_host_audio_ctrl_callback(_usb_pipe_handle,pointer,
    uchar_ptr,uint_32,uint_32);
void usb_host_audio_interrupt_callback(_usb_pipe_handle,pointer,
    uchar_ptr,uint_32,uint_32);
    void usb_host_audio_request_ctrl_callback(_usb_pipe_handle,pointer,uchar_ptr,uint_32,uint_32);
    void config_channel(USB_AUDIO_CTRL_DESC_FU_PTR,uint_8);
#ifdef __cplusplus
}
#endif
#endif

/* EOF */
