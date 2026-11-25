//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_COMMON_H
#define MANTARAY_COMMON_H

#include <algorithm>
#include <array>
#include <bit>
#include <concepts>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <string_view>
#include <type_traits>
#include <utility>

namespace MantaRay
{

    using s00 = std::size_t;

    using u64 = std::uint64_t;
    using i64 = std:: int64_t;

    using u32 = std::uint32_t;
    using i32 = std:: int32_t;

    using u16 = std::uint16_t;
    using i16 = std:: int16_t;

    using u08 = std::uint8_t;
    using i08 = std:: int8_t;

    using f32 = float;
    using f64 = double;

    template<typename T>
    constexpr T WrapAdd(const T left, const T right)
    {
        using U = std::make_unsigned_t<T>;

        return std::bit_cast<T>(static_cast<U>(static_cast<u64>(static_cast<U>(left)) + static_cast<U>(right)));
    }

    template<typename T>
    constexpr T WrapSub(const T left, const T right)
    {
        using U = std::make_unsigned_t<T>;

        return std::bit_cast<T>(static_cast<U>(static_cast<u64>(static_cast<U>(left)) - static_cast<U>(right)));
    }

    template<typename T>
    constexpr T WrapMul(const T left, const T right)
    {
        using U = std::make_unsigned_t<T>;

        return std::bit_cast<T>(static_cast<U>(static_cast<u64>(static_cast<U>(left)) * static_cast<U>(right)));
    }

    constexpr inline s00 Alignment = 64;

    template<u08>
    struct Absent {};

    template<typename T, typename W>
    constexpr inline bool IsWidening =  std::is_same_v<T, W>                              ||
                                       (std::is_same_v<T, i16> && std::is_same_v<W, i08>) ||
                                       (std::is_same_v<T, i32> && std::is_same_v<W, i16>) ||
                                       (std::is_same_v<T, i32> && std::is_same_v<W, i08>)  ;

    namespace Detail
    {

        template<typename T>
        constexpr inline bool UnderAligned = alignof(std::array<T, 1>) < alignof(T);

        template<typename T, s00 N>
        struct alignas(T) Realigned : std::array<T, N> {};

        template<typename T, s00 N>
        using Flat = std::conditional_t<UnderAligned<T>, Realigned<T, N>, std::array<T, N>>;

        template<typename T, s00 N, s00... Ns>
        struct Nest { using Type = Flat<typename Nest<T, Ns...>::Type, N>; };

        template<typename T, s00 N>
        struct Nest<T, N> { using Type = Flat<T, N>; };

    }

    template<typename T, s00... Ns>
    using Array = Detail::Nest<T, Ns...>::Type;

    namespace Detail
    {

        template<typename T>
        class Buffer
        {

            T*  Items    = nullptr;
            s00 Count    = 0;
            s00 Capacity = 0;

            constexpr explicit Buffer(
                T* const  items   ,
                const s00 count   ,
                const s00 capacity
            ) : Items(items), Count(count), Capacity(capacity) {}

            constexpr static Buffer Zeroed(const s00 count, const s00 capacity)
            { return Buffer(new T[capacity](), count, capacity); }

            constexpr static Buffer Uninitialized(const s00 count, const s00 capacity)
            { return Buffer(new T[capacity], count, capacity); }

            public:
            constexpr Buffer() = default;

            constexpr explicit Buffer(const s00 count) : Buffer(Zeroed(count, count)) {}

            constexpr explicit Buffer(const s00 count, const T fill) : Buffer(Uninitialized(count, count))
            {
                for (s00 i = 0; i < count; i++) Items[i] = fill;
            }

            constexpr static Buffer Reserved(const s00 capacity) { return Uninitialized(0, capacity); }

            constexpr Buffer(Buffer&& other) noexcept : Items   (std::exchange(other.Items   , nullptr)),
                                                        Count   (std::exchange(other.Count   , 0      )),
                                                        Capacity(std::exchange(other.Capacity, 0      )) {}

            constexpr Buffer& operator =(Buffer&& other) noexcept
            {
                std::swap(Items   , other.Items   );
                std::swap(Count   , other.Count   );
                std::swap(Capacity, other.Capacity);

                return *this;
            }

            Buffer(const Buffer&) = delete;

            Buffer& operator =(const Buffer&) = delete;

            constexpr ~Buffer() { delete[] Items; }

            constexpr void Push(const T& item) { Items[Count++] = item; }

            constexpr s00 size() const { return Count; }

            constexpr const T* data() const { return Items; }

            constexpr       T& operator [](const s00 i)       { return Items[i]; }
            constexpr const T& operator [](const s00 i) const { return Items[i]; }

            constexpr       T* begin()       { return Items; }
            constexpr const T* begin() const { return Items; }
            constexpr       T* end  ()       { return Items + Count; }
            constexpr const T* end  () const { return Items + Count; }

        };

    }

    struct Interval
    {

        i64 Min = 0;
        i64 Max = 0;

        constexpr bool operator ==(const Interval&) const = default;

    };

    struct Rational
    {

        i64 Numerator   = 0;
        i64 Denominator = 0;

        constexpr bool operator ==(const Rational&) const = default;

    };

    namespace Detail
    {

        using i128 = __int128;

        constexpr inline i64 Saturation = std::numeric_limits<i64>::max();

        constexpr i64 Saturate(const i128 value)
        {
            if (value >  Saturation) return  Saturation;
            if (value < -Saturation) return -Saturation;

            return static_cast<i64>(value);
        }

        constexpr i64 Narrow(const i128 value)
        {
            if (value > std::numeric_limits<i64>::max() || value < std::numeric_limits<i64>::min()) __builtin_trap();

            return static_cast<i64>(value);
        }

        constexpr i128 Gcd(i128 left, i128 right)
        {
            while (right != 0) {
                const i128 rest = left % right;

                left  = right;
                right = rest ;
            }

            return left < 0 ? -left : left;
        }

        constexpr Rational Reduce(i128 numerator, i128 denominator)
        {
            if (denominator == 0) __builtin_trap();

            if (denominator < 0) {
                numerator   = -numerator  ;
                denominator = -denominator;
            }

            const i128 divisor = numerator == 0 ? denominator : Gcd(numerator, denominator);

            return { .Numerator = Narrow(numerator / divisor), .Denominator = Narrow(denominator / divisor) };
        }

    }

    constexpr Rational Ratio(const i64 numerator, const i64 denominator = 1)
    {
        return Detail::Reduce(numerator, denominator);
    }

    constexpr bool Defined(const Rational value) { return value.Denominator != 0; }

    constexpr bool Integral(const Rational value) { return value.Denominator == 1; }

    constexpr Rational operator *(const Rational left, const Rational right)
    {
        return Detail::Reduce(
            Detail::i128 { left.Numerator   } * right.Numerator  ,
            Detail::i128 { left.Denominator } * right.Denominator
        );
    }

    constexpr Rational operator /(const Rational left, const Rational right)
    {
        return Detail::Reduce(
            Detail::i128 { left.Numerator   } * right.Denominator,
            Detail::i128 { left.Denominator } * right.Numerator
        );
    }

    constexpr Rational operator +(const Rational left, const Rational right)
    {
        return Detail::Reduce(
            Detail::i128 { left.Numerator } * right.Denominator + Detail::i128 { right.Numerator } * left.Denominator,
            Detail::i128 { left.Denominator } * right.Denominator
        );
    }

    constexpr bool operator <(const Rational left, const Rational right)
    {
        const Detail::i128 lhs = Detail::i128 { left .Numerator } * right.Denominator;
        const Detail::i128 rhs = Detail::i128 { right.Numerator } * left .Denominator;

        return lhs < rhs;
    }

    constexpr Rational ShiftDown(const Rational value, const s00 shift)
    {
        return Detail::Reduce(value.Numerator, Detail::i128 { value.Denominator } << shift);
    }

    constexpr Rational ShiftUp(const Rational value, const s00 shift)
    {
        return Detail::Reduce(Detail::i128 { value.Numerator } << shift, value.Denominator);
    }

    constexpr i64 Floor(const Rational value)
    {
        const i64 quotient = value.Numerator / value.Denominator;

        return quotient * value.Denominator > value.Numerator ? quotient - 1 : quotient;
    }

    constexpr i64 Ceil(const Rational value)
    {
        return -Floor({ .Numerator = -value.Numerator, .Denominator = value.Denominator });
    }

    constexpr i64 RoundHalfAway(const Rational value)
    {
        const Rational half = value.Numerator < 0 ? Ratio(-1, 2) : Ratio(1, 2);
        const Rational sum  = value + half;

        return sum.Numerator / sum.Denominator;
    }

    constexpr f64 ToDouble(const Rational value)
    {
        return static_cast<f64>(value.Numerator) / static_cast<f64>(value.Denominator);
    }

    namespace Detail
    {

        constexpr f64 Magnitude(const f64 value) { return value < 0 ? -value : value; }

        constexpr Rational Approximate(const f64 value)
        {
            i128 previousNumerator   = 1;
            i128 previousDenominator = 0;

            i128 numerator           = static_cast<i64>(value);
            i128 denominator         = 1;

            f64 rest = value - static_cast<f64>(static_cast<i64>(value));

            for (s00 i = 0; i < 40; i++) {
                const f64 error = Magnitude(static_cast<f64>(numerator) / static_cast<f64>(denominator) - value);

                if (error <= Magnitude(value) * 1e-13 || rest == 0) break;

                const f64 inverse = 1 / rest;
                const i64 term    = static_cast<i64>(inverse);

                const i128 nextNumerator   = term * numerator   + previousNumerator  ;
                const i128 nextDenominator = term * denominator + previousDenominator;

                previousNumerator   = numerator      ;
                previousDenominator = denominator    ;

                numerator           = nextNumerator  ;
                denominator         = nextDenominator;

                rest = inverse - static_cast<f64>(term);
            }

            return Reduce(numerator, denominator);
        }

    }

    constexpr Rational RationalOf(const f64 value)
    {
        if (value < 0) {
            const Rational positive = RationalOf(-value);

            return { .Numerator = -positive.Numerator, .Denominator = positive.Denominator };
        }

        f64 scaled      = value;
        i64 denominator = 1;

        for (s00 i = 0; i < 24 && scaled != static_cast<f64>(static_cast<i64>(scaled)); i++) {
            scaled      *= 2;
            denominator *= 2;
        }

        if (scaled == static_cast<f64>(static_cast<i64>(scaled))) return Ratio(static_cast<i64>(scaled), denominator);

        return Detail::Approximate(value);
    }

    constexpr Interval operator +(const Interval left, const Interval right)
    {
        return {
            .Min = Detail::Saturate(Detail::i128 { left.Min } + right.Min),
            .Max = Detail::Saturate(Detail::i128 { left.Max } + right.Max)
        };
    }

    constexpr Interval operator -(const Interval left, const Interval right)
    {
        return {
            .Min = Detail::Saturate(Detail::i128 { left.Min } - right.Max),
            .Max = Detail::Saturate(Detail::i128 { left.Max } - right.Min)
        };
    }

    constexpr Interval operator *(const Interval left, const Interval right)
    {
        const Detail::i128 a = Detail::i128 { left.Min } * right.Min;
        const Detail::i128 b = Detail::i128 { left.Min } * right.Max;
        const Detail::i128 c = Detail::i128 { left.Max } * right.Min;
        const Detail::i128 d = Detail::i128 { left.Max } * right.Max;

        return { .Min = Detail::Saturate(std::min({ a, b, c, d })), .Max = Detail::Saturate(std::max({ a, b, c, d })) };
    }

    constexpr Interval Repeat(const Interval interval, const s00 count)
    {
        const Detail::i128 low  = Detail::i128 { interval.Min } * count;
        const Detail::i128 high = Detail::i128 { interval.Max } * count;

        return {
            .Min = Detail::Saturate(std::min<Detail::i128>(low , 0)),
            .Max = Detail::Saturate(std::max<Detail::i128>(high, 0))
        };
    }

    constexpr Interval Clamp(const Interval interval, const i64 lower, const i64 upper)
    {
        return { .Min = std::clamp(interval.Min, lower, upper), .Max = std::clamp(interval.Max, lower, upper) };
    }

    constexpr Interval Square(const Interval interval)
    {
        const Detail::i128 low  = Detail::i128 { interval.Min } * interval.Min;
        const Detail::i128 high = Detail::i128 { interval.Max } * interval.Max;

        const bool straddles = interval.Min <= 0 && interval.Max >= 0;

        return {
            .Min = Detail::Saturate(straddles ? 0 : std::min(low, high)),
            .Max = Detail::Saturate(                std::max(low, high))
        };
    }

    constexpr Interval ShiftDown(const Interval interval, const s00 shift)
    {
        const s00 amount = std::min<s00>(shift, 63);

        return { .Min = interval.Min >> amount, .Max = interval.Max >> amount };
    }

    constexpr Interval ShiftUp(const Interval interval, const s00 shift)
    {
        return {
            .Min = Detail::Saturate(Detail::i128 { interval.Min } << shift),
            .Max = Detail::Saturate(Detail::i128 { interval.Max } << shift)
        };
    }

    constexpr Interval Divide(const Interval interval, const i64 divisor)
    {
        const i64 low  = interval.Min / divisor;
        const i64 high = interval.Max / divisor;

        return { .Min = std::min(low, high), .Max = std::max(low, high) };
    }

    constexpr Interval Hull(const Interval left, const Interval right)
    {
        return { .Min = std::min(left.Min, right.Min), .Max = std::max(left.Max, right.Max) };
    }

    template<std::integral T>
    constexpr bool Fits(const Interval interval)
    {
        return Detail::i128 { interval.Min } >= std::numeric_limits<T>::min() &&
               Detail::i128 { interval.Max } <= std::numeric_limits<T>::max() ;
    }

    constexpr bool Bounded(const Interval interval)
    {
        return interval.Min > -Detail::Saturation && interval.Max < Detail::Saturation;
    }

    template<typename... T>
    struct List
    {

        constexpr static s00 Size = sizeof...(T);

    };

    template<s00 I, typename... T>
    using At = __type_pack_element<I, T...>;

    class Message
    {

        constexpr static s00 Capacity = 256;

        Array<char, Capacity> Buffer {};

        s00 Length = 0;

        constexpr void Append(const char character)
        {
            if (Length < Capacity - 1) Buffer[Length++] = character;
        }

        public:
        constexpr Message& operator <<(const std::string_view text)
        {
            for (const char character : text) Append(character);

            return *this;
        }

        constexpr Message& operator <<(const i64 value)
        {
            if (value < 0) Append('-');

            u64 rest = value < 0 ? 0 - static_cast<u64>(value) : static_cast<u64>(value);

            Array<char, 20> digits {};

            s00 count = 0;

            do {
                digits[count++] = static_cast<char>('0' + rest % 10);

                rest /= 10;
            } while (rest != 0);

            while (count != 0) Append(digits[--count]);

            return *this;
        }

        constexpr Message& operator <<(const Rational value)
        {
            *this << value.Numerator;

            if (value.Denominator != 1) *this << "/" << value.Denominator;

            return *this;
        }

        constexpr const char* data() const { return Buffer.data(); }

        constexpr s00 size() const { return Length; }

    };

}

#if defined(_MSC_VER)
#define NO_UNIQUE_ADDRESS [[msvc::no_unique_address]]
#else
#define NO_UNIQUE_ADDRESS [[no_unique_address]]
#endif

#define ALIGN_4  alignas(4)
#define ALIGN_8  alignas(8)
#define ALIGN_16 alignas(16)
#define ALIGN_32 alignas(32)
#define ALIGN_64 alignas(64)

#if defined(__x86_64__)
#define ALIGN_ARRAY ALIGN_16
#else
#define ALIGN_ARRAY
#endif

#define PRAGMA(x) _Pragma(#x)
#define UNROLL(x) PRAGMA(clang loop unroll(x))

#endif //MANTARAY_COMMON_H
