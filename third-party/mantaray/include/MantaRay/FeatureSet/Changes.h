//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_FEATURESET_CHANGES_H
#define MANTARAY_FEATURESET_CHANGES_H

#include <cassert>
#include <span>

#include "FeatureSet.h"
#include "../Common.h"

namespace MantaRay
{

    struct PieceChange
    {

        Piece Type   = Piece::Pawn;
        u08   Side   = White;
        u08   Square = 0;

    };

    class PieceDelta
    {

        constexpr static s00 CodeBits = 10;
        constexpr static u64 CodeMask = (u64 { 1 } << CodeBits) - 1;

        constexpr static s00   RemovalShift = 4 * CodeBits;
        constexpr static s00 InsertionShift = RemovalShift + 2;

        constexpr static s00 ShapeShift = 48;
        constexpr static s00 ShapeBits  =  4;

        static_assert(InsertionShift + 2 <= ShapeShift, "the two counters precede the shape" );
        static_assert(ShapeShift + ShapeBits <= 64   , "the shape (at most 8) fits the word");

        u64 Word = 0;

        [[nodiscard]]
        constexpr static u08 ShapeOf(const u08 removals, const u08 insertions) noexcept
        { return static_cast<u08>(removals * 3 + insertions); }

        [[nodiscard]]
        constexpr static u16 CodeOf(const Piece piece, const u08 side, const u08 square) noexcept
        { return static_cast<u16>(side << 9 | static_cast<u08>(piece) << 6 | square); }

        [[nodiscard]]
        constexpr PieceChange ChangeAt(const s00 slot) const noexcept
        {
            static_assert(CodeOf(Piece::King, Black, 63) <= CodeMask, "every piece code fits a code slot");
            static_assert(
                (MaxRemoved + MaxInserted) * CodeBits <= RemovalShift && MaxRemoved < 4 && MaxInserted < 4,
                "every removal and insertion has a code slot, and each count fits its 2-bit counter"
            );

            const u64 code = Word >> CodeBits * slot & CodeMask;

            return {
                .Type   = static_cast<Piece>(code >> 6 & 7),
                .Side   = static_cast<u08>(code >> 9 & 1),
                .Square = static_cast<u08>(code & 63)
            };
        }

        public:
        constexpr static u08 MaxRemoved  = 2;
        constexpr static u08 MaxInserted = 2;

        constexpr void Remove(const Piece piece, const u08 side, const u08 square) noexcept
        {
            assert(RemovedCount() < MaxRemoved && piece <= Piece::King && side < 2 && square < 64);

            Word += (u64 { CodeOf(piece, side, square) } << CodeBits * RemovedCount()) +
                    (u64 { 1 } <<   RemovalShift) + (u64 { ShapeOf(1, 0) } << ShapeShift);
        }

        constexpr void Insert(const Piece piece, const u08 side, const u08 square) noexcept
        {
            assert(InsertedCount() < MaxInserted && piece <= Piece::King && side < 2 && square < 64);

            Word += (u64 { CodeOf(piece, side, square) } << CodeBits * (MaxRemoved + InsertedCount())) +
                    (u64 { 1 } << InsertionShift) + (u64 { ShapeOf(0, 1) } << ShapeShift);
        }

        constexpr void Move(const Piece piece, const u08 side, const u08 from, const u08 to) noexcept
        {
            Remove(piece, side, from);
            Insert(piece, side, to  );
        }

        [[nodiscard]]
        constexpr u08  RemovedCount() const noexcept { return static_cast<u08>(Word >>   RemovalShift & 3); }
        [[nodiscard]]
        constexpr u08 InsertedCount() const noexcept { return static_cast<u08>(Word >> InsertionShift & 3); }

        [[nodiscard]]
        constexpr u08 Shape() const noexcept
        {
            static_assert(ShapeOf(MaxRemoved, MaxInserted) < 1 << ShapeBits, "ShapeBits must hold every shape");

            return static_cast<u08>(Word >> ShapeShift);
        }

        [[nodiscard]]
        constexpr u32 ShapeIndex() const noexcept
        {
            return static_cast<u32>(Word >> ShapeShift);
        }

        [[nodiscard]]
        constexpr u16  RemovedCode(const s00 i) const noexcept
        {
            assert(i <  RemovedCount());

            return static_cast<u16>(Word >> CodeBits *               i  & CodeMask);
        }

        [[nodiscard]]
        constexpr u16 InsertedCode(const s00 i) const noexcept
        {
            assert(i < InsertedCount());

            return static_cast<u16>(Word >> CodeBits * (MaxRemoved + i) & CodeMask);
        }

        [[nodiscard]]
        constexpr PieceChange  Removed(const s00 i) const noexcept
        {
            assert(i <  RemovedCount());

            return ChangeAt(             i);
        }

        [[nodiscard]]
        constexpr PieceChange Inserted(const s00 i) const noexcept
        {
            assert(i < InsertedCount());

            return ChangeAt(MaxRemoved + i);
        }

    };

    enum class Polarity : u08 { Add, Remove };

    constexpr Polarity Opposite(const Polarity polarity) noexcept
    { return polarity == Polarity::Add ? Polarity::Remove : Polarity::Add; }

    namespace Detail
    {

        constexpr inline u32 Slack = 16;

    }

    template<typename F>
    class Changes
    {

        static_assert(FeatureSet<F>, "changes are kept for a feature family");

        Array<typename F::Change, F::MaxChanges + Detail::Slack> Additions;
        Array<typename F::Change, F::MaxChanges + Detail::Slack> Removals ;

        u32 AdditionCount = 0;
        u32 RemovalCount  = 0;

        public:
        using Change = F::Change;

        constexpr static u32 Slack = Detail::Slack;

        constexpr Changes() noexcept {}

        constexpr void Add(const typename F::Change change) noexcept
        {
            assert(AdditionCount < F::MaxChanges);

            Additions[AdditionCount++] = change;
        }

        constexpr void Remove(const typename F::Change change) noexcept
        {
            assert(RemovalCount < F::MaxChanges);

            Removals[RemovalCount++] = change;
        }

        [[nodiscard]]
        constexpr u32 Count(const Polarity list) const noexcept
        { return list == Polarity::Add ? AdditionCount : RemovalCount; }

        [[nodiscard]]
        constexpr typename F::Change* Tail(const Polarity list) noexcept
        { return list == Polarity::Add ? Additions.data() + AdditionCount : Removals.data() + RemovalCount; }

        constexpr void Advance(const Polarity list, const u32 count) noexcept
        {
            u32& total = list == Polarity::Add ? AdditionCount : RemovalCount;

            assert(total + count <= F::MaxChanges);

            total += count;
        }

        constexpr void Clear() noexcept
        {
            AdditionCount = 0;
            RemovalCount  = 0;
        }

        [[nodiscard]]
        constexpr std::span<const typename F::Change> Added  () const noexcept
        { return std::span(Additions).first(AdditionCount); }
        [[nodiscard]]
        constexpr std::span<const typename F::Change> Removed() const noexcept
        { return std::span(Removals).first(RemovalCount); }

    };

}

#endif //MANTARAY_FEATURESET_CHANGES_H
