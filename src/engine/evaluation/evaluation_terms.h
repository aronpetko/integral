#ifndef INTEGRAL_EVALUATION_TERMS_H
#define INTEGRAL_EVALUATION_TERMS_H

#include "../../utils/types.h"

namespace eval {

// clang-format off
template <typename T>
using PieceTable = std::array<T, kNumPieceTypes>;

template <typename T>
using PieceSquareTable = PieceTable<std::array<T, kSquareCount>>;

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

template <typename T>
using OutpostTable = std::array<T, 24>;

constexpr PieceTable<ScorePair> kPieceValues = {
  Pair(83, 162), Pair(299, 338), Pair(335, 356), Pair(407, 694), Pair(873, 1285), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(53, 156), Pair(57, 148), Pair(39, 148), Pair(68, 96), Pair(52, 97), Pair(41, 110), Pair(-12, 160), Pair(-27, 160),
      Pair(4, 0), Pair(-7, 15), Pair(27, -32), Pair(29, -69), Pair(38, -73), Pair(69, -54), Pair(23, 1), Pair(3, -13),
      Pair(-19, -21), Pair(-16, -19), Pair(-9, -41), Pair(-3, -62), Pair(19, -64), Pair(15, -58), Pair(-3, -23), Pair(-6, -43),
      Pair(-25, -41), Pair(-27, -28), Pair(-15, -49), Pair(1, -59), Pair(2, -59), Pair(6, -59), Pair(-9, -34), Pair(-8, -58),
      Pair(-25, -45), Pair(-21, -34), Pair(-13, -51), Pair(-9, -52), Pair(4, -51), Pair(0, -57), Pair(4, -41), Pair(-4, -62),
      Pair(-23, -40), Pair(-21, -27), Pair(-17, -42), Pair(-19, -48), Pair(-6, -37), Pair(8, -50), Pair(11, -37), Pair(-16, -59),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-135, -39), Pair(-113, 8), Pair(-56, 21), Pair(-21, 9), Pair(9, 12), Pair(-51, -11), Pair(-93, 7), Pair(-93, -58),
      Pair(-11, 12), Pair(9, 23), Pair(35, 17), Pair(53, 15), Pair(27, 10), Pair(89, -3), Pair(5, 18), Pair(27, -10),
      Pair(6, 15), Pair(37, 20), Pair(40, 39), Pair(42, 38), Pair(86, 21), Pair(83, 7), Pair(50, 10), Pair(30, 3),
      Pair(11, 28), Pair(8, 35), Pair(26, 45), Pair(53, 41), Pair(31, 44), Pair(54, 43), Pair(19, 36), Pair(46, 15),
      Pair(-4, 30), Pair(5, 31), Pair(17, 48), Pair(22, 44), Pair(31, 49), Pair(33, 35), Pair(39, 27), Pair(13, 26),
      Pair(-23, 17), Pair(-3, 26), Pair(4, 32), Pair(14, 47), Pair(31, 43), Pair(14, 27), Pair(20, 20), Pair(1, 22),
      Pair(-28, 18), Pair(-15, 25), Pair(-3, 27), Pair(13, 25), Pair(15, 24), Pair(14, 22), Pair(9, 14), Pair(4, 26),
      Pair(-59, 21), Pair(-20, 11), Pair(-21, 22), Pair(-6, 26), Pair(2, 26), Pair(5, 16), Pair(-17, 18), Pair(-26, 16)
  },
  {
      Pair(-48, 27), Pair(-71, 31), Pair(-66, 24), Pair(-109, 34), Pair(-93, 30), Pair(-89, 20), Pair(-49, 19), Pair(-66, 15),
      Pair(-26, 9), Pair(-9, 20), Pair(-18, 21), Pair(-31, 25), Pair(-5, 13), Pair(-13, 18), Pair(-17, 22), Pair(-34, 12),
      Pair(-20, 28), Pair(-5, 23), Pair(-9, 31), Pair(2, 18), Pair(-16, 26), Pair(19, 32), Pair(8, 27), Pair(4, 26),
      Pair(-26, 25), Pair(-17, 29), Pair(-3, 30), Pair(7, 41), Pair(5, 34), Pair(-3, 36), Pair(-12, 22), Pair(-23, 25),
      Pair(-21, 18), Pair(-29, 30), Pair(-15, 34), Pair(4, 32), Pair(3, 29), Pair(-19, 31), Pair(-22, 29), Pair(-3, 10),
      Pair(-19, 20), Pair(-2, 32), Pair(-6, 33), Pair(-6, 36), Pair(-3, 40), Pair(-2, 33), Pair(-1, 23), Pair(1, 12),
      Pair(-6, 25), Pair(-5, 12), Pair(3, 15), Pair(-15, 25), Pair(-4, 23), Pair(5, 18), Pair(16, 17), Pair(2, 7),
      Pair(-19, 14), Pair(5, 28), Pair(-19, 18), Pair(-22, 24), Pair(-15, 21), Pair(-20, 29), Pair(-5, 12), Pair(5, -7)
  },
  {
      Pair(9, 4), Pair(2, 17), Pair(5, 16), Pair(2, 12), Pair(13, 1), Pair(26, 11), Pair(20, 9), Pair(0, 8),
      Pair(0, 6), Pair(3, 23), Pair(20, 18), Pair(34, 8), Pair(20, 5), Pair(43, 7), Pair(32, 4), Pair(18, -2),
      Pair(-14, 5), Pair(15, 9), Pair(15, 5), Pair(13, 1), Pair(42, -12), Pair(50, -9), Pair(74, -13), Pair(23, -17),
      Pair(-17, 6), Pair(-2, 9), Pair(1, 10), Pair(5, 5), Pair(8, -10), Pair(11, -3), Pair(14, -4), Pair(-3, -12),
      Pair(-23, -4), Pair(-23, 7), Pair(-11, 0), Pair(-8, -1), Pair(-7, -7), Pair(-19, 4), Pair(5, -10), Pair(-12, -19),
      Pair(-26, -11), Pair(-20, -5), Pair(-13, -10), Pair(-14, -7), Pair(-2, -17), Pair(-3, -14), Pair(27, -35), Pair(2, -38),
      Pair(-25, -18), Pair(-18, -9), Pair(-2, -12), Pair(-3, -13), Pair(4, -23), Pair(7, -20), Pair(16, -31), Pair(-21, -32),
      Pair(-10, -14), Pair(-5, -12), Pair(2, -10), Pair(7, -16), Pair(13, -24), Pair(8, -16), Pair(2, -22), Pair(-5, -33)
  },
  {
      Pair(-48, -1), Pair(-53, 16), Pair(-35, 37), Pair(3, 18), Pair(3, 19), Pair(12, 18), Pair(55, -42), Pair(-13, 5),
      Pair(-9, -20), Pair(-32, 15), Pair(-29, 46), Pair(-42, 69), Pair(-35, 86), Pair(7, 43), Pair(7, 23), Pair(43, 11),
      Pair(-8, -11), Pair(-12, 2), Pair(-14, 37), Pair(-4, 44), Pair(0, 60), Pair(48, 38), Pair(51, 10), Pair(47, 7),
      Pair(-18, -5), Pair(-17, 12), Pair(-13, 23), Pair(-15, 43), Pair(-14, 59), Pair(0, 47), Pair(6, 42), Pair(9, 29),
      Pair(-15, -11), Pair(-19, 15), Pair(-14, 13), Pair(-9, 33), Pair(-6, 30), Pair(-8, 31), Pair(1, 21), Pair(8, 15),
      Pair(-11, -29), Pair(-8, -9), Pair(-7, 2), Pair(-10, 3), Pair(-5, 9), Pair(0, 11), Pair(12, -6), Pair(8, -15),
      Pair(-6, -37), Pair(-4, -34), Pair(2, -32), Pair(8, -30), Pair(6, -24), Pair(15, -43), Pair(18, -62), Pair(22, -82),
      Pair(-13, -37), Pair(-7, -37), Pair(-2, -34), Pair(1, -26), Pair(5, -39), Pair(-6, -38), Pair(3, -57), Pair(3, -63)
  },
  {
      Pair(84, -93), Pair(119, -50), Pair(91, -28), Pair(-47, 16), Pair(-28, -2), Pair(3, -5), Pair(73, -22), Pair(171, -125),
      Pair(-54, 5), Pair(28, 27), Pair(-30, 43), Pair(59, 29), Pair(-7, 41), Pair(0, 51), Pair(28, 34), Pair(-21, 8),
      Pair(-82, 13), Pair(66, 23), Pair(-20, 50), Pair(-42, 63), Pair(-20, 61), Pair(57, 41), Pair(-1, 40), Pair(-45, 11),
      Pair(-54, 0), Pair(-13, 21), Pair(-66, 51), Pair(-109, 66), Pair(-116, 61), Pair(-79, 48), Pair(-76, 28), Pair(-126, 12),
      Pair(-52, -14), Pair(-20, 10), Pair(-86, 44), Pair(-120, 62), Pair(-130, 58), Pair(-82, 35), Pair(-78, 16), Pair(-123, 1),
      Pair(-18, -22), Pair(13, -1), Pair(-58, 30), Pair(-77, 45), Pair(-78, 41), Pair(-70, 26), Pair(-30, 0), Pair(-41, -17),
      Pair(44, -38), Pair(-2, -4), Pair(-13, 10), Pair(-35, 22), Pair(-46, 23), Pair(-29, 9), Pair(-5, -11), Pair(28, -39),
      Pair(39, -72), Pair(45, -42), Pair(38, -28), Pair(-30, -3), Pair(20, -31), Pair(-21, -12), Pair(29, -39), Pair(51, -81)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-31, -19), Pair(-17, -14), Pair(-7, 6), Pair(-2, 14), Pair(4, 22), Pair(10, 30), Pair(18, 29), Pair(24, 27),
  Pair(30, 17)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-33, -29), Pair(-23, -27), Pair(-12, -10), Pair(-5, 2), Pair(4, 12), Pair(8, 22), Pair(13, 26), Pair(16, 28),
  Pair(19, 31), Pair(25, 28), Pair(36, 22), Pair(45, 22), Pair(47, 32), Pair(57, 11)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-20, -49), Pair(-13, -20), Pair(-9, -17), Pair(-6, -12), Pair(-8, -4), Pair(-3, 0), Pair(-1, 6), Pair(2, 7),
  Pair(6, 10), Pair(8, 14), Pair(13, 14), Pair(13, 18), Pair(18, 19), Pair(20, 16), Pair(13, 16)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-7, -242), Pair(-4, -252), Pair(-14, -110), Pair(-12, -64), Pair(-10, -41), Pair(-8, -28), Pair(-5, -10), Pair(-4, 4),
  Pair(-1, 12), Pair(2, 14), Pair(4, 21), Pair(7, 27), Pair(8, 29), Pair(8, 37), Pair(11, 39), Pair(13, 43),
  Pair(13, 52), Pair(14, 53), Pair(23, 51), Pair(36, 43), Pair(38, 46), Pair(88, 17), Pair(74, 28), Pair(97, 6),
  Pair(204, -34), Pair(196, -51), Pair(102, 20), Pair(67, 13)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-4, 1), Pair(-12, 10), Pair(-9, 35), Pair(11, 62), Pair(9, 124), Pair(23, 24), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(0, -8), Pair(-1, 0), Pair(17, 9), Pair(44, 48), Pair(113, 183), Pair(-33, 418), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-12, -44), Pair(5, -35), Pair(-4, -28), Pair(-3, -17), Pair(-12, -11), Pair(-13, -25), Pair(3, -41), Pair(-10, -54)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-9, 3), Pair(-7, -16), Pair(-17, -11), Pair(-15, -19), Pair(-19, -20), Pair(-10, -10), Pair(-7, -16), Pair(-7, 5)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(26, 12), Pair(25, 4), Pair(22, 12), Pair(27, 11), Pair(28, 17), Pair(49, 0), Pair(58, 0), Pair(90, -1)
  },
  {
      Pair(2, 47), Pair(7, 17), Pair(5, 19), Pair(15, 8), Pair(10, 10), Pair(19, 2), Pair(28, 5), Pair(19, 29)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(19, -1), Pair(18, 7), Pair(15, 3),
  Pair(29, -5), Pair(25, 2), Pair(27, -7),
  Pair(39, 1), Pair(0, 0), Pair(35, 1),
  Pair(-21, 5), Pair(-11, 13), Pair(-20, 6)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-12, 8), Pair(-17, 13), Pair(-14, 10),
  Pair(-11, 9), Pair(-19, 16), Pair(-14, 11),
  Pair(-6, 1), Pair(-15, 11), Pair(-6, 3),
  Pair(7, -1), Pair(-12, 8), Pair(6, 1),
  Pair(21, -5), Pair(13, 8), Pair(13, -5),
  Pair(0, 0), Pair(-72, -24), Pair(0, 0),
  Pair(-13, -48), Pair(0, 0), Pair(-16, -45)
};

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-83, -14), Pair(-113, 4), Pair(-61, -5), Pair(-58, -2), Pair(-42, 2), Pair(-76, 11), Pair(-73, 12), Pair(-48, 8)
  },
  {
      Pair(-31, 69), Pair(-62, 38), Pair(-27, 27), Pair(-11, 10), Pair(-9, 5), Pair(-24, 18), Pair(-42, 36), Pair(-29, 50)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(12, 16), Pair(-6, 14), Pair(10, 25), Pair(30, 26), Pair(17, 35), Pair(22, 48), Pair(23, 22), Pair(-9, 38),
  Pair(-1, 19), Pair(15, 17), Pair(12, 23), Pair(4, 37), Pair(10, 25), Pair(10, 21), Pair(18, 16), Pair(-2, 28),
  Pair(8, 14), Pair(3, 5), Pair(0, 18), Pair(6, 21), Pair(3, 26), Pair(-7, 21), Pair(-1, 10), Pair(-1, 11)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-7, 12), Pair(12, -2), Pair(17, -2), Pair(29, 2), Pair(69, -17), Pair(45, -8), Pair(28, -19), Pair(-14, -27),
  Pair(-18, -7), Pair(23, 4), Pair(10, 0), Pair(25, 6), Pair(18, 2), Pair(31, -7), Pair(18, 14), Pair(24, -26),
  Pair(-23, 25), Pair(13, 3), Pair(8, 17), Pair(21, 14), Pair(27, 20), Pair(5, 9), Pair(18, -2), Pair(-45, 11)
};

constexpr ScorePair kBishopPairBonus = Pair(22, 66);

constexpr ScorePair kTempoBonus = Pair(21, 25);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_EVALUATION_TERMS_H