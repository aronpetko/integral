#ifndef INTEGRAL_SPSA_H
#define INTEGRAL_SPSA_H

#include "../engine/uci/uci.h"
#include "tuner.h"

// #define SPSA_TUNE

class Tunable {
 public:
  explicit Tunable(std::string_view name,
                   int value,
                   int min,
                   int max,
                   double step,
                   double learning_rate)
      : value_(value) {
    uci::AddOption<uci::OptionVisibility::kHidden>(
        name, value, min, max, [this](uci::Option &option) {
          value_ = option.GetValue<int>();
        });

#ifdef SPSA_TUNE
    fmt::println(
        "{}, {}, {}, {}, {}, {}", name, value, min, max, step, learning_rate);
#endif
  }

  constexpr operator int() const {
    return value_;
  }

  [[nodiscard]] int Get() const {
    return value_;
  }

 private:
  int value_;
};

#endif  // INTEGRAL_SPSA_H