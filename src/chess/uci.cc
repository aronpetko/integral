#include "uci.h"

#include <format>
#include <string>

#include "../ascii_logo.h"
#include "../engine/search.h"
#include "../tests/tests.h"
#include "move_gen.h"

#define INT_OPTION(name, value, min, max) options[name] = Option(name, value, min, max)
#define STRING_OPTION(name, value) options[name] = Option(name, value)

namespace uci {

std::unordered_map<std::string_view, Option> options;

template <typename T>
Option &GetOption(std::string_view option) {
  return options[option];
}

void InitializeOptions() {
  INT_OPTION("Hash", 64, 0, 1024);
  INT_OPTION("Threads", 1, 1, 1);
}

void PrintOptions() {
  for (const auto &[_, option] : options) {
    std::cout << option.ToString() << std::endl;
  }
}

void Position(Board &board, std::stringstream &input_stream) {
  std::string position_type;
  input_stream >> position_type;

  std::string position_fen;
  if (position_type == "fen") {
    position_fen =
        input_stream.str().substr(static_cast<int>(input_stream.tellg()) + 1);
  } else if (position_type == "startpos") {
    position_fen = fen::kStartFen;
  }

  board.SetFromFen(position_fen);

  std::string dummy;
  while (input_stream >> dummy && dummy != "moves")
    ;

  std::string move_input;
  while (input_stream >> move_input) {
    const auto move = Move::FromStr(board.GetState(), move_input);
    if (move && board.IsMovePseudoLegal(move)) {
      board.MakeMove(move);
    } else {
      std::cerr << std::format("invalid move: {}\n", move_input);
    }
  }
}

void Go(Board &board, Search &search, std::stringstream &input_stream) {
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
      tests::Perft(board, depth);
      return;
    }
  }

  time_config.turn = board.GetState().turn;

  if (option.empty()) {
    time_config.depth = kMaxSearchDepth;
  }

  search.Start(time_config);
}

void Test(Board &board, std::stringstream &input_stream) {
  std::string type;
  input_stream >> type;

  if (type == "perft") {
    tests::PerftSuite();
  } else if (type == "see") {
    tests::SEESuite();
  } else {
    tests::PerftSuite();
    tests::SEESuite();
  }
}

void AcceptCommands(int arg_count, char **args) {
  move_gen::InitializeAttacks();

  InitializeOptions();
  PrintOptions();

  const int kTTMbSize = 64;
  transposition_table.Resize(kTTMbSize);

  Board board;
  board.SetFromFen(fen::kStartFen);

  Search search(board);
  search.NewGame();

  if (args[1] && std::string(args[1]) == "bench") {
    const int depth = arg_count == 3 ? std::stoi(args[2]) : 0;
    tests::BenchSuite(board, search, depth);
    return;
  }

  PrintAsciiLogo();
  std::cout << std::format(
                   "    v{}, written by {}\n", kEngineVersion, kEngineAuthor)
            << std::endl;

  std::string input_line;
  while (input_line != "quit") {
    std::getline(std::cin, input_line);
    std::stringstream input_stream(input_line);

    std::string command;
    input_stream >> command;

    if (command == "uci") {
      std::cout << std::format("id name {}", kEngineName) << std::endl;
      std::cout << std::format("id author {}", kEngineAuthor) << std::endl;

      // TODO: properly implement options
      std::cout << "option name Threads type spin default 1 min 1 max 1"
                << std::endl;
      std::cout << "option name Hash type spin default 16 min 16 max 16"
                << std::endl;

      std::cout << "uciok" << std::endl;
    } else if (command == "isready") {
      std::cout << "readyok" << std::endl;
    } else if (command == "position") {
      Position(board, input_stream);
    } else if (command == "go") {
      Go(board, search, input_stream);
    } else if (command == "stop") {
      search.Stop();
    } else if (command == "ucinewgame") {
      search.NewGame();
    } else if (command == "print") {
      board.PrintPieces();
    } else if (command == "test") {
      Test(board, input_stream);
    } else if (command == "bench") {
      // Bench is its own command for OpenBench support
      int depth = 0;
      input_stream >> depth;
      tests::BenchSuite(board, search, depth);
    }
  }
}

}  // namespace uci