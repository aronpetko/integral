#include "board.h"
#include "fen.h"

#ifdef WIN32
#include <windows.h>
#endif

int main() {
#ifdef WIN32
  SetConsoleOutputCP(CP_UTF8);
#endif

  Board board(fen::string_to_board("rnbqkbnr/pppppppp/8/4P3/8/8/PPPP1PPP/RNBQKBNR b KQkq - 0 1"));

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