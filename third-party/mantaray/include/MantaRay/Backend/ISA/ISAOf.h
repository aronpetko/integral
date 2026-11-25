//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_BACKEND_ISA_ISAOF_H
#define MANTARAY_BACKEND_ISA_ISAOF_H

#include "AVX2.h"
#include "AVX512.h"
#include "AVX512VNNI.h"
#include "NEON.h"
#include "Scalar.h"
#include "SSE2.h"
#include "SSE41.h"
#include "../../Lowering/Target.h"

namespace MantaRay::Backend
{

    namespace Detail
    {

        template<const Lowering::Target& T>
        struct ISAOf;

        template<>
        struct ISAOf<Lowering::Scalar> { using Type = ISA::Scalar; };

#if defined(__SSE2__)
        template<>
        struct ISAOf<Lowering::SSE2> { using Type = ISA::SSE2; };
#endif

#if defined(__SSE4_1__)
        template<>
        struct ISAOf<Lowering::SSE41> { using Type = ISA::SSE41; };
#endif

#if defined(__AVX2__)
        template<>
        struct ISAOf<Lowering::AVX2> { using Type = ISA::AVX2; };
#endif

#if defined(__AVX512BW__)
        template<>
        struct ISAOf<Lowering::AVX512> { using Type = ISA::AVX512; };
#endif

#if defined(__AVX512BW__) && defined(__AVX512VNNI__)
        template<>
        struct ISAOf<Lowering::AVX512VNNI> { using Type = ISA::AVX512VNNI; };
#endif

#if defined(__ARM_NEON) && defined(__aarch64__)
        template<>
        struct ISAOf<Lowering::NEON> { using Type = ISA::NEON; };
#endif

    }

    template<const Lowering::Target& T>
    using ISAOf = Detail::ISAOf<T>::Type;

}

#endif //MANTARAY_BACKEND_ISA_ISAOF_H
