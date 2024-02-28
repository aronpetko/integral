cmake_minimum_required(VERSION 3.25)
project(integral)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_executable(integral src/main.cpp src/board.cpp src/board.h src/move.h src/types.h src/bitboard.h src/fen.cpp src/fen.h src/move_gen.cpp src/move_gen.h
        src/eval.cpp
        src/eval.h
        src/search.cpp
        src/search.h
        src/zobrist.cpp
        src/zobrist.h)

target_link_options(integral PRIVATE)