cmake_minimum_required(VERSION 3.8)
project(variant LANGUAGES C CXX)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE debug)
endif()

include(CheckCXXCompilerFlag)
include(CheckCCompilerFlag)
include(CheckIncludeFile)
include(GNUInstallDirs)

option(ENABLE_TEST        "Default to disable test function"     OFF)
option(BUILD_SHARED_LIBS  "Default to building shared libraries" ON)
option(BUILD_STATIC_LIBS  "Default to building static libraries" ON)

check_c_compiler_flag("-Wall"               FLAG_SUPPORTED_WALL)
check_c_compiler_flag("-Werror"             FLAG_SUPPORTED_WERROR)
check_c_compiler_flag("-Wextra"             FLAG_SUPPORTED_WEXTRA)
check_c_compiler_flag("-Wpedantic"          FLAG_SUPPORTED_WPEDANTIC)
check_c_compiler_flag("-Wunused-variable"   FLAG_SUPPORTED_WUNUSED_VARIABLE)
check_c_compiler_flag("-Wconversion"        FLAG_SUPPORTED_WCONVERSION)
check_c_compiler_flag("-fvisibility=hidden" FLAG_SUPPORTED_VISIBILITY)
check_c_compiler_flag("-std=c11"            FLAG_SUPPORTED_STDC11)

check_include_file("stdbool.h"              HAS_STDBOOL_H)
check_include_file("stdint.h"               HAS_STDLIB_H)
check_include_file("stdio.h"                HAS_STDIO_H)
check_include_file("stdlib.h"               HAS_STDLIB_H)
check_include_file("string.h"               HAS_STRING_H)

set(CMAKE_CXX_STANDARD              17)
set(CMAKE_CXX_STANDARD_REQUIRED     ON)

include_directories(${CMAKE_SOURCE_DIR}/include)
add_library(${PROJECT_NAME} variant.cc
                            include/variant.h
)

target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<BOOL:${FLAG_SUPPORTED_WALL}>:-Wall>
    $<$<BOOL:${FLAG_SUPPORTED_WERROR}>:-Werror>
    $<$<BOOL:${FLAG_SUPPORTED_WEXTRA}>:-Wextra>
    $<$<BOOL:${FLAG_SUPPORTED_WPEDANTIC}>:-Wpedantic>
    $<$<BOOL:${FLAG_SUPPORTED_WUNUSED_VARIABLE}>:-Wunused-variable>
    $<$<BOOL:${FLAG_SUPPORTED_WCONVERSION}>:-Wconversion>
    $<$<BOOL:${FLAG_SUPPORTED_VISIBILITY}>:-fvisibility=hidden>
)

target_include_directories(
    ${PROJECT_NAME}
        PRIVATE
            ${CMAKE_SOURCE_DIR}/include
)

if(ENABLE_TEST)
    set(CMAKE_C_STANDARD                11)
    set(CMAKE_C_STANDARD_REQUIRED       ON)
    add_subdirectory(${CMAKE_SOURCE_DIR}/test)
endif()

if(TARGET ${PROJECT_NAME})
    install(FILES ${PROJECT_SOURCE_DIR}/include/variant.h
            DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
    )

    install(TARGETS ${PROJECT_NAME}
            RUNTIME       DESTINATION ${CMAKE_INSTALL_BINDIR}
            LIBRARY       DESTINATION ${CMAKE_INSTALL_LIBDIR}
            ARCHIVE       DESTINATION ${CMAKE_INSTALL_LIBDIR}
            PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
    )
endif()

