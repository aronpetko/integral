#include "uci.h"

#include <string>
#include <algorithm>

#include "../../ascii_logo.h"
#include "../../data_gen/data_gen.h"
#include "../../tests/tests.h"
#include "../evaluation/nnue/sparse.h"
#include "../search/search.h"
#include "../search/syzygy/syzygy.h"
#include "fmt/format.h"
#include "reporter.h"

namespace uci {

namespace options {

void Initialize(search::Searcher &searcher) {
  // clang-format off
  listener.AddOption<OptionVisibility::kPublic>("Hash", 64, 1, 1048576, [&searcher](const Option &option) {
    searcher.ResizeHash(option.GetValue<int>());
  });
  listener.AddOption<OptionVisibility::kPublic>("Threads", 1, 1, 512, [&searcher](const Option &option) {
    searcher.SetThreadCount(option.GetValue<U16>());
  });
  listener.AddOption<OptionVisibility::kPublic>("MultiPV", 1, 1, 6);
  listener.AddOption<OptionVisibility::kPublic>("MoveOverhead", 10, 0, 10000);
  listener.AddOption<OptionVisibility::kPublic>("Minimal", false);
  listener.AddOption<OptionVisibility::kPublic>("SyzygyPath", std::string("<empty>"), [](const Option &option) {
    syzygy::SetPath(option.GetValue<std::string>());
  });
  listener.AddOption<OptionVisibility::kPublic>("SyzygyProbeDepth", 1, 1, 100, [](const Option &option) {
    syzygy::probe_depth = option.GetValue<int>();
  });
  listener.AddOption<OptionVisibility::kPublic>("SyzygyProbeLimit", 32, 3, 32, [](const Option &option) {
    syzygy::piece_probe_limit = option.GetValue<int>();
    syzygy::max_pieces = std::min<int>(syzygy::max_pieces, syzygy::piece_probe_limit);
  });
  // clang-format on
}

}  // namespace options

namespace commands {

void Initialize(Board &board, search::Searcher &searcher) {  // clang-format off
  listener.RegisterCommand("position", CommandType::kOrdered, {
    CreateArgument("fen", ArgumentType::kOptional, LimitedInputProcessor<6>()),
    CreateArgument("startpos", ArgumentType::kOptional, NoInputProcessor()),
    CreateArgument("kiwipete", ArgumentType::kOptional, NoInputProcessor()),
    CreateArgument("moves", ArgumentType::kOptional, UnlimitedInputProcessor())
  }, [&board](Command *cmd) {
    std::string board_fen;
    if (cmd->ArgumentExists("startpos")) board_fen = fen::kStartFen;
    else if (cmd->ArgumentExists("kiwipete")) board_fen = fen::kKiwipeteFen;
    else if (cmd->ArgumentExists("fen")) board_fen = *cmd->ParseArgument<std::string>("fen");
    board.SetFromFen(board_fen);

    const auto moves = cmd->ParseArgument<std::string>("moves");
    if (moves) {
      std::stringstream stream(*moves);
      std::string move_str;
      while (stream >> move_str) {
        const auto move = Move::FromStr(move_str, board.GetState());
        if (move) board.MakeMove(move);
        else fmt::println("Error: invalid move '{}'", move_str);
      }
    }
  });

  listener.RegisterCommand("go", CommandType::kUnordered, {
    CreateArgument("perft", ArgumentType::kOptional, LimitedInputProcessor<1>()),
    CreateArgument("infinite", ArgumentType::kOptional, NoInputProcessor()),
    CreateArgument("movetime", ArgumentType::kOptional, LimitedInputProcessor<1>()),
    CreateArgument("depth", ArgumentType::kOptional, LimitedInputProcessor<1>()),
    CreateArgument("nodes", ArgumentType::kOptional, LimitedInputProcessor<1>()),
    CreateArgument("soft_nodes", ArgumentType::kOptional, LimitedInputProcessor<1>()),
    CreateArgument("wtime", ArgumentType::kOptional, LimitedInputProcessor<1>()),
    CreateArgument("winc", ArgumentType::kOptional, LimitedInputProcessor<1>()),
    CreateArgument("btime", ArgumentType::kOptional, LimitedInputProcessor<1>()),
    CreateArgument("binc", ArgumentType::kOptional, LimitedInputProcessor<1>()),
  }, [&board, &searcher](Command *cmd) {
    const auto perft_depth = cmd->ParseArgument<int>("perft");
    if (perft_depth) {
      tests::Perft(board, *perft_depth);
      return;
    }

    search::TimeConfig time_config;
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

    const auto depth = cmd->ParseArgument<int>("depth");
    if (depth) time_config.depth = *depth;

    const auto nodes = cmd->ParseArgument<int>("nodes");
    if (nodes) time_config.nodes = *nodes;

    const auto soft_nodes = cmd->ParseArgument<int>("soft_nodes");
    if (soft_nodes) time_config.soft_nodes = *soft_nodes;

    const Color turn = board.GetState().turn;
    time_config.time_left = time_left[turn];
    time_config.increment = increment[turn];

    // No arguments passed has the same behavior as passing 'infinite'
    if (cmd->ArgumentExists("infinite") || !time_config.HasBeenModified())
      time_config.infinite = true;

    searcher.Start(time_config);
  });

  listener.RegisterCommand("datagen", CommandType::kUnordered, {
    CreateArgument("soft_limit", ArgumentType::kOptional, LimitedInputProcessor<1>()),
    CreateArgument("hard_limit", ArgumentType::kOptional, LimitedInputProcessor<1>()),
    CreateArgument("games", ArgumentType::kRequired, LimitedInputProcessor<1>()),
    CreateArgument("threads", ArgumentType::kRequired, LimitedInputProcessor<1>()),
    CreateArgument("min_moves", ArgumentType::kRequired, LimitedInputProcessor<1>()),
    CreateArgument("max_moves", ArgumentType::kRequired, LimitedInputProcessor<1>()),
    CreateArgument("out", ArgumentType::kRequired, LimitedInputProcessor<1>()),
    CreateArgument("book", ArgumentType::kOptional, LimitedInputProcessor<1>()),
  }, [](Command *cmd) {
    const auto book_file = cmd->ParseArgument<std::string>("book");
    data_gen::Config config{
      .soft_node_limit = *cmd->ParseArgument<U64>("soft_limit"),
      .hard_node_limit = *cmd->ParseArgument<U64>("hard_limit"),
      .num_games = *cmd->ParseArgument<U64>("games"),
      .num_threads = *cmd->ParseArgument<I32>("threads"),
      .min_move_plies = *cmd->ParseArgument<I32>("min_moves"),
      .max_move_plies = *cmd->ParseArgument<I32>("max_moves"),
      .output_file = *cmd->ParseArgument<std::string>("out"),
      .fens_file = book_file ? *book_file : "",
    };
    data_gen::Generate(config);
  });

  listener.RegisterCommand("stop", CommandType::kUnordered, {
    CreateArgument("datagen", ArgumentType::kOptional, NoInputProcessor()),
  }, [&searcher](Command *cmd) {
    searcher.Stop();
    if (cmd->ArgumentExists("datagen")) {
      data_gen::stop = true;
    }
  });

  listener.RegisterCommand("ucinewgame", CommandType::kUnordered, {}, [&searcher](Command *cmd) {
    searcher.NewGame();
  });

  listener.RegisterCommand("eval", CommandType::kUnordered, {}, [&board](Command *cmd) {
    const auto eval = eval::Evaluate(board);
    fmt::println("info cp {}\ninfo normalized cp {}", eval, eval::NormalizeScore(eval, board.GetState().MaterialCount()));
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
    else if (cmd->ArgumentExists("perft")) tests::PerftSuite();
    else {
      tests::SEESuite();
      tests::PerftSuite();
    }
  });

  listener.RegisterCommand("bench", CommandType::kUnordered, {
    CreateArgument("depth", ArgumentType::kOptional, NoInputProcessor()),
  }, [](Command *cmd) {
    const auto bench_depth = cmd->ParseArgument<int>("depth");
    if (bench_depth) tests::BenchSuite(*bench_depth);
    else tests::BenchSuite(tests::kDefaultBenchDepth);
  });

#ifdef SPARSE_PERMUTE
  listener.RegisterCommand("permute", CommandType::kUnordered, {
    CreateArgument("out", ArgumentType::kRequired, LimitedInputProcessor<1>()),
  }, [](Command *cmd) {
    tests::BenchSuite(tests::kDefaultBenchDepth);
    nnue::sparse::SavePermutedNetwork(*cmd->ParseArgument<std::string>("out"));
  });
#endif

  listener.RegisterCommand("uci", CommandType::kUnordered, {}, [](Command *cmd) {
    fmt::println(
      "id name {}\n"
      "id author {}",
      constants::kEngineName,
      constants::kEngineAuthor
    );
    listener.PrintOptions();
    reporter::using_uci = true;
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

Listener::~Listener() {
  if (syzygy::enabled) {
    syzygy::Free();
  }
}

void AcceptCommands(int arg_count, char **args) {
  Board board;
  board.SetFromFen(fen::kStartFen);

  search::Searcher searcher(board);

  options::Initialize(searcher);
  commands::Initialize(board, searcher);

  // OpenBench requires the bench command to be parsed from the command line
  if (args[1] && std::string(args[1]) == "bench") {
    const int depth =
        arg_count == 3 ? std::stoi(args[2]) : tests::kDefaultBenchDepth;
    tests::BenchSuite(depth);
    return;
  }

  PrintAsciiLogo();
  fmt::println(
      "    {} by {}\n", constants::kEngineName, constants::kEngineAuthor);

  listener.Listen();
}

}  // namespace uci