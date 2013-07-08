#ifndef __hidkeyboard_h__
#define __hidkeyboard_h__
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
* $FileName: hidkeyboard.h$
* $Version : 3.8.1.0$
* $Date    : Aug-9-2012$
*
* Comments:
*
*   This file contains keyboard-application types and definitions.
*
*END************************************************************************/

#ifdef __USB_OTG__
#include "otgapi.h"
#include "devapi.h"
#else
#include "hostapi.h"
#endif
#include "audio_speaker.h"

/***************************************
**
** Application-specific definitions
*/

/* Used to initialize USB controller */
#define MAX_FRAME_SIZE           1024

#define  HID_KEYBOARD_BUFFER_SIZE    1

#define USB_Keyboard_Event_CTRL 0x01
#define USB_Keyboard_Event_DATA 0x02
/*
** Following structs contain all states and pointers
** used by the application to control/operate devices.
*/

typedef struct usb_keyboard_device_struct {
    uint_32                          DEV_STATE;  /* Attach/detach state */
    _usb_device_instance_handle      DEV_HANDLE;
    _usb_interface_descriptor_handle INTF_HANDLE;
    CLASS_CALL_STRUCT                CLASS_INTF; /* Class-specific info */
} USB_KEYBOARD_DEVICE_STRUCT,  _PTR_ USB_KEYBOARD_DEVICE_STRUCT_PTR;


/* Alphabetical list of Function Prototypes */

#ifdef __cplusplus
extern "C" {
#endif

    void usb_host_hid_keyboard_recv_callback(_usb_pipe_handle, pointer, uchar_ptr, uint_32,
    uint_32);
    void usb_host_hid_keyboard_ctrl_callback(_usb_pipe_handle, pointer, uchar_ptr, uint_32,
    uint_32);
    void usb_host_hid_keyboard_event(_usb_device_instance_handle,
    _usb_interface_descriptor_handle, uint_32);

#ifdef __cplusplus
}
#endif


#endif

/* EOF */
