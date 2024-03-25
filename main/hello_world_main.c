/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_system.h"
#include "usbd_core.h"
#include "usbh_core.h"

void app_main(void)
{
    USB_LOG_INFO("Hello world!\n");

    // extern void cdc_acm_msc_init(uint8_t busid, uint32_t reg_base);
    // cdc_acm_msc_init(0, 0x60080000);

    usbh_initialize(0, 0x60080000);
    while(1)
    {
        // extern void cdc_acm_data_send_with_dtr_test(uint8_t busid);
        // cdc_acm_data_send_with_dtr_test(0);
        vTaskDelay(10);
    }
}
