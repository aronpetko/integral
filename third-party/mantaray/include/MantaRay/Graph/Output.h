//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_GRAPH_OUTPUT_H
#define MANTARAY_GRAPH_OUTPUT_H

#include <source_location>
#include <string_view>
#include <type_traits>
#include <vector>

#include "Layer.h"
#include "Value.h"
#include "../Common.h"
#include "../FeatureSet/FeatureSet.h"
#include "../IR/GraphIR.h"

namespace MantaRay
{

    struct FileItem
    {

        IR::ItemKind                  Kind   = IR::ItemKind::None;
        Detail::Shared<Detail::Token> Tensor {};
        u32                           Count  = 0;
        u16                           Span   = 0;
        u64                           Value  = 0;

    };

    struct Bytes
    {

        u32 Count = 0;

    };

    struct Magic
    {

        u64 Value = 0;
        u32 Count = 0;

        template<s00 N>
        consteval explicit Magic(const char (&text)[N]) : Count(N - 1)
        {
            static_assert(N - 1 <= 8, "a magic value holds at most 8 bytes");

            for (s00 i = 0; i + 1 < N; i++) Value |= u64 { static_cast<u08>(text[i]) } << (8 * i);
        }

    };

    template<typename T>
    struct Constant
    {

        T Value {};

        constexpr explicit Constant(const T value) : Value(value) {}

    };

    template<typename T>
    struct Text {};

    class FileSpec
    {

        std::vector<FileItem> Entries {};

        IR::File Options {};

        constexpr void Add(const TensorRef& tensor)
        {
            Entries.push_back({ .Kind = IR::ItemKind::Tensor, .Tensor = tensor.Handle() });
        }

        template<typename... F>
        constexpr void Add(const Value<F...>& parameter) { Add(TensorOf(parameter)); }

        constexpr void Add(const Bytes& bytes)
        { Entries.push_back({ .Kind = IR::ItemKind::Bytes, .Count = bytes.Count }); }

        constexpr void Add(const Magic& magic)
        {
            Entries.push_back({ .Kind = IR::ItemKind::Constant, .Count = magic.Count, .Value = magic.Value });
        }

        template<typename T>
        constexpr void Add(const Constant<T>& constant)
        {
            Entries.push_back({
                .Kind  = IR::ItemKind::Constant,
                .Count = sizeof(T),
                .Value = static_cast<u64>(static_cast<std::make_unsigned_t<T>>(constant.Value))
            });
        }

        template<typename T>
        constexpr void Add(const Text<T>&) { Entries.push_back({ .Kind = IR::ItemKind::Text, .Count = sizeof(T) }); }

        constexpr void Add(const FileSpec& block)
        {
            for (const FileItem& entry : block.Entries) Entries.push_back(entry);
        }

        public:
        template<typename... I>
        constexpr explicit FileSpec(const IR::File& options, const I&... items) : Options(options)
        { (Add(items), ...); }

        template<typename S, typename... I>
        constexpr static FileSpec Block(const I&... items)
        {
            FileSpec block(IR::File {}, items...);

            const u16 span = static_cast<u16>(block.Entries.size());

            const FileItem head { .Kind = IR::ItemKind::Block, .Count = S::Count, .Span = span };

            block.Entries.insert(block.Entries.begin(), head);

            return block;
        }

        constexpr const std::vector<FileItem>& Items() const { return Entries; }

        constexpr IR::File Format() const { return Options; }

        constexpr FileSpec Compressed() const
        {
            FileSpec copy = *this;

            copy.Options.Encoding = IR::Encoding::Leb128;

            return copy;
        }

    };

    template<typename... I>
    constexpr FileSpec Bullet(const I&... items)
    { return FileSpec(IR::File { .Padding = IR::Padding::Bullet }, items...); }

    template<typename... I>
    constexpr FileSpec Exact(const I&... items)
    { return FileSpec(IR::File { .Padding = IR::Padding::Exact }, items...); }

    template<typename... I>
    constexpr FileSpec Aligned(const I&... items)
    { return FileSpec(IR::File { .Padding = IR::Padding::Zeros }, items...); }

    template<typename S, typename... I>
    constexpr FileSpec Block(const I&... items) { return FileSpec::Block<S>(items...); }

    template<typename... F>
    struct Head
    {

        Value<F...>          Root;
        Rational             Scale;
        std::source_location Site;

        constexpr explicit Head(
            const Value<F...>&          root                                ,
            const f64                   scale                               ,
            const std::source_location& site = std::source_location::current()
        ) : Root(root), Scale(RationalOf(scale)), Site(site) {}

    };

    namespace Detail
    {

        template<typename T>
        constexpr void Place(std::vector<const T*>& list, const T* item)
        {
            item->Order = list.size();

            list.push_back(item);
        }

        struct Ordered
        {

            const Node* First = nullptr;
            const Node* Last  = nullptr;

            s00 Count = 0;

        };

        constexpr void Visit(Ordered& order, const Node& root)
        {
            if (root.Order != Missing) return;

            root.Next   = 0;
            root.Parent = nullptr;

            const Node* current = &root;

            while (current) {
                if (current->Next < current->Inputs.size()) {
                    const Node* child = &*current->Inputs[current->Next++];

                    if (child->Order != Missing) continue;

                    child->Next   = 0;
                    child->Parent = current;

                    current = child;

                    continue;
                }

                current->Order = order.Count++;

                if (order.Last) order.Last->Following = current;
                else            order.First           = current;

                order.Last = current;
                current    = current->Parent;
            }
        }

        constexpr void Declare(std::vector<const Token*>& tokens, const Token& token)
        {
            if (token.Order != Missing) return;

            if (token.Base  ) Declare(tokens, *token.Base  );
            if (token.Factor) Declare(tokens, *token.Factor);

            Place(tokens, &token);
        }

        constexpr std::string_view Basename(const std::string_view full)
        {
            const s00 slash = full.find_last_of('/');

            return slash == std::string_view::npos ? full : full.substr(slash + 1);
        }

        struct Interned
        {

            std::string_view Path {};
            std::string_view Name {};

        };

        constexpr bool Equal(const std::string_view left, const std::string_view right)
        { return left.size() == right.size() && __builtin_memcmp(left.data(), right.data(), left.size()) == 0; }

        constexpr u16 Intern(std::vector<Interned>& files, const char* path)
        {
            if (!path) return 0;

            const std::string_view full { path, __builtin_strlen(path) };

            for (s00 i = 0; i < files.size(); i++)
                if (Equal(files[i].Path, full)) return static_cast<u16>(i + 1);

            const std::string_view name = Basename(full);

            for (s00 i = 0; i < files.size(); i++)
                if (Equal(files[i].Name, name)) return static_cast<u16>(i + 1);

            files.push_back({ .Path = full, .Name = name });

            return static_cast<u16>(files.size());
        }

        struct Collected
        {

            Ordered                   Order  {};
            std::vector<const Token*> Tokens {};
            std::vector<Interned>     Files  {};

            s00 Items = 0;

        };

        struct Restored
        {

            const Collected& Pass;

            constexpr ~Restored()
            {
                for (const Node* node = Pass.Order.First; node; node = node->Following) node->Order = Missing;

                for (const Token* token : Pass.Tokens) token->Order = Missing;
            }

        };

    }

    template<typename... B>
    class Graph
    {

        std::vector<Detail::Shared<Detail::Node>> Roots  {};
        std::vector<Rational>                     Scales {};
        std::vector<std::source_location>         Sites  {};

        FileSpec File    { IR::File {} };
        bool     Written = false;

        constexpr Detail::Collected Collect() const
        {
            Detail::Collected collected {};

            for (const Detail::Shared<Detail::Node>& root : Roots) Detail::Visit(collected.Order, *root);

            if (collected.Order.Last) collected.Order.Last->Following = nullptr;

            for (const Detail::Node* node = collected.Order.First; node; node = node->Following)
                if (node->Tensor) Detail::Declare(collected.Tokens, *node->Tensor);

            for (const Detail::Token* token : collected.Tokens) {
                Detail::Intern(collected.Files, token->File);

                collected.Items += token->Spec.Role != IR::Role::Folded;
            }

            for (const std::source_location& site : Sites) Detail::Intern(collected.Files, site.file_name());

            for (const FileItem& item : File.Items())
                if (item.Kind == IR::ItemKind::Tensor) Detail::Intern(collected.Files, item.Tensor->File);

            if (Written) collected.Items = File.Items().size();

            return collected;
        }

        constexpr static u16 IndexOf(const u08* tag)
        {
            constexpr Array<const u08*, sizeof...(B)> Tags { &Detail::Tag<B>... };

            for (s00 i = 0; i < sizeof...(B); i++)
                if (Tags[i] == tag) return static_cast<u16>(i + 1);

            return 0;
        }

        constexpr IR::Fault Capacity(Detail::Collected& collected) const
        {
            const s00 nodes       = collected.Order.Count;
            const s00 tensors     = collected.Tokens.size();
            const s00 steps       = nodes * IR::StepsPerNode;
            const s00 featureSets = (0 + ... + (FeatureSet<B> ? 1 : 0));

            IR::Fault fault {};

            if (nodes > IR::MaxIndex || tensors > IR::MaxIndex)
                fault = Expect::Raise(IR::FaultCode::IndexCapacity, nodes, tensors, IR::MaxIndex);
            else if (steps > IR::StepLimit)
                fault = Expect::Raise(IR::FaultCode::StepBudget, nodes, steps, IR::StepLimit);
            else if (featureSets > IR::MaxFeatureSet)
                fault = Expect::Raise(IR::FaultCode::FeatureSetCapacity, featureSets, IR::MaxFeatureSet);

            if (fault.Code == IR::FaultCode::None) return fault;

            fault.File   = Detail::Intern(collected.Files, Sites[0].file_name());
            fault.Line   = static_cast<u16>(Sites[0].line  ());
            fault.Column = static_cast<u16>(Sites[0].column());

            return fault;
        }

        public:
        template<typename... H>
        constexpr explicit Graph(
            const H&... heads
        ) : Roots ({ heads.Root.Handle()... }),
            Scales({ heads.Scale... }),
            Sites ({ heads.Site... }) {}

        template<typename... H>
        constexpr explicit Graph(const FileSpec& file, const H&... heads) : Graph(heads...)
        {
            File    = file;
            Written = true;
        }

        constexpr IR::Sizes Measure() const
        {
            Detail::Collected collected = Collect();

            const Detail::Restored restored { collected };

            const IR::Fault fault = Capacity(collected);

            for (const Detail::Node* node = collected.Order.First; node; node = node->Following) {
                Detail::Intern(collected.Files, node->File);

                if (node->FaultFile) Detail::Intern(collected.Files, node->FaultFile);
            }

            return {
                .Nodes    = static_cast<u32>(fault.Code == IR::FaultCode::None ? collected.Order.Count : 0),
                .Tensors  = static_cast<u32>(fault.Code == IR::FaultCode::None ? collected.Tokens.size() : 0),
                .Bindings = static_cast<u32>(sizeof...(B)),
                .Heads    = static_cast<u32>(Roots.size()),
                .Items    = static_cast<u32>(fault.Code == IR::FaultCode::None ? collected.Items : 0),
                .Files    = static_cast<u32>(collected.Files.size())
            };
        }

        template<IR::Sizes S>
        constexpr IR::Graph<S> Freeze() const
        {
            IR::Graph<S> graph {};

            graph.Bindings = { Detail::BindingOf<B, B...>()... };

            Detail::Collected collected = Collect();

            const Detail::Restored restored { collected };

            std::vector<Detail::Interned>& files = collected.Files;

            graph.Fault = Capacity(collected);

            const auto name = [&] {
                for (s00 i = 0; i < S.Files && i < files.size(); i++)
                for (s00 c = 0; c < files[i].Name.size() && c + 1 < IR::NameSize; c++)
                    graph.Files[i][c] = files[i].Name[c];
            };

            if (graph.Fault.Code != IR::FaultCode::None) {
                name();

                return graph;
            }

            const Detail::Node* next = collected.Order.First;

            for (s00 i = 0; i < S.Nodes; i++, next = next->Following) {
                const Detail::Node& node = *next;

                IR::Node& spec = graph.Nodes[i];

                spec = node.Spec;

                for (s00 input = 0; input < node.Inputs.size(); input++)
                    spec.Inputs[input] = static_cast<u16>(node.Inputs[input]->Order);

                if (node.Tensor ) spec.Tensor  = static_cast<u16>(node.Tensor->Order + 1);
                if (node.Binding) spec.Binding = IndexOf(node.Binding);

                spec.File = Detail::Intern(files, node.File);

                if (graph.Fault.Code == IR::FaultCode::None && node.Fault.Code != IR::FaultCode::None) {
                    graph.Fault      = node.Fault;
                    graph.Fault.File = Detail::Intern(files, node.FaultFile);
                }
            }

            for (s00 i = 0; i < S.Heads; i++)
                graph.Heads[i] = { .Node = static_cast<u16>(Roots[i]->Order), .Scale = Scales[i] };

            name();

            const auto fail = [&](IR::Fault fault, const u16 file, const u16 at, const u16 col) {
                if (graph.Fault.Code != IR::FaultCode::None) return;

                fault.File   = file;
                fault.Line   = at;
                fault.Column = col;

                graph.Fault = fault;
            };

            for (s00 i = 0; i < S.Tensors; i++) {
                const Detail::Token& token = *collected.Tokens[i];

                graph.Tensors[i]      = token.Spec;
                graph.Tensors[i].File = Detail::Intern(files, token.File);

                if (token.Base  ) graph.Tensors[i].Base   = static_cast<u16>(token.Base  ->Order + 1);
                if (token.Factor) graph.Tensors[i].Factor = static_cast<u16>(token.Factor->Order + 1);
            }

            if (!Written) {
                s00 item = 0;

                for (s00 i = 0; i < S.Tensors; i++)
                    if (graph.Tensors[i].Role != IR::Role::Folded)
                        graph.Items[item++] = { .Kind = IR::ItemKind::Tensor, .Tensor = static_cast<u16>(i) };

                return graph;
            }

            graph.File = File.Format();

            Array<u16, S.Tensors> saved {};

            for (s00 i = 0; i < S.Items; i++) {
                const FileItem& entry = File.Items()[i];

                IR::Item item { .Kind = entry.Kind, .Span = entry.Span, .Count = entry.Count, .Value = entry.Value };

                if (entry.Kind == IR::ItemKind::Tensor) {
                    const IR::Tensor& spec = entry.Tensor->Spec;
                    const u16         file = Detail::Intern(files, entry.Tensor->File);
                    const s00         slot = entry.Tensor->Order;

                    if (slot == Detail::Missing || spec.Role == IR::Role::Folded)
                        fail(Expect::Raise(IR::FaultCode::TensorUnused), file, spec.Line, spec.Column);
                    else if (++saved[slot] > 1)
                        fail(Expect::Raise(IR::FaultCode::TensorSavedTwice), file, spec.Line, spec.Column);

                    item.Tensor = static_cast<u16>(slot == Detail::Missing ? 0 : slot);
                }

                graph.Items[i] = item;
            }

            for (s00 i = 0; i < S.Tensors; i++) {
                const IR::Tensor& tensor = graph.Tensors[i];

                if (saved[i] == 0 && tensor.Role != IR::Role::Folded)
                    fail(Expect::Raise(IR::FaultCode::TensorNotSaved), tensor.File, tensor.Line, tensor.Column);
            }

            return graph;
        }

    };

    namespace Detail
    {

        template<typename V>
        struct Bindings;

        template<typename... B>
        struct Bindings<Value<B...>> { using Type = MantaRay::Graph<B...>; };

        template<typename... V>
        struct Joined;

        template<typename V>
        struct Joined<V> { using Type = V; };

        template<typename V, typename W, typename... R>
        struct Joined<V, W, R...> { using Type = Joined<Union<V, W>, R...>::Type; };

    }

    template<typename... F>
    constexpr Graph<F...> Output(
        const Value<F...>&          root                                ,
        const f64                   scale                               ,
        const std::source_location& site = std::source_location::current()
    )
    {
        return Graph<F...>(Head<F...>(root, scale, site));
    }

    template<typename... F>
    constexpr Graph<F...> Output(
        const Value<F...>&          root                                ,
        const f64                   scale                               ,
        const FileSpec&             file                                ,
        const std::source_location& site = std::source_location::current()
    )
    {
        return Graph<F...>(file, Head<F...>(root, scale, site));
    }

    template<typename... H>
    constexpr auto Output(const FileSpec& file, const H&... heads)
    {
        using V = Detail::Joined<decltype(heads.Root)...>::Type;

        return typename Detail::Bindings<V>::Type(file, heads...);
    }

}

#endif //MANTARAY_GRAPH_OUTPUT_H
