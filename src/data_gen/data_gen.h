#ifndef INTEGRAL_DATAGEN_H
#define INTEGRAL_DATAGEN_H

#include <atomic>

#include "../utils/types.h"

// Data generation is the process by how Integral creates data in order to train
// its evaluation. Integral plays many games against itself and when a suitable
// position occurs in a game, it will store it in a list. At the end of this
// game, the data is then written to a file with the WDL (outcome) of the game.
namespace data_gen {

inline std::atomic<bool> stop = false;

struct Config {
  U64 soft_node_limit = 0;
  U64 hard_node_limit = 0;
  U64 num_games = 0;
  I32 num_threads = 0;
  I32 min_move_plies = 8, max_move_plies = 9;
  std::string output_file;
  std::string fens_file;
};

void Generate(Config config);

}  // namespace data_gen

#endif  // INTEGRAL_DATAGEN_H