#ifndef INTEGRAL_SIMD_H_
#define INTEGRAL_SIMD_H_

#include <array>
#include <bit>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <type_traits>
#include <utility>

#include "../src/utils/types.h"

#if defined(BUILD_NATIVE)
#if __BMI2__ && defined(BUILD_FAST_PEXT)
#define BUILD_HAS_BMI2 1
#else
#define BUILD_HAS_BMI2 0
#endif
#define BUILD_HAS_AVX512VBMI __AVX512VBMI__
#define BUILD_HAS_AVX512VNNI __AVX512VNNI__
#define BUILD_HAS_AVX512 (__AVX512F__ && (__AVX512BW__ || __AVX512VNNI__))
#define BUILD_HAS_AVX2 __AVX2__
#define BUILD_HAS_SSE41 __SSE4_1__
#define BUILD_HAS_BMI1 __BMI__
#define BUILD_HAS_POPCNT __POPCNT__
#define BUILD_HAS_NEON __ARM_NEON
#elif defined(BUILD_VBMI512)
#define BUILD_HAS_BMI2 1
#define BUILD_HAS_AVX512VBMI 1
#define BUILD_HAS_AVX512VNNI 1
#define BUILD_HAS_AVX512 1
#define BUILD_HAS_AVX2 1
#define BUILD_HAS_SSE41 1
#define BUILD_HAS_BMI1 1
#define BUILD_HAS_POPCNT 1
#define BUILD_HAS_NEON 0
#elif defined(BUILD_VNNI512)
#define BUILD_HAS_BMI2 1
#define BUILD_HAS_AVX512VBMI 0
#define BUILD_HAS_AVX512VNNI 1
#define BUILD_HAS_AVX512 1
#define BUILD_HAS_AVX2 1
#define BUILD_HAS_SSE41 1
#define BUILD_HAS_BMI1 1
#define BUILD_HAS_POPCNT 1
#define BUILD_HAS_NEON 0
#elif defined(BUILD_AVX512)
#define BUILD_HAS_BMI2 1
#define BUILD_HAS_AVX512VBMI 0
#define BUILD_HAS_AVX512VNNI 0
#define BUILD_HAS_AVX512 1
#define BUILD_HAS_AVX2 1
#define BUILD_HAS_SSE41 1
#define BUILD_HAS_BMI1 1
#define BUILD_HAS_POPCNT 1
#define BUILD_HAS_NEON 0
#elif defined(BUILD_AVX2_BMI2)
#define BUILD_HAS_BMI2 1
#define BUILD_HAS_AVX512VBMI 0
#define BUILD_HAS_AVX512VNNI 0
#define BUILD_HAS_AVX512 0
#define BUILD_HAS_AVX2 1
#define BUILD_HAS_SSE41 1
#define BUILD_HAS_BMI1 1
#define BUILD_HAS_POPCNT 1
#define BUILD_HAS_NEON 0
#elif defined(BUILD_AVX2)
#define BUILD_HAS_BMI2 0
#define BUILD_HAS_AVX512VBMI 0
#define BUILD_HAS_AVX512VNNI 0
#define BUILD_HAS_AVX512 0
#define BUILD_HAS_AVX2 1
#define BUILD_HAS_SSE41 1
#define BUILD_HAS_BMI1 1
#define BUILD_HAS_POPCNT 1
#define BUILD_HAS_NEON 0
#elif defined(BUILD_SSE41_POPCNT)
#define BUILD_HAS_BMI2 0
#define BUILD_HAS_AVX512VBMI 0
#define BUILD_HAS_AVX512VNNI 0
#define BUILD_HAS_AVX512 0
#define BUILD_HAS_AVX2 0
#define BUILD_HAS_SSE41 1
#define BUILD_HAS_BMI1 0
#define BUILD_HAS_POPCNT 1
#define BUILD_HAS_NEON 0
#else
#error No architecture specified
#endif

#define BUILD_HAS_SIMD \
  (BUILD_HAS_AVX512 || BUILD_HAS_AVX2 || BUILD_HAS_SSE41 || BUILD_HAS_NEON)

#if BUILD_HAS_AVX512 || BUILD_HAS_AVX2 || BUILD_HAS_SSE41
#include <immintrin.h>
#elif BUILD_HAS_NEON
#include <arm_neon.h>
#endif

namespace simd {

#if BUILD_HAS_AVX512
constexpr std::size_t kVectorBytes = 64;
#elif BUILD_HAS_AVX2
constexpr std::size_t kVectorBytes = 32;
#elif BUILD_HAS_SSE41 || BUILD_HAS_NEON
constexpr std::size_t kVectorBytes = 16;
#else
constexpr std::size_t kVectorBytes = 16;
#endif

constexpr std::size_t kAlignment = kVectorBytes < 16 ? 16 : kVectorBytes;

[[nodiscard]] constexpr auto NextMultiple(auto x, auto m) {
  return x + (m - x % m) % m;
}

namespace detail {

template <typename T, std::size_t N>
struct VectorHelper {
  using Type __attribute__((__vector_size__(N * sizeof(T)))) = T;
};

}  // namespace detail

template <typename T, std::size_t N>
using Vector = typename detail::VectorHelper<T, N>::Type;

template <typename T>
constexpr std::size_t kNativeLanes = kVectorBytes / sizeof(T);

template <typename T>
using Native = Vector<T, kNativeLanes<T>>;

template <typename V>
using ElementOf = std::remove_cvref_t<decltype(std::declval<V&>()[0])>;

template <typename V>
constexpr std::size_t kLanesOf = sizeof(V) / sizeof(ElementOf<V>);

template <typename V>
constexpr std::size_t kBytesOf = sizeof(V);

using Vepi8 = Native<I8>;
using Vepu8 = Native<U8>;
using Vepi16 = Native<I16>;
using Vepi32 = Native<I32>;
using Vepi64 = Native<I64>;
using Vepf32 = Native<float>;

template <typename T, std::size_t N = kNativeLanes<T>>
[[nodiscard]] inline Vector<T, N> Load(const T* ptr) {
  struct __attribute__((packed, may_alias)) Unaligned {
    Vector<T, N> v;
  };
  return reinterpret_cast<const Unaligned*>(ptr)->v;
}

template <typename T,
          std::size_t N = kNativeLanes<T>,
          typename V = Vector<T, N>>
inline void Store(T* ptr, V v) {
  struct __attribute__((packed, may_alias)) Unaligned {
    Vector<T, N> v;
  };
  reinterpret_cast<Unaligned*>(ptr)->v = v;
}

template <typename T, std::size_t N = kNativeLanes<T>>
[[nodiscard]] inline Vector<T, N> Set(T value) {
  if constexpr (std::is_floating_point_v<T>) {
#if BUILD_HAS_AVX512
    if constexpr (N == 16)
      return std::bit_cast<Vector<T, N>>(_mm512_set1_ps(value));
#elif BUILD_HAS_AVX2
    if constexpr (N == 8)
      return std::bit_cast<Vector<T, N>>(_mm256_set1_ps(value));
#elif BUILD_HAS_SSE41
    if constexpr (N == 4)
      return std::bit_cast<Vector<T, N>>(_mm_set1_ps(value));
#endif
  }
  // 0 + x is exact for integers
  return Vector<T, N>{} + value;
}

template <typename T, std::size_t N = kNativeLanes<T>>
[[nodiscard]] inline Vector<T, N> Zero() {
  return Set<T, N>(T{0});
}

template <typename T, std::size_t N = kNativeLanes<T>>
[[nodiscard]] inline Vector<T, N>& AsVector(T* ptr) {
  return *reinterpret_cast<Vector<T, N>*>(ptr);
}

template <typename T, std::size_t N = kNativeLanes<T>>
[[nodiscard]] inline const Vector<T, N>& AsVector(const T* ptr) {
  return *reinterpret_cast<const Vector<T, N>*>(ptr);
}

template <typename V>
[[nodiscard]] inline V Min(V a, V b) {
  if constexpr (std::is_same_v<ElementOf<V>, float>) {
#if BUILD_HAS_AVX512
    if constexpr (kLanesOf<V> == 16)
      return std::bit_cast<V>(
          _mm512_min_ps(std::bit_cast<__m512>(a), std::bit_cast<__m512>(b)));
#elif BUILD_HAS_AVX2
    if constexpr (kLanesOf<V> == 8)
      return std::bit_cast<V>(
          _mm256_min_ps(std::bit_cast<__m256>(a), std::bit_cast<__m256>(b)));
#elif BUILD_HAS_SSE41
    if constexpr (kLanesOf<V> == 4)
      return std::bit_cast<V>(
          _mm_min_ps(std::bit_cast<__m128>(a), std::bit_cast<__m128>(b)));
#endif
  }
#if defined(__clang__)
  if constexpr (std::is_integral_v<ElementOf<V>>)
    return __builtin_elementwise_min(a, b);
#endif
  return a < b ? a : b;
}

template <typename V>
[[nodiscard]] inline V Max(V a, V b) {
  if constexpr (std::is_same_v<ElementOf<V>, float>) {
#if BUILD_HAS_AVX512
    if constexpr (kLanesOf<V> == 16)
      return std::bit_cast<V>(
          _mm512_max_ps(std::bit_cast<__m512>(a), std::bit_cast<__m512>(b)));
#elif BUILD_HAS_AVX2
    if constexpr (kLanesOf<V> == 8)
      return std::bit_cast<V>(
          _mm256_max_ps(std::bit_cast<__m256>(a), std::bit_cast<__m256>(b)));
#elif BUILD_HAS_SSE41
    if constexpr (kLanesOf<V> == 4)
      return std::bit_cast<V>(
          _mm_max_ps(std::bit_cast<__m128>(a), std::bit_cast<__m128>(b)));
#endif
  }
#if defined(__clang__)
  if constexpr (std::is_integral_v<ElementOf<V>>)
    return __builtin_elementwise_max(a, b);
#endif
  return a > b ? a : b;
}

template <typename V>
[[nodiscard]] inline V Clamp(V v, ElementOf<V> lo, ElementOf<V> hi) {
  return Min(Max(v, Set<ElementOf<V>, kLanesOf<V>>(lo)),
             Set<ElementOf<V>, kLanesOf<V>>(hi));
}

template <typename V>
[[nodiscard]] inline V Clip(V v, ElementOf<V> q) {
  return Clamp(v, ElementOf<V>{0}, q);
}

template <typename V>
[[nodiscard]] inline V MultiplyAdd(V a, V b, V c) {
  return a * b + c;
}

template <typename To, typename V>
[[nodiscard]] inline auto Convert(V v) {
  using From = ElementOf<V>;
  constexpr std::size_t N = kLanesOf<V>;
  if constexpr (std::is_same_v<From, I8> && std::is_same_v<To, I16>) {
#if BUILD_HAS_AVX512
    if constexpr (N == 32)
      return std::bit_cast<Vector<I16, 32>>(
          _mm512_cvtepi8_epi16(std::bit_cast<__m256i>(v)));
#elif BUILD_HAS_AVX2
    if constexpr (N == 16)
      return std::bit_cast<Vector<I16, 16>>(
          _mm256_cvtepi8_epi16(std::bit_cast<__m128i>(v)));
#elif BUILD_HAS_SSE41
    if constexpr (N == 8) {
      __m128i wide;
      std::memcpy(&wide, &v, sizeof(v));
      return std::bit_cast<Vector<I16, 8>>(_mm_cvtepi8_epi16(wide));
    }
#endif
  }
  if constexpr (std::is_same_v<From, I16> && std::is_same_v<To, I32>) {
#if BUILD_HAS_AVX512
    if constexpr (N == 16)
      return std::bit_cast<Vector<I32, 16>>(
          _mm512_cvtepi16_epi32(std::bit_cast<__m256i>(v)));
#elif BUILD_HAS_AVX2
    if constexpr (N == 8)
      return std::bit_cast<Vector<I32, 8>>(
          _mm256_cvtepi16_epi32(std::bit_cast<__m128i>(v)));
#elif BUILD_HAS_SSE41
    if constexpr (N == 4) {
      __m128i wide;
      std::memcpy(&wide, &v, sizeof(v));
      return std::bit_cast<Vector<I32, 4>>(_mm_cvtepi16_epi32(wide));
    }
#endif
  }
  return __builtin_convertvector(v, Vector<To, N>);
}

template <typename To, typename V>
[[nodiscard]] inline auto Cast(V v) {
  return std::bit_cast<Vector<To, sizeof(V) / sizeof(To)>>(v);
}

template <typename V>
[[nodiscard]] inline auto LowerHalf(V v) {
  Vector<ElementOf<V>, kLanesOf<V> / 2> out;
  std::memcpy(&out, &v, sizeof(out));
  return out;
}

template <typename V>
[[nodiscard]] inline auto UpperHalf(V v) {
  Vector<ElementOf<V>, kLanesOf<V> / 2> out;
  std::memcpy(&out,
              reinterpret_cast<const ElementOf<V>*>(&v) + kLanesOf<V> / 2,
              sizeof(out));
  return out;
}

template <typename V>
[[nodiscard]] inline auto Concat(V lo, V hi) {
  Vector<ElementOf<V>, kLanesOf<V> * 2> out;
  std::memcpy(&out, &lo, sizeof(lo));
  std::memcpy(
      reinterpret_cast<ElementOf<V>*>(&out) + kLanesOf<V>, &hi, sizeof(hi));
  return out;
}

template <typename V>
[[nodiscard]] inline ElementOf<V> ReduceAdd(V v) {
  using E = ElementOf<V>;
  constexpr std::size_t kLanes = kLanesOf<V>;
#if BUILD_HAS_AVX512
  if constexpr (std::is_same_v<E, I32> && kLanes == 16) {
    return _mm512_reduce_add_epi32(std::bit_cast<__m512i>(v));
  }
  if constexpr (std::is_same_v<E, float> && kLanes == 16) {
    return _mm512_reduce_add_ps(std::bit_cast<__m512>(v));
  }
#elif BUILD_HAS_AVX2
  if constexpr (std::is_same_v<E, I32> && kLanes == 8) {
    const __m256i vv = std::bit_cast<__m256i>(v);
    const __m128i lower128 = _mm256_castsi256_si128(vv);
    const __m128i upper128 = _mm256_extracti128_si256(vv, 1);
    const __m128i sum128 = _mm_add_epi32(lower128, upper128);
    const __m128i upper64 = _mm_unpackhi_epi64(sum128, sum128);
    const __m128i sum64 = _mm_add_epi32(upper64, sum128);
    const __m128i upper32 = _mm_shuffle_epi32(sum64, 1);
    const __m128i sum32 = _mm_add_epi32(upper32, sum64);
    return _mm_cvtsi128_si32(sum32);
  }
  if constexpr (std::is_same_v<E, float> && kLanes == 8) {
    const __m256 vv = std::bit_cast<__m256>(v);
    const __m128 sum128 =
        _mm_add_ps(_mm256_castps256_ps128(vv), _mm256_extractf128_ps(vv, 1));
    const __m128 upper64 = _mm_movehl_ps(sum128, sum128);
    const __m128 sum64 = _mm_add_ps(sum128, upper64);
    const __m128 upper32 = _mm_shuffle_ps(sum64, sum64, 1);
    const __m128 sum32 = _mm_add_ss(sum64, upper32);
    return _mm_cvtss_f32(sum32);
  }
#elif BUILD_HAS_SSE41
  if constexpr (std::is_same_v<E, I32> && kLanes == 4) {
    const __m128i vv = std::bit_cast<__m128i>(v);
    const __m128i upper64 = _mm_unpackhi_epi64(vv, vv);
    const __m128i sum64 = _mm_add_epi32(upper64, vv);
    const __m128i upper32 = _mm_shuffle_epi32(sum64, 1);
    const __m128i sum32 = _mm_add_epi32(upper32, sum64);
    return _mm_cvtsi128_si32(sum32);
  }
  if constexpr (std::is_same_v<E, float> && kLanes == 4) {
    const __m128 vv = std::bit_cast<__m128>(v);
    const __m128 upper64 = _mm_movehl_ps(vv, vv);
    const __m128 sum64 = _mm_add_ps(vv, upper64);
    const __m128 upper32 = _mm_shuffle_ps(sum64, sum64, 1);
    const __m128 sum32 = _mm_add_ss(sum64, upper32);
    return _mm_cvtss_f32(sum32);
  }
#endif
  E lanes[kLanes];
  std::memcpy(lanes, &v, sizeof(lanes));
  E sum = E{0};
  for (std::size_t i = 0; i < kLanes; ++i) sum += lanes[i];
  return sum;
}

template <typename V, std::size_t Count>
[[nodiscard]] inline ElementOf<V> ReduceAdd(const std::array<V, Count>& vs) {
  V acc = vs[0];
  for (std::size_t i = 1; i < Count; ++i) acc += vs[i];
  return ReduceAdd(acc);
}

#if BUILD_HAS_AVX512
constexpr int kPackusOrder[8] = {0, 2, 4, 6, 1, 3, 5, 7};
#elif BUILD_HAS_AVX2
constexpr int kPackusOrder[4] = {0, 2, 1, 3};
#else
constexpr int kPackusOrder[2] = {0, 1};
#endif

[[nodiscard]] inline Vepi32 MultiplyAddEpi16(Vepi16 a, Vepi16 b) {
#if BUILD_HAS_AVX512
  return std::bit_cast<Vepi32>(
      _mm512_madd_epi16(std::bit_cast<__m512i>(a), std::bit_cast<__m512i>(b)));
#elif BUILD_HAS_AVX2
  return std::bit_cast<Vepi32>(
      _mm256_madd_epi16(std::bit_cast<__m256i>(a), std::bit_cast<__m256i>(b)));
#elif BUILD_HAS_SSE41
  return std::bit_cast<Vepi32>(
      _mm_madd_epi16(std::bit_cast<__m128i>(a), std::bit_cast<__m128i>(b)));
#else
  Vepi32 out{};
  for (std::size_t i = 0; i < kNativeLanes<I32>; ++i)
    out[i] =
        I32(a[2 * i]) * I32(b[2 * i]) + I32(a[2 * i + 1]) * I32(b[2 * i + 1]);
  return out;
#endif
}

[[nodiscard]] inline Vepi16 MulhiEpi16(Vepi16 a, Vepi16 b) {
#if BUILD_HAS_AVX512
  return std::bit_cast<Vepi16>(
      _mm512_mulhi_epi16(std::bit_cast<__m512i>(a), std::bit_cast<__m512i>(b)));
#elif BUILD_HAS_AVX2
  return std::bit_cast<Vepi16>(
      _mm256_mulhi_epi16(std::bit_cast<__m256i>(a), std::bit_cast<__m256i>(b)));
#elif BUILD_HAS_SSE41
  return std::bit_cast<Vepi16>(
      _mm_mulhi_epi16(std::bit_cast<__m128i>(a), std::bit_cast<__m128i>(b)));
#else
  Vepi16 out{};
  for (std::size_t i = 0; i < kNativeLanes<I16>; ++i)
    out[i] = I16((I32(a[i]) * I32(b[i])) >> 16);
  return out;
#endif
}

[[nodiscard]] inline Vepu8 PackusEpi16(Vepi16 a, Vepi16 b) {
#if BUILD_HAS_AVX512
  return std::bit_cast<Vepu8>(_mm512_packus_epi16(std::bit_cast<__m512i>(a),
                                                  std::bit_cast<__m512i>(b)));
#elif BUILD_HAS_AVX2
  return std::bit_cast<Vepu8>(_mm256_packus_epi16(std::bit_cast<__m256i>(a),
                                                  std::bit_cast<__m256i>(b)));
#elif BUILD_HAS_SSE41
  return std::bit_cast<Vepu8>(
      _mm_packus_epi16(std::bit_cast<__m128i>(a), std::bit_cast<__m128i>(b)));
#else
  constexpr std::size_t kHalf = kNativeLanes<I16>;
  Vepu8 out{};
  for (std::size_t i = 0; i < kHalf; ++i) {
    out[i] = U8(a[i] < 0 ? 0 : (a[i] > 255 ? 255 : a[i]));
    out[i + kHalf] = U8(b[i] < 0 ? 0 : (b[i] > 255 ? 255 : b[i]));
  }
  return out;
#endif
}

[[nodiscard]] inline Vepi32 DpbusdEpi32(Vepi32 sum, Vepu8 u, Vepi8 i) {
#if BUILD_HAS_AVX512VNNI
  return std::bit_cast<Vepi32>(_mm512_dpbusd_epi32(std::bit_cast<__m512i>(sum),
                                                   std::bit_cast<__m512i>(u),
                                                   std::bit_cast<__m512i>(i)));
#elif BUILD_HAS_AVX512
  const auto product = _mm512_maddubs_epi16(std::bit_cast<__m512i>(u),
                                            std::bit_cast<__m512i>(i));
  return sum + std::bit_cast<Vepi32>(
                   _mm512_madd_epi16(product, _mm512_set1_epi16(1)));
#elif BUILD_HAS_AVX2
  const auto product = _mm256_maddubs_epi16(std::bit_cast<__m256i>(u),
                                            std::bit_cast<__m256i>(i));
  return sum + std::bit_cast<Vepi32>(
                   _mm256_madd_epi16(product, _mm256_set1_epi16(1)));
#elif BUILD_HAS_SSE41
  const auto product =
      _mm_maddubs_epi16(std::bit_cast<__m128i>(u), std::bit_cast<__m128i>(i));
  return sum +
         std::bit_cast<Vepi32>(_mm_madd_epi16(product, _mm_set1_epi16(1)));
#else
  for (std::size_t j = 0; j < kNativeLanes<I32>; ++j)
    for (std::size_t k = 0; k < 4; ++k)
      sum[j] += I32(u[4 * j + k]) * I32(i[4 * j + k]);
  return sum;
#endif
}

// Two dot products fused into one widening step. The emulated paths sum two
// maddubs results before widening, which can exceed I16; the saturating add
// clamps instead of wrapping. Only the VNNI path is exact.
[[nodiscard]] inline Vepi32 DpbusdEpi32x2(
    Vepi32 sum, Vepu8 u1, Vepi8 i1, Vepu8 u2, Vepi8 i2) {
#if BUILD_HAS_AVX512VNNI
  return DpbusdEpi32(DpbusdEpi32(sum, u1, i1), u2, i2);
#elif BUILD_HAS_AVX512
  const auto p1 = _mm512_maddubs_epi16(std::bit_cast<__m512i>(u1),
                                       std::bit_cast<__m512i>(i1));
  const auto p2 = _mm512_maddubs_epi16(std::bit_cast<__m512i>(u2),
                                       std::bit_cast<__m512i>(i2));
  return sum + std::bit_cast<Vepi32>(_mm512_madd_epi16(
                   _mm512_adds_epi16(p1, p2), _mm512_set1_epi16(1)));
#elif BUILD_HAS_AVX2
  const auto p1 = _mm256_maddubs_epi16(std::bit_cast<__m256i>(u1),
                                       std::bit_cast<__m256i>(i1));
  const auto p2 = _mm256_maddubs_epi16(std::bit_cast<__m256i>(u2),
                                       std::bit_cast<__m256i>(i2));
  return sum + std::bit_cast<Vepi32>(_mm256_madd_epi16(
                   _mm256_adds_epi16(p1, p2), _mm256_set1_epi16(1)));
#elif BUILD_HAS_SSE41
  const auto p1 =
      _mm_maddubs_epi16(std::bit_cast<__m128i>(u1), std::bit_cast<__m128i>(i1));
  const auto p2 =
      _mm_maddubs_epi16(std::bit_cast<__m128i>(u2), std::bit_cast<__m128i>(i2));
  return sum + std::bit_cast<Vepi32>(
                   _mm_madd_epi16(_mm_adds_epi16(p1, p2), _mm_set1_epi16(1)));
#else
  return DpbusdEpi32(DpbusdEpi32(sum, u1, i1), u2, i2);
#endif
}

// Bitmask of I32 lanes greater than zero.
[[nodiscard]] inline U16 NonZeroMask(Vepi32 v) {
#if BUILD_HAS_AVX512
  return _mm512_cmpgt_epi32_mask(std::bit_cast<__m512i>(v),
                                 _mm512_setzero_si512());
#elif BUILD_HAS_AVX2
  return U16(_mm256_movemask_ps(_mm256_castsi256_ps(
      _mm256_cmpgt_epi32(std::bit_cast<__m256i>(v), _mm256_setzero_si256()))));
#elif BUILD_HAS_SSE41
  return U16(_mm_movemask_ps(_mm_castsi128_ps(
      _mm_cmpgt_epi32(std::bit_cast<__m128i>(v), _mm_setzero_si128()))));
#else
  U16 mask = 0;
  for (std::size_t i = 0; i < kNativeLanes<I32>; ++i)
    mask |= U16(v[i] > 0) << i;
  return mask;
#endif
}

[[nodiscard]] inline Vepu8 PermuteBytes(Vepu8 table, Vepu8 indices) {
#if BUILD_HAS_AVX512VBMI
  const auto idx = std::bit_cast<__m512i>(indices);
  const auto valid = _mm512_cmplt_epu8_mask(idx, _mm512_set1_epi8(64));
  return std::bit_cast<Vepu8>(
      _mm512_maskz_permutexvar_epi8(valid, idx, std::bit_cast<__m512i>(table)));
#else
  Vepu8 out{};
  for (std::size_t i = 0; i < kNativeLanes<U8>; ++i) {
    const U8 index = indices[i];
    out[i] = (index & 0x80) ? U8(0) : table[index % kNativeLanes<U8>];
  }
  return out;
#endif
}

inline void PermuteBytes64(const U8* table, const U8* indices, U8* out) {
#if BUILD_HAS_AVX512VBMI
  const auto idx = _mm512_loadu_si512(indices);
  const auto valid = _mm512_cmplt_epu8_mask(idx, _mm512_set1_epi8(64));
  _mm512_storeu_si512(
      out,
      _mm512_maskz_permutexvar_epi8(valid, idx, _mm512_loadu_si512(table)));
#else
  for (std::size_t i = 0; i < 64; ++i) {
    const U8 index = indices[i];
    out[i] = (index & 0x80) ? U8(0) : table[index];
  }
#endif
}

// Fills every ray at or beyond its first set bit, across all eight
// direction-lanes of a packed BitRays value at once.
[[nodiscard]] constexpr U64 RayFill(U64 rays) {
  rays = (rays + 0x7E7E7E7E7E7E7E7EULL) & 0x8080808080808080ULL;
  return rays - (rays >> 7);
}

}  // namespace simd

#endif  // INTEGRAL_SIMD_H_