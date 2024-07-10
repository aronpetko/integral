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
  Pair(80, 183), Pair(289, 283), Pair(350, 346), Pair(411, 690), Pair(855, 1235), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(50, 131), Pair(36, 133), Pair(22, 135), Pair(65, 91), Pair(56, 94), Pair(51, 105), Pair(-17, 149), Pair(-18, 145),
      Pair(2, -40), Pair(-17, -19), Pair(17, -63), Pair(23, -94), Pair(42, -97), Pair(62, -83), Pair(18, -35), Pair(1, -45),
      Pair(-22, -52), Pair(-23, -45), Pair(-16, -70), Pair(-8, -87), Pair(11, -88), Pair(6, -83), Pair(-13, -52), Pair(-11, -70),
      Pair(-28, -67), Pair(-32, -47), Pair(-18, -75), Pair(-7, -83), Pair(-4, -83), Pair(-3, -82), Pair(-19, -57), Pair(-16, -80),
      Pair(-38, -71), Pair(-42, -54), Pair(-31, -75), Pair(-25, -76), Pair(-18, -76), Pair(-21, -79), Pair(-22, -65), Pair(-22, -85),
      Pair(-30, -65), Pair(-34, -49), Pair(-25, -68), Pair(-27, -74), Pair(-18, -63), Pair(-5, -74), Pair(-9, -62), Pair(-21, -83),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-122, -27), Pair(-89, 13), Pair(-52, 30), Pair(-8, 12), Pair(9, 17), Pair(-34, -5), Pair(-82, 13), Pair(-85, -48),
      Pair(-11, 23), Pair(6, 36), Pair(14, 35), Pair(27, 33), Pair(23, 23), Pair(58, 16), Pair(19, 26), Pair(12, 4),
      Pair(11, 26), Pair(24, 36), Pair(26, 52), Pair(38, 46), Pair(49, 41), Pair(79, 17), Pair(19, 29), Pair(34, 8),
      Pair(23, 36), Pair(22, 41), Pair(42, 51), Pair(53, 51), Pair(44, 49), Pair(52, 48), Pair(31, 37), Pair(48, 22),
      Pair(12, 39), Pair(26, 40), Pair(36, 57), Pair(40, 56), Pair(41, 59), Pair(51, 41), Pair(40, 36), Pair(26, 32),
      Pair(-10, 28), Pair(12, 35), Pair(18, 44), Pair(31, 56), Pair(42, 53), Pair(27, 37), Pair(30, 29), Pair(13, 31),
      Pair(-15, 27), Pair(-2, 35), Pair(9, 39), Pair(22, 38), Pair(25, 36), Pair(18, 35), Pair(18, 24), Pair(15, 36),
      Pair(-46, 31), Pair(-10, 23), Pair(-9, 33), Pair(5, 39), Pair(12, 37), Pair(15, 24), Pair(-5, 29), Pair(-9, 23)
  },
  {
      Pair(-49, 33), Pair(-66, 34), Pair(-67, 27), Pair(-97, 34), Pair(-96, 33), Pair(-92, 23), Pair(-53, 26), Pair(-78, 22),
      Pair(-35, 16), Pair(-27, 28), Pair(-25, 25), Pair(-37, 29), Pair(-38, 25), Pair(-25, 23), Pair(-49, 32), Pair(-46, 18),
      Pair(-20, 31), Pair(-11, 28), Pair(-17, 34), Pair(-15, 26), Pair(-20, 30), Pair(17, 34), Pair(4, 30), Pair(-6, 31),
      Pair(-32, 30), Pair(-21, 33), Pair(-16, 34), Pair(0, 40), Pair(-4, 35), Pair(-9, 37), Pair(-24, 31), Pair(-30, 28),
      Pair(-26, 24), Pair(-34, 35), Pair(-19, 34), Pair(-2, 34), Pair(-2, 29), Pair(-19, 34), Pair(-27, 32), Pair(-12, 14),
      Pair(-31, 25), Pair(-11, 33), Pair(-11, 35), Pair(-12, 39), Pair(-12, 43), Pair(-8, 34), Pair(-7, 26), Pair(-13, 16),
      Pair(-17, 26), Pair(-12, 15), Pair(-3, 18), Pair(-20, 30), Pair(-9, 28), Pair(-4, 22), Pair(7, 19), Pair(-4, 8),
      Pair(-26, 14), Pair(-7, 33), Pair(-28, 26), Pair(-29, 28), Pair(-19, 24), Pair(-27, 32), Pair(-15, 18), Pair(1, -6)
  },
  {
      Pair(-12, 3), Pair(-10, 11), Pair(-4, 14), Pair(-10, 12), Pair(3, 1), Pair(20, 3), Pair(8, 6), Pair(-14, 3),
      Pair(-8, -3), Pair(-4, 9), Pair(9, 7), Pair(26, -4), Pair(11, -6), Pair(30, -4), Pair(26, -7), Pair(4, -9),
      Pair(-13, -3), Pair(15, -1), Pair(12, -2), Pair(9, -4), Pair(36, -17), Pair(47, -20), Pair(62, -20), Pair(11, -21),
      Pair(-14, -1), Pair(0, 1), Pair(2, 2), Pair(6, -2), Pair(10, -17), Pair(13, -16), Pair(13, -14), Pair(-7, -18),
      Pair(-19, -9), Pair(-19, 1), Pair(-8, -4), Pair(-3, -4), Pair(0, -12), Pair(-19, -5), Pair(4, -17), Pair(-15, -23),
      Pair(-22, -14), Pair(-16, -9), Pair(-9, -12), Pair(-8, -9), Pair(1, -18), Pair(-1, -20), Pair(22, -36), Pair(0, -40),
      Pair(-20, -21), Pair(-13, -12), Pair(0, -13), Pair(-1, -14), Pair(6, -25), Pair(3, -23), Pair(13, -33), Pair(-18, -36),
      Pair(-8, -17), Pair(-3, -16), Pair(3, -11), Pair(7, -17), Pair(14, -26), Pair(6, -21), Pair(1, -23), Pair(-7, -34)
  },
  {
      Pair(-42, -1), Pair(-41, -1), Pair(-30, 18), Pair(-5, 8), Pair(-18, 16), Pair(-15, 16), Pair(32, -42), Pair(-15, -5),
      Pair(-6, -18), Pair(-16, 2), Pair(-21, 37), Pair(-36, 51), Pair(-55, 76), Pair(-14, 36), Pair(-7, 15), Pair(30, -1),
      Pair(-2, -13), Pair(-3, -2), Pair(-8, 28), Pair(-4, 29), Pair(-8, 43), Pair(19, 22), Pair(19, -2), Pair(16, -5),
      Pair(-11, -5), Pair(-5, 13), Pair(-5, 24), Pair(-7, 39), Pair(-7, 38), Pair(2, 19), Pair(10, 15), Pair(7, -1),
      Pair(-5, -10), Pair(-11, 25), Pair(-6, 26), Pair(-2, 40), Pair(3, 30), Pair(-3, 20), Pair(10, 5), Pair(8, -4),
      Pair(-4, -21), Pair(0, 3), Pair(-1, 19), Pair(-3, 20), Pair(0, 22), Pair(5, 12), Pair(18, -8), Pair(11, -23),
      Pair(1, -27), Pair(4, -22), Pair(8, -17), Pair(12, -10), Pair(11, -8), Pair(18, -35), Pair(23, -56), Pair(30, -78),
      Pair(-9, -20), Pair(-1, -25), Pair(1, -15), Pair(3, -7), Pair(10, -31), Pair(-2, -38), Pair(3, -46), Pair(3, -45)
  },
  {
      Pair(76, -105), Pair(94, -63), Pair(65, -40), Pair(-49, -2), Pair(-31, -17), Pair(-75, -4), Pair(-6, -23), Pair(129, -132),
      Pair(-85, -7), Pair(-3, 16), Pair(-24, 21), Pair(69, 4), Pair(-6, 17), Pair(-32, 36), Pair(-27, 27), Pair(-87, 2),
      Pair(-77, -5), Pair(66, 5), Pair(10, 20), Pair(-29, 34), Pair(7, 31), Pair(64, 18), Pair(-23, 25), Pair(-48, -8),
      Pair(-42, -23), Pair(9, -6), Pair(-29, 15), Pair(-75, 32), Pair(-80, 27), Pair(-52, 19), Pair(-40, -1), Pair(-137, -5),
      Pair(-42, -39), Pair(6, -19), Pair(-41, 7), Pair(-83, 28), Pair(-80, 21), Pair(-44, 2), Pair(-43, -14), Pair(-118, -21),
      Pair(-23, -42), Pair(27, -26), Pair(-25, -2), Pair(-40, 13), Pair(-37, 8), Pair(-35, -3), Pair(-8, -25), Pair(-42, -37),
      Pair(33, -54), Pair(7, -22), Pair(3, -12), Pair(-19, -1), Pair(-23, -1), Pair(-13, -11), Pair(5, -30), Pair(20, -56),
      Pair(18, -80), Pair(35, -52), Pair(23, -35), Pair(-38, -13), Pair(5, -37), Pair(-25, -22), Pair(19, -48), Pair(26, -88)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-32, 27), Pair(-18, 28), Pair(-8, 47), Pair(-3, 54), Pair(3, 60), Pair(8, 66), Pair(15, 64), Pair(19, 60),
  Pair(22, 51)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-36, -19), Pair(-26, -21), Pair(-18, -6), Pair(-13, 4), Pair(-7, 12), Pair(-4, 20), Pair(-3, 23), Pair(-2, 27),
  Pair(0, 30), Pair(3, 28), Pair(11, 24), Pair(16, 25), Pair(13, 37), Pair(21, 19)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-22, -48), Pair(-15, -21), Pair(-12, -17), Pair(-9, -11), Pair(-12, -5), Pair(-8, -3), Pair(-8, 3), Pair(-7, 5),
  Pair(-6, 8), Pair(-5, 11), Pair(-2, 12), Pair(-4, 16), Pair(-2, 18), Pair(-1, 16), Pair(-4, 14)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(4, -213), Pair(5, -191), Pair(-4, -68), Pair(-3, -27), Pair(-2, -4), Pair(0, 8), Pair(2, 24), Pair(3, 35),
  Pair(5, 41), Pair(6, 42), Pair(7, 46), Pair(10, 50), Pair(11, 48), Pair(11, 50), Pair(13, 49), Pair(16, 48),
  Pair(15, 51), Pair(18, 45), Pair(27, 35), Pair(40, 20), Pair(43, 14), Pair(89, -21), Pair(77, -20), Pair(92, -45),
  Pair(172, -78), Pair(191, -121), Pair(136, -85), Pair(89, -80)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(1, 12), Pair(0, 26), Pair(2, 59), Pair(28, 94), Pair(26, 161), Pair(36, 49), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(7, 0), Pair(15, 7), Pair(21, 17), Pair(47, 60), Pair(123, 191), Pair(-216, 474), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(21, 10), Pair(14, 5), Pair(14, 13), Pair(23, 41), Pair(149, 33), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-9, -46), Pair(11, -36), Pair(1, -25), Pair(-2, -14), Pair(-10, -5), Pair(-9, -19), Pair(8, -32), Pair(-4, -49)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-7, 12), Pair(-2, -12), Pair(-11, -4), Pair(-8, -12), Pair(-11, -15), Pair(-4, -6), Pair(1, -13), Pair(-5, 8)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(31, 6), Pair(25, 2), Pair(21, 8), Pair(24, 7), Pair(24, 12), Pair(37, 3), Pair(46, 2), Pair(75, 0)
  },
  {
      Pair(6, 29), Pair(9, 6), Pair(9, 5), Pair(17, -4), Pair(11, -1), Pair(16, -5), Pair(24, -2), Pair(15, 17)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(13, -6), Pair(17, -5), Pair(9, -3),
  Pair(21, -11), Pair(17, -11), Pair(20, -12),
  Pair(30, -4), Pair(0, 0), Pair(28, -3),
  Pair(-10, 5), Pair(-15, 1), Pair(-9, 7)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-6, 1), Pair(-13, 3), Pair(-9, 3),
  Pair(-6, 1), Pair(-15, 4), Pair(-9, 3),
  Pair(-1, -7), Pair(-11, 0), Pair(-1, -5),
  Pair(12, -8), Pair(-4, -5), Pair(11, -6),
  Pair(14, -5), Pair(25, 0), Pair(8, -4),
  Pair(0, 0), Pair(6, -31), Pair(0, 0),
  Pair(58, -49), Pair(0, 0), Pair(50, -46)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-25, 22), Pair(-26, 6), Pair(-17, -15), Pair(-14, -25), Pair(-10, -26), Pair(2, -28), Pair(-10, -31)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-76, -40), Pair(-2, -38), Pair(-3, -15), Pair(5, -7), Pair(7, -2), Pair(8, 3), Pair(-6, 0)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-149, 201);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-54, -13), Pair(-71, -6), Pair(-40, -8), Pair(-28, -8), Pair(-24, -1), Pair(-41, 1), Pair(-54, 4), Pair(-37, 7)
  },
  {
      Pair(-18, 47), Pair(-39, 20), Pair(-23, 13), Pair(-3, -4), Pair(-7, -6), Pair(-12, 5), Pair(-33, 23), Pair(-24, 36)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(11, -1), Pair(28, -10), Pair(66, -34), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(13, -1), Pair(31, -4), Pair(60, -12), Pair(65, -41), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(13, -19), Pair(34, -22), Pair(56, -17), Pair(87, -21), Pair(100, -31), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(4, 10), Pair(16, 19), Pair(39, 22), Pair(81, 6), Pair(111, 4), Pair(169, -16), Pair(253, -79)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(18, -5), Pair(32, 14), Pair(31, 20), Pair(53, 1), Pair(30, 12), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByPawnPenalty = {
  Pair(-13, 16), Pair(-62, -22), Pair(-63, -52), Pair(-82, -6), Pair(-76, 31), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByKnightPenalty = {
  Pair(11, -15), Pair(14, -2), Pair(-28, -37), Pair(-67, -14), Pair(-51, 28), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByBishopPenalty = {
  Pair(0, -17), Pair(-18, -26), Pair(7, -27), Pair(-49, -23), Pair(-64, -53), Pair(0, 0)
};

constexpr PieceTable<ScorePair> kThreatenedByRookPenalty = {
  Pair(1, -22), Pair(-14, -26), Pair(-19, -30), Pair(12, -32), Pair(-79, -7), Pair(0, 0)
};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(11, 23), Pair(13, 11), Pair(27, 21), Pair(37, 19), Pair(38, 27), Pair(22, 45), Pair(39, 15), Pair(-5, 37),
  Pair(-2, 13), Pair(13, 15), Pair(10, 20), Pair(0, 33), Pair(6, 20), Pair(3, 22), Pair(12, 15), Pair(-7, 25),
  Pair(7, 7), Pair(1, 2), Pair(-3, 14), Pair(2, 14), Pair(1, 20), Pair(-11, 18), Pair(-3, 7), Pair(-2, 7)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-15, 12), Pair(14, -1), Pair(19, 1), Pair(34, 0), Pair(54, -14), Pair(33, -3), Pair(21, -11), Pair(-16, -30),
  Pair(-25, -10), Pair(19, 5), Pair(8, 2), Pair(13, 11), Pair(8, 3), Pair(14, -2), Pair(13, 11), Pair(16, -22),
  Pair(-25, 29), Pair(5, 4), Pair(-1, 18), Pair(14, 11), Pair(17, 21), Pair(-1, 6), Pair(10, 0), Pair(-52, 8)
};

constexpr ScorePair kBishopPairBonus = Pair(20, 59);

constexpr ScorePair kTempoBonus = Pair(28, 27);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H