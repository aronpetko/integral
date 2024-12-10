#ifndef INTEGRAL_SPSA_H
#define INTEGRAL_SPSA_H

#include <string>
#include <type_traits>
#include "../engine/uci/uci.h"

#define SPSA_TUNE
#define PRINT_SPSA_INPUTS

#ifdef SPSA_TUNE
#define TUNABLE(name, value, min, max, disabled) \
  inline Tunable<decltype(value)> name(#name, value, min, max, (max - min) / 20, disabled)

#define TUNABLE_STEP(name, value, min, max, disabled, step) \
  inline Tunable<decltype(value)> name(#name, value, min, max, step, disabled)

constexpr double kLearningRate = 0.002;

template<typename T>
class Tunable {
 public:
  explicit Tunable(std::string_view name,
                   T value,
                   T min,
                   T max,
                   T step = T{},
                   bool disabled = false)
      : value_(value),
        step_(step),
        learning_rate_(kLearningRate) {
#ifdef SPSA_TUNE
    if (disabled) return;

    if constexpr (std::is_same_v<T, int>) {
      uci::listener.AddOption<uci::OptionVisibility::kPublic>(
          name, value, min, max, [this](uci::Option &option) {
            value_ = option.GetValue<int>();
          });
#ifdef PRINT_SPSA_INPUTS
      fmt::println("{}, int, {}, {}, {}, {}, {}", name, value, min, max, step_, learning_rate_);
#endif
    } else if constexpr (std::is_same_v<T, double>) {
      uci::listener.AddOption<uci::OptionVisibility::kPublic>(
          name, std::to_string(value), [this](uci::Option &option) {
            value_ = std::stod(option.GetValue<std::string>());
          });
#ifdef PRINT_SPSA_INPUTS
      fmt::println("{}, float, {}, {}, {}, {}, {}", name, value, min, max, step_, learning_rate_);
#endif
    }
#endif
  }

  constexpr operator T() const {
    return value_;
  }

  [[nodiscard]] T Get() const {
    return value_;
  }

  [[nodiscard]] T GetStep() const {
    return step_;
  }

  [[nodiscard]] double GetLearningRate() const {
    return learning_rate_;
  }

 private:
  T value_;
  T step_;
  double learning_rate_;
};
#else
#define TUNABLE(name, value, min, max, disabled) \
  static constexpr auto name = value

template<typename T>
using Tunable = T;
#endif

#endif  // INTEGRAL_SPSA_H