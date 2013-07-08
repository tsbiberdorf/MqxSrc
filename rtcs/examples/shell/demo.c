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
* $FileName: demo.c$
* $Version : 3.8.35.0$
* $Date    : Oct-5-2012$
*
* Comments:
*
*   Example using RTCS Library.
*
*END************************************************************************/

#include <string.h>
#include <mqx.h>
#include <bsp.h>
#include <mfs.h>
#include <rtcs.h>
#include <shell.h>
#include "config.h"  
#include <fio.h>

#if DEMOCFG_ENABLE_PPP
#include <ppp.h>

#if ! RTCSCFG_ENABLE_VIRTUAL_ROUTES
#error This application requires RTCSCFG_ENABLE_VIRTUAL_ROUTES defined non-zero in user_config.h. Please recompile libraries (BSP, RTCS) with this option.
#endif

#if ! RTCSCFG_ENABLE_GATEWAYS
#error This application requires RTCSCFG_ENABLE_GATEWAYS defined non-zero in user_config.h. Please recompile libraries (BSP, RTCS) with this option.
#endif

#warning This application requires PPP device to be defined manually and being different from the default IO channel (BSP_DEFAULT_IO_CHANNEL). See PPP_DEVICE in config.h.

#warning This application requires PPP device QUEUE_SIZE  to be more than size of input LCP packet (set BSPCFG_UARTX_QUEUE_SIZE to 128 in user_config.h) If no, you can lose LCP packets.

#if PPP_SECRETS_NOT_SHARED
#error This application requires PPP_SECRETS_NOT_SHARED defined to zero in /src/rtcs/source/include/ppp.h. Please recompile RTCS with this option.
#endif

#endif /* DEMOCFG_ENABLE_PPP */


#if ! BSPCFG_ENABLE_IO_SUBSYSTEM
#error This application requires BSPCFG_ENABLE_IO_SUBSYSTEM defined non-zero in user_config.h. Please recompile BSP with this option.
#endif


#ifndef BSP_DEFAULT_IO_CHANNEL_DEFINED
#error This application requires BSP_DEFAULT_IO_CHANNEL to be not NULL. Please set corresponding BSPCFG_ENABLE_TTYx to non-zero in user_config.h and recompile BSP with this option.
#endif



#define MAIN_TASK 1

/*  
**  FTP root directory can be specified here. 
*/
char FTPd_rootdir[] = "a:\\"; 
extern const SHELL_COMMAND_STRUCT Shell_commands[];
extern void Main_task (uint_32);
extern void Ram_disk_start(void);

const TASK_TEMPLATE_STRUCT  MQX_template_list[] = 
{
   /* Task Index,   Function,   Stack,  Priority,   Name,   Attributes,          Param, Time Slice */
    { MAIN_TASK,    Main_task,  2500,   9,          "Main", MQX_AUTO_START_TASK, 0,     0 },
    { 0 }
};

#if DEMOCFG_ENABLE_RAMDISK

#if (DEMOCFG_ENABLE_MRAM_RAMDISK) /* MRAM RAM disk enabled */

/* The MRam disk base address definition taken from linker command file*/
#if defined (BSP_EXTERNAL_MRAM_RAM_BASE) && defined (BSP_EXTERNAL_MRAM_RAM_SIZE)
    #define RAM_DISK_BASE   BSP_EXTERNAL_MRAM_RAM_BASE 
    #define RAM_DISK_SIZE   BSP_EXTERNAL_MRAM_RAM_SIZE
#else
   #error MRAM RAM disk needs space to be defined
#endif

#endif /* MRAM RAM disk enabled */
/*FUNCTION*------------------------------------------------
* 
* Function Name: Ram_disk_start
* Comments     :
*    
*
*END*-----------------------------------------------------*/
void Ram_disk_start(void)
{
    MQX_FILE_PTR               dev_handle1, a_fd_ptr;
    int_32                     error_code;
    _mqx_uint                  mqx_status;
    uint_32                    size;
    uchar_ptr                  base;
    a_fd_ptr = 0;
#if DEMOCFG_ENABLE_MRAM_RAMDISK /* MRAM RAM disk enabled */
    size = RAM_DISK_SIZE;
    base = RAM_DISK_BASE;
#else 
    /* Determine RAMDISK size  - start on 128 KiB and go down to 16 KiB */
    for (size = 128*1024; size > 16*1024; size /= 2)
    {
        base = (uchar_ptr) _mem_alloc(size);
        if (base != NULL)
        {
            _mem_free(base);
            base = NULL;
            break;
        }
    }
    /* If memory block is big half its size, otherwise leave it on 8 KiB */
    if (size > 8*1024)
    {
        size /= 2;
    }
    base = (uchar_ptr) _mem_alloc(size);
    if (base == NULL)
    {
        printf("\nError - unable to allocate space for RAM disk - NULL pointer");
        _task_block();
    }
#endif /* MRAM RAM disk enabled */
    
    /* Install device */
    mqx_status = _io_mem_install("mfs_ramdisk:", (uchar_ptr)base, (_file_size)size);
    if ( mqx_status != MQX_OK ) 
    {
        printf("\nError installing memory device (0x%x)", mqx_status);
        _task_block();
    }

    /* Open the device which MFS will be installed on */
    dev_handle1 = fopen("mfs_ramdisk:", 0);
    if ( dev_handle1 == NULL ) 
    {
        printf("\nUnable to open Ramdisk device");
        _task_block();
    }

    /* Install MFS  */
    mqx_status = _io_mfs_install(dev_handle1, "a:", (_file_size)0);
    if (mqx_status != MFS_NO_ERROR) 
    {
        printf("\nError initializing a:");
        _task_block();
    } 
    else 
    {
        printf("\nInitialized Ram Disk to a:\\");
    }

    /* Open the filesystem and detect, if format is required */
    a_fd_ptr = fopen("a:", NULL);
    error_code = ferror(a_fd_ptr);
    if ((error_code != MFS_NO_ERROR) && (error_code != MFS_NOT_A_DOS_DISK))
    {
        printf("\nError while opening a:\\ (%s)", MFS_Error_text((uint_32)(uint_32)error_code));
        _task_block();
    }
    if (error_code == MFS_NOT_A_DOS_DISK) 
    {
        printf("\nNOT A DOS DISK! You must format to continue.");
    }
    
} 

#endif /* DEMOCFG_ENABLE_RAMDISK */

/*TASK*-----------------------------------------------------------------
*
* Task Name      : Main_task
* Returned Value : void
* Comments       :
*
*END------------------------------------------------------------------*/
void Main_task(uint_32 temp)
{
    uint_32     error;

#if RTCS_MINIMUM_FOOTPRINT
   /* runtime RTCS configuration for devices with small RAM, for others the default BSP setting is used */
   _RTCSPCB_init = 4;
   _RTCSPCB_grow = 2;
   _RTCSPCB_max = 20;
   _RTCS_msgpool_init = 4;
   _RTCS_msgpool_grow = 2;
   _RTCS_msgpool_max  = 20;
   _RTCS_socket_part_init = 4;
   _RTCS_socket_part_grow = 2;
   _RTCS_socket_part_max  = 20;
#endif
    _RTCSTASK_stacksize = 3000;
    error = RTCS_create();
    if (error != RTCS_OK) 
    {
        printf("\nRTCS failed to initialize, error = %X", error);
        _task_block();
    }
    /* Enable IP forwarding */
    _IP_forward = TRUE;

#if DEMOCFG_ENABLE_PPP
   /* Instalation of driver for PPP device. */   
    #if PPP_DEVICE_DUN       /* Dial-Up Network */
    _io_dun_install("dun:");
    #endif
    #if PPP_DEVICE_RAS     /* Remote Access Service */
     error = _io_ras_install("dcn:");
    #endif
#endif
        
        
#if DEMOCFG_ENABLE_RAMDISK  
    Ram_disk_start();
    /*If root directory is not specified, use root from first valid filesystem */
    if(FTPd_rootdir[0] == '\0')
    {
        _io_get_fs_name(_io_get_first_valid_fs(), FTPd_rootdir, sizeof(FTPd_rootdir));
        FTPd_rootdir[strlen(FTPd_rootdir)] = '\\';
        FTPd_rootdir[strlen(FTPd_rootdir)+1] = '\0';
    }
#endif /* DEMOCFG_ENABLE_RAMDISK */

    /* Run the shell */
    Shell(Shell_commands, NULL);
    for(;;) 
    {
        printf("Shell exited, restarting...\n");
        Shell(Shell_commands, NULL);
    }
}
/* EOF */
