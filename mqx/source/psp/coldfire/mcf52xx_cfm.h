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
* $FileName: mcf52xx_cfm.h$
* $Version : 3.0.1.0$
* $Date    : May-21-2009$
*
* Comments:
*
*   This file contains the type definitions for the MCF52XX PIT module.
*
*END************************************************************************/

#ifndef __mcf52xx_cfm_h__
#define __mcf52xx_cfm_h__

#define __mcf52xx_cfm_h__version "$Version:3.0.1.0$"
#define __mcf52xx_cfm_h__date    "$Date:May-21-2009$"

#ifdef __cplusplus
extern "C" {
#endif

/*------------------------------------------------------------------------*/
/*
** CFM  registers bit set.
*/
/* Bit definitions and macros for MCF52XX_CFM_CFMMCR */
#define MCF52XX_CFM_CFMMCR_KEYACC                (0x20)
#define MCF52XX_CFM_CFMMCR_CCIE                  (0x40)
#define MCF52XX_CFM_CFMMCR_CBEIE                 (0x80)
#define MCF52XX_CFM_CFMMCR_AEIE                  (0x100)
#define MCF52XX_CFM_CFMMCR_PVIE                  (0x200)
#define MCF52XX_CFM_CFMMCR_LOCK                  (0x400)

/* Bit definitions and macros for MCF52XX_CFM_CFMCLKD */
#define MCF52XX_CFM_CFMCLKD_DIV(x)               (((x)&0x3F)<<0)
#define MCF52XX_CFM_CFMCLKD_PRDIV8               (0x40)
#define MCF52XX_CFM_CFMCLKD_DIVLD                (0x80)

/* Bit definitions and macros for MCF52XX_CFM_CFMSEC */
#define MCF52XX_CFM_CFMSEC_SEC(x)                (((x)&0xFFFF)<<0)
#define MCF52XX_CFM_CFMSEC_SECSTAT               (0x40000000)
#define MCF52XX_CFM_CFMSEC_KEYEN                 (0x80000000)

/* Bit definitions and macros for MCF52XX_CFM_CFMPROT */
#define MCF52XX_CFM_CFMPROT_PROTECT(x)           (((x)&0xFFFFFFFF)<<0)

/* Bit definitions and macros for MCF52XX_CFM_CFMSACC */
#define MCF52XX_CFM_CFMSACC_SUPV(x)              (((x)&0xFFFFFFFF)<<0)

/* Bit definitions and macros for MCF52XX_CFM_CFMDACC */
#define MCF52XX_CFM_CFMDACC_DACC(x)              (((x)&0xFFFFFFFF)<<0)

/* Bit definitions and macros for MCF52XX_CFM_CFMUSTAT */
#define MCF52XX_CFM_CFMUSTAT_BLANK               (0x4)
#define MCF52XX_CFM_CFMUSTAT_ACCERR              (0x10)
#define MCF52XX_CFM_CFMUSTAT_PVIOL               (0x20)
#define MCF52XX_CFM_CFMUSTAT_CCIF                (0x40)
#define MCF52XX_CFM_CFMUSTAT_CBEIF               (0x80)

/* Bit definitions and macros for MCF52XX_CFM_CFMCMD */
#define MCF52XX_CFM_CFMCMD_CMD(x)                (((x)&0x7F)<<0)
#define MCF52XX_CFM_CFMCMD_BLANK_CHECK           (0x5)
#define MCF52XX_CFM_CFMCMD_PAGE_ERASE_VERIFY     (0x6)
#define MCF52XX_CFM_CFMCMD_WORD_PROGRAM          (0x20)
#define MCF52XX_CFM_CFMCMD_PAGE_ERASE            (0x40)
#define MCF52XX_CFM_CFMCMD_MASS_ERASE            (0x41)

/* Bit definitions and macros for MCF52XX_CFM_CFMCLKSEL */
#define MCF52XX_CFM_CFMCLKSEL_CLKSEL(x)          (((x)&0x3)<<0)

/*
** MCF5225_CFM_STRUCT                                                                   
** Internal flash registers
*/
typedef struct MCF52XX_cfm_struct
{
   uint_16  CFMMCR;         // CFM Configuration Register
   uchar    CFMCLKD;        // CFM Clock Divider Register
   uchar    filler1[5];
   uint_32  CFMSEC;         // CFM Security Register
   uchar    filler2[4];
   uint_32  CFMPROT;        // CFM Protection Register
   uint_32  CFMSACC;        // CFM Supervisor Access Register
   uint_32  CFMDACC;        // CFM Data Access Register
   uchar    filler3[4];
   uchar    CFMUSTAT;       // CFM User Status Register
   uchar    filler4[3];
   uchar    CFMCMD;         // CFM Command Register
   uchar    filler5[37];
   uint_16  CFMCLKSEL;      // CFM Clock Select Register
   uchar    filler[0xFFB3]; 
} MCF52XX_CFM_STRUCT, _PTR_ MCF52XX_CFM_STRUCT_PTR;
typedef volatile struct MCF52XX_cfm_struct _PTR_ VMCF52XX_CFM_STRUCT_PTR;

#ifdef __cplusplus
}
#endif

#endif  //__mcf52xx_cfm_h__
