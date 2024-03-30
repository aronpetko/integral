#include "time_mgmt.h"
#include <thread>

TimeManagement::TimeManagement(const TimeManagement::Config &config, Board &board)
    : config_(config),
      board_(board),
      current_move_time_(0),
      times_up_(false),
      worker_processed_(false),
      nodes_searched_(0),
      node_spent_table_({}) {}

const TimeManagement::Config &TimeManagement::get_config() {
  return config_;
}

void TimeManagement::start() {
  start_time_ = std::chrono::steady_clock::now();
  node_spent_table_.fill(0ULL);

  // stop after the hard limit has been passed
  worker = std::thread([this] {
    std::unique_lock<std::mutex> lock(mutex_);
    if (!times_up_.load()) {
      worker_processed_ = true;

      times_up_cv_.wait_for(lock, std::chrono::milliseconds(calculate_hard_limit()), [this] {
        return times_up_.load();
      });

      times_up_ = true;
      end_time_ = std::chrono::steady_clock::now();
    }
  });

  while (!worker_processed_.load()) {
    std::this_thread::yield();
  }
}

void TimeManagement::stop() {
  {
    std::lock_guard<std::mutex> lock(mutex_);
    times_up_ = true;
  }
  times_up_cv_.notify_one();

  if (worker.joinable()) {
    worker.join();
  }

  end_time_ = std::chrono::steady_clock::now();
}

[[nodiscard]] long long TimeManagement::calculate_hard_limit() {
  const auto &state = board_.get_state();
  return config_.move_time ? config_.move_time : config_.time[state.turn] / 20 + config_.increment[state.turn] / 2;
}

[[nodiscard]] long long TimeManagement::calculate_soft_limit(const Move &pv_move) {
  // taken from chessatron
  const auto best_move_fraction =
      static_cast<double>(node_spent_table_[pv_move.get_data() % 4096]) / std::max(1LL, nodes_searched_);
  const auto hard_limit = calculate_hard_limit();
  return ((hard_limit / 10) * 3) * (1.6 - best_move_fraction) * 1.5;
}

void TimeManagement::update_nodes_searched() {
  ++nodes_searched_;
}

void TimeManagement::update_node_spent_table(const Move &move, long long prev_nodes_searched) {
  const long long nodes_spent = nodes_searched_ - prev_nodes_searched;
  node_spent_table_[move.get_data() % 4096] += nodes_spent;
}

bool TimeManagement::times_up() const {
  return !config_.depth && times_up_.load();
}

bool TimeManagement::root_times_up(const Move &pv_move) {
  return config_.depth == 0 && time_elapsed() >= calculate_soft_limit(pv_move);
}

long long TimeManagement::nodes_per_second() const {
  const double time_in_ms =
      std::max(times_up_ ? duration_cast<std::chrono::milliseconds>(end_time_ - start_time_).count() : time_elapsed(),
               1LL);
  return nodes_searched_ * 1000.0 / time_in_ms;
}

long long TimeManagement::get_nodes_searched() const {
  return nodes_searched_;
}

long long TimeManagement::get_move_time() const {
  return current_move_time_;
}

long long TimeManagement::time_elapsed() const {
  return duration_cast<std::chrono::milliseconds>(
      std::chrono::steady_clock::now() - start_time_).count();
}