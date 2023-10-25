cmake_minimum_required(VERSION 3.25)
project(integral)

set(CMAKE_CXX_STANDARD 20)

add_executable(integral main.cpp board.ixx fen.ixx types.ixx bitboard.ixx)
