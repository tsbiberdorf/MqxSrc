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
* $FileName: int_gkis.c$
* $Version : 3.5.3.0$
* $Date    : Feb-24-2010$
*
* Comments:
*
*   This file contains the functions for returning the kernel 
*   isr for an interrupt.
*
*END************************************************************************/

#include "mqx_inc.h"

#if defined( PSP_BOOKE ) || defined( PSP_BOOKE_VLE) 
/* Pass it off to the bsp */
extern INT_KERNEL_ISR_FPTR _bsp_int_get_kernel_isr(_mqx_uint);
#endif

/*!
 * \brief Gets a pointer to the kernel ISR for the specified vector number. The 
 * kernel ISR depends on the PSP.
 *  
 * \param[in] vector Vector number whose kernel ISR is requested.
 * 
 * \return Pointer to the kernel ISR (Success.)
 * \return NULL   
 * 
 * \warning On failure, calls _task_set_error() to set the task error code:
 * \li MQX_INVALID_VECTORED_INTERRUPT 
 * 
 * \see _int_kernel_isr
 * \see _int_install_kernel_isr
 */
INT_KERNEL_ISR_FPTR _int_get_kernel_isr
(
      _mqx_uint int_vector
)
{ /* Body */

#if MQX_CHECK_ERRORS
   if ( int_vector >= PSP_MAXIMUM_INTERRUPT_VECTORS ) {
      _task_set_error(MQX_INVALID_VECTORED_INTERRUPT);
      return NULL;
   } /* Endif */
#endif

#if defined (PSP_BOOKE) || defined( PSP_BOOKE_VLE) 

   return _bsp_int_get_kernel_isr(int_vector);

#else   /* !PSP_BOOKE (Original exception model) */

   #ifdef PSP_MPC566
   return (INT_KERNEL_ISR_FPTR)(_int_get_vector_table() + (int_vector * 0x100));
   #else
   return (INT_KERNEL_ISR_FPTR)(int_vector * 0x100);
   #endif
   
#endif /* PSP_BOOKE */

} /* Endbody */

/* EOF */
