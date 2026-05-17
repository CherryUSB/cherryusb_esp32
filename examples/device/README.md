# CherryUSB Device Example

A composite USB **CDC ACM + MSC** device demo running on ESP chips with native USB IP, built on top of [CherryUSB](https://github.com/cherry-embedded/CherryUSB).

After flashing, the board enumerates on the host as:

- a virtual serial port (CDC ACM) — echoes data back to the host
- a USB mass-storage disk (MSC) — backed by an in-RAM block device

## Supported Targets

| Chip       | USB IP            | Register base (auto-selected) |
| ---------- | ----------------- | ----------------------------- |
| ESP32-S2   | Full-Speed (FS0)  | `0x60080000`                  |
| ESP32-S3   | Full-Speed (FS0)  | `0x60080000`                  |
| ESP32-P4   | High-Speed (HS0)  | `0x50000000`                  |
| ESP32-S31  | High-Speed (HS0)  | `0x20300000`                  |

The register base is picked up from `ESP_USBD_BASE` in `CherryUSB/osal/idf/usb_config.h` according to `CONFIG_IDF_TARGET_*`, so `main.c` does not hard-code any address.

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

and the host OS should detect a new CDC serial port and a removable disk.

## References

- CherryUSB upstream: <https://github.com/cherry-embedded/CherryUSB>
- API docs: <https://cherryusb.readthedocs.io/>
