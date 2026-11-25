//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_FEATURESET_KINGBUCKETS_H
#define MANTARAY_FEATURESET_KINGBUCKETS_H

#include <algorithm>

#include "Attacks.h"
#include "Changes.h"
#include "FeatureSet.h"
#include "../Common.h"

namespace MantaRay
{

    struct BucketLayout
    {

        Array<u08, 64> Buckets {};

        bool Mirrored    = false;
        bool MergedKings = false;

    };

    static_assert(sizeof(BucketLayout) == 66, "BucketLayout is a template argument and must have no padding");

    constexpr BucketLayout Mirrored(const Array<u08, 32>& half, const bool mergedKings = false)
    {
        constexpr Array<u08, 8> Files { 0, 1, 2, 3, 3, 2, 1, 0 };

        BucketLayout layout { .Mirrored = true, .MergedKings = mergedKings };

        for (s00 square = 0; square < 64; square++) layout.Buckets[square] = half[square / 8 * 4 + Files[square % 8]];

        return layout;
    }

    constexpr BucketLayout Unmirrored(const Array<u08, 64>& full) { return { .Buckets = full }; }

    template<BucketLayout L>
    struct KingBucketTrigger
    {

        constexpr static BucketLayout Layout = L;

        constexpr static u32 Buckets  = std::ranges::max(Layout.Buckets) + u32 { 1 };
        constexpr static u32 KeyCount = Buckets * (Layout.Mirrored ? 2 : 1);

        constexpr static u32 KeyOf(const u08 perspective, const u08 king) noexcept
        {
            const u32 bucket = Layout.Buckets[king ^ (56 * perspective)];

            return Layout.Mirrored ? bucket * 2 + ((king & 7) >= 4) : bucket;
        }

        template<typename Board>
        constexpr static u32 Key(const u08 perspective, const Board& board) noexcept
        {
            return KeyOf(perspective, board.King(perspective));
        }

    };

    template<BucketLayout L>
    struct KingBuckets
    {

        using Trigger  = KingBucketTrigger<L>;
        using Change   = PieceChange;
        using Snapshot = Array<u64, 12>;

        constexpr static BucketLayout Layout = L;

        constexpr static u32 Width = Layout.MergedKings ? 704 : 768;

        constexpr static u32  InputSize  = Width * Trigger::Buckets;
        constexpr static u32  MaxActive  = 32;
        constexpr static u32  MaxChanges = 4;
        constexpr static bool Shared     = false;
        constexpr static bool Cached     = true;

        constexpr static u32 Index(const u08 perspective, const u32 key, const PieceChange& change) noexcept
        {
            const u32 bucket = Layout.Mirrored ? key / 2 : key;
            const u32 flip   = 56 * perspective ^ (Layout.Mirrored && key % 2 ? 7 : 0);
            const u32 code   = static_cast<u32>(change.Side) << 9 | static_cast<u32>(change.Type) << 6 | change.Square;
            const u32 side   = Layout.MergedKings && change.Type == Piece::King ? 0 : (code >> 9) ^ perspective;

            return Width * bucket + 384 * side + ((code & 511) ^ flip);
        }

        constexpr static u32 IndexLean(const u08 perspective, const u32 key, const PieceChange& change) noexcept
        {
            const u32 bucket = Layout.Mirrored ? key / 2 : key;
            const u32 flip   = 56 * perspective ^ (Layout.Mirrored && key % 2 ? 7 : 0);
            const u32 code   = static_cast<u32>(change.Side) << 9 | static_cast<u32>(change.Type) << 6 | change.Square;
            const u32 viewed = code ^ static_cast<u32>(perspective) << 9 ^ flip;

            if (Layout.MergedKings && change.Type == Piece::King) return Width * bucket + (viewed & 511);

            return Width * bucket + viewed - (viewed >> 2 & 128);
        }

        template<typename Board, typename Emit>
        constexpr static void Active(const u08 perspective, const Board& board, Emit&& emit) noexcept
        {
            const u32 key = Trigger::Key(perspective, board);

            for (u08 side  = 0; side  < 2; side++)
            for (u08 piece = 0; piece < 6; piece++) {
                const Piece type = static_cast<Piece>(piece);

                u64 bits = board.Pieces(side, type);

                while (bits)
                    emit(Index(perspective, key, { .Type = type, .Side = side, .Square = Attacks::PopLowest(bits) }));
            }
        }

        template<typename Board>
        constexpr static Snapshot SnapshotOf(const Board& board) noexcept
        {
            Snapshot snapshot {};

            for (u08 side  = 0; side  < 2; side++)
            for (u08 piece = 0; piece < 6; piece++)
                snapshot[side * 6 + piece] = board.Pieces(side, static_cast<Piece>(piece));

            return snapshot;
        }

        template<typename Board, typename Removed, typename Added>
        constexpr static void Diff(
            const Snapshot& snapshot,
            const Board&    board   ,
                  Removed&& removed ,
                  Added&&   added
        ) noexcept
        {
            for (u08 side  = 0; side  < 2; side++)
            for (u08 piece = 0; piece < 6; piece++) {
                const Piece type    = static_cast<Piece>(piece);
                const u64   cached  = snapshot[side * 6 + piece];
                const u64   current = board.Pieces(side, type);

                u64 gone = cached  & ~current;
                u64 come = current & ~cached ;

                while (gone) removed(PieceChange { .Type = type, .Side = side, .Square = Attacks::PopLowest(gone) });
                while (come) added  (PieceChange { .Type = type, .Side = side, .Square = Attacks::PopLowest(come) });
            }
        }

    };

}

#endif //MANTARAY_FEATURESET_KINGBUCKETS_H
