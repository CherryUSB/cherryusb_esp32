/*
 * SPDX-FileCopyrightText: 2022-2023 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "device_cdc.h"

static char *TAG = "device_cdc_main";
USB_NOCACHE_RAM_SECTION USB_MEM_ALIGNX uint8_t read_buffer[2048];
USB_NOCACHE_RAM_SECTION USB_MEM_ALIGNX uint8_t write_buffer[2048];
static int write_buffer_len = 0;

volatile bool ep_tx_busy_flag = false;

void usbd_event_handler(uint8_t event)
{
    switch (event) {
        case USBD_EVENT_RESET:
            break;
        case USBD_EVENT_CONNECTED:
            break;
        case USBD_EVENT_DISCONNECTED:
            break;
        case USBD_EVENT_RESUME:
            break;
        case USBD_EVENT_SUSPEND:
            break;
        case USBD_EVENT_CONFIGURED:
            /* setup first out ep read transfer */
            usbd_ep_start_read(CDC_OUT_EP, read_buffer, sizeof(read_buffer));
            break;
        case USBD_EVENT_SET_REMOTE_WAKEUP:
            break;
        case USBD_EVENT_CLR_REMOTE_WAKEUP:
            break;

        default:
            break;
    }
}

static void usbd_cdc_acm_bulk_out(uint8_t ep, uint32_t nbytes)
{
    USB_LOG_RAW("actual out len:%d\r\n", nbytes);
    memcpy(&write_buffer[0], &read_buffer[0], nbytes);
    write_buffer_len = nbytes;
    usbd_ep_start_read(CDC_OUT_EP, read_buffer, sizeof(read_buffer));
}

static void usbd_cdc_acm_bulk_in(uint8_t ep, uint32_t nbytes)
{
    USB_LOG_RAW("actual in len:%d\r\n", nbytes);
    if ((nbytes % CDC_MAX_MPS) == 0 && nbytes) {
        usbd_ep_start_write(CDC_IN_EP, NULL, 0);
    } else {
        ep_tx_busy_flag = false;
    }
}

struct usbd_endpoint cdc_out_ep = {
    .ep_addr = CDC_OUT_EP,
    .ep_cb = usbd_cdc_acm_bulk_out
};

struct usbd_endpoint cdc_in_ep = {
    .ep_addr = CDC_IN_EP,
    .ep_cb = usbd_cdc_acm_bulk_in
};

struct usbd_interface intf0;
struct usbd_interface intf1;

static void cdc_acm_init(void)
{
    const uint8_t data[10] = { 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x30 };

    memcpy(&write_buffer[0], data, 10);

    usbd_desc_register(cdc_descriptor);
    usbd_add_interface(usbd_cdc_acm_init_intf(&intf0));
    usbd_add_interface(usbd_cdc_acm_init_intf(&intf1));
    usbd_add_endpoint(&cdc_out_ep);
    usbd_add_endpoint(&cdc_in_ep);
    usbd_initialize();
}

void usbd_cdc_acm_set_dtr(uint8_t intf, bool dtr)
{
    USB_LOG_INFO("intf:%u, dtr:%d\r\n", intf, dtr);
}

void usbd_cdc_acm_set_rts(uint8_t intf, bool rts)
{
    USB_LOG_INFO("intf:%u, rts:%d\r\n", intf, rts);
}

static void cdc_acm_data_send_with_dtr_test(void)
{
    if (write_buffer_len) {
        ep_tx_busy_flag = true;
        usbd_ep_start_write(CDC_IN_EP, write_buffer, write_buffer_len);
        write_buffer_len = 0;
        while (ep_tx_busy_flag) {
            vTaskDelay(1);
        }
    }
}

void app_main()
{
    // Initialize the USB driver and CDC interface
    cdc_acm_init();
    ESP_LOGI(TAG, "usb cdc acm init done");

    while (1) {
        // Send back the data received from the host
        cdc_acm_data_send_with_dtr_test();
        vTaskDelay(1);
    }
}