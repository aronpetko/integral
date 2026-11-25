//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_BACKEND_KERNEL_ACCUMULATORDOT_H
#define MANTARAY_BACKEND_KERNEL_ACCUMULATORDOT_H

#include <algorithm>
#include <bit>
#include <cassert>
#include <limits>
#include <span>
#include <type_traits>

#include "Pack.h"
#include "Reduce.h"
#include "Update.h"
#include "../../Common.h"
#include "../../IR/GraphIR.h"
#include "../../Lowering/Facts.h"
#include "../../Lowering/Program.h"

namespace MantaRay::Backend::ISA
{

    class Scalar;

}

namespace MantaRay::Backend::Kernel
{

    namespace Detail
    {

        template<typename F, typename ISA, typename T>
        constexpr inline bool Reads = false;

        template<typename ISA, typename T>
        constexpr inline bool Reads<MantaRay::Detail::Read<ISA, T>, ISA, T> = true;

        template<typename ISA, typename T, typename W, s00 R, s00 A>
        constexpr inline bool Reads<MantaRay::Detail::Update<ISA, T, W, R, A>, ISA, T> = true;

        template<typename F>
        constexpr inline bool Writes = false;

        template<typename ISA, typename T, typename W, s00 R, s00 A>
        constexpr inline bool Writes<MantaRay::Detail::Update<ISA, T, W, R, A>> = true;

    }

    constexpr inline s00 FusedUnroll = 4;

    template<const auto& Program, s00 I, typename ISA>
    struct AccumulatorDot
    {

        constexpr static Lowering::Stage Stage = Program.Stages[I];

        static_assert(Stage.Kind == Lowering::Kind::AccumulatorDot, "the stage is not an AccumulatorDot");

        constexpr static IR::DType SlotType = Program.Slots[std::countr_zero(Stage.Slots)].Type;

        static_assert(SlotType == IR::DType::I16 || SlotType == IR::DType::I32, "accumulators are i16 or i32");

        using Weight = std::conditional_t<Stage.Mode == Lowering::Mode::PackusDot, i08, i16>;
        using Slot   = std::conditional_t<SlotType   == IR::DType::I32           , i32, i16>;
        using Sum    = std::conditional_t<Stage.Wide                             , i64, i32>;

        constexpr static bool Linear  = Stage.Mode == Lowering::Mode::Linear;
        constexpr static bool Packus  = Stage.Mode == Lowering::Mode::PackusDot;
        constexpr static bool Lizard  = Stage.Mode == Lowering::Mode::Lizard;
        constexpr static bool Squared = Stage.Mode == Lowering::Mode::SquareFirst;
        constexpr static bool Widened = Stage.Mode == Lowering::Mode::Widened;
        constexpr static bool Scalar  = std::is_same_v<ISA, Backend::ISA::Scalar>;

        constexpr static bool Narrowed = std::is_same_v<Slot, i32> && Lizard && !Scalar &&
                                         Stage.Width % (ISA::Bytes / sizeof(i16)) == 0;

        constexpr static bool Direct = std::is_same_v<Slot, i16> && (Linear || Packus || Lizard || Squared || Widened);

        constexpr static bool Specialized = Narrowed || Direct;
        constexpr static bool Packed      = Specialized && Packus;

        constexpr static s00 K      = Stage.Chains;
        constexpr static s00 Stride = Packed ? ISA::Bytes : ISA::Bytes / (Narrowed ? sizeof(i16) : sizeof(Slot));

        static_assert(K > 0                      , "a dot product needs an accumulator"           );
        static_assert(!Packed || ISA::VNNI       , "packed dots need exact u08 x i08 dot products");
        static_assert(Stage.Width % Stride == 0  , "perspective rows must fill whole vectors"     );
        static_assert(Alignment % ISA::Bytes == 0, "ISA vector must divide 64 bytes"              );

        static_assert(
            !(std::is_same_v<Slot, i32> && Lizard) || Fits<i16>({ .Min = Stage.Low, .Max = Stage.High }),
            "an i32-slot Lizard stage narrows to i16, which LizardExact guarantees: both clamp bounds fit i16"
        );

        static_assert(
            !(Direct && Squared) || Lowering::SquareFitsI16({ .Min = Stage.Low, .Max = Stage.High }),
            "a SquareFirst stage squares in i16, which SquareFitsI16 guarantees"
        );

        consteval static s00 Block(const s00 vectors, const s00 chains, const s00 target)
        {
            for (s00 block = target; block < vectors; block++)
                if (vectors % block == 0 && 2 * block % chains == 0) return block;

            return vectors;
        }

        template<typename L, typename R>
        [[clang::always_inline]]
        static ISA::Vector Fetch(const L& white, const R& black, const u32 slot, const u32 block) noexcept
        {
            if constexpr (std::is_same_v<L, R> && !Detail::Writes<L>) return (slot == 0 ? white : black)(block);

            if (slot == 0) return white(block);

            return black(block);
        }

        [[clang::always_inline]]
        static ISA::Vector Clamp(typename ISA::Vector value) noexcept
        {
            constexpr i16 Low  = static_cast<i16>(std::max<i64>(Stage.Low , std::numeric_limits<i16>::min()));
            constexpr i16 High = static_cast<i16>(std::min<i64>(Stage.High, std::numeric_limits<i16>::max()));

            if (Low  > std::numeric_limits<i16>::min()) value = ISA::MaxI16(value, ISA::BroadcastI16(Low ));
            if (High < std::numeric_limits<i16>::max()) value = ISA::MinI16(value, ISA::BroadcastI16(High));

            return value;
        }

        [[clang::always_inline]]
        static ISA::Vector Accumulate(
            const typename ISA::Vector sum   ,
            const typename ISA::Vector x     ,
            const typename ISA::Vector weight
        ) noexcept
        {
            if (Lizard) return ISA::AddI32(sum, ISA::MaddI16(ISA::MulLoI16(x, weight), x));

            if (Squared) return ISA::AddI32(sum, ISA::MaddI16(ISA::MulLoI16(x, x), weight));

            if (Widened) {
                const auto even = ISA::BroadcastI32(1);
                const auto odd  = ISA::BroadcastI32(1 << 16);

                const auto low  = ISA::MulLoI32(ISA::MaddI16(x, ISA::MulLoI16(weight, even)), ISA::MaddI16(x, even));
                const auto high = ISA::MulLoI32(ISA::MaddI16(x, ISA::MulLoI16(weight, odd )), ISA::MaddI16(x, odd ));

                return ISA::AddI32(sum, ISA::AddI32(low, high));
            }

            return ISA::AddI32(sum, ISA::MaddI16(x, weight));
        }

        template<typename L, typename R>
        [[clang::always_inline]]
        static i64 Vectorized(const L& white, const R& black, const u08 stm, const Weight* const weights) noexcept
        {
            constexpr u32 Lanes   = ISA::Bytes / sizeof(Slot);
            constexpr u32 Vectors = Stage.Width / Stride;
            constexpr u32 Step    = Detail::Writes<L> || Detail::Writes<R> ? Block(Vectors, K, FusedUnroll) : Vectors;

            Array<typename ISA::Vector, K> sums;

            typename ISA::Vector pending {};

            UNROLL(full)
            for (s00 k = 0; k < K; k++) sums[k] = ISA::Zero();

            UNROLL(disable)
            for (u32 v = 0; v < Vectors; v += Step)
            UNROLL(full)
            for (u32 j = 0; j < Step; j++)
            UNROLL(full)
            for (u32 slot = 0; slot < 2; slot++) {
                const u32  i      = (v + j) * Stride;
                const u32  block  = i / Lanes;
                const s00  k      = (2 * j + slot) % K;
                const auto weight = ISA::Load(weights + (slot ^ stm) * Stage.Width + i);

                if (Packed) {
                    const auto low  = Fetch(white, black, slot, block    );
                    const auto high = Fetch(white, black, slot, block + 1);

                    sums[k] = ISA::DotU08I08(sums[k], ISA::PackUnsignedI16(low, high), weight);
                } else if (Narrowed) {
                    const auto low  = Fetch(white, black, slot, block    );
                    const auto high = Fetch(white, black, slot, block + 1);

                    sums[k] = Accumulate(sums[k], Clamp(ISA::PackI16(low, high)), weight);
                } else if (Scalar && (Detail::Writes<L> || Detail::Writes<R>)) {
                    if (slot == 0) {
                        const auto own   = Fetch(white, black, 0, block);
                        const auto other = Fetch(white, black, 1, block);

                        sums[k] = Accumulate(sums[k], Clamp(own), weight);

                        pending = Clamp(other);
                    } else sums[k] = Accumulate(sums[k], pending, weight);
                } else sums[k] = Accumulate(sums[k], Clamp(Fetch(white, black, slot, block)), weight);
            }

            if (Stage.Wide) return ReduceI64<ISA, K>(sums);

            return ReduceI32<ISA, K>(sums);
        }

        [[clang::always_inline]]
        static Sum Term(const Slot value, const Weight weight) noexcept
        {
            const i64 x = std::clamp<i64>(value, Stage.Low, Stage.High);

            if (Stage.Activation == Lowering::Activation::SquaredClamp) return static_cast<Sum>(x * x * weight);

            return static_cast<Sum>(x * weight);
        }

        template<typename L, typename R>
        [[clang::always_inline]]
        static i64 Generic(const L& white, const R& black, const u08 stm, const Weight* const weights) noexcept
        {
            constexpr u32 Lanes  = ISA::Bytes / sizeof(Slot);
            constexpr u32 Blocks = Stage.Width / Lanes;

            Array<Sum, K> chains {};

            for (u32 block = 0; block < Blocks; block++)
            for (u32 slot  = 0; slot  < 2     ; slot++) {
                const auto    values = std::bit_cast<Array<Slot, Lanes>>(Fetch(white, black, slot, block));
                const Weight* row    = weights + (slot ^ stm) * Stage.Width + block * Lanes;

                for (u32 lane = 0; lane < Lanes; lane++) chains[lane % K] += Term(values[lane], row[lane]);
            }

            i64 sum = 0;

            for (const Sum chain : chains) sum += chain;

            return sum;
        }

        template<typename W>
        static void Assign(const std::span<const W> logical, Weight* const packed) noexcept
        {
            constexpr u32 Inputs = 2 * Stage.Width;

            assert(logical.size() == s00 { Stage.Buckets } * Inputs);

            for (u32 o = 0; o < Stage.Buckets; o++)
            for (u32 i = 0; i < Inputs       ; i++)
                packed[o * Inputs + i] = static_cast<Weight>(logical[o * Inputs + LogicalIndex<ISA, Packed>(i)]);
        }

        template<typename L, typename R>
        [[clang::always_inline]]
        static i64 Run(const L& white, const R& black, const u08 stm, const Weight* const weights) noexcept
        {
            static_assert(
                Detail::Reads<L, ISA, Slot> && Detail::Reads<R, ISA, Slot>,
                "each side is a Read or Update functor of this ISA over the stage's accumulators"
            );

            assert(stm < 2);

            const L localWhite = white;
            const R localBlack = black;

            if (Specialized) return Vectorized(localWhite, localBlack, stm, weights);

            return Generic(localWhite, localBlack, stm, weights);
        }

        template<typename L, typename R>
        [[clang::always_inline]]
        static i64 Run(const L& stm, const R& ntm, const Weight* const weights) noexcept
        { return Run(stm, ntm, 0, weights); }

    };

}

#endif //MANTARAY_BACKEND_KERNEL_ACCUMULATORDOT_H
