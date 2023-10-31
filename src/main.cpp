#include "board.h"
#include "fen.h"

#include <windows.h>

int main() {
  SetConsoleOutputCP(65001);

  Board board(fen::string_to_board("8/3k4/8/3Q4/8/3K4/8/8 w - - 0 1"));
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