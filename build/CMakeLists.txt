cmake_minimum_required(VERSION 3.25)

project(c_sandbox C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message("configuring for windows GCC")
    set(CMAKE_C_COMPILER "C:/MinGW/bin/gcc.exe")
endif()

add_subdirectory(../src src)

MESSAGE(STATUS "Done configuring entire CMake project")
