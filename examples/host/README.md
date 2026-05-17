# CherryUSB Host Example

A USB **Host** demo running on ESP chips with native USB IP, built on top of [CherryUSB](https://github.com/cherry-embedded/CherryUSB).

The example brings up the CherryUSB host stack and enables a few common class drivers, so plugging different USB peripherals into the board's USB port will be enumerated automatically:

- **CDC ACM** — USB-to-serial / modem devices
- **HID** — keyboards, mice, gamepads, etc.
- **CDC RNDIS** — USB Ethernet dongles (integrated with `esp-netif` + lwIP, hence the `esp_netif_init()` / `esp_event_loop_create_default()` calls in `app_main`)
- A custom class hook (`CONFIG_CHERRYUSB_HOST_CUSTOM`) for user extensions

## Supported Targets

| Chip       | USB IP            | Register base (auto-selected) |
| ---------- | ----------------- | ----------------------------- |
| ESP32-S2   | Full-Speed (FS0)  | `0x60080000`                  |
| ESP32-S3   | Full-Speed (FS0)  | `0x60080000`                  |
| ESP32-P4   | High-Speed (HS0)  | `0x50000000`                  |
| ESP32-S31  | High-Speed (HS0)  | `0x20300000`                  |

The register base is picked up from `ESP_USBH_BASE` in `CherryUSB/osal/idf/usb_config.h` according to `CONFIG_IDF_TARGET_*`, so `main.c` does not hard-code any address.

## Build & Flash

```bash
idf.py set-target esp32s3   # or esp32s2 / esp32p4 / esp32s31
idf.py build
idf.py -p <PORT> flash monitor
```

On boot you should see:

```
Hello CherryUSB!
```

Plug in a USB peripheral and the corresponding class driver will print enumeration logs over the monitor.

## References

- CherryUSB upstream: <https://github.com/cherry-embedded/CherryUSB>
- API docs: <https://cherryusb.readthedocs.io/>
