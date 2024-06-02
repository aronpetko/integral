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
  Pair(106, 144),  Pair(317, 319),  Pair(353, 349),  Pair(464, 689),  Pair(990, 1177),  Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0),
      Pair(28, 62),  Pair(67, 47),  Pair(37, 49),  Pair(66, -22),  Pair(46, -21),  Pair(29, 4),  Pair(-38, 52),  Pair(-87, 74),
      Pair(-4, 56),  Pair(16, 60),  Pair(50, 5),  Pair(46, -43),  Pair(59, -48),  Pair(102, -15),  Pair(75, 33),  Pair(19, 35),
      Pair(-28, 32),  Pair(-2, 23),  Pair(-1, 0),  Pair(6, -26),  Pair(31, -27),  Pair(24, -12),  Pair(28, 10),  Pair(-4, 4),
      Pair(-39, 10),  Pair(-14, 14),  Pair(-12, -7),  Pair(5, -17),  Pair(7, -18),  Pair(6, -8),  Pair(10, 1),  Pair(-18, -11),
      Pair(-33, 3),  Pair(-14, 12),  Pair(-10, -6),  Pair(-6, -7),  Pair(12, -5),  Pair(8, -3),  Pair(32, -2),  Pair(-7, -16),
      Pair(-34, 10),  Pair(-13, 20),  Pair(-19, 5),  Pair(-18, 2),  Pair(-4, 13),  Pair(20, 5),  Pair(43, 4),  Pair(-19, -12),
      Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0)
  },
  {
      Pair(-185, -62),  Pair(-157, 19),  Pair(-84, 39),  Pair(-46, 25),  Pair(-1, 26),  Pair(-76, 0),  Pair(-129, 18),  Pair(-128, -88),
      Pair(-33, 24),  Pair(-6, 40),  Pair(29, 35),  Pair(56, 32),  Pair(23, 24),  Pair(103, 9),  Pair(-15, 35),  Pair(21, -4),
      Pair(-9, 32),  Pair(36, 41),  Pair(59, 63),  Pair(68, 64),  Pair(118, 44),  Pair(117, 36),  Pair(66, 29),  Pair(23, 17),
      Pair(-12, 48),  Pair(7, 61),  Pair(38, 78),  Pair(65, 77),  Pair(38, 79),  Pair(71, 74),  Pair(21, 59),  Pair(33, 34),
      Pair(-28, 45),  Pair(-7, 52),  Pair(15, 77),  Pair(18, 77),  Pair(31, 81),  Pair(23, 66),  Pair(18, 51),  Pair(-13, 33),
      Pair(-50, 21),  Pair(-22, 41),  Pair(-3, 49),  Pair(12, 70),  Pair(28, 65),  Pair(7, 42),  Pair(6, 31),  Pair(-27, 24),
      Pair(-58, 18),  Pair(-45, 35),  Pair(-26, 41),  Pair(-6, 39),  Pair(-6, 39),  Pair(-2, 34),  Pair(-24, 21),  Pair(-26, 26),
      Pair(-105, 14),  Pair(-40, 1),  Pair(-47, 29),  Pair(-27, 32),  Pair(-23, 31),  Pair(-17, 18),  Pair(-36, 6),  Pair(-67, 8)
  },
  {
      Pair(-20, 56),  Pair(-52, 68),  Pair(-46, 56),  Pair(-96, 70),  Pair(-76, 63),  Pair(-61, 53),  Pair(-20, 50),  Pair(-47, 50),
      Pair(0, 45),  Pair(24, 50),  Pair(11, 52),  Pair(-12, 54),  Pair(26, 41),  Pair(14, 43),  Pair(17, 53),  Pair(3, 39),
      Pair(10, 65),  Pair(35, 55),  Pair(32, 55),  Pair(52, 44),  Pair(33, 49),  Pair(79, 55),  Pair(54, 51),  Pair(47, 59),
      Pair(4, 58),  Pair(14, 62),  Pair(36, 57),  Pair(48, 69),  Pair(45, 62),  Pair(37, 60),  Pair(14, 60),  Pair(5, 58),
      Pair(3, 52),  Pair(7, 61),  Pair(9, 66),  Pair(40, 65),  Pair(36, 62),  Pair(11, 61),  Pair(6, 57),  Pair(16, 39),
      Pair(9, 51),  Pair(20, 59),  Pair(23, 61),  Pair(18, 61),  Pair(22, 67),  Pair(25, 57),  Pair(24, 51),  Pair(28, 38),
      Pair(19, 52),  Pair(25, 42),  Pair(31, 36),  Pair(10, 55),  Pair(22, 49),  Pair(35, 43),  Pair(43, 46),  Pair(24, 32),
      Pair(8, 43),  Pair(33, 57),  Pair(13, 49),  Pair(7, 55),  Pair(14, 54),  Pair(6, 60),  Pair(30, 37),  Pair(24, 24)
  },
  {
      Pair(13, 65),  Pair(-7, 75),  Pair(-5, 84),  Pair(-5, 77),  Pair(15, 67),  Pair(34, 64),  Pair(29, 63),  Pair(56, 56),
      Pair(-3, 70),  Pair(-10, 84),  Pair(12, 86),  Pair(37, 71),  Pair(19, 73),  Pair(55, 60),  Pair(45, 56),  Pair(86, 41),
      Pair(-28, 72),  Pair(0, 69),  Pair(-5, 71),  Pair(-4, 66),  Pair(33, 51),  Pair(45, 44),  Pair(100, 35),  Pair(69, 32),
      Pair(-35, 75),  Pair(-26, 70),  Pair(-27, 78),  Pair(-18, 70),  Pair(-15, 54),  Pair(0, 49),  Pair(12, 50),  Pair(13, 45),
      Pair(-49, 66),  Pair(-48, 67),  Pair(-38, 67),  Pair(-30, 63),  Pair(-27, 59),  Pair(-36, 57),  Pair(-9, 45),  Pair(-25, 44),
      Pair(-50, 59),  Pair(-45, 54),  Pair(-35, 54),  Pair(-28, 55),  Pair(-19, 47),  Pair(-21, 40),  Pair(13, 17),  Pair(-12, 22),
      Pair(-50, 50),  Pair(-40, 52),  Pair(-18, 51),  Pair(-17, 49),  Pair(-11, 41),  Pair(-7, 34),  Pair(8, 24),  Pair(-28, 34),
      Pair(-29, 45),  Pair(-24, 47),  Pair(-10, 52),  Pair(-2, 44),  Pair(2, 39),  Pair(-6, 41),  Pair(7, 30),  Pair(-25, 27)
  },
  {
      Pair(-23, 139),  Pair(-34, 159),  Pair(-12, 180),  Pair(29, 159),  Pair(33, 161),  Pair(42, 161),  Pair(86, 92),  Pair(16, 146),
      Pair(10, 129),  Pair(-16, 160),  Pair(-11, 193),  Pair(-23, 215),  Pair(-16, 236),  Pair(27, 190),  Pair(15, 177),  Pair(70, 164),
      Pair(12, 131),  Pair(7, 140),  Pair(0, 179),  Pair(10, 186),  Pair(15, 204),  Pair(77, 181),  Pair(85, 147),  Pair(86, 144),
      Pair(-6, 143),  Pair(-4, 151),  Pair(-2, 164),  Pair(-5, 186),  Pair(-2, 201),  Pair(12, 193),  Pair(20, 187),  Pair(26, 176),
      Pair(-3, 131),  Pair(-7, 157),  Pair(-5, 152),  Pair(2, 177),  Pair(5, 171),  Pair(3, 171),  Pair(11, 160),  Pair(21, 158),
      Pair(1, 115),  Pair(5, 129),  Pair(7, 143),  Pair(3, 140),  Pair(9, 150),  Pair(12, 149),  Pair(26, 132),  Pair(22, 125),
      Pair(9, 107),  Pair(11, 107),  Pair(19, 104),  Pair(24, 111),  Pair(21, 117),  Pair(36, 89),  Pair(40, 58),  Pair(58, 29),
      Pair(6, 105),  Pair(9, 102),  Pair(20, 100),  Pair(22, 118),  Pair(24, 99),  Pair(7, 101),  Pair(36, 68),  Pair(21, 72)
  },
  {
      Pair(46, -118),  Pair(68, -62),  Pair(74, -41),  Pair(-82, 12),  Pair(-47, -2),  Pair(12, -2),  Pair(80, -15),  Pair(161, -142),
      Pair(-102, 0),  Pair(-51, 39),  Pair(-78, 47),  Pair(39, 28),  Pair(-26, 53),  Pair(-17, 66),  Pair(10, 56),  Pair(-19, 14),
      Pair(-136, 17),  Pair(6, 40),  Pair(-68, 62),  Pair(-95, 76),  Pair(-44, 78),  Pair(50, 68),  Pair(4, 67),  Pair(-39, 25),
      Pair(-93, 4),  Pair(-99, 45),  Pair(-116, 68),  Pair(-170, 82),  Pair(-156, 83),  Pair(-116, 77),  Pair(-113, 66),  Pair(-157, 32),
      Pair(-95, -9),  Pair(-91, 27),  Pair(-134, 57),  Pair(-170, 77),  Pair(-165, 74),  Pair(-121, 59),  Pair(-128, 42),  Pair(-166, 23),
      Pair(-38, -21),  Pair(-17, 6),  Pair(-85, 34),  Pair(-102, 48),  Pair(-95, 48),  Pair(-94, 36),  Pair(-40, 11),  Pair(-58, -5),
      Pair(67, -47),  Pair(15, -12),  Pair(-1, 2),  Pair(-41, 14),  Pair(-44, 19),  Pair(-21, 6),  Pair(33, -19),  Pair(45, -43),
      Pair(63, -96),  Pair(95, -69),  Pair(64, -44),  Pair(-49, -21),  Pair(19, -47),  Pair(-15, -27),  Pair(71, -64),  Pair(72, -101)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(16, 86),  Pair(34, 87),  Pair(40, 96),  Pair(44, 94),  Pair(47, 100),  Pair(46, 107),  Pair(44, 109),  Pair(43, 109),
  Pair(45, 105)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-8, 0),  Pair(1, 21),  Pair(10, 31),  Pair(14, 45),  Pair(22, 62),  Pair(31, 78),  Pair(38, 84),  Pair(43, 92),
  Pair(44, 102),  Pair(46, 99),  Pair(49, 98),  Pair(53, 99),  Pair(47, 108),  Pair(83, 84)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-6, 36),  Pair(5, 58),  Pair(11, 60),  Pair(17, 64),  Pair(16, 73),  Pair(25, 78),  Pair(29, 82),  Pair(38, 84),
  Pair(42, 94),  Pair(49, 99),  Pair(55, 101),  Pair(60, 105),  Pair(60, 111),  Pair(68, 116),  Pair(68, 110)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-5, 28),  Pair(-15, 70),  Pair(-25, 149),  Pair(-21, 165),  Pair(-19, 170),  Pair(-15, 177),  Pair(-10, 184),  Pair(-12, 209),
  Pair(-10, 218),  Pair(-7, 222),  Pair(-6, 235),  Pair(-5, 243),  Pair(-5, 254),  Pair(-4, 262),  Pair(-2, 269),  Pair(-1, 275),
  Pair(3, 281),  Pair(-1, 293),  Pair(3, 300),  Pair(6, 300),  Pair(18, 295),  Pair(23, 296),  Pair(24, 298),  Pair(31, 297),
  Pair(58, 274),  Pair(122, 252),  Pair(131, 247),  Pair(249, 194)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0),  Pair(-18, -9),  Pair(-24, 1),  Pair(-17, 30),  Pair(8, 59),  Pair(1, 135),  Pair(34, 188),  Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0),  Pair(0, -10),  Pair(2, 3),  Pair(22, 20),  Pair(47, 72),  Pair(127, 251),  Pair(25, 481),  Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-25, -50), Pair(-13, -44), Pair(-18, -43), Pair(-12, -28), Pair(-21, -24), Pair(-24, -43), Pair(-26, -39), Pair(-26, -59)
};

constexpr FileTable<ScorePair> kRookOnOpenFileBonus = {
  Pair(10, 10), Pair(10, 10), Pair(10, 10), Pair(10, 10), Pair(10, 10), Pair(10, 10), Pair(10, 10), Pair(10, 10)
};

constexpr ScorePair kTempoBonus = Pair(24, 28);

constexpr std::array<int, PieceType::kNumTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_EVAL_TERMS_H