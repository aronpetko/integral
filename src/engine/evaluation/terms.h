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
      Pair(97, 152), Pair(416, 391), Pair(441, 443), Pair(559, 795), Pair(1112, 1450), Pair(0, 0)
  },
  {
      Pair(69, 95), Pair(203, 243), Pair(206, 267), Pair(239, 447), Pair(521, 962), Pair(0, 0)
  },
  {
      Pair(50, 77), Pair(194, 219), Pair(204, 237), Pair(229, 361), Pair(516, 765), Pair(0, 0)
  },
  {
      Pair(67, 76), Pair(224, 238), Pair(242, 246), Pair(265, 383), Pair(631, 977), Pair(0, 0)
  },
  {
      Pair(58, 104), Pair(213, 211), Pair(247, 220), Pair(251, 342), Pair(702, 1022), Pair(0, 0)
  },
  {
      Pair(55, 100), Pair(226, 187), Pair(257, 192), Pair(196, 315), Pair(488, 923), Pair(0, 0)
  },
  {
      Pair(135, 107), Pair(316, 268), Pair(427, 286), Pair(351, 460), Pair(810, 1074), Pair(0, 0)
  }
}};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {{ // Bucket 0
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(-6, 68), Pair(-39, 76), Pair(-15, 27), Pair(19, -10), Pair(40, -32), Pair(60, -54), Pair(-47, -16), Pair(-91, 41),
      Pair(-10, 69), Pair(-2, 52), Pair(28, 18), Pair(40, -33), Pair(62, -32), Pair(118, -45), Pair(45, 13), Pair(13, 47),
      Pair(-13, 22), Pair(2, 2), Pair(-4, -6), Pair(10, -36), Pair(32, -38), Pair(45, -54), Pair(16, -11), Pair(-1, -3),
      Pair(-18, -1), Pair(-8, -3), Pair(-1, -24), Pair(7, -27), Pair(13, -35), Pair(36, -55), Pair(22, -28), Pair(6, -25),
      Pair(-29, -8), Pair(-17, -17), Pair(-16, -17), Pair(-10, -17), Pair(2, -14), Pair(-1, -28), Pair(0, -28), Pair(-3, -33),
      Pair(-20, 3), Pair(-8, -4), Pair(-17, 4), Pair(-8, -7), Pair(-3, 15), Pair(16, -3), Pair(18, -10), Pair(-12, -34),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-215, 3), Pair(-167, 68), Pair(-120, 67), Pair(-10, 19), Pair(-19, 30), Pair(-43, -19), Pair(-144, 23), Pair(-97, -84),
      Pair(-32, 27), Pair(-32, 55), Pair(5, 47), Pair(11, 63), Pair(23, 38), Pair(70, 10), Pair(9, 15), Pair(-4, -17),
      Pair(-35, 46), Pair(-3, 51), Pair(21, 73), Pair(34, 62), Pair(57, 38), Pair(93, 27), Pair(21, 46), Pair(25, 6),
      Pair(8, 46), Pair(22, 61), Pair(39, 80), Pair(58, 77), Pair(48, 88), Pair(66, 70), Pair(29, 84), Pair(39, 42),
      Pair(-9, 41), Pair(15, 56), Pair(35, 78), Pair(40, 78), Pair(43, 82), Pair(53, 58), Pair(49, 62), Pair(11, 52),
      Pair(-24, 18), Pair(2, 41), Pair(13, 54), Pair(27, 72), Pair(38, 71), Pair(24, 53), Pair(22, 40), Pair(2, 11),
      Pair(-46, 41), Pair(-22, 40), Pair(-9, 28), Pair(9, 52), Pair(7, 55), Pair(9, 20), Pair(-3, 38), Pair(-2, 43),
      Pair(-79, -12), Pair(-22, 10), Pair(-29, 32), Pair(-5, 41), Pair(-1, 41), Pair(9, 30), Pair(-16, 23), Pair(-60, 0)
    },
    {
      Pair(-35, 68), Pair(-61, 56), Pair(-87, 53), Pair(-105, 61), Pair(-146, 75), Pair(-91, 38), Pair(-64, 63), Pair(-28, 49),
      Pair(-51, 61), Pair(-28, 65), Pair(-9, 37), Pair(-43, 65), Pair(-31, 39), Pair(-4, 39), Pair(-65, 63), Pair(-27, 20),
      Pair(-11, 56), Pair(-3, 62), Pair(7, 59), Pair(2, 35), Pair(-1, 46), Pair(22, 72), Pair(28, 51), Pair(4, 57),
      Pair(-23, 55), Pair(3, 57), Pair(-6, 58), Pair(19, 64), Pair(13, 49), Pair(20, 48), Pair(1, 52), Pair(-9, 57),
      Pair(-9, 43), Pair(-3, 39), Pair(3, 53), Pair(8, 49), Pair(18, 43), Pair(5, 40), Pair(3, 38), Pair(3, 27),
      Pair(-6, 30), Pair(15, 53), Pair(9, 50), Pair(8, 60), Pair(9, 65), Pair(15, 49), Pair(19, 34), Pair(14, 44),
      Pair(12, 25), Pair(13, 20), Pair(18, 26), Pair(1, 41), Pair(8, 48), Pair(22, 37), Pair(40, 42), Pair(23, 4),
      Pair(15, 14), Pair(28, 22), Pair(-2, 37), Pair(-3, 32), Pair(4, 40), Pair(13, 53), Pair(23, 32), Pair(28, 5)
    },
    {
      Pair(75, 104), Pair(68, 112), Pair(35, 123), Pair(44, 116), Pair(75, 104), Pair(89, 108), Pair(80, 121), Pair(40, 133),
      Pair(44, 110), Pair(37, 122), Pair(56, 116), Pair(67, 120), Pair(51, 114), Pair(80, 98), Pair(101, 94), Pair(65, 102),
      Pair(41, 99), Pair(90, 96), Pair(72, 105), Pair(84, 93), Pair(97, 82), Pair(118, 83), Pair(168, 55), Pair(72, 85),
      Pair(47, 98), Pair(69, 98), Pair(77, 99), Pair(88, 91), Pair(86, 88), Pair(77, 100), Pair(96, 75), Pair(55, 84),
      Pair(24, 88), Pair(25, 115), Pair(35, 98), Pair(44, 96), Pair(39, 88), Pair(26, 102), Pair(70, 76), Pair(26, 83),
      Pair(14, 81), Pair(28, 85), Pair(25, 88), Pair(34, 84), Pair(38, 77), Pair(33, 84), Pair(78, 55), Pair(41, 40),
      Pair(4, 74), Pair(24, 78), Pair(36, 72), Pair(37, 79), Pair(40, 67), Pair(41, 69), Pair(66, 43), Pair(-1, 53),
      Pair(29, 84), Pair(35, 77), Pair(41, 77), Pair(48, 72), Pair(49, 69), Pair(48, 82), Pair(53, 66), Pair(-2, 66)
    },
    {
      Pair(77, 117), Pair(71, 139), Pair(88, 144), Pair(109, 134), Pair(107, 146), Pair(102, 173), Pair(163, 108), Pair(137, 126),
      Pair(77, 129), Pair(44, 170), Pair(85, 157), Pair(54, 190), Pair(43, 206), Pair(102, 189), Pair(81, 191), Pair(166, 113),
      Pair(80, 122), Pair(84, 146), Pair(82, 165), Pair(88, 170), Pair(99, 190), Pair(128, 184), Pair(134, 177), Pair(92, 183),
      Pair(85, 128), Pair(98, 150), Pair(92, 148), Pair(89, 175), Pair(90, 197), Pair(115, 166), Pair(124, 167), Pair(124, 141),
      Pair(88, 125), Pair(95, 149), Pair(94, 148), Pair(88, 189), Pair(99, 167), Pair(96, 159), Pair(122, 125), Pair(114, 126),
      Pair(93, 102), Pair(102, 125), Pair(96, 151), Pair(94, 143), Pair(96, 144), Pair(106, 133), Pair(128, 97), Pair(116, 74),
      Pair(95, 84), Pair(102, 95), Pair(108, 86), Pair(105, 121), Pair(112, 104), Pair(122, 53), Pair(129, 33), Pair(118, 37),
      Pair(100, 86), Pair(92, 87), Pair(99, 78), Pair(109, 85), Pair(109, 73), Pair(95, 59), Pair(101, 15), Pair(91, 41)
    },
    {
      Pair(940, -52), Pair(957, 38), Pair(963, 37), Pair(858, 47), Pair(915, 19), Pair(894, 36), Pair(923, 49), Pair(931, -68),
      Pair(898, -4), Pair(1057, 55), Pair(992, 64), Pair(972, 38), Pair(963, 32), Pair(1015, 40), Pair(1020, 58), Pair(922, -10),
      Pair(1404, -8), Pair(1614, 7), Pair(1521, 23), Pair(1478, 25), Pair(1446, 31), Pair(1581, 13), Pair(1523, 25), Pair(1466, -17),
      Pair(1442, -26), Pair(1548, -7), Pair(1506, 11), Pair(1418, 25), Pair(1370, 30), Pair(1481, 13), Pair(1469, 2), Pair(1384, -16),
      Pair(893, -45), Pair(939, -22), Pair(947, -3), Pair(822, 30), Pair(840, 21), Pair(898, 3), Pair(901, -12), Pair(810, -31),
      Pair(379, -23), Pair(405, -1), Pair(384, 22), Pair(349, 45), Pair(356, 41), Pair(362, 25), Pair(386, 3), Pair(364, -25),
      Pair(131, -23), Pair(87, 25), Pair(73, 38), Pair(41, 56), Pair(36, 56), Pair(44, 50), Pair(82, 23), Pair(111, -21),
      Pair(-313, -40), Pair(-282, 19), Pair(45, 20), Pair(-30, 34), Pair(26, 17), Pair(-12, 38), Pair(-307, 27), Pair(-303, -41)
    }
  }},
  {{ // Bucket 1
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(10, 106), Pair(-62, 120), Pair(-32, 79), Pair(45, 35), Pair(21, 36), Pair(-3, 41), Pair(-44, 61), Pair(-102, 81),
      Pair(66, 100), Pair(26, 94), Pair(65, 69), Pair(64, 22), Pair(77, 24), Pair(93, 34), Pair(53, 86), Pair(14, 85),
      Pair(57, 67), Pair(31, 52), Pair(30, 45), Pair(46, 9), Pair(52, 19), Pair(50, 15), Pair(40, 44), Pair(2, 63),
      Pair(51, 47), Pair(21, 51), Pair(37, 28), Pair(56, 12), Pair(45, 25), Pair(43, 15), Pair(35, 33), Pair(-6, 49),
      Pair(53, 33), Pair(21, 42), Pair(28, 40), Pair(24, 31), Pair(29, 40), Pair(17, 28), Pair(39, 27), Pair(-2, 39),
      Pair(55, 48), Pair(37, 48), Pair(24, 63), Pair(13, 66), Pair(0, 73), Pair(28, 42), Pair(42, 40), Pair(11, 47),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-136, -9), Pair(-205, 145), Pair(-25, 81), Pair(15, 88), Pair(85, 48), Pair(-45, 62), Pair(-28, 67), Pair(-69, -33),
      Pair(-28, 87), Pair(29, 98), Pair(85, 69), Pair(73, 99), Pair(81, 80), Pair(82, 71), Pair(17, 79), Pair(79, 41),
      Pair(16, 103), Pair(71, 98), Pair(56, 125), Pair(106, 98), Pair(126, 82), Pair(94, 92), Pair(68, 86), Pair(67, 73),
      Pair(74, 121), Pair(99, 108), Pair(108, 110), Pair(124, 113), Pair(104, 123), Pair(118, 120), Pair(101, 108), Pair(100, 90),
      Pair(67, 103), Pair(71, 109), Pair(103, 120), Pair(106, 127), Pair(111, 125), Pair(122, 111), Pair(119, 99), Pair(70, 96),
      Pair(45, 83), Pair(75, 102), Pair(96, 97), Pair(103, 121), Pair(110, 116), Pair(94, 95), Pair(95, 90), Pair(61, 87),
      Pair(38, 98), Pair(68, 94), Pair(75, 102), Pair(82, 103), Pair(88, 98), Pair(84, 96), Pair(62, 94), Pair(46, 77),
      Pair(-21, 71), Pair(51, 88), Pair(43, 98), Pair(60, 107), Pair(66, 108), Pair(56, 88), Pair(46, 84), Pair(17, 50)
    },
    {
      Pair(37, 119), Pair(-3, 140), Pair(-25, 130), Pair(-115, 173), Pair(-171, 187), Pair(-61, 125), Pair(30, 139), Pair(13, 124),
      Pair(-9, 122), Pair(59, 126), Pair(37, 132), Pair(28, 126), Pair(23, 139), Pair(72, 113), Pair(20, 143), Pair(56, 111),
      Pair(68, 121), Pair(66, 141), Pair(89, 135), Pair(91, 122), Pair(102, 104), Pair(74, 133), Pair(101, 118), Pair(102, 118),
      Pair(71, 126), Pair(88, 125), Pair(83, 137), Pair(85, 137), Pair(96, 129), Pair(92, 140), Pair(89, 124), Pair(81, 132),
      Pair(74, 101), Pair(75, 131), Pair(100, 107), Pair(108, 124), Pair(113, 119), Pair(89, 119), Pair(85, 119), Pair(83, 96),
      Pair(78, 115), Pair(117, 115), Pair(100, 136), Pair(103, 131), Pair(104, 136), Pair(108, 123), Pair(101, 111), Pair(89, 98),
      Pair(111, 94), Pair(118, 100), Pair(122, 102), Pair(97, 129), Pair(105, 119), Pair(108, 109), Pair(120, 99), Pair(103, 80),
      Pair(109, 95), Pair(102, 118), Pair(85, 121), Pair(91, 112), Pair(92, 109), Pair(79, 118), Pair(77, 117), Pair(91, 96)
    },
    {
      Pair(168, 250), Pair(130, 260), Pair(116, 269), Pair(157, 268), Pair(81, 270), Pair(114, 282), Pair(120, 271), Pair(129, 265),
      Pair(128, 240), Pair(110, 261), Pair(136, 247), Pair(159, 267), Pair(170, 239), Pair(150, 234), Pair(119, 245), Pair(135, 235),
      Pair(127, 236), Pair(179, 227), Pair(114, 248), Pair(159, 242), Pair(191, 207), Pair(147, 226), Pair(193, 213), Pair(145, 226),
      Pair(130, 224), Pair(168, 214), Pair(151, 242), Pair(142, 256), Pair(156, 224), Pair(159, 224), Pair(167, 212), Pair(158, 215),
      Pair(116, 227), Pair(109, 236), Pair(112, 239), Pair(121, 252), Pair(133, 228), Pair(110, 232), Pair(111, 225), Pair(127, 212),
      Pair(113, 217), Pair(127, 216), Pair(108, 231), Pair(111, 245), Pair(122, 216), Pair(120, 219), Pair(137, 200), Pair(135, 189),
      Pair(105, 209), Pair(117, 221), Pair(116, 226), Pair(113, 225), Pair(134, 200), Pair(121, 217), Pair(127, 181), Pair(102, 190),
      Pair(131, 204), Pair(122, 204), Pair(126, 216), Pair(135, 217), Pair(139, 202), Pair(109, 211), Pair(123, 193), Pair(142, 172)
    },
    {
      Pair(222, 368), Pair(270, 366), Pair(296, 367), Pair(310, 358), Pair(266, 404), Pair(254, 404), Pair(291, 362), Pair(229, 405),
      Pair(248, 360), Pair(240, 382), Pair(256, 393), Pair(193, 450), Pair(195, 454), Pair(263, 410), Pair(259, 380), Pair(310, 397),
      Pair(275, 357), Pair(279, 340), Pair(292, 374), Pair(306, 361), Pair(282, 403), Pair(281, 404), Pair(337, 359), Pair(321, 382),
      Pair(277, 342), Pair(294, 373), Pair(290, 376), Pair(282, 399), Pair(289, 405), Pair(307, 395), Pair(315, 381), Pair(311, 384),
      Pair(295, 331), Pair(282, 390), Pair(299, 366), Pair(289, 443), Pair(294, 420), Pair(301, 368), Pair(311, 365), Pair(296, 361),
      Pair(279, 344), Pair(315, 327), Pair(303, 389), Pair(296, 393), Pair(299, 389), Pair(305, 382), Pair(311, 366), Pair(296, 383),
      Pair(275, 308), Pair(315, 280), Pair(326, 280), Pair(319, 331), Pair(316, 335), Pair(309, 324), Pair(334, 265), Pair(338, 242),
      Pair(325, 235), Pair(305, 265), Pair(319, 258), Pair(319, 275), Pair(288, 328), Pair(288, 273), Pair(305, 254), Pair(331, 255)
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
      Pair(103, 145), Pair(98, 133), Pair(92, 123), Pair(136, 70), Pair(114, 67), Pair(146, 69), Pair(51, 121), Pair(-19, 149),
      Pair(34, 128), Pair(69, 107), Pair(80, 83), Pair(102, 37), Pair(131, 31), Pair(153, 48), Pair(104, 87), Pair(37, 117),
      Pair(35, 98), Pair(52, 81), Pair(48, 64), Pair(70, 39), Pair(97, 38), Pair(94, 40), Pair(66, 70), Pair(29, 83),
      Pair(30, 79), Pair(45, 75), Pair(51, 55), Pair(63, 49), Pair(72, 44), Pair(82, 46), Pair(64, 62), Pair(22, 65),
      Pair(13, 72), Pair(30, 68), Pair(31, 63), Pair(38, 60), Pair(45, 63), Pair(55, 56), Pair(57, 55), Pair(5, 60),
      Pair(25, 78), Pair(42, 74), Pair(31, 75), Pair(31, 77), Pair(41, 78), Pair(78, 64), Pair(80, 62), Pair(6, 66),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-177, 82), Pair(-121, 125), Pair(-85, 134), Pair(68, 93), Pair(127, 85), Pair(-27, 119), Pair(-140, 137), Pair(-109, 23),
      Pair(32, 105), Pair(41, 120), Pair(78, 116), Pair(139, 123), Pair(129, 111), Pair(164, 85), Pair(95, 100), Pair(80, 90),
      Pair(31, 115), Pair(92, 120), Pair(109, 146), Pair(132, 130), Pair(139, 125), Pair(182, 110), Pair(128, 87), Pair(125, 84),
      Pair(77, 123), Pair(109, 133), Pair(136, 143), Pair(152, 140), Pair(150, 146), Pair(187, 129), Pair(139, 125), Pair(147, 103),
      Pair(72, 122), Pair(100, 133), Pair(118, 157), Pair(140, 146), Pair(136, 154), Pair(153, 133), Pair(167, 120), Pair(111, 121),
      Pair(53, 105), Pair(78, 124), Pair(102, 134), Pair(116, 151), Pair(131, 144), Pair(112, 123), Pair(111, 112), Pair(85, 110),
      Pair(35, 115), Pair(55, 121), Pair(69, 125), Pair(94, 124), Pair(95, 120), Pair(89, 112), Pair(81, 114), Pair(86, 109),
      Pair(-35, 117), Pair(40, 111), Pair(44, 121), Pair(64, 131), Pair(71, 124), Pair(88, 110), Pair(67, 112), Pair(-2, 128)
    },
    {
      Pair(44, 153), Pair(16, 158), Pair(-24, 163), Pair(-34, 171), Pair(5, 154), Pair(-22, 159), Pair(63, 145), Pair(-17, 175),
      Pair(38, 144), Pair(81, 150), Pair(86, 144), Pair(78, 149), Pair(49, 151), Pair(73, 151), Pair(67, 147), Pair(69, 138),
      Pair(73, 150), Pair(89, 152), Pair(105, 150), Pair(78, 150), Pair(136, 130), Pair(133, 153), Pair(125, 145), Pair(114, 145),
      Pair(74, 146), Pair(101, 149), Pair(109, 145), Pair(135, 144), Pair(112, 152), Pair(132, 139), Pair(102, 149), Pair(99, 139),
      Pair(85, 129), Pair(78, 148), Pair(118, 143), Pair(111, 150), Pair(123, 142), Pair(105, 151), Pair(106, 139), Pair(110, 131),
      Pair(85, 132), Pair(119, 137), Pair(104, 146), Pair(119, 147), Pair(114, 155), Pair(125, 140), Pair(121, 139), Pair(112, 123),
      Pair(90, 136), Pair(105, 118), Pair(122, 121), Pair(101, 133), Pair(111, 132), Pair(116, 118), Pair(143, 109), Pair(105, 104),
      Pair(87, 123), Pair(109, 140), Pair(98, 133), Pair(84, 144), Pair(81, 142), Pair(85, 143), Pair(95, 141), Pair(74, 119)
    },
    {
      Pair(164, 303), Pair(168, 313), Pair(140, 323), Pair(156, 310), Pair(164, 303), Pair(214, 300), Pair(192, 312), Pair(169, 312),
      Pair(157, 292), Pair(145, 310), Pair(176, 303), Pair(221, 287), Pair(202, 289), Pair(243, 276), Pair(183, 292), Pair(185, 283),
      Pair(150, 293), Pair(179, 290), Pair(184, 292), Pair(195, 281), Pair(222, 263), Pair(246, 268), Pair(263, 256), Pair(179, 276),
      Pair(135, 296), Pair(176, 292), Pair(180, 294), Pair(204, 280), Pair(209, 268), Pair(218, 268), Pair(206, 274), Pair(167, 279),
      Pair(121, 285), Pair(123, 299), Pair(136, 297), Pair(151, 292), Pair(147, 285), Pair(144, 292), Pair(163, 277), Pair(134, 277),
      Pair(118, 270), Pair(116, 287), Pair(126, 279), Pair(144, 274), Pair(137, 278), Pair(142, 271), Pair(171, 253), Pair(111, 268),
      Pair(108, 265), Pair(121, 268), Pair(135, 272), Pair(142, 268), Pair(151, 253), Pair(150, 256), Pair(146, 259), Pair(128, 243),
      Pair(124, 268), Pair(124, 271), Pair(131, 276), Pair(145, 261), Pair(149, 252), Pair(151, 253), Pair(143, 256), Pair(121, 262)
    },
    {
      Pair(250, 498), Pair(293, 471), Pair(289, 501), Pair(349, 463), Pair(322, 494), Pair(364, 479), Pair(397, 448), Pair(333, 494),
      Pair(274, 471), Pair(247, 508), Pair(279, 500), Pair(274, 519), Pair(256, 571), Pair(346, 500), Pair(294, 515), Pair(361, 481),
      Pair(292, 455), Pair(309, 453), Pair(311, 493), Pair(318, 487), Pair(334, 508), Pair(375, 489), Pair(356, 500), Pair(328, 488),
      Pair(309, 433), Pair(314, 485), Pair(309, 480), Pair(305, 516), Pair(326, 511), Pair(342, 508), Pair(346, 502), Pair(351, 464),
      Pair(300, 448), Pair(305, 485), Pair(315, 486), Pair(315, 507), Pair(310, 509), Pair(333, 479), Pair(347, 467), Pair(322, 476),
      Pair(295, 427), Pair(312, 454), Pair(311, 475), Pair(313, 481), Pair(324, 472), Pair(333, 462), Pair(344, 435), Pair(320, 451),
      Pair(305, 436), Pair(299, 433), Pair(320, 418), Pair(323, 436), Pair(325, 441), Pair(331, 400), Pair(344, 370), Pair(349, 357),
      Pair(301, 413), Pair(278, 437), Pair(297, 424), Pair(318, 421), Pair(315, 419), Pair(293, 425), Pair(318, 392), Pair(306, 402)
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
      Pair(119, 106), Pair(206, 75), Pair(107, 89), Pair(153, 51), Pair(166, 50), Pair(102, 57), Pair(13, 135), Pair(-14, 121),
      Pair(57, 104), Pair(100, 101), Pair(149, 56), Pair(130, 35), Pair(132, 32), Pair(198, 43), Pair(117, 83), Pair(82, 85),
      Pair(33, 89), Pair(30, 94), Pair(45, 62), Pair(57, 51), Pair(79, 48), Pair(74, 52), Pair(61, 72), Pair(13, 77),
      Pair(6, 78), Pair(9, 94), Pair(31, 61), Pair(39, 61), Pair(42, 61), Pair(59, 59), Pair(37, 72), Pair(-16, 71),
      Pair(-17, 73), Pair(-5, 87), Pair(18, 66), Pair(31, 69), Pair(24, 75), Pair(42, 63), Pair(38, 70), Pair(-32, 70),
      Pair(-16, 87), Pair(14, 89), Pair(29, 71), Pair(6, 72), Pair(30, 83), Pair(46, 73), Pair(36, 78), Pair(-29, 81),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-229, 15), Pair(-196, 81), Pair(-119, 96), Pair(39, 64), Pair(-85, 94), Pair(-8, 73), Pair(52, 43), Pair(-183, 30),
      Pair(-4, 55), Pair(19, 84), Pair(14, 81), Pair(100, 80), Pair(84, 77), Pair(68, 63), Pair(10, 86), Pair(0, 63),
      Pair(32, 50), Pair(59, 67), Pair(86, 92), Pair(119, 85), Pair(135, 70), Pair(113, 69), Pair(103, 56), Pair(40, 55),
      Pair(43, 85), Pair(85, 86), Pair(123, 97), Pair(104, 103), Pair(144, 91), Pair(146, 92), Pair(165, 60), Pair(79, 70),
      Pair(15, 93), Pair(116, 85), Pair(62, 116), Pair(110, 112), Pair(115, 109), Pair(135, 91), Pair(142, 69), Pair(90, 70),
      Pair(-5, 57), Pair(19, 92), Pair(70, 88), Pair(103, 101), Pair(105, 100), Pair(104, 77), Pair(63, 81), Pair(19, 83),
      Pair(-72, 87), Pair(14, 100), Pair(18, 89), Pair(49, 96), Pair(46, 92), Pair(90, 74), Pair(25, 97), Pair(57, 79),
      Pair(-94, 89), Pair(-57, 81), Pair(-63, 102), Pair(-34, 92), Pair(-1, 90), Pair(-11, 81), Pair(-32, 75), Pair(-16, 114)
    },
    {
      Pair(-5, 112), Pair(-29, 131), Pair(-4, 111), Pair(5, 113), Pair(6, 112), Pair(-110, 124), Pair(51, 95), Pair(-70, 114),
      Pair(-38, 108), Pair(61, 107), Pair(14, 115), Pair(42, 103), Pair(-3, 112), Pair(59, 103), Pair(3, 118), Pair(-12, 108),
      Pair(62, 108), Pair(55, 110), Pair(76, 106), Pair(53, 113), Pair(95, 111), Pair(110, 109), Pair(88, 102), Pair(128, 90),
      Pair(36, 113), Pair(70, 104), Pair(76, 110), Pair(97, 109), Pair(116, 115), Pair(85, 113), Pair(80, 117), Pair(94, 93),
      Pair(0, 111), Pair(42, 110), Pair(78, 103), Pair(94, 108), Pair(87, 104), Pair(95, 108), Pair(68, 104), Pair(89, 84),
      Pair(36, 106), Pair(57, 105), Pair(62, 105), Pair(91, 98), Pair(92, 103), Pair(88, 97), Pair(84, 99), Pair(44, 106),
      Pair(29, 122), Pair(48, 100), Pair(55, 109), Pair(64, 106), Pair(78, 99), Pair(59, 96), Pair(81, 83), Pair(53, 88),
      Pair(10, 110), Pair(26, 133), Pair(32, 114), Pair(39, 103), Pair(45, 105), Pair(47, 105), Pair(-33, 119), Pair(8, 99)
    },
    {
      Pair(85, 250), Pair(40, 271), Pair(82, 265), Pair(84, 257), Pair(95, 240), Pair(175, 229), Pair(176, 225), Pair(115, 240),
      Pair(139, 215), Pair(115, 239), Pair(107, 247), Pair(220, 206), Pair(158, 216), Pair(185, 210), Pair(174, 216), Pair(128, 218),
      Pair(87, 231), Pair(124, 230), Pair(140, 227), Pair(154, 214), Pair(152, 208), Pair(204, 204), Pair(149, 213), Pair(93, 221),
      Pair(36, 242), Pair(108, 236), Pair(89, 248), Pair(160, 221), Pair(142, 212), Pair(144, 210), Pair(136, 216), Pair(98, 216),
      Pair(22, 233), Pair(17, 255), Pair(57, 246), Pair(65, 240), Pair(68, 233), Pair(82, 223), Pair(63, 236), Pair(57, 218),
      Pair(28, 211), Pair(11, 240), Pair(33, 229), Pair(60, 218), Pair(56, 215), Pair(59, 221), Pair(113, 196), Pair(-9, 217),
      Pair(3, 215), Pair(35, 219), Pair(33, 225), Pair(53, 214), Pair(32, 219), Pair(87, 193), Pair(60, 201), Pair(-6, 222),
      Pair(50, 211), Pair(42, 225), Pair(41, 230), Pair(69, 219), Pair(59, 211), Pair(80, 205), Pair(64, 212), Pair(54, 204)
    },
    {
      Pair(117, 301), Pair(95, 313), Pair(114, 323), Pair(126, 317), Pair(5, 396), Pair(136, 358), Pair(199, 260), Pair(126, 307),
      Pair(86, 306), Pair(81, 311), Pair(81, 348), Pair(134, 340), Pair(160, 335), Pair(229, 304), Pair(161, 282), Pair(236, 241),
      Pair(127, 301), Pair(117, 296), Pair(191, 261), Pair(120, 333), Pair(205, 307), Pair(255, 272), Pair(272, 231), Pair(228, 232),
      Pair(102, 294), Pair(110, 314), Pair(139, 299), Pair(127, 343), Pair(188, 310), Pair(218, 303), Pair(240, 261), Pair(182, 272),
      Pair(118, 266), Pair(100, 326), Pair(163, 316), Pair(158, 327), Pair(174, 325), Pair(191, 301), Pair(203, 262), Pair(122, 326),
      Pair(77, 263), Pair(145, 279), Pair(152, 289), Pair(162, 284), Pair(149, 312), Pair(191, 266), Pair(225, 186), Pair(159, 244),
      Pair(129, 219), Pair(153, 249), Pair(168, 238), Pair(171, 255), Pair(176, 269), Pair(166, 239), Pair(212, 183), Pair(148, 216),
      Pair(87, 254), Pair(98, 262), Pair(125, 288), Pair(164, 244), Pair(138, 253), Pair(143, 256), Pair(137, 311), Pair(145, 238)
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
      Pair(161, 83), Pair(199, 69), Pair(262, 66), Pair(168, 64), Pair(56, 92), Pair(56, 86), Pair(22, 134), Pair(127, 95),
      Pair(77, 69), Pair(108, 89), Pair(173, 32), Pair(143, 27), Pair(105, 32), Pair(157, 35), Pair(124, 55), Pair(29, 69),
      Pair(5, 66), Pair(67, 72), Pair(59, 43), Pair(63, 43), Pair(56, 46), Pair(82, 44), Pair(43, 65), Pair(38, 47),
      Pair(-9, 58), Pair(-21, 89), Pair(20, 49), Pair(22, 59), Pair(-13, 60), Pair(40, 51), Pair(-13, 75), Pair(-26, 49),
      Pair(-28, 52), Pair(6, 75), Pair(12, 44), Pair(51, 45), Pair(26, 49), Pair(12, 50), Pair(-2, 68), Pair(-29, 48),
      Pair(-52, 68), Pair(5, 79), Pair(46, 41), Pair(11, 51), Pair(10, 57), Pair(27, 57), Pair(19, 69), Pair(-52, 60),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-206, -63), Pair(-38, 6), Pair(-38, 57), Pair(-70, 66), Pair(120, 40), Pair(-8, 42), Pair(-126, 44), Pair(-494, 45),
      Pair(-91, 53), Pair(-20, 70), Pair(73, 54), Pair(135, 59), Pair(127, 30), Pair(56, 47), Pair(44, 50), Pair(34, 30),
      Pair(62, 34), Pair(129, 46), Pair(141, 75), Pair(145, 61), Pair(122, 67), Pair(170, 49), Pair(167, 36), Pair(106, 42),
      Pair(63, 54), Pair(129, 58), Pair(90, 82), Pair(199, 66), Pair(168, 76), Pair(231, 55), Pair(196, 43), Pair(137, 33),
      Pair(3, 69), Pair(47, 78), Pair(86, 89), Pair(111, 90), Pair(97, 89), Pair(117, 86), Pair(89, 70), Pair(89, 68),
      Pair(-36, 64), Pair(-28, 96), Pair(55, 85), Pair(80, 94), Pair(83, 100), Pair(107, 74), Pair(23, 82), Pair(-47, 91),
      Pair(-131, 93), Pair(-3, 87), Pair(-43, 82), Pair(31, 82), Pair(50, 84), Pair(31, 79), Pair(73, 59), Pair(14, 53),
      Pair(-77, 75), Pair(-72, 67), Pair(-109, 85), Pair(42, 80), Pair(-45, 71), Pair(-125, 70), Pair(-17, 81), Pair(-58, 101)
    },
    {
      Pair(-48, 93), Pair(-37, 103), Pair(44, 75), Pair(3, 94), Pair(66, 71), Pair(-11, 84), Pair(35, 90), Pair(121, 78),
      Pair(20, 87), Pair(63, 76), Pair(71, 81), Pair(30, 73), Pair(3, 84), Pair(124, 63), Pair(-49, 101), Pair(10, 96),
      Pair(3, 101), Pair(9, 100), Pair(114, 82), Pair(146, 79), Pair(201, 62), Pair(203, 77), Pair(139, 77), Pair(62, 98),
      Pair(26, 104), Pair(99, 78), Pair(96, 89), Pair(166, 70), Pair(152, 85), Pair(128, 79), Pair(99, 78), Pair(67, 88),
      Pair(30, 92), Pair(77, 86), Pair(94, 79), Pair(79, 91), Pair(107, 80), Pair(72, 91), Pair(103, 73), Pair(136, 69),
      Pair(-49, 119), Pair(68, 90), Pair(71, 89), Pair(111, 84), Pair(86, 94), Pair(82, 85), Pair(80, 97), Pair(-49, 114),
      Pair(-56, 128), Pair(-19, 106), Pair(72, 81), Pair(65, 87), Pair(7, 91), Pair(-20, 87), Pair(61, 70), Pair(-67, 97),
      Pair(-18, 91), Pair(-59, 107), Pair(-23, 109), Pair(-14, 105), Pair(2, 95), Pair(-25, 96), Pair(-27, 78), Pair(82, 105)
    },
    {
      Pair(77, 218), Pair(58, 240), Pair(27, 244), Pair(108, 219), Pair(73, 225), Pair(215, 183), Pair(116, 213), Pair(211, 186),
      Pair(136, 191), Pair(127, 202), Pair(139, 200), Pair(182, 188), Pair(178, 183), Pair(134, 195), Pair(149, 189), Pair(206, 168),
      Pair(133, 187), Pair(121, 204), Pair(95, 210), Pair(202, 177), Pair(222, 163), Pair(210, 175), Pair(111, 199), Pair(178, 169),
      Pair(107, 190), Pair(69, 216), Pair(91, 203), Pair(145, 198), Pair(126, 189), Pair(196, 165), Pair(96, 195), Pair(125, 186),
      Pair(10, 200), Pair(-24, 224), Pair(6, 218), Pair(6, 218), Pair(73, 193), Pair(19, 209), Pair(69, 198), Pair(72, 171),
      Pair(20, 183), Pair(-2, 207), Pair(-76, 231), Pair(3, 210), Pair(45, 187), Pair(9, 194), Pair(20, 198), Pair(38, 174),
      Pair(-60, 208), Pair(-76, 230), Pair(-17, 209), Pair(-28, 215), Pair(56, 190), Pair(25, 199), Pair(24, 187), Pair(32, 191),
      Pair(-24, 213), Pair(-18, 216), Pair(-33, 225), Pair(21, 206), Pair(69, 180), Pair(34, 197), Pair(-35, 223), Pair(10, 193)
    },
    {
      Pair(102, 152), Pair(-18, 187), Pair(62, 179), Pair(147, 162), Pair(164, 147), Pair(95, 196), Pair(184, 109), Pair(-40, 247),
      Pair(67, 143), Pair(131, 120), Pair(3, 209), Pair(-26, 288), Pair(6, 267), Pair(12, 242), Pair(-36, 229), Pair(231, 66),
      Pair(-46, 185), Pair(-57, 214), Pair(164, 135), Pair(-67, 287), Pair(344, 61), Pair(157, 180), Pair(107, 151), Pair(236, 80),
      Pair(-88, 250), Pair(-63, 237), Pair(-86, 265), Pair(200, 154), Pair(183, 150), Pair(82, 205), Pair(37, 198), Pair(245, 83),
      Pair(-153, 239), Pair(-16, 194), Pair(-213, 312), Pair(9, 219), Pair(93, 179), Pair(99, 191), Pair(237, 71), Pair(206, 9),
      Pair(-229, 246), Pair(-68, 224), Pair(29, 210), Pair(77, 200), Pair(86, 177), Pair(149, 99), Pair(-20, 173), Pair(37, 113),
      Pair(-176, 296), Pair(-66, 251), Pair(-15, 221), Pair(-28, 248), Pair(-16, 217), Pair(25, 139), Pair(16, 177), Pair(-35, 235),
      Pair(-69, 171), Pair(62, 65), Pair(-38, 195), Pair(74, 50), Pair(38, 195), Pair(-53, 210), Pair(-118, 259), Pair(-85, 158)
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
      Pair(22, 134), Pair(197, 109), Pair(378, 91), Pair(248, 91), Pair(127, 121), Pair(191, 110), Pair(-23, 168), Pair(32, 129),
      Pair(97, 76), Pair(182, 94), Pair(220, 55), Pair(132, 66), Pair(232, 41), Pair(160, 62), Pair(182, 66), Pair(31, 80),
      Pair(-3, 81), Pair(20, 101), Pair(115, 60), Pair(24, 72), Pair(82, 59), Pair(92, 62), Pair(82, 78), Pair(-29, 71),
      Pair(-11, 76), Pair(-8, 104), Pair(60, 64), Pair(3, 75), Pair(41, 63), Pair(9, 76), Pair(48, 82), Pair(-54, 70),
      Pair(-14, 63), Pair(-4, 88), Pair(42, 55), Pair(24, 68), Pair(69, 57), Pair(29, 64), Pair(67, 72), Pair(-24, 60),
      Pair(-57, 75), Pair(-18, 92), Pair(64, 55), Pair(-69, 93), Pair(7, 63), Pair(-12, 78), Pair(33, 76), Pair(-76, 78),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-21, -64), Pair(225, -74), Pair(233, -9), Pair(123, -21), Pair(227, -19), Pair(94, -10), Pair(-221, -1), Pair(227, -80),
      Pair(-90, -12), Pair(260, -17), Pair(162, -1), Pair(215, 2), Pair(249, -7), Pair(150, -9), Pair(182, -14), Pair(-40, -7),
      Pair(-74, 14), Pair(155, 8), Pair(80, 51), Pair(117, 48), Pair(325, 10), Pair(194, 32), Pair(233, -3), Pair(190, -32),
      Pair(40, 6), Pair(78, 35), Pair(157, 48), Pair(168, 51), Pair(86, 64), Pair(139, 51), Pair(139, 6), Pair(78, 6),
      Pair(-9, 20), Pair(32, 50), Pair(58, 68), Pair(94, 64), Pair(124, 61), Pair(55, 54), Pair(118, 26), Pair(130, 1),
      Pair(-96, 28), Pair(-108, 73), Pair(-19, 72), Pair(123, 57), Pair(-73, 96), Pair(27, 64), Pair(-57, 52), Pair(85, -10),
      Pair(-187, 56), Pair(-136, 52), Pair(-88, 50), Pair(-146, 81), Pair(-21, 66), Pair(-2, 45), Pair(90, 27), Pair(-114, 61),
      Pair(-102, 12), Pair(-129, 38), Pair(-321, 87), Pair(-182, 74), Pair(63, 20), Pair(-214, 48), Pair(-151, 45), Pair(-21, 33)
    },
    {
      Pair(-114, 55), Pair(285, 30), Pair(167, 29), Pair(80, 44), Pair(84, 18), Pair(5, 55), Pair(324, -11), Pair(92, 37),
      Pair(-35, 53), Pair(82, 57), Pair(113, 40), Pair(162, 20), Pair(197, 19), Pair(231, 16), Pair(162, 36), Pair(2, 66),
      Pair(-51, 66), Pair(76, 55), Pair(78, 46), Pair(149, 45), Pair(229, 30), Pair(237, 46), Pair(234, 30), Pair(203, 31),
      Pair(57, 42), Pair(86, 46), Pair(143, 42), Pair(180, 31), Pair(198, 34), Pair(190, 36), Pair(115, 41), Pair(125, 31),
      Pair(-1, 67), Pair(92, 47), Pair(107, 51), Pair(96, 51), Pair(200, 24), Pair(152, 56), Pair(97, 31), Pair(14, 75),
      Pair(8, 74), Pair(126, 44), Pair(91, 54), Pair(102, 45), Pair(121, 45), Pair(119, 41), Pair(67, 65), Pair(-23, 63),
      Pair(-30, 78), Pair(-58, 75), Pair(70, 39), Pair(57, 52), Pair(120, 41), Pair(-121, 68), Pair(-96, 80), Pair(-54, 59),
      Pair(-81, 90), Pair(24, 69), Pair(-82, 94), Pair(-98, 83), Pair(-42, 86), Pair(-47, 68), Pair(-34, 75), Pair(-17, 66)
    },
    {
      Pair(134, 131), Pair(179, 144), Pair(144, 153), Pair(107, 167), Pair(-23, 187), Pair(189, 130), Pair(152, 153), Pair(297, 102),
      Pair(158, 117), Pair(98, 164), Pair(181, 140), Pair(195, 128), Pair(203, 121), Pair(193, 124), Pair(267, 103), Pair(223, 111),
      Pair(94, 129), Pair(80, 153), Pair(198, 121), Pair(168, 122), Pair(227, 106), Pair(259, 107), Pair(205, 117), Pair(227, 94),
      Pair(96, 131), Pair(154, 135), Pair(30, 166), Pair(161, 121), Pair(68, 146), Pair(223, 107), Pair(-21, 175), Pair(210, 102),
      Pair(0, 142), Pair(-31, 175), Pair(51, 161), Pair(83, 151), Pair(85, 146), Pair(71, 150), Pair(40, 156), Pair(30, 143),
      Pair(34, 125), Pair(4, 158), Pair(-65, 175), Pair(29, 159), Pair(6, 157), Pair(54, 145), Pair(-3, 164), Pair(-22, 142),
      Pair(-29, 149), Pair(-88, 175), Pair(-24, 176), Pair(-14, 162), Pair(12, 153), Pair(69, 142), Pair(-175, 200), Pair(3, 140),
      Pair(-93, 174), Pair(-69, 190), Pair(-84, 188), Pair(-34, 177), Pair(-21, 167), Pair(11, 159), Pair(-55, 176), Pair(-89, 178)
    },
    {
      Pair(156, 50), Pair(16, 149), Pair(193, 73), Pair(110, 134), Pair(112, 125), Pair(44, 138), Pair(-2, 132), Pair(199, 11),
      Pair(-129, 230), Pair(43, 136), Pair(89, 166), Pair(147, 161), Pair(156, 128), Pair(438, -11), Pair(223, 74), Pair(38, 148),
      Pair(11, 138), Pair(131, 97), Pair(177, 121), Pair(140, 96), Pair(345, 12), Pair(329, -4), Pair(28, 142), Pair(262, 6),
      Pair(-128, 205), Pair(-29, 161), Pair(183, 103), Pair(244, 44), Pair(25, 175), Pair(90, 122), Pair(-101, 218), Pair(-30, 187),
      Pair(-111, 206), Pair(-107, 225), Pair(-105, 208), Pair(-25, 236), Pair(-21, 224), Pair(183, 39), Pair(-68, 200), Pair(68, 143),
      Pair(-165, 235), Pair(-172, 273), Pair(-40, 194), Pair(79, 106), Pair(-185, 304), Pair(-54, 146), Pair(-35, 157), Pair(12, 148),
      Pair(51, 104), Pair(-69, 154), Pair(81, 57), Pair(48, 99), Pair(-99, 202), Pair(-157, 185), Pair(34, 209), Pair(78, 31),
      Pair(21, 79), Pair(-201, 241), Pair(40, 120), Pair(-96, 135), Pair(3, 180), Pair(54, 137), Pair(-153, 219), Pair(102, 99)
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
      Pair(-47, 140), Pair(344, 103), Pair(253, 133), Pair(191, 150), Pair(71, 165), Pair(196, 147), Pair(-185, 211), Pair(47, 119),
      Pair(37, 94), Pair(153, 117), Pair(328, 58), Pair(111, 97), Pair(224, 68), Pair(149, 103), Pair(111, 119), Pair(51, 67),
      Pair(-78, 85), Pair(-5, 103), Pair(67, 67), Pair(37, 63), Pair(55, 68), Pair(28, 69), Pair(-105, 105), Pair(-67, 63),
      Pair(-109, 77), Pair(-13, 84), Pair(93, 52), Pair(99, 48), Pair(17, 76), Pair(20, 44), Pair(-9, 87), Pair(-74, 51),
      Pair(-62, 51), Pair(115, 37), Pair(98, 20), Pair(128, 19), Pair(-16, 59), Pair(128, 17), Pair(5, 61), Pair(23, 29),
      Pair(-135, 75), Pair(29, 54), Pair(91, 20), Pair(-121, 106), Pair(-116, 45), Pair(-26, 55), Pair(-35, 68), Pair(-68, 55),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-49, -105), Pair(-40, -64), Pair(151, -73), Pair(39, -61), Pair(-60, -31), Pair(150, -97), Pair(65, -153), Pair(-29, -121),
      Pair(46, -58), Pair(95, -56), Pair(-107, 33), Pair(96, 4), Pair(153, -30), Pair(-157, 20), Pair(30, -35), Pair(-29, -51),
      Pair(27, -88), Pair(-70, 1), Pair(98, 54), Pair(195, 37), Pair(581, -50), Pair(225, 23), Pair(340, -82), Pair(108, -48),
      Pair(93, -24), Pair(-102, 44), Pair(151, 6), Pair(138, 52), Pair(100, 40), Pair(-10, 89), Pair(359, -26), Pair(187, -115),
      Pair(36, -15), Pair(-17, 28), Pair(26, 72), Pair(-97, 56), Pair(169, 55), Pair(-68, 45), Pair(-79, -15), Pair(13, 3),
      Pair(-118, 15), Pair(-37, 31), Pair(-34, 77), Pair(9, 61), Pair(134, 49), Pair(-46, 79), Pair(17, -44), Pair(-82, 2),
      Pair(20, -89), Pair(9, 14), Pair(-79, 14), Pair(-185, 47), Pair(-270, 55), Pair(-53, 11), Pair(-95, -43), Pair(71, -16),
      Pair(-128, -49), Pair(-157, 71), Pair(37, 5), Pair(-66, 13), Pair(82, -23), Pair(-297, 20), Pair(-318, 20), Pair(-2, -73)
    },
    {
      Pair(10, -11), Pair(82, -39), Pair(71, 5), Pair(336, -6), Pair(-210, 16), Pair(-70, -3), Pair(10, -43), Pair(37, 32),
      Pair(-140, -25), Pair(33, 4), Pair(9, -8), Pair(91, -19), Pair(39, 1), Pair(-10, -2), Pair(208, -36), Pair(56, 0),
      Pair(-36, 18), Pair(-47, 25), Pair(151, 7), Pair(-54, 14), Pair(108, -14), Pair(55, 35), Pair(-6, 7), Pair(14, -3),
      Pair(-66, 26), Pair(45, -5), Pair(185, 8), Pair(95, 6), Pair(132, 0), Pair(26, 16), Pair(-45, -3), Pair(316, -58),
      Pair(49, -8), Pair(217, -43), Pair(19, 13), Pair(232, -28), Pair(101, -38), Pair(187, 4), Pair(-59, 7), Pair(377, -20),
      Pair(11, 9), Pair(205, -41), Pair(144, -7), Pair(21, 19), Pair(-135, 41), Pair(-28, 19), Pair(-70, 28), Pair(0, 29),
      Pair(-70, 56), Pair(185, 3), Pair(239, -38), Pair(26, -8), Pair(23, 4), Pair(21, 5), Pair(-141, -13), Pair(-40, 16),
      Pair(-128, 32), Pair(1, 53), Pair(-116, 12), Pair(-159, 46), Pair(-135, 11), Pair(-128, 54), Pair(-24, 19), Pair(-49, 36)
    },
    {
      Pair(278, -5), Pair(123, 66), Pair(179, 43), Pair(-65, 67), Pair(191, 62), Pair(27, 69), Pair(164, 12), Pair(423, -15),
      Pair(342, -17), Pair(285, -3), Pair(160, 47), Pair(117, 30), Pair(218, 47), Pair(146, 34), Pair(174, 12), Pair(264, 3),
      Pair(84, 59), Pair(152, 42), Pair(102, 59), Pair(148, 26), Pair(212, 44), Pair(285, 13), Pair(197, 44), Pair(89, 64),
      Pair(99, 44), Pair(38, 49), Pair(119, 53), Pair(-232, 117), Pair(39, 94), Pair(316, -15), Pair(415, -27), Pair(93, 68),
      Pair(-102, 73), Pair(183, 40), Pair(243, 44), Pair(70, 54), Pair(385, 11), Pair(75, 45), Pair(174, 33), Pair(53, 40),
      Pair(-95, 63), Pair(-36, 70), Pair(48, 37), Pair(44, 36), Pair(-176, 132), Pair(-34, 49), Pair(148, 56), Pair(-96, 89),
      Pair(-145, 79), Pair(-77, 99), Pair(-144, 97), Pair(86, 32), Pair(-3, 92), Pair(-51, 60), Pair(-164, 105), Pair(-92, 94),
      Pair(-258, 118), Pair(-112, 110), Pair(91, 89), Pair(-205, 99), Pair(0, 100), Pair(-69, 91), Pair(29, 43), Pair(-198, 124)
    },
    {
      Pair(197, -53), Pair(-257, 218), Pair(35, 91), Pair(243, 38), Pair(224, 7), Pair(-135, 156), Pair(144, 39), Pair(171, -5),
      Pair(149, 67), Pair(-98, 173), Pair(128, 97), Pair(87, 86), Pair(77, 125), Pair(37, 129), Pair(17, 79), Pair(-13, 71),
      Pair(115, 69), Pair(178, 34), Pair(111, 103), Pair(260, 12), Pair(194, 85), Pair(121, 94), Pair(211, 52), Pair(31, 73),
      Pair(112, 104), Pair(84, 153), Pair(114, 101), Pair(115, 59), Pair(93, 123), Pair(13, 150), Pair(136, 109), Pair(84, 112),
      Pair(82, 81), Pair(87, 107), Pair(46, 78), Pair(-16, 146), Pair(52, 130), Pair(99, 102), Pair(-10, 146), Pair(102, 38),
      Pair(116, 41), Pair(87, 143), Pair(-7, 122), Pair(65, 88), Pair(-157, 206), Pair(-115, 165), Pair(46, 82), Pair(22, 99),
      Pair(223, 81), Pair(73, 72), Pair(36, 148), Pair(-68, 133), Pair(-102, 184), Pair(75, 87), Pair(69, 96), Pair(39, 147),
      Pair(16, 85), Pair(-1, 65), Pair(63, 63), Pair(-159, 229), Pair(-40, 61), Pair(-121, 159), Pair(12, 25), Pair(-111, 105)
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
      Pair(6, 46), Pair(27, 65), Pair(36, 94), Pair(41, 110), Pair(45, 119), Pair(51, 127), Pair(56, 126), Pair(61, 121),
      Pair(66, 107)
  },
  {
      Pair(129, 168), Pair(139, 138), Pair(147, 168), Pair(154, 183), Pair(160, 191), Pair(166, 201), Pair(170, 204), Pair(174, 202),
      Pair(179, 190)
  },
  {
      Pair(130, 157), Pair(137, 140), Pair(145, 165), Pair(150, 179), Pair(153, 190), Pair(157, 200), Pair(166, 198), Pair(168, 193),
      Pair(174, 175)
  },
  {
      Pair(110, 173), Pair(127, 116), Pair(140, 153), Pair(140, 173), Pair(145, 180), Pair(138, 193), Pair(139, 193), Pair(149, 186),
      Pair(143, 177)
  },
  {
      Pair(124, 165), Pair(132, 73), Pair(127, 143), Pair(111, 158), Pair(142, 164), Pair(132, 178), Pair(117, 175), Pair(126, 170),
      Pair(125, 158)
  },
  {
      Pair(124, 143), Pair(51, 145), Pair(69, 135), Pair(87, 147), Pair(116, 149), Pair(118, 154), Pair(140, 147), Pair(135, 141),
      Pair(173, 120)
  },
  {
      Pair(100, 167), Pair(-104, 94), Pair(50, 110), Pair(69, 106), Pair(74, 101), Pair(56, 117), Pair(39, 103), Pair(208, 63),
      Pair(65, 48)
  }
}};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {{
  {
      Pair(14, 16), Pair(21, 10), Pair(31, 40), Pair(36, 60), Pair(43, 76), Pair(46, 93), Pair(49, 101), Pair(51, 106),
      Pair(52, 114), Pair(58, 115), Pair(67, 114), Pair(81, 114), Pair(90, 126), Pair(136, 81)
  },
  {
      Pair(119, 118), Pair(129, 122), Pair(147, 133), Pair(153, 154), Pair(160, 168), Pair(163, 177), Pair(164, 186), Pair(166, 190),
      Pair(166, 198), Pair(175, 191), Pair(178, 197), Pair(200, 182), Pair(210, 183), Pair(228, 178)
  },
  {
      Pair(100, 154), Pair(124, 113), Pair(130, 135), Pair(137, 151), Pair(144, 167), Pair(148, 180), Pair(148, 189), Pair(152, 195),
      Pair(153, 201), Pair(162, 202), Pair(167, 198), Pair(211, 188), Pair(174, 219), Pair(208, 183)
  },
  {
      Pair(74, 182), Pair(104, 107), Pair(117, 124), Pair(118, 148), Pair(131, 155), Pair(139, 171), Pair(132, 184), Pair(135, 191),
      Pair(140, 197), Pair(151, 196), Pair(156, 198), Pair(163, 194), Pair(207, 197), Pair(243, 174)
  },
  {
      Pair(102, 163), Pair(108, 74), Pair(105, 115), Pair(122, 131), Pair(143, 140), Pair(130, 159), Pair(145, 165), Pair(139, 167),
      Pair(127, 181), Pair(143, 179), Pair(126, 185), Pair(115, 184), Pair(133, 222), Pair(130, 174)
  },
  {
      Pair(46, 189), Pair(250, 53), Pair(107, 89), Pair(141, 112), Pair(120, 119), Pair(125, 136), Pair(103, 149), Pair(147, 142),
      Pair(147, 155), Pair(153, 154), Pair(132, 156), Pair(124, 162), Pair(121, 193), Pair(1, 180)
  },
  {
      Pair(-87, 130), Pair(74, 47), Pair(140, 38), Pair(144, 63), Pair(157, 89), Pair(55, 100), Pair(32, 113), Pair(80, 108),
      Pair(83, 108), Pair(81, 116), Pair(77, 101), Pair(124, 103), Pair(52, 200), Pair(91, 125)
  }
}};

constexpr RookMobilityTable<ScorePair> kRookMobility = {{
  {
      Pair(-10, 44), Pair(3, 83), Pair(4, 102), Pair(7, 110), Pair(11, 114), Pair(18, 117), Pair(24, 123), Pair(30, 128),
      Pair(35, 135), Pair(39, 140), Pair(44, 144), Pair(46, 149), Pair(49, 151), Pair(62, 139), Pair(76, 132)
  },
  {
      Pair(151, 212), Pair(161, 229), Pair(168, 248), Pair(170, 271), Pair(176, 280), Pair(183, 286), Pair(190, 292), Pair(198, 296),
      Pair(200, 302), Pair(212, 302), Pair(208, 309), Pair(213, 308), Pair(204, 318), Pair(214, 304), Pair(225, 294)
  },
  {
      Pair(158, 248), Pair(168, 272), Pair(170, 277), Pair(177, 290), Pair(180, 301), Pair(180, 311), Pair(180, 319), Pair(186, 320),
      Pair(192, 323), Pair(200, 327), Pair(204, 330), Pair(212, 332), Pair(220, 333), Pair(231, 330), Pair(264, 312)
  },
  {
      Pair(205, 185), Pair(187, 218), Pair(178, 236), Pair(176, 268), Pair(173, 284), Pair(162, 300), Pair(168, 305), Pair(169, 306),
      Pair(168, 312), Pair(180, 314), Pair(177, 319), Pair(191, 320), Pair(200, 324), Pair(188, 324), Pair(231, 305)
  },
  {
      Pair(171, 161), Pair(204, 180), Pair(188, 219), Pair(205, 239), Pair(144, 269), Pair(145, 278), Pair(133, 290), Pair(144, 286),
      Pair(157, 284), Pair(164, 290), Pair(181, 287), Pair(170, 300), Pair(191, 296), Pair(188, 297), Pair(228, 272)
  },
  {
      Pair(234, 142), Pair(42, 225), Pair(110, 198), Pair(84, 232), Pair(107, 233), Pair(123, 238), Pair(115, 265), Pair(99, 262),
      Pair(115, 259), Pair(125, 257), Pair(105, 272), Pair(147, 265), Pair(163, 267), Pair(174, 265), Pair(236, 237)
  },
  {
      Pair(94, 2), Pair(-95, 109), Pair(66, 162), Pair(131, 181), Pair(-51, 234), Pair(-95, 244), Pair(53, 245), Pair(35, 234),
      Pair(24, 236), Pair(104, 235), Pair(155, 218), Pair(133, 226), Pair(209, 210), Pair(208, 207), Pair(384, 172)
  }
}};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {{
  {
      Pair(42, 303), Pair(100, 84), Pair(118, 156), Pair(125, 208), Pair(124, 244), Pair(125, 269), Pair(128, 286), Pair(129, 312),
      Pair(131, 325), Pair(135, 326), Pair(135, 340), Pair(137, 345), Pair(141, 343), Pair(142, 344), Pair(143, 346), Pair(146, 341),
      Pair(146, 341), Pair(151, 334), Pair(157, 330), Pair(166, 317), Pair(173, 297), Pair(205, 265), Pair(207, 251), Pair(196, 256),
      Pair(135, 294), Pair(277, 190), Pair(295, 168), Pair(199, 172)
  },
  {
      Pair(346, 87), Pair(358, 272), Pair(360, 335), Pair(366, 376), Pair(367, 400), Pair(374, 413), Pair(377, 434), Pair(378, 465),
      Pair(382, 466), Pair(385, 476), Pair(389, 483), Pair(392, 485), Pair(389, 496), Pair(388, 500), Pair(389, 494), Pair(390, 497),
      Pair(386, 507), Pair(380, 507), Pair(369, 520), Pair(393, 497), Pair(403, 475), Pair(402, 487), Pair(400, 476), Pair(386, 467),
      Pair(390, 460), Pair(415, 441), Pair(330, 472), Pair(227, 452)
  },
  {
      Pair(285, 566), Pair(281, 539), Pair(337, 476), Pair(341, 471), Pair(347, 486), Pair(353, 511), Pair(354, 537), Pair(354, 555),
      Pair(357, 565), Pair(358, 571), Pair(365, 570), Pair(366, 582), Pair(370, 578), Pair(364, 595), Pair(371, 588), Pair(372, 590),
      Pair(378, 587), Pair(382, 582), Pair(381, 578), Pair(424, 542), Pair(417, 548), Pair(477, 500), Pair(473, 489), Pair(523, 454),
      Pair(519, 470), Pair(444, 477), Pair(492, 502), Pair(351, 559)
  },
  {
      Pair(205, 365), Pair(152, 417), Pair(119, 403), Pair(207, 283), Pair(259, 362), Pair(287, 335), Pair(251, 398), Pair(259, 410),
      Pair(261, 401), Pair(271, 418), Pair(274, 416), Pair(274, 425), Pair(253, 437), Pair(235, 464), Pair(272, 436), Pair(270, 444),
      Pair(248, 463), Pair(294, 440), Pair(313, 412), Pair(349, 392), Pair(387, 359), Pair(344, 391), Pair(394, 348), Pair(490, 294),
      Pair(312, 362), Pair(328, 383), Pair(347, 464), Pair(267, 392)
  },
  {
      Pair(102, 154), Pair(124, 133), Pair(-6, 231), Pair(151, 197), Pair(115, 316), Pair(172, 110), Pair(139, 303), Pair(173, 272),
      Pair(182, 246), Pair(171, 254), Pair(143, 305), Pair(88, 372), Pair(156, 310), Pair(160, 328), Pair(100, 365), Pair(80, 377),
      Pair(104, 366), Pair(162, 307), Pair(218, 299), Pair(223, 293), Pair(185, 303), Pair(295, 256), Pair(214, 265), Pair(514, 112),
      Pair(297, 251), Pair(317, 210), Pair(125, 345), Pair(173, 249)
  },
  {
      Pair(12, 4), Pair(53, 79), Pair(168, 219), Pair(-86, -125), Pair(193, -16), Pair(12, 206), Pair(84, 311), Pair(168, 295),
      Pair(16, 295), Pair(-79, 396), Pair(143, 305), Pair(-67, 401), Pair(102, 307), Pair(58, 342), Pair(80, 332), Pair(91, 316),
      Pair(233, 252), Pair(62, 351), Pair(242, 254), Pair(134, 313), Pair(207, 269), Pair(362, 196), Pair(382, 158), Pair(225, 223),
      Pair(328, 159), Pair(203, 254), Pair(132, 143), Pair(140, 246)
  },
  {
      Pair(-14, -28), Pair(-2, 40), Pair(116, 218), Pair(135, 213), Pair(40, 28), Pair(168, 109), Pair(-6, 11), Pair(49, 116),
      Pair(34, 255), Pair(156, 194), Pair(172, 201), Pair(-3, 237), Pair(208, 192), Pair(65, 220), Pair(192, 192), Pair(145, 226),
      Pair(-16, 336), Pair(251, 168), Pair(35, 297), Pair(191, 187), Pair(228, 178), Pair(237, 194), Pair(52, 253), Pair(158, 212),
      Pair(265, 175), Pair(185, 195), Pair(2, 263), Pair(100, 232)
  }
}};

constexpr KingBuckets<RankTable<ScorePair>> kPassedPawnBonus = {{
  {
      Pair(0, 0), Pair(-26, -74), Pair(-16, -71), Pair(-4, -36), Pair(30, 6), Pair(43, 82), Pair(138, 155), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-6, -39), Pair(-18, -19), Pair(-5, 8), Pair(22, 47), Pair(12, 132), Pair(61, 110), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-42, -38), Pair(-47, -22), Pair(-28, 6), Pair(19, 40), Pair(38, 121), Pair(127, 158), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-60, -49), Pair(-45, -31), Pair(-53, 11), Pair(1, 45), Pair(10, 128), Pair(143, 167), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-59, -56), Pair(-42, -49), Pair(-52, -2), Pair(-29, 51), Pair(-10, 120), Pair(175, 133), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-66, -40), Pair(-48, -51), Pair(-50, -14), Pair(-37, 42), Pair(-31, 129), Pair(136, 123), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-57, -21), Pair(-115, -18), Pair(-97, 12), Pair(-32, 37), Pair(-50, 107), Pair(161, 109), Pair(0, 0)
  }
}};

constexpr KingBuckets<RankTable<ScorePair>> kPawnPhalanxBonus = {{
  {
      Pair(0, 0), Pair(7, -3), Pair(18, 8), Pair(22, 24), Pair(60, 91), Pair(155, 237), Pair(-11, 478), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(15, 3), Pair(17, 16), Pair(17, 28), Pair(42, 75), Pair(114, 258), Pair(96, 380), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(11, 2), Pair(23, 8), Pair(17, 25), Pair(53, 90), Pair(98, 259), Pair(122, 449), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(1, 2), Pair(20, 7), Pair(19, 27), Pair(37, 94), Pair(6, 248), Pair(-40, 463), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-6, 0), Pair(3, 2), Pair(39, 13), Pair(25, 91), Pair(-104, 237), Pair(-172, 359), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-21, 0), Pair(-27, -2), Pair(13, 3), Pair(9, 75), Pair(25, 166), Pair(-147, 554), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-86, 18), Pair(-19, 17), Pair(-44, 39), Pair(73, 76), Pair(-221, 171), Pair(-64, 8), Pair(0, 0)
  }
}};

constexpr KingBuckets<RankTable<ScorePair>> kDefendedPawnBonus = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(23, 24), Pair(14, 19), Pair(20, 22), Pair(36, 86), Pair(172, 100), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(22, 21), Pair(16, 16), Pair(22, 24), Pair(31, 64), Pair(299, 55), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(30, 10), Pair(23, 7), Pair(20, 19), Pair(43, 62), Pair(226, 80), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(37, 4), Pair(29, -1), Pair(21, 14), Pair(22, 67), Pair(253, 43), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(23, 1), Pair(36, -5), Pair(24, 7), Pair(59, 44), Pair(159, 51), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(-2, 4), Pair(-6, -2), Pair(7, 14), Pair(45, 41), Pair(215, -11), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(-60, 25), Pair(-71, 18), Pair(11, 22), Pair(153, -21), Pair(129, -4), Pair(0, 0)
  }
}};

constexpr KingBuckets<FileTable<ScorePair>> kDoubledPawnPenalty = {{
  {
      Pair(-32, -36), Pair(-8, -21), Pair(-9, -23), Pair(-7, -23), Pair(-22, -6), Pair(-28, 4), Pair(-8, -18), Pair(-47, -32)
  },
  {
      Pair(-51, -33), Pair(4, -21), Pair(-1, -29), Pair(-15, -3), Pair(-2, -11), Pair(-10, -11), Pair(-15, -23), Pair(-9, -45)
  },
  {
      Pair(-14, -55), Pair(-8, -22), Pair(-4, -21), Pair(-2, -13), Pair(-14, -6), Pair(-17, -12), Pair(-7, -23), Pair(-17, -50)
  },
  {
      Pair(-25, -54), Pair(-20, -31), Pair(6, -30), Pair(-1, -19), Pair(-2, -19), Pair(-17, -24), Pair(-13, -28), Pair(-57, -47)
  },
  {
      Pair(-22, -59), Pair(-2, -54), Pair(-12, -43), Pair(45, -57), Pair(32, -40), Pair(15, -46), Pair(-4, -47), Pair(8, -73)
  },
  {
      Pair(55, -97), Pair(-30, -60), Pair(-55, -46), Pair(42, -66), Pair(15, -48), Pair(-40, -49), Pair(-37, -47), Pair(26, -91)
  },
  {
      Pair(77, -75), Pair(-105, -4), Pair(-227, -10), Pair(-137, -106), Pair(54, -25), Pair(-63, -40), Pair(-117, -11), Pair(13, -103)
  }
}};

constexpr KingBuckets<FileTable<ScorePair>> kIsolatedPawnPenalty = {{
  {
      Pair(5, -7), Pair(-7, -10), Pair(-11, -16), Pair(-11, -19), Pair(-15, -21), Pair(-10, -9), Pair(-5, -16), Pair(17, -11)
  },
  {
      Pair(-5, -5), Pair(-2, -11), Pair(-12, -16), Pair(-15, -14), Pair(-12, -22), Pair(0, -14), Pair(-2, -10), Pair(0, -7)
  },
  {
      Pair(8, -7), Pair(-1, -15), Pair(-5, -17), Pair(-8, -22), Pair(-5, -25), Pair(-3, -16), Pair(-5, -14), Pair(15, -9)
  },
  {
      Pair(6, 2), Pair(-6, -18), Pair(-7, -12), Pair(9, -28), Pair(8, -26), Pair(0, -15), Pair(-3, -13), Pair(25, -8)
  },
  {
      Pair(8, 11), Pair(-9, -15), Pair(-10, -2), Pair(-11, -21), Pair(0, -19), Pair(-17, -9), Pair(5, -13), Pair(-16, 8)
  },
  {
      Pair(7, 13), Pair(-17, -10), Pair(-48, 10), Pair(8, -16), Pair(-37, -9), Pair(-16, -7), Pair(-51, 1), Pair(10, 7)
  },
  {
      Pair(66, 4), Pair(-58, -2), Pair(-36, 8), Pair(76, -14), Pair(4, -21), Pair(2, 1), Pair(59, -21), Pair(23, 13)
  }
}};

constexpr KingBuckets<std::array<FileTable<ScorePair>, 2>> kRookOnFileBonus = {{
  {{ // Bucket 0
    {
      Pair(24, 12), Pair(21, 15), Pair(24, 20), Pair(26, 12), Pair(30, 16), Pair(50, 5), Pair(41, 22), Pair(109, -21)
    },
    {
      Pair(12, 16), Pair(14, 5), Pair(16, 11), Pair(20, 10), Pair(19, 5), Pair(29, -9), Pair(34, -8), Pair(58, -17)
    }
  }},
  {{ // Bucket 1
    {
      Pair(38, 9), Pair(21, 11), Pair(25, 12), Pair(38, -11), Pair(32, 16), Pair(55, 0), Pair(54, 13), Pair(59, 10)
    },
    {
      Pair(53, 12), Pair(29, 5), Pair(17, 16), Pair(33, -16), Pair(33, 1), Pair(36, -9), Pair(45, -8), Pair(13, 12)
    }
  }},
  {{ // Bucket 2
    {
      Pair(30, 10), Pair(37, 2), Pair(34, 6), Pair(30, 11), Pair(36, 13), Pair(42, 8), Pair(47, 5), Pair(69, -3)
    },
    {
      Pair(9, 31), Pair(19, 10), Pair(20, 3), Pair(18, 5), Pair(19, 2), Pair(25, 0), Pair(32, -7), Pair(15, 12)
    }
  }},
  {{ // Bucket 3
    {
      Pair(43, 3), Pair(64, -15), Pair(68, -12), Pair(28, 4), Pair(49, 7), Pair(40, 8), Pair(54, -6), Pair(75, -2)
    },
    {
      Pair(-1, 43), Pair(30, 5), Pair(41, -1), Pair(36, -7), Pair(33, -2), Pair(20, 0), Pair(24, -3), Pair(21, 16)
    }
  }},
  {{ // Bucket 4
    {
      Pair(13, 6), Pair(74, -20), Pair(75, -14), Pair(38, -4), Pair(24, 8), Pair(46, -4), Pair(75, -13), Pair(34, 4)
    },
    {
      Pair(-37, 66), Pair(17, 17), Pair(89, -12), Pair(61, -15), Pair(3, 5), Pair(56, -14), Pair(45, -11), Pair(-108, 61)
    }
  }},
  {{ // Bucket 5
    {
      Pair(76, -3), Pair(94, -30), Pair(96, -31), Pair(66, -17), Pair(67, -13), Pair(60, -19), Pair(142, -43), Pair(22, 7)
    },
    {
      Pair(-8, 80), Pair(32, 18), Pair(60, 8), Pair(119, -27), Pair(60, -17), Pair(26, -14), Pair(128, -30), Pair(-52, 51)
    }
  }},
  {{ // Bucket 6
    {
      Pair(129, -31), Pair(92, -17), Pair(86, -36), Pair(87, -8), Pair(74, -48), Pair(112, -21), Pair(47, -11), Pair(90, -33)
    },
    {
      Pair(52, 74), Pair(-34, 43), Pair(-25, -11), Pair(152, -37), Pair(298, -90), Pair(108, -10), Pair(135, -3), Pair(238, -21)
    }
  }}
}};

constexpr KingBuckets<std::array<ScorePair, 12>> kPawnShelterTable = {{
  {
      Pair(21, -11), Pair(50, -18), Pair(28, -10),
      Pair(44, -22), Pair(53, -25), Pair(46, -24),
      Pair(54, -10), Pair(0, 0), Pair(47, -8),
      Pair(18, -1), Pair(21, -12), Pair(16, 0)
  },
  {
      Pair(18, -8), Pair(10, 0), Pair(12, -7),
      Pair(39, -24), Pair(27, -6), Pair(35, -24),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(13, -4), Pair(14, -1), Pair(13, -4),
      Pair(29, -16), Pair(17, -12), Pair(26, -14),
      Pair(58, -20), Pair(0, 0), Pair(50, -18),
      Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(32, 3), Pair(55, -3), Pair(20, 8),
      Pair(26, -6), Pair(45, -12), Pair(27, -8),
      Pair(45, -8), Pair(0, 0), Pair(45, -6),
      Pair(14, 1), Pair(40, -14), Pair(11, 3)
  },
  {
      Pair(60, 12), Pair(108, 5), Pair(16, 29),
      Pair(53, -13), Pair(76, -7), Pair(48, -10),
      Pair(60, 3), Pair(0, 0), Pair(54, 5),
      Pair(25, 6), Pair(39, 2), Pair(22, 6)
  },
  {
      Pair(33, 12), Pair(77, -23), Pair(-12, 41),
      Pair(97, -5), Pair(136, -14), Pair(111, -6),
      Pair(71, 27), Pair(0, 0), Pair(-2, 36),
      Pair(44, 8), Pair(86, -21), Pair(27, 12)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(-15, 10), Pair(0, 0), Pair(-47, 15),
      Pair(15, -4), Pair(13, -106), Pair(93, -18)
  }
}};

constexpr KingBuckets<std::array<ScorePair, 21>> kPawnStormTable = {{
  {
      Pair(-11, 7), Pair(-19, 10), Pair(-9, 8),
      Pair(-12, 8), Pair(-27, 18), Pair(-11, 8),
      Pair(-7, -1), Pair(-18, 10), Pair(-2, -1),
      Pair(8, 1), Pair(-14, 13), Pair(12, -2),
      Pair(40, -10), Pair(42, 4), Pair(29, -10),
      Pair(120, -24), Pair(2, -42), Pair(148, -53),
      Pair(93, -81), Pair(0, 0), Pair(94, -76)
  },
  {
      Pair(-10, 7), Pair(-13, 15), Pair(-8, 9),
      Pair(-11, 11), Pair(-22, 19), Pair(-12, 11),
      Pair(-4, 1), Pair(-14, 14), Pair(0, 4),
      Pair(11, 2), Pair(-12, 12), Pair(10, 5),
      Pair(27, -4), Pair(35, 3), Pair(23, -7),
      Pair(66, 20), Pair(-5, -36), Pair(56, -50),
      Pair(36, -53), Pair(0, 0), Pair(66, -65)
  },
  {
      Pair(-13, 12), Pair(-20, 14), Pair(-12, 12),
      Pair(-9, 6), Pair(-19, 13), Pair(-10, 6),
      Pair(-1, -1), Pair(-17, 10), Pair(-2, 1),
      Pair(7, 1), Pair(-10, 8), Pair(10, 1),
      Pair(30, -8), Pair(35, 4), Pair(29, -8),
      Pair(42, 6), Pair(-35, -19), Pair(59, -29),
      Pair(44, -55), Pair(0, 0), Pair(27, -50)
  },
  {
      Pair(3, -1), Pair(-15, 11), Pair(-4, 2),
      Pair(-1, 1), Pair(-12, 13), Pair(1, 2),
      Pair(4, -6), Pair(-12, 7), Pair(2, -3),
      Pair(18, -4), Pair(-1, 0), Pair(10, -2),
      Pair(20, -10), Pair(31, 1), Pair(23, -10),
      Pair(16, -2), Pair(-26, -20), Pair(69, -21),
      Pair(35, -52), Pair(0, 0), Pair(23, -51)
  },
  {
      Pair(45, -17), Pair(-11, 9), Pair(15, -12),
      Pair(0, -4), Pair(18, 4), Pair(4, -6),
      Pair(29, -12), Pair(3, 3), Pair(5, -11),
      Pair(28, -14), Pair(25, -9), Pair(29, -13),
      Pair(35, -16), Pair(39, -11), Pair(15, -13),
      Pair(8, -5), Pair(-6, -40), Pair(53, -20),
      Pair(58, -62), Pair(0, 0), Pair(54, -64)
  },
  {
      Pair(63, -19), Pair(26, -6), Pair(-4, -15),
      Pair(-17, -8), Pair(7, 1), Pair(-9, -9),
      Pair(8, -19), Pair(18, -13), Pair(6, -19),
      Pair(22, -21), Pair(31, -21), Pair(20, -20),
      Pair(46, -29), Pair(68, -38), Pair(65, -33),
      Pair(46, -36), Pair(30, -82), Pair(10, -6),
      Pair(54, -70), Pair(0, 0), Pair(39, -66)
  },
  {
      Pair(-6, -7), Pair(13, 12), Pair(-34, 4),
      Pair(-147, 12), Pair(-7, 6), Pair(-66, 4),
      Pair(8, -24), Pair(-67, -6), Pair(-25, -12),
      Pair(0, -21), Pair(-13, -17), Pair(-35, -7),
      Pair(142, -47), Pair(17, -33), Pair(-33, -22),
      Pair(2, -45), Pair(-25, -74), Pair(-3, 32),
      Pair(69, -61), Pair(0, 0), Pair(-14, -68)
  }
}};

constexpr KingBuckets<std::array<ScorePair, 8>> kKingPPDistanceTable = {{
  {
      Pair(0, 0), Pair(8, 37), Pair(-4, 46), Pair(-10, 40), Pair(0, 33), Pair(3, 32), Pair(4, 35), Pair(-14, 27)
  },
  {
      Pair(0, 0), Pair(-9, 18), Pair(-11, 13), Pair(-7, 10), Pair(-8, 11), Pair(1, 8), Pair(61, 110), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(11, 29), Pair(-10, 30), Pair(-10, 23), Pair(-11, 16), Pair(-15, 15), Pair(0, 6), Pair(15, -11)
  },
  {
      Pair(0, 0), Pair(2, 40), Pair(-8, 32), Pair(-10, 22), Pair(-27, 16), Pair(-49, 15), Pair(-24, 0), Pair(-55, -3)
  },
  {
      Pair(0, 0), Pair(8, 42), Pair(2, 30), Pair(-18, 15), Pair(-58, 12), Pair(-50, -3), Pair(-78, 2), Pair(-61, -11)
  },
  {
      Pair(0, 0), Pair(-3, 52), Pair(25, 35), Pair(-15, 7), Pair(-62, -8), Pair(-78, -14), Pair(-79, -15), Pair(-152, 5)
  },
  {
      Pair(0, 0), Pair(-35, 158), Pair(-5, 96), Pair(5, 17), Pair(2, -16), Pair(-27, -25), Pair(-138, -10), Pair(-79, -18)
  }
}};

constexpr KingBuckets<std::array<ScorePair, 8>> kEnemyKingPPDistanceTable = {{
  {
      Pair(0, 0), Pair(-90, -14), Pair(-19, 5), Pair(-7, 33), Pair(6, 46), Pair(10, 58), Pair(14, 64), Pair(5, 54)
  },
  {
      Pair(0, 0), Pair(-87, -28), Pair(-25, -5), Pair(-5, 16), Pair(-2, 31), Pair(0, 41), Pair(-5, 50), Pair(-27, 45)
  },
  {
      Pair(0, 0), Pair(-65, -30), Pair(-16, -1), Pair(-2, 23), Pair(10, 35), Pair(16, 45), Pair(17, 52), Pair(9, 51)
  },
  {
      Pair(0, 0), Pair(-45, -36), Pair(-28, 4), Pair(-16, 30), Pair(-5, 47), Pair(-4, 58), Pair(14, 61), Pair(14, 55)
  },
  {
      Pair(0, 0), Pair(-9, -44), Pair(-4, 4), Pair(-23, 42), Pair(-19, 60), Pair(-19, 71), Pair(6, 75), Pair(-13, 73)
  },
  {
      Pair(0, 0), Pair(-17, -38), Pair(-16, 8), Pair(-23, 44), Pair(-20, 64), Pair(1, 75), Pair(-10, 85), Pair(-28, 91)
  },
  {
      Pair(0, 0), Pair(53, -63), Pair(-47, 9), Pair(-54, 46), Pair(-49, 73), Pair(-18, 79), Pair(-21, 84), Pair(-90, 93)
  }
}};

constexpr KingBuckets<ScorePair> kKingCantReachPPBonus = {
  Pair(-524, 236), Pair(42, 245), Pair(-174, 249), Pair(-103, 228), Pair(-126, 172), Pair(-13, 104), Pair(115, 78)
};


constexpr KingBuckets<std::array<FileTable<ScorePair>, 2>> kKingOnFilePenalty = {{
  {{ // Bucket 0
    {
      Pair(-143, 13), Pair(-95, -11), Pair(-30, -16), Pair(-17, -21), Pair(-22, -13), Pair(-28, -12), Pair(-56, -5), Pair(-42, 2)
    },
    {
      Pair(-72, 153), Pair(-58, 58), Pair(-9, 10), Pair(2, -8), Pair(-7, -6), Pair(2, 0), Pair(-33, 26), Pair(-30, 63)
    }
  }},
  {{ // Bucket 1
    {
      Pair(-9, 45), Pair(-35, 18), Pair(-48, -3), Pair(-22, -6), Pair(-35, 6), Pair(-53, 3), Pair(-27, 18), Pair(-16, 29)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(-26, 45), Pair(-20, 37), Pair(-23, 28), Pair(-37, 27), Pair(0, 0), Pair(0, 0)
    }
  }},
  {{ // Bucket 2
    {
      Pair(-94, -17), Pair(-77, -15), Pair(-24, -20), Pair(-40, -19), Pair(-27, -17), Pair(-29, -13), Pair(-54, -1), Pair(-40, -1)
    },
    {
      Pair(-76, 87), Pair(-61, 40), Pair(-35, 31), Pair(-21, 9), Pair(-11, 1), Pair(10, 2), Pair(-45, 31), Pair(-50, 50)
    }
  }},
  {{ // Bucket 3
    {
      Pair(-12, -37), Pair(-17, -12), Pair(-16, -16), Pair(-4, -21), Pair(-8, -17), Pair(1, -13), Pair(-14, -7), Pair(-31, 3)
    },
    {
      Pair(-22, 36), Pair(11, 4), Pair(7, -6), Pair(19, -21), Pair(19, -20), Pair(21, -3), Pair(-1, 11), Pair(-1, 26)
    }
  }},
  {{ // Bucket 4
    {
      Pair(49, -35), Pair(2, -15), Pair(-45, -5), Pair(8, -14), Pair(6, -8), Pair(-9, -5), Pair(11, -13), Pair(41, -4)
    },
    {
      Pair(60, -18), Pair(15, -18), Pair(-26, -5), Pair(43, -32), Pair(38, -22), Pair(-11, -3), Pair(15, -2), Pair(28, -6)
    }
  }},
  {{ // Bucket 5
    {
      Pair(104, -37), Pair(-20, -28), Pair(7, -20), Pair(11, -17), Pair(83, -22), Pair(24, -14), Pair(53, -29), Pair(45, -10)
    },
    {
      Pair(117, -59), Pair(-11, -41), Pair(23, -29), Pair(130, -54), Pair(118, -57), Pair(-5, -22), Pair(62, -37), Pair(73, -33)
    }
  }},
  {{ // Bucket 6
    {
      Pair(85, -61), Pair(7, -83), Pair(59, -77), Pair(107, -52), Pair(49, -30), Pair(40, -38), Pair(50, -66), Pair(124, -10)
    },
    {
      Pair(57, 1), Pair(65, -59), Pair(58, -71), Pair(30, -23), Pair(63, -41), Pair(81, -40), Pair(46, -41), Pair(40, -48)
    }
  }}
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {{ // Bucket 0
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(11, 8), Pair(29, 0), Pair(88, -32), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(11, 8), Pair(28, 13), Pair(74, -6), Pair(128, -45), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(29, -21), Pair(49, -25), Pair(79, -22), Pair(139, -35), Pair(176, -56), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(5, 18), Pair(19, 38), Pair(37, 63), Pair(101, 52), Pair(161, 56), Pair(264, 13), Pair(393, -61)
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
      Pair(0, 0), Pair(12, 2), Pair(19, 3), Pair(69, -34), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(13, 2), Pair(31, 2), Pair(62, -10), Pair(113, -75), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(26, -20), Pair(43, -22), Pair(48, -9), Pair(104, -21), Pair(136, -28), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(5, 29), Pair(20, 64), Pair(33, 83), Pair(81, 82), Pair(118, 80), Pair(193, 55), Pair(317, -49)
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
      Pair(0, 0), Pair(28, -1), Pair(47, -7), Pair(96, -28), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(23, -2), Pair(51, -6), Pair(88, -16), Pair(66, -33), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(30, -19), Pair(52, -20), Pair(79, -18), Pair(122, -23), Pair(176, -40), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(8, 24), Pair(22, 45), Pair(65, 38), Pair(135, 22), Pair(172, 22), Pair(323, -46), Pair(344, -40)
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
      Pair(0, 0), Pair(40, -3), Pair(65, -10), Pair(114, -18), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(28, -4), Pair(55, -6), Pair(75, -11), Pair(64, -28), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(41, -21), Pair(73, -24), Pair(75, -13), Pair(139, -22), Pair(173, -33), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(24, 16), Pair(48, 32), Pair(104, 13), Pair(190, 3), Pair(271, -25), Pair(480, -125), Pair(368, -24)
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
      Pair(0, 0), Pair(60, -4), Pair(78, -10), Pair(98, -16), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(20, 2), Pair(38, 0), Pair(74, -6), Pair(-4, -1), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(47, -19), Pair(73, -19), Pair(102, -16), Pair(125, -14), Pair(187, -31), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(-64, 81), Pair(23, 55), Pair(69, 45), Pair(155, 9), Pair(399, -90), Pair(340, -46), Pair(210, 26)
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
      Pair(0, 0), Pair(66, -1), Pair(103, -9), Pair(45, -3), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(51, -1), Pair(73, -1), Pair(62, -7), Pair(-16, -18), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(25, -11), Pair(104, -22), Pair(138, -19), Pair(141, -10), Pair(137, -20), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(31, 48), Pair(20, 65), Pair(181, -8), Pair(274, -54), Pair(432, -86), Pair(235, 20), Pair(-17, 149)
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
      Pair(0, 0), Pair(68, -7), Pair(191, -27), Pair(193, -37), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(16, 5), Pair(49, -12), Pair(134, -14), Pair(43, -50), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(94, -40), Pair(99, -26), Pair(192, -35), Pair(154, -28), Pair(153, -16), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(-142, 125), Pair(206, -50), Pair(318, -115), Pair(33, 50), Pair(272, -51), Pair(107, 41), Pair(16, 151)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    }
  }}
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {{
  {
      Pair(0, 0), Pair(35, 24), Pair(8, 35), Pair(41, 0), Pair(22, 26), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(29, 23), Pair(13, 19), Pair(43, 9), Pair(20, 24), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(77, 4), Pair(30, 14), Pair(59, -1), Pair(27, 22), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(78, -2), Pair(42, 8), Pair(54, -3), Pair(68, -6), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(81, -7), Pair(35, 14), Pair(52, -5), Pair(122, -33), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(98, -16), Pair(44, 12), Pair(110, -17), Pair(131, -35), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(120, -22), Pair(-3, 13), Pair(171, -49), Pair(165, -59), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {{ // Bucket 0
    {
      Pair(-13, 24), Pair(-9, 25)
    },
    {
      Pair(-81, -35), Pair(-64, -52)
    },
    {
      Pair(-57, -64), Pair(-67, -88)
    },
    {
      Pair(-100, 3), Pair(-72, -42)
    },
    {
      Pair(-54, -35), Pair(-61, -41)
    },
    {
      Pair(81, 11), Pair(31, 33)
    }
  }},
  {{ // Bucket 1
    {
      Pair(-3, 26), Pair(-1, 30)
    },
    {
      Pair(-61, -44), Pair(-65, -46)
    },
    {
      Pair(-66, -73), Pair(-74, -90)
    },
    {
      Pair(-137, 48), Pair(-93, -16)
    },
    {
      Pair(-32, -92), Pair(-87, 96)
    },
    {
      Pair(-107, 53), Pair(-3, 69)
    }
  }},
  {{ // Bucket 2
    {
      Pair(-3, 21), Pair(-6, 33)
    },
    {
      Pair(-71, -40), Pair(-70, -48)
    },
    {
      Pair(-68, -64), Pair(-62, -98)
    },
    {
      Pair(-122, 16), Pair(-76, -40)
    },
    {
      Pair(-80, 57), Pair(-73, -14)
    },
    {
      Pair(1, 2), Pair(-33, -21)
    }
  }},
  {{ // Bucket 3
    {
      Pair(8, 7), Pair(0, 30)
    },
    {
      Pair(-99, -21), Pair(-57, -66)
    },
    {
      Pair(-101, -69), Pair(-67, -84)
    },
    {
      Pair(-113, 26), Pair(-52, -44)
    },
    {
      Pair(-77, 74), Pair(-95, 97)
    },
    {
      Pair(-161, 26), Pair(-152, 35)
    }
  }},
  {{ // Bucket 4
    {
      Pair(-11, 7), Pair(10, 31)
    },
    {
      Pair(-186, -16), Pair(202, -111)
    },
    {
      Pair(-12, -63), Pair(-75, -62)
    },
    {
      Pair(-85, -6), Pair(-162, -36)
    },
    {
      Pair(76, 4), Pair(55, 91)
    },
    {
      Pair(-109, 43), Pair(-80, 0)
    }
  }},
  {{ // Bucket 5
    {
      Pair(42, 19), Pair(-32, 42)
    },
    {
      Pair(146, -68), Pair(-171, -19)
    },
    {
      Pair(17, -45), Pair(-302, -8)
    },
    {
      Pair(-47, 5), Pair(67, -59)
    },
    {
      Pair(17, -19), Pair(-10, -32)
    },
    {
      Pair(-88, 42), Pair(-102, 42)
    }
  }},
  {{ // Bucket 6
    {
      Pair(32, 32), Pair(-224, 87)
    },
    {
      Pair(21, -11), Pair(-38, -11)
    },
    {
      Pair(11, 43), Pair(40, 24)
    },
    {
      Pair(-40, -49), Pair(-8, -190)
    },
    {
      Pair(30, 60), Pair(12, 25)
    },
    {
      Pair(-25, -120), Pair(29, 26)
    }
  }}
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {{
  {
      Pair(0, 0), Pair(20, 42), Pair(20, 37), Pair(31, 27), Pair(22, 13), Pair(109, -101)
  },
  {
      Pair(0, 0), Pair(20, 37), Pair(27, 35), Pair(40, 15), Pair(24, 22), Pair(93, -66)
  },
  {
      Pair(0, 0), Pair(30, 39), Pair(29, 31), Pair(37, 19), Pair(31, -6), Pair(71, -25)
  },
  {
      Pair(0, 0), Pair(46, 38), Pair(15, 36), Pair(56, 9), Pair(56, -28), Pair(15, 11)
  },
  {
      Pair(0, 0), Pair(67, 30), Pair(129, -11), Pair(82, 5), Pair(4, 29), Pair(-22, 26)
  },
  {
      Pair(0, 0), Pair(49, 40), Pair(55, 4), Pair(7, 35), Pair(65, -1), Pair(39, 17)
  },
  {
      Pair(0, 0), Pair(-47, 39), Pair(-13, 1), Pair(-155, 81), Pair(43, 39), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {{ // Bucket 0
    {
      Pair(-5, -17), Pair(8, -10)
    },
    {
      Pair(-27, -41), Pair(-11, -47)
    },
    {
      Pair(-37, -43), Pair(-25, -56)
    },
    {
      Pair(-76, -7), Pair(-55, -35)
    },
    {
      Pair(-42, -36), Pair(-45, -19)
    },
    {
      Pair(-115, 3), Pair(-55, -77)
    }
  }},
  {{ // Bucket 1
    {
      Pair(1, -22), Pair(10, -11)
    },
    {
      Pair(-15, -46), Pair(-14, -46)
    },
    {
      Pair(-30, -45), Pair(-29, -57)
    },
    {
      Pair(-81, -18), Pair(-52, -36)
    },
    {
      Pair(-41, 23), Pair(-52, 57)
    },
    {
      Pair(-149, -5), Pair(-87, -13)
    }
  }},
  {{ // Bucket 2
    {
      Pair(7, -29), Pair(9, -10)
    },
    {
      Pair(-26, -48), Pair(1, -55)
    },
    {
      Pair(-29, -41), Pair(-28, -44)
    },
    {
      Pair(-79, -6), Pair(-48, -42)
    },
    {
      Pair(-56, 32), Pair(-35, -28)
    },
    {
      Pair(-162, 11), Pair(-126, -26)
    }
  }},
  {{ // Bucket 3
    {
      Pair(26, -35), Pair(12, -11)
    },
    {
      Pair(-14, -36), Pair(-7, -46)
    },
    {
      Pair(-80, -25), Pair(-24, -48)
    },
    {
      Pair(-63, -16), Pair(-57, -33)
    },
    {
      Pair(-84, 73), Pair(-60, 85)
    },
    {
      Pair(-164, 8), Pair(-183, -8)
    }
  }},
  {{ // Bucket 4
    {
      Pair(62, -42), Pair(16, -20)
    },
    {
      Pair(-59, -61), Pair(102, -64)
    },
    {
      Pair(-73, -19), Pair(-97, -28)
    },
    {
      Pair(-71, -4), Pair(103, -91)
    },
    {
      Pair(61, 186), Pair(192, 68)
    },
    {
      Pair(-180, 0), Pair(-51, -16)
    }
  }},
  {{ // Bucket 5
    {
      Pair(53, -37), Pair(43, -30)
    },
    {
      Pair(68, -67), Pair(105, -61)
    },
    {
      Pair(54, -37), Pair(-149, -11)
    },
    {
      Pair(41, -31), Pair(95, -46)
    },
    {
      Pair(106, -17), Pair(166, 114)
    },
    {
      Pair(-238, 37), Pair(-11, -42)
    }
  }},
  {{ // Bucket 6
    {
      Pair(28, -24), Pair(82, -29)
    },
    {
      Pair(-46, -133), Pair(-38, -122)
    },
    {
      Pair(33, -43), Pair(6, -70)
    },
    {
      Pair(-21, 7), Pair(76, 10)
    },
    {
      Pair(66, 93), Pair(7, -12)
    },
    {
      Pair(-112, 41), Pair(-4, -18)
    }
  }}
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {{ // Bucket 0
    {
      Pair(-16, -14), Pair(1, -6)
    },
    {
      Pair(-50, -39), Pair(-27, -51)
    },
    {
      Pair(2, -86), Pair(8, -109)
    },
    {
      Pair(-77, -5), Pair(-50, -33)
    },
    {
      Pair(-70, -31), Pair(-48, -74)
    },
    {
      Pair(-38, -41), Pair(-56, -44)
    }
  }},
  {{ // Bucket 1
    {
      Pair(-13, -13), Pair(-1, -2)
    },
    {
      Pair(-56, -23), Pair(-28, -32)
    },
    {
      Pair(9, -119), Pair(3, -93)
    },
    {
      Pair(-76, -9), Pair(-48, -30)
    },
    {
      Pair(-75, -9), Pair(-45, -84)
    },
    {
      Pair(1, -17), Pair(-39, -57)
    }
  }},
  {{ // Bucket 2
    {
      Pair(-10, -22), Pair(-3, -5)
    },
    {
      Pair(-49, -27), Pair(-29, -37)
    },
    {
      Pair(-4, -103), Pair(13, -108)
    },
    {
      Pair(-64, -15), Pair(-42, -45)
    },
    {
      Pair(-83, -1), Pair(-88, -41)
    },
    {
      Pair(-138, 8), Pair(-56, -49)
    }
  }},
  {{ // Bucket 3
    {
      Pair(24, -34), Pair(-1, -10)
    },
    {
      Pair(-64, -25), Pair(-13, -46)
    },
    {
      Pair(85, -129), Pair(-4, -108)
    },
    {
      Pair(-69, -6), Pair(-17, -48)
    },
    {
      Pair(-128, 54), Pair(-58, -18)
    },
    {
      Pair(12, -31), Pair(-64, -51)
    }
  }},
  {{ // Bucket 4
    {
      Pair(59, -39), Pair(29, -30)
    },
    {
      Pair(-98, -19), Pair(28, -65)
    },
    {
      Pair(84, -132), Pair(43, -138)
    },
    {
      Pair(106, -41), Pair(-57, 1)
    },
    {
      Pair(-282, 226), Pair(-44, -22)
    },
    {
      Pair(-90, -11), Pair(108, -28)
    }
  }},
  {{ // Bucket 5
    {
      Pair(115, -62), Pair(83, -46)
    },
    {
      Pair(51, -67), Pair(69, -81)
    },
    {
      Pair(195, -151), Pair(63, -133)
    },
    {
      Pair(167, -69), Pair(-19, -2)
    },
    {
      Pair(138, 32), Pair(-22, 11)
    },
    {
      Pair(-222, 33), Pair(2, -77)
    }
  }},
  {{ // Bucket 6
    {
      Pair(79, -70), Pair(37, -40)
    },
    {
      Pair(-97, -33), Pair(98, -90)
    },
    {
      Pair(-68, -62), Pair(-38, -72)
    },
    {
      Pair(66, -32), Pair(-64, -82)
    },
    {
      Pair(105, 200), Pair(0, 0)
    },
    {
      Pair(-37, -39), Pair(11, 88)
    }
  }}
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {{ // Bucket 0
    {
      Pair(-2, -24), Pair(12, -3)
    },
    {
      Pair(-40, -35), Pair(-3, -18)
    },
    {
      Pair(-27, -33), Pair(-8, -12)
    },
    {
      Pair(10, -51), Pair(17, -41)
    },
    {
      Pair(-65, -21), Pair(-43, -58)
    },
    {
      Pair(-46, -21), Pair(-65, -24)
    }
  }},
  {{ // Bucket 1
    {
      Pair(9, -30), Pair(20, -13)
    },
    {
      Pair(-44, -29), Pair(3, -21)
    },
    {
      Pair(-15, -28), Pair(-11, -2)
    },
    {
      Pair(41, -69), Pair(12, -47)
    },
    {
      Pair(-86, 1), Pair(-52, -74)
    },
    {
      Pair(-102, 13), Pair(-6, -41)
    }
  }},
  {{ // Bucket 2
    {
      Pair(7, -29), Pair(15, -10)
    },
    {
      Pair(-27, -29), Pair(5, -17)
    },
    {
      Pair(-21, -29), Pair(-9, -10)
    },
    {
      Pair(10, -55), Pair(24, -48)
    },
    {
      Pair(-89, 22), Pair(-63, -20)
    },
    {
      Pair(-105, 10), Pair(-122, -12)
    }
  }},
  {{ // Bucket 3
    {
      Pair(33, -37), Pair(22, -18)
    },
    {
      Pair(-24, -26), Pair(15, -23)
    },
    {
      Pair(-8, -38), Pair(15, -19)
    },
    {
      Pair(44, -65), Pair(18, -41)
    },
    {
      Pair(-94, 75), Pair(-50, -41)
    },
    {
      Pair(-134, 4), Pair(-164, -11)
    }
  }},
  {{ // Bucket 4
    {
      Pair(40, -34), Pair(53, -26)
    },
    {
      Pair(10, -36), Pair(42, -29)
    },
    {
      Pair(-35, -32), Pair(24, -23)
    },
    {
      Pair(43, -65), Pair(-52, -24)
    },
    {
      Pair(55, -39), Pair(-148, -64)
    },
    {
      Pair(-201, 32), Pair(-149, -11)
    }
  }},
  {{ // Bucket 5
    {
      Pair(3, -22), Pair(18, -18)
    },
    {
      Pair(50, -60), Pair(46, -57)
    },
    {
      Pair(99, -75), Pair(77, -45)
    },
    {
      Pair(177, -100), Pair(-80, -21)
    },
    {
      Pair(-7, 37), Pair(-160, -51)
    },
    {
      Pair(-410, 71), Pair(-311, 34)
    }
  }},
  {{ // Bucket 6
    {
      Pair(60, -16), Pair(34, -15)
    },
    {
      Pair(-217, -3), Pair(167, -73)
    },
    {
      Pair(-46, -53), Pair(170, -63)
    },
    {
      Pair(162, -106), Pair(-3, -49)
    },
    {
      Pair(193, -120), Pair(61, -29)
    },
    {
      Pair(-387, 64), Pair(-299, -18)
    }
  }}
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {{
  {
      Pair(38, 28), Pair(22, 45), Pair(39, 47), Pair(47, 46), Pair(32, 78), Pair(44, 62), Pair(33, 67), Pair(56, 43),
      Pair(23, 9), Pair(17, 26), Pair(25, 27), Pair(-1, 82), Pair(6, 41), Pair(4, 42), Pair(11, 28), Pair(3, 23),
      Pair(7, 13), Pair(7, 18), Pair(2, 31), Pair(13, 32), Pair(1, 38), Pair(-9, 34), Pair(1, 4), Pair(0, 9)
  },
  {
      Pair(-6, 81), Pair(21, 31), Pair(57, 37), Pair(45, 30), Pair(42, 53), Pair(88, 68), Pair(28, 61), Pair(-33, 88),
      Pair(34, 10), Pair(14, 27), Pair(22, 37), Pair(7, 51), Pair(26, 28), Pair(39, 19), Pair(19, 28), Pair(17, 43),
      Pair(19, 17), Pair(25, 27), Pair(9, 27), Pair(13, 15), Pair(10, 12), Pair(-8, 23), Pair(-6, 37), Pair(1, 31)
  },
  {
      Pair(52, 1), Pair(30, 25), Pair(50, 25), Pair(37, 29), Pair(11, 59), Pair(9, 49), Pair(17, 69), Pair(40, 27),
      Pair(-22, 37), Pair(21, 19), Pair(22, 31), Pair(29, 38), Pair(7, 37), Pair(-1, 31), Pair(9, 24), Pair(-7, 29),
      Pair(9, 19), Pair(32, 2), Pair(21, 12), Pair(13, 27), Pair(17, 13), Pair(-5, 29), Pair(-23, 14), Pair(5, 3)
  },
  {
      Pair(28, 22), Pair(12, 52), Pair(54, 28), Pair(41, 32), Pair(45, 41), Pair(77, 38), Pair(-8, 43), Pair(136, -29),
      Pair(30, 14), Pair(15, 23), Pair(36, 28), Pair(78, 23), Pair(44, 32), Pair(27, 25), Pair(-23, 46), Pair(147, -3),
      Pair(88, -10), Pair(-43, 26), Pair(38, 14), Pair(44, 9), Pair(27, 13), Pair(10, 16), Pair(-36, 31), Pair(-3, 8)
  },
  {
      Pair(-105, 12), Pair(-62, 46), Pair(66, 4), Pair(28, 27), Pair(28, 31), Pair(-44, 64), Pair(51, 30), Pair(50, -17),
      Pair(-72, 38), Pair(-32, 46), Pair(82, 22), Pair(4, 32), Pair(-1, 34), Pair(-28, 54), Pair(18, 18), Pair(-120, 53),
      Pair(54, 29), Pair(53, 20), Pair(18, 19), Pair(42, 21), Pair(84, 21), Pair(11, 4), Pair(52, 16), Pair(38, 7)
  },
  {
      Pair(134, -4), Pair(68, 22), Pair(125, 0), Pair(138, 19), Pair(-166, 20), Pair(-35, 28), Pair(-43, 19), Pair(5, 12),
      Pair(157, -13), Pair(3, 41), Pair(7, 34), Pair(-93, 45), Pair(-14, 34), Pair(-6, 33), Pair(-31, 51), Pair(-33, 42),
      Pair(-58, 45), Pair(-44, 13), Pair(154, -7), Pair(-18, 46), Pair(162, 22), Pair(-8, 46), Pair(-11, 26), Pair(14, 30)
  },
  {
      Pair(17, 105), Pair(-1, 46), Pair(-15, 4), Pair(72, 59), Pair(-9, 11), Pair(47, 92), Pair(29, 130), Pair(34, 41),
      Pair(-46, 49), Pair(-104, 22), Pair(107, 116), Pair(9, 63), Pair(-30, -8), Pair(43, 19), Pair(82, 4), Pair(44, 118),
      Pair(30, -27), Pair(2, 26), Pair(148, 63), Pair(57, 44), Pair(87, 76), Pair(-56, 72), Pair(-30, 62), Pair(28, 43)
  }
}};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {{
  {
      Pair(-14, 55), Pair(14, 32), Pair(31, 4), Pair(43, 24), Pair(63, 20), Pair(83, -19), Pair(13, 40), Pair(13, 26),
      Pair(-29, -20), Pair(24, 22), Pair(30, 2), Pair(34, 26), Pair(12, 32), Pair(10, 21), Pair(14, 28), Pair(5, -7),
      Pair(-31, 10), Pair(9, 23), Pair(5, 32), Pair(19, 21), Pair(19, 35), Pair(-3, 14), Pair(2, 7), Pair(-29, -29)
  },
  {
      Pair(44, 10), Pair(65, 6), Pair(32, 10), Pair(62, 10), Pair(41, 25), Pair(76, 9), Pair(31, 53), Pair(-93, 18),
      Pair(35, -30), Pair(17, 27), Pair(-2, 6), Pair(36, 5), Pair(18, 27), Pair(43, -8), Pair(13, 20), Pair(-39, 1),
      Pair(-10, 37), Pair(-17, 18), Pair(9, 30), Pair(15, 5), Pair(17, 21), Pair(3, 7), Pair(17, -3), Pair(-102, 0)
  },
  {
      Pair(-125, 79), Pair(34, 13), Pair(61, -1), Pair(60, -2), Pair(41, 8), Pair(56, 17), Pair(17, 17), Pair(11, -45),
      Pair(3, -18), Pair(42, 0), Pair(18, 6), Pair(36, 18), Pair(35, 6), Pair(28, 5), Pair(6, 20), Pair(32, -17),
      Pair(-10, 33), Pair(29, 8), Pair(1, 15), Pair(24, 13), Pair(44, 10), Pair(5, 1), Pair(17, 0), Pair(-42, 9)
  },
  {
      Pair(90, 3), Pair(51, -10), Pair(17, -2), Pair(132, -23), Pair(90, -24), Pair(36, 18), Pair(-11, 34), Pair(67, -19),
      Pair(-106, 34), Pair(84, 3), Pair(58, -16), Pair(85, -15), Pair(42, -11), Pair(78, -12), Pair(53, 3), Pair(77, -6),
      Pair(-78, 46), Pair(107, -17), Pair(38, 8), Pair(45, 11), Pair(76, 10), Pair(1, 15), Pair(20, 5), Pair(-139, 17)
  },
  {
      Pair(-62, 39), Pair(66, -15), Pair(164, -35), Pair(168, -15), Pair(69, -26), Pair(46, -3), Pair(93, 3), Pair(-135, 37),
      Pair(17, -31), Pair(-48, 26), Pair(39, -2), Pair(82, -5), Pair(52, 0), Pair(123, -6), Pair(76, 16), Pair(-92, 45),
      Pair(-267, 72), Pair(74, -13), Pair(0, 10), Pair(166, -28), Pair(99, -11), Pair(21, 14), Pair(18, 20), Pair(-132, 29)
  },
  {
      Pair(17, 41), Pair(105, -27), Pair(88, -2), Pair(136, -29), Pair(65, -41), Pair(63, -8), Pair(128, -18), Pair(-2, -54),
      Pair(-91, 43), Pair(63, 7), Pair(178, -13), Pair(143, -10), Pair(61, 6), Pair(-14, 0), Pair(36, 22), Pair(-106, 21),
      Pair(-116, 51), Pair(-44, 18), Pair(216, -24), Pair(126, -6), Pair(33, 29), Pair(-68, 26), Pair(64, 32), Pair(-79, 5)
  },
  {
      Pair(17, 65), Pair(78, 8), Pair(109, -85), Pair(70, -18), Pair(46, -15), Pair(144, -34), Pair(115, -30), Pair(19, -66),
      Pair(-16, 14), Pair(111, 52), Pair(180, -8), Pair(-61, -5), Pair(69, 15), Pair(-179, 28), Pair(-20, 69), Pair(51, -82),
      Pair(38, 155), Pair(-83, 64), Pair(50, 24), Pair(128, 12), Pair(-37, 84), Pair(-135, 23), Pair(121, 60), Pair(39, 104)
  }
}};

constexpr KingBuckets<ScorePair> kBishopPairBonus = {{
  {
      Pair(26, 81)
  },
  {
      Pair(29, 70)
  },
  {
      Pair(32, 74)
  },
  {
      Pair(24, 73)
  },
  {
      Pair(40, 68)
  },
  {
      Pair(-76, 113)
  },
  {
      Pair(-38, 121)
  }
}};


constexpr ScorePair kTempoBonus = Pair(24, 25);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H