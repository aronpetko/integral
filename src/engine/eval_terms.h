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
  Pair(96, 128),  Pair(269, 260),  Pair(249, 247),  Pair(303, 427),  Pair(595, 764),  Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {
      Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0),
      Pair(58, 213),  Pair(111, 194),  Pair(70, 193),  Pair(120, 95),  Pair(91, 93),  Pair(50, 127),  Pair(-55, 198),  Pair(-106, 227),
      Pair(44, 138),  Pair(71, 143),  Pair(114, 65),  Pair(116, 4),  Pair(130, -3),  Pair(180, 33),  Pair(146, 104),  Pair(77, 106),
      Pair(13, 114),  Pair(53, 100),  Pair(48, 64),  Pair(58, 34),  Pair(92, 32),  Pair(77, 47),  Pair(91, 81),  Pair(51, 73),
      Pair(1, 87),  Pair(39, 90),  Pair(40, 56),  Pair(66, 48),  Pair(68, 47),  Pair(60, 53),  Pair(69, 74),  Pair(31, 56),
      Pair(4, 75),  Pair(33, 85),  Pair(33, 54),  Pair(43, 61),  Pair(65, 60),  Pair(53, 57),  Pair(92, 68),  Pair(47, 49),
      Pair(3, 81),  Pair(35, 87),  Pair(21, 61),  Pair(25, 69),  Pair(45, 80),  Pair(75, 63),  Pair(109, 64),  Pair(29, 48),
      Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0),  Pair(0, 0)
  },
  {
      Pair(-170, 8),  Pair(-124, 115),  Pair(-21, 142),  Pair(33, 124),  Pair(94, 124),  Pair(-14, 87),  Pair(-88, 117),  Pair(-83, -32),
      Pair(48, 124),  Pair(88, 143),  Pair(138, 139),  Pair(172, 133),  Pair(128, 121),  Pair(244, 102),  Pair(74, 139),  Pair(120, 87),
      Pair(80, 134),  Pair(144, 144),  Pair(180, 176),  Pair(193, 178),  Pair(265, 149),  Pair(262, 137),  Pair(186, 129),  Pair(124, 114),
      Pair(77, 154),  Pair(104, 176),  Pair(147, 198),  Pair(187, 198),  Pair(148, 201),  Pair(194, 193),  Pair(123, 172),  Pair(140, 136),
      Pair(54, 153),  Pair(84, 163),  Pair(117, 197),  Pair(122, 199),  Pair(140, 204),  Pair(127, 182),  Pair(118, 162),  Pair(74, 137),
      Pair(22, 120),  Pair(63, 146),  Pair(90, 160),  Pair(110, 188),  Pair(132, 180),  Pair(103, 148),  Pair(101, 134),  Pair(56, 123),
      Pair(10, 116),  Pair(30, 138),  Pair(56, 145),  Pair(84, 145),  Pair(84, 145),  Pair(90, 137),  Pair(60, 118),  Pair(55, 125),
      Pair(-58, 109),  Pair(37, 93),  Pair(25, 129),  Pair(54, 133),  Pair(58, 132),  Pair(68, 113),  Pair(43, 100),  Pair(-3, 95)
  },
  {
      Pair(96, 192),  Pair(52, 206),  Pair(59, 193),  Pair(-13, 212),  Pair(18, 201),  Pair(40, 185),  Pair(94, 183),  Pair(60, 183),
      Pair(122, 175),  Pair(159, 181),  Pair(141, 183),  Pair(106, 185),  Pair(162, 169),  Pair(146, 173),  Pair(152, 185),  Pair(122, 168),
      Pair(135, 204),  Pair(172, 186),  Pair(169, 188),  Pair(199, 170),  Pair(172, 179),  Pair(237, 187),  Pair(200, 183),  Pair(187, 192),
      Pair(127, 195),  Pair(142, 199),  Pair(174, 190),  Pair(193, 209),  Pair(188, 198),  Pair(176, 196),  Pair(142, 196),  Pair(128, 194),
      Pair(124, 184),  Pair(134, 197),  Pair(134, 205),  Pair(181, 202),  Pair(173, 199),  Pair(138, 197),  Pair(131, 192),  Pair(144, 167),
      Pair(134, 184),  Pair(150, 196),  Pair(156, 198),  Pair(147, 196),  Pair(154, 203),  Pair(157, 193),  Pair(156, 183),  Pair(162, 168),
      Pair(145, 186),  Pair(157, 173),  Pair(164, 161),  Pair(135, 189),  Pair(151, 181),  Pair(173, 172),  Pair(183, 182),  Pair(155, 158),
      Pair(132, 173),  Pair(164, 190),  Pair(140, 179),  Pair(128, 188),  Pair(141, 188),  Pair(128, 195),  Pair(165, 162),  Pair(154, 147)
  },
  {
      Pair(204, 347),  Pair(177, 361),  Pair(179, 373),  Pair(181, 364),  Pair(210, 349),  Pair(233, 347),  Pair(226, 346),  Pair(265, 333),
      Pair(180, 355),  Pair(173, 374),  Pair(205, 377),  Pair(239, 357),  Pair(213, 359),  Pair(263, 341),  Pair(247, 336),  Pair(302, 315),
      Pair(145, 357),  Pair(184, 354),  Pair(178, 356),  Pair(182, 349),  Pair(235, 328),  Pair(242, 320),  Pair(320, 306),  Pair(277, 301),
      Pair(133, 362),  Pair(148, 355),  Pair(146, 366),  Pair(163, 356),  Pair(166, 333),  Pair(178, 326),  Pair(195, 327),  Pair(200, 319),
      Pair(114, 350),  Pair(115, 351),  Pair(130, 352),  Pair(145, 346),  Pair(147, 341),  Pair(128, 339),  Pair(167, 321),  Pair(147, 320),
      Pair(114, 339),  Pair(118, 335),  Pair(135, 333),  Pair(143, 335),  Pair(156, 324),  Pair(152, 313),  Pair(200, 280),  Pair(165, 290),
      Pair(114, 329),  Pair(126, 331),  Pair(157, 329),  Pair(158, 329),  Pair(167, 316),  Pair(172, 307),  Pair(193, 293),  Pair(145, 306),
      Pair(141, 322),  Pair(149, 324),  Pair(168, 331),  Pair(179, 321),  Pair(186, 310),  Pair(174, 314),  Pair(188, 298),  Pair(146, 298)
  },
  {
      Pair(376, 640),  Pair(362, 665),  Pair(402, 689),  Pair(456, 661),  Pair(457, 668),  Pair(482, 657),  Pair(532, 570),  Pair(433, 645),
      Pair(423, 625),  Pair(386, 668),  Pair(394, 712),  Pair(379, 742),  Pair(387, 772),  Pair(451, 710),  Pair(432, 690),  Pair(506, 674),
      Pair(424, 630),  Pair(418, 640),  Pair(408, 694),  Pair(426, 702),  Pair(433, 727),  Pair(518, 693),  Pair(528, 645),  Pair(528, 644),
      Pair(399, 646),  Pair(402, 656),  Pair(405, 674),  Pair(404, 702),  Pair(406, 723),  Pair(426, 712),  Pair(435, 705),  Pair(446, 688),
      Pair(403, 626),  Pair(398, 663),  Pair(400, 657),  Pair(413, 690),  Pair(415, 680),  Pair(411, 682),  Pair(424, 667),  Pair(436, 665),
      Pair(407, 606),  Pair(414, 622),  Pair(417, 642),  Pair(412, 639),  Pair(421, 651),  Pair(425, 651),  Pair(443, 629),  Pair(437, 619),
      Pair(418, 593),  Pair(421, 593),  Pair(434, 589),  Pair(441, 599),  Pair(435, 609),  Pair(457, 567),  Pair(463, 524),  Pair(489, 483),
      Pair(415, 587),  Pair(418, 584),  Pair(433, 581),  Pair(437, 608),  Pair(439, 581),  Pair(415, 585),  Pair(454, 540),  Pair(435, 543)
  },
  {
      Pair(47, -144),  Pair(70, -62),  Pair(86, -37),  Pair(-133, 42),  Pair(-78, 19),  Pair(5, 18),  Pair(98, -3),  Pair(238, -185),
      Pair(-159, 23),  Pair(-86, 78),  Pair(-127, 90),  Pair(36, 62),  Pair(-52, 97),  Pair(-47, 118),  Pair(-1, 100),  Pair(-45, 45),
      Pair(-208, 49),  Pair(-11, 80),  Pair(-108, 111),  Pair(-148, 131),  Pair(-81, 133),  Pair(52, 118),  Pair(-14, 118),  Pair(-69, 60),
      Pair(-148, 30),  Pair(-153, 88),  Pair(-182, 121),  Pair(-252, 141),  Pair(-237, 143),  Pair(-176, 133),  Pair(-173, 117),  Pair(-232, 70),
      Pair(-151, 12),  Pair(-146, 63),  Pair(-204, 106),  Pair(-254, 134),  Pair(-246, 131),  Pair(-182, 106),  Pair(-192, 84),  Pair(-245, 57),
      Pair(-65, -6),  Pair(-39, 34),  Pair(-135, 72),  Pair(-155, 93),  Pair(-143, 91),  Pair(-142, 75),  Pair(-67, 39),  Pair(-94, 17),
      Pair(87, -42),  Pair(11, 7),  Pair(-12, 27),  Pair(-70, 44),  Pair(-74, 50),  Pair(-40, 31),  Pair(37, -2),  Pair(53, -37),
      Pair(77, -109),  Pair(124, -75),  Pair(80, -40),  Pair(-82, -6),  Pair(15, -45),  Pair(-35, -14),  Pair(87, -66),  Pair(89, -119)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(111, 220),  Pair(138, 215),  Pair(148, 226),  Pair(153, 221),  Pair(157, 229),  Pair(154, 238),  Pair(151, 241),  Pair(150, 241),
  Pair(153, 235)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(119, 116),  Pair(133, 146),  Pair(146, 160),  Pair(151, 180),  Pair(163, 204),  Pair(174, 228),  Pair(184, 235),  Pair(190, 247),
  Pair(191, 261),  Pair(194, 258),  Pair(198, 257),  Pair(204, 258),  Pair(198, 271),  Pair(247, 237)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(172, 325),  Pair(188, 355),  Pair(196, 355),  Pair(204, 361),  Pair(204, 373),  Pair(215, 378),  Pair(221, 382),  Pair(232, 385),
  Pair(238, 400),  Pair(247, 405),  Pair(255, 408),  Pair(263, 415),  Pair(264, 423),  Pair(275, 426),  Pair(277, 420)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(520, 247),  Pair(503, 414),  Pair(488, 535),  Pair(493, 560),  Pair(497, 565),  Pair(502, 576),  Pair(510, 585),  Pair(507, 623),
  Pair(510, 636),  Pair(514, 643),  Pair(515, 662),  Pair(515, 674),  Pair(517, 689),  Pair(518, 700),  Pair(521, 710),  Pair(522, 720),
  Pair(526, 727),  Pair(522, 745),  Pair(527, 755),  Pair(531, 755),  Pair(549, 751),  Pair(556, 752),  Pair(558, 754),  Pair(569, 752),
  Pair(606, 721),  Pair(703, 685),  Pair(676, 700),  Pair(704, 710)
};

constexpr PassedPawnTable<ScorePair> kPassedPawn = {
  Pair(0, 0),  Pair(-22, -6),  Pair(-31, 4),  Pair(-26, 43),  Pair(12, 89),  Pair(0, 204),  Pair(76, 209),  Pair(0, 0)
};

constexpr ScorePair kTempoBonus = Pair(35, 40);
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