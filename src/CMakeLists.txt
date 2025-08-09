cmake_minimum_required(VERSION 3.10)

project(c_sandbox C)

add_executable(${PROJECT_NAME} main.c)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ../../../bin/)

MESSAGE ("Done configuring src cmake")