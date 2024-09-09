#ifndef INTEGRAL_SIMD_H_
#define INTEGRAL_SIMD_H_

#include "types.h"

#if defined(SIMD)
#include <immintrin.h>
#endif

namespace simd {

#if defined(AVX512)

using Vepi16 = __m512i;
using Vepi32 = __m512i;

inline Vepi16 ZeroEpi16() {
  return _mm512_setzero_si512();
}
inline Vepi32 ZeroEpi32() {
  return _mm512_setzero_si512();
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

inline Vepi16 Clip(Vepi16 vector, int l1q) {
  return _mm512_min_epi16(_mm512_max_epi16(vector, ZeroEpi16()), SetEpi16(l1q));
}

inline int ReduceAddEpi32(Vepi32 v) {
  return _mm512_reduce_add_epi32(v);
}

#elif defined(AVX2)

using Vepi16 = __m256i;
using Vepi32 = __m256i;

inline Vepi16 ZeroEpi16() {
  return _mm256_setzero_si256();
}
inline Vepi32 ZeroEpi32() {
  return _mm256_setzero_si256();
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

inline Vepi16 Clip(Vepi16 vector, int l1q) {
  return _mm256_min_epi16(_mm256_max_epi16(vector, ZeroEpi16()), SetEpi16(l1q));
}

// Implementation from Stormphrax
inline int ReduceAddEpi32(Vepi32 vector) {
  auto high128 = _mm256_extracti128_si256(vector, 1);
  auto low128 = _mm256_castsi256_si128(vector);

  auto sum128 = _mm_add_epi32(high128, low128);
  // copies the highest 64 bits twice into a 128 vector
  auto high64 = _mm_unpackhi_epi64(sum128, sum128);

  // we sum together the 64 least significant bits because those are the ones that matter
  // bottom 64 bits store the 2 important numbers
  auto sum64 = _mm_add_epi32(sum128, high64);

  // take the highest 32 bits and places thin into the least significant 32 bits in a 128 vector
  // the shuffle operation does this
  const auto high32 = _mm_shuffle_epi32(sum64, _MM_SHUFFLE(2, 3, 0, 1));

  // adds the two important numbers up
  const auto sum32 = _mm_add_epi32(sum64, high32);

  // extracts the sum
  return _mm_cvtsi128_si32(sum32);
}

#endif  // AVX2

}  // namespace simd

#endif  // INTEGRAL_SIMD_H_