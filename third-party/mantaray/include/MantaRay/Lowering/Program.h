//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_LOWERING_PROGRAM_H
#define MANTARAY_LOWERING_PROGRAM_H

#include <algorithm>
#include <string_view>

#include "../Common.h"
#include "../IR/Analysis.h"
#include "../IR/GraphIR.h"

namespace MantaRay::Lowering
{

    enum class Kind : u08 { None, AccumulatorDot, AccumulatorTransform, Dense, Reference, Pointwise };

    enum class Mode : u08 { None, Linear, PackusDot, Lizard, SquareFirst, Widened, MulHi, ZeroPoint };

    enum class Activation : u08 { None, Clamp, SquaredClamp, Pairwise, Other };

    enum class Dot : u08 { None, Dpbusd, Maddubs, Wide, Madd, MulLo, Fma, MulAdd };

    enum class Form : u08 { None, Sparse, Grouped, Broadcast, RowDot, Lanes, Serial, Generic };

    enum class Test : u08 { None, Positive, Nonzero };

    constexpr inline u32 SparseInputs = 512;

    constexpr inline Array<std::string_view, 6> KindNames {
        "None", "AccumulatorDot", "AccumulatorTransform", "Dense", "Reference", "Pointwise"
    };
    constexpr inline Array<std::string_view, 8> ModeNames {
        "None", "Linear", "PackusDot", "Lizard", "SquareFirst", "Widened", "MulHi", "ZeroPoint"
    };
    constexpr inline Array<std::string_view, 5> ActivationNames {
        "None", "Clamp", "SquaredClamp", "Pairwise", "Other"
    };
    constexpr inline Array<std::string_view, 8> DotNames {
        "None", "Dpbusd", "Maddubs", "Wide", "Madd", "MulLo", "Fma", "MulAdd"
    };
    constexpr inline Array<std::string_view, 8> FormNames {
        "None", "Sparse", "Grouped", "Broadcast", "RowDot", "Lanes", "Serial", "Generic"
    };
    constexpr inline Array<std::string_view, 3> TestNames { "None", "Positive", "Nonzero" };
    constexpr inline Array<std::string_view, 8> TypeNames { "none", "i08", "u08", "i16", "u16", "i32", "i64", "f32" };

    struct Slot
    {

        u16  Root        = 0;
        u16  Twin        = 0;
        u16  Trigger     = 0;
        u32  FeatureSets = 0;
        u32  Width       = 0;
        bool Bias        = false;
        bool Incremental = true;
        bool Shared      = false;

        IR::DType      Type        = IR::DType::None;
        IR::Dependence Perspective = IR::Dependence::None;

        constexpr bool operator ==(const Slot&) const = default;

    };

    struct Stage
    {

        Kind       Kind       = Kind::None;
        Mode       Mode       = Mode::None;
        Activation Activation = Activation::None;

        u16 Node   = 0;
        u32 Slots  = 0;
        u16 Chains = 0;
        u16 Shift  = 0;

        bool Wide   = false;
        bool Sparse = false;
        bool Fused  = false;

        i64 Low  = 0;
        i64 High = 0;

        u32 Width   = 0;
        u32 Rows    = 0;
        u32 Buckets = 1;

        IR::DType Input  = IR::DType::None;
        IR::DType Weight = IR::DType::None;
        IR::DType Output = IR::DType::None;

        Lowering::Activation Then      = Activation::None;
        i64                  ThenLow   = 0;
        i64                  ThenHigh  = 0;
        u16                  ThenShift = 0;

        IR::Reduction Reduction = IR::Reduction::Sequential;
        IR::Op        Requant   = IR::Op::None;
        IR::DType     Wrap      = IR::DType::None;
        bool          Unfused   = false;
        u16           Bias      = 0;
        Rational      Factor    {};

        Dot  Dot  = Dot::None;
        Form Form = Form::None;
        Test Test = Test::None;

        u32  Padded   = 0;
        u08  Tile     = 0;
        u08  Sets     = 0;
        bool Pairs    = false;
        bool OneSided = false;
        bool BiasInit = false;
        bool Narrow   = false;
        bool Vector   = false;
        bool Packed   = false;
        u08  Saturate = 0;

        i64 WeightLow  = 0;
        i64 WeightHigh = 0;
        i64 BiasLow    = 0;
        i64 BiasHigh   = 0;

        constexpr bool operator ==(const Stage&) const = default;

    };

    constexpr bool EpilogueFits32(const Stage& stage)
    {
        const bool real = IR::IsFloat(stage.Input) || IR::IsFloat(stage.Weight);

        const bool kinds = stage.Kind == Kind::Dense && !real && !stage.Wide;
        const bool steps = (stage.Requant == IR::Op::None || stage.Requant == IR::Op::ShiftRight) &&
                           (stage.Wrap    == IR::DType::None || stage.Wrap  == IR::DType::I32       );

        if (!kinds || !steps) return false;

        const Interval x    { .Min = stage.Low      , .Max = stage.High       };
        const Interval w    { .Min = stage.WeightLow, .Max = stage.WeightHigh };
        const Interval bias { .Min = stage.BiasLow  , .Max = stage.BiasHigh   };

        const bool     shifted = stage.Requant == IR::Op::ShiftRight;
        const bool     wrapped = stage.Wrap    == IR::DType::I32;
        const Interval exact   = Repeat(x * w, stage.Width);
        const Interval sum     = Fits<i32>(exact) ? exact : IR::RangeOf(IR::DType::I32);
        const Interval moved   = shifted ? ShiftDown(sum, stage.Shift) : sum;
        const Interval biased  = stage.Bias ? moved + bias : moved;

        if (!wrapped && !Fits<i32>(biased)) return false;

        const Interval value = wrapped ? IR::RangeOf(IR::DType::I32) : biased;
        const Interval then  { .Min = stage.ThenLow, .Max = stage.ThenHigh };

        const bool clamps  = stage.Then != Activation::None;
        const bool squares = stage.Then == Activation::SquaredClamp;

        if (clamps && (!Fits<i32>(then) || (squares && !Fits<i32>(Square(then))))) return false;

        const Interval bounded {
            .Min = std::min(std::max(value.Min, then.Min), then.Max),
            .Max = std::min(std::max(value.Max, then.Min), then.Max)
        };

        const Interval clamped = clamps  ? bounded         : value  ;
        const Interval squared = squares ? Square(clamped) : clamped;
        const Interval result  = ShiftDown(squared, stage.ThenShift);
        const Interval output  = IR::RangeOf(stage.Output);

        return result.Min >= output.Min && result.Max <= output.Max;
    }

    constexpr bool Woven(const Stage& stage, const s00 bytes)
    { return stage.Form == Form::Sparse && stage.Tile == 2 && bytes == Alignment; }

    constexpr bool BiasInit(const Stage& stage)
    {
        return stage.Kind == Kind::Dense && stage.Requant == IR::Op::None && EpilogueFits32(stage);
    }

    constexpr bool PackAbsorbable(const s00 outputs, const s00 bytes) { return bytes > 16 && outputs % bytes == 0; }

    template<s00 N>
    struct Program
    {

        Array<Slot , N> Slots  {};
        Array<Stage, N> Stages {};

        u16 SlotCount  = 0;
        u16 StageCount = 0;

        bool Fusable = false;

        constexpr bool operator ==(const Program&) const = default;

    };

}

#endif //MANTARAY_LOWERING_PROGRAM_H
