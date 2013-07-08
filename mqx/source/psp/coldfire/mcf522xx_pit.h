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
* $FileName: mcf522xx_pit.h$
* $Version : 3.6.2.0$
* $Date    : Jun-4-2010$
*
* Comments:
*
*   This file contains the type definitions for the mcf522xx PIT module.
*
*END************************************************************************/

#ifndef __mcf522xx_pit_h__
#define __mcf522xx_pit_h__

#define __mcf522xx_pit_h__version "$Version:3.6.2.0$"
#define __mcf522xx_pit_h__date    "$Date:Jun-4-2010$"

#ifdef __cplusplus
extern "C" {
#endif

/*
** MCF522XX_PIT_STRUCT                                                                  
** Programmable interrupt timer
*/
typedef struct mcf522xx_pit_struct
{
   uint_16  PCSR;           // PIT control and status register
   uint_16  PMR;            // PIT modulus register
   uint_16  PCNTR;          // PIT count register
   uchar    filler[0xFFFA];
} MCF522XX_PIT_STRUCT, _PTR_ MCF522XX_PIT_STRUCT_PTR;
typedef volatile struct mcf522xx_pit_struct _PTR_ VMCF522XX_PIT_STRUCT_PTR;

#ifdef __cplusplus
}
#endif

#endif  //__mcf522xx_pit_h__
