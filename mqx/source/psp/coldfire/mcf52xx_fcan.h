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
* $FileName: mcf52xx_fcan.h$
* $Version : 3.6.6.0$
* $Date    : Jun-4-2010$
*
* Comments:
*
*   This file contains the type definitions for the mcf52xx FlexCAN module.
*
*END************************************************************************/

#ifndef __mcf52xx_fcan_h__
#define __mcf52xx_fcan_h__

#define __mcf52xx_fcan_h__version "$Version:3.6.6.0$"
#define __mcf52xx_fcan_h__date    "$Date:Jun-4-2010$"

#ifdef __cplusplus
extern "C" {
#endif

/* Message buffer memory map */
#define FLEXCAN_MSGCTRL_RTR                     (0x00100000)
#define FLEXCAN_MSGCTRL_IDE                     (0x00200000)
#define FLEXCAN_MSGCTRL_SRR                     (0x00400000)
#define FLEXCAN_MSGCRTL_CODE                    (0x0F000000)
#define FLEXCAN_MSG_CTRL_DLEN                   (0x000F0000)
#define FLEXCAN_MSG_DISABLE                     (~ FLEXCAN_MSGCRTL_CODE)

/*
** Message Buffer Codes for Rx Buffers
*/
#define FLEXCAN_RX_MSG_BUFFER_NOT_ACTIVE     (0x00000000)
#define FLEXCAN_RX_MSG_BUFFER_EMPTY          (0x04000000)
#define FLEXCAN_RX_MSG_BUFFER_FULL           (0x02000000)
#define FLEXCAN_RX_MSG_BUFFER_OVERRUN        (0x06000000)
#define FLEXCAN_RX_MSG_BUFFER_BUSY           (0x01000000)

/* Message Buffer Codes for Tx Buffers */
#define FLEXCAN_TX_MSG_BUFFER_NOT_ACTIVE        (0x08000000)
#define FLEXCAN_MESSAGE_TRANSMIT_ONCE           (0x0C000000)
#define FLEXCAN_MESSAGE_TRANSMIT_REMOTE         (0x0C000000)
#define FLEXCAN_MESSAGE_TRANSMIT_RESPONED       (0x0A000000)
#define FLEXCAN_MESSAGE_TRANSMIT_RESPONED_ONLY  (0x0E000000)

/* Interrupt masks */
#define FLEXCAN_WAKEUP_INT              (0x0001)
#define FLEXCAN_ERROR_INT               (0x0002)
#define FLEXCAN_BUSOFF_INT              (0x0004)
#define FLEXCAN_ALL_INT                 (0x0007)
#define FLEXCAN_TX_RX_INT               (~ FLEXCAN_ALL_INT)
#define FLEXCAN_IMASK_VALUE             (0xFFFF)


/*------------------------------------------------------------------------*/
/*
** FCAN  registers bit set.
*/

/* Bit definitions and macros for MCF52XX_FCAN_CANMCR */
#define MCF52XX_FCAN_CANMCR_MAXMB(x)          (((x)&0xF)<<0)
#define MCF52XX_FCAN_CANMCR_LPMACK            (0x100000)
#define MCF52XX_FCAN_CANMCR_SUPV              (0x800000)
#define MCF52XX_FCAN_CANMCR_FRZACK            (0x1000000)
#define MCF52XX_FCAN_CANMCR_SOFTRST           (0x2000000)
#define MCF52XX_FCAN_CANMCR_NOTRDY            (0x8000000)
#define MCF52XX_FCAN_CANMCR_HALT              (0x10000000)
#define MCF52XX_FCAN_CANMCR_FRZ               (0x40000000)
#define MCF52XX_FCAN_CANMCR_MDIS              (0x80000000)

/* Bit definitions and macros for MCF52XX_FCAN_CANCTRL */
#define MCF52XX_FCAN_CANCTRL_PROPSEG(x)       (((x)&0x7)<<0)
#define MCF52XX_FCAN_CANCTRL_LOM              (0x8)
#define MCF52XX_FCAN_CANCTRL_LBUF             (0x10)
#define MCF52XX_FCAN_CANCTRL_TSYNC            (0x20)
#define MCF52XX_FCAN_CANCTRL_BOFFREC          (0x40)
#define MCF52XX_FCAN_CANCTRL_SAMP             (0x80)
#define MCF52XX_FCAN_CANCTRL_LPB              (0x1000)
#define MCF52XX_FCAN_CANCTRL_CLK_SRC          (0x2000)
#define MCF52XX_FCAN_CANCTRL_ERRMSK           (0x4000)
#define MCF52XX_FCAN_CANCTRL_BOFFMSK          (0x8000)
#define MCF52XX_FCAN_CANCTRL_PSEG2(x)         (((x)&0x7)<<0x10)
#define MCF52XX_FCAN_CANCTRL_PSEG1(x)         (((x)&0x7)<<0x13)
#define MCF52XX_FCAN_CANCTRL_RJW(x)           (((x)&0x3)<<0x16)
#define MCF52XX_FCAN_CANCTRL_PRESDIV(x)       (((x)&0xFF)<<0x18)

/* Bit definitions and macros for MCF52XX_FCAN_TIMER */
#define MCF52XX_FCAN_TIMER_TIMER(x)           (((x)&0xFFFF)<<0)

/* Bit definitions and macros for MCF52XX_FCAN_RXGMASK */
#define MCF52XX_FCAN_RXGMASK_MI(x)            (((x)&0x1FFFFFFF)<<0)

/* Bit definitions and macros for MCF52XX_FCAN_RX14MASK */
#define MCF52XX_FCAN_RX14MASK_MI(x)           (((x)&0x1FFFFFFF)<<0)

/* Bit definitions and macros for MCF52XX_FCAN_RX15MASK */
#define MCF52XX_FCAN_RX15MASK_MI(x)           (((x)&0x1FFFFFFF)<<0)

/* Bit definitions and macros for MCF52XX_FCAN_RX15MASK */
#define MCF52XX_FCAN_RX15MASK_MI(x)           (((x)&0x1FFFFFFF)<<0)

/* Bit definitions and macros for ID masks */
#define MCF52XX_FCAN_STANDARD_ID_MASK(x)      (((x)&0x7FF)<<18)
#define MCF52XX_FCAN_EXTENDED_ID_MASK(x)      (((x)&0x1FFFFFFF)<<0)

/* Bit definitions and macros for MCF52XX_FCAN_ERRCNT */
#define MCF52XX_FCAN_ERRCNT_TXECTR(x)         (((x)&0xFF)<<0)
#define MCF52XX_FCAN_ERRCNT_RXECTR(x)         (((x)&0xFF)<<0x8)

/* Bit definitions and macros for MCF52XX_FCAN_ERRSTAT */
#define MCF52XX_FCAN_ERRSTAT_ERRINT           (0x2)
#define MCF52XX_FCAN_ERRSTAT_BOFFINT          (0x4)
#define MCF52XX_FCAN_ERRSTAT_FLTCONF(x)       (((x)&0x3)<<0x4)
#define MCF52XX_FCAN_ERRSTAT_FLTCONF_ACTIVE   (0)
#define MCF52XX_FCAN_ERRSTAT_FLTCONF_PASSIVE  (0x10)
#define MCF52XX_FCAN_ERRSTAT_FLTCONF_BUSOFF   (0x20)
#define MCF52XX_FCAN_ERRSTAT_TXRX             (0x40)
#define MCF52XX_FCAN_ERRSTAT_IDLE             (0x80)
#define MCF52XX_FCAN_ERRSTAT_RXWRN            (0x100)
#define MCF52XX_FCAN_ERRSTAT_TXWRN            (0x200)
#define MCF52XX_FCAN_ERRSTAT_STFERR           (0x400)
#define MCF52XX_FCAN_ERRSTAT_FRMERR           (0x800)
#define MCF52XX_FCAN_ERRSTAT_CRCERR           (0x1000)
#define MCF52XX_FCAN_ERRSTAT_ACKERR           (0x2000)
#define MCF52XX_FCAN_ERRSTAT_BIT0ERR          (0x4000)
#define MCF52XX_FCAN_ERRSTAT_BIT1ERR          (0x8000)

/* Bit definitions and macros for MCF52XX_FCAN_IMASK */
#define MCF52XX_FCAN_IMASK_BUF0M              (0x1)
#define MCF52XX_FCAN_IMASK_BUF1M              (0x2)
#define MCF52XX_FCAN_IMASK_BUF2M              (0x4)
#define MCF52XX_FCAN_IMASK_BUF3M              (0x8)
#define MCF52XX_FCAN_IMASK_BUF4M              (0x10)
#define MCF52XX_FCAN_IMASK_BUF5M              (0x20)
#define MCF52XX_FCAN_IMASK_BUF6M              (0x40)
#define MCF52XX_FCAN_IMASK_BUF7M              (0x80)
#define MCF52XX_FCAN_IMASK_BUF8M              (0x100)
#define MCF52XX_FCAN_IMASK_BUF9M              (0x200)
#define MCF52XX_FCAN_IMASK_BUF10M             (0x400)
#define MCF52XX_FCAN_IMASK_BUF11M             (0x800)
#define MCF52XX_FCAN_IMASK_BUF12M             (0x1000)
#define MCF52XX_FCAN_IMASK_BUF13M             (0x2000)
#define MCF52XX_FCAN_IMASK_BUF14M             (0x4000)
#define MCF52XX_FCAN_IMASK_BUF15M             (0x8000)
#define MCF52XX_FCAN_IMASK_BUF(x)             (0x1<<(x))

/* Bit definitions and macros for MCF52XX_FCAN_IFLAG */
#define MCF52XX_FCAN_IFLAG_BUF0I              (0x1)
#define MCF52XX_FCAN_IFLAG_BUF1I              (0x2)
#define MCF52XX_FCAN_IFLAG_BUF2I              (0x4)
#define MCF52XX_FCAN_IFLAG_BUF3I              (0x8)
#define MCF52XX_FCAN_IFLAG_BUF4I              (0x10)
#define MCF52XX_FCAN_IFLAG_BUF5I              (0x20)
#define MCF52XX_FCAN_IFLAG_BUF6I              (0x40)
#define MCF52XX_FCAN_IFLAG_BUF7I              (0x80)
#define MCF52XX_FCAN_IFLAG_BUF8I              (0x100)
#define MCF52XX_FCAN_IFLAG_BUF9I              (0x200)
#define MCF52XX_FCAN_IFLAG_BUF10I             (0x400)
#define MCF52XX_FCAN_IFLAG_BUF11I             (0x800)
#define MCF52XX_FCAN_IFLAG_BUF12I             (0x1000)
#define MCF52XX_FCAN_IFLAG_BUF13I             (0x2000)
#define MCF52XX_FCAN_IFLAG_BUF14I             (0x4000)
#define MCF52XX_FCAN_IFLAG_BUF15I             (0x8000)
#define MCF52XX_FCAN_IFLAG_BUF(x)             (0x1<<(x))


/*------------------------------------------------------------------------*/
/*
** FCAN registers bit set GENERALIZED
*/

#define FLEXCAN_CANMCR_MAXMB                  MCF52XX_FCAN_CANMCR_MAXMB
#define FLEXCAN_CANMCR_FRZACK                 MCF52XX_FCAN_CANMCR_FRZACK
#define FLEXCAN_CANMCR_SOFTRST                MCF52XX_FCAN_CANMCR_SOFTRST
#define FLEXCAN_CANMCR_HALT                   MCF52XX_FCAN_CANMCR_HALT
#define FLEXCAN_CANMCR_FRZ                    MCF52XX_FCAN_CANMCR_FRZ
#define FLEXCAN_CANMCR_MDIS                   MCF52XX_FCAN_CANMCR_MDIS
#define FLEXCAN_CANMCR_LPMACK                 MCF52XX_FCAN_CANMCR_LPMACK
#define FLEXCAN_CANMCR_NOTRDY                 MCF52XX_FCAN_CANMCR_NOTRDY

#define FLEXCAN_CANCTRL_LOM                   MCF52XX_FCAN_CANCTRL_LOM
#define FLEXCAN_CANCTRL_TSYNC                 MCF52XX_FCAN_CANCTRL_TSYNC
#define FLEXCAN_CANCTRL_LPB                   MCF52XX_FCAN_CANCTRL_LPB
#define FLEXCAN_CANCTRL_BOFFREC               MCF52XX_FCAN_CANCTRL_BOFFREC
#define FLEXCAN_CANCTRL_SAMP                  MCF52XX_FCAN_CANCTRL_SAMP
#define FLEXCAN_CANCTRL_CLK_SRC               MCF52XX_FCAN_CANCTRL_CLK_SRC
#define FLEXCAN_CANCTRL_ERRMSK                MCF52XX_FCAN_CANCTRL_ERRMSK
#define FLEXCAN_CANCTRL_BOFFMSK               MCF52XX_FCAN_CANCTRL_BOFFMSK

#define FLEXCAN_CANCTRL_PROPSEG               MCF52XX_FCAN_CANCTRL_PROPSEG
#define FLEXCAN_CANCTRL_PSEG2                 MCF52XX_FCAN_CANCTRL_PSEG2
#define FLEXCAN_CANCTRL_PSEG1                 MCF52XX_FCAN_CANCTRL_PSEG1
#define FLEXCAN_CANCTRL_RJW                   MCF52XX_FCAN_CANCTRL_RJW
#define FLEXCAN_CANCTRL_PRESDIV               MCF52XX_FCAN_CANCTRL_PRESDIV

#define FLEXCAN_STANDARD_ID_MASK              MCF52XX_FCAN_STANDARD_ID_MASK
#define FLEXCAN_EXTENDED_ID_MASK              MCF52XX_FCAN_EXTENDED_ID_MASK

#define _flexcan_int_init                     _mcf52xx_int_init


/*
** MCF5223_FCAN_STRUCT                                                                   
** FlexCAN Registers
*/
typedef struct mcf52XX_fcan_struct
{   
   uint_32  CANMCR;          // Module Configuration Register
   uint_32  CANCTRL;         // FlexCAN Control Register
   uint_32  TIMER;           // Free Running TImer
   uint_32  filler2; 
   uint_32  RXGMASK;         // Rx Global Mask
   uint_32  RX14MASK;        // Rx Buffer 14 Mask
   uint_32  RX15MASK;        // Rx Buffer 15 Mask
   uint_32  ERRCNT;          // Error Counter Register
   uint_32  ERRSTAT;         // Error and Status
   uint_32  filler3; 
   uint_32  IMASK;           // Interrupt Mask Register
   uint_32  filler4;
   uint_32  IFLAG;           // Interrupt Flag Register  
} MCF52XX_FCAN_STRUCT, _PTR_ MCF52XX_FCAN_STRUCT_PTR;
typedef volatile struct mcf52XX_fcan_struct _PTR_ VMCF52XX_FCAN_STRUCT_PTR;

/* FlexCAN MSG Object structure */
typedef struct mcf52xx_flexcan_msg_struct
{
   uint_32 CONTROL;            /* CTRL/STATUS */
   uint_32 ID;                 /* ID */
   uchar   DATA[8];              /* bytes Data Field */

} MCF52XX_FCAN_MSG_STRUCT, _PTR_ MCF52XX_FCAN_MSG_STRUCT_PTR;
typedef volatile struct mcf52xx_flexcan_msg_struct VMCF52XX_FCAN_MSG_STRUCT;
typedef volatile struct mcf52xx_flexcan_msg_struct _PTR_ VMCF52XX_FCAN_MSG_STRUCT_PTR;

typedef VMCF52XX_FCAN_MSG_STRUCT      FLEXCAN_MSG_OBJECT_STRUCT;
typedef VMCF52XX_FCAN_MSG_STRUCT_PTR  FLEXCAN_MSG_OBJECT_STRUCT_PTR;
typedef VMCF52XX_FCAN_STRUCT_PTR      FLEXCAN_REG_STRUCT_PTR;

#ifdef __cplusplus
}
#endif

#endif  //__mcf52xx_fcan_h__
