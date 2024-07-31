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
using PieceSquareTable = KingBuckets<KingBuckets<PieceTable<std::array<T, kSquareCount>>>>;

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
  Pair(79, 174), Pair(337, 444), Pair(346, 492), Pair(441, 860), Pair(1063, 1526), Pair(0, 0)
};

constexpr PieceSquareTable<ScorePair> kPieceSquareTable = {{
  {{ // Bucket 0
    {{ // Bucket 0
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(108, 347), Pair(102, 324), Pair(133, 255), Pair(141, 213), Pair(142, 187), Pair(174, 134), Pair(19, 28), Pair(-25, 49),
        Pair(-32, 177), Pair(12, 175), Pair(19, 172), Pair(46, 109), Pair(49, 84), Pair(112, 9), Pair(51, 75), Pair(9, 92),
        Pair(-25, 62), Pair(3, 46), Pair(-4, 37), Pair(12, -6), Pair(27, -18), Pair(28, -28), Pair(18, 13), Pair(-12, 19),
        Pair(-32, 31), Pair(-9, 24), Pair(-9, -12), Pair(-6, -10), Pair(0, -19), Pair(-3, -22), Pair(16, -12), Pair(-4, -4),
        Pair(-36, 20), Pair(-16, 22), Pair(-20, 1), Pair(-17, -1), Pair(-5, 11), Pair(-14, 4), Pair(28, 13), Pair(9, -9),
        Pair(-37, 26), Pair(-18, 22), Pair(-27, 14), Pair(-28, 17), Pair(-22, 19), Pair(2, 34), Pair(42, 8), Pair(8, -40),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-251, 52), Pair(-173, 107), Pair(-80, 143), Pair(-6, 145), Pair(-7, 154), Pair(-118, 102), Pair(-167, 88), Pair(-145, -62),
        Pair(-28, 93), Pair(-20, 115), Pair(28, 135), Pair(47, 171), Pair(42, 161), Pair(94, 107), Pair(-25, 82), Pair(19, 111),
        Pair(-30, 103), Pair(8, 151), Pair(38, 175), Pair(50, 179), Pair(96, 147), Pair(76, 201), Pair(40, 167), Pair(24, 108),
        Pair(-10, 116), Pair(9, 159), Pair(25, 194), Pair(30, 236), Pair(19, 228), Pair(52, 218), Pair(21, 206), Pair(19, 159),
        Pair(-25, 97), Pair(-7, 144), Pair(4, 187), Pair(1, 196), Pair(2, 203), Pair(4, 195), Pair(23, 178), Pair(-9, 112),
        Pair(-40, 58), Pair(-19, 115), Pair(-15, 132), Pair(-2, 155), Pair(0, 160), Pair(-10, 140), Pair(-9, 136), Pair(-26, 45),
        Pair(-66, 75), Pair(-47, 93), Pair(-33, 98), Pair(-22, 125), Pair(-28, 124), Pair(-21, 99), Pair(-28, 102), Pair(-31, 88),
        Pair(-129, 23), Pair(-41, 4), Pair(-71, 84), Pair(-55, 95), Pair(-43, 104), Pair(-31, 91), Pair(-48, 37), Pair(-98, -29)
      },
      { // Piece 2
        Pair(-84, 152), Pair(-91, 121), Pair(-163, 173), Pair(-106, 134), Pair(-91, 143), Pair(-118, 114), Pair(-57, 140), Pair(-34, 134),
        Pair(-48, 117), Pair(-11, 147), Pair(-4, 128), Pair(-31, 141), Pair(-1, 126), Pair(17, 101), Pair(19, 133), Pair(-8, 107),
        Pair(-13, 119), Pair(1, 145), Pair(24, 151), Pair(19, 138), Pair(28, 148), Pair(62, 165), Pair(46, 152), Pair(5, 146),
        Pair(-22, 107), Pair(10, 142), Pair(13, 135), Pair(33, 175), Pair(20, 170), Pair(29, 160), Pair(12, 152), Pair(-14, 140),
        Pair(-26, 112), Pair(-5, 124), Pair(-6, 163), Pair(6, 157), Pair(8, 167), Pair(-5, 132), Pair(-2, 129), Pair(-7, 84),
        Pair(-19, 87), Pair(-7, 122), Pair(-11, 130), Pair(-8, 141), Pair(-13, 134), Pair(-15, 136), Pair(-4, 100), Pair(1, 103),
        Pair(-16, 92), Pair(-11, 79), Pair(-6, 96), Pair(-25, 105), Pair(-25, 121), Pair(-13, 91), Pair(2, 108), Pair(0, 37),
        Pair(-10, 55), Pair(-12, 70), Pair(-36, 41), Pair(-52, 98), Pair(-44, 81), Pair(-30, 102), Pair(-19, 95), Pair(-16, 71)
      },
      { // Piece 3
        Pair(53, 223), Pair(64, 225), Pair(16, 261), Pair(21, 250), Pair(62, 228), Pair(-9, 316), Pair(22, 253), Pair(122, 176),
        Pair(21, 233), Pair(22, 235), Pair(42, 247), Pair(62, 245), Pair(68, 230), Pair(119, 209), Pair(80, 230), Pair(91, 237),
        Pair(9, 201), Pair(42, 195), Pair(42, 211), Pair(64, 197), Pair(80, 189), Pair(99, 188), Pair(134, 157), Pair(75, 171),
        Pair(-2, 192), Pair(11, 202), Pair(26, 205), Pair(45, 203), Pair(38, 205), Pair(46, 193), Pair(66, 160), Pair(54, 170),
        Pair(-21, 167), Pair(-20, 186), Pair(-13, 199), Pair(0, 198), Pair(-5, 182), Pair(-8, 183), Pair(38, 139), Pair(9, 132),
        Pair(-36, 148), Pair(-22, 171), Pair(-23, 173), Pair(-21, 171), Pair(-19, 169), Pair(-23, 160), Pair(29, 131), Pair(-5, 116),
        Pair(-56, 143), Pair(-20, 147), Pair(-12, 158), Pair(-14, 160), Pair(-16, 146), Pair(-8, 148), Pair(33, 103), Pair(-27, 100),
        Pair(-17, 142), Pair(-13, 160), Pair(-7, 172), Pair(-3, 171), Pair(-7, 163), Pair(-11, 156), Pair(35, 163), Pair(-44, 95)
      },
      { // Piece 4
        Pair(-38, 318), Pair(4, 317), Pair(-3, 358), Pair(31, 342), Pair(30, 355), Pair(72, 412), Pair(77, 292), Pair(235, 106),
        Pair(2, 289), Pair(-25, 333), Pair(18, 323), Pair(-21, 397), Pair(7, 412), Pair(67, 439), Pair(-38, 393), Pair(23, 326),
        Pair(3, 273), Pair(13, 283), Pair(7, 323), Pair(23, 330), Pair(25, 397), Pair(96, 375), Pair(105, 377), Pair(54, 378),
        Pair(16, 242), Pair(14, 288), Pair(19, 284), Pair(13, 333), Pair(15, 362), Pair(36, 372), Pair(43, 353), Pair(53, 334),
        Pair(16, 236), Pair(19, 279), Pair(17, 274), Pair(15, 327), Pair(18, 311), Pair(27, 299), Pair(38, 263), Pair(44, 294),
        Pair(12, 222), Pair(24, 243), Pair(17, 273), Pair(13, 259), Pair(19, 243), Pair(14, 274), Pair(44, 223), Pair(43, 206),
        Pair(15, 190), Pair(22, 213), Pair(23, 206), Pair(18, 223), Pair(19, 218), Pair(37, 154), Pair(50, 124), Pair(34, 141),
        Pair(16, 209), Pair(4, 203), Pair(10, 189), Pair(17, 198), Pair(14, 185), Pair(-5, 186), Pair(18, 130), Pair(-12, 272)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-8, -8), Pair(26, 43), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(-6, 24), Pair(5, -31)
      }
    }},
    {{ // Bucket 1
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(120, 248), Pair(65, 261), Pair(146, 90), Pair(112, 62), Pair(146, -15), Pair(88, 18), Pair(30, 186), Pair(124, 289),
        Pair(-22, 112), Pair(21, 125), Pair(41, 53), Pair(87, 28), Pair(77, 5), Pair(74, 30), Pair(42, 82), Pair(23, 98),
        Pair(-26, 38), Pair(5, 18), Pair(2, -8), Pair(26, -26), Pair(18, -26), Pair(11, -34), Pair(34, 8), Pair(10, 27),
        Pair(-50, 8), Pair(-16, 1), Pair(-13, -33), Pair(-3, -17), Pair(-11, -30), Pair(-15, -38), Pair(19, -14), Pair(10, -12),
        Pair(-54, -2), Pair(-32, 6), Pair(-17, -34), Pair(-24, -8), Pair(-21, -13), Pair(-34, -20), Pair(46, -8), Pair(25, -20),
        Pair(-59, 5), Pair(-30, 10), Pair(-30, -10), Pair(-37, -18), Pair(-33, 10), Pair(-8, -5), Pair(53, -7), Pair(18, -30),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-114, -89), Pair(-94, 21), Pair(-165, 76), Pair(-11, 21), Pair(113, 26), Pair(-110, 95), Pair(-49, 85), Pair(-129, -42),
        Pair(-19, 43), Pair(37, 44), Pair(81, 76), Pair(44, 77), Pair(17, 59), Pair(82, 53), Pair(-5, 68), Pair(60, -37),
        Pair(19, 15), Pair(22, 102), Pair(37, 109), Pair(122, 82), Pair(115, 60), Pair(92, 117), Pair(58, 67), Pair(19, 55),
        Pair(21, 72), Pair(40, 120), Pair(53, 134), Pair(58, 129), Pair(48, 138), Pair(84, 109), Pair(36, 127), Pair(36, 89),
        Pair(-20, 67), Pair(29, 78), Pair(19, 126), Pair(12, 126), Pair(22, 127), Pair(17, 124), Pair(9, 112), Pair(-3, 48),
        Pair(-35, -9), Pair(-14, 64), Pair(-10, 70), Pair(12, 84), Pair(5, 87), Pair(-7, 61), Pair(2, 73), Pair(-19, -11),
        Pair(-63, 47), Pair(-38, 23), Pair(-29, 37), Pair(-20, 54), Pair(-23, 58), Pair(-18, 26), Pair(-24, 18), Pair(-20, -4),
        Pair(-166, 35), Pair(-48, -22), Pair(-58, 29), Pair(-54, 53), Pair(-30, 28), Pair(-54, 37), Pair(-59, -6), Pair(-98, -125)
      },
      { // Piece 2
        Pair(-23, 75), Pair(0, 46), Pair(-106, 38), Pair(-194, 69), Pair(-67, 83), Pair(-96, -1), Pair(-60, 30), Pair(-47, 44),
        Pair(-2, 23), Pair(3, 65), Pair(23, 58), Pair(-69, 110), Pair(-3, 113), Pair(28, 26), Pair(-9, 81), Pair(-26, 7),
        Pair(-7, 58), Pair(63, 55), Pair(62, 66), Pair(72, 69), Pair(66, 52), Pair(94, 86), Pair(53, 65), Pair(1, 63),
        Pair(19, 53), Pair(26, 85), Pair(48, 85), Pair(60, 88), Pair(58, 81), Pair(71, 51), Pair(28, 77), Pair(-4, 88),
        Pair(8, 14), Pair(43, 46), Pair(1, 78), Pair(19, 87), Pair(15, 73), Pair(9, 86), Pair(28, 47), Pair(21, 68),
        Pair(15, 24), Pair(6, 40), Pair(4, 56), Pair(4, 52), Pair(-1, 54), Pair(2, 58), Pair(15, 37), Pair(14, 51),
        Pair(-7, 0), Pair(4, 26), Pair(7, 26), Pair(-10, 25), Pair(-18, 41), Pair(-4, 49), Pair(20, 40), Pair(-5, -31),
        Pair(8, -5), Pair(-9, -1), Pair(-28, -22), Pair(-41, 30), Pair(-43, 44), Pair(-51, 37), Pair(18, 11), Pair(6, -31)
      },
      { // Piece 3
        Pair(137, 70), Pair(62, 96), Pair(24, 150), Pair(9, 139), Pair(94, 126), Pair(-25, 98), Pair(82, 100), Pair(128, 27),
        Pair(88, 85), Pair(54, 108), Pair(127, 83), Pair(115, 108), Pair(81, 97), Pair(52, 112), Pair(83, 104), Pair(142, 77),
        Pair(15, 93), Pair(115, 46), Pair(84, 76), Pair(133, 55), Pair(103, 79), Pair(49, 91), Pair(143, 56), Pair(101, 52),
        Pair(4, 86), Pair(42, 50), Pair(62, 65), Pair(83, 47), Pair(59, 82), Pair(42, 54), Pair(48, 56), Pair(42, 71),
        Pair(-17, 37), Pair(-15, 73), Pair(7, 55), Pair(-5, 74), Pair(10, 61), Pair(-16, 58), Pair(52, 16), Pair(43, 8),
        Pair(-44, 39), Pair(-4, 22), Pair(-15, 43), Pair(1, 30), Pair(-4, 34), Pair(-33, 56), Pair(0, 71), Pair(-2, 11),
        Pair(-38, -8), Pair(-20, 37), Pair(0, 19), Pair(-7, 27), Pair(-24, 45), Pair(-18, 23), Pair(-1, 44), Pair(-47, 13),
        Pair(-23, 14), Pair(-8, 43), Pair(12, 41), Pair(9, 35), Pair(9, 47), Pair(-11, 37), Pair(-2, 83), Pair(-51, -10)
      },
      { // Piece 4
        Pair(40, 88), Pair(40, 134), Pair(72, 131), Pair(77, 144), Pair(64, 132), Pair(-19, 204), Pair(50, 170), Pair(60, 168),
        Pair(48, 149), Pair(-23, 221), Pair(78, 191), Pair(52, 215), Pair(26, 369), Pair(19, 247), Pair(1, 241), Pair(90, 139),
        Pair(-2, 137), Pair(43, 156), Pair(55, 182), Pair(87, 240), Pair(80, 254), Pair(66, 266), Pair(98, 194), Pair(20, 223),
        Pair(61, 58), Pair(34, 157), Pair(51, 163), Pair(59, 179), Pair(49, 231), Pair(53, 196), Pair(41, 249), Pair(40, 147),
        Pair(31, 43), Pair(47, 115), Pair(29, 127), Pair(3, 196), Pair(4, 199), Pair(10, 164), Pair(34, 101), Pair(19, 147),
        Pair(12, 114), Pair(30, 70), Pair(21, 83), Pair(20, 56), Pair(10, 92), Pair(29, 54), Pair(24, 95), Pair(0, 74),
        Pair(29, -15), Pair(39, -1), Pair(29, 8), Pair(19, 20), Pair(30, 19), Pair(57, -91), Pair(15, 1), Pair(18, -18),
        Pair(0, 65), Pair(9, 31), Pair(10, -7), Pair(21, 1), Pair(21, -38), Pair(-6, -30), Pair(1, 11), Pair(-3, 20)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(51, -33), Pair(89, 4), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(15, 5), Pair(19, -40)
      }
    }},
    {{ // Bucket 2
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(128, 240), Pair(159, 210), Pair(151, 171), Pair(161, 117), Pair(180, 81), Pair(160, 81), Pair(92, 121), Pair(119, 197),
        Pair(-27, 149), Pair(17, 142), Pair(42, 103), Pair(69, 63), Pair(59, 31), Pair(108, -16), Pair(43, 25), Pair(-27, 58),
        Pair(-23, 45), Pair(5, 24), Pair(-4, 12), Pair(10, -17), Pair(36, -33), Pair(30, -29), Pair(35, 6), Pair(12, -5),
        Pair(-30, 11), Pair(-15, 8), Pair(-8, -22), Pair(-8, -20), Pair(-4, -24), Pair(-2, -31), Pair(21, -12), Pair(7, -12),
        Pair(-28, -3), Pair(-18, 5), Pair(-19, -20), Pair(-24, -6), Pair(-8, -2), Pair(-5, -8), Pair(37, -6), Pair(20, -23),
        Pair(-30, 8), Pair(-22, 11), Pair(-32, 6), Pair(-36, 14), Pair(-34, 19), Pair(7, 7), Pair(47, -1), Pair(14, -40),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-218, 7), Pair(-112, 76), Pair(-48, 84), Pair(26, 60), Pair(165, 47), Pair(69, 105), Pair(-18, 12), Pair(-122, 5),
        Pair(9, 18), Pair(34, 55), Pair(68, 70), Pair(115, 81), Pair(91, 74), Pair(124, 51), Pair(45, -22), Pair(58, 27),
        Pair(10, 47), Pair(30, 93), Pair(75, 106), Pair(113, 101), Pair(162, 86), Pair(168, 87), Pair(94, 71), Pair(69, 10),
        Pair(15, 54), Pair(31, 99), Pair(62, 128), Pair(82, 129), Pair(79, 137), Pair(116, 112), Pair(65, 123), Pair(50, 69),
        Pair(-7, 61), Pair(21, 87), Pair(30, 127), Pair(44, 137), Pair(57, 128), Pair(53, 131), Pair(69, 89), Pair(34, 72),
        Pair(-28, 36), Pair(0, 69), Pair(11, 83), Pair(25, 108), Pair(29, 102), Pair(20, 87), Pair(29, 74), Pair(2, 11),
        Pair(-66, 40), Pair(-36, 55), Pair(-13, 51), Pair(-5, 79), Pair(0, 71), Pair(-8, 68), Pair(-16, 39), Pair(-15, 36),
        Pair(-116, -20), Pair(-43, 2), Pair(-47, 26), Pair(-54, 56), Pair(-34, 59), Pair(-21, 48), Pair(-31, 2), Pair(-153, 27)
      },
      { // Piece 2
        Pair(-73, 82), Pair(-2, 74), Pair(-116, 106), Pair(-103, 106), Pair(-36, 79), Pair(-30, 92), Pair(25, 74), Pair(-50, 62),
        Pair(-48, 43), Pair(19, 73), Pair(30, 60), Pair(15, 61), Pair(38, 66), Pair(52, 45), Pair(32, 41), Pair(34, 31),
        Pair(6, 53), Pair(10, 87), Pair(49, 85), Pair(76, 59), Pair(87, 69), Pair(129, 64), Pair(12, 75), Pair(63, 50),
        Pair(-1, 50), Pair(40, 78), Pair(42, 77), Pair(85, 85), Pair(90, 82), Pair(100, 75), Pair(66, 82), Pair(24, 51),
        Pair(-11, 38), Pair(19, 70), Pair(19, 85), Pair(56, 81), Pair(51, 82), Pair(44, 76), Pair(44, 55), Pair(34, 31),
        Pair(10, 33), Pair(8, 54), Pair(22, 60), Pair(19, 65), Pair(21, 68), Pair(13, 70), Pair(25, 32), Pair(28, 40),
        Pair(2, 17), Pair(19, 16), Pair(17, 26), Pair(3, 45), Pair(2, 51), Pair(14, 28), Pair(23, 43), Pair(31, -26),
        Pair(27, -9), Pair(10, 12), Pair(-16, 10), Pair(-32, 36), Pair(-32, 38), Pair(-13, 46), Pair(-3, 21), Pair(8, 16)
      },
      { // Piece 3
        Pair(124, 95), Pair(96, 117), Pair(99, 119), Pair(122, 103), Pair(155, 87), Pair(177, 90), Pair(204, 97), Pair(147, 112),
        Pair(68, 105), Pair(49, 123), Pair(75, 129), Pair(87, 124), Pair(92, 126), Pair(94, 81), Pair(62, 101), Pair(85, 89),
        Pair(44, 101), Pair(67, 94), Pair(88, 101), Pair(102, 89), Pair(135, 72), Pair(169, 74), Pair(198, 50), Pair(129, 59),
        Pair(29, 86), Pair(44, 88), Pair(51, 100), Pair(75, 91), Pair(97, 80), Pair(126, 73), Pair(108, 76), Pair(87, 57),
        Pair(-13, 73), Pair(-5, 93), Pair(-6, 110), Pair(20, 89), Pair(8, 97), Pair(32, 79), Pair(92, 49), Pair(31, 55),
        Pair(-28, 64), Pair(2, 63), Pair(-4, 77), Pair(2, 71), Pair(-13, 78), Pair(0, 67), Pair(40, 50), Pair(13, 32),
        Pair(-43, 49), Pair(6, 42), Pair(1, 52), Pair(7, 55), Pair(-2, 52), Pair(16, 48), Pair(16, 53), Pair(-22, 28),
        Pair(-1, 51), Pair(7, 60), Pair(11, 72), Pair(16, 66), Pair(10, 71), Pair(13, 57), Pair(50, 75), Pair(-21, 30)
      },
      { // Piece 4
        Pair(18, 188), Pair(37, 201), Pair(80, 190), Pair(92, 196), Pair(140, 173), Pair(118, 221), Pair(142, 165), Pair(140, 212),
        Pair(28, 123), Pair(-13, 178), Pair(38, 171), Pair(51, 197), Pair(31, 258), Pair(89, 206), Pair(48, 190), Pair(99, 169),
        Pair(16, 135), Pair(24, 156), Pair(49, 149), Pair(57, 191), Pair(96, 199), Pair(164, 244), Pair(94, 239), Pair(80, 218),
        Pair(25, 123), Pair(50, 148), Pair(36, 172), Pair(53, 208), Pair(70, 235), Pair(121, 228), Pair(97, 224), Pair(72, 213),
        Pair(37, 101), Pair(41, 137), Pair(42, 136), Pair(32, 206), Pair(38, 200), Pair(62, 202), Pair(81, 177), Pair(66, 190),
        Pair(34, 76), Pair(32, 128), Pair(45, 126), Pair(41, 114), Pair(44, 135), Pair(44, 141), Pair(55, 112), Pair(39, 138),
        Pair(30, 87), Pair(34, 101), Pair(38, 89), Pair(34, 120), Pair(36, 95), Pair(46, 62), Pair(41, 37), Pair(7, 89),
        Pair(22, 94), Pair(13, 104), Pair(25, 73), Pair(26, 87), Pair(18, 82), Pair(-10, 101), Pair(23, 46), Pair(-40, 184)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(23, -54), Pair(60, -3), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(4, -3), Pair(4, -50)
      }
    }},
    {{ // Bucket 3
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(141, 196), Pair(167, 174), Pair(74, 191), Pair(105, 104), Pair(115, 92), Pair(120, 119), Pair(-23, 236), Pair(73, 185),
        Pair(-85, 145), Pair(-7, 118), Pair(40, 69), Pair(98, 4), Pair(56, 1), Pair(50, 2), Pair(26, 67), Pair(-38, 77),
        Pair(-34, 35), Pair(-27, 25), Pair(-16, -9), Pair(-22, -25), Pair(25, -46), Pair(-7, -40), Pair(38, -25), Pair(-41, -2),
        Pair(-44, 5), Pair(-37, 3), Pair(-25, -31), Pair(-26, -21), Pair(-18, -21), Pair(-2, -26), Pair(35, -15), Pair(36, -33),
        Pair(-45, -4), Pair(-34, 1), Pair(-44, -11), Pair(-43, 5), Pair(-2, -6), Pair(-8, -15), Pair(57, -20), Pair(18, -27),
        Pair(-42, 2), Pair(-30, 6), Pair(-27, -6), Pair(-59, 17), Pair(-45, 12), Pair(16, -3), Pair(66, -19), Pair(29, -51),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-88, 24), Pair(-106, 7), Pair(40, 55), Pair(12, 50), Pair(55, 42), Pair(-23, 100), Pair(-98, 18), Pair(-114, -114),
        Pair(27, 5), Pair(1, 23), Pair(27, 36), Pair(126, 78), Pair(133, 57), Pair(136, 3), Pair(34, 19), Pair(61, 26),
        Pair(-23, 38), Pair(20, 79), Pair(62, 92), Pair(185, 29), Pair(125, 76), Pair(74, 108), Pair(64, 39), Pair(69, 30),
        Pair(-23, 43), Pair(36, 69), Pair(40, 99), Pair(95, 101), Pair(148, 89), Pair(150, 75), Pair(182, 38), Pair(29, 53),
        Pair(-13, 38), Pair(4, 66), Pair(20, 95), Pair(32, 112), Pair(66, 99), Pair(63, 109), Pair(63, 100), Pair(84, 12),
        Pair(-81, 57), Pair(-9, 51), Pair(8, 75), Pair(-1, 98), Pair(43, 91), Pair(20, 77), Pair(78, 25), Pair(-27, 9),
        Pair(-85, 5), Pair(-97, 20), Pair(-76, 79), Pair(-26, 69), Pair(-21, 70), Pair(-55, 67), Pair(-36, 22), Pair(-27, 16),
        Pair(-239, -24), Pair(-50, -42), Pair(-61, 17), Pair(-84, 25), Pair(-45, 40), Pair(-47, 31), Pair(-110, 3), Pair(-164, -10)
      },
      { // Piece 2
        Pair(-50, 63), Pair(-7, 16), Pair(-105, 87), Pair(-49, 60), Pair(-71, 66), Pair(8, 30), Pair(-19, 44), Pair(-101, 67),
        Pair(6, 13), Pair(-15, 56), Pair(-9, 33), Pair(90, 35), Pair(16, 56), Pair(44, 18), Pair(-86, 50), Pair(3, 23),
        Pair(-16, 48), Pair(27, 45), Pair(62, 45), Pair(39, 39), Pair(43, 70), Pair(152, 53), Pair(-16, 84), Pair(-13, 52),
        Pair(-9, 2), Pair(30, 49), Pair(7, 57), Pair(103, 54), Pair(109, 45), Pair(84, 31), Pair(68, 49), Pair(46, 28),
        Pair(-39, 6), Pair(-16, 63), Pair(38, 50), Pair(49, 65), Pair(51, 65), Pair(73, 38), Pair(34, 34), Pair(45, 2),
        Pair(15, 23), Pair(10, 38), Pair(-23, 57), Pair(16, 56), Pair(24, 45), Pair(-3, 64), Pair(-30, 64), Pair(23, 20),
        Pair(-41, 4), Pair(-5, 16), Pair(-8, 41), Pair(-42, 53), Pair(-16, 44), Pair(-10, 20), Pair(-25, 30), Pair(-32, -9),
        Pair(56, -50), Pair(-30, 13), Pair(-49, 4), Pair(-23, 17), Pair(-27, 11), Pair(-28, 10), Pair(-52, 25), Pair(-55, -15)
      },
      { // Piece 3
        Pair(50, 69), Pair(27, 89), Pair(-6, 114), Pair(47, 92), Pair(33, 109), Pair(23, 101), Pair(17, 111), Pair(100, 80),
        Pair(29, 60), Pair(31, 68), Pair(68, 66), Pair(72, 65), Pair(87, 61), Pair(116, 53), Pair(110, 24), Pair(96, 23),
        Pair(-27, 68), Pair(38, 64), Pair(29, 71), Pair(30, 72), Pair(76, 57), Pair(90, 41), Pair(30, 40), Pair(10, 49),
        Pair(-55, 85), Pair(-75, 94), Pair(6, 75), Pair(63, 56), Pair(75, 58), Pair(42, 58), Pair(122, 8), Pair(-10, 60),
        Pair(-80, 54), Pair(-57, 71), Pair(-82, 72), Pair(-84, 92), Pair(9, 52), Pair(-14, 78), Pair(-2, 77), Pair(31, 43),
        Pair(-148, 67), Pair(-50, 42), Pair(-105, 68), Pair(-80, 50), Pair(-58, 53), Pair(-41, 42), Pair(-12, 24), Pair(-24, -1),
        Pair(-66, 22), Pair(-79, 26), Pair(-81, 45), Pair(-85, 50), Pair(-58, 42), Pair(-36, 35), Pair(-62, 44), Pair(-97, 50),
        Pair(-74, 38), Pair(-65, 49), Pair(-76, 63), Pair(-58, 60), Pair(-59, 58), Pair(-62, 62), Pair(-14, 30), Pair(-70, -23)
      },
      { // Piece 4
        Pair(44, 90), Pair(112, 93), Pair(131, 61), Pair(219, 57), Pair(170, 97), Pair(126, 152), Pair(191, 95), Pair(159, 108),
        Pair(64, 45), Pair(51, 79), Pair(77, 108), Pair(117, 115), Pair(143, 134), Pair(164, 110), Pair(84, 106), Pair(116, 133),
        Pair(23, 34), Pair(-9, 77), Pair(40, 88), Pair(86, 80), Pair(68, 122), Pair(230, 100), Pair(139, 64), Pair(225, 2),
        Pair(57, 5), Pair(37, 82), Pair(63, 94), Pair(98, 100), Pair(123, 153), Pair(231, 71), Pair(160, 136), Pair(103, 143),
        Pair(28, 47), Pair(61, 37), Pair(119, 18), Pair(100, 91), Pair(80, 145), Pair(95, 126), Pair(192, 42), Pair(176, 52),
        Pair(21, -8), Pair(31, 48), Pair(34, 76), Pair(32, 62), Pair(59, 56), Pair(50, 126), Pair(100, 87), Pair(88, 46),
        Pair(22, 35), Pair(60, -21), Pair(45, 5), Pair(46, 31), Pair(35, 63), Pair(37, 58), Pair(38, 12), Pair(53, 7),
        Pair(18, 31), Pair(17, 34), Pair(5, 63), Pair(25, 31), Pair(-15, 70), Pair(-31, 32), Pair(77, -55), Pair(33, -123)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(65, -47), Pair(141, -31), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(28, -2), Pair(27, -40)
      }
    }},
    {{ // Bucket 4
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(103, 165), Pair(86, 176), Pair(51, 191), Pair(46, 138), Pair(19, 151), Pair(-54, 99), Pair(-120, 232), Pair(143, 195),
        Pair(-19, 96), Pair(40, 68), Pair(67, 47), Pair(52, 41), Pair(106, 6), Pair(-7, 35), Pair(10, 105), Pair(3, 74),
        Pair(-58, 19), Pair(-46, -2), Pair(-41, -35), Pair(-52, -37), Pair(-5, -55), Pair(-22, -45), Pair(55, -32), Pair(-57, -10),
        Pair(-61, -11), Pair(-39, -19), Pair(-69, -36), Pair(-92, -22), Pair(-2, -46), Pair(-16, -58), Pair(11, -34), Pair(-6, -40),
        Pair(-90, -15), Pair(-55, -14), Pair(-48, -36), Pair(-24, -16), Pair(-12, -14), Pair(14, -22), Pair(51, -27), Pair(-2, -35),
        Pair(-49, -19), Pair(-16, -6), Pair(-21, -14), Pair(-70, 24), Pair(5, -19), Pair(49, -16), Pair(67, -25), Pair(32, -52),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-203, -96), Pair(-30, -5), Pair(-100, -93), Pair(16, -46), Pair(48, -14), Pair(84, -52), Pair(29, -7), Pair(-23, -158),
        Pair(36, -111), Pair(-13, -41), Pair(32, 4), Pair(125, -7), Pair(162, 30), Pair(162, -74), Pair(20, -11), Pair(-14, -60),
        Pair(-134, -15), Pair(79, -18), Pair(-9, 33), Pair(119, 38), Pair(196, -36), Pair(168, -30), Pair(-46, -8), Pair(-26, -50),
        Pair(-55, -46), Pair(4, 28), Pair(54, 34), Pair(112, 33), Pair(136, 38), Pair(157, 11), Pair(31, 18), Pair(122, -28),
        Pair(33, 27), Pair(30, 4), Pair(66, 17), Pair(109, 5), Pair(126, -2), Pair(210, -3), Pair(167, -9), Pair(219, -55),
        Pair(-206, 32), Pair(-124, 48), Pair(35, -8), Pair(15, 44), Pair(95, 0), Pair(79, 23), Pair(-3, 3), Pair(-29, -34),
        Pair(-91, -15), Pair(35, -29), Pair(34, -30), Pair(-32, 39), Pair(27, -9), Pair(3, -4), Pair(46, -26), Pair(-28, 25),
        Pair(-77, -34), Pair(-123, -40), Pair(-77, -36), Pair(-41, -54), Pair(-23, -13), Pair(-37, 5), Pair(7, -59), Pair(-3, -107)
      },
      { // Piece 2
        Pair(-113, 24), Pair(-46, 13), Pair(-76, 5), Pair(-86, 14), Pair(-44, 12), Pair(-25, -23), Pair(-22, 24), Pair(-7, 19),
        Pair(-134, -44), Pair(22, 23), Pair(-103, 18), Pair(-88, 59), Pair(6, 4), Pair(-24, 20), Pair(-20, 4), Pair(-145, -8),
        Pair(-23, -44), Pair(-41, 11), Pair(12, 10), Pair(25, -3), Pair(16, 15), Pair(28, 5), Pair(45, -3), Pair(45, -47),
        Pair(26, -19), Pair(-14, 12), Pair(30, 4), Pair(30, 19), Pair(29, 6), Pair(23, -14), Pair(76, -3), Pair(12, -17),
        Pair(-166, 21), Pair(23, -50), Pair(10, -10), Pair(49, -10), Pair(61, -13), Pair(112, -6), Pair(-14, 20), Pair(41, -14),
        Pair(-5, 0), Pair(-9, -24), Pair(0, -10), Pair(-14, 8), Pair(39, 12), Pair(36, -2), Pair(-53, 6), Pair(6, 4),
        Pair(-75, 56), Pair(-50, -5), Pair(-16, -10), Pair(-61, 7), Pair(-77, 25), Pair(-28, -4), Pair(-41, -10), Pair(-96, -62),
        Pair(-62, -23), Pair(7, -43), Pair(-98, -35), Pair(-91, -14), Pair(-74, -12), Pair(2, -50), Pair(5, -63), Pair(-177, -19)
      },
      { // Piece 3
        Pair(-20, -21), Pair(-70, 16), Pair(1, 6), Pair(-34, 7), Pair(-66, 27), Pair(-26, 23), Pair(-59, 44), Pair(-72, 38),
        Pair(-1, -35), Pair(-8, -29), Pair(-51, 3), Pair(4, -3), Pair(2, 11), Pair(88, -40), Pair(106, -42), Pair(0, -35),
        Pair(14, -38), Pair(-35, -13), Pair(-20, 1), Pair(109, -51), Pair(52, -19), Pair(103, -47), Pair(108, -53), Pair(-18, -27),
        Pair(-45, -38), Pair(-41, 7), Pair(-74, -4), Pair(54, -51), Pair(24, -60), Pair(83, -33), Pair(4, -77), Pair(-63, -20),
        Pair(-99, -29), Pair(-87, 2), Pair(-105, 13), Pair(5, -38), Pair(-43, -8), Pair(-11, 17), Pair(58, -70), Pair(27, -63),
        Pair(-116, -30), Pair(-124, -17), Pair(-78, -29), Pair(-44, -22), Pair(7, -52), Pair(47, -63), Pair(30, -57), Pair(4, -52),
        Pair(-150, -53), Pair(-148, -61), Pair(-159, 16), Pair(-59, -64), Pair(-135, -6), Pair(-18, -72), Pair(-51, -9), Pair(-28, -68),
        Pair(-161, -16), Pair(-123, -28), Pair(-105, -2), Pair(-96, -30), Pair(-77, -23), Pair(-74, -31), Pair(-18, -42), Pair(-56, -77)
      },
      { // Piece 4
        Pair(26, -69), Pair(25, -57), Pair(171, -69), Pair(68, -48), Pair(29, -15), Pair(154, -102), Pair(104, -60), Pair(212, -151),
        Pair(125, -170), Pair(143, -101), Pair(51, -67), Pair(229, -85), Pair(103, -10), Pair(231, -110), Pair(224, -130), Pair(341, -196),
        Pair(-17, -17), Pair(-36, -40), Pair(16, -73), Pair(66, -51), Pair(176, -6), Pair(321, -110), Pair(237, -137), Pair(353, -254),
        Pair(-56, -75), Pair(24, -71), Pair(-103, -14), Pair(-14, -11), Pair(100, -72), Pair(87, 72), Pair(70, -151), Pair(-48, -20),
        Pair(-49, -62), Pair(-9, -76), Pair(48, -27), Pair(13, -18), Pair(157, -76), Pair(148, -140), Pair(70, -73), Pair(38, 30),
        Pair(-61, -89), Pair(-123, 24), Pair(-20, -29), Pair(-31, -43), Pair(87, -111), Pair(122, -88), Pair(113, -59), Pair(52, -35),
        Pair(82, -164), Pair(-33, -67), Pair(-17, -60), Pair(-20, 3), Pair(30, -97), Pair(21, -62), Pair(-21, -79), Pair(-61, -15),
        Pair(-142, -51), Pair(-30, -89), Pair(49, -106), Pair(-36, 6), Pair(-82, -84), Pair(9, -110), Pair(-14, -135), Pair(21, 29)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(56, -12), Pair(114, -11), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(56, 1), Pair(61, -44)
      }
    }},
    {{ // Bucket 5
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(121, 101), Pair(119, 133), Pair(-7, 137), Pair(76, 133), Pair(102, 117), Pair(127, 124), Pair(99, 72), Pair(-15, 164),
        Pair(26, 61), Pair(21, 70), Pair(-55, 69), Pair(54, 11), Pair(-30, 68), Pair(78, 3), Pair(15, 70), Pair(14, 76),
        Pair(-7, -16), Pair(-38, -11), Pair(-75, -27), Pair(-77, -42), Pair(-26, -49), Pair(24, -63), Pair(-38, -26), Pair(-69, 1),
        Pair(-103, -20), Pair(-87, -38), Pair(-60, -50), Pair(-106, -57), Pair(-71, -53), Pair(17, -83), Pair(-63, -43), Pair(-27, -46),
        Pair(-76, -44), Pair(-35, -46), Pair(-74, -52), Pair(-69, -38), Pair(-31, -44), Pair(-41, -37), Pair(-3, -52), Pair(4, -69),
        Pair(-102, -8), Pair(-29, -19), Pair(7, -44), Pair(95, -30), Pair(78, -26), Pair(92, -38), Pair(78, -35), Pair(6, -48),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-115, -188), Pair(-33, -143), Pair(-128, -116), Pair(-18, -87), Pair(2, -35), Pair(-75, -51), Pair(-48, -115), Pair(-12, -145),
        Pair(79, -102), Pair(2, -38), Pair(90, -105), Pair(15, -12), Pair(106, -46), Pair(28, -63), Pair(-4, -50), Pair(-134, -107),
        Pair(71, -104), Pair(22, -60), Pair(102, -36), Pair(65, -31), Pair(146, -72), Pair(77, -61), Pair(-46, -62), Pair(18, -106),
        Pair(19, -88), Pair(-26, -2), Pair(58, -15), Pair(178, -53), Pair(183, -63), Pair(119, -27), Pair(21, -21), Pair(-25, -74),
        Pair(-34, -30), Pair(-87, -19), Pair(87, -38), Pair(106, -26), Pair(165, -53), Pair(182, -48), Pair(74, -52), Pair(132, -59),
        Pair(-46, -110), Pair(-60, -37), Pair(45, -29), Pair(126, -24), Pair(130, -53), Pair(87, -41), Pair(70, -24), Pair(117, -170),
        Pair(10, -50), Pair(-73, -69), Pair(37, -68), Pair(-90, -28), Pair(-36, -40), Pair(21, -21), Pair(-26, -54), Pair(58, -81),
        Pair(27, -173), Pair(-154, -93), Pair(32, -55), Pair(1, -60), Pair(-90, -11), Pair(-6, -85), Pair(17, -88), Pair(-6, -223)
      },
      { // Piece 2
        Pair(47, 17), Pair(-142, 32), Pair(-134, -12), Pair(-149, 6), Pair(-223, -3), Pair(-62, -4), Pair(-239, -3), Pair(-64, -37),
        Pair(-198, 38), Pair(-125, 31), Pair(-165, -3), Pair(-207, 37), Pair(8, 7), Pair(-80, -18), Pair(-136, -10), Pair(-87, -9),
        Pair(-50, -47), Pair(-92, -6), Pair(-88, 2), Pair(-141, 28), Pair(-148, 22), Pair(-67, -8), Pair(-43, 0), Pair(-45, -42),
        Pair(-105, -30), Pair(-135, 16), Pair(-66, 6), Pair(-93, 7), Pair(45, -7), Pair(-70, 17), Pair(-94, 22), Pair(-79, -30),
        Pair(-134, -86), Pair(-83, -40), Pair(-26, -20), Pair(-9, -31), Pair(41, 8), Pair(-21, -20), Pair(-122, -10), Pair(76, -39),
        Pair(-81, -48), Pair(68, -82), Pair(-95, -58), Pair(-71, -28), Pair(52, -82), Pair(106, -37), Pair(58, -26), Pair(51, -103),
        Pair(-114, -3), Pair(-73, -21), Pair(-61, 12), Pair(-139, -20), Pair(16, -54), Pair(-5, -52), Pair(69, -89), Pair(-235, 13),
        Pair(-94, -119), Pair(-47, -98), Pair(-23, -9), Pair(9, -35), Pair(-66, -21), Pair(16, -73), Pair(-26, -58), Pair(-55, -59)
      },
      { // Piece 3
        Pair(33, -99), Pair(-60, -74), Pair(-58, -38), Pair(-8, -57), Pair(-94, -40), Pair(-27, -17), Pair(-172, -10), Pair(-78, -45),
        Pair(-92, -68), Pair(-47, -79), Pair(-85, -71), Pair(-32, -58), Pair(27, -81), Pair(-6, -92), Pair(56, -106), Pair(-130, -64),
        Pair(-151, -70), Pair(95, -115), Pair(-87, -51), Pair(-31, -72), Pair(19, -95), Pair(7, -64), Pair(51, -103), Pair(-25, -82),
        Pair(51, -115), Pair(17, -115), Pair(-70, -73), Pair(-61, -83), Pair(67, -105), Pair(106, -104), Pair(32, -103), Pair(-2, -104),
        Pair(33, -129), Pair(-16, -132), Pair(85, -121), Pair(-12, -123), Pair(42, -129), Pair(6, -84), Pair(-31, -123), Pair(-87, -79),
        Pair(-100, -104), Pair(-24, -109), Pair(-106, -81), Pair(45, -129), Pair(-5, -78), Pair(82, -112), Pair(30, -121), Pair(-41, -105),
        Pair(-74, -106), Pair(9, -144), Pair(-106, -92), Pair(-79, -89), Pair(-9, -120), Pair(-20, -92), Pair(91, -180), Pair(-18, -108),
        Pair(-201, -105), Pair(-44, -111), Pair(-62, -86), Pair(29, -128), Pair(30, -114), Pair(47, -116), Pair(36, -121), Pair(82, -208)
      },
      { // Piece 4
        Pair(170, -314), Pair(-74, -186), Pair(22, -114), Pair(70, -166), Pair(108, -187), Pair(-73, -114), Pair(-160, -105), Pair(-160, -69),
        Pair(19, -208), Pair(41, -221), Pair(38, -190), Pair(-39, -99), Pair(58, -116), Pair(15, -173), Pair(35, -168), Pair(-5, -170),
        Pair(-99, -174), Pair(83, -251), Pair(-47, -129), Pair(-13, -180), Pair(28, -158), Pair(152, -171), Pair(147, -246), Pair(119, -234),
        Pair(-9, -221), Pair(-87, -79), Pair(-5, -127), Pair(-6, -48), Pair(145, -142), Pair(140, -205), Pair(-63, -156), Pair(226, -259),
        Pair(40, -179), Pair(3, -130), Pair(7, -78), Pair(-174, 6), Pair(-74, -105), Pair(110, -105), Pair(110, -210), Pair(50, -225),
        Pair(-83, -81), Pair(-125, -98), Pair(-1, -129), Pair(19, -203), Pair(35, -57), Pair(101, -116), Pair(121, -161), Pair(66, -174),
        Pair(36, -175), Pair(-93, -128), Pair(-66, -93), Pair(148, -246), Pair(66, -152), Pair(-4, -159), Pair(65, -193), Pair(-43, -160),
        Pair(-60, -147), Pair(-7, -125), Pair(4, -208), Pair(50, -196), Pair(101, -179), Pair(118, -199), Pair(-16, -110), Pair(-2, -171)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-57, 39), Pair(61, 25), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(65, 20), Pair(41, -16)
      }
    }},
    {{ // Bucket 6
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-4, 122), Pair(78, 75), Pair(62, 175), Pair(93, 121), Pair(80, 145), Pair(18, 51), Pair(-20, 66), Pair(19, 100),
        Pair(-21, 110), Pair(-60, 98), Pair(55, 0), Pair(-29, 96), Pair(-60, 49), Pair(14, -11), Pair(-81, 122), Pair(70, 107),
        Pair(11, -22), Pair(-16, -8), Pair(-50, -10), Pair(-77, -35), Pair(-147, 42), Pair(-56, -59), Pair(5, 38), Pair(21, -26),
        Pair(-112, -94), Pair(-106, -62), Pair(-19, -93), Pair(-19, -84), Pair(-65, -97), Pair(6, -42), Pair(-52, -26), Pair(-74, -38),
        Pair(-118, -57), Pair(-103, -39), Pair(-70, 30), Pair(9, -21), Pair(-123, -28), Pair(-35, -16), Pair(-91, -33), Pair(104, -119),
        Pair(46, -106), Pair(-56, -54), Pair(-13, -52), Pair(24, -182), Pair(12, 9), Pair(58, -37), Pair(0, -38), Pair(53, -72),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(6, -69), Pair(-35, -123), Pair(-58, -65), Pair(32, 4), Pair(13, -82), Pair(-1, -53), Pair(-4, -29), Pair(-9, -98),
        Pair(14, 94), Pair(-30, 44), Pair(18, -48), Pair(-75, 92), Pair(-9, -27), Pair(8, -29), Pair(-112, -143), Pair(-55, -157),
        Pair(-25, -55), Pair(-5, -47), Pair(-36, -77), Pair(-92, -15), Pair(-93, 0), Pair(-49, -47), Pair(-39, 158), Pair(-98, -98),
        Pair(11, -71), Pair(30, -5), Pair(68, -9), Pair(15, -47), Pair(16, -50), Pair(32, -19), Pair(-7, -4), Pair(35, -76),
        Pair(37, -46), Pair(31, -58), Pair(-23, -15), Pair(74, -41), Pair(37, -13), Pair(-68, -79), Pair(44, 44), Pair(-9, -35),
        Pair(36, -60), Pair(40, -27), Pair(2, -34), Pair(42, 10), Pair(79, -71), Pair(61, 41), Pair(-30, -176), Pair(31, -3),
        Pair(27, 82), Pair(3, 22), Pair(-25, -105), Pair(91, -120), Pair(40, -12), Pair(63, -46), Pair(-10, -32), Pair(-31, -62),
        Pair(15, 19), Pair(16, -46), Pair(-7, 22), Pair(12, 79), Pair(-34, -73), Pair(-53, 29), Pair(14, -19), Pair(14, 19)
      },
      { // Piece 2
        Pair(-85, 27), Pair(-58, 6), Pair(-11, 23), Pair(-23, 64), Pair(-2, 54), Pair(32, -45), Pair(-22, 1), Pair(-17, -29),
        Pair(-38, -12), Pair(-61, 6), Pair(42, 24), Pair(-40, -38), Pair(89, 93), Pair(21, 67), Pair(4, -8), Pair(-19, -17),
        Pair(-20, -39), Pair(-16, 52), Pair(-30, 62), Pair(-45, -47), Pair(28, 55), Pair(-3, 36), Pair(4, 121), Pair(13, 41),
        Pair(27, 14), Pair(-48, 38), Pair(63, 14), Pair(88, 22), Pair(-38, 29), Pair(-32, 102), Pair(161, 5), Pair(-30, -30),
        Pair(-69, 40), Pair(28, -2), Pair(66, 42), Pair(-12, 65), Pair(61, 1), Pair(41, 54), Pair(-47, 44), Pair(-71, -113),
        Pair(26, 40), Pair(97, -80), Pair(54, 89), Pair(-27, -69), Pair(15, -76), Pair(90, 27), Pair(9, 14), Pair(-4, 42),
        Pair(0, -72), Pair(-4, 55), Pair(69, -29), Pair(-46, -42), Pair(-58, -54), Pair(-83, 41), Pair(-6, 8), Pair(27, -7),
        Pair(3, -77), Pair(54, 47), Pair(-23, -75), Pair(-92, -74), Pair(-2, -61), Pair(59, -13), Pair(-42, -68), Pair(-9, -85)
      },
      { // Piece 3
        Pair(-22, -24), Pair(15, 1), Pair(16, 15), Pair(-57, 18), Pair(11, -18), Pair(21, 49), Pair(-68, 34), Pair(-26, 38),
        Pair(-76, -36), Pair(-37, -23), Pair(15, -18), Pair(-146, 4), Pair(7, 14), Pair(-33, -42), Pair(-67, 44), Pair(-77, 49),
        Pair(67, -29), Pair(-13, -49), Pair(82, -53), Pair(-10, 11), Pair(-40, -27), Pair(-78, -9), Pair(4, 26), Pair(-93, -61),
        Pair(93, -27), Pair(-36, 37), Pair(96, -123), Pair(87, -58), Pair(38, 37), Pair(39, 31), Pair(-98, -22), Pair(53, -62),
        Pair(-44, -1), Pair(51, 11), Pair(13, -18), Pair(37, 28), Pair(-45, 20), Pair(-78, 38), Pair(18, 2), Pair(-1, -39),
        Pair(23, -56), Pair(91, -32), Pair(52, -41), Pair(28, -21), Pair(112, -58), Pair(130, 41), Pair(-49, -42), Pair(-26, -76),
        Pair(-7, -49), Pair(55, -22), Pair(169, -30), Pair(36, 20), Pair(12, -59), Pair(-10, -33), Pair(-28, -45), Pair(4, -72),
        Pair(152, -159), Pair(11, -34), Pair(12, -61), Pair(19, -17), Pair(2, 17), Pair(190, -37), Pair(75, -111), Pair(5, -7)
      },
      { // Piece 4
        Pair(-157, -135), Pair(32, -57), Pair(-26, -47), Pair(-105, -123), Pair(-119, -116), Pair(-50, -118), Pair(29, 14), Pair(-69, -64),
        Pair(8, -125), Pair(58, -97), Pair(-66, -87), Pair(-3, -68), Pair(-31, -90), Pair(-93, -85), Pair(11, 68), Pair(-81, -97),
        Pair(-1, -57), Pair(-19, -87), Pair(-13, -28), Pair(-27, -57), Pair(-45, -176), Pair(-43, -71), Pair(-112, -99), Pair(-56, -192),
        Pair(36, -62), Pair(27, -107), Pair(77, -68), Pair(48, -64), Pair(15, -34), Pair(37, -64), Pair(-14, -34), Pair(-38, -90),
        Pair(-17, -117), Pair(46, -29), Pair(-28, -89), Pair(-39, -46), Pair(52, -99), Pair(8, 6), Pair(44, 7), Pair(-29, -4),
        Pair(-48, -120), Pair(32, -155), Pair(95, 52), Pair(43, -52), Pair(37, 52), Pair(-16, -59), Pair(62, -15), Pair(-3, -70),
        Pair(16, -48), Pair(-48, -94), Pair(-5, -15), Pair(-12, -50), Pair(20, -60), Pair(-81, -52), Pair(3, -51), Pair(-14, 19),
        Pair(4, -50), Pair(23, -26), Pair(50, 15), Pair(25, -74), Pair(92, -33), Pair(-29, -43), Pair(-44, -144), Pair(-48, -107)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-145, 56), Pair(-18, 44), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(5, 45), Pair(-39, 27)
      }
    }}
  }},
  {{ // Bucket 1
    {{ // Bucket 0
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(138, 281), Pair(89, 278), Pair(25, 271), Pair(97, 231), Pair(162, 124), Pair(56, 140), Pair(26, -23), Pair(-51, -14),
        Pair(-26, 161), Pair(18, 147), Pair(26, 151), Pair(20, 89), Pair(44, 52), Pair(107, -15), Pair(31, 63), Pair(-38, 38),
        Pair(-20, 40), Pair(7, 31), Pair(1, 2), Pair(16, -25), Pair(43, -43), Pair(45, -34), Pair(5, 1), Pair(-56, 18),
        Pair(-23, 3), Pair(-4, 11), Pair(-2, -19), Pair(13, -30), Pair(25, -42), Pair(14, -31), Pair(-1, -16), Pair(-57, -5),
        Pair(-19, -4), Pair(-3, 11), Pair(-3, -19), Pair(-7, -14), Pair(24, -13), Pair(-4, -18), Pair(-1, -2), Pair(-55, -12),
        Pair(-24, 0), Pair(9, 18), Pair(-8, 13), Pair(0, 15), Pair(-1, 13), Pair(15, -7), Pair(3, 2), Pair(-58, -17),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-241, 4), Pair(-313, 119), Pair(-187, 143), Pair(-99, 106), Pair(-4, 41), Pair(-163, 27), Pair(-100, 45), Pair(-165, -42),
        Pair(-10, -15), Pair(-32, 55), Pair(18, 58), Pair(41, 90), Pair(56, 55), Pair(92, 66), Pair(-67, 76), Pair(54, 4),
        Pair(-23, 63), Pair(59, 65), Pair(38, 107), Pair(46, 107), Pair(106, 80), Pair(64, 138), Pair(39, 105), Pair(32, 47),
        Pair(4, 55), Pair(16, 100), Pair(32, 109), Pair(51, 134), Pair(29, 154), Pair(75, 123), Pair(31, 124), Pair(19, 90),
        Pair(-15, 24), Pair(-13, 113), Pair(11, 114), Pair(13, 120), Pair(22, 115), Pair(27, 106), Pair(38, 91), Pair(-15, 36),
        Pair(-34, 17), Pair(-8, 52), Pair(3, 69), Pair(-6, 106), Pair(15, 86), Pair(1, 76), Pair(-1, 64), Pair(-32, 17),
        Pair(-38, -13), Pair(-56, 36), Pair(-21, 33), Pair(-15, 62), Pair(-18, 66), Pair(-7, 53), Pair(-44, 24), Pair(-35, -44),
        Pair(-132, 20), Pair(-39, -30), Pair(-49, 5), Pair(-40, 43), Pair(-17, 58), Pair(-60, 48), Pair(-42, -13), Pair(-158, 25)
      },
      { // Piece 2
        Pair(-45, 79), Pair(-128, 98), Pair(-78, 25), Pair(-120, 99), Pair(-168, 70), Pair(-104, -26), Pair(-139, 78), Pair(-130, 90),
        Pair(-41, 31), Pair(17, 52), Pair(-23, 79), Pair(-62, 113), Pair(10, 64), Pair(12, 71), Pair(-6, 65), Pair(-4, 36),
        Pair(-12, 36), Pair(-7, 86), Pair(19, 88), Pair(24, 61), Pair(57, 37), Pair(64, 79), Pair(81, 42), Pair(15, 55),
        Pair(-15, 45), Pair(20, 69), Pair(12, 86), Pair(44, 94), Pair(41, 88), Pair(42, 57), Pair(16, 65), Pair(-33, 85),
        Pair(-36, 44), Pair(9, 62), Pair(8, 81), Pair(29, 82), Pair(30, 83), Pair(11, 45), Pair(-1, 51), Pair(-12, -19),
        Pair(-10, 8), Pair(20, 31), Pair(2, 74), Pair(6, 70), Pair(1, 73), Pair(3, 56), Pair(-5, 43), Pair(-17, -8),
        Pair(8, -8), Pair(7, 14), Pair(22, 16), Pair(-17, 45), Pair(-8, 37), Pair(4, 48), Pair(1, 22), Pair(-19, -21),
        Pair(7, 5), Pair(-13, 24), Pair(-34, 0), Pair(-29, 46), Pair(-44, 53), Pair(-23, -23), Pair(-32, 2), Pair(-36, 3)
      },
      { // Piece 3
        Pair(99, 78), Pair(24, 146), Pair(-10, 152), Pair(39, 93), Pair(-46, 190), Pair(10, 123), Pair(88, 102), Pair(-79, 171),
        Pair(2, 120), Pair(1, 121), Pair(-6, 150), Pair(61, 120), Pair(79, 116), Pair(74, 122), Pair(43, 107), Pair(89, 78),
        Pair(-3, 89), Pair(30, 80), Pair(3, 108), Pair(60, 63), Pair(106, 57), Pair(75, 71), Pair(102, 67), Pair(38, 56),
        Pair(-14, 75), Pair(12, 68), Pair(-1, 102), Pair(36, 88), Pair(55, 80), Pair(60, 69), Pair(42, 40), Pair(32, 38),
        Pair(-27, 50), Pair(-45, 97), Pair(-27, 92), Pair(-20, 104), Pair(1, 49), Pair(12, 44), Pair(18, 14), Pair(6, 27),
        Pair(-47, 38), Pair(-49, 63), Pair(-43, 81), Pair(-27, 60), Pair(-25, 58), Pair(-15, 28), Pair(27, 0), Pair(-3, -9),
        Pair(-71, 23), Pair(-40, 17), Pair(-51, 60), Pair(-45, 59), Pair(-12, 29), Pair(-22, 55), Pair(10, -36), Pair(-24, -24),
        Pair(-32, 8), Pair(-33, 32), Pair(-21, 46), Pair(-26, 57), Pair(-4, 30), Pair(-16, 15), Pair(8, -18), Pair(6, -43)
      },
      { // Piece 4
        Pair(-139, 239), Pair(-57, 192), Pair(-117, 279), Pair(-30, 224), Pair(-40, 191), Pair(65, 147), Pair(-68, 40), Pair(97, 87),
        Pair(-31, 85), Pair(-58, 127), Pair(-42, 150), Pair(-74, 234), Pair(-18, 226), Pair(-21, 263), Pair(-94, 228), Pair(13, 61),
        Pair(-17, 56), Pair(-31, 111), Pair(-46, 154), Pair(-5, 100), Pair(-21, 202), Pair(23, 235), Pair(66, 182), Pair(55, 144),
        Pair(-36, 83), Pair(-42, 147), Pair(-21, 71), Pair(-25, 147), Pair(-45, 222), Pair(-8, 212), Pair(-1, 177), Pair(-1, 164),
        Pair(-26, 19), Pair(-12, 62), Pair(-37, 85), Pair(-27, 160), Pair(-45, 178), Pair(-26, 137), Pair(-7, 92), Pair(6, 107),
        Pair(-36, 7), Pair(-20, 22), Pair(-20, 79), Pair(-29, 97), Pair(-37, 119), Pair(-29, 113), Pair(-15, 58), Pair(-2, 61),
        Pair(-36, -53), Pair(-21, -13), Pair(-8, -39), Pair(-15, 16), Pair(-32, 33), Pair(-18, 5), Pair(7, -25), Pair(6, -64),
        Pair(-15, -51), Pair(-44, -38), Pair(-24, -38), Pair(-21, -31), Pair(-54, -7), Pair(-61, 12), Pair(-22, -41), Pair(-15, -33)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(24, 19), Pair(-86, 23), Pair(-10, -13), Pair(-40, 25), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 1
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(81, 254), Pair(52, 259), Pair(37, 118), Pair(3, 75), Pair(90, 39), Pair(52, 81), Pair(27, 137), Pair(122, 227),
        Pair(-41, 117), Pair(-10, 112), Pair(-1, 90), Pair(23, 34), Pair(32, 16), Pair(29, 25), Pair(-16, 96), Pair(-29, 62),
        Pair(-32, 36), Pair(-9, 26), Pair(-6, 6), Pair(10, -20), Pair(9, -23), Pair(16, -22), Pair(2, 26), Pair(-36, 11),
        Pair(-46, 10), Pair(-21, 9), Pair(-15, -42), Pair(-6, -18), Pair(-2, -23), Pair(-10, -22), Pair(-13, 0), Pair(-51, -14),
        Pair(-38, -11), Pair(-28, 13), Pair(-19, -19), Pair(-25, -9), Pair(-8, -4), Pair(-21, -22), Pair(1, 4), Pair(-45, -33),
        Pair(-46, -7), Pair(-15, 17), Pair(-25, 3), Pair(-25, 10), Pair(-27, 5), Pair(0, -7), Pair(-6, 3), Pair(-48, -40),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-175, -72), Pair(-128, 90), Pair(-122, 110), Pair(-106, 50), Pair(-79, 54), Pair(-20, 4), Pair(-191, 109), Pair(-174, -40),
        Pair(-3, 74), Pair(-40, 54), Pair(18, 67), Pair(-25, 81), Pair(-9, 90), Pair(26, 105), Pair(-41, 89), Pair(-3, 79),
        Pair(-84, 88), Pair(7, 124), Pair(-3, 162), Pair(55, 82), Pair(66, 134), Pair(19, 152), Pair(25, 61), Pair(-23, 36),
        Pair(-18, 113), Pair(-1, 141), Pair(26, 130), Pair(15, 168), Pair(6, 165), Pair(36, 139), Pair(1, 137), Pair(-5, 81),
        Pair(-44, 85), Pair(-12, 83), Pair(-20, 139), Pair(-11, 131), Pair(-11, 136), Pair(-13, 138), Pair(-18, 85), Pair(-26, 78),
        Pair(-57, 38), Pair(-37, 97), Pair(-29, 89), Pair(-27, 107), Pair(-16, 119), Pair(-27, 88), Pair(-28, 77), Pair(-54, 32),
        Pair(-53, -1), Pair(-66, 76), Pair(-41, 108), Pair(-45, 79), Pair(-44, 84), Pair(-30, 76), Pair(-49, 17), Pair(-68, -6),
        Pair(-150, 12), Pair(-63, 5), Pair(-75, 40), Pair(-38, 49), Pair(-74, 103), Pair(-60, 20), Pair(-58, 20), Pair(-69, -38)
      },
      { // Piece 2
        Pair(-80, 123), Pair(-167, 120), Pair(-83, 39), Pair(-117, 101), Pair(-110, 30), Pair(-187, 164), Pair(10, 85), Pair(-105, 65),
        Pair(-54, 34), Pair(-55, 86), Pair(-25, 70), Pair(-100, 131), Pair(-83, 115), Pair(-5, 59), Pair(-32, 85), Pair(-54, 22),
        Pair(-40, 65), Pair(-38, 104), Pair(6, 88), Pair(23, 64), Pair(59, 49), Pair(20, 114), Pair(-14, 97), Pair(-28, 85),
        Pair(-20, 59), Pair(-5, 82), Pair(9, 67), Pair(-6, 116), Pair(2, 98), Pair(23, 93), Pair(-3, 82), Pair(-27, 85),
        Pair(-29, 42), Pair(-11, 56), Pair(-13, 74), Pair(-15, 96), Pair(-10, 69), Pair(-25, 95), Pair(-14, 64), Pair(-24, 50),
        Pair(-30, 31), Pair(-16, 59), Pair(-25, 66), Pair(-21, 59), Pair(-29, 73), Pair(-25, 77), Pair(-25, 37), Pair(-28, 16),
        Pair(-42, 54), Pair(-23, 51), Pair(-16, 34), Pair(-42, 54), Pair(-37, 48), Pair(-34, 55), Pair(-26, 38), Pair(-34, -4),
        Pair(-35, 31), Pair(-41, -43), Pair(-57, 6), Pair(-46, 31), Pair(-60, 40), Pair(-50, 5), Pair(-61, 24), Pair(-55, 25)
      },
      { // Piece 3
        Pair(86, 80), Pair(25, 140), Pair(23, 112), Pair(56, 73), Pair(66, 55), Pair(-37, 150), Pair(62, 78), Pair(48, 103),
        Pair(-20, 130), Pair(-39, 155), Pair(-2, 149), Pair(55, 117), Pair(35, 135), Pair(38, 141), Pair(-36, 143), Pair(22, 135),
        Pair(-61, 135), Pair(-12, 114), Pair(-4, 93), Pair(-4, 110), Pair(63, 66), Pair(-10, 134), Pair(49, 71), Pair(-33, 125),
        Pair(-51, 108), Pair(-25, 64), Pair(-19, 97), Pair(-33, 90), Pair(-29, 105), Pair(-6, 84), Pair(-21, 115), Pair(-24, 59),
        Pair(-71, 86), Pair(-60, 104), Pair(-54, 77), Pair(-42, 83), Pair(-33, 107), Pair(-29, 33), Pair(-58, 93), Pair(-41, 64),
        Pair(-68, 8), Pair(-46, 34), Pair(-67, 62), Pair(-69, 90), Pair(-18, 11), Pair(-63, 63), Pair(-34, 39), Pair(-58, 62),
        Pair(-106, 18), Pair(-87, 66), Pair(-64, 65), Pair(-65, 46), Pair(-66, 65), Pair(-53, 54), Pair(-36, -19), Pair(-93, 72),
        Pair(-73, 11), Pair(-68, 41), Pair(-57, 35), Pair(-55, 54), Pair(-21, 27), Pair(-48, 23), Pair(-46, 15), Pair(-43, -12)
      },
      { // Piece 4
        Pair(-18, 103), Pair(24, 132), Pair(101, 85), Pair(-18, 178), Pair(18, 88), Pair(-5, 130), Pair(55, 169), Pair(-31, 174),
        Pair(2, 107), Pair(-56, 151), Pair(21, 181), Pair(10, 139), Pair(11, 89), Pair(-1, 144), Pair(-1, 186), Pair(23, 134),
        Pair(-33, 150), Pair(-6, 130), Pair(-19, 197), Pair(14, 232), Pair(38, 232), Pair(-12, 208), Pair(39, 206), Pair(-25, 184),
        Pair(9, 76), Pair(-4, 95), Pair(16, 108), Pair(11, 198), Pair(7, 153), Pair(-3, 209), Pair(9, 186), Pair(14, 60),
        Pair(0, 15), Pair(13, 51), Pair(9, 54), Pair(-12, 117), Pair(-9, 108), Pair(7, 82), Pair(12, 82), Pair(-9, 61),
        Pair(3, -2), Pair(8, 20), Pair(6, 32), Pair(-1, 53), Pair(-11, 63), Pair(2, 50), Pair(-2, 79), Pair(-13, 68),
        Pair(8, -50), Pair(7, -9), Pair(11, -65), Pair(1, -28), Pair(2, -34), Pair(13, -30), Pair(13, -51), Pair(4, -18),
        Pair(-1, -15), Pair(0, -98), Pair(1, -69), Pair(2, -65), Pair(-30, 1), Pair(-48, -40), Pair(-20, -64), Pair(16, -35)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(27, 6), Pair(-43, -2), Pair(-6, -12), Pair(-34, 5), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 2
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(109, 195), Pair(139, 183), Pair(94, 169), Pair(124, 125), Pair(100, 102), Pair(64, 103), Pair(53, 165), Pair(62, 122),
        Pair(-26, 140), Pair(29, 105), Pair(32, 87), Pair(46, 32), Pair(75, 20), Pair(65, 7), Pair(19, 33), Pair(-32, 42),
        Pair(-50, 49), Pair(4, 22), Pair(-1, 1), Pair(13, -31), Pair(39, -38), Pair(42, -34), Pair(19, 1), Pair(-32, -4),
        Pair(-41, 12), Pair(-23, 15), Pair(-7, -21), Pair(1, -24), Pair(19, -39), Pair(-7, -22), Pair(6, -14), Pair(-53, -5),
        Pair(-35, -1), Pair(-9, 8), Pair(-14, -15), Pair(-21, -9), Pair(13, -13), Pair(-17, -9), Pair(-1, 2), Pair(-51, -14),
        Pair(-35, 6), Pair(3, 9), Pair(-6, 3), Pair(-22, 16), Pair(-4, 2), Pair(6, -6), Pair(1, 0), Pair(-64, -3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-160, -131), Pair(-127, 50), Pair(-155, 43), Pair(26, 39), Pair(68, 41), Pair(42, 112), Pair(54, 0), Pair(-89, -129),
        Pair(25, -31), Pair(22, 37), Pair(51, 48), Pair(111, 33), Pair(53, 64), Pair(60, 39), Pair(-16, 31), Pair(42, -40),
        Pair(-14, 30), Pair(9, 73), Pair(79, 82), Pair(82, 79), Pair(122, 91), Pair(90, 97), Pair(54, 53), Pair(15, 4),
        Pair(-9, 60), Pair(38, 65), Pair(60, 105), Pair(60, 106), Pair(69, 125), Pair(82, 102), Pair(40, 91), Pair(84, -9),
        Pair(-27, 57), Pair(26, 81), Pair(17, 115), Pair(48, 105), Pair(48, 106), Pair(45, 112), Pair(41, 80), Pair(-8, 51),
        Pair(-29, 5), Pair(-6, 58), Pair(-5, 80), Pair(13, 96), Pair(13, 96), Pair(1, 70), Pair(18, 46), Pair(-46, 40),
        Pair(-93, 29), Pair(-49, 50), Pair(-50, 61), Pair(-21, 65), Pair(-17, 68), Pair(-5, 44), Pair(-85, 51), Pair(-79, -15),
        Pair(-79, -50), Pair(-67, 7), Pair(-56, 17), Pair(-36, 34), Pair(-71, 58), Pair(-95, 70), Pair(-57, 8), Pair(-84, -33)
      },
      { // Piece 2
        Pair(-63, 58), Pair(-88, 80), Pair(-60, 80), Pair(-192, 64), Pair(-89, 99), Pair(-174, 110), Pair(7, 43), Pair(-8, 87),
        Pair(-23, 2), Pair(21, 56), Pair(-30, 66), Pair(18, 63), Pair(-9, 88), Pair(9, 76), Pair(34, 27), Pair(31, 7),
        Pair(15, 10), Pair(23, 53), Pair(52, 59), Pair(89, 46), Pair(12, 68), Pair(70, 48), Pair(-10, 59), Pair(21, 8),
        Pair(-25, 27), Pair(26, 50), Pair(32, 55), Pair(71, 53), Pair(61, 69), Pair(87, 65), Pair(54, 40), Pair(-6, 46),
        Pair(-29, 45), Pair(37, 32), Pair(0, 70), Pair(50, 62), Pair(39, 62), Pair(35, 37), Pair(-11, 47), Pair(2, 19),
        Pair(-27, 43), Pair(9, 30), Pair(-6, 60), Pair(13, 56), Pair(22, 53), Pair(8, 53), Pair(17, 20), Pair(-13, 21),
        Pair(-58, 15), Pair(9, 11), Pair(3, 21), Pair(-3, 38), Pair(-16, 37), Pair(-2, 37), Pair(-4, 16), Pair(-10, -75),
        Pair(33, -34), Pair(42, 5), Pair(-45, 6), Pair(-30, 17), Pair(-7, 10), Pair(-40, 1), Pair(-69, 28), Pair(-9, -35)
      },
      { // Piece 3
        Pair(92, 62), Pair(37, 93), Pair(34, 107), Pair(65, 92), Pair(63, 98), Pair(-6, 145), Pair(43, 107), Pair(98, 79),
        Pair(-8, 97), Pair(33, 73), Pair(45, 79), Pair(26, 116), Pair(21, 95), Pair(19, 81), Pair(-28, 105), Pair(9, 113),
        Pair(5, 78), Pair(46, 78), Pair(-16, 106), Pair(12, 98), Pair(120, 42), Pair(76, 71), Pair(112, 42), Pair(42, 60),
        Pair(-36, 80), Pair(-16, 65), Pair(-35, 94), Pair(11, 91), Pair(-20, 107), Pair(31, 65), Pair(15, 53), Pair(11, 70),
        Pair(-92, 54), Pair(-59, 64), Pair(-64, 90), Pair(-59, 92), Pair(7, 62), Pair(-8, 52), Pair(-48, 61), Pair(-16, 56),
        Pair(-75, 47), Pair(-42, 46), Pair(-63, 51), Pair(-68, 66), Pair(-69, 71), Pair(-30, 59), Pair(13, 17), Pair(-14, 4),
        Pair(-62, 14), Pair(-92, 60), Pair(-64, 58), Pair(-46, 35), Pair(-61, 52), Pair(-25, 26), Pair(-52, 35), Pair(-65, 24),
        Pair(-65, 12), Pair(-57, 29), Pair(-55, 46), Pair(-63, 49), Pair(-32, 44), Pair(-13, 9), Pair(-14, 0), Pair(-13, -18)
      },
      { // Piece 4
        Pair(-16, 134), Pair(-10, 167), Pair(52, 131), Pair(13, 174), Pair(84, 151), Pair(7, 181), Pair(118, 85), Pair(41, 168),
        Pair(15, 73), Pair(-6, 77), Pair(-19, 154), Pair(-51, 224), Pair(-3, 176), Pair(63, 149), Pair(5, 172), Pair(17, 132),
        Pair(-6, 73), Pair(13, 84), Pair(17, 88), Pair(54, 83), Pair(97, 158), Pair(53, 214), Pair(39, 147), Pair(27, 131),
        Pair(1, 72), Pair(15, 116), Pair(31, 105), Pair(9, 138), Pair(39, 164), Pair(55, 230), Pair(86, 165), Pair(43, 139),
        Pair(26, 45), Pair(-6, 83), Pair(-4, 134), Pair(36, 108), Pair(35, 154), Pair(56, 127), Pair(39, 150), Pair(9, 151),
        Pair(-32, 46), Pair(10, 33), Pair(38, 58), Pair(15, 35), Pair(6, 101), Pair(3, 124), Pair(44, 79), Pair(-15, 99),
        Pair(-50, 28), Pair(12, -21), Pair(19, -12), Pair(22, 51), Pair(8, 40), Pair(10, 27), Pair(31, -17), Pair(29, -26),
        Pair(-34, 34), Pair(-32, -10), Pair(-4, -61), Pair(-4, 7), Pair(-46, 83), Pair(-36, -17), Pair(-26, -28), Pair(27, -10)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(51, -17), Pair(-61, -5), Pair(-14, -18), Pair(-19, -5), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 3
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(72, 178), Pair(146, 167), Pair(66, 163), Pair(92, 110), Pair(139, 66), Pair(55, 130), Pair(6, 193), Pair(13, 146),
        Pair(7, 97), Pair(41, 77), Pair(34, 38), Pair(62, 26), Pair(24, -28), Pair(33, 8), Pair(-20, 54), Pair(-27, 41),
        Pair(-68, 48), Pair(6, 9), Pair(-37, -5), Pair(13, -53), Pair(26, -63), Pair(34, -51), Pair(10, -23), Pair(-76, -4),
        Pair(-36, -4), Pair(-12, 7), Pair(-39, -24), Pair(-20, -19), Pair(-19, -25), Pair(9, -35), Pair(21, -8), Pair(-39, -21),
        Pair(-53, -4), Pair(-32, 5), Pair(-23, -19), Pair(-16, 0), Pair(3, -5), Pair(-23, -5), Pair(-3, -1), Pair(-36, -22),
        Pair(-37, -3), Pair(-4, -3), Pair(0, -8), Pair(6, -21), Pair(-25, 10), Pair(8, -11), Pair(4, -6), Pair(-79, -3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-63, -71), Pair(-152, -38), Pair(-137, 70), Pair(-25, 33), Pair(-47, 51), Pair(-97, 10), Pair(8, -2), Pair(-9, -208),
        Pair(3, -4), Pair(-15, 30), Pair(68, -24), Pair(47, 45), Pair(70, 5), Pair(191, -53), Pair(27, 2), Pair(-24, -4),
        Pair(62, -5), Pair(52, 40), Pair(49, 81), Pair(95, 36), Pair(160, 11), Pair(114, 36), Pair(-9, 75), Pair(106, -31),
        Pair(79, -6), Pair(78, 34), Pair(78, 74), Pair(128, 56), Pair(127, 71), Pair(143, 71), Pair(79, 47), Pair(48, 21),
        Pair(28, 5), Pair(22, 41), Pair(59, 58), Pair(51, 72), Pair(106, 65), Pair(125, 63), Pair(115, 46), Pair(10, 38),
        Pair(-11, -26), Pair(61, 27), Pair(28, 54), Pair(72, 61), Pair(-8, 84), Pair(23, 59), Pair(25, 47), Pair(-23, 10),
        Pair(-70, -8), Pair(-78, 42), Pair(8, 35), Pair(-32, 49), Pair(0, 45), Pair(9, 31), Pair(37, -8), Pair(-69, -49),
        Pair(-132, -84), Pair(-78, 14), Pair(3, -42), Pair(-70, 22), Pair(-23, 23), Pair(19, 2), Pair(-111, 38), Pair(-246, -47)
      },
      { // Piece 2
        Pair(-116, 10), Pair(-2, 1), Pair(-188, 39), Pair(-74, 40), Pair(-126, 35), Pair(-91, 17), Pair(59, 3), Pair(-126, 2),
        Pair(-33, -15), Pair(-14, 48), Pair(-73, 37), Pair(79, 18), Pair(-1, 45), Pair(51, 14), Pair(3, 44), Pair(10, 11),
        Pair(22, -3), Pair(-6, 32), Pair(24, 43), Pair(62, 35), Pair(-25, 53), Pair(-21, 49), Pair(6, 82), Pair(81, -10),
        Pair(-6, 12), Pair(20, 37), Pair(65, 7), Pair(19, 56), Pair(56, 52), Pair(88, 49), Pair(-4, 29), Pair(-37, 26),
        Pair(-11, -16), Pair(71, -1), Pair(-26, 45), Pair(100, 18), Pair(82, 32), Pair(41, 34), Pair(70, -4), Pair(7, -20),
        Pair(-56, -11), Pair(51, -1), Pair(41, 16), Pair(30, 24), Pair(59, 23), Pair(20, 36), Pair(-10, 8), Pair(-1, 6),
        Pair(21, 8), Pair(17, -6), Pair(-36, 35), Pair(8, 9), Pair(-7, 17), Pair(-20, 28), Pair(-38, 2), Pair(-13, -86),
        Pair(-64, -36), Pair(43, -40), Pair(-70, -17), Pair(-63, -2), Pair(-50, -14), Pair(-69, -12), Pair(-75, 2), Pair(8, -10)
      },
      { // Piece 3
        Pair(-2, 56), Pair(9, 46), Pair(-15, 64), Pair(-48, 78), Pair(-23, 80), Pair(-7, 85), Pair(36, 75), Pair(35, 59),
        Pair(14, 21), Pair(-42, 51), Pair(20, 34), Pair(71, 39), Pair(66, 42), Pair(84, 18), Pair(26, 28), Pair(71, 10),
        Pair(-44, 52), Pair(-4, 39), Pair(29, 28), Pair(19, 34), Pair(113, 12), Pair(8, 24), Pair(-85, 80), Pair(-37, 35),
        Pair(-58, 22), Pair(-48, 51), Pair(15, 46), Pair(47, 20), Pair(-43, 46), Pair(130, 0), Pair(7, 10), Pair(-47, 31),
        Pair(-97, 34), Pair(-37, 40), Pair(-40, 50), Pair(-68, 56), Pair(-44, 38), Pair(1, 41), Pair(-48, 48), Pair(-14, -9),
        Pair(-58, -21), Pair(-61, 3), Pair(-125, 37), Pair(-29, 2), Pair(-68, 24), Pair(-64, 10), Pair(-39, 37), Pair(-79, -4),
        Pair(-116, 3), Pair(-122, 11), Pair(-61, 7), Pair(-92, 22), Pair(-69, -6), Pair(-67, 15), Pair(-65, -25), Pair(-41, -43),
        Pair(-100, -22), Pair(-77, -9), Pair(-104, 16), Pair(-66, 19), Pair(-46, 13), Pair(-53, -6), Pair(-94, 12), Pair(-88, -25)
      },
      { // Piece 4
        Pair(-59, 12), Pair(109, 18), Pair(0, 80), Pair(5, 81), Pair(48, 93), Pair(110, 72), Pair(77, 143), Pair(53, 112),
        Pair(68, -59), Pair(15, 25), Pair(57, 37), Pair(93, 30), Pair(61, 93), Pair(5, 111), Pair(119, 28), Pair(140, 27),
        Pair(29, -28), Pair(-89, -4), Pair(105, -47), Pair(9, 77), Pair(73, 92), Pair(130, 97), Pair(112, -26), Pair(204, -101),
        Pair(63, -74), Pair(-4, -11), Pair(21, 39), Pair(113, 17), Pair(122, 31), Pair(38, 94), Pair(-16, 98), Pair(85, 15),
        Pair(-37, 43), Pair(-48, 2), Pair(56, 94), Pair(-5, 89), Pair(133, 39), Pair(95, -9), Pair(26, -2), Pair(74, 88),
        Pair(-76, 17), Pair(-7, 9), Pair(5, 10), Pair(7, 8), Pair(3, 6), Pair(31, 9), Pair(94, -20), Pair(94, -3),
        Pair(-56, 49), Pair(-10, -90), Pair(-3, -32), Pair(-15, -24), Pair(19, -40), Pair(13, -48), Pair(-88, 49), Pair(-9, -9),
        Pair(-51, -53), Pair(-10, -130), Pair(-19, -58), Pair(-14, -62), Pair(-79, -82), Pair(1, -50), Pair(-62, -144), Pair(-78, -18)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(67, -15), Pair(-63, 7), Pair(-3, -11), Pair(-14, 1), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 4
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(200, 139), Pair(-74, 198), Pair(119, 98), Pair(150, 87), Pair(42, 100), Pair(121, 112), Pair(-58, 221), Pair(144, 133),
        Pair(-61, 97), Pair(0, 92), Pair(6, 74), Pair(-20, 35), Pair(-42, 46), Pair(-16, 57), Pair(-81, 88), Pair(47, 77),
        Pair(-21, 12), Pair(-19, -6), Pair(-82, 2), Pair(-67, -32), Pair(-57, -49), Pair(-16, -52), Pair(-22, -10), Pair(-33, -9),
        Pair(-66, -12), Pair(-33, -6), Pair(-37, -32), Pair(-43, -28), Pair(-74, -20), Pair(-27, -50), Pair(-7, -28), Pair(-102, -17),
        Pair(-50, -29), Pair(-98, 6), Pair(-19, -32), Pair(-53, 14), Pair(-12, -8), Pair(-22, -8), Pair(-7, -2), Pair(-71, -22),
        Pair(-33, -15), Pair(-48, 9), Pair(3, -10), Pair(-33, 0), Pair(51, -22), Pair(48, -8), Pair(-11, -1), Pair(-68, -5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-114, -118), Pair(-37, -39), Pair(-118, 10), Pair(-17, -50), Pair(-88, 52), Pair(-99, 16), Pair(-26, 14), Pair(-31, -129),
        Pair(-110, -46), Pair(34, -24), Pair(-62, 13), Pair(-17, 67), Pair(-34, 29), Pair(133, -8), Pair(10, -7), Pair(19, -102),
        Pair(-37, -32), Pair(1, 11), Pair(94, 44), Pair(63, 20), Pair(53, 38), Pair(115, 35), Pair(32, -8), Pair(-60, 2),
        Pair(47, -45), Pair(-10, 36), Pair(113, 22), Pair(109, 49), Pair(73, 50), Pair(104, 40), Pair(129, 29), Pair(95, -44),
        Pair(-45, 16), Pair(-14, 16), Pair(112, 41), Pair(163, 25), Pair(104, 55), Pair(127, 14), Pair(162, -11), Pair(65, -19),
        Pair(-12, -27), Pair(7, 13), Pair(2, 25), Pair(67, 18), Pair(118, -20), Pair(-11, 31), Pair(-90, 48), Pair(-56, -29),
        Pair(-60, -21), Pair(-47, 14), Pair(-98, 8), Pair(-50, 49), Pair(11, 18), Pair(20, -4), Pair(-42, -32), Pair(8, -73),
        Pair(-75, -95), Pair(-175, 38), Pair(183, -103), Pair(-35, -23), Pair(30, -15), Pair(-12, 0), Pair(-150, 45), Pair(-23, -55)
      },
      { // Piece 2
        Pair(21, -36), Pair(-5, -2), Pair(-123, 3), Pair(-98, 35), Pair(-200, 38), Pair(-9, -16), Pair(-38, 6), Pair(-77, -1),
        Pair(-57, -46), Pair(44, 6), Pair(-30, -5), Pair(-27, 16), Pair(-39, -12), Pair(-30, 15), Pair(-36, 18), Pair(-136, 25),
        Pair(33, -34), Pair(-40, 7), Pair(42, 7), Pair(-140, 26), Pair(-183, 43), Pair(-37, 0), Pair(86, 0), Pair(121, -36),
        Pair(-131, 12), Pair(32, 10), Pair(-28, -5), Pair(104, -6), Pair(61, -30), Pair(29, -2), Pair(-26, 23), Pair(11, -26),
        Pair(53, -16), Pair(31, -2), Pair(-15, 2), Pair(203, -28), Pair(91, -26), Pair(3, 10), Pair(-97, -6), Pair(-30, -20),
        Pair(14, -1), Pair(-33, 14), Pair(-23, 25), Pair(113, -17), Pair(48, 9), Pair(25, 14), Pair(-23, -12), Pair(37, -24),
        Pair(-32, -23), Pair(-50, -4), Pair(-24, 10), Pair(-15, 3), Pair(-47, -7), Pair(-35, -6), Pair(-22, -46), Pair(-29, -17),
        Pair(-149, -14), Pair(-43, 28), Pair(-106, -3), Pair(-42, -17), Pair(14, -28), Pair(-87, -10), Pair(27, -9), Pair(-18, 8)
      },
      { // Piece 3
        Pair(61, -23), Pair(-34, -16), Pair(-136, 21), Pair(-9, 18), Pair(-53, 20), Pair(-30, 23), Pair(-117, 33), Pair(-78, 12),
        Pair(-102, -2), Pair(-49, -26), Pair(-65, -21), Pair(-38, -10), Pair(-69, 2), Pair(-4, -31), Pair(-8, -8), Pair(-26, -39),
        Pair(-116, -10), Pair(-21, -20), Pair(30, -15), Pair(2, -5), Pair(52, -53), Pair(137, -47), Pair(42, -38), Pair(-7, -55),
        Pair(-90, -19), Pair(-7, -39), Pair(-29, -8), Pair(37, -35), Pair(-2, -13), Pair(12, -26), Pair(4, -61), Pair(-33, -33),
        Pair(-20, -49), Pair(-42, -47), Pair(-17, -21), Pair(-77, -24), Pair(-68, -41), Pair(27, -30), Pair(-79, 11), Pair(-64, -37),
        Pair(-35, -79), Pair(-100, -42), Pair(-99, -31), Pair(-67, -39), Pair(-54, -35), Pair(-14, -29), Pair(-16, -39), Pair(-144, -21),
        Pair(-95, -106), Pair(-100, -52), Pair(9, -67), Pair(-26, -90), Pair(-45, -29), Pair(-145, 1), Pair(-62, -25), Pair(-123, -34),
        Pair(-112, -74), Pair(-89, -60), Pair(-14, -71), Pair(-35, -61), Pair(0, -61), Pair(44, -80), Pair(-56, -73), Pair(-110, -64)
      },
      { // Piece 4
        Pair(69, -33), Pair(155, -79), Pair(21, 25), Pair(71, -37), Pair(-41, -34), Pair(98, -43), Pair(-52, 7), Pair(-1, -75),
        Pair(1, -85), Pair(-144, 8), Pair(116, -48), Pair(-31, 7), Pair(111, 0), Pair(21, -27), Pair(81, -59), Pair(243, -118),
        Pair(26, -46), Pair(53, -94), Pair(-87, -10), Pair(125, -38), Pair(122, -32), Pair(29, -41), Pair(145, -160), Pair(253, -78),
        Pair(46, -86), Pair(51, -60), Pair(-44, 2), Pair(122, -59), Pair(17, 12), Pair(114, -111), Pair(45, 71), Pair(-33, 52),
        Pair(-48, -95), Pair(108, -21), Pair(53, -25), Pair(57, 60), Pair(-38, 45), Pair(137, -38), Pair(-87, 13), Pair(-11, 104),
        Pair(-65, -99), Pair(-45, -53), Pair(68, -104), Pair(-74, -3), Pair(5, 9), Pair(-3, 19), Pair(76, 3), Pair(-94, 32),
        Pair(15, -109), Pair(-97, 0), Pair(-119, -81), Pair(-82, -10), Pair(-23, -53), Pair(-59, -243), Pair(78, -6), Pair(-37, -108),
        Pair(52, 18), Pair(-16, -161), Pair(-164, -171), Pair(73, -168), Pair(89, -89), Pair(-142, -70), Pair(-32, -79), Pair(2, 13)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(71, 0), Pair(24, -3), Pair(6, -2), Pair(3, 8), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 5
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(86, 127), Pair(127, 140), Pair(74, 133), Pair(167, 112), Pair(52, 134), Pair(-104, 110), Pair(81, 164), Pair(-51, 152),
        Pair(28, 79), Pair(25, 75), Pair(-59, 72), Pair(-5, 54), Pair(-83, 117), Pair(-115, 78), Pair(82, 53), Pair(-67, 67),
        Pair(-58, 6), Pair(-60, 10), Pair(-106, -13), Pair(-122, -23), Pair(-116, -31), Pair(-31, -47), Pair(-42, -28), Pair(-65, 1),
        Pair(-139, -15), Pair(-52, -38), Pair(-55, -69), Pair(-80, -36), Pair(-100, -51), Pair(-60, -65), Pair(-37, -54), Pair(-37, -43),
        Pair(-94, -27), Pair(-73, -19), Pair(-73, -49), Pair(-31, -7), Pair(-9, -28), Pair(-23, -42), Pair(-50, -32), Pair(-68, -43),
        Pair(-98, 0), Pair(-50, -12), Pair(-5, -28), Pair(-152, 25), Pair(40, -1), Pair(20, -5), Pair(-4, -11), Pair(-97, -13),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(26, -91), Pair(-16, -30), Pair(-112, -25), Pair(-12, -48), Pair(-38, -123), Pair(-106, -41), Pair(-25, -73), Pair(-65, -155),
        Pair(-88, -66), Pair(-52, -41), Pair(-167, -14), Pair(-102, -15), Pair(-81, 11), Pair(44, -28), Pair(-18, -72), Pair(-106, -93),
        Pair(-110, -65), Pair(-29, -33), Pair(-1, 7), Pair(49, -11), Pair(77, -7), Pair(80, -26), Pair(2, -30), Pair(-123, -2),
        Pair(-34, -42), Pair(26, -41), Pair(99, -11), Pair(53, 1), Pair(157, -17), Pair(146, -36), Pair(111, -10), Pair(-98, -54),
        Pair(-51, -15), Pair(-150, 13), Pair(118, -35), Pair(50, -9), Pair(87, -16), Pair(134, -9), Pair(-37, 3), Pair(58, -30),
        Pair(-141, -110), Pair(72, -28), Pair(73, -26), Pair(109, -45), Pair(48, -41), Pair(115, -13), Pair(96, -79), Pair(113, -30),
        Pair(-21, -96), Pair(-39, -27), Pair(-19, -27), Pair(-83, 20), Pair(64, -16), Pair(41, -21), Pair(-41, 7), Pair(-87, -123),
        Pair(-47, -117), Pair(-127, -1), Pair(294, -162), Pair(25, -78), Pair(106, -83), Pair(-29, -29), Pair(62, -126), Pair(-30, -115)
      },
      { // Piece 2
        Pair(-113, 45), Pair(-103, -10), Pair(-217, 43), Pair(-171, 22), Pair(-125, -1), Pair(-99, -22), Pair(-239, -20), Pair(-102, -20),
        Pair(-92, -32), Pair(-169, 51), Pair(-117, 0), Pair(-191, 27), Pair(-265, -10), Pair(-184, 36), Pair(-271, 40), Pair(35, -17),
        Pair(-59, -35), Pair(-57, 7), Pair(-138, 50), Pair(-131, 5), Pair(-234, 29), Pair(-225, 37), Pair(-123, -8), Pair(66, -21),
        Pair(11, -37), Pair(-113, 16), Pair(-136, -6), Pair(-162, 34), Pair(-91, 5), Pair(-142, 34), Pair(-237, 37), Pair(-80, -35),
        Pair(-124, -6), Pair(-96, 1), Pair(40, -41), Pair(-8, -2), Pair(-19, 19), Pair(-51, -7), Pair(-153, -9), Pair(-66, 0),
        Pair(-97, -18), Pair(-34, 1), Pair(-7, -5), Pair(57, -31), Pair(-28, -18), Pair(-37, -15), Pair(55, -32), Pair(-34, -48),
        Pair(-117, -48), Pair(-98, 13), Pair(-69, -10), Pair(-57, 8), Pair(-86, 7), Pair(43, -55), Pair(-207, 40), Pair(-160, -22),
        Pair(-85, 42), Pair(-289, 64), Pair(-175, -21), Pair(-11, -64), Pair(68, -82), Pair(35, -38), Pair(-49, -36), Pair(-104, 52)
      },
      { // Piece 3
        Pair(-32, -74), Pair(-4, -65), Pair(-18, -78), Pair(-48, -33), Pair(-80, -13), Pair(-33, -8), Pair(-84, -37), Pair(-27, -64),
        Pair(-59, -62), Pair(-87, -68), Pair(-143, -53), Pair(32, -75), Pair(-68, -38), Pair(-77, -49), Pair(4, -97), Pair(-14, -109),
        Pair(-92, -65), Pair(54, -83), Pair(-71, -61), Pair(79, -77), Pair(-70, -58), Pair(-20, -63), Pair(-2, -86), Pair(-148, -49),
        Pair(-46, -96), Pair(-24, -83), Pair(-27, -78), Pair(95, -116), Pair(-110, -42), Pair(114, -111), Pair(-116, -71), Pair(-57, -101),
        Pair(-91, -103), Pair(76, -134), Pair(147, -127), Pair(-9, -111), Pair(18, -104), Pair(92, -111), Pair(8, -141), Pair(-54, -102),
        Pair(-82, -109), Pair(-64, -104), Pair(-5, -81), Pair(-88, -61), Pair(87, -161), Pair(16, -103), Pair(90, -128), Pair(-121, -116),
        Pair(-154, -119), Pair(-88, -74), Pair(30, -148), Pair(133, -151), Pair(115, -161), Pair(148, -131), Pair(75, -114), Pair(55, -187),
        Pair(-50, -161), Pair(-52, -137), Pair(14, -139), Pair(-72, -100), Pair(47, -110), Pair(41, -133), Pair(80, -168), Pair(-40, -160)
      },
      { // Piece 4
        Pair(-129, -201), Pair(42, -150), Pair(-24, -95), Pair(-13, -76), Pair(-64, -110), Pair(-82, -109), Pair(-108, -82), Pair(-55, -119),
        Pair(-29, -222), Pair(60, -107), Pair(-50, -97), Pair(48, -62), Pair(-3, -48), Pair(-20, 18), Pair(17, -101), Pair(14, -105),
        Pair(38, -87), Pair(-45, -210), Pair(-63, -126), Pair(-34, -129), Pair(-15, -59), Pair(62, -130), Pair(-1, -159), Pair(-71, -128),
        Pair(-37, -59), Pair(1, -122), Pair(-30, -117), Pair(26, -126), Pair(19, -81), Pair(17, -121), Pair(40, -128), Pair(49, -127),
        Pair(-64, -164), Pair(-31, -65), Pair(-23, -116), Pair(18, -50), Pair(44, -29), Pair(-28, -112), Pair(2, -27), Pair(47, -132),
        Pair(45, -119), Pair(-92, -116), Pair(-13, -65), Pair(3, -30), Pair(60, -77), Pair(-53, -159), Pair(-46, -59), Pair(123, 2),
        Pair(-30, -138), Pair(-27, -87), Pair(-17, -170), Pair(-161, -111), Pair(-5, -117), Pair(-66, -155), Pair(8, -80), Pair(-46, -124),
        Pair(-152, -175), Pair(-21, -115), Pair(60, -90), Pair(35, -145), Pair(6, -128), Pair(-59, -135), Pair(-80, -144), Pair(-107, -209)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(29, 13), Pair(-8, 3), Pair(-10, -4), Pair(-3, 14), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 6
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(34, 124), Pair(48, 175), Pair(50, 40), Pair(40, -38), Pair(-13, 118), Pair(-7, 32), Pair(-53, 132), Pair(27, 125),
        Pair(99, 33), Pair(37, 111), Pair(-17, 88), Pair(64, 44), Pair(-53, 21), Pair(25, 71), Pair(-15, 137), Pair(41, 42),
        Pair(-79, -6), Pair(-100, 28), Pair(183, -10), Pair(-59, 53), Pair(-70, -48), Pair(-55, -30), Pair(-52, 51), Pair(-101, 3),
        Pair(-74, -7), Pair(-65, -28), Pair(47, -39), Pair(-33, 3), Pair(-102, -68), Pair(55, -106), Pair(-36, -16), Pair(-242, 4),
        Pair(14, -48), Pair(-112, -2), Pair(9, -78), Pair(-37, 5), Pair(-25, -20), Pair(-45, -48), Pair(-164, -7), Pair(-180, -36),
        Pair(2, 7), Pair(27, 6), Pair(120, -43), Pair(-13, -24), Pair(-27, 17), Pair(31, -66), Pair(-118, -42), Pair(42, -58),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-6, -96), Pair(-6, -31), Pair(3, -9), Pair(8, 22), Pair(-17, -110), Pair(-16, -198), Pair(-17, 31), Pair(3, 84),
        Pair(6, 14), Pair(-27, -103), Pair(-58, -129), Pair(-6, -14), Pair(-31, -121), Pair(10, -68), Pair(30, 78), Pair(-75, -76),
        Pair(32, -49), Pair(21, -119), Pair(45, -2), Pair(48, -67), Pair(-65, -39), Pair(50, 38), Pair(1, 12), Pair(-6, -103),
        Pair(5, -21), Pair(15, 41), Pair(15, -16), Pair(-126, 59), Pair(51, -5), Pair(-38, -68), Pair(-47, -101), Pair(-29, -12),
        Pair(19, 40), Pair(5, -26), Pair(54, -32), Pair(28, 15), Pair(53, -49), Pair(14, 76), Pair(33, 39), Pair(-25, -21),
        Pair(-17, -32), Pair(33, 63), Pair(-2, -37), Pair(79, 4), Pair(52, 75), Pair(41, 22), Pair(1, -124), Pair(8, -28),
        Pair(-28, -33), Pair(-22, 44), Pair(25, -41), Pair(-39, 23), Pair(63, 28), Pair(-25, -50), Pair(-37, -91), Pair(-22, -99),
        Pair(1, -22), Pair(-51, 6), Pair(34, 47), Pair(30, 37), Pair(-32, -105), Pair(65, 46), Pair(32, -119), Pair(-4, -11)
      },
      { // Piece 2
        Pair(-4, 88), Pair(-14, -81), Pair(-25, -96), Pair(-8, 13), Pair(0, 98), Pair(-26, 51), Pair(-9, 62), Pair(-6, 42),
        Pair(-33, 110), Pair(61, 133), Pair(-35, -73), Pair(-22, -16), Pair(10, -11), Pair(-28, 6), Pair(-80, 92), Pair(-18, 100),
        Pair(-13, 99), Pair(37, 69), Pair(33, 40), Pair(29, 80), Pair(-32, -43), Pair(-39, 84), Pair(-11, 61), Pair(-32, 78),
        Pair(6, 100), Pair(-64, 82), Pair(-24, 94), Pair(66, 108), Pair(56, 98), Pair(-30, 113), Pair(-77, 21), Pair(-32, -47),
        Pair(-38, -3), Pair(-76, 7), Pair(29, -32), Pair(-14, 31), Pair(-68, 66), Pair(-2, 53), Pair(4, 80), Pair(30, 129),
        Pair(-7, 28), Pair(-28, -5), Pair(-50, 49), Pair(85, 44), Pair(20, 28), Pair(76, 53), Pair(-2, 20), Pair(-3, 32),
        Pair(-16, -67), Pair(-56, 128), Pair(-95, 110), Pair(-71, 28), Pair(-65, 122), Pair(8, 94), Pair(-34, 90), Pair(-32, -91),
        Pair(0, -52), Pair(-11, -108), Pair(-46, -123), Pair(12, -132), Pair(10, 28), Pair(45, -26), Pair(1, 55), Pair(-9, -47)
      },
      { // Piece 3
        Pair(-17, -32), Pair(-23, 5), Pair(-18, -34), Pair(21, 44), Pair(-32, -70), Pair(-101, -1), Pair(-16, 29), Pair(13, 0),
        Pair(-28, -24), Pair(-15, -26), Pair(9, -46), Pair(-79, -24), Pair(53, 27), Pair(-19, -53), Pair(-50, -18), Pair(62, -64),
        Pair(-132, -98), Pair(9, 21), Pair(-102, 1), Pair(57, -26), Pair(-35, -16), Pair(71, -8), Pair(-5, -31), Pair(-42, 12),
        Pair(21, -44), Pair(24, -17), Pair(31, 37), Pair(-61, -42), Pair(-29, -38), Pair(26, -25), Pair(-6, -16), Pair(-40, -11),
        Pair(5, -13), Pair(19, -2), Pair(-64, -108), Pair(35, 4), Pair(74, 0), Pair(-16, -19), Pair(-76, 13), Pair(-62, -69),
        Pair(88, -157), Pair(61, -59), Pair(61, 2), Pair(-46, 3), Pair(21, -1), Pair(66, -77), Pair(25, -16), Pair(-75, 22),
        Pair(4, -87), Pair(0, -83), Pair(11, -31), Pair(48, -48), Pair(60, -110), Pair(-19, -65), Pair(-10, 28), Pair(15, 17),
        Pair(56, -77), Pair(-25, -42), Pair(-2, -74), Pair(21, -120), Pair(35, -11), Pair(-109, -149), Pair(2, -37), Pair(16, -112)
      },
      { // Piece 4
        Pair(-29, -52), Pair(-50, -111), Pair(-28, -52), Pair(-29, -56), Pair(-45, -40), Pair(-71, -96), Pair(-36, -42), Pair(-57, -105),
        Pair(-47, -79), Pair(2, -52), Pair(-19, -2), Pair(17, 18), Pair(105, 101), Pair(-73, -39), Pair(-85, -107), Pair(31, 60),
        Pair(-20, -56), Pair(30, 51), Pair(-49, -21), Pair(-4, -34), Pair(-111, -86), Pair(-116, -72), Pair(38, 39), Pair(16, 7),
        Pair(13, 21), Pair(-47, -64), Pair(-33, -41), Pair(79, 73), Pair(-7, -84), Pair(-51, -85), Pair(-43, -77), Pair(-27, -59),
        Pair(-11, -26), Pair(45, 31), Pair(11, -22), Pair(88, 102), Pair(55, 83), Pair(-14, -66), Pair(3, -13), Pair(-50, -117),
        Pair(-27, -111), Pair(-65, -114), Pair(44, 9), Pair(-9, -54), Pair(-10, -37), Pair(46, 74), Pair(45, 79), Pair(-57, -52),
        Pair(-42, -99), Pair(-13, -88), Pair(-30, -72), Pair(8, 17), Pair(-22, -8), Pair(-38, -38), Pair(14, 34), Pair(-29, -85),
        Pair(-25, -46), Pair(0, -15), Pair(23, 43), Pair(-79, -146), Pair(-26, -82), Pair(-67, -90), Pair(-21, -46), Pair(16, 29)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(-32, 38), Pair(-23, 25), Pair(-114, 16), Pair(-105, 49), Pair(0, 0), Pair(0, 0)
      }
    }}
  }},
  {{ // Bucket 2
    {{ // Bucket 0
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(127, 305), Pair(164, 268), Pair(152, 269), Pair(151, 189), Pair(153, 177), Pair(165, 149), Pair(51, 23), Pair(-9, 42),
        Pair(-26, 161), Pair(24, 153), Pair(52, 140), Pair(77, 98), Pair(93, 64), Pair(119, 21), Pair(67, 54), Pair(10, 51),
        Pair(-18, 48), Pair(11, 42), Pair(8, 17), Pair(27, -9), Pair(52, -29), Pair(40, -23), Pair(10, 9), Pair(-20, 20),
        Pair(-19, 14), Pair(1, 13), Pair(0, -8), Pair(9, -22), Pair(22, -30), Pair(18, -16), Pair(15, -5), Pair(-10, -17),
        Pair(-27, 4), Pair(-3, 10), Pair(-10, -10), Pair(-7, -5), Pair(4, -5), Pair(10, -7), Pair(23, -1), Pair(-15, -29),
        Pair(-24, 11), Pair(-13, 16), Pair(-19, 3), Pair(-19, 7), Pair(-24, 26), Pair(27, 13), Pair(47, 2), Pair(-18, -28),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-294, 29), Pair(-135, 131), Pair(-162, 97), Pair(-45, 111), Pair(23, 91), Pair(-34, 86), Pair(-85, -32), Pair(-121, -40),
        Pair(-15, 55), Pair(-19, 61), Pair(49, 95), Pair(75, 105), Pair(69, 115), Pair(121, 47), Pair(48, 47), Pair(81, -28),
        Pair(-52, 80), Pair(39, 98), Pair(72, 116), Pair(104, 91), Pair(126, 91), Pair(179, 81), Pair(109, 103), Pair(39, 80),
        Pair(-6, 60), Pair(35, 100), Pair(64, 117), Pair(79, 148), Pair(65, 150), Pair(111, 132), Pair(63, 130), Pair(76, 76),
        Pair(-7, 54), Pair(21, 99), Pair(40, 120), Pair(30, 129), Pair(42, 134), Pair(42, 120), Pair(67, 109), Pair(29, 59),
        Pair(-31, 18), Pair(-11, 80), Pair(5, 87), Pair(23, 105), Pair(37, 102), Pair(17, 86), Pair(6, 81), Pair(2, 27),
        Pair(-33, -6), Pair(-39, 70), Pair(-26, 69), Pair(-10, 78), Pair(-7, 75), Pair(-4, 58), Pair(-7, 33), Pair(-10, 30),
        Pair(-193, 12), Pair(-51, -27), Pair(-91, 50), Pair(-46, 54), Pair(-53, 48), Pair(-46, 36), Pair(-43, 5), Pair(-50, -95)
      },
      { // Piece 2
        Pair(-106, 95), Pair(-68, 86), Pair(-164, 94), Pair(-117, 115), Pair(-73, 92), Pair(-107, 86), Pair(-13, 71), Pair(48, 24),
        Pair(-22, 54), Pair(24, 76), Pair(17, 68), Pair(-20, 93), Pair(39, 46), Pair(25, 75), Pair(3, 90), Pair(53, 32),
        Pair(7, 61), Pair(15, 79), Pair(68, 70), Pair(56, 80), Pair(98, 55), Pair(114, 85), Pair(71, 88), Pair(43, 56),
        Pair(0, 49), Pair(40, 77), Pair(44, 73), Pair(85, 97), Pair(61, 104), Pair(95, 64), Pair(39, 87), Pair(30, 60),
        Pair(-10, 33), Pair(28, 66), Pair(28, 91), Pair(43, 85), Pair(54, 79), Pair(26, 73), Pair(35, 59), Pair(15, 37),
        Pair(-5, 25), Pair(21, 62), Pair(11, 70), Pair(25, 71), Pair(18, 69), Pair(19, 62), Pair(25, 40), Pair(28, 29),
        Pair(4, 18), Pair(6, 21), Pair(23, 45), Pair(-2, 51), Pair(-4, 51), Pair(8, 38), Pair(33, 25), Pair(7, -22),
        Pair(-3, 4), Pair(-13, 43), Pair(-32, 5), Pair(-43, 31), Pair(-41, 38), Pair(-54, 21), Pair(-37, 29), Pair(-1, -28)
      },
      { // Piece 3
        Pair(89, 127), Pair(62, 150), Pair(88, 135), Pair(99, 140), Pair(119, 136), Pair(95, 186), Pair(40, 192), Pair(101, 108),
        Pair(61, 122), Pair(64, 134), Pair(97, 130), Pair(118, 126), Pair(112, 125), Pair(199, 81), Pair(101, 121), Pair(162, 119),
        Pair(47, 101), Pair(76, 103), Pair(83, 107), Pair(99, 101), Pair(141, 78), Pair(177, 61), Pair(194, 43), Pair(124, 61),
        Pair(21, 95), Pair(39, 109), Pair(56, 112), Pair(71, 102), Pair(79, 88), Pair(89, 85), Pair(133, 51), Pair(79, 76),
        Pair(-14, 79), Pair(2, 99), Pair(10, 106), Pair(24, 101), Pair(12, 87), Pair(31, 77), Pair(57, 56), Pair(12, 88),
        Pair(-18, 56), Pair(-22, 85), Pair(-9, 73), Pair(-3, 73), Pair(1, 68), Pair(0, 66), Pair(63, 31), Pair(-1, 55),
        Pair(-54, 63), Pair(0, 44), Pair(-1, 69), Pair(10, 62), Pair(3, 57), Pair(30, 42), Pair(60, 12), Pair(30, -17),
        Pair(1, 56), Pair(6, 65), Pair(10, 78), Pair(17, 73), Pair(18, 63), Pair(22, 50), Pair(39, 53), Pair(13, 40)
      },
      { // Piece 4
        Pair(-50, 206), Pair(-57, 264), Pair(-21, 251), Pair(13, 243), Pair(17, 252), Pair(114, 268), Pair(93, 209), Pair(168, 44),
        Pair(-30, 193), Pair(-39, 216), Pair(-17, 233), Pair(-20, 250), Pair(34, 276), Pair(98, 268), Pair(-99, 330), Pair(-17, 247),
        Pair(-9, 156), Pair(5, 150), Pair(-8, 221), Pair(11, 235), Pair(11, 297), Pair(135, 196), Pair(101, 241), Pair(67, 236),
        Pair(-2, 106), Pair(-7, 189), Pair(8, 173), Pair(-2, 218), Pair(20, 243), Pair(45, 245), Pair(50, 221), Pair(50, 209),
        Pair(-6, 116), Pair(5, 157), Pair(-3, 156), Pair(4, 200), Pair(4, 203), Pair(20, 188), Pair(38, 149), Pair(37, 170),
        Pair(-13, 80), Pair(1, 119), Pair(-1, 154), Pair(-5, 143), Pair(-6, 138), Pair(10, 142), Pair(31, 107), Pair(31, 52),
        Pair(11, 33), Pair(-5, 97), Pair(1, 86), Pair(-3, 106), Pair(-2, 100), Pair(18, 53), Pair(33, 51), Pair(70, 7),
        Pair(-10, 82), Pair(-37, 115), Pair(-31, 95), Pair(1, 68), Pair(-1, 54), Pair(-12, 47), Pair(3, 11), Pair(11, 51)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(10, 4), Pair(-17, 12), Pair(-63, 44), Pair(-126, 55), Pair(-96, 46), Pair(-85, 46), Pair(2, 3), Pair(12, -22),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 1
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(152, 235), Pair(84, 249), Pair(177, 82), Pair(148, 42), Pair(103, 23), Pair(123, 4), Pair(-46, 232), Pair(170, 213),
        Pair(-43, 144), Pair(-3, 151), Pair(19, 95), Pair(57, 47), Pair(87, 17), Pair(72, 36), Pair(45, 87), Pair(-34, 116),
        Pair(-45, 51), Pair(-12, 35), Pair(8, -9), Pair(34, -27), Pair(29, -19), Pair(21, -16), Pair(43, -8), Pair(9, 2),
        Pair(-45, 18), Pair(-36, 26), Pair(-11, -21), Pair(15, -21), Pair(11, -24), Pair(7, -15), Pair(31, -21), Pair(-9, -14),
        Pair(-54, 8), Pair(-27, 12), Pair(-2, -20), Pair(-1, -15), Pair(1, -10), Pair(14, -25), Pair(40, -20), Pair(-21, -27),
        Pair(-64, 16), Pair(-18, 11), Pair(-32, 1), Pair(-47, 3), Pair(-21, 13), Pair(8, -1), Pair(24, -5), Pair(-32, -16),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-133, -136), Pair(17, 8), Pair(-101, 51), Pair(-87, 78), Pair(80, -54), Pair(-186, 133), Pair(-226, 59), Pair(-196, -4),
        Pair(-56, 23), Pair(13, 44), Pair(19, 63), Pair(39, 70), Pair(-17, 66), Pair(105, 47), Pair(-4, 15), Pair(-24, 39),
        Pair(7, 38), Pair(2, 85), Pair(94, 74), Pair(115, 94), Pair(125, 106), Pair(128, 92), Pair(98, 47), Pair(-16, 51),
        Pair(42, 24), Pair(46, 78), Pair(103, 84), Pair(76, 102), Pair(54, 130), Pair(115, 87), Pair(61, 96), Pair(15, 89),
        Pair(-22, 39), Pair(-48, 105), Pair(39, 99), Pair(18, 109), Pair(51, 97), Pair(21, 112), Pair(39, 73), Pair(10, 39),
        Pair(-61, 12), Pair(-31, 76), Pair(-5, 66), Pair(-16, 91), Pair(36, 70), Pair(0, 77), Pair(-9, 56), Pair(-34, 29),
        Pair(-67, 17), Pair(-6, 16), Pair(-26, 29), Pair(-23, 57), Pair(-7, 43), Pair(-46, 61), Pair(-26, 35), Pair(-66, 42),
        Pair(-149, 14), Pair(-72, -2), Pair(-87, 40), Pair(-62, 61), Pair(-45, 6), Pair(-99, 41), Pair(-71, 9), Pair(-162, 49)
      },
      { // Piece 2
        Pair(-88, 106), Pair(-94, 80), Pair(-138, 96), Pair(-218, 107), Pair(-150, 61), Pair(-214, 97), Pair(-126, 74), Pair(-102, 42),
        Pair(-52, 20), Pair(-27, 37), Pair(47, 44), Pair(-2, 42), Pair(-74, 88), Pair(-76, 83), Pair(-44, 90), Pair(-30, 39),
        Pair(-14, 14), Pair(19, 39), Pair(68, 46), Pair(115, 60), Pair(141, 16), Pair(69, 88), Pair(68, 44), Pair(-1, 59),
        Pair(46, 22), Pair(-3, 65), Pair(33, 69), Pair(64, 66), Pair(97, 60), Pair(91, 43), Pair(41, 61), Pair(-11, 44),
        Pair(16, 15), Pair(37, 34), Pair(15, 56), Pair(42, 60), Pair(22, 65), Pair(16, 62), Pair(27, 59), Pair(16, 35),
        Pair(-19, 32), Pair(-17, 34), Pair(18, 32), Pair(-1, 59), Pair(2, 49), Pair(19, 40), Pair(-2, 27), Pair(-21, 28),
        Pair(-12, 4), Pair(4, 2), Pair(-15, 27), Pair(-16, 29), Pair(-21, 24), Pair(-31, 32), Pair(0, 21), Pair(13, -23),
        Pair(-50, 41), Pair(-28, 14), Pair(-46, -5), Pair(-86, 55), Pair(-87, 13), Pair(-78, 6), Pair(-26, 2), Pair(-6, -17)
      },
      { // Piece 3
        Pair(35, 103), Pair(3, 113), Pair(64, 99), Pair(16, 138), Pair(-2, 112), Pair(-35, 181), Pair(104, 77), Pair(60, 91),
        Pair(45, 101), Pair(71, 95), Pair(108, 82), Pair(153, 83), Pair(91, 103), Pair(34, 113), Pair(92, 84), Pair(107, 75),
        Pair(44, 69), Pair(67, 69), Pair(37, 73), Pair(85, 79), Pair(83, 82), Pair(52, 96), Pair(156, 36), Pair(95, 54),
        Pair(-38, 82), Pair(29, 55), Pair(29, 70), Pair(58, 77), Pair(22, 87), Pair(54, 49), Pair(6, 80), Pair(27, 62),
        Pair(-75, 69), Pair(-50, 85), Pair(-54, 92), Pair(-64, 105), Pair(-15, 64), Pair(-56, 97), Pair(-45, 81), Pair(7, 22),
        Pair(-56, 31), Pair(-73, 57), Pair(-71, 70), Pair(-27, 45), Pair(-42, 64), Pair(-79, 60), Pair(-5, 41), Pair(-38, 39),
        Pair(-80, 30), Pair(-58, 32), Pair(-42, 35), Pair(-27, 28), Pair(-26, 25), Pair(-33, 12), Pair(-50, 52), Pair(-25, -5),
        Pair(-76, 45), Pair(-44, 46), Pair(-39, 56), Pair(-41, 58), Pair(-24, 39), Pair(-44, 44), Pair(-31, 51), Pair(-33, 17)
      },
      { // Piece 4
        Pair(17, 56), Pair(-12, 146), Pair(-25, 152), Pair(91, 144), Pair(67, 165), Pair(127, 55), Pair(97, 111), Pair(61, 145),
        Pair(44, 111), Pair(33, 137), Pair(73, 142), Pair(140, 151), Pair(-4, 207), Pair(-23, 178), Pair(36, 177), Pair(95, 137),
        Pair(4, 104), Pair(71, 98), Pair(113, 118), Pair(58, 293), Pair(106, 215), Pair(85, 235), Pair(143, 153), Pair(59, 124),
        Pair(17, 97), Pair(31, 112), Pair(43, 98), Pair(36, 178), Pair(55, 247), Pair(68, 135), Pair(76, 193), Pair(80, 61),
        Pair(-22, 101), Pair(21, 120), Pair(50, 58), Pair(41, 141), Pair(34, 127), Pair(19, 133), Pair(58, 84), Pair(58, 85),
        Pair(-10, 58), Pair(5, 62), Pair(-1, 54), Pair(8, 44), Pair(-4, 42), Pair(-13, 96), Pair(13, 60), Pair(-3, 15),
        Pair(-45, -23), Pair(11, 2), Pair(5, 17), Pair(15, 9), Pair(2, 31), Pair(18, -7), Pair(-34, 22), Pair(-16, 59),
        Pair(-19, 61), Pair(-72, 20), Pair(-28, 13), Pair(-6, 0), Pair(-1, -36), Pair(9, -74), Pair(45, -21), Pair(8, -5)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(56, -15), Pair(40, -8), Pair(20, 7), Pair(-68, 30), Pair(-33, 23), Pair(-24, 23), Pair(22, -6), Pair(55, -30),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 2
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(201, 192), Pair(211, 174), Pair(194, 133), Pair(150, 97), Pair(197, 53), Pair(162, 51), Pair(76, 146), Pair(185, 126),
        Pair(-31, 136), Pair(33, 117), Pair(57, 93), Pair(101, 46), Pair(101, 10), Pair(122, -5), Pair(39, 54), Pair(-54, 76),
        Pair(-25, 44), Pair(7, 29), Pair(3, 9), Pair(22, -14), Pair(45, -22), Pair(39, -19), Pair(37, 2), Pair(12, -1),
        Pair(-32, 16), Pair(-12, 15), Pair(-8, -10), Pair(2, -15), Pair(18, -24), Pair(19, -15), Pair(28, -6), Pair(-2, -14),
        Pair(-35, 4), Pair(-10, 4), Pair(-19, -7), Pair(-17, -3), Pair(3, -7), Pair(20, -18), Pair(32, -13), Pair(0, -30),
        Pair(-37, 15), Pair(-17, 13), Pair(-21, 1), Pair(-25, 20), Pair(-21, 10), Pair(43, -9), Pair(48, -2), Pair(-14, -21),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-235, 11), Pair(-168, 85), Pair(-65, 72), Pair(40, 59), Pair(163, 55), Pair(239, 28), Pair(39, 14), Pair(-169, -60),
        Pair(59, 15), Pair(13, 53), Pair(38, 78), Pair(147, 79), Pair(119, 70), Pair(167, 20), Pair(-27, 59), Pair(-9, 46),
        Pair(40, 40), Pair(52, 83), Pair(91, 103), Pair(118, 104), Pair(170, 90), Pair(170, 99), Pair(145, 74), Pair(87, 12),
        Pair(21, 59), Pair(48, 95), Pair(84, 107), Pair(125, 111), Pair(112, 126), Pair(143, 111), Pair(95, 99), Pair(94, 50),
        Pair(-8, 66), Pair(52, 86), Pair(48, 117), Pair(69, 118), Pair(85, 115), Pair(92, 110), Pair(105, 84), Pair(50, 63),
        Pair(-26, 42), Pair(3, 73), Pair(26, 83), Pair(31, 108), Pair(45, 97), Pair(42, 80), Pair(47, 62), Pair(35, 34),
        Pair(-91, 25), Pair(-51, 61), Pair(2, 54), Pair(-6, 74), Pair(13, 67), Pair(5, 53), Pair(-5, 41), Pair(-28, 34),
        Pair(-217, -31), Pair(-62, 18), Pair(-63, 33), Pair(-79, 66), Pair(-41, 48), Pair(-72, 52), Pair(-18, 14), Pair(-158, 11)
      },
      { // Piece 2
        Pair(0, 37), Pair(23, 52), Pair(-38, 56), Pair(7, 58), Pair(30, 36), Pair(-104, 66), Pair(42, 51), Pair(-70, 64),
        Pair(-30, 32), Pair(22, 55), Pair(31, 52), Pair(45, 56), Pair(37, 56), Pair(54, 67), Pair(25, 64), Pair(-39, 49),
        Pair(21, 42), Pair(54, 58), Pair(71, 62), Pair(64, 53), Pair(124, 39), Pair(136, 60), Pair(106, 49), Pair(51, 32),
        Pair(8, 50), Pair(62, 62), Pair(62, 62), Pair(118, 60), Pair(119, 64), Pair(123, 47), Pair(93, 54), Pair(50, 37),
        Pair(-14, 51), Pair(33, 49), Pair(46, 69), Pair(60, 70), Pair(74, 61), Pair(45, 70), Pair(57, 55), Pair(42, 32),
        Pair(-7, 36), Pair(2, 52), Pair(19, 56), Pair(22, 58), Pair(22, 61), Pair(35, 47), Pair(22, 33), Pair(21, 34),
        Pair(14, 8), Pair(18, 19), Pair(27, 16), Pair(5, 41), Pair(12, 36), Pair(20, 29), Pair(33, 18), Pair(14, -32),
        Pair(22, -9), Pair(-7, 27), Pair(-26, 11), Pair(-18, 28), Pair(-23, 25), Pair(-54, 27), Pair(-26, 17), Pair(-25, 27)
      },
      { // Piece 3
        Pair(115, 88), Pair(138, 83), Pair(107, 100), Pair(137, 86), Pair(150, 77), Pair(202, 51), Pair(154, 87), Pair(224, 66),
        Pair(39, 105), Pair(50, 108), Pair(96, 102), Pair(96, 108), Pair(95, 102), Pair(94, 73), Pair(8, 113), Pair(89, 88),
        Pair(24, 95), Pair(64, 85), Pair(86, 86), Pair(99, 78), Pair(120, 75), Pair(165, 64), Pair(167, 41), Pair(117, 64),
        Pair(1, 88), Pair(1, 100), Pair(36, 100), Pair(62, 88), Pair(96, 71), Pair(86, 75), Pair(96, 70), Pair(75, 66),
        Pair(-41, 77), Pair(-18, 87), Pair(-16, 94), Pair(-12, 90), Pair(3, 78), Pair(27, 67), Pair(49, 60), Pair(31, 55),
        Pair(-57, 55), Pair(-44, 76), Pair(-24, 65), Pair(-13, 58), Pair(-31, 67), Pair(2, 52), Pair(37, 47), Pair(-3, 41),
        Pair(-75, 50), Pair(-35, 60), Pair(-9, 46), Pair(-15, 57), Pair(-7, 42), Pair(20, 27), Pair(23, 26), Pair(-4, 0),
        Pair(-18, 47), Pair(-12, 57), Pair(-9, 66), Pair(-2, 59), Pair(0, 51), Pair(1, 48), Pair(14, 48), Pair(-10, 50)
      },
      { // Piece 4
        Pair(86, 117), Pair(89, 138), Pair(118, 148), Pair(153, 138), Pair(179, 138), Pair(215, 128), Pair(227, 112), Pair(228, 120),
        Pair(29, 105), Pair(18, 134), Pair(64, 147), Pair(48, 160), Pair(85, 190), Pair(112, 170), Pair(99, 189), Pair(99, 131),
        Pair(0, 122), Pair(58, 102), Pair(46, 136), Pair(83, 137), Pair(145, 165), Pair(236, 138), Pair(121, 201), Pair(134, 132),
        Pair(29, 89), Pair(41, 152), Pair(16, 170), Pair(56, 190), Pair(85, 219), Pair(125, 231), Pair(114, 204), Pair(114, 157),
        Pair(15, 81), Pair(39, 124), Pair(49, 128), Pair(48, 154), Pair(70, 142), Pair(102, 137), Pair(84, 159), Pair(88, 129),
        Pair(42, 26), Pair(55, 60), Pair(49, 102), Pair(46, 102), Pair(43, 112), Pair(47, 131), Pair(78, 88), Pair(38, 112),
        Pair(15, 66), Pair(37, 66), Pair(37, 52), Pair(51, 64), Pair(38, 83), Pair(37, 50), Pair(60, 13), Pair(51, 55),
        Pair(33, 17), Pair(13, 56), Pair(8, 71), Pair(38, 54), Pair(28, 55), Pair(-4, 70), Pair(53, 4), Pair(-9, 24)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(68, -29), Pair(15, -5), Pair(-22, 17), Pair(-74, 32), Pair(-52, 24), Pair(-47, 24), Pair(15, -4), Pair(35, -30),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 3
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(128, 174), Pair(131, 182), Pair(156, 122), Pair(179, 92), Pair(103, 98), Pair(196, 92), Pair(119, 177), Pair(129, 165),
        Pair(-39, 106), Pair(26, 80), Pair(17, 57), Pair(71, 16), Pair(47, 12), Pair(21, 15), Pair(28, 59), Pair(-15, 71),
        Pair(-53, 38), Pair(-39, 28), Pair(-12, -1), Pair(-4, -23), Pair(25, -31), Pair(32, -36), Pair(-9, -3), Pair(-41, 2),
        Pair(-69, 15), Pair(-54, 14), Pair(-20, -16), Pair(-10, -17), Pair(8, -17), Pair(17, -19), Pair(40, -10), Pair(-21, -18),
        Pair(-70, 4), Pair(-46, 4), Pair(-21, -15), Pair(-12, -7), Pair(-1, -6), Pair(24, -17), Pair(31, -18), Pair(-19, -24),
        Pair(-62, 14), Pair(-44, 14), Pair(-25, -5), Pair(-24, 2), Pair(-12, 2), Pair(42, -14), Pair(31, -8), Pair(-44, -13),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-170, -27), Pair(23, -7), Pair(0, 43), Pair(57, 10), Pair(32, 49), Pair(-10, 34), Pair(-167, 44), Pair(-77, -107),
        Pair(42, -31), Pair(47, 9), Pair(83, 22), Pair(73, 54), Pair(172, 36), Pair(150, 0), Pair(-5, 23), Pair(2, 18),
        Pair(-26, 11), Pair(71, 33), Pair(94, 59), Pair(123, 56), Pair(188, 40), Pair(184, 47), Pair(51, 34), Pair(81, -6),
        Pair(29, 17), Pair(80, 49), Pair(92, 73), Pair(162, 70), Pair(175, 76), Pair(175, 67), Pair(134, 60), Pair(89, 37),
        Pair(23, 11), Pair(56, 40), Pair(75, 72), Pair(116, 68), Pair(85, 73), Pair(112, 78), Pair(104, 44), Pair(-27, 43),
        Pair(-28, -18), Pair(1, 34), Pair(22, 60), Pair(56, 73), Pair(58, 68), Pair(43, 54), Pair(26, 50), Pair(-54, 48),
        Pair(-37, -11), Pair(-19, 8), Pair(-13, 25), Pair(-10, 40), Pair(-2, 45), Pair(8, 31), Pair(-25, 22), Pair(9, 14),
        Pair(-140, -50), Pair(-113, 18), Pair(-36, -15), Pair(-73, 31), Pair(-61, 27), Pair(-63, 2), Pair(-39, -38), Pair(-172, -6)
      },
      { // Piece 2
        Pair(-79, 41), Pair(27, 18), Pair(-82, 22), Pair(-90, 42), Pair(-65, 29), Pair(-24, 37), Pair(-7, 7), Pair(-54, 36),
        Pair(-73, 25), Pair(2, 30), Pair(-5, 32), Pair(6, 23), Pair(76, 4), Pair(52, 14), Pair(5, 31), Pair(-68, 16),
        Pair(-49, 23), Pair(40, 26), Pair(73, 24), Pair(54, 24), Pair(113, 6), Pair(127, 18), Pair(105, 13), Pair(23, 8),
        Pair(-14, 17), Pair(32, 27), Pair(59, 23), Pair(111, 24), Pair(139, 20), Pair(112, 17), Pair(74, 13), Pair(17, 12),
        Pair(-30, 8), Pair(26, 20), Pair(49, 30), Pair(84, 24), Pair(69, 30), Pair(41, 35), Pair(72, 18), Pair(32, 8),
        Pair(-61, 16), Pair(25, 11), Pair(7, 30), Pair(21, 30), Pair(32, 30), Pair(21, 25), Pair(29, 0), Pair(-9, -1),
        Pair(-53, 6), Pair(24, -18), Pair(32, -15), Pair(10, 3), Pair(-23, 17), Pair(-15, 16), Pair(6, -5), Pair(-54, -39),
        Pair(-33, -16), Pair(-22, -10), Pair(-117, 13), Pair(-38, 0), Pair(-55, 0), Pair(-117, 4), Pair(-90, 2), Pair(-28, -26)
      },
      { // Piece 3
        Pair(35, 42), Pair(5, 57), Pair(55, 46), Pair(49, 48), Pair(59, 50), Pair(62, 55), Pair(71, 43), Pair(69, 45),
        Pair(30, 28), Pair(54, 32), Pair(74, 32), Pair(88, 34), Pair(114, 32), Pair(139, 16), Pair(98, 19), Pair(93, 12),
        Pair(-16, 40), Pair(-22, 50), Pair(-27, 69), Pair(58, 39), Pair(12, 37), Pair(40, 29), Pair(45, 21), Pair(11, 22),
        Pair(-39, 37), Pair(-5, 38), Pair(2, 45), Pair(29, 37), Pair(37, 38), Pair(25, 40), Pair(104, 9), Pair(19, 28),
        Pair(-56, 25), Pair(-73, 48), Pair(-33, 37), Pair(-38, 44), Pair(39, 25), Pair(25, 28), Pair(72, 15), Pair(18, 9),
        Pair(-104, 2), Pair(-66, 16), Pair(-74, 19), Pair(-72, 25), Pair(-69, 24), Pair(-25, 2), Pair(-54, 19), Pair(-82, 29),
        Pair(-155, 16), Pair(-80, -12), Pair(-70, 15), Pair(-106, 21), Pair(-84, 14), Pair(-7, -9), Pair(-38, -6), Pair(-89, -22),
        Pair(-62, -5), Pair(-53, 1), Pair(-69, 21), Pair(-54, 19), Pair(-66, 21), Pair(-46, 12), Pair(-40, 6), Pair(-35, -3)
      },
      { // Piece 4
        Pair(83, 11), Pair(113, 2), Pair(218, -18), Pair(181, 16), Pair(155, 61), Pair(155, 67), Pair(231, 14), Pair(219, -2),
        Pair(45, 0), Pair(46, 44), Pair(126, 14), Pair(139, 50), Pair(132, 93), Pair(208, 3), Pair(167, 29), Pair(206, 16),
        Pair(36, -26), Pair(53, -34), Pair(13, 52), Pair(68, 46), Pair(87, 60), Pair(251, 64), Pair(150, -11), Pair(147, -58),
        Pair(81, -54), Pair(69, -13), Pair(96, 14), Pair(97, 41), Pair(113, 63), Pair(225, 22), Pair(133, 45), Pair(256, -52),
        Pair(44, -35), Pair(54, -12), Pair(26, 49), Pair(63, 74), Pair(71, 77), Pair(100, 75), Pair(112, 21), Pair(75, 37),
        Pair(41, -78), Pair(-7, -3), Pair(19, 4), Pair(3, 26), Pair(-16, 40), Pair(85, 15), Pair(23, 41), Pair(113, -16),
        Pair(-30, -66), Pair(-43, 11), Pair(-2, 2), Pair(27, -35), Pair(-2, 7), Pair(16, -16), Pair(-48, -25), Pair(-6, -81),
        Pair(-32, 12), Pair(-33, -47), Pair(8, -73), Pair(38, -59), Pair(6, -52), Pair(-61, -20), Pair(33, -97), Pair(-21, -38)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(82, -37), Pair(49, -14), Pair(19, 5), Pair(-32, 19), Pair(-18, 14), Pair(-13, 12), Pair(21, -6), Pair(49, -32),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 4
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(106, 145), Pair(141, 146), Pair(42, 124), Pair(124, 116), Pair(87, 102), Pair(18, 151), Pair(169, 156), Pair(76, 155),
        Pair(4, 93), Pair(36, 68), Pair(11, 62), Pair(14, 35), Pair(44, 36), Pair(30, 32), Pair(27, 60), Pair(-13, 78),
        Pair(-45, 16), Pair(-27, -1), Pair(-50, -22), Pair(-36, -37), Pair(10, -47), Pair(18, -45), Pair(-15, -13), Pair(-6, -14),
        Pair(-86, -3), Pair(-59, -1), Pair(-23, -30), Pair(-19, -35), Pair(6, -46), Pair(-20, -35), Pair(-2, -21), Pair(-77, -21),
        Pair(-68, -15), Pair(-53, -6), Pair(-41, -19), Pair(-42, 3), Pair(1, -11), Pair(20, -24), Pair(28, -20), Pair(-35, -34),
        Pair(-91, 0), Pair(-57, 7), Pair(-14, -13), Pair(-19, 3), Pair(0, -16), Pair(42, -15), Pair(9, -9), Pair(-62, -17),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-6, -165), Pair(-89, -38), Pair(-91, 11), Pair(16, -20), Pair(-26, 5), Pair(-95, -5), Pair(94, -69), Pair(-13, -132),
        Pair(-109, -30), Pair(-69, -16), Pair(80, -13), Pair(-68, 40), Pair(88, -11), Pair(116, -25), Pair(-30, -7), Pair(13, -27),
        Pair(-46, -27), Pair(62, -13), Pair(-14, 26), Pair(102, 9), Pair(105, 9), Pair(116, 14), Pair(30, -17), Pair(-12, -42),
        Pair(2, -27), Pair(26, 11), Pair(47, 22), Pair(109, 27), Pair(112, 38), Pair(130, 19), Pair(111, 3), Pair(39, -17),
        Pair(-41, -30), Pair(72, -21), Pair(89, 20), Pair(103, 26), Pair(105, 30), Pair(131, 15), Pair(194, -24), Pair(48, -45),
        Pair(-47, -48), Pair(-60, -9), Pair(71, -10), Pair(98, 6), Pair(81, 17), Pair(11, 14), Pair(62, -10), Pair(16, -20),
        Pair(-80, -80), Pair(-20, -12), Pair(-38, -4), Pair(7, -13), Pair(-25, 6), Pair(-18, -5), Pair(-78, -27), Pair(42, -13),
        Pair(-89, -134), Pair(-91, -43), Pair(9, -15), Pair(-45, -15), Pair(-39, -36), Pair(-4, -30), Pair(-102, -8), Pair(-85, -72)
      },
      { // Piece 2
        Pair(-36, -12), Pair(-23, -18), Pair(-51, -14), Pair(-50, -6), Pair(-174, 12), Pair(-99, 3), Pair(-81, -27), Pair(-36, 8),
        Pair(-151, -22), Pair(-50, -14), Pair(-95, 8), Pair(-84, 5), Pair(-79, -1), Pair(20, -12), Pair(-23, -10), Pair(-58, -33),
        Pair(-12, -22), Pair(-72, 8), Pair(46, -21), Pair(28, -9), Pair(45, -1), Pair(-4, -7), Pair(10, -15), Pair(-9, -48),
        Pair(-126, 0), Pair(-24, 1), Pair(-8, -11), Pair(76, -15), Pair(109, -15), Pair(79, -25), Pair(70, -6), Pair(-24, -31),
        Pair(-56, -34), Pair(-74, 5), Pair(-18, -8), Pair(113, -22), Pair(117, -27), Pair(49, -9), Pair(22, -30), Pair(-48, -22),
        Pair(-25, -44), Pair(-67, -16), Pair(11, -8), Pair(-16, 8), Pair(10, -5), Pair(-15, -2), Pair(86, -41), Pair(-60, -24),
        Pair(-75, -42), Pair(-49, -51), Pair(-20, -39), Pair(2, -38), Pair(-31, -26), Pair(-14, -27), Pair(-46, -30), Pair(-39, -65),
        Pair(-65, -22), Pair(-52, -36), Pair(-61, -54), Pair(-55, -45), Pair(-76, -28), Pair(-72, -42), Pair(-12, -23), Pair(-132, -23)
      },
      { // Piece 3
        Pair(1, -27), Pair(-11, -18), Pair(-6, -19), Pair(15, -23), Pair(10, -10), Pair(-16, -4), Pair(-1, -13), Pair(29, -14),
        Pair(-35, -50), Pair(-41, -33), Pair(8, -31), Pair(-9, -15), Pair(52, -38), Pair(124, -72), Pair(7, -46), Pair(68, -77),
        Pair(-31, -33), Pair(11, -46), Pair(4, -29), Pair(92, -50), Pair(88, -59), Pair(140, -66), Pair(105, -83), Pair(14, -50),
        Pair(-84, -38), Pair(-29, -47), Pair(-47, -27), Pair(12, -33), Pair(56, -89), Pair(63, -72), Pair(20, -64), Pair(-26, -73),
        Pair(-88, -49), Pair(-127, -15), Pair(-107, -11), Pair(6, -52), Pair(-2, -46), Pair(33, -54), Pair(81, -70), Pair(-19, -64),
        Pair(-70, -76), Pair(-76, -59), Pair(-67, -65), Pair(-46, -70), Pair(-87, -33), Pair(-11, -65), Pair(1, -63), Pair(-121, -38),
        Pair(-135, -63), Pair(-79, -74), Pair(-75, -70), Pair(-66, -70), Pair(-102, -57), Pair(-30, -67), Pair(-11, -68), Pair(-105, -81),
        Pair(-79, -84), Pair(-54, -92), Pair(-66, -69), Pair(-87, -48), Pair(-92, -56), Pair(-44, -67), Pair(-94, -54), Pair(-26, -91)
      },
      { // Piece 4
        Pair(29, -195), Pair(-51, -75), Pair(99, -110), Pair(99, -72), Pair(128, -78), Pair(113, -66), Pair(112, -110), Pair(40, -28),
        Pair(58, -140), Pair(14, -104), Pair(201, -167), Pair(151, -111), Pair(202, -114), Pair(100, -86), Pair(143, -89), Pair(47, -78),
        Pair(100, -228), Pair(7, -110), Pair(78, -140), Pair(23, -99), Pair(240, -181), Pair(118, -96), Pair(156, -150), Pair(141, -207),
        Pair(-74, -181), Pair(-75, -96), Pair(10, -168), Pair(149, -181), Pair(34, -55), Pair(38, -83), Pair(28, -137), Pair(139, -146),
        Pair(-89, -137), Pair(-34, -73), Pair(14, -75), Pair(24, -130), Pair(118, -109), Pair(81, -92), Pair(132, -143), Pair(-43, -70),
        Pair(-167, -63), Pair(-65, -133), Pair(44, -117), Pair(21, -121), Pair(26, -34), Pair(57, -85), Pair(29, -62), Pair(55, -125),
        Pair(-139, -203), Pair(-20, -158), Pair(-152, -110), Pair(-17, -159), Pair(8, -150), Pair(-65, -105), Pair(-3, -158), Pair(-64, -98),
        Pair(8, -156), Pair(-51, -111), Pair(1, -183), Pair(10, -197), Pair(-66, -137), Pair(-115, -68), Pair(-146, -94), Pair(-19, -146)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(76, -18), Pair(66, -9), Pair(43, 3), Pair(-19, 22), Pair(0, 13), Pair(15, 12), Pair(32, 0), Pair(62, -24),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 5
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(191, 108), Pair(156, 120), Pair(230, 81), Pair(138, 84), Pair(171, 81), Pair(121, 127), Pair(244, 121), Pair(200, 103),
        Pair(-32, 80), Pair(67, 59), Pair(2, 49), Pair(17, 58), Pair(42, 49), Pair(-35, 51), Pair(-10, 74), Pair(9, 75),
        Pair(-70, 13), Pair(-64, -4), Pair(-29, -26), Pair(-105, -29), Pair(-34, -37), Pair(-33, -28), Pair(7, -20), Pair(-35, -9),
        Pair(-121, -10), Pair(-94, -15), Pair(-28, -49), Pair(-38, -45), Pair(-26, -49), Pair(-20, -55), Pair(-25, -42), Pair(-59, -37),
        Pair(-109, -14), Pair(-94, -18), Pair(-66, -28), Pair(-50, -28), Pair(-14, -33), Pair(1, -41), Pair(-43, -28), Pair(-89, -36),
        Pair(-93, -1), Pair(-75, -3), Pair(3, -27), Pair(-2, -11), Pair(22, -17), Pair(46, -23), Pair(29, -20), Pair(-84, -22),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-150, -166), Pair(-59, -78), Pair(-188, -31), Pair(-102, -48), Pair(-76, -23), Pair(-226, -2), Pair(-14, -63), Pair(-46, -193),
        Pair(-130, -62), Pair(-73, -52), Pair(-42, -47), Pair(-50, -15), Pair(-43, -4), Pair(0, -40), Pair(9, -61), Pair(-73, -101),
        Pair(-120, -61), Pair(-9, -43), Pair(15, -36), Pair(29, -22), Pair(49, -18), Pair(68, -31), Pair(11, -50), Pair(10, -97),
        Pair(-149, -74), Pair(-7, -33), Pair(46, -20), Pair(13, 7), Pair(60, -10), Pair(133, -35), Pair(69, -58), Pair(102, -70),
        Pair(35, -84), Pair(-58, -15), Pair(-23, -12), Pair(66, -13), Pair(85, -23), Pair(96, -13), Pair(102, -36), Pair(43, -85),
        Pair(-57, -88), Pair(32, -47), Pair(-38, -23), Pair(27, -21), Pair(90, -36), Pair(38, -43), Pair(159, -61), Pair(-2, -81),
        Pair(-61, -77), Pair(-31, -74), Pair(109, -96), Pair(44, -73), Pair(40, -43), Pair(87, -63), Pair(-75, -11), Pair(45, -83),
        Pair(41, -168), Pair(-6, -75), Pair(-43, -78), Pair(6, -69), Pair(51, -98), Pair(29, -70), Pair(32, -84), Pair(42, -180)
      },
      { // Piece 2
        Pair(-163, -5), Pair(-155, 33), Pair(-198, -7), Pair(-114, -10), Pair(-184, -13), Pair(-214, 6), Pair(-78, -30), Pair(-125, -25),
        Pair(-78, -40), Pair(-150, -6), Pair(-187, 15), Pair(-169, 5), Pair(-215, 7), Pair(-170, 3), Pair(-174, -6), Pair(-81, -41),
        Pair(-171, -30), Pair(-60, -22), Pair(-143, 12), Pair(-153, -5), Pair(-133, 4), Pair(-155, 6), Pair(-62, -16), Pair(-155, -28),
        Pair(-135, -52), Pair(-100, -5), Pair(-123, -19), Pair(-83, -2), Pair(-90, -4), Pair(-117, -3), Pair(-88, -5), Pair(-118, -35),
        Pair(-84, -56), Pair(-125, -25), Pair(-54, -27), Pair(59, -43), Pair(-3, -21), Pair(4, -24), Pair(-58, -25), Pair(61, -101),
        Pair(-55, -55), Pair(-127, -8), Pair(-92, -14), Pair(-29, -41), Pair(-9, -19), Pair(-98, -17), Pair(-132, -27), Pair(-111, -68),
        Pair(25, -62), Pair(-36, -77), Pair(-83, -54), Pair(-63, -59), Pair(-40, -51), Pair(-68, -73), Pair(-41, -63), Pair(-51, -104),
        Pair(-148, -39), Pair(-278, 20), Pair(-120, -76), Pair(-36, -61), Pair(-52, -74), Pair(-69, -76), Pair(-161, -47), Pair(-159, -50)
      },
      { // Piece 3
        Pair(-47, -93), Pair(-24, -83), Pair(40, -87), Pair(40, -87), Pair(-66, -64), Pair(-47, -46), Pair(20, -77), Pair(-62, -62),
        Pair(-64, -99), Pair(-42, -108), Pair(-40, -81), Pair(-9, -102), Pair(-4, -85), Pair(27, -120), Pair(-2, -109), Pair(4, -111),
        Pair(-61, -95), Pair(0, -101), Pair(-15, -71), Pair(4, -102), Pair(62, -119), Pair(68, -106), Pair(2, -107), Pair(-16, -108),
        Pair(-38, -115), Pair(9, -111), Pair(-43, -97), Pair(46, -107), Pair(45, -113), Pair(91, -121), Pair(92, -126), Pair(3, -122),
        Pair(2, -122), Pair(-77, -110), Pair(-13, -99), Pair(-18, -119), Pair(61, -142), Pair(99, -143), Pair(-15, -138), Pair(-30, -147),
        Pair(-103, -110), Pair(-76, -105), Pair(-40, -125), Pair(-44, -129), Pair(30, -140), Pair(138, -159), Pair(63, -158), Pair(-124, -129),
        Pair(-87, -153), Pair(-21, -131), Pair(29, -144), Pair(-26, -133), Pair(69, -165), Pair(138, -164), Pair(98, -155), Pair(-44, -144),
        Pair(-3, -177), Pair(5, -166), Pair(-1, -149), Pair(21, -144), Pair(18, -152), Pair(48, -150), Pair(64, -174), Pair(-18, -144)
      },
      { // Piece 4
        Pair(-68, -285), Pair(-116, -144), Pair(-19, -269), Pair(20, -214), Pair(-137, -211), Pair(-167, -205), Pair(-197, -202), Pair(-212, -211),
        Pair(-34, -249), Pair(52, -269), Pair(63, -299), Pair(-64, -217), Pair(-4, -173), Pair(-61, -177), Pair(144, -353), Pair(110, -283),
        Pair(33, -301), Pair(-99, -175), Pair(-33, -217), Pair(88, -263), Pair(-34, -162), Pair(199, -386), Pair(22, -250), Pair(64, -233),
        Pair(-51, -231), Pair(67, -292), Pair(-56, -252), Pair(32, -230), Pair(112, -311), Pair(39, -221), Pair(-63, -178), Pair(80, -281),
        Pair(-21, -287), Pair(-42, -308), Pair(-124, -152), Pair(-104, -123), Pair(117, -220), Pair(-59, -186), Pair(-37, -205), Pair(-55, -175),
        Pair(-83, -164), Pair(-125, -144), Pair(-15, -195), Pair(-46, -173), Pair(19, -139), Pair(111, -177), Pair(-50, -106), Pair(-41, -258),
        Pair(-25, -233), Pair(-29, -300), Pair(49, -174), Pair(90, -217), Pair(97, -260), Pair(-108, -144), Pair(-52, -197), Pair(-72, -242),
        Pair(-5, -253), Pair(-69, -179), Pair(23, -170), Pair(-94, -205), Pair(61, -217), Pair(-101, -242), Pair(-7, -171), Pair(-45, -223)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(54, -1), Pair(12, 2), Pair(20, 0), Pair(-16, 8), Pair(6, 6), Pair(-8, 11), Pair(36, 1), Pair(61, -19),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 6
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-19, 195), Pair(143, 178), Pair(39, 99), Pair(89, 118), Pair(-107, 85), Pair(43, 197), Pair(-8, 196), Pair(78, 179),
        Pair(-62, 140), Pair(-69, 174), Pair(-44, 124), Pair(43, 77), Pair(11, 122), Pair(-56, 91), Pair(18, 207), Pair(4, 137),
        Pair(-126, 66), Pair(62, 25), Pair(-76, 35), Pair(-114, 13), Pair(-28, -24), Pair(-24, -4), Pair(-76, 49), Pair(-190, 48),
        Pair(-159, -1), Pair(-3, -34), Pair(-31, -47), Pair(-128, 13), Pair(-44, -70), Pair(71, -56), Pair(-92, -15), Pair(-54, -19),
        Pair(-121, -20), Pair(-155, 2), Pair(-12, -56), Pair(-79, -17), Pair(-17, -37), Pair(-7, -31), Pair(-38, -12), Pair(-97, -27),
        Pair(-100, -12), Pair(-21, -15), Pair(40, -34), Pair(1, 44), Pair(-36, -9), Pair(47, -42), Pair(112, -57), Pair(-156, -34),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-45, -121), Pair(-71, -232), Pair(-27, -80), Pair(-81, -129), Pair(4, -111), Pair(-37, -42), Pair(-31, 15), Pair(-73, -178),
        Pair(-52, -159), Pair(-54, -42), Pair(-29, -95), Pair(41, 23), Pair(58, -26), Pair(-58, -89), Pair(-40, -61), Pair(15, -70),
        Pair(-53, -56), Pair(-26, -109), Pair(-66, -57), Pair(-46, 25), Pair(46, -31), Pair(-58, -11), Pair(-21, -44), Pair(-49, -60),
        Pair(-29, -73), Pair(87, -63), Pair(-9, -15), Pair(49, -1), Pair(82, -17), Pair(35, 1), Pair(-28, -19), Pair(-36, -10),
        Pair(11, -22), Pair(-67, -34), Pair(71, 1), Pair(49, -3), Pair(248, -37), Pair(98, -30), Pair(44, -32), Pair(-39, 35),
        Pair(-53, -40), Pair(-20, -59), Pair(39, -18), Pair(107, 21), Pair(-63, 44), Pair(44, -43), Pair(91, -28), Pair(12, -30),
        Pair(-28, -103), Pair(-23, -149), Pair(-15, -71), Pair(-54, -26), Pair(-10, -42), Pair(231, -40), Pair(-6, -18), Pair(100, -84),
        Pair(16, 17), Pair(37, -123), Pair(42, -33), Pair(20, -37), Pair(-11, -79), Pair(72, -52), Pair(11, -71), Pair(-8, 12)
      },
      { // Piece 2
        Pair(12, 25), Pair(-11, 21), Pair(-11, 27), Pair(-27, 38), Pair(4, 12), Pair(-15, -12), Pair(38, -38), Pair(13, -4),
        Pair(-34, -16), Pair(-58, 56), Pair(-70, -7), Pair(-85, 66), Pair(6, -13), Pair(-29, -39), Pair(40, -29), Pair(59, 73),
        Pair(-48, -42), Pair(-2, -4), Pair(-98, 33), Pair(-76, -6), Pair(-65, -10), Pair(-135, 63), Pair(-70, 67), Pair(-8, 13),
        Pair(-13, -18), Pair(-35, 20), Pair(-172, 78), Pair(-54, 27), Pair(-65, 55), Pair(-138, 75), Pair(-68, 45), Pair(-19, -54),
        Pair(-92, 0), Pair(-32, 79), Pair(-113, -33), Pair(-138, 81), Pair(42, 15), Pair(-51, 16), Pair(-33, 26), Pair(-11, 40),
        Pair(-87, 65), Pair(-41, -40), Pair(19, -6), Pair(-7, 9), Pair(-14, -9), Pair(-35, -18), Pair(-19, 14), Pair(-60, 11),
        Pair(-13, -42), Pair(-77, -37), Pair(-50, -11), Pair(48, -2), Pair(84, -68), Pair(-21, 6), Pair(34, -71), Pair(-63, 21),
        Pair(-45, -42), Pair(-74, 38), Pair(-52, -69), Pair(-107, -18), Pair(-139, -31), Pair(-26, -42), Pair(-54, 58), Pair(-60, -25)
      },
      { // Piece 3
        Pair(-43, -34), Pair(46, -95), Pair(8, -56), Pair(-9, -6), Pair(-18, -31), Pair(-8, -63), Pair(23, -49), Pair(-25, -49),
        Pair(125, -100), Pair(-48, -42), Pair(8, -83), Pair(-33, -50), Pair(-26, -77), Pair(95, -102), Pair(-29, -53), Pair(15, -93),
        Pair(69, -93), Pair(66, -108), Pair(17, -83), Pair(60, -93), Pair(-26, -68), Pair(-38, -79), Pair(77, -90), Pair(116, -147),
        Pair(29, -65), Pair(-92, -54), Pair(40, -84), Pair(6, -75), Pair(42, -107), Pair(75, -120), Pair(-20, -96), Pair(82, -104),
        Pair(-61, -57), Pair(-59, -70), Pair(111, -89), Pair(100, -61), Pair(70, -90), Pair(78, -91), Pair(38, -109), Pair(76, -103),
        Pair(-48, -62), Pair(-38, -47), Pair(90, -143), Pair(122, -139), Pair(116, -82), Pair(95, -80), Pair(12, -114), Pair(75, -106),
        Pair(25, -128), Pair(-53, -92), Pair(102, -145), Pair(-6, -89), Pair(136, -154), Pair(-2, -60), Pair(138, -51), Pair(34, -138),
        Pair(52, -123), Pair(81, -149), Pair(25, -100), Pair(95, -130), Pair(25, -160), Pair(154, -157), Pair(65, -127), Pair(89, -146)
      },
      { // Piece 4
        Pair(-236, -120), Pair(-59, -153), Pair(-121, -198), Pair(-64, -162), Pair(-139, -176), Pair(-68, -87), Pair(-168, -138), Pair(-102, -130),
        Pair(-84, -143), Pair(-53, -99), Pair(-75, -78), Pair(-56, -138), Pair(-61, -50), Pair(-67, -183), Pair(58, -136), Pair(-40, -117),
        Pair(-40, -152), Pair(-104, -104), Pair(-51, -61), Pair(-100, -103), Pair(46, -63), Pair(-3, -251), Pair(-74, -159), Pair(-44, -130),
        Pair(-54, -155), Pair(-68, -94), Pair(76, -107), Pair(64, -168), Pair(-3, -129), Pair(-9, -113), Pair(-52, -148), Pair(-57, -104),
        Pair(45, -106), Pair(3, -142), Pair(107, -81), Pair(-38, -94), Pair(-40, -87), Pair(24, -107), Pair(-13, -81), Pair(-40, -117),
        Pair(-30, -195), Pair(64, -64), Pair(16, -103), Pair(21, -63), Pair(-6, -170), Pair(18, -88), Pair(-70, -93), Pair(5, -2),
        Pair(-64, -155), Pair(-25, -71), Pair(31, 14), Pair(56, -84), Pair(14, -94), Pair(-12, -102), Pair(-69, -109), Pair(-47, -124),
        Pair(39, -68), Pair(-32, -169), Pair(67, -65), Pair(-21, -123), Pair(10, -102), Pair(-13, -109), Pair(1, -108), Pair(-76, -159)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-55, 75), Pair(-79, 36), Pair(-79, 55), Pair(6, 24), Pair(-12, 49), Pair(-71, 61), Pair(29, 22), Pair(56, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }}
  }},
  {{ // Bucket 3
    {{ // Bucket 0
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(232, 184), Pair(150, 200), Pair(37, 302), Pair(171, 193), Pair(133, 170), Pair(124, 164), Pair(51, 56), Pair(-39, 36),
        Pair(-15, 133), Pair(0, 151), Pair(68, 143), Pair(91, 113), Pair(129, 62), Pair(133, 24), Pair(85, 61), Pair(-1, 65),
        Pair(-35, 52), Pair(5, 42), Pair(27, 26), Pair(33, 0), Pair(62, -26), Pair(36, -3), Pair(61, -8), Pair(-21, 8),
        Pair(-32, 15), Pair(-11, 20), Pair(2, -8), Pair(18, -18), Pair(36, -27), Pair(67, -32), Pair(44, -28), Pair(-23, -33),
        Pair(-40, 4), Pair(-19, 9), Pair(-1, -16), Pair(-8, -12), Pair(15, -14), Pair(28, -19), Pair(36, -13), Pair(-51, -22),
        Pair(-47, 12), Pair(-11, 7), Pair(-26, 3), Pair(11, -5), Pair(-10, 14), Pair(-8, -1), Pair(9, -3), Pair(-62, -14),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-432, 102), Pair(-184, -9), Pair(-198, 104), Pair(68, 71), Pair(-29, 78), Pair(209, 27), Pair(-68, 19), Pair(1, -70),
        Pair(-78, 44), Pair(-2, 54), Pair(-35, 71), Pair(21, 108), Pair(98, 120), Pair(83, 43), Pair(-44, 37), Pair(30, 6),
        Pair(-52, 20), Pair(37, 56), Pair(100, 102), Pair(93, 100), Pair(133, 74), Pair(127, 105), Pair(67, 99), Pair(115, 20),
        Pair(-77, 82), Pair(48, 68), Pair(92, 82), Pair(108, 96), Pair(85, 111), Pair(99, 126), Pair(94, 96), Pair(130, 24),
        Pair(-49, 64), Pair(-10, 85), Pair(12, 118), Pair(34, 105), Pair(54, 107), Pair(62, 84), Pair(66, 86), Pair(21, 51),
        Pair(-79, 26), Pair(-46, 82), Pair(-13, 72), Pair(24, 89), Pair(5, 93), Pair(31, 53), Pair(-34, 64), Pair(-8, 26),
        Pair(-173, -3), Pair(-137, 67), Pair(-73, 68), Pair(-54, 79), Pair(-23, 60), Pair(-4, 46), Pair(-38, 27), Pair(-29, -6),
        Pair(-145, -8), Pair(-127, 18), Pair(-143, 56), Pair(-98, 38), Pair(-60, 41), Pair(-135, 31), Pair(-98, 3), Pair(47, -99)
      },
      { // Piece 2
        Pair(-233, 90), Pair(-103, 56), Pair(-98, 54), Pair(-129, 69), Pair(-107, 58), Pair(-109, 105), Pair(-15, 103), Pair(84, 16),
        Pair(-92, 50), Pair(-37, 83), Pair(-66, 91), Pair(-9, 55), Pair(-23, 50), Pair(37, 43), Pair(-95, 99), Pair(-66, 66),
        Pair(24, 37), Pair(34, 48), Pair(51, 71), Pair(47, 69), Pair(61, 76), Pair(123, 63), Pair(82, 61), Pair(71, 46),
        Pair(-27, 45), Pair(28, 59), Pair(32, 71), Pair(104, 74), Pair(46, 77), Pair(64, 51), Pair(65, 69), Pair(-6, 69),
        Pair(-108, 41), Pair(13, 71), Pair(35, 78), Pair(22, 74), Pair(41, 73), Pair(12, 70), Pair(22, 17), Pair(-1, 24),
        Pair(-26, 11), Pair(-22, 47), Pair(-20, 64), Pair(-20, 72), Pair(-1, 60), Pair(-17, 63), Pair(-10, 44), Pair(3, 13),
        Pair(-7, -4), Pair(3, 3), Pair(10, 28), Pair(-9, 33), Pair(-22, 41), Pair(-19, 21), Pair(-14, 16), Pair(-77, 0),
        Pair(-104, 41), Pair(-11, 53), Pair(-75, 10), Pair(-94, 27), Pair(-68, 33), Pair(-89, 13), Pair(-92, 16), Pair(-62, 17)
      },
      { // Piece 3
        Pair(56, 112), Pair(44, 130), Pair(12, 173), Pair(50, 125), Pair(66, 140), Pair(224, 30), Pair(4, 99), Pair(99, 111),
        Pair(35, 109), Pair(25, 120), Pair(29, 127), Pair(58, 118), Pair(110, 93), Pair(153, 76), Pair(83, 102), Pair(72, 104),
        Pair(-56, 115), Pair(-27, 115), Pair(29, 109), Pair(38, 102), Pair(24, 103), Pair(126, 69), Pair(104, 79), Pair(41, 63),
        Pair(-42, 93), Pair(-23, 105), Pair(-1, 94), Pair(8, 96), Pair(16, 79), Pair(17, 82), Pair(93, 45), Pair(27, 67),
        Pair(-100, 93), Pair(-91, 107), Pair(-23, 87), Pair(-63, 96), Pair(-60, 80), Pair(-48, 84), Pair(-26, 60), Pair(-11, 40),
        Pair(-84, 61), Pair(-89, 82), Pair(-89, 78), Pair(-83, 72), Pair(-100, 86), Pair(-16, 39), Pair(-38, 60), Pair(-42, 43),
        Pair(-119, 57), Pair(-70, 60), Pair(-69, 75), Pair(-47, 53), Pair(-71, 70), Pair(-38, 42), Pair(-1, 3), Pair(-100, 61),
        Pair(-76, 58), Pair(-87, 75), Pair(-73, 90), Pair(-62, 74), Pair(-54, 70), Pair(-34, 58), Pair(-24, 41), Pair(-32, 31)
      },
      { // Piece 4
        Pair(-131, 128), Pair(-56, 140), Pair(-10, 145), Pair(-23, 150), Pair(-11, 191), Pair(121, 92), Pair(98, 112), Pair(30, 1),
        Pair(-48, 103), Pair(-131, 176), Pair(5, 124), Pair(-29, 196), Pair(29, 183), Pair(178, 144), Pair(-27, 185), Pair(44, 103),
        Pair(-65, 60), Pair(-48, 96), Pair(-25, 104), Pair(-26, 157), Pair(-2, 191), Pair(102, 120), Pair(78, 154), Pair(95, 96),
        Pair(-71, 94), Pair(-94, 136), Pair(-7, 98), Pair(-28, 126), Pair(9, 156), Pair(11, 178), Pair(47, 136), Pair(26, 141),
        Pair(-60, 23), Pair(-45, 80), Pair(-58, 114), Pair(10, 107), Pair(-17, 138), Pair(32, 92), Pair(15, 87), Pair(4, 66),
        Pair(-101, 59), Pair(-69, 55), Pair(-51, 72), Pair(-63, 89), Pair(-55, 80), Pair(-59, 123), Pair(9, -5), Pair(13, -47),
        Pair(-56, -28), Pair(-62, 20), Pair(-26, -16), Pair(-38, 42), Pair(-25, 5), Pair(-13, -30), Pair(-33, -26), Pair(29, -52),
        Pair(-82, 28), Pair(-72, -36), Pair(-36, -38), Pair(-52, 5), Pair(-43, -10), Pair(-76, 11), Pair(-60, 11), Pair(22, -33)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-38, -17), Pair(19, -3), Pair(-6, 13), Pair(-96, 55), Pair(-75, 48), Pair(-57, 33), Pair(-1, -2), Pair(-1, -33),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 1
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(77, 271), Pair(29, 228), Pair(227, 86), Pair(157, 27), Pair(126, 10), Pair(137, 1), Pair(7, 243), Pair(116, 245),
        Pair(-21, 135), Pair(70, 106), Pair(129, 57), Pair(70, 55), Pair(78, 44), Pair(111, 35), Pair(52, 73), Pair(-4, 92),
        Pair(-38, 40), Pair(-27, 42), Pair(-1, 12), Pair(21, 6), Pair(54, -16), Pair(38, -7), Pair(54, -3), Pair(-17, 11),
        Pair(-63, 15), Pair(-47, 23), Pair(-5, -27), Pair(10, -12), Pair(13, -21), Pair(34, -29), Pair(39, -22), Pair(-59, -9),
        Pair(-92, 14), Pair(-15, 2), Pair(14, -22), Pair(29, -17), Pair(9, -16), Pair(25, -24), Pair(37, -18), Pair(-38, -24),
        Pair(-99, 30), Pair(-42, 17), Pair(-20, -10), Pair(-83, 3), Pair(-32, 9), Pair(-22, -12), Pair(-20, -7), Pair(-83, -2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-233, -47), Pair(10, 31), Pair(-66, 93), Pair(-66, 58), Pair(14, 19), Pair(-154, 11), Pair(24, 24), Pair(-181, 2),
        Pair(-32, 22), Pair(-65, 41), Pair(11, 29), Pair(48, 74), Pair(90, -22), Pair(46, 84), Pair(54, 39), Pair(-101, 121),
        Pair(-9, 24), Pair(63, 63), Pair(126, 62), Pair(105, 73), Pair(164, 56), Pair(118, 85), Pair(71, 35), Pair(92, -1),
        Pair(14, 2), Pair(103, 47), Pair(128, 85), Pair(102, 88), Pair(92, 96), Pair(106, 88), Pair(87, 84), Pair(68, 29),
        Pair(-31, 40), Pair(32, 57), Pair(-21, 93), Pair(26, 94), Pair(37, 91), Pair(53, 79), Pair(74, 64), Pair(35, 11),
        Pair(-57, -29), Pair(41, 29), Pair(13, 31), Pair(21, 65), Pair(31, 65), Pair(20, 41), Pair(-66, 70), Pair(38, -8),
        Pair(-234, 6), Pair(-46, 12), Pair(-35, 4), Pair(-74, 61), Pair(-39, 51), Pair(7, 22), Pair(23, -21), Pair(-70, -9),
        Pair(-72, -23), Pair(-102, -55), Pair(-115, 20), Pair(-158, 34), Pair(-148, 24), Pair(-98, -6), Pair(-87, -20), Pair(-107, 88)
      },
      { // Piece 2
        Pair(-101, 10), Pair(-141, 53), Pair(-49, -3), Pair(-68, 38), Pair(-17, 53), Pair(-46, 51), Pair(-39, -14), Pair(-178, 27),
        Pair(8, 14), Pair(32, 27), Pair(-21, 50), Pair(109, 24), Pair(1, 37), Pair(42, 31), Pair(-51, 76), Pair(-54, 16),
        Pair(-75, 25), Pair(-4, 22), Pair(71, 30), Pair(75, 27), Pair(79, 40), Pair(74, 43), Pair(78, 28), Pair(50, 2),
        Pair(2, 6), Pair(81, 13), Pair(137, -5), Pair(58, 39), Pair(131, 19), Pair(101, 36), Pair(74, 18), Pair(12, -3),
        Pair(-1, -5), Pair(-16, 64), Pair(4, 48), Pair(45, 46), Pair(40, 19), Pair(35, 34), Pair(28, 24), Pair(-40, 3),
        Pair(17, -26), Pair(4, 17), Pair(13, 24), Pair(18, 30), Pair(44, -1), Pair(18, 14), Pair(77, -19), Pair(6, 0),
        Pair(-45, 25), Pair(-9, -2), Pair(53, -11), Pair(-20, 3), Pair(-33, 8), Pair(-21, -5), Pair(-9, -19), Pair(-3, -40),
        Pair(19, -18), Pair(-17, -9), Pair(-81, 9), Pair(-107, 3), Pair(-30, -7), Pair(-99, -3), Pair(-94, 12), Pair(-51, -21)
      },
      { // Piece 3
        Pair(62, 66), Pair(16, 60), Pair(-24, 72), Pair(114, 15), Pair(47, 15), Pair(49, 97), Pair(29, 68), Pair(69, 52),
        Pair(88, 62), Pair(12, 84), Pair(82, 68), Pair(113, 57), Pair(128, 38), Pair(66, 68), Pair(117, 62), Pair(136, 46),
        Pair(-26, 69), Pair(5, 64), Pair(9, 88), Pair(45, 60), Pair(51, 54), Pair(57, 69), Pair(47, 27), Pair(16, 43),
        Pair(-69, 60), Pair(-93, 97), Pair(16, 47), Pair(21, 40), Pair(32, 48), Pair(30, 36), Pair(9, 48), Pair(-5, 34),
        Pair(-115, 58), Pair(-135, 79), Pair(-67, 46), Pair(-117, 74), Pair(-89, 61), Pair(-31, 14), Pair(-65, 33), Pair(-34, 21),
        Pair(-155, 35), Pair(-113, 40), Pair(-79, 28), Pair(-72, 32), Pair(-98, 36), Pair(-111, 63), Pair(-62, 30), Pair(-21, 21),
        Pair(-158, 26), Pair(-144, 28), Pair(-134, 47), Pair(-137, 62), Pair(-81, 19), Pair(-67, 4), Pair(-54, 3), Pair(-78, 13),
        Pair(-115, 22), Pair(-9, -20), Pair(-84, 36), Pair(-73, 34), Pair(-42, 29), Pair(-72, 34), Pair(-61, 26), Pair(-24, -24)
      },
      { // Piece 4
        Pair(-153, 87), Pair(-17, 54), Pair(-8, 34), Pair(54, 112), Pair(43, 92), Pair(117, 62), Pair(0, 35), Pair(22, 66),
        Pair(1, 12), Pair(7, 26), Pair(60, 5), Pair(89, 93), Pair(5, 142), Pair(63, 26), Pair(-39, 108), Pair(91, -14),
        Pair(39, -25), Pair(105, -9), Pair(81, 69), Pair(27, 154), Pair(64, 142), Pair(69, 80), Pair(146, 81), Pair(54, 22),
        Pair(-37, -9), Pair(-18, 43), Pair(-8, 75), Pair(-23, 111), Pair(85, 105), Pair(61, 62), Pair(12, 105), Pair(1, 15),
        Pair(-36, -93), Pair(59, -19), Pair(-85, 76), Pair(11, 58), Pair(-5, 49), Pair(66, -16), Pair(-13, 64), Pair(-45, 46),
        Pair(-96, -104), Pair(-83, -24), Pair(-51, 53), Pair(-62, -59), Pair(-51, 55), Pair(-107, 56), Pair(-40, -26), Pair(3, -17),
        Pair(-85, -23), Pair(-35, -90), Pair(-125, -39), Pair(-90, -32), Pair(-49, -81), Pair(-63, -55), Pair(-49, -116), Pair(10, -90),
        Pair(-106, -9), Pair(-124, 3), Pair(-64, -92), Pair(-82, -101), Pair(-112, -114), Pair(-36, -83), Pair(-92, -44), Pair(-55, 29)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-22, -8), Pair(36, -4), Pair(2, 17), Pair(-17, 24), Pair(-32, 27), Pair(-18, 13), Pair(3, -12), Pair(46, -46),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 2
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(214, 156), Pair(224, 127), Pair(222, 101), Pair(185, 59), Pair(129, 80), Pair(173, 43), Pair(142, 124), Pair(246, 95),
        Pair(-35, 117), Pair(73, 99), Pair(115, 61), Pair(123, 42), Pair(146, 13), Pair(86, 23), Pair(16, 55), Pair(-37, 77),
        Pair(-39, 43), Pair(15, 24), Pair(3, 14), Pair(22, -3), Pair(32, -8), Pair(22, -4), Pair(52, 0), Pair(0, -2),
        Pair(-59, 19), Pair(-33, 17), Pair(-2, -11), Pair(6, -15), Pair(30, -19), Pair(29, -24), Pair(36, -14), Pair(-43, -14),
        Pair(-58, 6), Pair(-23, 6), Pair(-2, -15), Pair(-5, -11), Pair(18, -18), Pair(28, -27), Pair(31, -17), Pair(-46, -19),
        Pair(-76, 26), Pair(-52, 19), Pair(-24, -6), Pair(-35, 2), Pair(-10, -4), Pair(-6, -9), Pair(-5, -3), Pair(-63, -2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-47, -46), Pair(-56, 28), Pair(-44, 41), Pair(65, 30), Pair(46, 45), Pair(53, 20), Pair(138, -15), Pair(-118, -87),
        Pair(-42, 24), Pair(-48, 37), Pair(11, 52), Pair(72, 61), Pair(108, 42), Pair(78, 36), Pair(-7, 37), Pair(-39, 15),
        Pair(-11, 36), Pair(44, 55), Pair(109, 72), Pair(132, 71), Pair(125, 67), Pair(128, 76), Pair(82, 65), Pair(56, 24),
        Pair(26, 26), Pair(82, 52), Pair(98, 78), Pair(115, 80), Pair(117, 86), Pair(110, 78), Pair(84, 66), Pair(95, 25),
        Pair(29, 19), Pair(82, 47), Pair(69, 83), Pair(82, 81), Pair(108, 76), Pair(87, 77), Pair(123, 46), Pair(69, 19),
        Pair(-70, 21), Pair(-29, 54), Pair(41, 47), Pair(53, 57), Pair(30, 68), Pair(63, 40), Pair(49, 36), Pair(2, -12),
        Pair(-59, 18), Pair(-87, 42), Pair(-31, 24), Pair(-3, 41), Pair(-16, 52), Pair(11, 25), Pair(-31, 36), Pair(31, -29),
        Pair(-115, -62), Pair(-198, 24), Pair(-91, 24), Pair(-55, 13), Pair(-149, 44), Pair(-99, 3), Pair(-125, 16), Pair(-176, -9)
      },
      { // Piece 2
        Pair(-32, 24), Pair(-1, 18), Pair(-34, 29), Pair(-16, 24), Pair(-31, 26), Pair(-71, 19), Pair(18, 8), Pair(-23, 31),
        Pair(-66, 4), Pair(-21, 32), Pair(41, 17), Pair(-1, 32), Pair(10, 39), Pair(63, 14), Pair(41, 27), Pair(-50, 27),
        Pair(-36, 25), Pair(77, 17), Pair(77, 14), Pair(119, 12), Pair(147, 9), Pair(160, 11), Pair(54, 29), Pair(20, 11),
        Pair(-32, 29), Pair(62, 26), Pair(108, 18), Pair(94, 31), Pair(130, 33), Pair(117, 26), Pair(77, 31), Pair(48, 1),
        Pair(-35, 14), Pair(51, 11), Pair(49, 35), Pair(65, 37), Pair(90, 26), Pair(40, 33), Pair(67, 7), Pair(-3, 7),
        Pair(-24, 1), Pair(-17, 30), Pair(35, 19), Pair(10, 21), Pair(44, 18), Pair(18, 20), Pair(11, 8), Pair(16, -12),
        Pair(-12, 2), Pair(-25, 0), Pair(1, 0), Pair(28, 0), Pair(6, 3), Pair(0, -12), Pair(20, -19), Pair(-8, -47),
        Pair(-75, 14), Pair(-20, -17), Pair(-68, -3), Pair(-32, -6), Pair(-18, -14), Pair(-31, -18), Pair(-114, 41), Pair(-52, -16)
      },
      { // Piece 3
        Pair(100, 49), Pair(77, 52), Pair(21, 78), Pair(41, 62), Pair(102, 36), Pair(119, 39), Pair(96, 45), Pair(132, 46),
        Pair(24, 65), Pair(20, 64), Pair(-7, 88), Pair(52, 66), Pair(45, 64), Pair(3, 46), Pair(62, 38), Pair(4, 56),
        Pair(22, 49), Pair(21, 49), Pair(68, 43), Pair(61, 40), Pair(121, 15), Pair(163, 15), Pair(73, 33), Pair(43, 46),
        Pair(-42, 52), Pair(1, 50), Pair(-40, 71), Pair(53, 48), Pair(21, 51), Pair(51, 43), Pair(24, 43), Pair(27, 36),
        Pair(-66, 34), Pair(-95, 68), Pair(-78, 63), Pair(-61, 59), Pair(-27, 47), Pair(-48, 52), Pair(-28, 38), Pair(-84, 36),
        Pair(-145, 29), Pair(-101, 48), Pair(-96, 41), Pair(-106, 39), Pair(-105, 45), Pair(-55, 16), Pair(-46, 12), Pair(-37, -18),
        Pair(-129, 22), Pair(-79, 12), Pair(-86, 19), Pair(-44, 9), Pair(-49, 8), Pair(-46, -2), Pair(-27, -3), Pair(-78, 23),
        Pair(-84, 24), Pair(-85, 29), Pair(-88, 43), Pair(-64, 30), Pair(-60, 23), Pair(-35, 15), Pair(-41, 22), Pair(-23, -4)
      },
      { // Piece 4
        Pair(5, 10), Pair(72, 16), Pair(35, 70), Pair(101, 12), Pair(66, 65), Pair(211, -38), Pair(180, 7), Pair(142, -14),
        Pair(-67, -14), Pair(-50, 41), Pair(-38, 55), Pair(-62, 123), Pair(61, 68), Pair(55, 52), Pair(-27, 65), Pair(116, -58),
        Pair(3, -18), Pair(-89, 51), Pair(61, -3), Pair(-11, 66), Pair(85, 42), Pair(178, 23), Pair(-69, 145), Pair(91, 19),
        Pair(-59, -20), Pair(-39, 30), Pair(8, 27), Pair(24, 95), Pair(49, 95), Pair(32, 140), Pair(153, 16), Pair(44, 80),
        Pair(-33, -54), Pair(-83, 21), Pair(-57, 49), Pair(0, 44), Pair(12, 56), Pair(-20, 92), Pair(-21, 86), Pair(53, -4),
        Pair(-57, -69), Pair(-32, -3), Pair(-44, 12), Pair(-22, -17), Pair(-28, 20), Pair(-35, 52), Pair(-41, 9), Pair(-77, -101),
        Pair(-13, -138), Pair(-41, -72), Pair(-34, -38), Pair(-10, -53), Pair(-28, -14), Pair(-69, 0), Pair(-64, -32), Pair(-12, -69),
        Pair(-80, -126), Pair(-41, -43), Pair(-48, -79), Pair(-43, -64), Pair(-105, -8), Pair(-194, 45), Pair(-85, -65), Pair(-90, -28)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(62, -51), Pair(26, -8), Pair(0, 11), Pair(-43, 30), Pair(-39, 26), Pair(-15, 10), Pair(8, -9), Pair(-2, -33),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 3
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(186, 150), Pair(206, 143), Pair(119, 128), Pair(209, 83), Pair(136, 94), Pair(142, 86), Pair(215, 128), Pair(82, 147),
        Pair(18, 83), Pair(76, 65), Pair(76, 40), Pair(72, 18), Pair(85, 8), Pair(105, 1), Pair(65, 59), Pair(-5, 68),
        Pair(-56, 32), Pair(-20, 22), Pair(42, -12), Pair(6, -17), Pair(30, -26), Pair(43, -27), Pair(20, -4), Pair(-48, 2),
        Pair(-62, 7), Pair(-37, 10), Pair(-13, -16), Pair(-11, -8), Pair(3, -11), Pair(17, -23), Pair(7, -6), Pair(-48, -21),
        Pair(-85, 5), Pair(-47, 3), Pair(-8, -21), Pair(-14, -12), Pair(21, -19), Pair(24, -28), Pair(3, -9), Pair(-77, -13),
        Pair(-85, 18), Pair(-51, 11), Pair(-46, -2), Pair(-11, -11), Pair(-9, -1), Pair(-16, -7), Pair(-26, 6), Pair(-73, -5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-87, -149), Pair(-27, -3), Pair(-140, 55), Pair(-24, 40), Pair(40, -6), Pair(-67, 33), Pair(33, 6), Pair(-81, -110),
        Pair(-14, -34), Pair(-71, 23), Pair(31, 25), Pair(96, 22), Pair(139, 21), Pair(-2, 1), Pair(41, 18), Pair(-89, 2),
        Pair(-3, -23), Pair(76, 20), Pair(92, 39), Pair(116, 42), Pair(138, 28), Pair(130, 35), Pair(51, 24), Pair(60, -17),
        Pair(71, -14), Pair(51, 27), Pair(144, 40), Pair(107, 59), Pair(170, 48), Pair(127, 54), Pair(125, 39), Pair(102, -3),
        Pair(14, 7), Pair(70, 28), Pair(52, 47), Pair(92, 50), Pair(58, 59), Pair(95, 49), Pair(75, 33), Pair(74, -10),
        Pair(-44, -22), Pair(12, 26), Pair(33, 28), Pair(59, 40), Pair(16, 48), Pair(55, 21), Pair(-9, 31), Pair(-13, 2),
        Pair(-96, -48), Pair(-63, 9), Pair(-49, 12), Pair(-20, 24), Pair(-39, 32), Pair(-19, 16), Pair(-15, 13), Pair(10, -19),
        Pair(35, -50), Pair(-220, 13), Pair(-128, -12), Pair(-70, -6), Pair(-1, -37), Pair(-86, -18), Pair(-102, -11), Pair(-112, -61)
      },
      { // Piece 2
        Pair(-41, -27), Pair(-25, 4), Pair(-23, -6), Pair(-34, 11), Pair(-43, 2), Pair(-34, 1), Pair(61, -3), Pair(-34, -24),
        Pair(-34, -30), Pair(-19, 12), Pair(38, 0), Pair(12, -2), Pair(-3, -24), Pair(-11, 0), Pair(1, -14), Pair(-47, -4),
        Pair(-3, -11), Pair(32, 5), Pair(57, -7), Pair(20, 5), Pair(196, -27), Pair(158, -16), Pair(105, -7), Pair(-13, -22),
        Pair(-46, -2), Pair(55, 5), Pair(61, -2), Pair(122, -5), Pair(124, 2), Pair(57, -7), Pair(97, -1), Pair(54, -19),
        Pair(11, -33), Pair(22, -6), Pair(100, -7), Pair(39, 10), Pair(70, -1), Pair(69, -10), Pair(55, -6), Pair(-5, -29),
        Pair(-98, -2), Pair(28, -14), Pair(24, -4), Pair(-21, 8), Pair(10, 1), Pair(-5, 1), Pair(12, -10), Pair(-78, 3),
        Pair(-77, -12), Pair(-72, -9), Pair(15, -17), Pair(-15, -15), Pair(-26, -14), Pair(-14, -11), Pair(-34, -30), Pair(19, -72),
        Pair(-128, -31), Pair(-41, -12), Pair(-89, -23), Pair(-49, -21), Pair(-49, -32), Pair(-88, -16), Pair(27, -51), Pair(-42, -27)
      },
      { // Piece 3
        Pair(13, 11), Pair(32, 11), Pair(63, 5), Pair(64, 1), Pair(57, 6), Pair(66, 9), Pair(101, -3), Pair(69, 5),
        Pair(85, -26), Pair(46, -3), Pair(92, -14), Pair(122, -15), Pair(76, 4), Pair(128, -23), Pair(125, -37), Pair(87, -25),
        Pair(-22, 9), Pair(10, 5), Pair(68, -5), Pair(63, -14), Pair(55, -6), Pair(94, -24), Pair(43, -19), Pair(-57, -2),
        Pair(-26, -2), Pair(34, -15), Pair(67, -10), Pair(16, 1), Pair(113, -29), Pair(89, -26), Pair(81, -23), Pair(-4, -6),
        Pair(-105, -3), Pair(-37, -5), Pair(-18, -4), Pair(-15, 1), Pair(3, -13), Pair(-13, -5), Pair(-24, 10), Pair(20, -32),
        Pair(-148, -17), Pair(-76, -15), Pair(-25, -31), Pair(-92, -10), Pair(-56, -23), Pair(-30, -27), Pair(43, -45), Pair(-116, -24),
        Pair(-149, -23), Pair(-66, -38), Pair(-18, -49), Pair(-51, -32), Pair(-82, -17), Pair(-61, -41), Pair(-67, -37), Pair(-50, -32),
        Pair(-58, -40), Pair(-55, -37), Pair(-80, -14), Pair(-40, -25), Pair(-32, -30), Pair(-11, -39), Pair(-27, -34), Pair(-35, -39)
      },
      { // Piece 4
        Pair(39, -82), Pair(127, -107), Pair(38, -58), Pair(189, -70), Pair(81, -7), Pair(66, 3), Pair(0, 28), Pair(100, -17),
        Pair(66, -138), Pair(-114, 22), Pair(-123, 65), Pair(-21, 7), Pair(46, 29), Pair(-3, 34), Pair(231, -125), Pair(-15, 13),
        Pair(-83, -51), Pair(-137, -54), Pair(42, -67), Pair(-2, -5), Pair(135, -64), Pair(122, -43), Pair(-30, -59), Pair(-36, -139),
        Pair(-27, -143), Pair(-112, -10), Pair(-85, -20), Pair(29, -35), Pair(-41, 19), Pair(144, -87), Pair(48, -69), Pair(59, -98),
        Pair(-13, -91), Pair(-103, -16), Pair(-74, -8), Pair(-31, 12), Pair(35, 1), Pair(35, -32), Pair(-19, 8), Pair(-45, -10),
        Pair(-86, -112), Pair(11, -161), Pair(-104, -31), Pair(-16, -93), Pair(-41, -81), Pair(-33, 5), Pair(53, -96), Pair(-69, -40),
        Pair(-161, -91), Pair(-49, -140), Pair(-46, -121), Pair(-16, -94), Pair(-46, -132), Pair(-81, -5), Pair(-14, -145), Pair(-64, -151),
        Pair(-59, -189), Pair(-199, 3), Pair(-112, -80), Pair(12, -170), Pair(-91, -105), Pair(5, -71), Pair(-100, -172), Pair(-53, -132)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-14, -24), Pair(23, -4), Pair(5, 8), Pair(-19, 24), Pair(3, 18), Pair(22, 4), Pair(4, -3), Pair(-1, -27),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 4
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(139, 147), Pair(195, 109), Pair(10, 141), Pair(159, 85), Pair(91, 108), Pair(78, 114), Pair(-17, 169), Pair(-31, 165),
        Pair(-21, 92), Pair(45, 75), Pair(12, 63), Pair(96, 45), Pair(104, 31), Pair(-39, 53), Pair(44, 65), Pair(-19, 79),
        Pair(-65, 23), Pair(30, -7), Pair(26, -21), Pair(-5, -31), Pair(-10, -28), Pair(44, -42), Pair(67, -24), Pair(-14, -13),
        Pair(-111, 7), Pair(-51, 1), Pair(-13, -29), Pair(16, -39), Pair(18, -45), Pair(11, -44), Pair(-21, -20), Pair(-97, -18),
        Pair(-119, 5), Pair(-59, -1), Pair(-58, -12), Pair(-18, -16), Pair(-10, -17), Pair(11, -28), Pair(-20, -13), Pair(-91, -17),
        Pair(-136, 20), Pair(-76, 10), Pair(-47, -10), Pair(-1, -16), Pair(12, -14), Pair(-8, -10), Pair(-42, 0), Pair(-71, -5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-64, -119), Pair(-48, -30), Pair(-116, 10), Pair(-46, -5), Pair(-85, 15), Pair(-42, -8), Pair(-45, -9), Pair(22, -57),
        Pair(-146, -36), Pair(-80, -23), Pair(3, -3), Pair(23, 24), Pair(83, 4), Pair(130, -17), Pair(-24, -2), Pair(-20, -67),
        Pair(-11, -35), Pair(4, 4), Pair(27, 28), Pair(38, 44), Pair(101, 30), Pair(13, 25), Pair(35, -14), Pair(45, -15),
        Pair(-45, -13), Pair(-28, 19), Pair(91, 13), Pair(77, 28), Pair(114, 26), Pair(146, 18), Pair(73, 1), Pair(-2, -6),
        Pair(41, -49), Pair(86, -6), Pair(90, 15), Pair(58, 34), Pair(95, 24), Pair(126, 9), Pair(82, 9), Pair(-6, 2),
        Pair(-9, -62), Pair(-92, 0), Pair(-17, 6), Pair(19, 17), Pair(55, 7), Pair(-6, 15), Pair(-64, 15), Pair(-74, -43),
        Pair(-51, -62), Pair(-172, 0), Pair(36, -22), Pair(-53, 11), Pair(-50, 17), Pair(-40, -5), Pair(-85, -8), Pair(-51, -24),
        Pair(-47, -97), Pair(-87, -10), Pair(-99, -31), Pair(-78, -22), Pair(-136, -8), Pair(-119, -35), Pair(-144, -27), Pair(-17, -101)
      },
      { // Piece 2
        Pair(-101, -12), Pair(-30, -17), Pair(-152, 11), Pair(-56, -11), Pair(-93, 1), Pair(-118, -1), Pair(-38, -19), Pair(48, -20),
        Pair(-99, -34), Pair(-49, -8), Pair(-166, 10), Pair(-109, 14), Pair(-141, 8), Pair(-85, -4), Pair(-91, 1), Pair(-57, -25),
        Pair(-19, -37), Pair(34, -24), Pair(-53, 6), Pair(-19, -7), Pair(-62, 4), Pair(58, -8), Pair(-49, 0), Pair(-145, -6),
        Pair(-96, -8), Pair(-62, 0), Pair(-24, -12), Pair(100, -28), Pair(118, -13), Pair(70, -21), Pair(-1, -9), Pair(-58, -29),
        Pair(-97, -29), Pair(-83, -10), Pair(-37, -16), Pair(51, -21), Pair(65, -16), Pair(52, -10), Pair(-4, -35), Pair(-68, -12),
        Pair(-28, -37), Pair(-45, -15), Pair(-39, -17), Pair(-29, -9), Pair(-1, -17), Pair(9, -30), Pair(-5, -30), Pair(-74, -29),
        Pair(-118, -22), Pair(-89, -33), Pair(-57, -22), Pair(-40, -23), Pair(-38, -27), Pair(-20, -30), Pair(-41, -42), Pair(-59, -45),
        Pair(-139, -19), Pair(-105, -32), Pair(-45, -68), Pair(-52, -42), Pair(-19, -52), Pair(-121, -31), Pair(-145, -33), Pair(-80, -46)
      },
      { // Piece 3
        Pair(25, -45), Pair(-8, -28), Pair(3, -25), Pair(23, -32), Pair(21, -22), Pair(31, -21), Pair(103, -60), Pair(64, -44),
        Pair(-42, -39), Pair(-25, -42), Pair(-48, -24), Pair(20, -44), Pair(53, -34), Pair(70, -66), Pair(33, -55), Pair(19, -57),
        Pair(9, -44), Pair(10, -42), Pair(65, -48), Pair(54, -43), Pair(97, -64), Pair(127, -63), Pair(69, -65), Pair(55, -66),
        Pair(-56, -43), Pair(-14, -57), Pair(13, -42), Pair(57, -67), Pair(129, -69), Pair(135, -80), Pair(-15, -38), Pair(-62, -52),
        Pair(-106, -40), Pair(-77, -38), Pair(-109, -26), Pair(5, -45), Pair(22, -60), Pair(49, -62), Pair(44, -54), Pair(-8, -68),
        Pair(-150, -81), Pair(-79, -55), Pair(-112, -46), Pair(-60, -71), Pair(-29, -50), Pair(-32, -65), Pair(95, -120), Pair(-57, -85),
        Pair(-90, -94), Pair(-93, -83), Pair(-88, -66), Pair(-70, -70), Pair(10, -96), Pair(-55, -64), Pair(-48, -94), Pair(-23, -84),
        Pair(-82, -79), Pair(-57, -77), Pair(-74, -59), Pair(-56, -59), Pair(-23, -73), Pair(-43, -74), Pair(-39, -72), Pair(-31, -76)
      },
      { // Piece 4
        Pair(69, -202), Pair(29, -121), Pair(-39, -78), Pair(-24, -6), Pair(86, -72), Pair(-75, -21), Pair(86, -186), Pair(-84, -86),
        Pair(-113, -67), Pair(-33, -91), Pair(41, -127), Pair(25, -72), Pair(51, -88), Pair(-34, -95), Pair(-31, -4), Pair(67, -137),
        Pair(-75, -56), Pair(5, -154), Pair(31, -50), Pair(19, -59), Pair(176, -144), Pair(-12, -72), Pair(151, -118), Pair(-37, -102),
        Pair(-96, -139), Pair(-25, -118), Pair(-3, -7), Pair(40, -125), Pair(15, -70), Pair(15, -65), Pair(-17, -92), Pair(-29, -16),
        Pair(-86, -165), Pair(-73, -65), Pair(16, -114), Pair(-48, -18), Pair(-58, 4), Pair(48, -78), Pair(-9, -71), Pair(-6, -54),
        Pair(-71, -188), Pair(-93, -114), Pair(-25, -14), Pair(-108, -39), Pair(68, -98), Pair(197, -94), Pair(16, -119), Pair(55, -35),
        Pair(-85, -158), Pair(-27, -133), Pair(-68, -193), Pair(-40, -101), Pair(-151, -113), Pair(-35, -103), Pair(-82, -173), Pair(-7, -70),
        Pair(-128, -191), Pair(-39, -167), Pair(-29, -169), Pair(-75, -102), Pair(-109, -169), Pair(-68, -91), Pair(2, -43), Pair(-58, -105)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(79, -53), Pair(6, -13), Pair(9, 0), Pair(-18, 15), Pair(-9, 17), Pair(17, 4), Pair(-15, -4), Pair(5, -30),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 5
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(77, 138), Pair(184, 96), Pair(-23, 130), Pair(-26, 166), Pair(35, 184), Pair(84, 142), Pair(37, 194), Pair(172, 130),
        Pair(-59, 121), Pair(15, 110), Pair(-69, 110), Pair(4, 82), Pair(-21, 90), Pair(7, 92), Pair(-8, 112), Pair(-26, 102),
        Pair(-112, 43), Pair(-50, 19), Pair(-9, 3), Pair(19, -15), Pair(-57, -1), Pair(70, -19), Pair(47, -7), Pair(-16, -1),
        Pair(-95, -7), Pair(-60, -9), Pair(-34, -30), Pair(21, -42), Pair(-63, -31), Pair(12, -46), Pair(-30, -28), Pair(-116, -19),
        Pair(-114, -12), Pair(-33, -15), Pair(-24, -36), Pair(-55, -24), Pair(-90, -20), Pair(4, -36), Pair(-45, -23), Pair(-144, -25),
        Pair(-145, 13), Pair(-119, 10), Pair(24, -27), Pair(-49, -51), Pair(-57, -28), Pair(-45, -15), Pair(-60, -2), Pair(-130, -6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-73, -145), Pair(-81, -71), Pair(-57, -54), Pair(-154, -69), Pair(-92, -48), Pair(-91, -49), Pair(13, -98), Pair(-56, -151),
        Pair(12, -93), Pair(45, -62), Pair(16, -45), Pair(-131, 2), Pair(-70, -22), Pair(61, -65), Pair(-28, -44), Pair(-64, -116),
        Pair(-78, -87), Pair(-140, -29), Pair(-33, -13), Pair(54, -16), Pair(82, -30), Pair(-66, -7), Pair(45, -52), Pair(-166, -58),
        Pair(146, -82), Pair(48, -44), Pair(56, -41), Pair(38, -11), Pair(116, -15), Pair(36, -21), Pair(23, -29), Pair(62, -96),
        Pair(-44, -50), Pair(-68, -19), Pair(53, -33), Pair(191, -31), Pair(134, -29), Pair(142, -15), Pair(61, -38), Pair(29, -41),
        Pair(-107, -88), Pair(-27, -17), Pair(27, -35), Pair(18, -57), Pair(2, -25), Pair(65, -45), Pair(-22, -54), Pair(22, -95),
        Pair(-78, -104), Pair(-115, -33), Pair(-45, -30), Pair(47, -70), Pair(25, -56), Pair(-14, -36), Pair(36, -43), Pair(8, -74),
        Pair(-21, -146), Pair(85, -79), Pair(34, -80), Pair(-20, -76), Pair(38, -56), Pair(61, -84), Pair(77, -91), Pair(-76, -80)
      },
      { // Piece 2
        Pair(-89, -63), Pair(25, -65), Pair(-157, 4), Pair(-142, -26), Pair(-116, -38), Pair(-209, -32), Pair(-54, -32), Pair(-47, -57),
        Pair(-87, -49), Pair(-121, -11), Pair(-88, 4), Pair(-91, 5), Pair(-208, 6), Pair(-100, -6), Pair(-110, -10), Pair(-31, -52),
        Pair(-160, -37), Pair(-27, -17), Pair(-61, -8), Pair(-124, 0), Pair(-118, 1), Pair(-53, -14), Pair(-6, -32), Pair(-36, -48),
        Pair(-116, -38), Pair(-38, 0), Pair(-91, -29), Pair(-49, -18), Pair(-85, -5), Pair(-68, 0), Pair(-109, -5), Pair(-160, -39),
        Pair(-56, -74), Pair(-64, -54), Pair(-51, -14), Pair(17, -37), Pair(32, -38), Pair(21, 2), Pair(-121, -19), Pair(-72, -93),
        Pair(-26, -54), Pair(-70, -45), Pair(-15, -45), Pair(28, -52), Pair(26, -40), Pair(62, -65), Pair(11, -72), Pair(-102, -59),
        Pair(-58, -59), Pair(-100, -40), Pair(-50, -43), Pair(-33, -74), Pair(-107, -48), Pair(-12, -57), Pair(-97, -46), Pair(7, -98),
        Pair(-20, -12), Pair(-163, 2), Pair(-86, -58), Pair(-71, -43), Pair(-4, -57), Pair(-19, -55), Pair(-107, -78), Pair(-107, -40)
      },
      { // Piece 3
        Pair(-20, -87), Pair(86, -112), Pair(72, -95), Pair(60, -73), Pair(46, -98), Pair(76, -101), Pair(109, -107), Pair(34, -82),
        Pair(-10, -118), Pair(68, -124), Pair(48, -101), Pair(2, -81), Pair(20, -69), Pair(40, -104), Pair(-45, -83), Pair(-12, -95),
        Pair(-37, -94), Pair(64, -116), Pair(45, -97), Pair(33, -93), Pair(71, -99), Pair(-4, -77), Pair(2, -96), Pair(-32, -102),
        Pair(-10, -94), Pair(40, -111), Pair(-10, -90), Pair(76, -110), Pair(64, -117), Pair(57, -114), Pair(58, -121), Pair(6, -114),
        Pair(22, -131), Pair(-41, -115), Pair(8, -102), Pair(22, -128), Pair(34, -115), Pair(69, -122), Pair(-102, -114), Pair(-18, -130),
        Pair(-10, -150), Pair(69, -155), Pair(12, -132), Pair(11, -146), Pair(19, -140), Pair(34, -130), Pair(27, -115), Pair(6, -130),
        Pair(5, -152), Pair(-26, -122), Pair(-4, -147), Pair(-14, -130), Pair(47, -138), Pair(125, -159), Pair(48, -142), Pair(122, -186),
        Pair(-20, -138), Pair(54, -142), Pair(-6, -137), Pair(19, -121), Pair(50, -167), Pair(50, -131), Pair(82, -169), Pair(85, -164)
      },
      { // Piece 4
        Pair(-174, -156), Pair(-95, -214), Pair(-187, -142), Pair(-22, -168), Pair(-162, -146), Pair(-171, -95), Pair(-164, -195), Pair(-158, -225),
        Pair(-100, -178), Pair(-89, -223), Pair(-85, -182), Pair(53, -105), Pair(-61, -131), Pair(40, -102), Pair(-60, -79), Pair(-31, -157),
        Pair(-47, -164), Pair(-88, -117), Pair(-48, -122), Pair(19, -130), Pair(-33, -111), Pair(-90, -147), Pair(-57, -152), Pair(-37, -156),
        Pair(-71, -172), Pair(-71, -132), Pair(-44, -156), Pair(-77, -119), Pair(21, -178), Pair(-149, -135), Pair(-98, -67), Pair(-106, -179),
        Pair(-85, -217), Pair(-34, -104), Pair(-12, -129), Pair(-70, -83), Pair(32, -108), Pair(-61, -125), Pair(-8, -91), Pair(-98, -120),
        Pair(-77, -178), Pair(30, -96), Pair(-31, -168), Pair(-50, -116), Pair(-2, -131), Pair(-91, -109), Pair(-25, -142), Pair(-77, -133),
        Pair(-43, -174), Pair(-19, -199), Pair(-84, -164), Pair(20, -47), Pair(-6, -70), Pair(-30, -165), Pair(-85, -157), Pair(-49, -100),
        Pair(-56, -114), Pair(-76, -209), Pair(10, -172), Pair(-71, -121), Pair(-38, -85), Pair(-79, -160), Pair(-61, -119), Pair(-135, -218)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-3, -45), Pair(28, -19), Pair(17, 0), Pair(-28, 22), Pair(17, 14), Pair(14, 12), Pair(22, -6), Pair(-10, -24),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 6
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-158, 174), Pair(-27, 145), Pair(-22, 219), Pair(-1, 124), Pair(37, 128), Pair(52, 157), Pair(-72, 182), Pair(-9, 166),
        Pair(-53, 146), Pair(-31, 140), Pair(-19, 175), Pair(-82, 85), Pair(186, 152), Pair(73, 82), Pair(-108, 210), Pair(-14, 124),
        Pair(-126, 23), Pair(-53, 37), Pair(-97, 43), Pair(-30, 19), Pair(-108, 8), Pair(-49, 39), Pair(-150, 37), Pair(-26, 26),
        Pair(-120, 5), Pair(-59, 2), Pair(-55, -18), Pair(45, -26), Pair(-16, -27), Pair(3, -26), Pair(-43, -10), Pair(-136, -17),
        Pair(-166, 11), Pair(-122, -19), Pair(-2, -26), Pair(-102, -23), Pair(33, -40), Pair(58, -34), Pair(-59, -9), Pair(-110, -10),
        Pair(-110, 21), Pair(-121, 15), Pair(6, -21), Pair(-2, -26), Pair(33, -56), Pair(17, -27), Pair(-81, 15), Pair(-147, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-21, -205), Pair(-42, -101), Pair(-57, -34), Pair(-56, -85), Pair(-55, -56), Pair(-56, -52), Pair(16, 15), Pair(-2, 33),
        Pair(-35, -130), Pair(2, -31), Pair(-27, -72), Pair(35, -93), Pair(-13, -46), Pair(-75, -20), Pair(33, -35), Pair(-2, -122),
        Pair(89, -78), Pair(-128, -20), Pair(-72, -15), Pair(-61, -27), Pair(11, -26), Pair(-90, -64), Pair(3, -47), Pair(36, 15),
        Pair(11, -45), Pair(72, -62), Pair(79, -24), Pair(20, -17), Pair(-18, 2), Pair(33, -20), Pair(13, -61), Pair(-2, -41),
        Pair(-38, -168), Pair(49, -62), Pair(-33, 13), Pair(76, -33), Pair(-9, -27), Pair(97, -49), Pair(21, -46), Pair(-7, -78),
        Pair(-47, -155), Pair(24, -26), Pair(-29, -75), Pair(88, -11), Pair(134, -9), Pair(18, -53), Pair(-59, -71), Pair(44, -84),
        Pair(-47, -116), Pair(25, -27), Pair(25, -70), Pair(137, -77), Pair(-46, -47), Pair(-107, -26), Pair(-26, -78), Pair(-91, -218),
        Pair(8, 19), Pair(53, -76), Pair(-46, -79), Pair(-68, -59), Pair(-20, -71), Pair(32, -65), Pair(1, -23), Pair(0, -20)
      },
      { // Piece 2
        Pair(17, 35), Pair(-22, 69), Pair(-7, 66), Pair(-17, 29), Pair(11, 14), Pair(-32, -73), Pair(-37, -16), Pair(-27, 58),
        Pair(1, 7), Pair(18, 28), Pair(-68, 1), Pair(-26, 31), Pair(-77, -33), Pair(88, -21), Pair(-74, 45), Pair(-30, -35),
        Pair(6, -17), Pair(-38, 21), Pair(-103, 16), Pair(-112, -1), Pair(-144, -5), Pair(-20, 18), Pair(58, -24), Pair(-144, -6),
        Pair(9, -23), Pair(21, 3), Pair(-51, 88), Pair(-90, 45), Pair(-28, 7), Pair(-17, 0), Pair(33, 45), Pair(-38, -45),
        Pair(-26, 23), Pair(-59, 28), Pair(-2, -21), Pair(42, 29), Pair(-23, -8), Pair(47, -6), Pair(-57, 17), Pair(-99, -22),
        Pair(0, -25), Pair(13, 38), Pair(-106, -59), Pair(-24, -56), Pair(-10, -21), Pair(-2, 49), Pair(-35, -28), Pair(-28, 56),
        Pair(-56, -68), Pair(-26, 74), Pair(-48, 89), Pair(-31, 6), Pair(-44, 35), Pair(-109, 57), Pair(-14, -4), Pair(-58, -31),
        Pair(-48, -26), Pair(-20, 30), Pair(-26, -31), Pair(-91, 35), Pair(-67, 20), Pair(-70, -20), Pair(-7, 34), Pair(-10, -22)
      },
      { // Piece 3
        Pair(-6, -62), Pair(-56, -91), Pair(-96, -56), Pair(25, -81), Pair(92, -61), Pair(-1, -78), Pair(-4, -106), Pair(55, -108),
        Pair(40, -93), Pair(48, -140), Pair(24, -134), Pair(-7, -74), Pair(15, -80), Pair(-82, -61), Pair(-77, -61), Pair(-52, -52),
        Pair(-46, -112), Pair(28, -126), Pair(-40, -122), Pair(66, -109), Pair(145, -147), Pair(51, -114), Pair(4, -146), Pair(65, -149),
        Pair(14, -123), Pair(56, -74), Pair(74, -108), Pair(-23, -105), Pair(39, -99), Pair(166, -141), Pair(27, -96), Pair(-11, -79),
        Pair(-92, -96), Pair(18, -118), Pair(-98, -57), Pair(-35, -63), Pair(31, -95), Pair(70, -87), Pair(33, -86), Pair(-18, -84),
        Pair(-51, -62), Pair(-43, -77), Pair(119, -151), Pair(21, -120), Pair(101, -86), Pair(42, -111), Pair(-30, -121), Pair(-20, -84),
        Pair(15, -78), Pair(54, -167), Pair(-52, -67), Pair(38, -174), Pair(-29, -172), Pair(43, -145), Pair(-58, -146), Pair(37, -110),
        Pair(-69, -123), Pair(125, -180), Pair(20, -71), Pair(-20, -129), Pair(46, -188), Pair(46, -180), Pair(79, -66), Pair(100, -190)
      },
      { // Piece 4
        Pair(-64, -141), Pair(45, -114), Pair(-96, -149), Pair(-87, -199), Pair(-193, -73), Pair(-66, -152), Pair(-163, -212), Pair(-150, -173),
        Pair(-117, -180), Pair(-40, -87), Pair(-21, -19), Pair(-44, -94), Pair(13, 5), Pair(-59, -113), Pair(-70, -127), Pair(-29, -112),
        Pair(-46, -120), Pair(-36, -221), Pair(-29, -96), Pair(-58, -140), Pair(-28, -66), Pair(-45, -182), Pair(-55, -104), Pair(41, -57),
        Pair(-110, -172), Pair(-63, -143), Pair(-43, -133), Pair(-30, -38), Pair(-21, -95), Pair(-33, -50), Pair(-34, -57), Pair(-24, -54),
        Pair(-62, -97), Pair(0, -39), Pair(-51, -70), Pair(44, 62), Pair(35, -26), Pair(-36, -47), Pair(-8, -57), Pair(-74, -152),
        Pair(-46, -100), Pair(-54, -161), Pair(29, -50), Pair(26, -46), Pair(31, 6), Pair(-16, -33), Pair(-69, -95), Pair(-24, -26),
        Pair(-93, -220), Pair(-94, -162), Pair(-56, -102), Pair(21, 23), Pair(-48, -31), Pair(9, -26), Pair(-15, -74), Pair(-10, -79),
        Pair(1, -29), Pair(-63, -174), Pair(-12, -84), Pair(-33, -31), Pair(-1, -20), Pair(-43, -143), Pair(-26, -134), Pair(-17, -86)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-32, 41), Pair(14, 27), Pair(-149, 39), Pair(-99, 53), Pair(10, 52), Pair(-1, 47), Pair(34, 27), Pair(-73, 19),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }}
  }},
  {{ // Bucket 4
    {{ // Bucket 0
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(244, 103), Pair(294, 128), Pair(210, 248), Pair(165, 191), Pair(33, 193), Pair(103, 115), Pair(59, 4), Pair(44, 8),
        Pair(71, 91), Pair(104, 117), Pair(75, 148), Pair(69, 130), Pair(84, 109), Pair(158, 32), Pair(144, 47), Pair(32, 59),
        Pair(-28, 37), Pair(12, 24), Pair(4, 31), Pair(58, 7), Pair(54, -14), Pair(109, -18), Pair(59, -3), Pair(-54, 4),
        Pair(-61, 20), Pair(-75, 26), Pair(2, -17), Pair(-2, -10), Pair(35, -30), Pair(55, -28), Pair(15, -26), Pair(-44, -32),
        Pair(-26, -13), Pair(-37, -1), Pair(9, -27), Pair(-4, -11), Pair(-11, -21), Pair(9, -27), Pair(-11, -10), Pair(-113, -3),
        Pair(-71, 0), Pair(-67, 14), Pair(7, -32), Pair(2, -27), Pair(-98, 1), Pair(-45, -5), Pair(-28, -7), Pair(-128, -11),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-174, -46), Pair(-53, -48), Pair(-157, 76), Pair(64, 14), Pair(16, 41), Pair(-11, -52), Pair(-54, -175), Pair(-30, -38),
        Pair(-157, -11), Pair(-141, 71), Pair(74, 5), Pair(62, 80), Pair(96, 53), Pair(24, 6), Pair(6, 82), Pair(85, -25),
        Pair(-81, -25), Pair(30, 30), Pair(95, 22), Pair(96, 50), Pair(188, 24), Pair(117, 43), Pair(69, 32), Pair(72, -20),
        Pair(6, 27), Pair(27, 32), Pair(45, 48), Pair(137, 60), Pair(119, 64), Pair(157, 38), Pair(130, 48), Pair(155, 1),
        Pair(-61, -17), Pair(2, 8), Pair(26, 62), Pair(73, 20), Pair(70, 54), Pair(40, 35), Pair(45, 49), Pair(86, -74),
        Pair(-83, -58), Pair(-68, 13), Pair(-58, 51), Pair(41, 34), Pair(-1, 34), Pair(43, 26), Pair(23, -9), Pair(-52, -23),
        Pair(-126, -112), Pair(-156, 8), Pair(97, -52), Pair(-82, 31), Pair(-78, 48), Pair(43, 2), Pair(16, -53), Pair(12, -33),
        Pair(-37, -84), Pair(-155, -60), Pair(-191, -35), Pair(-59, 15), Pair(-31, 14), Pair(-192, -19), Pair(-150, -49), Pair(-58, -99)
      },
      { // Piece 2
        Pair(-224, 42), Pair(-5, -23), Pair(-43, 33), Pair(-59, -1), Pair(-50, -9), Pair(41, -33), Pair(-11, -2), Pair(38, 29),
        Pair(40, 21), Pair(-116, 30), Pair(63, -3), Pair(-52, 41), Pair(-1, 10), Pair(94, -23), Pair(-114, 43), Pair(-169, 48),
        Pair(-88, 64), Pair(-44, 34), Pair(79, -4), Pair(45, 5), Pair(48, 33), Pair(112, 28), Pair(157, -6), Pair(39, 20),
        Pair(-111, 28), Pair(48, 21), Pair(49, 1), Pair(135, 5), Pair(91, 17), Pair(73, 20), Pair(59, 4), Pair(-56, 31),
        Pair(-21, 12), Pair(9, 8), Pair(22, 25), Pair(68, 10), Pair(123, 0), Pair(6, -5), Pair(-3, 7), Pair(-36, -19),
        Pair(-89, -19), Pair(64, -17), Pair(-26, 37), Pair(11, 16), Pair(12, 4), Pair(6, -15), Pair(-48, -4), Pair(-83, -71),
        Pair(43, -7), Pair(-45, -27), Pair(-55, 30), Pair(-42, -21), Pair(-31, -21), Pair(-58, -11), Pair(-27, -43), Pair(154, -125),
        Pair(-122, -12), Pair(-80, 12), Pair(-66, -42), Pair(-31, -65), Pair(-87, 1), Pair(-112, -7), Pair(55, -44), Pair(-4, 31)
      },
      { // Piece 3
        Pair(33, 75), Pair(-88, 96), Pair(31, 98), Pair(46, 78), Pair(102, 40), Pair(-10, 43), Pair(-3, 79), Pair(-32, 82),
        Pair(-14, 63), Pair(71, 29), Pair(-4, 59), Pair(99, 33), Pair(99, 12), Pair(73, 23), Pair(155, 26), Pair(124, 29),
        Pair(-82, 52), Pair(-44, 39), Pair(-1, 33), Pair(55, 28), Pair(115, -4), Pair(51, 32), Pair(6, 26), Pair(70, 3),
        Pair(-90, 34), Pair(-29, 39), Pair(-5, 56), Pair(-7, 36), Pair(34, 11), Pair(24, 9), Pair(-9, 21), Pair(-92, 44),
        Pair(-117, 24), Pair(-44, 23), Pair(18, -20), Pair(-107, 42), Pair(11, -20), Pair(43, -14), Pair(-119, -31), Pair(-111, 24),
        Pair(-147, 22), Pair(-68, 7), Pair(-137, 39), Pair(-65, 9), Pair(-106, 12), Pair(-26, -35), Pair(-27, -6), Pair(-63, 28),
        Pair(-130, -7), Pair(-259, 70), Pair(-25, -28), Pair(-109, 9), Pair(-58, -17), Pair(-39, -28), Pair(-83, -19), Pair(-178, 44),
        Pair(-127, 12), Pair(-132, 20), Pair(-96, 31), Pair(-66, 5), Pair(-30, -28), Pair(-62, -14), Pair(-91, 11), Pair(-50, -41)
      },
      { // Piece 4
        Pair(-80, -58), Pair(-102, 58), Pair(55, -36), Pair(72, -72), Pair(-7, 16), Pair(50, 28), Pair(-36, -8), Pair(-4, 7),
        Pair(-154, -24), Pair(-66, 68), Pair(-92, -17), Pair(-226, 142), Pair(-127, 143), Pair(-55, 76), Pair(44, 36), Pair(-87, 151),
        Pair(-116, -45), Pair(-214, 92), Pair(110, -78), Pair(-142, 84), Pair(-20, 23), Pair(83, 18), Pair(-11, 55), Pair(61, -26),
        Pair(-213, -6), Pair(-159, 35), Pair(-158, 35), Pair(-84, 44), Pair(-78, 84), Pair(11, 57), Pair(-30, -19), Pair(49, -53),
        Pair(-194, -103), Pair(-152, -9), Pair(-177, 11), Pair(-89, 33), Pair(5, -44), Pair(-117, 72), Pair(-126, -46), Pair(20, -172),
        Pair(-236, -86), Pair(-141, -109), Pair(-132, -30), Pair(-165, 23), Pair(-74, -96), Pair(-77, -63), Pair(-89, -160), Pair(-55, -76),
        Pair(-302, -7), Pair(-192, -107), Pair(-169, -64), Pair(-175, -34), Pair(-111, -56), Pair(-87, -149), Pair(-177, -23), Pair(-166, -70),
        Pair(-260, -39), Pair(-66, -151), Pair(-152, -86), Pair(-137, -138), Pair(-125, -152), Pair(-172, -33), Pair(-153, -32), Pair(-103, -79)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-31, -40), Pair(26, -8), Pair(-5, 11), Pair(-128, 45), Pair(-79, 27), Pair(-72, 20), Pair(-11, -11), Pair(-59, -44),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 1
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(51, 277), Pair(146, 218), Pair(392, 18), Pair(272, 8), Pair(180, -18), Pair(240, -40), Pair(92, 196), Pair(-25, 197),
        Pair(5, 145), Pair(128, 117), Pair(176, 69), Pair(73, 90), Pair(100, 80), Pair(162, 57), Pair(191, 42), Pair(110, 83),
        Pair(-114, 75), Pair(13, 39), Pair(-5, 43), Pair(25, 29), Pair(63, -5), Pair(61, 6), Pair(44, 6), Pair(-40, -8),
        Pair(-145, 34), Pair(-39, 16), Pair(-12, -7), Pair(16, -12), Pair(50, -14), Pair(38, -22), Pair(0, -11), Pair(-99, -3),
        Pair(-148, 17), Pair(-29, -3), Pair(-30, -6), Pair(-31, -8), Pair(-5, -20), Pair(-53, -7), Pair(-14, -12), Pair(-72, -9),
        Pair(-136, 42), Pair(-75, 19), Pair(-66, 0), Pair(-110, -13), Pair(30, -14), Pair(-81, 4), Pair(-72, 5), Pair(-70, -2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-177, -63), Pair(-10, -69), Pair(64, -16), Pair(-18, 25), Pair(27, -11), Pair(-39, -38), Pair(50, -5), Pair(-313, -154),
        Pair(-56, 29), Pair(-49, 55), Pair(57, 36), Pair(-52, 20), Pair(1, -1), Pair(5, 35), Pair(77, -13), Pair(3, -4),
        Pair(81, 7), Pair(-38, 44), Pair(85, 59), Pair(75, 55), Pair(172, 39), Pair(201, 34), Pair(123, 25), Pair(119, -32),
        Pair(22, 24), Pair(38, 42), Pair(11, 49), Pair(96, 36), Pair(106, 57), Pair(114, 63), Pair(99, 8), Pair(116, -13),
        Pair(-81, 38), Pair(-68, 29), Pair(-13, 34), Pair(64, 44), Pair(31, 31), Pair(6, 46), Pair(58, 29), Pair(12, -38),
        Pair(-145, -29), Pair(-150, 75), Pair(-17, 18), Pair(-19, 20), Pair(-16, 38), Pair(6, 9), Pair(-62, 15), Pair(-116, -54),
        Pair(-62, -67), Pair(18, 22), Pair(-67, -19), Pair(-46, 1), Pair(-80, 19), Pair(-20, 0), Pair(8, 9), Pair(-69, -1),
        Pair(-57, -19), Pair(-233, -49), Pair(-145, 0), Pair(20, -9), Pair(-171, 6), Pair(8, -24), Pair(-29, -53), Pair(-61, -47)
      },
      { // Piece 2
        Pair(96, -37), Pair(-104, -26), Pair(-33, -57), Pair(-11, -18), Pair(47, -15), Pair(-7, -19), Pair(-101, -10), Pair(130, -53),
        Pair(-59, 4), Pair(70, -60), Pair(-49, -5), Pair(-87, 1), Pair(-2, -66), Pair(124, -42), Pair(53, 7), Pair(107, -52),
        Pair(-13, -20), Pair(34, -25), Pair(91, 6), Pair(124, -35), Pair(181, -15), Pair(117, 15), Pair(137, -16), Pair(-18, 2),
        Pair(-37, -8), Pair(53, 4), Pair(67, -9), Pair(111, 3), Pair(89, 34), Pair(116, -12), Pair(75, -7), Pair(-14, -9),
        Pair(-4, 7), Pair(120, -69), Pair(61, -15), Pair(63, -4), Pair(162, -33), Pair(83, -8), Pair(148, -39), Pair(-44, 15),
        Pair(-24, 37), Pair(-27, 10), Pair(95, -25), Pair(47, -18), Pair(73, -34), Pair(-19, -12), Pair(111, -82), Pair(-112, 51),
        Pair(-191, 59), Pair(-5, -48), Pair(4, -29), Pair(-59, -26), Pair(-38, -15), Pair(-47, -13), Pair(0, -47), Pair(60, -10),
        Pair(6, -51), Pair(-37, -5), Pair(-50, -50), Pair(-67, -14), Pair(-23, -84), Pair(-76, -26), Pair(-101, -36), Pair(-60, -60)
      },
      { // Piece 3
        Pair(10, 62), Pair(32, 49), Pair(4, 45), Pair(122, 21), Pair(25, 68), Pair(14, 9), Pair(47, -22), Pair(37, 27),
        Pair(80, 22), Pair(103, 13), Pair(122, -8), Pair(176, -30), Pair(229, -27), Pair(30, 21), Pair(72, 15), Pair(136, -11),
        Pair(143, -12), Pair(125, -10), Pair(92, -2), Pair(97, 11), Pair(47, -2), Pair(128, -30), Pair(32, 14), Pair(53, -9),
        Pair(-26, -5), Pair(-48, 14), Pair(-62, 8), Pair(94, -2), Pair(43, -1), Pair(18, -11), Pair(-21, 13), Pair(-66, 16),
        Pair(-41, -29), Pair(-126, 14), Pair(-4, -13), Pair(-53, 8), Pair(-85, 13), Pair(-158, 40), Pair(-54, -11), Pair(-81, -51),
        Pair(-81, -38), Pair(-15, -27), Pair(-152, 11), Pair(-97, -16), Pair(-88, -7), Pair(-13, -61), Pair(-163, 23), Pair(-104, 2),
        Pair(-111, -37), Pair(-84, -11), Pair(-28, -57), Pair(-149, 35), Pair(-89, -17), Pair(-68, -39), Pair(-76, -25), Pair(-65, 12),
        Pair(-105, -34), Pair(-88, -37), Pair(-29, -29), Pair(-143, 10), Pair(-1, -59), Pair(-44, -43), Pair(-51, -6), Pair(-55, -37)
      },
      { // Piece 4
        Pair(-193, 89), Pair(-95, -8), Pair(-64, -42), Pair(54, 59), Pair(12, 21), Pair(72, 131), Pair(-27, -15), Pair(19, 15),
        Pair(-57, -57), Pair(1, -5), Pair(-114, 148), Pair(8, 26), Pair(-32, 14), Pair(-10, -26), Pair(48, 20), Pair(146, -130),
        Pair(17, -70), Pair(-67, 17), Pair(88, -71), Pair(-89, 147), Pair(262, -79), Pair(107, 1), Pair(-73, 26), Pair(60, -37),
        Pair(15, -81), Pair(-104, 25), Pair(-108, -27), Pair(-3, 53), Pair(-3, 64), Pair(-50, 12), Pair(72, -44), Pair(60, -107),
        Pair(-256, 35), Pair(-70, -11), Pair(-142, -10), Pair(14, 6), Pair(-85, 12), Pair(-45, 20), Pair(64, -86), Pair(-56, -113),
        Pair(-140, -58), Pair(-116, -15), Pair(-173, -71), Pair(-46, -124), Pair(-64, -17), Pair(-33, -50), Pair(-128, 11), Pair(-71, -76),
        Pair(-61, -87), Pair(-103, -50), Pair(-93, -120), Pair(-103, -112), Pair(-69, -96), Pair(-219, -29), Pair(-200, -14), Pair(-107, -166),
        Pair(-141, -139), Pair(-149, -71), Pair(-123, -77), Pair(-84, -119), Pair(-119, -45), Pair(-33, -48), Pair(-103, -168), Pair(34, -59)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(26, -54), Pair(8, 5), Pair(13, 20), Pair(-42, 29), Pair(-31, 18), Pair(-16, 8), Pair(21, -12), Pair(-72, -34),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 2
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(261, 111), Pair(274, 84), Pair(172, 94), Pair(188, 84), Pair(123, 78), Pair(135, 57), Pair(227, 46), Pair(339, 72),
        Pair(112, 82), Pair(134, 77), Pair(149, 65), Pair(191, 36), Pair(106, 30), Pair(145, 16), Pair(82, 40), Pair(-1, 72),
        Pair(-70, 44), Pair(10, 23), Pair(56, 10), Pair(27, 8), Pair(56, -8), Pair(35, -5), Pair(38, -2), Pair(-32, -8),
        Pair(-96, 22), Pair(-38, 15), Pair(-18, -9), Pair(12, -10), Pair(-1, -13), Pair(27, -24), Pair(11, -10), Pair(-97, -7),
        Pair(-99, 12), Pair(-52, 5), Pair(-32, -12), Pair(7, -24), Pair(9, -21), Pair(10, -27), Pair(-29, -4), Pair(-78, -13),
        Pair(-117, 28), Pair(-72, 14), Pair(-19, -18), Pair(-29, -12), Pair(-12, -21), Pair(-42, -11), Pair(-45, -2), Pair(-112, -1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-51, -147), Pair(6, -14), Pair(-47, 22), Pair(-40, -22), Pair(143, -28), Pair(66, -28), Pair(-1, 1), Pair(-135, -124),
        Pair(-18, -45), Pair(-20, -12), Pair(-46, 22), Pair(112, 5), Pair(109, 5), Pair(43, 0), Pair(-139, 33), Pair(54, -41),
        Pair(-84, -14), Pair(28, 6), Pair(79, 34), Pair(62, 43), Pair(125, 25), Pair(161, 35), Pair(83, 20), Pair(30, 23),
        Pair(-53, 2), Pair(118, -7), Pair(137, 28), Pair(152, 19), Pair(98, 47), Pair(114, 36), Pair(85, 27), Pair(85, -9),
        Pair(-62, 6), Pair(21, 19), Pair(97, 21), Pair(104, 33), Pair(89, 26), Pair(120, 21), Pair(39, 23), Pair(27, -31),
        Pair(-189, -32), Pair(-20, 2), Pair(2, 6), Pair(59, 14), Pair(25, 22), Pair(46, 8), Pair(-11, 10), Pair(-43, 1),
        Pair(-53, -46), Pair(-82, 20), Pair(-29, -23), Pair(2, -19), Pair(-33, 8), Pair(-71, -14), Pair(-31, -48), Pair(-101, -53),
        Pair(-89, -73), Pair(-239, -15), Pair(-150, -17), Pair(-128, -15), Pair(-156, -18), Pair(-146, -19), Pair(-154, -30), Pair(-108, 3)
      },
      { // Piece 2
        Pair(-45, -42), Pair(-38, -29), Pair(2, -46), Pair(-45, -19), Pair(68, -26), Pair(-43, -3), Pair(103, -57), Pair(-29, 11),
        Pair(-70, -39), Pair(70, -37), Pair(43, -25), Pair(-4, -15), Pair(46, -27), Pair(156, -43), Pair(51, -28), Pair(49, -35),
        Pair(25, -39), Pair(10, -37), Pair(102, -26), Pair(82, -20), Pair(217, -59), Pair(175, -17), Pair(67, -22), Pair(3, -18),
        Pair(-29, -40), Pair(39, -17), Pair(76, -21), Pair(181, -31), Pair(112, -12), Pair(129, -32), Pair(122, -21), Pair(43, -30),
        Pair(-49, -28), Pair(43, -19), Pair(100, -24), Pair(62, -15), Pair(68, -14), Pair(79, -23), Pair(45, -20), Pair(84, -62),
        Pair(-62, -24), Pair(30, -37), Pair(28, -18), Pair(54, -33), Pair(-10, -14), Pair(22, -31), Pair(-30, -21), Pair(-22, -41),
        Pair(-11, -38), Pair(-40, -40), Pair(15, -40), Pair(-6, -43), Pair(26, -54), Pair(-55, -47), Pair(-15, -50), Pair(-36, -80),
        Pair(-89, -65), Pair(-81, -31), Pair(-111, -52), Pair(-58, -42), Pair(-18, -47), Pair(-54, -65), Pair(-25, -80), Pair(24, -87)
      },
      { // Piece 3
        Pair(8, -1), Pair(51, -8), Pair(12, 7), Pair(57, -10), Pair(32, -4), Pair(114, -25), Pair(100, -34), Pair(179, -47),
        Pair(-8, -2), Pair(-15, 3), Pair(42, -8), Pair(61, -17), Pair(80, -29), Pair(-77, 30), Pair(43, -17), Pair(13, 2),
        Pair(36, -23), Pair(88, -35), Pair(117, -43), Pair(109, -44), Pair(119, -53), Pair(150, -45), Pair(119, -54), Pair(29, -13),
        Pair(-50, -11), Pair(-8, -18), Pair(-31, -2), Pair(9, -18), Pair(-6, -6), Pair(63, -29), Pair(124, -48), Pair(-43, -10),
        Pair(-69, -34), Pair(-108, -4), Pair(-34, -30), Pair(-113, -1), Pair(-33, -15), Pair(-19, -37), Pair(-52, -16), Pair(-86, -33),
        Pair(-139, -32), Pair(-117, -29), Pair(-156, -10), Pair(-124, -23), Pair(-81, -30), Pair(-72, -40), Pair(-100, -27), Pair(-150, -17),
        Pair(-231, -17), Pair(-133, -37), Pair(-111, -36), Pair(-60, -56), Pair(-106, -32), Pair(-99, -50), Pair(-104, -15), Pair(-112, -51),
        Pair(-102, -47), Pair(-100, -36), Pair(-103, -34), Pair(-65, -47), Pair(-42, -59), Pair(-57, -45), Pair(-106, -32), Pair(-105, -43)
      },
      { // Piece 4
        Pair(-60, -77), Pair(28, -88), Pair(-93, -23), Pair(-31, -49), Pair(-6, -29), Pair(-7, -18), Pair(13, -53), Pair(-185, 14),
        Pair(-112, -120), Pair(-80, -111), Pair(-128, -52), Pair(-141, -66), Pair(-8, -54), Pair(-101, -13), Pair(-143, 54), Pair(-31, -117),
        Pair(-77, -163), Pair(-128, -107), Pair(-85, -41), Pair(-79, -20), Pair(2, -12), Pair(20, -15), Pair(-72, -48), Pair(24, -64),
        Pair(-196, -105), Pair(-96, -76), Pair(-109, 1), Pair(-46, -22), Pair(76, -71), Pair(-10, -4), Pair(43, -62), Pair(153, -138),
        Pair(-124, -117), Pair(-144, -92), Pair(-262, -2), Pair(-94, -23), Pair(-57, -59), Pair(-61, -41), Pair(55, -112), Pair(-19, -112),
        Pair(-220, -127), Pair(-257, 11), Pair(-146, -63), Pair(-207, -51), Pair(-165, -31), Pair(-148, -92), Pair(-240, -21), Pair(-30, -181),
        Pair(-182, -175), Pair(-204, -100), Pair(-92, -161), Pair(-177, -81), Pair(-135, -151), Pair(-143, -130), Pair(-207, -127), Pair(-164, -75),
        Pair(-88, -228), Pair(-105, -261), Pair(-130, -191), Pair(-141, -157), Pair(-289, -89), Pair(-251, -101), Pair(-204, -160), Pair(-161, -145)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-18, -49), Pair(44, -16), Pair(7, 8), Pair(-72, 25), Pair(-55, 20), Pair(-18, 7), Pair(30, -16), Pair(-66, -38),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 3
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(246, 124), Pair(170, 133), Pair(151, 139), Pair(208, 79), Pair(196, 98), Pair(115, 123), Pair(157, 145), Pair(115, 151),
        Pair(56, 75), Pair(155, 54), Pair(135, 44), Pair(141, 27), Pair(89, 37), Pair(167, 8), Pair(165, 34), Pair(106, 54),
        Pair(-55, 33), Pair(9, 15), Pair(42, -5), Pair(67, -26), Pair(30, -25), Pair(69, -34), Pair(17, -9), Pair(-47, -8),
        Pair(-100, 19), Pair(-65, 22), Pair(-45, -5), Pair(-3, -12), Pair(-23, -8), Pair(19, -22), Pair(-27, 0), Pair(-97, -6),
        Pair(-123, 12), Pair(-64, 6), Pair(-47, -11), Pair(-16, -15), Pair(-7, -16), Pair(-6, -24), Pair(-12, -7), Pair(-84, -9),
        Pair(-131, 29), Pair(-85, 18), Pair(-57, -5), Pair(-21, -13), Pair(-31, -18), Pair(-72, -5), Pair(-78, 8), Pair(-158, 15),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-208, -118), Pair(2, -46), Pair(-175, 12), Pair(-78, -9), Pair(-34, 9), Pair(22, -5), Pair(-20, -52), Pair(-78, -114),
        Pair(-46, -15), Pair(-17, -7), Pair(16, 20), Pair(18, 25), Pair(172, 0), Pair(-70, 20), Pair(-76, -12), Pair(21, -3),
        Pair(37, -42), Pair(-27, 3), Pair(39, 34), Pair(89, 24), Pair(51, 17), Pair(166, 13), Pair(34, -1), Pair(-24, -13),
        Pair(71, -19), Pair(64, 12), Pair(97, 24), Pair(137, 23), Pair(128, 28), Pair(162, 22), Pair(146, -2), Pair(108, -35),
        Pair(-12, -39), Pair(5, 5), Pair(84, 11), Pair(66, 25), Pair(79, 13), Pair(93, 18), Pair(15, 13), Pair(-27, 2),
        Pair(-7, -69), Pair(-57, 4), Pair(18, -2), Pair(32, 22), Pair(-25, 30), Pair(58, 8), Pair(-35, 18), Pair(-31, -28),
        Pair(-101, -42), Pair(-60, -37), Pair(-93, -13), Pair(39, -15), Pair(-54, 29), Pair(-44, -28), Pair(-84, -25), Pair(71, -77),
        Pair(-111, -113), Pair(-173, -64), Pair(-118, -16), Pair(-27, -20), Pair(-59, -29), Pair(-114, -30), Pair(-206, -20), Pair(-16, -113)
      },
      { // Piece 2
        Pair(61, -71), Pair(76, -42), Pair(42, -49), Pair(-11, -31), Pair(-74, -28), Pair(-4, -19), Pair(13, -35), Pair(-91, -42),
        Pair(19, -50), Pair(89, -49), Pair(61, -45), Pair(38, -41), Pair(28, -40), Pair(1, -41), Pair(74, -37), Pair(-94, -29),
        Pair(12, -29), Pair(114, -41), Pair(86, -27), Pair(120, -45), Pair(169, -62), Pair(134, -44), Pair(109, -36), Pair(54, -63),
        Pair(-41, -22), Pair(57, -25), Pair(50, -25), Pair(176, -54), Pair(186, -40), Pair(135, -38), Pair(75, -40), Pair(18, -48),
        Pair(-16, -53), Pair(35, -29), Pair(53, -30), Pair(108, -36), Pair(75, -33), Pair(19, -23), Pair(-24, -20), Pair(-39, -48),
        Pair(-45, -50), Pair(0, -31), Pair(-32, -18), Pair(20, -24), Pair(4, -28), Pair(-4, -28), Pair(58, -54), Pair(-53, -51),
        Pair(-44, -57), Pair(-68, -44), Pair(0, -41), Pair(-16, -32), Pair(-62, -31), Pair(-10, -54), Pair(-13, -49), Pair(-123, -73),
        Pair(-138, -23), Pair(-22, -59), Pair(-56, -56), Pair(-45, -58), Pair(-50, -54), Pair(-142, -53), Pair(-34, -56), Pair(-11, -80)
      },
      { // Piece 3
        Pair(0, -32), Pair(54, -37), Pair(53, -28), Pair(34, -33), Pair(42, -32), Pair(185, -66), Pair(126, -51), Pair(122, -49),
        Pair(29, -43), Pair(42, -43), Pair(96, -55), Pair(73, -44), Pair(22, -28), Pair(103, -56), Pair(91, -58), Pair(104, -59),
        Pair(1, -24), Pair(92, -60), Pair(8, -45), Pair(94, -51), Pair(61, -56), Pair(74, -50), Pair(75, -64), Pair(-72, -21),
        Pair(-30, -32), Pair(1, -35), Pair(25, -33), Pair(49, -44), Pair(80, -55), Pair(134, -53), Pair(124, -68), Pair(48, -48),
        Pair(-69, -61), Pair(-13, -48), Pair(-11, -54), Pair(-41, -33), Pair(7, -49), Pair(-12, -48), Pair(62, -45), Pair(-86, -57),
        Pair(-164, -57), Pair(-114, -52), Pair(-104, -54), Pair(-98, -48), Pair(-72, -54), Pair(-126, -49), Pair(-140, -44), Pair(-101, -43),
        Pair(-157, -55), Pair(-64, -66), Pair(-74, -68), Pair(-83, -65), Pair(-29, -65), Pair(-73, -65), Pair(-77, -78), Pair(-232, -25),
        Pair(-97, -67), Pair(-90, -68), Pair(-67, -56), Pair(-31, -80), Pair(-56, -68), Pair(-87, -64), Pair(-77, -56), Pair(-139, -29)
      },
      { // Piece 4
        Pair(-46, -133), Pair(-117, -47), Pair(-83, -62), Pair(-22, -59), Pair(-16, 31), Pair(-48, 3), Pair(11, -86), Pair(-7, -52),
        Pair(-61, -112), Pair(-61, -114), Pair(-184, -5), Pair(-23, 31), Pair(106, -41), Pair(25, -21), Pair(-76, -51), Pair(-85, -97),
        Pair(-52, -74), Pair(-6, -78), Pair(-108, -58), Pair(-39, -80), Pair(-8, -89), Pair(57, -16), Pair(-27, -63), Pair(-3, -51),
        Pair(-67, -53), Pair(-132, -22), Pair(-70, -74), Pair(-6, -67), Pair(-18, -107), Pair(-37, 13), Pair(-34, 16), Pair(-6, -80),
        Pair(-114, -143), Pair(-11, -104), Pair(9, -105), Pair(-70, 22), Pair(-18, -54), Pair(-31, -5), Pair(-2, -98), Pair(-68, -115),
        Pair(-91, -220), Pair(-127, -157), Pair(-73, -54), Pair(-30, -93), Pair(-118, -66), Pair(-94, -73), Pair(-167, -52), Pair(-94, -120),
        Pair(-142, -192), Pair(-144, -95), Pair(-43, -93), Pair(-136, -96), Pair(-97, -60), Pair(-78, -93), Pair(-8, -94), Pair(-127, -148),
        Pair(-33, -210), Pair(-101, -199), Pair(-115, -14), Pair(-115, -91), Pair(-64, -142), Pair(-91, -146), Pair(-80, -122), Pair(-104, -133)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(9, -66), Pair(69, -34), Pair(33, -3), Pair(-31, 14), Pair(-39, 13), Pair(-5, 1), Pair(-5, -13), Pair(-38, -47),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 4
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(73, 159), Pair(240, 95), Pair(147, 145), Pair(114, 134), Pair(126, 147), Pair(-11, 132), Pair(-2, 140), Pair(49, 162),
        Pair(76, 92), Pair(120, 89), Pair(112, 87), Pair(95, 71), Pair(68, 66), Pair(87, 80), Pair(31, 118), Pair(9, 112),
        Pair(-43, 24), Pair(56, -3), Pair(16, -3), Pair(18, -11), Pair(20, -22), Pair(134, -36), Pair(37, 0), Pair(16, -16),
        Pair(-84, -1), Pair(-46, 5), Pair(20, -26), Pair(-16, -32), Pair(32, -50), Pair(16, -30), Pair(-20, -8), Pair(-125, -10),
        Pair(-143, 7), Pair(-46, 0), Pair(-114, -6), Pair(34, -26), Pair(-26, -23), Pair(-18, -26), Pair(-3, -8), Pair(-123, -6),
        Pair(-166, 22), Pair(-130, 22), Pair(-96, 1), Pair(-51, 2), Pair(-70, -2), Pair(-90, 0), Pair(-64, 11), Pair(-79, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-96, -180), Pair(-16, -92), Pair(57, -54), Pair(35, -56), Pair(5, -59), Pair(-69, -55), Pair(-74, -55), Pair(-66, -116),
        Pair(-105, -79), Pair(-52, -71), Pair(-14, -25), Pair(68, -66), Pair(10, -8), Pair(56, -45), Pair(49, -75), Pair(-104, -121),
        Pair(9, -56), Pair(112, -28), Pair(96, -21), Pair(27, -7), Pair(61, -28), Pair(-10, -34), Pair(123, -60), Pair(40, -91),
        Pair(12, -68), Pair(151, -60), Pair(59, -34), Pair(53, -18), Pair(131, -24), Pair(91, -29), Pair(103, -54), Pair(31, -73),
        Pair(-38, -99), Pair(53, -35), Pair(25, -33), Pair(84, -28), Pair(75, -45), Pair(21, -36), Pair(117, -35), Pair(116, -110),
        Pair(-127, -68), Pair(-3, -60), Pair(47, -46), Pair(12, -7), Pair(27, -41), Pair(63, -48), Pair(-45, -26), Pair(36, -75),
        Pair(-71, -83), Pair(-8, -68), Pair(-102, -54), Pair(15, -57), Pair(-8, -31), Pair(12, -49), Pair(-20, -84), Pair(-19, -84),
        Pair(-52, -113), Pair(-87, -105), Pair(-56, -94), Pair(-14, -74), Pair(13, -60), Pair(-30, -81), Pair(-6, -97), Pair(-2, -100)
      },
      { // Piece 2
        Pair(-92, -53), Pair(-29, -40), Pair(46, -68), Pair(11, -73), Pair(-77, -62), Pair(1, -102), Pair(25, -66), Pair(-112, -75),
        Pair(-48, -80), Pair(29, -60), Pair(-102, -45), Pair(-3, -51), Pair(-56, -56), Pair(15, -62), Pair(9, -37), Pair(48, -69),
        Pair(75, -53), Pair(34, -64), Pair(18, -67), Pair(75, -63), Pair(20, -69), Pair(13, -53), Pair(62, -69), Pair(31, -95),
        Pair(-133, -59), Pair(-14, -52), Pair(48, -55), Pair(67, -59), Pair(199, -79), Pair(109, -50), Pair(87, -76), Pair(-6, -50),
        Pair(-70, -75), Pair(-21, -57), Pair(83, -73), Pair(12, -59), Pair(138, -71), Pair(68, -52), Pair(124, -72), Pair(-118, -77),
        Pair(-90, -87), Pair(37, -47), Pair(-32, -57), Pair(-13, -58), Pair(5, -55), Pair(-69, -38), Pair(9, -73), Pair(-89, -60),
        Pair(-127, -54), Pair(-112, -28), Pair(-72, -61), Pair(0, -61), Pair(50, -76), Pair(18, -54), Pair(-109, -60), Pair(-104, -76),
        Pair(-9, -55), Pair(-107, -48), Pair(-98, -43), Pair(-115, -73), Pair(-60, -80), Pair(-116, -93), Pair(29, -84), Pair(-24, -56)
      },
      { // Piece 3
        Pair(9, -91), Pair(56, -116), Pair(70, -108), Pair(149, -109), Pair(113, -89), Pair(116, -111), Pair(44, -97), Pair(45, -82),
        Pair(-95, -91), Pair(-17, -79), Pair(-8, -77), Pair(111, -98), Pair(-12, -83), Pair(44, -104), Pair(56, -108), Pair(25, -128),
        Pair(1, -86), Pair(27, -106), Pair(104, -92), Pair(34, -93), Pair(39, -101), Pair(-6, -70), Pair(35, -105), Pair(-37, -91),
        Pair(-90, -102), Pair(29, -129), Pair(13, -98), Pair(73, -95), Pair(26, -105), Pair(101, -125), Pair(67, -110), Pair(-95, -124),
        Pair(-5, -146), Pair(-77, -107), Pair(-105, -77), Pair(-3, -103), Pair(86, -100), Pair(-22, -92), Pair(38, -92), Pair(-104, -140),
        Pair(-42, -143), Pair(127, -175), Pair(-17, -135), Pair(-116, -91), Pair(-60, -99), Pair(-66, -110), Pair(17, -120), Pair(-49, -122),
        Pair(-101, -144), Pair(-153, -99), Pair(-97, -128), Pair(-27, -126), Pair(-96, -124), Pair(-60, -133), Pair(-120, -114), Pair(-69, -134),
        Pair(-129, -115), Pair(-113, -135), Pair(-25, -123), Pair(-116, -100), Pair(-37, -117), Pair(-53, -116), Pair(34, -146), Pair(-74, -105)
      },
      { // Piece 4
        Pair(32, -106), Pair(38, -151), Pair(-97, -110), Pair(-104, -84), Pair(27, -65), Pair(-83, -62), Pair(-44, -101), Pair(-88, -75),
        Pair(7, -41), Pair(-11, -100), Pair(31, -31), Pair(-40, -50), Pair(-37, -4), Pair(-63, -77), Pair(-38, -106), Pair(-43, -96),
        Pair(-85, -155), Pair(85, -58), Pair(-15, -4), Pair(0, -10), Pair(-36, -25), Pair(50, -24), Pair(-73, -53), Pair(-26, -67),
        Pair(-74, -134), Pair(-30, -52), Pair(-53, -122), Pair(-25, -56), Pair(43, 70), Pair(-10, -36), Pair(-3, -23), Pair(-48, -118),
        Pair(-98, -143), Pair(-37, -50), Pair(27, 71), Pair(-13, -42), Pair(-4, 2), Pair(2, 40), Pair(-9, -20), Pair(-40, -81),
        Pair(-107, -214), Pair(23, 20), Pair(-3, -33), Pair(-2, -94), Pair(-35, -26), Pair(-33, -31), Pair(-19, -48), Pair(-72, -86),
        Pair(-38, 0), Pair(-79, -127), Pair(-26, -70), Pair(-30, -37), Pair(-65, -105), Pair(-145, -219), Pair(-58, -76), Pair(-55, -92),
        Pair(-22, -31), Pair(-42, -133), Pair(-66, -87), Pair(19, -22), Pair(-36, -76), Pair(13, -74), Pair(-44, -97), Pair(-84, -151)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(93, -65), Pair(17, -3), Pair(47, 8), Pair(-18, 23), Pair(-42, 34), Pair(-1, 21), Pair(-23, 11), Pair(-14, -35),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 5
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-18, 176), Pair(122, 176), Pair(-30, 186), Pair(40, 151), Pair(111, 187), Pair(-41, 199), Pair(29, 194), Pair(-40, 185),
        Pair(-157, 139), Pair(-10, 141), Pair(30, 122), Pair(55, 136), Pair(19, 137), Pair(38, 123), Pair(50, 128), Pair(-114, 131),
        Pair(-107, 47), Pair(5, 30), Pair(15, 21), Pair(9, 21), Pair(21, 7), Pair(55, 2), Pair(-73, 30), Pair(-144, 32),
        Pair(-163, 21), Pair(-100, -1), Pair(-72, -12), Pair(-86, -3), Pair(-29, -22), Pair(22, -31), Pair(-61, -6), Pair(-126, -1),
        Pair(-150, 20), Pair(-111, 11), Pair(-18, -26), Pair(24, -28), Pair(-37, -29), Pair(-45, -24), Pair(-72, 0), Pair(-139, -8),
        Pair(-140, 27), Pair(-57, 14), Pair(-84, -5), Pair(3, -19), Pair(-35, -14), Pair(-121, -1), Pair(-60, 7), Pair(-174, 15),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-44, -199), Pair(-63, -126), Pair(-56, -33), Pair(-44, -116), Pair(-39, -90), Pair(-48, -70), Pair(-10, -121), Pair(-48, -174),
        Pair(-98, -137), Pair(-67, -94), Pair(8, -70), Pair(-43, -62), Pair(-34, -73), Pair(14, -100), Pair(-56, -74), Pair(-18, -105),
        Pair(15, -102), Pair(44, -54), Pair(15, -31), Pair(27, -36), Pair(31, -53), Pair(-19, -48), Pair(-1, -88), Pair(56, -115),
        Pair(-20, -81), Pair(90, -59), Pair(169, -60), Pair(112, -50), Pair(40, -36), Pair(42, -41), Pair(106, -92), Pair(48, -114),
        Pair(-32, -142), Pair(-9, -37), Pair(68, -76), Pair(114, -59), Pair(126, -91), Pair(79, -51), Pair(-6, -69), Pair(78, -130),
        Pair(2, -120), Pair(35, -78), Pair(76, -63), Pair(4, -49), Pair(68, -60), Pair(114, -85), Pair(37, -56), Pair(50, -153),
        Pair(-6, -164), Pair(50, -106), Pair(-105, -119), Pair(146, -77), Pair(-36, -68), Pair(-47, -84), Pair(-16, -113), Pair(52, -116),
        Pair(-8, -142), Pair(-49, -68), Pair(-15, -104), Pair(52, -89), Pair(11, -93), Pair(36, -124), Pair(-50, -81), Pair(18, -144)
      },
      { // Piece 2
        Pair(-43, -51), Pair(-120, -65), Pair(-1, -82), Pair(-50, -55), Pair(-101, -40), Pair(-126, -109), Pair(0, -75), Pair(-5, -86),
        Pair(-90, -79), Pair(38, -66), Pair(-24, -57), Pair(-77, -40), Pair(-99, -31), Pair(-39, -59), Pair(27, -33), Pair(-27, -39),
        Pair(-40, -70), Pair(-67, -27), Pair(-24, -59), Pair(-61, -46), Pair(-93, -51), Pair(11, -56), Pair(-43, -64), Pair(-4, -58),
        Pair(-48, -88), Pair(-41, -39), Pair(-94, -50), Pair(25, -45), Pair(-24, -26), Pair(-36, -51), Pair(-90, -33), Pair(-75, -86),
        Pair(-82, -70), Pair(-81, -68), Pair(-6, -66), Pair(12, -81), Pair(21, -78), Pair(29, -70), Pair(11, -93), Pair(-29, -78),
        Pair(42, -125), Pair(-96, -63), Pair(-24, -63), Pair(-44, -35), Pair(-49, -45), Pair(-49, -51), Pair(-136, -19), Pair(-62, -68),
        Pair(-44, -109), Pair(-81, -60), Pair(-28, -90), Pair(-74, -45), Pair(-152, -69), Pair(-39, -75), Pair(-107, -68), Pair(8, -147),
        Pair(-91, -65), Pair(-89, -52), Pair(-43, -95), Pair(-24, -84), Pair(-95, -49), Pair(-79, -109), Pair(-47, -61), Pair(23, -31)
      },
      { // Piece 3
        Pair(102, -142), Pair(15, -123), Pair(131, -139), Pair(55, -129), Pair(-12, -101), Pair(-38, -103), Pair(-17, -125), Pair(-79, -98),
        Pair(-28, -131), Pair(77, -144), Pair(80, -156), Pair(73, -136), Pair(-23, -117), Pair(6, -142), Pair(77, -149), Pair(143, -171),
        Pair(40, -125), Pair(17, -130), Pair(14, -129), Pair(57, -141), Pair(30, -116), Pair(57, -139), Pair(56, -146), Pair(38, -145),
        Pair(72, -147), Pair(45, -138), Pair(52, -141), Pair(15, -133), Pair(27, -124), Pair(129, -157), Pair(85, -161), Pair(59, -151),
        Pair(-6, -139), Pair(-99, -139), Pair(-2, -141), Pair(24, -175), Pair(46, -155), Pair(81, -133), Pair(12, -145), Pair(-37, -148),
        Pair(-37, -195), Pair(-101, -153), Pair(-23, -178), Pair(16, -162), Pair(-56, -149), Pair(-155, -129), Pair(32, -169), Pair(92, -188),
        Pair(-142, -145), Pair(33, -162), Pair(17, -164), Pair(-39, -159), Pair(18, -177), Pair(-25, -162), Pair(-39, -165), Pair(-84, -145),
        Pair(-35, -153), Pair(60, -172), Pair(-51, -143), Pair(-31, -159), Pair(6, -174), Pair(-61, -150), Pair(-48, -137), Pair(-33, -198)
      },
      { // Piece 4
        Pair(-76, -191), Pair(-91, -175), Pair(-27, -239), Pair(-20, -122), Pair(3, -168), Pair(-166, -212), Pair(-14, -175), Pair(-46, -153),
        Pair(-71, -172), Pair(-51, -68), Pair(-10, -122), Pair(-59, -51), Pair(8, -118), Pair(-104, -74), Pair(-58, -180), Pair(-115, -200),
        Pair(-143, -203), Pair(-41, -85), Pair(-34, -58), Pair(21, -74), Pair(-50, -110), Pair(7, -74), Pair(-90, -57), Pair(-39, -132),
        Pair(-96, -176), Pair(-6, -149), Pair(-72, -38), Pair(-5, -99), Pair(-1, -91), Pair(-60, -109), Pair(-91, -117), Pair(-63, -63),
        Pair(1, -40), Pair(-43, -119), Pair(-98, -70), Pair(-73, -90), Pair(-59, -62), Pair(-77, -128), Pair(-58, -126), Pair(-17, -18),
        Pair(-59, -121), Pair(-45, -151), Pair(-86, -155), Pair(-10, -24), Pair(-6, -30), Pair(-24, -79), Pair(-37, -73), Pair(-22, -75),
        Pair(12, -81), Pair(-8, -42), Pair(-55, -129), Pair(-89, -190), Pair(-57, -123), Pair(-39, -79), Pair(-65, -149), Pair(-17, -72),
        Pair(-112, -235), Pair(-24, -55), Pair(-102, -241), Pair(-34, -159), Pair(-81, -145), Pair(-14, -159), Pair(-55, -98), Pair(-54, -130)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(22, -60), Pair(-2, -5), Pair(22, 4), Pair(-86, 31), Pair(-20, 24), Pair(45, 12), Pair(8, -1), Pair(-3, -44),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 6
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-102, 216), Pair(-51, 200), Pair(6, 174), Pair(16, 176), Pair(-68, 194), Pair(-44, 174), Pair(-9, 248), Pair(-153, 201),
        Pair(-148, 171), Pair(22, 157), Pair(-15, 174), Pair(-15, 155), Pair(1, 200), Pair(-25, 151), Pair(0, 197), Pair(-87, 157),
        Pair(-68, 48), Pair(24, 43), Pair(-185, 69), Pair(-103, 57), Pair(-111, 42), Pair(50, 38), Pair(-20, 58), Pair(-151, 62),
        Pair(-80, 3), Pair(-78, 31), Pair(-30, 14), Pair(-66, -2), Pair(-1, -12), Pair(45, -3), Pair(-163, 20), Pair(-212, 13),
        Pair(-166, -5), Pair(-20, -12), Pair(-83, -11), Pair(-124, 4), Pair(-99, -12), Pair(13, 1), Pair(-118, -3), Pair(-153, 5),
        Pair(-137, 12), Pair(-144, 2), Pair(48, -32), Pair(-26, -31), Pair(-20, 25), Pair(-36, -24), Pair(-86, 6), Pair(-149, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-30, -284), Pair(-46, -148), Pair(-2, -9), Pair(12, -78), Pair(-6, -24), Pair(-22, -98), Pair(-22, -69), Pair(-3, -20),
        Pair(-5, -171), Pair(7, -129), Pair(-32, -46), Pair(-3, -47), Pair(-11, -49), Pair(-5, -131), Pair(-60, -71), Pair(-16, -125),
        Pair(-62, -124), Pair(-79, -105), Pair(63, -52), Pair(-59, -29), Pair(20, -8), Pair(89, -30), Pair(37, -95), Pair(-29, -56),
        Pair(30, -72), Pair(14, -64), Pair(54, -29), Pair(105, -19), Pair(37, 5), Pair(99, -65), Pair(8, -47), Pair(-65, -84),
        Pair(-61, -90), Pair(9, -67), Pair(1, -8), Pair(207, -84), Pair(12, -23), Pair(50, -84), Pair(11, -38), Pair(46, -30),
        Pair(-14, -128), Pair(-1, 16), Pair(-67, -16), Pair(55, -32), Pair(69, -4), Pair(13, -79), Pair(53, -9), Pair(19, -135),
        Pair(5, -46), Pair(17, -17), Pair(-29, -82), Pair(19, -88), Pair(25, -96), Pair(-25, -112), Pair(5, -60), Pair(-32, -54),
        Pair(-4, -110), Pair(-4, -100), Pair(-29, -107), Pair(9, -92), Pair(25, -57), Pair(9, -162), Pair(-37, -72), Pair(-34, -71)
      },
      { // Piece 2
        Pair(-1, -31), Pair(4, 50), Pair(-67, 6), Pair(-72, -76), Pair(4, -5), Pair(-41, -60), Pair(40, -33), Pair(-10, -21),
        Pair(12, 35), Pair(-19, 33), Pair(10, -17), Pair(-23, -51), Pair(-59, -18), Pair(17, -10), Pair(-100, -23), Pair(-47, -55),
        Pair(-36, -39), Pair(-75, -3), Pair(-124, 8), Pair(-8, 30), Pair(-60, 13), Pair(109, -33), Pair(14, -21), Pair(33, -46),
        Pair(-3, -50), Pair(23, -9), Pair(2, -35), Pair(-67, 9), Pair(-32, -30), Pair(-6, -44), Pair(-48, -24), Pair(-40, -28),
        Pair(-4, 1), Pair(-53, 20), Pair(22, -6), Pair(107, -48), Pair(-43, -20), Pair(-34, -58), Pair(35, -13), Pair(-25, 0),
        Pair(-116, -25), Pair(12, -24), Pair(36, -35), Pair(42, -60), Pair(-63, 19), Pair(-61, -27), Pair(29, 5), Pair(5, 7),
        Pair(-9, 24), Pair(11, -65), Pair(-33, 38), Pair(-28, -83), Pair(36, -71), Pair(-30, -41), Pair(39, -56), Pair(-3, -22),
        Pair(6, -35), Pair(-21, 31), Pair(-12, -86), Pair(-41, -41), Pair(20, -83), Pair(-3, -51), Pair(-3, -3), Pair(-11, -123)
      },
      { // Piece 3
        Pair(9, -97), Pair(20, -93), Pair(47, -142), Pair(-17, -79), Pair(4, -46), Pair(22, -70), Pair(18, -139), Pair(-23, -117),
        Pair(2, -153), Pair(-99, -97), Pair(23, -157), Pair(-17, -105), Pair(100, -140), Pair(42, -160), Pair(-2, -96), Pair(-11, -134),
        Pair(-36, -95), Pair(15, -108), Pair(-4, -100), Pair(-75, -79), Pair(-69, -85), Pair(-101, -68), Pair(13, -123), Pair(20, -149),
        Pair(-54, -124), Pair(63, -84), Pair(48, -109), Pair(70, -135), Pair(11, -111), Pair(69, -113), Pair(-1, -96), Pair(-45, -89),
        Pair(39, -95), Pair(-11, -129), Pair(-71, -90), Pair(17, -120), Pair(21, -80), Pair(-112, -112), Pair(-8, -91), Pair(76, -145),
        Pair(-70, -104), Pair(-87, -69), Pair(16, -87), Pair(56, -153), Pair(38, -180), Pair(60, -118), Pair(32, -104), Pair(2, -145),
        Pair(70, -106), Pair(49, -69), Pair(10, -179), Pair(60, -184), Pair(24, -114), Pair(-50, -158), Pair(13, -157), Pair(-31, -178),
        Pair(-84, -152), Pair(66, -160), Pair(-78, -114), Pair(-27, -157), Pair(-8, -210), Pair(5, -151), Pair(156, -155), Pair(-6, -110)
      },
      { // Piece 4
        Pair(-128, -103), Pair(-92, -86), Pair(-30, 27), Pair(-76, -53), Pair(-93, -100), Pair(-116, -176), Pair(-26, -184), Pair(-85, -151),
        Pair(-4, -12), Pair(24, -33), Pair(-64, -154), Pair(-75, -103), Pair(-5, 63), Pair(-81, -114), Pair(-18, -53), Pair(-101, -162),
        Pair(17, -69), Pair(-65, -172), Pair(57, 61), Pair(-47, -60), Pair(-42, -68), Pair(-32, -22), Pair(-101, -145), Pair(-64, -93),
        Pair(-21, -50), Pair(-107, -135), Pair(-35, -86), Pair(-23, -64), Pair(18, 13), Pair(-40, -72), Pair(-51, -24), Pair(-39, 12),
        Pair(-17, -83), Pair(-45, -156), Pair(-44, -115), Pair(-13, -86), Pair(-5, -62), Pair(10, -32), Pair(-74, -122), Pair(-34, -81),
        Pair(-50, -132), Pair(-38, -51), Pair(21, 30), Pair(16, -38), Pair(65, 19), Pair(-59, -56), Pair(-24, -72), Pair(1, -63),
        Pair(-1, -20), Pair(-6, -26), Pair(-29, -78), Pair(-23, -81), Pair(30, 49), Pair(-77, -147), Pair(-27, -49), Pair(-14, -41),
        Pair(-52, -129), Pair(-71, -135), Pair(-47, -113), Pair(-56, -109), Pair(-40, -61), Pair(-5, -74), Pair(10, -10), Pair(-65, -104)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-35, -3), Pair(-30, 49), Pair(47, 44), Pair(-2, 49), Pair(-28, 61), Pair(-17, 68), Pair(-5, 42), Pair(-55, -2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }}
  }},
  {{ // Bucket 5
    {{ // Bucket 0
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(330, 56), Pair(366, 67), Pair(216, 243), Pair(168, 212), Pair(-55, 243), Pair(195, 161), Pair(136, 2), Pair(46, -20),
        Pair(174, 67), Pair(190, 102), Pair(85, 164), Pair(-21, 166), Pair(77, 140), Pair(152, 47), Pair(205, 49), Pair(94, 31),
        Pair(-126, 83), Pair(-93, 84), Pair(48, 55), Pair(-52, 52), Pair(34, 5), Pair(5, 26), Pair(9, 25), Pair(-9, 1),
        Pair(-182, 57), Pair(-76, 28), Pair(-65, 10), Pair(-57, -1), Pair(-87, 8), Pair(-6, -20), Pair(-90, 10), Pair(-81, -8),
        Pair(-122, 1), Pair(-109, 8), Pair(-45, -13), Pair(-8, -30), Pair(-78, 1), Pair(-95, -2), Pair(-43, -16), Pair(-105, -19),
        Pair(-173, 16), Pair(-103, 12), Pair(-45, 1), Pair(-120, 31), Pair(-137, -26), Pair(-69, -9), Pair(-99, -6), Pair(-91, -16),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-130, -177), Pair(34, -40), Pair(77, -52), Pair(47, -79), Pair(-37, -16), Pair(-6, -42), Pair(-15, -83), Pair(-2, 26),
        Pair(79, -92), Pair(145, -39), Pair(39, -55), Pair(42, -4), Pair(307, -11), Pair(-27, 10), Pair(-52, -15), Pair(-37, 29),
        Pair(26, -51), Pair(-24, 14), Pair(132, -25), Pair(144, -26), Pair(218, -24), Pair(257, -39), Pair(170, -32), Pair(24, -38),
        Pair(-39, -50), Pair(85, 9), Pair(123, -8), Pair(153, -22), Pair(154, -10), Pair(255, -17), Pair(95, -33), Pair(125, -32),
        Pair(-169, -1), Pair(-52, -9), Pair(102, -16), Pair(62, 5), Pair(204, -28), Pair(84, 1), Pair(113, -11), Pair(93, -26),
        Pair(23, -52), Pair(-81, -28), Pair(116, -72), Pair(-71, 16), Pair(2, -32), Pair(80, -30), Pair(51, -80), Pair(-127, -71),
        Pair(-103, -120), Pair(-144, -45), Pair(21, -9), Pair(-117, -22), Pair(-97, -32), Pair(16, -89), Pair(66, -48), Pair(-68, -114),
        Pair(-48, -59), Pair(-110, -126), Pair(-155, -46), Pair(-137, -29), Pair(-31, -90), Pair(-26, -143), Pair(-266, -57), Pair(-75, -49)
      },
      { // Piece 2
        Pair(-49, -77), Pair(38, -38), Pair(-65, -61), Pair(-1, -33), Pair(-108, -40), Pair(-6, -81), Pair(130, -100), Pair(-13, -90),
        Pair(-132, -37), Pair(16, -16), Pair(63, -48), Pair(112, -95), Pair(128, -81), Pair(64, -64), Pair(11, -69), Pair(65, -117),
        Pair(32, -100), Pair(20, -41), Pair(211, -78), Pair(136, -47), Pair(133, -82), Pair(274, -60), Pair(262, -93), Pair(80, -59),
        Pair(-89, -34), Pair(-2, -51), Pair(139, -46), Pair(166, -69), Pair(107, -42), Pair(234, -66), Pair(112, -45), Pair(15, -12),
        Pair(-28, -89), Pair(38, -55), Pair(127, -78), Pair(191, -72), Pair(229, -88), Pair(29, -46), Pair(163, -100), Pair(8, -21),
        Pair(-27, -82), Pair(104, -102), Pair(133, -80), Pair(106, -58), Pair(132, -93), Pair(104, -83), Pair(162, -139), Pair(37, -121),
        Pair(52, -126), Pair(-130, -59), Pair(69, -70), Pair(46, -85), Pair(-58, -66), Pair(-117, -55), Pair(-2, -89), Pair(-84, -154),
        Pair(-89, -78), Pair(10, -64), Pair(-111, -59), Pair(-64, -111), Pair(-130, -40), Pair(-116, -61), Pair(-56, -117), Pair(19, -97)
      },
      { // Piece 3
        Pair(56, -1), Pair(-90, 14), Pair(-50, -12), Pair(36, -2), Pair(-75, 21), Pair(59, -24), Pair(9, 14), Pair(12, 14),
        Pair(56, -30), Pair(42, -28), Pair(101, -49), Pair(232, -83), Pair(139, -67), Pair(33, -42), Pair(80, -34), Pair(181, -62),
        Pair(-32, -38), Pair(77, -74), Pair(75, -54), Pair(58, -40), Pair(68, -58), Pair(111, -37), Pair(157, -70), Pair(-81, -21),
        Pair(-28, -49), Pair(-32, -38), Pair(-36, -29), Pair(103, -40), Pair(-70, -13), Pair(166, -100), Pair(43, -52), Pair(51, -53),
        Pair(-174, -20), Pair(-16, -48), Pair(-76, -26), Pair(-28, -64), Pair(-52, -53), Pair(-19, -92), Pair(-71, -33), Pair(-81, -53),
        Pair(-197, -13), Pair(-121, -20), Pair(-117, -50), Pair(13, -92), Pair(-57, -54), Pair(-117, -33), Pair(-41, -51), Pair(-190, -39),
        Pair(-188, -21), Pair(-236, -43), Pair(-88, -24), Pair(-66, -39), Pair(-82, -79), Pair(-100, -60), Pair(-108, -30), Pair(-141, -1),
        Pair(-252, -21), Pair(-211, -40), Pair(-99, -36), Pair(-54, -78), Pair(-95, -61), Pair(-95, -43), Pair(-165, 4), Pair(-188, -28)
      },
      { // Piece 4
        Pair(-196, -122), Pair(-137, -62), Pair(-82, -81), Pair(14, -26), Pair(-43, -91), Pair(-126, -36), Pair(47, 83), Pair(-43, -68),
        Pair(-203, 17), Pair(-149, -117), Pair(-214, -15), Pair(-40, 32), Pair(-101, 43), Pair(74, -63), Pair(-79, -49), Pair(-56, -46),
        Pair(-125, -92), Pair(-107, -62), Pair(-13, -36), Pair(-7, -104), Pair(-36, -57), Pair(125, -137), Pair(-133, 31), Pair(84, -154),
        Pair(-195, -53), Pair(-200, -18), Pair(-63, -70), Pair(21, -27), Pair(-79, -16), Pair(-76, 3), Pair(-103, -51), Pair(-167, -100),
        Pair(-280, -27), Pair(-171, -73), Pair(-288, -63), Pair(-147, -32), Pair(-124, 10), Pair(-22, -127), Pair(-177, -108), Pair(-189, -138),
        Pair(-185, -159), Pair(-203, -88), Pair(-151, -71), Pair(-81, -243), Pair(-262, -109), Pair(-225, -18), Pair(-214, -91), Pair(-97, -185),
        Pair(-185, -98), Pair(-210, -125), Pair(-164, -111), Pair(-98, -110), Pair(-113, -188), Pair(-192, -119), Pair(-174, -72), Pair(-225, -246),
        Pair(-154, -187), Pair(-218, -232), Pair(-129, -217), Pair(-304, -87), Pair(-111, -119), Pair(-129, -188), Pair(-252, -141), Pair(-124, -126)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-114, -36), Pair(71, -13), Pair(-15, 7), Pair(4, 0), Pair(-78, 9), Pair(35, 9), Pair(29, 13), Pair(-51, -42),
        Pair(-39, -51), Pair(41, -28), Pair(61, -19), Pair(-29, 1), Pair(-41, 0), Pair(-54, 15), Pair(0, -5), Pair(-23, -63),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 1
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(200, 158), Pair(291, 199), Pair(433, 1), Pair(278, -7), Pair(283, -29), Pair(426, -31), Pair(25, 202), Pair(256, 134),
        Pair(9, 139), Pair(142, 129), Pair(151, 87), Pair(115, 94), Pair(111, 80), Pair(226, 40), Pair(186, 77), Pair(39, 130),
        Pair(-102, 65), Pair(-58, 67), Pair(-19, 52), Pair(-53, 68), Pair(55, 21), Pair(59, 19), Pair(-9, 40), Pair(-27, 25),
        Pair(-166, 31), Pair(-130, 42), Pair(-27, -6), Pair(-28, 7), Pair(-52, 4), Pair(-3, -13), Pair(-73, 25), Pair(-70, 6),
        Pair(-162, 7), Pair(-64, 7), Pair(-77, -16), Pair(-107, 14), Pair(-7, -28), Pair(-48, -25), Pair(-62, -9), Pair(-71, -8),
        Pair(-213, 47), Pair(-150, 39), Pair(-83, -3), Pair(-85, -5), Pair(-26, -24), Pair(-103, -8), Pair(-92, 10), Pair(-115, 7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-65, -177), Pair(-6, -2), Pair(11, -10), Pair(31, -109), Pair(25, -103), Pair(-6, -126), Pair(-31, -60), Pair(-38, 4),
        Pair(-149, -33), Pair(40, -47), Pair(35, -15), Pair(2, -6), Pair(31, 12), Pair(62, -23), Pair(-95, -24), Pair(-88, -64),
        Pair(25, -31), Pair(87, -61), Pair(126, -16), Pair(137, 9), Pair(128, 2), Pair(315, -46), Pair(14, -10), Pair(22, -44),
        Pair(-98, 0), Pair(-20, -13), Pair(132, -5), Pair(109, -7), Pair(86, 7), Pair(125, -1), Pair(96, -22), Pair(-32, 1),
        Pair(-7, -57), Pair(-37, 22), Pair(74, 7), Pair(145, -31), Pair(67, 11), Pair(55, 5), Pair(124, -41), Pair(-36, -82),
        Pair(-114, -80), Pair(-136, 3), Pair(2, -22), Pair(-17, -12), Pair(-72, 12), Pair(-13, -26), Pair(19, -78), Pair(45, -117),
        Pair(-58, -103), Pair(-63, -32), Pair(-114, -16), Pair(-132, -40), Pair(5, -44), Pair(-47, -77), Pair(18, -119), Pair(-66, -108),
        Pair(-4, -42), Pair(-142, -124), Pair(-104, -89), Pair(-186, -98), Pair(19, -86), Pair(-173, -116), Pair(-201, 1), Pair(-35, -76)
      },
      { // Piece 2
        Pair(-61, -112), Pair(-20, -74), Pair(48, -129), Pair(-25, -86), Pair(12, -94), Pair(74, -138), Pair(27, -143), Pair(10, -101),
        Pair(-91, -124), Pair(132, -98), Pair(107, -50), Pair(78, -72), Pair(85, -61), Pair(122, -78), Pair(85, -76), Pair(-22, -116),
        Pair(62, -54), Pair(41, -65), Pair(141, -87), Pair(179, -104), Pair(303, -119), Pair(266, -76), Pair(204, -62), Pair(95, -111),
        Pair(50, -76), Pair(208, -88), Pair(229, -102), Pair(198, -86), Pair(268, -109), Pair(235, -104), Pair(150, -89), Pair(54, -66),
        Pair(10, -87), Pair(63, -81), Pair(133, -73), Pair(78, -71), Pair(75, -76), Pair(172, -88), Pair(196, -120), Pair(6, -41),
        Pair(-14, -120), Pair(70, -59), Pair(67, -77), Pair(58, -72), Pair(152, -93), Pair(84, -88), Pair(187, -110), Pair(30, -78),
        Pair(-69, -129), Pair(-78, -107), Pair(-29, -62), Pair(50, -96), Pair(61, -117), Pair(-41, -55), Pair(104, -111), Pair(-19, -96),
        Pair(66, -108), Pair(137, -103), Pair(-101, -74), Pair(-90, -61), Pair(-120, -98), Pair(-122, -123), Pair(-43, -90), Pair(76, -125)
      },
      { // Piece 3
        Pair(-47, -5), Pair(26, 10), Pair(-35, -23), Pair(-37, 4), Pair(-18, -36), Pair(-69, -39), Pair(-70, -57), Pair(61, -31),
        Pair(261, -97), Pair(249, -106), Pair(294, -109), Pair(228, -96), Pair(210, -79), Pair(227, -97), Pair(216, -87), Pair(131, -67),
        Pair(46, -68), Pair(111, -81), Pair(76, -66), Pair(92, -98), Pair(244, -122), Pair(194, -121), Pair(120, -100), Pair(15, -60),
        Pair(37, -68), Pair(11, -70), Pair(-21, -67), Pair(33, -68), Pair(-6, -61), Pair(153, -121), Pair(-109, -29), Pair(42, -89),
        Pair(-221, -42), Pair(-93, -36), Pair(23, -48), Pair(18, -29), Pair(-12, -79), Pair(-106, -52), Pair(33, -106), Pair(-20, -72),
        Pair(-84, -96), Pair(-162, -20), Pair(-38, -91), Pair(-43, -105), Pair(-123, -84), Pair(10, -95), Pair(-37, -88), Pair(-9, -86),
        Pair(-146, -84), Pair(-181, -83), Pair(-209, -39), Pair(-53, -92), Pair(-70, -85), Pair(-45, -94), Pair(-32, -46), Pair(-80, -49),
        Pair(-218, -65), Pair(-177, -31), Pair(-175, -73), Pair(-159, -52), Pair(-149, -70), Pair(-168, -62), Pair(-170, -46), Pair(-184, -44)
      },
      { // Piece 4
        Pair(-192, -175), Pair(-160, -28), Pair(27, -24), Pair(-20, -14), Pair(-34, -61), Pair(3, -11), Pair(-10, -1), Pair(-10, 9),
        Pair(-179, -78), Pair(-111, -87), Pair(-28, -29), Pair(-31, 14), Pair(-7, -21), Pair(-57, -95), Pair(-6, -74), Pair(32, -93),
        Pair(-46, -81), Pair(-53, -135), Pair(6, -68), Pair(24, -13), Pair(0, -24), Pair(24, -66), Pair(-122, -50), Pair(-77, -101),
        Pair(-123, -107), Pair(-122, -125), Pair(9, -107), Pair(98, -100), Pair(25, -28), Pair(-48, -32), Pair(-27, -45), Pair(-86, -165),
        Pair(-16, -52), Pair(29, 18), Pair(-47, 2), Pair(-15, -51), Pair(-91, -29), Pair(-49, -159), Pair(-130, -88), Pair(-92, -86),
        Pair(-154, -66), Pair(-87, -104), Pair(-154, -128), Pair(-246, 5), Pair(-167, -93), Pair(-98, -141), Pair(-95, -151), Pair(-91, -78),
        Pair(-99, -197), Pair(-50, -78), Pair(-119, -167), Pair(-143, -107), Pair(-20, -161), Pair(-122, -120), Pair(-110, -59), Pair(-94, -109),
        Pair(-50, -90), Pair(-185, -213), Pair(-76, 18), Pair(-375, -223), Pair(-121, -95), Pair(-78, -67), Pair(-75, -90), Pair(-16, -5)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-24, -32), Pair(152, -23), Pair(95, 9), Pair(-47, 21), Pair(4, 19), Pair(-4, 31), Pair(105, -10), Pair(-93, -26),
        Pair(-54, -46), Pair(96, -29), Pair(54, -8), Pair(-82, 16), Pair(-21, -1), Pair(11, 6), Pair(5, -5), Pair(-70, -33),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 2
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(400, 50), Pair(493, 37), Pair(377, 77), Pair(310, 66), Pair(150, 89), Pair(249, 42), Pair(329, 68), Pair(492, 21),
        Pair(211, 62), Pair(268, 63), Pair(381, 17), Pair(301, 22), Pair(262, -2), Pair(252, -8), Pair(240, 10), Pair(123, 28),
        Pair(-72, 47), Pair(-9, 35), Pair(90, 9), Pair(-24, 23), Pair(20, 5), Pair(76, -12), Pair(49, 10), Pair(-55, 4),
        Pair(-114, 24), Pair(-60, 23), Pair(-26, -1), Pair(-25, -11), Pair(-6, -15), Pair(-20, -18), Pair(-74, 6), Pair(-112, 4),
        Pair(-148, 14), Pair(-106, 5), Pair(-50, -20), Pair(-26, -19), Pair(-63, -21), Pair(-81, -20), Pair(-47, -14), Pair(-136, -6),
        Pair(-199, 34), Pair(-120, 19), Pair(-94, -3), Pair(-18, -7), Pair(-87, -14), Pair(-65, -12), Pair(-78, 4), Pair(-154, 13),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-23, -183), Pair(19, -72), Pair(13, -57), Pair(-45, -52), Pair(110, -24), Pair(-107, -62), Pair(-117, -77), Pair(-14, -106),
        Pair(-98, -96), Pair(55, -68), Pair(81, -55), Pair(36, -17), Pair(123, -45), Pair(160, -23), Pair(29, -72), Pair(-48, -70),
        Pair(-82, -63), Pair(-21, -14), Pair(138, -22), Pair(74, -3), Pair(248, -36), Pair(163, -11), Pair(119, -53), Pair(99, -65),
        Pair(-57, -53), Pair(71, -40), Pair(62, -20), Pair(90, -5), Pair(72, 6), Pair(123, -17), Pair(74, -31), Pair(17, -42),
        Pair(-119, -51), Pair(29, -37), Pair(92, -23), Pair(93, -9), Pair(116, -14), Pair(69, -12), Pair(86, -41), Pair(-7, -42),
        Pair(-112, -90), Pair(-7, -63), Pair(-4, -33), Pair(23, -27), Pair(16, -27), Pair(-13, -42), Pair(18, -42), Pair(0, -52),
        Pair(-157, -67), Pair(-110, -73), Pair(-153, -35), Pair(-113, -36), Pair(-96, -21), Pair(-32, -45), Pair(-102, -86), Pair(-22, -81),
        Pair(-57, -112), Pair(-229, -60), Pair(-258, -69), Pair(-184, -72), Pair(-122, -65), Pair(-231, -63), Pair(-86, -114), Pair(-35, -90)
      },
      { // Piece 2
        Pair(-21, -97), Pair(91, -118), Pair(143, -118), Pair(11, -87), Pair(138, -114), Pair(-2, -102), Pair(72, -150), Pair(59, -124),
        Pair(-36, -144), Pair(242, -139), Pair(130, -107), Pair(215, -108), Pair(137, -106), Pair(219, -89), Pair(192, -98), Pair(75, -126),
        Pair(15, -94), Pair(131, -92), Pair(177, -94), Pair(172, -105), Pair(252, -105), Pair(319, -102), Pair(322, -120), Pair(18, -102),
        Pair(84, -96), Pair(227, -105), Pair(158, -83), Pair(256, -106), Pair(243, -100), Pair(236, -106), Pair(221, -95), Pair(62, -105),
        Pair(-148, -79), Pair(14, -79), Pair(244, -109), Pair(182, -104), Pair(216, -106), Pair(239, -108), Pair(120, -97), Pair(-61, -65),
        Pair(12, -93), Pair(134, -105), Pair(55, -86), Pair(197, -120), Pair(140, -104), Pair(112, -99), Pair(67, -86), Pair(-101, -84),
        Pair(-76, -101), Pair(25, -113), Pair(79, -103), Pair(35, -89), Pair(95, -112), Pair(43, -125), Pair(-59, -87), Pair(28, -150),
        Pair(-58, -110), Pair(65, -105), Pair(-93, -102), Pair(-45, -99), Pair(-14, -103), Pair(-47, -102), Pair(67, -101), Pair(-43, -122)
      },
      { // Piece 3
        Pair(113, -90), Pair(163, -106), Pair(102, -81), Pair(89, -84), Pair(5, -87), Pair(184, -117), Pair(225, -114), Pair(174, -101),
        Pair(-109, -46), Pair(-14, -62), Pair(37, -78), Pair(113, -93), Pair(76, -107), Pair(73, -94), Pair(-13, -50), Pair(124, -97),
        Pair(44, -93), Pair(82, -97), Pair(94, -104), Pair(116, -123), Pair(153, -129), Pair(218, -134), Pair(189, -127), Pair(98, -105),
        Pair(-26, -84), Pair(34, -106), Pair(-26, -74), Pair(32, -92), Pair(75, -113), Pair(59, -88), Pair(32, -94), Pair(-25, -89),
        Pair(-104, -100), Pair(-77, -71), Pair(28, -111), Pair(-39, -80), Pair(-31, -95), Pair(-26, -91), Pair(-13, -71), Pair(-157, -61),
        Pair(-139, -94), Pair(-108, -81), Pair(-128, -100), Pair(-53, -106), Pair(-111, -89), Pair(-25, -124), Pair(-61, -99), Pair(-165, -77),
        Pair(-181, -100), Pair(-101, -111), Pair(-86, -100), Pair(-102, -100), Pair(-168, -72), Pair(-16, -128), Pair(-133, -85), Pair(-217, -83),
        Pair(-146, -111), Pair(-100, -111), Pair(-90, -97), Pair(-60, -120), Pair(-105, -117), Pair(-85, -119), Pair(-106, -93), Pair(-139, -85)
      },
      { // Piece 4
        Pair(-71, -262), Pair(-146, -151), Pair(-69, -165), Pair(-73, -125), Pair(-93, -111), Pair(-179, -158), Pair(-224, -104), Pair(-159, -185),
        Pair(-199, -207), Pair(-77, -190), Pair(-105, -220), Pair(-118, -109), Pair(3, -160), Pair(-131, -127), Pair(-108, -124), Pair(-104, -155),
        Pair(-140, -227), Pair(-89, -263), Pair(-152, -76), Pair(-178, -65), Pair(-93, -93), Pair(-90, -130), Pair(-33, -155), Pair(-96, -206),
        Pair(-66, -212), Pair(-178, -187), Pair(-149, -90), Pair(-155, -107), Pair(-173, -91), Pair(-136, -94), Pair(-203, -58), Pair(-133, -151),
        Pair(-225, -212), Pair(-245, -158), Pair(-252, -159), Pair(-207, -145), Pair(-95, -137), Pair(-173, -174), Pair(-190, -117), Pair(-42, -234),
        Pair(-170, -181), Pair(-207, -122), Pair(-162, -147), Pair(-105, -266), Pair(-287, -83), Pair(-155, -257), Pair(-243, -219), Pair(-288, -189),
        Pair(-242, -231), Pair(-143, -196), Pair(-193, -210), Pair(-125, -254), Pair(-279, -286), Pair(-284, -210), Pair(-112, -201), Pair(-219, -307),
        Pair(-183, -331), Pair(-178, -194), Pair(-176, -323), Pair(-195, -243), Pair(-177, -312), Pair(-169, -121), Pair(-141, -268), Pair(-183, -218)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(34, -40), Pair(116, -5), Pair(6, 5), Pair(-67, 10), Pair(-21, 0), Pair(40, 10), Pair(32, 13), Pair(-86, -24),
        Pair(10, -48), Pair(48, -20), Pair(-9, 2), Pair(-103, 15), Pair(-64, 13), Pair(-35, 5), Pair(7, -11), Pair(-65, -41),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 3
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(246, 171), Pair(323, 155), Pair(284, 165), Pair(236, 161), Pair(202, 147), Pair(210, 156), Pair(155, 186), Pair(258, 165),
        Pair(161, 100), Pair(272, 69), Pair(292, 52), Pair(200, 72), Pair(169, 62), Pair(197, 43), Pair(286, 62), Pair(157, 77),
        Pair(-15, 36), Pair(64, 24), Pair(115, 7), Pair(71, -5), Pair(29, -15), Pair(147, -30), Pair(105, 8), Pair(-38, 9),
        Pair(-94, 21), Pair(-24, 14), Pair(-23, 4), Pair(-33, -7), Pair(-68, -17), Pair(-14, -14), Pair(0, 2), Pair(-113, 4),
        Pair(-166, 21), Pair(-56, -1), Pair(-14, -8), Pair(-10, -11), Pair(1, -34), Pair(-66, -13), Pair(-69, -2), Pair(-143, -1),
        Pair(-140, 30), Pair(-128, 25), Pair(-104, -10), Pair(-75, -9), Pair(-60, -21), Pair(-98, 4), Pair(-127, 23), Pair(-190, 26),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-6, -189), Pair(53, -73), Pair(4, -78), Pair(40, -61), Pair(26, -103), Pair(41, -23), Pair(-25, -22), Pair(27, -98),
        Pair(-51, -125), Pair(-95, -65), Pair(-7, -35), Pair(132, -59), Pair(81, -34), Pair(90, -28), Pair(35, -71), Pair(62, -83),
        Pair(37, -87), Pair(94, -81), Pair(72, -14), Pair(98, -33), Pair(163, -47), Pair(118, -24), Pair(54, -55), Pair(108, -102),
        Pair(123, -84), Pair(47, -45), Pair(141, -45), Pair(77, -12), Pair(128, -23), Pair(145, -30), Pair(24, -29), Pair(17, -90),
        Pair(-19, -84), Pair(-5, -65), Pair(50, -28), Pair(152, -51), Pair(14, -34), Pair(78, -31), Pair(6, -37), Pair(-6, -69),
        Pair(45, -111), Pair(12, -45), Pair(71, -61), Pair(59, -32), Pair(-14, -26), Pair(30, -39), Pair(-18, -57), Pair(-57, -76),
        Pair(-8, -103), Pair(-146, -57), Pair(2, -82), Pair(-85, -27), Pair(-9, -41), Pair(-45, -71), Pair(-35, -58), Pair(-90, -142),
        Pair(-12, -158), Pair(-142, -125), Pair(-219, -60), Pair(-130, -55), Pair(-173, -100), Pair(-105, -91), Pair(-61, -155), Pair(-76, -113)
      },
      { // Piece 2
        Pair(-70, -112), Pair(14, -81), Pair(64, -85), Pair(68, -107), Pair(42, -130), Pair(47, -97), Pair(23, -90), Pair(38, -58),
        Pair(18, -93), Pair(99, -94), Pair(109, -117), Pair(158, -119), Pair(159, -106), Pair(242, -117), Pair(36, -80), Pair(-33, -86),
        Pair(13, -103), Pair(151, -117), Pair(166, -109), Pair(190, -103), Pair(292, -116), Pair(201, -105), Pair(177, -92), Pair(31, -74),
        Pair(49, -89), Pair(98, -88), Pair(206, -108), Pair(153, -89), Pair(250, -102), Pair(235, -102), Pair(199, -81), Pair(107, -95),
        Pair(-10, -86), Pair(112, -75), Pair(134, -89), Pair(219, -108), Pair(155, -100), Pair(134, -102), Pair(149, -95), Pair(-87, -84),
        Pair(-54, -90), Pair(-32, -77), Pair(93, -78), Pair(83, -106), Pair(143, -112), Pair(40, -100), Pair(36, -84), Pair(-49, -75),
        Pair(44, -88), Pair(97, -104), Pair(59, -131), Pair(59, -95), Pair(59, -108), Pair(-34, -93), Pair(-163, -63), Pair(-35, -115),
        Pair(-128, -104), Pair(-19, -124), Pair(-125, -61), Pair(15, -96), Pair(-38, -97), Pair(55, -134), Pair(42, -123), Pair(-25, -89)
      },
      { // Piece 3
        Pair(37, -126), Pair(35, -100), Pair(53, -120), Pair(124, -99), Pair(-69, -52), Pair(41, -81), Pair(13, -84), Pair(111, -114),
        Pair(119, -133), Pair(72, -113), Pair(158, -133), Pair(66, -105), Pair(148, -115), Pair(181, -135), Pair(75, -129), Pair(49, -112),
        Pair(56, -131), Pair(-67, -110), Pair(31, -105), Pair(21, -109), Pair(-7, -141), Pair(36, -120), Pair(-59, -90), Pair(65, -143),
        Pair(-18, -103), Pair(68, -117), Pair(52, -121), Pair(51, -113), Pair(59, -108), Pair(129, -123), Pair(90, -124), Pair(24, -118),
        Pair(-32, -142), Pair(-35, -104), Pair(-14, -109), Pair(-41, -96), Pair(9, -109), Pair(47, -118), Pair(-33, -110), Pair(26, -130),
        Pair(-139, -108), Pair(-72, -112), Pair(-44, -134), Pair(-85, -117), Pair(-71, -94), Pair(-36, -125), Pair(-80, -99), Pair(-96, -140),
        Pair(-184, -99), Pair(-80, -134), Pair(-19, -130), Pair(-112, -111), Pair(16, -156), Pair(-64, -127), Pair(-108, -139), Pair(-77, -113),
        Pair(-126, -129), Pair(-31, -135), Pair(-61, -136), Pair(-94, -117), Pair(-114, -117), Pair(-53, -131), Pair(-55, -131), Pair(-164, -109)
      },
      { // Piece 4
        Pair(-40, -243), Pair(-56, -119), Pair(-55, -103), Pair(-27, -170), Pair(-87, -129), Pair(-45, -110), Pair(-36, -174), Pair(-115, -222),
        Pair(-57, -159), Pair(-92, -99), Pair(-33, -208), Pair(-29, -149), Pair(35, -165), Pair(-106, -125), Pair(-65, -84), Pair(-142, -162),
        Pair(-53, -121), Pair(-94, -142), Pair(-135, -66), Pair(-4, -105), Pair(-57, -147), Pair(-23, -110), Pair(-90, -173), Pair(-90, -103),
        Pair(-84, -179), Pair(-57, -155), Pair(-43, -155), Pair(-21, -146), Pair(48, -111), Pair(-82, -165), Pair(-130, -181), Pair(-127, -214),
        Pair(-65, -81), Pair(-108, -113), Pair(-118, -117), Pair(5, -37), Pair(-91, -87), Pair(-49, -164), Pair(-118, -211), Pair(-110, -94),
        Pair(-132, -202), Pair(-77, -140), Pair(-106, -214), Pair(-60, -161), Pair(-48, -152), Pair(-46, -168), Pair(-50, -125), Pair(-156, -225),
        Pair(-145, -275), Pair(-79, -155), Pair(-27, -229), Pair(-109, -150), Pair(-93, -218), Pair(-93, -106), Pair(-69, -155), Pair(-43, -196),
        Pair(-109, -212), Pair(-52, -102), Pair(2, -47), Pair(-114, -252), Pair(-27, -217), Pair(-125, -153), Pair(-66, -128), Pair(-40, -125)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-13, -29), Pair(18, 15), Pair(21, 20), Pair(-62, 19), Pair(28, 9), Pair(28, 18), Pair(-20, 20), Pair(-69, -20),
        Pair(40, -33), Pair(-1, 8), Pair(39, 15), Pair(-7, 11), Pair(-18, 14), Pair(-16, 19), Pair(0, 7), Pair(-84, -20),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 4
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-52, 212), Pair(139, 199), Pair(141, 198), Pair(132, 173), Pair(195, 138), Pair(122, 183), Pair(15, 223), Pair(-68, 183),
        Pair(-29, 146), Pair(105, 145), Pair(67, 130), Pair(130, 112), Pair(54, 124), Pair(102, 106), Pair(120, 130), Pair(-11, 137),
        Pair(-108, 46), Pair(-14, 31), Pair(92, 1), Pair(-2, 8), Pair(-1, 1), Pair(67, -1), Pair(94, 16), Pair(-27, 30),
        Pair(-164, 36), Pair(-45, 21), Pair(4, -6), Pair(7, -27), Pair(-4, -28), Pair(-16, -13), Pair(-1, 8), Pair(-146, 16),
        Pair(-185, 20), Pair(-106, 10), Pair(-86, -3), Pair(-60, 13), Pair(-81, -8), Pair(-76, -17), Pair(-102, 10), Pair(-150, 0),
        Pair(-206, 40), Pair(-149, 32), Pair(-54, 3), Pair(-117, 17), Pair(-94, 3), Pair(-73, 12), Pair(-122, 21), Pair(-115, 9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(16, -197), Pair(91, -168), Pair(-70, -56), Pair(31, -123), Pair(98, -128), Pair(-31, -86), Pair(-48, -105), Pair(-9, -202),
        Pair(-64, -107), Pair(22, -106), Pair(36, -95), Pair(137, -67), Pair(-22, -47), Pair(80, -85), Pair(-17, -78), Pair(-83, -155),
        Pair(-42, -108), Pair(50, -54), Pair(70, -58), Pair(82, -81), Pair(56, -33), Pair(64, -71), Pair(23, -52), Pair(-10, -111),
        Pair(8, -114), Pair(74, -69), Pair(93, -51), Pair(93, -46), Pair(93, -45), Pair(148, -85), Pair(60, -79), Pair(-112, -105),
        Pair(-13, -141), Pair(-21, -35), Pair(51, -54), Pair(48, -54), Pair(104, -44), Pair(84, -39), Pair(-18, -63), Pair(30, -115),
        Pair(-79, -113), Pair(-64, -97), Pair(43, -68), Pair(20, -42), Pair(62, -76), Pair(92, -79), Pair(-88, -45), Pair(-21, -103),
        Pair(-45, -115), Pair(-100, -97), Pair(15, -78), Pair(-36, -70), Pair(83, -77), Pair(-62, -109), Pair(39, -56), Pair(-24, -95),
        Pair(-66, -165), Pair(-84, -118), Pair(-49, -127), Pair(-59, -81), Pair(14, -44), Pair(-60, -115), Pair(10, -114), Pair(-16, -148)
      },
      { // Piece 2
        Pair(-76, -117), Pair(117, -119), Pair(-6, -91), Pair(-69, -84), Pair(-87, -115), Pair(-141, -74), Pair(9, -70), Pair(-24, -104),
        Pair(62, -96), Pair(-87, -91), Pair(65, -99), Pair(-10, -129), Pair(88, -92), Pair(11, -94), Pair(12, -87), Pair(-65, -103),
        Pair(110, -136), Pair(174, -111), Pair(71, -97), Pair(77, -89), Pair(56, -107), Pair(-3, -90), Pair(9, -116), Pair(34, -98),
        Pair(-69, -61), Pair(17, -86), Pair(159, -120), Pair(156, -89), Pair(108, -92), Pair(156, -126), Pair(74, -100), Pair(0, -131),
        Pair(-35, -116), Pair(90, -102), Pair(86, -97), Pair(128, -90), Pair(137, -104), Pair(112, -101), Pair(12, -106), Pair(47, -143),
        Pair(-68, -91), Pair(27, -90), Pair(120, -94), Pair(20, -102), Pair(76, -85), Pair(63, -78), Pair(34, -83), Pair(-63, -127),
        Pair(-31, -102), Pair(-77, -70), Pair(-48, -119), Pair(81, -111), Pair(56, -102), Pair(32, -106), Pair(-53, -103), Pair(-12, -138),
        Pair(1, -115), Pair(-89, -80), Pair(-131, -78), Pair(-93, -117), Pair(-38, -105), Pair(-30, -124), Pair(11, -137), Pair(52, -114)
      },
      { // Piece 3
        Pair(86, -171), Pair(38, -133), Pair(126, -143), Pair(49, -120), Pair(19, -125), Pair(16, -145), Pair(114, -159), Pair(59, -149),
        Pair(36, -159), Pair(85, -146), Pair(-80, -124), Pair(40, -121), Pair(95, -145), Pair(56, -155), Pair(119, -174), Pair(5, -145),
        Pair(-66, -111), Pair(35, -154), Pair(91, -166), Pair(39, -144), Pair(86, -141), Pair(84, -137), Pair(23, -145), Pair(-15, -128),
        Pair(10, -171), Pair(24, -194), Pair(41, -165), Pair(-27, -152), Pair(-22, -145), Pair(1, -172), Pair(-7, -132), Pair(-59, -147),
        Pair(-21, -170), Pair(-138, -115), Pair(-4, -133), Pair(-56, -136), Pair(52, -160), Pair(47, -154), Pair(53, -173), Pair(-76, -152),
        Pair(-65, -143), Pair(65, -198), Pair(-68, -137), Pair(-49, -154), Pair(-73, -159), Pair(128, -169), Pair(120, -191), Pair(-103, -144),
        Pair(-80, -181), Pair(-100, -164), Pair(15, -173), Pair(-119, -139), Pair(-59, -150), Pair(-36, -161), Pair(-70, -160), Pair(-86, -156),
        Pair(-83, -164), Pair(-112, -144), Pair(-72, -151), Pair(-43, -169), Pair(-32, -148), Pair(-97, -154), Pair(-63, -159), Pair(-77, -164)
      },
      { // Piece 4
        Pair(-107, -121), Pair(-71, -134), Pair(-66, -128), Pair(-74, -119), Pair(39, -205), Pair(52, -174), Pair(-131, -152), Pair(-74, -142),
        Pair(-73, -126), Pair(-50, -39), Pair(-47, -129), Pair(4, -76), Pair(-60, -32), Pair(-100, -154), Pair(10, -71), Pair(-165, -134),
        Pair(-64, -87), Pair(-8, -81), Pair(6, -152), Pair(-41, -97), Pair(-70, -125), Pair(-43, -69), Pair(-82, -98), Pair(-79, -127),
        Pair(-41, -91), Pair(-12, -52), Pair(-27, -57), Pair(-37, -94), Pair(-80, -134), Pair(-20, -58), Pair(-29, -50), Pair(55, 23),
        Pair(-67, -114), Pair(-46, -89), Pair(-53, -60), Pair(-38, -98), Pair(-81, -99), Pair(-35, -74), Pair(9, -33), Pair(-87, -173),
        Pair(-118, -125), Pair(-67, -95), Pair(-103, -118), Pair(-47, -147), Pair(-71, -159), Pair(-26, -45), Pair(-56, -99), Pair(-4, -58),
        Pair(-11, -91), Pair(-80, -88), Pair(-48, -121), Pair(-94, -168), Pair(-13, -124), Pair(-28, -66), Pair(-38, -73), Pair(-23, -166),
        Pair(-82, -193), Pair(-68, -146), Pair(-84, -190), Pair(-38, -97), Pair(-21, -26), Pair(-76, -184), Pair(-104, -205), Pair(-78, -146)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(47, -32), Pair(81, 10), Pair(45, 12), Pair(-14, 13), Pair(-11, 5), Pair(37, 23), Pair(65, 11), Pair(16, -28),
        Pair(31, -41), Pair(19, 11), Pair(-24, 21), Pair(-76, 36), Pair(-53, 26), Pair(-21, 23), Pair(-20, 19), Pair(-68, -24),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 5
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-97, 212), Pair(81, 213), Pair(251, 178), Pair(195, 177), Pair(248, 172), Pair(184, 206), Pair(74, 209), Pair(-72, 207),
        Pair(-130, 163), Pair(-50, 163), Pair(76, 162), Pair(82, 150), Pair(89, 154), Pair(18, 139), Pair(-4, 161), Pair(-73, 165),
        Pair(-135, 63), Pair(-39, 48), Pair(23, 46), Pair(-58, 38), Pair(-37, 26), Pair(40, 33), Pair(9, 47), Pair(-143, 56),
        Pair(-159, 27), Pair(-73, 11), Pair(-16, -9), Pair(-73, -7), Pair(-69, -20), Pair(-36, -20), Pair(-5, -5), Pair(-155, 19),
        Pair(-179, 12), Pair(-102, -3), Pair(-60, -23), Pair(-158, 1), Pair(-116, -20), Pair(-26, -36), Pair(-148, 1), Pair(-224, 8),
        Pair(-188, 42), Pair(-147, 24), Pair(-121, -3), Pair(-97, 3), Pair(-130, -23), Pair(-102, -6), Pair(-97, 13), Pair(-245, 29),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-28, -204), Pair(-52, -156), Pair(8, -142), Pair(-87, -143), Pair(-51, -121), Pair(-7, -135), Pair(-97, -121), Pair(60, -204),
        Pair(-23, -145), Pair(28, -151), Pair(-18, -119), Pair(-3, -104), Pair(-27, -109), Pair(-43, -140), Pair(8, -119), Pair(-4, -141),
        Pair(-125, -131), Pair(38, -115), Pair(41, -83), Pair(54, -110), Pair(116, -119), Pair(32, -101), Pair(21, -119), Pair(-52, -119),
        Pair(-14, -134), Pair(16, -111), Pair(61, -105), Pair(55, -99), Pair(53, -86), Pair(95, -99), Pair(70, -108), Pair(-12, -105),
        Pair(49, -134), Pair(-16, -111), Pair(29, -91), Pair(68, -98), Pair(157, -107), Pair(78, -93), Pair(168, -119), Pair(-32, -142),
        Pair(-18, -157), Pair(-64, -106), Pair(91, -116), Pair(90, -100), Pair(61, -96), Pair(73, -107), Pair(-56, -118), Pair(-12, -127),
        Pair(-76, -136), Pair(-20, -135), Pair(-65, -133), Pair(-43, -100), Pair(-21, -85), Pair(-6, -134), Pair(-15, -93), Pair(-70, -114),
        Pair(-73, -163), Pair(8, -128), Pair(-53, -93), Pair(-12, -146), Pair(64, -131), Pair(20, -120), Pair(65, -137), Pair(-14, -170)
      },
      { // Piece 2
        Pair(34, -110), Pair(104, -123), Pair(-25, -116), Pair(-93, -107), Pair(69, -128), Pair(-94, -94), Pair(131, -144), Pair(-46, -119),
        Pair(-21, -115), Pair(-183, -79), Pair(-59, -89), Pair(24, -94), Pair(-98, -99), Pair(96, -131), Pair(-20, -102), Pair(-17, -115),
        Pair(-67, -93), Pair(36, -98), Pair(38, -97), Pair(46, -107), Pair(34, -122), Pair(-14, -107), Pair(90, -123), Pair(-55, -138),
        Pair(-18, -128), Pair(-82, -88), Pair(37, -117), Pair(15, -98), Pair(18, -99), Pair(80, -111), Pair(-97, -82), Pair(11, -116),
        Pair(47, -122), Pair(2, -124), Pair(-8, -82), Pair(20, -98), Pair(37, -101), Pair(-72, -80), Pair(11, -100), Pair(-96, -111),
        Pair(-131, -101), Pair(26, -115), Pair(-37, -104), Pair(-106, -89), Pair(-29, -91), Pair(19, -97), Pair(11, -136), Pair(17, -123),
        Pair(-49, -92), Pair(-121, -90), Pair(107, -157), Pair(-158, -107), Pair(-11, -119), Pair(-29, -125), Pair(-76, -110), Pair(-13, -158),
        Pair(-88, -92), Pair(-5, -78), Pair(-50, -108), Pair(-66, -126), Pair(-166, -119), Pair(7, -121), Pair(-99, -114), Pair(-14, -133)
      },
      { // Piece 3
        Pair(100, -218), Pair(89, -220), Pair(206, -217), Pair(50, -197), Pair(68, -181), Pair(67, -208), Pair(115, -210), Pair(108, -218),
        Pair(34, -202), Pair(49, -193), Pair(202, -241), Pair(40, -191), Pair(143, -227), Pair(56, -209), Pair(98, -215), Pair(-29, -199),
        Pair(22, -193), Pair(112, -231), Pair(16, -199), Pair(161, -228), Pair(93, -218), Pair(147, -235), Pair(96, -229), Pair(61, -214),
        Pair(49, -198), Pair(202, -230), Pair(89, -223), Pair(150, -218), Pair(85, -216), Pair(161, -231), Pair(6, -189), Pair(74, -235),
        Pair(-16, -215), Pair(36, -223), Pair(120, -227), Pair(64, -226), Pair(28, -230), Pair(110, -254), Pair(126, -245), Pair(42, -230),
        Pair(32, -253), Pair(55, -244), Pair(-29, -209), Pair(7, -207), Pair(-41, -214), Pair(-93, -190), Pair(-100, -212), Pair(-47, -195),
        Pair(-89, -205), Pair(-74, -209), Pair(-8, -199), Pair(-97, -178), Pair(-133, -174), Pair(-54, -202), Pair(1, -210), Pair(-28, -230),
        Pair(-85, -200), Pair(-134, -175), Pair(-16, -223), Pair(-19, -229), Pair(-23, -217), Pair(-32, -201), Pair(-53, -208), Pair(-80, -212)
      },
      { // Piece 4
        Pair(-112, -346), Pair(-152, -288), Pair(-141, -223), Pair(-197, -257), Pair(-129, -261), Pair(-227, -210), Pair(-58, -334), Pair(-125, -321),
        Pair(-124, -234), Pair(-94, -213), Pair(-76, -242), Pair(-51, -266), Pair(-101, -238), Pair(-55, -251), Pair(-92, -309), Pair(-130, -259),
        Pair(-103, -245), Pair(-121, -236), Pair(-106, -188), Pair(-60, -278), Pair(-49, -241), Pair(-67, -270), Pair(-93, -284), Pair(-107, -240),
        Pair(-177, -260), Pair(-116, -283), Pair(-111, -205), Pair(-61, -188), Pair(-81, -205), Pair(-5, -229), Pair(-154, -214), Pair(-142, -233),
        Pair(-95, -271), Pair(-142, -265), Pair(-29, -132), Pair(-73, -132), Pair(-147, -261), Pair(-49, -209), Pair(-72, -128), Pair(-119, -227),
        Pair(-77, -141), Pair(-124, -220), Pair(-125, -230), Pair(-129, -254), Pair(-131, -232), Pair(-127, -254), Pair(31, -16), Pair(-89, -205),
        Pair(-103, -294), Pair(-151, -251), Pair(-199, -293), Pair(-129, -255), Pair(-40, -231), Pair(-131, -268), Pair(-102, -233), Pair(-153, -293),
        Pair(-120, -269), Pair(-80, -214), Pair(-138, -302), Pair(-70, -285), Pair(-93, -263), Pair(-130, -266), Pair(-132, -250), Pair(-108, -278)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-21, -25), Pair(54, 8), Pair(72, 6), Pair(-17, -5), Pair(39, -6), Pair(44, 6), Pair(41, 8), Pair(9, -36),
        Pair(28, -34), Pair(-16, 10), Pair(7, 13), Pair(-108, 27), Pair(-23, 22), Pair(10, 21), Pair(-25, 20), Pair(-38, -31),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 6
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-177, 249), Pair(-145, 277), Pair(59, 281), Pair(186, 245), Pair(116, 242), Pair(66, 271), Pair(8, 272), Pair(-181, 276),
        Pair(-227, 252), Pair(-8, 246), Pair(53, 199), Pair(9, 214), Pair(82, 218), Pair(16, 191), Pair(-88, 246), Pair(-131, 217),
        Pair(-151, 88), Pair(-56, 91), Pair(36, 64), Pair(-41, 121), Pair(-65, 55), Pair(98, 80), Pair(47, 87), Pair(-89, 77),
        Pair(-138, 25), Pair(-163, 23), Pair(-28, 16), Pair(-90, 15), Pair(13, -21), Pair(9, -1), Pair(-78, 36), Pair(-166, 28),
        Pair(-165, 12), Pair(-138, 6), Pair(-73, 1), Pair(-65, -21), Pair(-54, -2), Pair(-83, -12), Pair(-171, 8), Pair(-104, 7),
        Pair(-169, 24), Pair(-145, 40), Pair(-109, 6), Pair(-34, 33), Pair(32, -8), Pair(-132, 2), Pair(-171, 24), Pair(-43, 6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-42, -124), Pair(-16, -97), Pair(18, -73), Pair(-4, -59), Pair(-48, -91), Pair(-49, -156), Pair(1, -167), Pair(37, -92),
        Pair(-12, -214), Pair(-62, -139), Pair(-84, -93), Pair(-4, -105), Pair(-6, -52), Pair(-117, -172), Pair(-37, -48), Pair(-8, -152),
        Pair(-26, -153), Pair(-41, -63), Pair(-71, -97), Pair(-56, -49), Pair(-85, -74), Pair(-10, -74), Pair(45, -29), Pair(-51, -180),
        Pair(-27, -108), Pair(-19, -96), Pair(-83, -65), Pair(45, -39), Pair(100, -83), Pair(85, -101), Pair(118, -122), Pair(-25, -84),
        Pair(-9, -128), Pair(18, -100), Pair(112, -78), Pair(30, -90), Pair(23, -83), Pair(59, -65), Pair(-51, -111), Pair(54, -95),
        Pair(-22, -105), Pair(60, -58), Pair(32, -80), Pair(60, -83), Pair(95, -73), Pair(-36, -52), Pair(-23, -17), Pair(20, -141),
        Pair(-12, -106), Pair(19, -67), Pair(-67, -145), Pair(-41, -71), Pair(-7, -112), Pair(-19, -91), Pair(8, -52), Pair(-10, -22),
        Pair(-26, -46), Pair(-29, -103), Pair(-12, -101), Pair(-74, -93), Pair(41, -79), Pair(38, -90), Pair(-12, -173), Pair(-25, -84)
      },
      { // Piece 2
        Pair(-17, -69), Pair(9, 13), Pair(-94, -53), Pair(-15, -18), Pair(19, -73), Pair(-8, -82), Pair(-18, 23), Pair(-5, -71),
        Pair(16, -16), Pair(-61, 4), Pair(-19, -13), Pair(-8, -67), Pair(-5, -49), Pair(-48, -31), Pair(-22, -65), Pair(-42, -115),
        Pair(14, -31), Pair(0, -61), Pair(-34, -33), Pair(16, -3), Pair(22, -59), Pair(-136, -25), Pair(-21, -35), Pair(-3, -28),
        Pair(-52, -25), Pair(-16, -12), Pair(17, -41), Pair(-81, -22), Pair(14, 17), Pair(-37, -106), Pair(-70, -27), Pair(54, -35),
        Pair(-71, -32), Pair(-54, -5), Pair(58, -9), Pair(26, 3), Pair(71, -82), Pair(-20, -6), Pair(-26, -47), Pair(9, -21),
        Pair(-32, -19), Pair(0, -19), Pair(20, -34), Pair(-106, -82), Pair(-109, -108), Pair(-48, -40), Pair(-47, 12), Pair(7, -39),
        Pair(-23, -23), Pair(-73, -84), Pair(14, -60), Pair(-42, -77), Pair(-72, -130), Pair(-24, -131), Pair(12, -28), Pair(-33, -83),
        Pair(1, -67), Pair(87, -131), Pair(-19, -69), Pair(-3, -99), Pair(-57, -22), Pair(-41, -135), Pair(-4, -40), Pair(44, -72)
      },
      { // Piece 3
        Pair(43, -190), Pair(17, -161), Pair(20, -140), Pair(64, -185), Pair(20, -147), Pair(-31, -125), Pair(-47, -96), Pair(55, -163),
        Pair(-25, -191), Pair(49, -149), Pair(88, -153), Pair(26, -154), Pair(7, -144), Pair(1, -181), Pair(-1, -175), Pair(-29, -209),
        Pair(-8, -172), Pair(-21, -115), Pair(27, -150), Pair(124, -196), Pair(17, -140), Pair(-4, -165), Pair(16, -160), Pair(19, -163),
        Pair(32, -182), Pair(45, -170), Pair(-27, -153), Pair(-32, -142), Pair(-95, -127), Pair(55, -215), Pair(6, -157), Pair(-38, -168),
        Pair(58, -230), Pair(47, -189), Pair(-95, -165), Pair(63, -167), Pair(-40, -145), Pair(-31, -159), Pair(-42, -168), Pair(8, -177),
        Pair(-20, -134), Pair(-31, -131), Pair(13, -180), Pair(-66, -179), Pair(52, -153), Pair(56, -183), Pair(29, -192), Pair(25, -175),
        Pair(-36, -129), Pair(44, -174), Pair(40, -107), Pair(-49, -191), Pair(37, -138), Pair(1, -145), Pair(-21, -217), Pair(1, -177),
        Pair(-23, -171), Pair(-77, -174), Pair(157, -233), Pair(-1, -230), Pair(-11, -209), Pair(-9, -210), Pair(-34, -214), Pair(-29, -207)
      },
      { // Piece 4
        Pair(-120, -161), Pair(-44, -201), Pair(-1, -203), Pair(-88, -90), Pair(-50, -87), Pair(-126, -138), Pair(-124, -193), Pair(-80, -151),
        Pair(-49, -173), Pair(-86, -135), Pair(-73, -48), Pair(-94, -81), Pair(-60, -172), Pair(-39, -96), Pair(-61, -108), Pair(-36, -77),
        Pair(-35, -138), Pair(-132, -130), Pair(-34, -76), Pair(-8, -67), Pair(-39, -87), Pair(-42, -129), Pair(-76, -120), Pair(-56, -66),
        Pair(-61, -150), Pair(-26, -90), Pair(-16, -89), Pair(-41, -131), Pair(-44, -67), Pair(-27, -114), Pair(-70, -108), Pair(-17, -160),
        Pair(-34, -81), Pair(25, -101), Pair(0, -172), Pair(-30, -44), Pair(20, -104), Pair(11, -86), Pair(-59, -130), Pair(-21, -75),
        Pair(-45, -131), Pair(-50, -126), Pair(-92, -142), Pair(-13, -94), Pair(-2, -44), Pair(-101, -145), Pair(-39, -149), Pair(-24, -93),
        Pair(-40, -116), Pair(-49, -75), Pair(-43, -128), Pair(-34, -124), Pair(6, -40), Pair(-26, -147), Pair(5, -16), Pair(-26, -72),
        Pair(-96, -106), Pair(-16, -39), Pair(-39, -94), Pair(-34, -105), Pair(-17, -90), Pair(-83, -208), Pair(-2, -27), Pair(-71, -192)
      },
      { // Piece 5
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-18, 8), Pair(38, 31), Pair(-35, 38), Pair(-3, -5), Pair(-34, 29), Pair(23, 19), Pair(62, 29), Pair(39, 0),
        Pair(-72, -4), Pair(59, 35), Pair(-9, 13), Pair(-107, 34), Pair(-71, 35), Pair(18, 36), Pair(6, 34), Pair(-4, -6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }}
  }},
  {{ // Bucket 6
    {{ // Bucket 0
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(39, 121), Pair(283, 100), Pair(124, 289), Pair(120, 273), Pair(-3, 240), Pair(56, 184), Pair(79, -9), Pair(59, -40),
        Pair(28, 173), Pair(197, 175), Pair(36, 209), Pair(41, 224), Pair(14, 186), Pair(162, 102), Pair(127, 39), Pair(111, 0),
        Pair(-21, 61), Pair(-57, 101), Pair(188, 32), Pair(-18, 87), Pair(6, 30), Pair(-40, 28), Pair(-113, 22), Pair(-12, -28),
        Pair(-87, -7), Pair(-110, 103), Pair(19, 0), Pair(8, 34), Pair(-5, 8), Pair(-60, -7), Pair(-141, 12), Pair(-185, -37),
        Pair(-129, 28), Pair(-12, -32), Pair(57, -15), Pair(17, -27), Pair(-91, 8), Pair(-13, -36), Pair(-229, 4), Pair(-30, -44),
        Pair(-64, -36), Pair(-52, 33), Pair(-33, -29), Pair(-75, -11), Pair(-30, -18), Pair(-119, 0), Pair(-206, 51), Pair(-201, -5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(11, 54), Pair(16, 8), Pair(74, 31), Pair(-17, -94), Pair(15, 39), Pair(40, -81), Pair(19, 55), Pair(0, -16),
        Pair(7, 11), Pair(-15, 16), Pair(31, -70), Pair(84, 68), Pair(84, -17), Pair(28, -89), Pair(-36, -61), Pair(5, -6),
        Pair(-47, -55), Pair(-10, -39), Pair(0, -1), Pair(55, 9), Pair(233, -37), Pair(75, 77), Pair(60, 26), Pair(51, 44),
        Pair(73, 4), Pair(-22, -43), Pair(68, 47), Pair(-45, -2), Pair(20, 76), Pair(54, 94), Pair(119, 2), Pair(3, -7),
        Pair(51, 53), Pair(-8, -29), Pair(24, 54), Pair(-77, 12), Pair(77, 116), Pair(18, 27), Pair(-17, 37), Pair(-73, -26),
        Pair(-65, -28), Pair(14, -64), Pair(-102, 22), Pair(-4, -64), Pair(5, -25), Pair(-84, -78), Pair(35, -1), Pair(-5, -78),
        Pair(-20, -87), Pair(9, 16), Pair(-74, 63), Pair(-210, 34), Pair(-84, -58), Pair(20, 44), Pair(18, -1), Pair(-52, -85),
        Pair(2, 33), Pair(-20, -3), Pair(20, 56), Pair(-2, 8), Pair(0, -42), Pair(-83, -144), Pair(-113, -97), Pair(-17, -70)
      },
      { // Piece 2
        Pair(-25, -31), Pair(9, -15), Pair(-27, -25), Pair(18, -87), Pair(10, 64), Pair(-100, -106), Pair(-9, -42), Pair(5, 86),
        Pair(17, -39), Pair(-27, -39), Pair(-33, -41), Pair(13, -30), Pair(21, -32), Pair(-18, -81), Pair(23, 43), Pair(27, 12),
        Pair(-34, -68), Pair(27, -35), Pair(92, -74), Pair(-15, -15), Pair(103, -15), Pair(44, 80), Pair(0, -29), Pair(37, 35),
        Pair(20, -10), Pair(113, -93), Pair(36, -73), Pair(134, -74), Pair(-11, -63), Pair(-71, 29), Pair(-79, -103), Pair(81, -29),
        Pair(38, 92), Pair(40, -6), Pair(-35, 21), Pair(187, -87), Pair(64, -42), Pair(39, -110), Pair(-29, -33), Pair(-31, 15),
        Pair(30, 80), Pair(14, -72), Pair(68, 116), Pair(-54, -12), Pair(65, -56), Pair(-121, -38), Pair(-10, 43), Pair(17, -28),
        Pair(13, -58), Pair(110, 6), Pair(122, -119), Pair(-78, 27), Pair(-6, -48), Pair(2, 38), Pair(-63, -84), Pair(-21, -57),
        Pair(-54, -39), Pair(-11, 22), Pair(-188, 40), Pair(-9, 40), Pair(-15, -7), Pair(-117, -122), Pair(29, -97), Pair(-3, -74)
      },
      { // Piece 3
        Pair(-6, -22), Pair(86, 132), Pair(102, 186), Pair(69, 72), Pair(71, 184), Pair(-70, -66), Pair(-28, -50), Pair(9, -3),
        Pair(129, -29), Pair(147, -33), Pair(61, -15), Pair(-28, 47), Pair(214, -56), Pair(82, -41), Pair(46, 41), Pair(-23, -30),
        Pair(2, 39), Pair(7, -31), Pair(102, 44), Pair(54, 26), Pair(-40, 62), Pair(58, 93), Pair(-43, 28), Pair(-37, -20),
        Pair(-55, 29), Pair(-106, 43), Pair(-136, 31), Pair(-141, -54), Pair(-2, -27), Pair(34, 42), Pair(16, 61), Pair(0, 20),
        Pair(21, 3), Pair(4, -4), Pair(-45, 5), Pair(5, -9), Pair(98, -120), Pair(-11, -4), Pair(20, 36), Pair(1, -6),
        Pair(-43, -74), Pair(-12, 62), Pair(-54, -51), Pair(-74, 16), Pair(-4, -53), Pair(51, -21), Pair(42, 8), Pair(-56, 24),
        Pair(-102, 28), Pair(-38, 45), Pair(-22, -25), Pair(-122, 11), Pair(-66, -92), Pair(35, 22), Pair(-81, 20), Pair(26, 15),
        Pair(-306, 11), Pair(-239, 81), Pair(-66, 17), Pair(-174, 43), Pair(55, -22), Pair(-122, 37), Pair(-52, 13), Pair(-318, 61)
      },
      { // Piece 4
        Pair(-82, -65), Pair(-18, -54), Pair(20, -48), Pair(21, -11), Pair(1, -90), Pair(-95, -61), Pair(-34, -26), Pair(3, 6),
        Pair(-34, -159), Pair(-108, -77), Pair(-24, 30), Pair(-56, 4), Pair(28, 53), Pair(-45, 79), Pair(16, -33), Pair(-40, -22),
        Pair(5, -31), Pair(70, 87), Pair(22, 21), Pair(20, 30), Pair(12, 100), Pair(5, 21), Pair(75, -27), Pair(49, -119),
        Pair(-60, -91), Pair(-110, -67), Pair(-34, 54), Pair(-8, -36), Pair(42, -18), Pair(-13, -12), Pair(-35, -1), Pair(-42, -15),
        Pair(-47, -113), Pair(103, 78), Pair(-82, -23), Pair(53, 84), Pair(74, -60), Pair(26, 78), Pair(16, 95), Pair(-57, -116),
        Pair(-53, -113), Pair(-10, 11), Pair(-41, 37), Pair(-52, -31), Pair(-13, -30), Pair(-103, -35), Pair(54, 90), Pair(-12, 3),
        Pair(55, -49), Pair(-100, -165), Pair(2, -17), Pair(-123, -89), Pair(-62, -70), Pair(-64, -80), Pair(-17, -25), Pair(-19, -26),
        Pair(-76, -76), Pair(-110, -148), Pair(-19, -20), Pair(-149, -104), Pair(-35, -80), Pair(-149, -110), Pair(-26, -23), Pair(-135, -122)
      },
      { // Piece 5
        Pair(11, -113), Pair(80, -19), Pair(100, -48), Pair(133, -71), Pair(-43, -18), Pair(141, -34), Pair(-73, 42), Pair(-32, -111),
        Pair(-68, -1), Pair(50, 3), Pair(32, -8), Pair(42, -13), Pair(-19, 15), Pair(-113, 25), Pair(42, 15), Pair(-22, -4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 1
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(75, 135), Pair(72, 231), Pair(189, 57), Pair(101, 87), Pair(81, 34), Pair(99, 18), Pair(41, 197), Pair(64, 130),
        Pair(2, 128), Pair(90, 157), Pair(104, 49), Pair(113, 62), Pair(89, 83), Pair(113, 78), Pair(238, 98), Pair(25, 121),
        Pair(7, 49), Pair(-153, 70), Pair(5, 59), Pair(21, 65), Pair(-64, -10), Pair(7, 25), Pair(-125, 43), Pair(-88, 5),
        Pair(-149, 13), Pair(-55, 64), Pair(22, 15), Pair(102, -6), Pair(6, -50), Pair(-94, -27), Pair(-110, 36), Pair(-171, 24),
        Pair(-147, -50), Pair(10, 44), Pair(-76, -37), Pair(-30, 37), Pair(-208, -24), Pair(-139, 5), Pair(-184, 0), Pair(-121, -35),
        Pair(-175, 6), Pair(-151, 79), Pair(-98, -14), Pair(-10, -34), Pair(-55, -25), Pair(-148, -6), Pair(-129, 45), Pair(-174, 42),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(31, -78), Pair(15, 40), Pair(-37, -41), Pair(-35, -101), Pair(-12, -104), Pair(14, 17), Pair(-2, -18), Pair(-56, -142),
        Pair(18, 52), Pair(-29, -27), Pair(47, 45), Pair(-7, -29), Pair(37, 4), Pair(14, 3), Pair(-57, -174), Pair(-3, 15),
        Pair(-32, -36), Pair(-8, 18), Pair(106, 12), Pair(127, 40), Pair(35, -16), Pair(73, 59), Pair(41, 10), Pair(-63, -145),
        Pair(-8, -65), Pair(39, 58), Pair(118, 68), Pair(5, 66), Pair(72, 80), Pair(-17, 51), Pair(100, 41), Pair(-33, 27),
        Pair(-19, -6), Pair(1, -1), Pair(42, 3), Pair(-17, 40), Pair(66, -10), Pair(20, 16), Pair(11, -1), Pair(4, 38),
        Pair(-6, -73), Pair(-67, -147), Pair(18, -30), Pair(20, 8), Pair(32, 57), Pair(-7, 7), Pair(12, -52), Pair(-20, -64),
        Pair(-16, -72), Pair(3, 13), Pair(-14, -8), Pair(-14, -8), Pair(-85, -23), Pair(0, -23), Pair(-14, -38), Pair(-17, -85),
        Pair(-14, -14), Pair(-79, 75), Pair(14, -10), Pair(-8, 67), Pair(-16, -86), Pair(-53, -145), Pair(-78, -107), Pair(-11, -57)
      },
      { // Piece 2
        Pair(-2, -61), Pair(11, -10), Pair(24, -41), Pair(14, -133), Pair(-23, -89), Pair(-21, -135), Pair(-15, -215), Pair(-29, -175),
        Pair(-38, -212), Pair(53, -4), Pair(4, 39), Pair(17, -126), Pair(43, 43), Pair(10, -6), Pair(69, -55), Pair(-42, -135),
        Pair(-10, 57), Pair(39, -34), Pair(-20, -103), Pair(36, -54), Pair(98, -25), Pair(108, -100), Pair(-55, -38), Pair(-29, -94),
        Pair(-36, -33), Pair(87, -21), Pair(116, -42), Pair(-17, -33), Pair(14, -77), Pair(-13, -74), Pair(112, -31), Pair(18, -7),
        Pair(-38, -65), Pair(-48, -36), Pair(29, -75), Pair(21, -23), Pair(-26, -81), Pair(-7, -34), Pair(41, -46), Pair(19, 24),
        Pair(8, 14), Pair(11, -45), Pair(-9, -1), Pair(20, 25), Pair(-80, 2), Pair(-22, -87), Pair(-46, -62), Pair(7, 95),
        Pair(41, 19), Pair(65, 7), Pair(28, -47), Pair(1, -5), Pair(49, -37), Pair(-35, -5), Pair(-67, -57), Pair(34, 23),
        Pair(-5, -120), Pair(-9, -6), Pair(-126, -87), Pair(-11, 72), Pair(-40, -32), Pair(-8, -70), Pair(-5, -93), Pair(-13, -111)
      },
      { // Piece 3
        Pair(86, 62), Pair(33, 44), Pair(-25, 51), Pair(52, 96), Pair(-5, -7), Pair(-61, -16), Pair(13, 15), Pair(17, -23),
        Pair(233, -74), Pair(182, -29), Pair(173, -50), Pair(134, 17), Pair(40, 31), Pair(93, -6), Pair(51, 2), Pair(10, -44),
        Pair(17, 26), Pair(86, 21), Pair(-53, 10), Pair(34, 31), Pair(110, 43), Pair(150, -23), Pair(-1, -35), Pair(28, 38),
        Pair(44, 52), Pair(42, -26), Pair(-48, -19), Pair(22, -4), Pair(11, 34), Pair(49, -1), Pair(8, 14), Pair(-45, -69),
        Pair(-40, -76), Pair(26, 22), Pair(21, -8), Pair(-143, -20), Pair(49, 10), Pair(61, -7), Pair(-5, 59), Pair(11, 40),
        Pair(35, -48), Pair(-48, 56), Pair(11, -10), Pair(17, 59), Pair(21, 56), Pair(-24, -21), Pair(26, 28), Pair(-8, -23),
        Pair(-43, -55), Pair(-25, 50), Pair(2, -68), Pair(17, -47), Pair(-81, -17), Pair(24, 35), Pair(2, 63), Pair(7, 63),
        Pair(-159, 6), Pair(-1, -26), Pair(-125, -2), Pair(-61, -111), Pair(19, -24), Pair(-7, 20), Pair(-46, 16), Pair(-53, 49)
      },
      { // Piece 4
        Pair(-54, -105), Pair(-54, -111), Pair(17, 39), Pair(-22, 2), Pair(1, 3), Pair(-20, -47), Pair(-27, -49), Pair(32, 57),
        Pair(-31, -108), Pair(21, 10), Pair(47, -7), Pair(-25, -66), Pair(1, 52), Pair(25, 43), Pair(1, -92), Pair(-116, -147),
        Pair(9, -2), Pair(-8, -38), Pair(103, 122), Pair(-8, -30), Pair(23, 41), Pair(27, 44), Pair(31, 41), Pair(8, 8),
        Pair(32, 2), Pair(59, 59), Pair(-4, -58), Pair(65, -31), Pair(11, -35), Pair(-10, -39), Pair(6, 9), Pair(-9, -13),
        Pair(-24, -29), Pair(-36, -30), Pair(-18, -62), Pair(-26, -63), Pair(38, 78), Pair(-27, -66), Pair(-74, -99), Pair(-45, -72),
        Pair(-46, -20), Pair(-62, -98), Pair(23, 45), Pair(-25, -44), Pair(-62, -58), Pair(8, 23), Pair(9, -34), Pair(-18, -32),
        Pair(-58, -32), Pair(-23, -22), Pair(45, 87), Pair(-56, -61), Pair(-14, -23), Pair(-15, -31), Pair(39, 37), Pair(-17, -26),
        Pair(-20, -56), Pair(-62, -90), Pair(-8, -5), Pair(-156, -101), Pair(-14, -23), Pair(-11, -13), Pair(-10, -48), Pair(0, 0)
      },
      { // Piece 5
        Pair(21, -209), Pair(-5, -15), Pair(-109, -12), Pair(104, 37), Pair(-5, 28), Pair(-76, 89), Pair(18, 48), Pair(17, -137),
        Pair(-32, -43), Pair(66, 13), Pair(16, 11), Pair(34, -13), Pair(79, 54), Pair(105, 44), Pair(38, 35), Pair(34, -53),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 2
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(327, 122), Pair(373, 144), Pair(298, 183), Pair(185, 180), Pair(21, 214), Pair(155, 167), Pair(80, 185), Pair(399, 80),
        Pair(209, 106), Pair(248, 160), Pair(268, 138), Pair(255, 87), Pair(208, 71), Pair(115, 79), Pair(242, 103), Pair(216, 47),
        Pair(-42, 86), Pair(33, 84), Pair(114, 14), Pair(24, 28), Pair(2, 15), Pair(5, 10), Pair(-55, 31), Pair(-7, -21),
        Pair(-142, 27), Pair(-40, 27), Pair(47, -33), Pair(-76, 19), Pair(-83, 3), Pair(-96, 1), Pair(-86, 22), Pair(-133, -2),
        Pair(-163, 30), Pair(-22, 26), Pair(-65, 22), Pair(-57, -23), Pair(-39, -31), Pair(2, -39), Pair(-97, 18), Pair(-152, -7),
        Pair(-204, 59), Pair(-182, 32), Pair(-36, -6), Pair(-64, 9), Pair(-125, 27), Pair(-113, 15), Pair(-182, 42), Pair(-163, 20),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-57, -128), Pair(5, 13), Pair(-16, -20), Pair(-31, -97), Pair(6, 6), Pair(54, 18), Pair(-12, -112), Pair(-6, -40),
        Pair(1, -87), Pair(28, -34), Pair(-5, -27), Pair(86, -3), Pair(34, -18), Pair(-103, -26), Pair(-9, -8), Pair(4, -114),
        Pair(-23, -6), Pair(-23, -47), Pair(36, 16), Pair(88, -6), Pair(180, -5), Pair(43, 20), Pair(109, -12), Pair(51, -28),
        Pair(-3, -31), Pair(-90, -91), Pair(49, 12), Pair(105, -23), Pair(24, 26), Pair(-19, 51), Pair(121, -93), Pair(65, -49),
        Pair(-33, 15), Pair(16, 5), Pair(-38, 15), Pair(-53, 1), Pair(147, 7), Pair(4, 19), Pair(0, 8), Pair(-14, -16),
        Pair(-15, -172), Pair(-46, -45), Pair(-89, -11), Pair(-124, -19), Pair(78, -71), Pair(-18, -56), Pair(-62, -92), Pair(10, 30),
        Pair(-3, -89), Pair(-102, -43), Pair(7, -68), Pair(-136, -37), Pair(-7, -49), Pair(-14, -52), Pair(-22, 2), Pair(-2, 14),
        Pair(-78, -149), Pair(-53, 27), Pair(-78, 11), Pair(-58, -20), Pair(21, 17), Pair(-52, -55), Pair(-127, -84), Pair(-27, -91)
      },
      { // Piece 2
        Pair(-26, -147), Pair(-16, -135), Pair(-41, -77), Pair(83, -73), Pair(-34, -55), Pair(55, -93), Pair(37, -127), Pair(-46, -45),
        Pair(-54, -161), Pair(63, -155), Pair(15, -119), Pair(72, -82), Pair(125, 20), Pair(103, -72), Pair(52, -93), Pair(-1, -61),
        Pair(-58, -66), Pair(22, -54), Pair(122, -105), Pair(34, -62), Pair(49, -67), Pair(226, 17), Pair(116, -33), Pair(-106, -48),
        Pair(-1, -102), Pair(8, -49), Pair(101, -87), Pair(154, -100), Pair(174, -49), Pair(75, -116), Pair(-39, -48), Pair(97, -90),
        Pair(53, -78), Pair(168, -80), Pair(46, -86), Pair(244, -88), Pair(141, -119), Pair(180, -133), Pair(-44, -65), Pair(92, -48),
        Pair(-49, -53), Pair(146, -74), Pair(-16, -27), Pair(116, -88), Pair(53, -85), Pair(65, -74), Pair(-44, -57), Pair(-62, -103),
        Pair(-56, 12), Pair(-124, -60), Pair(63, -108), Pair(33, -64), Pair(12, -76), Pair(137, -107), Pair(-48, -106), Pair(-25, -109),
        Pair(31, -142), Pair(-7, -48), Pair(-59, -44), Pair(-138, -62), Pair(-17, -65), Pair(-19, -81), Pair(-19, -86), Pair(41, -104)
      },
      { // Piece 3
        Pair(63, -98), Pair(17, -24), Pair(106, -45), Pair(-58, 16), Pair(148, -15), Pair(66, -31), Pair(8, -89), Pair(215, -55),
        Pair(-38, -93), Pair(-19, -53), Pair(-46, -44), Pair(83, -137), Pair(15, -73), Pair(17, -69), Pair(31, -64), Pair(-6, -11),
        Pair(-35, -75), Pair(20, -42), Pair(-103, -48), Pair(-2, -26), Pair(113, -73), Pair(15, -34), Pair(-6, -78), Pair(38, -72),
        Pair(-85, -27), Pair(-89, -10), Pair(-5, -94), Pair(-183, -27), Pair(53, -34), Pair(54, -100), Pair(95, -96), Pair(34, -86),
        Pair(-8, -76), Pair(64, -62), Pair(-20, -43), Pair(-5, -68), Pair(-31, -92), Pair(-26, -46), Pair(71, -50), Pair(-76, -45),
        Pair(-100, -97), Pair(-80, -77), Pair(-7, -82), Pair(-121, -102), Pair(-168, -47), Pair(9, -74), Pair(105, -71), Pair(-28, -87),
        Pair(-62, -110), Pair(28, -61), Pair(-18, -138), Pair(-181, -28), Pair(9, -42), Pair(-86, -67), Pair(-86, -97), Pair(-95, -59),
        Pair(-330, -43), Pair(-106, -36), Pair(-55, -121), Pair(-212, -63), Pair(-195, -15), Pair(-55, -69), Pair(-90, -110), Pair(-151, -62)
      },
      { // Piece 4
        Pair(10, -220), Pair(-194, -7), Pair(-36, -99), Pair(-21, -44), Pair(-12, -90), Pair(-156, -73), Pair(-43, -70), Pair(-111, -121),
        Pair(14, 26), Pair(-56, -48), Pair(-17, -55), Pair(23, -19), Pair(-2, -58), Pair(-47, 30), Pair(-42, -36), Pair(41, 3),
        Pair(-87, -66), Pair(-3, -65), Pair(-9, -17), Pair(-37, -27), Pair(13, -46), Pair(-9, 9), Pair(-65, -116), Pair(-107, -154),
        Pair(-3, -37), Pair(40, -19), Pair(10, 30), Pair(-12, -10), Pair(-30, -19), Pair(-10, -14), Pair(-11, 12), Pair(-11, -96),
        Pair(-73, -138), Pair(-26, -73), Pair(-60, -112), Pair(-39, -34), Pair(-105, -43), Pair(-9, -62), Pair(-80, -72), Pair(-52, -111),
        Pair(-28, -154), Pair(-10, -40), Pair(-38, -62), Pair(-68, -99), Pair(-154, -105), Pair(-114, -145), Pair(-37, -55), Pair(-75, -145),
        Pair(-41, -13), Pair(-67, -38), Pair(-66, -8), Pair(-41, -11), Pair(-134, -143), Pair(40, 14), Pair(-27, -57), Pair(-21, -33),
        Pair(-106, -127), Pair(-120, -141), Pair(-75, -123), Pair(-127, -43), Pair(-100, -89), Pair(-42, -49), Pair(-60, -172), Pair(-87, -147)
      },
      { // Piece 5
        Pair(178, -197), Pair(-6, -55), Pair(30, -23), Pair(-24, -12), Pair(-51, -38), Pair(16, -3), Pair(-104, 31), Pair(126, -167),
        Pair(-17, -60), Pair(44, 10), Pair(81, 8), Pair(-137, 49), Pair(-31, 23), Pair(26, 12), Pair(25, 30), Pair(16, -27),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 3
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(18, 272), Pair(71, 315), Pair(194, 228), Pair(216, 217), Pair(-21, 237), Pair(89, 236), Pair(17, 239), Pair(-39, 249),
        Pair(127, 139), Pair(127, 112), Pair(332, 51), Pair(116, 109), Pair(149, 67), Pair(180, 58), Pair(110, 113), Pair(69, 118),
        Pair(-41, 56), Pair(-21, 64), Pair(23, 25), Pair(35, -27), Pair(52, -17), Pair(103, 12), Pair(-41, 54), Pair(-56, 38),
        Pair(-60, 16), Pair(-156, 37), Pair(-43, 2), Pair(-14, 41), Pair(40, -11), Pair(-64, 6), Pair(-34, 20), Pair(-135, 4),
        Pair(-122, 3), Pair(-95, 15), Pair(-55, 9), Pair(11, 5), Pair(-92, 3), Pair(118, -28), Pair(-134, 2), Pair(-120, 13),
        Pair(-154, 66), Pair(-187, 18), Pair(-20, 28), Pair(21, 69), Pair(2, -25), Pair(-63, 16), Pair(-125, 24), Pair(-150, 17),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-78, -206), Pair(-66, -62), Pair(-22, -85), Pair(29, -30), Pair(-41, -27), Pair(41, -92), Pair(35, -15), Pair(-29, -219),
        Pair(-28, -36), Pair(-77, -56), Pair(-56, -80), Pair(-43, -13), Pair(48, -4), Pair(27, -38), Pair(-21, -49), Pair(-13, -102),
        Pair(-81, -144), Pair(35, -13), Pair(38, -14), Pair(65, 3), Pair(125, -29), Pair(74, -59), Pair(-15, -12), Pair(-9, -49),
        Pair(24, -56), Pair(17, -67), Pair(43, -17), Pair(-32, 28), Pair(98, 1), Pair(3, -63), Pair(18, 15), Pair(-5, -89),
        Pair(-8, -95), Pair(-117, -29), Pair(15, 10), Pair(-11, -61), Pair(174, -56), Pair(28, 1), Pair(-5, -71), Pair(-10, -63),
        Pair(-57, -69), Pair(14, 2), Pair(-27, -45), Pair(26, -3), Pair(16, 6), Pair(-11, -11), Pair(-38, -48), Pair(-29, -50),
        Pair(33, -62), Pair(-30, -29), Pair(-74, -147), Pair(-38, -68), Pair(-26, -62), Pair(-64, -59), Pair(-52, -120), Pair(60, 30),
        Pair(-38, -160), Pair(0, -92), Pair(7, -13), Pair(-18, -121), Pair(6, -108), Pair(-43, -32), Pair(-32, -71), Pair(-4, -44)
      },
      { // Piece 2
        Pair(13, -123), Pair(29, -133), Pair(55, -129), Pair(136, -99), Pair(-98, -75), Pair(-45, -74), Pair(23, -81), Pair(15, -60),
        Pair(-83, -159), Pair(75, -107), Pair(20, -137), Pair(65, -111), Pair(-40, -118), Pair(14, -102), Pair(35, -111), Pair(-18, -146),
        Pair(-2, -59), Pair(-11, -62), Pair(47, -72), Pair(-18, -60), Pair(75, -65), Pair(91, -101), Pair(12, -106), Pair(-105, -116),
        Pair(-52, -62), Pair(109, -57), Pair(224, -123), Pair(64, -102), Pair(106, -110), Pair(-55, -83), Pair(89, -86), Pair(42, -69),
        Pair(-24, -116), Pair(23, -71), Pair(77, -107), Pair(132, -85), Pair(107, -94), Pair(105, -86), Pair(-37, -113), Pair(104, 16),
        Pair(18, -82), Pair(33, -53), Pair(-3, -41), Pair(94, -110), Pair(59, -92), Pair(-1, -40), Pair(3, -112), Pair(13, -98),
        Pair(-8, -75), Pair(35, -88), Pair(38, -69), Pair(21, -122), Pair(108, -115), Pair(-14, -92), Pair(-20, -108), Pair(32, -91),
        Pair(-38, -47), Pair(-4, -84), Pair(-141, -102), Pair(-53, -85), Pair(-68, -98), Pair(-67, -78), Pair(-43, -168), Pair(-45, -94)
      },
      { // Piece 3
        Pair(110, -102), Pair(-91, -71), Pair(131, -132), Pair(33, -96), Pair(16, -88), Pair(49, -105), Pair(-140, -69), Pair(80, -98),
        Pair(59, -87), Pair(-5, -60), Pair(42, -79), Pair(42, -73), Pair(172, -141), Pair(92, -118), Pair(40, -128), Pair(131, -145),
        Pair(-46, -84), Pair(-151, -105), Pair(-30, -87), Pair(10, -121), Pair(7, -156), Pair(9, -52), Pair(-6, -100), Pair(-19, -108),
        Pair(21, -100), Pair(74, -122), Pair(51, -101), Pair(-45, -61), Pair(9, -65), Pair(114, -118), Pair(153, -130), Pair(-1, -105),
        Pair(-110, -110), Pair(-69, -65), Pair(-16, -122), Pair(15, -112), Pair(104, -146), Pair(38, -93), Pair(-12, -106), Pair(-44, -132),
        Pair(-73, -148), Pair(-35, -122), Pair(19, -145), Pair(-31, -127), Pair(-19, -96), Pair(-111, -98), Pair(8, -75), Pair(-8, -130),
        Pair(-96, -167), Pair(-78, -99), Pair(-25, -135), Pair(-37, -105), Pair(-89, -113), Pair(-68, -140), Pair(-92, -152), Pair(-96, -177),
        Pair(-148, -113), Pair(-105, -170), Pair(-36, -169), Pair(-72, -97), Pair(17, -170), Pair(-139, -88), Pair(-56, -111), Pair(-213, -139)
      },
      { // Piece 4
        Pair(-35, -229), Pair(-69, -45), Pair(-70, -158), Pair(-4, -78), Pair(-52, -69), Pair(9, -122), Pair(47, -136), Pair(-29, -202),
        Pair(58, -23), Pair(-84, -4), Pair(27, -65), Pair(-12, -29), Pair(33, 20), Pair(-10, -96), Pair(-29, -34), Pair(-1, -27),
        Pair(-4, 6), Pair(-17, -45), Pair(-3, -55), Pair(-1, 9), Pair(14, 1), Pair(80, 96), Pair(77, 114), Pair(-5, -7),
        Pair(-19, -57), Pair(-71, -36), Pair(-16, -45), Pair(-31, 12), Pair(-55, -78), Pair(-36, -43), Pair(-18, -21), Pair(-34, -68),
        Pair(6, 10), Pair(-30, -117), Pair(-21, -12), Pair(8, -29), Pair(-128, -8), Pair(38, 35), Pair(-46, -84), Pair(-29, -82),
        Pair(34, 36), Pair(13, 15), Pair(-38, -44), Pair(5, 41), Pair(-10, -37), Pair(-28, -65), Pair(-66, -60), Pair(32, 23),
        Pair(-30, -54), Pair(-62, -97), Pair(-58, -55), Pair(-24, -67), Pair(-62, -101), Pair(-119, -207), Pair(-27, -45), Pair(-19, -23),
        Pair(-26, -19), Pair(-70, -161), Pair(-19, -32), Pair(50, 44), Pair(-113, -203), Pair(-72, -102), Pair(-78, -154), Pair(-73, -149)
      },
      { // Piece 5
        Pair(42, -156), Pair(199, -92), Pair(-43, 3), Pair(34, -17), Pair(32, -28), Pair(-69, 6), Pair(-25, -20), Pair(-5, -116),
        Pair(37, -48), Pair(65, 28), Pair(13, 22), Pair(50, 21), Pair(19, 18), Pair(-7, 24), Pair(91, 19), Pair(-124, -15),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 4
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-46, 270), Pair(74, 249), Pair(63, 222), Pair(7, 291), Pair(73, 246), Pair(-13, 277), Pair(47, 283), Pair(45, 247),
        Pair(3, 175), Pair(52, 213), Pair(173, 142), Pair(-68, 162), Pair(-47, 158), Pair(42, 145), Pair(16, 208), Pair(-3, 172),
        Pair(-41, 42), Pair(-9, 73), Pair(42, 12), Pair(-60, 23), Pair(-74, -7), Pair(36, 6), Pair(-59, 38), Pair(-38, 49),
        Pair(-128, 27), Pair(-65, 21), Pair(-18, 12), Pair(29, -26), Pair(-32, 2), Pair(-89, -8), Pair(56, -10), Pair(-178, 29),
        Pair(-169, 32), Pair(-155, 14), Pair(16, 1), Pair(-38, 66), Pair(-146, 19), Pair(-27, 4), Pair(-105, 26), Pair(-214, 44),
        Pair(-146, 51), Pair(-160, 36), Pair(-43, 0), Pair(-6, 53), Pair(-125, 36), Pair(-68, 27), Pair(-25, 18), Pair(-191, 54),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-61, -93), Pair(10, -147), Pair(9, -101), Pair(-14, -106), Pair(-61, -72), Pair(-14, -101), Pair(-35, -88), Pair(-39, -111),
        Pair(-15, -198), Pair(13, -93), Pair(-39, -59), Pair(-72, -53), Pair(26, -70), Pair(16, -69), Pair(-13, -77), Pair(-24, -64),
        Pair(-20, -86), Pair(-27, -73), Pair(-61, -62), Pair(-35, -45), Pair(234, -60), Pair(20, -44), Pair(33, -80), Pair(-15, -72),
        Pair(-8, -130), Pair(-32, -7), Pair(-18, -49), Pair(9, -10), Pair(93, -50), Pair(28, -32), Pair(-30, -10), Pair(-64, -73),
        Pair(-46, -116), Pair(-46, -77), Pair(-37, -34), Pair(25, -66), Pair(66, -5), Pair(-33, -44), Pair(-100, -66), Pair(-50, -18),
        Pair(-23, -77), Pair(12, -70), Pair(-94, -59), Pair(28, -15), Pair(15, -56), Pair(36, -56), Pair(-49, -77), Pair(-76, -22),
        Pair(-7, -38), Pair(-29, -79), Pair(-37, -84), Pair(-35, -38), Pair(4, -64), Pair(8, -96), Pair(-53, -46), Pair(5, -55),
        Pair(-26, -66), Pair(-54, -75), Pair(-58, -25), Pair(50, -50), Pair(-4, -65), Pair(-26, -67), Pair(9, -14), Pair(-10, -56)
      },
      { // Piece 2
        Pair(-72, -72), Pair(-21, -51), Pair(-19, -63), Pair(47, -46), Pair(-64, -48), Pair(-20, -66), Pair(-94, -116), Pair(25, 7),
        Pair(17, -117), Pair(2, -49), Pair(-3, -107), Pair(-67, -87), Pair(-20, -32), Pair(6, -107), Pair(22, -38), Pair(15, -20),
        Pair(-5, -89), Pair(113, -92), Pair(84, -92), Pair(27, -55), Pair(53, -81), Pair(14, -82), Pair(35, -77), Pair(20, -56),
        Pair(-39, -29), Pair(-80, -35), Pair(-84, -26), Pair(75, -95), Pair(11, -26), Pair(-57, -63), Pair(41, -41), Pair(-12, -136),
        Pair(2, -124), Pair(59, -57), Pair(-39, -87), Pair(121, -96), Pair(42, -64), Pair(-3, -68), Pair(11, -116), Pair(71, -118),
        Pair(-15, -65), Pair(-57, -68), Pair(2, -73), Pair(-59, -32), Pair(-23, -83), Pair(22, -68), Pair(23, -115), Pair(-20, -92),
        Pair(-71, -85), Pair(-6, -88), Pair(-81, -122), Pair(-38, -107), Pair(-59, -78), Pair(-24, -82), Pair(-155, -63), Pair(23, -70),
        Pair(3, -21), Pair(6, -48), Pair(29, -10), Pair(-15, -118), Pair(-1, -72), Pair(-55, -90), Pair(-20, -11), Pair(-32, -13)
      },
      { // Piece 3
        Pair(-15, -115), Pair(71, -154), Pair(-72, -83), Pair(28, -93), Pair(13, -94), Pair(-47, -91), Pair(22, -135), Pair(125, -186),
        Pair(84, -166), Pair(-27, -154), Pair(-26, -141), Pair(10, -102), Pair(71, -84), Pair(-65, -96), Pair(13, -135), Pair(-50, -160),
        Pair(45, -142), Pair(130, -157), Pair(85, -121), Pair(171, -128), Pair(-14, -127), Pair(109, -93), Pair(27, -109), Pair(7, -136),
        Pair(-7, -150), Pair(-16, -109), Pair(-19, -132), Pair(-3, -126), Pair(-78, -69), Pair(-20, -143), Pair(-19, -126), Pair(-79, -108),
        Pair(-24, -123), Pair(7, -159), Pair(89, -134), Pair(36, -118), Pair(46, -87), Pair(-3, -73), Pair(37, -120), Pair(34, -157),
        Pair(-41, -172), Pair(-17, -137), Pair(48, -154), Pair(-28, -150), Pair(-49, -89), Pair(-46, -133), Pair(-47, -158), Pair(-53, -164),
        Pair(-131, -164), Pair(51, -165), Pair(44, -152), Pair(147, -212), Pair(45, -135), Pair(81, -184), Pair(73, -91), Pair(-120, -153),
        Pair(-72, -154), Pair(3, -171), Pair(71, -169), Pair(55, -194), Pair(-98, -164), Pair(-73, -144), Pair(-19, -164), Pair(-40, -145)
      },
      { // Piece 4
        Pair(-147, -197), Pair(-98, -140), Pair(-80, -125), Pair(9, -89), Pair(142, -136), Pair(24, -43), Pair(-64, -80), Pair(7, -215),
        Pair(-20, -92), Pair(-3, -132), Pair(-2, 1), Pair(10, -61), Pair(-63, -42), Pair(-17, -2), Pair(-61, -127), Pair(-90, -96),
        Pair(-11, -93), Pair(-58, -125), Pair(-103, -101), Pair(51, 13), Pair(12, -52), Pair(-23, -25), Pair(-34, -75), Pair(-73, -76),
        Pair(-22, -42), Pair(56, 79), Pair(17, 13), Pair(12, 6), Pair(-6, -17), Pair(-1, -12), Pair(29, 56), Pair(0, 5),
        Pair(-24, -67), Pair(-45, -115), Pair(56, 17), Pair(45, -1), Pair(29, 11), Pair(-2, 54), Pair(2, -20), Pair(-5, -37),
        Pair(43, 3), Pair(60, 82), Pair(-33, -76), Pair(-11, -61), Pair(-49, -66), Pair(-1, 11), Pair(-40, -49), Pair(-50, -43),
        Pair(44, 19), Pair(-59, -153), Pair(-57, -130), Pair(3, -19), Pair(6, 44), Pair(-8, -30), Pair(-16, -35), Pair(-90, -139),
        Pair(-89, -160), Pair(-31, -67), Pair(-20, -41), Pair(-33, -94), Pair(-21, -88), Pair(-26, -90), Pair(-53, -86), Pair(-66, -108)
      },
      { // Piece 5
        Pair(-38, -80), Pair(57, -70), Pair(-74, -41), Pair(-46, 16), Pair(70, -19), Pair(10, -35), Pair(24, -18), Pair(-55, -138),
        Pair(-74, -42), Pair(73, 7), Pair(41, 17), Pair(63, 11), Pair(61, 15), Pair(34, 13), Pair(-2, 34), Pair(-21, -32),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 5
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-106, 273), Pair(128, 260), Pair(127, 274), Pair(126, 234), Pair(163, 272), Pair(77, 277), Pair(-26, 285), Pair(-44, 268),
        Pair(-193, 241), Pair(94, 200), Pair(82, 171), Pair(-31, 202), Pair(93, 134), Pair(4, 195), Pair(-42, 239), Pair(-171, 229),
        Pair(-132, 97), Pair(-87, 85), Pair(24, 75), Pair(-10, 45), Pair(28, 33), Pair(-106, 78), Pair(-64, 74), Pair(-109, 82),
        Pair(-146, 22), Pair(-94, 32), Pair(38, -13), Pair(85, -26), Pair(-18, -3), Pair(-98, -10), Pair(-35, 21), Pair(-186, 45),
        Pair(-83, 21), Pair(-22, -3), Pair(5, -16), Pair(-68, 57), Pair(-40, -26), Pair(-6, -23), Pair(-110, 10), Pair(-108, 14),
        Pair(-213, 55), Pair(-126, 44), Pair(-128, 28), Pair(-26, -19), Pair(-138, -37), Pair(-132, 23), Pair(-72, 41), Pair(-74, 35),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-18, -136), Pair(-69, -129), Pair(2, -123), Pair(-10, -57), Pair(-26, -37), Pair(-14, -85), Pair(8, -159), Pair(17, 76),
        Pair(-15, -102), Pair(-3, -152), Pair(-9, -38), Pair(1, -93), Pair(-10, -115), Pair(-118, -57), Pair(-29, -130), Pair(-19, -142),
        Pair(4, -158), Pair(-60, -91), Pair(67, -83), Pair(36, -32), Pair(38, -103), Pair(1, -51), Pair(76, -76), Pair(-26, -120),
        Pair(-40, -141), Pair(-50, -85), Pair(26, -112), Pair(27, -38), Pair(0, -56), Pair(-67, -39), Pair(34, -87), Pair(-29, -136),
        Pair(-18, -117), Pair(-34, -77), Pair(46, -60), Pair(-7, -36), Pair(35, -65), Pair(-41, -139), Pair(-43, -106), Pair(-11, -134),
        Pair(-20, -137), Pair(-40, -87), Pair(-47, -72), Pair(33, -72), Pair(-31, -55), Pair(-102, -44), Pair(10, -96), Pair(-22, -94),
        Pair(-54, -151), Pair(0, -21), Pair(-18, -78), Pair(-21, -50), Pair(-61, -55), Pair(4, -104), Pair(-2, -133), Pair(-47, -84),
        Pair(-26, -148), Pair(9, -88), Pair(-24, -163), Pair(-17, -102), Pair(-6, -38), Pair(-59, -39), Pair(-29, -104), Pair(2, -82)
      },
      { // Piece 2
        Pair(-4, -50), Pair(21, -79), Pair(-75, -114), Pair(20, -90), Pair(-79, -118), Pair(-49, -100), Pair(-67, -134), Pair(15, -105),
        Pair(-85, -109), Pair(23, -107), Pair(-43, -85), Pair(2, -130), Pair(4, -86), Pair(28, -106), Pair(-12, -89), Pair(52, -80),
        Pair(-92, -105), Pair(-62, -61), Pair(22, -109), Pair(68, -87), Pair(13, -124), Pair(-83, -53), Pair(-55, -74), Pair(9, -100),
        Pair(-14, 19), Pair(-87, -40), Pair(-12, -70), Pair(-19, -74), Pair(78, -45), Pair(146, -114), Pair(19, -42), Pair(-17, -75),
        Pair(-12, -22), Pair(-1, -63), Pair(11, -40), Pair(14, -16), Pair(116, -63), Pair(-32, -15), Pair(-8, 0), Pair(-54, -51),
        Pair(-4, -58), Pair(-4, -85), Pair(-27, -39), Pair(-44, -69), Pair(-26, -85), Pair(15, -139), Pair(13, -59), Pair(-49, -131),
        Pair(-20, 14), Pair(-6, -67), Pair(-51, -159), Pair(48, -55), Pair(-65, -69), Pair(-17, -60), Pair(-10, -104), Pair(-22, 22),
        Pair(-29, -59), Pair(38, 19), Pair(6, -105), Pair(-21, -130), Pair(-95, -94), Pair(-41, -56), Pair(-58, -105), Pair(-20, -89)
      },
      { // Piece 3
        Pair(227, -246), Pair(67, -202), Pair(74, -174), Pair(-30, -173), Pair(40, -184), Pair(41, -142), Pair(112, -208), Pair(105, -203),
        Pair(-30, -255), Pair(-15, -173), Pair(13, -183), Pair(62, -179), Pair(73, -160), Pair(79, -198), Pair(-26, -216), Pair(-11, -224),
        Pair(-33, -185), Pair(106, -180), Pair(35, -183), Pair(-24, -196), Pair(73, -145), Pair(65, -205), Pair(28, -195), Pair(49, -190),
        Pair(127, -193), Pair(-5, -136), Pair(58, -184), Pair(-35, -129), Pair(112, -191), Pair(119, -218), Pair(81, -181), Pair(-49, -146),
        Pair(-55, -198), Pair(-20, -168), Pair(10, -180), Pair(-10, -105), Pair(133, -184), Pair(10, -194), Pair(-28, -189), Pair(18, -147),
        Pair(-38, -172), Pair(-37, -236), Pair(-63, -214), Pair(49, -208), Pair(39, -180), Pair(-143, -100), Pair(-17, -126), Pair(-53, -170),
        Pair(-14, -184), Pair(-31, -175), Pair(-22, -165), Pair(13, -210), Pair(-4, -163), Pair(-42, -217), Pair(-58, -119), Pair(6, -179),
        Pair(-26, -185), Pair(-36, -200), Pair(1, -256), Pair(12, -219), Pair(44, -199), Pair(-63, -188), Pair(14, -216), Pair(44, -170)
      },
      { // Piece 4
        Pair(-79, -240), Pair(-93, -131), Pair(-131, -116), Pair(-43, -127), Pair(-75, -152), Pair(-132, -117), Pair(-75, -167), Pair(-56, -208),
        Pair(3, -57), Pair(-92, -121), Pair(-42, -63), Pair(-23, -80), Pair(-6, -3), Pair(24, -70), Pair(-69, -126), Pair(-72, -88),
        Pair(-86, -94), Pair(-31, -109), Pair(-41, -61), Pair(-19, -59), Pair(-49, 2), Pair(-38, -70), Pair(-54, -117), Pair(-40, -63),
        Pair(-49, -131), Pair(-12, -104), Pair(-3, -75), Pair(-50, -97), Pair(-25, -75), Pair(-13, -45), Pair(41, -79), Pair(-16, -113),
        Pair(-88, -175), Pair(-14, -1), Pair(-45, -88), Pair(-31, -39), Pair(-24, -66), Pair(1, -20), Pair(-46, -71), Pair(-81, -137),
        Pair(-92, -149), Pair(4, 26), Pair(-17, -24), Pair(-16, -100), Pair(7, 2), Pair(29, -29), Pair(-27, -64), Pair(-27, -36),
        Pair(-93, -184), Pair(-46, -125), Pair(-68, -205), Pair(-10, -91), Pair(8, -48), Pair(-8, -17), Pair(-39, -125), Pair(-32, -74),
        Pair(-64, -136), Pair(-46, -160), Pair(-120, -241), Pair(-19, -30), Pair(-43, -120), Pair(-34, -70), Pair(-43, -147), Pair(-63, -72)
      },
      { // Piece 5
        Pair(80, -100), Pair(-3, -49), Pair(7, -30), Pair(-36, 14), Pair(-42, -5), Pair(-46, -11), Pair(7, -20), Pair(100, -119),
        Pair(-51, -48), Pair(5, 4), Pair(-28, 14), Pair(3, -6), Pair(-29, 7), Pair(19, 13), Pair(73, 9), Pair(18, -48),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }},
    {{ // Bucket 6
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-156, 261), Pair(-4, 294), Pair(6, 315), Pair(67, 283), Pair(7, 273), Pair(99, 365), Pair(-43, 373), Pair(-20, 332),
        Pair(-155, 312), Pair(0, 239), Pair(40, 235), Pair(122, 203), Pair(-7, 246), Pair(-35, 271), Pair(6, 268), Pair(-149, 306),
        Pair(-175, 148), Pair(17, 142), Pair(-57, 163), Pair(-3, 133), Pair(-28, 131), Pair(49, 152), Pair(-79, 140), Pair(-43, 127),
        Pair(-114, 24), Pair(-112, 71), Pair(14, 86), Pair(6, 53), Pair(-11, 55), Pair(-2, 49), Pair(-91, 69), Pair(-71, 73),
        Pair(-99, 52), Pair(-126, 27), Pair(-70, 60), Pair(36, 58), Pair(-50, 24), Pair(-11, -31), Pair(-89, 61), Pair(7, 13),
        Pair(-106, 52), Pair(-213, 27), Pair(20, -5), Pair(-16, 50), Pair(-20, 21), Pair(-58, 101), Pair(-9, 23), Pair(-87, 90),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-9, -33), Pair(-31, -53), Pair(5, 57), Pair(-7, -98), Pair(-7, -134), Pair(-4, 3), Pair(-9, -114), Pair(1, -86),
        Pair(-11, -68), Pair(-8, -123), Pair(-33, -102), Pair(-71, -60), Pair(-17, 35), Pair(-25, -98), Pair(-19, -56), Pair(-51, -123),
        Pair(39, -63), Pair(-12, -56), Pair(-72, -24), Pair(-10, -42), Pair(-20, -35), Pair(10, -79), Pair(54, -141), Pair(-35, -124),
        Pair(-32, -59), Pair(-19, -86), Pair(19, -34), Pair(16, 0), Pair(11, -26), Pair(13, 10), Pair(-23, -43), Pair(-7, -136),
        Pair(-21, -66), Pair(25, -105), Pair(-26, -7), Pair(-69, -99), Pair(23, -54), Pair(-13, -3), Pair(-21, -152), Pair(13, 15),
        Pair(-20, -47), Pair(-20, 18), Pair(9, -15), Pair(-27, -64), Pair(13, -18), Pair(-14, 15), Pair(-1, -77), Pair(-10, -7),
        Pair(-11, -122), Pair(21, 77), Pair(-1, -158), Pair(10, -67), Pair(-18, -76), Pair(-6, -7), Pair(-1, -16), Pair(-2, -36),
        Pair(-3, -57), Pair(37, -20), Pair(7, 2), Pair(8, 95), Pair(-10, -106), Pair(-2, -16), Pair(6, 27), Pair(-5, -75)
      },
      { // Piece 2
        Pair(20, -17), Pair(44, -4), Pair(6, -39), Pair(-11, -96), Pair(-7, 40), Pair(23, -74), Pair(-9, -116), Pair(6, 18),
        Pair(-7, 7), Pair(-88, -78), Pair(-66, 24), Pair(-34, -106), Pair(-109, -78), Pair(15, 13), Pair(21, 53), Pair(0, -67),
        Pair(4, -37), Pair(-37, -30), Pair(-21, 72), Pair(19, -51), Pair(23, 48), Pair(-56, 38), Pair(34, -46), Pair(-5, -68),
        Pair(-5, -15), Pair(4, 59), Pair(13, 10), Pair(-29, 37), Pair(72, -15), Pair(-12, -44), Pair(-10, 79), Pair(2, -88),
        Pair(-4, 45), Pair(-19, 69), Pair(8, 116), Pair(8, 10), Pair(-90, -34), Pair(37, 73), Pair(-4, 9), Pair(10, 80),
        Pair(0, -109), Pair(-2, 39), Pair(-41, -60), Pair(-1, -1), Pair(-36, 26), Pair(-5, -77), Pair(-7, -1), Pair(4, 28),
        Pair(-54, -61), Pair(25, 16), Pair(40, 101), Pair(-3, -59), Pair(50, 86), Pair(-14, -22), Pair(2, 34), Pair(-2, -7),
        Pair(-14, 42), Pair(-5, -78), Pair(-10, -106), Pair(15, -93), Pair(-14, -26), Pair(-14, -22), Pair(-16, -90), Pair(-9, 29)
      },
      { // Piece 3
        Pair(20, -125), Pair(36, -76), Pair(30, -72), Pair(-5, -79), Pair(-58, -67), Pair(8, -155), Pair(-20, -95), Pair(-6, -125),
        Pair(3, -140), Pair(-6, -101), Pair(12, -116), Pair(-2, -89), Pair(-5, -125), Pair(-65, -110), Pair(-30, -11), Pair(30, -89),
        Pair(-4, -44), Pair(-6, -109), Pair(3, -160), Pair(32, -117), Pair(-37, -140), Pair(24, -73), Pair(57, -91), Pair(-66, -18),
        Pair(7, -78), Pair(-4, -121), Pair(-3, -77), Pair(16, -152), Pair(8, -141), Pair(86, -130), Pair(-76, -130), Pair(-51, -115),
        Pair(59, -104), Pair(70, -44), Pair(11, -64), Pair(-4, -111), Pair(-1, -84), Pair(-38, -116), Pair(22, -36), Pair(-5, -102),
        Pair(58, -20), Pair(-4, -102), Pair(15, -103), Pair(66, -120), Pair(-45, -131), Pair(-3, -55), Pair(-19, -144), Pair(-55, -157),
        Pair(-44, -58), Pair(-44, -9), Pair(-100, -127), Pair(-6, -22), Pair(42, -60), Pair(-38, -108), Pair(6, -111), Pair(35, -106),
        Pair(-36, -115), Pair(30, -154), Pair(6, -69), Pair(-1, -95), Pair(59, -86), Pair(-40, -101), Pair(-29, -158), Pair(-39, -110)
      },
      { // Piece 4
        Pair(25, -84), Pair(-72, -87), Pair(-58, -49), Pair(-36, -42), Pair(-32, 38), Pair(-71, -37), Pair(-56, -89), Pair(118, -96),
        Pair(-11, -50), Pair(14, -3), Pair(-17, -85), Pair(-9, -23), Pair(-2, -80), Pair(-29, -41), Pair(20, 31), Pair(-111, -209),
        Pair(16, 23), Pair(-14, 16), Pair(-16, -30), Pair(-33, -42), Pair(6, 13), Pair(67, 95), Pair(-55, -53), Pair(-78, -121),
        Pair(-23, -53), Pair(22, 71), Pair(9, -66), Pair(-36, -7), Pair(-8, 34), Pair(-13, 5), Pair(-34, -33), Pair(-26, -22),
        Pair(2, -2), Pair(36, 29), Pair(9, -24), Pair(-56, -33), Pair(-10, 6), Pair(-34, -64), Pair(12, -11), Pair(41, 89),
        Pair(-26, -102), Pair(33, 39), Pair(8, 27), Pair(44, 15), Pair(-19, 19), Pair(12, -2), Pair(7, -37), Pair(-24, -51),
        Pair(28, -63), Pair(-20, -65), Pair(41, 43), Pair(23, 63), Pair(-29, -37), Pair(-13, 14), Pair(-50, -71), Pair(51, 67),
        Pair(-20, -98), Pair(11, 38), Pair(58, 107), Pair(-55, -116), Pair(-12, 6), Pair(-51, -119), Pair(-38, -90), Pair(-27, -68)
      },
      { // Piece 5
        Pair(-120, -106), Pair(73, -3), Pair(156, -21), Pair(-113, 35), Pair(-74, 11), Pair(38, 20), Pair(34, -14), Pair(43, -77),
        Pair(35, -46), Pair(-55, 44), Pair(-40, 67), Pair(4, 46), Pair(-11, 26), Pair(14, 45), Pair(60, 15), Pair(-63, -13),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      }
    }}
  }}
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(-3, 98), Pair(13, 65), Pair(18, 93), Pair(21, 106), Pair(24, 114), Pair(27, 123), Pair(31, 123), Pair(38, 116),
  Pair(42, 104)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-24, 43), Pair(-15, -4), Pair(-8, 20), Pair(-4, 38), Pair(1, 55), Pair(4, 68), Pair(5, 78), Pair(6, 83),
  Pair(10, 89), Pair(14, 90), Pair(23, 87), Pair(33, 83), Pair(64, 91), Pair(84, 68)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-40, -32), Pair(-31, -17), Pair(-28, 2), Pair(-27, 24), Pair(-25, 33), Pair(-19, 37), Pair(-14, 43), Pair(-7, 45),
  Pair(-3, 48), Pair(3, 53), Pair(7, 57), Pair(12, 59), Pair(18, 58), Pair(43, 46), Pair(85, 23)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-25, 202), Pair(-31, 162), Pair(-7, 114), Pair(-2, 102), Pair(0, 114), Pair(0, 136), Pair(2, 150), Pair(3, 171),
  Pair(5, 184), Pair(9, 186), Pair(10, 196), Pair(12, 199), Pair(13, 200), Pair(16, 202), Pair(14, 205), Pair(13, 205),
  Pair(14, 202), Pair(15, 198), Pair(19, 188), Pair(30, 176), Pair(39, 162), Pair(48, 143), Pair(46, 137), Pair(26, 143),
  Pair(26, 133), Pair(113, 75), Pair(159, 85), Pair(165, 65)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-34, -102), Pair(-33, -90), Pair(-18, -57), Pair(19, -22), Pair(38, 47), Pair(172, 134), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(7, 0), Pair(17, 6), Pair(15, 20), Pair(46, 83), Pair(121, 156), Pair(12, 293), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(22, 10), Pair(13, 6), Pair(18, 13), Pair(46, 52), Pair(209, 36), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-26, -56), Pair(-9, -32), Pair(-7, -23), Pair(-9, -20), Pair(-18, -11), Pair(-15, -13), Pair(-3, -23), Pair(-35, -43)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(3, 2), Pair(-5, -11), Pair(-10, -11), Pair(-9, -18), Pair(-11, -19), Pair(-7, -12), Pair(-7, -9), Pair(11, -4)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(21, 10), Pair(23, 8), Pair(23, 13), Pair(25, 10), Pair(28, 12), Pair(43, 8), Pair(51, 1), Pair(58, -1)
  },
  {
      Pair(10, 28), Pair(14, 13), Pair(16, 8), Pair(17, 8), Pair(14, 5), Pair(22, 0), Pair(27, -1), Pair(21, 12)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(14, -2), Pair(30, -8), Pair(20, -2),
  Pair(33, -12), Pair(34, -15), Pair(33, -13),
  Pair(51, -9), Pair(0, 0), Pair(45, -7),
  Pair(15, 4), Pair(7, 0), Pair(11, 6)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-9, 8), Pair(-17, 14), Pair(-10, 8),
  Pair(-13, 5), Pair(-24, 10), Pair(-14, 5),
  Pair(-7, -1), Pair(-15, 5), Pair(-3, -2),
  Pair(8, -2), Pair(-6, 2), Pair(12, -3),
  Pair(42, -18), Pair(45, -8), Pair(41, -19),
  Pair(-22, 1), Pair(-38, -13), Pair(-14, -17),
  Pair(58, -54), Pair(0, 0), Pair(49, -52)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-1, 88), Pair(1, 75), Pair(2, 62), Pair(7, 51), Pair(8, 45), Pair(16, 39), Pair(5, 29)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-13, -30), Pair(-21, 17), Pair(-8, 39), Pair(1, 52), Pair(10, 59), Pair(12, 65), Pair(5, 69)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-644, 109);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-41, -28), Pair(-73, -8), Pair(-6, -23), Pair(-1, -25), Pair(-12, -18), Pair(-5, -18), Pair(-46, -4), Pair(-14, -10)
  },
  {
      Pair(-48, 58), Pair(-43, 22), Pair(-6, 2), Pair(-2, -8), Pair(-1, -5), Pair(5, -3), Pair(-30, 16), Pair(-25, 32)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(10, 4), Pair(28, 1), Pair(71, -10), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(10, 4), Pair(25, 6), Pair(68, -2), Pair(75, -19), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(25, -16), Pair(41, -15), Pair(66, -13), Pair(100, -15), Pair(159, -32), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(6, 21), Pair(17, 48), Pair(37, 63), Pair(97, 54), Pair(143, 62), Pair(243, 27), Pair(352, -32)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(29, 4), Pair(8, 10), Pair(29, -2), Pair(16, 21), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(-12, 17), Pair(-4, 33)
  },
  {
      Pair(-37, -75), Pair(-24, -66)
  },
  {
      Pair(-45, -100), Pair(-34, -101)
  },
  {
      Pair(-42, -35), Pair(-36, -31)
  },
  {
      Pair(-36, -36), Pair(-36, -38)
  },
  {
      Pair(1, 33), Pair(-22, -7)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(18, 36), Pair(16, 3), Pair(14, 36), Pair(12, 4), Pair(39, 4)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-1, -22), Pair(6, -7)
  },
  {
      Pair(-18, 0), Pair(-2, -6)
  },
  {
      Pair(-29, -34), Pair(-20, -47)
  },
  {
      Pair(-56, -14), Pair(-39, -31)
  },
  {
      Pair(-36, -39), Pair(-29, -35)
  },
  {
      Pair(-47, -21), Pair(-15, -49)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-12, -17), Pair(0, -4)
  },
  {
      Pair(-44, -31), Pair(-23, -48)
  },
  {
      Pair(-13, -25), Pair(-10, -40)
  },
  {
      Pair(-51, -17), Pair(-36, -34)
  },
  {
      Pair(-44, -20), Pair(-33, -35)
  },
  {
      Pair(-4, -24), Pair(-5, -19)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(3, -24), Pair(11, -6)
  },
  {
      Pair(-30, -28), Pair(0, -14)
  },
  {
      Pair(-25, -22), Pair(-5, -8)
  },
  {
      Pair(6, -18), Pair(7, -15)
  },
  {
      Pair(-43, -18), Pair(-31, -21)
  },
  {
      Pair(2, -29), Pair(-9, -34)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(-2, 38), Pair(18, 48), Pair(39, 24), Pair(39, 27), Pair(36, 36), Pair(41, 32), Pair(4, 61), Pair(21, 27),
  Pair(15, 25), Pair(11, 26), Pair(15, 33), Pair(12, 39), Pair(4, 37), Pair(-3, 39), Pair(1, 26), Pair(2, 22),
  Pair(5, 11), Pair(6, 23), Pair(-1, 30), Pair(10, 23), Pair(2, 30), Pair(-7, 24), Pair(-12, 19), Pair(-1, 5)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-2, 2), Pair(29, 11), Pair(27, -6), Pair(46, -3), Pair(46, -6), Pair(83, -10), Pair(34, 13), Pair(10, -1),
  Pair(13, -14), Pair(18, 16), Pair(24, 2), Pair(38, 8), Pair(17, 8), Pair(38, 3), Pair(10, 20), Pair(1, 12),
  Pair(-21, 6), Pair(16, 16), Pair(7, 18), Pair(17, 13), Pair(16, 18), Pair(-2, 13), Pair(-3, 18), Pair(-14, -10)
};

constexpr ScorePair kBishopPairBonus = Pair(16, 86);

constexpr ScorePair kTempoBonus = Pair(12, 16);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H