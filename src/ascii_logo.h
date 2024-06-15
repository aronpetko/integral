#ifndef INTEGRAL_ASCII_LOGO_H
#define INTEGRAL_ASCII_LOGO_H

#include <iostream>
#include <string>

// clang-format off
constexpr std::string_view kIntegralAsciiLogo =
R"(
                   πππ
                  ππ ππ
                 ππ
                ππ
               ππ
           ππ ππ
            πππ
)";
// clang-format on

inline void PrintAsciiLogo() {
  fmt::println("{}", kIntegralAsciiLogo);
}

#endif  // INTEGRAL_ASCII_LOGO_H