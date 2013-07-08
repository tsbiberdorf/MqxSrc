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
* $FileName: int_vtab.c$
* $Version : 3.8.5.0$
* $Date    : Jun-7-2012$
*
* Comments:
*
*   This file contains the functions used to access the vector
*   table locations.
*
*END************************************************************************/

#include "mqx_inc.h"

/*!
 * \brief Changes the location of the interrupt vector table.
 * 
 * \param[in] new Address of the new interrupt vector table.
 * 
 * \return Address of the previous vector table.
 * 
 * \warning Behavior depends on the BSP and the PSP.
 * 
 * \see _int_get_vector_table
 * \see _int_get_previous_vector_table
 */
_mqx_max_type _int_set_vector_table
   (
      _mqx_max_type new
   )
{ /* Body */

   #if defined(PSP_PPC401) || defined(PSP_PPC403) || defined(PSP_PPC405) || \
       defined(PSP_IOP480)

      return (_mqx_max_type)_PSP_SET_VECTOR_TABLE((uint_32)new);

   #else
      return 0;
   #endif

} /* Endbody */

/*!
 * \brief Gets the address of the current interrupt vector table. The function 
 * depends on the PSP.
 * 
 * \return Address of the current interrupt vector table.
 * \return 0 (failure) 
 * 
 * \see _int_set_vector_table
 * \see _int_get_previous_vector_table
 */  
_mqx_max_type _int_get_vector_table
   (
      void
   )
{ /* Body */

   #if defined(PSP_PPC401) || defined(PSP_PPC403) || defined(PSP_PPC405) || \
       defined(PSP_IOP480)

      return (_mqx_max_type)_PSP_GET_VECTOR_TABLE();

   #else
      uint_32 tmp;
      
      _PSP_MSR_GET(tmp);
      if (tmp & PSP_MSR_IP) {
         return 0xFFF00000;
      } else {
         return 0;
      }/* Endif */
   #endif
   
} /* Endbody */

/* EOF */
