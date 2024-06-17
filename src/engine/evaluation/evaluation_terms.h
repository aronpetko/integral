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
  Pair(97, 150), Pair(296, 337), Pair(352, 335), Pair(416, 696), Pair(868, 1290), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(22, 163), Pair(51, 146), Pair(21, 156), Pair(59, 86), Pair(40, 95), Pair(13, 115), Pair(29, 123), Pair(-35, 166),
      Pair(-10, 21), Pair(-14, 36), Pair(11, -6), Pair(23, -61), Pair(43, -69), Pair(61, -44), Pair(31, 9), Pair(6, 1),
      Pair(-11, -21), Pair(-4, -22), Pair(-14, -38), Pair(2, -77), Pair(23, -72), Pair(19, -61), Pair(6, -26), Pair(6, -41),
      Pair(-16, -44), Pair(-14, -31), Pair(-21, -45), Pair(-6, -54), Pair(-3, -55), Pair(-2, -53), Pair(-4, -40), Pair(-1, -56),
      Pair(-17, -47), Pair(-14, -29), Pair(-23, -39), Pair(-16, -40), Pair(-5, -41), Pair(-3, -52), Pair(5, -35), Pair(7, -59),
      Pair(-18, -40), Pair(-16, -23), Pair(-33, -20), Pair(-25, -40), Pair(-13, -25), Pair(-4, -33), Pair(8, -29), Pair(-3, -63),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-137, -53), Pair(-115, -4), Pair(-58, 7), Pair(-27, -2), Pair(5, 0), Pair(-51, -23), Pair(-100, -3), Pair(-94, -72),
      Pair(-15, -2), Pair(8, 4), Pair(35, -5), Pair(58, -7), Pair(10, 4), Pair(70, -6), Pair(-6, 19), Pair(32, -26),
      Pair(23, -10), Pair(35, 3), Pair(48, 26), Pair(43, 37), Pair(95, 12), Pair(62, 30), Pair(38, 16), Pair(-18, 32),
      Pair(21, 0), Pair(8, 29), Pair(25, 45), Pair(35, 77), Pair(30, 54), Pair(41, 63), Pair(9, 51), Pair(40, 10),
      Pair(-4, 20), Pair(7, 13), Pair(14, 45), Pair(18, 44), Pair(17, 67), Pair(21, 44), Pair(20, 43), Pair(1, 41),
      Pair(-20, -14), Pair(-5, 4), Pair(2, 16), Pair(11, 33), Pair(25, 34), Pair(11, 17), Pair(16, 13), Pair(-8, 22),
      Pair(-26, -1), Pair(-4, -10), Pair(-4, 7), Pair(11, 8), Pair(11, 12), Pair(13, 1), Pair(-2, 5), Pair(-2, 28),
      Pair(-71, 20), Pair(-17, -24), Pair(-10, -15), Pair(-1, 2), Pair(-1, 11), Pair(1, 3), Pair(-17, -14), Pair(-4, -46)
  },
  {
      Pair(-40, 26), Pair(-57, 25), Pair(-58, 25), Pair(-97, 30), Pair(-85, 29), Pair(-87, 19), Pair(-50, 22), Pair(-62, 16),
      Pair(-31, 15), Pair(-11, 24), Pair(21, -8), Pair(-18, 20), Pair(19, -4), Pair(15, 0), Pair(-26, 32), Pair(-23, 8),
      Pair(-8, 19), Pair(29, 0), Pair(12, 20), Pair(29, 7), Pair(15, 14), Pair(22, 39), Pair(32, 14), Pair(-7, 53),
      Pair(-18, 16), Pair(-11, 37), Pair(-5, 37), Pair(1, 69), Pair(13, 45), Pair(12, 36), Pair(-1, 16), Pair(-26, 40),
      Pair(-14, 16), Pair(-11, 22), Pair(-13, 52), Pair(10, 47), Pair(-2, 58), Pair(-6, 27), Pair(-10, 25), Pair(3, -3),
      Pair(-5, 5), Pair(1, 38), Pair(0, 30), Pair(-5, 46), Pair(3, 34), Pair(-8, 48), Pair(3, 30), Pair(5, 15),
      Pair(7, 15), Pair(3, 0), Pair(10, 14), Pair(-3, 8), Pair(2, 16), Pair(13, 6), Pair(13, 25), Pair(14, 3),
      Pair(-4, 9), Pair(17, 21), Pair(-8, -4), Pair(-8, 16), Pair(5, 4), Pair(-11, 17), Pair(-11, 32), Pair(14, -34)
  },
  {
      Pair(25, 11), Pair(10, 31), Pair(8, 25), Pair(6, 15), Pair(18, 8), Pair(28, 18), Pair(20, 17), Pair(6, 11),
      Pair(19, 11), Pair(-6, 44), Pair(12, 30), Pair(35, 13), Pair(24, 11), Pair(34, 25), Pair(9, 28), Pair(-16, 20),
      Pair(-6, 13), Pair(27, 20), Pair(-3, 25), Pair(3, 11), Pair(27, 8), Pair(47, 1), Pair(72, -2), Pair(25, -13),
      Pair(1, 7), Pair(-3, 27), Pair(-11, 27), Pair(4, 17), Pair(-26, 26), Pair(-8, 25), Pair(-8, 20), Pair(-17, 4),
      Pair(-10, -3), Pair(-52, 45), Pair(-14, 13), Pair(-19, 19), Pair(-19, 13), Pair(-21, 19), Pair(5, 0), Pair(-28, 3),
      Pair(-12, -13), Pair(1, -9), Pair(-10, -2), Pair(-16, 10), Pair(-11, 5), Pair(-13, 14), Pair(-1, 16), Pair(-4, -20),
      Pair(0, -37), Pair(4, -15), Pair(20, -25), Pair(10, -11), Pair(13, -24), Pair(10, -9), Pair(35, -48), Pair(-9, -51),
      Pair(3, -21), Pair(10, -23), Pair(18, -21), Pair(22, -23), Pair(22, -20), Pair(16, -6), Pair(4, -11), Pair(2, -50)
  },
  {
      Pair(-38, -17), Pair(-61, 21), Pair(-35, 36), Pair(-2, 23), Pair(-2, 23), Pair(12, 20), Pair(47, -33), Pair(-15, 11),
      Pair(-31, -3), Pair(-42, 24), Pair(-72, 110), Pair(-47, 76), Pair(-23, 73), Pair(-14, 77), Pair(-16, 62), Pair(39, 16),
      Pair(-16, -9), Pair(-38, 39), Pair(-33, 66), Pair(10, 18), Pair(19, 28), Pair(43, 51), Pair(43, 30), Pair(-9, 160),
      Pair(-3, -40), Pair(-16, 7), Pair(-9, 11), Pair(-28, 71), Pair(-27, 86), Pair(-10, 67), Pair(-15, 91), Pair(-3, 75),
      Pair(-15, -12), Pair(-14, 4), Pair(-16, 13), Pair(-31, 83), Pair(-13, 40), Pair(-7, 30), Pair(13, -9), Pair(27, -28),
      Pair(-18, -2), Pair(-4, -20), Pair(-18, 36), Pair(-17, 22), Pair(-6, 21), Pair(2, 5), Pair(16, -17), Pair(18, -37),
      Pair(6, -64), Pair(4, -51), Pair(7, -47), Pair(16, -56), Pair(10, -39), Pair(14, -38), Pair(17, -70), Pair(42, -126),
      Pair(-7, -45), Pair(-1, -43), Pair(8, -54), Pair(7, -42), Pair(14, -60), Pair(-9, -28), Pair(-8, -32), Pair(-3, -54)
  },
  {
      Pair(66, -79), Pair(70, -31), Pair(74, -29), Pair(-67, 32), Pair(-23, 13), Pair(19, 6), Pair(85, -8), Pair(194, -125),
      Pair(-69, 27), Pair(-16, 52), Pair(-45, 47), Pair(45, 49), Pair(-3, 56), Pair(-2, 66), Pair(31, 57), Pair(3, 18),
      Pair(-101, 35), Pair(24, 46), Pair(-34, 54), Pair(-55, 73), Pair(-18, 69), Pair(45, 47), Pair(-6, 55), Pair(-34, 21),
      Pair(-61, 15), Pair(-53, 44), Pair(-76, 53), Pair(-122, 75), Pair(-115, 68), Pair(-94, 54), Pair(-88, 41), Pair(-126, 22),
      Pair(-57, -3), Pair(-54, 29), Pair(-101, 49), Pair(-131, 75), Pair(-134, 70), Pair(-96, 40), Pair(-88, 29), Pair(-129, 6),
      Pair(-29, -14), Pair(-2, 8), Pair(-52, 25), Pair(-65, 54), Pair(-85, 51), Pair(-79, 24), Pair(-20, -2), Pair(-59, -13),
      Pair(24, -24), Pair(5, -5), Pair(2, 1), Pair(-44, 28), Pair(-50, 27), Pair(-15, 0), Pair(2, -19), Pair(29, -53),
      Pair(14, -50), Pair(32, -31), Pair(28, -19), Pair(-39, 0), Pair(11, -40), Pair(-12, -27), Pair(21, -37), Pair(36, -78)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-15, -33), Pair(-5, -10), Pair(3, 16), Pair(7, 32), Pair(13, 37), Pair(16, 48), Pair(22, 49), Pair(20, 49),
  Pair(30, 27)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-39, -45), Pair(-31, -33), Pair(-22, -2), Pair(-16, 15), Pair(-10, 33), Pair(-9, 49), Pair(-3, 46), Pair(-4, 56),
  Pair(-3, 60), Pair(3, 53), Pair(10, 46), Pair(25, 37), Pair(13, 43), Pair(25, 15)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-38, -55), Pair(-29, -31), Pair(-26, -23), Pair(-23, -18), Pair(-24, -13), Pair(-19, -9), Pair(-17, -4), Pair(-11, 2),
  Pair(-13, 7), Pair(-2, 1), Pair(5, -2), Pair(19, -9), Pair(9, 0), Pair(15, -6), Pair(-7, -1)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-10, -261), Pair(-14, -153), Pair(-17, -86), Pair(-13, -56), Pair(-12, -30), Pair(-10, -21), Pair(-5, -22), Pair(-5, 0),
  Pair(-2, 5), Pair(2, 5), Pair(1, 16), Pair(7, 14), Pair(7, 26), Pair(1, 47), Pair(13, 29), Pair(3, 56),
  Pair(-10, 83), Pair(24, 37), Pair(6, 65), Pair(44, 28), Pair(36, 41), Pair(81, 16), Pair(72, 24), Pair(94, 6),
  Pair(209, -42), Pair(219, -78), Pair(150, -26), Pair(104, -21)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-18, 6), Pair(-11, 10), Pair(-2, 33), Pair(13, 65), Pair(26, 107), Pair(11, 40), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(4, -11), Pair(2, -9), Pair(17, 10), Pair(33, 59), Pair(118, 186), Pair(-69, 432), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-43, -24), Pair(-9, -33), Pair(6, -52), Pair(-5, -25), Pair(-16, -5), Pair(-17, -22), Pair(-4, -35), Pair(-34, -51)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(7, -2), Pair(-11, -15), Pair(-24, -4), Pair(-14, -19), Pair(-24, -14), Pair(-18, -3), Pair(-24, -8), Pair(8, -6)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(14, 28), Pair(22, 12), Pair(15, 29), Pair(13, 28), Pair(16, 33), Pair(25, 20), Pair(23, 28), Pair(62, 33)
  },
  {
      Pair(29, 27), Pair(14, 14), Pair(2, 29), Pair(17, 7), Pair(14, 13), Pair(7, 21), Pair(45, -17), Pair(48, 20)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(12, 3), Pair(12, 17), Pair(1, 13),
  Pair(17, 4), Pair(13, 24), Pair(15, 4),
  Pair(8, 16), Pair(0, 0), Pair(10, 14),
  Pair(-16, 8), Pair(-4, 19), Pair(-3, 7)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-10, 5), Pair(-15, 10), Pair(-13, 10),
  Pair(-7, 2), Pair(-16, 13), Pair(-13, 7),
  Pair(-5, -3), Pair(-12, 2), Pair(-6, 1),
  Pair(1, 6), Pair(-12, 8), Pair(4, 4),
  Pair(4, 3), Pair(4, 15), Pair(10, -2),
  Pair(0, 0), Pair(-54, -29), Pair(0, 0),
  Pair(-6, -45), Pair(0, 0), Pair(-20, -39)
};

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-8, -42), Pair(-40, -21), Pair(-30, -7), Pair(-5, -14), Pair(-16, -6), Pair(-39, 6), Pair(-44, 1), Pair(-25, 3)
  },
  {
      Pair(-19, 59), Pair(-31, 25), Pair(-22, 33), Pair(29, -15), Pair(-5, 5), Pair(-8, 18), Pair(-22, 18), Pair(-24, 61)
  }
}};

constexpr ScorePair kBishopPairBonus = Pair(24, 40);
constexpr ScorePair kTempoBonus = Pair(16, 33);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_EVALUATION_TERMS_H