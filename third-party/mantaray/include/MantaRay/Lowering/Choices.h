//
// Copyright (c) 2026 Shaheryar Sohail
// SPDX-License-Identifier: MIT
//

#ifndef MANTARAY_LOWERING_CHOICES_H
#define MANTARAY_LOWERING_CHOICES_H

#include <limits>
#include <string_view>

#include "Target.h"
#include "../Common.h"

namespace MantaRay::Lowering
{

    enum class Choice : u08 {
        None,
        Nnz, Threats, PawnPairs, Attacks, Ordinal, PairIndex, Flip, RowIndex, Prefetch
    };

    enum class Tier : u08 {
        None,
        Compress, IndexTable, Swizzle, Table, Lut, Expand,
        Rays, Walk, Pext,
        Popcount, Arithmetic, Modulo, Lookup, Scalar, Gather,
        Off, FirstLine, FirstTwoLines
    };

    constexpr inline Array<std::string_view, 10> ChoiceNames {
        "None",
        "Nnz", "Threats", "PawnPairs", "Attacks", "Ordinal", "PairIndex", "Flip", "RowIndex", "Prefetch"
    };

    constexpr inline Array<std::string_view, 19> TierNames {
        "None",
        "Compress", "IndexTable", "Swizzle", "Table", "Lut", "Expand",
        "Rays", "Walk", "Pext",
        "Popcount", "Arithmetic", "Modulo", "Lookup", "Scalar", "Gather",
        "Off", "FirstLine", "FirstTwoLines"
    };

    constexpr inline Array<std::string_view, 8> CapabilityNames {
        "Shuffle", "Gather", "FMA", "Masks", "Permute8", "Compress", "Table", "VNNI"
    };

    static_assert(ChoiceNames.size() == static_cast<s00>(Choice::Prefetch   ) + 1, "ChoiceNames lists every Choice");
    static_assert(TierNames  .size() == static_cast<s00>(Tier::FirstTwoLines) + 1, "TierNames lists every Tier"    );

    struct Capabilities
    {

        bool Shuffle  = false;
        bool Gather   = false;
        bool FMA      = false;
        bool Masks    = false;
        bool Permute8 = false;
        bool Compress = false;
        bool Table    = false;
        bool VNNI     = false;

        constexpr bool operator ==(const Capabilities&) const = default;

    };

    struct Decision
    {

        std::string_view Id     {};
        Choice           Choice = Choice::None;
        Capabilities     Has    {};
        Capabilities     Lacks  {};
        u32              Least  = 0;
        u32              Most   = std::numeric_limits<u32>::max();
        Tier             Tier   = Tier::None;

    };

    constexpr inline Array<Decision, 15> Decisions { {
        {
            .Id     = "M2-n"                                ,
            .Choice = Choice::Threats                       ,
            .Has    = { .Permute8 = true, .Compress = true },
            .Tier   = Tier::Swizzle
        },
        {
            .Id     = "M2-v1"                           ,
            .Choice = Choice::Threats                   ,
            .Lacks  = { .Shuffle = true, .Table = true },
            .Tier   = Tier::Lut
        },
        {
            .Id     = "M2-a"           ,
            .Choice = Choice::Threats  ,
            .Has    = { .Table = true },
            .Tier   = Tier::Table
        },
        {
            .Id     = "M3-n"                                ,
            .Choice = Choice::PawnPairs                     ,
            .Has    = { .Permute8 = true, .Compress = true },
            .Tier   = Tier::Compress
        },
        {
            .Id     = "M3-v34"                           ,
            .Choice = Choice::PawnPairs                  ,
            .Has    = { .Shuffle = true, .Gather = true },
            .Tier   = Tier::Expand
        },
        {
            .Id     = "M3-v2"            ,
            .Choice = Choice::PawnPairs  ,
            .Has    = { .Shuffle = true },
            .Lacks  = { .Gather = true } ,
            .Tier   = Tier::Lut
        },
        {
            .Id     = "M3-v1"                           ,
            .Choice = Choice::PawnPairs                 ,
            .Lacks  = { .Shuffle = true, .Table = true },
            .Tier   = Tier::Lut
        },
        {
            .Id     = "M3-a"           ,
            .Choice = Choice::PawnPairs,
            .Has    = { .Table = true },
            .Tier   = Tier::Expand
        },
        {
            .Id     = "M4-n"                                ,
            .Choice = Choice::Attacks                       ,
            .Has    = { .Permute8 = true, .Compress = true },
            .Tier   = Tier::Rays
        },
        {
            .Id     = "M5-ordinal-v1"                   ,
            .Choice = Choice::Ordinal                   ,
            .Lacks  = { .Shuffle = true, .Table = true },
            .Tier   = Tier::Popcount
        },
        {
            .Id     = "M5-ppindex"     ,
            .Choice = Choice::PairIndex,
            .Tier   = Tier::Lookup
        },
        {
            .Id     = "M5-flip"   ,
            .Choice = Choice::Flip,
            .Tier   = Tier::Lookup
        },
        {
            .Id     = "M5-gather"                      ,
            .Choice = Choice::RowIndex                 ,
            .Has    = { .Gather = true, .Masks = true },
            .Tier   = Tier::Scalar
        },
        {
            .Id     = "M5-rowindex-v3"  ,
            .Choice = Choice::RowIndex  ,
            .Has    = { .Gather = true },
            .Lacks  = { .Masks = true } ,
            .Tier   = Tier::Scalar
        },
        {
            .Id     = "M5-x"            ,
            .Choice = Choice::RowIndex  ,
            .Lacks  = { .Gather = true },
            .Tier   = Tier::Scalar
        }
    } };

    struct Nominal
    {

        const Target* Target = nullptr;
        Capabilities  Set    {};

    };

    constexpr inline Array<Nominal, 7> Nominals { {
        { .Target = &Scalar    , .Set = {} },
        { .Target = &SSE2      , .Set = {} },
        { .Target = &SSE41     , .Set = { .Shuffle = true } },
        { .Target = &AVX2      , .Set = { .Shuffle = true, .Gather = true, .FMA = true } },
        { .Target = &AVX512    , .Set = { .Shuffle = true, .Gather = true, .FMA = true, .Masks = true } },
        { .Target = &AVX512VNNI, .Set = { .Shuffle = true, .Gather = true, .FMA = true, .Masks = true,
                                          .Permute8 = true, .Compress = true, .VNNI = true } },
        { .Target = &NEON      , .Set = { .FMA = true, .Table = true } }
    } };

    constexpr Array<bool, 8> FlagsOf(const Capabilities& capabilities)
    {
        return {
            capabilities.Shuffle , capabilities.Gather  , capabilities.FMA  , capabilities.Masks,
            capabilities.Permute8, capabilities.Compress, capabilities.Table, capabilities.VNNI
        };
    }

    constexpr Capabilities NominalOf(const Target& target)
    {
        for (s00 i = 0; i < Nominals.size(); i++)
            if (Nominals[i].Target == &target) return Nominals[i].Set;

        return {};
    }

    template<typename ISA>
    consteval Capabilities CapabilitiesOf()
    {
        Capabilities capabilities {};

        if constexpr (requires { ISA::Shuffle ; }) capabilities.Shuffle  = ISA::Shuffle ;
        if constexpr (requires { ISA::Gather  ; }) capabilities.Gather   = ISA::Gather  ;
        if constexpr (requires { ISA::FMA     ; }) capabilities.FMA      = ISA::FMA     ;
        if constexpr (requires { ISA::Masks   ; }) capabilities.Masks    = ISA::Masks   ;
        if constexpr (requires { ISA::Permute8; }) capabilities.Permute8 = ISA::Permute8;
        if constexpr (requires { ISA::Compress; }) capabilities.Compress = ISA::Compress;
        if constexpr (requires { ISA::Table   ; }) capabilities.Table    = ISA::Table   ;
        if constexpr (requires { ISA::VNNI    ; }) capabilities.VNNI     = ISA::VNNI    ;

        return capabilities;
    }

    constexpr Tier DefaultOf(const Choice choice, const Capabilities& capabilities)
    {
        switch (choice) {
            case Choice::Nnz      : return capabilities.Compress ? Tier::Compress : Tier::IndexTable;
            case Choice::PawnPairs: return capabilities.Compress ? Tier::Compress : Tier::Expand    ;
            case Choice::Attacks  : return Tier::Rays      ;
            case Choice::Ordinal  : return Tier::Popcount  ;
            case Choice::PairIndex: return Tier::Arithmetic;
            case Choice::Flip     : return Tier::Modulo    ;
            case Choice::RowIndex : return capabilities.Gather ? Tier::Gather : Tier::Scalar;
            case Choice::Prefetch : return Tier::FirstLine ;
            case Choice::Threats  :
                if (capabilities.Permute8 && capabilities.Compress) return Tier::Compress;
                if (capabilities.Shuffle                          ) return Tier::Swizzle ;
                if (capabilities.Table                            ) return Tier::Table   ;

                return Tier::Lut;
            default               : return Tier::None;
        }
    }

    namespace Detail
    {

        constexpr bool Matches(const Decision& decision, const Choice choice, const Capabilities& set, const u32 size)
        {
            const Array<bool, 8> flags = FlagsOf(set           );
            const Array<bool, 8> has   = FlagsOf(decision.Has  );
            const Array<bool, 8> lacks = FlagsOf(decision.Lacks);

            bool matches = decision.Choice == choice && size >= decision.Least && size <= decision.Most;

            for (s00 f = 0; f < flags.size(); f++)
                matches = matches && (flags[f] || !has[f]) && !(flags[f] && lacks[f]);

            return matches;
        }

        template<s00 D>
        constexpr s00 DecisionOf(
            const std::array<Decision, D>& decisions   ,
            const Choice                   choice      ,
            const Capabilities&            capabilities,
            const u32                      size
        )
        {
            for (s00 d = 0; d < D; d++)
                if (Matches(decisions[d], choice, capabilities, size)) return d;

            return D;
        }

    }

    template<s00 D>
    constexpr Tier ChoiceOf(
        const std::array<Decision, D>& decisions   ,
        const Choice                   choice      ,
        const Capabilities&            capabilities,
        const u32                      size
    )
    {
        const s00 d = Detail::DecisionOf(decisions, choice, capabilities, size);

        return d < D ? decisions[d].Tier : DefaultOf(choice, capabilities);
    }

    template<s00 D>
    constexpr std::string_view RecordOf(
        const std::array<Decision, D>& decisions   ,
        const Choice                   choice      ,
        const Capabilities&            capabilities,
        const u32                      size
    )
    {
        const s00 d = Detail::DecisionOf(decisions, choice, capabilities, size);

        return d < D ? decisions[d].Id : std::string_view { "default" };
    }

    constexpr Tier ChoiceOf(const Choice choice, const Capabilities& capabilities, const u32 size)
    { return ChoiceOf(Decisions, choice, capabilities, size); }

    constexpr Tier ChoiceOf(const Choice choice, const Capabilities& capabilities)
    { return ChoiceOf(Decisions, choice, capabilities, 0); }

    constexpr std::string_view RecordOf(const Choice choice, const Capabilities& capabilities, const u32 size)
    { return RecordOf(Decisions, choice, capabilities, size); }

}

#endif //MANTARAY_LOWERING_CHOICES_H
