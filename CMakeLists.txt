cmake_minimum_required(VERSION 3.25)
project(integral)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -march=native -funroll-loops -DNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-O0")

file(GLOB SOURCES "src/*.cpp" "src/magics/*.cpp")

add_executable(integral ${SOURCES}
        src/move_picker.cpp
        src/move_picker.h src/list.h)

target_link_options(integral PRIVATE)