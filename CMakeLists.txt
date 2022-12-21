cmake_minimum_required(VERSION 3.12)

project(jp2a
    VERSION 1.1.1
    DESCRIPTION "Converts jpg/png images to ASCII"
    LANGUAGES C
)

if(WIN32)
    set(WIN32_MACROS "WIN32")
endif(WIN32)

find_package(JPEG REQUIRED)
find_package(PNG REQUIRED)

file(TOUCH ${CMAKE_BINARY_DIR}/config.h)
add_subdirectory(src)
