//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_GRAPH_OPERATION_H
#define MANTARAY_GRAPH_OPERATION_H

#include <source_location>
#include <utility>

#include "Tensor.h"
#include "Value.h"
#include "../Common.h"
#include "../IR/GraphIR.h"

namespace MantaRay
{

    namespace Detail
    {

        constexpr Shared<Node> Scalar(const Rational value, const std::source_location& site)
        {
            IR::Node node = Spec(IR::Op::Constant, 1);

            node.Low = value;

            const Placed placed = Located(node, site);

            return Shared<Node> { std::in_place, placed.Spec, placed.File };
        }

        template<typename V>
        constexpr V Unary(const V& x, IR::Node spec, const std::source_location& site)
        {
            spec.Size = x.Size();

            return Make<V>(Located(spec, site), { x.Handle() }, Expect::DenseOperand(x.Sparse()));
        }

        template<typename V, typename L, typename R>
        constexpr V Binary(const IR::Op operation, const L& left, const R& right, const std::source_location& site)
        {
            const IR::Fault fault = Expect::DenseOperand(left.Sparse() || right.Sparse()) |
                                    Expect::SameSize    (left.Size()  ,   right.Size()  );

            return Make<V>(Located(Spec(operation, left.Size()), site), { left.Handle(), right.Handle() }, fault);
        }

        template<typename V>
        constexpr V WithScalar(const IR::Op operation, const V& x, const f64 value, const std::source_location& site)
        {
            return Make<V>(
                Located(Spec(operation, x.Size()), site),
                { x.Handle(), Scalar(RationalOf(value), site) },
                Expect::DenseOperand(x.Sparse())
            );
        }

        template<typename V>
        constexpr V Shifted(const IR::Op operation, const V& x, const u16 shift, const std::source_location& site)
        {
            IR::Node spec = Spec(operation, 0);

            spec.Shift = shift;

            return Unary(x, spec, site);
        }

        template<typename V>
        constexpr V Bounded(
            const V&                    x     ,
            const IR::Bound             bounds,
            const Rational              low   ,
            const Rational              high  ,
            const std::source_location& site
        )
        {
            IR::Node spec = Spec(IR::Op::Clamp, x.Size());

            spec.Bounds = bounds;
            spec.Low    = low   ;
            spec.High   = high  ;

            const IR::Fault fault = Expect::DenseOperand(x.Sparse()) |
                                    (bounds == IR::Bound::Both ? Expect::OrderedBounds(low, high) : IR::Fault {});

            return Make<V>(Located(spec, site), { x.Handle() }, fault);
        }

    }

    template<typename... F>
    constexpr Value<F...> Clamp(
        const Value<F...>&          x                                   ,
        const f64                   low                                 ,
        const f64                   high                                ,
        const std::source_location& site = std::source_location::current()
    )
    { return Detail::Bounded(x, IR::Bound::Both, RationalOf(low), RationalOf(high), site); }

    template<typename... F>
    constexpr Value<F...> ClippedReLU(
        const Value<F...>&          x                                   ,
        const f64                   low  = 0                            ,
        const f64                   high = 1                            ,
        const std::source_location& site = std::source_location::current()
    )
    { return Detail::Bounded(x, IR::Bound::Both, RationalOf(low), RationalOf(high), site); }

    template<typename... F>
    constexpr Value<F...> ReLU(const Value<F...>& x, const std::source_location& site = std::source_location::current())
    { return Detail::Bounded(x, IR::Bound::Low, Ratio(0), {}, site); }

    template<typename... F>
    constexpr Value<F...> Min(
        const Value<F...>&          x                                   ,
        const f64                   high                                ,
        const std::source_location& site = std::source_location::current()
    )
    { return Detail::Bounded(x, IR::Bound::High, {}, RationalOf(high), site); }

    template<typename... F>
    constexpr Value<F...> Max(
        const Value<F...>&          x                                   ,
        const f64                   low                                 ,
        const std::source_location& site = std::source_location::current()
    )
    { return Detail::Bounded(x, IR::Bound::Low, RationalOf(low), {}, site); }

    template<typename... L, typename... R>
    constexpr Union<Value<L...>, Value<R...>> Min(
        const Value<L...>&          left                                ,
        const Value<R...>&          right                               ,
        const std::source_location& site = std::source_location::current()
    )
    { return Detail::Binary<Union<Value<L...>, Value<R...>>>(IR::Op::Min, left, right, site); }

    template<typename... L, typename... R>
    constexpr Union<Value<L...>, Value<R...>> Max(
        const Value<L...>&          left                                ,
        const Value<R...>&          right                               ,
        const std::source_location& site = std::source_location::current()
    )
    { return Detail::Binary<Union<Value<L...>, Value<R...>>>(IR::Op::Max, left, right, site); }

    template<typename... F>
    constexpr Value<F...> SquaredClippedReLU(
        const Value<F...>&          x                                   ,
        const f64                   low  = 0                            ,
        const f64                   high = 1                            ,
        const std::source_location& site = std::source_location::current()
    )
    {
        const Value<F...> clipped = ClippedReLU(x, low, high, site);

        return Detail::Binary<Value<F...>>(IR::Op::Mul, clipped, clipped, site);
    }

    template<typename... F>
    constexpr Value<F...> SquaredReLU(
        const Value<F...>&          x                                   ,
        const std::source_location& site = std::source_location::current()
    )
    {
        const Value<F...> rectified = ReLU(x, site);

        return Detail::Binary<Value<F...>>(IR::Op::Mul, rectified, rectified, site);
    }

    template<typename... F>
    constexpr Value<F...> Square(
        const Value<F...>&          x                                   ,
        const std::source_location& site = std::source_location::current()
    )
    { return Detail::Binary<Value<F...>>(IR::Op::Mul, x, x, site); }

    template<typename... F>
    constexpr Value<F...> Apply(
        const Value<F...>&          x                                   ,
        const IR::Function          function                            ,
        const std::source_location& site = std::source_location::current()
    )
    {
        IR::Node spec = Detail::Spec(IR::Op::Unary, 0);

        spec.Function = function;

        return Detail::Unary(x, spec, site);
    }

    template<typename... F>
    constexpr Value<F...> Abs(const Value<F...>& x, const std::source_location& site = std::source_location::current())
    { return Apply(x, IR::Function::Abs, site); }

    template<typename... F>
    constexpr Value<F...> Sigmoid(
        const Value<F...>&          x                                   ,
        const std::source_location& site = std::source_location::current()
    )
    { return Apply(x, IR::Function::Sigmoid, site); }

    template<typename... F>
    constexpr Value<F...> Exp(const Value<F...>& x, const std::source_location& site = std::source_location::current())
    { return Apply(x, IR::Function::Exp, site); }

    template<typename... F>
    constexpr Value<F...> Tanh(const Value<F...>& x, const std::source_location& site = std::source_location::current())
    { return Apply(x, IR::Function::Tanh, site); }

    template<typename... F>
    constexpr Value<F...> AbsPow(
        const Value<F...>&          x                                   ,
        const f64                   power                               ,
        const std::source_location& site = std::source_location::current()
    )
    { return Detail::WithScalar(IR::Op::Pow, Abs(x, site), power, site); }

    template<typename... F>
    constexpr Value<F...> Divide(
        const Value<F...>&          x                                   ,
        const i64                   divisor                             ,
        const std::source_location& site = std::source_location::current()
    )
    {
        IR::Node spec = Detail::Spec(IR::Op::Divide, 0);

        spec.Low = Ratio(divisor);

        return Detail::Unary(x, spec, site);
    }

    template<typename... F>
    constexpr Value<F...> Dequantize(
        const Value<F...>&          x                                   ,
        const Rational              factor = {}                         ,
        const std::source_location& site   = std::source_location::current()
    )
    {
        IR::Node spec = Detail::Spec(IR::Op::Dequantize, 0);

        spec.Low = factor;

        return Detail::Unary(x, spec, site);
    }

    template<typename T, typename... F>
    constexpr Value<F...> Wrap(const Value<F...>& x, const std::source_location& site = std::source_location::current())
    {
        IR::Node spec = Detail::Spec(IR::Op::Wrap, 0);

        spec.Type = DTypeOf<T>();

        return Detail::Unary(x, spec, site);
    }

    template<typename T, typename... F>
    constexpr Value<F...> Verify(
        const Value<F...>&          x                                   ,
        const std::source_location& site = std::source_location::current()
    )
    {
        IR::Node spec = Detail::Spec(IR::Op::Verify, 0);

        spec.Type = DTypeOf<T>();

        return Detail::Unary(x, spec, site);
    }

    template<typename... F>
    constexpr Value<F...> Assume(
        const Value<F...>&          x                                   ,
        const f64                   low                                 ,
        const f64                   high                                ,
        const std::source_location& site = std::source_location::current()
    )
    {
        IR::Node spec = Detail::Spec(IR::Op::Assume, 0);

        spec.Low  = RationalOf(low );
        spec.High = RationalOf(high);

        return Detail::Unary(x, spec, site);
    }

    template<typename... F>
    constexpr Value<F...> Slice(
        const Value<F...>&          x                                   ,
        const u32                   begin                               ,
        const u32                   end                                 ,
        const std::source_location& site = std::source_location::current()
    )
    {
        const IR::Fault fault = Expect::DenseOperand(x.Sparse()) | Expect::SliceInside(begin, end, x.Size());

        IR::Node spec = Detail::Spec(IR::Op::Slice, fault.Code == IR::FaultCode::None ? end - begin : 0);

        spec.Begin = begin;
        spec.End   = end  ;

        return Detail::Make<Value<F...>>(Detail::Located(spec, site), { x.Handle() }, fault);
    }

    template<typename... F>
    constexpr Value<F...> Pairwise(
        const Value<F...>&          x                                   ,
        const std::source_location& site = std::source_location::current()
    )
    {
        const u32 half = x.Size() / 2;

        return Detail::Make<Value<F...>>(
            Detail::Located(Detail::Spec(IR::Op::Mul, half), site),
            { Slice(x, 0, half, site).Handle(), Slice(x, half, 2 * half, site).Handle() },
            Expect::DenseOperand(x.Sparse()) | Expect::EvenSize(x.Size())
        );
    }

    template<typename... F>
    constexpr std::pair<Value<F...>, Value<F...>> Halves(
        const Value<F...>&          x                                   ,
        const std::source_location& site = std::source_location::current()
    )
    {
        const u32 half = x.Size() / 2;

        const Value<F...> low  = Slice(x, 0   , half    , site);
        const Value<F...> high = Slice(x, half, 2 * half, site);

        const Detail::Placed placed { .Spec = low.Handle()->Spec, .File = low.Handle()->File };

        return { Detail::Make<Value<F...>>(placed, { x.Handle() }, Expect::EvenSize(x.Size())), high };
    }

    template<typename... L, typename... R>
    constexpr Union<Value<L...>, Value<R...>> Concat(
        const Value<L...>&          left                                ,
        const Value<R...>&          right                               ,
        const std::source_location& site = std::source_location::current()
    )
    {
        return Detail::Make<Union<Value<L...>, Value<R...>>>(
            Detail::Located(Detail::Spec(IR::Op::Concat, left.Size() + right.Size()), site),
            { left.Handle(), right.Handle() },
            Expect::DenseOperand(left.Sparse() || right.Sparse())
        );
    }

    template<typename S, typename... F>
    constexpr Detail::With<Value<F...>, S> Select(
        const Value<F...>&          x                                   ,
        const std::source_location& site = std::source_location::current()
    )
    {
        const IR::Fault fault = Expect::DenseOperand(x.Sparse()) | Expect::DivisibleIntoBuckets(x.Size(), S::Count);

        IR::Node spec = Detail::Spec(IR::Op::Select, x.Size() / S::Count);

        spec.Begin = S::Count;

        return Detail::Make<Detail::With<Value<F...>, S>>(
            Detail::Located(spec, site),
            { x.Handle() },
            fault,
            {},
            &Detail::Tag<S>
        );
    }

    template<typename... F>
    constexpr Value<F...> Sum(const Value<F...>& x, const std::source_location& site = std::source_location::current())
    {
        return Detail::Make<Value<F...>>(
            Detail::Located(Detail::Spec(IR::Op::Sum, 1), site),
            { x.Handle() },
            Expect::DenseOperand(x.Sparse())
        );
    }

}

#endif //MANTARAY_GRAPH_OPERATION_H
