#ifndef INTEGRAL_UCI_H_
#define INTEGRAL_UCI_H_

#include <any>
#include <format>
#include <utility>

#include "../utils/string.h"
#include "board.h"
#include "fen.h"

class Search;

namespace uci {

const std::string kEngineName = "Integral";
const std::string kEngineVersion = "0.1";
const std::string kEngineAuthor = "Aron Petkovski";

class Option {
 public:
  Option() {}

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

void Position(Board &board, std::stringstream &input_stream);

void Go(Board &board, Search &search, std::stringstream &input_stream);

void Test(Board &board, std::stringstream &input_stream);

void AcceptCommands(int arg_count, char **args);

}  // namespace uci

#endif  // INTEGRAL_UCI_H_