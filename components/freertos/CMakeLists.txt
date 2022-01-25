set(srcs
        "port/Posix/port.c"
        "port/Posix/utils/wait_for_event.c"
        "port/Posix/application.c"
        "port/MemMang/heap_3.c"
        )

set(include_dirs
    include
    port/Posix)

set(private_include_dirs
    include/freertos
    port/Posix/utils
    port/Posix
    .)

list(APPEND srcs
    "croutine.c"
    "event_groups.c"
    "list.c"
    "queue.c"
    "tasks.c"
    "timers.c"
    "stream_buffer.c")

# app_trace is required by FreeRTOS headers only when CONFIG_SYSVIEW_ENABLE=y,
# but requirements can't depend on config options, so always require it.
idf_component_register(SRCS "${srcs}"
                    INCLUDE_DIRS ${include_dirs}
                    PRIV_INCLUDE_DIRS  ${private_include_dirs})

# idf_component_get_property(COMPONENT_DIR freertos COMPONENT_DIR)
# idf_component_set_property(freertos ORIG_INCLUDE_PATH "${COMPONENT_DIR}/include/freertos/")
target_compile_options(${COMPONENT_LIB} PUBLIC -DprojCOVERAGE_TEST=1)
target_link_libraries(${COMPONENT_LIB} PUBLIC pthread)
