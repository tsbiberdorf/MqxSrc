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
* $FileName: mcf52xx_i2c.h$
* $Version : 3.5.3.0$
* $Date    : Nov-26-2009$
*
* Comments:
*
*   This file contains the type definitions for the mcf52xx I2C module.
*
*END************************************************************************/

#ifndef __mcf52xx_i2c_h__
#define __mcf52xx_i2c_h__

#define __mcf52xx_i2c_h__version "$Version:3.5.3.0$"
#define __mcf52xx_i2c_h__date    "$Date:Nov-26-2009$"

#ifdef __cplusplus
extern "C" {
#endif


/*------------------------------------------------------------------------*/
/*
** I2C registers
*/

/* Bit definitions and macros for MCF52XX_I2C_I2ADR */
#define MCF52XX_I2C_I2ADR_ADR(x)                 (((x)&0x7F)<<0x1)

/* Bit definitions and macros for MCF52XX_I2C_I2FDR */
#define MCF52XX_I2C_I2FDR_IC(x)                  (((x)&0x3F)<<0)

/* Bit definitions and macros for MCF52XX_I2C_I2CR */
#define MCF52XX_I2C_I2CR_RSTA                    (0x4)
#define MCF52XX_I2C_I2CR_TXAK                    (0x8)
#define MCF52XX_I2C_I2CR_MTX                     (0x10)
#define MCF52XX_I2C_I2CR_MSTA                    (0x20)
#define MCF52XX_I2C_I2CR_IIEN                    (0x40)
#define MCF52XX_I2C_I2CR_IEN                     (0x80)

/* Bit definitions and macros for MCF52XX_I2C_I2SR */
#define MCF52XX_I2C_I2SR_RXAK                    (0x1)
#define MCF52XX_I2C_I2SR_IIF                     (0x2)
#define MCF52XX_I2C_I2SR_SRW                     (0x4)
#define MCF52XX_I2C_I2SR_IAL                     (0x10)
#define MCF52XX_I2C_I2SR_IBB                     (0x20)
#define MCF52XX_I2C_I2SR_IAAS                    (0x40)
#define MCF52XX_I2C_I2SR_ICF                     (0x80)


/*------------------------------------------------------------------------*/

/*
** MCF52XX_I2C_STRUCT
** This structure defines what one i2c register look like
*/

typedef struct mcf52xx_i2c_struct
{
   uchar    I2ADR;          // I2C address register
   uchar    filler1[3];
   uchar    I2FDR;          // I2C frequency divider register
   uchar    filler2[3];
   uchar    I2CR;           // I2C control register
   uchar    filler3[3];
   uchar    I2SR;           // I2C status register
   uchar    filler4[3];
   uchar    I2DR;           // I2C data I/O register
   uchar    filler5[47];
} MCF52XX_I2C_STRUCT, _PTR_ MCF52XX_I2C_STRUCT_PTR;
typedef volatile struct mcf52xx_i2c_struct _PTR_ VMCF52XX_I2C_STRUCT_PTR;

#ifdef __cplusplus
}
#endif

#endif  //__mcf52xx_i2c_h__
