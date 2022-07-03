#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include <stdio.h>

void app_main()
{
    extern void cdc_acm_msc_init();

    printf("Hello cherry!\n");
    cdc_acm_msc_init();

    while (1)
    {
        extern void cdc_acm_data_send_with_dtr_test();

        cdc_acm_data_send_with_dtr_test();
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}