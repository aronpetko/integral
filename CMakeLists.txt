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

# Function to check for AVX support
function(check_avx_support)
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|AMD64|i686|i386")
        # Check for AVX512 support
        check_cxx_compiler_flag("-mavx512f" COMPILER_SUPPORTS_AVX512)
        if(COMPILER_SUPPORTS_AVX512)
            set(AVX_FLAGS "-mavx512f" PARENT_SCOPE)
            set(AVX_DEFINES "-DSIMD -DAVX512" PARENT_SCOPE)
        else()
            # Check for AVX2 support
            check_cxx_compiler_flag("-mavx2" COMPILER_SUPPORTS_AVX2)
            if(COMPILER_SUPPORTS_AVX2)
                set(AVX_FLAGS "-mavx2" PARENT_SCOPE)
                set(AVX_DEFINES "-DSIMD -DAVX2" PARENT_SCOPE)
            endif()
        endif()
    endif()
endfunction()

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
    check_avx_support()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native ${AVX_FLAGS}")
    add_definitions(${AVX_DEFINES})
endif ()

# Set debug and release specific flags
set(CMAKE_CXX_FLAGS_RELEASE "-pthread -fopenmp -O3 -funroll-loops -DNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-pthread -fopenmp -g -O0")

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
add_definitions(-DFMT_HEADER_ONLY -DEVALFILE="${PROJECT_SOURCE_DIR}/integral.nnue")

# Collect source files
file(GLOB_RECURSE SOURCES "src/*.cc" "src/*.h")

# Create the executable target
add_executable(integral ${SOURCES} third-party/fathom/tbconfig.h third-party/fathom/tbprobe.h third-party/fathom/stdendian.h third-party/fathom/tbprobe.c src/data_gen/data_gen.h src/data_gen/format/binpack.h)