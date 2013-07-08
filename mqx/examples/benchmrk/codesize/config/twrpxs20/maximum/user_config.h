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
* $FileName: user_config.h$
* $Version : 3.8.1.0$
* $Date    : Oct-9-2012$
*
* Comments:
*
*   User configuration for MQX components
*
*END************************************************************************/

#ifndef __user_config_h__
#define __user_config_h__

// this is custom config for the codesize measurement
#define CODESIZE_USER_CONFIG 1

/* mandatory CPU identification */
#define MQX_CPU                           PSP_CPU_MPXS20
#define MQX_USE_INTERRUPTS                1
#define MQX_KERNEL_LOGGING                1

#define BSPCFG_ENABLE_IO_SUBSYSTEM        1

/* ttya - on board serial console over OSBDM (DEFAULT) */
/* ttyb - TWR-SER RS232 serial console (PCS9)          */          
#define BSP_DEFAULT_IO_CHANNEL            "ttyb:"
#define BSP_DEFAULT_IO_CHANNEL_DEFINED    1 

/* Uncomenting these line causes PIT to be used as system timer */
//#define BSPCFG_TIMER_PIT_DEVICE         (0)
//#define BSPCFG_TIMER_PIT_CHANNEL        (0)
//#define BSPCFG_TIMER_INT_LEVEL          (1)

#define BSPCFG_ENABLE_ENET_STATS          1
#define BSPCFG_ENABLE_ENET_MULTICAST      1
#define BSPCFG_ENABLE_CPP                 1
#define BSPCFG_ENABLE_TTYA                1 
#define BSPCFG_ENABLE_ITTYA               1               
#define BSPCFG_ENABLE_TTYB                1
#define BSPCFG_ENABLE_ITTYB               1
#define BSPCFG_ENABLE_TTYC                1
#define BSPCFG_ENABLE_ITTYC               1
#define BSPCFG_ENABLE_TTYD                1
#define BSPCFG_ENABLE_ITTYD               1
#define BSPCFG_ENABLE_TTYE                1
#define BSPCFG_ENABLE_ITTYE               1
#define BSPCFG_ENABLE_TTYF                1
#define BSPCFG_ENABLE_ITTYF               1
#define BSPCFG_ENABLE_TTYG                1
#define BSPCFG_ENABLE_ITTYG               1
#define BSPCFG_ENABLE_TTYH                1
#define BSPCFG_ENABLE_ITTYH               1
#define BSPCFG_ENABLE_TTYI                1
#define BSPCFG_ENABLE_ITTYI               1
#define BSPCFG_ENABLE_TTYJ                1
#define BSPCFG_ENABLE_ITTYJ               1

#define BSPCFG_ENABLE_SPI0                1
#define BSPCFG_ENABLE_ISPI0               1               
#define BSPCFG_ENABLE_SPI1                1
#define BSPCFG_ENABLE_ISPI1               1
#define BSPCFG_ENABLE_SPI2                1
#define BSPCFG_ENABLE_ISPI2               1
#define BSPCFG_ENABLE_SPI3                1
#define BSPCFG_ENABLE_ISPI3               1
#define BSPCFG_ENABLE_SPI4                1
#define BSPCFG_ENABLE_ISPI4               1
#define BSPCFG_ENABLE_SPI5                1
#define BSPCFG_ENABLE_ISPI5               1
#define BSPCFG_ENABLE_SPI6                1
#define BSPCFG_ENABLE_ISPI6               1
#define BSPCFG_ENABLE_SPI7                1
#define BSPCFG_ENABLE_ISPI7               1
#define BSPCFG_ENABLE_SPI8                1
#define BSPCFG_ENABLE_ISPI8               1
#define BSPCFG_ENABLE_SPI9                1
#define BSPCFG_ENABLE_ISPI9               1

#define BSPCFG_ENABLE_NANDFLASH           1
#define BSPCFG_ENABLE_GPIODEV             0
#define BSPCFG_ENABLE_RTCDEV              0 /* TODO: FIX the codesize main.c*/
#define BSPCFG_ENABLE_PCFLASH             1
#define BSPCFG_ENABLE_SDHC                1
#define BSPCFG_ENABLE_I2C0                1
#define BSPCFG_ENABLE_II2C0               1
#define BSPCFG_ENABLE_FLASHX              1

/*
** board-specific MQX settings - see for defaults mqx\source\include\mqx_cnfg.h
*/

#define MQXCFG_ENABLE_FP                  1
#define MQX_INCLUDE_FLOATING_POINT_IO     1

/*
** board-specific RTCS settings - see for defaults rtcs\source\include\rtcscfg.h
*/

#define SHELLCFG_USES_RTCS                0
#define RTCSCFG_ENABLE_LWDNS              1 
#define TELNETDCFG_NOWAIT                 FALSE 


#define BSPCFG_ENABLE_CPP                 1

/*
** include common settings
*/
#define PSP_HAS_SUPPORT_STRUCT  1

/* and enable verification checks in kernel */
#include "verif_enabled_config.h"

#endif
