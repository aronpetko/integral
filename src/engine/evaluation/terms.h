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
      Pair(101, 150), Pair(391, 396), Pair(412, 453), Pair(537, 779), Pair(1100, 1393), Pair(0, 0)
  },
  {
      Pair(59, 89), Pair(175, 239), Pair(176, 263), Pair(207, 432), Pair(501, 897), Pair(0, 0)
  },
  {
      Pair(51, 70), Pair(162, 214), Pair(173, 235), Pair(204, 345), Pair(496, 703), Pair(0, 0)
  },
  {
      Pair(69, 79), Pair(198, 238), Pair(212, 249), Pair(243, 375), Pair(605, 896), Pair(0, 0)
  },
  {
      Pair(54, 105), Pair(178, 213), Pair(210, 219), Pair(215, 331), Pair(662, 896), Pair(0, 0)
  },
  {
      Pair(31, 98), Pair(170, 201), Pair(261, 187), Pair(174, 311), Pair(441, 852), Pair(0, 0)
  },
  {
      Pair(112, 100), Pair(212, 286), Pair(355, 275), Pair(240, 456), Pair(731, 895), Pair(0, 0)
  }
}};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {{ // Bucket 0
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(-21, 67), Pair(-17, 50), Pair(5, 13), Pair(21, -13), Pair(43, -27), Pair(47, -57), Pair(-55, -51), Pair(-115, 35),
      Pair(-25, 65), Pair(-9, 47), Pair(3, 20), Pair(24, -25), Pair(45, -25), Pair(89, -30), Pair(24, 6), Pair(-15, 53),
      Pair(-22, 20), Pair(-6, -1), Pair(-19, -6), Pair(1, -36), Pair(15, -32), Pair(30, -52), Pair(12, -22), Pair(-24, 10),
      Pair(-25, 1), Pair(-11, -6), Pair(-12, -29), Pair(-10, -27), Pair(-4, -32), Pair(21, -52), Pair(25, -45), Pair(-9, -12),
      Pair(-33, -8), Pair(-24, -19), Pair(-28, -19), Pair(-23, -17), Pair(-15, -12), Pair(-14, -28), Pair(-10, -40), Pair(-25, -24),
      Pair(-29, -1), Pair(-17, -11), Pair(-34, -1), Pair(-27, -4), Pair(-27, 11), Pair(-5, 0), Pair(6, -32), Pair(-29, -40),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-247, -33), Pair(-121, 33), Pair(-160, 65), Pair(-36, 30), Pair(-16, 24), Pair(-138, 70), Pair(-83, 19), Pair(-195, 4),
      Pair(-52, 20), Pair(-48, 37), Pair(-6, 38), Pair(11, 59), Pair(15, 54), Pair(57, 1), Pair(-38, 18), Pair(-2, 0),
      Pair(-76, 28), Pair(-31, 46), Pair(-1, 74), Pair(17, 65), Pair(33, 47), Pair(41, 65), Pair(-7, 49), Pair(2, 15),
      Pair(-24, 32), Pair(0, 52), Pair(15, 82), Pair(27, 84), Pair(21, 98), Pair(41, 76), Pair(4, 85), Pair(10, 50),
      Pair(-31, 26), Pair(-9, 56), Pair(7, 80), Pair(10, 89), Pair(15, 87), Pair(21, 79), Pair(29, 57), Pair(-11, 47),
      Pair(-43, -7), Pair(-19, 34), Pair(-13, 52), Pair(2, 70), Pair(6, 70), Pair(-4, 49), Pair(-8, 42), Pair(-26, -6),
      Pair(-64, 23), Pair(-49, 29), Pair(-34, 19), Pair(-18, 51), Pair(-24, 54), Pair(-21, 26), Pair(-33, 40), Pair(-32, 33),
      Pair(-126, -28), Pair(-42, -14), Pair(-56, 19), Pair(-32, 37), Pair(-25, 37), Pair(-22, 32), Pair(-44, 8), Pair(-110, -57)
    },
    {
      Pair(-72, 64), Pair(-97, 70), Pair(-165, 80), Pair(-148, 75), Pair(-128, 74), Pair(-149, 59), Pair(-21, 45), Pair(-50, 56),
      Pair(-84, 62), Pair(-52, 68), Pair(-38, 52), Pair(-68, 63), Pair(-66, 50), Pair(-18, 33), Pair(-75, 58), Pair(-39, 30),
      Pair(-29, 46), Pair(-24, 61), Pair(-4, 55), Pair(-14, 37), Pair(1, 44), Pair(-13, 74), Pair(-1, 54), Pair(-16, 45),
      Pair(-39, 42), Pair(-12, 48), Pair(-25, 54), Pair(3, 45), Pair(-10, 51), Pair(-11, 51), Pair(-19, 54), Pair(-26, 52),
      Pair(-30, 31), Pair(-19, 34), Pair(-14, 46), Pair(-15, 52), Pair(-6, 46), Pair(-16, 37), Pair(-12, 36), Pair(-20, 25),
      Pair(-25, 24), Pair(-8, 36), Pair(-13, 41), Pair(-12, 51), Pair(-13, 52), Pair(-10, 44), Pair(-5, 28), Pair(-10, 40),
      Pair(-13, 21), Pair(-8, 13), Pair(-7, 19), Pair(-21, 36), Pair(-17, 43), Pair(-5, 24), Pair(9, 34), Pair(-1, -16),
      Pair(-2, 5), Pair(-5, 19), Pair(-27, 30), Pair(-26, 28), Pair(-25, 37), Pair(-16, 45), Pair(-11, 34), Pair(-4, 17)
    },
    {
      Pair(37, 111), Pair(30, 117), Pair(-1, 129), Pair(7, 125), Pair(26, 117), Pair(51, 131), Pair(34, 140), Pair(44, 129),
      Pair(10, 113), Pair(-1, 123), Pair(22, 118), Pair(34, 122), Pair(30, 122), Pair(53, 100), Pair(42, 113), Pair(22, 110),
      Pair(6, 104), Pair(58, 89), Pair(38, 109), Pair(63, 94), Pair(75, 88), Pair(85, 97), Pair(99, 76), Pair(28, 97),
      Pair(10, 100), Pair(32, 99), Pair(41, 99), Pair(63, 94), Pair(57, 100), Pair(46, 102), Pair(55, 86), Pair(18, 95),
      Pair(-10, 86), Pair(-7, 107), Pair(-3, 102), Pair(12, 95), Pair(4, 90), Pair(-5, 102), Pair(25, 84), Pair(-11, 86),
      Pair(-19, 72), Pair(-3, 83), Pair(-12, 85), Pair(3, 75), Pair(1, 76), Pair(-6, 81), Pair(21, 65), Pair(-16, 54),
      Pair(-39, 66), Pair(-6, 59), Pair(-4, 65), Pair(4, 59), Pair(3, 58), Pair(6, 58), Pair(8, 51), Pair(-55, 52),
      Pair(-3, 65), Pair(1, 66), Pair(6, 70), Pair(13, 63), Pair(11, 63), Pair(13, 77), Pair(12, 66), Pair(-29, 40)
    },
    {
      Pair(51, 91), Pair(74, 88), Pair(72, 107), Pair(72, 110), Pair(90, 103), Pair(119, 118), Pair(108, 116), Pair(165, 60),
      Pair(50, 104), Pair(10, 140), Pair(64, 110), Pair(34, 152), Pair(20, 179), Pair(108, 140), Pair(28, 175), Pair(117, 102),
      Pair(46, 93), Pair(60, 100), Pair(59, 109), Pair(68, 123), Pair(85, 143), Pair(107, 142), Pair(111, 151), Pair(58, 152),
      Pair(62, 81), Pair(68, 118), Pair(66, 101), Pair(60, 146), Pair(71, 150), Pair(80, 158), Pair(94, 144), Pair(98, 109),
      Pair(70, 71), Pair(76, 101), Pair(74, 97), Pair(64, 149), Pair(69, 138), Pair(77, 108), Pair(93, 89), Pair(87, 87),
      Pair(69, 59), Pair(81, 73), Pair(77, 95), Pair(72, 89), Pair(76, 84), Pair(76, 90), Pair(98, 49), Pair(91, 33),
      Pair(72, 37), Pair(81, 38), Pair(86, 25), Pair(81, 65), Pair(83, 59), Pair(98, -9), Pair(104, -21), Pair(84, 8),
      Pair(84, 22), Pair(72, 27), Pair(78, 21), Pair(84, 38), Pair(88, 19), Pair(69, 15), Pair(76, -32), Pair(65, 20)
    },
    {
      Pair(982, -119), Pair(1022, 4), Pair(1018, 9), Pair(971, 32), Pair(1004, 10), Pair(1018, 6), Pair(967, 23), Pair(944, -93),
      Pair(962, -53), Pair(1080, 27), Pair(1066, 29), Pair(1019, 24), Pair(1043, 15), Pair(1105, 11), Pair(1083, 36), Pair(1021, -53),
      Pair(1411, -15), Pair(1546, 7), Pair(1548, 5), Pair(1514, -5), Pair(1489, -5), Pair(1520, 6), Pair(1520, 9), Pair(1438, -31),
      Pair(1420, -22), Pair(1521, -16), Pair(1501, 2), Pair(1432, 10), Pair(1418, 9), Pair(1458, 5), Pair(1473, -10), Pair(1378, -26),
      Pair(871, -31), Pair(964, -13), Pair(958, 5), Pair(838, 45), Pair(866, 29), Pair(904, 10), Pair(942, -9), Pair(842, -30),
      Pair(332, 1), Pair(392, 9), Pair(392, 25), Pair(340, 60), Pair(357, 47), Pair(362, 30), Pair(374, 9), Pair(345, -14),
      Pair(95, -9), Pair(58, 28), Pair(44, 47), Pair(-14, 70), Pair(10, 59), Pair(-1, 60), Pair(57, 30), Pair(79, -11),
      Pair(-274, -48), Pair(-244, 11), Pair(49, 18), Pair(-26, 31), Pair(32, -1), Pair(-9, 30), Pair(-263, 14), Pair(-261, -56)
    }
  }},
  {{ // Bucket 1
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(27, 81), Pair(-41, 106), Pair(-43, 94), Pair(14, 39), Pair(66, 19), Pair(27, 32), Pair(-68, 66), Pair(-105, 74),
      Pair(49, 103), Pair(45, 84), Pair(56, 75), Pair(48, 33), Pair(66, 34), Pair(62, 60), Pair(49, 63), Pair(6, 87),
      Pair(45, 70), Pair(37, 58), Pair(30, 53), Pair(50, 13), Pair(49, 24), Pair(58, 31), Pair(42, 45), Pair(0, 70),
      Pair(42, 56), Pair(29, 56), Pair(37, 37), Pair(48, 20), Pair(41, 32), Pair(46, 29), Pair(41, 34), Pair(3, 55),
      Pair(41, 43), Pair(27, 44), Pair(25, 43), Pair(19, 38), Pair(31, 46), Pair(17, 41), Pair(45, 29), Pair(4, 45),
      Pair(44, 52), Pair(42, 46), Pair(21, 62), Pair(16, 61), Pair(7, 69), Pair(26, 49), Pair(49, 30), Pair(11, 46),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-148, -1), Pair(-111, 84), Pair(-109, 117), Pair(-6, 90), Pair(7, 65), Pair(-98, 111), Pair(-4, 55), Pair(-111, -42),
      Pair(28, 54), Pair(20, 85), Pair(72, 72), Pair(89, 102), Pair(74, 98), Pair(86, 74), Pair(26, 87), Pair(57, 50),
      Pair(4, 80), Pair(58, 93), Pair(60, 126), Pair(89, 105), Pair(110, 101), Pair(96, 111), Pair(59, 85), Pair(86, 59),
      Pair(53, 97), Pair(75, 104), Pair(89, 121), Pair(90, 128), Pair(87, 136), Pair(103, 123), Pair(82, 112), Pair(71, 100),
      Pair(50, 85), Pair(61, 108), Pair(82, 127), Pair(83, 132), Pair(87, 125), Pair(95, 123), Pair(106, 98), Pair(52, 109),
      Pair(31, 51), Pair(54, 95), Pair(67, 102), Pair(74, 125), Pair(79, 122), Pair(68, 101), Pair(62, 93), Pair(42, 49),
      Pair(17, 72), Pair(38, 88), Pair(45, 91), Pair(56, 100), Pair(59, 103), Pair(58, 93), Pair(32, 101), Pair(33, 43),
      Pair(-71, 53), Pair(32, 62), Pair(14, 64), Pair(45, 96), Pair(39, 97), Pair(33, 93), Pair(33, 68), Pair(-17, 41)
    },
    {
      Pair(-3, 152), Pair(-38, 146), Pair(-93, 155), Pair(-116, 169), Pair(-121, 157), Pair(-33, 139), Pair(78, 122), Pair(-8, 166),
      Pair(2, 137), Pair(41, 134), Pair(47, 129), Pair(9, 142), Pair(19, 139), Pair(64, 124), Pair(21, 142), Pair(48, 125),
      Pair(61, 115), Pair(43, 140), Pair(74, 133), Pair(78, 120), Pair(96, 111), Pair(55, 139), Pair(88, 118), Pair(78, 120),
      Pair(52, 121), Pair(76, 115), Pair(62, 133), Pair(86, 125), Pair(83, 134), Pair(81, 127), Pair(78, 110), Pair(56, 133),
      Pair(64, 103), Pair(70, 106), Pair(82, 116), Pair(80, 122), Pair(90, 124), Pair(76, 121), Pair(75, 113), Pair(69, 107),
      Pair(66, 101), Pair(90, 111), Pair(78, 124), Pair(85, 127), Pair(83, 129), Pair(83, 121), Pair(82, 111), Pair(72, 92),
      Pair(76, 88), Pair(94, 95), Pair(90, 114), Pair(75, 127), Pair(79, 117), Pair(79, 115), Pair(92, 104), Pair(82, 66),
      Pair(97, 83), Pair(79, 120), Pair(61, 121), Pair(70, 108), Pair(55, 124), Pair(67, 111), Pair(60, 106), Pair(71, 110)
    },
    {
      Pair(158, 238), Pair(140, 252), Pair(98, 266), Pair(113, 270), Pair(69, 279), Pair(72, 290), Pair(143, 265), Pair(152, 254),
      Pair(114, 239), Pair(103, 249), Pair(123, 242), Pair(158, 253), Pair(138, 247), Pair(145, 226), Pair(88, 253), Pair(139, 230),
      Pair(107, 235), Pair(154, 221), Pair(126, 241), Pair(161, 230), Pair(185, 206), Pair(152, 227), Pair(185, 207), Pair(134, 226),
      Pair(110, 228), Pair(126, 222), Pair(131, 231), Pair(145, 234), Pair(143, 230), Pair(164, 215), Pair(135, 221), Pair(142, 219),
      Pair(89, 220), Pair(86, 239), Pair(90, 241), Pair(101, 237), Pair(115, 218), Pair(113, 219), Pair(101, 225), Pair(114, 209),
      Pair(86, 201), Pair(91, 214), Pair(79, 222), Pair(92, 222), Pair(99, 208), Pair(101, 205), Pair(115, 201), Pair(113, 183),
      Pair(64, 203), Pair(88, 194), Pair(75, 209), Pair(87, 211), Pair(93, 197), Pair(95, 192), Pair(105, 179), Pair(77, 194),
      Pair(99, 191), Pair(96, 192), Pair(99, 197), Pair(106, 202), Pair(102, 194), Pair(106, 182), Pair(106, 174), Pair(123, 166)
    },
    {
      Pair(251, 340), Pair(308, 309), Pair(242, 380), Pair(268, 381), Pair(261, 391), Pair(299, 378), Pair(294, 349), Pair(273, 380),
      Pair(249, 344), Pair(215, 373), Pair(269, 346), Pair(242, 388), Pair(230, 414), Pair(274, 364), Pair(225, 410), Pair(288, 364),
      Pair(255, 337), Pair(266, 341), Pair(261, 357), Pair(284, 338), Pair(293, 373), Pair(250, 440), Pair(316, 390), Pair(273, 379),
      Pair(268, 313), Pair(274, 359), Pair(271, 341), Pair(278, 376), Pair(277, 401), Pair(281, 416), Pair(299, 386), Pair(296, 349),
      Pair(287, 298), Pair(281, 323), Pair(291, 340), Pair(280, 383), Pair(278, 400), Pair(292, 347), Pair(302, 338), Pair(280, 363),
      Pair(279, 261), Pair(301, 281), Pair(296, 320), Pair(290, 332), Pair(283, 342), Pair(291, 348), Pair(294, 320), Pair(295, 304),
      Pair(270, 259), Pair(300, 240), Pair(309, 239), Pair(295, 293), Pair(295, 296), Pair(298, 247), Pair(317, 254), Pair(305, 255),
      Pair(297, 243), Pair(278, 245), Pair(302, 189), Pair(303, 250), Pair(267, 288), Pair(278, 232), Pair(298, 201), Pair(303, 244)
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
      Pair(81, 141), Pair(82, 132), Pair(122, 98), Pair(120, 78), Pair(132, 63), Pair(137, 56), Pair(26, 110), Pair(-17, 130),
      Pair(21, 134), Pair(47, 111), Pair(65, 84), Pair(87, 47), Pair(110, 44), Pair(141, 57), Pair(79, 79), Pair(20, 113),
      Pair(28, 99), Pair(45, 84), Pair(40, 67), Pair(64, 45), Pair(87, 46), Pair(82, 46), Pair(55, 71), Pair(28, 85),
      Pair(27, 82), Pair(39, 80), Pair(44, 59), Pair(48, 55), Pair(58, 52), Pair(74, 55), Pair(57, 66), Pair(29, 67),
      Pair(14, 74), Pair(24, 70), Pair(22, 67), Pair(28, 67), Pair(34, 70), Pair(48, 63), Pair(40, 61), Pair(7, 61),
      Pair(19, 82), Pair(29, 76), Pair(16, 79), Pair(14, 84), Pair(15, 92), Pair(62, 69), Pair(68, 63), Pair(6, 62),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-171, 65), Pair(-50, 107), Pair(-93, 146), Pair(23, 113), Pair(87, 104), Pair(59, 122), Pair(11, 95), Pair(-123, 56),
      Pair(40, 93), Pair(46, 109), Pair(81, 109), Pair(116, 134), Pair(133, 118), Pair(156, 82), Pair(81, 91), Pair(63, 95),
      Pair(31, 94), Pair(65, 120), Pair(103, 144), Pair(115, 132), Pair(132, 127), Pair(192, 120), Pair(123, 96), Pair(96, 80),
      Pair(63, 118), Pair(93, 127), Pair(116, 144), Pair(143, 145), Pair(133, 156), Pair(160, 132), Pair(119, 128), Pair(119, 104),
      Pair(56, 113), Pair(86, 131), Pair(105, 152), Pair(109, 157), Pair(120, 151), Pair(131, 144), Pair(140, 125), Pair(100, 115),
      Pair(34, 94), Pair(60, 126), Pair(76, 136), Pair(94, 154), Pair(106, 147), Pair(86, 131), Pair(77, 123), Pair(64, 103),
      Pair(20, 101), Pair(38, 121), Pair(49, 115), Pair(63, 130), Pair(68, 126), Pair(66, 110), Pair(50, 123), Pair(62, 106),
      Pair(-70, 72), Pair(24, 89), Pair(-2, 116), Pair(40, 126), Pair(38, 122), Pair(43, 111), Pair(43, 94), Pair(-49, 80)
    },
    {
      Pair(5, 168), Pair(22, 164), Pair(-61, 170), Pair(-36, 171), Pair(-47, 165), Pair(-62, 163), Pair(41, 147), Pair(-38, 171),
      Pair(17, 152), Pair(61, 151), Pair(63, 147), Pair(57, 151), Pair(33, 152), Pair(75, 148), Pair(29, 157), Pair(54, 144),
      Pair(67, 143), Pair(71, 153), Pair(104, 149), Pair(79, 145), Pair(115, 138), Pair(118, 155), Pair(118, 141), Pair(95, 139),
      Pair(54, 144), Pair(86, 145), Pair(77, 148), Pair(116, 144), Pair(97, 153), Pair(113, 139), Pair(90, 147), Pair(82, 139),
      Pair(60, 136), Pair(75, 134), Pair(99, 141), Pair(85, 149), Pair(105, 143), Pair(95, 143), Pair(95, 134), Pair(86, 127),
      Pair(65, 129), Pair(91, 135), Pair(82, 143), Pair(91, 150), Pair(89, 152), Pair(99, 141), Pair(94, 135), Pair(96, 128),
      Pair(78, 128), Pair(83, 119), Pair(94, 124), Pair(78, 135), Pair(81, 138), Pair(93, 119), Pair(118, 111), Pair(82, 102),
      Pair(79, 118), Pair(76, 141), Pair(63, 133), Pair(60, 140), Pair(57, 139), Pair(63, 132), Pair(59, 141), Pair(82, 121)
    },
    {
      Pair(148, 302), Pair(147, 309), Pair(134, 312), Pair(151, 302), Pair(157, 300), Pair(175, 307), Pair(203, 299), Pair(166, 309),
      Pair(135, 290), Pair(133, 298), Pair(159, 292), Pair(191, 285), Pair(187, 286), Pair(214, 265), Pair(163, 285), Pair(159, 283),
      Pair(120, 291), Pair(169, 279), Pair(167, 286), Pair(190, 267), Pair(207, 258), Pair(232, 266), Pair(250, 248), Pair(148, 279),
      Pair(118, 283), Pair(139, 287), Pair(162, 284), Pair(192, 271), Pair(190, 268), Pair(185, 268), Pair(174, 268), Pair(142, 277),
      Pair(100, 275), Pair(101, 295), Pair(104, 295), Pair(119, 286), Pair(123, 277), Pair(126, 282), Pair(139, 276), Pair(108, 271),
      Pair(85, 260), Pair(93, 279), Pair(94, 274), Pair(110, 265), Pair(107, 264), Pair(103, 269), Pair(134, 263), Pair(86, 265),
      Pair(52, 263), Pair(92, 253), Pair(99, 258), Pair(109, 249), Pair(107, 249), Pair(120, 239), Pair(117, 245), Pair(55, 255),
      Pair(101, 254), Pair(100, 262), Pair(106, 264), Pair(118, 253), Pair(121, 247), Pair(122, 253), Pair(111, 256), Pair(99, 251)
    },
    {
      Pair(276, 439), Pair(303, 436), Pair(310, 440), Pair(317, 443), Pair(313, 463), Pair(394, 425), Pair(419, 398), Pair(373, 405),
      Pair(272, 428), Pair(226, 482), Pair(281, 452), Pair(268, 484), Pair(262, 519), Pair(354, 464), Pair(249, 513), Pair(341, 439),
      Pair(273, 421), Pair(290, 420), Pair(279, 456), Pair(302, 444), Pair(315, 480), Pair(351, 479), Pair(347, 476), Pair(298, 459),
      Pair(295, 391), Pair(291, 458), Pair(287, 442), Pair(280, 493), Pair(297, 499), Pair(324, 482), Pair(330, 476), Pair(335, 429),
      Pair(285, 404), Pair(296, 438), Pair(291, 456), Pair(287, 484), Pair(291, 483), Pair(314, 448), Pair(326, 428), Pair(315, 419),
      Pair(288, 377), Pair(300, 409), Pair(296, 437), Pair(293, 439), Pair(297, 431), Pair(309, 423), Pair(327, 382), Pair(320, 361),
      Pair(284, 390), Pair(292, 386), Pair(307, 365), Pair(302, 398), Pair(305, 395), Pair(319, 345), Pair(325, 328), Pair(332, 327),
      Pair(300, 361), Pair(273, 384), Pair(284, 373), Pair(302, 387), Pair(304, 373), Pair(289, 365), Pair(291, 346), Pair(298, 342)
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
      Pair(136, 86), Pair(140, 90), Pair(113, 73), Pair(151, 49), Pair(117, 62), Pair(102, 60), Pair(43, 94), Pair(36, 88),
      Pair(29, 108), Pair(61, 98), Pair(90, 63), Pair(84, 44), Pair(123, 34), Pair(152, 56), Pair(82, 77), Pair(4, 98),
      Pair(18, 84), Pair(30, 83), Pair(42, 58), Pair(48, 48), Pair(59, 51), Pair(63, 55), Pair(68, 65), Pair(16, 67),
      Pair(3, 74), Pair(16, 81), Pair(29, 56), Pair(31, 57), Pair(26, 59), Pair(47, 58), Pair(41, 64), Pair(-21, 64),
      Pair(-10, 68), Pair(1, 75), Pair(16, 60), Pair(11, 68), Pair(3, 72), Pair(33, 58), Pair(37, 60), Pair(-38, 62),
      Pair(-9, 77), Pair(8, 75), Pair(10, 64), Pair(6, 60), Pair(12, 69), Pair(25, 65), Pair(27, 67), Pair(-31, 68),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-207, 13), Pair(-102, 62), Pair(-76, 96), Pair(68, 61), Pair(3, 69), Pair(47, 75), Pair(75, 38), Pair(-198, -3),
      Pair(-6, 48), Pair(-21, 76), Pair(51, 65), Pair(82, 89), Pair(107, 76), Pair(106, 45), Pair(45, 59), Pair(30, 38),
      Pair(8, 49), Pair(29, 73), Pair(75, 99), Pair(102, 89), Pair(118, 79), Pair(121, 86), Pair(115, 46), Pair(95, 30),
      Pair(36, 63), Pair(58, 84), Pair(102, 95), Pair(111, 104), Pair(126, 99), Pair(146, 83), Pair(145, 61), Pair(112, 48),
      Pair(19, 73), Pair(90, 84), Pair(64, 111), Pair(83, 116), Pair(94, 108), Pair(98, 103), Pair(127, 72), Pair(64, 73),
      Pair(-48, 71), Pair(29, 84), Pair(36, 93), Pair(73, 101), Pair(71, 101), Pair(67, 79), Pair(42, 80), Pair(16, 69),
      Pair(-123, 87), Pair(-29, 91), Pair(-1, 83), Pair(12, 89), Pair(17, 91), Pair(30, 72), Pair(11, 85), Pair(6, 67),
      Pair(-192, 72), Pair(-75, 67), Pair(-40, 77), Pair(11, 82), Pair(-29, 88), Pair(-57, 81), Pair(-27, 46), Pair(-68, 57)
    },
    {
      Pair(-102, 119), Pair(-37, 124), Pair(-76, 118), Pair(16, 114), Pair(-39, 112), Pair(-38, 110), Pair(54, 104), Pair(-47, 121),
      Pair(-34, 113), Pair(46, 108), Pair(33, 108), Pair(39, 105), Pair(14, 107), Pair(37, 108), Pair(31, 106), Pair(0, 104),
      Pair(24, 103), Pair(67, 103), Pair(70, 106), Pair(40, 113), Pair(64, 114), Pair(108, 108), Pair(95, 97), Pair(80, 92),
      Pair(8, 108), Pair(56, 104), Pair(32, 115), Pair(84, 108), Pair(69, 118), Pair(94, 97), Pair(88, 99), Pair(70, 95),
      Pair(-2, 104), Pair(73, 91), Pair(65, 101), Pair(62, 111), Pair(81, 104), Pair(58, 111), Pair(69, 95), Pair(77, 85),
      Pair(19, 104), Pair(47, 99), Pair(42, 106), Pair(55, 103), Pair(63, 102), Pair(68, 94), Pair(59, 95), Pair(41, 96),
      Pair(34, 89), Pair(29, 91), Pair(50, 98), Pair(53, 96), Pair(43, 97), Pair(42, 92), Pair(47, 85), Pair(10, 89),
      Pair(-23, 113), Pair(-1, 117), Pair(3, 102), Pair(-6, 106), Pair(8, 101), Pair(15, 92), Pair(-10, 100), Pair(-11, 108)
    },
    {
      Pair(81, 241), Pair(59, 257), Pair(32, 262), Pair(71, 247), Pair(91, 235), Pair(176, 220), Pair(151, 226), Pair(133, 232),
      Pair(111, 212), Pair(75, 233), Pair(100, 227), Pair(163, 212), Pair(146, 213), Pair(186, 189), Pair(176, 201), Pair(103, 219),
      Pair(74, 219), Pair(104, 218), Pair(109, 220), Pair(145, 199), Pair(161, 189), Pair(202, 193), Pair(160, 190), Pair(75, 216),
      Pair(57, 220), Pair(96, 222), Pair(89, 226), Pair(143, 205), Pair(162, 196), Pair(143, 196), Pair(131, 202), Pair(72, 212),
      Pair(32, 213), Pair(12, 240), Pair(40, 233), Pair(56, 220), Pair(56, 219), Pair(44, 224), Pair(54, 227), Pair(8, 222),
      Pair(14, 199), Pair(9, 222), Pair(-13, 221), Pair(35, 203), Pair(36, 201), Pair(23, 207), Pair(46, 208), Pair(-32, 210),
      Pair(-21, 207), Pair(9, 204), Pair(5, 209), Pair(41, 192), Pair(23, 196), Pair(46, 187), Pair(41, 184), Pair(-30, 211),
      Pair(26, 197), Pair(12, 215), Pair(18, 215), Pair(45, 200), Pair(52, 191), Pair(49, 201), Pair(32, 204), Pair(28, 190)
    },
    {
      Pair(111, 272), Pair(138, 265), Pair(148, 287), Pair(161, 281), Pair(151, 319), Pair(246, 251), Pair(172, 298), Pair(254, 228),
      Pair(130, 244), Pair(88, 299), Pair(158, 271), Pair(88, 339), Pair(120, 348), Pair(272, 256), Pair(107, 304), Pair(213, 225),
      Pair(122, 242), Pair(123, 261), Pair(129, 284), Pair(132, 290), Pair(172, 313), Pair(256, 270), Pair(195, 320), Pair(209, 225),
      Pair(99, 266), Pair(76, 328), Pair(144, 285), Pair(117, 347), Pair(177, 311), Pair(183, 326), Pair(200, 290), Pair(186, 252),
      Pair(151, 194), Pair(114, 286), Pair(131, 297), Pair(127, 331), Pair(153, 317), Pair(151, 300), Pair(178, 252), Pair(164, 212),
      Pair(89, 218), Pair(117, 259), Pair(110, 292), Pair(129, 265), Pair(119, 274), Pair(134, 286), Pair(164, 198), Pair(160, 187),
      Pair(148, 153), Pair(127, 209), Pair(147, 224), Pair(143, 254), Pair(148, 242), Pair(151, 215), Pair(156, 182), Pair(178, 168),
      Pair(123, 184), Pair(117, 216), Pair(134, 205), Pair(155, 200), Pair(142, 223), Pair(114, 230), Pair(76, 233), Pair(154, 197)
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
      Pair(154, 73), Pair(176, 87), Pair(120, 83), Pair(176, 63), Pair(139, 74), Pair(148, 73), Pair(61, 81), Pair(59, 90),
      Pair(78, 69), Pair(117, 61), Pair(80, 51), Pair(81, 33), Pair(57, 34), Pair(125, 44), Pair(100, 46), Pair(-2, 64),
      Pair(21, 62), Pair(34, 66), Pair(4, 55), Pair(35, 45), Pair(33, 49), Pair(63, 48), Pair(45, 52), Pair(4, 44),
      Pair(-13, 59), Pair(-5, 72), Pair(0, 49), Pair(32, 49), Pair(-14, 53), Pair(49, 43), Pair(18, 55), Pair(-28, 46),
      Pair(-14, 51), Pair(-2, 61), Pair(-5, 45), Pair(61, 32), Pair(29, 39), Pair(15, 46), Pair(-3, 55), Pair(-21, 42),
      Pair(-27, 60), Pair(-7, 64), Pair(-11, 53), Pair(20, 33), Pair(16, 46), Pair(-1, 57), Pair(0, 57), Pair(-40, 50),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-189, -4), Pair(-23, 35), Pair(-96, 75), Pair(7, 52), Pair(94, 30), Pair(-13, 61), Pair(-66, 80), Pair(-464, 31),
      Pair(-9, 35), Pair(16, 57), Pair(64, 49), Pair(85, 72), Pair(94, 65), Pair(79, 37), Pair(-36, 63), Pair(116, 36),
      Pair(27, 36), Pair(63, 49), Pair(67, 89), Pair(104, 80), Pair(171, 56), Pair(189, 62), Pair(142, 43), Pair(104, 31),
      Pair(69, 45), Pair(106, 59), Pair(120, 78), Pair(156, 75), Pair(151, 83), Pair(176, 68), Pair(132, 55), Pair(136, 40),
      Pair(-5, 59), Pair(30, 75), Pair(81, 86), Pair(111, 88), Pair(120, 86), Pair(110, 85), Pair(103, 68), Pair(43, 58),
      Pair(-15, 47), Pair(15, 73), Pair(38, 84), Pair(77, 89), Pair(92, 87), Pair(71, 75), Pair(35, 67), Pair(8, 62),
      Pair(-100, 70), Pair(-11, 83), Pair(12, 64), Pair(10, 73), Pair(9, 84), Pair(37, 63), Pair(16, 70), Pair(54, 37),
      Pair(-86, 71), Pair(-141, 78), Pair(-109, 82), Pair(16, 73), Pair(-46, 63), Pair(-65, 56), Pair(-137, 60), Pair(-41, 51)
    },
    {
      Pair(-62, 100), Pair(9, 94), Pair(75, 77), Pair(1, 86), Pair(22, 85), Pair(-6, 86), Pair(84, 86), Pair(48, 81),
      Pair(12, 90), Pair(37, 90), Pair(25, 87), Pair(48, 79), Pair(48, 84), Pair(104, 75), Pair(83, 85), Pair(20, 86),
      Pair(37, 88), Pair(42, 95), Pair(84, 91), Pair(88, 89), Pair(128, 82), Pair(192, 79), Pair(118, 83), Pair(84, 84),
      Pair(23, 95), Pair(36, 92), Pair(99, 84), Pair(143, 75), Pair(187, 74), Pair(134, 76), Pair(92, 83), Pair(49, 85),
      Pair(33, 93), Pair(45, 84), Pair(101, 75), Pair(76, 82), Pair(97, 78), Pair(83, 84), Pair(83, 75), Pair(87, 71),
      Pair(-35, 109), Pair(58, 87), Pair(50, 91), Pair(76, 84), Pair(53, 89), Pair(66, 82), Pair(38, 93), Pair(-22, 100),
      Pair(17, 91), Pair(-22, 93), Pair(56, 83), Pair(37, 86), Pair(35, 77), Pair(-11, 78), Pair(31, 72), Pair(8, 59),
      Pair(-64, 106), Pair(-54, 110), Pair(-64, 103), Pair(-19, 104), Pair(-9, 92), Pair(-18, 84), Pair(-64, 96), Pair(16, 94)
    },
    {
      Pair(67, 213), Pair(58, 229), Pair(38, 236), Pair(82, 215), Pair(132, 200), Pair(180, 192), Pair(141, 201), Pair(194, 187),
      Pair(85, 192), Pair(78, 204), Pair(112, 196), Pair(148, 186), Pair(172, 177), Pair(148, 183), Pair(126, 190), Pair(184, 168),
      Pair(99, 186), Pair(145, 182), Pair(116, 190), Pair(187, 160), Pair(181, 161), Pair(174, 175), Pair(153, 178), Pair(151, 176),
      Pair(62, 190), Pair(69, 201), Pair(82, 202), Pair(116, 187), Pair(131, 179), Pair(174, 170), Pair(128, 180), Pair(88, 193),
      Pair(33, 176), Pair(26, 200), Pair(55, 193), Pair(30, 198), Pair(61, 184), Pair(21, 202), Pair(25, 204), Pair(19, 187),
      Pair(-29, 176), Pair(-4, 197), Pair(-42, 209), Pair(6, 189), Pair(23, 183), Pair(-9, 192), Pair(-49, 210), Pair(2, 182),
      Pair(-82, 196), Pair(-67, 205), Pair(-1, 192), Pair(-47, 196), Pair(6, 183), Pair(-21, 190), Pair(-26, 197), Pair(-72, 208),
      Pair(4, 177), Pair(-24, 203), Pair(-7, 201), Pair(1, 190), Pair(24, 179), Pair(16, 194), Pair(-41, 207), Pair(-2, 184)
    },
    {
      Pair(134, 138), Pair(30, 188), Pair(71, 172), Pair(93, 149), Pair(110, 159), Pair(77, 178), Pair(195, 135), Pair(45, 200),
      Pair(16, 143), Pair(72, 156), Pair(17, 198), Pair(-82, 271), Pair(-19, 261), Pair(70, 205), Pair(29, 273), Pair(206, 72),
      Pair(-11, 165), Pair(-55, 237), Pair(149, 143), Pair(-16, 246), Pair(173, 142), Pair(121, 202), Pair(76, 195), Pair(231, 63),
      Pair(-65, 201), Pair(-52, 247), Pair(11, 231), Pair(37, 253), Pair(130, 196), Pair(58, 226), Pair(118, 140), Pair(195, 49),
      Pair(-78, 180), Pair(-20, 187), Pair(-45, 235), Pair(-22, 250), Pair(57, 203), Pair(33, 205), Pair(189, 52), Pair(205, 7),
      Pair(-151, 148), Pair(8, 130), Pair(-8, 220), Pair(1, 211), Pair(1, 207), Pair(58, 170), Pair(-64, 164), Pair(85, 51),
      Pair(-158, 191), Pair(33, 155), Pair(52, 136), Pair(-2, 226), Pair(9, 187), Pair(40, 128), Pair(-64, 182), Pair(-13, 147),
      Pair(-48, 106), Pair(54, 68), Pair(-38, 189), Pair(-41, 185), Pair(-31, 189), Pair(-16, 179), Pair(-84, 213), Pair(56, 179)
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
      Pair(125, 107), Pair(204, 114), Pair(223, 98), Pair(124, 119), Pair(166, 107), Pair(178, 93), Pair(137, 123), Pair(56, 104),
      Pair(63, 81), Pair(135, 78), Pair(162, 58), Pair(46, 75), Pair(119, 56), Pair(115, 59), Pair(129, 64), Pair(43, 60),
      Pair(22, 78), Pair(0, 95), Pair(46, 65), Pair(-31, 84), Pair(45, 69), Pair(71, 58), Pair(42, 80), Pair(4, 58),
      Pair(1, 75), Pair(-18, 97), Pair(29, 68), Pair(-9, 75), Pair(21, 67), Pair(9, 71), Pair(23, 86), Pair(-34, 66),
      Pair(-8, 67), Pair(-19, 83), Pair(22, 62), Pair(6, 75), Pair(40, 66), Pair(1, 69), Pair(2, 82), Pair(-27, 60),
      Pair(-24, 77), Pair(-15, 84), Pair(16, 63), Pair(-67, 84), Pair(30, 74), Pair(-10, 78), Pair(10, 83), Pair(-50, 67),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-35, -70), Pair(232, -27), Pair(187, 11), Pair(71, -5), Pair(163, -10), Pair(38, 21), Pair(-205, 40), Pair(209, -82),
      Pair(-42, 7), Pair(171, -6), Pair(84, 11), Pair(125, 32), Pair(147, 24), Pair(204, -19), Pair(128, 5), Pair(30, -12),
      Pair(25, 3), Pair(91, 20), Pair(147, 46), Pair(78, 56), Pair(193, 28), Pair(240, 28), Pair(162, 8), Pair(194, -22),
      Pair(24, 16), Pair(45, 26), Pair(112, 47), Pair(98, 62), Pair(68, 64), Pair(198, 32), Pair(118, 15), Pair(65, 10),
      Pair(-50, 27), Pair(39, 47), Pair(63, 58), Pair(102, 58), Pair(128, 55), Pair(79, 50), Pair(74, 36), Pair(71, 13),
      Pair(-26, 25), Pair(-52, 56), Pair(63, 51), Pair(90, 57), Pair(23, 61), Pair(63, 42), Pair(20, 33), Pair(3, 2),
      Pair(-97, 44), Pair(-127, 64), Pair(-37, 40), Pair(-20, 50), Pair(-17, 53), Pair(-43, 40), Pair(34, 19), Pair(-104, 49),
      Pair(-111, -1), Pair(-112, 42), Pair(-298, 75), Pair(-181, 52), Pair(16, 23), Pair(-166, 37), Pair(-137, 42), Pair(-39, -6)
    },
    {
      Pair(-52, 53), Pair(148, 40), Pair(95, 36), Pair(34, 49), Pair(46, 32), Pair(-3, 51), Pair(222, 8), Pair(116, 40),
      Pair(-25, 65), Pair(22, 56), Pair(150, 36), Pair(140, 32), Pair(81, 48), Pair(208, 28), Pair(57, 64), Pair(25, 60),
      Pair(51, 47), Pair(89, 63), Pair(145, 46), Pair(128, 45), Pair(200, 32), Pair(211, 50), Pair(240, 28), Pair(62, 56),
      Pair(30, 56), Pair(107, 47), Pair(117, 45), Pair(138, 42), Pair(212, 33), Pair(189, 28), Pair(136, 44), Pair(127, 41),
      Pair(-78, 64), Pair(25, 52), Pair(102, 42), Pair(182, 29), Pair(196, 22), Pair(189, 39), Pair(93, 39), Pair(-6, 59),
      Pair(-29, 73), Pair(44, 55), Pair(69, 49), Pair(119, 30), Pair(164, 31), Pair(82, 39), Pair(153, 37), Pair(-56, 69),
      Pair(45, 41), Pair(29, 51), Pair(89, 32), Pair(62, 44), Pair(77, 34), Pair(25, 36), Pair(-33, 48), Pair(48, 31),
      Pair(-74, 76), Pair(109, 54), Pair(-113, 91), Pair(-25, 70), Pair(-22, 68), Pair(-73, 63), Pair(20, 55), Pair(50, 46)
    },
    {
      Pair(170, 120), Pair(170, 145), Pair(116, 164), Pair(109, 154), Pair(47, 167), Pair(235, 123), Pair(143, 154), Pair(244, 121),
      Pair(146, 116), Pair(120, 143), Pair(182, 132), Pair(212, 112), Pair(178, 119), Pair(253, 103), Pair(153, 143), Pair(242, 109),
      Pair(121, 116), Pair(108, 133), Pair(101, 142), Pair(208, 96), Pair(250, 85), Pair(258, 104), Pair(149, 129), Pair(169, 112),
      Pair(158, 101), Pair(152, 117), Pair(27, 155), Pair(162, 110), Pair(107, 125), Pair(174, 113), Pair(111, 133), Pair(117, 118),
      Pair(-6, 131), Pair(-4, 155), Pair(19, 158), Pair(-1, 160), Pair(55, 137), Pair(83, 131), Pair(44, 147), Pair(56, 127),
      Pair(-30, 130), Pair(-17, 154), Pair(-92, 171), Pair(-40, 151), Pair(-62, 161), Pair(44, 135), Pair(-30, 170), Pair(-28, 149),
      Pair(-65, 143), Pair(-117, 162), Pair(-40, 162), Pair(-40, 149), Pair(-43, 150), Pair(44, 131), Pair(-111, 182), Pair(-48, 153),
      Pair(32, 116), Pair(-30, 153), Pair(-93, 179), Pair(-21, 153), Pair(-34, 154), Pair(-16, 160), Pair(-92, 185), Pair(-52, 157)
    },
    {
      Pair(204, 37), Pair(136, 128), Pair(190, 112), Pair(141, 118), Pair(161, 132), Pair(69, 147), Pair(94, 114), Pair(182, 62),
      Pair(-148, 233), Pair(56, 166), Pair(45, 165), Pair(128, 147), Pair(228, 101), Pair(300, 24), Pair(218, 106), Pair(89, 164),
      Pair(0, 127), Pair(137, 107), Pair(137, 150), Pair(88, 144), Pair(264, 62), Pair(306, 31), Pair(62, 157), Pair(249, 2),
      Pair(-125, 182), Pair(-53, 180), Pair(185, 99), Pair(170, 116), Pair(54, 164), Pair(85, 146), Pair(-112, 226), Pair(-77, 128),
      Pair(-78, 203), Pair(-143, 210), Pair(-118, 226), Pair(-18, 227), Pair(-12, 195), Pair(183, 66), Pair(-57, 161), Pair(17, 84),
      Pair(-197, 174), Pair(-138, 240), Pair(-77, 197), Pair(78, 126), Pair(-122, 239), Pair(-8, 129), Pair(-89, 163), Pair(-52, 98),
      Pair(32, 109), Pair(-57, 165), Pair(82, 60), Pair(64, 135), Pair(-15, 146), Pair(-151, 214), Pair(11, 156), Pair(60, 2),
      Pair(35, 119), Pair(-194, 212), Pair(5, 105), Pair(-56, 143), Pair(8, 103), Pair(10, 99), Pair(-143, 187), Pair(82, 80)
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
      Pair(12, 130), Pair(299, 136), Pair(203, 115), Pair(191, 137), Pair(10, 143), Pair(167, 109), Pair(-49, 174), Pair(115, 109),
      Pair(25, 91), Pair(226, 88), Pair(292, 42), Pair(156, 73), Pair(216, 36), Pair(127, 60), Pair(119, 92), Pair(85, 58),
      Pair(-103, 86), Pair(28, 92), Pair(45, 53), Pair(4, 72), Pair(31, 73), Pair(35, 56), Pair(-3, 89), Pair(-38, 59),
      Pair(-91, 70), Pair(57, 83), Pair(71, 51), Pair(20, 85), Pair(48, 64), Pair(39, 58), Pair(3, 82), Pair(-69, 57),
      Pair(-51, 46), Pair(47, 63), Pair(49, 27), Pair(25, 71), Pair(26, 50), Pair(87, 46), Pair(-16, 73), Pair(-26, 43),
      Pair(-130, 79), Pair(-18, 72), Pair(10, 46), Pair(-118, 88), Pair(-119, 57), Pair(3, 72), Pair(-38, 81), Pair(-111, 63),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(-54, -81), Pair(-3, -2), Pair(131, -51), Pair(38, -20), Pair(-32, 34), Pair(183, -49), Pair(91, -27), Pair(-17, -21),
      Pair(22, -19), Pair(101, -55), Pair(-61, 28), Pair(97, 17), Pair(147, -23), Pair(-95, 15), Pair(16, -5), Pair(-32, -72),
      Pair(-8, -57), Pair(0, -2), Pair(82, 47), Pair(92, 22), Pair(388, -47), Pair(184, 15), Pair(304, -61), Pair(121, -67),
      Pair(108, -69), Pair(-42, 5), Pair(126, 17), Pair(122, 54), Pair(107, 37), Pair(-17, 67), Pair(269, -35), Pair(136, -72),
      Pair(25, -14), Pair(-2, 32), Pair(43, 43), Pair(-3, 32), Pair(96, 32), Pair(-42, 35), Pair(-74, -12), Pair(-37, -37),
      Pair(-128, 30), Pair(7, 27), Pair(-34, 42), Pair(44, 33), Pair(104, 13), Pair(-66, 43), Pair(2, -17), Pair(-109, -16),
      Pair(67, -36), Pair(14, 31), Pair(-84, -8), Pair(-160, 40), Pair(-202, 11), Pair(-33, -17), Pair(-111, -20), Pair(46, -5),
      Pair(-135, -114), Pair(-146, -1), Pair(13, -43), Pair(-34, 21), Pair(87, -49), Pair(-290, 12), Pair(-330, -20), Pair(-4, -49)
    },
    {
      Pair(7, -29), Pair(76, -23), Pair(52, -10), Pair(301, -20), Pair(-211, 34), Pair(-75, 34), Pair(9, -18), Pair(48, 29),
      Pair(-153, 4), Pair(47, 4), Pair(26, 4), Pair(109, -6), Pair(10, 31), Pair(11, 7), Pair(199, -6), Pair(69, -18),
      Pair(-47, -5), Pair(-35, 48), Pair(107, 0), Pair(15, 14), Pair(145, 1), Pair(48, 23), Pair(13, -2), Pair(36, 0),
      Pair(-109, 37), Pair(34, 11), Pair(74, -2), Pair(123, -25), Pair(92, -5), Pair(49, -12), Pair(58, -10), Pair(233, -12),
      Pair(20, -2), Pair(163, -13), Pair(53, 0), Pair(200, -33), Pair(137, -45), Pair(166, -33), Pair(-36, 29), Pair(356, -31),
      Pair(3, 27), Pair(162, -14), Pair(44, 27), Pair(62, -15), Pair(-58, 14), Pair(-5, 10), Pair(-75, 43), Pair(-12, -5),
      Pair(-46, -5), Pair(145, -20), Pair(232, -48), Pair(4, -14), Pair(30, -10), Pair(39, -9), Pair(-156, 15), Pair(-31, 3),
      Pair(-88, 44), Pair(11, 0), Pair(-127, 50), Pair(-156, 38), Pair(-145, 34), Pair(-120, 25), Pair(-38, -8), Pair(-16, 8)
    },
    {
      Pair(268, -14), Pair(201, 53), Pair(168, 46), Pair(12, 72), Pair(158, 44), Pair(68, 87), Pair(169, 54), Pair(390, 7),
      Pair(243, 1), Pair(196, 35), Pair(109, 42), Pair(105, 43), Pair(196, 34), Pair(135, 53), Pair(202, 33), Pair(223, 37),
      Pair(70, 43), Pair(114, 49), Pair(129, 46), Pair(131, 35), Pair(193, 28), Pair(303, 24), Pair(134, 57), Pair(109, 55),
      Pair(102, 32), Pair(25, 66), Pair(101, 48), Pair(-192, 118), Pair(93, 51), Pair(282, 15), Pair(359, 10), Pair(24, 61),
      Pair(-82, 82), Pair(123, 32), Pair(166, 32), Pair(37, 61), Pair(273, -16), Pair(78, 75), Pair(110, 54), Pair(32, 56),
      Pair(-105, 60), Pair(-48, 68), Pair(71, 35), Pair(-27, 55), Pair(-139, 95), Pair(-85, 77), Pair(97, 60), Pair(-84, 75),
      Pair(-114, 62), Pair(-3, 51), Pair(-29, 68), Pair(5, 34), Pair(-31, 56), Pair(-13, 66), Pair(-154, 99), Pair(-126, 94),
      Pair(-132, 67), Pair(-35, 70), Pair(64, 37), Pair(-88, 79), Pair(-16, 38), Pair(-19, 78), Pair(56, 62), Pair(-133, 97)
    },
    {
      Pair(231, -15), Pair(-186, 232), Pair(39, 111), Pair(210, 21), Pair(209, 23), Pair(-59, 153), Pair(175, 15), Pair(187, -9),
      Pair(147, 44), Pair(-94, 197), Pair(126, 95), Pair(97, 117), Pair(78, 158), Pair(20, 146), Pair(33, 130), Pair(31, 137),
      Pair(126, 99), Pair(189, 68), Pair(120, 112), Pair(262, 42), Pair(184, 88), Pair(129, 126), Pair(212, 66), Pair(38, 75),
      Pair(91, 50), Pair(58, 138), Pair(96, 95), Pair(91, 95), Pair(99, 106), Pair(29, 121), Pair(147, 117), Pair(70, 73),
      Pair(55, 35), Pair(81, 64), Pair(53, 77), Pair(-8, 157), Pair(3, 80), Pair(96, 117), Pair(-5, 154), Pair(114, 41),
      Pair(150, 62), Pair(64, 95), Pair(-17, 90), Pair(57, 79), Pair(-178, 181), Pair(-99, 151), Pair(7, 62), Pair(8, 90),
      Pair(168, -13), Pair(51, 46), Pair(10, 76), Pair(-54, 140), Pair(-120, 164), Pair(68, 74), Pair(43, 44), Pair(-9, 68),
      Pair(-8, 76), Pair(12, 94), Pair(59, 78), Pair(-206, 169), Pair(-7, 89), Pair(-119, 149), Pair(31, 49), Pair(-114, 109)
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
      Pair(-15, 67), Pair(2, 64), Pair(6, 93), Pair(9, 108), Pair(12, 118), Pair(16, 125), Pair(20, 124), Pair(26, 116),
      Pair(31, 104)
  },
  {
      Pair(116, 177), Pair(124, 138), Pair(126, 170), Pair(130, 185), Pair(134, 194), Pair(136, 204), Pair(140, 202), Pair(147, 194),
      Pair(158, 175)
  },
  {
      Pair(108, 181), Pair(119, 137), Pair(121, 170), Pair(126, 182), Pair(128, 191), Pair(132, 199), Pair(138, 198), Pair(142, 190),
      Pair(149, 176)
  },
  {
      Pair(95, 189), Pair(119, 117), Pair(111, 152), Pair(108, 173), Pair(116, 179), Pair(112, 188), Pair(115, 188), Pair(126, 178),
      Pair(134, 163)
  },
  {
      Pair(104, 183), Pair(130, 81), Pair(105, 142), Pair(116, 153), Pair(106, 166), Pair(103, 174), Pair(96, 175), Pair(93, 170),
      Pair(119, 149)
  },
  {
      Pair(130, 158), Pair(46, 124), Pair(91, 136), Pair(103, 142), Pair(98, 148), Pair(103, 153), Pair(90, 155), Pair(90, 145),
      Pair(103, 124)
  },
  {
      Pair(116, 122), Pair(-92, 100), Pair(23, 116), Pair(110, 88), Pair(35, 116), Pair(77, 108), Pair(80, 98), Pair(14, 98),
      Pair(58, 69)
  }
}};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {{
  {
      Pair(-11, 38), Pair(-4, 2), Pair(2, 31), Pair(6, 52), Pair(11, 72), Pair(14, 90), Pair(15, 99), Pair(15, 105),
      Pair(18, 111), Pair(23, 113), Pair(32, 112), Pair(52, 106), Pair(61, 120), Pair(97, 85)
  },
  {
      Pair(108, 112), Pair(115, 110), Pair(125, 128), Pair(130, 147), Pair(135, 166), Pair(138, 179), Pair(139, 187), Pair(141, 192),
      Pair(140, 201), Pair(141, 206), Pair(154, 197), Pair(162, 191), Pair(165, 212), Pair(237, 171)
  },
  {
      Pair(88, 168), Pair(105, 104), Pair(107, 130), Pair(113, 147), Pair(118, 166), Pair(122, 180), Pair(122, 189), Pair(121, 198),
      Pair(124, 204), Pair(132, 206), Pair(139, 203), Pair(170, 194), Pair(152, 213), Pair(192, 181)
  },
  {
      Pair(79, 181), Pair(105, 85), Pair(92, 122), Pair(94, 141), Pair(100, 154), Pair(105, 169), Pair(99, 182), Pair(105, 188),
      Pair(104, 194), Pair(113, 194), Pair(122, 192), Pair(136, 186), Pair(196, 190), Pair(202, 163)
  },
  {
      Pair(11, 210), Pair(112, 59), Pair(123, 98), Pair(93, 125), Pair(106, 139), Pair(121, 150), Pair(114, 164), Pair(110, 171),
      Pair(118, 174), Pair(113, 179), Pair(105, 182), Pair(120, 172), Pair(81, 211), Pair(197, 160)
  },
  {
      Pair(118, 158), Pair(191, 45), Pair(114, 84), Pair(131, 101), Pair(143, 114), Pair(115, 130), Pair(116, 147), Pair(127, 146),
      Pair(109, 156), Pair(139, 149), Pair(131, 152), Pair(139, 147), Pair(60, 192), Pair(87, 154)
  },
  {
      Pair(-67, 158), Pair(49, 13), Pair(105, 32), Pair(39, 67), Pair(110, 75), Pair(52, 96), Pair(57, 107), Pair(89, 99),
      Pair(90, 108), Pair(106, 105), Pair(107, 112), Pair(102, 117), Pair(47, 146), Pair(93, 147)
  }
}};

constexpr RookMobilityTable<ScorePair> kRookMobility = {{
  {
      Pair(-41, 23), Pair(-33, 44), Pair(-32, 82), Pair(-31, 101), Pair(-29, 112), Pair(-23, 115), Pair(-17, 122), Pair(-10, 126),
      Pair(-5, 132), Pair(-1, 137), Pair(4, 140), Pair(6, 145), Pair(8, 149), Pair(30, 134), Pair(75, 115)
  },
  {
      Pair(137, 173), Pair(144, 206), Pair(145, 231), Pair(146, 258), Pair(148, 274), Pair(153, 283), Pair(160, 291), Pair(168, 291),
      Pair(169, 297), Pair(182, 298), Pair(181, 303), Pair(183, 308), Pair(184, 308), Pair(218, 289), Pair(266, 261)
  },
  {
      Pair(147, 241), Pair(153, 225), Pair(148, 263), Pair(150, 285), Pair(151, 299), Pair(157, 305), Pair(156, 316), Pair(159, 316),
      Pair(165, 319), Pair(174, 324), Pair(182, 327), Pair(187, 328), Pair(198, 323), Pair(219, 313), Pair(257, 291)
  },
  {
      Pair(168, 199), Pair(127, 212), Pair(146, 235), Pair(131, 265), Pair(136, 279), Pair(143, 285), Pair(136, 299), Pair(138, 298),
      Pair(145, 299), Pair(150, 305), Pair(157, 307), Pair(166, 308), Pair(172, 307), Pair(193, 293), Pair(245, 267)
  },
  {
      Pair(93, 222), Pair(125, 185), Pair(106, 223), Pair(133, 238), Pair(116, 263), Pair(107, 272), Pair(114, 279), Pair(122, 276),
      Pair(133, 275), Pair(134, 281), Pair(139, 284), Pair(148, 287), Pair(171, 279), Pair(189, 269), Pair(277, 227)
  },
  {
      Pair(192, 140), Pair(-14, 217), Pair(119, 194), Pair(61, 234), Pair(73, 238), Pair(43, 261), Pair(52, 265), Pair(96, 250),
      Pair(112, 250), Pair(107, 256), Pair(109, 260), Pair(125, 257), Pair(144, 254), Pair(167, 241), Pair(292, 186)
  },
  {
      Pair(132, 94), Pair(-74, 148), Pair(62, 130), Pair(140, 131), Pair(-27, 221), Pair(5, 220), Pair(22, 231), Pair(54, 204),
      Pair(28, 229), Pair(-20, 241), Pair(-9, 243), Pair(46, 231), Pair(187, 191), Pair(248, 174), Pair(345, 139)
  }
}};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {{
  {
      Pair(35, 294), Pair(67, 251), Pair(92, 191), Pair(100, 160), Pair(100, 191), Pair(101, 205), Pair(102, 229), Pair(103, 248),
      Pair(104, 264), Pair(106, 270), Pair(107, 279), Pair(109, 282), Pair(110, 284), Pair(111, 286), Pair(110, 289), Pair(111, 286),
      Pair(111, 283), Pair(113, 277), Pair(115, 273), Pair(123, 259), Pair(122, 250), Pair(137, 223), Pair(140, 201), Pair(147, 195),
      Pair(85, 204), Pair(190, 145), Pair(235, 147), Pair(184, 137)
  },
  {
      Pair(394, 185), Pair(350, 416), Pair(356, 329), Pair(357, 346), Pair(360, 335), Pair(360, 363), Pair(362, 388), Pair(362, 409),
      Pair(366, 422), Pair(369, 430), Pair(371, 437), Pair(371, 445), Pair(373, 444), Pair(373, 451), Pair(369, 454), Pair(367, 456),
      Pair(368, 458), Pair(372, 437), Pair(362, 453), Pair(362, 443), Pair(403, 402), Pair(360, 428), Pair(329, 435), Pair(325, 422),
      Pair(293, 403), Pair(408, 379), Pair(341, 456), Pair(247, 511)
  },
  {
      Pair(323, 598), Pair(282, 626), Pair(314, 535), Pair(331, 463), Pair(332, 474), Pair(340, 475), Pair(345, 486), Pair(341, 513),
      Pair(344, 521), Pair(346, 527), Pair(348, 533), Pair(352, 533), Pair(351, 536), Pair(353, 541), Pair(354, 541), Pair(357, 539),
      Pair(356, 537), Pair(364, 526), Pair(367, 521), Pair(372, 508), Pair(401, 479), Pair(404, 465), Pair(426, 435), Pair(412, 432),
      Pair(404, 427), Pair(370, 436), Pair(437, 441), Pair(333, 466)
  },
  {
      Pair(213, 429), Pair(235, 482), Pair(262, 405), Pair(222, 346), Pair(222, 385), Pair(247, 346), Pair(260, 356), Pair(266, 349),
      Pair(269, 356), Pair(270, 365), Pair(268, 376), Pair(272, 374), Pair(258, 391), Pair(250, 401), Pair(251, 394), Pair(262, 396),
      Pair(231, 414), Pair(239, 407), Pair(258, 380), Pair(294, 361), Pair(297, 341), Pair(319, 325), Pair(318, 320), Pair(414, 255),
      Pair(270, 320), Pair(301, 298), Pair(275, 296), Pair(229, 332)
  },
  {
      Pair(152, 255), Pair(206, 281), Pair(59, 298), Pair(127, 221), Pair(81, 296), Pair(220, 128), Pair(197, 203), Pair(155, 271),
      Pair(191, 250), Pair(199, 231), Pair(169, 290), Pair(154, 291), Pair(136, 307), Pair(127, 311), Pair(109, 315), Pair(80, 346),
      Pair(87, 322), Pair(120, 302), Pair(100, 317), Pair(143, 288), Pair(172, 255), Pair(273, 198), Pair(225, 207), Pair(493, 56),
      Pair(254, 170), Pair(283, 122), Pair(89, 277), Pair(148, 217)
  },
  {
      Pair(45, 85), Pair(176, 296), Pair(171, 237), Pair(-10, 13), Pair(195, -3), Pair(53, 228), Pair(60, 299), Pair(141, 262),
      Pair(10, 278), Pair(-2, 336), Pair(119, 284), Pair(-2, 349), Pair(85, 311), Pair(61, 322), Pair(90, 298), Pair(59, 300),
      Pair(143, 253), Pair(81, 281), Pair(133, 257), Pair(86, 278), Pair(177, 218), Pair(324, 132), Pair(344, 120), Pair(216, 179),
      Pair(309, 131), Pair(167, 175), Pair(158, 180), Pair(131, 214)
  },
  {
      Pair(-7, -14), Pair(3, 51), Pair(135, 261), Pair(129, 211), Pair(57, 53), Pair(167, 78), Pair(-10, 8), Pair(44, 105),
      Pair(77, 262), Pair(163, 185), Pair(138, 179), Pair(-24, 245), Pair(219, 116), Pair(99, 256), Pair(161, 175), Pair(111, 218),
      Pair(-2, 280), Pair(166, 211), Pair(45, 271), Pair(170, 197), Pair(270, 125), Pair(197, 157), Pair(44, 207), Pair(172, 172),
      Pair(258, 164), Pair(172, 161), Pair(-12, 265), Pair(96, 229)
  }
}};

constexpr KingBuckets<RankTable<ScorePair>> kPassedPawnBonus = {{
  {
      Pair(0, 0), Pair(-28, -66), Pair(-21, -69), Pair(-5, -38), Pair(28, 4), Pair(49, 77), Pair(150, 142), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-7, -31), Pair(-24, -18), Pair(-10, 11), Pair(20, 49), Pair(38, 114), Pair(85, 97), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-46, -32), Pair(-48, -22), Pair(-31, 7), Pair(13, 38), Pair(50, 106), Pair(130, 144), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-57, -43), Pair(-52, -26), Pair(-43, 11), Pair(10, 39), Pair(52, 104), Pair(136, 146), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-70, -45), Pair(-60, -39), Pair(-54, 2), Pair(-10, 42), Pair(52, 99), Pair(160, 113), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-100, -28), Pair(-99, -32), Pair(-77, -1), Pair(-17, 39), Pair(44, 107), Pair(162, 91), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-99, 1), Pair(-120, 1), Pair(-107, 19), Pair(19, 25), Pair(-37, 96), Pair(224, 47), Pair(0, 0)
  }
}};

constexpr KingBuckets<RankTable<ScorePair>> kPawnPhalanxBonus = {{
  {
      Pair(0, 0), Pair(7, -5), Pair(15, 8), Pair(15, 23), Pair(42, 106), Pair(126, 152), Pair(83, 303), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(7, 7), Pair(15, 13), Pair(11, 25), Pair(25, 87), Pair(43, 175), Pair(47, 278), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(15, -1), Pair(22, 6), Pair(15, 21), Pair(40, 92), Pair(69, 179), Pair(62, 372), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(10, -1), Pair(17, 5), Pair(21, 22), Pair(40, 86), Pair(129, 153), Pair(-84, 320), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(8, -6), Pair(14, -2), Pair(30, 10), Pair(54, 83), Pair(16, 186), Pair(-174, 353), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-1, -13), Pair(-23, 0), Pair(4, 12), Pair(51, 66), Pair(20, 168), Pair(-207, 286), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-23, 7), Pair(-18, 6), Pair(-25, 18), Pair(0, 66), Pair(-205, 195), Pair(-52, 26), Pair(0, 0)
  }
}};

constexpr KingBuckets<RankTable<ScorePair>> kDefendedPawnBonus = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(20, 18), Pair(11, 13), Pair(19, 16), Pair(42, 77), Pair(182, 69), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(17, 16), Pair(11, 9), Pair(16, 18), Pair(35, 63), Pair(285, 28), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(28, 6), Pair(20, 3), Pair(20, 12), Pair(52, 56), Pair(203, 40), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(34, 1), Pair(25, -3), Pair(19, 10), Pair(52, 52), Pair(241, 47), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(40, -6), Pair(33, -6), Pair(29, 3), Pair(77, 38), Pair(232, 43), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(36, -8), Pair(27, -13), Pair(46, 1), Pair(91, 35), Pair(169, 14), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(-21, 1), Pair(-23, 4), Pair(-2, 11), Pair(192, -34), Pair(157, 18), Pair(0, 0)
  }
}};

constexpr KingBuckets<FileTable<ScorePair>> kDoubledPawnPenalty = {{
  {
      Pair(-36, -31), Pair(-20, -15), Pair(-9, -14), Pair(-10, -23), Pair(-21, -13), Pair(-27, 9), Pair(-23, 11), Pair(-57, -17)
  },
  {
      Pair(-53, -29), Pair(-11, -17), Pair(-11, -12), Pair(-16, -5), Pair(-6, -9), Pair(-9, -15), Pair(-25, -14), Pair(-19, -32)
  },
  {
      Pair(-20, -55), Pair(-12, -24), Pair(-2, -20), Pair(-7, -15), Pair(-19, -8), Pair(-17, -12), Pair(1, -20), Pair(-21, -43)
  },
  {
      Pair(-21, -62), Pair(-7, -31), Pair(1, -26), Pair(0, -21), Pair(-6, -19), Pair(-16, -23), Pair(-15, -30), Pair(-16, -52)
  },
  {
      Pair(-10, -84), Pair(12, -48), Pair(28, -44), Pair(5, -38), Pair(24, -35), Pair(13, -39), Pair(4, -44), Pair(12, -69)
  },
  {
      Pair(24, -100), Pair(0, -58), Pair(-16, -43), Pair(52, -75), Pair(16, -49), Pair(5, -48), Pair(-8, -54), Pair(30, -83)
  },
  {
      Pair(101, -115), Pair(-148, -38), Pair(-177, -21), Pair(-151, -36), Pair(54, -54), Pair(-87, -34), Pair(-80, -28), Pair(-35, -78)
  }
}};

constexpr KingBuckets<FileTable<ScorePair>> kIsolatedPawnPenalty = {{
  {
      Pair(8, -12), Pair(-6, -12), Pair(-8, -16), Pair(-10, -20), Pair(-10, -21), Pair(-8, -14), Pair(-7, -11), Pair(27, -20)
  },
  {
      Pair(4, -12), Pair(0, -14), Pair(-5, -23), Pair(-8, -16), Pair(-11, -23), Pair(-1, -16), Pair(-6, -7), Pair(6, -13)
  },
  {
      Pair(5, -9), Pair(-5, -13), Pair(-6, -17), Pair(-7, -22), Pair(-5, -23), Pair(-3, -15), Pair(-8, -11), Pair(16, -12)
  },
  {
      Pair(4, 0), Pair(-3, -16), Pair(-10, -11), Pair(-3, -23), Pair(0, -22), Pair(-3, -14), Pair(-17, -8), Pair(27, -8)
  },
  {
      Pair(-3, 5), Pair(-17, -10), Pair(13, -14), Pair(-21, -17), Pair(-1, -18), Pair(-10, -14), Pair(-4, -8), Pair(0, 1)
  },
  {
      Pair(-12, 7), Pair(1, -11), Pair(-3, -5), Pair(33, -26), Pair(-9, -19), Pair(-12, -10), Pair(-14, -12), Pair(1, 7)
  },
  {
      Pair(28, 14), Pair(-62, 1), Pair(-4, 5), Pair(67, -36), Pair(10, -9), Pair(-21, 4), Pair(21, -17), Pair(4, 12)
  }
}};

constexpr KingBuckets<std::array<FileTable<ScorePair>, 2>> kRookOnFileBonus = {{
  {{ // Bucket 0
    {
      Pair(21, 14), Pair(20, 19), Pair(24, 16), Pair(26, 11), Pair(29, 12), Pair(48, 6), Pair(46, 15), Pair(80, -5)
    },
    {
      Pair(13, 10), Pair(12, 11), Pair(17, 6), Pair(17, 11), Pair(15, 9), Pair(28, -10), Pair(38, -2), Pair(47, 1)
    }
  }},
  {{ // Bucket 1
    {
      Pair(21, 17), Pair(17, 17), Pair(19, 16), Pair(27, 1), Pair(31, 13), Pair(48, 12), Pair(41, 15), Pair(30, 15)
    },
    {
      Pair(35, 16), Pair(22, 9), Pair(16, 15), Pair(21, -4), Pair(25, 8), Pair(23, 11), Pair(28, -7), Pair(7, 8)
    }
  }},
  {{ // Bucket 2
    {
      Pair(22, 14), Pair(29, 8), Pair(30, 9), Pair(26, 13), Pair(28, 14), Pair(41, 10), Pair(39, 7), Pair(50, 2)
    },
    {
      Pair(8, 25), Pair(16, 10), Pair(18, 6), Pair(15, 8), Pair(16, 5), Pair(26, -2), Pair(32, -5), Pair(13, 12)
    }
  }},
  {{ // Bucket 3
    {
      Pair(21, 11), Pair(37, -1), Pair(53, -1), Pair(16, 15), Pair(22, 15), Pair(32, 14), Pair(28, 9), Pair(51, 5)
    },
    {
      Pair(0, 34), Pair(27, 3), Pair(43, 0), Pair(30, 0), Pair(12, 7), Pair(23, -2), Pair(28, -4), Pair(26, 12)
    }
  }},
  {{ // Bucket 4
    {
      Pair(28, 9), Pair(30, -1), Pair(37, 0), Pair(32, 9), Pair(-12, 24), Pair(20, 10), Pair(73, -9), Pair(-19, 19)
    },
    {
      Pair(-19, 54), Pair(35, 8), Pair(42, -3), Pair(53, -9), Pair(4, 8), Pair(31, -9), Pair(50, -14), Pair(-46, 30)
    }
  }},
  {{ // Bucket 5
    {
      Pair(-13, 30), Pair(45, -1), Pair(81, -12), Pair(22, 15), Pair(21, 17), Pair(-16, 20), Pair(42, -10), Pair(-36, 24)
    },
    {
      Pair(-42, 80), Pair(51, 18), Pair(115, -17), Pair(86, -14), Pair(82, -19), Pair(8, -12), Pair(99, -34), Pair(-17, 29)
    }
  }},
  {{ // Bucket 6
    {
      Pair(80, 2), Pair(4, 0), Pair(27, 2), Pair(89, 3), Pair(73, 10), Pair(45, -8), Pair(-60, 7), Pair(-6, 6)
    },
    {
      Pair(115, 47), Pair(75, 1), Pair(53, -5), Pair(146, -38), Pair(279, -67), Pair(158, -59), Pair(97, -45), Pair(235, -45)
    }
  }}
}};

constexpr KingBuckets<std::array<ScorePair, 12>> kPawnShelterTable = {{
  {
      Pair(22, -5), Pair(53, -18), Pair(33, -5),
      Pair(41, -10), Pair(50, -15), Pair(40, -14),
      Pair(54, -10), Pair(0, 0), Pair(47, -8),
      Pair(18, -1), Pair(21, -12), Pair(16, 0)
  },
  {
      Pair(17, -6), Pair(5, 6), Pair(17, -6),
      Pair(28, -10), Pair(13, 7), Pair(37, -10),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(7, -2), Pair(12, -3), Pair(7, -1),
      Pair(27, -14), Pair(16, -12), Pair(20, -12),
      Pair(56, -18), Pair(0, 0), Pair(49, -17),
      Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(2, 7), Pair(26, -3), Pair(8, 5),
      Pair(23, -9), Pair(25, -11), Pair(20, -8),
      Pair(34, -5), Pair(0, 0), Pair(31, -3),
      Pair(13, 5), Pair(12, 1), Pair(9, 8)
  },
  {
      Pair(18, 19), Pair(67, 1), Pair(16, 25),
      Pair(48, -13), Pair(52, -11), Pair(42, -13),
      Pair(53, 1), Pair(0, 0), Pair(46, 2),
      Pair(10, 10), Pair(3, 11), Pair(10, 12)
  },
  {
      Pair(-55, 50), Pair(99, -15), Pair(-65, 58),
      Pair(113, -5), Pair(54, 0), Pair(111, -4),
      Pair(68, 18), Pair(0, 0), Pair(57, 18),
      Pair(55, 3), Pair(27, -7), Pair(46, 4)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(-27, 50), Pair(0, 0), Pair(-95, 69),
      Pair(96, -21), Pair(124, -90), Pair(120, -21)
  }
}};

constexpr KingBuckets<std::array<ScorePair, 21>> kPawnStormTable = {{
  {
      Pair(-8, 7), Pair(-17, 12), Pair(-9, 6),
      Pair(-13, 9), Pair(-24, 16), Pair(-11, 7),
      Pair(-9, 1), Pair(-16, 6), Pair(-3, -1),
      Pair(5, 2), Pair(-14, 11), Pair(10, 0),
      Pair(38, -10), Pair(40, 0), Pair(36, -12),
      Pair(101, -10), Pair(-39, -23), Pair(117, -37),
      Pair(94, -73), Pair(0, 0), Pair(71, -61)
  },
  {
      Pair(-7, 9), Pair(-12, 13), Pair(-6, 8),
      Pair(-12, 8), Pair(-21, 18), Pair(-12, 8),
      Pair(-6, 5), Pair(-10, 10), Pair(-3, 5),
      Pair(5, 5), Pair(-12, 13), Pair(5, 3),
      Pair(34, -9), Pair(34, 6), Pair(25, -7),
      Pair(19, -3), Pair(-22, -24), Pair(-38, 23),
      Pair(38, -54), Pair(0, 0), Pair(58, -63)
  },
  {
      Pair(-22, 20), Pair(-24, 19), Pair(-16, 18),
      Pair(-12, 8), Pair(-21, 16), Pair(-12, 7),
      Pair(-7, 2), Pair(-17, 10), Pair(-3, 1),
      Pair(5, 2), Pair(-10, 8), Pair(9, 1),
      Pair(37, -11), Pair(40, 2), Pair(39, -12),
      Pair(12, -28), Pair(-43, -11), Pair(9, -11),
      Pair(18, -51), Pair(0, 0), Pair(21, -49)
  },
  {
      Pair(-3, 8), Pair(-12, 14), Pair(-4, 7),
      Pair(-3, 6), Pair(-13, 14), Pair(-1, 5),
      Pair(2, -2), Pair(-12, 9), Pair(5, -2),
      Pair(14, -3), Pair(-7, 5), Pair(13, -3),
      Pair(36, -14), Pair(41, -2), Pair(30, -12),
      Pair(-53, 11), Pair(-45, -10), Pair(-45, -13),
      Pair(19, -51), Pair(0, 0), Pair(31, -54)
  },
  {
      Pair(1, 4), Pair(4, 5), Pair(7, 0),
      Pair(-4, 3), Pair(0, 9), Pair(13, -4),
      Pair(19, -9), Pair(-8, 5), Pair(12, -9),
      Pair(26, -10), Pair(13, -3), Pair(20, -10),
      Pair(44, -20), Pair(48, -13), Pair(34, -19),
      Pair(-15, 14), Pair(-31, -23), Pair(43, -3),
      Pair(60, -65), Pair(0, 0), Pair(75, -67)
  },
  {
      Pair(37, -4), Pair(17, 3), Pair(46, -19),
      Pair(15, -8), Pair(-7, 5), Pair(6, -10),
      Pair(23, -19), Pair(-7, -1), Pair(27, -22),
      Pair(25, -18), Pair(11, -8), Pair(15, -15),
      Pair(73, -33), Pair(91, -37), Pair(62, -32),
      Pair(7, -3), Pair(12, -56), Pair(-16, 19),
      Pair(84, -74), Pair(0, 0), Pair(80, -70)
  },
  {
      Pair(-46, 2), Pair(-45, 14), Pair(-89, 31),
      Pair(-161, 23), Pair(3, -7), Pair(-22, -21),
      Pair(5, -19), Pair(-12, -8), Pair(-34, -14),
      Pair(16, -13), Pair(-2, -16), Pair(-25, -12),
      Pair(91, -48), Pair(53, -32), Pair(87, -46),
      Pair(14, -25), Pair(-43, -37), Pair(-7, -12),
      Pair(74, -76), Pair(0, 0), Pair(119, -79)
  }
}};

constexpr KingBuckets<std::array<ScorePair, 8>> kKingPPDistanceTable = {{
  {
      Pair(0, 0), Pair(9, 28), Pair(-5, 46), Pair(-8, 47), Pair(1, 36), Pair(0, 34), Pair(3, 32), Pair(-10, 15)
  },
  {
      Pair(0, 0), Pair(-7, 13), Pair(-9, 16), Pair(-10, 15), Pair(-7, 7), Pair(-1, 8), Pair(85, 97), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(-1, 29), Pair(-12, 31), Pair(-7, 23), Pair(-6, 15), Pair(-5, 9), Pair(5, 2), Pair(8, -13)
  },
  {
      Pair(0, 0), Pair(3, 38), Pair(-2, 29), Pair(-16, 23), Pair(-10, 11), Pair(-13, 5), Pair(-7, -6), Pair(-25, -17)
  },
  {
      Pair(0, 0), Pair(10, 38), Pair(0, 28), Pair(-24, 21), Pair(-37, 10), Pair(-14, -9), Pair(-29, -13), Pair(-52, -16)
  },
  {
      Pair(0, 0), Pair(-6, 46), Pair(7, 31), Pair(-12, 11), Pair(-48, 1), Pair(-34, -16), Pair(-64, -17), Pair(-131, -4)
  },
  {
      Pair(0, 0), Pair(18, 113), Pair(-13, 83), Pair(27, 23), Pair(-34, 4), Pair(-7, -18), Pair(-65, -20), Pair(-127, -8)
  }
}};

constexpr KingBuckets<std::array<ScorePair, 8>> kEnemyKingPPDistanceTable = {{
  {
      Pair(0, 0), Pair(-58, -40), Pair(-19, 3), Pair(-8, 32), Pair(0, 49), Pair(6, 61), Pair(10, 69), Pair(8, 66)
  },
  {
      Pair(0, 0), Pair(-67, -44), Pair(-27, -3), Pair(-4, 15), Pair(1, 31), Pair(2, 42), Pair(-10, 53), Pair(-17, 56)
  },
  {
      Pair(0, 0), Pair(-29, -47), Pair(-19, 2), Pair(4, 20), Pair(13, 35), Pair(21, 44), Pair(20, 55), Pair(17, 56)
  },
  {
      Pair(0, 0), Pair(-8, -49), Pair(-24, 6), Pair(-6, 27), Pair(4, 41), Pair(3, 53), Pair(13, 61), Pair(14, 62)
  },
  {
      Pair(0, 0), Pair(13, -55), Pair(-20, 12), Pair(-17, 40), Pair(1, 52), Pair(-6, 68), Pair(12, 74), Pair(12, 77)
  },
  {
      Pair(0, 0), Pair(47, -57), Pair(-49, 19), Pair(-21, 43), Pair(-11, 63), Pair(5, 75), Pair(-17, 90), Pair(-45, 105)
  },
  {
      Pair(0, 0), Pair(28, -86), Pair(-95, 16), Pair(-45, 38), Pair(-46, 60), Pair(25, 68), Pair(35, 83), Pair(-20, 98)
  }
}};

constexpr KingBuckets<ScorePair> kKingCantReachPPBonus = {
  Pair(-528, 95), Pair(50, 78), Pair(-199, 104), Pair(-115, 99), Pair(-135, 99), Pair(45, 83), Pair(149, 75)
};


constexpr KingBuckets<std::array<FileTable<ScorePair>, 2>> kKingOnFilePenalty = {{
  {{ // Bucket 0
    {
      Pair(-104, -6), Pair(-56, -21), Pair(-30, -16), Pair(-17, -21), Pair(-22, -13), Pair(-28, -12), Pair(-41, -14), Pair(-8, -21)
    },
    {
      Pair(-84, 128), Pair(-42, 38), Pair(-9, 10), Pair(2, -8), Pair(-7, -6), Pair(2, 0), Pair(-25, 7), Pair(-27, 45)
    }
  }},
  {{ // Bucket 1
    {
      Pair(-9, 45), Pair(-35, 18), Pair(-28, -6), Pair(-3, -21), Pair(-25, -1), Pair(-12, -5), Pair(-27, 18), Pair(-16, 29)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(-31, 37), Pair(-36, 26), Pair(-20, 24), Pair(-26, 26), Pair(0, 0), Pair(0, 0)
    }
  }},
  {{ // Bucket 2
    {
      Pair(-37, -29), Pair(-36, -13), Pair(-8, -27), Pair(-3, -37), Pair(1, -29), Pair(13, -28), Pair(-49, 2), Pair(-17, -7)
    },
    {
      Pair(-88, 89), Pair(-60, 43), Pair(-44, 20), Pair(-20, -3), Pair(-7, -2), Pair(12, 0), Pair(-48, 30), Pair(-38, 44)
    }
  }},
  {{ // Bucket 3
    {
      Pair(-6, -47), Pair(-5, -17), Pair(4, -22), Pair(14, -35), Pair(3, -25), Pair(21, -21), Pair(-18, -6), Pair(-15, -12)
    },
    {
      Pair(-26, 33), Pair(-55, 18), Pair(-19, 1), Pair(-18, -17), Pair(0, -10), Pair(3, 3), Pair(-20, 14), Pair(-18, 27)
    }
  }},
  {{ // Bucket 4
    {
      Pair(17, -33), Pair(-16, -17), Pair(-16, -14), Pair(22, -29), Pair(6, -18), Pair(22, -18), Pair(-3, -19), Pair(-20, -14)
    },
    {
      Pair(34, -3), Pair(-10, -7), Pair(-10, -8), Pair(10, -25), Pair(-3, -7), Pair(-9, 3), Pair(-1, -1), Pair(11, 2)
    }
  }},
  {{ // Bucket 5
    {
      Pair(3, -28), Pair(-30, -18), Pair(-32, -14), Pair(-63, -8), Pair(6, -15), Pair(22, -17), Pair(8, -23), Pair(-27, -7)
    },
    {
      Pair(45, -33), Pair(-27, -20), Pair(-23, -3), Pair(-5, -16), Pair(-14, -12), Pair(-23, -5), Pair(-7, -14), Pair(23, -13)
    }
  }},
  {{ // Bucket 6
    {
      Pair(68, -17), Pair(42, -47), Pair(73, -46), Pair(80, -46), Pair(51, -35), Pair(61, -29), Pair(45, -44), Pair(78, 0)
    },
    {
      Pair(92, 45), Pair(55, -25), Pair(111, -38), Pair(109, -20), Pair(132, -49), Pair(96, -36), Pair(111, -54), Pair(85, -4)
    }
  }}
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {{ // Bucket 0
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(9, 8), Pair(26, 7), Pair(102, -21), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(8, 11), Pair(23, 15), Pair(71, 3), Pair(110, -13), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(29, -17), Pair(47, -17), Pair(77, -16), Pair(144, -29), Pair(197, -44), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(5, 23), Pair(19, 50), Pair(36, 75), Pair(103, 62), Pair(145, 83), Pair(264, 48), Pair(336, 57)
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
      Pair(0, 0), Pair(11, 6), Pair(16, 9), Pair(80, -15), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(7, 5), Pair(22, 8), Pair(51, -1), Pair(49, -15), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(22, -12), Pair(37, -9), Pair(47, -3), Pair(108, -16), Pair(128, -16), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(7, 28), Pair(21, 63), Pair(31, 93), Pair(86, 95), Pair(132, 105), Pair(241, 60), Pair(272, 14)
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
      Pair(0, 0), Pair(22, 2), Pair(43, -2), Pair(103, -18), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(20, 0), Pair(45, -2), Pair(83, -11), Pair(106, -22), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(30, -14), Pair(49, -13), Pair(75, -11), Pair(134, -21), Pair(206, -39), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(9, 26), Pair(24, 53), Pair(54, 60), Pair(126, 47), Pair(153, 73), Pair(317, 7), Pair(336, 62)
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
      Pair(0, 0), Pair(26, -2), Pair(49, -4), Pair(100, -16), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(29, -2), Pair(52, -2), Pair(85, -10), Pair(112, -30), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(36, -14), Pair(65, -17), Pair(80, -11), Pair(147, -23), Pair(259, -48), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(34, 13), Pair(50, 47), Pair(97, 40), Pair(152, 44), Pair(243, 31), Pair(390, -12), Pair(427, 53)
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
      Pair(0, 0), Pair(26, 0), Pair(56, -5), Pair(107, -13), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(34, -2), Pair(54, 1), Pair(75, -2), Pair(97, -2), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(47, -16), Pair(82, -18), Pair(120, -18), Pair(183, -28), Pair(231, -36), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(-5, 51), Pair(24, 90), Pair(82, 80), Pair(163, 72), Pair(383, -8), Pair(342, 52), Pair(357, 138)
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
      Pair(0, 0), Pair(60, -2), Pair(115, -8), Pair(116, -9), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(51, -3), Pair(33, 14), Pair(61, 5), Pair(92, -2), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(16, -5), Pair(68, -11), Pair(159, -22), Pair(202, -26), Pair(317, -53), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(-10, 66), Pair(62, 59), Pair(74, 75), Pair(243, 25), Pair(392, -14), Pair(295, 67), Pair(72, 274)
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
      Pair(0, 0), Pair(88, -3), Pair(152, -10), Pair(99, -8), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(48, -4), Pair(37, 10), Pair(89, 5), Pair(61, -52), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(45, -6), Pair(82, -15), Pair(178, -28), Pair(164, -14), Pair(203, -34), Pair(0, 0), Pair(0, 0)
    },
    {
      Pair(0, 0), Pair(-81, 109), Pair(158, 21), Pair(324, -66), Pair(110, 105), Pair(276, 32), Pair(142, 112), Pair(33, 202)
    },
    {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
    }
  }}
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {{
  {
      Pair(0, 0), Pair(19, 15), Pair(1, 12), Pair(16, -1), Pair(10, 23), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(17, 16), Pair(4, 10), Pair(20, 6), Pair(11, 30), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(52, 0), Pair(8, 10), Pair(34, -1), Pair(15, 26), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(53, -3), Pair(6, 7), Pair(35, -4), Pair(45, 10), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(58, -7), Pair(-1, 7), Pair(43, -8), Pair(68, 1), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(77, -17), Pair(-12, 12), Pair(75, -13), Pair(75, -5), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(91, -28), Pair(-86, 33), Pair(111, -38), Pair(106, -28), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {{ // Bucket 0
    {
      Pair(-4, 31), Pair(0, 34)
    },
    {
      Pair(-75, -51), Pair(-46, -79)
    },
    {
      Pair(-56, -87), Pair(-41, -102)
    },
    {
      Pair(-60, -27), Pair(-40, -55)
    },
    {
      Pair(-35, -24), Pair(-41, -33)
    },
    {
      Pair(104, 2), Pair(59, 12)
    }
  }},
  {{ // Bucket 1
    {
      Pair(-1, 31), Pair(4, 34)
    },
    {
      Pair(-65, -58), Pair(-49, -74)
    },
    {
      Pair(-45, -100), Pair(-42, -99)
    },
    {
      Pair(-61, -9), Pair(-47, -31)
    },
    {
      Pair(-52, -4), Pair(-39, -43)
    },
    {
      Pair(-33, 55), Pair(65, 17)
    }
  }},
  {{ // Bucket 2
    {
      Pair(8, 23), Pair(1, 41)
    },
    {
      Pair(-79, -55), Pair(-49, -59)
    },
    {
      Pair(-71, -78), Pair(-46, -80)
    },
    {
      Pair(-58, -22), Pair(-48, -30)
    },
    {
      Pair(-39, -56), Pair(-39, -49)
    },
    {
      Pair(-5, 28), Pair(53, -32)
    }
  }},
  {{ // Bucket 3
    {
      Pair(13, 16), Pair(0, 42)
    },
    {
      Pair(-45, -62), Pair(-51, -54)
    },
    {
      Pair(-65, -80), Pair(-25, -94)
    },
    {
      Pair(-47, -33), Pair(-16, -41)
    },
    {
      Pair(-80, 32), Pair(-69, 34)
    },
    {
      Pair(-50, 17), Pair(-81, 24)
    }
  }},
  {{ // Bucket 4
    {
      Pair(56, 0), Pair(6, 40)
    },
    {
      Pair(-115, -70), Pair(33, -64)
    },
    {
      Pair(-60, -91), Pair(-35, -87)
    },
    {
      Pair(-43, -40), Pair(-127, 47)
    },
    {
      Pair(-4, -55), Pair(42, 84)
    },
    {
      Pair(-51, 21), Pair(-106, -13)
    }
  }},
  {{ // Bucket 5
    {
      Pair(124, -19), Pair(-30, 42)
    },
    {
      Pair(140, -87), Pair(-134, -10)
    },
    {
      Pair(-5, -138), Pair(-261, 73)
    },
    {
      Pair(-59, -31), Pair(96, -15)
    },
    {
      Pair(13, -8), Pair(34, 8)
    },
    {
      Pair(-2, 6), Pair(-124, 20)
    }
  }},
  {{ // Bucket 6
    {
      Pair(32, -17), Pair(-138, 61)
    },
    {
      Pair(24, -94), Pair(-38, -12)
    },
    {
      Pair(-4, -11), Pair(31, 6)
    },
    {
      Pair(-46, -93), Pair(-9, -174)
    },
    {
      Pair(32, 60), Pair(7, 14)
    },
    {
      Pair(-30, -100), Pair(26, 31)
    }
  }}
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {{
  {
      Pair(0, 0), Pair(17, 42), Pair(11, 45), Pair(20, 40), Pair(12, 29), Pair(63, -52)
  },
  {
      Pair(0, 0), Pair(13, 37), Pair(12, 37), Pair(19, 33), Pair(6, 38), Pair(49, -25)
  },
  {
      Pair(0, 0), Pair(26, 37), Pair(23, 28), Pair(27, 30), Pair(17, 11), Pair(26, -6)
  },
  {
      Pair(0, 0), Pair(42, 30), Pair(32, 26), Pair(44, 22), Pair(47, -9), Pair(-6, 16)
  },
  {
      Pair(0, 0), Pair(63, 24), Pair(71, 5), Pair(57, 21), Pair(87, 10), Pair(-14, 20)
  },
  {
      Pair(0, 0), Pair(13, 37), Pair(78, -16), Pair(18, 32), Pair(53, -16), Pair(30, 14)
  },
  {
      Pair(0, 0), Pair(18, 50), Pair(-11, -27), Pair(-148, 83), Pair(39, 28), Pair(0, 0)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {{ // Bucket 0
    {
      Pair(-3, -19), Pair(5, -5)
    },
    {
      Pair(-20, -11), Pair(-2, -12)
    },
    {
      Pair(-26, -41), Pair(-18, -58)
    },
    {
      Pair(-51, -15), Pair(-33, -40)
    },
    {
      Pair(-31, -66), Pair(-27, -47)
    },
    {
      Pair(-83, -2), Pair(15, -77)
    }
  }},
  {{ // Bucket 1
    {
      Pair(-4, -20), Pair(7, -7)
    },
    {
      Pair(-7, -10), Pair(-4, -22)
    },
    {
      Pair(-28, -38), Pair(-21, -55)
    },
    {
      Pair(-34, -27), Pair(-24, -30)
    },
    {
      Pair(-34, -64), Pair(-34, 2)
    },
    {
      Pair(-84, -13), Pair(-18, -35)
    }
  }},
  {{ // Bucket 2
    {
      Pair(3, -25), Pair(7, -7)
    },
    {
      Pair(-3, -18), Pair(12, -24)
    },
    {
      Pair(-30, -35), Pair(-23, -45)
    },
    {
      Pair(-54, -19), Pair(-28, -33)
    },
    {
      Pair(-41, -29), Pair(-15, -55)
    },
    {
      Pair(-99, -4), Pair(-71, -37)
    }
  }},
  {{ // Bucket 3
    {
      Pair(23, -31), Pair(10, -8)
    },
    {
      Pair(3, -14), Pair(19, -22)
    },
    {
      Pair(-42, -32), Pair(-16, -46)
    },
    {
      Pair(-33, -23), Pair(-48, -18)
    },
    {
      Pair(-33, -15), Pair(-22, 32)
    },
    {
      Pair(-94, -13), Pair(-51, -34)
    }
  }},
  {{ // Bucket 4
    {
      Pair(26, -35), Pair(10, -15)
    },
    {
      Pair(26, -28), Pair(83, -43)
    },
    {
      Pair(-61, -29), Pair(-63, -28)
    },
    {
      Pair(-12, -23), Pair(71, -61)
    },
    {
      Pair(-36, 48), Pair(203, 70)
    },
    {
      Pair(-126, -16), Pair(-75, -22)
    }
  }},
  {{ // Bucket 5
    {
      Pair(41, -38), Pair(26, -23)
    },
    {
      Pair(74, -37), Pair(97, -50)
    },
    {
      Pair(32, -40), Pair(-38, -43)
    },
    {
      Pair(-2, -30), Pair(54, -21)
    },
    {
      Pair(112, -27), Pair(153, 98)
    },
    {
      Pair(-215, 1), Pair(-54, -26)
    }
  }},
  {{ // Bucket 6
    {
      Pair(13, -38), Pair(55, -31)
    },
    {
      Pair(-27, -69), Pair(-27, -32)
    },
    {
      Pair(22, -45), Pair(45, -61)
    },
    {
      Pair(-55, -22), Pair(87, 34)
    },
    {
      Pair(62, 79), Pair(3, -18)
    },
    {
      Pair(-146, -6), Pair(-25, -34)
    }
  }}
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {{ // Bucket 0
    {
      Pair(-13, -13), Pair(0, -2)
    },
    {
      Pair(-41, -39), Pair(-23, -59)
    },
    {
      Pair(-10, -21), Pair(-6, -42)
    },
    {
      Pair(-48, -21), Pair(-38, -37)
    },
    {
      Pair(-40, -26), Pair(-27, -36)
    },
    {
      Pair(-24, -5), Pair(2, -29)
    }
  }},
  {{ // Bucket 1
    {
      Pair(-13, -12), Pair(0, 0)
    },
    {
      Pair(-36, -41), Pair(-23, -51)
    },
    {
      Pair(-4, -40), Pair(-10, -43)
    },
    {
      Pair(-37, -25), Pair(-38, -27)
    },
    {
      Pair(-44, 30), Pair(-25, -22)
    },
    {
      Pair(-12, -14), Pair(-18, -8)
    }
  }},
  {{ // Bucket 2
    {
      Pair(-9, -16), Pair(-6, 0)
    },
    {
      Pair(-43, -35), Pair(-23, -51)
    },
    {
      Pair(-4, -37), Pair(-2, -44)
    },
    {
      Pair(-50, -20), Pair(-38, -29)
    },
    {
      Pair(-27, -39), Pair(-23, -52)
    },
    {
      Pair(-11, -12), Pair(11, -28)
    }
  }},
  {{ // Bucket 3
    {
      Pair(11, -22), Pair(1, -5)
    },
    {
      Pair(-57, -29), Pair(-12, -53)
    },
    {
      Pair(23, -41), Pair(13, -48)
    },
    {
      Pair(-42, -21), Pair(-36, -29)
    },
    {
      Pair(-71, -33), Pair(-48, 43)
    },
    {
      Pair(-49, -10), Pair(-2, -47)
    }
  }},
  {{ // Bucket 4
    {
      Pair(50, -38), Pair(27, -21)
    },
    {
      Pair(-23, -42), Pair(19, -62)
    },
    {
      Pair(21, -48), Pair(74, -83)
    },
    {
      Pair(95, -48), Pair(22, -19)
    },
    {
      Pair(-283, 185), Pair(11, -16)
    },
    {
      Pair(-66, -20), Pair(147, -39)
    }
  }},
  {{ // Bucket 5
    {
      Pair(134, -70), Pair(118, -53)
    },
    {
      Pair(42, -65), Pair(56, -84)
    },
    {
      Pair(207, -101), Pair(151, -106)
    },
    {
      Pair(202, -90), Pair(15, -24)
    },
    {
      Pair(112, -19), Pair(3, 16)
    },
    {
      Pair(-269, 17), Pair(41, -73)
    }
  }},
  {{ // Bucket 6
    {
      Pair(158, -82), Pair(177, -65)
    },
    {
      Pair(-103, -57), Pair(119, -129)
    },
    {
      Pair(-78, -64), Pair(-14, -96)
    },
    {
      Pair(74, -44), Pair(-53, -56)
    },
    {
      Pair(81, 164), Pair(-1, -4)
    },
    {
      Pair(-23, -10), Pair(-7, -7)
    }
  }}
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {{ // Bucket 0
    {
      Pair(2, -23), Pair(10, -1)
    },
    {
      Pair(-31, -30), Pair(-2, -13)
    },
    {
      Pair(-24, -25), Pair(-3, -10)
    },
    {
      Pair(7, -31), Pair(14, -37)
    },
    {
      Pair(-39, -17), Pair(-23, -35)
    },
    {
      Pair(16, -29), Pair(-4, -31)
    }
  }},
  {{ // Bucket 1
    {
      Pair(8, -25), Pair(12, -6)
    },
    {
      Pair(-17, -34), Pair(1, -19)
    },
    {
      Pair(-14, -25), Pair(-6, -8)
    },
    {
      Pair(13, -32), Pair(5, -36)
    },
    {
      Pair(-71, 22), Pair(-29, -7)
    },
    {
      Pair(-55, -4), Pair(-34, -21)
    }
  }},
  {{ // Bucket 2
    {
      Pair(10, -27), Pair(13, -7)
    },
    {
      Pair(-16, -28), Pair(3, -13)
    },
    {
      Pair(-15, -23), Pair(-4, -10)
    },
    {
      Pair(16, -36), Pair(19, -40)
    },
    {
      Pair(-31, -22), Pair(-15, -40)
    },
    {
      Pair(-25, -17), Pair(-29, -31)
    }
  }},
  {{ // Bucket 3
    {
      Pair(20, -30), Pair(23, -13)
    },
    {
      Pair(-22, -28), Pair(14, -20)
    },
    {
      Pair(3, -32), Pair(10, -17)
    },
    {
      Pair(34, -37), Pair(8, -30)
    },
    {
      Pair(18, -46), Pair(3, -43)
    },
    {
      Pair(-64, -14), Pair(-91, -14)
    }
  }},
  {{ // Bucket 4
    {
      Pair(30, -30), Pair(41, -22)
    },
    {
      Pair(81, -59), Pair(46, -33)
    },
    {
      Pair(3, -34), Pair(19, -19)
    },
    {
      Pair(38, -42), Pair(9, -33)
    },
    {
      Pair(83, -32), Pair(-39, 15)
    },
    {
      Pair(-104, -7), Pair(-52, -24)
    }
  }},
  {{ // Bucket 5
    {
      Pair(8, -28), Pair(42, -25)
    },
    {
      Pair(76, -61), Pair(105, -67)
    },
    {
      Pair(54, -48), Pair(21, -20)
    },
    {
      Pair(139, -74), Pair(-25, -24)
    },
    {
      Pair(-45, -36), Pair(-87, 8)
    },
    {
      Pair(-270, 22), Pair(-231, 22)
    }
  }},
  {{ // Bucket 6
    {
      Pair(-31, -17), Pair(43, -24)
    },
    {
      Pair(-147, -25), Pair(151, -100)
    },
    {
      Pair(-26, -8), Pair(174, -78)
    },
    {
      Pair(184, -92), Pair(26, -40)
    },
    {
      Pair(174, -175), Pair(78, -20)
    },
    {
      Pair(-406, 60), Pair(-256, 58)
    }
  }}
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {{
  {
      Pair(12, 60), Pair(18, 49), Pair(43, 33), Pair(33, 34), Pair(20, 56), Pair(53, 27), Pair(25, 51), Pair(26, 25),
      Pair(17, 19), Pair(10, 27), Pair(18, 33), Pair(3, 74), Pair(1, 42), Pair(-5, 47), Pair(4, 21), Pair(18, 8),
      Pair(5, 14), Pair(5, 16), Pair(1, 28), Pair(10, 31), Pair(0, 36), Pair(-10, 26), Pair(-9, 21), Pair(-1, 4)
  },
  {
      Pair(65, 29), Pair(20, 40), Pair(22, 44), Pair(15, 40), Pair(18, 42), Pair(18, 48), Pair(1, 80), Pair(14, 69),
      Pair(-6, 18), Pair(6, 31), Pair(12, 42), Pair(5, 42), Pair(6, 39), Pair(12, 36), Pair(5, 23), Pair(22, 1),
      Pair(5, 30), Pair(12, 16), Pair(-1, 28), Pair(9, 21), Pair(-1, 26), Pair(-7, 19), Pair(-15, 20), Pair(2, -7)
  },
  {
      Pair(9, 53), Pair(22, 46), Pair(38, 29), Pair(30, 33), Pair(12, 51), Pair(-8, 44), Pair(2, 72), Pair(49, 8),
      Pair(21, 14), Pair(12, 28), Pair(16, 32), Pair(9, 45), Pair(2, 34), Pair(-7, 39), Pair(0, 31), Pair(9, 24),
      Pair(8, 9), Pair(7, 26), Pair(8, 21), Pair(18, 21), Pair(0, 28), Pair(-11, 22), Pair(-19, 23), Pair(-8, 7)
  },
  {
      Pair(32, 40), Pair(39, 47), Pair(50, 20), Pair(23, 28), Pair(26, 35), Pair(44, 31), Pair(-16, 65), Pair(-27, 50),
      Pair(-53, 36), Pair(18, 24), Pair(20, 33), Pair(43, 23), Pair(13, 31), Pair(-13, 40), Pair(-55, 53), Pair(-9, 32),
      Pair(-6, 24), Pair(-31, 33), Pair(27, 21), Pair(26, 11), Pair(15, 20), Pair(-8, 20), Pair(-35, 33), Pair(38, 2)
  },
  {
      Pair(-53, 28), Pair(-16, 50), Pair(64, 21), Pair(13, 23), Pair(3, 32), Pair(-5, 46), Pair(32, 41), Pair(45, 8),
      Pair(-54, 37), Pair(-28, 43), Pair(54, 21), Pair(23, 34), Pair(15, 32), Pair(-14, 44), Pair(-9, 37), Pair(-11, 32),
      Pair(-28, 35), Pair(23, 35), Pair(10, 27), Pair(9, 30), Pair(3, 18), Pair(-8, 17), Pair(-15, 28), Pair(19, 2)
  },
  {
      Pair(119, -52), Pair(101, 32), Pair(76, 13), Pair(105, 12), Pair(-92, 48), Pair(-97, 54), Pair(16, 23), Pair(27, -12),
      Pair(167, 10), Pair(59, 28), Pair(-5, 28), Pair(21, 34), Pair(73, 26), Pair(-19, 50), Pair(-15, 38), Pair(-62, 41),
      Pair(-15, 39), Pair(-47, 16), Pair(91, 20), Pair(15, 27), Pair(83, 8), Pair(38, 24), Pair(-4, 22), Pair(-36, 26)
  },
  {
      Pair(13, 104), Pair(17, 17), Pair(-8, 31), Pair(44, 15), Pair(-16, 56), Pair(37, 46), Pair(7, 59), Pair(27, 16),
      Pair(-42, 98), Pair(-69, 68), Pair(97, 12), Pair(-1, 30), Pair(11, 30), Pair(14, 44), Pair(91, 13), Pair(27, 49),
      Pair(40, -14), Pair(7, 55), Pair(135, 17), Pair(83, 38), Pair(42, 12), Pair(-19, 30), Pair(-47, 21), Pair(16, 51)
  }
}};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {{
  {
      Pair(-28, 35), Pair(21, 20), Pair(17, 8), Pair(39, 10), Pair(32, 17), Pair(95, -20), Pair(35, 25), Pair(-13, 28),
      Pair(0, 11), Pair(17, 21), Pair(30, -6), Pair(29, 32), Pair(11, 25), Pair(29, 26), Pair(13, 17), Pair(-15, 14),
      Pair(-28, 7), Pair(10, 18), Pair(5, 27), Pair(18, 9), Pair(12, 29), Pair(-3, 15), Pair(-2, 13), Pair(-12, -11)
  },
  {
      Pair(35, -9), Pair(57, 10), Pair(42, 4), Pair(66, -16), Pair(85, -11), Pair(84, -2), Pair(41, 44), Pair(-97, 76),
      Pair(-24, 34), Pair(12, 28), Pair(-7, 6), Pair(33, 12), Pair(22, 4), Pair(44, 3), Pair(5, 26), Pair(41, -13),
      Pair(-21, -7), Pair(-9, 27), Pair(6, 20), Pair(17, 13), Pair(19, 11), Pair(-2, 4), Pair(26, -1), Pair(-19, -37)
  },
  {
      Pair(-54, 38), Pair(35, 14), Pair(22, 4), Pair(48, 1), Pair(52, -3), Pair(64, 1), Pair(23, 20), Pair(13, -30),
      Pair(32, -8), Pair(28, 12), Pair(36, 1), Pair(37, 10), Pair(25, 7), Pair(20, 12), Pair(7, 21), Pair(4, 18),
      Pair(-6, 5), Pair(24, 18), Pair(10, 16), Pair(26, 10), Pair(24, 7), Pair(-8, 12), Pair(-1, 20), Pair(-34, 1)
  },
  {
      Pair(22, 22), Pair(74, 0), Pair(9, -2), Pair(98, -22), Pair(84, -24), Pair(57, 3), Pair(1, 33), Pair(65, -38),
      Pair(-49, 18), Pair(45, 9), Pair(60, -10), Pair(64, -9), Pair(50, -9), Pair(15, 8), Pair(5, 23), Pair(3, 11),
      Pair(-79, 24), Pair(2, 13), Pair(37, 7), Pair(40, 3), Pair(8, 13), Pair(16, 11), Pair(14, 9), Pair(-101, 31)
  },
  {
      Pair(1, 4), Pair(124, -22), Pair(98, -24), Pair(98, -19), Pair(76, -35), Pair(-18, 5), Pair(75, 5), Pair(-104, 30),
      Pair(-38, -21), Pair(40, 14), Pair(9, 2), Pair(3, 15), Pair(-7, 17), Pair(61, 10), Pair(35, 23), Pair(-47, 53),
      Pair(-221, 41), Pair(41, 7), Pair(27, 4), Pair(80, 0), Pair(18, 9), Pair(-20, 20), Pair(5, 10), Pair(-156, 32)
  },
  {
      Pair(-1, -11), Pair(107, -24), Pair(53, -18), Pair(30, 3), Pair(65, -18), Pair(45, -12), Pair(87, -7), Pair(6, 6),
      Pair(-100, 10), Pair(-28, 25), Pair(55, 3), Pair(86, -5), Pair(45, 15), Pair(14, 20), Pair(28, 29), Pair(-94, 14),
      Pair(-146, 46), Pair(-7, 31), Pair(126, -2), Pair(24, 10), Pair(-41, 27), Pair(-52, 23), Pair(23, 25), Pair(-114, 9)
  },
  {
      Pair(14, 54), Pair(51, -30), Pair(96, -12), Pair(94, 18), Pair(73, -8), Pair(142, -18), Pair(142, -19), Pair(21, -53),
      Pair(-18, 6), Pair(95, 47), Pair(134, -3), Pair(3, 25), Pair(58, 28), Pair(-136, 64), Pair(-9, 72), Pair(58, -34),
      Pair(20, 100), Pair(-136, 95), Pair(66, 28), Pair(93, 34), Pair(-18, 65), Pair(-105, 59), Pair(99, -7), Pair(26, 37)
  }
}};

constexpr KingBuckets<ScorePair> kBishopPairBonus = {{
  {
      Pair(16, 80)
  },
  {
      Pair(13, 75)
  },
  {
      Pair(25, 70)
  },
  {
      Pair(23, 70)
  },
  {
      Pair(-10, 84)
  },
  {
      Pair(-204, 144)
  },
  {
      Pair(-127, 139)
  }
}};


constexpr ScorePair kTempoBonus = Pair(16, 18);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H