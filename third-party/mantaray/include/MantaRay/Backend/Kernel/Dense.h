//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_BACKEND_KERNEL_DENSE_H
#define MANTARAY_BACKEND_KERNEL_DENSE_H

#include <algorithm>
#include <array>
#include <bit>
#include <cassert>
#include <cmath>
#include <cstring>
#include <span>
#include <type_traits>

#include "Pack.h"
#include "Reduce.h"
#include "Sparse.h"
#include "../../Common.h"
#include "../../IR/GraphIR.h"
#include "../../Lowering/Facts.h"
#include "../../Lowering/Program.h"
#include "../ISA/Scalar.h"

namespace MantaRay::Backend::Kernel
{

    template<typename ISA>
    consteval bool Holdable(const Lowering::Stage& stage)
    {
        const bool emulated = !ISA::PairDot && (stage.Dot == Lowering::Dot::Dpbusd  ||
                                                stage.Dot == Lowering::Dot::Maddubs ||
                                                stage.Dot == Lowering::Dot::Wide    ||
                                                stage.Dot == Lowering::Dot::Madd    );

        const bool forms = stage.Form == Lowering::Form::Grouped || stage.Form == Lowering::Form::Broadcast ||
                           stage.Form == Lowering::Form::RowDot;

        return stage.Kind == Lowering::Kind::Dense && !std::is_same_v<ISA, Backend::ISA::Scalar> && !emulated &&
               forms && stage.Input == IR::DType::U08 && stage.Weight == IR::DType::I08 &&
               ISA::Bytes == Alignment && stage.Width % ISA::Bytes == 0;
    }

    template<const auto& Program, s00 I, typename ISA>
    struct Dense
    {

        constexpr static Lowering::Stage Stage = Program.Stages[I];

        static_assert(Stage.Kind == Lowering::Kind::Dense, "Kernel::Dense runs a Dense stage");

        constexpr static u32 Inputs  = Stage.Width  ;
        constexpr static u32 Rows    = Stage.Rows   ;
        constexpr static u32 Buckets = Stage.Buckets;
        constexpr static u32 Lanes   = ISA::Bytes / sizeof(f32);

        constexpr static bool Real     = Stage.Weight  == IR::DType::F32;
        constexpr static bool Shifted  = Stage.Mode    == Lowering::Mode::ZeroPoint;
        constexpr static bool Scaled   = Stage.Requant == IR::Op::Dequantize;
        constexpr static bool Floating = Real || Scaled;
        constexpr static bool Biased   = Stage.Bias != 0;
        constexpr static bool Chained  = Stage.Reduction == IR::Reduction::BiasFirstFma;
        constexpr static bool Laned    = Stage.Reduction == IR::Reduction::Lanes16;
        constexpr static bool Packed   = Stage.Packed && Lowering::PackAbsorbable(Inputs / 2, ISA::Bytes);

        static_assert(Real == (Stage.Input == IR::DType::F32), "a Dense stage multiplies f32 by f32 or integers");
        static_assert(
            !Stage.Packed || (Stage.Input == IR::DType::U08 && Inputs % 2 == 0),
            "an absorbed pack order permutes the u08 columns of two perspectives"
        );
        static_assert(
            !Stage.Sparse || (Stage.Input == IR::DType::U08 && Stage.Weight == IR::DType::I08),
            "a sparse Dense stage multiplies u08 by i08"
        );
        static_assert(!Chained || Biased, "a BiasFirstFma Dense stage starts from its bias Parameter");

        constexpr static Lowering::Form Form = Stage.Form;

        constexpr static bool Scalar = std::is_same_v<ISA, Backend::ISA::Scalar>;

        constexpr static bool Emulated = !ISA::PairDot && (Stage.Dot == Lowering::Dot::Dpbusd  ||
                                                           Stage.Dot == Lowering::Dot::Maddubs ||
                                                           Stage.Dot == Lowering::Dot::Wide    ||
                                                           Stage.Dot == Lowering::Dot::Madd    );

        constexpr static bool Tiled   = !Scalar && (Form == Lowering::Form::Sparse ||
                                                    (!Emulated && (Form == Lowering::Form::Grouped ||
                                                                   Form == Lowering::Form::Broadcast)));
        constexpr static bool Spread  = Tiled && (Real || Form == Lowering::Form::Sparse);
        constexpr static bool Folded  = !Scalar && (Form == Lowering::Form::Lanes || Form == Lowering::Form::Serial);
        constexpr static bool Chunked = Tiled ? Form == Lowering::Form::Sparse : Stage.Sparse;

        constexpr static bool Blocked = Tiled && !Real && (Form == Lowering::Form::Grouped ||
                                                           Form == Lowering::Form::Broadcast);
        constexpr static bool Dotted  = !Scalar && !Emulated && Form == Lowering::Form::RowDot;

        constexpr static u32 Tile    = Stage.Tile;
        constexpr static u32 Padded  = Tiled ? Stage.Padded : Rows;
        constexpr static u32 Depth   = !Blocked                             ? 1 :
                                       Form      == Lowering::Form::Grouped ? 4 :
                                       Stage.Dot == Lowering::Dot::Madd     ? 2 : 1;
        constexpr static u32 Columns = (Inputs + Depth - 1) / Depth * Depth;
        constexpr static u32 Stride  = Spread || Blocked ? Padded : Rows;
        constexpr static u64 Column  = u64 { Padded } * Depth;

        constexpr static bool Woven = Tiled && Lowering::Woven(Stage, ISA::Bytes);

        static_assert(!Woven || Padded * 2 == ISA::Bytes, "a woven column is one line of every row's 2-byte word");

        constexpr static bool Widened = Stage.Dot == Lowering::Dot::Wide ||
                                        (Stage.Dot == Lowering::Dot::Maddubs && !ISA::Maddubs);
        constexpr static bool Doubled = Stage.Pairs && !Widened;

        constexpr static u32 Take = Doubled ? 2 : 1;

        static_assert(
            !Tiled || (Tile * Lanes == Padded && Padded >= Rows && Padded - Rows < Lanes),
            "a tiled Dense stage holds its rows, rounded up to the lane count, in Tile vectors"
        );
        static_assert(!Tiled || !Stage.Wide, "a tiled Dense stage sums in i32 or f32 lanes");
        static_assert(
            !Chunked || (Stage.Input == IR::DType::U08 && Stage.Weight == IR::DType::I08),
            "the Sparse form multiplies u08 by i08"
        );
        static_assert(!Folded || Real, "the Lanes and Serial forms run f32 stages");
        static_assert(
            !Folded || Form != Lowering::Form::Lanes || (Laned && Tile * Lanes == 16),
            "the Lanes form holds the 16 canonical partial sums of Lanes16"
        );
        static_assert(
            Form != Lowering::Form::Serial || (Rows == 1 && !Laned),
            "the Serial form runs one Sequential or BiasFirstFma row"
        );
        static_assert(!Real || !(Tiled || Folded) || Stage.Sets == 1, "an f32 form runs one accumulator set");
        static_assert(
            !Real || !(Tiled || Folded) ||
            Stage.Dot == (Chained || Laned ? Lowering::Dot::Fma : Lowering::Dot::MulAdd),
            "an f32 form multiplies in the declared reduction order"
        );
        static_assert(
            Floating || !Stage.Vector || Lowering::EpilogueFits32(Stage),
            "the integer vector epilogue needs EpilogueFits32"
        );
        static_assert(
            !Stage.BiasInit || (Lowering::BiasInit(Stage) && Stage.Vector && Biased),
            "accumulators start at the bias only under BiasInit, with the vector epilogue"
        );

        constexpr static Interval X { .Min = Stage.Low      , .Max = Stage.High       };
        constexpr static Interval W { .Min = Stage.WeightLow, .Max = Stage.WeightHigh };

        constexpr static bool Octets = Stage.Input == IR::DType::U08 && Stage.Weight == IR::DType::I08;
        constexpr static bool Shorts = Stage.Input == IR::DType::I16 && Stage.Weight == IR::DType::I16;
        constexpr static bool Words  = Stage.Input == IR::DType::I32 && Stage.Weight == IR::DType::I32;

        static_assert(
            !(Blocked || Dotted) || (!Stage.Wide && (Octets || Shorts || Words)),
            "the integer forms sum u08 by i08, i16 by i16 or i32 by i32 in modular i32 lanes"
        );
        static_assert(!Blocked || Form != Lowering::Form::Grouped || Octets, "the Grouped form multiplies u08 by i08");
        static_assert(
            !(Blocked || Dotted) || !Octets || Stage.Dot == Lowering::Dot::Dpbusd ||
            Stage.Dot == Lowering::Dot::Maddubs || Stage.Dot == Lowering::Dot::Wide,
            "a u08 by i08 form dots four bytes per lane"
        );
        static_assert(
            !(Blocked || Dotted) || !Shorts || Stage.Dot == Lowering::Dot::Madd,
            "an i16 by i16 form dots i16 pairs"
        );
        static_assert(
            !(Blocked || Dotted) || !Words || Stage.Dot == Lowering::Dot::MulLo,
            "an i32 by i32 form multiplies i32 lanes"
        );
        static_assert(
            !(Blocked || Dotted) || Stage.Dot != Lowering::Dot::Dpbusd ||
            (ISA::VNNI && Lowering::VnniExact(X, W)),
            "vpdpbusd needs VNNI and VnniExact"
        );
        static_assert(
            !(Blocked || Dotted) || Stage.Dot != Lowering::Dot::Maddubs || Lowering::MaddubsExact(X, W),
            "the saturating u08 by i08 dot needs MaddubsExact"
        );
        static_assert(
            !Blocked || !Stage.Pairs ||
            (Stage.Dot == Lowering::Dot::Maddubs && Lowering::MaddubsPairExact(X, W)),
            "two groups share one i16 sum only under MaddubsPairExact"
        );

        constexpr static s00 Budget = ISA::Registers - 4;
        constexpr static u32 Chunks = Tile == 0 ? 1 : static_cast<u32>((Tile + Budget - 1) / Budget);
        constexpr static u32 Block  = (Tile + Chunks - 1) / Chunks;

        constexpr static u32 Unrolled = 64;

        constexpr static i64 ZeroPoint = 32768;

        constexpr static i64 Divisor = Stage.Requant == IR::Op::Divide ? Stage.Factor.Numerator : 1;

        constexpr static f32 Factor = Scaled ? static_cast<f32>(Stage.Factor.Numerator) /
                                               static_cast<f32>(Stage.Factor.Denominator) : 1.0F;

        using Input  = IR::ElementOf<Stage.Input >;
        using Weight = IR::ElementOf<Stage.Weight>;
        using Output = IR::ElementOf<Stage.Output>;
        using Wrap   = std::conditional_t<Stage.Wrap == IR::DType::None, i64, IR::ElementOf<Stage.Wrap>>;

        using Sum  = std::conditional_t<Real, f32, std::conditional_t<Stage.Wide, i64, u32>>;
        using Bias = std::conditional_t<Floating, f32, i32>;

        using Accumulator = std::conditional_t<Real, typename ISA::VectorF, typename ISA::Vector>;

        static_assert(!Tiled || !Floating || std::is_same_v<Output, f32>, "a floating Dense stage stores f32");
        static_assert(
            !Blocked || (Depth * sizeof(Input) == 4 && Depth * sizeof(Weight) == 4),
            "a Blocked step broadcasts four bytes of inputs against Depth weights per row"
        );
        static_assert(
            !Blocked || (Stage.Sets >= 1 && (Stage.Sets == 1 || Chunks == 1)),
            "accumulator sets share the registers of one block"
        );

        constexpr static u32 Each = ISA::Bytes / sizeof(Weight);

        constexpr static u32 Group = std::is_same_v<Output, i32> ? 1 :
                                     std::is_same_v<Output, i16> ? 2 :
                                     std::is_same_v<Output, u08> ? 4 : 0;

        struct Parameters
        {

            alignas(Alignment) Array<Weight, Buckets, Stride * Columns> Weights;
            alignas(Alignment) Array<Bias  , Buckets, Padded          > Biases ;

            NO_UNIQUE_ADDRESS std::conditional_t<Shifted, Array<Sum, Buckets, Rows>, Absent<0>> Corrections;

        };

        constexpr static bool Holdable = Kernel::Holdable<ISA>(Stage);

        static_assert(
            !Holdable || ((Blocked || Dotted) && Octets && Inputs % ISA::Bytes == 0),
            "a Holdable stage runs the Grouped, Broadcast or RowDot kernel on whole u08 vectors"
        );

        struct Held
        {

            const ISA::Vector* Blocks;
            u32                At = 0;

            [[clang::always_inline]]
            constexpr Held operator +(const u32 offset) const noexcept
            { return { .Blocks = Blocks, .At = At + offset }; }

            [[clang::always_inline]]
            ISA::Vector Block() const noexcept { return Blocks[At / ISA::Bytes]; }

            [[clang::always_inline]]
            u08 operator [](const u32 k) const noexcept
            {
                using Lanes08 [[gnu::vector_size(ISA::Bytes)]] = u08;

                return std::bit_cast<Lanes08>((*this + k).Block())[(At + k) % ISA::Bytes];
            }

        };

        constexpr static u64 Generic(const u32 row, const u32 column) noexcept
        {
            if (Chunked       ) return (u64 { column } / 4 * Rows + row) * 4 + column % 4;
            if (Real && !Laned) return  u64 { column } * Rows + row;

            return u64 { row } * Inputs + column;
        }

        constexpr static u64 Position(const u32 row, const u32 column) noexcept
        {
            if (Woven) {
                const u32 lane = row % Lanes;
                const u32 word = lane / 4 * 8 + row / Lanes * 4 + lane % 4;

                return u64 { column / 2 } * ISA::Bytes + u64 { word } * 2 + column % 2;
            }

            if (Form == Lowering::Form::Sparse) return (u64 { column } / 4 * Padded + row) * 4 + column % 4;

            if (Spread) return u64 { column } * Padded + row;
            if (Folded) return u64 { row    } * Inputs + column;

            if (Blocked) return (u64 { column } / Depth * Padded + row) * Depth + column % Depth;

            return Generic(row, column);
        }

        constexpr static u32 Logical(const u32 column) noexcept
        { return static_cast<u32>(LogicalIndex<ISA, Packed>(column)); }

        template<typename W>
        static Sum Correction(const std::span<const W> row) noexcept
        {
            Sum total = 0;

            for (const W value : row) total += static_cast<Sum>(static_cast<Weight>(value));

            return total * static_cast<Sum>(ZeroPoint);
        }

        template<typename W, typename B>
        static void Assign(
                  Parameters&        parameters,
            const std::span<const W> weights   ,
            const std::span<const B> biases
        ) noexcept
        {
            const u32 stride = biases.size() == Rows ? 0 : Rows;

            assert(weights.size() == u64 { Buckets } * Rows * Inputs);
            assert(!Biased || biases.size() == Rows || biases.size() == u64 { Buckets } * Rows);

            if (Padded > Rows || Columns > Inputs)
                for (u32 bucket = 0; bucket < Buckets; bucket++) {
                    parameters.Weights[bucket].fill(Weight {});
                    parameters.Biases [bucket].fill(Bias   {});
                }

            for (u32 bucket = 0; bucket < Buckets; bucket++)
            for (u32 row    = 0; row    < Rows   ; row++   ) {
                const u64 first = (u64 { bucket } * Rows + row) * Inputs;
                const u64 bias  =  u64 { bucket } * stride + row;

                for (u32 column = 0; column < Inputs; column++)
                    parameters.Weights[bucket][Position(row, column)] =
                        static_cast<Weight>(weights[first + Logical(column)]);

                parameters.Biases[bucket][row] = Biased ? static_cast<Bias>(biases[bias]) : Bias {};

                if constexpr (Shifted) parameters.Corrections[bucket][row] = Correction(weights.subspan(first, Inputs));
            }
        }

        [[clang::always_inline]]
        static Sum Operand(const Input x) noexcept
        { return static_cast<Sum>(static_cast<i64>(x) - (Shifted ? ZeroPoint : 0)); }

        [[clang::always_inline]]
        static void Accumulate(
            const Parameters&  parameters,
            const Input* const input     ,
            const u32          bucket    ,
                  Sum* const   sums
        ) noexcept requires (!Real)
        {
            const Weight* weights = parameters.Weights[bucket].data();

            if constexpr (Chunked) Kernel::Sparse<Inputs, Rows>(input, weights, sums);
            else
                for (u32 row    = 0; row    < Rows  ; row++   )
                for (u32 column = 0; column < Inputs; column++)
                    sums[row] += Operand(input[column]) * static_cast<Sum>(weights[row * Inputs + column]);

            if constexpr (Shifted)
                for (u32 row = 0; row < Rows; row++) sums[row] += parameters.Corrections[bucket][row];
        }

        [[clang::always_inline]]
        static f32 Fold(std::array<f32, 16> lanes) noexcept
        {
            #pragma clang fp contract(off)

            for (u32 width = 8; width > 0    ; width /= 2)
            for (u32 lane  = 0; lane  < width; lane++    ) lanes[lane] += lanes[lane + width];

            return lanes[0];
        }

        [[clang::always_inline]]
        static f32 Lanes16(const f32* const input, const f32* const weights) noexcept
        {
            #pragma clang fp contract(off)

            Array<f32, 16> lanes {};

            for (u32 column = 0; column < Inputs; column++)
                lanes[column % 16] = std::fma(input[column], weights[column], lanes[column % 16]);

            return Fold(lanes);
        }

        [[clang::always_inline]]
        static void Accumulate(
            const Parameters&  parameters,
            const Input* const input     ,
            const u32          bucket    ,
                  Sum* const   sums
        ) noexcept requires (Real)
        {
            #pragma clang fp contract(off)

            const f32* weights = parameters.Weights[bucket].data();

            if (Laned) {
                for (u32 row = 0; row < Rows; row++) sums[row] = Lanes16(input, weights + row * Inputs);

                return;
            }

            for (u32 row = 0; row < Rows; row++) sums[row] = Chained ? parameters.Biases[bucket][row] : 0.0F;

            for (u32 column = 0; column < Inputs; column++)
            for (u32 row    = 0; row    < Rows  ; row++   ) {
                const f32 x = input  [column           ];
                const f32 w = weights[column * Rows + row];

                sums[row] = Chained ? std::fma(x, w, sums[row]) : sums[row] + x * w;
            }
        }

        [[clang::always_inline]]
        static ISA::VectorF Read(const f32* const address) noexcept
        {
            typename ISA::VectorF value;

            std::memcpy(&value, address, sizeof(value));

            return value;
        }

        [[clang::always_inline]]
        static f32 Fma(const f32 x, const f32 w, const f32 addend) noexcept
        {
            alignas(Alignment) Array<f32, Lanes> lanes;

            ISA::StoreF(lanes.data(), ISA::FmaF(ISA::BroadcastF(x), ISA::BroadcastF(w), ISA::BroadcastF(addend)));

            return lanes[0];
        }

        [[clang::always_inline]]
        static Array<Accumulator, Tile> Start(const Parameters& parameters, const u32 bucket) noexcept
        {
            const Bias* biases = parameters.Biases[bucket].data();

            Array<Accumulator, Tile> sums;

            UNROLL(full)
            for (u32 t = 0; t < Tile; t++)
                if constexpr (Real) sums[t] = Chained        ? ISA::LoadF(biases + t * Lanes) : ISA::ZeroF();
                else                sums[t] = Stage.BiasInit ? ISA::Load (biases + t * Lanes) : ISA::Zero ();

            return sums;
        }

        template<typename T>
        [[clang::always_inline]]
        static ISA::Vector Fetch(const T* const address) noexcept
        {
            typename ISA::Vector value;

            std::memcpy(&value, address, sizeof(value));

            return value;
        }

        [[clang::always_inline]]
        static ISA::Vector Splat(const Input* const address) noexcept
        { return ISA::BroadcastU32(reinterpret_cast<const u08*>(address)); }

        [[clang::always_inline]]
        static ISA::Vector Fetch(const Held input) noexcept { return input.Block(); }

        [[clang::always_inline]]
        static ISA::Vector Splat(const Held input) noexcept
        {
            using Lanes32 [[gnu::vector_size(ISA::Bytes)]] = u32;

            const Lanes32 groups = std::bit_cast<Lanes32>(input.Block());

            return ISA::BroadcastI32(static_cast<i32>(groups[input.At % ISA::Bytes / 4]));
        }

        [[clang::always_inline]]
        static ISA::Vector Product(const ISA::Vector sum, const ISA::Vector x, const ISA::Vector w) noexcept
        {
            static_assert(
                !Widened || Stage.Dot == Lowering::Dot::Wide || Lowering::MaddubsExact(X, W),
                "the exact u08 by i08 dot stands in for maddubs only under MaddubsExact"
            );

            if constexpr (Stage.Dot == Lowering::Dot::MulLo)     return ISA::AddI32(sum, ISA::MulLoI32(x, w));
            else if constexpr (Stage.Dot == Lowering::Dot::Madd) return ISA::DotI16(sum, x, w);
            else if constexpr (Widened)                          return ISA::DotU08I08Wide(sum, x, w);
            else                                                 return ISA::DotU08I08(sum, x, w);
        }

        [[clang::always_inline]]
        static void Single(
                  Array<Accumulator, Tile>& sums  ,
            const ISA::Vector               x     ,
            const Weight* const             column,
            const u32                       first
        ) noexcept
        {
            UNROLL(full)
            for (u32 t = first; t < std::min(first + Block, Tile); t++)
                sums[t] = Product(sums[t], x, ISA::Load(column + t * Each));
        }

        template<typename In>
        [[clang::always_inline]]
        static void Paired(
                  Array<Accumulator, Tile>& sums  ,
            const In                        input ,
            const Weight* const             column,
            const u32                       first
        ) noexcept
        {
            const auto ones = ISA::BroadcastI16(1);

            const auto a = Splat(input        );
            const auto b = Splat(input + Depth);

            UNROLL(full)
            for (u32 t = first; t < std::min(first + Block, Tile); t++) {
                const auto low  = ISA::MaddubsI16(a, ISA::Load(column          + t * Each));
                const auto high = ISA::MaddubsI16(b, ISA::Load(column + Column + t * Each));

                sums[t] = ISA::AddI32(sums[t], ISA::MaddI16(ISA::AddI16(low, high), ones));
            }
        }

        template<typename In>
        [[clang::always_inline]]
        static void Advance(
                  Array<Accumulator, Stage.Sets, Tile>& sets   ,
            const In                                    input  ,
            const Weight* const                         weights,
            const u32                                   block  ,
            const u32                                   first
        ) noexcept
        {
            UNROLL(full)
            for (u32 s = 0; s < Stage.Sets; s++) {
                const u32 at = block + s * Take;

                if constexpr (Doubled) Paired(sets[s], input + at * Depth, weights + at * Column, first);
                else                   Single(sets[s], Splat(input + at * Depth), weights + at * Column, first);
            }
        }

        template<typename In>
        [[clang::always_inline]]
        static void Columnar(
            const In                        input  ,
            const Weight* const             weights,
                  Array<Accumulator, Tile>& sums
        ) noexcept
        {
            static_assert(Blocked, "Grouped and integer Broadcast stages accumulate by input blocks");

            constexpr u32 Whole  = Inputs / Depth;
            constexpr u32 Round  = Stage.Sets * Take;
            constexpr u32 Rounds = Whole / Round * Round;

            Array<Accumulator, Stage.Sets, Tile> sets;

            sets[0] = sums;

            for (u32 s = 1; s < Stage.Sets; s++)
            for (u32 t = 0; t < Tile      ; t++) sets[s][t] = ISA::Zero();

            UNROLL(full)
            for (u32 first = 0; first < Tile; first += Block) {
                if (Columns / Depth * Tile <= Unrolled) {
                    UNROLL(full)
                    for (u32 block = 0; block < Rounds; block += Round) Advance(sets, input, weights, block, first);
                } else {
                    UNROLL(disable)
                    for (u32 block = 0; block < Rounds; block += Round) Advance(sets, input, weights, block, first);
                }

                u32 block = Rounds;

                if constexpr (Doubled)
                    for (; block + 2 <= Whole; block += 2)
                        Paired(sets[0], input + block * Depth, weights + block * Column, first);

                for (; block < Whole; block++)
                    Single(sets[0], Splat(input + block * Depth), weights + block * Column, first);

                if constexpr (Columns > Inputs) {
                    ALIGN_4 Array<Input, Depth> rest {};

                    std::copy_n(input + Whole * Depth, Inputs - Whole * Depth, rest.data());

                    Single(sets[0], Splat(rest.data()), weights + Whole * Column, first);
                }
            }

            for (u32 t = 0; t < Tile; t++) {
                sums[t] = sets[0][t];

                for (u32 s = 1; s < Stage.Sets; s++) sums[t] = ISA::AddI32(sums[t], sets[s][t]);
            }
        }

        template<typename In>
        [[clang::always_inline]]
        static void Across(
                  Array<typename ISA::Vector, Rows>& sums   ,
            const In                                 input  ,
            const Weight* const                      weights,
            const u32                                column
        ) noexcept
        {
            const auto x = Fetch(input + column);

            UNROLL(full)
            for (u32 row = 0; row < Rows; row++) {
                const Weight* own = weights + u64 { row } * Inputs + column;

                sums[row] = Product(sums[row], x, Inputs % Each == 0 ? ISA::Load(own) : Fetch(own));
            }
        }

        template<typename In>
        [[clang::always_inline]]
        static void Rowwise(
            const Parameters&   parameters,
            const In            input     ,
                  Output* const output    ,
            const u32           bucket
        ) noexcept
        {
            constexpr u32 Whole = Inputs / Each * Each;

            const Weight* weights = parameters.Weights[bucket].data();

            Array<typename ISA::Vector, Rows> sums;

            UNROLL(full)
            for (u32 row = 0; row < Rows; row++) sums[row] = ISA::Zero();

            if (Whole / Each * Rows <= Unrolled) {
                UNROLL(full)
                for (u32 column = 0; column < Whole; column += Each) Across(sums, input, weights, column);
            } else {
                UNROLL(disable)
                for (u32 column = 0; column < Whole; column += Each) Across(sums, input, weights, column);
            }

            UNROLL(full)
            for (u32 row = 0; row < Rows; row++) {
                Sum sum = static_cast<Sum>(ISA::ReduceI32(sums[row]));

                for (u32 column = Whole; column < Inputs; column++)
                    sum += Operand(input[column]) * static_cast<Sum>(weights[u64 { row } * Inputs + column]);

                output[row] = Finish(sum, parameters.Biases[bucket][row]);
            }
        }

        template<Lowering::Form F, typename In>
        [[clang::always_inline]]
        static void Accumulate(
            const Parameters&               parameters,
            const In                        input     ,
            const u32                       bucket    ,
                  Array<Accumulator, Tile>& sums
        ) noexcept
        {
            #pragma clang fp contract(off)

            static_assert(F == Form && Tiled, "a tiled Dense stage accumulates by its own form");

            if constexpr (F == Lowering::Form::Sparse)
                Kernel::Sparse<Stage, ISA>(input, parameters.Weights[bucket].data(), sums);
            else if constexpr (Real) {
                const f32* weights = parameters.Weights[bucket].data();

                UNROLL(full)
                for (u32 first  = 0; first  < Tile  ; first += Block)
                for (u32 column = 0; column < Inputs; column++      ) {
                    const auto x = ISA::BroadcastF(input[column]);

                    UNROLL(full)
                    for (u32 t = first; t < std::min(first + Block, Tile); t++) {
                        const auto w = ISA::LoadF(weights + u64 { column } * Padded + t * Lanes);

                        sums[t] = Chained ? ISA::FmaF(x, w, sums[t]) : ISA::AddF(sums[t], ISA::MulF(x, w));
                    }
                }
            } else {
                Columnar(input, parameters.Weights[bucket].data(), sums);
            }
        }

        [[clang::always_inline]]
        static f32 Tree(const f32* const input, const f32* const weights) noexcept
        {
            #pragma clang fp contract(off)

            constexpr u32 Whole = Inputs / Lanes * Lanes;

            Array<typename ISA::VectorF, Tile> sums;

            UNROLL(full)
            for (u32 t = 0; t < Tile; t++) sums[t] = ISA::ZeroF();

            for (u32 base = 0; base < Whole; base += 16)
            UNROLL(full)
            for (u32 t = 0; t < Tile; t++) {
                const u32 column = base + t * Lanes;

                if (column < Whole) sums[t] = ISA::FmaF(Read(input + column), Read(weights + column), sums[t]);
            }

            if (Whole == Inputs) return ReduceF<ISA, Tile>(sums);

            alignas(Alignment) Array<f32, 16> lanes;

            UNROLL(full)
            for (u32 t = 0; t < Tile; t++) ISA::StoreF(lanes.data() + t * Lanes, sums[t]);

            for (u32 column = Whole; column < Inputs; column++)
                lanes[column % 16] = Fma(input[column], weights[column], lanes[column % 16]);

            return Fold(lanes);
        }

        [[clang::always_inline]]
        static f32 Serial(const f32* const input, const f32* const weights, const f32 bias) noexcept
        {
            #pragma clang fp contract(off)

            constexpr u32 Whole = Inputs / Lanes * Lanes;

            if (Chained) {
                auto chain = ISA::BroadcastF(bias);

                for (u32 column = 0; column < Inputs; column++)
                    chain = ISA::FmaF(ISA::BroadcastF(input[column]), ISA::BroadcastF(weights[column]), chain);

                alignas(Alignment) Array<f32, Lanes> lanes;

                ISA::StoreF(lanes.data(), chain);

                return lanes[0];
            }

            alignas(Alignment) Array<f32, Inputs> products;

            for (u32 column = 0; column < Whole; column += Lanes)
                ISA::StoreF(products.data() + column, ISA::MulF(Read(input + column), Read(weights + column)));

            for (u32 column = Whole; column < Inputs; column++) products[column] = input[column] * weights[column];

            f32 sum = 0.0F;

            for (u32 column = 0; column < Inputs; column++) sum = sum + products[column];

            return sum;
        }

        [[clang::always_inline]]
        static i64 IntegerOf(const Sum sum, const Bias bias) noexcept
        {
            i64 value = Stage.Wide ? static_cast<i64>(sum) : static_cast<i64>(static_cast<i32>(sum));

            if (Stage.Requant == IR::Op::Divide    ) value /= Divisor;
            if (Stage.Requant == IR::Op::ShiftRight) value >>= Stage.Shift;

            if (Biased && !Scaled) value += static_cast<i64>(bias);

            return static_cast<Wrap>(value);
        }

        [[clang::always_inline]]
        static f32 FloatOf(const Sum sum, const Bias bias) noexcept
        {
            #pragma clang fp contract(off)

            const f32 real = Scaled ? static_cast<f32>(IntegerOf(sum, bias)) : 0.0F;

            if (Scaled && Biased && !Stage.Unfused) return std::fma(real, Factor, static_cast<f32>(bias));

            const f32 value = Scaled ? real * Factor : static_cast<f32>(sum);

            return Biased && !Chained ? value + static_cast<f32>(bias) : value;
        }

        [[clang::always_inline]]
        static Output Finish(const Sum sum, const Bias bias) noexcept
        {
            #pragma clang fp contract(off)

            constexpr bool Clamps  = Stage.Then != Lowering::Activation::None;
            constexpr bool Squares = Stage.Then == Lowering::Activation::SquaredClamp;

            constexpr i64 Low  = Stage.ThenLow ;
            constexpr i64 High = Stage.ThenHigh;

            if (Floating) {
                f32 x = FloatOf(sum, bias);

                if (Clamps ) x = std::min(std::max(x, static_cast<f32>(Low)), static_cast<f32>(High));
                if (Squares) x = x * x;

                return static_cast<Output>(x);
            }

            i64 x = IntegerOf(sum, bias);

            if (Clamps ) x = std::min(std::max(x, Low), High);
            if (Squares) x = x * x;

            return static_cast<Output>(x >> Stage.ThenShift);
        }

        [[clang::always_inline]]
        static ISA::VectorF Epilogue(const Accumulator sum, const f32* const bias) noexcept requires (Floating)
        {
            #pragma clang fp contract(off)

            constexpr bool Clamps  = Stage.Then != Lowering::Activation::None;
            constexpr bool Squares = Stage.Then == Lowering::Activation::SquaredClamp;

            constexpr f32 Low  = static_cast<f32>(Stage.ThenLow );
            constexpr f32 High = static_cast<f32>(Stage.ThenHigh);

            typename ISA::VectorF x;

            if constexpr (Real) x = Biased && !Chained ? ISA::AddF(sum, ISA::LoadF(bias)) : sum;
            else {
                auto value = sum;

                if (Stage.Wrap == IR::DType::I16)
                    value = ISA::template ShiftRightI32<16>(ISA::template ShiftLeftI32<16>(value));
                if (Stage.Wrap == IR::DType::I08)
                    value = ISA::template ShiftRightI32<24>(ISA::template ShiftLeftI32<24>(value));

                if (Stage.Wrap == IR::DType::U16) value = ISA::And(value, ISA::BroadcastI32(0xFFFF));
                if (Stage.Wrap == IR::DType::U08) value = ISA::And(value, ISA::BroadcastI32(0x00FF));

                const auto real = ISA::CvtI32F(value);

                if (Biased && !Stage.Unfused) x = ISA::FmaF(real, ISA::BroadcastF(Factor), ISA::LoadF(bias));
                else {
                    x = ISA::MulF(real, ISA::BroadcastF(Factor));

                    if (Biased && !Chained) x = ISA::AddF(x, ISA::LoadF(bias));
                }
            }

            if (Clamps ) x = ISA::MinF(ISA::BroadcastF(High), ISA::MaxF(ISA::BroadcastF(Low), x));
            if (Squares) x = ISA::MulF(x, x);

            return x;
        }

        [[clang::always_inline]]
        static ISA::Vector Epilogue(const Accumulator sum, const i32* const bias) noexcept requires (!Floating)
        {
            constexpr bool Clamps  = Stage.Then != Lowering::Activation::None;
            constexpr bool Squares = Stage.Then == Lowering::Activation::SquaredClamp;

            constexpr i32 Low  = static_cast<i32>(Stage.ThenLow );
            constexpr i32 High = static_cast<i32>(Stage.ThenHigh);

            constexpr s00 Shift = std::min<s00>(Stage.Shift    , 31);
            constexpr s00 Then  = std::min<s00>(Stage.ThenShift, 31);

            auto x = sum;

            if (Stage.Requant == IR::Op::ShiftRight) x = ISA::template ShiftRightI32<Shift>(x);

            if (Biased && !Stage.BiasInit) x = ISA::AddI32(x, ISA::Load(bias));

            if (Clamps ) x = ISA::MinI32(ISA::BroadcastI32(High), ISA::MaxI32(ISA::BroadcastI32(Low), x));
            if (Squares) x = ISA::MulLoI32(x, x);

            return ISA::template ShiftRightI32<Then>(x);
        }

        [[clang::always_inline]]
        static void Finish(
            const Parameters&               parameters,
            const u32                       bucket    ,
            const Array<Accumulator, Tile>& sums      ,
                  Output* const             output
        ) noexcept requires (Floating)
        {
            const f32* biases = parameters.Biases[bucket].data();

            alignas(Alignment) Array<f32, Padded> values;

            UNROLL(full)
            for (u32 t = 0; t < Tile; t++)
                ISA::StoreF(values.data() + t * Lanes, Epilogue(sums[t], biases + t * Lanes));

            std::copy_n(values.data(), Rows, output);
        }

        [[clang::always_inline]]
        static void Finish(
            const Parameters&               parameters,
            const u32                       bucket    ,
            const Array<Accumulator, Tile>& sums      ,
                  Output* const             output
        ) noexcept requires (!Floating && Stage.Vector)
        {
            const i32* biases = parameters.Biases[bucket].data();

            Array<typename ISA::Vector, Tile> values;

            UNROLL(full)
            for (u32 t = 0; t < Tile; t++) values[t] = Epilogue(sums[t], biases + t * Lanes);

            if constexpr (Group == 0) {
                alignas(Alignment) Array<i32, Padded> lanes;

                UNROLL(full)
                for (u32 t = 0; t < Tile; t++) ISA::Store(lanes.data() + t * Lanes, values[t]);

                for (u32 row = 0; row < Rows; row++) output[row] = static_cast<Output>(lanes[row]);
            } else {
                constexpr u32 Stored = (Tile + Group - 1) / Group;

                const auto at = [&](const u32 t) { return t < Tile ? values[t] : ISA::Zero(); };

                alignas(Alignment) Array<Output, Stored * Group * Lanes> lanes;

                UNROLL(full)
                for (u32 s = 0; s < Stored; s++) {
                    const u32 t = s * Group;

                    const auto packed = Group == 1 ? values[t]                      :
                                        Group == 2 ? ISA::PackI16(at(t), at(t + 1)) :
                                                     ISA::PackU08(
                                                         ISA::PackI16(at(t    ), at(t + 1)),
                                                         ISA::PackI16(at(t + 2), at(t + 3))
                                                     );

                    ISA::Store(lanes.data() + t * Lanes, packed);
                }

                std::copy_n(lanes.data(), Rows, output);
            }
        }

        [[clang::always_inline]]
        static void Finish(
            const Parameters&               parameters,
            const u32                       bucket    ,
            const Array<Accumulator, Tile>& sums      ,
                  Output* const             output
        ) noexcept requires (!Floating && !Stage.Vector)
        {
            alignas(Alignment) Array<Sum, Padded> lanes;

            UNROLL(full)
            for (u32 t = 0; t < Tile; t++) ISA::Store(lanes.data() + t * Lanes, sums[t]);

            for (u32 row = 0; row < Rows; row++) output[row] = Finish(lanes[row], parameters.Biases[bucket][row]);
        }

        template<typename In>
        [[clang::always_inline]]
        static void Run(
            const Parameters&   parameters,
            const In            input     ,
                  Output* const output    ,
            const u32           bucket
        ) noexcept
        {
            assert(bucket < Buckets);

            if constexpr (Tiled) {
                Array<Accumulator, Tile> sums = Start(parameters, bucket);

                Accumulate<Form>(parameters, input, bucket, sums);

                Finish(parameters, bucket, sums, output);
            } else if constexpr (Folded) {
                const f32* weights = parameters.Weights[bucket].data();
                const f32* biases  = parameters.Biases [bucket].data();

                for (u32 row = 0; row < Rows; row++) {
                    const f32* own = weights + row * Inputs;

                    if constexpr (Laned) output[row] = Finish(Tree  (input, own             ), biases[row]);
                    else                 output[row] = Finish(Serial(input, own, biases[row]), biases[row]);
                }
            } else if constexpr (Dotted) {
                Rowwise(parameters, input, output, bucket);
            } else {
                Array<Sum, Rows> sums {};

                Accumulate(parameters, input, bucket, sums.data());

                for (u32 row = 0; row < Rows; row++) output[row] = Finish(sums[row], parameters.Biases[bucket][row]);
            }
        }

    };

}

#endif //MANTARAY_BACKEND_KERNEL_DENSE_H
