#ifndef INTEGRAL_TERMS_H
#define INTEGRAL_TERMS_H

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
  Pair(77, 182), Pair(293, 291), Pair(346, 346), Pair(412, 699), Pair(860, 1257), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(51, 132), Pair(35, 135), Pair(21, 136), Pair(64, 92), Pair(53, 95), Pair(50, 106), Pair(-17, 150), Pair(-16, 146),
      Pair(4, -40), Pair(-14, -18), Pair(17, -63), Pair(25, -94), Pair(39, -96), Pair(64, -83), Pair(20, -35), Pair(4, -44),
      Pair(-20, -51), Pair(-22, -43), Pair(-14, -70), Pair(-10, -86), Pair(12, -87), Pair(6, -82), Pair(-10, -52), Pair(-10, -68),
      Pair(-26, -66), Pair(-30, -46), Pair(-18, -74), Pair(-5, -81), Pair(-2, -82), Pair(1, -81), Pair(-14, -57), Pair(-14, -79),
      Pair(-35, -70), Pair(-40, -53), Pair(-27, -74), Pair(-23, -74), Pair(-14, -75), Pair(-18, -77), Pair(-17, -64), Pair(-19, -84),
      Pair(-27, -64), Pair(-31, -46), Pair(-22, -66), Pair(-22, -73), Pair(-15, -63), Pair(1, -72), Pair(-2, -61), Pair(-21, -81),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-126, -28), Pair(-92, 13), Pair(-48, 31), Pair(-15, 14), Pair(-1, 20), Pair(-45, -3), Pair(-84, 13), Pair(-89, -48),
      Pair(-15, 23), Pair(2, 36), Pair(10, 36), Pair(20, 34), Pair(12, 25), Pair(48, 17), Pair(11, 27), Pair(11, 3),
      Pair(9, 26), Pair(19, 37), Pair(32, 52), Pair(28, 48), Pair(37, 43), Pair(71, 21), Pair(15, 31), Pair(32, 9),
      Pair(20, 36), Pair(24, 40), Pair(38, 52), Pair(61, 50), Pair(35, 51), Pair(55, 50), Pair(22, 39), Pair(46, 22),
      Pair(9, 39), Pair(24, 39), Pair(34, 57), Pair(38, 56), Pair(41, 60), Pair(48, 42), Pair(44, 36), Pair(23, 33),
      Pair(-12, 27), Pair(9, 34), Pair(17, 43), Pair(28, 57), Pair(41, 53), Pair(25, 37), Pair(29, 29), Pair(12, 30),
      Pair(-16, 26), Pair(-4, 35), Pair(7, 38), Pair(22, 38), Pair(24, 36), Pair(21, 35), Pair(18, 26), Pair(14, 37),
      Pair(-48, 28), Pair(-12, 23), Pair(-11, 33), Pair(3, 39), Pair(10, 38), Pair(15, 27), Pair(-8, 29), Pair(-11, 22)
  },
  {
      Pair(-47, 35), Pair(-68, 35), Pair(-69, 29), Pair(-103, 36), Pair(-103, 35), Pair(-97, 25), Pair(-53, 26), Pair(-80, 23),
      Pair(-35, 18), Pair(-27, 29), Pair(-28, 26), Pair(-38, 30), Pair(-41, 26), Pair(-28, 25), Pair(-54, 34), Pair(-47, 20),
      Pair(-21, 33), Pair(-12, 29), Pair(-19, 35), Pair(-17, 27), Pair(-23, 32), Pair(14, 35), Pair(0, 32), Pair(-7, 34),
      Pair(-33, 32), Pair(-22, 35), Pair(-16, 35), Pair(-1, 41), Pair(-5, 35), Pair(-8, 38), Pair(-25, 32), Pair(-31, 31),
      Pair(-26, 26), Pair(-35, 37), Pair(-18, 37), Pair(-1, 35), Pair(-1, 31), Pair(-20, 36), Pair(-23, 35), Pair(-12, 16),
      Pair(-32, 27), Pair(-10, 35), Pair(-11, 37), Pair(-12, 42), Pair(-9, 45), Pair(-7, 37), Pair(-7, 29), Pair(-10, 18),
      Pair(-16, 29), Pair(-12, 17), Pair(-3, 20), Pair(-18, 33), Pair(-8, 32), Pair(1, 25), Pair(10, 22), Pair(-4, 11),
      Pair(-26, 16), Pair(-6, 35), Pair(-27, 27), Pair(-27, 31), Pair(-19, 28), Pair(-26, 37), Pair(-14, 20), Pair(2, -4)
  },
  {
      Pair(-15, 3), Pair(-15, 13), Pair(-12, 16), Pair(-17, 14), Pair(-9, 4), Pair(13, 6), Pair(2, 7), Pair(-14, 3),
      Pair(-12, -3), Pair(-9, 9), Pair(3, 7), Pair(20, -3), Pair(5, -6), Pair(22, -4), Pair(23, -9), Pair(6, -11),
      Pair(-15, -3), Pair(12, -1), Pair(9, -1), Pair(8, -5), Pair(34, -18), Pair(47, -20), Pair(64, -22), Pair(16, -24),
      Pair(-16, -1), Pair(-3, 0), Pair(0, 2), Pair(2, -1), Pair(9, -18), Pair(12, -16), Pair(13, -15), Pair(-5, -19),
      Pair(-22, -9), Pair(-21, 1), Pair(-10, -4), Pair(-4, -4), Pair(0, -13), Pair(-19, -5), Pair(4, -18), Pair(-15, -24),
      Pair(-23, -15), Pair(-18, -9), Pair(-10, -12), Pair(-10, -9), Pair(1, -19), Pair(-2, -20), Pair(22, -37), Pair(0, -41),
      Pair(-22, -22), Pair(-14, -13), Pair(-1, -14), Pair(0, -15), Pair(6, -26), Pair(7, -25), Pair(15, -35), Pair(-17, -37),
      Pair(-10, -18), Pair(-4, -16), Pair(2, -12), Pair(7, -17), Pair(14, -26), Pair(7, -20), Pair(2, -25), Pair(-6, -36)
  },
  {
      Pair(-40, -9), Pair(-44, 2), Pair(-27, 19), Pair(-8, 5), Pair(-17, 10), Pair(-12, 14), Pair(39, -43), Pair(-15, -11),
      Pair(-4, -18), Pair(-16, 10), Pair(-22, 44), Pair(-31, 59), Pair(-50, 79), Pair(-6, 30), Pair(-3, 21), Pair(40, -2),
      Pair(-1, -7), Pair(-3, 8), Pair(-3, 39), Pair(-3, 42), Pair(-8, 54), Pair(22, 29), Pair(24, 7), Pair(14, -3),
      Pair(-12, 4), Pair(-5, 20), Pair(-4, 27), Pair(-9, 48), Pair(-6, 47), Pair(2, 29), Pair(10, 24), Pair(6, 4),
      Pair(-7, -5), Pair(-12, 24), Pair(-6, 21), Pair(-1, 36), Pair(4, 33), Pair(-4, 24), Pair(10, 9), Pair(7, -2),
      Pair(-6, -21), Pair(-2, 0), Pair(-1, 10), Pair(-4, 16), Pair(1, 21), Pair(3, 14), Pair(17, -7), Pair(11, -22),
      Pair(0, -33), Pair(1, -28), Pair(7, -22), Pair(11, -16), Pair(10, -10), Pair(20, -37), Pair(23, -56), Pair(27, -80),
      Pair(-9, -32), Pair(-2, -32), Pair(-1, -19), Pair(1, -10), Pair(7, -27), Pair(-3, -37), Pair(1, -49), Pair(5, -58)
  },
  {
      Pair(68, -100), Pair(90, -57), Pair(55, -36), Pair(-64, 2), Pair(-48, -12), Pair(-66, 0), Pair(12, -19), Pair(136, -127),
      Pair(-79, -4), Pair(-3, 20), Pair(-39, 26), Pair(56, 7), Pair(-19, 22), Pair(-33, 41), Pair(-15, 31), Pair(-66, 5),
      Pair(-89, -1), Pair(61, 8), Pair(-16, 25), Pair(-51, 38), Pair(-24, 37), Pair(47, 22), Pair(-19, 27), Pair(-52, -4),
      Pair(-53, -19), Pair(-1, -3), Pair(-54, 20), Pair(-105, 36), Pair(-110, 32), Pair(-75, 23), Pair(-52, 3), Pair(-138, -3),
      Pair(-49, -36), Pair(-7, -15), Pair(-62, 12), Pair(-103, 30), Pair(-103, 25), Pair(-59, 5), Pair(-52, -11), Pair(-125, -17),
      Pair(-19, -40), Pair(26, -24), Pair(-32, 0), Pair(-47, 15), Pair(-47, 11), Pair(-40, -2), Pair(-8, -23), Pair(-40, -34),
      Pair(41, -51), Pair(12, -21), Pair(4, -10), Pair(-17, 0), Pair(-23, 1), Pair(-11, -11), Pair(12, -28), Pair(26, -51),
      Pair(28, -79), Pair(45, -51), Pair(31, -35), Pair(-30, -14), Pair(13, -39), Pair(-19, -23), Pair(28, -48), Pair(39, -87)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-35, 23), Pair(-21, 23), Pair(-11, 43), Pair(-5, 51), Pair(1, 57), Pair(6, 64), Pair(13, 63), Pair(18, 60),
  Pair(21, 51)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-34, -18), Pair(-24, -21), Pair(-16, -5), Pair(-10, 6), Pair(-4, 14), Pair(-1, 23), Pair(1, 27), Pair(2, 31),
  Pair(3, 34), Pair(7, 33), Pair(15, 30), Pair(21, 31), Pair(17, 44), Pair(27, 26)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-24, -53), Pair(-16, -25), Pair(-13, -20), Pair(-11, -15), Pair(-13, -7), Pair(-9, -4), Pair(-9, 2), Pair(-8, 4),
  Pair(-7, 8), Pair(-5, 11), Pair(-1, 13), Pair(-2, 18), Pair(1, 19), Pair(3, 17), Pair(-2, 17)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-1, -225), Pair(1, -210), Pair(-8, -87), Pair(-6, -45), Pair(-5, -22), Pair(-2, -10), Pair(0, 7), Pair(1, 18),
  Pair(3, 25), Pair(5, 27), Pair(7, 33), Pair(9, 37), Pair(11, 38), Pair(11, 43), Pair(13, 43), Pair(15, 45),
  Pair(14, 52), Pair(16, 50), Pair(24, 44), Pair(36, 34), Pair(39, 32), Pair(85, 3), Pair(70, 9), Pair(88, -13),
  Pair(185, -52), Pair(206, -90), Pair(155, -51), Pair(108, -44)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(1, 9), Pair(-1, 24), Pair(0, 56), Pair(27, 92), Pair(23, 159), Pair(32, 48), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(6, 0), Pair(15, 7), Pair(22, 18), Pair(47, 61), Pair(116, 193), Pair(-208, 471), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(21, 10), Pair(15, 6), Pair(15, 13), Pair(22, 42), Pair(134, 37), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-9, -47), Pair(11, -37), Pair(2, -26), Pair(-1, -14), Pair(-9, -5), Pair(-9, -20), Pair(6, -33), Pair(-3, -50)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-8, 13), Pair(-1, -11), Pair(-11, -4), Pair(-8, -12), Pair(-11, -14), Pair(-4, -6), Pair(1, -13), Pair(-5, 8)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(31, 8), Pair(25, 3), Pair(21, 9), Pair(23, 8), Pair(24, 13), Pair(37, 4), Pair(46, 4), Pair(73, 2)
  },
  {
      Pair(5, 28), Pair(8, 5), Pair(8, 4), Pair(16, -5), Pair(11, -2), Pair(16, -5), Pair(25, -2), Pair(14, 18)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(12, -6), Pair(17, -4), Pair(9, -3),
  Pair(25, -10), Pair(19, -8), Pair(24, -11),
  Pair(33, -2), Pair(0, 0), Pair(30, -2),
  Pair(-7, 5), Pair(-19, 4), Pair(-5, 7)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-7, 1), Pair(-14, 3), Pair(-9, 3),
  Pair(-6, 1), Pair(-15, 5), Pair(-9, 3),
  Pair(-1, -7), Pair(-12, 0), Pair(-1, -5),
  Pair(14, -9), Pair(-5, -5), Pair(12, -6),
  Pair(31, -9), Pair(23, 0), Pair(24, -9),
  Pair(0, 0), Pair(1, -31), Pair(0, 0),
  Pair(51, -50), Pair(0, 0), Pair(46, -47)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-20, 20), Pair(-25, 6), Pair(-17, -16), Pair(-14, -26), Pair(-9, -28), Pair(5, -30), Pair(-6, -33)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-73, -38), Pair(-2, -35), Pair(-1, -12), Pair(7, -5), Pair(8, 1), Pair(6, 6), Pair(-10, 2)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-113, 203);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-84, -10), Pair(-94, -3), Pair(-56, -7), Pair(-50, -5), Pair(-37, -1), Pair(-63, 4), Pair(-65, 5), Pair(-52, 8)
  },
  {
      Pair(-25, 51), Pair(-42, 21), Pair(-23, 14), Pair(-5, -3), Pair(-7, -5), Pair(-15, 7), Pair(-33, 24), Pair(-30, 38)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(17, 1), Pair(35, -9), Pair(86, -24), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(12, -3), Pair(30, -6), Pair(59, -17), Pair(64, -45), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(12, -22), Pair(32, -24), Pair(57, -20), Pair(92, -27), Pair(107, -41), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(3, 8), Pair(15, 22), Pair(39, 29), Pair(87, 16), Pair(126, 18), Pair(212, -25), Pair(285, -74)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByPawnPenalty = {
  Pair(-13, 15), Pair(-61, -22), Pair(-63, -53), Pair(-83, -7), Pair(-76, 35), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByKnightPenalty = {
  Pair(11, -15), Pair(11, 0), Pair(-32, -37), Pair(-68, -15), Pair(-54, 26), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByBishopPenalty = {
  Pair(0, -18), Pair(-19, -28), Pair(6, -27), Pair(-49, -24), Pair(-65, -52), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByRookPenalty = {
  Pair(0, -23), Pair(-15, -27), Pair(-19, -30), Pair(0, -32), Pair(-76, -11), Pair(0, 0)
};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(8, 23), Pair(13, 11), Pair(28, 19), Pair(37, 19), Pair(37, 26), Pair(20, 48), Pair(35, 16), Pair(-8, 36),
  Pair(-1, 13), Pair(11, 16), Pair(11, 20), Pair(2, 31), Pair(7, 20), Pair(3, 20), Pair(13, 16), Pair(-7, 25),
  Pair(7, 8), Pair(0, 2), Pair(-3, 14), Pair(2, 14), Pair(0, 20), Pair(-11, 17), Pair(-5, 7), Pair(-3, 7)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-15, 11), Pair(15, -1), Pair(19, 2), Pair(34, 0), Pair(56, -14), Pair(33, -2), Pair(19, -11), Pair(-18, -31),
  Pair(-23, -11), Pair(19, 5), Pair(7, 2), Pair(14, 12), Pair(8, 4), Pair(15, -2), Pair(13, 11), Pair(12, -23),
  Pair(-24, 28), Pair(6, 5), Pair(-1, 18), Pair(14, 12), Pair(18, 22), Pair(-1, 6), Pair(10, -1), Pair(-52, 8)
};

constexpr ScorePair kBishopPairBonus = Pair(20, 61);

constexpr ScorePair kTempoBonus = Pair(28, 27);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H