#ifndef INTEGRAL_TIME_MGMT_H_
#define INTEGRAL_TIME_MGMT_H_

#include <array>
#include <chrono>
#include <condition_variable>
#include <thread>

#include "../chess/board.h"
#include "../utils/types.h"

class TimeManagement {
 public:
  struct Config {
    int depth;
    int move_time;
    std::array<int, 2> time;
    std::array<int, 2> increment;
    Color turn;

    Config() : depth(0), move_time(0), time({}), increment({}) {}
  };

  explicit TimeManagement(const Config &config);

  TimeManagement() = default;

  const Config &get_config();

  void set_config(const Config &config);

  void start();

  void stop();

  void update_nodes_searched();

  void update_nodes_spent_table(Move move, const U64 &nodes_spent);

  [[nodiscard]] bool soft_times_up(Move pv_move);

  [[nodiscard]] bool times_up() const;

  [[nodiscard]] U64 nodes_per_second() const;

  [[nodiscard]] U64 get_nodes_searched() const;

  [[nodiscard]] U64 get_move_time() const;

  [[nodiscard]] U64 time_elapsed() const;

  [[nodiscard]] U64 calculate_hard_limit(Color turn) const;

  [[nodiscard]] U64 calculate_soft_limit(Color turn, Move pv_move) const;

 private:
  [[nodiscard]] int node_table_index(Move move) const;

 private:
  Config config_;
  std::chrono::steady_clock::time_point start_time_, end_time_;
  U64 current_move_time_;
  U64 nodes_searched_;
  bool times_up_;
  std::array<U64, 4096> nodes_spent_table_;
};

#endif // INTEGRAL_TIME_MGMT_H_