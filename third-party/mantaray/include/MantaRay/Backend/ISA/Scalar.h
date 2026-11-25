//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_BACKEND_ISA_SCALAR_H
#define MANTARAY_BACKEND_ISA_SCALAR_H

#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <cstring>
#include <memory>

#include "../../Common.h"

namespace MantaRay::Backend::ISA
{

    class Scalar
    {

        template<typename T>
        using Lanes [[gnu::vector_size(16)]] = T;

        template<typename T>
        constexpr static s00 Count = 16 / sizeof(T);

        template<typename T, typename V>
        [[clang::always_inline]]
        static V Fill(const T value)
        {
            Lanes<T> lanes;

            for (s00 i = 0; i < Count<T>; i++) lanes[i] = value;

            return std::bit_cast<V>(lanes);
        }

        template<typename T, typename V, typename F>
        [[clang::always_inline]]
        static V Map(const V left, const V right, const F function)
        {
            const auto a = std::bit_cast<Lanes<T>>(left );
            const auto b = std::bit_cast<Lanes<T>>(right);

            Lanes<T> result;

            for (s00 i = 0; i < Count<T>; i++) result[i] = function(a[i], b[i]);

            return std::bit_cast<V>(result);
        }

        [[clang::always_inline]]
        static i32 SaturateI16(const i32 value) noexcept { return std::clamp(value, -32768, 32767); }

        public:
        using Vector  = Lanes<u08>;
        using VectorF = Lanes<f32>;

        static_assert(alignof(Array<Vector , 2>) == alignof(Vector ), "arrays of vectors keep the vector's alignment");
        static_assert(alignof(Array<VectorF, 2>) == alignof(VectorF), "arrays of vectors keep the vector's alignment");

        constexpr static s00  Bytes     = 16;
        constexpr static s00  Registers = 16;
        constexpr static s00  DotChains =  4;
        constexpr static bool VNNI      = false;

        constexpr static bool Masks    = false;
        constexpr static bool Permute8 = false;
        constexpr static bool Compress = false;
        constexpr static bool FMA      = false;
        constexpr static bool Shuffle  = false;
        constexpr static bool Gather   = false;
        constexpr static bool Table    = false;
        constexpr static bool PairDot  = false;
        constexpr static bool Maddubs  = false;

        constexpr static s00 DotInFlight = 1;

        template<typename T>
        [[clang::always_inline]]
        static Vector Load(const T* const address) noexcept
        {
            Vector value;

            std::memcpy(&value, std::assume_aligned<Bytes>(reinterpret_cast<const u08*>(address)), Bytes);

            return value;
        }

        template<typename T, s00 N>
        [[clang::always_inline]]
        static Vector Load(const std::array<T, N>& array, const s00 index) noexcept
        {
            Vector value;

            std::memcpy(&value, std::assume_aligned<Bytes>(reinterpret_cast<const u08*>(&array[index])), Bytes);

            return value;
        }

        template<typename T>
        [[clang::always_inline]]
        static void Store(T* const address, const Vector value) noexcept
        { std::memcpy(std::assume_aligned<Bytes>(reinterpret_cast<u08*>(address)), &value, Bytes); }

        template<typename T, s00 N>
        [[clang::always_inline]]
        static void Store(std::array<T, N>& array, const s00 index, const Vector value) noexcept
        { std::memcpy(std::assume_aligned<Bytes>(reinterpret_cast<u08*>(&array[index])), &value, Bytes); }

        template<typename T>
        [[clang::always_inline]]
        static void StoreUnaligned(T* const address, const Vector value) noexcept
        { std::memcpy(reinterpret_cast<u08*>(address), &value, Bytes); }

        template<typename T, s00 N>
        [[clang::always_inline]]
        static void StoreUnaligned(std::array<T, N>& array, const s00 index, const Vector value) noexcept
        { std::memcpy(reinterpret_cast<u08*>(&array[index]), &value, Bytes); }

        template<typename T>
        [[clang::always_inline]]
        static Vector LoadUnaligned(const T* const address) noexcept
        {
            Vector value;

            std::memcpy(&value, address, Bytes);

            return value;
        }

        template<typename T, s00 N>
        [[clang::always_inline]]
        static Vector LoadUnaligned(const std::array<T, N>& array, const s00 index) noexcept
        {
            Vector value;

            std::memcpy(&value, &array[index], Bytes);

            return value;
        }

        [[clang::always_inline]]
        static Vector BroadcastU128(const u08* const address) noexcept
        {
            Vector value;

            std::memcpy(&value, address, Bytes);

            return value;
        }

        template<typename T, typename W>
        [[clang::always_inline]]
        static Vector LoadAs(const W* const address) noexcept
        {
            static_assert(IsWidening<T, W>, "LoadAs reads W == T or sign-extends i08 to i16 or i32 and i16 to i32");

            using Narrow [[gnu::vector_size(Count<T> * sizeof(W))]] = W;

            Narrow value;

            std::memcpy(&value, std::assume_aligned<sizeof(Narrow)>(address), sizeof(Narrow));

            return std::bit_cast<Vector>(__builtin_convertvector(value, Lanes<T>));
        }

        template<typename T, typename W, s00 N>
        [[clang::always_inline]]
        static Vector LoadAs(const std::array<W, N>& array, const s00 index) noexcept
        { return LoadAs<T>(&array[index]); }

        [[clang::always_inline]]
        static Vector Zero() noexcept { return Vector {}; }

        [[clang::always_inline]]
        static Vector BroadcastU08(const u08 value) noexcept { return Fill<u08, Vector>(value); }

        [[clang::always_inline]]
        static Vector BroadcastI16(const i16 value) noexcept { return Fill<i16, Vector>(value); }

        [[clang::always_inline]]
        static Vector BroadcastI32(const i32 value) noexcept { return Fill<i32, Vector>(value); }

        [[clang::always_inline]]
        static Vector BroadcastU32(const u08* const address) noexcept
        {
            u32 value;

            std::memcpy(&value, address, sizeof(u32));

            return Fill<u32, Vector>(value);
        }

        [[clang::always_inline]]
        static Vector And(const Vector left, const Vector right) noexcept { return left & right; }

        [[clang::always_inline]]
        static Vector Or(const Vector left, const Vector right) noexcept { return left | right; }

        [[clang::always_inline]]
        static Vector AddI16(const Vector left, const Vector right) noexcept
        { return Map<i16>(left, right, [](const i16 a, const i16 b) { return WrapAdd(a, b); }); }

        [[clang::always_inline]]
        static Vector SubI16(const Vector left, const Vector right) noexcept
        { return Map<i16>(left, right, [](const i16 a, const i16 b) { return WrapSub(a, b); }); }

        [[clang::always_inline]]
        static Vector MinI16(const Vector left, const Vector right) noexcept
        { return Map<i16>(left, right, [](const i16 a, const i16 b) { return std::min(a, b); }); }

        [[clang::always_inline]]
        static Vector MaxI16(const Vector left, const Vector right) noexcept
        { return Map<i16>(left, right, [](const i16 a, const i16 b) { return std::max(a, b); }); }

        [[clang::always_inline]]
        static Vector MulLoI16(const Vector left, const Vector right) noexcept
        { return Map<i16>(left, right, [](const i16 a, const i16 b) { return WrapMul(a, b); }); }

        [[clang::always_inline]]
        static Vector MulHiI16(const Vector left, const Vector right) noexcept
        {
            const auto high = [](const i16 a, const i16 b) { return static_cast<i16>(i32 { a } * b >> 16); };

            return Map<i16>(left, right, high);
        }

        template<s00 S>
        [[clang::always_inline]]
        static Vector ShiftLeftI16(const Vector value) noexcept
        {
            static_assert(S < 16, "an i16 shift stays below 16");

            return std::bit_cast<Vector>(std::bit_cast<Lanes<u16>>(value) << static_cast<u16>(S));
        }

        template<s00 S>
        [[clang::always_inline]]
        static Vector ShiftRightI16(const Vector value) noexcept
        {
            static_assert(S < 16, "an i16 shift stays below 16");

            return std::bit_cast<Vector>(std::bit_cast<Lanes<i16>>(value) >> static_cast<i16>(S));
        }

        [[clang::always_inline]]
        static Vector AddI32(const Vector left, const Vector right) noexcept
        { return std::bit_cast<Vector>(std::bit_cast<Lanes<u32>>(left) + std::bit_cast<Lanes<u32>>(right)); }

        [[clang::always_inline]]
        static Vector SubI32(const Vector left, const Vector right) noexcept
        { return Map<i32>(left, right, [](const i32 a, const i32 b) { return WrapSub(a, b); }); }

        [[clang::always_inline]]
        static Vector MulLoI32(const Vector left, const Vector right) noexcept
        { return Map<i32>(left, right, [](const i32 a, const i32 b) { return WrapMul(a, b); }); }

        [[clang::always_inline]]
        static Vector MinI32(const Vector left, const Vector right) noexcept
        { return Map<i32>(left, right, [](const i32 a, const i32 b) { return std::min(a, b); }); }

        [[clang::always_inline]]
        static Vector MaxI32(const Vector left, const Vector right) noexcept
        { return Map<i32>(left, right, [](const i32 a, const i32 b) { return std::max(a, b); }); }

        template<s00 S>
        [[clang::always_inline]]
        static Vector ShiftRightI32(const Vector value) noexcept
        {
            static_assert(S < 32, "an i32 shift stays below 32");

            return std::bit_cast<Vector>(std::bit_cast<Lanes<i32>>(value) >> static_cast<i32>(S));
        }

        template<s00 S>
        [[clang::always_inline]]
        static Vector ShiftLeftI32(const Vector value) noexcept
        {
            static_assert(S < 32, "an i32 shift stays below 32");

            return std::bit_cast<Vector>(std::bit_cast<Lanes<u32>>(value) << static_cast<u32>(S));
        }

        template<bool Positive>
        [[clang::always_inline]]
        static u32 NonzeroMaskI32(const Vector value) noexcept
        {
            const auto lanes = std::bit_cast<Lanes<i32>>(value);

            u32 mask = 0;

            for (s00 i = 0; i < Count<i32>; i++) mask |= u32 { lanes[i] != 0 } << i;

            return mask;
        }

        [[clang::always_inline]]
        static Vector MaddI16(const Vector left, const Vector right) noexcept
        {
            using Wide [[gnu::vector_size(32)]] = i32;
            using Bits [[gnu::vector_size(16)]] = u32;

            const auto a = __builtin_convertvector(std::bit_cast<Lanes<i16>>(left ), Wide);
            const auto b = __builtin_convertvector(std::bit_cast<Lanes<i16>>(right), Wide);

            const auto products = a * b;

            const auto even = std::bit_cast<Bits>(__builtin_shufflevector(products, products, 0, 2, 4, 6));
            const auto odd  = std::bit_cast<Bits>(__builtin_shufflevector(products, products, 1, 3, 5, 7));

            return std::bit_cast<Vector>(even + odd);
        }

        [[clang::always_inline]]
        static i32 ReduceI32(const Vector value) noexcept
        {
            const auto lanes = std::bit_cast<Lanes<i32>>(value);

            i32 sum = 0;

            for (s00 i = 0; i < Count<i32>; i++) sum = WrapAdd(sum, lanes[i]);

            return sum;
        }

        [[clang::always_inline]]
        static i64 ReduceI64(const Vector value) noexcept
        {
            const auto lanes = std::bit_cast<Lanes<i32>>(value);

            i64 sum = 0;

            for (s00 i = 0; i < Count<i32>; i++) sum += lanes[i];

            return sum;
        }

        [[clang::always_inline]]
        static Vector PackUnsignedI16(const Vector left, const Vector right) noexcept
        {
            const auto a = std::bit_cast<Lanes<i16>>(left );
            const auto b = std::bit_cast<Lanes<i16>>(right);

            Vector result;

            for (s00 i = 0; i < Count<i16>; i++) {
                result[i             ] = static_cast<u08>(std::clamp<i16>(a[i], 0, 255));
                result[i + Count<i16>] = static_cast<u08>(std::clamp<i16>(b[i], 0, 255));
            }

            return result;
        }

        [[clang::always_inline]]
        static Vector PackU08(const Vector left, const Vector right) noexcept { return PackUnsignedI16(left, right); }

        [[clang::always_inline]]
        static Vector PackI16(const Vector left, const Vector right) noexcept
        {
            const auto a = std::bit_cast<Lanes<i32>>(left );
            const auto b = std::bit_cast<Lanes<i32>>(right);

            Lanes<i16> result;

            for (s00 i = 0; i < Count<i32>; i++) {
                result[i             ] = static_cast<i16>(SaturateI16(a[i]));
                result[i + Count<i32>] = static_cast<i16>(SaturateI16(b[i]));
            }

            return std::bit_cast<Vector>(result);
        }

        [[clang::always_inline]]
        static u64 TestMask64(const Vector left, const Vector right) noexcept
        {
            u64 mask = 0;

            for (s00 i = 0; i < Bytes; i++) mask |= u64 { (left[i] & right[i]) != 0 } << i;

            return mask;
        }

        [[clang::always_inline]]
        static Vector BlendMaskU08(const Vector mask, const Vector left, const Vector right) noexcept
        {
            Vector result;

            for (s00 i = 0; i < Bytes; i++) result[i] = mask[i] & 0x80 ? right[i] : left[i];

            return result;
        }

        [[clang::always_inline]]
        static Vector PutU08(const Vector value, const Vector lanes, const u08 lane, const u08 code) noexcept
        {
            Vector result;

            for (s00 i = 0; i < Bytes; i++) result[i] = lanes[i] == lane ? code : value[i];

            return result;
        }

        [[clang::always_inline]]
        static Vector WidenU08U32(const Vector value) noexcept
        {
            Lanes<u32> result;

            for (s00 i = 0; i < Count<u32>; i++) result[i] = value[i];

            return std::bit_cast<Vector>(result);
        }

        [[clang::always_inline]]
        static Array<Vector, 2> WidenI08(const Vector value) noexcept
        {
            const auto bytes = std::bit_cast<Lanes<i08>>(value);

            Lanes<i16> low;
            Lanes<i16> high;

            for (s00 i = 0; i < Count<i16>; i++) {
                low [i] = bytes[i             ];
                high[i] = bytes[i + Count<i16>];
            }

            return { std::bit_cast<Vector>(low), std::bit_cast<Vector>(high) };
        }

        [[clang::always_inline]]
        static Vector MaddubsI16(const Vector u8, const Vector i8) noexcept
        {
            const auto b = std::bit_cast<Lanes<i08>>(i8);

            Lanes<i16> result;

            for (s00 i = 0; i < Count<i16>; i++)
                result[i] = static_cast<i16>(SaturateI16(u8[2 * i] * b[2 * i] + u8[2 * i + 1] * b[2 * i + 1]));

            return std::bit_cast<Vector>(result);
        }

        [[clang::always_inline]]
        static Vector DotI16(const Vector sum, const Vector left, const Vector right) noexcept
        { return AddI32(sum, MaddI16(left, right)); }

        [[clang::always_inline]]
        static Vector DotU08I08Wide(const Vector sum, const Vector u8, const Vector i8) noexcept
        {
            const auto s = std::bit_cast<Lanes<i32>>(sum);
            const auto b = std::bit_cast<Lanes<i08>>(i8 );

            Lanes<i32> result;

            for (s00 i = 0; i < Count<i32>; i++) {
                i32 dot = 0;

                for (s00 j = 4 * i; j < 4 * i + 4; j++) dot += u8[j] * b[j];

                result[i] = WrapAdd(s[i], dot);
            }

            return std::bit_cast<Vector>(result);
        }

        [[clang::always_inline]]
        static Vector DotU08I08(const Vector sum, const Vector u8, const Vector i8) noexcept
        {
            const auto s = std::bit_cast<Lanes<i32>>(sum);
            const auto b = std::bit_cast<Lanes<i08>>(i8 );

            Lanes<i32> result;

            for (s00 i = 0; i < Count<i32>; i++) {
                const i32 low  = SaturateI16(u8[4 * i    ] * b[4 * i    ] + u8[4 * i + 1] * b[4 * i + 1]);
                const i32 high = SaturateI16(u8[4 * i + 2] * b[4 * i + 2] + u8[4 * i + 3] * b[4 * i + 3]);

                result[i] = WrapAdd(s[i], low + high);
            }

            return std::bit_cast<Vector>(result);
        }

        template<s00 N>
        [[clang::always_inline]]
        static VectorF LoadF(const std::array<f32, N>& array, const s00 index) noexcept
        {
            VectorF value;

            std::memcpy(&value, std::assume_aligned<Bytes>(&array[index]), Bytes);

            return value;
        }

        [[clang::always_inline]]
        static VectorF LoadF(const f32* const address) noexcept
        {
            VectorF value;

            std::memcpy(&value, std::assume_aligned<Bytes>(address), Bytes);

            return value;
        }

        [[clang::always_inline]]
        static void StoreF(f32* const address, const VectorF value) noexcept
        { std::memcpy(std::assume_aligned<Bytes>(address), &value, Bytes); }

        template<s00 N>
        [[clang::always_inline]]
        static void StoreF(std::array<f32, N>& array, const s00 index, const VectorF value) noexcept
        { std::memcpy(std::assume_aligned<Bytes>(&array[index]), &value, Bytes); }

        [[clang::always_inline]]
        static VectorF ZeroF() noexcept { return VectorF {}; }

        [[clang::always_inline]]
        static VectorF BroadcastF(const f32 value) noexcept { return Fill<f32, VectorF>(value); }

        [[clang::always_inline]]
        static VectorF CvtI32F(const Vector value) noexcept
        { return __builtin_convertvector(std::bit_cast<Lanes<i32>>(value), VectorF); }

        [[clang::always_inline]]
        static VectorF AddF(const VectorF left, const VectorF right) noexcept
        {
            #pragma clang fp contract(off)

            VectorF result;

            for (s00 i = 0; i < Count<f32>; i++) result[i] = left[i] + right[i];

            return result;
        }

        [[clang::always_inline]]
        static VectorF MulF(const VectorF left, const VectorF right) noexcept
        {
            #pragma clang fp contract(off)

            VectorF result;

            for (s00 i = 0; i < Count<f32>; i++) result[i] = left[i] * right[i];

            return result;
        }

        [[clang::always_inline]]
        static VectorF MinF(const VectorF left, const VectorF right) noexcept
        {
            VectorF result;

            for (s00 i = 0; i < Count<f32>; i++) result[i] = left[i] < right[i] ? left[i] : right[i];

            return result;
        }

        [[clang::always_inline]]
        static VectorF MaxF(const VectorF left, const VectorF right) noexcept
        {
            VectorF result;

            for (s00 i = 0; i < Count<f32>; i++) result[i] = left[i] > right[i] ? left[i] : right[i];

            return result;
        }

        [[clang::always_inline]]
        static VectorF FmaF(const VectorF left, const VectorF right, const VectorF addend) noexcept
        {
            VectorF result;

            for (s00 i = 0; i < Count<f32>; i++) result[i] = std::fma(left[i], right[i], addend[i]);

            return result;
        }

        [[clang::always_inline]]
        static f32 ReduceF(VectorF value) noexcept
        {
            #pragma clang fp contract(off)

            for (s00 width = Count<f32>; width > 1        ; width /= 2)
            for (s00 i     = 0         ; i     < width / 2; i++) value[i] = value[i] + value[i + width / 2];

            return value[0];
        }

        [[clang::always_inline]]
        static void Prefetch(const void* const address) noexcept { __builtin_prefetch(address); }

    };

}

#endif //MANTARAY_BACKEND_ISA_SCALAR_H
