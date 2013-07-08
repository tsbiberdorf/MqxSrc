/**HEADER*********************************************************************
*
* Copyright (c) 2010 Freescale Semiconductor;
* All Rights Reserved
*
******************************************************************************
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
******************************************************************************
*
* $FileName: comp.h$
* $Version : 3.8.16.0$
* $Date    : Oct-4-2012$
*
* Comments:
*
*   This file defines the Freescale ARM build tools specific macros for MQX
*
*END*************************************************************************/
#ifndef __comp_h__
#define __comp_h__   1


#ifdef __cplusplus
extern "C" {
#endif

extern asm void __set_BASEPRI(uint_32 basePri);

#define _ASM_NOP()      asm(nop)
#define _ASM_STOP(x)    asm(stop #(x))
#define _ASM_WFI()      asm(wfi)
#define _ASM_SLEEP()    asm(wfi)

#define _PSP_SET_ENABLE_SR(x)   __set_BASEPRI(x)
#define _PSP_SET_DISABLE_SR(x)  _PSP_SET_ENABLE_SR(x)

#define _PSP_SYNC()


/* Kinetis User mode definitions */
#if MQX_ENABLE_USER_MODE
#pragma  define_section kaccess ".kaccess_data" ".kaccess_bss" ".kaccess_rodata" abs32 RW
#pragma  define_section rwuser ".rwuser_data" ".rwuser_bss" ".rwuser_rodata" abs32 RW
#pragma  define_section rouser ".rouser_data" ".rouser_bss" ".rouser_rodata" abs32 RW
#pragma  define_section nouser ".nouser_data" ".nouser_bss" ".nouser_rodata" abs32 RW

#define KERNEL_ACCESS  __declspec(kaccess)
#define USER_RW_ACCESS __declspec(rwuser)
#define USER_RO_ACCESS __declspec(rouser)
#define USER_NO_ACCESS __declspec(nouser)

#else /* MQX_ENABLE_USER_MODE */

#define KERNEL_ACCESS
#define USER_RW_ACCESS
#define USER_RO_ACCESS
#define USER_NO_ACCESS

#endif /* MQX_ENABLE_USER_MODE */

/*
 *      DATATYPE MODIFIERS
 */

#define _WEAK_SYMBOL(x)     __declspec(weak) x
#define _WEAK_FUNCTION(x)   __declspec(weak) x

/* compiler dependent structure packing option */
#define PACKED_STRUCT_BEGIN
#define PACKED_STRUCT_END   __attribute__((__packed__))

/* compiler dependent union packing option */
#define PACKED_UNION_BEGIN
#define PACKED_UNION_END    __attribute__((__packed__))

#ifdef __cplusplus
}
#endif

#endif   /* __comp_h__ */
