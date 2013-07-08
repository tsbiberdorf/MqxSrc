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
* $FileName: reg_enet.h$
* $Version : 3.7.5.0$
* $Date    : Feb-7-2011$
*
* Comments:
*
*   This file contains the type definitions for the ColdFire 32-bit 
*   MAC_NET module.
*
*END************************************************************************/

#ifndef __reg_enet_h__
#define __reg_enet_h__

#define __reg_enet_h__version "$Version:3.7.5.0$"
#define __reg_enet_h__date    "$Date:Feb-7-2011$"

#ifdef __cplusplus
extern "C" {
#endif

/* ----------------------------------------------------------------------------
   -- ENET
   ---------------------------------------------------------------------------- */

/*! \addtogroup ENET_Peripheral ENET */
/*! \{ */


/*! ENET - Peripheral register structure */
typedef struct  {
  uint_8 RESERVED_0[4];
  uint_32 EIR;                                    /*!< Interrupt Event Register, offset: 0x4 */
  uint_32 EIMR;                                   /*!< Interrupt Mask Register, offset: 0x8 */
  uint_8 RESERVED_1[4];
  uint_32 RDAR;                                   /*!< Receive Descriptor Active Register, offset: 0x10 */
  uint_32 TDAR;                                   /*!< Transmit Descriptor Active Register, offset: 0x14 */
  uint_8 RESERVED_2[12];
  uint_32 ECR;                                    /*!< Ethernet Control Register, offset: 0x24 */
  uint_8 RESERVED_3[24];
  uint_32 MMFR;                                   /*!< MII Management Frame Register, offset: 0x40 */
  uint_32 MSCR;                                   /*!< MII Speed Control Register, offset: 0x44 */
  uint_8 RESERVED_4[28];
  uint_32 MIBC;                                   /*!< MIB Control Register, offset: 0x64 */
  uint_8 RESERVED_5[28];
  uint_32 RCR;                                    /*!< Receive Control Register, offset: 0x84 */
  uint_8 RESERVED_6[60];
  uint_32 TCR;                                    /*!< Transmit Control Register, offset: 0xC4 */
  uint_8 RESERVED_7[28];
  uint_32 PALR;                                   /*!< Physical Address Lower Register, offset: 0xE4 */
  uint_32 PAUR;                                   /*!< Physical Address Upper Register, offset: 0xE8 */
  uint_32 OPD;                                    /*!< Opcode/Pause Duration Register, offset: 0xEC */
  uint_8 RESERVED_8[40];
  uint_32 IAUR;                                   /*!< Descriptor Individual Upper Address Register, offset: 0x118 */
  uint_32 IALR;                                   /*!< Descriptor Individual Lower Address Register, offset: 0x11C */
  uint_32 GAUR;                                   /*!< Descriptor Group Upper Address Register, offset: 0x120 */
  uint_32 GALR;                                   /*!< Descriptor Group Lower Address Register, offset: 0x124 */
  uint_8 RESERVED_9[28];
  uint_32 TFWR;                                   /*!< Transmit FIFO Watermark Register, offset: 0x144 */
  uint_8 RESERVED_10[56];
  uint_32 RDSR;                                   /*!< Receive Descriptor Ring Start Register, offset: 0x180 */
  uint_32 TDSR;                                   /*!< Transmit Buffer Descriptor Ring Start Register, offset: 0x184 */
  uint_32 MRBR;                                   /*!< Maximum Receive Buffer Size Register, offset: 0x188 */
  uint_8 RESERVED_11[4];
  uint_32 RSFL;                                   /*!< Receive FIFO Section Full Threshold, offset: 0x190 */
  uint_32 RSEM;                                   /*!< Receive FIFO Section Empty Threshold, offset: 0x194 */
  uint_32 RAEM;                                   /*!< Receive FIFO Almost Empty Threshold, offset: 0x198 */
  uint_32 RAFL;                                   /*!< Receive FIFO Almost Full Threshold, offset: 0x19C */
  uint_32 TSEM;                                   /*!< Transmit FIFO Section Empty Threshold, offset: 0x1A0 */
  uint_32 TAEM;                                   /*!< Transmit FIFO Almost Empty Threshold, offset: 0x1A4 */
  uint_32 TAFL;                                   /*!< Transmit FIFO Almost Full Threshold, offset: 0x1A8 */
  uint_32 TIPG;                                   /*!< Transmit Inter-Packet Gap, offset: 0x1AC */
  uint_32 FTRL;                                   /*!< Frame Truncation Length, offset: 0x1B0 */
  uint_8 RESERVED_12[12];
  uint_32 TACC;                                   /*!< Transmit Accelerator Function Configuration, offset: 0x1C0 */
  uint_32 RACC;                                   /*!< Receive Accelerator Function Configuration, offset: 0x1C4 */
  uint_8 RESERVED_13[56];
  uint_32 RMON_T_DROP;                            /*!< Count of frames not counted correctly, offset: 0x200 */
  uint_32 RMON_T_PACKETS;                         /*!< RMON Tx packet count, offset: 0x204 */
  uint_32 RMON_T_BC_PKT;                          /*!< RMON Tx Broadcast Packets, offset: 0x208 */
  uint_32 RMON_T_MC_PKT;                          /*!< RMON Tx Multicast Packets, offset: 0x20C */
  uint_32 RMON_T_CRC_ALIGN;                       /*!< RMON Tx Packets w CRC/Align error, offset: 0x210 */
  uint_32 RMON_T_UNDERSIZE;                       /*!< RMON Tx Packets < 64 bytes, good CRC, offset: 0x214 */
  uint_32 RMON_T_OVERSIZE;                        /*!< RMON Tx Packets > MAX_FL bytes, good CRC, offset: 0x218 */
  uint_32 RMON_T_FRAG;                            /*!< RMON Tx Packets < 64 bytes, bad CRC, offset: 0x21C */
  uint_32 RMON_T_JAB;                             /*!< RMON Tx Packets > MAX_FL bytes, bad CRC, offset: 0x220 */
  uint_32 RMON_T_COL;                             /*!< RMON Tx collision count, offset: 0x224 */
  uint_32 RMON_T_P64;                             /*!< RMON Tx 64 byte packets, offset: 0x228 */
  uint_32 RMON_T_P65TO127;                        /*!< RMON Tx 65 to 127 byte packets, offset: 0x22C */
  uint_32 RMON_T_P128TO255;                       /*!< RMON Tx 128 to 255 byte packets, offset: 0x230 */
  uint_32 RMON_T_P256TO511;                       /*!< RMON Tx 256 to 511 byte packets, offset: 0x234 */
  uint_32 RMON_T_P512TO1023;                      /*!< RMON Tx 512 to 1023 byte packets, offset: 0x238 */
  uint_32 RMON_T_P1024TO2047;                     /*!< RMON Tx 1024 to 2047 byte packets, offset: 0x23C */
  uint_32 RMON_T_P_GTE2048;                       /*!< RMON Tx packets w > 2048 bytes, offset: 0x240 */
  uint_32 RMON_T_OCTETS;                          /*!< RMON Tx Octets, offset: 0x244 */
  uint_32 IEEE_T_DROP;                            /*!< Count of frames not counted correctly, offset: 0x248 */
  uint_32 IEEE_T_FRAME_OK;                        /*!< Frames Transmitted OK, offset: 0x24C */
  uint_32 IEEE_T_1COL;                            /*!< Frames Transmitted with Single Collision, offset: 0x250 */
  uint_32 IEEE_T_MCOL;                            /*!< Frames Transmitted with Multiple Collisions, offset: 0x254 */
  uint_32 IEEE_T_DEF;                             /*!< Frames Transmitted after Deferral Delay, offset: 0x258 */
  uint_32 IEEE_T_LCOL;                            /*!< Frames Transmitted with Late Collision, offset: 0x25C */
  uint_32 IEEE_T_EXCOL;                           /*!< Frames Transmitted with Excessive Collisions, offset: 0x260 */
  uint_32 IEEE_T_MACERR;                          /*!< Frames Transmitted with Tx FIFO Underrun, offset: 0x264 */
  uint_32 IEEE_T_CSERR;                           /*!< Frames Transmitted with Carrier Sense Error, offset: 0x268 */
  uint_32 IEEE_T_SQE;                             /*!< Frames Transmitted with SQE Error, offset: 0x26C */
  uint_32 IEEE_T_FDXFC;                           /*!< Flow Control Pause frames transmitted, offset: 0x270 */
  uint_32 IEEE_T_OCTETS_OK;                       /*!< Octet count for Frames Transmitted w/o Error, offset: 0x274 */
  uint_8 RESERVED_14[12];
  uint_32 RMON_R_PACKETS;                         /*!< RMON Rx packet count, offset: 0x284 */
  uint_32 RMON_R_BC_PKT;                          /*!< RMON Rx Broadcast Packets, offset: 0x288 */
  uint_32 RMON_R_MC_PKT;                          /*!< RMON Rx Multicast Packets, offset: 0x28C */
  uint_32 RMON_R_CRC_ALIGN;                       /*!< RMON Rx Packets w CRC/Align error, offset: 0x290 */
  uint_32 RMON_R_UNDERSIZE;                       /*!< RMON Rx Packets < 64 bytes, good CRC, offset: 0x294 */
  uint_32 RMON_R_OVERSIZE;                        /*!< RMON Rx Packets > MAX_FL bytes, good CRC, offset: 0x298 */
  uint_32 RMON_R_FRAG;                            /*!< RMON Rx Packets < 64 bytes, bad CRC, offset: 0x29C */
  uint_32 RMON_R_JAB;                             /*!< RMON Rx Packets > MAX_FL bytes, bad CRC, offset: 0x2A0 */
  uint_32 RMON_R_RESVD_0;                         /*!< Reserved, offset: 0x2A4 */
  uint_32 RMON_R_P64;                             /*!< RMON Rx 64 byte packets, offset: 0x2A8 */
  uint_32 RMON_R_P65TO127;                        /*!< RMON Rx 65 to 127 byte packets, offset: 0x2AC */
  uint_32 RMON_R_P128TO255;                       /*!< RMON Rx 128 to 255 byte packets, offset: 0x2B0 */
  uint_32 RMON_R_P256TO511;                       /*!< RMON Rx 256 to 511 byte packets, offset: 0x2B4 */
  uint_32 RMON_R_P512TO1023;                      /*!< RMON Rx 512 to 1023 byte packets, offset: 0x2B8 */
  uint_32 RMON_R_P1024TO2047;                     /*!< RMON Rx 1024 to 2047 byte packets, offset: 0x2BC */
  uint_32 RMON_R_P_GTE2048;                       /*!< RMON Rx packets w > 2048 bytes, offset: 0x2C0 */
  uint_32 RMON_R_OCTETS;                          /*!< RMON Rx Octets, offset: 0x2C4 */
  uint_32 RMON_R_DROP;                            /*!< Count of frames not counted correctly, offset: 0x2C8 */
  uint_32 RMON_R_FRAME_OK;                        /*!< Frames Received OK, offset: 0x2CC */
  uint_32 IEEE_R_CRC;                             /*!< Frames Received with CRC Error, offset: 0x2D0 */
  uint_32 IEEE_R_ALIGN;                           /*!< Frames Received with Alignment Error, offset: 0x2D4 */
  uint_32 IEEE_R_MACERR;                          /*!< Receive Fifo Overflow count, offset: 0x2D8 */
  uint_32 IEEE_R_FDXFC;                           /*!< Flow Control Pause frames received, offset: 0x2DC */
  uint_32 IEEE_R_OCTETS_OK;                       /*!< Octet count for Frames Rcvd w/o Error, offset: 0x2E0 */
  uint_8 RESERVED_15[284];
  uint_32 ATCR;                                   /*!< Timer Control Register, offset: 0x400 */
  uint_32 ATVR;                                   /*!< Timer Value Register, offset: 0x404 */
  uint_32 ATOFF;                                  /*!< Timer Offset Register, offset: 0x408 */
  uint_32 ATPER;                                  /*!< Timer Period Register, offset: 0x40C */
  uint_32 ATCOR;                                  /*!< Timer Correction Register, offset: 0x410 */
  uint_32 ATINC;                                  /*!< Time-Stamping Clock Period Register, offset: 0x414 */
  uint_32 ATSTMP;                                 /*!< Timestamp of Last Transmitted Frame, offset: 0x418 */
  uint_8 RESERVED_16[488];
  uint_32 TGSR;                                   /*!< Timer Global Status Register, offset: 0x604 */
  struct {                                         /* offset: 0x608, array step: 0x8 */
    uint_32 TCSR;                                   /*!< Timer Control Status Register, array offset: 0x608, array step: 0x8 */
    uint_32 TCCR;                                   /*!< Timer Compare Capture Register, array offset: 0x60C, array step: 0x8 */
  } CHANNEL[4];
} volatile ENET_MemMap, * ENET_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- ENET - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup ENET_Register_Accessor_Macros ENET - Register accessor macros */
/*! \{ */


/* ENET - Register accessors */
#define ENET_EIR_REG(base)                       ((base)->EIR)
#define ENET_EIMR_REG(base)                      ((base)->EIMR)
#define ENET_RDAR_REG(base)                      ((base)->RDAR)
#define ENET_TDAR_REG(base)                      ((base)->TDAR)
#define ENET_ECR_REG(base)                       ((base)->ECR)
#define ENET_MMFR_REG(base)                      ((base)->MMFR)
#define ENET_MSCR_REG(base)                      ((base)->MSCR)
#define ENET_MIBC_REG(base)                      ((base)->MIBC)
#define ENET_RCR_REG(base)                       ((base)->RCR)
#define ENET_TCR_REG(base)                       ((base)->TCR)
#define ENET_PALR_REG(base)                      ((base)->PALR)
#define ENET_PAUR_REG(base)                      ((base)->PAUR)
#define ENET_OPD_REG(base)                       ((base)->OPD)
#define ENET_IAUR_REG(base)                      ((base)->IAUR)
#define ENET_IALR_REG(base)                      ((base)->IALR)
#define ENET_GAUR_REG(base)                      ((base)->GAUR)
#define ENET_GALR_REG(base)                      ((base)->GALR)
#define ENET_TFWR_REG(base)                      ((base)->TFWR)
#define ENET_RDSR_REG(base)                      ((base)->RDSR)
#define ENET_TDSR_REG(base)                      ((base)->TDSR)
#define ENET_MRBR_REG(base)                      ((base)->MRBR)
#define ENET_RSFL_REG(base)                      ((base)->RSFL)
#define ENET_RSEM_REG(base)                      ((base)->RSEM)
#define ENET_RAEM_REG(base)                      ((base)->RAEM)
#define ENET_RAFL_REG(base)                      ((base)->RAFL)
#define ENET_TSEM_REG(base)                      ((base)->TSEM)
#define ENET_TAEM_REG(base)                      ((base)->TAEM)
#define ENET_TAFL_REG(base)                      ((base)->TAFL)
#define ENET_TIPG_REG(base)                      ((base)->TIPG)
#define ENET_FTRL_REG(base)                      ((base)->FTRL)
#define ENET_TACC_REG(base)                      ((base)->TACC)
#define ENET_RACC_REG(base)                      ((base)->RACC)
#define ENET_RMON_T_DROP_REG(base)               ((base)->RMON_T_DROP)
#define ENET_RMON_T_PACKETS_REG(base)            ((base)->RMON_T_PACKETS)
#define ENET_RMON_T_BC_PKT_REG(base)             ((base)->RMON_T_BC_PKT)
#define ENET_RMON_T_MC_PKT_REG(base)             ((base)->RMON_T_MC_PKT)
#define ENET_RMON_T_CRC_ALIGN_REG(base)          ((base)->RMON_T_CRC_ALIGN)
#define ENET_RMON_T_UNDERSIZE_REG(base)          ((base)->RMON_T_UNDERSIZE)
#define ENET_RMON_T_OVERSIZE_REG(base)           ((base)->RMON_T_OVERSIZE)
#define ENET_RMON_T_FRAG_REG(base)               ((base)->RMON_T_FRAG)
#define ENET_RMON_T_JAB_REG(base)                ((base)->RMON_T_JAB)
#define ENET_RMON_T_COL_REG(base)                ((base)->RMON_T_COL)
#define ENET_RMON_T_P64_REG(base)                ((base)->RMON_T_P64)
#define ENET_RMON_T_P65TO127_REG(base)           ((base)->RMON_T_P65TO127)
#define ENET_RMON_T_P128TO255_REG(base)          ((base)->RMON_T_P128TO255)
#define ENET_RMON_T_P256TO511_REG(base)          ((base)->RMON_T_P256TO511)
#define ENET_RMON_T_P512TO1023_REG(base)         ((base)->RMON_T_P512TO1023)
#define ENET_RMON_T_P1024TO2047_REG(base)        ((base)->RMON_T_P1024TO2047)
#define ENET_RMON_T_P_GTE2048_REG(base)          ((base)->RMON_T_P_GTE2048)
#define ENET_RMON_T_OCTETS_REG(base)             ((base)->RMON_T_OCTETS)
#define ENET_IEEE_T_DROP_REG(base)               ((base)->IEEE_T_DROP)
#define ENET_IEEE_T_FRAME_OK_REG(base)           ((base)->IEEE_T_FRAME_OK)
#define ENET_IEEE_T_1COL_REG(base)               ((base)->IEEE_T_1COL)
#define ENET_IEEE_T_MCOL_REG(base)               ((base)->IEEE_T_MCOL)
#define ENET_IEEE_T_DEF_REG(base)                ((base)->IEEE_T_DEF)
#define ENET_IEEE_T_LCOL_REG(base)               ((base)->IEEE_T_LCOL)
#define ENET_IEEE_T_EXCOL_REG(base)              ((base)->IEEE_T_EXCOL)
#define ENET_IEEE_T_MACERR_REG(base)             ((base)->IEEE_T_MACERR)
#define ENET_IEEE_T_CSERR_REG(base)              ((base)->IEEE_T_CSERR)
#define ENET_IEEE_T_SQE_REG(base)                ((base)->IEEE_T_SQE)
#define ENET_IEEE_T_FDXFC_REG(base)              ((base)->IEEE_T_FDXFC)
#define ENET_IEEE_T_OCTETS_OK_REG(base)          ((base)->IEEE_T_OCTETS_OK)
#define ENET_RMON_R_PACKETS_REG(base)            ((base)->RMON_R_PACKETS)
#define ENET_RMON_R_BC_PKT_REG(base)             ((base)->RMON_R_BC_PKT)
#define ENET_RMON_R_MC_PKT_REG(base)             ((base)->RMON_R_MC_PKT)
#define ENET_RMON_R_CRC_ALIGN_REG(base)          ((base)->RMON_R_CRC_ALIGN)
#define ENET_RMON_R_UNDERSIZE_REG(base)          ((base)->RMON_R_UNDERSIZE)
#define ENET_RMON_R_OVERSIZE_REG(base)           ((base)->RMON_R_OVERSIZE)
#define ENET_RMON_R_FRAG_REG(base)               ((base)->RMON_R_FRAG)
#define ENET_RMON_R_JAB_REG(base)                ((base)->RMON_R_JAB)
#define ENET_RMON_R_RESVD_0_REG(base)            ((base)->RMON_R_RESVD_0)
#define ENET_RMON_R_P64_REG(base)                ((base)->RMON_R_P64)
#define ENET_RMON_R_P65TO127_REG(base)           ((base)->RMON_R_P65TO127)
#define ENET_RMON_R_P128TO255_REG(base)          ((base)->RMON_R_P128TO255)
#define ENET_RMON_R_P256TO511_REG(base)          ((base)->RMON_R_P256TO511)
#define ENET_RMON_R_P512TO1023_REG(base)         ((base)->RMON_R_P512TO1023)
#define ENET_RMON_R_P1024TO2047_REG(base)        ((base)->RMON_R_P1024TO2047)
#define ENET_RMON_R_P_GTE2048_REG(base)          ((base)->RMON_R_P_GTE2048)
#define ENET_RMON_R_OCTETS_REG(base)             ((base)->RMON_R_OCTETS)
#define ENET_RMON_R_DROP_REG(base)               ((base)->RMON_R_DROP)
#define ENET_RMON_R_FRAME_OK_REG(base)           ((base)->RMON_R_FRAME_OK)
#define ENET_IEEE_R_CRC_REG(base)                ((base)->IEEE_R_CRC)
#define ENET_IEEE_R_ALIGN_REG(base)              ((base)->IEEE_R_ALIGN)
#define ENET_IEEE_R_MACERR_REG(base)             ((base)->IEEE_R_MACERR)
#define ENET_IEEE_R_FDXFC_REG(base)              ((base)->IEEE_R_FDXFC)
#define ENET_IEEE_R_OCTETS_OK_REG(base)          ((base)->IEEE_R_OCTETS_OK)
#define ENET_ATCR_REG(base)                      ((base)->ATCR)
#define ENET_ATVR_REG(base)                      ((base)->ATVR)
#define ENET_ATOFF_REG(base)                     ((base)->ATOFF)
#define ENET_ATPER_REG(base)                     ((base)->ATPER)
#define ENET_ATCOR_REG(base)                     ((base)->ATCOR)
#define ENET_ATINC_REG(base)                     ((base)->ATINC)
#define ENET_ATSTMP_REG(base)                    ((base)->ATSTMP)
#define ENET_TGSR_REG(base)                      ((base)->TGSR)
#define ENET_TCSR_REG(base,index)                ((base)->CHANNEL[index].TCSR)
#define ENET_TCCR_REG(base,index)                ((base)->CHANNEL[index].TCCR)

/*! \} */ /* end of group ENET_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- ENET Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup ENET_Register_Masks ENET Register Masks */
/*! \{ */

/* EIR Bit Fields */
#define ENET_EIR_TS_TIMER_MASK                   0x8000u
#define ENET_EIR_TS_TIMER_SHIFT                  15
#define ENET_EIR_TS_AVAIL_MASK                   0x10000u
#define ENET_EIR_TS_AVAIL_SHIFT                  16
#define ENET_EIR_WAKEUP_MASK                     0x20000u
#define ENET_EIR_WAKEUP_SHIFT                    17
#define ENET_EIR_PLR_MASK                        0x40000u
#define ENET_EIR_PLR_SHIFT                       18
#define ENET_EIR_UN_MASK                         0x80000u
#define ENET_EIR_UN_SHIFT                        19
#define ENET_EIR_RL_MASK                         0x100000u
#define ENET_EIR_RL_SHIFT                        20
#define ENET_EIR_LC_MASK                         0x200000u
#define ENET_EIR_LC_SHIFT                        21
#define ENET_EIR_EBERR_MASK                      0x400000u
#define ENET_EIR_EBERR_SHIFT                     22
#define ENET_EIR_MII_MASK                        0x800000u
#define ENET_EIR_MII_SHIFT                       23
#define ENET_EIR_RXB_MASK                        0x1000000u
#define ENET_EIR_RXB_SHIFT                       24
#define ENET_EIR_RXF_MASK                        0x2000000u
#define ENET_EIR_RXF_SHIFT                       25
#define ENET_EIR_TXB_MASK                        0x4000000u
#define ENET_EIR_TXB_SHIFT                       26
#define ENET_EIR_TXF_MASK                        0x8000000u
#define ENET_EIR_TXF_SHIFT                       27
#define ENET_EIR_GRA_MASK                        0x10000000u
#define ENET_EIR_GRA_SHIFT                       28
#define ENET_EIR_BABT_MASK                       0x20000000u
#define ENET_EIR_BABT_SHIFT                      29
#define ENET_EIR_BABR_MASK                       0x40000000u
#define ENET_EIR_BABR_SHIFT                      30
/* EIMR Bit Fields */
#define ENET_EIMR_TS_TIMER_MASK                  0x8000u
#define ENET_EIMR_TS_TIMER_SHIFT                 15
#define ENET_EIMR_TS_AVAIL_MASK                  0x10000u
#define ENET_EIMR_TS_AVAIL_SHIFT                 16
#define ENET_EIMR_WAKEUP_MASK                    0x20000u
#define ENET_EIMR_WAKEUP_SHIFT                   17
#define ENET_EIMR_PLR_MASK                       0x40000u
#define ENET_EIMR_PLR_SHIFT                      18
#define ENET_EIMR_UN_MASK                        0x80000u
#define ENET_EIMR_UN_SHIFT                       19
#define ENET_EIMR_RL_MASK                        0x100000u
#define ENET_EIMR_RL_SHIFT                       20
#define ENET_EIMR_LC_MASK                        0x200000u
#define ENET_EIMR_LC_SHIFT                       21
#define ENET_EIMR_EBERR_MASK                     0x400000u
#define ENET_EIMR_EBERR_SHIFT                    22
#define ENET_EIMR_MII_MASK                       0x800000u
#define ENET_EIMR_MII_SHIFT                      23
#define ENET_EIMR_RXB_MASK                       0x1000000u
#define ENET_EIMR_RXB_SHIFT                      24
#define ENET_EIMR_RXF_MASK                       0x2000000u
#define ENET_EIMR_RXF_SHIFT                      25
#define ENET_EIMR_TXB_MASK                       0x4000000u
#define ENET_EIMR_TXB_SHIFT                      26
#define ENET_EIMR_TXF_MASK                       0x8000000u
#define ENET_EIMR_TXF_SHIFT                      27
#define ENET_EIMR_GRA_MASK                       0x10000000u
#define ENET_EIMR_GRA_SHIFT                      28
#define ENET_EIMR_BABT_MASK                      0x20000000u
#define ENET_EIMR_BABT_SHIFT                     29
#define ENET_EIMR_BABR_MASK                      0x40000000u
#define ENET_EIMR_BABR_SHIFT                     30
/* RDAR Bit Fields */
#define ENET_RDAR_RDAR_MASK                      0x1000000u
#define ENET_RDAR_RDAR_SHIFT                     24
/* TDAR Bit Fields */
#define ENET_TDAR_TDAR_MASK                      0x1000000u
#define ENET_TDAR_TDAR_SHIFT                     24
/* ECR Bit Fields */
#define ENET_ECR_RESET_MASK                      0x1u
#define ENET_ECR_RESET_SHIFT                     0
#define ENET_ECR_ETHEREN_MASK                    0x2u
#define ENET_ECR_ETHEREN_SHIFT                   1
#define ENET_ECR_MAGICEN_MASK                    0x4u
#define ENET_ECR_MAGICEN_SHIFT                   2
#define ENET_ECR_SLEEP_MASK                      0x8u
#define ENET_ECR_SLEEP_SHIFT                     3
#define ENET_ECR_EN1588_MASK                     0x10u
#define ENET_ECR_EN1588_SHIFT                    4
#define ENET_ECR_DBGEN_MASK                      0x40u
#define ENET_ECR_DBGEN_SHIFT                     6
#define ENET_ECR_STOPEN_MASK                     0x80u
#define ENET_ECR_STOPEN_SHIFT                    7
/* MMFR Bit Fields */
#define ENET_MMFR_DATA_MASK                      0xFFFFu
#define ENET_MMFR_DATA_SHIFT                     0
#define ENET_MMFR_DATA(x)                        (((uint_32)(((uint_32)(x))<<ENET_MMFR_DATA_SHIFT))&ENET_MMFR_DATA_MASK)
#define ENET_MMFR_TA_MASK                        0x30000u
#define ENET_MMFR_TA_SHIFT                       16
#define ENET_MMFR_TA(x)                          (((uint_32)(((uint_32)(x))<<ENET_MMFR_TA_SHIFT))&ENET_MMFR_TA_MASK)
#define ENET_MMFR_RA_MASK                        0x7C0000u
#define ENET_MMFR_RA_SHIFT                       18
#define ENET_MMFR_RA(x)                          (((uint_32)(((uint_32)(x))<<ENET_MMFR_RA_SHIFT))&ENET_MMFR_RA_MASK)
#define ENET_MMFR_PA_MASK                        0xF800000u
#define ENET_MMFR_PA_SHIFT                       23
#define ENET_MMFR_PA(x)                          (((uint_32)(((uint_32)(x))<<ENET_MMFR_PA_SHIFT))&ENET_MMFR_PA_MASK)
#define ENET_MMFR_OP_MASK                        0x30000000u
#define ENET_MMFR_OP_SHIFT                       28
#define ENET_MMFR_OP(x)                          (((uint_32)(((uint_32)(x))<<ENET_MMFR_OP_SHIFT))&ENET_MMFR_OP_MASK)
#define ENET_MMFR_ST_MASK                        0xC0000000u
#define ENET_MMFR_ST_SHIFT                       30
#define ENET_MMFR_ST(x)                          (((uint_32)(((uint_32)(x))<<ENET_MMFR_ST_SHIFT))&ENET_MMFR_ST_MASK)
/* MSCR Bit Fields */
#define ENET_MSCR_MII_SPEED_MASK                 0x7Eu
#define ENET_MSCR_MII_SPEED_SHIFT                1
#define ENET_MSCR_MII_SPEED(x)                   (((uint_32)(((uint_32)(x))<<ENET_MSCR_MII_SPEED_SHIFT))&ENET_MSCR_MII_SPEED_MASK)
#define ENET_MSCR_DIS_PRE_MASK                   0x80u
#define ENET_MSCR_DIS_PRE_SHIFT                  7
#define ENET_MSCR_HOLDTIME_MASK                  0x700u
#define ENET_MSCR_HOLDTIME_SHIFT                 8
#define ENET_MSCR_HOLDTIME(x)                    (((uint_32)(((uint_32)(x))<<ENET_MSCR_HOLDTIME_SHIFT))&ENET_MSCR_HOLDTIME_MASK)
/* MIBC Bit Fields */
#define ENET_MIBC_MIB_CLEAR_MASK                 0x20000000u
#define ENET_MIBC_MIB_CLEAR_SHIFT                29
#define ENET_MIBC_MIB_IDLE_MASK                  0x40000000u
#define ENET_MIBC_MIB_IDLE_SHIFT                 30
#define ENET_MIBC_MIB_DIS_MASK                   0x80000000u
#define ENET_MIBC_MIB_DIS_SHIFT                  31
/* RCR Bit Fields */
#define ENET_RCR_LOOP_MASK                       0x1u
#define ENET_RCR_LOOP_SHIFT                      0
#define ENET_RCR_DRT_MASK                        0x2u
#define ENET_RCR_DRT_SHIFT                       1
#define ENET_RCR_MII_MODE_MASK                   0x4u
#define ENET_RCR_MII_MODE_SHIFT                  2
#define ENET_RCR_PROM_MASK                       0x8u
#define ENET_RCR_PROM_SHIFT                      3
#define ENET_RCR_BC_REJ_MASK                     0x10u
#define ENET_RCR_BC_REJ_SHIFT                    4
#define ENET_RCR_FCE_MASK                        0x20u
#define ENET_RCR_FCE_SHIFT                       5
#define ENET_RCR_RMII_MODE_MASK                  0x100u
#define ENET_RCR_RMII_MODE_SHIFT                 8
#define ENET_RCR_RMII_10T_MASK                   0x200u
#define ENET_RCR_RMII_10T_SHIFT                  9
#define ENET_RCR_PADEN_MASK                      0x1000u
#define ENET_RCR_PADEN_SHIFT                     12
#define ENET_RCR_PAUFWD_MASK                     0x2000u
#define ENET_RCR_PAUFWD_SHIFT                    13
#define ENET_RCR_CRCFWD_MASK                     0x4000u
#define ENET_RCR_CRCFWD_SHIFT                    14
#define ENET_RCR_CFEN_MASK                       0x8000u
#define ENET_RCR_CFEN_SHIFT                      15
#define ENET_RCR_MAX_FL_MASK                     0x3FFF0000u
#define ENET_RCR_MAX_FL_SHIFT                    16
#define ENET_RCR_MAX_FL(x)                       (((uint_32)(((uint_32)(x))<<ENET_RCR_MAX_FL_SHIFT))&ENET_RCR_MAX_FL_MASK)
#define ENET_RCR_NLC_MASK                        0x40000000u
#define ENET_RCR_NLC_SHIFT                       30
#define ENET_RCR_GRS_MASK                        0x80000000u
#define ENET_RCR_GRS_SHIFT                       31
/* TCR Bit Fields */
#define ENET_TCR_GTS_MASK                        0x1u
#define ENET_TCR_GTS_SHIFT                       0
#define ENET_TCR_FDEN_MASK                       0x4u
#define ENET_TCR_FDEN_SHIFT                      2
#define ENET_TCR_TFC_PAUSE_MASK                  0x8u
#define ENET_TCR_TFC_PAUSE_SHIFT                 3
#define ENET_TCR_RFC_PAUSE_MASK                  0x10u
#define ENET_TCR_RFC_PAUSE_SHIFT                 4
#define ENET_TCR_ADDSEL_MASK                     0xE0u
#define ENET_TCR_ADDSEL_SHIFT                    5
#define ENET_TCR_ADDSEL(x)                       (((uint_32)(((uint_32)(x))<<ENET_TCR_ADDSEL_SHIFT))&ENET_TCR_ADDSEL_MASK)
#define ENET_TCR_ADDINS_MASK                     0x100u
#define ENET_TCR_ADDINS_SHIFT                    8
#define ENET_TCR_CRCFWD_MASK                     0x200u
#define ENET_TCR_CRCFWD_SHIFT                    9
/* PALR Bit Fields */
#define ENET_PALR_PADDR1_MASK                    0xFFFFFFFFu
#define ENET_PALR_PADDR1_SHIFT                   0
#define ENET_PALR_PADDR1(x)                      (((uint_32)(((uint_32)(x))<<ENET_PALR_PADDR1_SHIFT))&ENET_PALR_PADDR1_MASK)
/* PAUR Bit Fields */
#define ENET_PAUR_TYPE_MASK                      0xFFFFu
#define ENET_PAUR_TYPE_SHIFT                     0
#define ENET_PAUR_TYPE(x)                        (((uint_32)(((uint_32)(x))<<ENET_PAUR_TYPE_SHIFT))&ENET_PAUR_TYPE_MASK)
#define ENET_PAUR_PADDR2_MASK                    0xFFFF0000u
#define ENET_PAUR_PADDR2_SHIFT                   16
#define ENET_PAUR_PADDR2(x)                      (((uint_32)(((uint_32)(x))<<ENET_PAUR_PADDR2_SHIFT))&ENET_PAUR_PADDR2_MASK)
/* OPD Bit Fields */
#define ENET_OPD_PAUSE_DUR_MASK                  0xFFFFu
#define ENET_OPD_PAUSE_DUR_SHIFT                 0
#define ENET_OPD_PAUSE_DUR(x)                    (((uint_32)(((uint_32)(x))<<ENET_OPD_PAUSE_DUR_SHIFT))&ENET_OPD_PAUSE_DUR_MASK)
#define ENET_OPD_OPCODE_MASK                     0xFFFF0000u
#define ENET_OPD_OPCODE_SHIFT                    16
#define ENET_OPD_OPCODE(x)                       (((uint_32)(((uint_32)(x))<<ENET_OPD_OPCODE_SHIFT))&ENET_OPD_OPCODE_MASK)
/* IAUR Bit Fields */
#define ENET_IAUR_IADDR1_MASK                    0xFFFFFFFFu
#define ENET_IAUR_IADDR1_SHIFT                   0
#define ENET_IAUR_IADDR1(x)                      (((uint_32)(((uint_32)(x))<<ENET_IAUR_IADDR1_SHIFT))&ENET_IAUR_IADDR1_MASK)
/* IALR Bit Fields */
#define ENET_IALR_IADDR2_MASK                    0xFFFFFFFFu
#define ENET_IALR_IADDR2_SHIFT                   0
#define ENET_IALR_IADDR2(x)                      (((uint_32)(((uint_32)(x))<<ENET_IALR_IADDR2_SHIFT))&ENET_IALR_IADDR2_MASK)
/* GAUR Bit Fields */
#define ENET_GAUR_GADDR1_MASK                    0xFFFFFFFFu
#define ENET_GAUR_GADDR1_SHIFT                   0
#define ENET_GAUR_GADDR1(x)                      (((uint_32)(((uint_32)(x))<<ENET_GAUR_GADDR1_SHIFT))&ENET_GAUR_GADDR1_MASK)
/* GALR Bit Fields */
#define ENET_GALR_GADDR2_MASK                    0xFFFFFFFFu
#define ENET_GALR_GADDR2_SHIFT                   0
#define ENET_GALR_GADDR2(x)                      (((uint_32)(((uint_32)(x))<<ENET_GALR_GADDR2_SHIFT))&ENET_GALR_GADDR2_MASK)
/* TFWR Bit Fields */
#define ENET_TFWR_TFWR_MASK                      0x3Fu
#define ENET_TFWR_TFWR_SHIFT                     0
#define ENET_TFWR_TFWR(x)                        (((uint_32)(((uint_32)(x))<<ENET_TFWR_TFWR_SHIFT))&ENET_TFWR_TFWR_MASK)
#define ENET_TFWR_STRFWD_MASK                    0x100u
#define ENET_TFWR_STRFWD_SHIFT                   8
/* RDSR Bit Fields */
#define ENET_RDSR_R_DES_START_MASK               0xFFFFFFF8u
#define ENET_RDSR_R_DES_START_SHIFT              3
#define ENET_RDSR_R_DES_START(x)                 (((uint_32)(((uint_32)(x))<<ENET_RDSR_R_DES_START_SHIFT))&ENET_RDSR_R_DES_START_MASK)
/* TDSR Bit Fields */
#define ENET_TDSR_X_DES_START_MASK               0xFFFFFFF8u
#define ENET_TDSR_X_DES_START_SHIFT              3
#define ENET_TDSR_X_DES_START(x)                 (((uint_32)(((uint_32)(x))<<ENET_TDSR_X_DES_START_SHIFT))&ENET_TDSR_X_DES_START_MASK)
/* MRBR Bit Fields */
#define ENET_MRBR_R_BUF_SIZE_MASK                0x3FF0u
#define ENET_MRBR_R_BUF_SIZE_SHIFT               4
#define ENET_MRBR_R_BUF_SIZE(x)                  (((uint_32)(((uint_32)(x))<<ENET_MRBR_R_BUF_SIZE_SHIFT))&ENET_MRBR_R_BUF_SIZE_MASK)
/* RSFL Bit Fields */
#define ENET_RSFL_RX_SECTION_FULL_MASK           0xFFu
#define ENET_RSFL_RX_SECTION_FULL_SHIFT          0
#define ENET_RSFL_RX_SECTION_FULL(x)             (((uint_32)(((uint_32)(x))<<ENET_RSFL_RX_SECTION_FULL_SHIFT))&ENET_RSFL_RX_SECTION_FULL_MASK)
/* RSEM Bit Fields */
#define ENET_RSEM_RX_SECTION_EMPTY_MASK          0xFFu
#define ENET_RSEM_RX_SECTION_EMPTY_SHIFT         0
#define ENET_RSEM_RX_SECTION_EMPTY(x)            (((uint_32)(((uint_32)(x))<<ENET_RSEM_RX_SECTION_EMPTY_SHIFT))&ENET_RSEM_RX_SECTION_EMPTY_MASK)
/* RAEM Bit Fields */
#define ENET_RAEM_RX_ALMOST_EMPTY_MASK           0xFFu
#define ENET_RAEM_RX_ALMOST_EMPTY_SHIFT          0
#define ENET_RAEM_RX_ALMOST_EMPTY(x)             (((uint_32)(((uint_32)(x))<<ENET_RAEM_RX_ALMOST_EMPTY_SHIFT))&ENET_RAEM_RX_ALMOST_EMPTY_MASK)
/* RAFL Bit Fields */
#define ENET_RAFL_RX_ALMOST_FULL_MASK            0xFFu
#define ENET_RAFL_RX_ALMOST_FULL_SHIFT           0
#define ENET_RAFL_RX_ALMOST_FULL(x)              (((uint_32)(((uint_32)(x))<<ENET_RAFL_RX_ALMOST_FULL_SHIFT))&ENET_RAFL_RX_ALMOST_FULL_MASK)
/* TSEM Bit Fields */
#define ENET_TSEM_TX_SECTION_EMPTY_MASK          0xFFu
#define ENET_TSEM_TX_SECTION_EMPTY_SHIFT         0
#define ENET_TSEM_TX_SECTION_EMPTY(x)            (((uint_32)(((uint_32)(x))<<ENET_TSEM_TX_SECTION_EMPTY_SHIFT))&ENET_TSEM_TX_SECTION_EMPTY_MASK)
/* TAEM Bit Fields */
#define ENET_TAEM_TX_ALMOST_EMPTY_MASK           0xFFu
#define ENET_TAEM_TX_ALMOST_EMPTY_SHIFT          0
#define ENET_TAEM_TX_ALMOST_EMPTY(x)             (((uint_32)(((uint_32)(x))<<ENET_TAEM_TX_ALMOST_EMPTY_SHIFT))&ENET_TAEM_TX_ALMOST_EMPTY_MASK)
/* TAFL Bit Fields */
#define ENET_TAFL_TX_ALMOST_FULL_MASK            0xFFu
#define ENET_TAFL_TX_ALMOST_FULL_SHIFT           0
#define ENET_TAFL_TX_ALMOST_FULL(x)              (((uint_32)(((uint_32)(x))<<ENET_TAFL_TX_ALMOST_FULL_SHIFT))&ENET_TAFL_TX_ALMOST_FULL_MASK)
/* TIPG Bit Fields */
#define ENET_TIPG_IPG_MASK                       0x1Fu
#define ENET_TIPG_IPG_SHIFT                      0
#define ENET_TIPG_IPG(x)                         (((uint_32)(((uint_32)(x))<<ENET_TIPG_IPG_SHIFT))&ENET_TIPG_IPG_MASK)
/* FTRL Bit Fields */
#define ENET_FTRL_TRUNC_FL_MASK                  0x3FFFu
#define ENET_FTRL_TRUNC_FL_SHIFT                 0
#define ENET_FTRL_TRUNC_FL(x)                    (((uint_32)(((uint_32)(x))<<ENET_FTRL_TRUNC_FL_SHIFT))&ENET_FTRL_TRUNC_FL_MASK)
/* TACC Bit Fields */
#define ENET_TACC_SHIFT16_MASK                   0x1u
#define ENET_TACC_SHIFT16_SHIFT                  0
#define ENET_TACC_IPCHK_MASK                     0x8u
#define ENET_TACC_IPCHK_SHIFT                    3
#define ENET_TACC_PROCHK_MASK                    0x10u
#define ENET_TACC_PROCHK_SHIFT                   4
/* RACC Bit Fields */
#define ENET_RACC_PADREM_MASK                    0x1u
#define ENET_RACC_PADREM_SHIFT                   0
#define ENET_RACC_IPDIS_MASK                     0x2u
#define ENET_RACC_IPDIS_SHIFT                    1
#define ENET_RACC_PRODIS_MASK                    0x4u
#define ENET_RACC_PRODIS_SHIFT                   2
#define ENET_RACC_LINEDIS_MASK                   0x40u
#define ENET_RACC_LINEDIS_SHIFT                  6
#define ENET_RACC_SHIFT16_MASK                   0x80u
#define ENET_RACC_SHIFT16_SHIFT                  7
/* RMON_T_DROP Bit Fields */
#define ENET_RMON_T_DROP_Value_MASK              0xFFFFFFFFu
#define ENET_RMON_T_DROP_Value_SHIFT             0
#define ENET_RMON_T_DROP_Value(x)                (((uint_32)(((uint_32)(x))<<ENET_RMON_T_DROP_Value_SHIFT))&ENET_RMON_T_DROP_Value_MASK)
/* RMON_T_PACKETS Bit Fields */
#define ENET_RMON_T_PACKETS_Value_MASK           0xFFFFFFFFu
#define ENET_RMON_T_PACKETS_Value_SHIFT          0
#define ENET_RMON_T_PACKETS_Value(x)             (((uint_32)(((uint_32)(x))<<ENET_RMON_T_PACKETS_Value_SHIFT))&ENET_RMON_T_PACKETS_Value_MASK)
/* RMON_T_BC_PKT Bit Fields */
#define ENET_RMON_T_BC_PKT_Value_MASK            0xFFFFFFFFu
#define ENET_RMON_T_BC_PKT_Value_SHIFT           0
#define ENET_RMON_T_BC_PKT_Value(x)              (((uint_32)(((uint_32)(x))<<ENET_RMON_T_BC_PKT_Value_SHIFT))&ENET_RMON_T_BC_PKT_Value_MASK)
/* RMON_T_MC_PKT Bit Fields */
#define ENET_RMON_T_MC_PKT_Value_MASK            0xFFFFFFFFu
#define ENET_RMON_T_MC_PKT_Value_SHIFT           0
#define ENET_RMON_T_MC_PKT_Value(x)              (((uint_32)(((uint_32)(x))<<ENET_RMON_T_MC_PKT_Value_SHIFT))&ENET_RMON_T_MC_PKT_Value_MASK)
/* RMON_T_CRC_ALIGN Bit Fields */
#define ENET_RMON_T_CRC_ALIGN_Value_MASK         0xFFFFFFFFu
#define ENET_RMON_T_CRC_ALIGN_Value_SHIFT        0
#define ENET_RMON_T_CRC_ALIGN_Value(x)           (((uint_32)(((uint_32)(x))<<ENET_RMON_T_CRC_ALIGN_Value_SHIFT))&ENET_RMON_T_CRC_ALIGN_Value_MASK)
/* RMON_T_UNDERSIZE Bit Fields */
#define ENET_RMON_T_UNDERSIZE_Value_MASK         0xFFFFFFFFu
#define ENET_RMON_T_UNDERSIZE_Value_SHIFT        0
#define ENET_RMON_T_UNDERSIZE_Value(x)           (((uint_32)(((uint_32)(x))<<ENET_RMON_T_UNDERSIZE_Value_SHIFT))&ENET_RMON_T_UNDERSIZE_Value_MASK)
/* RMON_T_OVERSIZE Bit Fields */
#define ENET_RMON_T_OVERSIZE_Value_MASK          0xFFFFFFFFu
#define ENET_RMON_T_OVERSIZE_Value_SHIFT         0
#define ENET_RMON_T_OVERSIZE_Value(x)            (((uint_32)(((uint_32)(x))<<ENET_RMON_T_OVERSIZE_Value_SHIFT))&ENET_RMON_T_OVERSIZE_Value_MASK)
/* RMON_T_FRAG Bit Fields */
#define ENET_RMON_T_FRAG_Value_MASK              0xFFFFFFFFu
#define ENET_RMON_T_FRAG_Value_SHIFT             0
#define ENET_RMON_T_FRAG_Value(x)                (((uint_32)(((uint_32)(x))<<ENET_RMON_T_FRAG_Value_SHIFT))&ENET_RMON_T_FRAG_Value_MASK)
/* RMON_T_JAB Bit Fields */
#define ENET_RMON_T_JAB_Value_MASK               0xFFFFFFFFu
#define ENET_RMON_T_JAB_Value_SHIFT              0
#define ENET_RMON_T_JAB_Value(x)                 (((uint_32)(((uint_32)(x))<<ENET_RMON_T_JAB_Value_SHIFT))&ENET_RMON_T_JAB_Value_MASK)
/* RMON_T_COL Bit Fields */
#define ENET_RMON_T_COL_Value_MASK               0xFFFFFFFFu
#define ENET_RMON_T_COL_Value_SHIFT              0
#define ENET_RMON_T_COL_Value(x)                 (((uint_32)(((uint_32)(x))<<ENET_RMON_T_COL_Value_SHIFT))&ENET_RMON_T_COL_Value_MASK)
/* RMON_T_P64 Bit Fields */
#define ENET_RMON_T_P64_Value_MASK               0xFFFFFFFFu
#define ENET_RMON_T_P64_Value_SHIFT              0
#define ENET_RMON_T_P64_Value(x)                 (((uint_32)(((uint_32)(x))<<ENET_RMON_T_P64_Value_SHIFT))&ENET_RMON_T_P64_Value_MASK)
/* RMON_T_P65TO127 Bit Fields */
#define ENET_RMON_T_P65TO127_Value_MASK          0xFFFFFFFFu
#define ENET_RMON_T_P65TO127_Value_SHIFT         0
#define ENET_RMON_T_P65TO127_Value(x)            (((uint_32)(((uint_32)(x))<<ENET_RMON_T_P65TO127_Value_SHIFT))&ENET_RMON_T_P65TO127_Value_MASK)
/* RMON_T_P128TO255 Bit Fields */
#define ENET_RMON_T_P128TO255_Value_MASK         0xFFFFFFFFu
#define ENET_RMON_T_P128TO255_Value_SHIFT        0
#define ENET_RMON_T_P128TO255_Value(x)           (((uint_32)(((uint_32)(x))<<ENET_RMON_T_P128TO255_Value_SHIFT))&ENET_RMON_T_P128TO255_Value_MASK)
/* RMON_T_P256TO511 Bit Fields */
#define ENET_RMON_T_P256TO511_Value_MASK         0xFFFFFFFFu
#define ENET_RMON_T_P256TO511_Value_SHIFT        0
#define ENET_RMON_T_P256TO511_Value(x)           (((uint_32)(((uint_32)(x))<<ENET_RMON_T_P256TO511_Value_SHIFT))&ENET_RMON_T_P256TO511_Value_MASK)
/* RMON_T_P512TO1023 Bit Fields */
#define ENET_RMON_T_P512TO1023_Value_MASK        0xFFFFFFFFu
#define ENET_RMON_T_P512TO1023_Value_SHIFT       0
#define ENET_RMON_T_P512TO1023_Value(x)          (((uint_32)(((uint_32)(x))<<ENET_RMON_T_P512TO1023_Value_SHIFT))&ENET_RMON_T_P512TO1023_Value_MASK)
/* RMON_T_P1024TO2047 Bit Fields */
#define ENET_RMON_T_P1024TO2047_Value_MASK       0xFFFFFFFFu
#define ENET_RMON_T_P1024TO2047_Value_SHIFT      0
#define ENET_RMON_T_P1024TO2047_Value(x)         (((uint_32)(((uint_32)(x))<<ENET_RMON_T_P1024TO2047_Value_SHIFT))&ENET_RMON_T_P1024TO2047_Value_MASK)
/* RMON_T_P_GTE2048 Bit Fields */
#define ENET_RMON_T_P_GTE2048_Value_MASK         0xFFFFFFFFu
#define ENET_RMON_T_P_GTE2048_Value_SHIFT        0
#define ENET_RMON_T_P_GTE2048_Value(x)           (((uint_32)(((uint_32)(x))<<ENET_RMON_T_P_GTE2048_Value_SHIFT))&ENET_RMON_T_P_GTE2048_Value_MASK)
/* RMON_T_OCTETS Bit Fields */
#define ENET_RMON_T_OCTETS_Value_MASK            0xFFFFFFFFu
#define ENET_RMON_T_OCTETS_Value_SHIFT           0
#define ENET_RMON_T_OCTETS_Value(x)              (((uint_32)(((uint_32)(x))<<ENET_RMON_T_OCTETS_Value_SHIFT))&ENET_RMON_T_OCTETS_Value_MASK)
/* IEEE_T_DROP Bit Fields */
#define ENET_IEEE_T_DROP_Value_MASK              0xFFFFFFFFu
#define ENET_IEEE_T_DROP_Value_SHIFT             0
#define ENET_IEEE_T_DROP_Value(x)                (((uint_32)(((uint_32)(x))<<ENET_IEEE_T_DROP_Value_SHIFT))&ENET_IEEE_T_DROP_Value_MASK)
/* IEEE_T_FRAME_OK Bit Fields */
#define ENET_IEEE_T_FRAME_OK_Value_MASK          0xFFFFFFFFu
#define ENET_IEEE_T_FRAME_OK_Value_SHIFT         0
#define ENET_IEEE_T_FRAME_OK_Value(x)            (((uint_32)(((uint_32)(x))<<ENET_IEEE_T_FRAME_OK_Value_SHIFT))&ENET_IEEE_T_FRAME_OK_Value_MASK)
/* IEEE_T_1COL Bit Fields */
#define ENET_IEEE_T_1COL_Value_MASK              0xFFFFFFFFu
#define ENET_IEEE_T_1COL_Value_SHIFT             0
#define ENET_IEEE_T_1COL_Value(x)                (((uint_32)(((uint_32)(x))<<ENET_IEEE_T_1COL_Value_SHIFT))&ENET_IEEE_T_1COL_Value_MASK)
/* IEEE_T_MCOL Bit Fields */
#define ENET_IEEE_T_MCOL_Value_MASK              0xFFFFFFFFu
#define ENET_IEEE_T_MCOL_Value_SHIFT             0
#define ENET_IEEE_T_MCOL_Value(x)                (((uint_32)(((uint_32)(x))<<ENET_IEEE_T_MCOL_Value_SHIFT))&ENET_IEEE_T_MCOL_Value_MASK)
/* IEEE_T_DEF Bit Fields */
#define ENET_IEEE_T_DEF_Value_MASK               0xFFFFFFFFu
#define ENET_IEEE_T_DEF_Value_SHIFT              0
#define ENET_IEEE_T_DEF_Value(x)                 (((uint_32)(((uint_32)(x))<<ENET_IEEE_T_DEF_Value_SHIFT))&ENET_IEEE_T_DEF_Value_MASK)
/* IEEE_T_LCOL Bit Fields */
#define ENET_IEEE_T_LCOL_Value_MASK              0xFFFFFFFFu
#define ENET_IEEE_T_LCOL_Value_SHIFT             0
#define ENET_IEEE_T_LCOL_Value(x)                (((uint_32)(((uint_32)(x))<<ENET_IEEE_T_LCOL_Value_SHIFT))&ENET_IEEE_T_LCOL_Value_MASK)
/* IEEE_T_EXCOL Bit Fields */
#define ENET_IEEE_T_EXCOL_Value_MASK             0xFFFFFFFFu
#define ENET_IEEE_T_EXCOL_Value_SHIFT            0
#define ENET_IEEE_T_EXCOL_Value(x)               (((uint_32)(((uint_32)(x))<<ENET_IEEE_T_EXCOL_Value_SHIFT))&ENET_IEEE_T_EXCOL_Value_MASK)
/* IEEE_T_MACERR Bit Fields */
#define ENET_IEEE_T_MACERR_Value_MASK            0xFFFFFFFFu
#define ENET_IEEE_T_MACERR_Value_SHIFT           0
#define ENET_IEEE_T_MACERR_Value(x)              (((uint_32)(((uint_32)(x))<<ENET_IEEE_T_MACERR_Value_SHIFT))&ENET_IEEE_T_MACERR_Value_MASK)
/* IEEE_T_CSERR Bit Fields */
#define ENET_IEEE_T_CSERR_Value_MASK             0xFFFFFFFFu
#define ENET_IEEE_T_CSERR_Value_SHIFT            0
#define ENET_IEEE_T_CSERR_Value(x)               (((uint_32)(((uint_32)(x))<<ENET_IEEE_T_CSERR_Value_SHIFT))&ENET_IEEE_T_CSERR_Value_MASK)
/* IEEE_T_SQE Bit Fields */
#define ENET_IEEE_T_SQE_Value_MASK               0xFFFFFFFFu
#define ENET_IEEE_T_SQE_Value_SHIFT              0
#define ENET_IEEE_T_SQE_Value(x)                 (((uint_32)(((uint_32)(x))<<ENET_IEEE_T_SQE_Value_SHIFT))&ENET_IEEE_T_SQE_Value_MASK)
/* IEEE_T_FDXFC Bit Fields */
#define ENET_IEEE_T_FDXFC_Value_MASK             0xFFFFFFFFu
#define ENET_IEEE_T_FDXFC_Value_SHIFT            0
#define ENET_IEEE_T_FDXFC_Value(x)               (((uint_32)(((uint_32)(x))<<ENET_IEEE_T_FDXFC_Value_SHIFT))&ENET_IEEE_T_FDXFC_Value_MASK)
/* IEEE_T_OCTETS_OK Bit Fields */
#define ENET_IEEE_T_OCTETS_OK_Value_MASK         0xFFFFFFFFu
#define ENET_IEEE_T_OCTETS_OK_Value_SHIFT        0
#define ENET_IEEE_T_OCTETS_OK_Value(x)           (((uint_32)(((uint_32)(x))<<ENET_IEEE_T_OCTETS_OK_Value_SHIFT))&ENET_IEEE_T_OCTETS_OK_Value_MASK)
/* RMON_R_PACKETS Bit Fields */
#define ENET_RMON_R_PACKETS_Value_MASK           0xFFFFFFFFu
#define ENET_RMON_R_PACKETS_Value_SHIFT          0
#define ENET_RMON_R_PACKETS_Value(x)             (((uint_32)(((uint_32)(x))<<ENET_RMON_R_PACKETS_Value_SHIFT))&ENET_RMON_R_PACKETS_Value_MASK)
/* RMON_R_BC_PKT Bit Fields */
#define ENET_RMON_R_BC_PKT_Value_MASK            0xFFFFFFFFu
#define ENET_RMON_R_BC_PKT_Value_SHIFT           0
#define ENET_RMON_R_BC_PKT_Value(x)              (((uint_32)(((uint_32)(x))<<ENET_RMON_R_BC_PKT_Value_SHIFT))&ENET_RMON_R_BC_PKT_Value_MASK)
/* RMON_R_MC_PKT Bit Fields */
#define ENET_RMON_R_MC_PKT_Value_MASK            0xFFFFFFFFu
#define ENET_RMON_R_MC_PKT_Value_SHIFT           0
#define ENET_RMON_R_MC_PKT_Value(x)              (((uint_32)(((uint_32)(x))<<ENET_RMON_R_MC_PKT_Value_SHIFT))&ENET_RMON_R_MC_PKT_Value_MASK)
/* RMON_R_CRC_ALIGN Bit Fields */
#define ENET_RMON_R_CRC_ALIGN_Value_MASK         0xFFFFFFFFu
#define ENET_RMON_R_CRC_ALIGN_Value_SHIFT        0
#define ENET_RMON_R_CRC_ALIGN_Value(x)           (((uint_32)(((uint_32)(x))<<ENET_RMON_R_CRC_ALIGN_Value_SHIFT))&ENET_RMON_R_CRC_ALIGN_Value_MASK)
/* RMON_R_UNDERSIZE Bit Fields */
#define ENET_RMON_R_UNDERSIZE_Value_MASK         0xFFFFFFFFu
#define ENET_RMON_R_UNDERSIZE_Value_SHIFT        0
#define ENET_RMON_R_UNDERSIZE_Value(x)           (((uint_32)(((uint_32)(x))<<ENET_RMON_R_UNDERSIZE_Value_SHIFT))&ENET_RMON_R_UNDERSIZE_Value_MASK)
/* RMON_R_OVERSIZE Bit Fields */
#define ENET_RMON_R_OVERSIZE_Value_MASK          0xFFFFFFFFu
#define ENET_RMON_R_OVERSIZE_Value_SHIFT         0
#define ENET_RMON_R_OVERSIZE_Value(x)            (((uint_32)(((uint_32)(x))<<ENET_RMON_R_OVERSIZE_Value_SHIFT))&ENET_RMON_R_OVERSIZE_Value_MASK)
/* RMON_R_FRAG Bit Fields */
#define ENET_RMON_R_FRAG_Value_MASK              0xFFFFFFFFu
#define ENET_RMON_R_FRAG_Value_SHIFT             0
#define ENET_RMON_R_FRAG_Value(x)                (((uint_32)(((uint_32)(x))<<ENET_RMON_R_FRAG_Value_SHIFT))&ENET_RMON_R_FRAG_Value_MASK)
/* RMON_R_JAB Bit Fields */
#define ENET_RMON_R_JAB_Value_MASK               0xFFFFFFFFu
#define ENET_RMON_R_JAB_Value_SHIFT              0
#define ENET_RMON_R_JAB_Value(x)                 (((uint_32)(((uint_32)(x))<<ENET_RMON_R_JAB_Value_SHIFT))&ENET_RMON_R_JAB_Value_MASK)
/* RMON_R_RESVD_0 Bit Fields */
#define ENET_RMON_R_RESVD_0_Value_MASK           0xFFFFFFFFu
#define ENET_RMON_R_RESVD_0_Value_SHIFT          0
#define ENET_RMON_R_RESVD_0_Value(x)             (((uint_32)(((uint_32)(x))<<ENET_RMON_R_RESVD_0_Value_SHIFT))&ENET_RMON_R_RESVD_0_Value_MASK)
/* RMON_R_P64 Bit Fields */
#define ENET_RMON_R_P64_Value_MASK               0xFFFFFFFFu
#define ENET_RMON_R_P64_Value_SHIFT              0
#define ENET_RMON_R_P64_Value(x)                 (((uint_32)(((uint_32)(x))<<ENET_RMON_R_P64_Value_SHIFT))&ENET_RMON_R_P64_Value_MASK)
/* RMON_R_P65TO127 Bit Fields */
#define ENET_RMON_R_P65TO127_Value_MASK          0xFFFFFFFFu
#define ENET_RMON_R_P65TO127_Value_SHIFT         0
#define ENET_RMON_R_P65TO127_Value(x)            (((uint_32)(((uint_32)(x))<<ENET_RMON_R_P65TO127_Value_SHIFT))&ENET_RMON_R_P65TO127_Value_MASK)
/* RMON_R_P128TO255 Bit Fields */
#define ENET_RMON_R_P128TO255_Value_MASK         0xFFFFFFFFu
#define ENET_RMON_R_P128TO255_Value_SHIFT        0
#define ENET_RMON_R_P128TO255_Value(x)           (((uint_32)(((uint_32)(x))<<ENET_RMON_R_P128TO255_Value_SHIFT))&ENET_RMON_R_P128TO255_Value_MASK)
/* RMON_R_P256TO511 Bit Fields */
#define ENET_RMON_R_P256TO511_Value_MASK         0xFFFFFFFFu
#define ENET_RMON_R_P256TO511_Value_SHIFT        0
#define ENET_RMON_R_P256TO511_Value(x)           (((uint_32)(((uint_32)(x))<<ENET_RMON_R_P256TO511_Value_SHIFT))&ENET_RMON_R_P256TO511_Value_MASK)
/* RMON_R_P512TO1023 Bit Fields */
#define ENET_RMON_R_P512TO1023_Value_MASK        0xFFFFFFFFu
#define ENET_RMON_R_P512TO1023_Value_SHIFT       0
#define ENET_RMON_R_P512TO1023_Value(x)          (((uint_32)(((uint_32)(x))<<ENET_RMON_R_P512TO1023_Value_SHIFT))&ENET_RMON_R_P512TO1023_Value_MASK)
/* RMON_R_P1024TO2047 Bit Fields */
#define ENET_RMON_R_P1024TO2047_Value_MASK       0xFFFFFFFFu
#define ENET_RMON_R_P1024TO2047_Value_SHIFT      0
#define ENET_RMON_R_P1024TO2047_Value(x)         (((uint_32)(((uint_32)(x))<<ENET_RMON_R_P1024TO2047_Value_SHIFT))&ENET_RMON_R_P1024TO2047_Value_MASK)
/* RMON_R_P_GTE2048 Bit Fields */
#define ENET_RMON_R_P_GTE2048_Value_MASK         0xFFFFFFFFu
#define ENET_RMON_R_P_GTE2048_Value_SHIFT        0
#define ENET_RMON_R_P_GTE2048_Value(x)           (((uint_32)(((uint_32)(x))<<ENET_RMON_R_P_GTE2048_Value_SHIFT))&ENET_RMON_R_P_GTE2048_Value_MASK)
/* RMON_R_OCTETS Bit Fields */
#define ENET_RMON_R_OCTETS_Value_MASK            0xFFFFFFFFu
#define ENET_RMON_R_OCTETS_Value_SHIFT           0
#define ENET_RMON_R_OCTETS_Value(x)              (((uint_32)(((uint_32)(x))<<ENET_RMON_R_OCTETS_Value_SHIFT))&ENET_RMON_R_OCTETS_Value_MASK)
/* RMON_R_DROP Bit Fields */
#define ENET_RMON_R_DROP_Value_MASK              0xFFFFFFFFu
#define ENET_RMON_R_DROP_Value_SHIFT             0
#define ENET_RMON_R_DROP_Value(x)                (((uint_32)(((uint_32)(x))<<ENET_RMON_R_DROP_Value_SHIFT))&ENET_RMON_R_DROP_Value_MASK)
/* RMON_R_FRAME_OK Bit Fields */
#define ENET_RMON_R_FRAME_OK_Value_MASK          0xFFFFFFFFu
#define ENET_RMON_R_FRAME_OK_Value_SHIFT         0
#define ENET_RMON_R_FRAME_OK_Value(x)            (((uint_32)(((uint_32)(x))<<ENET_RMON_R_FRAME_OK_Value_SHIFT))&ENET_RMON_R_FRAME_OK_Value_MASK)
/* IEEE_R_CRC Bit Fields */
#define ENET_IEEE_R_CRC_Value_MASK               0xFFFFFFFFu
#define ENET_IEEE_R_CRC_Value_SHIFT              0
#define ENET_IEEE_R_CRC_Value(x)                 (((uint_32)(((uint_32)(x))<<ENET_IEEE_R_CRC_Value_SHIFT))&ENET_IEEE_R_CRC_Value_MASK)
/* IEEE_R_ALIGN Bit Fields */
#define ENET_IEEE_R_ALIGN_Value_MASK             0xFFFFFFFFu
#define ENET_IEEE_R_ALIGN_Value_SHIFT            0
#define ENET_IEEE_R_ALIGN_Value(x)               (((uint_32)(((uint_32)(x))<<ENET_IEEE_R_ALIGN_Value_SHIFT))&ENET_IEEE_R_ALIGN_Value_MASK)
/* IEEE_R_MACERR Bit Fields */
#define ENET_IEEE_R_MACERR_Value_MASK            0xFFFFFFFFu
#define ENET_IEEE_R_MACERR_Value_SHIFT           0
#define ENET_IEEE_R_MACERR_Value(x)              (((uint_32)(((uint_32)(x))<<ENET_IEEE_R_MACERR_Value_SHIFT))&ENET_IEEE_R_MACERR_Value_MASK)
/* IEEE_R_FDXFC Bit Fields */
#define ENET_IEEE_R_FDXFC_Value_MASK             0xFFFFFFFFu
#define ENET_IEEE_R_FDXFC_Value_SHIFT            0
#define ENET_IEEE_R_FDXFC_Value(x)               (((uint_32)(((uint_32)(x))<<ENET_IEEE_R_FDXFC_Value_SHIFT))&ENET_IEEE_R_FDXFC_Value_MASK)
/* IEEE_R_OCTETS_OK Bit Fields */
#define ENET_IEEE_R_OCTETS_OK_Value_MASK         0xFFFFFFFFu
#define ENET_IEEE_R_OCTETS_OK_Value_SHIFT        0
#define ENET_IEEE_R_OCTETS_OK_Value(x)           (((uint_32)(((uint_32)(x))<<ENET_IEEE_R_OCTETS_OK_Value_SHIFT))&ENET_IEEE_R_OCTETS_OK_Value_MASK)
/* ATCR Bit Fields */
#define ENET_ATCR_EN_MASK                        0x1u
#define ENET_ATCR_EN_SHIFT                       0
#define ENET_ATCR_OFFEN_MASK                     0x4u
#define ENET_ATCR_OFFEN_SHIFT                    2
#define ENET_ATCR_OFFRST_MASK                    0x8u
#define ENET_ATCR_OFFRST_SHIFT                   3
#define ENET_ATCR_PEREN_MASK                     0x10u
#define ENET_ATCR_PEREN_SHIFT                    4
#define ENET_ATCR_PINPER_MASK                    0x80u
#define ENET_ATCR_PINPER_SHIFT                   7
#define ENET_ATCR_RESTART_MASK                   0x200u
#define ENET_ATCR_RESTART_SHIFT                  9
#define ENET_ATCR_CAPTURE_MASK                   0x800u
#define ENET_ATCR_CAPTURE_SHIFT                  11
#define ENET_ATCR_SLAVE_MASK                     0x2000u
#define ENET_ATCR_SLAVE_SHIFT                    13
/* ATVR Bit Fields */
#define ENET_ATVR_ATIME_MASK                     0xFFFFFFFFu
#define ENET_ATVR_ATIME_SHIFT                    0
#define ENET_ATVR_ATIME(x)                       (((uint_32)(((uint_32)(x))<<ENET_ATVR_ATIME_SHIFT))&ENET_ATVR_ATIME_MASK)
/* ATOFF Bit Fields */
#define ENET_ATOFF_OFFSET_MASK                   0xFFFFFFFFu
#define ENET_ATOFF_OFFSET_SHIFT                  0
#define ENET_ATOFF_OFFSET(x)                     (((uint_32)(((uint_32)(x))<<ENET_ATOFF_OFFSET_SHIFT))&ENET_ATOFF_OFFSET_MASK)
/* ATPER Bit Fields */
#define ENET_ATPER_PERIOD_MASK                   0xFFFFFFFFu
#define ENET_ATPER_PERIOD_SHIFT                  0
#define ENET_ATPER_PERIOD(x)                     (((uint_32)(((uint_32)(x))<<ENET_ATPER_PERIOD_SHIFT))&ENET_ATPER_PERIOD_MASK)
/* ATCOR Bit Fields */
#define ENET_ATCOR_COR_MASK                      0x7FFFFFFFu
#define ENET_ATCOR_COR_SHIFT                     0
#define ENET_ATCOR_COR(x)                        (((uint_32)(((uint_32)(x))<<ENET_ATCOR_COR_SHIFT))&ENET_ATCOR_COR_MASK)
/* ATINC Bit Fields */
#define ENET_ATINC_INC_MASK                      0x7Fu
#define ENET_ATINC_INC_SHIFT                     0
#define ENET_ATINC_INC(x)                        (((uint_32)(((uint_32)(x))<<ENET_ATINC_INC_SHIFT))&ENET_ATINC_INC_MASK)
#define ENET_ATINC_INC_CORR_MASK                 0x7F00u
#define ENET_ATINC_INC_CORR_SHIFT                8
#define ENET_ATINC_INC_CORR(x)                   (((uint_32)(((uint_32)(x))<<ENET_ATINC_INC_CORR_SHIFT))&ENET_ATINC_INC_CORR_MASK)
/* ATSTMP Bit Fields */
#define ENET_ATSTMP_TIMESTAMP_MASK               0xFFFFFFFFu
#define ENET_ATSTMP_TIMESTAMP_SHIFT              0
#define ENET_ATSTMP_TIMESTAMP(x)                 (((uint_32)(((uint_32)(x))<<ENET_ATSTMP_TIMESTAMP_SHIFT))&ENET_ATSTMP_TIMESTAMP_MASK)
/* TGSR Bit Fields */
#define ENET_TGSR_TF0_MASK                       0x1u
#define ENET_TGSR_TF0_SHIFT                      0
#define ENET_TGSR_TF1_MASK                       0x2u
#define ENET_TGSR_TF1_SHIFT                      1
#define ENET_TGSR_TF2_MASK                       0x4u
#define ENET_TGSR_TF2_SHIFT                      2
#define ENET_TGSR_TF3_MASK                       0x8u
#define ENET_TGSR_TF3_SHIFT                      3
/* TCSR Bit Fields */
#define ENET_TCSR_TDRE_MASK                      0x1u
#define ENET_TCSR_TDRE_SHIFT                     0
#define ENET_TCSR_TMODE_MASK                     0x3Cu
#define ENET_TCSR_TMODE_SHIFT                    2
#define ENET_TCSR_TMODE(x)                       (((uint_32)(((uint_32)(x))<<ENET_TCSR_TMODE_SHIFT))&ENET_TCSR_TMODE_MASK)
#define ENET_TCSR_TIE_MASK                       0x40u
#define ENET_TCSR_TIE_SHIFT                      6
#define ENET_TCSR_TF_MASK                        0x80u
#define ENET_TCSR_TF_SHIFT                       7
/* TCCR Bit Fields */
#define ENET_TCCR_TCC_MASK                       0xFFFFFFFFu
#define ENET_TCCR_TCC_SHIFT                      0
#define ENET_TCCR_TCC(x)                         (((uint_32)(((uint_32)(x))<<ENET_TCCR_TCC_SHIFT))&ENET_TCCR_TCC_MASK)

/*! \} */ /* end of group ENET_Register_Masks */


/* ENET - Peripheral instance base addresses */
/*! Peripheral ENET base pointer */
#define ENET_BASE_PTR                            ((ENET_MemMapPtr)0x400C0000u)

/* ----------------------------------------------------------------------------
   -- ENET - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup ENET_Register_Accessor_Macros ENET - Register accessor macros */
/*! \{ */


/* ENET - Register instance definitions */
/* ENET */
#define ENET_EIR                                 ENET_EIR_REG(ENET_BASE_PTR)
#define ENET_EIMR                                ENET_EIMR_REG(ENET_BASE_PTR)
#define ENET_RDAR                                ENET_RDAR_REG(ENET_BASE_PTR)
#define ENET_TDAR                                ENET_TDAR_REG(ENET_BASE_PTR)
#define ENET_ECR                                 ENET_ECR_REG(ENET_BASE_PTR)
#define ENET_MMFR                                ENET_MMFR_REG(ENET_BASE_PTR)
#define ENET_MSCR                                ENET_MSCR_REG(ENET_BASE_PTR)
#define ENET_MIBC                                ENET_MIBC_REG(ENET_BASE_PTR)
#define ENET_RCR                                 ENET_RCR_REG(ENET_BASE_PTR)
#define ENET_TCR                                 ENET_TCR_REG(ENET_BASE_PTR)
#define ENET_PALR                                ENET_PALR_REG(ENET_BASE_PTR)
#define ENET_PAUR                                ENET_PAUR_REG(ENET_BASE_PTR)
#define ENET_OPD                                 ENET_OPD_REG(ENET_BASE_PTR)
#define ENET_IAUR                                ENET_IAUR_REG(ENET_BASE_PTR)
#define ENET_IALR                                ENET_IALR_REG(ENET_BASE_PTR)
#define ENET_GAUR                                ENET_GAUR_REG(ENET_BASE_PTR)
#define ENET_GALR                                ENET_GALR_REG(ENET_BASE_PTR)
#define ENET_TFWR                                ENET_TFWR_REG(ENET_BASE_PTR)
#define ENET_RDSR                                ENET_RDSR_REG(ENET_BASE_PTR)
#define ENET_TDSR                                ENET_TDSR_REG(ENET_BASE_PTR)
#define ENET_MRBR                                ENET_MRBR_REG(ENET_BASE_PTR)
#define ENET_RSFL                                ENET_RSFL_REG(ENET_BASE_PTR)
#define ENET_RSEM                                ENET_RSEM_REG(ENET_BASE_PTR)
#define ENET_RAEM                                ENET_RAEM_REG(ENET_BASE_PTR)
#define ENET_RAFL                                ENET_RAFL_REG(ENET_BASE_PTR)
#define ENET_TSEM                                ENET_TSEM_REG(ENET_BASE_PTR)
#define ENET_TAEM                                ENET_TAEM_REG(ENET_BASE_PTR)
#define ENET_TAFL                                ENET_TAFL_REG(ENET_BASE_PTR)
#define ENET_TIPG                                ENET_TIPG_REG(ENET_BASE_PTR)
#define ENET_FTRL                                ENET_FTRL_REG(ENET_BASE_PTR)
#define ENET_TACC                                ENET_TACC_REG(ENET_BASE_PTR)
#define ENET_RACC                                ENET_RACC_REG(ENET_BASE_PTR)
#define ENET_ATCR                                ENET_ATCR_REG(ENET_BASE_PTR)
#define ENET_ATVR                                ENET_ATVR_REG(ENET_BASE_PTR)
#define ENET_ATOFF                               ENET_ATOFF_REG(ENET_BASE_PTR)
#define ENET_ATPER                               ENET_ATPER_REG(ENET_BASE_PTR)
#define ENET_ATCOR                               ENET_ATCOR_REG(ENET_BASE_PTR)
#define ENET_ATINC                               ENET_ATINC_REG(ENET_BASE_PTR)
#define ENET_ATSTMP                              ENET_ATSTMP_REG(ENET_BASE_PTR)
#define ENET_TGSR                                ENET_TGSR_REG(ENET_BASE_PTR)
#define ENET_TCSR0                               ENET_TCSR_REG(ENET_BASE_PTR,0)
#define ENET_TCCR0                               ENET_TCCR_REG(ENET_BASE_PTR,0)
#define ENET_TCSR1                               ENET_TCSR_REG(ENET_BASE_PTR,1)
#define ENET_TCCR1                               ENET_TCCR_REG(ENET_BASE_PTR,1)
#define ENET_TCSR2                               ENET_TCSR_REG(ENET_BASE_PTR,2)
#define ENET_TCCR2                               ENET_TCCR_REG(ENET_BASE_PTR,2)
#define ENET_TCSR3                               ENET_TCSR_REG(ENET_BASE_PTR,3)
#define ENET_TCCR3                               ENET_TCCR_REG(ENET_BASE_PTR,3)
#define ENET_RMON_T_DROP                         ENET_RMON_T_DROP_REG(ENET_BASE_PTR)
#define ENET_RMON_T_PACKETS                      ENET_RMON_T_PACKETS_REG(ENET_BASE_PTR)
#define ENET_RMON_T_BC_PKT                       ENET_RMON_T_BC_PKT_REG(ENET_BASE_PTR)
#define ENET_RMON_T_MC_PKT                       ENET_RMON_T_MC_PKT_REG(ENET_BASE_PTR)
#define ENET_RMON_T_CRC_ALIGN                    ENET_RMON_T_CRC_ALIGN_REG(ENET_BASE_PTR)
#define ENET_RMON_T_UNDERSIZE                    ENET_RMON_T_UNDERSIZE_REG(ENET_BASE_PTR)
#define ENET_RMON_T_OVERSIZE                     ENET_RMON_T_OVERSIZE_REG(ENET_BASE_PTR)
#define ENET_RMON_T_FRAG                         ENET_RMON_T_FRAG_REG(ENET_BASE_PTR)
#define ENET_RMON_T_JAB                          ENET_RMON_T_JAB_REG(ENET_BASE_PTR)
#define ENET_RMON_T_COL                          ENET_RMON_T_COL_REG(ENET_BASE_PTR)
#define ENET_RMON_T_P64                          ENET_RMON_T_P64_REG(ENET_BASE_PTR)
#define ENET_RMON_T_P65TO127                     ENET_RMON_T_P65TO127_REG(ENET_BASE_PTR)
#define ENET_RMON_T_P128TO255                    ENET_RMON_T_P128TO255_REG(ENET_BASE_PTR)
#define ENET_RMON_T_P256TO511                    ENET_RMON_T_P256TO511_REG(ENET_BASE_PTR)
#define ENET_RMON_T_P512TO1023                   ENET_RMON_T_P512TO1023_REG(ENET_BASE_PTR)
#define ENET_RMON_T_P1024TO2047                  ENET_RMON_T_P1024TO2047_REG(ENET_BASE_PTR)
#define ENET_RMON_T_P_GTE2048                    ENET_RMON_T_P_GTE2048_REG(ENET_BASE_PTR)
#define ENET_RMON_T_OCTETS                       ENET_RMON_T_OCTETS_REG(ENET_BASE_PTR)
#define ENET_IEEE_T_DROP                         ENET_IEEE_T_DROP_REG(ENET_BASE_PTR)
#define ENET_IEEE_T_FRAME_OK                     ENET_IEEE_T_FRAME_OK_REG(ENET_BASE_PTR)
#define ENET_IEEE_T_1COL                         ENET_IEEE_T_1COL_REG(ENET_BASE_PTR)
#define ENET_IEEE_T_MCOL                         ENET_IEEE_T_MCOL_REG(ENET_BASE_PTR)
#define ENET_IEEE_T_DEF                          ENET_IEEE_T_DEF_REG(ENET_BASE_PTR)
#define ENET_IEEE_T_LCOL                         ENET_IEEE_T_LCOL_REG(ENET_BASE_PTR)
#define ENET_IEEE_T_EXCOL                        ENET_IEEE_T_EXCOL_REG(ENET_BASE_PTR)
#define ENET_IEEE_T_MACERR                       ENET_IEEE_T_MACERR_REG(ENET_BASE_PTR)
#define ENET_IEEE_T_CSERR                        ENET_IEEE_T_CSERR_REG(ENET_BASE_PTR)
#define ENET_IEEE_T_SQE                          ENET_IEEE_T_SQE_REG(ENET_BASE_PTR)
#define ENET_IEEE_T_FDXFC                        ENET_IEEE_T_FDXFC_REG(ENET_BASE_PTR)
#define ENET_IEEE_T_OCTETS_OK                    ENET_IEEE_T_OCTETS_OK_REG(ENET_BASE_PTR)
#define ENET_RMON_R_PACKETS                      ENET_RMON_R_PACKETS_REG(ENET_BASE_PTR)
#define ENET_RMON_R_BC_PKT                       ENET_RMON_R_BC_PKT_REG(ENET_BASE_PTR)
#define ENET_RMON_R_MC_PKT                       ENET_RMON_R_MC_PKT_REG(ENET_BASE_PTR)
#define ENET_RMON_R_CRC_ALIGN                    ENET_RMON_R_CRC_ALIGN_REG(ENET_BASE_PTR)
#define ENET_RMON_R_UNDERSIZE                    ENET_RMON_R_UNDERSIZE_REG(ENET_BASE_PTR)
#define ENET_RMON_R_OVERSIZE                     ENET_RMON_R_OVERSIZE_REG(ENET_BASE_PTR)
#define ENET_RMON_R_FRAG                         ENET_RMON_R_FRAG_REG(ENET_BASE_PTR)
#define ENET_RMON_R_JAB                          ENET_RMON_R_JAB_REG(ENET_BASE_PTR)
#define ENET_RMON_R_RESVD_0                      ENET_RMON_R_RESVD_0_REG(ENET_BASE_PTR)
#define ENET_RMON_R_P64                          ENET_RMON_R_P64_REG(ENET_BASE_PTR)
#define ENET_RMON_R_P65TO127                     ENET_RMON_R_P65TO127_REG(ENET_BASE_PTR)
#define ENET_RMON_R_P128TO255                    ENET_RMON_R_P128TO255_REG(ENET_BASE_PTR)
#define ENET_RMON_R_P256TO511                    ENET_RMON_R_P256TO511_REG(ENET_BASE_PTR)
#define ENET_RMON_R_P512TO1023                   ENET_RMON_R_P512TO1023_REG(ENET_BASE_PTR)
#define ENET_RMON_R_P1024TO2047                  ENET_RMON_R_P1024TO2047_REG(ENET_BASE_PTR)
#define ENET_RMON_R_P_GTE2048                    ENET_RMON_R_P_GTE2048_REG(ENET_BASE_PTR)
#define ENET_RMON_R_OCTETS                       ENET_RMON_R_OCTETS_REG(ENET_BASE_PTR)
#define ENET_IEEE_R_DROP                         ENET_RMON_R_DROP_REG(ENET_BASE_PTR)
#define ENET_IEEE_R_FRAME_OK                     ENET_RMON_R_FRAME_OK_REG(ENET_BASE_PTR)
#define ENET_IEEE_R_CRC                          ENET_IEEE_R_CRC_REG(ENET_BASE_PTR)
#define ENET_IEEE_R_ALIGN                        ENET_IEEE_R_ALIGN_REG(ENET_BASE_PTR)
#define ENET_IEEE_R_MACERR                       ENET_IEEE_R_MACERR_REG(ENET_BASE_PTR)
#define ENET_IEEE_R_FDXFC                        ENET_IEEE_R_FDXFC_REG(ENET_BASE_PTR)
#define ENET_IEEE_R_OCTETS_OK                    ENET_IEEE_R_OCTETS_OK_REG(ENET_BASE_PTR)

/*! \} */ /* end of group ENET_Register_Accessor_Macros */


/*! \} */ /* end of group ENET_Peripheral */

#ifdef __cplusplus
}
#endif


#endif
