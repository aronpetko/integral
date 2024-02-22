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
      auto move = Move::from_str(command);
      if (!move) {
        std::cerr << "this is an invalid move or command" << std::endl;
        continue;
      }

      move->set_piece_type(get_piece_type(move->get_from(), board.get_state()->pieces));
      board.make_move(move.value());
    }
  }
}