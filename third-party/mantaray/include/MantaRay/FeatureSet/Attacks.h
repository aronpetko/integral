//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_FEATURESET_ATTACKS_H
#define MANTARAY_FEATURESET_ATTACKS_H

#include <array>
#include <bit>
#include <utility>

#include "FeatureSet.h"
#include "../Common.h"

namespace MantaRay::Attacks
{

    constexpr inline Array<i32, 8, 2> Directions {
        { { 1, 0 }, { 1, 1 }, { 0, 1 }, { -1, 1 }, { -1, 0 }, { -1, -1 }, { 0, -1 }, { 1, -1 } }
    };

    namespace Detail
    {

        constexpr inline Array<i32, 8, 2> Knight {
            { { 1, 2 }, { 2, 1 }, { 2, -1 }, { 1, -2 }, { -1, -2 }, { -2, -1 }, { -2, 1 }, { -1, 2 } }
        };

        constexpr inline Array<i32, 4, 2> Bishop { { { 1, 1 }, { 1, -1 }, { -1, 1 }, { -1, -1 } } };
        constexpr inline Array<i32, 4, 2> Rook   { { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } } };

        constexpr u64 Walk(
            const u08  square  ,
            const i32  fileStep,
            const i32  rankStep,
            const u64  occupied,
            const bool ray
        ) noexcept
        {
            u64 result = 0;

            i32 file = square % 8 + fileStep;
            i32 rank = square / 8 + rankStep;

            while (file >= 0 && file < 8 && rank >= 0 && rank < 8) {
                const u64 bit = u64 { 1 } << (rank * 8 + file);

                result |= bit;

                if (!ray || (occupied & bit)) break;

                file += fileStep;
                rank += rankStep;
            }

            return result;
        }

        template<s00 N>
        constexpr u64 Steps(
            const u08                                square  ,
            const std::array<std::array<i32, 2>, N>& steps   ,
            const u64                                occupied,
            const bool                               ray
        ) noexcept
        {
            u64 result = 0;

            for (s00 i = 0; i < N; i++) result |= Walk(square, steps[i][0], steps[i][1], occupied, ray);

            return result;
        }

        constexpr u64 Walked(const u08 side, const Piece piece, const u08 square, const u64 occupied) noexcept
        {
            const i32 forward = side == White ? 1 : -1;

            switch (piece) {
                case Piece::Pawn  : return Walk(square,  1, forward, 0, false) |
                                           Walk(square, -1, forward, 0, false);
                case Piece::Knight: return Steps(square, Knight    , 0       , false);
                case Piece::Bishop: return Steps(square, Bishop    , occupied, true );
                case Piece::Rook  : return Steps(square, Rook      , occupied, true );
                case Piece::Queen : return Steps(square, Directions, occupied, true );
                case Piece::King  : return Steps(square, Directions, 0       , false);
            }

            std::unreachable();
        }

        consteval Array<u64, 8, 64> RaysOf()
        {
            Array<u64, 8, 64> rays {};

            for (s00 direction = 0; direction < 8; direction++)
            for (s00 square    = 0; square    < 64; square++)
                rays[direction][square] = Walk(square, Directions[direction][0], Directions[direction][1], 0, true);

            return rays;
        }

        consteval Array<u64, 64> LeapsOf(const u08 side, const Piece piece)
        {
            Array<u64, 64> leaps {};

            for (s00 square = 0; square < 64; square++) leaps[square] = Walked(side, piece, square, 0);

            return leaps;
        }

        consteval Array<u64, 2, 64> PawnsOf() { return { LeapsOf(White, Piece::Pawn), LeapsOf(Black, Piece::Pawn) }; }

    }

    constexpr inline Array<u64, 8, 64> Rays    = Detail::RaysOf ();
    constexpr inline Array<u64, 2, 64> Pawns   = Detail::PawnsOf();
    constexpr inline Array<u64, 64>    Knights = Detail::LeapsOf(White, Piece::Knight);
    constexpr inline Array<u64, 64>    Kings   = Detail::LeapsOf(White, Piece::King  );

    namespace Detail
    {

        consteval bool Ascending(const u08 direction)
        {
            return Directions[direction][1] * 8 + Directions[direction][0] > 0;
        }

        consteval bool Sentinels()
        {
            for (s00 direction = 0; direction < 8; direction++) {
                const u08 edge = direction < 4 ? 63 : 0;

                if (Ascending(direction) != (direction < 4) || Rays[direction][edge] != 0) return false;
            }

            return true;
        }

        static_assert(Sentinels(), "directions 0-3 ascend, 4-7 descend, and each ends at square 63 or 0");

        constexpr u64 Slide(const u08 square, const u08 direction, const u64 occupied) noexcept
        {
            const u64 ray     = Rays[direction][square];
            const u64 blocked = ray & occupied;
            const u08 first   = direction < 4 ? static_cast<u08>(std::countr_zero(blocked | u64 { 1 } << 63))
                                              : static_cast<u08>(63 - std::countl_zero(blocked | 1));

            return ray ^ Rays[direction][first];
        }

    }

    constexpr u64 Of(const u08 side, const Piece piece, const u08 square, const u64 occupied) noexcept
    {
        if consteval { return Detail::Walked(side, piece, square, occupied); }

        const auto line  = [&] {
            return Detail::Slide(square, 0, occupied) | Detail::Slide(square, 2, occupied) |
                   Detail::Slide(square, 4, occupied) | Detail::Slide(square, 6, occupied);
        };
        const auto slant = [&] {
            return Detail::Slide(square, 1, occupied) | Detail::Slide(square, 3, occupied) |
                   Detail::Slide(square, 5, occupied) | Detail::Slide(square, 7, occupied);
        };

        switch (piece) {
            case Piece::Pawn  : return Pawns[side][square];
            case Piece::Knight: return Knights[square];
            case Piece::Bishop: return slant();
            case Piece::Rook  : return line ();
            case Piece::Queen : return line () | slant();
            case Piece::King  : return Kings[square];
        }

        std::unreachable();
    }

    constexpr u64 Empty(const u08 side, const Piece piece, const u08 square) noexcept
    { return Of(side, piece, square, 0); }

    constexpr u64 Ray(const u08 square, const u08 direction, const u64 occupied) noexcept
    {
        if consteval {
            return Detail::Walk(square, Directions[direction][0], Directions[direction][1], occupied, true);
        }

        return Detail::Slide(square, direction, occupied);
    }

    constexpr u08 PopLowest(u64& bits) noexcept
    {
        const u08 square = static_cast<u08>(std::countr_zero(bits));

        bits &= bits - 1;

        return square;
    }

}

#endif //MANTARAY_FEATURESET_ATTACKS_H
