#ifndef INTEGRAL_SIMD_H_
#define INTEGRAL_SIMD_H_

#include "../src/utils/types.h"

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
#define BUILD_HAS_SIMD (BUILD_HAS_AVX512 || BUILD_HAS_AVX2 || BUILD_HAS_NEON)
#elif defined(BUILD_APPLE_SILICON)
#define BUILD_HAS_BMI2 0
#define BUILD_HAS_AVX512VNNI 0
#define BUILD_HAS_AVX512 0
#define BUILD_HAS_AVX2 0
#define BUILD_HAS_BMI1 0
#define BUILD_HAS_POPCNT 0
#define BUILD_HAS_SSE41 0
#define BUILD_HAS_NEON 1
#define BUILD_HAS_SIMD 1
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

#if BUILD_HAS_SIMD && !BUILD_HAS_NEON
#include <immintrin.h>
#endif

#if BUILD_HAS_NEON
// SSE compatibility for ARM
#include <arm_neon.h>
using __m128i = int16x8_t;

inline __m128i _mm_setzero_si128() {
  return vdupq_n_s16(0);
}

inline __m128i _mm_set1_epi16(short a) {
  return vdupq_n_s16(a);
}

inline __m128i _mm_loadu_si128(const __m128i* p) {
  return vld1q_s16(reinterpret_cast<const int16_t*>(p));
}

inline void _mm_storeu_si128(__m128i* p, __m128i a) {
  vst1q_s16(reinterpret_cast<int16_t*>(p), a);
}

inline __m128i _mm_add_epi16(__m128i a, __m128i b) {
  return vaddq_s16(a, b);
}
#endif

namespace simd {

#if BUILD_HAS_AVX512

using Vepi8 = __m512i;
using Vepi16 = __m512i;
using Vepi32 = __m512i;
using Vepf32 = __m512;

constexpr int kPackusOrder[8] = {0, 2, 4, 6, 1, 3, 5, 7};
constexpr int kAlignment = 64;

inline Vepi32 DpbusdEpi32(Vepi32 sum, Vepi8 first, Vepi8 second) {
  Vepi32 sum32 = _mm512_madd_epi16(_mm512_maddubs_epi16(first, second),
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

#elif BUILD_HAS_NEON

using Vepi8 = int8x16_t;
using Vepi16 = int16x8_t;
using Vepi32 = int32x4_t;
using Vepf32 = float32x4_t;

constexpr int kPackusOrder[2] = {0, 1};
constexpr int kAlignment = 16;

inline Vepi32 DpbusdEpi32(Vepi32 sum, Vepi8 first, Vepi8 second) {
  // Dot product (sum += first * second)
  // vdotq_s32 is available on ARMv8.2-A
#if defined(__ARM_FEATURE_DOTPROD)
  return vdotq_s32(sum, first, second);
#else
  // Fallback if dot product is not available
  int16x8_t mul_low = vmull_s8(vget_low_s8(first), vget_low_s8(second));
  int16x8_t mul_high = vmull_high_s8(first, second);
  sum = vpadalq_s16(sum, mul_low);
  sum = vpadalq_s16(sum, mul_high);
  return sum;
#endif
}

inline Vepi32 DpbusdEpi32x2(Vepi32 sum, Vepi8 u, Vepi8 i, Vepi8 u2, Vepi8 i2) {
  sum = DpbusdEpi32(sum, u, i);
  return DpbusdEpi32(sum, u2, i2);
}

inline Vepi16 ZeroEpi16() {
  return vdupq_n_s16(0);
}

inline Vepi32 ZeroEpi32() {
  return vdupq_n_s32(0);
}

inline Vepf32 ZeroPs() {
  return vdupq_n_f32(0.0f);
}

inline Vepi16 LoadEpi16(const int16_t* memory_address) {
  return vld1q_s16(memory_address);
}

inline Vepi32 LoadEpi32(const int32_t* memory_address) {
  return vld1q_s32(memory_address);
}

inline Vepi16 SetEpi16(int num) {
  return vdupq_n_s16(num);
}

inline Vepi32 SetEpi32(int num) {
  return vdupq_n_s32(num);
}

inline Vepi16 AddEpi16(Vepi16 v1, Vepi16 v2) {
  return vaddq_s16(v1, v2);
}

inline Vepi32 AddEpi32(Vepi32 v1, Vepi32 v2) {
  return vaddq_s32(v1, v2);
}

inline Vepi16 MultiplyEpi16(Vepi16 v1, Vepi16 v2) {
  return vmulq_s16(v1, v2);
}

inline Vepi32 MultiplyAddEpi16(Vepi16 v1, Vepi16 v2) {
  // This is actually madd: (v1.lo * v2.lo) + (v1.hi * v2.hi)
  // We need to implement it to match _mm256_madd_epi16
  int32x4_t low = vmull_s16(vget_low_s16(v1), vget_low_s16(v2));
  int32x4_t high = vmull_high_s16(v1, v2);
  // v1 is [a, b, c, d, e, f, g, h], v2 is [i, j, k, l, m, n, o, p]
  // madd is [ai+bj, ck+dl, em+fn, go+hp]
  return vpaddq_s32(low, high);
}

inline Vepi16 MulhiEpi16(Vepi16 a, Vepi16 b) {
  // Multiply 16-bit and keep high 16-bit
  int32x4_t low = vmull_s16(vget_low_s16(a), vget_low_s16(b));
  int32x4_t high = vmull_high_s16(a, b);
  return vcombine_s16(vshrn_n_s32(low, 16), vshrn_n_s32(high, 16));
}

inline Vepi16 SlliEpi16(Vepi16 a, int shift) {
  // NEON shift must be a constant for vshlq_n_s16, but our usage might be variable.
  // Actually in nnue.cc it's a constant (16 - kFtShift).
  // But for flexibility we can use vshlq_s16.
  return vshlq_s16(a, vdupq_n_s16(shift));
}

inline Vepi8 PackusEpi16(Vepi16 a, Vepi16 b) {
  // Pack 16-bit to 8-bit unsigned with saturation
  return vcombine_s8(vqmovun_s16(a), vqmovun_s16(b));
}

inline Vepi16 Min(Vepi16 one, Vepi16 two) {
  return vminq_s16(one, two);
}

inline Vepi16 Max(Vepi16 one, Vepi16 two) {
  return vmaxq_s16(one, two);
}

inline Vepf32 MaxPs(Vepf32 one, Vepf32 two) {
  return vmaxq_f32(one, two);
}

inline Vepf32 MinPs(Vepf32 one, Vepf32 two) {
  return vminq_f32(one, two);
}

inline Vepi16 Clip(Vepi16 vector, int l1q) {
  return vminq_s16(vmaxq_s16(vector, ZeroEpi16()), vdupq_n_s16(l1q));
}

inline void StoreEpi16(void* memory_address, Vepi16 vector) {
  vst1q_s16(reinterpret_cast<int16_t*>(memory_address), vector);
}

inline int ReduceAddEpi32(Vepi32 vector) {
  return vaddvq_s32(vector);
}

inline float ReduceAddPs(Vepf32 vec) {
  return vaddvq_f32(vec);
}

inline float ReduceAddPs(Vepf32* v) {
  return vaddvq_f32(v[0]);
}

inline Vepf32 ConvertEpi32ToPs(Vepi32 v) {
  return vcvtq_f32_s32(v);
}

inline void StorePs(float* memory_address, Vepf32 v) {
  vst1q_f32(memory_address, v);
}

inline Vepf32 SetPs(float value) {
  return vdupq_n_f32(value);
}

inline Vepf32 MultiplyPs(Vepf32 v1, Vepf32 v2) {
  return vmulq_f32(v1, v2);
}

inline Vepf32 MultiplyAddPs(Vepf32 v1, Vepf32 v2, Vepf32 sum) {
  return vfmaq_f32(sum, v1, v2);
}

inline void StoreEpi32(void* memory_address, Vepi32 vector) {
  vst1q_s32(reinterpret_cast<int32_t*>(memory_address), vector);
}

inline uint8_t GetNnzMask(Vepi8 x) {
  // Get a 4-bit mask of non-zero I32 elements
  uint32x4_t x_i32 = vreinterpretq_u32_s8(x);
  uint32x4_t mask = vtstq_u32(x_i32, x_i32);
  uint32x4_t bit_mask = {1, 2, 4, 8};
  uint32x4_t masked = vandq_u32(mask, bit_mask);
  return (uint8_t)vaddvq_u32(masked);
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

#else
constexpr int kAlignment = 64;
#endif

inline float ReduceAddPsRecursive(float* sums, int length) {
  if (length == 2) return sums[0] + sums[1];
  length /= 2;
  for (int i = 0; i < length; ++i) sums[i] += sums[i + length];
  return ReduceAddPsRecursive(sums, length);
}

}  // namespace simd

#endif  // INTEGRAL_SIMD_H_