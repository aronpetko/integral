#ifndef INTEGRAL_MULTI_ARRAY_H
#define INTEGRAL_MULTI_ARRAY_H

#include <array>

template <typename T, std::size_t N, std::size_t... Ns>
struct MultiArrayImpl {
  using Type = std::array<typename MultiArrayImpl<T, Ns...>::Type, N>;
};

template <typename T, std::size_t N>
struct MultiArrayImpl<T, N> {
  using Type = std::array<T, N>;
};

template <typename T, std::size_t... Ns>
using MultiArray = typename MultiArrayImpl<T, Ns...>::Type;

#endif  // INTEGRAL_MULTI_ARRAY_H