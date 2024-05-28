#ifndef INTEGRAL_TESTS_H
#define INTEGRAL_TESTS_H

#include <chrono>
#include <fmt/format.h>
#include <ranges>
#include <sstream>
#include <vector>

#include "../utils/string.h"

class Board;
class Search;

namespace tests {

void BenchSuite(Board &board, Search &search, int depth);

void SEESuite();

void PerftSuite();

void Perft(Board &board, int depth);

}  // namespace tests

#endif  // INTEGRAL_TESTS_H