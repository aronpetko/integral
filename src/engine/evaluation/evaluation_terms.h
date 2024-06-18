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
  Pair(83, 159), Pair(295, 322), Pair(352, 346), Pair(416, 698), Pair(862, 1283), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(46, 145), Pair(50, 135), Pair(32, 135), Pair(62, 84), Pair(44, 85), Pair(31, 99), Pair(-20, 147), Pair(-33, 149),
      Pair(3, 3), Pair(-8, 17), Pair(26, -29), Pair(28, -66), Pair(35, -70), Pair(66, -51), Pair(20, 2), Pair(2, -10),
      Pair(-19, -18), Pair(-17, -17), Pair(-9, -39), Pair(-4, -59), Pair(17, -61), Pair(12, -55), Pair(-5, -21), Pair(-6, -41),
      Pair(-26, -37), Pair(-27, -26), Pair(-16, -47), Pair(0, -56), Pair(1, -57), Pair(5, -56), Pair(-10, -33), Pair(-9, -55),
      Pair(-25, -42), Pair(-21, -32), Pair(-14, -48), Pair(-9, -48), Pair(3, -48), Pair(-1, -53), Pair(2, -38), Pair(-6, -59),
      Pair(-25, -37), Pair(-21, -25), Pair(-18, -39), Pair(-20, -45), Pair(-6, -36), Pair(7, -48), Pair(10, -35), Pair(-18, -56),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-137, -48), Pair(-114, -1), Pair(-59, 13), Pair(-23, 0), Pair(5, 4), Pair(-54, -19), Pair(-97, -2), Pair(-96, -67),
      Pair(-15, 4), Pair(6, 15), Pair(32, 10), Pair(49, 7), Pair(24, 1), Pair(85, -11), Pair(2, 10), Pair(23, -17),
      Pair(3, 7), Pair(31, 14), Pair(41, 36), Pair(53, 35), Pair(88, 20), Pair(90, 11), Pair(51, 5), Pair(25, -3),
      Pair(6, 23), Pair(10, 32), Pair(30, 44), Pair(53, 45), Pair(33, 44), Pair(54, 42), Pair(17, 31), Pair(39, 11),
      Pair(-6, 25), Pair(3, 24), Pair(14, 45), Pair(19, 44), Pair(27, 47), Pair(23, 35), Pair(32, 22), Pair(7, 19),
      Pair(-27, 9), Pair(-8, 17), Pair(0, 23), Pair(10, 38), Pair(26, 34), Pair(11, 16), Pair(14, 10), Pair(-5, 12),
      Pair(-32, 8), Pair(-19, 16), Pair(-7, 17), Pair(8, 14), Pair(10, 13), Pair(10, 11), Pair(5, 4), Pair(-1, 16),
      Pair(-64, 12), Pair(-25, 2), Pair(-25, 12), Pair(-10, 16), Pair(-4, 15), Pair(5, 1), Pair(-19, 5), Pair(-33, 6)
  },
  {
      Pair(-43, 21), Pair(-67, 25), Pair(-61, 18), Pair(-101, 27), Pair(-87, 24), Pair(-83, 14), Pair(-45, 14), Pair(-62, 9),
      Pair(-22, 4), Pair(-4, 14), Pair(-13, 15), Pair(-27, 19), Pair(1, 8), Pair(-8, 13), Pair(-11, 17), Pair(-28, 6),
      Pair(-16, 22), Pair(2, 18), Pair(0, 25), Pair(17, 13), Pair(7, 18), Pair(37, 25), Pair(17, 18), Pair(8, 19),
      Pair(-24, 18), Pair(-9, 27), Pair(5, 24), Pair(23, 38), Pair(17, 30), Pair(7, 30), Pair(-7, 22), Pair(-20, 18),
      Pair(-18, 15), Pair(-18, 27), Pair(-9, 33), Pair(16, 34), Pair(13, 32), Pair(-14, 29), Pair(-14, 22), Pair(-3, 4),
      Pair(-15, 15), Pair(2, 27), Pair(-2, 27), Pair(-3, 30), Pair(0, 34), Pair(2, 26), Pair(2, 18), Pair(3, 7),
      Pair(-3, 20), Pair(-2, 7), Pair(7, 9), Pair(-11, 19), Pair(-1, 16), Pair(10, 11), Pair(17, 11), Pair(4, 1),
      Pair(-15, 9), Pair(8, 23), Pair(-15, 12), Pair(-20, 17), Pair(-12, 15), Pair(-13, 20), Pair(2, 5), Pair(6, -13)
  },
  {
      Pair(13, 3), Pair(6, 15), Pair(8, 14), Pair(6, 11), Pair(16, 0), Pair(31, 8), Pair(22, 9), Pair(4, 7),
      Pair(4, 5), Pair(7, 22), Pair(25, 17), Pair(38, 7), Pair(24, 5), Pair(48, 6), Pair(36, 4), Pair(23, -2),
      Pair(-9, 4), Pair(20, 9), Pair(19, 4), Pair(18, 1), Pair(46, -13), Pair(55, -9), Pair(77, -12), Pair(27, -17),
      Pair(-12, 6), Pair(1, 10), Pair(5, 10), Pair(9, 5), Pair(12, -10), Pair(16, -3), Pair(16, -2), Pair(-1, -10),
      Pair(-20, -4), Pair(-20, 8), Pair(-8, 1), Pair(-4, 0), Pair(-3, -6), Pair(-15, 4), Pair(6, -7), Pair(-10, -16),
      Pair(-23, -9), Pair(-18, -3), Pair(-11, -8), Pair(-12, -4), Pair(0, -14), Pair(0, -12), Pair(27, -31), Pair(4, -35),
      Pair(-22, -16), Pair(-15, -7), Pair(-1, -10), Pair(0, -11), Pair(6, -21), Pair(11, -18), Pair(17, -28), Pair(-19, -30),
      Pair(-8, -11), Pair(-3, -10), Pair(4, -7), Pair(9, -14), Pair(14, -21), Pair(15, -17), Pair(4, -19), Pair(-5, -29)
  },
  {
      Pair(-47, -6), Pair(-53, 12), Pair(-36, 33), Pair(2, 13), Pair(1, 14), Pair(12, 12), Pair(54, -47), Pair(-11, -2),
      Pair(-7, -26), Pair(-30, 10), Pair(-29, 41), Pair(-41, 65), Pair(-35, 80), Pair(6, 39), Pair(7, 18), Pair(44, 6),
      Pair(-7, -15), Pair(-11, -2), Pair(-15, 32), Pair(-5, 41), Pair(-2, 58), Pair(46, 37), Pair(51, 8), Pair(46, 6),
      Pair(-17, -10), Pair(-17, 10), Pair(-13, 18), Pair(-15, 41), Pair(-15, 57), Pair(-2, 48), Pair(4, 43), Pair(7, 30),
      Pair(-15, -15), Pair(-19, 10), Pair(-15, 13), Pair(-10, 33), Pair(-8, 32), Pair(-11, 34), Pair(-2, 24), Pair(6, 19),
      Pair(-11, -32), Pair(-8, -12), Pair(-8, 1), Pair(-12, 6), Pair(-7, 13), Pair(-2, 14), Pair(10, 0), Pair(6, -10),
      Pair(-7, -40), Pair(-4, -37), Pair(2, -35), Pair(8, -31), Pair(4, -19), Pair(14, -39), Pair(17, -58), Pair(20, -77),
      Pair(-14, -36), Pair(-8, -36), Pair(-2, -33), Pair(0, -23), Pair(2, -33), Pair(-3, -36), Pair(5, -57), Pair(1, -60)
  },
  {
      Pair(75, -92), Pair(109, -49), Pair(89, -29), Pair(-50, 15), Pair(-26, -3), Pair(4, -6), Pair(73, -23), Pair(181, -128),
      Pair(-57, 3), Pair(26, 26), Pair(-30, 42), Pair(56, 28), Pair(-8, 39), Pair(-1, 50), Pair(26, 33), Pair(-25, 7),
      Pair(-84, 12), Pair(66, 22), Pair(-19, 49), Pair(-41, 62), Pair(-19, 60), Pair(56, 40), Pair(-1, 39), Pair(-47, 10),
      Pair(-57, -1), Pair(-15, 20), Pair(-66, 49), Pair(-110, 65), Pair(-117, 59), Pair(-81, 47), Pair(-78, 27), Pair(-129, 11),
      Pair(-54, -15), Pair(-23, 9), Pair(-89, 42), Pair(-123, 61), Pair(-132, 56), Pair(-84, 34), Pair(-80, 14), Pair(-125, 0),
      Pair(-21, -23), Pair(10, -2), Pair(-60, 28), Pair(-81, 44), Pair(-81, 40), Pair(-73, 24), Pair(-33, 0), Pair(-42, -19),
      Pair(42, -39), Pair(-5, -5), Pair(-17, 10), Pair(-42, 22), Pair(-51, 22), Pair(-34, 9), Pair(-9, -11), Pair(25, -40),
      Pair(38, -74), Pair(42, -43), Pair(36, -29), Pair(-36, -3), Pair(13, -29), Pair(-25, -13), Pair(27, -40), Pair(49, -83)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-24, 3), Pair(-11, 7), Pair(-1, 26), Pair(4, 36), Pair(9, 43), Pair(15, 50), Pair(21, 49), Pair(27, 45),
  Pair(34, 33)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-55, -15), Pair(-45, -15), Pair(-35, 1), Pair(-28, 15), Pair(-19, 24), Pair(-15, 34), Pair(-11, 38), Pair(-8, 40),
  Pair(-7, 42), Pair(-2, 39), Pair(5, 33), Pair(11, 31), Pair(12, 39), Pair(21, 17)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-35, -58), Pair(-29, -30), Pair(-26, -25), Pair(-24, -19), Pair(-25, -13), Pair(-21, -7), Pair(-19, -1), Pair(-17, 0),
  Pair(-12, 3), Pair(-9, 7), Pair(-6, 8), Pair(-6, 12), Pair(-2, 13), Pair(2, 9), Pair(-5, 9)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-1, -265), Pair(0, -250), Pair(-11, -110), Pair(-9, -64), Pair(-8, -40), Pair(-5, -27), Pair(-2, -8), Pair(-2, 6),
  Pair(1, 15), Pair(4, 18), Pair(5, 25), Pair(8, 31), Pair(10, 33), Pair(10, 41), Pair(12, 44), Pair(15, 49),
  Pair(15, 56), Pair(15, 58), Pair(24, 57), Pair(37, 49), Pair(40, 53), Pair(88, 24), Pair(75, 35), Pair(97, 13),
  Pair(210, -30), Pair(227, -61), Pair(164, -8), Pair(118, -6)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-5, 1), Pair(-12, 9), Pair(-9, 35), Pair(11, 62), Pair(8, 123), Pair(27, 37), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(-1, -7), Pair(-1, 0), Pair(18, 9), Pair(43, 47), Pair(112, 182), Pair(-122, 443), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-13, -43), Pair(5, -34), Pair(-4, -28), Pair(-3, -18), Pair(-12, -10), Pair(-11, -26), Pair(3, -40), Pair(-10, -53)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-8, 3), Pair(-6, -15), Pair(-17, -11), Pair(-15, -19), Pair(-19, -20), Pair(-9, -10), Pair(-7, -16), Pair(-7, 5)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(27, 11), Pair(25, 3), Pair(22, 12), Pair(26, 11), Pair(28, 17), Pair(45, 2), Pair(57, 0), Pair(91, -2)
  },
  {
      Pair(3, 45), Pair(7, 17), Pair(6, 19), Pair(15, 9), Pair(11, 11), Pair(15, 5), Pair(28, 4), Pair(19, 28)
  }
}};

constexpr PieceTable<ScorePair> kKingZoneSafetyBonus = {
  Pair(0, 0), Pair(2, 4), Pair(3, 2), Pair(7, -7), Pair(4, -16), Pair(0, 0)
};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(19, -1), Pair(18, 7), Pair(16, 3),
  Pair(29, -6), Pair(26, 2), Pair(29, -7),
  Pair(39, 0), Pair(0, 0), Pair(36, 1),
  Pair(-20, 4), Pair(-11, 12), Pair(-19, 5)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-13, 8), Pair(-17, 13), Pair(-13, 9),
  Pair(-11, 8), Pair(-18, 15), Pair(-13, 11),
  Pair(-7, 2), Pair(-15, 11), Pair(-6, 3),
  Pair(6, 0), Pair(-12, 8), Pair(6, 2),
  Pair(20, -5), Pair(13, 8), Pair(14, -5),
  Pair(0, 0), Pair(-72, -23), Pair(0, 0),
  Pair(-12, -48), Pair(0, 0), Pair(-15, -45)
};

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-81, -13), Pair(-113, 4), Pair(-61, -4), Pair(-57, -2), Pair(-40, 2), Pair(-76, 11), Pair(-72, 13), Pair(-48, 8)
  },
  {
      Pair(-30, 68), Pair(-62, 38), Pair(-28, 27), Pair(-11, 10), Pair(-9, 6), Pair(-25, 18), Pair(-42, 36), Pair(-29, 50)
  }
}};

constexpr ScorePair kBishopPairBonus = Pair(22, 65);
constexpr ScorePair kTempoBonus = Pair(20, 25);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_EVALUATION_TERMS_H