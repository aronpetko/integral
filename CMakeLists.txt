cmake_minimum_required(VERSION 3.22)
project(integral)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_VERBOSE_MAKEFILE ON)

include(CheckCXXCompilerFlag)

# Options for different build types
option(BUILD_X86_64 "Build with x86-64 optimization" OFF)
option(BUILD_X86_64_MODERN "Build with x86-64 modern optimization" OFF)
option(BUILD_X86_64_BMI2 "Build with x86-64 bmi2 optimization" OFF)

# Set compiler flags based on the selected build type
if(BUILD_X86_64)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mtune=znver1 -msse -msse2 -mpopcnt")
endif()

if(BUILD_X86_64_MODERN)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mtune=znver2 -m64 -msse -msse3 -mpopcnt")
endif()

if(BUILD_X86_64_BMI2)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=haswell -DUSE_AVX2 -mavx2 -mbmi2")
endif()

# Native optimization option
option(BUILD_NATIVE "Build with native optimizations" OFF)

if(BUILD_NATIVE)
    # Check for AVX512 support
    check_cxx_compiler_flag("-mavx512f -mavx512bw" COMPILER_SUPPORTS_AVX512BW)
    if(COMPILER_SUPPORTS_AVX512BW)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DUSE_AVX512 -mavx512f -mavx512bw")
    else()
        # Check for AVX2 support
        check_cxx_compiler_flag("-mavx2 -mbmi" COMPILER_SUPPORTS_AVX2)
        if(COMPILER_SUPPORTS_AVX2)
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DUSE_AVX2 -mavx2 -mbmi")
        endif()
    endif()

    # General native flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
endif()

# Set debug and release specific flags
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -flto -DNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-O0")

# Conditionally add static linking flag on Windows
if(WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
endif()

# Collect source files
file(GLOB SOURCES "src/*.cc" "src/magics/*.cc" "src/chess/*.cc" "src/engine/*.cc" "src/utils/*.cc" "src/tests/*.cc")
add_executable(integral ${SOURCES})