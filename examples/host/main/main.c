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
#include "demo/usb_host.c"

void app_main(void)
{
    USB_LOG_INFO("Hello CherryUSB!\n");

    usbh_initialize(0, ESP_USBH_BASE);
    while(1)
    {
        vTaskDelay(10);
    }
}
