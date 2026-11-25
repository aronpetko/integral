//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_BACKEND_KERNEL_GEOMETRY_H
#define MANTARAY_BACKEND_KERNEL_GEOMETRY_H

#include <algorithm>
#include <array>
#include <bit>
#include <type_traits>

#include "../../Common.h"
#include "../../FeatureSet/Attacks.h"
#include "../../FeatureSet/Changes.h"
#include "../../FeatureSet/Geometry.h"
#include "../../FeatureSet/PawnPairs.h"
#include "../../FeatureSet/Threats.h"
#include "../../Lowering/Choices.h"

namespace MantaRay::Backend::Kernel::Geometry
{

    namespace Detail
    {

        constexpr inline u64 Rays = 0xFEFEFEFEFEFEFEFE;

        consteval Array<u08, 16, 16> SelectsOf()
        {
            Array<u08, 16, 16> selects {};

            for (s00 lane = 0; lane < 16; lane++) selects[lane][lane] = 0x80;

            return selects;
        }

        consteval Array<u08, 258, 8> ListsOf()
        {
            Array<u08, 258, 8> lists {};

            for (s00 byte = 0; byte < 256; byte++) {
                u08 count = 0;

                for (s00 bit = 0; bit < 8; bit++) if (byte >> bit & 1) lists[byte][count++] = static_cast<u08>(bit);
            }

            return lists;
        }

        consteval Array<u08, 64> IotaOf()
        {
            Array<u08, 64> iota {};

            for (s00 square = 0; square < 64; square++) iota[square] = static_cast<u08>(square);

            return iota;
        }

        alignas(Alignment) constexpr inline Array<u08, 16, 16> Selects = SelectsOf();
        alignas(Alignment) constexpr inline Array<u08, 258, 8> Lists   = ListsOf  ();
        alignas(Alignment) constexpr inline Array<u08, 64    > Iota    = IotaOf   ();

        alignas(Alignment) constexpr inline Array<u08, 64, 64> Perm = MantaRay::Geometry::Perm;

        template<const MantaRay::Geometry::Tables& G>
        struct Aligned
        {

            alignas(Alignment) constexpr static Array<u08, 64> In      = G.In;
            alignas(Alignment) constexpr static Array<u08, 64> Sliders = G.Sliders;

        };

        consteval bool Selectable()
        {
            for (s00 focus = 0; focus < 64; focus++)
            for (s00 slot  = 0; slot  < 64; slot++) {
                const u08 square = Perm[focus][slot];

                if (square != MantaRay::Geometry::Off && square >= 64) return false;
            }

            return MantaRay::Geometry::Off == 0x80;
        }

        template<u32 S>
        consteval bool Quarters()
        {
            for (s00 focus = 0; focus < 64; focus++)
            for (s00 word  = 0; word  < 16; word++) {
                u32 lanes = 0;

                for (s00 byte = 0; byte < 4; byte++) lanes |= u32 { Perm[focus][word * 4 + byte] } << (byte * 8);

                const u32 shifted = lanes << S;

                for (s00 byte = 0; byte < 4; byte++)
                    if ((shifted >> (byte * 8 + 7) & 1) != (Perm[focus][word * 4 + byte] >> (7 - S) & 1)) return false;
            }

            return true;
        }

        consteval bool Masked()
        {
            for (s00 code = 0; code < MantaRay::Geometry::Empty; code++)
                if (MantaRay::Geometry::Class[code] == 0) return false;

            return MantaRay::Geometry::Empty < 16 && MantaRay::Geometry::Class[MantaRay::Geometry::Empty] == 0;
        }

        consteval bool Opposed()
        {
            for (s00 direction = 0; direction < 8; direction++) {
                const u08 opposite = static_cast<u08>(direction ^ 4);

                if (Attacks::Directions[opposite][0] != -Attacks::Directions[direction][0]) return false;
                if (Attacks::Directions[opposite][1] != -Attacks::Directions[direction][1]) return false;

                if (std::rotr(u64 { 0xFF } << (opposite * 8), 32) != u64 { 0xFF } << (direction * 8))
                    return false;
            }

            return true;
        }

        consteval bool Listed()
        {
            for (s00 byte = 0; byte < Lists.size(); byte++)
            for (s00 slot = 0; slot < 8           ; slot++) {
                const u32 count = byte < 256 ? static_cast<u32>(std::popcount(byte)) : 0;

                if (Lists[byte][slot] >= 8 || (slot >= count && Lists[byte][slot] != 0)) return false;
            }

            return true;
        }

        consteval bool Counted()
        {
            for (s00 square = 0; square < 64; square++) if (Iota[square] != square) return false;

            return true;
        }

        consteval bool Defaulted()
        {
            return MantaRay::Geometry::Off >= 64 && MantaRay::Geometry::Empty < 16;
        }

        static_assert(Selectable(), "a slot holds a square below 64 or the off-board marker 0x80, which shuffles zero");
        static_assert(
            Quarters<3>() && Quarters<2>(),
            "a 32-bit shift by 3 or 2 moves bit 4 or 5 of each slot byte to its bit 7, the blend selector"
        );
        static_assert(Masked(), "every piece code has a class bit, and the empty code and off-board slots have none");
        static_assert(Opposed(), "a 32-bit rotation pairs every direction with its opposite");
        static_assert(Listed(), "a list row holds the set bits of its byte in order below 8, then zeros");
        static_assert(Counted(), "the iota holds each square in its own byte, so a compressed byte is its square");
        static_assert(
            Defaulted(),
            "an off-board slot takes the empty code and every code indexes the first register of the class table"
        );

        template<const MantaRay::Geometry::Tables& G, bool Xray, typename C>
        [[clang::always_inline]]
        void Emit(
            const std::array<u08, 64>& codes   ,
            const u08                  square  ,
            const u08                  code    ,
            const u64                  occupied,
            const u64                  targets ,
            const u64                  incoming,
            const u64                  sliders ,
            const Polarity             polarity,
                  C&                   out
        ) noexcept
        {
            using Change = C::Change;

            const Array<u08, 64>& squares = Perm[square];

            const u64 closest = MantaRay::Geometry::Closest(occupied);

            Change* own   = out.Tail(polarity);
            Change* other = out.Tail(Opposite(polarity));

            u32 owned  = 0;
            u32 others = 0;

            for (u64 rest = G.Out[code] & closest & targets; rest; ) {
                const u08 slot = Attacks::PopLowest(rest);

                own[owned++] = { .Attacker = code, .From = square, .Attacked = codes[slot], .To = squares[slot] };
            }

            for (u64 rest = closest & incoming; rest; ) {
                const u08 slot = Attacks::PopLowest(rest);

                own[owned++] = { .Attacker = codes[slot], .From = squares[slot], .Attacked = code, .To = square };
            }

            if (Xray) {
                const u64 inner  = closest & Rays;
                const u64 slid   = inner & sliders;
                const u64 beyond = std::rotr(inner, 32);
                const u64 valid  = MantaRay::Geometry::Fill(beyond) & MantaRay::Geometry::Fill(slid);

                for (u64 rest = slid & valid; rest; ) {
                    const u08 slot   = Attacks::PopLowest(rest);
                    const u64 group  = u64 { 0xFF } << (slot & 56);
                    const u08 victim = static_cast<u08>(std::countr_zero(std::rotl(beyond & group, 32)));

                    other[others] = {
                        .Attacker = codes  [slot  ],
                        .From     = squares[slot  ],
                        .Attacked = codes  [victim],
                        .To       = squares[victim]
                    };
                    others       += (G.Victims[codes[slot]] & MantaRay::Geometry::Class[codes[victim]]) != 0;
                }
            }

            out.Advance(polarity          , owned );
            out.Advance(Opposite(polarity), others);
        }

        template<typename ISA>
        struct Quartered
        {

            using Vector = ISA::Vector;

            struct Mailbox
            {

                Array<Vector, 4> Quarters;

            };

            [[clang::always_inline]]
            static Mailbox Load(const std::array<u08, 64>& codes) noexcept
            {
                Mailbox mailbox;

                for (u08 quarter = 0; quarter < 4; quarter++)
                    mailbox.Quarters[quarter] = ISA::BroadcastU128(codes.data() + 16 * quarter);

                return mailbox;
            }

            [[clang::always_inline]]
            static void Put(Mailbox& mailbox, const u08 square, const u08 code) noexcept
            {
                const auto select = ISA::BroadcastU128(Selects[square % 16].data());

                Vector& quarter = mailbox.Quarters[square / 16];

                quarter = ISA::BlendMaskU08(select, quarter, ISA::BroadcastU08(code));
            }

        };

        template<typename ISA, const MantaRay::Geometry::Tables& G, bool Xray, typename P, typename K, typename C>
        [[clang::always_inline]]
        void Scan(
            const u08      square  ,
            const u08      code    ,
            const Polarity polarity,
                  C&       out     ,
            const P&       gather  ,
            const K&       classify
        ) noexcept
        {
            using A = Aligned<G>;

            constexpr s00 Chunks = 64 / ISA::Bytes;

            static_assert(Chunks * ISA::Bytes == 64, "the 64 slots of a focus square fill whole vectors");

            const auto victims   = ISA::BroadcastU08(G.Victims  [code]);
            const auto attackers = ISA::BroadcastU08(G.Attackers[code]);

            alignas(Alignment) Array<u08, 64> codes;

            u64 occupied = 0;
            u64 targets  = 0;
            u64 incoming = 0;
            u64 sliders  = 0;

            for (s00 chunk = 0; chunk < Chunks; chunk++) {
                const s00 offset = chunk * ISA::Bytes;

                const auto piece = gather(ISA::Load(Perm[square].data() + offset));
                const auto bits  = classify(piece);
                const auto in    = ISA::And(ISA::Load(A::In.data() + offset), attackers);

                ISA::Store(codes.data() + offset, piece);

                occupied |= ISA::TestMask64(bits, bits     ) << offset;
                targets  |= ISA::TestMask64(bits, victims  ) << offset;
                incoming |= ISA::TestMask64(bits, in       ) << offset;

                if (Xray) sliders |= ISA::TestMask64(bits, ISA::Load(A::Sliders.data() + offset)) << offset;
            }

            Emit<G, Xray>(codes, square, code, occupied, targets, incoming, sliders, polarity, out);
        }

        template<typename T, const Array<u64, 64>& Masks, typename C>
        [[clang::always_inline]]
        void Pairs(
            const std::array<u64, 2>& pawns   ,
            const u64                 touched ,
            const Polarity            polarity,
                  C&                  out
        ) noexcept
        {
            using Change = C::Change;

            static_assert(
                std::bit_cast<u32>(Change { .FirstSide = 1, .First = 2, .SecondSide = 3, .Second = 4 }) == 0x04030201,
                "a pawn-pair record is {FirstSide, First, SecondSide, Second} in byte order"
            );
            static_assert(T::Reach <= C::Slack, "a list store runs at most the list's slack past its last record");

            Change* tail = out.Tail(polarity);

            const u64 all = pawns[White] | pawns[Black];

            u32 count = 0;
            u64 seen  = 0;

            for (u64 rest = all & touched; rest; ) {
                const u08 first = Attacks::PopLowest(rest);
                const u32 side  = (pawns[White] >> first & 1) == 0;
                const u32 base  = side | u32 { first } << 8;

                const u64 partners = all & Masks[first] & ~seen;

                seen |= u64 { 1 } << first;

                count += T::Partners(partners &  pawns[White], base                  , tail + count);
                count += T::Partners(partners & ~pawns[White], base | u32 { 1 } << 16, tail + count);
            }

            out.Advance(polarity, count);
        }

    }

    template<typename ISA> requires (ISA::Shuffle)
    struct Swizzle : Detail::Quartered<ISA>
    {

        using Vector  = ISA::Vector;
        using Mailbox = Detail::Quartered<ISA>::Mailbox;

        template<const MantaRay::Geometry::Tables& G, bool Xray, typename C>
        [[clang::noinline]]
        static void Focus(
            const Mailbox& mailbox ,
            const u08      square  ,
            const u08      code    ,
            const Polarity polarity,
                  C&       out
        ) noexcept
        {
            const auto classes = ISA::BroadcastU128(MantaRay::Geometry::Class.data());
            const auto off     = ISA::BroadcastU08(MantaRay::Geometry::Off);

            const auto& first  = mailbox.Quarters[0];
            const auto& second = mailbox.Quarters[1];
            const auto& third  = mailbox.Quarters[2];
            const auto& fourth = mailbox.Quarters[3];

            const auto gather = [&](const Vector index) {
                const auto four = ISA::template ShiftLeftI32<3>(index);
                const auto five = ISA::template ShiftLeftI32<2>(index);
                const auto low  = ISA::BlendMaskU08(four, ISA::Shuffle16(first, index), ISA::Shuffle16(second, index));
                const auto high = ISA::BlendMaskU08(four, ISA::Shuffle16(third, index), ISA::Shuffle16(fourth, index));

                return ISA::Or(ISA::BlendMaskU08(five, low, high), ISA::And(index, off));
            };

            const auto classify = [&](const Vector piece) { return ISA::Shuffle16(classes, piece); };

            Detail::Scan<ISA, G, Xray>(square, code, polarity, out, gather, classify);
        }

    };

    template<typename ISA> requires (ISA::Table)
    struct Table : Detail::Quartered<ISA>
    {

        using Vector  = ISA::Vector;
        using Mailbox = Detail::Quartered<ISA>::Mailbox;

        static_assert(ISA::Bytes == 16, "a quarter of the mailbox is one table register");

        template<const MantaRay::Geometry::Tables& G, bool Xray, typename C>
        [[clang::always_inline]]
        static void Focus(
            const Mailbox& mailbox ,
            const u08      square  ,
            const u08      code    ,
            const Polarity polarity,
                  C&       out
        ) noexcept
        {
            const auto             empty   = ISA::BroadcastU08(MantaRay::Geometry::Empty);
            const Array<Vector, 4> classes {
                ISA::BroadcastU128(MantaRay::Geometry::Class.data()),
                ISA::Zero(),
                ISA::Zero(),
                ISA::Zero()
            };

            const auto gather   = [&](const Vector index) { return ISA::Table64(mailbox.Quarters, index, empty); };
            const auto classify = [&](const Vector piece) { return ISA::Table64(classes, piece, ISA::Zero()); };

            Detail::Scan<ISA, G, Xray>(square, code, polarity, out, gather, classify);
        }

    };

    template<typename ISA>
    struct Expand
    {

        constexpr static u32 Lanes = ISA::Bytes / sizeof(u32);
        constexpr static u32 Reach = std::max<u32>(8, Lanes);

        static_assert(
            255 * 8 + (Reach - Lanes) + 16 <= Detail::Lists.size() * 8,
            "the 16-byte list reads of every byte stay inside the padded list table"
        );

        template<typename Change>
        [[clang::always_inline]]
        static u32 Partners(u64 partners, const u32 base, Change* const tail) noexcept
        {
            u32 count = 0;

            while (partners) {
                const u32 shift = static_cast<u32>(std::countr_zero(partners)) & ~u32 { 7 };
                const u32 byte  = static_cast<u32>(partners >> shift) & 0xFF;

                for (u32 part = 0; part < 8; part += Lanes) {
                    const auto squares = ISA::Or(
                        ISA::BroadcastU128(Detail::Lists[byte].data() + part),
                        ISA::BroadcastU08(static_cast<u08>(shift))
                    );
                    const auto records = ISA::Or(
                        ISA::template ShiftLeftI32<24>(ISA::WidenU08U32(squares)),
                        ISA::BroadcastI32(static_cast<i32>(base))
                    );

                    ISA::StoreUnaligned(tail + count + part, records);
                }

                count    += static_cast<u32>(std::popcount(byte));
                partners &= ~(u64 { 0xFF } << shift);
            }

            return count;
        }

        template<const Array<u64, 64>& Masks, typename C>
        [[clang::noinline]]
        static void Pairs(
            const std::array<u64, 2>& pawns   ,
            const u64                 touched ,
            const Polarity            polarity,
                  C&                  out
        ) noexcept
        { Detail::Pairs<Expand, Masks>(pawns, touched, polarity, out); }

    };

    template<typename ISA> requires (ISA::Compress)
    struct Compress
    {

        using Vector = ISA::Vector;

        constexpr static u32 Lanes = ISA::Bytes / sizeof(u32);
        constexpr static u32 Reach = Lanes;

        static_assert(ISA::Bytes == 64, "the iota holds the 64 squares in one vector, one byte each");

        template<typename Change>
        [[clang::always_inline]]
        static u32 Partners(const u64 partners, const u32 base, Change* const tail) noexcept
        {
            const u32  count = static_cast<u32>(std::popcount(partners));
            const auto head  = ISA::BroadcastI32(static_cast<i32>(base));

            Vector squares = ISA::CompressU08(partners, ISA::Load(Detail::Iota.data()));

            const auto store = [&](const u32 part) {
                const auto records = ISA::Or(ISA::template ShiftLeftI32<24>(ISA::WidenU08U32(squares)), head);

                ISA::StoreUnaligned(tail + part, records);
            };

            store(0);

            for (u32 part = Lanes; part < count; part += Lanes) {
                squares = ISA::CompressU08(~u64 { 0 } << Lanes, squares);

                store(part);
            }

            return count;
        }

        template<const Array<u64, 64>& Masks, typename C>
        [[clang::noinline]]
        static void Pairs(
            const std::array<u64, 2>& pawns   ,
            const u64                 touched ,
            const Polarity            polarity,
                  C&                  out
        ) noexcept
        { Detail::Pairs<Compress, Masks>(pawns, touched, polarity, out); }

    };

    template<typename F>
    constexpr inline Lowering::Choice Derives = Lowering::Choice::None;

    template<ThreatMap M>
    constexpr inline Lowering::Choice Derives<Threats<M>> = Lowering::Choice::Threats;

    template<PairMask K>
    constexpr inline Lowering::Choice Derives<PawnPairs<K>> = Lowering::Choice::PawnPairs;

    namespace Detail
    {

        template<typename ISA, Lowering::Choice C, Lowering::Tier T>
        consteval auto BuiltOf()
        {
            using Tier = Lowering::Tier;

            constexpr bool Threat = C == Lowering::Choice::Threats;
            constexpr bool Pair   = C == Lowering::Choice::PawnPairs;
            constexpr bool Both   = T == Tier::Compress || T == Tier::Table || T == Tier::Lut;

            static_assert(!Threat || Both || T == Tier::Swizzle, "a threat tier is Compress, Swizzle, Table or Lut");
            static_assert(!Pair   || Both || T == Tier::Expand , "a pawn-pair tier is Compress, Expand, Table or Lut");

            constexpr bool Swizzles = requires { typename Swizzle<ISA>; };
            constexpr bool Tables   = requires { typename Table<ISA>; };

            if constexpr (Threat && T == Tier::Table && Tables)
                return std::type_identity<Table<ISA>> {};
            else if constexpr (Threat && T != Tier::Lut && Swizzles)
                return std::type_identity<Swizzle<ISA>> {};
            else if constexpr (Threat && T != Tier::Lut && Tables)
                return std::type_identity<Table<ISA>> {};
            else if constexpr (Pair && T == Tier::Compress && requires { typename Compress<ISA>; })
                return std::type_identity<Compress<ISA>> {};
            else if constexpr (Pair && T != Tier::Lut)
                return std::type_identity<Expand<ISA>> {};
            else return std::type_identity<MantaRay::Geometry::Lut> {};
        }

    }

    template<typename ISA, Lowering::Choice C, Lowering::Tier T>
    using TierFor = decltype(Detail::BuiltOf<ISA, C, T>())::type;

    template<typename ISA, typename F>
    using DerivationOf = TierFor<ISA, Derives<F>, Lowering::ChoiceOf(Derives<F>, Lowering::CapabilitiesOf<ISA>())>;

}

#endif //MANTARAY_BACKEND_KERNEL_GEOMETRY_H
