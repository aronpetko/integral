//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_LOWERING_TARGET_H
#define MANTARAY_LOWERING_TARGET_H

#include <string_view>

#include "../Common.h"

namespace MantaRay::Lowering
{

    struct Target
    {

        std::string_view Name {};

        s00 Bytes       = 0;
        s00 Registers   = 0;
        s00 DotChains   = 2;
        s00 DotInFlight = 1;

        bool VNNI    = false;
        bool Maddubs = false;

    };

    constexpr inline Target Scalar {
        .Name      = "Scalar",
        .Bytes     = 16,
        .Registers = 16,
        .DotChains = 4
    };

    constexpr inline Target SSE2 {
        .Name      = "SSE2",
        .Bytes     = 16,
        .Registers = 16
    };

    constexpr inline Target SSE41 {
        .Name      = "SSE41",
        .Bytes     = 16,
        .Registers = 16,
        .Maddubs   = true
    };

    constexpr inline Target AVX2 {
        .Name      = "AVX2",
        .Bytes     = 32,
        .Registers = 16,
        .Maddubs   = true
    };

    constexpr inline Target AVX512 {
        .Name      = "AVX512",
        .Bytes     = 64,
        .Registers = 32,
        .Maddubs   = true
    };

    constexpr inline Target AVX512VNNI {
        .Name        = "AVX512VNNI",
        .Bytes       = 64,
        .Registers   = 32,
        .DotInFlight = 6,
        .VNNI        = true,
        .Maddubs     = true
    };

    constexpr inline Target NEON {
        .Name      = "NEON",
        .Bytes     = 16,
        .Registers = 32
    };

#if   defined(MANTARAY_FORCE_SCALAR)
    constexpr inline const Target& Native = Scalar;
#elif defined(__AVX512BW__) && defined(__AVX512VNNI__)
    constexpr inline const Target& Native = AVX512VNNI;
#elif defined(__AVX512BW__)
    constexpr inline const Target& Native = AVX512;
#elif defined(__AVX2__)
    constexpr inline const Target& Native = AVX2;
#elif defined(__SSE4_1__)
    constexpr inline const Target& Native = SSE41;
#elif defined(__SSE2__)
    constexpr inline const Target& Native = SSE2;
#elif defined(__ARM_NEON) && defined(__aarch64__)
    constexpr inline const Target& Native = NEON;
#else
    constexpr inline const Target& Native = Scalar;
#endif

}

#endif //MANTARAY_LOWERING_TARGET_H
