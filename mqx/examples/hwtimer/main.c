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
* $FileName: main.c$
* $Version : 3.8.19.0$
* $Date    : Jun-6-2012$
*
* Comments:
*
*   This file contains the source for the hello example program.
*
*END************************************************************************/

#include <mqx.h>
#include <bsp.h>
#include <hwtimer.h>
#include <lwsem.h>


#if ! BSPCFG_ENABLE_IO_SUBSYSTEM
#error This application requires BSPCFG_ENABLE_IO_SUBSYSTEM defined non-zero in user_config.h. Please recompile BSP with this option.
#endif


#ifndef BSP_DEFAULT_IO_CHANNEL_DEFINED
#error This application requires BSP_DEFAULT_IO_CHANNEL to be not NULL. Please set corresponding BSPCFG_ENABLE_TTYx to non-zero in user_config.h and recompile BSP with this option.
#endif

/*hwtimer example defines*/
#define HWTIMER1_FREQUENCY  250         //frequency set to hwtimer 1
#define HWTIMER2_PERIOD     1000000     //period set to 1s to hwtimer 2
/* Task IDs */
#define HWTIMER_TASK 5

extern void hwtimer_task(uint_32);

extern HWTIMER_DEVIF_STRUCT BSP_HWTIMER1_DEV;  //device struct
HWTIMER hwtimer1;                       //hwtimer handle
HWTIMER hwtimer2;                       //hwtimer handle
HWTIMER time;                           //struct for storing time
LWSEM_STRUCT job_done;                  //semaphore for end of job

const TASK_TEMPLATE_STRUCT  MQX_template_list[] =
{
    /* Task Index,   Function,   Stack,  Priority, Name,     Attributes,          Param, Time Slice */
    { HWTIMER_TASK,  hwtimer_task, 1500,   8,   "hwtimer",  MQX_AUTO_START_TASK, 0,     0 },
    { 0 }
};

/*FUNCTION*----------------------------------------------------------------*
* Function Name  : hwtimer1_callback
* Returned Value : void
* Comments :
*       Callback for hwtimer1
*END*--------------------------------------------------------------------*/
void hwtimer1_callback(pointer p)
{
    putchar('.');
}

/*FUNCTION*----------------------------------------------------------------*
* Function Name  : hwtimer2_callback
* Returned Value : void
* Comments :
*   Callback for hwtimer2
*
*END*--------------------------------------------------------------------*/
void hwtimer2_callback(pointer p)
{
    int ticks = hwtimer_get_ticks(&hwtimer2);
    if(1 == ticks)
    {
        /* Start hwtimer1*/
        printf("hwtimer2_callback %d tick : start hwtimer1\n",ticks);
        hwtimer_start(&hwtimer1);
    }
    if(2 == ticks)
    {
        printf("\nhwtimer2_callback %d ticks: block hwtimer1_callback\n",ticks);
        hwtimer_callback_block(&hwtimer1);
    }
    if(4 == ticks)
    {
        printf("\nhwtimer2_callback %d ticks: unblock hwtimer1_callback\n",ticks);
        hwtimer_callback_cancel(&hwtimer1); // Clear pending callback for hwtimer1
        hwtimer_callback_unblock(&hwtimer1);
    }
    if(6 == ticks)
    {
        printf("\nhwtimer2_callback %d ticks: stop hwtimer1\n",ticks);
        hwtimer_stop(&hwtimer1);
        printf("hwtimer2_callback %d ticks: stop hwtimer2\n",ticks);
        hwtimer_stop(&hwtimer2);
        printf("hwtimer2_callback %d ticks: hwtimer1 = %d ticks\n",ticks, hwtimer_get_ticks(&hwtimer1));
        _lwsem_post(&job_done);
    }
}

/*TASK*-----------------------------------------------------
*
* Task Name    : hwtimer_task
* Comments     :
*    This task prints " HWTIMER"
*
*END*-----------------------------------------------------*/
void hwtimer_task
    (
        uint_32 initial_data
    )
{


    printf("\n--------------------------START OF HWTIMER EXAMPLE--------------------------\n");

    if (MQX_OK != _lwsem_create(&job_done, 0))
    {
        printf("Failed to create semaphore");
        _task_block();
    }
    /* Initialization of hwtimer1*/
    printf("Initialization of hwtimer1   :");
    if (MQX_OK != hwtimer_init(&hwtimer1, &BSP_HWTIMER1_DEV, BSP_HWTIMER1_ID, (BSP_DEFAULT_MQX_HARDWARE_INTERRUPT_LEVEL_MAX + 1)))
    {
        printf(" FAILED!\n");
    }
    else
    {
        printf(" OK\n");
    }
    printf("Try to set frequency %d Hz to hwtimer1\n",HWTIMER1_FREQUENCY);
    hwtimer_set_freq(&hwtimer1, BSP_HWTIMER1_SOURCE_CLK, HWTIMER1_FREQUENCY);
    printf("Read frequency from hwtimer1 : %d Hz\n", hwtimer_get_freq(&hwtimer1));
    printf("Read period from hwtimer1    : %d us\n", hwtimer_get_period(&hwtimer1));
    printf("Read modulo from hwtimer1    : %d\n", hwtimer_get_modulo(&hwtimer1));
    /* Register isr for hwtimer1 */
    printf("Register callback for hwtimer1\n");
    hwtimer_callback_reg(&hwtimer1,(HWTIMER_CALLBACK_FPTR)hwtimer1_callback, NULL);



    /* Initialization of hwtimer2*/
    printf("\nInitialization of hwtimer2   :");
    if (MQX_OK != hwtimer_init(&hwtimer2, &BSP_HWTIMER2_DEV, BSP_HWTIMER2_ID, 1))
    {
        printf(" FAILED!\n");
    }
    else
    {
        printf(" OK\n");
    }
    printf("Try to set period %d us to hwtimer2\n", HWTIMER2_PERIOD);
    hwtimer_set_period(&hwtimer2, BSP_HWTIMER2_SOURCE_CLK, HWTIMER2_PERIOD);
    printf("Read frequency from hwtimer2 : %d Hz\n", hwtimer_get_freq(&hwtimer2));
    printf("Read period from hwtimer2    : %d us\n", hwtimer_get_period(&hwtimer2));
    printf("Read modulo from hwtimer2    : %d\n", hwtimer_get_modulo(&hwtimer2));
    /* Register isr for hwtimer2 */
    printf("Register callback for hwtimer2\n");
    hwtimer_callback_reg(&hwtimer2,(HWTIMER_CALLBACK_FPTR)hwtimer2_callback, NULL);
    /* Start hwtimer1*/
    printf("Start hwtimer2\n");
    hwtimer_start(&hwtimer2);

    /* Waiting for semaphore from callback routine */
    _lwsem_wait(&job_done);

    /* Deinitialization of hwtimers */
    printf("Deinit hwtimer1\n");
    hwtimer_deinit(&hwtimer1);
    printf("Deinit hwtimer2\n");
    hwtimer_deinit(&hwtimer2);

    printf("---------------------------END OF HWTIMER EXAMPLE---------------------------\n");
    _lwsem_destroy(&job_done);
}

/* EOF */
