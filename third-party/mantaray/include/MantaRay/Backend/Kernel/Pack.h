//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_BACKEND_KERNEL_PACK_H
#define MANTARAY_BACKEND_KERNEL_PACK_H

#include "../../Common.h"

namespace MantaRay::Backend::Kernel
{

    template<typename ISA>
    constexpr Array<u08, ISA::Bytes> PackPermutation() noexcept
    {
        constexpr s00 Half = ISA::Bytes / 2;

        Array<u08, ISA::Bytes> order;

        for (s00 i = 0; i < ISA::Bytes; i++) order[i] = static_cast<u08>(i / 16 * 8 + i % 8 + (i % 16 < 8 ? 0 : Half));

        return order;
    }

    template<typename ISA, bool Packed>
    constexpr s00 LogicalIndex(const s00 position) noexcept
    {
        if (!Packed) return position;

        constexpr Array<u08, ISA::Bytes> Order = PackPermutation<ISA>();

        return position - position % ISA::Bytes + Order[position % ISA::Bytes];
    }

}

#endif //MANTARAY_BACKEND_KERNEL_PACK_H
