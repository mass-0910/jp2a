set(jp2a_source
    aspect_ratio.c
    curl.c
    html.c
    image.c
    jp2a.c
    options.c
    terminal.c
)

add_library(jp2a STATIC ${jp2a_source})

target_include_directories(jp2a PUBLIC include ${CMAKE_BINARY_DIR})
target_compile_definitions(jp2a PUBLIC
    ${WIN32_MACROS}
    NDEBUG
    _CONSOLE
    PACKAGE_STRING="jp2a 1.1.1-whofetch"
    PACKAGE_URL="https://github.com/mass-0910/jp2a"
    PACKAGE_BUGREPORT="https://github.com/mass-0910/jp2a/issues"
    HAVE_STRING_H
    HAVE_STDLIB_H
)

target_include_directories(jp2a PUBLIC ${JPEG_INCLUDE_DIR})
target_link_libraries(jp2a ${JPEG_LIBRARIES})

target_include_directories(jp2a PUBLIC ${PNG_INCLUDE_DIR})
target_link_libraries(jp2a ${PNG_LIBRARIES})
