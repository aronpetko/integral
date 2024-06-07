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
  Pair(91, 158), Pair(320, 295), Pair(378, 323), Pair(472, 685), Pair(1003, 1176), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(38, 51), Pair(51, 38), Pair(22, 40), Pair(56, -21), Pair(34, -17), Pair(26, -7), Pair(-21, 50), Pair(-52, 50),
      Pair(11, 34), Pair(3, 49), Pair(43, -7), Pair(45, -49), Pair(56, -51), Pair(93, -33), Pair(49, 31), Pair(19, 13),
      Pair(-15, 10), Pair(-10, 10), Pair(-1, -15), Pair(4, -39), Pair(32, -40), Pair(28, -36), Pair(19, 2), Pair(9, -24),
      Pair(-22, -14), Pair(-22, -1), Pair(-9, -25), Pair(10, -34), Pair(12, -34), Pair(18, -36), Pair(17, -14), Pair(5, -41),
      Pair(-22, -19), Pair(-15, -7), Pair(-7, -25), Pair(-1, -25), Pair(12, -23), Pair(12, -32), Pair(24, -18), Pair(10, -46),
      Pair(-21, -13), Pair(-15, 0), Pair(-12, -16), Pair(-15, -20), Pair(0, -7), Pair(21, -26), Pair(33, -13), Pair(-4, -42),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-169, -38), Pair(-144, 25), Pair(-76, 40), Pair(-35, 26), Pair(1, 29), Pair(-68, 2), Pair(-125, 26), Pair(-120, -57),
      Pair(-21, 31), Pair(4, 43), Pair(33, 34), Pair(56, 33), Pair(25, 27), Pair(96, 12), Pair(-5, 41), Pair(23, 7),
      Pair(1, 35), Pair(33, 41), Pair(44, 66), Pair(59, 65), Pair(101, 48), Pair(102, 38), Pair(56, 34), Pair(26, 25),
      Pair(4, 52), Pair(8, 61), Pair(32, 77), Pair(58, 79), Pair(37, 78), Pair(63, 74), Pair(20, 62), Pair(44, 40),
      Pair(-10, 55), Pair(-1, 52), Pair(12, 78), Pair(21, 77), Pair(29, 81), Pair(26, 68), Pair(37, 53), Pair(7, 51),
      Pair(-37, 34), Pair(-13, 43), Pair(-4, 49), Pair(8, 69), Pair(27, 65), Pair(8, 44), Pair(16, 36), Pair(-8, 41),
      Pair(-41, 36), Pair(-26, 43), Pair(-12, 44), Pair(7, 42), Pair(9, 40), Pair(7, 38), Pair(0, 32), Pair(-4, 49),
      Pair(-77, 40), Pair(-33, 24), Pair(-34, 37), Pair(-15, 44), Pair(-7, 44), Pair(-3, 32), Pair(-29, 31), Pair(-38, 38)
  },
  {
      Pair(-27, 64), Pair(-55, 71), Pair(-47, 61), Pair(-95, 72), Pair(-80, 68), Pair(-73, 57), Pair(-28, 54), Pair(-50, 53),
      Pair(0, 46), Pair(22, 57), Pair(9, 59), Pair(-7, 62), Pair(23, 49), Pair(15, 53), Pair(10, 61), Pair(-10, 49),
      Pair(5, 69), Pair(28, 60), Pair(28, 68), Pair(46, 55), Pair(36, 60), Pair(70, 68), Pair(43, 61), Pair(34, 65),
      Pair(-5, 64), Pair(18, 71), Pair(31, 68), Pair(54, 83), Pair(45, 77), Pair(35, 74), Pair(17, 68), Pair(2, 65),
      Pair(5, 59), Pair(2, 71), Pair(14, 80), Pair(44, 80), Pair(41, 76), Pair(10, 74), Pair(9, 67), Pair(23, 45),
      Pair(5, 60), Pair(27, 73), Pair(22, 74), Pair(21, 76), Pair(25, 81), Pair(26, 70), Pair(27, 62), Pair(29, 50),
      Pair(22, 64), Pair(22, 50), Pair(32, 50), Pair(12, 64), Pair(25, 62), Pair(34, 54), Pair(47, 53), Pair(30, 44),
      Pair(7, 54), Pair(35, 68), Pair(7, 57), Pair(1, 64), Pair(10, 60), Pair(6, 70), Pair(23, 47), Pair(36, 29)
  },
  {
      Pair(-3, 57), Pair(-9, 72), Pair(-5, 71), Pair(-11, 66), Pair(5, 52), Pair(15, 65), Pair(3, 67), Pair(-14, 62),
      Pair(-17, 61), Pair(-17, 82), Pair(6, 75), Pair(23, 61), Pair(3, 59), Pair(31, 62), Pair(10, 63), Pair(3, 53),
      Pair(-34, 59), Pair(-1, 66), Pair(0, 59), Pair(-2, 53), Pair(31, 37), Pair(41, 42), Pair(69, 39), Pair(6, 35),
      Pair(-38, 59), Pair(-23, 64), Pair(-18, 65), Pair(-12, 58), Pair(-11, 40), Pair(-6, 48), Pair(-8, 51), Pair(-26, 41),
      Pair(-47, 48), Pair(-47, 62), Pair(-33, 53), Pair(-30, 51), Pair(-29, 43), Pair(-42, 56), Pair(-18, 43), Pair(-37, 32),
      Pair(-51, 39), Pair(-44, 46), Pair(-35, 40), Pair(-35, 42), Pair(-24, 30), Pair(-24, 35), Pair(8, 13), Pair(-19, 9),
      Pair(-48, 30), Pair(-42, 43), Pair(-23, 38), Pair(-22, 37), Pair(-16, 24), Pair(-13, 29), Pair(-8, 18), Pair(-47, 16),
      Pair(-31, 35), Pair(-25, 37), Pair(-17, 41), Pair(-12, 33), Pair(-5, 23), Pair(-11, 34), Pair(-20, 28), Pair(-27, 13)
  },
  {
      Pair(-26, 142), Pair(-31, 161), Pair(-9, 186), Pair(33, 165), Pair(37, 165), Pair(44, 164), Pair(93, 94), Pair(13, 149),
      Pair(14, 123), Pair(-13, 164), Pair(-10, 200), Pair(-25, 228), Pair(-18, 246), Pair(32, 197), Pair(24, 180), Pair(73, 165),
      Pair(16, 132), Pair(10, 148), Pair(9, 187), Pair(19, 196), Pair(29, 213), Pair(84, 188), Pair(87, 155), Pair(81, 153),
      Pair(1, 140), Pair(6, 156), Pair(9, 170), Pair(7, 197), Pair(10, 212), Pair(24, 200), Pair(31, 194), Pair(34, 179),
      Pair(6, 128), Pair(1, 159), Pair(6, 161), Pair(13, 185), Pair(16, 180), Pair(13, 180), Pair(24, 168), Pair(32, 160),
      Pair(9, 109), Pair(14, 133), Pair(15, 145), Pair(10, 149), Pair(17, 155), Pair(23, 154), Pair(37, 136), Pair(32, 127),
      Pair(15, 101), Pair(18, 101), Pair(25, 105), Pair(33, 107), Pair(30, 115), Pair(39, 89), Pair(45, 67), Pair(49, 44),
      Pair(8, 98), Pair(15, 97), Pair(20, 101), Pair(23, 113), Pair(28, 95), Pair(15, 97), Pair(26, 76), Pair(26, 64)
  },
  {
      Pair(83, -130), Pair(100, -73), Pair(99, -53), Pair(-60, 2), Pair(-24, -11), Pair(38, -13), Pair(100, -27), Pair(212, -154),
      Pair(-63, -14), Pair(-8, 23), Pair(-46, 35), Pair(72, 18), Pair(4, 39), Pair(14, 56), Pair(43, 40), Pair(14, 4),
      Pair(-101, -2), Pair(43, 17), Pair(-25, 42), Pair(-54, 58), Pair(-7, 61), Pair(77, 42), Pair(20, 42), Pair(-15, 5),
      Pair(-54, -18), Pair(-45, 14), Pair(-73, 41), Pair(-129, 61), Pair(-116, 57), Pair(-89, 48), Pair(-86, 28), Pair(-126, 8),
      Pair(-50, -32), Pair(-41, 1), Pair(-90, 33), Pair(-132, 53), Pair(-131, 51), Pair(-86, 30), Pair(-80, 12), Pair(-127, -3),
      Pair(-6, -39), Pair(14, -14), Pair(-53, 17), Pair(-75, 33), Pair(-69, 31), Pair(-72, 19), Pair(-29, -6), Pair(-36, -24),
      Pair(74, -59), Pair(0, -17), Pair(1, -5), Pair(-18, 5), Pair(-31, 9), Pair(-20, 0), Pair(5, -21), Pair(50, -53),
      Pair(68, -101), Pair(69, -66), Pair(65, -48), Pair(-12, -27), Pair(51, -54), Pair(-8, -27), Pair(50, -56), Pair(79, -106)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(0, 33), Pair(22, 74), Pair(34, 99), Pair(41, 111), Pair(48, 120), Pair(55, 131), Pair(64, 129), Pair(71, 126),
  Pair(78, 113)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-24, 15), Pair(-12, 40), Pair(1, 61), Pair(10, 78), Pair(20, 89), Pair(25, 103), Pair(30, 107), Pair(34, 110),
  Pair(36, 113), Pair(41, 109), Pair(53, 104), Pair(60, 101), Pair(59, 112), Pair(74, 84)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(5, 42), Pair(15, 70), Pair(18, 71), Pair(23, 76), Pair(20, 87), Pair(26, 92), Pair(27, 98), Pair(31, 101),
  Pair(35, 104), Pair(39, 108), Pair(43, 109), Pair(44, 114), Pair(49, 116), Pair(54, 111), Pair(43, 112)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-17, 17), Pair(-16, 49), Pair(-27, 138), Pair(-24, 169), Pair(-22, 190), Pair(-18, 199), Pair(-15, 218), Pair(-13, 234),
  Pair(-10, 242), Pair(-8, 245), Pair(-5, 254), Pair(-2, 261), Pair(1, 264), Pair(0, 273), Pair(3, 275), Pair(6, 281),
  Pair(6, 291), Pair(7, 293), Pair(17, 291), Pair(33, 280), Pair(36, 285), Pair(93, 250), Pair(79, 262), Pair(97, 243),
  Pair(150, 244), Pair(149, 216), Pair(124, 249), Pair(218, 174)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-6, 2), Pair(-14, 13), Pair(-11, 44), Pair(12, 74), Pair(8, 149), Pair(61, 197), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(-1, -9), Pair(-1, -1), Pair(21, 12), Pair(50, 58), Pair(135, 223), Pair(-110, 532), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-16, -48), Pair(4, -37), Pair(-7, -29), Pair(-5, -18), Pair(-15, -11), Pair(-18, -24), Pair(-13, -37), Pair(-19, -57)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-9, 2), Pair(-8, -19), Pair(-20, -14), Pair(-18, -23), Pair(-23, -23), Pair(-13, -11), Pair(-7, -20), Pair(-11, 8)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(33, 12), Pair(30, 3), Pair(27, 13), Pair(32, 12), Pair(37, 19), Pair(60, -3), Pair(78, -6), Pair(111, -5)
  },
  {
      Pair(2, 54), Pair(9, 19), Pair(7, 21), Pair(19, 10), Pair(14, 14), Pair(23, 0), Pair(41, -1), Pair(28, 29)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(22, -1), Pair(43, 1), Pair(17, 4),
  Pair(34, -7), Pair(53, -8), Pair(32, -8),
  Pair(47, 0), Pair(0, 0), Pair(42, 1),
  Pair(-25, 5), Pair(18, 5), Pair(-24, 6)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-18, 9), Pair(-27, 7), Pair(-19, 12),
  Pair(-16, 10), Pair(-29, 8), Pair(-19, 12),
  Pair(-7, 1), Pair(-24, 1), Pair(-7, 2),
  Pair(7, -1), Pair(-15, -5), Pair(5, 1),
  Pair(24, -7), Pair(15, -7), Pair(17, -7),
  Pair(0, 0), Pair(-90, -47), Pair(0, 0),
  Pair(-23, -56), Pair(0, 0), Pair(-28, -53)
};

constexpr ScorePair kTempoBonus = Pair(23, 29);

constexpr std::array<int, PieceType::kNumTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_EVAL_TERMS_H