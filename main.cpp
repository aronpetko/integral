#include "board.h"
#include "fen.h"

int main() {
  Board board(fen::string_to_board(fen::kStartFen));
  board.make_move(Move(0, 30));
  print_bb(board.get_state()->pieces[kAllPieces]);
  // board.undo_move();
  std::cout << fen::board_to_string(board.get_state()) << std::endl << fen::kStartFen;
}