cmake_minimum_required(VERSION 3.5)

# PROJECT_PLATFORM_LINUX
# PROJECT_PLATFORM_ESP32
add_compile_definitions(PROJECT_PLATFORM_LINUX)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)

add_compile_options(
    -Wno-unused-variable
    -Wno-unused-but-set-variable
    -Wno-unused-function
    -Wno-missing-field-initializers
    -Wno-maybe-uninitialized
    -Wno-pointer-arith
    -Wno-narrowing
    -Wno-implicit-fallthrough
    -Wno-unused-result
)

set(EXTRA_COMPONENT_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/components/freertos)
set(COMPONENTS main)
project(linux_freertos_test)
