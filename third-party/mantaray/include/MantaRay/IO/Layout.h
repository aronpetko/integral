//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_IO_LAYOUT_H
#define MANTARAY_IO_LAYOUT_H

#include <string_view>

#include "../Common.h"
#include "../IR/Analysis.h"
#include "../IR/GraphIR.h"

namespace MantaRay::IO
{

    constexpr inline std::string_view Padding      = "bullet";
    constexpr inline s00              PaddingBlock = 64;

    constexpr s00 PaddedSize(const s00 payload) { return (payload + PaddingBlock - 1) / PaddingBlock * PaddingBlock; }

    struct Chunk
    {

        IR::ItemKind Kind   = IR::ItemKind::None;
        u16          Tensor = 0;
        u16          Bucket = 0;
        u16          Count  = 1;
        u32          Bytes  = 0;
        u64          Offset = 0;
        u64          Value  = 0;

    };

    template<s00 N>
    struct Plan
    {

        Array<Chunk, N> Chunks {};

        u64 Payload  = 0;
        u64 FileSize = 0;

    };

    constexpr u64 FileIndex(const IR::Tensor& tensor, const u32 row, const u32 column, const u16 count = 1)
    {
        const u32 rows    = tensor.Rows / count;
        const u32 columns = tensor.Columns;

        if (columns == 1) return row;

        const u16 buckets = tensor.Layout.Buckets == 0 ? 1 : tensor.Layout.Buckets;
        const u32 outputs = rows / buckets;
        const u32 bucket  = row / outputs;
        const u32 output  = row % outputs;
        const u32 block   = tensor.Layout.Block;

        const u64 base = u64 { bucket } * columns * outputs;

        switch (tensor.Layout.Order) {
            case IR::Order::RowMajor   : return u64 { row } * columns + column;
            case IR::Order::BucketMajor: return base + u64 { column } * outputs + output;
            case IR::Order::Blocked    :
                return base + u64 { column / block } * outputs * block + u64 { output } * block + column % block;
            default                    : return u64 { column } * rows + row;
        }
    }

    namespace Detail
    {

        template<typename G>
        consteval IR::Diagnostic Located(const G& graph, const IR::Tensor& tensor, const Message& text)
        {
            const std::string_view name = IR::FileOf(graph, tensor.File);

            Message message {};

            if (name.empty()) message << "line ";
            else              message << name << ":";

            message << i64 { tensor.Line } << ":" << i64 { tensor.Column } << " (Tensor): " <<
                       std::string_view { text.data(), text.size() };

            return { .Ok = false, .Text = message };
        }

        template<typename G>
        consteval IR::Diagnostic CheckChunk(const G& graph, const IR::Tensor& tensor, const u32 count)
        {
            const u32  rows    = tensor.Rows / count;
            const u32  buckets = tensor.Layout.Buckets == 0 ? 1 : tensor.Layout.Buckets;
            const u32  block   = tensor.Layout.Block;
            const bool matrix  = tensor.Columns > 1;
            const bool blocked = matrix && tensor.Layout.Order == IR::Order::Blocked;

            if (tensor.Rows % count != 0)
                return Located(graph, tensor, Message {} << "rows " << i64 { tensor.Rows } <<
                                                            " are not divisible into " << i64 { count } <<
                                                            " block repetitions");

            if (matrix && rows % buckets != 0)
                return Located(graph, tensor, Message {} << "rows " << i64 { rows } <<
                                                            " of a block repetition are not " <<
                                                            "divisible into " << i64 { buckets } << " buckets");

            if (blocked && (block == 0 || tensor.Columns % block != 0))
                return Located(graph, tensor, Message {} << "columns " << i64 { tensor.Columns } <<
                                                            " are not divisible into blocks of " << i64 { block });

            return {};
        }

    }

    template<typename G>
    consteval IR::Diagnostic CheckLayout(const G& graph)
    {
        for (s00 i = 0; i < graph.ItemCount; i++) {
            const IR::Item& item  = graph.Items[i];
            const bool      block = item.Kind == IR::ItemKind::Block;
            const u32       count = block ? item.Count : 1;
            const s00       last  = block ? i + item.Span : i;

            for (s00 k = block ? i + 1 : i; k <= last; k++) {
                const IR::Item& inner = graph.Items[k];

                if (inner.Kind != IR::ItemKind::Tensor) continue;

                const IR::Diagnostic diagnostic = Detail::CheckChunk(graph, graph.Tensors[inner.Tensor], count);

                if (!diagnostic.Ok) return diagnostic;
            }

            i = last;
        }

        return {};
    }

    template<typename G>
    consteval s00 ChunkCount(const G& graph)
    {
        s00 count = 0;

        for (s00 i = 0; i < graph.ItemCount; i++) {
            const IR::Item& item  = graph.Items[i];
            const bool      block = item.Kind == IR::ItemKind::Block;

            count += block ? s00 { item.Count } * item.Span : 1;
            i     += block ? item.Span                      : 0;
        }

        return count;
    }

    template<s00 N, typename G>
    consteval Plan<N> Arrange(const G& graph)
    {
        Plan<N> plan {};

        s00 chunk  = 0;
        u64 offset = 0;

        const auto add = [&](const IR::Item& item, const u16 bucket, const u16 count) {
            const IR::Tensor& tensor = graph.Tensors[item.Tensor];
            const s00         values = IR::ElementsOf(tensor) / count;

            const u32 bytes = item.Kind == IR::ItemKind::Tensor ? static_cast<u32>(values * IR::BytesOf(tensor.Stored))
                                                                : item.Count;

            plan.Chunks[chunk++] = {
                .Kind   = item.Kind  ,
                .Tensor = item.Tensor,
                .Bucket = bucket     ,
                .Count  = count      ,
                .Bytes  = bytes      ,
                .Offset = offset     ,
                .Value  = item.Value
            };

            offset += bytes;
        };

        for (s00 i = 0; i < graph.ItemCount; i++) {
            const IR::Item& item = graph.Items[i];

            if (item.Kind != IR::ItemKind::Block) {
                add(item, 0, 1);

                continue;
            }

            const u16 count = static_cast<u16>(item.Count);

            for (u16 bucket = 0; bucket <  count    ; bucket++)
            for (s00 k      = 1; k      <= item.Span; k     ++) add(graph.Items[i + k], bucket, count);

            i += item.Span;
        }

        plan.Payload  = offset;
        plan.FileSize = graph.File.Padding == IR::Padding::Exact ? offset : PaddedSize(offset);

        return plan;
    }

}

#endif //MANTARAY_IO_LAYOUT_H
