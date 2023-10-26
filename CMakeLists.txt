cmake_minimum_required(VERSION 3.25)
project(integral)

set(CMAKE_CXX_STANDARD 17)

add_executable(integral main.cpp board.cpp board.h move.h types.h bitboard.cpp bitboard.h fen.cpp fen.h)