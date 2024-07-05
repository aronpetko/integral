#ifndef INTEGRAL_SPSA_H
#define INTEGRAL_SPSA_H

#include "../engine/uci/uci.h"
#include "tuner.h"

// #define SPSA_TUNE

class Tunable {
 public:
  explicit Tunable(std::string_view name,
                   double value,
                   double min,
                   double max,
                   double learning_rate = 0.002)
      : value_(value) {
    const int exponent = std::max({GetScalingExponent(value),
                                   GetScalingExponent(min),
                                   GetScalingExponent(max)});
    scaling_constant_ = static_cast<int>(std::pow(10, exponent));

    const auto int_value = static_cast<I64>(value * scaling_constant_);
    const auto int_min = static_cast<I64>(min * scaling_constant_);
    const auto int_max = static_cast<I64>(max * scaling_constant_);

    uci::listener.AddOption<uci::OptionVisibility::kHidden>(
        name, int_value, int_min, int_max, [this](uci::Option &option) {
          value_ =
              option.GetValue<I64>() / static_cast<double>(scaling_constant_);
        });

#ifdef SPSA_TUNE
    constexpr double kStepFactor = 0.05;
    const int step = (int_max - int_min) * kStepFactor;
    fmt::println("{}, {}, {}, {}, {}, {}",
                 name,
                 int_value,
                 int_min,
                 int_max,
                 step,
                 learning_rate);
#endif
  }

  constexpr operator double() const {
    return value_;
  }

  [[nodiscard]] double Get() const {
    return value_;
  }

 private:
  [[nodiscard]] int GetScalingExponent(double number) const {
    int exponent = 0;
    while (std::floor(number) != number) {
      number *= 10;
      exponent++;
    }
    return exponent;
  }

 private:
  double value_;
  int scaling_constant_;
};

#endif  // INTEGRAL_SPSA_H