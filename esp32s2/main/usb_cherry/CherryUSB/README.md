# CherryUSB

[中文版](./README_zh.md)

CherryUSB is a tiny, beautiful and portable USB host and device stack for embedded system with USB ip.

![CherryUSB](./docs/asserts/usb_outline.png)

## Why choose

- Ip-oriented programming means the same usb ip's driver has no need to be written repeatedly, only the parts(such as `usb_xx_low_level_init`：including usb clock, usb gpio and usb irq configuration)that are not the same have to be implemented,
- Tree-based coding makes it easier for users to understand usb concept, enumeration process and class driver loading process
- Templating the class drivers makes it easier to use composite device and add custom drivers
- Simplifying the complex transfer of usb makes it easier for users to use usb as easily as uart and dma
- Fewer directory structures, fewer apis, fewer codesize, extreme usb bandwidth

## Directoy Structure

```
.
├── class
├── common
├── core
├── demo
├── docs
├── osal
├── packet capture
└── port
└── tools

```

|   Directory       |  Description            |
|:-------------:|:---------------------------:|
|class          |  usb class driver           |
|common         |  usb spec macros and utils  |
|core           |  usb core implementation  |
|demo           |  different chips demo     |
|osal           |  os wrapper              |
|docs           |  doc for guiding         |
|packet capture |  packet capture file     |
|port           |  usb dcd and hcd porting |
|tools           |  tool used url          |

## Device Stack Overview

CherryUSB Device Stack provides a unified framework of functions for standard device requests, CLASS requests, VENDOR requests and custom special requests. The object-oriented and chained approach allows the user to quickly get started with composite devices without having to worry about the underlying logic. At the same time, a standard dcd porting interface has been standardised for adapting different USB IPs to achieve ip-oriented programming.

CherryUSB Device Stack has the following functions：

- Support USB2.0 full and high speed
- Support endpoint irq callback register by users, let users do whatever they wants in endpoint irq callback.
- Support Composite Device
- Support Communication Device Class (CDC)
- Support Human Interface Device (HID)
- Support Mass Storage Class (MSC)
- Support USB VIDEO CLASS (UVC1.0、UVC1.5)
- Support USB AUDIO CLASS (UAC1.0、UAC2.0)
- Support Device Firmware Upgrade CLASS (DFU)
- Support USB MIDI CLASS (MIDI)
- Support Test and Measurement CLASS (TMC)
- Support Remote NDIS (RNDIS)
- Support WINUSB1.0、WINUSB2.0(with BOS)
- Support Vendor class

CherryUSB Device Stack resource usage (GCC 10.2 with -O2):

|   file      |  FLASH (Byte)  |  RAM (Byte)  |
|:-----------:|:--------------:|:------------:|
|usbd_core.c  |  3045          | 373          |
|usbd_cdc.c   |  302           | 20           |
|usbd_msc.c   |  2452          | 132          |
|usbd_hid.c   |  784           | 201          |
|usbd_audio.c |  438           | 14           |
|usbd_video.c |  402           | 4            |

## Host Stack Overview

The CherryUSB Host Stack has a standard enumeration implementation for devices mounted on roothubs and external hubs, and a standard interface for different Classes to indicate what the Class driver needs to do after enumeration and after disconnection. A standard hcd porting interface has also been standardised for adapting different USB IPs for IP-oriented programming. Finally, the host stack is managed using os, and provides osal to make a adaptation for different os.

CherryUSB Host Stack has the following functions：

- Automatic loading of supported Class drivers
- Support blocking transfers and asynchronous transfers
- Support Composite Device
- Multi-level HUB support, expandable up to 7 levels
- Support Communication Device Class (CDC)
- Support Human Interface Device (HID)
- Support Mass Storage Class (MSC)
- Support Remote NDIS (RNDIS)
- Support Vendor class

The CherryUSB Host stack also provides the lsusb function, which allows you to view information about all mounted devices, including those on external hubs, with the help of a shell plugin.

CherryUSB Host Stack resource usage (GCC 10.2 with -O2):

|   file        |  FLASH (Byte)  |  RAM (Byte)  |
|:-------------:|:--------------:|:------------:|
|usbh_core.c    |  7992          | 472          |
|usbh_cdc_acm.c |  1208          | 4            |
|usbh_msc.c     |  2239          | 4            |
|usbh_hid.c     |  930           | 4            |
|usbh_hub.c     |  3878          | 14           |

## Documentation Tutorial

Quickly start, USB basic concepts, API manual, Class basic concepts and examples, see [CherryUSB Documentation Tutorial](https://cherryusb.readthedocs.io/)

## Video Tutorial

USB basic concepts and how the CherryUSB Device stack is implemented, see [CherryUSB Device Stack Tutorial](https://www.bilibili.com/video/BV1Ef4y1t73d).

## Graphical Config Tool

[chryusb_configurator](https://github.com/Egahp/chryusb_configurator) is written in **electron + vite2 + ts** framework，currently used to automate the generation of descriptor arrays, with additional functionality to be added later.

## Demo Repo

|   Manufacturer       |  CHIP or Series    | USB IP| Repo Url |
|:-------------:|:----------:|:----------:|:----------:|
|Bouffalolab    |  BL702 | bouffalolab|[bl_mcu_sdk](https://github.com/bouffalolab/bl_mcu_sdk/tree/master/examples/usb)|
|Essemi    |  ES32F36xx | musb |[es32f369_repo](https://github.com/sakumisu/CherryUSB/tree/master/demo/es32)|
|AllwinnerTech    |  F1C100S | musb |[cherryusb_rtt_f1c100s](https://github.com/CherryUSB/cherryusb_rtt_f1c100s)|
|ST    |  STM32F103C8T6 | fsdev |[stm32f103_repo](https://github.com/sakumisu/CherryUSB/tree/master/demo/stm32/usb_device/stm32f103c8t6)|
|ST    |  STM32F4 | dwc2 |[stm32f429_device_repo](https://github.com/sakumisu/CherryUSB/tree/master/demo/stm32/usb_device/stm32f429igt6)   [stm32f429_host_repo](https://github.com/sakumisu/CherryUSB/tree/master/demo/stm32/usb_host/stm32f429igt6)|
|ST    |  STM32H7 | dwc2 |[stm32h743_device_repo](https://github.com/sakumisu/CherryUSB/tree/master/demo/stm32/usb_device/stm32h743vbt6)   [stm32h743_host_repo](https://github.com/sakumisu/CherryUSB/tree/master/demo/stm32/usb_host/stm32h743xih6)|
|WCH    |  CH32V307 | ch32_usbfs |[ch32v307_repo](https://github.com/sakumisu/CherryUSB/tree/master/demo/ch32/usb_device/CH32V307VCT6)|
|WCH    |  CH57x | ch58x |[ch57x_repo](https://github.com/CherryUSB/cherryusb_ch57x)|
|Nuvoton    |  Nuc442 | nuvoton |[nuc442_repo](https://github.com/sakumisu/CherryUSB/tree/master/demo/nuvoton/usb_device/nuc442)|
|Nordicsemi |  Nrf52840 | nrf5x |[nrf5x_repo](https://github.com/CherryUSB/cherryusb_nrf5x)|
|Geehy    |  APM32E10x APM32F0xx| fsdev |[apm32_repo](https://github.com/CherryUSB/cherryusb_apm32)|
|Mindmotion    |  MM32L3xx | mm32 |[mm32_repo](https://github.com/CherryUSB/cherryusb_mm32)|

## Contact

QQ group: 642693751