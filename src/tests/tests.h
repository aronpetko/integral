#ifndef INTEGRAL_TESTS_H
#define INTEGRAL_TESTS_H

#include <ranges>
#include <format>
#include <sstream>
#include <vector>
#include <chrono>
#include "../utils/string.h"

class Board;
class Search;

namespace tests {

void BenchSuite(Board &board, Search &search, int depth);

void SEESuite();

void PerftSuite();

void Perft(Board &board, int depth);

}

#endif // INTEGRAL_TESTS_H