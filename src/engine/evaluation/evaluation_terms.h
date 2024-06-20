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
  Pair(82, 168), Pair(297, 335), Pair(336, 356), Pair(405, 695), Pair(869, 1285), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(54, 153), Pair(48, 154), Pair(37, 148), Pair(68, 98), Pair(53, 96), Pair(36, 114), Pair(-20, 161), Pair(-32, 167),
      Pair(1, -2), Pair(-12, 18), Pair(29, -34), Pair(30, -70), Pair(39, -76), Pair(71, -58), Pair(22, -4), Pair(3, -13),
      Pair(-21, -21), Pair(-22, -13), Pair(-7, -43), Pair(-2, -63), Pair(20, -68), Pair(16, -60), Pair(-5, -27), Pair(-6, -43),
      Pair(-28, -40), Pair(-33, -21), Pair(-15, -51), Pair(2, -60), Pair(4, -63), Pair(8, -62), Pair(-11, -38), Pair(-8, -58),
      Pair(-27, -45), Pair(-27, -26), Pair(-12, -52), Pair(-8, -53), Pair(5, -54), Pair(0, -58), Pair(2, -44), Pair(-4, -63),
      Pair(-25, -40), Pair(-27, -20), Pair(-16, -44), Pair(-18, -48), Pair(-5, -41), Pair(9, -51), Pair(9, -41), Pair(-16, -60),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-135, -40), Pair(-111, 8), Pair(-57, 22), Pair(-21, 9), Pair(9, 12), Pair(-50, -10), Pair(-94, 7), Pair(-94, -57),
      Pair(-11, 13), Pair(9, 24), Pair(35, 18), Pair(53, 15), Pair(27, 11), Pair(89, -3), Pair(5, 20), Pair(26, -8),
      Pair(5, 16), Pair(36, 20), Pair(40, 40), Pair(41, 38), Pair(86, 21), Pair(82, 8), Pair(49, 11), Pair(30, 3),
      Pair(10, 29), Pair(8, 36), Pair(25, 45), Pair(52, 41), Pair(31, 45), Pair(54, 43), Pair(18, 36), Pair(45, 17),
      Pair(-4, 31), Pair(5, 32), Pair(17, 47), Pair(22, 44), Pair(31, 50), Pair(33, 36), Pair(39, 28), Pair(13, 27),
      Pair(-23, 17), Pair(-3, 26), Pair(4, 32), Pair(14, 48), Pair(31, 44), Pair(14, 27), Pair(20, 21), Pair(0, 23),
      Pair(-28, 18), Pair(-15, 25), Pair(-3, 27), Pair(13, 25), Pair(14, 24), Pair(13, 23), Pair(8, 15), Pair(4, 27),
      Pair(-59, 22), Pair(-21, 12), Pair(-21, 23), Pair(-6, 28), Pair(2, 27), Pair(5, 17), Pair(-17, 18), Pair(-26, 16)
  },
  {
      Pair(-49, 27), Pair(-72, 31), Pair(-68, 24), Pair(-109, 33), Pair(-95, 31), Pair(-90, 20), Pair(-51, 19), Pair(-69, 14),
      Pair(-26, 9), Pair(-11, 20), Pair(-19, 21), Pair(-33, 25), Pair(-6, 13), Pair(-15, 17), Pair(-19, 22), Pair(-35, 12),
      Pair(-21, 28), Pair(-6, 23), Pair(-10, 30), Pair(1, 18), Pair(-17, 26), Pair(18, 31), Pair(6, 28), Pair(3, 26),
      Pair(-28, 24), Pair(-18, 29), Pair(-4, 29), Pair(6, 40), Pair(4, 33), Pair(-5, 35), Pair(-14, 21), Pair(-25, 27),
      Pair(-22, 19), Pair(-30, 30), Pair(-16, 33), Pair(3, 32), Pair(1, 28), Pair(-20, 30), Pair(-24, 28), Pair(-4, 9),
      Pair(-21, 19), Pair(-3, 32), Pair(-7, 33), Pair(-8, 36), Pair(-5, 39), Pair(-4, 32), Pair(-2, 23), Pair(0, 12),
      Pair(-7, 25), Pair(-7, 12), Pair(2, 14), Pair(-16, 24), Pair(-5, 23), Pair(4, 18), Pair(15, 16), Pair(0, 7),
      Pair(-20, 13), Pair(4, 28), Pair(-20, 18), Pair(-24, 24), Pair(-17, 21), Pair(-21, 29), Pair(-6, 12), Pair(3, -8)
  },
  {
      Pair(8, 5), Pair(1, 17), Pair(4, 17), Pair(0, 12), Pair(12, 0), Pair(24, 10), Pair(16, 10), Pair(-1, 8),
      Pair(0, 7), Pair(2, 23), Pair(21, 18), Pair(33, 8), Pair(20, 5), Pair(43, 6), Pair(32, 3), Pair(18, -3),
      Pair(-13, 5), Pair(15, 10), Pair(15, 6), Pair(13, 2), Pair(42, -13), Pair(49, -10), Pair(75, -15), Pair(24, -18),
      Pair(-17, 7), Pair(-3, 10), Pair(1, 10), Pair(5, 5), Pair(8, -10), Pair(12, -5), Pair(14, -4), Pair(-2, -12),
      Pair(-23, -4), Pair(-23, 8), Pair(-11, 0), Pair(-8, 0), Pair(-6, -7), Pair(-18, 3), Pair(5, -11), Pair(-11, -19),
      Pair(-26, -10), Pair(-20, -5), Pair(-13, -10), Pair(-14, -7), Pair(-2, -18), Pair(-2, -15), Pair(26, -35), Pair(3, -38),
      Pair(-25, -18), Pair(-18, -8), Pair(-3, -12), Pair(-3, -12), Pair(4, -23), Pair(8, -21), Pair(16, -31), Pair(-20, -33),
      Pair(-10, -15), Pair(-5, -12), Pair(2, -9), Pair(6, -16), Pair(13, -24), Pair(8, -16), Pair(2, -23), Pair(-5, -35)
  },
  {
      Pair(-46, -2), Pair(-51, 15), Pair(-34, 36), Pair(4, 19), Pair(3, 19), Pair(13, 18), Pair(56, -42), Pair(-14, 4),
      Pair(-7, -19), Pair(-31, 16), Pair(-29, 46), Pair(-41, 70), Pair(-34, 86), Pair(7, 42), Pair(7, 22), Pair(44, 9),
      Pair(-8, -9), Pair(-12, 5), Pair(-15, 39), Pair(-4, 44), Pair(0, 59), Pair(48, 39), Pair(52, 8), Pair(48, 7),
      Pair(-19, -2), Pair(-17, 14), Pair(-13, 24), Pair(-15, 45), Pair(-13, 60), Pair(0, 46), Pair(6, 42), Pair(9, 29),
      Pair(-15, -10), Pair(-19, 16), Pair(-14, 14), Pair(-9, 35), Pair(-6, 32), Pair(-8, 31), Pair(1, 21), Pair(8, 15),
      Pair(-11, -28), Pair(-7, -9), Pair(-7, 3), Pair(-10, 4), Pair(-4, 10), Pair(0, 11), Pair(12, -5), Pair(8, -14),
      Pair(-6, -37), Pair(-4, -34), Pair(2, -31), Pair(8, -29), Pair(6, -23), Pair(15, -43), Pair(18, -61), Pair(22, -79),
      Pair(-12, -37), Pair(-6, -36), Pair(-2, -33), Pair(1, -24), Pair(5, -39), Pair(-6, -37), Pair(3, -55), Pair(3, -63)
  },
  {
      Pair(88, -93), Pair(124, -49), Pair(93, -25), Pair(-45, 18), Pair(-25, 3), Pair(5, 1), Pair(74, -15), Pair(171, -121),
      Pair(-45, 1), Pair(35, 24), Pair(-22, 40), Pair(65, 27), Pair(-5, 42), Pair(3, 54), Pair(29, 37), Pair(-22, 11),
      Pair(-75, 6), Pair(72, 17), Pair(-15, 45), Pair(-39, 59), Pair(-15, 59), Pair(59, 39), Pair(1, 39), Pair(-40, 9),
      Pair(-44, -11), Pair(-7, 12), Pair(-68, 44), Pair(-110, 61), Pair(-118, 57), Pair(-80, 44), Pair(-75, 23), Pair(-121, 8),
      Pair(-47, -24), Pair(-19, 2), Pair(-89, 38), Pair(-124, 57), Pair(-132, 55), Pair(-82, 31), Pair(-78, 11), Pair(-123, -1),
      Pair(-15, -28), Pair(13, -5), Pair(-59, 26), Pair(-77, 42), Pair(-77, 39), Pair(-69, 25), Pair(-32, 1), Pair(-41, -16),
      Pair(47, -40), Pair(-2, -4), Pair(-12, 10), Pair(-34, 20), Pair(-45, 23), Pair(-28, 11), Pair(-5, -9), Pair(29, -36),
      Pair(39, -68), Pair(44, -38), Pair(37, -24), Pair(-29, -2), Pair(20, -28), Pair(-21, -9), Pair(28, -34), Pair(51, -76)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-29, -17), Pair(-16, -12), Pair(-5, 8), Pair(0, 18), Pair(6, 25), Pair(12, 34), Pair(19, 32), Pair(25, 30),
  Pair(32, 20)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-34, -28), Pair(-24, -26), Pair(-13, -9), Pair(-6, 4), Pair(3, 13), Pair(7, 23), Pair(12, 27), Pair(15, 29),
  Pair(18, 33), Pair(24, 29), Pair(35, 25), Pair(43, 23), Pair(45, 36), Pair(54, 13)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-20, -49), Pair(-13, -21), Pair(-9, -17), Pair(-6, -12), Pair(-8, -4), Pair(-3, 1), Pair(-1, 6), Pair(2, 8),
  Pair(5, 11), Pair(9, 15), Pair(13, 15), Pair(12, 19), Pair(17, 21), Pair(20, 16), Pair(14, 16)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-6, -247), Pair(-3, -249), Pair(-14, -109), Pair(-11, -63), Pair(-10, -39), Pair(-7, -27), Pair(-5, -9), Pair(-3, 5),
  Pair(0, 12), Pair(2, 15), Pair(4, 22), Pair(6, 29), Pair(9, 31), Pair(8, 39), Pair(11, 41), Pair(13, 45),
  Pair(13, 53), Pair(14, 54), Pair(23, 51), Pair(36, 44), Pair(39, 46), Pair(88, 16), Pair(75, 27), Pair(97, 6),
  Pair(205, -36), Pair(202, -55), Pair(106, 14), Pair(71, 10)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-5, -2), Pair(-8, 7), Pair(-3, 36), Pair(18, 66), Pair(9, 134), Pair(14, 35), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(0, -7), Pair(-1, 0), Pair(18, 9), Pair(43, 47), Pair(119, 177), Pair(-51, 423), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-7, -52), Pair(10, -42), Pair(-5, -28), Pair(-4, -16), Pair(-13, -7), Pair(-13, -21), Pair(5, -35), Pair(-7, -52)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-16, 12), Pair(-7, -16), Pair(-17, -11), Pair(-15, -20), Pair(-19, -22), Pair(-9, -13), Pair(-7, -16), Pair(-10, 3)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(27, 10), Pair(25, 3), Pair(22, 11), Pair(27, 10), Pair(28, 15), Pair(49, -1), Pair(57, 0), Pair(89, -2)
  },
  {
      Pair(2, 45), Pair(8, 17), Pair(6, 18), Pair(16, 7), Pair(11, 10), Pair(19, 1), Pair(28, 4), Pair(19, 29)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(20, -6), Pair(19, 2), Pair(16, -2),
  Pair(30, -12), Pair(26, -5), Pair(29, -13),
  Pair(41, -7), Pair(0, 0), Pair(37, -6),
  Pair(-17, -3), Pair(-6, 1), Pair(-17, -2)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-12, 4), Pair(-16, 6), Pair(-13, 6),
  Pair(-10, 3), Pair(-18, 7), Pair(-12, 5),
  Pair(-5, -5), Pair(-13, 1), Pair(-5, -4),
  Pair(8, -8), Pair(-10, -3), Pair(7, -6),
  Pair(22, -12), Pair(16, -4), Pair(15, -12),
  Pair(0, 0), Pair(-65, -36), Pair(0, 0),
  Pair(-6, -55), Pair(0, 0), Pair(-11, -52)
};

constexpr std::array<ScorePair, 8> kKingPassedPawnDistanceTable = {
  Pair(0, 0), Pair(2, 23), Pair(-7, 7), Pair(-5, -11), Pair(-4, -20), Pair(4, -22), Pair(18, -23), Pair(6, -25)
};

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-88, -4), Pair(-116, 7), Pair(-62, -2), Pair(-60, 2), Pair(-42, 5), Pair(-76, 12), Pair(-73, 12), Pair(-48, 11)
  },
  {
      Pair(-35, 75), Pair(-64, 41), Pair(-27, 25), Pair(-11, 8), Pair(-9, 0), Pair(-24, 15), Pair(-42, 33), Pair(-29, 48)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(10, 18), Pair(-7, 14), Pair(11, 24), Pair(30, 26), Pair(17, 35), Pair(22, 47), Pair(23, 22), Pair(-9, 39),
  Pair(-2, 19), Pair(14, 17), Pair(12, 23), Pair(5, 37), Pair(10, 25), Pair(9, 21), Pair(18, 15), Pair(-2, 28),
  Pair(8, 15), Pair(3, 5), Pair(0, 19), Pair(6, 22), Pair(3, 26), Pair(-6, 21), Pair(-1, 9), Pair(-1, 11)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-8, 11), Pair(12, -1), Pair(16, -1), Pair(29, 3), Pair(69, -17), Pair(44, -8), Pair(28, -18), Pair(-14, -26),
  Pair(-18, -7), Pair(22, 5), Pair(10, 0), Pair(24, 6), Pair(19, 1), Pair(31, -6), Pair(18, 13), Pair(24, -26),
  Pair(-23, 26), Pair(13, 4), Pair(8, 18), Pair(21, 14), Pair(28, 20), Pair(5, 8), Pair(18, -2), Pair(-44, 10)
};

constexpr ScorePair kBishopPairBonus = Pair(22, 65);

constexpr ScorePair kTempoBonus = Pair(21, 25);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_EVALUATION_TERMS_H