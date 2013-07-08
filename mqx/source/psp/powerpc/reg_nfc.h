/**HEADER***********************************************************************
*
* Copyright (c) 2008 Freescale Semiconductor;
* All Rights Reserved
*
********************************************************************************
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
********************************************************************************
*
* $FileName: reg_nfc.h$
* $Version : 3.8.8.0$
* $Date    : Jun-7-2012$
*
* Comments:
*
*   This file contains the type definitions for the MPC512X NAND Flash
*   Controller (NFC).
*
*END***************************************************************************/

#ifndef __reg_nfc_h__
#define __reg_nfc_h__

#include <stdint.h>

/* -----------------------------------------------------------------------------
   -- NFC
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup NFC_Peripheral NFC
 * @{
 */


/**
 * @brief NFC SRAM buffers definitions
 *
 * Macro definition to access NFC SRAM buffers
 */
#define NFC_SRAM_B0_REG(base,index)       ((base)->RESERVED_0[index])
#define NFC_SRAM_B1_REG(base,index)       ((base)->RESERVED_0[index+0x1000u])
#define NFC_SRAM_B2_REG(base,index)       ((base)->RESERVED_0[index+0x2000u])
#define NFC_SRAM_B3_REG(base,index)       ((base)->RESERVED_0[index+0x3000u])


/** NFC - Peripheral register structure */
typedef struct NFC_MemMap {
  uint8_t RESERVED_0[16128];
  uint32_t CMD1;                                   /**< Flash command 1, offset: 0x3F00 */
  uint32_t CMD2;                                   /**< Flash command 2, offset: 0x3F04 */
  uint32_t CAR;                                    /**< Column address, offset: 0x3F08 */
  uint32_t RAR;                                    /**< Row address, offset: 0x3F0C */
  uint32_t RPT;                                    /**< Flash command repeat, offset: 0x3F10 */
  uint32_t RAI;                                    /**< Row address increment, offset: 0x3F14 */
  uint32_t SR1;                                    /**< Flash status 1, offset: 0x3F18 */
  uint32_t SR2;                                    /**< Flash status 2, offset: 0x3F1C */
  uint32_t DMA1;                                   /**< DMA channel 1 address, offset: 0x3F20 */
  uint32_t DMACFG;                                 /**< DMA configuration, offset: 0x3F24 */
  uint32_t SWAP;                                   /**< Cach swap, offset: 0x3F28 */
  uint32_t SECSZ;                                  /**< Sector size, offset: 0x3F2C */
  uint32_t CFG;                                    /**< Flash configuration, offset: 0x3F30 */
  uint32_t DMA2;                                   /**< DMA channel 2 address, offset: 0x3F34 */
  uint32_t ISR;                                    /**< Interrupt status, offset: 0x3F38 */
} volatile NFC_MemMap, * NFC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- NFC - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup NFC_Register_Accessor_Macros NFC - Register accessor macros
 * @{
 */


/* NFC - Register accessors */
#define NFC_CMD1_REG(base)                       ((base)->CMD1)
#define NFC_CMD2_REG(base)                       ((base)->CMD2)
#define NFC_CAR_REG(base)                        ((base)->CAR)
#define NFC_RAR_REG(base)                        ((base)->RAR)
#define NFC_RPT_REG(base)                        ((base)->RPT)
#define NFC_RAI_REG(base)                        ((base)->RAI)
#define NFC_SR1_REG(base)                        ((base)->SR1)
#define NFC_SR2_REG(base)                        ((base)->SR2)
#define NFC_DMA1_REG(base)                       ((base)->DMA1)
#define NFC_DMACFG_REG(base)                     ((base)->DMACFG)
#define NFC_SWAP_REG(base)                       ((base)->SWAP)
#define NFC_SECSZ_REG(base)                      ((base)->SECSZ)
#define NFC_CFG_REG(base)                        ((base)->CFG)
#define NFC_DMA2_REG(base)                       ((base)->DMA2)
#define NFC_ISR_REG(base)                        ((base)->ISR)

/**
 * @}
 */ /* end of group NFC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- NFC Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup NFC_Register_Masks NFC Register Masks
 * @{
 */

/* CMD1 Bit Fields */
#define NFC_CMD1_BYTE3_MASK                      0xFF0000u
#define NFC_CMD1_BYTE3_SHIFT                     16
#define NFC_CMD1_BYTE3(x)                        (((uint32_t)(((uint32_t)(x))<<NFC_CMD1_BYTE3_SHIFT))&NFC_CMD1_BYTE3_MASK)
#define NFC_CMD1_BYTE2_MASK                      0xFF000000u
#define NFC_CMD1_BYTE2_SHIFT                     24
#define NFC_CMD1_BYTE2(x)                        (((uint32_t)(((uint32_t)(x))<<NFC_CMD1_BYTE2_SHIFT))&NFC_CMD1_BYTE2_MASK)
/* CMD2 Bit Fields */
#define NFC_CMD2_BUSY_START_MASK                 0x1u
#define NFC_CMD2_BUSY_START_SHIFT                0
#define NFC_CMD2_BUFNO_MASK                      0x6u
#define NFC_CMD2_BUFNO_SHIFT                     1
#define NFC_CMD2_BUFNO(x)                        (((uint32_t)(((uint32_t)(x))<<NFC_CMD2_BUFNO_SHIFT))&NFC_CMD2_BUFNO_MASK)
#define NFC_CMD2_CODE_MASK                       0xFFFF00u
#define NFC_CMD2_CODE_SHIFT                      8
#define NFC_CMD2_CODE(x)                         (((uint32_t)(((uint32_t)(x))<<NFC_CMD2_CODE_SHIFT))&NFC_CMD2_CODE_MASK)
#define NFC_CMD2_BYTE1_MASK                      0xFF000000u
#define NFC_CMD2_BYTE1_SHIFT                     24
#define NFC_CMD2_BYTE1(x)                        (((uint32_t)(((uint32_t)(x))<<NFC_CMD2_BYTE1_SHIFT))&NFC_CMD2_BYTE1_MASK)
/* CAR Bit Fields */
#define NFC_CAR_BYTE1_MASK                       0xFFu
#define NFC_CAR_BYTE1_SHIFT                      0
#define NFC_CAR_BYTE1(x)                         (((uint32_t)(((uint32_t)(x))<<NFC_CAR_BYTE1_SHIFT))&NFC_CAR_BYTE1_MASK)
#define NFC_CAR_BYTE2_MASK                       0xFF00u
#define NFC_CAR_BYTE2_SHIFT                      8
#define NFC_CAR_BYTE2(x)                         (((uint32_t)(((uint32_t)(x))<<NFC_CAR_BYTE2_SHIFT))&NFC_CAR_BYTE2_MASK)
/* RAR Bit Fields */
#define NFC_RAR_BYTE1_MASK                       0xFFu
#define NFC_RAR_BYTE1_SHIFT                      0
#define NFC_RAR_BYTE1(x)                         (((uint32_t)(((uint32_t)(x))<<NFC_RAR_BYTE1_SHIFT))&NFC_RAR_BYTE1_MASK)
#define NFC_RAR_BYTE2_MASK                       0xFF00u
#define NFC_RAR_BYTE2_SHIFT                      8
#define NFC_RAR_BYTE2(x)                         (((uint32_t)(((uint32_t)(x))<<NFC_RAR_BYTE2_SHIFT))&NFC_RAR_BYTE2_MASK)
#define NFC_RAR_BYTE3_MASK                       0xFF0000u
#define NFC_RAR_BYTE3_SHIFT                      16
#define NFC_RAR_BYTE3(x)                         (((uint32_t)(((uint32_t)(x))<<NFC_RAR_BYTE3_SHIFT))&NFC_RAR_BYTE3_MASK)
#define NFC_RAR_RB0_MASK                         0x1000000u
#define NFC_RAR_RB0_SHIFT                        24
#define NFC_RAR_RB1_MASK                         0x2000000u
#define NFC_RAR_RB1_SHIFT                        25
#define NFC_RAR_CS0_MASK                         0x10000000u
#define NFC_RAR_CS0_SHIFT                        28
#define NFC_RAR_CS1_MASK                         0x20000000u
#define NFC_RAR_CS1_SHIFT                        29
/* RPT Bit Fields */
#define NFC_RPT_COUNT_MASK                       0xFFFFu
#define NFC_RPT_COUNT_SHIFT                      0
#define NFC_RPT_COUNT(x)                         (((uint32_t)(((uint32_t)(x))<<NFC_RPT_COUNT_SHIFT))&NFC_RPT_COUNT_MASK)
/* RAI Bit Fields */
#define NFC_RAI_INC1_MASK                        0xFFu
#define NFC_RAI_INC1_SHIFT                       0
#define NFC_RAI_INC1(x)                          (((uint32_t)(((uint32_t)(x))<<NFC_RAI_INC1_SHIFT))&NFC_RAI_INC1_MASK)
#define NFC_RAI_INC2_MASK                        0xFF00u
#define NFC_RAI_INC2_SHIFT                       8
#define NFC_RAI_INC2(x)                          (((uint32_t)(((uint32_t)(x))<<NFC_RAI_INC2_SHIFT))&NFC_RAI_INC2_MASK)
#define NFC_RAI_INC3_MASK                        0xFF0000u
#define NFC_RAI_INC3_SHIFT                       16
#define NFC_RAI_INC3(x)                          (((uint32_t)(((uint32_t)(x))<<NFC_RAI_INC3_SHIFT))&NFC_RAI_INC3_MASK)
/* SR1 Bit Fields */
#define NFC_SR1_ID4_MASK                         0xFFu
#define NFC_SR1_ID4_SHIFT                        0
#define NFC_SR1_ID4(x)                           (((uint32_t)(((uint32_t)(x))<<NFC_SR1_ID4_SHIFT))&NFC_SR1_ID4_MASK)
#define NFC_SR1_ID3_MASK                         0xFF00u
#define NFC_SR1_ID3_SHIFT                        8
#define NFC_SR1_ID3(x)                           (((uint32_t)(((uint32_t)(x))<<NFC_SR1_ID3_SHIFT))&NFC_SR1_ID3_MASK)
#define NFC_SR1_ID2_MASK                         0xFF0000u
#define NFC_SR1_ID2_SHIFT                        16
#define NFC_SR1_ID2(x)                           (((uint32_t)(((uint32_t)(x))<<NFC_SR1_ID2_SHIFT))&NFC_SR1_ID2_MASK)
#define NFC_SR1_ID1_MASK                         0xFF000000u
#define NFC_SR1_ID1_SHIFT                        24
#define NFC_SR1_ID1(x)                           (((uint32_t)(((uint32_t)(x))<<NFC_SR1_ID1_SHIFT))&NFC_SR1_ID1_MASK)
/* SR2 Bit Fields */
#define NFC_SR2_STATUS1_MASK                     0xFFu
#define NFC_SR2_STATUS1_SHIFT                    0
#define NFC_SR2_STATUS1(x)                       (((uint32_t)(((uint32_t)(x))<<NFC_SR2_STATUS1_SHIFT))&NFC_SR2_STATUS1_MASK)
#define NFC_SR2_ID5_MASK                         0xFF000000u
#define NFC_SR2_ID5_SHIFT                        24
#define NFC_SR2_ID5(x)                           (((uint32_t)(((uint32_t)(x))<<NFC_SR2_ID5_SHIFT))&NFC_SR2_ID5_MASK)
/* DMA1 Bit Fields */
#define NFC_DMA1_ADDRESS_MASK                    0xFFFFFFFFu
#define NFC_DMA1_ADDRESS_SHIFT                   0
#define NFC_DMA1_ADDRESS(x)                      (((uint32_t)(((uint32_t)(x))<<NFC_DMA1_ADDRESS_SHIFT))&NFC_DMA1_ADDRESS_MASK)
/* DMACFG Bit Fields */
#define NFC_DMACFG_ACT2_MASK                     0x1u
#define NFC_DMACFG_ACT2_SHIFT                    0
#define NFC_DMACFG_ACT1_MASK                     0x2u
#define NFC_DMACFG_ACT1_SHIFT                    1
#define NFC_DMACFG_OFFSET2_MASK                  0x1E00u
#define NFC_DMACFG_OFFSET2_SHIFT                 9
#define NFC_DMACFG_OFFSET2(x)                    (((uint32_t)(((uint32_t)(x))<<NFC_DMACFG_OFFSET2_SHIFT))&NFC_DMACFG_OFFSET2_MASK)
#define NFC_DMACFG_COUNT2_MASK                   0xFE000u
#define NFC_DMACFG_COUNT2_SHIFT                  13
#define NFC_DMACFG_COUNT2(x)                     (((uint32_t)(((uint32_t)(x))<<NFC_DMACFG_COUNT2_SHIFT))&NFC_DMACFG_COUNT2_MASK)
#define NFC_DMACFG_COUNT1_MASK                   0xFFF00000u
#define NFC_DMACFG_COUNT1_SHIFT                  20
#define NFC_DMACFG_COUNT1(x)                     (((uint32_t)(((uint32_t)(x))<<NFC_DMACFG_COUNT1_SHIFT))&NFC_DMACFG_COUNT1_MASK)
/* SWAP Bit Fields */
#define NFC_SWAP_ADDR2_MASK                      0xFFEu
#define NFC_SWAP_ADDR2_SHIFT                     1
#define NFC_SWAP_ADDR2(x)                        (((uint32_t)(((uint32_t)(x))<<NFC_SWAP_ADDR2_SHIFT))&NFC_SWAP_ADDR2_MASK)
#define NFC_SWAP_ADDR1_MASK                      0xFFE0000u
#define NFC_SWAP_ADDR1_SHIFT                     17
#define NFC_SWAP_ADDR1(x)                        (((uint32_t)(((uint32_t)(x))<<NFC_SWAP_ADDR1_SHIFT))&NFC_SWAP_ADDR1_MASK)
/* SECSZ Bit Fields */
#define NFC_SECSZ_SIZE_MASK                      0x1FFFu
#define NFC_SECSZ_SIZE_SHIFT                     0
#define NFC_SECSZ_SIZE(x)                        (((uint32_t)(((uint32_t)(x))<<NFC_SECSZ_SIZE_SHIFT))&NFC_SECSZ_SIZE_MASK)
/* CFG Bit Fields */
#define NFC_CFG_PAGECNT_MASK                     0xFu
#define NFC_CFG_PAGECNT_SHIFT                    0
#define NFC_CFG_PAGECNT(x)                       (((uint32_t)(((uint32_t)(x))<<NFC_CFG_PAGECNT_SHIFT))&NFC_CFG_PAGECNT_MASK)
#define NFC_CFG_AIBN_MASK                        0x10u
#define NFC_CFG_AIBN_SHIFT                       4
#define NFC_CFG_AIAD_MASK                        0x20u
#define NFC_CFG_AIAD_SHIFT                       5
#define NFC_CFG_BTMD_MASK                       (0x40u)
#define NFC_CFG_BTMD_SHIFT                       6
#define NFC_CFG_BITWIDTH_MASK                    0x80u
#define NFC_CFG_BITWIDTH_SHIFT                   7
#define NFC_CFG_TIMEOUT_MASK                     0x1F00u
#define NFC_CFG_TIMEOUT_SHIFT                    8
#define NFC_CFG_TIMEOUT(x)                       (((uint32_t)(((uint32_t)(x))<<NFC_CFG_TIMEOUT_SHIFT))&NFC_CFG_TIMEOUT_MASK)
#define NFC_CFG_IDCNT_MASK                       0xE000u
#define NFC_CFG_IDCNT_SHIFT                      13
#define NFC_CFG_IDCNT(x)                         (((uint32_t)(((uint32_t)(x))<<NFC_CFG_IDCNT_SHIFT))&NFC_CFG_IDCNT_MASK)
#define NFC_CFG_FAST_MASK                        0x10000u
#define NFC_CFG_FAST_SHIFT                       16
#define NFC_CFG_ECCMODE_MASK                     0xE0000u
#define NFC_CFG_ECCMODE_SHIFT                    17
#define NFC_CFG_ECCMODE(x)                       (((uint32_t)(((uint32_t)(x))<<NFC_CFG_ECCMODE_SHIFT))&NFC_CFG_ECCMODE_MASK)
#define NFC_CFG_DMAREQ_MASK                      0x100000u
#define NFC_CFG_DMAREQ_SHIFT                     20
#define NFC_CFG_ECCSRAM_MASK                     0x200000u
#define NFC_CFG_ECCSRAM_SHIFT                    21
#define NFC_CFG_ECCAD_MASK                       0x7FC00000u
#define NFC_CFG_ECCAD_SHIFT                      22
#define NFC_CFG_ECCAD(x)                         (((uint32_t)(((uint32_t)(x))<<NFC_CFG_ECCAD_SHIFT))&NFC_CFG_ECCAD_MASK)
#define NFC_CFG_STOPWERR_MASK                    0x80000000u
#define NFC_CFG_STOPWERR_SHIFT                   31
/* DMA2 Bit Fields */
#define NFC_DMA2_ADDRESS_MASK                    0xFFFFFFFFu
#define NFC_DMA2_ADDRESS_SHIFT                   0
#define NFC_DMA2_ADDRESS(x)                      (((uint32_t)(((uint32_t)(x))<<NFC_DMA2_ADDRESS_SHIFT))&NFC_DMA2_ADDRESS_MASK)
/* ISR Bit Fields */
#define NFC_ISR_DMABN_MASK                       0x3u
#define NFC_ISR_DMABN_SHIFT                      0
#define NFC_ISR_DMABN(x)                         (((uint32_t)(((uint32_t)(x))<<NFC_ISR_DMABN_SHIFT))&NFC_ISR_DMABN_MASK)
#define NFC_ISR_ECCBN_MASK                       0xCu
#define NFC_ISR_ECCBN_SHIFT                      2
#define NFC_ISR_ECCBN(x)                         (((uint32_t)(((uint32_t)(x))<<NFC_ISR_ECCBN_SHIFT))&NFC_ISR_ECCBN_MASK)
#define NFC_ISR_RESBN_MASK                       0x30u
#define NFC_ISR_RESBN_SHIFT                      4
#define NFC_ISR_RESBN(x)                         (((uint32_t)(((uint32_t)(x))<<NFC_ISR_RESBN_SHIFT))&NFC_ISR_RESBN_MASK)
#define NFC_ISR_IDLECLR_MASK                     0x20000u
#define NFC_ISR_IDLECLR_SHIFT                    17
#define NFC_ISR_DONECLR_MASK                     0x40000u
#define NFC_ISR_DONECLR_SHIFT                    18
#define NFC_ISR_WERRCLR_MASK                     0x80000u
#define NFC_ISR_WERRCLR_SHIFT                    19
#define NFC_ISR_IDLEEN_MASK                      0x100000u
#define NFC_ISR_IDLEEN_SHIFT                     20
#define NFC_ISR_DONEEN_MASK                      0x200000u
#define NFC_ISR_DONEEN_SHIFT                     21
#define NFC_ISR_WERREN_MASK                      0x400000u
#define NFC_ISR_WERREN_SHIFT                     22
#define NFC_ISR_DMABUSY_MASK                     0x800000u
#define NFC_ISR_DMABUSY_SHIFT                    23
#define NFC_ISR_ECCBUSY_MASK                     0x1000000u
#define NFC_ISR_ECCBUSY_SHIFT                    24
#define NFC_ISR_RESBUSY_MASK                     0x2000000u
#define NFC_ISR_RESBUSY_SHIFT                    25
#define NFC_ISR_CMDBUSY_MASK                     0x4000000u
#define NFC_ISR_CMDBUSY_SHIFT                    26
#define NFC_ISR_WERRNS_MASK                      0x8000000u
#define NFC_ISR_WERRNS_SHIFT                     27
#define NFC_ISR_IDLE_MASK                        0x20000000u
#define NFC_ISR_IDLE_SHIFT                       29
#define NFC_ISR_DONE_MASK                        0x40000000u
#define NFC_ISR_DONE_SHIFT                       30
#define NFC_ISR_WERR_MASK                        0x80000000u
#define NFC_ISR_WERR_SHIFT                       31

/**
 * @}
 */ /* end of group NFC_Register_Masks */



/**
 * @}
 */ /* end of group NFC_Peripheral */

#endif  /*__reg_nfc_h__ */
