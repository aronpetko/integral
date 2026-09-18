#include "data_gen.h"

#include <fmt/color.h>
#include <fmt/format.h>

#include <csignal>
#include <fstream>
#include <optional>

#include "../chess/board.h"
#include "../engine/search/search.h"
#include "book.h"
#include "format/binpack.h"

namespace data_gen {

// clang-format off
constexpr std::array<int, 64> kCenterScore = {
  1,  1,  1,  1,  1,  1,  1,  1,
  1,  2,  2,  2,  2,  2,  2,  1,
  2,  3,  3,  3,  3,  3,  3,  2,
  3,  5,  5,  5,  5,  5,  5,  3,
  4,  6,  7,  9,  9,  7,  6,  4,
  4,  6,  8,  8,  8,  8,  6,  4,
  3,  5,  6,  6,  6,  6,  5,  3,
  1,  1,  4,  4,  4,  4,  1,  1
};
// clang-format on

Move SelectPreferredMove(MoveList &moves, Color stm) {
  if (moves.Empty()) {
    return Move();
  }

  std::vector<int> move_scores;
  move_scores.reserve(moves.Size());

  // Score moves based on destination square
  for (int i = 0; i < moves.Size(); ++i) {
    const auto to_square = moves[i].GetTo();
    move_scores.push_back(kCenterScore[to_square.RelativeTo(stm)]);
  }

  // Create a distribution weighted by scores
  std::discrete_distribution<> move_dist(move_scores.begin(),
                                         move_scores.end());
  static thread_local std::random_device rd;
  static thread_local std::mt19937 gen(rd());

  int selected_index = move_dist(gen);
  return moves[selected_index];
}

constexpr int kOpeningMinCp = 80, kOpeningMaxCp = 125;
constexpr int kOpeningScoreMargin = 35;
constexpr int kOpeningMultiPv = 6, kOpeningMaxDepth = 6;
constexpr U64 kOpeningSoftNodeLimit = 1'000, kOpeningHardNodeLimit = 100'000;

[[nodiscard]] bool IsOpeningIdeal(std::unique_ptr<search::Thread> &thread,
                                  search::Searcher &searcher) {
  constexpr search::TimeConfig kOpeningVerificationLimits{.depth = 10,
                                                          .nodes = 1'000'000};
  const auto [score, move] =
      searcher.DataGenStart(thread, kOpeningVerificationLimits);
  // Not ideal if there's no legal move!
  if (!move) {
    return false;
  }
  const int cp = std::abs(
      eval::NormalizeScore(score, thread->board.GetState().MaterialCount()));
  return cp >= kOpeningMinCp && cp <= kOpeningMaxCp;
}

[[nodiscard]] bool FindStartingPosition(std::unique_ptr<search::Thread> &thread,
                                        search::Searcher &searcher,
                                        const Config &config,
                                        const Book &book) {
  auto &board = thread->board;
  board.SetFromFen(book.Empty() ? fen::kStartFen
                                : book[RandomU64(0, book.Size() - 1)]);

  I32 current_ply = 0;
  I32 target_plies = RandomU64(config.min_move_plies, config.max_move_plies);

  while (current_ply < target_plies && !stop) {
    Move random_move;

    if (!book.Empty()) {
      const int previous_multi_pv = thread->multi_pv;
      thread->multi_pv = kOpeningMultiPv;
      searcher.DataGenStart(thread,
                            {.depth = kOpeningMaxDepth,
                             .nodes = kOpeningHardNodeLimit,
                             .soft_nodes = kOpeningSoftNodeLimit});
      thread->multi_pv = previous_multi_pv;

      MoveList candidates, fallback_candidates;
      int nearest_distance = kInfiniteScore;
      for (int i = 0; i < thread->completed_pvs; ++i) {
        const auto &root = thread->root_moves[i];
        const int cp = std::abs(
            eval::NormalizeScore(root.score, board.GetState().MaterialCount()));
        const int distance =
            std::max({kOpeningMinCp - cp, cp - kOpeningMaxCp, 0});
        if (distance < nearest_distance) {
          nearest_distance = distance;
          random_move = root.move;
        }
        if (distance == 0) {
          candidates.Push(root.move);
        } else if (distance <= kOpeningScoreMargin) {
          fallback_candidates.Push(root.move);
        }
      }
      const auto &choices =
          candidates.Empty() ? fallback_candidates : candidates;
      if (!choices.Empty()) {
        random_move = choices[RandomU64(0, choices.Size() - 1)];
      }
      if (!random_move) {
        return false;
      }
    } else {
      auto legal_moves = board.GetLegalMoves();

      // If no legal moves are available, reset the board
      if (legal_moves.Empty()) {
        current_ply = 0;
        board.SetFromFen(fen::kStartFen);
        continue;
      }

      // Bucket for moves categorized by the piece type
      std::array<MoveList, kNumPieceTypes> piece_moves;

      // Gather all moves that don't lose material and bucket them by piece type
      for (int i = 0; i < legal_moves.Size(); i++) {
        const auto move = legal_moves[i];
        const auto moving_piece = board.GetState().GetPieceType(move.GetFrom());
        piece_moves[moving_piece].Push(move);
      }

      constexpr std::array<int, kNumPieceTypes> kPieceProbabilities = {
          35, 25, 25, 5, 5, 5};

      static thread_local std::random_device rd;
      static thread_local std::mt19937 gen(rd());
      static thread_local std::discrete_distribution<> dist(
          kPieceProbabilities.begin(), kPieceProbabilities.end());

      int chosen_piece = dist(gen);
      auto &chosen_moves = piece_moves[chosen_piece];
      if (!chosen_moves.Empty()) {
        random_move = SelectPreferredMove(chosen_moves, board.GetState().turn);
      } else {
        current_ply = 0;
        board.SetFromFen(fen::kStartFen);
        continue;
      }
    }

    board.MakeMove(random_move);
    ++current_ply;
  }
  return !stop && IsOpeningIdeal(thread, searcher);
}

std::atomic<U64> positions_written = 0, games_completed = 0, start_time = 0;
std::mutex display_mutex;

void PrintProgress(const Config &config, U64 completed, U64 written) {
  std::lock_guard lock(display_mutex);

  auto current_time = GetCurrentTimeMilliseconds();
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
              std::ostream &output_stream,
              std::mutex &output_mutex,
              const Book &book) {
  RandomSeed(thread_id, GetCurrentTimeMilliseconds());

  constexpr int kWinThreshold = 2500;
  constexpr int kWinPliesThreshold = 5;
  constexpr int kDrawThreshold = 2;
  constexpr int kDrawPliesThreshold = 8;

  search::TimeConfig time_config{.nodes = config.hard_node_limit,
                                 .soft_nodes = config.soft_node_limit};
  format::BinPackFormatter formatter(output_stream);

  auto thread = std::make_unique<search::Thread>(0);

  search::Searcher searcher(thread->board);
  searcher.ResizeHash(16);

  const bool from_book = !book.Empty();
  bool new_game = true;
  const int workload = config.num_games / config.num_threads;
  for (int i = 0; i < workload && !stop; i++) {
    // Retain TT and history in book datagen for strength purposes, because we
    // do multiple MultiPv searches when picking the random moves on top of
    // each book position (to roughly maintain the unbalanced starting score)
    if (new_game || !from_book) {
      searcher.NewGame();
      thread->NewGame();
      new_game = false;
    }
    if (!FindStartingPosition(thread, searcher, config, book)) {
      --i;
      continue;
    }

    const auto &state = thread->board.GetState();
    new_game = true;
    formatter.SetPosition(state);

    U64 win_plies = 0, loss_plies = 0, draw_plies = 0;

    std::optional<double> wdl_outcome;
    while (!stop) {
      // Score returned as white-relative
      const auto [score, best_move] =
          searcher.DataGenStart(thread, time_config);

      // The game has ended
      if (!best_move) {
        wdl_outcome = state.InCheck() ? state.turn == Color::kBlack : 0.5;
        break;
      } else {
        if (std::abs(score) >= kMateInMaxPlyScore) {
          // Return the correct score depending on who is getting checkmated
          wdl_outcome = score > 0;
        } else {
          if (score >= kWinThreshold) {
            ++win_plies, loss_plies = draw_plies = 0;
          } else if (score <= -kWinThreshold) {
            ++loss_plies, win_plies = draw_plies = 0;
          } else if (std::abs(score) <= kDrawThreshold &&
                     state.half_moves >= 200) {
            ++draw_plies, win_plies = loss_plies = 0;
          }

          if (win_plies >= kWinPliesThreshold) {
            wdl_outcome = 1.0;
          } else if (loss_plies >= kWinPliesThreshold) {
            wdl_outcome = 0.0;
          } else if (draw_plies >= kDrawPliesThreshold) {
            wdl_outcome = 0.5;
          }
        }
      }

      thread->board.MakeMove(best_move);

      // Check for draw here since search doesn't terminate with an adjudicated
      // draw score at root
      if (thread->board.IsRepetition(0) ||
          thread->board.IsInsufficientMaterial()) {
        wdl_outcome = 0.5;
        break;
      }

      formatter.PushMove(best_move, state.turn, score);

      if (wdl_outcome) {
        break;
      }
    }

    if (wdl_outcome) {
      U64 written;
      {
        std::lock_guard lock(output_mutex);
        if (!output_stream) {
          break;
        }
        const auto positions = formatter.WriteOutcome(*wdl_outcome);
        output_stream.flush();
        if (!output_stream) {
          fmt::println("Error: failed to write datagen output");
          stop = true;
          break;
        }
        written =
            positions_written.fetch_add(positions, std::memory_order_relaxed) +
            positions;
      }
      const auto completed =
          games_completed.fetch_add(1, std::memory_order_relaxed) + 1;

      if (completed % std::clamp<U64>(config.num_games / 50, 1, 1000) == 0 ||
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
  if (config.num_threads <= 0 || config.num_games < config.num_threads ||
      config.min_move_plies < 0 ||
      config.max_move_plies < config.min_move_plies) {
    fmt::println("Error: invalid datagen limits");
    return;
  }
  fmt::println("Starting data generation process...\n");

  stop = false;
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
  start_time = GetCurrentTimeMilliseconds();

  std::vector<std::thread> threads;
  threads.reserve(config.num_threads);

  std::optional<Book> book;
  try {
    book.emplace(config.fens_file);
  } catch (const std::exception &error) {
    fmt::println(
        "Error: cannot open book {}: {}", config.fens_file, error.what());
    return;
  }

  std::ofstream output_stream(path, std::ios::binary | std::ios::app);
  if (!output_stream) {
    fmt::println("Error: cannot open datagen output {}", path);
    return;
  }
  std::mutex output_mutex;
  for (int i = 0; i < config.num_threads; i++) {
    threads.emplace_back([&config, i, &book, &output_stream, &output_mutex]() {
      GameLoop(config, i, output_stream, output_mutex, *book);
    });
  }
  for (auto &thread : threads) {
    thread.join();
  }

  output_stream.close();
  if (!output_stream.good()) {
    fmt::println("Error: failed to close datagen output {}", path);
    return;
  }
  fmt::println("Wrote {} games to {}", games_completed.load(), path);
}

}  // namespace data_gen
