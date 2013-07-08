/**HEADER********************************************************************
*
* Copyright (c) 2008 Freescale Semiconductor;
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
* $FileName: main.h$
* $Version : 3.8.3.0$
* $Date    : Sep-12-2012$
*
* Comments:
*
*   This include file is used to provide information needed by
*   applications using the SAI I/O functions.
*
*END************************************************************************/

#ifndef __main_h_
#define __main_h_

#include <mqx.h>
#include <bsp.h>
#include <lwevent.h>
#include <message.h>

extern void Init_task(uint_32);
extern void Sdcard_task(uint_32);
extern void Shell_task(uint_32);
extern void Sdcard_write_task(uint_32);

#define AUDIO_SAMPLE_RATE   (44100)
#ifdef BSPCFG_ENABLE_SAI
#define CLK_MULT             (384)
#else
#define CLK_MULT             (256)
#endif

#define INIT_TASK 1
#define SDCARD_TASK 2
#define SHELL_TASK 3
#define SDCARD_WRITE_TASK 4

#define WRITE_QUEUE 8
#define REC_BLOCK_SIZE 512

/* Parameter structure required for SD write task */
typedef struct sd_write_param_struct
{
    /* Pointer to output file */
    MQX_FILE_PTR file_ptr;
    
    /* LW Semaphore pointer signaling finished writing to SD card */
    LWSEM_STRUCT sdwrite_sem;   
} SD_WRITE_PARAM_STRUCT;

/* This struct contains a data field and a message struct. */
typedef struct
{
    /* Message header */ 
    MESSAGE_HEADER_STRUCT HEADER;
    
    /* Data length */
    uint_32 LENGTH;
    
    /* Data */
    char DATA[REC_BLOCK_SIZE];   
} REC_MESSAGE, _PTR_ REC_MESSAGE_PTR;

#endif /* __main_h_ */

/* EOF */
