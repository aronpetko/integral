#include "board.h"
#include "fen.h"
#include "move_gen.h"

int main() {
  Board board(fen::string_to_board("k7/8/8/8/8/8/8/R3K2R w KQ - 0 1"));
  print_pieces(board.get_state()->pieces);

  std::string move;
  while (std::cin >> move) {
    if (move == "undo") {
      board.undo_move();
      print_pieces(board.get_state()->pieces);
      continue;
    }

    auto [from, to] = algebraic_to_pos(move);
    board.make_move({from, to, get_piece_type(from, board.get_state()->pieces)});

    print_pieces(board.get_state()->pieces);
  }
}