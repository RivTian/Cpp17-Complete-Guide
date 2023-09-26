cmake_minimum_required(VERSION 3.21)

project(
        "Cpp17_Guide"
        VERSION 1.0
        DESCRIPTION
        "The 'build-all' instructions for all examples for the book C++17 - The Complete Guide"
        LANGUAGES CXX
)
include(CTest)

set(CMAKE_BUILD_TYPE
        "Debug"
        CACHE STRING "Default build type for single-config generators"
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#打印生成器类型和生成类型（如果适用）
get_property(
        is_multi_config_generator GLOBAL
        PROPERTY GENERATOR_IS_MULTI_CONFIG
)
if (NOT is_multi_config_generator)
    message(STATUS "Using a single-config generator (${CMAKE_GENERATOR})")
    message(STATUS "Current build type is `${CMAKE_BUILD_TYPE}`")
else ()
    message(STATUS "Using a multi-config generator (${CMAKE_GENERATOR})")
endif ()

find_program(CCACHE_PROGRAM ccache)
if (CCACHE_PROGRAM)
    set(CMAKE_C_COMPILER_LAUNCHER ${CCACHE_PROGRAM})
    set(CMAKE_CXX_COMPILER_LAUNCHER ${CCACHE_PROGRAM})
endif ()

add_subdirectory(simple_executable)