#include <iostream>

import board;
import fen;

int main() {
  Board board(fen::string_to_board(fen::kStartFen));
  std::cout << fen::board_to_string(board.get_state()) << std::endl << fen::kStartFen;
}