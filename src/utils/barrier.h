#ifndef INTEGRAL_BARRIER_H
#define INTEGRAL_BARRIER_H

#include <atomic>
#include <cassert>
#include <condition_variable>
#include <mutex>

#include "types.h"

class Barrier {
 public:
  explicit Barrier(I64 expected) {
    Reset(expected);
  }

  void Reset(I64 expected) {
    assert(expected > 0);
    assert(current_.load() == total_.load());

    total_.store(expected, std::memory_order::seq_cst);
    current_.store(expected, std::memory_order::seq_cst);
  }

  void ArriveAndWait() {
    std::unique_lock lock{wait_mutex_};

    const auto current = --current_;

    if (current > 0) {
      const auto phase = phase_.load(std::memory_order::relaxed);
      wait_signal_.wait(lock, [this, phase] {
        return (phase - phase_.load(std::memory_order::acquire)) < 0;
      });
    } else {
      const auto total = total_.load(std::memory_order::acquire);
      current_.store(total, std::memory_order::release);

      ++phase_;

      wait_signal_.notify_all();
    }
  }

  [[nodiscard]] bool IsCleared() const {
    return current_.load(std::memory_order::acquire) ==
           total_.load(std::memory_order::acquire);
  }

 private:
  std::atomic<I64> total_{};
  std::atomic<I64> current_{};
  std::atomic<I64> phase_{};
  std::mutex wait_mutex_{};
  std::condition_variable wait_signal_{};
};

#endif  // INTEGRAL_BARRIER_H