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
* $FileName: mcf52xx_uart.h$
* $Version : 3.6.5.0$
* $Date    : Dec-3-2010$
*
* Comments:
*
*   This file contains the type definitions for the mcf52xx QSPI module.
*
*END************************************************************************/

#ifndef __mcf52xx_uart_h__
#define __mcf52xx_uart_h__

#define __mcf52xx_uart_h__version "$Version:3.6.5.0$"
#define __mcf52xx_uart_h__date    "$Date:Dec-3-2010$"

#ifdef __cplusplus
extern "C" {
#endif

/*------------------------------------------------------------------------*/
/*
** UART registers
*/
#define MCF52XX_UART_UMR1_RXRTS             (0x80)
#define MCF52XX_UART_UMR1_RXIRQ             (0x40)
#define MCF52XX_UART_UMR1_ERR               (0x20)
#define MCF52XX_UART_UMR1_EVEN_PARITY       (0x00)
#define MCF52XX_UART_UMR1_ODD_PARITY        (0x04)
#define MCF52XX_UART_UMR1_LOW_PARITY        (0x08)
#define MCF52XX_UART_UMR1_HI_PARITY         (0x0C)
#define MCF52XX_UART_UMR1_NO_PARITY         (0x10)
#define MCF52XX_UART_UMR1_MULTI_DROP        (0x18)
#define MCF52XX_UART_UMR1_MD_ADDRESS        (0x1C)
#define MCF52XX_UART_UMR1_5_BITS            (0x00)
#define MCF52XX_UART_UMR1_6_BITS            (0x01)
#define MCF52XX_UART_UMR1_7_BITS            (0x02)
#define MCF52XX_UART_UMR1_8_BITS            (0x03)
#define MCF52XX_UART_UMR1_MASK_DATA_BITS    (0x03)

#define MCF52XX_UART_UMR2_AUTO_ECHO         (0x40)
#define MCF52XX_UART_UMR2_LOCAL_LOOP        (0x80)
#define MCF52XX_UART_UMR2_RMT_LOOP          (0xC0)
#define MCF52XX_UART_UMR2_TXRTS             (0x20)
#define MCF52XX_UART_UMR2_TXCTS             (0x10)
#define MCF52XX_UART_UMR2_1_STOP_BIT        (0x07)
#define MCF52XX_UART_UMR2_2_STOP_BITS       (0x0F)
#define MCF52XX_UART_UMR2_MASK_STOP_BITS    (0x0F)

#define MCF52XX_UART_USR_RB                 (0x80)
#define MCF52XX_UART_USR_FE                 (0x40)
#define MCF52XX_UART_USR_PE                 (0x20)
#define MCF52XX_UART_USR_OE                 (0x10)
#define MCF52XX_UART_USR_TXEMP              (0x08)
#define MCF52XX_UART_USR_TXRDY              (0x04)
#define MCF52XX_UART_USR_FFULL              (0x02)
#define MCF52XX_UART_USR_RXRDY              (0x01)

#define MCF52XX_UART_UCSR_RX_TIMER          (0xD0)
#define MCF52XX_UART_UCSR_RXCLK16           (0xE0)
#define MCF52XX_UART_UCSR_RXCLK1            (0xF0)
#define MCF52XX_UART_UCSR_TX_TIMER          (0x0D)
#define MCF52XX_UART_UCSR_TXCLK16           (0x0E)
#define MCF52XX_UART_UCSR_TXCLK1            (0x0F)

#define MCF52XX_UART_UCR_RESET_POINTER      (0x10)
#define MCF52XX_UART_UCR_RESET_RX           (0x20)
#define MCF52XX_UART_UCR_RESET_TX           (0x30)
#define MCF52XX_UART_UCR_RESET_ERROR        (0x40)
#define MCF52XX_UART_UCR_RESET_BREAK        (0x50)
#define MCF52XX_UART_UCR_START_BREAK        (0x60)
#define MCF52XX_UART_UCR_STOP_BREAK         (0x70)
#define MCF52XX_UART_UCR_AUTOBAUD           (0x80)
#define MCF52XX_UART_UCR_TX_ENABLE          (0x04)
#define MCF52XX_UART_UCR_TX_DISABLE         (0x08)
#define MCF52XX_UART_UCR_RX_ENABLE          (0x01)
#define MCF52XX_UART_UCR_RX_DISABLE         (0x02)

#define MCF52XX_UART_UIPCR_CTS_CHANGE       (0x10)
#define MCF52XX_UART_UIPCR_CTS              (0x01)

#define MCF52XX_UART_UACR_INPUT_CNTRL       (0x01)

#define MCF52XX_UART_UISR_CHANGE_STATE      (0x80)
#define MCF52XX_UART_UISR_CHANGE_BRK        (0x04)
#define MCF52XX_UART_UISR_RXRDY             (0x02)
#define MCF52XX_UART_UISR_TXRDY             (0x01)

#define MCF52XX_UART_UIMR_CHANGE_STATE      (0x80)
#define MCF52XX_UART_UIMR_CHANGE_BRK        (0x04)
#define MCF52XX_UART_UIMR_FFULL             (0x02)
#define MCF52XX_UART_UIMR_TXRDY             (0x01)

#define MCF52XX_UART_UIP_CTS                (0x01)

#define MCF52XX_UART_UOP_RTS                (0x01)

/*------------------------------------------------------------------------*/

/*
** MCF52XX_UART_STRUCT
** This structure defines what one uart register look like
*/
typedef union mcf52xx_uart_struct
{
   struct  {
      uchar UMR;             // UART mode register
      uchar filler1[3];
      uchar USR;             // UART status register
      uchar filler2[3];
      uchar filler4a;             
      uchar filler4[3];
      uchar URB;             // (Read) UART Receive Buffer 
      uchar filler5[3];
      uchar UIPCR;           // (Read) UART Input Port Change Register 
      uchar filler6[3];
      uchar UISR;            // (Read) UART Interrupt Status Register 
      uchar filler7[3];
      uchar filler9a;            
      uchar filler9[3];
      uchar filler10a;            
      uchar filler10[3];
      uchar filler11[0x0234 - 0x021C - 3 - 1];
      uchar UIP;             // (Read) UART Input Port Register
      uchar filler12[3];
      uchar filler13a;            
      uchar filler13[3];
      uchar filler14a;     // (Write) UART Output Port Bit Reset Command Register
      uchar filler14[3];
   } READ;
   struct  {
      uchar UMR;             // UART mode register
      uchar filler1[3];
      uchar UCSR;             // UART status register
      uchar filler2[3];
      uchar UCR;             // (Write) UART Command Register
      uchar filler4[3];
      uchar UTB;             //  (Write) UART Transmit Buffer
      uchar filler5[3];
      uchar UACR;            //  (Write) UART Auxiliary Control Register
      uchar filler6[3];
      uchar UIMR;            // (Write) UART Interrupt Mask Register
      uchar filler7[3];
      uchar UBG1;            // (Write) UART Baud Rate Generator Register 1
      uchar filler9[3];
      uchar UBG2;            // (Write) UART Baud Rate Generator Register 2
      uchar filler10[3];
      uchar filler11[0x0234 - 0x021C - 3 - 1];
      uchar filler12a;             
      uchar filler12[3];
      uchar UOP1;            // (Write) UART Output Port Bit Set Command Register 0
      uchar filler13[3];
      uchar UOP0;             // (Write) UART Output Port Bit Reset Command Register
   } WRITE;
} MCF52XX_UART_STRUCT, _PTR_ MCF52XX_UART_STRUCT_PTR;

#ifdef __cplusplus
}
#endif

#endif  //__mcf52xx_fcan_h__

