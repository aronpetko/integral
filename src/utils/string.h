#ifndef INTEGRAL_STRING_H
#define INTEGRAL_STRING_H

#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

static std::vector<std::string> SplitString(std::string_view input,
                                            char delimiter) {
  std::vector<std::string> result;
  std::string token;
  std::istringstream token_stream((std::string(input)));

  while (getline(token_stream, token, delimiter)) {
    result.push_back(token);
  }

  return result;
}

static std::string RemoveWhitespace(std::string_view input) {
  std::string output;
  for (char c : input) {
    if (!std::isspace(static_cast<unsigned char>(c))) {
      output.push_back(c);
    }
  }
  return output;
}

static std::string ToLowercase(std::string string) {
  std::ranges::transform(string, string.begin(), [](auto ch) {
    return std::tolower(ch, std::locale());
  });
  return string;
}

inline std::string_view BoolToString(bool value) {
  return value ? "true" : "false";
}

inline bool StringToBool(std::string_view string) {
  return ToLowercase(std::string(string)) == "true";
}

#endif  // INTEGRAL_STRING_H