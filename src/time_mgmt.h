#ifndef INTEGRAL_TIME_MGMT_H_
#define INTEGRAL_TIME_MGMT_H_

#include "types.h"
#include "board.h"

#include <array>

class TimeManagement {
 public:
  struct Config {
    int depth{};
    int move_time{};
    std::array<int, 2> time{};
    std::array<int, 2> increment{};
  };

  explicit TimeManagement(const Config &config, Board &board);

  const Config &get_config();

  void start();

  void update_move_time(const Move &pv_move);

  void update_nodes_searched();

  void update_node_spent_table(const Move &move, int prev_nodes_searched);

  [[nodiscard]] bool times_up();

  [[nodiscard]] int get_nodes_searched() const;

  [[nodiscard]] int get_move_time() const;

  [[nodiscard]] long long time_elapsed() const;

 private:
  const Config &config_;
  Board &board_;
  std::chrono::steady_clock::time_point start_time_;
  int current_move_time_;
  int nodes_searched_;
  bool times_up_;
  std::array<U64, 4096> node_spent_table_;
};

#endif // INTEGRAL_TIME_MGMT_H_