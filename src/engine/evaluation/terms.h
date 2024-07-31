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
using PieceTable = std::array<T, kNumPieceTypes>;

template <typename T>
using PieceSquareTable = KingBuckets<PieceTable<std::array<T, kSquareCount>>>;

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
  Pair(172, 313), Pair(619, 320), Pair(791, 743), Pair(986, 1435), Pair(1841, 2243), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {{ // Bucket 0
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(49, 213), Pair(3, 282), Pair(-11, 295), Pair(123, 135), Pair(126, 104), Pair(161, 49), Pair(-1, -116), Pair(-169, -3),
      Pair(27, 171), Pair(-21, 234), Pair(54, 123), Pair(69, 32), Pair(111, 40), Pair(236, -43), Pair(89, 70), Pair(48, 70),
      Pair(-15, 51), Pair(-17, 81), Pair(0, -4), Pair(3, -52), Pair(64, -78), Pair(69, -79), Pair(-10, 26), Pair(13, -40),
      Pair(-17, 1), Pair(-38, 72), Pair(-1, -31), Pair(25, -63), Pair(35, -71), Pair(55, -77), Pair(-11, 3), Pair(7, -68),
      Pair(-43, -15), Pair(-60, 50), Pair(-32, -23), Pair(-18, -30), Pair(-3, -27), Pair(-3, -49), Pair(-15, -12), Pair(0, -86),
      Pair(-20, -5), Pair(-33, 63), Pair(-14, 1), Pair(-22, -23), Pair(2, 7), Pair(47, -26), Pair(16, 15), Pair(0, -85),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-437, 154), Pair(-412, 169), Pair(-213, 182), Pair(-132, 107), Pair(-109, 127), Pair(-61, -85), Pair(-255, 11), Pair(-220, -203),
      Pair(-109, 151), Pair(-50, 169), Pair(-18, 137), Pair(-32, 178), Pair(-35, 152), Pair(177, 58), Pair(40, 150), Pair(60, 9),
      Pair(-26, 132), Pair(4, 175), Pair(-7, 205), Pair(24, 158), Pair(62, 132), Pair(183, 102), Pair(-2, 151), Pair(99, 99),
      Pair(0, 168), Pair(47, 152), Pair(83, 167), Pair(98, 180), Pair(83, 174), Pair(116, 160), Pair(54, 167), Pair(81, 139),
      Pair(-19, 140), Pair(36, 135), Pair(66, 172), Pair(75, 170), Pair(79, 181), Pair(106, 121), Pair(79, 144), Pair(19, 127),
      Pair(-57, 104), Pair(-2, 128), Pair(29, 136), Pair(47, 176), Pair(76, 165), Pair(51, 123), Pair(47, 122), Pair(4, 116),
      Pair(-77, 106), Pair(-47, 125), Pair(-15, 127), Pair(22, 115), Pair(26, 119), Pair(16, 93), Pair(7, 110), Pair(2, 129),
      Pair(-154, 153), Pair(-46, 74), Pair(-49, 122), Pair(-28, 150), Pair(6, 140), Pair(12, 100), Pair(-62, 114), Pair(-43, 55)
    },
    {
      Pair(-122, 126), Pair(-153, 76), Pair(-197, 71), Pair(-255, 126), Pair(-246, 36), Pair(-152, -29), Pair(-179, 132), Pair(-204, 153),
      Pair(-85, 83), Pair(-63, 85), Pair(-41, 37), Pair(-110, 75), Pair(-81, 19), Pair(-49, 33), Pair(-156, 135), Pair(-85, 62),
      Pair(-29, 82), Pair(-37, 83), Pair(-37, 75), Pair(-60, 55), Pair(-87, 88), Pair(61, 93), Pair(49, 84), Pair(6, 103),
      Pair(-65, 86), Pair(-20, 82), Pair(-22, 70), Pair(-6, 120), Pair(-13, 59), Pair(4, 60), Pair(-28, 67), Pair(-42, 74),
      Pair(-33, 33), Pair(-75, 84), Pair(-20, 80), Pair(-6, 40), Pair(-5, 38), Pair(-21, 43), Pair(-41, 69), Pair(-9, -2),
      Pair(-49, 19), Pair(11, 92), Pair(-1, 68), Pair(-6, 71), Pair(-4, 101), Pair(11, 70), Pair(17, 42), Pair(9, 22),
      Pair(-2, 37), Pair(2, -14), Pair(18, 7), Pair(-22, 47), Pair(14, 46), Pair(24, 40), Pair(55, 34), Pair(39, -37),
      Pair(-15, -5), Pair(38, 17), Pair(-18, 37), Pair(-26, 58), Pair(8, 48), Pair(-22, 78), Pair(20, 39), Pair(67, -78)
    },
    {
      Pair(-30, 308), Pair(101, 270), Pair(-55, 384), Pair(55, 220), Pair(147, 148), Pair(73, 296), Pair(-88, 260), Pair(-65, 118),
      Pair(-30, 133), Pair(-18, 158), Pair(9, 171), Pair(53, 122), Pair(18, 114), Pair(121, 105), Pair(132, 116), Pair(33, 102),
      Pair(-23, 104), Pair(55, 120), Pair(27, 134), Pair(29, 118), Pair(115, 48), Pair(163, 20), Pair(229, 36), Pair(83, 12),
      Pair(5, 93), Pair(50, 109), Pair(62, 106), Pair(43, 106), Pair(70, 71), Pair(83, 52), Pair(109, 46), Pair(55, 8),
      Pair(-23, 87), Pair(-5, 115), Pair(-1, 94), Pair(12, 107), Pair(13, 75), Pair(-27, 86), Pair(65, 39), Pair(-1, 0),
      Pair(-35, 76), Pair(-19, 68), Pair(-16, 90), Pair(-17, 95), Pair(12, 64), Pair(15, 35), Pair(94, -24), Pair(24, -51),
      Pair(-46, 53), Pair(-34, 95), Pair(11, 71), Pair(2, 91), Pair(30, 45), Pair(18, 46), Pair(76, -19), Pair(-40, 1),
      Pair(-8, 60), Pair(-3, 56), Pair(5, 71), Pair(19, 62), Pair(32, 35), Pair(28, 41), Pair(16, 20), Pair(-22, 9)
    },
    {
      Pair(-418, 625), Pair(-88, 282), Pair(-108, 334), Pair(-36, 316), Pair(35, 139), Pair(54, 121), Pair(20, 237), Pair(-305, 511),
      Pair(-149, 233), Pair(-119, 238), Pair(-135, 352), Pair(-151, 368), Pair(-200, 447), Pair(-79, 394), Pair(-188, 360), Pair(-154, 431),
      Pair(-78, 204), Pair(-81, 233), Pair(-86, 293), Pair(-90, 321), Pair(-87, 323), Pair(-4, 327), Pair(-12, 286), Pair(0, 208),
      Pair(-95, 232), Pair(-64, 254), Pair(-67, 267), Pair(-72, 320), Pair(-70, 303), Pair(-13, 217), Pair(-18, 270), Pair(-6, 188),
      Pair(-80, 190), Pair(-94, 275), Pair(-73, 249), Pair(-70, 308), Pair(-58, 271), Pair(-68, 260), Pair(-17, 208), Pair(-34, 207),
      Pair(-76, 167), Pair(-61, 207), Pair(-67, 239), Pair(-78, 251), Pair(-75, 277), Pair(-45, 224), Pair(-4, 176), Pair(-18, 125),
      Pair(-66, 159), Pair(-55, 129), Pair(-47, 141), Pair(-41, 177), Pair(-42, 177), Pair(-26, 97), Pair(13, 11), Pair(36, -51),
      Pair(-92, 157), Pair(-77, 138), Pair(-61, 137), Pair(-54, 140), Pair(-52, 132), Pair(-68, 91), Pair(-58, 68), Pair(-21, 28)
    },
    {
      Pair(720, -436), Pair(569, -295), Pair(483, -236), Pair(342, -180), Pair(439, -217), Pair(217, -153), Pair(403, -212), Pair(783, -481),
      Pair(343, -234), Pair(530, -165), Pair(397, -132), Pair(560, -167), Pair(445, -137), Pair(307, -77), Pair(396, -111), Pair(229, -172),
      Pair(514, -76), Pair(813, -39), Pair(590, 13), Pair(510, 29), Pair(526, 38), Pair(670, 17), Pair(535, 21), Pair(536, -85),
      Pair(659, -140), Pair(714, -73), Pair(560, -17), Pair(442, 17), Pair(403, 7), Pair(504, -6), Pair(527, -56), Pair(426, -103),
      Pair(529, -108), Pair(614, -42), Pair(429, 34), Pair(325, 71), Pair(302, 64), Pair(391, 16), Pair(455, -35), Pair(303, -69),
      Pair(326, -81), Pair(426, -30), Pair(266, 38), Pair(207, 74), Pair(205, 67), Pair(222, 34), Pair(335, -29), Pair(272, -73),
      Pair(158, -82), Pair(88, 10), Pair(60, 41), Pair(9, 64), Pair(-9, 71), Pair(24, 47), Pair(77, -3), Pair(115, -77),
      Pair(2, -72), Pair(61, 4), Pair(17, 15), Pair(-123, 54), Pair(-45, 19), Pair(-89, 41), Pair(7, 12), Pair(15, -88)
    }
  }},
  {{ // Bucket 1
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(330, 308), Pair(20, 283), Pair(53, 65), Pair(142, -33), Pair(111, -61), Pair(-22, 73), Pair(-162, 515), Pair(134, 387),
      Pair(16, 153), Pair(8, 138), Pair(120, -13), Pair(123, -67), Pair(154, -124), Pair(136, -20), Pair(98, 83), Pair(67, 89),
      Pair(-52, 58), Pair(-17, 52), Pair(6, -19), Pair(22, -50), Pair(62, -61), Pair(23, -41), Pair(27, 9), Pair(45, -8),
      Pair(-82, 20), Pair(-53, 46), Pair(-18, -43), Pair(30, -44), Pair(38, -51), Pair(24, -54), Pair(-12, 6), Pair(23, -55),
      Pair(-117, 1), Pair(-80, 35), Pair(-58, -36), Pair(-40, -13), Pair(-18, -36), Pair(-37, -43), Pair(-12, -22), Pair(-11, -66),
      Pair(-86, 12), Pair(-51, 41), Pair(-37, -7), Pair(-35, -1), Pair(-12, 8), Pair(6, -26), Pair(30, -21), Pair(-6, -57),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-267, -130), Pair(-42, 97), Pair(-165, 173), Pair(-79, 26), Pair(353, -31), Pair(-55, 24), Pair(-376, 83), Pair(-261, -53),
      Pair(8, 101), Pair(-31, 185), Pair(5, 185), Pair(134, -31), Pair(112, 8), Pair(53, 125), Pair(-14, 182), Pair(-41, 75),
      Pair(-2, 136), Pair(55, 149), Pair(20, 184), Pair(129, 136), Pair(25, 145), Pair(48, 126), Pair(-4, 119), Pair(69, 26),
      Pair(76, 167), Pair(19, 188), Pair(64, 188), Pair(70, 208), Pair(89, 188), Pair(94, 221), Pair(84, 180), Pair(82, 122),
      Pair(-10, 177), Pair(39, 169), Pair(63, 196), Pair(97, 175), Pair(67, 207), Pair(113, 141), Pair(57, 156), Pair(16, 168),
      Pair(-55, 127), Pair(9, 143), Pair(23, 151), Pair(56, 155), Pair(84, 171), Pair(39, 143), Pair(44, 142), Pair(-17, 130),
      Pair(-75, 128), Pair(-9, 149), Pair(-12, 113), Pair(18, 147), Pair(17, 133), Pair(13, 175), Pair(7, 40), Pair(-23, 167),
      Pair(-185, 214), Pair(-77, 192), Pair(-45, 144), Pair(-5, 166), Pair(-12, 121), Pair(11, 100), Pair(-65, 173), Pair(-100, 148)
    },
    {
      Pair(0, 57), Pair(-189, 79), Pair(-199, 11), Pair(-435, 117), Pair(-217, 67), Pair(-258, 49), Pair(-85, 17), Pair(-130, 18),
      Pair(-9, -22), Pair(0, 40), Pair(-18, 11), Pair(-55, 57), Pair(-53, 69), Pair(-47, 26), Pair(-124, 87), Pair(-132, 24),
      Pair(-11, 91), Pair(55, 2), Pair(-1, 35), Pair(95, 30), Pair(80, 10), Pair(-5, 115), Pair(25, 66), Pair(-21, 85),
      Pair(-34, 59), Pair(0, 63), Pair(19, 62), Pair(18, 51), Pair(33, 46), Pair(40, 57), Pair(-18, 64), Pair(-43, 76),
      Pair(-27, 41), Pair(-68, 54), Pair(-20, 39), Pair(36, 45), Pair(27, 27), Pair(-5, 53), Pair(-29, 55), Pair(-24, 73),
      Pair(-38, 62), Pair(28, 40), Pair(18, 49), Pair(-3, 77), Pair(18, 67), Pair(24, 43), Pair(43, 59), Pair(17, 3),
      Pair(18, 15), Pair(19, 29), Pair(53, -4), Pair(-6, 53), Pair(6, 43), Pair(34, 58), Pair(73, 21), Pair(19, 89),
      Pair(33, -20), Pair(45, -7), Pair(-26, 83), Pair(11, 42), Pair(27, 20), Pair(-56, 100), Pair(15, -68), Pair(32, -22)
    },
    {
      Pair(181, 150), Pair(228, 178), Pair(214, 151), Pair(251, 137), Pair(103, 50), Pair(-96, 162), Pair(118, 172), Pair(-44, 261),
      Pair(115, 121), Pair(115, 137), Pair(87, 127), Pair(174, 85), Pair(81, 99), Pair(-53, 186), Pair(3, 164), Pair(-19, 174),
      Pair(55, 142), Pair(126, 98), Pair(82, 118), Pair(80, 65), Pair(60, 53), Pair(70, 73), Pair(131, 85), Pair(-22, 105),
      Pair(41, 109), Pair(47, 110), Pair(42, 101), Pair(9, 100), Pair(37, 59), Pair(67, 70), Pair(0, 111), Pair(-38, 137),
      Pair(-29, 88), Pair(-79, 120), Pair(-6, 85), Pair(-32, 127), Pair(18, 75), Pair(-44, 127), Pair(-33, 109), Pair(-68, 107),
      Pair(-84, 92), Pair(-23, 79), Pair(15, 69), Pair(-9, 72), Pair(-1, 64), Pair(-25, 101), Pair(19, 51), Pair(-58, 104),
      Pair(-38, 29), Pair(-19, 63), Pair(-7, 72), Pair(-45, 75), Pair(2, 47), Pair(-20, 82), Pair(2, 55), Pair(-78, 69),
      Pair(-48, 77), Pair(-10, 62), Pair(2, 73), Pair(2, 46), Pair(39, 25), Pair(-5, 75), Pair(-35, 74), Pair(-46, 51)
    },
    {
      Pair(191, 98), Pair(162, 112), Pair(193, 63), Pair(257, 24), Pair(-308, 527), Pair(56, 296), Pair(52, 295), Pair(37, 271),
      Pair(232, 49), Pair(106, 119), Pair(116, 216), Pair(70, 281), Pair(-229, 540), Pair(18, 224), Pair(82, 156), Pair(177, 165),
      Pair(159, 82), Pair(156, 87), Pair(151, 151), Pair(114, 261), Pair(70, 296), Pair(82, 256), Pair(162, 118), Pair(108, 172),
      Pair(130, 139), Pair(101, 205), Pair(133, 227), Pair(15, 332), Pair(84, 260), Pair(92, 278), Pair(106, 235), Pair(145, 160),
      Pair(87, 142), Pair(30, 320), Pair(70, 249), Pair(69, 231), Pair(88, 271), Pair(78, 209), Pair(85, 202), Pair(97, 209),
      Pair(94, 120), Pair(92, 160), Pair(73, 221), Pair(57, 223), Pair(91, 209), Pair(88, 182), Pair(113, 166), Pair(92, 133),
      Pair(70, -25), Pair(103, 24), Pair(97, 99), Pair(90, 126), Pair(109, 106), Pair(110, 98), Pair(110, 59), Pair(101, 77),
      Pair(64, 117), Pair(33, 182), Pair(64, 133), Pair(65, 79), Pair(105, 0), Pair(43, 140), Pair(122, 51), Pair(59, 158)
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
      Pair(135, 236), Pair(168, 201), Pair(103, 200), Pair(142, 104), Pair(78, 123), Pair(134, 101), Pair(-52, 285), Pair(213, 222),
      Pair(-7, 55), Pair(-17, 112), Pair(57, -17), Pair(76, -84), Pair(91, -105), Pair(194, -95), Pair(82, 19), Pair(-6, 38),
      Pair(-12, 35), Pair(-25, 60), Pair(-10, -9), Pair(8, -48), Pair(76, -49), Pair(45, -39), Pair(20, 17), Pair(18, -9),
      Pair(-55, 5), Pair(-57, 57), Pair(-14, -23), Pair(7, -41), Pair(12, -37), Pair(14, -46), Pair(3, -3), Pair(8, -39),
      Pair(-66, -11), Pair(-66, 32), Pair(-35, -26), Pair(-30, -19), Pair(17, -38), Pair(-17, -43), Pair(6, -23), Pair(-4, -52),
      Pair(-36, 0), Pair(-37, 49), Pair(-1, -17), Pair(-34, -11), Pair(21, 4), Pair(33, -27), Pair(65, -20), Pair(-5, -41),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-345, -92), Pair(-108, 66), Pair(-171, 71), Pair(33, 23), Pair(13, 41), Pair(-50, -44), Pair(-58, -2), Pair(-277, -147),
      Pair(-47, 49), Pair(-26, 115), Pair(9, 113), Pair(113, 75), Pair(84, 61), Pair(54, 91), Pair(-44, 93), Pair(-87, 61),
      Pair(-48, 141), Pair(33, 131), Pair(89, 121), Pair(151, 90), Pair(159, 91), Pair(243, 10), Pair(161, 54), Pair(31, 42),
      Pair(28, 124), Pair(70, 137), Pair(116, 149), Pair(164, 122), Pair(179, 128), Pair(179, 121), Pair(122, 127), Pair(146, 46),
      Pair(-13, 144), Pair(79, 143), Pair(109, 165), Pair(146, 151), Pair(158, 157), Pair(186, 115), Pair(154, 106), Pair(78, 118),
      Pair(-81, 147), Pair(-11, 138), Pair(44, 156), Pair(89, 165), Pair(137, 153), Pair(85, 113), Pair(70, 98), Pair(27, 115),
      Pair(-100, 130), Pair(-75, 145), Pair(-13, 144), Pair(41, 146), Pair(58, 136), Pair(14, 148), Pair(25, 110), Pair(8, 127),
      Pair(-200, 88), Pair(-62, 118), Pair(-64, 128), Pair(28, 117), Pair(-7, 148), Pair(-7, 120), Pair(-1, 104), Pair(-96, 170)
    },
    {
      Pair(-113, 39), Pair(-124, 50), Pair(-59, 41), Pair(-218, 17), Pair(-136, -14), Pair(-266, 9), Pair(-143, 11), Pair(-206, 26),
      Pair(-127, 7), Pair(-32, 22), Pair(0, 6), Pair(-1, -12), Pair(-32, 7), Pair(-49, 35), Pair(-79, 39), Pair(-19, -35),
      Pair(-37, 40), Pair(29, 10), Pair(-56, 50), Pair(27, -12), Pair(-22, 22), Pair(-40, 30), Pair(-18, 13), Pair(14, -3),
      Pair(-38, 31), Pair(-9, 42), Pair(51, 27), Pair(41, 44), Pair(108, 33), Pair(125, 23), Pair(50, 26), Pair(13, 9),
      Pair(-59, 34), Pair(-12, 38), Pair(-2, 24), Pair(51, 31), Pair(60, 10), Pair(22, 24), Pair(-28, 32), Pair(3, 10),
      Pair(-30, 35), Pair(12, 38), Pair(25, 43), Pair(20, 46), Pair(26, 60), Pair(38, 31), Pair(37, 23), Pair(11, -1),
      Pair(-57, 46), Pair(5, 11), Pair(37, 3), Pair(-3, 39), Pair(9, 41), Pair(43, 21), Pair(56, 8), Pair(24, -15),
      Pair(-82, 38), Pair(40, -10), Pair(-13, 39), Pair(-18, 32), Pair(-19, 44), Pair(-23, 59), Pair(-11, 46), Pair(15, -4)
    },
    {
      Pair(-102, 117), Pair(-95, 133), Pair(-63, 124), Pair(-69, 118), Pair(-11, 74), Pair(90, 71), Pair(-39, 117), Pair(-79, 125),
      Pair(15, 87), Pair(40, 111), Pair(76, 86), Pair(149, 79), Pair(105, 53), Pair(90, 56), Pair(-9, 83), Pair(-24, 88),
      Pair(6, 72), Pair(99, 72), Pair(69, 70), Pair(73, 48), Pair(163, 14), Pair(209, 12), Pair(173, 40), Pair(18, 47),
      Pair(-30, 97), Pair(52, 81), Pair(54, 93), Pair(64, 64), Pair(109, 22), Pair(147, 13), Pair(107, 21), Pair(-44, 55),
      Pair(-52, 57), Pair(-40, 82), Pair(7, 60), Pair(23, 64), Pair(42, 44), Pair(36, 32), Pair(14, 39), Pair(-16, 29),
      Pair(-30, 41), Pair(-27, 66), Pair(-8, 48), Pair(2, 60), Pair(37, 26), Pair(31, 22), Pair(61, -8), Pair(33, -36),
      Pair(-48, 45), Pair(-23, 51), Pair(-19, 59), Pair(19, 40), Pair(1, 31), Pair(26, 12), Pair(-3, 21), Pair(-65, 0),
      Pair(-30, 58), Pair(-21, 52), Pair(-2, 51), Pair(19, 39), Pair(30, 21), Pair(25, 30), Pair(3, 22), Pair(-41, 23)
    },
    {
      Pair(-89, 146), Pair(-175, 200), Pair(-84, 215), Pair(-36, 184), Pair(9, 161), Pair(1, 192), Pair(136, 43), Pair(20, 117),
      Pair(21, 137), Pair(9, 187), Pair(47, 191), Pair(-43, 247), Pair(14, 186), Pair(25, 150), Pair(6, 344), Pair(119, 173),
      Pair(69, 101), Pair(55, 141), Pair(47, 226), Pair(81, 176), Pair(69, 245), Pair(167, 145), Pair(133, 110), Pair(113, 184),
      Pair(30, 105), Pair(90, 124), Pair(102, 138), Pair(83, 155), Pair(106, 210), Pair(119, 179), Pair(157, 126), Pair(110, 156),
      Pair(44, 118), Pair(67, 146), Pair(66, 204), Pair(100, 206), Pair(106, 196), Pair(53, 185), Pair(97, 146), Pair(102, 114),
      Pair(55, 79), Pair(53, 158), Pair(78, 163), Pair(89, 166), Pair(79, 165), Pair(93, 153), Pair(109, 120), Pair(106, 74),
      Pair(69, 74), Pair(69, 122), Pair(81, 116), Pair(82, 135), Pair(95, 123), Pair(112, 58), Pair(123, 32), Pair(69, 25),
      Pair(65, 32), Pair(67, 46), Pair(24, 110), Pair(76, 84), Pair(37, 97), Pair(32, 67), Pair(39, 45), Pair(22, 105)
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
      Pair(157, 166), Pair(469, 33), Pair(137, 177), Pair(88, 134), Pair(87, 118), Pair(43, 125), Pair(291, 228), Pair(72, 249),
      Pair(57, -4), Pair(45, 19), Pair(147, -93), Pair(204, -150), Pair(92, -113), Pair(145, -95), Pair(175, -38), Pair(165, -22),
      Pair(-49, 32), Pair(8, 9), Pair(13, -47), Pair(-1, -61), Pair(94, -69), Pair(104, -81), Pair(56, -2), Pair(43, -19),
      Pair(-83, 9), Pair(-31, 23), Pair(-19, -16), Pair(-11, -8), Pair(-7, -12), Pair(14, -30), Pair(45, 6), Pair(17, -36),
      Pair(-80, -11), Pair(-49, 1), Pair(12, -43), Pair(-28, -24), Pair(38, -39), Pair(43, -54), Pair(36, -33), Pair(-5, -48),
      Pair(-78, 15), Pair(-5, 15), Pair(38, -25), Pair(-52, -5), Pair(35, -19), Pair(89, -44), Pair(89, -23), Pair(-35, -18),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-251, -91), Pair(-450, 45), Pair(-306, 110), Pair(224, 8), Pair(233, 28), Pair(148, 27), Pair(-531, 109), Pair(-88, -129),
      Pair(-129, 135), Pair(121, 78), Pair(161, 43), Pair(305, 35), Pair(357, -22), Pair(210, 5), Pair(-21, 85), Pair(44, 39),
      Pair(-24, 69), Pair(137, 60), Pair(160, 114), Pair(250, 82), Pair(309, 93), Pair(277, 17), Pair(47, 96), Pair(99, 25),
      Pair(127, 126), Pair(162, 94), Pair(228, 114), Pair(302, 88), Pair(349, 71), Pair(273, 103), Pair(437, 14), Pair(189, 85),
      Pair(74, 140), Pair(114, 125), Pair(191, 130), Pair(255, 108), Pair(291, 111), Pair(264, 89), Pair(300, 69), Pair(143, 82),
      Pair(-3, 106), Pair(79, 127), Pair(102, 144), Pair(200, 150), Pair(247, 131), Pair(161, 121), Pair(174, 93), Pair(135, 116),
      Pair(-174, 199), Pair(-72, 161), Pair(83, 126), Pair(121, 121), Pair(75, 135), Pair(122, 135), Pair(89, 102), Pair(-57, 194),
      Pair(-269, 168), Pair(-79, 123), Pair(-115, 166), Pair(-30, 136), Pair(148, 117), Pair(116, 107), Pair(-59, 173), Pair(-180, 146)
    },
    {
      Pair(-79, 43), Pair(135, -8), Pair(-5, 16), Pair(46, -29), Pair(-66, 26), Pair(-21, 30), Pair(46, 3), Pair(-321, 31),
      Pair(-38, 14), Pair(-62, 45), Pair(-9, 19), Pair(258, -49), Pair(12, -21), Pair(-38, 9), Pair(-54, 28), Pair(-17, 41),
      Pair(37, 40), Pair(162, 15), Pair(94, 14), Pair(125, -14), Pair(146, -31), Pair(171, 4), Pair(30, 28), Pair(140, 4),
      Pair(167, -9), Pair(75, 15), Pair(122, 14), Pair(255, -35), Pair(229, -26), Pair(231, -12), Pair(144, -5), Pair(41, 13),
      Pair(13, 37), Pair(134, 20), Pair(98, 17), Pair(287, -8), Pair(148, 9), Pair(143, 35), Pair(94, 32), Pair(124, -5),
      Pair(64, 27), Pair(55, 33), Pair(121, 25), Pair(97, 39), Pair(163, 33), Pair(41, 49), Pair(54, 42), Pair(59, 49),
      Pair(-61, 96), Pair(-1, 35), Pair(82, 30), Pair(49, 39), Pair(16, 56), Pair(93, 18), Pair(115, 2), Pair(-72, 44),
      Pair(45, 39), Pair(22, 45), Pair(16, 41), Pair(-67, 57), Pair(10, 37), Pair(0, 45), Pair(-53, 53), Pair(-61, 33)
    },
    {
      Pair(-65, 124), Pair(-22, 128), Pair(83, 98), Pair(133, 81), Pair(36, 104), Pair(-77, 132), Pair(93, 94), Pair(38, 98),
      Pair(24, 59), Pair(82, 80), Pair(161, 53), Pair(249, 7), Pair(214, 10), Pair(255, 25), Pair(122, 44), Pair(59, 46),
      Pair(99, 61), Pair(131, 86), Pair(148, 63), Pair(198, 19), Pair(151, 27), Pair(151, 31), Pair(9, 123), Pair(-124, 121),
      Pair(39, 89), Pair(123, 69), Pair(179, 63), Pair(205, 56), Pair(196, 19), Pair(276, 3), Pair(213, 39), Pair(23, 61),
      Pair(-77, 97), Pair(-51, 123), Pair(34, 88), Pair(49, 71), Pair(123, 30), Pair(178, 28), Pair(127, 46), Pair(2, 48),
      Pair(-46, 58), Pair(8, 61), Pair(18, 39), Pair(80, 40), Pair(94, 21), Pair(105, 26), Pair(135, -2), Pair(-51, 42),
      Pair(-58, 58), Pair(-5, 68), Pair(41, 42), Pair(-25, 60), Pair(44, 18), Pair(77, 5), Pair(43, 10), Pair(-96, 39),
      Pair(-56, 76), Pair(-72, 93), Pair(7, 64), Pair(39, 42), Pair(35, 32), Pair(38, 48), Pair(-27, 67), Pair(-56, 69)
    },
    {
      Pair(243, 176), Pair(336, 125), Pair(507, 85), Pair(759, -69), Pair(437, 134), Pair(415, 137), Pair(483, 13), Pair(242, 226),
      Pair(350, 58), Pair(231, 127), Pair(162, 239), Pair(166, 259), Pair(377, 249), Pair(258, 253), Pair(385, 60), Pair(435, 102),
      Pair(159, 198), Pair(216, 205), Pair(223, 304), Pair(331, 213), Pair(242, 329), Pair(454, 203), Pair(436, 132), Pair(527, -16),
      Pair(315, 118), Pair(287, 123), Pair(245, 248), Pair(478, 120), Pair(459, 109), Pair(522, 104), Pair(441, 131), Pair(447, 57),
      Pair(234, 167), Pair(263, 175), Pair(291, 139), Pair(351, 161), Pair(394, 86), Pair(346, 164), Pair(434, 57), Pair(446, 53),
      Pair(242, 73), Pair(249, 168), Pair(278, 170), Pair(247, 200), Pair(318, 190), Pair(352, 80), Pair(354, 49), Pair(380, 145),
      Pair(209, 62), Pair(244, 67), Pair(220, 159), Pair(303, 163), Pair(298, 98), Pair(330, 86), Pair(288, 70), Pair(128, 223),
      Pair(139, 161), Pair(140, 145), Pair(206, 244), Pair(191, 228), Pair(78, 194), Pair(188, 208), Pair(103, 14), Pair(219, -8)
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
      Pair(49, 186), Pair(619, 31), Pair(-39, 277), Pair(334, 149), Pair(-28, 245), Pair(84, 252), Pair(-133, 393), Pair(93, 240),
      Pair(-41, -12), Pair(40, -13), Pair(-72, -21), Pair(112, -53), Pair(101, -43), Pair(138, -43), Pair(-27, 62), Pair(290, -33),
      Pair(-61, 5), Pair(32, -5), Pair(50, -49), Pair(21, -47), Pair(166, -78), Pair(159, -85), Pair(178, -14), Pair(146, -40),
      Pair(-38, -20), Pair(59, -14), Pair(14, -55), Pair(69, -48), Pair(107, -59), Pair(75, -68), Pair(196, -31), Pair(88, -46),
      Pair(-81, -26), Pair(-31, -14), Pair(-11, -35), Pair(37, -21), Pair(92, -35), Pair(82, -46), Pair(164, -38), Pair(43, -50),
      Pair(-68, 1), Pair(75, -19), Pair(92, -46), Pair(107, -49), Pair(164, -54), Pair(170, -64), Pair(184, -49), Pair(19, -29),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-178, -160), Pair(-214, 23), Pair(-352, 133), Pair(198, -29), Pair(49, 56), Pair(18, 34), Pair(-127, 180), Pair(-3, -114),
      Pair(-142, 26), Pair(-17, 92), Pair(68, 85), Pair(549, -41), Pair(287, 58), Pair(244, 55), Pair(55, 103), Pair(326, -3),
      Pair(-83, 88), Pair(-79, 101), Pair(262, 63), Pair(463, 26), Pair(416, 22), Pair(396, -39), Pair(25, 63), Pair(-156, 133),
      Pair(-64, 113), Pair(174, 132), Pair(224, 98), Pair(509, 35), Pair(421, 54), Pair(369, 81), Pair(177, 41), Pair(-19, 126),
      Pair(130, 58), Pair(344, 48), Pair(183, 104), Pair(444, 55), Pair(355, 61), Pair(480, 43), Pair(285, 100), Pair(279, 20),
      Pair(225, 34), Pair(258, 57), Pair(267, 71), Pair(364, 95), Pair(280, 103), Pair(211, 72), Pair(-74, 136), Pair(-198, 137),
      Pair(-297, 119), Pair(108, 86), Pair(239, 111), Pair(144, 103), Pair(263, 76), Pair(275, 65), Pair(102, 70), Pair(60, 117),
      Pair(-298, 130), Pair(-161, 136), Pair(356, 64), Pair(105, 86), Pair(-93, 157), Pair(80, 107), Pair(-4, 162), Pair(-50, 111)
    },
    {
      Pair(-178, 79), Pair(9, 27), Pair(104, -16), Pair(84, 20), Pair(-26, 62), Pair(70, -31), Pair(49, -1), Pair(86, 41),
      Pair(-20, 13), Pair(125, 16), Pair(-240, 62), Pair(67, 30), Pair(53, -3), Pair(-23, 21), Pair(-21, 25), Pair(-207, 55),
      Pair(154, 42), Pair(49, 41), Pair(69, 46), Pair(-81, 22), Pair(115, 4), Pair(149, 15), Pair(52, 46), Pair(220, -19),
      Pair(-98, 79), Pair(66, 61), Pair(199, 16), Pair(347, -38), Pair(162, 18), Pair(287, 9), Pair(276, -3), Pair(287, -1),
      Pair(277, 5), Pair(168, 4), Pair(105, 3), Pair(285, -16), Pair(72, 9), Pair(73, 8), Pair(51, 43), Pair(144, 11),
      Pair(84, 39), Pair(-8, 61), Pair(131, 16), Pair(150, 25), Pair(317, 11), Pair(235, 42), Pair(306, 8), Pair(-14, 57),
      Pair(-461, 127), Pair(117, 9), Pair(123, 25), Pair(123, 16), Pair(107, 13), Pair(77, 13), Pair(94, 20), Pair(16, 30),
      Pair(-485, 148), Pair(-310, 173), Pair(-3, 55), Pair(-106, 62), Pair(1, 37), Pair(-23, 32), Pair(26, 35), Pair(-274, 68)
    },
    {
      Pair(-10, 73), Pair(-133, 147), Pair(-71, 133), Pair(-37, 123), Pair(-73, 137), Pair(237, 69), Pair(156, 81), Pair(43, 76),
      Pair(-81, 67), Pair(292, 10), Pair(8, 76), Pair(78, 67), Pair(194, 41), Pair(177, 45), Pair(310, -13), Pair(157, -22),
      Pair(65, 45), Pair(57, 50), Pair(216, -19), Pair(312, -14), Pair(426, -53), Pair(425, -40), Pair(92, 29), Pair(80, 8),
      Pair(3, 56), Pair(413, -31), Pair(8, 79), Pair(179, -12), Pair(273, -35), Pair(448, -89), Pair(383, -67), Pair(99, 39),
      Pair(-48, 93), Pair(-47, 106), Pair(-98, 127), Pair(158, 43), Pair(62, 69), Pair(244, 22), Pair(177, 41), Pair(-92, 99),
      Pair(-185, 98), Pair(189, -9), Pair(34, 37), Pair(-17, 52), Pair(35, 55), Pair(158, 35), Pair(194, -20), Pair(-49, 28),
      Pair(-140, 18), Pair(-117, 18), Pair(29, 33), Pair(25, 0), Pair(15, 20), Pair(77, 11), Pair(97, 15), Pair(-51, 5),
      Pair(16, 9), Pair(66, 22), Pair(151, 0), Pair(101, 24), Pair(124, -1), Pair(182, -38), Pair(2, 49), Pair(-58, 37)
    },
    {
      Pair(416, -26), Pair(324, 48), Pair(362, 136), Pair(409, 147), Pair(225, 262), Pair(461, 127), Pair(495, -66), Pair(276, 191),
      Pair(289, 38), Pair(475, 123), Pair(571, 122), Pair(557, 139), Pair(727, -52), Pair(614, 58), Pair(491, 64), Pair(853, -176),
      Pair(385, 81), Pair(366, 100), Pair(398, 84), Pair(503, 162), Pair(800, -102), Pair(748, -73), Pair(749, -124), Pair(1148, -411),
      Pair(260, 316), Pair(226, 408), Pair(120, 336), Pair(659, 64), Pair(564, -9), Pair(544, 154), Pair(511, 1), Pair(396, 282),
      Pair(-5, 312), Pair(286, 241), Pair(509, 246), Pair(384, 215), Pair(408, 205), Pair(621, 87), Pair(634, 114), Pair(327, 254),
      Pair(275, 134), Pair(281, 194), Pair(675, 49), Pair(373, 196), Pair(403, 135), Pair(606, 83), Pair(312, 128), Pair(239, 261),
      Pair(232, 221), Pair(195, 116), Pair(338, 81), Pair(123, 264), Pair(336, 92), Pair(405, 58), Pair(247, 48), Pair(-43, 150),
      Pair(206, 279), Pair(337, 52), Pair(313, 44), Pair(458, 54), Pair(356, 87), Pair(-30, 270), Pair(190, 416), Pair(95, 477)
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
      Pair(-111, 238), Pair(697, 96), Pair(624, 143), Pair(-42, 235), Pair(273, 251), Pair(162, 285), Pair(-140, 335), Pair(244, 206),
      Pair(53, 38), Pair(47, 67), Pair(41, 59), Pair(-139, 84), Pair(81, 81), Pair(122, 61), Pair(310, 59), Pair(177, 53),
      Pair(74, -26), Pair(118, -29), Pair(94, -48), Pair(-118, -30), Pair(47, -32), Pair(224, -64), Pair(174, -61), Pair(149, -49),
      Pair(116, -57), Pair(131, -33), Pair(139, -71), Pair(131, -59), Pair(175, -73), Pair(296, -93), Pair(356, -96), Pair(195, -68),
      Pair(59, -50), Pair(73, -44), Pair(55, -54), Pair(33, -34), Pair(127, -52), Pair(207, -51), Pair(234, -67), Pair(142, -63),
      Pair(31, -9), Pair(115, -19), Pair(222, -55), Pair(-179, -26), Pair(281, -87), Pair(308, -58), Pair(409, -87), Pair(3, -26),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-70, -181), Pair(-235, -23), Pair(-162, -23), Pair(144, -26), Pair(6, -33), Pair(-269, -39), Pair(20, -179), Pair(395, -210),
      Pair(-39, 27), Pair(246, -47), Pair(46, 1), Pair(190, -21), Pair(289, -61), Pair(163, -60), Pair(160, 11), Pair(-55, 0),
      Pair(-299, 20), Pair(146, -30), Pair(368, -33), Pair(496, -30), Pair(637, -72), Pair(403, -63), Pair(120, -73), Pair(-26, 39),
      Pair(266, -77), Pair(262, 3), Pair(624, -74), Pair(538, -57), Pair(871, -133), Pair(331, 1), Pair(196, -57), Pair(623, -118),
      Pair(-33, 33), Pair(85, 45), Pair(285, 35), Pair(497, 10), Pair(485, -2), Pair(499, -13), Pair(415, -17), Pair(561, -55),
      Pair(-184, -42), Pair(264, 16), Pair(540, -49), Pair(796, -49), Pair(706, -12), Pair(455, -19), Pair(596, -52), Pair(195, -4),
      Pair(3, -119), Pair(-144, 48), Pair(253, -35), Pair(351, 17), Pair(448, -41), Pair(545, -64), Pair(48, 68), Pair(210, -29),
      Pair(233, -35), Pair(9, 14), Pair(655, -57), Pair(771, -91), Pair(482, -86), Pair(282, -6), Pair(354, -57), Pair(-168, 56)
    },
    {
      Pair(271, -27), Pair(148, 22), Pair(413, -74), Pair(-46, -22), Pair(177, 5), Pair(-478, 57), Pair(204, -6), Pair(114, -87),
      Pair(-217, 9), Pair(118, -7), Pair(77, 42), Pair(191, 26), Pair(180, -4), Pair(232, -16), Pair(22, -1), Pair(121, 64),
      Pair(-230, 35), Pair(234, -9), Pair(185, 29), Pair(-73, 35), Pair(13, 54), Pair(-46, 34), Pair(1, 64), Pair(154, -9),
      Pair(58, -33), Pair(100, 27), Pair(-47, 50), Pair(171, 19), Pair(241, -23), Pair(-113, 123), Pair(-265, 84), Pair(-173, 68),
      Pair(43, 32), Pair(131, -13), Pair(134, 14), Pair(120, 5), Pair(241, -7), Pair(186, 35), Pair(87, 23), Pair(269, -5),
      Pair(55, 7), Pair(161, -4), Pair(-73, 27), Pair(63, 4), Pair(292, -76), Pair(188, -12), Pair(272, -73), Pair(194, -60),
      Pair(-146, 116), Pair(186, -94), Pair(172, -24), Pair(166, -47), Pair(221, -44), Pair(201, -60), Pair(165, -9), Pair(-101, -28),
      Pair(-601, 20), Pair(-735, 261), Pair(-15, 3), Pair(26, 36), Pair(85, -30), Pair(106, 15), Pair(-435, 99), Pair(-603, 36)
    },
    {
      Pair(365, -102), Pair(75, -8), Pair(4, 51), Pair(25, 64), Pair(23, 31), Pair(513, -62), Pair(332, -17), Pair(398, -78),
      Pair(98, -46), Pair(261, -51), Pair(323, -30), Pair(72, 10), Pair(274, -70), Pair(91, 12), Pair(381, -63), Pair(98, -19),
      Pair(-5, -8), Pair(449, -99), Pair(227, -69), Pair(94, -30), Pair(124, -29), Pair(310, -74), Pair(145, -27), Pair(243, -78),
      Pair(155, -10), Pair(505, -96), Pair(146, -20), Pair(149, -17), Pair(123, -45), Pair(493, -121), Pair(203, -24), Pair(238, -55),
      Pair(228, -57), Pair(322, -78), Pair(637, -189), Pair(294, -127), Pair(452, -125), Pair(220, -12), Pair(101, -79), Pair(-105, 2),
      Pair(62, -41), Pair(511, -96), Pair(-23, -1), Pair(105, -25), Pair(64, -46), Pair(145, -50), Pair(349, -69), Pair(191, -68),
      Pair(80, -56), Pair(-7, -10), Pair(95, -47), Pair(204, -64), Pair(310, -134), Pair(446, -147), Pair(234, -111), Pair(477, -181),
      Pair(192, -102), Pair(326, -122), Pair(295, -124), Pair(352, -141), Pair(545, -193), Pair(364, -141), Pair(392, -147), Pair(-9, -40)
    },
    {
      Pair(158, -47), Pair(-102, 170), Pair(95, 153), Pair(437, 74), Pair(332, 77), Pair(-255, 290), Pair(-64, 163), Pair(-135, 178),
      Pair(237, 31), Pair(218, 6), Pair(214, 63), Pair(246, 185), Pair(264, 124), Pair(380, 101), Pair(478, -106), Pair(389, 32),
      Pair(142, 148), Pair(379, 4), Pair(134, 196), Pair(412, 74), Pair(192, 199), Pair(598, -140), Pair(387, -8), Pair(502, -40),
      Pair(59, 171), Pair(235, 143), Pair(270, 144), Pair(457, 59), Pair(558, 10), Pair(320, 36), Pair(-109, 210), Pair(386, 64),
      Pair(185, -32), Pair(43, 271), Pair(36, 258), Pair(-325, 640), Pair(121, 202), Pair(141, 290), Pair(-124, 324), Pair(150, 181),
      Pair(-402, 464), Pair(-50, 456), Pair(261, 191), Pair(385, 46), Pair(137, 449), Pair(349, 73), Pair(136, 227), Pair(283, 232),
      Pair(118, 49), Pair(166, 202), Pair(164, 180), Pair(380, 39), Pair(310, 124), Pair(-32, 108), Pair(94, 159), Pair(-47, 150),
      Pair(-85, 137), Pair(-194, 209), Pair(455, -232), Pair(279, 8), Pair(118, 150), Pair(52, 130), Pair(-512, 506), Pair(261, -164)
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
      Pair(-238, 297), Pair(256, 159), Pair(385, 246), Pair(654, 156), Pair(174, 275), Pair(332, 232), Pair(-272, 247), Pair(-325, 272),
      Pair(-170, 121), Pair(291, 23), Pair(358, 72), Pair(250, -60), Pair(294, 34), Pair(359, -11), Pair(-18, 130), Pair(352, 20),
      Pair(44, 38), Pair(394, -39), Pair(184, 19), Pair(-184, 54), Pair(55, -40), Pair(534, -71), Pair(313, -29), Pair(341, -44),
      Pair(31, -22), Pair(396, -81), Pair(105, -26), Pair(24, -42), Pair(100, -85), Pair(431, -107), Pair(335, -73), Pair(239, -66),
      Pair(77, -75), Pair(297, -175), Pair(298, -131), Pair(-53, -107), Pair(32, -73), Pair(265, -140), Pair(325, -122), Pair(338, -127),
      Pair(51, -47), Pair(419, -88), Pair(511, -110), Pair(72, 27), Pair(-249, -28), Pair(422, -89), Pair(513, -126), Pair(273, -91),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(90, -443), Pair(-453, -248), Pair(449, -230), Pair(-155, -183), Pair(-70, -208), Pair(240, -174), Pair(250, -179), Pair(-42, -140),
      Pair(596, -111), Pair(38, 31), Pair(-83, -128), Pair(41, -57), Pair(598, -308), Pair(-310, -54), Pair(-205, -124), Pair(-63, -217),
      Pair(275, -143), Pair(-127, -159), Pair(289, -158), Pair(1, -97), Pair(150, -177), Pair(8, 20), Pair(586, -41), Pair(241, -124),
      Pair(32, -142), Pair(138, -4), Pair(452, -143), Pair(562, -166), Pair(695, -167), Pair(667, -203), Pair(334, -205), Pair(23, -29),
      Pair(231, -274), Pair(51, -120), Pair(217, 64), Pair(300, -82), Pair(541, -206), Pair(163, -72), Pair(33, -128), Pair(-35, 66),
      Pair(-347, -80), Pair(298, -134), Pair(180, -62), Pair(846, -163), Pair(397, -39), Pair(68, -16), Pair(23, -70), Pair(292, 133),
      Pair(-90, -152), Pair(-27, -77), Pair(29, -6), Pair(-166, -62), Pair(88, -113), Pair(318, -177), Pair(-304, -122), Pair(310, -217),
      Pair(-569, -74), Pair(-17, -40), Pair(81, -149), Pair(-93, -91), Pair(341, -229), Pair(-1, -153), Pair(-367, -48), Pair(-51, 65)
    },
    {
      Pair(57, -44), Pair(211, 53), Pair(-142, -120), Pair(241, -85), Pair(49, 95), Pair(26, -143), Pair(104, -18), Pair(-94, -29),
      Pair(32, -45), Pair(2, -87), Pair(-146, -32), Pair(184, -135), Pair(286, -110), Pair(271, -175), Pair(231, -77), Pair(59, -85),
      Pair(142, -94), Pair(111, -131), Pair(205, -138), Pair(33, -52), Pair(185, -112), Pair(126, -82), Pair(22, -41), Pair(188, -44),
      Pair(19, -50), Pair(124, -154), Pair(4, -76), Pair(60, 0), Pair(42, -98), Pair(-276, 10), Pair(211, -101), Pair(59, -63),
      Pair(-267, -97), Pair(31, -41), Pair(306, -138), Pair(309, -127), Pair(341, -91), Pair(155, -12), Pair(-313, -5), Pair(277, 2),
      Pair(-69, 41), Pair(277, -97), Pair(112, -143), Pair(270, -24), Pair(7, -74), Pair(-294, -14), Pair(-20, -5), Pair(-128, -23),
      Pair(-422, 52), Pair(84, -111), Pair(210, -141), Pair(210, -141), Pair(-119, -71), Pair(-96, -138), Pair(6, -283), Pair(-148, -101),
      Pair(-298, -108), Pair(121, 5), Pair(-287, -184), Pair(-88, -159), Pair(-390, -38), Pair(89, -149), Pair(-503, -35), Pair(-400, -259)
    },
    {
      Pair(230, -189), Pair(314, -173), Pair(52, -151), Pair(168, -78), Pair(401, -239), Pair(173, -124), Pair(-48, 1), Pair(416, -200),
      Pair(469, -229), Pair(344, -214), Pair(559, -252), Pair(-52, -148), Pair(249, -201), Pair(-43, -140), Pair(-198, -3), Pair(-11, -162),
      Pair(-65, -114), Pair(206, -154), Pair(234, -201), Pair(303, -192), Pair(81, -97), Pair(39, -154), Pair(136, -135), Pair(338, -249),
      Pair(591, -244), Pair(334, -136), Pair(210, -165), Pair(161, -168), Pair(156, -196), Pair(520, -266), Pair(196, -108), Pair(248, -186),
      Pair(215, -196), Pair(505, -232), Pair(258, -186), Pair(290, -189), Pair(474, -290), Pair(168, -135), Pair(202, -200), Pair(230, -185),
      Pair(15, -106), Pair(89, -82), Pair(389, -268), Pair(522, -317), Pair(353, -199), Pair(606, -294), Pair(102, -153), Pair(-70, -77),
      Pair(151, -82), Pair(-27, -77), Pair(286, -183), Pair(461, -317), Pair(513, -316), Pair(76, -115), Pair(56, -145), Pair(98, -206),
      Pair(119, -139), Pair(83, -216), Pair(237, -242), Pair(148, -250), Pair(177, -303), Pair(682, -381), Pair(366, -245), Pair(465, -244)
    },
    {
      Pair(-187, -84), Pair(-383, 113), Pair(-357, 6), Pair(-307, -10), Pair(-331, 96), Pair(-348, 47), Pair(-436, -100), Pair(48, -348),
      Pair(-71, -154), Pair(-209, 22), Pair(94, -19), Pair(-198, -86), Pair(-138, 29), Pair(-596, 235), Pair(-57, -39), Pair(-270, -108),
      Pair(-6, -92), Pair(-220, -95), Pair(-85, 14), Pair(70, -122), Pair(-53, -54), Pair(-141, -154), Pair(-179, -101), Pair(38, -134),
      Pair(-122, 38), Pair(-337, 45), Pair(330, -115), Pair(145, -121), Pair(188, -70), Pair(-230, 96), Pair(-85, 52), Pair(4, -31),
      Pair(102, -199), Pair(195, -157), Pair(-46, -26), Pair(-375, 240), Pair(231, 4), Pair(-219, 131), Pair(-336, 124), Pair(-126, 48),
      Pair(-184, -319), Pair(12, -177), Pair(-201, 200), Pair(-92, 25), Pair(-718, 401), Pair(-313, 102), Pair(122, -234), Pair(248, -69),
      Pair(445, -453), Pair(-110, -170), Pair(-291, 127), Pair(-547, 331), Pair(-398, 362), Pair(-239, -14), Pair(12, -57), Pair(-375, 246),
      Pair(-59, -134), Pair(-394, -97), Pair(465, -149), Pair(-638, 251), Pair(-418, 90), Pair(-633, -9), Pair(58, 1), Pair(-969, 165)
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

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(129, 496), Pair(164, 474), Pair(186, 529), Pair(200, 550), Pair(212, 571), Pair(221, 591), Pair(236, 592), Pair(243, 588),
  Pair(244, 570)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(20, 176), Pair(45, 144), Pair(69, 188), Pair(83, 219), Pair(98, 241), Pair(106, 267), Pair(112, 279), Pair(117, 288),
  Pair(120, 301), Pair(131, 298), Pair(153, 293), Pair(166, 299), Pair(156, 340), Pair(163, 294)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(49, 175), Pair(74, 244), Pair(85, 265), Pair(86, 300), Pair(87, 312), Pair(100, 319), Pair(107, 328), Pair(116, 333),
  Pair(126, 341), Pair(134, 351), Pair(142, 357), Pair(146, 369), Pair(158, 373), Pair(166, 375), Pair(166, 369)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(353, 298), Pair(464, 102), Pair(444, 643), Pair(464, 763), Pair(465, 868), Pair(470, 914), Pair(478, 950), Pair(481, 985),
  Pair(487, 1007), Pair(495, 1009), Pair(500, 1025), Pair(504, 1046), Pair(513, 1037), Pair(512, 1051), Pair(519, 1051), Pair(528, 1042),
  Pair(528, 1052), Pair(534, 1050), Pair(554, 1028), Pair(586, 996), Pair(608, 973), Pair(709, 905), Pair(696, 896), Pair(736, 836),
  Pair(846, 800), Pair(1085, 613), Pair(946, 692), Pair(694, 752)
};

constexpr KingBuckets<RankTable<ScorePair>> kPassedPawnBonus = {{
  {
      Pair(0, 0), Pair(31, -221), Pair(41, -200), Pair(43, -105), Pair(98, 9), Pair(100, 103), Pair(121, 296), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(63, -235), Pair(62, -217), Pair(51, -127), Pair(87, -6), Pair(91, 161), Pair(223, 217), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(19, -204), Pair(8, -161), Pair(12, -73), Pair(77, 23), Pair(119, 193), Pair(139, 194), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-36, -174), Pair(-47, -114), Pair(-35, -22), Pair(65, 71), Pair(66, 287), Pair(239, 234), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-80, -128), Pair(-149, -55), Pair(-178, 37), Pair(-118, 144), Pair(-184, 427), Pair(138, 311), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-154, -99), Pair(-240, -61), Pair(-389, 87), Pair(-476, 279), Pair(-499, 461), Pair(256, 251), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-205, -108), Pair(-244, -30), Pair(-296, 67), Pair(-401, 230), Pair(-275, 375), Pair(125, 245), Pair(0, 0)
  }
}};

constexpr KingBuckets<RankTable<ScorePair>> kPawnPhalanxBonus = {{
  {
      Pair(0, 0), Pair(19, -8), Pair(36, 2), Pair(44, 31), Pair(122, 132), Pair(348, 386), Pair(229, 1446), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(16, 6), Pair(49, 15), Pair(62, 27), Pair(144, 130), Pair(911, 401), Pair(74, 1146), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(7, 3), Pair(29, 27), Pair(76, 38), Pair(103, 181), Pair(-160, 972), Pair(-367, 1408), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-7, 14), Pair(-19, 44), Pair(67, 59), Pair(-11, 198), Pair(-221, 664), Pair(-701, 1280), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-51, 47), Pair(21, 38), Pair(-34, 53), Pair(-142, 236), Pair(-6, 643), Pair(-943, 1268), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(48, 5), Pair(17, -1), Pair(-109, 90), Pair(-189, 252), Pair(-317, 666), Pair(-1769, 1298), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(10, -50), Pair(-65, 26), Pair(13, 38), Pair(-209, 200), Pair(-858, 515), Pair(-608, 722), Pair(0, 0)
  }
}};

constexpr KingBuckets<RankTable<ScorePair>> kDefendedPawnBonus = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(55, 36), Pair(33, 31), Pair(35, 39), Pair(49, 155), Pair(458, 46), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(59, 25), Pair(36, 18), Pair(29, 39), Pair(71, 142), Pair(776, 92), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(50, 30), Pair(31, 24), Pair(26, 49), Pair(47, 140), Pair(246, 120), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(24, 35), Pair(6, 22), Pair(7, 49), Pair(54, 118), Pair(390, 122), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(39, 33), Pair(-26, 28), Pair(-10, 56), Pair(115, 105), Pair(9, 421), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(5, 17), Pair(-21, 17), Pair(-45, 44), Pair(418, -10), Pair(-195, 397), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(-78, 48), Pair(108, -13), Pair(-44, -7), Pair(369, 91), Pair(-230, 453), Pair(0, 0)
  }
}};

constexpr KingBuckets<FileTable<ScorePair>> kDoubledPawnPenalty = {{
  {
      Pair(-25, -153), Pair(32, -140), Pair(-3, -75), Pair(-7, -33), Pair(-29, -19), Pair(-29, -40), Pair(43, -108), Pair(5, -150)
  },
  {
      Pair(-4, -118), Pair(31, -100), Pair(17, -67), Pair(8, -64), Pair(-4, -11), Pair(-10, -53), Pair(-7, -59), Pair(-31, -89)
  },
  {
      Pair(-28, -117), Pair(30, -97), Pair(25, -73), Pair(29, -41), Pair(-6, -17), Pair(7, -54), Pair(17, -67), Pair(-39, -126)
  },
  {
      Pair(-69, -89), Pair(11, -70), Pair(13, -77), Pair(78, -36), Pair(92, -23), Pair(-32, -39), Pair(3, -51), Pair(-141, -59)
  },
  {
      Pair(-193, -89), Pair(-84, -50), Pair(45, -53), Pair(-125, -13), Pair(131, -52), Pair(0, -38), Pair(-117, -41), Pair(-210, -82)
  },
  {
      Pair(-248, -77), Pair(-229, -12), Pair(-38, -85), Pair(-24, -84), Pair(-492, 58), Pair(-65, -79), Pair(-107, -13), Pair(-212, -66)
  },
  {
      Pair(-683, 114), Pair(-593, 89), Pair(-394, 0), Pair(-226, -14), Pair(-33, -70), Pair(-763, -9), Pair(-496, 72), Pair(-440, -59)
  }
}};

constexpr KingBuckets<FileTable<ScorePair>> kIsolatedPawnPenalty = {{
  {
      Pair(-21, 55), Pair(-3, -32), Pair(-29, -11), Pair(-25, -22), Pair(-40, -20), Pair(-25, -7), Pair(4, -34), Pair(-28, 39)
  },
  {
      Pair(4, 29), Pair(1, -21), Pair(-33, -15), Pair(-27, -43), Pair(-27, -48), Pair(10, -30), Pair(-4, -37), Pair(-11, 15)
  },
  {
      Pair(-2, 32), Pair(-10, -29), Pair(-33, -9), Pair(-7, -34), Pair(-18, -49), Pair(-4, -22), Pair(-9, -28), Pair(-2, 4)
  },
  {
      Pair(15, 2), Pair(-15, -24), Pair(-41, -10), Pair(34, -58), Pair(-6, -60), Pair(24, -29), Pair(-27, -30), Pair(-14, 2)
  },
  {
      Pair(46, -10), Pair(-23, -31), Pair(-11, -20), Pair(71, -63), Pair(23, -61), Pair(54, -31), Pair(26, -33), Pair(18, -1)
  },
  {
      Pair(80, -27), Pair(107, -48), Pair(44, -25), Pair(216, -67), Pair(124, -54), Pair(125, -38), Pair(68, -33), Pair(103, -32)
  },
  {
      Pair(376, -109), Pair(284, -79), Pair(135, -27), Pair(190, -56), Pair(290, -55), Pair(378, -50), Pair(299, -98), Pair(232, -73)
  }
}};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(55, 14), Pair(49, 7), Pair(47, 21), Pair(50, 18), Pair(53, 31), Pair(76, 12), Pair(114, -1), Pair(190, -14)
  },
  {
      Pair(22, 89), Pair(24, 24), Pair(29, 23), Pair(50, -2), Pair(39, 0), Pair(44, -8), Pair(63, -7), Pair(64, 39)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(35, -13), Pair(48, -14), Pair(26, -3),
  Pair(58, -26), Pair(51, -30), Pair(55, -27),
  Pair(80, -5), Pair(0, 0), Pair(72, -3),
  Pair(-29, 19), Pair(-4, -7), Pair(-33, 23)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-19, 4), Pair(-39, 11), Pair(-23, 10),
  Pair(-18, 3), Pair(-46, 20), Pair(-24, 9),
  Pair(-5, -12), Pair(-40, 10), Pair(-8, -8),
  Pair(32, -17), Pair(-10, -8), Pair(28, -11),
  Pair(56, -29), Pair(57, -2), Pair(39, -30),
  Pair(0, 0), Pair(-24, -36), Pair(0, 0),
  Pair(96, -99), Pair(0, 0), Pair(70, -92)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-40, 189), Pair(-42, 147), Pair(-26, 96), Pair(-18, 68), Pair(-14, 60), Pair(5, 56), Pair(-17, 53)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-78, -99), Pair(-24, -47), Pair(-28, 30), Pair(-22, 70), Pair(-25, 96), Pair(-23, 110), Pair(-38, 85)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-3292, 446);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-190, -25), Pair(-203, -14), Pair(-80, -30), Pair(-74, -19), Pair(-47, -10), Pair(-84, -6), Pair(-133, 1), Pair(-99, 14)
  },
  {
      Pair(-13, 111), Pair(-91, 46), Pair(-34, 23), Pair(4, -3), Pair(-5, -14), Pair(-9, 6), Pair(-64, 49), Pair(-42, 78)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(29, 4), Pair(66, -19), Pair(138, -55), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(35, 3), Pair(70, -2), Pair(160, -19), Pair(182, -97), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(50, -53), Pair(90, -50), Pair(137, -36), Pair(207, -38), Pair(247, -63), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(6, 28), Pair(28, 60), Pair(80, 68), Pair(192, 33), Pair(287, 15), Pair(451, -51), Pair(633, -186)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(123, 25), Pair(51, 58), Pair(151, 1), Pair(70, 31), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-48, 35), Pair(-29, 49)
  },
  {
      Pair(-175, -59), Pair(-173, -76)
  },
  {
      Pair(-152, -122), Pair(-172, -188)
  },
  {
      Pair(-247, 8), Pair(-220, -82)
  },
  {
      Pair(-198, 91), Pair(-217, 38)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(44, 84), Pair(54, 52), Pair(76, 26), Pair(58, -10), Pair(142, -4)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-6, -51), Pair(24, -31)
  },
  {
      Pair(-57, -117), Pair(-7, -154)
  },
  {
      Pair(-110, -83), Pair(-74, -87)
  },
  {
      Pair(-216, -4), Pair(-161, -67)
  },
  {
      Pair(-150, 93), Pair(-153, 54)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-27, -52), Pair(3, -24)
  },
  {
      Pair(-127, -62), Pair(-55, -68)
  },
  {
      Pair(54, -357), Pair(82, -342)
  },
  {
      Pair(-213, -19), Pair(-122, -97)
  },
  {
      Pair(-221, -45), Pair(-160, -233)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-5, -65), Pair(29, -29)
  },
  {
      Pair(-103, -68), Pair(-5, -36)
  },
  {
      Pair(-77, -72), Pair(-34, -10)
  },
  {
      Pair(-5, -142), Pair(32, -81)
  },
  {
      Pair(-218, 19), Pair(-162, -112)
  },
  {
      Pair(0, 0), Pair(0, 0)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(61, 46), Pair(49, 27), Pair(102, 57), Pair(122, 59), Pair(124, 74), Pair(70, 120), Pair(96, 39), Pair(7, 110),
  Pair(13, 33), Pair(34, 47), Pair(48, 56), Pair(26, 91), Pair(36, 65), Pair(29, 56), Pair(33, 45), Pair(-13, 72),
  Pair(23, 28), Pair(15, 11), Pair(3, 45), Pair(23, 48), Pair(17, 56), Pair(-18, 55), Pair(4, 20), Pair(1, 25)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-26, 32), Pair(60, -4), Pair(82, 6), Pair(116, 11), Pair(186, -31), Pair(136, -1), Pair(66, -20), Pair(-41, -49),
  Pair(-52, -41), Pair(49, 20), Pair(28, 8), Pair(63, 36), Pair(38, 13), Pair(43, -7), Pair(34, 23), Pair(44, -52),
  Pair(-57, 73), Pair(26, 11), Pair(9, 55), Pair(48, 40), Pair(62, 61), Pair(7, 21), Pair(37, 1), Pair(-120, 12)
};

constexpr ScorePair kBishopPairBonus = Pair(50, 154);

constexpr ScorePair kTempoBonus = Pair(80, 74);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H