cmake_minimum_required(VERSION 3.12)

set(jp2a_source
    src/aspect_ratio.c
    src/curl.c
    src/html.c
    src/image.c
    src/jp2a.c
    src/options.c
    src/terminal.c
)

if(WIN32)
    set(WIN32_MACROS "WIN32")
endif(WIN32)

file(TOUCH ${CMAKE_BINARY_DIR}/config.h)

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

find_package(JPEG REQUIRED)
target_link_libraries(jp2a ${JPEG_LIBRARIES})
find_package(PNG REQUIRED)
target_link_libraries(jp2a ${PNG_LIBRARIES})
