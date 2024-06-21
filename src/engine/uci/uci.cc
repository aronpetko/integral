#include "uci.h"

#include <string>

#include "../../ascii_logo.h"
#include "../../chess/move_gen.h"
#include "../../engine/evaluation/pawn_structure_cache.h"
#include "../../tests/tests.h"
#include "../../tuner/tuner.h"
#include "../search/search.h"
#include "fmt/format.h"

namespace uci {

void InitializeOptions() {
  AddOption<OptionVisibility::kPublic>(
      "Hash", 64, 1, 1048576, [](Option &option) {
        transposition_table.Resize(option.GetValue<int>());
      });
  AddOption<OptionVisibility::kPublic>(
      "Pawn Cache", 64, 1, 1048576, [](Option &option) {
        eval::pawn_cache.Resize(option.GetValue<int>());
      });
  AddOption<OptionVisibility::kPublic>("Threads", 1, 1, 1);
  AddOption<OptionVisibility::kPublic>("Move Overhead", 50, 0, 10000);
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
    const auto move = Move::FromStr(move_input);
    if (move && board.IsMovePseudoLegal(move)) {
      board.MakeMove(move);
    } else {
      std::cerr << fmt::format("invalid move: {}\n", move_input);
    }
  }
}

void Go(Board &board, Search &search, std::stringstream &input_stream) {
  TimeConfig time_config;
  std::array<int, 2> time_left = {};
  std::array<int, 2> increment = {};

  std::string option;
  while (input_stream >> option) {
    if (option == "wtime") {
      input_stream >> time_left[Color::kWhite];
    } else if (option == "btime") {
      input_stream >> time_left[Color::kBlack];
    } else if (option == "winc") {
      input_stream >> increment[Color::kWhite];
    } else if (option == "binc") {
      input_stream >> increment[Color::kBlack];
    } else if (option == "movetime") {
      input_stream >> time_config.move_time;
    } else if (option == "depth") {
      input_stream >> time_config.depth;
    } else if (option == "infinite") {
      time_config.infinite = true;
    } else if (option == "perft") {
      int depth;
      input_stream >> depth;
      tests::Perft(board, depth);
      return;
    }
  }

  if (option.empty()) {
    time_config.infinite = true;
  }

  const Color turn = board.GetState().turn;
  time_config.time_left = time_left[turn];
  time_config.increment = increment[turn];

  search.Start(time_config);
}

void Test(std::stringstream &input_stream) {
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

void SetOption(std::stringstream &input_stream) {
  std::string arg;
  input_stream >> arg;

  if (arg == "name") {
    std::string name;
    input_stream >> name;

    input_stream >> arg;
    if (arg == "value") {
      std::string value;
      input_stream >> value;
      GetOption(name).SetValue(value);
    }
  }
}

void AcceptCommands(int arg_count, char **args) {
  move_gen::InitializeAttacks();

  InitializeOptions();

#ifdef TUNE
  Tuner tuner;
  tuner.LoadFromFile(args[1]);
  tuner.Tune();
#endif

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
  fmt::println("    Integral v{} by {}\n", kEngineVersion, kEngineAuthor);

  std::string input_line;
  while (input_line != "quit") {
    std::getline(std::cin, input_line);
    std::stringstream input_stream(input_line);

    std::string command;
    input_stream >> command;

    if (command == "uci") {
      fmt::println("id name {}", kEngineName);
      fmt::println("id author {}", kEngineAuthor);
      PrintOptions();
      fmt::println("uciok");
    } else if (command == "isready") {
      fmt::println("readyok");
    } else if (command == "position") {
      search.WaitUntilFinished();
      Position(board, input_stream);
    } else if (command == "go") {
      Go(board, search, input_stream);
    } else if (command == "stop") {
      search.Stop();
    } else if (command == "ucinewgame") {
      search.WaitUntilFinished();
      search.NewGame();
    } else if (command == "print") {
      board.PrintPieces();
    } else if (command == "test") {
      Test(input_stream);
    } else if (command == "bench") {
      // Bench is its own command for OpenBench support
      int depth = 0;
      input_stream >> depth;
      tests::BenchSuite(board, search, depth);
    } else if (command == "setoption") {
      SetOption(input_stream);
    } else if (command == "eval" || command == "evaluate") {
      fmt::println("{}", eval::Evaluate(board.GetState()));
    }
  }
}

}  // namespace uci