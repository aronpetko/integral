//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_BACKEND_KERNEL_ACCUMULATORTRANSFORM_H
#define MANTARAY_BACKEND_KERNEL_ACCUMULATORTRANSFORM_H

#include <algorithm>
#include <numeric>
#include <span>
#include <type_traits>

#include "../../Common.h"
#include "../../Lowering/Facts.h"
#include "../../Lowering/Program.h"

namespace MantaRay::Backend::Kernel
{

    namespace Detail
    {

        template<IR::DType T>
        using TransformOutput = std::conditional_t<T == IR::DType::U08, u08,
                                std::conditional_t<T == IR::DType::U16, u16,
                                std::conditional_t<T == IR::DType::I32, i32, i16>>>;

        consteval u32 TransformOutputs(const Lowering::Stage& stage)
        { return stage.Activation == Lowering::Activation::Pairwise ? stage.Width / 2 : stage.Width; }

        consteval Interval TransformRange(const Lowering::Stage& stage)
        {
            const Interval bounds { .Min = stage.Low, .Max = stage.High };

            if (stage.Activation == Lowering::Activation::Clamp       ) return bounds;
            if (stage.Activation == Lowering::Activation::SquaredClamp) return Square(bounds);

            return bounds * bounds;
        }

        template<const Lowering::Stage& S, typename T, typename O>
        [[clang::always_inline]]
        O TransformLane(const T left, const T right) noexcept
        {
            constexpr T   Low   = static_cast<T>(S.Low );
            constexpr T   High  = static_cast<T>(S.High);
            constexpr u16 Shift = S.Shift;

            const i32 a = std::clamp(left , Low, High);
            const i32 b = std::clamp(right, Low, High);

            if (S.Activation == Lowering::Activation::Clamp) return static_cast<O>(a >> Shift);

            if (S.Mode == Lowering::Mode::MulHi) return static_cast<O>(static_cast<i16>(a << (16 - Shift)) * b >> 16);

            return static_cast<O>(a * b >> Shift);
        }

        template<const Lowering::Stage& S, typename T, typename O>
        [[clang::always_inline]]
        void TransformPerspective(const std::span<const T* const> slots, O* output) noexcept
        {
            constexpr u32 Outputs = TransformOutputs(S);
            constexpr u32 Partner = S.Activation == Lowering::Activation::Pairwise ? Outputs : 0;
            constexpr u32 Block   = std::gcd(Outputs, static_cast<u32>(Alignment / sizeof(T)));

            static_assert(std::is_same_v<T, i16> || std::is_same_v<T, i32> , "accumulators are i16 or i32"       );
            static_assert(Fits<T>(Interval { .Min = S.Low, .Max = S.High }), "the clamp must fit the accumulator");

            for (u32 base = 0; base < Outputs; base += Block) {
                Array<T, Block> left  {};
                Array<T, Block> right {};

                for (const T* slot : slots)
                for (u32 i = 0; i < Block; i++) {
                    left [i] = WrapAdd(left [i], slot[          base + i]);
                    right[i] = WrapAdd(right[i], slot[Partner + base + i]);
                }

                for (u32 i = 0; i < Block; i++) output[base + i] = TransformLane<S, T, O>(left[i], right[i]);
            }
        }

        template<const auto& Program>
        consteval bool TransformSlots(const Lowering::Stage& stage)
        {
            for (s00 s = 0; s < Program.SlotCount && s < 32; s++)
                if (stage.Slots >> s & 1 && Program.Slots[s].Type != IR::DType::I16) return false;

            return true;
        }

        template<const Lowering::Stage& S, typename T>
        constexpr inline bool TransformVector = S.Vector && std::is_same_v<T, i16>;

        template<const Lowering::Stage& S, typename ISA>
        constexpr inline bool TransformPacked = S.Packed && Lowering::PackAbsorbable(TransformOutputs(S), ISA::Bytes);

        template<typename ISA>
        [[clang::always_inline]]
        ISA::Vector TransformSum(const std::span<const i16* const> slots, const s00 index) noexcept
        {
            typename ISA::Vector sum = ISA::LoadUnaligned(slots.front() + index);

            for (const i16* slot : slots.subspan(1)) sum = ISA::AddI16(sum, ISA::LoadUnaligned(slot + index));

            return sum;
        }

        template<const Lowering::Stage& S, bool Floor, typename ISA>
        [[clang::always_inline]]
        ISA::Vector TransformBounded(const typename ISA::Vector value) noexcept
        {
            const auto above = ISA::MinI16(value, ISA::BroadcastI16(static_cast<i16>(S.High)));

            if constexpr (Floor) return ISA::MaxI16(above, ISA::BroadcastI16(static_cast<i16>(S.Low)));
            else                 return above;
        }

        template<const Lowering::Stage& S, typename ISA>
        [[clang::always_inline]]
        ISA::Vector TransformClamped(const typename ISA::Vector value) noexcept
        {
            constexpr s00  Shift = S.Shift;
            constexpr bool Floor = !S.OneSided || Shift == 1;

            const auto clamped = TransformBounded<S, Floor, ISA>(value);

            if constexpr (Shift >= 16) return ISA::Zero();
            else if constexpr (Shift == 0) return clamped;
            else if constexpr (Shift == 1) {
                static_assert(S.Low >= 0 && S.High <= 16383, "a shift by one doubles the clamped value into an i16");

                return ISA::MulHiI16(ISA::template ShiftLeftI16<1>(clamped), ISA::BroadcastI16(1 << 14));
            } else return ISA::MulHiI16(clamped, ISA::BroadcastI16(static_cast<i16>(1 << (16 - Shift))));
        }

        template<const Lowering::Stage& S, typename ISA>
        [[clang::always_inline]]
        ISA::Vector TransformProduct(
            const typename ISA::Vector left ,
            const typename ISA::Vector right
        ) noexcept
        {
            if constexpr (S.Shift == 0) return ISA::Zero();
            else return ISA::MulHiI16(
                ISA::template ShiftLeftI16<16 - S.Shift>(TransformBounded<S, true, ISA>(left)),
                TransformBounded<S, !S.OneSided, ISA>(right)
            );
        }

        template<const Lowering::Stage& S, typename ISA>
        [[clang::always_inline]]
        ISA::Vector TransformLanes(const std::span<const i16* const> slots, const s00 base) noexcept
        {
            if constexpr (S.Activation == Lowering::Activation::Clamp)
                return TransformClamped<S, ISA>(TransformSum<ISA>(slots, base));
            else
                return TransformProduct<S, ISA>(
                    TransformSum<ISA>(slots, base),
                    TransformSum<ISA>(slots, TransformOutputs(S) + base)
                );
        }

        template<const Lowering::Stage& S>
        [[clang::always_inline]]
        void TransformTail(const std::span<const i16* const> slots, u08* output, const s00 begin) noexcept
        {
            constexpr s00 Outputs = TransformOutputs(S);
            constexpr s00 Partner = S.Activation == Lowering::Activation::Pairwise ? Outputs : 0;

            for (s00 i = begin; i < Outputs; i++) {
                i16 left  = 0;
                i16 right = 0;

                for (const i16* slot : slots) {
                    left  = WrapAdd(left , slot[          i]);
                    right = WrapAdd(right, slot[Partner + i]);
                }

                output[i] = TransformLane<S, i16, u08>(left, right);
            }
        }

        template<const Lowering::Stage& S, typename ISA>
        [[clang::always_inline]]
        ISA::Vector TransformPack(const typename ISA::Vector first, const typename ISA::Vector second) noexcept
        {
            if constexpr (TransformPacked<S, ISA>) return ISA::PackUnsignedI16(first, second);
            else                                   return ISA::PackU08        (first, second);
        }

        template<const Lowering::Stage& S, typename ISA>
        [[clang::always_inline]]
        void TransformVectors(const std::span<const i16* const> slots, u08* output) noexcept
        {
            constexpr s00 Outputs = TransformOutputs(S);
            constexpr s00 Whole   = Outputs / ISA::Bytes * ISA::Bytes;
            constexpr s00 Lanes   = ISA::Bytes / sizeof(i16);

            static_assert(Fits<i16>(Interval { .Min = S.Low, .Max = S.High }), "the clamp must fit the accumulator");
            static_assert(!TransformPacked<S, ISA> || Whole == Outputs, "the absorbed pack order fills whole vectors");

            for (s00 base = 0; base < Whole; base += ISA::Bytes) {
                const auto first  = TransformLanes<S, ISA>(slots, base        );
                const auto second = TransformLanes<S, ISA>(slots, base + Lanes);

                ISA::StoreUnaligned(output + base, TransformPack<S, ISA>(first, second));
            }

            if (Whole < Outputs) TransformTail<S>(slots, output, Whole);
        }

    }

    template<const auto& Program, s00 I, typename ISA>
    struct AccumulatorTransform
    {

        constexpr static Lowering::Stage Stage = Program.Stages[I];

        using Output = Detail::TransformOutput<Stage.Output>;

        constexpr static bool Packed = Detail::TransformPacked<Stage, ISA>;

        static_assert(Stage.Kind == Lowering::Kind::AccumulatorTransform, "the stage is not an AccumulatorTransform");
        static_assert(Stage.Shift < 32                                  , "transform shifts are below 32"           );
        static_assert(Fits<i32>(Detail::TransformRange(Stage))          , "transform products must fit i32"         );

        static_assert(
            Stage.Output == IR::DType::U08 || Stage.Output == IR::DType::U16 || Stage.Output == IR::DType::I16 ||
            Stage.Output == IR::DType::I32,
            "transforms pack to u08, u16, i16 or i32"
        );

        static_assert(
            Fits<Output>(ShiftDown(Detail::TransformRange(Stage), Stage.Shift)),
            "transform values must fit the output dtype"
        );

        static_assert(
            Stage.Mode != Lowering::Mode::MulHi ||
            Lowering::MulHiExact({ .Min = Stage.Low, .Max = Stage.High }, Stage.Shift),
            "MulHi needs an exact mulhi product"
        );

        static_assert(!Stage.Vector || Stage.Output == IR::DType::U08, "the vector form packs to u08");

        static_assert(
            !Stage.Vector || Stage.Activation == Lowering::Activation::Clamp ||
            (Stage.Activation == Lowering::Activation::Pairwise && Stage.Mode == Lowering::Mode::MulHi),
            "the vector form takes a Clamp or a MulHi Pairwise"
        );

        static_assert(!Stage.Vector || Detail::TransformSlots<Program>(Stage), "the vector form reads i16 slots");

        static_assert(!Stage.OneSided || Stage.Vector, "the one-sided clamp belongs to the vector form");

        static_assert(
            !Stage.OneSided ||
            Lowering::LowerClampAbsorbed(
                { .Min = Stage.Low, .Max = Stage.High },
                Stage.Shift,
                Stage.Activation == Lowering::Activation::Pairwise,
                Stage.Output
            ),
            "the one-sided clamp needs LowerClampAbsorbed: a lower bound of 0 and a product that packs to u08"
        );

        static_assert(!Stage.Packed || Stage.Vector, "the absorbed pack order belongs to the vector form");

        template<typename T>
        [[clang::always_inline]]
        static void Run(
            const std::span<const T* const> stm   ,
            const std::span<const T* const> ntm   ,
                  Output*                   output
        ) noexcept
        {
            constexpr u32 Outputs = Detail::TransformOutputs(Stage);

            static_assert(!Packed || Detail::TransformVector<Stage, T>, "only the vector form writes the pack order");

            if constexpr (Detail::TransformVector<Stage, T>) {
                Detail::TransformVectors<Stage, ISA>(stm, output          );
                Detail::TransformVectors<Stage, ISA>(ntm, output + Outputs);
            } else {
                Detail::TransformPerspective<Stage>(stm, output          );
                Detail::TransformPerspective<Stage>(ntm, output + Outputs);
            }
        }

    };

}

#endif //MANTARAY_BACKEND_KERNEL_ACCUMULATORTRANSFORM_H
