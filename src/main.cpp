#include "board.h"
#include "fen.h"

int main() {
  Board board(fen::string_to_board("r3k2r/p6p/8/8/8/8/P6P/R3K2R w KQkq - 0 1"));

  std::string command;
  while (true) {
    print_pieces(board.get_state()->pieces);

    std::getline(std::cin, command);
    if (command == "exit") {
      break;
    } else if (command == "undo") {
      board.undo_move();
    } else {
      auto parsed_move = algebraic_to_pos(command);
      if (!parsed_move) {
        std::cerr << "this is an invalid move or command" << std::endl;
        continue;
      }

      auto [from, to] = parsed_move.value();
      board.make_move({from, to, get_piece_type(from, board.get_state()->pieces)});
    }
  }
}