/**HEADER********************************************************************
* 
* Copyright (c) 2009 Freescale Semiconductor;
* All Rights Reserved                       
*
* Copyright (c) 1989-2009 ARC International;
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
* $FileName: mcf5xxx_fec.h$
* $Version : 3.6.4.0$
* $Date    : Jun-4-2010$
*
* Comments:
*
*   This file contains the type definitions for the ColdFire 32-bit FEC module.
*
*END************************************************************************/

#ifndef __mcf5xxx_fec_h__
#define __mcf5xxx_fec_h__

#define __mcf5xxx_fec_h__version "$Version:3.6.4.0$"
#define __mcf5xxx_fec_h__date    "$Date:Jun-4-2010$"

#ifdef __cplusplus
extern "C" {
#endif


/*------------------------------------------------------------------------*/
/*
** ENET FEC  registers bit set.
*/

/* FEC Ethernet Buffer descriptor bits */
#define MCF5XXX_FEC_BD_ETHER_RX_EMPTY                (1<<15)
#define MCF5XXX_FEC_BD_ETHER_RX_WRAP                 (1<<13)

/* The following are status bits set after reception */
#define MCF5XXX_FEC_BD_ETHER_RX_LAST_FRAME           (1<<11)
#define MCF5XXX_FEC_BD_ETHER_RX_MISS                 (1<<8)
#define MCF5XXX_FEC_BD_ETHER_RX_BROADCAST            (1<<7)
#define MCF5XXX_FEC_BD_ETHER_RX_MULTICAST            (1<<6)
#define MCF5XXX_FEC_BD_ETHER_RX_LENGTH_VIOLATION     (1<<5)
#define MCF5XXX_FEC_BD_ETHER_RX_NON_OCTET            (1<<4)
#define MCF5XXX_FEC_BD_ETHER_RX_CRC_ERROR            (1<<2)
#define MCF5XXX_FEC_BD_ETHER_RX_OVERRUN              (1<<1)
#define MCF5XXX_FEC_BD_ETHER_RX_TRUNCATED            (1<<0)

#define MCF5XXX_FEC_BD_ETHER_TX_READY                (1<<15)
#define MCF5XXX_FEC_BD_ETHER_TX_SOFTWARE_OWNERSHIP_1 (1<<14)
#define MCF5XXX_FEC_BD_ETHER_TX_WRAP                 (1<<13)
#define MCF5XXX_FEC_BD_ETHER_TX_SOFTWARE_OWNERSHIP_2 (1<<12)
#define MCF5XXX_FEC_BD_ETHER_TX_LAST                 (1<<11)
#define MCF5XXX_FEC_BD_ETHER_TX_SEND_CRC             (1<<10)
#define MCF5XXX_FEC_BD_ETHER_TX_BAD_CRC              (1<<9)

/* FEC Ethernet Control Register */
#define MCF5XXX_FEC_ECR_ETHER_EN                 (0x00000002)
#define MCF5XXX_FEC_ECR_RESET                    (0x00000001)

/* FEC Interrupt Event Register */
#define MCF5XXX_FEC_EIR_ALL_PENDING              (0xFFF80000)
#define MCF5XXX_FEC_EIR_HBERR                    (0x80000000)
#define MCF5XXX_FEC_EIR_BABR                     (0x40000000)
#define MCF5XXX_FEC_EIR_BABT                     (0x20000000)
#define MCF5XXX_FEC_EIR_GRA                      (0x10000000)
#define MCF5XXX_FEC_EIR_TXF                      (0x08000000)
#define MCF5XXX_FEC_EIR_TXB                      (0x04000000)
#define MCF5XXX_FEC_EIR_RXF                      (0x02000000)
#define MCF5XXX_FEC_EIR_RXB                      (0x01000000)
#define MCF5XXX_FEC_EIR_MII                      (0x00800000)
#define MCF5XXX_FEC_EIR_EBERR                    (0x00400000)
#define MCF5XXX_FEC_EIR_LC                       (0x00200000)
#define MCF5XXX_FEC_EIR_RL                       (0x00100000)
#define MCF5XXX_FEC_EIR_UN                       (0x00080000)

/* FEC Interrupt Mask Register */
#define MCF5XXX_FEC_EIMR_MASK_ALL                (0xFFF80000)
#define MCF5XXX_FEC_EIMR_HBERR                   (0x80000000)
#define MCF5XXX_FEC_EIMR_BABR                    (0x40000000)
#define MCF5XXX_FEC_EIMR_BABT                    (0x20000000)
#define MCF5XXX_FEC_EIMR_GRA                     (0x10000000)
#define MCF5XXX_FEC_EIMR_TXF                     (0x08000000)
#define MCF5XXX_FEC_EIMR_TXB                     (0x04000000)
#define MCF5XXX_FEC_EIMR_RXF                     (0x02000000)
#define MCF5XXX_FEC_EIMR_RXB                     (0x01000000)
#define MCF5XXX_FEC_EIMR_MII                     (0x00800000)
#define MCF5XXX_FEC_EIMR_EBERR                   (0x00400000)
#define MCF5XXX_FEC_EIMR_LC                      (0x00200000)
#define MCF5XXX_FEC_EIMR_RL                      (0x00100000)
#define MCF5XXX_FEC_EIMR_UN                      (0x00080000)


/* FEC Receive Descriptor Active Register */
#define MCF5XXX_FEC_RDAR_ACTIVE                  (1<<24)

/* FEC Transmit Descriptor Active Register */
#define MCF5XXX_FEC_TDAR_ACTIVE                  (1<<24)

/* FEC Receive Control Register */
#define MCF5XXX_FEC_RCR_RMII_10T                 (1 << 9)
#define MCF5XXX_FEC_RCR_RMII_MODE                (1 << 8)

#define MCF5XXX_FEC_RCR_FCE                      (0x00000020)
#define MCF5XXX_FEC_RCR_BC_REJ                   (0x00000010)
#define MCF5XXX_FEC_RCR_PROM                     (0x00000008)
#define MCF5XXX_FEC_RCR_MII_MODE                 (0x00000004)
#define MCF5XXX_FEC_RCR_DRT                      (0x00000002)
#define MCF5XXX_FEC_RCR_LOOP                     (0x00000001)
#define MCF5XXX_FEC_RCR_FRAME_LENGTH(x)          (((x)&0x7ff)<<16)

/* FEC Transmit Control Register */
#define MCF5XXX_FEC_TCR_FDEN                     (0x00000004)
#define MCF5XXX_FEC_TCR_HBC                      (0x00000002)
#define MCF5XXX_FEC_TCR_GTS                      (0x00000001)

/* MII Management Frame Register */
#define MCF5XXX_FEC_MII_START_OF_FRAME           (0x40000000)
#define MCF5XXX_FEC_MII_OPCODE_READ              (0x20000000)
#define MCF5XXX_FEC_MII_OPCODE_WRITE             (0x10000000)
#define MCF5XXX_FEC_MII_PA(x)                    (((x)&0x1F)<<23)
#define MCF5XXX_FEC_MII_RA(x)                    (((x)&0x1F)<<18)
#define MCF5XXX_FEC_MII_DATA(x)                  (((x)&0xFFFF))
#define MCF5XXX_FEC_MII_TURNAROUND               (0x00020000)
#define MCF5XXX_FEC_MII_MSCR_PREAMBLE            (1<<7)
#define MCF5XXX_FEC_MII_MSCR_SPEED(x)            (((x) 0x3F) << 1)

#define MCF5XXX_FEC_SIM_ICR_ERX_IL(a)                ( 0x00000800 | (((a)&0x07)<<8) )
#define MCF5XXX_FEC_SIM_ICR_ETX_IL(a)                ( 0x00000080 | (((a)&0x07)<<4) )
#define MCF5XXX_FEC_SIM_ICR_ENTC_IL(a)               ( 0x00000008 | ((a)&0x07) )


#define MCF5XXX_FEC_INT_TX_INTF 0       // Transmit frame interrupt
#define MCF5XXX_FEC_INT_TX_INTB 1       // Transmit buffer interrupt
#define MCF5XXX_FEC_INT_TX_UN   2       // Transmit FIFO underrun
#define MCF5XXX_FEC_INT_RL      3       // Collision retry limit
#define MCF5XXX_FEC_INT_RX_INTF 4       // Receive frame interrupt
#define MCF5XXX_FEC_INT_RX_INTB 5       // Receive buffer interrupt
#define MCF5XXX_FEC_INT_MII     6       // MII interrupt
#define MCF5XXX_FEC_INT_LC      7       // Late collision
#define MCF5XXX_FEC_INT_HBERR   8       // Heartbeat error
#define MCF5XXX_FEC_INT_GRA     9       // Graceful stop complete
#define MCF5XXX_FEC_INT_EBERR   10      // Ethernet bus error
#define MCF5XXX_FEC_INT_BABT    11      // Babbling transmit error
#define MCF5XXX_FEC_INT_BABR    12      // Babbling receive error
#define MCF5XXX_FEC_NUM_INTS    13      


/*
** MCF5XXX_FEC_STRUCT
** Fast Ethernet Controller registers
*/
typedef struct mcf5xxx_fec_struct
{
   uchar    filler1[4];
   uint_32  EIR;             // Ethernet interrupt event register
   uint_32  EIMR;            // Ethernet interrupt mask register
   uint_32  removed_IVSR;    // does not exist - Ethernet interrupt vector status
   uint_32  RDAR;            // Ethernet Rx ring updated flag
   uint_32  TDAR;            // Ethernet Tx ring updated flag
   uchar    filler2[12];
   uint_32  ECR;             // Ethernet control register
   uchar    filler3[24];
#define MMFR MDATA
   uint_32  MDATA;           // Ethernet MII data register
   uint_32  MSCR;            // Ethernet MII speed register
   uchar    filler4[28];
   uint_32  MIBC;            // MIB control/status register
   uchar    filler5[28];
   uint_32  RCR;             // Ethernet Rx control register
   uchar    filler6[60];
   uint_32  TCR;             // Ethernet Tx control register
   uchar    filler7[28];
   uint_32  PALR;            // Physical address low
   uint_32  PAUR;            // Physical address high + type field
   uint_32  OPD;             // Opcode + pause duration
   uchar    filler8[40];
   uint_32  IAUR;            // Upper 32-bits of individual hash table
   uint_32  IALR;            // Lower 32-bits of individual hash table
   uint_32  GAUR;            // Upper 32-bits of group hash table
   uint_32  GALR;            // Lower 32-bits of group hash table
   uchar    filler9[28];
   uint_32  TFWR;            // Transmit FIFO watermark
   uchar    filler10[4];
   uint_32  FRBR;            // Ethernet receive bound register
   uint_32  FRSR;            // Ethernet Rx FIFO start address
   uchar    filler11[44];
   uint_32  ERDSR;           // Ethernet Rx descriptor ring
   uint_32  ETDSR;           // Ethernet Tx descriptor ring
   uint_32  EMRBR;           // Ethernet Rx buffer size
   uchar    filler12[116];
   uchar    MIB_RAM[512];      // Ram to store FEC counters
   uchar    filler13[1024]; // FEC FIFO memory
} MCF5XXX_FEC_STRUCT, _PTR_ MCF5XXX_FEC_STRUCT_PTR;
typedef volatile struct mcf5xxx_fec_struct _PTR_ VMCF5XXX_FEC_STRUCT_PTR;

/*
** MCF5XXX_FEC_BD_STRUCT
** This structure defines what the Ethernet buffer descriptor looks like
*/
typedef struct mcf5xxx_fec_bd_struct
{
   uint_16      CONTROL;
   uint_16      LENGTH;
   uchar_ptr    BUFFER;
} MCF5XXX_FEC_BD_STRUCT, _PTR_ MCF5XXX_FEC_BD_STRUCT_PTR;
typedef volatile struct mcf5xxx_fec_bd_struct _PTR_ VMCF5XXX_FEC_BD_STRUCT_PTR;

#ifdef __cplusplus
}
#endif


#endif
