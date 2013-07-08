/**HEADER********************************************************************
*
* Copyright (c) 2013 Freescale Semiconductor;
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
* $FileName: mcc.c$
* $Version : 3.8.2.0$
* $Date    : Oct-2-2012$
*
* Comments:
*
*   This file contains the source for one of the MCC pingpong examples.
*
*END************************************************************************/

#include <mqx.h>
#include <bsp.h>
#include "mcc.h"
#include "mcc_config.h"
#include "mcc_common.h"
#include "mcc_api.h"
#include "mcc_mqx.h"
#include <string.h>

#include <core_mutex.h>

#if ! BSPCFG_ENABLE_IO_SUBSYSTEM
#error This application requires BSPCFG_ENABLE_IO_SUBSYSTEM defined non-zero in user_config.h. Please recompile BSP with this option.
#endif


#ifndef BSP_DEFAULT_IO_CHANNEL_DEFINED
#error This application requires BSP_DEFAULT_IO_CHANNEL to be not NULL. Please set corresponding BSPCFG_ENABLE_TTYx to non-zero in user_config.h and recompile BSP with this option.
#endif

/* Application-specific settings */
/* 1: Blocking mode (task is blocked when no new message is available)
 * 0: Non-blocking mode (task is waiting for a new message in a spin loop) */
#define MCC_APP_BLOCKING_MODE  (1)

extern void main_task(uint_32);
extern void responder_task(uint_32);

#if PSP_MQX_CPU_IS_VYBRID_A5
const TASK_TEMPLATE_STRUCT  MQX_template_list[] =
{
   /* Task Index,    Function,       Stack,  Priority, Name,        Attributes,          Param, Time Slice */
    { MAIN_TTN,      main_task,      2000,   9,        "Main",      MQX_AUTO_START_TASK, MCC_MQX_NODE_A5,   0 },
    { 0 }
};
#else
TASK_TEMPLATE_STRUCT  MQX_template_list[] =
{
   /* Task Index,    Function,       Stack,  Priority,  Name,        Attributes,          Param, Time Slice */
    { RESPONDER_TTN, responder_task, 2000,   9,         "Responder", MQX_AUTO_START_TASK, MCC_MQX_NODE_M4,  0 },
    { 0 }
};
#endif

MCC_ENDPOINT    mqx_endpoint_a5 = {0,MCC_MQX_NODE_A5,MCC_MQX_SENDER_PORT};
MCC_ENDPOINT    mqx_endpoint_m4 = {1,MCC_MQX_NODE_M4,MCC_MQX_RESPONDER_PORT};

/*TASK*----------------------------------------------------------
*
* Task Name : main_task
* Comments  :
*     This task creates a message pool and a message queue then
*     sends a message to a queue on the second CPU.
*     It waits for a return message, validating the message before
*     sending a new message.
*END*-----------------------------------------------------------*/

void main_task(uint_32 node_num)
{
    THE_MESSAGE     msg;
    MCC_MEM_SIZE    num_of_received_bytes;
    CORE_MUTEX_PTR  coremutex_app_ptr;
    MCC_INFO_STRUCT mcc_info;
    int             ret_value;
#if !MCC_APP_BLOCKING_MODE
    unsigned int    num_available_msgs;
#endif

    /* create core mutex used in the app. for accessing the serial console */
    coremutex_app_ptr = _core_mutex_create( 0, MCC_PRINTF_SEMAPHORE_NUMBER, MQX_TASK_QUEUE_FIFO );

    msg.DATA = 1;
    ret_value = mcc_initialize(node_num);
    ret_value = mcc_get_info(node_num, &mcc_info);
    if(MCC_SUCCESS == ret_value && (strcmp(mcc_info.version_string, MCC_VERSION_STRING) != 0)) {
        _core_mutex_lock(coremutex_app_ptr);
        printf("\n\n\nError, attempting to use different versions of the MCC library on each core! Application is stopped now.\n");
        _core_mutex_unlock(coremutex_app_ptr);
        mcc_destroy(node_num);
        _task_block();
    }
    ret_value = mcc_create_endpoint(&mqx_endpoint_a5, MCC_MQX_SENDER_PORT);

    _core_mutex_lock(coremutex_app_ptr);
    printf("\n\n\nMain task started, MCC version is %s\n", mcc_info.version_string);
    _core_mutex_unlock(coremutex_app_ptr);

    while (1) {
        /* wait until the remote endpoint is created by the other core */
        while(MCC_ERR_ENDPOINT == mcc_send(&mqx_endpoint_m4, &msg, sizeof(THE_MESSAGE), 0xffffffff)) {
        }
#if MCC_APP_BLOCKING_MODE
        ret_value = mcc_recv_copy(&mqx_endpoint_a5, &msg, sizeof(THE_MESSAGE), &num_of_received_bytes, 0xffffffff);
#else
        mcc_msgs_available(&mqx_endpoint_a5, &num_available_msgs);
        while(num_available_msgs==0) {
        	mcc_msgs_available(&mqx_endpoint_a5, &num_available_msgs);
        }
        ret_value = mcc_recv_copy(&mqx_endpoint_a5, &msg, sizeof(THE_MESSAGE), &num_of_received_bytes, 0);
#endif
        if(MCC_SUCCESS != ret_value) {
            _core_mutex_lock(coremutex_app_ptr);
            printf("Main task receive error: %i\n", ret_value);
            _core_mutex_unlock(coremutex_app_ptr);
        } else {
            _core_mutex_lock(coremutex_app_ptr);
            printf("Main task received a msg\n");
            printf("Message: Size=%x, DATA = %x\n", num_of_received_bytes, msg.DATA);
            _core_mutex_unlock(coremutex_app_ptr);
            msg.DATA++;
        }
    }
}

/*TASK*----------------------------------------------------------
*
* Task Name : responder_task
* Comments  :
*     This task creates a message queue then waits for a message.
*     Upon receiving the message the data is incremented before
*     the message is returned to the sender.
*END*-----------------------------------------------------------*/

void responder_task(uint_32 node_num)
{
    THE_MESSAGE     msg;
    MCC_MEM_SIZE    num_of_received_bytes;
    CORE_MUTEX_PTR  coremutex_app_ptr;
    MCC_INFO_STRUCT mcc_info;
    int             ret_value;
#if !MCC_APP_BLOCKING_MODE
    unsigned int    num_available_msgs;
#endif

    /* create core mutex used in the app. for accessing the serial console */
    coremutex_app_ptr = _core_mutex_create( 0, MCC_PRINTF_SEMAPHORE_NUMBER, MQX_TASK_QUEUE_FIFO );

    msg.DATA = 1;
    ret_value = mcc_initialize(node_num);
    ret_value = mcc_get_info(node_num, &mcc_info);
    if(MCC_SUCCESS == ret_value && (strcmp(mcc_info.version_string, MCC_VERSION_STRING) != 0)) {
        _core_mutex_lock(coremutex_app_ptr);
        printf("\n\n\nError, attempting to use different versions of the MCC library on each core! Application is stopped now.\n");
        _core_mutex_unlock(coremutex_app_ptr);
        mcc_destroy(node_num);
        _task_block();
    }
    ret_value = mcc_create_endpoint(&mqx_endpoint_m4, MCC_MQX_RESPONDER_PORT);

    _core_mutex_lock(coremutex_app_ptr);
    printf("\n\n\nResponder task started, MCC version is %s\n", mcc_info.version_string);
    _core_mutex_unlock(coremutex_app_ptr);
    while (TRUE) {
#if MCC_APP_BLOCKING_MODE
        ret_value = mcc_recv_copy(&mqx_endpoint_m4, &msg, sizeof(THE_MESSAGE), &num_of_received_bytes, 0xffffffff);
#else
        mcc_msgs_available(&mqx_endpoint_m4, &num_available_msgs);
        while(num_available_msgs==0) {
            mcc_msgs_available(&mqx_endpoint_m4, &num_available_msgs);
        }
        ret_value = mcc_recv_copy(&mqx_endpoint_m4, &msg, sizeof(THE_MESSAGE), &num_of_received_bytes, 0);
#endif
        if(MCC_SUCCESS != ret_value) {
            _core_mutex_lock(coremutex_app_ptr);
            printf("Responder task receive error: %i\n", ret_value);
            _core_mutex_unlock(coremutex_app_ptr);
        } else {
            _core_mutex_lock(coremutex_app_ptr);
            printf("Responder task received a msg\n");
            printf("Message: Size=%x, DATA = %x\n", num_of_received_bytes, msg.DATA);
            _core_mutex_unlock(coremutex_app_ptr);
            msg.DATA++;
            ret_value = mcc_send(&mqx_endpoint_a5, &msg, sizeof(THE_MESSAGE), 0xffffffff);
        }
    }
}
