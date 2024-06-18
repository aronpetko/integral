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

constexpr PieceTable<ScorePair> kPieceValues = {
  Pair(83, 161), Pair(300, 345), Pair(336, 360), Pair(407, 696), Pair(878, 1292), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(53, 161), Pair(56, 153), Pair(39, 153), Pair(69, 101), Pair(51, 102), Pair(42, 115), Pair(-12, 165), Pair(-26, 165),
      Pair(4, 3), Pair(-7, 17), Pair(28, -30), Pair(29, -67), Pair(38, -70), Pair(70, -53), Pair(22, 3), Pair(3, -10),
      Pair(-19, -19), Pair(-16, -18), Pair(-8, -40), Pair(-3, -60), Pair(20, -63), Pair(16, -57), Pair(-3, -21), Pair(-6, -41),
      Pair(-25, -39), Pair(-26, -26), Pair(-16, -48), Pair(1, -57), Pair(3, -57), Pair(8, -58), Pair(-9, -32), Pair(-7, -56),
      Pair(-24, -44), Pair(-20, -32), Pair(-13, -49), Pair(-8, -49), Pair(4, -49), Pair(1, -55), Pair(4, -38), Pair(-5, -60),
      Pair(-23, -39), Pair(-20, -26), Pair(-17, -41), Pair(-19, -46), Pair(-6, -36), Pair(8, -49), Pair(11, -35), Pair(-17, -57),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-136, -38), Pair(-114, 9), Pair(-57, 22), Pair(-22, 9), Pair(8, 13), Pair(-51, -10), Pair(-95, 7), Pair(-95, -57),
      Pair(-13, 13), Pair(8, 24), Pair(34, 18), Pair(51, 16), Pair(25, 11), Pair(89, -3), Pair(4, 20), Pair(26, -9),
      Pair(5, 17), Pair(32, 21), Pair(43, 42), Pair(54, 41), Pair(91, 26), Pair(92, 16), Pair(53, 13), Pair(28, 6),
      Pair(8, 31), Pair(12, 37), Pair(32, 49), Pair(55, 51), Pair(36, 49), Pair(58, 47), Pair(22, 38), Pair(44, 20),
      Pair(-4, 32), Pair(4, 30), Pair(15, 51), Pair(23, 49), Pair(30, 55), Pair(27, 40), Pair(36, 27), Pair(11, 27),
      Pair(-26, 14), Pair(-6, 22), Pair(2, 26), Pair(12, 46), Pair(28, 40), Pair(12, 21), Pair(18, 14), Pair(-2, 20),
      Pair(-29, 19), Pair(-17, 26), Pair(-5, 28), Pair(12, 27), Pair(13, 26), Pair(12, 23), Pair(6, 16), Pair(2, 29),
      Pair(-61, 22), Pair(-22, 14), Pair(-23, 23), Pair(-8, 28), Pair(0, 28), Pair(3, 17), Pair(-18, 20), Pair(-28, 17)
  },
  {
      Pair(-47, 29), Pair(-71, 32), Pair(-65, 25), Pair(-107, 35), Pair(-92, 31), Pair(-88, 21), Pair(-48, 20), Pair(-66, 16),
      Pair(-26, 10), Pair(-7, 19), Pair(-17, 21), Pair(-31, 24), Pair(-4, 13), Pair(-12, 17), Pair(-16, 20), Pair(-32, 13),
      Pair(-20, 28), Pair(-2, 20), Pair(-4, 27), Pair(12, 14), Pair(2, 18), Pair(32, 25), Pair(12, 21), Pair(5, 26),
      Pair(-28, 24), Pair(-12, 28), Pair(0, 24), Pair(18, 37), Pair(12, 29), Pair(4, 29), Pair(-10, 23), Pair(-22, 24),
      Pair(-22, 20), Pair(-25, 27), Pair(-14, 35), Pair(11, 33), Pair(10, 32), Pair(-18, 29), Pair(-17, 24), Pair(-5, 9),
      Pair(-20, 20), Pair(-6, 26), Pair(-8, 29), Pair(-7, 34), Pair(-6, 35), Pair(-6, 28), Pair(-5, 17), Pair(1, 13),
      Pair(-5, 26), Pair(-5, 14), Pair(4, 15), Pair(-14, 26), Pair(-3, 25), Pair(5, 20), Pair(16, 19), Pair(2, 8),
      Pair(-19, 16), Pair(6, 30), Pair(-18, 20), Pair(-23, 25), Pair(-16, 23), Pair(-19, 31), Pair(-5, 14), Pair(5, -5)
  },
  {
      Pair(10, 6), Pair(4, 18), Pair(6, 18), Pair(3, 13), Pair(14, 2), Pair(27, 12), Pair(21, 11), Pair(2, 9),
      Pair(2, 8), Pair(4, 25), Pair(22, 20), Pair(35, 9), Pair(21, 7), Pair(45, 9), Pair(34, 5), Pair(20, -1),
      Pair(-11, 7), Pair(17, 12), Pair(17, 7), Pair(15, 2), Pair(44, -12), Pair(52, -7), Pair(76, -11), Pair(26, -16),
      Pair(-14, 8), Pair(0, 11), Pair(3, 11), Pair(7, 6), Pair(9, -9), Pair(13, -1), Pair(15, -2), Pair(-1, -10),
      Pair(-22, -2), Pair(-21, 9), Pair(-9, 1), Pair(-6, 1), Pair(-5, -6), Pair(-17, 5), Pair(6, -9), Pair(-10, -17),
      Pair(-25, -9), Pair(-19, -4), Pair(-11, -9), Pair(-12, -6), Pair(-1, -16), Pair(-2, -13), Pair(28, -33), Pair(4, -36),
      Pair(-23, -16), Pair(-17, -7), Pair(-1, -11), Pair(-1, -12), Pair(5, -22), Pair(8, -19), Pair(17, -30), Pair(-19, -31),
      Pair(-9, -13), Pair(-3, -11), Pair(4, -8), Pair(8, -15), Pair(14, -23), Pair(10, -14), Pair(3, -20), Pair(-4, -32)
  },
  {
      Pair(-47, -1), Pair(-53, 17), Pair(-36, 38), Pair(3, 19), Pair(3, 20), Pair(12, 19), Pair(56, -41), Pair(-14, 6),
      Pair(-8, -19), Pair(-31, 16), Pair(-29, 47), Pair(-42, 71), Pair(-35, 87), Pair(7, 44), Pair(7, 23), Pair(43, 13),
      Pair(-8, -10), Pair(-12, 4), Pair(-14, 38), Pair(-5, 45), Pair(0, 60), Pair(49, 39), Pair(52, 11), Pair(48, 8),
      Pair(-19, -4), Pair(-17, 14), Pair(-13, 23), Pair(-14, 44), Pair(-14, 60), Pair(0, 48), Pair(6, 44), Pair(9, 30),
      Pair(-16, -9), Pair(-19, 16), Pair(-15, 14), Pair(-10, 35), Pair(-6, 31), Pair(-9, 31), Pair(1, 22), Pair(8, 16),
      Pair(-12, -28), Pair(-8, -8), Pair(-7, 3), Pair(-10, 4), Pair(-5, 10), Pair(-1, 12), Pair(12, -4), Pair(8, -13),
      Pair(-7, -36), Pair(-4, -34), Pair(2, -32), Pair(8, -29), Pair(6, -23), Pair(15, -43), Pair(18, -62), Pair(23, -81),
      Pair(-13, -36), Pair(-7, -36), Pair(-2, -33), Pair(1, -25), Pair(5, -39), Pair(-6, -36), Pair(3, -56), Pair(2, -63)
  },
  {
      Pair(80, -92), Pair(115, -49), Pair(92, -28), Pair(-50, 17), Pair(-29, -1), Pair(3, -4), Pair(70, -21), Pair(175, -127),
      Pair(-56, 6), Pair(25, 28), Pair(-34, 44), Pair(55, 30), Pair(-11, 43), Pair(-3, 53), Pair(24, 35), Pair(-25, 9),
      Pair(-85, 14), Pair(63, 25), Pair(-23, 52), Pair(-45, 64), Pair(-23, 63), Pair(53, 42), Pair(-4, 41), Pair(-48, 12),
      Pair(-58, 2), Pair(-16, 23), Pair(-68, 52), Pair(-114, 68), Pair(-119, 63), Pair(-82, 50), Pair(-80, 29), Pair(-130, 13),
      Pair(-55, -12), Pair(-23, 12), Pair(-90, 46), Pair(-123, 63), Pair(-132, 59), Pair(-85, 36), Pair(-81, 16), Pair(-126, 2),
      Pair(-22, -20), Pair(11, 0), Pair(-61, 31), Pair(-80, 47), Pair(-81, 42), Pair(-73, 27), Pair(-33, 1), Pair(-43, -17),
      Pair(42, -36), Pair(-4, -2), Pair(-15, 12), Pair(-37, 23), Pair(-49, 24), Pair(-31, 10), Pair(-7, -10), Pair(26, -39),
      Pair(37, -71), Pair(43, -41), Pair(36, -27), Pair(-33, -2), Pair(18, -30), Pair(-23, -12), Pair(27, -38), Pair(49, -81)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-29, -26), Pair(-16, -21), Pair(-6, -1), Pair(0, 9), Pair(6, 17), Pair(11, 25), Pair(18, 24), Pair(25, 21),
  Pair(31, 11)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-33, -33), Pair(-22, -32), Pair(-12, -15), Pair(-4, -1), Pair(4, 9), Pair(9, 20), Pair(14, 24), Pair(16, 26),
  Pair(18, 30), Pair(24, 28), Pair(33, 24), Pair(40, 24), Pair(40, 33), Pair(50, 11)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-20, -48), Pair(-13, -20), Pair(-9, -17), Pair(-5, -11), Pair(-8, -4), Pair(-3, 0), Pair(-1, 6), Pair(2, 9),
  Pair(6, 11), Pair(9, 14), Pair(13, 16), Pair(13, 19), Pair(17, 20), Pair(21, 16), Pair(14, 16)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-13, -182), Pair(-4, -253), Pair(-15, -113), Pair(-13, -66), Pair(-12, -43), Pair(-9, -31), Pair(-6, -12), Pair(-5, 2),
  Pair(-2, 10), Pair(1, 13), Pair(2, 19), Pair(5, 26), Pair(7, 27), Pair(7, 36), Pair(9, 37), Pair(12, 42),
  Pair(12, 50), Pair(13, 52), Pair(21, 50), Pair(34, 42), Pair(37, 45), Pair(87, 15), Pair(72, 27), Pair(96, 5),
  Pair(167, -12), Pair(138, -18), Pair(70, 38), Pair(43, 24)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-5, 0), Pair(-12, 9), Pair(-9, 35), Pair(11, 62), Pair(8, 124), Pair(23, 22), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(-1, -8), Pair(-1, -1), Pair(18, 9), Pair(43, 47), Pair(119, 181), Pair(63, 338), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-13, -44), Pair(5, -35), Pair(-4, -28), Pair(-3, -18), Pair(-11, -11), Pair(-14, -25), Pair(3, -41), Pair(-10, -55)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-8, 3), Pair(-7, -16), Pair(-18, -11), Pair(-15, -19), Pair(-19, -20), Pair(-10, -10), Pair(-7, -16), Pair(-7, 5)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(26, 12), Pair(25, 4), Pair(22, 12), Pair(27, 12), Pair(28, 17), Pair(49, -1), Pair(58, 0), Pair(90, -1)
  },
  {
      Pair(2, 47), Pair(7, 18), Pair(5, 19), Pair(15, 9), Pair(11, 11), Pair(19, 2), Pair(28, 5), Pair(18, 30)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(18, 0), Pair(18, 7), Pair(15, 3),
  Pair(29, -6), Pair(25, 2), Pair(28, -7),
  Pair(39, 1), Pair(0, 0), Pair(35, 1),
  Pair(-20, 5), Pair(-12, 13), Pair(-20, 6)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-12, 8), Pair(-17, 13), Pair(-13, 10),
  Pair(-11, 9), Pair(-19, 16), Pair(-13, 11),
  Pair(-6, 1), Pair(-15, 11), Pair(-6, 3),
  Pair(7, -1), Pair(-12, 8), Pair(7, 2),
  Pair(21, -6), Pair(14, 8), Pair(15, -5),
  Pair(0, 0), Pair(-72, -25), Pair(0, 0),
  Pair(-12, -49), Pair(0, 0), Pair(-15, -46)
};

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-83, -14), Pair(-114, 4), Pair(-62, -5), Pair(-60, -2), Pair(-42, 2), Pair(-77, 11), Pair(-73, 13), Pair(-48, 8)
  },
  {
      Pair(-31, 68), Pair(-63, 38), Pair(-29, 27), Pair(-11, 10), Pair(-10, 5), Pair(-25, 18), Pair(-43, 37), Pair(-30, 51)
  }
}};

constexpr ScorePair kDefendedBishopBonus = Pair(4, 13);
constexpr ScorePair kDefendedKnightBonus = Pair(1, 14);

constexpr ScorePair kBishopPairBonus = Pair(21, 67);

constexpr ScorePair kTempoBonus = Pair(21, 25);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_EVALUATION_TERMS_H