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
  Pair(96, 175), Pair(317, 280), Pair(367, 313), Pair(467, 683), Pair(1018, 1150), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(27, 53), Pair(55, 25), Pair(18, 33), Pair(50, -33), Pair(27, -31), Pair(26, -10), Pair(-10, 33), Pair(-63, 56),
      Pair(7, 31), Pair(11, 32), Pair(43, -17), Pair(43, -62), Pair(52, -65), Pair(94, -37), Pair(58, 10), Pair(10, 14),
      Pair(-17, 6), Pair(1, -6), Pair(-1, -27), Pair(5, -52), Pair(33, -54), Pair(30, -40), Pair(28, -17), Pair(1, -22),
      Pair(-25, -17), Pair(-12, -15), Pair(-9, -35), Pair(9, -47), Pair(12, -49), Pair(18, -41), Pair(26, -32), Pair(-2, -41),
      Pair(-24, -22), Pair(-4, -20), Pair(-7, -36), Pair(0, -37), Pair(14, -36), Pair(13, -37), Pair(35, -35), Pair(3, -46),
      Pair(-23, -17), Pair(-4, -13), Pair(-12, -27), Pair(-13, -32), Pair(1, -22), Pair(22, -31), Pair(41, -31), Pair(-11, -42),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-163, -26), Pair(-137, 29), Pair(-70, 44), Pair(-28, 30), Pair(9, 33), Pair(-61, 6), Pair(-116, 27), Pair(-113, -49),
      Pair(-16, 34), Pair(9, 47), Pair(39, 41), Pair(58, 39), Pair(29, 31), Pair(103, 15), Pair(2, 43), Pair(29, 10),
      Pair(4, 39), Pair(37, 46), Pair(48, 72), Pair(62, 71), Pair(105, 53), Pair(104, 44), Pair(61, 37), Pair(30, 28),
      Pair(7, 57), Pair(11, 67), Pair(35, 82), Pair(63, 84), Pair(40, 82), Pair(67, 79), Pair(24, 66), Pair(48, 45),
      Pair(-7, 61), Pair(2, 58), Pair(16, 84), Pair(25, 82), Pair(34, 89), Pair(30, 73), Pair(40, 58), Pair(11, 56),
      Pair(-32, 40), Pair(-9, 49), Pair(0, 57), Pair(12, 76), Pair(32, 72), Pair(12, 51), Pair(20, 43), Pair(-5, 46),
      Pair(-38, 41), Pair(-23, 49), Pair(-8, 50), Pair(11, 49), Pair(13, 48), Pair(11, 46), Pair(3, 38), Pair(0, 53),
      Pair(-77, 46), Pair(-29, 32), Pair(-30, 45), Pair(-12, 52), Pair(-3, 51), Pair(1, 39), Pair(-25, 42), Pair(-36, 38)
  },
  {
      Pair(-29, 68), Pair(-58, 74), Pair(-52, 65), Pair(-101, 76), Pair(-84, 71), Pair(-77, 61), Pair(-35, 59), Pair(-53, 54),
      Pair(-5, 48), Pair(16, 60), Pair(3, 62), Pair(-13, 66), Pair(20, 53), Pair(9, 57), Pair(5, 63), Pair(-14, 52),
      Pair(0, 71), Pair(22, 65), Pair(19, 73), Pair(39, 59), Pair(26, 63), Pair(63, 71), Pair(39, 64), Pair(29, 67),
      Pair(-9, 65), Pair(8, 75), Pair(26, 72), Pair(46, 88), Pair(39, 78), Pair(29, 78), Pair(11, 70), Pair(-4, 65),
      Pair(-3, 61), Pair(-4, 75), Pair(7, 84), Pair(39, 82), Pair(35, 81), Pair(4, 78), Pair(3, 71), Pair(18, 48),
      Pair(0, 62), Pair(20, 75), Pair(17, 76), Pair(17, 80), Pair(20, 84), Pair(20, 75), Pair(21, 66), Pair(24, 52),
      Pair(16, 67), Pair(17, 53), Pair(27, 53), Pair(7, 67), Pair(19, 65), Pair(29, 60), Pair(42, 57), Pair(25, 46),
      Pair(2, 54), Pair(29, 71), Pair(2, 59), Pair(-4, 65), Pair(5, 63), Pair(0, 73), Pair(18, 53), Pair(31, 28)
  },
  {
      Pair(-2, 60), Pair(-13, 74), Pair(-12, 74), Pair(-14, 67), Pair(3, 53), Pair(17, 67), Pair(7, 66), Pair(-14, 66),
      Pair(-13, 63), Pair(-11, 82), Pair(10, 76), Pair(26, 62), Pair(8, 60), Pair(35, 66), Pair(16, 63), Pair(6, 56),
      Pair(-32, 63), Pair(3, 67), Pair(2, 60), Pair(0, 55), Pair(32, 38), Pair(44, 46), Pair(70, 43), Pair(11, 38),
      Pair(-34, 62), Pair(-18, 65), Pair(-14, 65), Pair(-10, 57), Pair(-7, 41), Pair(-1, 50), Pair(-4, 53), Pair(-20, 44),
      Pair(-43, 50), Pair(-43, 62), Pair(-29, 53), Pair(-26, 51), Pair(-24, 44), Pair(-37, 59), Pair(-14, 46), Pair(-30, 34),
      Pair(-45, 42), Pair(-40, 47), Pair(-31, 41), Pair(-32, 43), Pair(-18, 32), Pair(-19, 38), Pair(14, 15), Pair(-13, 10),
      Pair(-43, 33), Pair(-37, 43), Pair(-18, 38), Pair(-18, 37), Pair(-11, 25), Pair(-7, 32), Pair(-3, 21), Pair(-41, 17),
      Pair(-27, 38), Pair(-20, 38), Pair(-12, 42), Pair(-7, 34), Pair(0, 24), Pair(-5, 36), Pair(-16, 30), Pair(-22, 16)
  },
  {
      Pair(-32, 141), Pair(-40, 161), Pair(-17, 188), Pair(24, 167), Pair(28, 168), Pair(39, 164), Pair(85, 96), Pair(8, 150),
      Pair(14, 121), Pair(-13, 160), Pair(-10, 196), Pair(-25, 224), Pair(-18, 244), Pair(30, 196), Pair(23, 176), Pair(73, 163),
      Pair(15, 132), Pair(10, 146), Pair(7, 186), Pair(18, 194), Pair(22, 214), Pair(82, 188), Pair(84, 157), Pair(82, 153),
      Pair(1, 140), Pair(3, 158), Pair(8, 168), Pair(6, 193), Pair(7, 212), Pair(23, 199), Pair(30, 193), Pair(34, 178),
      Pair(4, 133), Pair(0, 160), Pair(6, 157), Pair(13, 180), Pair(16, 177), Pair(14, 178), Pair(24, 168), Pair(34, 160),
      Pair(9, 113), Pair(14, 132), Pair(15, 144), Pair(12, 145), Pair(18, 153), Pair(23, 155), Pair(37, 136), Pair(32, 127),
      Pair(16, 101), Pair(19, 101), Pair(26, 105), Pair(33, 106), Pair(31, 115), Pair(41, 93), Pair(45, 67), Pair(50, 48),
      Pair(9, 100), Pair(16, 99), Pair(21, 103), Pair(24, 113), Pair(29, 97), Pair(16, 101), Pair(29, 77), Pair(28, 66)
  },
  {
      Pair(89, -137), Pair(108, -79), Pair(111, -60), Pair(-53, -5), Pair(-9, -21), Pair(39, -18), Pair(116, -35), Pair(226, -160),
      Pair(-60, -20), Pair(3, 15), Pair(-28, 25), Pair(74, 9), Pair(18, 29), Pair(21, 47), Pair(59, 31), Pair(23, -4),
      Pair(-100, -8), Pair(51, 11), Pair(-17, 35), Pair(-48, 51), Pair(-2, 53), Pair(78, 34), Pair(15, 37), Pair(-16, 0),
      Pair(-49, -24), Pair(-42, 9), Pair(-67, 35), Pair(-125, 54), Pair(-115, 51), Pair(-88, 41), Pair(-83, 23), Pair(-129, 4),
      Pair(-45, -36), Pair(-42, -4), Pair(-92, 29), Pair(-137, 50), Pair(-132, 47), Pair(-88, 26), Pair(-84, 8), Pair(-131, -7),
      Pair(-10, -42), Pair(13, -17), Pair(-51, 13), Pair(-73, 29), Pair(-69, 27), Pair(-73, 15), Pair(-29, -9), Pair(-36, -28),
      Pair(74, -62), Pair(2, -20), Pair(4, -8), Pair(-15, 1), Pair(-28, 5), Pair(-19, -5), Pair(6, -24), Pair(52, -57),
      Pair(66, -104), Pair(71, -68), Pair(67, -51), Pair(-10, -31), Pair(54, -58), Pair(-6, -31), Pair(52, -61), Pair(81, -109)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(4, 78), Pair(21, 85), Pair(34, 111), Pair(40, 122), Pair(48, 132), Pair(54, 142), Pair(63, 140), Pair(71, 136),
  Pair(78, 123)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-33, 37), Pair(-20, 40), Pair(-6, 61), Pair(3, 77), Pair(13, 89), Pair(18, 103), Pair(24, 107), Pair(27, 110),
  Pair(29, 115), Pair(34, 109), Pair(45, 104), Pair(53, 101), Pair(54, 112), Pair(64, 85)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(5, 38), Pair(14, 69), Pair(18, 72), Pair(22, 78), Pair(20, 87), Pair(26, 92), Pair(28, 99), Pair(32, 102),
  Pair(36, 105), Pair(39, 109), Pair(43, 112), Pair(42, 116), Pair(46, 119), Pair(51, 114), Pair(39, 114)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-48, -103), Pair(-8, -75), Pair(-22, 125), Pair(-19, 172), Pair(-17, 199), Pair(-13, 210), Pair(-10, 230), Pair(-8, 247),
  Pair(-4, 256), Pair(-2, 260), Pair(1, 267), Pair(4, 275), Pair(6, 278), Pair(6, 287), Pair(9, 290), Pair(12, 296),
  Pair(11, 306), Pair(12, 308), Pair(23, 307), Pair(36, 299), Pair(39, 303), Pair(99, 267), Pair(81, 281), Pair(109, 254),
  Pair(213, 225), Pair(198, 206), Pair(151, 259), Pair(232, 182)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-16, -7), Pair(-24, 2), Pair(-18, 33), Pair(8, 66), Pair(6, 141), Pair(62, 184), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(0, -6), Pair(0, 3), Pair(23, 17), Pair(52, 66), Pair(136, 236), Pair(-149, 548), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-26, -62), Pair(-13, -47), Pair(-17, -48), Pair(-14, -34), Pair(-22, -28), Pair(-28, -42), Pair(-27, -38), Pair(-27, -64)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-9, 3), Pair(-10, -19), Pair(-21, -14), Pair(-18, -23), Pair(-23, -22), Pair(-14, -10), Pair(-9, -21), Pair(-12, 9)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(32, 12), Pair(32, 4), Pair(28, 14), Pair(33, 14), Pair(36, 20), Pair(61, -4), Pair(76, -6), Pair(113, -6)
  },
  {
      Pair(3, 56), Pair(11, 22), Pair(7, 25), Pair(19, 14), Pair(14, 16), Pair(24, 3), Pair(45, 1), Pair(28, 31)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(21, 0), Pair(42, 1), Pair(17, 4),
  Pair(34, -7), Pair(53, -8), Pair(32, -9),
  Pair(48, 1), Pair(0, 0), Pair(44, 1),
  Pair(-21, 4), Pair(19, 4), Pair(-20, 5)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-18, 10), Pair(-27, 7), Pair(-18, 12),
  Pair(-15, 10), Pair(-29, 9), Pair(-18, 12),
  Pair(-6, 0), Pair(-23, 1), Pair(-6, 2),
  Pair(8, -1), Pair(-14, -5), Pair(7, 2),
  Pair(26, -6), Pair(17, -9), Pair(18, -7),
  Pair(0, 0), Pair(-86, -50), Pair(0, 0),
  Pair(-16, -57), Pair(0, 0), Pair(-19, -53)
};

constexpr ScorePair kBishopPairBonus = Pair(26, 78);
constexpr ScorePair kTempoBonus = Pair(26, 30);

constexpr std::array<int, PieceType::kNumTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_EVAL_TERMS_H