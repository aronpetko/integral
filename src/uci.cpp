#include "uci.h"
#include "move_gen.h"

#include <string>
#include <format>
#include <fstream>

namespace uci {

void position(Board &board, std::stringstream &input_stream) {
  std::string position_type;
  input_stream >> position_type;

  std::string position;
  if (position_type == "fen") {
    position = input_stream.str().substr(static_cast<int>(input_stream.tellg()) + 1);
  } else if (position_type == "startpos") {
    position = fen::kStartFen;
  }

  std::string dummy;
  while (input_stream >> dummy && dummy != "moves");

  std::string move_input;
  while (input_stream >> move_input);

  const int kTranspositionTableMbSize = 64;

  // if no moves were given then this command wants to set a new position
  if (move_input.empty()) {
    board = Board(fen::string_to_board(position), kTranspositionTableMbSize);
  } else {
    if (!board.initialized()) {
      board = Board(fen::string_to_board(position), kTranspositionTableMbSize);
    }

    // we now have the last move sent in the position
    const auto move = Move::from_str(board.get_state(), move_input);
    std::ofstream log("/Users/aron/Desktop/log.txt", std::ios_base::out | std::ios_base::app);
    log << move_input << std::endl;
    log.close();

    if (move.has_value() && board.is_legal_move(move.value())) {
      board.make_move(move.value());
    } else {
      std::cerr << std::format("invalid move: {}\n", move_input);
    }
  }
}

void go(Board &board, std::stringstream &input_stream) {
  TimeManagement::Config time_config{};

  std::string option;

  while (input_stream >> option) {
    if (option == "wtime") {
      input_stream >> time_config.time[Color::kWhite];
    } else if (option == "btime") {
      input_stream >> time_config.time[Color::kBlack];
    } else if (option == "winc") {
      input_stream >> time_config.increment[Color::kWhite];
    } else if (option == "binc") {
      input_stream >> time_config.increment[Color::kBlack];
    } else if (option == "movetime") {
      input_stream >> time_config.move_time;
    } else if (option == "depth") {
      input_stream >> time_config.depth;
    } else if (option == "infinite") {
      time_config.depth = 20;
    } else if (option == "perft") {
      perft(board, input_stream);
      return;
    }
  }

  if (option.empty())
    time_config.depth = 13;

  const Move best_move = Search(time_config, board).find_best_move();
  if (best_move != Move::null_move()) {
    board.make_move(best_move);
  }

  std::cout << std::format("bestmove {}", best_move.to_string()) << std::endl;
}

int perft_internal(Board &board, int depth, int start_depth) {
  if (depth == 0)
    return 1;

  auto &state = board.get_state();

  int nodes = 0;
  auto moves = generate_moves(board);

  for (int i = 0; i < moves.size(); i++) {
    board.make_move(moves[i]);
    if (!king_in_check(flip_color(state.turn), state)) {
      const int pos_nodes = perft_internal(board, depth - 1, start_depth);
      nodes += pos_nodes;

      if (depth == start_depth) {
        std::cout << std::format("{}: {}\n", moves[i].to_string(), pos_nodes);
      }
    }
    board.undo_move();
  }

  return nodes;
}

void perft(Board &board, std::stringstream &input_stream) {
  int depth;

  std::string option;
  if (input_stream >> option && option == "depth") {
    input_stream >> depth;
    assert(depth >= 0);

    const auto start_time = std::chrono::steady_clock::now();
    const int nodes = perft_internal(board, depth, depth);
    const auto elapsed = duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time).count() / 1000.0;

    std::cout << std::format("perft({}): {}\ntook: {:.2f}s\nnps: {}", depth, nodes, elapsed, nodes / elapsed) << std::endl;
  }
}

void accept_commands() {
  std::cout << std::format("Integral v{}", kEngineVersion) << std::endl;

  // initialize ray attacks for sliding pieces and knight attacks
  initialize_attacks();

  Board board;

  std::string input_line;
  while (input_line != "quit") {
    std::getline(std::cin, input_line);
    std::stringstream input_stream(input_line);

    std::string command;
    input_stream >> command;

    if (command == "uci") {
      std::cout << std::format("id name {}", kEngineName) << std::endl;
      std::cout << std::format("id author {}", kEngineAuthor) << std::endl;
      std::cout << "uciok" << std::endl;
    } else if (command == "isready") {
      std::cout << "readyok" << std::endl;
    } else if (command == "position") {
      position(board, input_stream);
    } else if (command == "go") {
      go(board, input_stream);
    }
  }
}

}