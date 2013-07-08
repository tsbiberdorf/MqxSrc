#include <mqx.h>
#include <bsp.h>
#include <lwmsgq.h>

//the following block is specific to the K60 twr bd
#define MY_TRIGGER ADC_PDB_TRIGGER
#if !BSPCFG_ENABLE_ADC1
	#error This application requires BSPCFG_ENABLE_ADC1 defined non-zero in user_config.h. Please recompile BSP with this option.
#endif /* BSPCFG_ENABLE_ADCx */


/* ADC device init struct */
const ADC_INIT_STRUCT adc_init = {
    ADC_RESOLUTION_DEFAULT,     /* resolution */
};

/* Logical channel #1 init struct */
const ADC_INIT_CHANNEL_STRUCT adc_channel_param1 =
{
    ADC1_SOURCE_ADPM1, /* physical ADC channel - this is the potentiometer on the tower board*/
    ADC_CHANNEL_MEASURE_LOOP | ADC_CHANNEL_START_TRIGGERED, /* runs continuously after IOCTL trigger */
    10,             /* number of samples in one run sequence */
    0,              /* time offset from trigger point in us */
    300000,         /* period in us (= 0.3 sec) */
    0x10000,        /* scale range of result (not used now) */
    10,             /* circular buffer size (sample count) */
    MY_TRIGGER,     /* logical trigger ID that starts this ADC channel */
};

uint_32 adc_value;

/*TASK*-----------------------------------------------------
**
** Task Name    : main_task
** Comments     :
**
*END*-----------------------------------------------------*/

void ADC_Task(uint_32 initial_data)
{
    ADC_RESULT_STRUCT data;
    _mqx_int i;
    MQX_FILE_PTR f, f_ch1;

    printf("Opening ADC device ...");
    f = fopen("adc1:", (const char*)&adc_init);
    if(f != NULL)
    {
        printf("done\n");
    }
    else
    {
        printf("failed\n");
        _task_block();
    }

    printf("Opening channel #1 ...");
    f_ch1 = fopen("adc1:" "first", (const char*)&adc_channel_param1);
    if(f_ch1 != NULL)
    {
        printf("done, prepared to start by trigger\n");
    }
    else
    {
        printf("failed\n");
        _task_block();
    }

    _time_delay(300);

    printf("Triggering channel #1...");
    ioctl(f, ADC_IOCTL_FIRE_TRIGGER, (pointer) MY_TRIGGER);
    printf("triggered!\n");

    for(i = 0; ; i++)
    {
        /* channel 1 sample ready? */
        if (read(f_ch1, &data, sizeof(data)))
        {
        	adc_value = data.result;
            printf("ADC ch 1: %4d \n", data.result);
        }
        else
            printf("               ");

        _time_delay(300);
    }
}
