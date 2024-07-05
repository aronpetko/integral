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
    CreateArgument("fen", ArgumentType::kOptional, LimitedInputProcessor<6>()),
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
    CreateArgument("perft", ArgumentType::kOptional, LimitedInputProcessor<1>()),
    CreateArgument("infinite", ArgumentType::kOptional, NoInputProcessor()),
    CreateArgument("movetime", ArgumentType::kOptional, LimitedInputProcessor<1>()),
    CreateArgument("nodes", ArgumentType::kOptional, LimitedInputProcessor<1>()),
    CreateArgument("wtime", ArgumentType::kOptional, LimitedInputProcessor<1>()),
    CreateArgument("btime", ArgumentType::kOptional, LimitedInputProcessor<1>()),
    CreateArgument("winc", ArgumentType::kOptional, LimitedInputProcessor<1>()),
    CreateArgument("binc", ArgumentType::kOptional, LimitedInputProcessor<1>()),
  }, [&board, &search](Command *cmd) {
    const auto perft_depth = cmd->ParseArgument<int>("perft");
    if (perft_depth) {
      tests::Perft(board, *perft_depth);
      return;
    }

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

    const Color turn = board.GetState().turn;
    time_config.time_left = time_left[turn];
    time_config.increment = increment[turn];

    // No arguments passed has the same behavior as passing 'infinite'
    if (cmd->ArgumentExists("infinite") || !time_config.HasBeenModified())
      time_config.infinite = true;

    search.Start(time_config);
  });

  listener.RegisterCommand("stop", CommandType::kUnordered, {}, [&search](Command *cmd) {
    search.Stop();
    search.WaitUntilFinished();
  });

  listener.RegisterCommand("ucinewgame", CommandType::kUnordered, {}, [&search](Command *cmd) {
    search.Stop();
    search.WaitUntilFinished();
    search.NewGame();
  });

  listener.RegisterCommand("eval", CommandType::kUnordered, {}, [&board](Command *cmd) {
    fmt::println("info string cp {}", eval::Evaluate(board.GetState()));
  });

  listener.RegisterCommand("print", CommandType::kUnordered, {}, [&board](Command *cmd) {
    board.PrintPieces();
  });

  listener.RegisterCommand("setoption", CommandType::kUnordered, {
    CreateArgument("name", ArgumentType::kRequired, LimitedInputProcessor<1>()),
    CreateArgument("value", ArgumentType::kRequired, LimitedInputProcessor<1>()),
    CreateArgument("wtime", ArgumentType::kOptional, LimitedInputProcessor<1>()),
  }, [](Command *cmd) {
    const auto option_name = *cmd->ParseArgument<std::string>("name");
    const auto option_value = *cmd->ParseArgument<std::string>("value");
    listener.GetOption(option_name).SetValue(option_value);
  });

  listener.RegisterCommand("test", CommandType::kUnordered, {
    CreateArgument("see", ArgumentType::kOptional, NoInputProcessor()),
    CreateArgument("perft", ArgumentType::kOptional, NoInputProcessor()),
  }, [](Command *cmd) {
    if (cmd->ArgumentExists("see")) tests::SEESuite();
    if (cmd->ArgumentExists("perft")) tests::PerftSuite();
    else {
      tests::SEESuite();
      tests::PerftSuite();
    }
  });

  listener.RegisterCommand("bench", CommandType::kUnordered, {
    CreateArgument("depth", ArgumentType::kOptional, NoInputProcessor()),
  }, [&board, &search](Command *cmd) {
    const auto bench_depth = cmd->ParseArgument<int>("depth");
    if (bench_depth) tests::BenchSuite(board, search, *bench_depth);
    else tests::BenchSuite(board, search, tests::kDefaultBenchDepth);
  });

  listener.RegisterCommand("uci", CommandType::kUnordered, {}, [](Command *cmd) {
    fmt::println(
      "id name {}\n"
      "id author {}",
      constants::kEngineName,
      constants::kEngineAuthor
    );
    listener.PrintOptions();
    fmt::println("uciok");
  });

  listener.RegisterCommand("isready", CommandType::kUnordered, {}, [](Command *cmd) {
    fmt::println("readyok");
  });

  listener.RegisterCommand("quit", CommandType::kUnordered, {}, [](Command *cmd) {
    exit(EXIT_SUCCESS);
  });
  // clang-format on
}

}  // namespace commands

void AcceptCommands(int arg_count, char **args) {
  Board board;
  board.SetFromFen(fen::kStartFen);

  Search search(board);

  options::Initialize();
  commands::Initialize(board, search);

  // OpenBench requires the bench command to be parsed from the command line
  if (args[1] && std::string(args[1]) == "bench") {
    const int depth =
        arg_count == 3 ? std::stoi(args[2]) : tests::kDefaultBenchDepth;
    tests::BenchSuite(board, search, depth);
    return;
  }

  PrintAsciiLogo();
  fmt::println(
      "    {} by {}\n", constants::kEngineName, constants::kEngineAuthor);

#ifdef TUNE
  Tuner tuner;
  tuner.LoadFromFile(args[1]);
  tuner.Tune();
#endif

  listener.Listen();
}

}  // namespace uci