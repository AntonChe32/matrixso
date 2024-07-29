cmake_minimum_required(VERSION 3.22)
project(
    Matrix
    VERSION 0.0.1
    DESCRIPTION "Matrix lib"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)

set(sources
    src/c/api.cpp
    src/c/api.h
    src/matrix.h
    src/matrix.cpp
    src/export.h
)

include(GenerateExportHeader)

add_library(matrixlibst STATIC ${sources})

generate_export_header(matrixlibst 
    EXPORT_FILE_NAME "${PROJECT_BINARY_DIR}/export_st.h"
    BASE_NAME matrixlib
)


target_compile_definitions(
    matrixlibst
    PUBLIC
        MATRIX_STATIC_DEFINED    
)

target_sources(matrixlibst PRIVATE ${sources})

target_include_directories(matrixlibst
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
)

add_library(matrixlibso SHARED ${sources})

generate_export_header(matrixlibso
    EXPORT_FILE_NAME "${PROJECT_BINARY_DIR}/export_so.h"
    BASE_NAME matrixlib
)


target_sources(matrixlibso PRIVATE ${sources})

target_include_directories(matrixlibso
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
)

