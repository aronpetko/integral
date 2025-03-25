#ifndef INTEGRAL_FUSED_H
#define INTEGRAL_FUSED_H

#include <type_traits>

#include "types.h"

enum FusedOperation {
  Add,
  Sub
};

template <FusedOperation... ops,
          typename T,
          std::enable_if_t<sizeof...(ops) == 0, bool> = true>
T Fused(const T& in) {
  return in;
}

template <FusedOperation update_op,
          FusedOperation... ops,
          typename T,
          typename... Ts,
          std::enable_if_t<is_all_same_v<T, Ts...>, bool> = true,
          std::enable_if_t<sizeof...(ops) == sizeof...(Ts), bool> = true>
T Fused(const T& in, const T& operand, const Ts&... operands) {
  switch (update_op) {
    case Add:
      return Fused<ops...>(in + operand, operands...);
    case Sub:
      return Fused<ops...>(in - operand, operands...);
  }
}

#endif
