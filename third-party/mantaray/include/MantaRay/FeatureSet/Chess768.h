//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_FEATURESET_CHESS768_H
#define MANTARAY_FEATURESET_CHESS768_H

#include "Attacks.h"
#include "Changes.h"
#include "FeatureSet.h"
#include "../Common.h"

namespace MantaRay
{

    struct Chess768
    {

        using Trigger = NoTrigger;
        using Change  = PieceChange;

        constexpr static u32  InputSize  = 768;
        constexpr static u32  MaxActive  = 32;
        constexpr static u32  MaxChanges = 4;
        constexpr static bool Shared     = false;
        constexpr static bool Cached     = false;

        constexpr static u32 Index(const u08 perspective, const u32, const PieceChange& change) noexcept
        {
            const u32 code = static_cast<u32>(change.Side) << 9 | static_cast<u32>(change.Type) << 6 | change.Square;

            return 384 * ((code >> 9) ^ perspective) + ((code & 511) ^ (56 * perspective));
        }

        constexpr static u32 IndexCode(const u08 perspective, const u32, const u16 code) noexcept
        {
            const u32 side   = (code >>  9) ^       perspective ;
            const u32 piece  = (code >>  6) &   7               ;
            const u32 square = (code &  63) ^ (56 * perspective);

            return side * 384 + piece * 64 + square;
        }

        constexpr static u32 IndexLean(const u08 perspective, const u32, const PieceChange& change) noexcept
        {
            const u32 code   = static_cast<u32>(change.Side) << 9 | static_cast<u32>(change.Type) << 6 | change.Square;
            const u32 viewed = code ^ static_cast<u32>(perspective) * (512 | 56);

            return viewed - (viewed >> 2 & 128);
        }

        template<typename Board, typename Emit>
        constexpr static void Active(const u08 perspective, const Board& board, Emit&& emit) noexcept
        {
            for (u08 side  = 0; side  < 2; side++)
            for (u08 piece = 0; piece < 6; piece++) {
                const Piece type = static_cast<Piece>(piece);

                u64 bits = board.Pieces(side, type);

                while (bits)
                    emit(Index(perspective, 0, { .Type = type, .Side = side, .Square = Attacks::PopLowest(bits) }));
            }
        }

    };

}

#endif //MANTARAY_FEATURESET_CHESS768_H
