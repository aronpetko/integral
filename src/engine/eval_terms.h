#ifndef INTEGRAL_EVAL_TERMS_H
#define INTEGRAL_EVAL_TERMS_H

#include "../utils/types.h"

namespace eval {

// clang-format off
template <typename T>
using PieceValueTable = std::array<T, PieceType::kNumTypes>;
constexpr PieceValueTable<ScorePair> kPieceValues = {
    Pair(100, 110),  // Pawn
    Pair(300, 280),  // Knight
    Pair(305, 295),  // Bishop
    Pair(500, 520),  // Rook
    Pair(900, 880),  // Queen
    Pair(0, 0)       // King
};

template <typename T>
using PieceSquareTable = std::array<std::array<T, kSquareCount>,
                                    PieceType::kNumTypes>;
constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  { // Pawns
    Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
    Pair(50, 50), Pair(50, 50), Pair(50, 50), Pair(50, 50), Pair(50, 50), Pair(50, 50), Pair(50, 50), Pair(50, 50),
    Pair(10, 20), Pair(10, 20), Pair(20, 30), Pair(30, 40), Pair(30, 40), Pair(20, 30), Pair(10, 20), Pair(10, 20),
    Pair(5, 10), Pair(5, 15), Pair(10, 25), Pair(25, 35), Pair(25, 35), Pair(10, 25), Pair(5, 15), Pair(5, 10),
    Pair(0, 5), Pair(0, 10), Pair(0, 20), Pair(20, 30), Pair(20, 30), Pair(0, 20), Pair(0, 10), Pair(0, 5),
    Pair(5, 0), Pair(-5, 5), Pair(-10, 10), Pair(0, 20), Pair(0, 20), Pair(-10, 10), Pair(-5, 5), Pair(5, 0),
    Pair(5, 5), Pair(10, 10), Pair(10, 10), Pair(-20, -5), Pair(-20, -5), Pair(10, 10), Pair(10, 10), Pair(5, 5),
    Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  { // Knights
     Pair(-50, -50), Pair(-40, -40), Pair(-30, -30), Pair(-30, -30), Pair(-30, -30), Pair(-30, -30), Pair(-40, -40), Pair(-50, -50),
     Pair(-40, -40), Pair(-20, -20), Pair(0, 5), Pair(0, 5), Pair(0, 5), Pair(0, 5), Pair(-20, -20), Pair(-40, -40),
     Pair(-30, -30), Pair(0, 5), Pair(10, 20), Pair(15, 25), Pair(15, 25), Pair(10, 20), Pair(0, 5), Pair(-30, -30),
     Pair(-30, -30), Pair(5, 10), Pair(15, 25), Pair(20, 30), Pair(20, 30), Pair(15, 25), Pair(5, 10), Pair(-30, -30),
     Pair(-30, -30), Pair(0, 5), Pair(15, 25), Pair(20, 30), Pair(20, 30), Pair(15, 25), Pair(0, 5), Pair(-30, -30),
     Pair(-30, -30), Pair(5, 10), Pair(10, 20), Pair(15, 25), Pair(15, 25), Pair(10, 20), Pair(5, 10), Pair(-30, -30),
     Pair(-40, -40), Pair(-20, -20), Pair(0, 5), Pair(5, 10), Pair(5, 10), Pair(0, 5), Pair(-20, -20), Pair(-40, -40),
     Pair(-50, -50), Pair(-40, -40), Pair(-30, -30), Pair(-30, -30), Pair(-30, -30), Pair(-30, -30), Pair(-40, -40), Pair(-50, -50)
  }, // Bishops
  {
     Pair(-20, -20), Pair(-10, -10), Pair(-10, -10), Pair(-10, -10), Pair(-10, -10), Pair(-10, -10), Pair(-10, -10), Pair(-20, -20),
     Pair(-10, -10), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(-10, -10),
     Pair(-10, -10), Pair(0, 5), Pair(5, 10), Pair(10, 15), Pair(10, 15), Pair(5, 10), Pair(0, 5), Pair(-10, -10),
     Pair(-10, -10), Pair(5, 10), Pair(5, 15), Pair(10, 25), Pair(10, 25), Pair(5, 15), Pair(5, 10), Pair(-10, -10),
     Pair(-10, -10), Pair(0, 5), Pair(10, 15), Pair(10, 25), Pair(10, 25), Pair(10, 15), Pair(0, 5), Pair(-10, -10),
     Pair(-10, -10), Pair(10, 10), Pair(10, 15), Pair(10, 15), Pair(10, 15), Pair(10, 15), Pair(10, 10), Pair(-10, -10),
     Pair(-10, -10), Pair(5, 0), Pair(0, 5), Pair(0, 10), Pair(0, 10), Pair(0, 5), Pair(5, 0), Pair(-10, -10),
     Pair(-20, -20), Pair(-10, -10), Pair(-10, -10), Pair(-10, -10), Pair(-10, -10), Pair(-10, -10), Pair(-10, -10), Pair(-20, -20)
  },
  { // Rooks
     Pair(0, 10), Pair(0, 15), Pair(0, 15), Pair(0, 20), Pair(0, 20), Pair(0, 15), Pair(0, 10), Pair(0, 5),
     Pair(5, 5), Pair(10, 10), Pair(10, 10), Pair(10, 15), Pair(10, 15), Pair(10, 10), Pair(10, 5), Pair(5, 0),
     Pair(-5, 5), Pair(0, 10), Pair(0, 10), Pair(0, 10), Pair(0, 10), Pair(0, 10), Pair(0, 5), Pair(-5, 0),
     Pair(-5, 0), Pair(0, 5), Pair(0, 10), Pair(0, 10), Pair(0, 10), Pair(0, 5), Pair(0, 0), Pair(-5, -5),
     Pair(-5, -5), Pair(0, 0), Pair(0, 5), Pair(0, 5), Pair(0, 5), Pair(0, 0), Pair(-5, -5), Pair(-5, -10),
     Pair(-5, -10), Pair(0, -5), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, -5), Pair(-5, -10), Pair(-5, -15),
     Pair(-5, -15), Pair(0, -10), Pair(0, -5), Pair(0, 0), Pair(0, 0), Pair(0, -5), Pair(-5, -10), Pair(-5, -20),
     Pair(0, -20), Pair(0, -15), Pair(0, -10), Pair(5, -5), Pair(5, -5), Pair(0, -10), Pair(0, -15), Pair(0, -20)
  },
  { // Queens
     Pair(-20, -20), Pair(-10, -10), Pair(-10, -10), Pair(-5, -5), Pair(-5, -5), Pair(-10, -10), Pair(-10, -10), Pair(-20, -20),
     Pair(-10, -10), Pair(0, 5), Pair(0, 5), Pair(0, 5), Pair(0, 5), Pair(0, 5), Pair(0, 5), Pair(-10, -10),
     Pair(-10, -5), Pair(0, 10), Pair(5, 10), Pair(5, 10), Pair(5, 10), Pair(5, 10), Pair(0, 10), Pair(-10, -5),
     Pair(-5, 0), Pair(0, 10), Pair(5, 15), Pair(5, 20), Pair(5, 20), Pair(5, 15), Pair(0, 10), Pair(-5, 0),
     Pair(0, 5), Pair(0, 15), Pair(5, 20), Pair(5, 25), Pair(5, 25), Pair(5, 20), Pair(0, 15), Pair(-5, 5),
     Pair(-10, -5), Pair(5, 10), Pair(5, 20), Pair(5, 20), Pair(5, 20), Pair(5, 20), Pair(0, 10), Pair(-10, -5),
     Pair(-10, -10), Pair(0, 5), Pair(0, 10), Pair(0, 10), Pair(0, 10), Pair(0, 10), Pair(0, 5), Pair(-10, -10),
     Pair(-20, -20), Pair(-10, -10), Pair(-10, -5), Pair(-5, 0), Pair(-5, 0), Pair(-10, -5), Pair(-10, -10), Pair(-20, -20)
  },
  { // King
     Pair(-30, 30), Pair(-40, 40), Pair(-40, 40), Pair(-50, 50), Pair(-50, 50), Pair(-40, 40), Pair(-40, 40), Pair(-30, 30),
     Pair(-30, 20), Pair(-40, 20), Pair(-40, 30), Pair(-50, 40), Pair(-50, 40), Pair(-40, 30), Pair(-40, 20), Pair(-30, 20),
     Pair(-30, 10), Pair(-40, 10), Pair(-40, 20), Pair(-50, 30), Pair(-50, 30), Pair(-40, 20), Pair(-40, 10), Pair(-30, 10),
     Pair(-30, 0), Pair(-40, 5), Pair(-40, 15), Pair(-50, 30), Pair(-50, 30), Pair(-40, 15), Pair(-40, 5), Pair(-30, 0),
     Pair(-20, -10), Pair(-30, 0), Pair(-30, 10), Pair(-40, 20), Pair(-40, 20), Pair(-30, 10), Pair(-30, 0), Pair(-20, -10),
     Pair(-10, -20), Pair(-20, -5), Pair(-20, 5), Pair(-20, 10), Pair(-20, 10), Pair(-20, 5), Pair(-20, -5), Pair(-10, -20),
     Pair(20, -30), Pair(20, -10), Pair(0, -10), Pair(0, 0), Pair(0, 0), Pair(0, -10), Pair(20, -10), Pair(20, -30),
     Pair(20, -50), Pair(30, -30), Pair(10, -30), Pair(0, -20), Pair(0, -20), Pair(10, -30), Pair(30, -30), Pair(20, -50)
  },
}};

template <typename T>
using KnightMobilityTable = std::array<T, 9>;
constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-5, -20), Pair(5, 10), Pair(23, 28), Pair(29, 34), Pair(36, 41),
  Pair(40, 45), Pair(48, 53), Pair(48, 53), Pair(51, 56)
};

template <typename T>
using RookMobilityTable = std::array<T, 15>;
constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-10, 0), Pair(-5, 5), Pair(0, 10), Pair(5, 15), Pair(5, 15),
  Pair(10, 20), Pair(13, 23), Pair(18, 28), Pair(25, 35), Pair(34, 44),
  Pair(38, 48), Pair(42, 52), Pair(47, 57), Pair(50, 60), Pair(55, 65)
};

template <typename T>
using BishopMobilityTable = std::array<T, 14>;
constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(3, 8), Pair(12, 17), Pair(21, 26), Pair(23, 28),
  Pair(31, 36), Pair(39, 44), Pair(46, 51), Pair(50, 55),
  Pair(50, 55), Pair(53, 58), Pair(56, 61), Pair(60, 65),
  Pair(59, 64), Pair(92, 97)
};

template <typename T>
using QueenMobilityTable = std::array<T, 28>;
constexpr QueenMobilityTable<ScorePair> kQueenMobility = {{
  Pair(-71, -25), Pair(-70, -84), Pair(-73, -50), Pair(-70, -35),
  Pair(-67, -35), Pair(-63, -26), Pair(-59, -20), Pair(-61, 1),
  Pair(-59, 12),  Pair(-55, 14),  Pair(-55, 27),  Pair(-55, 34),
  Pair(-53, 42),  Pair(-52, 49),  Pair(-50, 54),  Pair(-49, 59),
  Pair(-46, 64),  Pair(-49, 77),  Pair(-44, 81),  Pair(-42, 82),
  Pair(-35, 84),  Pair(-30, 84),  Pair(-28, 84),  Pair(-15, 80),
  Pair(-2, 66),   Pair(52, 49),   Pair(64, 43),   Pair(189, -16)
}};

template <typename T>
using PassedPawnTable = std::array<T, kNumRanks>;
constexpr PassedPawnTable<ScorePair> kPassedPawn = {
  Pair(0, 0),
  Pair(-2, 4),
  Pair(-7, 13),
  Pair(8, 37),
  Pair(12, 61),
  Pair(7, 119),
  Pair(48, 109),
  Pair(0, 0)
};

constexpr ScorePair kTempoBonus = Pair(10, 10);
// clang-format on

constexpr std::array<int, PieceType::kNumTypes> kGamePhaseIncrements = {0, 1, 1, 2, 4, 0};

template <typename T>
using TraceTerm = std::array<T, 2>;

// A struct that counts the amount of times each term is used, and by which side
struct EvalTrace {
  // The names, though they are not constant, must match the above names (for
  // ease of use with the tuner)
  TraceTerm<PieceValueTable<I16>> kPieceValues{};
  TraceTerm<PieceSquareTable<I16>> kPieceSquareTable{};
  TraceTerm<KnightMobilityTable<I16>> kKnightMobility{};
  TraceTerm<BishopMobilityTable<I16>> kBishopMobility{};
  TraceTerm<RookMobilityTable<I16>> kRookMobility{};
  TraceTerm<QueenMobilityTable<I16>> kQueenMobility{};
  TraceTerm<PassedPawnTable<I16>> kPassedPawn{};
  TraceTerm<I16> kTempoBonus{};
  Score eval{};
};

inline EvalTrace trace;

#define TUNE

#ifdef TUNE
#define TraceAdd(term, count, color) trace.term[color] += count
#define TraceIncrement(term, color) trace.term[color]++
#define TraceScale(s) trace.scale = s
#define TraceEval(e) trace.eval = e
#else
#define TraceAdd(term, count, color)
#define TraceIncrement(term, color)
#define TraceScale(s)
#define TraceEval(e)
#endif

}  // namespace eval

#endif  // INTEGRAL_EVAL_TERMS_H