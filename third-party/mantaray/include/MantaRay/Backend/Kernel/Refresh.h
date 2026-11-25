//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_BACKEND_KERNEL_REFRESH_H
#define MANTARAY_BACKEND_KERNEL_REFRESH_H

#include <span>

#include "Update.h"
#include "../../Common.h"

namespace MantaRay::Backend::Kernel
{

    template<typename ISA, u32 Width, typename T, typename W, typename... D>
    [[clang::always_inline]]
    void Refresh(const T* const bias, const std::span<const W* const> rows, D* const... destinations) noexcept
    { Update<ISA, Width, T, W>(bias, {}, rows, destinations...); }

    template<typename W>
    struct Mending
    {

        std::span<const W* const> Removed ;
        std::span<const W* const> Inserted;
        std::span<const W* const> Active  ;

    };

    template<typename ISA, u32 Width, typename T, typename... W>
    [[clang::always_inline]]
    void Mend(T* const entry, T* const destination, const Mending<W>&... lists) noexcept
    {
        constexpr s00 Lanes  = Detail::Lanes<ISA, Width, T>();
        constexpr s00 Tile   = Detail::Tile(Width / Lanes, ISA::Registers - 4);
        constexpr s00 Stride = Tile * Lanes;

        static_assert(sizeof...(W) > 0   , "a partly cached refresh has rows of at least one type");
        static_assert(Width % Stride == 0, "refresh tiles must cover the accumulator exactly"    );

        for (s00 offset = 0; offset < Width; offset += Stride) {
            Array<typename ISA::Vector, Tile> values;

            UNROLL(full)
            for (s00 i = 0; i < Tile; i++) values[i] = ISA::Load(entry + offset + i * Lanes);

            ([&] {
                for (const W* row : lists.Removed) {
                    UNROLL(full)
                    for (s00 i = 0; i < Tile; i++)
                        values[i] = Detail::Sub<ISA, T>(values[i], ISA::template LoadAs<T>(row + offset + i * Lanes));
                }

                for (const W* row : lists.Inserted) {
                    UNROLL(full)
                    for (s00 i = 0; i < Tile; i++)
                        values[i] = Detail::Add<ISA, T>(values[i], ISA::template LoadAs<T>(row + offset + i * Lanes));
                }
            }(), ...);

            UNROLL(full)
            for (s00 i = 0; i < Tile; i++) ISA::Store(entry + offset + i * Lanes, values[i]);

            ([&] {
                for (const W* row : lists.Active) {
                    UNROLL(full)
                    for (s00 i = 0; i < Tile; i++)
                        values[i] = Detail::Add<ISA, T>(values[i], ISA::template LoadAs<T>(row + offset + i * Lanes));
                }
            }(), ...);

            UNROLL(full)
            for (s00 i = 0; i < Tile; i++) ISA::Store(destination + offset + i * Lanes, values[i]);
        }
    }

}

#endif //MANTARAY_BACKEND_KERNEL_REFRESH_H
