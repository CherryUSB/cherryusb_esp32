idf_component_register(SRCS 
    "device_cdc_main.c"
    INCLUDE_DIRS
    "."
)

# Determine whether cherryusb_esp32 is fetched from the component registry or from the local path
idf_build_get_property(build_components BUILD_COMPONENTS)
if(cherryusb_esp32 IN_LIST build_components)
    set(cherryusb_esp32_name cherryusb_esp32) # Local component
else()
    set(cherryusb_esp32_name leeebo__cherryusb_esp32) # Managed component
endif()

# Pass usb_config.h.h from this component to cherryusb_esp32
idf_component_get_property(_cherryusb_esp32_lib ${cherryusb_esp32_name} COMPONENT_LIB)
cmake_policy(SET CMP0079 NEW)
target_link_libraries(${_cherryusb_esp32_lib} PRIVATE ${COMPONENT_LIB})
