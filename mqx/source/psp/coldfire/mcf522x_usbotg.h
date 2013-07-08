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
* $FileName: mcf522x_usbotg.h$
* $Version : 3.7.14.0$
* $Date    : Feb-7-2011$
*
* Comments:
*
*   This file contains the type definitions for the mcf522x usbotg module.
*
*END************************************************************************/

#ifndef __mcf522x_usbotg_h__
#define __mcf522x_usbotg_h__

#define __mcf522x_usbotg_h__version "$Version:3.7.14.0$"
#define __mcf522x_usbotg_h__date    "$Date:Feb-7-2011$"

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*------------------------------------------------------------------------*/
/*
** USB_MemMap reflecting generic USB-OTG peripheral structure
*/

typedef struct USB_MemMap {
  uint8_t PERID;                                   /*!< Peripheral ID Register, offset: 0x0 */
  uint8_t RESERVED_0[3];
  uint8_t IDCOMP;                                  /*!< Peripheral ID Complement Register, offset: 0x4 */
  uint8_t RESERVED_1[3];
  uint8_t REV;                                     /*!< Peripheral Revision Register, offset: 0x8 */
  uint8_t RESERVED_2[3];
  uint8_t ADDINFO;                                 /*!< Peripheral Additional Info Register, offset: 0xC */
  uint8_t RESERVED_3[3];
  uint8_t OTGISTAT;                                /*!< OTG Interrupt Status Register, offset: 0x10 */
  uint8_t RESERVED_4[3];
  uint8_t OTGICR;                                  /*!< OTG Interrupt Control Register, offset: 0x14 */
  uint8_t RESERVED_5[3];
  uint8_t OTGSTAT;                                 /*!< OTG Status Register, offset: 0x18 */
  uint8_t RESERVED_6[3];
  uint8_t OTGCTL;                                  /*!< OTG Control Register, offset: 0x1C */
  uint8_t RESERVED_7[99];
  uint8_t ISTAT;                                   /*!< Interrupt Status Register, offset: 0x80 */
  uint8_t RESERVED_8[3];
  uint8_t INTEN;                                   /*!< Interrupt Enable Register, offset: 0x84 */
  uint8_t RESERVED_9[3];
  uint8_t ERRSTAT;                                 /*!< Error Interrupt Status Register, offset: 0x88 */
  uint8_t RESERVED_10[3];
  uint8_t ERREN;                                   /*!< Error Interrupt Enable Register, offset: 0x8C */
  uint8_t RESERVED_11[3];
  uint8_t STAT;                                    /*!< Status Register, offset: 0x90 */
  uint8_t RESERVED_12[3];
  uint8_t CTL;                                     /*!< Control Register, offset: 0x94 */
  uint8_t RESERVED_13[3];
  uint8_t ADDR;                                    /*!< Address Register, offset: 0x98 */
  uint8_t RESERVED_14[3];
  uint8_t BDTPAGE1;                                /*!< BDT Page Register 1, offset: 0x9C */
  uint8_t RESERVED_15[3];
  uint8_t FRMNUML;                                 /*!< Frame Number Register Low, offset: 0xA0 */
  uint8_t RESERVED_16[3];
  uint8_t FRMNUMH;                                 /*!< Frame Number Register High, offset: 0xA4 */
  uint8_t RESERVED_17[3];
  uint8_t TOKEN;                                   /*!< Token Register, offset: 0xA8 */
  uint8_t RESERVED_18[3];
  uint8_t SOFTHLD;                                 /*!< SOF Threshold Register, offset: 0xAC */
  uint8_t RESERVED_19[3];
  uint8_t BDTPAGE2;                                /*!< BDT Page Register 2, offset: 0xB0 */
  uint8_t RESERVED_20[3];
  uint8_t BDTPAGE3;                                /*!< BDT Page Register 3, offset: 0xB4 */
  uint8_t RESERVED_21[11];
  struct {                                         /* offset: 0xC0, array step: 0x4 */
    uint8_t ENDPT;                                   /*!< Endpoint Control Register, array offset: 0xC0, array step: 0x4 */
    uint8_t RESERVED_0[3];
  } ENDPOINT[16];
  uint8_t USBCTRL;                                 /*!< USB Control Register, offset: 0x100 */
  uint8_t RESERVED_22[3];
  uint8_t OBSERVE;                                 /*!< USB OTG Observe Register, offset: 0x104 */
  uint8_t RESERVED_23[3];
  uint8_t CONTROL;                                 /*!< USB OTG Control Register, offset: 0x108 */
  uint8_t RESERVED_24[3];
  uint8_t USBTRC0;                                 /*!< USB Transceiver and Regulator Control Register 0, offset: 0x10C */
  uint8_t RESERVED_25[3];
  uint8_t OTGPIN;                                  /*!< USB OTG PIN Observer, offset: 0x110  */
} USB_MemMap;
typedef volatile USB_MemMap *USB_MemMapPtr;

/*! \brief USBOTG - Register accessors */
#define USB_PERID_REG(base)                      ((base)->PERID)
#define USB_IDCOMP_REG(base)                     ((base)->IDCOMP)
#define USB_REV_REG(base)                        ((base)->REV)
#define USB_ADDINFO_REG(base)                    ((base)->ADDINFO)
#define USB_OTGISTAT_REG(base)                   ((base)->OTGISTAT)
#define USB_OTGICR_REG(base)                     ((base)->OTGICR)
#define USB_OTGSTAT_REG(base)                    ((base)->OTGSTAT)
#define USB_OTGCTL_REG(base)                     ((base)->OTGCTL)
#define USB_ISTAT_REG(base)                      ((base)->ISTAT)
#define USB_INTEN_REG(base)                      ((base)->INTEN)
#define USB_ERRSTAT_REG(base)                    ((base)->ERRSTAT)
#define USB_ERREN_REG(base)                      ((base)->ERREN)
#define USB_STAT_REG(base)                       ((base)->STAT)
#define USB_CTL_REG(base)                        ((base)->CTL)
#define USB_ADDR_REG(base)                       ((base)->ADDR)
#define USB_BDTPAGE1_REG(base)                   ((base)->BDTPAGE1)
#define USB_FRMNUML_REG(base)                    ((base)->FRMNUML)
#define USB_FRMNUMH_REG(base)                    ((base)->FRMNUMH)
#define USB_TOKEN_REG(base)                      ((base)->TOKEN)
#define USB_SOFTHLD_REG(base)                    ((base)->SOFTHLD)
#define USB_BDTPAGE2_REG(base)                   ((base)->BDTPAGE2)
#define USB_BDTPAGE3_REG(base)                   ((base)->BDTPAGE3)
#define USB_ENDPT_REG(base,index)                ((base)->ENDPOINT[index].ENDPT)
#define USB_USBCTRL_REG(base)                    ((base)->USBCTRL)
#define USB_OBSERVE_REG(base)                    ((base)->OBSERVE)
#define USB_CONTROL_REG(base)                    ((base)->CONTROL)
#define USB_USBTRC0_REG(base)                    ((base)->USBTRC0)

/*! \brief USBOTG - Register bit group masks and offsets */
/*! \brief PERID Bit Fields */
#define USB_PERID_ID_MASK                        0x3Fu
#define USB_PERID_ID_SHIFT                       0
#define USB_PERID_ID(x)                          (((uint8_t)(((uint8_t)(x))<<USB_PERID_ID_SHIFT))&USB_PERID_ID_MASK)
/* IDCOMP Bit Fields */
#define USB_IDCOMP_NID_MASK                      0x3Fu
#define USB_IDCOMP_NID_SHIFT                     0
#define USB_IDCOMP_NID(x)                        (((uint8_t)(((uint8_t)(x))<<USB_IDCOMP_NID_SHIFT))&USB_IDCOMP_NID_MASK)
/* REV Bit Fields */
#define USB_REV_REV_MASK                         0xFFu
#define USB_REV_REV_SHIFT                        0
#define USB_REV_REV(x)                           (((uint8_t)(((uint8_t)(x))<<USB_REV_REV_SHIFT))&USB_REV_REV_MASK)
/* ADDINFO Bit Fields */
#define USB_ADDINFO_IEHOST_MASK                  0x1u
#define USB_ADDINFO_IEHOST_SHIFT                 0
#define USB_ADDINFO_IRQNUM_MASK                  0xF8u
#define USB_ADDINFO_IRQNUM_SHIFT                 3
#define USB_ADDINFO_IRQNUM(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ADDINFO_IRQNUM_SHIFT))&USB_ADDINFO_IRQNUM_MASK)
/* OTGISTAT Bit Fields */
#define USB_OTGISTAT_AVBUSCHG_MASK               0x1u
#define USB_OTGISTAT_AVBUSCHG_SHIFT              0
#define USB_OTGISTAT_B_SESS_CHG_MASK             0x4u
#define USB_OTGISTAT_B_SESS_CHG_SHIFT            2
#define USB_OTGISTAT_SESSVLDCHG_MASK             0x8u
#define USB_OTGISTAT_SESSVLDCHG_SHIFT            3
#define USB_OTGISTAT_LINE_STATE_CHG_MASK         0x20u
#define USB_OTGISTAT_LINE_STATE_CHG_SHIFT        5
#define USB_OTGISTAT_ONEMSEC_MASK                0x40u
#define USB_OTGISTAT_ONEMSEC_SHIFT               6
#define USB_OTGISTAT_IDCHG_MASK                  0x80u
#define USB_OTGISTAT_IDCHG_SHIFT                 7
/* OTGICR Bit Fields */
#define USB_OTGICR_AVBUSEN_MASK                  0x1u
#define USB_OTGICR_AVBUSEN_SHIFT                 0
#define USB_OTGICR_BSESSEN_MASK                  0x4u
#define USB_OTGICR_BSESSEN_SHIFT                 2
#define USB_OTGICR_SESSVLDEN_MASK                0x8u
#define USB_OTGICR_SESSVLDEN_SHIFT               3
#define USB_OTGICR_LINESTATEEN_MASK              0x20u
#define USB_OTGICR_LINESTATEEN_SHIFT             5
#define USB_OTGICR_ONEMSECEN_MASK                0x40u
#define USB_OTGICR_ONEMSECEN_SHIFT               6
#define USB_OTGICR_IDEN_MASK                     0x80u
#define USB_OTGICR_IDEN_SHIFT                    7
/* OTGSTAT Bit Fields */
#define USB_OTGSTAT_AVBUSVLD_MASK                0x1u
#define USB_OTGSTAT_AVBUSVLD_SHIFT               0
#define USB_OTGSTAT_BSESSEND_MASK                0x4u
#define USB_OTGSTAT_BSESSEND_SHIFT               2
#define USB_OTGSTAT_SESS_VLD_MASK                0x8u
#define USB_OTGSTAT_SESS_VLD_SHIFT               3
#define USB_OTGSTAT_LINESTATESTABLE_MASK         0x20u
#define USB_OTGSTAT_LINESTATESTABLE_SHIFT        5
#define USB_OTGSTAT_ONEMSECEN_MASK               0x40u
#define USB_OTGSTAT_ONEMSECEN_SHIFT              6
#define USB_OTGSTAT_ID_MASK                      0x80u
#define USB_OTGSTAT_ID_SHIFT                     7
/* OTGCTL Bit Fields */
#define USB_OTGCTL_VBUS_DSCHG_MASK               0x1u
#define USB_OTGCTL_VBUS_DSCHG_SHIFT              0
#define USB_OTGCTL_VBUS_CHG_MASK                 0x2u
#define USB_OTGCTL_VBUS_CHG_SHIFT                1
#define USB_OTGCTL_OTGEN_MASK                    0x4u
#define USB_OTGCTL_OTGEN_SHIFT                   2
#define USB_OTGCTL_VBUS_EN_MASK                  0x8u
#define USB_OTGCTL_VBUS_EN_SHIFT                 3
#define USB_OTGCTL_DMLOW_MASK                    0x10u
#define USB_OTGCTL_DMLOW_SHIFT                   4
#define USB_OTGCTL_DPLOW_MASK                    0x20u
#define USB_OTGCTL_DPLOW_SHIFT                   5
#define USB_OTGCTL_DM_HIGH_MASK                  0x40u
#define USB_OTGCTL_DM_HIGH_SHIFT                 6
#define USB_OTGCTL_DPHIGH_MASK                   0x80u
#define USB_OTGCTL_DPHIGH_SHIFT                  7
/* ISTAT Bit Fields */
#define USB_ISTAT_USBRST_MASK                    0x1u
#define USB_ISTAT_USBRST_SHIFT                   0
#define USB_ISTAT_ERROR_MASK                     0x2u
#define USB_ISTAT_ERROR_SHIFT                    1
#define USB_ISTAT_SOFTOK_MASK                    0x4u
#define USB_ISTAT_SOFTOK_SHIFT                   2
#define USB_ISTAT_TOKDNE_MASK                    0x8u
#define USB_ISTAT_TOKDNE_SHIFT                   3
#define USB_ISTAT_SLEEP_MASK                     0x10u
#define USB_ISTAT_SLEEP_SHIFT                    4
#define USB_ISTAT_RESUME_MASK                    0x20u
#define USB_ISTAT_RESUME_SHIFT                   5
#define USB_ISTAT_ATTACH_MASK                    0x40u
#define USB_ISTAT_ATTACH_SHIFT                   6
#define USB_ISTAT_STALL_MASK                     0x80u
#define USB_ISTAT_STALL_SHIFT                    7
/* INTEN Bit Fields */
#define USB_INTEN_USBRSTEN_MASK                  0x1u
#define USB_INTEN_USBRSTEN_SHIFT                 0
#define USB_INTEN_ERROREN_MASK                   0x2u
#define USB_INTEN_ERROREN_SHIFT                  1
#define USB_INTEN_SOFTOKEN_MASK                  0x4u
#define USB_INTEN_SOFTOKEN_SHIFT                 2
#define USB_INTEN_TOKDNEEN_MASK                  0x8u
#define USB_INTEN_TOKDNEEN_SHIFT                 3
#define USB_INTEN_SLEEPEN_MASK                   0x10u
#define USB_INTEN_SLEEPEN_SHIFT                  4
#define USB_INTEN_RESUMEEN_MASK                  0x20u
#define USB_INTEN_RESUMEEN_SHIFT                 5
#define USB_INTEN_ATTACHEN_MASK                  0x40u
#define USB_INTEN_ATTACHEN_SHIFT                 6
#define USB_INTEN_STALLEN_MASK                   0x80u
#define USB_INTEN_STALLEN_SHIFT                  7
/* ERRSTAT Bit Fields */
#define USB_ERRSTAT_PIDERR_MASK                  0x1u
#define USB_ERRSTAT_PIDERR_SHIFT                 0
#define USB_ERRSTAT_CRC5EOF_MASK                 0x2u
#define USB_ERRSTAT_CRC5EOF_SHIFT                1
#define USB_ERRSTAT_CRC16_MASK                   0x4u
#define USB_ERRSTAT_CRC16_SHIFT                  2
#define USB_ERRSTAT_DFN8_MASK                    0x8u
#define USB_ERRSTAT_DFN8_SHIFT                   3
#define USB_ERRSTAT_BTOERR_MASK                  0x10u
#define USB_ERRSTAT_BTOERR_SHIFT                 4
#define USB_ERRSTAT_DMAERR_MASK                  0x20u
#define USB_ERRSTAT_DMAERR_SHIFT                 5
#define USB_ERRSTAT_BTSERR_MASK                  0x80u
#define USB_ERRSTAT_BTSERR_SHIFT                 7
/* ERREN Bit Fields */
#define USB_ERREN_PIDERREN_MASK                  0x1u
#define USB_ERREN_PIDERREN_SHIFT                 0
#define USB_ERREN_CRC5EOFEN_MASK                 0x2u
#define USB_ERREN_CRC5EOFEN_SHIFT                1
#define USB_ERREN_CRC16EN_MASK                   0x4u
#define USB_ERREN_CRC16EN_SHIFT                  2
#define USB_ERREN_DFN8EN_MASK                    0x8u
#define USB_ERREN_DFN8EN_SHIFT                   3
#define USB_ERREN_BTOERREN_MASK                  0x10u
#define USB_ERREN_BTOERREN_SHIFT                 4
#define USB_ERREN_DMAERREN_MASK                  0x20u
#define USB_ERREN_DMAERREN_SHIFT                 5
#define USB_ERREN_BTSERREN_MASK                  0x80u
#define USB_ERREN_BTSERREN_SHIFT                 7
/* STAT Bit Fields */
#define USB_STAT_ODD_MASK                        0x4u
#define USB_STAT_ODD_SHIFT                       2
#define USB_STAT_TX_MASK                         0x8u
#define USB_STAT_TX_SHIFT                        3
#define USB_STAT_ENDP_MASK                       0xF0u
#define USB_STAT_ENDP_SHIFT                      4
#define USB_STAT_ENDP(x)                         (((uint8_t)(((uint8_t)(x))<<USB_STAT_ENDP_SHIFT))&USB_STAT_ENDP_MASK)
/* CTL Bit Fields */
#define USB_CTL_USBENSOFEN_MASK                  0x1u
#define USB_CTL_USBENSOFEN_SHIFT                 0
#define USB_CTL_ODDRST_MASK                      0x2u
#define USB_CTL_ODDRST_SHIFT                     1
#define USB_CTL_RESUME_MASK                      0x4u
#define USB_CTL_RESUME_SHIFT                     2
#define USB_CTL_HOSTMODEEN_MASK                  0x8u
#define USB_CTL_HOSTMODEEN_SHIFT                 3
#define USB_CTL_RESET_MASK                       0x10u
#define USB_CTL_RESET_SHIFT                      4
#define USB_CTL_TXSUSPENDTOKENBUSY_MASK          0x20u
#define USB_CTL_TXSUSPENDTOKENBUSY_SHIFT         5
#define USB_CTL_SE0_MASK                         0x40u
#define USB_CTL_SE0_SHIFT                        6
#define USB_CTL_JSTATE_MASK                      0x80u
#define USB_CTL_JSTATE_SHIFT                     7
/* ADDR Bit Fields */
#define USB_ADDR_ADDR_MASK                       0x7Fu
#define USB_ADDR_ADDR_SHIFT                      0
#define USB_ADDR_ADDR(x)                         (((uint8_t)(((uint8_t)(x))<<USB_ADDR_ADDR_SHIFT))&USB_ADDR_ADDR_MASK)
#define USB_ADDR_LSEN_MASK                       0x80u
#define USB_ADDR_LSEN_SHIFT                      7
/* BDTPAGE1 Bit Fields */
#define USB_BDTPAGE1_BDTBA_MASK                  0xFEu
#define USB_BDTPAGE1_BDTBA_SHIFT                 1
#define USB_BDTPAGE1_BDTBA(x)                    (((uint8_t)(((uint8_t)(x))<<USB_BDTPAGE1_BDTBA_SHIFT))&USB_BDTPAGE1_BDTBA_MASK)
/* FRMNUML Bit Fields */
#define USB_FRMNUML_FRM_MASK                     0xFFu
#define USB_FRMNUML_FRM_SHIFT                    0
#define USB_FRMNUML_FRM(x)                       (((uint8_t)(((uint8_t)(x))<<USB_FRMNUML_FRM_SHIFT))&USB_FRMNUML_FRM_MASK)
/* FRMNUMH Bit Fields */
#define USB_FRMNUMH_FRM_MASK                     0x7u
#define USB_FRMNUMH_FRM_SHIFT                    0
#define USB_FRMNUMH_FRM(x)                       (((uint8_t)(((uint8_t)(x))<<USB_FRMNUMH_FRM_SHIFT))&USB_FRMNUMH_FRM_MASK)
/* TOKEN Bit Fields */
#define USB_TOKEN_TOKENENDPT_MASK                0xFu
#define USB_TOKEN_TOKENENDPT_SHIFT               0
#define USB_TOKEN_TOKENENDPT(x)                  (((uint8_t)(((uint8_t)(x))<<USB_TOKEN_TOKENENDPT_SHIFT))&USB_TOKEN_TOKENENDPT_MASK)
#define USB_TOKEN_TOKENPID_MASK                  0xF0u
#define USB_TOKEN_TOKENPID_SHIFT                 4
#define USB_TOKEN_TOKENPID(x)                    (((uint8_t)(((uint8_t)(x))<<USB_TOKEN_TOKENPID_SHIFT))&USB_TOKEN_TOKENPID_MASK)
#define USB_TOKEN_TOKENPID_OUT                   USB_TOKEN_TOKENPID(0x1)
#define USB_TOKEN_TOKENPID_IN                    USB_TOKEN_TOKENPID(0x9)
#define USB_TOKEN_TOKENPID_SETUP                 USB_TOKEN_TOKENPID(0xD)
/* SOFTHLD Bit Fields */
#define USB_SOFTHLD_CNT_MASK                     0xFFu
#define USB_SOFTHLD_CNT_SHIFT                    0
#define USB_SOFTHLD_CNT(x)                       (((uint8_t)(((uint8_t)(x))<<USB_SOFTHLD_CNT_SHIFT))&USB_SOFTHLD_CNT_MASK)
/* BDTPAGE2 Bit Fields */
#define USB_BDTPAGE2_BDTBA_MASK                  0xFFu
#define USB_BDTPAGE2_BDTBA_SHIFT                 0
#define USB_BDTPAGE2_BDTBA(x)                    (((uint8_t)(((uint8_t)(x))<<USB_BDTPAGE2_BDTBA_SHIFT))&USB_BDTPAGE2_BDTBA_MASK)
/* BDTPAGE3 Bit Fields */
#define USB_BDTPAGE3_BDTBA_MASK                  0xFFu
#define USB_BDTPAGE3_BDTBA_SHIFT                 0
#define USB_BDTPAGE3_BDTBA(x)                    (((uint8_t)(((uint8_t)(x))<<USB_BDTPAGE3_BDTBA_SHIFT))&USB_BDTPAGE3_BDTBA_MASK)
/* ENDPT Bit Fields */
#define USB_ENDPT_EPHSHK_MASK                    0x1u
#define USB_ENDPT_EPHSHK_SHIFT                   0
#define USB_ENDPT_EPSTALL_MASK                   0x2u
#define USB_ENDPT_EPSTALL_SHIFT                  1
#define USB_ENDPT_EPTXEN_MASK                    0x4u
#define USB_ENDPT_EPTXEN_SHIFT                   2
#define USB_ENDPT_EPRXEN_MASK                    0x8u
#define USB_ENDPT_EPRXEN_SHIFT                   3
#define USB_ENDPT_EPCTLDIS_MASK                  0x10u
#define USB_ENDPT_EPCTLDIS_SHIFT                 4
#define USB_ENDPT_RETRYDIS_MASK                  0x40u
#define USB_ENDPT_RETRYDIS_SHIFT                 6
#define USB_ENDPT_HOSTWOHUB_MASK                 0x80u
#define USB_ENDPT_HOSTWOHUB_SHIFT                7
/* USBCTRL Bit Fields */
#define USB_USBCTRL_CLKSRC_MASK                  0x3u
#define USB_USBCTRL_CLKSRC_SHIFT                 0
#define USB_USBCTRL_CLKSRC(x)                    (((uint8_t)(((uint8_t)(x))<<USB_USBCTRL_CLKSRC_SHIFT))&USB_USBCTRL_CLKSRC_MASK)
#define USB_USBCTRL_CLKSRC_ALTCLK                USB_USBCTRL_CLKSRC(0x0)
#define USB_USBCTRL_CLKSRC_OSCCLK                USB_USBCTRL_CLKSRC(0x1)
#define USB_USBCTRL_CLKSRC_SYSCLK                USB_USBCTRL_CLKSRC(0x3)
#define USB_USBCTRL_PDE_MASK                     0x40u
#define USB_USBCTRL_PDE_SHIFT                    6
#define USB_USBCTRL_SUSP_MASK                    0x80u
#define USB_USBCTRL_SUSP_SHIFT                   7
/* OBSERVE Bit Fields */
#define USB_OBSERVE_VBUSDSCHG_MASK               0x2u
#define USB_OBSERVE_VBUSDSCHG_SHIFT              1
#define USB_OBSERVE_VBUSCHG_MASK                 0x4u
#define USB_OBSERVE_VBUSCHG_SHIFT                2
#define USB_OBSERVE_VBUSEN_MASK                  0x8u
#define USB_OBSERVE_VBUSEN_SHIFT                 3
#define USB_OBSERVE_DMPD_MASK                    0x10u
#define USB_OBSERVE_DMPD_SHIFT                   4
#define USB_OBSERVE_DPPD_MASK                    0x40u
#define USB_OBSERVE_DPPD_SHIFT                   6
#define USB_OBSERVE_DPPU_MASK                    0x80u
#define USB_OBSERVE_DPPU_SHIFT                   7
/* CONTROL Bit Fields */
#define USB_CONTROL_SESSEND_MASK                 0x1u
#define USB_CONTROL_SESSEND_SHIFT                0 
#define USB_CONTROL_SESSVLD_MASK                 0x2u
#define USB_CONTROL_SESSVLD_SHIFT                1
#define USB_CONTROL_VBUSVLD_MASK                 0x4u
#define USB_CONTROL_VBUSVLD_SHIFT                2
#define USB_CONTROL_ID_MASK                      0x8u
#define USB_CONTROL_ID_SHIFT                     3
#define MCF5222_USB_CONTROL_VBUSD_MASK           0x10u
#define MCF5222_USB_CONTROL_VBUSD_SHIFT          4
#define USB_CONTROL_DPPULLUPNONOTG_MASK          0x10u
#define USB_CONTROL_DPPULLUPNONOTG_SHIFT         4
/* USBTRC0 Bit Fields */
#define USB_USBTRC0_USB_RESUME_INT_MASK          0x1u
#define USB_USBTRC0_USB_RESUME_INT_SHIFT         0
#define USB_USBTRC0_SYNC_DET_MASK                0x2u
#define USB_USBTRC0_SYNC_DET_SHIFT               1
#define USB_USBTRC0_USBVREN_MASK                 0x4u
#define USB_USBTRC0_USBVREN_SHIFT                2
#define USB_USBTRC0_USBRESMEN_MASK               0x20u
#define USB_USBTRC0_USBRESMEN_SHIFT              5
#define USB_USBTRC0_USBPU_MASK                   0x40u
#define USB_USBTRC0_USBPU_SHIFT                  6
#define USB_USBTRC0_USBRESET_MASK                0x80u
#define USB_USBTRC0_USBRESET_SHIFT               7
/* USB Buffer Descriptor Table Bit Fields */
#define USB_BD_BC(n)                             ((n & 0x3ff) << 16)
#define USB_BD_OWN                               0x80
#define USB_BD_DATA01(n)                         ((n & 1) << 6)
#define USB_BD_DATA0                             USB_BD_DATA01(0)
#define USB_BD_DATA1                             USB_BD_DATA01(1)
#define USB_BD_KEEP                              0x20
#define USB_BD_NINC                              0x10
#define USB_BD_DTS                               0x08
#define USB_BD_STALL                             0x04
#define USB_BD_PID(n)                            ((n & 0x0f) << 2)


/*------------------------------------------------------------------------*/
/*
** USB OTG obsolete memory map
**
** WARNING!!!
** Follwing structure is OBSOLETE. Use USB_MemMap instead!
*/

typedef struct mcf522x_usbotg_struct
{   
    uchar   PER_ID;       // OBSOLETE, use USB_MemMap instead!
    uchar   filler0[3];
    uchar   ID_COMP;      // OBSOLETE, use USB_MemMap instead!
    uchar   filler1[3];
    uchar   REV;          // OBSOLETE, use USB_MemMap instead!
    uchar   filler2[3];
    uchar   ADD_INFO;     // OBSOLETE, use USB_MemMap instead!
    uchar   filler3[3];
    uchar   OTG_INT_STAT; // OBSOLETE, use USB_MemMap instead!
    uchar   filler4[3];
    uchar   OTG_INT_EN;   // OBSOLETE, use USB_MemMap instead!
    uchar   filler5[3];
    uchar   OTG_STATUS;   // OBSOLETE, use USB_MemMap instead!
    uchar   filler6[3];
    uchar   OTG_CTRL;     // OBSOLETE, use USB_MemMap instead!
    uchar   filler7[99];
    uchar   INT_STAT;     // OBSOLETE, use USB_MemMap instead!
    uchar   filler8[3];
    uchar   INT_ENB;      // OBSOLETE, use USB_MemMap instead!
    uchar   filler9[3];
    uchar   ERR_STAT;     // OBSOLETE, use USB_MemMap instead!
    uchar   filler10[3];
    uchar   ERR_ENB;      // OBSOLETE, use USB_MemMap instead!
    uchar   filler11[3];
    uchar   STAT;         // OBSOLETE, use USB_MemMap instead!
    uchar   filler12[3];
    uchar   CTL;          // OBSOLETE, use USB_MemMap instead!
    uchar   filler13[3];
    uchar   ADDR;         // OBSOLETE, use USB_MemMap instead!
    uchar   filler14[3];
    uchar   BDT_PAGE_01;  // OBSOLETE, use USB_MemMap instead!
    uchar   filler15[3];
    uchar   FRM_NUML;     // OBSOLETE, use USB_MemMap instead!
    uchar   filler16[3];
    uchar   FRM_NUMH;     // OBSOLETE, use USB_MemMap instead!
    uchar   filler17[3];
    uchar   TOKEN;        // OBSOLETE, use USB_MemMap instead!
    uchar   filler18[3];
    uchar   SOF_THLD;     // OBSOLETE, use USB_MemMap instead!
    uchar   filler19[3];
    uchar   BDT_PAGE_02;  // OBSOLETE, use USB_MemMap instead!
    uchar   filler20[3];
    uchar   BDT_PAGE_03;  // OBSOLETE, use USB_MemMap instead!
    uchar   filler21[11];
    uchar   ENDPT0;       // OBSOLETE, use USB_MemMap instead!
    uchar   filler22[3];
    uchar   ENDPT1;       // OBSOLETE, use USB_MemMap instead!
    uchar   filler23[3];
    uchar   ENDPT2;       // OBSOLETE, use USB_MemMap instead!
    uchar   filler24[3];
    uchar   ENDPT3;       // OBSOLETE, use USB_MemMap instead!
    uchar   filler25[3];
    uchar   ENDPT4;       // OBSOLETE, use USB_MemMap instead!
    uchar   filler26[3];
    uchar   ENDPT5;       // OBSOLETE, use USB_MemMap instead!
    uchar   filler27[3];
    uchar   ENDPT6;       // OBSOLETE, use USB_MemMap instead!
    uchar   filler28[3];
    uchar   ENDPT7;       // OBSOLETE, use USB_MemMap instead!
    uchar   filler29[3];
    uchar   ENDPT8;       // OBSOLETE, use USB_MemMap instead!
    uchar   filler30[3];
    uchar   ENDPT9;       // OBSOLETE, use USB_MemMap instead!
    uchar   filler31[3];
    uchar   ENDPT10;      // OBSOLETE, use USB_MemMap instead!
    uchar   filler32[3];
    uchar   ENDPT11;      // OBSOLETE, use USB_MemMap instead!
    uchar   filler33[3];
    uchar   ENDPT12;      // OBSOLETE, use USB_MemMap instead!
    uchar   filler34[3];
    uchar   ENDPT13;      // OBSOLETE, use USB_MemMap instead!
    uchar   filler35[3];
    uchar   ENDPT14;      // OBSOLETE, use USB_MemMap instead!
    uchar   filler36[3];
    uchar   ENDPT15;      // OBSOLETE, use USB_MemMap instead!
    uchar   filler37[3];
    uchar   USB_CTRL;     // OBSOLETE, use USB_MemMap instead!
    uchar   filler38[3];
    uchar   USB_OTG_OBSERVE; // OBSOLETE, use USB_MemMap instead!
    uchar   filler39[3];
    uchar   USB_OTG_CONTROL; // OBSOLETE, use USB_MemMap instead!
    uchar   filler40[3];
    uchar   USBTRC0;      // OBSOLETE, use USB_MemMap instead!
    uchar   filler41[3];
    uchar   OTGPIN;       // OBSOLETE, use USB_MemMap instead!
    uchar   filler42[3]; 
} MCF522X_USBOTG_STRUCT, _PTR_ MCF522X_USBOTG_STRUCT_PTR;

/* Bit definitions and macros for PER_ID */
#define MCF522X_USBOTG_PER_ID_ID(x)             (((x)&0x3F)<<0)

/* Bit definitions and macros for ID_COMP */
#define MCF522X_USBOTG_ID_COMP_NID(x)           (((x)&0x3F)<<0)

/* Bit definitions and macros for REV */
#define MCF522X_USBOTG_REV_REV(x)               (((x)&0xFF)<<0)

/* Bit definitions and macros for ADD_INFO */
#define MCF522X_USBOTG_ADD_INFO_IEHOST          (0x1)
#define MCF522X_USBOTG_ADD_INFO_IRQ_NUM(x)      (((x)&0x1F)<<0x3)

/* Bit definitions and macros for OTG_INT_STAT */
#define MCF522X_USBOTG_OTG_INT_STAT_A_VBUS_CHG  (0x1)
#define MCF522X_USBOTG_OTG_INT_STAT_B_SESS_CHG  (0x4)
#define MCF522X_USBOTG_OTG_INT_STAT_SESS_VLD_CHG (0x8)
#define MCF522X_USBOTG_OTG_INT_STAT_LINE_STATE_CHG (0x20)
#define MCF522X_USBOTG_OTG_INT_STAT_1_MSEC      (0x40)
#define MCF522X_USBOTG_OTG_INT_STAT_ID_CHG      (0x80)

/* Bit definitions and macros for OTG_INT_EN */
#define MCF522X_USBOTG_OTG_INT_EN_A_VBUS_EN     (0x1)
#define MCF522X_USBOTG_OTG_INT_EN_B_SESS_EN     (0x4)
#define MCF522X_USBOTG_OTG_INT_EN_SESS_VLD_EN   (0x8)
#define MCF522X_USBOTG_OTG_INT_EN_LINE_STATE_EN (0x20)
#define MCF522X_USBOTG_OTG_INT_EN_1_MSEC_EN     (0x40)
#define MCF522X_USBOTG_OTG_INT_EN_ID_EN         (0x80)

/* Bit definitions and macros for OTG_STAT */
#define MCF522X_USBOTG_OTG_STAT_A_VBUS_VLD      (0x1)
#define MCF522X_USBOTG_OTG_STAT_B_SESS_END      (0x4)
#define MCF522X_USBOTG_OTG_STAT_SESS_VLD        (0x8)
#define MCF522X_USBOTG_OTG_STAT_LINE_STATE_STABLE (0x20)
#define MCF522X_USBOTG_OTG_STAT_1_MSEC_EN       (0x40)
#define MCF522X_USBOTG_OTG_STAT_ID              (0x80)

/* Bit definitions and macros for OTG_CTRL */
#define MCF522X_USBOTG_OTG_CTRL_VBUS_DSCHG      (0x1)
#define MCF522X_USBOTG_OTG_CTRL_VBUS_CHG        (0x2)
#define MCF522X_USBOTG_OTG_CTRL_OTG_EN          (0x4)
#define MCF522X_USBOTG_OTG_CTRL_VBUS_ON         (0x8)
#define MCF522X_USBOTG_OTG_CTRL_DM_LOW          (0x10)
#define MCF522X_USBOTG_OTG_CTRL_DP_LOW          (0x20)
#define MCF522X_USBOTG_OTG_CTRL_DM_HIGH         (0x40)
#define MCF522X_USBOTG_OTG_CTRL_DP_HIGH         (0x80)

/* Bit definitions and macros for INT_STAT */
#define MCF522X_USBOTG_INT_STAT_USB_RST         (0x1)
#define MCF522X_USBOTG_INT_STAT_ERROR           (0x2)
#define MCF522X_USBOTG_INT_STAT_SOF_TOK         (0x4)
#define MCF522X_USBOTG_INT_STAT_TOK_DNE         (0x8)
#define MCF522X_USBOTG_INT_STAT_SLEEP           (0x10)
#define MCF522X_USBOTG_INT_STAT_RESUME          (0x20)
#define MCF522X_USBOTG_INT_STAT_ATTACH          (0x40)
#define MCF522X_USBOTG_INT_STAT_STALL           (0x80)

/* Bit definitions and macros for INT_ENB */
#define MCF522X_USBOTG_INT_ENB_USB_RST_EN       (0x1)
#define MCF522X_USBOTG_INT_ENB_ERROR_EN         (0x2)
#define MCF522X_USBOTG_INT_ENB_SOF_TOK_EN       (0x4)
#define MCF522X_USBOTG_INT_ENB_TOK_DNE_EN       (0x8)
#define MCF522X_USBOTG_INT_ENB_SLEEP_EN         (0x10)
#define MCF522X_USBOTG_INT_ENB_RESUME_EN        (0x20)
#define MCF522X_USBOTG_INT_ENB_ATTACH_EN        (0x40)
#define MCF522X_USBOTG_INT_ENB_STALL_EN         (0x80)

/* Bit definitions and macros for ERR_STAT */
#define MCF522X_USBOTG_ERR_STAT_PID_ERR         (0x1)
#define MCF522X_USBOTG_ERR_STAT_CRC5_EOF        (0x2)
#define MCF522X_USBOTG_ERR_STAT_CRC16           (0x4)
#define MCF522X_USBOTG_ERR_STAT_DFN8            (0x8)
#define MCF522X_USBOTG_ERR_STAT_BTO_ERR         (0x10)
#define MCF522X_USBOTG_ERR_STAT_DMA_ERR         (0x20)
#define MCF522X_USBOTG_ERR_STAT_BTS_ERR         (0x80)

/* Bit definitions and macros for ERR_ENB */
#define MCF522X_USBOTG_ERR_ENB_PID_ERR_EN       (0x1)
#define MCF522X_USBOTG_ERR_ENB_CRC5_EOF_EN      (0x2)
#define MCF522X_USBOTG_ERR_ENB_CRC16_EN         (0x4)
#define MCF522X_USBOTG_ERR_ENB_DFN8_EN          (0x8)
#define MCF522X_USBOTG_ERR_ENB_BTO_ERR_EN       (0x10)
#define MCF522X_USBOTG_ERR_ENB_DMA_ERR_EN       (0x20)
#define MCF522X_USBOTG_ERR_ENB_BTS_ERR_EN       (0x80)

/* Bit definitions and macros for STAT */
#define MCF522X_USBOTG_STAT_ODD                 (0x4)
#define MCF522X_USBOTG_STAT_TX                  (0x8)
#define MCF522X_USBOTG_STAT_ENDP(x)             (((x)&0xF)<<0x4)

/* Bit definitions and macros for OTG_CTL */
#define MCF522X_USBOTG_CTL_USB_EN_SOF_EN        (0x1)
#define MCF522X_USBOTG_CTL_ODD_RST              (0x2)
#define MCF522X_USBOTG_CTL_RESUME               (0x4)
#define MCF522X_USBOTG_CTL_HOST_MODE_EN         (0x8)
#define MCF522X_USBOTG_CTL_RESET                (0x10)
#define MCF522X_USBOTG_CTL_TXSUSPEND_TOKENBUSY  (0x20)
#define MCF522X_USBOTG_CTL_SE0                  (0x40)
#define MCF522X_USBOTG_CTL_JSTATE               (0x80)

/* Bit definitions and macros for ADDR */
#define MCF522X_USBOTG_ADDR_ADDR(x)             (((x)&0x7F)<<0)
#define MCF522X_USBOTG_ADDR_LS_EN               (0x80)

/* Bit definitions and macros for BDT_PAGE_01 */
#define MCF522X_USBOTG_BDT_PAGE_01_BDT_BA9      (0x2)
#define MCF522X_USBOTG_BDT_PAGE_01_BDT_BA10     (0x4)
#define MCF522X_USBOTG_BDT_PAGE_01_BDT_BA11     (0x8)
#define MCF522X_USBOTG_BDT_PAGE_01_BDT_BA12     (0x10)
#define MCF522X_USBOTG_BDT_PAGE_01_BDT_BA13     (0x20)
#define MCF522X_USBOTG_BDT_PAGE_01_BDT_BA14     (0x40)
#define MCF522X_USBOTG_BDT_PAGE_01_BDT_BA15     (0x80)

/* Bit definitions and macros for FRM_NUML */
#define MCF522X_USBOTG_FRM_NUML_FRM0            (0x1)
#define MCF522X_USBOTG_FRM_NUML_FRM1            (0x2)
#define MCF522X_USBOTG_FRM_NUML_FRM2            (0x4)
#define MCF522X_USBOTG_FRM_NUML_FRM3            (0x8)
#define MCF522X_USBOTG_FRM_NUML_FRM4            (0x10)
#define MCF522X_USBOTG_FRM_NUML_FRM5            (0x20)
#define MCF522X_USBOTG_FRM_NUML_FRM6            (0x40)
#define MCF522X_USBOTG_FRM_NUML_FRM7            (0x80)

/* Bit definitions and macros for FRM_NUMH */
#define MCF522X_USBOTG_FRM_NUMH_FRM8            (0x1)
#define MCF522X_USBOTG_FRM_NUMH_FRM9            (0x2)
#define MCF522X_USBOTG_FRM_NUMH_FRM10           (0x4)

/* Bit definitions and macros for TOKEN */
#define MCF522X_USBOTG_TOKEN_TOKEN_ENDPT(x)     (((x)&0xF)<<0)
#define MCF522X_USBOTG_TOKEN_TOKEN_PID(x)       (((x)&0xF)<<0x4)
#define MCF522X_USBOTG_TOKEN_TOKEN_PID_OUT      (0x10)
#define MCF522X_USBOTG_TOKEN_TOKEN_PID_IN       (0x90)
#define MCF522X_USBOTG_TOKEN_TOKEN_PID_SETUP    (0xD0)

/* Bit definitions and macros for SOF_THLD */
#define MCF522X_USBOTG_SOF_THLD_CNT0            (0x1)
#define MCF522X_USBOTG_SOF_THLD_CNT1            (0x2)
#define MCF522X_USBOTG_SOF_THLD_CNT2            (0x4)
#define MCF522X_USBOTG_SOF_THLD_CNT3            (0x8)
#define MCF522X_USBOTG_SOF_THLD_CNT4            (0x10)
#define MCF522X_USBOTG_SOF_THLD_CNT5            (0x20)
#define MCF522X_USBOTG_SOF_THLD_CNT6            (0x40)
#define MCF522X_USBOTG_SOF_THLD_CNT7            (0x80)

/* Bit definitions and macros for BDT_PAGE_02 */
#define MCF522X_USBOTG_BDT_PAGE_02_BDT_BA16     (0x1)
#define MCF522X_USBOTG_BDT_PAGE_02_BDT_BA17     (0x2)
#define MCF522X_USBOTG_BDT_PAGE_02_BDT_BA18     (0x4)
#define MCF522X_USBOTG_BDT_PAGE_02_BDT_BA19     (0x8)
#define MCF522X_USBOTG_BDT_PAGE_02_BDT_BA20     (0x10)
#define MCF522X_USBOTG_BDT_PAGE_02_BDT_BA21     (0x20)
#define MCF522X_USBOTG_BDT_PAGE_02_BDT_BA22     (0x40)
#define MCF522X_USBOTG_BDT_PAGE_02_BDT_BA23     (0x80)

/* Bit definitions and macros for BDT_PAGE_03 */
#define MCF522X_USBOTG_BDT_PAGE_03_BDT_BA24     (0x1)
#define MCF522X_USBOTG_BDT_PAGE_03_BDT_BA25     (0x2)
#define MCF522X_USBOTG_BDT_PAGE_03_BDT_BA26     (0x4)
#define MCF522X_USBOTG_BDT_PAGE_03_BDT_BA27     (0x8)
#define MCF522X_USBOTG_BDT_PAGE_03_BDT_BA28     (0x10)
#define MCF522X_USBOTG_BDT_PAGE_03_BDT_BA29     (0x20)
#define MCF522X_USBOTG_BDT_PAGE_03_BDT_BA30     (0x40)
#define MCF522X_USBOTG_BDT_PAGE_03_BDT_BA31     (0x80)

/* Bit definitions and macros for ENDPT */
#define MCF522X_USBOTG_ENDPT_EP_HSHK            (0x1)
#define MCF522X_USBOTG_ENDPT_EP_STALL           (0x2)
#define MCF522X_USBOTG_ENDPT_EP_TX_EN           (0x4)
#define MCF522X_USBOTG_ENDPT_EP_RX_EN           (0x8)
#define MCF522X_USBOTG_ENDPT_EP_CTL_DIS         (0x10)
#define MCF522X_USBOTG_ENDPT_RETRY_DIS          (0x40)
#define MCF522X_USBOTG_ENDPT_HOST_WO_HUB        (0x80)

/* Bit definitions and macros for USB_CTRL */
#define MCF522X_USBOTG_USB_CTRL_CLK_SRC(x)      (((x)&0x3)<<0)
#define MCF522X_USBOTG_USB_CTRL_CLK_SRC_ALTCLK  (0)
#define MCF522X_USBOTG_USB_CTRL_CLK_SRC_OSCCLK  (0x1)
#define MCF522X_USBOTG_USB_CTRL_CLK_SRC_SYSCLK  (0x3)
#define MCF522X_USBOTG_USB_CTRL_PDE             (0x40)
#define MCF522X_USBOTG_USB_CTRL_SUSP            (0x80)

/* Bit definitions and macros for OTG_OBSERVE */
#define MCF522X_USBOTG_USB_OTG_OBSERVE_VBUSDIS  (0x2)
#define MCF522X_USBOTG_USB_OTG_OBSERVE_VBUSCHG  (0x4)
#define MCF522X_USBOTG_USB_OTG_OBSERVE_VBUSE    (0x8)
#define MCF522X_USBOTG_USB_OTG_OBSERVE_DM_PD    (0x10)
#define MCF522X_USBOTG_USB_OTG_OBSERVE_DP_PD    (0x40)
#define MCF522X_USBOTG_USB_OTG_OBSERVE_DP_PU    (0x80)

/* Bit definitions and macros for OTG_CONTROL */
#define MCF522X_USBOTG_USB_OTG_CONTROL_SESSEND  (0x1)
#define MCF522X_USBOTG_USB_OTG_CONTROL_SESSVLD  (0x2)
#define MCF522X_USBOTG_USB_OTG_CONTROL_VBUSVLD  (0x4)
#define MCF522X_USBOTG_USB_OTG_CONTROL_ID       (0x8)
#define MCF522X_USBOTG_USB_OTG_CONTROL_VBUSD    (0x10)

/* Bit definitons and macros for USB buffer descriptor */
#define MCF522X_USBOTG_BD_BC(n)                 ((n & 0x3ff) << 16)
#define MCF522X_USBOTG_BD_OWN                   0x80
#define MCF522X_USBOTG_BD_DATA01(n)             ((n & 1) << 6)
#define MCF522X_USBOTG_BD_DATA0                 MCF522X_USBOTG_BD_DATA01(0)
#define MCF522X_USBOTG_BD_DATA1                 MCF522X_USBOTG_BD_DATA01(1)
#define MCF522X_USBOTG_BD_KEEP                  0x20
#define MCF522X_USBOTG_BD_NINC                  0x10
#define MCF522X_USBOTG_BD_DTS                   0x08
#define MCF522X_USBOTG_BD_STALL                 0x04

#define MCF522X_USBOTG_BD_PID(n)                ((n & 0x0f) << 2)

#ifdef __cplusplus
}
#endif


#endif
