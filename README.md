## CherryUSB ESP32S2/ESP32S3

support device and host in **app_main**.

## patch for usb host

- usbh_core.c

```
    extern uint32_t _usbh_class_info_start;
    extern uint32_t _usbh_class_info_end;
    usbh_class_info_table_begin = (struct usbh_class_info *)&_usbh_class_info_start;
    usbh_class_info_table_end = (struct usbh_class_info *)&_usbh_class_info_end;
```


