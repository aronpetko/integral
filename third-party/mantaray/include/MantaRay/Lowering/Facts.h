//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_LOWERING_FACTS_H
#define MANTARAY_LOWERING_FACTS_H

#include <algorithm>
#include <limits>

#include "../Common.h"
#include "../IR/Analysis.h"
#include "../IR/GraphIR.h"

namespace MantaRay::Lowering
{

    constexpr inline i64 SaturationLimit = std::numeric_limits<i16>::max();

    constexpr bool Licenses(const IR::Provenance provenance)
    { return provenance == IR::Provenance::Proven || provenance == IR::Provenance::LoadVerified; }

    constexpr Interval Licensed(const IR::Fact& fact)
    { return Licenses(fact.Provenance) ? fact.Range : IR::RangeOf(fact.Storage); }

    constexpr bool MaddExact(const Interval x, const Interval w)
    {
        return Fits<i16>(x) && Fits<i16>(w) && Fits<i32>(Repeat(x * w, 2));
    }

    constexpr bool MaddubsExact(const Interval x, const Interval w)
    {
        return Fits<u08>(x) && Fits<i08>(w) && Fits<i16>(Repeat(x * w, 2));
    }

    constexpr bool MaddubsPairExact(const Interval x, const Interval w)
    {
        return Fits<u08>(x) && Fits<i08>(w) && Fits<i16>(Repeat(x * w, 4));
    }

    constexpr bool VnniExact(const Interval x, const Interval w) { return Fits<u08>(x) && Fits<i08>(w); }

    constexpr bool NarrowsTo16(const Interval x, const Interval w)
    {
        return Fits<i16>(x) && Fits<i16>(w) && MaddExact(x, w);
    }

    constexpr bool LizardExact(const Interval x, const Interval w)
    {
        return Fits<i16>(x) && Fits<i16>(w) && Fits<i16>(x * w) && Fits<i32>(Repeat(Square(x) * w, 2));
    }

    constexpr bool SquareFitsI16(const Interval x) { return Fits<i16>(Square(x)); }

    constexpr bool PackusIsClippedReLU(const i64 low, const i64 high) { return low == 0 && high == 255; }

    constexpr bool MulHiExact(const Interval x, const u16 shift)
    {
        return x.Min >= 0 && shift <= 16 && Fits<i16>(ShiftUp(x, 16 - shift));
    }

    constexpr bool ModularSum(const IR::Node& root) { return root.Operation == IR::Op::Wrap; }

    constexpr bool ModularSum(const IR::DType wrap, const IR::Op requant)
    {
        return wrap == IR::DType::I32 && requant == IR::Op::None;
    }

    constexpr bool LowerClampAbsorbed(
        const Interval  clamp   ,
        const u16       shift   ,
        const bool      pairwise,
        const IR::DType output
    )
    {
        const Interval product = pairwise ? clamp * clamp : clamp;

        return clamp.Min == 0 && ShiftDown(product, shift).Max <= 255 && output == IR::DType::U08;
    }

    constexpr bool NnzCmpgtSafe(const Interval x) { return x.Min >= 0 && x.Max <= 127; }

    namespace Detail
    {

        struct Chain
        {

            bool     Valid = false;
            Interval Range {};

        };

        template<s00 N, s00 H>
        constexpr u16 OnlyUser(
            const std::array<IR::Node, N>& nodes,
            const std::array<IR::Head, H>& heads,
            const u16                      node
        )
        {
            u16 user  = 0;
            u16 count = 0;

            for (s00 h = 0; h < H; h++)
                if (heads[h].Node == node) count++;

            for (s00 i = 0; i < N; i++) {
                bool reads = false;

                for (s00 k = 0; k < nodes[i].InputCount; k++) reads = reads || nodes[i].Inputs[k] == node;

                if (!reads) continue;

                user = static_cast<u16>(i);
                count++;
            }

            return count == 1 ? user : 0;
        }

        template<s00 N>
        constexpr bool Constant(
            const std::array<IR::Node, N>& nodes,
            const std::array<IR::Fact, N>& facts,
            const u16                      node
        )
        {
            return nodes[node].Operation == IR::Op::Constant && facts[node].Domain == IR::Domain::Constant;
        }

        template<s00 N>
        constexpr Interval Bound(
            const std::array<IR::Node, N>& nodes,
            const std::array<IR::Fact, N>& facts,
            const u16                      node
        )
        {
            const IR::Node& spec     = nodes[node];
            const Rational  constant = nodes[spec.Inputs[1]].Low;
            const i64       value    = spec.Operation == IR::Op::Mul ? constant.Numerator
                                                                     : Floor(constant * facts[spec.Inputs[0]].Scale);

            return { .Min = value, .Max = value };
        }

        template<s00 N, s00 H>
        constexpr Chain Evaluate(
            const std::array<IR::Node, N>& nodes,
            const std::array<IR::Fact, N>& facts,
            const std::array<IR::Head, H>& heads,
            const u16                      value,
            const u16                      use  ,
            const Interval                 range
        )
        {
            u16      input   = value;
            u16      node    = use;
            Interval current = range;

            while (node != 0 && facts[node].Domain == IR::Domain::Integer) {
                const IR::Node& spec = nodes[node];

                const bool square   = spec.Operation == IR::Op::Mul && spec.InputCount == 2 &&
                                      spec.Inputs[0] == input && spec.Inputs[1] == input;
                const bool constant = spec.InputCount == 2 && spec.Inputs[0] == input &&
                                      Constant(nodes, facts, spec.Inputs[1]);
                const bool unary    = spec.InputCount == 1 && spec.Inputs[0] == input;

                const Interval operand = constant ? Bound(nodes, facts, node) : Interval {};

                if (square) current = Square(current);
                else if (constant && spec.Operation == IR::Op::Mul) current = current * operand;
                else if (constant && spec.Operation == IR::Op::Add) current = current + operand;
                else if (unary && spec.Operation == IR::Op::ShiftRight) current = ShiftDown(current, spec.Shift);
                else if (unary && spec.Operation == IR::Op::ShiftLeft ) current = ShiftUp  (current, spec.Shift);
                else if (unary && spec.Operation == IR::Op::Clamp) {
                    const Rational scale = facts[input].Scale;

                    const bool lower = spec.Bounds == IR::Bound::Low  || spec.Bounds == IR::Bound::Both;
                    const bool upper = spec.Bounds == IR::Bound::High || spec.Bounds == IR::Bound::Both;

                    const i64 low  = lower ? Floor(spec.Low  * scale) : std::numeric_limits<i64>::min();
                    const i64 high = upper ? Floor(spec.High * scale) : std::numeric_limits<i64>::max();

                    current = {
                        .Min = std::min(std::max(current.Min, low), high),
                        .Max = std::min(std::max(current.Max, low), high)
                    };
                } else return {};

                if (spec.Operation == IR::Op::Clamp) return { .Valid = true, .Range = current };

                input = node;
                node  = OnlyUser(nodes, heads, node);
            }

            return {};
        }

        template<s00 N, s00 H>
        constexpr bool Settled(
            const std::array<IR::Node, N>& nodes,
            const std::array<IR::Fact, N>& facts,
            const std::array<IR::Head, H>& heads,
            const u16                      value,
            const u16                      use  ,
            const i64                      threshold
        )
        {
            const Interval range = facts[value].Range;

            const Chain high = Evaluate(nodes, facts, heads, value, use, { .Min = threshold, .Max = range.Max });
            const Chain low  = Evaluate(nodes, facts, heads, value, use, { .Min = range.Min, .Max = -threshold });

            const bool above = range.Max <= threshold  || (high.Valid && high.Range.Min == high.Range.Max);
            const bool below = range.Min >= -threshold || (low .Valid && low .Range.Min == low .Range.Max);

            return above && below;
        }

    }

    template<s00 N, s00 H>
    constexpr i64 SaturationThreshold(
        const std::array<IR::Node, N>& nodes,
        const std::array<IR::Fact, N>& facts,
        const std::array<IR::Head, H>& heads,
        const u16                      value,
        const u16                      use
    )
    {
        const IR::Fact& fact = facts[value];

        if (fact.Domain != IR::Domain::Integer || !Licenses(fact.Provenance)) return -1;

        if (!Detail::Evaluate(nodes, facts, heads, value, use, fact.Range).Valid) return -1;

        if (!Detail::Settled(nodes, facts, heads, value, use, SaturationLimit)) return -1;

        i64 low  = 0;
        i64 high = SaturationLimit;

        while (low < high) {
            const i64 middle = low + (high - low) / 2;

            if (Detail::Settled(nodes, facts, heads, value, use, middle)) high = middle;
            else low = middle + 1;
        }

        return low;
    }

    template<s00 N, s00 H>
    constexpr bool SaturationAbsorbed(
        const std::array<IR::Node, N>& nodes,
        const std::array<IR::Fact, N>& facts,
        const std::array<IR::Head, H>& heads,
        const u16                      value,
        const u16                      use
    )
    {
        return SaturationThreshold(nodes, facts, heads, value, use) >= 0;
    }

}

#endif //MANTARAY_LOWERING_FACTS_H
