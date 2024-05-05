#ifndef INTEGRAL_UCI_OPTION_H
#define INTEGRAL_UCI_OPTION_H

#include <format>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

#include "../utils/string.h"

namespace uci {

class Option {
 public:
  Option() : min_(0), max_(0) {}

  explicit Option(std::string_view name, double value, double min, double max)
      : name_(name),
        type_("spin"),
        default_(std::to_string(value)),
        min_(min),
        max_(max) {
    value_ = default_;
  }

  explicit Option(std::string_view name, int value, double min, double max)
      : name_(name),
        type_("spin"),
        default_(std::to_string(value)),
        min_(min),
        max_(max) {
    value_ = default_;
  }

  explicit Option(std::string_view name, bool value)
      : name_(name), type_("check"), default_(BoolToString(value)) {
    value_ = default_;
  }

  explicit Option(std::string_view name, std::string_view value)
      : name_(name), type_("string"), default_(value) {
    value_ = default_;
  }

  void SetValue(std::string_view value) {
    value_ = value;
  }

  template <typename T>
  [[nodiscard]] T GetValue() const {
    if constexpr (std::is_integral<T>::value) {
      return T(std::stoi(value_));
    }
    return T(value_);
  }

  [[nodiscard]] std::string ToString() const {
    auto str = std::format("option name {} type {} default {} value {}",
                           name_,
                           type_,
                           default_,
                           value_);

    if (type_ == "spin") {
      str += std::format(" min {} max {}", min_, max_);
    }
    return str;
  }

 private:
  std::string_view name_;
  // Can be "spin", "check", or "string"
  std::string type_;
  // Values are stored as a string for easy conversion
  std::string value_, default_;
  // Should only be used with spin types
  double min_, max_;
};

inline std::unordered_map<std::string_view, Option> options;

template <typename T>
inline void AddOption(std::string_view name, T value, double min, double max);

template <>
inline void AddOption<double>(std::string_view name,
                              double value,
                              double min,
                              double max) {
  options[name] = Option(name, value, min, max);
}

template <>
inline void AddOption<int>(std::string_view name,
                           int value,
                           double min,
                           double max) {
  options[name] = Option(name, value, min, max);
}

template <typename T>
inline void AddOption(std::string_view name, T value);

// Specialization for boolean (check option)
template <>
inline void AddOption<bool>(std::string_view name, bool value) {
  options[name] = Option(name, value);
}

// Specialization for string (string option)
template <>
inline void AddOption<std::string_view>(std::string_view name,
                                        std::string_view value) {
  options[name] = Option(name, value);
}

inline void PrintOptions() {
  for (const auto &[_, option] : options) {
    std::cout << option.ToString() << std::endl;
  }
}

}  // namespace uci

#endif  // INTEGRAL_UCI_OPTION_H