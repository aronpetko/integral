cmake_minimum_required(VERSION 3.25)
project(integral)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS_DEBUG "-O0")

file(GLOB SOURCES "src/*.cpp")

add_executable(integral src/main.cpp ${SOURCES}
        src/magics/magic_finder.cpp
        src/magics/magic_finder.h
        src/magics/attacks.cpp
        src/magics/attacks.h
        src/magics/entry.h
        src/magics/precomputed.h)

target_link_options(integral PRIVATE)