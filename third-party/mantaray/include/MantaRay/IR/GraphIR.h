//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_IR_GRAPHIR_H
#define MANTARAY_IR_GRAPHIR_H

#include <algorithm>
#include <limits>
#include <string_view>

#include "../Common.h"

namespace MantaRay::IR
{

    constexpr inline u16 Version = 1;

    constexpr inline s00 MaxInputs = 2;

#if defined(MANTARAY_CONSTEXPR_STEPS)
    constexpr inline s00 StepLimit = MANTARAY_CONSTEXPR_STEPS;
#else
    constexpr inline s00 StepLimit = 1048576;
#endif

    constexpr inline s00 StepsPerNode  = 450;
    constexpr inline s00 MaxIndex      = 0xFFFE;
    constexpr inline s00 MaxFeatureSet = 32;
    constexpr inline s00 NameSize      = 48;

    enum class Op : u08 {
        None,
        Input, Parameter, Constant,
        SparseMatmul, Matmul,
        Add, Sub, Mul, Min, Max, Pow,
        Clamp, Unary,
        ShiftRight, ShiftLeft, Divide,
        Dequantize, Wrap, Assume, Verify,
        Slice, Concat, Select, Sum
    };

    constexpr inline Array<std::string_view, 25> OpNames {
        "None",
        "Input", "Parameter", "Constant",
        "SparseMatmul", "Matmul",
        "Add", "Sub", "Mul", "Min", "Max", "Pow",
        "Clamp", "Unary",
        "ShiftRight", "ShiftLeft", "Divide",
        "Dequantize", "Wrap", "Assume", "Verify",
        "Slice", "Concat", "Select", "Sum"
    };

    static_assert(OpNames.size() == static_cast<s00>(Op::Sum) + 1, "OpNames must list every Op");

    constexpr std::string_view Name(const Op op) { return OpNames[static_cast<s00>(op)]; }

    enum class Function : u08 {
        None,
        Abs, Sign, Exp, Log, Sqrt, Reciprocal, Sigmoid, Tanh,
        Sin, Cos, Tan, Sinh, Cosh, Round, Truncate, IsPositive, IsZero, IsNonNegative
    };

    enum class Perspective : u08 { None, Stm, Ntm, Shared };

    enum class DType : u08 { None, I08, U08, I16, U16, I32, I64, F32 };

    enum class Bound : u08 { None, Low, High, Both };

    enum class Role : u08 { None, Weights, Biases, Values, Folded };

    enum class Rounding : u08 { None, HalfAway, Truncate };

    enum class Order : u08 { None, ColumnMajor, RowMajor, BucketMajor, Blocked };

    enum class Reduction : u08 { Sequential, BiasFirstFma, Lanes16 };

    enum class Kind : u08 { None, FeatureSet, Selector };

    enum class ItemKind : u08 { None, Tensor, Bytes, Block, Constant, Text };

    enum class Encoding : u08 { Raw, Leb128 };

    enum class Padding : u08 { Bullet, Exact, Zeros };

    struct Sizes
    {

        u32 Nodes    = 0;
        u32 Tensors  = 0;
        u32 Bindings = 0;
        u32 Heads    = 0;
        u32 Items    = 0;
        u32 Files    = 0;

        constexpr bool operator ==(const Sizes&) const = default;

    };

    static_assert(sizeof(Sizes) == 6 * sizeof(u32), "Sizes is a template argument and must have no padding");

    struct Node
    {

        Op          Operation   = Op::None;
        u08         InputCount  = 0;
        Bound       Bounds      = Bound::None;
        Function    Function    = Function::None;
        Perspective Perspective = Perspective::None;
        DType       Type        = DType::None;
        Reduction   Reduction   = Reduction::Sequential;

        u16 Tensor  = 0;
        u16 Binding = 0;
        u16 Shift   = 0;
        u16 File    = 0;
        u16 Line    = 0;
        u16 Column  = 0;

        Array<u16, MaxInputs> Inputs {};

        u32 Size   = 0;
        u32 Begin  = 0;
        u32 End    = 0;
        u32 Offset = 0;

        Rational Low  {};
        Rational High {};

        constexpr bool operator ==(const Node&) const = default;

    };

    struct Layout
    {

        Order Order   = Order::None;
        u16   Buckets = 0;
        u16   Block   = 0;

        constexpr bool operator ==(const Layout&) const = default;

    };

    struct Tensor
    {

        Role     Role     = Role::None;
        DType    Type     = DType::None;
        DType    Stored   = DType::None;
        Rounding Rounding = Rounding::None;
        Layout   Layout   {};

        u16 File   = 0;
        u16 Line   = 0;
        u16 Column = 0;

        u16 Base   = 0;
        u16 Factor = 0;

        u32 Rows    = 0;
        u32 Columns = 0;

        Rational Quantization {};
        Rational ClipLow      {};
        Rational ClipHigh     {};

        constexpr bool operator ==(const Tensor&) const = default;

    };

    struct Head
    {

        u16      Node  = 0;
        Rational Scale {};

        constexpr bool operator ==(const Head&) const = default;

    };

    struct Item
    {

        ItemKind Kind   = ItemKind::None;
        u16      Tensor = 0;
        u16      Span   = 0;
        u32      Count  = 0;
        u64      Value  = 0;

        constexpr bool operator ==(const Item&) const = default;

    };

    struct File
    {

        Encoding Encoding = Encoding::Raw;
        Padding  Padding  = Padding::Bullet;

        constexpr bool operator ==(const File&) const = default;

    };

    struct Binding
    {

        Kind Kind        = Kind::None;
        bool Shared      = false;
        bool Cached      = false;
        bool Incremental = true;
        u16  Trigger     = 0;

        u32 InputSize  = 0;
        u32 MaxActive  = 0;
        u32 MaxChanges = 0;
        u32 Count      = 0;

        constexpr bool operator ==(const Binding&) const = default;

    };

    enum class FaultCode : u08 {
        None,
        SizeMismatch, InputSize, SliceOutside, OddSize, BucketSplit, BoundOrder, SparseOperand,
        IndexCapacity, FeatureSetCapacity, StepBudget,
        TensorNotSaved, TensorSavedTwice, TensorUnused, FoldShape, ReductionDomain
    };

    struct Fault
    {

        FaultCode Code      = FaultCode::None;
        Op        Operation = Op::None;
        u16       File      = 0;
        u16       Line      = 0;
        u16       Column    = 0;

        Array<i64, 3> Values {};

        constexpr bool operator ==(const Fault&) const = default;

    };

    constexpr Fault operator |(const Fault& left, const Fault& right)
    {
        return left.Code != FaultCode::None ? left : right;
    }

    using FileName = Array<char, NameSize>;

    template<Sizes S>
    struct Graph
    {

        constexpr static Sizes Size = S;

        constexpr static u32 NodeCount   = S.Nodes  ;
        constexpr static u32 TensorCount = S.Tensors;
        constexpr static u32 HeadCount   = S.Heads  ;
        constexpr static u32 ItemCount   = S.Items  ;

        u16 Version = IR::Version;

        File  File  {};
        Fault Fault {};

        Array<Binding , S.Bindings> Bindings {};
        Array<Head    , S.Heads   > Heads    {};
        Array<Item    , S.Items   > Items    {};
        Array<Tensor  , S.Tensors > Tensors  {};
        Array<Node    , S.Nodes   > Nodes    {};
        Array<FileName, S.Files   > Files    {};

        constexpr bool operator ==(const Graph&) const = default;

    };

    template<typename G>
    constexpr std::string_view FileOf(const G& graph, const u16 file)
    {
        if (file == 0 || file > graph.Files.size()) return {};

        const FileName& name = graph.Files[file - 1];

        s00 length = 0;

        while (length < name.size() && name[length] != '\0') length++;

        return { name.data(), length };
    }

    template<DType T>
    using ElementOf = At<static_cast<s00>(T), void, i08, u08, i16, u16, i32, i64, f32>;

    constexpr s00 BytesOf(const DType type)
    {
        constexpr Array<s00, 8> Bytes { 0, 1, 1, 2, 2, 4, 8, 4 };

        return Bytes[static_cast<s00>(type)];
    }

    constexpr bool IsFloat(const DType type) { return type == DType::F32; }

    constexpr Interval RangeOf(const DType type)
    {
        switch (type) {
            case DType::I08: return { .Min = std::numeric_limits<i08>::min(), .Max = std::numeric_limits<i08>::max() };
            case DType::U08: return { .Min = 0                              , .Max = std::numeric_limits<u08>::max() };
            case DType::I16: return { .Min = std::numeric_limits<i16>::min(), .Max = std::numeric_limits<i16>::max() };
            case DType::U16: return { .Min = 0                              , .Max = std::numeric_limits<u16>::max() };
            case DType::I32: return { .Min = std::numeric_limits<i32>::min(), .Max = std::numeric_limits<i32>::max() };
            default        : return { .Min = std::numeric_limits<i64>::min(), .Max = std::numeric_limits<i64>::max() };
        }
    }

    constexpr DType StorageOf(const Interval range)
    {
        if (Fits<u08>(range)) return DType::U08;
        if (Fits<i08>(range)) return DType::I08;
        if (Fits<i16>(range)) return DType::I16;
        if (Fits<u16>(range)) return DType::U16;
        if (Fits<i32>(range)) return DType::I32;

        return DType::I64;
    }

    constexpr Interval BoundsOf(const Tensor& tensor)
    {
        if (IsFloat(tensor.Type) || !Defined(tensor.ClipLow)) return RangeOf(tensor.Type);

        const Rational low  = tensor.ClipLow  * tensor.Quantization;
        const Rational high = tensor.ClipHigh * tensor.Quantization;

        const bool nearest = tensor.Rounding != Rounding::Truncate;

        const i64 lower = nearest ? RoundHalfAway(low ) : Ceil (low );
        const i64 upper = nearest ? RoundHalfAway(high) : Floor(high);

        const Interval type = RangeOf(tensor.Type);

        return { .Min = std::max(lower, type.Min), .Max = std::min(upper, type.Max) };
    }

    constexpr s00 ElementsOf(const Tensor& tensor) { return s00 { tensor.Rows } * tensor.Columns; }

    template<typename G>
    constexpr Interval TensorBounds(const G& graph, const u16 tensor)
    {
        const Tensor& spec = graph.Tensors[tensor];

        if (spec.Role != Role::Folded) return BoundsOf(spec);

        const Interval base   = TensorBounds(graph, static_cast<u16>(spec.Base   - 1));
        const Interval factor = TensorBounds(graph, static_cast<u16>(spec.Factor - 1));

        return base + factor;
    }

    struct RealRange
    {

        bool Clipped = false;
        f64  Low     = 0;
        f64  High    = 0;

    };

    template<typename G>
    constexpr RealRange TensorReals(const G& graph, const u16 tensor)
    {
        const Tensor& spec = graph.Tensors[tensor];

        if (spec.Role == Role::Folded) {
            const RealRange base   = TensorReals(graph, static_cast<u16>(spec.Base   - 1));
            const RealRange factor = TensorReals(graph, static_cast<u16>(spec.Factor - 1));

            return {
                .Clipped = base.Clipped && factor.Clipped,
                .Low     = base.Low  + factor.Low ,
                .High    = base.High + factor.High
            };
        }

        if (!Defined(spec.ClipLow)) return {};

        return { .Clipped = true, .Low = ToDouble(spec.ClipLow), .High = ToDouble(spec.ClipHigh) };
    }

}

#endif //MANTARAY_IR_GRAPHIR_H
