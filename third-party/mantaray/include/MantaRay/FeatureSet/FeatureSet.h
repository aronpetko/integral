//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_FEATURESET_FEATURESET_H
#define MANTARAY_FEATURESET_FEATURESET_H

#include <concepts>
#include <source_location>
#include <type_traits>

#include "../Common.h"
#include "../Graph/Value.h"
#include "../IR/GraphIR.h"

namespace MantaRay
{

    enum class Piece : u08 { Pawn, Knight, Bishop, Rook, Queen, King };

    constexpr inline u08 White = 0;
    constexpr inline u08 Black = 1;

    struct NoTrigger
    {

        constexpr static u32 KeyCount = 1;

        constexpr static u32 KeyOf(const u08, const u08) noexcept { return 0; }

        template<typename Board>
        constexpr static u32 Key(const u08, const Board&) noexcept { return 0; }

    };

    struct MirrorTrigger
    {

        constexpr static u32 KeyCount = 2;

        constexpr static u32 KeyOf(const u08, const u08 king) noexcept { return (king & 7) >= 4; }

        template<typename Board>
        constexpr static u32 Key(const u08 perspective, const Board& board) noexcept
        {
            return KeyOf(perspective, board.King(perspective));
        }

    };

    template<typename F>
    concept FeatureSet = requires {
        { F::InputSize  } -> std::convertible_to<u32>;
        { F::MaxActive  } -> std::convertible_to<u32>;
        { F::MaxChanges } -> std::convertible_to<u32>;

        { F::Shared     } -> std::convertible_to<bool>;
        { F::Cached     } -> std::convertible_to<bool>;

        { F::Trigger::KeyCount } -> std::convertible_to<u32>;
    };

    class PieceDelta;

    template<typename F>
    class Changes;

    template<typename F>
    concept DerivedFeatureSet = FeatureSet<F> && F::Derived && requires (
        const PieceDelta&         delta      ,
        const typename F::Record& after      ,
              Changes<F>&         out        ,
        const typename F::Change  change     ,
        const u08                 perspective,
        const u32                 key
    ) {
        { F::Changes(delta, after, out) };
        { F::Index(perspective, key, change) } -> std::same_as<u32>;
        { F::NoRow                           } -> std::convertible_to<u32>;
    };

    template<typename F, typename C>
    concept LeanIndexed = requires (const u08 perspective, const u32 key, const C& change) {
        { F::Index    (perspective, key, change) } -> std::same_as<u32>;
        { F::IndexLean(perspective, key, change) } -> std::same_as<u32>;
    };

    template<typename F>
    concept CodeIndexed = requires (const u08 perspective, const u32 key, const u16 code) {
        { F::IndexCode(perspective, key, code) } -> std::same_as<u32>;
    };

    template<typename S>
    concept Selector = requires {
        { S::Count } -> std::convertible_to<u32>;
    } && !FeatureSet<S>;

    template<FeatureSet F>
    struct Perspectives
    {

        Value<F> Stm;
        Value<F> Ntm;

    };

    namespace Detail
    {

        template<FeatureSet F>
        constexpr Value<F> InputOf(const IR::Perspective perspective, const std::source_location& site)
        {
            IR::Node spec {};

            spec.Operation   = IR::Op::Input;
            spec.Perspective = perspective;
            spec.Size        = F::InputSize;

            const Placed placed = Located(spec, site);

            return Make<Value<F>>(placed, {}, {}, {}, &Tag<F>);
        }

        template<typename F, typename... All>
        consteval u16 TriggerOf()
        {
            if constexpr (!FeatureSet<F>) return 0;
            else {
                constexpr Array<bool, sizeof...(All)> Same {
                    [] {
                        if constexpr (FeatureSet<All>)
                            return std::is_same_v<typename All::Trigger, typename F::Trigger>;

                        return false;
                    }()...
                };

                u16 index = 0;

                while (!Same[index]) index++;

                return index;
            }
        }

        template<typename F>
        consteval bool IncrementalOf()
        {
            if constexpr (requires { F::Incremental; }) return F::Incremental;

            return true;
        }

        template<typename F, typename... All>
        consteval IR::Binding BindingOf()
        {
            if constexpr (FeatureSet<F>)
                return {
                    .Kind        = IR::Kind::FeatureSet,
                    .Shared      = F::Shared,
                    .Cached      = F::Cached,
                    .Incremental = IncrementalOf<F>(),
                    .Trigger     = TriggerOf<F, All...>(),
                    .InputSize   = F::InputSize,
                    .MaxActive   = F::MaxActive,
                    .MaxChanges  = F::MaxChanges,
                    .Count       = F::Trigger::KeyCount
                };
            else
                return { .Kind = IR::Kind::Selector, .Count = F::Count };
        }

    }

    template<FeatureSet F>
    constexpr auto Input(const std::source_location& site = std::source_location::current())
    {
        if constexpr (F::Shared) return Detail::InputOf<F>(IR::Perspective::Shared, site);
        else
            return Perspectives<F> {
                .Stm = Detail::InputOf<F>(IR::Perspective::Stm, site),
                .Ntm = Detail::InputOf<F>(IR::Perspective::Ntm, site)
            };
    }

}

#endif //MANTARAY_FEATURESET_FEATURESET_H
