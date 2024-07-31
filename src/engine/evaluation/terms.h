#ifndef INTEGRAL_TERMS_H
#define INTEGRAL_TERMS_H

#include "../../utils/types.h"

namespace eval {

// clang-format off
constexpr int kNumKingBuckets = 7;

template <typename T>
using KingBuckets = std::array<T, kNumKingBuckets>;

constexpr SquareTable<int> kKingBucketLayout = {
  6, 6, 6, 6, 6, 6, 6, 6,
  6, 6, 6, 6, 6, 6, 6, 6,
  5, 5, 5, 5, 5, 5, 5, 5,
  5, 5, 5, 5, 5, 5, 5, 5,
  4, 4, 4, 4, 4, 4, 4, 4,
  3, 3, 3, 3, 3, 3, 3, 3,
  2, 2, 2, 2, 2, 2, 2, 2,
  0, 0, 1, 1, 1, 1, 0, 0
};

template <typename T>
using PieceTable = KingBuckets<std::array<T, kNumPieceTypes>>;

template <typename T>
using PieceSquareTable = PieceTable<SquareTable<T>>;

template <typename T>
using KnightMobilityTable = KingBuckets<std::array<T, 9>>;

template <typename T>
using RookMobilityTable = KingBuckets<std::array<T, 15>>;

template <typename T>
using BishopMobilityTable = KingBuckets<std::array<T, 14>>;

template <typename T>
using QueenMobilityTable = KingBuckets<std::array<T, 28>>;

template <typename T>
using RankTable = std::array<T, kNumRanks>;

template <typename T>
using FileTable = std::array<T, kNumFiles>;

template <typename T>
using OutpostTable = KingBuckets<std::array<T, 24>>;

constexpr PieceTable<ScorePair> kPieceValues = {{
  {
      Pair(90, 164), Pair(407, 424), Pair(430, 473), Pair(544, 850), Pair(1052, 1611), Pair(0, 0)
  },
  {
      Pair(74, 107), Pair(199, 270), Pair(203, 294), Pair(224, 488), Pair(450, 1095), Pair(0, 0)
  },
  {
      Pair(46, 84), Pair(187, 249), Pair(195, 264), Pair(203, 402), Pair(437, 888), Pair(0, 0)
  },
  {
      Pair(53, 83), Pair(190, 264), Pair(208, 270), Pair(205, 428), Pair(481, 1095), Pair(0, 0)
  },
  {
      Pair(39, 113), Pair(153, 239), Pair(194, 248), Pair(167, 385), Pair(490, 1151), Pair(0, 0)
  },
  {
      Pair(32, 115), Pair(165, 212), Pair(175, 222), Pair(96, 356), Pair(316, 1005), Pair(0, 0)
  },
  {
      Pair(115, 129), Pair(263, 307), Pair(343, 326), Pair(252, 494), Pair(561, 1199), Pair(0, 0)
  }
}};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {{ // Bucket 0
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(-22, 92), Pair(-51, 105), Pair(-20, 27), Pair(6, -14), Pair(47, -51), Pair(45, -41), Pair(-63, -8), Pair(-87, 70),
      Pair(9, 77), Pair(4, 62), Pair(44, 11), Pair(59, -49), Pair(82, -50), Pair(135, -52), Pair(78, 17), Pair(52, 41),
      Pair(-16, 32), Pair(4, 11), Pair(5, -8), Pair(5, -31), Pair(40, -44), Pair(48, -52), Pair(19, -6), Pair(26, -16),
      Pair(-20, -1), Pair(-10, 2), Pair(-1, -19), Pair(13, -26), Pair(20, -32), Pair(39, -51), Pair(14, -20), Pair(27, -38),
      Pair(-35, -5), Pair(-23, -10), Pair(-15, -16), Pair(-7, -15), Pair(6, -14), Pair(4, -32), Pair(-2, -23), Pair(17, -46),
      Pair(-20, 4), Pair(-9, 5), Pair(-8, 3), Pair(0, -12), Pair(11, 16), Pair(25, -10), Pair(17, 1), Pair(4, -35),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-173, -3), Pair(-173, 83), Pair(-91, 50), Pair(-63, 39), Pair(-52, 42), Pair(-32, -43), Pair(-160, 22), Pair(-95, -87),
      Pair(-29, 52), Pair(-21, 87), Pair(-5, 64), Pair(-1, 65), Pair(7, 34), Pair(63, 30), Pair(41, 13), Pair(-6, -2),
      Pair(-11, 70), Pair(3, 77), Pair(10, 84), Pair(24, 66), Pair(47, 44), Pair(108, 5), Pair(17, 36), Pair(35, 4),
      Pair(12, 78), Pair(23, 76), Pair(45, 75), Pair(57, 85), Pair(48, 86), Pair(64, 72), Pair(34, 86), Pair(50, 38),
      Pair(-11, 70), Pair(26, 60), Pair(36, 83), Pair(42, 80), Pair(43, 87), Pair(59, 54), Pair(37, 75), Pair(12, 64),
      Pair(-32, 51), Pair(-3, 60), Pair(9, 70), Pair(24, 87), Pair(42, 81), Pair(24, 64), Pair(23, 58), Pair(0, 61),
      Pair(-44, 43), Pair(-26, 59), Pair(-11, 53), Pair(11, 61), Pair(11, 63), Pair(8, 39), Pair(8, 49), Pair(1, 68),
      Pair(-71, 18), Pair(-27, 45), Pair(-27, 48), Pair(-2, 46), Pair(5, 59), Pair(10, 43), Pair(-22, 45), Pair(-30, 30)
    },
    {
      Pair(-29, 87), Pair(-81, 72), Pair(-71, 55), Pair(-138, 78), Pair(-114, 61), Pair(-60, 16), Pair(-106, 107), Pair(-33, 28),
      Pair(-30, 62), Pair(-16, 75), Pair(-3, 49), Pair(-26, 64), Pair(-20, 35), Pair(-22, 55), Pair(-73, 78), Pair(-48, 40),
      Pair(-1, 73), Pair(6, 69), Pair(-5, 65), Pair(-2, 42), Pair(-18, 54), Pair(36, 75), Pair(23, 67), Pair(5, 83),
      Pair(-23, 74), Pair(-2, 72), Pair(5, 62), Pair(9, 85), Pair(17, 50), Pair(22, 57), Pair(-2, 66), Pair(-14, 66),
      Pair(-14, 69), Pair(-19, 58), Pair(-6, 73), Pair(13, 47), Pair(10, 51), Pair(4, 51), Pair(-12, 65), Pair(8, 36),
      Pair(-13, 47), Pair(13, 76), Pair(9, 69), Pair(4, 74), Pair(9, 88), Pair(16, 71), Pair(25, 51), Pair(21, 51),
      Pair(9, 46), Pair(9, 33), Pair(20, 38), Pair(-2, 60), Pair(13, 61), Pair(27, 68), Pair(46, 55), Pair(30, 38),
      Pair(6, 29), Pair(35, 36), Pair(3, 47), Pair(0, 47), Pair(20, 45), Pair(26, 62), Pair(33, 44), Pair(51, -12)
    },
    {
      Pair(54, 124), Pair(54, 140), Pair(44, 146), Pair(33, 145), Pair(74, 121), Pair(56, 137), Pair(86, 138), Pair(1, 144),
      Pair(35, 131), Pair(43, 147), Pair(55, 146), Pair(68, 135), Pair(43, 130), Pair(64, 130), Pair(118, 109), Pair(63, 124),
      Pair(26, 132), Pair(79, 129), Pair(61, 131), Pair(62, 119), Pair(94, 104), Pair(120, 93), Pair(190, 60), Pair(75, 99),
      Pair(46, 125), Pair(56, 137), Pair(71, 127), Pair(64, 119), Pair(76, 105), Pair(76, 113), Pair(98, 101), Pair(48, 104),
      Pair(23, 119), Pair(24, 143), Pair(38, 117), Pair(42, 124), Pair(41, 115), Pair(18, 129), Pair(74, 99), Pair(31, 100),
      Pair(8, 120), Pair(21, 123), Pair(30, 117), Pair(27, 122), Pair(41, 106), Pair(37, 105), Pair(89, 67), Pair(53, 58),
      Pair(9, 103), Pair(15, 125), Pair(39, 105), Pair(37, 117), Pair(45, 99), Pair(42, 94), Pair(80, 75), Pair(15, 71),
      Pair(22, 121), Pair(32, 112), Pair(38, 109), Pair(45, 106), Pair(51, 97), Pair(45, 109), Pair(47, 100), Pair(-10, 113)
    },
    {
      Pair(42, 179), Pair(40, 185), Pair(65, 179), Pair(111, 142), Pair(92, 154), Pair(76, 202), Pair(149, 115), Pair(96, 166),
      Pair(62, 178), Pair(61, 183), Pair(62, 220), Pair(58, 206), Pair(23, 264), Pair(65, 240), Pair(63, 219), Pair(139, 175),
      Pair(72, 179), Pair(71, 190), Pair(70, 217), Pair(69, 230), Pair(67, 236), Pair(103, 242), Pair(112, 213), Pair(98, 187),
      Pair(62, 193), Pair(80, 191), Pair(78, 203), Pair(68, 229), Pair(74, 242), Pair(104, 183), Pair(96, 219), Pair(105, 175),
      Pair(62, 182), Pair(57, 216), Pair(64, 213), Pair(64, 235), Pair(80, 211), Pair(67, 210), Pair(93, 183), Pair(91, 180),
      Pair(66, 166), Pair(68, 190), Pair(64, 217), Pair(60, 214), Pair(64, 217), Pair(78, 193), Pair(102, 167), Pair(98, 119),
      Pair(69, 148), Pair(71, 163), Pair(73, 171), Pair(74, 191), Pair(81, 172), Pair(93, 129), Pair(99, 117), Pair(108, 59),
      Pair(58, 177), Pair(61, 168), Pair(68, 162), Pair(71, 163), Pair(79, 138), Pair(71, 122), Pair(71, 82), Pair(44, 161)
    },
    {
      Pair(1338, -82), Pair(1371, 12), Pair(1275, 31), Pair(1156, 40), Pair(1279, 5), Pair(1275, 15), Pair(1318, 28), Pair(1366, -100),
      Pair(1260, -23), Pair(1404, 48), Pair(1273, 69), Pair(1280, 35), Pair(1321, 25), Pair(1372, 25), Pair(1378, 44), Pair(1285, -9),
      Pair(1777, -31), Pair(1993, -13), Pair(1919, 0), Pair(1819, 23), Pair(1810, 23), Pair(1978, -8), Pair(1851, 8), Pair(1867, -50),
      Pair(1865, -66), Pair(1927, -29), Pair(1906, -21), Pair(1783, 5), Pair(1741, 4), Pair(1859, -16), Pair(1847, -29), Pair(1763, -50),
      Pair(1242, -86), Pair(1266, -57), Pair(1292, -47), Pair(1184, -18), Pair(1194, -23), Pair(1259, -42), Pair(1224, -49), Pair(1164, -74),
      Pair(574, -40), Pair(580, -9), Pair(524, 19), Pair(522, 26), Pair(504, 34), Pair(518, 17), Pair(551, -6), Pair(541, -37),
      Pair(156, -31), Pair(97, 30), Pair(91, 36), Pair(66, 49), Pair(53, 56), Pair(71, 45), Pair(93, 26), Pair(120, -22),
      Pair(-515, -22), Pair(-496, 52), Pair(-44, 49), Pair(-112, 65), Pair(-61, 50), Pair(-90, 63), Pair(-528, 64), Pair(-518, -8)
    }
  }},
  {{ // Bucket 1
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(27, 109), Pair(-26, 134), Pair(-31, 87), Pair(57, 55), Pair(-17, 40), Pair(-49, 21), Pair(-61, 55), Pair(-97, 82),
      Pair(74, 103), Pair(17, 126), Pair(63, 63), Pair(76, 15), Pair(70, 23), Pair(100, 27), Pair(43, 112), Pair(14, 96),
      Pair(58, 69), Pair(22, 59), Pair(28, 46), Pair(36, 13), Pair(48, 18), Pair(40, 13), Pair(31, 51), Pair(11, 63),
      Pair(60, 37), Pair(10, 58), Pair(34, 30), Pair(52, 14), Pair(38, 27), Pair(40, 11), Pair(31, 38), Pair(6, 40),
      Pair(57, 26), Pair(11, 47), Pair(21, 37), Pair(14, 38), Pair(21, 39), Pair(10, 26), Pair(28, 31), Pair(-3, 34),
      Pair(58, 42), Pair(22, 61), Pair(23, 57), Pair(-1, 61), Pair(-9, 78), Pair(20, 42), Pair(31, 48), Pair(6, 50),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-86, -70), Pair(-206, 170), Pair(-65, 71), Pair(-37, 100), Pair(78, 40), Pair(14, 2), Pair(-45, 94), Pair(-48, -57),
      Pair(-41, 106), Pair(35, 101), Pair(68, 77), Pair(25, 99), Pair(47, 95), Pair(82, 79), Pair(7, 84), Pair(69, 50),
      Pair(15, 109), Pair(82, 111), Pair(36, 135), Pair(81, 110), Pair(80, 106), Pair(64, 92), Pair(44, 120), Pair(55, 82),
      Pair(60, 129), Pair(87, 122), Pair(100, 119), Pair(120, 111), Pair(105, 119), Pair(114, 122), Pair(95, 105), Pair(98, 83),
      Pair(54, 129), Pair(57, 142), Pair(98, 129), Pair(106, 132), Pair(103, 142), Pair(120, 108), Pair(104, 121), Pair(74, 94),
      Pair(33, 111), Pair(69, 119), Pair(89, 111), Pair(96, 135), Pair(109, 133), Pair(86, 107), Pair(89, 98), Pair(58, 105),
      Pair(29, 121), Pair(59, 118), Pair(72, 125), Pair(69, 125), Pair(79, 109), Pair(77, 106), Pair(64, 104), Pair(37, 88),
      Pair(-25, 79), Pair(33, 109), Pair(48, 109), Pair(51, 125), Pair(68, 122), Pair(54, 100), Pair(33, 108), Pair(35, 56)
    },
    {
      Pair(6, 126), Pair(-5, 152), Pair(-44, 131), Pair(-82, 156), Pair(-174, 199), Pair(-106, 122), Pair(39, 129), Pair(-7, 108),
      Pair(-6, 115), Pair(39, 132), Pair(42, 124), Pair(14, 132), Pair(2, 137), Pair(45, 129), Pair(28, 126), Pair(52, 106),
      Pair(55, 144), Pair(50, 159), Pair(42, 159), Pair(87, 125), Pair(63, 123), Pair(74, 125), Pair(84, 149), Pair(90, 129),
      Pair(56, 149), Pair(91, 134), Pair(76, 144), Pair(87, 148), Pair(91, 125), Pair(90, 161), Pair(73, 147), Pair(63, 154),
      Pair(75, 106), Pair(37, 168), Pair(92, 115), Pair(95, 142), Pair(104, 121), Pair(74, 130), Pair(65, 138), Pair(76, 110),
      Pair(63, 129), Pair(108, 123), Pair(97, 145), Pair(94, 147), Pair(95, 152), Pair(103, 137), Pair(97, 127), Pair(79, 106),
      Pair(98, 105), Pair(106, 117), Pair(120, 109), Pair(87, 145), Pair(102, 131), Pair(107, 114), Pair(107, 114), Pair(93, 99),
      Pair(84, 112), Pair(100, 128), Pair(74, 135), Pair(93, 122), Pair(102, 107), Pair(71, 138), Pair(55, 149), Pair(79, 97)
    },
    {
      Pair(137, 280), Pair(56, 301), Pair(138, 266), Pair(120, 297), Pair(56, 297), Pair(57, 305), Pair(75, 291), Pair(98, 291),
      Pair(77, 271), Pair(103, 280), Pair(119, 266), Pair(111, 293), Pair(172, 243), Pair(138, 256), Pair(106, 262), Pair(105, 261),
      Pair(89, 256), Pair(141, 260), Pair(100, 263), Pair(132, 258), Pair(172, 225), Pair(132, 240), Pair(170, 235), Pair(126, 230),
      Pair(85, 259), Pair(151, 237), Pair(133, 271), Pair(109, 283), Pair(121, 254), Pair(160, 239), Pair(139, 233), Pair(120, 239),
      Pair(97, 259), Pair(83, 265), Pair(109, 250), Pair(111, 278), Pair(110, 261), Pair(104, 252), Pair(117, 237), Pair(96, 229),
      Pair(93, 248), Pair(113, 259), Pair(107, 251), Pair(98, 272), Pair(110, 247), Pair(118, 242), Pair(133, 212), Pair(110, 219),
      Pair(99, 222), Pair(94, 252), Pair(127, 248), Pair(108, 240), Pair(129, 221), Pair(114, 246), Pair(117, 204), Pair(96, 203),
      Pair(123, 221), Pair(105, 231), Pair(114, 245), Pair(124, 240), Pair(136, 223), Pair(109, 225), Pair(115, 211), Pair(120, 200)
    },
    {
      Pair(172, 422), Pair(156, 442), Pair(227, 414), Pair(249, 402), Pair(251, 404), Pair(192, 438), Pair(193, 440), Pair(223, 347),
      Pair(226, 345), Pair(205, 420), Pair(211, 433), Pair(148, 501), Pair(140, 502), Pair(211, 459), Pair(238, 405), Pair(279, 422),
      Pair(242, 399), Pair(237, 365), Pair(224, 436), Pair(254, 398), Pair(229, 457), Pair(261, 417), Pair(282, 387), Pair(289, 427),
      Pair(244, 386), Pair(251, 404), Pair(261, 417), Pair(243, 446), Pair(245, 422), Pair(273, 395), Pair(283, 397), Pair(267, 426),
      Pair(258, 372), Pair(233, 451), Pair(251, 412), Pair(254, 486), Pair(249, 465), Pair(254, 417), Pair(263, 410), Pair(265, 384),
      Pair(248, 377), Pair(264, 408), Pair(259, 440), Pair(244, 452), Pair(259, 440), Pair(258, 441), Pair(271, 408), Pair(267, 420),
      Pair(256, 336), Pair(277, 308), Pair(277, 335), Pair(272, 381), Pair(268, 392), Pair(263, 384), Pair(301, 296), Pair(296, 313),
      Pair(256, 309), Pair(260, 306), Pair(264, 345), Pair(264, 331), Pair(256, 350), Pair(256, 311), Pair(269, 311), Pair(282, 324)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    }
  }},
  {{ // Bucket 2
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(123, 151), Pair(73, 153), Pair(83, 137), Pair(150, 60), Pair(105, 58), Pair(111, 84), Pair(41, 125), Pair(5, 160),
      Pair(56, 126), Pair(74, 114), Pair(85, 84), Pair(109, 36), Pair(135, 21), Pair(159, 49), Pair(113, 108), Pair(52, 129),
      Pair(29, 104), Pair(45, 90), Pair(44, 71), Pair(61, 48), Pair(96, 43), Pair(87, 46), Pair(67, 80), Pair(22, 88),
      Pair(24, 84), Pair(37, 85), Pair(41, 66), Pair(59, 57), Pair(70, 53), Pair(74, 50), Pair(56, 72), Pair(13, 70),
      Pair(3, 80), Pair(21, 80), Pair(24, 70), Pair(33, 70), Pair(40, 70), Pair(44, 64), Pair(54, 63), Pair(0, 67),
      Pair(15, 85), Pair(35, 85), Pair(34, 78), Pair(18, 86), Pair(51, 80), Pair(80, 70), Pair(74, 72), Pair(-4, 77),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-131, 62), Pair(-127, 124), Pair(-85, 133), Pair(75, 86), Pair(143, 79), Pair(-111, 118), Pair(-251, 160), Pair(-104, 19),
      Pair(-13, 141), Pair(28, 133), Pair(60, 130), Pair(142, 112), Pair(82, 117), Pair(128, 92), Pair(60, 130), Pair(68, 95),
      Pair(28, 135), Pair(93, 127), Pair(79, 156), Pair(126, 125), Pair(117, 129), Pair(194, 80), Pair(92, 99), Pair(135, 83),
      Pair(66, 135), Pair(102, 140), Pair(130, 150), Pair(129, 141), Pair(132, 146), Pair(186, 125), Pair(127, 138), Pair(148, 121),
      Pair(60, 150), Pair(103, 139), Pair(107, 164), Pair(140, 145), Pair(130, 161), Pair(143, 138), Pair(168, 123), Pair(89, 149),
      Pair(36, 130), Pair(72, 134), Pair(103, 136), Pair(111, 160), Pair(137, 150), Pair(110, 124), Pair(115, 113), Pair(87, 121),
      Pair(22, 128), Pair(22, 144), Pair(60, 146), Pair(90, 131), Pair(97, 123), Pair(91, 135), Pair(83, 109), Pair(77, 125),
      Pair(-53, 166), Pair(29, 135), Pair(51, 133), Pair(59, 153), Pair(73, 142), Pair(84, 129), Pair(61, 128), Pair(17, 138)
    },
    {
      Pair(34, 167), Pair(33, 153), Pair(-35, 169), Pair(-55, 173), Pair(0, 157), Pair(-39, 173), Pair(33, 156), Pair(-32, 176),
      Pair(46, 150), Pair(72, 155), Pair(72, 146), Pair(25, 168), Pair(41, 158), Pair(57, 151), Pair(38, 167), Pair(63, 152),
      Pair(71, 161), Pair(85, 154), Pair(77, 158), Pair(62, 153), Pair(105, 141), Pair(131, 148), Pair(117, 157), Pair(108, 161),
      Pair(75, 154), Pair(98, 153), Pair(105, 158), Pair(132, 152), Pair(99, 165), Pair(119, 155), Pair(91, 152), Pair(98, 146),
      Pair(76, 146), Pair(58, 166), Pair(104, 150), Pair(105, 163), Pair(106, 153), Pair(86, 170), Pair(90, 156), Pair(89, 144),
      Pair(64, 157), Pair(118, 147), Pair(111, 150), Pair(117, 154), Pair(113, 165), Pair(116, 149), Pair(125, 147), Pair(107, 120),
      Pair(80, 145), Pair(93, 123), Pair(113, 133), Pair(94, 141), Pair(111, 139), Pair(114, 133), Pair(136, 116), Pair(90, 121),
      Pair(62, 142), Pair(106, 154), Pair(96, 144), Pair(91, 155), Pair(93, 157), Pair(75, 165), Pair(116, 134), Pair(56, 123)
    },
    {
      Pair(110, 330), Pair(133, 344), Pair(115, 353), Pair(141, 335), Pair(120, 329), Pair(193, 322), Pair(131, 350), Pair(133, 337),
      Pair(132, 318), Pair(140, 336), Pair(165, 333), Pair(205, 311), Pair(188, 309), Pair(228, 308), Pair(167, 325), Pair(159, 315),
      Pair(142, 316), Pair(157, 323), Pair(163, 324), Pair(169, 306), Pair(196, 290), Pair(223, 288), Pair(233, 298), Pair(162, 299),
      Pair(111, 334), Pair(175, 322), Pair(155, 332), Pair(169, 313), Pair(179, 292), Pair(197, 294), Pair(186, 309), Pair(145, 305),
      Pair(87, 326), Pair(123, 325), Pair(120, 327), Pair(144, 314), Pair(133, 308), Pair(123, 318), Pair(141, 309), Pair(120, 306),
      Pair(108, 304), Pair(104, 316), Pair(114, 310), Pair(127, 304), Pair(135, 304), Pair(134, 295), Pair(158, 282), Pair(99, 296),
      Pair(106, 291), Pair(119, 300), Pair(125, 305), Pair(134, 299), Pair(150, 276), Pair(148, 281), Pair(137, 293), Pair(113, 272),
      Pair(104, 295), Pair(111, 295), Pair(115, 304), Pair(124, 291), Pair(135, 273), Pair(135, 272), Pair(129, 285), Pair(106, 288)
    },
    {
      Pair(189, 557), Pair(232, 505), Pair(254, 540), Pair(314, 503), Pair(311, 511), Pair(273, 546), Pair(402, 434), Pair(321, 519),
      Pair(228, 520), Pair(246, 513), Pair(242, 563), Pair(265, 533), Pair(250, 581), Pair(286, 527), Pair(287, 517), Pair(319, 543),
      Pair(259, 491), Pair(268, 511), Pair(298, 520), Pair(286, 537), Pair(301, 541), Pair(353, 497), Pair(329, 504), Pair(320, 496),
      Pair(258, 495), Pair(270, 528), Pair(290, 524), Pair(289, 536), Pair(303, 522), Pair(300, 537), Pair(317, 528), Pair(312, 496),
      Pair(270, 489), Pair(254, 547), Pair(273, 537), Pair(289, 538), Pair(295, 523), Pair(292, 516), Pair(301, 512), Pair(280, 529),
      Pair(259, 475), Pair(270, 507), Pair(272, 511), Pair(281, 521), Pair(287, 523), Pair(295, 513), Pair(308, 489), Pair(279, 522),
      Pair(270, 475), Pair(261, 475), Pair(276, 479), Pair(284, 482), Pair(283, 490), Pair(287, 460), Pair(293, 421), Pair(300, 419),
      Pair(215, 491), Pair(234, 483), Pair(240, 492), Pair(267, 475), Pair(261, 476), Pair(249, 484), Pair(271, 487), Pair(261, 462)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    }
  }},
  {{ // Bucket 3
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(80, 124), Pair(235, 69), Pair(142, 87), Pair(146, 58), Pair(233, 22), Pair(92, 55), Pair(-36, 146), Pair(-26, 148),
      Pair(59, 107), Pair(131, 111), Pair(176, 51), Pair(157, 29), Pair(200, 15), Pair(202, 43), Pair(121, 98), Pair(127, 82),
      Pair(11, 101), Pair(39, 104), Pair(32, 74), Pair(45, 59), Pair(77, 56), Pair(58, 58), Pair(32, 93), Pair(-1, 86),
      Pair(-19, 90), Pair(13, 107), Pair(23, 74), Pair(29, 68), Pair(50, 67), Pair(43, 67), Pair(16, 92), Pair(-6, 79),
      Pair(-46, 87), Pair(-3, 100), Pair(8, 78), Pair(34, 76), Pair(32, 80), Pair(27, 74), Pair(8, 90), Pair(-27, 79),
      Pair(-33, 99), Pair(25, 104), Pair(37, 82), Pair(-18, 94), Pair(43, 90), Pair(50, 81), Pair(24, 95), Pair(-27, 91),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-217, 17), Pair(-315, 99), Pair(-142, 120), Pair(-65, 85), Pair(-60, 92), Pair(-100, 72), Pair(-2, 56), Pair(-202, 51),
      Pair(-81, 80), Pair(10, 95), Pair(-2, 103), Pair(75, 73), Pair(77, 64), Pair(38, 74), Pair(-31, 112), Pair(-71, 91),
      Pair(82, 53), Pair(111, 63), Pair(82, 84), Pair(144, 80), Pair(95, 74), Pair(136, 40), Pair(102, 70), Pair(60, 58),
      Pair(44, 102), Pair(104, 93), Pair(95, 111), Pair(91, 104), Pair(138, 96), Pair(103, 108), Pair(162, 72), Pair(35, 101),
      Pair(21, 96), Pair(65, 99), Pair(51, 124), Pair(102, 112), Pair(112, 112), Pair(119, 93), Pair(74, 83), Pair(100, 75),
      Pair(14, 67), Pair(21, 96), Pair(90, 86), Pair(86, 107), Pair(128, 104), Pair(129, 73), Pair(83, 79), Pair(-1, 101),
      Pair(-67, 103), Pair(40, 96), Pair(11, 99), Pair(68, 101), Pair(43, 106), Pair(135, 79), Pair(30, 95), Pair(60, 101),
      Pair(-24, 105), Pair(-34, 91), Pair(-77, 127), Pair(-138, 125), Pair(4, 103), Pair(12, 91), Pair(-36, 106), Pair(0, 125)
    },
    {
      Pair(1, 125), Pair(-22, 144), Pair(14, 118), Pair(-34, 108), Pair(-45, 129), Pair(-159, 131), Pair(-67, 114), Pair(-45, 107),
      Pair(-5, 102), Pair(89, 101), Pair(-14, 124), Pair(96, 92), Pair(-40, 116), Pair(47, 92), Pair(-26, 140), Pair(2, 112),
      Pair(58, 126), Pair(55, 112), Pair(63, 109), Pair(48, 109), Pair(78, 118), Pair(138, 104), Pair(72, 115), Pair(105, 106),
      Pair(76, 110), Pair(79, 111), Pair(107, 102), Pair(91, 118), Pair(103, 113), Pair(47, 142), Pair(95, 111), Pair(95, 99),
      Pair(-14, 126), Pair(-30, 145), Pair(87, 102), Pair(101, 111), Pair(61, 111), Pair(93, 105), Pair(35, 130), Pair(35, 110),
      Pair(-2, 124), Pair(38, 120), Pair(79, 109), Pair(103, 96), Pair(129, 96), Pair(93, 104), Pair(60, 107), Pair(19, 116),
      Pair(30, 147), Pair(37, 116), Pair(26, 127), Pair(46, 124), Pair(62, 116), Pair(32, 122), Pair(69, 91), Pair(61, 90),
      Pair(14, 106), Pair(9, 165), Pair(27, 125), Pair(27, 120), Pair(84, 113), Pair(33, 127), Pair(-96, 158), Pair(23, 98)
    },
    {
      Pair(61, 263), Pair(21, 281), Pair(69, 284), Pair(32, 278), Pair(69, 258), Pair(88, 275), Pair(79, 258), Pair(14, 267),
      Pair(129, 230), Pair(118, 260), Pair(61, 280), Pair(212, 212), Pair(103, 239), Pair(119, 254), Pair(110, 250), Pair(84, 231),
      Pair(76, 250), Pair(103, 252), Pair(111, 246), Pair(98, 243), Pair(119, 232), Pair(164, 226), Pair(114, 242), Pair(60, 233),
      Pair(-17, 273), Pair(91, 254), Pair(27, 286), Pair(115, 257), Pair(86, 242), Pair(85, 241), Pair(84, 246), Pair(62, 236),
      Pair(0, 259), Pair(-17, 286), Pair(-30, 287), Pair(52, 264), Pair(74, 249), Pair(47, 247), Pair(38, 256), Pair(30, 235),
      Pair(37, 230), Pair(31, 246), Pair(22, 254), Pair(48, 244), Pair(36, 241), Pair(48, 246), Pair(83, 207), Pair(-24, 229),
      Pair(-11, 234), Pair(35, 232), Pair(18, 255), Pair(26, 244), Pair(15, 250), Pair(97, 207), Pair(73, 207), Pair(12, 226),
      Pair(51, 223), Pair(37, 239), Pair(20, 255), Pair(62, 240), Pair(50, 229), Pair(80, 216), Pair(66, 217), Pair(57, 214)
    },
    {
      Pair(45, 351), Pair(81, 317), Pair(90, 329), Pair(85, 351), Pair(-46, 427), Pair(34, 424), Pair(178, 230), Pair(44, 360),
      Pair(44, 342), Pair(53, 332), Pair(29, 380), Pair(135, 351), Pair(139, 349), Pair(223, 287), Pair(127, 310), Pair(207, 261),
      Pair(159, 312), Pair(67, 335), Pair(212, 270), Pair(77, 375), Pair(174, 325), Pair(221, 284), Pair(246, 223), Pair(191, 285),
      Pair(95, 332), Pair(142, 306), Pair(169, 281), Pair(133, 338), Pair(182, 305), Pair(197, 301), Pair(237, 253), Pair(192, 266),
      Pair(114, 270), Pair(63, 351), Pair(148, 346), Pair(184, 323), Pair(157, 356), Pair(194, 297), Pair(161, 321), Pair(99, 373),
      Pair(19, 330), Pair(155, 272), Pair(169, 291), Pair(153, 312), Pair(149, 332), Pair(219, 235), Pair(222, 204), Pair(143, 270),
      Pair(110, 281), Pair(89, 333), Pair(170, 243), Pair(167, 268), Pair(170, 310), Pair(151, 267), Pair(154, 222), Pair(114, 250),
      Pair(22, 342), Pair(48, 318), Pair(113, 286), Pair(139, 268), Pair(161, 225), Pair(153, 294), Pair(107, 337), Pair(156, 247)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    }
  }},
  {{ // Bucket 4
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(82, 102), Pair(324, 25), Pair(264, 66), Pair(138, 50), Pair(65, 108), Pair(-59, 126), Pair(27, 156), Pair(215, 80),
      Pair(66, 61), Pair(81, 116), Pair(157, 29), Pair(165, 16), Pair(181, 19), Pair(158, 35), Pair(168, 59), Pair(62, 77),
      Pair(-26, 75), Pair(110, 85), Pair(68, 47), Pair(42, 49), Pair(66, 57), Pair(85, 51), Pair(27, 87), Pair(46, 59),
      Pair(-15, 64), Pair(-23, 110), Pair(19, 60), Pair(-11, 69), Pair(19, 63), Pair(5, 65), Pair(-52, 98), Pair(-53, 63),
      Pair(-50, 58), Pair(6, 94), Pair(25, 51), Pair(16, 60), Pair(11, 62), Pair(14, 60), Pair(-2, 81), Pair(-61, 64),
      Pair(-62, 72), Pair(-6, 103), Pair(51, 48), Pair(-33, 51), Pair(15, 74), Pair(44, 60), Pair(18, 80), Pair(-75, 75),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-327, -54), Pair(-162, 15), Pair(-4, 54), Pair(-46, 48), Pair(131, 45), Pair(7, 42), Pair(-163, 42), Pair(-698, 103),
      Pair(-140, 85), Pair(3, 76), Pair(57, 53), Pair(161, 28), Pair(75, 20), Pair(-5, 82), Pair(119, 60), Pair(95, 15),
      Pair(21, 63), Pair(128, 42), Pair(199, 44), Pair(167, 36), Pair(115, 71), Pair(170, 30), Pair(93, 48), Pair(110, 47),
      Pair(30, 78), Pair(156, 50), Pair(101, 71), Pair(223, 50), Pair(180, 66), Pair(169, 65), Pair(203, 36), Pair(255, 11),
      Pair(-19, 85), Pair(40, 86), Pair(7, 109), Pair(115, 93), Pair(50, 84), Pair(97, 90), Pair(45, 85), Pair(238, 53),
      Pair(-42, 83), Pair(-44, 106), Pair(142, 70), Pair(68, 95), Pair(40, 110), Pair(136, 71), Pair(-4, 109), Pair(-21, 98),
      Pair(-33, 105), Pair(-13, 92), Pair(-27, 82), Pair(70, 78), Pair(103, 80), Pair(-29, 113), Pair(96, 42), Pair(-28, 83),
      Pair(-97, 95), Pair(-135, 99), Pair(-169, 103), Pair(79, 78), Pair(39, 87), Pair(-55, 84), Pair(-54, 116), Pair(-149, 157)
    },
    {
      Pair(63, 75), Pair(-74, 114), Pair(85, 64), Pair(85, 83), Pair(73, 67), Pair(90, 64), Pair(-6, 86), Pair(104, 71),
      Pair(39, 73), Pair(90, 70), Pair(103, 77), Pair(-19, 85), Pair(-18, 91), Pair(129, 61), Pair(-37, 98), Pair(-60, 121),
      Pair(6, 116), Pair(98, 77), Pair(207, 64), Pair(84, 80), Pair(294, 31), Pair(193, 95), Pair(96, 91), Pair(110, 92),
      Pair(-93, 126), Pair(160, 84), Pair(98, 88), Pair(201, 63), Pair(75, 119), Pair(110, 87), Pair(91, 88), Pair(74, 86),
      Pair(51, 77), Pair(44, 96), Pair(62, 78), Pair(73, 85), Pair(78, 76), Pair(77, 86), Pair(80, 79), Pair(102, 84),
      Pair(-79, 129), Pair(74, 98), Pair(67, 96), Pair(106, 83), Pair(113, 99), Pair(79, 93), Pair(70, 106), Pair(-81, 123),
      Pair(-65, 153), Pair(-8, 105), Pair(45, 95), Pair(52, 92), Pair(-57, 118), Pair(-23, 92), Pair(24, 79), Pair(-130, 139),
      Pair(-104, 121), Pair(-137, 117), Pair(-37, 117), Pair(5, 113), Pair(-88, 113), Pair(-68, 123), Pair(-38, 83), Pair(178, 121)
    },
    {
      Pair(109, 207), Pair(-20, 265), Pair(73, 242), Pair(64, 236), Pair(10, 257), Pair(166, 195), Pair(42, 237), Pair(283, 160),
      Pair(110, 204), Pair(101, 220), Pair(130, 212), Pair(196, 191), Pair(149, 195), Pair(107, 216), Pair(184, 193), Pair(185, 175),
      Pair(125, 192), Pair(43, 239), Pair(58, 227), Pair(159, 207), Pair(160, 186), Pair(93, 202), Pair(111, 211), Pair(124, 186),
      Pair(87, 209), Pair(-56, 266), Pair(80, 214), Pair(124, 212), Pair(64, 210), Pair(148, 177), Pair(90, 214), Pair(140, 180),
      Pair(-8, 220), Pair(-94, 254), Pair(-46, 242), Pair(-28, 244), Pair(43, 211), Pair(89, 195), Pair(21, 213), Pair(121, 151),
      Pair(89, 188), Pair(-21, 242), Pair(-143, 261), Pair(-23, 243), Pair(-39, 236), Pair(-2, 205), Pair(35, 194), Pair(61, 174),
      Pair(-48, 227), Pair(-92, 258), Pair(11, 219), Pair(29, 228), Pair(65, 200), Pair(92, 186), Pair(64, 180), Pair(54, 184),
      Pair(-16, 224), Pair(-52, 247), Pair(-50, 245), Pair(1, 232), Pair(19, 215), Pair(53, 193), Pair(-24, 239), Pair(32, 190)
    },
    {
      Pair(43, 193), Pair(-9, 176), Pair(0, 221), Pair(94, 190), Pair(202, 113), Pair(-14, 243), Pair(292, 25), Pair(-183, 321),
      Pair(-16, 182), Pair(165, 120), Pair(-91, 272), Pair(-126, 362), Pair(89, 239), Pair(-10, 223), Pair(-135, 265), Pair(125, 130),
      Pair(-108, 233), Pair(-36, 219), Pair(195, 103), Pair(-40, 286), Pair(251, 106), Pair(233, 163), Pair(-110, 240), Pair(235, 71),
      Pair(-106, 270), Pair(14, 207), Pair(-220, 346), Pair(237, 106), Pair(119, 166), Pair(150, 140), Pair(-8, 229), Pair(299, 72),
      Pair(-160, 278), Pair(-35, 200), Pair(-282, 361), Pair(92, 182), Pair(74, 181), Pair(103, 219), Pair(312, 20), Pair(84, 68),
      Pair(-285, 286), Pair(26, 206), Pair(133, 144), Pair(43, 260), Pair(165, 147), Pair(250, 29), Pair(22, 135), Pair(9, 216),
      Pair(-212, 355), Pair(-75, 239), Pair(-48, 245), Pair(-45, 254), Pair(89, 194), Pair(117, 80), Pair(-12, 190), Pair(-215, 303),
      Pair(-77, 236), Pair(96, 13), Pair(10, 166), Pair(169, 1), Pair(57, 201), Pair(-111, 246), Pair(-108, 276), Pair(-58, 109)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    }
  }},
  {{ // Bucket 5
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(-5, 139), Pair(226, 66), Pair(413, 108), Pair(356, 62), Pair(22, 162), Pair(165, 140), Pair(-144, 206), Pair(123, 145),
      Pair(164, 60), Pair(165, 128), Pair(267, 56), Pair(226, 48), Pair(297, 36), Pair(219, 64), Pair(179, 77), Pair(83, 89),
      Pair(-24, 86), Pair(15, 120), Pair(133, 62), Pair(35, 72), Pair(94, 62), Pair(55, 69), Pair(43, 98), Pair(-22, 74),
      Pair(-47, 80), Pair(-29, 125), Pair(57, 71), Pair(-29, 83), Pair(26, 73), Pair(-63, 89), Pair(1, 101), Pair(-61, 70),
      Pair(-36, 60), Pair(-30, 107), Pair(40, 51), Pair(18, 69), Pair(70, 60), Pair(-5, 69), Pair(59, 82), Pair(-35, 62),
      Pair(-49, 64), Pair(-28, 110), Pair(69, 58), Pair(-168, 127), Pair(-83, 74), Pair(-34, 75), Pair(7, 85), Pair(-81, 77),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(55, -72), Pair(256, -82), Pair(268, -24), Pair(136, -26), Pair(178, 4), Pair(199, -71), Pair(-172, -11), Pair(400, -100),
      Pair(-303, 12), Pair(190, 7), Pair(240, -1), Pair(322, -43), Pair(387, -58), Pair(79, 15), Pair(125, 13), Pair(74, -5),
      Pair(-181, 53), Pair(140, 14), Pair(129, 22), Pair(79, 56), Pair(507, -24), Pair(208, 29), Pair(245, -5), Pair(168, -18),
      Pair(23, 18), Pair(118, 31), Pair(236, 31), Pair(248, 45), Pair(145, 41), Pair(51, 92), Pair(168, -2), Pair(44, 34),
      Pair(44, 31), Pair(-109, 71), Pair(32, 73), Pair(103, 57), Pair(166, 51), Pair(95, 38), Pair(143, 19), Pair(41, 9),
      Pair(-105, 14), Pair(-124, 78), Pair(-30, 78), Pair(90, 61), Pair(-63, 100), Pair(-28, 93), Pair(-55, 63), Pair(29, 31),
      Pair(-281, 51), Pair(-260, 80), Pair(-153, 72), Pair(-198, 94), Pair(2, 73), Pair(-13, 64), Pair(61, 49), Pair(-220, 102),
      Pair(-160, 69), Pair(-84, 29), Pair(-394, 118), Pair(-204, 113), Pair(-30, 42), Pair(-270, 84), Pair(-60, 52), Pair(-73, 72)
    },
    {
      Pair(-311, 100), Pair(353, 18), Pair(294, 9), Pair(186, 11), Pair(72, 27), Pair(-7, 51), Pair(526, -35), Pair(37, 43),
      Pair(-5, 53), Pair(113, 44), Pair(81, 57), Pair(49, 27), Pair(309, -12), Pair(250, 16), Pair(303, 1), Pair(20, 53),
      Pair(-5, 78), Pair(156, 28), Pair(73, 55), Pair(212, 41), Pair(175, 49), Pair(261, 40), Pair(181, 43), Pair(199, 34),
      Pair(106, 32), Pair(69, 55), Pair(85, 63), Pair(188, 24), Pair(250, 30), Pair(179, 50), Pair(108, 51), Pair(142, 19),
      Pair(30, 76), Pair(98, 54), Pair(128, 49), Pair(45, 69), Pair(151, 32), Pair(52, 73), Pair(107, 21), Pair(67, 95),
      Pair(-20, 94), Pair(178, 48), Pair(44, 64), Pair(148, 56), Pair(129, 52), Pair(158, 51), Pair(-8, 105), Pair(-20, 81),
      Pair(-11, 108), Pair(-92, 97), Pair(-40, 69), Pair(53, 58), Pair(109, 52), Pair(-113, 82), Pair(-203, 125), Pair(-166, 84),
      Pair(-138, 110), Pair(-21, 85), Pair(-75, 113), Pair(-111, 88), Pair(-157, 112), Pair(-89, 93), Pair(-173, 106), Pair(-236, 134)
    },
    {
      Pair(64, 162), Pair(128, 162), Pair(63, 186), Pair(101, 187), Pair(-16, 189), Pair(151, 150), Pair(17, 206), Pair(418, 70),
      Pair(124, 136), Pair(120, 173), Pair(169, 161), Pair(167, 141), Pair(181, 134), Pair(142, 152), Pair(247, 111), Pair(185, 121),
      Pair(-19, 175), Pair(60, 174), Pair(240, 120), Pair(83, 157), Pair(138, 154), Pair(214, 117), Pair(251, 114), Pair(245, 91),
      Pair(26, 176), Pair(64, 175), Pair(0, 193), Pair(81, 161), Pair(-23, 179), Pair(270, 90), Pair(-99, 203), Pair(215, 99),
      Pair(-89, 184), Pair(-100, 213), Pair(-4, 198), Pair(134, 153), Pair(66, 166), Pair(148, 150), Pair(-20, 184), Pair(86, 148),
      Pair(17, 145), Pair(-67, 189), Pair(-9, 185), Pair(-23, 199), Pair(59, 164), Pair(24, 167), Pair(-30, 180), Pair(59, 128),
      Pair(16, 156), Pair(-92, 202), Pair(26, 184), Pair(-23, 192), Pair(-50, 187), Pair(80, 163), Pair(-179, 206), Pair(103, 115),
      Pair(-98, 195), Pair(-142, 241), Pair(-58, 201), Pair(-20, 187), Pair(-28, 185), Pair(49, 165), Pair(-51, 183), Pair(-19, 176)
    },
    {
      Pair(42, 94), Pair(-96, 165), Pair(157, 77), Pair(205, 93), Pair(117, 97), Pair(127, 48), Pair(67, 78), Pair(121, 24),
      Pair(-181, 264), Pair(72, 120), Pair(121, 142), Pair(244, 132), Pair(204, 59), Pair(445, -28), Pair(162, 107), Pair(-46, 209),
      Pair(76, 96), Pair(184, 35), Pair(267, 56), Pair(110, 98), Pair(427, -40), Pair(402, -52), Pair(28, 128), Pair(426, -66),
      Pair(-181, 239), Pair(40, 121), Pair(105, 127), Pair(335, 6), Pair(-74, 217), Pair(90, 95), Pair(-174, 254), Pair(-57, 180),
      Pair(-233, 278), Pair(-158, 256), Pair(-107, 223), Pair(45, 223), Pair(0, 228), Pair(263, 4), Pair(-233, 319), Pair(121, 139),
      Pair(-288, 312), Pair(-280, 352), Pair(-40, 214), Pair(210, 45), Pair(-352, 426), Pair(-73, 182), Pair(-92, 207), Pair(-78, 222),
      Pair(28, 99), Pair(-99, 205), Pair(66, 156), Pair(8, 108), Pair(-152, 261), Pair(-97, 174), Pair(43, 242), Pair(-16, 73),
      Pair(13, 49), Pair(-227, 311), Pair(45, 110), Pair(-88, 121), Pair(-67, 262), Pair(62, 166), Pair(-123, 235), Pair(231, 44)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    }
  }},
  {{ // Bucket 6
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(-89, 140), Pair(303, 94), Pair(282, 159), Pair(202, 157), Pair(109, 170), Pair(92, 193), Pair(-256, 218), Pair(55, 135),
      Pair(-24, 109), Pair(240, 122), Pair(378, 70), Pair(166, 92), Pair(269, 53), Pair(222, 126), Pair(16, 144), Pair(-33, 93),
      Pair(-115, 100), Pair(-70, 127), Pair(122, 65), Pair(-8, 80), Pair(45, 66), Pair(26, 81), Pair(-211, 136), Pair(-62, 69),
      Pair(-144, 87), Pair(-30, 79), Pair(152, 46), Pair(98, 34), Pair(-1, 68), Pair(14, 39), Pair(-53, 92), Pair(-47, 38),
      Pair(-127, 69), Pair(139, 35), Pair(174, -4), Pair(178, -10), Pair(-39, 64), Pair(120, 13), Pair(-49, 66), Pair(82, 15),
      Pair(-186, 79), Pair(84, 60), Pair(120, 11), Pair(-266, 128), Pair(-68, 38), Pair(-2, 41), Pair(-40, 66), Pair(-36, 52),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-58, -116), Pair(-116, -71), Pair(316, -74), Pair(119, -84), Pair(-86, -7), Pair(337, -125), Pair(111, -270), Pair(1, -248),
      Pair(187, -125), Pair(119, -76), Pair(-150, 92), Pair(9, -10), Pair(345, -74), Pair(-304, 34), Pair(62, -130), Pair(-1, -77),
      Pair(104, -72), Pair(-137, 24), Pair(153, 39), Pair(383, 2), Pair(707, -66), Pair(220, 33), Pair(446, -102), Pair(169, -71),
      Pair(64, -20), Pair(-177, 76), Pair(213, -20), Pair(339, -7), Pair(254, 10), Pair(22, 67), Pair(502, -51), Pair(319, -89),
      Pair(64, 10), Pair(-134, 60), Pair(-176, 80), Pair(-308, 129), Pair(99, 69), Pair(-23, 49), Pair(-190, 31), Pair(-53, 17),
      Pair(-159, 17), Pair(-55, -13), Pair(3, 41), Pair(-65, 80), Pair(218, 20), Pair(-44, 65), Pair(-21, -32), Pair(-125, 29),
      Pair(-11, -114), Pair(-37, -2), Pair(-122, 59), Pair(-348, 98), Pair(-428, 72), Pair(-4, 4), Pair(-87, -8), Pair(154, -94),
      Pair(-264, -4), Pair(-207, 99), Pair(-45, 80), Pair(-99, 70), Pair(143, 74), Pair(-502, 117), Pair(-553, 116), Pair(-3, 4)
    },
    {
      Pair(23, -13), Pair(153, -34), Pair(78, 31), Pair(548, -30), Pair(-311, 28), Pair(-141, -18), Pair(59, -44), Pair(5, 10),
      Pair(-154, -23), Pair(-28, -9), Pair(-174, -7), Pair(214, -60), Pair(37, 14), Pair(135, -21), Pair(183, -52), Pair(18, -21),
      Pair(9, -14), Pair(-144, 24), Pair(229, -27), Pair(-58, 1), Pair(85, -34), Pair(-12, 39), Pair(-11, 29), Pair(11, -22),
      Pair(-136, 13), Pair(-66, 21), Pair(145, 19), Pair(155, 0), Pair(158, -2), Pair(102, -20), Pair(-127, 13), Pair(407, -67),
      Pair(-15, -13), Pair(343, -76), Pair(108, 7), Pair(235, -17), Pair(128, -15), Pair(336, -5), Pair(-86, -16), Pair(608, -34),
      Pair(-7, 21), Pair(160, -57), Pair(314, -49), Pair(-42, 29), Pair(-78, 43), Pair(-195, 46), Pair(-54, 1), Pair(-18, 40),
      Pair(-148, 85), Pair(283, 2), Pair(318, -40), Pair(-3, 8), Pair(-55, 15), Pair(62, 41), Pair(-227, -13), Pair(-78, 94),
      Pair(-229, 26), Pair(121, 69), Pair(-236, 63), Pair(-274, 96), Pair(-198, 53), Pair(-200, 66), Pair(-89, 89), Pair(-149, 49)
    },
    {
      Pair(270, 14), Pair(81, 74), Pair(233, 21), Pair(-72, 35), Pair(394, 27), Pair(-31, 82), Pair(156, 9), Pair(571, -48),
      Pair(404, -33), Pair(403, -23), Pair(210, 26), Pair(139, 7), Pair(184, 70), Pair(139, 28), Pair(251, -15), Pair(397, -23),
      Pair(46, 72), Pair(201, 42), Pair(64, 82), Pair(44, 22), Pair(109, 80), Pair(221, 17), Pair(90, 54), Pair(95, 73),
      Pair(183, 28), Pair(28, 52), Pair(98, 51), Pair(-431, 137), Pair(-35, 132), Pair(434, -31), Pair(385, -27), Pair(181, 75),
      Pair(-99, 88), Pair(147, 54), Pair(291, 42), Pair(-109, 53), Pair(556, -8), Pair(-40, 64), Pair(183, 28), Pair(32, 96),
      Pair(-20, 69), Pair(-94, 91), Pair(69, 22), Pair(49, 6), Pair(-308, 174), Pair(25, 48), Pair(74, 67), Pair(-135, 96),
      Pair(-244, 116), Pair(-112, 125), Pair(-205, 105), Pair(91, 24), Pair(-13, 114), Pair(-66, 70), Pair(-51, 80), Pair(-164, 122),
      Pair(-281, 140), Pair(-182, 137), Pair(112, 105), Pair(-253, 85), Pair(-98, 156), Pair(-24, 69), Pair(74, 25), Pair(-216, 151)
    },
    {
      Pair(231, -104), Pair(-464, 327), Pair(30, 85), Pair(187, 54), Pair(254, -18), Pair(-201, 181), Pair(140, 65), Pair(242, -64),
      Pair(145, 80), Pair(-208, 211), Pair(177, 105), Pair(89, 83), Pair(135, 77), Pair(-67, 157), Pair(70, 55), Pair(-12, 60),
      Pair(144, 57), Pair(312, -41), Pair(127, 82), Pair(333, -24), Pair(217, 53), Pair(75, 86), Pair(218, 38), Pair(-39, 69),
      Pair(113, 119), Pair(96, 136), Pair(218, 90), Pair(174, 35), Pair(157, 75), Pair(-16, 215), Pair(157, 95), Pair(127, 117),
      Pair(130, 58), Pair(165, 88), Pair(64, 56), Pair(-85, 190), Pair(109, 135), Pair(136, 146), Pair(-72, 208), Pair(109, 16),
      Pair(156, 30), Pair(100, 141), Pair(-54, 209), Pair(18, 160), Pair(-269, 260), Pair(-243, 241), Pair(218, 53), Pair(90, 68),
      Pair(344, 38), Pair(95, 9), Pair(-7, 155), Pair(-234, 209), Pair(-213, 277), Pair(75, 110), Pair(64, 123), Pair(-12, 193),
      Pair(10, 58), Pair(-50, -16), Pair(118, 52), Pair(-247, 329), Pair(-93, 118), Pair(-207, 213), Pair(-44, 2), Pair(-287, 147)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    }
  }}
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {{
  {
      Pair(-4, 45), Pair(20, 80), Pair(33, 114), Pair(40, 130), Pair(47, 139), Pair(52, 153), Pair(61, 152), Pair(64, 151),
      Pair(65, 143)
  },
  {
      Pair(114, 182), Pair(125, 161), Pair(135, 189), Pair(143, 199), Pair(150, 209), Pair(158, 219), Pair(162, 224), Pair(170, 222),
      Pair(176, 211)
  },
  {
      Pair(116, 151), Pair(125, 154), Pair(134, 179), Pair(142, 192), Pair(145, 208), Pair(146, 220), Pair(156, 219), Pair(156, 218),
      Pair(156, 204)
  },
  {
      Pair(126, 139), Pair(118, 123), Pair(127, 170), Pair(123, 189), Pair(117, 204), Pair(123, 214), Pair(119, 217), Pair(115, 218),
      Pair(124, 211)
  },
  {
      Pair(194, 122), Pair(190, 73), Pair(82, 155), Pair(74, 177), Pair(113, 183), Pair(116, 194), Pair(75, 202), Pair(99, 195),
      Pair(74, 189)
  },
  {
      Pair(137, 109), Pair(175, 125), Pair(53, 152), Pair(38, 167), Pair(109, 166), Pair(94, 175), Pair(103, 167), Pair(95, 163),
      Pair(107, 158)
  },
  {
      Pair(56, 134), Pair(-190, 96), Pair(90, 118), Pair(101, 116), Pair(114, 105), Pair(87, 131), Pair(-18, 127), Pair(218, 78),
      Pair(23, 72)
  }
}};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {{
  {
      Pair(8, 21), Pair(17, 35), Pair(27, 67), Pair(35, 82), Pair(43, 100), Pair(47, 114), Pair(51, 120), Pair(53, 126),
      Pair(54, 135), Pair(59, 137), Pair(74, 135), Pair(76, 138), Pair(74, 156), Pair(120, 132)
  },
  {
      Pair(105, 144), Pair(117, 135), Pair(136, 152), Pair(143, 176), Pair(151, 186), Pair(154, 194), Pair(157, 202), Pair(159, 209),
      Pair(160, 215), Pair(172, 199), Pair(167, 214), Pair(194, 204), Pair(192, 221), Pair(156, 210)
  },
  {
      Pair(88, 154), Pair(110, 133), Pair(118, 157), Pair(125, 175), Pair(134, 187), Pair(137, 201), Pair(140, 206), Pair(145, 215),
      Pair(154, 215), Pair(150, 218), Pair(162, 212), Pair(187, 210), Pair(204, 225), Pair(137, 219)
  },
  {
      Pair(63, 180), Pair(82, 133), Pair(122, 139), Pair(110, 166), Pair(118, 172), Pair(125, 190), Pair(122, 201), Pair(114, 210),
      Pair(123, 215), Pair(123, 215), Pair(117, 221), Pair(134, 224), Pair(130, 229), Pair(194, 202)
  },
  {
      Pair(131, 151), Pair(134, 81), Pair(107, 131), Pair(143, 139), Pair(143, 158), Pair(130, 171), Pair(136, 179), Pair(116, 181),
      Pair(80, 201), Pair(153, 185), Pair(83, 203), Pair(78, 214), Pair(43, 267), Pair(1, 216)
  },
  {
      Pair(-8, 218), Pair(316, 42), Pair(139, 86), Pair(175, 117), Pair(96, 136), Pair(120, 156), Pair(88, 163), Pair(118, 158),
      Pair(144, 170), Pair(95, 190), Pair(114, 171), Pair(29, 200), Pair(-3, 239), Pair(-110, 232)
  },
  {
      Pair(-224, 173), Pair(48, 66), Pair(293, 4), Pair(273, 34), Pair(219, 80), Pair(50, 106), Pair(67, 112), Pair(107, 122),
      Pair(36, 122), Pair(6, 146), Pair(104, 113), Pair(-23, 133), Pair(7, 207), Pair(-21, 126)
  }
}};

constexpr RookMobilityTable<ScorePair> kRookMobility = {{
  {
      Pair(-18, 70), Pair(-1, 127), Pair(0, 140), Pair(4, 148), Pair(9, 143), Pair(17, 148), Pair(22, 154), Pair(26, 162),
      Pair(32, 169), Pair(34, 175), Pair(39, 180), Pair(41, 187), Pair(41, 190), Pair(43, 179), Pair(18, 186)
  },
  {
      Pair(129, 232), Pair(138, 257), Pair(151, 272), Pair(152, 298), Pair(155, 309), Pair(164, 315), Pair(172, 321), Pair(175, 330),
      Pair(177, 337), Pair(188, 334), Pair(189, 341), Pair(196, 334), Pair(185, 347), Pair(194, 334), Pair(181, 336)
  },
  {
      Pair(132, 270), Pair(148, 307), Pair(149, 312), Pair(161, 319), Pair(160, 333), Pair(159, 344), Pair(157, 353), Pair(163, 354),
      Pair(170, 358), Pair(175, 363), Pair(182, 363), Pair(184, 370), Pair(194, 373), Pair(198, 376), Pair(208, 366)
  },
  {
      Pair(171, 189), Pair(157, 255), Pair(143, 271), Pair(165, 290), Pair(162, 306), Pair(137, 329), Pair(142, 330), Pair(135, 336),
      Pair(129, 346), Pair(150, 345), Pair(137, 354), Pair(148, 357), Pair(155, 364), Pair(128, 376), Pair(148, 365)
  },
  {
      Pair(292, 87), Pair(162, 220), Pair(200, 231), Pair(173, 272), Pair(131, 288), Pair(112, 306), Pair(105, 319), Pair(123, 312),
      Pair(124, 313), Pair(111, 327), Pair(144, 315), Pair(117, 332), Pair(147, 332), Pair(132, 339), Pair(96, 339)
  },
  {
      Pair(136, 191), Pair(41, 218), Pair(117, 213), Pair(92, 243), Pair(132, 233), Pair(131, 252), Pair(102, 287), Pair(55, 292),
      Pair(60, 290), Pair(88, 282), Pair(57, 302), Pair(98, 300), Pair(135, 296), Pair(142, 302), Pair(93, 309)
  },
  {
      Pair(148, -85), Pair(-202, 68), Pair(50, 173), Pair(155, 171), Pair(-41, 253), Pair(-84, 251), Pair(31, 265), Pair(40, 254),
      Pair(5, 253), Pair(131, 246), Pair(166, 225), Pair(125, 243), Pair(160, 234), Pair(152, 232), Pair(258, 216)
  }
}};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {{
  {
      Pair(-7, 300), Pair(71, -54), Pair(69, 191), Pair(79, 294), Pair(77, 349), Pair(80, 369), Pair(85, 383), Pair(86, 403),
      Pair(90, 415), Pair(95, 413), Pair(96, 426), Pair(97, 438), Pair(104, 429), Pair(107, 430), Pair(110, 434), Pair(116, 425),
      Pair(113, 433), Pair(121, 423), Pair(137, 408), Pair(139, 408), Pair(141, 398), Pair(202, 342), Pair(186, 349), Pair(182, 342),
      Pair(205, 349), Pair(346, 234), Pair(331, 188), Pair(181, 190)
  },
  {
      Pair(224, 198), Pair(313, 14), Pair(289, 366), Pair(295, 439), Pair(304, 459), Pair(309, 487), Pair(312, 510), Pair(317, 529),
      Pair(321, 541), Pair(325, 545), Pair(325, 569), Pair(332, 560), Pair(328, 571), Pair(326, 579), Pair(329, 573), Pair(331, 586),
      Pair(338, 581), Pair(320, 594), Pair(314, 605), Pair(332, 590), Pair(359, 559), Pair(397, 548), Pair(436, 519), Pair(426, 507),
      Pair(470, 470), Pair(542, 387), Pair(402, 496), Pair(251, 519)
  },
  {
      Pair(109, 392), Pair(269, 144), Pair(288, 451), Pair(286, 494), Pair(296, 544), Pair(298, 573), Pair(292, 622), Pair(299, 621),
      Pair(301, 639), Pair(299, 654), Pair(309, 647), Pair(307, 667), Pair(315, 662), Pair(304, 681), Pair(316, 672), Pair(321, 671),
      Pair(326, 669), Pair(341, 662), Pair(324, 671), Pair(382, 622), Pair(387, 630), Pair(462, 574), Pair(425, 591), Pair(507, 533),
      Pair(555, 517), Pair(534, 495), Pair(608, 489), Pair(324, 610)
  },
  {
      Pair(185, 251), Pair(-43, 419), Pair(34, 422), Pair(179, 171), Pair(245, 301), Pair(271, 296), Pair(220, 414), Pair(234, 444),
      Pair(218, 457), Pair(233, 469), Pair(224, 468), Pair(232, 480), Pair(198, 498), Pair(190, 530), Pair(214, 514), Pair(235, 498),
      Pair(232, 512), Pair(269, 492), Pair(283, 468), Pair(296, 453), Pair(379, 397), Pair(300, 454), Pair(386, 407), Pair(377, 383),
      Pair(376, 388), Pair(344, 425), Pair(370, 512), Pair(376, 438)
  },
  {
      Pair(34, 27), Pair(-110, 25), Pair(-201, 319), Pair(95, 176), Pair(86, 390), Pair(175, 100), Pair(45, 350), Pair(145, 274),
      Pair(102, 320), Pair(140, 329), Pair(127, 339), Pair(60, 410), Pair(153, 329), Pair(115, 389), Pair(150, 351), Pair(80, 400),
      Pair(75, 421), Pair(152, 355), Pair(269, 303), Pair(223, 319), Pair(144, 358), Pair(370, 244), Pair(85, 361), Pair(490, 142),
      Pair(479, 226), Pair(506, 184), Pair(102, 398), Pair(194, 165)
  },
  {
      Pair(26, -10), Pair(-82, -283), Pair(237, 189), Pair(-209, -397), Pair(419, 2), Pair(-46, 284), Pair(128, 253), Pair(118, 345),
      Pair(34, 400), Pair(-157, 514), Pair(226, 278), Pair(-87, 446), Pair(121, 335), Pair(142, 303), Pair(51, 390), Pair(150, 324),
      Pair(183, 312), Pair(-18, 435), Pair(146, 340), Pair(147, 349), Pair(175, 319), Pair(296, 266), Pair(358, 197), Pair(114, 314),
      Pair(389, 173), Pair(91, 306), Pair(110, 130), Pair(163, 280)
  },
  {
      Pair(-43, -86), Pair(-32, 33), Pair(102, 210), Pair(163, 254), Pair(58, 19), Pair(155, 39), Pair(42, 28), Pair(21, 118),
      Pair(-26, 339), Pair(146, 228), Pair(279, 141), Pair(-59, 281), Pair(254, 162), Pair(127, 196), Pair(360, 117), Pair(198, 182),
      Pair(-135, 426), Pair(265, 167), Pair(-68, 356), Pair(150, 198), Pair(62, 274), Pair(197, 235), Pair(-92, 328), Pair(-44, 333),
      Pair(384, 115), Pair(282, 184), Pair(-92, 309), Pair(77, 257)
  }
}};

constexpr KingBuckets<RankTable<ScorePair>> kPassedPawnBonus = {{
  {
      Pair(0, 0), Pair(-23, -82), Pair(-10, -76), Pair(-4, -34), Pair(32, 13), Pair(29, 99), Pair(118, 176), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-7, -42), Pair(-12, -24), Pair(0, 3), Pair(13, 53), Pair(1, 138), Pair(55, 125), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-43, -48), Pair(-50, -27), Pair(-30, 5), Pair(21, 48), Pair(16, 148), Pair(122, 183), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-69, -54), Pair(-38, -39), Pair(-54, 10), Pair(-14, 54), Pair(-11, 151), Pair(154, 191), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-65, -65), Pair(-24, -63), Pair(-64, -4), Pair(-48, 60), Pair(-46, 143), Pair(181, 162), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-50, -52), Pair(-18, -70), Pair(-24, -25), Pair(-66, 50), Pair(-137, 165), Pair(133, 157), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-14, -46), Pair(-52, -54), Pair(-73, 7), Pair(-46, 47), Pair(-113, 127), Pair(41, 168), Pair(0, 0)
  }
}};

constexpr KingBuckets<RankTable<ScorePair>> kPawnPhalanxBonus = {{
  {
      Pair(0, 0), Pair(5, -1), Pair(19, 7), Pair(28, 20), Pair(71, 85), Pair(151, 392), Pair(-9, 584), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(16, 0), Pair(19, 18), Pair(17, 30), Pair(48, 66), Pair(57, 428), Pair(80, 670), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(10, 3), Pair(19, 12), Pair(25, 25), Pair(58, 90), Pair(78, 360), Pair(-23, 519), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-7, 4), Pair(23, 8), Pair(15, 31), Pair(43, 106), Pair(-196, 396), Pair(-217, 508), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(10, -2), Pair(-13, 6), Pair(58, 13), Pair(33, 93), Pair(-257, 378), Pair(-398, 464), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-24, 6), Pair(-33, -3), Pair(51, -4), Pair(67, 76), Pair(-139, 215), Pair(-400, 700), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-125, 20), Pair(-55, 21), Pair(-138, 67), Pair(118, 64), Pair(-524, 240), Pair(-136, 88), Pair(0, 0)
  }
}};

constexpr KingBuckets<RankTable<ScorePair>> kDefendedPawnBonus = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(27, 28), Pair(16, 23), Pair(16, 29), Pair(23, 107), Pair(113, 158), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(26, 23), Pair(17, 20), Pair(20, 28), Pair(30, 70), Pair(234, 110), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(33, 11), Pair(25, 9), Pair(17, 24), Pair(30, 73), Pair(182, 113), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(40, 5), Pair(34, -1), Pair(24, 18), Pair(-10, 77), Pair(156, 77), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(7, 7), Pair(40, -6), Pair(19, 7), Pair(60, 48), Pair(-16, 62), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(-13, 10), Pair(14, -2), Pair(26, 17), Pair(68, 32), Pair(54, -5), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(-59, 29), Pair(-67, 25), Pair(38, 26), Pair(-8, 30), Pair(143, -10), Pair(0, 0)
  }
}};

constexpr KingBuckets<FileTable<ScorePair>> kDoubledPawnPenalty = {{
  {
      Pair(-9, -61), Pair(5, -30), Pair(-4, -26), Pair(0, -23), Pair(-18, 1), Pair(-24, -5), Pair(12, -34), Pair(-31, -50)
  },
  {
      Pair(-63, -27), Pair(11, -28), Pair(6, -33), Pair(-9, 0), Pair(-2, 0), Pair(-2, -16), Pair(-11, -26), Pair(-7, -53)
  },
  {
      Pair(-4, -55), Pair(-1, -24), Pair(2, -31), Pair(4, -10), Pair(-4, -3), Pair(-10, -20), Pair(-2, -29), Pair(15, -67)
  },
  {
      Pair(-30, -52), Pair(-47, -29), Pair(3, -38), Pair(7, -19), Pair(10, -14), Pair(-5, -30), Pair(-8, -32), Pair(-63, -50)
  },
  {
      Pair(-21, -51), Pair(17, -75), Pair(-8, -49), Pair(88, -47), Pair(95, -53), Pair(-13, -54), Pair(-19, -44), Pair(102, -92)
  },
  {
      Pair(102, -93), Pair(-20, -70), Pair(-67, -54), Pair(83, -64), Pair(67, -55), Pair(-3, -61), Pair(-39, -47), Pair(68, -113)
  },
  {
      Pair(61, -67), Pair(-96, 22), Pair(-252, 6), Pair(-196, -138), Pair(6, -26), Pair(-57, -37), Pair(-130, -17), Pair(-8, -91)
  }
}};

constexpr KingBuckets<FileTable<ScorePair>> kIsolatedPawnPenalty = {{
  {
      Pair(1, -4), Pair(-3, -19), Pair(-14, -17), Pair(-12, -18), Pair(-20, -20), Pair(-12, -5), Pair(1, -25), Pair(2, -2)
  },
  {
      Pair(-9, 0), Pair(0, -18), Pair(-10, -15), Pair(-12, -16), Pair(-10, -26), Pair(3, -17), Pair(2, -16), Pair(-3, -4)
  },
  {
      Pair(6, -4), Pair(3, -19), Pair(-7, -17), Pair(0, -28), Pair(-4, -29), Pair(-2, -16), Pair(-1, -18), Pair(13, -7)
  },
  {
      Pair(15, 4), Pair(-20, -17), Pair(-6, -12), Pair(18, -31), Pair(8, -32), Pair(0, -14), Pair(12, -19), Pair(9, -3)
  },
  {
      Pair(12, 19), Pair(-19, -19), Pair(-18, 3), Pair(12, -23), Pair(-17, -21), Pair(-21, -5), Pair(-3, -13), Pair(-27, 15)
  },
  {
      Pair(-7, 28), Pair(-19, -19), Pair(-61, 20), Pair(-2, -10), Pair(-48, -7), Pair(14, -9), Pair(-55, -2), Pair(-25, 21)
  },
  {
      Pair(107, 6), Pair(-100, 2), Pair(-59, 8), Pair(126, -5), Pair(-20, -11), Pair(-26, 3), Pair(51, -13), Pair(0, 26)
  }
}};

constexpr KingBuckets<std::array<FileTable<ScorePair>, 2>> kRookOnFileBonus = {{
  {{ // Bucket 0
    {
      Pair(21, 18), Pair(19, 11), Pair(19, 26), Pair(22, 15), Pair(26, 20), Pair(50, 5), Pair(46, 20), Pair(135, -34)
    },
    {
      Pair(11, 24), Pair(12, 0), Pair(14, 15), Pair(25, 10), Pair(20, 2), Pair(30, -9), Pair(29, -17), Pair(58, -16)
    }
  }},
  {{ // Bucket 1
    {
      Pair(57, 4), Pair(16, 12), Pair(5, 23), Pair(38, -5), Pair(28, 17), Pair(34, 10), Pair(58, 20), Pair(81, 12)
    },
    {
      Pair(61, 22), Pair(37, 2), Pair(12, 20), Pair(33, -18), Pair(38, -8), Pair(33, -21), Pair(46, -8), Pair(20, 14)
    }
  }},
  {{ // Bucket 2
    {
      Pair(24, 12), Pair(34, 0), Pair(33, 4), Pair(29, 13), Pair(36, 17), Pair(34, 12), Pair(52, 3), Pair(75, -3)
    },
    {
      Pair(8, 49), Pair(18, 8), Pair(17, 5), Pair(22, 2), Pair(16, 4), Pair(22, -4), Pair(30, -15), Pair(11, 18)
    }
  }},
  {{ // Bucket 3
    {
      Pair(29, 8), Pair(62, -16), Pair(89, -22), Pair(47, -6), Pair(63, 0), Pair(42, 7), Pair(86, -13), Pair(95, 1)
    },
    {
      Pair(-11, 64), Pair(29, 10), Pair(51, -8), Pair(24, -8), Pair(45, -11), Pair(25, -10), Pair(32, 3), Pair(19, 24)
    }
  }},
  {{ // Bucket 4
    {
      Pair(31, -2), Pair(114, -38), Pair(66, -13), Pair(48, -19), Pair(93, -18), Pair(23, 2), Pair(42, -6), Pair(35, 11)
    },
    {
      Pair(-64, 87), Pair(30, 13), Pair(85, -11), Pair(28, -15), Pair(43, -21), Pair(70, -12), Pair(55, -16), Pair(-180, 96)
    }
  }},
  {{ // Bucket 5
    {
      Pair(132, -29), Pair(137, -48), Pair(83, -39), Pair(80, -29), Pair(90, -29), Pair(21, -22), Pair(166, -47), Pair(2, 16)
    },
    {
      Pair(-61, 113), Pair(-10, 20), Pair(92, 1), Pair(160, -39), Pair(52, -20), Pair(-6, -6), Pair(136, -23), Pair(-189, 112)
    }
  }},
  {{ // Bucket 6
    {
      Pair(132, -40), Pair(106, -10), Pair(125, -42), Pair(153, 15), Pair(87, -68), Pair(176, -34), Pair(27, 5), Pair(124, -51)
    },
    {
      Pair(78, 92), Pair(-49, 57), Pair(-46, -2), Pair(225, -13), Pair(302, -104), Pair(165, -3), Pair(12, 56), Pair(138, 35)
    }
  }}
}};

constexpr KingBuckets<std::array<ScorePair, 12>> kPawnShelterTable = {{
  {
      Pair(22, -13), Pair(47, -20), Pair(17, -8),
      Pair(45, -25), Pair(57, -37), Pair(45, -29),
      Pair(54, -10), Pair(0, 0), Pair(47, -8),
      Pair(18, -1), Pair(21, -12), Pair(16, 0)
  },
  {
      Pair(18, -10), Pair(10, -1), Pair(13, -7),
      Pair(37, -23), Pair(32, -5), Pair(35, -27),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(13, -5), Pair(12, -3), Pair(12, -3),
      Pair(30, -18), Pair(16, -13), Pair(29, -16),
      Pair(55, -19), Pair(0, 0), Pair(50, -18),
      Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(64, -2), Pair(85, -8), Pair(37, 6),
      Pair(30, -6), Pair(69, -22), Pair(31, -7),
      Pair(43, -8), Pair(0, 0), Pair(49, -7),
      Pair(14, -5), Pair(79, -38), Pair(11, -4)
  },
  {
      Pair(109, 2), Pair(101, 22), Pair(26, 32),
      Pair(56, -15), Pair(30, 9), Pair(48, -10),
      Pair(64, 8), Pair(0, 0), Pair(46, 12),
      Pair(6, 3), Pair(18, 8), Pair(17, 3)
  },
  {
      Pair(134, -22), Pair(12, -13), Pair(68, 27),
      Pair(194, -23), Pair(160, -14), Pair(153, -15),
      Pair(70, 37), Pair(0, 0), Pair(23, 44),
      Pair(26, 6), Pair(84, -25), Pair(49, 12)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(-161, 47), Pair(0, 0), Pair(-103, 51),
      Pair(-64, 51), Pair(139, -114), Pair(122, 13)
  }
}};

constexpr KingBuckets<std::array<ScorePair, 21>> kPawnStormTable = {{
  {
      Pair(-13, 12), Pair(-23, 13), Pair(-13, 11),
      Pair(-12, 7), Pair(-30, 22), Pair(-14, 11),
      Pair(-4, -3), Pair(-24, 16), Pair(-4, 1),
      Pair(13, -1), Pair(-15, 11), Pair(11, -3),
      Pair(35, -10), Pair(35, 10), Pair(20, -8),
      Pair(120, -24), Pair(41, -63), Pair(148, -53),
      Pair(95, -93), Pair(0, 0), Pair(90, -87)
  },
  {
      Pair(-7, 9), Pair(-17, 19), Pair(-11, 13),
      Pair(-8, 10), Pair(-23, 22), Pair(-16, 13),
      Pair(-5, 4), Pair(-21, 19), Pair(-6, 7),
      Pair(13, 3), Pair(-10, 9), Pair(11, 8),
      Pair(27, -4), Pair(28, 2), Pair(18, -11),
      Pair(66, 20), Pair(5, -45), Pair(56, -50),
      Pair(32, -45), Pair(0, 0), Pair(45, -61)
  },
  {
      Pair(-6, 7), Pair(-21, 17), Pair(-12, 9),
      Pair(-7, 4), Pair(-17, 11), Pair(-11, 7),
      Pair(-1, -1), Pair(-21, 13), Pair(-7, 3),
      Pair(12, -1), Pair(-12, 8), Pair(11, 2),
      Pair(25, -4), Pair(22, 12), Pair(20, -4),
      Pair(42, 6), Pair(-14, -32), Pair(59, -29),
      Pair(54, -56), Pair(0, 0), Pair(57, -59)
  },
  {
      Pair(7, -4), Pair(-12, 10), Pair(-8, 4),
      Pair(-9, 3), Pair(-14, 14), Pair(-3, 4),
      Pair(-7, -2), Pair(-15, 8), Pair(6, -5),
      Pair(10, -1), Pair(7, -3), Pair(8, 1),
      Pair(11, -3), Pair(36, 6), Pair(9, -3),
      Pair(16, -2), Pair(-11, -31), Pair(69, -21),
      Pair(67, -64), Pair(0, 0), Pair(31, -54)
  },
  {
      Pair(62, -28), Pair(-37, 18), Pair(20, -16),
      Pair(12, -10), Pair(44, -3), Pair(-3, -6),
      Pair(-13, -5), Pair(-7, 5), Pair(-15, -5),
      Pair(11, -14), Pair(19, -14), Pair(23, -11),
      Pair(40, -12), Pair(47, -10), Pair(5, -8),
      Pair(8, -5), Pair(36, -60), Pair(53, -20),
      Pair(54, -68), Pair(0, 0), Pair(44, -58)
  },
  {
      Pair(34, -16), Pair(24, 3), Pair(-20, -11),
      Pair(-38, -5), Pair(-5, 7), Pair(-25, -6),
      Pair(9, -18), Pair(37, -17), Pair(-25, -12),
      Pair(6, -21), Pair(53, -32), Pair(3, -23),
      Pair(10, -23), Pair(49, -39), Pair(27, -28),
      Pair(46, -36), Pair(136, -122), Pair(10, -6),
      Pair(57, -70), Pair(0, 0), Pair(28, -66)
  },
  {
      Pair(2, -13), Pair(-2, 28), Pair(-14, -14),
      Pair(-214, 19), Pair(-84, 40), Pair(-96, 15),
      Pair(58, -33), Pair(-55, -11), Pair(-57, -9),
      Pair(-57, -11), Pair(-47, -8), Pair(-88, 12),
      Pair(108, -52), Pair(-14, -37), Pair(-44, -28),
      Pair(2, -45), Pair(58, -120), Pair(-3, 32),
      Pair(60, -48), Pair(0, 0), Pair(-100, -61)
  }
}};

constexpr KingBuckets<std::array<ScorePair, 8>> kKingPPDistanceTable = {{
  {
      Pair(0, 0), Pair(9, 43), Pair(-5, 47), Pair(-6, 32), Pair(-2, 32), Pair(4, 33), Pair(7, 40), Pair(-16, 38)
  },
  {
      Pair(0, 0), Pair(-8, 13), Pair(-10, 9), Pair(-10, 9), Pair(-5, 10), Pair(-3, 14), Pair(55, 125), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(10, 33), Pair(-7, 31), Pair(-13, 23), Pair(-12, 13), Pair(-21, 19), Pair(-9, 13), Pair(28, -2)
  },
  {
      Pair(0, 0), Pair(7, 44), Pair(-11, 35), Pair(-15, 27), Pair(-34, 20), Pair(-68, 20), Pair(-43, 9), Pair(-66, -6)
  },
  {
      Pair(0, 0), Pair(11, 44), Pair(-6, 35), Pair(-23, 14), Pair(-80, 14), Pair(-72, -2), Pair(-128, 16), Pair(-36, -9)
  },
  {
      Pair(0, 0), Pair(-28, 65), Pair(24, 38), Pair(-9, 3), Pair(-65, -16), Pair(-134, -10), Pair(-47, -25), Pair(-138, 2)
  },
  {
      Pair(0, 0), Pair(-56, 161), Pair(21, 101), Pair(-17, 20), Pair(3, -16), Pair(-63, -21), Pair(-176, 3), Pair(-38, -30)
  }
}};

constexpr KingBuckets<std::array<ScorePair, 8>> kEnemyKingPPDistanceTable = {{
  {
      Pair(0, 0), Pair(-111, 1), Pair(-17, 0), Pair(-5, 33), Pair(7, 47), Pair(10, 59), Pair(14, 66), Pair(9, 41)
  },
  {
      Pair(0, 0), Pair(-88, -23), Pair(-17, -11), Pair(-3, 15), Pair(-3, 32), Pair(-5, 43), Pair(-7, 53), Pair(-33, 43)
  },
  {
      Pair(0, 0), Pair(-102, -14), Pair(-7, -8), Pair(-4, 24), Pair(7, 38), Pair(16, 47), Pair(15, 57), Pair(8, 48)
  },
  {
      Pair(0, 0), Pair(-64, -24), Pair(-27, -3), Pair(-21, 30), Pair(-15, 48), Pair(-7, 62), Pair(16, 61), Pair(-4, 50)
  },
  {
      Pair(0, 0), Pair(-37, -35), Pair(14, -7), Pair(-37, 44), Pair(-32, 67), Pair(-31, 79), Pair(-1, 77), Pair(-30, 78)
  },
  {
      Pair(0, 0), Pair(-85, -15), Pair(17, -3), Pair(-21, 44), Pair(-49, 70), Pair(-22, 81), Pair(-1, 89), Pair(-15, 80)
  },
  {
      Pair(0, 0), Pair(62, -47), Pair(-12, -1), Pair(-73, 47), Pair(-64, 79), Pair(-73, 102), Pair(-30, 82), Pair(-88, 80)
  }
}};

constexpr KingBuckets<ScorePair> kKingCantReachPPBonus = {
  Pair(-588, 278), Pair(29, 329), Pair(-403, 364), Pair(-231, 378), Pair(-314, 253), Pair(-182, 131), Pair(173, 95)
};


constexpr KingBuckets<std::array<FileTable<ScorePair>, 2>> kKingOnFilePenalty = {{
  {{ // Bucket 0
    {
      Pair(-162, 20), Pair(-130, -7), Pair(-30, -16), Pair(-17, -21), Pair(-22, -13), Pair(-28, -12), Pair(-66, -13), Pair(-52, -1)
    },
    {
      Pair(-37, 169), Pair(-63, 68), Pair(-9, 10), Pair(2, -8), Pair(-7, -6), Pair(2, 0), Pair(-33, 27), Pair(-9, 59)
    }
  }},
  {{ // Bucket 1
    {
      Pair(-9, 45), Pair(-35, 18), Pair(-39, -10), Pair(-36, -1), Pair(-44, 10), Pair(-61, 0), Pair(-27, 18), Pair(-16, 29)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(-17, 47), Pair(-15, 46), Pair(-26, 33), Pair(-35, 30), Pair(0, 0), Pair(0, 0)
    }
  }},
  {{ // Bucket 2
    {
      Pair(-151, -5), Pair(-89, -18), Pair(-39, -12), Pair(-64, -5), Pair(-55, -4), Pair(-57, -1), Pair(-69, -7), Pair(-53, -4)
    },
    {
      Pair(-52, 83), Pair(-59, 39), Pair(-42, 43), Pair(-19, 20), Pair(-17, 7), Pair(5, 7), Pair(-44, 31), Pair(-54, 50)
    }
  }},
  {{ // Bucket 3
    {
      Pair(-64, -28), Pair(-9, -20), Pair(-10, -20), Pair(-29, -9), Pair(4, -19), Pair(-18, -13), Pair(-23, -12), Pair(-44, 5)
    },
    {
      Pair(-13, 34), Pair(62, -16), Pair(51, -18), Pair(50, -29), Pair(63, -40), Pair(35, -12), Pair(34, 0), Pair(22, 19)
    }
  }},
  {{ // Bucket 4
    {
      Pair(38, -21), Pair(7, -4), Pair(-140, 26), Pair(-60, 17), Pair(-59, 20), Pair(-107, 28), Pair(-43, 10), Pair(21, 20)
    },
    {
      Pair(68, -4), Pair(-14, -6), Pair(-65, 16), Pair(38, -27), Pair(0, -16), Pair(-55, 7), Pair(-24, 8), Pair(4, 10)
    }
  }},
  {{ // Bucket 5
    {
      Pair(60, -34), Pair(-65, -29), Pair(-67, -12), Pair(-24, -15), Pair(42, -8), Pair(-68, 5), Pair(6, -17), Pair(20, 3)
    },
    {
      Pair(57, -57), Pair(-26, -58), Pair(-26, -35), Pair(182, -78), Pair(106, -74), Pair(-100, -18), Pair(-16, -35), Pair(-20, -27)
    }
  }},
  {{ // Bucket 6
    {
      Pair(157, -80), Pair(48, -112), Pair(146, -107), Pair(191, -72), Pair(56, -37), Pair(-28, -20), Pair(97, -91), Pair(308, -65)
    },
    {
      Pair(143, -15), Pair(103, -81), Pair(269, -127), Pair(94, -36), Pair(112, -58), Pair(27, -25), Pair(107, -37), Pair(208, -114)
    }
  }}
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {{ // Bucket 0
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(14, 3), Pair(32, -12), Pair(56, -39), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(17, 6), Pair(35, 9), Pair(87, -14), Pair(111, -53), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(26, -27), Pair(47, -30), Pair(77, -25), Pair(134, -39), Pair(165, -71), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(3, 12), Pair(11, 31), Pair(30, 56), Pair(81, 49), Pair(130, 56), Pair(191, 42), Pair(268, -61)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    }
  }},
  {{ // Bucket 1
    {
      Pair(0, 0), Pair(12, 2), Pair(25, -7), Pair(61, -28), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(13, -2), Pair(27, -7), Pair(63, -46), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(20, -3), Pair(37, -4), Pair(70, -18), Pair(90, -94), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(31, -27), Pair(48, -29), Pair(43, -11), Pair(92, -22), Pair(139, -38), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(4, 25), Pair(14, 66), Pair(33, 74), Pair(75, 60), Pair(103, 55), Pair(156, 70), Pair(328, -106)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    }
  }},
  {{ // Bucket 2
    {
      Pair(0, 0), Pair(15, 0), Pair(30, -2), Pair(62, -12), Pair(71, -44), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(35, -3), Pair(51, -14), Pair(100, -47), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(29, -4), Pair(52, -7), Pair(89, -17), Pair(65, -54), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(30, -27), Pair(53, -28), Pair(81, -24), Pair(108, -26), Pair(126, -37), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(3, 23), Pair(19, 31), Pair(57, 22), Pair(128, -7), Pair(159, -12), Pair(275, -56), Pair(370, -113)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    }
  }},
  {{ // Bucket 3
    {
      Pair(0, 0), Pair(21, -20), Pair(35, -20), Pair(51, -14), Pair(80, -17), Pair(91, -26), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(38, 0), Pair(74, -17), Pair(100, -26), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(34, -5), Pair(58, -8), Pair(83, -15), Pair(55, -52), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(43, -32), Pair(67, -30), Pair(78, -18), Pair(113, -18), Pair(103, -21), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(19, 13), Pair(60, 11), Pair(89, 1), Pair(177, -21), Pair(259, -57), Pair(480, -165), Pair(307, -57)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    }
  }},
  {{ // Bucket 4
    {
      Pair(0, 0), Pair(2, 14), Pair(10, 25), Pair(29, 31), Pair(74, 14), Pair(110, 10), Pair(173, -13), Pair(232, -63)
    },
    {
      Pair(0, 0), Pair(120, -16), Pair(111, -22), Pair(176, -33), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(-5, 6), Pair(3, 2), Pair(54, -8), Pair(-204, 21), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(26, -17), Pair(71, -23), Pair(58, -8), Pair(107, -13), Pair(166, -32), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(-52, 78), Pair(-5, 48), Pair(62, 25), Pair(58, 35), Pair(314, -66), Pair(452, -152), Pair(343, -105)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    }
  }},
  {{ // Bucket 5
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(75, -3), Pair(120, -16), Pair(2, -4), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(28, 9), Pair(73, -4), Pair(82, -18), Pair(-132, -12), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(25, -15), Pair(123, -35), Pair(140, -21), Pair(43, 13), Pair(16, 4), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(92, 9), Pair(16, 47), Pair(150, -18), Pair(307, -101), Pair(407, -93), Pair(286, -25), Pair(-210, 208)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    }
  }},
  {{ // Bucket 6
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(69, -8), Pair(224, -53), Pair(310, -102), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(-33, 12), Pair(67, -26), Pair(171, -32), Pair(139, -72), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(98, -41), Pair(47, -5), Pair(130, -19), Pair(31, 6), Pair(242, -27), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(-197, 142), Pair(198, -74), Pair(314, -139), Pair(-52, 47), Pair(213, -56), Pair(141, -3), Pair(-4, 173)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    }
  }}
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {{
  {
      Pair(0, 0), Pair(57, 36), Pair(18, 58), Pair(79, -2), Pair(29, 34), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(40, 28), Pair(19, 25), Pair(72, 8), Pair(26, 24), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(90, 16), Pair(44, 24), Pair(78, 6), Pair(35, 24), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(88, 4), Pair(85, 14), Pair(72, 3), Pair(74, -9), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(109, -6), Pair(81, 21), Pair(55, 7), Pair(135, -38), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(118, -13), Pair(50, 21), Pair(108, -7), Pair(150, -43), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(109, -10), Pair(0, 28), Pair(174, -41), Pair(163, -57), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {{ // Bucket 0
    {
      Pair(-29, 26), Pair(-18, 24)
    },
    {
      Pair(-95, -33), Pair(-91, -43)
    },
    {
      Pair(-73, -70), Pair(-95, -91)
    },
    {
      Pair(-124, -5), Pair(-122, -25)
    },
    {
      Pair(-92, -22), Pair(-104, -24)
    },
    {
      Pair(81, 11), Pair(31, 33)
    }
  }},
  {{ // Bucket 1
    {
      Pair(-19, 25), Pair(-6, 28)
    },
    {
      Pair(-96, -42), Pair(-102, -23)
    },
    {
      Pair(-103, -51), Pair(-92, -111)
    },
    {
      Pair(-146, 10), Pair(-153, -21)
    },
    {
      Pair(-84, -61), Pair(-143, 144)
    },
    {
      Pair(-107, 53), Pair(-3, 69)
    }
  }},
  {{ // Bucket 2
    {
      Pair(-23, 24), Pair(-12, 28)
    },
    {
      Pair(-65, -49), Pair(-93, -57)
    },
    {
      Pair(-71, -77), Pair(-79, -126)
    },
    {
      Pair(-153, 2), Pair(-105, -81)
    },
    {
      Pair(-111, 118), Pair(-127, 40)
    },
    {
      Pair(1, 2), Pair(-33, -21)
    }
  }},
  {{ // Bucket 3
    {
      Pair(-19, 2), Pair(-14, 28)
    },
    {
      Pair(-130, -13), Pair(-44, -94)
    },
    {
      Pair(-104, -69), Pair(-49, -121)
    },
    {
      Pair(-104, 1), Pair(-44, -99)
    },
    {
      Pair(-66, 72), Pair(-171, 148)
    },
    {
      Pair(-161, 26), Pair(-152, 35)
    }
  }},
  {{ // Bucket 4
    {
      Pair(-39, 6), Pair(8, 27)
    },
    {
      Pair(-140, -24), Pair(222, -138)
    },
    {
      Pair(6, -76), Pair(-113, -87)
    },
    {
      Pair(-88, -33), Pair(-351, -22)
    },
    {
      Pair(118, 15), Pair(-17, 67)
    },
    {
      Pair(-109, 43), Pair(-80, 0)
    }
  }},
  {{ // Bucket 5
    {
      Pair(-46, 43), Pair(-11, 43)
    },
    {
      Pair(127, -76), Pair(-262, -53)
    },
    {
      Pair(30, -51), Pair(-363, -43)
    },
    {
      Pair(-18, -21), Pair(95, -83)
    },
    {
      Pair(91, -33), Pair(-50, -109)
    },
    {
      Pair(-88, 42), Pair(-102, 42)
    }
  }},
  {{ // Bucket 6
    {
      Pair(-121, 76), Pair(-367, 146)
    },
    {
      Pair(23, -52), Pair(-85, 37)
    },
    {
      Pair(69, -118), Pair(63, 44)
    },
    {
      Pair(-119, -6), Pair(20, -230)
    },
    {
      Pair(27, 47), Pair(33, 67)
    },
    {
      Pair(-25, -120), Pair(29, 26)
    }
  }}
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {{
  {
      Pair(0, 0), Pair(22, 44), Pair(28, 27), Pair(38, 21), Pair(31, -4), Pair(145, -137)
  },
  {
      Pair(0, 0), Pair(25, 36), Pair(31, 37), Pair(50, 12), Pair(27, 11), Pair(124, -96)
  },
  {
      Pair(0, 0), Pair(34, 43), Pair(31, 38), Pair(35, 15), Pair(37, -3), Pair(106, -40)
  },
  {
      Pair(0, 0), Pair(56, 41), Pair(14, 33), Pair(63, 3), Pair(59, -70), Pair(46, 7)
  },
  {
      Pair(0, 0), Pair(15, 54), Pair(146, -29), Pair(42, 12), Pair(-49, 83), Pair(16, 26)
  },
  {
      Pair(0, 0), Pair(109, 39), Pair(-12, 32), Pair(-10, 39), Pair(92, -49), Pair(68, 20)
  },
  {
      Pair(0, 0), Pair(-172, 70), Pair(-48, 44), Pair(-239, 98), Pair(96, 83), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {{ // Bucket 0
    {
      Pair(-7, -22), Pair(12, -17)
    },
    {
      Pair(-35, -68), Pair(-11, -92)
    },
    {
      Pair(-62, -52), Pair(-40, -52)
    },
    {
      Pair(-111, -9), Pair(-89, -36)
    },
    {
      Pair(-71, -13), Pair(-80, 15)
    },
    {
      Pair(-115, 3), Pair(-55, -77)
    }
  }},
  {{ // Bucket 1
    {
      Pair(-3, -29), Pair(13, -15)
    },
    {
      Pair(-47, -43), Pair(-11, -86)
    },
    {
      Pair(-46, -58), Pair(-41, -56)
    },
    {
      Pair(-106, -32), Pair(-71, -69)
    },
    {
      Pair(-97, 156), Pair(-87, 69)
    },
    {
      Pair(-149, -5), Pair(-87, -13)
    }
  }},
  {{ // Bucket 2
    {
      Pair(10, -38), Pair(15, -16)
    },
    {
      Pair(-34, -64), Pair(3, -99)
    },
    {
      Pair(-36, -58), Pair(-35, -44)
    },
    {
      Pair(-119, 5), Pair(-76, -51)
    },
    {
      Pair(-59, 73), Pair(-57, -6)
    },
    {
      Pair(-162, 11), Pair(-126, -26)
    }
  }},
  {{ // Bucket 3
    {
      Pair(27, -39), Pair(10, -11)
    },
    {
      Pair(-105, -52), Pair(-39, -72)
    },
    {
      Pair(-129, -24), Pair(-58, -46)
    },
    {
      Pair(-117, 2), Pair(-77, -54)
    },
    {
      Pair(-180, 198), Pair(-96, 201)
    },
    {
      Pair(-164, 8), Pair(-183, -8)
    }
  }},
  {{ // Bucket 4
    {
      Pair(101, -52), Pair(36, -29)
    },
    {
      Pair(-110, -74), Pair(197, -107)
    },
    {
      Pair(-60, -26), Pair(-50, -49)
    },
    {
      Pair(-190, 26), Pair(112, -113)
    },
    {
      Pair(42, 243), Pair(84, 147)
    },
    {
      Pair(-180, 0), Pair(-51, -16)
    }
  }},
  {{ // Bucket 5
    {
      Pair(18, -24), Pair(39, -37)
    },
    {
      Pair(97, -75), Pair(328, -92)
    },
    {
      Pair(41, -43), Pair(-56, -54)
    },
    {
      Pair(34, -25), Pair(147, -97)
    },
    {
      Pair(274, -25), Pair(229, 144)
    },
    {
      Pair(-238, 37), Pair(-11, -42)
    }
  }},
  {{ // Bucket 6
    {
      Pair(103, -29), Pair(99, -35)
    },
    {
      Pair(-91, -104), Pair(-28, -36)
    },
    {
      Pair(-103, -30), Pair(-51, -178)
    },
    {
      Pair(20, 52), Pair(94, -93)
    },
    {
      Pair(72, 45), Pair(51, 11)
    },
    {
      Pair(-112, 41), Pair(-4, -18)
    }
  }}
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {{ // Bucket 0
    {
      Pair(-19, -21), Pair(1, -9)
    },
    {
      Pair(-66, -45), Pair(-30, -44)
    },
    {
      Pair(30, -203), Pair(47, -206)
    },
    {
      Pair(-117, -11), Pair(-69, -48)
    },
    {
      Pair(-110, -77), Pair(-81, -130)
    },
    {
      Pair(-38, -41), Pair(-56, -44)
    }
  }},
  {{ // Bucket 1
    {
      Pair(-13, -20), Pair(-1, -3)
    },
    {
      Pair(-77, -22), Pair(-31, -24)
    },
    {
      Pair(30, -240), Pair(40, -183)
    },
    {
      Pair(-111, -9), Pair(-65, -51)
    },
    {
      Pair(-112, 20), Pair(-89, -80)
    },
    {
      Pair(1, -17), Pair(-39, -57)
    }
  }},
  {{ // Bucket 2
    {
      Pair(-3, -33), Pair(1, -11)
    },
    {
      Pair(-51, -36), Pair(-27, -29)
    },
    {
      Pair(17, -215), Pair(50, -205)
    },
    {
      Pair(-91, -23), Pair(-49, -80)
    },
    {
      Pair(-132, -4), Pair(-158, -47)
    },
    {
      Pair(-138, 8), Pair(-56, -49)
    }
  }},
  {{ // Bucket 3
    {
      Pair(28, -52), Pair(-5, -17)
    },
    {
      Pair(-95, -21), Pair(0, -51)
    },
    {
      Pair(109, -246), Pair(1, -204)
    },
    {
      Pair(-107, -6), Pair(-19, -87)
    },
    {
      Pair(-137, 44), Pair(-78, -115)
    },
    {
      Pair(12, -31), Pair(-64, -51)
    }
  }},
  {{ // Bucket 4
    {
      Pair(31, -42), Pair(37, -38)
    },
    {
      Pair(-180, 5), Pair(40, -46)
    },
    {
      Pair(165, -236), Pair(-33, -194)
    },
    {
      Pair(-22, 8), Pair(-176, 22)
    },
    {
      Pair(-507, 380), Pair(-298, 184)
    },
    {
      Pair(-90, -11), Pair(108, -28)
    }
  }},
  {{ // Bucket 5
    {
      Pair(90, -57), Pair(86, -44)
    },
    {
      Pair(129, -66), Pair(-18, -54)
    },
    {
      Pair(146, -186), Pair(5, -182)
    },
    {
      Pair(177, -112), Pair(0, -66)
    },
    {
      Pair(99, 5), Pair(-139, -26)
    },
    {
      Pair(-222, 33), Pair(2, -77)
    }
  }},
  {{ // Bucket 6
    {
      Pair(68, -65), Pair(84, -54)
    },
    {
      Pair(-230, -45), Pair(96, -81)
    },
    {
      Pair(-169, -108), Pair(-159, -148)
    },
    {
      Pair(64, -84), Pair(-117, -128)
    },
    {
      Pair(106, 219), Pair(0, 0)
    },
    {
      Pair(-37, -39), Pair(11, 88)
    }
  }}
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {{ // Bucket 0
    {
      Pair(-6, -31), Pair(15, -8)
    },
    {
      Pair(-54, -51), Pair(-3, -26)
    },
    {
      Pair(-46, -43), Pair(-16, -10)
    },
    {
      Pair(-4, -96), Pair(25, -58)
    },
    {
      Pair(-108, -21), Pair(-77, -76)
    },
    {
      Pair(-46, -21), Pair(-65, -24)
    }
  }},
  {{ // Bucket 1
    {
      Pair(4, -38), Pair(22, -20)
    },
    {
      Pair(-60, -30), Pair(-1, -21)
    },
    {
      Pair(-36, -36), Pair(-18, 3)
    },
    {
      Pair(13, -108), Pair(21, -83)
    },
    {
      Pair(-120, -8), Pair(-85, -92)
    },
    {
      Pair(-102, 13), Pair(-6, -41)
    }
  }},
  {{ // Bucket 2
    {
      Pair(5, -40), Pair(16, -13)
    },
    {
      Pair(-52, -35), Pair(1, -14)
    },
    {
      Pair(-34, -48), Pair(-20, -6)
    },
    {
      Pair(-2, -103), Pair(24, -65)
    },
    {
      Pair(-131, 33), Pair(-114, -11)
    },
    {
      Pair(-105, 10), Pair(-122, -12)
    }
  }},
  {{ // Bucket 3
    {
      Pair(35, -49), Pair(24, -26)
    },
    {
      Pair(-18, -38), Pair(33, -31)
    },
    {
      Pair(-16, -57), Pair(-20, -6)
    },
    {
      Pair(56, -117), Pair(17, -60)
    },
    {
      Pair(-150, 113), Pair(-151, 39)
    },
    {
      Pair(-134, 4), Pair(-164, -11)
    }
  }},
  {{ // Bucket 4
    {
      Pair(50, -43), Pair(35, -26)
    },
    {
      Pair(-81, -17), Pair(-8, -7)
    },
    {
      Pair(-67, -40), Pair(55, -41)
    },
    {
      Pair(-2, -87), Pair(-12, -46)
    },
    {
      Pair(18, -43), Pair(-306, 42)
    },
    {
      Pair(-201, 32), Pair(-149, -11)
    }
  }},
  {{ // Bucket 5
    {
      Pair(-7, -24), Pair(9, -18)
    },
    {
      Pair(45, -76), Pair(21, -44)
    },
    {
      Pair(98, -91), Pair(65, -42)
    },
    {
      Pair(129, -119), Pair(-52, -46)
    },
    {
      Pair(-119, 88), Pair(-303, -7)
    },
    {
      Pair(-410, 71), Pair(-311, 34)
    }
  }},
  {{ // Bucket 6
    {
      Pair(25, -3), Pair(40, -5)
    },
    {
      Pair(-219, 17), Pair(160, -52)
    },
    {
      Pair(-132, -41), Pair(114, -34)
    },
    {
      Pair(167, -143), Pair(15, -38)
    },
    {
      Pair(287, -181), Pair(184, -69)
    },
    {
      Pair(-387, 64), Pair(-299, -18)
    }
  }}
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {{
  {
      Pair(36, 12), Pair(39, -13), Pair(46, 39), Pair(67, 38), Pair(55, 79), Pair(26, 88), Pair(29, 104), Pair(10, 106),
      Pair(11, 2), Pair(19, 30), Pair(24, 38), Pair(4, 67), Pair(16, 36), Pair(12, 43), Pair(16, 24), Pair(-32, 72),
      Pair(9, 13), Pair(-2, 12), Pair(-1, 33), Pair(11, 30), Pair(4, 42), Pair(-14, 34), Pair(11, -8), Pair(-3, 17)
  },
  {
      Pair(-61, 139), Pair(5, 52), Pair(54, 45), Pair(77, 23), Pair(106, 27), Pair(125, 68), Pair(80, -33), Pair(-44, 92),
      Pair(62, 32), Pair(8, 43), Pair(20, 45), Pair(7, 64), Pair(30, 32), Pair(34, 20), Pair(24, 32), Pair(15, 94),
      Pair(29, 2), Pair(65, -15), Pair(2, 14), Pair(10, 18), Pair(21, -2), Pair(-8, 30), Pair(0, 35), Pair(2, 31)
  },
  {
      Pair(56, 4), Pair(0, 9), Pair(83, 21), Pair(33, 44), Pair(32, 59), Pair(-15, 69), Pair(100, 17), Pair(-60, 120),
      Pair(-52, 52), Pair(24, 12), Pair(29, 23), Pair(53, 27), Pair(26, 30), Pair(3, 29), Pair(14, 16), Pair(-27, 21),
      Pair(20, 17), Pair(5, 0), Pair(18, 13), Pair(12, 28), Pair(28, -1), Pair(6, 21), Pair(-25, 7), Pair(24, -19)
  },
  {
      Pair(-139, 38), Pair(-84, 86), Pair(110, 18), Pair(-14, 59), Pair(42, 45), Pair(27, 85), Pair(93, -1), Pair(319, -105),
      Pair(38, 32), Pair(-9, 25), Pair(78, 1), Pair(113, 18), Pair(98, 12), Pair(94, 5), Pair(46, 11), Pair(192, -26),
      Pair(73, -10), Pair(16, 4), Pair(65, -12), Pair(62, 12), Pair(49, 22), Pair(37, 0), Pair(-14, 47), Pair(25, -6)
  },
  {
      Pair(-260, 80), Pair(-133, 68), Pair(97, 10), Pair(131, 11), Pair(79, 31), Pair(69, 46), Pair(97, 24), Pair(80, -32),
      Pair(-93, 67), Pair(-101, 71), Pair(100, 22), Pair(-25, 31), Pair(14, 20), Pair(-6, 44), Pair(265, -33), Pair(-390, 100),
      Pair(125, -1), Pair(-45, 2), Pair(192, -26), Pair(88, -17), Pair(197, 21), Pair(62, 3), Pair(26, 8), Pair(9, 14)
  },
  {
      Pair(322, 178), Pair(52, 64), Pair(86, 5), Pair(295, -11), Pair(-233, 11), Pair(-17, -3), Pair(-43, -11), Pair(-14, 27),
      Pair(259, -49), Pair(29, 29), Pair(-18, 45), Pair(-122, 29), Pair(0, 54), Pair(63, -23), Pair(97, 34), Pair(133, -23),
      Pair(28, -14), Pair(-5, 29), Pair(214, -1), Pair(-155, 91), Pair(198, 72), Pair(-47, 73), Pair(24, 17), Pair(58, 50)
  },
  {
      Pair(35, 82), Pair(38, 23), Pair(34, 1), Pair(73, -15), Pair(-36, 1), Pair(-11, 73), Pair(5, 152), Pair(64, 67),
      Pair(-90, 9), Pair(-176, -17), Pair(230, 142), Pair(-9, 31), Pair(-10, -9), Pair(220, -9), Pair(199, -27), Pair(34, 87),
      Pair(50, -36), Pair(-14, 12), Pair(224, 91), Pair(45, 97), Pair(124, 122), Pair(-2, 23), Pair(-87, 145), Pair(33, 62)
  }
}};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {{
  {
      Pair(-26, 50), Pair(20, 42), Pair(30, 20), Pair(49, 29), Pair(84, 29), Pair(65, -24), Pair(28, 5), Pair(30, -24),
      Pair(-33, -61), Pair(22, 31), Pair(10, 25), Pair(29, 36), Pair(7, 42), Pair(1, 29), Pair(13, 23), Pair(28, -36),
      Pair(-40, 27), Pair(10, 25), Pair(2, 40), Pair(19, 48), Pair(27, 49), Pair(1, 11), Pair(18, -6), Pair(-48, -29)
  },
  {
      Pair(30, -6), Pair(-6, 29), Pair(47, -4), Pair(46, 3), Pair(52, 31), Pair(64, 55), Pair(42, -35), Pair(-111, -13),
      Pair(55, -42), Pair(26, 39), Pair(14, 21), Pair(19, 20), Pair(1, 54), Pair(22, 4), Pair(16, 32), Pair(-5, -47),
      Pair(40, 29), Pair(0, -7), Pair(5, 28), Pair(21, -7), Pair(18, 34), Pair(10, 15), Pair(26, 2), Pair(-113, 19)
  },
  {
      Pair(-91, 33), Pair(22, 10), Pair(65, -4), Pair(80, 0), Pair(92, -8), Pair(37, 35), Pair(-23, 21), Pair(-49, -20),
      Pair(-8, -23), Pair(29, 9), Pair(3, 9), Pair(31, 23), Pair(67, -7), Pair(40, -11), Pair(21, 12), Pair(50, -41),
      Pair(-64, 53), Pair(10, 10), Pair(-1, 19), Pair(45, 4), Pair(64, 9), Pair(12, -8), Pair(32, -12), Pair(-39, 26)
  },
  {
      Pair(144, -26), Pair(12, -16), Pair(57, -1), Pair(191, -44), Pair(86, -31), Pair(82, -6), Pair(81, -6), Pair(-32, -60),
      Pair(-66, 14), Pair(48, -3), Pair(19, -2), Pair(106, -29), Pair(98, -25), Pair(145, -45), Pair(88, 1), Pair(113, -45),
      Pair(-31, 65), Pair(179, -48), Pair(-5, 35), Pair(62, 11), Pair(147, 0), Pair(-1, 39), Pair(47, -14), Pair(-206, 39)
  },
  {
      Pair(-196, 59), Pair(-38, 2), Pair(138, -17), Pair(253, -28), Pair(40, -2), Pair(51, -21), Pair(202, -54), Pair(-218, 6),
      Pair(65, -11), Pair(-151, 6), Pair(172, -29), Pair(135, -29), Pair(168, -66), Pair(169, -32), Pair(133, -18), Pair(-154, 51),
      Pair(-293, 111), Pair(91, -26), Pair(85, 17), Pair(217, -38), Pair(113, -12), Pair(23, 19), Pair(119, 15), Pair(-179, 71)
  },
  {
      Pair(5, 54), Pair(136, -55), Pair(65, 15), Pair(232, -67), Pair(51, -74), Pair(86, -30), Pair(165, -53), Pair(-67, -49),
      Pair(-171, 64), Pair(205, -20), Pair(403, -63), Pair(276, -34), Pair(16, -7), Pair(42, -37), Pair(48, 1), Pair(-178, 63),
      Pair(-132, 53), Pair(-23, 3), Pair(255, -14), Pair(258, -25), Pair(189, 9), Pair(-25, 20), Pair(171, 10), Pair(-58, 5)
  },
  {
      Pair(21, 103), Pair(132, 72), Pair(226, -129), Pair(138, -51), Pair(58, -5), Pair(268, -63), Pair(227, -69), Pair(17, 43),
      Pair(-54, 57), Pair(123, 38), Pair(373, -38), Pair(-210, -20), Pair(105, -29), Pair(-239, 72), Pair(-52, 77), Pair(22, -217),
      Pair(41, 101), Pair(-157, 89), Pair(-6, 19), Pair(108, 7), Pair(-54, 76), Pair(-301, 30), Pair(252, 112), Pair(57, 184)
  }
}};

constexpr KingBuckets<ScorePair> kBishopPairBonus = {{
  {
      Pair(29, 85)
  },
  {
      Pair(25, 82)
  },
  {
      Pair(38, 77)
  },
  {
      Pair(34, 75)
  },
  {
      Pair(55, 63)
  },
  {
      Pair(31, 86)
  },
  {
      Pair(91, 94)
  }
}};


constexpr ScorePair kTempoBonus = Pair(43, 40);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H