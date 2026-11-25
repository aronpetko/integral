//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_GRAPH_LAYER_H
#define MANTARAY_GRAPH_LAYER_H

#include <source_location>
#include <utility>

#include "Tensor.h"
#include "Value.h"
#include "../Common.h"
#include "../IR/GraphIR.h"

namespace MantaRay
{

    struct Epilogue
    {

        IR::Op   Operation = IR::Op::None;
        u16      Shift     = 0;
        Rational Factor    {};
        bool     Fused     = true;

        constexpr Epilogue Unfused() const
        {
            Epilogue copy = *this;

            copy.Fused = false;

            return copy;
        }

    };

    constexpr Epilogue DivideBy(const i64 divisor) { return { .Operation = IR::Op::Divide, .Factor = Ratio(divisor) }; }

    constexpr Epilogue ShiftRight(const u16 shift) { return { .Operation = IR::Op::ShiftRight, .Shift = shift }; }

    constexpr Epilogue Dequantize(const Rational factor = {})
    { return { .Operation = IR::Op::Dequantize, .Factor = factor }; }

    class TensorRef
    {

        Detail::Shared<Detail::Token> Token;

        public:
        constexpr explicit TensorRef(Detail::Shared<Detail::Token> token) : Token(std::move(token)) {}

        constexpr const Detail::Shared<Detail::Token>& Handle() const { return Token; }

    };

    using Reduction = IR::Reduction;

    class Layer
    {

        Detail::Shared<Detail::Token> WeightToken {};
        Detail::Shared<Detail::Token> BiasToken   {};

        u32 RowBegin    = 0;
        u32 RowEnd      = 0;
        u32 ColumnBegin = 0;
        u32 ColumnEnd   = 0;

        Epilogue      Plan  {};
        IR::Reduction Order = IR::Reduction::Sequential;
        IR::Fault     Fault {};

        constexpr static Detail::Shared<Detail::Token> Declare(
            const TensorSpec&           spec ,
            const u32                   rows ,
            const u32                   cols ,
            const std::source_location& site
        )
        {
            IR::Tensor tensor = spec.Describe();

            tensor.Rows    = rows;
            tensor.Columns = cols;
            tensor.Line    = static_cast<u16>(site.line  ());
            tensor.Column  = static_cast<u16>(site.column());

            return Detail::Shared<Detail::Token>(Detail::Token { .Spec = tensor, .File = site.file_name() });
        }

        constexpr static Detail::Shared<Detail::Token> Folded(
            const Detail::Shared<Detail::Token>& base  ,
            const Detail::Shared<Detail::Token>& factor
        )
        {
            IR::Tensor tensor = base->Spec;

            tensor.Role   = IR::Role::Folded;
            tensor.Stored = IR::DType::None;
            tensor.Layout = {};

            return Detail::Shared<Detail::Token> {
                Detail::Token { .Spec = tensor, .File = base->File, .Base = base, .Factor = factor }
            };
        }

        constexpr static IR::Fault FoldShape(const IR::Tensor& base, const IR::Tensor& factor)
        {
            const bool fits = factor.Rows != 0 && factor.Columns != 0 && base.Rows % factor.Rows == 0 &&
                              base.Columns % factor.Columns == 0 && base.Type == factor.Type;

            if (fits) return {};

            return Expect::Raise(IR::FaultCode::FoldShape, factor.Rows, factor.Columns, base.Rows);
        }

        constexpr Detail::Shared<Detail::Node> Bias(const std::source_location& site) const
        {
            IR::Node spec {};

            spec.Operation = IR::Op::Parameter;
            spec.Size      = RowEnd - RowBegin;
            spec.Begin     = RowBegin;
            spec.End       = RowEnd;

            const Detail::Placed placed = Detail::Located(spec, site);

            return Detail::Shared<Detail::Node> {
                std::in_place, placed.Spec, placed.File, Detail::Edges {}, BiasToken
            };
        }

        public:
        constexpr explicit Layer(
            const u32                   inputs ,
            const u32                   outputs,
            const TensorSpec&           weights,
            const Epilogue&             plan   ,
            const std::source_location& site
        ) : WeightToken(Declare(weights, outputs, inputs, site)), RowEnd(outputs), ColumnEnd(inputs), Plan(plan) {}

        constexpr explicit Layer(
            const u32                   inputs ,
            const u32                   outputs,
            const TensorSpec&           weights,
            const TensorSpec&           biases ,
            const Epilogue&             plan   ,
            const std::source_location& site
        ) : Layer(inputs, outputs, weights, plan, site)
        {
            BiasToken = Declare(biases, outputs, 1, site);
        }

        constexpr explicit Layer(const Layer& base, const Layer& factor) : Layer(base)
        {
            WeightToken = Folded(base.WeightToken, factor.WeightToken);
            Fault       = FoldShape(base.WeightToken->Spec, factor.WeightToken->Spec);

            if (base.BiasToken && factor.BiasToken) {
                BiasToken = Folded(base.BiasToken, factor.BiasToken);
                Fault     = Fault | FoldShape(base.BiasToken->Spec, factor.BiasToken->Spec);
            }
        }

        template<typename... F>
        constexpr Value<F...> operator ()(
            const Value<F...>&          x                                   ,
            const std::source_location& site = std::source_location::current()
        ) const
        {
            IR::Node spec {};

            spec.Operation = x.Sparse() ? IR::Op::SparseMatmul : IR::Op::Matmul;
            spec.Size      = RowEnd - RowBegin;
            spec.Begin     = RowBegin;
            spec.End       = RowEnd;
            spec.Offset    = ColumnBegin;
            spec.Reduction = Order;

            const bool chained = Order == IR::Reduction::BiasFirstFma;
            const bool floats  = WeightToken->Spec.Type == IR::DType::F32 &&
                                 (!BiasToken || BiasToken->Spec.Type == IR::DType::F32);
            const bool invalid = Order != IR::Reduction::Sequential &&
                                 (!floats || x.Sparse() || (chained && !BiasToken));

            const IR::Fault order = invalid ? Expect::Raise(IR::FaultCode::ReductionDomain) : IR::Fault {};
            const IR::Fault fault = Fault | Expect::AffineInputSize(ColumnEnd - ColumnBegin, x.Size()) | order;

            const Detail::Placed placed = Detail::Located(spec, site);

            Detail::Edges edges = chained && BiasToken ? Detail::Edges { x.Handle(), Bias(site) }
                                                       : Detail::Edges { x.Handle()             };

            Detail::Shared<Detail::Node> sum =
                Detail::Make<Value<F...>>(placed, std::move(edges), fault, WeightToken).Handle();

            if (chained) return Value<F...>(sum);

            if (Plan.Operation != IR::Op::None) {
                IR::Node epilogue {};

                epilogue.Operation = Plan.Operation;
                epilogue.Size      = spec.Size;
                epilogue.Shift     = Plan.Shift;
                epilogue.Low       = Plan.Factor;

                Detail::Edges inputs { sum };

                const bool fused = Plan.Operation == IR::Op::Dequantize && Plan.Fused && BiasToken;

                if (fused) inputs.Push(Bias(site));

                sum = Detail::Make<Value<F...>>(Detail::Located(epilogue, site), std::move(inputs)).Handle();

                if (fused) return Value<F...>(sum);
            }

            if (!BiasToken) return Value<F...>(sum);

            IR::Node add {};

            add.Operation = IR::Op::Add;
            add.Size      = spec.Size;

            return Detail::Make<Value<F...>>(Detail::Located(add, site), { sum, Bias(site) });
        }

        template<typename... F>
        constexpr Value<F...> Forward(
            const Value<F...>&          x                                   ,
            const std::source_location& site = std::source_location::current()
        ) const
        { return (*this)(x, site); }

        constexpr Layer Slice(const u32 begin, const u32 end) const
        {
            Layer copy = *this;

            copy.Fault    = Fault | Expect::SliceInside(begin, end, RowEnd - RowBegin);
            copy.RowBegin = RowBegin + begin;
            copy.RowEnd   = RowBegin + end  ;

            return copy;
        }

        constexpr Layer Inputs(const u32 begin, const u32 end) const
        {
            Layer copy = *this;

            copy.Fault       = Fault | Expect::SliceInside(begin, end, ColumnEnd - ColumnBegin);
            copy.ColumnBegin = ColumnBegin + begin;
            copy.ColumnEnd   = ColumnBegin + end  ;

            return copy;
        }

        constexpr Layer Ordered(const IR::Reduction order) const
        {
            Layer copy = *this;

            copy.Order = order;

            return copy;
        }

        constexpr TensorRef Weights() const { return TensorRef(WeightToken); }

        constexpr TensorRef Biases() const { return TensorRef(BiasToken); }

    };

    constexpr Layer Affine(
        const u32                   inputs                              ,
        const u32                   outputs                             ,
        const TensorSpec&           weights                             ,
        const TensorSpec&           biases                              ,
        const Epilogue&             plan = {}                           ,
        const std::source_location& site = std::source_location::current()
    )
    { return Layer(inputs, outputs, weights, biases, plan, site); }

    constexpr Layer Linear(
        const u32                   inputs                              ,
        const u32                   outputs                             ,
        const TensorSpec&           weights                             ,
        const Epilogue&             plan = {}                           ,
        const std::source_location& site = std::source_location::current()
    )
    { return Layer(inputs, outputs, weights, plan, site); }

    constexpr Layer Fold(const Layer& base, const Layer& factor) { return Layer(base, factor); }

    constexpr Value<> Parameter(
        const u32                   size                                ,
        const TensorSpec&           spec                                ,
        const std::source_location& site = std::source_location::current()
    )
    {
        IR::Tensor tensor = spec.Describe();

        tensor.Rows    = size;
        tensor.Columns = 1;
        tensor.Line    = static_cast<u16>(site.line  ());
        tensor.Column  = static_cast<u16>(site.column());

        IR::Node node {};

        node.Operation = IR::Op::Parameter;
        node.Size      = size;
        node.End       = size;

        const Detail::Placed placed = Detail::Located(node, site);

        Detail::Shared<Detail::Token> token { Detail::Token { .Spec = tensor, .File = site.file_name() } };

        return Value<>(
            Detail::Shared<Detail::Node>(
                Detail::Node { .Spec = placed.Spec, .File = placed.File, .Tensor = std::move(token) }
            )
        );
    }

    template<typename... F>
    constexpr TensorRef TensorOf(const Value<F...>& parameter) { return TensorRef(parameter.Handle()->Tensor); }

}

#endif //MANTARAY_GRAPH_LAYER_H
