#include "data_gen.h"

#include <fmt/color.h>
#include <fmt/format.h>

#include <csignal>
#include <filesystem>

#include "../chess/board.h"
#include "../engine/search/search.h"
#include "../engine/uci/option.h"
#include "format/binpack.h"
#include "format/fens.h"

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

void FindStartingPosition(Board &board, I32 min_plies, I32 max_plies) {
  board.SetFromFen(fen::kStartFen);

  I32 current_ply = 0, target_plies = RandomU64(min_plies, max_plies);
  while (current_ply < target_plies) {
    auto legal_moves = GetLegalMoves(board);

    // If no legal moves are available, reset the board
    if (legal_moves.Empty()) {
      current_ply = 0;
      board.SetFromFen(fen::kStartFen);
      continue;
    }

    // Probabilities for selecting a move based on the piece type
    constexpr std::array<int, kNumPieceTypes> kPieceProbabilities = {
        35, 25, 25, 5, 10, 0};

    // Bucket for moves categorized by the piece type
    std::array<MoveList, kNumPieceTypes> piece_moves;
    for (int i = 0; i < legal_moves.Size(); i++) {
      const auto move = legal_moves[i];
      if (eval::StaticExchange(move, 0, board.GetState())) {
        const auto moving_piece = board.GetState().GetPieceType(move.GetFrom());
        piece_moves[moving_piece].Push(move);
      }
    }

    bool found_valid_move = false;
    for (const auto &moves : piece_moves) {
      if (!moves.Empty()) {
        found_valid_move = true;
        break;
      }
    }

    if (!found_valid_move) {
      current_ply = 0;
      board.SetFromFen(fen::kStartFen);
      continue;
    }

    // Calculate the total probability for choosing a piece with legal moves
    int total_probability = 0;
    for (int i = 0; i < kNumPieceTypes; ++i) {
      if (!piece_moves[i].Empty()) {
        total_probability += kPieceProbabilities[i];
      }
    }

    // Select a piece type to move based on the weighted probability
    int chosen_piece = -1;
    int random_value = RandomU64(0, total_probability - 1);

    for (int i = 0; i < kNumPieceTypes; ++i) {
      if (!piece_moves[i].Empty()) {
        if (random_value < kPieceProbabilities[i]) {
          chosen_piece = i;
          break;
        }
        random_value -= kPieceProbabilities[i];
      }
    }

    // Fallback: if no piece was chosen, pick the first piece with legal moves
    if (chosen_piece == -1 || piece_moves[chosen_piece].Empty()) {
      chosen_piece = 0;
      while (piece_moves[chosen_piece].Empty()) {
        ++chosen_piece;
      }
    }

    // Choose a random move for the selected piece type
    auto &chosen_moves = piece_moves[chosen_piece];
    const auto random_move =
        chosen_moves[RandomU64(0, chosen_moves.Size() - 1)];
    board.MakeMove<false>(random_move);

    // Prevent the last ply from being a checkmate/stalemate
    if (++current_ply == target_plies && GetLegalMoves(board).Empty()) {
      current_ply = 0;
      board.SetFromFen(fen::kStartFen);
    }
  }
}

std::atomic<U64> positions_written = 0, games_completed = 0, start_time = 0;
std::mutex display_mutex;

void PrintProgress(const Config &config, U64 completed, U64 written) {
  std::lock_guard lock(display_mutex);

  auto current_time = search::GetCurrentTime();
  auto elapsed_time = current_time - start_time;
  auto games_left = config.num_games - completed;
  auto time_per_game = elapsed_time / std::max<U64>(1, completed);
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
  RandomSeed(thread_id, search::GetCurrentTime());

  constexpr int kWinThreshold = 1500;
  constexpr int kWinPliesThreshold = 5;
  constexpr int kDrawThreshold = 2;
  constexpr int kDrawPliesThreshold = 10;
  constexpr int kInitialScoreThreshold = 1000;

  search::TimeConfig time_config{.nodes = config.hard_node_limit,
                                 .soft_nodes = config.soft_node_limit};
  format::BinPackFormatter formatter(output_stream);

  Board board;

  search::Search search(board);
  search.ResizeHash(16);

  auto thread = std::make_unique<search::Thread>(0);

  const int workload = config.num_games / config.num_threads;
  for (int i = 0; i < workload && !stop; i++) {
    // Find a valid legal position to play the game from
    FindStartingPosition(board, config.min_move_plies, config.max_move_plies);

    const auto &state = board.GetState();
    formatter.SetPosition(state);

    search.NewGame();
    thread->NewGame();

    const auto [initial_score, _] = search.DataGenStart(
        thread, search::TimeConfig{.depth = 10, .nodes = 1'000'000});

    if (std::abs(initial_score) >= kInitialScoreThreshold) {
      --i;
      continue;
    }

    U64 win_plies = 0, loss_plies = 0, draw_plies = 0;

    std::optional<double> wdl_outcome;
    while (!stop) {
      // Score returned in white-relative
      const auto [score, best_move] = search.DataGenStart(thread, time_config);

      // The game has ended
      if (!best_move) {
        wdl_outcome = state.InCheck() ? state.turn == Color::kBlack : 0.5;
        break;
      } else {
        if (std::abs(score) >= kTBWinInMaxPlyScore) {
          // Return the correct score depending on who is getting checkmated
          wdl_outcome = score > 0;
        } else {
          const int scaled_win_threshold =
              kWinThreshold -
              800 * std::clamp<double>(state.half_moves, 0, 200) / 200;
          if (score >= scaled_win_threshold) {
            ++win_plies, loss_plies = draw_plies = 0;
          } else if (score <= -scaled_win_threshold) {
            ++loss_plies, win_plies = draw_plies = 0;
          } else if (std::abs(score) <= kDrawThreshold) {
            ++draw_plies, win_plies = loss_plies = 0;
          }

          if (win_plies >= kWinPliesThreshold) {
            wdl_outcome = 1.0;
          } else if (loss_plies >= kWinPliesThreshold) {
            wdl_outcome = 0.0;
          } else if (draw_plies >= kDrawPliesThreshold ||
                     state.half_moves >= 200) {
            wdl_outcome = 0.5;
          }
        }
      }

      board.MakeMove<false>(best_move);

      // Check for draw here since search doesn't terminate with an adjudicated
      // draw score at root
      if (board.IsDraw(0)) {
        wdl_outcome = 0.5;
        break;
      }

      formatter.PushMove(best_move, state.turn, score);

      if (wdl_outcome) {
        break;
      }
    }

    if (wdl_outcome) {
      const auto written = positions_written.fetch_add(
          formatter.WriteOutcome(*wdl_outcome), std::memory_order_relaxed);
      const auto completed =
          games_completed.fetch_add(1, std::memory_order_relaxed) + 1;

      if (completed % std::min<U64>(config.num_games / 50, 1000ULL) == 0 ||
          completed == 1) {
        PrintProgress(config, completed, written);
      }
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