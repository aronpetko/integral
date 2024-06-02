#ifndef INTEGRAL_EVAL_TERMS_H
#define INTEGRAL_EVAL_TERMS_H

#include "../utils/types.h"

namespace eval {

// clang-format off
template <typename T>
using PieceValueTable = std::array<T, PieceType::kNumTypes>;

template <typename T>
using PieceSquareTable = std::array<std::array<T, kSquareCount>,
                                    PieceType::kNumTypes>;

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
  Pair(107, 153), Pair(320, 310), Pair(364, 341), Pair(453, 689), Pair(995, 1176), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(35, 75), Pair(62, 45), Pair(35, 48), Pair(75, -27), Pair(47, -26), Pair(31, -4), Pair(-49, 49), Pair(-77, 72),
      Pair(6, 55), Pair(19, 54), Pair(54, 0), Pair(55, -49), Pair(67, -55), Pair(116, -26), Pair(75, 25), Pair(38, 25),
      Pair(-22, 31), Pair(-1, 16), Pair(0, -6), Pair(10, -33), Pair(35, -35), Pair(35, -23), Pair(31, 2), Pair(13, -6),
      Pair(-35, 8), Pair(-14, 7), Pair(-13, -13), Pair(7, -24), Pair(9, -26), Pair(15, -19), Pair(15, -7), Pair(-3, -21),
      Pair(-31, 2), Pair(-13, 5), Pair(-12, -11), Pair(-5, -14), Pair(11, -14), Pair(15, -13), Pair(36, -10), Pair(6, -25),
      Pair(-34, 9), Pair(-14, 13), Pair(-22, 0), Pair(-19, -6), Pair(-5, 5), Pair(26, -6), Pair(46, -4), Pair(-8, -20),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-186, -63), Pair(-155, 20), Pair(-82, 39), Pair(-47, 26), Pair(-2, 28), Pair(-79, 1), Pair(-127, 19), Pair(-130, -86),
      Pair(-33, 21), Pair(-6, 40), Pair(30, 36), Pair(56, 34), Pair(25, 25), Pair(98, 13), Pair(-18, 37), Pair(10, 0),
      Pair(-10, 31), Pair(36, 42), Pair(59, 64), Pair(69, 66), Pair(117, 45), Pair(117, 37), Pair(62, 32), Pair(21, 18),
      Pair(-11, 48), Pair(8, 62), Pair(38, 80), Pair(64, 79), Pair(38, 80), Pair(70, 75), Pair(20, 61), Pair(34, 35),
      Pair(-28, 46), Pair(-7, 53), Pair(16, 79), Pair(18, 79), Pair(31, 83), Pair(22, 68), Pair(20, 53), Pair(-13, 35),
      Pair(-51, 24), Pair(-22, 44), Pair(-4, 52), Pair(11, 71), Pair(27, 67), Pair(6, 45), Pair(7, 34), Pair(-27, 27),
      Pair(-61, 21), Pair(-46, 37), Pair(-26, 44), Pair(-7, 41), Pair(-7, 41), Pair(-3, 38), Pair(-22, 22), Pair(-25, 28),
      Pair(-105, 17), Pair(-45, 4), Pair(-52, 32), Pair(-33, 34), Pair(-27, 33), Pair(-16, 20), Pair(-39, 11), Pair(-65, 10)
  },
  {
      Pair(-20, 58), Pair(-51, 69), Pair(-45, 58), Pair(-97, 72), Pair(-78, 66), Pair(-64, 55), Pair(-23, 52), Pair(-46, 53),
      Pair(-1, 45), Pair(23, 52), Pair(10, 54), Pair(-13, 55), Pair(25, 43), Pair(8, 47), Pair(13, 56), Pair(-4, 42),
      Pair(8, 65), Pair(32, 57), Pair(31, 57), Pair(49, 45), Pair(32, 51), Pair(75, 58), Pair(50, 54), Pair(41, 62),
      Pair(1, 60), Pair(13, 64), Pair(32, 59), Pair(46, 72), Pair(43, 64), Pair(35, 63), Pair(13, 62), Pair(2, 60),
      Pair(1, 53), Pair(5, 64), Pair(6, 69), Pair(38, 68), Pair(34, 65), Pair(9, 64), Pair(5, 59), Pair(16, 40),
      Pair(6, 55), Pair(19, 63), Pair(21, 64), Pair(15, 64), Pair(20, 69), Pair(22, 61), Pair(23, 53), Pair(27, 41),
      Pair(15, 55), Pair(23, 44), Pair(30, 38), Pair(7, 57), Pair(19, 52), Pair(32, 46), Pair(43, 49), Pair(24, 35),
      Pair(5, 46), Pair(28, 60), Pair(7, 50), Pair(-1, 58), Pair(8, 57), Pair(2, 62), Pair(27, 40), Pair(24, 25)
  },
  {
      Pair(9, 59), Pair(0, 74), Pair(6, 76), Pair(3, 67), Pair(16, 57), Pair(24, 70), Pair(8, 71), Pair(-27, 74),
      Pair(-7, 65), Pair(-7, 84), Pair(15, 80), Pair(36, 62), Pair(10, 63), Pair(36, 67), Pair(7, 69), Pair(-9, 64),
      Pair(-30, 63), Pair(4, 68), Pair(1, 63), Pair(-3, 56), Pair(29, 41), Pair(41, 48), Pair(73, 44), Pair(6, 43),
      Pair(-34, 64), Pair(-20, 67), Pair(-21, 68), Pair(-13, 59), Pair(-14, 42), Pair(-2, 51), Pair(-7, 55), Pair(-25, 48),
      Pair(-45, 52), Pair(-43, 64), Pair(-31, 56), Pair(-28, 53), Pair(-25, 46), Pair(-36, 59), Pair(-19, 48), Pair(-41, 38),
      Pair(-44, 43), Pair(-42, 50), Pair(-32, 44), Pair(-28, 44), Pair(-18, 33), Pair(-20, 40), Pair(9, 17), Pair(-17, 12),
      Pair(-43, 36), Pair(-37, 48), Pair(-20, 44), Pair(-21, 42), Pair(-14, 29), Pair(-9, 36), Pair(-12, 28), Pair(-47, 24),
      Pair(-23, 42), Pair(-21, 45), Pair(-13, 47), Pair(-7, 38), Pair(-2, 29), Pair(-5, 41), Pair(-11, 34), Pair(-28, 23)
  },
  {
      Pair(-18, 143), Pair(-26, 159), Pair(-2, 180), Pair(40, 157), Pair(45, 158), Pair(52, 161), Pair(96, 92), Pair(15, 153),
      Pair(16, 128), Pair(-10, 161), Pair(-5, 194), Pair(-17, 216), Pair(-15, 240), Pair(27, 193), Pair(16, 180), Pair(61, 173),
      Pair(18, 129), Pair(12, 139), Pair(7, 179), Pair(16, 186), Pair(22, 203), Pair(83, 181), Pair(88, 148), Pair(87, 144),
      Pair(0, 140), Pair(3, 151), Pair(5, 162), Pair(2, 186), Pair(4, 201), Pair(18, 192), Pair(26, 186), Pair(32, 175),
      Pair(3, 130), Pair(-1, 156), Pair(2, 151), Pair(8, 177), Pair(11, 170), Pair(11, 170), Pair(20, 159), Pair(26, 159),
      Pair(6, 116), Pair(11, 129), Pair(12, 143), Pair(9, 140), Pair(15, 147), Pair(18, 151), Pair(33, 135), Pair(26, 126),
      Pair(11, 111), Pair(16, 107), Pair(24, 104), Pair(28, 112), Pair(24, 120), Pair(39, 91), Pair(45, 64), Pair(50, 45),
      Pair(7, 109), Pair(10, 105), Pair(18, 104), Pair(21, 121), Pair(23, 105), Pair(8, 106), Pair(35, 74), Pair(22, 76)
  },
  {
      Pair(56, -127), Pair(74, -69), Pair(77, -46), Pair(-81, 7), Pair(-47, -6), Pair(17, -6), Pair(85, -19), Pair(180, -148),
      Pair(-94, -8), Pair(-42, 34), Pair(-75, 43), Pair(42, 25), Pair(-24, 49), Pair(-13, 64), Pair(12, 53), Pair(-13, 11),
      Pair(-131, 10), Pair(13, 35), Pair(-62, 57), Pair(-95, 73), Pair(-46, 74), Pair(47, 65), Pair(2, 64), Pair(-43, 23),
      Pair(-84, -2), Pair(-91, 40), Pair(-111, 63), Pair(-171, 80), Pair(-156, 80), Pair(-117, 75), Pair(-114, 63), Pair(-159, 29),
      Pair(-88, -15), Pair(-83, 23), Pair(-130, 53), Pair(-169, 73), Pair(-163, 71), Pair(-118, 55), Pair(-126, 39), Pair(-165, 21),
      Pair(-33, -25), Pair(-6, 1), Pair(-79, 30), Pair(-97, 45), Pair(-89, 45), Pair(-87, 33), Pair(-37, 8), Pair(-54, -10),
      Pair(78, -52), Pair(24, -16), Pair(8, -2), Pair(-35, 11), Pair(-39, 15), Pair(-14, 2), Pair(37, -22), Pair(49, -46),
      Pair(68, -100), Pair(98, -73), Pair(64, -49), Pair(-50, -23), Pair(19, -51), Pair(-15, -30), Pair(69, -67), Pair(73, -103)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(17, 95), Pair(34, 94), Pair(40, 105), Pair(43, 102), Pair(46, 108), Pair(45, 114), Pair(43, 116), Pair(43, 116),
  Pair(45, 112)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-14, 5), Pair(-4, 27), Pair(5, 37), Pair(8, 51), Pair(16, 68), Pair(25, 85), Pair(32, 90), Pair(37, 98),
  Pair(38, 107), Pair(40, 105), Pair(44, 103), Pair(48, 104), Pair(40, 113), Pair(76, 90)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(3, 40), Pair(12, 65), Pair(17, 67), Pair(21, 71), Pair(20, 79), Pair(25, 83), Pair(27, 85), Pair(31, 88),
  Pair(30, 98), Pair(33, 102), Pair(37, 103), Pair(38, 108), Pair(39, 112), Pair(42, 114), Pair(38, 111)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-3, 31), Pair(-10, 64), Pair(-23, 146), Pair(-21, 163), Pair(-19, 168), Pair(-16, 176), Pair(-12, 183), Pair(-13, 209),
  Pair(-12, 218), Pair(-9, 221), Pair(-7, 236), Pair(-8, 243), Pair(-6, 254), Pair(-5, 261), Pair(-4, 269), Pair(-4, 275),
  Pair(0, 280), Pair(-4, 293), Pair(-1, 300), Pair(3, 301), Pair(15, 297), Pair(18, 299), Pair(20, 301), Pair(27, 301),
  Pair(52, 279), Pair(116, 258), Pair(120, 254), Pair(239, 202)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-17, -8), Pair(-24, 0), Pair(-16, 29), Pair(9, 59), Pair(1, 134), Pair(46, 185), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(1, -10), Pair(2, 4), Pair(23, 20), Pair(48, 73), Pair(136, 249), Pair(-26, 529), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-29, -60), Pair(-15, -47), Pair(-18, -47), Pair(-17, -30), Pair(-25, -25), Pair(-33, -40), Pair(-32, -39), Pair(-40, -60)
};

constexpr FileTable<ScorePair> kRookOnOpenFileBonus = {
  Pair(37, 10), Pair(32, 2), Pair(30, 11), Pair(31, 13), Pair(38, 17), Pair(54, -4), Pair(84, -10), Pair(144, -18)
};

constexpr FileTable<ScorePair> kRookOnSemiOpenFileBonus = {
  Pair(6, 54), Pair(10, 18), Pair(8, 21), Pair(19, 10), Pair(16, 9), Pair(24, -2), Pair(47, -3), Pair(46, 24)
};

constexpr ScorePair kTempoBonus = Pair(25, 28);

constexpr std::array<int, PieceType::kNumTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_EVAL_TERMS_H