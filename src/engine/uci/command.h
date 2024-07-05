#ifndef INTEGRAL_COMMAND_H
#define INTEGRAL_COMMAND_H

#include <functional>
#include <iostream>
#include <map>
#include <optional>
#include <string>

#include "../../utils/string.h"
#include "fmt/format.h"

namespace uci {

enum class ArgumentType {
  kOptional,
  kRequired
};

class CommandInputProcessor {
 public:
  virtual ~CommandInputProcessor() = default;
  virtual bool Process(std::stringstream &stream, std::string &output) = 0;
};

struct NoInputProcessor : public CommandInputProcessor {
 public:
  bool Process(std::stringstream &stream, std::string &output) override {
    return true;
  }
};

template <std::size_t N>
struct LimitedInputProcessor : public CommandInputProcessor {
 public:
  bool Process(std::stringstream &stream, std::string &output) override {
    output.clear();

    std::size_t i;
    for (i = 0; i < N; i++) {
      std::string input;
      if (!(stream >> input)) return false;

      output += input + " ";
    }

    output.pop_back();  // Remove the trailing space
    return i == N;
  }
};

struct UnlimitedInputProcessor : public CommandInputProcessor {
 public:
  bool Process(std::stringstream &stream, std::string &output) override {
    std::string input;
    while (stream >> input) {
      output += input + " ";
    }

    output.pop_back();  // Remove the trailing space
    return true;
  }
};

class Argument {
 public:
  explicit Argument(std::string_view name,
                    ArgumentType type,
                    std::shared_ptr<CommandInputProcessor> processor)
      : name_(name), type_(type), processor_(std::move(processor)) {}

  void ProcessInput(std::stringstream &stream) {
    processor_->Process(stream, input_);
    SetProcessed(true);
  }

  [[nodiscard]] bool BeenProcessed() const {
    return processed_;
  }

  void SetProcessed(bool value) {
    processed_ = value;
    if (!value) input_.clear();
  }

  [[nodiscard]] bool HasInput() const {
    return !input_.empty();
  }

  [[nodiscard]] std::string_view GetName() const {
    return name_;
  }

  [[nodiscard]] std::string GetInput() const {
    return input_;
  }

  [[nodiscard]] ArgumentType GetType() const {
    return type_;
  }

 private:
  std::string_view name_;
  ArgumentType type_;
  std::shared_ptr<CommandInputProcessor> processor_;
  std::string input_;
  bool processed_;
};

enum class CommandType {
  kOrdered,
  kUnordered
};

class Command;
using CommandHandler = std::function<void(Command *)>;

class Command {
 public:
  explicit Command(std::string_view name,
                   CommandType type,
                   std::vector<Argument> args,
                   CommandHandler handler)
      : name_(name),
        type_(type),
        args_(std::move(args)),
        handler_(std::move(handler)),
        args_idx_(0) {}

  // Processes the input stream based on the command type (Ordered or Unordered)
  void ProcessLine(std::stringstream &stream) {
    args_idx_ = 0;
    if (type_ == CommandType::kOrdered) {
      ProcessOrderedArguments(stream);
    } else {
      ProcessUnorderedArguments(stream);
    }
  }

  // Executes the command after all arguments have been processed
  void Execute() {
    // Check if all required arguments have been provided
    for (const auto &arg : args_) {
      if (arg.GetType() == ArgumentType::kRequired && arg.GetInput().empty()) {
        throw std::runtime_error(
            fmt::format("required argument '{}' is missing", arg.GetName()));
      }
    }
    // Call the command handler
    handler_(this);
  }

  // Parses and returns the value of a specific argument
  template <typename T>
  [[nodiscard]] std::optional<T> ParseArgument(std::string_view argument_name) {
    auto argument = FindArgument(argument_name);
    if (argument != args_.end() && argument->HasInput()) {
      if constexpr (std::is_same_v<T, std::string>) {
        return argument->GetInput();
      }

      std::stringstream stream(argument->GetInput());
      T value;
      if (!(stream >> value)) {
        throw std::runtime_error(fmt::format(
            "argument '{}' couldn't be parsed correctly", argument_name));
      }
      return value;
    }
    return std::nullopt;
  }

  // Checks if an argument with the given name exists
  [[nodiscard]] bool ArgumentExists(std::string_view argument_name) {
    auto it = FindArgument(argument_name);
    return it != args_.end() && it->BeenProcessed();
  }

 private:
  // Processes arguments in order, matching argument names with their expected
  // positions
  void ProcessOrderedArguments(std::stringstream &stream) {
    std::string argument_name;
    while (stream >> argument_name) {
      bool argument_processed = false;

      // Search for the matching argument starting from the current index
      for (std::size_t i = args_idx_; i < args_.size(); ++i) {
        auto &current_arg = args_[i];
        current_arg.SetProcessed(false);

        if (current_arg.GetName() == argument_name) {
          // The argument name matches, process it
          current_arg.ProcessInput(stream);
          current_arg.SetProcessed(true);
          argument_processed = true;
          args_idx_ = i + 1;  // Move to the next argument
          break;
        } else if (current_arg.GetType() == ArgumentType::kRequired) {
          // If we encounter a required argument that doesn't match, it's an
          // error
          fmt::println("error: expected argument '{}', but got '{}'",
                       current_arg.GetName(),
                       argument_name);
          return;
        }
        // If it's optional and doesn't match, continue searching
      }

      if (!argument_processed) {
        // If we've gone through all arguments and haven't found a match, it's
        // an unknown argument
        fmt::println("error: unknown argument '{}'", argument_name);
      }

      if (stream.fail()) {
        // If stream fails, stop processing
        break;
      }
    }

    // Check if any required arguments are missing
    for (size_t i = args_idx_; i < args_.size(); ++i) {
      if (args_[i].GetType() == ArgumentType::kRequired) {
        fmt::println("error: missing required argument '{}'",
                     args_[i].GetName());
      }
    }
  }

  // Processes arguments in any order, matching them by name
  void ProcessUnorderedArguments(std::stringstream &stream) {
    std::string argument_name;
    while (stream >> argument_name) {
      auto argument = FindArgument(argument_name);
      if (argument != args_.end()) {
        argument->ProcessInput(stream);
      } else {
        fmt::println("unknown argument: '{}'", argument_name);
      }
    }
  }

  // Finds an argument by name in the args_ vector
  std::vector<Argument>::iterator FindArgument(std::string_view argument_name) {
    return std::ranges::find_if(args_, [&argument_name](const Argument &arg) {
      return arg.GetName() == argument_name;
    });
  }

 private:
  std::string_view name_;
  CommandType type_;
  std::vector<Argument> args_;
  CommandHandler handler_;
  std::size_t args_idx_;
};

template <typename T>
Argument CreateArgument(std::string_view name, ArgumentType type, T processor) {
  return Argument(name, type, std::make_shared<T>(std::move(processor)));
}

}  // namespace uci

#endif  // INTEGRAL_COMMAND_H