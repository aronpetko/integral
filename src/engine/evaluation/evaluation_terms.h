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
  Pair(83, 171), Pair(296, 329), Pair(337, 355), Pair(405, 699), Pair(864, 1290), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(52, 144), Pair(43, 143), Pair(26, 147), Pair(58, 104), Pair(51, 105), Pair(38, 119), Pair(-9, 158), Pair(-22, 158),
      Pair(1, -13), Pair(-14, 7), Pair(24, -38), Pair(26, -68), Pair(38, -71), Pair(69, -58), Pair(22, -9), Pair(4, -19),
      Pair(-21, -29), Pair(-22, -22), Pair(-9, -48), Pair(-3, -66), Pair(18, -69), Pair(14, -63), Pair(-6, -32), Pair(-7, -49),
      Pair(-27, -47), Pair(-33, -29), Pair(-16, -55), Pair(1, -64), Pair(2, -66), Pair(6, -64), Pair(-12, -43), Pair(-9, -63),
      Pair(-26, -50), Pair(-28, -35), Pair(-13, -56), Pair(-9, -56), Pair(4, -57), Pair(-1, -61), Pair(1, -47), Pair(-5, -67),
      Pair(-25, -45), Pair(-28, -28), Pair(-17, -47), Pair(-19, -52), Pair(-6, -43), Pair(7, -55), Pair(9, -44), Pair(-17, -65),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-135, -37), Pair(-112, 11), Pair(-57, 25), Pair(-21, 12), Pair(10, 14), Pair(-50, -7), Pair(-93, 9), Pair(-93, -56),
      Pair(-11, 16), Pair(9, 26), Pair(35, 21), Pair(53, 18), Pair(27, 13), Pair(89, 0), Pair(5, 23), Pair(26, -6),
      Pair(5, 19), Pair(36, 23), Pair(40, 42), Pair(41, 41), Pair(85, 24), Pair(82, 10), Pair(50, 12), Pair(30, 5),
      Pair(10, 31), Pair(8, 38), Pair(26, 47), Pair(53, 43), Pair(31, 47), Pair(54, 46), Pair(18, 39), Pair(46, 19),
      Pair(-4, 34), Pair(5, 34), Pair(17, 50), Pair(22, 47), Pair(30, 53), Pair(33, 38), Pair(39, 30), Pair(13, 30),
      Pair(-23, 21), Pair(-3, 29), Pair(4, 34), Pair(14, 50), Pair(31, 47), Pair(14, 30), Pair(20, 24), Pair(0, 26),
      Pair(-28, 21), Pair(-15, 28), Pair(-3, 30), Pair(13, 28), Pair(14, 27), Pair(13, 26), Pair(8, 18), Pair(4, 31),
      Pair(-59, 24), Pair(-21, 15), Pair(-21, 26), Pair(-6, 31), Pair(1, 30), Pair(5, 19), Pair(-17, 21), Pair(-26, 18)
  },
  {
      Pair(-51, 32), Pair(-72, 33), Pair(-68, 27), Pair(-108, 35), Pair(-95, 34), Pair(-90, 21), Pair(-53, 23), Pair(-69, 17),
      Pair(-27, 11), Pair(-11, 22), Pair(-20, 22), Pair(-33, 28), Pair(-6, 16), Pair(-15, 20), Pair(-19, 23), Pair(-35, 14),
      Pair(-22, 30), Pair(-7, 25), Pair(-10, 32), Pair(0, 21), Pair(-18, 29), Pair(17, 33), Pair(6, 29), Pair(2, 28),
      Pair(-28, 26), Pair(-18, 31), Pair(-4, 31), Pair(5, 43), Pair(3, 36), Pair(-5, 37), Pair(-14, 23), Pair(-25, 28),
      Pair(-22, 21), Pair(-30, 32), Pair(-17, 36), Pair(2, 35), Pair(1, 31), Pair(-20, 32), Pair(-25, 31), Pair(-5, 11),
      Pair(-21, 22), Pair(-4, 34), Pair(-7, 35), Pair(-8, 38), Pair(-5, 42), Pair(-4, 34), Pair(-3, 26), Pair(-1, 15),
      Pair(-8, 29), Pair(-7, 15), Pair(2, 17), Pair(-17, 27), Pair(-6, 25), Pair(3, 21), Pair(14, 19), Pair(0, 10),
      Pair(-20, 16), Pair(3, 30), Pair(-21, 20), Pair(-25, 26), Pair(-17, 23), Pair(-21, 31), Pair(-7, 15), Pair(3, -5)
  },
  {
      Pair(8, 3), Pair(1, 15), Pair(4, 15), Pair(0, 11), Pair(11, 0), Pair(22, 9), Pair(14, 11), Pair(-3, 8),
      Pair(-1, 5), Pair(1, 22), Pair(19, 17), Pair(32, 7), Pair(18, 4), Pair(42, 6), Pair(31, 2), Pair(16, -3),
      Pair(-14, 4), Pair(14, 8), Pair(13, 4), Pair(11, 1), Pair(41, -14), Pair(48, -10), Pair(73, -14), Pair(22, -19),
      Pair(-17, 5), Pair(-4, 8), Pair(0, 9), Pair(4, 4), Pair(7, -12), Pair(11, -5), Pair(12, -5), Pair(-4, -13),
      Pair(-24, -5), Pair(-24, 6), Pair(-12, -1), Pair(-9, -1), Pair(-8, -8), Pair(-19, 2), Pair(4, -12), Pair(-13, -20),
      Pair(-27, -12), Pair(-21, -6), Pair(-14, -11), Pair(-15, -8), Pair(-3, -19), Pair(-3, -16), Pair(26, -36), Pair(1, -39),
      Pair(-26, -19), Pair(-19, -10), Pair(-4, -13), Pair(-4, -14), Pair(2, -24), Pair(6, -21), Pair(15, -32), Pair(-22, -34),
      Pair(-11, -15), Pair(-6, -14), Pair(1, -10), Pair(5, -17), Pair(11, -25), Pair(7, -17), Pair(1, -23), Pair(-7, -35)
  },
  {
      Pair(-47, -1), Pair(-52, 15), Pair(-34, 35), Pair(3, 19), Pair(3, 19), Pair(14, 16), Pair(54, -41), Pair(-14, 3),
      Pair(-8, -19), Pair(-31, 16), Pair(-29, 46), Pair(-42, 70), Pair(-35, 86), Pair(7, 43), Pair(6, 23), Pair(44, 9),
      Pair(-9, -10), Pair(-12, 4), Pair(-15, 37), Pair(-5, 44), Pair(0, 59), Pair(47, 39), Pair(52, 7), Pair(48, 6),
      Pair(-19, -3), Pair(-17, 14), Pair(-13, 24), Pair(-15, 45), Pair(-14, 60), Pair(0, 46), Pair(6, 41), Pair(9, 28),
      Pair(-16, -10), Pair(-20, 17), Pair(-15, 14), Pair(-10, 35), Pair(-7, 31), Pair(-9, 31), Pair(0, 21), Pair(8, 15),
      Pair(-11, -28), Pair(-8, -8), Pair(-8, 3), Pair(-11, 4), Pair(-5, 10), Pair(-1, 11), Pair(11, -5), Pair(7, -13),
      Pair(-6, -37), Pair(-4, -33), Pair(1, -31), Pair(8, -29), Pair(5, -23), Pair(14, -43), Pair(17, -61), Pair(21, -76),
      Pair(-13, -37), Pair(-7, -36), Pair(-3, -33), Pair(0, -24), Pair(4, -38), Pair(-6, -37), Pair(1, -54), Pair(1, -60)
  },
  {
      Pair(91, -85), Pair(124, -44), Pair(86, -23), Pair(-48, 18), Pair(-27, 1), Pair(-3, 3), Pair(69, -13), Pair(167, -115),
      Pair(-41, 5), Pair(30, 27), Pair(-26, 38), Pair(58, 22), Pair(-11, 34), Pair(-5, 49), Pair(28, 36), Pair(-29, 12),
      Pair(-65, 8), Pair(78, 17), Pair(-22, 40), Pair(-51, 52), Pair(-30, 52), Pair(55, 33), Pair(4, 35), Pair(-39, 7),
      Pair(-34, -11), Pair(2, 8), Pair(-67, 36), Pair(-120, 52), Pair(-128, 48), Pair(-79, 37), Pair(-63, 18), Pair(-116, 5),
      Pair(-40, -25), Pair(-14, -2), Pair(-87, 30), Pair(-126, 49), Pair(-133, 45), Pair(-80, 23), Pair(-73, 6), Pair(-118, -5),
      Pair(-17, -26), Pair(12, -8), Pair(-57, 19), Pair(-75, 34), Pair(-77, 31), Pair(-69, 17), Pair(-32, -5), Pair(-42, -19),
      Pair(43, -36), Pair(-3, -4), Pair(-10, 6), Pair(-32, 17), Pair(-43, 18), Pair(-27, 6), Pair(-5, -12), Pair(27, -36),
      Pair(35, -61), Pair(43, -35), Pair(37, -23), Pair(-30, 0), Pair(20, -28), Pair(-21, -8), Pair(27, -33), Pair(49, -73)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-29, -11), Pair(-16, -6), Pair(-6, 14), Pair(0, 23), Pair(6, 31), Pair(12, 40), Pair(19, 38), Pair(25, 36),
  Pair(31, 26)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-35, -26), Pair(-24, -25), Pair(-14, -8), Pair(-6, 5), Pair(2, 15), Pair(7, 25), Pair(11, 29), Pair(15, 31),
  Pair(17, 34), Pair(23, 31), Pair(34, 26), Pair(42, 25), Pair(45, 37), Pair(53, 14)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-19, -49), Pair(-12, -21), Pair(-9, -17), Pair(-5, -12), Pair(-8, -4), Pair(-2, 1), Pair(-1, 6), Pair(2, 8),
  Pair(6, 11), Pair(9, 15), Pair(12, 16), Pair(12, 20), Pair(17, 21), Pair(20, 17), Pair(14, 16)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-4, -253), Pair(-2, -247), Pair(-12, -107), Pair(-10, -61), Pair(-9, -37), Pair(-5, -25), Pair(-3, -7), Pair(-2, 7),
  Pair(1, 14), Pair(4, 17), Pair(5, 24), Pair(8, 30), Pair(10, 32), Pair(10, 40), Pair(12, 42), Pair(15, 46),
  Pair(15, 54), Pair(16, 56), Pair(25, 53), Pair(37, 46), Pair(40, 48), Pair(89, 19), Pair(75, 30), Pair(98, 8),
  Pair(206, -33), Pair(212, -59), Pair(115, 8), Pair(79, 8)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-7, -17), Pair(-14, -1), Pair(-12, 35), Pair(11, 72), Pair(6, 140), Pair(13, 37), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(0, -7), Pair(-1, 0), Pair(17, 10), Pair(43, 47), Pair(116, 178), Pair(-80, 430), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-8, -48), Pair(10, -39), Pair(-5, -28), Pair(-4, -16), Pair(-12, -8), Pair(-13, -22), Pair(4, -34), Pair(-8, -51)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-15, 8), Pair(-7, -16), Pair(-17, -11), Pair(-15, -20), Pair(-19, -20), Pair(-9, -11), Pair(-7, -16), Pair(-9, 3)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(27, 11), Pair(25, 4), Pair(22, 11), Pair(28, 10), Pair(29, 16), Pair(49, -1), Pair(57, 0), Pair(90, -2)
  },
  {
      Pair(2, 47), Pair(7, 19), Pair(6, 19), Pair(16, 7), Pair(11, 11), Pair(19, 2), Pair(28, 5), Pair(18, 30)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(19, -6), Pair(20, -1), Pair(16, -2),
  Pair(30, -10), Pair(27, -6), Pair(28, -11),
  Pair(39, -2), Pair(0, 0), Pair(35, -1),
  Pair(-13, 5), Pair(-5, 3), Pair(-13, 7)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-12, 4), Pair(-15, 5), Pair(-12, 6),
  Pair(-10, 3), Pair(-17, 6), Pair(-12, 5),
  Pair(-5, -6), Pair(-13, 0), Pair(-5, -4),
  Pair(9, -8), Pair(-9, -3), Pair(8, -6),
  Pair(21, -7), Pair(15, 0), Pair(15, -7),
  Pair(0, 0), Pair(-13, -30), Pair(0, 0),
  Pair(33, -48), Pair(0, 0), Pair(27, -45)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-10, 23), Pair(-19, 9), Pair(-14, -12), Pair(-12, -23), Pair(-5, -26), Pair(14, -30), Pair(4, -31)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-55, -22), Pair(13, -21), Pair(12, 4), Pair(15, 13), Pair(11, 21), Pair(7, 27), Pair(-14, 26)
};

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-88, -6), Pair(-114, 4), Pair(-60, -4), Pair(-59, -1), Pair(-41, 2), Pair(-75, 9), Pair(-72, 9), Pair(-49, 9)
  },
  {
      Pair(-29, 57), Pair(-59, 28), Pair(-24, 17), Pair(-8, 0), Pair(-7, -4), Pair(-22, 11), Pair(-40, 28), Pair(-26, 40)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(8, 24), Pair(-7, 15), Pair(10, 24), Pair(30, 26), Pair(17, 35), Pair(22, 48), Pair(22, 23), Pair(-10, 42),
  Pair(-2, 20), Pair(14, 18), Pair(12, 22), Pair(4, 37), Pair(10, 25), Pair(9, 20), Pair(18, 14), Pair(-2, 28),
  Pair(8, 15), Pair(3, 6), Pair(0, 19), Pair(6, 21), Pair(3, 26), Pair(-7, 21), Pair(-2, 9), Pair(-1, 11)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-9, 12), Pair(12, -1), Pair(16, -1), Pair(29, 1), Pair(68, -17), Pair(45, -8), Pair(27, -16), Pair(-14, -27),
  Pair(-18, -5), Pair(22, 5), Pair(10, -1), Pair(24, 6), Pair(19, 1), Pair(31, -7), Pair(18, 13), Pair(24, -25),
  Pair(-23, 27), Pair(13, 3), Pair(8, 17), Pair(21, 13), Pair(27, 20), Pair(5, 8), Pair(18, -2), Pair(-44, 10)
};

constexpr ScorePair kBishopPairBonus = Pair(22, 65);

constexpr ScorePair kTempoBonus = Pair(21, 25);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_EVALUATION_TERMS_H