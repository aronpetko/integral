#ifndef INTEGRAL_TESTS_H
#define INTEGRAL_TESTS_H

#include <ranges>
#include <format>
#include <sstream>
#include <vector>
#include <chrono>
#include "../utils/string.h"

class Board;

namespace tests {

void bench_suite(int depth);

void see_suite();

void perft_suite();

void perft(Board &board, int depth);

}

#endif // INTEGRAL_TESTS_H