//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_BACKEND_KERNEL_POINTWISE_H
#define MANTARAY_BACKEND_KERNEL_POINTWISE_H

#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <cstring>
#include <limits>
#include <type_traits>
#include <utility>

#include "Dense.h"
#include "../../Common.h"
#include "../../IR/Analysis.h"
#include "../../IR/GraphIR.h"
#include "../../Lowering/Facts.h"
#include "../../Lowering/Lowering.h"

namespace MantaRay::Backend::Kernel
{

    enum class Source : u08 { Inline, Buffer, Slots, Parameter, Constant };

    struct Place
    {

        Source    Source = Source::Inline;
        IR::DType Type   = IR::DType::None;
        u32       Offset = 0;
        u32       Slots  = 0;

        constexpr bool operator ==(const Place&) const = default;

    };

    constexpr inline s00 DTypes = static_cast<s00>(IR::DType::F32) + 1;

    template<s00 N>
    struct Plan : Lowering::Program<N>
    {

        Array<IR::Node, N> Nodes  {};
        Array<IR::Fact, N> Facts  {};
        Array<Place   , N> Places {};
        Array<Place   , N> Copies {};
        Array<u16     , N> Owner  {};
        Array<u16     , N> Exits  {};
        Array<i64     , N> Limits {};

        Array<u32, DTypes> Values     {};
        Array<u32, DTypes> Parameters {};

        bool Supported = true;

    };

    static_assert(
        std::has_unique_object_representations_v<Array<u32, DTypes>>,
        "the arena sizes are a template argument and must have no padding"
    );

    template<Array<u32, DTypes> Sizes>
    struct Arena
    {

        alignas(Alignment) Array<i08, Sizes[static_cast<s00>(IR::DType::I08)]> I08;
        alignas(Alignment) Array<u08, Sizes[static_cast<s00>(IR::DType::U08)]> U08;
        alignas(Alignment) Array<i16, Sizes[static_cast<s00>(IR::DType::I16)]> I16;
        alignas(Alignment) Array<u16, Sizes[static_cast<s00>(IR::DType::U16)]> U16;
        alignas(Alignment) Array<i32, Sizes[static_cast<s00>(IR::DType::I32)]> I32;
        alignas(Alignment) Array<i64, Sizes[static_cast<s00>(IR::DType::I64)]> I64;
        alignas(Alignment) Array<f32, Sizes[static_cast<s00>(IR::DType::F32)]> F32;

        template<IR::DType T>
        [[clang::always_inline]]
        IR::ElementOf<T>* Data() noexcept
        {
            if constexpr (T == IR::DType::I08)      return I08.data();
            else if constexpr (T == IR::DType::U08) return U08.data();
            else if constexpr (T == IR::DType::I16) return I16.data();
            else if constexpr (T == IR::DType::U16) return U16.data();
            else if constexpr (T == IR::DType::I32) return I32.data();
            else if constexpr (T == IR::DType::I64) return I64.data();
            else if constexpr (T == IR::DType::F32) return F32.data();
            else {
                static_assert(false, "an arena holds i08, u08, i16, u16, i32, i64 or f32");

                std::unreachable();
            }
        }

        template<IR::DType T>
        [[clang::always_inline]]
        const IR::ElementOf<T>* Data() const noexcept
        {
            if constexpr (T == IR::DType::I08)      return I08.data();
            else if constexpr (T == IR::DType::U08) return U08.data();
            else if constexpr (T == IR::DType::I16) return I16.data();
            else if constexpr (T == IR::DType::U16) return U16.data();
            else if constexpr (T == IR::DType::I32) return I32.data();
            else if constexpr (T == IR::DType::I64) return I64.data();
            else if constexpr (T == IR::DType::F32) return F32.data();
            else {
                static_assert(false, "an arena holds i08, u08, i16, u16, i32, i64 or f32");

                std::unreachable();
            }
        }

    };

    template<s00 Slots, s00 Bindings>
    struct Sources
    {

        Array<const i16*, Slots   > Narrow  {};
        Array<const i32*, Slots   > Wide    {};
        Array<u32       , Bindings> Buckets {};

    };

    template<typename A, typename H>
    struct Scratch
    {

        A& Values;
        H& Held  ;

        template<IR::DType T>
        [[clang::always_inline]]
        auto* Data() noexcept { return Values.template Data<T>(); }

        template<IR::DType T>
        [[clang::always_inline]]
        const auto* Data() const noexcept { return std::as_const(Values).template Data<T>(); }

    };

    constexpr inline u32 KeptBlocks = 4;

    template<s00 N>
    consteval bool Whole(const Plan<N>& plan, const u16 node, const u32 bytes)
    {
        const u16   owner = plan.Owner [node];
        const Place spot  = plan.Places[node];
        const u32   size  = plan.Facts [node].Size;

        if (owner == 0 || spot.Source != Source::Buffer || spot.Type != IR::DType::U08) return false;

        if (plan.Stages[owner - 1].Kind != Lowering::Kind::Pointwise || !plan.Stages[owner - 1].Vector) return false;

        return spot.Offset % bytes == 0 && size % bytes == 0 && size <= KeptBlocks * bytes;
    }

    template<typename ISA, s00 N>
    consteval bool Held(const Plan<N>& plan, const s00 stage)
    {
        constexpr u32 Bytes = static_cast<u32>(ISA::Bytes);

        const Lowering::Stage& spec = plan.Stages[stage];

        if (!Holdable<ISA>(spec)) return false;

        const Place from = plan.Places[plan.Nodes[spec.Node].Inputs[0]];

        if (from.Source != Source::Buffer || from.Type != IR::DType::U08 || from.Offset % Bytes != 0) return false;

        for (u32 block = from.Offset; block < from.Offset + spec.Width; block += Bytes) {
            bool whole = false;

            for (s00 node = 0; node < N; node++) {
                const Place spot = plan.Places[node];

                whole = whole || (Whole(plan, static_cast<u16>(node), Bytes) && plan.Owner[node] <= stage &&
                                  spot.Offset <= block && block < spot.Offset + plan.Facts[node].Size);
            }

            if (!whole) return false;
        }

        return true;
    }

    template<typename ISA, s00 N>
    consteval bool Kept(const Plan<N>& plan, const u16 node)
    {
        constexpr u32 Bytes = static_cast<u32>(ISA::Bytes);

        if (!Whole(plan, node, Bytes)) return false;

        const Place spot = plan.Places[node];

        for (s00 stage = plan.Owner[node]; stage < plan.StageCount; stage++) {
            if (!Held<ISA>(plan, stage)) continue;

            const Place from = plan.Places[plan.Nodes[plan.Stages[stage].Node].Inputs[0]];
            const u32   end  = from.Offset + plan.Stages[stage].Width;

            if (from.Offset < spot.Offset + plan.Facts[node].Size && spot.Offset < end) return true;
        }

        return false;
    }

    template<typename ISA, s00 N>
    consteval bool Holds(const Plan<N>& plan)
    {
        for (s00 stage = 0; stage < plan.StageCount; stage++) if (Held<ISA>(plan, stage)) return true;

        return false;
    }

    namespace Detail
    {

        template<typename A, typename C, typename S>
        struct Frame
        {

                  A& Values   ;
            const C& Constants;
            const S& Sources  ;

        };

        template<s00 N>
        consteval i64 Operand(const Plan<N>& plan, const u16 node)
        {
            const IR::Node& spec     = plan.Nodes[node];
            const Rational  constant = plan.Nodes[spec.Inputs[1]].Low;

            if (spec.Operation == IR::Op::Mul) return constant.Numerator;

            return Floor(constant * plan.Facts[spec.Inputs[0]].Scale);
        }

        template<s00 N>
        consteval bool Link(const Plan<N>& plan, const u16 node, const u16 input)
        {
            const IR::Node& spec = plan.Nodes[node];
            const IR::Op    op   = spec.Operation;

            const bool scalar   = spec.InputCount == 2 && plan.Facts[spec.Inputs[1]].Domain == IR::Domain::Constant;
            const bool square   = op == IR::Op::Mul && spec.InputCount == 2 &&
                                  spec.Inputs[0] == input && spec.Inputs[1] == input;
            const bool constant = (op == IR::Op::Mul || op == IR::Op::Add) && scalar && spec.Inputs[0] == input;
            const bool unary    = (op == IR::Op::ShiftRight || op == IR::Op::ShiftLeft || op == IR::Op::Clamp) &&
                                  spec.InputCount == 1 && spec.Inputs[0] == input;

            return plan.Facts[node].Domain == IR::Domain::Integer && (square || constant || unary);
        }

        template<s00 N, s00 H>
        consteval u16 Closing(const Plan<N>& plan, const std::array<IR::Head, H>& heads, const u16 use)
        {
            const u16 owner = plan.Owner[use];

            u16 input = plan.Nodes[use].Inputs[0];
            u16 node  = use;

            while (node != 0 && plan.Owner[node] == owner && Link(plan, node, input)) {
                if (plan.Nodes[node].Operation == IR::Op::Clamp) return node;

                if (plan.Places[node].Source != Source::Inline) return 0;

                input = node;
                node  = Lowering::Detail::OnlyUser(plan.Nodes, heads, node);
            }

            return 0;
        }

        template<s00 N, s00 H, typename F>
        consteval void Walk(
            const Plan<N>&                 plan ,
            const std::array<IR::Head, H>& heads,
            const u16                      use  ,
            const u16                      end  ,
            const F&                       visit
        )
        {
            u16 node = use;

            visit(node);

            while (node != end) {
                node = Lowering::Detail::OnlyUser(plan.Nodes, heads, node);

                visit(node);
            }
        }

        template<s00 N>
        consteval Interval Next(const Plan<N>& plan, const u16 node, const Interval range)
        {
            const IR::Node& spec = plan.Nodes[node];

            if (spec.Operation == IR::Op::Mul && spec.Inputs[1] == spec.Inputs[0]) return Square(range);

            if (spec.Operation == IR::Op::Mul || spec.Operation == IR::Op::Add) {
                const i64      value    = Operand(plan, node);
                const Interval constant { .Min = value, .Max = value };

                return spec.Operation == IR::Op::Mul ? range * constant : range + constant;
            }

            if (spec.Operation == IR::Op::ShiftRight) return ShiftDown(range, spec.Shift);
            if (spec.Operation == IR::Op::ShiftLeft ) return ShiftUp  (range, spec.Shift);

            const Rational scale = plan.Facts[spec.Inputs[0]].Scale;

            const bool lower = spec.Bounds == IR::Bound::Low  || spec.Bounds == IR::Bound::Both;
            const bool upper = spec.Bounds == IR::Bound::High || spec.Bounds == IR::Bound::Both;

            const i64 low  = lower ? Floor(spec.Low  * scale) : std::numeric_limits<i64>::min();
            const i64 high = upper ? Floor(spec.High * scale) : std::numeric_limits<i64>::max();

            return Clamp(range, low, high);
        }

    }

    template<s00 N, s00 H>
    consteval void Saturate(Plan<N>& plan, const std::array<IR::Head, H>& heads)
    {
        Array<bool, N> chained {};

        for (s00 use = 0; use < N; use++) {
            const u16 owner = plan.Owner[use];

            if (chained[use] || owner == 0 || plan.Nodes[use].InputCount == 0) continue;

            if (plan.Stages[owner - 1].Kind != Lowering::Kind::Pointwise) continue;

            const u16 value = plan.Nodes[use].Inputs[0];
            const u16 end   = Detail::Closing(plan, heads, use);

            if (end == 0 || end == use || plan.Facts[value].Domain != IR::Domain::Integer) continue;

            bool wide = false;

            Detail::Walk(plan, heads, use, end, [&](const u16 node) {
                wide = wide || (node != end && !Fits<i32>(plan.Facts[node].Range));
            });

            if (!wide) continue;

            const i64 limit = Lowering::SaturationThreshold(plan.Nodes, plan.Facts, heads, value, use);

            if (limit <= 0) continue;

            const Interval start = Clamp(plan.Facts[value].Range, -limit, limit);

            Interval range   = start;
            bool     changed = false;

            Detail::Walk(plan, heads, use, end, [&](const u16 node) {
                range   = Detail::Next(plan, node, range);
                changed = changed || (node != end && Fits<i32>(range) && !Fits<i32>(plan.Facts[node].Range));
            });

            const auto proof = Lowering::Detail::Evaluate(plan.Nodes, plan.Facts, heads, value, use, start);

            if (!changed || !proof.Valid || proof.Range != range) continue;

            plan.Limits[use] = limit;

            plan.Stages[owner - 1].Saturate++;

            range = start;

            Detail::Walk(plan, heads, use, end, [&](const u16 node) {
                range = Detail::Next(plan, node, range);

                plan.Facts[node].Range = range;
                chained[node]          = true;
            });
        }
    }

    template<const auto& Program, s00 I, typename ISA>
    struct Elementwise
    {

        constexpr static Lowering::Stage Stage = Program.Stages[I];

        constexpr static bool Lanewise = Stage.Kind == Lowering::Kind::Pointwise && Stage.Vector;

        constexpr static Array<IR::Head, 0> Heads {};

        template<u16 Node>
        using Number = std::conditional_t<Program.Facts[Node].Domain == IR::Domain::Float, f32,
                       std::conditional_t<Fits<i32>(Program.Facts[Node].Range)          , i32, i64>>;

        template<IR::DType T>
        using Wrapped = std::conditional_t<T == IR::DType::None || T == IR::DType::F32, i64, IR::ElementOf<T>>;

        consteval static bool Real  (const u16 node) { return Program.Facts[node].Domain == IR::Domain::Float   ; }
        consteval static bool Scalar(const u16 node) { return Program.Facts[node].Domain == IR::Domain::Constant; }

        consteval static bool Loaded(const u16 out, const u16 node)
        {
            const Place spot = Program.Places[node];

            if (spot.Source == Source::Slots || spot.Source == Source::Parameter) return true;

            return spot.Source == Source::Buffer && (Program.Owner[node] != I + 1 || node < out);
        }

        consteval static i64 Operand(const u16 node) { return Detail::Operand(Program, node); }

        consteval static bool Narrow(const u16 node)
        {
            const IR::Node& spec  = Program.Nodes[node];
            const i64       limit = Program.Limits[node];

            if (!Fits<i32>(Program.Facts[node].Range)) return false;

            for (s00 k = 0; k < spec.InputCount; k++) {
                const u16      input = spec.Inputs[k];
                const i64      value = Scalar(input) ? Operand(node) : 0;
                const Interval range = Scalar(input) ? Interval { .Min = value, .Max = value }
                                                     : Program.Facts[input].Range;
                const Interval used  = limit > 0 && !Scalar(input) ? Clamp(range, -limit, limit) : range;

                if (!Fits<i32>(used)) return false;
            }

            return true;
        }

        consteval static s00 SaturatedCount()
        {
            s00 count = 0;

            for (s00 node = 0; node < Program.Nodes.size(); node++)
                count += Program.Owner[node] == I + 1 && Program.Limits[node] > 0;

            return count;
        }

        constexpr static s00 Saturated = SaturatedCount();

        static_assert(Saturated == Stage.Saturate, "the plan's Saturate counts the uses whose chain it narrows");
        static_assert(Saturated == 0 || Stage.Kind == Lowering::Kind::Pointwise, "only a Pointwise stage narrows");

        consteval static u32 Cut(const u16 out, const u16 node, const u32 low, const u32 high)
        {
            const IR::Node& spec = Program.Nodes[node];

            if (Loaded(out, node) || Scalar(node)) return 0;

            if (spec.Operation == IR::Op::Select || spec.Operation == IR::Op::Sum) return 0;

            if (spec.Operation == IR::Op::Slice) {
                const u32 cut = Cut(out, spec.Inputs[0], low + spec.Begin, high + spec.Begin);

                return cut ? cut - spec.Begin : 0;
            }

            if (spec.Operation == IR::Op::Concat) {
                const u32 left = Program.Facts[spec.Inputs[0]].Size;

                if (low < left && left < high) return left;

                if (high <= left) return Cut(out, spec.Inputs[0], low, high);

                const u32 cut = Cut(out, spec.Inputs[1], low - left, high - left);

                return cut ? cut + left : 0;
            }

            for (s00 k = 0; k < spec.InputCount; k++)
                if (const u32 cut = Cut(out, spec.Inputs[k], low, high); cut) return cut;

            return 0;
        }

        consteval static bool Emitted(const u16 node)
        {
            const Lowering::Stage& stage = Program.Stages[I];

            if (Program.Owner[node] != I + 1 || Program.Places[node].Source != Source::Buffer) return false;

            return stage.Kind == Lowering::Kind::Pointwise || node != stage.Node;
        }

        consteval static s00 EmittedCount()
        {
            s00 count = 0;

            for (s00 node = 0; node < Program.Nodes.size(); node++) count += Emitted(node);

            return count;
        }

        constexpr static s00 Count = EmittedCount();

        consteval static Array<u16, Count> EmittedNodes()
        {
            Array<u16, Count> outputs {};

            s00 count = 0;

            for (s00 node = 0; node < Program.Nodes.size(); node++)
                if (Emitted(node)) outputs[count++] = static_cast<u16>(node);

            return outputs;
        }

        constexpr static Array<u16, Count> Outputs = EmittedNodes();

        consteval static bool Copied(const u16 node)
        {
            const Lowering::Stage& stage = Program.Stages[I];

            if (Program.Copies[node].Source != Source::Buffer || stage.Kind != Lowering::Kind::Dense) return false;

            const IR::Node& input = Program.Nodes[Program.Nodes[stage.Node].Inputs[0]];

            return input.Operation == IR::Op::Concat && (input.Inputs[0] == node || input.Inputs[1] == node);
        }

        consteval static s00 CopiedCount()
        {
            s00 count = 0;

            for (s00 node = 0; node < Program.Nodes.size(); node++) count += Copied(node);

            return count;
        }

        constexpr static s00 CopyCount = CopiedCount();

        consteval static Array<u16, CopyCount> CopiedNodes()
        {
            Array<u16, CopyCount> nodes {};

            s00 count = 0;

            for (s00 node = 0; node < Program.Nodes.size(); node++)
                if (Copied(node)) nodes[count++] = static_cast<u16>(node);

            return nodes;
        }

        constexpr static Array<u16, CopyCount> CopyNodes = CopiedNodes();

        template<u32 Mask, typename F>
        [[clang::always_inline]]
        static auto Gather(const F& frame, const u32 k) noexcept
        {
            constexpr u32  First = std::countr_zero(Mask);
            constexpr bool Wide  = Program.Slots[First].Type == IR::DType::I32;

            using T = std::conditional_t<Wide, i32, i16>;

            T sum = 0;

            for (u32 slot = First; slot < 32; slot++) {
                if (!(Mask >> slot & 1)) continue;

                sum = WrapAdd<T>(sum, Wide ? frame.Sources.Wide[slot][k] : frame.Sources.Narrow[slot][k]);
            }

            return sum;
        }

        template<u16 Node, typename F>
        [[clang::always_inline]]
        static Number<Node> Load(const F& frame, const u32 k) noexcept
        {
            constexpr Place Spot = Program.Places[Node];

            if constexpr (Spot.Source == Source::Slots)
                return static_cast<Number<Node>>(Gather<Spot.Slots>(frame, k));
            else if constexpr (Spot.Source == Source::Parameter)
                return static_cast<Number<Node>>(frame.Constants.template Data<Spot.Type>()[Spot.Offset + k]);
            else return static_cast<Number<Node>>(frame.Values.template Data<Spot.Type>()[Spot.Offset + k]);
        }

        [[clang::always_inline]]
        static f32 Apply(const IR::Function function, const f32 x) noexcept
        {
            #pragma clang fp contract(off)

            if (function == IR::Function::Abs    ) return std::fabs(x);
            if (function == IR::Function::Exp    ) return std::exp(x);
            if (function == IR::Function::Sigmoid) return 1.0F / (1.0F + std::exp(-x));
            if (function == IR::Function::Tanh   ) return std::tanh(x);

            std::unreachable();
        }

        template<u16 Out, u16 Node, u32 Low, u32 High, typename F>
        [[clang::always_inline]]
        static Number<Node> Value(const F& frame, const u32 k) noexcept
        {
            constexpr IR::Node Spec = Program.Nodes[Node];
            constexpr IR::Op   Op   = Spec.Operation;

            if constexpr (Loaded(Out, Node)) return Load<Node>(frame, k);
            else if constexpr (Op == IR::Op::Slice)
                return Value<Out, Spec.Inputs[0], Low + Spec.Begin, High + Spec.Begin>(frame, k + Spec.Begin);
            else if constexpr (Op == IR::Op::Select) return Selected<Out, Node            >(frame, k);
            else if constexpr (Op == IR::Op::Concat) return Joined  <Out, Node, Low, High>(frame, k);
            else if constexpr (Op == IR::Op::Sum   ) return Summed  <Out, Node            >(frame   );
            else if constexpr (Real(Node)          ) return Floating<Out, Node, Low, High>(frame, k);
            else                                     return Discrete<Out, Node, Low, High>(frame, k);
        }

        template<u16 Out, u16 Node, typename F>
        [[clang::always_inline]]
        static Number<Node> Selected(const F& frame, const u32 k) noexcept
        {
            constexpr IR::Node Spec  = Program.Nodes[Node];
            constexpr u16      Input = Spec.Inputs[0];
            constexpr u32      Size  = Program.Facts[Node ].Size;
            constexpr u32      Whole = Program.Facts[Input].Size;

            const u32 offset = frame.Sources.Buckets[Spec.Binding - 1] * Size;

            return static_cast<Number<Node>>(Value<Out, Input, 0, Whole>(frame, k + offset));
        }

        template<u16 Out, u16 Node, u32 Low, u32 High, typename F>
        [[clang::always_inline]]
        static Number<Node> Joined(const F& frame, const u32 k) noexcept
        {
            constexpr IR::Node Spec  = Program.Nodes[Node];
            constexpr u16      Left  = Spec.Inputs[0];
            constexpr u16      Right = Spec.Inputs[1];
            constexpr u32      Split = Program.Facts[Left].Size;

            using T = Number<Node>;

            if constexpr (High <= Split) return static_cast<T>(Value<Out, Left, Low, High>(frame, k));
            else if constexpr (Low >= Split)
                return static_cast<T>(Value<Out, Right, Low - Split, High - Split>(frame, k - Split));
            else {
                if (k < Split) return static_cast<T>(Value<Out, Left, Low, Split>(frame, k));

                return static_cast<T>(Value<Out, Right, 0, High - Split>(frame, k - Split));
            }
        }

        template<u16 Out, u16 Node, typename F>
        [[clang::always_inline]]
        static Number<Node> Summed(const F& frame) noexcept
        {
            #pragma clang fp contract(off)

            constexpr u16 Input = Program.Nodes[Node].Inputs[0];
            constexpr u32 Size  = Program.Facts[Input].Size;

            using T = std::conditional_t<Real(Node), f32, i64>;

            T sum = 0;

            for (u32 k = 0; k < Size; k++) sum += static_cast<T>(Value<Out, Input, 0, Size>(frame, k));

            return static_cast<Number<Node>>(sum);
        }

        template<u16 Out, u16 Node, u08 K, u32 Low, u32 High, typename W, typename F>
        [[clang::always_inline]]
        static W Argument(const F& frame, const u32 k) noexcept
        {
            constexpr u16 Input = Program.Nodes[Node].Inputs[K];
            constexpr i64 Limit = Program.Limits[Node];

            using V = Number<Input>;

            const V value = Value<Out, Input, Low, High>(frame, k);

            if constexpr (Limit <= 0) return static_cast<W>(value);
            else {
                static_assert(
                    Input == Program.Nodes[Node].Inputs[0] && Program.Places[Node].Source == Source::Inline &&
                    Lowering::SaturationAbsorbed(Program.Nodes, Program.Facts, Heads, Input, Node) &&
                    Lowering::SaturationThreshold(Program.Nodes, Program.Facts, Heads, Input, Node) == Limit,
                    "a use clamps its value to the threshold of its chain (SaturationAbsorbed)"
                );

                return static_cast<W>(std::min(std::max(value, static_cast<V>(-Limit)), static_cast<V>(Limit)));
            }
        }

        template<u16 Out, u16 Node, u32 Low, u32 High, typename W, typename F>
        [[clang::always_inline]]
        static W Right(const F& frame, const u32 k) noexcept
        {
            constexpr u16 Input = Program.Nodes[Node].Inputs[1];

            if constexpr (!Scalar(Input))              return Argument<Out, Node, 1, Low, High, W>(frame, k);
            else if constexpr (std::is_same_v<W, f32>) return static_cast<f32>(ToDouble(Program.Nodes[Input].Low));
            else                                       return static_cast<W>(Operand(Node));
        }

        template<u16 Out, u16 Node, u32 Low, u32 High, typename F>
        [[clang::always_inline]]
        static f32 Floating(const F& frame, const u32 k) noexcept
        {
            #pragma clang fp contract(off)

            constexpr IR::Node Spec  = Program.Nodes[Node];
            constexpr IR::Op   Op    = Spec.Operation;
            constexpr u16      Input = Spec.Inputs[0];

            const auto x = Value<Out, Input, Low, High>(frame, k);

            if constexpr (Op == IR::Op::Dequantize) {
                constexpr Rational Scale   = Program.Facts[Input].Scale;
                constexpr Rational Inverse = Ratio(Scale.Denominator, Scale.Numerator);
                constexpr Rational Given   = Defined(Spec.Low) ? Spec.Low : Inverse;
                constexpr f32      Factor  = static_cast<f32>(Given.Numerator) /
                                             static_cast<f32>(Given.Denominator);

                const f32 real = static_cast<f32>(x);

                if constexpr (Spec.InputCount == 2)
                    return std::fma(real, Factor, Value<Out, Spec.Inputs[1], Low, High>(frame, k));
                else return real * Factor;
            } else if constexpr (Op == IR::Op::Clamp) {
                constexpr bool Lower = Spec.Bounds == IR::Bound::Low  || Spec.Bounds == IR::Bound::Both;
                constexpr bool Upper = Spec.Bounds == IR::Bound::High || Spec.Bounds == IR::Bound::Both;

                constexpr f32 Infinity = std::numeric_limits<f32>::infinity();

                constexpr f32 Bottom = Lower ? static_cast<f32>(ToDouble(Spec.Low )) : -Infinity;
                constexpr f32 Top    = Upper ? static_cast<f32>(ToDouble(Spec.High)) :  Infinity;

                return std::min(std::max(x, Bottom), Top);
            } else if constexpr (Op == IR::Op::Unary) {
                static_assert(
                    Spec.Function == IR::Function::Abs     || Spec.Function == IR::Function::Exp ||
                    Spec.Function == IR::Function::Sigmoid || Spec.Function == IR::Function::Tanh,
                    "an f32 Unary is Abs, Exp, Sigmoid or Tanh"
                );

                return Apply(Spec.Function, x);
            } else {
                static_assert(
                    Op == IR::Op::Add || Op == IR::Op::Mul || Op == IR::Op::Min || Op == IR::Op::Max ||
                    Op == IR::Op::Pow,
                    "an f32 Pointwise node is a Dequantize, a Clamp, a Unary or an elementwise operation"
                );

                const f32 y = Right<Out, Node, Low, High, f32>(frame, k);

                if (Op == IR::Op::Add) return x + y;
                if (Op == IR::Op::Mul) return x * y;
                if (Op == IR::Op::Min) return std::min(x, y);
                if (Op == IR::Op::Max) return std::max(x, y);

                return static_cast<f32>(std::pow(x, y));
            }
        }

        template<u16 Out, u16 Node, u32 Low, u32 High, typename F>
        [[clang::always_inline]]
        static Number<Node> Discrete(const F& frame, const u32 k) noexcept
        {
            constexpr IR::Node Spec    = Program.Nodes[Node];
            constexpr IR::Op   Op      = Spec.Operation;
            constexpr i64      Divisor = Op == IR::Op::Divide ? Spec.Low.Numerator : 1;

            using W = std::conditional_t<Narrow(Node), i32, i64>;
            using T = Number<Node>;

            const W x = Argument<Out, Node, 0, Low, High, W>(frame, k);

            if constexpr (Op == IR::Op::Add || Op == IR::Op::Mul || Op == IR::Op::Min || Op == IR::Op::Max) {
                const W y = Right<Out, Node, Low, High, W>(frame, k);

                if (Op == IR::Op::Add) return static_cast<T>(x + y);
                if (Op == IR::Op::Mul) return static_cast<T>(x * y);
                if (Op == IR::Op::Min) return static_cast<T>(std::min(x, y));
                if (Op == IR::Op::Max) return static_cast<T>(std::max(x, y));

                std::unreachable();
            } else if constexpr (Op == IR::Op::Clamp) {
                constexpr Rational Scale = Program.Facts[Spec.Inputs[0]].Scale;

                constexpr bool Lower = Spec.Bounds == IR::Bound::Low  || Spec.Bounds == IR::Bound::Both;
                constexpr bool Upper = Spec.Bounds == IR::Bound::High || Spec.Bounds == IR::Bound::Both;

                constexpr i64 Least = std::numeric_limits<W>::min();
                constexpr i64 Most  = std::numeric_limits<W>::max();

                constexpr i64 LowBound  = Lower ? Floor(Spec.Low  * Scale) : Least;
                constexpr i64 HighBound = Upper ? Floor(Spec.High * Scale) : Most ;

                constexpr W Bottom = static_cast<W>(std::clamp(LowBound , Least, Most));
                constexpr W Top    = static_cast<W>(std::clamp(HighBound, Least, Most));

                return static_cast<T>(std::min(std::max(x, Bottom), Top));
            } else {
                static_assert(
                    Op == IR::Op::Unary  || Op == IR::Op::ShiftRight || Op == IR::Op::ShiftLeft ||
                    Op == IR::Op::Divide || Op == IR::Op::Wrap       || Op == IR::Op::Verify    ||
                    Op == IR::Op::Assume,
                    "an integer Pointwise node is an elementwise operation, a clamp, a shift or a wrap"
                );

                if (Op == IR::Op::Unary     ) return static_cast<T>(std::abs(x));
                if (Op == IR::Op::ShiftRight) return static_cast<T>(x >> Spec.Shift);
                if (Op == IR::Op::ShiftLeft ) return static_cast<T>(x << Spec.Shift);
                if (Op == IR::Op::Divide    ) return static_cast<T>(x / static_cast<W>(Divisor));
                if (Op == IR::Op::Wrap      ) return static_cast<T>(static_cast<Wrapped<Spec.Type>>(x));

                return static_cast<T>(x);
            }
        }

        template<u16 Out, u32 Low, u32 High, typename F>
        [[clang::always_inline]]
        static void Emit(const F& frame) noexcept
        {
            constexpr u32 Middle = Cut(Out, Out, Low, High);

            if constexpr (Middle != 0) {
                Emit<Out, Low   , Middle>(frame);
                Emit<Out, Middle, High  >(frame);
            } else {
                constexpr Place Spot = Program.Places[Out];

                using T = IR::ElementOf<Spot.Type>;

                const auto sources = frame.Sources;
                const F    local   { .Values = frame.Values, .Constants = frame.Constants, .Sources = sources };

                T* output = local.Values.template Data<Spot.Type>() + Spot.Offset;

                if constexpr (Lanewise) {
                    PRAGMA(clang loop vectorize_width(ISA::Bytes / 4))
                    for (u32 k = Low; k < High; k++) output[k] = static_cast<T>(Value<Out, Out, Low, High>(local, k));
                } else {
                    for (u32 k = Low; k < High; k++) output[k] = static_cast<T>(Value<Out, Out, Low, High>(local, k));
                }
            }
        }

        template<u16 Out, u32 Low, u32 High, typename F>
        [[clang::always_inline]]
        static void EmitTo(const F& frame, u08* const output) noexcept
        {
            constexpr u32 Middle = Cut(Out, Out, Low, High);

            if constexpr (Middle != 0) {
                EmitTo<Out, Low   , Middle>(frame, output);
                EmitTo<Out, Middle, High  >(frame, output);
            } else {
                const auto sources = frame.Sources;
                const F    local   { .Values = frame.Values, .Constants = frame.Constants, .Sources = sources };

                PRAGMA(clang loop vectorize_width(ISA::Bytes / 4))
                for (u32 k = Low; k < High; k++) output[k] = static_cast<u08>(Value<Out, Out, Low, High>(local, k));
            }
        }

        template<typename V, s00... K>
        [[clang::always_inline]]
        static auto Join(const V low, const V high, const std::index_sequence<K...>) noexcept
        { return __builtin_shufflevector(low, high, K...); }

        template<u16 Out, typename F>
        [[clang::always_inline]]
        static void Keep(const F& frame) noexcept
        {
            constexpr Place Spot  = Program.Places[Out];
            constexpr u32   Bytes = static_cast<u32>(ISA::Bytes);
            constexpr u32   Piece = Bytes / 4;
            constexpr u32   Size  = Program.Facts[Out].Size;

            using Quarter [[gnu::vector_size(Piece)]] = u08;

            alignas(Alignment) Array<u08, Size> scratch;

            EmitTo<Out, 0, Size>(frame, scratch.data());

            u08* output = frame.Values.template Data<IR::DType::U08>() + Spot.Offset;

            for (u32 block = 0; block < Size / Bytes; block++) {
                Array<Quarter, 4> pieces;

                for (u32 p = 0; p < 4; p++)
                    std::memcpy(&pieces[p], scratch.data() + block * Bytes + p * Piece, Piece);

                const auto low  = Join(pieces[0], pieces[1], std::make_index_sequence<2 * Piece> {});
                const auto high = Join(pieces[2], pieces[3], std::make_index_sequence<2 * Piece> {});
                const auto kept = std::bit_cast<typename ISA::Vector>(
                    Join(low, high, std::make_index_sequence<4 * Piece> {})
                );

                frame.Values.Held[Spot.Offset / Bytes + block] = kept;

                ISA::Store(output + block * Bytes, kept);
            }
        }

        template<u16 Out, typename F>
        [[clang::always_inline]]
        static void Write(const F& frame) noexcept
        {
            if constexpr (Lanewise && Kept<ISA>(Program, Out) && requires { frame.Values.Held; }) Keep<Out>(frame);
            else Emit<Out, 0, Program.Facts[Out].Size>(frame);
        }

        template<typename A, typename C, typename S>
        [[clang::always_inline]]
        static void Run(A& values, const C& constants, const S& sources) noexcept
        {
            const Detail::Frame<A, C, S> frame { .Values = values, .Constants = constants, .Sources = sources };

            [&]<s00... O> [[clang::always_inline]] (const std::index_sequence<O...>) {
                (Write<Outputs[O]>(frame), ...);
            }(std::make_index_sequence<Count> {});
        }

        template<u16 Node, typename F>
        [[clang::always_inline]]
        static void Copy(const F& frame) noexcept
        {
            constexpr Place Spot = Program.Copies[Node];

            using T = IR::ElementOf<Spot.Type>;

            const auto sources = frame.Sources;
            const F    local   { .Values = frame.Values, .Constants = frame.Constants, .Sources = sources };

            T* output = local.Values.template Data<Spot.Type>() + Spot.Offset;

            for (u32 k = 0; k < Program.Facts[Node].Size; k++) output[k] = static_cast<T>(Load<Node>(local, k));
        }

        template<typename A, typename C, typename S>
        [[clang::always_inline]]
        static void RunCopies(A& values, const C& constants, const S& sources) noexcept
        {
            const Detail::Frame<A, C, S> frame { .Values = values, .Constants = constants, .Sources = sources };

            [&]<s00... O>(const std::index_sequence<O...>) {
                (Copy<CopyNodes[O]>(frame), ...);
            }(std::make_index_sequence<CopyCount> {});
        }

    };

    template<const auto& Program, s00 I, typename ISA>
    struct Pointwise
    {

        constexpr static Lowering::Stage Stage = Program.Stages[I];

        static_assert(Stage.Kind == Lowering::Kind::Pointwise, "Kernel::Pointwise runs a Pointwise stage");

        template<typename A, typename C, typename S>
        [[clang::always_inline]]
        [[clang::min_vector_width(512)]]
        static void Run(A& values, const C& constants, const S& sources) noexcept
        { Elementwise<Program, I, ISA>::Run(values, constants, sources); }

    };

}

#endif //MANTARAY_BACKEND_KERNEL_POINTWISE_H
