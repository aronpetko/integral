#ifndef INTEGRAL_ASCII_LOGO_H
#define INTEGRAL_ASCII_LOGO_H

#include <iostream>
#include <string>

// clang-format off
constexpr std::string_view kIntegralAsciiLogo =
R"(
    ___     _                     _
   |_ _|_ _| |_ ___ __ _ _ _ __ _| |
    | || ' \  _/ -_) _` | '_/ _` | |
   |___|_||_\__\___\__, |_| \__,_|_|
                   |___/
)";
// clang-format on

inline void PrintAsciiLogo() {
  std::cout << kIntegralAsciiLogo << std::endl;
}

#endif  // INTEGRAL_ASCII_LOGO_H