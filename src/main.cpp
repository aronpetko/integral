#include "board.h"
#include "fen.h"

#include <windows.h>

int main() {
  SetConsoleOutputCP(65001);

  Board board(fen::string_to_board("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQK2R w KQkq - 0 1"));
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