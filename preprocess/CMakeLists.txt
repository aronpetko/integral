cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

# Build options for different architectures
option(BUILD_NATIVE "Build with native optimizations" ${PREPROCESS_BUILD_NATIVE})
option(BUILD_VNNI512 "Build with AVX512 VNNI support" ${PREPROCESS_BUILD_VNNI512})
option(BUILD_AVX512 "Build with AVX512 optimizations" ${PREPROCESS_BUILD_AVX512})
option(BUILD_AVX2_BMI2 "Build with AVX2 + BMI2 optimizations" ${PREPROCESS_BUILD_AVX2_BMI2})
option(BUILD_AVX2 "Build with AVX2 optimizations" ${PREPROCESS_BUILD_AVX2})
option(BUILD_SSE41_POPCNT "Build with SSE4.1 + POPCNT optimizations" ${PREPROCESS_BUILD_SSE41_POPCNT})
option(BUILD_DEBUG "Build with debug information" ${PREPROCESS_BUILD_DEBUG})
option(SPARSE_PERMUTE "Use sparse permute network format" ${PREPROCESS_SPARSE_PERMUTE})

# Architecture-specific flags
set(CXXFLAGS_NATIVE "-march=native")
set(CXXFLAGS_VNNI512 "-march=znver4 -mtune=znver4 -DBUILD_VNNI512 -DBUILD_FAST_PEXT")
set(CXXFLAGS_AVX512 "-march=x86-64-v4 -mtune=skylake-avx512 -DBUILD_AVX512 -DBUILD_FAST_PEXT")
set(CXXFLAGS_AVX2_BMI2 "-march=haswell -mtune=haswell -mavx2 -mbmi2 -DBUILD_AVX2_BMI2 -DBUILD_FAST_PEXT")
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
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXXFLAGS_NATIVE} -DBUILD_NATIVE")
endif ()

# Include third-party directories
include_directories(../third-party/fathom)
include_directories(../third-party/fmt/include)
add_definitions(-DFMT_HEADER_ONLY)

add_executable(preprocess net_processing.cc)