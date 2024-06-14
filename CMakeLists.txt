cmake_minimum_required(VERSION 3.22)
project(integral)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_VERBOSE_MAKEFILE ON)

include(CheckCXXCompilerFlag)

# Options for different build types
option(BUILD_X86_64 "Build with x86-64 optimization" OFF)
option(BUILD_X86_64_MODERN "Build with x86-64 modern optimization" OFF)
option(BUILD_X86_64_BMI2 "Build with x86-64 bmi2 optimization" OFF)
option(BUILD_DEBUG "Build with debug information" OFF)
option(BUILD_NATIVE "Build with native optimizations" ON)

# Set the build type
if(BUILD_DEBUG)
    set(CMAKE_BUILD_TYPE Debug)
elseif(BUILD_X86_64)
    set(CMAKE_BUILD_TYPE Release)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mtune=znver1 -msse -msse2 -mpopcnt")
elseif(BUILD_X86_64_MODERN)
    set(CMAKE_BUILD_TYPE Release)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mtune=znver2 -m64 -msse -msse3 -mpopcnt")
elseif(BUILD_X86_64_BMI2)
    set(CMAKE_BUILD_TYPE Release)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=haswell -DUSE_AVX2 -mavx2 -mbmi2")
elseif(BUILD_NATIVE)
    set(CMAKE_BUILD_TYPE Release)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
endif()

# Set debug and release specific flags
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -fopenmp -flto -fomit-frame-pointer -std=gnu++2a -DNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-O2 -g")

# Conditionally add static linking flag on Windows
if(WIN32)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,16777216")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
endif()

add_subdirectory(third-party/fmt)
include_directories(third-party/fmt/include)
add_definitions(-DFMT_HEADER_ONLY)

# Collect source files
file(GLOB SOURCES "src/*.cc" "src/magics/*.cc" "src/tuner/*.cc" "src/chess/*.cc" "src/engine/*.cc" "src/utils/*.cc" "src/tests/*.cc")

add_executable(integral ${SOURCES} src/tuner/tuner.cc)