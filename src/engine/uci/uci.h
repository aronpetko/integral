#ifndef INTEGRAL_UCI_H_
#define INTEGRAL_UCI_H_

#include <mutex>
#include <utility>

#include "../../chess/board.h"
#include "../../chess/fen.h"
#include "../../chess/move_gen.h"
#include "command.h"
#include "option.h"

class Search;

namespace uci {

namespace constants {

constexpr std::string_view kEngineName = "Integral v2";
constexpr std::string_view kEngineAuthor = "Aron Petkovski";

}  // namespace constants

class Listener {
 public:
  Listener() = default;

  void Listen() {
    std::string line;
    while (std::getline(std::cin, line)) {
      std::stringstream ss(line);
      std::string command_name;
      ss >> command_name;

      auto it = commands_.find(command_name);
      if (it != commands_.end()) {
        auto &command = it->second;
        command->ProcessLine(ss);
        command->Execute();
      } else {
        fmt::println("error: unknown command: '{}'", command_name);
      }
    }
  }

  void RegisterCommand(std::string_view name,
                       CommandType type,
                       const std::vector<Argument> &arguments,
                       CommandHandler handler) {
    commands_[name] =
        std::make_shared<Command>(name, type, arguments, std::move(handler));
  }

  // Primary template
  template <typename T, OptionVisibility visibility = OptionVisibility::kPublic>
  [[maybe_unused]] void AddOption(
      std::string_view name,
      T value,
      std::function<void(Option &)> callback = [](Option &) {}) {
    static_assert(std::is_same<T, void>::value,
                  "unsupported type for AddOption");
  }

  // Specialization for int
  template <OptionVisibility visibility>
  [[maybe_unused]] std::enable_if_t<std::is_same_v<I64, I64>, void> AddOption(
      std::string_view name,
      I64 value,
      I64 min,
      I64 max,
      std::function<void(Option &)> callback = [](Option &) {}) {
    options_[name] =
        Option(name, value, min, max, visibility, std::move(callback));
  }

  // Specialization for bool
  template <OptionVisibility visibility>
  [[maybe_unused]] std::enable_if_t<std::is_same_v<bool, bool>, void> AddOption(
      std::string_view name,
      bool value,
      std::function<void(Option &)> callback = [](Option &) {}) {
    options_[name] = Option(name, value, visibility, std::move(callback));
  }

  // Specialization for std::string_view
  template <OptionVisibility visibility>
  [[maybe_unused]] std::
      enable_if_t<std::is_same_v<std::string_view, std::string_view>, void>
      AddOption(
          std::string_view name,
          std::string_view value,
          std::function<void(Option &)> callback = [](Option &) {}) {
    options_[name] = Option(name, value, visibility, std::move(callback));
  }

  [[maybe_unused]] Option &GetOption(std::string_view option) {
    std::lock_guard lock(mtx_);
    return options_[option];
  }

  [[maybe_unused]] void PrintOptions() {
    for (const auto &[_, option] : options_) {
      if (option.IsPublic()) {
        fmt::println("{}", option.ToString());
      }
    }
  }

 private:
  std::unordered_map<std::string_view, std::shared_ptr<Command>> commands_;
  std::map<std::string_view, Option, CaseInsensitive> options_;
  std::mutex mtx_;
};

inline Listener listener;

void AcceptCommands(int arg_count, char **args);

}  // namespace uci

#endif  // INTEGRAL_UCI_H_