#ifndef INTEGRAL_OPTION_H
#define INTEGRAL_OPTION_H

#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <utility>

#include "../../utils/string.h"
#include "fmt/format.h"

namespace uci {

enum class OptionVisibility {
  kPublic,
  kHidden
};

class Option {
 public:
  Option() : min_(0), max_(0), visibility_(OptionVisibility::kPublic) {}

  explicit Option(
      std::string_view name,
      I64 value,
      I64 min,
      I64 max,
      OptionVisibility visibility = OptionVisibility::kPublic,
      std::function<void(Option &)> callback = [](Option &) {})
      : name_(name),
        type_("spin"),
        default_(std::to_string(value)),
        min_(min),
        max_(max),
        callback_(std::move(callback)),
        visibility_(visibility) {
    value_ = default_;
    callback_(*this);
  }

  explicit Option(
      std::string_view name,
      bool value,
      OptionVisibility visibility = OptionVisibility::kPublic,
      std::function<void(Option &)> callback = [](Option &) {})
      : name_(name),
        type_("check"),
        default_(BoolToString(value)),
        callback_(std::move(callback)),
        visibility_(visibility) {
    value_ = default_;
    callback_(*this);
  }

  explicit Option(
      std::string_view name,
      std::string_view value,
      OptionVisibility visibility = OptionVisibility::kPublic,
      std::function<void(Option &)> callback = [](Option &) {})
      : name_(name),
        type_("string"),
        default_(value),
        callback_(std::move(callback)),
        visibility_(visibility) {
    value_ = default_;
    callback_(*this);
  }

  void SetValue(std::string_view value) {
    value_ = value;
    callback_(*this);
  }

  template <typename T>
  [[nodiscard]] T GetValue() const {
    if constexpr (std::is_integral<T>::value) {
      return T(std::stoull(value_));
    } else if constexpr (std::is_same<T, bool>::value) {
      return StringToBool(value_);
    } else {
      return T(value_);
    }
  }

  [[nodiscard]] std::string ToString() const {
    auto str = fmt::format(
        "option name {} type {} default {}", name_, type_, default_);
    if (type_ == "spin") {
      str += fmt::format(" min {} max {}", min_, max_);
    }
    return str;
  }

  [[nodiscard]] constexpr bool IsPublic() const {
    return visibility_ == OptionVisibility::kPublic;
  }

 private:
  std::string_view name_;
  // Can be "spin", "check", or "string"
  std::string type_;
  // Values are stored as a string for easy conversion
  std::string value_, default_;
  // Should only be used with spin types
  I64 min_, max_;
  // Function to call when the value is changed
  std::function<void(Option &)> callback_;
  // The visibility of this option to the user
  OptionVisibility visibility_;
};

struct CaseInsensitive {
  bool operator()(std::string_view one, std::string_view two) const {
    return std::lexicographical_compare(
        one.begin(), one.end(), two.begin(), two.end(), [](char c1, char c2) {
          return tolower(c1) < tolower(c2);
        });
  }
};

}  // namespace uci

#endif  // INTEGRAL_OPTION_H