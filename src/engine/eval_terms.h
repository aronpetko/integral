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
  Pair(100, 130),  Pair(315, 328),  Pair(345, 348),  Pair(464, 687),  Pair(1005, 1150),  Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0),
      Pair(31, 70),  Pair(69, 57),  Pair(40, 56),  Pair(76, -13),  Pair(55, -14),  Pair(26, 9),  Pair(-48, 60),  Pair(-85, 80),
      Pair(-2, 59),  Pair(17, 63),  Pair(48, 8),  Pair(49, -35),  Pair(59, -41),  Pair(95, -14),  Pair(70, 36),  Pair(21, 38),
      Pair(-23, 42),  Pair(5, 34),  Pair(2, 7),  Pair(8, -14),  Pair(32, -15),  Pair(21, -5),  Pair(30, 20),  Pair(3, 14),
      Pair(-32, 23),  Pair(-5, 26),  Pair(-5, 2),  Pair(14, -4),  Pair(15, -4),  Pair(9, 0),  Pair(15, 15),  Pair(-11, 3),
      Pair(-30, 15),  Pair(-10, 23),  Pair(-10, 0),  Pair(-3, 5),  Pair(13, 5),  Pair(4, 2),  Pair(32, 10),  Pair(0, -3),
      Pair(-31, 19),  Pair(-9, 24),  Pair(-18, 5),  Pair(-15, 10),  Pair(-1, 19),  Pair(20, 6),  Pair(44, 8),  Pair(-12, -3),
      Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0)
  },
  {
      Pair(-183, -63),  Pair(-152, 15),  Pair(-80, 34),  Pair(-42, 22),  Pair(1, 23),  Pair(-74, -4),  Pair(-127, 16),  Pair(-123, -90),
      Pair(-31, 22),  Pair(-3, 36),  Pair(32, 34),  Pair(56, 29),  Pair(25, 21),  Pair(107, 8),  Pair(-13, 33),  Pair(20, -4),
      Pair(-9, 30),  Pair(37, 37),  Pair(62, 60),  Pair(71, 61),  Pair(122, 41),  Pair(120, 33),  Pair(66, 27),  Pair(22, 15),
      Pair(-10, 44),  Pair(8, 59),  Pair(38, 76),  Pair(67, 76),  Pair(39, 78),  Pair(72, 72),  Pair(22, 57),  Pair(34, 32),
      Pair(-27, 43),  Pair(-6, 51),  Pair(18, 75),  Pair(21, 76),  Pair(34, 79),  Pair(24, 64),  Pair(18, 49),  Pair(-13, 32),
      Pair(-50, 19),  Pair(-21, 38),  Pair(-2, 48),  Pair(13, 68),  Pair(28, 63),  Pair(8, 40),  Pair(6, 30),  Pair(-26, 22),
      Pair(-58, 17),  Pair(-44, 32),  Pair(-26, 38),  Pair(-6, 37),  Pair(-6, 38),  Pair(-1, 32),  Pair(-23, 18),  Pair(-27, 23),
      Pair(-106, 12),  Pair(-39, 0),  Pair(-48, 26),  Pair(-27, 29),  Pair(-24, 28),  Pair(-17, 15),  Pair(-34, 5),  Pair(-67, 2)
  },
  {
      Pair(-18, 53),  Pair(-49, 64),  Pair(-44, 54),  Pair(-95, 67),  Pair(-74, 60),  Pair(-58, 49),  Pair(-19, 47),  Pair(-43, 47),
      Pair(1, 42),  Pair(27, 46),  Pair(15, 48),  Pair(-10, 49),  Pair(30, 37),  Pair(18, 40),  Pair(22, 49),  Pair(1, 37),
      Pair(10, 62),  Pair(36, 49),  Pair(34, 51),  Pair(55, 38),  Pair(36, 45),  Pair(81, 51),  Pair(56, 48),  Pair(46, 54),
      Pair(4, 56),  Pair(15, 59),  Pair(38, 52),  Pair(51, 66),  Pair(48, 58),  Pair(39, 57),  Pair(15, 56),  Pair(5, 55),
      Pair(2, 48),  Pair(9, 57),  Pair(9, 63),  Pair(43, 61),  Pair(37, 59),  Pair(12, 57),  Pair(7, 54),  Pair(16, 36),
      Pair(10, 48),  Pair(20, 57),  Pair(25, 58),  Pair(18, 57),  Pair(23, 61),  Pair(25, 55),  Pair(25, 47),  Pair(29, 36),
      Pair(16, 49),  Pair(26, 40),  Pair(31, 32),  Pair(9, 52),  Pair(22, 46),  Pair(37, 40),  Pair(44, 47),  Pair(24, 30),
      Pair(8, 41),  Pair(30, 53),  Pair(14, 45),  Pair(5, 51),  Pair(14, 51),  Pair(5, 56),  Pair(31, 33),  Pair(24, 23)
  },
  {
      Pair(16, 66),  Pair(-3, 75),  Pair(-2, 84),  Pair(-1, 78),  Pair(20, 67),  Pair(38, 65),  Pair(32, 64),  Pair(59, 55),
      Pair(-1, 70),  Pair(-6, 84),  Pair(17, 87),  Pair(41, 72),  Pair(23, 74),  Pair(58, 61),  Pair(47, 58),  Pair(86, 43),
      Pair(-26, 72),  Pair(2, 71),  Pair(-2, 72),  Pair(0, 66),  Pair(38, 52),  Pair(43, 46),  Pair(99, 37),  Pair(68, 33),
      Pair(-34, 76),  Pair(-24, 71),  Pair(-25, 78),  Pair(-13, 71),  Pair(-11, 55),  Pair(-2, 50),  Pair(10, 51),  Pair(14, 46),
      Pair(-48, 66),  Pair(-47, 68),  Pair(-37, 68),  Pair(-26, 64),  Pair(-24, 60),  Pair(-38, 59),  Pair(-10, 46),  Pair(-24, 46),
      Pair(-48, 59),  Pair(-44, 56),  Pair(-33, 55),  Pair(-27, 57),  Pair(-18, 49),  Pair(-20, 41),  Pair(13, 17),  Pair(-11, 24),
      Pair(-48, 52),  Pair(-39, 53),  Pair(-17, 52),  Pair(-16, 52),  Pair(-10, 43),  Pair(-7, 37),  Pair(9, 27),  Pair(-25, 36),
      Pair(-29, 47),  Pair(-23, 49),  Pair(-10, 54),  Pair(-1, 46),  Pair(3, 39),  Pair(-5, 42),  Pair(5, 31),  Pair(-24, 30)
  },
  {
      Pair(-24, 137),  Pair(-35, 156),  Pair(-8, 175),  Pair(30, 156),  Pair(33, 158),  Pair(43, 157),  Pair(84, 91),  Pair(16, 142),
      Pair(10, 126),  Pair(-16, 158),  Pair(-10, 190),  Pair(-22, 211),  Pair(-16, 232),  Pair(29, 189),  Pair(16, 174),  Pair(69, 162),
      Pair(11, 130),  Pair(7, 138),  Pair(-1, 178),  Pair(11, 184),  Pair(16, 201),  Pair(76, 178),  Pair(84, 143),  Pair(84, 141),
      Pair(-6, 141),  Pair(-5, 150),  Pair(-3, 164),  Pair(-4, 184),  Pair(-2, 199),  Pair(12, 190),  Pair(18, 185),  Pair(26, 173),
      Pair(-5, 129),  Pair(-8, 156),  Pair(-7, 151),  Pair(2, 175),  Pair(4, 168),  Pair(1, 169),  Pair(10, 158),  Pair(19, 156),
      Pair(-1, 115),  Pair(4, 127),  Pair(6, 141),  Pair(2, 139),  Pair(8, 147),  Pair(11, 147),  Pair(24, 132),  Pair(20, 123),
      Pair(7, 106),  Pair(9, 106),  Pair(17, 104),  Pair(23, 110),  Pair(19, 117),  Pair(34, 87),  Pair(39, 57),  Pair(57, 28),
      Pair(4, 102),  Pair(7, 99),  Pair(17, 99),  Pair(20, 117),  Pair(22, 98),  Pair(4, 100),  Pair(32, 67),  Pair(19, 70)
  },
  {
      Pair(32, -115),  Pair(56, -59),  Pair(68, -41),  Pair(-87, 14),  Pair(-51, -2),  Pair(6, -2),  Pair(73, -16),  Pair(135, -138),
      Pair(-107, 0),  Pair(-55, 39),  Pair(-85, 48),  Pair(33, 29),  Pair(-32, 53),  Pair(-28, 68),  Pair(5, 56),  Pair(-28, 16),
      Pair(-142, 19),  Pair(-2, 41),  Pair(-72, 63),  Pair(-101, 77),  Pair(-52, 79),  Pair(44, 69),  Pair(-4, 68),  Pair(-43, 26),
      Pair(-100, 6),  Pair(-104, 47),  Pair(-126, 70),  Pair(-176, 85),  Pair(-165, 86),  Pair(-120, 79),  Pair(-119, 67),  Pair(-161, 34),
      Pair(-102, -8),  Pair(-99, 29),  Pair(-140, 60),  Pair(-176, 78),  Pair(-170, 77),  Pair(-125, 59),  Pair(-132, 44),  Pair(-169, 25),
      Pair(-40, -20),  Pair(-22, 8),  Pair(-91, 36),  Pair(-106, 50),  Pair(-97, 49),  Pair(-96, 37),  Pair(-42, 12),  Pair(-61, -4),
      Pair(67, -45),  Pair(13, -11),  Pair(-4, 4),  Pair(-44, 16),  Pair(-47, 20),  Pair(-22, 7),  Pair(32, -17),  Pair(44, -42),
      Pair(60, -93),  Pair(93, -69),  Pair(62, -44),  Pair(-52, -20),  Pair(17, -47),  Pair(-19, -26),  Pair(68, -62),  Pair(69, -100)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(15, 82),  Pair(33, 78),  Pair(40, 86),  Pair(44, 83),  Pair(47, 89),  Pair(45, 95),  Pair(43, 97),  Pair(41, 98),
  Pair(44, 93)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-4, -4),  Pair(7, 17),  Pair(16, 27),  Pair(19, 42),  Pair(27, 59),  Pair(35, 76),  Pair(42, 81),  Pair(47, 90),
  Pair(47, 100),  Pair(49, 98),  Pair(52, 97),  Pair(56, 98),  Pair(51, 107),  Pair(87, 83)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-9, 35),  Pair(2, 55),  Pair(8, 56),  Pair(13, 60),  Pair(13, 69),  Pair(21, 72),  Pair(25, 75),  Pair(34, 78),
  Pair(37, 88),  Pair(44, 92),  Pair(49, 94),  Pair(54, 99),  Pair(56, 105),  Pair(63, 107),  Pair(65, 102)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-5, 19),  Pair(-14, 65),  Pair(-24, 148),  Pair(-20, 165),  Pair(-18, 169),  Pair(-14, 176),  Pair(-9, 181),  Pair(-11, 208),
  Pair(-8, 217),  Pair(-5, 222),  Pair(-5, 235),  Pair(-5, 243),  Pair(-4, 254),  Pair(-3, 261),  Pair(-1, 268),  Pair(0, 274),
  Pair(3, 279),  Pair(0, 292),  Pair(4, 299),  Pair(7, 297),  Pair(19, 294),  Pair(24, 295),  Pair(26, 296),  Pair(33, 294),
  Pair(60, 273),  Pair(127, 248),  Pair(142, 235),  Pair(263, 185)
};

constexpr PassedPawnTable<ScorePair> kPassedPawn = {
  Pair(0, 0),  Pair(-15, -4),  Pair(-22, 3),  Pair(-18, 31),  Pair(8, 63),  Pair(-1, 145),  Pair(29, 192),  Pair(0, 0)
};

constexpr ScorePair kTempoBonus = Pair(25, 28);
// clang-format on

constexpr std::array<int, PieceType::kNumTypes> kGamePhaseIncrements = {
    0, 1, 1, 2, 4, 0};

template <typename T>
using TraceTerm = std::array<T, 2>;

// A struct that counts the amount of times each term is used, and by which side
struct EvalTrace {
  // The names, though they are not constant, must match the above names (for
  // ease of use with the tuner)
  PieceValueTable<TraceTerm<I16>> kPieceValues{};
  PieceSquareTable<TraceTerm<I16>> kPieceSquareTable{};
  KnightMobilityTable<TraceTerm<I16>> kKnightMobility{};
  BishopMobilityTable<TraceTerm<I16>> kBishopMobility{};
  RookMobilityTable<TraceTerm<I16>> kRookMobility{};
  QueenMobilityTable<TraceTerm<I16>> kQueenMobility{};
  PassedPawnTable<TraceTerm<I16>> kPassedPawn{};
  TraceTerm<I16> kTempoBonus{};
  Score eval{};
};

inline EvalTrace trace;

// #define TUNE

#ifdef TUNE
#define TRACE_ADD(term, count, color) trace.term[color] += count
#define TRACE_INCREMENT(term, color) trace.term[color]++
#define TRACE_SCALE(s) trace.scale = s
#define TRACE_EVAL(e) trace.eval = e
#else
#define TRACE_ADD(term, count, color)
#define TRACE_INCREMENT(term, color)
#define TRACE_SCALE(s)
#define TRACE_EVAL(e)
#endif

}  // namespace eval

#endif  // INTEGRAL_EVAL_TERMS_H