//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_LOWERING_LOWERING_H
#define MANTARAY_LOWERING_LOWERING_H

#include <algorithm>
#include <limits>
#include <string_view>
#include <utility>

#include "Choices.h"
#include "Facts.h"
#include "Program.h"
#include "Target.h"
#include "../Common.h"
#include "../IR/Analysis.h"
#include "../IR/GraphIR.h"

namespace MantaRay::Lowering
{

    namespace Detail
    {

        constexpr bool Absorbing(const IR::Op op)
        { return op == IR::Op::Add || op == IR::Op::Wrap || op == IR::Op::Verify; }

        template<typename G, s00 N>
        struct Context
        {

            const G&                  Graph;
            const Array<IR::Fact, N>& Facts;

            Array<u16, N    > UserCount {};
            Array<u16, N    > Producer  {};
            Array<u32, N + 1> First     {};
            Array<u16, 2 * N> Edges     {};

            constexpr explicit Context(const G& graph, const Array<IR::Fact, N>& facts) : Graph(graph), Facts(facts)
            {
                for (s00 i = 0; i < N; i++) {
                    const IR::Node& spec = graph.Nodes[i];

                    for (s00 k = 0; k < spec.InputCount; k++) {
                        UserCount[spec.Inputs[k]]++;

                        Producer[i] = std::max(Producer[i], Producer[spec.Inputs[k]]);
                    }

                    if (spec.Operation == IR::Op::Matmul) Producer[i] = static_cast<u16>(i);
                }

                for (s00 i = 0; i < N; i++) First[i + 1] = First[i] + UserCount[i];

                Array<u32, N> fill {};

                for (s00 i = 0; i < N; i++)
                for (s00 k = 0; k < graph.Nodes[i].InputCount; k++) {
                    const u16 input = graph.Nodes[i].Inputs[k];

                    Edges[First[input] + fill[input]++] = static_cast<u16>(i);
                }
            }

            constexpr u16 User(const u16 node, const u16 k) const { return Edges[First[node] + k]; }

            constexpr const IR::Node& At(const u16 node) const { return Graph.Nodes[node]; }

            constexpr u16 Only(const u16 node) const { return UserCount[node] == 1 ? User(node, 0) : 0; }

            constexpr u16 SquareOf(const u16 node) const
            {
                const bool twice = UserCount[node] == 2 && User(node, 0) == User(node, 1);

                return twice && At(User(node, 0)).Operation == IR::Op::Mul ? User(node, 0) : 0;
            }

            constexpr bool Split(const u16 node) const
            {
                const IR::Node& spec = At(node);

                return spec.Operation == IR::Op::Concat && UserCount[node] == 1 &&
                       Producer[spec.Inputs[0]] != Producer[spec.Inputs[1]];
            }

            constexpr bool Root(const u16 node) const
            {
                const IR::Node& spec = At(node);

                if (!Facts[node].Linear || spec.InputCount == 0 || spec.Operation == IR::Op::Slice) return false;

                for (s00 k = 0; k < UserCount[node]; k++) {
                    const u16 user = User(node, k);

                    if (!Facts[user].Linear || !Absorbing(At(user).Operation)) return true;
                }

                return UserCount[node] == 0;
            }

            constexpr void Terms(const u16 node, u32& featureSets, bool& bias) const
            {
                const IR::Node& spec = At(node);

                if (spec.Operation == IR::Op::SparseMatmul) featureSets |= Facts[node].FeatureSets;
                if (spec.Operation == IR::Op::Parameter   ) bias      = true;

                if (!Absorbing(spec.Operation)) return;

                for (s00 k = 0; k < spec.InputCount; k++) Terms(spec.Inputs[k], featureSets, bias);
            }

            constexpr bool SameTerms(const u16 a, const u16 b) const
            {
                const IR::Node& x = At(a);
                const IR::Node& y = At(b);

                if (x.Operation != y.Operation || x.InputCount != y.InputCount || x.Tensor != y.Tensor ||
                    x.Begin     != y.Begin     || x.End        != y.End        || x.Offset != y.Offset ||
                    x.Binding   != y.Binding   ) return false;

                if (x.Operation == IR::Op::Input) return true;

                for (s00 k = 0; k < x.InputCount; k++)
                    if (!SameTerms(x.Inputs[k], y.Inputs[k])) return false;

                return true;
            }

        };

        template<typename G, s00 N>
        constexpr void CoverTerms(const Context<G, N>& context, const u16 node, Array<bool, N>& covered)
        {
            const IR::Node& spec = context.At(node);

            covered[node] = true;

            if (!Absorbing(spec.Operation) && spec.Operation != IR::Op::SparseMatmul) return;

            for (s00 k = 0; k < spec.InputCount; k++) CoverTerms(context, spec.Inputs[k], covered);
        }

        template<typename G, s00 N>
        constexpr void CoverPrologue(const Context<G, N>& context, const u16 node, Array<bool, N>& covered)
        {
            const IR::Node& spec = context.At(node);

            if (covered[node]) return;

            const bool pointwise = spec.Operation == IR::Op::Concat || spec.Operation == IR::Op::Clamp ||
                                   spec.Operation == IR::Op::Mul    || spec.Operation == IR::Op::Slice ||
                                   spec.Operation == IR::Op::ShiftRight;

            if (!pointwise) return;

            covered[node] = true;

            for (s00 k = 0; k < spec.InputCount; k++) CoverPrologue(context, spec.Inputs[k], covered);
        }

        template<typename G, s00 N>
        constexpr u16 ParameterOf(const Context<G, N>& context, const u16 operand)
        {
            const IR::Node& spec = context.At(operand);

            if (spec.Operation == IR::Op::Parameter) return operand;

            const bool selected = spec.Operation == IR::Op::Select &&
                                  context.At(spec.Inputs[0]).Operation == IR::Op::Parameter;

            return selected ? spec.Inputs[0] : 0;
        }

        template<typename G, s00 N>
        constexpr bool Record(const Context<G, N>& context, const u16 step, Stage& stage)
        {
            const IR::Node& spec = context.At(step);

            if (stage.Kind != Kind::Dense || spec.Operation == IR::Op::Select) return true;

            const bool real   = context.Facts[step].Domain == IR::Domain::Float;
            const bool scaled = stage.Requant == IR::Op::Dequantize;
            const bool fresh  = stage.Requant == IR::Op::None && stage.Bias == 0 && stage.Wrap == IR::DType::None;

            if (spec.Operation == IR::Op::Divide || spec.Operation == IR::Op::ShiftRight) {
                if (!fresh) return false;

                stage.Requant = spec.Operation;
                stage.Factor  = spec.Low;
                stage.Shift   = spec.Shift;

                return true;
            }

            if (spec.Operation == IR::Op::Add) {
                const bool floating = stage.Weight == IR::DType::F32 || scaled;
                const bool fits     = stage.Bias == 0 && (real ? floating : !scaled && stage.Wrap == IR::DType::None);

                if (!fits) return false;

                stage.Bias    = ParameterOf(context, spec.Inputs[1]);
                stage.Unfused = scaled;

                return true;
            }

            if (spec.Operation == IR::Op::Wrap) {
                if (stage.Wrap != IR::DType::None || real || scaled) return false;

                stage.Wrap = spec.Type;

                return true;
            }

            if (spec.Operation == IR::Op::Dequantize) {
                const u16      bias  = spec.InputCount == 2 ? ParameterOf(context, spec.Inputs[1]) : u16 { 0 };
                const Rational scale = context.Facts[spec.Inputs[0]].Scale;

                if (!fresh || (spec.InputCount == 2 && bias == 0)) return false;

                stage.Requant = IR::Op::Dequantize;
                stage.Factor  = Defined(spec.Low) ? spec.Low : Ratio(scale.Denominator, scale.Numerator);
                stage.Bias    = bias;

                return true;
            }

            std::unreachable();
        }

        template<typename G, s00 N>
        constexpr u16 CoverEpilogue(const Context<G, N>& context, Stage& stage, Array<bool, N>& covered)
        {
            u16 node     = stage.Node;
            u16 selector = 0;

            while (context.UserCount[node] == 1) {
                const u16       user = context.User(node, 0);
                const IR::Node& spec = context.At(user);

                const bool      sum     = spec.Operation == IR::Op::Add && spec.InputCount == 2;
                const IR::Node& operand = context.At(sum ? spec.Inputs[1] : user);

                const bool selected = sum && operand.Operation == IR::Op::Select && operand.Binding == selector &&
                                      context.At(operand.Inputs[0]).Operation == IR::Op::Parameter;

                const bool bias = sum && (operand.Operation == IR::Op::Parameter || selected);

                const bool step = bias                                 || spec.Operation == IR::Op::Divide ||
                                  spec.Operation == IR::Op::ShiftRight || spec.Operation == IR::Op::Select ||
                                  spec.Operation == IR::Op::Wrap       || spec.Operation == IR::Op::Dequantize;

                if (!step || !Record(context, user, stage)) return node;

                covered[user] = true;

                for (s00 k = 1; k < spec.InputCount; k++) covered[spec.Inputs[k]] = true;

                if (selected) covered[operand.Inputs[0]] = true;

                if (spec.Operation == IR::Op::Select) selector = spec.Binding;

                node = user;
            }

            return node;
        }

        template<typename G, s00 N>
        constexpr bool ThenBounds(const Context<G, N>& context, const u16 clamp, Interval& bounds)
        {
            const IR::Node& spec = context.At(clamp);
            const IR::Fact& fact = context.Facts[clamp];

            if (fact.Domain == IR::Domain::Integer) {
                bounds = fact.Range;

                return true;
            }

            if (fact.Domain != IR::Domain::Float || spec.Bounds != IR::Bound::Both) return false;

            if (spec.Low.Denominator != 1 || spec.High.Denominator != 1) return false;

            bounds = { .Min = spec.Low.Numerator, .Max = spec.High.Numerator };

            return true;
        }

        template<typename G, s00 N>
        constexpr void Absorb(const Context<G, N>& context, const u16 end, Stage& stage, Array<bool, N>& covered)
        {
            const u16 clamp = context.Only(end);

            Interval bounds {};

            if (context.At(clamp).Operation != IR::Op::Clamp || !ThenBounds(context, clamp, bounds)) return;

            const u16 square = context.SquareOf(clamp);
            const u16 active = square ? square : clamp;
            const u16 after  = context.Only(active);
            const u16 shift  = context.At(after).Operation == IR::Op::ShiftRight ? after : 0;
            const u16 last   = shift ? shift : active;
            const u16 split  = context.Only(last);
            const u16 input  = context.Split(split) ? split : last;
            const u16 next   = context.Only(input);

            if (context.At(next).Operation != IR::Op::Matmul || context.At(next).Inputs[0] != input) return;

            stage.Then      = square ? Activation::SquaredClamp : Activation::Clamp;
            stage.ThenLow   = bounds.Min;
            stage.ThenHigh  = bounds.Max;
            stage.ThenShift = shift ? context.At(shift).Shift : 0;
            stage.Output    = context.Facts[input].Storage;

            covered[clamp ] = true;
            covered[active] = true;
            covered[last  ] = true;
        }

        template<typename G, s00 N>
        constexpr Activation Classify(
            const Context<G, N>& context,
            const u16            node   ,
                  u16&           root   ,
                  Interval&      clamp  ,
                  u16&           shift
        )
        {
            u16 current = node;

            if (context.At(current).Operation == IR::Op::ShiftRight) {
                shift   = context.At(current).Shift;
                current = context.At(current).Inputs[0];
            }

            const IR::Node& spec = context.At(current);

            if (spec.Operation == IR::Op::Clamp) {
                root  = spec.Inputs[0];
                clamp = context.Facts[current].Range;

                return context.Root(root) ? Activation::Clamp : Activation::Other;
            }

            if (spec.Operation != IR::Op::Mul) return Activation::Other;

            const IR::Node& left  = context.At(spec.Inputs[0]);
            const IR::Node& right = context.At(spec.Inputs[1]);

            if (spec.Inputs[0] == spec.Inputs[1] && left.Operation == IR::Op::Clamp) {
                root  = left.Inputs[0];
                clamp = context.Facts[spec.Inputs[0]].Range;

                return context.Root(root) ? Activation::SquaredClamp : Activation::Other;
            }

            if (left.Operation != IR::Op::Clamp || right.Operation != IR::Op::Clamp) return Activation::Other;

            const IR::Node& low  = context.At(left .Inputs[0]);
            const IR::Node& high = context.At(right.Inputs[0]);

            if (low.Operation != IR::Op::Slice || high.Operation != IR::Op::Slice || low.Inputs[0] != high.Inputs[0])
                return Activation::Other;

            if (context.Facts[spec.Inputs[0]].Range != context.Facts[spec.Inputs[1]].Range) return Activation::Other;

            if (low.Begin != 0 || low.End != high.Begin || high.End != 2 * low.End) return Activation::Other;

            if (high.End != context.Facts[low.Inputs[0]].Size) return Activation::Other;

            root  = low.Inputs[0];
            clamp = context.Facts[spec.Inputs[0]].Range;

            return context.Root(root) ? Activation::Pairwise : Activation::Other;
        }

        template<typename G, s00 N>
        constexpr bool PerspectivePair(const Context<G, N>& context, const u16 node, Program<N>& program, Stage& stage)
        {
            const IR::Node& concat = context.At(node);

            if (concat.Operation != IR::Op::Concat) return false;

            Array<u16       , 2> roots       {};
            Array<u16       , 2> shifts      {};
            Array<Interval  , 2> clamps      {};
            Array<Activation, 2> activations {};

            for (s00 side = 0; side < 2; side++)
                activations[side] = Classify(context, concat.Inputs[side], roots[side], clamps[side], shifts[side]);

            if (activations[0] != activations[1] || activations[0] == Activation::Other || clamps[0] != clamps[1])
                return false;

            const IR::Fact& stm = context.Facts[roots[0]];
            const IR::Fact& ntm = context.Facts[roots[1]];

            if (stm.Perspective != IR::Dependence::Stm || ntm.Perspective != IR::Dependence::Ntm) return false;

            if (shifts[0] != shifts[1] || stm.Size != ntm.Size) return false;

            stage.Activation = activations[0];
            stage.Shift      = shifts[0];
            stage.Low        = clamps[0].Min;
            stage.High       = clamps[0].Max;
            stage.Width      = stm.Size;

            for (s00 r = 0; r < roots.size(); r++)
            for (s00 s = 0; s < program.SlotCount; s++)
                if (program.Slots[s].Root == roots[r]) stage.Slots |= s < 32 ? u32 { 1 } << s : 0;

            return true;
        }

        template<s00 N>
        constexpr u16 Join(const Program<N>& combined, const Slot& slot)
        {
            if (!slot.Incremental || slot.Shared) return combined.SlotCount;

            for (s00 t = 0; t < combined.SlotCount; t++) {
                const Slot& into = combined.Slots[t];

                if (into.Root == slot.Root && into.Incremental && !into.Shared) return static_cast<u16>(t);
            }

            return combined.SlotCount;
        }

        constexpr Mode SquaredClampMode(const Interval x, const Interval w)
        {
            const Interval product = Square(x) * w;
            const bool     squared = SquareFitsI16(x) && MaddExact(Square(x), w);

            if (LizardExact(x, w)) return Mode::Lizard;
            if (squared          ) return Mode::SquareFirst;

            return Fits<i32>(Repeat(product, 2)) ? Mode::Widened : Mode::None;
        }

        constexpr void PlanDot(const Target& target, const Interval product, const s00 terms, Stage& stage)
        {
            const s00 lanes  = target.Bytes / 4;
            const s00 group  = stage.Mode == Mode::PackusDot ? 4 : 2;
            const s00 rounds = (terms + group * lanes - 1) / (group * lanes);

            s00 accumulators = 1;

            while (!Fits<i32>(Repeat(product, group * ((rounds + accumulators - 1) / accumulators))) &&
                   lanes * accumulators < terms) accumulators *= 2;

            stage.Chains = static_cast<u16>(std::max(target.DotChains, accumulators));
            stage.Wide   = !Fits<i32>(Repeat(product, terms));
        }

        template<typename G, s00 N>
        constexpr void FormSlots(const Context<G, N>& context, const u16 root, Program<N>& program)
        {
            const G&                  graph = context.Graph;
            const Array<IR::Fact, N>& facts = context.Facts;

            u32  featureSets = 0;
            bool bias        = false;

            context.Terms(root, featureSets, bias);

            Array<u16 , IR::MaxFeatureSet> triggers {};
            Array<u32 , IR::MaxFeatureSet> groups   {};
            Array<bool, IR::MaxFeatureSet> eager    {};
            Array<bool, IR::MaxFeatureSet> shared   {};
            Array<bool, IR::MaxFeatureSet> cached   {};

            u16 count = 0;

            for (s00 f = 0; f < graph.Bindings.size() && f < IR::MaxFeatureSet; f++) {
                if (!(featureSets >> f & 1)) continue;

                const IR::Binding& binding = graph.Bindings[f];

                u16 group = 0;

                while (group < count && (triggers[group] != binding.Trigger || eager[group] != binding.Incremental ||
                                         shared[group] != binding.Shared)) group++;

                if (group == count) {
                    triggers[count] = binding.Trigger;
                    eager   [count] = binding.Incremental;
                    shared  [count] = binding.Shared;
                    cached  [count] = binding.Cached;

                    count++;
                }

                groups[group] |= u32 { 1 } << f;
                cached[group]  = cached[group] && binding.Cached;
            }

            const bool      modular = ModularSum(graph.Nodes[root]) && graph.Nodes[root].Type == IR::DType::I16;
            const IR::DType type    = Fits<i16>(facts[root].Range) || modular ? IR::DType::I16 : IR::DType::I32;

            u16 home = count;

            for (s00 group = 0; group < count; group++) {
                const bool candidate = eager[group] && !shared[group];
                const bool preferred = home == count || (cached[group] && !cached[home]);

                if (candidate && preferred) home = static_cast<u16>(group);
            }

            for (s00 group = 0; group < count; group++)
                program.Slots[program.SlotCount++] = {
                    .Root        = root,
                    .Trigger     = triggers[group],
                    .FeatureSets = groups[group],
                    .Width       = facts[root].Size,
                    .Bias        = bias && group == (home == count ? 0 : home),
                    .Incremental = eager[group],
                    .Shared      = shared[group],
                    .Type        = type,
                    .Perspective = shared[group] ? IR::Dependence::Shared : facts[root].Perspective
                };
        }

        template<typename G, s00 N>
        constexpr void PairTwins(const Context<G, N>& context, Program<N>& program)
        {
            for (s00 s = 0; s < program.SlotCount; s++)
            for (s00 t = 0; t < program.SlotCount; t++) {
                const Slot& left  = program.Slots[s];
                const Slot& right = program.Slots[t];

                const bool sides = left .Perspective == IR::Dependence::Stm &&
                                   right.Perspective == IR::Dependence::Ntm && context.SameTerms(left.Root, right.Root);

                const bool common = left.Shared && right.Shared && s < t && left.Root != right.Root;

                const bool twins = (sides || common) && left.FeatureSets == right.FeatureSets &&
                                   left.Width == right.Width && left.Bias == right.Bias &&
                                   left.Incremental == right.Incremental;

                if (twins) {
                    program.Slots[s].Twin = static_cast<u16>(t + 1);
                    program.Slots[t].Twin = static_cast<u16>(s + 1);
                }
            }
        }

        template<typename G, s00 N>
        constexpr void PlanAccumulatorDot(const Context<G, N>& context, const Target& target, Stage& stage)
        {
            const Interval x { .Min = stage.Low, .Max = stage.High };
            const Interval w = IR::TensorBounds(context.Graph, static_cast<u16>(context.At(stage.Node).Tensor - 1));

            stage.Kind = Kind::AccumulatorDot;

            if (stage.Activation == Activation::Clamp && MaddExact(x, w)) {
                const bool packus = target.VNNI && PackusIsClippedReLU(stage.Low, stage.High) && Fits<i08>(w) &&
                                    stage.Width % target.Bytes == 0;

                stage.Mode = packus ? Mode::PackusDot : Mode::Linear;
            }

            if (stage.Activation == Activation::SquaredClamp) stage.Mode = SquaredClampMode(x, w);

            if (stage.Mode == Mode::None) stage.Kind = Kind::Reference;

            const Interval product = stage.Activation == Activation::Clamp ? x * w : Square(x) * w;

            PlanDot(target, product, 2 * stage.Width, stage);
        }

        constexpr Stage TransformOf(const Stage& stage, const u16 node, const IR::DType output)
        {
            Stage transform = stage;

            transform.Kind   = Kind::AccumulatorTransform;
            transform.Node   = node;
            transform.Output = output;
            transform.Rows   = 0;

            const bool mulhi = transform.Activation == Activation::Pairwise &&
                               MulHiExact({ .Min = transform.Low, .Max = transform.High }, transform.Shift);

            transform.Mode = mulhi ? Mode::MulHi : Mode::Widened;

            return transform;
        }

        template<typename G, s00 N>
        constexpr void LowerMatmul(
            const Context<G, N>& context,
            const Target&        target,
            const u16            matmul,
                  Program<N>&    program
        )
        {
            const G&                  graph = context.Graph;
            const Array<IR::Fact, N>& facts = context.Facts;

            const IR::Node&   node     = graph.Nodes[matmul];
            const u16         weights  = static_cast<u16>(node.Tensor - 1);
            const IR::Tensor& tensor   = graph.Tensors[weights];
            const IR::Fact&   input    = facts[node.Inputs[0]];
            const u16         selector = facts[matmul].Selector;
            const u32         buckets  = selector ? graph.Bindings[selector - 1].Count : 1;

            const bool narrowed = input.Storage == IR::DType::I16 && tensor.Type == IR::DType::I32 &&
                                  NarrowsTo16(Licensed(input), IR::TensorBounds(graph, weights));

            Stage stage {
                .Node    = matmul,
                .Rows    = (node.End - node.Begin) / buckets,
                .Buckets = buckets,
                .Input   = input.Storage,
                .Weight  = narrowed ? IR::DType::I16 : tensor.Type,
                .Output  = facts[matmul].Storage
            };

            const bool accumulator = PerspectivePair(context, node.Inputs[0], program, stage);

            if (accumulator && stage.Rows == 1 && stage.Activation != Activation::Pairwise && stage.Shift == 0) {
                PlanAccumulatorDot(context, target, stage);

                stage.Fused = program.StageCount == 0;

                program.Stages[program.StageCount++] = stage;

                return;
            }

            if (accumulator) program.Stages[program.StageCount++] = TransformOf(stage, node.Inputs[0], input.Storage);

            const bool bytes   = input.Storage == IR::DType::U08 && input.Range.Min >= 0 &&
                                 tensor.Type == IR::DType::I08;
            const bool maddubs = bytes && MaddubsExact(input.Range, IR::TensorBounds(graph, weights));
            const bool shifted = input.Storage == IR::DType::U16 && input.Range.Min >= 0 && input.Range.Max > 32767 &&
                                 (tensor.Type == IR::DType::I08 || tensor.Type == IR::DType::I16);

            stage.Kind       = Kind::Dense;
            stage.Sparse     = accumulator && bytes && input.Size >= SparseInputs;
            stage.Activation = Activation::None;
            stage.Mode       = bytes && (target.VNNI || (target.Maddubs && maddubs)) ? Mode::PackusDot :
                               shifted                                               ? Mode::ZeroPoint : Mode::Linear;
            stage.Shift      = 0;
            stage.Width      = input.Size;
            stage.Wide       = facts[matmul].Storage == IR::DType::I64;
            stage.Reduction  = node.Reduction;
            stage.Bias       = node.InputCount == 2 ? ParameterOf(context, node.Inputs[1]) : u16 { 0 };

            program.Stages[program.StageCount++] = stage;
        }

        template<typename G, s00 N>
        constexpr Array<bool, N> Cover(const Context<G, N>& context, Program<N>& program)
        {
            Array<bool, N> owned {};

            for (s00 i = 0; i < N; i++) owned[i] = context.At(i).Operation == IR::Op::Constant;

            for (s00 s = 0; s < program.SlotCount; s++) CoverTerms(context, program.Slots[s].Root, owned);

            for (s00 s = 0; s < program.StageCount; s++) {
                Stage&          stage = program.Stages[s];
                const IR::Node& spec  = context.At(stage.Node);

                if (stage.Kind == Kind::AccumulatorTransform) {
                    CoverPrologue(context, stage.Node, owned);

                    continue;
                }

                owned[stage.Node] = true;

                for (s00 k = 1; k < spec.InputCount; k++) owned[spec.Inputs[k]] = true;

                if (stage.Kind == Kind::AccumulatorDot) CoverPrologue(context, spec.Inputs[0], owned);

                if (context.Split(spec.Inputs[0])) owned[spec.Inputs[0]] = true;

                const u16 end = CoverEpilogue(context, stage, owned);

                if (stage.Kind != Kind::Dense) continue;

                stage.Output = context.Facts[end].Storage;
                stage.Wide   = stage.Wide && !ModularSum(stage.Wrap, stage.Requant);

                Absorb(context, end, stage, owned);
            }

            return owned;
        }

        template<s00 N>
        constexpr Program<N> Order(const Program<N>& program, const Array<bool, N>& owned)
        {
            Program<N> ordered = program;

            ordered.StageCount = 0;

            u16 previous = 0;

            const auto glue = [&](const u16 until) {
                u16 count = 0;

                for (s00 i = previous; i < until; i++) count += !owned[i];

                if (count)
                    ordered.Stages[ordered.StageCount++] = { .Kind = Kind::Pointwise, .Node = until, .Rows = count };
            };

            for (s00 s = 0; s < program.StageCount; s++) {
                const Stage& stage = program.Stages[s];

                if (stage.Kind != Kind::AccumulatorTransform) glue(stage.Node);

                ordered.Stages[ordered.StageCount++] = stage;

                previous = std::max<u16>(previous, stage.Node);
            }

            glue(static_cast<u16>(N));

            return ordered;
        }

        constexpr Form FormOf(const Stage& stage)
        {
            const bool bytes  = stage.Input == IR::DType::U08 && stage.Weight == IR::DType::I08;
            const bool shorts = stage.Input == IR::DType::I16 && stage.Weight == IR::DType::I16;
            const bool words  = stage.Input == IR::DType::I32 && stage.Weight == IR::DType::I32;
            const bool reals  = stage.Input == IR::DType::F32 && stage.Weight == IR::DType::F32;

            const bool generic = stage.Wide || stage.Requant == IR::Op::Divide || stage.Mode == Mode::ZeroPoint ||
                                 !(bytes || shorts || words || reals);

            if (generic) return Form::Generic;

            if (reals) {
                if (stage.Reduction == IR::Reduction::Lanes16) return Form::Lanes;

                return stage.Rows == 1 ? Form::Serial : Form::Broadcast;
            }

            if (stage.Sparse  ) return Form::Sparse;
            if (stage.Rows < 4) return Form::RowDot;

            return bytes ? Form::Grouped : Form::Broadcast;
        }

        constexpr Dot DotOf(const Target& target, const Stage& stage, const Interval x, const Interval w)
        {
            if (stage.Input == IR::DType::F32)
                return stage.Reduction == IR::Reduction::Sequential ? Dot::MulAdd : Dot::Fma;

            if (stage.Input == IR::DType::I16) return Dot::Madd;
            if (stage.Input == IR::DType::I32) return NarrowsTo16(x, w) ? Dot::Madd : Dot::MulLo;

            if (target.VNNI && VnniExact(x, w)) return Dot::Dpbusd;

            return MaddubsExact(x, w) ? Dot::Maddubs : Dot::Wide;
        }

        template<typename G, s00 N>
        constexpr void PlanMatmul(const Context<G, N>& context, const Target& target, Stage& stage)
        {
            const IR::Node& node    = context.At(stage.Node);
            const IR::Node& bias    = context.At(stage.Bias);
            const IR::Fact& input   = context.Facts[node.Inputs[0]];
            const bool      integer = !IR::IsFloat(stage.Input) && !IR::IsFloat(stage.Weight);
            const bool      whole   = integer && stage.Bias != 0 && bias.Tensor != 0 &&
                                      !IR::IsFloat(context.Graph.Tensors[bias.Tensor - 1].Type);

            const u16 weights = static_cast<u16>(node.Tensor - 1);
            const u16 biases  = static_cast<u16>(bias.Tensor - 1);

            const Interval x = integer ? Licensed(input)                          : Interval {};
            const Interval w = integer ? IR::TensorBounds(context.Graph, weights) : Interval {};
            const Interval b = whole   ? IR::TensorBounds(context.Graph, biases ) : Interval {};

            const s00 lanes = target.Bytes / 4;
            const s00 most  = s00 { std::numeric_limits<u08>::max() } * lanes;

            stage.Low        = x.Min;
            stage.High       = x.Max;
            stage.WeightLow  = w.Min;
            stage.WeightHigh = w.Max;
            stage.BiasLow    = b.Min;
            stage.BiasHigh   = b.Max;
            stage.Form       = stage.Rows > most ? Form::Generic : FormOf(stage);

            if (stage.Form == Form::Generic) return;

            const bool sparse  = stage.Form == Form::Sparse;
            const bool chunks  = sparse || stage.Form == Form::Grouped;
            const bool columns = chunks || stage.Form == Form::Broadcast;
            const bool scaled  = stage.Requant == IR::Op::Dequantize;
            const Test test    = NnzCmpgtSafe(x) ? Test::Positive : Test::Nonzero;

            stage.Dot    = DotOf(target, stage, x, w);
            stage.Test   = sparse  ? test : Test::None;
            stage.Padded = columns ? static_cast<u32>((stage.Rows + lanes - 1) / lanes * lanes) : 0;
            stage.Narrow = stage.Input == IR::DType::I32 && stage.Dot == Dot::Madd;
            stage.Pairs  = chunks && stage.Dot == Dot::Maddubs && MaddubsPairExact(x, w);

            const s00 tile = columns                   ? stage.Padded / lanes :
                             stage.Form == Form::Lanes ? 16 / lanes           : 0;

            const s00 inflight = target.DotInFlight;
            const s00 budget   = tile ? (target.Registers - 4) / tile : 0;
            const s00 sets     = chunks ? std::max<s00>(1, std::min((inflight + tile - 1) / tile, budget)) : 1;

            stage.Tile     = static_cast<u08>(tile);
            stage.Sets     = static_cast<u08>(sets);
            stage.BiasInit = integer && stage.Bias != 0 && BiasInit(stage);
            stage.Vector   = integer && !scaled ? EpilogueFits32(stage) : true;
        }

        template<s00 N>
        constexpr void PlanTransform(const Program<N>& program, Stage& stage)
        {
            bool narrow = stage.Slots != 0;

            for (s00 s = 0; s < program.SlotCount && s < 32; s++)
                if (stage.Slots >> s & 1) narrow = narrow && program.Slots[s].Type == IR::DType::I16;

            const bool     pairwise = stage.Activation == Activation::Pairwise;
            const bool     shaped   = stage.Activation == Activation::Clamp || (pairwise && stage.Mode == Mode::MulHi);
            const Interval clamp    { .Min = stage.Low, .Max = stage.High };

            stage.Vector   = narrow && shaped && stage.Output == IR::DType::U08;
            stage.OneSided = stage.Vector && LowerClampAbsorbed(clamp, stage.Shift, pairwise, stage.Output);
        }

        template<typename G, s00 N>
        constexpr bool Lanewise(const Context<G, N>& context, const u16 node)
        {
            const IR::Node& spec = context.At(node);

            if (spec.Operation == IR::Op::Unary) return spec.Function == IR::Function::Abs;

            return spec.Operation != IR::Op::Sum && spec.Operation != IR::Op::Pow && spec.Operation != IR::Op::Divide;
        }

        template<typename G, s00 N>
        constexpr void PlanPointwise(const Context<G, N>& context, const Array<bool, N>& owned, Program<N>& program)
        {
            u16 previous = 0;

            for (s00 s = 0; s < program.StageCount; s++) {
                Stage& stage = program.Stages[s];

                if (stage.Kind != Kind::Pointwise) {
                    previous = std::max(previous, stage.Node);

                    continue;
                }

                bool vector = true;

                for (s00 i = previous; i < stage.Node; i++) vector = vector && (owned[i] || Lanewise(context, i));

                stage.Vector = vector;
            }
        }

        template<typename G, s00 N>
        constexpr bool Headed(const Context<G, N>& context, const u16 node)
        {
            for (s00 h = 0; h < context.Graph.Heads.size(); h++)
                if (context.Graph.Heads[h].Node == node) return true;

            return false;
        }

        template<typename G, s00 N>
        constexpr void PlanPack(const Context<G, N>& context, const Target& target, Program<N>& program)
        {
            Array<u16, N> writer {};

            for (s00 s = 0; s < program.StageCount; s++)
                if (program.Stages[s].Kind == Kind::AccumulatorTransform)
                    writer[program.Stages[s].Node] = static_cast<u16>(s + 1);

            for (s00 d = 0; d < program.StageCount; d++) {
                Stage& dense = program.Stages[d];

                if (dense.Kind != Kind::Dense) continue;

                const u16 input = context.At(dense.Node).Inputs[0];

                if (writer[input] == 0) continue;

                Stage& transform = program.Stages[writer[input] - 1];

                const u32  outputs = transform.Activation == Activation::Pairwise ? transform.Width / 2
                                                                                  : transform.Width;
                const bool only    = context.Only(input) == dense.Node && !Headed(context, input);
                const bool shaped  = transform.Vector && dense.Width == 2 * outputs;

                if (!only || !shaped || !PackAbsorbable(outputs, target.Bytes)) continue;

                transform.Packed = true;
                dense.Packed     = true;
            }
        }

        template<typename G, s00 N>
        constexpr void PlanStages(
            const Context<G, N>&  context,
            const Target&         target ,
            const Array<bool, N>& owned  ,
                  Program<N>&     program
        )
        {
            for (s00 s = 0; s < program.StageCount; s++) {
                Stage& stage = program.Stages[s];

                if (stage.Kind == Kind::Dense               ) PlanMatmul   (context, target, stage);
                if (stage.Kind == Kind::AccumulatorTransform) PlanTransform(program, stage);
            }

            PlanPack     (context, target, program);
            PlanPointwise(context, owned , program);
        }

    }

    template<s00 N, typename G>
    consteval Program<N> Lower(const G& graph, const Array<IR::Fact, N>& facts, const Target& target)
    {
        Program<N> program {};

        const Detail::Context<G, N> context { graph, facts };

        for (s00 i = 0; i < N; i++)
            if (context.Root(i)) Detail::FormSlots(context, i, program);

        Detail::PairTwins(context, program);

        for (s00 i = 0; i < N; i++)
            if (graph.Nodes[i].Operation == IR::Op::Matmul) Detail::LowerMatmul(context, target, i, program);

        program.Fusable = program.StageCount > 0 && program.Stages[0].Kind == Kind::AccumulatorDot;

        const Array<bool, N> owned = Detail::Cover(context, program);

        Program<N> ordered = Detail::Order(program, owned);

        Detail::PlanStages(context, target, owned, ordered);

        return ordered;
    }

    template<s00 N>
    consteval Program<N> Combine(const Program<N>& program)
    {
        Program<N> combined { .Stages = program.Stages, .StageCount = program.StageCount, .Fusable = program.Fusable };

        Array<u16 , N> index  {};
        Array<bool, N> joined {};

        for (s00 s = 0; s < program.SlotCount; s++) {
            const Slot& slot   = program.Slots[s];
            const u16   target = Detail::Join(combined, slot);

            index[s] = target;

            if (target == combined.SlotCount) {
                combined.Slots[combined.SlotCount++] = slot;

                continue;
            }

            combined.Slots[target].FeatureSets |= slot.FeatureSets;
            combined.Slots[target].Bias      = combined.Slots[target].Bias || slot.Bias;
        }

        for (s00 s = 0; s < program.SlotCount; s++) {
            const u16 twin = program.Slots[s].Twin ? static_cast<u16>(index[program.Slots[s].Twin - 1] + 1) : 0;

            Slot& slot = combined.Slots[index[s]];

            slot.Twin = joined[index[s]] && slot.Twin != twin ? 0 : twin;

            joined[index[s]] = true;
        }

        for (s00 s = 0; s < combined.StageCount; s++) combined.Stages[s].Slots = 0;

        for (s00 s = 0; s < combined.StageCount; s++)
        for (s00 t = 0; t < program.SlotCount && t < 32; t++) {
            const bool reads = program.Stages[s].Slots >> t & 1;

            combined.Stages[s].Slots |= reads ? u32 { 1 } << index[t] : 0;
        }

        return combined;
    }

    template<s00 N, typename G>
    consteval bool SlotsExact(
        const G&                  graph      ,
        const Array<IR::Fact, N>& facts      ,
        const Program<N>&         program    ,
        const u32                 featureSets
    )
    {
        for (s00 s = 0; s < program.SlotCount; s++) {
            const Slot&     slot = program.Slots[s];
            const IR::Fact& fact = facts[slot.Root];
            const Interval  type = IR::RangeOf(slot.Type);

            const bool bounded = Licenses(fact.Provenance) && fact.Range.Min >= type.Min && fact.Range.Max <= type.Max;

            if ((slot.FeatureSets & featureSets) && !ModularSum(graph.Nodes[slot.Root]) && !bounded) return false;
        }

        return true;
    }

    template<s00 N>
    consteval Message Describe(const Stage& stage)
    {
        Message text {};

        text << KindNames[static_cast<s00>(stage.Kind)] << "<";

        if (stage.Kind == Kind::AccumulatorDot) {
            text << ActivationNames[static_cast<s00>(stage.Activation)] << "[" << stage.Low << "," << stage.High <<
                    "]," << ModeNames[static_cast<s00>(stage.Mode)] << ",K=" << i64 { stage.Chains } <<
                    (stage.Wide ? ",i64" : ",i32");

            if (stage.Buckets > 1) text << ",Select=" << i64 { stage.Buckets };

            return text << ">";
        }

        if (stage.Kind == Kind::AccumulatorTransform) {
            text << ActivationNames[static_cast<s00>(stage.Activation)] << "[" << stage.Low << "," << stage.High << "]";

            if (stage.Shift) text << ">>" << i64 { stage.Shift };

            if (stage.Activation == Activation::Pairwise) text << "," << ModeNames[static_cast<s00>(stage.Mode)];

            return text << "," << TypeNames[static_cast<s00>(stage.Output)] << ">";
        }

        if (stage.Kind == Kind::Pointwise) return text << i64 { stage.Rows } << ">";

        text << TypeNames[static_cast<s00>(stage.Input)] << "x" << TypeNames[static_cast<s00>(stage.Weight)] << "," <<
                i64 { stage.Rows } << (stage.Sparse ? ",Sparse" : "");

        if (stage.Mode == Mode::PackusDot) text << ",Dpbusd";
        if (stage.Mode == Mode::ZeroPoint) text << ",ZeroPoint";

        if (stage.Buckets > 1) text << ",Select=" << i64 { stage.Buckets };

        if (stage.Then != Activation::None)
            text << ",Then=" << ActivationNames[static_cast<s00>(stage.Then)] << "[" << stage.ThenLow << "," <<
                    stage.ThenHigh << "]";

        return text << ">";
    }

    template<s00 N>
    consteval Message Describe(const Program<N>& program)
    {
        Message text {};

        for (s00 s = 0; s < program.StageCount; s++) {
            const Message stage = Describe<N>(program.Stages[s]);

            if (s) text << " -> ";

            text << std::string_view { stage.data(), stage.size() };
        }

        return text;
    }

    template<s00 N>
    consteval Message Explain(const Stage& stage, const Capabilities& capabilities)
    {
        Message text = Describe<N>(stage);

        bool first = true;

        const auto item = [&](const std::string_view name) -> Message& {
            text << (first ? "" : ",") << name;

            first = false;

            return text;
        };

        const auto range = [&](const std::string_view name, const i64 low, const i64 high) {
            if (low != 0 || high != 0) item(name) << "=[" << low << "," << high << "]";
        };

        text << " plan{";

        if (stage.Form != Form::None) item("Form=") << FormNames[static_cast<s00>(stage.Form)];
        if (stage.Dot  != Dot ::None) item("Dot=" ) << DotNames [static_cast<s00>(stage.Dot )];
        if (stage.Test != Test::None) item("Test=") << TestNames[static_cast<s00>(stage.Test)];

        if (stage.Padded) item("Padded=") << i64 { stage.Padded };
        if (stage.Tile  ) item("Tile="  ) << i64 { stage.Tile   };
        if (stage.Sets  ) item("Sets="  ) << i64 { stage.Sets   };

        if (stage.Pairs   ) item("Pairs"   );
        if (stage.OneSided) item("OneSided");
        if (stage.BiasInit) item("BiasInit");
        if (stage.Narrow  ) item("Narrow"  );
        if (stage.Vector  ) item("Vector"  );
        if (stage.Packed  ) item("Packed"  );

        if (stage.Saturate) item("Saturate=") << i64 { stage.Saturate };

        if (stage.Kind == Kind::Dense) range("x", stage.Low, stage.High);

        range("w", stage.WeightLow, stage.WeightHigh);
        range("b", stage.BiasLow  , stage.BiasHigh  );

        const u32 groups = stage.Width / 4;

        if (stage.Form == Form::Sparse)
            item("Nnz=") << TierNames[static_cast<s00>(ChoiceOf(Choice::Nnz, capabilities, groups))] << "[" <<
                            RecordOf(Choice::Nnz, capabilities, groups) << "]";

        return text << "}";
    }

    template<s00 N>
    consteval Array<Message, N> Explain(const Program<N>& program, const Capabilities& capabilities)
    {
        Array<Message, N> lines {};

        for (s00 s = 0; s < program.StageCount; s++) lines[s] = Explain<N>(program.Stages[s], capabilities);

        return lines;
    }

    consteval Message Explain(const std::string_view featureSet, const Choice choice, const Capabilities& capabilities)
    {
        Message text {};

        return text << featureSet << ": tier=" << TierNames[static_cast<s00>(ChoiceOf(choice, capabilities))] << " [" <<
                       RecordOf(choice, capabilities, 0) << "]";
    }

}

#endif //MANTARAY_LOWERING_LOWERING_H
