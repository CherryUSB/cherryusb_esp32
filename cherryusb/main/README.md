## CherryUSB ESP32S2/ESP32S3

**app_main** 中包含主从初始化代码，自行选择编译

## PATCH

- usbh_core.c

```
    extern uint32_t _usbh_class_info_start;
    extern uint32_t _usbh_class_info_end;
    usbh_class_info_table_begin = (struct usbh_class_info *)&_usbh_class_info_start;
    usbh_class_info_table_end = (struct usbh_class_info *)&_usbh_class_info_end;
```

- CMakeLists.txt，修改为正确路径

```
include($ENV{IDF_PATH}/demo/cherryusb/main/cherryusb/cherryusb.cmake)
```

