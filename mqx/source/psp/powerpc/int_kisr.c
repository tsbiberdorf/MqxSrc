/*HEADER*********************************************************************
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
* $FileName: int_kisr.c$
* $Version : 3.8.4.0$
* $Date    : Sep-20-2011$
*
* Comments:
*
*   This file contains the function for installing a kernel level isr.
*
*END************************************************************************/

#include "mqx_inc.h"

/*!
 * \brief Installs the kernel ISR handler. The kernel ISR depends on the PSP.
 * 
 * Some real-time applications need special event handling to occur outside the 
 * scope of MQX. The need might arise that the latency in servicing an interrupt 
 * be less than the MQX interrupt latency. If this is the case, an application can
 * use _int_install_kernel_isr() to bypass MQX and let the interrupt be serviced
 * immediately.
 * \n Because the function returns the previous kernel ISR, applications can 
 * temporarily install an ISR or chain ISRs so that each new one calls the one
 * installed before it.
 * \n A kernel ISR must save the registers that it needs and must service the 
 * hardware interrupt. When the kernel ISR is finished, it must restore the 
 * registers and perform a return-from-interrupt instruction.
 * \n A kernel ISR cannot call MQX functions. However, it can put data in global 
 * data, which a task can access.
 * 
 * \note The function is not available for all PSPs.
 *  
 * \param[in] vector  Vector where the ISR is to be installed.
 * \param[in] isr_ptr Pointer to the ISR to install into the vector table.
 * 
 * \return Pointer to the previous kernel ISR for the vector (Success.).
 * \return NULL     
 * 
 * \see _int_kernel_isr
 * \see _int_get_kernel_isr
 */ 
INT_KERNEL_ISR_FPTR _int_install_kernel_isr
(  
      _mqx_uint           int_vector,
      INT_KERNEL_ISR_FPTR isr_ptr
)
{ /* Body */
#if !MQX_ROM_VECTORS
   _KLOGM(KERNEL_DATA_STRUCT_PTR kernel_data;)
   uint_32                       result  = MQX_OK;
   pointer                       loc;

   _KLOGM(_GET_KERNEL_DATA(kernel_data);)
   _KLOGE3(KLOG_int_install_kernel_isr, int_vector, isr_ptr);
   

  
#if MQX_CHECK_ERRORS
   loc = NULL;

   if ( int_vector >= PSP_MAXIMUM_INTERRUPT_VECTORS ) {
      result = MQX_INVALID_VECTORED_INTERRUPT;
      /* Set result code and return result. */
      _task_set_error(result);
   } else {
#endif

   #ifdef PSP_MPC566
     loc = (pointer)(_int_get_vector_table() + (int_vector * 0x100));
   #else
     loc = (pointer)(int_vector * 0x100);
   #endif

   _int_disable();
   _mem_copy((pointer)isr_ptr, loc, 0x100);

#if PSP_HAS_DATA_CACHE
   _dcache_flush_mlines(loc, 0x100);
#endif 

#if PSP_HAS_CODE_CACHE
   _icache_invalidate_mlines(loc, 0x100);
#endif   
   _int_enable();

#if MQX_CHECK_ERRORS
   } /* Endif */
#endif

   _KLOGX3(KLOG_int_install_kernel_isr, loc, result);

   return (INT_KERNEL_ISR_FPTR)(loc);
#else
    
#if MQX_CHECK_ERRORS
   /* Set result code and return result. */
   _task_set_error(MQX_INVALID_CONFIGURATION);
#endif

   return NULL;
#endif


} /* Endbody */

/* EOF */
