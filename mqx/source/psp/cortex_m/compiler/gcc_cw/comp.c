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
*   This file contains runtime support for the CodeWarrior GCC.
*
*END************************************************************************/

#include "mqx.h"


/* CodeWarrior init function prototypes */
void __init_hardware(void);
void __init_registers(void);


pointer malloc(_mem_size);
pointer calloc(_mem_size, _mem_size);
void    free(pointer);
int     _exit(int);


extern void init_hardware(void);

#if MQX_ENABLE_CPP || BSPCFG_ENABLE_CPP
extern void __fini_cpp(void);
extern void __destroy_global_chain(void);
#endif /* MQX_ENABLE_CPP || BSPCFG_ENABLE_CPP */


/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : __init_hardware
* Returned Value   : void
* Comments         :
*   Function __init_hardware() overloads its default instance in EWL Runtime library.
*   It calls function init_hardware() which initializes CPU registers .
*
*END*----------------------------------------------------------------------*/

void __init_hardware(void)
{
    /* Initialize device. */
    init_hardware();
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : __init_registers
* Returned Value   : void
* Comments         :
*   Empty function __init_registers() overloads its default instance
*   in EWL Runtime library. Registers are already initialized in __boot
*
*END*----------------------------------------------------------------------*/
void __init_registers(void)
{
    /* this is an empty function */
}

/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : malloc
* Returned Value   : pointer
* Comments         :
*   Override C/C++ runtime heap allocation function
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
*   Override C/C++ runtime heap deallocation
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
*   Override C/C++ runtime heap deallocation function
*
*END*----------------------------------------------------------------------*/

void free(pointer p)
{
    _mem_free(p);
}


/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    : exit
* Returned Value   : should not return
* Comments         :
*   Replacement for Codewarrior's exit function
*
*END*----------------------------------------------------------------------*/
#if MQX_EXIT_ENABLED
int _exit(int status)
{
#if MQX_ENABLE_CPP || BSPCFG_ENABLE_CPP
    /* Semi-normal CodeWarrior shutdown sequence */
    __destroy_global_chain();
    __fini_cpp();
#endif /* MQX_ENABLE_CPP || BSPCFG_ENABLE_CPP */

    /*
    ** Change for whatever is appropriate for your board
    ** and application.  Perhaps a software reset or
    ** some kind of trap/call to the kernel soft re-boot.
    */
    while (TRUE) {
    }

    return(0);
}

#else  /* MQX_EXIT_ENABLED */

int _exit(int status)
{
    return 0;
}

#endif /* MQX_EXIT_ENABLED */
/* EOF */
