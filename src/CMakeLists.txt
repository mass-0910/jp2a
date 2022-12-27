add_library(jp2a STATIC)

target_sources(jp2a PRIVATE
    aspect_ratio.c
    curl.c
    html.c
    image.c
    jp2a.c
    options.c
    terminal.c
)

target_include_directories(jp2a PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${CMAKE_BINARY_DIR} # for config.h
    ${JPEG_INCLUDE_DIR}
    ${PNG_INCLUDE_DIR}
)

target_link_libraries(jp2a
    ${JPEG_LIBRARIES}
    ${PNG_LIBRARIES}
)

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
