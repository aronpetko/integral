cmake_minimum_required(VERSION 3.25)
project(integral)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS_RELEASE "-O3 -march=native -mtune=native -DNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-O0")

set(CMAKE_VERBOSE_MAKEFILE ON)

file(GLOB SOURCES "src/*.cc" "src/magics/*.cc" "src/chess/*.cc" "src/engine/*.cc" "src/utils/*.cc" "src/tests/*.cc")
add_executable(integral ${SOURCES})