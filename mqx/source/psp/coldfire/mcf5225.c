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
* $FileName: mcf5225.c$
* $Version : 3.6.6.0$
* $Date    : Aug-31-2010$
*
* Comments:
*
*   This file contains utiltity functions for use with a mcf5225x.
*
*END************************************************************************/

#include "mqx_inc.h"
#include "mcf5225.h"


/* Copies of control registers */
volatile uint_32 _psp_saved_cacr = 0;
volatile uint_32 _psp_saved_mbar = 0x40000000;

/*
** Define padding needed to make the STOREBLOCK_STRUCT align properly
** to cache line size (see mem_prv.h)
*/
// No cache on 5225x, so don't need to align to cache line
//#define PSP_MEM_STOREBLOCK_ALIGNMENT   (2) /* padding in _mqx_uints */


#define NYI()

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : _mcf5225_initialize_support
* Returned Value   : none
* Comments         :
*  Initilize the support functions for the mcf5225
*
*END*------------------------------------------------------------------------*/

void _mcf5225_initialize_support
   (
      /* [IN] dummy parameter */
      uint_32 param
   )
{ /* Body */
#if PSP_HAS_SUPPORT_STRUCT
   KERNEL_DATA_STRUCT_PTR kernel_data;

   _GET_KERNEL_DATA(kernel_data);

   kernel_data->PSP_SUPPORT_PTR = _mem_alloc_system_zero((uint_32)sizeof(PSP_SUPPORT_STRUCT));
   _mem_set_type(kernel_data->PSP_SUPPORT_PTR, MEM_TYPE_PSP_SUPPORT_STRUCT);
#endif
} /* Endbody */

/* EOF */
