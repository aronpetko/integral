//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_GRAPH_VALUE_H
#define MANTARAY_GRAPH_VALUE_H

#include <source_location>
#include <type_traits>
#include <utility>

#include "../Common.h"
#include "../IR/GraphIR.h"

namespace MantaRay
{

    namespace Detail
    {

        template<typename T>
        class Shared
        {

            struct Box
            {

                T    Value;
                s00  References = 1;
                Box* Next       = nullptr;

            };

            Box* Pointer = nullptr;

            constexpr static void Release(Box*& pending, Shared& child)
            {
                Box* box = std::exchange(child.Pointer, nullptr);

                if (!box || --box->References != 0) return;

                box->Next = pending;
                pending   = box;
            }

            public:
            constexpr Shared() = default;

            constexpr explicit Shared(T value) : Pointer(new Box { .Value = std::move(value) }) {}

            template<typename... A>
            constexpr explicit Shared(
                      std::in_place_t      ,
                      A&&...          parts
            ) : Pointer(new Box { .Value = T { std::forward<A>(parts)... } }) {}

            constexpr Shared(const Shared& other) : Pointer(other.Pointer) { if (Pointer) Pointer->References++; }

            constexpr Shared(Shared&& other) noexcept : Pointer(std::exchange(other.Pointer, nullptr)) {}

            constexpr Shared& operator =(Shared other) noexcept
            {
                std::swap(Pointer, other.Pointer);

                return *this;
            }

            constexpr ~Shared()
            {
                if (!Pointer || --Pointer->References != 0) return;

                Box* pending = std::exchange(Pointer, nullptr);

                while (pending) {
                    Box* box = pending;

                    pending = box->Next;

                    if constexpr (requires { box->Value.Inputs; })
                        for (Shared& child : box->Value.Inputs) Release(pending, child);

                    delete box;
                }
            }

            constexpr const T& operator  *() const { return  Pointer->Value; }
            constexpr const T* operator ->() const { return &Pointer->Value; }

            constexpr explicit operator bool() const { return Pointer != nullptr; }

        };

        template<typename T>
        constexpr inline u08 Tag = 0;

        constexpr inline s00 Missing = ~s00 { 0 };

        struct Token
        {

            IR::Tensor  Spec {};
            const char* File = nullptr;

            Shared<Token> Base   {};
            Shared<Token> Factor {};

            mutable s00 Order = Missing;

        };

        struct Node;

        class Edges
        {

            Array<Shared<Node>, IR::MaxInputs> Items;

            s00 Count = 0;

            public:
            constexpr Edges() = default;

            constexpr Edges(Shared<Node> first);

            constexpr Edges(Shared<Node> first, Shared<Node> second);

            constexpr void Push(Shared<Node> edge);

            constexpr s00 size() const { return Count; }

            constexpr       Shared<Node>& operator [](const s00 i)       { return Items[i]; }
            constexpr const Shared<Node>& operator [](const s00 i) const { return Items[i]; }

            constexpr       Shared<Node>* begin()       { return Items.data(); }
            constexpr const Shared<Node>* begin() const { return Items.data(); }
            constexpr       Shared<Node>* end  ()       { return Items.data() + Count; }
            constexpr const Shared<Node>* end  () const { return Items.data() + Count; }

        };

        struct Node
        {

            IR::Node    Spec {};
            const char* File = nullptr;

            Edges Inputs {};

            Shared<Token> Tensor {};

            const u08* Binding = nullptr;

            IR::Fault   Fault     {};
            const char* FaultFile = nullptr;

            mutable s00         Order     = Missing;
            mutable s00         Next      = 0;
            mutable const Node* Parent    = nullptr;
            mutable const Node* Following = nullptr;

        };

        constexpr Edges::Edges(Shared<Node> first) : Items { std::move(first) }, Count(1) {}

        constexpr Edges::Edges(
                  Shared<Node> first ,
                  Shared<Node> second
        ) : Items { std::move(first), std::move(second) }, Count(2) {}

        constexpr void Edges::Push(Shared<Node> edge) { Items[Count++] = std::move(edge); }

        struct Placed
        {

            IR::Node    Spec {};
            const char* File = nullptr;

        };

        constexpr Placed Located(IR::Node spec, const std::source_location& site)
        {
            spec.Line   = static_cast<u16>(site.line  ());
            spec.Column = static_cast<u16>(site.column());

            return { .Spec = spec, .File = site.file_name() };
        }

        template<typename V>
        struct Here
        {

            const V&             Value;
            std::source_location Site;

            constexpr Here(
                const V&                    value                               ,
                const std::source_location& site = std::source_location::current()
            ) : Value(value), Site(site) {}

        };

        template<typename T, typename... L>
        constexpr inline bool Among = (std::is_same_v<T, L> || ...);

        template<typename... T>
        constexpr inline bool Never = false;

    }

    namespace Expect
    {

        constexpr IR::Fault Raise(const IR::FaultCode code, const i64 a = 0, const i64 b = 0, const i64 c = 0)
        {
            return { .Code = code, .Values = { a, b, c } };
        }

        constexpr IR::Fault SameSize(const u32 left, const u32 right)
        {
            return left == right ? IR::Fault {} : Raise(IR::FaultCode::SizeMismatch, left, right);
        }

        constexpr IR::Fault AffineInputSize(const u32 expected, const u32 actual)
        {
            return expected == actual ? IR::Fault {} : Raise(IR::FaultCode::InputSize, expected, actual);
        }

        constexpr IR::Fault SliceInside(const u32 begin, const u32 end, const u32 size)
        {
            return begin < end && end <= size ? IR::Fault {} : Raise(IR::FaultCode::SliceOutside, begin, end, size);
        }

        constexpr IR::Fault EvenSize(const u32 size)
        {
            return size % 2 == 0 ? IR::Fault {} : Raise(IR::FaultCode::OddSize, size);
        }

        constexpr IR::Fault DivisibleIntoBuckets(const u32 size, const u32 buckets)
        {
            return size % buckets == 0 ? IR::Fault {} : Raise(IR::FaultCode::BucketSplit, size, buckets);
        }

        constexpr IR::Fault OrderedBounds(const Rational low, const Rational high)
        {
            return low < high ? IR::Fault {} : Raise(IR::FaultCode::BoundOrder);
        }

        constexpr IR::Fault DenseOperand(const bool sparse)
        {
            return sparse ? Raise(IR::FaultCode::SparseOperand) : IR::Fault {};
        }

    }

    template<typename... B>
    class Value;

    namespace Detail
    {

        template<typename V, typename... T>
        struct Append;

        template<typename... A>
        struct Append<Value<A...>> { using Type = Value<A...>; };

        template<typename... A, typename T, typename... R>
        struct Append<Value<A...>, T, R...>
        {

            using Next = std::conditional_t<(std::is_same_v<A, T> || ...), Value<A...>, Value<A..., T>>;

            using Type = Append<Next, R...>::Type;

        };

        template<typename L, typename R>
        struct Merge;

        template<typename... A, typename... C>
        struct Merge<Value<A...>, Value<C...>> { using Type = Append<Value<A...>, C...>::Type; };

        template<typename V, typename... T>
        using With = Append<V, T...>::Type;

        constexpr IR::Node Spec(const IR::Op operation, const u32 size)
        {
            IR::Node node {};

            node.Operation = operation;
            node.Size      = size;

            return node;
        }

        template<typename V, typename L, typename R>
        constexpr V Binary(const IR::Op operation, const L& left, const R& right, const std::source_location& site);

        template<typename V>
        constexpr V WithScalar(const IR::Op operation, const V& x, const f64 value, const std::source_location& site);

        template<typename V>
        constexpr V Shifted(const IR::Op operation, const V& x, const u16 shift, const std::source_location& site);

    }

    template<typename L, typename R>
    using Union = Detail::Merge<L, R>::Type;

    template<typename... B>
    class Value
    {

        Detail::Shared<Detail::Node> Root;

        public:
        constexpr explicit Value(Detail::Shared<Detail::Node> root) : Root(std::move(root)) {}

        template<typename... C>
        constexpr Value(
            const Value<C...>& narrower
        ) requires (Detail::Among<C, B...> && ...) : Root(narrower.Handle()) {}

        template<typename... C>
        constexpr Value(
            const Value<C...>& wider
        ) requires (!(Detail::Among<C, B...> && ...)) : Root(wider.Handle())
        {
            static_assert(
                Detail::Never<C...>,
                "this value depends on a family or selector the target Value<...> does not list; "
                "declare the variable with every family and selector it will hold"
            );
        }

        constexpr const Detail::Shared<Detail::Node>& Handle() const { return Root; }

        constexpr u32 Size() const { return Root->Spec.Size; }

        constexpr bool Sparse() const { return Root->Spec.Operation == IR::Op::Input; }

        template<typename... R>
        friend constexpr Union<Value, Value<R...>> operator +(const Detail::Here<Value>& left, const Value<R...>& right)
        {
            return Detail::Binary<Union<Value, Value<R...>>>(IR::Op::Add, left.Value, right, left.Site);
        }

        template<typename... R>
        friend constexpr Union<Value, Value<R...>> operator -(const Detail::Here<Value>& left, const Value<R...>& right)
        {
            const Value<R...> negated = Detail::WithScalar(IR::Op::Mul, right, -1, left.Site);

            return Detail::Binary<Union<Value, Value<R...>>>(IR::Op::Add, left.Value, negated, left.Site);
        }

        template<typename... R>
        friend constexpr Union<Value, Value<R...>> operator *(const Detail::Here<Value>& left, const Value<R...>& right)
        {
            return Detail::Binary<Union<Value, Value<R...>>>(IR::Op::Mul, left.Value, right, left.Site);
        }

        friend constexpr Value operator +(const Detail::Here<Value>& left, const f64 value)
        { return Detail::WithScalar(IR::Op::Add, left.Value, value, left.Site); }

        friend constexpr Value operator -(const Detail::Here<Value>& left, const f64 value)
        { return Detail::WithScalar(IR::Op::Add, left.Value, -value, left.Site); }

        friend constexpr Value operator *(const Detail::Here<Value>& left, const f64 value)
        { return Detail::WithScalar(IR::Op::Mul, left.Value, value, left.Site); }

        friend constexpr Value operator *(const f64 value, const Detail::Here<Value>& right)
        { return Detail::WithScalar(IR::Op::Mul, right.Value, value, right.Site); }

        friend constexpr Value operator /(const Detail::Here<Value>& left, const f64 value)
        { return Detail::WithScalar(IR::Op::Mul, left.Value, 1 / value, left.Site); }

        friend constexpr Value operator >>(const Detail::Here<Value>& left, const u16 shift)
        { return Detail::Shifted(IR::Op::ShiftRight, left.Value, shift, left.Site); }

        friend constexpr Value operator <<(const Detail::Here<Value>& left, const u16 shift)
        { return Detail::Shifted(IR::Op::ShiftLeft, left.Value, shift, left.Site); }

    };

    namespace Detail
    {

        constexpr IR::Fault Blame(IR::Fault fault, const IR::Node& spec)
        {
            if (fault.Code == IR::FaultCode::None) return fault;

            fault.Operation = spec.Operation;
            fault.Line      = spec.Line;
            fault.Column    = spec.Column;

            return fault;
        }

        template<typename V>
        constexpr V Make(
            const Placed&       placed           ,
                  Edges         inputs           ,
            const IR::Fault     fault   = {}     ,
                  Shared<Token> tensor  = {}     ,
            const u08*          binding = nullptr
        )
        {
            IR::Fault   carried {};
            const char* where   = nullptr;

            for (const Shared<Node>& input : inputs)
                if (carried.Code == IR::FaultCode::None && input->Fault.Code != IR::FaultCode::None) {
                    carried = input->Fault;
                    where   = input->FaultFile;
                }

            if (carried.Code == IR::FaultCode::None && fault.Code != IR::FaultCode::None) {
                carried = Blame(fault, placed.Spec);
                where   = placed.File;
            }

            IR::Node spec = placed.Spec;

            spec.InputCount = static_cast<u08>(inputs.size());

            Shared<Node> node {
                std::in_place, spec, placed.File, std::move(inputs), std::move(tensor), binding, carried, where
            };

            return V { std::move(node) };
        }

    }

}

#endif //MANTARAY_GRAPH_VALUE_H
