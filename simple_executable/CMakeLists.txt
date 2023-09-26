cmake_minimum_required(VERSION 3.21)

# Define a CMake project
project(
        simple_executable
        VERSION 1.0
        DESCRIPTION "A simple C++ project to demonstrate basic CMake usage"
        LANGUAGES CXX)


# find_package(fmt CONFIG REQUIRED)
find_package(fmt QUIET)
if (NOT fmt_FOUND)
    message(WARNING "fmt not found, skipping vcpkg example")
endif ()

add_executable(simple_executable_with_vcpkg)

target_compile_features(
        simple_executable_with_vcpkg
        PRIVATE cxx_std_17
)

target_sources(
        simple_executable_with_vcpkg
        PRIVATE src/main.cpp
)

target_link_libraries(
        simple_executable_with_vcpkg
        PRIVATE fmt::fmt
)