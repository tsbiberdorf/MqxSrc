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
* $FileName: int_unx.c$
* $Version : 3.5.3.0$
* $Date    : Feb-24-2010$
*
* Comments:
*
*   This file contains the function for the unexpected
*   exception handling function for MQX, which will display on the
*   console what exception has ocurred.
*   NOTE: the default I/O for the current task is used, since a printf
*   is being done from an ISR.
*   This default I/O must NOT be an interrupt drive I/O channel.
*
*END************************************************************************/

#include "mqx_inc.h"
#include "fio.h"
#include "psp.h"

/*!
 * \brief An MQX-provided default ISR for unhandled interrupts. The function
 * depends on the PSP.
 *
 * The function changes the state of the active task to UNHANDLED_INT_BLOCKED and
 * blocks the task.
 * \n The function uses the default I/O channel to display at least:
 * \li Vector number that caused the unhandled exception.
 * \li Task ID and task descriptor of the active task.
 *
 * \n Depending on the PSP, more information might be displayed.
 *
 * \param[in] parameter Parameter passed to the default ISR.
 *
 * \note
 * Since the ISR uses printf() to display information to the default I/O channel,
 * default I/O must not be on a channel that uses interrupt-driven I/O or the
 * debugger.
 * \warning Blocks the active task.
 *
 * \see _int_install_unexpected_isr
 */
void _int_unexpected_isr
   (
      pointer parameter
   )
{ /* Body */
   volatile KERNEL_DATA_STRUCT _PTR_ kernel_data;
   volatile TD_STRUCT _PTR_          td_ptr;

   printf("\n\r*** UNHANDLED INTERRUPT ***\n\r");
   _psp_dump_context(parameter);

   _GET_KERNEL_DATA(kernel_data);
   td_ptr = kernel_data->ACTIVE_PTR;

   _INT_DISABLE();
   if (td_ptr->STATE != UNHANDLED_INT_BLOCKED) {
      td_ptr->STATE = UNHANDLED_INT_BLOCKED;
      td_ptr->INFO  = (_mqx_uint)parameter;

      _QUEUE_UNLINK(td_ptr);
   } /* Endif */
   _INT_ENABLE();

} /* Endbody */

/* EOF */
