cmake_minimum_required(VERSION 3.16)
project(integral)

# Set the C++ standard and verbosity
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_VERBOSE_MAKEFILE ON)

# Include necessary modules
include(CheckCXXCompilerFlag)
include(CheckCXXSourceRuns)
include(CheckIPOSupported)

# Build options for different architectures
set(BUILD_NATIVE ON)
option(BUILD_NATIVE "Build with native optimizations" ON)
option(BUILD_VNNI512 "Build with AVX512 VNNI support" OFF)
option(BUILD_AVX512 "Build with AVX512 optimizations" OFF)
option(BUILD_AVX2_BMI2 "Build with AVX2 + BMI2 optimizations" OFF)
option(BUILD_AVX2 "Build with AVX2 optimizations" OFF)
option(BUILD_SSE41_POPCNT "Build with SSE4.1 + POPCNT optimizations" OFF)
option(BUILD_DEBUG "Build with debug information" OFF)

# Allow user to specify EVALFILE through CMake
set(NETWORK_NAME zekrom-v6)
set(EVALFILE "${EVALFILE}" CACHE STRING "Path to the evaluation (.nnue) file")
set(NNUE_URL "https://github.com/aronpetko/integral-networks/releases/download/${NETWORK_NAME}/${NETWORK_NAME}.nnue")
set(NNUE_PATH "${PROJECT_SOURCE_DIR}/${NETWORK_NAME}.nnue")

# Define the location to download the .nnue file if not provided
if (NOT EVALFILE)
    # Check if the .nnue file exists, if not, download it
    if (NOT EXISTS ${NNUE_PATH})
        message(STATUS "${NETWORK_NAME}.nnue not found. Downloading from ${NNUE_URL}...")
        file(DOWNLOAD ${NNUE_URL} ${NNUE_PATH}
                STATUS DOWNLOAD_STATUS
                SHOW_PROGRESS
        )
        list(GET DOWNLOAD_STATUS 0 DOWNLOAD_STATUS_CODE)
        if (NOT ${DOWNLOAD_STATUS_CODE} EQUAL 0)
            message(FATAL_ERROR "Failed to download ${NETWORK_NAME}.nnue from ${NNUE_URL}")
        endif ()
    else ()
        message(STATUS "${NETWORK_NAME}.nnue already exists. Skipping download.")
    endif ()
    set(EVALFILE ${NNUE_PATH})
else ()
    message(STATUS "Using user-specified EVALFILE: ${EVALFILE}")
endif ()

# Option for preparing the network to sparse permute neurons (requires turning off AVX)
option(SPARSE_PERMUTE OFF)
if (SPARSE_PERMUTE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DSPARSE_PERMUTE")
endif ()

# Define output path for preprocessed file
set(PREPROCESSED_FILE "${CMAKE_CURRENT_BINARY_DIR}/processed.nnue")
set(PREPROCESS_BUILD_NATIVE ${BUILD_NATIVE} CACHE INTERNAL "")
set(PREPROCESS_BUILD_VNNI512 ${BUILD_VNNI512} CACHE INTERNAL "")
set(PREPROCESS_BUILD_AVX512 ${BUILD_AVX512} CACHE INTERNAL "")
set(PREPROCESS_BUILD_AVX2_BMI2 ${BUILD_AVX2_BMI2} CACHE INTERNAL "")
set(PREPROCESS_BUILD_AVX2 ${BUILD_AVX2} CACHE INTERNAL "")
set(PREPROCESS_BUILD_SSE41_POPCNT ${BUILD_SSE41_POPCNT} CACHE INTERNAL "")
set(PREPROCESS_BUILD_DEBUG ${BUILD_DEBUG} CACHE INTERNAL "")
set(PREPROCESS_SPARSE_PERMUTE ${SPARSE_PERMUTE} CACHE INTERNAL "")

# Add subdirectory containing the preprocess project
add_subdirectory(preprocess)

# Custom command to run preprocessing
add_custom_command(
        OUTPUT ${PREPROCESSED_FILE}
        COMMAND preprocess ${EVALFILE} ${PREPROCESSED_FILE}
        DEPENDS preprocess ${EVALFILE}
        COMMENT "Running net preprocessing"
        VERBATIM
)

# Custom target that depends on the output file
add_custom_target(run_preprocess ALL DEPENDS ${PREPROCESSED_FILE})

# Define preprocessed file as a macro so it’s accessible from C++
add_definitions(-DEVALFILE="${PREPROCESSED_FILE}")

# Architecture-specific flags
set(CXXFLAGS_NATIVE "-march=native")
set(CXXFLAGS_VNNI512 "-march=znver4 -mtune=znver4 -DBUILD_VNNI512 -DUSE_PEXT")
set(CXXFLAGS_AVX512 "-march=x86-64-v4 -mtune=skylake-avx512 -DBUILD_AVX512 -DUSE_PEXT")
set(CXXFLAGS_AVX2_BMI2 "-march=haswell -mtune=haswell -mavx2 -mbmi2 -DBUILD_AVX2_BMI2 -DUSE_PEXT")
set(CXXFLAGS_AVX2 "-march=bdver4 -mno-tbm -mno-sse4a -mno-bmi2 -mtune=znver2 -DBUILD_AVX2")
set(CXXFLAGS_SSE41_POPCNT "-march=nehalem -mtune=sandybridge -DBUILD_SSE41_POPCNT")

# Apply the correct flags based on the build type
if (BUILD_DEBUG)
    set(CMAKE_BUILD_TYPE Debug)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")
elseif (BUILD_VNNI512)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXXFLAGS_VNNI512} -DBUILD_VNNI512")
elseif (BUILD_AVX512)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXXFLAGS_AVX512} -DBUILD_AVX512")
elseif (BUILD_AVX2_BMI2)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXXFLAGS_AVX2_BMI2} -DBUILD_AVX2_BMI2")
elseif (BUILD_AVX2)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXXFLAGS_AVX2} -DBUILD_AVX2")
elseif (BUILD_SSE41_POPCNT)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXXFLAGS_SSE41_POPCNT} -DBUILD_SSE41_POPCNT")
elseif (BUILD_NATIVE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXXFLAGS_NATIVE} -DBUILD_NATIVE -DUSE_PEXT")

    execute_process(
            COMMAND ${CMAKE_CXX_COMPILER} -march=native -E -dM -
            INPUT_FILE /dev/null
            OUTPUT_VARIABLE COMPILER_DEFINES
            OUTPUT_STRIP_TRAILING_WHITESPACE
            ERROR_QUIET
    )

    # Debug output
    message(STATUS "Checking for BMI2 support in native build...")

    # Check if BMI2 is supported
    string(FIND "${COMPILER_DEFINES}" "__BMI2__" HAS_BMI2)

    # Also check for specific Zen architectures
    string(FIND "${COMPILER_DEFINES}" "__znver1" IS_ZNVER1)
    string(FIND "${COMPILER_DEFINES}" "__znver2" IS_ZNVER2)
    string(FIND "${COMPILER_DEFINES}" "__znver3" IS_ZNVER3)
    string(FIND "${COMPILER_DEFINES}" "__znver4" IS_ZNVER4)

    if (NOT HAS_BMI2 EQUAL -1)
        # BMI2 is supported
        if (NOT IS_ZNVER3 EQUAL -1 OR NOT IS_ZNVER4 EQUAL -1)
            # Zen 3 and Zen 4 have fast PEXT
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DUSE_PEXT")
            message(STATUS "BMI2 (PEXT) support detected and enabled for Zen 3/4 processor")
        elseif (IS_ZNVER1 EQUAL -1 AND IS_ZNVER2 EQUAL -1)
            # Not znver1 or znver2, so PEXT should be fast (Intel or other)
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DUSE_PEXT")
            message(STATUS "BMI2 (PEXT) support detected and enabled for native build")
        elseif (NOT IS_ZNVER2 EQUAL -1 AND CMAKE_SYSTEM_NAME STREQUAL "Linux")
            # Special case: Check for AMD EPYC 7B on znver2
            execute_process(
                    COMMAND lscpu
                    OUTPUT_VARIABLE LSCPU_OUTPUT
                    ERROR_QUIET
                    OUTPUT_STRIP_TRAILING_WHITESPACE
            )
            string(FIND "${LSCPU_OUTPUT}" "AMD EPYC 7B" IS_EPYC_7B)
            if (NOT IS_EPYC_7B EQUAL -1)
                set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DUSE_PEXT")
                message(STATUS "BMI2 (PEXT) support enabled for AMD EPYC 7B processor")
            else()
                message(STATUS "BMI2 detected but PEXT disabled due to slow implementation on znver2")
            endif()
        else()
            message(STATUS "BMI2 detected but PEXT disabled due to slow implementation on znver1")
        endif()
    endif()
endif ()

option(DATAGEN OFF)
if (DATAGEN)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDATAGEN")
endif ()

# Set common flags for release and debug builds
set(CMAKE_CXX_FLAGS_RELEASE "-pthread -O3 -funroll-loops -DNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-pthread -g -O0")

# Check for Link-Time Optimization (LTO) support
check_ipo_supported(RESULT LTO_SUPPORTED)

if (LTO_SUPPORTED)
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELEASE ON)
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELWITHDEBINFO OFF)
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_DEBUG OFF)
endif ()

# Add Clang-specific flags
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libstdc++")
endif ()

# Static linking on Windows
if (WIN32)
    if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,/STACK:8388608")
    endif ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
endif ()

# Include third-party directories
include_directories(third-party/fathom)
include_directories(third-party/fmt/include)
add_definitions(-DFMT_HEADER_ONLY)

# Collect all source files
file(GLOB_RECURSE SOURCES "src/*.cc" "src/*.h")

# Create the executable
add_executable(integral ${SOURCES}
        third-party/fathom/tbconfig.h
        third-party/fathom/tbprobe.h
        third-party/fathom/stdendian.h
        third-party/fathom/tbprobe.c
        src/data_gen/data_gen.h
        src/data_gen/format/binpack.h
        src/engine/search/cuckoo.cc)

# Make sure main build depends on this
add_dependencies(integral run_preprocess)