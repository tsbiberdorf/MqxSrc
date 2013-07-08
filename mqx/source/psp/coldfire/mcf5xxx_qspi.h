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
* $FileName: mcf5xxx_qspi.h$
* $Version : 3.7.5.0$
* $Date    : Feb-7-2011$
*
* Comments:
*
*   This file contains the type definitions for the mcf5xxx QSPI module.
*
*END************************************************************************/

#ifndef __mcf5xxx_qspi_h__
#define __mcf5xxx_qspi_h__

#define __mcf5xxx_qspi_h__version "$Version:3.7.5.0$"
#define __mcf5xxx_qspi_h__date    "$Date:Feb-7-2011$"

#ifdef __cplusplus
extern "C" {
#endif


/*------------------------------------------------------------------------*/
/*
** QSPI  registers bit set.
*/

/* Bit definitions and macros for MCF5XXX_QSPI_QMR */
#define MCF5XXX_QSPI_QMR_BAUD(x)                 (((x)&0xFF)<<0)
#define MCF5XXX_QSPI_QMR_CPHA                    (0x100)
#define MCF5XXX_QSPI_QMR_CPOL                    (0x200)
#define MCF5XXX_QSPI_QMR_BITS_GET(reg)           (((reg)>>0xA)&0xF)
#define MCF5XXX_QSPI_QMR_BITS_SET(val)           (((val)&0xF)<<0xA)
#define MCF5XXX_QSPI_QMR_DOHIE                   (0x4000)
#define MCF5XXX_QSPI_QMR_MSTR                    (0x8000)

/* Bit definitions and macros for MCF5XXX_QSPI_QDLYR */
#define MCF5XXX_QSPI_QDLYR_DTL(x)                (((x)&0xFF)<<0)
#define MCF5XXX_QSPI_QDLYR_QCD(x)                (((x)&0x7F)<<0x8)
#define MCF5XXX_QSPI_QDLYR_SPE                   (0x8000)

/* Bit definitions and macros for MCF5XXX_QSPI_QWR */
#define MCF5XXX_QSPI_QWR_NEWQP(x)                (((x)&0xF)<<0)
#define MCF5XXX_QSPI_QWR_CPTQP(x)                (((x)&0xF)<<0x4)
#define MCF5XXX_QSPI_QWR_ENDQP(x)                (((x)&0xF)<<0x8)
#define MCF5XXX_QSPI_QWR_CSIV                    (0x1000)
#define MCF5XXX_QSPI_QWR_WRTO                    (0x2000)
#define MCF5XXX_QSPI_QWR_WREN                    (0x4000)
#define MCF5XXX_QSPI_QWR_HALT                    (0x8000)

/* Bit definitions and macros for MCF5XXX_QSPI_QIR */
#define MCF5XXX_QSPI_QIR_SPIF                    (0x1)
#define MCF5XXX_QSPI_QIR_ABRT                    (0x4)
#define MCF5XXX_QSPI_QIR_WCEF                    (0x8)
#define MCF5XXX_QSPI_QIR_SPIFE                   (0x100)
#define MCF5XXX_QSPI_QIR_ABRTE                   (0x400)
#define MCF5XXX_QSPI_QIR_WCEFE                   (0x800)
#define MCF5XXX_QSPI_QIR_ABRTL                   (0x1000)
#define MCF5XXX_QSPI_QIR_ABRTB                   (0x4000)
#define MCF5XXX_QSPI_QIR_WCEFB                   (0x8000)

/* Bit definitions and macros for MCF5XXX_QSPI_QAR */
#define MCF5XXX_QSPI_QAR_ADDR(x)                 (((x)&0x3F)<<0)
#define MCF5XXX_QSPI_QAR_TRANS                   (0)
#define MCF5XXX_QSPI_QAR_RECV                    (0x10)
#define MCF5XXX_QSPI_QAR_CMD                     (0x20)

/* Bit definitions and macros for MCF5XXX_QSPI_QDR */
#define MCF5XXX_QSPI_QDR_DATA(x)                 (((x)&0xFFFF)<<0)
#define MCF5XXX_QSPI_QDR_CONT                    (0x8000)
#define MCF5XXX_QSPI_QDR_BITSE                   (0x4000)
#define MCF5XXX_QSPI_QDR_DT                      (0x2000)
#define MCF5XXX_QSPI_QDR_DSCK                    (0x1000)
#define MCF5XXX_QSPI_QDR_CS(x)                   (((x)&0x0F)<<8)
#define MCF5XXX_QSPI_QDR_QSPI_CS3                (0x08)
#define MCF5XXX_QSPI_QDR_QSPI_CS2                (0x04)
#define MCF5XXX_QSPI_QDR_QSPI_CS1                (0x02)
#define MCF5XXX_QSPI_QDR_QSPI_CS0                (0x01)

/*
** MCF5XXX_QSPI_STRUCT
** QSPI
*/
typedef struct mcf5xxx_qspi_struct
{
   uint_16  QMR;            /* QSPI mode register */
   uint_16  filler1;
   uint_16  QDLYR;          /* QSPI delay register */
   uint_16  filler2;
   uint_16  QWR;            /* QSPI wrap register */
   uint_16  filler3;
   uint_16  QIR;            /* QSPI interrupt register */
   uint_16  filler4;
   uint_16  QAR;            /* QSPI address register */
   uint_16  filler5;
   uint_16  QDR;            /* QSPI data register */
   uchar    filler6[42];
} MCF5XXX_QSPI_STRUCT, _PTR_ MCF5XXX_QSPI_STRUCT_PTR;
typedef volatile struct mcf5xxx_qspi_struct _PTR_ VMCF5XXX_QSPI_STRUCT_PTR;

#ifdef __cplusplus
}
#endif

#endif

