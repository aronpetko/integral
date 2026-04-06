#ifndef INTEGRAL_FUSED_H
#define INTEGRAL_FUSED_H

#include <type_traits>

#include "types.h"

enum FusedOperation {
  kAdd,
  kSub
};

template <FusedOperation... ops,
          typename T,
          std::enable_if_t<sizeof...(ops) == 0, bool> = true>
inline constexpr T Fused(const T& in) {
  return in;
}

template <FusedOperation update_op,
          FusedOperation... ops,
          typename T,
          typename... Ts,
          std::enable_if_t<is_all_same_v<T, Ts...>, bool> = true,
          std::enable_if_t<sizeof...(ops) == sizeof...(Ts), bool> = true>
inline constexpr T Fused(const T& in, const T& operand, const Ts&... operands) {
  switch (update_op) {
    case kAdd:
      return Fused<ops...>(static_cast<T>(in + operand), operands...);
    case kSub:
      return Fused<ops...>(static_cast<T>(in - operand), operands...);
  }
}

#endif
