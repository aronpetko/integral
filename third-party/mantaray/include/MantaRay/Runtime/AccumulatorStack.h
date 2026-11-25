//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_RUNTIME_ACCUMULATORSTACK_H
#define MANTARAY_RUNTIME_ACCUMULATORSTACK_H

#include <algorithm>
#include <bit>
#include <cassert>
#include <concepts>
#include <cstring>
#include <span>
#include <tuple>
#include <type_traits>
#include <utility>

#include "AccumulatorCache.h"
#include "Delta.h"
#include "Network.h"
#include "../Common.h"
#include "../Backend/Backend.h"
#include "../FeatureSet/Attacks.h"
#include "../FeatureSet/FeatureSet.h"
#include "../FeatureSet/Geometry.h"
#include "../IR/GraphIR.h"
#include "../Lowering/Lowering.h"

namespace MantaRay
{

    enum class UpdatePolicy : u08 { Eager, Lazy };

    namespace Detail
    {

        template<typename Board>
        concept BoardView = requires (const Board& board) {
            { board.SideToMove() } -> std::convertible_to<u08>;
        };

        template<typename M, u16 Selected>
        consteval bool CountedBy()
        {
            if constexpr (Selected == 0) return false;
            else return requires { M::template Binding<Selected - 1>::OfCount(u08 {}); };
        }

        template<s00 S>
        struct Units
        {

            u16 Count = 0;

            Array<u16, S> Lead {};
            Array<u16, S> Of   {};

        };

        template<s00 S, s00 N>
        consteval Units<S> UnitsOf(const Lowering::Program<N>& program)
        {
            Units<S> units {};

            for (s00 s = 0; s < S; s++) {
                const u16 twin = program.Slots[s].Twin;

                if (twin != 0 && twin - s00 { 1 } < s) {
                    units.Of[s] = units.Of[twin - 1];

                    continue;
                }

                units.Of  [s          ] = units.Count;
                units.Lead[units.Count] = static_cast<u16>(s);

                units.Count++;
            }

            return units;
        }

        template<typename M, u16... B>
        consteval bool AnyCounted(const std::integer_sequence<u16, B...>) { return (CountedBy<M, B + 1>() || ...); }

        template<typename F>
        consteval u32 TypicalOf()
        {
            if constexpr (requires { F::TypicalChanges; }) return F::TypicalChanges;
            else                                            return F::MaxChanges;
        }

        template<typename F>
        consteval bool EagerOf()
        {
            if constexpr (requires { F::Eager; }) return F::Eager;
            else                                   return false;
        }

        template<typename F>
        consteval u32 RoomOf()
        {
            if (DerivedFeatureSet<F>) return TypicalOf<F>();

            return 2;
        }

        template<typename M, typename W>
        consteval bool Streamed(const u16 sparse, const u64 bytes)
        {
            const IR::Tensor& spec = M::Graph.Tensors[M::Graph.Nodes[sparse].Tensor - 1];

            return u64 { spec.Rows } * spec.Columns * sizeof(W) >= bytes;
        }

        enum class Phase : u08 { Deferred, Stored, Overflowed };

        struct Extent
        {

            u16   Removed = 0;
            u16   Added   = 0;
            Phase State   = Phase::Deferred;

        };

        template<typename F, s00 Capacity>
        struct Store
        {

            constexpr static u32 Room    = TypicalOf<F>();
            constexpr static u32 Typical = Room + Slack;

            static_assert(Room > 0 && Room <= 0xFFFF, "a family's typical change count fits a u16");

            Array<typename F::Record, Capacity          > Records {};
            Array<typename F::Change, Capacity * Typical> Arena   {};
            Array<Extent            , Capacity          > Extents {};
            Array<bool              , Capacity          > Linked  {};

        };

        template<u32 N, typename T>
        [[clang::always_inline]]
        void Spread(const std::span<const T> from, T* to) noexcept
        {
            static_assert(std::is_trivially_copyable_v<T>, "a block of changes is copied as bytes");

            UNROLL(full)
            for (u32 block = 0; block < (N + Slack - 1) / Slack; block++) {
                if (block * Slack >= from.size()) break;

                std::memcpy(to + block * Slack, from.data() + block * Slack, Slack * sizeof(T));
            }
        }

        template<typename F, s00 Capacity>
        using StoreOf = std::conditional_t<DerivedFeatureSet<F>, Store<F, Capacity>, Absent<3>>;

        struct Origin
        {

            u16 Slot    = 0;
            u16 Term    = 0;
            u16 Binding = 0;

        };

        template<typename M, s00 S, s00 Groups>
        consteval Array<Origin, Groups, IR::MaxFeatureSet> OriginsOf(
            const Array<Leaves, S     >& split  ,
            const Array<Leaves, Groups>& grouped
        )
        {
            Array<Origin, Groups, IR::MaxFeatureSet> origins {};

            for (s00 c = 0; c < Groups; c++)
            for (s00 j = 0; j < grouped[c].Terms; j++) {
                const u16 node    = grouped[c].Sparse[j];
                const u16 binding = static_cast<u16>(M::Graph.Nodes[M::Graph.Nodes[node].Inputs[0]].Binding - 1);

                for (s00 s = 0; s < S; s++)
                for (s00 t = 0; t < split[s].Terms; t++)
                    if (split[s].Sparse[t] == node)
                        origins[c][j] = {
                            .Slot    = static_cast<u16>(s),
                            .Term    = static_cast<u16>(t),
                            .Binding = binding
                        };
            }

            return origins;
        }

        template<s00 N>
        consteval u16 HomeOf(const Lowering::Program<N>& split, const Lowering::Slot& group)
        {
            u16 home = split.SlotCount;

            for (s00 s = 0; s < split.SlotCount; s++) {
                const Lowering::Slot& slot = split.Slots[s];

                if (slot.Root != group.Root || (slot.FeatureSets & group.FeatureSets) == 0) continue;

                if (home == split.SlotCount || slot.Bias) home = static_cast<u16>(s);
            }

            return home;
        }

        constexpr inline u16 Unkeyed = 0xFFFF;

        struct Classes
        {

            u16 Count = 0;

            Array<u16, IR::MaxFeatureSet> Leader {};
            Array<u16, IR::MaxFeatureSet> Of     {};

        };

        template<typename M>
        consteval Classes ClassesOf(
            const Array<Origin, IR::MaxFeatureSet>& origins    ,
            const u16                               terms      ,
            const bool                              incremental
        )
        {
            Classes classes {};

            classes.Of.fill(Unkeyed);

            const auto trigger = [&](const u16 term) { return M::Graph.Bindings[origins[term].Binding].Trigger; };

            for (s00 j = 0; j < terms && incremental; j++) {
                if (M::Graph.Bindings[origins[j].Binding].Count == 1) continue;

                u16 k = 0;

                while (k < classes.Count && trigger(classes.Leader[k]) != trigger(j)) k++;

                if (k == classes.Count) classes.Leader[classes.Count++] = static_cast<u16>(j);

                classes.Of[j] = k;
            }

            return classes;
        }

        struct Boardless {};

    }

    template<
        auto                    D                            ,
        s00                     Capacity                     ,
        UpdatePolicy            Policy  = UpdatePolicy::Lazy ,
        Accumulators            Grouped = Accumulators::Split,
        const Lowering::Target& T       = Lowering::Native
    >
    class alignas(Alignment) AccumulatorStack
    {

        using Net = Network<D, T>;
        using M   = Net::Model;
        using ISA = Backend::ISAOf<T>;

        constexpr static Lowering::Stage Stage = Net::Program.Stages[0];

        constexpr static u16 Stm      = Detail::SlotOf(Net::Program, Stage.Slots, IR::Dependence::Stm);
        constexpr static u16 Ntm      = Detail::SlotOf(Net::Program, Stage.Slots, IR::Dependence::Ntm);
        constexpr static u16 Selected = M::Facts[Stage.Node].Selector;

        using F = M::template Binding<std::countr_zero(Net::Program.Slots[Stm].FeatureSets)>;
        using S = Net::template SlotType<Stm>;
        using W = std::remove_const_t<std::remove_pointer_t<decltype(std::declval<const Net&>().FeatureRow(0, 0))>>;

        template<s00 R, s00 A>
        using Transition = Detail::Update<ISA, S, W, R, A>;

        constexpr static u32  Width    = Stage.Width;
        constexpr static u08  Sets     = Net::Program.Slots[Ntm].Twin == Stm + 1 ? 1 : 2;
        constexpr static bool Lazy     = Policy == UpdatePolicy::Lazy;
        constexpr static bool Fused    = Lazy && Net::Fusable;
        constexpr static bool Counted  = Stage.Buckets > 1 && Detail::CountedBy<M, Selected>();
        constexpr static bool Keyed    = F::Trigger::KeyCount > 1;
        constexpr static bool Cached   = F::Cached;
        constexpr static u08  Computed = 0x3;
        constexpr static bool LeanStep = ISA::Bytes >= 64;
        constexpr static bool LeanFuse = LeanStep || ISA::Bytes <= 32;

        constexpr static u32 UnrollBudget = Backend::Kernel::Detail::UnrollBudget;
        constexpr static u32 RowVectors   = Width * sizeof(S) / ISA::Bytes;
        constexpr static s00 HotAlign     = Lazy && (ISA::Bytes <= 16 || RowVectors >= UnrollBudget) ? 64 : 1;
        constexpr static u32 StepBudget   = Lazy ? UnrollBudget - 1 : UnrollBudget;

        template<s00 R, s00 A>
        constexpr static u32 Budget = Lazy && R == 1 && A == 1 ? UnrollBudget : StepBudget;

        constexpr static bool CodeStep = !Lazy && ISA::Bytes >= 64 && CodeIndexed<F>;

        template<s00 R, s00 A>
        constexpr static u08 Shape = static_cast<u08>(R * 3 + A);

        static_assert(Capacity > 0, "the stack needs room for the root");

        static_assert(
            Net::Program.StageCount == 1 && Stage.Kind == Lowering::Kind::AccumulatorDot,
            "the stack runs single AccumulatorDot programs"
        );
        static_assert(
            std::popcount(Stage.Slots) == 2 && std::has_single_bit(Net::Program.Slots[Stm].FeatureSets) &&
            Net::Program.Slots[Ntm].FeatureSets == Net::Program.Slots[Stm].FeatureSets,
            "the stack covers one slot per side and one family per slot"
        );
        static_assert(
            !Net::NeedsBoard && Net::Program.Slots[Stm].Incremental,
            "the stack covers incremental piece-code slots whose triggers have KeyOf"
        );
        static_assert(
            Grouped == Accumulators::Split || Lowering::Combine(Net::Program) == Net::Program,
            "combined accumulators need a program whose slots combine"
        );
        static_assert(
            LeanFuse,
            "no lowering has a vector wider than 32 bytes and narrower than 64, so the fused (2,2) step is always lean"
        );
        static_assert(
            !Lazy || (Budget<1, 1> == UnrollBudget && Budget<2, 1> == StepBudget),
            "a lazy stack unrolls its (1,1) step to the full budget and every other step to one vector less"
        );

        using CountArray = std::conditional_t<Counted, Array<u08, Capacity>                       , Absent<0>>;
        using KeyArray   = std::conditional_t<Keyed  , Array<u32, Capacity, 2>                    , Absent<1>>;
        using Table      = std::conditional_t<Cached , AccumulatorCache<F, S, W, Width, Sets, ISA>, Absent<2>>;

        alignas(Alignment) Array<S, Capacity, 2, Sets, Width> Accumulated {};

        Array<PieceDelta, Capacity> Deltas {};
        Array<u08       , Capacity> Flags  {};

        NO_UNIQUE_ADDRESS CountArray PieceCounts {};
        NO_UNIQUE_ADDRESS KeyArray   Keys        {};
        NO_UNIQUE_ADDRESS Table      Cache       {};

        const Net* Model;

        s00 Top = 0;

        [[clang::always_inline]]
        static auto DispatchShape(const PieceDelta& delta) noexcept
        {
            if constexpr (Lazy && ISA::Bytes <= 32) return delta.ShapeIndex();
            else return delta.Shape();
        }

        [[clang::always_inline]]
              Array<S, Width>& At(const s00 ply, const u08 perspective, const u08 set)       noexcept
        { return Accumulated[ply][perspective][set]; }
        [[clang::always_inline]]
        const Array<S, Width>& At(const s00 ply, const u08 perspective, const u08 set) const noexcept
        { return Accumulated[ply][perspective][set]; }

        [[clang::always_inline]]
        constexpr static u08 Role(const u08 perspective, const u08 stm) noexcept
        {
            if (Sets == 1) return 0;

            return static_cast<u08>(perspective ^ stm);
        }

        [[clang::always_inline]]
        u32 Key(const s00 ply, const u08 perspective) const noexcept
        {
            if constexpr (Keyed) return Keys[ply][perspective];

            return 0;
        }

        template<bool Opaque = false, bool Lean = false>
        [[clang::always_inline]]
        const W* Row(const u08 set, const u08 perspective, const u32 key, const PieceChange& change) const noexcept
        {
            if constexpr (Opaque && Lean && LeanIndexed<F, PieceChange>) {
                u64 index = F::IndexLean(perspective, key, change);

                asm("" : "+r"(index));

                [[assume(index >> 32 == 0)]];

                return Model->FeatureRow(set, static_cast<u32>(index));
            }

            u32 index = F::Index(perspective, key, change);

            if (Opaque) asm("" : "+r"(index));

            return Model->FeatureRow(set, index);
        }

        [[clang::always_inline]]
        const W* RowCode(const u08 set, const u08 perspective, const u32 key, const u16 code) const noexcept
        {
            u64 index = F::IndexCode(perspective, key, code);

            asm("" : "+r"(index));

            [[assume(index >> 32 == 0)]];

            return Model->FeatureRow(set, static_cast<u32>(index));
        }

        template<s00 R, s00 A, bool Lean = false>
        [[clang::always_inline]]
        Transition<R, A> Transitions(
            const s00         ply        ,
            const PieceDelta& delta      ,
            const u08         perspective,
            const u08         set
        ) noexcept
        {
            const u32 key = Key(ply, perspective);

            S* child = At(ply, perspective, set).data();

            if (!Lazy && RowVectors > UnrollBudget) asm("" : "+r"(child));

            Transition<R, A> transition {
                .Child    = child,
                .Parent   = At(ply - 1, perspective, set).data(),
                .Removed  = {},
                .Inserted = {}
            };

            if constexpr (CodeStep) {
                for (s00 i = 0; i < R; i++)
                    transition.Removed [i] = RowCode(set, perspective, key, delta.RemovedCode (i));
                for (s00 i = 0; i < A; i++)
                    transition.Inserted[i] = RowCode(set, perspective, key, delta.InsertedCode(i));
            } else {
                for (s00 i = 0; i < R; i++)
                    transition.Removed [i] = Row<true, Lean>(set, perspective, key, delta.Removed (i));
                for (s00 i = 0; i < A; i++)
                    transition.Inserted[i] = Row<true, Lean>(set, perspective, key, delta.Inserted(i));
            }

            return transition;
        }

        template<s00 R, s00 A, bool Lean = false>
        [[clang::always_inline]]
        void Step(const s00 ply, const PieceDelta& delta) noexcept
        {
            UNROLL(full)
            for (u08 set = 0; set < Sets; set++) {
                const Transition<R, A> white = Transitions<R, A, Lean>(ply, delta, White, set);
                const Transition<R, A> black = Transitions<R, A, Lean>(ply, delta, Black, set);

                Backend::Kernel::Advance<Width, Budget<R, A>>(white);
                Backend::Kernel::Advance<Width, Budget<R, A>>(black);
            }
        }

        template<s00 R, s00 A>
        [[clang::noinline]]
        [[gnu::aligned(HotAlign)]]
        void StepRare(const s00 ply, const PieceDelta& delta) noexcept { Step<R, A>(ply, delta); }

        template<s00 R, s00 A>
        [[clang::noinline]]
        static void StepAt(AccumulatorStack& stack, const s00 ply, const PieceDelta& delta) noexcept
        { stack.template Step<R, A>(ply, delta); }

        using StepFunction = void (*)(AccumulatorStack&, s00, const PieceDelta&) noexcept;

        ALIGN_ARRAY constexpr static Array<StepFunction, Shape<2, 2> + 1> StepTable {
            StepAt<0, 0>, StepAt<0, 1>, StepAt<0, 2>,
            StepAt<1, 0>, StepAt<1, 1>, StepAt<1, 2>,
            StepAt<2, 0>, StepAt<2, 1>, StepAt<2, 2>
        };

        static_assert(
            []<s00... I>(const std::index_sequence<I...>) {
                return ((StepTable[Shape<I / 3, I % 3>] == StepAt<I / 3, I % 3>) && ...);
            }(std::make_index_sequence<std::size(StepTable)> {}),
            "StepTable holds StepAt<R, A> at index Shape<R, A>"
        );

        [[clang::noinline]]
        [[gnu::aligned(HotAlign)]]
        void AdvanceRare(const s00 ply, const PieceDelta& delta) noexcept
        {
            switch (delta.Shape()) {
                case Shape<0, 0>: StepRare<0, 0>(ply, delta); break;
                case Shape<0, 1>: StepRare<0, 1>(ply, delta); break;
                case Shape<1, 0>: StepRare<1, 0>(ply, delta); break;
                case Shape<0, 2>: StepRare<0, 2>(ply, delta); break;
                case Shape<1, 2>: StepRare<1, 2>(ply, delta); break;
                default         : StepRare<2, 0>(ply, delta); break;
            }
        }

        [[clang::always_inline]]
        void Advance(const s00 ply, const PieceDelta& delta) noexcept
        {
            switch (DispatchShape(delta)) {
                case Shape<1, 1>: Step<1, 1, LeanStep>(ply, delta); break;
                case Shape<2, 1>: Step<2, 1, LeanStep>(ply, delta); break;
                [[unlikely]]
                case Shape<2, 2>: Step<2, 2, LeanStep>(ply, delta); break;
                default         : AdvanceRare(ply, delta); break;
            }
        }

        [[clang::noinline]]
        void AdvanceRarePush(const s00 ply, const PieceDelta& delta) noexcept
        {
            switch (delta.ShapeIndex()) {
                case Shape<0, 0>: Step<0, 0>(ply, delta); break;
                case Shape<0, 1>: Step<0, 1>(ply, delta); break;
                case Shape<0, 2>: Step<0, 2>(ply, delta); break;
                case Shape<1, 0>: Step<1, 0>(ply, delta); break;
                case Shape<1, 2>: Step<1, 2>(ply, delta); break;
                default         : Step<2, 0>(ply, delta); break;
            }
        }

        [[clang::always_inline]]
        void AdvancePush(const s00 ply, const PieceDelta& delta) noexcept
        {
            const u32 shape = delta.ShapeIndex();

            if (CodeStep) {
                if      (shape == Shape<2, 2>) Step<2, 2>(ply, delta);
                else if (shape == Shape<2, 1>) Step<2, 1>(ply, delta);
                else if (shape != Shape<1, 1>) AdvanceRarePush(ply, delta);
                else                           Step<1, 1>(ply, delta);

                return;
            }

            switch (shape) {
                case Shape<1, 1>: Step<1, 1>(ply, delta); break;
                case Shape<2, 1>: Step<2, 1>(ply, delta); break;
                case Shape<2, 2>: Step<2, 2>(ply, delta); break;
                default         : StepTable[shape](*this, ply, delta); break;
            }
        }

        template<s00 R, s00 A>
        [[clang::always_inline]]
        void StepOne(const s00 ply, const PieceDelta& delta, const u08 perspective) noexcept
        {
            UNROLL(full)
            for (u08 set = 0; set < Sets; set++)
                Backend::Kernel::Advance<Width, StepBudget>(Transitions<R, A>(ply, delta, perspective, set));
        }

        [[clang::noinline]]
        void AdvanceOne(const s00 ply, const PieceDelta& delta, const u08 perspectives) noexcept requires (Keyed)
        {
            const u08 perspective = perspectives >> 1;

            switch (delta.Shape()) {
                case Shape<0, 0>: StepOne<0, 0>(ply, delta, perspective); break;
                case Shape<0, 1>: StepOne<0, 1>(ply, delta, perspective); break;
                case Shape<0, 2>: StepOne<0, 2>(ply, delta, perspective); break;
                case Shape<1, 0>: StepOne<1, 0>(ply, delta, perspective); break;
                case Shape<1, 1>: StepOne<1, 1>(ply, delta, perspective); break;
                case Shape<1, 2>: StepOne<1, 2>(ply, delta, perspective); break;
                case Shape<2, 0>: StepOne<2, 0>(ply, delta, perspective); break;
                case Shape<2, 1>: StepOne<2, 1>(ply, delta, perspective); break;
                default         : StepOne<2, 2>(ply, delta, perspective); break;
            }
        }

        [[clang::always_inline]]
        void Advance(const s00 ply, const PieceDelta& delta, const u08 perspectives) noexcept requires (Keyed)
        {
            if (perspectives == Computed) Advance   (ply, delta              );
            else                          AdvanceOne(ply, delta, perspectives);
        }

        [[clang::always_inline]]
        void Track(const s00 ply, const PieceDelta& delta) noexcept
        {
            if constexpr (Counted) {
                const u08 parent = PieceCounts[ply - 1];

                PieceCounts[ply] = static_cast<u08>(parent + delta.InsertedCount() - delta.RemovedCount());
            }

            if constexpr (Keyed) {
                Keys[ply] = Keys[ply - 1];

                UNROLL(full)
                for (s00 i = 0; i < 2; i++) {
                    if (i == delta.InsertedCount()) break;

                    const PieceChange change = delta.Inserted(i);

                    if (change.Type == Piece::King)
                        Keys[ply][change.Side] = F::Trigger::KeyOf(change.Side, change.Square);
                }
            }
        }

        [[clang::always_inline]]
        bool Ready(const s00 ply) const noexcept
        {
            if constexpr (Keyed) return Flags[ply - 1] == Computed && Keys[ply] == Keys[ply - 1];

            return Flags[ply - 1] == Computed;
        }

        [[clang::always_inline]]
        u08 Unchanged(const s00 ply) const noexcept requires (Keyed)
        {
            return (Keys[ply][0] == Keys[ply - 1][0]) | (Keys[ply][1] == Keys[ply - 1][1]) << 1;
        }

        template<typename Board>
        [[clang::always_inline]]
        void Rebuild(const s00 ply, const u08 perspectives, const Board& board) noexcept
        {
            Array<const W*, 2, Sets, F::MaxActive> rows;

            const Array<u32, 2> keys { Key(ply, White), Key(ply, Black) };

            u32 count = 0;

            for (u08 side  = 0; side  < 2; side++ )
            for (u08 piece = 0; piece < 6; piece++) {
                const Piece type = static_cast<Piece>(piece);

                for (u64 bits = board.Pieces(side, type); bits != 0; count++) {
                    assert(count < F::MaxActive);

                    const PieceChange change { .Type = type, .Side = side, .Square = Attacks::PopLowest(bits) };

                    for (u08 perspective = 0; perspective < 2   ; perspective++)
                    for (u08 set         = 0; set         < Sets; set++        )
                        rows[perspective][set][count % F::MaxActive] = Row(set, perspective, keys[perspective], change);
                }
            }

            count = std::min<u32>(count, F::MaxActive);

            for (u08 perspective = 0; perspective < 2   ; perspective++)
            for (u08 set         = 0; set         < Sets; set++        ) {
                if (!(perspectives >> perspective & 1)) continue;

                Backend::Kernel::Refresh<ISA, Width>(
                    Model->FeatureBias(set),
                    std::span<const W* const>(rows[perspective][set].data(), count),
                    At(ply, perspective, set).data()
                );
            }
        }

        template<typename Board>
        [[clang::always_inline]]
        void Refresh(const s00 ply, const u08 perspectives, const Board& board) noexcept
        {
            assert(!(perspectives & 1) || Key(ply, White) == F::Trigger::Key(White, board));
            assert(!(perspectives & 2) || Key(ply, Black) == F::Trigger::Key(Black, board));

            if constexpr (Cached) {
                for (u08 perspective = 0; perspective < 2   ; perspective++)
                for (u08 set         = 0; set         < Sets; set++        ) {
                    if (!(perspectives >> perspective & 1)) continue;

                    Cache.Refresh(*Model, set, perspective, Key(ply, perspective), board, At(ply, perspective, set));
                }
            } else Rebuild(ply, perspectives, board);
        }

        [[clang::noinline]]
        [[gnu::aligned(HotAlign)]]
        void CatchUp() noexcept
        {
            const s00 top = Top;

            s00 ply = top - 1;

            while (Flags[ply - 1] != Computed) ply--;

            for (; ply < top; ply++) {
                Advance(ply, Deltas[ply]);

                Flags[ply] = Computed;
            }
        }

        [[clang::noinline]]
        void Retreat(const s00 ply, const u08 perspective) noexcept requires (Keyed)
        {
            const PieceDelta& delta = Deltas[ply];

            const u32 key        = Key(ply, perspective);
            const u08 removals   = delta.RemovedCount ();
            const u08 insertions = delta.InsertedCount();

            for (u08 set = 0; set < Sets; set++) {
                Array<const W*, PieceDelta::MaxRemoved > removed ;
                Array<const W*, PieceDelta::MaxInserted> inserted;

                for (s00 i = 0; i < removals  ; i++) removed [i] = Row(set, perspective, key, delta.Removed (i));
                for (s00 i = 0; i < insertions; i++) inserted[i] = Row(set, perspective, key, delta.Inserted(i));

                Backend::Kernel::Update<ISA, Width, S, W>(
                    At(ply, perspective, set).data(),
                    std::span<const W* const>(inserted).first(insertions),
                    std::span<const W* const>(removed ).first(removals  ),
                    At(ply - 1, perspective, set).data()
                );
            }
        }

        template<typename Board>
        [[clang::noinline]]
        [[gnu::aligned(HotAlign)]]
        void CatchUp(const Board& board) noexcept requires (Keyed)
        {
            const s00 top = Top;

            Array<s00, 2> base;

            for (u08 perspective = 0; perspective < 2; perspective++) {
                s00 ply = top;

                while (!(Flags[ply] >> perspective & 1) && Keys[ply][perspective] == Keys[ply - 1][perspective]) ply--;

                if (Flags[ply] >> perspective & 1) base[perspective] = ply;
                else {
                    Refresh(top, static_cast<u08>(1 << perspective), board);

                    Flags[top] |= 1 << perspective;
                    base [perspective] = top;

                    for (s00 child = top; child > ply; child--) {
                        Retreat(child, perspective);

                        Flags[child - 1] |= 1 << perspective;
                    }
                }
            }

            for (s00 ply = std::min(base[0], base[1]) + 1; ply <= top; ply++) {
                const u08 perspectives = (base[0] < ply) | (base[1] < ply) << 1;

                Advance(ply, Deltas[ply], perspectives);

                Flags[ply] |= perspectives;
            }
        }

        template<typename Board>
        [[clang::noinline]]
        void RefreshTop(const Board& board) noexcept requires (Keyed)
        {
            const s00 top = Top;

            Refresh(top, static_cast<u08>(Flags[top] ^ Computed), board);

            Flags[top] = Computed;
        }

        template<typename Board>
        [[clang::always_inline]]
        void Settle(const Board& board) noexcept
        {
            if constexpr (Keyed) CatchUp(board);
            else                 CatchUp();
        }

        [[clang::always_inline]]
        void Compute() noexcept
        {
            if (Lazy) {
                const s00 top = Top;

                if (Flags[top] == Computed) return;

                if (!Ready(top)) CatchUp();

                Advance(top, Deltas[top]);

                Flags[top] = Computed;
            }
        }

        template<typename Board>
        [[clang::always_inline]]
        void Compute(const Board& board) noexcept
        {
            if constexpr (!Keyed) Compute();
            else {
                const s00 top = Top;

                if (Flags[top] == Computed) return;

                if (Lazy) {
                    if (Ready(top)) {
                        Advance(top, Deltas[top]);

                        Flags[top] = Computed;
                    } else CatchUp(board);
                } else RefreshTop(board);
            }
        }

        [[clang::always_inline]]
        s00 Bucket() const noexcept
        {
            if constexpr (Counted) return M::template Binding<Selected - 1>::OfCount(PieceCounts[Top]);

            return 0;
        }

        [[clang::always_inline]]
        i32 Forward(const u08 stm, const s00 bucket) const noexcept
        {
            assert(stm < 2);

            const Detail::Read<ISA, S> own   { .Values = At(Top, stm    , 0       ).data() };
            const Detail::Read<ISA, S> other { .Values = At(Top, stm ^ 1, Sets - 1).data() };

            return Model->Forward(own, other, bucket);
        }

        template<s00 R, s00 A, bool Lean = false>
        [[clang::always_inline]]
        i32 Fuse(const s00 ply, const PieceDelta& delta, const u08 stm, const s00 bucket) noexcept
        {
            assert(ply == Top && stm < 2);

            const Transition<R, A> white = Transitions<R, A, Lean>(ply, delta, White, Role(White, stm));
            const Transition<R, A> black = Transitions<R, A, Lean>(ply, delta, Black, Role(Black, stm));

            Flags[ply] = Computed;

            const i32 value = Model->Forward(white, black, stm, bucket);

            if (Sets == 2) {
                Backend::Kernel::Advance<Width>(Transitions<R, A, Lean>(ply, delta, White, Role(White, stm) ^ 1));
                Backend::Kernel::Advance<Width>(Transitions<R, A, Lean>(ply, delta, Black, Role(Black, stm) ^ 1));
            }

            return value;
        }

        template<typename Catch>
        [[clang::always_inline]]
        i32 EvaluateFused(const u08 stm, const s00 bucket, const Catch& catchUp) noexcept
        {
            const s00 top = Top;

            if (Flags[top] != Computed) [[likely]] {
                if (!Ready(top)) [[unlikely]] {
                    catchUp();

                    if (Keyed) return Forward(stm, bucket);
                }

                const PieceDelta& delta = Deltas[top];

                switch (DispatchShape(delta)) {
                    case Shape<1, 1>: return Fuse<1, 1, false   >(top, delta, stm, bucket);
                    case Shape<2, 1>: return Fuse<2, 1, false   >(top, delta, stm, bucket);
                    case Shape<2, 2>: return Fuse<2, 2, LeanFuse>(top, delta, stm, bucket);
                    default         :                 AdvanceRare(top, delta             ); break;
                }

                Flags[top] = Computed;
            }

            return Forward(stm, bucket);
        }

        public:
        using N = Net;

        explicit AccumulatorStack(const N& network) noexcept : Model(&network)
        {
            ClearCache();

            for (u08 perspective = 0; perspective < 2   ; perspective++)
            for (u08 set         = 0; set         < Sets; set++        )
                Backend::Kernel::Copy<ISA, Width>(Model->FeatureBias(set), At(0, perspective, set).data());

            Flags[0] = Computed;
        }

        AccumulatorStack(const N&&) = delete;

        template<typename Board>
        void Reset(const Board& board) noexcept
        {
            if constexpr (Keyed) {
                Keys[0][White] = F::Trigger::Key(White, board);
                Keys[0][Black] = F::Trigger::Key(Black, board);
            }

            Refresh(0, Computed, board);

            if constexpr (Counted) {
                s00 pieces = 0;

                for (u08 side  = 0; side  < 2; side++ )
                for (u08 piece = 0; piece < 6; piece++)
                    pieces += std::popcount(board.Pieces(side, static_cast<Piece>(piece)));

                PieceCounts[0] = static_cast<u08>(pieces);
            }

            Top      = 0;
            Flags[0] = Computed;
        }

        void Push(const PieceDelta& delta) noexcept requires (!N::NeedsBoard)
        {
            assert(Top < Capacity - 1);

            const s00 top = ++Top;

            Track(top, delta);

            if (Lazy) {
                Deltas[top] = delta;
                Flags [top] = 0;
            } else if constexpr (Keyed) {
                const u08 ready = Flags[top - 1] & Unchanged(top);

                Flags[top] = ready;

                if      (ready == Computed) AdvancePush(top, delta       );
                else if (ready != 0       ) AdvanceOne (top, delta, ready);
            } else AdvancePush(top, delta);
        }

        template<typename Board>
        void Push(const PieceDelta& delta, const Board&) noexcept { Push(delta); }

        template<typename Board>
        void Push(const Delta<D>& delta, const Board& after) noexcept { Push(delta.Pieces, after); }

        [[clang::always_inline]]
        void Pop() noexcept
        {
            assert(Top > 0);

            Top--;
        }

        [[nodiscard]]
        [[gnu::aligned(HotAlign)]]
        i32 Evaluate(const u08 stm) noexcept requires (!N::NeedsBoardAtEval)
        {
            if (Fused) return EvaluateFused(stm, Bucket(), [this] { CatchUp(); });

            Compute();

            return Forward(stm, Bucket());
        }

        template<typename Board>
        [[nodiscard]]
        [[gnu::aligned(HotAlign)]]
        i32 Evaluate(const Board& board) noexcept requires (Detail::BoardView<Board>)
        {
            const u08 stm    = board.SideToMove();
            const s00 bucket = N::Bucket(board);

            if (Fused) return EvaluateFused(stm, bucket, [&] { Settle(board); });

            Compute(board);

            return Forward(stm, bucket);
        }

        template<typename Board>
        [[nodiscard]]
        Array<i32, N::Outputs> EvaluateAll(const Board& board) noexcept
        {
            static_assert(N::Outputs == 1, "a single AccumulatorDot program has one output lane");

            return { Evaluate(board) };
        }

        [[clang::always_inline]]
        void Materialize() noexcept requires (!N::NeedsBoardAtEval) { Compute(); }

        template<typename Board>
        [[clang::always_inline]]
        void Materialize(const Board& board) noexcept { Compute(board); }

        void ClearCache() noexcept
        {
            if constexpr (Cached) Cache.Clear(*Model);
        }

        [[nodiscard]]
        s00 Depth() const noexcept { return Top; }

        template<s00 Slot>
        [[nodiscard]]
        std::span<const typename N::template SlotType<Slot>> Values(const u08 perspective) const noexcept
        {
            static_assert(Slot == Stm || Slot == Ntm, "Values reads a slot of the AccumulatorDot stage");

            assert(perspective < 2 && (!(Lazy || Keyed) || Flags[Top] >> perspective & 1));

            return At(Top, perspective, Slot == Stm ? 0 : Sets - 1);
        }

    };

    template<
        auto                    D       ,
        s00                     Capacity,
        UpdatePolicy            Policy  ,
        Accumulators            Grouped ,
        const Lowering::Target& T
    > requires (Detail::Refused<D>)
    class AccumulatorStack<D, Capacity, Policy, Grouped, T> : public Network<D, T> {};

    template<
        auto                    D       ,
        s00                     Capacity,
        UpdatePolicy            Policy  ,
        Accumulators            Grouped ,
        const Lowering::Target& T
    > requires (Detail::Staged<D, T>)
    class alignas(Alignment) AccumulatorStack<D, Capacity, Policy, Grouped, T>
    {

        using Net = Network<D, T>;
        using M   = Net::Model;
        using ISA = Backend::ISAOf<T>;

        constexpr static Lowering::Program<M::Nodes> Program =
            Grouped == Accumulators::Combined ? Lowering::Combine(Net::Program)
                                              : Net::Program;

        constexpr static s00 Slots        = Program.SlotCount;
        constexpr static s00 Splits       = Net::Program.SlotCount;
        constexpr static s00 BindingCount = M::Graph.Bindings.size();

        constexpr static Array<Detail::Leaves, Slots> Leaf = Detail::LeavesOf<M, Slots>(Program);

        constexpr static Array<Detail::Origin, Slots, IR::MaxFeatureSet> Origins =
            Detail::OriginsOf<M, Splits, Slots>(Detail::LeavesOf<M, Splits>(Net::Program), Leaf);

        constexpr static Detail::Units<Slots> Units = Detail::UnitsOf<Slots>(Program);

        constexpr static bool Lazy     = Policy == UpdatePolicy::Lazy;
        constexpr static bool Counted  = Detail::AnyCounted<M>(std::make_integer_sequence<u16, BindingCount> {});
        constexpr static u08  Computed = 0x3;

        template<s00 U>
        constexpr static u16 Lead = Units.Lead[U];

        template<s00 U>
        constexpr static Lowering::Slot Group = Program.Slots[Lead<U>];

        template<s00 U>
        constexpr static u32 Width = Group<U>.Width;

        template<s00 U>
        constexpr static s00 Terms = Leaf[Lead<U>].Terms;

        template<s00 U>
        constexpr static u16 Home = Detail::HomeOf(Net::Program, Group<U>);

        template<s00 U, s00 J>
        constexpr static Detail::Origin From = Origins[Lead<U>][J];

        template<s00 U>
        using S = Net::template SlotType<Home<U>>;

        template<s00 U, s00 J>
        using F = Net::template FeatureSet<From<U, J>.Slot, From<U, J>.Term>;

        template<s00 U, s00 J>
        using W = Net::template RowType<From<U, J>.Slot, From<U, J>.Term>;

        template<s00 U>
        constexpr static Detail::Classes Class = Detail::ClassesOf<M>(Origins[Lead<U>], Terms<U>, Group<U>.Incremental);

        template<s00 U, s00 K>
        using Trigger = F<U, Class<U>.Leader[K]>::Trigger;

        template<s00 U>
        constexpr static bool Keyed = Class<U>.Count > 0;

        template<s00 U>
        constexpr static bool Derived = []<s00... J>(const std::index_sequence<J...>) {
            return (DerivedFeatureSet<F<U, J>> || ...);
        }(std::make_index_sequence<Terms<U>> {});

        template<s00 U>
        constexpr static bool Indexed = []<s00... J>(const std::index_sequence<J...>) {
            return ((DerivedFeatureSet<F<U, J>> || requires (const PieceChange change) {
                F<U, J>::Index(u08 {}, u32 {}, change);
            }) && ...);
        }(std::make_index_sequence<Terms<U>> {});

        template<s00 U>
        constexpr static bool Refreshed = Keyed<U> || Derived<U> || !Indexed<U>;

        template<s00 U>
        constexpr static bool AnyCached = []<s00... J>(const std::index_sequence<J...>) {
            return (F<U, J>::Cached || ...);
        }(std::make_index_sequence<Terms<U>> {});

        template<s00 U>
        constexpr static bool Applies = !Group<U>.Incremental || !(Keyed<U> || AnyCached<U>) || Indexed<U>;

        constexpr static bool Applicable = []<s00... U>(const std::index_sequence<U...>) {
            return (Applies<U> && ...);
        }(std::make_index_sequence<Units.Count> {});

        template<s00 U>
        constexpr static bool Cacheable = []<s00... J>(const std::index_sequence<J...>) {
            return (F<U, J>::Cached && ...);
        }(std::make_index_sequence<Terms<U>> {}) && Group<U>.Incremental && Indexed<U>;

        template<s00 U>
        constexpr static bool Cached = Cacheable<U> && Terms<U> == 1;

        template<s00 U>
        constexpr static bool Joint = Cacheable<U> && Terms<U> > 1;

        template<s00 U>
        constexpr static bool Partial = !Cacheable<U> && AnyCached<U> && Group<U>.Incremental && Indexed<U>;

        template<s00 U>
        constexpr static bool Termwise = Partial<U> && Lazy && Keyed<U>;

        constexpr static u32 StepOccupancy = 15;

        template<s00 U, s00 K>
        constexpr static bool Keying = []<s00... J>(const std::index_sequence<J...>) {
            return ((Class<U>.Of[J] == K && F<U, J>::Cached) || ...);
        }(std::make_index_sequence<Terms<U>> {});

        template<s00 U>
        constexpr static u32 Loose = []<s00... J>(const std::index_sequence<J...>) {
            return ((!F<U, J>::Cached && Class<U>.Of[J] != Detail::Unkeyed ? u32 { 1 } << Class<U>.Of[J] : u32 { 0 }) |
                    ... | u32 { 0 });
        }(std::make_index_sequence<Terms<U>> {});

        template<s00 U>
        constexpr static bool CachedDerived = []<s00... J>(const std::index_sequence<J...>) {
            return ((F<U, J>::Cached && DerivedFeatureSet<F<U, J>>) || ...);
        }(std::make_index_sequence<Terms<U>> {});

        template<s00 U>
        constexpr static u64 Combos = []<s00... K>(const std::index_sequence<K...>) {
            return (u64 { 1 } * ... * (Keying<U, K> ? Trigger<U, K>::KeyCount : 1));
        }(std::make_index_sequence<Class<U>.Count> {});

        constexpr static bool Underived = []<s00... U>(const std::index_sequence<U...>) {
            return !(CachedDerived<U> || ...);
        }(std::make_index_sequence<Units.Count> {});

        template<s00 U, typename Weight>
        constexpr static u32 Room = []<s00... J>(const std::index_sequence<J...>) {
            return ((std::is_same_v<W<U, J>, Weight> ? Detail::RoomOf<F<U, J>>() : u32 { 0 }) + ... + u32 { 0 });
        }(std::make_index_sequence<Terms<U>> {});

        template<s00 U, typename Weight>
        constexpr static u32 Reach = []<s00... J>(const std::index_sequence<J...>) {
            return ((std::is_same_v<W<U, J>, Weight> ? F<U, J>::MaxActive : u32 { 0 }) + ... + u32 { 0 });
        }(std::make_index_sequence<Terms<U>> {});

        template<s00 U, typename Weight>
        constexpr static u32 Kept = []<s00... J>(const std::index_sequence<J...>) {
            return ((std::is_same_v<W<U, J>, Weight> && F<U, J>::Cached ? F<U, J>::MaxActive : u32 { 0 }) + ... +
                    u32 { 0 });
        }(std::make_index_sequence<Terms<U>> {});

        template<s00 U, typename Weight>
        constexpr static u32 Swept = Reach<U, Weight> - Kept<U, Weight>;

        template<s00 U, typename Weight>
        constexpr static bool Last = Reach<U, Weight> > 0 && (std::is_same_v<Weight, i32> || Reach<U, i32> == 0) &&
                                     (!std::is_same_v<Weight, i08> || Reach<U, i16> == 0);

        template<s00 R, s00 A>
        constexpr static u08 Shape = static_cast<u08>(R * 3 + A);

        template<typename G>
        constexpr static bool Chained = requires (const typename G::Record& record, const PieceDelta& delta) {
            { G::Next(record, delta) } -> std::same_as<typename G::Record>;
            { record == record     } -> std::convertible_to<bool>;
        };

        template<typename G>
        using TierOf = Backend::Kernel::Geometry::DerivationOf<ISA, G>;

        constexpr static u64 PrefetchBytes = u64 { 8 } << 20;
        constexpr static u32 PrefetchLines = 1;

        template<s00 U, s00 J>
        constexpr static bool Prefetched = Detail::Streamed<M, W<U, J>>(Leaf[Lead<U>].Sparse[J], PrefetchBytes);

        static_assert(
            std::ranges::none_of(Leaf, &Detail::Leaves::Overflow),
            "a combined slot sums more than IR::MaxFeatureSet sparse terms or biases"
        );
        static_assert(PrefetchLines <= 2, "a row prefetch covers line 0 or lines 0 and 1");
        static_assert(Capacity > 0, "the stack needs room for the root");
        static_assert(
            Applicable,
            "a keyed or cached incremental slot needs Index(perspective, key, change) on each non-derived family"
        );
        static_assert(Underived, "a cached family is mended from piece changes, so it cannot be derived");

        template<s00 U, s00... J>
        static std::tuple<
            std::conditional_t<F<U, J>::Cached, typename Detail::Snapshots<F<U, J>>::Snapshot, Absent<J>>...
        > SnapshotsOf(const std::index_sequence<J...>);

        template<s00 U>
        struct Entry
        {

            alignas(Alignment) Array<S<U>, Width<U>> Values;

            decltype(SnapshotsOf<U>(std::make_index_sequence<Terms<U>> {})) Pieces;

            u64 Generation;

        };

        template<s00 U>
        struct Unit
        {

            constexpr static bool Incremental = Group<U>.Incremental;
            constexpr static s00  Sides       = Group<U>.Shared ? 1 : 2;

            static_assert(
                !(Joint<U> || Partial<U>) || Combos<U> <= 0xFFFFFFFF,
                "an accumulator cache's key tuples fit a u32"
            );

            using Single = AccumulatorCache<F<U, 0>, S<U>, W<U, 0>, Width<U>, 1, ISA>;
            using Joints = Array<Entry<U>, 2, Combos<U>>;

            using ValueArray = std::conditional_t<
                Incremental, Array<S<U>, Capacity, 2, Width<U>>, Array<S<U>, Sides, Width<U>>
            >;

            using FlagArray = std::conditional_t<Incremental, Array<u08, Capacity>                   , Absent<0>>;
            using  KeyArray = std::conditional_t<Keyed<U>   , Array<u32, Capacity, 2, Class<U>.Count>, Absent<1>>;

            using Table = std::conditional_t<
                Cached<U>, Single, std::conditional_t<Joint<U> || Partial<U>, Joints, Absent<2>>
            >;

            alignas(Alignment) ValueArray Values {};

            NO_UNIQUE_ADDRESS FlagArray Flags {};
            NO_UNIQUE_ADDRESS KeyArray  Keys  {};
            NO_UNIQUE_ADDRESS Table     Cache {};

        };

        template<s00 U, typename R>
        struct Mends
        {

            Array<const R*, std::max(Kept<U, R>, u32 { 1 })> Removed ;
            Array<const R*, std::max(Kept<U, R>, u32 { 1 })> Inserted;
            Array<const R*, Reach<U, R> + 1                > Active  ;

            u32 Removals   = 0;
            u32 Insertions = 0;
            u32 Count      = 0;

        };

        struct Rewound
        {

            Array<u64, 12> Sets {};

            template<typename Board>
            static Rewound Of(const Board& board) noexcept
            {
                Rewound rewound {};

                for (u08 side  = 0; side  < 2; side++ )
                for (u08 piece = 0; piece < 6; piece++)
                    rewound.Sets[side * 6 + piece] = board.Pieces(side, static_cast<Piece>(piece));

                return rewound;
            }

            void Undo(const PieceDelta& delta) noexcept
            {
                for (s00 i = 0; i < delta.InsertedCount(); i++) {
                    const PieceChange change = delta.Inserted(i);

                    Sets[change.Side * 6 + static_cast<u08>(change.Type)] &= ~(u64 { 1 } << change.Square);
                }

                for (s00 i = 0; i < delta.RemovedCount(); i++) {
                    const PieceChange change = delta.Removed(i);

                    Sets[change.Side * 6 + static_cast<u08>(change.Type)] |= u64 { 1 } << change.Square;
                }
            }

            u64 Pieces(const u08 side, const Piece piece) const noexcept
            { return Sets[side * 6 + static_cast<u08>(piece)]; }

            u08 King(const u08 side) const noexcept
            { return static_cast<u08>(std::countr_zero(Pieces(side, Piece::King))); }

            u64 Occupied() const noexcept
            {
                u64 occupied = 0;

                for (s00 set = 0; set < 12; set++) occupied |= Sets[set];

                return occupied;
            }

        };

        template<u16... U>
        static std::tuple<Unit<U>...> UnitsOf(const std::integer_sequence<u16, U...>);

        template<u16... B>
        static std::tuple<Detail::StoreOf<typename M::template Binding<B>, Capacity>...> StoresOf(
            std::integer_sequence<u16, B...>
        );

        using CountArray = std::conditional_t<Counted, Array<u08, Capacity>, Absent<2>>;

        decltype(UnitsOf (std::make_integer_sequence<u16, Units.Count > {})) State  {};
        decltype(StoresOf(std::make_integer_sequence<u16, BindingCount> {})) Stores {};

        Array<PieceDelta, Capacity> Deltas {};

        NO_UNIQUE_ADDRESS CountArray PieceCounts {};

        const Net* Model;

        s00 Top = 0;

        bool Rooted = false;

        template<s00 U>
        [[clang::always_inline]]
              Unit<U>& StateOf()       noexcept { return std::get<U>(State); }
        template<s00 U>
        [[clang::always_inline]]
        const Unit<U>& StateOf() const noexcept { return std::get<U>(State); }

        template<s00 U>
        [[clang::always_inline]]
              Array<S<U>, Width<U>>& At(const s00 ply, const u08 side)       noexcept
        { return StateOf<U>().Values[ply][side]; }
        template<s00 U>
        [[clang::always_inline]]
        const Array<S<U>, Width<U>>& At(const s00 ply, const u08 side) const noexcept
        { return StateOf<U>().Values[ply][side]; }

        template<s00 U>
        [[clang::always_inline]]
        const S<U>* Current(const u08 side) const noexcept
        {
            if constexpr (Unit<U>::Incremental) return At<U>(Top, side).data();
            else return StateOf<U>().Values[Unit<U>::Sides == 1 ? 0 : side].data();
        }

        template<s00 U, s00 J>
        [[clang::always_inline]]
        u32 Key(const s00 ply, const u08 side) const noexcept
        {
            constexpr u16 K = Class<U>.Of[J];

            if constexpr (K == Detail::Unkeyed) return 0;
            else return StateOf<U>().Keys[ply][side][K];
        }

        template<s00 U, s00 J>
        [[clang::always_inline]]
        const W<U, J>* Row(const u32 index) const noexcept
        { return Model->template FeatureRow<From<U, J>.Slot, From<U, J>.Term>(index); }

        template<s00 U, s00 J, bool Opaque = false>
        [[clang::always_inline]]
        const W<U, J>* Row(const u08 side, const u32 key, const PieceChange& change) const noexcept
        {
            u32 index = F<U, J>::Index(side, key, change);

            if (Opaque) asm("" : "+r"(index));

            return Row<U, J>(index);
        }

        [[clang::always_inline]]
        s00 Enter(const PieceDelta& delta) noexcept
        {
            assert(Top < Capacity - 1);

            const s00 top = ++Top;

            if constexpr (Counted) {
                const u08 parent = PieceCounts[top - 1];

                PieceCounts[top] = static_cast<u08>(parent + delta.InsertedCount() - delta.RemovedCount());
            }

            Deltas[top] = delta;

            return top;
        }

        template<s00 U, s00 J>
        [[clang::always_inline]]
        static void Fetch(const W<U, J>* row) noexcept
        {
            constexpr s00 Line = Alignment / sizeof(W<U, J>);

            if constexpr (Prefetched<U, J>)
                for (u32 line = 0; line < PrefetchLines; line++) ISA::Prefetch(row + line * Line);
        }

        template<u16 B, typename C>
        void Keep(const s00 ply, const C& changes) noexcept
        {
            using G = M::template Binding<B>;
            using P = Detail::Store<G, Capacity>;

            auto& store = std::get<B>(Stores);

            const std::span<const typename G::Change> removed = changes.Removed();
            const std::span<const typename G::Change> added   = changes.Added  ();

            if (removed.size() + added.size() > P::Room) {
                store.Extents[ply] = { .State = Detail::Phase::Overflowed };

                return;
            }

            typename G::Change* region = store.Arena.data() + ply * P::Typical;

            Detail::Spread<P::Room>(removed, region                 );
            Detail::Spread<P::Room>(added  , region + removed.size());

            store.Extents[ply] = {
                .Removed = static_cast<u16>(removed.size()),
                .Added   = static_cast<u16>(added  .size()),
                .State   = Detail::Phase::Stored
            };
        }

        template<u16 B>
        void Generate(
            const s00                                      ply   ,
            const PieceDelta&                              delta ,
            const typename M::template Binding<B>::Record& record
        ) noexcept
        {
            using G = M::template Binding<B>;

            Changes<G> changes;

            if constexpr (requires { G::template Changes<TierOf<G>>(delta, record, changes); })
                G::template Changes<TierOf<G>>(delta, record, changes);
            else G::Changes(delta, record, changes);

            Keep<B>(ply, changes);
        }

        template<u16 B, typename Board>
        [[clang::always_inline]]
        void Record(const s00 ply, const Delta<D>& delta, const Board& after) noexcept
        {
            using G = M::template Binding<B>;

            if constexpr (DerivedFeatureSet<G>) {
                auto& store = std::get<B>(Stores);

                if constexpr (Chained<G>) {
                    if (delta.template Filled<G>()) {
                        store.Linked[ply] = false;

                        Keep<B>(ply, delta.template Recorded<G>());

                        return;
                    }

                    const bool parent = (ply > 1 || Rooted) && store.Linked[ply - 1];

                    store.Records[ply] = parent ? G::Next(store.Records[ply - 1], delta.Pieces) : G::Capture(after);
                    store.Linked [ply] = true;

                    assert(store.Records[ply] == G::Capture(after));
                }

                if (delta.template Filled<G>()) {
                    Keep<B>(ply, delta.template Recorded<G>());

                    return;
                }

                if constexpr (!Chained<G> && requires { { G::Inert(delta.Pieces) } -> std::convertible_to<bool>; })
                    if (G::Inert(delta.Pieces)) {
                        store.Extents[ply] = { .State = Detail::Phase::Stored };

                        return;
                    }

                if constexpr (!Chained<G>) store.Records[ply] = G::Capture(after);

                if (Detail::EagerOf<G>()) {
                    Generate<B>(ply, delta.Pieces, store.Records[ply]);

                    return;
                }

                store.Extents[ply] = { .State = Detail::Phase::Deferred };
            }
        }

        template<u16 B>
        [[clang::always_inline]]
        bool Derive(const s00 ply) noexcept
        {
            const auto& store = std::get<B>(Stores);

            if (store.Extents[ply].State == Detail::Phase::Deferred) Generate<B>(ply, Deltas[ply], store.Records[ply]);

            return store.Extents[ply].State == Detail::Phase::Stored;
        }

        template<s00 U>
        [[clang::always_inline]]
        bool Fits(const s00 ply) noexcept
        {
            if (!Indexed<U>) return false;

            return [&]<s00... J>(const std::index_sequence<J...>) {
                return ([&] {
                    if constexpr (DerivedFeatureSet<F<U, J>>) return Derive<From<U, J>.Binding>(ply);
                    else return true;
                }() && ...);
            }(std::make_index_sequence<Terms<U>> {});
        }

        template<s00 U, s00 J, typename Weight, u32 L>
        [[clang::always_inline]]
        void Collect(
            const s00                      ply       ,
            const u08                      side      ,
                  Array<const Weight*, L>& removed   ,
                  Array<const Weight*, L>& inserted  ,
                  u32&                     removals  ,
                  u32&                     insertions
        ) const noexcept
        {
            using G = F<U, J>;

            const u32 key = Key<U, J>(ply, side);

            if constexpr (DerivedFeatureSet<G>) {
                using P = Detail::Store<G, Capacity>;

                const auto&          store  = std::get<From<U, J>.Binding>(Stores);
                const Detail::Extent extent = store.Extents[ply];

                const typename G::Change* region = store.Arena.data() + ply * P::Typical;

                assert(extent.State == Detail::Phase::Stored);

                const auto take = [&](Array<const Weight*, L>& rows, u32& count, const u32 index) {
                    const Weight* row = Row<U, J>(index);

                    Fetch<U, J>(row);

                    rows[count++] = row;
                };

                const auto removal   = [&](const u32 index) { take(removed , removals  , index); };
                const auto insertion = [&](const u32 index) { take(inserted, insertions, index); };

                Backend::Kernel::RowIndex::Rows<ISA, G>(side, key, region                 , extent.Removed, removal  );
                Backend::Kernel::RowIndex::Rows<ISA, G>(side, key, region + extent.Removed, extent.Added  , insertion);
            } else {
                const PieceDelta& delta = Deltas[ply];

                const auto piece = [&](const PieceChange& change, Array<const Weight*, L>& rows, u32& count) {
                    const Weight* row = Row<U, J, true>(side, key, change);

                    Fetch<U, J>(row);

                    rows[count++] = row;
                };

                for (s00 i = 0; i < delta.RemovedCount (); i++) piece(delta.Removed (i), removed , removals  );
                for (s00 i = 0; i < delta.InsertedCount(); i++) piece(delta.Inserted(i), inserted, insertions);
            }
        }

        template<s00 U, typename Weight>
        [[clang::always_inline]]
        void Pass(const s00 ply, const u08 side, bool& first) noexcept
        {
            constexpr u32 L = Room<U, Weight>;

            if constexpr (L > 0) {
                Array<const Weight*, L> removed ;
                Array<const Weight*, L> inserted;

                u32 removals   = 0;
                u32 insertions = 0;

                [&]<s00... J>(const std::index_sequence<J...>) {
                    ([&] {
                        if constexpr (std::is_same_v<W<U, J>, Weight>)
                            Collect<U, J, Weight, L>(ply, side, removed, inserted, removals, insertions);
                    }(), ...);
                }(std::make_index_sequence<Terms<U>> {});

                S<U>* child = At<U>(ply, side).data();

                Backend::Kernel::Update<ISA, Width<U>, S<U>, Weight>(
                    first ? At<U>(ply - 1, side).data() : child,
                    std::span(removed ).first(removals  ),
                    std::span(inserted).first(insertions),
                    child
                );

                first = false;
            }
        }

        template<s00 U>
        void Replay(const s00 ply, const u08 sides) noexcept
        {
            for (u08 side = 0; side < 2; side++) {
                if (!(sides >> side & 1)) continue;

                bool first = true;

                Pass<U, i08>(ply, side, first);
                Pass<U, i16>(ply, side, first);
                Pass<U, i32>(ply, side, first);
            }
        }

        template<s00 U, typename Weight>
        [[clang::always_inline]]
        void Revert(const s00 ply, const u08 side, bool& first) noexcept
        {
            constexpr u32 L = Room<U, Weight>;

            if constexpr (L > 0) {
                Array<const Weight*, L> removed ;
                Array<const Weight*, L> inserted;

                u32 removals   = 0;
                u32 insertions = 0;

                [&]<s00... J>(const std::index_sequence<J...>) {
                    ([&] {
                        if constexpr (std::is_same_v<W<U, J>, Weight>)
                            Collect<U, J, Weight, L>(ply, side, removed, inserted, removals, insertions);
                    }(), ...);
                }(std::make_index_sequence<Terms<U>> {});

                S<U>* parent = At<U>(ply - 1, side).data();

                Backend::Kernel::Update<ISA, Width<U>, S<U>, Weight>(
                    first ? At<U>(ply, side).data() : parent,
                    std::span(inserted).first(insertions),
                    std::span(removed ).first(removals  ),
                    parent
                );

                first = false;
            }
        }

        template<s00 U>
        [[clang::noinline]]
        void Retreat(const s00 ply, const u08 side) noexcept
        {
            bool first = true;

            Revert<U, i08>(ply, side, first);
            Revert<U, i16>(ply, side, first);
            Revert<U, i32>(ply, side, first);
        }

        template<s00 U, s00 R, s00 A>
        [[clang::always_inline]]
        void Apply(const s00 ply, const PieceDelta& delta, const u08 side) noexcept
        {
            if (Terms<U> == 1) {
                const u32 key = Key<U, 0>(ply, side);

                Detail::Update<ISA, S<U>, W<U, 0>, R, A> transition {
                    .Child    = At<U>(ply    , side).data(),
                    .Parent   = At<U>(ply - 1, side).data(),
                    .Removed  = {},
                    .Inserted = {}
                };

                for (s00 i = 0; i < R; i++) transition.Removed [i] = Row<U, 0, true>(side, key, delta.Removed (i));
                for (s00 i = 0; i < A; i++) transition.Inserted[i] = Row<U, 0, true>(side, key, delta.Inserted(i));

                Backend::Kernel::Advance<Width<U>>(transition);
            } else {
                [&]<s00... J>(const std::index_sequence<J...>) {
                    ([&] {
                        const u32 key = Key<U, J>(ply, side);

                        Array<const W<U, J>*, R> removed ;
                        Array<const W<U, J>*, A> inserted;

                        for (s00 i = 0; i < R; i++) removed [i] = Row<U, J, true>(side, key, delta.Removed (i));
                        for (s00 i = 0; i < A; i++) inserted[i] = Row<U, J, true>(side, key, delta.Inserted(i));

                        Backend::Kernel::Update<ISA, Width<U>, S<U>, W<U, J>>(
                            At<U>(J == 0 ? ply - 1 : ply, side).data(),
                            std::span(removed ),
                            std::span(inserted),
                            At<U>(ply, side).data()
                        );
                    }(), ...);
                }(std::make_index_sequence<Terms<U>> {});
            }
        }

        template<s00 U, s00 R, s00 A>
        [[clang::always_inline]]
        void Step(const s00 ply, const PieceDelta& delta, const u08 sides) noexcept
        {
            if (sides & 1) Apply<U, R, A>(ply, delta, White);
            if (sides & 2) Apply<U, R, A>(ply, delta, Black);
        }

        template<s00 U>
        [[clang::noinline]]
        void AdvanceRare(const s00 ply, const PieceDelta& delta, const u08 sides) noexcept
        {
            switch (delta.Shape()) {
                case Shape<0, 0>: Step<U, 0, 0>(ply, delta, sides); break;
                case Shape<0, 1>: Step<U, 0, 1>(ply, delta, sides); break;
                case Shape<0, 2>: Step<U, 0, 2>(ply, delta, sides); break;
                case Shape<1, 0>: Step<U, 1, 0>(ply, delta, sides); break;
                case Shape<1, 2>: Step<U, 1, 2>(ply, delta, sides); break;
                default         : Step<U, 2, 0>(ply, delta, sides); break;
            }
        }

        template<s00 U>
        [[clang::always_inline]]
        void Advance(const s00 ply, const u08 sides) noexcept
        {
            if constexpr (!Indexed<U>) std::unreachable();
            else if constexpr (Derived<U>) Replay<U>(ply, sides);
            else {
                const PieceDelta& delta = Deltas[ply];

                switch (delta.Shape()) {
                    case Shape<1, 1>: Step       <U, 1, 1>(ply, delta, sides); break;
                    case Shape<2, 1>: Step       <U, 2, 1>(ply, delta, sides); break;
                    case Shape<2, 2>: Step       <U, 2, 2>(ply, delta, sides); break;
                    default         : AdvanceRare<U      >(ply, delta, sides); break;
                }
            }
        }

        template<s00 U, s00 K, typename Board>
        [[clang::always_inline]]
        void Track(const s00 ply, const PieceDelta& delta, [[maybe_unused]] const Board& after) noexcept
        {
            using G = Trigger<U, K>;

            auto& keys = StateOf<U>().Keys;

            if constexpr (requires { G::KeyOf(u08 {}, u08 {}); }) {
                keys[ply][White][K] = keys[ply - 1][White][K];
                keys[ply][Black][K] = keys[ply - 1][Black][K];

                UNROLL(full)
                for (s00 i = 0; i < 2; i++) {
                    if (i == delta.InsertedCount()) break;

                    const PieceChange change = delta.Inserted(i);

                    if (change.Type != Piece::King) continue;

                    keys[ply][change.Side][K] = G::KeyOf(change.Side, change.Square);
                }
            } else {
                keys[ply][White][K] = G::Key(White, after);
                keys[ply][Black][K] = G::Key(Black, after);
            }
        }

        template<s00 U, typename Board>
        [[clang::always_inline]]
        void Track(const s00 ply, const PieceDelta& delta, const Board& after) noexcept
        {
            [&]<s00... K>(const std::index_sequence<K...>) {
                (Track<U, K>(ply, delta, after), ...);
            }(std::make_index_sequence<Class<U>.Count> {});
        }

        template<s00 U>
        [[clang::always_inline]]
        u08 Unchanged(const s00 ply) const noexcept
        {
            if constexpr (Keyed<U>) {
                const auto& keys = StateOf<U>().Keys;

                return (keys[ply][0] == keys[ply - 1][0]) | (keys[ply][1] == keys[ply - 1][1]) << 1;
            }

            return Computed;
        }

        template<s00 U>
        [[clang::always_inline]]
        bool Ready(const s00 ply) noexcept
        { return StateOf<U>().Flags[ply - 1] == Computed && Unchanged<U>(ply) == Computed && Fits<U>(ply); }

        template<s00 U>
        [[clang::always_inline]]
        void Settle(const s00 top) noexcept
        {
            if constexpr (Unit<U>::Incremental) {
                auto& flags = StateOf<U>().Flags;

                if (Lazy) {
                    flags[top] = 0;

                    return;
                }

                const u08 ready = flags[top - 1] & Unchanged<U>(top);
                const u08 sides = ready != 0 && Fits<U>(top) ? ready : 0;

                flags[top] = sides;

                if (sides != 0) Advance<U>(top, sides);
            }
        }

        template<s00 U, s00 J, typename Board>
        [[clang::always_inline]]
        void Gather(const u08 side, const Board& board, S<U>* values) const noexcept
        {
            using R = W<U, J>;

            constexpr u32 Limit = F<U, J>::MaxActive;

            Array<const R*, Limit> rows;

            u32 count = 0;

            const auto emit = [&](const u32 feature) {
                assert(count < Limit);

                if (count == Limit) return;

                const R* row = Row<U, J>(feature);

                Fetch<U, J>(row);

                rows[count++] = row;
            };

            if constexpr (requires { F<U, J>::template Active<ISA>(side, board, emit); })
                F<U, J>::template Active<ISA>(side, board, emit);
            else F<U, J>::Active(side, board, emit);

            const std::span<const R* const> active(std::span(rows).first(count));

            if (J == 0) Backend::Kernel::Refresh<ISA, Width<U>>(Model->template FeatureBias<Home<U>>(), active, values);
            else        Backend::Kernel::Update <ISA, Width<U>, S<U>, R>(values, {}, active, values);
        }

        template<s00 U, typename Board>
        void Fill(const u08 side, const Board& board, S<U>* values) const noexcept
        {
            [&]<s00... J>(const std::index_sequence<J...>) {
                (Gather<U, J>(side, board, values), ...);
            }(std::make_index_sequence<Terms<U>> {});
        }

        template<s00 U, s00 K, typename Board>
        bool KeyAgrees(const s00 ply, const u08 sides, const Board& board) const noexcept
        {
            const auto& keys = StateOf<U>().Keys[ply];

            return (!(sides & 1) || keys[White][K] == Trigger<U, K>::Key(White, board)) &&
                   (!(sides & 2) || keys[Black][K] == Trigger<U, K>::Key(Black, board));
        }

        template<s00 U, typename Board>
        bool KeysAgree(const s00 ply, const u08 sides, const Board& board) const noexcept
        {
            return [&]<s00... K>(const std::index_sequence<K...>) {
                return (KeyAgrees<U, K>(ply, sides, board) && ...);
            }(std::make_index_sequence<Class<U>.Count> {});
        }

        template<s00 U, s00 K, typename Board>
        [[clang::always_inline]]
        void Rekey(const Board& board) noexcept
        {
            auto& keys = StateOf<U>().Keys[0];

            keys[White][K] = Trigger<U, K>::Key(White, board);
            keys[Black][K] = Trigger<U, K>::Key(Black, board);
        }

        template<s00 U, typename Board>
        [[clang::always_inline]]
        void Rekey(const Board& board) noexcept
        {
            [&]<s00... K>(const std::index_sequence<K...>) {
                (Rekey<U, K>(board), ...);
            }(std::make_index_sequence<Class<U>.Count> {});
        }

        template<s00 U>
        void Blank(Entry<U>& entry) const noexcept
        {
            Backend::Kernel::Copy<ISA, Width<U>>(Model->template FeatureBias<Home<U>>(), entry.Values.data());

            entry.Pieces     = {};
            entry.Generation = Model->Generation();
        }

        template<s00 U>
        [[clang::always_inline]]
        u32 Combo(const s00 ply, const u08 side) const noexcept
        {
            u32 combo = 0;

            if constexpr (Keyed<U>) {
                const auto& keys = StateOf<U>().Keys[ply][side];

                [&]<s00... K>(const std::index_sequence<K...>) {
                    ((combo = Keying<U, K> ? combo * Trigger<U, K>::KeyCount + keys[K] : combo), ...);
                }(std::make_index_sequence<Class<U>.Count> {});
            }

            return combo;
        }

        template<s00 U, s00 J, typename Weight, u32 L, typename Board, typename Flush>
        [[clang::always_inline]]
        void MendTerm(
                  Entry<U>&                entry     ,
            const s00                      ply       ,
            const u08                      side      ,
            const Board&                   board     ,
                  Array<const Weight*, L>& removed   ,
                  Array<const Weight*, L>& inserted  ,
                  u32&                     removals  ,
                  u32&                     insertions,
            const Flush&                   flush
        ) const noexcept
        {
            using P = Detail::Snapshots<F<U, J>>;

            const u32 key = Key<U, J>(ply, side);

            auto& pieces = std::get<J>(entry.Pieces);

            P::Diff(
                pieces,
                board,
                [&](const PieceChange& change) {
                    if (removals == L) flush();

                    removed [removals  ++] = Row<U, J>(side, key, change);
                },
                [&](const PieceChange& change) {
                    if (insertions == L) flush();

                    inserted[insertions++] = Row<U, J>(side, key, change);
                }
            );

            pieces = P::Of(board);
        }

        template<s00 U, typename Weight, typename Board>
        [[clang::always_inline]]
        void Mend(
                  Entry<U>&              entry      ,
            const s00                    ply        ,
            const u08                    side       ,
            const Board&                 board      ,
                  Array<S<U>, Width<U>>& destination
        ) const noexcept
        {
            constexpr u32 L = Reach<U, Weight>;

            if constexpr (L > 0) {
                Array<const Weight*, L> removed ;
                Array<const Weight*, L> inserted;

                u32 removals   = 0;
                u32 insertions = 0;

                S<U>* values = entry.Values.data();

                const auto flush = [&] {
                    Backend::Kernel::Update<ISA, Width<U>, S<U>, Weight>(
                        values,
                        std::span(removed ).first(removals  ),
                        std::span(inserted).first(insertions),
                        values
                    );

                    removals   = 0;
                    insertions = 0;
                };

                [&]<s00... J>(const std::index_sequence<J...>) {
                    ([&] {
                        if constexpr (std::is_same_v<W<U, J>, Weight>)
                            MendTerm<U, J, Weight, L>(
                                entry,
                                ply,
                                side,
                                board,
                                removed,
                                inserted,
                                removals,
                                insertions,
                                flush
                            );
                    }(), ...);
                }(std::make_index_sequence<Terms<U>> {});

                if (Last<U, Weight>)
                    Backend::Kernel::Update<ISA, Width<U>, S<U>, Weight>(
                        values,
                        std::span(removed ).first(removals  ),
                        std::span(inserted).first(insertions),
                        values,
                        destination.data()
                    );
                else flush();
            }
        }

        template<s00 U, typename R, typename Board>
        [[clang::always_inline]]
        u32 Enumerate(const u08 side, const Board& board, Array<const R*, Reach<U, R> + 1>& rows) const noexcept
        {
            constexpr u32 Limit = Swept<U, R>;

            u32 count = 0;

            [&]<s00... J>(const std::index_sequence<J...>) {
                ([&] {
                    if constexpr (std::is_same_v<W<U, J>, R> && !F<U, J>::Cached) {
                        const auto emit = [&](const u32 feature) {
                            assert(count < Limit);

                            if (count == Limit) return;

                            const R* row = Row<U, J>(feature);

                            Fetch<U, J>(row);

                            rows[count++] = row;
                        };

                        if constexpr (requires { F<U, J>::template Active<ISA>(side, board, emit); })
                            F<U, J>::template Active<ISA>(side, board, emit);
                        else F<U, J>::Active(side, board, emit);
                    }
                }(), ...);
            }(std::make_index_sequence<Terms<U>> {});

            return count;
        }

        template<s00 U, typename R, typename Board>
        [[clang::always_inline]]
        void MendRows(
                  Entry<U>&    entry,
            const s00          ply  ,
            const u08          side ,
            const Board&       board,
                  Mends<U, R>& rows
        ) const noexcept
        {
            constexpr u32 L = Kept<U, R>;

            if constexpr (L > 0) {
                S<U>* values = entry.Values.data();

                const auto flush = [&] {
                    Backend::Kernel::Update<ISA, Width<U>, S<U>, R>(
                        values,
                        std::span(rows.Removed ).first(rows.Removals  ),
                        std::span(rows.Inserted).first(rows.Insertions),
                        values
                    );

                    rows.Removals   = 0;
                    rows.Insertions = 0;
                };

                [&]<s00... J>(const std::index_sequence<J...>) {
                    ([&] {
                        if constexpr (std::is_same_v<W<U, J>, R> && F<U, J>::Cached) {
                            const u32 removals   = rows.Removals;
                            const u32 insertions = rows.Insertions;

                            MendTerm<U, J, R, L>(
                                entry,
                                ply,
                                side,
                                board,
                                rows.Removed,
                                rows.Inserted,
                                rows.Removals,
                                rows.Insertions,
                                flush
                            );

                            for (u32 i = removals   < rows.Removals   ? removals   : 0; i < rows.Removals  ; i++)
                                Fetch<U, J>(rows.Removed [i]);
                            for (u32 i = insertions < rows.Insertions ? insertions : 0; i < rows.Insertions; i++)
                                Fetch<U, J>(rows.Inserted[i]);
                        }
                    }(), ...);
                }(std::make_index_sequence<Terms<U>> {});
            }
        }

        template<s00 U, typename R>
        [[clang::always_inline]]
        static auto Views(const Mends<U, R>& rows) noexcept
        {
            if constexpr (Reach<U, R> == 0) return std::tuple<> {};
            else return std::tuple(Backend::Kernel::Mending<R> {
                .Removed  = std::span(rows.Removed ).first(rows.Removals  ),
                .Inserted = std::span(rows.Inserted).first(rows.Insertions),
                .Active   = std::span(rows.Active  ).first(rows.Count     )
            });
        }

        template<s00 U, typename Board>
        void Restore(const s00 ply, const u08 side, const Board& board) noexcept
        {
            Entry<U>& entry = StateOf<U>().Cache[side][Combo<U>(ply, side)];

            if (entry.Generation != Model->Generation()) Blank<U>(entry);

            Array<S<U>, Width<U>>& destination = At<U>(ply, side);

            if constexpr (Partial<U>) {
                Mends<U, i08> rows08;
                Mends<U, i16> rows16;
                Mends<U, i32> rows32;

                MendRows<U>(entry, ply, side, board, rows08);
                MendRows<U>(entry, ply, side, board, rows16);
                MendRows<U>(entry, ply, side, board, rows32);

                rows08.Count = Enumerate<U, i08>(side, board, rows08.Active);
                rows16.Count = Enumerate<U, i16>(side, board, rows16.Active);
                rows32.Count = Enumerate<U, i32>(side, board, rows32.Active);

                std::apply(
                    [&](const auto&... lists) {
                        Backend::Kernel::Mend<ISA, Width<U>>(entry.Values.data(), destination.data(), lists...);
                    },
                    std::tuple_cat(Views<U>(rows08), Views<U>(rows16), Views<U>(rows32))
                );
            } else {
                Mend<U, i08>(entry, ply, side, board, destination);
                Mend<U, i16>(entry, ply, side, board, destination);
                Mend<U, i32>(entry, ply, side, board, destination);
            }
        }

        template<s00 U, typename Board>
        void Refresh(const s00 ply, const u08 sides, const Board& board) noexcept
        {
            assert(KeysAgree<U>(ply, sides, board));

            for (u08 side = 0; side < 2; side++) {
                if (!(sides >> side & 1)) continue;

                if constexpr (Cached<U>) {
                    const typename Net::template SlotRows<From<U, 0>.Slot> rows(*Model);

                    StateOf<U>().Cache.Refresh(rows, 0, side, Key<U, 0>(ply, side), board, At<U>(ply, side));
                } else if constexpr (Joint<U> || Partial<U>) Restore<U>(ply, side, board);
                else Fill<U>(side, board, At<U>(ply, side).data());
            }
        }

        template<s00 U>
        [[clang::noinline]]
        void CatchUp() noexcept
        {
            auto& flags = StateOf<U>().Flags;

            const s00 top = Top;

            s00 ply = top - 1;

            while (flags[ply - 1] != Computed) ply--;

            for (; ply <= top; ply++) {
                Advance<U>(ply, Computed);

                flags[ply] = Computed;
            }
        }

        template<s00 U>
        [[clang::always_inline]]
        bool Continues(const s00 ply, const u08 side) noexcept
        { return (Unchanged<U>(ply) >> side & 1) && Fits<U>(ply); }

        template<s00 U, typename Weight>
        [[clang::noinline]]
        static void Shift(
            const S<U>* const                    base       ,
            const std::span<const Weight* const> removed    ,
            const std::span<const Weight* const> inserted   ,
                  S<U>* const                    destination
        ) noexcept
        { Backend::Kernel::Update<ISA, Width<U>, S<U>, Weight>(base, removed, inserted, destination); }

        template<s00 U, typename Weight, typename Board>
        [[clang::always_inline]]
        void MendEntry(Entry<U>& entry, const s00 ply, const u08 side, const Board& board) const noexcept
        {
            constexpr u32 L = Kept<U, Weight>;

            if constexpr (L > 0) {
                Array<const Weight*, L> removed ;
                Array<const Weight*, L> inserted;

                u32 removals   = 0;
                u32 insertions = 0;

                S<U>* values = entry.Values.data();

                const auto flush = [&] {
                    Shift<U, Weight>(
                        values, std::span(removed).first(removals), std::span(inserted).first(insertions), values
                    );

                    removals   = 0;
                    insertions = 0;
                };

                [&]<s00... J>(const std::index_sequence<J...>) {
                    ([&] {
                        if constexpr (std::is_same_v<W<U, J>, Weight> && F<U, J>::Cached)
                            MendTerm<U, J, Weight, L>(
                                entry,
                                ply,
                                side,
                                board,
                                removed,
                                inserted,
                                removals,
                                insertions,
                                flush
                            );
                    }(), ...);
                }(std::make_index_sequence<Terms<U>> {});

                if (removals + insertions > 0) flush();
            }
        }

        template<s00 U, typename Weight>
        [[clang::always_inline]]
        void Transfer(const s00 ply, const u08 side) noexcept
        {
            constexpr u32 L = Room<U, Weight>;

            if constexpr (L > 0 && Swept<U, Weight> > 0) {
                Array<const Weight*, L> removed ;
                Array<const Weight*, L> inserted;

                u32 removals   = 0;
                u32 insertions = 0;

                [&]<s00... J>(const std::index_sequence<J...>) {
                    ([&] {
                        if constexpr (std::is_same_v<W<U, J>, Weight> && !F<U, J>::Cached)
                            Collect<U, J, Weight, L>(ply, side, removed, inserted, removals, insertions);
                    }(), ...);
                }(std::make_index_sequence<Terms<U>> {});

                S<U>* child = At<U>(ply, side).data();

                if (removals + insertions > 0)
                    Shift<U, Weight>(
                        child, std::span(removed).first(removals), std::span(inserted).first(insertions), child
                    );
            }
        }

        template<s00 U>
        [[clang::always_inline]]
        bool Steady(const s00 ply, const u08 side) const noexcept
        {
            const auto& keys = StateOf<U>().Keys;

            return [&]<s00... K>(const std::index_sequence<K...>) {
                return ((!(Loose<U> >> K & 1) || keys[ply][side][K] == keys[ply - 1][side][K]) && ...);
            }(std::make_index_sequence<Class<U>.Count> {});
        }

        template<s00 U, typename Board>
        [[clang::noinline]]
        bool Swap(const s00 ply, const u08 side, const Board& board) noexcept
        {
            Rewound now = Rewound::Of(board);

            for (s00 above = Top; above > ply; above--) now.Undo(Deltas[above]);

            if (static_cast<u32>(std::popcount(now.Occupied())) < StepOccupancy) return false;
            if (!Fits<U>(ply)) return false;

            Rewound then = now;

            then.Undo(Deltas[ply]);

            Entry<U>& stale = StateOf<U>().Cache[side][Combo<U>(ply - 1, side)];
            Entry<U>& fresh = StateOf<U>().Cache[side][Combo<U>(ply    , side)];

            assert(&stale != &fresh);

            if (stale.Generation != Model->Generation()) Blank<U>(stale);
            if (fresh.Generation != Model->Generation()) Blank<U>(fresh);

            MendEntry<U, i08>(stale, ply - 1, side, then);
            MendEntry<U, i16>(stale, ply - 1, side, then);
            MendEntry<U, i32>(stale, ply - 1, side, then);
            MendEntry<U, i08>(fresh, ply    , side, now );
            MendEntry<U, i16>(fresh, ply    , side, now );
            MendEntry<U, i32>(fresh, ply    , side, now );

            const Array<const S<U>*, 1> minus { stale.Values.data() };
            const Array<const S<U>*, 1> plus  { fresh.Values.data() };

            Shift<U, S<U>>(At<U>(ply - 1, side).data(), std::span(minus), std::span(plus), At<U>(ply, side).data());

            Transfer<U, i08>(ply, side);
            Transfer<U, i16>(ply, side);
            Transfer<U, i32>(ply, side);

            return true;
        }

        template<s00 U, typename Board>
        [[clang::always_inline]]
        bool Stepped(const s00 ply, const u08 side, const Board& board) noexcept
        {
            if constexpr (Termwise<U>)
                return (ply > 1 || Rooted) && (StateOf<U>().Flags[ply - 1] >> side & 1) && Steady<U>(ply, side) &&
                       Swap<U>(ply, side, board);
            else return false;
        }

        template<s00 U, typename Board>
        [[clang::noinline]]
        void CatchUp(const Board& board) noexcept
        {
            auto& flags = StateOf<U>().Flags;

            const s00 top = Top;

            Array<s00, 2> base;

            for (u08 side = 0; side < 2; side++) {
                s00 ply = top;

                while (!(flags[ply] >> side & 1) && Continues<U>(ply, side)) ply--;

                if (flags[ply] >> side & 1) base[side] = ply;
                else if (Stepped<U>(ply, side, board)) {
                    flags[ply] |= 1 << side;
                    base [side] = ply;
                } else {
                    Refresh<U>(top, static_cast<u08>(1 << side), board);

                    flags[top] |= 1 << side;
                    base [side] = top;

                    if constexpr (Indexed<U>)
                        for (s00 child = top; child > ply; child--) {
                            Retreat<U>(child, side);

                            flags[child - 1] |= 1 << side;
                        }
                }
            }

            for (s00 ply = std::min(base[0], base[1]) + 1; ply <= top; ply++) {
                const u08 sides = (base[0] < ply) | (base[1] < ply) << 1;

                Advance<U>(ply, sides);

                flags[ply] |= sides;
            }
        }

        template<s00 U>
        [[clang::always_inline]]
        void Compute() noexcept
        {
            static_assert(
                !Refreshed<U>,
                "a slot that cannot apply a ply is refreshed from the board; call Evaluate(board) or Materialize(board)"
            );

            auto& flags = StateOf<U>().Flags;

            const s00 top = Top;

            if (!Lazy || flags[top] == Computed) return;

            if (Ready<U>(top)) {
                Advance<U>(top, Computed);

                flags[top] = Computed;
            } else CatchUp<U>();
        }

        template<s00 U, typename Board>
        [[clang::always_inline]]
        void Compute(const Board& board) noexcept
        {
            if constexpr (!Unit<U>::Incremental) {
                for (u08 side = 0; side < Unit<U>::Sides; side++)
                    Fill<U>(side, board, StateOf<U>().Values[side].data());
            } else if constexpr (!Refreshed<U>) Compute<U>();
            else {
                auto& flags = StateOf<U>().Flags;

                const s00 top = Top;

                if (flags[top] == Computed) return;

                if (!Lazy) {
                    Refresh<U>(top, static_cast<u08>(flags[top] ^ Computed), board);

                    flags[top] = Computed;
                } else if (Ready<U>(top)) {
                    Advance<U>(top, Computed);

                    flags[top] = Computed;
                } else CatchUp<U>(board);
            }
        }

        template<typename Function>
        [[clang::always_inline]]
        static void Each(const Function& function) noexcept
        {
            [&]<s00... U>(const std::index_sequence<U...>) {
                (function.template operator()<U>(), ...);
            }(std::make_index_sequence<Units.Count> {});
        }

        template<typename Board>
        [[clang::always_inline]]
        void Remember(const s00 ply, const Delta<D>& delta, const Board& after) noexcept
        {
            [&]<u16... B>(const std::integer_sequence<u16, B...>) {
                (Record<B>(ply, delta, after), ...);
            }(std::make_integer_sequence<u16, BindingCount> {});
        }

        template<s00 Slot>
        [[clang::always_inline]]
        void Bind(typename Net::Sources& sources, const u08 stm) const noexcept
        {
            constexpr bool Opposite = Program.Slots[Slot].Perspective == IR::Dependence::Ntm;

            const u08 side = Opposite ? static_cast<u08>(stm ^ 1) : stm;

            const auto* values = Current<Units.Of[Slot]>(side);

            if constexpr (std::is_same_v<S<Units.Of[Slot]>, i32>) sources.Wide  [Slot] = values;
            else                                                  sources.Narrow[Slot] = values;
        }

        [[clang::always_inline]]
        u08 Pieces() const noexcept
        {
            if constexpr (Counted) return PieceCounts[Top];

            return 0;
        }

        template<typename Choose>
        [[clang::always_inline]]
        Array<i32, Net::Outputs> Forward(const u08 stm, const Choose& choose) const noexcept
        {
            assert(stm < 2);

            typename Net::Sources sources {};

            [&]<s00... I>(const std::index_sequence<I...>) {
                (Bind<I>(sources, stm), ...);
            }(std::make_index_sequence<Slots> {});

            [&]<u16... B>(const std::integer_sequence<u16, B...>) {
                ([&] {
                    using Choice = M::template Binding<B>;

                    if constexpr (Selector<Choice>) sources.Buckets[B] = choose.template operator()<Choice, B>();
                }(), ...);
            }(std::make_integer_sequence<u16, BindingCount> {});

            return Model->template Forward<Grouped>(sources);
        }

        public:
        using N = Net;

        explicit AccumulatorStack(const N& network) noexcept : Model(&network)
        {
            ClearCache();

            Each([&]<s00 U> {
                if constexpr (Unit<U>::Incremental) {
                    for (u08 side = 0; side < 2; side++)
                        Backend::Kernel::Copy<ISA, Width<U>>(
                            Model->template FeatureBias<Home<U>>(),
                            At<U>(0, side).data()
                        );

                    StateOf<U>().Flags[0] = Computed;
                }
            });
        }

        AccumulatorStack(const N&&) = delete;

        template<typename Board>
        void Reset(const Board& board) noexcept
        {
            Each([&]<s00 U> {
                if constexpr (Unit<U>::Incremental) {
                    Rekey  <U>(board);
                    Refresh<U>(0, Computed, board);

                    StateOf<U>().Flags[0] = Computed;
                }
            });

            if constexpr (Counted) {
                s00 pieces = 0;

                for (u08 side  = 0; side  < 2; side++ )
                for (u08 piece = 0; piece < 6; piece++)
                    pieces += std::popcount(board.Pieces(side, static_cast<Piece>(piece)));

                PieceCounts[0] = static_cast<u08>(pieces);
            }

            [&]<u16... B>(const std::integer_sequence<u16, B...>) {
                ([&] {
                    using G = M::template Binding<B>;

                    if constexpr (DerivedFeatureSet<G> && Chained<G>) {
                        std::get<B>(Stores).Records[0] = G::Capture(board);
                        std::get<B>(Stores).Linked [0] = true;
                    }
                }(), ...);
            }(std::make_integer_sequence<u16, BindingCount> {});

            Top    = 0;
            Rooted = true;
        }

        void Push(const PieceDelta& delta) noexcept requires (!N::NeedsBoard)
        {
            const s00 top = Enter(delta);

            Each([&]<s00 U> {
                Track <U>(top, delta, Detail::Boardless {});
                Settle<U>(top);
            });
        }

        template<typename Board>
        void Push(const PieceDelta& delta, const Board& after) noexcept
        {
            if constexpr (!N::NeedsBoard) Push(delta);
            else Push(Delta<D> { .Pieces = delta }, after);
        }

        template<typename Board>
        void Push(const Delta<D>& delta, const Board& after) noexcept
        {
            if constexpr (!N::NeedsBoard) Push(delta.Pieces);
            else {
                const s00 top = Enter(delta.Pieces);

                Remember(top, delta, after);

                Each([&]<s00 U> {
                    Track <U>(top, delta.Pieces, after);
                    Settle<U>(top);
                });
            }
        }

        [[clang::always_inline]]
        void Pop() noexcept
        {
            assert(Top > 0);

            Top--;
        }

        [[nodiscard]]
        i32 Evaluate(const u08 stm) noexcept requires (!N::NeedsBoardAtEval)
        {
            Materialize();

            return Forward(stm, [&]<typename Choice, u16> { return Choice::OfCount(Pieces()); })[0];
        }

        template<typename Board>
        [[nodiscard]]
        i32 Evaluate(const Board& board) noexcept requires (Detail::BoardView<Board>) { return EvaluateAll(board)[0]; }

        template<typename Board>
        [[nodiscard]]
        Array<i32, N::Outputs> EvaluateAll(const Board& board) noexcept
        {
            Materialize(board);

            return Forward(board.SideToMove(), [&]<typename Choice, u16 B> {
                if constexpr (Detail::CountedBy<M, B + 1>()) return Choice::OfCount(Pieces());
                else return Choice::Of(board);
            });
        }

        void Materialize() noexcept requires (!N::NeedsBoardAtEval)
        {
            Each([&]<s00 U> { Compute<U>(); });
        }

        template<typename Board>
        void Materialize(const Board& board) noexcept
        {
            Each([&]<s00 U> { Compute<U>(board); });
        }

        void ClearCache() noexcept
        {
            Each([&]<s00 U> {
                if constexpr (Cached<U>)
                    StateOf<U>().Cache.Clear(typename Net::template SlotRows<From<U, 0>.Slot>(*Model));
                else if constexpr (Joint<U> || Partial<U>)
                    for (Array<Entry<U>, Combos<U>>& perspective : StateOf<U>().Cache)
                    for (Entry<U>& entry : perspective) Blank<U>(entry);
            });
        }

        [[nodiscard]]
        s00 Depth() const noexcept { return Top; }

        template<s00 Slot>
        [[nodiscard]]
        std::span<const S<Units.Of[Slot]>> Values(const u08 perspective) const noexcept
        {
            constexpr u16 U = Units.Of[Slot];

            if constexpr (Unit<U>::Incremental)
                assert(perspective < 2 && (!(Lazy || Refreshed<U>) || StateOf<U>().Flags[Top] >> perspective & 1));

            return { Current<U>(perspective), Width<U> };
        }

    };

}

#endif //MANTARAY_RUNTIME_ACCUMULATORSTACK_H
