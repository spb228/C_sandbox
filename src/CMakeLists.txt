cmake_minimum_required(VERSION 3.10)

project(c_sandbox C)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/threads threads)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/processes processes)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/IPC ipc)

add_executable(${PROJECT_NAME} main.c)

target_link_libraries(${PROJECT_NAME} PRIVATE inc)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin)

MESSAGE (STATUS "Done configuring src cmake")