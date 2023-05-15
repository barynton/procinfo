cmake_minimum_required(VERSION 3.22.1 FATAL_ERROR)
project(procinfo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

add_subdirectory(core)
add_subdirectory(test_core)

add_subdirectory(cli)