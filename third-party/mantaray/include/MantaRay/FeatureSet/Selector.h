//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_FEATURESET_SELECTOR_H
#define MANTARAY_FEATURESET_SELECTOR_H

#include <algorithm>
#include <bit>

#include "../Common.h"

namespace MantaRay
{

    template<u32 N>
    struct MaterialCount
    {

        static_assert(N > 0, "MaterialCount requires at least one bucket");

        constexpr static u32 Count = N;

        constexpr static u32 OfCount(const u08 pieces) noexcept { return (pieces - u32 { 2 }) / ((32 + N - 1) / N); }

        template<typename Board>
        constexpr static u32 Of(const Board& board) noexcept
        {
            return OfCount(static_cast<u08>(std::popcount(board.Occupied())));
        }

    };

    static_assert(sizeof(Array<u08, 33>) == 33, "Array<u08, 33> is a template argument and must have no padding");

    template<Array<u08, 33> Table>
    struct PieceCountTable
    {

        constexpr static Array<u08, 33> Buckets = Table;

        constexpr static u32 Count = std::ranges::max(Buckets) + u32 { 1 };

        constexpr static u32 OfCount(const u08 pieces) noexcept { return Buckets[pieces]; }

        template<typename Board>
        constexpr static u32 Of(const Board& board) noexcept
        {
            return OfCount(static_cast<u08>(std::popcount(board.Occupied())));
        }

    };

}

#endif //MANTARAY_FEATURESET_SELECTOR_H
