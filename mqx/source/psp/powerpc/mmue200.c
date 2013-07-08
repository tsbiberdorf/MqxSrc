/**HEADER********************************************************************
*
* Copyright (c) 20011 Freescale Semiconductor;
* All Rights Reserved
*
* Copyright (c) 2011 Embedded Access Inc.;
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
* $FileName: mmue200.c$
* $Version : 3.8.1.0$
* $Date    : Oct-5-2011$
*
* Comments:
*
*   This file contains MMU utiltity functions for use with the e200
*   CPUs.
*
*END************************************************************************/

#include "mqx_inc.h"

/*FUNCTION*-----------------------------------------------------------------
*
* Function Name   : _mmu_init
* Returned Value  : void
* Comments        :
*   Initialize the mmu
*
*END*---------------------------------------------------------------------*/

void _mmu_init
   (
      /* [IN] dummy value */
      pointer dummy
   )
{
    PSP_SUPPORT_STRUCT_PTR psp_support_ptr = _psp_get_support_ptr();
    uint_32 i;
    for (i=0;i<E200CORE_MMU_NUM_TLBS/32;i++) {
        psp_support_ptr->TLB_ALLOC[i] =0;
    }
    psp_support_ptr->NUM_TLB_FREE = E200CORE_MMU_NUM_TLBS;
}



/*FUNCTION*-----------------------------------------------------------------
*
* Function Name   : _mmu_enable
* Returned Value  : void
* Comments        :
*   Enable the operation of the mmu - not supported
*
*END*---------------------------------------------------------------------*/

void _mmu_enable( void )
{

}

/*FUNCTION*-----------------------------------------------------------------
*
* Function Name   : _mmu_disable
* Returned Value  : void
* Comments        :
*   Disable the operation of the mmu - not supported
*
*END*---------------------------------------------------------------------*/

void _mmu_disable( void )
{
}


/*FUNCTION*-----------------------------------------------------------------
*
* Function Name   : _mmu_get_min_page_alignment
* Returned Value  : void
* Comments        :
*   returns the smallest page size needed
*
*END*---------------------------------------------------------------------*/

static uint_32 _mmu_get_min_page_alignment(uint_32 value)
{
    uint_32 i, mask =1;
    for (i=0;i<32;i++) {
        if (mask & value) {
            return mask;
        }
        mask <<= 1;
    }
    return 0x80000000; // 2G alignment, the max we allow
}

/*FUNCTION*-----------------------------------------------------------------
*
* Function Name   : _mmu_get_max_page_alignment
* Returned Value  : void
* Comments        :
*   returns the largest page size needed
*
*END*---------------------------------------------------------------------*/
static uint_32 _mmu_get_max_page_alignment(uint_32 value)
{
    uint_32 i, mask =0x80000000;
    for (i=0;i<32;i++) {
        if (mask & value) {
            return mask;
        }
        mask >>= 1;
    }
    return 0;
}


/*FUNCTION*-----------------------------------------------------------------
*
* Function Name   : _mmu_reserve_tlb
* Returned Value  : void
* Comments        :
*   Marks a TLB as being used. This is used to inform MQX of TLBs already
*   programmed by boot code.
*
*END*---------------------------------------------------------------------*/

void _mmu_reserve_tlb(uint_32 tlb_no)
{
    PSP_SUPPORT_STRUCT_PTR psp_support_ptr = _psp_get_support_ptr();
   uint_32 index, mask;

    index = tlb_no>>5;
    if (tlb_no<E200CORE_MMU_NUM_TLBS){
        mask = 1<<(tlb_no&0x1f);
        if ((mask & psp_support_ptr->TLB_ALLOC[index])==0) {
            psp_support_ptr->TLB_ALLOC[index] |= mask;
            psp_support_ptr->NUM_TLB_FREE--;
        }
    }
}


/*FUNCTION*-----------------------------------------------------------------
*
* Function Name   : _mmu_alloc_tlb
* Returned Value  : void
* Comments        :
*    Finds and allocates an unused TLB.
*
*END*---------------------------------------------------------------------*/

static uint_32 _mmu_alloc_tlb(PSP_SUPPORT_STRUCT_PTR psp_support_ptr)
{
    uint_32 i,j, mask;
    for (i=0;i<E200CORE_MMU_NUM_TLBS/32;i++) {
        mask = 1;
        for (j=0;j<32;j++) {
            if ((mask & psp_support_ptr->TLB_ALLOC[i])==0) {
                psp_support_ptr->TLB_ALLOC[i] |= mask;
                psp_support_ptr->NUM_TLB_FREE--;
                return i*32+j;
            }
            mask <<= 1;
        }
    }
    return E200CORE_MMU_NUM_TLBS;
}

/*FUNCTION*-----------------------------------------------------------------
*
* Function Name   : _mmu_free_tlb
* Returned Value  : void
* Comments        :
*    Frees a TLB. NOTE: TLB should be invalidated before it is freed.
*
*END*---------------------------------------------------------------------*/

static boolean _mmu_free_tlb(PSP_SUPPORT_STRUCT_PTR psp_support_ptr, uint_32 tlb_no)
{
    uint_32 index, mask;

    index = tlb_no>>5;
    if (tlb_no<E200CORE_MMU_NUM_TLBS){
        mask = 1<<(tlb_no&0x1f);
        if ((mask & psp_support_ptr->TLB_ALLOC[index])!=0) {
            psp_support_ptr->TLB_ALLOC[index] &= ~mask;
            psp_support_ptr->NUM_TLB_FREE++;
            return TRUE;
        }
    }
    return FALSE;
}


/*FUNCTION*-----------------------------------------------------------------
*
* Function Name   : _mmu_write_table_entry
* Returned Value  : void
* Comments        :
*    Writes a TLB entry to the MMU.
*
*END*---------------------------------------------------------------------*/
__asm void _mmu_write_table_entry( uint_32 mas0,  uint_32 mas1, uint_32 mas2, uint_32 mas3)
{
 //   fralloc

    /* Write MMU Assist Register 0 (MAS0); SPR 624 */
    mtspr   spr624, r3
    /* Write MMU Assist Register 1 (MAS1); SPR 625 */
    mtspr   spr625, r4
    /* Write MMU Assist Register 2 (MAS2); SPR 626 */
    mtspr   spr626, r5
    /* Write MMU Assist Register 3 (MAS3); SPR 627 */
    mtspr   spr627, r6
    /* Write the table entry */
    tlbwe

//    frfree
    blr
}


/*FUNCTION*-----------------------------------------------------------------
*
* Function Name   : _mmu_page_size_to_tsize
* Returned Value  : void
* Comments        :
*    Converts a page size i bytes to tsize, where page_size = 2^tsize*1K
*
*END*---------------------------------------------------------------------*/
static uint_32 _mmu_page_size_to_tsize( uint_32 page_size)
{
    uint_32 mask, i;

    mask=1024;
    for (i=0;i<22;i++) {
        if (page_size & mask) {
            return i;
        }
        mask <<= 1;
    }
}


/*FUNCTION*-----------------------------------------------------------------
*
* Function Name   : _mmu_release_tlb
* Returned Value  : void
* Comments        :
*   Releases a TLB that was allocated by the Boot code. This invalidates the
*   TLB, then marks it free.
*
*END*---------------------------------------------------------------------*/


void _mmu_release_tlb(uint_32 tlb_no)
{
    PSP_SUPPORT_STRUCT_PTR psp_support_ptr = _psp_get_support_ptr();
   uint_32 index, mask;

    index = tlb_no>>5;
    if (tlb_no<E200CORE_MMU_NUM_TLBS){
        mask = 1<<(tlb_no&0x1f);
        if (mask & psp_support_ptr->TLB_ALLOC[index]) {
            _mmu_write_table_entry(E200CORE_MAS0_TLBSEL_TLB1|E200CORE_TLB_NUM(tlb_no),0,0,0);
            _mmu_free_tlb(psp_support_ptr,tlb_no);
            //return TRUE;
        }
    }
   // return FALSE;
}

/*FUNCTION*-----------------------------------------------------------------
*
* Function Name   : _mmu_add_virtual_region
* Returned Value  : MQX_OK or an error code
* Comments        :
*  Adds a virtual region. An extension of _mmu_add_region, this allows P->V
*  translation, as well as specifying a PID for the MMU entries.
*
*END*---------------------------------------------------------------------*/

_mqx_uint _mmu_add_virtual_region
   (
      /* [IN] the starting location of the memory block */
      uchar_ptr phys_mem_ptr,

      /* [IN] the starting location of the memory block */
      uchar_ptr virt_mem_ptr,

      /* [IN] the size of the memory block */
      _mem_size input_size,

      /* [IN] flags indicating what type of memory this is */
      _mqx_uint flags,

      _mqx_uint tid
   )
{
   PSP_SUPPORT_STRUCT_PTR psp_support_ptr = _psp_get_support_ptr();
   int_32                 size;
   uint_32                vmem_addr, pmem_addr;
   uint_32                i,size_page_size, addr_page_size, phys_page_size, next_page_size,num_pages=0;
   uint_32                page_sizes[E200CORE_MMU_NUM_TLBS];
   uint_32                tlb_no, tsize, mas0, mas1, mas2, mas3, mas1_flags, mas2_flags, mas3_flags;

   if (psp_support_ptr == NULL) {
      return(MQX_COMPONENT_DOES_NOT_EXIST);
   }

   size = (int_32)input_size;
   vmem_addr = (uint_32) virt_mem_ptr;
   pmem_addr = (uint_32) phys_mem_ptr;
   size_page_size = _mmu_get_min_page_alignment(size);
   addr_page_size = _mmu_get_min_page_alignment(vmem_addr);
   phys_page_size = _mmu_get_min_page_alignment(pmem_addr);


   if (size_page_size < E200CORE_MMU_MIN_PAGE_SIZE) {
       return MQX_INVALID_SIZE;
   }
   if (addr_page_size < E200CORE_MMU_MIN_PAGE_SIZE) {
       return MQX_INVALID_POINTER;
   }
   if ((phys_page_size<addr_page_size) && (phys_page_size<size_page_size)) {
       return MQX_INVALID_POINTER;
   }

   if (flags & (PSP_MMU_WRITE_BUFFERED|PSP_MMU_WRITE_NO_UPDATE)) {
       return MQX_INVALID_PARAMETER;
   }

   while (size > 0) {
       addr_page_size = _mmu_get_min_page_alignment(vmem_addr);
       if (addr_page_size<=size) {
           // either mem_ptr not aligned to size, we need to use a smaller page size than size,
           // or, they are both aligned to exactly the same size
           page_sizes[num_pages] = addr_page_size;
       } else {
           // Page ptr is aligned to an area greater than size. Use the largest page size we can
           page_sizes[num_pages] = _mmu_get_max_page_alignment(size);
       }
       size -= page_sizes[num_pages];
       vmem_addr += page_sizes[num_pages];
       num_pages++;
   }

   if (num_pages>psp_support_ptr->NUM_TLB_FREE) {
       return MQX_OUT_OF_MEMORY;
   }

   mas1_flags = E200CORE_TLB_VALID|E200CORE_TLB_TID(tid);
   mas2_flags = 0;
   mas3_flags = 0;
   if (flags & PSP_MMU_CACHE_INHIBITED) {
       mas2_flags |= E200CORE_MMU_CACHE_INHIBIT;
   }
   if (flags & PSP_MMU_CODE_CACHE_INHIBITED) {
       mas2_flags |= E200CORE_MMU_CACHE_INHIBIT;
   }
   if (flags & PSP_MMU_COHERENT) {
       mas2_flags |= E200CORE_MMU_CACHE_COHERENT;
   }
   if (flags & PSP_MMU_DATA_CACHE_INHIBITED) {
       mas2_flags |= E200CORE_MMU_CACHE_INHIBIT;
   }
   if (flags & PSP_MMU_GUARDED) {
       mas2_flags |= E200CORE_MMU_CACHE_GUARDED;
   }
   if (flags & PSP_MMU_PAGE_LOCKED) {
       mas1_flags |= E200CORE_TLB_IPROT;
   }
   if (flags & PSP_MMU_WRITE_THROUGH) {
       mas2_flags |= E200CORE_MMU_CACHE_WRITE_THRU;
   }
   if (flags & PSP_MMU_PAGE_VLE) {
       mas2_flags |= E200CORE_MMU_VLE;
   }

   if (flags & PSP_MMU_EXEC_ALLOWED) {
       mas3_flags |= E200CORE_TLB_UX|E200CORE_TLB_SX;
   }
   if ((flags & PSP_MMU_READ_PROTECTED)==0) {
       mas3_flags |= E200CORE_TLB_UR|E200CORE_TLB_SR;
   }
   if ((flags & PSP_MMU_WRITE_PROTECTED)==0) {
       mas3_flags |= E200CORE_TLB_UW|E200CORE_TLB_SW;
   }

   size = (int_32)input_size;
   vmem_addr = (uint_32)virt_mem_ptr;

   for (i=0;i<num_pages;i++) {
       tlb_no = _mmu_alloc_tlb(psp_support_ptr);
       mas0 = E200CORE_MAS0_TLBSEL_TLB1|E200CORE_TLB_NUM(tlb_no);
       mas1 = mas1_flags | E200CORE_TLB_BLOCK_SIZE(_mmu_page_size_to_tsize(page_sizes[i]));
       mas2 = (vmem_addr & E200CORE_TLB_PAGE_MASK) | mas2_flags;
       mas3 = (pmem_addr & E200CORE_TLB_PAGE_MASK) | mas3_flags;
       _mmu_write_table_entry(mas0,mas1,mas2,mas3);
       vmem_addr += page_sizes[i];
       pmem_addr += page_sizes[i];
   }

   return(MQX_OK);

}



/*FUNCTION*-----------------------------------------------------------------
*
* Function Name   : _mmu_add_region
* Returned Value  : MQX_OK or an error code
* Comments        :
*   Adds a global "flat" (P=V) region to the MMU
*
*END*---------------------------------------------------------------------*/

_mqx_uint _mmu_add_region
   (
      /* [IN] the starting location of the memory block */
      uchar_ptr phys_mem_ptr,

       /* [IN] the size of the memory block */
      _mem_size input_size,

      /* [IN] flags indicating what type of memory this is */
      _mqx_uint flags
   )
{
    return _mmu_add_virtual_region(phys_mem_ptr,phys_mem_ptr,input_size,flags,0);
}


/* EOF */
