//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_IR_ANALYSIS_H
#define MANTARAY_IR_ANALYSIS_H

#include <algorithm>
#include <bit>
#include <limits>
#include <string_view>

#include "GraphIR.h"
#include "../Common.h"

namespace MantaRay::IR
{

    enum class Domain : u08 { None, Sparse, Integer, Float, Constant };

    enum class Provenance : u08 { Proven, LoadVerified, Assumed, Unbounded };

    enum class Dependence : u08 { None, Shared, Stm, Ntm, Both };

    constexpr inline f64 Unbounded = 1e300;

    struct Fact
    {

        Domain     Domain      = Domain::None;
        Provenance Provenance  = Provenance::Proven;
        Dependence Perspective = Dependence::None;
        DType      Storage     = DType::None;

        bool Linear = false;

        u16 Consumers = 0;
        u16 Selector  = 0;

        u32 Size        = 0;
        u32 FeatureSets = 0;

        Rational Scale {};
        Interval Range {};

        f64 Low  = 0;
        f64 High = 0;

        constexpr bool operator ==(const Fact&) const = default;

    };

    struct Diagnostic
    {

        bool    Ok   = true;
        Message Text {};

    };

    template<s00 N>
    struct Analysis
    {

        Diagnostic Diagnostic {};

        Array<Fact, N> Facts {};

        u16 Checks = 0;

        Array<u16, N> Verified {};

    };

    namespace Detail
    {

        constexpr Diagnostic Fail(const Message& text) { return { .Ok = false, .Text = text }; }

        constexpr Dependence Combine(const Dependence left, const Dependence right)
        {
            if (left  == Dependence::None || left == right) return right;
            if (right == Dependence::None                 ) return left ;

            if (left  == Dependence::Shared) return right;
            if (right == Dependence::Shared) return left ;

            return Dependence::Both;
        }

        constexpr Provenance Weakest(const Provenance left, const Provenance right) { return std::max(left, right); }

        constexpr Interval Scaled(const Rational real, const Rational scale)
        {
            const Rational value = real * scale;

            return { .Min = Floor(value), .Max = Ceil(value) };
        }

        constexpr Interval Scaled(const Rational real, const Rational scale, bool& exact)
        {
            exact = Integral(real * scale);

            return Scaled(real, scale);
        }

        constexpr f64 Lower(const f64 left, const f64 right) { return left < right ? left : right; }

        constexpr f64 Upper(const f64 left, const f64 right) { return left > right ? left : right; }

        struct Range
        {

            f64 Low  = 0;
            f64 High = 0;

        };

        constexpr Range Product(const f64 a, const f64 b, const f64 c, const f64 d)
        {
            const f64 x = a * c;
            const f64 y = a * d;
            const f64 z = b * c;
            const f64 w = b * d;

            return { .Low = Lower(Lower(x, y), Lower(z, w)), .High = Upper(Upper(x, y), Upper(z, w)) };
        }

        constexpr f64 Clip(const f64 value) { return std::clamp(value, -Unbounded, Unbounded); }

        constexpr bool UsesTensor(const Op op)
        { return op == Op::SparseMatmul || op == Op::Matmul || op == Op::Parameter; }

        constexpr bool UsesBinding(const Op op) { return op == Op::Input || op == Op::Select; }

        constexpr Diagnostic Explain(const Fault& fault)
        {
            const i64 a = fault.Values[0];
            const i64 b = fault.Values[1];
            const i64 c = fault.Values[2];

            switch (fault.Code) {
                case FaultCode::SizeMismatch:
                    return Fail(Message {} << "operand sizes " << a << " and " << b << " differ");
                case FaultCode::InputSize:
                    return Fail(Message {} << "layer expects input size " << a << " but the value has " << b);
                case FaultCode::SliceOutside:
                    return Fail(Message {} << "slice [" << a << ", " << b << ") is outside a value of size " << c);
                case FaultCode::OddSize:
                    return Fail(Message {} << "Pairwise needs an even size but the value has " << a);
                case FaultCode::BucketSplit:
                    return Fail(Message {} << "size " << a << " is not divisible into " << b << " buckets");
                case FaultCode::BoundOrder:
                    return Fail(Message {} << "the lower clamp bound must be below the upper one");
                case FaultCode::SparseOperand:
                    return Fail(Message {} << "a sparse input must pass through a layer first");
                case FaultCode::IndexCapacity:
                    return Fail(Message {} << "the graph has " << a << " nodes and " << b << " tensors; " <<
                                              "GraphIR indices are u16 (at most " << c << ")");
                case FaultCode::FeatureSetCapacity:
                    return Fail(Message {} << "the graph uses " << a << " feature families; at most " << b <<
                                              " are supported");
                case FaultCode::StepBudget:
                    return Fail(Message {} << "the graph has " << a << " nodes; freezing it needs about " << b <<
                                              " constexpr steps but the limit is " << c << "; compile with " <<
                                              "-fconstexpr-steps=" << b << " -DMANTARAY_CONSTEXPR_STEPS=" << b);
                case FaultCode::FoldShape:
                    return Fail(Message {} << "the factor tensor (" << a << "x" << b << ") must tile the base " <<
                                              "tensor and have its dtype");
                case FaultCode::ReductionDomain:
                    return Fail(Message {} << "a reduction order applies to dense f32 layers; BiasFirstFma also " <<
                                              "needs a bias");
                case FaultCode::TensorNotSaved:
                    return Fail(Message {} << "this tensor is used by the graph but missing from the file spec");
                case FaultCode::TensorSavedTwice:
                    return Fail(Message {} << "this tensor appears twice in the file spec");
                case FaultCode::TensorUnused:
                    return Fail(Message {} << "this tensor is in the file spec but not used by the graph");
                default:
                    return Fail(Message {} << "unknown builder fault");
            }
        }

        template<Sizes S>
        class Analyzer
        {

            const Graph<S>& G;

            public:
            constexpr explicit Analyzer(const Graph<S>& graph) : G(graph) {}

            constexpr Diagnostic Locate(
                const u16              file      ,
                const u16              line      ,
                const u16              column    ,
                const std::string_view label     ,
                const Diagnostic&      diagnostic
            ) const
            {
                if (diagnostic.Ok) return diagnostic;

                const std::string_view text { diagnostic.Text.data(), diagnostic.Text.size() };
                const std::string_view name = FileOf(G, file);

                Message message {};

                if (name.empty()) message << "line ";
                else              message << name << ":";

                return Fail(message << line << ":" << column << " (" << label << "): " << text);
            }

            constexpr Diagnostic Locate(const Node& node, const Diagnostic& diagnostic) const
            { return Locate(node.File, node.Line, node.Column, Name(node.Operation), diagnostic); }

            constexpr Diagnostic Locate(const Tensor& tensor, const Diagnostic& diagnostic) const
            { return Locate(tensor.File, tensor.Line, tensor.Column, "Tensor", diagnostic); }

            constexpr Diagnostic Locate(const Fault& fault) const
            {
                const std::string_view label = fault.Operation != Op::None                  ? Name(fault.Operation) :
                                               fault.Code      >= FaultCode::TensorNotSaved ? "Tensor"              :
                                                                                              "Output"              ;

                return Locate(fault.File, fault.Line, fault.Column, label, Explain(fault));
            }

            constexpr Diagnostic CheckGraph() const
            {
                if (G.Version != Version)
                    return Fail(Message {} << "graph version " << i64 { G.Version } << " does not match IR::Version " <<
                                              i64 { Version });

                if (G.Fault.Code != FaultCode::None) return Locate(G.Fault);

                for (s00 i = 0; i < S.Tensors; i++)
                    if (const Diagnostic diagnostic = CheckFolded(G.Tensors[i], i); !diagnostic.Ok)
                        return Locate(G.Tensors[i], diagnostic);

                for (s00 i = 0; i < S.Nodes; i++)
                    if (const Diagnostic diagnostic = CheckNode(G.Nodes[i], i); !diagnostic.Ok)
                        return Locate(G.Nodes[i], diagnostic);

                for (s00 h = 0; h < S.Heads; h++)
                    if (G.Heads[h].Node >= S.Nodes)
                        return Fail(Message {} << "head " << static_cast<i64>(h) << " refers to node " <<
                                                  i64 { G.Heads[h].Node } << " but the graph has " << i64 { S.Nodes } <<
                                                  " nodes");

                return CheckReachable();
            }

            constexpr static Diagnostic CheckFolded(const Tensor& tensor, const s00 index)
            {
                if (tensor.Role != Role::Folded) return {};

                if (tensor.Base   != 0 && tensor.Base   <= index &&
                    tensor.Factor != 0 && tensor.Factor <= index ) return {};

                return Fail(Message {} << "a folded tensor must refer to earlier base and factor tensors");
            }

            constexpr Diagnostic CheckNode(const Node& node, const s00 index) const
            {
                if (node.InputCount > MaxInputs)
                    return Fail(Message {} << "a node has at most " << static_cast<i64>(MaxInputs) << " inputs but " <<
                                              "this one has " << i64 { node.InputCount });

                for (s00 k = 0; k < node.InputCount; k++)
                    if (node.Inputs[k] >= index)
                        return Fail(Message {} << "input " << static_cast<i64>(k) << " refers to node " <<
                                                  i64 { node.Inputs[k] } << ", which does not precede node " <<
                                                  static_cast<i64>(index));

                if (UsesTensor (node.Operation)) return CheckView   (node);
                if (UsesBinding(node.Operation)) return CheckBinding(node);

                return {};
            }

            constexpr Diagnostic CheckView(const Node& node) const
            {
                if (node.Tensor == 0 || node.Tensor > S.Tensors)
                    return Fail(Message {} << "the node refers to tensor " << i64 { node.Tensor } <<
                                              " but the graph has " << i64 { S.Tensors } << " tensors");

                const Tensor& tensor = G.Tensors[node.Tensor - 1];

                const u64 width = node.InputCount == 0 ? 1 : G.Nodes[node.Inputs[0]].Size;
                const u64 end   = node.Offset + width;

                if (node.Begin <= node.End && node.End <= tensor.Rows && end <= tensor.Columns) return {};

                return Fail(Message {} << "rows [" << i64 { node.Begin } << ", " << i64 { node.End } << ") and " <<
                                          "columns [" << i64 { node.Offset } << ", " << static_cast<i64>(end) <<
                                          ") exceed the " << i64 { tensor.Rows } << "x" << i64 { tensor.Columns } <<
                                          " tensor " << i64 { node.Tensor });
            }

            constexpr Diagnostic CheckBinding(const Node& node) const
            {
                if (node.Binding == 0 || node.Binding > S.Bindings)
                    return Fail(Message {} << "the node refers to binding " << i64 { node.Binding } <<
                                              " but the graph has " << i64 { S.Bindings } << " bindings");

                const Binding& binding = G.Bindings[node.Binding - 1];

                if (node.Operation == Op::Input && binding.Kind != Kind::FeatureSet)
                    return Fail(Message {} << "binding " << i64 { node.Binding } << " is not a feature family");

                if (node.Operation == Op::Input && node.Size != binding.InputSize)
                    return Fail(Message {} << "the input has size " << i64 { node.Size } << " but binding " <<
                                              i64 { node.Binding } << " has " << i64 { binding.InputSize } <<
                                              " features");

                if (node.Operation == Op::Input) return {};

                if (binding.Kind != Kind::Selector)
                    return Fail(Message {} << "binding " << i64 { node.Binding } << " is not a selector");

                const u64 input = node.InputCount == 0 ? 0 : G.Nodes[node.Inputs[0]].Size;

                if (u64 { node.Size } * binding.Count == input) return {};

                return Fail(Message {} << "size " << i64 { node.Size } << " x " << i64 { binding.Count } <<
                                          " buckets does not equal the input size " << static_cast<i64>(input));
            }

            constexpr Diagnostic CheckReachable() const
            {
                Array<bool, S.Nodes> reached {};

                for (s00 h = 0; h < S.Heads; h++) reached[G.Heads[h].Node] = true;

                for (s00 i = S.Nodes; i-- > 0;) {
                    if (!reached[i]) continue;

                    for (s00 k = 0; k < G.Nodes[i].InputCount; k++) reached[G.Nodes[i].Inputs[k]] = true;
                }

                for (s00 i = 0; i < S.Nodes; i++)
                    if (!reached[i])
                        return Locate(G.Nodes[i], Fail(Message {} << "this node is not reachable from any output"));

                return {};
            }

            constexpr Diagnostic Visit(const Node& node, Fact& fact, const Array<Fact, MaxInputs>& inputs) const
            {
                const Fact& a = inputs[0];
                const Fact& b = inputs[1];

                const bool binary = node.InputCount > 1;

                fact.Size        = node.Size;
                fact.Perspective = Combine(a.Perspective, binary ? b.Perspective : Dependence::None);
                fact.FeatureSets = a.FeatureSets | (binary ? b.FeatureSets : 0);
                fact.Provenance  = Weakest(a.Provenance, binary ? b.Provenance : Provenance::Proven);
                fact.Domain      = a.Domain;
                fact.Scale       = a.Scale ;
                fact.Range       = a.Range ;
                fact.Low         = a.Low   ;
                fact.High        = a.High  ;

                switch (node.Operation) {
                    case Op::Input       : return VisitInput      (node, fact      );
                    case Op::Parameter   : return VisitParameter  (node, fact      );
                    case Op::Constant    : return VisitConstant   (node, fact      );
                    case Op::SparseMatmul: return VisitSparse     (node, fact, a   );
                    case Op::Matmul      : return VisitMatmul     (node, fact, a, b);
                    case Op::Add         :
                    case Op::Sub         :
                    case Op::Min         :
                    case Op::Max         : return VisitAdditive   (node, fact, a, b);
                    case Op::Mul         : return VisitMul        (node, fact, a, b);
                    case Op::Pow         : return VisitFloatOnly  (      fact, a   );
                    case Op::Clamp       : return VisitClamp      (node, fact, a   );
                    case Op::Unary       : return VisitUnary      (node, fact, a   );
                    case Op::ShiftRight  :
                    case Op::ShiftLeft   :
                    case Op::Divide      : return VisitRequantize (node, fact, a   );
                    case Op::Dequantize  : return VisitDequantize (node, fact, a, b);
                    case Op::Wrap        :
                    case Op::Verify      :
                    case Op::Assume      : return VisitAnnotation (node, fact, a   );
                    case Op::Slice       : return VisitSlice      (      fact, a   );
                    case Op::Concat      : return VisitConcat     (      fact, a, b);
                    case Op::Select      : return VisitSelect     (node, fact      );
                    case Op::Sum         : return VisitSum        (      fact, a   );
                    default              : return Fail(Message {} << "unknown operation");
                }
            }

            constexpr static Diagnostic VisitInput(const Node& node, Fact& fact)
            {
                fact.Domain      = Domain::Sparse;
                fact.Linear      = true;
                fact.FeatureSets = u32 { 1 } << (node.Binding - 1);
                fact.Range       = { .Min = 0, .Max = 1 };
                fact.Scale       = Ratio(1);
                fact.Perspective = node.Perspective == Perspective::Stm ? Dependence::Stm    :
                                   node.Perspective == Perspective::Ntm ? Dependence::Ntm    :
                                                                          Dependence::Shared ;

                return {};
            }

            constexpr Diagnostic VisitParameter(const Node& node, Fact& fact) const
            {
                const Tensor& tensor = G.Tensors[node.Tensor - 1];

                fact.Linear      = true;
                fact.FeatureSets = 0;

                if (tensor.Columns != 1) return Fail(Message {} << "a parameter must be a vector");

                if (IsFloat(tensor.Type)) {
                    const bool clipped = Defined(tensor.ClipLow);

                    fact.Domain = Domain::Float;
                    fact.Low    = clipped ? ToDouble(tensor.ClipLow ) : -Unbounded;
                    fact.High   = clipped ? ToDouble(tensor.ClipHigh) :  Unbounded;

                    if (!clipped) fact.Provenance = Provenance::Unbounded;

                    return {};
                }

                fact.Domain = Domain::Integer;
                fact.Scale  = tensor.Quantization;
                fact.Range  = TensorBounds(G, static_cast<u16>(node.Tensor - 1));

                return {};
            }

            constexpr static Diagnostic VisitConstant(const Node& node, Fact& fact)
            {
                fact.Domain = Domain::Constant;
                fact.Scale  = node.Low;
                fact.Low    = ToDouble(node.Low);
                fact.High   = fact.Low;

                return {};
            }

            constexpr Diagnostic VisitSparse(const Node& node, Fact& fact, const Fact& input) const
            {
                if (input.Domain != Domain::Sparse)
                    return Fail(Message {} << "the operand of a sparse layer must be a family input");

                const Tensor&  tensor  = G.Tensors[node.Tensor - 1];
                const Binding& binding = G.Bindings[std::countr_zero(input.FeatureSets)];

                fact.Linear = true;

                if (IsFloat(tensor.Type)) {
                    const bool clipped = Defined(tensor.ClipLow);
                    const f64  active  = binding.MaxActive;

                    fact.Domain     = Domain::Float;
                    fact.Low        = clipped ? Lower(ToDouble(tensor.ClipLow ) * active, 0) : -Unbounded;
                    fact.High       = clipped ? Upper(ToDouble(tensor.ClipHigh) * active, 0) :  Unbounded;
                    fact.Provenance = clipped ? fact.Provenance : Provenance::Unbounded;

                    return {};
                }

                fact.Domain = Domain::Integer;
                fact.Scale  = tensor.Quantization;
                fact.Range  = Repeat(TensorBounds(G, static_cast<u16>(node.Tensor - 1)), binding.MaxActive);

                return {};
            }

            constexpr Diagnostic VisitMatmul(const Node& node, Fact& fact, const Fact& input, const Fact& bias) const
            {
                const Tensor& tensor = G.Tensors[node.Tensor - 1];

                if (input.Size != tensor.Columns)
                    return Fail(Message {} << "expected input size " << i64 { tensor.Columns } << " but got " <<
                                              i64 { input.Size });

                if (IsFloat(tensor.Type)) return VisitFloatMatmul(node, fact, input, bias);

                if (input.Domain != Domain::Integer)
                    return Fail(Message {} << "integer weights require an integer input");

                if (!Fits<i32>(input.Range))
                    return Fail(Message {} << "input range [" << input.Range.Min << ", " << input.Range.Max <<
                                              "] does not fit i32");

                const Interval weights = TensorBounds(G, static_cast<u16>(node.Tensor - 1));

                fact.Domain = Domain::Integer;
                fact.Scale  = input.Scale * tensor.Quantization;
                fact.Range  = Repeat(input.Range * weights, input.Size);

                if (!Bounded(fact.Range)) return Fail(Message {} << "sum range overflows i64");

                return {};
            }

            constexpr Diagnostic VisitFloatMatmul(
                const Node& node ,
                      Fact& fact ,
                const Fact& input,
                const Fact& bias
            ) const
            {
                if (input.Domain != Domain::Float)
                    return Fail(Message {} << "f32 weights require a float input; Dequantize the value first");

                const RealRange reals   = TensorReals(G, static_cast<u16>(node.Tensor - 1));
                const bool      clipped = reals.Clipped;
                const f64       low     = clipped ? reals.Low  : -Unbounded;
                const f64       high    = clipped ? reals.High :  Unbounded;
                const Range     term    = Product(input.Low, input.High, low, high);

                fact.Domain     = Domain::Float;
                fact.Low        = Clip(Lower(term.Low , 0) * input.Size);
                fact.High       = Clip(Upper(term.High, 0) * input.Size);
                fact.Provenance = clipped ? fact.Provenance : Provenance::Unbounded;

                if (node.InputCount != 2) return {};

                if (bias.Domain != Domain::Float || bias.Size != node.Size)
                    return Fail(Message {} << "the chained bias must be a float vector of size " << i64 { node.Size });

                fact.Low  = Clip(fact.Low  + bias.Low );
                fact.High = Clip(fact.High + bias.High);

                return {};
            }

            constexpr static Diagnostic VisitAdditive(const Node& node, Fact& fact, const Fact& a, const Fact& b)
            {
                if (b.Domain == Domain::Constant) return VisitOffset(node, fact, a, b);

                if (a.Domain != b.Domain)
                    return Fail(Message {} << "operands mix integer and float values; Dequantize the integer one");

                if (a.Size != b.Size)
                    return Fail(Message {} << "operand sizes " << i64 { a.Size } << " and " << i64 { b.Size } <<
                                              " differ");

                const bool subtract = node.Operation == Op::Sub;
                const bool extremum = node.Operation == Op::Min || node.Operation == Op::Max;

                fact.Linear = node.Operation == Op::Add && a.Linear && b.Linear;

                if (a.Domain == Domain::Float) {
                    if (extremum) {
                        fact.Low  = Lower(a.Low , b.Low );
                        fact.High = Upper(a.High, b.High);

                        return {};
                    }

                    fact.Low  = subtract ? a.Low  - b.High : a.Low  + b.Low ;
                    fact.High = subtract ? a.High - b.Low  : a.High + b.High;

                    return {};
                }

                if (a.Scale != b.Scale) return ScaleMismatch(a.Scale, b.Scale);

                if (extremum) fact.Range = Hull(a.Range, b.Range);
                else if (subtract) fact.Range = a.Range - b.Range;
                else fact.Range = a.Range + b.Range;

                return {};
            }

            constexpr static Diagnostic VisitOffset(const Node& node, Fact& fact, const Fact& a, const Fact& b)
            {
                if (a.Domain == Domain::Float) {
                    fact.Low  = node.Operation == Op::Max ? Upper(a.Low , b.Low) : a.Low  + b.Low;
                    fact.High = node.Operation == Op::Min ? Lower(a.High, b.Low) : a.High + b.Low;

                    return {};
                }

                bool exact = true;

                const Interval offset = Scaled(b.Scale, a.Scale, exact);

                if (!exact)
                    return Fail(Message {} << "constant " << b.Scale << " times scale " << a.Scale <<
                                              " is not an integer");

                fact.Range = a.Range + offset;

                return {};
            }

            constexpr static Diagnostic ScaleMismatch(const Rational left, const Rational right)
            {
                const bool     larger = right < left;
                const Rational ratio  = larger ? left / right : right / left;

                Message text {};

                text << "integer scales " << left << " and " << right << " differ";

                if (Integral(ratio)) text << "; divide the " << (larger ? "left" : "right") << " operand by " << ratio;

                return Fail(text);
            }

            constexpr static Diagnostic VisitMul(const Node& node, Fact& fact, const Fact& a, const Fact& b)
            {
                if (b.Domain == Domain::Constant) return VisitScaling(fact, a, b);

                if (a.Domain != b.Domain)
                    return Fail(Message {} << "operands mix integer and float values; Dequantize the integer one");

                if (a.Size != b.Size)
                    return Fail(Message {} << "operand sizes " << i64 { a.Size } << " and " << i64 { b.Size } <<
                                              " differ");

                if (a.Domain == Domain::Float) {
                    const Range range = Product(a.Low, a.High, b.Low, b.High);

                    fact.Low  = Clip(range.Low );
                    fact.High = Clip(range.High);

                    return {};
                }

                fact.Scale = a.Scale * b.Scale;
                fact.Range = node.Inputs[0] == node.Inputs[1] ? Square(a.Range) : a.Range * b.Range;

                if (!Bounded(fact.Range))
                    return Fail(Message {} << "product range exceeds the i64 analysis headroom; " <<
                                              "Wrap or clip an operand");

                return {};
            }

            constexpr static Diagnostic VisitScaling(Fact& fact, const Fact& a, const Fact& b)
            {
                if (a.Domain == Domain::Float) {
                    const Range range = Product(a.Low, a.High, b.Low, b.Low);

                    fact.Low  = range.Low ;
                    fact.High = range.High;

                    return {};
                }

                if (!Integral(b.Scale))
                    return Fail(Message {} << "integer value multiplied by the non-integer constant " << b.Scale);

                fact.Range = a.Range * Interval { .Min = b.Scale.Numerator, .Max = b.Scale.Numerator };

                return {};
            }

            constexpr static Diagnostic VisitFloatOnly(Fact& fact, const Fact& input)
            {
                if (input.Domain != Domain::Float) return Fail(Message {} << "operation requires a float value");

                fact.Low        = -Unbounded;
                fact.High       =  Unbounded;
                fact.Provenance = Provenance::Unbounded;

                return {};
            }

            constexpr static Diagnostic VisitClamp(const Node& node, Fact& fact, const Fact& input)
            {
                const bool low  = node.Bounds == Bound::Low  || node.Bounds == Bound::Both;
                const bool high = node.Bounds == Bound::High || node.Bounds == Bound::Both;

                if (input.Domain == Domain::Float) {
                    if (low ) fact.Low  = Upper(input.Low , ToDouble(node.Low ));
                    if (low ) fact.High = Upper(input.High, ToDouble(node.Low ));
                    if (high) fact.High = Lower(fact.High , ToDouble(node.High));
                    if (high) fact.Low  = Lower(fact.Low  , ToDouble(node.High));

                    return {};
                }

                if (input.Domain != Domain::Integer) return Fail(Message {} << "clamp requires a dense value");

                constexpr i64 Lowest  = std::numeric_limits<i64>::min();
                constexpr i64 Highest = std::numeric_limits<i64>::max();

                bool lowExact  = true;
                bool highExact = true;

                const i64 lower = low  ? Scaled(node.Low , input.Scale, lowExact ).Min : Lowest ;
                const i64 upper = high ? Scaled(node.High, input.Scale, highExact).Max : Highest;

                if (!lowExact || !highExact)
                    return Fail(Message {} << "clamp bounds [" << (low ? node.Low : Ratio(0)) << ", " <<
                                              (high ? node.High : Ratio(0)) << "] times scale " << input.Scale <<
                                              " are not integers");

                fact.Range = Clamp(input.Range, lower, upper);

                return {};
            }

            constexpr static Diagnostic VisitUnary(const Node& node, Fact& fact, const Fact& input)
            {
                const bool absolute = node.Function == Function::Abs;

                if (input.Domain == Domain::Integer && absolute) {
                    const i64 magnitude = std::max(-input.Range.Min, input.Range.Max);

                    fact.Range = { .Min = input.Range.Min >= 0 ? input.Range.Min : 0, .Max = magnitude };

                    return {};
                }

                if (input.Domain != Domain::Float) return Fail(Message {} << "operation requires a float value");

                if (absolute) {
                    fact.Low  = input.Low >= 0 ? input.Low : 0;
                    fact.High = Upper(-input.Low, input.High);

                    return {};
                }

                if (node.Function == Function::Sigmoid) {
                    fact.Low  = 0;
                    fact.High = 1;

                    return {};
                }

                if (node.Function == Function::Tanh) {
                    fact.Low  = -1;
                    fact.High =  1;

                    return {};
                }

                return VisitFloatOnly(fact, input);
            }

            constexpr static Diagnostic VisitRequantize(const Node& node, Fact& fact, const Fact& input)
            {
                if (input.Domain != Domain::Integer)
                    return Fail(Message {} << "requantisation requires an integer value");

                if (node.Operation == Op::ShiftRight) {
                    fact.Range = ShiftDown(input.Range, node.Shift);
                    fact.Scale = ShiftDown(input.Scale, node.Shift);

                    return {};
                }

                if (node.Operation == Op::ShiftLeft) {
                    fact.Range = ShiftUp(input.Range, node.Shift);
                    fact.Scale = ShiftUp(input.Scale, node.Shift);

                    if (Bounded(fact.Range)) return {};

                    return Fail(Message {} << "shifted range exceeds the i64 analysis headroom");
                }

                if (!Integral(node.Low) || node.Low.Numerator <= 0)
                    return Fail(Message {} << "divisor " << node.Low << " is not a positive integer");

                fact.Range = Divide(input.Range, node.Low.Numerator);
                fact.Scale = input.Scale / node.Low;

                return {};
            }

            constexpr static Diagnostic VisitDequantize(
                const Node& node ,
                      Fact& fact ,
                const Fact& input,
                const Fact& bias
            )
            {
                if (input.Domain != Domain::Integer) return Fail(Message {} << "Dequantize requires an integer value");

                const Rational factor = Defined(node.Low) ? node.Low : Ratio(1) / input.Scale;

                fact.Domain = Domain::Float;
                fact.Scale  = Ratio(1);
                fact.Low    = static_cast<f64>(input.Range.Min) * ToDouble(factor);
                fact.High   = static_cast<f64>(input.Range.Max) * ToDouble(factor);

                if (node.InputCount == 1) return {};

                if (bias.Domain != Domain::Float || bias.Size != input.Size)
                    return Fail(Message {} << "the fused bias must be a float vector of size " << i64 { input.Size });

                fact.Low  += bias.Low ;
                fact.High += bias.High;

                return {};
            }

            constexpr static Diagnostic VisitAnnotation(const Node& node, Fact& fact, const Fact& input)
            {
                if (input.Domain != Domain::Integer)
                    return Fail(Message {} << "range annotations require an integer value");

                fact.Linear = input.Linear;

                if (node.Operation == Op::Wrap) {
                    if (!FitsType(input.Range, node.Type)) fact.Range = RangeOf(node.Type);

                    return {};
                }

                if (node.Operation == Op::Verify) {
                    if (!input.Linear) return Fail(Message {} << "Verify applies to accumulated sums only");

                    if (FitsType(input.Range, node.Type)) return {};

                    fact.Range      = RangeOf(node.Type);
                    fact.Provenance = Weakest(fact.Provenance, Provenance::LoadVerified);

                    return {};
                }

                const i64 lower = Scaled(node.Low , input.Scale).Min;
                const i64 upper = Scaled(node.High, input.Scale).Max;

                fact.Range      = { .Min = lower, .Max = upper };
                fact.Provenance = Weakest(fact.Provenance, Provenance::Assumed);
                fact.Linear     = false;

                return {};
            }

            constexpr static Diagnostic VisitSlice(Fact& fact, const Fact& input)
            {
                fact.Linear = input.Linear;

                return {};
            }

            constexpr static Diagnostic VisitConcat(Fact& fact, const Fact& a, const Fact& b)
            {
                if (a.Domain != b.Domain)
                    return Fail(Message {} << "concatenated values mix integer and float domains");

                if (a.Domain == Domain::Integer && a.Scale != b.Scale)
                    return Fail(Message {} << "concatenated scales " << a.Scale << " and " << b.Scale << " differ");

                fact.Range = Hull(a.Range, b.Range);
                fact.Low   = Lower(a.Low , b.Low );
                fact.High  = Upper(a.High, b.High);

                return {};
            }

            constexpr static Diagnostic VisitSelect(const Node& node, Fact& fact)
            {
                fact.Selector = node.Binding;

                return {};
            }

            constexpr static Diagnostic VisitSum(Fact& fact, const Fact& input)
            {
                fact.Range = Repeat(input.Range, input.Size);
                fact.Low   = Clip(input.Low  * input.Size);
                fact.High  = Clip(input.High * input.Size);

                return {};
            }

            constexpr static bool FitsType(const Interval range, const DType type)
            {
                const Interval bounds = RangeOf(type);

                return range.Min >= bounds.Min && range.Max <= bounds.Max;
            }

            constexpr static Diagnostic CheckHead(const Head& head, const Fact& fact)
            {
                if (fact.Domain == Domain::Float) return {};

                if (fact.Domain != Domain::Integer) return Fail(Message {} << "an output must be a dense value");

                const Rational factor = head.Scale / fact.Scale;
                const Interval range {
                    .Min = Floor(Ratio(fact.Range.Min) * factor),
                    .Max = Ceil (Ratio(fact.Range.Max) * factor)
                };

                if (Fits<i32>(range)) return {};

                return Fail(Message {} << "output range [" << range.Min << ", " << range.Max << "] does not fit i32");
            }

            constexpr static Diagnostic CheckTensor(const Tensor& tensor)
            {
                if (!IsFloat(tensor.Type) && !(Ratio(0) < tensor.Quantization))
                    return Fail(Message {} << "tensor scale " << tensor.Quantization << " is not positive");

                if (Defined(tensor.ClipLow) && !(tensor.ClipLow < tensor.ClipHigh))
                    return Fail(Message {} << "tensor clip is empty");

                if (tensor.Layout.Buckets > 1 && tensor.Rows % tensor.Layout.Buckets != 0)
                    return Fail(Message {} << "rows " << i64 { tensor.Rows } << " are not divisible into " <<
                                              i64 { tensor.Layout.Buckets } << " buckets");

                return {};
            }

        };

    }

    template<Sizes S>
    consteval Analysis<S.Nodes> Analyze(const Graph<S>& graph)
    {
        constexpr s00 N = S.Nodes;

        Analysis<N> analysis {};

        const Detail::Analyzer<S> analyzer { graph };

        analysis.Diagnostic = analyzer.CheckGraph();

        for (s00 i = 0; i < S.Tensors && analysis.Diagnostic.Ok; i++)
            analysis.Diagnostic = analyzer.Locate(graph.Tensors[i], analyzer.CheckTensor(graph.Tensors[i]));

        for (s00 i = 0; i < N && analysis.Diagnostic.Ok; i++) {
            const Node& node = graph.Nodes[i];
            Fact&       fact = analysis.Facts[i];

            Array<Fact, MaxInputs> inputs {};

            for (s00 k = 0; k < node.InputCount; k++) {
                inputs[k] = analysis.Facts[node.Inputs[k]];

                analysis.Facts[node.Inputs[k]].Consumers++;
            }

            analysis.Diagnostic = analyzer.Locate(node, analyzer.Visit(node, fact, inputs));

            if (fact.Domain == Domain::Integer) fact.Storage = StorageOf(fact.Range);
            if (fact.Domain == Domain::Float  ) fact.Storage = DType::F32;

            if (node.Operation == Op::Verify && fact.Provenance == Provenance::LoadVerified)
                analysis.Verified[analysis.Checks++] = static_cast<u16>(i);
        }

        for (s00 i = 0; i < S.Heads && analysis.Diagnostic.Ok; i++) {
            const Head& head = graph.Heads[i];
            const Node& node = graph.Nodes[head.Node];

            analysis.Diagnostic = analyzer.Locate(
                node.File,
                node.Line,
                node.Column,
                "Output",
                analyzer.CheckHead(head, analysis.Facts[head.Node])
            );
        }

        for (s00 i = 0; i < N && analysis.Diagnostic.Ok; i++) {
            const Node& node = graph.Nodes[i];

            if (node.Operation != Op::Select || node.InputCount == 0) continue;

            for (s00 k = node.Inputs[0]; ; k = graph.Nodes[k].Inputs[0]) {
                const Node& producer = graph.Nodes[k];

                analysis.Facts[k].Selector = node.Binding;

                if (producer.Operation == Op::Matmul || producer.Operation == Op::SparseMatmul) break;
                if (producer.InputCount == 0                                                     ) break;
            }
        }

        return analysis;
    }

}

#endif //MANTARAY_IR_ANALYSIS_H
