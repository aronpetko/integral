//
// Created by Aron on 9/8/2024.
//

#ifndef SPRT_SH_SIMD_H
#define SPRT_SH_SIMD_H

#pragma once

#include "types.h"

#define SIMD
#define AVX2

#if defined(SIMD)
#include <immintrin.h>
#endif

#if defined(AVX512)
using vepi16 = __m512i;
using vepi32 = __m512i;

inline vepi16 zero_epi16() { return _mm512_setzero_si512(); }
inline vepi32 zero_epi32() { return _mm512_setzero_si512(); }
inline vepi16 load_epi16(const int16_t *memory_address) { return _mm512_load_si512(reinterpret_cast<const __m512i *>(memory_address)); }
inline vepi32 load_epi32(const int32_t *memory_address) { return _mm512_load_si512(reinterpret_cast<const __m512i *>(memory_address)); }
// this function puts num as every value in the vector
inline vepi16 set_epi16(int num) { return _mm512_set1_epi16(num); };
inline vepi32 set_epi32(int num) { return _mm512_set1_epi32(num); };
inline void store_epi16(void *memory_address, vepi16 vector) { _mm512_store_si512(memory_address, vector); }
inline vepi16 add_epi16(vepi32 v1, vepi32 v2) { return _mm512_add_epi16(v1, v2); }
inline vepi32 add_epi32(vepi32 v1, vepi32 v2) { return _mm512_add_epi32(v1, v2); }
inline vepi16 multiply_epi16(vepi16 v1, vepi16 v2) { return _mm512_mullo_epi16(v1, v2); }
// multiplies the two vectors together using intermediate int32, and then adds adjacent int32s
inline vepi32 multiply_add_epi16(vepi16 v1, vepi16 v2) { return _mm512_madd_epi16(v1, v2); }

inline vepi16 clip(vepi16 vector, int L1Q) { return _mm512_min_epi16(_mm512_max_epi16(vector, zero_epi16()), set_epi16(L1Q)); }

inline int reduce_add_epi32(vepi32 v) { return _mm512_reduce_add_epi32(v); }

#elif defined(AVX2)
using vepi16 = __m256i;
using vepi32 = __m256i;

inline vepi16 zero_epi16() { return _mm256_setzero_si256(); }
inline vepi32 zero_epi32() { return _mm256_setzero_si256(); }
inline vepi16 load_epi16(const int16_t *memory_address) { return _mm256_load_si256(reinterpret_cast<const __m256i *>(memory_address)); }
inline vepi32 load_epi32(const int32_t *memory_address) { return _mm256_load_si256(reinterpret_cast<const __m256i *>(memory_address)); }
// this function puts num as every value in the vector
inline vepi16 set_epi16(int num) { return _mm256_set1_epi16(num); };
inline vepi32 set_epi32(int num) { return _mm256_set1_epi32(num); };
// inline void store_epi16(void *memory_address, vepi16 vector) { _mm256_store_si256(memory_address, vector); }

inline vepi16 add_epi16(vepi32 v1, vepi32 v2) { return _mm256_add_epi16(v1, v2); }
inline vepi32 add_epi32(vepi32 v1, vepi32 v2) { return _mm256_add_epi32(v1, v2); }
inline vepi16 multiply_epi16(vepi16 v1, vepi16 v2) { return _mm256_mullo_epi16(v1, v2); }
// multiplies the two vectors together using intermediate int32, and then adds adjacent int32s
inline vepi32 multiply_add_epi16(vepi16 v1, vepi16 v2) { return _mm256_madd_epi16(v1, v2); }

inline vepi16 clip(vepi16 vector, int L1Q) { return _mm256_min_epi16(_mm256_max_epi16(vector, zero_epi16()), set_epi16(L1Q)); }

// implementation from Stormphrax
inline int reduce_add_epi32(vepi32 vector)
{
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

#endif

#endif  // SPRT_SH_SIMD_H
