//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_RUNTIME_NETWORK_H
#define MANTARAY_RUNTIME_NETWORK_H

#include <algorithm>
#include <atomic>
#include <bit>
#include <cassert>
#include <cstddef>
#include <optional>
#include <span>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

#include "Delta.h"
#include "../Common.h"
#include "../Model.h"
#include "../Backend/Backend.h"
#include "../FeatureSet/FeatureSet.h"
#include "../IO/Loader.h"
#include "../IR/Analysis.h"
#include "../IR/GraphIR.h"
#include "../Lowering/Lowering.h"

namespace MantaRay
{

    enum class Accumulators : u08 { Split, Combined };

    namespace Detail
    {

        inline std::atomic<u64> NextGeneration { 1 };

        constexpr inline u16 NoNode = 0xFFFF;

        constexpr inline u32 TransposeTile = 64;

        template<typename G>
        consteval u16 TermOf(const G& graph, const u16 node, const IR::Op op)
        {
            const IR::Node& spec = graph.Nodes[node];

            if (spec.Operation == op) return node;

            const bool linear = spec.Operation == IR::Op::Add || spec.Operation == IR::Op::Wrap ||
                                spec.Operation == IR::Op::Verify;

            if (!linear) return NoNode;

            for (s00 k = 0; k < spec.InputCount; k++)
                if (const u16 term = TermOf(graph, spec.Inputs[k], op); term != NoNode) return term;

            return NoNode;
        }

        template<typename G>
        consteval u32 FeaturesOf(const G& graph, const u16 sparse)
        {
            return sparse == NoNode ? 0 : graph.Nodes[graph.Nodes[sparse].Inputs[0]].Size;
        }

        template<typename G>
        consteval u16 RowTensorOf(const G& graph, const u16 sparse)
        {
            return sparse == NoNode ? 0 : static_cast<u16>(graph.Nodes[sparse].Tensor - 1);
        }

        template<typename G>
        consteval u16 BiasOf(const G& graph, const Lowering::Slot& slot)
        {
            return slot.Bias ? TermOf(graph, slot.Root, IR::Op::Parameter) : NoNode;
        }

        template<typename G>
        consteval u16 UserOf(const G& graph, const u16 node)
        {
            for (s00 user = node + s00 { 1 }; user < G::NodeCount; user++) {
                const IR::Node& spec = graph.Nodes[user];

                if (spec.InputCount > 0 && spec.Inputs[0] == node) return static_cast<u16>(user);
            }

            return NoNode;
        }

        template<typename G>
        consteval s00 ChainLength(const G& graph, u16 node, const u16 head)
        {
            s00 length = 0;

            for (; node != head && node != NoNode; length++) node = UserOf(graph, node);

            return length;
        }

        template<s00 Length, typename G>
        consteval Array<u16, Length> Chain(const G& graph, u16 node)
        {
            Array<u16, Length> chain {};

            for (s00 i = 0; i < Length; i++) chain[i] = node = UserOf(graph, node);

            return chain;
        }

        template<s00 N>
        consteval u16 SlotOf(const Lowering::Program<N>& program, const u32 slots, const IR::Dependence perspective)
        {
            for (s00 s = 0; s < program.SlotCount && s < 32; s++)
                if ((slots >> s & 1) && program.Slots[s].Perspective == perspective) return static_cast<u16>(s);

            return 0;
        }

        constexpr bool EpilogueStep(const IR::Op op)
        {
            return op == IR::Op::Add || op == IR::Op::Divide || op == IR::Op::ShiftRight || op == IR::Op::Select;
        }

        consteval Rational HeadFactor(const Rational head, const Rational scale)
        {
            return Reduce(i128 { head.Numerator } * scale.Denominator, i128 { head.Denominator } * scale.Numerator);
        }

        template<typename G, typename Facts>
        consteval s00 LanesOf(const G& graph, const Facts& facts)
        {
            s00 lanes = 0;

            for (const IR::Head& head : graph.Heads) lanes += facts[head.Node].Size;

            return lanes;
        }

        template<typename F>
        consteval bool BoardAtPush()
        {
            if (!FeatureSet<F>) return false;

            return DerivedFeatureSet<F> || !requires { F::Trigger::KeyOf(u08 {}, u08 {}); };
        }

        template<typename F>
        consteval bool BoardAtEval()
        {
            if constexpr (FeatureSet<F>) return F::Trigger::KeyCount > 1 || !IncrementalOf<F>();

            return !requires { F::OfCount(u08 {}); };
        }

        template<typename... All>
        consteval u32 DerivedOf(List<All...>)
        {
            u32 mask  = 0;
            u32 index = 0;

            ((mask |= DerivedFeatureSet<All> ? u32 { 1 } << index : 0, index++), ...);

            return mask;
        }

        template<typename... All>
        consteval bool AnyBoardAtPush(List<All...>) { return (BoardAtPush<All>() || ...); }

        template<typename... All>
        consteval bool AnyBoardAtEval(List<All...>) { return (BoardAtEval<All>() || ...); }

        template<typename V>
        struct Aligned
        {

            alignas(Alignment) V Values;

        };

        template<auto D, const Lowering::Target& T>
        constexpr inline Lowering::Program<Model<D>::Nodes> LoweredOf = Model<D>::Ok ?
                         Lowering::Lower  <Model<D>::Nodes>(Model<D>::Graph, Model<D>::Facts, T) :
                         Lowering::Program<Model<D>::Nodes> {};

        template<typename G>
        consteval s00 CountOf(const G& graph, const u16 node, const IR::Op op)
        {
            const IR::Node& spec = graph.Nodes[node];

            if (spec.Operation == op) return 1;

            if (!Lowering::Detail::Absorbing(spec.Operation)) return 0;

            s00 count = 0;

            for (s00 k = 0; k < spec.InputCount; k++) count += CountOf(graph, spec.Inputs[k], op);

            return count;
        }

        template<auto D, const Lowering::Target& T>
        consteval bool SingleDot()
        {
            using M = Model<D>;

            constexpr const Lowering::Program<M::Nodes>& Program = LoweredOf<D, T>;

            const Lowering::Stage& stage = Program.Stages[0];

            if (Program.StageCount != 1 || stage.Kind != Lowering::Kind::AccumulatorDot) return false;

            if (Program.SlotCount != 2 || std::popcount(stage.Slots) != 2) return false;

            if (AnyBoardAtPush(typename M::Bindings {})) return false;

            for (s00 s = 0; s < 2; s++) {
                const Lowering::Slot& slot = Program.Slots[s];

                if (!std::has_single_bit(slot.FeatureSets) || !slot.Incremental || slot.Shared) return false;

                if (CountOf(M::Graph, slot.Root, IR::Op::SparseMatmul) != 1) return false;

                if (CountOf(M::Graph, slot.Root, IR::Op::Parameter) > 1) return false;
            }

            return true;
        }

        template<auto D, const Lowering::Target& T>
        concept Staged = Accepted<D> && !SingleDot<D, T>();

        struct Leaves
        {

            u16  Lead     = 0;
            u16  Terms    = 0;
            u16  Biases   = 0;
            bool Overflow = false;

            Array<u16, IR::MaxFeatureSet> Sparse     {};
            Array<u16, IR::MaxFeatureSet> Parameters {};

        };

        template<typename G, typename Facts>
        consteval void Collect(
            const G&      graph      ,
            const Facts&  facts      ,
            const u16     node       ,
            const u32     featureSets,
                  Leaves& leaves
        )
        {
            const IR::Node& spec = graph.Nodes[node];

            if (spec.Operation == IR::Op::SparseMatmul) {
                if ((facts[node].FeatureSets & featureSets) == 0) return;

                leaves.Overflow = leaves.Overflow || leaves.Terms == IR::MaxFeatureSet;

                if (leaves.Terms < IR::MaxFeatureSet) leaves.Sparse[leaves.Terms++] = node;

                return;
            }

            if (spec.Operation == IR::Op::Parameter) {
                leaves.Overflow = leaves.Overflow || leaves.Biases == IR::MaxFeatureSet;

                if (leaves.Biases < IR::MaxFeatureSet) leaves.Parameters[leaves.Biases++] = node;

                return;
            }

            if (!Lowering::Detail::Absorbing(spec.Operation)) return;

            for (s00 k = 0; k < spec.InputCount; k++) Collect(graph, facts, spec.Inputs[k], featureSets, leaves);
        }

        template<typename M, s00 S>
        consteval Array<Leaves, S> LeavesOf(const Lowering::Program<M::Nodes>& program)
        {
            Array<Leaves, S> leaves {};

            for (s00 s = 0; s < S; s++) {
                const Lowering::Slot& slot = program.Slots[s];

                Collect(M::Graph, M::Facts, slot.Root, slot.FeatureSets, leaves[s]);

                leaves[s].Lead   = slot.Twin != 0 && slot.Twin - s00 { 1 } < s ? static_cast<u16>(slot.Twin - 1)
                                                                               : static_cast<u16>(s);
                leaves[s].Biases = slot.Bias ? leaves[s].Biases : u16 { 0 };
            }

            return leaves;
        }

        template<s00 S>
        consteval Array<u16, S + 1> FirstOf(const Array<Leaves, S>& leaves)
        {
            Array<u16, S + 1> first {};

            for (s00 s = 0; s < S; s++) first[s + 1] = first[s] + (leaves[s].Lead == s ? leaves[s].Terms : 0);

            return first;
        }

        template<s00 TermCount, s00 S>
        consteval Array<u16, TermCount, 2> OwnersOf(const Array<Leaves, S>& leaves, const Array<u16, S + 1>& first)
        {
            Array<u16, TermCount, 2> owners {};

            for (s00 s = 0; s < S; s++)
            for (s00 t = 0; t < leaves[s].Terms && leaves[s].Lead == s; t++) {
                owners[first[s] + t][0] = static_cast<u16>(s);
                owners[first[s] + t][1] = static_cast<u16>(t);
            }

            return owners;
        }

        template<s00 N>
        consteval s00 ParameterCountOf(const Backend::Kernel::Plan<N>& plan)
        {
            s00 count = 0;

            for (const Backend::Kernel::Place& place : plan.Places)
                count += place.Source == Backend::Kernel::Source::Parameter;

            return count;
        }

        template<s00 Count, s00 N>
        consteval Array<u16, Count> ParametersOf(const Backend::Kernel::Plan<N>& plan)
        {
            Array<u16, Count> parameters {};

            s00 count = 0;

            for (s00 i = 0; i < plan.Places.size(); i++)
                if (plan.Places[i].Source == Backend::Kernel::Source::Parameter)
                    parameters[count++] = static_cast<u16>(i);

            return parameters;
        }

        struct Roles
        {

            u16 StmCount = 0;
            u16 NtmCount = 0;

            Array<u16, 32> Stm {};
            Array<u16, 32> Ntm {};

        };

        static_assert(sizeof(Roles) == 66 * sizeof(u16), "Roles is a template argument and must have no padding");

        template<s00 N>
        consteval Roles RolesOf(const Lowering::Program<N>& program, const u32 slots)
        {
            u16 stm = NoNode;
            u16 ntm = NoNode;

            for (s00 s = 0; s < program.SlotCount && s < 32; s++) {
                if (!(slots >> s & 1)) continue;

                if (program.Slots[s].Perspective == IR::Dependence::Stm) stm = program.Slots[s].Root;
                if (program.Slots[s].Perspective == IR::Dependence::Ntm) ntm = program.Slots[s].Root;
            }

            Roles roles {};

            for (s00 s = 0; s < program.SlotCount && s < 32; s++) {
                if (!(slots >> s & 1)) continue;

                if (program.Slots[s].Root == stm) roles.Stm[roles.StmCount++] = static_cast<u16>(s);
                if (program.Slots[s].Root == ntm) roles.Ntm[roles.NtmCount++] = static_cast<u16>(s);
            }

            return roles;
        }

        template<typename C, s00 N>
        consteval void Own(const C& context, const Lowering::Program<N>& program, Backend::Kernel::Plan<N>& plan)
        {
            Array<bool, N> owned {};

            for (s00 i = 0; i < N; i++) owned[i] = context.At(i).Operation == IR::Op::Constant;

            for (s00 s = 0; s < program.SlotCount; s++)
                Lowering::Detail::CoverTerms(context, program.Slots[s].Root, owned);

            for (s00 s = 0; s < program.StageCount; s++) {
                const Lowering::Stage& stage = program.Stages[s];

                if (stage.Kind == Lowering::Kind::Pointwise) continue;

                const IR::Node&      spec   = context.At(stage.Node);
                const Array<bool, N> before = owned;

                if (stage.Kind == Lowering::Kind::AccumulatorTransform)
                    Lowering::Detail::CoverPrologue(context, stage.Node, owned);
                else {
                    Lowering::Stage replay = stage;

                    replay.Requant   = IR::Op::None;
                    replay.Wrap      = IR::DType::None;
                    replay.Unfused   = false;
                    replay.Factor    = {};
                    replay.Then      = Lowering::Activation::None;
                    replay.ThenLow   = 0;
                    replay.ThenHigh  = 0;
                    replay.ThenShift = 0;

                    if (stage.Kind == Lowering::Kind::Dense) {
                        replay.Shift = 0;
                        replay.Bias  = spec.InputCount == 2 ? Lowering::Detail::ParameterOf(context, spec.Inputs[1])
                                                            : u16 { 0 };
                    }

                    owned[stage.Node] = true;

                    for (s00 k = 1; k < spec.InputCount; k++) owned[spec.Inputs[k]] = true;

                    if (stage.Kind == Lowering::Kind::AccumulatorDot)
                        Lowering::Detail::CoverPrologue(context, spec.Inputs[0], owned);

                    if (context.Split(spec.Inputs[0])) owned[spec.Inputs[0]] = true;

                    const u16 end = Lowering::Detail::CoverEpilogue(context, replay, owned);

                    if (stage.Kind == Lowering::Kind::Dense) {
                        replay.Output = context.Facts[end].Storage;

                        Lowering::Detail::Absorb(context, end, replay, owned);
                    }

                    plan.Supported = plan.Supported && replay == stage;
                }

                for (s00 i = 0; i < N; i++)
                    if (owned[i] && !before[i]) plan.Owner[i] = static_cast<u16>(s + 1);
            }

            u16 previous = 0;

            for (s00 s = 0; s < program.StageCount; s++) {
                const Lowering::Stage& stage = program.Stages[s];

                if (stage.Kind != Lowering::Kind::Pointwise) {
                    previous = std::max(previous, stage.Node);

                    continue;
                }

                u32 count = 0;

                for (s00 i = previous; i < stage.Node; i++) {
                    if (owned[i]) continue;

                    owned     [i] = true;
                    plan.Owner[i] = static_cast<u16>(s + 1);

                    count++;
                }

                plan.Supported = plan.Supported && count == stage.Rows;
            }

            for (s00 i = 0; i < N; i++) plan.Supported = plan.Supported && (owned[i] || context.UserCount[i] == 0);
        }

        template<typename G>
        consteval bool Headed(const G& graph, const u16 node)
        {
            for (const IR::Head& head : graph.Heads)
                if (head.Node == node) return true;

            return false;
        }

        template<typename C, s00 N>
        consteval bool Leaving(const C& context, const Backend::Kernel::Plan<N>& plan, const u16 node)
        {
            const u16 owner = plan.Owner[node];

            if (owner == 0 || context.At(node).Operation == IR::Op::Parameter) return false;

            if (Headed(context.Graph, node)) return true;

            for (s00 k = 0; k < context.UserCount[node]; k++)
                if (plan.Owner[context.User(node, k)] != owner) return true;

            return false;
        }

        constexpr u32 Allocate(Array<u32, Backend::Kernel::DTypes>& sizes, const IR::DType type, const u32 count)
        {
            const u32 lanes  = static_cast<u32>(Alignment / IR::BytesOf(type));
            const u32 offset = sizes[static_cast<s00>(type)];

            sizes[static_cast<s00>(type)] += (count + lanes - 1) / lanes * lanes;

            return offset;
        }

        template<typename C, s00 N>
        consteval bool Evaluated(const C& context, const Backend::Kernel::Plan<N>& plan, const u16 user)
        {
            const u16 owner = plan.Owner[user];

            if (owner == 0) return false;

            const Lowering::Kind kind = plan.Stages[owner - 1].Kind;

            if (kind == Lowering::Kind::Pointwise || kind == Lowering::Kind::AccumulatorDot) return true;

            return kind == Lowering::Kind::Dense && context.At(user).Operation == IR::Op::Matmul;
        }

        template<s00 N>
        consteval bool Root(const Lowering::Program<N>& program, const u16 node)
        {
            for (s00 s = 0; s < program.SlotCount; s++)
                if (program.Slots[s].Root == node) return true;

            return false;
        }

        template<typename C, s00 N>
        consteval void Place(const C& context, const Lowering::Program<N>& program, Backend::Kernel::Plan<N>& plan)
        {
            const auto buffer = [&](const u16 node, const IR::DType type, const u32 offset) {
                plan.Supported    = plan.Supported && plan.Places[node].Source == Backend::Kernel::Source::Inline;
                plan.Places[node] = { .Source = Backend::Kernel::Source::Buffer, .Type = type, .Offset = offset };
            };

            const auto operand = [&](const u16 node, const IR::DType type, const u32 offset, const bool dense) {
                if (context.At(node).Operation != IR::Op::Parameter && !Root(program, node)) {
                    buffer(node, type, offset);

                    return;
                }

                plan.Supported    = plan.Supported && dense &&
                                    plan.Copies[node].Source == Backend::Kernel::Source::Inline;
                plan.Copies[node] = { .Source = Backend::Kernel::Source::Buffer, .Type = type, .Offset = offset };
            };

            for (s00 s = 0; s < program.StageCount; s++) {
                const Lowering::Stage& stage = program.Stages[s];

                if (stage.Kind != Lowering::Kind::Dense && stage.Kind != Lowering::Kind::AccumulatorDot) continue;

                const u16 input = context.At(stage.Node).Inputs[0];

                if (stage.Kind == Lowering::Kind::AccumulatorDot)
                    buffer(
                        stage.Node,
                        context.Facts[stage.Node].Storage,
                        Allocate(plan.Values, context.Facts[stage.Node].Storage, context.Facts[stage.Node].Size)
                    );

                if (!context.Split(input)) continue;

                const IR::Node& concat = context.At(input);
                const IR::DType type   = context.Facts[input].Storage;
                const u32       offset = Allocate(plan.Values, type, context.Facts[input].Size);
                const bool      dense  = stage.Kind == Lowering::Kind::Dense;

                buffer (input           , type, offset                                              );
                operand(concat.Inputs[0], type, offset                                       , dense);
                operand(concat.Inputs[1], type, offset + context.Facts[concat.Inputs[0]].Size, dense);
            }

            for (s00 i = 0; i < N; i++) {
                const IR::Node& spec = context.At(i);

                if (spec.Operation == IR::Op::Constant)
                    plan.Places[i] = { .Source = Backend::Kernel::Source::Constant };

                if (!Leaving(context, plan, i) || plan.Places[i].Source != Backend::Kernel::Source::Inline) continue;

                const IR::DType type = context.Facts[i].Storage;

                buffer(i, type, Allocate(plan.Values, type, context.Facts[i].Size));
            }

            for (s00 s = 0; s < program.SlotCount && s < 32; s++) {
                Backend::Kernel::Place& place = plan.Places[program.Slots[s].Root];

                place.Source  = Backend::Kernel::Source::Slots;
                place.Type    = program.Slots[s].Type;
                place.Slots  |= u32 { 1 } << s;
            }

            for (s00 i = 0; i < N; i++) {
                if (context.At(i).Operation != IR::Op::Parameter) continue;

                bool read = Headed(context.Graph, i) || plan.Copies[i].Source == Backend::Kernel::Source::Buffer;

                for (s00 k = 0; k < context.UserCount[i]; k++)
                    read = read || Evaluated(context, plan, context.User(i, k));

                if (!read) continue;

                const IR::DType type = context.Facts[i].Storage;

                plan.Places[i] = {
                    .Source = Backend::Kernel::Source::Parameter,
                    .Type   = type,
                    .Offset = Allocate(plan.Parameters, type, context.Facts[i].Size)
                };
            }

            for (s00 i = 0; i < N; i++) {
                if (!Leaving(context, plan, i)) continue;

                const u16              owner = plan.Owner[i];
                const Lowering::Stage& stage = program.Stages[owner - 1];

                if (stage.Kind == Lowering::Kind::Pointwise) continue;

                plan.Supported        = plan.Supported && plan.Exits[owner - 1] == 0;
                plan.Exits[owner - 1] = static_cast<u16>(i);
            }
        }

        template<const auto& Program, s00 I, typename ISA, Lowering::Kind K = Program.Stages[I].Kind>
        struct Layer { using Type = Absent<0>; };

        template<const auto& Program, s00 I, typename ISA>
        struct Layer<Program, I, ISA, Lowering::Kind::Dense>
        {

            using Type = Backend::Kernel::Dense<Program, I, ISA>::Parameters;

        };

        template<const auto& Program, s00 I, typename ISA>
        struct Layer<Program, I, ISA, Lowering::Kind::AccumulatorDot>
        {

            using Weight = Backend::Kernel::AccumulatorDot<Program, I, ISA>::Weight;

            using Type = Aligned<Array<Weight, Program.Stages[I].Buckets * 2 * Program.Stages[I].Width>>;

        };

        constexpr bool Readable(const Backend::Kernel::Source source)
        { return source == Backend::Kernel::Source::Buffer || source == Backend::Kernel::Source::Parameter; }

        template<typename M>
        consteval Backend::Kernel::Plan<M::Nodes> PlanOf(const Lowering::Program<M::Nodes>& program)
        {
            constexpr s00 N = M::Nodes;

            using G = std::remove_cvref_t<decltype(M::Graph)>;

            const Lowering::Detail::Context<G, N> context(M::Graph, M::Facts);

            Backend::Kernel::Plan<N> plan {};

            static_cast<Lowering::Program<N>&>(plan) = program;

            plan.Nodes = M::Graph.Nodes;
            plan.Facts = M::Facts;

            Own  (context, program, plan);
            Place(context, program, plan);

            for (s00 s = 0; s < program.StageCount; s++) {
                const Lowering::Stage& stage = program.Stages[s];
                const u16              exit  = plan.Exits[s];

                if (stage.Kind == Lowering::Kind::Pointwise) continue;

                const bool transform = stage.Kind == Lowering::Kind::AccumulatorTransform;
                const bool written   = plan.Places[exit].Source == Backend::Kernel::Source::Buffer;
                const bool typed     = plan.Places[exit].Type   == stage.Output;

                const bool dot      = stage.Kind == Lowering::Kind::AccumulatorDot;
                const bool selected = context.Facts[exit].Size == 1;

                plan.Supported = plan.Supported && exit != 0 && written && (!transform || exit == stage.Node);
                plan.Supported = plan.Supported && (stage.Kind != Lowering::Kind::Dense || typed);
                plan.Supported = plan.Supported && (!transform || typed) && (!dot || selected);

                if (stage.Kind != Lowering::Kind::Dense) continue;

                const Backend::Kernel::Place input = plan.Places[context.At(stage.Node).Inputs[0]];

                plan.Supported = plan.Supported && Readable(input.Source) && input.Type == stage.Input;
            }

            for (const IR::Head& head : M::Graph.Heads)
                plan.Supported = plan.Supported && Readable(plan.Places[head.Node].Source);

            Backend::Kernel::Saturate(plan, M::Graph.Heads);

            return plan;
        }

    }

    template<auto D, const Lowering::Target& T = Lowering::Native>
    class Network
    {

        using M   = MantaRay::Model<D>;
        using ISA = Backend::ISAOf<T>;

        constexpr static Lowering::Program<M::Nodes> Lowered = M::Ok ? Lowering::Lower<M::Nodes>(M::Graph, M::Facts, T)
                                                                     : Lowering::Program<M::Nodes> {};

        constexpr static Lowering::Stage Stage = Lowered.Stages[0];

        constexpr static u16 Stm = Detail::SlotOf(Lowered, Stage.Slots, IR::Dependence::Stm);
        constexpr static u16 Ntm = Detail::SlotOf(Lowered, Stage.Slots, IR::Dependence::Ntm);

        constexpr static bool Twins   = Lowered.Slots[Ntm].Twin == Stm + 1;
        constexpr static u08  Sets    = Twins ? 1 : 2;
        constexpr static u32  Width   = Stage.Width;
        constexpr static u32  Inputs  = 2 * Width;
        constexpr static u32  Buckets = Stage.Buckets;

        constexpr static Array<u16, 2> Sparse {
            Detail::TermOf(M::Graph, Lowered.Slots[Stm].Root, IR::Op::SparseMatmul),
            Detail::TermOf(M::Graph, Lowered.Slots[Ntm].Root, IR::Op::SparseMatmul)
        };
        constexpr static Array<u16, 2> Bias {
            Detail::BiasOf(M::Graph, Lowered.Slots[Stm]),
            Detail::BiasOf(M::Graph, Lowered.Slots[Ntm])
        };

        constexpr static u32 Features = Detail::FeaturesOf(M::Graph, Sparse[0]);

        using S = std::conditional_t<Lowered.Slots[Stm].Type == IR::DType::I32, i32, i16>;
        using W = IO::Tensors<M>::template Element<Detail::RowTensorOf(M::Graph, Sparse[0])>;
        using O = std::conditional_t<Stage.Mode == Lowering::Mode::PackusDot, i08, i16>;

        constexpr static u16 Head  = M::Graph.Heads[0].Node;
        constexpr static s00 Steps = Detail::ChainLength(M::Graph, Stage.Node, Head);

        constexpr static Array<u16, Steps> Epilogue = Detail::Chain<Steps>(M::Graph, Stage.Node);

        constexpr static Message Text = Lowering::Describe(Lowered);

        static_assert(Width * sizeof(W) % Alignment == 0, "feature rows must stay 64-byte aligned");

        alignas(Alignment) Array<W  , Sets, Features, Width> Rows    {};
        alignas(Alignment) Array<S  , Sets,           Width> Biases  {};
        alignas(Alignment) Array<O  , Buckets * Inputs     > Weights {};
        alignas(Alignment) Array<i32, Steps, Buckets       > Offsets {};

        std::optional<IO::Tensors<M>> Tensors {};

        u64 Stamp = 0;

        template<u08 I>
        void AssignSlot(const IO::Tensors<M>& tensors) noexcept
        {
            constexpr IR::Node Spec    = M::Graph.Nodes[Sparse[I]];
            constexpr u32      Columns = M::Graph.Tensors[Spec.Tensor - 1].Columns;

            const auto rows = tensors.template View<Spec.Tensor - 1>();

            for (u32 top  = 0  ; top  < Width   ; top  += Detail::TransposeTile)
            for (u32 left = 0  ; left < Features; left += Detail::TransposeTile)
            for (u32 o = top; o < std::min(top + Detail::TransposeTile, Width); o++) {
                const auto source = rows.subspan(u64 { Spec.Begin + o } * Columns + Spec.Offset);

                for (u32 feature = left; feature < std::min(left + Detail::TransposeTile, Features); feature++)
                    Rows[I][feature][o] = static_cast<W>(source[feature]);
            }

            if constexpr (Bias[I] != Detail::NoNode) {
                constexpr IR::Node Parameter = M::Graph.Nodes[Bias[I]];

                const auto biases = tensors.template View<Parameter.Tensor - 1>();

                for (s00 o = 0; o < Width; o++) Biases[I][o] = static_cast<S>(biases[Parameter.Begin + o]);
            }
        }

        void AssignWeights(const IO::Tensors<M>& tensors)
        {
            constexpr IR::Node Spec    = M::Graph.Nodes[Stage.Node];
            constexpr u32      Columns = M::Graph.Tensors[Spec.Tensor - 1].Columns;

            using E = IO::Tensors<M>::template Element<Spec.Tensor - 1>;

            const auto weights = tensors.template View<Spec.Tensor - 1>();

            std::vector<E> logical(u64 { Buckets } * Inputs);

            for (s00 b = 0; b < Buckets; b++)
                std::copy_n(
                    weights.subspan(u64 { Spec.Begin + b } * Columns + Spec.Offset).begin(),
                    Inputs,
                    logical.begin() + u64 { b } * Inputs
                );

            Backend::Kernel::AccumulatorDot<Program, 0, ISA>::Assign(std::span<const E>(logical), Weights.data());
        }

        template<s00 I>
        void AssignOffsets(const IO::Tensors<M>& tensors) noexcept
        {
            constexpr IR::Node Step = M::Graph.Nodes[Epilogue[I]];

            if constexpr (Step.Operation == IR::Op::Add) {
                constexpr IR::Node Operand  = M::Graph.Nodes[Step.Inputs[1]];
                constexpr bool     Selected = Operand.Operation == IR::Op::Select;
                constexpr bool     Bucketed = Selected || M::Facts[Epilogue[I]].Size > 1;
                constexpr IR::Node Spec     = Selected ? M::Graph.Nodes[Operand.Inputs[0]] : Operand;

                const auto biases = tensors.template View<Spec.Tensor - 1>();

                for (s00 b = 0; b < Buckets; b++)
                    Offsets[I][b] = static_cast<i32>(biases[Spec.Begin + (Bucketed ? b : 0)]);
            }
        }

        template<u08... I>
        void AssignSlots(const IO::Tensors<M>& tensors, const std::integer_sequence<u08, I...>) noexcept
        { (AssignSlot<I>(tensors), ...); }

        template<s00... I>
        void AssignEpilogue(const IO::Tensors<M>& tensors, const std::index_sequence<I...>) noexcept
        { (AssignOffsets<I>(tensors), ...); }

        void Assign(const IO::Tensors<M>& tensors)
        {
            AssignSlots(tensors, std::make_integer_sequence<u08, Sets> {});
            AssignWeights(tensors);
            AssignEpilogue(tensors, std::make_index_sequence<Steps> {});
        }

        template<u08 I, typename Board>
        void Refresh(const u08 perspective, const Board& board, Array<S, Width>& values) const noexcept
        {
            using F = M::template Binding<M::Graph.Nodes[M::Graph.Nodes[Sparse[I]].Inputs[0]].Binding - 1>;

            Array<const W*, F::MaxActive> rows;

            u32 count = 0;

            F::Active(perspective, board, [&](const u32 feature) {
                assert(count < F::MaxActive);

                if (count < F::MaxActive) rows[count++] = FeatureRow(I, feature);
            });

            Backend::Kernel::Refresh<ISA, Width>(
                FeatureBias(I),
                std::span<const W* const>(rows.data(), count),
                values.data()
            );
        }

        template<s00 I>
        [[clang::always_inline]]
        i64 Step(const i64 value, const s00 row) const noexcept
        {
            constexpr IR::Node Spec    = M::Graph.Nodes[Epilogue[I]];
            constexpr i64      Divisor = Spec.Operation == IR::Op::Divide ? Spec.Low.Numerator : 1;

            static_assert(
                Detail::EpilogueStep(Spec.Operation),
                "an AccumulatorDot epilogue step is a bias, a Divide, a ShiftRight or a Select"
            );

            if (Spec.Operation == IR::Op::Divide    ) return value /  Divisor;
            if (Spec.Operation == IR::Op::ShiftRight) return value >> Spec.Shift;
            if (Spec.Operation == IR::Op::Add       ) return value +  Offsets[I][row];

            return value;
        }

        [[clang::always_inline]]
        constexpr static i32 Scale(const i64 value) noexcept
        {
            constexpr Rational Reduced = Detail::HeadFactor(M::Graph.Heads[0].Scale, M::Facts[Head].Scale);
            constexpr i64      Factor  = Reduced.Numerator  ;
            constexpr i64      Divisor = Reduced.Denominator;
            constexpr Interval Range   = M::Facts[Head].Range * Interval { .Min = Factor, .Max = Factor };
            constexpr bool     Narrow  = Fits<i32>(Range) && Fits<i32>(Interval { .Min = Factor , .Max = Factor  }) &&
                                                             Fits<i32>(Interval { .Min = Divisor, .Max = Divisor });

            if (Narrow) return static_cast<i32>(value) * static_cast<i32>(Factor) / static_cast<i32>(Divisor);

            if (Bounded(Range)) return static_cast<i32>(value * Factor / Divisor);

            return static_cast<i32>(Detail::i128 { value } * Factor / Divisor);
        }

        template<s00... I>
        [[clang::always_inline]]
        i32 Finish(i64 value, const s00 row, const std::index_sequence<I...>) const noexcept
        {
            ((value = Step<I>(value, row)), ...);

            return Scale(value);
        }

        public:
        using Model    = M;
        using Bindings = M::Bindings;

        constexpr static Lowering::Program<Model::Nodes> Program = Lowered;

        constexpr static bool Fusable          = Program.Fusable;
        constexpr static bool NeedsBoard       = Detail::AnyBoardAtPush(Bindings {});
        constexpr static bool NeedsBoardAtEval = Detail::AnyBoardAtEval(Bindings {});
        constexpr static s00  Outputs          = Detail::LanesOf(Model::Graph, Model::Facts);

        template<s00 Slot>
        using SlotType = std::conditional_t<Program.Slots[Slot].Type == IR::DType::I32, i32, i16>;

        [[nodiscard]]
        LoadResult Load(const std::span<const std::byte> bytes) noexcept
        {
            IO::Tensors<M> tensors {};

            if (const LoadResult result = IO::Load(bytes, tensors); !result) return result;

            Assign(tensors);

            Tensors = std::move(tensors);
            Stamp   = Detail::NextGeneration.fetch_add(1, std::memory_order_relaxed);

            return {};
        }

        [[nodiscard]]
        std::vector<std::byte> Save() const
        {
            if (Tensors) return IO::Save(*Tensors);

            return IO::Save(IO::Tensors<M> {});
        }

        [[nodiscard]]
        u64 Generation() const noexcept { return Stamp; }

        [[nodiscard]]
        constexpr static std::string_view Describe() noexcept { return { Text.data(), Text.size() }; }

        template<typename Board>
        [[nodiscard]]
        i32 Evaluate(const Board& board) const noexcept
        {
            const u08 stm = board.SideToMove();

            alignas(Alignment) Array<S, 2, Width> values;

            Refresh<0       >(stm                      , board, values[0]);
            Refresh<Sets - 1>(static_cast<u08>(stm ^ 1), board, values[1]);

            return Forward(
                Detail::Read<ISA, S> { .Values = values[0].data() },
                Detail::Read<ISA, S> { .Values = values[1].data() },
                Bucket(board)
            );
        }

        template<typename Board>
        [[nodiscard]]
        Array<i32, Outputs> EvaluateAll(const Board& board) const noexcept
        {
            static_assert(Outputs == 1, "a single AccumulatorDot program has one output lane");

            return { Evaluate(board) };
        }

        template<typename Board>
        [[nodiscard]]
        static s00 Bucket(const Board& board) noexcept
        {
            constexpr u16 Selected = M::Facts[Stage.Node].Selector;

            if constexpr (Selected == 0) return 0;
            else return M::template Binding<Selected - 1>::Of(board);
        }

        [[nodiscard]]
        [[clang::always_inline]]
        const W* FeatureRow(const u08 set, const u32 index) const noexcept
        {
            assert(set < Sets && index < Features);

            return Rows[set][index].data();
        }

        [[nodiscard]]
        [[clang::always_inline]]
        const S* FeatureBias(const u08 set) const noexcept
        {
            assert(set < Sets);

            return Biases[set].data();
        }

        template<typename Left, typename Right>
        [[nodiscard]]
        [[clang::always_inline]]
        i32 Forward(const Left& stm, const Right& ntm, const s00 bucket) const noexcept
        {
            assert(bucket < Buckets || Buckets == 1);

            const s00 row = Buckets == 1 ? 0 : bucket;

            const i64 sum = Backend::Kernel::AccumulatorDot<Program, 0, ISA>::Run(
                stm,
                ntm,
                Weights.data() + row * Inputs
            );

            return Finish(sum, row, std::make_index_sequence<Steps> {});
        }

        template<typename Left, typename Right>
        [[nodiscard]]
        [[clang::always_inline]]
        i32 Forward(const Left& white, const Right& black, const u08 stm, const s00 bucket) const noexcept
        {
            assert(bucket < Buckets || Buckets == 1);

            const s00 row = Buckets == 1 ? 0 : bucket;

            const i64 sum = Backend::Kernel::AccumulatorDot<Program, 0, ISA>::Run(
                white,
                black,
                stm,
                Weights.data() + row * Inputs
            );

            return Finish(sum, row, std::make_index_sequence<Steps> {});
        }

    };

    template<auto D, const Lowering::Target& T> requires (Detail::Refused<D>)
    class Network<D, T>
    {

        static_assert(Detail::Rejected<Detail::Pipeline<D>::Report>, "the network declaration is invalid");

    };

    template<auto D, const Lowering::Target& T> requires (Detail::Staged<D, T>)
    class Network<D, T>
    {

        using M   = MantaRay::Model<D>;
        using ISA = Backend::ISAOf<T>;

        constexpr static Lowering::Program    <M::Nodes> Lowered    = Detail::LoweredOf<D, T>;
        constexpr static Backend::Kernel::Plan<M::Nodes> Plan       = Detail::PlanOf<M>(Lowered);
        constexpr static Lowering::Program    <M::Nodes> Joined     = Lowering::Combine(Lowered);
        constexpr static Backend::Kernel::Plan<M::Nodes> JoinedPlan = Detail::PlanOf<M>(Joined);

        constexpr static s00 Slots        = Lowered.SlotCount;
        constexpr static s00 Stages       = Lowered.StageCount;
        constexpr static s00 BindingCount = M::Graph.Bindings.size();
        constexpr static s00 Lanes        = Detail::LanesOf(M::Graph, M::Facts);

        constexpr static Array<Detail::Leaves, Slots> Leaf = Detail::LeavesOf<M, Slots>(Lowered);

        constexpr static bool Bounded = std::ranges::none_of(Leaf, &Detail::Leaves::Overflow);

        constexpr static u32 Derived = Detail::DerivedOf(typename M::Bindings {});

        constexpr static Array<u16, Slots + 1> First = Detail::FirstOf<Slots>(Leaf);

        constexpr static s00 Tables = First[Slots];

        constexpr static Array<u16, Tables, 2> Owners = Detail::OwnersOf<Tables, Slots>(Leaf, First);

        constexpr static s00 ParameterCount = Detail::ParameterCountOf(Plan);

        constexpr static Array<u16, ParameterCount> Parameters = Detail::ParametersOf<ParameterCount>(Plan);

        constexpr static Message Text = Lowering::Describe(Lowered);

        static_assert(Bounded, "a slot sums more than IR::MaxFeatureSet sparse terms or biases");

        static_assert(
            Lowering::SlotsExact(M::Graph, M::Facts, Lowered, Derived) &&
            Lowering::SlotsExact(M::Graph, M::Facts, Joined , Derived),
            "a slot that a derived family writes must sum modulo its width or have a proven range that fits it"
        );

        template<s00 Slot>
        using Accumulator = std::conditional_t<Lowered.Slots[Slot].Type == IR::DType::I32, i32, i16>;

        template<s00 Slot, s00 Term>
        constexpr static IR::Node Sparse = M::Graph.Nodes[Leaf[Slot].Sparse[Term]];

        template<s00 Slot, s00 Term>
        constexpr static IR::Node Input = M::Graph.Nodes[Sparse<Slot, Term>.Inputs[0]];

        template<s00 Slot, s00 Term>
        constexpr static u32 Features = Input<Slot, Term>.Size;

        template<s00 Slot, s00 Term>
        using Binding = M::template Binding<Input<Slot, Term>.Binding - 1>;

        template<s00 Slot, s00 Term>
        using Row = IO::Tensors<M>::template Element<Sparse<Slot, Term>.Tensor - 1>;

        template<s00 I>
        using Table = Detail::Aligned<Array<
            Row<Owners[I][0], Owners[I][1]>, Features<Owners[I][0], Owners[I][1]>, Lowered.Slots[Owners[I][0]].Width
        >>;

        template<s00 Slot>
        using Values = Detail::Aligned<Array<Accumulator<Slot>, Lowered.Slots[Slot].Width>>;

        template<s00... I>
        static std::tuple<Table<I>...> TablesOf(const std::index_sequence<I...>);

        template<s00... I>
        static std::tuple<Values<I>...> ValuesOf(const std::index_sequence<I...>);

        template<s00... I>
        static std::tuple<typename Detail::Layer<Lowered, I, ISA>::Type...> LayersOf(const std::index_sequence<I...>);

        using Feed       = Backend::Kernel::Sources<Slots, BindingCount>;
        using SlotValues = decltype(ValuesOf(std::make_index_sequence<Slots> {}));

        decltype(TablesOf(std::make_index_sequence<Tables> {})) Rows   {};
        SlotValues                                              Biases {};
        decltype(LayersOf(std::make_index_sequence<Stages> {})) Layers {};

        Backend::Kernel::Arena<Plan.Parameters> Constants {};

        std::optional<IO::Tensors<M>> Tensors {};

        u64 Stamp = 0;

        template<s00 I>
        void AssignRows(const IO::Tensors<M>& tensors) noexcept
        {
            constexpr u16      Slot    = Owners[I][0];
            constexpr u16      Term    = Owners[I][1];
            constexpr IR::Node Spec    = Sparse<Slot, Term>;
            constexpr u32      Columns = M::Graph.Tensors[Spec.Tensor - 1].Columns;
            constexpr u32      Width   = Lowered.Slots[Slot].Width;
            constexpr u32      Count   = Features<Slot, Term>;

            using W = Row<Slot, Term>;

            const auto rows  = tensors.template View<Spec.Tensor - 1>();
            auto&      table = std::get<I>(Rows).Values;

            for (u32 top  = 0  ; top  < Width; top  += Detail::TransposeTile)
            for (u32 left = 0  ; left < Count; left += Detail::TransposeTile)
            for (u32 o = top; o < std::min(top + Detail::TransposeTile, Width); o++) {
                const auto source = rows.subspan(u64 { Spec.Begin + o } * Columns + Spec.Offset);

                for (u32 feature = left; feature < std::min(left + Detail::TransposeTile, Count); feature++)
                    table[feature][o] = static_cast<W>(source[feature]);
            }
        }

        template<s00 Slot>
        void AssignBias(const IO::Tensors<M>& tensors) noexcept
        {
            using S = Accumulator<Slot>;

            auto& bias = std::get<Slot>(Biases).Values;

            bias.fill(0);

            [&]<s00... J>(const std::index_sequence<J...>) {
                ([&] {
                    constexpr IR::Node Spec = M::Graph.Nodes[Leaf[Slot].Parameters[J]];

                    const auto values = tensors.template View<Spec.Tensor - 1>();

                    for (s00 o = 0; o < bias.size(); o++)
                        bias[o] = WrapAdd<S>(bias[o], static_cast<S>(values[Spec.Begin + o]));
                }(), ...);
            }(std::make_index_sequence<Leaf[Slot].Biases> {});
        }

        template<u16 Node>
        static auto Parameter(const IO::Tensors<M>& tensors) noexcept
        {
            constexpr IR::Node Spec = M::Graph.Nodes[Node];

            return tensors.template View<Spec.Tensor - 1>().subspan(Spec.Begin, Spec.End - Spec.Begin);
        }

        template<s00 I>
        void AssignLayer(const IO::Tensors<M>& tensors) noexcept
        {
            constexpr Lowering::Stage Spec = Lowered.Stages[I];

            if constexpr (Spec.Kind == Lowering::Kind::Dense || Spec.Kind == Lowering::Kind::AccumulatorDot) {
                constexpr IR::Node Matmul  = M::Graph.Nodes[Spec.Node];
                constexpr u32      Columns = M::Graph.Tensors[Matmul.Tensor - 1].Columns;
                constexpr u32      Inputs  = Spec.Kind == Lowering::Kind::Dense ? Spec.Width : 2 * Spec.Width;
                constexpr u32      Count   = Matmul.End - Matmul.Begin;

                using E = IO::Tensors<M>::template Element<Matmul.Tensor - 1>;

                const std::span<const E> weights = tensors.template View<Matmul.Tensor - 1>();

                std::vector<E> logical(u64 { Count } * Inputs);

                for (s00 row = 0; row < Count; row++)
                    std::copy_n(
                        weights.subspan(u64 { Matmul.Begin + row } * Columns + Matmul.Offset).begin(),
                        Inputs,
                        logical.begin() + u64 { row } * Inputs
                    );

                const std::span<const E> rows(logical);

                auto& layer = std::get<I>(Layers);

                if constexpr (Spec.Kind == Lowering::Kind::AccumulatorDot)
                    Backend::Kernel::AccumulatorDot<Lowered, I, ISA>::Assign(rows, layer.Values.data());
                else if constexpr (Spec.Bias == 0)
                    Backend::Kernel::Dense<Lowered, I, ISA>::Assign(layer, rows, rows.first(0));
                else Backend::Kernel::Dense<Lowered, I, ISA>::Assign(layer, rows, Parameter<Spec.Bias>(tensors));
            }
        }

        template<u16 Node>
        void AssignParameter(const IO::Tensors<M>& tensors) noexcept
        {
            constexpr Backend::Kernel::Place Spot = Plan.Places[Node];

            using E = IR::ElementOf<Spot.Type>;

            const auto values = Parameter<Node>(tensors);

            for (s00 k = 0; k < values.size(); k++)
                Constants.template Data<Spot.Type>()[Spot.Offset + k] = static_cast<E>(values[k]);
        }

        void Assign(const IO::Tensors<M>& tensors) noexcept
        {
            [&]<s00... I>(const std::index_sequence<I...>) {
                (AssignRows<I>(tensors), ...);
            }(std::make_index_sequence<Tables> {});

            [&]<s00... I>(const std::index_sequence<I...>) {
                (AssignBias<I>(tensors), ...);
            }(std::make_index_sequence<Slots> {});

            [&]<s00... I>(const std::index_sequence<I...>) {
                (AssignLayer<I>(tensors), ...);
            }(std::make_index_sequence<Stages> {});

            [&]<s00... I>(const std::index_sequence<I...>) {
                (AssignParameter<Parameters[I]>(tensors), ...);
            }(std::make_index_sequence<ParameterCount> {});
        }

        template<s00 Slot>
        [[clang::always_inline]]
        constexpr static u08 Side(const u08 stm) noexcept
        {
            if (Lowered.Slots[Slot].Perspective == IR::Dependence::Ntm) return static_cast<u08>(stm ^ 1);

            return stm;
        }

        template<s00 Slot, s00 Term, typename Board>
        void Gather(
            const u08                                                  side  ,
            const Board&                                               board ,
                  Array<Accumulator<Slot>, Lowered.Slots[Slot].Width>& values
        ) const noexcept
        {
            constexpr u32 Width = Lowered.Slots[Slot].Width;

            using F = Binding<Slot, Term>;
            using W = Row    <Slot, Term>;
            using S = Accumulator<Slot>;

            Array<const W*, F::MaxActive> rows;

            u32 count = 0;

            F::Active(side, board, [&](const u32 feature) {
                assert(count < F::MaxActive);

                if (count < F::MaxActive) rows[count++] = FeatureRow<Slot, Term>(feature);
            });

            const std::span<const W* const> active(std::span(rows).first(count));

            if (Term == 0) Backend::Kernel::Refresh<ISA, Width>(FeatureBias<Slot>(), active, values.data());
            else           Backend::Kernel::Update <ISA, Width, S, W>(values.data(), {}, active, values.data());
        }

        template<s00 Slot, typename Board>
        void Refresh(
            const u08                                                  side  ,
            const Board&                                               board ,
                  Array<Accumulator<Slot>, Lowered.Slots[Slot].Width>& values
        ) const noexcept
        {
            [&]<s00... J>(const std::index_sequence<J...>) {
                (Gather<Slot, J>(side, board, values), ...);
            }(std::make_index_sequence<Leaf[Slot].Terms> {});
        }

        template<typename V>
        [[clang::always_inline]]
        static const V* Pointer(const Feed& sources, const u16 slot) noexcept
        {
            if constexpr (std::is_same_v<V, i32>) return sources.Wide[slot];
            else return sources.Narrow[slot];
        }

        template<s00 Slot>
        [[clang::always_inline]]
        static void Bind(Feed& sources, const Accumulator<Slot>* values) noexcept
        {
            if constexpr (std::is_same_v<Accumulator<Slot>, i32>) sources.Wide  [Slot] = values;
            else                                                  sources.Narrow[Slot] = values;
        }

        template<s00 I>
        [[clang::always_inline]]
        static u32 Bucket(const Feed& sources) noexcept
        {
            constexpr u16 Selector = M::Facts[Lowered.Stages[I].Node].Selector;

            if (Selector == 0 || Lowered.Stages[I].Buckets == 1) return 0;

            return sources.Buckets[Selector - 1];
        }

        template<const auto& L, const auto& P, s00 I, typename A>
        [[clang::always_inline]]
        void Step(A& values, const Feed& sources) const noexcept
        requires (P.Stages[I].Kind == Lowering::Kind::AccumulatorTransform)
        {
            constexpr Lowering::Stage        Spec  = L.Stages[I];
            constexpr Backend::Kernel::Place Out   = P.Places[Spec.Node];
            constexpr Detail::Roles          Roles = Detail::RolesOf(L, Spec.Slots);

            constexpr IR::DType Type = L.Slots[Roles.Stm[0]].Type;

            using K = Backend::Kernel::AccumulatorTransform<L, I, ISA>;
            using S = IR::ElementOf<Type>;

            static_assert(Type == L.Slots[Roles.Ntm[0]].Type, "both roles of a transform share a dtype");
            static_assert(
                std::is_same_v<typename K::Output, IR::ElementOf<Out.Type>>,
                "a transform writes its output in the dtype of its buffer"
            );

            Array<const S*, Roles.StmCount> stm;
            Array<const S*, Roles.NtmCount> ntm;

            for (u16 i = 0; i < Roles.StmCount; i++) stm[i] = Pointer<S>(sources, Roles.Stm[i]);
            for (u16 i = 0; i < Roles.NtmCount; i++) ntm[i] = Pointer<S>(sources, Roles.Ntm[i]);

            K::template Run<S>(
                std::span(stm),
                std::span(ntm),
                values.template Data<Out.Type>() + Out.Offset
            );
        }

        template<const auto& L, const auto& P, s00 I, typename A>
        [[clang::always_inline]]
        void Step(A& values, const Feed& sources) const noexcept
        requires (P.Stages[I].Kind == Lowering::Kind::Dense)
        {
            constexpr Lowering::Stage        Spec = L.Stages[I];
            constexpr u16                    Exit = P.Exits[I];
            constexpr Backend::Kernel::Place From = P.Places[M::Graph.Nodes[Spec.Node].Inputs[0]];
            constexpr Backend::Kernel::Place To   = P.Places[Exit];

            using K = Backend::Kernel::Dense<Lowered, I, ISA>;

            static_assert(
                std::is_same_v<typename K::Input , IR::ElementOf<From.Type>> &&
                std::is_same_v<typename K::Output, IR::ElementOf<To  .Type>>,
                "a Dense stage reads and writes buffers of its own dtypes"
            );

            const typename K::Input* input =
                From.Source == Backend::Kernel::Source::Parameter ? Constants.template Data<From.Type>() + From.Offset
                                                                  : values   .template Data<From.Type>() + From.Offset;

            typename K::Output* output = values.template Data<To.Type>() + To.Offset;

            Backend::Kernel::Elementwise<P, I, ISA>::RunCopies(values, Constants, sources);

            if constexpr (Backend::Kernel::Held<ISA>(P, I)) {
                const typename K::Held held { .Blocks = values.Held.data() + From.Offset / ISA::Bytes };

                if (M::Facts[Exit].Size == Spec.Rows) {
                    K::Run(std::get<I>(Layers), held, output, Bucket<I>(sources));

                    return;
                }

                for (u32 bucket = 0; bucket < Spec.Buckets; bucket++)
                    K::Run(std::get<I>(Layers), held, output + bucket * Spec.Rows, bucket);

                return;
            }

            if (M::Facts[Exit].Size == Spec.Rows) {
                K::Run(std::get<I>(Layers), input, output, Bucket<I>(sources));

                return;
            }

            for (u32 bucket = 0; bucket < Spec.Buckets; bucket++)
                K::Run(std::get<I>(Layers), input, output + bucket * Spec.Rows, bucket);
        }

        template<const auto& L, const auto& P, s00 I, typename A>
        [[clang::always_inline]]
        void Step(A& values, const Feed& sources) const noexcept
        requires (P.Stages[I].Kind == Lowering::Kind::Pointwise)
        { Backend::Kernel::Pointwise<P, I, ISA>::Run(values, Constants, sources); }

        template<Detail::Roles Roles, bool Own, typename V, u32 Width>
        [[clang::always_inline]]
        static const V* Summed(const Feed& sources, Array<V, Width>& scratch) noexcept
        {
            constexpr u16 Count = Own ? Roles.StmCount : Roles.NtmCount;

            constexpr Array<u16, 32> List = Own ? Roles.Stm : Roles.Ntm;

            if (Count == 1) return Pointer<V>(sources, List[0]);

            Array<const V*, Count - 1> rest;

            for (u16 i = 1; i < Count; i++) rest[i - 1] = Pointer<V>(sources, List[i]);

            Backend::Kernel::Update<ISA, Width, V, V>(
                Pointer<V>(sources, List[0]),
                {},
                std::span(rest),
                scratch.data()
            );

            return scratch.data();
        }

        template<const auto& L, const auto& P, s00 I, typename A>
        [[clang::always_inline]]
        void Step(A& values, const Feed& sources) const noexcept
        requires (P.Stages[I].Kind == Lowering::Kind::AccumulatorDot)
        {
            constexpr Lowering::Stage        Spec  = L.Stages[I];
            constexpr Backend::Kernel::Place Raw   = P.Places[Spec.Node];
            constexpr Detail::Roles          Roles = Detail::RolesOf(L, Spec.Slots);

            using K = Backend::Kernel::AccumulatorDot<L, I, ISA>;
            using S = K::Slot;

            alignas(Alignment) Array<S, 2, Spec.Width> scratch;

            const S* stm = Summed<Roles, true , S, Spec.Width>(sources, scratch[0]);
            const S* ntm = Summed<Roles, false, S, Spec.Width>(sources, scratch[1]);

            const u32 bucket = Bucket<I>(sources);
            const i64 sum    = K::Run(
                Detail::Read<ISA, S> { .Values = stm },
                Detail::Read<ISA, S> { .Values = ntm },
                std::get<I>(Layers).Values.data() + bucket * 2 * Spec.Width
            );

            values.template Data<Raw.Type>()[Raw.Offset + bucket] = static_cast<IR::ElementOf<Raw.Type>>(sum);

            Backend::Kernel::Elementwise<P, I, ISA>::Run(values, Constants, sources);
        }

        template<s00 H, typename V>
        [[clang::always_inline]]
        constexpr static i32 Scale(const V value) noexcept
        {
            constexpr IR::Head Spec = M::Graph.Heads[H];

            if constexpr (std::is_same_v<V, f32>) {
                constexpr f32 Factor = static_cast<f32>(ToDouble(Spec.Scale));

                return static_cast<i32>(std::clamp(value * Factor, -2147483648.0F, 2147483520.0F));
            } else {
                constexpr Rational Reduced = Detail::HeadFactor(Spec.Scale, M::Facts[Spec.Node].Scale);

                return static_cast<i32>(Detail::i128 { value } * Reduced.Numerator / Reduced.Denominator);
            }
        }

        template<const auto& P, s00 H, typename A>
        [[clang::always_inline]]
        void Head(const A& values, Array<i32, Lanes>& lanes, s00& lane) const noexcept
        {
            constexpr IR::Head               Spec = M::Graph.Heads[H];
            constexpr Backend::Kernel::Place Spot = P.Places[Spec.Node];

            const auto* data = Spot.Source == Backend::Kernel::Source::Parameter ? Constants.template Data<Spot.Type>()
                                                                                 : values   .template Data<Spot.Type>();

            using V = IR::ElementOf<Spot.Type>;

            for (u32 k = 0; k < M::Facts[Spec.Node].Size; k++) {
                const V value = data[Spot.Offset + k];

                if constexpr (std::is_same_v<V, f32>) lanes[lane++] = Scale<H>(value      );
                else                                  lanes[lane++] = Scale<H>(i64 { value });
            }
        }

        template<const auto& L, const auto& P>
        [[clang::always_inline]]
        Array<i32, Lanes> Run(const Feed& sources) const noexcept
        {
            static_assert(P.Supported                    , "the program's buffers cannot be placed for this runtime");
            static_assert(P.Parameters == Plan.Parameters, "every grouping reads the same constants");

            using Arena = Backend::Kernel::Arena<P.Values>;
            using Held  = Array<typename ISA::Vector, P.Values[static_cast<s00>(IR::DType::U08)] / ISA::Bytes + 1>;

            Arena arena;
            Held  held ;

            Backend::Kernel::Scratch<Arena, Held> scratch { .Values = arena, .Held = held };

            auto& values = std::get<Backend::Kernel::Holds<ISA>(P) ? 1 : 0>(std::tie(arena, scratch));

            [&]<s00... I>(const std::index_sequence<I...>) {
                (Step<L, P, I>(values, sources), ...);
            }(std::make_index_sequence<Stages> {});

            Array<i32, Lanes> lanes;

            s00 lane = 0;

            [&]<s00... H>(const std::index_sequence<H...>) {
                (Head<P, H>(values, lanes, lane), ...);
            }(std::make_index_sequence<M::Graph.HeadCount> {});

            return lanes;
        }

        public:
        using Model    = M;
        using Bindings = M::Bindings;
        using Sources  = Feed;

        constexpr static Lowering::Program<Model::Nodes> Program = Lowered;

        constexpr static bool Fusable          = Program.Fusable;
        constexpr static bool NeedsBoard       = Detail::AnyBoardAtPush(Bindings {});
        constexpr static bool NeedsBoardAtEval = Detail::AnyBoardAtEval(Bindings {});
        constexpr static s00  Outputs          = Lanes;

        template<s00 Slot>
        using SlotType = Accumulator<Slot>;

        template<s00 Slot, s00 Term>
        using FeatureSet = Binding<Slot, Term>;

        template<s00 Slot, s00 Term>
        using RowType = Row<Slot, Term>;

        template<s00 Slot>
        constexpr static s00 Terms = Leaf[Slot].Terms;

        template<s00 Slot>
        class SlotRows
        {

            const Network* Of;

            public:
            explicit SlotRows(const Network& network) noexcept : Of(&network) {}

            SlotRows(const Network&&) = delete;

            [[nodiscard]]
            [[clang::always_inline]]
            const RowType<Slot, 0>* FeatureRow(const u08, const u32 index) const noexcept
            { return Of->template FeatureRow<Slot, 0>(index); }

            [[nodiscard]]
            [[clang::always_inline]]
            const SlotType<Slot>* FeatureBias(const u08) const noexcept { return Of->template FeatureBias<Slot>(); }

            [[nodiscard]]
            u64 Generation() const noexcept { return Of->Generation(); }

        };

        [[nodiscard]]
        LoadResult Load(const std::span<const std::byte> bytes) noexcept
        {
            IO::Tensors<M> tensors {};

            if (const LoadResult result = IO::Load(bytes, tensors); !result) return result;

            Assign(tensors);

            Tensors = std::move(tensors);
            Stamp   = Detail::NextGeneration.fetch_add(1, std::memory_order_relaxed);

            return {};
        }

        [[nodiscard]]
        std::vector<std::byte> Save() const
        {
            if (Tensors) return IO::Save(*Tensors);

            return IO::Save(IO::Tensors<M> {});
        }

        [[nodiscard]]
        u64 Generation() const noexcept { return Stamp; }

        [[nodiscard]]
        constexpr static std::string_view Describe() noexcept { return { Text.data(), Text.size() }; }

        template<typename Board>
        [[nodiscard]]
        i32 Evaluate(const Board& board) const noexcept { return EvaluateAll(board)[0]; }

        template<typename Board>
        [[nodiscard]]
        Array<i32, Outputs> EvaluateAll(const Board& board) const noexcept
        {
            const u08 stm = board.SideToMove();

            SlotValues accumulators;
            Sources    sources {};

            [&]<s00... S>(const std::index_sequence<S...>) {
                ([&] {
                    auto& values = std::get<S>(accumulators).Values;

                    Refresh<S>(Side<S>(stm), board, values);
                    Bind   <S>(sources, values.data());
                }(), ...);
            }(std::make_index_sequence<Slots> {});

            [&]<s00... B>(const std::index_sequence<B...>) {
                ([&] {
                    using Choice = M::template Binding<B>;

                    if constexpr (Selector<Choice>) sources.Buckets[B] = Choice::Of(board);
                }(), ...);
            }(std::make_index_sequence<BindingCount> {});

            return Forward(sources);
        }

        template<s00 Slot, s00 Term>
        [[nodiscard]]
        [[clang::always_inline]]
        const RowType<Slot, Term>* FeatureRow(const u32 index) const noexcept
        {
            assert(index < (Features<Slot, Term>));

            return std::get<First[Leaf[Slot].Lead] + Term>(Rows).Values[index].data();
        }

        template<s00 Slot>
        [[nodiscard]]
        [[clang::always_inline]]
        const SlotType<Slot>* FeatureBias() const noexcept { return std::get<Slot>(Biases).Values.data(); }

        template<Accumulators Grouped = Accumulators::Split>
        [[nodiscard]]
        Array<i32, Outputs> Forward(const Sources& sources) const noexcept
        {
            if constexpr (Grouped == Accumulators::Combined && Joined != Lowered)
                 return Run<Joined , JoinedPlan>(sources);
            else return Run<Lowered,       Plan>(sources);
        }

    };

}

#endif //MANTARAY_RUNTIME_NETWORK_H
