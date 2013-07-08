/**HEADER********************************************************************
*
* Copyright (c) 2012 Freescale Semiconductor;
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
* $FileName: vybrid.h$
* $Version : 3.8.9.0$
* $Date    : Sep-24-2012$
*
* Comments:
*
*   This file contains the type definitions for the i.MX microcontrollers.
*
*END************************************************************************/

#ifndef __vybrid_h__
#define __vybrid_h__

#define _vybrid_h_version "$Version:3.8.9.0$"
#define _vybrid_h_date    "$Date:Sep-24-2012$"

/**************************************************************************
 TEMPORARY CPU HEADERS
**************************************************************************/
#ifndef __ASM__
#include <stdint.h>

#if (MQX_CPU == PSP_CPU_VF65GS10_A5) || (MQX_CPU == PSP_CPU_VF65GS10_M4)
    #include "MVF50GS10MK50.h"

	#if PSP_MQX_CPU_IS_VYBRID_A5
	#include <gic.h>
	#else
	#include <nvic.h>
	#endif

	#include <irouter_vybrid.h>
#else
    #error "Ooooo, too new cpu..."
#endif

#endif // __ASM__


/*
*******************************************************************************
**
**                  CONSTANT DEFINITIONS
**
*******************************************************************************
*/
#define PSP_NUM_CORES                   2
#define SEMA4_NUM_DEVICES               1

#if (MQX_CPU == PSP_CPU_VF65GS10_A5)
	#ifndef PSP_HAS_MMU
	#define PSP_HAS_MMU                 1
	#endif

	#ifndef PSP_HAS_L1_CACHE
    #define PSP_HAS_L1_CACHE            1
	#endif

	#ifndef PSP_HAS_L2_CACHE
    #define PSP_HAS_L2_CACHE            1
	#endif

    #ifndef PSP_HAS_CODE_CACHE
    #define PSP_HAS_CODE_CACHE          1
    #endif

    #ifndef PSP_HAS_DATA_CACHE
    #define PSP_HAS_DATA_CACHE          1
    #endif

    #ifndef PSP_HAS_FPU
    #define PSP_HAS_FPU          		1
    #endif
#elif (MQX_CPU == PSP_CPU_VF65GS10_M4)
    #ifndef PSP_HAS_CODE_CACHE
    #define PSP_HAS_CODE_CACHE          1
    #endif

    #ifndef PSP_HAS_DATA_CACHE
    #define PSP_HAS_DATA_CACHE          1
    #endif

    #ifndef PSP_HAS_FPU
    #define PSP_HAS_FPU          		1
    #endif
#endif

#if 0

/* Cache and MMU definition values */
#ifndef PSP_HAS_MMU
#define PSP_HAS_MMU                     0
#endif

#ifndef PSP_HAS_L1_CACHE
#define PSP_HAS_L1_CACHE                0
#endif

#ifndef PSP_HAS_L2_CACHE
#define PSP_HAS_L2_CACHE                0
#endif

#ifndef PSP_HAS_CODE_CACHE
#define PSP_HAS_CODE_CACHE              0
#endif

#ifndef PSP_HAS_DATA_CACHE
#define PSP_HAS_DATA_CACHE              0
#endif

#ifndef PSP_HAS_FPU
#define PSP_HAS_FPU          			0
#endif

#endif

#ifndef __ASM__

/* Standard cache macros */
#if PSP_HAS_DATA_CACHE
#define _DCACHE_ENABLE(n)               _dcache_enable()
#define _DCACHE_DISABLE()               _dcache_disable()
#define _DCACHE_FLUSH()                 _dcache_flush()
#define _DCACHE_FLUSH_LINE(p)           _dcache_flush_line(p)
#define _DCACHE_FLUSH_MLINES(p, m)      _dcache_flush_mlines(p,m)
#define _DCACHE_INVALIDATE()            _dcache_invalidate()
#define _DCACHE_INVALIDATE_LINE(p)      _dcache_invalidate_line(p)
#define _DCACHE_INVALIDATE_MLINES(p, m) _dcache_invalidate_mlines(p, m)

#define _DCACHE_FLUSH_MBYTES(p, m)      _DCACHE_FLUSH_MLINES(p, m)
#define _DCACHE_INVALIDATE_MBYTES(p, m) _DCACHE_INVALIDATE_MLINES(p, m)

#else
#define _DCACHE_ENABLE(n)
#define _DCACHE_DISABLE()
#define _DCACHE_FLUSH()
#define _DCACHE_FLUSH_LINE(p)
#define _DCACHE_FLUSH_MLINES(p, m)
#define _DCACHE_INVALIDATE()
#define _DCACHE_INVALIDATE_LINE(p)
#define _DCACHE_INVALIDATE_MLINES(p, m)

#define _DCACHE_FLUSH_MBYTES(p, m)
#define _DCACHE_INVALIDATE_MBYTES(p, m)
#endif

#if PSP_HAS_CODE_CACHE
#define _ICACHE_ENABLE(n)                   _icache_enable()
#define _ICACHE_DISABLE()                   _icache_disable()
#define _ICACHE_INVALIDATE()                _icache_invalidate()
#define _ICACHE_INVALIDATE_LINE(p)          _icache_invalidate_line(p)
#define _ICACHE_INVALIDATE_MLINES(p, m)     _icache_invalidate_mlines(p, m)
#else
#define _ICACHE_ENABLE(n)
#define _ICACHE_DISABLE()
#define _ICACHE_FLUSH()
#define _ICACHE_FLUSH_LINE(p)
#define _ICACHE_FLUSH_MLINES(p, m)
#define _ICACHE_INVALIDATE()
#define _ICACHE_INVALIDATE_LINE(p)
#define _ICACHE_INVALIDATE_MLINES(p, m)
#endif

#define reg32_write(addr,val) *((unsigned long*)(addr)) = (val)


typedef uint_32 PSP_INTERRUPT_TABLE_INDEX;
typedef void (*vector_entry)(void);

/** GICD */
typedef struct GICD_MemMap {
    uint32_t CTLR;
    uint32_t TYPER;
    uint32_t IIDR;
    uint32_t rsvd0[29];
    uint32_t IGROUPR[32];
    uint32_t ISENABLER[32];
    uint32_t ICENABLER[32];
    uint32_t ISPENDR[32];
    uint32_t ICPENDR[32];

    uint32_t ISACTIVER[32];
    uint32_t ICACTIVER[32];
    uint32_t IPRIORITYR[255];
    uint32_t ITARGETSR[255];
    uint32_t ICFGR[64];
    uint32_t NSACR[64];
    uint32_t SGIR;
    uint32_t rsvd1[3];
    uint32_t CPENDSGIR[4];
    uint32_t SPENDSGIR[4];
} volatile *GICD_MemMapPtr;

#define GICD_BASE_PTR                   ((GICD_MemMapPtr)0x40003000)


#define GICD_CTLR_REG(base)             ((base)->CTLR)
#define GICD_IGROUPR_REG(base, idx)     ((base)->IGROUPR[idx])
#define GICD_ISENABLER_REG(base, idx)   ((base)->ISENABLER[idx])
#define GICD_ICENABLER_REG(base, idx)   ((base)->ICENABLER[idx])
#define GICD_ICPENDR_REG(base, idx)     ((base)->ICPENDR[idx])
#define GICD_IPRIORITYR_REG(base, idx)     ((base)->IPRIORITYR[idx])
#define GICD_ITARGETSR_REG(base, idx)     ((base)->ITARGETSR[idx])

#define GICD_CTLR                       GICD_CTLR_REG(GICD_BASE_PTR)
#define GICD_IGROUPR(idx)               GICD_IGROUPR_REG(GICD_BASE_PTR, (idx))
#define GICD_ISENABLER(idx)             GICD_ISENABLER_REG(GICD_BASE_PTR, (idx))
#define GICD_ICENABLER(idx)             GICD_ICENABLER_REG(GICD_BASE_PTR, (idx))
#define GICD_ICPENDR(idx)               GICD_ICPENDR_REG(GICD_BASE_PTR, (idx))
#define GICD_IPRIORITYR(idx)            GICD_IPRIORITYR_REG(GICD_BASE_PTR, (idx))
#define GICD_ITARGETSR(idx)             GICD_ITARGETSR_REG(GICD_BASE_PTR, (idx))

/** GICC */
typedef struct GICC_MemMap {
    uint32_t CTLR;
    uint32_t PMR;
    uint32_t BPR;
    uint32_t IAR;
    uint32_t EOIR;
    uint32_t RPR;
    uint32_t HPPIR;
    uint32_t ABPR;
    uint32_t AIAR;
    uint32_t AEOIR;
    uint32_t AHPPIR;
    uint32_t rsvd0[41];
    uint32_t APR[3];
    uint32_t NSAPR[3];
    uint32_t rsvd1[4];
    uint32_t IIDR;
    uint32_t DIR;
} volatile *GICC_MemMapPtr;

#define GICC_BASE_PTR           ((GICC_MemMapPtr)0x40002100)


#define GICC_CTLR_REG(base)     ((base)->CTLR)
#define GICC_PMR_REG(base)      ((base)->PMR)


#define GICC_CTLR               GICC_CTLR_REG(GICC_BASE_PTR)
#define GICC_PMR                GICC_PMR_REG(GICC_BASE_PTR)



/** GICC */
typedef struct GT_MemMap {
    uint32_t CNTRL;
    uint32_t CNTRH;
    uint32_t CONTR;
    uint32_t IS;
    uint32_t CVRL;
    uint32_t CVRH;
    uint32_t AIR;
} volatile *GT_MemMapPtr;

#define GT_BASE_PTR             ((GT_MemMapPtr)0x40002200)

#define GT_CNTRL_REG(base)      ((base)->CNTRL)
#define GT_CNTRH_REG(base)      ((base)->CNTRH)
#define GT_CONTR_REG(base)      ((base)->CONTR)
#define GT_IS_REG(base)         ((base)->IS)
#define GT_CVRL_REG(base)       ((base)->CVRL)
#define GT_CVRH_REG(base)       ((base)->CVRH)
#define GT_AIR_REG(base)        ((base)->AIR)

#define GT_CNTRL                GT_CNTRL_REG(GT_BASE_PTR)
#define GT_CNTRH                GT_CNTRH_REG(GT_BASE_PTR)
#define GT_CONTR                GT_CONTR_REG(GT_BASE_PTR)
#define GT_IS                   GT_IS_REG(GT_BASE_PTR)
#define GT_CVRL                 GT_CVRL_REG(GT_BASE_PTR)
#define GT_CVRH                 GT_CVRH_REG(GT_BASE_PTR)
#define GT_AIR                  GT_AIR_REG(GT_BASE_PTR)
/* SW_MUX_CTL_PAD_PAD Bit Fields */

#define IOMUXC_SW_MUX_CTL_PAD_PAD_IBE_MASK       0x1u
#define IOMUXC_SW_MUX_CTL_PAD_PAD_IBE_SHIFT      0
#define IOMUXC_SW_MUX_CTL_PAD_PAD_IBE(x)         (((uint32_t)(((uint32_t)(x))<<IOMUXC_SW_MUX_CTL_PAD_PAD_IBE_SHIFT))&IOMUXC_SW_MUX_CTL_PAD_PAD_IBE_MASK)
#define IOMUXC_SW_MUX_CTL_PAD_PAD_OBE_MASK       0x2u
#define IOMUXC_SW_MUX_CTL_PAD_PAD_OBE_SHIFT      1
#define IOMUXC_SW_MUX_CTL_PAD_PAD_OBE(x)         (((uint32_t)(((uint32_t)(x))<<IOMUXC_SW_MUX_CTL_PAD_PAD_OBE_SHIFT))&IOMUXC_SW_MUX_CTL_PAD_PAD_OBE_MASK)
#define IOMUXC_SW_MUX_CTL_PAD_PAD_PUE_MASK       0x4u
#define IOMUXC_SW_MUX_CTL_PAD_PAD_PUE_SHIFT      2
#define IOMUXC_SW_MUX_CTL_PAD_PAD_PUE(x)         (((uint32_t)(((uint32_t)(x))<<IOMUXC_SW_MUX_CTL_PAD_PAD_PUE_SHIFT))&IOMUXC_SW_MUX_CTL_PAD_PAD_PUE_MASK)
#define IOMUXC_SW_MUX_CTL_PAD_PAD_PKE_MASK       0x8u
#define IOMUXC_SW_MUX_CTL_PAD_PAD_PKE_SHIFT      3
#define IOMUXC_SW_MUX_CTL_PAD_PAD_PKE(x)         (((uint32_t)(((uint32_t)(x))<<IOMUXC_SW_MUX_CTL_PAD_PAD_PKE_SHIFT))&IOMUXC_SW_MUX_CTL_PAD_PAD_PKE_MASK)
#define IOMUXC_SW_MUX_CTL_PAD_PAD_PUS_MASK       0x30u
#define IOMUXC_SW_MUX_CTL_PAD_PAD_PUS_SHIFT      4
#define IOMUXC_SW_MUX_CTL_PAD_PAD_PUS(x)         (((uint32_t)(((uint32_t)(x))<<IOMUXC_SW_MUX_CTL_PAD_PAD_PUS_SHIFT))&IOMUXC_SW_MUX_CTL_PAD_PAD_PUS_MASK)
#define IOMUXC_SW_MUX_CTL_PAD_PAD_DSE_MASK       0x1C0u
#define IOMUXC_SW_MUX_CTL_PAD_PAD_DSE_SHIFT      6
#define IOMUXC_SW_MUX_CTL_PAD_PAD_DSE(x)         (((uint32_t)(((uint32_t)(x))<<IOMUXC_SW_MUX_CTL_PAD_PAD_DSE_SHIFT))&IOMUXC_SW_MUX_CTL_PAD_PAD_DSE_MASK)
#define IOMUXC_SW_MUX_CTL_PAD_PAD_HYS_MASK       0x200u
#define IOMUXC_SW_MUX_CTL_PAD_PAD_HYS_SHIFT      9
#define IOMUXC_SW_MUX_CTL_PAD_PAD_HYS(x)         (((uint32_t)(((uint32_t)(x))<<IOMUXC_SW_MUX_CTL_PAD_PAD_HYS_SHIFT))&IOMUXC_SW_MUX_CTL_PAD_PAD_HYS_MASK)
#define IOMUXC_SW_MUX_CTL_PAD_PAD_ODE_MASK       0x400u
#define IOMUXC_SW_MUX_CTL_PAD_PAD_ODE_SHIFT      10
#define IOMUXC_SW_MUX_CTL_PAD_ODE(x)             (((uint32_t)(((uint32_t)(x))<<IOMUXC_SW_MUX_CTL_PAD_PAD_ODE_SHIFT))&IOMUXC_SW_MUX_CTL_PAD_PAD_ODE_MASK)
#define IOMUXC_SW_MUX_CTL_PAD_PAD_SRE_MASK       0x800u
#define IOMUXC_SW_MUX_CTL_PAD_PAD_SRE_SHIFT      11
#define IOMUXC_SW_MUX_CTL_PAD_PAD_SRE(x)         (((uint32_t)(((uint32_t)(x))<<IOMUXC_SW_MUX_CTL_PAD_PAD_SRE_SHIFT))&IOMUXC_SW_MUX_CTL_PAD_PAD_SRE_MASK)
#define IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED_MASK     0x3000u
#define IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED_SHIFT    12
#define IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED(x)       (((uint32_t)(((uint32_t)(x))<<IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED_SHIFT))&IOMUXC_SW_MUX_CTL_PAD_PAD_SPEED_MASK)
#define IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE_MASK  0x700000u
#define IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE_SHIFT 20
#define IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE(x)    (((uint32_t)(((uint32_t)(x))<<IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE_SHIFT))&IOMUXC_SW_MUX_CTL_PAD_PAD_MUX_MODE_MASK)



#define IOMUXC_SW_MUX_CTL_PAD_DDR_PUE_MASK 0x4u
#define IOMUXC_SW_MUX_CTL_PAD_DDR_PUE_SHIFT 2
#define IOMUXC_SW_MUX_CTL_PAD_DDR_PKE_MASK 0x8u
#define IOMUXC_SW_MUX_CTL_PAD_DDR_PKE_SHIFT 3
#define IOMUXC_SW_MUX_CTL_PAD_DDR_PUS_MASK 0x30u
#define IOMUXC_SW_MUX_CTL_PAD_DDR_PUS_SHIFT 4
#define IOMUXC_SW_MUX_CTL_PAD_DDR_PUS(x)  (((uint32_t)(((uint32_t)(x))<<IOMUXC_SW_MUX_CTL_PAD_DDR_PUS_SHIFT))&IOMUXC_SW_MUX_CTL_PAD_DDR_PUS_MASK)
#define IOMUXC_SW_MUX_CTL_PAD_DDR_DSE_MASK 0x1C0u
#define IOMUXC_SW_MUX_CTL_PAD_DDR_DSE_SHIFT 6
#define IOMUXC_SW_MUX_CTL_PAD_DDR_DSE(x)  (((uint32_t)(((uint32_t)(x))<<IOMUXC_SW_MUX_CTL_PAD_DDR_DSE_SHIFT))&IOMUXC_SW_MUX_CTL_PAD_DDR_DSE_MASK)
#define IOMUXC_SW_MUX_CTL_PAD_DDR_HYS_MASK 0x200u
#define IOMUXC_SW_MUX_CTL_PAD_DDR_HYS_SHIFT 9
#define IOMUXC_SW_MUX_CTL_PAD_DDR_TRIM_MASK 0xC000u
#define IOMUXC_SW_MUX_CTL_PAD_DDR_TRIM_SHIFT 14
#define IOMUXC_SW_MUX_CTL_PAD_DDR_TRIM(x) (((uint32_t)(((uint32_t)(x))<<IOMUXC_SW_MUX_CTL_PAD_DDR_TRIM_SHIFT))&IOMUXC_SW_MUX_CTL_PAD_DDR_TRIM_MASK)
#define IOMUXC_SW_MUX_CTL_PAD_DDR_INPUT_MASK 0x10000u
#define IOMUXC_SW_MUX_CTL_PAD_DDR_INPUT_SHIFT 16
#define IOMUXC_SW_MUX_CTL_PAD_DDR_INPUT(x) (((uint32_t)(((uint32_t)(x))<<IOMUXC_SW_MUX_CTL_PAD_DDR_INPUT_SHIFT))&IOMUXC_SW_MUX_CTL_PAD_DDR_INPUT_MASK)


#endif // __ASM__
/**************************************************************************
**************************************************************************/

/*------------------------------------------------------------------------*/
/*
**                    CONSTANT DEFINITIONS
*/

/* A5 L1 and L2 caches, M4 cache have 32-byte lines. */
#define PSP_CACHE_LINE_SIZE          32
#define PSP_CACHE_LINE_ALIGNMENT    (-PSP_CACHE_LINE_SIZE)

#ifndef __ASM__



/*------------------------------------------------------------------------*/
/*
**                      TYPE DEFINITIONS
*/


/*
** PSP_SUPPORT_STRUCT
** This structure is used to maintain the PSP support information
*/

#if PSP_HAS_SUPPORT_STRUCT

typedef struct psp_support_struct
{
   /* Where in memory the page tables start */
   uint_32     PAGE_TABLE_BASE;

   uint_32     PAGE_TABLE_SIZE;
   uint_32     PAGE_TABLE_USED;
   uint_32     MMU_DEFAULT_ATTRIBUTE;


   /* Vector Base register */
   uint_32                   VBR;
} PSP_SUPPORT_STRUCT, _PTR_ PSP_SUPPORT_STRUCT_PTR;
#endif

/*------------------------------------------------------------------------*/
/*
**                      FUNCTION PROTOTYPES AND GLOBAL EXTERNS
*/

#ifdef __cplusplus
extern "C" {
#endif

#if PSP_HAS_SUPPORT_STRUCT
void _a5_initialize_support(void);
void _psp_set_support_ptr(PSP_SUPPORT_STRUCT_PTR psp_sup_ptr);
extern PSP_SUPPORT_STRUCT_PTR   _psp_get_support_ptr(void);
#endif
/* PSP Cache prototypes */
void _dcache_enable(void);
void _dcache_disable(void);
void _dcache_flush(void);
void _dcache_flush_line(pointer);
void _dcache_flush_mlines(pointer, uint_32);
void _dcache_invalidate(void);
void _dcache_invalidate_line(pointer);
void _dcache_invalidate_mlines(pointer, uint_32);

void _icache_enable(void);
void _icache_disable(void);
void _icache_flush(void);
void _icache_flush_line(pointer);
void _icache_flush_mlines(pointer, uint_32);
void _icache_invalidate(void);
void _icache_invalidate_line(pointer);
void _icache_invalidate_mlines(pointer, uint_32);

#ifdef __cplusplus
}
#endif

#endif /* __ASM__ */

#endif // __vybrid_h__
