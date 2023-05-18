/*
 * @Author       : 陈科进
 * @Date         : 2023-05-18 13:27:40
 * @LastEditors  : 陈科进
 * @LastEditTime : 2023-05-18 21:07:26
 * @FilePath     : \main\hello_world_main.c
 * @Description  : ESP32 candlelight firmware object
 */

#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "hal/usb_hal.h"
#include "soc/usb_periph.h"
#include "driver/gpio.h"
#include "driver/periph_ctrl.h"
#include <stdio.h>

static void ConfigureUsbPins(usb_hal_context_t *usb)
{
    /* usb_periph_iopins currently configures USB_OTG as USB Device.
     * Introduce additional parameters in usb_hal_context_t when adding support
     * for USB Host.
     */
    for (const usb_iopin_dsc_t *iopin = usb_periph_iopins; iopin->pin != -1; ++iopin)
    {
        if ((usb->use_external_phy) || (iopin->ext_phy_only == 0))
        {
            gpio_pad_select_gpio(iopin->pin);
            if (iopin->is_output)
            {
                gpio_matrix_out(iopin->pin, iopin->func, false, false);
            }
            else
            {
                gpio_matrix_in(iopin->pin, iopin->func, false);
                gpio_pad_input_enable(iopin->pin);
            }
            gpio_pad_unhold(iopin->pin);
        }
    }
    if (!usb->use_external_phy)
    {
        gpio_set_drive_capability(USBPHY_DM_NUM, GPIO_DRIVE_CAP_3);
        gpio_set_drive_capability(USBPHY_DP_NUM, GPIO_DRIVE_CAP_3);
    }
}
void app_main()
{
    extern void cdc_acm_init00();
    periph_module_reset(PERIPH_USB_MODULE);
    periph_module_enable(PERIPH_USB_MODULE);

    usb_hal_context_t hal = {
        .use_external_phy = false};
    usb_hal_init(&hal);
    ConfigureUsbPins(&hal);

    printf("Hello cherry!\n");
    cdc_acm_init00();
    while (1)
    {
        extern void cdc_acm_data_send_with_dtr_test();

        cdc_acm_data_send_with_dtr_test();
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}