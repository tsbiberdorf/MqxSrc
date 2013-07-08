/**HEADER********************************************************************
* 
* Copyright (c) 2008 Freescale Semiconductor;
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
* $FileName: httpdsrv.h$
* $Version : 3.8.2.0$
* $Date    : Sep-25-2012$
*
* Comments:
*
*   Configurable information for the RTCS examples.
*
*END************************************************************************/
#ifndef _httpdsrv_h_
#define _httpdsrv_h_

#include <bsp.h>

#define LED(num) BSP_LED##num
#define NUM_LEDS 0

#ifdef BSP_LED1
#undef  NUM_LEDS
#define NUM_LEDS 1
#endif
#ifdef BSP_LED2
#undef  NUM_LEDS
#define NUM_LEDS 2
#endif
#ifdef BSP_LED3
#undef  NUM_LEDS
#define NUM_LEDS 3
#endif
#ifdef BSP_LED4
#undef  NUM_LEDS
#define NUM_LEDS 4
#endif

#define ADC_CHANNELS   1

#if defined(BSP_TWR_K60N512) || defined(BSP_TWR_K40X256)    
    #if BSPCFG_ENABLE_ADC1
        #define MY_ADC "adc1:" /* must be #1 as the inputs are wired to ADC 1 */    
        #define ENABLE_ADC BSPCFG_ENABLE_ADC1    
        #define ADC_SOURCE0 ADC1_SOURCE_ADPM1
        #define MY_TRIGGER ADC_PDB_TRIGGER
    #endif /* BSPCFG_ENABLE_ADCx */

#else /* defined BSP_xxx */    
    #if BSPCFG_ENABLE_ADC
        #define MY_ADC "adc:"    
        #define ENABLE_ADC BSPCFG_ENABLE_ADC
        #define ADC_SOURCE0 BSP_ADC_CH_POT
        #define MY_TRIGGER 0
    #endif /* BSPCFG_ENABLE_ADCx */
#endif /* defined BSP_xxx */

#endif // _httpdsrv_h_
