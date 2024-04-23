#include "../chess/board.h"
#include "../chess/move_gen.h"
#include "tests.h"

namespace tests {

U64 perft_internal(Board &board, int depth, int start_depth) {
  auto moves = move_gen::moves(MoveType::kAll, board);

  auto &state = board.get_state();
  U64 total_nodes = 0;

  for (int i = 0; i < moves.size(); i++) {
    const auto move = moves[i];
    if (!board.is_move_legal(move))
      continue;

    U64 child_nodes;
    if (depth == 1) {
      // bulk counting
      total_nodes += child_nodes = 1;
    } else {
      board.make_move(move);
      total_nodes += child_nodes = perft_internal(board, depth - 1, start_depth);
      board.undo_move();
    }

    if (depth == start_depth) {
      std::cout << std::format("{}: {}\n", move.to_string(), child_nodes);
    }
  }

  return total_nodes;
}

void perft(Board &board, int depth) {
  assert(depth >= 0);

  const auto start_time = std::chrono::steady_clock::now();
  const U64 nodes = perft_internal(board, depth, depth);
  const auto elapsed = duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time).count() / 1000.0;

  std::cout << std::format("info nodes {} time {} nps {}", nodes, elapsed * 1000.0, static_cast<U64>(nodes / elapsed)) << std::endl;
}

void perft_suite() {
  // todo: implement this
}

}