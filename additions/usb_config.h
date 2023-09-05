/*
 * SPDX-FileCopyrightText: 2022-2023 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#define CHERRYUSB_VERSION 0x001001
#include "sdkconfig.h"
#include "esp_rom_sys.h"

/* ================ USB common Configuration ================ */

#define CONFIG_USB_PRINTF(...) esp_rom_printf(__VA_ARGS__)

#define usb_malloc(size) malloc(size)
#define usb_free(ptr)    free(ptr)

#ifndef CONFIG_USB_DBG_LEVEL
#define CONFIG_USB_DBG_LEVEL USB_DBG_INFO
#endif

/* Enable print with color */
#define CONFIG_USB_PRINTF_COLOR_ENABLE

/* data align size when use dma */
#ifndef CONFIG_USB_ALIGN_SIZE
#define CONFIG_USB_ALIGN_SIZE 4
#endif

/* attribute data into no cache ram */
#define USB_NOCACHE_RAM_SECTION

/* ================= USB Device Stack Configuration ================ */
// NOTE: Below configurations are removed to Kconfig, `idf.py menuconfig` to config them

/* Ep0 max transfer buffer, specially for receiving data from ep0 out */
// #define CONFIG_USBDEV_REQUEST_BUFFER_LEN 256
/* Setup packet log for debug */
// #define CONFIG_USBDEV_SETUP_LOG_PRINT
/* Check if the input descriptor is correct */
// #define CONFIG_USBDEV_DESC_CHECK
/* Enable test mode */
// #define CONFIG_USBDEV_TEST_MODE

/* ================ USB HOST Stack Configuration ================== */
// NOTE: Below configurations are removed to Kconfig, `idf.py menuconfig` to config them

// #define CONFIG_USBHOST_MAX_RHPORTS          1
// #define CONFIG_USBHOST_MAX_EXTHUBS          1
// #define CONFIG_USBHOST_MAX_EHPORTS          4
// #define CONFIG_USBHOST_MAX_INTERFACES       6
// #define CONFIG_USBHOST_MAX_INTF_ALTSETTINGS 1
// #define CONFIG_USBHOST_MAX_ENDPOINTS        4
// #define CONFIG_USBHOST_MAX_CDC_ACM_CLASS 4
// #define CONFIG_USBHOST_MAX_HID_CLASS     4
// #define CONFIG_USBHOST_MAX_MSC_CLASS     2
// #define CONFIG_USBHOST_MAX_AUDIO_CLASS   1
// #define CONFIG_USBHOST_MAX_VIDEO_CLASS   1
// #define CONFIG_USBHOST_MAX_RNDIS_CLASS   1
// #define CONFIG_USBHOST_DEV_NAMELEN 16
// #define CONFIG_USBHOST_PSC_PRIO 4
// #define CONFIG_USBHOST_PSC_STACKSIZE 2048
// #define CONFIG_USBHOST_GET_STRING_DESC
// #define CONFIG_USBHOST_REQUEST_BUFFER_LEN 512
// #define CONFIG_USBHOST_CONTROL_TRANSFER_TIMEOUT 500

/* ================ USB Device Port Configuration ================*/
#if CONFIG_IDF_TARGET_ESP32S2 || CONFIG_IDF_TARGET_ESP32S3
#define CONFIG_USB_DWC2_PORT FS_PORT
#define USB_BASE 0x60080000
// esp32s2/s3 has 6 endpoints in device mode (except ep0)
#define USB_NUM_BIDIR_ENDPOINTS 4
#elif CONFIG_IDF_TARGET_ESP32C5 || CONFIG_IDF_TARGET_ESP32P4
#define CONFIG_USB_DWC2_PORT HS_PORT
#define CONFIG_USB_HS
#define USB_BASE 0x60080000
// todo: check c5, p4 in later
#define USB_NUM_BIDIR_ENDPOINTS 4
#else
#error "Unsupported SoC"
#endif

/* ================ USB Host Port Configuration ==================*/

#if CONFIG_IDF_TARGET_ESP32S2 || CONFIG_IDF_TARGET_ESP32S3
// esp32s2/s3 has 7 endpoints in host mode (except ep0)
#define CONFIG_USBHOST_PIPE_NUM 7
#elif CONFIG_IDF_TARGET_ESP32C5 || CONFIG_IDF_TARGET_ESP32P4
// todo: check c5, p4 in later
#define CONFIG_USBHOST_PIPE_NUM 7
#else
#error "Unsupported SoC"
#endif
