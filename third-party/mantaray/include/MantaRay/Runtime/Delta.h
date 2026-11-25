//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_RUNTIME_DELTA_H
#define MANTARAY_RUNTIME_DELTA_H

#include <tuple>
#include <type_traits>

#include "../Common.h"
#include "../Model.h"
#include "../FeatureSet/Changes.h"
#include "../FeatureSet/FeatureSet.h"

namespace MantaRay
{

    namespace Detail
    {

        template<typename F>
        consteval auto RecordingOf()
        {
            if constexpr (DerivedFeatureSet<F>) return std::tuple<Changes<F>> {};
            else                                return std::tuple<>           {};
        }

        template<typename... All>
        consteval auto RecordingsOf(List<All...>) { return std::tuple_cat(RecordingOf<All>()...); }

        template<typename... All>
        consteval bool AnyDerived(List<All...>) { return (DerivedFeatureSet<All> || ...); }

        template<typename F, typename... All>
        consteval u32 MarkOf(List<All...>)
        {
            constexpr Array<bool, sizeof...(All)> Same { std::is_same_v<F, All>... };

            u32 index = 0;

            while (!Same[index]) index++;

            return u32 { 1 } << index;
        }

    }

    template<auto D>
    struct Delta
    {

        using Bindings = Detail::Pipeline<D>::Bindings;

        PieceDelta Pieces {};

        NO_UNIQUE_ADDRESS           decltype(Detail::RecordingsOf(Bindings {}))                 Recordings {};
        NO_UNIQUE_ADDRESS std::conditional_t<Detail::AnyDerived  (Bindings {}), u32, Absent<0>> Fills      {};

        template<DerivedFeatureSet F>
        [[nodiscard]]
        constexpr Changes<F>& Recorded() noexcept
        {
            Fills |= Detail::MarkOf<F>(Bindings {});

            return std::get<Changes<F>>(Recordings);
        }

        template<DerivedFeatureSet F>
        [[nodiscard]]
        constexpr const Changes<F>& Recorded() const noexcept { return std::get<Changes<F>>(Recordings); }

        template<DerivedFeatureSet F>
        [[nodiscard]]
        constexpr bool Filled() const noexcept { return (Fills & Detail::MarkOf<F>(Bindings {})) != 0; }

    };

}

#endif //MANTARAY_RUNTIME_DELTA_H
