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
* $FileName: cortexa5.h$
* $Version : 3.8.7.0$
* $Date    : Oct-2-2012$
*
* Comments:
* Vybrid interrupt router
*
*END************************************************************************/

#include "irouter_vybrid.h"

/*FUNCTION*-----------------------------------------------------------------
*
* Function Name   : _irouter_routing
* Returned Value  : _mqx_uint
*       MQX_OK or error code
* Comments        :
*  	Initerrupt routing for shared interrupts
*
*END*---------------------------------------------------------------------*/
_mqx_uint _irouter_routing
    (
        // [IN] Interrupt number
        _mqx_uint irq,

        // [IN] core number
        _mqx_uint core,

        // [IN] enable - set/clear
        boolean enable
    )
{
    _mqx_uint ext_irq_no = irq - PSP_INT_FIRST_INT_ROUTER;

    if (irq >= PSP_INT_FIRST_INT_ROUTER && irq <= PSP_INT_LAST_INTERNAL) {
        if (enable) {
            MSCM_IRSPRC(irq - PSP_INT_FIRST_INT_ROUTER) |= core;
        }
        else {
            MSCM_IRSPRC(irq - PSP_INT_FIRST_INT_ROUTER) &= ~core;
        }
    }

    return MQX_OK;
}
