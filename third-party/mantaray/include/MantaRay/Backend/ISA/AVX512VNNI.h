//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_BACKEND_ISA_AVX512VNNI_H
#define MANTARAY_BACKEND_ISA_AVX512VNNI_H

#if defined(__AVX512BW__) && defined(__AVX512VNNI__)

#include <immintrin.h>

#include "AVX512.h"

namespace MantaRay::Backend::ISA
{

    struct AVX512VNNI : AVX512
    {

        constexpr static bool VNNI = true;

        constexpr static s00 DotInFlight = 6;

        [[clang::always_inline]]
        static Vector DotU08I08(const Vector sum, const Vector u8, const Vector i8) noexcept
        { return _mm512_dpbusd_epi32(sum, u8, i8); }

        [[clang::always_inline]]
        static Vector DotU08I08Wide(const Vector sum, const Vector u8, const Vector i8) noexcept
        { return _mm512_dpbusd_epi32(sum, u8, i8); }

        [[clang::always_inline]]
        static Vector DotI16(const Vector sum, const Vector left, const Vector right) noexcept
        { return _mm512_dpwssd_epi32(sum, left, right); }

    };

}

#endif

#endif //MANTARAY_BACKEND_ISA_AVX512VNNI_H
