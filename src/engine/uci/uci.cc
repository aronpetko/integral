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

namespace options {

void Initialize() {
  // clang-format off
  listener.AddOption<OptionVisibility::kPublic>("Hash", 64, 1, 1048576, [](const Option &option) {
    transposition_table.Resize(option.GetValue<int>());
  });
  listener.AddOption<OptionVisibility::kPublic>("Pawn Cache", 1, 1, 1048576, [](const Option &option) {
    eval::pawn_cache.Resize(option.GetValue<int>());
  });
  listener.AddOption<OptionVisibility::kPublic>("Threads", 1, 1, 1);
  listener.AddOption<OptionVisibility::kPublic>("Move Overhead", 10, 0, 10000);
  // clang-format on
}

}  // namespace options

namespace commands {

void Initialize(Board &board, Search &search) {
  // clang-format off
  listener.RegisterCommand("position", CommandType::kOrdered, {
    CreateArgument("fen", ArgumentType::kOptional, LimitedInputProcessor<5>()),
    CreateArgument("startpos", ArgumentType::kOptional, NoInputProcessor()),
    CreateArgument("moves", ArgumentType::kOptional, UnlimitedInputProcessor())
  }, [&board](Command *cmd) {
    std::string board_fen;
    if (cmd->ArgumentExists("startpos")) board_fen = fen::kStartFen;
    else if (cmd->ArgumentExists("fen")) board_fen = *cmd->ParseArgument<std::string>("fen");
    board.SetFromFen(board_fen);

    const auto moves = cmd->ParseArgument<std::string>("moves");
    if (moves) {
      std::stringstream stream(*moves);
      std::string move_str;
      while (stream >> move_str) {
        const auto move = Move::FromStr(move_str);
        if (move) board.MakeMove(move);
        else fmt::println("invalid move '{}'", move_str);
      }
    }
  });

  listener.RegisterCommand("go", CommandType::kOrdered, {
    CreateArgument("infinite", ArgumentType::kOptional, NoInputProcessor()),
    CreateArgument("movetime", ArgumentType::kOptional, LimitedInputProcessor<1>()),
    CreateArgument("nodes", ArgumentType::kOptional, LimitedInputProcessor<1>()),
    CreateArgument("wtime", ArgumentType::kOptional, LimitedInputProcessor<1>()),
    CreateArgument("btime", ArgumentType::kOptional, LimitedInputProcessor<1>()),
    CreateArgument("winc", ArgumentType::kOptional, LimitedInputProcessor<1>()),
    CreateArgument("binc", ArgumentType::kOptional, LimitedInputProcessor<1>()),
  }, [&board, &search](Command *cmd) {
    TimeConfig time_config;
    std::array<int, 2> time_left = {};
    std::array<int, 2> increment = {};

    const auto white_time = cmd->ParseArgument<int>("wtime");
    if (white_time) time_left[Color::kWhite] = *white_time;

    const auto black_time = cmd->ParseArgument<int>("btime");
    if (black_time) time_left[Color::kBlack] = *black_time;

    const auto white_inc = cmd->ParseArgument<int>("winc");
    if (white_inc) increment[Color::kWhite] = *white_inc;

    const auto black_inc = cmd->ParseArgument<int>("binc");
    if (black_inc) increment[Color::kBlack] = *black_inc;

    const auto move_time = cmd->ParseArgument<int>("movetime");
    if (move_time) time_config.move_time = *move_time;

    if (cmd->ArgumentExists("infinite")) time_config.infinite = true;

    const Color turn = board.GetState().turn;
    time_config.time_left = time_left[turn];
    time_config.increment = increment[turn];

    search.Start(time_config);
  });
  // clang-format on
}

}  // namespace commands

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
      listener.GetOption(name).SetValue(value);
    }
  }
}

void AcceptCommands(int arg_count, char **args) {
  move_gen::InitializeAttacks();

  Board board;
  board.SetFromFen(fen::kStartFen);

  Search search(board);

  options::Initialize();
  commands::Initialize(board, search);

#ifdef TUNE
  Tuner tuner;
  tuner.LoadFromFile(args[1]);
  tuner.Tune();
#endif

  if (args[1] && std::string(args[1]) == "bench") {
    board.SetFromFen(fen::kStartFen);
    search.NewGame();

    const int depth = arg_count == 3 ? std::stoi(args[2]) : 0;
    tests::BenchSuite(board, search, depth);
    return;
  }

  PrintAsciiLogo();
  fmt::println(
      "    {} by {}\n", constants::kEngineName, constants::kEngineAuthor);

  listener.Listen();
}

}  // namespace uci