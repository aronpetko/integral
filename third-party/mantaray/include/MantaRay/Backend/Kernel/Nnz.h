//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_BACKEND_KERNEL_NNZ_H
#define MANTARAY_BACKEND_KERNEL_NNZ_H

#include <bit>
#include <cstring>
#include <type_traits>

#include "../../Common.h"
#include "../../Lowering/Choices.h"
#include "../ISA/Scalar.h"

namespace MantaRay::Backend::Kernel
{

    namespace Detail
    {

        using NnzRow [[gnu::vector_size(16)]] = u16;

        consteval Array<u16, 256, 8> NnzRowsOf()
        {
            Array<u16, 256, 8> rows {};

            for (s00 mask = 0; mask < 256; mask++) {
                u32 count = 0;

                for (s00 bit = 0; bit < 8; bit++) if (mask >> bit & 1) rows[mask][count++] = static_cast<u16>(bit);
            }

            return rows;
        }

        consteval Array<u16, 32> NnzIotaOf()
        {
            Array<u16, 32> iota {};

            for (s00 i = 0; i < 32; i++) iota[i] = static_cast<u16>(i);

            return iota;
        }

        alignas(Alignment) constexpr inline Array<u16, 256, 8> NnzRows = NnzRowsOf();
        alignas(Alignment) constexpr inline Array<u16, 32   > NnzIota = NnzIotaOf();

        template<typename ISA>
        consteval Lowering::Tier NnzTier(const u32 groups)
        { return Lowering::ChoiceOf(Lowering::Choice::Nnz, Lowering::CapabilitiesOf<ISA>(), groups); }

        template<u32 Groups>
        [[clang::always_inline]]
        u32 NnzLoop(const u08* input, u16* list) noexcept
        {
            u32 count = 0;

            for (u32 group = 0; group < Groups; group++) {
                const u08* x = input + group * 4;

                list[count]  = static_cast<u16>(group);
                count       += (x[0] | x[1] | x[2] | x[3]) != 0;
            }

            return count;
        }

        template<typename ISA, bool Positive, u32 Count>
        [[clang::always_inline]]
        u32 NnzMask(const u08* input) noexcept
        {
            constexpr u32 Lanes = ISA::Bytes / 4;
            constexpr u32 Loads = (Count + Lanes - 1) / Lanes;

            u32 mask = 0;

            UNROLL(full)
            for (u32 load = 0; load < Loads; load++)
                mask |= ISA::template NonzeroMaskI32<Positive>(ISA::Load(input + load * ISA::Bytes)) << load * Lanes;

            return Count < 32 ? mask & ((u32 { 1 } << Count % 32) - 1) : mask;
        }

        [[clang::always_inline]]
        inline void NnzEmit(u16* list, const u32 mask, const NnzRow base) noexcept
        {
            NnzRow row;

            std::memcpy(&row, NnzRows[mask].data(), sizeof(NnzRow));

            row += base;

            std::memcpy(list, &row, sizeof(NnzRow));
        }

        template<typename ISA, bool Positive, u32 Count>
        [[clang::always_inline]]
        void NnzBlock(const u08* input, u16* list, u32& count, NnzRow& base) noexcept
        {
            constexpr NnzRow Eight { 8, 8, 8, 8, 8, 8, 8, 8 };

            const u32 mask = NnzMask<ISA, Positive, Count>(input);

            UNROLL(full)
            for (u32 slice = 0; slice < (Count + 7) / 8; slice++) {
                const u32 byte = mask >> slice * 8 & 0xFF;

                NnzEmit(list + count, byte, base);

                count += static_cast<u32>(std::popcount(byte));
                base  += Eight;
            }
        }

        template<typename ISA, u32 Groups, bool Positive>
        [[clang::always_inline]]
        u32 NnzTable(const u08* input, u16* list) noexcept
        {
            constexpr u32 Block = std::max<u32>(ISA::Bytes / 4, 8);
            constexpr u32 Full  = Groups / Block;
            constexpr u32 Rest  = Groups % Block;

            u32    count = 0;
            NnzRow base  {};

            UNROLL(disable)
            for (u32 block = 0; block < Full; block++)
                NnzBlock<ISA, Positive, Block>(input + block * Block * 4, list, count, base);

            if constexpr (Rest != 0) NnzBlock<ISA, Positive, Rest>(input + Full * Block * 4, list, count, base);

            return count;
        }

        template<typename ISA, bool Positive, u32 Count>
        [[clang::always_inline]]
        void NnzSpan(
            const u08*                  input,
                  u16*                  list ,
                  u32&                  count,
                  typename ISA::Vector& base
        ) noexcept
        {
            const u32 mask = NnzMask<ISA, Positive, Count>(input);

            ISA::StoreUnaligned(list + count, ISA::CompressU16(mask, base));

            count += static_cast<u32>(std::popcount(mask));
            base   = ISA::AddI16(base, ISA::BroadcastI16(32));
        }

        template<typename ISA, u32 Groups, bool Positive>
        [[clang::always_inline]]
        u32 NnzCompress(const u08* input, u16* list) noexcept
        {
            static_assert(ISA::Bytes == 64, "the Compress tier takes 32 groups in two 64-byte loads");

            constexpr u32 Span = 32;
            constexpr u32 Full = Groups / Span;
            constexpr u32 Rest = Groups % Span;

            u32  count = 0;
            auto base  = ISA::Load(NnzIota, 0);

            UNROLL(disable)
            for (u32 span = 0; span < Full; span++)
                NnzSpan<ISA, Positive, Span>(input + span * Span * 4, list, count, base);

            if constexpr (Rest != 0) NnzSpan<ISA, Positive, Rest>(input + Full * Span * 4, list, count, base);

            return count;
        }

        template<typename ISA, u32 Count, Lowering::Tier T, bool Valued, typename B>
        [[clang::always_inline]]
        void NnzWordSpan(const u08* input, u16* list, u16* values, u32& count, B& base) noexcept
        {
            const auto x = ISA::Load(input);

            u32 mask = ISA::NonzeroMaskI16(x);

            if constexpr (Count < 32) mask &= (u32 { 1 } << Count) - 1;

            if constexpr (T == Lowering::Tier::Compress) {
                ISA::StoreUnaligned(list + count, ISA::CompressU16(mask, base));

                if constexpr (Valued) ISA::StoreUnaligned(values + count, ISA::CompressU16(mask, x));

                count += static_cast<u32>(std::popcount(mask));
                base   = ISA::AddI16(base, ISA::BroadcastI16(32));
            } else {
                constexpr NnzRow Eight { 8, 8, 8, 8, 8, 8, 8, 8 };

                UNROLL(full)
                for (u32 slice = 0; slice < (Count + 7) / 8; slice++) {
                    const u32 byte = mask >> slice * 8 & 0xFF;

                    NnzEmit(list + count, byte, base);

                    count += static_cast<u32>(std::popcount(byte));
                    base  += Eight;
                }
            }
        }

        template<typename ISA, u32 Words, Lowering::Tier T, bool Valued>
        [[clang::always_inline]]
        u32 NnzWordScan(const u08* input, u16* list, u16* values) noexcept
        {
            static_assert(ISA::Bytes == 64, "2-byte lanes are scanned 32 at a time, one 64-byte load each");
            static_assert(!Valued || T == Lowering::Tier::Compress, "the value list is compressed beside the list");

            constexpr u32 Full = Words / 32;
            constexpr u32 Rest = Words % 32;

            u32 count = 0;

            auto base = [] {
                if constexpr (T == Lowering::Tier::Compress) return ISA::Load(NnzIota, 0);
                else                                         return NnzRow {};
            }();

            UNROLL(disable)
            for (u32 load = 0; load < Full; load++)
                NnzWordSpan<ISA, 32, T, Valued>(input + load * ISA::Bytes, list, values, count, base);

            if constexpr (Rest != 0)
                NnzWordSpan<ISA, Rest, T, Valued>(input + Full * ISA::Bytes, list, values, count, base);

            return count;
        }

    }

    template<u32 Groups>
    using NnzList = Array<u16, Groups + 32>;

    template<typename ISA, u32 Groups, bool Positive, Lowering::Tier T = Detail::NnzTier<ISA>(Groups)>
    [[clang::always_inline]]
    u32 Nnz(const u08* input, u16* list) noexcept
    {
        static_assert(Groups <= 65536, "NNZ indices are u16");
        static_assert(
            T == Lowering::Tier::Compress || T == Lowering::Tier::IndexTable,
            "the NNZ list is built by Compress or by the index table"
        );

        if constexpr (std::is_same_v<ISA, Backend::ISA::Scalar>) return Detail::NnzLoop<Groups>(input, list);
        else if constexpr (T == Lowering::Tier::Compress) {
            static_assert(ISA::Compress, "the Compress tier needs a register vpcompressw");

            return Detail::NnzCompress<ISA, Groups, Positive>(input, list);
        } else return Detail::NnzTable<ISA, Groups, Positive>(input, list);
    }

    template<typename ISA, u32 Words>
    constexpr inline bool NnzValued = Detail::NnzTier<ISA>(Words) == Lowering::Tier::Compress;

    template<typename ISA, u32 Words, bool Valued, Lowering::Tier T = Detail::NnzTier<ISA>(Words)>
    [[clang::always_inline]]
    u32 NnzWords(const u08* input, u16* list, u16* values) noexcept
    {
        static_assert(Words <= 65536, "NNZ indices are u16");
        static_assert(
            T == Lowering::Tier::Compress || T == Lowering::Tier::IndexTable,
            "the NNZ list is built by Compress or by the index table"
        );
        static_assert(T != Lowering::Tier::Compress || ISA::Compress, "the Compress tier needs vpcompressw");

        return Detail::NnzWordScan<ISA, Words, T, Valued>(input, list, values);
    }

}

#endif //MANTARAY_BACKEND_KERNEL_NNZ_H
