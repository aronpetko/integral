#include "uci.h"

#include <format>
#include <fstream>
#include <string>

#include "../engine/search.h"
#include "../tests/tests.h"
#include "move_gen.h"

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

  board.set_from_fen(position_fen);

  std::string dummy;
  while (input_stream >> dummy && dummy != "moves");

  std::string move_input;
  while (input_stream >> move_input) {
    const auto move = Move::from_str(board.get_state(), move_input);
    if (move && board.is_move_pseudo_legal(move)) {
      board.make_move(move);
    } else {
      std::cerr << std::format("invalid move: {}\n", move_input);
    }
  }
}

void go(Board &board, Search &search, std::stringstream &input_stream) {
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
      time_config.depth = kMaxSearchDepth;
    } else if (option == "perft") {
      int depth;
      input_stream >> depth;
      tests::perft(board, depth);
      return;
    }
  }

  time_config.turn = board.get_state().turn;

  if (option.empty()) {
    time_config.depth = kMaxSearchDepth;
  }

  search.start(time_config);
}

void test(Board &board, std::stringstream &input_stream) {
  std::string type;
  input_stream >> type;

  if (type == "perft") {
    tests::perft_suite();
  } else if (type == "see") {
    tests::see_suite();
  } else {
    tests::perft_suite();
    tests::see_suite();
  }
}

void accept_commands(int arg_count, char **args) {
  std::cout << std::format("    v{}, written by {}\n", kEngineVersion, kEngineAuthor) << std::endl;

  // init attack lookups
  move_gen::initialize_attacks();

  const int kTTMbSize = 64;
  transposition_table.resize(kTTMbSize);

  Board board;
  board.set_from_fen(fen::kStartFen);
  Search search(board);

  if (args[1] && std::string(args[1]) == "bench") {
    const int depth = arg_count == 3 ? std::stoi(args[2]) : 0;
    tests::bench_suite(depth);
  }

  std::string input_line;
  while (input_line != "quit") {
    std::getline(std::cin, input_line);
    std::stringstream input_stream(input_line);

    std::string command;
    input_stream >> command;

    if (command == "uci") {
      std::cout << std::format("id name {}", kEngineName) << std::endl;
      std::cout << std::format("id author {}", kEngineAuthor) << std::endl;

      // todo: properly implement options
      std::cout << "option name Threads type spin default 1 min 1 max 1" << std::endl;
      std::cout << "option name Hash type spin default 64 min 64 max 64" << std::endl;

      std::cout << "uciok" << std::endl;
    } else if (command == "isready") {
      std::cout << "readyok" << std::endl;
    } else if (command == "position") {
      position(board, input_stream);
    } else if (command == "go") {
      go(board, search, input_stream);
    } else if (command == "stop") {
      search.stop();
    } else if (command == "ucinewgame") {
      transposition_table.clear();
    } else if (command == "print") {
      board.print_pieces();
    } else if (command == "test") {
      test(board, input_stream);
    } else if (command == "bench") {
      // bench is its own command for OpenBench support
      int depth = 0;
      input_stream >> depth;
      tests::bench_suite(depth);
    }
  }
}

}