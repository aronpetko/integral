//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_IR_CANONICAL_H
#define MANTARAY_IR_CANONICAL_H

#include <bit>
#include <limits>
#include <span>
#include <utility>
#include <vector>

#include "GraphIR.h"
#include "../Common.h"

namespace MantaRay::IR
{

    namespace Detail
    {

        using MantaRay::Detail::Buffer;

        constexpr bool Same(const Node& a, const Node& b)
        {
            return a.Operation == b.Operation && a.InputCount == b.InputCount && a.Bounds == b.Bounds &&
                   a.Function == b.Function && a.Perspective == b.Perspective && a.Type == b.Type &&
                   a.Reduction == b.Reduction && a.Tensor == b.Tensor && a.Binding == b.Binding && a.Shift == b.Shift &&
                   a.Inputs[0] == b.Inputs[0] && a.Inputs[1] == b.Inputs[1] && a.Size == b.Size && a.Begin == b.Begin &&
                   a.End == b.End && a.Offset == b.Offset && a.Low == b.Low && a.High == b.High;
        }

        constexpr u64 Hash(const Node& node)
        {
            constexpr u64 Prime = u64 { 1099511628211 };

            const u64 kind   = static_cast<u64>(node.Operation) | static_cast<u64>(node.Function) << 8 |
                               static_cast<u64>(node.Bounds) << 16 | static_cast<u64>(node.Perspective) << 24 |
                               static_cast<u64>(node.Type) << 32 | static_cast<u64>(node.Reduction) << 40 |
                               static_cast<u64>(node.InputCount) << 48;
            const u64 source = static_cast<u64>(node.Tensor) | static_cast<u64>(node.Binding) << 16 |
                               static_cast<u64>(node.Shift) << 32;
            const u64 edges  = static_cast<u64>(node.Inputs[0]) | static_cast<u64>(node.Inputs[1]) << 16 |
                               static_cast<u64>(node.Size) << 32;
            const u64 range  = static_cast<u64>(node.Begin) | static_cast<u64>(node.End) << 32;
            const u64 low    = static_cast<u64>(node.Low .Numerator) ^ static_cast<u64>(node.Low .Denominator) << 7;
            const u64 high   = static_cast<u64>(node.High.Numerator) ^ static_cast<u64>(node.High.Denominator) << 7;
            const u64 bounds = low ^ high << 1 ^ node.Offset;

            u64 hash = u64 { 1469598103934665603 };

            hash = (hash ^ kind  ) * Prime;
            hash = (hash ^ source) * Prime;
            hash = (hash ^ edges ) * Prime;
            hash = (hash ^ range ) * Prime;

            return (hash ^ bounds) * Prime;
        }

        constexpr bool PowerOfTwo(const Rational value)
        {
            return Integral(value) && value.Numerator > 0 && std::has_single_bit(static_cast<u64>(value.Numerator));
        }

        constexpr inline s00 Expansion = 4;

        constexpr inline u16 Unplaced = 0xFFFF;

        struct Rewritten
        {

            Buffer<Node> Nodes {};
            Buffer<u16>  Map   {};
            Buffer<bool> Live  {};

            s00 Count = 0;

        };

        class Numbering
        {

            Buffer<u16> Table {};

            const Buffer<Node>& Nodes;

            public:
            constexpr explicit Numbering(
                const Buffer<Node>& nodes   ,
                const s00           capacity
            ) : Table(capacity + capacity / 4 + 1), Nodes(nodes) {}

            constexpr u16 Find(const Node& node, const u64 hash) const
            {
                s00 slot = hash % Table.size();

                while (Table[slot] != 0) {
                    if (Same(Nodes[Table[slot] - 1], node)) return static_cast<u16>(Table[slot] - 1);

                    slot = (slot + 1) % Table.size();
                }

                return Unplaced;
            }

            constexpr void Insert(const u64 hash, const u16 index)
            {
                s00 slot = hash % Table.size();

                while (Table[slot] != 0) slot = (slot + 1) % Table.size();

                Table[slot] = static_cast<u16>(index + 1);
            }

        };

        class Rewriter
        {

            Buffer<Node>& Out;
            Numbering&    Values;

            std::span<const Tensor> Tensors;

            public:
            constexpr explicit Rewriter(
                      Buffer<Node>&           out    ,
                      Numbering&              values ,
                const std::span<const Tensor> tensors
            ) : Out(out), Values(values), Tensors(tensors) {}

            constexpr u16 Emit(const Node& node)
            {
                const u64 hash  = Hash(node);
                const u16 found = Values.Find(node, hash);

                if (found != Unplaced) return found;

                const u16 index = static_cast<u16>(Out.size());

                Out.Push(node);
                Values.Insert(hash, index);

                return index;
            }

            constexpr u16 Constant(const Node& site, const Rational value)
            {
                Node constant {};

                constant.Operation = Op::Constant;
                constant.Size      = 1;
                constant.Low       = value;
                constant.File      = site.File;
                constant.Line      = site.Line;
                constant.Column    = site.Column;

                return Emit(constant);
            }

            constexpr bool NonNegative(const u16 index) const
            {
                const Node& node = Out[index];

                switch (node.Operation) {
                    case Op::Clamp     : return (node.Bounds == Bound::Low || node.Bounds == Bound::Both) &&
                                                !(node.Low < Ratio(0));
                    case Op::Mul       : return node.InputCount == 2 && node.Inputs[0] == node.Inputs[1];
                    case Op::ShiftRight:
                    case Op::Divide    :
                    case Op::Slice     :
                    case Op::Select    : return NonNegative(node.Inputs[0]);
                    case Op::Concat    : return NonNegative(node.Inputs[0]) && NonNegative(node.Inputs[1]);
                    default            : return false;
                }
            }

            constexpr bool Floating(u16 index) const
            {
                for (;; index = Out[index].Inputs[0]) {
                    const Node& node = Out[index];

                    switch (node.Operation) {
                        case Op::Dequantize  : return true;
                        case Op::Input       :
                        case Op::Constant    : return false;
                        case Op::Parameter   :
                        case Op::Matmul      :
                        case Op::SparseMatmul: return node.Tensor != 0 && node.Tensor <= Tensors.size() &&
                                                      IsFloat(Tensors[node.Tensor - 1].Type);
                        default              : break;
                    }
                }
            }

            constexpr u16 Rewrite(Node node)
            {
                if (node.Operation == Op::Sub) {
                    Node negate = node;

                    negate.Operation = Op::Mul;
                    negate.Inputs    = { node.Inputs[1], Constant(node, Ratio(-1)) };

                    node.Operation = Op::Add;
                    node.Inputs[1] = Rewrite(negate);

                    return Rewrite(node);
                }

                const bool scalar = node.InputCount == 2 && Out[node.Inputs[1]].Operation == Op::Constant;

                if ((node.Operation == Op::Min || node.Operation == Op::Max) && scalar) {
                    const Rational bound = Out[node.Inputs[1]].Low;

                    node.InputCount = 1;
                    node.Inputs[1]  = 0;
                    node.Bounds     = node.Operation == Op::Min ? Bound::High : Bound::Low;
                    node.Low        = node.Operation == Op::Max ? bound : Rational {};
                    node.High       = node.Operation == Op::Min ? bound : Rational {};
                    node.Operation  = Op::Clamp;

                    return Rewrite(node);
                }

                if (node.InputCount == 0) return Emit(node);

                const Node& input = Out[node.Inputs[0]];

                if (node.Operation == Op::Clamp && input.Operation == Op::Clamp) {
                    const bool outerLow  = node .Bounds == Bound::Low  || node .Bounds == Bound::Both;
                    const bool outerHigh = node .Bounds == Bound::High || node .Bounds == Bound::Both;
                    const bool innerLow  = input.Bounds == Bound::Low  || input.Bounds == Bound::Both;
                    const bool innerHigh = input.Bounds == Bound::High || input.Bounds == Bound::Both;

                    Rational low  = input.Low ;
                    Rational high = input.High;

                    if (outerLow && innerLow) low = node.Low < input.Low ? input.Low : node.Low;
                    else if (outerLow) low = node.Low;

                    if (outerHigh && innerHigh) high = input.High < node.High ? input.High : node.High;
                    else if (outerHigh) high = node.High;

                    const bool lower = outerLow  || innerLow ;
                    const bool upper = outerHigh || innerHigh;

                    if (!lower || !upper || low < high) {
                        node.Inputs[0] = input.Inputs[0];
                        node.Bounds    = lower && upper ? Bound::Both : lower ? Bound::Low : Bound::High;
                        node.Low       = lower ? low  : Rational {};
                        node.High      = upper ? high : Rational {};

                        return Rewrite(node);
                    }
                }

                if (node.Operation == Op::Slice && node.InputCount == 1 && input.Operation == Op::Clamp) {
                    Node slice = node;

                    slice.Inputs[0] = input.Inputs[0];

                    Node clamp = input;

                    clamp.Size      = node.Size;
                    clamp.Inputs[0] = Rewrite(slice);
                    clamp.File      = node.File;
                    clamp.Line      = node.Line;
                    clamp.Column    = node.Column;

                    return Rewrite(clamp);
                }

                if (node.Operation == Op::ShiftRight && input.Operation == Op::ShiftRight &&
                    node.Shift + input.Shift <= std::numeric_limits<i64>::digits) {
                    node.Shift     = static_cast<u16>(node.Shift + input.Shift);
                    node.Inputs[0] = input.Inputs[0];

                    return Rewrite(node);
                }

                const bool requantized = node.Operation == Op::Divide && PowerOfTwo(node.Low);

                if (requantized && NonNegative(node.Inputs[0]) && !Floating(node.Inputs[0])) {
                    node.Operation = Op::ShiftRight;
                    node.Shift     = static_cast<u16>(std::countr_zero(static_cast<u64>(node.Low.Numerator)));
                    node.Low       = {};

                    return Rewrite(node);
                }

                if (node.Operation == Op::Slice && input.Operation == Op::Concat) {
                    const u32  split   = Out[input.Inputs[0]].Size;
                    const bool high    = node.Begin >= split;
                    const u16  operand = input.Inputs[high];
                    const u32  offset  = high ? split : 0;

                    if (!high && node.End > split) return Emit(node);

                    if (node.Begin == offset && node.End == offset + Out[operand].Size) return operand;

                    node.Inputs[0] = operand;
                    node.Begin    -= offset;
                    node.End      -= offset;

                    return Rewrite(node);
                }

                if (node.Operation == Op::Select && input.Operation == Op::Add &&
                    Out[input.Inputs[1]].Operation == Op::Parameter) {
                    Node sum  = input;
                    Node bias = node;

                    bias.Inputs[0] = input.Inputs[1];
                    node.Inputs[0] = input.Inputs[0];

                    sum.Size   = node.Size;
                    sum.Inputs = { Rewrite(node), Rewrite(bias) };

                    return Rewrite(sum);
                }

                return Emit(node);
            }

        };

        constexpr Rewritten Rewrite(
            const std::span<const Node>   nodes  ,
            const std::span<const Head>   heads  ,
            const std::span<const Tensor> tensors
        )
        {
            Rewritten result {};

            result.Nodes = Buffer<Node>::Reserved(nodes.size() * Expansion);
            result.Map   = Buffer<u16> { nodes.size() };

            Numbering numbering { result.Nodes, nodes.size() * Expansion };
            Rewriter  rewriter  { result.Nodes, numbering, tensors };

            for (s00 i = 0; i < nodes.size(); i++) {
                Node node = nodes[i];

                for (s00 k = 0; k < node.InputCount; k++) node.Inputs[k] = result.Map[node.Inputs[k]];

                result.Map[i] = rewriter.Rewrite(node);
            }

            result.Live = Buffer<bool> { result.Nodes.size() };

            for (const Head& head : heads) result.Live[result.Map[head.Node]] = true;

            for (s00 i = result.Nodes.size(); i-- > 0;) {
                if (!result.Live[i]) continue;

                for (s00 k = 0; k < result.Nodes[i].InputCount; k++) result.Live[result.Nodes[i].Inputs[k]] = true;
            }

            for (const bool live : result.Live) result.Count += live;

            return result;
        }

        class Emission
        {

            const Buffer<Node>& Nodes;

            Buffer<u16>  Path ;
            Buffer<u08>  Next ;
            Buffer<u16>  Index;
            Buffer<Node> Out  ;

            public:
            constexpr explicit Emission(
                const Buffer<Node>& nodes,
                const s00           count
            ) : Nodes(nodes),
                Path (nodes.size()),
                Next (nodes.size()),
                Index(nodes.size(), Unplaced),
                Out  (Buffer<Node>::Reserved(count)) {}

            constexpr void Place(const u16 root)
            {
                if (Index[root] != Unplaced) return;

                s00 depth = 0;

                Path[depth++] = root;

                while (depth > 0) {
                    const u16   current = Path[depth - 1];
                    const Node& node    = Nodes[current];

                    if (Next[current] < node.InputCount) {
                        const u16 input = node.Inputs[Next[current]++];

                        if (Index[input] == Unplaced) Path[depth++] = input;

                        continue;
                    }

                    Node placed = node;

                    for (s00 k = 0; k < placed.InputCount; k++) placed.Inputs[k] = Index[placed.Inputs[k]];

                    Index[current] = static_cast<u16>(Out.size());

                    Out.Push(placed);

                    depth--;
                }
            }

            constexpr u16 Placed(const u16 node) const { return Index[node]; }

            constexpr Buffer<Node> Release() { return std::move(Out); }

        };

    }

    struct Canonical
    {

        MantaRay::Detail::Buffer<Node> Nodes {};
        std::vector<Head>              Heads {};

    };

    constexpr Canonical Canonicalize(
        const std::span<const Node>   nodes      ,
        const std::span<const Head>   heads      ,
        const std::span<const Tensor> tensors = {}
    )
    {
        const Detail::Rewritten rewritten = Detail::Rewrite(nodes, heads, tensors);

        Detail::Emission emission { rewritten.Nodes, rewritten.Count };

        for (const Head& head : heads) emission.Place(rewritten.Map[head.Node]);

        Canonical out {};

        out.Nodes = emission.Release();
        out.Heads.assign(heads.begin(), heads.end());

        for (Head& head : out.Heads) head.Node = emission.Placed(rewritten.Map[head.Node]);

        return out;
    }

    template<typename G>
    consteval Sizes CanonicalSizes(const G& graph)
    {
        Sizes sizes = G::Size;

        if (graph.Fault.Code != FaultCode::None) return sizes;

        sizes.Nodes = static_cast<u32>(Detail::Rewrite(graph.Nodes, graph.Heads, graph.Tensors).Count);

        return sizes;
    }

    template<Sizes S, typename G>
    consteval Graph<S> Canonicalize(const G& graph)
    {
        Graph<S> out {};

        out.Version  = graph.Version;
        out.File     = graph.File;
        out.Fault    = graph.Fault;
        out.Bindings = graph.Bindings;
        out.Items    = graph.Items;
        out.Tensors  = graph.Tensors;
        out.Files    = graph.Files;
        out.Heads    = graph.Heads;

        if (graph.Fault.Code != FaultCode::None) {
            for (s00 i = 0; i < S.Nodes; i++) out.Nodes[i] = graph.Nodes[i];

            return out;
        }

        const Canonical canonical = Canonicalize(graph.Nodes, graph.Heads, graph.Tensors);

        for (s00 i = 0; i < S.Nodes; i++) out.Nodes[i] = canonical.Nodes[i];
        for (s00 i = 0; i < S.Heads; i++) out.Heads[i] = canonical.Heads[i];

        return out;
    }

}

#endif //MANTARAY_IR_CANONICAL_H
