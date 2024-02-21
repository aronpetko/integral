#include "board.h"
#include "fen.h"
#include "move_gen.h"

int main() {
  Board board(fen::string_to_board("rnbqkbnr/ppp1pppp/8/1Q1p4/3P4/8/PPP1PPPP/RNB1KBNR b KQkq - 0 1"));
  print_pieces(board.get_state()->pieces);

  std::string move;
  while (std::cin >> move) {
    if (move == "undo") {
      board.undo_move();
      print_pieces(board.get_state()->pieces);
      continue;
    }

    board.make_move(algebraic_to_move(move));
    print_pieces(board.get_state()->pieces);
  }
}