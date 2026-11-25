//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_FEATURESET_THREATS_H
#define MANTARAY_FEATURESET_THREATS_H

#include <bit>
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

    struct ThreatMap
    {

        Array<i08, 6, 6> Targets {};

    };

    static_assert(sizeof(ThreatMap) == 36, "ThreatMap is a template argument and must have no padding");

    constexpr inline ThreatMap TI59808 { { {
        { -1,  0, -1,  1, -1, -1 },
        {  0,  1,  2,  3,  4, -1 },
        {  0,  1,  2,  3, -1, -1 },
        {  0,  1,  2,  3, -1, -1 },
        {  0,  1,  2,  3,  4, -1 },
        { -1, -1, -1, -1, -1, -1 }
    } } };

    constexpr inline ThreatMap TI60144 { { {
        {  0,  1, -1,  2, -1, -1 },
        {  0,  1,  2,  3,  4, -1 },
        {  0,  1,  2,  3, -1, -1 },
        {  0,  1,  2,  3, -1, -1 },
        {  0,  1,  2,  3,  4, -1 },
        { -1, -1, -1, -1, -1, -1 }
    } } };

    constexpr inline ThreatMap TI66864 { { {
        {  0,  1, -1,  2, -1, -1 },
        {  0,  1,  2,  3,  4, -1 },
        {  0,  1,  2,  3, -1, -1 },
        {  0,  1,  2,  3, -1, -1 },
        {  0,  1,  2,  3,  4, -1 },
        {  0,  1,  2,  3, -1, -1 }
    } } };

    template<ThreatMap M>
    struct Threats
    {

        using Trigger = MirrorTrigger;

        constexpr static bool Derived = true;
        constexpr static u32  NoRow   = ~u32 { 0 };

        struct Tables
        {

            u32 Dimensions = 0;

            Array<u32, 12, 12, 2> Pairs   {};
            Array<u32, 12, 64   > Offsets {};
            Array<u64, 12, 64   > Pseudo  {};

        };

        consteval static Tables Build()
        {
            Tables tables {};

            Array<u32, 6> targets {};

            for (s00 attacker = 0; attacker < 6; attacker++)
            for (s00 victim   = 0; victim   < 6; victim++)
                targets[attacker] += M.Targets[attacker][victim] >= 0 ? 2 : 0;

            Array<u32, 12> base {};
            Array<u32, 12> per  {};

            for (s00 piece = 0; piece < 12; piece++) {
                const bool pawn = piece % 6 == 0;

                u32 run = 0;

                for (s00 square = 0; square < 64; square++) {
                    const u64 pseudo = Attacks::Empty(piece / 6, static_cast<Piece>(piece % 6), square);

                    tables.Offsets[piece][square] = run;
                    tables.Pseudo [piece][square] = pseudo;

                    if (!pawn || (square >= 8 && square < 56)) run += static_cast<u32>(std::popcount(pseudo));
                }

                per [piece] = run;
                base[piece] = tables.Dimensions;

                tables.Dimensions += targets[piece % 6] * run;
            }

            for (s00 attacker = 0; attacker < 12; attacker++)
            for (s00 victim   = 0; victim   < 12; victim++) {
                const i32  slot    = M.Targets[attacker % 6][victim % 6];
                const u32  side    = static_cast<u32>(victim / 6 * (targets[attacker % 6] / 2));
                const u32  feature = base[attacker] + (side + slot) * per[attacker];
                const bool semi    = attacker % 6 == victim % 6 && (attacker / 6 != victim / 6 || attacker % 6 != 0);

                tables.Pairs[attacker][victim][0] = slot < 0         ? NoRow : feature;
                tables.Pairs[attacker][victim][1] = slot < 0 || semi ? NoRow : feature;
            }

            return tables;
        }

        constexpr static Tables Table = Build();

        constexpr static Geometry::Tables Shape = Geometry::Build(M.Targets);

        consteval static Array<u08, 2, 12> FlipsOf()
        {
            Array<u08, 2, 12> flips {};

            for (s00 perspective = 0; perspective < 2 ; perspective++)
            for (s00 code        = 0; code        < 12; code++)
                flips[perspective][code] = static_cast<u08>(Flip<Lowering::Tier::Modulo>(perspective, code));

            return flips;
        }

        consteval static Array<u08, 12, 64, 64> OrdinalsOf()
        {
            Array<u08, 12, 64, 64> ordinals {};

            for (s00 piece = 0; piece < 12; piece++)
            for (s00 from  = 0; from  < 64; from++) {
                const u64 pseudo = Table.Pseudo[piece][from];

                u64 count = 0;

                for (s00 to = 0; to < 64; to++) {
                    ordinals[piece][from][to] = static_cast<u08>(count);

                    count += pseudo >> to & 1;
                }
            }

            return ordinals;
        }

        consteval static Array<u08, 64> SquaresOf()
        {
            Array<u08, 64> squares {};

            for (s00 square = 0; square < 64; square++) squares[square] = static_cast<u08>(square);

            return squares;
        }

        alignas(Alignment) constexpr static Array<u08,  2, 12    > Flips    = FlipsOf   ();
        alignas(Alignment) constexpr static Array<u08, 12, 64, 64> Ordinals = OrdinalsOf();
        alignas(Alignment) constexpr static Array<u08, 64        > Squares  = SquaresOf ();

        consteval static Array<u64, 2, 2, 64> BelowOf()
        {
            Array<u64, 2, 2, 64> below {};

            for (s00 perspective = 0; perspective < 2 ; perspective++)
            for (s00 key         = 0; key         < 2 ; key++        )
            for (s00 from        = 0; from        < 64; from++       ) {
                const s00 orient = 56 * perspective ^ 7 * key;

                for (s00 to = 0; to < 64; to++)
                    if ((to ^ orient) < (from ^ orient)) below[perspective][key][from] |= u64 { 1 } << to;
            }

            return below;
        }

        alignas(Alignment) constexpr static Array<u64, 2, 2, 64> Below = BelowOf();

        template<typename ISA>
        constexpr static Lowering::Tier FlipOf =
            Lowering::ChoiceOf(Lowering::Choice::Flip   , Lowering::CapabilitiesOf<ISA>());

        template<typename ISA>
        constexpr static Lowering::Tier OrdinalOf =
            Lowering::ChoiceOf(Lowering::Choice::Ordinal, Lowering::CapabilitiesOf<ISA>());

        constexpr static u32  InputSize      = Table.Dimensions;
        constexpr static u32  MaxActive      = 256;
        constexpr static u32  MaxChanges     = 256;
        constexpr static u32  TypicalChanges =  80;
        constexpr static bool Shared         = false;
        constexpr static bool Cached         = false;

        static_assert(PieceDelta::MaxRemoved  * Geometry::MaxFocus + PieceDelta::MaxInserted * Geometry::MaxXrays <=
                      MaxChanges,
                      "the removals take a focus set per removed piece and an x-ray set per inserted piece");
        static_assert(PieceDelta::MaxInserted * Geometry::MaxFocus + PieceDelta::MaxRemoved  * Geometry::MaxXrays <=
                      MaxChanges,
                      "the additions take a focus set per inserted piece and an x-ray set per removed piece");

        struct Record
        {

            alignas(Alignment) Array<u08, 64> Codes {};

            constexpr u64 Pieces(const u08 side, const Piece piece) const noexcept
            {
                const u08 code = static_cast<u08>(side * 6 + static_cast<u08>(piece));

                u64 pieces = 0;

                for (u08 square = 0; square < 64; square++) pieces |= u64 { Codes[square] == code } << square;

                return pieces;
            }

            constexpr u64 Occupied() const noexcept
            {
                u64 occupied = 0;

                for (u08 square = 0; square < 64; square++)
                    occupied |= u64 { Codes[square] != Geometry::Empty } << square;

                return occupied;
            }

            constexpr u08 King(const u08 side) const noexcept
            { return static_cast<u08>(std::countr_zero(Pieces(side, Piece::King))); }

            constexpr u08 At(const u08 square) const noexcept { return Codes[square]; }

            constexpr bool operator ==(const Record&) const noexcept = default;

        };

        static_assert(sizeof(Record) == 64 && alignof(Record) == 64, "the record is one 64-byte mailbox");

        struct Change
        {

            u08 Attacker;
            u08 From;
            u08 Attacked;
            u08 To;

        };

        template<typename Board>
        constexpr static Record Capture(const Board& after) noexcept
        {
            Record record {};

            for (u08 square = 0; square < 64; square++) record.Codes[square] = after.At(square);

            return record;
        }

        constexpr static Record Next(const Record& parent, const PieceDelta& delta) noexcept
        {
            if consteval {
                Record record = parent;

                for (s00 i = 0; i < delta.RemovedCount (); i++) record.Codes[delta.Removed(i).Square] = Geometry::Empty;

                for (s00 i = 0; i < delta.InsertedCount(); i++) {
                    const PieceChange change = delta.Inserted(i);

                    record.Codes[change.Square] = Geometry::CodeOf(change);
                }

                return record;
            }

            using ISA = Backend::ISAOf<Lowering::Native>;

            constexpr s00 Chunks = 64 / ISA::Bytes;

            Array<typename ISA::Vector, Chunks> codes;

            for (s00 chunk = 0; chunk < Chunks; chunk++) codes[chunk] = ISA::Load(parent.Codes, chunk * ISA::Bytes);

            const auto put = [&](const u08 square, const u08 code) {
                for (s00 chunk = 0; chunk < Chunks; chunk++)
                    codes[chunk] = ISA::PutU08(codes[chunk], ISA::Load(Squares, chunk * ISA::Bytes), square, code);
            };

            for (s00 i = 0; i < delta.RemovedCount (); i++) put(delta.Removed(i).Square, Geometry::Empty);

            for (s00 i = 0; i < delta.InsertedCount(); i++) {
                const PieceChange change = delta.Inserted(i);

                put(change.Square, Geometry::CodeOf(change));
            }

            Record record;

            for (s00 chunk = 0; chunk < Chunks; chunk++) ISA::Store(record.Codes, chunk * ISA::Bytes, codes[chunk]);

            return record;
        }

        struct Pairing
        {

            constexpr static u08 None = 2;

            Array<u08, 2> Mates { None, None };

            u08 Taken = 0;

        };

        constexpr static Pairing Pair(const PieceDelta& delta) noexcept
        {
            Pairing pairing {};

            const auto pair = [&](const auto& match) {
                for (s00 r = 0; r < delta.RemovedCount (); r++)
                for (s00 i = 0; i < delta.InsertedCount(); i++) {
                    const bool free = pairing.Mates[r] == Pairing::None && (pairing.Taken >> i & 1) == 0;

                    if (!free || !match(delta.Removed(r), delta.Inserted(i))) continue;

                    pairing.Mates[r]  = static_cast<u08>(i);
                    pairing.Taken    |= static_cast<u08>(1 << i);
                }
            };

            pair([](const PieceChange removal, const PieceChange insertion) {
                return removal.Square == insertion.Square;
            });

            pair([](const PieceChange removal, const PieceChange insertion) {
                return removal.Side == insertion.Side && removal.Type == insertion.Type;
            });

            pair([](const PieceChange removal, const PieceChange insertion) {
                return removal.Side == insertion.Side;
            });

            return pairing;
        }

        template<typename T = Geometry::Lut>
        constexpr static void Changes(
            const PieceDelta&                 delta,
            const Record&                     after,
                  MantaRay::Changes<Threats>& out
        ) noexcept
        {
            const s00 removals   = delta.RemovedCount ();
            const s00 insertions = delta.InsertedCount();

            typename T::Mailbox mailbox = T::Load(after.Codes);

            for (s00 i = 0; i < insertions; i++) T::Put(mailbox, delta.Inserted(i).Square, Geometry::Empty);
            for (s00 i = 0; i < removals  ; i++) T::Put(mailbox, delta.Removed (i).Square, Code(delta.Removed(i)));

            const Pairing pairing = Pair(delta);

            const auto remove = [&](const PieceChange change) {
                T::template Focus<Shape, true>(mailbox, change.Square, Code(change), Polarity::Remove, out);
                T::Put(mailbox, change.Square, Geometry::Empty);
            };

            const auto add = [&](const PieceChange change) {
                T::template Focus<Shape, true>(mailbox, change.Square, Code(change), Polarity::Add, out);
                T::Put(mailbox, change.Square, Code(change));
            };

            const auto mutate = [&](const PieceChange removal, const PieceChange insertion) {
                T::template Focus<Shape, false>(mailbox, removal.Square, Code(removal  ), Polarity::Remove, out);
                T::Put(mailbox, removal.Square, Code(insertion));
                T::template Focus<Shape, false>(mailbox, removal.Square, Code(insertion), Polarity::Add   , out);
            };

            for (s00 r = 0; r < removals; r++) if (pairing.Mates[r] == Pairing::None) remove(delta.Removed(r));

            for (s00 r = 0; r < removals; r++) {
                if (pairing.Mates[r] == Pairing::None) continue;

                const PieceChange removal   = delta.Removed (r);
                const PieceChange insertion = delta.Inserted(pairing.Mates[r]);

                if (removal.Square == insertion.Square) mutate(removal, insertion);
            }

            for (s00 r = 0; r < removals; r++) {
                if (pairing.Mates[r] == Pairing::None) continue;

                const PieceChange removal   = delta.Removed (r);
                const PieceChange insertion = delta.Inserted(pairing.Mates[r]);

                if (removal.Square == insertion.Square) continue;

                remove(removal  );
                add   (insertion);
            }

            for (s00 i = 0; i < insertions; i++) if ((pairing.Taken >> i & 1) == 0) add(delta.Inserted(i));
        }

        template<Lowering::Tier T>
        constexpr static u32 Flip(const u08 perspective, const u08 code) noexcept
        {
            using Tier = Lowering::Tier;

            static_assert(T == Tier::Lookup || T == Tier::Modulo, "a colour flip is Lookup or Modulo");

            if constexpr (T == Tier::Lookup) return Flips[perspective][code];
            else return (code + 6 * perspective) % 12;
        }

        template<Lowering::Tier T>
        constexpr static u32 Ordinal(const u32 attacker, const u32 from, const u32 to) noexcept
        {
            using Tier = Lowering::Tier;

            static_assert(T == Tier::Lookup || T == Tier::Popcount, "an ordinal is Lookup or Popcount");

            if constexpr (T == Tier::Lookup) return Ordinals[attacker][from][to];
            else return static_cast<u32>(std::popcount(Table.Pseudo[attacker][from] & ((u64 { 1 } << to) - 1)));
        }

        template<typename ISA = Backend::ISAOf<Lowering::Native>>
        constexpr static u32 Index(const u08 perspective, const u32 key, const Change& change) noexcept
        {
            const u32 orient   = 56 * perspective ^ 7 * key;
            const u32 from     = change.From ^ orient;
            const u32 to       = change.To   ^ orient;
            const u32 attacker = Flip<FlipOf<ISA>>(perspective, change.Attacker);
            const u32 attacked = Flip<FlipOf<ISA>>(perspective, change.Attacked);
            const u32 pair     = Table.Pairs[attacker][attacked][from < to];

            if (pair == NoRow) return NoRow;

            return pair + Table.Offsets[attacker][from] + Ordinal<OrdinalOf<ISA>>(attacker, from, to);
        }

        template<typename ISA = Backend::ISAOf<Lowering::Native>, typename Board, typename Emit>
        constexpr static void Active(const u08 perspective, const Board& board, Emit&& emit) noexcept
        {
            static_assert(Trigger::KeyCount == 2, "the orientation of a threat index is a mirror and a colour flip");

            const u32 key    = Trigger::Key(perspective, board);
            const u32 orient = 56 * perspective ^ 7 * key;

            const u64 occupied = board.Occupied();

            Array<u64, 2, 6> pieces;
            Array<u64,    6> types ;

            for (u08 piece = 0; piece < 6; piece++) {
                pieces[White][piece] = board.Pieces(White, static_cast<Piece>(piece));
                pieces[Black][piece] = board.Pieces(Black, static_cast<Piece>(piece));
                types        [piece] = pieces[White][piece] | pieces[Black][piece];
            }

            const Array<u64, 64>& below = Below[perspective][key];

            [&]<u08... P>(const std::integer_sequence<u08, P...>) {
                ([&] {
                    constexpr u08 Others = [] {
                        u08 others = 0;

                        for (u08 victim = 0; victim < 6; victim++)
                            if (victim != P && M.Targets[P][victim] >= 0) others |= static_cast<u08>(1 << victim);

                        return others;
                    }();

                    if constexpr (Others == 0 && M.Targets[P][P] < 0) return;

                    constexpr bool Pawn   = P == static_cast<u08>(Piece::Pawn);
                    constexpr bool Mutual = M.Targets[P][P] >= 0;

                    u64 other = 0;

                    for (u08 victim = 0; victim < 6; victim++) if (Others >> victim & 1) other |= types[victim];

                    for (u08 side = 0; side < 2; side++) {
                        const u64 both = Pawn && Mutual ? other | pieces[side][P] : other;
                        const u64 once = !Mutual ? 0 : Pawn ? pieces[side ^ 1][P] : types[P];

                        const u32 attacker = Flip<FlipOf<ISA>>(perspective, static_cast<u08>(side * 6 + P));

                        u64 sources = pieces[side][P];

                        while (sources) {
                            const u08 from   = Attacks::PopLowest(sources);
                            const u32 source = from ^ orient;
                            const u32 offset = Table.Offsets[attacker][source];

                            u64 targets = Attacks::Of(side, static_cast<Piece>(P), from, occupied) &
                                          (both | (once & below[from]));

                            while (targets) {
                                const u08 to       = Attacks::PopLowest(targets);
                                const u32 target   = to ^ orient;
                                const u32 attacked = Flip<FlipOf<ISA>>(perspective, board.At(to));
                                const u32 pair     = Table.Pairs[attacker][attacked][source < target];

                                assert(pair != NoRow);

                                emit(pair + offset + Ordinal<OrdinalOf<ISA>>(attacker, source, target));
                            }
                        }
                    }
                }(), ...);
            }(std::make_integer_sequence<u08, 6> {});
        }

        template<typename Emit>
        constexpr static void Collect(const Change& change, Emit&& emit) noexcept
        {
            if (Table.Pairs[change.Attacker][change.Attacked][0] != NoRow) emit(change);
        }

        template<typename Board, typename Emit>
        constexpr static void Outgoing(
            const Board& board   ,
            const u64    occupied,
            const u08    attacker,
            const u08    from    ,
                  Emit&& emit
        ) noexcept
        {
            u64 targets = Attacks::Of(attacker / 6, static_cast<Piece>(attacker % 6), from, occupied) & occupied;

            while (targets) {
                const u08 to = Attacks::PopLowest(targets);

                Collect({ .Attacker = attacker, .From = from, .Attacked = board.At(to), .To = to }, emit);
            }
        }

        constexpr static u08 Code(const PieceChange change) noexcept { return Geometry::CodeOf(change); }

    };

}

#endif //MANTARAY_FEATURESET_THREATS_H
