//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_BACKEND_ISA_AVX2_H
#define MANTARAY_BACKEND_ISA_AVX2_H

#if defined(__AVX2__)

#include <array>
#include <type_traits>
#include <utility>

#include <immintrin.h>

#include "SSE41.h"
#include "../../Common.h"

namespace MantaRay::Backend::ISA
{

    struct AVX2
    {

        using Vector  = __m256i;
        using VectorF = __m256 ;

        static_assert(alignof(Array<Vector , 2>) == alignof(Vector ), "arrays of vectors keep the vector's alignment");
        static_assert(alignof(Array<VectorF, 2>) == alignof(VectorF), "arrays of vectors keep the vector's alignment");

        constexpr static s00 Bytes     = 32;
        constexpr static s00 Registers = 16;
        constexpr static s00 DotChains =  2;

        constexpr static bool VNNI = false;

        constexpr static bool Masks    = false;
        constexpr static bool Permute8 = false;
        constexpr static bool Compress = false;
        constexpr static bool Table    = false;
        constexpr static bool PairDot  = true;
        constexpr static bool Maddubs  = true;

#if defined(__SSSE3__)
        constexpr static bool Shuffle = true;
#else
        constexpr static bool Shuffle = false;
#endif

        constexpr static bool Gather = true;

#if defined(__FMA__)
        constexpr static bool FMA = true;
#else
        constexpr static bool FMA = false;
#endif

        constexpr static s00 DotInFlight = 1;

        template<typename T>
        [[clang::always_inline]]
        static Vector Load(const T* const address) noexcept
        { return _mm256_load_si256(reinterpret_cast<const Vector*>(address)); }

        template<typename T, s00 N>
        [[clang::always_inline]]
        static Vector Load(const std::array<T, N>& array, const s00 index) noexcept
        { return _mm256_load_si256(reinterpret_cast<const Vector*>(&array[index])); }

        template<typename T>
        [[clang::always_inline]]
        static void Store(T* const address, const Vector value) noexcept
        { _mm256_store_si256(reinterpret_cast<Vector*>(address), value); }

        template<typename T, s00 N>
        [[clang::always_inline]]
        static void Store(std::array<T, N>& array, const s00 index, const Vector value) noexcept
        { _mm256_store_si256(reinterpret_cast<Vector*>(&array[index]), value); }

        template<typename T>
        [[clang::always_inline]]
        static void StoreUnaligned(T* const address, const Vector value) noexcept
        { _mm256_storeu_si256(reinterpret_cast<Vector*>(address), value); }

        template<typename T, s00 N>
        [[clang::always_inline]]
        static void StoreUnaligned(std::array<T, N>& array, const s00 index, const Vector value) noexcept
        { _mm256_storeu_si256(reinterpret_cast<Vector*>(&array[index]), value); }

        template<typename T>
        [[clang::always_inline]]
        static Vector LoadUnaligned(const T* const address) noexcept
        { return _mm256_loadu_si256(reinterpret_cast<const Vector*>(address)); }

        template<typename T, s00 N>
        [[clang::always_inline]]
        static Vector LoadUnaligned(const std::array<T, N>& array, const s00 index) noexcept
        { return _mm256_loadu_si256(reinterpret_cast<const Vector*>(&array[index])); }

        [[clang::always_inline]]
        static Vector BroadcastU128(const u08* const address) noexcept
        { return _mm256_broadcastsi128_si256(_mm_loadu_si128(reinterpret_cast<const __m128i*>(address))); }

        template<typename T, typename W>
        [[clang::always_inline]]
        static Vector LoadAs(const W* const address) noexcept
        {
            static_assert(IsWidening<T, W>, "LoadAs reads W == T or sign-extends i08 to i16 or i32 and i16 to i32");

            if (std::is_same_v<T, W>) return Load(address);

            if (std::is_same_v<T, i16> && std::is_same_v<W, i08>)
                return _mm256_cvtepi8_epi16 (_mm_load_si128 (reinterpret_cast<const __m128i*>(address)));

            if (std::is_same_v<T, i32> && std::is_same_v<W, i16>)
                return _mm256_cvtepi16_epi32(_mm_load_si128 (reinterpret_cast<const __m128i*>(address)));

            if (std::is_same_v<T, i32> && std::is_same_v<W, i08>)
                return _mm256_cvtepi8_epi32 (_mm_loadl_epi64(reinterpret_cast<const __m128i*>(address)));

            std::unreachable();
        }

        template<typename T, typename W, s00 N>
        [[clang::always_inline]]
        static Vector LoadAs(const std::array<W, N>& array, const s00 index) noexcept
        { return LoadAs<T>(&array[index]); }

        [[clang::always_inline]]
        static Vector Zero() noexcept { return _mm256_setzero_si256(); }

        [[clang::always_inline]]
        static Vector BroadcastU08(const u08 value) noexcept { return _mm256_set1_epi8(static_cast<i08>(value)); }

        [[clang::always_inline]]
        static Vector BroadcastI16(const i16 value) noexcept { return _mm256_set1_epi16(value); }

        [[clang::always_inline]]
        static Vector BroadcastI32(const i32 value) noexcept { return _mm256_set1_epi32(value); }

        [[clang::always_inline]]
        static Vector BroadcastU32(const u08* const address) noexcept
        { return _mm256_broadcastd_epi32(_mm_loadu_si32(address)); }

        [[clang::always_inline]]
        static Vector And(const Vector left, const Vector right) noexcept { return _mm256_and_si256(left, right); }

        [[clang::always_inline]]
        static Vector Or(const Vector left, const Vector right) noexcept { return _mm256_or_si256(left, right); }

        [[clang::always_inline]]
        static Vector Xor(const Vector left, const Vector right) noexcept { return _mm256_xor_si256(left, right); }

        [[clang::always_inline]]
        static Vector AddI16(const Vector left, const Vector right) noexcept { return _mm256_add_epi16(left, right); }

        [[clang::always_inline]]
        static Vector SubI16(const Vector left, const Vector right) noexcept { return _mm256_sub_epi16(left, right); }

        [[clang::always_inline]]
        static Vector MinI16(const Vector left, const Vector right) noexcept { return _mm256_min_epi16(left, right); }

        [[clang::always_inline]]
        static Vector MaxI16(const Vector left, const Vector right) noexcept { return _mm256_max_epi16(left, right); }

        [[clang::always_inline]]
        static Vector MulLoI16(const Vector left, const Vector right) noexcept
        { return _mm256_mullo_epi16(left, right); }

        [[clang::always_inline]]
        static Vector MulHiI16(const Vector left, const Vector right) noexcept
        { return _mm256_mulhi_epi16(left, right); }

        template<s00 S>
        [[clang::always_inline]]
        static Vector ShiftLeftI16(const Vector value) noexcept
        {
            static_assert(S < 16, "an i16 shift stays below 16");

            return _mm256_slli_epi16(value, S);
        }

        template<s00 S>
        [[clang::always_inline]]
        static Vector ShiftRightI16(const Vector value) noexcept
        {
            static_assert(S < 16, "an i16 shift stays below 16");

            return _mm256_srai_epi16(value, S);
        }

        [[clang::always_inline]]
        static Vector AddI32(const Vector left, const Vector right) noexcept { return _mm256_add_epi32(left, right); }

        [[clang::always_inline]]
        static Vector SubI32(const Vector left, const Vector right) noexcept { return _mm256_sub_epi32(left, right); }

        [[clang::always_inline]]
        static Vector MulLoI32(const Vector left, const Vector right) noexcept
        { return _mm256_mullo_epi32(left, right); }

        [[clang::always_inline]]
        static Vector MinI32(const Vector left, const Vector right) noexcept { return _mm256_min_epi32(left, right); }

        [[clang::always_inline]]
        static Vector MaxI32(const Vector left, const Vector right) noexcept { return _mm256_max_epi32(left, right); }

        [[clang::always_inline]]
        static Vector CompareGreaterI32(const Vector left, const Vector right) noexcept
        { return _mm256_cmpgt_epi32(left, right); }

        template<s00 S>
        [[clang::always_inline]]
        static Vector ShiftRightI32(const Vector value) noexcept
        {
            static_assert(S < 32, "an i32 shift stays below 32");

            return _mm256_srai_epi32(value, S);
        }

        template<s00 S>
        [[clang::always_inline]]
        static Vector ShiftRightU32(const Vector value) noexcept
        {
            static_assert(S < 32, "a u32 shift stays below 32");

            return _mm256_srli_epi32(value, S);
        }

        template<s00 S>
        [[clang::always_inline]]
        static Vector ShiftLeftI32(const Vector value) noexcept
        {
            static_assert(S < 32, "an i32 shift stays below 32");

            return _mm256_slli_epi32(value, S);
        }

        [[clang::always_inline]]
        static Vector ShiftLeftVarI32(const Vector value, const Vector count) noexcept
        { return _mm256_sllv_epi32(value, count); }

        template<bool Positive>
        [[clang::always_inline]]
        static u32 NonzeroMaskI32(const Vector value) noexcept
        {
            const auto zero = _mm256_setzero_si256();

            const auto lanes = Positive ? _mm256_cmpgt_epi32(value, zero) : _mm256_cmpeq_epi32(value, zero);
            const auto mask  = static_cast<u32>(_mm256_movemask_ps(_mm256_castsi256_ps(lanes)));

            return Positive ? mask : mask ^ 0xFF;
        }

        [[clang::always_inline]]
        static Vector MaddI16(const Vector left, const Vector right) noexcept { return _mm256_madd_epi16(left, right); }

        [[clang::always_inline]]
        static i32 ReduceI32(const Vector value) noexcept
        {
            return SSE41::ReduceI32(_mm_add_epi32(_mm256_castsi256_si128(value), _mm256_extracti128_si256(value, 1)));
        }

        [[clang::always_inline]]
        static i64 ReduceI64(const Vector value) noexcept
        {
            const auto wide = _mm256_add_epi64(
                _mm256_cvtepi32_epi64(_mm256_castsi256_si128  (value   )),
                _mm256_cvtepi32_epi64(_mm256_extracti128_si256(value, 1))
            );

            const auto half = _mm_add_epi64(_mm256_castsi256_si128(wide), _mm256_extracti128_si256(wide, 1));

            return Detail::ReducePairI64(half);
        }

        [[clang::always_inline]]
        static Vector PackUnsignedI16(const Vector left, const Vector right) noexcept
        { return _mm256_packus_epi16(left, right); }

        [[clang::always_inline]]
        static Vector PackU08(const Vector left, const Vector right) noexcept
        { return _mm256_permute4x64_epi64(PackUnsignedI16(left, right), 0xD8); }

        [[clang::always_inline]]
        static Vector PackI16(const Vector left, const Vector right) noexcept
        { return _mm256_permute4x64_epi64(_mm256_packs_epi32(left, right), 0xD8); }

        [[clang::always_inline]]
        static Vector MaddubsI16(const Vector u8, const Vector i8) noexcept { return _mm256_maddubs_epi16(u8, i8); }

        [[clang::always_inline]]
        static Vector Shuffle16(const Vector table, const Vector index) noexcept
        { return _mm256_shuffle_epi8(table, index); }

        [[clang::always_inline]]
        static u64 TestMask64(const Vector left, const Vector right) noexcept
        {
            const auto zero = _mm256_cmpeq_epi8(_mm256_and_si256(left, right), _mm256_setzero_si256());

            return ~static_cast<u32>(_mm256_movemask_epi8(zero));
        }

        [[clang::always_inline]]
        static Vector BlendMaskU08(const Vector mask, const Vector left, const Vector right) noexcept
        { return _mm256_blendv_epi8(left, right, mask); }

        [[clang::always_inline]]
        static Vector PutU08(const Vector value, const Vector lanes, const u08 lane, const u08 code) noexcept
        {
            const auto select = _mm256_cmpeq_epi8(lanes, _mm256_set1_epi8(static_cast<i08>(lane)));

            return _mm256_blendv_epi8(value, _mm256_set1_epi8(static_cast<i08>(code)), select);
        }

        [[clang::always_inline]]
        static Vector WidenU08U32(const Vector value) noexcept
        { return _mm256_cvtepu8_epi32(_mm256_castsi256_si128(value)); }

        [[clang::always_inline]]
        static Array<Vector, 2> WidenI08(const Vector value) noexcept
        {
            return {
                _mm256_cvtepi8_epi16(_mm256_castsi256_si128  (value   )),
                _mm256_cvtepi8_epi16(_mm256_extracti128_si256(value, 1))
            };
        }

        template<s00 Scale>
        [[clang::always_inline]]
        static Vector GatherI32(const void* const base, const Vector index) noexcept
        {
            static_assert(Scale == 1 || Scale == 2 || Scale == 4 || Scale == 8, "a gather scale is 1, 2, 4 or 8");

            return _mm256_i32gather_epi32(static_cast<const i32*>(base), index, Scale);
        }

        [[clang::always_inline]]
        static Vector DotI16(const Vector sum, const Vector left, const Vector right) noexcept
        { return _mm256_add_epi32(sum, _mm256_madd_epi16(left, right)); }

        [[clang::always_inline]]
        static Vector DotU08I08Wide(const Vector sum, const Vector u8, const Vector i8) noexcept
        {
            const auto low = _mm256_set1_epi16(0x00FF);

            const auto even = _mm256_srai_epi16(_mm256_slli_epi16(i8, 8), 8);
            const auto odd  = _mm256_srai_epi16(                  i8    , 8);

            const auto sums = _mm256_add_epi32(
                _mm256_madd_epi16(_mm256_and_si256(u8, low), even),
                _mm256_madd_epi16(_mm256_srli_epi16(u8, 8 ), odd )
            );

            return _mm256_add_epi32(sum, sums);
        }

        [[clang::always_inline]]
        static Vector DotU08I08(const Vector sum, const Vector u8, const Vector i8) noexcept
        {
            return _mm256_add_epi32(sum, _mm256_madd_epi16(_mm256_maddubs_epi16(u8, i8), _mm256_set1_epi16(1)));
        }

        template<s00 N>
        [[clang::always_inline]]
        static VectorF LoadF(const std::array<f32, N>& array, const s00 index) noexcept
        { return _mm256_load_ps(&array[index]); }

        [[clang::always_inline]]
        static VectorF LoadF(const f32* const address) noexcept { return _mm256_load_ps(address); }

        [[clang::always_inline]]
        static void StoreF(f32* const address, const VectorF value) noexcept { _mm256_store_ps(address, value); }

        template<s00 N>
        [[clang::always_inline]]
        static void StoreF(std::array<f32, N>& array, const s00 index, const VectorF value) noexcept
        { _mm256_store_ps(&array[index], value); }

        [[clang::always_inline]]
        static VectorF ZeroF() noexcept { return _mm256_setzero_ps(); }

        [[clang::always_inline]]
        static VectorF BroadcastF(const f32 value) noexcept { return _mm256_set1_ps(value); }

        [[clang::always_inline]]
        static VectorF CvtI32F(const Vector value) noexcept { return _mm256_cvtepi32_ps(value); }

        [[clang::always_inline]]
        static VectorF AddF(const VectorF left, const VectorF right) noexcept { return _mm256_add_ps(left, right); }

        [[clang::always_inline]]
        static VectorF MulF(const VectorF left, const VectorF right) noexcept { return _mm256_mul_ps(left, right); }

        [[clang::always_inline]]
        static VectorF MinF(const VectorF left, const VectorF right) noexcept { return _mm256_min_ps(left, right); }

        [[clang::always_inline]]
        static VectorF MaxF(const VectorF left, const VectorF right) noexcept { return _mm256_max_ps(left, right); }

#if defined(__FMA__)
        [[clang::always_inline]]
        static VectorF FmaF(const VectorF left, const VectorF right, const VectorF addend) noexcept
        { return _mm256_fmadd_ps(left, right, addend); }
#else
        [[clang::always_inline]]
        static VectorF FmaF(const VectorF left, const VectorF right, const VectorF addend) noexcept
        {
            const auto low  = SSE41::FmaF(
                _mm256_castps256_ps128(left  ),
                _mm256_castps256_ps128(right ),
                _mm256_castps256_ps128(addend)
            );
            const auto high = SSE41::FmaF(
                _mm256_extractf128_ps(left  , 1),
                _mm256_extractf128_ps(right , 1),
                _mm256_extractf128_ps(addend, 1)
            );

            return _mm256_insertf128_ps(_mm256_castps128_ps256(low), high, 1);
        }
#endif

        [[clang::always_inline]]
        static f32 ReduceF(const VectorF value) noexcept
        {
            return SSE41::ReduceF(_mm_add_ps(_mm256_castps256_ps128(value), _mm256_extractf128_ps(value, 1)));
        }

        [[clang::always_inline]]
        static void Prefetch(const void* const address) noexcept
        { _mm_prefetch(static_cast<const char*>(address), _MM_HINT_T0); }

    };

}

#endif

#endif //MANTARAY_BACKEND_ISA_AVX2_H
