//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_BACKEND_KERNEL_UPDATE_H
#define MANTARAY_BACKEND_KERNEL_UPDATE_H

#include <algorithm>
#include <span>
#include <type_traits>

#include "../../Common.h"

namespace MantaRay::Detail
{

    template<typename ISA, typename T, typename W, s00 R, s00 A>
    struct Update;

}

namespace MantaRay::Backend::Kernel
{

    namespace Detail
    {

        template<typename ISA, typename T>
        [[clang::always_inline]]
        ISA::Vector Add(const typename ISA::Vector left, const typename ISA::Vector right) noexcept
        {
            static_assert(std::is_same_v<T, i16> || std::is_same_v<T, i32>, "accumulators are i16 or i32");

            if (std::is_same_v<T, i16>) return ISA::AddI16(left, right);

            return ISA::AddI32(left, right);
        }

        template<typename ISA, typename T>
        [[clang::always_inline]]
        ISA::Vector Sub(const typename ISA::Vector left, const typename ISA::Vector right) noexcept
        {
            static_assert(std::is_same_v<T, i16> || std::is_same_v<T, i32>, "accumulators are i16 or i32");

            if (std::is_same_v<T, i16>) return ISA::SubI16(left, right);

            return ISA::SubI32(left, right);
        }

        template<typename ISA, u32 Width, typename T>
        consteval s00 Lanes()
        {
            static_assert(Width * sizeof(T) % Alignment  == 0, "kernel width must be a multiple of 64 bytes");
            static_assert(Alignment         % ISA::Bytes == 0, "ISA vector must divide 64 bytes"            );

            return ISA::Bytes / sizeof(T);
        }

        consteval s00 Tile(const s00 vectors, const s00 limit)
        {
            for (s00 tile = std::min(vectors, limit); tile > 1; tile--) if (vectors % tile == 0) return tile;

            return 1;
        }

        template<u32 Width, typename ISA, typename T, typename W, s00 R, s00 A>
        consteval u32 Blocks(const std::type_identity<MantaRay::Detail::Update<ISA, T, W, R, A>>)
        { return Width / Lanes<ISA, Width, T>(); }

        constexpr inline u32 UnrollBudget = 96;

        template<u32 Width, u32 Budget, typename ISA, typename T, typename W, s00 R, s00 A>
        consteval u32 Span(const std::type_identity<MantaRay::Detail::Update<ISA, T, W, R, A>>)
        {
            constexpr u32 Vectors = Width / Lanes<ISA, Width, T>();

            if (Vectors <= Budget) return Vectors;

            for (s00 span = 16; span > 1; span--) if (Vectors % span == 0) return static_cast<u32>(span);

            return 1;
        }

    }

    template<u32 Width, u32 Budget = Detail::UnrollBudget, typename F>
    [[clang::always_inline]]
    void Advance(const F& update) noexcept
    {
        constexpr u32 Blocks = Detail::Blocks<Width>(std::type_identity<F> {});
        constexpr u32 Span   = Detail::Span<Width, Budget>(std::type_identity<F> {});

        const F local = update;

        if (Span == Blocks) {
            UNROLL(full)
            for (u32 block = 0; block < Blocks; block++) local(block);
        } else {
            UNROLL(disable)
            for (u32 base = 0; base < Blocks; base += Span)
            UNROLL(full)
            for (u32 block = base; block < base + Span; block++) local(block);
        }
    }

    template<typename ISA, u32 Width, typename T>
    [[clang::always_inline]]
    void Copy(const T* const source, T* const destination) noexcept
    {
        constexpr s00 Lanes = Detail::Lanes<ISA, Width, T>();

        UNROLL(full)
        for (s00 i = 0; i < Width; i += Lanes) ISA::Store(destination + i, ISA::Load(source + i));
    }

    template<typename ISA, u32 Width, typename T, typename W, typename... D>
    [[clang::always_inline]]
    void Update(
        const T* const                  base        ,
        const std::span<const W* const> removed     ,
        const std::span<const W* const> inserted    ,
              D* const...               destinations
    ) noexcept
    {
        constexpr s00 Lanes  = Detail::Lanes<ISA, Width, T>();
        constexpr s00 Tile   = Detail::Tile(Width / Lanes, ISA::Registers - 4);
        constexpr s00 Stride = Tile * Lanes;

        static_assert((std::is_same_v<D, T> && ...), "every destination is a slot of the base type"   );
        static_assert(Width % Stride == 0          , "refresh tiles must cover the accumulator exactly");

        for (s00 offset = 0; offset < Width; offset += Stride) {
            Array<typename ISA::Vector, Tile> values;

            UNROLL(full)
            for (s00 i = 0; i < Tile; i++) values[i] = ISA::Load(base + offset + i * Lanes);

            for (const W* row : removed) {
                UNROLL(full)
                for (s00 i = 0; i < Tile; i++)
                    values[i] = Detail::Sub<ISA, T>(values[i], ISA::template LoadAs<T>(row + offset + i * Lanes));
            }

            for (const W* row : inserted) {
                UNROLL(full)
                for (s00 i = 0; i < Tile; i++)
                    values[i] = Detail::Add<ISA, T>(values[i], ISA::template LoadAs<T>(row + offset + i * Lanes));
            }

            ([&] {
                UNROLL(full)
                for (s00 i = 0; i < Tile; i++) ISA::Store(destinations + offset + i * Lanes, values[i]);
            }(), ...);
        }
    }

}

namespace MantaRay::Detail
{

    template<typename ISA, typename T, typename W, s00 R, s00 A>
    [[clang::always_inline]]
    constexpr ISA::Vector Apply(
              typename ISA::Vector value   ,
        const Array<const W*, R>&  removed ,
        const Array<const W*, A>&  inserted,
        const s00                  offset
    ) noexcept
    {
        const auto row = [&](const W* pointer) { return ISA::template LoadAs<T>(pointer + offset); };

        if constexpr (R == 2 && A == 1) {
            const auto left  = Backend::Kernel::Detail::Add<ISA, T>(value          , row(inserted[0]));
            const auto right = Backend::Kernel::Detail::Add<ISA, T>(row(removed[0]), row(removed [1]));

            return Backend::Kernel::Detail::Sub<ISA, T>(left, right);
        }

        if constexpr (R == 2 && A == 2) {
            const auto left  = Backend::Kernel::Detail::Add<ISA, T>(
                Backend::Kernel::Detail::Sub<ISA, T>(value, row(removed[0])),
                row(inserted[0])
            );
            const auto right = Backend::Kernel::Detail::Sub<ISA, T>(row(inserted[1]), row(removed[1]));

            return Backend::Kernel::Detail::Add<ISA, T>(left, right);
        }

        for (const W* pointer : removed ) value = Backend::Kernel::Detail::Sub<ISA, T>(value, row(pointer));
        for (const W* pointer : inserted) value = Backend::Kernel::Detail::Add<ISA, T>(value, row(pointer));

        return value;
    }

    template<typename ISA, typename T>
    struct Read
    {

        const T* Values;

        [[clang::always_inline]]
        constexpr auto operator ()(const u32 block) const noexcept
        {
            constexpr s00 Lanes = ISA::Bytes / sizeof(T);

            return ISA::Load(Values + block * Lanes);
        }

    };

    template<typename ISA, typename T, typename W, s00 R, s00 A>
    struct Update
    {

        T*                 Child;
        const T*           Parent;
        Array<const W*, R> Removed;
        Array<const W*, A> Inserted;

        [[clang::always_inline]]
        constexpr auto operator ()(const u32 block) const noexcept
        {
            constexpr s00 Lanes = ISA::Bytes / sizeof(T);

            const s00 offset = block * Lanes;

            const auto value = Detail::Apply<ISA, T, W, R, A>(
                ISA::Load(Parent + offset),
                Removed,
                Inserted,
                offset
            );

            ISA::Store(Child + offset, value);

            return value;
        }

    };

}

#endif //MANTARAY_BACKEND_KERNEL_UPDATE_H
