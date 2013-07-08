/**HEADER********************************************************************
*
* Copyright (c) 2008-2012 Freescale Semiconductor;
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
* $FileName: comp.c$
* $Version : 3.8.2.0$
* $Date    : Oct-3-2012$
*
* Comments:
*
*   This file contains runtime support for the RV Compiler.
*
*END************************************************************************/

#include "mqx.h"


void __user_setup_stackheap(void);
int __aeabi_atexit(pointer, pointer, pointer);

pointer malloc(_mem_size);
pointer calloc(_mem_size, _mem_size);
void    free(pointer);


/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : __user_setup_stackheap
* Returned Value   : void
* Comments         :
*   To create a version of __user_setup_stackheap()
*   that inherits sp from the execution environment
*   and does not have a heap, set r0 and r2 to zero and return.
*
*END*----------------------------------------------------------------------*/

__asm void __user_setup_stackheap(void)
{
    mov r0, #0
    mov r2, #0
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : __aeabi_atexit
* Returned Value   : int
* Comments         :
*   Override C/C++ runtime __aeabi_atexit function in KEIL
*   to avoid the call to malloc and free before MQX starts
*   http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.faqs/ka3951.html
*
*END*----------------------------------------------------------------------*/
int __aeabi_atexit(pointer object_ptr, pointer destructor_ptr, pointer __dso_handle_ptr)
{
    return (1);
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : malloc
* Returned Value   : pointer
* Comments         :
*   Override C/C++ runtime heap allocation function in KEIL
*
*END*----------------------------------------------------------------------*/

pointer malloc(_mem_size bytes)
{
    return _mem_alloc_system(bytes);
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : calloc
* Returned Value   : pointer
* Comments         :
*   Override C/C++ runtime heap allocation function in KEIL
*
*END*----------------------------------------------------------------------*/

pointer calloc(_mem_size n, _mem_size z)
{
    return _mem_alloc_system_zero(n*z);
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : free
* Returned Value   : void
* Comments         :
*   Override C/C++ runtime heap deallocation function in KEIL
*
*END*----------------------------------------------------------------------*/

void free(pointer p)
{
    _mem_free(p);
}

/* EOF */
