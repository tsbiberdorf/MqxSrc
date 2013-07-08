/**HEADER********************************************************************
*
* Copyright (c) 2008 Freescale Semiconductor;
* All Rights Reserved
*
* Copyright (c) 2004-2008 Embedded Access Inc.;
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
* $FileName: mpxsxx.h$
* $Version : 3.8.2.0$
* $Date    : Sep-17-2012$
*
* Comments:
*
*   This file contains the type definitions for the Freescale PowerPC
*   PX  processor family.
*
*END***********************************************************************/

#ifndef __mpxsxx_h__
#define __mpxsxx_h__

#include <e200core.h>

/*--------------------------------------------------------------------------*/
/*
**                         DATATYPE DECLARATIONS
*/

#ifndef __ASM__

typedef struct psp_virtual_context_struct
   /* This structure is used to store the virtual context for a task.
   ** The address of this structure is kept in the task extensions struct.
   */
{

   /* What blocks of memory are assigned to this task */
   QUEUE_STRUCT       PAGE_INFO;

} PSP_VIRTUAL_CONTEXT_STRUCT, _PTR_ PSP_VIRTUAL_CONTEXT_STRUCT_PTR;


typedef struct psp_pte_struct
   /* This structure is used to store the PageTableEntry */
{
   uint_32  UPPER_PTE;
   uint_32  LOWER_PTE;
} PSP_PTE_STRUCT, _PTR_ PSP_PTE_STRUCT_PTR;


typedef struct psp_page_info_struct
   /* This structure is used to store memory block information
   ** for use with the virtual memory MMU support
   */
{
   /* Queue header */
   QUEUE_ELEMENT_STRUCT ELEMENT;

   /* Physical Memory location */
   uchar_ptr            ADDR;

   /* Virtual Memory location */
   uchar_ptr            VADDR;

   /* page table entry struct */
   PSP_PTE_STRUCT       PTE;

   /* page table entry address in the table */
   PSP_PTE_STRUCT_PTR   PTE_PTR;


} PSP_PAGE_INFO_STRUCT, _PTR_ PSP_PAGE_INFO_STRUCT_PTR;


/* This structure is used to maintain the PSP support information */
typedef struct psp_support_struct
{
   /* Count if the number of TLBs currently free */
   uint_32                    NUM_TLB_FREE;

   uint_32                    TLB_ALLOC[E200CORE_MMU_NUM_TLBS/32];

   /* Address of unused space for cache flushing */
   pointer                    FLUSH_AREA;

   /* Instruction and/or data MMU enable */
   uint_32                    MSR_MMU_ENABLE_BITS;

   /* Count if the number of TLB locked (at end of TLB list) */
   uint_32                    LOCKED_TLB_START;

   /* last memory location for mmu pages */
   uint_32_ptr                MMU_PAGE_TABLE_BASE;

   /* Memory block of MMU mem ptrs */
   PSP_PAGE_INFO_STRUCT_PTR   MMU_PAGE_INFO_BASE;

   /* A queue of available unmapped memory blocks */
   QUEUE_STRUCT               VPAGE_FREELIST;

   /* A light weight semaphore to protect the memory queue */
   LWSEM_STRUCT               VPAGE_FREELIST_LWSEM;

   /* A light weight semaphore to protect the mmu pages */
   LWSEM_STRUCT               MMU_LWSEM;

   pointer                    MMU_L1_BASE;
   pointer                    END_MMU_PAGE_PTR;
   uchar_ptr                  CURRENT_MMU_PAGE_PTR;
   uint_32                    PAGE_SIZE;

   pointer                    MMU_SHORT_TLB_PAGE_PTR;
   uchar_ptr                  CURRENT_SHORT_TLB_PTR;

} PSP_SUPPORT_STRUCT, _PTR_ PSP_SUPPORT_STRUCT_PTR;


/*----------------------------------------------------------------------*/
/*
**                    FUNCTION PROTOTYPES
*/

#ifdef __cplusplus
extern "C" {
#endif

pointer _psp_core_peripheral_address(uint_32 config, pointer address);
boolean _psp_core_peripheral_enabled(uint_32 config);

void _mpxsxx_initialize_support(void);

#ifdef __cplusplus
}
#endif

#endif //__ASM__

#endif
