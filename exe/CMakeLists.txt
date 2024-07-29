cmake_minimum_required(VERSION 3.22)
project(
    Matrix
    VERSION 0.0.1
    DESCRIPTION "Matrix class"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)

add_executable(matrix_class
    src/main.cpp 
)
# find_library(MYLIB_LIBRARY NAMES matrixlibso PATHS "${PROJECT_BINARY_DIR}/../lib")
include_directories(src)

set(sources
    src/main.cpp
)

target_sources(matrix_class PRIVATE ${sources})

target_include_directories(matrix_class
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
)
target_link_libraries(matrix_class PRIVATE matrixlibso)

add_custom_command(TARGET matrix_class PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "HEEEEYYYYYYYYYYYYYYYYYY!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
    COMMAND ${CMAKE_COMMAND} -E make_directory -p ../../exe/libs/libmatrixlib
    COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_BINARY_DIR}/../lib/libmatrixlibso.so ../../exe/libs/libmatrixlib
    COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_BINARY_DIR}/../lib/libmatrixlibst.a ../../exe/libs/libmatrixlib
)
