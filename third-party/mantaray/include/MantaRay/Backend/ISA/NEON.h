//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_BACKEND_ISA_NEON_H
#define MANTARAY_BACKEND_ISA_NEON_H

#if defined(__ARM_NEON) && defined(__aarch64__)

#include <arm_neon.h>
#include <array>
#include <cstring>
#include <type_traits>
#include <utility>

#include "../../Common.h"

namespace MantaRay::Backend::ISA
{

    class NEON
    {

        [[clang::always_inline]]
        static int32x4_t AsI32(const int16x8_t value) noexcept { return vreinterpretq_s32_s16(value); }

        [[clang::always_inline]]
        static int16x8_t AsI16(const int32x4_t value) noexcept { return vreinterpretq_s16_s32(value); }

        public:
        using Vector  = int16x8_t  ;
        using VectorF = float32x4_t;

        static_assert(alignof(Array<Vector , 2>) == alignof(Vector ), "arrays of vectors keep the vector's alignment");
        static_assert(alignof(Array<VectorF, 2>) == alignof(VectorF), "arrays of vectors keep the vector's alignment");

        constexpr static s00 Bytes     = 16;
        constexpr static s00 Registers = 32;
        constexpr static s00 DotChains =  2;

        constexpr static bool VNNI = false;

        constexpr static bool Masks    = false;
        constexpr static bool Permute8 = false;
        constexpr static bool Compress = false;
        constexpr static bool FMA      = true;
        constexpr static bool Shuffle  = false;
        constexpr static bool Gather   = false;
        constexpr static bool Table    = true;
        constexpr static bool PairDot  = false;
        constexpr static bool Maddubs  = false;

        constexpr static s00 DotInFlight = 1;

        template<typename T>
        [[clang::always_inline]]
        static Vector Load(const T* const address) noexcept { return vld1q_s16(reinterpret_cast<const i16*>(address)); }

        template<typename T, s00 N>
        [[clang::always_inline]]
        static Vector Load(const std::array<T, N>& array, const s00 index) noexcept
        { return vld1q_s16(reinterpret_cast<const i16*>(&array[index])); }

        template<typename T>
        [[clang::always_inline]]
        static void Store(T* const address, const Vector value) noexcept
        { vst1q_s16(reinterpret_cast<i16*>(address), value); }

        template<typename T, s00 N>
        [[clang::always_inline]]
        static void Store(std::array<T, N>& array, const s00 index, const Vector value) noexcept
        { vst1q_s16(reinterpret_cast<i16*>(&array[index]), value); }

        template<typename T>
        [[clang::always_inline]]
        static void StoreUnaligned(T* const address, const Vector value) noexcept
        { vst1q_u8(reinterpret_cast<u08*>(address), vreinterpretq_u8_s16(value)); }

        template<typename T, s00 N>
        [[clang::always_inline]]
        static void StoreUnaligned(std::array<T, N>& array, const s00 index, const Vector value) noexcept
        { vst1q_u8(reinterpret_cast<u08*>(&array[index]), vreinterpretq_u8_s16(value)); }

        template<typename T>
        [[clang::always_inline]]
        static Vector LoadUnaligned(const T* const address) noexcept
        { return vreinterpretq_s16_u8(vld1q_u8(reinterpret_cast<const u08*>(address))); }

        template<typename T, s00 N>
        [[clang::always_inline]]
        static Vector LoadUnaligned(const std::array<T, N>& array, const s00 index) noexcept
        { return vreinterpretq_s16_u8(vld1q_u8(reinterpret_cast<const u08*>(&array[index]))); }

        [[clang::always_inline]]
        static Vector BroadcastU128(const u08* const address) noexcept
        { return vreinterpretq_s16_u8(vld1q_u8(address)); }

        template<typename T, typename W>
        [[clang::always_inline]]
        static Vector LoadAs(const W* const address) noexcept
        {
            static_assert(IsWidening<T, W>, "LoadAs reads W == T or sign-extends i08 to i16 or i32 and i16 to i32");

            if (std::is_same_v<T, W>) return Load(address);

            if (std::is_same_v<T, i16> && std::is_same_v<W, i08>)
                return vmovl_s8(vld1_s8(reinterpret_cast<const i08*>(address)));

            if (std::is_same_v<T, i32> && std::is_same_v<W, i16>)
                return AsI16(vmovl_s16(vld1_s16(reinterpret_cast<const i16*>(address))));

            if (std::is_same_v<T, i32> && std::is_same_v<W, i08>) {
                const auto bytes = vreinterpret_s8_s32(vld1_dup_s32(reinterpret_cast<const i32*>(address)));

                return AsI16(vmovl_s16(vget_low_s16(vmovl_s8(bytes))));
            }

            std::unreachable();
        }

        template<typename T, typename W, s00 N>
        [[clang::always_inline]]
        static Vector LoadAs(const std::array<W, N>& array, const s00 index) noexcept
        { return LoadAs<T>(&array[index]); }

        [[clang::always_inline]]
        static Vector Zero() noexcept { return vdupq_n_s16(0); }

        [[clang::always_inline]]
        static Vector BroadcastU08(const u08 value) noexcept { return vreinterpretq_s16_u8(vdupq_n_u8(value)); }

        [[clang::always_inline]]
        static Vector BroadcastI16(const i16 value) noexcept { return vdupq_n_s16(value); }

        [[clang::always_inline]]
        static Vector BroadcastI32(const i32 value) noexcept { return AsI16(vdupq_n_s32(value)); }

        [[clang::always_inline]]
        static Vector BroadcastU32(const u08* const address) noexcept
        {
            u32 value;

            std::memcpy(&value, address, sizeof(u32));

            return vreinterpretq_s16_u32(vdupq_n_u32(value));
        }

        [[clang::always_inline]]
        static Vector And(const Vector left, const Vector right) noexcept { return vandq_s16(left, right); }

        [[clang::always_inline]]
        static Vector Or(const Vector left, const Vector right) noexcept { return vorrq_s16(left, right); }

        [[clang::always_inline]]
        static Vector AddI16(const Vector left, const Vector right) noexcept { return vaddq_s16(left, right); }

        [[clang::always_inline]]
        static Vector SubI16(const Vector left, const Vector right) noexcept { return vsubq_s16(left, right); }

        [[clang::always_inline]]
        static Vector MinI16(const Vector left, const Vector right) noexcept { return vminq_s16(left, right); }

        [[clang::always_inline]]
        static Vector MaxI16(const Vector left, const Vector right) noexcept { return vmaxq_s16(left, right); }

        [[clang::always_inline]]
        static Vector MulLoI16(const Vector left, const Vector right) noexcept { return vmulq_s16(left, right); }

        [[clang::always_inline]]
        static Vector MulHiI16(const Vector left, const Vector right) noexcept
        {
            const auto low  = vmull_s16     (vget_low_s16(left), vget_low_s16(right));
            const auto high = vmull_high_s16(             left ,              right );

            return vuzp2q_s16(AsI16(low), AsI16(high));
        }

        template<s00 S>
        [[clang::always_inline]]
        static Vector ShiftLeftI16(const Vector value) noexcept
        {
            static_assert(S < 16, "an i16 shift stays below 16");

            return vshlq_n_s16(value, S);
        }

        template<s00 S>
        [[clang::always_inline]]
        static Vector ShiftRightI16(const Vector value) noexcept
        {
            static_assert(S < 16, "an i16 shift stays below 16");

            if constexpr (S == 0) return value;
            else                  return vshrq_n_s16(value, S);
        }

        [[clang::always_inline]]
        static Vector AddI32(const Vector left, const Vector right) noexcept
        { return AsI16(vaddq_s32(AsI32(left), AsI32(right))); }

        [[clang::always_inline]]
        static Vector SubI32(const Vector left, const Vector right) noexcept
        { return AsI16(vsubq_s32(AsI32(left), AsI32(right))); }

        [[clang::always_inline]]
        static Vector MulLoI32(const Vector left, const Vector right) noexcept
        { return AsI16(vmulq_s32(AsI32(left), AsI32(right))); }

        [[clang::always_inline]]
        static Vector MinI32(const Vector left, const Vector right) noexcept
        { return AsI16(vminq_s32(AsI32(left), AsI32(right))); }

        [[clang::always_inline]]
        static Vector MaxI32(const Vector left, const Vector right) noexcept
        { return AsI16(vmaxq_s32(AsI32(left), AsI32(right))); }

        template<s00 S>
        [[clang::always_inline]]
        static Vector ShiftRightI32(const Vector value) noexcept
        {
            static_assert(S < 32, "an i32 shift stays below 32");

            if constexpr (S == 0) return value;
            else                  return AsI16(vshrq_n_s32(AsI32(value), S));
        }

        template<s00 S>
        [[clang::always_inline]]
        static Vector ShiftLeftI32(const Vector value) noexcept
        {
            static_assert(S < 32, "an i32 shift stays below 32");

            return AsI16(vshlq_n_s32(AsI32(value), S));
        }

        template<bool Positive>
        [[clang::always_inline]]
        static u32 NonzeroMaskI32(const Vector value) noexcept
        {
            const uint32x4_t bits { 1, 2, 4, 8 };

            return vaddvq_u32(vandq_u32(vtstq_s32(AsI32(value), AsI32(value)), bits));
        }

        [[clang::always_inline]]
        static Vector MaddI16(const Vector left, const Vector right) noexcept
        {
            const auto low  = vmull_s16     (vget_low_s16(left), vget_low_s16(right));
            const auto high = vmull_high_s16(             left ,              right );

            return AsI16(vpaddq_s32(low, high));
        }

        [[clang::always_inline]]
        static i32 ReduceI32(const Vector value) noexcept { return vaddvq_s32(AsI32(value)); }

        [[clang::always_inline]]
        static i64 ReduceI64(const Vector value) noexcept { return vaddlvq_s32(AsI32(value)); }

        [[clang::always_inline]]
        static Vector PackUnsignedI16(const Vector left, const Vector right) noexcept
        { return vreinterpretq_s16_u8(vqmovun_high_s16(vqmovun_s16(left), right)); }

        [[clang::always_inline]]
        static Vector PackU08(const Vector left, const Vector right) noexcept { return PackUnsignedI16(left, right); }

        [[clang::always_inline]]
        static Vector PackI16(const Vector left, const Vector right) noexcept
        { return vqmovn_high_s32(vqmovn_s32(AsI32(left)), AsI32(right)); }

        [[clang::always_inline]]
        static Vector MaddubsI16(const Vector u8, const Vector i8) noexcept
        {
            const auto a = vreinterpretq_u8_s16(u8);
            const auto b = vreinterpretq_s8_s16(i8);

            const auto low  = vmulq_s16(vreinterpretq_s16_u16(vmovl_u8(vget_low_u8(a))), vmovl_s8(vget_low_s8(b)));
            const auto high = vmulq_s16(vreinterpretq_s16_u16(vmovl_high_u8(a)        ), vmovl_high_s8(b)        );

            return vqaddq_s16(vuzp1q_s16(low, high), vuzp2q_s16(low, high));
        }

        [[clang::always_inline]]
        static Vector DotI16(const Vector sum, const Vector left, const Vector right) noexcept
        { return AddI32(sum, MaddI16(left, right)); }

        [[clang::always_inline]]
        static u64 TestMask64(const Vector left, const Vector right) noexcept
        {
            const uint8x16_t bits { 1, 2, 4, 8, 16, 32, 64, 128, 1, 2, 4, 8, 16, 32, 64, 128 };

            const auto set = vandq_u8(vtstq_u8(vreinterpretq_u8_s16(left), vreinterpretq_u8_s16(right)), bits);

            return u64 { vaddv_u8(vget_low_u8(set)) } | u64 { vaddv_u8(vget_high_u8(set)) } << 8;
        }

        [[clang::always_inline]]
        static Vector BlendMaskU08(const Vector mask, const Vector left, const Vector right) noexcept
        {
            const auto select = vcltzq_s8(vreinterpretq_s8_s16(mask));

            return vreinterpretq_s16_u8(vbslq_u8(select, vreinterpretq_u8_s16(right), vreinterpretq_u8_s16(left)));
        }

        [[clang::always_inline]]
        static Vector PutU08(const Vector value, const Vector lanes, const u08 lane, const u08 code) noexcept
        {
            const auto select = vceqq_u8(vreinterpretq_u8_s16(lanes), vdupq_n_u8(lane));

            return vreinterpretq_s16_u8(vbslq_u8(select, vdupq_n_u8(code), vreinterpretq_u8_s16(value)));
        }

        [[clang::always_inline]]
        static Vector Table64(const Array<Vector, 4>& table, const Vector index, const Vector fill) noexcept
        {
            const uint8x16x4_t bytes {{
                vreinterpretq_u8_s16(table[0]),
                vreinterpretq_u8_s16(table[1]),
                vreinterpretq_u8_s16(table[2]),
                vreinterpretq_u8_s16(table[3])
            }};

            return vreinterpretq_s16_u8(vqtbx4q_u8(vreinterpretq_u8_s16(fill), bytes, vreinterpretq_u8_s16(index)));
        }

        [[clang::always_inline]]
        static Vector WidenU08U32(const Vector value) noexcept
        {
            const auto words = vmovl_u8(vget_low_u8(vreinterpretq_u8_s16(value)));

            return AsI16(vreinterpretq_s32_u32(vmovl_u16(vget_low_u16(words))));
        }

        [[clang::always_inline]]
        static Array<Vector, 2> WidenI08(const Vector value) noexcept
        {
            const auto bytes = vreinterpretq_s8_s16(value);

            return { vmovl_s8(vget_low_s8(bytes)), vmovl_high_s8(bytes) };
        }

        [[clang::always_inline]]
        static Vector DotU08I08Wide(const Vector sum, const Vector u8, const Vector i8) noexcept
        {
            const auto a = vreinterpretq_u8_s16(u8);
            const auto b = vreinterpretq_s8_s16(i8);

            const auto low  = vmulq_s16(vreinterpretq_s16_u16(vmovl_u8(vget_low_u8(a))), vmovl_s8(vget_low_s8(b)));
            const auto high = vmulq_s16(vreinterpretq_s16_u16(vmovl_high_u8(a)        ), vmovl_high_s8(b)        );

            return AsI16(vpadalq_s16(vpadalq_s16(AsI32(sum), vuzp1q_s16(low, high)), vuzp2q_s16(low, high)));
        }

        [[clang::always_inline]]
        static Vector DotU08I08(const Vector sum, const Vector u8, const Vector i8) noexcept
        {
            const auto a = vreinterpretq_u8_s16(u8);
            const auto b = vreinterpretq_s8_s16(i8);

            const auto low  = vmulq_s16(vreinterpretq_s16_u16(vmovl_u8(vget_low_u8(a))), vmovl_s8(vget_low_s8(b)));
            const auto high = vmulq_s16(vreinterpretq_s16_u16(vmovl_high_u8(a)        ), vmovl_high_s8(b)        );

            const auto pairs = vqaddq_s16(vuzp1q_s16(low, high), vuzp2q_s16(low, high));

            return AsI16(vpadalq_s16(AsI32(sum), pairs));
        }

        template<s00 N>
        [[clang::always_inline]]
        static VectorF LoadF(const std::array<f32, N>& array, const s00 index) noexcept
        { return vld1q_f32(&array[index]); }

        [[clang::always_inline]]
        static VectorF LoadF(const f32* const address) noexcept { return vld1q_f32(address); }

        [[clang::always_inline]]
        static void StoreF(f32* const address, const VectorF value) noexcept { vst1q_f32(address, value); }

        template<s00 N>
        [[clang::always_inline]]
        static void StoreF(std::array<f32, N>& array, const s00 index, const VectorF value) noexcept
        { vst1q_f32(&array[index], value); }

        [[clang::always_inline]]
        static VectorF ZeroF() noexcept { return vdupq_n_f32(0.0F); }

        [[clang::always_inline]]
        static VectorF BroadcastF(const f32 value) noexcept { return vdupq_n_f32(value); }

        [[clang::always_inline]]
        static VectorF CvtI32F(const Vector value) noexcept { return vcvtq_f32_s32(AsI32(value)); }

        [[clang::always_inline]]
        static VectorF AddF(const VectorF left, const VectorF right) noexcept { return vaddq_f32(left, right); }

        [[clang::always_inline]]
        static VectorF MulF(const VectorF left, const VectorF right) noexcept { return vmulq_f32(left, right); }

        [[clang::always_inline]]
        static VectorF MinF(const VectorF left, const VectorF right) noexcept
        { return vbslq_f32(vcltq_f32(left, right), left, right); }

        [[clang::always_inline]]
        static VectorF MaxF(const VectorF left, const VectorF right) noexcept
        { return vbslq_f32(vcgtq_f32(left, right), left, right); }

        [[clang::always_inline]]
        static VectorF FmaF(const VectorF left, const VectorF right, const VectorF addend) noexcept
        { return vfmaq_f32(addend, left, right); }

        [[clang::always_inline]]
        static f32 ReduceF(const VectorF value) noexcept
        { return vpadds_f32(vadd_f32(vget_low_f32(value), vget_high_f32(value))); }

        [[clang::always_inline]]
        static void Prefetch(const void* const address) noexcept { __builtin_prefetch(address, 0, 3); }

    };

}

#endif

#endif //MANTARAY_BACKEND_ISA_NEON_H
