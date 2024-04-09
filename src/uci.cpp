#include "uci.h"
#include "move_gen.h"
#include "move_picker.h"

#include <string>
#include <format>
#include <fstream>

namespace uci {

void position(Board &board, std::stringstream &input_stream) {
  std::string position_type;
  input_stream >> position_type;

  std::string position_fen;
  if (position_type == "fen") {
    position_fen = input_stream.str().substr(static_cast<int>(input_stream.tellg()) + 1);
  } else if (position_type == "startpos") {
    position_fen = fen::kStartFen;
  }

  const int kTranspositionTableMbSize = 128;
  if (!board.initialized()) {
    board = Board(kTranspositionTableMbSize);
  }

  board.set_from_fen(position_fen);

  std::string dummy;
  while (input_stream >> dummy && dummy != "moves");

  std::string move_input;
  while (input_stream >> move_input) {
    const auto move = Move::from_str(board.get_state(), move_input);

    if (move.has_value() && board.is_move_pseudo_legal(move.value())) {
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

  const auto search_result = Search(time_config, board).go();
  std::cout << std::format("bestmove {}", search_result.best_move.to_string()) << std::endl;
}

int perft_internal(Board &board, int depth, int start_depth) {
  if (depth == 0)
    return 1;

  auto &state = board.get_state();

  int nodes = 0;
  //auto moves = move_gen::moves(MoveType::kAll, board);

  MovePicker mp(MovePickerType::kSearch, board, Move::null_move(), nullptr);
  Move move;
  while ((move = mp.next())) {
    board.make_move(move);
    if (!move_gen::king_in_check(flip_color(state.turn), state)) {
      const int pos_nodes = perft_internal(board, depth - 1, start_depth);
      nodes += pos_nodes;

      if (depth == start_depth) {
        std::cout << std::format("{}: {}\n", move.to_string(), pos_nodes);
      }
    }
    board.undo_move();
  }

  return nodes;
}

void perft(Board &board, std::stringstream &input_stream) {
  int depth;

  if (input_stream >> depth) {
    assert(depth >= 0);

    const auto start_time = std::chrono::steady_clock::now();
    const int nodes = perft_internal(board, depth, depth);
    const auto elapsed = duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time).count() / 1000.0;

    std::cout << std::format("nodes: {}\ntime elapsed: {:.2f}s\nnodes per second: {:.0f}", nodes, elapsed, nodes / elapsed) << std::endl;
  }
}

void accept_commands() {
  std::cout << std::format("Integral v{}", kEngineVersion) << std::endl;

  // init attack lookups
  move_gen::initialize_attacks();

  // init table lookups that the search will do
  Search::init_tables();

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
    } else if (command == "ucinewgame") {
      board.get_transpo_table().clear();
    }
  }
}

}