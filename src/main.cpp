#include "board.h"
#include "fen.h"
#include "move_gen.h"

#include <chrono>
#include <iomanip>
#include <map>

#ifdef WIN32
#include <windows.h>
#endif

inline std::vector<std::pair<std::string, int>> poses;

unsigned long perft(Board &board, int depth) {
  if (!depth)
    return 1;

  const auto moves = generate_moves(board.get_state());

  unsigned long positions = 0;
  for (const auto& move : moves) {
    if (!board.is_legal_move(move))
      continue;

    board.make_move(move, true, depth);
    positions += perft(board, depth - 1);
    board.undo_move();
  }

  return positions;
}

int main() {
#ifdef WIN32
  SetConsoleOutputCP(CP_UTF8);
#endif

  Board board(fen::string_to_board(fen::kStartFen));

  const auto start = std::chrono::high_resolution_clock::now();
  const int perft_nodes = perft(board, 6);
  const auto end = std::chrono::high_resolution_clock::now();
  const auto elapsed = std::chrono::duration<double>(end - start).count();

  std::cout << "+-+-+-+-+-+-+-+-+" << std::endl;
  std::cout << "Nodes: " << perft_nodes << std::endl;
  std::cout << "Captures: " << captures << std::endl;
  std::cout << "En Passants: " << en_passant_captures << std::endl;
  std::cout << "Castles: " << castles << std::endl;
  std::cout << "Promotions: " << promotions << std::endl;
  std::cout << "Checks: " << checks << std::endl;
  std::cout << std::endl << "Took " << std::fixed << std::setprecision(2) << elapsed << "s" << std::endl;
  std::cout << "NPS: " << perft_nodes / elapsed << std::endl;

  std::cout << "+-+-+-+-+-+-+-+-+" << std::endl << std::endl;

  sort(poses.begin(), poses.end());
  for (const auto& [move, nodes] : poses) {
    // std::cout << move + ": " << nodes << std::endl;
  }

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

      if (board.is_legal_move(move.value()))
        board.make_move(move.value());
    }
  }
}