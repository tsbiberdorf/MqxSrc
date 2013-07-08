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
* $FileName: mcf52xx_rtc.h$
* $Version : 3.6.7.0$
* $Date    : Jun-4-2010$
*
* Comments:
*
*   This file contains the type definitions for the mcf52xx RTC module.
*
*END************************************************************************/

#ifndef __mcf52xx_rtc_h__
#define __mcf52xx_rtc_h__

#define __mcf52xx_rtc_h__version "$Version:3.6.7.0$"
#define __mcf52xx_rtc_h__date    "$Date:Jun-4-2010$"

#ifdef __cplusplus
extern "C" {
#endif


#define MCF52XX_RTC_HOURMIN_HOURS_WRITE(x)          (((x)&0x1F)<<0x08)
#define MCF52XX_RTC_HOURMIN_MINUTES_WRITE(x)        ((x)&0x3F)
#define MCF52XX_RTC_HOURMIN_HOURS_READ(x)           (((x)>>0x08)&0x1F)
#define MCF52XX_RTC_HOURMIN_MINUTES_READ(x)         ((x)&0x3F)
#define MCF52XX_RTC_SECONDS_READ(x)                 ((x)&0x3F)
#define MCF52XX_RTC_SECONDS_WRITE(x)                ((x)&0x3F)
#define MCF52XX_RTC_ALRM_HM_HOURS_WRITE(x)          (((x)&0x1F)<<0x08)
#define MCF52XX_RTC_ALRM_HM_MINUTES_WRITE(x)        ((x)&0x3F)
#define MCF52XX_RTC_ALRM_HM_HOURS_READ(x)           (((x)>>0x08)&0x1F)
#define MCF52XX_RTC_ALRM_HM_MINUTES_READ(x)         ((x)&0x3F)
#define MCF52XX_RTC_ALRM_SEC_READ(x)                ((x)&0x3F)
#define MCF52XX_RTC_ALRM_SEC_WRITE(x)               ((x)&0x3F)
#define MCF52XX_RTC_RTCCTL_EN                       (1<<7)
#define MCF52XX_RTC_RTCCTL_SWR                      (1<<0)
#define MCF52XX_RTC_RTCISR_SW                       (1<<0)
#define MCF52XX_RTC_RTCISR_MIN                      (1<<1)
#define MCF52XX_RTC_RTCISR_ALM                      (1<<2)
#define MCF52XX_RTC_RTCISR_DAY                      (1<<3)
#define MCF52XX_RTC_RTCISR_1HZ                      (1<<4)
#define MCF52XX_RTC_RTCISR_HR                       (1<<5)
#define MCF52XX_RTC_RTCISR_2HZ                      (1<<7)
#define MCF52XX_RTC_RTCISR_SAM0                     (1<<8)
#define MCF52XX_RTC_RTCISR_SAM1                     (1<<9)
#define MCF52XX_RTC_RTCISR_SAM2                     (1<<10)
#define MCF52XX_RTC_RTCISR_SAM3                     (1<<11)
#define MCF52XX_RTC_RTCISR_SAM4                     (1<<12)
#define MCF52XX_RTC_RTCISR_SAM5                     (1<<13)
#define MCF52XX_RTC_RTCISR_SAM6                     (1<<14)
#define MCF52XX_RTC_RTCISR_SAM7                     (1<<15)
#define MCF52XX_RTC_RTCISR_EN                       (1<<31)
#define MCF52XX_RTC_RTCIENR_SW                      (1<<0)
#define MCF52XX_RTC_RTCIENR_MIN                     (1<<1)
#define MCF52XX_RTC_RTCIENR_ALM                     (1<<2)
#define MCF52XX_RTC_RTCIENR_DAY                     (1<<3)
#define MCF52XX_RTC_RTCIENR_1HZ                     (1<<4)
#define MCF52XX_RTC_RTCIENR_HR                      (1<<5)
#define MCF52XX_RTC_RTCIENR_2HZ                     (1<<7)
#define MCF52XX_RTC_RTCIENR_SAM0                    (1<<8)
#define MCF52XX_RTC_RTCIENR_SAM1                    (1<<9)
#define MCF52XX_RTC_RTCIENR_SAM2                    (1<<10)
#define MCF52XX_RTC_RTCIENR_SAM3                    (1<<11)
#define MCF52XX_RTC_RTCIENR_SAM4                    (1<<12)
#define MCF52XX_RTC_RTCIENR_SAM5                    (1<<13)
#define MCF52XX_RTC_RTCIENR_SAM6                    (1<<14)
#define MCF52XX_RTC_RTCIENR_SAM7                    (1<<15)
#define MCF52XX_RTC_STPWCH_CNT(x)                   ((x)&0x1F)
#define MCF52XX_RTC_DAYS_DAYS(x)                    ((x)&0xFFFF)
#define MCF52XX_RTC_ALRM_DAY_DAYS(x)                ((x)&0xFFFF)


/*
** MCF52XX_RTC_STRUCT
** Real Time Clock                                                                   
*/
typedef struct mcf52xx_rtc_struct
{
   uint_32  HOURMIN;        // RTC Hours and Minutes Counter Register
   uint_32  SECONDS;        // RTC Seconds Counter Register
   uint_32  ALRM_HM;        // RTC Hours and Minutes Alarm Register
   uint_32  ALRM_SEC;       // RTC Seconds Alarm Register
   uint_32  RTCCTL;         // RTC Control Register
   uint_32  RTCISR;         // RTC Interrupt Status Register
   uint_32  RTCIENR;        // RTC Interrupt Enable Register
   uint_32  STPWCH;         // Stopwatch Minutes Register
   uint_16  filler0;        // ONLY 16 bit ACCESS IS ALLOWED !
   uint_16  DAYS;           // RTC Days Counter Register
   uint_16  filler1;        // ONLY 16 bit ACCESS IS ALLOWED !
   uint_16  ALRM_DAY;       // RTC Days Alarm Register
   uchar    filler2[0xC];
   uint_32  RTCGOCU;        // RTC General Oscillator Count Upper Register
   uint_32  RTCGOCL;        // RTC General Oscillator Count Lower Register
   uchar    filler3[0x4];
   
} MCF52XX_RTC_STRUCT, _PTR_ MCF52XX_RTC_STRUCT_PTR;
typedef volatile struct mcf52xx_rtc_struct _PTR_ VMCF52XX_RTC_STRUCT_PTR;


#ifdef __cplusplus
}
#endif

#endif
