cmake_minimum_required(VERSION 3.22.1 FATAL_ERROR)

add_library(core
    CpuInformation.cpp
)

message("CMAKE_CXX_COMPILER_ID:" ${CMAKE_CXX_COMPILER_ID})

if (CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
    target_sources(core
    PRIVATE 
        CpuCycles.cpp
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_sources(core
    PRIVATE 
        CpuCycles.cpp
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_sources(core
    PRIVATE 
        CpuCyclesMsvc.cpp
    )
endif()

target_include_directories(core 
PUBLIC
    ./include
)

target_link_libraries(core
PRIVATE
    CONAN_PKG::cpuinfo
)