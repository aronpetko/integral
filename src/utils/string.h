#ifndef INTEGRAL_STRING_H
#define INTEGRAL_STRING_H

#include <vector>
#include <string>
#include <sstream>

static std::vector<std::string> SplitString(const std::string& input,
                                            char delimiter) {
  std::vector<std::string> result;
  std::string token;
  std::istringstream token_stream(input);

  while (getline(token_stream, token, delimiter)) {
    result.push_back(token);
  }

  return result;
}

static std::string RemoveWhitespace(const std::string& input) {
  std::string output;
  for (char c : input) {
    if (!std::isspace(static_cast<unsigned char>(c))) {
      output.push_back(c);
    }
  }
  return output;
}

inline std::string_view BoolToString(bool value) {
  return value ? "true" : "false";
}

#endif  // INTEGRAL_STRING_H