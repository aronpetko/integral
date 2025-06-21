#ifndef INTEGRAL_MATH_H
#define INTEGRAL_MATH_H

constexpr int kQuantizeBase = 1024;

template <typename T>
static constexpr T Lerp(T a, T b, int factor) {
  return (a * (kQuantizeBase - factor) + b * factor) / kQuantizeBase;
}

#endif  // INTEGRAL_MATH_H