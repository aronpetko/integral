#ifndef INTEGRAL_TESTS_H
#define INTEGRAL_TESTS_H

#include <fmt/format.h>

#include <chrono>
#include <ranges>
#include <sstream>
#include <vector>

#include "../utils/string.h"

class Board;
class Search;

namespace tests {

constexpr int kDefaultBenchDepth = 12;

void BenchSuite(int depth, bool sparsity_fens = false);

void SEESuite();

void PerftSuite();

void Perft(Board &board, int depth);

}  // namespace tests

#endif  // INTEGRAL_TESTS_H