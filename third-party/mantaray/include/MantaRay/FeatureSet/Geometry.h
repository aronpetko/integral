//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_FEATURESET_GEOMETRY_H
#define MANTARAY_FEATURESET_GEOMETRY_H

#include <bit>

#include "Attacks.h"
#include "Changes.h"
#include "FeatureSet.h"
#include "../Common.h"

namespace MantaRay::Geometry
{

    constexpr inline u08 Empty = 12;
    constexpr inline u08 Off   = 0x80;

    namespace Detail
    {

        consteval Array<u64, 12, 64> ReachOf()
        {
            Array<u64, 12, 64> reach {};

            for (s00 code   = 0; code   < 12; code++)
            for (s00 square = 0; square < 64; square++)
                reach[code][square] = Attacks::Empty(code / 6, static_cast<Piece>(code % 6), square);

            return reach;
        }

        constexpr inline Array<u64, 12, 64> Reach = ReachOf();

        consteval bool Line(const i32 file, const i32 rank)
        {
            return file == 0 || rank == 0 || file == rank || file == -rank;
        }

        consteval bool Slides(const u08 code)
        {
            for (s00 square = 0; square < 64; square++)
                if (Attacks::Of(code / 6, static_cast<Piece>(code % 6), square, ~u64 { 0 }) != Reach[code][square])
                    return true;

            return false;
        }

        struct Jumps
        {

            Array<i32, 8, 2> Steps {};

            u32 Count = 0;

        };

        consteval Jumps JumpsOf()
        {
            Jumps jumps {};

            for (s00 code   = 0; code   < 12; code++)
            for (s00 square = 0; square < 64; square++)
            for (u64 reach  = Reach[code][square]; reach; ) {
                const u08 target = Attacks::PopLowest(reach);
                const i32 file   = target % 8 - static_cast<i32>(square) % 8;
                const i32 rank   = target / 8 - static_cast<i32>(square) / 8;

                bool known = Line(file, rank);

                for (s00 i = 0; i < jumps.Count; i++) known |= jumps.Steps[i][0] == file && jumps.Steps[i][1] == rank;

                if (known) continue;

                if (jumps.Count < 8) jumps.Steps[jumps.Count] = { file, rank };

                jumps.Count++;
            }

            return jumps;
        }

        constexpr inline Jumps Leaping = JumpsOf();

        static_assert(Leaping.Count <= 8, "the squares reached off the eight lines fit one slot per octant");

        consteval Array<u08, 64, 64> PermOf()
        {
            Array<u08, 64, 64> perm {};

            for (s00 focus     = 0; focus     < 64; focus++)
            for (s00 direction = 0; direction < 8 ; direction++)
            for (s00 distance  = 0; distance  < 8 ; distance++) {
                const Array<i32, 2>& step = Attacks::Directions[direction];
                const Array<i32, 2>& leap = Leaping.Steps      [direction];

                const bool jump = distance == 0;
                const i32  file = static_cast<i32>(focus) % 8 + (jump ? leap[0] : static_cast<i32>(distance) * step[0]);
                const i32  rank = static_cast<i32>(focus) / 8 + (jump ? leap[1] : static_cast<i32>(distance) * step[1]);
                const bool off  = (jump && direction >= Leaping.Count) || file < 0 || file > 7 || rank < 0 || rank > 7;

                perm[focus][direction * 8 + distance] = off ? Off : static_cast<u08>(rank * 8 + file);
            }

            return perm;
        }

    }

    constexpr inline Array<u08, 64, 64> Perm = Detail::PermOf();

    constexpr inline u32 MaxFocus = 2 * (Detail::Leaping.Count + static_cast<u32>(Attacks::Directions.size()));
    constexpr inline u32 MaxXrays = static_cast<u32>(Attacks::Directions.size());

    namespace Detail
    {

        consteval Array<u08, 64, 64> SlotsOf()
        {
            Array<u08, 64, 64> slots {};

            for (Array<u08, 64>& row : slots) row.fill(Off);

            for (s00 focus = 0; focus < 64; focus++)
            for (s00 slot  = 0; slot  < 64; slot++)
                if (Perm[focus][slot] != Off) slots[focus][Perm[focus][slot]] = static_cast<u08>(slot);

            return slots;
        }

        consteval Array<u64, 64> LeapsOf()
        {
            Array<u64, 64> leaps {};

            for (s00 focus     = 0; focus     < 64; focus++)
            for (s00 direction = 0; direction < 8 ; direction++)
                if (Perm[focus][direction * 8] != Off) leaps[focus] |= u64 { 1 } << Perm[focus][direction * 8];

            return leaps;
        }

        consteval Array<u08, 16> ClassOf()
        {
            Array<u08, 16> classes {};

            u08 next = 0;

            for (s00 code = 0; code < 12; code++) {
                const u08 twin = static_cast<u08>(code < 6 ? code + 6 : code - 6);

                if (code >= 6 && Reach[code] == Reach[twin]) classes[code] = classes[twin];
                else                                          classes[code] = static_cast<u08>(1 << next++);
            }

            return classes;
        }

    }

    constexpr inline Array<u08, 64, 64> Slots = Detail::SlotsOf();
    constexpr inline Array<u64, 64>     Leaps = Detail::LeapsOf();
    constexpr inline Array<u08, 16>     Class = Detail::ClassOf();

    namespace Detail
    {

        consteval bool Classes()
        {
            u08 seen = 0;

            for (s00 code = 0; code < 12; code++) {
                if (std::popcount(Class[code]) != 1) return false;

                seen |= Class[code];
            }

            return seen < 0x80;
        }

        static_assert(Classes(), "every code takes one of at most seven class bits; an empty square has none");

        consteval bool Invariant()
        {
            for (s00 code = 0; code < 12; code++) {
                u64 outward = 0;
                u64 missed  = 0;
                u64 inward  = 0;
                u64 blind   = 0;

                for (s00 focus = 0; focus < 64; focus++)
                for (s00 slot  = 0; slot  < 64; slot++) {
                    const u08 square = Perm[focus][slot];

                    if (square == Off) continue;

                    const u64 bit = u64 { 1 } << slot;

                    if (Reach[code][focus ] >> square & 1) outward |= bit;
                    else                                   missed  |= bit;

                    if (Reach[code][square] >> focus  & 1) inward  |= bit;
                    else                                   blind   |= bit;
                }

                if ((outward & missed) != 0 || (inward & blind) != 0) return false;

                const bool slides = Slides(code);

                for (s00 direction = 0; direction < 8; direction++) {
                    const u08 out  = outward >> ( direction * 8)      & 0xFE;
                    const u08 in   = inward  >> ( direction * 8)      & 0xFE;
                    const u08 back = outward >> ((direction ^ 4) * 8) & 0xFE;

                    if (slides ? (out != 0 && out != 0xFE) || (in != 0 && in != 0xFE) || in != back
                               : (out & 0xFC) != 0 || (in & 0xFC) != 0) return false;
                }
            }

            return true;
        }

        static_assert(
            Invariant(),
            "a code reaches the same slots from every focus: on a ray the first square only, or every square up to the "
            "first piece and on past the focus"
        );

    }

    struct Tables
    {

        Array<u64, 13> Out       {};
        Array<u08, 64> In        {};
        Array<u08, 64> Sliders   {};
        Array<u08, 13> Victims   {};
        Array<u08, 13> Attackers {};

    };

    consteval Tables Build(const Array<i08, 6, 6>& targets)
    {
        Tables tables {};

        for (s00 code  = 0; code  < 12; code++)
        for (s00 other = 0; other < 12; other++) {
            if (targets[code  % 6][other % 6] >= 0) tables.Victims  [code] |= Class[other];
            if (targets[other % 6][code  % 6] >= 0) tables.Attackers[code] |= Class[other];
        }

        for (s00 code = 0; code < 12; code++) {
            if (tables.Victims[code] == 0) continue;

            const bool slides = Detail::Slides(code);

            for (s00 focus = 0; focus < 64; focus++)
            for (s00 slot  = 0; slot  < 64; slot++) {
                const u08 square = Perm[focus][slot];

                if (square == Off) continue;

                if (Detail::Reach[code][focus] >> square & 1) tables.Out[code] |= u64 { 1 } << slot;

                if (Detail::Reach[code][square] >> focus & 1) {
                    tables.In[slot] |= Class[code];

                    if (slides && slot % 8 != 0) tables.Sliders[slot] |= Class[code];
                }
            }
        }

        return tables;
    }

    constexpr u08 CodeOf(const PieceChange change) noexcept
    { return static_cast<u08>(change.Side * 6 + static_cast<u08>(change.Type)); }

    constexpr u64 Closest(const u64 occupied) noexcept
    {
        const u64 forced = occupied | 0x8181818181818181;

        return (forced ^ (forced - 0x0303030303030303)) & occupied;
    }

    constexpr u64 Fill(const u64 groups) noexcept
    {
        const u64 high = (groups + 0x7E7E7E7E7E7E7E7E) & 0x8080808080808080;

        return high - (high >> 7);
    }

    namespace Detail
    {

        consteval u08 Nearest(const u08 byte)
        {
            const u32 rays = byte & 0xFE;

            return static_cast<u08>((byte & 1) | (rays & (0 - rays)));
        }

        consteval bool Forced()
        {
            for (s00 byte  = 0; byte  < 256; byte++)
            for (s00 place = 0; place < 8  ; place++)
            for (s00 side  = 0; side  < 2  ; side++) {
                const u32 shift    = static_cast<u32>(place * 8);
                const u64 around   = side == 0 ? 0 : ~u64 { 0 };
                const u64 occupied = (around & ~(u64 { 0xFF } << shift)) | u64 { byte } << shift;
                const u64 closest  = Closest(occupied);

                for (s00 group = 0; group < 64; group += 8)
                    if ((closest >> group & 0xFF) != Nearest(static_cast<u08>(occupied >> group))) return false;
            }

            return true;
        }

        consteval bool Filled()
        {
            for (s00 bit   = 0; bit   < 8; bit++)
            for (s00 place = 0; place < 8; place++)
            for (s00 side  = 0; side  < 3; side++) {
                const u32 shift  = static_cast<u32>(place * 8);
                const u32 byte   = bit  == 0 ? 0 : u32   { 1 } << bit;
                const u64 around = side == 0 ? 0 : side == 1 ? 0x8080808080808080 : 0x0202020202020202;
                const u64 groups = (around & ~(u64 { 0xFF } << shift)) | u64 { byte } << shift;

                if ((Fill(groups) >> shift & 0xFF) != (byte == 0 ? 0 : 0x7F)) return false;
            }

            return true;
        }

        static_assert(Forced(), "with the knight slot and the seventh ray square forced on, closest is computed per "
                                "byte without a borrow and keeps the knight bit and the lowest ray bit of each byte");
        static_assert(Filled(), "fill turns a byte with one ray bit into 0x7F and an empty byte into 0, with no carry");

    }

    template<typename Emit>
    constexpr void Partners(
        const Array<u64, 2>&  pawns  ,
        const Array<u64, 64>& masks  ,
        const u64             touched,
              Emit&&          emit
    ) noexcept
    {
        const u64 all = pawns[White] | pawns[Black];

        u64 seen = 0;
        u64 rest = all & touched;

        while (rest) {
            const u08 first = Attacks::PopLowest(rest);

            u64 partners = all & masks[first] & ~seen;

            seen |= u64 { 1 } << first;

            while (partners) emit(first, Attacks::PopLowest(partners));
        }
    }

    struct Lut
    {

        struct Mailbox
        {

            Array<u08, 64> Codes    {};
            u64            Occupied =  0;

        };

        constexpr static Mailbox Load(const Array<u08, 64>& codes) noexcept
        {
            Mailbox mailbox { .Codes = codes };

            for (u08 square = 0; square < 64; square++) mailbox.Occupied |= u64 { codes[square] != Empty } << square;

            return mailbox;
        }

        constexpr static void Put(Mailbox& mailbox, const u08 square, const u08 code) noexcept
        {
            const u64 bit = u64 { 1 } << square;

            mailbox.Codes[square] = code;
            mailbox.Occupied      = code == Empty ? mailbox.Occupied & ~bit : mailbox.Occupied | bit;
        }

        template<const Tables& G, bool Xray, typename C>
        constexpr static void Focus(
            const Mailbox& mailbox ,
            const u08      square  ,
            const u08      code    ,
            const Polarity polarity,
                  C&       out
        ) noexcept
        {
            using Change = C::Change;

            Change* const own   = out.Tail(polarity);
            Change* const other = out.Tail(Opposite(polarity));

            const u64 outgoing  = G.Out      [code];
            const u08 victims   = G.Victims  [code];
            const u08 attackers = G.Attackers[code];

            u32 owned  = 0;
            u32 others = 0;

            const auto touch = [&](const u08 target) {
                const u08 slot  = Slots[square][target];
                const u08 piece = mailbox.Codes[target];
                const u08 kind  = Class[piece];

                own[owned] = { .Attacker = code , .From = square, .Attacked = piece, .To = target };
                owned     += (outgoing >> slot & 1) != 0 && (victims & kind) != 0;

                own[owned] = { .Attacker = piece, .From = target, .Attacked = code , .To = square };
                owned     += (G.In[slot] & attackers & kind) != 0;
            };

            for (u64 leaps = Leaps[square] & mailbox.Occupied; leaps; ) touch(Attacks::PopLowest(leaps));

            Array<u08, 8> nearest {};

            u08 present = 0;

            for (u08 direction = 0; direction < 8; direction++) {
                const u64 blockers = Attacks::Rays[direction][square] & mailbox.Occupied;

                if (blockers == 0) continue;

                const u08 target = direction < 4 ? static_cast<u08>(std::countr_zero(blockers))
                                                 : static_cast<u08>(63 - std::countl_zero(blockers));

                nearest[direction]  = target;
                present            |= static_cast<u08>(1 << direction);

                touch(target);
            }

            if (Xray) {
                const auto xray = [&](const u08 from, const u08 to) {
                    const u08 slider = mailbox.Codes[from];
                    const u08 victim = mailbox.Codes[to  ];

                    other[others] = { .Attacker = slider, .From = from, .Attacked = victim, .To = to };
                    others       += (G.Sliders[Slots[square][from]] & Class[slider]) != 0 &&
                                    (G.Victims[slider]              & Class[victim]) != 0;
                };

                for (u08 direction = 0; direction < 4; direction++) {
                    if ((present >> direction & 0x11) != 0x11) continue;

                    xray(nearest[direction    ], nearest[direction + 4]);
                    xray(nearest[direction + 4], nearest[direction    ]);
                }
            }

            out.Advance(polarity          , owned );
            out.Advance(Opposite(polarity), others);
        }

        template<const Array<u64, 64>& Masks, typename C>
        constexpr static void Pairs(
            const Array<u64, 2>& pawns   ,
            const u64            touched ,
            const Polarity       polarity,
                  C&             out
        ) noexcept
        {
            using Change = C::Change;

            Change* const tail = out.Tail(polarity);

            u32 count = 0;

            const auto side = [&](const u08 square) { return pawns[White] >> square & 1 ? White : Black; };

            Partners(pawns, Masks, touched, [&](const u08 first, const u08 second) {
                tail[count++] = {
                    .FirstSide  = side(first ),
                    .First      = first,
                    .SecondSide = side(second),
                    .Second     = second
                };
            });

            out.Advance(polarity, count);
        }

    };

}

#endif //MANTARAY_FEATURESET_GEOMETRY_H
