//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_BACKEND_KERNEL_SPARSE_H
#define MANTARAY_BACKEND_KERNEL_SPARSE_H

#include <cstring>
#include <type_traits>

#include "Nnz.h"
#include "../../Common.h"
#include "../../Lowering/Facts.h"
#include "../../Lowering/Program.h"

namespace MantaRay::Backend::Kernel
{

    template<u32 Inputs, u32 Rows, u32 Stride = Rows, typename A>
    [[clang::always_inline]]
    void Sparse(const u08* input, const i08* weights, A* sums) noexcept
    {
        static_assert(Inputs % 4 == 0, "sparse inputs are scanned in groups of 4 bytes");
        static_assert(Stride >= Rows , "a chunk column holds every row"                );

        constexpr u32 Groups = Inputs / 4;

        Array<u32, Groups> active;

        u32 count = 0;

        for (u32 group = 0; group < Groups; group++) {
            const u08* x = input + group * 4;

            active[count]  = group;
            count         += (x[0] | x[1] | x[2] | x[3]) != 0;
        }

        for (u32 i = 0; i < count; i++) {
            const u08* x   = input   + active[i] * 4;
            const i08* row = weights + active[i] * 4 * Stride;

            for (u32 r = 0; r < Rows; r++)
            for (u32 j = 0; j < 4   ; j++) sums[r] += static_cast<A>(x[j]) * static_cast<A>(row[r * 4 + j]);
        }
    }

    namespace Detail
    {

        template<typename ISA, Lowering::Dot D>
        [[clang::always_inline]]
        ISA::Vector SparseDot(
            const typename ISA::Vector sum,
            const typename ISA::Vector x  ,
            const typename ISA::Vector w
        ) noexcept
        {
            if constexpr (D == Lowering::Dot::Wide) return ISA::DotU08I08Wide(sum, x, w);
            else                                    return ISA::DotU08I08    (sum, x, w);
        }

        template<typename ISA, Lowering::Dot D, s00 Tile, u64 Column>
        [[clang::always_inline]]
        void SparseChunk(
                  Array<typename ISA::Vector, Tile>& sums   ,
            const u08*                               input  ,
            const i08*                               weights,
            const u32                                group
        ) noexcept
        {
            const auto x      = ISA::BroadcastU32(input + group * 4);
            const i08* column = weights + group * Column;

            UNROLL(full)
            for (s00 t = 0; t < Tile; t++) sums[t] = SparseDot<ISA, D>(sums[t], x, ISA::Load(column + t * ISA::Bytes));
        }

        template<typename ISA, s00 Tile, u64 Column>
        [[clang::always_inline]]
        void SparsePair(
                  Array<typename ISA::Vector, Tile>& sums   ,
            const u08*                               input  ,
            const i08*                               weights,
            const u32                                first  ,
            const u32                                next
        ) noexcept
        {
            const auto ones = ISA::BroadcastI16(1);

            const auto a = ISA::BroadcastU32(input + first * 4);
            const auto b = ISA::BroadcastU32(input + next  * 4);

            const i08* left  = weights + first * Column;
            const i08* right = weights + next  * Column;

            UNROLL(full)
            for (s00 t = 0; t < Tile; t++) {
                const auto low  = ISA::MaddubsI16(a, ISA::Load(left  + t * ISA::Bytes));
                const auto high = ISA::MaddubsI16(b, ISA::Load(right + t * ISA::Bytes));

                sums[t] = ISA::AddI32(sums[t], ISA::MaddI16(ISA::AddI16(low, high), ones));
            }
        }

        template<typename ISA>
        [[clang::always_inline]]
        ISA::Vector SparseWord(const u08* input, const u32 word) noexcept
        {
            u16 value;

            std::memcpy(&value, input + word * 2, sizeof(value));

            return ISA::BroadcastI32(static_cast<i32>(value));
        }

        template<typename ISA>
        [[clang::always_inline]]
        ISA::Vector SparseTwin(const u08* input, const u32 first, const u32 next) noexcept
        {
            u16 low ;
            u16 high;

            std::memcpy(&low , input + first * 2, sizeof(low ));
            std::memcpy(&high, input + next  * 2, sizeof(high));

            return ISA::BroadcastI32(static_cast<i32>(u32 { low } | u32 { high } << 16));
        }

        template<typename ISA, Lowering::Dot D>
        [[clang::always_inline]]
        void SparseWoven(
                  Array<typename ISA::Vector, 2>& sums   ,
            const typename ISA::Vector            x      ,
            const i08*                            weights,
            const u32                             first  ,
            const u32                             next
        ) noexcept
        {
            const auto left  = ISA::Load(weights + first * ISA::Bytes);
            const auto right = ISA::Load(weights + next  * ISA::Bytes);

            sums[0] = SparseDot<ISA, D>(sums[0], x, ISA::UnpackLoI16(left, right));
            sums[1] = SparseDot<ISA, D>(sums[1], x, ISA::UnpackHiI16(left, right));
        }

        template<typename ISA, Lowering::Dot D>
        [[clang::always_inline]]
        void SparseWovenLast(
                  Array<typename ISA::Vector, 2>& sums   ,
            const u08*                            input  ,
            const i08*                            weights,
            const u32                             word
        ) noexcept
        {
            const auto x    = SparseWord<ISA>(input, word);
            const auto left = ISA::Load(weights + word * ISA::Bytes);

            sums[0] = SparseDot<ISA, D>(sums[0], x, ISA::UnpackLoI16(left, ISA::Zero()));
            sums[1] = SparseDot<ISA, D>(sums[1], x, ISA::UnpackHiI16(left, ISA::Zero()));
        }

        template<typename ISA>
        [[clang::always_inline]]
        void SparseWovenPair(
                  Array<typename ISA::Vector, 2>& sums   ,
            const typename ISA::Vector            x      ,
            const typename ISA::Vector            y      ,
            const i08*                            weights,
            const u16*                            words
        ) noexcept
        {
            const auto ones = ISA::BroadcastI16(1);

            const auto a = ISA::Load(weights + words[0] * ISA::Bytes);
            const auto b = ISA::Load(weights + words[1] * ISA::Bytes);
            const auto c = ISA::Load(weights + words[2] * ISA::Bytes);
            const auto d = ISA::Load(weights + words[3] * ISA::Bytes);

            const auto low  = ISA::AddI16(
                ISA::MaddubsI16(x, ISA::UnpackLoI16(a, b)), ISA::MaddubsI16(y, ISA::UnpackLoI16(c, d))
            );
            const auto high = ISA::AddI16(
                ISA::MaddubsI16(x, ISA::UnpackHiI16(a, b)), ISA::MaddubsI16(y, ISA::UnpackHiI16(c, d))
            );

            sums[0] = ISA::AddI32(sums[0], ISA::MaddI16(low , ones));
            sums[1] = ISA::AddI32(sums[1], ISA::MaddI16(high, ones));
        }

        template<const Lowering::Stage& S, typename ISA>
        [[clang::always_inline]]
        void SparseLines(
            const u08*                            input  ,
            const i08*                            weights,
                  Array<typename ISA::Vector, 2>& sums
        ) noexcept
        {
            constexpr u32  Words  = S.Width / 2;
            constexpr s00  Sets   = S.Sets;
            constexpr u32  Take   = S.Pairs ? 4 : 2;
            constexpr u32  Step   = Sets * Take;
            constexpr bool Valued = NnzValued<ISA, Words>;

            static_assert(Lowering::Woven(S, ISA::Bytes), "a woven sparse stage has two sum vectors of one line");

            alignas(Alignment) NnzList<Words> list;

            alignas(Alignment) std::conditional_t<Valued, NnzList<Words>, Absent<0>> values;

            const u32 count = [&] {
                if constexpr (Valued) return NnzWords<ISA, Words, true >(input, list.data(), values.data());
                else                  return NnzWords<ISA, Words, false>(input, list.data(), nullptr      );
            }();

            const auto twin = [&](const u32 at) {
                if constexpr (Valued) return ISA::BroadcastU32(reinterpret_cast<const u08*>(values.data() + at));
                else                  return SparseTwin<ISA>(input, list[at], list[at + 1]);
            };

            Array<typename ISA::Vector, Sets, 2> sets;

            sets[0] = sums;

            for (s00 s = 1; s < Sets; s++)
            for (s00 t = 0; t < 2   ; t++) sets[s][t] = ISA::Zero();

            u32 i = 0;

            UNROLL(disable)
            for (; i + Step <= count; i += Step) {
                UNROLL(full)
                for (s00 s = 0; s < Sets; s++) {
                    const u32 first = i + static_cast<u32>(s) * Take;

                    if constexpr (S.Pairs)
                        SparseWovenPair<ISA>(sets[s], twin(first), twin(first + 2), weights, list.data() + first);
                    else
                        SparseWoven<ISA, S.Dot>(sets[s], twin(first), weights, list[first], list[first + 1]);
                }
            }

            if constexpr (S.Pairs) {
                UNROLL(disable)
                for (; i + 4 <= count; i += 4)
                    SparseWovenPair<ISA>(sets[0], twin(i), twin(i + 2), weights, list.data() + i);
            }

            UNROLL(disable)
            for (; i + 2 <= count; i += 2)
                SparseWoven<ISA, S.Dot>(sets[0], twin(i), weights, list[i], list[i + 1]);

            if (i < count) SparseWovenLast<ISA, S.Dot>(sets[0], input, weights, list[i]);

            for (s00 t = 0; t < 2; t++) {
                sums[t] = sets[0][t];

                for (s00 s = 1; s < Sets; s++) sums[t] = ISA::AddI32(sums[t], sets[s][t]);
            }
        }

    }

    template<const Lowering::Stage& S, typename ISA>
    [[clang::always_inline]]
    void Sparse(
        const u08*                                 input  ,
        const i08*                                 weights,
              Array<typename ISA::Vector, S.Tile>& sums
    ) noexcept
    {
        constexpr Interval X { .Min = S.Low      , .Max = S.High       };
        constexpr Interval W { .Min = S.WeightLow, .Max = S.WeightHigh };

        constexpr u32  Groups   = S.Width / 4;
        constexpr s00  Tile     = S.Tile;
        constexpr s00  Sets     = S.Sets;
        constexpr u32  Take     = S.Pairs ? 2 : 1;
        constexpr u32  Step     = Sets * Take;
        constexpr u64  Column   = u64 { S.Padded } * 4;
        constexpr bool Positive = S.Test == Lowering::Test::Positive;

        static_assert(
            S.Kind == Lowering::Kind::Dense && S.Form == Lowering::Form::Sparse,
            "Kernel::Sparse runs a sparse Dense stage"
        );
        static_assert(S.Width % 4 == 0 && !S.Wide, "a sparse stage reads 4-byte groups into a modular i32 sum");
        static_assert(Tile * ISA::Bytes == Column, "the tile covers the padded rows of a chunk column");
        static_assert(S.Padded >= S.Rows && Sets >= 1, "padding only adds rows, and a sparse stage has a set");
        static_assert(S.Test != Lowering::Test::None, "a sparse stage names its NNZ test");
        static_assert(!Positive || Lowering::NnzCmpgtSafe(X), "the cmpgt NNZ test needs NnzCmpgtSafe");

        if constexpr (Lowering::Woven(S, ISA::Bytes)) {
            Detail::SparseLines<S, ISA>(input, weights, sums);

            return;
        }

        static_assert(
            S.Dot == Lowering::Dot::Dpbusd || S.Dot == Lowering::Dot::Maddubs || S.Dot == Lowering::Dot::Wide,
            "a sparse stage dots u08 by i08"
        );
        static_assert(
            S.Dot != Lowering::Dot::Dpbusd || (ISA::VNNI && Lowering::VnniExact(X, W)),
            "vpdpbusd needs VNNI and VnniExact"
        );
        static_assert(
            S.Dot != Lowering::Dot::Maddubs || Lowering::MaddubsExact(X, W),
            "the saturating u08 by i08 dot needs MaddubsExact"
        );
        static_assert(
            !S.Pairs || (S.Dot == Lowering::Dot::Maddubs && Lowering::MaddubsPairExact(X, W)),
            "two chunks share one i16 sum only under MaddubsPairExact"
        );

        alignas(Alignment) NnzList<Groups> list;

        const u32 count = Nnz<ISA, Groups, Positive>(input, list.data());

        Array<typename ISA::Vector, Sets, Tile> sets;

        sets[0] = sums;

        for (s00 s = 1; s < Sets; s++)
        for (s00 t = 0; t < Tile; t++) sets[s][t] = ISA::Zero();

        u32 i = 0;

        UNROLL(disable)
        for (; i + Step <= count; i += Step) {
            UNROLL(full)
            for (s00 s = 0; s < Sets; s++) {
                const u32 first = i + static_cast<u32>(s) * Take;

                if constexpr (S.Pairs)
                    Detail::SparsePair<ISA, Tile, Column>(sets[s], input, weights, list[first], list[first + 1]);
                else
                    Detail::SparseChunk<ISA, S.Dot, Tile, Column>(sets[s], input, weights, list[first]);
            }
        }

        if constexpr (S.Pairs) {
            UNROLL(disable)
            for (; i + 2 <= count; i += 2)
                Detail::SparsePair<ISA, Tile, Column>(sets[0], input, weights, list[i], list[i + 1]);
        }

        UNROLL(disable)
        for (; i < count; i++) Detail::SparseChunk<ISA, S.Dot, Tile, Column>(sets[0], input, weights, list[i]);

        for (s00 t = 0; t < Tile; t++) {
            sums[t] = sets[0][t];

            for (s00 s = 1; s < Sets; s++) sums[t] = ISA::AddI32(sums[t], sets[s][t]);
        }
    }

}

#endif //MANTARAY_BACKEND_KERNEL_SPARSE_H
