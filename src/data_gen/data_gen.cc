#include "data_gen.h"

#include <fmt/format.h>

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

    const auto move = legal_moves[RandomU64() % legal_moves.Size()];
    board.MakeMove(move);

    ++current_ply;
  }

  return board;
}

inline std::atomic<U64> positions_written = 0;
inline std::mutex write_mutex;

void GameLoop(const Config &config, std::ostream &output_stream) {
  constexpr int kWinThreshold = 800;
  constexpr int kDrawThreshold = 10;
  constexpr int kPliesThreshold = 5;

  search::TimeConfig time_config{.nodes = config.hard_node_limit,
                                 .soft_nodes = config.soft_node_limit};
  format::BinPackFormatter formatter(output_stream);

  for (int i = 0; i < config.num_games / config.num_threads && !stop; i++) {
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
        positions_written.store(
            positions_written.load(std::memory_order_relaxed) +
                formatter.WriteOutcome(*wdl_outcome),
            std::memory_order_relaxed);
        break;
      }
    }
  }
}

void Generate(Config config) {
  fmt::println("Starting data generation process...");

  const auto time = std::time(nullptr);
  const auto tm = *std::localtime(&time);

  std::stringstream buffer;
  buffer << std::put_time(&tm, "%d-%m-%Y");

  const auto path = config.output_file + "-" + buffer.str();
  const auto start_time = search::GetCurrentTime();

  std::vector<std::thread> threads;
  threads.reserve(config.num_threads);

  std::vector<std::string> temp_files;
  std::atomic<int> successful_threads{0};

  for (int i = 0; i < config.num_threads; i++) {
    const auto thread_path = path + fmt::format("_temp{}", i);
    temp_files.push_back(thread_path);

    threads.emplace_back([&config, &thread_path, i, &successful_threads]() {
      try {
        std::ofstream output_stream(thread_path,
                                    std::ios::binary | std::ios::app);
        if (!output_stream) {
          fmt::println("Error: Failed to open output file {} for thread {}", thread_path, i);
          return;
        }
        GameLoop(config, output_stream);
        output_stream.close();
        if (output_stream.good()) {
          // Explicitly flush to ensure all data is written
          output_stream.flush();
          successful_threads++;
          fmt::println("Thread {} completed successfully", i);
        } else {
          fmt::println("Error: Thread {} encountered an issue while closing the file", i);
        }
      } catch (const std::exception& e) {
        fmt::println("Error: Thread {} threw an exception: {}", i, e.what());
      } catch (...) {
        fmt::println("Error: Thread {} threw an unknown exception", i);
      }
    });
  }

  for (auto &thread : threads) {
    thread.join();
  }

  fmt::println("All threads completed. Successful threads: {}/{}",
               successful_threads.load(), config.num_threads);

  // Add a small delay to ensure file system sync
  std::this_thread::sleep_for(std::chrono::seconds(1));

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
        fmt::println("Successfully concatenated and removed temp file {}", temp_file);
      } else {
        fmt::println("Error: Failed to remove temp file {} after concatenation. Error: {}", temp_file, strerror(errno));
      }
    } else {
      fmt::println("Error: Failed to open temp file {} for concatenation. Error: {}", temp_file, strerror(errno));
    }
  }

  final_output.close();

  fmt::println("Concatenated {} out of {} expected temp files", concatenated_files, config.num_threads);

  const auto time_elapsed = search::GetCurrentTime() - start_time;
  fmt::println("Wrote {} positions. Average Speed: {} pos/sec",
               positions_written.load(),
               positions_written.load() * 1000 / time_elapsed);
}

}  // namespace data_gen