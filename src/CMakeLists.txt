cmake_minimum_required(VERSION 3.10)

project(c_sandbox C)

set(INC_LIB_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/../inc/file.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../inc/oop_car.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../inc/oop_car.c
)

add_library(inc_lib STATIC 
    ${INC_LIB_FILES})

set_target_properties(inc_lib PROPERTIES LINKER_LANGUAGE C)

add_executable(${PROJECT_NAME} main.c)

target_link_libraries(${PROJECT_NAME} PRIVATE inc_lib)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ../../../bin/)

MESSAGE ("Done configuring src cmake")