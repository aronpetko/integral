//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_BACKEND_KERNEL_REDUCE_H
#define MANTARAY_BACKEND_KERNEL_REDUCE_H

#include "../../Common.h"

namespace MantaRay::Backend::Kernel
{

    template<typename ISA, s00 K>
    [[clang::always_inline]]
    i32 ReduceI32(Array<typename ISA::Vector, K> sums) noexcept
    {
        for (s00 width = K; width > 1        ; width = (width + 1) / 2)
        for (s00 i     = 0; i     < width / 2;                     i++)
            sums[i] = ISA::AddI32(sums[i], sums[i + (width + 1) / 2]);

        return ISA::ReduceI32(sums[0]);
    }

    template<typename ISA, s00 K>
    [[clang::always_inline]]
    i64 ReduceI64(const Array<typename ISA::Vector, K>& sums) noexcept
    {
        i64 sum = 0;

        for (const auto& value : sums) sum += ISA::ReduceI64(value);

        return sum;
    }

    template<typename ISA, s00 N>
    [[clang::always_inline]]
    f32 ReduceF(Array<typename ISA::VectorF, N> partials) noexcept
    {
        #pragma clang fp contract(off)

        static_assert(N * ISA::Bytes == 16 * sizeof(f32), "f32 reductions take 16 canonical partial sums");

        for (s00 width = N; width > 1        ; width /= 2)
        for (s00 i     = 0; i     < width / 2;        i++)
            partials[i] = ISA::AddF(partials[i], partials[i + width / 2]);

        return ISA::ReduceF(partials[0]);
    }

}

#endif //MANTARAY_BACKEND_KERNEL_REDUCE_H
