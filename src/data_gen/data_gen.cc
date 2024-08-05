#include "data_gen.h"

#include <fmt/color.h>
#include <fmt/format.h>

#include <csignal>
#include <filesystem>

#include "../chess/board.h"
#include "../engine/search/search.h"
#include "format/binpack.h"

namespace data_gen {

MoveList GetLegalMoves(Board &board) {
  auto move_list = move_gen::GenerateMoves(MoveGenType::kAll, board);
  auto legal_move_list = MoveList{};

  for (int i = 0; i < move_list.Size(); i++) {
    const auto move = move_list[i];
    if (board.IsMoveLegal(move)) {
      legal_move_list.Push(move);
    }
  }

  return legal_move_list;
}

Board FindStartingPosition(I32 plies) {
  Board board;
  board.SetFromFen(fen::kStartFen);

  I32 current_ply = 0;
  while (current_ply < plies) {
    auto legal_moves = GetLegalMoves(board);
    // Keep looping until we can find a legal move
    if (legal_moves.Empty()) {
      board.UndoMove(), --current_ply;
      continue;
    }

    const auto move = legal_moves[RandomU64(0, legal_moves.Size() - 1)];
    board.MakeMove(move);

    // Prevent the last ply being checkmate/stalemate
    if (++current_ply == plies && GetLegalMoves(board).Empty()) {
      board.UndoMove(), --current_ply;
    }
  }

  return board;
}

std::atomic<U64> positions_written = 0, games_completed = 0, start_time = 0;
std::mutex display_mutex;

void PrintProgress(const Config &config, U64 completed, U64 written) {
  std::lock_guard lock(display_mutex);

  auto current_time = search::GetCurrentTime();
  auto elapsed_time = current_time - start_time;
  auto games_left = config.num_games - completed;
  auto time_per_game = elapsed_time / completed;
  auto time_remaining = time_per_game * games_left;

  // Calculate progress bar
  int bar_width = 50;
  double progress = static_cast<double>(completed) / config.num_games;
  int filled_length = static_cast<int>(std::round(bar_width * progress));

  std::string bar;
  for (int i = 0; i < bar_width; ++i) {
    if (i < filled_length) {
      bar += "\u2588";  // Full block
    } else {
      bar += " ";  // Light shade
    }
  }

  // Calculate speeds
  double games_per_second =
      static_cast<double>(completed) / (elapsed_time / 1000.0);
  double positions_per_second =
      static_cast<double>(written) / (elapsed_time / 1000.0);

  // Format time remaining
  std::string time_str;
  if (time_remaining >= 3600000) {
    time_str = fmt::format("{}h {}m {}s",
                           time_remaining / 3600000,
                           (time_remaining % 3600000) / 60000,
                           (time_remaining % 60000) / 1000);
  } else if (time_remaining >= 60000) {
    time_str = fmt::format(
        "{}m {}s", time_remaining / 60000, (time_remaining % 60000) / 1000);
  } else {
    time_str = fmt::format("{}s", time_remaining / 1000);
  }

  // Clear previous lines (5 lines total)
  fmt::print("\033[5F\033[J");

  // Print updated progress with green bar and aligned gray data
  fmt::print("{:15} [", "Progress:");
  fmt::print(fg(fmt::color::green), "{}", bar);
  fmt::print("] ");
  fmt::print(
      fg(fmt::color::gray), "{}% complete\n", static_cast<int>(progress * 100));

  fmt::print("{:15} ", "Games:");
  fmt::print(fg(fmt::color::gray), "{} / {}\n", completed, config.num_games);

  fmt::print("{:15} ", "Positions:");
  fmt::print(fg(fmt::color::gray), "{}\n", written);

  fmt::print("{:15} ", "Time remaining:");
  fmt::print(fg(fmt::color::gray), "{}\n", time_str);

  fmt::print("{:15} ", "Speed:");
  fmt::print(fg(fmt::color::gray),
             "{:.1f} games/s, {:.1f} pos/s\n",
             games_per_second,
             positions_per_second);

  // Ensure output is displayed immediately
  std::cout.flush();
}

void GameLoop(const Config &config,
              int thread_id,
              std::ostream &output_stream) {
  constexpr int kWinThreshold = 800;
  constexpr int kDrawThreshold = 10;
  constexpr int kPliesThreshold = 5;

  search::TimeConfig time_config{.nodes = config.hard_node_limit,
                                 .soft_nodes = config.soft_node_limit};
  format::BinPackFormatter formatter(output_stream);

  const int workload = config.num_games / config.num_threads;
  for (int i = 0; i < workload && !stop; i++) {
    // Find a valid legal position to play the game from
    auto board = FindStartingPosition(config.random_move_plies);

    const auto &state = board.GetState();
    formatter.SetPosition(state);

    search::Search search(board);
    search.NewGame();

    U64 win_plies = 0, loss_plies = 0, draw_plies = 0;

    std::optional<double> wdl_outcome;
    while (!stop) {
      const auto [score, best_move] = search.DataGenStart(time_config);

      // The game has ended
      if (!best_move) {
        wdl_outcome = state.InCheck() ? state.turn == Color::kBlack : 0.5;
        break;
      } else {
        if (std::abs(score) >= kTBWinScore - kMaxPlyFromRoot) {
          // Return the correct score depending on who is getting checkmated
          wdl_outcome = (score < 0) == (state.turn == Color::kBlack);
        } else if (state.turn == Color::kWhite) {
          if (score > kWinThreshold) {
            ++win_plies, loss_plies = draw_plies = 0;
          } else if (score < -kWinThreshold) {
            ++loss_plies, win_plies = draw_plies = 0;
          } else if (std::abs(score) < kDrawThreshold &&
                     state.half_moves > 50) {
            ++draw_plies, win_plies = loss_plies = 0;
          }

          if (win_plies > kPliesThreshold) {
            wdl_outcome = 1.0;
          } else if (loss_plies > kPliesThreshold) {
            wdl_outcome = 0.0;
          } else if (draw_plies > kPliesThreshold) {
            wdl_outcome = 0.5;
          }
        }
      }

      formatter.PushMove(best_move, state.turn, score);
      board.MakeMove(best_move);

      // Check for draw here since search doesn't terminate with an adjudicated
      // draw score at root
      if (board.IsDraw(0)) {
        wdl_outcome = 0.5;
      }

      if (wdl_outcome) {
        break;
      }
    }

    const auto written = positions_written.fetch_add(
        formatter.WriteOutcome(*wdl_outcome), std::memory_order_relaxed);
    const auto completed =
        games_completed.fetch_add(1, std::memory_order_relaxed) + 1;

    if (completed % (config.num_games / 50) == 0) {
      PrintProgress(config, completed, written);
    }
  }

  PrintProgress(config,
                games_completed.load(std::memory_order_relaxed),
                positions_written.load(std::memory_order_relaxed));
}

void signal_handler([[maybe_unused]] int signum) {
  stop = true;
}

void Generate(Config config) {
  fmt::println("Starting data generation process...\n");

  games_completed = positions_written = 0;

  // Handle Ctrl + C
  std::signal(SIGINT, signal_handler);

  // Change the number of games to fit evenly within the number of threads
  config.num_games -= config.num_games % config.num_threads;

  const auto time = std::time(nullptr);
  const auto tm = *std::localtime(&time);

  std::stringstream buffer;
  buffer << std::put_time(&tm, "%d-%m-%Y");

  const auto path = config.output_file + "-" + buffer.str();
  start_time = search::GetCurrentTime();

  std::vector<std::thread> threads;
  threads.reserve(config.num_threads);

  std::vector<std::string> temp_files;

  for (int i = 0; i < config.num_threads; i++) {
    auto thread_path = path + fmt::format("_temp{}", i);
    temp_files.push_back(thread_path);

    threads.emplace_back([&config, thread_path = std::move(thread_path), i]() {
      std::ofstream output_stream(thread_path,
                                  std::ios::binary | std::ios::app);
      if (!output_stream) {
        fmt::println("Error: Failed to open output file {} for thread {} '{}'",
                     thread_path,
                     i,
                     strerror(errno));
        return;
      }

      GameLoop(config, i, output_stream);

      output_stream.close();
      if (output_stream.good()) {
        // Explicitly flush to ensure all data is written
        output_stream.flush();
      } else {
        fmt::println(
            "Error: Thread {} encountered an issue while closing the file", i);
      }
    });
  }

  for (auto &thread : threads) {
    thread.join();
  }

  // Add a small delay to ensure file system sync
  std::this_thread::sleep_for(std::chrono::seconds(1));

  fmt::println("");

  // Concatenate all temp files into one big file
  std::ofstream final_output(path, std::ios::binary);
  if (!final_output) {
    fmt::println("Error: Failed to open final output file {}", path);
    return;
  }

  int concatenated_files = 0;
  for (const auto &temp_file : temp_files) {
    std::ifstream input(temp_file, std::ios::binary);
    if (input) {
      final_output << input.rdbuf();
      input.close();
      // Delete the temp file
      if (std::remove(temp_file.c_str()) == 0) {
        concatenated_files++;
        fmt::println("Successfully concatenated and removed temp file {}",
                     temp_file);
      } else {
        fmt::println(
            "Error: Failed to remove temp file {} after concatenation. Error: "
            "{}",
            temp_file,
            strerror(errno));
      }
    } else {
      fmt::println(
          "Error: Failed to open temp file {} for concatenation. Error: {}",
          temp_file,
          strerror(errno));
    }
  }

  final_output.close();

  fmt::println("Concatenated {} out of {} expected temp files",
               concatenated_files,
               config.num_threads);
}

}  // namespace data_gen