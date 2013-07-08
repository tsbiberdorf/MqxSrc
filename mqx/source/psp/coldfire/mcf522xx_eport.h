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
* $FileName: mcf522xx_eport.h$
* $Version : 3.0.2.0$
* $Date    : Apr-23-2009$
*
* Comments:
*
*   This file contains the type definitions for the mcf522xx EPORT module.
*
*END************************************************************************/

#ifndef __mcf522xx_eport_h__
#define __mcf522xx_eport_h__

#define __mcf522xx_eport_h__version "$Version:3.0.2.0$"
#define __mcf522xx_eport_h__date    "$Date:Apr-23-2009$"

#ifdef __cplusplus
extern "C" {
#endif

/*------------------------------------------------------------------------*/
/*
** EPORT  registers bit set.
*/

/* Bit definitions and macros for MCF522XX_EPORT_EPPAR */
#define MCF522XX_EPORT_EPPAR_EPPA1(x)             (((x)&0x3)<<0x2)
#define MCF522XX_EPORT_EPPAR_EPPA1_LEVEL          (0)
#define MCF522XX_EPORT_EPPAR_EPPA1_RISING         (0x4)
#define MCF522XX_EPORT_EPPAR_EPPA1_FALLING        (0x8)
#define MCF522XX_EPORT_EPPAR_EPPA1_BOTH           (0xC)
#define MCF522XX_EPORT_EPPAR_EPPA2(x)             (((x)&0x3)<<0x4)
#define MCF522XX_EPORT_EPPAR_EPPA2_LEVEL          (0)
#define MCF522XX_EPORT_EPPAR_EPPA2_RISING         (0x10)
#define MCF522XX_EPORT_EPPAR_EPPA2_FALLING        (0x20)
#define MCF522XX_EPORT_EPPAR_EPPA2_BOTH           (0x30)
#define MCF522XX_EPORT_EPPAR_EPPA3(x)             (((x)&0x3)<<0x6)
#define MCF522XX_EPORT_EPPAR_EPPA3_LEVEL          (0)
#define MCF522XX_EPORT_EPPAR_EPPA3_RISING         (0x40)
#define MCF522XX_EPORT_EPPAR_EPPA3_FALLING        (0x80)
#define MCF522XX_EPORT_EPPAR_EPPA3_BOTH           (0xC0)
#define MCF522XX_EPORT_EPPAR_EPPA4(x)             (((x)&0x3)<<0x8)
#define MCF522XX_EPORT_EPPAR_EPPA4_LEVEL          (0)
#define MCF522XX_EPORT_EPPAR_EPPA4_RISING         (0x100)
#define MCF522XX_EPORT_EPPAR_EPPA4_FALLING        (0x200)
#define MCF522XX_EPORT_EPPAR_EPPA4_BOTH           (0x300)
#define MCF522XX_EPORT_EPPAR_EPPA5(x)             (((x)&0x3)<<0xA)
#define MCF522XX_EPORT_EPPAR_EPPA5_LEVEL          (0)
#define MCF522XX_EPORT_EPPAR_EPPA5_RISING         (0x400)
#define MCF522XX_EPORT_EPPAR_EPPA5_FALLING        (0x800)
#define MCF522XX_EPORT_EPPAR_EPPA5_BOTH           (0xC00)
#define MCF522XX_EPORT_EPPAR_EPPA6(x)             (((x)&0x3)<<0xC)
#define MCF522XX_EPORT_EPPAR_EPPA6_LEVEL          (0)
#define MCF522XX_EPORT_EPPAR_EPPA6_RISING         (0x1000)
#define MCF522XX_EPORT_EPPAR_EPPA6_FALLING        (0x2000)
#define MCF522XX_EPORT_EPPAR_EPPA6_BOTH           (0x3000)
#define MCF522XX_EPORT_EPPAR_EPPA7(x)             (((x)&0x3)<<0xE)
#define MCF522XX_EPORT_EPPAR_EPPA7_LEVEL          (0)
#define MCF522XX_EPORT_EPPAR_EPPA7_RISING         (0x4000)
#define MCF522XX_EPORT_EPPAR_EPPA7_FALLING        (0x8000)
#define MCF522XX_EPORT_EPPAR_EPPA7_BOTH           (0xC000)
#define MCF522XX_EPORT_EPPAR_LEVEL                (0)
#define MCF522XX_EPORT_EPPAR_RISING               (0x1)
#define MCF522XX_EPORT_EPPAR_FALLING              (0x2)
#define MCF522XX_EPORT_EPPAR_BOTH                 (0x3)

/* Bit definitions and macros for MCF522XX_EPORT_EPDDR */
#define MCF522XX_EPORT_EPDDR_EPDD1                (0x2)
#define MCF522XX_EPORT_EPDDR_EPDD2                (0x4)
#define MCF522XX_EPORT_EPDDR_EPDD3                (0x8)
#define MCF522XX_EPORT_EPDDR_EPDD4                (0x10)
#define MCF522XX_EPORT_EPDDR_EPDD5                (0x20)
#define MCF522XX_EPORT_EPDDR_EPDD6                (0x40)
#define MCF522XX_EPORT_EPDDR_EPDD7                (0x80)

/* Bit definitions and macros for MCF522XX_EPORT_EPIER */
#define MCF522XX_EPORT_EPIER_EPIE1                (0x2)
#define MCF522XX_EPORT_EPIER_EPIE2                (0x4)
#define MCF522XX_EPORT_EPIER_EPIE3                (0x8)
#define MCF522XX_EPORT_EPIER_EPIE4                (0x10)
#define MCF522XX_EPORT_EPIER_EPIE5                (0x20)
#define MCF522XX_EPORT_EPIER_EPIE6                (0x40)
#define MCF522XX_EPORT_EPIER_EPIE7                (0x80)

/* Bit definitions and macros for MCF522XX_EPORT_EPDR */
#define MCF522XX_EPORT_EPDR_EPD1                  (0x2)
#define MCF522XX_EPORT_EPDR_EPD2                  (0x4)
#define MCF522XX_EPORT_EPDR_EPD3                  (0x8)
#define MCF522XX_EPORT_EPDR_EPD4                  (0x10)
#define MCF522XX_EPORT_EPDR_EPD5                  (0x20)
#define MCF522XX_EPORT_EPDR_EPD6                  (0x40)
#define MCF522XX_EPORT_EPDR_EPD7                  (0x80)

/* Bit definitions and macros for MCF522XX_EPORT_EPPDR */
#define MCF522XX_EPORT_EPPDR_EPPD1                (0x2)
#define MCF522XX_EPORT_EPPDR_EPPD2                (0x4)
#define MCF522XX_EPORT_EPPDR_EPPD3                (0x8)
#define MCF522XX_EPORT_EPPDR_EPPD4                (0x10)
#define MCF522XX_EPORT_EPPDR_EPPD5                (0x20)
#define MCF522XX_EPORT_EPPDR_EPPD6                (0x40)
#define MCF522XX_EPORT_EPPDR_EPPD7                (0x80)

/* Bit definitions and macros for MCF522XX_EPORT_EPFR */
#define MCF522XX_EPORT_EPFR_EPF1                  (0x2)
#define MCF522XX_EPORT_EPFR_EPF2                  (0x4)
#define MCF522XX_EPORT_EPFR_EPF3                  (0x8)
#define MCF522XX_EPORT_EPFR_EPF4                  (0x10)
#define MCF522XX_EPORT_EPFR_EPF5                  (0x20)
#define MCF522XX_EPORT_EPFR_EPF6                  (0x40)
#define MCF522XX_EPORT_EPFR_EPF7                  (0x80)


/*
** MCF522XX_EPORT_STRUCT                                                                  
** Programmable interrupt timer
*/
typedef struct mcf522xx_eport_struct
{
   uint_16  EPPAR;          // EPORT pin assignment register
   uchar    EPDDR;          // EPORT data direction register
   uchar    EPIER;          // EPORT interrupt enable register
   uchar    EPDR;           // EPORT data register
   uchar    EPPDR;          // EPORT pin data register
   uchar    EPFR;           // EPORT flag register
   uchar    filler1[0xFFF9];
} MCF522XX_EPORT_STRUCT, _PTR_ MCF522XX_EPORT_STRUCT_PTR;
typedef volatile struct mcf522xx_eport_struct _PTR_ VMCF522XX_EPORT_STRUCT_PTR;

#ifdef __cplusplus
}
#endif

#endif  //__mcf522xx_eport_h__
