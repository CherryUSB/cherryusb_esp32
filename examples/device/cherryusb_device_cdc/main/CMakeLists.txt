idf_component_register(SRCS 
    "device_cdc_main.c"
    INCLUDE_DIRS
    "."
)

# Determine whether esp_cherryusb is fetched from the component registry or from the local path
idf_build_get_property(build_components BUILD_COMPONENTS)
if(esp_cherryusb IN_LIST build_components)
    set(esp_cherryusb_name esp_cherryusb) # Local component
else()
    set(esp_cherryusb_name leeebo__esp_cherryusb) # Managed component
endif()

# Pass usb_config.h.h from this component to esp_cherryusb
idf_component_get_property(_esp_cherryusb_lib ${esp_cherryusb_name} COMPONENT_LIB)
cmake_policy(SET CMP0079 NEW)
target_link_libraries(${_esp_cherryusb_lib} PRIVATE ${COMPONENT_LIB})
