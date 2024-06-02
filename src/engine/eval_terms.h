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
using PassedPawnTable = std::array<T, kNumRanks>;

constexpr PieceValueTable<ScorePair> kPieceValues = {
  Pair(101, 133),  Pair(316, 325),  Pair(349, 353),  Pair(465, 696),  Pair(988, 1182),  Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0),
      Pair(30, 70),  Pair(69, 52),  Pair(41, 54),  Pair(74, -15),  Pair(54, -14),  Pair(26, 9),  Pair(-49, 58),  Pair(-87, 81),
      Pair(-3, 60),  Pair(17, 61),  Pair(49, 5),  Pair(50, -38),  Pair(59, -44),  Pair(96, -17),  Pair(69, 33),  Pair(20, 36),
      Pair(-26, 39),  Pair(1, 27),  Pair(-1, 2),  Pair(8, -20),  Pair(31, -21),  Pair(18, -13),  Pair(27, 14),  Pair(0, 10),
      Pair(-36, 18),  Pair(-11, 19),  Pair(-11, -4),  Pair(8, -9),  Pair(11, -11),  Pair(4, -6),  Pair(11, 7),  Pair(-13, -4),
      Pair(-30, 12),  Pair(-10, 18),  Pair(-9, -4),  Pair(-2, 1),  Pair(13, 1),  Pair(4, -2),  Pair(33, 7),  Pair(0, -7),
      Pair(-33, 17),  Pair(-11, 22),  Pair(-20, 4),  Pair(-16, 8),  Pair(-4, 18),  Pair(18, 4),  Pair(42, 8),  Pair(-14, -6),
      Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0)
  },
  {
      Pair(-184, -62),  Pair(-156, 18),  Pair(-82, 37),  Pair(-42, 25),  Pair(0, 26),  Pair(-75, -2),  Pair(-128, 20),  Pair(-125, -88),
      Pair(-32, 25),  Pair(-4, 40),  Pair(32, 36),  Pair(56, 32),  Pair(25, 24),  Pair(106, 11),  Pair(-14, 36),  Pair(20, -1),
      Pair(-8, 32),  Pair(37, 40),  Pair(61, 63),  Pair(70, 64),  Pair(120, 44),  Pair(118, 36),  Pair(66, 30),  Pair(22, 19),
      Pair(-11, 47),  Pair(7, 62),  Pair(38, 79),  Pair(66, 79),  Pair(39, 80),  Pair(71, 75),  Pair(22, 60),  Pair(34, 34),
      Pair(-28, 47),  Pair(-6, 52),  Pair(16, 78),  Pair(19, 78),  Pair(32, 82),  Pair(23, 66),  Pair(19, 52),  Pair(-14, 35),
      Pair(-50, 22),  Pair(-22, 42),  Pair(-3, 51),  Pair(12, 70),  Pair(27, 65),  Pair(7, 43),  Pair(6, 31),  Pair(-27, 24),
      Pair(-58, 20),  Pair(-45, 36),  Pair(-27, 40),  Pair(-6, 40),  Pair(-7, 40),  Pair(-2, 35),  Pair(-23, 21),  Pair(-26, 26),
      Pair(-108, 14),  Pair(-40, 5),  Pair(-49, 29),  Pair(-28, 32),  Pair(-25, 32),  Pair(-18, 19),  Pair(-36, 8),  Pair(-69, 5)
  },
  {
      Pair(-19, 56),  Pair(-50, 66),  Pair(-44, 57),  Pair(-95, 70),  Pair(-75, 63),  Pair(-58, 52),  Pair(-19, 49),  Pair(-44, 50),
      Pair(0, 44),  Pair(26, 50),  Pair(13, 51),  Pair(-12, 53),  Pair(28, 40),  Pair(16, 43),  Pair(20, 53),  Pair(1, 39),
      Pair(10, 64),  Pair(36, 53),  Pair(34, 55),  Pair(55, 41),  Pair(35, 48),  Pair(81, 54),  Pair(55, 50),  Pair(46, 56),
      Pair(5, 59),  Pair(15, 62),  Pair(37, 56),  Pair(51, 70),  Pair(48, 61),  Pair(39, 60),  Pair(14, 59),  Pair(5, 58),
      Pair(2, 51),  Pair(9, 59),  Pair(9, 66),  Pair(41, 64),  Pair(36, 61),  Pair(11, 59),  Pair(7, 56),  Pair(16, 39),
      Pair(10, 51),  Pair(21, 59),  Pair(24, 60),  Pair(17, 59),  Pair(22, 64),  Pair(25, 57),  Pair(25, 49),  Pair(29, 39),
      Pair(19, 51),  Pair(26, 42),  Pair(30, 34),  Pair(10, 54),  Pair(22, 48),  Pair(37, 43),  Pair(44, 48),  Pair(25, 32),
      Pair(7, 43),  Pair(30, 55),  Pair(13, 47),  Pair(5, 53),  Pair(14, 53),  Pair(5, 58),  Pair(30, 36),  Pair(24, 25)
  },
  {
      Pair(16, 66),  Pair(-2, 76),  Pair(-2, 84),  Pair(-1, 78),  Pair(20, 67),  Pair(39, 65),  Pair(34, 63),  Pair(60, 56),
      Pair(-1, 72),  Pair(-5, 84),  Pair(17, 87),  Pair(41, 72),  Pair(23, 74),  Pair(58, 61),  Pair(47, 57),  Pair(87, 43),
      Pair(-26, 72),  Pair(2, 70),  Pair(-3, 72),  Pair(0, 67),  Pair(38, 52),  Pair(43, 47),  Pair(101, 36),  Pair(69, 33),
      Pair(-34, 76),  Pair(-24, 71),  Pair(-25, 79),  Pair(-14, 72),  Pair(-10, 56),  Pair(-2, 50),  Pair(11, 51),  Pair(14, 46),
      Pair(-47, 66),  Pair(-46, 67),  Pair(-37, 67),  Pair(-27, 64),  Pair(-24, 60),  Pair(-38, 58),  Pair(-9, 46),  Pair(-24, 45),
      Pair(-48, 59),  Pair(-44, 55),  Pair(-34, 54),  Pair(-27, 55),  Pair(-19, 48),  Pair(-20, 40),  Pair(14, 17),  Pair(-11, 23),
      Pair(-48, 52),  Pair(-39, 53),  Pair(-17, 52),  Pair(-16, 51),  Pair(-11, 42),  Pair(-7, 35),  Pair(9, 26),  Pair(-26, 35),
      Pair(-29, 46),  Pair(-23, 48),  Pair(-10, 53),  Pair(-1, 45),  Pair(3, 38),  Pair(-5, 42),  Pair(6, 29),  Pair(-25, 28)
  },
  {
      Pair(-23, 137),  Pair(-35, 157),  Pair(-9, 178),  Pair(31, 156),  Pair(34, 159),  Pair(42, 160),  Pair(87, 90),  Pair(18, 142),
      Pair(11, 126),  Pair(-16, 159),  Pair(-10, 191),  Pair(-22, 212),  Pair(-16, 236),  Pair(29, 190),  Pair(16, 176),  Pair(69, 163),
      Pair(12, 130),  Pair(8, 138),  Pair(-1, 180),  Pair(11, 186),  Pair(16, 203),  Pair(76, 181),  Pair(84, 145),  Pair(85, 144),
      Pair(-5, 142),  Pair(-5, 151),  Pair(-3, 165),  Pair(-4, 186),  Pair(-3, 201),  Pair(12, 193),  Pair(19, 187),  Pair(27, 175),
      Pair(-4, 131),  Pair(-8, 157),  Pair(-6, 153),  Pair(1, 177),  Pair(4, 171),  Pair(1, 171),  Pair(11, 161),  Pair(20, 157),
      Pair(0, 115),  Pair(5, 128),  Pair(5, 143),  Pair(2, 140),  Pair(8, 148),  Pair(12, 148),  Pair(25, 133),  Pair(21, 124),
      Pair(7, 107),  Pair(9, 107),  Pair(18, 105),  Pair(24, 111),  Pair(20, 118),  Pair(35, 88),  Pair(40, 58),  Pair(58, 28),
      Pair(4, 103),  Pair(8, 100),  Pair(18, 99),  Pair(20, 118),  Pair(23, 99),  Pair(5, 101),  Pair(33, 68),  Pair(19, 71)
  },
  {
      Pair(40, -116),  Pair(62, -60),  Pair(72, -41),  Pair(-85, 13),  Pair(-49, -3),  Pair(9, -2),  Pair(77, -14),  Pair(149, -141),
      Pair(-107, 1),  Pair(-54, 40),  Pair(-81, 48),  Pair(36, 29),  Pair(-30, 53),  Pair(-23, 68),  Pair(7, 56),  Pair(-25, 17),
      Pair(-141, 19),  Pair(1, 42),  Pair(-70, 64),  Pair(-99, 78),  Pair(-48, 80),  Pair(46, 70),  Pair(0, 68),  Pair(-41, 27),
      Pair(-99, 6),  Pair(-102, 47),  Pair(-122, 69),  Pair(-173, 84),  Pair(-160, 85),  Pair(-117, 78),  Pair(-116, 67),  Pair(-159, 33),
      Pair(-97, -8),  Pair(-94, 28),  Pair(-137, 58),  Pair(-173, 77),  Pair(-166, 75),  Pair(-121, 59),  Pair(-128, 43),  Pair(-166, 23),
      Pair(-36, -20),  Pair(-17, 7),  Pair(-87, 35),  Pair(-101, 49),  Pair(-94, 49),  Pair(-93, 36),  Pair(-39, 11),  Pair(-58, -6),
      Pair(70, -46),  Pair(17, -11),  Pair(2, 3),  Pair(-40, 16),  Pair(-43, 19),  Pair(-19, 6),  Pair(37, -18),  Pair(47, -43),
      Pair(65, -95),  Pair(97, -69),  Pair(66, -44),  Pair(-48, -20),  Pair(21, -47),  Pair(-14, -26),  Pair(72, -63),  Pair(74, -102)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(17, 86),  Pair(34, 85),  Pair(41, 92),  Pair(45, 89),  Pair(48, 97),  Pair(46, 103),  Pair(44, 104),  Pair(43, 104),
  Pair(45, 101)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-7, -5),  Pair(3, 16),  Pair(13, 28),  Pair(15, 41),  Pair(24, 58),  Pair(33, 75),  Pair(40, 81),  Pair(45, 89),
  Pair(46, 98),  Pair(48, 97),  Pair(51, 96),  Pair(56, 97),  Pair(51, 107),  Pair(87, 83)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-9, 37),  Pair(2, 59),  Pair(8, 59),  Pair(14, 63),  Pair(13, 72),  Pair(21, 75),  Pair(25, 79),  Pair(34, 79),
  Pair(37, 91),  Pair(44, 95),  Pair(50, 98),  Pair(55, 102),  Pair(56, 107),  Pair(63, 111),  Pair(65, 106)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-3, 24),  Pair(-12, 70),  Pair(-22, 151),  Pair(-19, 168),  Pair(-16, 172),  Pair(-13, 179),  Pair(-8, 186),  Pair(-10, 211),
  Pair(-7, 221),  Pair(-5, 225),  Pair(-3, 237),  Pair(-3, 246),  Pair(-2, 256),  Pair(-1, 264),  Pair(0, 269),  Pair(1, 277),
  Pair(5, 283),  Pair(1, 294),  Pair(6, 301),  Pair(9, 301),  Pair(22, 296),  Pair(26, 297),  Pair(28, 298),  Pair(35, 298),
  Pair(61, 275),  Pair(126, 253),  Pair(138, 244),  Pair(257, 192)
};

constexpr PassedPawnTable<ScorePair> kPassedPawn = {
  Pair(0, 0),  Pair(-14, -4),  Pair(-23, 5),  Pair(-16, 33),  Pair(8, 64),  Pair(0, 141),  Pair(30, 192),  Pair(0, 0)
};

constexpr std::array<ScorePair, 8> kPawnPhalanxBonus = {
  Pair(0, 0),  Pair(3, -2),  Pair(2, 4),  Pair(21, 22),  Pair(49, 77),  Pair(145, 251),  Pair(43, 416),  Pair(0, 0)
};

constexpr ScorePair kTempoBonus = Pair(24, 29);

constexpr std::array<int, PieceType::kNumTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_EVAL_TERMS_H