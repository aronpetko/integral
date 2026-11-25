//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_BACKEND_KERNEL_ROWINDEX_H
#define MANTARAY_BACKEND_KERNEL_ROWINDEX_H

#include <bit>

#include "../../Common.h"
#include "../../FeatureSet/Threats.h"
#include "../../Lowering/Choices.h"

namespace MantaRay::Backend::Kernel::RowIndex
{

    namespace Detail
    {

        template<typename F>
        constexpr inline bool Threat = false;

        template<ThreatMap M>
        constexpr inline bool Threat<Threats<M>> = true;

        ALIGN_16 constexpr inline Array<u08, 16> Bits { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4 };

        template<typename ISA, typename F>
        constexpr inline bool Gathers =
            Threat<F> && Lowering::CapabilitiesOf<ISA>().Gather &&
            Lowering::ChoiceOf(Lowering::Choice::RowIndex, Lowering::CapabilitiesOf<ISA>()) == Lowering::Tier::Gather;

        template<typename F>
        consteval bool Recorded()
        {
            using Change = F::Change;

            return std::bit_cast<u32>(Change { .Attacker = 1, .From = 2, .Attacked = 3, .To = 4 }) == 0x04030201;
        }

        template<typename F>
        consteval bool Signed()
        {
            return F::InputSize <= u32 { 1 } << 31 && F::NoRow == ~u32 { 0 };
        }

        template<typename ISA, typename F>
        [[clang::always_inline]]
        u32 IndexOf(const u08 side, const u32 key, const typename F::Change& change) noexcept
        {
            if constexpr (requires { F::template Index<ISA>(side, key, change); })
                return F::template Index<ISA>(side, key, change);
            else return F::Index(side, key, change);
        }

    }

    template<typename ISA, typename F>
    constexpr inline Lowering::Tier TierOf = Detail::Gathers<ISA, F> ? Lowering::Tier::Gather : Lowering::Tier::Scalar;

    template<typename ISA, typename F, typename Emit>
    [[clang::always_inline]]
    u32 Gather(
        const u08                       side   ,
        const u32                       key    ,
        const typename F::Change* const changes,
        const u32                       count  ,
              Emit&                     emit
    ) noexcept
    {
        using Vector = ISA::Vector;

        constexpr u32 Lanes = ISA::Bytes / sizeof(u32);

        static_assert(ISA::Gather && Detail::Threat<F>, "a gathered row index needs a Gather ISA and a threat map");
        static_assert(Detail::Recorded<F>(), "a threat record is {Attacker, From, Attacked, To} in byte order");
        static_assert(Detail::Signed<F>(), "every row index is below 2^31, so bit 31 marks NoRow alone");
        static_assert(std::endian::native == std::endian::little, "Pseudo's low word precedes its high word");

        const u08* pairs   = reinterpret_cast<const u08*>(F::Table.Pairs  .data());
        const u08* offsets = reinterpret_cast<const u08*>(F::Table.Offsets.data());
        const u08* pseudo  = reinterpret_cast<const u08*>(F::Table.Pseudo .data());

        const auto bytes  = ISA::BroadcastI32(0xFF);
        const auto eleven = ISA::BroadcastI32(11);
        const auto twelve = ISA::BroadcastI32(12);
        const auto word   = ISA::BroadcastI32(32);
        const auto both   = ISA::BroadcastI32(64);
        const auto nibble = ISA::BroadcastU08(0x0F);
        const auto ones   = ISA::BroadcastU08(1);
        const auto pair16 = ISA::BroadcastI16(1);
        const auto bits   = ISA::BroadcastU128(Detail::Bits.data());
        const auto orient = ISA::BroadcastI32(static_cast<i32>(56 * side ^ 7 * key));
        const auto flip   = ISA::BroadcastI32(6 * side);

        const auto counts = [&](const Vector value) {
            return ISA::AddI16(
                ISA::Shuffle16(bits, ISA::And(value, nibble)),
                ISA::Shuffle16(bits, ISA::And(ISA::template ShiftRightU32<4>(value), nibble))
            );
        };

        const auto flipped = [&](const Vector code) {
            const auto shifted = ISA::AddI32(code, flip);

            return ISA::SubI32(shifted, ISA::And(ISA::CompareGreaterI32(shifted, eleven), twelve));
        };

        u32 i = 0;

        for (; i + Lanes <= count; i += Lanes) {
            const auto record   = ISA::LoadUnaligned(changes + i);
            const auto from     = ISA::Xor(ISA::And(ISA::template ShiftRightU32< 8>(record), bytes), orient);
            const auto to       = ISA::Xor(ISA::template ShiftRightU32<24>(record), orient);
            const auto attacker = flipped(ISA::And(record, bytes));
            const auto attacked = flipped(ISA::And(ISA::template ShiftRightU32<16>(record), bytes));
            const auto below    = ISA::template ShiftRightU32<31>(ISA::CompareGreaterI32(to, from));
            const auto slot     = ISA::AddI32(
                ISA::template ShiftLeftI32<1>(ISA::AddI32(ISA::MulLoI32(attacker, twelve), attacked)),
                below
            );
            const auto row      = ISA::AddI32(ISA::template ShiftLeftI32<6>(attacker), from);

            const auto pair   = ISA::template GatherI32<4>(pairs  , slot);
            const auto offset = ISA::template GatherI32<4>(offsets, row );
            const auto low    = ISA::ShiftLeftVarI32(
                ISA::template GatherI32<8>(pseudo    , row),
                ISA::SubI32(word, ISA::MinI32(to, word))
            );
            const auto high   = ISA::ShiftLeftVarI32(
                ISA::template GatherI32<8>(pseudo + 4, row),
                ISA::SubI32(both, to)
            );

            const auto ordinal = ISA::MaddI16(ISA::MaddubsI16(ISA::AddI16(counts(low), counts(high)), ones), pair16);
            const auto indices = ISA::Or(
                ISA::AddI32(ISA::AddI32(pair, offset), ordinal),
                ISA::template ShiftRightI32<31>(pair)
            );

            alignas(Alignment) Array<u32, Lanes> lanes;

            ISA::Store(lanes.data(), indices);

            for (const u32 index : lanes) if (index != F::NoRow) emit(index);
        }

        return i;
    }

    template<typename ISA, typename F, Lowering::Tier T = TierOf<ISA, F>, typename Emit>
    [[clang::always_inline]]
    void Rows(
        const u08                       side   ,
        const u32                       key    ,
        const typename F::Change* const changes,
        const u32                       count  ,
              Emit&&                    emit
    ) noexcept
    {
        static_assert(T == Lowering::Tier::Gather || T == Lowering::Tier::Scalar, "a row index is Gather or Scalar");

        u32 i = 0;

        if constexpr (T == Lowering::Tier::Gather) i = Gather<ISA, F>(side, key, changes, count, emit);

        for (; i < count; i++) {
            const u32 index = Detail::IndexOf<ISA, F>(side, key, changes[i]);

            if (index != F::NoRow) emit(index);
        }
    }

}

#endif //MANTARAY_BACKEND_KERNEL_ROWINDEX_H
