#include "board.h"
#include "fen.h"

#include <windows.h>

int main() {
  SetConsoleOutputCP(65001);

  Board board(fen::string_to_board(fen::kStartFen));
  print_pieces(board.get_state()->pieces);

  std::string move;
  while (std::cin >> move) {
    if (move == "undo") {
      board.undo_move();
      //clear();
      print_pieces(board.get_state()->pieces);
      continue;
    }

    board.make_move(algebraic_to_move(move));
   // clear();
    print_pieces(board.get_state()->pieces);
  }
}