cmake_minimum_required(VERSION 3.10)

project(threads C)

add_executable(${PROJECT_NAME} threads.c)

target_link_libraries(${PROJECT_NAME} PRIVATE inc)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../../bin)

MESSAGE (STATUS "Done configuring threads cmake")