//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_IO_LOADER_H
#define MANTARAY_IO_LOADER_H

#include <algorithm>
#include <bit>
#include <cmath>
#include <cstddef>
#include <cstring>
#include <functional>
#include <limits>
#include <span>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

#include "Layout.h"
#include "../Common.h"
#include "../Model.h"
#include "../IR/GraphIR.h"

namespace MantaRay
{

    enum class LoadStatus : u08 {
        Ok, SizeMismatch, BadPadding, BoundViolation, NotFinite, Truncated, RangeUnverified, BadHeader, BadEncoding
    };

    struct LoadResult
    {

        LoadStatus Status = LoadStatus::Ok;
        u16        Tensor = 0;
        u64        Index  = 0;

        constexpr explicit operator bool() const noexcept { return Status == LoadStatus::Ok; }

        [[nodiscard]]
        constexpr std::string_view Message() const noexcept
        {
            switch (Status) {
                case LoadStatus::Ok             : return "ok"              ;
                case LoadStatus::SizeMismatch   : return "size mismatch"   ;
                case LoadStatus::BadPadding     : return "bad padding"     ;
                case LoadStatus::BoundViolation : return "bound violation" ;
                case LoadStatus::NotFinite      : return "not finite"      ;
                case LoadStatus::Truncated      : return "truncated"       ;
                case LoadStatus::RangeUnverified: return "range unverified";
                case LoadStatus::BadHeader      : return "bad header"      ;
                case LoadStatus::BadEncoding    : return "bad encoding"    ;
            }

            return "unknown status";
        }

    };

}

namespace MantaRay::IO
{

    namespace Detail
    {

        template<typename M, u16... I>
        auto Allocate(const std::integer_sequence<u16, I...>)
        {
            return std::tuple {
                std::vector<IR::ElementOf<M::Graph.Tensors[I].Type>>(IR::ElementsOf(M::Graph.Tensors[I]))...
            };
        }

    }

    template<typename M>
    class Tensors
    {

        using Indices = std::make_integer_sequence<u16, M::Graph.TensorCount>;

        constexpr static IR::Diagnostic Arrangement = CheckLayout(M::Graph);
        constexpr static s00            Reported    = Arrangement.Ok ? 0 : Arrangement.Text.size();
        constexpr static auto           Report      = MantaRay::Detail::Split<Reported>(Arrangement.Text);

        decltype(Detail::Allocate<M>(Indices {})) Values = Detail::Allocate<M>(Indices {});

        public:
        template<u16 I>
        using Element = IR::ElementOf<M::Graph.Tensors[I].Type>;

        Tensors() { static_assert(MantaRay::Detail::Rejected<Report>, "the file layout cannot hold a tensor"); }

        template<u16 I>
        [[nodiscard]]
        std::span<const Element<I>> View() const noexcept { return std::get<I>(Values); }
        template<u16 I>
        [[nodiscard]]
        std::span<      Element<I>> View()       noexcept { return std::get<I>(Values); }

    };

    namespace Detail
    {

        template<typename M>
        constexpr inline auto PlanOf = Arrange<ChunkCount(M::Graph)>(M::Graph);

        template<typename M>
        using Starts = Array<u64, ChunkCount(M::Graph) + 1>;

        template<typename T>
        T LittleEndian(const T value) noexcept
        {
            if constexpr (std::endian::native == std::endian::little || sizeof(T) == 1) return value;
            else {
                using U = std::conditional_t<sizeof(T) == 2, u16, std::conditional_t<sizeof(T) == 4, u32, u64>>;

                return std::bit_cast<T>(std::byteswap(std::bit_cast<U>(value)));
            }
        }

        template<typename T>
        T ReadLittle(const std::span<const std::byte> bytes, const u64 at) noexcept
        {
            T value;

            std::memcpy(&value, bytes.data() + at, sizeof(T));

            return LittleEndian(value);
        }

        template<typename T>
        void WriteLittle(std::vector<std::byte>& bytes, const u64 at, const T value) noexcept
        {
            const T little = LittleEndian(value);

            std::memcpy(bytes.data() + at, &little, sizeof(T));
        }

        inline u64 ReadUnsigned(const std::span<const std::byte> bytes, const u64 at, const u32 width) noexcept
        {
            u64 value = 0;

            for (u32 i = 0; i < width; i++) value |= u64 { std::to_integer<u08>(bytes[at + i]) } << (8 * i);

            return value;
        }

        inline void AppendUnsigned(std::vector<std::byte>& bytes, const u64 value, const u32 width)
        {
            for (u32 i = 0; i < width; i++)
                bytes.push_back(std::byte { static_cast<u08>(i < 8 ? value >> (8 * i) : 0) });
        }

        inline u64 LebLength(const std::span<const std::byte> bytes, const u64 at) noexcept
        {
            for (u64 i = at; i < bytes.size(); i++)
                if ((std::to_integer<u08>(bytes[i]) & 0x80) == 0) return i - at + 1;

            return 0;
        }

        inline u64 SkipLeb(const std::span<const std::byte> bytes, u64 position, const u64 count) noexcept
        {
            for (u64 i = 0; i < count && position <= bytes.size(); i++) {
                const u64 length = LebLength(bytes, position);

                position = length == 0 ? bytes.size() + 1 : position + length;
            }

            return position;
        }

        template<typename S>
        bool DecodeLeb(const std::span<const std::byte> bytes, const u64 at, const u64 length, S& value) noexcept
        {
            constexpr bool Real    = std::is_floating_point_v<S>;
            constexpr u64  Longest = (8 * sizeof(S) + 6) / 7;

            if (length > Longest) return false;

            u64 bits = 0;

            for (u64 i = 0; i < length; i++)
                bits |= u64 { std::to_integer<u08>(bytes[at + i]) & 0x7Fu } << (7 * i);

            const bool negative = !Real && (std::to_integer<u08>(bytes[at + length - 1]) & 0x40) != 0;
            const i64  number   = static_cast<i64>(negative ? bits | ~u64 { 0 } << (7 * length) : bits);

            value = Real ? static_cast<S>(std::bit_cast<f32>(static_cast<u32>(bits))) : static_cast<S>(number);

            if (Real) return bits <= std::numeric_limits<u32>::max();

            return number >= std::numeric_limits<S>::lowest() && number <= std::numeric_limits<S>::max();
        }

        template<typename S>
        void AppendLeb(std::vector<std::byte>& bytes, const S value)
        {
            constexpr bool Real = std::is_floating_point_v<S>;

            i64  rest = Real ? i64 { std::bit_cast<u32>(static_cast<f32>(value)) } : static_cast<i64>(value);
            bool more = true;

            while (more) {
                const u08 low = static_cast<u08>(rest & 0x7F);

                rest >>= 7;
                more   = Real ? rest != 0 : rest != ((low & 0x40) != 0 ? -1 : 0);

                bytes.push_back(std::byte { static_cast<u08>(more ? low | 0x80 : low) });
            }
        }

        inline std::byte PadByte(const IR::Padding padding, const u64 offset) noexcept
        {
            const std::byte bullet = static_cast<std::byte>(Padding[offset % Padding.size()]);

            return padding == IR::Padding::Bullet ? bullet : std::byte {};
        }

        template<typename F>
        void Walk(const IR::Tensor& tensor, const Chunk& chunk, const F& visit)
        {
            constexpr u32 Tile = 64;

            const u32 rows    = tensor.Rows / chunk.Count;
            const u32 columns = tensor.Columns;

            for (u32 top  = 0   ; top  < rows                          ; top  += Tile)
            for (u32 left = 0   ; left < columns                       ; left += Tile)
            for (u32 r    = top ; r    < std::min(top  + Tile, rows   ); r++         )
            for (u32 k    = left; k    < std::min(left + Tile, columns); k++         )
                visit(FileIndex(tensor, r, k, chunk.Count), (u64 { chunk.Bucket } * rows + r) * columns + k);
        }

        struct Findings
        {

            LoadResult Encoding {};
            LoadResult Bound    {};
            LoadResult Finite   {};

            void Record(const LoadResult result) noexcept
            {
                LoadResult& first = result.Status == LoadStatus::BadEncoding    ? Encoding :
                                    result.Status == LoadStatus::BoundViolation ? Bound    :
                                                                                  Finite   ;

                const bool earlier = result.Tensor == first.Tensor && result.Index < first.Index;

                if (first || earlier) first = result;
            }

            [[nodiscard]]
            LoadResult First() const noexcept { return !Encoding ? Encoding : !Bound ? Bound : Finite; }

        };

        template<typename M>
        LoadResult Scan(const std::span<const std::byte> bytes, Starts<M>& starts) noexcept
        {
            constexpr bool Compressed = M::Graph.File.Encoding == IR::Encoding::Leb128;

            u64 position = 0;

            for (s00 c = 0; c < PlanOf<M>.Chunks.size(); c++) {
                const Chunk& chunk  = PlanOf<M>.Chunks[c];
                const bool   header = chunk.Kind == IR::ItemKind::Constant || chunk.Kind == IR::ItemKind::Text;
                const bool   leb    = chunk.Kind == IR::ItemKind::Tensor   && Compressed;

                const u64        remaining = bytes.size() - position;
                const LoadResult truncated {
                    .Status = LoadStatus::Truncated,
                    .Tensor = chunk.Tensor,
                    .Index  = position
                };

                starts[c] = position;

                if (!leb && chunk.Bytes > remaining) return truncated;

                const u64 value = header ? ReadUnsigned(bytes, position, chunk.Bytes) : 0;

                if (chunk.Kind == IR::ItemKind::Constant && value != chunk.Value)
                    return { .Status = LoadStatus::BadHeader, .Index = position };

                const u64 text   = chunk.Kind == IR::ItemKind::Text ? value : 0;
                const u64 values = leb ? chunk.Bytes / IR::BytesOf(M::Graph.Tensors[chunk.Tensor].Stored) : 0;

                if (!leb && text > remaining - chunk.Bytes) return truncated;

                position = leb ? SkipLeb(bytes, position, values) : position + chunk.Bytes + text;

                if (position > bytes.size()) return truncated;
            }

            starts.back() = position;

            return {};
        }

        [[nodiscard]]
        inline LoadResult CheckSize(
            const std::span<const std::byte> bytes  ,
            const u64                        payload,
            const IR::Padding                padding
        ) noexcept
        {
            const bool exact  = bytes.size() == payload;
            const bool padded = padding != IR::Padding::Exact && bytes.size() == PaddedSize(payload);

            if (!exact && !padded) return { .Status = LoadStatus::SizeMismatch, .Index = bytes.size() };

            for (u64 i = payload; i < bytes.size(); i++)
                if (bytes[i] != PadByte(padding, i - payload)) return { .Status = LoadStatus::BadPadding, .Index = i };

            return {};
        }

        template<typename M, u16 I, typename S>
        LoadStatus Quantize(const S stored, typename Tensors<M>::template Element<I>& value) noexcept
        {
            using T = Tensors<M>::template Element<I>;

            constexpr IR::Tensor Spec      = M::Graph.Tensors[I];
            constexpr Interval   Bounds    = IR::BoundsOf(Spec);
            constexpr bool       Real      = IR::IsFloat(Spec.Type  );
            constexpr bool       Float     = IR::IsFloat(Spec.Stored);
            constexpr bool       Clipped   = Defined(Spec.ClipLow);
            constexpr bool       Truncates = Spec.Rounding == IR::Rounding::Truncate;

            constexpr f32 Scale = static_cast<f32>(ToDouble(Spec.Quantization));
            constexpr f32 Low   = Clipped ? static_cast<f32>(ToDouble(Spec.ClipLow  * Spec.Quantization)) : 0;
            constexpr f32 High  = Clipped ? static_cast<f32>(ToDouble(Spec.ClipHigh * Spec.Quantization)) : 0;

            if (Float && !std::isfinite(static_cast<f32>(stored)))
                return LoadStatus::NotFinite;

            if (Real) {
                value = static_cast<T>(stored);

                return LoadStatus::Ok;
            }

            const f32 scaled  = static_cast<f32>(stored) * Scale;
            const f32 clipped = Clipped   ? std::clamp(scaled, Low, High) : scaled;
            const f32 rounded = Truncates ? std::trunc(clipped)           : std::round(clipped);
            const f64 integer = Float     ? static_cast<f64>(rounded)     : static_cast<f64>(stored);

            if (integer < static_cast<f64>(Bounds.Min) || integer > static_cast<f64>(Bounds.Max))
                return LoadStatus::BoundViolation;

            value = static_cast<T>(integer);

            return LoadStatus::Ok;
        }

        template<typename M, u16 I, typename S>
        LoadResult Convert(const S stored, const u64 index, typename Tensors<M>::template Element<I>& value) noexcept
        {
            const LoadStatus status = Quantize<M, I>(stored, value);

            if (status == LoadStatus::Ok) return {};

            return { .Status = status, .Tensor = I, .Index = index };
        }

        template<typename M, u16 I>
        void DecodeChunk(
            const std::span<const std::byte> bytes   ,
            const u64                        at      ,
            const Chunk&                     chunk   ,
                  Tensors<M>&                tensors ,
                  Findings&                  findings
        ) noexcept
        {
            using T = Tensors<M>::template Element<I>;
            using S = IR::ElementOf<M::Graph.Tensors[I].Stored>;

            constexpr IR::Tensor Spec       = M::Graph.Tensors[I];
            constexpr bool       Compressed = M::Graph.File.Encoding == IR::Encoding::Leb128;

            const u32 rows = Spec.Rows / chunk.Count;

            std::vector<S> stored(Compressed ? u64 { rows } * Spec.Columns : 0);

            u64 position = at;

            for (S& value : stored) {
                const u64 length = LebLength(bytes, position);

                if (!DecodeLeb(bytes, position, length, value))
                    findings.Record({ .Status = LoadStatus::BadEncoding, .Tensor = I, .Index = position });

                position += length;
            }

            const std::span<T> values = tensors.template View<I>();

            const auto fetch = [&](const u64 file) {
                return Compressed ? stored[file] : ReadLittle<S>(bytes, at + file * sizeof(S));
            };

            bool clean = true;

            constexpr u32 Edge = 64;

            const u32 columns = Spec.Columns;

            const bool down = rows > 1 && FileIndex(Spec, 1, 0, chunk.Count) == FileIndex(Spec, 0, 0, chunk.Count) + 1;

            Array<T, Edge, Edge> block;

            const auto convert = [&](const u32 row, const u32 column, const u32 top, const u32 left) {
                T value {};

                clean &= Quantize<M, I>(fetch(FileIndex(Spec, top + row, left + column, chunk.Count)), value) ==
                         LoadStatus::Ok;

                block[row][column] = value;
            };

            for (u32 top  = 0; top  < rows   ; top  += Edge)
            for (u32 left = 0; left < columns; left += Edge) {
                const u32 height = std::min(Edge, rows    - top );
                const u32 width  = std::min(Edge, columns - left);

                if (down) {
                    for (u32 c = 0; c < width ; c++)
                    for (u32 r = 0; r < height; r++) convert(r, c, top, left);
                } else {
                    for (u32 r = 0; r < height; r++)
                    for (u32 c = 0; c < width ; c++) convert(r, c, top, left);
                }

                for (u32 r = 0; r < height; r++)
                    std::copy_n(
                        block[r].data(),
                        width,
                        values.subspan((u64 { chunk.Bucket } * rows + top + r) * columns + left).begin()
                    );
            }

            if (clean) return;

            Walk(Spec, chunk, [&](const u64 file, const u64 index) {
                if (const LoadResult result = Convert<M, I>(fetch(file), index, values[index]); !result)
                    findings.Record(result);
            });
        }

        template<typename M>
        LoadResult Decode(const std::span<const std::byte> bytes, const Starts<M>& starts, Tensors<M>& tensors) noexcept
        {
            Findings findings {};

            [&]<s00... C>(const std::index_sequence<C...>) {
                ([&] {
                    constexpr Chunk Item = PlanOf<M>.Chunks[C];

                    if constexpr (Item.Kind == IR::ItemKind::Tensor)
                        DecodeChunk<M, Item.Tensor>(bytes, starts[C], Item, tensors, findings);
                }(), ...);
            }(std::make_index_sequence<PlanOf<M>.Chunks.size()> {});

            return findings.First();
        }

        template<typename M, u16 I>
        LoadResult FoldTensor(Tensors<M>& tensors) noexcept
        {
            using T = Tensors<M>::template Element<I>;
            using W = std::conditional_t<std::is_floating_point_v<T>, f32, i64>;

            constexpr IR::Tensor Spec   = M::Graph.Tensors[I];
            constexpr u16        Base   = static_cast<u16>(Spec.Base   - 1);
            constexpr u16        Factor = static_cast<u16>(Spec.Factor - 1);
            constexpr IR::Tensor Tile   = M::Graph.Tensors[Factor];
            constexpr Interval   Range  = IR::RangeOf(Spec.Type);
            constexpr bool       Real   = IR::IsFloat(Spec.Type);

            const std::span<      T> values = tensors.template View<I>();
            const std::span<const T> base   = std::as_const(tensors).template View<Base  >();
            const std::span<const T> factor = std::as_const(tensors).template View<Factor>();

            for (u32 r = 0; r < Spec.Rows   ; r++)
            for (u32 c = 0; c < Spec.Columns; c++) {
                const u64 index = u64 { r } * Spec.Columns + c;
                const u64 other = u64 { r % Tile.Rows } * Tile.Columns + c % Tile.Columns;
                const W   sum   = static_cast<W>(base[index]) + static_cast<W>(factor[other]);

                const bool outside = Real ? !std::isfinite(sum)
                                          : static_cast<i64>(sum) < Range.Min || static_cast<i64>(sum) > Range.Max;

                if (outside) return { Real ? LoadStatus::NotFinite : LoadStatus::BoundViolation, I, index };

                values[index] = static_cast<T>(sum);
            }

            return {};
        }

        template<typename M>
        LoadResult Fold(Tensors<M>& tensors) noexcept
        {
            LoadResult result {};

            [&]<u16... I>(const std::integer_sequence<u16, I...>) {
                ([&] {
                    if constexpr (M::Graph.Tensors[I].Role == IR::Role::Folded)
                        if (result) result = FoldTensor<M, I>(tensors);
                }(), ...);
            }(std::make_integer_sequence<u16, M::Graph.TensorCount> {});

            return result;
        }

        template<typename M, typename F>
        void Visit(const Tensors<M>& tensors, const u16 tensor, const F& visit)
        {
            [&]<u16... I>(const std::integer_sequence<u16, I...>) {
                ((I == tensor ? visit(tensors.template View<I>()) : void()), ...);
            }(std::make_integer_sequence<u16, M::Graph.TensorCount> {});
        }

        template<typename T>
        Interval Extremes(const std::span<const T> row, const s00 active)
        {
            std::vector<i64> values(row.size());

            std::ranges::transform(row, values.begin(), [](const T value) { return static_cast<i64>(value); });

            const s00 count = std::min(active, values.size());

            Interval sum {};

            std::partial_sort(values.begin(), values.begin() + count, values.end());

            for (s00 k = 0; k < count; k++) sum.Min += std::min<i64>(values[k], 0);

            std::partial_sort(values.begin(), values.begin() + count, values.end(), std::greater<> {});

            for (s00 k = 0; k < count; k++) sum.Max += std::max<i64>(values[k], 0);

            return sum;
        }

        template<typename M>
        void Bound(const Tensors<M>& tensors, const u16 node, const u32 lane, Interval& sum)
        {
            const IR::Node& spec   = M::Graph.Nodes[node];
            const u16       tensor = static_cast<u16>(spec.Tensor - 1);

            if (spec.Operation == IR::Op::Parameter) {
                Visit(tensors, tensor, [&](const auto values) {
                    const i64 value = static_cast<i64>(values[spec.Begin + lane]);

                    sum.Min += std::min<i64>(value, 0);
                    sum.Max += std::max<i64>(value, 0);
                });

                return;
            }

            if (spec.Operation == IR::Op::SparseMatmul) {
                const IR::Binding& binding = M::Graph.Bindings[M::Graph.Nodes[spec.Inputs[0]].Binding - 1];

                const u64 row = u64 { spec.Begin + lane } * M::Graph.Tensors[tensor].Columns + spec.Offset;

                Visit(tensors, tensor, [&](const auto values) {
                    const Interval extremes = Extremes(values.subspan(row, binding.InputSize), binding.MaxActive);

                    sum.Min += extremes.Min;
                    sum.Max += extremes.Max;
                });

                return;
            }

            for (u16 k = 0; k < spec.InputCount; k++) Bound(tensors, spec.Inputs[k], lane, sum);
        }

        template<typename M>
        LoadResult Verify(const Tensors<M>& tensors)
        {
            for (u16 c = 0; c < M::Result.Checks; c++) {
                const u16      node   = M::Result.Verified[c];
                const Interval target = IR::RangeOf(M::Graph.Nodes[node].Type);

                for (u32 lane = 0; lane < M::Facts[node].Size; lane++) {
                    Interval sum {};

                    Bound(tensors, M::Graph.Nodes[node].Inputs[0], lane, sum);

                    if (sum.Min < target.Min || sum.Max > target.Max)
                        return { .Status = LoadStatus::RangeUnverified, .Tensor = node, .Index = lane };
                }
            }

            return {};
        }

        template<typename M, u16 I, typename S>
        S Encode(const typename Tensors<M>::template Element<I> value) noexcept
        {
            constexpr IR::Tensor Spec      = M::Graph.Tensors[I];
            constexpr bool       Quantized = IR::IsFloat(Spec.Stored) && !IR::IsFloat(Spec.Type);
            constexpr f64        Half      = Spec.Rounding == IR::Rounding::Truncate ? 0.5 : 0;

            if (!Quantized) return static_cast<S>(value);

            const f64 integer = static_cast<f64>(value);
            const f64 nudged  = integer > 0 ? integer + Half : integer < 0 ? integer - Half : integer;

            return static_cast<S>(nudged / ToDouble(Spec.Quantization));
        }

        template<typename M, u16 I>
        void SaveTensor(const Tensors<M>& tensors, const Chunk& chunk, std::vector<std::byte>& bytes)
        {
            using T = Tensors<M>::template Element<I>;
            using S = IR::ElementOf<M::Graph.Tensors[I].Stored>;

            constexpr IR::Tensor Spec       = M::Graph.Tensors[I];
            constexpr bool       Compressed = M::Graph.File.Encoding == IR::Encoding::Leb128;

            const u32 rows  = Spec.Rows / chunk.Count;
            const u64 count = u64 { rows } * Spec.Columns;
            const u64 at    = bytes.size();

            const std::span<const T> values = tensors.template View<I>();

            std::vector<S> stored(Compressed ? count : 0);

            bytes.resize(Compressed ? at : at + count * sizeof(S));

            Walk(Spec, chunk, [&](const u64 file, const u64 index) {
                const S value = Encode<M, I, S>(values[index]);

                if (Compressed) stored[file] = value;
                else            WriteLittle(bytes, at + file * sizeof(S), value);
            });

            for (const S value : stored) AppendLeb(bytes, value);
        }

        template<typename M, s00 C>
        void SaveChunk(const Tensors<M>& tensors, std::vector<std::byte>& bytes)
        {
            constexpr Chunk Item = PlanOf<M>.Chunks[C];

            if constexpr (Item.Kind == IR::ItemKind::Tensor) SaveTensor<M, Item.Tensor>(tensors, Item, bytes);
            else                                             AppendUnsigned(bytes, Item.Value, Item.Bytes);
        }

    }

    template<typename M>
    [[nodiscard]]
    LoadResult Load(const std::span<const std::byte> bytes, Tensors<M>& tensors) noexcept
    {
        constexpr IR::Padding Scheme = M::Graph.File.Padding;

        Detail::Starts<M> starts {};

        if (const LoadResult result = Detail::Scan<M>(bytes, starts); !result) return result;

        if (const LoadResult result = Detail::CheckSize(bytes, starts.back(), Scheme); !result) return result;

        Tensors<M> loaded {};

        if (const LoadResult result = Detail::Decode<M>(bytes, starts, loaded); !result) return result;
        if (const LoadResult result = Detail::Fold  <M>(loaded               ); !result) return result;
        if (const LoadResult result = Detail::Verify<M>(loaded               ); !result) return result;

        tensors = std::move(loaded);

        return {};
    }

    template<typename M>
    [[nodiscard]]
    std::vector<std::byte> Save(const Tensors<M>& tensors)
    {
        constexpr IR::Padding Scheme = M::Graph.File.Padding;

        std::vector<std::byte> bytes {};

        bytes.reserve(Detail::PlanOf<M>.FileSize);

        [&]<s00... C>(const std::index_sequence<C...>) {
            (Detail::SaveChunk<M, C>(tensors, bytes), ...);
        }(std::make_index_sequence<Detail::PlanOf<M>.Chunks.size()> {});

        const u64 payload = bytes.size();
        const u64 size    = Scheme == IR::Padding::Exact ? payload : PaddedSize(payload);

        for (u64 i = payload; i < size; i++) bytes.push_back(Detail::PadByte(Scheme, i - payload));

        return bytes;
    }

}

#endif //MANTARAY_IO_LOADER_H
