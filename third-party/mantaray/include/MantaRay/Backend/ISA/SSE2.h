//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_BACKEND_ISA_SSE2_H
#define MANTARAY_BACKEND_ISA_SSE2_H

#if defined(__SSE2__)

#include <array>
#include <type_traits>
#include <utility>

#include <immintrin.h>

#include "../../Common.h"

namespace MantaRay::Backend::ISA
{

    namespace Detail
    {

        [[clang::always_inline]]
        inline __m128d FmaToOdd(const __m128 left, const __m128 right, const __m128 addend) noexcept
        {
            #pragma clang fp contract(off)

            const auto product = _mm_mul_pd(_mm_cvtps_pd(left), _mm_cvtps_pd(right));
            const auto other   = _mm_cvtps_pd(addend);

            const auto sum   = _mm_add_pd(product, other);
            const auto part  = _mm_sub_pd(sum, product);
            const auto error = _mm_add_pd(_mm_sub_pd(product, _mm_sub_pd(sum, part)), _mm_sub_pd(other, part));

            const auto bits  = _mm_castpd_si128(sum);
            const auto signs = _mm_xor_si128(bits, _mm_castpd_si128(error));
            const auto one   = _mm_set1_epi64x(1);
            const auto zero  = _mm_setzero_si128();

            const auto even     = _mm_shuffle_epi32(_mm_cmpeq_epi32(_mm_and_si128(bits, one), zero), 0xA0);
            const auto inexact  = _mm_castpd_si128(_mm_cmpneq_pd(error, _mm_setzero_pd()));
            const auto finite   = _mm_castpd_si128(_mm_cmpeq_pd(_mm_sub_pd(sum, sum), _mm_setzero_pd()));
            const auto opposite = _mm_srai_epi32(_mm_shuffle_epi32(signs, 0xF5), 31);

            const auto odd = _mm_and_si128(even, _mm_and_si128(inexact, finite));

            return _mm_castsi128_pd(_mm_add_epi64(bits, _mm_and_si128(odd, _mm_or_si128(opposite, one))));
        }

        [[clang::always_inline]]
        inline i64 ReducePairI64(const __m128i value) noexcept
        { return _mm_cvtsi128_si64(_mm_add_epi64(value, _mm_unpackhi_epi64(value, value))); }

    }

    struct SSE2
    {

        using Vector  = __m128i;
        using VectorF = __m128 ;

        static_assert(alignof(Array<Vector , 2>) == alignof(Vector ), "arrays of vectors keep the vector's alignment");
        static_assert(alignof(Array<VectorF, 2>) == alignof(VectorF), "arrays of vectors keep the vector's alignment");

        constexpr static s00 Bytes     = 16;
        constexpr static s00 Registers = 16;
        constexpr static s00 DotChains =  2;

        constexpr static bool VNNI = false;

        constexpr static bool Masks    = false;
        constexpr static bool Permute8 = false;
        constexpr static bool Compress = false;
        constexpr static bool Gather   = false;
        constexpr static bool Table    = false;
        constexpr static bool PairDot  = true;
        constexpr static bool Maddubs  = false;

#if defined(__SSSE3__)
        constexpr static bool Shuffle = true;
#else
        constexpr static bool Shuffle = false;
#endif

#if defined(__FMA__)
        constexpr static bool FMA = true;
#else
        constexpr static bool FMA = false;
#endif

        constexpr static s00 DotInFlight = 1;

        template<typename T>
        [[clang::always_inline]]
        static Vector Load(const T* const address) noexcept
        { return _mm_load_si128(reinterpret_cast<const Vector*>(address)); }

        template<typename T, s00 N>
        [[clang::always_inline]]
        static Vector Load(const std::array<T, N>& array, const s00 index) noexcept
        { return _mm_load_si128(reinterpret_cast<const Vector*>(&array[index])); }

        template<typename T>
        [[clang::always_inline]]
        static void Store(T* const address, const Vector value) noexcept
        { _mm_store_si128(reinterpret_cast<Vector*>(address), value); }

        template<typename T, s00 N>
        [[clang::always_inline]]
        static void Store(std::array<T, N>& array, const s00 index, const Vector value) noexcept
        { _mm_store_si128(reinterpret_cast<Vector*>(&array[index]), value); }

        template<typename T>
        [[clang::always_inline]]
        static void StoreUnaligned(T* const address, const Vector value) noexcept
        { _mm_storeu_si128(reinterpret_cast<Vector*>(address), value); }

        template<typename T, s00 N>
        [[clang::always_inline]]
        static void StoreUnaligned(std::array<T, N>& array, const s00 index, const Vector value) noexcept
        { _mm_storeu_si128(reinterpret_cast<Vector*>(&array[index]), value); }

        template<typename T>
        [[clang::always_inline]]
        static Vector LoadUnaligned(const T* const address) noexcept
        { return _mm_loadu_si128(reinterpret_cast<const Vector*>(address)); }

        template<typename T, s00 N>
        [[clang::always_inline]]
        static Vector LoadUnaligned(const std::array<T, N>& array, const s00 index) noexcept
        { return _mm_loadu_si128(reinterpret_cast<const Vector*>(&array[index])); }

        [[clang::always_inline]]
        static Vector BroadcastU128(const u08* const address) noexcept
        { return _mm_loadu_si128(reinterpret_cast<const Vector*>(address)); }

        template<typename T, typename W>
        [[clang::always_inline]]
        static Vector LoadAs(const W* const address) noexcept
        {
            static_assert(IsWidening<T, W>, "LoadAs reads W == T or sign-extends i08 to i16 or i32 and i16 to i32");

            if (std::is_same_v<T, W>) return Load(address);

            if (std::is_same_v<T, i16> && std::is_same_v<W, i08>) {
                const auto bytes = _mm_loadl_epi64(reinterpret_cast<const Vector*>(address));

                return _mm_srai_epi16(_mm_unpacklo_epi8(bytes, bytes), 8);
            }

            if (std::is_same_v<T, i32> && std::is_same_v<W, i16>) {
                const auto words = _mm_loadl_epi64(reinterpret_cast<const Vector*>(address));

                return _mm_srai_epi32(_mm_unpacklo_epi16(words, words), 16);
            }

            if (std::is_same_v<T, i32> && std::is_same_v<W, i08>) {
                const auto bytes = _mm_loadu_si32(address);
                const auto words = _mm_unpacklo_epi8(bytes, bytes);

                return _mm_srai_epi32(_mm_unpacklo_epi16(words, words), 24);
            }

            std::unreachable();
        }

        template<typename T, typename W, s00 N>
        [[clang::always_inline]]
        static Vector LoadAs(const std::array<W, N>& array, const s00 index) noexcept
        { return LoadAs<T>(&array[index]); }

        [[clang::always_inline]]
        static Vector Zero() noexcept { return _mm_setzero_si128(); }

        [[clang::always_inline]]
        static Vector BroadcastU08(const u08 value) noexcept { return _mm_set1_epi8(static_cast<i08>(value)); }

        [[clang::always_inline]]
        static Vector BroadcastI16(const i16 value) noexcept { return _mm_set1_epi16(value); }

        [[clang::always_inline]]
        static Vector BroadcastI32(const i32 value) noexcept { return _mm_set1_epi32(value); }

        [[clang::always_inline]]
        static Vector BroadcastU32(const u08* const address) noexcept
        { return _mm_shuffle_epi32(_mm_loadu_si32(address), 0); }

        [[clang::always_inline]]
        static Vector And(const Vector left, const Vector right) noexcept { return _mm_and_si128(left, right); }

        [[clang::always_inline]]
        static Vector Or(const Vector left, const Vector right) noexcept { return _mm_or_si128(left, right); }

        [[clang::always_inline]]
        static Vector AddI16(const Vector left, const Vector right) noexcept { return _mm_add_epi16(left, right); }

        [[clang::always_inline]]
        static Vector SubI16(const Vector left, const Vector right) noexcept { return _mm_sub_epi16(left, right); }

        [[clang::always_inline]]
        static Vector MinI16(const Vector left, const Vector right) noexcept { return _mm_min_epi16(left, right); }

        [[clang::always_inline]]
        static Vector MaxI16(const Vector left, const Vector right) noexcept { return _mm_max_epi16(left, right); }

        [[clang::always_inline]]
        static Vector MulLoI16(const Vector left, const Vector right) noexcept { return _mm_mullo_epi16(left, right); }

        [[clang::always_inline]]
        static Vector MulHiI16(const Vector left, const Vector right) noexcept { return _mm_mulhi_epi16(left, right); }

        template<s00 S>
        [[clang::always_inline]]
        static Vector ShiftLeftI16(const Vector value) noexcept
        {
            static_assert(S < 16, "an i16 shift stays below 16");

            return _mm_slli_epi16(value, S);
        }

        template<s00 S>
        [[clang::always_inline]]
        static Vector ShiftRightI16(const Vector value) noexcept
        {
            static_assert(S < 16, "an i16 shift stays below 16");

            return _mm_srai_epi16(value, S);
        }

        [[clang::always_inline]]
        static Vector AddI32(const Vector left, const Vector right) noexcept { return _mm_add_epi32(left, right); }

        [[clang::always_inline]]
        static Vector SubI32(const Vector left, const Vector right) noexcept { return _mm_sub_epi32(left, right); }

        [[clang::always_inline]]
        static Vector MulLoI32(const Vector left, const Vector right) noexcept
        {
            const auto even = _mm_mul_epu32(               left    ,                right    );
            const auto odd  = _mm_mul_epu32(_mm_srli_si128(left, 4), _mm_srli_si128(right, 4));

            return _mm_unpacklo_epi32(_mm_shuffle_epi32(even, 0x88), _mm_shuffle_epi32(odd, 0x88));
        }

        [[clang::always_inline]]
        static Vector MinI32(const Vector left, const Vector right) noexcept
        {
            const auto greater = _mm_cmpgt_epi32(left, right);

            return _mm_or_si128(_mm_and_si128(greater, right), _mm_andnot_si128(greater, left));
        }

        [[clang::always_inline]]
        static Vector MaxI32(const Vector left, const Vector right) noexcept
        {
            const auto greater = _mm_cmpgt_epi32(left, right);

            return _mm_or_si128(_mm_and_si128(greater, left), _mm_andnot_si128(greater, right));
        }

        template<s00 S>
        [[clang::always_inline]]
        static Vector ShiftRightI32(const Vector value) noexcept
        {
            static_assert(S < 32, "an i32 shift stays below 32");

            return _mm_srai_epi32(value, S);
        }

        template<s00 S>
        [[clang::always_inline]]
        static Vector ShiftLeftI32(const Vector value) noexcept
        {
            static_assert(S < 32, "an i32 shift stays below 32");

            return _mm_slli_epi32(value, S);
        }

        template<bool Positive>
        [[clang::always_inline]]
        static u32 NonzeroMaskI32(const Vector value) noexcept
        {
            const auto zero = _mm_setzero_si128();

            const auto lanes = Positive ? _mm_cmpgt_epi32(value, zero) : _mm_cmpeq_epi32(value, zero);
            const auto mask  = static_cast<u32>(_mm_movemask_ps(_mm_castsi128_ps(lanes)));

            return Positive ? mask : mask ^ 0xF;
        }

        [[clang::always_inline]]
        static Vector MaddI16(const Vector left, const Vector right) noexcept { return _mm_madd_epi16(left, right); }

        [[clang::always_inline]]
        static i32 ReduceI32(const Vector value) noexcept
        {
            const auto pairs = _mm_add_epi32(value, _mm_unpackhi_epi64(value, value));

            return _mm_cvtsi128_si32(_mm_add_epi32(pairs, _mm_shuffle_epi32(pairs, 0x55)));
        }

        [[clang::always_inline]]
        static i64 ReduceI64(const Vector value) noexcept
        {
            const auto sign = _mm_srai_epi32(value, 31);
            const auto wide = _mm_add_epi64(_mm_unpacklo_epi32(value, sign), _mm_unpackhi_epi32(value, sign));

            return Detail::ReducePairI64(wide);
        }

        [[clang::always_inline]]
        static Vector PackUnsignedI16(const Vector left, const Vector right) noexcept
        { return _mm_packus_epi16(left, right); }

        [[clang::always_inline]]
        static Vector PackU08(const Vector left, const Vector right) noexcept { return PackUnsignedI16(left, right); }

        [[clang::always_inline]]
        static Vector PackI16(const Vector left, const Vector right) noexcept { return _mm_packs_epi32(left, right); }

        [[clang::always_inline]]
        static u64 TestMask64(const Vector left, const Vector right) noexcept
        {
            const auto zero = _mm_cmpeq_epi8(_mm_and_si128(left, right), _mm_setzero_si128());

            return static_cast<u32>(_mm_movemask_epi8(zero)) ^ 0xFFFF;
        }

        [[clang::always_inline]]
        static Vector BlendMaskU08(const Vector mask, const Vector left, const Vector right) noexcept
        {
            const auto select = _mm_cmplt_epi8(mask, _mm_setzero_si128());

            return _mm_or_si128(_mm_and_si128(select, right), _mm_andnot_si128(select, left));
        }

        [[clang::always_inline]]
        static Vector PutU08(const Vector value, const Vector lanes, const u08 lane, const u08 code) noexcept
        {
            const auto select = _mm_cmpeq_epi8(lanes, _mm_set1_epi8(static_cast<i08>(lane)));
            const auto filled = _mm_set1_epi8(static_cast<i08>(code));

            return _mm_or_si128(_mm_and_si128(select, filled), _mm_andnot_si128(select, value));
        }

#if defined(__SSSE3__)
        [[clang::always_inline]]
        static Vector Shuffle16(const Vector table, const Vector index) noexcept
        { return _mm_shuffle_epi8(table, index); }
#endif

        [[clang::always_inline]]
        static Vector WidenU08U32(const Vector value) noexcept
        {
            const auto zero = _mm_setzero_si128();

            return _mm_unpacklo_epi16(_mm_unpacklo_epi8(value, zero), zero);
        }

        [[clang::always_inline]]
        static Array<Vector, 2> WidenI08(const Vector value) noexcept
        {
            return {
                _mm_srai_epi16(_mm_unpacklo_epi8(value, value), 8),
                _mm_srai_epi16(_mm_unpackhi_epi8(value, value), 8)
            };
        }

        [[clang::always_inline]]
        static Vector MaddubsI16(const Vector u8, const Vector i8) noexcept
        {
            const auto low = _mm_set1_epi16(0x00FF);

            const auto even = _mm_mullo_epi16(_mm_and_si128(u8, low), _mm_srai_epi16(_mm_slli_epi16(i8, 8), 8));
            const auto odd  = _mm_mullo_epi16(_mm_srli_epi16(u8, 8 ), _mm_srai_epi16(               i8    , 8));

            return _mm_adds_epi16(even, odd);
        }

        [[clang::always_inline]]
        static Vector DotI16(const Vector sum, const Vector left, const Vector right) noexcept
        { return _mm_add_epi32(sum, _mm_madd_epi16(left, right)); }

        [[clang::always_inline]]
        static Vector DotU08I08Wide(const Vector sum, const Vector u8, const Vector i8) noexcept
        {
            const auto low = _mm_set1_epi16(0x00FF);

            const auto even = _mm_madd_epi16(_mm_and_si128(u8, low), _mm_srai_epi16(_mm_slli_epi16(i8, 8), 8));
            const auto odd  = _mm_madd_epi16(_mm_srli_epi16(u8, 8 ), _mm_srai_epi16(               i8    , 8));

            return _mm_add_epi32(sum, _mm_add_epi32(even, odd));
        }

        [[clang::always_inline]]
        static Vector DotU08I08(const Vector sum, const Vector u8, const Vector i8) noexcept
        {
            return _mm_add_epi32(sum, _mm_madd_epi16(MaddubsI16(u8, i8), _mm_set1_epi16(1)));
        }

        template<s00 N>
        [[clang::always_inline]]
        static VectorF LoadF(const std::array<f32, N>& array, const s00 index) noexcept
        { return _mm_load_ps(&array[index]); }

        [[clang::always_inline]]
        static VectorF LoadF(const f32* const address) noexcept { return _mm_load_ps(address); }

        [[clang::always_inline]]
        static void StoreF(f32* const address, const VectorF value) noexcept { _mm_store_ps(address, value); }

        template<s00 N>
        [[clang::always_inline]]
        static void StoreF(std::array<f32, N>& array, const s00 index, const VectorF value) noexcept
        { _mm_store_ps(&array[index], value); }

        [[clang::always_inline]]
        static VectorF ZeroF() noexcept { return _mm_setzero_ps(); }

        [[clang::always_inline]]
        static VectorF BroadcastF(const f32 value) noexcept { return _mm_set1_ps(value); }

        [[clang::always_inline]]
        static VectorF CvtI32F(const Vector value) noexcept { return _mm_cvtepi32_ps(value); }

        [[clang::always_inline]]
        static VectorF AddF(const VectorF left, const VectorF right) noexcept { return _mm_add_ps(left, right); }

        [[clang::always_inline]]
        static VectorF MulF(const VectorF left, const VectorF right) noexcept { return _mm_mul_ps(left, right); }

        [[clang::always_inline]]
        static VectorF MinF(const VectorF left, const VectorF right) noexcept { return _mm_min_ps(left, right); }

        [[clang::always_inline]]
        static VectorF MaxF(const VectorF left, const VectorF right) noexcept { return _mm_max_ps(left, right); }

#if defined(__FMA__)
        [[clang::always_inline]]
        static VectorF FmaF(const VectorF left, const VectorF right, const VectorF addend) noexcept
        { return _mm_fmadd_ps(left, right, addend); }
#else
        [[clang::always_inline]]
        static VectorF FmaF(const VectorF left, const VectorF right, const VectorF addend) noexcept
        {
            const auto a = _mm_movehl_ps(left  , left  );
            const auto b = _mm_movehl_ps(right , right );
            const auto c = _mm_movehl_ps(addend, addend);

            const auto low  = _mm_cvtpd_ps(Detail::FmaToOdd(left, right, addend));
            const auto high = _mm_cvtpd_ps(Detail::FmaToOdd(a   , b    , c     ));

            return _mm_movelh_ps(low, high);
        }
#endif

        [[clang::always_inline]]
        static f32 ReduceF(const VectorF value) noexcept
        {
            const auto pairs = _mm_add_ps(value, _mm_movehl_ps(value, value));

            return _mm_cvtss_f32(_mm_add_ss(pairs, _mm_shuffle_ps(pairs, pairs, 0x55)));
        }

        [[clang::always_inline]]
        static void Prefetch(const void* const address) noexcept
        { _mm_prefetch(static_cast<const char*>(address), _MM_HINT_T0); }

    };

}

#endif

#endif //MANTARAY_BACKEND_ISA_SSE2_H
