//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_BACKEND_ISA_AVX512_H
#define MANTARAY_BACKEND_ISA_AVX512_H

#if defined(__AVX512BW__)

#include <array>
#include <type_traits>
#include <utility>

#include <immintrin.h>

#include "AVX2.h"
#include "../../Common.h"

namespace MantaRay::Backend::ISA
{

    struct AVX512
    {

        using Vector  = __m512i;
        using VectorF = __m512 ;

        static_assert(alignof(Array<Vector , 2>) == alignof(Vector ), "arrays of vectors keep the vector's alignment");
        static_assert(alignof(Array<VectorF, 2>) == alignof(VectorF), "arrays of vectors keep the vector's alignment");

        constexpr static s00 Bytes     = 64;
        constexpr static s00 Registers = 32;
        constexpr static s00 DotChains =  2;

        constexpr static bool VNNI = false;

        constexpr static bool Masks = true;

#if defined(__AVX512VBMI__)
        constexpr static bool Permute8 = true;
#else
        constexpr static bool Permute8 = false;
#endif

#if defined(__AVX512VBMI2__)
        constexpr static bool Compress = true;
#else
        constexpr static bool Compress = false;
#endif

#if defined(__FMA__)
        constexpr static bool FMA = true;
#else
        constexpr static bool FMA = false;
#endif

#if defined(__SSSE3__)
        constexpr static bool Shuffle = true;
#else
        constexpr static bool Shuffle = false;
#endif

#if defined(__AVX2__)
        constexpr static bool Gather = true;
#else
        constexpr static bool Gather = false;
#endif

        constexpr static bool Table = false;

        constexpr static bool PairDot = true;
        constexpr static bool Maddubs = true;

        constexpr static s00 DotInFlight = 1;

        template<typename T>
        [[clang::always_inline]]
        static Vector Load(const T* const address) noexcept { return _mm512_load_si512(address); }

        template<typename T, s00 N>
        [[clang::always_inline]]
        static Vector Load(const std::array<T, N>& array, const s00 index) noexcept
        { return _mm512_load_si512(&array[index]); }

        template<typename T>
        [[clang::always_inline]]
        static void Store(T* const address, const Vector value) noexcept { _mm512_store_si512(address, value); }

        template<typename T, s00 N>
        [[clang::always_inline]]
        static void Store(std::array<T, N>& array, const s00 index, const Vector value) noexcept
        { _mm512_store_si512(&array[index], value); }

        template<typename T>
        [[clang::always_inline]]
        static void StoreUnaligned(T* const address, const Vector value) noexcept
        { _mm512_storeu_si512(address, value); }

        template<typename T, s00 N>
        [[clang::always_inline]]
        static void StoreUnaligned(std::array<T, N>& array, const s00 index, const Vector value) noexcept
        { _mm512_storeu_si512(&array[index], value); }

        template<typename T>
        [[clang::always_inline]]
        static Vector LoadUnaligned(const T* const address) noexcept { return _mm512_loadu_si512(address); }

        template<typename T, s00 N>
        [[clang::always_inline]]
        static Vector LoadUnaligned(const std::array<T, N>& array, const s00 index) noexcept
        { return _mm512_loadu_si512(&array[index]); }

        [[clang::always_inline]]
        static Vector BroadcastU128(const u08* const address) noexcept
        { return _mm512_broadcast_i32x4(_mm_loadu_si128(reinterpret_cast<const __m128i*>(address))); }

        template<typename T, typename W>
        [[clang::always_inline]]
        static Vector LoadAs(const W* const address) noexcept
        {
            static_assert(IsWidening<T, W>, "LoadAs reads W == T or sign-extends i08 to i16 or i32 and i16 to i32");

            if (std::is_same_v<T, W>) return Load(address);

            if (std::is_same_v<T, i16> && std::is_same_v<W, i08>)
                return _mm512_cvtepi8_epi16 (_mm256_load_si256(reinterpret_cast<const __m256i*>(address)));

            if (std::is_same_v<T, i32> && std::is_same_v<W, i16>)
                return _mm512_cvtepi16_epi32(_mm256_load_si256(reinterpret_cast<const __m256i*>(address)));

            if (std::is_same_v<T, i32> && std::is_same_v<W, i08>)
                return _mm512_cvtepi8_epi32 (_mm_load_si128   (reinterpret_cast<const __m128i*>(address)));

            std::unreachable();
        }

        template<typename T, typename W, s00 N>
        [[clang::always_inline]]
        static Vector LoadAs(const std::array<W, N>& array, const s00 index) noexcept
        { return LoadAs<T>(&array[index]); }

        [[clang::always_inline]]
        static Vector Zero() noexcept { return _mm512_setzero_si512(); }

        [[clang::always_inline]]
        static Vector BroadcastU08(const u08 value) noexcept { return _mm512_set1_epi8(static_cast<i08>(value)); }

        [[clang::always_inline]]
        static Vector BroadcastI16(const i16 value) noexcept { return _mm512_set1_epi16(value); }

        [[clang::always_inline]]
        static Vector BroadcastI32(const i32 value) noexcept { return _mm512_set1_epi32(value); }

        [[clang::always_inline]]
        static Vector BroadcastU32(const u08* const address) noexcept
        { return _mm512_broadcastd_epi32(_mm_loadu_si32(address)); }

        [[clang::always_inline]]
        static Vector And(const Vector left, const Vector right) noexcept { return _mm512_and_si512(left, right); }

        [[clang::always_inline]]
        static Vector Or(const Vector left, const Vector right) noexcept { return _mm512_or_si512(left, right); }

        [[clang::always_inline]]
        static Vector Xor(const Vector left, const Vector right) noexcept { return _mm512_xor_si512(left, right); }

        [[clang::always_inline]]
        static Vector AddI16(const Vector left, const Vector right) noexcept { return _mm512_add_epi16(left, right); }

        [[clang::always_inline]]
        static Vector SubI16(const Vector left, const Vector right) noexcept { return _mm512_sub_epi16(left, right); }

        [[clang::always_inline]]
        static Vector MinI16(const Vector left, const Vector right) noexcept { return _mm512_min_epi16(left, right); }

        [[clang::always_inline]]
        static Vector MaxI16(const Vector left, const Vector right) noexcept { return _mm512_max_epi16(left, right); }

        [[clang::always_inline]]
        static Vector MulLoI16(const Vector left, const Vector right) noexcept
        { return _mm512_mullo_epi16(left, right); }

        [[clang::always_inline]]
        static Vector MulHiI16(const Vector left, const Vector right) noexcept
        { return _mm512_mulhi_epi16(left, right); }

        template<s00 S>
        [[clang::always_inline]]
        static Vector ShiftLeftI16(const Vector value) noexcept
        {
            static_assert(S < 16, "an i16 shift stays below 16");

            return _mm512_slli_epi16(value, S);
        }

        template<s00 S>
        [[clang::always_inline]]
        static Vector ShiftRightI16(const Vector value) noexcept
        {
            static_assert(S < 16, "an i16 shift stays below 16");

            return _mm512_srai_epi16(value, S);
        }

        [[clang::always_inline]]
        static Vector AddI32(const Vector left, const Vector right) noexcept { return _mm512_add_epi32(left, right); }

        [[clang::always_inline]]
        static Vector SubI32(const Vector left, const Vector right) noexcept { return _mm512_sub_epi32(left, right); }

        [[clang::always_inline]]
        static Vector MulLoI32(const Vector left, const Vector right) noexcept
        { return _mm512_mullo_epi32(left, right); }

        [[clang::always_inline]]
        static Vector MinI32(const Vector left, const Vector right) noexcept { return _mm512_min_epi32(left, right); }

        [[clang::always_inline]]
        static Vector MaxI32(const Vector left, const Vector right) noexcept { return _mm512_max_epi32(left, right); }

        [[clang::always_inline]]
        static Vector CompareGreaterI32(const Vector left, const Vector right) noexcept
        { return _mm512_maskz_set1_epi32(_mm512_cmpgt_epi32_mask(left, right), -1); }

        template<s00 S>
        [[clang::always_inline]]
        static Vector ShiftRightI32(const Vector value) noexcept
        {
            static_assert(S < 32, "an i32 shift stays below 32");

            return _mm512_srai_epi32(value, S);
        }

        template<s00 S>
        [[clang::always_inline]]
        static Vector ShiftRightU32(const Vector value) noexcept
        {
            static_assert(S < 32, "a u32 shift stays below 32");

            return _mm512_srli_epi32(value, S);
        }

        template<s00 S>
        [[clang::always_inline]]
        static Vector ShiftLeftI32(const Vector value) noexcept
        {
            static_assert(S < 32, "an i32 shift stays below 32");

            return _mm512_slli_epi32(value, S);
        }

        [[clang::always_inline]]
        static Vector ShiftLeftVarI32(const Vector value, const Vector count) noexcept
        { return _mm512_sllv_epi32(value, count); }

        template<bool Positive>
        [[clang::always_inline]]
        static u32 NonzeroMaskI32(const Vector value) noexcept { return _mm512_test_epi32_mask(value, value); }

        [[clang::always_inline]]
        static u32 NonzeroMaskI16(const Vector value) noexcept { return _mm512_test_epi16_mask(value, value); }

        [[clang::always_inline]]
        static Vector UnpackLoI16(const Vector left, const Vector right) noexcept
        { return _mm512_unpacklo_epi16(left, right); }

        [[clang::always_inline]]
        static Vector UnpackHiI16(const Vector left, const Vector right) noexcept
        { return _mm512_unpackhi_epi16(left, right); }

#if defined(__AVX512VBMI2__)
        [[clang::always_inline]]
        static Vector CompressU16(const u32 mask, const Vector value) noexcept
        { return _mm512_maskz_compress_epi16(mask, value); }

        [[clang::always_inline]]
        static Vector CompressU08(const u64 mask, const Vector value) noexcept
        { return _mm512_maskz_compress_epi8(mask, value); }
#endif

        [[clang::always_inline]]
        static Vector CompressU32(const u32 mask, const Vector value) noexcept
        { return _mm512_maskz_compress_epi32(static_cast<__mmask16>(mask), value); }

        [[clang::always_inline]]
        static Vector MaddI16(const Vector left, const Vector right) noexcept { return _mm512_madd_epi16(left, right); }

        [[clang::always_inline]]
        static i32 ReduceI32(const Vector value) noexcept
        {
            const auto high = _mm512_extracti64x4_epi64(value, 1);

            return AVX2::ReduceI32(_mm256_add_epi32(_mm512_castsi512_si256(value), high));
        }

        [[clang::always_inline]]
        static i64 ReduceI64(const Vector value) noexcept
        {
            const auto wide = _mm512_add_epi64(
                _mm512_cvtepi32_epi64(_mm512_castsi512_si256   (value   )),
                _mm512_cvtepi32_epi64(_mm512_extracti64x4_epi64(value, 1))
            );

            return _mm512_reduce_add_epi64(wide);
        }

        [[clang::always_inline]]
        static Vector PackUnsignedI16(const Vector left, const Vector right) noexcept
        { return _mm512_packus_epi16(left, right); }

        [[clang::always_inline]]
        static Vector PackU08(const Vector left, const Vector right) noexcept
        {
            const auto order = _mm512_setr_epi64(0, 2, 4, 6, 1, 3, 5, 7);

            return _mm512_permutexvar_epi64(order, PackUnsignedI16(left, right));
        }

        [[clang::always_inline]]
        static Vector PackI16(const Vector left, const Vector right) noexcept
        {
            const auto order = _mm512_setr_epi64(0, 2, 4, 6, 1, 3, 5, 7);

            return _mm512_permutexvar_epi64(order, _mm512_packs_epi32(left, right));
        }

        [[clang::always_inline]]
        static Vector MaddubsI16(const Vector u8, const Vector i8) noexcept { return _mm512_maddubs_epi16(u8, i8); }

        [[clang::always_inline]]
        static Vector Shuffle16(const Vector table, const Vector index) noexcept
        { return _mm512_shuffle_epi8(table, index); }

#if defined(__AVX512VBMI__)
        [[clang::always_inline]]
        static Vector Permute64(const Vector table, const Vector index) noexcept
        { return _mm512_permutexvar_epi8(index, table); }
#endif

        [[clang::always_inline]]
        static u64 TestMask64(const Vector left, const Vector right) noexcept
        { return _mm512_test_epi8_mask(left, right); }

        [[clang::always_inline]]
        static Vector BlendMaskU08(const Vector mask, const Vector left, const Vector right) noexcept
        { return _mm512_mask_blend_epi8(_mm512_movepi8_mask(mask), left, right); }

        [[clang::always_inline]]
        static Vector PutU08(const Vector value, const Vector lanes, const u08 lane, const u08 code) noexcept
        {
            const __mmask64 select = _mm512_cmpeq_epi8_mask(lanes, _mm512_set1_epi8(static_cast<i08>(lane)));

            return _mm512_mask_set1_epi8(value, select, static_cast<i08>(code));
        }

        [[clang::always_inline]]
        static Vector WidenU08U32(const Vector value) noexcept
        { return _mm512_cvtepu8_epi32(_mm512_castsi512_si128(value)); }

        [[clang::always_inline]]
        static Array<Vector, 2> WidenI08(const Vector value) noexcept
        {
            return {
                _mm512_cvtepi8_epi16(_mm512_castsi512_si256   (value   )),
                _mm512_cvtepi8_epi16(_mm512_extracti64x4_epi64(value, 1))
            };
        }

        template<s00 Scale>
        [[clang::always_inline]]
        static Vector GatherI32(const void* const base, const Vector index) noexcept
        {
            static_assert(Scale == 1 || Scale == 2 || Scale == 4 || Scale == 8, "a gather scale is 1, 2, 4 or 8");

            return _mm512_i32gather_epi32(index, base, Scale);
        }

        [[clang::always_inline]]
        static Vector DotI16(const Vector sum, const Vector left, const Vector right) noexcept
        { return _mm512_add_epi32(sum, _mm512_madd_epi16(left, right)); }

        [[clang::always_inline]]
        static Vector DotU08I08Wide(const Vector sum, const Vector u8, const Vector i8) noexcept
        {
            const auto low = _mm512_set1_epi16(0x00FF);

            const auto even = _mm512_srai_epi16(_mm512_slli_epi16(i8, 8), 8);
            const auto odd  = _mm512_srai_epi16(                  i8    , 8);

            const auto sums = _mm512_add_epi32(
                _mm512_madd_epi16(_mm512_and_si512(u8, low), even),
                _mm512_madd_epi16(_mm512_srli_epi16(u8, 8 ), odd )
            );

            return _mm512_add_epi32(sum, sums);
        }

        [[clang::always_inline]]
        static Vector DotU08I08(const Vector sum, const Vector u8, const Vector i8) noexcept
        {
            return _mm512_add_epi32(sum, _mm512_madd_epi16(_mm512_maddubs_epi16(u8, i8), _mm512_set1_epi16(1)));
        }

        template<s00 N>
        [[clang::always_inline]]
        static VectorF LoadF(const std::array<f32, N>& array, const s00 index) noexcept
        { return _mm512_load_ps(&array[index]); }

        [[clang::always_inline]]
        static VectorF LoadF(const f32* const address) noexcept { return _mm512_load_ps(address); }

        [[clang::always_inline]]
        static void StoreF(f32* const address, const VectorF value) noexcept { _mm512_store_ps(address, value); }

        template<s00 N>
        [[clang::always_inline]]
        static void StoreF(std::array<f32, N>& array, const s00 index, const VectorF value) noexcept
        { _mm512_store_ps(&array[index], value); }

        [[clang::always_inline]]
        static VectorF ZeroF() noexcept { return _mm512_setzero_ps(); }

        [[clang::always_inline]]
        static VectorF BroadcastF(const f32 value) noexcept { return _mm512_set1_ps(value); }

        [[clang::always_inline]]
        static VectorF CvtI32F(const Vector value) noexcept { return _mm512_cvtepi32_ps(value); }

        [[clang::always_inline]]
        static VectorF AddF(const VectorF left, const VectorF right) noexcept { return _mm512_add_ps(left, right); }

        [[clang::always_inline]]
        static VectorF MulF(const VectorF left, const VectorF right) noexcept { return _mm512_mul_ps(left, right); }

        [[clang::always_inline]]
        static VectorF MinF(const VectorF left, const VectorF right) noexcept { return _mm512_min_ps(left, right); }

        [[clang::always_inline]]
        static VectorF MaxF(const VectorF left, const VectorF right) noexcept { return _mm512_max_ps(left, right); }

        [[clang::always_inline]]
        static VectorF FmaF(const VectorF left, const VectorF right, const VectorF addend) noexcept
        { return _mm512_fmadd_ps(left, right, addend); }

        [[clang::always_inline]]
        static f32 ReduceF(const VectorF value) noexcept
        {
            const auto high = _mm256_castpd_ps(_mm512_extractf64x4_pd(_mm512_castps_pd(value), 1));

            return AVX2::ReduceF(_mm256_add_ps(_mm512_castps512_ps256(value), high));
        }

        [[clang::always_inline]]
        static void Prefetch(const void* const address) noexcept
        { _mm_prefetch(static_cast<const char*>(address), _MM_HINT_T0); }

    };

}

#endif

#endif //MANTARAY_BACKEND_ISA_AVX512_H
