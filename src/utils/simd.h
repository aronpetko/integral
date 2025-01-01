#ifndef INTEGRAL_SIMD_H_
#define INTEGRAL_SIMD_H_

#include "types.h"

#if defined(BUILD_NATIVE)
#if __BMI2__ && defined(BUILD_FAST_PEXT)
#define BUILD_HAS_BMI2 1
#else
#define BUILD_HAS_BMI2 0
#endif
#define BUILD_HAS_AVX512VNNI __AVX512VNNI__
#define BUILD_HAS_AVX512 (__AVX512F__ && (__AVX512BW__ || __AVX512VNNI__))
#define BUILD_HAS_AVX2 __AVX2__
#define BUILD_HAS_BMI1 __BMI__
#define BUILD_HAS_POPCNT __POPCNT__
#define BUILD_HAS_SSE41 __SSE4_1__
#define BUILD_HAS_NEON __ARM_NEON
#define BUILD_HAS_SIMD (BUILD_HAS_AVX512 || BUILD_HAS_AVX2)
#elif defined(BUILD_VNNI512)
#define BUILD_HAS_BMI2 1
#define BUILD_HAS_AVX512VNNI 1
#define BUILD_HAS_AVX512 1
#define BUILD_HAS_AVX2 1
#define BUILD_HAS_BMI1 1
#define BUILD_HAS_POPCNT 1
#define BUILD_HAS_SSE41 1
#define BUILD_HAS_NEON 0
#define BUILD_HAS_SIMD 1
#elif defined(BUILD_AVX512)
#define BUILD_HAS_BMI2 1
#define BUILD_HAS_AVX512VNNI 0
#define BUILD_HAS_AVX512 1
#define BUILD_HAS_AVX2 1
#define BUILD_HAS_BMI1 1
#define BUILD_HAS_POPCNT 1
#define BUILD_HAS_SSE41 1
#define BUILD_HAS_NEON 0
#define BUILD_HAS_SIMD 1
#elif defined(BUILD_AVX2_BMI2)
#define BUILD_HAS_BMI2 1
#define BUILD_HAS_AVX512VNNI 0
#define BUILD_HAS_AVX512 0
#define BUILD_HAS_AVX2 1
#define BUILD_HAS_BMI1 1
#define BUILD_HAS_POPCNT 1
#define BUILD_HAS_SSE41 1
#define BUILD_HAS_NEON 0
#define BUILD_HAS_SIMD 1
#elif defined(BUILD_AVX2)
#define BUILD_HAS_BMI2 0
#define BUILD_HAS_AVX512VNNI 0
#define BUILD_HAS_AVX512 0
#define BUILD_HAS_AVX2 1
#define BUILD_HAS_BMI1 1
#define BUILD_HAS_POPCNT 1
#define BUILD_HAS_SSE41 1
#define BUILD_HAS_NEON 0
#define BUILD_HAS_SIMD 1
#elif defined(BUILD_SSE41_POPCNT)
#define BUILD_HAS_BMI2 0
#define BUILD_HAS_AVX512VNNI 0
#define BUILD_HAS_AVX512 0
#define BUILD_HAS_AVX2 0
#define BUILD_HAS_BMI1 0
#define BUILD_HAS_POPCNT 1
#define BUILD_HAS_SSE41 1
#define BUILD_HAS_NEON 0
#else
#error No architecture specified
#endif

#if BUILD_HAS_SIMD
#include <immintrin.h>
#endif

namespace simd {

#if BUILD_HAS_AVX512

using Vepi8 = __m512i;
using Vepi16 = __m512i;
using Vepi32 = __m512i;
using Vepf32 = __m512;

constexpr int kPackusOrder[8] = {0, 2, 4, 6, 1, 3, 5, 7};
constexpr int kAlignment = 64;

#ifdef BUILD_HAS_AVX512VNNI
inline Vepi32 DpbusdEpi32(Vepi32 sum, Vepi8 first, Vepi8 second) {
  return _mm512_dpbusd_epi32(sum, first, second);
}

inline Vepi32 DpbusdEpi32x2(Vepi32 sum, Vepi8 u, Vepi8 i, Vepi8 u2, Vepi8 i2) {
  return _mm512_dpbusd_epi32(_mm512_dpbusd_epi32(sum, u, i), u2, i2);
}
#else
inline Vepi32 DpbusdEpi32(Vepi32 sum, Vepi8 first, Vepi8 second) {
  VecI32 sum32 = _mm512_madd_epi16(_mm512_maddubs_epi16(first, second),
                                   _mm512_set1_epi16(1));
  return _mm512_add_epi32(sum32, sum);
}

inline Vepi32 DpbusdEpi32x2(Vepi32 sum, Vepi8 u, Vepi8 i, Vepi8 u2, Vepi8 i2) {
  const auto mul1 = _mm512_maddubs_epi16(u, i);
  const auto mul2 = _mm512_maddubs_epi16(u2, i2);
  const auto sum32 =
      _mm512_madd_epi16(_mm512_add_epi16(mul1, mul2), _mm512_set1_epi16(1));
  return _mm512_add_epi32(sum32, sum);
}
#endif

inline Vepi16 ZeroEpi16() {
  return _mm512_setzero_si512();
}

inline Vepi32 ZeroEpi32() {
  return _mm512_setzero_si512();
}

inline Vepf32 ZeroPs() {
  return _mm512_setzero_ps();
}

inline Vepi16 LoadEpi16(const int16_t* memory_address) {
  return _mm512_load_si512(reinterpret_cast<const __m512i*>(memory_address));
}

inline Vepi32 LoadEpi32(const int32_t* memory_address) {
  return _mm512_load_si512(reinterpret_cast<const __m512i*>(memory_address));
}

inline Vepi16 SetEpi16(int num) {
  return _mm512_set1_epi16(num);
}
inline Vepi32 SetEpi32(int num) {
  return _mm512_set1_epi32(num);
}

inline void StoreEpi16(void* memory_address, Vepi16 vector) {
  _mm512_store_si512(memory_address, vector);
}

inline Vepi16 AddEpi16(Vepi32 v1, Vepi32 v2) {
  return _mm512_add_epi16(v1, v2);
}

inline Vepi32 AddEpi32(Vepi32 v1, Vepi32 v2) {
  return _mm512_add_epi32(v1, v2);
}

inline Vepi16 MultiplyEpi16(Vepi16 v1, Vepi16 v2) {
  return _mm512_mullo_epi16(v1, v2);
}

inline Vepi32 MultiplyAddEpi16(Vepi16 v1, Vepi16 v2) {
  return _mm512_madd_epi16(v1, v2);
}

inline Vepi16 SlliEpi16(Vepi16 x, int shift) {
  return _mm512_slli_epi16(x, shift);
}

inline Vepi16 MulhiEpi16(Vepi16 x, Vepi16 y) {
  return _mm512_mulhi_epi16(x, y);
}

inline Vepi16 Min(Vepi16 one, Vepi16 two) {
  return _mm512_min_epi16(one, two);
}

inline Vepf32 Max(Vepf32 one, Vepf32 two) {
  return _mm512_max_ps(one, two);
}

inline Vepf32 MinPs(Vepf32 one, Vepf32 two) {
  return _mm512_min_ps(one, two);
}

inline Vepf32 MaxPs(Vepf32 one, Vepf32 two) {
  return _mm512_max_ps(one, two);
}

inline Vepi16 Clip(Vepi16 vector, int l1q) {
  return _mm512_min_epi16(_mm512_max_epi16(vector, ZeroEpi16()), SetEpi16(l1q));
}

inline int ReduceAddEpi32(Vepi32 v) {
  return _mm512_reduce_add_epi32(v);
}

inline float ReduceAddPs(Vepf32 v) {
  return _mm512_reduce_add_ps(v);
}

inline float ReduceAddPs(Vepf32* vec) {
  return _mm512_reduce_add_ps(vec[0]);
}

inline Vepi16 PackusEpi16(Vepi16 a, Vepi16 b) {
  return _mm512_packus_epi16(a, b);
}

inline Vepf32 ConvertEpi32ToPs(Vepi32 v) {
  return _mm512_cvtepi32_ps(v);
}

inline void StorePs(float* memory_address, Vepf32 v) {
  _mm512_store_ps(memory_address, v);
}

inline Vepf32 SetPs(float value) {
  return _mm512_set1_ps(value);
}

inline Vepf32 MultiplyPs(Vepf32 v1, Vepf32 v2) {
  return _mm512_mul_ps(v1, v2);
}

inline Vepf32 MultiplyAddPs(Vepf32 v1, Vepf32 v2, Vepf32 sum) {
  return _mm512_fmadd_ps(v1, v2, sum);
}

inline void StoreEpi32(void* memory_address, Vepi32 vector) {
  _mm512_store_si512(memory_address, vector);
}

inline U16 GetNnzMask(Vepi32 x) {
  return _mm512_cmpgt_epi32_mask(x, _mm512_setzero_si512());
}

#elif BUILD_HAS_AVX2

using Vepi8 = __m256i;
using Vepi16 = __m256i;
using Vepi32 = __m256i;
using Vepf32 = __m256;

constexpr int kPackusOrder[4] = {0, 2, 1, 3};
constexpr int kAlignment = std::max<int>(8, sizeof(Vepi16));

inline Vepi32 DpbusdEpi32(Vepi32 sum, Vepi8 first, Vepi8 second) {
  Vepi32 sum32 = _mm256_madd_epi16(_mm256_maddubs_epi16(first, second),
                                   _mm256_set1_epi16(1));
  return _mm256_add_epi32(sum32, sum);
}

inline Vepi32 DpbusdEpi32x2(Vepi32 sum, Vepi8 u, Vepi8 i, Vepi8 u2, Vepi8 i2) {
  const auto mul1 = _mm256_maddubs_epi16(u, i);
  const auto mul2 = _mm256_maddubs_epi16(u2, i2);
  const auto sum32 =
      _mm256_madd_epi16(_mm256_add_epi16(mul1, mul2), _mm256_set1_epi16(1));
  return _mm256_add_epi32(sum32, sum);
}

inline Vepi16 ZeroEpi16() {
  return _mm256_setzero_si256();
}

inline Vepf32 ZeroPs() {
  return _mm256_setzero_ps();
}

inline Vepi16 LoadEpi16(const int16_t* memory_address) {
  return _mm256_load_si256(reinterpret_cast<const __m256i*>(memory_address));
}

inline Vepi32 LoadEpi32(const int32_t* memory_address) {
  return _mm256_load_si256(reinterpret_cast<const __m256i*>(memory_address));
}

inline Vepi16 SetEpi16(int num) {
  return _mm256_set1_epi16(num);
}

inline Vepi32 SetEpi32(int num) {
  return _mm256_set1_epi32(num);
}

inline Vepi16 AddEpi16(Vepi32 v1, Vepi32 v2) {
  return _mm256_add_epi16(v1, v2);
}

inline Vepi32 AddEpi32(Vepi32 v1, Vepi32 v2) {
  return _mm256_add_epi32(v1, v2);
}

inline Vepi16 MultiplyEpi16(Vepi16 v1, Vepi16 v2) {
  return _mm256_mullo_epi16(v1, v2);
}

inline Vepi32 MultiplyAddEpi16(Vepi16 v1, Vepi16 v2) {
  return _mm256_madd_epi16(v1, v2);
}

inline Vepi16 MulhiEpi16(Vepi16 a, Vepi16 b) {
  return _mm256_mulhi_epi16(a, b);
}

inline Vepi16 SlliEpi16(Vepi16 a, int shift) {
  return _mm256_slli_epi16(a, shift);
}

inline Vepi8 PackusEpi16(Vepi16 a, Vepi16 b) {
  return _mm256_packus_epi16(a, b);
}

inline Vepi16 Min(Vepi16 one, Vepi16 two) {
  return _mm256_min_epi16(one, two);
}

inline Vepi16 Max(Vepi16 one, Vepi16 two) {
  return _mm256_max_epi16(one, two);
}

inline Vepf32 MaxPs(Vepf32 one, Vepf32 two) {
  return _mm256_max_ps(one, two);
}

inline Vepf32 MinPs(Vepf32 one, Vepf32 two) {
  return _mm256_min_ps(one, two);
}

inline Vepi16 Clip(Vepi16 vector, int l1q) {
  return _mm256_min_epi16(_mm256_max_epi16(vector, ZeroEpi16()), SetEpi16(l1q));
}

inline void StoreEpi16(void* memory_address, Vepi16 vector) {
  _mm256_store_si256(reinterpret_cast<__m256i*>(memory_address), vector);
}

// Implementation from Alexandria
inline int ReduceAddEpi32(Vepi32 vector) {
  // Split the __m256i into 2 __m128i vectors, and add them together
  __m128i lower128 = _mm256_castsi256_si128(vector);
  __m128i upper128 = _mm256_extracti128_si256(vector, 1);
  __m128i sum128 = _mm_add_epi32(lower128, upper128);

  // Store the high 64 bits of sum128 in the low 64 bits of this vector,
  // then add them together (only the lowest 64 bits are relevant)
  __m128i upper64 = _mm_unpackhi_epi64(sum128, sum128);
  __m128i sum64 = _mm_add_epi32(upper64, sum128);

  // Store the high 32 bits of the relevant part of sum64 in the low 32 bits of
  // the vector, and then add them together (only the lowest 32 bits are
  // relevant)
  __m128i upper32 = _mm_shuffle_epi32(sum64, 1);
  __m128i sum32 = _mm_add_epi32(upper32, sum64);

  // Return the bottom 32 bits of sum32
  return _mm_cvtsi128_si32(sum32);
}

inline float ReduceAddPs(Vepf32 vec) {
  const auto sum_128 =
      _mm_add_ps(_mm256_castps256_ps128(vec), _mm256_extractf128_ps(vec, 1));

  const auto upper_64 = _mm_movehl_ps(sum_128, sum_128);
  const auto sum_64 = _mm_add_ps(sum_128, upper_64);

  const auto upper_32 = _mm_shuffle_ps(sum_64, sum_64, 1);
  const auto sum_32 = _mm_add_ss(sum_64, upper_32);

  return _mm_cvtss_f32(sum_32);
}

inline float ReduceAddPs(Vepf32* v) {
  v[0] = _mm256_add_ps(v[0], v[1]);
  __m128 high = _mm256_extractf128_ps(v[0], 1);
  __m128 low = _mm256_castps256_ps128(v[0]);
  __m128 sum = _mm_add_ps(high, low);
  __m128 high64 = _mm_movehl_ps(sum, sum);
  __m128 sum64 = _mm_add_ps(sum, high64);

  return reinterpret_cast<float*>(&sum64)[0] +
         reinterpret_cast<float*>(&sum64)[1];
}

inline __m256 ConvertEpi32ToPs(Vepi32 v) {
  return _mm256_cvtepi32_ps(v);
}

inline void StorePs(float* memory_address, __m256 v) {
  _mm256_store_ps(memory_address, v);
}

inline __m256 SetPs(float value) {
  return _mm256_set1_ps(value);
}

inline Vepf32 MultiplyPs(Vepf32 v1, Vepf32 v2) {
  return _mm256_mul_ps(v1, v2);
}

inline Vepf32 MultiplyAddPs(Vepf32 v1, Vepf32 v2, Vepf32 sum) {
  return _mm256_fmadd_ps(v1, v2, sum);
}

inline void StoreEpi32(void* memory_address, Vepi32 vector) {
  _mm256_store_si256(reinterpret_cast<__m256i*>(memory_address), vector);
}

inline U8 GetNnzMask(Vepi32 x) {
  return _mm256_movemask_ps(
      _mm256_castsi256_ps(_mm256_cmpgt_epi32(x, _mm256_setzero_si256())));
}

#endif  // AVX2

}  // namespace simd

#endif  // INTEGRAL_SIMD_H_