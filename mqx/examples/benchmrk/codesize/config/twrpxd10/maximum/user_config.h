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
#define MQX_CPU                           PSP_CPU_MPXD10
#define MQX_USE_INTERRUPTS                1
#define MQX_KERNEL_LOGGING                1

#define BSPCFG_ENABLE_IO_SUBSYSTEM        1

/*  PIT to be used as system timer */
#define BSPCFG_TIMER_PIT_DEVICE         (0)
#define BSPCFG_TIMER_PIT_CHANNEL        (0)
#define BSPCFG_TIMER_INT_LEVEL          (1)


#define BSPCFG_ENABLE_CPP                 1
#define BSPCFG_ENABLE_TTYA                1
#define BSPCFG_ENABLE_ITTYA               1
#define BSPCFG_ENABLE_TTYB                1
#define BSPCFG_ENABLE_ITTYB               1

#define BSPCFG_ENABLE_SPI0                1
#define BSPCFG_ENABLE_ISPI0               1
#define BSPCFG_ENABLE_SPI1                1
#define BSPCFG_ENABLE_ISPI1               1

#define BSPCFG_ENABLE_I2C0                1
#define BSPCFG_ENABLE_II2C0               1
#define BSPCFG_ENABLE_I2C1                1
#define BSPCFG_ENABLE_II2C1               1
#define BSPCFG_ENABLE_I2C2                1
#define BSPCFG_ENABLE_II2C2               1
#define BSPCFG_ENABLE_I2C3                1
#define BSPCFG_ENABLE_II2C3               1

#define BSPCFG_ENABLE_RTCDEV              1
#define BSPCFG_ENABLE_PCFLASH             1
#define BSPCFG_ENABLE_FLASHX              1
#define BSPCFG_ENABLE_LWADC               1
/*
** board-specific RTCS settings - see for defaults rtcs\source\include\rtcscfg.h
*/

#define SHELLCFG_USES_RTCS                0


/*
** board-specific for e200z0
*/

#define MQX_PROFILING_ENABLE 0
#define MQX_RUN_TIME_ERR_CHECK_ENABLE 0

/* use the rest of defaults from small-RAM-device profile */
#include "maximum_config.h"
/* and enable verification checks in kernel */
#include "verif_enabled_config.h"

#endif
