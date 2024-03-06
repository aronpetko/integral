#include "board.h"
#include "fen.h"
#include "move_gen.h"
#include "eval.h"
#include "search.h"
#include "zobrist.h"

#include <chrono>
#include <iomanip>

#ifdef WIN32
#include <windows.h>
#endif

int perft_helper(Board &board, int depth) {
  if (!depth)
    return 1;

  auto &state = board.get_state();

  int positions = 0;
  for (const auto &move : generate_moves(state)) {
    board.make_move(move, true, depth);
    const bool in_check = king_in_check(Color(!state.turn), state);
    if (!in_check) positions += perft_helper(board, depth - 1);
    board.undo_move();
  }

  return positions;
}

void perft(Board &board, int depth) {
  const auto start = std::chrono::high_resolution_clock::now();
  const int perft_nodes = perft_helper(board, depth);
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
}

int main() {
#ifdef WIN32
  SetConsoleOutputCP(CP_UTF8);
#endif

  initialize_ray_attacks();

  Board board(fen::string_to_board(fen::kStartFen));

  std::string command;
  while (true) {
    std::cout << "\nthinking... end_game: " << board.get_state().is_end_game() << "\n";
    const auto start = std::chrono::high_resolution_clock::now();
    auto best_response = search::find_best_move(board);
    const auto end = std::chrono::high_resolution_clock::now();
    const auto elapsed = std::chrono::duration<double>(end - start).count();
    std::cout << "found best move in: " << elapsed << " | nps: " << std::fixed << std::setprecision(2) << (double)search::nodes_searched / (double)elapsed << std::endl;
    std::cout << "computer move: " << best_response.to_string() << std::endl;
    board.make_move(best_response);

    print_pieces(board.get_state().pieces);

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

      move->set_piece_type(get_piece_type(move->get_from(), board.get_state().pieces));

      if (board.is_legal_move(move.value())) {
        board.make_move(move.value());
      }
    }
  }
}