//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_RUNTIME_ACCUMULATORCACHE_H
#define MANTARAY_RUNTIME_ACCUMULATORCACHE_H

#include <cassert>
#include <span>

#include "Delta.h"
#include "../Common.h"
#include "../Backend/Kernel/Update.h"
#include "../FeatureSet/Attacks.h"
#include "../FeatureSet/FeatureSet.h"

namespace MantaRay
{

    namespace Detail
    {

        template<typename F, bool Own = requires { typename F::Snapshot; }>
        struct Snapshots
        {

            using Snapshot = Array<u64, 12>;

            template<typename Board>
            [[nodiscard]]
            constexpr static Snapshot Of(const Board& board) noexcept
            {
                Snapshot snapshot {};

                for (u08 side  = 0; side  < 2; side++ )
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
                for (u08 side  = 0; side  < 2; side++ )
                for (u08 piece = 0; piece < 6; piece++) {
                    const Piece type    = static_cast<Piece>(piece);
                    const u64   cached  = snapshot[side * 6 + piece];
                    const u64   current = board.Pieces(side, type);

                    u64 gone = cached  & ~current;
                    u64 come = current & ~cached ;

                    while (gone)
                        removed(PieceChange { .Type = type, .Side = side, .Square = Attacks::PopLowest(gone) });

                    while (come)
                        added  (PieceChange { .Type = type, .Side = side, .Square = Attacks::PopLowest(come) });
                }
            }

        };

        template<typename F>
        struct Snapshots<F, true>
        {

            using Snapshot = F::Snapshot;

            template<typename Board>
            [[nodiscard]]
            constexpr static Snapshot Of(const Board& board) noexcept { return F::SnapshotOf(board); }

            template<typename Board, typename Removed, typename Added>
            constexpr static void Diff(
                const Snapshot& snapshot,
                const Board&    board   ,
                      Removed&& removed ,
                      Added&&   added
            ) noexcept
            { F::Diff(snapshot, board, removed, added); }

        };

    }

    template<typename F, typename S, typename W, u32 Width, u08 Sets, typename ISA>
    class AccumulatorCache
    {

        using P = Detail::Snapshots<F>;

        constexpr static u32 Keys = F::Trigger::KeyCount;

        struct Entry
        {

            alignas(Alignment) Array<S, Width> Values;

            P::Snapshot Pieces;

            u64 Generation;

        };

        Array<Entry, Sets, 2, Keys> Entries {};

        static void Reset(Entry& entry, const S* bias, const u64 generation) noexcept
        {
            Backend::Kernel::Copy<ISA, Width>(bias, entry.Values.data());

            entry.Pieces     = {};
            entry.Generation = generation;
        }

        [[clang::noinline]]
        static void Flush(
                  Entry&                    entry   ,
            const std::span<const W* const> removed ,
            const std::span<const W* const> inserted
        ) noexcept
        { Backend::Kernel::Update<ISA, Width, S, W>(entry.Values.data(), removed, inserted, entry.Values.data()); }

        public:
        template<typename N>
        void Clear(const N& network) noexcept
        {
            for (s00 set         = 0; set         < Sets; set++        )
            for (u08 perspective = 0; perspective < 2   ; perspective++)
            for (Entry& entry : Entries[set][perspective])
                Reset(entry, network.FeatureBias(set), network.Generation());
        }

        template<typename N, typename Board>
        void Refresh(
            const N&               network    ,
            const u08              set        ,
            const u08              perspective,
            const u32              key        ,
            const Board&           board      ,
                  Array<S, Width>& destination
        ) noexcept
        {
            assert(set < Sets && perspective < 2 && key < Keys);

            Entry& entry = Entries[set][perspective][key];

            if (entry.Generation != network.Generation()) Reset(entry, network.FeatureBias(set), network.Generation());

            Array<const W*, F::MaxActive> removed ;
            Array<const W*, F::MaxActive> inserted;

            u32 removals   = 0;
            u32 insertions = 0;

            P::Diff(
                entry.Pieces,
                board,
                [&](const PieceChange& change) {
                    if (removals == F::MaxActive) {
                        Flush(entry, std::span(removed).first(removals), {});

                        removals = 0;
                    }

                    removed [removals  ++] = network.FeatureRow(set, F::Index(perspective, key, change));
                },
                [&](const PieceChange& change) {
                    if (insertions == F::MaxActive) {
                        Flush(entry, {}, std::span(inserted).first(insertions));

                        insertions = 0;
                    }

                    inserted[insertions++] = network.FeatureRow(set, F::Index(perspective, key, change));
                }
            );

            entry.Pieces = P::Of(board);

            Backend::Kernel::Update<ISA, Width, S, W>(
                entry.Values.data(),
                std::span(removed ).first(removals  ),
                std::span(inserted).first(insertions),
                destination.data(),
                entry.Values.data()
            );
        }

    };

}

#endif //MANTARAY_RUNTIME_ACCUMULATORCACHE_H
