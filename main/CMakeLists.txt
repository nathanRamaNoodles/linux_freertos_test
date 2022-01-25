set(COMPONENT_SRCDIRS .)
set(COMPONENT_ADD_INCLUDEDIRS .)
idf_build_get_property(target IDF_TARGET)

if("${target}" STREQUAL "linux")
    set(COMPONENT_REQUIRES freertos)
endif()
register_component()
