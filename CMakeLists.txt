idf_component_get_property(cusb_path leeebo__cherryusb COMPONENT_DIR)

set(srcs "additions/esp_cherryusb.c")
set(inc_dirs "additions" "${cusb_path}/common" "${cusb_path}/core")

# USB Device sources
if(CONFIG_CHERRYUSBD_ENABLED)
    list(APPEND srcs
        "${cusb_path}/core/usbd_core.c"
        "${cusb_path}/port/dwc2/usb_dc_dwc2.c")
endif()

if(CONFIG_CHERRYUSBD_CDC_ENABLED)
    list(APPEND srcs "${cusb_path}/class/cdc/usbd_cdc.c")
    list(APPEND inc_dirs "${cusb_path}/class/cdc")
endif()

if(CONFIG_CHERRYUSBD_MSC_ENABLED)
    list(APPEND srcs "${cusb_path}/class/msc/usbd_msc.c")
    list(APPEND inc_dirs "${cusb_path}/class/msc")
endif()

if(CONFIG_CHERRYUSBD_HID_ENABLED)
    list(APPEND srcs "${cusb_path}/class/hid/usbd_hid.c")
    list(APPEND inc_dirs "${cusb_path}/class/hid")
endif()

if(CONFIG_CHERRYUSBD_AUDIO_ENABLED)
    list(APPEND srcs "${cusb_path}/class/audio/usbd_audio.c")
    list(APPEND inc_dirs "${cusb_path}/class/audio")
endif()

if(CONFIG_CHERRYUSBD_VIDEO_ENABLED)
    list(APPEND srcs "${cusb_path}/class/video/usbd_video.c")
    list(APPEND inc_dirs "${cusb_path}/class/video")
endif()

if(CONFIG_CHERRYUSBD_RNDIS_ENABLED)
    list(APPEND srcs "${cusb_path}/class/rndis/usbd_rndis.c")
    list(APPEND inc_dirs "${cusb_path}/class/rndis")
endif()

if(CONFIG_CHERRYUSBD_DFU_ENABLED)
    list(APPEND srcs "${cusb_path}/class/dfu/usbd_dfu.c")
    list(APPEND inc_dirs "${cusb_path}/class/dfu")
endif()

if(CONFIG_CHERRYUSBD_MTP_ENABLE)
    list(APPEND srcs "${cusb_path}/class/mtp/usbd_mtp.c")
    list(APPEND inc_dirs "${cusb_path}/class/mtp")
endif()

if(CONFIG_CHERRYUSBD_PRINTER_ENABLED)
    list(APPEND srcs "${cusb_path}/class/printer/usbd_printer.c")
    list(APPEND inc_dirs "${cusb_path}/class/printer")
endif()

# USB Host sources
if(CONFIG_CHERRYUSBH_ENABLED)
    list(APPEND srcs
        "${cusb_path}/core/usbh_core.c"
        "${cusb_path}/port/dwc2/usb_hc_dwc2.c")
endif()

if(CONFIG_CHERRYUSBH_CDC_ENABLED)
    list(APPEND srcs "${cusb_path}/class/cdc/usbh_cdc.c")
    list(APPEND inc_dirs "${cusb_path}/class/cdc")
endif()

if(CONFIG_CHERRYUSBH_MSC_ENABLED)
    list(APPEND srcs "${cusb_path}/class/msc/usbh_msc.c")
    list(APPEND inc_dirs "${cusb_path}/class/msc")
endif()

if(CONFIG_CHERRYUSBH_HID_ENABLED)
    list(APPEND srcs "${cusb_path}/class/hid/usbh_hid.c")
    list(APPEND inc_dirs "${cusb_path}/class/hid")
endif()

if(CONFIG_CHERRYUSBH_AUDIO_ENABLED)
    list(APPEND srcs "${cusb_path}/class/audio/usbh_audio.c")
    list(APPEND inc_dirs "${cusb_path}/class/audio")
endif()

if(CONFIG_CHERRYUSBH_VIDEO_ENABLED)
    list(APPEND srcs "${cusb_path}/class/video/usbh_video.c")
    list(APPEND inc_dirs "${cusb_path}/class/video")
endif()

if(CONFIG_CHERRYUSBH_RNDIS_ENABLED)
    list(APPEND srcs "${cusb_path}/class/rndis/usbh_rndis.c")
    list(APPEND inc_dirs "${cusb_path}/class/rndis")
endif()

if(CONFIG_CHERRYUSBH_MTP_ENABLE)
    list(APPEND srcs "${cusb_path}/class/mtp/usbh_mtp.c")
    list(APPEND inc_dirs "${cusb_path}/class/mtp")
endif()

if(CONFIG_CHERRYUSBH_PRINTER_ENABLED)
    list(APPEND srcs "${cusb_path}/class/printer/usbh_printer.c")
    list(APPEND inc_dirs "${cusb_path}/class/printer")
endif()

idf_component_register(SRCS ${srcs}
    INCLUDE_DIRS ${inc_dirs}
    PRIV_REQUIRES usb
)

include(package_manager)
cu_pkg_define_version(${CMAKE_CURRENT_LIST_DIR})
