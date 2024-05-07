#ifndef INTEGRAL_UCI_OPTION_H
#define INTEGRAL_UCI_OPTION_H

#include <format>
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <utility>

#include "../utils/string.h"

namespace uci {

class Option {
 public:
  Option() : min_(0), max_(0) {}

  explicit Option(
      std::string_view name,
      int value,
      int min,
      int max,
      std::function<void(Option &)> callback = [](Option &) {})
      : name_(name),
        type_("spin"),
        default_(std::to_string(value)),
        min_(min),
        max_(max),
        callback_(std::move(callback)) {
    value_ = default_;
  }

  explicit Option(
      std::string_view name,
      bool value,
      std::function<void(Option &)> callback = [](Option &) {})
      : name_(name),
        type_("check"),
        default_(BoolToString(value)),
        callback_(std::move(callback)) {
    value_ = default_;
  }

  explicit Option(
      std::string_view name,
      std::string_view value,
      std::function<void(Option &)> callback = [](Option &) {})
      : name_(name),
        type_("string"),
        default_(value),
        callback_(std::move(callback)) {
    value_ = default_;
  }

  void SetValue(std::string_view value) {
    value_ = value;
    callback_(*this);
  }

  template <typename T>
  [[nodiscard]] T GetValue() const {
    if constexpr (std::is_integral<T>::value) {
      return T(std::stoi(value_));
    } else if constexpr (std::is_same<T, bool>::value) {
      return StringToBool(value_);
    } else {
      return T(value_);
    }
  }

  [[nodiscard]] std::string ToString() const {
    auto str = std::format(
        "option name {} type {} default {}", name_, type_, default_);
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
  int min_, max_;
  // Function to call when the value is changed
  std::function<void(Option &)> callback_;
};

struct CaseInsensitive {
  bool operator()(std::string_view one, std::string_view two) const {
    return std::lexicographical_compare(
        one.begin(), one.end(), two.begin(), two.end(), [](char c1, char c2) {
          return tolower(c1) < tolower(c2);
        });
  }
};

inline std::map<std::string_view, Option, CaseInsensitive> options;

template <typename T>
inline void AddOption(
    std::string_view name,
    T value,
    int min,
    int max,
    std::function<void(Option &)> callback = [](Option &) {});

// Specialization for int (spin option)
template <>
inline void AddOption<int>(std::string_view name,
                           int value,
                           int min,
                           int max,
                           std::function<void(Option &)> callback) {
  options[name] = Option(name, value, min, max, std::move(callback));
}

template <typename T>
inline void AddOption(
    std::string_view name,
    T value,
    std::function<void(Option &)> callback = [](Option &) {});

// Specialization for boolean (check option)
template <>
inline void AddOption<bool>(std::string_view name,
                            bool value,
                            std::function<void(Option &)> callback) {
  options[name] = Option(name, value, std::move(callback));
}

// Specialization for string (string option)
template <>
inline void AddOption<std::string_view>(
    std::string_view name,
    std::string_view value,
    std::function<void(Option &)> callback) {
  options[name] = Option(name, value, std::move(callback));
}

static Option &GetOption(std::string_view option) {
  return options[option];
}

static void PrintOptions() {
  for (const auto &[_, option] : options) {
    std::cout << option.ToString() << std::endl;
  }
}

}  // namespace uci

#endif  // INTEGRAL_UCI_OPTION_H