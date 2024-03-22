set(CONFIG_CHERRYUSB_DEVICE 1)
set(CONFIG_CHERRYUSB_DEVICE_CDC 1)
set(CONFIG_CHERRYUSB_DEVICE_HID 1)
set(CONFIG_CHERRYUSB_DEVICE_MSC 1)
set(CONFIG_CHERRYUSB_DEVICE_DCD "dwc2_esp")

set(CONFIG_CHERRYUSB_HOST 1)
set(CONFIG_CHERRYUSB_HOST_CDC_ACM 1)
# set(CONFIG_CHERRYUSB_HOST_CDC_ECM 1)
# set(CONFIG_CHERRYUSB_HOST_CDC_NCM 1)
set(CONFIG_CHERRYUSB_HOST_HID 1)
set(CONFIG_CHERRYUSB_HOST_MSC 1)
# set(CONFIG_CHERRYUSB_HOST_VIDEO 1)
# set(CONFIG_CHERRYUSB_HOST_AUDIO 1)
# set(CONFIG_CHERRYUSB_HOST_CDC_RNDIS 1)
# set(CONFIG_CHERRYUSB_HOST_BLUETOOTH 1)
# set(CONFIG_CHERRYUSB_HOST_ASIX 1)
# set(CONFIG_CHERRYUSB_HOST_RTL8152 1)
#set(CONFIG_CHERRYUSB_OSAL "freertos")
set(CONFIG_CHERRYUSB_HOST_HCD "dwc2_esp")

include($ENV{IDF_PATH}/demo/cherryusb/main/cherryusb/cherryusb.cmake)

idf_component_register(SRCS "hello_world_main.c" "usb_osal_freertos_esp.c" "cherryusb/demo/cdc_acm_msc_template.c" ${cherryusb_srcs}
                    INCLUDE_DIRS "." ${cherryusb_incs}
                    LDFRAGMENTS "linker.lf"
                    WHOLE_ARCHIVE)
