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
  Pair(115, 145), Pair(347, 295), Pair(392, 318), Pair(493, 627), Pair(1034, 1162), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(135, 103), Pair(95, 115), Pair(106, 102), Pair(88, 82), Pair(79, 86), Pair(71, 81), Pair(-34, 114), Pair(49, 84),
      Pair(0, -4), Pair(8, -10), Pair(14, -31), Pair(2, -49), Pair(22, -56), Pair(69, -51), Pair(66, -43), Pair(9, -29),
      Pair(-15, -25), Pair(-7, -26), Pair(-10, -42), Pair(5, -59), Pair(17, -55), Pair(23, -56), Pair(16, -38), Pair(-2, -47),
      Pair(-25, -37), Pair(-22, -33), Pair(-17, -50), Pair(-5, -56), Pair(-3, -59), Pair(15, -58), Pair(7, -48), Pair(-17, -54),
      Pair(-26, -42), Pair(-15, -39), Pair(-24, -48), Pair(-21, -48), Pair(-6, -50), Pair(7, -57), Pair(21, -54), Pair(-14, -59),
      Pair(-25, -37), Pair(-17, -33), Pair(-23, -42), Pair(-29, -44), Pair(-18, -35), Pair(20, -52), Pair(32, -51), Pair(-28, -55),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-136, 7), Pair(-101, 34), Pair(-77, 52), Pair(-55, 34), Pair(19, 19), Pair(-135, 43), Pair(-26, 9), Pair(-109, -29),
      Pair(-24, 20), Pair(-4, 37), Pair(50, 18), Pair(61, 26), Pair(41, 27), Pair(100, 1), Pair(-9, 27), Pair(31, 2),
      Pair(-7, 20), Pair(34, 20), Pair(57, 32), Pair(58, 37), Pair(99, 23), Pair(110, 19), Pair(51, 20), Pair(21, 16),
      Pair(8, 28), Pair(13, 34), Pair(39, 42), Pair(81, 34), Pair(39, 45), Pair(77, 35), Pair(18, 33), Pair(57, 18),
      Pair(3, 21), Pair(15, 27), Pair(35, 40), Pair(29, 42), Pair(46, 43), Pair(40, 35), Pair(65, 15), Pair(19, 31),
      Pair(-22, 9), Pair(2, 17), Pair(10, 22), Pair(30, 36), Pair(45, 31), Pair(21, 17), Pair(28, 11), Pair(-6, 16),
      Pair(-34, 8), Pair(-17, 20), Pair(-1, 14), Pair(21, 13), Pair(21, 14), Pair(23, 3), Pair(10, 16), Pair(0, 14),
      Pair(-53, -12), Pair(-18, -7), Pair(-27, 10), Pair(-3, 17), Pair(5, 10), Pair(17, -1), Pair(-9, -2), Pair(-23, -23)
  },
  {
      Pair(-91, 31), Pair(-115, 37), Pair(-108, 31), Pair(-114, 33), Pair(-101, 34), Pair(-161, 36), Pair(-21, 22), Pair(-27, 18),
      Pair(-37, 19), Pair(-9, 18), Pair(-14, 26), Pair(-31, 28), Pair(-7, 20), Pair(-4, 23), Pair(-26, 19), Pair(-45, 22),
      Pair(-24, 22), Pair(2, 22), Pair(-13, 30), Pair(4, 24), Pair(18, 30), Pair(4, 34), Pair(24, 25), Pair(10, 21),
      Pair(-23, 16), Pair(-10, 27), Pair(5, 22), Pair(28, 30), Pair(12, 30), Pair(10, 26), Pair(-5, 21), Pair(-16, 26),
      Pair(-14, 16), Pair(-12, 19), Pair(-4, 28), Pair(20, 23), Pair(19, 23), Pair(-15, 26), Pair(-2, 20), Pair(9, 12),
      Pair(-14, 17), Pair(5, 26), Pair(-3, 26), Pair(5, 23), Pair(7, 32), Pair(5, 23), Pair(4, 16), Pair(0, 16),
      Pair(1, 22), Pair(-7, 5), Pair(4, 15), Pair(-10, 19), Pair(3, 18), Pair(14, 11), Pair(21, 3), Pair(-1, 3),
      Pair(-30, 11), Pair(-8, 17), Pair(-21, 10), Pair(-31, 23), Pair(-15, 16), Pair(-15, 17), Pair(-5, 0), Pair(-27, 9)
  },
  {
      Pair(37, -5), Pair(19, 14), Pair(25, 8), Pair(32, -3), Pair(38, -3), Pair(20, 14), Pair(50, 2), Pair(47, -2),
      Pair(15, 14), Pair(17, 21), Pair(40, 13), Pair(56, 1), Pair(45, 5), Pair(76, 1), Pair(37, 11), Pair(37, -2),
      Pair(7, 10), Pair(26, 13), Pair(38, 9), Pair(40, -2), Pair(79, -15), Pair(81, -3), Pair(72, -4), Pair(4, 9),
      Pair(-16, 9), Pair(-10, 18), Pair(12, 11), Pair(33, -4), Pair(44, -7), Pair(34, 9), Pair(16, 8), Pair(4, -3),
      Pair(-28, -3), Pair(-18, 4), Pair(-13, 3), Pair(-1, -6), Pair(10, -14), Pair(-10, 5), Pair(-13, -6), Pair(-21, -18),
      Pair(-34, -18), Pair(-27, -8), Pair(-16, -12), Pair(-6, -20), Pair(9, -26), Pair(3, -16), Pair(17, -35), Pair(-17, -34),
      Pair(-31, -24), Pair(-18, -21), Pair(-1, -20), Pair(6, -31), Pair(17, -35), Pair(17, -34), Pair(7, -37), Pair(-46, -29),
      Pair(-6, -29), Pair(-1, -29), Pair(9, -24), Pair(15, -33), Pair(27, -43), Pair(22, -33), Pair(-2, -34), Pair(-5, -42)
  },
  {
      Pair(-58, 33), Pair(-39, 36), Pair(-36, 53), Pair(-6, 38), Pair(-8, 50), Pair(47, 22), Pair(83, -12), Pair(76, -5),
      Pair(-39, 19), Pair(-54, 55), Pair(-40, 71), Pair(-26, 77), Pair(-29, 95), Pair(26, 51), Pair(-8, 44), Pair(78, -33),
      Pair(-22, -6), Pair(-25, 37), Pair(-15, 46), Pair(-20, 66), Pair(18, 63), Pair(75, 36), Pair(67, 19), Pair(36, 26),
      Pair(-22, -2), Pair(-22, 28), Pair(-19, 48), Pair(-4, 54), Pair(7, 58), Pair(0, 64), Pair(5, 46), Pair(20, 18),
      Pair(-18, -17), Pair(-21, 11), Pair(-4, 10), Pair(-8, 40), Pair(2, 23), Pair(0, 28), Pair(9, 10), Pair(15, -6),
      Pair(-16, -30), Pair(0, -32), Pair(3, -11), Pair(1, -10), Pair(16, -16), Pair(17, -14), Pair(20, -32), Pair(18, -55),
      Pair(-8, -43), Pair(6, -51), Pair(15, -53), Pair(23, -58), Pair(23, -54), Pair(32, -81), Pair(40, -97), Pair(11, -102),
      Pair(0, -60), Pair(3, -71), Pair(7, -65), Pair(18, -73), Pair(21, -84), Pair(10, -98), Pair(-28, -73), Pair(-20, -72)
  },
  {
      Pair(165, -90), Pair(172, -21), Pair(130, -18), Pair(30, 4), Pair(58, 1), Pair(50, 14), Pair(105, 10), Pair(218, -56),
      Pair(19, 14), Pair(108, 22), Pair(90, 25), Pair(32, 33), Pair(71, 22), Pair(66, 39), Pair(57, 35), Pair(42, -3),
      Pair(-2, 19), Pair(122, 20), Pair(58, 34), Pair(32, 45), Pair(76, 28), Pair(82, 26), Pair(43, 33), Pair(-25, 21),
      Pair(-8, 3), Pair(60, 18), Pair(3, 43), Pair(2, 46), Pair(-16, 43), Pair(9, 31), Pair(-38, 21), Pair(-55, 10),
      Pair(-18, -17), Pair(24, 10), Pair(-19, 35), Pair(-67, 54), Pair(-70, 46), Pair(-55, 31), Pair(-49, 12), Pair(-55, -11),
      Pair(-34, -13), Pair(7, 8), Pair(-48, 33), Pair(-67, 41), Pair(-66, 37), Pair(-71, 27), Pair(-46, 8), Pair(-42, -14),
      Pair(11, -24), Pair(-22, 7), Pair(-43, 22), Pair(-54, 24), Pair(-55, 21), Pair(-54, 16), Pair(-21, -4), Pair(12, -28),
      Pair(-5, -38), Pair(28, -32), Pair(24, -17), Pair(-59, 7), Pair(15, -26), Pair(-63, -3), Pair(19, -34), Pair(37, -74)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-27, -12), Pair(-13, -22), Pair(1, 1), Pair(10, 15), Pair(19, 20), Pair(27, 29), Pair(33, 28), Pair(39, 26),
  Pair(38, 18)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-34, -24), Pair(-19, -32), Pair(-7, -19), Pair(3, -5), Pair(12, 5), Pair(20, 13), Pair(25, 17), Pair(27, 19),
  Pair(31, 21), Pair(35, 21), Pair(43, 18), Pair(65, 14), Pair(70, 15), Pair(88, 13)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-17, -59), Pair(-5, -37), Pair(1, -29), Pair(5, -24), Pair(5, -15), Pair(10, -11), Pair(13, -5), Pair(17, -5),
  Pair(19, 1), Pair(23, 3), Pair(26, 4), Pair(29, 6), Pair(31, 4), Pair(42, -3), Pair(29, 1)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-4, -192), Pair(-8, -126), Pair(-12, -70), Pair(-7, -62), Pair(-3, -47), Pair(1, -30), Pair(6, -26), Pair(11, -19),
  Pair(16, -12), Pair(19, -8), Pair(20, -2), Pair(24, 4), Pair(26, 5), Pair(30, 8), Pair(29, 14), Pair(35, 14),
  Pair(39, 14), Pair(46, 8), Pair(60, 0), Pair(68, -4), Pair(86, -19), Pair(106, -29), Pair(101, -28), Pair(144, -61),
  Pair(173, -77), Pair(204, -102), Pair(83, -33), Pair(63, -32)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-13, 6), Pair(-19, 13), Pair(-9, 33), Pair(18, 49), Pair(64, 75), Pair(98, -31), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(-4, -4), Pair(-1, 1), Pair(26, 8), Pair(54, 49), Pair(191, 115), Pair(12, 507), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-35, -48), Pair(-15, -28), Pair(-19, -20), Pair(-15, -16), Pair(-16, -16), Pair(-28, -14), Pair(-28, -25), Pair(-21, -39)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-2, -3), Pair(-11, -13), Pair(-23, -12), Pair(-26, -16), Pair(-25, -15), Pair(-16, -12), Pair(-10, -10), Pair(-3, -1)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(39, -1), Pair(43, -6), Pair(39, 1), Pair(42, 5), Pair(41, 5), Pair(63, -13), Pair(95, -15), Pair(110, -17)
  },
  {
      Pair(21, 33), Pair(19, 14), Pair(18, 9), Pair(26, 9), Pair(17, 8), Pair(33, -7), Pair(42, -2), Pair(34, 18)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(25, -2), Pair(27, -1), Pair(21, -2),
  Pair(38, -7), Pair(41, -5), Pair(38, -8),
  Pair(45, -4), Pair(0, 0), Pair(46, -5),
  Pair(0, -5), Pair(7, 1), Pair(1, -4)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-15, 10), Pair(-19, 13), Pair(-17, 14),
  Pair(-9, 9), Pair(-21, 18), Pair(-14, 11),
  Pair(-1, -1), Pair(-17, 14), Pair(-4, 2),
  Pair(9, 0), Pair(-14, 13), Pair(6, 1),
  Pair(24, -8), Pair(14, 9), Pair(27, -9),
  Pair(0, 0), Pair(-59, -32), Pair(0, 0),
  Pair(-39, -36), Pair(0, 0), Pair(-35, -39)
};

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-41, -21), Pair(-103, -3), Pair(-57, -11), Pair(-33, -12), Pair(-32, -5), Pair(-39, -1), Pair(-55, 8), Pair(-39, -3)
  },
  {
      Pair(-80, 86), Pair(-82, 46), Pair(-24, 19), Pair(-5, 7), Pair(-1, 5), Pair(-14, 14), Pair(-33, 29), Pair(-41, 50)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(31, -19), Pair(5, 9), Pair(29, 9), Pair(38, 16), Pair(16, 21), Pair(10, 33), Pair(34, 11), Pair(35, 8),
  Pair(13, 22), Pair(18, -3), Pair(19, 20), Pair(7, 30), Pair(14, 17), Pair(-5, 29), Pair(29, 8), Pair(10, 19),
  Pair(6, 15), Pair(0, 8), Pair(-3, 19), Pair(13, 20), Pair(2, 20), Pair(0, 11), Pair(-24, 15), Pair(3, -8)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-35, -1), Pair(22, 0), Pair(33, -8), Pair(43, -9), Pair(39, -11), Pair(74, -17), Pair(37, -10), Pair(-24, -1),
  Pair(-6, 10), Pair(19, 9), Pair(18, 1), Pair(32, -2), Pair(21, 0), Pair(30, 6), Pair(18, 15), Pair(-2, -5),
  Pair(-38, 20), Pair(4, 15), Pair(15, 11), Pair(20, 10), Pair(24, 12), Pair(2, 12), Pair(-4, 17), Pair(-70, 28)
};

constexpr ScorePair kBishopPairBonus = Pair(36, 56);

constexpr ScorePair kTempoBonus = Pair(50, 13);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_EVALUATION_TERMS_H