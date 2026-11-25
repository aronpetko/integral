//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_MODEL_H
#define MANTARAY_MODEL_H

#include <type_traits>

#include "Common.h"
#include "Graph/Output.h"
#include "IR/Analysis.h"
#include "IR/Canonical.h"
#include "IR/GraphIR.h"

namespace MantaRay
{

    namespace Detail
    {

        constexpr inline s00 LineWidth = 36;

        template<s00 L>
        struct Lines
        {

            constexpr static s00 Count  = L == 0 ? 1 : (L + LineWidth - 1) / LineWidth;
            constexpr static s00 Length = (L + Count - 1) / Count;

            Array<char, Count, Length + 1> Text {};

        };

        static_assert(
            sizeof(Lines<0>) == Lines<0>::Count * (Lines<0>::Length + 1),
            "Lines (the template argument) must have no padding"
        );

        template<s00 L>
        consteval Lines<L> Split(const Message& message)
        {
            constexpr s00 Length = Lines<L>::Length;

            static_assert(
                sizeof(Lines<L>) == Lines<L>::Count * (Length + 1),
                "Lines (the template argument) must have no padding"
            );

            Lines<L> lines {};

            for (s00 line = 0; line < Lines<L>::Count; line++) {
                for (s00 i = 0; i < Length; i++) {
                    const s00 index = line * Length + i;

                    lines.Text[line][i] = index < L ? message.data()[index] : ' ';
                }

                lines.Text[line][Length] = '\0';
            }

            return lines;
        }

        template<auto>
        constexpr inline bool Rejected = false;

        template<Lines<0> R>
        constexpr inline bool Rejected<R> = true;

        template<typename T>
        struct BindingList;

        template<typename... B>
        struct BindingList<Graph<B...>> { using Type = List<B...>; };

        template<typename L, s00 I>
        struct BindingAt;

        template<s00 I, typename... B>
        struct BindingAt<List<B...>, I> { using Type = At<I, B...>; };

        template<IR::Sizes S>
        consteval bool Narrowed(const IR::Graph<S>& graph)
        {
            for (const IR::Node& node : graph.Nodes)
                if (IR::Detail::UsesBinding(node.Operation) && node.Binding == 0) return true;

            return false;
        }

        template<s00 N, IR::Sizes S>
        consteval s00 Reported(const IR::Analysis<N>& result, const IR::Graph<S>& raw)
        {
            if (result.Diagnostic.Ok || Narrowed(raw)) return 0;

            return result.Diagnostic.Text.size();
        }

        template<auto D>
        consteval IR::Sizes Measure() { return D().Measure(); }

        template<auto D, IR::Sizes S>
        consteval IR::Graph<S> Freeze() { return D().template Freeze<S>(); }

        template<auto D>
        struct Pipeline
        {

            using Bindings = BindingList<std::remove_cvref_t<decltype(D())>>::Type;

            template<s00 I>
            using Binding = BindingAt<Bindings, I>::Type;

            constexpr static IR::Sizes            Sizes     = Measure<D>();
            constexpr static IR::Graph<Sizes>     Raw       = Freeze<D, Sizes>();
            constexpr static IR::Sizes            Canonical = IR::CanonicalSizes(Raw);
            constexpr static IR::Graph<Canonical> Graph     = IR::Canonicalize<Canonical>(Raw);
            constexpr static s00                  Nodes     = Canonical.Nodes;
            constexpr static IR::Analysis<Nodes>  Result    = IR::Analyze(Graph);

            constexpr static s00  Length = Reported(Result, Raw);
            constexpr static auto Report = Split<Length>(Result.Diagnostic.Text);

            constexpr static const auto& Facts = Result.Facts;
            constexpr static bool        Ok    = Result.Diagnostic.Ok;

        };

        template<auto D>
        consteval bool Accept()
        {
            if constexpr (std::is_invocable_v<decltype(D)>) return Pipeline<D>::Ok;

            return false;
        }

        template<auto D>
        consteval bool Refuse()
        {
            if constexpr (std::is_invocable_v<decltype(D)>) return Pipeline<D>::Length != 0;

            return false;
        }

        template<auto D>
        constexpr inline bool Accepted = Accept<D>();

        template<auto D>
        constexpr inline bool Refused = Refuse<D>();

    }

    template<auto D>
    struct Model
    {

        static_assert(
            std::is_invocable_v<decltype(D)>,
            "Model<D> takes the definition, which must be a constexpr function (Model<Net>) or a consteval lambda"
        );

        using Bindings = Detail::Pipeline<D>::Bindings;

        template<s00 I>
        using Binding = Detail::Pipeline<D>::template Binding<I>;

        constexpr static IR::Sizes            Sizes     = Detail::Pipeline<D>::Sizes;
        constexpr static IR::Graph<Sizes>     Raw       = Detail::Pipeline<D>::Raw;
        constexpr static IR::Sizes            Canonical = Detail::Pipeline<D>::Canonical;
        constexpr static IR::Graph<Canonical> Graph     = Detail::Pipeline<D>::Graph;
        constexpr static s00                  Nodes     = Canonical.Nodes;
        constexpr static IR::Analysis<Nodes>  Result    = Detail::Pipeline<D>::Result;

        constexpr static auto Report = Detail::Pipeline<D>::Report;

        static_assert(Detail::Rejected<Report>, "the network definition is invalid");

        constexpr static const auto& Facts = Result.Facts;
        constexpr static bool        Ok    = Result.Diagnostic.Ok;

    };

}

#endif //MANTARAY_MODEL_H
