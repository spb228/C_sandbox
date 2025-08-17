cmake_minimum_required(VERSION 3.10)

project(c_sandbox C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message("configuring for windows GCC")
    set(CMAKE_C_COMPILER "C:/MinGW/bin/gcc.exe")
endif()

add_subdirectory(../src src)

MESSAGE("Done configuring entire CMake project")
