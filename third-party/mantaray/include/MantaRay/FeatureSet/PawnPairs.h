//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_FEATURESET_PAWNPAIRS_H
#define MANTARAY_FEATURESET_PAWNPAIRS_H

#include <algorithm>
#include <cassert>

#include "Attacks.h"
#include "Changes.h"
#include "FeatureSet.h"
#include "Geometry.h"
#include "../Common.h"
#include "../Backend/ISA/ISAOf.h"
#include "../Lowering/Choices.h"

namespace MantaRay
{

    enum class PairMask : u08 { ThreeWide, All };

    template<PairMask K = PairMask::ThreeWide>
    struct PawnPairs
    {

        using Trigger = MirrorTrigger;

        constexpr static u32  InputSize  = 96 * 95 / 2;
        constexpr static u32  MaxActive  = K == PairMask::ThreeWide ? 96 : 120;
        constexpr static u32  MaxChanges = 48;
        constexpr static bool Shared     = false;
        constexpr static bool Cached     = false;
        constexpr static bool Derived    = true;
        constexpr static u32  NoRow      = ~u32 { 0 };

        static_assert(
            PieceDelta::MaxRemoved * 15 <= MaxChanges && PieceDelta::MaxInserted * 15 <= MaxChanges,
            "each pawn a delta removes or inserts pairs with at most 15 others (16 pawns) in its list"
        );

        struct Record
        {

            Array<u64, 2> Pawns {};
            Array<u08, 2> Kings {};

            constexpr u64 Pieces(const u08 side, [[maybe_unused]] const Piece piece) const noexcept
            {
                assert(piece == Piece::Pawn);

                return Pawns[side];
            }

            constexpr u08 King(const u08 side) const noexcept { return Kings[side]; }

        };

        struct Change
        {

            u08 FirstSide;
            u08 First;
            u08 SecondSide;
            u08 Second;

        };

        template<typename Board>
        constexpr static Record Capture(const Board& after) noexcept
        {
            return {
                .Pawns = { after.Pieces(White, Piece::Pawn), after.Pieces(Black, Piece::Pawn) },
                .Kings = { after.King(White), after.King(Black) }
            };
        }

        template<typename T = Geometry::Lut>
        constexpr static void Changes(
            const PieceDelta&                   delta,
            const Record&                       after,
                  MantaRay::Changes<PawnPairs>& out
        ) noexcept
        {
            u64 white = 0;
            u64 black = 0;

            const auto toggle = [&](const PieceChange change) {
                if (change.Type != Piece::Pawn) return;

                const u64 bit = u64 { 1 } << change.Square;

                if (change.Side == White) white ^= bit;
                else                      black ^= bit;
            };

            UNROLL(full)
            for (s00 i = 0; i < PieceDelta::MaxRemoved; i++) {
                if (i == delta.RemovedCount()) break;

                toggle(delta.Removed(i));
            }

            UNROLL(full)
            for (s00 i = 0; i < PieceDelta::MaxInserted; i++) {
                if (i == delta.InsertedCount()) break;

                toggle(delta.Inserted(i));
            }

            const u64           touched = white | black;
            const Array<u64, 2> before  { after.Pawns[White] ^ white, after.Pawns[Black] ^ black };

            T::template Pairs<Masks>(before     , touched, Polarity::Remove, out);
            T::template Pairs<Masks>(after.Pawns, touched, Polarity::Add   , out);
        }

        template<Lowering::Tier T>
        constexpr static u32 PairIndex(const u32 first, const u32 second) noexcept
        {
            using Tier = Lowering::Tier;

            static_assert(T == Tier::Lookup || T == Tier::Arithmetic, "a pawn-pair index is Lookup or Arithmetic");

            if constexpr (T == Tier::Lookup) return Pairs[first][second];
            else {
                const u32 high = std::max(first, second);
                const u32 low  = std::min(first, second);

                return high * (high - 1) / 2 + low;
            }
        }

        template<typename ISA = Backend::ISAOf<Lowering::Native>>
        constexpr static u32 Index(const u08 perspective, const u32 key, const Change& change) noexcept
        {
            const u32 first  = Id(perspective, key, change.FirstSide , change.First );
            const u32 second = Id(perspective, key, change.SecondSide, change.Second);

            return PairIndex<PairIndexOf<ISA>>(first, second);
        }

        template<typename ISA = Backend::ISAOf<Lowering::Native>, typename Board, typename Emit>
        constexpr static void Active(const u08 perspective, const Board& board, Emit&& emit) noexcept
        {
            const u32           key   = Trigger::Key(perspective, board);
            const Array<u64, 2> pawns { board.Pieces(White, Piece::Pawn), board.Pieces(Black, Piece::Pawn) };

            const auto side = [&](const u08 square) { return pawns[White] >> square & 1 ? White : Black; };

            Geometry::Partners(pawns, Masks, ~u64 { 0 }, [&](const u08 first, const u08 second) {
                emit(Index<ISA>(perspective, key, {
                    .FirstSide  = side(first ),
                    .First      = first,
                    .SecondSide = side(second),
                    .Second     = second
                }));
            });
        }

        consteval static Array<u64, 64> MasksOf()
        {
            Array<u64, 64> masks {};

            for (s00 square = 0; square < 64; square++) {
                constexpr u64 FileA = 0x0101010101010101;
                constexpr u64 Inner = 0x00FFFFFFFFFFFF00;

                const u08     file  = static_cast<u08>(square & 7);

                u64 mask = K == PairMask::All ? Inner : FileA << file;

                if (K == PairMask::ThreeWide && file > 0) mask |= FileA << (file - 1);
                if (K == PairMask::ThreeWide && file < 7) mask |= FileA << (file + 1);

                masks[square] = mask & Inner & ~(u64 { 1 } << square);
            }

            return masks;
        }

        constexpr static Array<u64, 64> Masks = MasksOf();

        consteval static Array<u16, 96, 96> PairsOf()
        {
            Array<u16, 96, 96> pairs {};

            for (s00 first  = 0; first  < 96; first++)
            for (s00 second = 0; second < 96; second++)
                pairs[first][second] = static_cast<u16>(PairIndex<Lowering::Tier::Arithmetic>(first, second));

            return pairs;
        }

        alignas(Alignment) constexpr static Array<u16, 96, 96> Pairs = PairsOf();

        template<typename ISA>
        constexpr static Lowering::Tier PairIndexOf =
            Lowering::ChoiceOf(Lowering::Choice::PairIndex, Lowering::CapabilitiesOf<ISA>());

        constexpr static u32 Id(const u08 perspective, const u32 key, const u08 side, const u08 square) noexcept
        {
            return 48 * (side != perspective) + ((square ^ (56 * perspective) ^ (7 * key)) - 8);
        }

        constexpr static void Toggle(Array<u64, 2>& pawns, const PieceChange change) noexcept
        {
            if (change.Type == Piece::Pawn) pawns[change.Side] ^= u64 { 1 } << change.Square;
        }

        constexpr static bool Inert(const PieceDelta& delta) noexcept
        {
            for (s00 i = 0; i < delta.RemovedCount(); i++) if (delta.Removed(i).Type == Piece::Pawn) return false;
            for (s00 i = 0; i < delta.InsertedCount(); i++) if (delta.Inserted(i).Type == Piece::Pawn) return false;

            return true;
        }

    };

}

#endif //MANTARAY_FEATURESET_PAWNPAIRS_H
