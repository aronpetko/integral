//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_BACKEND_ISA_SSE41_H
#define MANTARAY_BACKEND_ISA_SSE41_H

#if defined(__SSE4_1__)

#include <array>
#include <type_traits>
#include <utility>

#include <immintrin.h>

#include "SSE2.h"
#include "../../Common.h"

namespace MantaRay::Backend::ISA
{

    struct SSE41 : SSE2
    {

        constexpr static bool Maddubs = true;

        template<typename T, typename W>
        [[clang::always_inline]]
        static Vector LoadAs(const W* const address) noexcept
        {
            static_assert(IsWidening<T, W>, "LoadAs reads W == T or sign-extends i08 to i16 or i32 and i16 to i32");

            if (std::is_same_v<T, W>) return Load(address);

            if (std::is_same_v<T, i16> && std::is_same_v<W, i08>)
                return _mm_cvtepi8_epi16 (_mm_loadl_epi64(reinterpret_cast<const Vector*>(address)));

            if (std::is_same_v<T, i32> && std::is_same_v<W, i16>)
                return _mm_cvtepi16_epi32(_mm_loadl_epi64(reinterpret_cast<const Vector*>(address)));

            if (std::is_same_v<T, i32> && std::is_same_v<W, i08>)
                return _mm_cvtepi8_epi32 (_mm_loadu_si32 (                             address ));

            std::unreachable();
        }

        template<typename T, typename W, s00 N>
        [[clang::always_inline]]
        static Vector LoadAs(const std::array<W, N>& array, const s00 index) noexcept
        { return LoadAs<T>(&array[index]); }

        [[clang::always_inline]]
        static Vector MulLoI32(const Vector left, const Vector right) noexcept { return _mm_mullo_epi32(left, right); }

        [[clang::always_inline]]
        static Vector MinI32(const Vector left, const Vector right) noexcept { return _mm_min_epi32(left, right); }

        [[clang::always_inline]]
        static Vector MaxI32(const Vector left, const Vector right) noexcept { return _mm_max_epi32(left, right); }

        [[clang::always_inline]]
        static i64 ReduceI64(const Vector value) noexcept
        {
            const auto wide = _mm_add_epi64(
                _mm_cvtepi32_epi64(                   value        ),
                _mm_cvtepi32_epi64(_mm_unpackhi_epi64(value, value))
            );

            return Detail::ReducePairI64(wide);
        }

        [[clang::always_inline]]
        static Vector DotU08I08(const Vector sum, const Vector u8, const Vector i8) noexcept
        {
            return _mm_add_epi32(sum, _mm_madd_epi16(_mm_maddubs_epi16(u8, i8), _mm_set1_epi16(1)));
        }

        [[clang::always_inline]]
        static Vector MaddubsI16(const Vector u8, const Vector i8) noexcept { return _mm_maddubs_epi16(u8, i8); }

        [[clang::always_inline]]
        static Vector BlendMaskU08(const Vector mask, const Vector left, const Vector right) noexcept
        { return _mm_blendv_epi8(left, right, mask); }

        [[clang::always_inline]]
        static Vector PutU08(const Vector value, const Vector lanes, const u08 lane, const u08 code) noexcept
        {
            const auto select = _mm_cmpeq_epi8(lanes, _mm_set1_epi8(static_cast<i08>(lane)));

            return _mm_blendv_epi8(value, _mm_set1_epi8(static_cast<i08>(code)), select);
        }

        [[clang::always_inline]]
        static Vector WidenU08U32(const Vector value) noexcept { return _mm_cvtepu8_epi32(value); }

        [[clang::always_inline]]
        static Array<Vector, 2> WidenI08(const Vector value) noexcept
        { return { _mm_cvtepi8_epi16(value), _mm_cvtepi8_epi16(_mm_unpackhi_epi64(value, value)) }; }

    };

}

#endif

#endif //MANTARAY_BACKEND_ISA_SSE41_H
