#ifndef INTEGRAL_EVALUATION_TERMS_H
#define INTEGRAL_EVALUATION_TERMS_H

#include "../../utils/types.h"

namespace eval {

// clang-format off
template <typename T>
using PieceValueTable = std::array<T, kNumPieceTypes>;

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

constexpr PieceValueTable<ScorePair> kPieceValues = {
  Pair(83, 157), Pair(296, 326), Pair(352, 347), Pair(419, 695), Pair(866, 1274), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(48, 149), Pair(50, 140), Pair(33, 142), Pair(63, 90), Pair(45, 90), Pair(35, 103), Pair(-18, 152), Pair(-32, 154),
      Pair(3, 5), Pair(-9, 18), Pair(27, -27), Pair(28, -65), Pair(36, -69), Pair(69, -50), Pair(21, 5), Pair(2, -8),
      Pair(-19, -16), Pair(-18, -15), Pair(-9, -37), Pair(-4, -57), Pair(18, -59), Pair(14, -53), Pair(-5, -19), Pair(-7, -39),
      Pair(-25, -36), Pair(-28, -24), Pair(-16, -44), Pair(0, -54), Pair(1, -55), Pair(7, -55), Pair(-10, -31), Pair(-8, -53),
      Pair(-24, -41), Pair(-22, -30), Pair(-13, -45), Pair(-9, -46), Pair(3, -46), Pair(0, -51), Pair(3, -37), Pair(-5, -57),
      Pair(-24, -35), Pair(-23, -24), Pair(-18, -38), Pair(-20, -43), Pair(-7, -34), Pair(8, -46), Pair(10, -33), Pair(-17, -55),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-137, -49), Pair(-115, -3), Pair(-59, 11), Pair(-24, -2), Pair(6, 2), Pair(-53, -21), Pair(-98, -3), Pair(-97, -68),
      Pair(-15, 2), Pair(5, 13), Pair(31, 8), Pair(48, 6), Pair(22, 0), Pair(85, -13), Pair(1, 8), Pair(22, -20),
      Pair(3, 6), Pair(31, 13), Pair(40, 34), Pair(52, 34), Pair(87, 18), Pair(88, 9), Pair(50, 4), Pair(25, -4),
      Pair(6, 20), Pair(9, 29), Pair(30, 43), Pair(53, 45), Pair(33, 44), Pair(55, 41), Pair(19, 31), Pair(41, 10),
      Pair(-6, 23), Pair(2, 22), Pair(13, 44), Pair(20, 43), Pair(28, 47), Pair(24, 35), Pair(33, 21), Pair(9, 20),
      Pair(-27, 6), Pair(-8, 15), Pair(0, 21), Pair(10, 37), Pair(27, 34), Pair(10, 17), Pair(15, 10), Pair(-4, 12),
      Pair(-31, 7), Pair(-19, 14), Pair(-7, 16), Pair(9, 15), Pair(10, 13), Pair(9, 12), Pair(4, 4), Pair(-1, 16),
      Pair(-63, 11), Pair(-24, 1), Pair(-25, 12), Pair(-10, 16), Pair(-2, 16), Pair(0, 5), Pair(-21, 7), Pair(-31, 6)
  },
  {
      Pair(-42, 21), Pair(-66, 24), Pair(-60, 18), Pair(-101, 27), Pair(-87, 23), Pair(-83, 14), Pair(-45, 13), Pair(-62, 8),
      Pair(-22, 2), Pair(-4, 14), Pair(-13, 15), Pair(-26, 19), Pair(1, 7), Pair(-9, 12), Pair(-12, 16), Pair(-28, 6),
      Pair(-16, 21), Pair(2, 16), Pair(1, 24), Pair(17, 12), Pair(8, 17), Pair(36, 23), Pair(16, 17), Pair(8, 19),
      Pair(-24, 17), Pair(-8, 26), Pair(6, 23), Pair(24, 37), Pair(17, 29), Pair(8, 29), Pair(-7, 21), Pair(-18, 18),
      Pair(-18, 14), Pair(-19, 25), Pair(-9, 33), Pair(16, 33), Pair(14, 31), Pair(-12, 28), Pair(-12, 22), Pair(-1, 3),
      Pair(-16, 14), Pair(2, 25), Pair(-1, 27), Pair(-2, 30), Pair(1, 34), Pair(2, 27), Pair(3, 17), Pair(5, 6),
      Pair(-2, 19), Pair(-1, 6), Pair(7, 9), Pair(-11, 19), Pair(0, 17), Pair(8, 12), Pair(19, 10), Pair(5, 1),
      Pair(-15, 8), Pair(10, 21), Pair(-15, 11), Pair(-19, 18), Pair(-12, 15), Pair(-16, 22), Pair(-1, 6), Pair(9, -14)
  },
  {
      Pair(11, 7), Pair(5, 19), Pair(7, 19), Pair(4, 14), Pair(15, 4), Pair(28, 13), Pair(21, 12), Pair(3, 10),
      Pair(4, 9), Pair(5, 26), Pair(23, 21), Pair(37, 10), Pair(23, 8), Pair(45, 10), Pair(36, 7), Pair(21, 1),
      Pair(-10, 8), Pair(18, 13), Pair(18, 8), Pair(16, 4), Pair(45, -10), Pair(53, -6), Pair(77, -10), Pair(27, -15),
      Pair(-13, 8), Pair(1, 12), Pair(4, 12), Pair(8, 7), Pair(11, -8), Pair(14, -1), Pair(17, -1), Pair(0, -9),
      Pair(-20, -2), Pair(-20, 10), Pair(-8, 3), Pair(-5, 2), Pair(-3, -5), Pair(-16, 7), Pair(7, -7), Pair(-9, -16),
      Pair(-23, -8), Pair(-17, -2), Pair(-10, -8), Pair(-11, -4), Pair(2, -15), Pair(0, -11), Pair(29, -32), Pair(5, -35),
      Pair(-22, -15), Pair(-15, -6), Pair(0, -9), Pair(1, -10), Pair(7, -20), Pair(10, -17), Pair(18, -29), Pair(-18, -30),
      Pair(-7, -10), Pair(-2, -9), Pair(5, -7), Pair(10, -13), Pair(16, -21), Pair(11, -13), Pair(5, -19), Pair(-2, -31)
  },
  {
      Pair(-48, -2), Pair(-54, 15), Pair(-36, 36), Pair(2, 17), Pair(2, 18), Pair(12, 16), Pair(53, -42), Pair(-15, 4),
      Pair(-10, -20), Pair(-32, 14), Pair(-30, 45), Pair(-43, 68), Pair(-36, 84), Pair(5, 42), Pair(5, 22), Pair(41, 11),
      Pair(-9, -12), Pair(-13, 2), Pair(-17, 36), Pair(-6, 43), Pair(-3, 58), Pair(47, 37), Pair(50, 9), Pair(46, 7),
      Pair(-20, -5), Pair(-18, 11), Pair(-15, 22), Pair(-16, 42), Pair(-15, 57), Pair(-1, 46), Pair(4, 42), Pair(8, 28),
      Pair(-17, -10), Pair(-21, 14), Pair(-15, 13), Pair(-11, 33), Pair(-8, 29), Pair(-10, 30), Pair(-1, 20), Pair(7, 15),
      Pair(-13, -28), Pair(-9, -10), Pair(-9, 2), Pair(-11, 2), Pair(-6, 9), Pair(-1, 9), Pair(10, -6), Pair(7, -15),
      Pair(-8, -37), Pair(-5, -34), Pair(1, -33), Pair(6, -30), Pair(5, -24), Pair(13, -43), Pair(17, -63), Pair(21, -81),
      Pair(-14, -37), Pair(-7, -37), Pair(-4, -34), Pair(-1, -26), Pair(4, -40), Pair(-7, -37), Pair(2, -57), Pair(1, -63)
  },
  {
      Pair(71, -89), Pair(94, -44), Pair(83, -27), Pair(-56, 18), Pair(-26, -2), Pair(8, -6), Pair(76, -22), Pair(186, -128),
      Pair(-62, 6), Pair(18, 29), Pair(-35, 43), Pair(51, 30), Pair(-10, 41), Pair(-4, 52), Pair(24, 34), Pair(-18, 7),
      Pair(-90, 14), Pair(61, 24), Pair(-25, 51), Pair(-48, 63), Pair(-25, 62), Pair(50, 41), Pair(-6, 41), Pair(-49, 12),
      Pair(-60, 1), Pair(-17, 22), Pair(-70, 51), Pair(-114, 67), Pair(-120, 61), Pair(-84, 48), Pair(-80, 29), Pair(-131, 13),
      Pair(-56, -14), Pair(-26, 11), Pair(-91, 44), Pair(-123, 62), Pair(-133, 58), Pair(-86, 35), Pair(-81, 16), Pair(-127, 1),
      Pair(-24, -20), Pair(9, 0), Pair(-61, 30), Pair(-81, 46), Pair(-82, 42), Pair(-74, 26), Pair(-34, 1), Pair(-45, -16),
      Pair(40, -37), Pair(-6, -2), Pair(-16, 11), Pair(-39, 23), Pair(-50, 24), Pair(-32, 10), Pair(-8, -10), Pair(24, -39),
      Pair(35, -70), Pair(41, -41), Pair(34, -26), Pair(-34, -2), Pair(16, -29), Pair(-25, -11), Pair(26, -38), Pair(47, -81)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-25, 0), Pair(-12, 5), Pair(-1, 26), Pair(4, 35), Pair(10, 42), Pair(16, 50), Pair(23, 49), Pair(28, 45),
  Pair(34, 34)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-55, -16), Pair(-44, -15), Pair(-34, 2), Pair(-26, 15), Pair(-18, 24), Pair(-13, 35), Pair(-9, 38), Pair(-6, 40),
  Pair(-5, 43), Pair(0, 39), Pair(8, 35), Pair(15, 33), Pair(15, 41), Pair(25, 18)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-38, -56), Pair(-31, -28), Pair(-27, -25), Pair(-24, -20), Pair(-26, -12), Pair(-20, -8), Pair(-19, -3), Pair(-15, -1),
  Pair(-12, 3), Pair(-9, 6), Pair(-5, 7), Pair(-5, 10), Pair(-1, 12), Pair(3, 9), Pair(-5, 9)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-3, -262), Pair(-1, -247), Pair(-12, -107), Pair(-10, -61), Pair(-8, -38), Pair(-5, -26), Pair(-3, -8), Pair(-1, 7),
  Pair(2, 13), Pair(4, 16), Pair(5, 24), Pair(8, 31), Pair(10, 32), Pair(10, 40), Pair(13, 42), Pair(15, 46),
  Pair(15, 54), Pair(17, 56), Pair(25, 54), Pair(38, 46), Pair(40, 49), Pair(89, 19), Pair(75, 31), Pair(98, 10),
  Pair(210, -33), Pair(223, -62), Pair(156, -8), Pair(109, -6)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-5, 0), Pair(-12, 10), Pair(-9, 36), Pair(11, 61), Pair(8, 123), Pair(27, 34), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(0, -7), Pair(-1, -1), Pair(18, 9), Pair(43, 46), Pair(112, 182), Pair(-98, 436), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-13, -44), Pair(6, -34), Pair(-5, -28), Pair(-4, -17), Pair(-11, -10), Pair(-13, -25), Pair(3, -40), Pair(-10, -54)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-10, 3), Pair(-6, -15), Pair(-17, -12), Pair(-15, -18), Pair(-18, -20), Pair(-9, -10), Pair(-7, -16), Pair(-7, 5)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(26, 11), Pair(25, 3), Pair(22, 12), Pair(26, 11), Pair(28, 16), Pair(48, -2), Pair(58, -1), Pair(90, -1)
  },
  {
      Pair(3, 46), Pair(7, 18), Pair(6, 19), Pair(15, 8), Pair(10, 10), Pair(19, 2), Pair(28, 4), Pair(18, 29)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(18, -1), Pair(17, 7), Pair(15, 3),
  Pair(28, -5), Pair(24, 1), Pair(26, -7),
  Pair(38, 0), Pair(0, 0), Pair(34, 1),
  Pair(-20, 5), Pair(-11, 12), Pair(-20, 6)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-12, 8), Pair(-17, 12), Pair(-13, 9),
  Pair(-11, 9), Pair(-19, 16), Pair(-13, 10),
  Pair(-6, 2), Pair(-16, 11), Pair(-5, 2),
  Pair(7, -1), Pair(-12, 8), Pair(6, 1),
  Pair(21, -5), Pair(13, 8), Pair(14, -5),
  Pair(0, 0), Pair(-71, -24), Pair(0, 0),
  Pair(-12, -48), Pair(0, 0), Pair(-16, -45)
};

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-81, -14), Pair(-112, 3), Pair(-61, -5), Pair(-59, -2), Pair(-41, 2), Pair(-75, 11), Pair(-73, 13), Pair(-48, 8)
  },
  {
      Pair(-31, 68), Pair(-62, 38), Pair(-28, 27), Pair(-11, 10), Pair(-11, 5), Pair(-24, 18), Pair(-42, 35), Pair(-30, 49)
  }
}};

constexpr ScorePair kBishopPairBonus = Pair(22, 65);
constexpr ScorePair kTempoBonus = Pair(20, 25);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_EVALUATION_TERMS_H