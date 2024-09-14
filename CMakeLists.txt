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

include(CheckCXXCompilerFlag)
include(CheckCXXSourceRuns)

function(check_avx_support)
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|AMD64|i686|i386")
        # Function to detect AVX support
        function(detect_avx FEATURE FLAGS RESULT)
            set(AVX_CODE "
                #include <immintrin.h>
                int main() {
                    ${FEATURE}
                    return 0;
                }")

            # First, try without any flags
            check_cxx_source_runs("${AVX_CODE}" AVX_RUNS)

            if(NOT AVX_RUNS)
                # If it doesn't run, try with the specified flags
                set(CMAKE_REQUIRED_FLAGS "${FLAGS}")
                check_cxx_source_runs("${AVX_CODE}" AVX_RUNS_WITH_FLAG)
                unset(CMAKE_REQUIRED_FLAGS)

                if(AVX_RUNS_WITH_FLAG)
                    set(${RESULT} "${FLAGS}" PARENT_SCOPE)
                else()
                    set(${RESULT} "UNAVAILABLE" PARENT_SCOPE)
                endif()
            else()
                # AVX is supported without any special flags
                set(${RESULT} "AVAILABLE" PARENT_SCOPE)
            endif()
        endfunction()

        # Check for AVX512 support
        check_cxx_compiler_flag("-mavx512f" COMPILER_SUPPORTS_AVX512F)
        check_cxx_compiler_flag("-mavx512dq" COMPILER_SUPPORTS_AVX512DQ)
        check_cxx_compiler_flag("-mavx512bw" COMPILER_SUPPORTS_AVX512BW)
        check_cxx_compiler_flag("-mavx512vl" COMPILER_SUPPORTS_AVX512VL)

        if(COMPILER_SUPPORTS_AVX512F AND COMPILER_SUPPORTS_AVX512DQ AND
                COMPILER_SUPPORTS_AVX512BW AND COMPILER_SUPPORTS_AVX512VL)
            set(AVX512_FLAGS "-mavx512f -mavx512dq -mavx512bw -mavx512vl")
            detect_avx(
                    "__m512i a = _mm512_set1_epi32(1); __m512i b = _mm512_set1_epi32(2); __m512i c = _mm512_add_epi32(a, b); return _mm256_extract_epi32(_mm512_extracti64x4_epi64(c, 0), 0) == 3 ? 0 : 1;"
                    "${AVX512_FLAGS}"
                    AVX512_SUPPORT
            )

            if(NOT AVX512_SUPPORT STREQUAL "UNAVAILABLE")
                set(AVX_FLAGS "${AVX512_SUPPORT}" PARENT_SCOPE)
                set(AVX_DEFINES "-DSIMD -DAVX512" PARENT_SCOPE)
                message(STATUS "AVX512 is supported: ${AVX512_SUPPORT}")
                return()
            endif()
        endif()

        # Check for AVX2 support
        check_cxx_compiler_flag("-mavx2" COMPILER_SUPPORTS_AVX2)
        check_cxx_compiler_flag("-mfma" COMPILER_SUPPORTS_FMA)

        if(COMPILER_SUPPORTS_AVX2)
            set(AVX2_FLAGS "-mavx2")
            if(COMPILER_SUPPORTS_FMA)
                set(AVX2_FLAGS "${AVX2_FLAGS} -mfma")
            endif()

            detect_avx(
                    "__m256i a = _mm256_set1_epi32(1); __m256i b = _mm256_set1_epi32(2); __m256i c = _mm256_add_epi32(a, b); return _mm256_extract_epi32(c, 0) == 3 ? 0 : 1;"
                    "${AVX2_FLAGS}"
                    AVX2_SUPPORT
            )

            if(NOT AVX2_SUPPORT STREQUAL "UNAVAILABLE")
                set(AVX_FLAGS "${AVX2_SUPPORT}" PARENT_SCOPE)
                set(AVX_DEFINES "-DSIMD -DAVX2" PARENT_SCOPE)
                message(STATUS "AVX2 is supported: ${AVX2_SUPPORT}")
                return()
            endif()
        endif()

        message(STATUS "Neither AVX512 nor AVX2 is supported on this system")
    else()
        message(WARNING "AVX support check skipped for unsupported processor architecture: ${CMAKE_SYSTEM_PROCESSOR}")
    endif()
endfunction()

check_avx_support()
if(DEFINED AVX_FLAGS)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${AVX_FLAGS}")
endif()
if(DEFINED AVX_DEFINES)
    add_definitions(${AVX_DEFINES})
endif()

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
set(CMAKE_CXX_FLAGS_RELEASE "-pthread -O3 -funroll-loops -DNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-pthread -g -O0")

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