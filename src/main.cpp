#include "board.h"
#include "fen.h"

int main() {
  Board board(fen::string_to_board(fen::kStartFen));

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