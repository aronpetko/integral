cmake_minimum_required(VERSION 3.16)
project(integral)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_VERBOSE_MAKEFILE OFF)

include(CheckCXXCompilerFlag)

# Options for different build types
option(BUILD_X86_64_POPCNT "Build with x86-64-popcnt optimizations" OFF)
option(BUILD_X86_64_MODERN "Build with x86-64 modern optimizations" OFF)
option(BUILD_X86_64_BMI2 "Build with x86-64 bmi2 optimizations" OFF)
option(BUILD_DEBUG "Build with debug information" OFF)
option(BUILD_NATIVE "Build with native optimizations" ON)

# Set the build type
if (BUILD_DEBUG)
    set(CMAKE_BUILD_TYPE Debug)
elseif (BUILD_X86_64_POPCNT)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mtune=sandybridge -mpopcnt")
elseif (BUILD_X86_64_MODERN)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mtune=znver2 -msse -msse3")
elseif (BUILD_X86_64_BMI2)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mtune=haswell -mavx2 -mbmi2")
elseif (BUILD_NATIVE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
endif ()

# Set debug and release specific flags
set(CMAKE_CXX_FLAGS_RELEASE "-pthread -O3 -funroll-loops -DNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-pthread -fopenmp -O1")

include(CheckIPOSupported)
check_ipo_supported(RESULT LTO_SUPPORTED)

if (LTO_SUPPORTED)
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELEASE ON)
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELWITHDEBINFO OFF)
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_DEBUG OFF)
endif ()

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libstdc++")
endif ()

# Conditionally add static linking flag on Windows
if (WIN32)
    if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,/STACK:8388608")
    endif ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
endif ()

include_directories(third-party/fathom)
include_directories(third-party/fmt/include)
add_definitions(-DFMT_HEADER_ONLY)

# Collect source files
file(GLOB_RECURSE SOURCES "src/*.cc" "src/*.h")

# Create the executable target
add_executable(integral ${SOURCES} third-party/fathom/tbconfig.h third-party/fathom/tbprobe.h third-party/fathom/stdendian.h third-party/fathom/tbprobe.c)