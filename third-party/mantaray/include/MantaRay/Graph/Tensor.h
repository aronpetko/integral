//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_GRAPH_TENSOR_H
#define MANTARAY_GRAPH_TENSOR_H

#include <type_traits>
#include <utility>

#include "../Common.h"
#include "../IR/GraphIR.h"

namespace MantaRay
{

    template<typename T>
    constexpr IR::DType DTypeOf()
    {
        static_assert(
            std::is_same_v<T, i08> || std::is_same_v<T, u08> || std::is_same_v<T, i16> ||
            std::is_same_v<T, i32> || std::is_same_v<T, f32>,
            "a tensor element type must be i08, u08, i16, i32 or f32"
        );

        if (std::is_same_v<T, i08>) return IR::DType::I08;
        if (std::is_same_v<T, u08>) return IR::DType::U08;
        if (std::is_same_v<T, i16>) return IR::DType::I16;
        if (std::is_same_v<T, i32>) return IR::DType::I32;
        if (std::is_same_v<T, f32>) return IR::DType::F32;

        std::unreachable();
    }

    struct Quantization
    {

        Rational Value {};

        constexpr Quantization(const i64      value) : Value(Ratio(value)) {}
        constexpr Quantization(const Rational value) : Value(value       ) {}

    };

    struct Clip
    {

        Rational Low  {};
        Rational High {};

        constexpr Clip() = default;

        constexpr explicit Clip(const f64 bound) : Low(RationalOf(-bound)), High(RationalOf(bound)) {}

        constexpr Clip(const f64 low, const f64 high) : Low(RationalOf(low)), High(RationalOf(high)) {}

    };

    namespace Layout
    {

        constexpr inline IR::Layout ColumnMajor { .Order = IR::Order::ColumnMajor };
        constexpr inline IR::Layout RowMajor    { .Order = IR::Order::RowMajor    };

        constexpr IR::Layout BucketMajor(const u16 buckets)
        { return { .Order = IR::Order::BucketMajor, .Buckets = buckets }; }

        constexpr IR::Layout Blocked(const u16 buckets, const u16 block)
        { return { .Order = IR::Order::Blocked, .Buckets = buckets, .Block = block }; }

    }

    class TensorSpec
    {

        IR::Tensor Spec {};

        public:
        constexpr TensorSpec(
            const IR::Role      role        ,
            const IR::DType     type        ,
            const Quantization& quantization,
            const Clip&         clip
        )
        {
            Spec.Role         = role;
            Spec.Type         = type;
            Spec.Stored       = type;
            Spec.Rounding     = IR::Rounding::HalfAway;
            Spec.Layout       = Layout::ColumnMajor;
            Spec.Quantization = IR::IsFloat(type) ? Ratio(1) : quantization.Value;
            Spec.ClipLow      = clip.Low ;
            Spec.ClipHigh     = clip.High;
        }

        constexpr TensorSpec Arranged(const IR::Layout layout) const
        {
            TensorSpec copy = *this;

            copy.Spec.Layout = layout;

            return copy;
        }

        constexpr TensorSpec RowMajor() const { return Arranged(Layout::RowMajor); }

        template<typename T>
        constexpr TensorSpec Stored() const
        {
            TensorSpec copy = *this;

            copy.Spec.Stored = DTypeOf<T>();

            return copy;
        }

        constexpr TensorSpec Truncated() const
        {
            TensorSpec copy = *this;

            copy.Spec.Rounding = IR::Rounding::Truncate;

            return copy;
        }

        constexpr const IR::Tensor& Describe() const { return Spec; }

    };

    template<typename T>
    constexpr TensorSpec Weights(const Quantization& quantization = 1, const Clip& clip = {})
    {
        return { IR::Role::Weights, DTypeOf<T>(), quantization, clip };
    }

    template<typename T>
    constexpr TensorSpec Biases(const Quantization& quantization = 1, const Clip& clip = {})
    {
        return { IR::Role::Biases, DTypeOf<T>(), quantization, clip };
    }

}

#endif //MANTARAY_GRAPH_TENSOR_H
