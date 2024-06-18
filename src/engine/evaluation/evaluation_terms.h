#ifndef INTEGRAL_EVALUATION_TERMS_H
#define INTEGRAL_EVALUATION_TERMS_H

#include "../../utils/types.h"

namespace eval {

// clang-format off
template <typename T>
using PieceTable = std::array<T, kNumPieceTypes>;

template <typename T>
using PieceSquareTable = std::array<std::array<T, kSquareCount>,
                                    kNumPieceTypes>;

template <typename T>
using KnightMobilityTable = std::array<T, 9>;

template <typename T>
using RookMobilityTable = std::array<T, 15>;

template <typename T>
using BishopMobilityTable = std::array<T, 14>;

template <typename T>
using QueenMobilityTable = std::array<T, 28>;

template <typename T>
using RankTable = std::array<T, kNumRanks>;

template <typename T>
using FileTable = std::array<T, kNumFiles>;

constexpr PieceTable<ScorePair> kPieceValues = {
  Pair(84, 160), Pair(289, 317), Pair(352, 348), Pair(418, 700), Pair(862, 1270), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(44, 146), Pair(49, 137), Pair(31, 138), Pair(61, 86), Pair(44, 87), Pair(34, 100), Pair(-19, 149), Pair(-31, 149),
      Pair(2, 2), Pair(-8, 15), Pair(26, -31), Pair(27, -67), Pair(36, -71), Pair(68, -54), Pair(22, 2), Pair(3, -13),
      Pair(-21, -19), Pair(-17, -19), Pair(-10, -40), Pair(-5, -61), Pair(17, -62), Pair(15, -57), Pair(-4, -22), Pair(-6, -43),
      Pair(-26, -39), Pair(-27, -28), Pair(-17, -48), Pair(-1, -58), Pair(1, -58), Pair(7, -58), Pair(-10, -34), Pair(-8, -57),
      Pair(-27, -43), Pair(-22, -33), Pair(-15, -49), Pair(-9, -50), Pair(3, -49), Pair(-1, -54), Pair(3, -39), Pair(-6, -61),
      Pair(-25, -39), Pair(-22, -27), Pair(-18, -41), Pair(-21, -47), Pair(-6, -37), Pair(8, -50), Pair(11, -36), Pair(-17, -58),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-128, -45), Pair(-108, 2), Pair(-53, 15), Pair(-17, 2), Pair(13, 6), Pair(-46, -17), Pair(-90, 1), Pair(-87, -63),
      Pair(-8, 7), Pair(13, 17), Pair(38, 11), Pair(55, 8), Pair(29, 3), Pair(92, -10), Pair(8, 12), Pair(30, -15),
      Pair(10, 10), Pair(37, 15), Pair(47, 36), Pair(58, 34), Pair(93, 19), Pair(95, 9), Pair(56, 5), Pair(30, -2),
      Pair(12, 25), Pair(15, 32), Pair(34, 44), Pair(56, 44), Pair(29, 44), Pair(50, 42), Pair(15, 32), Pair(37, 12),
      Pair(0, 27), Pair(7, 25), Pair(18, 46), Pair(16, 44), Pair(23, 48), Pair(19, 36), Pair(28, 23), Pair(4, 22),
      Pair(-22, 10), Pair(-3, 19), Pair(4, 22), Pair(6, 38), Pair(21, 34), Pair(5, 18), Pair(12, 12), Pair(-8, 15),
      Pair(-26, 11), Pair(-14, 17), Pair(-2, 17), Pair(4, 16), Pair(8, 13), Pair(4, 14), Pair(9, 5), Pair(-4, 19),
      Pair(-60, 15), Pair(-19, 4), Pair(-21, 13), Pair(-13, 17), Pair(-7, 17), Pair(-5, 7), Pair(-20, 10), Pair(-37, 9)
  },
  {
      Pair(-46, 18), Pair(-70, 22), Pair(-63, 15), Pair(-101, 25), Pair(-87, 22), Pair(-82, 12), Pair(-43, 11), Pair(-59, 6),
      Pair(-26, 1), Pair(-8, 11), Pair(-15, 12), Pair(-29, 16), Pair(1, 5), Pair(-7, 9), Pair(-11, 13), Pair(-29, 3),
      Pair(-20, 19), Pair(-1, 15), Pair(-2, 21), Pair(15, 9), Pair(4, 13), Pair(37, 20), Pair(16, 15), Pair(7, 16),
      Pair(-25, 16), Pair(-12, 23), Pair(2, 20), Pair(21, 34), Pair(14, 25), Pair(3, 26), Pair(-7, 18), Pair(-23, 15),
      Pair(-19, 12), Pair(-19, 23), Pair(-12, 30), Pair(12, 30), Pair(9, 28), Pair(-17, 25), Pair(-18, 18), Pair(-7, 0),
      Pair(-16, 13), Pair(1, 24), Pair(-2, 24), Pair(-6, 26), Pair(-5, 30), Pair(-4, 22), Pair(-3, 14), Pair(0, 3),
      Pair(-2, 18), Pair(-2, 5), Pair(7, 6), Pair(-12, 15), Pair(-4, 13), Pair(3, 9), Pair(14, 7), Pair(1, -3),
      Pair(-15, 7), Pair(8, 19), Pair(-14, 8), Pair(-23, 13), Pair(-16, 11), Pair(-20, 19), Pair(-6, 2), Pair(3, -16)
  },
  {
      Pair(15, 6), Pair(9, 18), Pair(11, 17), Pair(8, 13), Pair(19, 2), Pair(31, 12), Pair(24, 12), Pair(4, 10),
      Pair(7, 8), Pair(9, 25), Pair(26, 20), Pair(40, 10), Pair(25, 7), Pair(46, 10), Pair(36, 6), Pair(23, 0),
      Pair(-7, 7), Pair(21, 11), Pair(21, 6), Pair(19, 3), Pair(47, -11), Pair(52, -5), Pair(76, -10), Pair(27, -14),
      Pair(-11, 8), Pair(3, 11), Pair(7, 11), Pair(10, 7), Pair(14, -8), Pair(13, 1), Pair(16, 0), Pair(0, -8),
      Pair(-18, -2), Pair(-18, 9), Pair(-6, 2), Pair(-3, 2), Pair(-1, -5), Pair(-17, 7), Pair(5, -7), Pair(-9, -15),
      Pair(-22, -7), Pair(-16, -2), Pair(-9, -7), Pair(-12, -3), Pair(-1, -14), Pair(-2, -9), Pair(27, -30), Pair(3, -33),
      Pair(-21, -15), Pair(-14, -6), Pair(1, -8), Pair(0, -9), Pair(5, -19), Pair(7, -15), Pair(15, -27), Pair(-19, -28),
      Pair(-7, -11), Pair(-2, -9), Pair(5, -7), Pair(9, -12), Pair(15, -20), Pair(8, -11), Pair(2, -17), Pair(-4, -27)
  },
  {
      Pair(-46, -2), Pair(-51, 16), Pair(-34, 37), Pair(6, 18), Pair(4, 19), Pair(16, 16), Pair(57, -42), Pair(-11, 3),
      Pair(-7, -19), Pair(-30, 14), Pair(-28, 46), Pair(-40, 68), Pair(-33, 84), Pair(8, 43), Pair(8, 21), Pair(44, 10),
      Pair(-7, -11), Pair(-10, 3), Pair(-14, 37), Pair(-4, 44), Pair(-2, 60), Pair(48, 39), Pair(51, 10), Pair(47, 7),
      Pair(-17, -4), Pair(-17, 13), Pair(-12, 23), Pair(-14, 43), Pair(-14, 58), Pair(-1, 47), Pair(5, 43), Pair(9, 29),
      Pair(-15, -9), Pair(-18, 14), Pair(-14, 14), Pair(-9, 33), Pair(-7, 30), Pair(-9, 30), Pair(0, 20), Pair(8, 15),
      Pair(-10, -28), Pair(-7, -9), Pair(-7, 2), Pair(-10, 3), Pair(-5, 10), Pair(-1, 11), Pair(11, -5), Pair(8, -13),
      Pair(-6, -36), Pair(-3, -33), Pair(2, -32), Pair(8, -29), Pair(7, -24), Pair(14, -41), Pair(18, -61), Pair(22, -79),
      Pair(-12, -37), Pair(-5, -37), Pair(0, -34), Pair(2, -26), Pair(6, -40), Pair(-5, -37), Pair(3, -56), Pair(1, -60)
  },
  {
      Pair(79, -90), Pair(111, -47), Pair(89, -26), Pair(-51, 17), Pair(-27, -1), Pair(4, -4), Pair(73, -21), Pair(181, -126),
      Pair(-53, 5), Pair(28, 27), Pair(-31, 44), Pair(54, 30), Pair(-10, 42), Pair(-3, 52), Pair(25, 35), Pair(-23, 9),
      Pair(-81, 13), Pair(66, 24), Pair(-21, 51), Pair(-45, 63), Pair(-22, 62), Pair(53, 41), Pair(-3, 41), Pair(-45, 12),
      Pair(-52, 1), Pair(-12, 21), Pair(-67, 51), Pair(-112, 66), Pair(-119, 61), Pair(-82, 48), Pair(-78, 28), Pair(-126, 13),
      Pair(-50, -14), Pair(-21, 10), Pair(-90, 44), Pair(-125, 62), Pair(-134, 58), Pair(-85, 35), Pair(-78, 16), Pair(-121, 1),
      Pair(-16, -21), Pair(13, -1), Pair(-60, 30), Pair(-82, 46), Pair(-83, 42), Pair(-73, 26), Pair(-31, 1), Pair(-36, -18),
      Pair(49, -38), Pair(-1, -3), Pair(-18, 12), Pair(-42, 24), Pair(-53, 25), Pair(-33, 10), Pair(-5, -10), Pair(34, -40),
      Pair(47, -73), Pair(48, -42), Pair(33, -25), Pair(-36, -1), Pair(12, -27), Pair(-25, -11), Pair(30, -37), Pair(60, -83)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-23, 11), Pair(-12, 7), Pair(-2, 29), Pair(4, 38), Pair(10, 45), Pair(15, 54), Pair(22, 52), Pair(28, 49),
  Pair(34, 38)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-56, -14), Pair(-46, -15), Pair(-36, 1), Pair(-28, 14), Pair(-20, 24), Pair(-16, 34), Pair(-11, 37), Pair(-8, 39),
  Pair(-7, 42), Pair(-2, 39), Pair(6, 34), Pair(12, 32), Pair(11, 40), Pair(21, 17)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-40, -62), Pair(-33, -34), Pair(-29, -30), Pair(-26, -25), Pair(-29, -17), Pair(-24, -13), Pair(-23, -7), Pair(-20, -5),
  Pair(-16, -2), Pair(-14, 2), Pair(-10, 3), Pair(-10, 7), Pair(-5, 7), Pair(-1, 4), Pair(-9, 4)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-2, -262), Pair(-2, -241), Pair(-11, -105), Pair(-9, -60), Pair(-8, -36), Pair(-5, -25), Pair(-2, -7), Pair(-1, 7),
  Pair(2, 14), Pair(4, 17), Pair(6, 24), Pair(9, 31), Pair(11, 32), Pair(10, 40), Pair(13, 42), Pair(15, 47),
  Pair(15, 54), Pair(17, 56), Pair(25, 54), Pair(39, 46), Pair(41, 49), Pair(90, 20), Pair(76, 31), Pair(99, 9),
  Pair(210, -33), Pair(225, -64), Pair(162, -10), Pair(116, -9)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-5, 1), Pair(-12, 10), Pair(-8, 35), Pair(11, 62), Pair(8, 123), Pair(28, 33), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(-1, -7), Pair(0, 0), Pair(18, 9), Pair(42, 47), Pair(113, 182), Pair(-122, 443), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-13, -44), Pair(5, -34), Pair(-4, -28), Pair(-3, -17), Pair(-11, -11), Pair(-14, -25), Pair(3, -40), Pair(-12, -52)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-8, 2), Pair(-7, -15), Pair(-17, -11), Pair(-15, -19), Pair(-18, -20), Pair(-9, -10), Pair(-7, -16), Pair(-6, 4)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(27, 11), Pair(25, 3), Pair(21, 13), Pair(26, 10), Pair(28, 16), Pair(49, -1), Pair(58, -1), Pair(91, -2)
  },
  {
      Pair(2, 46), Pair(7, 17), Pair(5, 19), Pair(15, 9), Pair(11, 10), Pair(20, 2), Pair(29, 4), Pair(20, 28)
  }
}};

constexpr PieceTable<ScorePair> kKingZoneSafetyBonus = {
  Pair(0, 0), Pair(12, 4), Pair(6, 4), Pair(6, -4), Pair(2, 0), Pair(0, 0)
};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(18, -1), Pair(18, 7), Pair(15, 3),
  Pair(28, -6), Pair(25, 2), Pair(27, -7),
  Pair(39, 0), Pair(0, 0), Pair(35, 0),
  Pair(-20, 4), Pair(-11, 13), Pair(-20, 5)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-12, 8), Pair(-17, 12), Pair(-13, 10),
  Pair(-10, 9), Pair(-19, 16), Pair(-12, 10),
  Pair(-6, 1), Pair(-15, 11), Pair(-6, 2),
  Pair(7, 0), Pair(-12, 8), Pair(5, 2),
  Pair(20, -5), Pair(14, 8), Pair(13, -5),
  Pair(0, 0), Pair(-71, -24), Pair(0, 0),
  Pair(-12, -48), Pair(0, 0), Pair(-16, -45)
};

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-85, -13), Pair(-114, 4), Pair(-61, -5), Pair(-56, -2), Pair(-39, 1), Pair(-73, 10), Pair(-71, 13), Pair(-48, 8)
  },
  {
      Pair(-30, 68), Pair(-61, 38), Pair(-28, 26), Pair(-10, 9), Pair(-9, 5), Pair(-23, 18), Pair(-41, 35), Pair(-28, 49)
  }
}};

constexpr ScorePair kBishopPairBonus = Pair(21, 64);
constexpr ScorePair kTempoBonus = Pair(20, 26);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_EVALUATION_TERMS_H