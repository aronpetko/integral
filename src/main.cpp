#include "board.h"
#include "fen.h"
#include "move_gen.h"
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
  for (const auto &move : generate_moves(board)) {
    board.make_move(move, true, depth);
    const bool in_check = king_in_check(flip_color(state.turn), state);
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
  /* std::cout << "Captures: " << captures << std::endl;
  std::cout << "En Passants: " << en_passant_captures << std::endl;
  std::cout << "Castles: " << castles << std::endl;
  std::cout << "Promotions: " << promotions << std::endl;
  std::cout << "Checks: " << checks << std::endl; */
  std::cout << std::endl << "Took " << std::fixed << std::setprecision(2) << elapsed << "s" << std::endl;
  std::cout << "NPS: " << perft_nodes / elapsed << std::endl;

  std::cout << "+-+-+-+-+-+-+-+-+" << std::endl << std::endl;
}

int main() {
#ifdef WIN32
  SetConsoleOutputCP(CP_UTF8);
#endif

  // initialize bishop/rook attacks the move generator
  initialize_ray_attacks();

  const int kTranspositionTableMbSize = 64;
  Board board(fen::string_to_board(fen::kStartFen), kTranspositionTableMbSize);

  std::string command;
  while (true) {
    std::cout << "started search" << std::endl;

    const auto best_response = search::find_best_move(board);
    board.make_move(best_response);

    std::cout << "computer move: " << best_response.to_string() << std::endl;

  get_move:
    print_pieces(board.get_state().pieces);

    std::getline(std::cin, command);
    if (command == "exit") {
      break;
    } else if (command == "undo") {
      board.undo_move();
      goto get_move;
    } else {
      auto move = Move::from_str(command);
      if (!move) {
        std::cerr << "this is an invalid move or command" << std::endl;
        goto get_move;
      }

      move->set_piece_type(get_piece_type(move->get_from(), board.get_state().pieces));

      if (board.is_legal_move(move.value())) {
        board.make_move(move.value());
      } else {
        goto get_move;
      }
    }
  }
}