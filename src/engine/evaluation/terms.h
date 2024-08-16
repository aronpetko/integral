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
using PieceSquareTable = KingBuckets<PieceTable<SquareTable<T>>>;

// [is_our_piece][pawn_position][piece][piece_position]
template <typename T>
using PawnRelativePSQT = SideTable<SquareTable<PieceTable<SquareTable<T>>>>;

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
  Pair(87, 118), Pair(395, 296), Pair(447, 364), Pair(600, 696), Pair(1177, 1198), Pair(0, 0)
};

constexpr PawnRelativePSQT<ScorePair> kPawnPieceSquareTable = {{
  {{ // Bucket 0
    {{ // Bucket 0
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 5
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
    {{ // Bucket 1
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 5
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
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 5
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
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 5
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
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 5
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
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 5
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
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 5
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
    {{ // Bucket 7
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 5
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
    {{ // Bucket 8
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(-6, -10), Pair(-32, 3), Pair(-76, 14), Pair(-30, 14), Pair(42, -17), Pair(7, -2), Pair(41, -5),
        Pair(-56, 14), Pair(56, -21), Pair(17, -34), Pair(17, -13), Pair(-24, -12), Pair(-44, 5), Pair(23, -6), Pair(-25, 4),
        Pair(-89, -42), Pair(6, -16), Pair(-23, -10), Pair(8, -29), Pair(-28, 1), Pair(5, -12), Pair(-2, -6), Pair(-9, 1),
        Pair(14, 52), Pair(40, -40), Pair(30, -32), Pair(9, -24), Pair(30, -27), Pair(7, -12), Pair(-23, -13), Pair(-24, -1),
        Pair(-82, 73), Pair(15, -29), Pair(22, -41), Pair(7, -24), Pair(10, -20), Pair(21, -23), Pair(-36, -12), Pair(-19, -18),
        Pair(0, 0), Pair(-37, 33), Pair(5, -16), Pair(3, -8), Pair(3, -14), Pair(3, -19), Pair(-1, -17), Pair(-21, -11),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-87, -161), Pair(28, 62), Pair(282, -39), Pair(-29, 39), Pair(-1, -164), Pair(325, -135), Pair(195, -123), Pair(141, -90),
        Pair(45, 30), Pair(40, -18), Pair(199, -117), Pair(151, -56), Pair(219, -138), Pair(0, -98), Pair(13, -52), Pair(253, 22),
        Pair(77, -15), Pair(92, -74), Pair(71, -22), Pair(82, -29), Pair(94, -57), Pair(55, -81), Pair(53, -60), Pair(42, -45),
        Pair(43, 12), Pair(10, -9), Pair(49, 13), Pair(74, -26), Pair(14, -6), Pair(114, -103), Pair(106, -65), Pair(-58, -8),
        Pair(120, -121), Pair(120, -5), Pair(-35, 17), Pair(66, -24), Pair(41, -36), Pair(126, -88), Pair(74, -69), Pair(-32, -27),
        Pair(10, -2), Pair(-16, 83), Pair(97, -3), Pair(113, -13), Pair(18, -23), Pair(58, -63), Pair(67, -94), Pair(-25, -78),
        Pair(0, 0), Pair(62, -106), Pair(36, 91), Pair(37, -7), Pair(66, -3), Pair(-8, -76), Pair(25, -74), Pair(38, 55),
        Pair(86, 161), Pair(-33, -15), Pair(257, 44), Pair(71, -39), Pair(12, -86), Pair(64, -100), Pair(-70, 18), Pair(82, -142)
      },
      { // Piece 2
        Pair(-61, 4), Pair(-176, 110), Pair(13, -75), Pair(-182, 157), Pair(55, -6), Pair(-220, 28), Pair(20, -60), Pair(-112, 272),
        Pair(-6, 122), Pair(-8, -19), Pair(33, 96), Pair(7, -34), Pair(6, 141), Pair(-69, 131), Pair(-209, 227), Pair(-96, 54),
        Pair(15, 77), Pair(18, 104), Pair(-34, 25), Pair(-15, 96), Pair(52, 46), Pair(-145, 206), Pair(40, 14), Pair(65, 37),
        Pair(61, -6), Pair(88, -27), Pair(76, 81), Pair(29, 36), Pair(-48, 181), Pair(62, 6), Pair(-109, 100), Pair(-116, 10),
        Pair(-88, -8), Pair(41, 75), Pair(-42, 71), Pair(-51, 190), Pair(107, -61), Pair(-68, 100), Pair(43, 28), Pair(-89, 51),
        Pair(-27, 102), Pair(285, -6), Pair(-58, 204), Pair(-34, 42), Pair(1, 66), Pair(9, -9), Pair(3, 50), Pair(-12, 11),
        Pair(0, 0), Pair(23, 215), Pair(19, 14), Pair(-36, 96), Pair(-2, 4), Pair(-95, 66), Pair(20, -48), Pair(-23, 52),
        Pair(128, 243), Pair(-24, 91), Pair(8, 81), Pair(-24, -3), Pair(-64, 55), Pair(-42, 4), Pair(-15, 6), Pair(-111, 65)
      },
      { // Piece 3
        Pair(121, 72), Pair(102, 55), Pair(171, -13), Pair(6, 76), Pair(-147, 101), Pair(118, 12), Pair(293, 6), Pair(267, -36),
        Pair(72, 101), Pair(175, 0), Pair(31, 57), Pair(128, 34), Pair(57, 51), Pair(255, -61), Pair(212, 6), Pair(70, 39),
        Pair(109, 104), Pair(84, 3), Pair(64, 46), Pair(17, 49), Pair(38, 43), Pair(-38, 99), Pair(75, 40), Pair(144, -18),
        Pair(42, 105), Pair(-6, 43), Pair(-47, 99), Pair(7, 64), Pair(21, 50), Pair(59, 32), Pair(42, 44), Pair(-5, 33),
        Pair(119, 64), Pair(20, 20), Pair(32, -5), Pair(58, -10), Pair(21, -27), Pair(109, -10), Pair(-151, 91), Pair(-2, 93),
        Pair(39, 94), Pair(3, 51), Pair(70, 36), Pair(-71, 73), Pair(71, 21), Pair(122, 11), Pair(77, -12), Pair(3, 56),
        Pair(0, 0), Pair(-60, 129), Pair(41, 61), Pair(83, 32), Pair(34, 73), Pair(67, 23), Pair(36, 81), Pair(-2, 130),
        Pair(72, 162), Pair(39, 18), Pair(26, 118), Pair(17, 119), Pair(23, 146), Pair(42, 117), Pair(56, 98), Pair(29, 140)
      },
      { // Piece 4
        Pair(104, -40), Pair(-1, 162), Pair(138, -3), Pair(45, 31), Pair(176, -22), Pair(76, 93), Pair(-62, -9), Pair(173, -33),
        Pair(-11, 123), Pair(-88, 253), Pair(95, 114), Pair(70, 15), Pair(57, 67), Pair(107, -20), Pair(20, 141), Pair(54, 61),
        Pair(35, -24), Pair(58, 30), Pair(67, 48), Pair(-69, 189), Pair(60, 72), Pair(48, 76), Pair(-60, 56), Pair(39, 60),
        Pair(103, 57), Pair(18, -57), Pair(-1, 238), Pair(-23, 144), Pair(19, 79), Pair(54, 30), Pair(109, -60), Pair(17, 90),
        Pair(106, -107), Pair(-16, 70), Pair(15, 6), Pair(-46, 92), Pair(-31, 45), Pair(72, 15), Pair(-46, -2), Pair(-35, 148),
        Pair(-94, 17), Pair(50, 109), Pair(-18, 23), Pair(-1, -35), Pair(-87, 168), Pair(13, 36), Pair(-92, 67), Pair(41, 31),
        Pair(0, 0), Pair(-67, 165), Pair(-7, -16), Pair(3, -63), Pair(-64, 46), Pair(45, -122), Pair(-37, 54), Pair(-88, -104),
        Pair(-62, 63), Pair(-8, -38), Pair(-42, 161), Pair(-30, 184), Pair(-25, 1), Pair(-85, 55), Pair(-115, 101), Pair(-17, 173)
      },
      { // Piece 5
        Pair(-3, 15), Pair(-30, 6), Pair(-24, -76), Pair(77, -26), Pair(178, -160), Pair(-39, 27), Pair(4, -49), Pair(22, -64),
        Pair(-94, -168), Pair(46, -33), Pair(-151, 7), Pair(7, 20), Pair(-51, -34), Pair(248, -43), Pair(157, -94), Pair(88, -18),
        Pair(-23, -155), Pair(-36, 31), Pair(20, 22), Pair(-3, 11), Pair(21, 12), Pair(70, -23), Pair(186, -80), Pair(151, -50),
        Pair(-123, -6), Pair(-100, 65), Pair(-31, 53), Pair(30, 27), Pair(-23, 18), Pair(-107, 6), Pair(64, -35), Pair(115, -54),
        Pair(66, -28), Pair(-178, 92), Pair(39, 18), Pair(16, 19), Pair(65, 4), Pair(1, 2), Pair(-15, -38), Pair(144, -79),
        Pair(-202, 169), Pair(-10, 128), Pair(67, 44), Pair(-50, 47), Pair(28, 12), Pair(-19, -10), Pair(-53, -47), Pair(1, -30),
        Pair(0, 0), Pair(-142, 201), Pair(2, 67), Pair(68, 40), Pair(-60, 29), Pair(-74, 0), Pair(-17, -16), Pair(3, -60),
        Pair(238, 132), Pair(154, 79), Pair(-130, 111), Pair(-43, 6), Pair(-93, -7), Pair(46, -89), Pair(-16, -93), Pair(-60, -83)
      }
    }},
    {{ // Bucket 9
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(6, 9), Pair(0, 0), Pair(8, -4), Pair(27, -2), Pair(28, -10), Pair(-11, 8), Pair(-40, -19), Pair(-4, 9),
        Pair(-27, -2), Pair(-82, -6), Pair(-11, -5), Pair(26, -28), Pair(-26, 3), Pair(-6, 2), Pair(-26, 4), Pair(-31, -7),
        Pair(-19, -10), Pair(6, -28), Pair(-3, -25), Pair(-11, -10), Pair(6, -12), Pair(-23, 1), Pair(2, -13), Pair(-13, -1),
        Pair(12, -24), Pair(-37, 3), Pair(-4, -12), Pair(-19, -10), Pair(-18, -10), Pair(-18, -12), Pair(-24, -16), Pair(2, -15),
        Pair(8, -31), Pair(7, -19), Pair(11, -17), Pair(-18, -18), Pair(-4, -18), Pair(2, -20), Pair(-32, -13), Pair(-2, -14),
        Pair(19, -20), Pair(0, 0), Pair(28, -26), Pair(18, -29), Pair(-6, -26), Pair(4, -22), Pair(-21, -17), Pair(-14, -12),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-107, 100), Pair(-88, -53), Pair(210, -159), Pair(-43, -44), Pair(-30, -66), Pair(77, -10), Pair(14, -104), Pair(39, 11),
        Pair(67, -150), Pair(-115, 49), Pair(192, 7), Pair(128, -59), Pair(122, -26), Pair(-32, -14), Pair(-23, -110), Pair(90, -48),
        Pair(95, 61), Pair(69, 2), Pair(-9, 11), Pair(-60, 57), Pair(38, 1), Pair(129, -53), Pair(45, -54), Pair(-5, -4),
        Pair(-176, 53), Pair(-14, 23), Pair(-56, 9), Pair(84, -39), Pair(99, -20), Pair(123, -23), Pair(-10, -10), Pair(181, -16),
        Pair(44, 119), Pair(-29, 84), Pair(63, 26), Pair(-44, -11), Pair(-9, 43), Pair(-41, 43), Pair(11, -28), Pair(-56, 15),
        Pair(-43, 149), Pair(4, 31), Pair(-78, 160), Pair(-100, 10), Pair(53, -27), Pair(-24, 21), Pair(-63, 37), Pair(-47, -80),
        Pair(-80, -95), Pair(0, 0), Pair(-37, 16), Pair(-49, 152), Pair(52, -37), Pair(113, -110), Pair(-29, 3), Pair(-68, 10),
        Pair(-19, -50), Pair(5, 212), Pair(-288, -14), Pair(-37, 115), Pair(-18, 4), Pair(-42, -20), Pair(93, -124), Pair(-92, -25)
      },
      { // Piece 2
        Pair(-205, 154), Pair(24, -8), Pair(-198, 138), Pair(-85, 31), Pair(-523, 167), Pair(-31, 46), Pair(-15, 113), Pair(-142, 126),
        Pair(29, 36), Pair(22, 110), Pair(35, 39), Pair(-229, 145), Pair(41, 12), Pair(-21, 100), Pair(-17, 29), Pair(-107, 220),
        Pair(39, 63), Pair(-87, 107), Pair(-34, 101), Pair(107, -41), Pair(-60, 116), Pair(53, 80), Pair(59, 222), Pair(50, -51),
        Pair(-105, 19), Pair(-63, 128), Pair(-61, 5), Pair(-36, 113), Pair(97, 46), Pair(-55, 234), Pair(1, 7), Pair(-14, 57),
        Pair(37, 89), Pair(-16, -52), Pair(-30, 80), Pair(49, 52), Pair(-94, 217), Pair(-14, 2), Pair(-15, 108), Pair(15, -58),
        Pair(-74, 79), Pair(-22, 194), Pair(7, 115), Pair(-84, 223), Pair(80, -35), Pair(-31, 69), Pair(15, 33), Pair(0, 59),
        Pair(-54, 257), Pair(0, 0), Pair(-6, 219), Pair(22, -36), Pair(-50, 56), Pair(-34, 9), Pair(-18, 51), Pair(54, -54),
        Pair(30, -94), Pair(3, 299), Pair(-87, 6), Pair(-46, 124), Pair(75, -46), Pair(-44, 97), Pair(-71, -37), Pair(-73, 173)
      },
      { // Piece 3
        Pair(44, -61), Pair(116, 43), Pair(-105, 60), Pair(101, -33), Pair(185, -87), Pair(197, 54), Pair(183, -4), Pair(341, -40),
        Pair(-69, 68), Pair(-74, 103), Pair(45, 31), Pair(65, 36), Pair(121, 13), Pair(136, -6), Pair(184, -8), Pair(-36, 119),
        Pair(1, 6), Pair(80, 87), Pair(3, -1), Pair(42, -64), Pair(74, -21), Pair(158, -16), Pair(115, 18), Pair(-1, 21),
        Pair(32, -31), Pair(35, 83), Pair(54, 30), Pair(-41, 64), Pair(23, 15), Pair(-98, 16), Pair(172, 30), Pair(203, -50),
        Pair(36, 9), Pair(-70, 102), Pair(22, 59), Pair(-99, 90), Pair(73, 26), Pair(38, 88), Pair(-13, 56), Pair(-27, 19),
        Pair(26, 46), Pair(9, 58), Pair(-50, 19), Pair(-20, 61), Pair(-47, 95), Pair(18, 29), Pair(55, -129), Pair(155, -18),
        Pair(139, 14), Pair(0, 0), Pair(0, 116), Pair(-86, 177), Pair(85, -4), Pair(178, -53), Pair(56, 83), Pair(106, -40),
        Pair(2, 2), Pair(60, 127), Pair(4, 11), Pair(-31, 112), Pair(-10, 113), Pair(-29, 100), Pair(-21, 110), Pair(-44, 67)
      },
      { // Piece 4
        Pair(96, 74), Pair(13, 51), Pair(151, 64), Pair(90, 5), Pair(34, 97), Pair(2, -6), Pair(-10, 94), Pair(209, 116),
        Pair(-39, 62), Pair(-202, 166), Pair(-59, 145), Pair(-127, 76), Pair(-26, 131), Pair(-55, 198), Pair(50, 63), Pair(29, -25),
        Pair(-112, 213), Pair(10, 112), Pair(-106, -4), Pair(2, 154), Pair(-22, 83), Pair(-1, 179), Pair(-56, 77), Pair(94, -93),
        Pair(-78, 118), Pair(-107, 83), Pair(-93, 52), Pair(122, -23), Pair(141, 5), Pair(28, 113), Pair(37, 53), Pair(179, -135),
        Pair(17, 74), Pair(-45, 77), Pair(-74, 143), Pair(-14, 119), Pair(-39, 63), Pair(-15, 55), Pair(-19, -46), Pair(44, -77),
        Pair(-12, -131), Pair(-34, -9), Pair(42, -63), Pair(-57, 192), Pair(27, -128), Pair(-29, 100), Pair(9, -53), Pair(52, -217),
        Pair(-46, -118), Pair(0, 0), Pair(79, -13), Pair(-29, -64), Pair(-16, -37), Pair(13, 89), Pair(146, -3), Pair(-90, 4),
        Pair(-167, 9), Pair(-1, 2), Pair(-85, -205), Pair(-8, -65), Pair(-14, -135), Pair(-2, 61), Pair(-141, 93), Pair(-175, 197)
      },
      { // Piece 5
        Pair(-44, -125), Pair(-14, -58), Pair(18, 98), Pair(17, -119), Pair(88, -58), Pair(101, -67), Pair(85, 24), Pair(79, -83),
        Pair(24, -10), Pair(-4, 101), Pair(59, 7), Pair(-40, 33), Pair(38, -20), Pair(-14, -48), Pair(120, -69), Pair(231, 8),
        Pair(-78, -91), Pair(21, -46), Pair(-29, 47), Pair(40, -45), Pair(-23, -30), Pair(-12, -14), Pair(52, -27), Pair(45, -64),
        Pair(-69, 10), Pair(-92, 55), Pair(-58, 41), Pair(94, 26), Pair(59, 2), Pair(-82, 13), Pair(-54, 0), Pair(-128, 0),
        Pair(-28, -70), Pair(-40, 34), Pair(89, 23), Pair(-118, 56), Pair(43, -10), Pair(101, -9), Pair(76, -64), Pair(74, -49),
        Pair(34, 116), Pair(92, 15), Pair(9, 94), Pair(-49, 50), Pair(-19, 22), Pair(42, -21), Pair(-8, -46), Pair(115, -141),
        Pair(-104, 214), Pair(0, 0), Pair(-82, 145), Pair(16, 47), Pair(-52, 20), Pair(32, -13), Pair(16, -40), Pair(-36, -61),
        Pair(-21, 24), Pair(81, 132), Pair(14, 87), Pair(-312, 96), Pair(-45, -5), Pair(8, -58), Pair(-6, -89), Pair(52, -147)
      }
    }},
    {{ // Bucket 10
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(32, -3), Pair(-8, 4), Pair(0, 0), Pair(-4, -11), Pair(-16, 26), Pair(51, 20), Pair(27, 2), Pair(-3, 12),
        Pair(-32, 6), Pair(-51, 5), Pair(50, -10), Pair(43, -13), Pair(60, -15), Pair(18, -21), Pair(-79, 24), Pair(-23, -2),
        Pair(2, -16), Pair(-15, -11), Pair(-12, 6), Pair(6, -20), Pair(-2, -5), Pair(-44, -7), Pair(-45, 2), Pair(-44, 8),
        Pair(2, -21), Pair(18, -20), Pair(-4, -10), Pair(6, -14), Pair(-1, -9), Pair(7, -17), Pair(-14, -12), Pair(-40, 1),
        Pair(21, -23), Pair(-7, -14), Pair(30, -18), Pair(-7, -10), Pair(-7, -8), Pair(-7, -14), Pair(-37, -3), Pair(-34, -6),
        Pair(11, -14), Pair(9, -23), Pair(0, 0), Pair(-4, -45), Pair(6, -13), Pair(-4, -16), Pair(-17, -15), Pair(-36, -7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-111, -133), Pair(46, -59), Pair(97, 17), Pair(297, 25), Pair(-3, -30), Pair(-109, -23), Pair(-74, 35), Pair(-108, -116),
        Pair(102, -110), Pair(-175, 82), Pair(-153, 53), Pair(-52, 82), Pair(50, -50), Pair(42, 1), Pair(102, -98), Pair(9, -40),
        Pair(-106, 93), Pair(83, 64), Pair(-7, 57), Pair(36, -36), Pair(-61, 61), Pair(70, -48), Pair(-43, 22), Pair(-64, 106),
        Pair(61, 35), Pair(41, 33), Pair(-29, 42), Pair(-63, 82), Pair(1, 35), Pair(-12, 25), Pair(2, -15), Pair(65, 28),
        Pair(22, 25), Pair(207, -49), Pair(97, 32), Pair(-52, 68), Pair(77, -7), Pair(-35, 79), Pair(7, -30), Pair(-52, 61),
        Pair(152, 63), Pair(-156, 211), Pair(55, -26), Pair(-30, 168), Pair(-80, 111), Pair(-14, 52), Pair(-83, 111), Pair(50, -74),
        Pair(-82, 127), Pair(-130, 96), Pair(0, 0), Pair(51, -30), Pair(-81, 172), Pair(64, -51), Pair(-52, -18), Pair(-24, -12),
        Pair(-24, 29), Pair(90, -211), Pair(-28, 247), Pair(105, -97), Pair(-2, 203), Pair(101, -92), Pair(17, 44), Pair(-69, -49)
      },
      { // Piece 2
        Pair(-80, 47), Pair(-4, 78), Pair(-240, 101), Pair(-65, 108), Pair(-55, 139), Pair(-79, 99), Pair(95, 6), Pair(-161, 130),
        Pair(-60, 86), Pair(27, 0), Pair(-70, 129), Pair(-179, 73), Pair(-44, 168), Pair(-32, 61), Pair(-4, 102), Pair(240, 3),
        Pair(122, 13), Pair(43, 81), Pair(-96, 43), Pair(-85, 140), Pair(-43, 57), Pair(-111, 151), Pair(-19, 126), Pair(-31, 185),
        Pair(-189, 155), Pair(-51, 58), Pair(104, 29), Pair(52, 53), Pair(37, 98), Pair(124, 45), Pair(-75, 220), Pair(164, -96),
        Pair(140, -14), Pair(90, 65), Pair(-61, 35), Pair(89, 102), Pair(60, -13), Pair(-121, 225), Pair(-68, 65), Pair(-73, -33),
        Pair(-20, 216), Pair(-142, 97), Pair(-12, 166), Pair(104, 11), Pair(-45, 188), Pair(-19, 33), Pair(-67, 75), Pair(-20, 4),
        Pair(44, -90), Pair(-13, 204), Pair(0, 0), Pair(-55, 237), Pair(-16, 6), Pair(-106, 142), Pair(45, -61), Pair(-37, -92),
        Pair(3, 124), Pair(-5, -21), Pair(66, 280), Pair(-234, 47), Pair(116, 63), Pair(-20, 36), Pair(52, 87), Pair(182, 14)
      },
      { // Piece 3
        Pair(-73, 55), Pair(66, 15), Pair(218, 38), Pair(36, 3), Pair(160, 44), Pair(120, 28), Pair(261, -62), Pair(144, 30),
        Pair(81, -17), Pair(9, 61), Pair(80, 71), Pair(100, 19), Pair(12, 72), Pair(97, 75), Pair(3, 62), Pair(106, 11),
        Pair(38, -14), Pair(58, -28), Pair(68, 85), Pair(13, 64), Pair(99, -2), Pair(320, -73), Pair(69, 35), Pair(-129, 122),
        Pair(87, 33), Pair(25, 27), Pair(-32, 102), Pair(-18, 82), Pair(-94, 99), Pair(4, 37), Pair(-8, 41), Pair(-171, 89),
        Pair(40, 27), Pair(128, -38), Pair(-56, 97), Pair(57, 6), Pair(48, -13), Pair(66, -8), Pair(1, -19), Pair(-87, 19),
        Pair(40, -32), Pair(200, 24), Pair(4, 86), Pair(-37, 49), Pair(154, -57), Pair(23, 34), Pair(58, -24), Pair(107, -112),
        Pair(-46, 69), Pair(-13, 98), Pair(0, 0), Pair(27, 73), Pair(171, 30), Pair(102, 0), Pair(-114, 42), Pair(-7, 11),
        Pair(4, 82), Pair(-55, 74), Pair(75, 168), Pair(-41, 9), Pair(-23, 129), Pair(80, 93), Pair(-51, 163), Pair(-24, 149)
      },
      { // Piece 4
        Pair(31, 17), Pair(163, 8), Pair(-194, 184), Pair(5, 1), Pair(108, -50), Pair(-1, -34), Pair(45, 44), Pair(-21, 135),
        Pair(31, 66), Pair(-84, 118), Pair(-93, 92), Pair(-34, 6), Pair(-24, 77), Pair(120, 88), Pair(-2, 86), Pair(-47, 15),
        Pair(9, 3), Pair(152, 33), Pair(4, 78), Pair(-12, 15), Pair(-80, 158), Pair(62, -31), Pair(-5, 39), Pair(29, -12),
        Pair(-14, 199), Pair(141, -131), Pair(-4, 78), Pair(-168, 118), Pair(49, 41), Pair(72, 15), Pair(120, -109), Pair(24, 17),
        Pair(-111, -98), Pair(-125, 10), Pair(107, -75), Pair(5, 11), Pair(-40, 163), Pair(-54, 90), Pair(6, -70), Pair(55, -136),
        Pair(-74, 79), Pair(-5, -74), Pair(37, 64), Pair(-12, 36), Pair(45, 5), Pair(61, -118), Pair(-123, 63), Pair(-52, -30),
        Pair(51, -118), Pair(-29, 37), Pair(0, 0), Pair(105, -94), Pair(-60, 67), Pair(30, 17), Pair(101, -208), Pair(-116, 38),
        Pair(31, -22), Pair(64, -101), Pair(35, -73), Pair(-113, -189), Pair(-57, 146), Pair(52, -44), Pair(-4, -15), Pair(97, 0)
      },
      { // Piece 5
        Pair(-9, 36), Pair(-6, -24), Pair(-43, -266), Pair(-12, 36), Pair(-19, -124), Pair(-13, -136), Pair(103, -199), Pair(1, -69),
        Pair(45, 7), Pair(1, -93), Pair(-20, -29), Pair(6, 6), Pair(-51, -111), Pair(-12, -16), Pair(-25, -65), Pair(-18, -99),
        Pair(-164, -36), Pair(-12, 1), Pair(-141, -68), Pair(123, -16), Pair(55, 0), Pair(50, -5), Pair(-60, 27), Pair(246, -124),
        Pair(34, -57), Pair(17, 9), Pair(140, -98), Pair(84, 32), Pair(-26, 77), Pair(-28, 44), Pair(95, -45), Pair(-68, -5),
        Pair(116, 58), Pair(82, 3), Pair(-24, 21), Pair(-74, 37), Pair(64, -2), Pair(56, -5), Pair(127, -56), Pair(55, -19),
        Pair(-111, 59), Pair(-29, 81), Pair(-177, 80), Pair(-1, 79), Pair(14, 24), Pair(8, 5), Pair(-47, -32), Pair(91, -77),
        Pair(116, -56), Pair(-132, 193), Pair(0, 0), Pair(-136, 145), Pair(-13, 47), Pair(32, -16), Pair(-19, -23), Pair(51, -89),
        Pair(-142, 142), Pair(253, -52), Pair(-188, 217), Pair(10, 43), Pair(-15, 9), Pair(1, -14), Pair(6, -72), Pair(38, -139)
      }
    }},
    {{ // Bucket 11
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(76, -13), Pair(-28, 1), Pair(4, 11), Pair(0, 0), Pair(-11, 39), Pair(12, 11), Pair(144, -30), Pair(-23, 12),
        Pair(28, -20), Pair(1, -32), Pair(-5, -15), Pair(-8, -17), Pair(20, -10), Pair(37, -8), Pair(50, -8), Pair(-9, -6),
        Pair(-8, -13), Pair(-41, -2), Pair(36, -28), Pair(18, -18), Pair(24, -14), Pair(-8, -1), Pair(-22, -16), Pair(-23, 8),
        Pair(4, -25), Pair(-38, -14), Pair(2, -19), Pair(-35, 30), Pair(16, -24), Pair(-28, -3), Pair(-8, -13), Pair(-16, -8),
        Pair(-2, -17), Pair(1, -7), Pair(16, -1), Pair(-26, 19), Pair(23, -20), Pair(17, -14), Pair(-15, -15), Pair(0, -10),
        Pair(4, -27), Pair(-19, -5), Pair(30, -6), Pair(0, 0), Pair(46, -21), Pair(-7, -3), Pair(-2, -11), Pair(5, -17),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-70, -1), Pair(10, -48), Pair(-58, -28), Pair(-186, 0), Pair(6, 55), Pair(49, -63), Pair(-19, -33), Pair(122, 0),
        Pair(80, -95), Pair(52, 34), Pair(-189, 108), Pair(-46, 88), Pair(80, -46), Pair(222, -62), Pair(67, 105), Pair(84, -12),
        Pair(-108, 107), Pair(49, -12), Pair(-46, 46), Pair(96, 41), Pair(68, -24), Pair(52, -45), Pair(38, -27), Pair(-177, 194),
        Pair(-115, 66), Pair(63, -75), Pair(61, 14), Pair(27, 21), Pair(-100, 107), Pair(105, 0), Pair(154, -105), Pair(52, -49),
        Pair(-116, 76), Pair(126, 81), Pair(-12, 93), Pair(60, 42), Pair(45, 22), Pair(72, -50), Pair(1, 53), Pair(102, 0),
        Pair(-90, -3), Pair(-46, 10), Pair(13, 150), Pair(-147, 87), Pair(-25, 148), Pair(-3, 82), Pair(32, -4), Pair(34, -41),
        Pair(-159, 2), Pair(-189, 206), Pair(-15, -18), Pair(0, 0), Pair(38, 72), Pair(-86, 147), Pair(137, -41), Pair(-52, 162),
        Pair(-87, -28), Pair(143, -83), Pair(-135, -33), Pair(32, 232), Pair(111, -134), Pair(1, 134), Pair(-40, 3), Pair(30, -26)
      },
      { // Piece 2
        Pair(-36, 76), Pair(-122, 116), Pair(-159, 113), Pair(5, -92), Pair(62, 130), Pair(-68, -50), Pair(51, 126), Pair(153, -78),
        Pair(-60, 71), Pair(79, 59), Pair(106, -48), Pair(16, 61), Pair(-38, -34), Pair(-18, 94), Pair(145, -43), Pair(61, 141),
        Pair(-7, 25), Pair(6, -36), Pair(-106, 108), Pair(142, -59), Pair(-123, 82), Pair(139, -23), Pair(-59, 104), Pair(-58, 50),
        Pair(42, 47), Pair(-185, 129), Pair(173, -3), Pair(-27, 75), Pair(-51, 20), Pair(-66, 76), Pair(-12, 26), Pair(-96, 216),
        Pair(-85, 181), Pair(-34, 37), Pair(43, 65), Pair(87, -13), Pair(67, 40), Pair(13, 65), Pair(-145, 251), Pair(-67, 66),
        Pair(21, -53), Pair(-42, 196), Pair(-28, 58), Pair(-62, 107), Pair(38, 19), Pair(-34, 177), Pair(-152, 82), Pair(-3, 65),
        Pair(41, 32), Pair(19, -35), Pair(-138, 222), Pair(0, 0), Pair(-28, 193), Pair(1, 12), Pair(-31, 53), Pair(-104, 63),
        Pair(10, -33), Pair(46, 84), Pair(-11, -107), Pair(86, 241), Pair(-102, 47), Pair(56, 2), Pair(-155, 122), Pair(-102, 111)
      },
      { // Piece 3
        Pair(83, 5), Pair(19, -59), Pair(-48, 38), Pair(101, 45), Pair(58, -12), Pair(255, -31), Pair(153, -34), Pair(112, -10),
        Pair(0, 32), Pair(-2, 56), Pair(6, 48), Pair(39, 61), Pair(-2, 10), Pair(222, -48), Pair(8, 4), Pair(106, -2),
        Pair(3, 13), Pair(-57, 10), Pair(116, 11), Pair(69, 37), Pair(-117, 65), Pair(169, -7), Pair(33, 76), Pair(257, -65),
        Pair(-6, 56), Pair(-69, 80), Pair(-116, 31), Pair(49, 38), Pair(30, -48), Pair(-66, 29), Pair(82, -2), Pair(193, -43),
        Pair(-59, -2), Pair(108, -24), Pair(58, -31), Pair(97, 60), Pair(147, -108), Pair(18, -23), Pair(-4, 55), Pair(45, -23),
        Pair(-95, 37), Pair(-4, 68), Pair(5, 47), Pair(-193, 125), Pair(16, -44), Pair(117, -2), Pair(-110, 107), Pair(41, 16),
        Pair(174, -7), Pair(-59, 96), Pair(-2, -17), Pair(0, 0), Pair(-22, 5), Pair(114, -34), Pair(82, 61), Pair(-5, 33),
        Pair(6, 102), Pair(-36, 111), Pair(-34, 50), Pair(52, 141), Pair(-29, 34), Pair(-33, 108), Pair(71, 51), Pair(-36, 91)
      },
      { // Piece 4
        Pair(150, -128), Pair(-36, 29), Pair(-55, -15), Pair(-86, 145), Pair(121, 21), Pair(75, 7), Pair(141, -84), Pair(129, 30),
        Pair(95, -36), Pair(-47, 19), Pair(-53, 31), Pair(36, 76), Pair(-31, 72), Pair(-68, 171), Pair(72, 82), Pair(142, -93),
        Pair(49, 12), Pair(-120, 180), Pair(-29, -20), Pair(76, -32), Pair(-39, 70), Pair(-3, 113), Pair(167, -95), Pair(57, -77),
        Pair(11, 12), Pair(50, -134), Pair(-7, -87), Pair(99, 2), Pair(121, -77), Pair(82, -35), Pair(95, -23), Pair(-3, 67),
        Pair(-50, 36), Pair(-16, -7), Pair(59, -44), Pair(73, 16), Pair(78, -99), Pair(121, -114), Pair(27, -54), Pair(72, -38),
        Pair(-100, 37), Pair(-16, 21), Pair(14, 140), Pair(63, 13), Pair(76, -23), Pair(35, 33), Pair(61, -142), Pair(-56, -118),
        Pair(77, -211), Pair(54, -255), Pair(-42, 40), Pair(0, 0), Pair(84, -51), Pair(-13, 73), Pair(-155, 67), Pair(-11, 94),
        Pair(-167, 177), Pair(-48, 31), Pair(-231, 118), Pair(78, -135), Pair(-182, -183), Pair(-68, -15), Pair(39, -21), Pair(-37, 77)
      },
      { // Piece 5
        Pair(8, -28), Pair(7, -44), Pair(17, 126), Pair(-16, -83), Pair(-18, -24), Pair(-89, -165), Pair(-15, -30), Pair(-21, -37),
        Pair(22, -66), Pair(-59, -98), Pair(23, -83), Pair(-9, -7), Pair(-10, -15), Pair(-61, -83), Pair(-106, -70), Pair(-3, -133),
        Pair(-11, -50), Pair(30, 10), Pair(40, -51), Pair(-34, 7), Pair(138, -46), Pair(53, 10), Pair(52, -82), Pair(3, -50),
        Pair(-35, -52), Pair(157, 24), Pair(167, -48), Pair(-242, 6), Pair(52, 32), Pair(72, 9), Pair(9, 15), Pair(63, -10),
        Pair(-113, -88), Pair(77, 55), Pair(-93, 4), Pair(2, -12), Pair(-156, 42), Pair(20, 10), Pair(40, -29), Pair(31, -54),
        Pair(-12, -55), Pair(77, -66), Pair(-133, 76), Pair(-130, 97), Pair(10, 48), Pair(139, -16), Pair(35, -7), Pair(67, -67),
        Pair(-2, 27), Pair(-52, -31), Pair(-26, 111), Pair(0, 0), Pair(-65, 111), Pair(46, 17), Pair(5, -6), Pair(36, -41),
        Pair(-36, 4), Pair(-38, 39), Pair(-84, -127), Pair(-133, 186), Pair(72, 127), Pair(40, -9), Pair(-16, -32), Pair(-14, -64)
      }
    }},
    {{ // Bucket 12
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(30, -14), Pair(-28, 11), Pair(16, -25), Pair(10, -38), Pair(0, 0), Pair(57, -24), Pair(7, -12), Pair(-13, 13),
        Pair(54, -33), Pair(-5, -16), Pair(-8, -13), Pair(34, -13), Pair(78, -31), Pair(24, -1), Pair(63, -27), Pair(-48, -9),
        Pair(-8, -17), Pair(-24, -2), Pair(-9, -18), Pair(-12, -6), Pair(0, -7), Pair(-24, 0), Pair(-5, -12), Pair(-49, 0),
        Pair(-24, -20), Pair(-1, -23), Pair(6, -28), Pair(21, -17), Pair(-34, -5), Pair(5, -8), Pair(-11, -13), Pair(-13, -6),
        Pair(-16, -13), Pair(-19, -13), Pair(-17, -15), Pair(35, -45), Pair(-6, -3), Pair(15, -21), Pair(-9, -9), Pair(-2, -15),
        Pair(-14, -21), Pair(6, -16), Pair(28, -20), Pair(-67, 7), Pair(0, 0), Pair(19, -36), Pair(-10, 8), Pair(9, -9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-9, -151), Pair(138, -72), Pair(-53, 4), Pair(150, -96), Pair(9, 25), Pair(-29, -54), Pair(5, -123), Pair(-123, 63),
        Pair(48, 2), Pair(-9, 21), Pair(17, -80), Pair(-13, 18), Pair(-245, 61), Pair(93, 51), Pair(63, -79), Pair(16, -43),
        Pair(-226, 0), Pair(-58, -66), Pair(2, -17), Pair(-81, -58), Pair(65, -86), Pair(73, 45), Pair(209, -31), Pair(178, -79),
        Pair(-97, -27), Pair(16, -86), Pair(-94, 24), Pair(-22, 25), Pair(128, -14), Pair(30, 29), Pair(104, 6), Pair(-56, 45),
        Pair(-87, -66), Pair(-125, 89), Pair(15, 26), Pair(79, 48), Pair(-63, 43), Pair(46, -1), Pair(98, 41), Pair(-17, 112),
        Pair(-39, -25), Pair(119, -108), Pair(-126, 152), Pair(-116, 172), Pair(81, 66), Pair(-61, 136), Pair(-21, 6), Pair(97, -147),
        Pair(-91, 24), Pair(-34, 17), Pair(-191, 221), Pair(-93, 37), Pair(0, 0), Pair(-117, -51), Pair(-53, 191), Pair(66, 25),
        Pair(16, -54), Pair(-58, -48), Pair(108, -93), Pair(-109, -53), Pair(-6, 226), Pair(4, -117), Pair(39, -50), Pair(37, 67)
      },
      { // Piece 2
        Pair(284, -76), Pair(-63, 126), Pair(-7, 77), Pair(-128, 92), Pair(-128, -3), Pair(8, 97), Pair(-67, -15), Pair(154, 150),
        Pair(-36, 92), Pair(40, -5), Pair(24, 44), Pair(-17, -5), Pair(-184, 108), Pair(103, 3), Pair(-81, 79), Pair(-75, 2),
        Pair(37, 45), Pair(36, 35), Pair(28, 20), Pair(54, 71), Pair(17, -9), Pair(-176, 133), Pair(30, -9), Pair(24, 49),
        Pair(-139, 222), Pair(-134, 166), Pair(-36, 104), Pair(172, -17), Pair(-3, 32), Pair(-89, 39), Pair(16, 54), Pair(-64, 35),
        Pair(-200, 28), Pair(-121, 178), Pair(-150, 87), Pair(131, 46), Pair(-1, 76), Pair(18, 12), Pair(-132, 100), Pair(-69, 196),
        Pair(-4, -13), Pair(157, -33), Pair(11, 149), Pair(-27, 145), Pair(38, 113), Pair(13, 28), Pair(-77, 126), Pair(53, -60),
        Pair(230, -113), Pair(-14, 29), Pair(-34, 85), Pair(-38, 168), Pair(0, 0), Pair(-87, 176), Pair(97, -103), Pair(-100, 11),
        Pair(97, -61), Pair(209, -71), Pair(-29, 120), Pair(-45, 72), Pair(30, 260), Pair(-167, -113), Pair(-24, 78), Pair(-31, 33)
      },
      { // Piece 3
        Pair(-56, -18), Pair(-119, 32), Pair(12, 16), Pair(69, -10), Pair(161, -10), Pair(28, -14), Pair(-3, -10), Pair(140, -25),
        Pair(76, -21), Pair(-7, 0), Pair(-92, 3), Pair(-99, 16), Pair(7, 42), Pair(40, -12), Pair(9, 21), Pair(-40, 55),
        Pair(39, -10), Pair(-9, -4), Pair(-36, 47), Pair(66, -26), Pair(109, 7), Pair(248, -122), Pair(225, -70), Pair(-66, 27),
        Pair(188, -38), Pair(-38, -1), Pair(-2, 7), Pair(-109, 17), Pair(139, -3), Pair(125, -75), Pair(-69, 27), Pair(21, -50),
        Pair(-129, 47), Pair(1, -26), Pair(58, -51), Pair(-97, -8), Pair(80, 24), Pair(-42, -3), Pair(188, -77), Pair(-19, 90),
        Pair(-109, 113), Pair(-124, 95), Pair(115, -54), Pair(5, 26), Pair(46, 66), Pair(60, -12), Pair(-26, 21), Pair(239, -48),
        Pair(101, 46), Pair(35, -34), Pair(83, 52), Pair(150, -7), Pair(0, 0), Pair(-63, 101), Pair(126, 2), Pair(31, -11),
        Pair(-57, 90), Pair(-55, 76), Pair(-82, 89), Pair(-51, -37), Pair(55, 117), Pair(-77, 13), Pair(16, 65), Pair(-110, 99)
      },
      { // Piece 4
        Pair(-78, 56), Pair(-27, -22), Pair(-17, 95), Pair(-40, 99), Pair(-16, -28), Pair(232, -30), Pair(-35, 33), Pair(60, -71),
        Pair(-94, 55), Pair(32, -45), Pair(57, -2), Pair(-108, 105), Pair(93, 80), Pair(-92, 182), Pair(-49, 72), Pair(9, 49),
        Pair(27, -78), Pair(87, 47), Pair(-108, 47), Pair(-109, 118), Pair(-34, -33), Pair(193, -160), Pair(87, -122), Pair(25, -90),
        Pair(-81, 120), Pair(-208, 162), Pair(-36, -100), Pair(134, -164), Pair(177, -133), Pair(47, -2), Pair(117, -102), Pair(98, -38),
        Pair(-124, 202), Pair(3, -2), Pair(-21, -17), Pair(-84, 5), Pair(-113, 75), Pair(-9, -14), Pair(22, -51), Pair(1, 21),
        Pair(-335, -5), Pair(59, -239), Pair(-55, -85), Pair(163, -381), Pair(78, 20), Pair(-117, 17), Pair(-34, 93), Pair(-38, -47),
        Pair(141, -147), Pair(-199, 119), Pair(62, -97), Pair(112, -140), Pair(0, 0), Pair(-13, -55), Pair(-57, 4), Pair(5, -105),
        Pair(40, -111), Pair(-217, 20), Pair(143, -244), Pair(-97, 28), Pair(7, -83), Pair(-80, -7), Pair(-110, 171), Pair(-27, -5)
      },
      { // Piece 5
        Pair(-102, 22), Pair(-37, -169), Pair(8, -43), Pair(-80, -164), Pair(51, -15), Pair(-14, -75), Pair(-12, 24), Pair(8, -64),
        Pair(1, -9), Pair(94, -31), Pair(-65, -139), Pair(88, -68), Pair(26, -6), Pair(68, -27), Pair(-103, -6), Pair(-10, 7),
        Pair(118, -43), Pair(8, -17), Pair(-76, 42), Pair(-64, 10), Pair(-5, 62), Pair(133, -81), Pair(32, 5), Pair(-179, 74),
        Pair(-56, -66), Pair(-87, 35), Pair(-15, 10), Pair(-49, -10), Pair(-138, 36), Pair(-22, 8), Pair(61, 1), Pair(0, -5),
        Pair(245, -82), Pair(104, -37), Pair(47, 6), Pair(-116, 25), Pair(-96, 71), Pair(-28, 49), Pair(58, -5), Pair(-108, 36),
        Pair(66, -52), Pair(13, -45), Pair(-131, 65), Pair(11, 93), Pair(1, 80), Pair(32, 73), Pair(59, 22), Pair(86, -60),
        Pair(135, -72), Pair(45, -39), Pair(194, -30), Pair(-169, 139), Pair(0, 0), Pair(-8, 96), Pair(-21, 47), Pair(17, -1),
        Pair(-57, -67), Pair(47, -56), Pair(-24, 52), Pair(-5, 77), Pair(-86, 182), Pair(28, 53), Pair(3, 0), Pair(32, -58)
      }
    }},
    {{ // Bucket 13
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-41, 17), Pair(11, -8), Pair(-51, -20), Pair(-12, -11), Pair(-57, 24), Pair(0, 0), Pair(-147, 45), Pair(-32, -9),
        Pair(45, -32), Pair(-47, -9), Pair(-56, 15), Pair(5, -19), Pair(-39, -19), Pair(-40, 1), Pair(-17, 20), Pair(66, -16),
        Pair(-7, -21), Pair(-3, -17), Pair(-46, -8), Pair(18, -23), Pair(-4, -9), Pair(40, -32), Pair(28, -16), Pair(9, -11),
        Pair(-35, -14), Pair(-14, -25), Pair(6, -25), Pair(11, -3), Pair(-22, -15), Pair(-3, -12), Pair(-28, -8), Pair(-3, -17),
        Pair(-13, -12), Pair(-23, -9), Pair(-36, -5), Pair(47, -27), Pair(-6, -19), Pair(13, 53), Pair(21, -15), Pair(12, -14),
        Pair(-7, -20), Pair(23, -40), Pair(0, -17), Pair(-128, 27), Pair(10, 16), Pair(0, 0), Pair(25, -10), Pair(7, -12),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-66, -98), Pair(-148, -212), Pair(-120, 34), Pair(172, 33), Pair(20, 41), Pair(-26, 38), Pair(-72, -35), Pair(-26, 111),
        Pair(-87, -269), Pair(-83, -87), Pair(154, 14), Pair(-54, -122), Pair(37, 20), Pair(-48, 80), Pair(26, -262), Pair(-228, -131),
        Pair(183, -81), Pair(-267, 55), Pair(90, 30), Pair(-86, 69), Pair(-17, -15), Pair(61, -61), Pair(124, 14), Pair(-8, 65),
        Pair(71, -55), Pair(26, -106), Pair(-19, -16), Pair(88, -46), Pair(-10, 4), Pair(138, -24), Pair(52, 16), Pair(-11, -49),
        Pair(-17, -165), Pair(-205, 43), Pair(-53, 42), Pair(103, -34), Pair(42, 67), Pair(143, 7), Pair(250, -24), Pair(-73, -27),
        Pair(20, -177), Pair(54, 38), Pair(-18, 84), Pair(-48, 0), Pair(-36, 69), Pair(83, -87), Pair(18, 57), Pair(109, -20),
        Pair(-52, -27), Pair(-16, -48), Pair(-31, -30), Pair(-125, 116), Pair(24, -33), Pair(0, 0), Pair(-1, 7), Pair(-111, 234),
        Pair(18, 77), Pair(-9, 74), Pair(8, -52), Pair(-54, -45), Pair(-135, -15), Pair(-33, 205), Pair(-117, -20), Pair(133, 83)
      },
      { // Piece 2
        Pair(-106, -18), Pair(-84, -127), Pair(14, 54), Pair(-271, 88), Pair(-140, 130), Pair(-94, -261), Pair(63, 197), Pair(-21, -90),
        Pair(-21, 20), Pair(32, 88), Pair(-21, -30), Pair(-202, 162), Pair(148, 11), Pair(-114, 130), Pair(64, 7), Pair(63, -2),
        Pair(-176, 211), Pair(106, -89), Pair(-29, 83), Pair(137, -46), Pair(-261, 115), Pair(75, -7), Pair(43, 142), Pair(60, -70),
        Pair(-45, -54), Pair(-132, 164), Pair(-120, 155), Pair(-109, 46), Pair(56, -22), Pair(235, -8), Pair(131, -55), Pair(-25, 45),
        Pair(-94, 133), Pair(-53, 22), Pair(-39, 161), Pair(45, -26), Pair(116, -7), Pair(-59, -117), Pair(-84, 134), Pair(90, 117),
        Pair(4, -4), Pair(-237, 101), Pair(-2, 8), Pair(-49, 164), Pair(33, -12), Pair(183, 3), Pair(-76, -24), Pair(-261, 211),
        Pair(-244, -47), Pair(56, -17), Pair(-34, 44), Pair(-99, 61), Pair(-116, 209), Pair(0, 0), Pair(-15, 107), Pair(-43, -128),
        Pair(79, -126), Pair(146, -20), Pair(31, -147), Pair(24, 48), Pair(-21, -54), Pair(-84, 271), Pair(54, 10), Pair(76, 29)
      },
      { // Piece 3
        Pair(106, -38), Pair(29, 53), Pair(-47, -12), Pair(17, 33), Pair(95, -77), Pair(85, 6), Pair(-8, -25), Pair(186, -19),
        Pair(33, -44), Pair(-79, -1), Pair(121, -81), Pair(-31, -36), Pair(19, 49), Pair(111, 2), Pair(61, -22), Pair(193, -103),
        Pair(-22, 28), Pair(-119, -8), Pair(-25, -21), Pair(125, -22), Pair(97, -25), Pair(110, 21), Pair(23, -5), Pair(87, -6),
        Pair(-39, 25), Pair(78, -33), Pair(-123, 23), Pair(-110, -32), Pair(11, -32), Pair(188, -13), Pair(58, -21), Pair(41, -53),
        Pair(22, 13), Pair(94, -26), Pair(57, 73), Pair(-47, 81), Pair(77, -9), Pair(75, -13), Pair(-66, 20), Pair(-91, 0),
        Pair(-13, -17), Pair(-172, -7), Pair(-81, 27), Pair(90, -77), Pair(-15, 9), Pair(9, 24), Pair(-177, 113), Pair(86, -65),
        Pair(130, 27), Pair(-121, 32), Pair(43, 94), Pair(-70, 49), Pair(5, 100), Pair(0, 0), Pair(369, -82), Pair(3, 71),
        Pair(-71, 85), Pair(-1, 20), Pair(10, 54), Pair(-49, 67), Pair(-23, 2), Pair(43, 109), Pair(-213, 85), Pair(51, 32)
      },
      { // Piece 4
        Pair(79, -116), Pair(-71, -33), Pair(-162, -83), Pair(-14, 37), Pair(102, -147), Pair(37, -75), Pair(24, -114), Pair(157, 114),
        Pair(-103, 157), Pair(-193, 52), Pair(-62, 74), Pair(-114, 67), Pair(23, -15), Pair(121, -119), Pair(-59, 21), Pair(-29, -126),
        Pair(122, -139), Pair(110, -157), Pair(39, -64), Pair(4, -109), Pair(-53, -57), Pair(-276, 67), Pair(-124, 63), Pair(-1, -159),
        Pair(-199, 122), Pair(76, -182), Pair(74, -99), Pair(57, 10), Pair(-134, 125), Pair(45, -44), Pair(-106, 56), Pair(9, -207),
        Pair(-61, -132), Pair(-68, 109), Pair(14, -117), Pair(7, 73), Pair(-116, 101), Pair(179, -79), Pair(-51, 74), Pair(-109, 143),
        Pair(-47, 114), Pair(-39, -118), Pair(52, -106), Pair(-94, 27), Pair(9, -63), Pair(-111, 27), Pair(174, 14), Pair(134, -93),
        Pair(56, -147), Pair(-6, 43), Pair(-67, 111), Pair(20, 51), Pair(-109, 96), Pair(0, 0), Pair(-51, 60), Pair(-38, -107),
        Pair(8, -89), Pair(-144, -56), Pair(-48, 2), Pair(6, -134), Pair(-85, -57), Pair(-56, -41), Pair(-14, -115), Pair(-34, -67)
      },
      { // Piece 5
        Pair(-28, -63), Pair(29, -40), Pair(60, -125), Pair(-13, 62), Pair(-81, -73), Pair(-52, -87), Pair(20, -74), Pair(52, 178),
        Pair(-19, -111), Pair(-97, -101), Pair(129, -165), Pair(54, -37), Pair(-41, -113), Pair(91, 31), Pair(-37, -110), Pair(14, -16),
        Pair(-80, -76), Pair(125, -42), Pair(196, -16), Pair(134, -68), Pair(-23, -32), Pair(-212, 39), Pair(175, 0), Pair(111, 18),
        Pair(12, -46), Pair(-104, -46), Pair(-28, 2), Pair(195, -83), Pair(-154, 52), Pair(-16, -29), Pair(-46, -8), Pair(18, -34),
        Pair(-39, -15), Pair(-27, -45), Pair(56, -5), Pair(96, -5), Pair(116, 6), Pair(100, 39), Pair(216, -24), Pair(206, -74),
        Pair(-104, -70), Pair(-201, 13), Pair(98, -59), Pair(14, 35), Pair(-83, 84), Pair(-113, 63), Pair(-68, 101), Pair(-97, 66),
        Pair(-104, -25), Pair(25, -29), Pair(53, 10), Pair(-146, 5), Pair(35, 90), Pair(0, 0), Pair(-58, 126), Pair(-64, 49),
        Pair(-163, -58), Pair(4, -78), Pair(-37, -23), Pair(65, -38), Pair(118, 135), Pair(-61, 158), Pair(92, 48), Pair(-100, 58)
      }
    }},
    {{ // Bucket 14
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-7, 2), Pair(40, 18), Pair(-27, -2), Pair(-145, 30), Pair(-7, 12), Pair(147, -45), Pair(0, 0), Pair(44, -30),
        Pair(-35, -14), Pair(-46, 2), Pair(34, -32), Pair(-14, -11), Pair(20, -9), Pair(-12, 7), Pair(33, -25), Pair(-19, -3),
        Pair(14, -17), Pair(-28, -22), Pair(-27, -19), Pair(-18, -13), Pair(-17, -9), Pair(13, -12), Pair(26, -13), Pair(52, -12),
        Pair(5, -21), Pair(25, -31), Pair(-22, -23), Pair(-14, -11), Pair(26, -32), Pair(-8, -17), Pair(-36, 5), Pair(23, -4),
        Pair(-4, -13), Pair(-11, -23), Pair(12, -19), Pair(-10, -14), Pair(15, -28), Pair(27, -14), Pair(6, 4), Pair(7, 7),
        Pair(14, -19), Pair(3, -23), Pair(31, -29), Pair(-13, 42), Pair(15, -46), Pair(31, -7), Pair(0, 0), Pair(28, -15),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(59, -56), Pair(-203, -74), Pair(132, -67), Pair(-76, -2), Pair(90, 54), Pair(252, -80), Pair(-45, -17), Pair(29, 2),
        Pair(-53, -108), Pair(-230, -37), Pair(270, -174), Pair(-94, 17), Pair(7, -107), Pair(-247, 35), Pair(-140, -40), Pair(-72, -57),
        Pair(16, -27), Pair(173, -98), Pair(-5, 11), Pair(116, -79), Pair(56, 5), Pair(-15, -83), Pair(39, -46), Pair(217, -210),
        Pair(-3, -27), Pair(-16, -18), Pair(-66, -19), Pair(61, -36), Pair(17, 44), Pair(-17, 71), Pair(9, -20), Pair(61, -39),
        Pair(-43, 11), Pair(66, -45), Pair(-39, 44), Pair(-62, 20), Pair(67, -44), Pair(106, -30), Pair(-163, 86), Pair(4, 102),
        Pair(37, 46), Pair(12, 35), Pair(108, -54), Pair(-73, 80), Pair(34, 79), Pair(-44, 146), Pair(19, 5), Pair(-94, 118),
        Pair(78, 34), Pair(209, 100), Pair(83, 52), Pair(-35, 60), Pair(-76, 126), Pair(109, -31), Pair(0, 0), Pair(64, -9),
        Pair(-42, -41), Pair(77, -138), Pair(-17, 50), Pair(-71, -43), Pair(20, 38), Pair(-78, -44), Pair(-8, 204), Pair(-29, -87)
      },
      { // Piece 2
        Pair(53, 84), Pair(-149, 88), Pair(-159, -79), Pair(-156, 174), Pair(37, 11), Pair(-136, 155), Pair(1, 27), Pair(-71, -21),
        Pair(-223, 204), Pair(-79, 150), Pair(-83, 128), Pair(-55, 13), Pair(-41, 115), Pair(-166, -48), Pair(-16, 81), Pair(93, -95),
        Pair(-38, -26), Pair(-278, 196), Pair(-47, 88), Pair(-31, 142), Pair(67, 6), Pair(99, 88), Pair(69, -43), Pair(-67, 13),
        Pair(-200, 127), Pair(68, -16), Pair(-139, 183), Pair(-4, 32), Pair(-68, 60), Pair(21, 44), Pair(-115, 88), Pair(186, 27),
        Pair(-31, -28), Pair(-244, 79), Pair(12, -11), Pair(-66, 180), Pair(-10, 46), Pair(-73, 92), Pair(179, -1), Pair(60, 68),
        Pair(-96, 62), Pair(-22, -2), Pair(-56, 68), Pair(37, -47), Pair(-26, 170), Pair(-54, -16), Pair(46, 55), Pair(72, 39),
        Pair(135, -3), Pair(-59, 90), Pair(-83, 0), Pair(-91, 50), Pair(-14, 9), Pair(47, 204), Pair(0, 0), Pair(-163, 221),
        Pair(138, 41), Pair(176, -27), Pair(-165, 103), Pair(31, -90), Pair(-274, 188), Pair(-57, -52), Pair(-2, 287), Pair(59, 37)
      },
      { // Piece 3
        Pair(-172, 56), Pair(-39, 18), Pair(23, 16), Pair(15, -19), Pair(332, -89), Pair(34, 19), Pair(196, 0), Pair(331, -54),
        Pair(85, -4), Pair(-59, 6), Pair(72, 50), Pair(192, -40), Pair(0, -52), Pair(78, -37), Pair(84, 29), Pair(-81, 53),
        Pair(-78, 12), Pair(-31, 3), Pair(-85, -8), Pair(129, -65), Pair(-45, -17), Pair(118, -9), Pair(-99, 57), Pair(11, 26),
        Pair(114, -5), Pair(78, -34), Pair(-81, 19), Pair(40, -77), Pair(137, -74), Pair(-24, -1), Pair(146, -19), Pair(238, -49),
        Pair(-95, -9), Pair(89, -21), Pair(12, -32), Pair(-57, -75), Pair(13, -44), Pair(227, -109), Pair(221, -38), Pair(49, 12),
        Pair(-26, -35), Pair(75, -34), Pair(120, -33), Pair(33, 29), Pair(109, -4), Pair(112, -127), Pair(235, -58), Pair(64, -42),
        Pair(-147, 55), Pair(-102, 68), Pair(-1, 46), Pair(-93, 13), Pair(9, -11), Pair(120, -18), Pair(0, 0), Pair(97, -60),
        Pair(-31, 52), Pair(19, 71), Pair(25, 53), Pair(-59, 115), Pair(42, 17), Pair(-16, -34), Pair(17, 128), Pair(-15, -43)
      },
      { // Piece 4
        Pair(-28, 146), Pair(-125, 84), Pair(-163, 45), Pair(-183, 10), Pair(-87, -22), Pair(29, 22), Pair(-134, -108), Pair(-46, -91),
        Pair(86, 2), Pair(-52, 10), Pair(-136, 215), Pair(-85, -50), Pair(6, 3), Pair(51, 18), Pair(36, 68), Pair(-113, 7),
        Pair(-61, -219), Pair(119, -65), Pair(12, -73), Pair(27, 56), Pair(21, 143), Pair(-151, -41), Pair(-51, 49), Pair(93, -35),
        Pair(25, 8), Pair(34, -83), Pair(16, -98), Pair(77, -36), Pair(-43, 50), Pair(106, -8), Pair(-205, 158), Pair(66, -41),
        Pair(-48, -96), Pair(-60, -3), Pair(12, -150), Pair(-2, -10), Pair(-83, 131), Pair(-138, 75), Pair(90, -164), Pair(133, -115),
        Pair(-85, -64), Pair(-56, -36), Pair(-134, 156), Pair(-36, 43), Pair(50, -44), Pair(12, -38), Pair(58, -65), Pair(-61, -140),
        Pair(54, -30), Pair(-48, -125), Pair(-27, -20), Pair(-55, 58), Pair(-174, 133), Pair(67, 83), Pair(0, 0), Pair(-239, -54),
        Pair(-62, -40), Pair(88, -42), Pair(20, -200), Pair(-17, -31), Pair(2, -119), Pair(-320, -162), Pair(83, -173), Pair(4, 3)
      },
      { // Piece 5
        Pair(43, -127), Pair(-10, -70), Pair(-36, -62), Pair(15, -130), Pair(-22, -40), Pair(31, -26), Pair(-15, -96), Pair(-26, -41),
        Pair(18, -44), Pair(-29, 9), Pair(148, -59), Pair(-27, -57), Pair(1, -38), Pair(75, -30), Pair(-10, -80), Pair(17, -1),
        Pair(-55, -84), Pair(-35, -57), Pair(-14, 15), Pair(-114, -3), Pair(252, -40), Pair(164, -4), Pair(-77, 1), Pair(-11, -104),
        Pair(24, -72), Pair(50, -40), Pair(-88, -2), Pair(-86, 44), Pair(-53, 44), Pair(40, 58), Pair(124, -70), Pair(11, 33),
        Pair(-113, -5), Pair(-12, -90), Pair(90, -53), Pair(-72, 30), Pair(258, -63), Pair(-65, 43), Pair(157, -12), Pair(15, -7),
        Pair(86, -155), Pair(-98, -71), Pair(135, -28), Pair(-171, 40), Pair(-84, 46), Pair(-49, 109), Pair(-206, 80), Pair(7, 36),
        Pair(-26, -117), Pair(-194, -41), Pair(-13, 1), Pair(12, -12), Pair(27, 5), Pair(-48, 146), Pair(0, 0), Pair(-22, 156),
        Pair(23, -61), Pair(-93, -103), Pair(121, -89), Pair(12, 1), Pair(-80, 55), Pair(34, 207), Pair(31, 175), Pair(174, -14)
      }
    }},
    {{ // Bucket 15
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-41, 6), Pair(4, -9), Pair(3, -12), Pair(24, -12), Pair(13, -13), Pair(32, 9), Pair(-44, 30), Pair(0, 0),
        Pair(-15, -2), Pair(48, -20), Pair(-13, 1), Pair(-17, -13), Pair(26, -17), Pair(41, -32), Pair(-21, 17), Pair(76, 41),
        Pair(57, -30), Pair(22, -14), Pair(12, -16), Pair(1, -10), Pair(-31, -18), Pair(-12, -3), Pair(23, -30), Pair(-87, 37),
        Pair(10, -29), Pair(-2, -25), Pair(-6, -21), Pair(7, -15), Pair(-7, -6), Pair(2, -10), Pair(27, -28), Pair(8, -102),
        Pair(29, -36), Pair(-5, -24), Pair(0, -22), Pair(1, -25), Pair(-17, -12), Pair(1, -17), Pair(23, -24), Pair(-42, -22),
        Pair(27, -33), Pair(-7, -25), Pair(-25, -15), Pair(6, -70), Pair(-30, 10), Pair(20, -21), Pair(26, -14), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-181, -90), Pair(31, -77), Pair(98, -182), Pair(-195, -25), Pair(105, 17), Pair(-18, -151), Pair(28, -69), Pair(90, -47),
        Pair(-69, -32), Pair(218, -183), Pair(-11, -49), Pair(-3, -39), Pair(225, -31), Pair(63, -53), Pair(360, -7), Pair(-199, -110),
        Pair(-60, -16), Pair(234, -71), Pair(-118, -10), Pair(20, -22), Pair(-44, -52), Pair(-69, 10), Pair(30, -78), Pair(-44, -99),
        Pair(19, -53), Pair(141, -127), Pair(-3, -85), Pair(47, -21), Pair(111, -48), Pair(142, -40), Pair(219, -128), Pair(141, -31),
        Pair(-25, -191), Pair(80, -52), Pair(-44, 67), Pair(45, -59), Pair(132, -104), Pair(22, -12), Pair(101, -58), Pair(191, -48),
        Pair(-133, 15), Pair(173, -148), Pair(65, -42), Pair(-48, 11), Pair(36, -5), Pair(-14, 83), Pair(-42, 76), Pair(116, -123),
        Pair(-184, -82), Pair(-37, 3), Pair(-45, -123), Pair(40, -105), Pair(-9, 11), Pair(-35, 106), Pair(28, -72), Pair(0, 0),
        Pair(36, 27), Pair(-10, -14), Pair(-324, 4), Pair(142, -106), Pair(-1, -80), Pair(-139, 42), Pair(-229, -174), Pair(-180, 206)
      },
      { // Piece 2
        Pair(-3, 189), Pair(-92, 2), Pair(59, 56), Pair(160, 33), Pair(60, 140), Pair(185, 1), Pair(-1, 123), Pair(-88, -195),
        Pair(75, -67), Pair(-56, 194), Pair(-74, 95), Pair(-88, 99), Pair(-89, 37), Pair(-81, 100), Pair(82, 14), Pair(59, 48),
        Pair(69, 111), Pair(246, -38), Pair(-59, 178), Pair(9, 27), Pair(77, 83), Pair(59, -27), Pair(-47, 24), Pair(-13, 76),
        Pair(69, 24), Pair(-18, 84), Pair(81, -49), Pair(70, 133), Pair(-35, 59), Pair(-71, 49), Pair(115, -83), Pair(20, 86),
        Pair(-65, 48), Pair(24, -33), Pair(3, 33), Pair(27, -40), Pair(-31, 136), Pair(39, 0), Pair(54, -27), Pair(232, 12),
        Pair(-49, -16), Pair(-61, 50), Pair(83, 5), Pair(68, 37), Pair(6, -94), Pair(-15, 160), Pair(-58, 92), Pair(-41, 91),
        Pair(-41, 111), Pair(-32, 68), Pair(-38, 67), Pair(-46, -25), Pair(-12, 60), Pair(114, -133), Pair(-2, 173), Pair(0, 0),
        Pair(-176, 42), Pair(52, -34), Pair(-35, -41), Pair(-40, 33), Pair(45, -72), Pair(-3, 79), Pair(-30, -113), Pair(89, 238)
      },
      { // Piece 3
        Pair(159, -29), Pair(-44, -16), Pair(-182, 76), Pair(27, -13), Pair(-82, 73), Pair(64, 11), Pair(132, -53), Pair(155, 4),
        Pair(-19, 5), Pair(-115, 25), Pair(137, -56), Pair(102, -75), Pair(-111, 75), Pair(-103, 47), Pair(51, -12), Pair(86, 21),
        Pair(3, -20), Pair(-43, 18), Pair(110, -34), Pair(-30, 10), Pair(146, -13), Pair(125, -55), Pair(55, -4), Pair(40, 16),
        Pair(93, -42), Pair(-51, 30), Pair(-25, -1), Pair(109, -31), Pair(-97, 2), Pair(157, -54), Pair(-25, -25), Pair(38, 35),
        Pair(135, -45), Pair(-21, 7), Pair(270, -63), Pair(20, 0), Pair(54, -58), Pair(141, -8), Pair(-50, -28), Pair(57, 16),
        Pair(172, -88), Pair(-72, 11), Pair(261, -69), Pair(56, 34), Pair(-4, 45), Pair(-59, 94), Pair(102, -32), Pair(32, 67),
        Pair(36, -43), Pair(60, -15), Pair(40, 71), Pair(-81, 90), Pair(-49, 146), Pair(129, -64), Pair(126, 29), Pair(0, 0),
        Pair(9, 104), Pair(-35, 98), Pair(-92, 102), Pair(7, 83), Pair(40, 39), Pair(81, 67), Pair(268, 32), Pair(62, 149)
      },
      { // Piece 4
        Pair(53, -2), Pair(-69, 51), Pair(-4, -15), Pair(-111, 49), Pair(68, 0), Pair(162, -175), Pair(-93, -28), Pair(71, 48),
        Pair(24, 150), Pair(-158, 131), Pair(-127, 122), Pair(-20, 210), Pair(-60, 19), Pair(37, 16), Pair(89, -41), Pair(-48, -40),
        Pair(116, -107), Pair(-122, 83), Pair(112, -133), Pair(-27, 6), Pair(-200, 143), Pair(114, -65), Pair(149, 118), Pair(-142, 123),
        Pair(-105, -126), Pair(73, -17), Pair(-70, 85), Pair(-67, 120), Pair(10, -51), Pair(4, -91), Pair(-36, 18), Pair(71, -141),
        Pair(58, -113), Pair(-51, 49), Pair(-127, 95), Pair(98, -178), Pair(-25, -23), Pair(-49, -112), Pair(-112, -37), Pair(152, -18),
        Pair(109, 144), Pair(-49, -19), Pair(-98, 30), Pair(-58, 80), Pair(20, -83), Pair(-66, -6), Pair(-3, -5), Pair(22, 3),
        Pair(161, -49), Pair(-3, 24), Pair(-31, -109), Pair(-42, -79), Pair(-52, 93), Pair(-62, 209), Pair(-3, -46), Pair(0, 0),
        Pair(97, -146), Pair(-251, 56), Pair(43, -24), Pair(-2, 42), Pair(-85, -56), Pair(-1, 98), Pair(-189, -129), Pair(-119, 97)
      },
      { // Piece 5
        Pair(44, -20), Pair(114, -160), Pair(37, -91), Pair(24, -88), Pair(2, 121), Pair(9, 37), Pair(45, 36), Pair(-30, -126),
        Pair(136, -107), Pair(40, -130), Pair(-81, -78), Pair(52, -7), Pair(12, -37), Pair(53, 12), Pair(-25, -66), Pair(-8, -153),
        Pair(-16, -70), Pair(-90, -48), Pair(-5, -18), Pair(-49, -27), Pair(333, -55), Pair(177, 14), Pair(64, 15), Pair(21, -16),
        Pair(206, -132), Pair(-45, -27), Pair(-156, 9), Pair(28, -2), Pair(66, 6), Pair(41, 41), Pair(98, -16), Pair(23, -96),
        Pair(-54, -62), Pair(-107, -73), Pair(185, -59), Pair(5, -5), Pair(-71, 29), Pair(-31, 52), Pair(-52, 57), Pair(-2, 46),
        Pair(104, -69), Pair(10, -90), Pair(-59, -42), Pair(45, -13), Pair(-85, 31), Pair(23, 54), Pair(-157, 136), Pair(-141, 105),
        Pair(-64, -21), Pair(-43, -71), Pair(-7, -64), Pair(-155, -3), Pair(-113, 79), Pair(-16, 50), Pair(-180, 188), Pair(0, 0),
        Pair(-64, -128), Pair(-74, -60), Pair(-73, -93), Pair(-104, 19), Pair(-180, 22), Pair(-282, 105), Pair(83, 146), Pair(153, 173)
      }
    }},
    {{ // Bucket 16
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(56, -14), Pair(26, 0), Pair(32, -7), Pair(-27, 20), Pair(-55, 32), Pair(-45, 32), Pair(36, 14), Pair(16, 3),
        Pair(0, 0), Pair(-13, -7), Pair(19, -10), Pair(7, -2), Pair(-3, 3), Pair(-6, 4), Pair(-10, 12), Pair(-10, 8),
        Pair(36, -41), Pair(6, -8), Pair(8, -12), Pair(7, -11), Pair(1, -4), Pair(-11, 2), Pair(-6, 4), Pair(-12, 11),
        Pair(6, -7), Pair(7, -5), Pair(4, -8), Pair(3, -13), Pair(0, 1), Pair(-7, -3), Pair(-4, -6), Pair(-10, 0),
        Pair(0, 0), Pair(3, -10), Pair(0, -14), Pair(1, -15), Pair(-8, -7), Pair(-11, -6), Pair(-2, -12), Pair(-8, -10),
        Pair(28, 48), Pair(-7, -14), Pair(6, -9), Pair(2, -8), Pair(-4, -4), Pair(-5, -9), Pair(-4, -8), Pair(-1, -13),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(13, 4), Pair(-55, 10), Pair(116, -15), Pair(118, -122), Pair(139, -58), Pair(51, -1), Pair(-69, -112), Pair(-179, -27),
        Pair(-73, 122), Pair(66, -39), Pair(158, -52), Pair(9, 8), Pair(77, 5), Pair(98, -27), Pair(-31, -18), Pair(102, -36),
        Pair(112, 26), Pair(82, -9), Pair(-6, 48), Pair(25, 22), Pair(26, -6), Pair(46, -15), Pair(70, -26), Pair(11, -16),
        Pair(39, 10), Pair(54, 30), Pair(46, 22), Pair(47, 11), Pair(28, 4), Pair(32, -4), Pair(41, -29), Pair(57, -42),
        Pair(26, 4), Pair(-4, 75), Pair(32, 19), Pair(19, 28), Pair(16, 15), Pair(55, -19), Pair(69, -48), Pair(40, -10),
        Pair(0, 0), Pair(8, 22), Pair(5, 61), Pair(6, 13), Pair(6, 22), Pair(25, 14), Pair(14, 3), Pair(26, -14),
        Pair(101, 135), Pair(31, -135), Pair(36, 27), Pair(13, 22), Pair(19, 18), Pair(33, -41), Pair(40, -39), Pair(53, -49),
        Pair(-58, 40), Pair(11, 70), Pair(22, 53), Pair(22, -65), Pair(39, -16), Pair(8, -10), Pair(49, -46), Pair(-37, -5)
      },
      { // Piece 2
        Pair(-171, 105), Pair(64, 48), Pair(-149, 117), Pair(-109, 72), Pair(120, 80), Pair(58, 101), Pair(-217, 198), Pair(50, 106),
        Pair(34, 31), Pair(-62, 62), Pair(101, 20), Pair(-11, 84), Pair(21, 95), Pair(-16, 156), Pair(81, 109), Pair(-45, 66),
        Pair(-104, 78), Pair(10, 62), Pair(-42, 60), Pair(-6, 117), Pair(-77, 153), Pair(29, 92), Pair(11, 65), Pair(59, 64),
        Pair(22, 63), Pair(13, 32), Pair(-9, 76), Pair(-18, 124), Pair(45, 78), Pair(-5, 55), Pair(47, 49), Pair(28, 33),
        Pair(30, 59), Pair(14, 127), Pair(-22, 118), Pair(23, 68), Pair(27, 23), Pair(18, 25), Pair(-31, 77), Pair(16, 34),
        Pair(0, 0), Pair(-29, 140), Pair(16, 81), Pair(1, 54), Pair(15, 57), Pair(9, 18), Pair(1, 55), Pair(-3, 40),
        Pair(24, 231), Pair(-17, 36), Pair(10, 43), Pair(26, 68), Pair(-10, 35), Pair(3, 50), Pair(-4, 16), Pair(0, 41),
        Pair(20, 34), Pair(-58, 155), Pair(13, 50), Pair(24, 35), Pair(18, 49), Pair(-3, 17), Pair(-19, 88), Pair(57, 28)
      },
      { // Piece 3
        Pair(42, 124), Pair(11, 95), Pair(35, 96), Pair(36, 92), Pair(40, 105), Pair(234, 33), Pair(54, 77), Pair(89, 70),
        Pair(48, 143), Pair(10, 105), Pair(52, 93), Pair(5, 107), Pair(92, 73), Pair(58, 72), Pair(-10, 121), Pair(73, 72),
        Pair(17, 145), Pair(35, 66), Pair(29, 104), Pair(78, 67), Pair(67, 70), Pair(39, 72), Pair(18, 60), Pair(25, 82),
        Pair(6, 151), Pair(-3, 92), Pair(-3, 93), Pair(1, 84), Pair(42, 76), Pair(47, 54), Pair(61, 79), Pair(37, 68),
        Pair(21, 130), Pair(34, 78), Pair(58, 73), Pair(18, 81), Pair(23, 74), Pair(41, 55), Pair(31, 55), Pair(0, 82),
        Pair(0, 0), Pair(21, 129), Pair(-1, 114), Pair(4, 91), Pair(6, 80), Pair(37, 64), Pair(73, 35), Pair(40, 65),
        Pair(25, 133), Pair(22, 33), Pair(-2, 113), Pair(7, 99), Pair(-5, 102), Pair(19, 101), Pair(-13, 132), Pair(-48, 131),
        Pair(-9, 117), Pair(19, 66), Pair(5, 90), Pair(11, 85), Pair(5, 107), Pair(19, 76), Pair(57, 48), Pair(28, 84)
      },
      { // Piece 4
        Pair(88, 115), Pair(166, 49), Pair(61, 181), Pair(-62, 203), Pair(56, 160), Pair(175, 123), Pair(125, 135), Pair(93, 178),
        Pair(50, 133), Pair(-7, 244), Pair(31, 195), Pair(-31, 240), Pair(35, 204), Pair(99, 153), Pair(53, 167), Pair(86, 148),
        Pair(-11, 211), Pair(85, 59), Pair(30, 152), Pair(37, 198), Pair(12, 180), Pair(63, 107), Pair(123, 73), Pair(55, 144),
        Pair(73, 159), Pair(62, 131), Pair(24, 174), Pair(16, 215), Pair(35, 160), Pair(69, 155), Pair(71, 126), Pair(63, 125),
        Pair(-16, 192), Pair(-27, 238), Pair(23, 166), Pair(26, 139), Pair(4, 184), Pair(47, 131), Pair(53, 101), Pair(52, 142),
        Pair(0, 0), Pair(33, 149), Pair(32, 127), Pair(32, 106), Pair(25, 113), Pair(41, 88), Pair(25, 124), Pair(64, 80),
        Pair(-43, 179), Pair(48, 115), Pair(31, 140), Pair(27, 100), Pair(30, 110), Pair(19, 128), Pair(23, 130), Pair(62, 119),
        Pair(6, 154), Pair(39, 105), Pair(7, 168), Pair(27, 127), Pair(7, 151), Pair(-2, 155), Pair(-17, 130), Pair(-55, 220)
      },
      { // Piece 5
        Pair(-52, -58), Pair(-20, -46), Pair(16, 49), Pair(176, -2), Pair(54, -90), Pair(43, -129), Pair(85, -112), Pair(161, -86),
        Pair(70, -136), Pair(-192, -52), Pair(61, -19), Pair(5, 0), Pair(83, -51), Pair(179, -105), Pair(177, -128), Pair(103, -53),
        Pair(70, -25), Pair(53, 2), Pair(121, -9), Pair(83, -23), Pair(115, -40), Pair(58, -52), Pair(198, -93), Pair(145, -88),
        Pair(18, -112), Pair(113, -3), Pair(-92, 32), Pair(69, -13), Pair(134, -23), Pair(144, -44), Pair(65, -57), Pair(64, -73),
        Pair(-92, -15), Pair(-203, 91), Pair(20, 12), Pair(38, -9), Pair(-26, 0), Pair(74, -41), Pair(8, -57), Pair(42, -45),
        Pair(0, 0), Pair(-212, 126), Pair(-51, 34), Pair(-60, 19), Pair(-6, -25), Pair(28, -42), Pair(47, -62), Pair(77, -77),
        Pair(54, 94), Pair(30, 16), Pair(-103, 64), Pair(4, -5), Pair(-4, -19), Pair(-9, -46), Pair(-10, -52), Pair(2, -54),
        Pair(0, 74), Pair(-69, 76), Pair(-74, 39), Pair(-83, 24), Pair(-23, -20), Pair(17, -61), Pair(-7, -72), Pair(5, -80)
      }
    }},
    {{ // Bucket 17
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-56, 21), Pair(82, 6), Pair(51, -2), Pair(-1, 32), Pair(5, 15), Pair(47, 10), Pair(45, -2), Pair(-48, 19),
        Pair(12, 6), Pair(0, 0), Pair(18, -15), Pair(4, -8), Pair(7, 2), Pair(-6, 21), Pair(31, 7), Pair(-14, 12),
        Pair(5, -7), Pair(-2, -9), Pair(1, -3), Pair(0, -8), Pair(-10, 0), Pair(-5, 1), Pair(-3, 5), Pair(10, 8),
        Pair(5, -4), Pair(13, -10), Pair(4, -7), Pair(3, -9), Pair(-3, -8), Pair(-10, -1), Pair(-3, -5), Pair(3, -2),
        Pair(15, -5), Pair(0, 0), Pair(12, -5), Pair(-2, -6), Pair(-2, -6), Pair(-5, -9), Pair(-12, -6), Pair(-1, -11),
        Pair(19, -5), Pair(37, 48), Pair(2, -11), Pair(2, -17), Pair(-8, -6), Pair(-10, -9), Pair(-5, -7), Pair(-1, -7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(37, -62), Pair(-98, -82), Pair(-41, 38), Pair(-55, -37), Pair(-71, 19), Pair(91, 4), Pair(-26, -23), Pair(-49, -36),
        Pair(182, 25), Pair(30, -27), Pair(91, 55), Pair(59, -6), Pair(34, 8), Pair(39, 9), Pair(9, -35), Pair(62, 49),
        Pair(213, -16), Pair(39, 37), Pair(33, 37), Pair(67, 27), Pair(37, 49), Pair(58, 10), Pair(11, -30), Pair(98, -37),
        Pair(10, 92), Pair(-7, 73), Pair(-22, 89), Pair(8, 31), Pair(26, 40), Pair(83, -9), Pair(47, 7), Pair(47, 11),
        Pair(-53, 135), Pair(15, 15), Pair(3, 111), Pair(7, 43), Pair(44, 44), Pair(37, -3), Pair(23, 43), Pair(57, -21),
        Pair(36, 13), Pair(0, 0), Pair(0, 60), Pair(-10, 114), Pair(7, 47), Pair(40, 25), Pair(9, 15), Pair(49, 6),
        Pair(60, -53), Pair(66, 184), Pair(-119, 20), Pair(27, 53), Pair(15, 30), Pair(-18, 15), Pair(56, -5), Pair(18, 52),
        Pair(-91, -76), Pair(-2, 63), Pair(86, -57), Pair(9, 90), Pair(40, -22), Pair(25, -27), Pair(-105, 73), Pair(40, 1)
      },
      { // Piece 2
        Pair(91, 10), Pair(-28, 57), Pair(-49, 57), Pair(-13, 92), Pair(-155, 113), Pair(-73, 84), Pair(-23, 89), Pair(-2, 171),
        Pair(92, 68), Pair(-34, 64), Pair(-12, 59), Pair(-89, 55), Pair(-36, 104), Pair(3, 129), Pair(-34, 195), Pair(13, 98),
        Pair(51, 49), Pair(-17, 56), Pair(52, 49), Pair(-30, 88), Pair(33, 71), Pair(11, 145), Pair(-66, 131), Pair(42, 39),
        Pair(-1, 48), Pair(5, 61), Pair(-7, 81), Pair(8, 89), Pair(-23, 142), Pair(-15, 94), Pair(18, 47), Pair(41, 50),
        Pair(-53, 57), Pair(34, 26), Pair(28, 63), Pair(-6, 143), Pair(14, 84), Pair(-13, 55), Pair(-27, 102), Pair(3, 3),
        Pair(26, 173), Pair(0, 0), Pair(1, 121), Pair(12, 78), Pair(0, 66), Pair(10, 52), Pair(-2, 58), Pair(14, 36),
        Pair(-184, 130), Pair(31, 222), Pair(17, 43), Pair(4, 49), Pair(-12, 71), Pair(-27, 53), Pair(15, 40), Pair(-10, 15),
        Pair(-38, 207), Pair(-24, 57), Pair(-26, 117), Pair(-17, 35), Pair(-34, 56), Pair(32, 65), Pair(-11, 82), Pair(-44, 103)
      },
      { // Piece 3
        Pair(89, 50), Pair(-8, 111), Pair(-19, 87), Pair(152, 8), Pair(85, 51), Pair(159, 30), Pair(90, 77), Pair(105, 49),
        Pair(46, 78), Pair(22, 126), Pair(27, 89), Pair(45, 96), Pair(57, 75), Pair(136, 40), Pair(102, 64), Pair(122, 49),
        Pair(21, 68), Pair(51, 116), Pair(74, 74), Pair(50, 73), Pair(135, 27), Pair(77, 53), Pair(154, 24), Pair(55, 53),
        Pair(46, 46), Pair(-11, 130), Pair(-12, 91), Pair(82, 28), Pair(-26, 82), Pair(-34, 72), Pair(-9, 73), Pair(95, 22),
        Pair(-16, 53), Pair(27, 111), Pair(-13, 68), Pair(-15, 56), Pair(36, 71), Pair(-44, 79), Pair(27, 47), Pair(17, 36),
        Pair(0, 43), Pair(0, 0), Pair(10, 96), Pair(37, 88), Pair(-33, 90), Pair(-4, 59), Pair(40, 55), Pair(36, 50),
        Pair(-80, 25), Pair(-2, 137), Pair(-31, 68), Pair(-38, 117), Pair(21, 80), Pair(-6, 108), Pair(-23, 127), Pair(-44, 143),
        Pair(-18, 74), Pair(-11, 108), Pair(-2, 82), Pair(-15, 95), Pair(-3, 77), Pair(12, 69), Pair(20, 77), Pair(30, 79)
      },
      { // Piece 4
        Pair(155, -45), Pair(77, 68), Pair(9, 151), Pair(40, 89), Pair(83, 127), Pair(128, 91), Pair(33, 156), Pair(80, 164),
        Pair(111, 27), Pair(25, 120), Pair(62, 94), Pair(-15, 177), Pair(68, 160), Pair(86, 251), Pair(9, 174), Pair(-20, 227),
        Pair(31, 148), Pair(73, 113), Pair(106, -4), Pair(-14, 148), Pair(76, 138), Pair(17, 120), Pair(110, 112), Pair(97, 27),
        Pair(89, -55), Pair(76, 104), Pair(-65, 264), Pair(75, 61), Pair(71, 156), Pair(30, 183), Pair(54, 79), Pair(102, 130),
        Pair(-56, 137), Pair(109, 33), Pair(-56, 195), Pair(30, 154), Pair(48, 88), Pair(70, -6), Pair(16, 124), Pair(48, 128),
        Pair(42, 62), Pair(0, 0), Pair(21, 134), Pair(22, 106), Pair(58, 37), Pair(53, 111), Pair(25, 167), Pair(29, 153),
        Pair(24, -28), Pair(-2, 126), Pair(39, 27), Pair(28, 105), Pair(36, 79), Pair(54, 54), Pair(34, 74), Pair(64, 30),
        Pair(2, 76), Pair(-28, 145), Pair(21, 69), Pair(26, 30), Pair(9, 139), Pair(57, -51), Pair(165, -37), Pair(48, 10)
      },
      { // Piece 5
        Pair(-68, -154), Pair(-84, -137), Pair(50, -32), Pair(-30, -22), Pair(-5, 4), Pair(-43, -80), Pair(-80, -39), Pair(25, -85),
        Pair(-36, -1), Pair(27, -34), Pair(-15, -52), Pair(-86, 27), Pair(151, -47), Pair(68, -72), Pair(11, -70), Pair(127, -116),
        Pair(122, -26), Pair(10, -51), Pair(123, -11), Pair(149, 2), Pair(79, -22), Pair(68, -23), Pair(26, -78), Pair(120, -101),
        Pair(-9, -54), Pair(115, -33), Pair(126, 5), Pair(76, -17), Pair(60, -18), Pair(-66, 19), Pair(-42, -5), Pair(151, -100),
        Pair(119, 39), Pair(-92, 48), Pair(-70, 60), Pair(42, -4), Pair(-79, 13), Pair(-40, -6), Pair(-15, -45), Pair(127, -103),
        Pair(-271, 173), Pair(0, 0), Pair(-153, 92), Pair(-6, 14), Pair(-62, 15), Pair(34, -32), Pair(37, -64), Pair(70, -73),
        Pair(69, 69), Pair(-181, 125), Pair(23, 104), Pair(-92, 29), Pair(-53, 4), Pair(-52, -22), Pair(-11, -42), Pair(-2, -52),
        Pair(-88, 51), Pair(-112, 59), Pair(-93, 72), Pair(-108, 7), Pair(-32, -20), Pair(-14, -48), Pair(3, -72), Pair(21, -101)
      }
    }},
    {{ // Bucket 18
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-17, 34), Pair(11, 5), Pair(-51, 10), Pair(5, 15), Pair(7, 13), Pair(57, -14), Pair(-34, 32), Pair(13, -1),
        Pair(-19, 11), Pair(-18, 14), Pair(0, 0), Pair(-5, -8), Pair(-3, 7), Pair(12, 3), Pair(11, 2), Pair(-25, 17),
        Pair(-8, -1), Pair(-3, -1), Pair(-21, 6), Pair(1, 0), Pair(3, -3), Pair(-9, -1), Pair(-5, 5), Pair(-2, 5),
        Pair(0, -9), Pair(-2, -8), Pair(0, -7), Pair(4, -2), Pair(-1, 2), Pair(-4, -2), Pair(-4, -2), Pair(-9, -3),
        Pair(-4, -2), Pair(2, -4), Pair(0, 0), Pair(7, -4), Pair(-8, -1), Pair(-16, -3), Pair(-7, -9), Pair(-8, -4),
        Pair(-1, -1), Pair(7, -3), Pair(31, 49), Pair(-15, -27), Pair(-2, -4), Pair(-3, -8), Pair(-8, -5), Pair(-7, -8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-16, 86), Pair(108, -4), Pair(5, 31), Pair(83, -13), Pair(223, 21), Pair(111, 21), Pair(85, -132), Pair(-126, -2),
        Pair(-15, -2), Pair(76, -23), Pair(-81, -12), Pair(48, 10), Pair(36, 57), Pair(70, 21), Pair(18, 58), Pair(78, -77),
        Pair(201, 6), Pair(52, 13), Pair(19, 79), Pair(25, 61), Pair(23, 44), Pair(43, 12), Pair(2, 64), Pair(61, 19),
        Pair(63, 30), Pair(80, 24), Pair(29, 74), Pair(1, 83), Pair(39, 41), Pair(16, 46), Pair(55, 8), Pair(113, -6),
        Pair(15, 79), Pair(-38, 154), Pair(19, 47), Pair(-7, 127), Pair(17, 51), Pair(17, 48), Pair(50, 67), Pair(36, 71),
        Pair(-52, 151), Pair(2, 58), Pair(0, 0), Pair(22, 62), Pair(-2, 140), Pair(35, 15), Pair(33, 33), Pair(38, -9),
        Pair(45, 48), Pair(-45, -157), Pair(48, 199), Pair(-10, -79), Pair(45, 59), Pair(31, 21), Pair(-7, 37), Pair(-13, 37),
        Pair(-35, 149), Pair(2, -56), Pair(19, 80), Pair(-18, 47), Pair(-21, 153), Pair(-30, 72), Pair(32, 21), Pair(281, -117)
      },
      { // Piece 2
        Pair(20, 51), Pair(-23, 43), Pair(39, 64), Pair(-45, 85), Pair(-51, 98), Pair(-17, 113), Pair(81, 100), Pair(16, -9),
        Pair(-11, 57), Pair(-34, 88), Pair(0, 69), Pair(46, 75), Pair(-47, 76), Pair(-81, 83), Pair(-11, 114), Pair(40, 146),
        Pair(48, 66), Pair(-15, 48), Pair(24, 84), Pair(2, 84), Pair(-5, 72), Pair(-25, 87), Pair(51, 141), Pair(10, 91),
        Pair(-26, 89), Pair(12, 53), Pair(-5, 79), Pair(1, 90), Pair(-2, 57), Pair(0, 146), Pair(-16, 95), Pair(14, 80),
        Pair(-99, 164), Pair(9, 67), Pair(42, 55), Pair(11, 62), Pair(6, 140), Pair(-10, 90), Pair(18, 57), Pair(20, 32),
        Pair(14, 45), Pair(19, 161), Pair(0, 0), Pair(4, 151), Pair(4, 88), Pair(-9, 68), Pair(9, 37), Pair(-7, 61),
        Pair(-26, 52), Pair(-23, -13), Pair(42, 222), Pair(10, -83), Pair(14, 58), Pair(37, 34), Pair(16, 33), Pair(41, 1),
        Pair(-106, -27), Pair(-67, 149), Pair(10, 50), Pair(-52, 166), Pair(-75, 87), Pair(6, 62), Pair(3, 99), Pair(30, 19)
      },
      { // Piece 3
        Pair(21, 78), Pair(67, 42), Pair(94, 87), Pair(84, 48), Pair(13, 67), Pair(34, 75), Pair(30, 68), Pair(-88, 97),
        Pair(3, 67), Pair(-8, 102), Pair(90, 103), Pair(31, 63), Pair(41, 70), Pair(134, 53), Pair(243, 33), Pair(87, 50),
        Pair(-23, 77), Pair(-21, 85), Pair(23, 109), Pair(35, 58), Pair(-27, 83), Pair(-52, 88), Pair(-4, 63), Pair(14, 53),
        Pair(35, 50), Pair(5, 62), Pair(18, 103), Pair(13, 48), Pair(-17, 108), Pair(11, 48), Pair(104, 36), Pair(91, 41),
        Pair(-33, 77), Pair(13, 53), Pair(61, 93), Pair(4, 83), Pair(-6, 87), Pair(25, 47), Pair(45, 61), Pair(14, 29),
        Pair(-55, 91), Pair(-48, 131), Pair(0, 0), Pair(-24, 117), Pair(-11, 75), Pair(10, 56), Pair(-9, 92), Pair(-5, 51),
        Pair(-103, 143), Pair(-51, 25), Pair(-30, 163), Pair(-29, 95), Pair(-4, 121), Pair(2, 129), Pair(25, 82), Pair(-41, 130),
        Pair(-13, 84), Pair(0, 40), Pair(-37, 128), Pair(-13, 86), Pair(3, 67), Pair(10, 55), Pair(18, 70), Pair(11, 55)
      },
      { // Piece 4
        Pair(94, 108), Pair(155, 58), Pair(34, 130), Pair(63, 105), Pair(129, 82), Pair(10, 110), Pair(60, 91), Pair(68, 99),
        Pair(68, 60), Pair(19, 158), Pair(88, 150), Pair(86, 82), Pair(-57, 291), Pair(103, 81), Pair(163, 2), Pair(86, 86),
        Pair(-5, 110), Pair(43, 68), Pair(44, 116), Pair(43, 189), Pair(42, 104), Pair(16, 109), Pair(64, 215), Pair(116, -8),
        Pair(75, 3), Pair(77, 48), Pair(48, 124), Pair(33, 166), Pair(33, 123), Pair(5, 182), Pair(76, 38), Pair(96, 82),
        Pair(36, 153), Pair(75, 104), Pair(84, 61), Pair(27, 121), Pair(-10, 203), Pair(72, 42), Pair(45, 95), Pair(24, 143),
        Pair(-40, 136), Pair(51, 58), Pair(0, 0), Pair(32, 161), Pair(1, 86), Pair(25, 108), Pair(78, 31), Pair(-19, 184),
        Pair(53, 56), Pair(53, -117), Pair(32, 107), Pair(36, 67), Pair(35, 85), Pair(44, 57), Pair(10, 118), Pair(17, 51),
        Pair(-14, 167), Pair(-15, 124), Pair(-6, 123), Pair(17, 77), Pair(46, -5), Pair(33, 91), Pair(83, -10), Pair(68, 154)
      },
      { // Piece 5
        Pair(-31, 16), Pair(-137, -161), Pair(-62, -251), Pair(66, 95), Pair(-7, -102), Pair(-15, -49), Pair(56, -136), Pair(-48, -114),
        Pair(-33, -89), Pair(24, -4), Pair(-30, -10), Pair(15, 6), Pair(8, -79), Pair(-61, -12), Pair(176, -76), Pair(-83, -82),
        Pair(82, 5), Pair(37, -33), Pair(176, -80), Pair(150, -81), Pair(137, -25), Pair(71, -20), Pair(98, -38), Pair(1, -103),
        Pair(129, -6), Pair(118, -41), Pair(107, -14), Pair(185, -14), Pair(160, -30), Pair(80, -3), Pair(54, -26), Pair(-19, -61),
        Pair(272, 29), Pair(35, 29), Pair(29, 5), Pair(72, 29), Pair(47, 0), Pair(3, -4), Pair(-45, -3), Pair(13, -75),
        Pair(-24, 49), Pair(-142, 114), Pair(0, 0), Pair(-50, 68), Pair(-14, 9), Pair(-13, 0), Pair(29, -27), Pair(-12, -48),
        Pair(-205, 58), Pair(44, 110), Pair(-202, 135), Pair(55, 113), Pair(-54, 26), Pair(27, -19), Pair(-11, -24), Pair(-5, -50),
        Pair(-172, 73), Pair(-82, 12), Pair(-160, 116), Pair(-84, 99), Pair(-34, -6), Pair(30, -15), Pair(-10, -56), Pair(23, -103)
      }
    }},
    {{ // Bucket 19
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-18, 12), Pair(-26, 29), Pair(-44, 12), Pair(8, 17), Pair(-34, 13), Pair(-5, 19), Pair(14, 11), Pair(16, 13),
        Pair(-8, 3), Pair(-5, 9), Pair(5, 7), Pair(0, 0), Pair(15, -2), Pair(-6, 5), Pair(19, 7), Pair(-18, 8),
        Pair(-6, 2), Pair(-6, -6), Pair(2, 0), Pair(6, -7), Pair(3, -6), Pair(1, -8), Pair(-2, -4), Pair(5, -2),
        Pair(-4, -12), Pair(5, -18), Pair(-2, -4), Pair(3, -13), Pair(8, -10), Pair(3, -3), Pair(-1, -10), Pair(-12, 0),
        Pair(-1, -7), Pair(-7, -4), Pair(-5, 3), Pair(0, 0), Pair(6, -5), Pair(-8, 1), Pair(-3, -8), Pair(-11, -3),
        Pair(2, -11), Pair(-2, -6), Pair(12, -41), Pair(22, 43), Pair(-11, -18), Pair(-3, -4), Pair(7, -15), Pair(-5, -4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-129, 45), Pair(-344, 201), Pair(64, 4), Pair(240, 55), Pair(-159, 95), Pair(171, -16), Pair(69, -85), Pair(200, -229),
        Pair(-62, 98), Pair(47, 33), Pair(-46, 72), Pair(91, 12), Pair(67, 36), Pair(50, 8), Pair(97, -29), Pair(-60, 70),
        Pair(62, -32), Pair(30, 66), Pair(-10, 45), Pair(28, 43), Pair(57, 52), Pair(26, 36), Pair(31, 23), Pair(9, 86),
        Pair(7, 50), Pair(14, 59), Pair(40, 46), Pair(-3, 58), Pair(60, 36), Pair(61, 16), Pair(28, 24), Pair(-10, 46),
        Pair(30, 84), Pair(-39, 102), Pair(-3, 147), Pair(1, 34), Pair(16, 122), Pair(5, 29), Pair(2, 54), Pair(37, 54),
        Pair(-25, -13), Pair(-4, 138), Pair(3, 66), Pair(0, 0), Pair(-10, 66), Pair(4, 117), Pair(6, 19), Pair(30, 30),
        Pair(6, -7), Pair(11, 83), Pair(-23, 2), Pair(19, 219), Pair(-53, -1), Pair(4, 102), Pair(53, 69), Pair(44, 15),
        Pair(-60, -61), Pair(-18, 110), Pair(20, -1), Pair(-28, 114), Pair(33, 35), Pair(4, 141), Pair(16, -35), Pair(-80, -26)
      },
      { // Piece 2
        Pair(-112, 135), Pair(-283, 179), Pair(110, 26), Pair(-62, 126), Pair(-21, 98), Pair(-14, 58), Pair(-179, 53), Pair(154, 118),
        Pair(15, 62), Pair(4, 71), Pair(-5, 45), Pair(58, 97), Pair(-56, 115), Pair(-32, 126), Pair(-68, 125), Pair(-50, 139),
        Pair(25, 37), Pair(-7, 83), Pair(-6, 78), Pair(29, 47), Pair(-40, 108), Pair(71, 65), Pair(-21, 112), Pair(-16, 130),
        Pair(28, 134), Pair(-4, 55), Pair(60, 43), Pair(35, 67), Pair(22, 62), Pair(-39, 112), Pair(-22, 156), Pair(-17, 56),
        Pair(-12, 74), Pair(-20, 142), Pair(-18, 72), Pair(51, 33), Pair(-32, 92), Pair(-19, 140), Pair(-7, 69), Pair(-22, 78),
        Pair(-18, 100), Pair(-20, 112), Pair(17, 139), Pair(0, 0), Pair(3, 148), Pair(15, 70), Pair(3, 35), Pair(7, 48),
        Pair(-7, 76), Pair(5, 54), Pair(-92, -49), Pair(24, 216), Pair(-3, -80), Pair(32, -2), Pair(21, 23), Pair(1, 19),
        Pair(20, 36), Pair(-21, 15), Pair(-26, 128), Pair(15, 87), Pair(-60, 168), Pair(32, -38), Pair(35, -1), Pair(37, 26)
      },
      { // Piece 3
        Pair(39, 49), Pair(2, 63), Pair(40, 63), Pair(70, 81), Pair(6, 71), Pair(117, 16), Pair(98, 48), Pair(4, 92),
        Pair(20, 64), Pair(-13, 86), Pair(6, 68), Pair(-66, 128), Pair(-17, 88), Pair(45, 69), Pair(-65, 94), Pair(71, 71),
        Pair(50, 43), Pair(9, 61), Pair(-21, 78), Pair(44, 94), Pair(23, 77), Pair(84, 14), Pair(86, 31), Pair(-33, 89),
        Pair(66, 34), Pair(26, 53), Pair(-3, 87), Pair(19, 97), Pair(21, 47), Pair(45, 38), Pair(21, 56), Pair(18, 56),
        Pair(21, 56), Pair(-8, 58), Pair(7, 73), Pair(13, 119), Pair(10, 55), Pair(-3, 76), Pair(1, 27), Pair(14, 51),
        Pair(-23, 98), Pair(-7, 94), Pair(-27, 89), Pair(0, 0), Pair(19, 85), Pair(95, 39), Pair(46, 34), Pair(25, 44),
        Pair(-59, 134), Pair(-71, 153), Pair(62, -29), Pair(-16, 176), Pair(-59, 62), Pair(-4, 123), Pair(5, 101), Pair(46, 90),
        Pair(1, 76), Pair(-9, 85), Pair(-12, 83), Pair(-28, 145), Pair(13, 62), Pair(15, 70), Pair(1, 102), Pair(14, 69)
      },
      { // Piece 4
        Pair(66, 77), Pair(14, 117), Pair(68, 95), Pair(-2, 197), Pair(-41, 212), Pair(35, 208), Pair(-5, 77), Pair(53, 150),
        Pair(72, 39), Pair(12, 114), Pair(86, 46), Pair(72, 92), Pair(71, 104), Pair(-6, 176), Pair(189, 28), Pair(78, 20),
        Pair(94, -74), Pair(-13, 134), Pair(62, 37), Pair(17, 159), Pair(26, 217), Pair(-5, 209), Pair(-8, 118), Pair(14, 147),
        Pair(34, 137), Pair(36, 95), Pair(46, 64), Pair(73, 116), Pair(68, 91), Pair(1, 144), Pair(18, 189), Pair(37, 124),
        Pair(11, 114), Pair(14, 157), Pair(87, -49), Pair(48, 137), Pair(53, 143), Pair(68, 68), Pair(0, 125), Pair(-6, 171),
        Pair(107, -46), Pair(23, 49), Pair(42, 100), Pair(0, 0), Pair(47, 81), Pair(37, 54), Pair(44, 62), Pair(6, 68),
        Pair(18, 82), Pair(10, 114), Pair(14, -27), Pair(41, 93), Pair(15, 22), Pair(53, 88), Pair(-25, 154), Pair(68, 73),
        Pair(-33, 147), Pair(23, 1), Pair(12, 81), Pair(25, 55), Pair(20, 130), Pair(47, 92), Pair(32, 73), Pair(80, -20)
      },
      { // Piece 5
        Pair(-29, -101), Pair(-5, -118), Pair(23, -116), Pair(5, -46), Pair(-38, -100), Pair(-39, -28), Pair(-95, -102), Pair(-216, -80),
        Pair(48, 30), Pair(12, -53), Pair(9, -12), Pair(16, -80), Pair(-150, 21), Pair(-42, -24), Pair(-65, -2), Pair(48, -3),
        Pair(91, -157), Pair(-29, -45), Pair(98, -18), Pair(2, -38), Pair(146, 21), Pair(-34, -12), Pair(-122, 5), Pair(-45, -46),
        Pair(78, -30), Pair(60, -10), Pair(282, -80), Pair(153, -62), Pair(9, -18), Pair(22, -28), Pair(-17, -14), Pair(-51, -7),
        Pair(-97, -107), Pair(64, -29), Pair(-43, 33), Pair(-63, 38), Pair(23, 28), Pair(109, -18), Pair(27, -3), Pair(21, -43),
        Pair(41, 20), Pair(-129, 12), Pair(-56, 74), Pair(0, 0), Pair(-76, 61), Pair(-28, 16), Pair(13, -11), Pair(47, -60),
        Pair(48, -4), Pair(-77, 28), Pair(-88, -20), Pair(-109, 104), Pair(124, -26), Pair(-44, 18), Pair(-1, -6), Pair(35, -45),
        Pair(-4, -28), Pair(-29, 2), Pair(-77, 79), Pair(-67, 84), Pair(-30, 80), Pair(-34, 7), Pair(1, -17), Pair(24, -71)
      }
    }},
    {{ // Bucket 20
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(25, 12), Pair(25, -4), Pair(-60, 16), Pair(-19, 11), Pair(-78, 31), Pair(39, 19), Pair(-20, 9), Pair(-26, 17),
        Pair(3, -3), Pair(-7, -2), Pair(3, -5), Pair(-15, 3), Pair(0, 0), Pair(-15, 5), Pair(-19, 10), Pair(0, 2),
        Pair(4, -12), Pair(-2, -9), Pair(-15, -6), Pair(-2, -1), Pair(0, 4), Pair(4, -8), Pair(4, -7), Pair(-1, 1),
        Pair(-3, -13), Pair(2, -20), Pair(-3, -10), Pair(-2, -2), Pair(20, -13), Pair(-3, 5), Pair(-10, -5), Pair(6, -6),
        Pair(-4, -15), Pair(1, -15), Pair(-9, -13), Pair(7, -2), Pair(0, 0), Pair(-1, -2), Pair(-6, -3), Pair(2, -6),
        Pair(-10, -6), Pair(-4, -8), Pair(0, -3), Pair(14, -75), Pair(30, 21), Pair(-8, -23), Pair(1, -5), Pair(13, -8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-178, 30), Pair(-40, 96), Pair(-14, 28), Pair(-162, 37), Pair(-230, 19), Pair(210, 41), Pair(130, 56), Pair(118, -112),
        Pair(132, -37), Pair(-24, 30), Pair(41, 26), Pair(70, -21), Pair(-54, 66), Pair(-44, 72), Pair(-42, -11), Pair(173, -34),
        Pair(-207, 156), Pair(-35, 57), Pair(26, 28), Pair(-19, 14), Pair(-44, 45), Pair(64, 50), Pair(16, 60), Pair(123, 39),
        Pair(-43, 72), Pair(-19, 44), Pair(-11, 44), Pair(4, 18), Pair(15, 21), Pair(30, 47), Pair(-1, 28), Pair(64, -10),
        Pair(6, -8), Pair(-41, 59), Pair(-33, 63), Pair(-10, 96), Pair(-10, 34), Pair(15, 92), Pair(17, 71), Pair(23, 50),
        Pair(3, 43), Pair(-67, 84), Pair(-23, 79), Pair(-25, 52), Pair(0, 0), Pair(-5, 46), Pair(-23, 75), Pair(-23, 11),
        Pair(-26, -17), Pair(-13, 91), Pair(39, 65), Pair(-47, -72), Pair(6, 172), Pair(-58, -15), Pair(-13, 87), Pair(-13, 41),
        Pair(-179, 132), Pair(-23, -10), Pair(-81, 174), Pair(-20, 3), Pair(30, 25), Pair(3, -21), Pair(-9, 110), Pair(-244, 5)
      },
      { // Piece 2
        Pair(-70, 44), Pair(-214, 76), Pair(12, 79), Pair(19, 56), Pair(-249, 120), Pair(-92, 39), Pair(97, 63), Pair(236, 150),
        Pair(20, 87), Pair(-74, 64), Pair(13, 62), Pair(-8, 55), Pair(-68, 117), Pair(114, 61), Pair(-26, 70), Pair(51, 46),
        Pair(-23, 133), Pair(-80, 74), Pair(8, 78), Pair(13, 22), Pair(16, 57), Pair(-59, 50), Pair(9, 36), Pair(126, 5),
        Pair(-19, 74), Pair(-28, 126), Pair(-42, 76), Pair(-22, 79), Pair(-32, 46), Pair(4, 29), Pair(-21, 71), Pair(55, 106),
        Pair(14, 23), Pair(-25, 64), Pair(-34, 130), Pair(-45, 72), Pair(59, 26), Pair(-40, 70), Pair(12, 112), Pair(31, 54),
        Pair(-7, 56), Pair(-17, 19), Pair(-2, 72), Pair(-9, 129), Pair(0, 0), Pair(-21, 130), Pair(-46, 88), Pair(-43, 77),
        Pair(-47, -28), Pair(14, 15), Pair(-62, 65), Pair(-58, -39), Pair(-8, 193), Pair(-87, -56), Pair(-6, 12), Pair(30, 65),
        Pair(59, 6), Pair(27, -11), Pair(-21, -11), Pair(-36, 110), Pair(1, 52), Pair(-71, 124), Pair(11, 4), Pair(87, 37)
      },
      { // Piece 3
        Pair(57, 22), Pair(-2, 44), Pair(-89, 40), Pair(79, 10), Pair(4, 53), Pair(107, 3), Pair(-148, 63), Pair(-4, 40),
        Pair(15, 12), Pair(17, 27), Pair(8, 27), Pair(-1, 24), Pair(-61, 63), Pair(-9, 43), Pair(155, -7), Pair(53, 21),
        Pair(-19, 23), Pair(30, 24), Pair(-10, 23), Pair(34, 27), Pair(-12, 39), Pair(5, 27), Pair(37, 4), Pair(-27, 6),
        Pair(5, 16), Pair(-15, 41), Pair(-33, 29), Pair(-4, 43), Pair(-8, 67), Pair(27, -19), Pair(-37, 31), Pair(13, 21),
        Pair(-29, 28), Pair(35, 26), Pair(-9, 17), Pair(11, 23), Pair(-69, 93), Pair(-9, 28), Pair(38, 23), Pair(87, 7),
        Pair(-33, -7), Pair(-21, -13), Pair(37, 31), Pair(-47, 60), Pair(0, 0), Pair(5, 51), Pair(62, 2), Pair(9, -4),
        Pair(-43, 81), Pair(-34, 81), Pair(-36, 78), Pair(-103, 70), Pair(-36, 133), Pair(-28, 32), Pair(11, 87), Pair(66, 69),
        Pair(-36, 43), Pair(-15, 41), Pair(-28, 41), Pair(-31, 59), Pair(-40, 91), Pair(-7, 32), Pair(31, 53), Pair(20, 33)
      },
      { // Piece 4
        Pair(-58, 140), Pair(-20, 8), Pair(-161, 198), Pair(128, 27), Pair(-41, 145), Pair(-11, 162), Pair(-101, 128), Pair(121, -17),
        Pair(27, 39), Pair(-14, 122), Pair(-21, 75), Pair(-51, 139), Pair(54, 38), Pair(84, -4), Pair(82, 87), Pair(78, 31),
        Pair(43, 48), Pair(22, -26), Pair(124, -53), Pair(-6, 32), Pair(-68, 139), Pair(1, 154), Pair(39, -25), Pair(10, 35),
        Pair(-47, 56), Pair(-7, 104), Pair(-55, 113), Pair(5, 63), Pair(-47, 47), Pair(6, 100), Pair(144, -47), Pair(-38, 131),
        Pair(-11, -2), Pair(-14, 36), Pair(-37, 159), Pair(34, -24), Pair(49, 23), Pair(57, -97), Pair(-8, 56), Pair(14, 90),
        Pair(3, 24), Pair(4, 0), Pair(-1, -41), Pair(70, -15), Pair(0, 0), Pair(-33, 98), Pair(-34, 63), Pair(-12, 5),
        Pair(39, 16), Pair(11, 63), Pair(-29, 63), Pair(-28, -55), Pair(1, 104), Pair(15, -148), Pair(-56, 182), Pair(-24, 163),
        Pair(11, 34), Pair(-31, 52), Pair(23, -10), Pair(2, 17), Pair(-3, -13), Pair(3, 28), Pair(0, 66), Pair(100, -31)
      },
      { // Piece 5
        Pair(11, -80), Pair(22, -143), Pair(-64, -128), Pair(-111, -68), Pair(-72, -132), Pair(-28, 5), Pair(19, -56), Pair(-5, -84),
        Pair(27, -235), Pair(-6, -73), Pair(-51, -81), Pair(-13, -5), Pair(-64, -62), Pair(51, -92), Pair(24, -50), Pair(-27, -148),
        Pair(-88, -43), Pair(-12, -50), Pair(85, -35), Pair(264, -115), Pair(162, -79), Pair(284, -65), Pair(-14, -33), Pair(59, -4),
        Pair(-53, -86), Pair(-30, -61), Pair(25, -48), Pair(43, -29), Pair(-55, -16), Pair(124, -35), Pair(7, -36), Pair(8, -14),
        Pair(33, -92), Pair(79, -38), Pair(-99, -13), Pair(17, 26), Pair(-149, 63), Pair(1, 33), Pair(-23, 14), Pair(72, -40),
        Pair(100, -105), Pair(58, -29), Pair(103, -24), Pair(-84, 60), Pair(0, 0), Pair(-17, 48), Pair(-31, 5), Pair(79, -19),
        Pair(19, -20), Pair(-11, 13), Pair(2, 13), Pair(-84, 77), Pair(-151, 99), Pair(88, 31), Pair(-35, 22), Pair(-8, 7),
        Pair(10, -25), Pair(-13, -37), Pair(-11, -36), Pair(-52, 71), Pair(-21, 83), Pair(-93, 79), Pair(-43, 10), Pair(-25, -7)
      }
    }},
    {{ // Bucket 21
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(44, -5), Pair(6, -1), Pair(-18, 21), Pair(-37, 9), Pair(-24, 2), Pair(40, -1), Pair(12, -7), Pair(-41, 32),
        Pair(5, -7), Pair(8, -21), Pair(-11, -3), Pair(5, -5), Pair(15, -5), Pair(0, 0), Pair(53, -2), Pair(32, -7),
        Pair(3, -9), Pair(2, -19), Pair(4, -20), Pair(-6, -7), Pair(3, -9), Pair(-11, 5), Pair(16, -3), Pair(15, -7),
        Pair(2, -16), Pair(-6, -16), Pair(-4, -20), Pair(-5, -13), Pair(-11, -7), Pair(-4, -6), Pair(12, -5), Pair(12, -8),
        Pair(1, -15), Pair(0, -15), Pair(-6, -8), Pair(1, -4), Pair(-5, -9), Pair(0, 0), Pair(11, -10), Pair(26, -9),
        Pair(9, -16), Pair(1, -12), Pair(-6, -16), Pair(12, -16), Pair(24, -50), Pair(25, 7), Pair(25, -27), Pair(26, -11),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-20, -42), Pair(-14, -9), Pair(16, -1), Pair(-2, 11), Pair(-44, 1), Pair(-18, -20), Pair(-78, 65), Pair(110, -68),
        Pair(-16, 89), Pair(66, -32), Pair(-35, 32), Pair(-102, 43), Pair(129, -25), Pair(28, -23), Pair(-36, -24), Pair(-165, 49),
        Pair(60, -20), Pair(-34, 25), Pair(-46, 55), Pair(20, 46), Pair(25, 21), Pair(143, 32), Pair(36, 18), Pair(-66, 56),
        Pair(33, -20), Pair(-46, 11), Pair(1, 14), Pair(10, 9), Pair(52, 0), Pair(13, 21), Pair(88, 10), Pair(97, -38),
        Pair(-66, -14), Pair(-52, 21), Pair(-8, 14), Pair(5, 13), Pair(-12, 82), Pair(24, 5), Pair(37, 50), Pair(20, 19),
        Pair(-17, -11), Pair(-16, 49), Pair(-26, 20), Pair(-3, 87), Pair(27, 29), Pair(0, 0), Pair(-60, 49), Pair(-30, -59),
        Pair(20, -21), Pair(-79, 66), Pair(-18, 41), Pair(-31, 58), Pair(-47, 0), Pair(-18, 163), Pair(-34, -43), Pair(0, 38),
        Pair(-24, -86), Pair(-35, 45), Pair(-84, 51), Pair(-11, 49), Pair(14, 20), Pair(19, 11), Pair(-26, -86), Pair(-246, 242)
      },
      { // Piece 2
        Pair(32, 98), Pair(-106, 52), Pair(10, 30), Pair(-29, 58), Pair(-127, 93), Pair(-103, 36), Pair(-34, 9), Pair(-128, 73),
        Pair(-139, 91), Pair(11, 75), Pair(-93, 67), Pair(-93, 74), Pair(-105, 71), Pair(-20, 55), Pair(-35, 52), Pair(-33, 32),
        Pair(-51, 66), Pair(-87, 76), Pair(-15, 63), Pair(-65, 54), Pair(-71, 72), Pair(-16, 72), Pair(-36, 91), Pair(-66, 38),
        Pair(-15, 10), Pair(-5, 64), Pair(-35, 82), Pair(-2, 51), Pair(-17, 35), Pair(-32, 68), Pair(25, 29), Pair(22, -12),
        Pair(-63, 52), Pair(-6, 30), Pair(-9, 27), Pair(-12, 32), Pair(-33, 21), Pair(-20, 30), Pair(-46, 74), Pair(-53, 81),
        Pair(-43, 28), Pair(46, 34), Pair(-34, 50), Pair(-22, 66), Pair(-38, 52), Pair(0, 0), Pair(-14, 83), Pair(37, 12),
        Pair(-6, 51), Pair(-26, 0), Pair(-34, 75), Pair(-51, 34), Pair(-18, -115), Pair(17, 142), Pair(-21, -102), Pair(-75, 30),
        Pair(-53, -21), Pair(25, 81), Pair(-32, 5), Pair(-51, 28), Pair(-97, 67), Pair(-8, 13), Pair(-148, 106), Pair(-116, -104)
      },
      { // Piece 3
        Pair(-29, 13), Pair(-67, 34), Pair(11, 27), Pair(-44, 64), Pair(15, 28), Pair(47, 28), Pair(27, 20), Pair(86, 24),
        Pair(-52, 37), Pair(-25, 13), Pair(33, 11), Pair(0, 24), Pair(-58, 64), Pair(3, 40), Pair(12, 31), Pair(48, -2),
        Pair(-26, 16), Pair(-25, 20), Pair(3, -8), Pair(-23, 41), Pair(-7, 28), Pair(49, 35), Pair(7, 33), Pair(53, 3),
        Pair(-9, 10), Pair(-33, 9), Pair(-42, 33), Pair(-47, 46), Pair(8, 9), Pair(96, 13), Pair(115, -16), Pair(21, 4),
        Pair(-52, 15), Pair(-20, 10), Pair(-22, 16), Pair(-28, 30), Pair(-34, 38), Pair(72, 39), Pair(59, -9), Pair(24, -15),
        Pair(8, -1), Pair(38, -22), Pair(9, 14), Pair(-20, 46), Pair(22, -10), Pair(0, 0), Pair(63, 46), Pair(21, 10),
        Pair(-76, 59), Pair(-115, 62), Pair(-42, 37), Pair(3, 15), Pair(0, -96), Pair(-11, 81), Pair(53, -66), Pair(-45, 77),
        Pair(-9, 1), Pair(-29, 8), Pair(-9, -2), Pair(-31, 39), Pair(-15, 16), Pair(-40, 34), Pair(18, 3), Pair(1, 13)
      },
      { // Piece 4
        Pair(-92, 5), Pair(-25, 74), Pair(1, 44), Pair(65, -8), Pair(-91, 113), Pair(7, 59), Pair(74, 47), Pair(-61, 123),
        Pair(-17, 95), Pair(-19, -11), Pair(-42, 102), Pair(9, -4), Pair(-57, 120), Pair(33, 16), Pair(-126, 118), Pair(92, -139),
        Pair(40, -43), Pair(7, 45), Pair(-2, 51), Pair(5, 79), Pair(66, -2), Pair(121, 14), Pair(55, -5), Pair(9, -43),
        Pair(36, 25), Pair(7, 2), Pair(-60, 36), Pair(-59, 80), Pair(7, 16), Pair(0, 27), Pair(48, -47), Pair(3, 14),
        Pair(12, -101), Pair(-45, 52), Pair(9, 30), Pair(-51, 64), Pair(-74, 99), Pair(-6, 26), Pair(-4, 53), Pair(0, 19),
        Pair(-4, 3), Pair(-28, -3), Pair(-20, 36), Pair(-30, 32), Pair(29, -30), Pair(0, 0), Pair(4, -3), Pair(23, 43),
        Pair(8, 15), Pair(-86, 89), Pair(-27, -40), Pair(-70, 94), Pair(-41, -17), Pair(-56, 96), Pair(-136, 48), Pair(-26, 80),
        Pair(-89, 59), Pair(-23, -52), Pair(1, 10), Pair(-1, -87), Pair(-62, 45), Pair(29, -47), Pair(-50, 122), Pair(-37, 107)
      },
      { // Piece 5
        Pair(86, -78), Pair(-6, -42), Pair(-33, -79), Pair(-201, -80), Pair(-93, -108), Pair(54, -26), Pair(41, -126), Pair(-2, -10),
        Pair(-26, -157), Pair(44, -72), Pair(222, -33), Pair(108, -54), Pair(-35, -5), Pair(-46, -111), Pair(64, -44), Pair(92, 2),
        Pair(135, -111), Pair(-82, -61), Pair(21, -39), Pair(-31, -30), Pair(81, -12), Pair(154, -28), Pair(25, -15), Pair(33, -48),
        Pair(11, -119), Pair(176, -52), Pair(19, -42), Pair(76, -29), Pair(196, -62), Pair(156, -37), Pair(88, -27), Pair(210, -36),
        Pair(187, -116), Pair(90, -59), Pair(49, -32), Pair(77, -33), Pair(60, 21), Pair(-24, 27), Pair(115, 12), Pair(3, 3),
        Pair(7, -42), Pair(202, -88), Pair(14, -19), Pair(-86, 9), Pair(-42, 42), Pair(0, 0), Pair(-4, 31), Pair(-28, 32),
        Pair(27, -38), Pair(105, -57), Pair(78, -24), Pair(-20, 12), Pair(189, 93), Pair(-150, 90), Pair(-99, 38), Pair(-91, 54),
        Pair(65, -100), Pair(-20, -46), Pair(-11, -15), Pair(16, -9), Pair(-35, 29), Pair(-92, 69), Pair(-69, 36), Pair(-106, 39)
      }
    }},
    {{ // Bucket 22
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-21, 7), Pair(27, -5), Pair(79, -23), Pair(-50, 8), Pair(-62, 28), Pair(17, -20), Pair(-33, 25), Pair(21, -17),
        Pair(10, -10), Pair(-29, -8), Pair(-11, -2), Pair(-20, -8), Pair(19, -9), Pair(-53, 1), Pair(0, 0), Pair(14, -13),
        Pair(6, -19), Pair(-9, -14), Pair(-6, -11), Pair(-5, -8), Pair(-5, -1), Pair(-8, -6), Pair(-6, -5), Pair(9, -8),
        Pair(2, -22), Pair(-6, -27), Pair(4, -9), Pair(-12, -12), Pair(-4, -10), Pair(-5, -5), Pair(-1, -12), Pair(3, -5),
        Pair(-5, -24), Pair(-9, -14), Pair(-10, -16), Pair(-3, -5), Pair(4, -6), Pair(-11, -4), Pair(0, 0), Pair(14, -2),
        Pair(-1, -23), Pair(-6, -12), Pair(7, -15), Pair(4, 15), Pair(-13, -5), Pair(-15, -20), Pair(4, 11), Pair(4, -10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(31, -13), Pair(71, -185), Pair(-5, -23), Pair(-150, 21), Pair(88, 14), Pair(-87, -19), Pair(59, -116), Pair(-19, -29),
        Pair(-66, 48), Pair(26, -41), Pair(33, 46), Pair(11, 17), Pair(-95, 45), Pair(-23, -5), Pair(49, -44), Pair(-34, -57),
        Pair(-28, 34), Pair(-31, -52), Pair(-26, 0), Pair(-36, 26), Pair(23, 9), Pair(6, 54), Pair(-7, 16), Pair(24, 30),
        Pair(2, -17), Pair(-28, 39), Pair(40, -12), Pair(27, -3), Pair(13, 9), Pair(19, 3), Pair(3, 50), Pair(66, 10),
        Pair(20, -60), Pair(-27, 6), Pair(-1, -5), Pair(23, -1), Pair(26, -7), Pair(-17, 86), Pair(-20, 4), Pair(-12, 21),
        Pair(-8, 113), Pair(20, -15), Pair(-18, 35), Pair(-2, 15), Pair(-60, 72), Pair(15, 1), Pair(0, 0), Pair(3, 69),
        Pair(61, 6), Pair(-58, -33), Pair(-46, 11), Pair(-22, 14), Pair(12, 21), Pair(-27, -115), Pair(19, 99), Pair(-28, -16),
        Pair(84, -24), Pair(-24, -4), Pair(-21, 8), Pair(43, -2), Pair(-53, 62), Pair(-44, 44), Pair(28, -15), Pair(-163, 12)
      },
      { // Piece 2
        Pair(-73, 176), Pair(-6, 82), Pair(-324, 114), Pair(-192, 59), Pair(-178, 105), Pair(32, 83), Pair(-242, 84), Pair(-67, 11),
        Pair(-164, 100), Pair(-20, 112), Pair(10, 23), Pair(-73, 70), Pair(-67, 67), Pair(-219, 55), Pair(-204, 82), Pair(-46, 6),
        Pair(64, 34), Pair(-128, 91), Pair(-72, 124), Pair(16, 67), Pair(-28, 69), Pair(-46, 51), Pair(61, 41), Pair(-8, 46),
        Pair(-53, 1), Pair(-54, 57), Pair(50, 15), Pair(-40, 96), Pair(-67, 33), Pair(12, 29), Pair(-17, -14), Pair(-60, -13),
        Pair(-10, 11), Pair(-58, 43), Pair(2, 16), Pair(-10, 41), Pair(-51, 92), Pair(-2, 39), Pair(70, 22), Pair(101, 12),
        Pair(-33, 13), Pair(-49, 41), Pair(-42, 52), Pair(-40, 43), Pair(-65, 49), Pair(-1, 67), Pair(0, 0), Pair(75, 109),
        Pair(-35, 29), Pair(-20, 13), Pair(-18, 0), Pair(-33, 50), Pair(-28, 29), Pair(-159, -34), Pair(3, 162), Pair(-65, 44),
        Pair(14, -2), Pair(-37, 37), Pair(-53, 49), Pair(0, 19), Pair(40, 28), Pair(-54, 68), Pair(-94, 80), Pair(14, 129)
      },
      { // Piece 3
        Pair(-10, 36), Pair(44, -20), Pair(62, -7), Pair(-28, 21), Pair(-85, 30), Pair(-32, 44), Pair(92, 1), Pair(-144, 64),
        Pair(117, -24), Pair(92, -21), Pair(14, 6), Pair(-40, 4), Pair(8, 26), Pair(109, -12), Pair(46, 24), Pair(58, -13),
        Pair(-6, 13), Pair(56, -31), Pair(59, -14), Pair(123, -45), Pair(-19, 4), Pair(57, 4), Pair(88, 1), Pair(127, -35),
        Pair(72, -34), Pair(32, -1), Pair(81, -18), Pair(36, -13), Pair(53, -8), Pair(61, -27), Pair(-14, 53), Pair(35, 4),
        Pair(-3, 23), Pair(-35, 28), Pair(114, -34), Pair(-86, 47), Pair(34, -14), Pair(39, -32), Pair(-15, 47), Pair(30, 36),
        Pair(-11, 21), Pair(-23, 24), Pair(-5, 5), Pair(94, -32), Pair(-41, 63), Pair(10, -10), Pair(0, 0), Pair(-82, 23),
        Pair(-17, 66), Pair(15, 21), Pair(19, 46), Pair(-16, 57), Pair(73, 15), Pair(8, -116), Pair(-28, 57), Pair(196, -110),
        Pair(5, 14), Pair(34, 3), Pair(13, 5), Pair(7, -9), Pair(25, 7), Pair(48, 11), Pair(-46, 50), Pair(-4, 26)
      },
      { // Piece 4
        Pair(-106, 91), Pair(-86, 0), Pair(43, 53), Pair(106, -22), Pair(192, -131), Pair(-139, 124), Pair(88, -35), Pair(168, -25),
        Pair(16, -141), Pair(-67, 91), Pair(-1, 63), Pair(-49, -10), Pair(-104, 91), Pair(62, -6), Pair(117, -73), Pair(132, -115),
        Pair(-57, -47), Pair(26, -29), Pair(30, -7), Pair(-84, 101), Pair(3, 74), Pair(48, -50), Pair(-40, 37), Pair(52, 63),
        Pair(-52, 62), Pair(-31, -8), Pair(-55, 70), Pair(-25, -4), Pair(4, 48), Pair(-42, 64), Pair(45, 28), Pair(54, -85),
        Pair(-30, -25), Pair(-122, 129), Pair(21, 27), Pair(-86, 53), Pair(-71, 124), Pair(-101, 74), Pair(-12, 43), Pair(-72, 50),
        Pair(37, -65), Pair(-40, 40), Pair(-59, 16), Pair(-29, -19), Pair(-51, 38), Pair(-52, 91), Pair(0, 0), Pair(-128, 71),
        Pair(-2, -114), Pair(13, 41), Pair(-42, 46), Pair(-38, -5), Pair(-66, 79), Pair(-103, 103), Pair(-150, 257), Pair(79, 15),
        Pair(-41, 5), Pair(-41, -120), Pair(-21, 8), Pair(-1, -113), Pair(-18, -29), Pair(41, -40), Pair(72, -214), Pair(-142, -25)
      },
      { // Piece 5
        Pair(59, -84), Pair(199, -91), Pair(37, -176), Pair(-52, -13), Pair(0, -51), Pair(-31, -85), Pair(-104, -132), Pair(12, 24),
        Pair(69, -111), Pair(24, -120), Pair(44, -97), Pair(-94, -10), Pair(-16, -1), Pair(132, -33), Pair(207, -73), Pair(0, 28),
        Pair(254, -141), Pair(17, -56), Pair(56, -38), Pair(140, -52), Pair(95, -1), Pair(213, -15), Pair(36, -17), Pair(-57, -8),
        Pair(129, -71), Pair(209, -62), Pair(2, -24), Pair(50, 8), Pair(104, -17), Pair(133, -9), Pair(123, -8), Pair(143, -44),
        Pair(28, -109), Pair(183, -82), Pair(21, -33), Pair(97, -19), Pair(86, -12), Pair(74, 61), Pair(7, 24), Pair(-12, 24),
        Pair(168, -82), Pair(106, -102), Pair(83, -56), Pair(-55, 13), Pair(-37, 15), Pair(-47, 59), Pair(0, 0), Pair(-78, 86),
        Pair(4, -66), Pair(3, -53), Pair(-23, -29), Pair(-1, -11), Pair(-47, 38), Pair(-32, 92), Pair(-88, 86), Pair(-95, 91),
        Pair(-48, -68), Pair(5, -103), Pair(-22, -44), Pair(-72, -37), Pair(-86, 30), Pair(-51, 65), Pair(-100, 76), Pair(-124, 59)
      }
    }},
    {{ // Bucket 23
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(24, -4), Pair(32, 8), Pair(22, 1), Pair(7, 5), Pair(48, 9), Pair(-65, 15), Pair(19, 3), Pair(-76, -41),
        Pair(8, -10), Pair(14, -13), Pair(25, -19), Pair(19, -8), Pair(0, -1), Pair(-31, 5), Pair(-14, 13), Pair(0, 0),
        Pair(3, -16), Pair(12, -23), Pair(15, -17), Pair(13, -19), Pair(5, -9), Pair(2, -10), Pair(15, -5), Pair(11, 14),
        Pair(6, -21), Pair(6, -18), Pair(11, -22), Pair(9, -10), Pair(9, -14), Pair(7, -6), Pair(2, -8), Pair(-34, 44),
        Pair(6, -20), Pair(6, -22), Pair(16, -17), Pair(11, -16), Pair(7, -11), Pair(-3, -1), Pair(-2, -9), Pair(0, 0),
        Pair(4, -21), Pair(8, -18), Pair(9, -25), Pair(4, -18), Pair(5, -22), Pair(-4, -6), Pair(-2, -22), Pair(-7, 27),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(36, -68), Pair(-45, 24), Pair(156, -94), Pair(-144, -16), Pair(50, -36), Pair(10, 42), Pair(70, -140), Pair(-73, -101),
        Pair(78, -32), Pair(53, -52), Pair(54, -30), Pair(124, -55), Pair(13, -28), Pair(189, -54), Pair(132, -32), Pair(93, -25),
        Pair(91, -54), Pair(41, -27), Pair(35, -26), Pair(27, -15), Pair(98, -33), Pair(43, -20), Pair(59, -26), Pair(61, -12),
        Pair(104, -76), Pair(35, -20), Pair(56, -36), Pair(64, -24), Pair(65, -17), Pair(49, -14), Pair(49, -27), Pair(-7, 71),
        Pair(28, -11), Pair(13, -44), Pair(29, 7), Pair(37, -18), Pair(38, -18), Pair(36, 3), Pair(22, 19), Pair(7, 52),
        Pair(-3, -24), Pair(2, -3), Pair(29, 0), Pair(30, -4), Pair(24, -13), Pair(25, 47), Pair(60, -28), Pair(0, 0),
        Pair(44, -83), Pair(24, -20), Pair(24, -22), Pair(17, 18), Pair(13, 6), Pair(59, -4), Pair(-82, -85), Pair(47, 133),
        Pair(46, -162), Pair(30, -80), Pair(31, 21), Pair(36, 4), Pair(50, -31), Pair(-34, 85), Pair(-15, 12), Pair(-16, 63)
      },
      { // Piece 2
        Pair(-2, 61), Pair(-39, 91), Pair(38, 90), Pair(-57, 67), Pair(-252, 92), Pair(-31, 59), Pair(5, 87), Pair(-62, 80),
        Pair(38, 50), Pair(99, 22), Pair(-110, 127), Pair(-78, 53), Pair(20, 46), Pair(72, 64), Pair(55, -10), Pair(23, 35),
        Pair(-19, 11), Pair(30, 21), Pair(-34, 70), Pair(4, 106), Pair(44, 40), Pair(55, -7), Pair(20, 70), Pair(61, 2),
        Pair(-1, 6), Pair(40, 27), Pair(-42, 37), Pair(1, 56), Pair(12, 63), Pair(-17, 88), Pair(19, 18), Pair(46, 20),
        Pair(67, 19), Pair(4, 25), Pair(56, 25), Pair(29, -4), Pair(40, 29), Pair(16, 50), Pair(65, 23), Pair(25, 73),
        Pair(1, 5), Pair(48, -1), Pair(42, -8), Pair(31, 11), Pair(24, 8), Pair(34, 46), Pair(19, 73), Pair(0, 0),
        Pair(96, 15), Pair(30, -25), Pair(32, 30), Pair(15, -3), Pair(32, 27), Pair(-6, 46), Pair(-12, 35), Pair(40, 174),
        Pair(42, 1), Pair(-3, -12), Pair(-1, 13), Pair(61, 6), Pair(16, -25), Pair(15, 40), Pair(-78, 98), Pair(21, 15)
      },
      { // Piece 3
        Pair(69, -7), Pair(-48, 40), Pair(71, 12), Pair(-120, 72), Pair(44, 3), Pair(6, 20), Pair(39, 37), Pair(86, 29),
        Pair(33, 1), Pair(-16, 19), Pair(-15, 19), Pair(5, 41), Pair(42, -7), Pair(32, 8), Pair(104, -19), Pair(70, 39),
        Pair(18, -1), Pair(47, -10), Pair(-32, 32), Pair(28, 10), Pair(5, 17), Pair(30, -2), Pair(-31, 73), Pair(2, 61),
        Pair(25, 11), Pair(65, -17), Pair(66, 5), Pair(33, 5), Pair(50, -5), Pair(84, 11), Pair(40, 3), Pair(28, 65),
        Pair(61, -3), Pair(59, 3), Pair(71, -2), Pair(35, 18), Pair(4, 4), Pair(35, 23), Pair(68, 8), Pair(22, 59),
        Pair(46, 4), Pair(31, -14), Pair(-3, 21), Pair(56, -16), Pair(19, 29), Pair(37, 29), Pair(67, 49), Pair(0, 0),
        Pair(47, 26), Pair(9, 59), Pair(26, 42), Pair(-4, 69), Pair(5, 46), Pair(21, 59), Pair(-66, -4), Pair(17, 88),
        Pair(26, 13), Pair(40, 8), Pair(36, 8), Pair(32, 7), Pair(26, 19), Pair(38, 3), Pair(19, 27), Pair(-22, 58)
      },
      { // Piece 4
        Pair(-53, 110), Pair(-46, 172), Pair(5, 51), Pair(-18, 118), Pair(28, 77), Pair(187, 59), Pair(26, -1), Pair(89, -7),
        Pair(3, 40), Pair(42, -53), Pair(2, 65), Pair(-77, 121), Pair(-64, 124), Pair(-111, 180), Pair(24, 78), Pair(-32, 146),
        Pair(49, -53), Pair(-6, 63), Pair(76, 32), Pair(-54, 150), Pair(-90, 216), Pair(-21, 71), Pair(-110, 130), Pair(96, -55),
        Pair(96, -106), Pair(-12, 41), Pair(83, -43), Pair(-35, 44), Pair(-56, 97), Pair(-28, 138), Pair(-27, 88), Pair(3, 160),
        Pair(45, -97), Pair(9, 19), Pair(24, 2), Pair(19, 0), Pair(27, 53), Pair(-4, 13), Pair(-42, 252), Pair(32, 25),
        Pair(34, -94), Pair(6, -2), Pair(28, -5), Pair(-43, 115), Pair(-4, 39), Pair(31, 18), Pair(-52, 76), Pair(0, 0),
        Pair(32, 28), Pair(-23, 47), Pair(-2, 3), Pair(-42, 105), Pair(1, -12), Pair(15, 53), Pair(-211, -12), Pair(-117, 74),
        Pair(30, 43), Pair(36, 18), Pair(-22, 96), Pair(0, -14), Pair(-23, 34), Pair(0, 63), Pair(-52, 61), Pair(-135, 197)
      },
      { // Piece 5
        Pair(-121, -69), Pair(28, -104), Pair(79, -67), Pair(-38, -80), Pair(-10, -66), Pair(128, -87), Pair(-32, 30), Pair(10, 47),
        Pair(-31, -144), Pair(125, -152), Pair(78, -64), Pair(129, -59), Pair(38, -15), Pair(-105, 16), Pair(146, -54), Pair(69, -180),
        Pair(59, -115), Pair(185, -85), Pair(34, -59), Pair(184, -76), Pair(201, -51), Pair(156, -29), Pair(167, -27), Pair(150, -65),
        Pair(-13, -78), Pair(106, -90), Pair(90, -53), Pair(25, -25), Pair(92, -15), Pair(96, -7), Pair(209, -29), Pair(239, -32),
        Pair(158, -109), Pair(6, -64), Pair(45, -68), Pair(36, -40), Pair(-50, 11), Pair(89, -6), Pair(-48, 77), Pair(-30, 9),
        Pair(63, -101), Pair(88, -95), Pair(42, -62), Pair(69, -46), Pair(-9, 15), Pair(-94, 36), Pair(-77, 75), Pair(0, 0),
        Pair(24, -67), Pair(-57, -42), Pair(-4, -54), Pair(-35, -26), Pair(-18, -1), Pair(-87, 43), Pair(54, 10), Pair(22, 77),
        Pair(18, -111), Pair(-41, -44), Pair(-33, -53), Pair(-73, -39), Pair(-68, 14), Pair(-89, 32), Pair(-38, 52), Pair(-33, 66)
      }
    }},
    {{ // Bucket 24
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(89, 42), Pair(18, 9), Pair(-2, 17), Pair(8, 12), Pair(9, 16), Pair(6, 21), Pair(-14, 16), Pair(-56, 29),
        Pair(-37, 41), Pair(-6, 6), Pair(9, 1), Pair(8, 0), Pair(-3, 12), Pair(-4, 6), Pair(-6, 19), Pair(-5, 17),
        Pair(0, 0), Pair(-1, -4), Pair(-4, -2), Pair(1, 1), Pair(0, 1), Pair(-5, 7), Pair(-5, 4), Pair(-4, 8),
        Pair(0, 0), Pair(2, -7), Pair(3, -6), Pair(-1, -3), Pair(-5, 0), Pair(-2, 1), Pair(-2, -1), Pair(-5, 1),
        Pair(11, 14), Pair(-5, -6), Pair(-1, -5), Pair(1, -5), Pair(-2, -2), Pair(-5, 0), Pair(-1, -7), Pair(-2, -2),
        Pair(8, 6), Pair(-11, -9), Pair(1, -3), Pair(3, -13), Pair(-4, -3), Pair(-4, -4), Pair(-5, -4), Pair(0, -3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-47, 63), Pair(88, -72), Pair(64, 2), Pair(271, -29), Pair(44, 17), Pair(64, 32), Pair(66, 21), Pair(20, 36),
        Pair(3, 20), Pair(23, 29), Pair(84, -9), Pair(40, 22), Pair(68, -3), Pair(105, -8), Pair(8, 0), Pair(34, 12),
        Pair(113, 27), Pair(73, 46), Pair(18, 32), Pair(46, 24), Pair(26, 24), Pair(54, 12), Pair(59, -1), Pair(45, 18),
        Pair(-11, 58), Pair(16, 32), Pair(12, 21), Pair(30, 19), Pair(22, 15), Pair(31, 15), Pair(27, 26), Pair(46, -7),
        Pair(0, 0), Pair(10, 47), Pair(13, 42), Pair(10, 21), Pair(23, 34), Pair(19, 16), Pair(35, 5), Pair(31, 12),
        Pair(27, 85), Pair(-3, -80), Pair(10, 42), Pair(12, 30), Pair(16, 24), Pair(15, 24), Pair(17, 12), Pair(17, 11),
        Pair(43, 49), Pair(5, 29), Pair(15, 25), Pair(3, 10), Pair(9, 18), Pair(27, 6), Pair(-5, 6), Pair(23, -2),
        Pair(-79, 51), Pair(1, 10), Pair(-6, 25), Pair(24, 14), Pair(1, 26), Pair(12, 11), Pair(15, 28), Pair(23, -99)
      },
      { // Piece 2
        Pair(74, 60), Pair(-41, 48), Pair(-134, 102), Pair(-76, 75), Pair(-19, 101), Pair(50, 115), Pair(92, 41), Pair(51, 74),
        Pair(34, 66), Pair(3, 61), Pair(-4, 75), Pair(-20, 81), Pair(-30, 113), Pair(-44, 112), Pair(1, 90), Pair(22, 54),
        Pair(-5, 71), Pair(-23, 90), Pair(-12, 87), Pair(-9, 100), Pair(-35, 100), Pair(23, 88), Pair(-26, 74), Pair(38, 44),
        Pair(35, 54), Pair(4, 75), Pair(-29, 97), Pair(-8, 73), Pair(3, 69), Pair(-1, 55), Pair(4, 55), Pair(11, 48),
        Pair(0, 0), Pair(-5, 74), Pair(8, 71), Pair(-7, 65), Pair(19, 57), Pair(5, 50), Pair(-3, 49), Pair(-1, 44),
        Pair(22, 148), Pair(1, -44), Pair(3, 66), Pair(10, 57), Pair(2, 51), Pair(-1, 47), Pair(-9, 66), Pair(0, 49),
        Pair(6, 99), Pair(-5, 71), Pair(2, 76), Pair(2, 56), Pair(-7, 62), Pair(-4, 51), Pair(-1, 41), Pair(-5, 39),
        Pair(14, 49), Pair(6, 75), Pair(-3, 61), Pair(1, 61), Pair(-10, 51), Pair(3, 48), Pair(-8, 69), Pair(11, 43)
      },
      { // Piece 3
        Pair(40, 103), Pair(75, 83), Pair(60, 92), Pair(-32, 115), Pair(33, 96), Pair(0, 115), Pair(45, 94), Pair(-11, 100),
        Pair(33, 132), Pair(18, 105), Pair(-2, 120), Pair(-5, 114), Pair(-4, 121), Pair(84, 81), Pair(90, 84), Pair(-43, 133),
        Pair(-7, 136), Pair(6, 97), Pair(1, 115), Pair(11, 108), Pair(34, 91), Pair(36, 92), Pair(11, 89), Pair(18, 86),
        Pair(-20, 136), Pair(6, 94), Pair(-10, 108), Pair(-4, 117), Pair(12, 86), Pair(20, 82), Pair(-5, 103), Pair(-12, 91),
        Pair(0, 0), Pair(18, 94), Pair(0, 114), Pair(4, 92), Pair(-7, 99), Pair(-8, 108), Pair(14, 88), Pair(-4, 93),
        Pair(-11, 97), Pair(-103, 68), Pair(-24, 104), Pair(-4, 87), Pair(-11, 90), Pair(-12, 99), Pair(8, 99), Pair(0, 94),
        Pair(-51, 97), Pair(-7, 81), Pair(-13, 96), Pair(-5, 79), Pair(0, 88), Pair(12, 77), Pair(-16, 107), Pair(36, 89),
        Pair(-13, 77), Pair(-15, 86), Pair(-11, 91), Pair(-9, 86), Pair(-6, 87), Pair(-2, 97), Pair(-2, 90), Pair(1, 99)
      },
      { // Piece 4
        Pair(34, 214), Pair(95, 146), Pair(53, 241), Pair(150, 134), Pair(-40, 287), Pair(3, 261), Pair(-42, 302), Pair(52, 213),
        Pair(92, 168), Pair(50, 192), Pair(34, 205), Pair(-17, 260), Pair(68, 184), Pair(30, 221), Pair(50, 205), Pair(103, 201),
        Pair(55, 175), Pair(52, 202), Pair(26, 223), Pair(30, 162), Pair(63, 173), Pair(68, 172), Pair(53, 206), Pair(60, 177),
        Pair(41, 228), Pair(28, 192), Pair(42, 188), Pair(31, 196), Pair(23, 217), Pair(61, 190), Pair(41, 200), Pair(68, 179),
        Pair(0, 0), Pair(31, 210), Pair(40, 188), Pair(24, 204), Pair(24, 187), Pair(51, 154), Pair(66, 121), Pair(40, 175),
        Pair(13, 176), Pair(32, 139), Pair(33, 165), Pair(34, 161), Pair(29, 171), Pair(34, 171), Pair(45, 137), Pair(42, 217),
        Pair(26, 137), Pair(37, 161), Pair(32, 163), Pair(30, 173), Pair(32, 164), Pair(35, 146), Pair(35, 159), Pair(11, 227),
        Pair(42, 129), Pair(35, 152), Pair(30, 144), Pair(30, 161), Pair(33, 158), Pair(14, 146), Pair(42, 161), Pair(2, 202)
      },
      { // Piece 5
        Pair(-139, 12), Pair(7, 9), Pair(72, 44), Pair(32, -22), Pair(61, -86), Pair(-46, -10), Pair(-30, -44), Pair(116, -37),
        Pair(71, 57), Pair(-27, -30), Pair(166, 1), Pair(-198, 21), Pair(-31, -19), Pair(3, -24), Pair(62, -39), Pair(146, -27),
        Pair(-18, -45), Pair(154, -19), Pair(42, 0), Pair(67, -27), Pair(126, -20), Pair(13, -9), Pair(-11, -15), Pair(183, -50),
        Pair(59, 9), Pair(-55, 53), Pair(64, 7), Pair(64, -5), Pair(76, -15), Pair(-4, -5), Pair(47, -27), Pair(63, -29),
        Pair(0, 0), Pair(-120, 36), Pair(-36, 20), Pair(-37, 14), Pair(47, -8), Pair(-28, 1), Pair(44, -23), Pair(85, -36),
        Pair(-6, 27), Pair(-82, 28), Pair(-87, 32), Pair(4, -1), Pair(-1, 1), Pair(38, -19), Pair(-23, -11), Pair(42, -28),
        Pair(21, 27), Pair(-10, 54), Pair(-33, 16), Pair(-36, 17), Pair(5, -7), Pair(9, -18), Pair(0, -20), Pair(10, -22),
        Pair(17, -16), Pair(36, 2), Pair(-23, 40), Pair(-21, 16), Pair(-6, -13), Pair(2, -23), Pair(-2, -25), Pair(8, -26)
      }
    }},
    {{ // Bucket 25
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-6, 14), Pair(-6, 27), Pair(14, 12), Pair(41, 3), Pair(25, 1), Pair(3, 16), Pair(28, 22), Pair(-22, 15),
        Pair(-7, 8), Pair(0, 9), Pair(4, 1), Pair(5, 5), Pair(1, 9), Pair(-1, 19), Pair(8, 14), Pair(-15, 23),
        Pair(1, 6), Pair(0, 0), Pair(-5, 3), Pair(1, 0), Pair(0, 3), Pair(-3, 4), Pair(-4, 4), Pair(-5, 8),
        Pair(8, -1), Pair(0, 0), Pair(0, -2), Pair(3, -2), Pair(-3, -3), Pair(-5, 0), Pair(-7, 0), Pair(-5, 2),
        Pair(1, -1), Pair(8, 13), Pair(-2, 0), Pair(4, -4), Pair(-2, -3), Pair(-10, -1), Pair(-10, -4), Pair(-3, -1),
        Pair(4, -10), Pair(10, 8), Pair(-4, -10), Pair(3, -10), Pair(-2, -4), Pair(-7, -6), Pair(-9, -7), Pair(-2, -4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-63, 80), Pair(26, -3), Pair(12, 9), Pair(14, 31), Pair(94, 27), Pair(102, -5), Pair(-20, 22), Pair(-60, 40),
        Pair(-19, 91), Pair(-18, 53), Pair(82, 38), Pair(35, 31), Pair(98, 21), Pair(23, 35), Pair(1, 39), Pair(35, 29),
        Pair(4, 49), Pair(6, 52), Pair(14, 57), Pair(20, 58), Pair(15, 47), Pair(17, 59), Pair(4, 45), Pair(62, 7),
        Pair(-5, 72), Pair(-11, 23), Pair(2, 66), Pair(11, 41), Pair(13, 63), Pair(19, 31), Pair(29, 36), Pair(23, 39),
        Pair(-6, 28), Pair(0, 0), Pair(6, 69), Pair(3, 55), Pair(11, 42), Pair(13, 43), Pair(35, 33), Pair(19, 42),
        Pair(-15, -53), Pair(22, 115), Pair(-21, -21), Pair(7, 58), Pair(4, 49), Pair(10, 49), Pair(9, 28), Pair(8, 18),
        Pair(10, -18), Pair(-6, 70), Pair(6, 39), Pair(9, 55), Pair(-3, 23), Pair(9, 32), Pair(-4, 48), Pair(18, 41),
        Pair(-106, 86), Pair(-26, -93), Pair(4, 53), Pair(-6, 20), Pair(13, 45), Pair(11, 26), Pair(-13, 74), Pair(23, 36)
      },
      { // Piece 2
        Pair(20, 50), Pair(-20, 99), Pair(-61, 63), Pair(-187, 118), Pair(-134, 113), Pair(-42, 95), Pair(-38, 127), Pair(-106, 122),
        Pair(-11, 57), Pair(-43, 78), Pair(-2, 79), Pair(-69, 116), Pair(-96, 105), Pair(10, 116), Pair(-8, 87), Pair(31, 89),
        Pair(-19, 65), Pair(11, 68), Pair(-24, 86), Pair(-11, 80), Pair(10, 92), Pair(-23, 90), Pair(0, 93), Pair(24, 50),
        Pair(-15, 26), Pair(-8, 76), Pair(-14, 80), Pair(-27, 94), Pair(4, 73), Pair(-11, 79), Pair(9, 57), Pair(16, 54),
        Pair(7, 122), Pair(0, 0), Pair(-10, 86), Pair(-9, 60), Pair(-7, 71), Pair(-4, 56), Pair(-10, 45), Pair(9, 30),
        Pair(-45, -111), Pair(-7, 153), Pair(-34, -25), Pair(0, 73), Pair(0, 50), Pair(-7, 52), Pair(6, 30), Pair(5, 48),
        Pair(-14, 121), Pair(1, 31), Pair(-8, 78), Pair(-10, 44), Pair(-15, 67), Pair(10, 34), Pair(-2, 42), Pair(-3, 38),
        Pair(1, 35), Pair(-19, 94), Pair(-1, 50), Pair(1, 64), Pair(-13, 35), Pair(-6, 46), Pair(17, 46), Pair(10, 84)
      },
      { // Piece 3
        Pair(14, 67), Pair(57, 88), Pair(-23, 96), Pair(29, 83), Pair(-30, 104), Pair(73, 53), Pair(-42, 98), Pair(27, 84),
        Pair(-4, 105), Pair(-32, 123), Pair(11, 93), Pair(-25, 110), Pair(-14, 112), Pair(-16, 99), Pair(27, 78), Pair(-47, 102),
        Pair(-2, 81), Pair(-46, 123), Pair(-7, 100), Pair(9, 90), Pair(-10, 103), Pair(42, 63), Pair(5, 77), Pair(15, 73),
        Pair(14, 59), Pair(7, 101), Pair(3, 78), Pair(-4, 99), Pair(-8, 86), Pair(-13, 82), Pair(11, 81), Pair(13, 53),
        Pair(-12, 54), Pair(0, 0), Pair(-17, 97), Pair(-13, 98), Pair(1, 81), Pair(-8, 85), Pair(-9, 89), Pair(13, 71),
        Pair(21, -26), Pair(-17, 101), Pair(12, -42), Pair(-6, 67), Pair(-27, 84), Pair(11, 68), Pair(11, 65), Pair(15, 61),
        Pair(-14, 57), Pair(-39, 74), Pair(2, 51), Pair(-4, 59), Pair(2, 57), Pair(1, 69), Pair(18, 62), Pair(-43, 101),
        Pair(-13, 71), Pair(-13, 49), Pair(-12, 70), Pair(-9, 78), Pair(-7, 74), Pair(-6, 73), Pair(1, 84), Pair(7, 75)
      },
      { // Piece 4
        Pair(122, 49), Pair(-47, 208), Pair(30, 158), Pair(102, 68), Pair(28, 161), Pair(24, 138), Pair(72, 150), Pair(16, 137),
        Pair(33, 130), Pair(20, 125), Pair(45, 142), Pair(41, 139), Pair(19, 203), Pair(-4, 214), Pair(26, 211), Pair(42, 144),
        Pair(42, 82), Pair(18, 127), Pair(16, 171), Pair(14, 155), Pair(41, 162), Pair(41, 135), Pair(74, 108), Pair(47, 130),
        Pair(23, 81), Pair(47, 93), Pair(50, 91), Pair(49, 98), Pair(46, 119), Pair(24, 151), Pair(38, 142), Pair(49, 106),
        Pair(38, 65), Pair(0, 0), Pair(18, 143), Pair(26, 120), Pair(40, 107), Pair(30, 102), Pair(27, 111), Pair(51, 110),
        Pair(36, 13), Pair(18, 100), Pair(31, 47), Pair(24, 95), Pair(41, 96), Pair(27, 123), Pair(45, 87), Pair(37, 109),
        Pair(30, 80), Pair(8, 92), Pair(22, 74), Pair(23, 97), Pair(31, 91), Pair(31, 65), Pair(44, 71), Pair(12, 122),
        Pair(1, 118), Pair(30, 70), Pair(39, 74), Pair(22, 100), Pair(29, 75), Pair(25, 117), Pair(31, 48), Pair(16, 69)
      },
      { // Piece 5
        Pair(-57, -218), Pair(-54, -106), Pair(16, -59), Pair(-24, 24), Pair(-142, 26), Pair(-90, -37), Pair(51, -64), Pair(15, -123),
        Pair(117, -38), Pair(150, -108), Pair(-36, -19), Pair(-10, 12), Pair(-89, -26), Pair(-52, -13), Pair(-34, -4), Pair(-37, -35),
        Pair(152, -23), Pair(-45, -6), Pair(239, -31), Pair(50, 1), Pair(-17, 12), Pair(-24, 14), Pair(-35, -1), Pair(82, -27),
        Pair(48, -18), Pair(-2, -1), Pair(22, 17), Pair(155, -17), Pair(70, 5), Pair(4, 9), Pair(54, -4), Pair(113, -36),
        Pair(-58, 44), Pair(0, 0), Pair(14, 7), Pair(15, 10), Pair(35, -2), Pair(15, 5), Pair(-1, 2), Pair(25, -22),
        Pair(64, 20), Pair(-69, -8), Pair(-26, -12), Pair(-16, 11), Pair(-15, 12), Pair(-6, 2), Pair(22, -23), Pair(52, -30),
        Pair(-58, 28), Pair(-36, 18), Pair(13, 17), Pair(-17, 3), Pair(-9, 18), Pair(1, -5), Pair(-4, -15), Pair(-6, -7),
        Pair(-66, 62), Pair(-7, -19), Pair(1, 10), Pair(10, -11), Pair(-16, 5), Pair(10, -13), Pair(-5, -19), Pair(2, -16)
      }
    }},
    {{ // Bucket 26
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(24, 8), Pair(3, 26), Pair(12, -7), Pair(-37, 30), Pair(8, 18), Pair(47, 8), Pair(27, 19), Pair(-11, 16),
        Pair(-10, 11), Pair(-1, 1), Pair(20, -6), Pair(1, 2), Pair(15, 5), Pair(-2, 21), Pair(6, 13), Pair(-14, 16),
        Pair(1, 0), Pair(5, -4), Pair(0, 0), Pair(3, -3), Pair(2, 2), Pair(-4, 4), Pair(0, 3), Pair(-1, 8),
        Pair(4, 0), Pair(-1, -5), Pair(0, 0), Pair(2, -2), Pair(-5, 3), Pair(-1, 1), Pair(-2, -5), Pair(-6, 2),
        Pair(3, -1), Pair(11, -27), Pair(12, 16), Pair(3, 5), Pair(-3, 0), Pair(-11, 0), Pair(-9, -1), Pair(-5, -5),
        Pair(3, -3), Pair(0, -13), Pair(12, 6), Pair(-10, -5), Pair(4, -10), Pair(-6, -5), Pair(-7, -5), Pair(-2, -4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(36, 102), Pair(22, 46), Pair(9, 51), Pair(63, 24), Pair(-20, 49), Pair(66, 31), Pair(138, 120), Pair(-118, 74),
        Pair(0, 34), Pair(-26, 46), Pair(-8, 72), Pair(-5, 74), Pair(-10, 86), Pair(-8, 66), Pair(-1, 77), Pair(102, 10),
        Pair(-32, 75), Pair(-5, 79), Pair(-12, 67), Pair(9, 83), Pair(14, 63), Pair(20, 33), Pair(8, 55), Pair(-9, 71),
        Pair(-29, 39), Pair(5, 85), Pair(-3, 40), Pair(18, 72), Pair(14, 43), Pair(21, 59), Pair(23, 37), Pair(22, 68),
        Pair(8, 70), Pair(5, 58), Pair(0, 0), Pair(-5, 79), Pair(3, 85), Pair(4, 56), Pair(36, 37), Pair(20, 38),
        Pair(11, 62), Pair(-26, -59), Pair(18, 132), Pair(-50, -12), Pair(29, 45), Pair(13, 52), Pair(14, 54), Pair(24, 10),
        Pair(11, 88), Pair(9, 46), Pair(13, 67), Pair(5, 36), Pair(22, 67), Pair(-1, 41), Pair(22, 34), Pair(28, 34),
        Pair(-91, 21), Pair(-3, 99), Pair(-56, 49), Pair(26, 29), Pair(3, 29), Pair(11, 64), Pair(15, 60), Pair(60, 14)
      },
      { // Piece 2
        Pair(58, 88), Pair(61, 38), Pair(-29, 63), Pair(40, 67), Pair(-54, 83), Pair(21, 64), Pair(-149, 97), Pair(31, 130),
        Pair(-11, 81), Pair(0, 63), Pair(0, 91), Pair(-13, 78), Pair(6, 79), Pair(-8, 53), Pair(-1, 100), Pair(-23, 105),
        Pair(-17, 50), Pair(-18, 80), Pair(-17, 65), Pair(-10, 77), Pair(-13, 82), Pair(7, 95), Pair(6, 72), Pair(15, 64),
        Pair(-3, 78), Pair(-30, 51), Pair(-10, 82), Pair(1, 62), Pair(6, 94), Pair(-10, 80), Pair(-6, 82), Pair(14, 58),
        Pair(-14, 75), Pair(-5, 93), Pair(0, 0), Pair(-13, 97), Pair(-6, 52), Pair(7, 69), Pair(13, 42), Pair(10, 37),
        Pair(-16, 58), Pair(-94, -78), Pair(6, 139), Pair(-38, -17), Pair(-7, 72), Pair(-1, 46), Pair(5, 37), Pair(7, 45),
        Pair(-63, -10), Pair(-4, 59), Pair(1, 51), Pair(-1, 59), Pair(-5, 25), Pair(-8, 60), Pair(4, 34), Pair(8, 37),
        Pair(-24, 110), Pair(8, 48), Pair(7, 57), Pair(-7, 42), Pair(-5, 83), Pair(-7, 33), Pair(-11, 8), Pair(-13, 76)
      },
      { // Piece 3
        Pair(24, 80), Pair(6, 77), Pair(50, 83), Pair(-23, 107), Pair(73, 42), Pair(14, 93), Pair(24, 98), Pair(28, 73),
        Pair(-14, 94), Pair(16, 91), Pair(9, 112), Pair(13, 95), Pair(40, 83), Pair(43, 79), Pair(52, 73), Pair(18, 77),
        Pair(1, 91), Pair(-12, 86), Pair(-52, 123), Pair(26, 87), Pair(26, 80), Pair(25, 81), Pair(-6, 89), Pair(-8, 78),
        Pair(-5, 83), Pair(13, 76), Pair(-22, 138), Pair(-10, 92), Pair(0, 89), Pair(26, 61), Pair(32, 76), Pair(31, 59),
        Pair(-11, 94), Pair(14, 62), Pair(0, 0), Pair(3, 77), Pair(-5, 83), Pair(10, 70), Pair(21, 63), Pair(25, 67),
        Pair(-33, 91), Pair(23, -42), Pair(-29, 103), Pair(23, -61), Pair(-7, 84), Pair(-10, 86), Pair(9, 70), Pair(-12, 90),
        Pair(-10, 80), Pair(2, 61), Pair(-35, 82), Pair(-5, 58), Pair(5, 59), Pair(-4, 86), Pair(11, 71), Pair(14, 69),
        Pair(-10, 83), Pair(-9, 71), Pair(-19, 74), Pair(-10, 73), Pair(0, 73), Pair(4, 73), Pair(15, 81), Pair(9, 76)
      },
      { // Piece 4
        Pair(57, 122), Pair(57, 128), Pair(11, 167), Pair(54, 176), Pair(108, 176), Pair(83, 129), Pair(74, 133), Pair(41, 188),
        Pair(43, 168), Pair(34, 156), Pair(62, 145), Pair(6, 194), Pair(-18, 240), Pair(85, 141), Pair(82, 161), Pair(21, 187),
        Pair(18, 142), Pair(43, 118), Pair(41, 137), Pair(36, 132), Pair(31, 195), Pair(42, 183), Pair(26, 147), Pair(79, 104),
        Pair(8, 187), Pair(15, 129), Pair(19, 177), Pair(40, 139), Pair(36, 176), Pair(34, 185), Pair(66, 83), Pair(45, 142),
        Pair(26, 125), Pair(16, 132), Pair(0, 0), Pair(30, 164), Pair(18, 146), Pair(39, 125), Pair(52, 120), Pair(55, 119),
        Pair(28, 109), Pair(54, 17), Pair(42, 101), Pair(49, -18), Pair(36, 135), Pair(45, 112), Pair(51, 106), Pair(23, 154),
        Pair(1, 208), Pair(7, 179), Pair(30, 95), Pair(28, 107), Pair(35, 106), Pair(47, 116), Pair(56, 113), Pair(82, 153),
        Pair(33, 107), Pair(28, 142), Pair(43, 101), Pair(37, 75), Pair(30, 145), Pair(-1, 164), Pair(-1, 205), Pair(34, 115)
      },
      { // Piece 5
        Pair(-68, -96), Pair(24, -14), Pair(-85, -119), Pair(-12, -39), Pair(-174, -101), Pair(18, -10), Pair(49, -114), Pair(-38, -70),
        Pair(50, -32), Pair(60, -31), Pair(-252, -50), Pair(69, -1), Pair(204, -52), Pair(86, -35), Pair(222, -66), Pair(-10, -17),
        Pair(-61, 8), Pair(30, -24), Pair(-13, -25), Pair(119, -12), Pair(131, -18), Pair(210, -40), Pair(-19, -4), Pair(193, -82),
        Pair(-4, -8), Pair(88, 19), Pair(75, 9), Pair(-14, 22), Pair(75, -12), Pair(133, -7), Pair(40, -3), Pair(47, -18),
        Pair(-3, -11), Pair(-47, 9), Pair(0, 0), Pair(80, -12), Pair(10, 10), Pair(54, 6), Pair(57, -8), Pair(28, -6),
        Pair(6, 10), Pair(121, -58), Pair(-114, 17), Pair(-148, 118), Pair(-11, 14), Pair(-1, 19), Pair(8, 0), Pair(37, -18),
        Pair(-88, 59), Pair(-41, 18), Pair(-51, 29), Pair(-1, 18), Pair(-19, 13), Pair(6, 11), Pair(5, -1), Pair(10, 0),
        Pair(-33, 44), Pair(-35, 13), Pair(-39, 17), Pair(-4, 25), Pair(-14, 23), Pair(28, 5), Pair(4, 1), Pair(12, -6)
      }
    }},
    {{ // Bucket 27
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-9, 28), Pair(10, 9), Pair(-7, 20), Pair(-19, 19), Pair(11, 6), Pair(-21, 23), Pair(17, 12), Pair(-1, 9),
        Pair(-10, 12), Pair(0, 10), Pair(-1, 1), Pair(-5, 7), Pair(2, 1), Pair(5, 8), Pair(3, 7), Pair(-14, 19),
        Pair(-3, -2), Pair(0, 0), Pair(-4, 3), Pair(0, 0), Pair(0, 2), Pair(2, 5), Pair(4, 4), Pair(4, 3),
        Pair(0, -2), Pair(3, -7), Pair(-2, -1), Pair(0, 0), Pair(-3, -3), Pair(-2, 1), Pair(-1, -3), Pair(2, -3),
        Pair(-3, -8), Pair(1, -5), Pair(-3, -40), Pair(15, 16), Pair(-2, -35), Pair(-6, -1), Pair(-1, -4), Pair(-2, -4),
        Pair(-1, -3), Pair(-4, -5), Pair(-3, -18), Pair(1, 3), Pair(-14, -16), Pair(-4, -1), Pair(1, -2), Pair(3, -3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-12, 18), Pair(-76, 118), Pair(-16, 26), Pair(-71, 70), Pair(4, 9), Pair(-33, 66), Pair(21, -40), Pair(60, 95),
        Pair(-34, 100), Pair(1, 77), Pair(11, 37), Pair(-23, 59), Pair(26, 50), Pair(29, 42), Pair(43, 64), Pair(-20, 63),
        Pair(32, 31), Pair(4, 61), Pair(16, 45), Pair(7, 57), Pair(38, 41), Pair(4, 63), Pair(-4, 46), Pair(-11, 67),
        Pair(-7, 66), Pair(-6, 9), Pair(-5, 74), Pair(-14, 36), Pair(8, 66), Pair(-3, 46), Pair(16, 40), Pair(25, 44),
        Pair(-17, 28), Pair(-19, 87), Pair(-1, 60), Pair(0, 0), Pair(4, 63), Pair(-8, 66), Pair(-9, 59), Pair(10, 53),
        Pair(-5, 27), Pair(-5, 50), Pair(-41, -7), Pair(26, 123), Pair(-53, -4), Pair(4, 47), Pair(4, 31), Pair(3, 83),
        Pair(-24, -3), Pair(-28, 83), Pair(-5, 18), Pair(8, 53), Pair(-6, 23), Pair(-2, 63), Pair(0, 6), Pair(13, 60),
        Pair(-26, 76), Pair(-8, 0), Pair(-8, 50), Pair(-46, -32), Pair(-9, 59), Pair(-10, 37), Pair(5, 70), Pair(58, 43)
      },
      { // Piece 2
        Pair(-22, 80), Pair(-95, 55), Pair(-28, 60), Pair(-68, 64), Pair(-73, 80), Pair(-3, 49), Pair(-40, 123), Pair(-120, 44),
        Pair(-66, 69), Pair(-11, 64), Pair(10, 62), Pair(-14, 68), Pair(-35, 73), Pair(0, 67), Pair(-39, 58), Pair(-6, 110),
        Pair(-17, 95), Pair(-17, 53), Pair(-9, 68), Pair(-34, 70), Pair(12, 76), Pair(-17, 49), Pair(0, 92), Pair(14, 29),
        Pair(-12, 56), Pair(-3, 89), Pair(-33, 55), Pair(-6, 70), Pair(-18, 34), Pair(15, 62), Pair(-4, 54), Pair(7, 76),
        Pair(-12, 63), Pair(-10, 48), Pair(1, 85), Pair(0, 0), Pair(4, 69), Pair(3, 47), Pair(0, 73), Pair(8, 33),
        Pair(-12, 35), Pair(-7, 79), Pair(-87, -105), Pair(13, 134), Pair(-37, -27), Pair(1, 59), Pair(4, 32), Pair(10, 34),
        Pair(3, 82), Pair(-44, -32), Pair(-21, 79), Pair(2, 28), Pair(-15, 66), Pair(-31, 18), Pair(0, 42), Pair(9, 10),
        Pair(-73, -95), Pair(7, 86), Pair(-3, 28), Pair(-2, 53), Pair(-5, 28), Pair(-7, 56), Pair(-61, 25), Pair(-1, 48)
      },
      { // Piece 3
        Pair(-2, 78), Pair(1, 77), Pair(-61, 84), Pair(-55, 91), Pair(13, 53), Pair(16, 70), Pair(46, 38), Pair(-37, 74),
        Pair(11, 69), Pair(-4, 75), Pair(3, 73), Pair(-17, 93), Pair(-12, 74), Pair(14, 81), Pair(-10, 90), Pair(-32, 88),
        Pair(1, 71), Pair(-6, 77), Pair(10, 58), Pair(7, 74), Pair(0, 67), Pair(-19, 82), Pair(27, 60), Pair(25, 70),
        Pair(-16, 63), Pair(-5, 68), Pair(1, 66), Pair(-22, 91), Pair(5, 60), Pair(-17, 78), Pair(13, 66), Pair(17, 70),
        Pair(-23, 62), Pair(14, 51), Pair(-11, 57), Pair(0, 0), Pair(-12, 71), Pair(-33, 84), Pair(7, 36), Pair(11, 57),
        Pair(-28, 74), Pair(-22, 71), Pair(-51, 23), Pair(-19, 76), Pair(-58, 12), Pair(-19, 62), Pair(-12, 49), Pair(4, 64),
        Pair(13, 66), Pair(-14, 64), Pair(3, 54), Pair(-34, 65), Pair(-10, 56), Pair(-5, 63), Pair(25, 47), Pair(16, 52),
        Pair(-5, 60), Pair(-11, 65), Pair(-7, 58), Pair(-26, 57), Pair(-12, 68), Pair(-5, 70), Pair(1, 55), Pair(10, 55)
      },
      { // Piece 4
        Pair(32, 140), Pair(56, 100), Pair(34, 124), Pair(75, 133), Pair(72, 124), Pair(65, 175), Pair(73, 161), Pair(23, 125),
        Pair(46, 74), Pair(17, 135), Pair(11, 135), Pair(73, 115), Pair(35, 141), Pair(-18, 192), Pair(9, 216), Pair(35, 133),
        Pair(31, 120), Pair(38, 82), Pair(27, 111), Pair(3, 136), Pair(9, 191), Pair(15, 127), Pair(46, 133), Pair(29, 99),
        Pair(21, 126), Pair(39, 120), Pair(26, 106), Pair(32, 128), Pair(39, 102), Pair(22, 148), Pair(18, 173), Pair(29, 133),
        Pair(11, 156), Pair(26, 64), Pair(21, 81), Pair(0, 0), Pair(22, 123), Pair(22, 117), Pair(18, 160), Pair(18, 144),
        Pair(10, 133), Pair(10, 110), Pair(4, 62), Pair(27, 108), Pair(26, -39), Pair(19, 119), Pair(22, 119), Pair(13, 135),
        Pair(27, 106), Pair(6, 103), Pair(7, 98), Pair(15, 100), Pair(15, 113), Pair(11, 128), Pair(17, 116), Pair(49, 50),
        Pair(11, 107), Pair(13, 129), Pair(12, 101), Pair(20, 108), Pair(23, 94), Pair(6, 138), Pair(35, 80), Pair(20, 114)
      },
      { // Piece 5
        Pair(-40, 17), Pair(-49, 47), Pair(25, -51), Pair(-85, -6), Pair(54, 4), Pair(-2, -52), Pair(55, -49), Pair(1, -27),
        Pair(106, -63), Pair(18, -56), Pair(107, -73), Pair(-10, -81), Pair(54, -5), Pair(-81, -58), Pair(138, -24), Pair(-95, -19),
        Pair(57, -65), Pair(155, -68), Pair(141, -36), Pair(134, -38), Pair(55, -31), Pair(192, -13), Pair(76, -17), Pair(97, 30),
        Pair(4, 19), Pair(83, -12), Pair(149, -10), Pair(113, -15), Pair(15, 34), Pair(146, -20), Pair(78, -1), Pair(71, -3),
        Pair(49, 16), Pair(-49, 33), Pair(-16, -16), Pair(0, 0), Pair(86, -30), Pair(23, 8), Pair(89, -6), Pair(44, -15),
        Pair(-84, 48), Pair(1, 19), Pair(125, -39), Pair(-78, 3), Pair(275, -56), Pair(-10, 19), Pair(45, 6), Pair(55, 1),
        Pair(-1, 26), Pair(-42, 31), Pair(-2, 8), Pair(-19, 16), Pair(3, 14), Pair(-24, 25), Pair(7, 19), Pair(20, 5),
        Pair(-57, 81), Pair(-30, 30), Pair(-15, 29), Pair(-8, -6), Pair(-2, 12), Pair(-2, 18), Pair(6, 15), Pair(4, 9)
      }
    }},
    {{ // Bucket 28
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(28, 1), Pair(-6, 13), Pair(3, 6), Pair(-23, 15), Pair(0, 9), Pair(2, 9), Pair(18, 9), Pair(32, 17),
        Pair(-2, 3), Pair(10, -1), Pair(-2, 4), Pair(-4, 6), Pair(0, -3), Pair(-3, 7), Pair(4, 0), Pair(-6, 8),
        Pair(1, -3), Pair(2, -3), Pair(-3, -2), Pair(-1, -1), Pair(0, 0), Pair(-5, 5), Pair(-2, 4), Pair(2, 4),
        Pair(2, -5), Pair(1, -8), Pair(3, -9), Pair(-4, -7), Pair(0, 0), Pair(0, 1), Pair(3, -3), Pair(3, 0),
        Pair(-1, -8), Pair(-1, -8), Pair(-1, -9), Pair(8, -15), Pair(9, 9), Pair(-5, -27), Pair(-2, -4), Pair(2, -1),
        Pair(1, -8), Pair(-5, -8), Pair(1, -13), Pair(-2, -17), Pair(13, -7), Pair(-9, -13), Pair(5, 2), Pair(5, -5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-11, 22), Pair(-40, 49), Pair(-99, 72), Pair(36, 21), Pair(-24, 95), Pair(43, 40), Pair(-72, 115), Pair(-87, 59),
        Pair(-11, 64), Pair(-20, 47), Pair(10, 59), Pair(-23, 46), Pair(6, 40), Pair(-41, 75), Pair(-21, 76), Pair(-64, 80),
        Pair(-8, 46), Pair(4, 50), Pair(-5, 54), Pair(18, 38), Pair(-14, 68), Pair(12, 27), Pair(1, 37), Pair(-21, 61),
        Pair(8, 40), Pair(1, 49), Pair(1, 25), Pair(-8, 66), Pair(-8, 45), Pair(-10, 78), Pair(-11, 20), Pair(12, 39),
        Pair(11, 36), Pair(-11, 31), Pair(0, 57), Pair(2, 56), Pair(0, 0), Pair(-9, 61), Pair(0, 66), Pair(-19, 17),
        Pair(2, 43), Pair(-4, 41), Pair(5, 41), Pair(-34, -52), Pair(17, 107), Pair(-36, -40), Pair(-2, 45), Pair(2, 44),
        Pair(4, 68), Pair(-48, 62), Pair(-6, 59), Pair(-8, 25), Pair(2, 51), Pair(-4, -1), Pair(1, 38), Pair(-11, -15),
        Pair(96, 69), Pair(7, 51), Pair(12, -2), Pair(0, 36), Pair(-35, -10), Pair(-5, 52), Pair(-13, 8), Pair(-3, 15)
      },
      { // Piece 2
        Pair(-109, 67), Pair(-44, 58), Pair(-98, 97), Pair(-60, 81), Pair(12, 57), Pair(-85, 69), Pair(-30, 73), Pair(-64, 90),
        Pair(-16, 54), Pair(-57, 69), Pair(14, 47), Pair(-42, 69), Pair(-35, 79), Pair(-32, 82), Pair(-5, 68), Pair(-15, 40),
        Pair(-8, 53), Pair(-17, 78), Pair(-30, 54), Pair(-4, 56), Pair(-32, 53), Pair(-7, 58), Pair(-39, 64), Pair(0, 65),
        Pair(8, 50), Pair(-14, 52), Pair(0, 63), Pair(-34, 51), Pair(10, 46), Pair(-8, 41), Pair(3, 70), Pair(1, 40),
        Pair(-16, 46), Pair(1, 41), Pair(-16, 58), Pair(5, 55), Pair(0, 0), Pair(8, 71), Pair(-17, 49), Pair(13, 53),
        Pair(-2, 36), Pair(-5, 38), Pair(-2, 41), Pair(-50, -90), Pair(12, 108), Pair(-92, -53), Pair(12, 46), Pair(-14, 41),
        Pair(-18, 66), Pair(-2, 37), Pair(-28, 24), Pair(-5, 38), Pair(-4, 29), Pair(-17, 56), Pair(-42, -16), Pair(13, 45),
        Pair(-10, 59), Pair(-35, -1), Pair(-4, 40), Pair(-1, 37), Pair(-14, 52), Pair(-7, 36), Pair(-74, 104), Pair(-56, -83)
      },
      { // Piece 3
        Pair(-22, 62), Pair(15, 51), Pair(-9, 62), Pair(35, 43), Pair(-1, 53), Pair(65, 24), Pair(61, 41), Pair(28, 43),
        Pair(-8, 56), Pair(-3, 58), Pair(1, 56), Pair(-2, 53), Pair(12, 54), Pair(23, 51), Pair(28, 49), Pair(30, 49),
        Pair(-3, 58), Pair(-7, 53), Pair(-11, 62), Pair(-8, 61), Pair(6, 62), Pair(18, 40), Pair(27, 55), Pair(-1, 47),
        Pair(-3, 50), Pair(-2, 54), Pair(-10, 63), Pair(-16, 64), Pair(12, 48), Pair(14, 36), Pair(3, 52), Pair(20, 41),
        Pair(-1, 52), Pair(-7, 49), Pair(-27, 61), Pair(-15, 60), Pair(0, 0), Pair(1, 42), Pair(-25, 70), Pair(5, 45),
        Pair(-8, 44), Pair(-12, 49), Pair(-10, 32), Pair(-16, -22), Pair(-10, 63), Pair(-37, -63), Pair(-4, 49), Pair(4, 34),
        Pair(-23, 65), Pair(4, 40), Pair(-6, 44), Pair(-4, 36), Pair(-23, 38), Pair(7, 46), Pair(14, 25), Pair(23, 29),
        Pair(1, 44), Pair(-10, 51), Pair(-7, 53), Pair(-10, 46), Pair(-16, 34), Pair(-2, 41), Pair(7, 41), Pair(0, 46)
      },
      { // Piece 4
        Pair(-21, 103), Pair(48, 83), Pair(-5, 119), Pair(35, 106), Pair(53, 78), Pair(33, 115), Pair(100, 74), Pair(34, 122),
        Pair(26, 93), Pair(18, 82), Pair(26, 82), Pair(3, 125), Pair(5, 129), Pair(-10, 138), Pair(42, 88), Pair(55, 46),
        Pair(20, 102), Pair(18, 88), Pair(29, 36), Pair(11, 117), Pair(22, 102), Pair(48, 102), Pair(42, 65), Pair(14, 133),
        Pair(26, 71), Pair(23, 82), Pair(7, 116), Pair(12, 82), Pair(17, 103), Pair(6, 92), Pair(30, 104), Pair(10, 117),
        Pair(9, 85), Pair(19, 82), Pair(7, 75), Pair(18, 101), Pair(0, 0), Pair(2, 101), Pair(12, 122), Pair(32, 68),
        Pair(7, 90), Pair(11, 84), Pair(9, 95), Pair(16, -12), Pair(7, 123), Pair(-2, -23), Pair(11, 120), Pair(-14, 152),
        Pair(16, 73), Pair(9, 101), Pair(10, 71), Pair(7, 79), Pair(15, 72), Pair(4, 122), Pair(5, 87), Pair(46, 78),
        Pair(16, 59), Pair(14, 71), Pair(15, 71), Pair(12, 60), Pair(10, 110), Pair(10, 67), Pair(49, 94), Pair(49, -16)
      },
      { // Piece 5
        Pair(-62, -48), Pair(65, 32), Pair(275, -66), Pair(44, 17), Pair(8, -124), Pair(55, -65), Pair(-31, 32), Pair(20, -64),
        Pair(42, -35), Pair(126, -39), Pair(51, -22), Pair(168, -12), Pair(231, -100), Pair(52, -45), Pair(97, -44), Pair(-34, -32),
        Pair(37, -4), Pair(57, 1), Pair(23, -6), Pair(46, -33), Pair(258, -86), Pair(279, -55), Pair(116, -34), Pair(-120, 14),
        Pair(113, -19), Pair(186, -27), Pair(136, -34), Pair(-33, 8), Pair(53, -20), Pair(85, -2), Pair(48, -3), Pair(155, -25),
        Pair(92, 19), Pair(52, 7), Pair(-14, 7), Pair(72, -54), Pair(0, 0), Pair(99, -44), Pair(10, 9), Pair(33, 19),
        Pair(78, 2), Pair(99, -18), Pair(28, 1), Pair(-90, -14), Pair(-38, -14), Pair(-112, -6), Pair(5, 15), Pair(6, 18),
        Pair(20, -11), Pair(27, 11), Pair(9, 8), Pair(61, -8), Pair(8, 1), Pair(31, -9), Pair(-20, 24), Pair(1, 24),
        Pair(25, -17), Pair(4, 9), Pair(5, 33), Pair(22, 15), Pair(-17, 10), Pair(10, 9), Pair(-14, 28), Pair(-7, 28)
      }
    }},
    {{ // Bucket 29
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-5, 12), Pair(25, 0), Pair(45, 7), Pair(8, 2), Pair(25, 0), Pair(-40, 32), Pair(-13, 12), Pair(12, 3),
        Pair(13, -3), Pair(5, 0), Pair(7, -2), Pair(-3, 9), Pair(-3, 10), Pair(11, -5), Pair(9, 7), Pair(-3, 9),
        Pair(4, -5), Pair(2, -5), Pair(6, -3), Pair(0, -3), Pair(5, -4), Pair(0, 0), Pair(7, -2), Pair(6, 2),
        Pair(8, -10), Pair(3, -5), Pair(-1, -6), Pair(-3, -4), Pair(3, -3), Pair(0, 0), Pair(4, -4), Pair(2, 0),
        Pair(7, -13), Pair(2, -9), Pair(-1, -7), Pair(3, -1), Pair(-6, 3), Pair(16, 7), Pair(-8, -19), Pair(7, -3),
        Pair(5, -13), Pair(3, -12), Pair(0, -8), Pair(9, -17), Pair(-4, -13), Pair(7, 0), Pair(-1, -15), Pair(9, -4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-28, 52), Pair(22, 53), Pair(-61, 54), Pair(12, -8), Pair(36, 46), Pair(-102, 51), Pair(115, -47), Pair(-93, 11),
        Pair(14, 56), Pair(27, 10), Pair(20, 32), Pair(-39, 82), Pair(9, 36), Pair(13, 42), Pair(28, 51), Pair(-36, 72),
        Pair(-25, 36), Pair(26, 30), Pair(33, 31), Pair(22, 33), Pair(24, 28), Pair(27, 42), Pair(-2, 28), Pair(29, 30),
        Pair(-4, 33), Pair(18, 19), Pair(6, 30), Pair(4, 19), Pair(26, 41), Pair(8, 25), Pair(29, 23), Pair(-32, -47),
        Pair(11, 27), Pair(42, 14), Pair(1, 19), Pair(12, 40), Pair(13, 37), Pair(0, 0), Pair(7, 19), Pair(5, 35),
        Pair(16, 4), Pair(0, 28), Pair(12, 15), Pair(14, 32), Pair(-37, 1), Pair(31, 82), Pair(-45, -49), Pair(7, 35),
        Pair(-50, 41), Pair(-34, 45), Pair(-5, 39), Pair(13, 41), Pair(-4, 21), Pair(30, 35), Pair(-1, -16), Pair(6, 31),
        Pair(-130, 2), Pair(3, 25), Pair(-5, 28), Pair(11, -16), Pair(8, 36), Pair(-27, -7), Pair(18, 86), Pair(-59, 44)
      },
      { // Piece 2
        Pair(-10, 61), Pair(36, -2), Pair(-39, 61), Pair(28, 53), Pair(-136, 78), Pair(-85, 40), Pair(-8, 33), Pair(71, 24),
        Pair(-56, 45), Pair(-19, 67), Pair(-30, 44), Pair(-12, 50), Pair(-13, 39), Pair(-4, 31), Pair(10, 33), Pair(-13, 79),
        Pair(-9, 37), Pair(-38, 46), Pair(-9, 61), Pair(-45, 56), Pair(11, 34), Pair(-23, 52), Pair(5, 46), Pair(-53, 23),
        Pair(-24, 48), Pair(7, 40), Pair(-33, 49), Pair(1, 53), Pair(-20, 33), Pair(-13, 61), Pair(-4, 25), Pair(6, 68),
        Pair(5, 37), Pair(-3, 39), Pair(-2, 42), Pair(-16, 30), Pair(6, 48), Pair(0, 0), Pair(10, 56), Pair(-20, 6),
        Pair(1, 24), Pair(0, 27), Pair(-11, 34), Pair(1, 43), Pair(-58, -81), Pair(23, 95), Pair(-76, -111), Pair(1, 43),
        Pair(10, 35), Pair(1, 21), Pair(-2, 49), Pair(-19, 2), Pair(4, 38), Pair(-2, 30), Pair(3, 31), Pair(-80, -91),
        Pair(-17, 37), Pair(-35, 72), Pair(-30, 3), Pair(13, 49), Pair(-16, 31), Pair(9, 33), Pair(-19, 33), Pair(-37, 105)
      },
      { // Piece 3
        Pair(14, 36), Pair(-17, 63), Pair(58, 29), Pair(29, 51), Pair(-4, 46), Pair(37, 41), Pair(-13, 45), Pair(4, 61),
        Pair(9, 34), Pair(7, 32), Pair(26, 32), Pair(-28, 59), Pair(24, 47), Pair(36, 44), Pair(56, 30), Pair(5, 47),
        Pair(26, 30), Pair(26, 32), Pair(43, 13), Pair(44, 28), Pair(41, 27), Pair(-8, 57), Pair(14, 44), Pair(-23, 44),
        Pair(22, 36), Pair(22, 21), Pair(16, 44), Pair(10, 42), Pair(26, 25), Pair(10, 64), Pair(-27, 40), Pair(39, 27),
        Pair(10, 30), Pair(3, 34), Pair(2, 23), Pair(19, 14), Pair(43, 15), Pair(0, 0), Pair(20, -6), Pair(19, 49),
        Pair(22, 26), Pair(14, 30), Pair(-12, 41), Pair(12, 30), Pair(36, -95), Pair(-9, 46), Pair(36, -56), Pair(-21, 67),
        Pair(5, 37), Pair(14, 39), Pair(5, 29), Pair(28, 27), Pair(13, 21), Pair(-14, 25), Pair(23, 52), Pair(82, 9),
        Pair(10, 36), Pair(6, 43), Pair(12, 31), Pair(4, 43), Pair(7, 37), Pair(-2, 22), Pair(13, 25), Pair(3, 40)
      },
      { // Piece 4
        Pair(6, 81), Pair(-20, 92), Pair(38, 95), Pair(-47, 149), Pair(132, -7), Pair(-41, 139), Pair(38, 83), Pair(31, 86),
        Pair(1, 104), Pair(1, 109), Pair(43, 9), Pair(-34, 141), Pair(-1, 89), Pair(-10, 64), Pair(-33, 164), Pair(30, 91),
        Pair(19, 65), Pair(21, 75), Pair(24, 51), Pair(26, 45), Pair(-12, 136), Pair(3, 62), Pair(33, 77), Pair(3, -2),
        Pair(18, 88), Pair(33, 57), Pair(3, 85), Pair(32, 80), Pair(31, 87), Pair(14, 86), Pair(14, 27), Pair(7, 60),
        Pair(19, 44), Pair(27, 52), Pair(24, 61), Pair(12, 53), Pair(15, 84), Pair(0, 0), Pair(7, 61), Pair(5, 52),
        Pair(12, 103), Pair(-1, 100), Pair(17, 41), Pair(9, 59), Pair(23, -77), Pair(2, 82), Pair(86, -263), Pair(-11, 91),
        Pair(40, 37), Pair(5, 85), Pair(12, 75), Pair(2, 64), Pair(-1, 80), Pair(24, 15), Pair(20, 58), Pair(-25, 58),
        Pair(15, 21), Pair(8, 36), Pair(21, 5), Pair(10, 58), Pair(1, 63), Pair(-20, 108), Pair(39, -55), Pair(-9, 46)
      },
      { // Piece 5
        Pair(10, -49), Pair(137, -29), Pair(-141, -24), Pair(-41, -44), Pair(77, -34), Pair(-144, 0), Pair(-71, -7), Pair(65, -59),
        Pair(-24, -76), Pair(61, -32), Pair(75, -34), Pair(119, -77), Pair(51, -22), Pair(167, -69), Pair(20, -9), Pair(48, -55),
        Pair(-9, -11), Pair(-27, -12), Pair(-36, 9), Pair(-108, 15), Pair(70, -11), Pair(301, -64), Pair(153, -29), Pair(144, -22),
        Pair(-67, 1), Pair(-37, -6), Pair(67, -9), Pair(97, -10), Pair(5, 18), Pair(117, -3), Pair(26, 20), Pair(11, 34),
        Pair(142, -38), Pair(27, -10), Pair(53, -1), Pair(66, -6), Pair(52, -21), Pair(0, 0), Pair(-7, 0), Pair(-23, 30),
        Pair(39, -35), Pair(74, -23), Pair(88, -5), Pair(2, 15), Pair(93, 12), Pair(-56, 0), Pair(96, -37), Pair(-14, 32),
        Pair(55, -15), Pair(28, -5), Pair(24, -5), Pair(-23, 13), Pair(35, 9), Pair(8, 18), Pair(14, 15), Pair(-25, 26),
        Pair(-12, -3), Pair(11, -11), Pair(4, 13), Pair(46, 18), Pair(-7, 16), Pair(-23, 15), Pair(-18, 26), Pair(-20, 40)
      }
    }},
    {{ // Bucket 30
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(1, 6), Pair(-2, 15), Pair(46, 0), Pair(21, 14), Pair(5, 12), Pair(-28, 16), Pair(-26, 13), Pair(-24, 30),
        Pair(7, -3), Pair(2, -4), Pair(6, -5), Pair(3, 4), Pair(-3, 6), Pair(-16, 3), Pair(6, 5), Pair(-13, 3),
        Pair(3, -4), Pair(3, -5), Pair(-1, -3), Pair(-3, -3), Pair(2, -4), Pair(-5, 3), Pair(0, 0), Pair(4, 3),
        Pair(3, -9), Pair(1, -8), Pair(-2, -8), Pair(-5, -3), Pair(0, -3), Pair(-3, 0), Pair(0, 0), Pair(14, 2),
        Pair(2, -11), Pair(3, -9), Pair(-5, -4), Pair(-5, -3), Pair(0, -6), Pair(-2, -1), Pair(2, 2), Pair(0, 4),
        Pair(1, -11), Pair(3, -9), Pair(-3, -6), Pair(-7, -3), Pair(-1, -7), Pair(0, -8), Pair(-4, 1), Pair(3, -7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(44, -50), Pair(-69, 37), Pair(-120, 62), Pair(113, -14), Pair(-70, 44), Pair(15, 50), Pair(49, 67), Pair(78, -64),
        Pair(59, 21), Pair(53, 19), Pair(52, 22), Pair(-88, 60), Pair(77, 46), Pair(-11, 31), Pair(-2, 56), Pair(36, 49),
        Pair(17, 31), Pair(30, 27), Pair(6, 24), Pair(19, 30), Pair(24, 37), Pair(13, 43), Pair(34, 38), Pair(25, 53),
        Pair(14, 18), Pair(9, 34), Pair(15, 34), Pair(31, 28), Pair(26, 32), Pair(12, 40), Pair(-10, 27), Pair(25, 27),
        Pair(7, 29), Pair(7, 54), Pair(21, 24), Pair(28, 18), Pair(19, 39), Pair(12, 34), Pair(0, 0), Pair(-2, 16),
        Pair(7, 48), Pair(6, 48), Pair(11, 48), Pair(17, 27), Pair(23, 34), Pair(-25, -23), Pair(26, 78), Pair(-24, -23),
        Pair(-2, 58), Pair(1, 48), Pair(11, 24), Pair(4, 26), Pair(10, 27), Pair(-12, 28), Pair(35, 31), Pair(0, -2),
        Pair(-83, 84), Pair(4, 17), Pair(11, 15), Pair(3, 38), Pair(9, 14), Pair(23, 24), Pair(-23, -45), Pair(46, 20)
      },
      { // Piece 2
        Pair(-56, 51), Pair(-36, 82), Pair(-212, 91), Pair(-112, 64), Pair(-90, 67), Pair(-9, 52), Pair(73, 54), Pair(62, 48),
        Pair(-49, 55), Pair(-22, 66), Pair(-18, 63), Pair(-14, 70), Pair(-13, 55), Pair(-33, 56), Pair(2, 45), Pair(-40, 95),
        Pair(-37, 76), Pair(34, 37), Pair(-14, 70), Pair(-12, 58), Pair(-6, 64), Pair(6, 43), Pair(-25, 72), Pair(16, 34),
        Pair(8, 42), Pair(8, 42), Pair(-4, 48), Pair(-4, 64), Pair(10, 42), Pair(-26, 81), Pair(20, 51), Pair(-114, 39),
        Pair(6, 42), Pair(0, 36), Pair(-7, 36), Pair(12, 35), Pair(5, 41), Pair(4, 50), Pair(0, 0), Pair(-15, 66),
        Pair(4, 40), Pair(19, 34), Pair(2, 42), Pair(-2, 38), Pair(12, 38), Pair(-38, -55), Pair(20, 93), Pair(-73, -112),
        Pair(-28, 42), Pair(8, 30), Pair(2, 40), Pair(6, 37), Pair(-19, 39), Pair(-20, 52), Pair(14, 9), Pair(8, 1),
        Pair(14, 32), Pair(4, 42), Pair(4, 22), Pair(-40, 50), Pair(22, 24), Pair(2, 44), Pair(-50, 76), Pair(-35, 18)
      },
      { // Piece 3
        Pair(1, 50), Pair(-5, 55), Pair(-9, 55), Pair(41, 39), Pair(6, 49), Pair(-4, 56), Pair(-18, 63), Pair(-40, 67),
        Pair(-4, 40), Pair(15, 38), Pair(4, 45), Pair(-19, 49), Pair(-14, 51), Pair(48, 32), Pair(73, 40), Pair(26, 42),
        Pair(31, 38), Pair(-13, 42), Pair(-16, 48), Pair(-12, 51), Pair(-16, 52), Pair(32, 43), Pair(-32, 60), Pair(29, 33),
        Pair(36, 19), Pair(5, 51), Pair(15, 43), Pair(41, 33), Pair(27, 36), Pair(29, 34), Pair(28, 61), Pair(-14, 33),
        Pair(9, 41), Pair(-1, 46), Pair(-10, 58), Pair(0, 42), Pair(36, 31), Pair(55, 40), Pair(0, 0), Pair(23, 12),
        Pair(7, 29), Pair(10, 41), Pair(2, 34), Pair(-14, 47), Pair(-5, 57), Pair(10, -157), Pair(15, 36), Pair(-26, 7),
        Pair(35, 19), Pair(27, 25), Pair(15, 41), Pair(16, 32), Pair(24, 24), Pair(14, 36), Pair(-11, 25), Pair(43, -9),
        Pair(15, 41), Pair(9, 46), Pair(14, 45), Pair(15, 35), Pair(9, 40), Pair(9, 40), Pair(-13, 31), Pair(3, 28)
      },
      { // Piece 4
        Pair(25, 29), Pair(1, 78), Pair(50, 46), Pair(75, 45), Pair(3, 127), Pair(153, -64), Pair(-38, 68), Pair(-17, 114),
        Pair(15, 56), Pair(29, 59), Pair(9, 92), Pair(-16, 71), Pair(-29, 100), Pair(23, 65), Pair(63, 40), Pair(-36, 130),
        Pair(35, 38), Pair(10, 56), Pair(3, 100), Pair(20, 43), Pair(2, 84), Pair(10, 89), Pair(-14, 86), Pair(32, 37),
        Pair(8, 60), Pair(4, 76), Pair(43, 36), Pair(1, 68), Pair(-4, 92), Pair(33, 46), Pair(-13, 109), Pair(-16, 22),
        Pair(21, 11), Pair(34, 3), Pair(6, 66), Pair(-6, 103), Pair(4, 67), Pair(16, 91), Pair(0, 0), Pair(-54, 130),
        Pair(8, 85), Pair(7, 70), Pair(22, 27), Pair(9, 58), Pair(0, 65), Pair(-24, -3), Pair(23, 35), Pair(33, 3),
        Pair(6, 87), Pair(8, 46), Pair(12, 57), Pair(7, 57), Pair(2, 53), Pair(14, 37), Pair(-10, 64), Pair(-11, 79),
        Pair(14, 65), Pair(16, 21), Pair(15, 46), Pair(15, 9), Pair(13, 44), Pair(10, 45), Pair(-5, 18), Pair(-7, 62)
      },
      { // Piece 5
        Pair(106, -48), Pair(121, 20), Pair(1, -92), Pair(94, 27), Pair(197, 38), Pair(13, -56), Pair(-108, -26), Pair(8, -274),
        Pair(-103, -51), Pair(-27, -26), Pair(101, -49), Pair(103, -68), Pair(-36, -29), Pair(157, -36), Pair(106, -83), Pair(-10, -54),
        Pair(300, -73), Pair(6, -29), Pair(-58, -8), Pair(61, -14), Pair(1, 9), Pair(253, -26), Pair(155, -28), Pair(348, -42),
        Pair(21, -12), Pair(26, -7), Pair(125, -37), Pair(-56, 8), Pair(76, 0), Pair(47, 19), Pair(-8, 18), Pair(13, 8),
        Pair(-47, -24), Pair(145, -43), Pair(25, -17), Pair(68, -12), Pair(20, 8), Pair(47, -12), Pair(0, 0), Pair(-25, -5),
        Pair(148, -52), Pair(44, -36), Pair(56, -21), Pair(7, 4), Pair(-19, 6), Pair(153, -43), Pair(11, -26), Pair(8, 13),
        Pair(-4, -12), Pair(-5, -12), Pair(12, -11), Pair(-2, 6), Pair(-14, 12), Pair(35, 0), Pair(-1, 10), Pair(15, -3),
        Pair(-19, -2), Pair(-6, -24), Pair(-13, -10), Pair(25, -9), Pair(-33, 22), Pair(23, 10), Pair(-14, 7), Pair(-9, 18)
      }
    }},
    {{ // Bucket 31
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(10, -1), Pair(12, 2), Pair(44, -9), Pair(23, -7), Pair(50, 0), Pair(-10, 12), Pair(-52, 12), Pair(87, -37),
        Pair(14, -11), Pair(-8, -8), Pair(2, -4), Pair(-8, 0), Pair(2, -1), Pair(-15, 7), Pair(-10, 7), Pair(-11, -15),
        Pair(3, -8), Pair(6, -7), Pair(0, -9), Pair(-4, -3), Pair(-1, -3), Pair(-5, 0), Pair(-5, -2), Pair(0, 0),
        Pair(5, -12), Pair(3, -13), Pair(-2, -7), Pair(1, -9), Pair(1, -8), Pair(2, -4), Pair(0, -10), Pair(0, 0),
        Pair(2, -13), Pair(4, -10), Pair(0, -9), Pair(0, -4), Pair(4, -8), Pair(-2, -1), Pair(-22, -13), Pair(6, 5),
        Pair(3, -8), Pair(5, -15), Pair(-2, -12), Pair(-4, -8), Pair(1, -7), Pair(1, -4), Pair(-10, -12), Pair(-9, 6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(78, -21), Pair(63, 8), Pair(78, -19), Pair(82, -14), Pair(-61, 15), Pair(-215, 62), Pair(117, 30), Pair(45, 6),
        Pair(-15, 2), Pair(22, -15), Pair(13, -2), Pair(60, -7), Pair(70, 1), Pair(10, 2), Pair(-22, 26), Pair(-57, 69),
        Pair(36, -29), Pair(31, 26), Pair(16, 8), Pair(40, 3), Pair(9, 4), Pair(-2, 32), Pair(43, 8), Pair(-55, 85),
        Pair(51, -11), Pair(30, -7), Pair(30, 7), Pair(26, -4), Pair(44, 1), Pair(29, 5), Pair(16, 13), Pair(29, 15),
        Pair(27, -6), Pair(22, -1), Pair(21, 8), Pair(47, 1), Pair(19, 2), Pair(32, 21), Pair(47, -1), Pair(0, 0),
        Pair(9, -12), Pair(8, -1), Pair(21, 4), Pair(26, 3), Pair(20, 4), Pair(28, 15), Pair(-14, -41), Pair(34, 83),
        Pair(-11, 14), Pair(36, -3), Pair(15, -6), Pair(16, 14), Pair(11, -4), Pair(9, 17), Pair(-23, 48), Pair(49, -13),
        Pair(58, -7), Pair(-1, 23), Pair(35, -23), Pair(32, -7), Pair(38, 0), Pair(0, 19), Pair(6, 22), Pair(2, -90)
      },
      { // Piece 2
        Pair(-3, 59), Pair(-114, 48), Pair(-145, 80), Pair(-11, 61), Pair(-204, 79), Pair(14, 56), Pair(-43, 34), Pair(-53, 22),
        Pair(-1, 50), Pair(8, 37), Pair(6, 57), Pair(-86, 87), Pair(-30, 75), Pair(-60, 58), Pair(-23, 40), Pair(90, 31),
        Pair(-43, 64), Pair(16, 49), Pair(-7, 50), Pair(-5, 56), Pair(19, 55), Pair(2, 62), Pair(12, 32), Pair(13, 34),
        Pair(-25, 47), Pair(6, 22), Pair(12, 42), Pair(12, 33), Pair(24, 39), Pair(-30, 55), Pair(44, 22), Pair(26, 34),
        Pair(-11, 27), Pair(2, 22), Pair(-7, 30), Pair(5, 28), Pair(5, 25), Pair(10, 30), Pair(5, 42), Pair(0, 0),
        Pair(9, 17), Pair(12, 25), Pair(11, 33), Pair(6, 23), Pair(13, 24), Pair(5, 38), Pair(-3, -29), Pair(10, 112),
        Pair(7, 40), Pair(15, 27), Pair(-1, 19), Pair(7, 29), Pair(13, 26), Pair(6, 33), Pair(17, 18), Pair(30, 18),
        Pair(14, 12), Pair(4, 13), Pair(5, 31), Pair(-2, 38), Pair(2, 31), Pair(16, 29), Pair(52, 26), Pair(24, 58)
      },
      { // Piece 3
        Pair(8, 17), Pair(25, 19), Pair(-14, 35), Pair(31, 20), Pair(-32, 34), Pair(-68, 62), Pair(35, 31), Pair(29, 43),
        Pair(27, 15), Pair(25, 16), Pair(21, 25), Pair(-12, 32), Pair(-14, 26), Pair(42, 6), Pair(53, 15), Pair(36, 46),
        Pair(19, 23), Pair(31, 17), Pair(12, 23), Pair(9, 26), Pair(39, 16), Pair(-15, 37), Pair(-8, 41), Pair(155, 16),
        Pair(0, 36), Pair(29, 16), Pair(40, 14), Pair(22, 6), Pair(37, 21), Pair(29, 21), Pair(31, 24), Pair(105, 31),
        Pair(18, 19), Pair(33, 17), Pair(28, 21), Pair(3, 36), Pair(31, 18), Pair(29, 39), Pair(25, 35), Pair(0, 0),
        Pair(-2, 39), Pair(8, 35), Pair(32, 20), Pair(22, 27), Pair(40, 1), Pair(10, 43), Pair(-16, -18), Pair(-24, 54),
        Pair(36, 19), Pair(21, 26), Pair(31, 7), Pair(19, 24), Pair(4, 27), Pair(24, 24), Pair(-7, 42), Pair(-31, 38),
        Pair(19, 26), Pair(20, 26), Pair(19, 26), Pair(13, 30), Pair(21, 26), Pair(23, 26), Pair(0, 35), Pair(-11, 35)
      },
      { // Piece 4
        Pair(34, 31), Pair(9, 48), Pair(23, 46), Pair(38, 31), Pair(87, 2), Pair(23, 42), Pair(3, 67), Pair(-10, 61),
        Pair(32, 14), Pair(26, 34), Pair(19, 52), Pair(-8, 44), Pair(49, 32), Pair(-31, 85), Pair(37, 56), Pair(-22, 43),
        Pair(39, 32), Pair(64, -3), Pair(-3, 86), Pair(9, 47), Pair(62, 28), Pair(19, 58), Pair(-6, 37), Pair(34, 45),
        Pair(12, 56), Pair(27, 19), Pair(9, 38), Pair(15, 51), Pair(25, 59), Pair(31, 36), Pair(16, 14), Pair(27, 57),
        Pair(12, 52), Pair(12, 16), Pair(17, 42), Pair(3, 35), Pair(8, 94), Pair(17, 57), Pair(18, 15), Pair(0, 0),
        Pair(21, 7), Pair(6, 52), Pair(15, 36), Pair(14, 37), Pair(10, 54), Pair(1, 62), Pair(49, -130), Pair(-40, 132),
        Pair(7, 56), Pair(30, 13), Pair(15, 45), Pair(16, 30), Pair(2, 46), Pair(12, 31), Pair(27, 25), Pair(-29, -20),
        Pair(24, 43), Pair(16, 58), Pair(10, 34), Pair(12, 29), Pair(24, 49), Pair(-38, 106), Pair(31, 66), Pair(-36, 57)
      },
      { // Piece 5
        Pair(-19, -102), Pair(81, 5), Pair(51, -108), Pair(-21, 11), Pair(49, -46), Pair(94, 4), Pair(-6, -59), Pair(-19, -136),
        Pair(288, -91), Pair(89, -67), Pair(-34, -30), Pair(62, -36), Pair(-12, -14), Pair(133, -42), Pair(-74, -77), Pair(-10, -58),
        Pair(124, -77), Pair(2, -36), Pair(53, -34), Pair(13, -15), Pair(189, -40), Pair(61, -16), Pair(97, -32), Pair(267, -73),
        Pair(11, -56), Pair(12, -17), Pair(74, -37), Pair(120, -28), Pair(23, -3), Pair(68, -3), Pair(38, 40), Pair(115, -7),
        Pair(122, -50), Pair(107, -59), Pair(19, -16), Pair(70, -22), Pair(6, 3), Pair(-54, 20), Pair(-6, 1), Pair(0, 0),
        Pair(92, -57), Pair(14, -29), Pair(13, -29), Pair(6, -5), Pair(9, 1), Pair(-37, 26), Pair(-35, -13), Pair(89, -20),
        Pair(-34, 11), Pair(-3, -43), Pair(3, -22), Pair(-3, -13), Pair(-14, 23), Pair(-16, 19), Pair(9, 33), Pair(18, 17),
        Pair(-11, -35), Pair(-23, -34), Pair(-20, -22), Pair(43, -1), Pair(-22, 11), Pair(-49, 37), Pair(6, 10), Pair(-2, 4)
      }
    }},
    {{ // Bucket 32
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-14, -52), Pair(-12, 24), Pair(-4, 20), Pair(-4, 24), Pair(25, 20), Pair(37, 15), Pair(-7, 18), Pair(-12, 28),
        Pair(-6, 7), Pair(-5, 5), Pair(1, 8), Pair(0, 10), Pair(1, 14), Pair(-1, 17), Pair(-4, 20), Pair(-6, 21),
        Pair(0, 0), Pair(-9, -1), Pair(-5, -1), Pair(-1, 3), Pair(-3, 4), Pair(-7, 9), Pair(-4, 8), Pair(-5, 10),
        Pair(0, 0), Pair(-9, -6), Pair(-3, -2), Pair(-4, 3), Pair(-4, 4), Pair(-5, 6), Pair(-3, 0), Pair(-3, 5),
        Pair(2, 6), Pair(-4, -1), Pair(-1, -1), Pair(-3, -1), Pair(-2, 0), Pair(-10, 2), Pair(-4, 0), Pair(-8, -3),
        Pair(10, 3), Pair(-5, -4), Pair(4, -2), Pair(-1, -4), Pair(-3, 1), Pair(-5, -1), Pair(-1, -1), Pair(-2, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-94, 66), Pair(65, 30), Pair(-8, 48), Pair(7, 72), Pair(-26, 53), Pair(-9, 91), Pair(-42, 69), Pair(7, 5),
        Pair(43, 69), Pair(22, 56), Pair(15, 39), Pair(20, 58), Pair(-8, 62), Pair(28, 40), Pair(93, 29), Pair(82, 3),
        Pair(33, 9), Pair(8, 58), Pair(-4, 62), Pair(14, 60), Pair(-1, 57), Pair(39, 44), Pair(57, 9), Pair(22, 48),
        Pair(0, 0), Pair(0, 65), Pair(-2, 60), Pair(4, 41), Pair(4, 53), Pair(6, 51), Pair(9, 44), Pair(30, 29),
        Pair(3, 98), Pair(-80, -28), Pair(2, 67), Pair(0, 47), Pair(9, 49), Pair(-1, 48), Pair(6, 50), Pair(7, 38),
        Pair(-1, 71), Pair(-3, 54), Pair(-9, 58), Pair(-15, 51), Pair(0, 42), Pair(-1, 51), Pair(3, 43), Pair(6, 33),
        Pair(-3, 10), Pair(6, 51), Pair(-10, 37), Pair(-6, 59), Pair(-3, 49), Pair(3, 40), Pair(-9, 33), Pair(4, 47),
        Pair(-98, 29), Pair(-4, 66), Pair(11, 30), Pair(24, 18), Pair(-5, 35), Pair(-2, 45), Pair(0, 71), Pair(-30, 6)
      },
      { // Piece 2
        Pair(-55, 66), Pair(-56, 109), Pair(-61, 88), Pair(-94, 137), Pair(-56, 113), Pair(-49, 102), Pair(-19, 87), Pair(20, 93),
        Pair(-5, 105), Pair(-25, 80), Pair(-4, 95), Pair(-73, 99), Pair(-9, 93), Pair(-11, 86), Pair(2, 113), Pair(-22, 90),
        Pair(-9, 71), Pair(-18, 104), Pair(-60, 103), Pair(-1, 90), Pair(-6, 87), Pair(-10, 112), Pair(-23, 89), Pair(12, 72),
        Pair(0, 0), Pair(-24, 81), Pair(-11, 95), Pair(-24, 80), Pair(0, 101), Pair(-25, 82), Pair(-2, 90), Pair(-8, 68),
        Pair(-14, 128), Pair(-129, 36), Pair(-18, 78), Pair(-17, 94), Pair(-7, 60), Pair(-1, 79), Pair(-24, 77), Pair(-3, 71),
        Pair(3, 92), Pair(-28, 74), Pair(-13, 87), Pair(-14, 73), Pair(-5, 76), Pair(-18, 59), Pair(-12, 80), Pair(-18, 61),
        Pair(-19, 93), Pair(-1, 89), Pair(-13, 72), Pair(-8, 75), Pair(-19, 65), Pair(-16, 79), Pair(-13, 49), Pair(4, 46),
        Pair(-7, 114), Pair(-8, 79), Pair(-3, 87), Pair(-22, 67), Pair(-23, 93), Pair(-15, 61), Pair(-6, 88), Pair(-10, 49)
      },
      { // Piece 3
        Pair(60, 112), Pair(-28, 129), Pair(-13, 130), Pair(-6, 125), Pair(6, 113), Pair(-32, 132), Pair(41, 108), Pair(-8, 114),
        Pair(-10, 154), Pair(-17, 126), Pair(-17, 134), Pair(-14, 123), Pair(-20, 139), Pair(7, 124), Pair(56, 102), Pair(-11, 120),
        Pair(4, 133), Pair(-19, 122), Pair(-10, 121), Pair(-8, 131), Pair(3, 121), Pair(13, 122), Pair(-23, 127), Pair(-25, 129),
        Pair(0, 0), Pair(-14, 137), Pair(-26, 146), Pair(-21, 137), Pair(-6, 119), Pair(-9, 121), Pair(-3, 109), Pair(7, 114),
        Pair(-24, 121), Pair(50, -37), Pair(-33, 120), Pair(-31, 111), Pair(-18, 112), Pair(-27, 115), Pair(-9, 108), Pair(-22, 110),
        Pair(-50, 113), Pair(-34, 119), Pair(-34, 116), Pair(-23, 106), Pair(-21, 115), Pair(-19, 107), Pair(-3, 103), Pair(-2, 102),
        Pair(-20, 84), Pair(-36, 121), Pair(-27, 103), Pair(-33, 115), Pair(-26, 106), Pair(-16, 103), Pair(-18, 118), Pair(16, 108),
        Pair(-30, 102), Pair(-30, 109), Pair(-31, 114), Pair(-26, 106), Pair(-24, 111), Pair(-22, 110), Pair(-13, 114), Pair(-16, 119)
      },
      { // Piece 4
        Pair(6, 244), Pair(37, 218), Pair(21, 229), Pair(-47, 295), Pair(85, 191), Pair(53, 213), Pair(132, 116), Pair(66, 237),
        Pair(19, 245), Pair(43, 203), Pair(29, 232), Pair(17, 237), Pair(12, 247), Pair(33, 263), Pair(34, 216), Pair(94, 147),
        Pair(29, 224), Pair(46, 212), Pair(27, 220), Pair(28, 212), Pair(42, 216), Pair(50, 215), Pair(83, 169), Pair(50, 199),
        Pair(0, 0), Pair(36, 188), Pair(42, 201), Pair(27, 217), Pair(19, 232), Pair(36, 219), Pair(41, 200), Pair(54, 183),
        Pair(32, 181), Pair(87, 12), Pair(24, 190), Pair(29, 193), Pair(32, 181), Pair(37, 182), Pair(48, 176), Pair(34, 188),
        Pair(15, 238), Pair(21, 190), Pair(27, 186), Pair(33, 176), Pair(22, 183), Pair(35, 172), Pair(38, 170), Pair(37, 170),
        Pair(33, 187), Pair(31, 167), Pair(28, 179), Pair(21, 193), Pair(29, 171), Pair(33, 158), Pair(36, 177), Pair(46, 193),
        Pair(27, 194), Pair(29, 179), Pair(24, 197), Pair(27, 168), Pair(30, 169), Pair(33, 159), Pair(43, 166), Pair(35, 119)
      },
      { // Piece 5
        Pair(-8, 106), Pair(-120, -54), Pair(33, 53), Pair(16, 10), Pair(-112, 2), Pair(-36, -17), Pair(-15, -27), Pair(-16, 10),
        Pair(116, 51), Pair(-108, -4), Pair(133, -26), Pair(161, -30), Pair(116, 9), Pair(77, -1), Pair(13, -11), Pair(49, -27),
        Pair(-72, 7), Pair(89, 1), Pair(23, -10), Pair(94, -13), Pair(181, -18), Pair(-45, 17), Pair(23, -4), Pair(-4, 9),
        Pair(0, 0), Pair(42, -30), Pair(23, -2), Pair(31, 3), Pair(89, -8), Pair(57, -4), Pair(37, -6), Pair(69, -11),
        Pair(-15, -51), Pair(79, -114), Pair(-15, 5), Pair(12, -1), Pair(33, -2), Pair(39, -5), Pair(9, 3), Pair(63, -17),
        Pair(8, 3), Pair(-37, 14), Pair(-31, -3), Pair(-12, 2), Pair(-9, -1), Pair(9, -6), Pair(7, -13), Pair(20, -6),
        Pair(26, -26), Pair(3, 3), Pair(-3, 12), Pair(27, -2), Pair(7, -6), Pair(8, -9), Pair(4, -8), Pair(7, -11),
        Pair(-1, 11), Pair(7, 4), Pair(9, 12), Pair(-1, 5), Pair(11, -8), Pair(20, -15), Pair(1, -15), Pair(7, -7)
      }
    }},
    {{ // Bucket 33
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-42, 40), Pair(37, -3), Pair(-18, 21), Pair(38, 14), Pair(1, 24), Pair(13, 25), Pair(-23, 33), Pair(3, 23),
        Pair(-6, 5), Pair(-14, 10), Pair(1, 6), Pair(-4, 18), Pair(0, 20), Pair(3, 16), Pair(6, 26), Pair(-7, 16),
        Pair(-4, 7), Pair(0, 0), Pair(0, 5), Pair(-5, 7), Pair(0, 11), Pair(-1, 8), Pair(0, 10), Pair(-2, 12),
        Pair(11, 8), Pair(0, 0), Pair(0, 16), Pair(1, 1), Pair(-6, 4), Pair(-5, 5), Pair(-4, 8), Pair(-2, 10),
        Pair(7, -1), Pair(3, 5), Pair(0, 8), Pair(0, 2), Pair(-2, 6), Pair(-8, 2), Pair(-6, 0), Pair(-3, 4),
        Pair(6, 3), Pair(11, 8), Pair(-1, 2), Pair(2, 1), Pair(-2, -2), Pair(-5, -1), Pair(-4, 0), Pair(-3, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-7, 43), Pair(52, 9), Pair(-48, 93), Pair(-97, 106), Pair(26, 38), Pair(-83, 106), Pair(-59, 76), Pair(-8, 90),
        Pair(1, 66), Pair(3, 84), Pair(57, 55), Pair(47, 44), Pair(-7, 63), Pair(51, 37), Pair(67, 48), Pair(44, 51),
        Pair(5, 81), Pair(19, 22), Pair(17, 69), Pair(6, 60), Pair(36, 69), Pair(23, 74), Pair(42, 54), Pair(50, 41),
        Pair(-6, 55), Pair(0, 0), Pair(6, 72), Pair(8, 85), Pair(15, 55), Pair(22, 61), Pair(29, 55), Pair(27, 50),
        Pair(-19, -27), Pair(34, 110), Pair(-43, 34), Pair(10, 67), Pair(12, 66), Pair(14, 59), Pair(33, 66), Pair(14, 63),
        Pair(-6, 13), Pair(16, 64), Pair(-1, 48), Pair(13, 58), Pair(-3, 55), Pair(14, 58), Pair(17, 61), Pair(14, 78),
        Pair(24, 57), Pair(-20, -16), Pair(4, 80), Pair(5, 46), Pair(15, 60), Pair(19, 38), Pair(17, 61), Pair(16, 74),
        Pair(24, 85), Pair(6, 59), Pair(10, 69), Pair(12, 49), Pair(11, 62), Pair(10, 59), Pair(4, 64), Pair(13, 59)
      },
      { // Piece 2
        Pair(-22, 71), Pair(-17, 100), Pair(-3, 60), Pair(-15, 104), Pair(-29, 129), Pair(-43, 112), Pair(-32, 107), Pair(1, 104),
        Pair(-4, 75), Pair(-44, 102), Pair(6, 84), Pair(-38, 111), Pair(15, 101), Pair(21, 100), Pair(51, 88), Pair(8, 89),
        Pair(-68, 69), Pair(-9, 86), Pair(9, 97), Pair(-16, 100), Pair(35, 80), Pair(-27, 110), Pair(-9, 114), Pair(15, 80),
        Pair(13, 70), Pair(0, 0), Pair(11, 86), Pair(-6, 97), Pair(6, 86), Pair(-4, 99), Pair(11, 78), Pair(6, 73),
        Pair(-52, -6), Pair(12, 110), Pair(-29, -23), Pair(-3, 82), Pair(6, 84), Pair(4, 68), Pair(3, 78), Pair(17, 64),
        Pair(-16, 63), Pair(-4, 82), Pair(-11, 73), Pair(8, 66), Pair(6, 72), Pair(5, 72), Pair(12, 55), Pair(10, 69),
        Pair(0, 94), Pair(9, 64), Pair(5, 67), Pair(4, 66), Pair(-1, 64), Pair(5, 65), Pair(8, 66), Pair(-1, 29),
        Pair(0, 110), Pair(15, 84), Pair(14, 64), Pair(12, 74), Pair(17, 64), Pair(8, 40), Pair(23, 54), Pair(16, 80)
      },
      { // Piece 3
        Pair(12, 107), Pair(65, 94), Pair(15, 119), Pair(19, 111), Pair(-1, 112), Pair(-46, 121), Pair(-6, 122), Pair(-11, 98),
        Pair(9, 120), Pair(15, 139), Pair(-12, 124), Pair(-6, 133), Pair(-21, 120), Pair(23, 118), Pair(2, 112), Pair(-30, 132),
        Pair(-1, 112), Pair(-20, 137), Pair(17, 112), Pair(5, 120), Pair(17, 111), Pair(35, 92), Pair(20, 107), Pair(-1, 109),
        Pair(0, 90), Pair(0, 0), Pair(4, 119), Pair(-1, 123), Pair(-6, 124), Pair(-12, 115), Pair(19, 114), Pair(5, 112),
        Pair(0, -25), Pair(-7, 101), Pair(-27, 35), Pair(-14, 104), Pair(-6, 106), Pair(3, 96), Pair(-14, 111), Pair(11, 89),
        Pair(-14, 101), Pair(-14, 98), Pair(-23, 101), Pair(3, 91), Pair(-12, 103), Pair(5, 91), Pair(-7, 107), Pair(5, 117),
        Pair(-9, 80), Pair(-25, 89), Pair(-1, 97), Pair(-1, 93), Pair(10, 93), Pair(-7, 103), Pair(-2, 92), Pair(5, 120),
        Pair(-8, 100), Pair(-8, 93), Pair(-10, 100), Pair(-1, 104), Pair(-2, 103), Pair(-1, 104), Pair(0, 117), Pair(7, 111)
      },
      { // Piece 4
        Pair(30, 192), Pair(35, 176), Pair(58, 177), Pair(15, 182), Pair(34, 222), Pair(112, 135), Pair(65, 192), Pair(15, 223),
        Pair(57, 149), Pair(31, 200), Pair(42, 161), Pair(50, 176), Pair(33, 190), Pair(53, 206), Pair(48, 214), Pair(73, 139),
        Pair(42, 119), Pair(14, 215), Pair(13, 197), Pair(29, 211), Pair(46, 212), Pair(32, 216), Pair(57, 166), Pair(52, 190),
        Pair(44, 141), Pair(0, 0), Pair(17, 194), Pair(46, 195), Pair(52, 187), Pair(34, 192), Pair(41, 200), Pair(49, 170),
        Pair(78, 4), Pair(35, 169), Pair(43, 149), Pair(30, 186), Pair(31, 182), Pair(40, 172), Pair(33, 171), Pair(44, 170),
        Pair(28, 138), Pair(29, 158), Pair(27, 157), Pair(25, 173), Pair(35, 163), Pair(27, 180), Pair(53, 153), Pair(20, 208),
        Pair(26, 174), Pair(24, 180), Pair(29, 158), Pair(26, 171), Pair(35, 145), Pair(37, 152), Pair(45, 158), Pair(42, 158),
        Pair(48, 127), Pair(49, 125), Pair(32, 152), Pair(34, 153), Pair(26, 157), Pair(32, 174), Pair(103, 83), Pair(-37, 227)
      },
      { // Piece 5
        Pair(60, 16), Pair(132, 39), Pair(102, -59), Pair(69, 63), Pair(46, 56), Pair(-213, 13), Pair(-32, -14), Pair(99, -48),
        Pair(17, -18), Pair(46, -49), Pair(-88, -47), Pair(82, 10), Pair(48, 28), Pair(-60, 33), Pair(7, -23), Pair(38, -18),
        Pair(163, -26), Pair(44, 10), Pair(195, -10), Pair(188, -6), Pair(194, -17), Pair(155, -15), Pair(62, -2), Pair(59, -2),
        Pair(-25, 7), Pair(0, 0), Pair(113, -37), Pair(36, -4), Pair(56, 0), Pair(-32, 20), Pair(27, 8), Pair(28, -15),
        Pair(-27, -25), Pair(30, -66), Pair(-89, -20), Pair(-10, -4), Pair(32, -3), Pair(33, 0), Pair(14, -3), Pair(29, -12),
        Pair(-47, -13), Pair(-19, -20), Pair(-3, -17), Pair(-24, -6), Pair(-9, 5), Pair(27, -4), Pair(37, -14), Pair(76, -28),
        Pair(-19, 5), Pair(-13, -3), Pair(21, -7), Pair(16, -4), Pair(18, -4), Pair(11, -3), Pair(17, -10), Pair(15, -9),
        Pair(-21, 10), Pair(-3, -5), Pair(9, -4), Pair(35, 7), Pair(8, 5), Pair(48, -17), Pair(10, -11), Pair(17, -13)
      }
    }},
    {{ // Bucket 34
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-29, 32), Pair(4, 10), Pair(3, 10), Pair(-2, 18), Pair(-8, 28), Pair(-4, 22), Pair(21, 23), Pair(5, 20),
        Pair(-4, 7), Pair(-3, 7), Pair(-1, 9), Pair(4, 6), Pair(3, 14), Pair(3, 18), Pair(-4, 12), Pair(-14, 23),
        Pair(-2, 5), Pair(3, 0), Pair(0, 0), Pair(3, 0), Pair(-3, 6), Pair(2, 5), Pair(1, 6), Pair(2, 8),
        Pair(1, -1), Pair(1, -16), Pair(0, 0), Pair(-4, 6), Pair(-2, 1), Pair(-3, 5), Pair(-4, 6), Pair(-1, 5),
        Pair(2, -2), Pair(4, -6), Pair(2, 3), Pair(-2, 3), Pair(-2, 3), Pair(-10, 1), Pair(-6, 3), Pair(-2, 2),
        Pair(1, -1), Pair(0, -10), Pair(9, 8), Pair(-10, -1), Pair(0, -3), Pair(-7, -2), Pair(-3, -1), Pair(1, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-19, 25), Pair(58, 52), Pair(49, 36), Pair(61, 55), Pair(-7, 58), Pair(-28, 108), Pair(-13, 123), Pair(19, 24),
        Pair(-12, 78), Pair(-13, 70), Pair(14, 61), Pair(-10, 78), Pair(14, 61), Pair(21, 54), Pair(19, 67), Pair(44, 48),
        Pair(-60, 37), Pair(-28, 93), Pair(-45, 71), Pair(-7, 77), Pair(-18, 63), Pair(-21, 93), Pair(6, 61), Pair(-24, 72),
        Pair(0, 84), Pair(-11, 59), Pair(0, 0), Pair(-6, 70), Pair(-7, 85), Pair(-4, 63), Pair(3, 76), Pair(4, 64),
        Pair(-5, 75), Pair(-62, 21), Pair(6, 121), Pair(-60, 12), Pair(1, 65), Pair(-8, 65), Pair(1, 72), Pair(5, 69),
        Pair(-5, 77), Pair(-25, 40), Pair(-5, 70), Pair(-8, 56), Pair(-10, 70), Pair(-13, 54), Pair(-7, 62), Pair(5, 63),
        Pair(-8, 1), Pair(-15, 83), Pair(-22, 23), Pair(-7, 70), Pair(-10, 53), Pair(-2, 69), Pair(-6, 61), Pair(6, 62),
        Pair(-21, 90), Pair(1, 68), Pair(-2, 54), Pair(7, 61), Pair(-6, 54), Pair(8, 61), Pair(-9, 87), Pair(34, 126)
      },
      { // Piece 2
        Pair(-10, 81), Pair(17, 45), Pair(-74, 82), Pair(6, 71), Pair(-51, 87), Pair(-24, 86), Pair(-42, 99), Pair(3, 70),
        Pair(-43, 48), Pair(-20, 81), Pair(-20, 91), Pair(-50, 83), Pair(-33, 74), Pair(-13, 88), Pair(-32, 82), Pair(-12, 57),
        Pair(-13, 94), Pair(-50, 63), Pair(-38, 84), Pair(-29, 80), Pair(-20, 91), Pair(-38, 90), Pair(-7, 73), Pair(-9, 69),
        Pair(-15, 62), Pair(-11, 74), Pair(0, 0), Pair(-14, 88), Pair(-14, 73), Pair(-31, 87), Pair(-17, 62), Pair(-8, 66),
        Pair(-22, 89), Pair(-85, -139), Pair(3, 119), Pair(-92, -84), Pair(-2, 62), Pair(-14, 65), Pair(-14, 72), Pair(-3, 64),
        Pair(-27, 6), Pair(-29, 65), Pair(-20, 58), Pair(-12, 60), Pair(-21, 42), Pair(-11, 63), Pair(1, 49), Pair(-6, 70),
        Pair(-46, 67), Pair(-14, 37), Pair(-7, 73), Pair(-12, 52), Pair(-10, 54), Pair(-31, 57), Pair(-7, 53), Pair(-1, 48),
        Pair(-18, 53), Pair(-10, 76), Pair(-7, 49), Pair(-11, 62), Pair(-10, 57), Pair(-9, 64), Pair(-29, 47), Pair(-26, 92)
      },
      { // Piece 3
        Pair(-17, 91), Pair(-6, 92), Pair(-5, 102), Pair(-40, 106), Pair(-17, 85), Pair(48, 75), Pair(27, 72), Pair(-16, 91),
        Pair(-15, 101), Pair(-19, 97), Pair(-38, 119), Pair(-6, 101), Pair(-7, 93), Pair(-2, 96), Pair(6, 98), Pair(-14, 92),
        Pair(-12, 95), Pair(-25, 91), Pair(-21, 104), Pair(-8, 90), Pair(1, 90), Pair(13, 84), Pair(-10, 81), Pair(-9, 77),
        Pair(-27, 91), Pair(-20, 82), Pair(0, 0), Pair(-2, 89), Pair(-21, 102), Pair(-12, 86), Pair(-9, 83), Pair(23, 70),
        Pair(-29, 83), Pair(-9, 42), Pair(-34, 83), Pair(-15, -1), Pair(-21, 77), Pair(-17, 81), Pair(-25, 77), Pair(-5, 64),
        Pair(-25, 89), Pair(-23, 67), Pair(-36, 77), Pair(-24, 68), Pair(-18, 84), Pair(-16, 71), Pair(-18, 82), Pair(-6, 70),
        Pair(-2, 82), Pair(-23, 78), Pair(-35, 83), Pair(-20, 65), Pair(-15, 70), Pair(-11, 79), Pair(-7, 81), Pair(4, 67),
        Pair(-22, 85), Pair(-22, 74), Pair(-26, 67), Pair(-22, 75), Pair(-20, 80), Pair(-17, 79), Pair(-6, 70), Pair(-7, 87)
      },
      { // Piece 4
        Pair(1, 156), Pair(28, 147), Pair(44, 143), Pair(22, 165), Pair(83, 125), Pair(128, 104), Pair(-16, 199), Pair(58, 151),
        Pair(16, 143), Pair(12, 164), Pair(-3, 190), Pair(11, 164), Pair(-5, 205), Pair(33, 168), Pair(27, 173), Pair(29, 129),
        Pair(21, 144), Pair(8, 124), Pair(13, 146), Pair(42, 123), Pair(27, 148), Pair(32, 148), Pair(39, 156), Pair(36, 144),
        Pair(9, 131), Pair(2, 161), Pair(0, 0), Pair(34, 122), Pair(17, 146), Pair(37, 141), Pair(25, 143), Pair(22, 165),
        Pair(11, 167), Pair(0, 36), Pair(28, 126), Pair(17, 89), Pair(19, 140), Pair(25, 116), Pair(25, 135), Pair(28, 149),
        Pair(-1, 111), Pair(6, 138), Pair(20, 116), Pair(21, 113), Pair(18, 109), Pair(11, 146), Pair(28, 143), Pair(13, 169),
        Pair(18, 151), Pair(19, 103), Pair(21, 134), Pair(13, 129), Pair(20, 120), Pair(18, 135), Pair(28, 131), Pair(26, 149),
        Pair(25, 115), Pair(19, 126), Pair(15, 136), Pair(19, 122), Pair(13, 134), Pair(20, 120), Pair(52, 65), Pair(-2, 122)
      },
      { // Piece 5
        Pair(43, -144), Pair(50, -62), Pair(158, -17), Pair(60, -29), Pair(34, 16), Pair(65, -6), Pair(63, -48), Pair(81, -96),
        Pair(9, -37), Pair(4, -12), Pair(-195, 37), Pair(-102, -6), Pair(112, -33), Pair(14, 2), Pair(88, -4), Pair(-48, 28),
        Pair(-13, -49), Pair(100, 2), Pair(-42, 31), Pair(153, -6), Pair(28, -6), Pair(2, 2), Pair(-42, 20), Pair(-12, -9),
        Pair(-201, 16), Pair(81, -39), Pair(0, 0), Pair(68, -33), Pair(74, -4), Pair(-4, 15), Pair(-21, 22), Pair(2, 15),
        Pair(-45, 11), Pair(-146, -19), Pair(-74, -31), Pair(-90, -69), Pair(1, -3), Pair(27, 8), Pair(19, 6), Pair(-4, 8),
        Pair(-29, 20), Pair(16, -10), Pair(14, -21), Pair(66, -25), Pair(-5, -5), Pair(-3, 15), Pair(3, 7), Pair(22, 3),
        Pair(-45, 27), Pair(-25, 3), Pair(8, -13), Pair(5, -4), Pair(-3, 8), Pair(10, 6), Pair(2, 5), Pair(4, 3),
        Pair(-1, 22), Pair(-16, 3), Pair(-12, 11), Pair(15, 11), Pair(3, 21), Pair(15, 13), Pair(5, 5), Pair(5, -7)
      }
    }},
    {{ // Bucket 35
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-11, 21), Pair(20, 9), Pair(-6, 13), Pair(35, -30), Pair(-21, 16), Pair(-10, 4), Pair(12, 11), Pair(-8, 15),
        Pair(-3, 14), Pair(-3, 8), Pair(-6, -1), Pair(-5, 15), Pair(5, 4), Pair(3, 14), Pair(11, 13), Pair(-8, 8),
        Pair(1, 0), Pair(2, 7), Pair(-3, 0), Pair(0, 0), Pair(4, 1), Pair(1, 1), Pair(2, 2), Pair(1, 9),
        Pair(3, -3), Pair(1, -5), Pair(5, -5), Pair(0, 0), Pair(-2, 0), Pair(-1, 2), Pair(4, -2), Pair(1, 3),
        Pair(4, -5), Pair(0, -4), Pair(1, -7), Pair(2, 4), Pair(0, 1), Pair(-2, 1), Pair(0, -3), Pair(-4, 0),
        Pair(3, -3), Pair(4, -1), Pair(-1, -8), Pair(6, 13), Pair(-2, -6), Pair(-2, 2), Pair(2, -4), Pair(2, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-78, 74), Pair(-52, 83), Pair(-17, 59), Pair(45, 75), Pair(-7, 68), Pair(-31, 111), Pair(-74, 90), Pair(19, 84),
        Pair(-21, 69), Pair(5, 60), Pair(0, 76), Pair(-43, 72), Pair(40, 58), Pair(-44, 93), Pair(-30, 60), Pair(-1, 66),
        Pair(32, 50), Pair(-25, 34), Pair(-28, 79), Pair(-19, 53), Pair(-13, 84), Pair(-3, 44), Pair(-8, 71), Pair(19, 81),
        Pair(-18, 51), Pair(-11, 67), Pair(-16, 70), Pair(0, 0), Pair(-10, 69), Pair(-8, 79), Pair(-4, 50), Pair(-11, 67),
        Pair(-3, 45), Pair(12, 57), Pair(-45, -12), Pair(16, 103), Pair(-75, 3), Pair(-8, 67), Pair(-3, 63), Pair(2, 59),
        Pair(-10, 32), Pair(-7, 64), Pair(-13, 27), Pair(-3, 69), Pair(-20, 43), Pair(-1, 63), Pair(-12, 42), Pair(2, 65),
        Pair(1, 35), Pair(-38, 43), Pair(1, 58), Pair(-14, 18), Pair(1, 57), Pair(-11, 44), Pair(3, 68), Pair(2, 64),
        Pair(-7, 74), Pair(0, 36), Pair(6, 69), Pair(-15, 45), Pair(-3, 57), Pair(5, 50), Pair(3, 77), Pair(21, 94)
      },
      { // Piece 2
        Pair(-88, 42), Pair(-88, 71), Pair(-30, 63), Pair(-13, 77), Pair(-111, 103), Pair(-58, 78), Pair(-178, 123), Pair(23, 86),
        Pair(7, 63), Pair(-77, 52), Pair(-6, 68), Pair(-28, 80), Pair(-36, 75), Pair(-30, 73), Pair(5, 92), Pair(-8, 50),
        Pair(-28, 69), Pair(-42, 81), Pair(-68, 56), Pair(-17, 66), Pair(0, 39), Pair(-22, 68), Pair(-35, 87), Pair(13, 49),
        Pair(-15, 73), Pair(-21, 52), Pair(-7, 63), Pair(0, 0), Pair(-4, 67), Pair(-23, 69), Pair(-7, 64), Pair(-24, 61),
        Pair(-32, 68), Pair(-11, 53), Pair(-57, -62), Pair(13, 100), Pair(-108, -145), Pair(-9, 57), Pair(-12, 50), Pair(3, 51),
        Pair(-10, 65), Pair(-36, 40), Pair(-20, 51), Pair(-14, 39), Pair(-9, 43), Pair(-28, 32), Pair(-4, 48), Pair(-16, 43),
        Pair(-43, 16), Pair(-7, 40), Pair(-14, 42), Pair(-1, 49), Pair(-14, 36), Pair(3, 46), Pair(-21, 16), Pair(-3, 42),
        Pair(-22, 53), Pair(-11, 63), Pair(-3, 59), Pair(-10, 52), Pair(-7, 58), Pair(-11, 33), Pair(-17, 53), Pair(-40, 16)
      },
      { // Piece 3
        Pair(-4, 71), Pair(-24, 89), Pair(2, 80), Pair(20, 73), Pair(-6, 81), Pair(22, 80), Pair(-19, 79), Pair(2, 81),
        Pair(1, 78), Pair(-14, 86), Pair(-24, 95), Pair(-22, 106), Pair(-10, 85), Pair(47, 67), Pair(9, 76), Pair(-34, 99),
        Pair(-10, 83), Pair(-22, 86), Pair(-7, 77), Pair(-17, 94), Pair(4, 71), Pair(10, 74), Pair(34, 60), Pair(1, 74),
        Pair(-13, 82), Pair(-9, 65), Pair(-12, 78), Pair(0, 0), Pair(-5, 79), Pair(-9, 85), Pair(-2, 71), Pair(-6, 72),
        Pair(-14, 73), Pair(-13, 65), Pair(7, -56), Pair(-11, 63), Pair(-49, 19), Pair(-18, 68), Pair(-41, 87), Pair(-6, 57),
        Pair(-13, 73), Pair(-5, 66), Pair(-11, 60), Pair(-33, 78), Pair(-16, 81), Pair(-9, 75), Pair(-17, 78), Pair(0, 73),
        Pair(7, 55), Pair(-8, 77), Pair(-6, 62), Pair(-29, 69), Pair(-8, 57), Pair(-9, 70), Pair(-13, 68), Pair(-2, 76),
        Pair(-10, 70), Pair(-10, 73), Pair(-13, 69), Pair(-21, 66), Pair(-14, 72), Pair(-9, 73), Pair(-5, 64), Pair(5, 63)
      },
      { // Piece 4
        Pair(-16, 146), Pair(40, 109), Pair(4, 169), Pair(3, 159), Pair(18, 180), Pair(0, 179), Pair(25, 191), Pair(32, 166),
        Pair(20, 164), Pair(18, 105), Pair(12, 175), Pair(13, 132), Pair(7, 180), Pair(-7, 207), Pair(41, 191), Pair(42, 175),
        Pair(17, 127), Pair(5, 166), Pair(18, 104), Pair(3, 172), Pair(16, 162), Pair(0, 191), Pair(26, 143), Pair(24, 169),
        Pair(5, 164), Pair(19, 133), Pair(6, 120), Pair(0, 0), Pair(11, 147), Pair(20, 144), Pair(24, 159), Pair(7, 171),
        Pair(17, 132), Pair(20, 131), Pair(45, -40), Pair(34, 125), Pair(44, -21), Pair(34, 101), Pair(22, 137), Pair(23, 148),
        Pair(25, 140), Pair(17, 111), Pair(11, 124), Pair(21, 122), Pair(14, 140), Pair(11, 122), Pair(18, 134), Pair(18, 128),
        Pair(13, 116), Pair(14, 138), Pair(17, 109), Pair(19, 130), Pair(16, 123), Pair(30, 115), Pair(19, 119), Pair(33, 142),
        Pair(12, 127), Pair(24, 108), Pair(18, 138), Pair(25, 118), Pair(21, 137), Pair(18, 128), Pair(58, 79), Pair(19, 113)
      },
      { // Piece 5
        Pair(14, 126), Pair(-68, -38), Pair(-94, -76), Pair(-61, -43), Pair(55, 48), Pair(102, -61), Pair(32, -26), Pair(178, -7),
        Pair(102, 89), Pair(-89, -8), Pair(17, -29), Pair(95, -19), Pair(-59, 8), Pair(5, -1), Pair(8, -25), Pair(48, -50),
        Pair(103, -7), Pair(-27, 17), Pair(84, -12), Pair(129, -44), Pair(50, 1), Pair(67, -4), Pair(-8, 10), Pair(71, -2),
        Pair(40, 3), Pair(60, 20), Pair(60, -53), Pair(0, 0), Pair(113, -63), Pair(-38, 12), Pair(11, 22), Pair(11, 31),
        Pair(54, 37), Pair(-56, 26), Pair(-92, 36), Pair(-5, -53), Pair(32, 3), Pair(38, -3), Pair(14, 16), Pair(75, 1),
        Pair(30, 17), Pair(-19, 9), Pair(72, -30), Pair(32, -37), Pair(42, -28), Pair(-6, 5), Pair(4, 18), Pair(52, 0),
        Pair(-21, 45), Pair(-25, 22), Pair(-2, 12), Pair(7, -9), Pair(2, 0), Pair(-9, 23), Pair(3, 14), Pair(9, 9),
        Pair(6, -6), Pair(-14, 40), Pair(-12, 8), Pair(-10, -2), Pair(-5, 7), Pair(0, 25), Pair(-2, 20), Pair(3, 16)
      }
    }},
    {{ // Bucket 36
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-30, 30), Pair(19, 11), Pair(-1, 9), Pair(-17, 24), Pair(34, 6), Pair(23, 16), Pair(-26, 33), Pair(8, 5),
        Pair(3, 2), Pair(-1, 5), Pair(-1, -5), Pair(-10, 9), Pair(-18, 13), Pair(12, 6), Pair(7, 12), Pair(-7, 12),
        Pair(2, -2), Pair(2, -1), Pair(4, -2), Pair(2, -1), Pair(0, 0), Pair(-1, 6), Pair(-1, 5), Pair(-3, 10),
        Pair(3, -5), Pair(4, -7), Pair(4, -6), Pair(3, 4), Pair(0, 0), Pair(-4, -7), Pair(2, 2), Pair(-1, 4),
        Pair(3, -7), Pair(3, -4), Pair(-1, -3), Pair(2, -3), Pair(2, 5), Pair(-6, -3), Pair(-2, 2), Pair(-3, 0),
        Pair(7, -2), Pair(4, -4), Pair(2, -4), Pair(-1, -3), Pair(5, 6), Pair(-6, -3), Pair(2, 6), Pair(-2, -2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-78, 83), Pair(-102, 91), Pair(57, 46), Pair(79, 46), Pair(-15, 59), Pair(-92, 80), Pair(-126, 44), Pair(27, 44),
        Pair(-12, 43), Pair(4, 61), Pair(-1, 72), Pair(-15, 52), Pair(-28, 75), Pair(-85, 80), Pair(-15, 50), Pair(19, 53),
        Pair(7, 74), Pair(-2, 68), Pair(-15, 37), Pair(-16, 68), Pair(-21, 46), Pair(-30, 76), Pair(-41, 36), Pair(15, 53),
        Pair(5, 53), Pair(-10, 53), Pair(2, 68), Pair(-7, 54), Pair(0, 0), Pair(-21, 54), Pair(-11, 54), Pair(-29, 28),
        Pair(4, 65), Pair(15, 39), Pair(1, 59), Pair(-73, 4), Pair(7, 101), Pair(-44, -2), Pair(-3, 64), Pair(1, 45),
        Pair(4, 46), Pair(-15, 46), Pair(-3, 57), Pair(-22, 39), Pair(-4, 64), Pair(-11, 20), Pair(-5, 50), Pair(-20, 10),
        Pair(-15, 67), Pair(4, 37), Pair(-1, 24), Pair(-2, 55), Pair(-20, 10), Pair(0, 54), Pair(-14, 38), Pair(2, 53),
        Pair(-48, 58), Pair(8, 60), Pair(-4, 44), Pair(16, 56), Pair(-3, 41), Pair(15, 42), Pair(-6, 45), Pair(83, -23)
      },
      { // Piece 2
        Pair(-33, 76), Pair(-21, 48), Pair(-62, 72), Pair(-91, 79), Pair(-111, 87), Pair(-94, 83), Pair(97, 52), Pair(-13, 60),
        Pair(-31, 67), Pair(-10, 63), Pair(-12, 47), Pair(-23, 72), Pair(-72, 87), Pair(-17, 60), Pair(43, 10), Pair(29, 69),
        Pair(-9, 69), Pair(-16, 51), Pair(-45, 71), Pair(-45, 54), Pair(5, 49), Pair(-60, 49), Pair(-18, 69), Pair(1, 41),
        Pair(-12, 49), Pair(-2, 54), Pair(-17, 54), Pair(-1, 61), Pair(0, 0), Pair(-13, 66), Pair(-18, 47), Pair(-4, 53),
        Pair(-5, 53), Pair(-14, 55), Pair(-10, 55), Pair(-78, -66), Pair(3, 104), Pair(-37, -80), Pair(-4, 61), Pair(-13, 41),
        Pair(-5, 47), Pair(-3, 53), Pair(-17, 21), Pair(-11, 50), Pair(-11, 34), Pair(-13, 41), Pair(-32, 11), Pair(-1, 52),
        Pair(-15, 71), Pair(-13, 16), Pair(-6, 55), Pair(-7, 40), Pair(-2, 46), Pair(-10, 35), Pair(-8, 39), Pair(-24, -46),
        Pair(-38, 23), Pair(-8, 68), Pair(-1, 36), Pair(7, 49), Pair(-28, 52), Pair(-2, 56), Pair(-24, 68), Pair(-25, 73)
      },
      { // Piece 3
        Pair(15, 67), Pair(-6, 78), Pair(-26, 80), Pair(4, 63), Pair(-26, 64), Pair(-14, 65), Pair(-45, 78), Pair(-36, 78),
        Pair(9, 70), Pair(5, 72), Pair(-8, 80), Pair(-4, 65), Pair(-15, 88), Pair(14, 72), Pair(31, 58), Pair(-5, 69),
        Pair(3, 65), Pair(-1, 73), Pair(-11, 76), Pair(-8, 78), Pair(7, 75), Pair(15, 55), Pair(10, 68), Pair(-6, 60),
        Pair(2, 67), Pair(5, 52), Pair(-9, 73), Pair(20, 49), Pair(0, 0), Pair(17, 40), Pair(-15, 74), Pair(5, 56),
        Pair(0, 61), Pair(6, 55), Pair(-15, 63), Pair(-49, -10), Pair(3, 54), Pair(13, -83), Pair(-21, 54), Pair(-5, 42),
        Pair(-5, 68), Pair(-1, 66), Pair(-1, 59), Pair(-7, 62), Pair(-14, 46), Pair(-2, 47), Pair(-6, 57), Pair(20, 56),
        Pair(13, 63), Pair(-4, 55), Pair(3, 60), Pair(-6, 48), Pair(-14, 58), Pair(12, 51), Pair(15, 42), Pair(29, 32),
        Pair(4, 62), Pair(-1, 60), Pair(1, 65), Pair(-8, 57), Pair(-7, 51), Pair(-3, 60), Pair(-2, 65), Pair(-1, 65)
      },
      { // Piece 4
        Pair(16, 131), Pair(-37, 161), Pair(-24, 196), Pair(14, 142), Pair(-9, 174), Pair(-13, 197), Pair(4, 132), Pair(26, 75),
        Pair(30, 135), Pair(12, 144), Pair(28, 114), Pair(43, 114), Pair(-18, 177), Pair(-19, 186), Pair(-23, 181), Pair(-1, 173),
        Pair(23, 123), Pair(30, 105), Pair(31, 124), Pair(4, 113), Pair(23, 140), Pair(-20, 201), Pair(-5, 168), Pair(20, 149),
        Pair(30, 106), Pair(30, 146), Pair(8, 111), Pair(25, 120), Pair(0, 0), Pair(0, 133), Pair(6, 99), Pair(24, 125),
        Pair(23, 132), Pair(11, 141), Pair(25, 109), Pair(27, 32), Pair(34, 107), Pair(36, -4), Pair(19, 126), Pair(14, 136),
        Pair(26, 137), Pair(16, 118), Pair(9, 109), Pair(6, 116), Pair(9, 120), Pair(16, 109), Pair(9, 101), Pair(6, 130),
        Pair(40, 94), Pair(11, 116), Pair(14, 119), Pair(7, 108), Pair(24, 114), Pair(13, 125), Pair(22, 95), Pair(24, 93),
        Pair(21, 113), Pair(15, 130), Pair(19, 80), Pair(20, 96), Pair(24, 96), Pair(20, 107), Pair(21, 102), Pair(15, 118)
      },
      { // Piece 5
        Pair(-151, 25), Pair(-49, 64), Pair(42, -47), Pair(-45, 58), Pair(56, 38), Pair(51, 74), Pair(71, -2), Pair(-5, -34),
        Pair(-22, -14), Pair(-6, 36), Pair(5, -1), Pair(38, 32), Pair(58, -27), Pair(-1, 11), Pair(22, -18), Pair(134, -18),
        Pair(-6, 10), Pair(48, 17), Pair(4, 0), Pair(78, -6), Pair(105, -5), Pair(164, -7), Pair(34, 27), Pair(98, -14),
        Pair(4, 6), Pair(59, 8), Pair(-37, 24), Pair(119, -59), Pair(0, 0), Pair(120, -56), Pair(70, -3), Pair(64, 13),
        Pair(-40, 16), Pair(9, 18), Pair(-45, 25), Pair(161, -95), Pair(-23, -38), Pair(43, -43), Pair(2, 6), Pair(23, 18),
        Pair(11, 13), Pair(29, 0), Pair(16, -2), Pair(80, -27), Pair(69, -29), Pair(62, -22), Pair(15, 7), Pair(6, 24),
        Pair(34, 8), Pair(12, 10), Pair(17, 18), Pair(30, 0), Pair(23, -6), Pair(23, 3), Pair(-3, 24), Pair(11, 20),
        Pair(0, 22), Pair(-3, 34), Pair(4, 27), Pair(22, 8), Pair(4, 10), Pair(24, 7), Pair(-2, 33), Pair(6, 36)
      }
    }},
    {{ // Bucket 37
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-4, 14), Pair(18, 10), Pair(-7, 15), Pair(28, 2), Pair(-7, 8), Pair(3, 13), Pair(8, 17), Pair(0, 10),
        Pair(4, 4), Pair(11, 0), Pair(4, 2), Pair(0, 4), Pair(1, -6), Pair(4, 6), Pair(6, 8), Pair(-6, 7),
        Pair(3, -1), Pair(4, -3), Pair(1, 1), Pair(0, -3), Pair(3, -2), Pair(0, 0), Pair(1, -1), Pair(-1, 3),
        Pair(8, -4), Pair(1, -7), Pair(5, -3), Pair(3, -4), Pair(6, 7), Pair(0, 0), Pair(-3, -9), Pair(-2, -1),
        Pair(5, -7), Pair(4, -7), Pair(2, -6), Pair(4, -5), Pair(0, -1), Pair(1, 3), Pair(-6, -6), Pair(0, -1),
        Pair(4, -7), Pair(5, -5), Pair(5, -7), Pair(2, -4), Pair(0, -1), Pair(7, 1), Pair(-4, -4), Pair(0, -3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-60, 71), Pair(21, 70), Pair(-42, 47), Pair(3, 69), Pair(52, 24), Pair(-60, 103), Pair(67, -17), Pair(-32, 65),
        Pair(-12, 57), Pair(19, 41), Pair(11, 54), Pair(-7, 42), Pair(1, 44), Pair(-5, 61), Pair(7, 35), Pair(30, 43),
        Pair(9, 53), Pair(14, 49), Pair(11, 45), Pair(6, 31), Pair(-2, 57), Pair(-12, 39), Pair(-9, 52), Pair(5, -8),
        Pair(16, 34), Pair(10, 48), Pair(1, 32), Pair(2, 52), Pair(0, 48), Pair(0, 0), Pair(-14, 41), Pair(-5, 39),
        Pair(17, 25), Pair(10, 51), Pair(7, 38), Pair(12, 38), Pair(-57, -23), Pair(12, 75), Pair(-60, -30), Pair(5, 42),
        Pair(14, 48), Pair(9, 46), Pair(0, 38), Pair(1, 41), Pair(-11, 27), Pair(10, 47), Pair(-21, 17), Pair(9, 32),
        Pair(-8, 49), Pair(-7, 60), Pair(12, 45), Pair(-3, 33), Pair(5, 44), Pair(-16, 8), Pair(9, 58), Pair(-10, -6),
        Pair(-13, 31), Pair(12, 50), Pair(11, 32), Pair(1, 47), Pair(-3, 54), Pair(-3, 44), Pair(-5, 63), Pair(-14, 23)
      },
      { // Piece 2
        Pair(-25, 66), Pair(74, 58), Pair(20, 37), Pair(-68, 65), Pair(-36, 76), Pair(-106, 75), Pair(-103, 86), Pair(45, 39),
        Pair(-5, 55), Pair(-39, 61), Pair(17, 55), Pair(-19, 62), Pair(-9, 52), Pair(-33, 78), Pair(8, 53), Pair(-90, 58),
        Pair(-7, 64), Pair(6, 58), Pair(-25, 58), Pair(7, 45), Pair(-28, 50), Pair(-8, 63), Pair(-46, 32), Pair(9, 53),
        Pair(6, 44), Pair(-11, 57), Pair(-3, 52), Pair(-15, 45), Pair(5, 51), Pair(0, 0), Pair(0, 49), Pair(-17, 45),
        Pair(-10, 57), Pair(16, 36), Pair(-10, 54), Pair(4, 39), Pair(-96, -59), Pair(12, 81), Pair(-84, -39), Pair(-5, 38),
        Pair(12, 50), Pair(3, 45), Pair(5, 48), Pair(-9, 26), Pair(-3, 31), Pair(-7, 37), Pair(-18, 32), Pair(-29, 3),
        Pair(6, 42), Pair(10, 43), Pair(-18, 39), Pair(8, 37), Pair(-3, 35), Pair(4, 50), Pair(-15, 20), Pair(-8, 50),
        Pair(-2, 50), Pair(-31, 41), Pair(9, 39), Pair(7, 31), Pair(7, 37), Pair(0, 39), Pair(-32, 65), Pair(-24, 70)
      },
      { // Piece 3
        Pair(20, 48), Pair(34, 49), Pair(4, 55), Pair(31, 50), Pair(32, 47), Pair(8, 56), Pair(8, 41), Pair(-16, 57),
        Pair(21, 46), Pair(19, 45), Pair(13, 49), Pair(-6, 60), Pair(6, 62), Pair(26, 66), Pair(83, 34), Pair(-3, 54),
        Pair(21, 40), Pair(22, 50), Pair(22, 39), Pair(21, 49), Pair(13, 42), Pair(52, 57), Pair(-17, 60), Pair(-1, 57),
        Pair(20, 40), Pair(7, 53), Pair(5, 53), Pair(16, 52), Pair(21, 41), Pair(0, 0), Pair(-8, 46), Pair(-7, 47),
        Pair(13, 36), Pair(10, 41), Pair(5, 42), Pair(-11, 50), Pair(-37, -36), Pair(4, 54), Pair(2, -76), Pair(-10, 43),
        Pair(14, 46), Pair(15, 45), Pair(6, 47), Pair(20, 39), Pair(2, 39), Pair(13, 28), Pair(-9, 41), Pair(-5, 42),
        Pair(16, 60), Pair(20, 46), Pair(18, 40), Pair(14, 44), Pair(7, 35), Pair(6, 42), Pair(5, 48), Pair(22, 40),
        Pair(13, 52), Pair(8, 55), Pair(13, 47), Pair(8, 51), Pair(9, 42), Pair(7, 42), Pair(4, 46), Pair(8, 55)
      },
      { // Piece 4
        Pair(3, 91), Pair(-2, 132), Pair(33, 70), Pair(-31, 144), Pair(9, 126), Pair(-2, 120), Pair(88, 77), Pair(14, 117),
        Pair(25, 101), Pair(14, 101), Pair(29, 100), Pair(28, 119), Pair(9, 140), Pair(9, 132), Pair(2, 145), Pair(22, 152),
        Pair(21, 94), Pair(10, 115), Pair(34, 80), Pair(30, 99), Pair(22, 91), Pair(55, 73), Pair(39, 32), Pair(4, 128),
        Pair(39, 87), Pair(27, 93), Pair(29, 92), Pair(37, 84), Pair(23, 98), Pair(0, 0), Pair(34, 79), Pair(21, 65),
        Pair(19, 86), Pair(29, 98), Pair(21, 93), Pair(29, 80), Pair(-29, 36), Pair(30, 70), Pair(28, 65), Pair(12, 126),
        Pair(20, 121), Pair(12, 110), Pair(19, 82), Pair(10, 102), Pair(14, 77), Pair(31, 59), Pair(11, 93), Pair(6, 50),
        Pair(19, 111), Pair(19, 102), Pair(22, 72), Pair(17, 93), Pair(18, 82), Pair(26, 73), Pair(14, 95), Pair(46, 96),
        Pair(21, 95), Pair(8, 103), Pair(28, 74), Pair(21, 81), Pair(30, 74), Pair(52, 15), Pair(-12, 112), Pair(31, 139)
      },
      { // Piece 5
        Pair(111, -8), Pair(54, -16), Pair(-223, 10), Pair(13, -22), Pair(-54, 9), Pair(120, -75), Pair(-169, -38), Pair(-112, 11),
        Pair(-121, 15), Pair(64, -8), Pair(21, -8), Pair(-131, -9), Pair(101, -24), Pair(-11, -7), Pair(37, -9), Pair(-66, 26),
        Pair(43, 17), Pair(110, -9), Pair(-77, 34), Pair(38, 0), Pair(-49, 12), Pair(135, -9), Pair(1, 7), Pair(-7, 1),
        Pair(-78, 11), Pair(-63, 36), Pair(112, 1), Pair(-78, 18), Pair(83, -40), Pair(0, 0), Pair(145, -45), Pair(49, 10),
        Pair(75, -10), Pair(11, 15), Pair(51, -3), Pair(22, -3), Pair(8, -107), Pair(-36, -34), Pair(-95, -61), Pair(37, 9),
        Pair(13, 2), Pair(45, -8), Pair(28, 6), Pair(26, -1), Pair(27, -16), Pair(39, -10), Pair(18, -6), Pair(-7, 16),
        Pair(27, -10), Pair(13, -4), Pair(44, -3), Pair(16, 9), Pair(13, 5), Pair(10, -1), Pair(11, 7), Pair(6, 17),
        Pair(9, -18), Pair(-14, 21), Pair(-2, 10), Pair(-4, 27), Pair(-1, 20), Pair(7, 5), Pair(-6, 12), Pair(2, 22)
      }
    }},
    {{ // Bucket 38
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(25, 15), Pair(25, 17), Pair(12, 9), Pair(7, 13), Pair(11, 13), Pair(28, 7), Pair(36, -5), Pair(-27, 27),
        Pair(2, 5), Pair(4, 4), Pair(5, 2), Pair(0, 10), Pair(9, 4), Pair(-12, 8), Pair(0, 12), Pair(-2, 8),
        Pair(2, 3), Pair(3, -1), Pair(2, 2), Pair(0, 3), Pair(0, 3), Pair(-2, 6), Pair(0, 0), Pair(2, 12),
        Pair(3, -4), Pair(9, -5), Pair(3, 0), Pair(-2, 2), Pair(-3, -1), Pair(2, 9), Pair(0, 0), Pair(6, 12),
        Pair(1, -4), Pair(2, -5), Pair(-1, -2), Pair(1, -2), Pair(2, 1), Pair(-3, 5), Pair(-3, 7), Pair(1, 3),
        Pair(2, -7), Pair(5, -11), Pair(1, -7), Pair(3, -5), Pair(1, -3), Pair(3, 0), Pair(4, 1), Pair(0, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-42, 80), Pair(-38, 59), Pair(-52, 68), Pair(-101, 70), Pair(120, 45), Pair(-94, 80), Pair(43, 34), Pair(-6, -21),
        Pair(46, 49), Pair(31, 47), Pair(15, 38), Pair(-22, 54), Pair(67, 21), Pair(11, 54), Pair(-84, 54), Pair(-25, 40),
        Pair(-12, 51), Pair(39, 40), Pair(31, 39), Pair(17, 47), Pair(31, 25), Pair(-5, 57), Pair(9, 2), Pair(0, 51),
        Pair(21, 26), Pair(25, 35), Pair(31, 33), Pair(9, 35), Pair(23, 46), Pair(20, 40), Pair(0, 0), Pair(-15, 37),
        Pair(16, 20), Pair(-4, 58), Pair(29, 40), Pair(16, 42), Pair(15, 39), Pair(-42, -16), Pair(19, 91), Pair(-45, -1),
        Pair(4, 64), Pair(14, 43), Pair(11, 41), Pair(-2, 43), Pair(18, 47), Pair(5, 32), Pair(17, 52), Pair(-17, 8),
        Pair(28, 44), Pair(-3, 62), Pair(10, 34), Pair(9, 44), Pair(-4, 37), Pair(11, 42), Pair(-6, -12), Pair(17, 66),
        Pair(-9, 37), Pair(8, 49), Pair(20, 31), Pair(0, 47), Pair(24, 34), Pair(15, 50), Pair(1, 45), Pair(-47, 116)
      },
      { // Piece 2
        Pair(-58, 101), Pair(-86, 66), Pair(-88, 103), Pair(-44, 67), Pair(-74, 77), Pair(-92, 70), Pair(62, 53), Pair(46, 52),
        Pair(27, 59), Pair(28, 53), Pair(-28, 65), Pair(-62, 99), Pair(-36, 75), Pair(-57, 74), Pair(-19, 72), Pair(19, 42),
        Pair(-2, 59), Pair(-9, 64), Pair(-1, 76), Pair(-8, 61), Pair(20, 59), Pair(0, 55), Pair(-14, 62), Pair(-73, 4),
        Pair(12, 54), Pair(15, 51), Pair(0, 57), Pair(9, 55), Pair(5, 53), Pair(-4, 63), Pair(0, 0), Pair(-7, 57),
        Pair(27, 56), Pair(1, 59), Pair(16, 50), Pair(4, 53), Pair(-3, 43), Pair(-55, -34), Pair(21, 90), Pair(-56, -46),
        Pair(-6, 60), Pair(21, 53), Pair(2, 51), Pair(7, 43), Pair(1, 37), Pair(3, 43), Pair(-11, 42), Pair(-2, 51),
        Pair(7, 69), Pair(11, 46), Pair(21, 48), Pair(-6, 42), Pair(7, 49), Pair(-1, 52), Pair(17, 32), Pair(-6, 26),
        Pair(12, 48), Pair(-1, 55), Pair(-3, 38), Pair(13, 45), Pair(-1, 48), Pair(14, 52), Pair(-28, 52), Pair(9, 44)
      },
      { // Piece 3
        Pair(12, 60), Pair(-20, 80), Pair(2, 70), Pair(-18, 71), Pair(4, 64), Pair(-107, 90), Pair(18, 62), Pair(14, 73),
        Pair(31, 52), Pair(31, 55), Pair(30, 61), Pair(21, 62), Pair(20, 62), Pair(48, 47), Pair(86, 65), Pair(11, 66),
        Pair(25, 49), Pair(7, 60), Pair(36, 50), Pair(3, 68), Pair(29, 43), Pair(15, 59), Pair(40, 71), Pair(-1, 70),
        Pair(33, 51), Pair(17, 54), Pair(25, 55), Pair(24, 63), Pair(56, 54), Pair(26, 49), Pair(0, 0), Pair(-9, 47),
        Pair(22, 49), Pair(11, 61), Pair(10, 54), Pair(8, 59), Pair(15, 53), Pair(5, -44), Pair(-20, 56), Pair(-53, -37),
        Pair(24, 44), Pair(39, 43), Pair(28, 54), Pair(23, 52), Pair(21, 59), Pair(6, 55), Pair(-4, 53), Pair(-19, 52),
        Pair(23, 62), Pair(39, 53), Pair(30, 57), Pair(27, 53), Pair(34, 47), Pair(30, 40), Pair(-3, 56), Pair(45, 21),
        Pair(24, 60), Pair(25, 57), Pair(22, 55), Pair(23, 58), Pair(22, 55), Pair(19, 51), Pair(0, 65), Pair(6, 48)
      },
      { // Piece 4
        Pair(22, 121), Pair(39, 52), Pair(-5, 118), Pair(68, 44), Pair(-52, 171), Pair(24, 119), Pair(55, 75), Pair(50, 93),
        Pair(50, 58), Pair(37, 95), Pair(37, 71), Pair(32, 103), Pair(-7, 100), Pair(40, 99), Pair(-73, 185), Pair(39, 131),
        Pair(55, 60), Pair(50, 87), Pair(51, 59), Pair(19, 68), Pair(-6, 126), Pair(1, 93), Pair(17, 101), Pair(12, 37),
        Pair(37, 78), Pair(22, 103), Pair(23, 99), Pair(8, 109), Pair(14, 98), Pair(19, 92), Pair(0, 0), Pair(-3, 88),
        Pair(21, 111), Pair(24, 102), Pair(39, 94), Pair(17, 104), Pair(21, 85), Pair(0, 56), Pair(23, 51), Pair(-17, 72),
        Pair(11, 129), Pair(16, 105), Pair(17, 115), Pair(23, 95), Pair(15, 75), Pair(14, 84), Pair(10, 86), Pair(1, 110),
        Pair(13, 123), Pair(23, 83), Pair(27, 68), Pair(21, 82), Pair(21, 95), Pair(11, 99), Pair(1, 119), Pair(23, 98),
        Pair(3, 121), Pair(29, 84), Pair(41, 65), Pair(26, 91), Pair(37, 62), Pair(-1, 114), Pair(-19, 124), Pair(38, 168)
      },
      { // Piece 5
        Pair(-13, -1), Pair(34, -21), Pair(186, -77), Pair(133, -41), Pair(63, -47), Pair(-46, -27), Pair(-97, -42), Pair(-35, -250),
        Pair(109, -36), Pair(35, -21), Pair(171, -34), Pair(133, -8), Pair(185, -59), Pair(23, -45), Pair(118, -33), Pair(104, -56),
        Pair(132, -16), Pair(64, -26), Pair(60, -25), Pair(-19, 4), Pair(-34, 11), Pair(-11, -1), Pair(174, -26), Pair(75, -17),
        Pair(53, -16), Pair(-8, 10), Pair(83, -12), Pair(14, -10), Pair(23, -8), Pair(61, -33), Pair(0, 0), Pair(11, -26),
        Pair(132, -50), Pair(36, -25), Pair(47, -17), Pair(7, -7), Pair(-7, -9), Pair(-145, -54), Pair(-43, -49), Pair(-423, -23),
        Pair(95, -42), Pair(91, -33), Pair(11, -14), Pair(26, -11), Pair(-14, -8), Pair(40, -21), Pair(17, -23), Pair(-22, -13),
        Pair(21, -15), Pair(-41, -12), Pair(8, -15), Pair(40, -11), Pair(3, 2), Pair(26, -7), Pair(-8, -4), Pair(1, -4),
        Pair(3, -38), Pair(-11, -25), Pair(4, -13), Pair(-8, 14), Pair(0, 11), Pair(7, -2), Pair(-11, 1), Pair(-3, -9)
      }
    }},
    {{ // Bucket 39
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(24, 4), Pair(-1, 16), Pair(38, -1), Pair(15, 7), Pair(13, 6), Pair(1, 16), Pair(-24, 5), Pair(-8, 102),
        Pair(10, 2), Pair(-5, 2), Pair(8, 2), Pair(12, 2), Pair(-4, 8), Pair(-14, 7), Pair(-5, 6), Pair(34, -45),
        Pair(4, -4), Pair(1, 1), Pair(5, -1), Pair(-1, -2), Pair(-5, -1), Pair(-4, 2), Pair(-12, -4), Pair(0, 0),
        Pair(6, -6), Pair(3, -4), Pair(2, -5), Pair(1, -3), Pair(3, -3), Pair(0, -1), Pair(-7, -11), Pair(0, 0),
        Pair(4, -5), Pair(1, -10), Pair(0, -6), Pair(-2, -5), Pair(2, -4), Pair(1, -1), Pair(-4, -7), Pair(4, 3),
        Pair(4, -7), Pair(1, -6), Pair(-3, -7), Pair(0, -7), Pair(2, -6), Pair(7, -3), Pair(0, -8), Pair(1, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-52, 46), Pair(-108, 61), Pair(19, 31), Pair(83, -12), Pair(-2, 49), Pair(-31, 69), Pair(7, 11), Pair(-104, 47),
        Pair(35, 1), Pair(19, 8), Pair(-2, 21), Pair(18, 28), Pair(40, 16), Pair(-5, 43), Pair(36, 20), Pair(20, 77),
        Pair(64, 6), Pair(16, 16), Pair(8, 33), Pair(39, 14), Pair(24, 36), Pair(49, 17), Pair(-39, 52), Pair(12, 30),
        Pair(37, 14), Pair(16, 24), Pair(24, 23), Pair(18, 22), Pair(24, 18), Pair(6, 40), Pair(6, 46), Pair(0, 0),
        Pair(9, 26), Pair(20, 22), Pair(12, 19), Pair(12, 33), Pair(18, 31), Pair(31, 26), Pair(-26, -28), Pair(21, 70),
        Pair(9, 32), Pair(8, 28), Pair(14, 28), Pair(5, 33), Pair(7, 20), Pair(12, 36), Pair(14, 29), Pair(21, 55),
        Pair(18, 6), Pair(17, 28), Pair(7, 19), Pair(13, 27), Pair(7, 44), Pair(-5, 34), Pair(15, 36), Pair(-2, -4),
        Pair(15, -76), Pair(2, 32), Pair(-2, 18), Pair(28, 3), Pair(18, 25), Pair(3, 36), Pair(9, 51), Pair(23, -3)
      },
      { // Piece 2
        Pair(-21, 74), Pair(-9, 70), Pair(-47, 83), Pair(-50, 72), Pair(-65, 86), Pair(7, 51), Pair(-61, 96), Pair(-1, 44),
        Pair(-12, 58), Pair(24, 57), Pair(-17, 63), Pair(-33, 88), Pair(-43, 82), Pair(-16, 85), Pair(-43, 50), Pair(61, 36),
        Pair(-8, 71), Pair(-13, 43), Pair(-20, 68), Pair(-4, 57), Pair(2, 49), Pair(-21, 63), Pair(4, 75), Pair(38, 42),
        Pair(0, 44), Pair(2, 58), Pair(-1, 47), Pair(12, 53), Pair(16, 44), Pair(5, 58), Pair(5, 52), Pair(0, 0),
        Pair(-10, 61), Pair(8, 36), Pair(-4, 53), Pair(3, 33), Pair(7, 49), Pair(5, 39), Pair(-97, -51), Pair(8, 85),
        Pair(2, 43), Pair(11, 56), Pair(3, 41), Pair(9, 47), Pair(8, 30), Pair(3, 50), Pair(-1, 36), Pair(1, 67),
        Pair(13, 55), Pair(9, 36), Pair(-3, 47), Pair(0, 40), Pair(2, 48), Pair(6, 40), Pair(14, 41), Pair(20, 37),
        Pair(12, 34), Pair(18, 49), Pair(3, 34), Pair(4, 52), Pair(-4, 42), Pair(8, 56), Pair(-9, 49), Pair(-4, 62)
      },
      { // Piece 3
        Pair(-11, 63), Pair(14, 62), Pair(-29, 77), Pair(14, 60), Pair(-28, 66), Pair(5, 75), Pair(-36, 79), Pair(49, 69),
        Pair(20, 55), Pair(5, 65), Pair(13, 59), Pair(13, 59), Pair(26, 58), Pair(-1, 63), Pair(64, 46), Pair(109, 58),
        Pair(19, 54), Pair(12, 58), Pair(9, 65), Pair(6, 58), Pair(12, 51), Pair(-6, 60), Pair(16, 57), Pair(22, 82),
        Pair(17, 61), Pair(12, 61), Pair(22, 63), Pair(28, 47), Pair(29, 50), Pair(9, 73), Pair(45, 59), Pair(0, 0),
        Pair(2, 63), Pair(23, 50), Pair(24, 52), Pair(-3, 49), Pair(11, 51), Pair(0, 50), Pair(41, -105), Pair(-12, 78),
        Pair(8, 43), Pair(33, 55), Pair(12, 55), Pair(13, 60), Pair(6, 52), Pair(13, 53), Pair(2, 47), Pair(-27, 63),
        Pair(35, 50), Pair(9, 59), Pair(27, 49), Pair(18, 55), Pair(16, 54), Pair(19, 42), Pair(21, 47), Pair(-19, 74),
        Pair(13, 59), Pair(8, 63), Pair(10, 59), Pair(9, 58), Pair(12, 54), Pair(14, 48), Pair(3, 62), Pair(-4, 59)
      },
      { // Piece 4
        Pair(34, 98), Pair(10, 103), Pair(44, 61), Pair(8, 83), Pair(4, 99), Pair(80, 90), Pair(21, 131), Pair(32, 88),
        Pair(34, 77), Pair(9, 110), Pair(35, 84), Pair(-13, 108), Pair(17, 104), Pair(-21, 152), Pair(-7, 89), Pair(57, 140),
        Pair(25, 80), Pair(23, 81), Pair(9, 84), Pair(27, 63), Pair(13, 92), Pair(37, 95), Pair(-22, 113), Pair(21, 117),
        Pair(22, 78), Pair(10, 93), Pair(28, 84), Pair(9, 111), Pair(30, 100), Pair(20, 92), Pair(14, 90), Pair(0, 0),
        Pair(22, 82), Pair(19, 85), Pair(9, 89), Pair(14, 94), Pair(20, 97), Pair(31, 65), Pair(37, 17), Pair(16, 51),
        Pair(5, 92), Pair(20, 78), Pair(10, 98), Pair(24, 79), Pair(22, 70), Pair(9, 107), Pair(17, 75), Pair(-19, 90),
        Pair(17, 107), Pair(20, 85), Pair(21, 72), Pair(17, 74), Pair(14, 85), Pair(27, 74), Pair(30, 71), Pair(-12, 170),
        Pair(17, 72), Pair(19, 81), Pair(21, 76), Pair(20, 65), Pair(27, 65), Pair(17, 104), Pair(0, 112), Pair(-13, 114)
      },
      { // Piece 5
        Pair(35, -42), Pair(118, -25), Pair(282, -40), Pair(-45, -10), Pair(131, -28), Pair(41, 0), Pair(49, 16), Pair(64, 218),
        Pair(114, -33), Pair(92, -17), Pair(34, 13), Pair(-91, 16), Pair(-111, -4), Pair(41, -31), Pair(75, -42), Pair(87, -10),
        Pair(29, -7), Pair(97, -18), Pair(73, -10), Pair(29, -1), Pair(95, -1), Pair(119, -24), Pair(10, 20), Pair(5, -10),
        Pair(71, -31), Pair(66, -18), Pair(46, -14), Pair(38, -4), Pair(33, 0), Pair(-106, 17), Pair(64, -39), Pair(0, 0),
        Pair(71, -19), Pair(91, -23), Pair(71, -21), Pair(58, -11), Pair(-8, 6), Pair(-8, 5), Pair(-368, 41), Pair(126, -61),
        Pair(28, -6), Pair(93, -41), Pair(59, -22), Pair(27, -4), Pair(22, 0), Pair(-20, 11), Pair(28, 6), Pair(29, 7),
        Pair(25, -27), Pair(1, -17), Pair(29, -20), Pair(6, 1), Pair(16, 6), Pair(3, 14), Pair(10, 9), Pair(4, -1),
        Pair(-5, -18), Pair(-9, -22), Pair(-7, -12), Pair(12, 5), Pair(-3, 19), Pair(-5, 22), Pair(5, 11), Pair(2, 8)
      }
    }},
    {{ // Bucket 40
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(82, -73), Pair(-10, 30), Pair(-21, 24), Pair(3, 18), Pair(17, 14), Pair(13, 15), Pair(3, 15), Pair(-30, 38),
        Pair(0, 0), Pair(-13, 6), Pair(4, 2), Pair(3, 7), Pair(6, 15), Pair(-4, 14), Pair(8, 24), Pair(-9, 18),
        Pair(-10, -13), Pair(-4, 0), Pair(-5, 1), Pair(-1, 6), Pair(0, 8), Pair(-8, 15), Pair(-1, 8), Pair(-4, 12),
        Pair(-6, -4), Pair(-7, -2), Pair(1, 3), Pair(-2, 3), Pair(-2, 5), Pair(-4, 7), Pair(-2, 5), Pair(-1, 7),
        Pair(0, 0), Pair(-4, 0), Pair(1, 1), Pair(-1, -1), Pair(-2, 6), Pair(-7, 5), Pair(-3, 1), Pair(-2, 1),
        Pair(9, -4), Pair(-3, -3), Pair(0, -1), Pair(0, -1), Pair(0, 0), Pair(-3, -2), Pair(-4, -2), Pair(-1, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-8, 22), Pair(3, 64), Pair(-30, 57), Pair(115, 25), Pair(39, 38), Pair(6, 73), Pair(77, 1), Pair(34, 32),
        Pair(-28, 3), Pair(13, 62), Pair(11, 37), Pair(18, 45), Pair(20, 45), Pair(36, 18), Pair(35, 38), Pair(26, 26),
        Pair(0, 0), Pair(18, 60), Pair(-5, 66), Pair(3, 52), Pair(-7, 59), Pair(31, 30), Pair(54, 13), Pair(25, 52),
        Pair(28, 93), Pair(-39, -35), Pair(11, 59), Pair(10, 49), Pair(16, 47), Pair(24, 38), Pair(19, 38), Pair(36, 23),
        Pair(6, 68), Pair(-24, 70), Pair(6, 53), Pair(1, 43), Pair(13, 46), Pair(8, 51), Pair(19, 47), Pair(15, 53),
        Pair(-10, 19), Pair(5, 49), Pair(-10, 53), Pair(10, 48), Pair(9, 39), Pair(6, 45), Pair(14, 48), Pair(14, 42),
        Pair(17, 65), Pair(13, 45), Pair(6, 44), Pair(7, 50), Pair(11, 37), Pair(13, 38), Pair(11, 29), Pair(12, 54),
        Pair(-26, 59), Pair(5, 45), Pair(18, 39), Pair(20, 41), Pair(-1, 39), Pair(12, 44), Pair(9, 50), Pair(-25, 92)
      },
      { // Piece 2
        Pair(-2, 80), Pair(-67, 109), Pair(58, 80), Pair(-72, 109), Pair(-34, 68), Pair(-29, 98), Pair(-53, 83), Pair(-90, 92),
        Pair(33, 84), Pair(1, 93), Pair(-5, 93), Pair(-20, 88), Pair(-19, 93), Pair(-38, 108), Pair(4, 89), Pair(18, 80),
        Pair(0, 0), Pair(-9, 87), Pair(-17, 97), Pair(13, 81), Pair(-2, 93), Pair(14, 89), Pair(-21, 89), Pair(29, 52),
        Pair(33, 99), Pair(-52, -50), Pair(2, 79), Pair(-12, 90), Pair(7, 80), Pair(-3, 86), Pair(9, 75), Pair(-1, 70),
        Pair(-19, 91), Pair(-32, 75), Pair(-10, 81), Pair(-9, 85), Pair(3, 71), Pair(9, 72), Pair(-14, 85), Pair(12, 66),
        Pair(9, 90), Pair(-1, 84), Pair(-2, 73), Pair(0, 67), Pair(3, 64), Pair(-3, 66), Pair(-2, 65), Pair(3, 69),
        Pair(0, 109), Pair(5, 78), Pair(1, 80), Pair(5, 69), Pair(-4, 68), Pair(-3, 68), Pair(8, 57), Pair(5, 65),
        Pair(7, 91), Pair(11, 90), Pair(5, 83), Pair(-2, 64), Pair(-3, 60), Pair(-1, 71), Pair(10, 70), Pair(8, 67)
      },
      { // Piece 3
        Pair(31, 123), Pair(-39, 138), Pair(-12, 132), Pair(-31, 135), Pair(-21, 118), Pair(-1, 125), Pair(28, 114), Pair(-27, 130),
        Pair(43, 129), Pair(-8, 123), Pair(-10, 135), Pair(-13, 132), Pair(-8, 132), Pair(-1, 126), Pair(59, 100), Pair(-19, 149),
        Pair(0, 0), Pair(-11, 143), Pair(-9, 143), Pair(7, 131), Pair(-15, 138), Pair(-17, 133), Pair(-17, 137), Pair(-22, 130),
        Pair(-16, 129), Pair(-4, -50), Pair(-18, 122), Pair(-10, 127), Pair(4, 120), Pair(-7, 128), Pair(-1, 114), Pair(-6, 118),
        Pair(-20, 112), Pair(-25, 126), Pair(-24, 119), Pair(-21, 109), Pair(-4, 112), Pair(-9, 112), Pair(8, 100), Pair(-7, 119),
        Pair(-24, 107), Pair(-20, 119), Pair(-23, 122), Pair(-10, 117), Pair(-16, 112), Pair(-10, 114), Pair(-10, 117), Pair(9, 106),
        Pair(-13, 104), Pair(-10, 114), Pair(-13, 116), Pair(-11, 109), Pair(-11, 111), Pair(-4, 111), Pair(0, 109), Pair(27, 101),
        Pair(-16, 108), Pair(-16, 111), Pair(-13, 109), Pair(-13, 112), Pair(-11, 110), Pair(-8, 114), Pair(-1, 115), Pair(-4, 123)
      },
      { // Piece 4
        Pair(-35, 299), Pair(-28, 255), Pair(-21, 279), Pair(-15, 267), Pair(31, 246), Pair(-53, 301), Pair(16, 236), Pair(75, 205),
        Pair(27, 249), Pair(41, 238), Pair(26, 230), Pair(5, 239), Pair(20, 281), Pair(20, 226), Pair(27, 212), Pair(46, 236),
        Pair(0, 0), Pair(44, 227), Pair(-1, 284), Pair(11, 269), Pair(22, 246), Pair(35, 194), Pair(48, 228), Pair(55, 173),
        Pair(39, 203), Pair(59, 65), Pair(41, 191), Pair(21, 226), Pair(8, 247), Pair(35, 235), Pair(39, 210), Pair(43, 204),
        Pair(29, 173), Pair(30, 175), Pair(22, 214), Pair(21, 210), Pair(27, 205), Pair(30, 197), Pair(45, 177), Pair(42, 189),
        Pair(11, 248), Pair(21, 192), Pair(21, 206), Pair(31, 190), Pair(19, 207), Pair(27, 207), Pair(30, 199), Pair(39, 168),
        Pair(20, 192), Pair(28, 181), Pair(22, 192), Pair(23, 184), Pair(28, 187), Pair(29, 178), Pair(27, 194), Pair(37, 183),
        Pair(23, 217), Pair(31, 178), Pair(22, 217), Pair(23, 191), Pair(27, 196), Pair(22, 210), Pair(55, 179), Pair(19, 149)
      },
      { // Piece 5
        Pair(-22, -3), Pair(98, 42), Pair(115, -30), Pair(110, 36), Pair(22, -4), Pair(79, -33), Pair(70, 48), Pair(-55, 31),
        Pair(-20, 9), Pair(-57, -19), Pair(58, 7), Pair(20, 5), Pair(-108, 74), Pair(54, -4), Pair(-55, 6), Pair(-95, 54),
        Pair(0, 0), Pair(-77, -35), Pair(-58, 22), Pair(94, 22), Pair(-17, 9), Pair(87, 7), Pair(-67, 28), Pair(3, 16),
        Pair(-29, -73), Pair(-113, -88), Pair(-147, 17), Pair(60, 3), Pair(-41, 17), Pair(-27, 26), Pair(9, 12), Pair(106, -11),
        Pair(52, -24), Pair(-37, 3), Pair(7, -13), Pair(-7, 6), Pair(30, 7), Pair(28, 8), Pair(41, 4), Pair(18, 9),
        Pair(10, -32), Pair(-4, -6), Pair(-15, 6), Pair(2, 2), Pair(6, 4), Pair(28, 2), Pair(-9, 15), Pair(11, 3),
        Pair(-2, -21), Pair(-12, -3), Pair(-2, 16), Pair(15, 10), Pair(10, 7), Pair(6, 3), Pair(-3, 7), Pair(-3, 11),
        Pair(19, 12), Pair(18, 1), Pair(14, 18), Pair(25, -1), Pair(7, 9), Pair(8, 7), Pair(-2, 1), Pair(2, -1)
      }
    }},
    {{ // Bucket 41
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-14, 29), Pair(-7, 19), Pair(8, 13), Pair(-2, 6), Pair(17, 15), Pair(26, 11), Pair(14, 24), Pair(3, 25),
        Pair(-2, 11), Pair(0, 0), Pair(-2, 3), Pair(5, 1), Pair(-1, 17), Pair(1, 16), Pair(8, 16), Pair(-5, 23),
        Pair(5, 7), Pair(-11, -15), Pair(-11, 26), Pair(0, 5), Pair(2, 8), Pair(-2, 9), Pair(-3, 13), Pair(-2, 13),
        Pair(6, 3), Pair(-6, -5), Pair(3, 12), Pair(-2, 4), Pair(-4, 4), Pair(-5, 8), Pair(-1, 5), Pair(-2, 8),
        Pair(1, 1), Pair(0, 0), Pair(0, 4), Pair(0, 2), Pair(-3, 4), Pair(-8, 3), Pair(-4, 2), Pair(-3, 2),
        Pair(0, -3), Pair(3, 0), Pair(-1, 1), Pair(-1, -1), Pair(-1, 0), Pair(-9, 1), Pair(-8, -3), Pair(-2, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-86, 37), Pair(-13, 32), Pair(-47, 79), Pair(-3, 56), Pair(-12, 89), Pair(93, 56), Pair(58, 16), Pair(-56, 125),
        Pair(5, 51), Pair(-44, -18), Pair(6, 73), Pair(16, 40), Pair(12, 68), Pair(34, 46), Pair(-2, 47), Pair(-3, 71),
        Pair(-19, 25), Pair(0, 0), Pair(-11, 49), Pair(-7, 72), Pair(11, 42), Pair(-12, 76), Pair(23, 32), Pair(20, 51),
        Pair(-40, 35), Pair(-1, 97), Pair(-92, 27), Pair(-6, 69), Pair(-1, 54), Pair(12, 58), Pair(12, 46), Pair(11, 50),
        Pair(-25, 35), Pair(3, 70), Pair(-28, 61), Pair(-4, 60), Pair(-6, 53), Pair(-2, 57), Pair(17, 49), Pair(9, 56),
        Pair(-2, 71), Pair(-24, 9), Pair(-5, 60), Pair(-19, 48), Pair(-7, 58), Pair(-1, 55), Pair(3, 57), Pair(6, 62),
        Pair(12, 46), Pair(-22, 75), Pair(0, 59), Pair(-2, 48), Pair(-2, 59), Pair(1, 51), Pair(3, 69), Pair(13, 73),
        Pair(-22, 37), Pair(1, 61), Pair(-6, 63), Pair(-7, 59), Pair(5, 58), Pair(8, 50), Pair(-1, 85), Pair(-15, 102)
      },
      { // Piece 2
        Pair(-45, 91), Pair(-75, 83), Pair(-198, 114), Pair(-107, 108), Pair(-54, 109), Pair(-115, 125), Pair(-26, 94), Pair(-1, 115),
        Pair(-146, 30), Pair(-38, 90), Pair(-29, 94), Pair(-27, 104), Pair(-45, 91), Pair(22, 99), Pair(5, 79), Pair(15, 83),
        Pair(-5, 85), Pair(0, 0), Pair(-18, 92), Pair(-21, 79), Pair(-3, 91), Pair(-24, 93), Pair(-18, 94), Pair(8, 62),
        Pair(-38, -74), Pair(-10, 110), Pair(-181, 28), Pair(-10, 83), Pair(-18, 88), Pair(-19, 97), Pair(0, 74), Pair(3, 75),
        Pair(-27, 78), Pair(-29, 60), Pair(-28, 86), Pair(-25, 73), Pair(-7, 67), Pair(-10, 65), Pair(-10, 74), Pair(7, 53),
        Pair(-9, 50), Pair(-10, 75), Pair(-20, 72), Pair(-8, 75), Pair(-12, 56), Pair(-6, 70), Pair(2, 59), Pair(3, 67),
        Pair(-1, 110), Pair(2, 54), Pair(-9, 74), Pair(-8, 56), Pair(-10, 70), Pair(-10, 51), Pair(0, 63), Pair(-5, 57),
        Pair(-12, 94), Pair(6, 78), Pair(-2, 64), Pair(-5, 71), Pair(-6, 58), Pair(-3, 66), Pair(3, 49), Pair(10, 62)
      },
      { // Piece 3
        Pair(-26, 106), Pair(-46, 103), Pair(-58, 117), Pair(-33, 110), Pair(4, 89), Pair(-39, 112), Pair(-15, 103), Pair(22, 98),
        Pair(-22, 109), Pair(-27, 118), Pair(-26, 110), Pair(-17, 114), Pair(-12, 109), Pair(52, 78), Pair(-27, 112), Pair(-3, 105),
        Pair(-26, 91), Pair(0, 0), Pair(-15, 112), Pair(-11, 110), Pair(-13, 114), Pair(12, 92), Pair(15, 86), Pair(14, 95),
        Pair(21, -53), Pair(-28, 86), Pair(-62, 9), Pair(-35, 103), Pair(-28, 96), Pair(-14, 87), Pair(8, 95), Pair(-16, 95),
        Pair(-11, 68), Pair(-26, 88), Pair(-39, 92), Pair(-34, 102), Pair(-7, 79), Pair(-19, 102), Pair(-18, 96), Pair(16, 89),
        Pair(-37, 94), Pair(-27, 89), Pair(-25, 91), Pair(-20, 90), Pair(-22, 92), Pair(-13, 88), Pair(-16, 92), Pair(1, 109),
        Pair(-13, 82), Pair(-27, 81), Pair(-21, 90), Pair(-9, 86), Pair(-15, 87), Pair(-18, 102), Pair(-14, 95), Pair(-11, 110),
        Pair(-23, 90), Pair(-22, 82), Pair(-23, 87), Pair(-19, 90), Pair(-18, 88), Pair(-17, 95), Pair(-8, 100), Pair(-8, 104)
      },
      { // Piece 4
        Pair(42, 137), Pair(16, 164), Pair(-12, 193), Pair(11, 172), Pair(8, 187), Pair(5, 166), Pair(-69, 237), Pair(64, 127),
        Pair(23, 123), Pair(9, 185), Pair(20, 161), Pair(22, 164), Pair(33, 164), Pair(46, 136), Pair(26, 154), Pair(12, 156),
        Pair(27, 97), Pair(0, 0), Pair(10, 199), Pair(37, 158), Pair(61, 113), Pair(19, 173), Pair(17, 154), Pair(41, 136),
        Pair(15, 169), Pair(22, 152), Pair(-23, 164), Pair(34, 143), Pair(38, 147), Pair(32, 161), Pair(44, 144), Pair(34, 138),
        Pair(20, 135), Pair(9, 151), Pair(15, 136), Pair(18, 150), Pair(15, 159), Pair(25, 151), Pair(29, 144), Pair(31, 152),
        Pair(18, 146), Pair(22, 145), Pair(15, 138), Pair(17, 147), Pair(34, 130), Pair(17, 144), Pair(30, 155), Pair(33, 162),
        Pair(36, 143), Pair(21, 139), Pair(20, 129), Pair(20, 130), Pair(20, 140), Pair(23, 145), Pair(30, 140), Pair(42, 144),
        Pair(10, 188), Pair(22, 176), Pair(24, 132), Pair(22, 137), Pair(19, 145), Pair(23, 128), Pair(36, 86), Pair(39, 129)
      },
      { // Piece 5
        Pair(35, -313), Pair(-18, -13), Pair(-4, 11), Pair(12, 34), Pair(128, 99), Pair(12, 4), Pair(-30, 90), Pair(110, -127),
        Pair(121, -54), Pair(95, -39), Pair(123, -45), Pair(110, 16), Pair(-289, 67), Pair(42, -24), Pair(-57, 40), Pair(-27, 19),
        Pair(18, -39), Pair(0, 0), Pair(-15, -40), Pair(168, -16), Pair(-92, 25), Pair(42, 7), Pair(-2, 2), Pair(-3, -5),
        Pair(11, 20), Pair(82, -110), Pair(12, 55), Pair(-36, -5), Pair(-53, 7), Pair(33, 10), Pair(24, 4), Pair(34, -6),
        Pair(156, -81), Pair(-17, -52), Pair(46, -29), Pair(-29, -16), Pair(32, -8), Pair(13, -1), Pair(6, 6), Pair(-1, 2),
        Pair(71, -34), Pair(40, -48), Pair(-28, -10), Pair(-2, -8), Pair(-7, -2), Pair(-5, 2), Pair(11, -2), Pair(35, -9),
        Pair(-14, -10), Pair(7, -26), Pair(14, -15), Pair(7, 1), Pair(13, -2), Pair(8, -4), Pair(-3, -2), Pair(-2, 0),
        Pair(45, -44), Pair(17, -11), Pair(33, -13), Pair(40, -4), Pair(7, 7), Pair(25, -10), Pair(0, -3), Pair(-3, -9)
      }
    }},
    {{ // Bucket 42
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-23, 39), Pair(-10, 18), Pair(-30, 18), Pair(-16, 0), Pair(17, 14), Pair(34, 3), Pair(-10, 18), Pair(2, 20),
        Pair(1, 12), Pair(-11, 7), Pair(0, 0), Pair(4, -3), Pair(8, 10), Pair(6, 8), Pair(12, 17), Pair(-14, 17),
        Pair(-3, 0), Pair(-1, 3), Pair(-12, -16), Pair(1, 39), Pair(-1, 5), Pair(0, 8), Pair(4, 4), Pair(1, 11),
        Pair(2, 0), Pair(4, -5), Pair(-2, -6), Pair(0, 6), Pair(-1, 4), Pair(0, 6), Pair(1, 2), Pair(-1, 7),
        Pair(3, 1), Pair(-1, -5), Pair(0, 0), Pair(3, 5), Pair(-1, 3), Pair(-6, 4), Pair(1, 2), Pair(-2, 1),
        Pair(0, 0), Pair(-4, -9), Pair(3, 1), Pair(0, 2), Pair(4, -5), Pair(-5, 0), Pair(0, 0), Pair(-2, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-4, 96), Pair(74, 41), Pair(44, 43), Pair(-56, 69), Pair(62, -14), Pair(160, -16), Pair(168, 67), Pair(81, -29),
        Pair(-69, -3), Pair(20, 62), Pair(14, -1), Pair(4, 79), Pair(13, -2), Pair(10, 55), Pair(35, 36), Pair(40, 45),
        Pair(21, 65), Pair(-7, 47), Pair(0, 0), Pair(6, 61), Pair(3, 63), Pair(15, 58), Pair(11, 39), Pair(-5, 50),
        Pair(7, 67), Pair(-10, -23), Pair(10, 102), Pair(-73, 6), Pair(11, 57), Pair(8, 46), Pair(18, 50), Pair(28, 39),
        Pair(10, 54), Pair(-21, 45), Pair(2, 64), Pair(-25, 56), Pair(6, 62), Pair(0, 35), Pair(7, 52), Pair(13, 54),
        Pair(-11, 41), Pair(0, 70), Pair(-13, 28), Pair(4, 61), Pair(-11, 39), Pair(7, 61), Pair(10, 47), Pair(8, 64),
        Pair(1, 70), Pair(4, 81), Pair(5, 52), Pair(5, 63), Pair(9, 46), Pair(9, 44), Pair(1, 62), Pair(23, 44),
        Pair(70, 59), Pair(6, 49), Pair(18, 22), Pair(8, 43), Pair(8, 54), Pair(17, 43), Pair(14, 56), Pair(26, 61)
      },
      { // Piece 2
        Pair(-141, -53), Pair(1, 60), Pair(46, 77), Pair(-76, 92), Pair(-10, 0), Pair(-22, 93), Pair(94, 26), Pair(31, 48),
        Pair(14, 60), Pair(-123, 48), Pair(-1, 84), Pair(-6, 57), Pair(9, 75), Pair(-9, 77), Pair(-6, 74), Pair(-3, 42),
        Pair(-12, 53), Pair(-7, 70), Pair(0, 0), Pair(2, 64), Pair(-3, 64), Pair(9, 71), Pair(7, 73), Pair(17, 58),
        Pair(9, 58), Pair(-33, -56), Pair(15, 95), Pair(-84, -35), Pair(7, 60), Pair(-7, 70), Pair(10, 66), Pair(4, 46),
        Pair(-22, 31), Pair(-17, 61), Pair(-12, 42), Pair(-27, 69), Pair(-6, 42), Pair(3, 70), Pair(-12, 64), Pair(12, 70),
        Pair(9, 51), Pair(-8, 53), Pair(7, 65), Pair(0, 42), Pair(6, 60), Pair(-4, 37), Pair(15, 47), Pair(3, 42),
        Pair(-19, 61), Pair(16, 50), Pair(2, 58), Pair(15, 56), Pair(-1, 39), Pair(13, 56), Pair(-3, 24), Pair(12, 76),
        Pair(21, 62), Pair(25, 54), Pair(16, 69), Pair(-2, 55), Pair(3, 62), Pair(3, 40), Pair(7, 61), Pair(-14, 48)
      },
      { // Piece 3
        Pair(1, 72), Pair(25, 61), Pair(-19, 82), Pair(14, 74), Pair(23, 64), Pair(22, 75), Pair(-80, 109), Pair(-20, 86),
        Pair(5, 80), Pair(1, 75), Pair(16, 79), Pair(-20, 84), Pair(28, 72), Pair(34, 74), Pair(19, 72), Pair(20, 60),
        Pair(0, 77), Pair(-17, 70), Pair(0, 0), Pair(16, 64), Pair(2, 87), Pair(6, 81), Pair(-7, 87), Pair(-1, 70),
        Pair(0, 63), Pair(-16, -8), Pair(8, 66), Pair(-16, -24), Pair(-14, 83), Pair(2, 67), Pair(22, 56), Pair(-3, 70),
        Pair(-1, 67), Pair(-14, 75), Pair(-15, 62), Pair(-15, 62), Pair(-1, 72), Pair(-3, 78), Pair(29, 48), Pair(10, 65),
        Pair(0, 67), Pair(-12, 62), Pair(-13, 69), Pair(-8, 71), Pair(-15, 78), Pair(0, 71), Pair(-8, 66), Pair(7, 86),
        Pair(1, 76), Pair(3, 60), Pair(-8, 67), Pair(-7, 68), Pair(-8, 76), Pair(0, 68), Pair(9, 64), Pair(7, 61),
        Pair(-3, 65), Pair(-6, 66), Pair(-5, 63), Pair(-7, 61), Pair(-2, 69), Pair(-1, 67), Pair(10, 59), Pair(8, 75)
      },
      { // Piece 4
        Pair(28, 120), Pair(13, 158), Pair(103, 70), Pair(-37, 207), Pair(30, 145), Pair(46, 135), Pair(74, 132), Pair(62, 126),
        Pair(20, 165), Pair(4, 130), Pair(18, 159), Pair(15, 136), Pair(18, 180), Pair(5, 165), Pair(31, 155), Pair(-10, 160),
        Pair(17, 120), Pair(7, 154), Pair(0, 0), Pair(42, 119), Pair(32, 160), Pair(19, 112), Pair(15, 184), Pair(37, 116),
        Pair(24, 130), Pair(-46, 187), Pair(51, 111), Pair(-32, 199), Pair(25, 139), Pair(25, 160), Pair(32, 125), Pair(24, 148),
        Pair(24, 117), Pair(16, 130), Pair(24, 113), Pair(15, 128), Pair(31, 105), Pair(27, 129), Pair(29, 120), Pair(30, 154),
        Pair(15, 144), Pair(15, 126), Pair(31, 114), Pair(18, 130), Pair(26, 112), Pair(20, 126), Pair(29, 121), Pair(21, 117),
        Pair(20, 119), Pair(26, 123), Pair(28, 126), Pair(20, 120), Pair(21, 120), Pair(18, 142), Pair(26, 93), Pair(37, 126),
        Pair(20, 139), Pair(22, 128), Pair(31, 109), Pair(22, 120), Pair(15, 153), Pair(27, 126), Pair(23, 126), Pair(23, 94)
      },
      { // Piece 5
        Pair(-8, 55), Pair(8, 19), Pair(-140, -37), Pair(37, -55), Pair(35, 36), Pair(0, 106), Pair(-1, 22), Pair(121, -60),
        Pair(83, -82), Pair(109, -64), Pair(91, -36), Pair(104, -30), Pair(3, 30), Pair(54, 27), Pair(61, 2), Pair(-82, 92),
        Pair(-128, -3), Pair(-30, -32), Pair(0, 0), Pair(167, -69), Pair(93, 10), Pair(49, 13), Pair(-77, 29), Pair(-71, 37),
        Pair(25, -4), Pair(4, 46), Pair(9, -65), Pair(-4, -25), Pair(-107, 13), Pair(-4, 18), Pair(63, 11), Pair(111, 8),
        Pair(22, -30), Pair(38, -22), Pair(23, -40), Pair(77, -32), Pair(-15, -5), Pair(21, 12), Pair(20, 9), Pair(17, 19),
        Pair(106, -12), Pair(-9, -1), Pair(-42, -4), Pair(10, -5), Pair(2, 7), Pair(-4, 13), Pair(0, 11), Pair(26, -5),
        Pair(-34, 14), Pair(3, -17), Pair(-4, -1), Pair(-2, -1), Pair(3, 13), Pair(1, 17), Pair(1, 11), Pair(3, 10),
        Pair(21, 11), Pair(-2, -8), Pair(-5, 13), Pair(12, 4), Pair(-3, 27), Pair(8, 12), Pair(-1, 11), Pair(7, 7)
      }
    }},
    {{ // Bucket 43
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-8, 23), Pair(19, 17), Pair(7, 10), Pair(25, -19), Pair(-34, 45), Pair(-48, 26), Pair(12, 15), Pair(-4, 23),
        Pair(-1, 13), Pair(3, 7), Pair(-9, 6), Pair(0, 0), Pair(-7, 2), Pair(-1, 5), Pair(6, 6), Pair(-10, 20),
        Pair(-4, 4), Pair(-5, 3), Pair(-2, -3), Pair(-13, -14), Pair(-8, 14), Pair(-2, 4), Pair(6, 4), Pair(2, 7),
        Pair(0, 2), Pair(-1, -3), Pair(3, -1), Pair(-7, -7), Pair(-2, 2), Pair(-2, 4), Pair(2, 3), Pair(-1, 6),
        Pair(1, -3), Pair(0, -1), Pair(-3, -5), Pair(0, 0), Pair(-2, -1), Pair(-4, 1), Pair(-2, 2), Pair(-1, 4),
        Pair(1, -3), Pair(-3, -5), Pair(-7, -8), Pair(0, 1), Pair(0, -3), Pair(-1, 0), Pair(-1, -2), Pair(-2, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-89, 82), Pair(59, 32), Pair(-74, 57), Pair(-74, 81), Pair(27, 70), Pair(-84, 110), Pair(-124, 113), Pair(5, -43),
        Pair(-28, 70), Pair(-41, 16), Pair(-4, 60), Pair(9, -17), Pair(-46, 82), Pair(-4, 42), Pair(-39, 42), Pair(-15, 61),
        Pair(18, 45), Pair(-8, 58), Pair(-46, 67), Pair(0, 0), Pair(-10, 53), Pair(-27, 75), Pair(-9, 37), Pair(-2, 53),
        Pair(-17, 54), Pair(-1, 53), Pair(-89, -1), Pair(-12, 100), Pair(-94, 33), Pair(-14, 70), Pair(-11, 56), Pair(3, 40),
        Pair(-16, 26), Pair(3, 33), Pair(-34, 35), Pair(-12, 66), Pair(-21, 40), Pair(-8, 56), Pair(-20, 38), Pair(-7, 59),
        Pair(-1, 49), Pair(-13, 19), Pair(-6, 49), Pair(-34, 36), Pair(-18, 62), Pair(-20, 29), Pair(-4, 52), Pair(-5, 65),
        Pair(3, 19), Pair(-24, 50), Pair(-4, 45), Pair(-9, 40), Pair(-3, 55), Pair(-9, 42), Pair(0, 57), Pair(2, 45),
        Pair(7, 66), Pair(3, 35), Pair(9, 47), Pair(-4, 59), Pair(-10, 52), Pair(0, 44), Pair(-4, 54), Pair(-39, 192)
      },
      { // Piece 2
        Pair(-55, 54), Pair(-89, -11), Pair(-49, 85), Pair(-6, 50), Pair(-110, 91), Pair(-68, 66), Pair(-8, 48), Pair(30, 24),
        Pair(-19, 34), Pair(0, 77), Pair(-44, 22), Pair(-74, 97), Pair(-48, 36), Pair(-42, 75), Pair(-30, 57), Pair(4, 48),
        Pair(-11, 83), Pair(-41, 55), Pair(-21, 81), Pair(0, 0), Pair(-21, 67), Pair(-16, 53), Pair(-19, 78), Pair(2, 51),
        Pair(-12, 40), Pair(-22, 64), Pair(-149, -91), Pair(-1, 94), Pair(-95, -87), Pair(-12, 70), Pair(-15, 49), Pair(-16, 76),
        Pair(-25, 64), Pair(-15, 31), Pair(-27, 54), Pair(-18, 34), Pair(-23, 49), Pair(-17, 20), Pair(-15, 58), Pair(-10, 36),
        Pair(-16, 34), Pair(-12, 50), Pair(-19, 43), Pair(-11, 58), Pair(-12, 42), Pair(-13, 55), Pair(-20, 15), Pair(-10, 67),
        Pair(-16, 46), Pair(-8, 22), Pair(-11, 55), Pair(-5, 37), Pair(-11, 53), Pair(-7, 39), Pair(-6, 39), Pair(-12, -4),
        Pair(-26, 41), Pair(1, 58), Pair(-2, 35), Pair(-9, 59), Pair(-16, 43), Pair(-1, 51), Pair(-26, 36), Pair(-12, 51)
      },
      { // Piece 3
        Pair(-32, 69), Pair(-10, 57), Pair(15, 52), Pair(32, 54), Pair(-27, 66), Pair(-34, 82), Pair(-1, 59), Pair(1, 62),
        Pair(-6, 59), Pair(-8, 62), Pair(-12, 48), Pair(-63, 88), Pair(-37, 73), Pair(38, 51), Pair(-9, 59), Pair(-11, 57),
        Pair(-23, 53), Pair(-35, 68), Pair(-3, 58), Pair(0, 0), Pair(5, 45), Pair(15, 46), Pair(-2, 56), Pair(21, 39),
        Pair(-6, 39), Pair(-22, 44), Pair(35, -119), Pair(-3, 46), Pair(-154, 112), Pair(-22, 57), Pair(6, 40), Pair(-9, 43),
        Pair(-14, 58), Pair(-12, 59), Pair(-24, 56), Pair(-14, 42), Pair(-25, 57), Pair(-24, 58), Pair(-11, 56), Pair(13, 47),
        Pair(-4, 56), Pair(-13, 48), Pair(-19, 47), Pair(-12, 49), Pair(-23, 57), Pair(0, 41), Pair(-1, 35), Pair(-13, 81),
        Pair(3, 38), Pair(-9, 56), Pair(-4, 40), Pair(-13, 45), Pair(-10, 41), Pair(3, 41), Pair(3, 52), Pair(24, 55),
        Pair(-10, 53), Pair(-10, 54), Pair(-12, 46), Pair(-15, 49), Pair(-11, 44), Pair(-6, 47), Pair(-11, 51), Pair(4, 47)
      },
      { // Piece 4
        Pair(13, 104), Pair(65, 37), Pair(-18, 135), Pair(-32, 153), Pair(27, 98), Pair(-100, 210), Pair(11, 114), Pair(14, 76),
        Pair(38, 92), Pair(18, 107), Pair(2, 92), Pair(1, 103), Pair(-18, 108), Pair(37, 93), Pair(33, 133), Pair(-4, 141),
        Pair(2, 112), Pair(15, 84), Pair(-19, 126), Pair(0, 0), Pair(20, 102), Pair(7, 151), Pair(0, 131), Pair(31, 101),
        Pair(17, 80), Pair(21, 82), Pair(83, -36), Pair(26, 91), Pair(-26, -15), Pair(10, 122), Pair(18, 117), Pair(14, 112),
        Pair(9, 115), Pair(17, 83), Pair(8, 98), Pair(17, 87), Pair(7, 93), Pair(15, 81), Pair(4, 125), Pair(21, 106),
        Pair(6, 107), Pair(5, 106), Pair(12, 74), Pair(16, 97), Pair(10, 88), Pair(8, 87), Pair(10, 106), Pair(5, 126),
        Pair(18, 89), Pair(7, 110), Pair(12, 75), Pair(12, 104), Pair(12, 73), Pair(11, 81), Pair(6, 119), Pair(56, 23),
        Pair(15, 94), Pair(17, 91), Pair(10, 116), Pair(18, 92), Pair(13, 98), Pair(12, 106), Pair(37, 57), Pair(45, 41)
      },
      { // Piece 5
        Pair(37, -4), Pair(-106, -49), Pair(-21, -144), Pair(57, -35), Pair(66, -37), Pair(-13, 8), Pair(-9, -48), Pair(18, -99),
        Pair(26, 49), Pair(-20, -13), Pair(252, -52), Pair(-110, -45), Pair(-17, 16), Pair(45, 47), Pair(140, 4), Pair(125, -27),
        Pair(36, 25), Pair(-70, 5), Pair(110, -98), Pair(0, 0), Pair(168, -100), Pair(73, -8), Pair(-21, 20), Pair(75, 18),
        Pair(35, 18), Pair(12, 0), Pair(-15, -101), Pair(72, -91), Pair(14, 41), Pair(-49, 26), Pair(61, 7), Pair(92, -8),
        Pair(-7, 9), Pair(25, -12), Pair(82, -47), Pair(46, -57), Pair(101, -45), Pair(50, -17), Pair(-21, 15), Pair(-27, 14),
        Pair(-16, -7), Pair(-20, 6), Pair(-9, -4), Pair(-9, -18), Pair(-2, -7), Pair(8, 5), Pair(13, 2), Pair(29, 2),
        Pair(-12, 19), Pair(3, 1), Pair(-20, 6), Pair(-3, -11), Pair(5, -6), Pair(6, 13), Pair(1, 14), Pair(10, 16),
        Pair(-26, 58), Pair(-13, 32), Pair(-8, 12), Pair(12, -8), Pair(3, 2), Pair(14, 9), Pair(-1, 20), Pair(1, 12)
      }
    }},
    {{ // Bucket 44
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-13, 17), Pair(5, 18), Pair(8, 7), Pair(-20, 22), Pair(7, 4), Pair(8, 19), Pair(-18, 29), Pair(19, 13),
        Pair(6, 6), Pair(1, 7), Pair(6, -2), Pair(-8, 5), Pair(0, 0), Pair(4, 9), Pair(-3, 11), Pair(-8, 9),
        Pair(3, 1), Pair(1, 2), Pair(6, -2), Pair(0, 35), Pair(-8, -5), Pair(5, -5), Pair(0, 6), Pair(-3, 11),
        Pair(5, -3), Pair(4, 0), Pair(4, 1), Pair(5, 5), Pair(0, -1), Pair(-3, 2), Pair(0, 4), Pair(-1, 5),
        Pair(5, 0), Pair(4, -1), Pair(0, -1), Pair(4, -1), Pair(0, 0), Pair(-1, 2), Pair(-3, 5), Pair(-4, 2),
        Pair(3, -1), Pair(3, -1), Pair(1, -3), Pair(3, -4), Pair(4, 0), Pair(0, -3), Pair(-6, 1), Pair(-1, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-22, 9), Pair(-5, 35), Pair(27, 38), Pair(-87, 57), Pair(38, 40), Pair(4, 57), Pair(-189, 84), Pair(-21, 61),
        Pair(-14, 69), Pair(1, 53), Pair(-39, 35), Pair(-49, 76), Pair(-48, 15), Pair(-38, 53), Pair(-43, -3), Pair(-28, 93),
        Pair(4, 29), Pair(-19, 31), Pair(-10, 58), Pair(-27, 54), Pair(0, 0), Pair(1, 42), Pair(-25, 52), Pair(-19, 27),
        Pair(14, 43), Pair(-11, 38), Pair(-3, 45), Pair(-107, 12), Pair(-7, 84), Pair(-45, 1), Pair(-1, 39), Pair(-3, 30),
        Pair(-5, 45), Pair(-31, 46), Pair(-10, 50), Pair(-35, 33), Pair(-12, 55), Pair(-30, 18), Pair(-14, 64), Pair(-12, 27),
        Pair(-8, 46), Pair(-10, 47), Pair(-20, 27), Pair(-15, 51), Pair(-36, 17), Pair(-9, 46), Pair(-25, 33), Pair(-3, 53),
        Pair(-14, 49), Pair(-17, 57), Pair(-3, 32), Pair(-7, 52), Pair(-12, 36), Pair(-9, 47), Pair(-9, 50), Pair(-3, 59),
        Pair(-9, 52), Pair(0, 49), Pair(-13, 39), Pair(1, 34), Pair(-2, 51), Pair(6, 38), Pair(-2, 46), Pair(20, 15)
      },
      { // Piece 2
        Pair(-43, 51), Pair(-82, 76), Pair(-78, 68), Pair(-54, 83), Pair(17, 48), Pair(-108, 88), Pair(-66, -22), Pair(1, 89),
        Pair(-13, 54), Pair(-36, 49), Pair(17, 58), Pair(-59, 48), Pair(-17, 70), Pair(1, 16), Pair(-6, 70), Pair(-40, 46),
        Pair(-24, 33), Pair(-9, 65), Pair(-43, 47), Pair(-22, 67), Pair(0, 0), Pair(-37, 79), Pair(-35, 47), Pair(5, 56),
        Pair(2, 53), Pair(-27, 44), Pair(-3, 58), Pair(-204, -43), Pair(0, 90), Pair(-159, -13), Pair(-9, 49), Pair(-23, 38),
        Pair(-25, 42), Pair(0, 49), Pair(-32, 23), Pair(-36, 48), Pair(-35, 30), Pair(-14, 42), Pair(-32, 31), Pair(-8, 51),
        Pair(1, 64), Pair(-26, 24), Pair(-4, 42), Pair(-21, 35), Pair(-5, 48), Pair(-29, 30), Pair(-17, 55), Pair(-35, 8),
        Pair(-39, 35), Pair(-1, 44), Pair(-18, 41), Pair(1, 53), Pair(-21, 36), Pair(-9, 55), Pair(-32, 27), Pair(-6, 39),
        Pair(-2, 46), Pair(-17, 35), Pair(4, 61), Pair(-25, 34), Pair(-10, 53), Pair(-18, 36), Pair(-15, 61), Pair(-32, 47)
      },
      { // Piece 3
        Pair(-11, 59), Pair(-8, 50), Pair(-9, 57), Pair(-38, 65), Pair(32, 43), Pair(42, 22), Pair(-41, 57), Pair(10, 50),
        Pair(4, 49), Pair(-5, 63), Pair(3, 60), Pair(-22, 61), Pair(6, 64), Pair(-23, 40), Pair(-3, 53), Pair(2, 50),
        Pair(-8, 50), Pair(-12, 53), Pair(2, 52), Pair(-17, 49), Pair(0, 0), Pair(-6, 57), Pair(-15, 51), Pair(23, 33),
        Pair(-1, 46), Pair(-14, 54), Pair(-7, 51), Pair(-2, -55), Pair(5, 29), Pair(-3, -106), Pair(-17, 48), Pair(-14, 51),
        Pair(-5, 52), Pair(-14, 55), Pair(-5, 44), Pair(-17, 41), Pair(-9, 38), Pair(-16, 38), Pair(-22, 37), Pair(9, 31),
        Pair(-12, 49), Pair(-7, 48), Pair(-10, 55), Pair(-9, 35), Pair(-16, 43), Pair(-9, 42), Pair(-9, 59), Pair(2, 49),
        Pair(-7, 57), Pair(5, 37), Pair(-7, 47), Pair(-15, 41), Pair(-12, 46), Pair(-3, 43), Pair(1, 37), Pair(11, 40),
        Pair(-6, 47), Pair(-7, 48), Pair(-4, 49), Pair(-13, 41), Pair(-7, 38), Pair(-9, 48), Pair(-11, 43), Pair(0, 48)
      },
      { // Piece 4
        Pair(-5, 104), Pair(-6, 137), Pair(9, 69), Pair(17, 125), Pair(19, 101), Pair(56, 98), Pair(95, 57), Pair(19, 115),
        Pair(27, 117), Pair(12, 121), Pair(42, 110), Pair(-4, 94), Pair(4, 93), Pair(-4, 82), Pair(22, 120), Pair(29, 104),
        Pair(23, 94), Pair(15, 95), Pair(23, 68), Pair(5, 81), Pair(0, 0), Pair(19, 99), Pair(4, 99), Pair(45, 54),
        Pair(28, 89), Pair(36, 76), Pair(21, 95), Pair(-67, -34), Pair(35, 72), Pair(107, 1), Pair(26, 95), Pair(30, 99),
        Pair(22, 91), Pair(10, 115), Pair(16, 103), Pair(15, 91), Pair(30, 62), Pair(20, 86), Pair(14, 90), Pair(26, 89),
        Pair(21, 109), Pair(19, 85), Pair(11, 98), Pair(15, 87), Pair(22, 93), Pair(19, 75), Pair(23, 66), Pair(23, 45),
        Pair(22, 73), Pair(11, 107), Pair(13, 92), Pair(11, 92), Pair(25, 87), Pair(12, 117), Pair(-2, 127), Pair(19, 106),
        Pair(9, 115), Pair(19, 88), Pair(17, 106), Pair(17, 84), Pair(23, 96), Pair(22, 68), Pair(-13, 137), Pair(5, 113)
      },
      { // Piece 5
        Pair(-19, 46), Pair(38, -31), Pair(114, -12), Pair(107, -33), Pair(107, -62), Pair(-50, -7), Pair(-126, -4), Pair(-31, -15),
        Pair(153, 58), Pair(121, 25), Pair(-25, 17), Pair(18, -5), Pair(118, -57), Pair(138, -66), Pair(-29, -27), Pair(-186, 97),
        Pair(16, 12), Pair(175, 6), Pair(112, -7), Pair(42, -66), Pair(0, 0), Pair(94, -72), Pair(28, 0), Pair(75, -3),
        Pair(109, -5), Pair(143, -3), Pair(-7, 6), Pair(7, 105), Pair(32, -73), Pair(5, -50), Pair(16, -2), Pair(42, 6),
        Pair(50, 15), Pair(8, 4), Pair(-17, 5), Pair(51, -34), Pair(40, -38), Pair(83, -35), Pair(22, -5), Pair(-15, 16),
        Pair(67, 7), Pair(36, -4), Pair(5, 8), Pair(9, -2), Pair(5, -17), Pair(8, -4), Pair(2, 15), Pair(26, 0),
        Pair(4, 4), Pair(-5, 16), Pair(11, 22), Pair(-7, 8), Pair(8, -1), Pair(15, 0), Pair(2, 16), Pair(5, 13),
        Pair(-7, 28), Pair(-7, 17), Pair(-2, 32), Pair(20, 7), Pair(-3, 21), Pair(23, 2), Pair(-1, 21), Pair(-5, 25)
      }
    }},
    {{ // Bucket 45
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-21, 24), Pair(-2, 19), Pair(7, 14), Pair(-15, 15), Pair(-16, 21), Pair(-13, -53), Pair(-25, 14), Pair(-1, 18),
        Pair(9, 5), Pair(7, 8), Pair(17, 3), Pair(8, -1), Pair(1, 2), Pair(0, 0), Pair(12, 3), Pair(2, 2),
        Pair(6, -1), Pair(6, 1), Pair(11, 2), Pair(3, -2), Pair(7, 27), Pair(-13, -3), Pair(2, 0), Pair(2, 1),
        Pair(5, -2), Pair(5, -2), Pair(7, -1), Pair(4, 2), Pair(3, 1), Pair(0, -2), Pair(2, -1), Pair(4, 2),
        Pair(6, -1), Pair(8, -3), Pair(6, -3), Pair(4, 1), Pair(3, 1), Pair(0, 0), Pair(-4, -5), Pair(-2, -1),
        Pair(4, -4), Pair(6, -3), Pair(7, -3), Pair(3, 2), Pair(2, -1), Pair(8, -4), Pair(1, -9), Pair(-2, -1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(47, 50), Pair(7, 67), Pair(33, 58), Pair(-14, 51), Pair(80, 50), Pair(126, 38), Pair(-244, 90), Pair(-14, 96),
        Pair(-7, 72), Pair(35, 53), Pair(68, 40), Pair(-13, 19), Pair(22, 34), Pair(-34, 54), Pair(35, 52), Pair(-49, 32),
        Pair(-6, 70), Pair(44, 45), Pair(10, 46), Pair(36, 53), Pair(27, 41), Pair(0, 0), Pair(19, 24), Pair(12, 50),
        Pair(34, 43), Pair(26, 56), Pair(29, 36), Pair(31, 37), Pair(-39, -10), Pair(50, 80), Pair(-16, -41), Pair(37, 28),
        Pair(21, 40), Pair(33, 43), Pair(17, 39), Pair(27, 48), Pair(-4, 47), Pair(15, 59), Pair(6, 16), Pair(25, 46),
        Pair(25, 57), Pair(23, 55), Pair(24, 45), Pair(8, 35), Pair(17, 48), Pair(2, 21), Pair(14, 67), Pair(0, 28),
        Pair(8, 55), Pair(4, 80), Pair(27, 44), Pair(19, 40), Pair(22, 53), Pair(3, 51), Pair(29, 68), Pair(12, 36),
        Pair(53, 15), Pair(30, 67), Pair(34, 32), Pair(22, 36), Pair(11, 55), Pair(40, 34), Pair(7, 67), Pair(-16, 30)
      },
      { // Piece 2
        Pair(6, 68), Pair(30, 31), Pair(14, 77), Pair(-20, 44), Pair(20, 65), Pair(-47, 68), Pair(10, 70), Pair(-188, -33),
        Pair(-17, 67), Pair(3, 63), Pair(-3, 61), Pair(27, 76), Pair(-7, 51), Pair(10, 66), Pair(-25, -7), Pair(-1, 97),
        Pair(38, 50), Pair(1, 68), Pair(22, 59), Pair(2, 49), Pair(34, 62), Pair(0, 0), Pair(4, 62), Pair(4, 39),
        Pair(13, 37), Pair(19, 58), Pair(9, 58), Pair(18, 57), Pair(-89, -9), Pair(40, 88), Pair(-36, -46), Pair(24, 44),
        Pair(25, 63), Pair(-1, 61), Pair(30, 51), Pair(-1, 37), Pair(-17, 50), Pair(8, 27), Pair(4, 64), Pair(7, 13),
        Pair(14, 53), Pair(25, 58), Pair(6, 31), Pair(22, 44), Pair(8, 34), Pair(25, 52), Pair(-9, 40), Pair(25, 45),
        Pair(22, 63), Pair(12, 27), Pair(18, 54), Pair(10, 33), Pair(24, 45), Pair(13, 48), Pair(24, 38), Pair(-11, 33),
        Pair(-7, 31), Pair(42, 48), Pair(12, 39), Pair(16, 52), Pair(18, 31), Pair(29, 52), Pair(30, 41), Pair(25, 64)
      },
      { // Piece 3
        Pair(35, 57), Pair(24, 61), Pair(9, 69), Pair(11, 71), Pair(30, 48), Pair(58, 27), Pair(37, 52), Pair(-13, 67),
        Pair(50, 50), Pair(25, 57), Pair(55, 43), Pair(22, 61), Pair(24, 58), Pair(49, 78), Pair(-2, 64), Pair(41, 50),
        Pair(39, 49), Pair(32, 52), Pair(24, 52), Pair(53, 47), Pair(13, 66), Pair(0, 0), Pair(37, 38), Pair(-19, 64),
        Pair(30, 47), Pair(15, 53), Pair(40, 50), Pair(2, 65), Pair(7, -28), Pair(25, 43), Pair(67, -38), Pair(-5, 51),
        Pair(37, 48), Pair(23, 47), Pair(26, 55), Pair(8, 57), Pair(11, 45), Pair(19, 50), Pair(19, 64), Pair(27, 53),
        Pair(32, 62), Pair(30, 48), Pair(10, 58), Pair(28, 55), Pair(17, 47), Pair(30, 40), Pair(39, 43), Pair(14, 71),
        Pair(39, 52), Pair(40, 57), Pair(28, 61), Pair(36, 45), Pair(30, 35), Pair(38, 37), Pair(22, 51), Pair(11, 65),
        Pair(30, 60), Pair(29, 58), Pair(27, 55), Pair(26, 52), Pair(25, 48), Pair(25, 54), Pair(27, 41), Pair(16, 67)
      },
      { // Piece 4
        Pair(-9, 115), Pair(7, 112), Pair(11, 135), Pair(106, 51), Pair(35, 102), Pair(18, 96), Pair(24, 190), Pair(70, 67),
        Pair(47, 94), Pair(44, 102), Pair(42, 115), Pair(46, 123), Pair(33, 101), Pair(36, 110), Pair(73, 66), Pair(50, 131),
        Pair(41, 105), Pair(23, 116), Pair(48, 88), Pair(26, 86), Pair(44, 55), Pair(0, 0), Pair(54, 60), Pair(44, 74),
        Pair(55, 85), Pair(48, 109), Pair(31, 108), Pair(40, 94), Pair(52, -56), Pair(83, 28), Pair(15, 47), Pair(51, 90),
        Pair(53, 61), Pair(30, 125), Pair(46, 85), Pair(32, 97), Pair(43, 77), Pair(51, 72), Pair(47, 116), Pair(56, 91),
        Pair(46, 66), Pair(30, 101), Pair(33, 108), Pair(34, 107), Pair(39, 96), Pair(51, 80), Pair(56, 75), Pair(44, 81),
        Pair(45, 83), Pair(45, 86), Pair(42, 70), Pair(36, 101), Pair(36, 94), Pair(44, 94), Pair(42, 117), Pair(72, 38),
        Pair(41, 61), Pair(40, 77), Pair(36, 97), Pair(39, 93), Pair(49, 79), Pair(42, 83), Pair(1, 131), Pair(78, 84)
      },
      { // Piece 5
        Pair(-65, 13), Pair(-98, -35), Pair(-36, -26), Pair(103, 17), Pair(67, 0), Pair(-4, -95), Pair(-72, 17), Pair(24, -124),
        Pair(-38, 17), Pair(-56, -5), Pair(-161, 38), Pair(-73, 8), Pair(8, -18), Pair(190, -76), Pair(-22, -14), Pair(64, -16),
        Pair(77, 7), Pair(126, -3), Pair(107, -14), Pair(-47, 11), Pair(-39, -62), Pair(0, 0), Pair(66, -51), Pair(90, -18),
        Pair(46, 17), Pair(113, -3), Pair(23, 10), Pair(1, -8), Pair(-228, -220), Pair(-63, -52), Pair(-36, -60), Pair(15, -10),
        Pair(60, -5), Pair(113, -4), Pair(7, 2), Pair(46, -15), Pair(34, -22), Pair(52, -32), Pair(33, -17), Pair(-16, -5),
        Pair(96, -27), Pair(47, -8), Pair(45, -8), Pair(20, 2), Pair(37, -12), Pair(-3, -6), Pair(27, -7), Pair(32, -1),
        Pair(6, 5), Pair(28, -1), Pair(28, 12), Pair(13, 7), Pair(16, -1), Pair(30, -9), Pair(2, 2), Pair(12, 13),
        Pair(-12, 12), Pair(-4, 4), Pair(1, 15), Pair(28, 13), Pair(1, 14), Pair(8, 13), Pair(-4, 8), Pair(16, 8)
      }
    }},
    {{ // Bucket 46
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(37, 16), Pair(29, 10), Pair(39, 3), Pair(15, 13), Pair(10, 8), Pair(-22, 12), Pair(-8, -4), Pair(-23, 24),
        Pair(3, 9), Pair(12, 9), Pair(6, 9), Pair(1, 7), Pair(4, 3), Pair(-11, 7), Pair(0, 0), Pair(2, 7),
        Pair(3, 9), Pair(7, 2), Pair(10, 3), Pair(0, 3), Pair(0, 0), Pair(7, 21), Pair(-6, -6), Pair(25, 14),
        Pair(3, 2), Pair(6, -5), Pair(2, 0), Pair(0, 1), Pair(1, 1), Pair(4, 4), Pair(5, -2), Pair(7, 5),
        Pair(4, -4), Pair(4, -1), Pair(2, 0), Pair(2, 0), Pair(4, -1), Pair(2, 4), Pair(0, 0), Pair(1, 4),
        Pair(3, -2), Pair(4, -4), Pair(-2, -3), Pair(1, -3), Pair(2, -3), Pair(6, 2), Pair(0, -5), Pair(-3, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-24, 66), Pair(-121, 106), Pair(-16, 43), Pair(-86, 75), Pair(13, 56), Pair(-72, 103), Pair(-134, 44), Pair(68, 15),
        Pair(7, 46), Pair(20, 46), Pair(22, 47), Pair(-11, 55), Pair(10, 0), Pair(11, 51), Pair(-72, 2), Pair(10, 73),
        Pair(-11, 48), Pair(26, 43), Pair(11, 53), Pair(-5, 46), Pair(16, 61), Pair(19, 53), Pair(0, 0), Pair(-73, 61),
        Pair(22, 43), Pair(13, 43), Pair(17, 42), Pair(2, 44), Pair(14, 35), Pair(-55, -5), Pair(3, 91), Pair(-26, 46),
        Pair(6, 44), Pair(16, 48), Pair(13, 47), Pair(-2, 38), Pair(3, 54), Pair(-21, 38), Pair(-7, 62), Pair(-27, 23),
        Pair(11, 45), Pair(9, 45), Pair(8, 45), Pair(3, 46), Pair(-11, 39), Pair(7, 52), Pair(-25, 16), Pair(2, 56),
        Pair(13, 49), Pair(11, 38), Pair(3, 45), Pair(6, 49), Pair(-1, 47), Pair(5, 45), Pair(11, 40), Pair(9, 61),
        Pair(13, 36), Pair(12, 45), Pair(3, 42), Pair(4, 39), Pair(10, 48), Pair(11, 44), Pair(15, 44), Pair(-25, 67)
      },
      { // Piece 2
        Pair(-14, 76), Pair(-75, 94), Pair(-29, 53), Pair(-5, 78), Pair(-119, 82), Pair(-84, 96), Pair(-10, 73), Pair(61, 74),
        Pair(1, 80), Pair(-9, 63), Pair(14, 77), Pair(-46, 77), Pair(-59, 94), Pair(-26, 55), Pair(-85, 82), Pair(-132, 10),
        Pair(-5, 65), Pair(1, 67), Pair(9, 61), Pair(-11, 78), Pair(0, 49), Pair(-3, 73), Pair(0, 0), Pair(-3, 65),
        Pair(0, 73), Pair(-1, 57), Pair(15, 67), Pair(7, 51), Pair(1, 61), Pair(-103, -55), Pair(1, 96), Pair(-85, 5),
        Pair(4, 57), Pair(9, 63), Pair(0, 56), Pair(-2, 65), Pair(-13, 33), Pair(-12, 60), Pair(-28, 56), Pair(-30, 70),
        Pair(2, 65), Pair(7, 54), Pair(7, 59), Pair(-10, 41), Pair(-1, 59), Pair(2, 43), Pair(1, 56), Pair(-13, 45),
        Pair(0, 61), Pair(11, 59), Pair(-6, 44), Pair(2, 59), Pair(-2, 39), Pair(3, 63), Pair(4, 40), Pair(8, 65),
        Pair(8, 68), Pair(-21, 33), Pair(10, 52), Pair(-8, 43), Pair(7, 59), Pair(4, 52), Pair(12, 72), Pair(-17, 76)
      },
      { // Piece 3
        Pair(23, 69), Pair(-2, 79), Pair(7, 70), Pair(-4, 80), Pair(27, 57), Pair(-28, 65), Pair(-44, 90), Pair(-23, 79),
        Pair(12, 70), Pair(35, 62), Pair(11, 74), Pair(8, 74), Pair(-12, 79), Pair(-16, 79), Pair(62, 74), Pair(5, 75),
        Pair(15, 61), Pair(9, 63), Pair(14, 60), Pair(1, 68), Pair(-7, 70), Pair(-10, 73), Pair(0, 0), Pair(-12, 58),
        Pair(33, 57), Pair(0, 66), Pair(19, 57), Pair(7, 71), Pair(15, 53), Pair(-42, -86), Pair(-16, 71), Pair(46, -42),
        Pair(20, 55), Pair(18, 69), Pair(12, 64), Pair(3, 67), Pair(6, 64), Pair(-11, 64), Pair(-1, 50), Pair(-18, 49),
        Pair(17, 68), Pair(13, 65), Pair(14, 65), Pair(15, 67), Pair(16, 51), Pair(7, 62), Pair(3, 58), Pair(-3, 53),
        Pair(17, 70), Pair(28, 63), Pair(21, 60), Pair(21, 57), Pair(25, 53), Pair(15, 54), Pair(-6, 57), Pair(42, 44),
        Pair(18, 69), Pair(16, 65), Pair(14, 67), Pair(12, 65), Pair(10, 65), Pair(9, 61), Pair(11, 55), Pair(8, 57)
      },
      { // Piece 4
        Pair(-7, 97), Pair(-50, 145), Pair(-21, 135), Pair(4, 114), Pair(11, 100), Pair(2, 176), Pair(-53, 149), Pair(9, 152),
        Pair(27, 86), Pair(10, 113), Pair(15, 118), Pair(-24, 151), Pair(-53, 179), Pair(37, 82), Pair(-2, 143), Pair(22, 109),
        Pair(11, 93), Pair(35, 68), Pair(-2, 104), Pair(-8, 86), Pair(4, 76), Pair(-13, 96), Pair(0, 0), Pair(-31, 36),
        Pair(27, 82), Pair(4, 113), Pair(13, 88), Pair(1, 114), Pair(-25, 139), Pair(-10, 37), Pair(-15, 62), Pair(10, 62),
        Pair(16, 77), Pair(4, 125), Pair(12, 103), Pair(-8, 126), Pair(-3, 106), Pair(-7, 101), Pair(-8, 88), Pair(3, 110),
        Pair(8, 132), Pair(2, 113), Pair(4, 112), Pair(5, 114), Pair(1, 103), Pair(-3, 111), Pair(22, 78), Pair(5, 103),
        Pair(4, 120), Pair(5, 105), Pair(6, 100), Pair(2, 100), Pair(-2, 115), Pair(2, 102), Pair(10, 74), Pair(2, 135),
        Pair(-7, 98), Pair(18, 70), Pair(13, 69), Pair(9, 90), Pair(10, 106), Pair(-5, 114), Pair(0, 121), Pair(15, 133)
      },
      { // Piece 5
        Pair(395, -63), Pair(74, 12), Pair(-37, 12), Pair(178, 10), Pair(8, -4), Pair(83, -7), Pair(195, -22), Pair(-29, -149),
        Pair(151, -16), Pair(49, -3), Pair(189, -7), Pair(8, 29), Pair(105, -34), Pair(19, -12), Pair(-24, -5), Pair(256, -32),
        Pair(192, 3), Pair(173, -11), Pair(-30, 21), Pair(72, 0), Pair(6, -7), Pair(-31, -27), Pair(0, 0), Pair(139, -51),
        Pair(87, -5), Pair(95, 5), Pair(104, -3), Pair(117, -15), Pair(-24, 5), Pair(6, 11), Pair(41, -67), Pair(-195, -424),
        Pair(126, -4), Pair(62, 0), Pair(50, 5), Pair(18, 4), Pair(25, -6), Pair(40, -9), Pair(17, -15), Pair(0, -19),
        Pair(111, -23), Pair(47, -4), Pair(40, -2), Pair(34, 3), Pair(-8, 11), Pair(27, 5), Pair(-2, 2), Pair(-31, 26),
        Pair(5, 13), Pair(-6, 5), Pair(4, 9), Pair(4, 14), Pair(2, 22), Pair(14, 7), Pair(4, 6), Pair(9, 9),
        Pair(-27, 11), Pair(-20, 5), Pair(-18, 24), Pair(-13, 26), Pair(-7, 22), Pair(16, 12), Pair(2, 13), Pair(7, 2)
      }
    }},
    {{ // Bucket 47
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(19, 16), Pair(-1, 11), Pair(33, 4), Pair(0, 10), Pair(1, 17), Pair(-12, 14), Pair(-9, -5), Pair(42, 22),
        Pair(3, 9), Pair(-3, 8), Pair(7, 5), Pair(13, 3), Pair(-2, 7), Pair(-25, 7), Pair(-17, 3), Pair(0, 0),
        Pair(5, 5), Pair(3, 5), Pair(5, 5), Pair(0, 2), Pair(-4, 1), Pair(-11, 1), Pair(-2, -5), Pair(-4, -3),
        Pair(2, -4), Pair(5, -2), Pair(4, -1), Pair(-2, -3), Pair(0, 2), Pair(1, 3), Pair(-2, -4), Pair(-1, -2),
        Pair(2, -3), Pair(1, -4), Pair(-2, -4), Pair(1, -4), Pair(2, -1), Pair(0, 0), Pair(-1, -3), Pair(0, 0),
        Pair(-1, -4), Pair(-2, -6), Pair(-4, -4), Pair(2, -4), Pair(1, -3), Pair(2, -1), Pair(2, -4), Pair(0, -2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-24, 66), Pair(-116, 50), Pair(-61, 39), Pair(-24, 61), Pair(-36, 70), Pair(48, 94), Pair(-24, 68), Pair(-40, 153),
        Pair(12, 22), Pair(-3, 32), Pair(3, 34), Pair(22, 41), Pair(19, 37), Pair(-19, 19), Pair(-8, 35), Pair(13, -3),
        Pair(39, 25), Pair(3, 34), Pair(1, 43), Pair(17, 42), Pair(-13, 40), Pair(22, 65), Pair(-7, 61), Pair(0, 0),
        Pair(16, 23), Pair(11, 37), Pair(13, 35), Pair(12, 38), Pair(13, 38), Pair(13, 42), Pair(-37, -13), Pair(30, 82),
        Pair(9, 34), Pair(16, 20), Pair(9, 36), Pair(10, 39), Pair(1, 40), Pair(13, 40), Pair(0, 37), Pair(1, 52),
        Pair(5, 18), Pair(10, 27), Pair(9, 32), Pair(4, 34), Pair(11, 39), Pair(-2, 32), Pair(10, 50), Pair(-14, 7),
        Pair(21, 22), Pair(9, 53), Pair(-2, 39), Pair(6, 34), Pair(8, 37), Pair(3, 39), Pair(20, 43), Pair(8, 41),
        Pair(53, 8), Pair(0, 48), Pair(-3, 31), Pair(15, 30), Pair(8, 39), Pair(5, 49), Pair(2, 47), Pair(-27, 71)
      },
      { // Piece 2
        Pair(-36, 100), Pair(-54, 87), Pair(-32, 89), Pair(-110, 67), Pair(-86, 86), Pair(-88, 115), Pair(25, 68), Pair(-8, 54),
        Pair(-16, 72), Pair(11, 70), Pair(-3, 67), Pair(-98, 106), Pair(-54, 87), Pair(-6, 79), Pair(-48, 76), Pair(36, 71),
        Pair(2, 75), Pair(-12, 62), Pair(-11, 79), Pair(-15, 72), Pair(-7, 85), Pair(-47, 70), Pair(-8, 76), Pair(0, 0),
        Pair(-17, 68), Pair(8, 55), Pair(-15, 73), Pair(8, 70), Pair(1, 63), Pair(-7, 65), Pair(-36, -26), Pair(23, 101),
        Pair(12, 51), Pair(-8, 63), Pair(0, 62), Pair(-10, 61), Pair(6, 54), Pair(-3, 51), Pair(-5, 56), Pair(-16, 52),
        Pair(1, 48), Pair(11, 67), Pair(3, 59), Pair(4, 56), Pair(-1, 48), Pair(4, 62), Pair(0, 54), Pair(5, 77),
        Pair(5, 77), Pair(8, 50), Pair(8, 54), Pair(-9, 52), Pair(3, 58), Pair(1, 54), Pair(10, 53), Pair(12, 52),
        Pair(19, 52), Pair(26, 55), Pair(-4, 46), Pair(1, 58), Pair(-4, 56), Pair(13, 68), Pair(-20, 82), Pair(6, 70)
      },
      { // Piece 3
        Pair(-15, 96), Pair(-7, 93), Pair(-30, 103), Pair(5, 92), Pair(-37, 95), Pair(27, 84), Pair(6, 90), Pair(16, 94),
        Pair(16, 86), Pair(6, 90), Pair(-4, 92), Pair(16, 84), Pair(28, 75), Pair(12, 88), Pair(51, 75), Pair(129, 88),
        Pair(17, 81), Pair(5, 90), Pair(10, 92), Pair(2, 92), Pair(13, 88), Pair(5, 91), Pair(6, 94), Pair(0, 0),
        Pair(20, 87), Pair(13, 79), Pair(22, 89), Pair(8, 86), Pair(10, 86), Pair(-1, 83), Pair(52, -22), Pair(-4, 84),
        Pair(19, 76), Pair(27, 75), Pair(19, 81), Pair(-7, 86), Pair(19, 66), Pair(6, 73), Pair(5, 80), Pair(-32, 86),
        Pair(11, 79), Pair(24, 84), Pair(22, 77), Pair(19, 83), Pair(12, 81), Pair(14, 72), Pair(7, 73), Pair(-15, 82),
        Pair(30, 73), Pair(16, 78), Pair(22, 78), Pair(20, 76), Pair(16, 75), Pair(16, 73), Pair(17, 67), Pair(-3, 76),
        Pair(15, 84), Pair(12, 86), Pair(13, 84), Pair(11, 82), Pair(15, 76), Pair(15, 75), Pair(3, 87), Pair(-1, 88)
      },
      { // Piece 4
        Pair(10, 151), Pair(-31, 184), Pair(5, 183), Pair(-33, 170), Pair(26, 150), Pair(40, 153), Pair(95, 124), Pair(-39, 181),
        Pair(25, 133), Pair(12, 149), Pair(20, 149), Pair(-28, 175), Pair(-11, 189), Pair(-33, 235), Pair(2, 169), Pair(31, 149),
        Pair(37, 122), Pair(13, 138), Pair(12, 145), Pair(10, 139), Pair(10, 159), Pair(3, 176), Pair(-42, 180), Pair(0, 0),
        Pair(21, 146), Pair(6, 162), Pair(9, 151), Pair(2, 173), Pair(7, 165), Pair(3, 175), Pair(-27, 53), Pair(7, 113),
        Pair(18, 137), Pair(8, 151), Pair(3, 146), Pair(4, 152), Pair(13, 156), Pair(15, 144), Pair(16, 128), Pair(3, 104),
        Pair(20, 118), Pair(8, 145), Pair(14, 133), Pair(15, 143), Pair(13, 140), Pair(2, 156), Pair(27, 116), Pair(5, 116),
        Pair(17, 132), Pair(16, 132), Pair(13, 131), Pair(11, 130), Pair(10, 137), Pair(20, 137), Pair(35, 103), Pair(0, 134),
        Pair(12, 102), Pair(7, 136), Pair(10, 127), Pair(15, 123), Pair(20, 127), Pair(10, 143), Pair(17, 145), Pair(28, 88)
      },
      { // Piece 5
        Pair(32, -28), Pair(76, -38), Pair(-134, 17), Pair(42, 24), Pair(19, 33), Pair(-249, 33), Pair(196, -19), Pair(54, -52),
        Pair(110, 0), Pair(35, 4), Pair(-27, 40), Pair(-101, 5), Pair(-178, 50), Pair(119, -26), Pair(-94, 2), Pair(97, -6),
        Pair(37, 23), Pair(-47, 25), Pair(-27, 15), Pair(41, 16), Pair(-30, 15), Pair(-77, 15), Pair(-24, -35), Pair(0, 0),
        Pair(137, -12), Pair(77, -8), Pair(84, -3), Pair(25, -4), Pair(48, 4), Pair(-49, 12), Pair(-203, -117), Pair(150, -75),
        Pair(55, -17), Pair(70, -13), Pair(101, -14), Pair(72, -4), Pair(-2, 6), Pair(-30, 0), Pair(48, -6), Pair(64, -20),
        Pair(97, -33), Pair(54, -11), Pair(56, -9), Pair(47, -3), Pair(45, -4), Pair(-12, 11), Pair(21, 2), Pair(23, -11),
        Pair(5, 11), Pair(-6, 6), Pair(19, -6), Pair(18, 2), Pair(9, 16), Pair(15, 12), Pair(2, 11), Pair(2, 2),
        Pair(-19, 7), Pair(-13, -1), Pair(-6, 9), Pair(30, 3), Pair(3, 20), Pair(-1, 21), Pair(7, 12), Pair(2, 19)
      }
    }},
    {{ // Bucket 48
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(-19, 21), Pair(-10, 15), Pair(-4, 28), Pair(14, 23), Pair(7, 19), Pair(-16, 17), Pair(-27, 31),
        Pair(-31, -49), Pair(-18, 5), Pair(0, -3), Pair(-1, 9), Pair(9, 6), Pair(-8, 18), Pair(2, 22), Pair(-4, 20),
        Pair(-10, -6), Pair(-5, 10), Pair(-5, 8), Pair(3, 1), Pair(0, 10), Pair(-4, 8), Pair(-1, 9), Pair(3, 14),
        Pair(-6, 2), Pair(-4, 5), Pair(-4, 1), Pair(-1, 4), Pair(3, 8), Pair(-2, 7), Pair(-2, 4), Pair(1, 5),
        Pair(1, 4), Pair(-1, 4), Pair(-1, -1), Pair(-2, 0), Pair(-1, 5), Pair(-5, 5), Pair(-1, 1), Pair(-3, 2),
        Pair(0, 0), Pair(3, 0), Pair(-2, -1), Pair(-3, -1), Pair(1, 1), Pair(-5, 3), Pair(-4, 4), Pair(1, 7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-41, -66), Pair(133, 17), Pair(-113, 81), Pair(-53, 75), Pair(121, 13), Pair(-47, 45), Pair(56, 34), Pair(83, -24),
        Pair(0, 0), Pair(27, 56), Pair(24, 52), Pair(21, 14), Pair(26, 53), Pair(14, 47), Pair(36, 15), Pair(57, 17),
        Pair(6, 119), Pair(-197, 94), Pair(10, 74), Pair(18, 52), Pair(0, 61), Pair(25, 48), Pair(59, 23), Pair(34, 47),
        Pair(20, 69), Pair(-15, 88), Pair(10, 51), Pair(10, 47), Pair(16, 48), Pair(24, 55), Pair(17, 49), Pair(31, 37),
        Pair(-10, 39), Pair(-12, 61), Pair(-6, 54), Pair(6, 63), Pair(12, 49), Pair(13, 52), Pair(18, 35), Pair(16, 55),
        Pair(1, 61), Pair(11, 58), Pair(-4, 64), Pair(10, 48), Pair(6, 46), Pair(7, 56), Pair(13, 47), Pair(20, 41),
        Pair(13, 66), Pair(8, 56), Pair(7, 44), Pair(6, 49), Pair(10, 47), Pair(14, 48), Pair(9, 52), Pair(18, 45),
        Pair(-109, 84), Pair(4, 61), Pair(7, 52), Pair(16, 49), Pair(3, 42), Pair(14, 56), Pair(9, 54), Pair(7, 94)
      },
      { // Piece 2
        Pair(10, 78), Pair(-23, 115), Pair(28, 87), Pair(-31, 80), Pair(-76, 105), Pair(-33, 118), Pair(-29, 84), Pair(-42, 122),
        Pair(0, 0), Pair(-10, 81), Pair(-4, 77), Pair(-18, 105), Pair(-14, 105), Pair(8, 89), Pair(-10, 99), Pair(9, 59),
        Pair(15, 104), Pair(-251, 220), Pair(-32, 93), Pair(2, 87), Pair(8, 75), Pair(20, 89), Pair(-16, 95), Pair(14, 76),
        Pair(29, 63), Pair(-30, 83), Pair(7, 102), Pair(-10, 79), Pair(6, 91), Pair(0, 89), Pair(7, 84), Pair(5, 61),
        Pair(-14, 91), Pair(-23, 87), Pair(-9, 88), Pair(-6, 92), Pair(-2, 74), Pair(5, 83), Pair(-12, 91), Pair(5, 80),
        Pair(5, 96), Pair(-7, 85), Pair(0, 79), Pair(-2, 81), Pair(1, 80), Pair(-3, 66), Pair(-1, 84), Pair(3, 72),
        Pair(4, 115), Pair(7, 82), Pair(-1, 81), Pair(3, 78), Pair(-4, 69), Pair(-2, 85), Pair(5, 66), Pair(8, 68),
        Pair(6, 94), Pair(-9, 105), Pair(6, 85), Pair(3, 69), Pair(-4, 88), Pair(1, 77), Pair(0, 78), Pair(8, 67)
      },
      { // Piece 3
        Pair(15, 127), Pair(-12, 142), Pair(-14, 131), Pair(-30, 141), Pair(-21, 142), Pair(24, 114), Pair(-6, 132), Pair(-20, 135),
        Pair(0, 0), Pair(-24, 156), Pair(-23, 162), Pair(-26, 161), Pair(-15, 150), Pair(-2, 149), Pair(21, 132), Pair(-27, 141),
        Pair(-14, 159), Pair(7, -280), Pair(-14, 130), Pair(-9, 137), Pair(0, 130), Pair(-5, 132), Pair(-35, 134), Pair(-29, 135),
        Pair(-19, 143), Pair(-26, 133), Pair(-12, 136), Pair(-11, 129), Pair(-3, 129), Pair(-11, 123), Pair(-12, 121), Pair(8, 116),
        Pair(-20, 133), Pair(-24, 99), Pair(-22, 126), Pair(-29, 123), Pair(-9, 119), Pair(-12, 125), Pair(-8, 123), Pair(-15, 121),
        Pair(-20, 108), Pair(-25, 131), Pair(-26, 131), Pair(-20, 127), Pair(-23, 133), Pair(-9, 120), Pair(7, 112), Pair(3, 127),
        Pair(-14, 109), Pair(-14, 105), Pair(-12, 119), Pair(-14, 122), Pair(-14, 130), Pair(-5, 122), Pair(-3, 125), Pair(4, 120),
        Pair(-19, 124), Pair(-23, 125), Pair(-22, 124), Pair(-19, 119), Pair(-15, 125), Pair(-14, 127), Pair(-9, 126), Pair(-12, 139)
      },
      { // Piece 4
        Pair(-121, 375), Pair(40, 208), Pair(-41, 314), Pair(-30, 282), Pair(-16, 275), Pair(5, 249), Pair(33, 260), Pair(6, 270),
        Pair(0, 0), Pair(29, 272), Pair(4, 279), Pair(-3, 287), Pair(10, 278), Pair(-10, 312), Pair(-28, 247), Pair(39, 247),
        Pair(15, 264), Pair(-238, -91), Pair(10, 236), Pair(0, 252), Pair(24, 239), Pair(21, 231), Pair(30, 222), Pair(29, 246),
        Pair(34, 214), Pair(5, 225), Pair(31, 213), Pair(12, 248), Pair(-1, 266), Pair(15, 250), Pair(12, 249), Pair(36, 221),
        Pair(16, 226), Pair(9, 205), Pair(8, 233), Pair(11, 233), Pair(8, 231), Pair(18, 215), Pair(18, 229), Pair(14, 248),
        Pair(8, 273), Pair(6, 229), Pair(7, 226), Pair(11, 222), Pair(5, 240), Pair(15, 226), Pair(13, 228), Pair(26, 198),
        Pair(13, 228), Pair(11, 215), Pair(10, 223), Pair(7, 217), Pair(12, 225), Pair(18, 200), Pair(14, 227), Pair(41, 174),
        Pair(18, 211), Pair(13, 211), Pair(9, 229), Pair(6, 219), Pair(13, 215), Pair(16, 228), Pair(31, 211), Pair(10, 186)
      },
      { // Piece 5
        Pair(81, 66), Pair(-66, 61), Pair(-39, 35), Pair(45, 63), Pair(2, 14), Pair(141, -1), Pair(109, -48), Pair(91, 66),
        Pair(0, 0), Pair(-21, -37), Pair(-106, 7), Pair(-79, 18), Pair(-89, -17), Pair(31, -1), Pair(130, -16), Pair(121, -14),
        Pair(5, -47), Pair(0, 0), Pair(-111, -5), Pair(-41, 0), Pair(-100, 27), Pair(32, -3), Pair(86, -10), Pair(40, -2),
        Pair(-140, -3), Pair(8, -19), Pair(-5, -34), Pair(49, -19), Pair(48, -10), Pair(20, 4), Pair(2, -3), Pair(42, -12),
        Pair(45, -62), Pair(-32, -11), Pair(-30, -7), Pair(23, -14), Pair(38, -8), Pair(21, 5), Pair(-10, 3), Pair(46, 2),
        Pair(15, -36), Pair(-52, -10), Pair(-16, -5), Pair(-31, -1), Pair(-22, -3), Pair(15, -7), Pair(12, -9), Pair(9, 2),
        Pair(-14, 6), Pair(2, -12), Pair(-7, 3), Pair(17, -5), Pair(1, -3), Pair(16, -10), Pair(2, -7), Pair(6, -5),
        Pair(-8, 29), Pair(13, 5), Pair(13, 17), Pair(20, -15), Pair(17, -9), Pair(16, -10), Pair(3, -13), Pair(4, -3)
      }
    }},
    {{ // Bucket 49
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(36, -32), Pair(0, 0), Pair(-7, 28), Pair(20, 4), Pair(-5, 18), Pair(-23, 41), Pair(-4, 22), Pair(5, 24),
        Pair(8, 15), Pair(-35, -46), Pair(-5, 2), Pair(2, 10), Pair(4, 5), Pair(1, 14), Pair(7, 13), Pair(-7, 18),
        Pair(8, 6), Pair(-10, -9), Pair(0, 14), Pair(-2, 4), Pair(-3, 8), Pair(-4, 11), Pair(-2, 11), Pair(-4, 15),
        Pair(5, 2), Pair(-7, -7), Pair(3, 9), Pair(-1, 3), Pair(-2, 5), Pair(-1, 7), Pair(-3, 9), Pair(-1, 10),
        Pair(4, 2), Pair(-4, 0), Pair(-1, 6), Pair(-3, -1), Pair(-2, 5), Pair(-5, 2), Pair(-5, 6), Pair(-7, 5),
        Pair(1, 0), Pair(0, 0), Pair(1, -2), Pair(-3, 9), Pair(-1, -3), Pair(-4, 1), Pair(-4, 3), Pair(-2, -2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-14, 40), Pair(-198, -78), Pair(37, 54), Pair(-68, 81), Pair(18, 51), Pair(22, 22), Pair(-168, 105), Pair(-39, 95),
        Pair(-16, -16), Pair(0, 0), Pair(-1, 54), Pair(-55, 78), Pair(-14, 41), Pair(8, 57), Pair(-5, 51), Pair(-14, 45),
        Pair(151, 10), Pair(1, 97), Pair(-299, 237), Pair(9, 72), Pair(-2, 64), Pair(13, 55), Pair(-6, 53), Pair(20, 32),
        Pair(-12, 84), Pair(-3, 65), Pair(-43, 77), Pair(-10, 68), Pair(-6, 42), Pair(4, 62), Pair(9, 46), Pair(9, 42),
        Pair(-5, 61), Pair(-7, 7), Pair(-24, 72), Pair(-11, 46), Pair(2, 58), Pair(1, 49), Pair(6, 59), Pair(2, 60),
        Pair(3, 61), Pair(-4, 52), Pair(-1, 57), Pair(-5, 52), Pair(-7, 56), Pair(2, 53), Pair(2, 54), Pair(-1, 70),
        Pair(19, 66), Pair(-5, 68), Pair(6, 58), Pair(0, 60), Pair(5, 50), Pair(1, 49), Pair(-4, 52), Pair(7, 57),
        Pair(31, 18), Pair(3, 59), Pair(1, 61), Pair(6, 48), Pair(7, 54), Pair(10, 47), Pair(-1, 76), Pair(-11, 46)
      },
      { // Piece 2
        Pair(0, 0), Pair(-35, 97), Pair(-53, 81), Pair(-29, 88), Pair(-30, 111), Pair(-54, 94), Pair(-86, 101), Pair(-20, 105),
        Pair(-12, 63), Pair(0, 0), Pair(-7, 72), Pair(-65, 114), Pair(-28, 100), Pair(16, 85), Pair(-2, 69), Pair(-1, 74),
        Pair(-21, -49), Pair(-3, 93), Pair(-193, -71), Pair(-29, 87), Pair(-7, 90), Pair(-23, 84), Pair(-25, 85), Pair(-2, 65),
        Pair(-10, 70), Pair(-19, 83), Pair(-46, 85), Pair(-19, 88), Pair(-10, 77), Pair(-31, 100), Pair(0, 67), Pair(-7, 77),
        Pair(-26, 76), Pair(-15, 59), Pair(-36, 82), Pair(-18, 74), Pair(-12, 66), Pair(-7, 66), Pair(-18, 82), Pair(10, 47),
        Pair(-3, 66), Pair(-12, 85), Pair(-10, 75), Pair(-10, 72), Pair(-2, 66), Pair(-11, 67), Pair(2, 59), Pair(-9, 77),
        Pair(-8, 110), Pair(3, 68), Pair(-14, 74), Pair(-2, 61), Pair(-13, 70), Pair(4, 67), Pair(-5, 63), Pair(-5, 65),
        Pair(0, 89), Pair(-8, 68), Pair(2, 77), Pair(-7, 87), Pair(17, 56), Pair(-4, 64), Pair(13, 61), Pair(11, 59)
      },
      { // Piece 3
        Pair(-37, 90), Pair(-42, 98), Pair(-9, 87), Pair(-9, 105), Pair(16, 84), Pair(-62, 111), Pair(1, 79), Pair(39, 78),
        Pair(-27, 84), Pair(0, 0), Pair(-19, 109), Pair(-6, 109), Pair(-27, 116), Pair(0, 102), Pair(-70, 131), Pair(-36, 111),
        Pair(-181, -37), Pair(-25, 94), Pair(-224, -56), Pair(-22, 101), Pair(-13, 90), Pair(3, 79), Pair(-12, 89), Pair(-6, 94),
        Pair(-21, 82), Pair(-18, 93), Pair(-23, 87), Pair(-25, 99), Pair(-33, 106), Pair(-33, 102), Pair(-11, 84), Pair(-22, 93),
        Pair(-21, 73), Pair(-16, 81), Pair(-33, 83), Pair(-26, 102), Pair(-9, 76), Pair(-5, 79), Pair(-3, 88), Pair(2, 86),
        Pair(-23, 81), Pair(-19, 96), Pair(-31, 93), Pair(-16, 90), Pair(-11, 80), Pair(-9, 86), Pair(0, 74), Pair(3, 88),
        Pair(-13, 88), Pair(-16, 78), Pair(-15, 88), Pair(-9, 81), Pair(-6, 82), Pair(-10, 93), Pair(-8, 86), Pair(-1, 99),
        Pair(-18, 86), Pair(-11, 85), Pair(-21, 82), Pair(-15, 87), Pair(-14, 89), Pair(-9, 91), Pair(-11, 94), Pair(2, 97)
      },
      { // Piece 4
        Pair(-11, 173), Pair(-33, 191), Pair(39, 163), Pair(10, 209), Pair(44, 152), Pair(-13, 210), Pair(-50, 207), Pair(60, 127),
        Pair(29, 144), Pair(0, 0), Pair(4, 209), Pair(-4, 200), Pair(7, 184), Pair(15, 195), Pair(22, 143), Pair(-9, 179),
        Pair(-125, 44), Pair(26, 140), Pair(-281, -101), Pair(23, 160), Pair(26, 162), Pair(40, 128), Pair(6, 172), Pair(20, 169),
        Pair(12, 164), Pair(18, 164), Pair(-1, 174), Pair(28, 159), Pair(12, 194), Pair(19, 172), Pair(12, 169), Pair(19, 161),
        Pair(5, 158), Pair(11, 166), Pair(3, 155), Pair(5, 187), Pair(12, 170), Pair(3, 176), Pair(9, 176), Pair(6, 189),
        Pair(19, 132), Pair(14, 160), Pair(16, 138), Pair(8, 160), Pair(18, 150), Pair(11, 160), Pair(11, 189), Pair(7, 193),
        Pair(19, 182), Pair(9, 176), Pair(10, 150), Pair(9, 152), Pair(7, 166), Pair(9, 155), Pair(19, 170), Pair(21, 186),
        Pair(8, 168), Pair(23, 174), Pair(15, 139), Pair(11, 151), Pair(12, 148), Pair(12, 154), Pair(8, 159), Pair(7, 112)
      },
      { // Piece 5
        Pair(-18, -25), Pair(109, -65), Pair(-50, -22), Pair(-62, -21), Pair(-124, 25), Pair(165, 9), Pair(-59, -41), Pair(30, -111),
        Pair(-39, -31), Pair(0, 0), Pair(10, -67), Pair(79, -22), Pair(-41, -6), Pair(-4, 27), Pair(29, 10), Pair(47, -31),
        Pair(0, 0), Pair(-129, -71), Pair(0, 0), Pair(-83, 2), Pair(-120, 20), Pair(19, 8), Pair(-36, 26), Pair(51, -7),
        Pair(-116, -19), Pair(-41, -58), Pair(22, -23), Pair(-135, -14), Pair(99, -17), Pair(75, -5), Pair(-30, 24), Pair(103, -43),
        Pair(-65, -34), Pair(-40, -32), Pair(-21, -21), Pair(16, -11), Pair(-1, -17), Pair(14, 1), Pair(10, -2), Pair(40, -19),
        Pair(-66, -9), Pair(9, -44), Pair(-22, -15), Pair(-6, -10), Pair(2, -6), Pair(4, -2), Pair(19, -5), Pair(25, -2),
        Pair(-11, -12), Pair(-8, -17), Pair(29, -27), Pair(17, 0), Pair(11, -5), Pair(16, -4), Pair(9, -5), Pair(7, -3),
        Pair(12, -6), Pair(6, -5), Pair(17, -10), Pair(26, -4), Pair(13, 4), Pair(36, -8), Pair(4, -5), Pair(12, -3)
      }
    }},
    {{ // Bucket 50
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-9, 15), Pair(-28, 27), Pair(0, 0), Pair(-28, 7), Pair(-29, 20), Pair(0, 14), Pair(-33, 27), Pair(24, 15),
        Pair(-6, 12), Pair(-1, 10), Pair(-29, -46), Pair(-15, 40), Pair(1, 6), Pair(8, 18), Pair(-6, 17), Pair(-9, 21),
        Pair(-4, 5), Pair(5, 13), Pair(-10, -6), Pair(1, 15), Pair(-5, 9), Pair(4, 8), Pair(4, 7), Pair(1, 12),
        Pair(-1, 1), Pair(2, -7), Pair(-11, -4), Pair(-1, 12), Pair(-7, 3), Pair(-2, 8), Pair(0, 6), Pair(1, 8),
        Pair(-1, 3), Pair(-4, -3), Pair(-5, -4), Pair(-1, 3), Pair(-3, 4), Pair(-7, 4), Pair(-2, 3), Pair(-1, 1),
        Pair(-5, 0), Pair(-6, -5), Pair(0, 0), Pair(-3, 8), Pair(-1, -2), Pair(-6, -1), Pair(3, 3), Pair(4, 5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-85, 77), Pair(-40, 89), Pair(-65, -45), Pair(-43, 47), Pair(53, 27), Pair(-36, 48), Pair(-64, 107), Pair(61, 15),
        Pair(-26, 70), Pair(3, 29), Pair(0, 0), Pair(-31, 41), Pair(-12, 65), Pair(-31, 46), Pair(-1, 44), Pair(-4, 23),
        Pair(-22, 66), Pair(134, -141), Pair(-2, 99), Pair(-352, 255), Pair(4, 59), Pair(-17, 49), Pair(-5, 61), Pair(-6, 50),
        Pair(-5, 60), Pair(-29, 39), Pair(-2, 72), Pair(-38, 52), Pair(-7, 63), Pair(-8, 36), Pair(4, 47), Pair(7, 37),
        Pair(-14, 59), Pair(-16, 75), Pair(-20, 35), Pair(-33, 59), Pair(-16, 53), Pair(-8, 68), Pair(1, 55), Pair(0, 34),
        Pair(-7, 41), Pair(-3, 74), Pair(-9, 56), Pair(-5, 67), Pair(-13, 47), Pair(-4, 52), Pair(-1, 47), Pair(2, 55),
        Pair(-6, 73), Pair(-26, 62), Pair(-4, 53), Pair(-7, 59), Pair(0, 48), Pair(-1, 43), Pair(6, 32), Pair(8, 56),
        Pair(49, 71), Pair(-4, 68), Pair(27, 19), Pair(-1, 60), Pair(6, 42), Pair(5, 52), Pair(1, 58), Pair(48, 28)
      },
      { // Piece 2
        Pair(-7, 65), Pair(51, -26), Pair(-79, 81), Pair(-49, 79), Pair(-52, 95), Pair(-58, 69), Pair(-152, 113), Pair(-22, 72),
        Pair(0, 24), Pair(-34, 75), Pair(0, 0), Pair(-24, 97), Pair(-33, 47), Pair(-23, 77), Pair(-13, 82), Pair(-34, 74),
        Pair(-1, 85), Pair(-43, -60), Pair(-17, 114), Pair(-473, 94), Pair(-25, 71), Pair(-27, 84), Pair(-22, 98), Pair(-12, 61),
        Pair(-5, 44), Pair(-25, 67), Pair(-24, 71), Pair(-46, 70), Pair(-4, 60), Pair(-5, 69), Pair(-15, 72), Pair(6, 67),
        Pair(-9, 98), Pair(-45, 68), Pair(-12, 79), Pair(-41, 65), Pair(-11, 68), Pair(-19, 71), Pair(-16, 78), Pair(-2, 60),
        Pair(-12, 39), Pair(-15, 77), Pair(-9, 61), Pair(-11, 74), Pair(-15, 55), Pair(-10, 62), Pair(-6, 46), Pair(-2, 54),
        Pair(-26, 111), Pair(-5, 52), Pair(4, 73), Pair(-9, 62), Pair(-5, 66), Pair(-5, 54), Pair(3, 56), Pair(1, 43),
        Pair(3, 64), Pair(-28, 112), Pair(-7, 63), Pair(-15, 87), Pair(-3, 49), Pair(-3, 77), Pair(-20, 34), Pair(-1, 83)
      },
      { // Piece 3
        Pair(-11, 62), Pair(-33, 55), Pair(-55, 82), Pair(-52, 81), Pair(-22, 82), Pair(8, 87), Pair(-26, 77), Pair(-124, 108),
        Pair(-15, 62), Pair(-40, 73), Pair(0, 0), Pair(-28, 81), Pair(-35, 104), Pair(-37, 105), Pair(-29, 96), Pair(-27, 84),
        Pair(-17, 52), Pair(78, -136), Pair(-4, 68), Pair(-110, 93), Pair(-25, 75), Pair(23, 65), Pair(-48, 80), Pair(-11, 73),
        Pair(-28, 82), Pair(-26, 56), Pair(-1, 74), Pair(-39, 72), Pair(-5, 64), Pair(-33, 86), Pair(-6, 72), Pair(-16, 71),
        Pair(-9, 65), Pair(-26, 51), Pair(-29, 67), Pair(-45, 72), Pair(-24, 76), Pair(-8, 73), Pair(-10, 67), Pair(-1, 70),
        Pair(-23, 62), Pair(-25, 62), Pair(-10, 66), Pair(-31, 79), Pair(-19, 83), Pair(-15, 70), Pair(-14, 80), Pair(-14, 84),
        Pair(-28, 80), Pair(-18, 62), Pair(-14, 68), Pair(-27, 68), Pair(-5, 60), Pair(-14, 79), Pair(-5, 83), Pair(9, 69),
        Pair(-23, 74), Pair(-23, 69), Pair(-21, 75), Pair(-22, 66), Pair(-19, 74), Pair(-17, 75), Pair(-10, 64), Pair(-12, 77)
      },
      { // Piece 4
        Pair(56, 77), Pair(-36, 120), Pair(102, 33), Pair(-46, 176), Pair(-22, 193), Pair(-119, 214), Pair(-11, 165), Pair(19, 126),
        Pair(26, 105), Pair(5, 74), Pair(0, 0), Pair(-13, 155), Pair(28, 125), Pair(-47, 172), Pair(-27, 158), Pair(-19, 129),
        Pair(26, 97), Pair(-185, 12), Pair(18, 126), Pair(-248, -50), Pair(25, 103), Pair(-21, 140), Pair(5, 118), Pair(9, 146),
        Pair(32, 134), Pair(11, 112), Pair(35, 118), Pair(9, 125), Pair(17, 119), Pair(0, 137), Pair(20, 118), Pair(11, 123),
        Pair(12, 112), Pair(6, 120), Pair(1, 133), Pair(0, 127), Pair(13, 121), Pair(17, 94), Pair(8, 121), Pair(0, 170),
        Pair(17, 71), Pair(2, 128), Pair(11, 115), Pair(3, 111), Pair(10, 102), Pair(3, 123), Pair(19, 85), Pair(9, 114),
        Pair(-11, 124), Pair(14, 105), Pair(13, 117), Pair(3, 117), Pair(4, 120), Pair(9, 121), Pair(9, 109), Pair(9, 127),
        Pair(11, 87), Pair(3, 117), Pair(11, 119), Pair(5, 102), Pair(2, 139), Pair(10, 92), Pair(24, 79), Pair(-23, 128)
      },
      { // Piece 5
        Pair(19, 240), Pair(-23, -16), Pair(61, -86), Pair(-19, -34), Pair(80, 39), Pair(-50, 40), Pair(48, 38), Pair(-40, 34),
        Pair(-60, -117), Pair(94, -103), Pair(0, 0), Pair(62, -102), Pair(-85, 35), Pair(-130, 43), Pair(-59, 44), Pair(34, -25),
        Pair(23, -53), Pair(0, 0), Pair(-197, -6), Pair(0, 0), Pair(-9, -21), Pair(-6, -4), Pair(78, 9), Pair(-109, 35),
        Pair(-169, -29), Pair(-129, -19), Pair(-113, -28), Pair(-56, -15), Pair(6, -8), Pair(19, -13), Pair(-10, 11), Pair(-30, 6),
        Pair(-6, -11), Pair(-86, -9), Pair(-38, -32), Pair(-21, -27), Pair(59, -18), Pair(-5, 4), Pair(-27, 13), Pair(12, 1),
        Pair(25, -5), Pair(-20, -9), Pair(-2, -33), Pair(12, -16), Pair(4, -2), Pair(-30, 8), Pair(-7, 1), Pair(13, -2),
        Pair(-21, 6), Pair(-4, -7), Pair(10, -8), Pair(-8, 4), Pair(3, 7), Pair(4, -2), Pair(6, -8), Pair(13, -8),
        Pair(35, -39), Pair(10, -23), Pair(3, 2), Pair(19, -18), Pair(7, 14), Pair(4, 7), Pair(0, 1), Pair(-3, -3)
      }
    }},
    {{ // Bucket 51
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-3, 8), Pair(-17, 29), Pair(4, 45), Pair(0, 0), Pair(67, -7), Pair(128, -27), Pair(13, -42), Pair(-5, 70),
        Pair(-5, 9), Pair(-3, 18), Pair(15, 27), Pair(-19, -40), Pair(-14, 75), Pair(-11, 17), Pair(-5, -15), Pair(-4, 17),
        Pair(-2, 13), Pair(-4, 9), Pair(9, 6), Pair(-3, -5), Pair(2, 15), Pair(-9, 16), Pair(5, 2), Pair(3, 8),
        Pair(4, 8), Pair(-2, 0), Pair(8, 0), Pair(-3, -10), Pair(-1, 5), Pair(-5, 2), Pair(-3, 5), Pair(-1, 5),
        Pair(2, 4), Pair(1, 0), Pair(-1, -2), Pair(-2, -2), Pair(-5, 2), Pair(0, 0), Pair(-2, 3), Pair(-3, 3),
        Pair(1, -1), Pair(3, -9), Pair(1, -8), Pair(0, 0), Pair(1, -8), Pair(-4, 0), Pair(-4, -5), Pair(-1, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-43, 97), Pair(-1, -240), Pair(-38, 64), Pair(11, -100), Pair(26, 40), Pair(-29, -15), Pair(-135, 4), Pair(64, -55),
        Pair(-11, -23), Pair(-28, 75), Pair(-16, 21), Pair(0, 0), Pair(-22, -31), Pair(-54, 32), Pair(27, -54), Pair(13, -23),
        Pair(-61, 101), Pair(19, 10), Pair(-375, -6), Pair(20, 70), Pair(28, 51), Pair(-63, 35), Pair(-23, 12), Pair(16, 12),
        Pair(-36, 47), Pair(-7, 64), Pair(-29, 48), Pair(-18, 63), Pair(-39, 30), Pair(6, 40), Pair(-12, 8), Pair(-15, 26),
        Pair(0, 39), Pair(-40, 62), Pair(-21, 45), Pair(-14, 5), Pair(-10, 24), Pair(-2, 32), Pair(-29, 63), Pair(-7, 63),
        Pair(-6, 51), Pair(-5, 16), Pair(-2, 30), Pair(-14, 34), Pair(-10, 42), Pair(-12, 13), Pair(-9, 26), Pair(-6, 72),
        Pair(7, 48), Pair(-18, 34), Pair(0, 25), Pair(-6, 33), Pair(-4, 34), Pair(8, 3), Pair(10, -2), Pair(-25, 81),
        Pair(8, -44), Pair(-2, 36), Pair(-38, -12), Pair(-22, 9), Pair(-3, 14), Pair(14, 35), Pair(-4, 33), Pair(-29, 96)
      },
      { // Piece 2
        Pair(34, -54), Pair(-131, 93), Pair(-72, -62), Pair(-7, 51), Pair(-120, -10), Pair(170, -20), Pair(156, -3), Pair(-2, -10),
        Pair(-35, 97), Pair(-56, 72), Pair(-14, 80), Pair(0, 0), Pair(-69, 91), Pair(-74, 116), Pair(-22, 79), Pair(-3, -4),
        Pair(-26, 52), Pair(-20, 55), Pair(-53, -314), Pair(1, 93), Pair(-57, -25), Pair(-37, 36), Pair(-11, 45), Pair(15, 29),
        Pair(-6, 52), Pair(-20, 30), Pair(-44, 85), Pair(-7, 17), Pair(-17, 46), Pair(-12, 48), Pair(-4, 49), Pair(-34, 96),
        Pair(-32, 40), Pair(-31, 62), Pair(-34, 29), Pair(-13, 56), Pair(-8, 10), Pair(-11, 44), Pair(-31, 50), Pair(11, 2),
        Pair(3, 25), Pair(-5, -34), Pair(-7, 43), Pair(-15, 36), Pair(-9, 27), Pair(-19, 32), Pair(-3, 51), Pair(-21, -7),
        Pair(-18, 51), Pair(-2, 49), Pair(-17, 65), Pair(2, 31), Pair(-17, 42), Pair(-3, 40), Pair(-2, 18), Pair(-23, 70),
        Pair(-10, 97), Pair(-44, 40), Pair(-1, 45), Pair(-8, 36), Pair(-12, 63), Pair(-12, 22), Pair(-4, 68), Pair(12, -12)
      },
      { // Piece 3
        Pair(-14, 40), Pair(-23, 39), Pair(105, 0), Pair(-97, 47), Pair(-18, 35), Pair(75, -15), Pair(-141, 108), Pair(-8, 10),
        Pair(-31, 43), Pair(-21, 30), Pair(8, 20), Pair(0, 0), Pair(-32, 35), Pair(60, 69), Pair(-17, 39), Pair(-36, 52),
        Pair(-43, 42), Pair(-33, 13), Pair(-112, 165), Pair(31, 13), Pair(42, 85), Pair(37, -29), Pair(2, 33), Pair(-1, 16),
        Pair(-30, 16), Pair(7, 24), Pair(-8, 18), Pair(-2, 6), Pair(-35, 48), Pair(-34, 13), Pair(2, 38), Pair(-16, 28),
        Pair(-13, 37), Pair(-30, 44), Pair(-35, 25), Pair(2, 7), Pair(-29, 29), Pair(-21, 31), Pair(-42, 83), Pair(12, 19),
        Pair(-6, 15), Pair(-6, 7), Pair(-27, 30), Pair(-17, 35), Pair(-15, 17), Pair(-9, 35), Pair(-18, 19), Pair(-29, 54),
        Pair(1, -1), Pair(5, -25), Pair(-29, -3), Pair(-4, 10), Pair(-38, 16), Pair(-25, 40), Pair(-7, 31), Pair(11, -32),
        Pair(-17, 30), Pair(-18, 29), Pair(-17, 18), Pair(-21, 27), Pair(-22, 33), Pair(-14, 19), Pair(-13, 12), Pair(-12, 23)
      },
      { // Piece 4
        Pair(-12, 46), Pair(62, 23), Pair(112, -19), Pair(84, -39), Pair(-79, 172), Pair(8, 121), Pair(118, -29), Pair(93, 12),
        Pair(23, 1), Pair(-29, 69), Pair(38, -36), Pair(0, 0), Pair(-47, 131), Pair(32, 115), Pair(0, 116), Pair(-32, 122),
        Pair(-22, 88), Pair(9, 6), Pair(39, -3), Pair(35, 47), Pair(-54, -29), Pair(42, 20), Pair(29, 30), Pair(24, 74),
        Pair(12, 48), Pair(19, 36), Pair(-4, 68), Pair(7, 47), Pair(-5, 89), Pair(27, 11), Pair(36, -7), Pair(17, 48),
        Pair(-3, 66), Pair(8, 45), Pair(18, -32), Pair(25, 42), Pair(22, 40), Pair(24, 12), Pair(17, 43), Pair(8, 27),
        Pair(-2, 39), Pair(4, 46), Pair(10, 23), Pair(16, 31), Pair(4, 46), Pair(10, 13), Pair(-4, 74), Pair(3, 39),
        Pair(33, -31), Pair(-3, 48), Pair(5, 17), Pair(17, 14), Pair(6, 27), Pair(22, 15), Pair(13, 44), Pair(34, -71),
        Pair(-6, 53), Pair(20, 31), Pair(1, 70), Pair(11, 42), Pair(8, 9), Pair(-3, 77), Pair(49, 16), Pair(-57, 21)
      },
      { // Piece 5
        Pair(-11, 143), Pair(20, -63), Pair(30, 113), Pair(-21, -33), Pair(-11, 12), Pair(11, 103), Pair(6, -93), Pair(-56, -97),
        Pair(21, -29), Pair(-56, -49), Pair(50, 5), Pair(0, 0), Pair(-40, -3), Pair(2, 56), Pair(14, -39), Pair(-83, -157),
        Pair(-58, -45), Pair(-15, -29), Pair(0, 0), Pair(-32, -111), Pair(0, 0), Pair(-17, 30), Pair(164, -24), Pair(-10, 32),
        Pair(17, 32), Pair(-154, 11), Pair(-185, 11), Pair(35, -58), Pair(163, -54), Pair(184, -46), Pair(-81, 31), Pair(17, -11),
        Pair(37, -55), Pair(-18, -22), Pair(156, -48), Pair(6, -43), Pair(-14, -16), Pair(-124, 24), Pair(84, -35), Pair(139, -19),
        Pair(-226, 83), Pair(-21, -12), Pair(-35, -15), Pair(53, -34), Pair(-14, 3), Pair(26, 5), Pair(8, 13), Pair(-12, 4),
        Pair(49, -25), Pair(-6, -4), Pair(-5, -6), Pair(60, -51), Pair(-2, 3), Pair(5, 9), Pair(8, 1), Pair(-2, 7),
        Pair(28, 12), Pair(14, 7), Pair(6, 6), Pair(18, -22), Pair(1, -5), Pair(24, 18), Pair(-2, 16), Pair(1, 12)
      }
    }},
    {{ // Bucket 52
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-4, 11), Pair(6, 26), Pair(-5, 13), Pair(-46, 22), Pair(0, 0), Pair(-9, -16), Pair(-15, 46), Pair(30, -10),
        Pair(4, 4), Pair(9, 8), Pair(1, 2), Pair(10, 20), Pair(-32, -19), Pair(-24, 50), Pair(13, 4), Pair(-4, 25),
        Pair(4, 4), Pair(3, 5), Pair(-4, 12), Pair(14, 13), Pair(-10, 7), Pair(4, 13), Pair(3, 6), Pair(1, 6),
        Pair(4, 3), Pair(-1, 1), Pair(-2, 6), Pair(0, 8), Pair(-6, -6), Pair(-1, 2), Pair(1, 3), Pair(0, 4),
        Pair(2, 0), Pair(4, 3), Pair(-5, 3), Pair(4, 7), Pair(-7, 1), Pair(-5, 0), Pair(-1, 4), Pair(-2, 3),
        Pair(1, -1), Pair(2, 8), Pair(2, 3), Pair(2, 8), Pair(0, 0), Pair(-3, -4), Pair(-1, 2), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(43, 34), Pair(34, 76), Pair(6, 17), Pair(-58, 91), Pair(-14, -73), Pair(0, 2), Pair(-49, -13), Pair(15, -49),
        Pair(-12, 79), Pair(-17, 62), Pair(-14, 38), Pair(-12, 34), Pair(0, 0), Pair(6, 44), Pair(-55, -30), Pair(-18, 13),
        Pair(73, 29), Pair(-18, 63), Pair(-5, 35), Pair(-93, -3), Pair(-8, 76), Pair(-497, 344), Pair(4, -2), Pair(-19, -17),
        Pair(7, 24), Pair(-10, 33), Pair(-9, 55), Pair(-37, 22), Pair(-12, 41), Pair(-33, 10), Pair(-3, 24), Pair(-27, 10),
        Pair(-6, 56), Pair(-14, 40), Pair(-20, 41), Pair(-27, 31), Pair(-5, 16), Pair(-12, 18), Pair(-12, 18), Pair(2, 36),
        Pair(-8, 20), Pair(-8, 54), Pair(-10, 19), Pair(-10, 42), Pair(-16, 36), Pair(-3, 23), Pair(-15, 35), Pair(-7, 40),
        Pair(-21, 39), Pair(-12, 38), Pair(3, 23), Pair(-8, 24), Pair(-10, 30), Pair(-7, 12), Pair(24, 20), Pair(11, 21),
        Pair(10, -139), Pair(3, 26), Pair(10, 35), Pair(-1, 37), Pair(17, 31), Pair(5, 7), Pair(4, 30), Pair(-2, -38)
      },
      { // Piece 2
        Pair(-31, 68), Pair(46, -28), Pair(-67, 145), Pair(-34, 23), Pair(-179, 107), Pair(-156, -10), Pair(8, 60), Pair(-88, 74),
        Pair(-27, 68), Pair(-2, 43), Pair(-2, 17), Pair(-87, 102), Pair(0, 0), Pair(-27, 92), Pair(-34, 13), Pair(23, 30),
        Pair(-13, 59), Pair(-40, 67), Pair(-31, 60), Pair(-387, 174), Pair(17, 79), Pair(-331, 266), Pair(11, 48), Pair(-7, 17),
        Pair(-21, 50), Pair(0, 43), Pair(2, 31), Pair(-56, 58), Pair(2, 31), Pair(-39, 79), Pair(0, 30), Pair(-9, 53),
        Pair(-17, 38), Pair(-9, 24), Pair(-24, 44), Pair(-35, 46), Pair(-20, 55), Pair(-28, 17), Pair(-19, 56), Pair(-19, -1),
        Pair(-6, 26), Pair(-20, 51), Pair(-19, 49), Pair(-13, 52), Pair(-13, 23), Pair(-18, 57), Pair(-22, 22), Pair(2, 33),
        Pair(-25, 28), Pair(-12, 37), Pair(-9, 60), Pair(-11, 30), Pair(-5, 45), Pair(-6, 40), Pair(-12, 48), Pair(-19, 24),
        Pair(-22, 56), Pair(8, 37), Pair(-10, 38), Pair(1, 41), Pair(-16, 52), Pair(-3, 44), Pair(-30, 81), Pair(16, 82)
      },
      { // Piece 3
        Pair(-7, 23), Pair(-67, 59), Pair(-102, 83), Pair(-71, 61), Pair(-37, 36), Pair(30, 37), Pair(20, 26), Pair(-62, 80),
        Pair(-1, 42), Pair(-18, 49), Pair(-20, 46), Pair(-49, 64), Pair(0, 0), Pair(-18, 26), Pair(-40, 70), Pair(-41, 39),
        Pair(4, 37), Pair(-11, 26), Pair(8, 25), Pair(-277, -79), Pair(51, 19), Pair(-27, -176), Pair(13, 7), Pair(-4, 34),
        Pair(-6, 44), Pair(8, 37), Pair(13, 23), Pair(-9, 21), Pair(2, 32), Pair(-40, 38), Pair(-14, 32), Pair(3, 31),
        Pair(-7, 39), Pair(-13, 42), Pair(-13, 31), Pair(-36, 31), Pair(-7, 23), Pair(-8, 9), Pair(-58, 46), Pair(13, 24),
        Pair(-22, 53), Pair(-11, 26), Pair(-8, 22), Pair(-20, 40), Pair(-10, 21), Pair(7, -2), Pair(-8, 46), Pair(-22, 47),
        Pair(-12, 55), Pair(-18, 42), Pair(-13, 35), Pair(-19, 30), Pair(-1, 10), Pair(7, 19), Pair(-24, 57), Pair(23, 18),
        Pair(-2, 27), Pair(-9, 30), Pair(5, 23), Pair(-12, 22), Pair(-2, 29), Pair(-3, 25), Pair(-4, 16), Pair(-3, 32)
      },
      { // Piece 4
        Pair(76, 32), Pair(-3, 61), Pair(84, 0), Pair(32, 24), Pair(-11, 24), Pair(2, 72), Pair(89, 17), Pair(-120, 195),
        Pair(38, 22), Pair(14, 72), Pair(56, -64), Pair(18, 29), Pair(0, 0), Pair(4, 87), Pair(52, -45), Pair(-6, 49),
        Pair(30, 2), Pair(-4, 78), Pair(21, 87), Pair(64, 24), Pair(51, 45), Pair(-65, -47), Pair(14, 65), Pair(-6, 119),
        Pair(24, 28), Pair(17, 65), Pair(31, -13), Pair(18, 22), Pair(39, 51), Pair(-7, 103), Pair(37, 22), Pair(12, 109),
        Pair(11, 44), Pair(13, 67), Pair(9, 71), Pair(17, 12), Pair(15, 40), Pair(18, 32), Pair(-9, 50), Pair(21, 47),
        Pair(19, 27), Pair(2, 46), Pair(5, 37), Pair(-5, 68), Pair(10, 33), Pair(7, 49), Pair(9, 28), Pair(22, -21),
        Pair(21, 41), Pair(5, 33), Pair(1, 51), Pair(-1, 54), Pair(16, 30), Pair(17, 10), Pair(-16, 87), Pair(20, 28),
        Pair(0, 80), Pair(6, 58), Pair(8, 51), Pair(3, 60), Pair(17, 50), Pair(31, 35), Pair(18, 10), Pair(42, -34)
      },
      { // Piece 5
        Pair(-15, 150), Pair(1, 34), Pair(-30, 15), Pair(6, 52), Pair(-15, -13), Pair(5, -134), Pair(17, 74), Pair(-4, 56),
        Pair(41, 125), Pair(-41, 60), Pair(34, -106), Pair(-45, -140), Pair(0, 0), Pair(113, -39), Pair(-148, -36), Pair(5, -24),
        Pair(-124, 8), Pair(-13, 67), Pair(-65, 2), Pair(0, 0), Pair(160, -96), Pair(0, 0), Pair(-6, -17), Pair(227, -47),
        Pair(129, -10), Pair(-23, 16), Pair(-209, 35), Pair(-25, -43), Pair(72, -51), Pair(109, -37), Pair(-115, 28), Pair(-96, 25),
        Pair(-95, 23), Pair(-81, 22), Pair(-12, 0), Pair(-66, 0), Pair(-14, -15), Pair(18, -8), Pair(-12, 6), Pair(-33, -4),
        Pair(25, 12), Pair(4, -1), Pair(-9, 26), Pair(5, -16), Pair(28, -21), Pair(-3, 0), Pair(28, -7), Pair(14, 5),
        Pair(-46, 24), Pair(-35, 37), Pair(-18, 33), Pair(6, 7), Pair(4, 4), Pair(27, -10), Pair(-1, 5), Pair(7, 1),
        Pair(-32, 46), Pair(-15, -7), Pair(-10, 4), Pair(44, -24), Pair(-4, -5), Pair(1, -4), Pair(-3, 9), Pair(-1, 9)
      }
    }},
    {{ // Bucket 53
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-3, 20), Pair(-5, 21), Pair(4, 17), Pair(4, 5), Pair(-18, 34), Pair(0, 0), Pair(-30, 8), Pair(-22, 22),
        Pair(5, 8), Pair(11, 12), Pair(2, 8), Pair(2, 4), Pair(10, 25), Pair(-25, -7), Pair(14, 19), Pair(6, 8),
        Pair(1, 5), Pair(6, 1), Pair(6, 7), Pair(5, 2), Pair(9, 13), Pair(-9, 0), Pair(-2, 6), Pair(-1, 5),
        Pair(9, 2), Pair(5, 2), Pair(5, 3), Pair(3, -3), Pair(4, 5), Pair(-8, -2), Pair(-1, 1), Pair(-5, 8),
        Pair(6, -2), Pair(8, 0), Pair(4, 1), Pair(5, 3), Pair(4, 8), Pair(-6, 4), Pair(-5, 4), Pair(-5, 4),
        Pair(4, 2), Pair(7, 0), Pair(4, -1), Pair(1, -2), Pair(3, 6), Pair(0, 0), Pair(-6, -2), Pair(-4, 8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-46, 68), Pair(-41, 107), Pair(-89, 95), Pair(-80, 75), Pair(-16, 88), Pair(-122, -3), Pair(-54, 128), Pair(84, -82),
        Pair(-25, 91), Pair(7, 70), Pair(-6, 59), Pair(-31, 62), Pair(-39, 75), Pair(0, 0), Pair(-42, 64), Pair(4, 76),
        Pair(-47, 86), Pair(18, 68), Pair(2, 70), Pair(3, 46), Pair(-309, 104), Pair(11, 95), Pair(-168, 95), Pair(-10, 55),
        Pair(2, 60), Pair(3, 67), Pair(-4, 54), Pair(-11, 77), Pair(-47, 50), Pair(11, 79), Pair(-32, 22), Pair(-2, 59),
        Pair(6, 46), Pair(-2, 70), Pair(-4, 70), Pair(-13, 59), Pair(-33, 59), Pair(-20, 46), Pair(-11, 62), Pair(-3, 38),
        Pair(12, 64), Pair(-2, 63), Pair(-1, 65), Pair(-15, 58), Pair(-5, 70), Pair(-5, 54), Pair(-12, 73), Pair(-14, 52),
        Pair(10, 56), Pair(-20, 96), Pair(3, 68), Pair(-4, 65), Pair(-9, 64), Pair(-6, 69), Pair(4, 68), Pair(-3, 68),
        Pair(-17, 63), Pair(8, 69), Pair(9, 52), Pair(6, 67), Pair(-3, 66), Pair(10, 58), Pair(-7, 67), Pair(10, 30)
      },
      { // Piece 2
        Pair(-29, 84), Pair(17, 78), Pair(-109, 93), Pair(-47, 106), Pair(-106, 71), Pair(-63, 79), Pair(-191, 4), Pair(-35, 108),
        Pair(-21, 92), Pair(-36, 82), Pair(5, 96), Pair(-67, 92), Pair(-29, 98), Pair(0, 0), Pair(-23, 92), Pair(8, 36),
        Pair(-21, 76), Pair(6, 93), Pair(-37, 78), Pair(-3, 90), Pair(-157, -77), Pair(19, 123), Pair(-138, -46), Pair(8, 67),
        Pair(0, 75), Pair(-29, 82), Pair(-17, 96), Pair(-32, 63), Pair(-39, 82), Pair(-26, 68), Pair(-15, 71), Pair(-19, 41),
        Pair(-12, 69), Pair(-4, 85), Pair(-31, 69), Pair(-8, 71), Pair(-50, 59), Pair(-4, 79), Pair(-43, 64), Pair(13, 62),
        Pair(-3, 71), Pair(-14, 65), Pair(-5, 80), Pair(-24, 59), Pair(-5, 75), Pair(-18, 63), Pair(-13, 79), Pair(-25, 49),
        Pair(-18, 65), Pair(2, 67), Pair(-28, 76), Pair(1, 73), Pair(-21, 68), Pair(-2, 80), Pair(-22, 54), Pair(-12, 96),
        Pair(-3, 72), Pair(-29, 98), Pair(6, 73), Pair(-14, 69), Pair(-3, 80), Pair(-11, 64), Pair(-14, 94), Pair(-21, 98)
      },
      { // Piece 3
        Pair(-27, 95), Pair(-25, 100), Pair(-40, 104), Pair(-24, 97), Pair(-21, 94), Pair(-121, 111), Pair(-17, 93), Pair(-8, 82),
        Pair(3, 84), Pair(-12, 87), Pair(-1, 86), Pair(-23, 96), Pair(-24, 96), Pair(0, 0), Pair(-28, 77), Pair(6, 80),
        Pair(11, 78), Pair(-10, 90), Pair(-9, 87), Pair(-3, 89), Pair(-219, 71), Pair(33, 65), Pair(51, -94), Pair(-12, 78),
        Pair(7, 79), Pair(-1, 83), Pair(0, 96), Pair(-2, 95), Pair(-19, 87), Pair(5, 77), Pair(0, 78), Pair(-10, 89),
        Pair(7, 88), Pair(3, 86), Pair(7, 78), Pair(-10, 86), Pair(-16, 66), Pair(2, 76), Pair(-12, 63), Pair(-8, 86),
        Pair(15, 76), Pair(7, 85), Pair(-6, 91), Pair(8, 83), Pair(-6, 83), Pair(9, 73), Pair(5, 74), Pair(7, 78),
        Pair(13, 89), Pair(4, 86), Pair(4, 90), Pair(10, 81), Pair(-2, 75), Pair(15, 67), Pair(17, 64), Pair(20, 75),
        Pair(9, 88), Pair(2, 89), Pair(5, 84), Pair(4, 85), Pair(3, 76), Pair(6, 82), Pair(4, 72), Pair(4, 77)
      },
      { // Piece 4
        Pair(-15, 148), Pair(55, 109), Pair(-2, 148), Pair(-12, 158), Pair(-8, 105), Pair(32, 36), Pair(-19, 182), Pair(-5, 181),
        Pair(19, 136), Pair(13, 139), Pair(17, 125), Pair(30, 96), Pair(4, 71), Pair(0, 0), Pair(-27, 201), Pair(9, 149),
        Pair(14, 129), Pair(9, 149), Pair(20, 132), Pair(19, 109), Pair(-75, 1), Pair(48, 85), Pair(-84, 187), Pair(36, 150),
        Pair(27, 118), Pair(21, 139), Pair(5, 158), Pair(15, 127), Pair(18, 141), Pair(30, 104), Pair(48, 133), Pair(37, 119),
        Pair(11, 134), Pair(17, 129), Pair(6, 152), Pair(23, 137), Pair(11, 139), Pair(30, 106), Pair(26, 147), Pair(21, 158),
        Pair(6, 137), Pair(6, 138), Pair(10, 137), Pair(5, 152), Pair(9, 135), Pair(31, 108), Pair(27, 145), Pair(27, 128),
        Pair(4, 134), Pair(18, 119), Pair(13, 122), Pair(13, 127), Pair(13, 131), Pair(27, 112), Pair(11, 170), Pair(55, 113),
        Pair(17, 125), Pair(14, 141), Pair(28, 114), Pair(15, 123), Pair(26, 116), Pair(25, 114), Pair(-4, 149), Pair(40, 156)
      },
      { // Piece 5
        Pair(-50, -35), Pair(144, -32), Pair(-16, 71), Pair(90, -100), Pair(-115, -48), Pair(102, -130), Pair(-26, -88), Pair(-64, -48),
        Pair(150, -28), Pair(43, 15), Pair(-34, 3), Pair(27, -38), Pair(-106, -37), Pair(0, 0), Pair(93, -76), Pair(-25, -9),
        Pair(78, -7), Pair(-50, 12), Pair(-47, 4), Pair(-86, -3), Pair(0, 0), Pair(-130, -48), Pair(0, 0), Pair(-26, -25),
        Pair(76, -19), Pair(-13, 11), Pair(25, -4), Pair(-19, -17), Pair(-27, -30), Pair(-50, -30), Pair(-8, -32), Pair(-49, -13),
        Pair(46, -15), Pair(57, -10), Pair(64, -13), Pair(-16, -4), Pair(-13, -19), Pair(-14, -21), Pair(-20, -10), Pair(-19, -1),
        Pair(31, 4), Pair(55, -13), Pair(13, 5), Pair(23, 1), Pair(2, -10), Pair(14, -12), Pair(-4, -8), Pair(16, 2),
        Pair(1, 10), Pair(-3, 8), Pair(6, 8), Pair(7, 5), Pair(-1, 3), Pair(8, 2), Pair(-3, 2), Pair(2, 5),
        Pair(-9, 5), Pair(-16, 13), Pair(-13, 15), Pair(-2, 14), Pair(-5, -5), Pair(-4, 4), Pair(-12, -12), Pair(13, -4)
      }
    }},
    {{ // Bucket 54
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(5, 19), Pair(20, 17), Pair(16, 13), Pair(3, 14), Pair(11, -7), Pair(-24, 9), Pair(0, 0), Pair(-25, 14),
        Pair(5, 7), Pair(6, 7), Pair(7, 7), Pair(-9, 13), Pair(-5, 4), Pair(-26, 29), Pair(-2, -10), Pair(4, 22),
        Pair(2, 7), Pair(8, 3), Pair(5, 7), Pair(-2, 7), Pair(-1, 4), Pair(-2, 14), Pair(5, -3), Pair(14, 14),
        Pair(5, 2), Pair(7, 4), Pair(4, 3), Pair(0, 2), Pair(3, 4), Pair(3, 8), Pair(-5, -2), Pair(-1, 7),
        Pair(2, -2), Pair(0, -3), Pair(-1, 0), Pair(0, 1), Pair(-2, -1), Pair(0, 8), Pair(-4, 3), Pair(-6, 6),
        Pair(0, 0), Pair(4, -2), Pair(0, 0), Pair(1, 3), Pair(-2, -2), Pair(4, 1), Pair(0, 0), Pair(-7, -1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-45, 46), Pair(-118, 92), Pair(-97, 79), Pair(-169, 115), Pair(-82, 29), Pair(-30, 86), Pair(17, -16), Pair(-37, 78),
        Pair(7, 43), Pair(18, 54), Pair(3, 45), Pair(-14, 26), Pair(-17, 50), Pair(34, 34), Pair(0, 0), Pair(-20, 1),
        Pair(-33, 52), Pair(19, 49), Pair(-4, 50), Pair(-9, 49), Pair(-10, 37), Pair(-424, 249), Pair(16, 93), Pair(-78, 114),
        Pair(9, 38), Pair(11, 40), Pair(-1, 51), Pair(9, 37), Pair(-3, 50), Pair(-44, 46), Pair(-8, 66), Pair(-18, 13),
        Pair(4, 57), Pair(11, 48), Pair(6, 48), Pair(-6, 52), Pair(7, 38), Pair(-34, 43), Pair(9, 9), Pair(-22, 52),
        Pair(11, 48), Pair(1, 58), Pair(3, 50), Pair(-4, 46), Pair(-10, 47), Pair(2, 48), Pair(-8, 42), Pair(-5, 57),
        Pair(-8, 56), Pair(14, 40), Pair(2, 42), Pair(1, 47), Pair(-3, 48), Pair(-2, 31), Pair(18, 42), Pair(4, 50),
        Pair(20, 27), Pair(8, 57), Pair(1, 61), Pair(5, 53), Pair(18, 44), Pair(10, 44), Pair(9, 44), Pair(-33, 45)
      },
      { // Piece 2
        Pair(-21, 101), Pair(-10, 70), Pair(-46, 88), Pair(-117, 92), Pair(-93, 107), Pair(-158, 66), Pair(150, 60), Pair(7, 0),
        Pair(-45, 71), Pair(9, 79), Pair(-18, 68), Pair(-55, 99), Pair(-62, 67), Pair(-19, 90), Pair(0, 0), Pair(-6, 48),
        Pair(-3, 85), Pair(-36, 69), Pair(15, 81), Pair(-34, 67), Pair(-4, 85), Pair(-271, 28), Pair(7, 106), Pair(-62, -35),
        Pair(-26, 62), Pair(5, 73), Pair(-20, 58), Pair(-3, 85), Pair(-12, 37), Pair(-52, 87), Pair(6, 41), Pair(-26, 70),
        Pair(7, 73), Pair(-18, 60), Pair(3, 80), Pair(-19, 41), Pair(-5, 62), Pair(-29, 40), Pair(-11, 75), Pair(-34, 39),
        Pair(-17, 52), Pair(14, 68), Pair(-15, 40), Pair(-4, 69), Pair(-16, 52), Pair(4, 69), Pair(-13, 52), Pair(0, 69),
        Pair(-6, 98), Pair(-10, 31), Pair(11, 60), Pair(-14, 47), Pair(4, 66), Pair(-19, 60), Pair(9, 66), Pair(-17, 56),
        Pair(-22, 54), Pair(-1, 59), Pair(-8, 46), Pair(1, 71), Pair(-13, 51), Pair(9, 74), Pair(-1, 45), Pair(-6, 104)
      },
      { // Piece 3
        Pair(7, 82), Pair(0, 91), Pair(-33, 104), Pair(-15, 93), Pair(9, 78), Pair(-4, 82), Pair(21, 88), Pair(-70, 113),
        Pair(0, 81), Pair(12, 81), Pair(-13, 96), Pair(-12, 89), Pair(-23, 98), Pair(-24, 83), Pair(0, 0), Pair(-11, 57),
        Pair(7, 77), Pair(-9, 82), Pair(1, 76), Pair(-6, 82), Pair(-2, 71), Pair(-46, 10), Pair(2, 101), Pair(256, -152),
        Pair(22, 71), Pair(-11, 85), Pair(12, 82), Pair(2, 79), Pair(0, 82), Pair(-9, 73), Pair(-17, 82), Pair(-3, 75),
        Pair(8, 72), Pair(-1, 87), Pair(6, 73), Pair(-4, 85), Pair(2, 71), Pair(-13, 60), Pair(-23, 74), Pair(14, 42),
        Pair(10, 81), Pair(12, 74), Pair(8, 76), Pair(4, 80), Pair(4, 79), Pair(18, 59), Pair(16, 55), Pair(3, 70),
        Pair(19, 85), Pair(14, 80), Pair(17, 74), Pair(9, 80), Pair(25, 67), Pair(18, 66), Pair(11, 61), Pair(31, 65),
        Pair(17, 81), Pair(10, 77), Pair(10, 78), Pair(7, 78), Pair(8, 75), Pair(8, 69), Pair(10, 64), Pair(-1, 72)
      },
      { // Piece 4
        Pair(-32, 152), Pair(-66, 164), Pair(-22, 178), Pair(6, 123), Pair(4, 158), Pair(-10, 128), Pair(-56, 134), Pair(-39, 105),
        Pair(13, 101), Pair(-4, 129), Pair(-16, 142), Pair(-37, 153), Pair(-29, 148), Pair(38, 32), Pair(0, 0), Pair(57, 75),
        Pair(12, 94), Pair(22, 113), Pair(-15, 129), Pair(2, 102), Pair(13, 88), Pair(-18, -153), Pair(33, 77), Pair(-8, -77),
        Pair(10, 122), Pair(-9, 124), Pair(-3, 133), Pair(-7, 141), Pair(-12, 117), Pair(-12, 138), Pair(-1, 78), Pair(5, 120),
        Pair(4, 110), Pair(-6, 147), Pair(5, 122), Pair(-5, 134), Pair(-10, 139), Pair(6, 124), Pair(-2, 105), Pair(13, 124),
        Pair(-5, 143), Pair(-9, 140), Pair(1, 124), Pair(-8, 141), Pair(-12, 133), Pair(-2, 137), Pair(18, 95), Pair(21, 100),
        Pair(10, 108), Pair(-2, 126), Pair(-2, 105), Pair(-3, 128), Pair(-5, 123), Pair(-2, 122), Pair(6, 108), Pair(8, 148),
        Pair(-4, 111), Pair(5, 94), Pair(8, 108), Pair(1, 117), Pair(5, 126), Pair(-8, 145), Pair(24, 72), Pair(12, 118)
      },
      { // Piece 5
        Pair(32, -16), Pair(181, 19), Pair(7, -32), Pair(6, 30), Pair(111, -14), Pair(67, 2), Pair(189, -24), Pair(27, 41),
        Pair(-187, 21), Pair(119, -21), Pair(50, 19), Pair(99, 1), Pair(15, -7), Pair(-73, -48), Pair(0, 0), Pair(36, -95),
        Pair(145, -7), Pair(136, -21), Pair(-13, 11), Pair(-11, 25), Pair(-50, -5), Pair(0, 0), Pair(-31, -50), Pair(0, 0),
        Pair(-59, 7), Pair(73, 4), Pair(40, -5), Pair(40, -3), Pair(-92, 11), Pair(-55, -6), Pair(-33, -13), Pair(1, -14),
        Pair(76, -1), Pair(67, -7), Pair(42, 1), Pair(-2, -1), Pair(24, -5), Pair(15, -4), Pair(-35, 2), Pair(-14, 3),
        Pair(89, -20), Pair(48, -8), Pair(38, -9), Pair(24, 6), Pair(4, 3), Pair(10, 0), Pair(-6, -4), Pair(-12, 10),
        Pair(17, -6), Pair(15, -4), Pair(12, 6), Pair(14, 6), Pair(5, 14), Pair(19, 0), Pair(-1, 7), Pair(1, 4),
        Pair(-6, 27), Pair(-15, 0), Pair(-8, 12), Pair(9, 9), Pair(3, 12), Pair(1, 7), Pair(-10, 13), Pair(-3, -2)
      }
    }},
    {{ // Bucket 55
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(20, 12), Pair(15, 15), Pair(36, 8), Pair(-6, 15), Pair(-5, 13), Pair(-8, 13), Pair(-28, 14), Pair(0, 0),
        Pair(0, 12), Pair(1, 10), Pair(9, 6), Pair(4, 5), Pair(-13, 6), Pair(-26, 13), Pair(-6, 10), Pair(4, -26),
        Pair(2, 6), Pair(2, 4), Pair(4, 5), Pair(-2, 4), Pair(-7, 2), Pair(-8, 4), Pair(-3, 5), Pair(8, -5),
        Pair(5, 3), Pair(2, -3), Pair(2, -1), Pair(1, 0), Pair(-2, 3), Pair(1, 2), Pair(-1, 1), Pair(-2, -2),
        Pair(2, 0), Pair(-2, -5), Pair(-4, -3), Pair(-4, -2), Pair(4, 2), Pair(3, 2), Pair(0, 4), Pair(0, 2),
        Pair(1, 3), Pair(-2, -7), Pair(-2, -5), Pair(0, -2), Pair(1, 4), Pair(9, 1), Pair(1, -4), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-20, 41), Pair(21, 23), Pair(-32, 35), Pair(62, 48), Pair(-79, 116), Pair(-119, 34), Pair(-124, 59), Pair(-43, -84),
        Pair(8, 58), Pair(1, 38), Pair(4, 42), Pair(10, 38), Pair(4, 46), Pair(23, 59), Pair(14, 41), Pair(0, 0),
        Pair(51, 20), Pair(1, 46), Pair(2, 52), Pair(11, 44), Pair(-17, 50), Pair(4, 52), Pair(-114, -35), Pair(30, 80),
        Pair(6, 44), Pair(15, 45), Pair(17, 45), Pair(12, 45), Pair(2, 45), Pair(7, 52), Pair(-19, 46), Pair(17, 69),
        Pair(11, 39), Pair(12, 37), Pair(8, 38), Pair(11, 43), Pair(5, 47), Pair(19, 43), Pair(-15, 53), Pair(-8, 22),
        Pair(8, 46), Pair(12, 36), Pair(11, 40), Pair(5, 33), Pair(12, 38), Pair(5, 45), Pair(5, 56), Pair(1, 70),
        Pair(27, 9), Pair(12, 46), Pair(-5, 49), Pair(7, 40), Pair(6, 43), Pair(8, 41), Pair(19, 40), Pair(10, 52),
        Pair(23, -11), Pair(4, 54), Pair(-15, 58), Pair(23, 26), Pair(10, 42), Pair(7, 47), Pair(1, 52), Pair(30, 73)
      },
      { // Piece 2
        Pair(-41, 103), Pair(-106, 102), Pair(-92, 96), Pair(-66, 89), Pair(-168, 84), Pair(-88, 113), Pair(-110, 113), Pair(-5, 55),
        Pair(-11, 84), Pair(9, 77), Pair(-18, 89), Pair(-107, 132), Pair(-33, 94), Pair(-42, 91), Pair(-23, 76), Pair(0, 0),
        Pair(-10, 84), Pair(2, 69), Pair(-21, 82), Pair(-11, 93), Pair(-13, 74), Pair(-19, 83), Pair(-47, -93), Pair(20, 105),
        Pair(-9, 75), Pair(-4, 64), Pair(-3, 78), Pair(2, 74), Pair(2, 80), Pair(-16, 72), Pair(-16, 70), Pair(1, 73),
        Pair(2, 61), Pair(-7, 72), Pair(-7, 70), Pair(-1, 65), Pair(-9, 64), Pair(1, 73), Pair(-9, 52), Pair(-7, 69),
        Pair(8, 66), Pair(8, 74), Pair(5, 72), Pair(-8, 62), Pair(5, 64), Pair(2, 68), Pair(3, 69), Pair(4, 73),
        Pair(3, 85), Pair(10, 60), Pair(-12, 50), Pair(-4, 65), Pair(-2, 65), Pair(5, 65), Pair(10, 59), Pair(21, 43),
        Pair(18, 63), Pair(-1, 51), Pair(2, 62), Pair(-5, 66), Pair(4, 55), Pair(4, 72), Pair(-3, 72), Pair(-2, 82)
      },
      { // Piece 3
        Pair(-1, 110), Pair(-12, 120), Pair(-14, 117), Pair(-13, 116), Pair(-43, 123), Pair(-7, 114), Pair(32, 115), Pair(-124, 150),
        Pair(10, 111), Pair(2, 112), Pair(-4, 111), Pair(9, 112), Pair(23, 102), Pair(20, 115), Pair(45, 109), Pair(0, 0),
        Pair(8, 105), Pair(-1, 115), Pair(3, 112), Pair(1, 110), Pair(9, 108), Pair(-48, 127), Pair(-9, -160), Pair(0, 113),
        Pair(10, 111), Pair(14, 107), Pair(15, 112), Pair(8, 101), Pair(9, 106), Pair(7, 105), Pair(-4, 117), Pair(-10, 108),
        Pair(20, 96), Pair(21, 99), Pair(16, 102), Pair(-2, 106), Pair(13, 105), Pair(1, 100), Pair(-39, 100), Pair(-16, 90),
        Pair(6, 109), Pair(24, 99), Pair(17, 93), Pair(13, 98), Pair(8, 95), Pair(11, 97), Pair(-2, 97), Pair(-26, 103),
        Pair(41, 85), Pair(15, 100), Pair(23, 100), Pair(22, 99), Pair(10, 103), Pair(14, 97), Pair(5, 115), Pair(12, 102),
        Pair(16, 106), Pair(11, 107), Pair(14, 103), Pair(12, 103), Pair(13, 99), Pair(12, 97), Pair(-17, 107), Pair(-2, 99)
      },
      { // Piece 4
        Pair(-23, 241), Pair(-27, 251), Pair(16, 201), Pair(-33, 242), Pair(-7, 199), Pair(10, 229), Pair(164, 117), Pair(-96, 267),
        Pair(-1, 208), Pair(2, 211), Pair(-1, 214), Pair(-40, 248), Pair(-23, 248), Pair(-35, 266), Pair(-15, 241), Pair(0, 0),
        Pair(22, 188), Pair(5, 207), Pair(-10, 220), Pair(-10, 211), Pair(-8, 245), Pair(-27, 245), Pair(-99, 137), Pair(20, 146),
        Pair(4, 201), Pair(-3, 217), Pair(-4, 220), Pair(-4, 218), Pair(-4, 226), Pair(-11, 210), Pair(-29, 216), Pair(-21, 202),
        Pair(3, 212), Pair(-2, 192), Pair(0, 180), Pair(-5, 211), Pair(-2, 213), Pair(4, 190), Pair(-1, 170), Pair(-15, 195),
        Pair(-5, 228), Pair(2, 195), Pair(5, 194), Pair(3, 194), Pair(1, 192), Pair(-5, 196), Pair(1, 200), Pair(-6, 181),
        Pair(11, 192), Pair(14, 168), Pair(6, 170), Pair(6, 174), Pair(1, 179), Pair(6, 198), Pair(20, 160), Pair(29, 114),
        Pair(9, 173), Pair(0, 192), Pair(15, 175), Pair(9, 167), Pair(12, 170), Pair(-9, 214), Pair(-13, 225), Pair(12, 190)
      },
      { // Piece 5
        Pair(16, 48), Pair(98, 27), Pair(195, -52), Pair(-110, -38), Pair(-125, 81), Pair(50, -50), Pair(-27, -16), Pair(-21, 37),
        Pair(-154, 19), Pair(150, -33), Pair(-62, 33), Pair(-122, 14), Pair(-45, 31), Pair(-156, -43), Pair(-141, -49), Pair(0, 0),
        Pair(23, -8), Pair(2, 5), Pair(-29, 4), Pair(-49, 8), Pair(-76, 4), Pair(-88, -2), Pair(0, 0), Pair(48, -35),
        Pair(145, -40), Pair(7, -9), Pair(50, -14), Pair(-7, 5), Pair(42, -5), Pair(-40, -8), Pair(-41, 0), Pair(-36, 11),
        Pair(46, -5), Pair(64, -17), Pair(38, -11), Pair(44, -7), Pair(19, 0), Pair(-40, 11), Pair(-20, -8), Pair(-4, -16),
        Pair(46, -10), Pair(70, -22), Pair(39, -11), Pair(57, -6), Pair(40, -7), Pair(-9, 12), Pair(21, -6), Pair(10, -2),
        Pair(23, -9), Pair(-9, -4), Pair(16, -4), Pair(12, 3), Pair(13, 5), Pair(26, 5), Pair(5, 9), Pair(2, 10),
        Pair(13, 7), Pair(-8, -3), Pair(-1, 5), Pair(40, 0), Pair(10, 13), Pair(7, 17), Pair(1, 18), Pair(-3, 29)
      }
    }},
    {{ // Bucket 56
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 5
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
    {{ // Bucket 57
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 5
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
    {{ // Bucket 58
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 5
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
    {{ // Bucket 59
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 5
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
    {{ // Bucket 60
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 5
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
    {{ // Bucket 61
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 5
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
    {{ // Bucket 62
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 5
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
    {{ // Bucket 63
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 5
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
  }},
  {{ // Bucket 1
    {{ // Bucket 0
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 5
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
    {{ // Bucket 1
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 5
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
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 5
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
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 5
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
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 5
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
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 5
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
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 5
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
    {{ // Bucket 7
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 5
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
    {{ // Bucket 8
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-12, 22), Pair(-68, 53), Pair(8, 56), Pair(4, 34), Pair(45, 65), Pair(-93, 30), Pair(-7, 22), Pair(116, 30),
        Pair(-37, -91), Pair(-38, 12), Pair(-10, 31), Pair(-41, 46), Pair(-134, 56), Pair(-38, 36), Pair(-32, 12), Pair(-31, 29),
        Pair(-16, 0), Pair(8, 36), Pair(37, 9), Pair(0, 19), Pair(23, 24), Pair(3, 18), Pair(-23, 22), Pair(25, 4),
        Pair(-26, 17), Pair(-9, 31), Pair(4, 9), Pair(-6, 14), Pair(-22, 19), Pair(2, 11), Pair(-17, 17), Pair(16, 10),
        Pair(-4, 42), Pair(-16, 28), Pair(11, 18), Pair(-6, 8), Pair(-15, 16), Pair(17, 1), Pair(-16, 17), Pair(-7, 23),
        Pair(1, 1), Pair(-11, 30), Pair(-9, 21), Pair(8, -14), Pair(-20, 28), Pair(5, 21), Pair(-14, 31), Pair(-12, 25),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-125, 64), Pair(26, 114), Pair(175, 27), Pair(48, 88), Pair(103, 22), Pair(-102, 35), Pair(8, 44), Pair(-4, -31),
        Pair(0, 0), Pair(6, 16), Pair(-37, 108), Pair(60, -67), Pair(-44, 53), Pair(-135, 46), Pair(-4, 128), Pair(-153, 50),
        Pair(76, 135), Pair(-24, 81), Pair(63, 28), Pair(147, 4), Pair(95, -39), Pair(46, -6), Pair(166, 44), Pair(10, 52),
        Pair(-24, 41), Pair(40, 50), Pair(64, 18), Pair(-14, 121), Pair(33, 29), Pair(72, -24), Pair(-5, 12), Pair(111, -17),
        Pair(-49, 78), Pair(22, 33), Pair(88, 8), Pair(56, 31), Pair(66, -25), Pair(-10, 27), Pair(-36, 9), Pair(7, -32),
        Pair(68, 15), Pair(75, -34), Pair(-6, 56), Pair(104, -43), Pair(-52, 25), Pair(70, -38), Pair(50, 28), Pair(19, 24),
        Pair(119, 62), Pair(-87, 75), Pair(160, -29), Pair(-1, 2), Pair(20, 12), Pair(75, 13), Pair(44, -8), Pair(106, 3),
        Pair(-85, -29), Pair(-59, 90), Pair(-1, 45), Pair(-31, 52), Pair(76, -25), Pair(1, -32), Pair(-118, 82), Pair(117, -52)
      },
      { // Piece 2
        Pair(80, -110), Pair(231, 8), Pair(-43, 41), Pair(183, -92), Pair(14, 5), Pair(42, -26), Pair(139, 29), Pair(-127, -132),
        Pair(0, 0), Pair(-37, 149), Pair(243, -33), Pair(3, -5), Pair(84, -82), Pair(66, -20), Pair(471, -132), Pair(4, -41),
        Pair(192, -22), Pair(159, 16), Pair(152, 63), Pair(132, -27), Pair(56, -42), Pair(195, -64), Pair(245, -50), Pair(-7, -9),
        Pair(81, -18), Pair(2, 50), Pair(141, 1), Pair(23, 59), Pair(194, -63), Pair(-88, 36), Pair(93, -81), Pair(-5, 1),
        Pair(-54, 78), Pair(113, -34), Pair(27, 33), Pair(117, 4), Pair(-17, 109), Pair(-19, -3), Pair(-6, 49), Pair(127, -99),
        Pair(51, -59), Pair(73, -56), Pair(-12, -7), Pair(36, 4), Pair(50, 1), Pair(31, 26), Pair(61, -11), Pair(11, 65),
        Pair(33, -82), Pair(58, -50), Pair(-121, 56), Pair(26, -8), Pair(68, 43), Pair(87, 2), Pair(73, 27), Pair(-89, 0),
        Pair(-39, -1), Pair(-35, 10), Pair(47, 1), Pair(115, -50), Pair(40, -8), Pair(49, 29), Pair(107, -2), Pair(33, 105)
      },
      { // Piece 3
        Pair(64, -160), Pair(59, 167), Pair(-22, 81), Pair(-71, 56), Pair(-109, 110), Pair(-88, 83), Pair(-166, 144), Pair(-117, 126),
        Pair(0, 0), Pair(193, 9), Pair(128, 9), Pair(144, 6), Pair(199, -19), Pair(158, 7), Pair(77, 31), Pair(105, 27),
        Pair(-8, 53), Pair(63, 61), Pair(-13, 101), Pair(-12, 68), Pair(-53, 117), Pair(104, 78), Pair(22, 109), Pair(33, 84),
        Pair(-19, 91), Pair(-13, 104), Pair(102, 37), Pair(138, 27), Pair(76, 62), Pair(-12, 81), Pair(-134, 114), Pair(-234, 190),
        Pair(1, 67), Pair(65, 95), Pair(-68, 118), Pair(158, 6), Pair(-14, 76), Pair(122, -30), Pair(22, 141), Pair(-10, 44),
        Pair(3, 51), Pair(-11, 58), Pair(134, 34), Pair(-80, 105), Pair(-68, 135), Pair(27, 13), Pair(-23, 89), Pair(26, 55),
        Pair(83, 5), Pair(45, 55), Pair(-45, 88), Pair(3, 77), Pair(55, 67), Pair(-65, 61), Pair(-3, 61), Pair(30, 8),
        Pair(10, 30), Pair(99, 36), Pair(88, -1), Pair(66, 11), Pair(11, 58), Pair(5, 55), Pair(54, 74), Pair(-8, 59)
      },
      { // Piece 4
        Pair(-89, -222), Pair(162, -79), Pair(73, 122), Pair(-24, 66), Pair(-15, 152), Pair(11, -7), Pair(128, 5), Pair(-84, 28),
        Pair(0, 0), Pair(44, 133), Pair(-65, 120), Pair(196, -20), Pair(7, 29), Pair(-193, 125), Pair(62, -4), Pair(108, -22),
        Pair(76, 50), Pair(-20, 127), Pair(51, 42), Pair(46, 15), Pair(144, -97), Pair(-4, 98), Pair(198, -88), Pair(46, 17),
        Pair(-57, 75), Pair(47, 79), Pair(-34, 31), Pair(-83, 199), Pair(44, 57), Pair(91, -147), Pair(11, -66), Pair(-16, -101),
        Pair(-4, 87), Pair(-44, 152), Pair(-41, 59), Pair(48, 30), Pair(115, -232), Pair(33, -8), Pair(-58, 85), Pair(118, 38),
        Pair(-13, 88), Pair(40, 41), Pair(-52, 78), Pair(39, -25), Pair(18, 80), Pair(-13, 101), Pair(80, -2), Pair(185, -105),
        Pair(40, -11), Pair(60, -23), Pair(11, -23), Pair(10, -30), Pair(51, -3), Pair(49, -66), Pair(-71, 109), Pair(17, -95),
        Pair(42, -27), Pair(-71, 43), Pair(42, -58), Pair(11, 117), Pair(110, -107), Pair(132, -96), Pair(88, -32), Pair(-50, -13)
      },
      { // Piece 5
        Pair(-55, -203), Pair(-131, 71), Pair(-14, 148), Pair(-3, 57), Pair(31, 18), Pair(70, -15), Pair(-23, -3), Pair(23, 153),
        Pair(0, 0), Pair(0, 129), Pair(-120, 81), Pair(137, 20), Pair(160, 30), Pair(-105, -51), Pair(109, -9), Pair(4, 26),
        Pair(-56, 36), Pair(62, 64), Pair(132, 50), Pair(-158, 49), Pair(-160, 23), Pair(63, -13), Pair(-50, -9), Pair(7, 53),
        Pair(47, 24), Pair(10, 74), Pair(4, 20), Pair(-67, 66), Pair(167, -41), Pair(54, 9), Pair(-30, -20), Pair(-225, 31),
        Pair(-298, 106), Pair(87, 60), Pair(45, 14), Pair(27, -4), Pair(36, -14), Pair(12, -25), Pair(-18, -32), Pair(-71, -27),
        Pair(-226, 98), Pair(30, 14), Pair(117, -1), Pair(-48, 4), Pair(73, -23), Pair(49, -39), Pair(6, -53), Pair(-28, -43),
        Pair(-33, 64), Pair(104, -10), Pair(55, -23), Pair(-109, 21), Pair(-31, -10), Pair(-2, -19), Pair(20, -46), Pair(-45, -33),
        Pair(-141, -54), Pair(114, -44), Pair(-22, -18), Pair(-58, 12), Pair(-21, -17), Pair(45, -76), Pair(6, -47), Pair(-28, -46)
      }
    }},
    {{ // Bucket 9
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-68, 53), Pair(3, 43), Pair(74, -8), Pair(-24, 29), Pair(-29, 36), Pair(-99, 20), Pair(-50, 46), Pair(43, 7),
        Pair(-23, 11), Pair(-34, -98), Pair(26, -21), Pair(-13, 46), Pair(-47, 33), Pair(29, 45), Pair(-3, 53), Pair(25, 25),
        Pair(-4, 47), Pair(17, -13), Pair(-4, 30), Pair(-11, 22), Pair(17, 18), Pair(-18, 15), Pair(-23, 32), Pair(15, 3),
        Pair(3, 45), Pair(-19, -7), Pair(-20, 31), Pair(-20, 19), Pair(-17, 17), Pair(-14, 20), Pair(17, 5), Pair(5, 20),
        Pair(-19, 32), Pair(-30, 15), Pair(-44, 16), Pair(-25, 17), Pair(-12, 14), Pair(-38, 15), Pair(4, 7), Pair(-10, 25),
        Pair(-9, 36), Pair(-17, 7), Pair(-51, 26), Pair(-18, -2), Pair(14, 6), Pair(-12, 23), Pair(-4, 21), Pair(-23, 29),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-62, -47), Pair(-12, 119), Pair(12, 60), Pair(68, 2), Pair(-72, -52), Pair(5, 62), Pair(-94, -162), Pair(-33, -71),
        Pair(-86, 91), Pair(0, 0), Pair(132, -1), Pair(28, 114), Pair(39, 14), Pair(-173, 89), Pair(-22, 82), Pair(69, 27),
        Pair(90, 97), Pair(14, 62), Pair(206, 59), Pair(26, 2), Pair(162, 32), Pair(-59, 17), Pair(-181, 82), Pair(66, -10),
        Pair(48, 46), Pair(-41, 57), Pair(57, 19), Pair(-4, 60), Pair(24, 68), Pair(-212, 92), Pair(-146, 60), Pair(60, 53),
        Pair(-29, 83), Pair(126, 74), Pair(73, 45), Pair(8, 48), Pair(84, 18), Pair(-21, 22), Pair(15, -14), Pair(-78, 34),
        Pair(-18, -53), Pair(-21, 29), Pair(41, 40), Pair(35, 27), Pair(49, 24), Pair(44, 50), Pair(-15, 75), Pair(-26, 116),
        Pair(20, -10), Pair(177, 2), Pair(-131, 21), Pair(2, 28), Pair(-29, 50), Pair(38, 58), Pair(-57, 14), Pair(76, -8),
        Pair(-61, -2), Pair(-23, 144), Pair(35, 43), Pair(41, 22), Pair(-117, 11), Pair(10, -17), Pair(-28, -83), Pair(53, -35)
      },
      { // Piece 2
        Pair(-90, -197), Pair(99, -108), Pair(200, -10), Pair(-26, 77), Pair(84, -87), Pair(-2, 105), Pair(71, -14), Pair(78, 112),
        Pair(167, 14), Pair(0, 0), Pair(133, 73), Pair(155, -110), Pair(74, 26), Pair(40, -72), Pair(-201, 136), Pair(46, -92),
        Pair(37, 18), Pair(150, 78), Pair(219, -53), Pair(-27, 120), Pair(109, -81), Pair(337, 20), Pair(183, -119), Pair(10, 38),
        Pair(105, 6), Pair(94, -44), Pair(51, 73), Pair(115, -2), Pair(81, 9), Pair(226, -81), Pair(2, 60), Pair(212, -115),
        Pair(129, -93), Pair(68, 15), Pair(82, -47), Pair(-38, 56), Pair(124, -15), Pair(-39, 142), Pair(14, -26), Pair(115, 48),
        Pair(-8, 65), Pair(17, -78), Pair(-30, 47), Pair(96, -66), Pair(19, 10), Pair(106, -29), Pair(153, 16), Pair(50, -31),
        Pair(149, -98), Pair(4, 61), Pair(-12, -42), Pair(-16, 31), Pair(8, 21), Pair(126, -38), Pair(84, -21), Pair(-70, 100),
        Pair(-116, 127), Pair(140, -115), Pair(21, 11), Pair(69, -47), Pair(-6, -10), Pair(93, -24), Pair(169, -76), Pair(119, 4)
      },
      { // Piece 3
        Pair(25, 88), Pair(54, -193), Pair(207, 58), Pair(12, 104), Pair(-41, 56), Pair(-61, 91), Pair(70, 32), Pair(38, 98),
        Pair(-7, 54), Pair(0, 0), Pair(53, 33), Pair(156, -12), Pair(275, -66), Pair(-21, 62), Pair(-71, 60), Pair(71, 20),
        Pair(-34, 62), Pair(17, 22), Pair(13, 72), Pair(84, 6), Pair(-136, 71), Pair(68, 59), Pair(157, 4), Pair(33, 31),
        Pair(80, 46), Pair(143, 18), Pair(16, 78), Pair(18, 96), Pair(-4, 48), Pair(-100, 125), Pair(123, 29), Pair(-57, 75),
        Pair(-67, 121), Pair(94, 28), Pair(31, 61), Pair(27, 59), Pair(91, 28), Pair(96, 37), Pair(-23, 88), Pair(-91, 91),
        Pair(-51, 126), Pair(-63, 50), Pair(17, 74), Pair(137, 23), Pair(-35, 79), Pair(-103, 85), Pair(-110, 116), Pair(-188, 17),
        Pair(103, -3), Pair(11, 51), Pair(4, 40), Pair(43, 60), Pair(87, 39), Pair(-10, 16), Pair(77, 13), Pair(47, 25),
        Pair(2, 62), Pair(7, 21), Pair(-17, 59), Pair(-3, 120), Pair(-11, 81), Pair(10, 49), Pair(54, 5), Pair(-50, 46)
      },
      { // Piece 4
        Pair(103, -145), Pair(-48, -92), Pair(132, -26), Pair(190, 44), Pair(-5, -9), Pair(43, -20), Pair(-93, -89), Pair(114, 19),
        Pair(-14, 44), Pair(0, 0), Pair(25, 53), Pair(-48, 61), Pair(70, -1), Pair(155, -159), Pair(-105, -68), Pair(104, -134),
        Pair(27, 50), Pair(63, 56), Pair(-1, 64), Pair(201, 51), Pair(-46, 89), Pair(23, -23), Pair(-93, -4), Pair(-130, 70),
        Pair(112, -19), Pair(-160, 199), Pair(-76, 121), Pair(18, 124), Pair(54, 92), Pair(173, 40), Pair(-107, 90), Pair(85, -111),
        Pair(106, -12), Pair(-45, 19), Pair(3, 181), Pair(80, -7), Pair(-15, 40), Pair(-34, 28), Pair(75, -82), Pair(-89, -110),
        Pair(211, -336), Pair(-7, 101), Pair(-47, 48), Pair(-15, 80), Pair(158, -120), Pair(-17, 63), Pair(-123, 178), Pair(-96, 19),
        Pair(-18, 54), Pair(-35, 35), Pair(4, 52), Pair(-59, 91), Pair(22, 0), Pair(157, -87), Pair(74, 3), Pair(-36, -41),
        Pair(58, -196), Pair(-65, 146), Pair(89, -157), Pair(-64, 167), Pair(-99, 75), Pair(-112, 82), Pair(5, -49), Pair(150, 3)
      },
      { // Piece 5
        Pair(-6, 219), Pair(98, 23), Pair(86, 48), Pair(149, 153), Pair(-23, -29), Pair(-10, 5), Pair(-6, -34), Pair(0, 25),
        Pair(-55, 179), Pair(0, 0), Pair(76, 108), Pair(-65, 78), Pair(136, -23), Pair(42, -13), Pair(-41, 26), Pair(-12, -59),
        Pair(-53, 108), Pair(100, 39), Pair(177, 15), Pair(-29, 49), Pair(115, -34), Pair(0, 26), Pair(-3, -45), Pair(-50, 51),
        Pair(86, 89), Pair(56, 8), Pair(92, 36), Pair(124, -3), Pair(14, -26), Pair(92, -30), Pair(-164, 22), Pair(-27, 18),
        Pair(87, -10), Pair(176, -35), Pair(91, 10), Pair(74, -44), Pair(123, -50), Pair(-189, 20), Pair(-185, -5), Pair(-121, 2),
        Pair(18, -7), Pair(35, -43), Pair(6, -37), Pair(20, -28), Pair(-61, -24), Pair(-79, -24), Pair(-112, -39), Pair(-170, -30),
        Pair(-5, -23), Pair(137, 33), Pair(-32, 25), Pair(-54, 7), Pair(-65, -15), Pair(-195, 20), Pair(-45, -31), Pair(-36, -57),
        Pair(11, 53), Pair(0, -17), Pair(102, 42), Pair(69, -47), Pair(-84, -43), Pair(-133, -2), Pair(-70, -57), Pair(-70, -52)
      }
    }},
    {{ // Bucket 10
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(9, 56), Pair(74, -8), Pair(-12, 55), Pair(73, 19), Pair(-108, 43), Pair(65, 37), Pair(-49, 0), Pair(76, -35),
        Pair(-35, 27), Pair(-27, 28), Pair(-44, -98), Pair(-13, 21), Pair(-6, 3), Pair(-92, 48), Pair(-184, 50), Pair(129, -17),
        Pair(-21, 19), Pair(-50, 54), Pair(-92, 17), Pair(-33, 54), Pair(-13, 20), Pair(2, 21), Pair(-14, 22), Pair(14, 15),
        Pair(9, 16), Pair(-15, 28), Pair(-34, -5), Pair(-14, 25), Pair(-17, 24), Pair(18, 8), Pair(6, 7), Pair(13, 6),
        Pair(20, 13), Pair(-51, 22), Pair(-48, 10), Pair(-4, 9), Pair(18, 4), Pair(-11, 6), Pair(9, 8), Pair(4, 16),
        Pair(-27, 29), Pair(-11, 13), Pair(-31, -8), Pair(-9, -37), Pair(7, 33), Pair(-9, 8), Pair(10, 6), Pair(-13, 20),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(226, -68), Pair(77, 112), Pair(-14, -40), Pair(17, 75), Pair(179, 57), Pair(-89, -16), Pair(5, -54), Pair(24, 28),
        Pair(-8, 95), Pair(188, 1), Pair(0, 0), Pair(85, -47), Pair(130, 121), Pair(-166, 89), Pair(87, -11), Pair(-163, -56),
        Pair(48, 37), Pair(-16, 5), Pair(202, 49), Pair(12, 84), Pair(58, 16), Pair(68, 31), Pair(124, 3), Pair(-58, 83),
        Pair(79, 20), Pair(34, 45), Pair(-130, 120), Pair(186, 11), Pair(-35, 54), Pair(-39, 110), Pair(-35, 78), Pair(2, 26),
        Pair(68, 88), Pair(40, 51), Pair(-1, 39), Pair(42, 23), Pair(-22, 45), Pair(74, 33), Pair(-57, 88), Pair(46, 114),
        Pair(78, 22), Pair(-23, 48), Pair(99, 55), Pair(-23, 91), Pair(-12, 41), Pair(39, -3), Pair(117, -37), Pair(20, 76),
        Pair(149, 16), Pair(-74, 65), Pair(126, 29), Pair(-3, -6), Pair(-18, 39), Pair(81, -16), Pair(-18, 4), Pair(4, -1),
        Pair(-126, -25), Pair(-61, 8), Pair(-27, 74), Pair(-1, -43), Pair(-33, 35), Pair(-55, 44), Pair(36, -117), Pair(38, 23)
      },
      { // Piece 2
        Pair(-87, 119), Pair(122, -30), Pair(-89, 8), Pair(376, -48), Pair(-13, 93), Pair(218, 2), Pair(-35, 35), Pair(14, -29),
        Pair(219, -8), Pair(-197, 176), Pair(0, 0), Pair(-2, -10), Pair(107, -43), Pair(152, 9), Pair(105, -15), Pair(112, 40),
        Pair(227, 79), Pair(179, -26), Pair(49, 113), Pair(132, -18), Pair(109, 91), Pair(231, -76), Pair(109, -8), Pair(-31, -72),
        Pair(7, 52), Pair(54, 55), Pair(227, -65), Pair(42, 20), Pair(172, -8), Pair(261, -10), Pair(118, 69), Pair(-61, 99),
        Pair(-74, 6), Pair(99, -12), Pair(-6, 38), Pair(152, -27), Pair(87, 28), Pair(122, 2), Pair(2, 38), Pair(66, -70),
        Pair(23, 5), Pair(8, -28), Pair(39, -2), Pair(-91, 57), Pair(140, -27), Pair(71, 23), Pair(117, -7), Pair(208, 18),
        Pair(125, -74), Pair(141, -61), Pair(-41, -1), Pair(-40, -3), Pair(14, 47), Pair(43, 15), Pair(26, 46), Pair(-10, 57),
        Pair(-59, -45), Pair(-147, 22), Pair(-2, 29), Pair(17, 47), Pair(126, 5), Pair(-50, 81), Pair(61, -40), Pair(148, 40)
      },
      { // Piece 3
        Pair(-61, 112), Pair(-33, 197), Pair(151, -178), Pair(210, 66), Pair(83, -2), Pair(86, 43), Pair(39, 134), Pair(190, 6),
        Pair(15, 79), Pair(4, 57), Pair(0, 0), Pair(23, 36), Pair(-43, 71), Pair(82, 34), Pair(62, 100), Pair(172, 24),
        Pair(63, 44), Pair(19, 105), Pair(53, 46), Pair(85, 31), Pair(-68, 99), Pair(-4, 68), Pair(-97, 100), Pair(-71, 169),
        Pair(-25, 115), Pair(16, 92), Pair(92, 58), Pair(-28, 85), Pair(-9, 100), Pair(-67, 106), Pair(26, 60), Pair(107, 19),
        Pair(64, 46), Pair(63, 101), Pair(75, 43), Pair(-91, 85), Pair(44, 53), Pair(61, 9), Pair(153, 66), Pair(-58, 81),
        Pair(-13, 64), Pair(109, 80), Pair(117, 42), Pair(37, 64), Pair(96, 25), Pair(43, 42), Pair(-30, 56), Pair(-45, 179),
        Pair(-163, 94), Pair(57, 57), Pair(89, 29), Pair(-53, 94), Pair(81, 37), Pair(-127, 109), Pair(-39, 63), Pair(-60, 23),
        Pair(-16, 37), Pair(39, 63), Pair(29, 42), Pair(14, 69), Pair(89, 6), Pair(16, 30), Pair(-10, 28), Pair(20, 13)
      },
      { // Piece 4
        Pair(-159, 36), Pair(34, -55), Pair(-30, -247), Pair(-33, -12), Pair(76, 29), Pair(51, 24), Pair(-69, -165), Pair(28, -26),
        Pair(45, -38), Pair(-55, 73), Pair(0, 0), Pair(19, 61), Pair(-11, 27), Pair(78, -115), Pair(58, 71), Pair(-4, -29),
        Pair(52, -72), Pair(15, 65), Pair(-40, 120), Pair(-7, 120), Pair(38, -77), Pair(95, 17), Pair(-113, 19), Pair(34, -93),
        Pair(82, -28), Pair(-157, 275), Pair(41, 70), Pair(-22, 67), Pair(0, 76), Pair(90, -60), Pair(112, -23), Pair(17, -86),
        Pair(20, -134), Pair(72, -24), Pair(-10, 50), Pair(-16, 39), Pair(-160, 124), Pair(83, -54), Pair(-62, 78), Pair(-13, 132),
        Pair(15, 121), Pair(-19, 35), Pair(65, -24), Pair(-13, -104), Pair(26, 0), Pair(20, -15), Pair(46, -111), Pair(202, 4),
        Pair(-50, -59), Pair(-2, 17), Pair(5, -72), Pair(32, -1), Pair(-46, 64), Pair(94, -86), Pair(55, -146), Pair(77, 22),
        Pair(-22, 44), Pair(-20, 30), Pair(-20, -45), Pair(-66, 3), Pair(70, -197), Pair(-160, 53), Pair(-56, 139), Pair(-43, -28)
      },
      { // Piece 5
        Pair(11, 172), Pair(143, 70), Pair(-63, 36), Pair(-97, 40), Pair(-34, 166), Pair(68, -14), Pair(43, 115), Pair(12, 50),
        Pair(-101, 203), Pair(59, 125), Pair(0, 0), Pair(-8, 91), Pair(-47, 20), Pair(-7, -38), Pair(-51, -38), Pair(18, 56),
        Pair(86, 84), Pair(45, 102), Pair(116, 37), Pair(256, 43), Pair(-89, 46), Pair(150, -56), Pair(123, -18), Pair(3, -40),
        Pair(187, 31), Pair(202, 45), Pair(89, 29), Pair(171, 3), Pair(80, -16), Pair(112, -18), Pair(-146, 10), Pair(68, -11),
        Pair(90, 71), Pair(95, -12), Pair(86, -18), Pair(-121, 11), Pair(-34, -14), Pair(59, -39), Pair(-51, -29), Pair(-9, -58),
        Pair(-329, 28), Pair(-157, 65), Pair(17, -41), Pair(-23, -4), Pair(-28, -8), Pair(-148, -20), Pair(2, -62), Pair(-126, -45),
        Pair(-91, -36), Pair(151, -60), Pair(35, 2), Pair(-35, -15), Pair(2, -67), Pair(-51, -44), Pair(-43, -36), Pair(-36, -34),
        Pair(-57, -1), Pair(81, 21), Pair(-168, -28), Pair(-99, 78), Pair(-113, -48), Pair(-132, -32), Pair(-49, -52), Pair(0, -42)
      }
    }},
    {{ // Bucket 11
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(4, 34), Pair(-24, 29), Pair(73, 19), Pair(43, 2), Pair(-7, 2), Pair(-78, 47), Pair(114, -30), Pair(-192, 82),
        Pair(17, 28), Pair(-98, 35), Pair(77, -5), Pair(-53, -59), Pair(-20, 24), Pair(42, 30), Pair(-63, 44), Pair(-45, 31),
        Pair(18, 11), Pair(16, 19), Pair(2, 61), Pair(9, -6), Pair(-3, 50), Pair(22, 27), Pair(32, 11), Pair(50, 5),
        Pair(7, 13), Pair(-16, 28), Pair(4, 16), Pair(-9, 15), Pair(-31, 26), Pair(-6, 9), Pair(32, 11), Pair(-14, 12),
        Pair(-1, 12), Pair(-5, 7), Pair(35, -1), Pair(-32, 17), Pair(-14, 8), Pair(4, 5), Pair(-1, 9), Pair(-9, 9),
        Pair(-10, 17), Pair(-9, 9), Pair(1, -3), Pair(-56, 55), Pair(-12, -1), Pair(-15, 16), Pair(6, 15), Pair(-12, 18),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-109, -40), Pair(9, 23), Pair(42, 124), Pair(-154, -45), Pair(42, 20), Pair(105, 152), Pair(-12, -12), Pair(-3, -8),
        Pair(16, 32), Pair(26, 164), Pair(-85, 111), Pair(0, 0), Pair(3, 115), Pair(-29, 163), Pair(104, 65), Pair(-117, 114),
        Pair(-46, -10), Pair(97, 18), Pair(8, 55), Pair(113, 40), Pair(79, 111), Pair(173, -18), Pair(28, 130), Pair(80, -79),
        Pair(-82, 100), Pair(43, 51), Pair(60, 50), Pair(107, 10), Pair(36, 76), Pair(90, 4), Pair(66, -41), Pair(-27, 29),
        Pair(44, 106), Pair(72, 88), Pair(46, 74), Pair(69, 90), Pair(29, 47), Pair(-78, 43), Pair(15, 54), Pair(72, 5),
        Pair(19, 65), Pair(27, 22), Pair(35, 3), Pair(125, 45), Pair(49, 41), Pair(52, -17), Pair(9, 52), Pair(56, -2),
        Pair(91, -19), Pair(-31, -78), Pair(19, 14), Pair(-13, 43), Pair(5, 124), Pair(99, 20), Pair(-73, 80), Pair(84, 128),
        Pair(4, 19), Pair(54, -24), Pair(111, 127), Pair(-9, 68), Pair(-45, 31), Pair(-33, 40), Pair(57, -29), Pair(18, -36)
      },
      { // Piece 2
        Pair(197, -40), Pair(26, -11), Pair(86, -4), Pair(-268, -89), Pair(-34, 22), Pair(-119, 33), Pair(30, -61), Pair(-51, 15),
        Pair(-108, 158), Pair(213, 26), Pair(-49, 114), Pair(0, 0), Pair(193, 35), Pair(112, -105), Pair(189, 34), Pair(-44, -27),
        Pair(59, 2), Pair(-39, 195), Pair(76, -1), Pair(195, 35), Pair(141, -14), Pair(225, 47), Pair(18, -32), Pair(316, 10),
        Pair(13, 161), Pair(103, -20), Pair(-16, 92), Pair(-9, 18), Pair(-32, 68), Pair(135, -13), Pair(53, 161), Pair(96, -15),
        Pair(48, -1), Pair(91, 53), Pair(30, 20), Pair(76, 84), Pair(49, -32), Pair(-43, 110), Pair(68, 28), Pair(185, 115),
        Pair(175, -40), Pair(-8, -51), Pair(124, -20), Pair(40, -9), Pair(4, 68), Pair(-35, 13), Pair(100, -25), Pair(53, 6),
        Pair(-107, 6), Pair(88, -55), Pair(-50, -39), Pair(-84, 124), Pair(11, -18), Pair(-46, 45), Pair(77, -8), Pair(70, 0),
        Pair(39, 22), Pair(-34, -41), Pair(62, 35), Pair(142, -37), Pair(28, 83), Pair(87, -38), Pair(174, -142), Pair(196, -60)
      },
      { // Piece 3
        Pair(-8, 78), Pair(-9, 120), Pair(36, 101), Pair(46, -119), Pair(110, 82), Pair(-74, 87), Pair(112, 61), Pair(108, 129),
        Pair(-8, 65), Pair(38, 50), Pair(5, 53), Pair(0, 0), Pair(98, 20), Pair(9, 33), Pair(-176, 130), Pair(-27, 30),
        Pair(24, 57), Pair(12, 70), Pair(25, 56), Pair(35, 34), Pair(-154, 171), Pair(40, 32), Pair(-73, 63), Pair(-21, 57),
        Pair(37, 73), Pair(197, 23), Pair(134, -3), Pair(64, 54), Pair(-98, 131), Pair(24, 104), Pair(183, -5), Pair(63, 71),
        Pair(64, 18), Pair(-77, 104), Pair(47, 61), Pair(-17, 67), Pair(-119, 99), Pair(-64, 77), Pair(108, 70), Pair(-90, 94),
        Pair(-60, 57), Pair(-199, 196), Pair(-12, 80), Pair(6, 45), Pair(-2, 105), Pair(-6, 70), Pair(-78, 59), Pair(-102, 70),
        Pair(28, 22), Pair(-13, 49), Pair(-137, 137), Pair(54, -6), Pair(-18, 98), Pair(-41, 72), Pair(-83, 70), Pair(68, 70),
        Pair(-81, 78), Pair(34, 58), Pair(31, 55), Pair(47, 32), Pair(16, 76), Pair(-51, 77), Pair(-83, 98), Pair(-63, 57)
      },
      { // Piece 4
        Pair(-39, 136), Pair(-8, 53), Pair(-31, 70), Pair(-154, -137), Pair(66, -69), Pair(-11, 25), Pair(-54, -9), Pair(-86, -59),
        Pair(39, 149), Pair(2, 39), Pair(-13, 95), Pair(0, 0), Pair(76, -20), Pair(172, -6), Pair(-88, -132), Pair(128, -132),
        Pair(58, 16), Pair(-62, 96), Pair(101, -49), Pair(59, -19), Pair(-8, 31), Pair(78, 3), Pair(13, 61), Pair(-91, -11),
        Pair(67, -68), Pair(55, 108), Pair(105, -132), Pair(29, 7), Pair(-100, 68), Pair(107, -32), Pair(-54, 120), Pair(16, 135),
        Pair(-115, 41), Pair(-35, 65), Pair(24, 51), Pair(56, 17), Pair(69, 94), Pair(-73, 184), Pair(50, -74), Pair(123, -45),
        Pair(-65, -8), Pair(-33, 108), Pair(77, -28), Pair(16, 73), Pair(-21, 36), Pair(-33, 61), Pair(-13, 16), Pair(-91, 17),
        Pair(39, -77), Pair(-112, 110), Pair(-20, 92), Pair(-56, 111), Pair(-23, 129), Pair(53, -1), Pair(23, -65), Pair(44, -74),
        Pair(180, -105), Pair(112, -66), Pair(-105, 72), Pair(98, -101), Pair(-24, -42), Pair(-59, -110), Pair(19, -121), Pair(13, -57)
      },
      { // Piece 5
        Pair(-23, 81), Pair(61, 201), Pair(11, 125), Pair(174, -16), Pair(-38, 52), Pair(-14, 165), Pair(-9, -82), Pair(6, 196),
        Pair(-3, -3), Pair(5, 27), Pair(202, 92), Pair(0, 0), Pair(-76, 159), Pair(3, 39), Pair(22, -95), Pair(30, 46),
        Pair(23, 111), Pair(15, 66), Pair(62, 64), Pair(64, 55), Pair(104, 42), Pair(15, 22), Pair(-93, -7), Pair(-75, 2),
        Pair(201, -69), Pair(138, -34), Pair(162, -10), Pair(103, 12), Pair(175, -12), Pair(63, -40), Pair(35, -10), Pair(88, -62),
        Pair(-86, 60), Pair(-29, 42), Pair(25, 6), Pair(36, 6), Pair(195, -64), Pair(7, -24), Pair(-91, 8), Pair(-168, -1),
        Pair(64, -95), Pair(78, -47), Pair(17, -57), Pair(13, -21), Pair(-87, -28), Pair(-46, -31), Pair(-49, -27), Pair(-65, -33),
        Pair(25, -41), Pair(-53, -1), Pair(-13, -44), Pair(-127, 21), Pair(-147, -7), Pair(-59, -46), Pair(-68, -31), Pair(-58, -31),
        Pair(152, -103), Pair(16, -82), Pair(-62, 23), Pair(2, -33), Pair(-125, 39), Pair(-38, -52), Pair(-26, -65), Pair(-64, -27)
      }
    }},
    {{ // Bucket 12
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(45, 65), Pair(-29, 36), Pair(-108, 43), Pair(-7, 2), Pair(6, 27), Pair(93, -49), Pair(-61, 52), Pair(93, 50),
        Pair(-46, 42), Pair(-42, 16), Pair(-130, 68), Pair(-4, 16), Pair(109, -66), Pair(109, -27), Pair(15, 28), Pair(6, -3),
        Pair(7, 14), Pair(9, 4), Pair(24, 30), Pair(32, 37), Pair(23, -3), Pair(-19, 43), Pair(23, 21), Pair(-8, 1),
        Pair(2, -1), Pair(69, -9), Pair(1, 19), Pair(-8, 20), Pair(-93, 22), Pair(3, 4), Pair(8, 10), Pair(-23, 11),
        Pair(-3, 9), Pair(-15, 20), Pair(-6, 9), Pair(1, 15), Pair(7, -14), Pair(-15, 31), Pair(10, 12), Pair(-14, 4),
        Pair(-5, 18), Pair(15, -3), Pair(11, -1), Pair(-105, 60), Pair(-5, 0), Pair(11, 7), Pair(16, 1), Pair(-29, 12),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(56, 35), Pair(-187, 22), Pair(126, 8), Pair(202, 129), Pair(-5, -73), Pair(290, 43), Pair(67, 59), Pair(-28, -55),
        Pair(-242, 13), Pair(-223, 237), Pair(183, -23), Pair(172, 81), Pair(0, 0), Pair(-101, 137), Pair(-1, 87), Pair(29, -101),
        Pair(88, 99), Pair(-13, 40), Pair(44, 11), Pair(-17, 81), Pair(147, 54), Pair(86, 78), Pair(167, -24), Pair(-25, -5),
        Pair(-260, 172), Pair(109, 79), Pair(-70, 70), Pair(32, 58), Pair(46, 3), Pair(71, 41), Pair(-67, 25), Pair(269, 2),
        Pair(-116, -52), Pair(-20, -66), Pair(33, 34), Pair(35, 31), Pair(-18, 114), Pair(22, 67), Pair(30, 26), Pair(69, -2),
        Pair(-34, -70), Pair(-115, 20), Pair(-38, 70), Pair(35, 18), Pair(123, 33), Pair(-42, 35), Pair(124, 45), Pair(123, -108),
        Pair(106, -44), Pair(1, -90), Pair(31, -58), Pair(9, -2), Pair(72, 41), Pair(9, -25), Pair(137, 67), Pair(-24, -20),
        Pair(-6, -1), Pair(-76, 4), Pair(-2, 107), Pair(181, -36), Pair(-78, 6), Pair(14, -30), Pair(105, 43), Pair(-21, -3)
      },
      { // Piece 2
        Pair(186, 42), Pair(-104, -49), Pair(-21, 30), Pair(251, -73), Pair(68, 50), Pair(90, -53), Pair(-161, -34), Pair(-22, -16),
        Pair(9, 3), Pair(103, 6), Pair(12, -13), Pair(230, 128), Pair(0, 0), Pair(13, 90), Pair(99, 2), Pair(181, -5),
        Pair(-122, 120), Pair(61, -55), Pair(-71, 153), Pair(244, -55), Pair(-78, 44), Pair(-40, 18), Pair(17, 94), Pair(-4, -29),
        Pair(21, -17), Pair(-144, 91), Pair(61, -21), Pair(-123, 104), Pair(265, -88), Pair(109, -34), Pair(79, -1), Pair(-46, 84),
        Pair(-176, 62), Pair(151, -30), Pair(-21, 72), Pair(84, -11), Pair(169, -31), Pair(24, -6), Pair(20, -52), Pair(21, -3),
        Pair(82, -25), Pair(29, -25), Pair(103, -80), Pair(9, 12), Pair(73, -13), Pair(158, 14), Pair(116, -120), Pair(6, -7),
        Pair(-130, 181), Pair(-30, -17), Pair(281, -123), Pair(15, -10), Pair(57, 8), Pair(24, -15), Pair(42, 31), Pair(-81, -17),
        Pair(199, -87), Pair(3, 47), Pair(-1, 38), Pair(-101, -37), Pair(6, 73), Pair(47, -2), Pair(180, -142), Pair(-197, 102)
      },
      { // Piece 3
        Pair(-166, 136), Pair(70, 23), Pair(-72, 113), Pair(15, 68), Pair(-151, -96), Pair(226, 44), Pair(89, -14), Pair(101, 26),
        Pair(-65, 49), Pair(-73, 33), Pair(-21, -1), Pair(63, 17), Pair(0, 0), Pair(88, 17), Pair(-15, 47), Pair(-118, 55),
        Pair(7, 24), Pair(112, 30), Pair(-6, 26), Pair(80, 16), Pair(120, -34), Pair(50, 8), Pair(-103, 36), Pair(0, 23),
        Pair(-17, 32), Pair(106, -53), Pair(-18, 60), Pair(8, 19), Pair(97, 1), Pair(2, 92), Pair(-99, 120), Pair(41, 67),
        Pair(160, 13), Pair(16, 39), Pair(-147, 71), Pair(-135, 41), Pair(-25, 32), Pair(96, -49), Pair(-36, 35), Pair(-55, 25),
        Pair(64, -35), Pair(69, 13), Pair(72, 128), Pair(93, 47), Pair(-57, 45), Pair(-12, 36), Pair(-21, 60), Pair(-74, 8),
        Pair(132, 12), Pair(89, 42), Pair(28, 16), Pair(-27, 14), Pair(32, 9), Pair(2, 130), Pair(-133, 95), Pair(-110, 92),
        Pair(-66, 6), Pair(11, -1), Pair(66, -23), Pair(37, -35), Pair(-2, 33), Pair(-7, 30), Pair(-7, -2), Pair(-4, 0)
      },
      { // Piece 4
        Pair(-39, -95), Pair(185, 150), Pair(0, 60), Pair(-27, -8), Pair(-271, -134), Pair(-47, -40), Pair(-49, -122), Pair(-47, -67),
        Pair(38, -79), Pair(-56, 42), Pair(-60, -7), Pair(9, -68), Pair(0, 0), Pair(113, -131), Pair(-50, -65), Pair(-134, 72),
        Pair(-21, 182), Pair(113, 13), Pair(55, -40), Pair(14, -85), Pair(11, -77), Pair(52, -35), Pair(87, 100), Pair(17, 25),
        Pair(-141, -111), Pair(-28, 77), Pair(23, -17), Pair(115, -73), Pair(-54, -24), Pair(73, -123), Pair(-27, 15), Pair(37, 12),
        Pair(-152, 64), Pair(91, -67), Pair(18, 48), Pair(148, -97), Pair(56, -90), Pair(-32, 74), Pair(173, -210), Pair(126, -170),
        Pair(-72, -140), Pair(-187, 64), Pair(-5, -10), Pair(22, 27), Pair(-141, 119), Pair(-42, -8), Pair(-49, -93), Pair(-71, -61),
        Pair(-46, -55), Pair(-35, -103), Pair(-101, -84), Pair(34, -59), Pair(-39, -63), Pair(38, 26), Pair(-29, -36), Pair(-26, -73),
        Pair(-52, 12), Pair(159, -128), Pair(-131, -110), Pair(-170, 100), Pair(-68, -102), Pair(-48, 9), Pair(-7, -27), Pair(50, 6)
      },
      { // Piece 5
        Pair(80, 20), Pair(-25, -131), Pair(-10, 63), Pair(-86, 64), Pair(8, -69), Pair(83, 93), Pair(61, 93), Pair(9, 81),
        Pair(-115, -6), Pair(12, -22), Pair(-4, 88), Pair(-126, 138), Pair(0, 0), Pair(27, 116), Pair(136, 85), Pair(59, 67),
        Pair(-51, -38), Pair(154, -75), Pair(1, 49), Pair(14, 21), Pair(166, 22), Pair(61, 33), Pair(115, 18), Pair(86, -60),
        Pair(-139, -64), Pair(-19, 0), Pair(103, 38), Pair(-6, 46), Pair(-81, 46), Pair(24, 2), Pair(77, -13), Pair(-90, -50),
        Pair(-98, 67), Pair(89, -7), Pair(-99, 62), Pair(206, -39), Pair(-66, 34), Pair(43, -15), Pair(19, -23), Pair(-41, -22),
        Pair(-75, -37), Pair(-70, 10), Pair(204, -81), Pair(-195, 69), Pair(-93, -4), Pair(-36, -28), Pair(4, -27), Pair(33, -65),
        Pair(-284, 24), Pair(40, -5), Pair(-53, 29), Pair(78, -82), Pair(-194, 18), Pair(-44, -53), Pair(44, -91), Pair(93, -67),
        Pair(-112, 49), Pair(-33, -4), Pair(-113, -18), Pair(27, 58), Pair(-16, -58), Pair(-77, -37), Pair(16, -63), Pair(63, -98)
      }
    }},
    {{ // Bucket 13
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-93, 30), Pair(-99, 20), Pair(65, 37), Pair(-78, 47), Pair(93, -49), Pair(19, 1), Pair(43, 16), Pair(6, 32),
        Pair(117, -6), Pair(-47, 65), Pair(-4, 66), Pair(6, 37), Pair(-49, 17), Pair(2, -73), Pair(47, -15), Pair(40, -4),
        Pair(15, 33), Pair(-30, 26), Pair(-82, 59), Pair(22, -15), Pair(-21, 35), Pair(-15, -3), Pair(-20, 30), Pair(14, 4),
        Pair(-14, 16), Pair(65, -2), Pair(26, 12), Pair(-44, 40), Pair(-16, -5), Pair(-36, 0), Pair(-14, 18), Pair(-31, 13),
        Pair(-22, 20), Pair(11, 1), Pair(-9, -7), Pair(17, -8), Pair(-29, 14), Pair(-2, -15), Pair(-33, 21), Pair(-11, 10),
        Pair(1, 9), Pair(11, 15), Pair(-23, 24), Pair(1, -17), Pair(-53, 68), Pair(-30, 16), Pair(7, 0), Pair(3, 12),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-1, 101), Pair(21, -5), Pair(-11, 68), Pair(166, -21), Pair(84, 78), Pair(127, -3), Pair(132, -37), Pair(-35, -122),
        Pair(14, 112), Pair(-34, 10), Pair(49, -39), Pair(-72, 21), Pair(-129, 0), Pair(0, 0), Pair(103, 14), Pair(0, 69),
        Pair(19, 49), Pair(-13, 41), Pair(-203, 115), Pair(89, -34), Pair(140, -75), Pair(-14, -11), Pair(213, 124), Pair(71, -33),
        Pair(-100, -84), Pair(-179, 16), Pair(-128, 81), Pair(-6, 35), Pair(146, -18), Pair(-48, 37), Pair(77, -7), Pair(148, -1),
        Pair(68, 48), Pair(-105, 1), Pair(27, 1), Pair(67, -29), Pair(-9, 23), Pair(28, -35), Pair(-22, -12), Pair(81, -122),
        Pair(-64, -4), Pair(37, -47), Pair(27, -25), Pair(-40, 56), Pair(-127, 61), Pair(-38, 64), Pair(11, -40), Pair(-9, 67),
        Pair(44, 91), Pair(146, 38), Pair(24, -119), Pair(-62, -60), Pair(65, -39), Pair(-136, -37), Pair(160, -93), Pair(-42, -160),
        Pair(-9, 15), Pair(88, 59), Pair(-22, 71), Pair(101, -51), Pair(-283, -60), Pair(-217, 82), Pair(-30, 182), Pair(25, -75)
      },
      { // Piece 2
        Pair(-43, -91), Pair(-32, 75), Pair(-114, 9), Pair(1, 8), Pair(69, -7), Pair(-116, 78), Pair(163, 8), Pair(-26, 11),
        Pair(11, 29), Pair(120, -15), Pair(95, 133), Pair(167, -114), Pair(-131, 104), Pair(0, 0), Pair(148, -17), Pair(280, -118),
        Pair(-62, -66), Pair(-48, 2), Pair(10, -53), Pair(222, 82), Pair(128, -52), Pair(51, 42), Pair(104, -48), Pair(71, -12),
        Pair(-39, 43), Pair(-12, -33), Pair(-131, 51), Pair(50, -24), Pair(-15, 6), Pair(-22, -31), Pair(-94, 62), Pair(80, -11),
        Pair(-71, -24), Pair(-169, 93), Pair(38, -26), Pair(291, 46), Pair(-19, -15), Pair(78, 117), Pair(115, -144), Pair(108, -11),
        Pair(3, 20), Pair(98, -21), Pair(-35, 46), Pair(-35, -45), Pair(55, 93), Pair(157, -46), Pair(28, 45), Pair(151, -32),
        Pair(-164, 2), Pair(4, 40), Pair(-10, -40), Pair(110, -1), Pair(1, 34), Pair(60, 61), Pair(22, -68), Pair(214, -17),
        Pair(26, 6), Pair(43, -7), Pair(8, 54), Pair(-77, 37), Pair(171, -29), Pair(-94, -28), Pair(80, -6), Pair(183, -142)
      },
      { // Piece 3
        Pair(46, 71), Pair(-64, 43), Pair(235, 30), Pair(111, 68), Pair(46, 84), Pair(-1, -119), Pair(-146, 100), Pair(106, 27),
        Pair(-27, 16), Pair(30, 14), Pair(59, 3), Pair(32, 47), Pair(50, 18), Pair(0, 0), Pair(-86, 63), Pair(-32, 10),
        Pair(37, 27), Pair(136, -40), Pair(-17, -16), Pair(-21, -106), Pair(-92, 64), Pair(157, -58), Pair(158, -29), Pair(-13, 35),
        Pair(103, 4), Pair(297, -83), Pair(7, -18), Pair(86, 27), Pair(35, 72), Pair(81, 23), Pair(38, -87), Pair(44, 43),
        Pair(113, -13), Pair(19, 45), Pair(17, -11), Pair(69, 47), Pair(55, 32), Pair(93, 21), Pair(-49, 18), Pair(-9, 30),
        Pair(12, -46), Pair(-140, 67), Pair(-119, -38), Pair(2, 27), Pair(-85, 38), Pair(2, 43), Pair(-36, 33), Pair(42, -16),
        Pair(24, -26), Pair(-99, 71), Pair(-23, 63), Pair(-190, 83), Pair(-2, 156), Pair(14, 19), Pair(29, 8), Pair(120, -41),
        Pair(-81, 54), Pair(7, 2), Pair(-49, 37), Pair(-39, 18), Pair(14, 11), Pair(1, 17), Pair(11, 1), Pair(-25, 71)
      },
      { // Piece 4
        Pair(-59, -9), Pair(-125, -178), Pair(-67, -196), Pair(-10, 33), Pair(118, -104), Pair(-141, -200), Pair(-73, -149), Pair(37, -111),
        Pair(0, 4), Pair(45, 122), Pair(-163, 77), Pair(-56, 165), Pair(84, -157), Pair(0, 0), Pair(49, -92), Pair(-102, 131),
        Pair(31, -125), Pair(200, -354), Pair(70, -63), Pair(-1, -84), Pair(21, 112), Pair(41, -156), Pair(-77, -25), Pair(-39, -60),
        Pair(109, -92), Pair(-33, -121), Pair(92, -67), Pair(24, -79), Pair(103, -7), Pair(16, -132), Pair(83, -311), Pair(3, 92),
        Pair(-40, 4), Pair(-120, -91), Pair(66, -92), Pair(25, 39), Pair(-27, -110), Pair(12, 201), Pair(-29, 75), Pair(70, 71),
        Pair(-15, -18), Pair(-191, -10), Pair(30, -5), Pair(105, -154), Pair(10, -119), Pair(-8, -43), Pair(-82, -45), Pair(-151, -10),
        Pair(-52, -125), Pair(54, -69), Pair(-70, -11), Pair(47, -37), Pair(-40, -42), Pair(43, -51), Pair(-180, 200), Pair(-2, -102),
        Pair(147, 49), Pair(-129, 36), Pair(-89, 87), Pair(-43, -63), Pair(78, -25), Pair(-96, 12), Pair(-64, -73), Pair(-68, -7)
      },
      { // Piece 5
        Pair(-35, -71), Pair(-5, -36), Pair(9, -120), Pair(83, 39), Pair(68, 80), Pair(78, -10), Pair(64, 113), Pair(-21, 82),
        Pair(7, 16), Pair(-43, -32), Pair(12, -3), Pair(124, 53), Pair(30, 110), Pair(0, 0), Pair(58, 93), Pair(-25, 127),
        Pair(39, -10), Pair(37, -34), Pair(26, 25), Pair(-103, 39), Pair(35, 72), Pair(-24, 35), Pair(234, 29), Pair(83, 46),
        Pair(5, 138), Pair(-104, -21), Pair(-63, 37), Pair(128, -58), Pair(31, 46), Pair(81, 6), Pair(61, 46), Pair(45, 34),
        Pair(-38, 18), Pair(-139, -21), Pair(-144, -13), Pair(-56, -12), Pair(-30, -13), Pair(66, -13), Pair(199, -13), Pair(-33, 10),
        Pair(-44, 18), Pair(-105, -28), Pair(73, -74), Pair(250, -67), Pair(-33, -28), Pair(46, -23), Pair(-125, 15), Pair(37, -27),
        Pair(-26, -59), Pair(-205, 46), Pair(144, -38), Pair(-111, 23), Pair(5, -36), Pair(-12, 6), Pair(45, -83), Pair(26, -50),
        Pair(-232, -65), Pair(-27, -27), Pair(-3, -39), Pair(-109, 19), Pair(-109, -19), Pair(-89, 16), Pair(0, -60), Pair(-41, 37)
      }
    }},
    {{ // Bucket 14
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-7, 22), Pair(-50, 46), Pair(-49, 0), Pair(114, -30), Pair(-61, 52), Pair(43, 16), Pair(-36, 41), Pair(-44, -56),
        Pair(-16, 30), Pair(-15, 72), Pair(-50, 33), Pair(102, -14), Pair(-17, 27), Pair(27, -19), Pair(89, -129), Pair(87, -43),
        Pair(60, 10), Pair(-14, 19), Pair(52, 0), Pair(-13, 7), Pair(27, -6), Pair(-18, 27), Pair(9, -15), Pair(1, 29),
        Pair(-10, 20), Pair(18, 17), Pair(7, 9), Pair(7, 5), Pair(13, 27), Pair(-9, 15), Pair(26, -31), Pair(6, 8),
        Pair(7, 2), Pair(20, 15), Pair(0, 4), Pair(31, -28), Pair(1, 4), Pair(13, 16), Pair(8, -15), Pair(-14, 14),
        Pair(-2, 20), Pair(13, 8), Pair(-21, 17), Pair(19, -5), Pair(-45, 29), Pair(4, 13), Pair(-5, -5), Pair(-17, 24),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(34, 54), Pair(28, 44), Pair(3, -70), Pair(-58, 67), Pair(162, 17), Pair(-276, 113), Pair(111, -42), Pair(-12, 1),
        Pair(-93, -3), Pair(-133, 108), Pair(61, -19), Pair(32, -23), Pair(191, 40), Pair(203, -92), Pair(0, 0), Pair(220, -124),
        Pair(72, 26), Pair(-22, -9), Pair(-45, 70), Pair(69, -10), Pair(147, -93), Pair(74, 23), Pair(38, -13), Pair(113, 51),
        Pair(-31, -75), Pair(121, 76), Pair(25, -19), Pair(94, 111), Pair(17, 23), Pair(148, 5), Pair(4, -22), Pair(22, -1),
        Pair(-97, 73), Pair(115, 81), Pair(63, -15), Pair(-41, -11), Pair(76, 8), Pair(-64, -13), Pair(93, 16), Pair(33, -51),
        Pair(-51, 84), Pair(-42, 91), Pair(45, -50), Pair(-58, -48), Pair(6, 112), Pair(-34, 9), Pair(-84, 43), Pair(148, -167),
        Pair(179, 10), Pair(77, 15), Pair(-19, 2), Pair(-52, 33), Pair(-23, 1), Pair(-27, -28), Pair(-8, -67), Pair(132, -77),
        Pair(-81, -94), Pair(-77, -26), Pair(-90, 109), Pair(-188, 101), Pair(141, 32), Pair(-80, -104), Pair(-104, -14), Pair(18, 51)
      },
      { // Piece 2
        Pair(-56, 2), Pair(61, -32), Pair(-62, 15), Pair(88, -183), Pair(-55, -29), Pair(-31, -3), Pair(-213, -63), Pair(-80, -134),
        Pair(-156, -87), Pair(45, 94), Pair(233, -98), Pair(164, -62), Pair(355, -83), Pair(1, 77), Pair(0, 0), Pair(-66, 33),
        Pair(159, 8), Pair(207, -102), Pair(1, 11), Pair(102, -107), Pair(156, 52), Pair(110, -30), Pair(68, 114), Pair(13, -29),
        Pair(-138, -49), Pair(-14, 102), Pair(33, -80), Pair(149, -56), Pair(165, -55), Pair(1, 82), Pair(33, -90), Pair(6, -18),
        Pair(-102, 75), Pair(150, -92), Pair(47, 40), Pair(154, -13), Pair(-74, 93), Pair(-39, -70), Pair(27, -65), Pair(97, -148),
        Pair(-15, 55), Pair(153, -10), Pair(85, -14), Pair(96, -56), Pair(54, -79), Pair(36, 14), Pair(22, -32), Pair(-4, -62),
        Pair(-58, -49), Pair(35, 5), Pair(-107, 83), Pair(-13, -39), Pair(57, 4), Pair(-1, 16), Pair(-37, -22), Pair(-110, 107),
        Pair(137, -23), Pair(102, -9), Pair(-6, -28), Pair(-81, 25), Pair(-36, -19), Pair(-99, 9), Pair(19, -146), Pair(18, -56)
      },
      { // Piece 3
        Pair(-225, 14), Pair(184, -20), Pair(62, -2), Pair(-18, 65), Pair(-11, 48), Pair(29, 89), Pair(-74, -126), Pair(78, 9),
        Pair(311, -71), Pair(69, -21), Pair(28, -33), Pair(84, -53), Pair(-34, 8), Pair(-2, 18), Pair(0, 0), Pair(-56, 54),
        Pair(6, 19), Pair(53, -13), Pair(74, -16), Pair(311, -136), Pair(62, -45), Pair(-30, 24), Pair(72, 14), Pair(201, -3),
        Pair(-212, 99), Pair(-36, 8), Pair(-52, 102), Pair(-52, -13), Pair(-5, -57), Pair(18, -3), Pair(-23, -27), Pair(-25, 83),
        Pair(-13, 67), Pair(33, -28), Pair(18, -87), Pair(88, -23), Pair(56, 25), Pair(-62, 56), Pair(239, -45), Pair(-41, 90),
        Pair(-271, 15), Pair(-146, 75), Pair(-267, 217), Pair(48, 135), Pair(-21, 8), Pair(85, -64), Pair(92, -8), Pair(-135, 65),
        Pair(29, 0), Pair(-163, 4), Pair(1, 56), Pair(19, -7), Pair(113, -12), Pair(-62, 44), Pair(94, -53), Pair(7, 0),
        Pair(-26, -57), Pair(-46, 71), Pair(-58, 18), Pair(36, -69), Pair(24, 12), Pair(-25, 8), Pair(60, 55), Pair(6, -1)
      },
      { // Piece 4
        Pair(220, -90), Pair(-216, -183), Pair(-26, 3), Pair(-89, -60), Pair(-55, -15), Pair(248, -170), Pair(-41, -51), Pair(150, -194),
        Pair(44, -81), Pair(31, -64), Pair(-150, 8), Pair(67, 38), Pair(108, -274), Pair(109, -116), Pair(0, 0), Pair(-23, -165),
        Pair(33, 4), Pair(-137, -180), Pair(175, -13), Pair(-72, 150), Pair(97, -14), Pair(102, -195), Pair(-91, 46), Pair(41, 97),
        Pair(157, -126), Pair(-82, 42), Pair(128, -25), Pair(28, 9), Pair(-57, -114), Pair(20, 63), Pair(2, -24), Pair(81, -2),
        Pair(55, -128), Pair(-147, -89), Pair(-51, -136), Pair(53, -61), Pair(22, 9), Pair(-173, 73), Pair(-115, 110), Pair(-114, -77),
        Pair(35, -201), Pair(-230, -11), Pair(-43, 29), Pair(123, -47), Pair(-167, 82), Pair(-13, 43), Pair(69, 61), Pair(149, 74),
        Pair(-98, 11), Pair(-11, -150), Pair(7, 48), Pair(-113, 55), Pair(-99, 25), Pair(6, 81), Pair(-83, -94), Pair(59, -110),
        Pair(-63, -193), Pair(-70, -45), Pair(-153, 200), Pair(-104, 285), Pair(34, -119), Pair(-7, -22), Pair(-236, 100), Pair(332, 97)
      },
      { // Piece 5
        Pair(1, -37), Pair(-3, -140), Pair(17, 18), Pair(3, 195), Pair(37, 143), Pair(-48, 60), Pair(-59, 27), Pair(4, 81),
        Pair(-35, 6), Pair(-10, 11), Pair(-31, -67), Pair(42, -132), Pair(37, 18), Pair(-128, 108), Pair(0, 0), Pair(-98, 150),
        Pair(-173, -40), Pair(-45, 18), Pair(-38, -3), Pair(-12, -49), Pair(78, 77), Pair(144, 28), Pair(69, 28), Pair(-71, 113),
        Pair(-56, -56), Pair(-44, -12), Pair(-25, -47), Pair(231, -25), Pair(70, 12), Pair(116, 36), Pair(20, 60), Pair(96, 67),
        Pair(16, -40), Pair(122, -44), Pair(-163, 22), Pair(1, -24), Pair(-54, 27), Pair(31, -6), Pair(59, 9), Pair(-79, 26),
        Pair(-79, -59), Pair(-12, -13), Pair(46, -45), Pair(-27, 25), Pair(48, -7), Pair(-114, 40), Pair(125, -6), Pair(-24, -3),
        Pair(66, -62), Pair(70, -65), Pair(-31, 12), Pair(-61, -20), Pair(-69, -3), Pair(2, -6), Pair(-8, 16), Pair(32, 26),
        Pair(1, -109), Pair(-86, 2), Pair(-19, -32), Pair(-138, 63), Pair(5, 34), Pair(58, -25), Pair(32, -59), Pair(55, -39)
      }
    }},
    {{ // Bucket 15
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(116, 30), Pair(43, 7), Pair(76, -35), Pair(-192, 82), Pair(93, 50), Pair(6, 32), Pair(-44, -56), Pair(-19, -10),
        Pair(-36, 38), Pair(-82, 58), Pair(-28, 50), Pair(53, -7), Pair(57, 13), Pair(-17, 18), Pair(-34, -24), Pair(80, -97),
        Pair(0, 16), Pair(-23, 20), Pair(-3, 17), Pair(0, 17), Pair(-18, 22), Pair(-6, 15), Pair(-14, 37), Pair(39, -11),
        Pair(6, 12), Pair(-7, 19), Pair(-32, 17), Pair(11, -3), Pair(-19, 21), Pair(-23, 20), Pair(-11, 18), Pair(34, 4),
        Pair(-2, 23), Pair(-24, 16), Pair(10, 17), Pair(14, -6), Pair(-2, 5), Pair(3, 7), Pair(10, 12), Pair(45, 0),
        Pair(-16, 29), Pair(-10, 22), Pair(-12, 23), Pair(-24, 22), Pair(-4, 5), Pair(-18, 17), Pair(-10, 17), Pair(38, -1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(16, 179), Pair(-5, 18), Pair(-32, -20), Pair(-9, -19), Pair(37, 125), Pair(-43, 73), Pair(28, 24), Pair(126, 161),
        Pair(127, -9), Pair(15, 133), Pair(25, -80), Pair(9, 36), Pair(142, 1), Pair(126, 69), Pair(-218, 70), Pair(0, 0),
        Pair(-171, 75), Pair(-27, 78), Pair(142, -5), Pair(-27, 38), Pair(208, 91), Pair(111, -1), Pair(46, 62), Pair(26, 63),
        Pair(-69, -8), Pair(-6, 39), Pair(14, -10), Pair(31, 2), Pair(107, -20), Pair(132, -7), Pair(109, -6), Pair(114, 112),
        Pair(14, 106), Pair(-191, 71), Pair(14, 2), Pair(21, -22), Pair(146, -31), Pair(92, -14), Pair(43, 21), Pair(116, -49),
        Pair(34, -22), Pair(17, -25), Pair(48, -60), Pair(135, -3), Pair(-27, -2), Pair(40, -25), Pair(78, -15), Pair(55, 33),
        Pair(71, 6), Pair(24, -56), Pair(-32, -57), Pair(-29, 80), Pair(7, 42), Pair(-53, -4), Pair(4, -18), Pair(-79, 12),
        Pair(-100, 52), Pair(-78, -6), Pair(-37, -60), Pair(-81, -5), Pair(-185, -46), Pair(-114, 69), Pair(42, -90), Pair(-63, 8)
      },
      { // Piece 2
        Pair(50, -105), Pair(-13, -24), Pair(116, -24), Pair(-22, -20), Pair(70, -40), Pair(44, 93), Pair(142, 20), Pair(76, -59),
        Pair(-124, 61), Pair(95, -97), Pair(123, -45), Pair(-136, -88), Pair(250, 32), Pair(256, -42), Pair(107, 90), Pair(0, 0),
        Pair(-40, -40), Pair(-39, 54), Pair(-17, -55), Pair(35, 15), Pair(218, -55), Pair(-35, 75), Pair(38, 21), Pair(161, 130),
        Pair(-23, 93), Pair(154, -73), Pair(-29, 30), Pair(7, -36), Pair(171, 37), Pair(88, -14), Pair(69, 47), Pair(-61, 85),
        Pair(57, -22), Pair(-92, 7), Pair(90, -78), Pair(62, 42), Pair(167, -8), Pair(20, 32), Pair(-65, 36), Pair(70, -37),
        Pair(100, 48), Pair(-42, -28), Pair(139, 21), Pair(72, -12), Pair(41, 34), Pair(106, -9), Pair(122, 6), Pair(182, -51),
        Pair(-106, 52), Pair(84, 54), Pair(103, -38), Pair(54, 25), Pair(61, -49), Pair(2, -65), Pair(3, -28), Pair(111, -220),
        Pair(50, 52), Pair(117, -52), Pair(49, -36), Pair(92, -49), Pair(-245, 7), Pair(32, -17), Pair(85, -92), Pair(109, -5)
      },
      { // Piece 3
        Pair(-89, 111), Pair(-81, 74), Pair(-207, 84), Pair(80, 44), Pair(137, 73), Pair(86, 9), Pair(95, 79), Pair(253, -203),
        Pair(64, 0), Pair(288, -32), Pair(-49, 59), Pair(65, 19), Pair(279, -24), Pair(204, -6), Pair(60, 38), Pair(0, 0),
        Pair(197, -28), Pair(55, 5), Pair(151, 25), Pair(-9, 18), Pair(105, -31), Pair(22, -17), Pair(-27, 82), Pair(-43, 56),
        Pair(12, 42), Pair(216, -18), Pair(206, -50), Pair(136, -18), Pair(81, -38), Pair(234, -44), Pair(47, 23), Pair(-47, 59),
        Pair(-50, 64), Pair(-82, 55), Pair(-86, 87), Pair(168, -31), Pair(97, -19), Pair(17, 37), Pair(147, -3), Pair(-70, 39),
        Pair(1, 54), Pair(-48, 76), Pair(170, 77), Pair(-84, 21), Pair(-44, -12), Pair(-107, 0), Pair(132, 22), Pair(-68, 84),
        Pair(-24, 124), Pair(112, 71), Pair(16, 39), Pair(-7, 20), Pair(27, 7), Pair(-15, -33), Pair(88, 31), Pair(13, 27),
        Pair(9, 4), Pair(18, 45), Pair(-65, 66), Pair(27, -13), Pair(-1, -39), Pair(32, 0), Pair(14, 53), Pair(62, -27)
      },
      { // Piece 4
        Pair(-89, -4), Pair(-121, -103), Pair(48, 59), Pair(-25, -46), Pair(121, 69), Pair(-73, -88), Pair(-12, -42), Pair(-106, -230),
        Pair(97, 14), Pair(225, -183), Pair(60, -93), Pair(157, -187), Pair(107, -19), Pair(-46, -47), Pair(91, -13), Pair(0, 0),
        Pair(-50, -101), Pair(151, -29), Pair(-4, -87), Pair(3, 72), Pair(27, -18), Pair(-33, -120), Pair(-37, -33), Pair(0, 182),
        Pair(44, -53), Pair(35, 71), Pair(136, -9), Pair(92, -82), Pair(88, -43), Pair(9, 90), Pair(-52, -35), Pair(-20, 11),
        Pair(50, -147), Pair(-72, -63), Pair(0, -33), Pair(36, 29), Pair(95, -63), Pair(-42, 100), Pair(-17, 106), Pair(153, -214),
        Pair(-87, -5), Pair(-68, 40), Pair(-55, -48), Pair(-24, 52), Pair(-93, 125), Pair(-47, 84), Pair(35, -135), Pair(59, -245),
        Pair(-13, 48), Pair(-160, 51), Pair(14, 71), Pair(-37, -7), Pair(-51, -18), Pair(-4, -70), Pair(-31, 10), Pair(-117, -66),
        Pair(3, -31), Pair(36, 124), Pair(54, -62), Pair(-48, -4), Pair(-41, 37), Pair(-67, -30), Pair(22, -83), Pair(-11, 7)
      },
      { // Piece 5
        Pair(20, 109), Pair(-75, 94), Pair(1, 61), Pair(-14, -11), Pair(2, 14), Pair(-64, 129), Pair(67, 28), Pair(142, -246),
        Pair(53, 75), Pair(30, -23), Pair(-146, 49), Pair(-87, 67), Pair(-2, -1), Pair(-52, 65), Pair(202, 56), Pair(0, 0),
        Pair(15, 96), Pair(46, -23), Pair(132, -51), Pair(-48, 79), Pair(41, -4), Pair(-51, 54), Pair(88, 7), Pair(-152, 57),
        Pair(247, 95), Pair(-37, 15), Pair(84, 49), Pair(-3, 25), Pair(7, 25), Pair(83, -3), Pair(131, 11), Pair(146, -41),
        Pair(-17, -57), Pair(24, 27), Pair(31, -18), Pair(73, 15), Pair(-56, -17), Pair(-88, 45), Pair(-16, 35), Pair(28, 14),
        Pair(-161, -46), Pair(-107, -14), Pair(91, 11), Pair(88, -40), Pair(-43, -3), Pair(-37, -9), Pair(25, -9), Pair(50, -34),
        Pair(-97, -51), Pair(-39, -35), Pair(-57, -36), Pair(128, -53), Pair(-79, 9), Pair(-14, -12), Pair(43, 3), Pair(8, -17),
        Pair(5, -21), Pair(18, -37), Pair(-77, -47), Pair(-90, -9), Pair(-42, -39), Pair(4, -10), Pair(-58, 23), Pair(-52, -14)
      }
    }},
    {{ // Bucket 16
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-37, -91), Pair(-24, 10), Pair(-35, 27), Pair(17, 27), Pair(-46, 42), Pair(117, -6), Pair(-16, 30), Pair(-36, 38),
        Pair(1, 63), Pair(-17, -13), Pair(-2, 21), Pair(-2, 44), Pair(-1, 38), Pair(15, 14), Pair(-50, 24), Pair(8, 14),
        Pair(9, -30), Pair(-10, -5), Pair(-1, 16), Pair(-3, 21), Pair(5, 12), Pair(8, 13), Pair(-2, 15), Pair(-4, 18),
        Pair(-18, 8), Pair(-5, 24), Pair(-3, 17), Pair(-2, 10), Pair(-3, 13), Pair(-5, 12), Pair(0, 14), Pair(-4, 15),
        Pair(-5, 34), Pair(-8, 19), Pair(-7, 12), Pair(-3, 16), Pair(-2, 11), Pair(5, 16), Pair(-1, 18), Pair(-6, 21),
        Pair(-22, 24), Pair(-7, 22), Pair(-4, 10), Pair(1, 9), Pair(-2, 13), Pair(-6, 23), Pair(0, 19), Pair(-4, 20),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(190, -6), Pair(-160, 74), Pair(105, 71), Pair(77, 42), Pair(53, 43), Pair(37, 5), Pair(59, 61), Pair(173, 4),
        Pair(41, -86), Pair(52, 47), Pair(68, 39), Pair(-9, 47), Pair(64, 62), Pair(161, 9), Pair(-60, 112), Pair(-131, 71),
        Pair(0, 0), Pair(47, 71), Pair(80, 44), Pair(37, 57), Pair(70, 17), Pair(99, -10), Pair(82, 43), Pair(-17, 27),
        Pair(40, 36), Pair(41, 78), Pair(48, 19), Pair(21, 62), Pair(43, 34), Pair(6, 55), Pair(24, 14), Pair(-2, 18),
        Pair(16, 35), Pair(32, 52), Pair(24, 63), Pair(34, 44), Pair(18, 29), Pair(51, 12), Pair(17, 38), Pair(2, 64),
        Pair(48, 38), Pair(22, 50), Pair(33, 31), Pair(37, 46), Pair(33, 41), Pair(29, 32), Pair(39, 4), Pair(2, 51),
        Pair(-41, 33), Pair(24, 10), Pair(26, 27), Pair(23, 37), Pair(19, 21), Pair(48, -14), Pair(-2, 27), Pair(9, 59),
        Pair(-209, 66), Pair(20, 2), Pair(27, 17), Pair(-57, 87), Pair(35, -2), Pair(4, 20), Pair(39, -30), Pair(-100, -24)
      },
      { // Piece 2
        Pair(77, -9), Pair(275, 13), Pair(124, -21), Pair(78, 15), Pair(93, -37), Pair(2, -2), Pair(182, -29), Pair(31, 4),
        Pair(56, -44), Pair(105, 29), Pair(148, 5), Pair(177, -17), Pair(156, -20), Pair(-75, 17), Pair(79, -7), Pair(96, 17),
        Pair(0, 0), Pair(94, 46), Pair(118, -1), Pair(24, 72), Pair(53, 9), Pair(-22, 32), Pair(-6, -14), Pair(-57, 81),
        Pair(39, 71), Pair(69, 14), Pair(45, 87), Pair(63, 5), Pair(64, 40), Pair(54, -9), Pair(27, 70), Pair(41, -9),
        Pair(35, -14), Pair(26, 49), Pair(51, 3), Pair(37, 49), Pair(43, 31), Pair(28, 45), Pair(46, -13), Pair(19, 32),
        Pair(18, 52), Pair(36, 14), Pair(4, 44), Pair(39, 15), Pair(21, 62), Pair(36, -1), Pair(58, 13), Pair(9, 26),
        Pair(64, -13), Pair(16, 24), Pair(7, 1), Pair(27, 24), Pair(40, 27), Pair(31, 44), Pair(45, 14), Pair(83, 16),
        Pair(19, 33), Pair(25, -2), Pair(9, 39), Pair(1, 37), Pair(29, 36), Pair(46, 26), Pair(150, 38), Pair(49, 22)
      },
      { // Piece 3
        Pair(98, -6), Pair(30, 96), Pair(-54, 109), Pair(72, 72), Pair(59, 63), Pair(17, 48), Pair(-23, 81), Pair(-49, 123),
        Pair(27, -56), Pair(81, 96), Pair(-17, 120), Pair(55, 76), Pair(47, 52), Pair(112, 67), Pair(-19, 93), Pair(77, 96),
        Pair(0, 0), Pair(59, 70), Pair(42, 77), Pair(60, 62), Pair(130, 37), Pair(-16, 88), Pair(61, 70), Pair(-45, 119),
        Pair(-29, 60), Pair(-25, 118), Pair(12, 94), Pair(20, 79), Pair(12, 84), Pair(35, 71), Pair(21, 84), Pair(30, 93),
        Pair(-15, 77), Pair(23, 94), Pair(24, 83), Pair(6, 101), Pair(20, 79), Pair(3, 77), Pair(-3, 90), Pair(50, 93),
        Pair(-18, 70), Pair(14, 108), Pair(12, 93), Pair(46, 58), Pair(8, 69), Pair(27, 43), Pair(33, 78), Pair(-18, 81),
        Pair(-43, 80), Pair(32, 70), Pair(2, 100), Pair(35, 59), Pair(2, 71), Pair(18, 56), Pair(-21, 98), Pair(43, 66),
        Pair(-8, 56), Pair(26, 81), Pair(24, 69), Pair(22, 76), Pair(30, 63), Pair(18, 64), Pair(28, 77), Pair(14, 71)
      },
      { // Piece 4
        Pair(88, 42), Pair(54, 129), Pair(60, 125), Pair(31, 110), Pair(151, 23), Pair(16, 79), Pair(-28, 91), Pair(75, 101),
        Pair(55, -91), Pair(82, 112), Pair(130, 85), Pair(34, 174), Pair(108, 96), Pair(105, 27), Pair(55, 88), Pair(64, 111),
        Pair(0, 0), Pair(36, 150), Pair(21, 193), Pair(43, 125), Pair(50, 83), Pair(124, 69), Pair(22, 138), Pair(18, 74),
        Pair(69, 28), Pair(66, 144), Pair(33, 146), Pair(86, 79), Pair(17, 177), Pair(53, 103), Pair(66, 76), Pair(40, 90),
        Pair(27, 155), Pair(59, 120), Pair(42, 148), Pair(42, 116), Pair(28, 188), Pair(40, 132), Pair(53, 107), Pair(51, 45),
        Pair(37, 158), Pair(44, 136), Pair(72, 81), Pair(57, 107), Pair(33, 134), Pair(50, 91), Pair(49, 112), Pair(68, 32),
        Pair(29, 127), Pair(64, 92), Pair(47, 119), Pair(60, 80), Pair(45, 135), Pair(68, 40), Pair(56, 87), Pair(52, 15),
        Pair(36, 97), Pair(61, 101), Pair(49, 69), Pair(52, 104), Pair(53, 97), Pair(57, 83), Pair(50, 127), Pair(88, -76)
      },
      { // Piece 5
        Pair(-6, 0), Pair(-73, 108), Pair(-110, 122), Pair(-6, -1), Pair(-16, -28), Pair(9, 54), Pair(7, 37), Pair(40, -29),
        Pair(-26, -26), Pair(-63, 149), Pair(-66, 134), Pair(17, 81), Pair(110, 37), Pair(147, -12), Pair(205, -55), Pair(147, -18),
        Pair(0, 0), Pair(73, 104), Pair(97, 90), Pair(172, 51), Pair(105, -13), Pair(89, 31), Pair(112, -7), Pair(-183, 78),
        Pair(93, 62), Pair(196, 60), Pair(91, 82), Pair(276, 17), Pair(-102, 82), Pair(2, 18), Pair(-62, 31), Pair(-29, 21),
        Pair(-13, 41), Pair(131, 58), Pair(163, 36), Pair(85, 44), Pair(-13, 29), Pair(53, 16), Pair(-12, 16), Pair(-74, 16),
        Pair(3, 81), Pair(5, 75), Pair(26, 48), Pair(-44, 44), Pair(-12, 27), Pair(-26, 15), Pair(-56, 14), Pair(-84, 16),
        Pair(-5, 42), Pair(54, 52), Pair(76, 15), Pair(-13, 30), Pair(-19, 32), Pair(-34, 24), Pair(-15, 9), Pair(-20, -13),
        Pair(134, -2), Pair(88, -1), Pair(47, 31), Pair(40, 24), Pair(-25, -4), Pair(-30, 11), Pair(-13, 3), Pair(-20, -12)
      }
    }},
    {{ // Bucket 17
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-37, 12), Pair(-34, -98), Pair(-27, 28), Pair(-98, 35), Pair(-42, 16), Pair(-47, 65), Pair(-15, 72), Pair(-82, 58),
        Pair(-18, -13), Pair(-4, 65), Pair(21, 15), Pair(3, 22), Pair(-7, 36), Pair(-9, 19), Pair(35, 23), Pair(7, 17),
        Pair(10, 12), Pair(4, -30), Pair(6, 19), Pair(-12, 17), Pair(-7, 23), Pair(-9, 21), Pair(-16, 14), Pair(-16, 25),
        Pair(-4, 35), Pair(12, 5), Pair(-18, 24), Pair(3, 12), Pair(-3, 11), Pair(0, 10), Pair(2, 18), Pair(-17, 22),
        Pair(-4, 24), Pair(3, 13), Pair(-7, 20), Pair(-1, 10), Pair(-8, 12), Pair(-1, 17), Pair(3, 17), Pair(-1, 20),
        Pair(-13, 30), Pair(0, -1), Pair(-23, 31), Pair(6, 11), Pair(-17, 22), Pair(-7, 21), Pair(1, 19), Pair(-7, 27),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(36, -12), Pair(-304, 98), Pair(10, 54), Pair(-73, 61), Pair(-80, 50), Pair(76, 79), Pair(-103, 98), Pair(72, 359),
        Pair(68, 48), Pair(28, -32), Pair(20, 83), Pair(66, 33), Pair(27, 75), Pair(-54, 46), Pair(99, 40), Pair(85, -75),
        Pair(-89, 105), Pair(0, 0), Pair(72, 78), Pair(24, 56), Pair(24, 52), Pair(80, 32), Pair(130, -43), Pair(-61, 89),
        Pair(133, 60), Pair(12, 102), Pair(63, 74), Pair(71, 36), Pair(36, 60), Pair(85, 53), Pair(16, 45), Pair(-58, 67),
        Pair(7, 69), Pair(109, 77), Pair(61, 50), Pair(35, 29), Pair(28, 34), Pair(34, 45), Pair(37, 70), Pair(30, 3),
        Pair(-27, 54), Pair(40, 81), Pair(25, 58), Pair(-6, 53), Pair(46, 42), Pair(34, 34), Pair(50, 28), Pair(20, 30),
        Pair(-57, 42), Pair(60, -3), Pair(15, 26), Pair(18, 44), Pair(21, 27), Pair(40, 77), Pair(20, 22), Pair(31, 11),
        Pair(19, -74), Pair(-23, 39), Pair(10, 61), Pair(25, 20), Pair(57, -6), Pair(62, 38), Pair(41, -37), Pair(47, 107)
      },
      { // Piece 2
        Pair(141, -7), Pair(85, -5), Pair(103, 24), Pair(110, -13), Pair(21, 25), Pair(285, -25), Pair(-102, 57), Pair(37, -4),
        Pair(-74, 39), Pair(27, -16), Pair(80, 31), Pair(68, 18), Pair(262, -50), Pair(-68, 40), Pair(81, -47), Pair(68, 56),
        Pair(59, 51), Pair(0, 0), Pair(183, -9), Pair(113, 3), Pair(92, 27), Pair(167, -44), Pair(79, 43), Pair(19, 1),
        Pair(24, 19), Pair(41, 83), Pair(49, 16), Pair(70, 41), Pair(67, -5), Pair(150, -38), Pair(83, 10), Pair(-23, 54),
        Pair(-4, 65), Pair(32, 21), Pair(93, 10), Pair(60, 16), Pair(73, 52), Pair(64, 34), Pair(43, 41), Pair(20, 72),
        Pair(22, 22), Pair(56, 10), Pair(51, -9), Pair(59, 39), Pair(51, 16), Pair(71, 31), Pair(50, 47), Pair(30, 43),
        Pair(55, 28), Pair(17, 6), Pair(18, 47), Pair(36, 5), Pair(31, 50), Pair(81, 11), Pair(53, 51), Pair(26, 30),
        Pair(32, 34), Pair(33, 15), Pair(11, 6), Pair(75, 12), Pair(1, 19), Pair(43, 45), Pair(63, 10), Pair(38, -39)
      },
      { // Piece 3
        Pair(49, 100), Pair(16, 26), Pair(-47, 145), Pair(17, 109), Pair(75, 75), Pair(10, 70), Pair(-27, 60), Pair(100, 49),
        Pair(28, 96), Pair(-78, -12), Pair(53, 116), Pair(56, 69), Pair(84, 58), Pair(136, 41), Pair(19, 85), Pair(-32, 121),
        Pair(31, 77), Pair(0, 0), Pair(81, 67), Pair(44, 92), Pair(-18, 105), Pair(37, 98), Pair(27, 82), Pair(92, 84),
        Pair(41, 81), Pair(19, 77), Pair(-15, 111), Pair(25, 103), Pair(57, 69), Pair(199, 1), Pair(14, 111), Pair(28, 88),
        Pair(-24, 123), Pair(-1, 86), Pair(50, 97), Pair(56, 85), Pair(36, 82), Pair(33, 73), Pair(6, 74), Pair(2, 102),
        Pair(-32, 104), Pair(0, 81), Pair(-1, 122), Pair(28, 72), Pair(34, 64), Pair(80, 55), Pair(49, 47), Pair(-3, 96),
        Pair(-10, 74), Pair(5, 87), Pair(30, 92), Pair(17, 88), Pair(-7, 98), Pair(22, 67), Pair(20, 53), Pair(-35, 141),
        Pair(13, 79), Pair(29, 74), Pair(22, 82), Pair(25, 76), Pair(18, 82), Pair(33, 69), Pair(22, 61), Pair(9, 69)
      },
      { // Piece 4
        Pair(-74, 177), Pair(52, 70), Pair(16, 110), Pair(44, 113), Pair(76, 87), Pair(65, 52), Pair(113, 24), Pair(-14, 93),
        Pair(-6, 103), Pair(-19, 8), Pair(25, 118), Pair(-6, 131), Pair(40, 123), Pair(16, 163), Pair(-104, 211), Pair(-90, 194),
        Pair(14, 155), Pair(0, 0), Pair(91, 96), Pair(13, 164), Pair(181, 74), Pair(-45, 218), Pair(126, 67), Pair(3, 56),
        Pair(60, 108), Pair(41, 153), Pair(66, 121), Pair(73, 163), Pair(77, 70), Pair(77, 140), Pair(45, -3), Pair(-31, 229),
        Pair(54, 91), Pair(47, 123), Pair(91, 60), Pair(98, 74), Pair(-14, 148), Pair(27, 213), Pair(30, 87), Pair(92, 90),
        Pair(4, 181), Pair(67, 46), Pair(25, 162), Pair(11, 95), Pair(41, 104), Pair(75, 66), Pair(17, 138), Pair(83, 107),
        Pair(15, 135), Pair(44, 68), Pair(41, 108), Pair(36, 144), Pair(71, 53), Pair(21, 145), Pair(67, 132), Pair(93, 46),
        Pair(47, 106), Pair(10, 147), Pair(-3, 156), Pair(37, 100), Pair(40, 62), Pair(96, 99), Pair(58, 20), Pair(91, 1)
      },
      { // Piece 5
        Pair(-19, 271), Pair(117, 175), Pair(-103, 311), Pair(28, 67), Pair(7, -11), Pair(40, 33), Pair(-94, 9), Pair(-38, -21),
        Pair(53, 163), Pair(188, 38), Pair(209, 50), Pair(28, 106), Pair(188, 18), Pair(-93, 11), Pair(72, -12), Pair(-49, 26),
        Pair(12, 140), Pair(0, 0), Pair(236, 75), Pair(28, 86), Pair(70, 8), Pair(3, -22), Pair(-41, 52), Pair(-162, 35),
        Pair(23, 129), Pair(159, 48), Pair(195, 65), Pair(88, 65), Pair(93, 17), Pair(-57, 66), Pair(127, -12), Pair(-100, 2),
        Pair(179, 63), Pair(133, 31), Pair(72, 57), Pair(94, 21), Pair(113, -13), Pair(-26, 8), Pair(-190, 53), Pair(-85, 21),
        Pair(11, 50), Pair(90, 19), Pair(-5, 37), Pair(37, 24), Pair(7, 17), Pair(-10, -14), Pair(-57, 5), Pair(-161, 25),
        Pair(103, 12), Pair(69, -4), Pair(82, 19), Pair(-3, 22), Pair(-2, 0), Pair(-60, 15), Pair(-40, -9), Pair(-38, -13),
        Pair(6, 88), Pair(46, 65), Pair(-28, 80), Pair(-25, -9), Pair(-11, -28), Pair(-3, -15), Pair(-23, -6), Pair(-43, -8)
      }
    }},
    {{ // Bucket 18
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-10, 32), Pair(27, -20), Pair(-44, -98), Pair(77, -4), Pair(-130, 69), Pair(-4, 66), Pair(-50, 33), Pair(-28, 50),
        Pair(-2, 20), Pair(21, 14), Pair(11, 49), Pair(-41, 64), Pair(2, 23), Pair(34, 13), Pair(-21, 42), Pair(-48, 41),
        Pair(3, 19), Pair(15, 28), Pair(-22, -42), Pair(10, 36), Pair(0, 22), Pair(9, 22), Pair(-10, 22), Pair(21, 14),
        Pair(1, 23), Pair(-5, 29), Pair(-14, -6), Pair(-4, 25), Pair(5, 13), Pair(12, 12), Pair(9, 10), Pair(-6, 17),
        Pair(-6, 22), Pair(-8, 22), Pair(-5, -2), Pair(-2, 18), Pair(10, 7), Pair(12, 15), Pair(0, 14), Pair(6, 13),
        Pair(-8, 24), Pair(-14, 19), Pair(-3, -4), Pair(-15, 13), Pair(-5, 22), Pair(-1, 18), Pair(-4, 19), Pair(0, 18),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-109, 130), Pair(133, 28), Pair(90, 77), Pair(-100, 82), Pair(-25, 84), Pair(-78, -65), Pair(48, 119), Pair(27, 51),
        Pair(-75, 107), Pair(97, 65), Pair(1, -12), Pair(62, 38), Pair(104, 45), Pair(-9, 31), Pair(245, 7), Pair(16, 100),
        Pair(63, 42), Pair(92, 68), Pair(0, 0), Pair(87, 45), Pair(131, 35), Pair(79, 42), Pair(100, 48), Pair(-10, 175),
        Pair(-9, 87), Pair(61, 97), Pair(17, 92), Pair(88, 88), Pair(22, 40), Pair(51, 38), Pair(23, 50), Pair(29, 31),
        Pair(59, 32), Pair(56, 32), Pair(5, 94), Pair(40, 59), Pair(-4, 63), Pair(7, 84), Pair(-1, 75), Pair(45, -12),
        Pair(67, 49), Pair(38, 51), Pair(31, 77), Pair(17, 56), Pair(56, 49), Pair(22, 57), Pair(21, 43), Pair(50, -12),
        Pair(59, 6), Pair(52, -39), Pair(42, 51), Pair(13, 47), Pair(21, 61), Pair(62, 7), Pair(-58, 107), Pair(38, 11),
        Pair(83, -23), Pair(3, 41), Pair(-119, 30), Pair(-33, 77), Pair(-4, 64), Pair(-41, 66), Pair(29, 17), Pair(86, -7)
      },
      { // Piece 2
        Pair(-57, -65), Pair(73, 58), Pair(199, -57), Pair(137, 44), Pair(80, -2), Pair(163, 8), Pair(95, -38), Pair(135, 4),
        Pair(-54, 99), Pair(82, -15), Pair(62, -54), Pair(130, -12), Pair(63, 68), Pair(92, -13), Pair(76, 6), Pair(-15, -10),
        Pair(109, 4), Pair(113, 5), Pair(0, 0), Pair(110, 45), Pair(87, -2), Pair(137, 23), Pair(29, -29), Pair(37, -11),
        Pair(17, 104), Pair(57, -4), Pair(19, 108), Pair(50, 20), Pair(56, 72), Pair(95, -21), Pair(71, -7), Pair(64, -6),
        Pair(35, 22), Pair(42, 41), Pair(40, -5), Pair(39, 52), Pair(25, 23), Pair(72, 41), Pair(28, 36), Pair(106, -15),
        Pair(18, 54), Pair(62, -16), Pair(39, 62), Pair(36, 31), Pair(22, 53), Pair(38, 19), Pair(10, 54), Pair(22, 61),
        Pair(13, 10), Pair(16, 30), Pair(71, 8), Pair(42, 43), Pair(34, 22), Pair(72, 64), Pair(32, 21), Pair(62, 72),
        Pair(71, -20), Pair(-80, 36), Pair(32, 39), Pair(38, 5), Pair(-3, 89), Pair(31, 23), Pair(83, 32), Pair(-5, 21)
      },
      { // Piece 3
        Pair(57, 93), Pair(164, 88), Pair(24, 43), Pair(-85, 153), Pair(97, 70), Pair(13, 77), Pair(-145, 127), Pair(33, 83),
        Pair(-9, 116), Pair(24, 92), Pair(-41, -29), Pair(86, 72), Pair(23, 74), Pair(1, 117), Pair(-118, 137), Pair(27, 101),
        Pair(17, 84), Pair(5, 97), Pair(0, 0), Pair(21, 80), Pair(82, 76), Pair(34, 54), Pair(53, 83), Pair(61, 69),
        Pair(32, 95), Pair(5, 80), Pair(-17, 86), Pair(-31, 100), Pair(3, 57), Pair(-31, 129), Pair(-79, 120), Pair(-43, 102),
        Pair(16, 95), Pair(-64, 144), Pair(24, 86), Pair(-26, 97), Pair(-3, 72), Pair(-36, 57), Pair(43, 76), Pair(-55, 76),
        Pair(-3, 101), Pair(12, 60), Pair(-58, 106), Pair(9, 84), Pair(38, 71), Pair(19, 50), Pair(-43, 78), Pair(13, 92),
        Pair(-2, 49), Pair(39, 66), Pair(-19, 75), Pair(1, 113), Pair(-13, 94), Pair(-28, 66), Pair(17, 81), Pair(1, 87),
        Pair(4, 70), Pair(6, 82), Pair(0, 63), Pair(4, 74), Pair(3, 107), Pair(12, 71), Pair(-55, 115), Pair(-15, 54)
      },
      { // Piece 4
        Pair(46, 69), Pair(-36, 209), Pair(97, 21), Pair(175, -18), Pair(116, 62), Pair(-83, 90), Pair(40, 59), Pair(282, -101),
        Pair(101, 34), Pair(87, 63), Pair(31, -70), Pair(34, 86), Pair(118, -1), Pair(125, 60), Pair(120, 241), Pair(96, 106),
        Pair(60, 59), Pair(22, 101), Pair(0, 0), Pair(-15, 131), Pair(5, 100), Pair(45, 87), Pair(-11, 104), Pair(27, 86),
        Pair(18, 143), Pair(26, 131), Pair(11, 148), Pair(-19, 124), Pair(63, 107), Pair(10, 179), Pair(38, 54), Pair(-8, 186),
        Pair(65, 53), Pair(25, 83), Pair(26, 127), Pair(41, 106), Pair(37, 83), Pair(13, 169), Pair(-11, 157), Pair(39, 148),
        Pair(68, -2), Pair(52, 68), Pair(43, 86), Pair(56, 46), Pair(43, 108), Pair(41, 144), Pair(39, 135), Pair(6, 88),
        Pair(64, 36), Pair(42, 3), Pair(30, 94), Pair(43, 39), Pair(33, 118), Pair(46, 35), Pair(52, 39), Pair(11, 157),
        Pair(83, 28), Pair(112, 58), Pair(50, 62), Pair(27, 139), Pair(24, 109), Pair(107, 16), Pair(179, -76), Pair(17, 98)
      },
      { // Piece 5
        Pair(111, 74), Pair(57, 216), Pair(176, 87), Pair(15, 116), Pair(-21, 31), Pair(-3, 102), Pair(-28, 10), Pair(-3, -44),
        Pair(11, 156), Pair(169, 88), Pair(198, -6), Pair(208, 42), Pair(300, 38), Pair(-27, 92), Pair(-26, 6), Pair(34, -55),
        Pair(184, 96), Pair(206, 113), Pair(0, 0), Pair(158, 85), Pair(102, 54), Pair(-146, 79), Pair(89, 11), Pair(33, 58),
        Pair(3, 109), Pair(173, 79), Pair(42, 93), Pair(101, 74), Pair(97, 35), Pair(-7, 58), Pair(-127, 42), Pair(-118, 26),
        Pair(77, 22), Pair(59, 73), Pair(26, 58), Pair(20, 60), Pair(98, 14), Pair(-45, 28), Pair(-6, -2), Pair(-161, 56),
        Pair(58, 67), Pair(24, 59), Pair(13, 21), Pair(-5, 30), Pair(-29, 32), Pair(-17, 3), Pair(-13, -10), Pair(-8, -32),
        Pair(5, 61), Pair(-81, 46), Pair(23, 12), Pair(-130, 43), Pair(-31, 15), Pair(-33, 6), Pair(-36, 1), Pair(-58, 1),
        Pair(91, 9), Pair(31, -10), Pair(-34, 40), Pair(-96, 22), Pair(-6, -7), Pair(-24, -8), Pair(-39, -11), Pair(-42, -4)
      }
    }},
    {{ // Bucket 19
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-41, 46), Pair(-13, 45), Pair(-13, 21), Pair(-54, -59), Pair(-4, 16), Pair(6, 37), Pair(102, -14), Pair(53, -6),
        Pair(-2, 43), Pair(3, 23), Pair(-39, 63), Pair(14, 27), Pair(6, 51), Pair(41, -3), Pair(-85, 40), Pair(2, 30),
        Pair(10, 20), Pair(7, 21), Pair(17, 41), Pair(-5, -36), Pair(21, 38), Pair(12, 16), Pair(19, 15), Pair(3, 20),
        Pair(3, 16), Pair(10, 15), Pair(-10, 28), Pair(2, -1), Pair(-4, 22), Pair(6, 11), Pair(-3, 10), Pair(8, 9),
        Pair(-3, 15), Pair(1, 11), Pair(-8, 13), Pair(1, -3), Pair(1, 14), Pair(10, 10), Pair(-9, 11), Pair(6, 8),
        Pair(-2, 16), Pair(-7, 21), Pair(-14, 18), Pair(22, -22), Pair(-13, 19), Pair(1, 14), Pair(-2, 11), Pair(7, 9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(58, 12), Pair(-40, 65), Pair(19, 31), Pair(47, 39), Pair(-67, 80), Pair(-162, 75), Pair(-202, 127), Pair(94, 201),
        Pair(62, 36), Pair(26, 125), Pair(26, 95), Pair(21, -10), Pair(81, 30), Pair(-50, 90), Pair(-57, 40), Pair(90, 32),
        Pair(6, 64), Pair(5, 94), Pair(35, 104), Pair(0, 0), Pair(62, 79), Pair(74, 79), Pair(47, 90), Pair(15, 81),
        Pair(25, 84), Pair(44, 65), Pair(46, 98), Pair(30, 105), Pair(42, 99), Pair(47, 62), Pair(36, 75), Pair(4, 109),
        Pair(54, 39), Pair(101, 24), Pair(38, 64), Pair(-20, 91), Pair(17, 85), Pair(24, 80), Pair(-15, 85), Pair(12, 31),
        Pair(-19, 126), Pair(-17, 83), Pair(30, 40), Pair(26, 61), Pair(45, 40), Pair(4, 64), Pair(15, 35), Pair(12, 87),
        Pair(-15, 56), Pair(-19, 9), Pair(12, 25), Pair(21, 64), Pair(13, 67), Pair(18, 80), Pair(57, 19), Pair(-18, 5),
        Pair(59, 32), Pair(-2, 69), Pair(64, -23), Pair(14, 43), Pair(-11, 27), Pair(8, 21), Pair(-21, 34), Pair(-71, -65)
      },
      { // Piece 2
        Pair(-10, 53), Pair(-20, 54), Pair(259, -26), Pair(-44, 28), Pair(-36, 106), Pair(-119, 37), Pair(-144, 79), Pair(41, -29),
        Pair(65, 6), Pair(2, 49), Pair(101, 11), Pair(98, -32), Pair(168, -7), Pair(189, 2), Pair(31, 13), Pair(0, 136),
        Pair(55, 83), Pair(62, -6), Pair(66, 57), Pair(0, 0), Pair(109, 33), Pair(125, 3), Pair(66, 60), Pair(87, 29),
        Pair(26, 40), Pair(49, 66), Pair(12, 34), Pair(103, 69), Pair(34, 42), Pair(49, 64), Pair(25, 28), Pair(72, 27),
        Pair(43, 58), Pair(56, 31), Pair(14, 89), Pair(91, -2), Pair(26, 66), Pair(42, 31), Pair(5, 71), Pair(31, 30),
        Pair(-5, 58), Pair(42, 38), Pair(48, 23), Pair(37, 63), Pair(27, 28), Pair(57, 37), Pair(31, 26), Pair(37, 77),
        Pair(1, 2), Pair(11, 56), Pair(29, 62), Pair(-7, 34), Pair(26, 60), Pair(39, 40), Pair(44, 34), Pair(26, 6),
        Pair(35, 50), Pair(-14, 81), Pair(5, 59), Pair(3, 83), Pair(53, -3), Pair(27, 58), Pair(13, 44), Pair(43, 18)
      },
      { // Piece 3
        Pair(14, 108), Pair(-57, 130), Pair(22, 108), Pair(-13, 71), Pair(123, 75), Pair(84, 96), Pair(-73, 128), Pair(-123, 154),
        Pair(68, 87), Pair(22, 117), Pair(64, 69), Pair(-105, 6), Pair(87, 86), Pair(68, 71), Pair(136, 105), Pair(57, 100),
        Pair(-17, 103), Pair(11, 77), Pair(-20, 96), Pair(0, 0), Pair(99, 64), Pair(-7, 87), Pair(122, 80), Pair(90, 83),
        Pair(57, 94), Pair(43, 87), Pair(0, 108), Pair(26, 67), Pair(12, 98), Pair(13, 76), Pair(11, 136), Pair(26, 55),
        Pair(-17, 113), Pair(-16, 110), Pair(50, 68), Pair(34, 86), Pair(-12, 111), Pair(20, 95), Pair(-48, 98), Pair(-7, 91),
        Pair(21, 77), Pair(37, 78), Pair(-15, 104), Pair(29, 92), Pair(9, 87), Pair(28, 112), Pair(34, 59), Pair(29, 89),
        Pair(-9, 87), Pair(25, 75), Pair(25, 82), Pair(-13, 101), Pair(1, 78), Pair(48, 52), Pair(5, 95), Pair(-96, 101),
        Pair(5, 75), Pair(28, 70), Pair(4, 99), Pair(22, 70), Pair(11, 98), Pair(17, 64), Pair(20, 85), Pair(-1, 66)
      },
      { // Piece 4
        Pair(-41, 41), Pair(4, 116), Pair(98, 80), Pair(5, 107), Pair(-70, 148), Pair(107, 13), Pair(172, 44), Pair(184, -21),
        Pair(40, 100), Pair(86, 87), Pair(34, 98), Pair(-40, 18), Pair(104, 13), Pair(129, 5), Pair(150, 48), Pair(2, 123),
        Pair(48, 146), Pair(80, 31), Pair(-13, 137), Pair(0, 0), Pair(95, 74), Pair(-15, 148), Pair(16, 170), Pair(109, 86),
        Pair(54, 114), Pair(8, 202), Pair(32, 171), Pair(34, 106), Pair(24, 117), Pair(105, 37), Pair(47, 134), Pair(59, 122),
        Pair(39, 69), Pair(37, 121), Pair(65, 79), Pair(44, 136), Pair(18, 151), Pair(1, 129), Pair(63, 85), Pair(47, 63),
        Pair(53, 70), Pair(47, 69), Pair(31, 90), Pair(67, 67), Pair(44, 150), Pair(45, 115), Pair(37, 58), Pair(58, -18),
        Pair(55, 69), Pair(19, 153), Pair(56, 67), Pair(62, 59), Pair(28, 148), Pair(24, 105), Pair(62, 88), Pair(20, 120),
        Pair(77, -55), Pair(104, 19), Pair(65, 77), Pair(38, 97), Pair(83, 29), Pair(65, 47), Pair(26, -31), Pair(64, -31)
      },
      { // Piece 5
        Pair(58, -17), Pair(-44, 118), Pair(68, 218), Pair(29, 127), Pair(-2, 106), Pair(37, 20), Pair(-8, 9), Pair(-23, -66),
        Pair(34, 52), Pair(36, 89), Pair(169, 54), Pair(-98, 67), Pair(88, 76), Pair(31, 117), Pair(100, 20), Pair(54, -26),
        Pair(17, 109), Pair(165, 5), Pair(216, 80), Pair(0, 0), Pair(18, 111), Pair(140, 18), Pair(97, -14), Pair(-129, 39),
        Pair(-26, 35), Pair(31, 21), Pair(86, 74), Pair(26, 103), Pair(75, 50), Pair(-71, 70), Pair(-4, -1), Pair(7, -37),
        Pair(-25, 24), Pair(85, 18), Pair(91, 20), Pair(17, 41), Pair(-39, 32), Pair(107, -12), Pair(-1, 14), Pair(-119, 1),
        Pair(-55, 66), Pair(16, -10), Pair(75, -11), Pair(-48, 32), Pair(47, -16), Pair(27, -9), Pair(1, -21), Pair(27, -49),
        Pair(11, 7), Pair(-10, -12), Pair(-45, -18), Pair(-68, 14), Pair(-59, -16), Pair(-56, 0), Pair(9, -30), Pair(8, -28),
        Pair(-30, 40), Pair(14, -10), Pair(-20, -5), Pair(-18, 2), Pair(-24, -37), Pair(-20, -35), Pair(2, -34), Pair(-1, -34)
      }
    }},
    {{ // Bucket 20
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-134, 56), Pair(-47, 31), Pair(-6, 3), Pair(-20, 23), Pair(109, -66), Pair(-49, 17), Pair(-17, 27), Pair(57, 13),
        Pair(-1, 38), Pair(-6, 36), Pair(2, 23), Pair(5, 51), Pair(16, 21), Pair(19, 14), Pair(28, 2), Pair(2, 28),
        Pair(-1, 14), Pair(0, 13), Pair(-6, 13), Pair(14, 39), Pair(-3, -49), Pair(26, 28), Pair(-7, 18), Pair(1, 10),
        Pair(-4, 13), Pair(5, 13), Pair(13, 4), Pair(-3, 25), Pair(5, -6), Pair(2, 18), Pair(9, 7), Pair(-4, 15),
        Pair(1, 12), Pair(-2, 14), Pair(4, 15), Pair(-7, 18), Pair(2, 5), Pair(-3, 14), Pair(1, 11), Pair(-7, 15),
        Pair(-3, 17), Pair(-2, 12), Pair(9, 3), Pair(-21, 23), Pair(4, 9), Pair(-4, 21), Pair(-9, 14), Pair(-11, 20),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(43, 149), Pair(-105, 157), Pair(-41, 77), Pair(42, 18), Pair(-6, 58), Pair(18, 35), Pair(183, 59), Pair(-176, 269),
        Pair(-24, 17), Pair(-95, 95), Pair(-31, 72), Pair(60, 31), Pair(13, -52), Pair(-40, 77), Pair(131, 47), Pair(7, 119),
        Pair(80, 93), Pair(24, 129), Pair(85, 38), Pair(90, 57), Pair(0, 0), Pair(-36, 51), Pair(-67, 100), Pair(35, 32),
        Pair(-18, 49), Pair(-1, 91), Pair(6, 43), Pair(61, 91), Pair(-1, 99), Pair(64, 65), Pair(3, 41), Pair(55, 98),
        Pair(-29, 31), Pair(108, 29), Pair(14, 36), Pair(9, 53), Pair(-15, 69), Pair(37, 27), Pair(82, 44), Pair(15, 13),
        Pair(-1, 39), Pair(-31, 46), Pair(-10, 62), Pair(1, 16), Pair(-3, 39), Pair(4, 36), Pair(15, 20), Pair(1, 2),
        Pair(-75, 25), Pair(-53, 47), Pair(-10, 11), Pair(-20, 40), Pair(17, 28), Pair(5, 77), Pair(11, 53), Pair(-25, 22),
        Pair(-76, -2), Pair(-16, 8), Pair(65, -31), Pair(22, 19), Pair(-45, 27), Pair(-35, 104), Pair(-19, 17), Pair(-54, 8)
      },
      { // Piece 2
        Pair(139, -112), Pair(69, 8), Pair(109, 0), Pair(281, -77), Pair(194, -93), Pair(104, 43), Pair(94, -14), Pair(48, 97),
        Pair(59, -9), Pair(85, 25), Pair(7, 36), Pair(94, -16), Pair(65, -78), Pair(73, -30), Pair(28, 43), Pair(91, -30),
        Pair(30, -28), Pair(155, -1), Pair(77, -37), Pair(104, 39), Pair(0, 0), Pair(114, 14), Pair(24, -17), Pair(38, 41),
        Pair(27, 76), Pair(13, 37), Pair(77, 11), Pair(15, 19), Pair(-15, 105), Pair(55, -9), Pair(7, 82), Pair(10, 5),
        Pair(66, -42), Pair(2, 49), Pair(36, 13), Pair(17, 56), Pair(37, -14), Pair(34, 12), Pair(33, 14), Pair(-22, 20),
        Pair(4, 34), Pair(37, 13), Pair(9, 45), Pair(57, -3), Pair(13, 35), Pair(3, 25), Pair(5, 24), Pair(-26, 24),
        Pair(-8, 13), Pair(-9, 64), Pair(86, -43), Pair(18, 26), Pair(44, -1), Pair(36, 31), Pair(5, 17), Pair(-70, 73),
        Pair(17, 46), Pair(44, -1), Pair(-16, 50), Pair(25, -19), Pair(-50, 64), Pair(2, 23), Pair(2, 71), Pair(-10, -67)
      },
      { // Piece 3
        Pair(-53, 82), Pair(-12, 69), Pair(10, 65), Pair(-59, 65), Pair(-38, 47), Pair(75, 39), Pair(-309, 140), Pair(-107, 113),
        Pair(28, 66), Pair(-51, 93), Pair(44, 42), Pair(28, 55), Pair(8, -91), Pair(67, 49), Pair(117, 55), Pair(39, 80),
        Pair(58, 42), Pair(6, 41), Pair(30, 26), Pair(112, 7), Pair(0, 0), Pair(-28, 70), Pair(47, 48), Pair(-40, 74),
        Pair(31, 73), Pair(37, 31), Pair(116, 0), Pair(-9, 60), Pair(49, 17), Pair(-1, 54), Pair(-10, 75), Pair(-3, 83),
        Pair(-31, 29), Pair(83, -21), Pair(-11, 63), Pair(-48, 62), Pair(-12, 48), Pair(18, 59), Pair(101, 34), Pair(-11, 52),
        Pair(-57, 45), Pair(24, 43), Pair(-19, 50), Pair(-5, 22), Pair(14, 2), Pair(6, 37), Pair(-13, 50), Pair(-31, 42),
        Pair(-107, 88), Pair(-71, 62), Pair(-6, 54), Pair(-13, 65), Pair(-32, 58), Pair(-41, 87), Pair(-16, 59), Pair(-72, 96),
        Pair(-35, 56), Pair(-17, 61), Pair(-4, 26), Pair(-21, 39), Pair(7, 37), Pair(-23, 78), Pair(-19, 68), Pair(-6, 56)
      },
      { // Piece 4
        Pair(19, 26), Pair(-4, 112), Pair(37, 45), Pair(155, -74), Pair(51, 17), Pair(135, 35), Pair(-49, 54), Pair(5, 157),
        Pair(-13, 30), Pair(12, 72), Pair(128, -8), Pair(-20, 99), Pair(30, -35), Pair(63, 97), Pair(135, 96), Pair(17, -13),
        Pair(31, 13), Pair(101, -44), Pair(46, -112), Pair(45, 10), Pair(0, 0), Pair(88, 41), Pair(68, -27), Pair(105, 105),
        Pair(34, 109), Pair(46, 21), Pair(98, 27), Pair(2, 39), Pair(-9, 50), Pair(81, 9), Pair(40, 70), Pair(85, 78),
        Pair(-8, 91), Pair(116, -93), Pair(57, 9), Pair(7, 108), Pair(-29, 127), Pair(51, 35), Pair(71, 16), Pair(49, 105),
        Pair(38, -32), Pair(61, -58), Pair(21, 36), Pair(52, 13), Pair(19, 17), Pair(61, -45), Pair(85, -51), Pair(40, 44),
        Pair(41, 25), Pair(-20, 80), Pair(17, 75), Pair(20, 30), Pair(26, 23), Pair(23, 4), Pair(21, 48), Pair(-54, 120),
        Pair(23, 21), Pair(83, 48), Pair(74, -82), Pair(29, 56), Pair(6, 67), Pair(64, 73), Pair(135, -19), Pair(179, -117)
      },
      { // Piece 5
        Pair(52, 58), Pair(28, 11), Pair(22, 19), Pair(23, 118), Pair(125, 31), Pair(-12, 195), Pair(-10, 55), Pair(-34, 47),
        Pair(-35, -36), Pair(25, -13), Pair(-15, 61), Pair(67, 46), Pair(50, 10), Pair(144, 30), Pair(95, 19), Pair(-43, 19),
        Pair(71, 19), Pair(-57, 50), Pair(231, 0), Pair(37, 92), Pair(0, 0), Pair(33, 95), Pair(77, 3), Pair(1, 12),
        Pair(132, 0), Pair(111, -15), Pair(-55, 47), Pair(171, 46), Pair(-92, 89), Pair(76, 54), Pair(-34, 28), Pair(-85, 27),
        Pair(77, -18), Pair(-206, 48), Pair(-69, 25), Pair(-16, 52), Pair(33, 23), Pair(63, 10), Pair(69, -6), Pair(-91, 24),
        Pair(-239, 53), Pair(83, -20), Pair(7, -6), Pair(43, -16), Pair(50, -12), Pair(38, -15), Pair(45, -33), Pair(70, -37),
        Pair(-13, -37), Pair(27, -20), Pair(-10, -20), Pair(-61, -7), Pair(-8, -25), Pair(2, -24), Pair(18, -36), Pair(16, -32),
        Pair(-38, -51), Pair(13, -1), Pair(-31, -8), Pair(-24, -21), Pair(-24, -27), Pair(-10, -39), Pair(0, -39), Pair(20, -48)
      }
    }},
    {{ // Bucket 21
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-38, 36), Pair(29, 45), Pair(-92, 48), Pair(42, 30), Pair(108, -30), Pair(2, -73), Pair(28, -19), Pair(-17, 18),
        Pair(15, 14), Pair(-10, 19), Pair(34, 13), Pair(41, -3), Pair(17, 13), Pair(18, 21), Pair(-2, 1), Pair(-66, 3),
        Pair(-15, 19), Pair(11, 8), Pair(23, 10), Pair(12, 9), Pair(23, 4), Pair(-12, -20), Pair(-4, 10), Pair(-2, -1),
        Pair(1, 6), Pair(0, 15), Pair(-2, 13), Pair(7, 17), Pair(9, 16), Pair(-7, 8), Pair(-4, 13), Pair(2, 8),
        Pair(3, 9), Pair(2, 14), Pair(7, 7), Pair(-3, 11), Pair(-8, 13), Pair(-7, 7), Pair(-3, 12), Pair(-8, 12),
        Pair(0, 6), Pair(1, 8), Pair(4, 3), Pair(15, -7), Pair(-30, 43), Pair(-6, 9), Pair(0, 14), Pair(-5, 5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-2, -32), Pair(3, 93), Pair(4, -4), Pair(99, 10), Pair(-59, 11), Pair(-40, 85), Pair(-79, 103), Pair(-186, -35),
        Pair(-15, -46), Pair(149, -19), Pair(23, 33), Pair(64, 19), Pair(60, 13), Pair(-148, 11), Pair(16, 81), Pair(85, 54),
        Pair(-80, 79), Pair(-89, 62), Pair(-18, 31), Pair(10, 62), Pair(7, 40), Pair(0, 0), Pair(209, 30), Pair(-13, 90),
        Pair(-77, 16), Pair(-18, 24), Pair(-44, 75), Pair(39, 22), Pair(63, 72), Pair(72, 18), Pair(18, 88), Pair(-20, 28),
        Pair(-24, 17), Pair(-62, 52), Pair(-27, 65), Pair(-24, 51), Pair(44, 32), Pair(-48, 60), Pair(10, 46), Pair(-9, 63),
        Pair(-68, 87), Pair(-23, 59), Pair(-33, 61), Pair(-5, 25), Pair(-19, 57), Pair(-25, 65), Pair(-27, 18), Pair(-8, 30),
        Pair(-30, 54), Pair(78, -19), Pair(-63, 72), Pair(-31, 34), Pair(15, -10), Pair(-40, 17), Pair(-10, 22), Pair(-1, 0),
        Pair(-110, 78), Pair(-82, 55), Pair(-16, 87), Pair(12, 48), Pair(-31, -5), Pair(-85, 94), Pair(42, -78), Pair(108, -18)
      },
      { // Piece 2
        Pair(45, -22), Pair(135, -105), Pair(60, -22), Pair(61, 2), Pair(-185, 39), Pair(39, -58), Pair(-3, 48), Pair(-22, -19),
        Pair(80, -43), Pair(73, -13), Pair(36, -53), Pair(185, -17), Pair(122, -51), Pair(152, -117), Pair(184, -65), Pair(19, 25),
        Pair(-20, 29), Pair(103, -85), Pair(54, 24), Pair(32, -45), Pair(118, 10), Pair(0, 0), Pair(192, -38), Pair(-76, 32),
        Pair(-73, 6), Pair(39, 47), Pair(58, -49), Pair(26, 51), Pair(31, -16), Pair(-10, 64), Pair(32, -15), Pair(36, 27),
        Pair(10, 64), Pair(-4, -31), Pair(27, 27), Pair(-1, -1), Pair(16, 51), Pair(31, -44), Pair(52, 20), Pair(-35, 8),
        Pair(-34, 12), Pair(-13, 32), Pair(10, -19), Pair(12, 12), Pair(12, -24), Pair(-12, 30), Pair(14, -23), Pair(-22, 38),
        Pair(79, -11), Pair(-5, -14), Pair(51, 11), Pair(1, -14), Pair(-6, 7), Pair(28, -49), Pair(6, 9), Pair(-19, -26),
        Pair(0, -16), Pair(16, -6), Pair(-2, -42), Pair(-31, 33), Pair(13, -9), Pair(-45, 50), Pair(127, -109), Pair(-22, -45)
      },
      { // Piece 3
        Pair(6, 71), Pair(29, 57), Pair(-6, 65), Pair(20, 89), Pair(105, 70), Pair(34, 19), Pair(-57, 36), Pair(-44, 67),
        Pair(21, 66), Pair(33, 46), Pair(34, 56), Pair(23, 46), Pair(47, 43), Pair(10, -60), Pair(29, 64), Pair(86, 43),
        Pair(-41, 53), Pair(20, 42), Pair(9, 20), Pair(-3, 34), Pair(-56, 71), Pair(0, 0), Pair(84, 19), Pair(-60, 64),
        Pair(-45, 75), Pair(-35, 67), Pair(62, 27), Pair(-13, 30), Pair(23, 39), Pair(-48, 36), Pair(63, 44), Pair(-13, 47),
        Pair(-66, 41), Pair(30, 44), Pair(-46, 50), Pair(-8, 46), Pair(-1, 60), Pair(44, -1), Pair(40, 34), Pair(77, -21),
        Pair(-40, 59), Pair(-42, 43), Pair(-55, 51), Pair(-29, 43), Pair(-37, 51), Pair(32, -10), Pair(-22, 35), Pair(68, 27),
        Pair(-42, 44), Pair(29, 22), Pair(-76, 56), Pair(-43, 33), Pair(-24, 49), Pair(1, 9), Pair(16, 36), Pair(-89, 66),
        Pair(-23, 28), Pair(-36, 44), Pair(-20, 29), Pair(-19, 20), Pair(2, 2), Pair(11, 1), Pair(-19, 39), Pair(9, 32)
      },
      { // Piece 4
        Pair(110, 28), Pair(41, 26), Pair(-184, 205), Pair(149, -60), Pair(136, -24), Pair(77, -42), Pair(80, -132), Pair(142, -158),
        Pair(-45, 91), Pair(-31, 97), Pair(85, -8), Pair(71, -53), Pair(94, 53), Pair(161, -256), Pair(29, 14), Pair(71, 1),
        Pair(-5, 23), Pair(0, 88), Pair(17, 30), Pair(38, 20), Pair(-121, 194), Pair(0, 0), Pair(61, -67), Pair(133, 70),
        Pair(-41, 34), Pair(34, 34), Pair(76, -4), Pair(28, 37), Pair(35, 70), Pair(60, -57), Pair(57, 78), Pair(127, -8),
        Pair(-4, 21), Pair(58, 11), Pair(-75, 104), Pair(-47, 111), Pair(40, 23), Pair(82, -9), Pair(52, -11), Pair(25, 25),
        Pair(-60, 1), Pair(-51, 164), Pair(34, -67), Pair(22, -31), Pair(27, 2), Pair(32, 14), Pair(-1, 7), Pair(22, 70),
        Pair(56, -7), Pair(-33, 56), Pair(-12, 46), Pair(10, 28), Pair(-43, 59), Pair(40, -84), Pair(31, -19), Pair(85, -140),
        Pair(22, -11), Pair(-16, 43), Pair(-20, 14), Pair(-10, -7), Pair(-19, 45), Pair(-30, 47), Pair(12, -72), Pair(-52, 168)
      },
      { // Piece 5
        Pair(10, 51), Pair(93, -46), Pair(-36, 97), Pair(61, 27), Pair(-86, 102), Pair(85, 66), Pair(4, 197), Pair(-42, 4),
        Pair(-2, 1), Pair(-132, -14), Pair(64, -4), Pair(109, 35), Pair(179, 62), Pair(2, 28), Pair(1, 65), Pair(67, 67),
        Pair(-32, 32), Pair(86, -17), Pair(-29, 14), Pair(120, 28), Pair(-11, 77), Pair(0, 0), Pair(248, 10), Pair(103, 45),
        Pair(35, 11), Pair(-178, 31), Pair(52, -6), Pair(-34, 55), Pair(129, 22), Pair(-20, 47), Pair(23, 33), Pair(85, 47),
        Pair(-219, 26), Pair(38, -13), Pair(-109, 44), Pair(8, 11), Pair(-12, 44), Pair(22, 21), Pair(74, 11), Pair(5, 12),
        Pair(54, -39), Pair(-91, -3), Pair(-45, -5), Pair(-3, 6), Pair(108, -28), Pair(20, 2), Pair(-4, -11), Pair(17, 5),
        Pair(-30, -11), Pair(-13, -17), Pair(-6, -18), Pair(-17, -7), Pair(19, -35), Pair(17, -13), Pair(30, -38), Pair(-2, 5),
        Pair(-7, -57), Pair(-3, -55), Pair(-5, -26), Pair(-61, -28), Pair(15, -42), Pair(-48, -15), Pair(29, -39), Pair(7, -4)
      }
    }},
    {{ // Bucket 22
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-32, 12), Pair(-3, 53), Pair(-184, 50), Pair(-63, 44), Pair(15, 28), Pair(47, -15), Pair(89, -129), Pair(-33, -24),
        Pair(-49, 24), Pair(35, 24), Pair(-22, 41), Pair(-85, 40), Pair(29, 2), Pair(-2, -1), Pair(12, 46), Pair(7, -39),
        Pair(1, 10), Pair(21, 2), Pair(-9, 21), Pair(0, 21), Pair(13, 6), Pair(-8, 0), Pair(32, -47), Pair(-16, 2),
        Pair(-3, 6), Pair(0, 11), Pair(3, 10), Pair(-18, 14), Pair(-2, 14), Pair(-15, 22), Pair(4, -19), Pair(-14, 23),
        Pair(-7, 9), Pair(-11, 11), Pair(6, 7), Pair(-8, 8), Pair(-10, 12), Pair(-10, 16), Pair(-2, -6), Pair(-13, 20),
        Pair(-6, 15), Pair(-1, 11), Pair(-6, 18), Pair(-13, 24), Pair(-20, 28), Pair(-13, 18), Pair(-4, -14), Pair(2, 8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-74, -72), Pair(-101, 101), Pair(-151, 90), Pair(160, 39), Pair(-61, 75), Pair(-22, 54), Pair(-103, -4), Pair(-15, -37),
        Pair(-230, 87), Pair(-150, 32), Pair(-58, 40), Pair(-54, 107), Pair(61, -14), Pair(53, 75), Pair(-56, -25), Pair(-84, 40),
        Pair(156, -80), Pair(-44, 71), Pair(-45, 57), Pair(-72, 62), Pair(51, 29), Pair(48, 43), Pair(0, 0), Pair(66, -9),
        Pair(-149, 39), Pair(-1, 22), Pair(-26, 23), Pair(25, 29), Pair(36, 20), Pair(67, 40), Pair(60, 10), Pair(47, 13),
        Pair(-10, 42), Pair(-2, 9), Pair(-9, 20), Pair(-16, 18), Pair(46, 1), Pair(12, 23), Pair(36, 37), Pair(-30, 52),
        Pair(-66, 3), Pair(-14, -7), Pair(-37, 40), Pair(-47, 68), Pair(-67, 16), Pair(-42, 38), Pair(-6, 15), Pair(18, -38),
        Pair(-70, 14), Pair(-175, 8), Pair(-8, 30), Pair(-24, -17), Pair(-60, 46), Pair(-77, 19), Pair(-142, 29), Pair(23, -99),
        Pair(-144, 44), Pair(-43, 16), Pair(54, -23), Pair(-129, 113), Pair(-54, 16), Pair(-80, 41), Pair(1, -10), Pair(-93, -63)
      },
      { // Piece 2
        Pair(-134, -65), Pair(79, -63), Pair(-64, -30), Pair(-60, -37), Pair(147, -23), Pair(149, -56), Pair(20, 34), Pair(3, 78),
        Pair(4, 7), Pair(16, -78), Pair(-51, -1), Pair(66, -49), Pair(127, 33), Pair(98, -12), Pair(-129, -10), Pair(-122, -14),
        Pair(74, -36), Pair(85, -6), Pair(-66, -16), Pair(53, 6), Pair(164, -78), Pair(117, 26), Pair(0, 0), Pair(42, -5),
        Pair(-27, 30), Pair(17, -31), Pair(-69, 32), Pair(47, -48), Pair(24, 57), Pair(86, -27), Pair(4, 21), Pair(-53, -23),
        Pair(-59, -6), Pair(-61, 49), Pair(44, -14), Pair(2, 37), Pair(31, -35), Pair(-4, 48), Pair(-10, -22), Pair(60, -6),
        Pair(-11, 71), Pair(-15, -31), Pair(0, 43), Pair(5, -24), Pair(-8, 25), Pair(-18, -27), Pair(-30, 45), Pair(-8, -6),
        Pair(77, -12), Pair(3, 17), Pair(-34, -14), Pair(1, 6), Pair(-18, -8), Pair(-32, 69), Pair(2, -51), Pair(-36, 59),
        Pair(-13, 2), Pair(-20, -33), Pair(-5, 42), Pair(-35, 0), Pair(-76, 30), Pair(-46, 17), Pair(-36, 19), Pair(-28, -36)
      },
      { // Piece 3
        Pair(-17, 26), Pair(75, 20), Pair(113, 40), Pair(113, 0), Pair(135, 51), Pair(-57, 83), Pair(109, -16), Pair(22, 36),
        Pair(53, 47), Pair(-41, 57), Pair(64, 29), Pair(187, -15), Pair(-62, 53), Pair(88, 43), Pair(-20, -53), Pair(-53, 75),
        Pair(-21, 57), Pair(-26, 49), Pair(46, 30), Pair(-60, 22), Pair(-21, 54), Pair(72, 18), Pair(0, 0), Pair(-162, 81),
        Pair(-13, 62), Pair(61, 20), Pair(22, 70), Pair(-72, 54), Pair(3, 20), Pair(-92, 67), Pair(38, 14), Pair(-7, 21),
        Pair(-84, 76), Pair(-54, 101), Pair(-29, 68), Pair(9, 37), Pair(-18, 45), Pair(26, 29), Pair(-12, -9), Pair(42, 21),
        Pair(28, -10), Pair(-34, 46), Pair(-2, 38), Pair(-18, 34), Pair(-42, 60), Pair(-48, 63), Pair(6, 23), Pair(-63, 93),
        Pair(14, 26), Pair(25, 24), Pair(-40, 37), Pair(-23, 76), Pair(9, 28), Pair(-22, -3), Pair(-6, 23), Pair(-40, 38),
        Pair(-48, 13), Pair(-25, 45), Pair(-63, 62), Pair(-17, 25), Pair(-22, 25), Pair(-13, 28), Pair(19, -3), Pair(9, 10)
      },
      { // Piece 4
        Pair(7, -87), Pair(-103, 36), Pair(-12, -84), Pair(78, -72), Pair(24, 5), Pair(52, 1), Pair(-18, 67), Pair(98, -28),
        Pair(-36, 192), Pair(40, 28), Pair(123, -42), Pair(-8, 2), Pair(180, -113), Pair(-13, 72), Pair(179, -366), Pair(88, -27),
        Pair(121, -115), Pair(45, -47), Pair(-32, 162), Pair(15, 26), Pair(24, -13), Pair(170, -172), Pair(0, 0), Pair(58, -160),
        Pair(35, -126), Pair(-23, 94), Pair(61, 22), Pair(43, 6), Pair(95, -26), Pair(-15, -4), Pair(6, -36), Pair(60, -39),
        Pair(16, -38), Pair(-53, 178), Pair(20, -73), Pair(3, 31), Pair(-33, 33), Pair(-50, 25), Pair(56, -65), Pair(73, -2),
        Pair(55, -19), Pair(-34, 44), Pair(36, -32), Pair(20, -34), Pair(31, 9), Pair(14, 18), Pair(-14, 23), Pair(139, -160),
        Pair(143, -32), Pair(27, -102), Pair(-30, 19), Pair(-22, -37), Pair(-9, -51), Pair(-56, 13), Pair(-19, 9), Pair(-49, 14),
        Pair(-3, -60), Pair(-63, -62), Pair(-63, 27), Pair(14, -20), Pair(-8, -109), Pair(10, -6), Pair(0, -5), Pair(114, -98)
      },
      { // Piece 5
        Pair(-7, 125), Pair(71, 80), Pair(10, 138), Pair(-20, 58), Pair(-44, -35), Pair(24, 204), Pair(-3, 104), Pair(-65, 116),
        Pair(-18, 42), Pair(120, -32), Pair(6, -9), Pair(80, 24), Pair(-165, 97), Pair(115, 24), Pair(121, 18), Pair(102, 124),
        Pair(-197, 24), Pair(70, 23), Pair(150, -37), Pair(59, -41), Pair(81, -1), Pair(154, 42), Pair(0, 0), Pair(111, 54),
        Pair(67, 48), Pair(-23, 13), Pair(-57, 13), Pair(195, -25), Pair(3, 35), Pair(-36, 37), Pair(47, 39), Pair(-6, 52),
        Pair(-257, -11), Pair(-71, -6), Pair(132, -30), Pair(-39, -7), Pair(53, 3), Pair(1, 25), Pair(19, 19), Pair(122, 26),
        Pair(-91, -9), Pair(-50, -3), Pair(-121, 4), Pair(24, -19), Pair(-33, -4), Pair(21, -22), Pair(63, -6), Pair(16, 18),
        Pair(-68, -21), Pair(-51, -31), Pair(-10, -16), Pair(-89, -5), Pair(-25, -14), Pair(-3, -4), Pair(46, -12), Pair(35, -32),
        Pair(-73, -46), Pair(-59, 8), Pair(-54, 2), Pair(29, -27), Pair(-16, -44), Pair(46, -15), Pair(14, -15), Pair(29, -29)
      }
    }},
    {{ // Bucket 23
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-31, 28), Pair(25, 25), Pair(129, -17), Pair(-45, 30), Pair(5, -3), Pair(40, -3), Pair(88, -43), Pair(80, -97),
        Pair(8, 15), Pair(8, 17), Pair(-49, 41), Pair(2, 29), Pair(2, 28), Pair(-66, 5), Pair(8, -39), Pair(7, 32),
        Pair(-2, 19), Pair(-2, 14), Pair(-5, 17), Pair(8, 9), Pair(-2, 12), Pair(-12, 11), Pair(-17, -5), Pair(28, -42),
        Pair(-8, 19), Pair(2, 15), Pair(5, 4), Pair(-8, 19), Pair(-2, 11), Pair(-2, 10), Pair(8, 18), Pair(24, -5),
        Pair(1, 18), Pair(-1, 11), Pair(3, 9), Pair(-6, 5), Pair(-3, 4), Pair(-9, 12), Pair(4, 16), Pair(2, -3),
        Pair(-8, 22), Pair(-3, 11), Pair(1, 12), Pair(-4, -2), Pair(4, -3), Pair(0, 8), Pair(-1, 21), Pair(-5, 16),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-27, -67), Pair(-11, 84), Pair(-54, 105), Pair(-159, 18), Pair(148, 66), Pair(274, -34), Pair(-37, 92), Pair(7, -20),
        Pair(6, -7), Pair(-58, 35), Pair(-104, 41), Pair(-19, 70), Pair(44, 42), Pair(26, 38), Pair(71, 23), Pair(63, -72),
        Pair(-20, -30), Pair(37, 11), Pair(20, 39), Pair(65, 4), Pair(38, 27), Pair(5, 31), Pair(82, 74), Pair(0, 0),
        Pair(20, -15), Pair(22, 7), Pair(57, 17), Pair(71, -3), Pair(43, 49), Pair(59, 1), Pair(43, 52), Pair(85, 11),
        Pair(25, 20), Pair(3, 1), Pair(16, 32), Pair(17, 8), Pair(34, 23), Pair(13, 28), Pair(47, 4), Pair(13, -9),
        Pair(34, 26), Pair(20, 7), Pair(9, 17), Pair(35, 11), Pair(25, 7), Pair(27, 1), Pair(31, 1), Pair(-3, 4),
        Pair(16, 47), Pair(100, -5), Pair(23, 24), Pair(15, -9), Pair(34, 9), Pair(29, -5), Pair(7, -2), Pair(23, -24),
        Pair(60, -43), Pair(-22, 56), Pair(-6, 34), Pair(13, 24), Pair(38, -20), Pair(-31, -45), Pair(17, -15), Pair(-164, 83)
      },
      { // Piece 2
        Pair(206, 2), Pair(80, -50), Pair(-5, -39), Pair(195, -48), Pair(246, -41), Pair(97, -6), Pair(61, 16), Pair(-54, -23),
        Pair(6, -13), Pair(46, -5), Pair(-66, 19), Pair(108, -23), Pair(29, -28), Pair(43, 19), Pair(132, -5), Pair(-105, -16),
        Pair(39, 25), Pair(174, -40), Pair(110, -39), Pair(71, -39), Pair(147, -12), Pair(111, -22), Pair(180, -37), Pair(0, 0),
        Pair(-28, 57), Pair(68, -19), Pair(9, 0), Pair(84, -33), Pair(55, -5), Pair(18, 29), Pair(66, 2), Pair(98, 16),
        Pair(76, 13), Pair(38, -38), Pair(75, -11), Pair(31, 14), Pair(61, -15), Pair(44, 5), Pair(67, -5), Pair(20, -14),
        Pair(18, -15), Pair(23, -4), Pair(57, -15), Pair(48, -26), Pair(54, -10), Pair(3, 0), Pair(12, -17), Pair(30, 12),
        Pair(26, -34), Pair(30, 5), Pair(49, -15), Pair(40, -5), Pair(17, 16), Pair(41, -20), Pair(21, -19), Pair(-42, 113),
        Pair(29, -3), Pair(34, -1), Pair(23, 11), Pair(36, -3), Pair(27, -22), Pair(22, -5), Pair(21, -40), Pair(38, -77)
      },
      { // Piece 3
        Pair(-17, 36), Pair(66, 22), Pair(-12, 62), Pair(180, 3), Pair(137, 10), Pair(83, 35), Pair(159, 27), Pair(104, -19),
        Pair(59, 24), Pair(-5, 64), Pair(14, 55), Pair(167, -3), Pair(35, 35), Pair(0, 55), Pair(26, 64), Pair(138, -112),
        Pair(-18, 38), Pair(22, 31), Pair(-27, 51), Pair(21, 31), Pair(69, 24), Pair(82, 11), Pair(87, 25), Pair(0, 0),
        Pair(6, 25), Pair(5, 28), Pair(49, 18), Pair(19, 39), Pair(49, 13), Pair(-3, 64), Pair(-63, 53), Pair(-30, -7),
        Pair(1, 31), Pair(-17, 51), Pair(0, 40), Pair(4, 41), Pair(-14, 34), Pair(11, 9), Pair(-17, 45), Pair(-12, 15),
        Pair(3, 28), Pair(32, 2), Pair(29, 28), Pair(64, -37), Pair(33, 21), Pair(10, 21), Pair(-26, 23), Pair(-11, -7),
        Pair(36, 27), Pair(-1, 19), Pair(47, 1), Pair(-5, 15), Pair(10, 24), Pair(21, 25), Pair(-7, 18), Pair(-45, 9),
        Pair(23, 4), Pair(14, 20), Pair(19, 34), Pair(29, 8), Pair(16, 23), Pair(8, 31), Pair(1, 20), Pair(-8, -18)
      },
      { // Piece 4
        Pair(-32, 59), Pair(-14, 72), Pair(146, -27), Pair(63, -7), Pair(135, 11), Pair(126, 28), Pair(33, 12), Pair(101, 57),
        Pair(6, 172), Pair(-23, 66), Pair(107, 18), Pair(-57, 135), Pair(128, -10), Pair(143, 21), Pair(12, 81), Pair(-72, -52),
        Pair(-75, 194), Pair(19, 83), Pair(-39, 57), Pair(79, 26), Pair(58, 17), Pair(127, -7), Pair(62, -13), Pair(0, 0),
        Pair(-60, 96), Pair(-39, 121), Pair(34, 7), Pair(17, 67), Pair(88, 39), Pair(29, 2), Pair(57, 54), Pair(77, -84),
        Pair(3, 75), Pair(45, 27), Pair(-15, 119), Pair(53, 44), Pair(0, 55), Pair(56, 42), Pair(38, 23), Pair(25, 108),
        Pair(108, -99), Pair(31, 2), Pair(-3, 82), Pair(4, -16), Pair(22, 61), Pair(47, -40), Pair(25, -16), Pair(-14, 54),
        Pair(-16, 80), Pair(21, 11), Pair(23, -29), Pair(21, 50), Pair(30, -20), Pair(36, -32), Pair(14, 58), Pair(-3, -53),
        Pair(-17, 157), Pair(1, 4), Pair(41, 9), Pair(15, 27), Pair(-45, 136), Pair(44, 44), Pair(55, -29), Pair(-21, 3)
      },
      { // Piece 5
        Pair(-20, 3), Pair(-79, 85), Pair(10, 26), Pair(-79, -72), Pair(126, 40), Pair(-24, 118), Pair(-210, 119), Pair(166, -27),
        Pair(-82, -28), Pair(126, 65), Pair(112, -3), Pair(10, 111), Pair(171, -10), Pair(-50, 81), Pair(24, 64), Pair(93, -70),
        Pair(-45, 58), Pair(49, -8), Pair(19, 34), Pair(126, 0), Pair(77, 12), Pair(88, 26), Pair(131, 27), Pair(0, 0),
        Pair(-111, 49), Pair(-35, 35), Pair(107, -7), Pair(-130, 46), Pair(21, 19), Pair(77, 28), Pair(67, 21), Pair(165, -21),
        Pair(-46, 23), Pair(4, 33), Pair(-176, 45), Pair(-46, 24), Pair(30, 16), Pair(93, -1), Pair(107, 26), Pair(68, 6),
        Pair(-237, 27), Pair(-78, 11), Pair(-29, 4), Pair(-70, 16), Pair(37, 1), Pair(50, 3), Pair(34, -2), Pair(37, 13),
        Pair(-32, -21), Pair(-32, -2), Pair(-13, -7), Pair(-24, -8), Pair(7, -4), Pair(4, 2), Pair(3, 14), Pair(10, 18),
        Pair(2, -5), Pair(-8, -14), Pair(-13, -21), Pair(11, -41), Pair(-12, -11), Pair(16, -22), Pair(18, 24), Pair(31, -6)
      }
    }},
    {{ // Bucket 24
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-16, -1), Pair(-4, 49), Pair(-21, 20), Pair(18, 12), Pair(7, 15), Pair(15, 32), Pair(60, 10), Pair(0, 16),
        Pair(10, -31), Pair(10, 11), Pair(3, 19), Pair(12, 21), Pair(-1, 14), Pair(-13, 20), Pair(2, 9), Pair(-1, 20),
        Pair(-4, 13), Pair(-15, 0), Pair(-5, 7), Pair(9, 12), Pair(0, 9), Pair(9, 13), Pair(-4, 15), Pair(-4, 15),
        Pair(-10, -9), Pair(-8, 3), Pair(1, 10), Pair(2, 12), Pair(4, 13), Pair(3, 11), Pair(1, 14), Pair(-3, 15),
        Pair(1, 15), Pair(-10, 12), Pair(-1, 15), Pair(2, 7), Pair(-1, 14), Pair(3, 13), Pair(2, 16), Pair(-2, 16),
        Pair(0, 12), Pair(-6, 13), Pair(0, 9), Pair(0, 0), Pair(-4, 17), Pair(-6, 19), Pair(-3, 17), Pair(0, 18),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(7, 8), Pair(-170, 86), Pair(4, 76), Pair(80, 36), Pair(-63, 77), Pair(3, 43), Pair(72, 26), Pair(37, 31),
        Pair(37, 46), Pair(7, 39), Pair(16, 56), Pair(23, 46), Pair(56, 46), Pair(-84, 98), Pair(9, 32), Pair(-11, 76),
        Pair(19, 3), Pair(-2, 61), Pair(38, 44), Pair(-5, 58), Pair(22, 52), Pair(-18, 69), Pair(-28, 50), Pair(27, 15),
        Pair(0, 0), Pair(15, 50), Pair(13, 54), Pair(24, 49), Pair(14, 55), Pair(11, 46), Pair(-1, 49), Pair(-22, 70),
        Pair(13, 100), Pair(20, 70), Pair(29, 44), Pair(12, 56), Pair(8, 50), Pair(16, 47), Pair(18, 25), Pair(8, 31),
        Pair(21, 62), Pair(10, 37), Pair(14, 38), Pair(19, 46), Pair(24, 50), Pair(12, 39), Pair(13, 33), Pair(19, 18),
        Pair(4, 24), Pair(32, 30), Pair(7, 37), Pair(10, 39), Pair(6, 53), Pair(13, 33), Pair(9, 28), Pair(-10, 58),
        Pair(-16, 10), Pair(2, 17), Pair(-14, 40), Pair(37, 34), Pair(7, 47), Pair(18, 20), Pair(20, 9), Pair(102, -124)
      },
      { // Piece 2
        Pair(-65, 93), Pair(123, -15), Pair(-62, 90), Pair(56, -3), Pair(-12, 39), Pair(48, -10), Pair(29, 39), Pair(-3, -37),
        Pair(12, 28), Pair(41, 61), Pair(23, 14), Pair(9, 35), Pair(47, -17), Pair(15, 46), Pair(12, 2), Pair(-33, 82),
        Pair(4, 38), Pair(34, 44), Pair(29, 43), Pair(23, 15), Pair(58, 33), Pair(54, -5), Pair(0, 36), Pair(9, 32),
        Pair(0, 0), Pair(11, 61), Pair(32, 25), Pair(36, 47), Pair(17, 23), Pair(12, 58), Pair(27, 11), Pair(32, 45),
        Pair(32, 67), Pair(25, 34), Pair(36, 45), Pair(20, 24), Pair(14, 59), Pair(23, 22), Pair(36, 37), Pair(8, 17),
        Pair(9, 7), Pair(14, 58), Pair(20, 29), Pair(17, 60), Pair(23, 34), Pair(14, 57), Pair(19, 18), Pair(19, 12),
        Pair(46, -19), Pair(9, 16), Pair(15, 23), Pair(15, 23), Pair(14, 59), Pair(20, 37), Pair(12, 56), Pair(27, 31),
        Pair(45, -30), Pair(-11, 40), Pair(5, 15), Pair(21, 36), Pair(11, 26), Pair(10, 58), Pair(-3, 36), Pair(1, 40)
      },
      { // Piece 3
        Pair(20, 42), Pair(-17, 113), Pair(16, 83), Pair(-43, 110), Pair(-75, 126), Pair(0, 78), Pair(-55, 111), Pair(-5, 94),
        Pair(-17, 62), Pair(-5, 94), Pair(23, 87), Pair(9, 85), Pair(10, 70), Pair(-23, 97), Pair(4, 85), Pair(22, 70),
        Pair(-37, 46), Pair(13, 92), Pair(-6, 105), Pair(8, 93), Pair(-4, 97), Pair(11, 92), Pair(58, 70), Pair(-20, 106),
        Pair(0, 0), Pair(6, 95), Pair(9, 90), Pair(1, 86), Pair(-5, 97), Pair(14, 86), Pair(16, 92), Pair(-10, 94),
        Pair(-26, 77), Pair(14, 85), Pair(25, 86), Pair(7, 92), Pair(4, 82), Pair(-13, 97), Pair(-33, 107), Pair(4, 94),
        Pair(-31, 88), Pair(-7, 90), Pair(10, 72), Pair(8, 82), Pair(8, 86), Pair(17, 62), Pair(1, 71), Pair(46, 50),
        Pair(-44, 71), Pair(-2, 91), Pair(-1, 76), Pair(20, 61), Pair(3, 81), Pair(7, 75), Pair(4, 65), Pair(-18, 54),
        Pair(-23, 61), Pair(-3, 87), Pair(0, 90), Pair(4, 82), Pair(0, 81), Pair(-2, 80), Pair(14, 68), Pair(15, 60)
      },
      { // Piece 4
        Pair(4, 167), Pair(69, 92), Pair(-16, 182), Pair(-68, 202), Pair(-38, 178), Pair(-8, 153), Pair(174, 53), Pair(24, 212),
        Pair(-12, 140), Pair(24, 151), Pair(23, 153), Pair(34, 122), Pair(43, 145), Pair(31, 185), Pair(54, 164), Pair(88, 57),
        Pair(8, 91), Pair(16, 197), Pair(18, 175), Pair(20, 151), Pair(48, 130), Pair(30, 175), Pair(51, 78), Pair(5, 187),
        Pair(0, 0), Pair(31, 170), Pair(18, 179), Pair(13, 180), Pair(34, 145), Pair(15, 138), Pair(32, 142), Pair(27, 155),
        Pair(20, 158), Pair(31, 191), Pair(33, 179), Pair(37, 148), Pair(34, 153), Pair(40, 144), Pair(40, 113), Pair(29, 132),
        Pair(11, 173), Pair(37, 143), Pair(27, 165), Pair(32, 141), Pair(46, 153), Pair(28, 157), Pair(34, 127), Pair(65, 57),
        Pair(26, 152), Pair(40, 119), Pair(33, 138), Pair(28, 168), Pair(32, 162), Pair(46, 118), Pair(52, 88), Pair(39, 117),
        Pair(35, 83), Pair(25, 132), Pair(34, 151), Pair(35, 149), Pair(34, 152), Pair(61, 108), Pair(-26, 224), Pair(-12, 168)
      },
      { // Piece 5
        Pair(69, -24), Pair(94, 101), Pair(-86, 107), Pair(-20, 8), Pair(-30, 90), Pair(-52, 72), Pair(60, 7), Pair(96, -8),
        Pair(-125, 138), Pair(-18, 171), Pair(-14, 79), Pair(-28, 81), Pair(-51, 47), Pair(21, 58), Pair(151, -26), Pair(134, -30),
        Pair(-11, 40), Pair(67, 86), Pair(91, 83), Pair(18, 47), Pair(58, 48), Pair(-13, 19), Pair(-115, 38), Pair(-128, 21),
        Pair(0, 0), Pair(23, 85), Pair(39, 73), Pair(21, 67), Pair(60, 34), Pair(-42, 37), Pair(-14, 18), Pair(-110, 34),
        Pair(-29, 28), Pair(42, 50), Pair(2, 70), Pair(-31, 54), Pair(-24, 49), Pair(-31, 25), Pair(-41, 21), Pair(-67, 24),
        Pair(77, 21), Pair(46, 49), Pair(15, 37), Pair(-19, 48), Pair(-22, 37), Pair(-46, 23), Pair(-27, 11), Pair(-39, 0),
        Pair(88, -4), Pair(89, 37), Pair(6, 33), Pair(-3, 25), Pair(-17, 23), Pair(-31, 23), Pair(-12, 7), Pair(-15, -3),
        Pair(77, -12), Pair(87, -6), Pair(22, 16), Pair(-42, 37), Pair(-24, 16), Pair(-19, 7), Pair(-5, -3), Pair(-12, -1)
      }
    }},
    {{ // Bucket 25
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(8, 35), Pair(17, -14), Pair(-50, 53), Pair(16, 17), Pair(9, 4), Pair(-30, 26), Pair(-14, 19), Pair(-23, 19),
        Pair(-10, -3), Pair(5, -29), Pair(13, 27), Pair(8, 19), Pair(1, 14), Pair(10, 8), Pair(21, 4), Pair(-2, 14),
        Pair(-13, 0), Pair(-1, 22), Pair(-5, 9), Pair(-6, 0), Pair(6, 10), Pair(9, 7), Pair(2, 16), Pair(1, 14),
        Pair(1, 7), Pair(4, -14), Pair(2, 7), Pair(3, 6), Pair(2, 14), Pair(9, 9), Pair(4, 12), Pair(-1, 12),
        Pair(-4, 14), Pair(7, 5), Pair(-4, 10), Pair(1, 12), Pair(2, 10), Pair(4, 9), Pair(4, 17), Pair(1, 16),
        Pair(-5, 14), Pair(6, 5), Pair(-8, 16), Pair(3, 5), Pair(-4, 17), Pair(3, 15), Pair(0, 16), Pair(-1, 17),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(10, 108), Pair(312, -5), Pair(86, 50), Pair(38, 61), Pair(32, 47), Pair(-193, 105), Pair(111, -88), Pair(9, -113),
        Pair(29, 52), Pair(19, 56), Pair(4, 49), Pair(20, 79), Pair(11, 49), Pair(21, 20), Pair(10, 40), Pair(-60, 65),
        Pair(12, 38), Pair(4, 32), Pair(60, 36), Pair(17, 51), Pair(-42, 73), Pair(2, 80), Pair(-9, 63), Pair(-2, 35),
        Pair(33, 53), Pair(0, 0), Pair(21, 68), Pair(5, 65), Pair(6, 60), Pair(-8, 59), Pair(2, 47), Pair(-3, 61),
        Pair(12, 88), Pair(24, 81), Pair(17, 68), Pair(9, 49), Pair(3, 70), Pair(15, 58), Pair(-15, 58), Pair(-6, 50),
        Pair(-12, 30), Pair(16, 64), Pair(1, 44), Pair(14, 52), Pair(16, 54), Pair(10, 47), Pair(5, 53), Pair(13, 29),
        Pair(-32, 18), Pair(27, 51), Pair(8, 42), Pair(8, 54), Pair(6, 44), Pair(-9, 51), Pair(1, 49), Pair(2, 49),
        Pair(-51, 85), Pair(-3, 40), Pair(-8, 28), Pair(-10, 80), Pair(12, 52), Pair(6, 53), Pair(7, 4), Pair(49, -9)
      },
      { // Piece 2
        Pair(70, 34), Pair(-34, 59), Pair(125, 2), Pair(-39, 61), Pair(-72, 16), Pair(27, 23), Pair(135, 3), Pair(1, 68),
        Pair(52, 31), Pair(14, 10), Pair(-18, 70), Pair(-42, 11), Pair(60, 5), Pair(-14, 13), Pair(52, 34), Pair(29, 19),
        Pair(-12, 17), Pair(22, 15), Pair(84, -4), Pair(36, 27), Pair(60, -2), Pair(19, 21), Pair(51, -12), Pair(-3, 23),
        Pair(-5, 62), Pair(0, 0), Pair(36, 35), Pair(22, 16), Pair(20, 40), Pair(31, -3), Pair(4, 56), Pair(18, 26),
        Pair(-30, -17), Pair(34, 57), Pair(10, 14), Pair(19, 56), Pair(10, 28), Pair(8, 49), Pair(33, -1), Pair(15, 38),
        Pair(6, 39), Pair(9, 27), Pair(16, 26), Pair(8, 14), Pair(7, 62), Pair(15, 24), Pair(25, 62), Pair(14, 22),
        Pair(-22, 5), Pair(6, 43), Pair(5, 19), Pair(3, 48), Pair(7, 21), Pair(20, 55), Pair(12, 36), Pair(6, 81),
        Pair(17, 19), Pair(29, 6), Pair(-2, 39), Pair(14, 10), Pair(13, 35), Pair(0, 32), Pair(26, 46), Pair(12, 7)
      },
      { // Piece 3
        Pair(10, 77), Pair(1, 58), Pair(-3, 73), Pair(-34, 101), Pair(-77, 105), Pair(-63, 93), Pair(35, 100), Pair(-17, 74),
        Pair(2, 75), Pair(-30, 66), Pair(10, 69), Pair(22, 74), Pair(-18, 85), Pair(-61, 106), Pair(15, 76), Pair(-34, 97),
        Pair(-20, 99), Pair(-52, 36), Pair(3, 93), Pair(13, 88), Pair(-5, 78), Pair(-62, 115), Pair(19, 87), Pair(-2, 94),
        Pair(-30, 86), Pair(0, 0), Pair(1, 84), Pair(-17, 77), Pair(3, 61), Pair(-2, 84), Pair(-20, 88), Pair(-15, 88),
        Pair(-23, 88), Pair(-30, 88), Pair(-1, 88), Pair(-4, 94), Pair(-4, 81), Pair(-12, 77), Pair(4, 96), Pair(6, 67),
        Pair(0, 70), Pair(-24, 57), Pair(11, 60), Pair(20, 69), Pair(7, 58), Pair(-19, 87), Pair(-7, 45), Pair(-2, 49),
        Pair(6, 72), Pair(-17, 58), Pair(-5, 74), Pair(3, 65), Pair(7, 54), Pair(7, 58), Pair(1, 82), Pair(-16, 67),
        Pair(-4, 70), Pair(-17, 57), Pair(2, 68), Pair(0, 73), Pair(-2, 66), Pair(-5, 69), Pair(-3, 63), Pair(3, 66)
      },
      { // Piece 4
        Pair(33, 72), Pair(28, 55), Pair(5, 126), Pair(-76, 144), Pair(30, 60), Pair(80, 18), Pair(31, 111), Pair(58, 67),
        Pair(19, 71), Pair(6, 58), Pair(11, 67), Pair(4, 116), Pair(23, 109), Pair(21, 95), Pair(63, 54), Pair(-30, 104),
        Pair(-14, 97), Pair(3, 17), Pair(30, 68), Pair(13, 96), Pair(-33, 164), Pair(-21, 147), Pair(-6, 128), Pair(7, 73),
        Pair(-5, 95), Pair(0, 0), Pair(3, 103), Pair(-16, 116), Pair(7, 72), Pair(28, 75), Pair(-16, 104), Pair(13, 112),
        Pair(-2, 100), Pair(11, 92), Pair(26, 79), Pair(17, 89), Pair(11, 101), Pair(-15, 119), Pair(6, 98), Pair(17, 57),
        Pair(-4, 112), Pair(17, 55), Pair(9, 97), Pair(13, 95), Pair(21, 79), Pair(11, 98), Pair(2, 61), Pair(-6, 101),
        Pair(8, 67), Pair(7, 69), Pair(14, 83), Pair(7, 113), Pair(12, 86), Pair(28, 70), Pair(11, 77), Pair(17, 29),
        Pair(-2, 88), Pair(12, 61), Pair(15, 83), Pair(9, 98), Pair(-2, 113), Pair(-5, 118), Pair(25, 75), Pair(12, 78)
      },
      { // Piece 5
        Pair(-45, 129), Pair(76, 124), Pair(25, 151), Pair(133, 99), Pair(-101, 186), Pair(70, -51), Pair(47, 7), Pair(3, 97),
        Pair(-220, 157), Pair(-169, 151), Pair(138, 124), Pair(106, 70), Pair(150, 51), Pair(93, 46), Pair(100, 47), Pair(113, 59),
        Pair(24, 65), Pair(-34, 69), Pair(244, 24), Pair(-84, 112), Pair(98, 31), Pair(1, 46), Pair(25, 27), Pair(-108, 10),
        Pair(81, 99), Pair(0, 0), Pair(119, 64), Pair(18, 65), Pair(-9, 62), Pair(-56, 29), Pair(-114, 37), Pair(-70, 15),
        Pair(61, 48), Pair(94, 40), Pair(46, 43), Pair(-39, 65), Pair(-2, 36), Pair(-52, 28), Pair(31, 0), Pair(-29, 4),
        Pair(23, 67), Pair(76, 20), Pair(68, 30), Pair(-5, 38), Pair(-10, 24), Pair(-24, 19), Pair(-47, 17), Pair(-52, 20),
        Pair(109, 19), Pair(24, 23), Pair(3, 29), Pair(5, 16), Pair(-13, 14), Pair(-42, 24), Pair(-15, 11), Pair(-12, -6),
        Pair(33, 6), Pair(49, -33), Pair(20, 6), Pair(-10, 13), Pair(-19, 11), Pair(-23, 6), Pair(-2, -8), Pair(-1, -16)
      }
    }},
    {{ // Bucket 26
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(35, 7), Pair(-5, 31), Pair(-93, 16), Pair(2, 60), Pair(24, 29), Pair(-82, 59), Pair(53, -1), Pair(-2, 18),
        Pair(1, 15), Pair(7, 20), Pair(-23, -43), Pair(18, 41), Pair(-6, 11), Pair(24, 9), Pair(-9, 20), Pair(-5, 16),
        Pair(-8, 7), Pair(-5, 9), Pair(1, 5), Pair(1, 10), Pair(5, 2), Pair(14, 11), Pair(0, 15), Pair(6, 14),
        Pair(0, 13), Pair(8, 14), Pair(-7, -32), Pair(12, 17), Pair(4, 6), Pair(11, 10), Pair(1, 13), Pair(-1, 15),
        Pair(4, 18), Pair(-4, 11), Pair(1, -4), Pair(-6, 19), Pair(4, 13), Pair(6, 11), Pair(3, 15), Pair(3, 14),
        Pair(0, 13), Pair(-6, 15), Pair(-1, -11), Pair(-3, 19), Pair(-1, 19), Pair(4, 17), Pair(3, 15), Pair(3, 13),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-62, 73), Pair(63, 68), Pair(85, 28), Pair(68, 68), Pair(-12, 123), Pair(94, 53), Pair(-136, 69), Pair(95, 82),
        Pair(27, 67), Pair(1, 74), Pair(16, 55), Pair(35, 33), Pair(38, 26), Pair(33, 43), Pair(-2, 112), Pair(45, 35),
        Pair(4, 59), Pair(-24, 74), Pair(-34, 57), Pair(40, 64), Pair(38, 52), Pair(8, 66), Pair(6, 89), Pair(-21, 44),
        Pair(-32, 95), Pair(2, 77), Pair(0, 0), Pair(33, 76), Pair(17, 66), Pair(47, 51), Pair(-1, 49), Pair(9, 50),
        Pair(-15, 49), Pair(30, 84), Pair(30, 102), Pair(20, 83), Pair(3, 56), Pair(17, 51), Pair(12, 61), Pair(8, 47),
        Pair(1, 56), Pair(7, 46), Pair(17, 61), Pair(17, 59), Pair(11, 75), Pair(10, 58), Pair(1, 61), Pair(18, 32),
        Pair(2, 61), Pair(5, 33), Pair(18, 51), Pair(7, 59), Pair(12, 49), Pair(27, 38), Pair(8, 68), Pair(18, 63),
        Pair(40, 0), Pair(-1, 65), Pair(-4, 45), Pair(-7, 65), Pair(16, 53), Pair(3, 70), Pair(9, 46), Pair(74, 37)
      },
      { // Piece 2
        Pair(-68, 73), Pair(48, 9), Pair(78, 57), Pair(-4, 12), Pair(32, 65), Pair(8, 3), Pair(69, 41), Pair(140, 16),
        Pair(14, 26), Pair(45, 67), Pair(3, 20), Pair(45, 81), Pair(40, -8), Pair(54, 47), Pair(19, 0), Pair(17, 52),
        Pair(13, 59), Pair(-40, 28), Pair(28, -3), Pair(58, 18), Pair(18, 47), Pair(34, 15), Pair(21, 54), Pair(-12, 28),
        Pair(-16, 35), Pair(23, 42), Pair(0, 0), Pair(15, 57), Pair(31, 27), Pair(11, 49), Pair(6, 23), Pair(0, 68),
        Pair(43, 46), Pair(-4, 16), Pair(39, 74), Pair(21, 21), Pair(6, 72), Pair(27, 25), Pair(23, 40), Pair(21, 9),
        Pair(-17, 13), Pair(9, 51), Pair(13, 24), Pair(9, 63), Pair(1, 25), Pair(15, 57), Pair(38, 26), Pair(12, 64),
        Pair(4, 14), Pair(-2, 33), Pair(17, 70), Pair(3, 31), Pair(16, 45), Pair(3, 27), Pair(18, 56), Pair(39, 23),
        Pair(-4, 25), Pair(0, 56), Pair(-2, 11), Pair(10, 47), Pair(15, 30), Pair(13, 47), Pair(-11, 54), Pair(26, 57)
      },
      { // Piece 3
        Pair(-17, 111), Pair(-9, 97), Pair(-11, 65), Pair(-29, 95), Pair(-37, 100), Pair(-83, 107), Pair(-24, 88), Pair(62, 83),
        Pair(16, 89), Pair(0, 85), Pair(-23, 74), Pair(23, 88), Pair(-26, 102), Pair(-20, 100), Pair(55, 86), Pair(21, 79),
        Pair(2, 92), Pair(25, 81), Pair(-28, 51), Pair(7, 92), Pair(21, 101), Pair(5, 104), Pair(-23, 103), Pair(42, 96),
        Pair(3, 67), Pair(2, 79), Pair(0, 0), Pair(12, 80), Pair(-2, 81), Pair(-4, 87), Pair(-9, 106), Pair(42, 66),
        Pair(14, 90), Pair(8, 93), Pair(-21, 84), Pair(-5, 95), Pair(-10, 87), Pair(-18, 86), Pair(-4, 69), Pair(-2, 66),
        Pair(14, 88), Pair(-11, 101), Pair(-5, 56), Pair(5, 64), Pair(4, 82), Pair(-18, 79), Pair(-4, 100), Pair(16, 57),
        Pair(-2, 81), Pair(7, 84), Pair(-11, 64), Pair(-12, 88), Pair(9, 65), Pair(-10, 86), Pair(-6, 93), Pair(34, 48),
        Pair(-2, 80), Pair(7, 76), Pair(-11, 63), Pair(3, 67), Pair(0, 73), Pair(-2, 66), Pair(2, 76), Pair(9, 47)
      },
      { // Piece 4
        Pair(83, 26), Pair(31, 105), Pair(-12, 108), Pair(4, 129), Pair(-14, 102), Pair(89, 101), Pair(51, 120), Pair(25, 111),
        Pair(21, 56), Pair(23, 107), Pair(0, 74), Pair(20, 140), Pair(20, 109), Pair(63, 67), Pair(34, 165), Pair(4, 101),
        Pair(-21, 178), Pair(31, 111), Pair(1, 44), Pair(-24, 188), Pair(38, 99), Pair(-6, 196), Pair(30, 95), Pair(-5, 121),
        Pair(-27, 172), Pair(9, 107), Pair(0, 0), Pair(-8, 151), Pair(2, 143), Pair(22, 109), Pair(2, 125), Pair(7, 89),
        Pair(13, 124), Pair(24, 101), Pair(12, 119), Pair(29, 102), Pair(14, 124), Pair(9, 129), Pair(-11, 155), Pair(9, 99),
        Pair(9, 91), Pair(23, 117), Pair(12, 117), Pair(29, 85), Pair(16, 113), Pair(10, 128), Pair(3, 145), Pair(25, 114),
        Pair(-11, 172), Pair(12, 113), Pair(18, 104), Pair(19, 125), Pair(26, 93), Pair(18, 113), Pair(25, 90), Pair(77, 14),
        Pair(54, 13), Pair(-11, 175), Pair(1, 137), Pair(15, 116), Pair(24, 101), Pair(36, 62), Pair(61, 3), Pair(38, 107)
      },
      { // Piece 5
        Pair(-31, 62), Pair(30, 156), Pair(84, 70), Pair(91, 162), Pair(-26, 1), Pair(304, -31), Pair(-8, 38), Pair(-81, -8),
        Pair(87, 39), Pair(75, 139), Pair(143, 91), Pair(85, 102), Pair(125, -37), Pair(-23, 60), Pair(-190, 53), Pair(-94, 3),
        Pair(200, 58), Pair(204, 23), Pair(93, 36), Pair(197, 52), Pair(51, 66), Pair(107, 14), Pair(0, 23), Pair(-114, 42),
        Pair(151, 49), Pair(120, 61), Pair(0, 0), Pair(165, 52), Pair(128, 24), Pair(112, 4), Pair(-47, 13), Pair(-78, -6),
        Pair(-61, 67), Pair(81, 30), Pair(53, 46), Pair(34, 40), Pair(-63, 43), Pair(-32, 16), Pair(-44, 8), Pair(-31, -2),
        Pair(11, 48), Pair(3, 31), Pair(8, 20), Pair(28, 28), Pair(9, 8), Pair(-17, 2), Pair(15, -11), Pair(-25, -1),
        Pair(31, 12), Pair(29, -1), Pair(23, -18), Pair(31, -4), Pair(-15, -5), Pair(-11, -12), Pair(-12, -14), Pair(-11, -17),
        Pair(20, -20), Pair(12, -9), Pair(20, -8), Pair(21, -23), Pair(-13, -21), Pair(-17, -15), Pair(-4, -26), Pair(-7, -38)
      }
    }},
    {{ // Bucket 27
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-1, 19), Pair(-11, 23), Pair(-31, 55), Pair(9, -6), Pair(32, 37), Pair(21, -16), Pair(-13, 5), Pair(0, 17),
        Pair(-4, 21), Pair(-13, 19), Pair(7, 35), Pair(-4, -35), Pair(12, 38), Pair(12, 8), Pair(-2, 21), Pair(9, 10),
        Pair(7, 10), Pair(-5, 0), Pair(1, 10), Pair(6, -10), Pair(1, 18), Pair(1, 5), Pair(7, 12), Pair(4, 7),
        Pair(-1, 14), Pair(4, 6), Pair(5, 13), Pair(-2, -8), Pair(10, 20), Pair(7, 9), Pair(8, 7), Pair(3, 10),
        Pair(-3, 13), Pair(6, 12), Pair(-7, 19), Pair(13, 8), Pair(-2, 19), Pair(7, 16), Pair(7, 10), Pair(3, 10),
        Pair(-5, 16), Pair(1, 12), Pair(-2, 16), Pair(11, 7), Pair(-4, 28), Pair(-5, 14), Pair(2, 11), Pair(1, 12),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(16, 101), Pair(-43, 124), Pair(30, 83), Pair(-85, 116), Pair(-57, 56), Pair(-55, 17), Pair(88, 41), Pair(-77, 66),
        Pair(17, 70), Pair(-40, 114), Pair(2, 30), Pair(21, 75), Pair(37, 51), Pair(34, 57), Pair(-16, 94), Pair(-61, 93),
        Pair(50, 5), Pair(19, 56), Pair(52, 43), Pair(-13, 18), Pair(46, 67), Pair(9, 40), Pair(-20, 92), Pair(16, 48),
        Pair(28, 69), Pair(5, 73), Pair(20, 72), Pair(0, 0), Pair(16, 61), Pair(21, 67), Pair(7, 70), Pair(-14, 79),
        Pair(5, 76), Pair(-11, 63), Pair(24, 81), Pair(23, 89), Pair(12, 85), Pair(0, 43), Pair(-16, 72), Pair(4, 48),
        Pair(-8, 76), Pair(-1, 70), Pair(-2, 48), Pair(17, 59), Pair(5, 36), Pair(6, 66), Pair(9, 56), Pair(13, 32),
        Pair(-13, 55), Pair(27, 35), Pair(5, 61), Pair(7, 81), Pair(8, 48), Pair(7, 55), Pair(-6, 60), Pair(-8, 68),
        Pair(-2, 121), Pair(-5, 40), Pair(-16, 61), Pair(17, 45), Pair(-6, 74), Pair(-5, 71), Pair(2, 37), Pair(41, -61)
      },
      { // Piece 2
        Pair(-125, -23), Pair(-58, 61), Pair(199, -33), Pair(67, 31), Pair(62, -16), Pair(0, 23), Pair(15, -6), Pair(-47, 19),
        Pair(31, 38), Pair(6, -50), Pair(43, 54), Pair(52, -10), Pair(87, 35), Pair(23, -40), Pair(13, 16), Pair(-34, 15),
        Pair(11, -8), Pair(33, 48), Pair(-3, -28), Pair(13, -6), Pair(62, 18), Pair(10, 45), Pair(32, -15), Pair(0, 58),
        Pair(32, 59), Pair(12, 20), Pair(27, 25), Pair(0, 0), Pair(20, 48), Pair(10, 1), Pair(12, 54), Pair(-5, 18),
        Pair(22, -9), Pair(32, 39), Pair(2, -5), Pair(42, 60), Pair(-9, 3), Pair(18, 47), Pair(18, -3), Pair(6, 52),
        Pair(17, 58), Pair(-17, 2), Pair(22, 40), Pair(9, 11), Pair(14, 52), Pair(-3, 1), Pair(21, 49), Pair(14, 6),
        Pair(-6, -25), Pair(7, 55), Pair(8, 6), Pair(20, 50), Pair(1, 16), Pair(11, 45), Pair(-11, 9), Pair(13, 49),
        Pair(13, 15), Pair(10, 30), Pair(7, 52), Pair(14, 1), Pair(23, 53), Pair(-1, 17), Pair(18, 37), Pair(0, -30)
      },
      { // Piece 3
        Pair(-19, 78), Pair(-18, 81), Pair(-35, 95), Pair(-4, 60), Pair(-55, 99), Pair(-60, 68), Pair(-37, 86), Pair(52, 52),
        Pair(-6, 77), Pair(-9, 90), Pair(13, 60), Pair(-13, 60), Pair(25, 62), Pair(-8, 69), Pair(-13, 76), Pair(-25, 73),
        Pair(2, 73), Pair(-20, 91), Pair(-9, 85), Pair(-73, 24), Pair(2, 84), Pair(-18, 87), Pair(9, 85), Pair(-4, 87),
        Pair(-2, 65), Pair(-8, 71), Pair(0, 44), Pair(0, 0), Pair(-9, 63), Pair(7, 58), Pair(15, 62), Pair(8, 58),
        Pair(3, 60), Pair(-5, 67), Pair(8, 71), Pair(27, 30), Pair(-1, 67), Pair(-1, 60), Pair(5, 62), Pair(-31, 68),
        Pair(5, 59), Pair(8, 63), Pair(7, 74), Pair(6, 40), Pair(13, 50), Pair(-11, 65), Pair(-1, 74), Pair(16, 39),
        Pair(2, 53), Pair(3, 49), Pair(-10, 58), Pair(-9, 51), Pair(-10, 71), Pair(-14, 57), Pair(7, 56), Pair(8, 29),
        Pair(-2, 58), Pair(2, 54), Pair(-5, 70), Pair(4, 49), Pair(-1, 64), Pair(-4, 61), Pair(8, 55), Pair(5, 50)
      },
      { // Piece 4
        Pair(-77, 95), Pair(6, 110), Pair(1, 114), Pair(-21, 119), Pair(-78, 171), Pair(77, 54), Pair(74, 72), Pair(71, 131),
        Pair(5, 75), Pair(13, 46), Pair(22, 93), Pair(43, 59), Pair(14, 106), Pair(25, 73), Pair(69, 47), Pair(21, 94),
        Pair(6, 114), Pair(17, 107), Pair(7, 69), Pair(-17, 1), Pair(-29, 138), Pair(-34, 144), Pair(0, 124), Pair(-12, 105),
        Pair(-17, 138), Pair(-11, 103), Pair(0, 75), Pair(0, 0), Pair(-22, 135), Pair(9, 91), Pair(2, 89), Pair(3, 89),
        Pair(-2, 146), Pair(12, 98), Pair(3, 110), Pair(22, 81), Pair(-13, 108), Pair(17, 86), Pair(3, 106), Pair(27, 37),
        Pair(31, 49), Pair(17, 72), Pair(16, 101), Pair(7, 103), Pair(6, 114), Pair(1, 119), Pair(7, 79), Pair(3, 97),
        Pair(-1, 80), Pair(10, 108), Pair(9, 106), Pair(22, 64), Pair(6, 108), Pair(6, 102), Pair(-14, 113), Pair(12, 72),
        Pair(4, 107), Pair(11, 79), Pair(3, 111), Pair(10, 98), Pair(6, 101), Pair(-6, 115), Pair(33, 51), Pair(-13, 116)
      },
      { // Piece 5
        Pair(9, 113), Pair(80, 178), Pair(88, 143), Pair(-138, 142), Pair(101, 111), Pair(115, 14), Pair(11, 77), Pair(-31, 30),
        Pair(120, 35), Pair(199, 87), Pair(-56, 115), Pair(76, 122), Pair(-92, 97), Pair(-51, 37), Pair(0, 12), Pair(141, -12),
        Pair(-139, 64), Pair(50, 48), Pair(191, 40), Pair(-51, 63), Pair(95, 35), Pair(129, 28), Pair(84, 18), Pair(-148, 33),
        Pair(42, 60), Pair(77, 37), Pair(-37, 99), Pair(0, 0), Pair(-78, 95), Pair(-19, 43), Pair(-80, 42), Pair(-7, 10),
        Pair(13, 26), Pair(66, 29), Pair(-12, 52), Pair(-40, 74), Pair(21, 28), Pair(-30, 27), Pair(12, -1), Pair(47, 1),
        Pair(23, 19), Pair(39, 7), Pair(25, 22), Pair(-44, 47), Pair(-18, 21), Pair(-1, 4), Pair(-1, 2), Pair(18, -18),
        Pair(19, 9), Pair(-25, 24), Pair(16, -14), Pair(5, 12), Pair(-4, -18), Pair(-10, -3), Pair(2, -8), Pair(7, -21),
        Pair(5, -21), Pair(-16, -5), Pair(-12, -22), Pair(-29, -2), Pair(1, -42), Pair(-2, -15), Pair(4, -24), Pair(5, -24)
      }
    }},
    {{ // Bucket 28
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(24, 26), Pair(17, 17), Pair(-15, 20), Pair(-3, 50), Pair(22, -3), Pair(-20, 37), Pair(27, -7), Pair(-18, 22),
        Pair(6, 10), Pair(-8, 23), Pair(1, 22), Pair(21, 40), Pair(-1, -48), Pair(24, 5), Pair(13, 6), Pair(-2, 14),
        Pair(2, 11), Pair(6, 9), Pair(4, 1), Pair(2, 18), Pair(7, -15), Pair(4, 12), Pair(-14, 0), Pair(6, 9),
        Pair(-1, 12), Pair(6, 11), Pair(9, 6), Pair(12, 13), Pair(1, -8), Pair(13, 11), Pair(6, 10), Pair(1, 9),
        Pair(2, 13), Pair(6, 12), Pair(5, 12), Pair(0, 15), Pair(12, 7), Pair(0, 13), Pair(-4, 12), Pair(-5, 11),
        Pair(0, 16), Pair(4, 12), Pair(6, 11), Pair(-5, 23), Pair(5, 11), Pair(-8, 19), Pair(-9, 10), Pair(-4, 10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(51, 32), Pair(-79, 55), Pair(-10, 30), Pair(-9, 74), Pair(101, 81), Pair(11, 24), Pair(-118, 87), Pair(-95, 80),
        Pair(-12, 59), Pair(11, 57), Pair(-22, 56), Pair(46, 39), Pair(-22, 74), Pair(-4, 54), Pair(64, 66), Pair(-40, 39),
        Pair(-3, 98), Pair(23, 58), Pair(14, 55), Pair(51, 54), Pair(4, 25), Pair(-37, 66), Pair(4, 54), Pair(16, 49),
        Pair(-16, 75), Pair(8, 76), Pair(13, 69), Pair(6, 63), Pair(0, 0), Pair(25, 47), Pair(15, 55), Pair(25, 48),
        Pair(8, 56), Pair(25, 52), Pair(15, 47), Pair(12, 75), Pair(24, 99), Pair(22, 63), Pair(9, 35), Pair(5, 54),
        Pair(-2, 48), Pair(4, 66), Pair(-4, 62), Pair(2, 45), Pair(18, 52), Pair(-1, 41), Pair(12, 36), Pair(2, 69),
        Pair(-15, 30), Pair(7, 16), Pair(1, 47), Pair(-3, 55), Pair(10, 60), Pair(-2, 51), Pair(-3, 58), Pair(1, 17),
        Pair(25, 0), Pair(-4, 30), Pair(-12, 53), Pair(5, 44), Pair(2, 56), Pair(-11, 50), Pair(2, 41), Pair(2, 131)
      },
      { // Piece 2
        Pair(1, 4), Pair(-38, -4), Pair(41, 9), Pair(147, -22), Pair(-17, 51), Pair(71, -12), Pair(117, -4), Pair(52, -14),
        Pair(-4, -11), Pair(3, 46), Pair(-7, -18), Pair(3, 46), Pair(34, -2), Pair(42, 45), Pair(-26, -32), Pair(31, 33),
        Pair(19, 41), Pair(19, -4), Pair(10, 43), Pair(25, 2), Pair(12, -5), Pair(26, -13), Pair(53, 21), Pair(-3, 19),
        Pair(3, 3), Pair(15, 47), Pair(21, -14), Pair(12, 40), Pair(0, 0), Pair(60, 25), Pair(16, 13), Pair(24, 48),
        Pair(9, 33), Pair(6, 4), Pair(17, 48), Pair(-8, 4), Pair(27, 70), Pair(2, -16), Pair(26, 49), Pair(2, 14),
        Pair(1, 9), Pair(-8, 63), Pair(-5, 3), Pair(17, 44), Pair(3, 17), Pair(13, 44), Pair(-15, -9), Pair(4, 68),
        Pair(26, 4), Pair(-18, 9), Pair(20, 32), Pair(-1, 6), Pair(13, 39), Pair(3, 7), Pair(5, 41), Pair(-26, -16),
        Pair(-35, 4), Pair(26, 20), Pair(-11, 21), Pair(13, 38), Pair(7, -10), Pair(2, 45), Pair(-5, 10), Pair(22, 15)
      },
      { // Piece 3
        Pair(5, 61), Pair(40, 52), Pair(-14, 67), Pair(49, 48), Pair(-132, 84), Pair(-48, 84), Pair(41, 66), Pair(5, 57),
        Pair(-8, 71), Pair(-6, 71), Pair(3, 59), Pair(20, 53), Pair(-14, 54), Pair(-8, 71), Pair(-32, 66), Pair(-26, 93),
        Pair(18, 58), Pair(-4, 67), Pair(-19, 68), Pair(18, 59), Pair(-56, 24), Pair(38, 66), Pair(48, 54), Pair(15, 70),
        Pair(5, 47), Pair(-7, 58), Pair(-10, 46), Pair(9, 45), Pair(0, 0), Pair(21, 25), Pair(-7, 58), Pair(0, 57),
        Pair(-1, 51), Pair(-17, 62), Pair(-3, 58), Pair(6, 56), Pair(16, 45), Pair(22, 59), Pair(19, 63), Pair(8, 65),
        Pair(3, 50), Pair(0, 45), Pair(3, 54), Pair(8, 45), Pair(5, 32), Pair(7, 47), Pair(-3, 55), Pair(4, 60),
        Pair(-1, 48), Pair(-15, 63), Pair(-3, 51), Pair(-3, 55), Pair(-4, 36), Pair(-5, 41), Pair(-12, 64), Pair(15, 34),
        Pair(-1, 49), Pair(-1, 50), Pair(-5, 53), Pair(3, 43), Pair(7, 34), Pair(-4, 55), Pair(17, 44), Pair(10, 51)
      },
      { // Piece 4
        Pair(1, 97), Pair(-30, 98), Pair(49, 76), Pair(-5, 104), Pair(-16, 73), Pair(60, 53), Pair(-30, 111), Pair(60, 4),
        Pair(16, 59), Pair(27, 72), Pair(-9, 65), Pair(70, 29), Pair(33, 48), Pair(54, 50), Pair(31, 83), Pair(-21, 184),
        Pair(24, 53), Pair(24, 58), Pair(-1, 102), Pair(9, 82), Pair(19, -15), Pair(42, 110), Pair(12, 150), Pair(31, 146),
        Pair(3, 77), Pair(16, 56), Pair(4, 59), Pair(24, 52), Pair(0, 0), Pair(17, 57), Pair(0, 129), Pair(28, 71),
        Pair(6, 99), Pair(12, 67), Pair(16, 52), Pair(-3, 88), Pair(20, 79), Pair(16, 77), Pair(28, 80), Pair(17, 126),
        Pair(16, 73), Pair(14, 72), Pair(5, 87), Pair(22, 71), Pair(16, 67), Pair(22, 69), Pair(16, 67), Pair(6, 122),
        Pair(-7, 98), Pair(16, 36), Pair(22, 53), Pair(17, 78), Pair(21, 47), Pair(22, 55), Pair(22, 71), Pair(24, 12),
        Pair(16, 43), Pair(20, 65), Pair(21, 58), Pair(15, 75), Pair(16, 53), Pair(25, 74), Pair(7, 96), Pair(60, -41)
      },
      { // Piece 5
        Pair(-83, 42), Pair(-91, -19), Pair(107, 112), Pair(-69, 52), Pair(-121, 84), Pair(12, 115), Pair(59, 22), Pair(-80, -23),
        Pair(-61, -34), Pair(154, -9), Pair(27, 19), Pair(94, 92), Pair(129, 81), Pair(-13, 108), Pair(80, -6), Pair(87, -49),
        Pair(85, 5), Pair(-23, 38), Pair(-34, 43), Pair(-68, 55), Pair(-46, 37), Pair(13, 30), Pair(57, 19), Pair(85, 35),
        Pair(9, 7), Pair(46, -6), Pair(10, 27), Pair(-83, 59), Pair(0, 0), Pair(25, 38), Pair(33, 9), Pair(40, 11),
        Pair(-121, 6), Pair(-43, 16), Pair(-6, 18), Pair(2, 22), Pair(13, 36), Pair(-22, 17), Pair(28, 0), Pair(30, -17),
        Pair(-138, 2), Pair(-21, 2), Pair(-26, 2), Pair(-38, 17), Pair(2, 17), Pair(-24, 8), Pair(21, -21), Pair(3, -25),
        Pair(5, -25), Pair(-20, -19), Pair(-19, -11), Pair(-20, -9), Pair(10, -16), Pair(-7, -17), Pair(8, -23), Pair(16, -26),
        Pair(-9, -36), Pair(-22, -10), Pair(-18, -33), Pair(-37, -26), Pair(0, -43), Pair(5, -50), Pair(8, -34), Pair(12, -46)
      }
    }},
    {{ // Bucket 29
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(3, 18), Pair(-17, 14), Pair(2, 21), Pair(21, 27), Pair(-19, 43), Pair(-15, -3), Pair(-19, 27), Pair(-6, 15),
        Pair(8, 13), Pair(-9, 22), Pair(8, 22), Pair(13, 15), Pair(25, 27), Pair(-12, -20), Pair(-7, -2), Pair(-13, 11),
        Pair(7, 11), Pair(11, 9), Pair(16, 10), Pair(1, 3), Pair(5, 13), Pair(-4, -2), Pair(-23, 2), Pair(-25, -1),
        Pair(3, 8), Pair(0, 17), Pair(10, 10), Pair(4, 15), Pair(14, 7), Pair(-4, -5), Pair(4, 3), Pair(3, 3),
        Pair(3, 10), Pair(9, 10), Pair(4, 9), Pair(2, 13), Pair(3, 15), Pair(11, 4), Pair(-10, 10), Pair(-3, 11),
        Pair(0, 16), Pair(3, 10), Pair(0, 15), Pair(3, 14), Pair(2, 23), Pair(4, 15), Pair(-11, 15), Pair(-6, 8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(61, -45), Pair(137, -3), Pair(-109, 65), Pair(-38, 71), Pair(105, 41), Pair(83, 46), Pair(-44, 58), Pair(10, 48),
        Pair(7, 53), Pair(40, 51), Pair(33, 43), Pair(28, 53), Pair(67, 10), Pair(22, 30), Pair(25, 38), Pair(-53, 106),
        Pair(0, 70), Pair(31, 43), Pair(54, 37), Pair(17, 37), Pair(57, 49), Pair(-35, 28), Pair(-7, 42), Pair(-17, 34),
        Pair(-5, 53), Pair(18, 36), Pair(33, 48), Pair(22, 58), Pair(28, 44), Pair(0, 0), Pair(5, 44), Pair(6, 60),
        Pair(-6, 48), Pair(22, 56), Pair(15, 35), Pair(15, 33), Pair(43, 59), Pair(37, 68), Pair(32, 67), Pair(-9, 11),
        Pair(-3, 28), Pair(16, 34), Pair(17, 35), Pair(11, 33), Pair(9, 33), Pair(10, 53), Pair(9, 16), Pair(13, 57),
        Pair(-6, 42), Pair(-10, 13), Pair(2, 22), Pair(0, 43), Pair(3, 47), Pair(23, 20), Pair(9, 17), Pair(-5, 54),
        Pair(-87, 0), Pair(9, 29), Pair(6, 13), Pair(4, 38), Pair(8, 33), Pair(-13, 49), Pair(4, 52), Pair(-53, -54)
      },
      { // Piece 2
        Pair(-30, -31), Pair(7, 11), Pair(61, -49), Pair(94, 6), Pair(50, -15), Pair(-104, 52), Pair(131, -21), Pair(104, 35),
        Pair(22, 8), Pair(-1, -8), Pair(45, 1), Pair(87, -40), Pair(100, 16), Pair(35, -19), Pair(79, 19), Pair(-67, 28),
        Pair(-3, -8), Pair(28, 40), Pair(17, -9), Pair(38, 24), Pair(76, 11), Pair(39, -2), Pair(-69, 18), Pair(26, 39),
        Pair(14, 37), Pair(42, -15), Pair(52, 23), Pair(38, -12), Pair(-4, 47), Pair(0, 0), Pair(24, 37), Pair(-1, 16),
        Pair(22, -10), Pair(14, 40), Pair(11, 8), Pair(38, 34), Pair(2, 14), Pair(25, 64), Pair(-5, -6), Pair(23, 37),
        Pair(12, 51), Pair(2, -2), Pair(19, 42), Pair(-6, -2), Pair(20, 40), Pair(12, -2), Pair(11, 21), Pair(-25, -14),
        Pair(13, 7), Pair(14, 37), Pair(-5, -1), Pair(19, 30), Pair(5, 0), Pair(27, 25), Pair(-7, 5), Pair(-1, 64),
        Pair(9, 49), Pair(3, -8), Pair(16, 25), Pair(-2, 3), Pair(30, 32), Pair(5, -10), Pair(16, 39), Pair(-7, -6)
      },
      { // Piece 3
        Pair(47, 50), Pair(7, 47), Pair(4, 68), Pair(65, 45), Pair(13, 72), Pair(22, 44), Pair(120, 28), Pair(70, 62),
        Pair(6, 70), Pair(48, 52), Pair(53, 35), Pair(42, 56), Pair(23, 57), Pair(-86, 75), Pair(-1, 64), Pair(13, 63),
        Pair(33, 46), Pair(38, 44), Pair(28, 53), Pair(7, 53), Pair(72, 45), Pair(60, -15), Pair(30, 46), Pair(36, 53),
        Pair(6, 59), Pair(21, 58), Pair(-2, 53), Pair(6, 51), Pair(10, 45), Pair(0, 0), Pair(12, 27), Pair(17, 39),
        Pair(34, 53), Pair(17, 56), Pair(35, 24), Pair(28, 44), Pair(25, 48), Pair(38, 18), Pair(47, 38), Pair(47, 33),
        Pair(11, 51), Pair(25, 44), Pair(30, 46), Pair(7, 52), Pair(35, 35), Pair(26, 15), Pair(17, 40), Pair(26, 35),
        Pair(-31, 66), Pair(21, 37), Pair(5, 51), Pair(8, 52), Pair(11, 56), Pair(15, 24), Pair(15, 60), Pair(61, 35),
        Pair(19, 40), Pair(21, 32), Pair(22, 38), Pair(20, 37), Pair(21, 39), Pair(27, 10), Pair(39, 44), Pair(22, 44)
      },
      { // Piece 4
        Pair(122, -16), Pair(46, 104), Pair(84, 34), Pair(52, 105), Pair(76, 95), Pair(64, 10), Pair(112, 27), Pair(120, 6),
        Pair(38, 48), Pair(8, 104), Pair(34, 52), Pair(124, -41), Pair(11, 72), Pair(20, 9), Pair(6, 120), Pair(30, 59),
        Pair(6, 85), Pair(4, 143), Pair(23, 54), Pair(59, 115), Pair(-3, 94), Pair(138, -98), Pair(-3, 89), Pair(36, 43),
        Pair(7, 88), Pair(-14, 79), Pair(57, 16), Pair(38, 37), Pair(24, 78), Pair(0, 0), Pair(35, 49), Pair(21, 72),
        Pair(36, 57), Pair(44, 45), Pair(0, 107), Pair(31, 62), Pair(31, 44), Pair(19, 58), Pair(25, 27), Pair(51, 11),
        Pair(30, 80), Pair(25, 58), Pair(27, 51), Pair(15, 40), Pair(37, 51), Pair(27, 28), Pair(7, 84), Pair(45, -13),
        Pair(47, 2), Pair(26, 71), Pair(16, 75), Pair(28, 57), Pair(26, 59), Pair(19, 47), Pair(31, 50), Pair(24, 58),
        Pair(40, 23), Pair(9, 94), Pair(28, 87), Pair(19, 70), Pair(23, 53), Pair(52, -2), Pair(38, 29), Pair(35, 11)
      },
      { // Piece 5
        Pair(-4, 0), Pair(-259, 108), Pair(-64, 47), Pair(8, 67), Pair(-123, 87), Pair(38, 37), Pair(-25, 73), Pair(76, 141),
        Pair(24, 17), Pair(-222, 58), Pair(164, 4), Pair(39, 26), Pair(-59, 81), Pair(130, 64), Pair(-160, 118), Pair(153, 29),
        Pair(144, -32), Pair(21, 5), Pair(12, 17), Pair(-124, 59), Pair(-28, 30), Pair(-37, 32), Pair(104, 8), Pair(15, 42),
        Pair(-164, 23), Pair(-2, 1), Pair(-29, 17), Pair(70, 17), Pair(102, 18), Pair(0, 0), Pair(6, 26), Pair(62, 22),
        Pair(-12, -4), Pair(-63, 11), Pair(-15, 9), Pair(-70, 25), Pair(20, 9), Pair(-17, 23), Pair(41, 8), Pair(46, 5),
        Pair(-70, -1), Pair(-81, -1), Pair(-44, 1), Pair(-44, 0), Pair(-13, 12), Pair(-35, 16), Pair(-6, 3), Pair(18, -12),
        Pair(-72, 13), Pair(-27, -18), Pair(-52, 0), Pair(-21, -17), Pair(-6, -21), Pair(-28, -9), Pair(17, -35), Pair(6, -16),
        Pair(-30, -41), Pair(-27, -24), Pair(-30, -24), Pair(-66, 1), Pair(-8, -53), Pair(4, -36), Pair(12, -49), Pair(-2, -25)
      }
    }},
    {{ // Bucket 30
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-23, 21), Pair(-23, 32), Pair(-14, 20), Pair(33, 12), Pair(24, 22), Pair(-21, 29), Pair(9, -15), Pair(-13, 38),
        Pair(-2, 15), Pair(-15, 14), Pair(-10, 23), Pair(19, 14), Pair(-7, 18), Pair(-7, 11), Pair(31, -47), Pair(-17, -5),
        Pair(-4, 13), Pair(3, 15), Pair(2, 15), Pair(7, 14), Pair(-15, 1), Pair(-22, 3), Pair(15, 5), Pair(-17, -4),
        Pair(-5, 14), Pair(-1, 15), Pair(-1, 11), Pair(-1, 14), Pair(2, 10), Pair(7, 0), Pair(14, -28), Pair(4, 0),
        Pair(-5, 16), Pair(2, 13), Pair(2, 13), Pair(0, 12), Pair(5, 15), Pair(4, 8), Pair(10, -8), Pair(-1, 18),
        Pair(1, 16), Pair(1, 17), Pair(2, 15), Pair(-2, 10), Pair(2, 16), Pair(-1, 15), Pair(11, -5), Pair(-9, 22),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(138, -17), Pair(221, -41), Pair(-19, 45), Pair(42, 29), Pair(142, 24), Pair(-157, 91), Pair(135, 7), Pair(10, -65),
        Pair(46, 0), Pair(-71, 60), Pair(3, 24), Pair(65, 37), Pair(71, 11), Pair(56, 12), Pair(76, 24), Pair(80, 20),
        Pair(-36, 55), Pair(2, 47), Pair(25, 52), Pair(59, 29), Pair(27, 33), Pair(12, 39), Pair(59, 5), Pair(-19, -21),
        Pair(19, 24), Pair(22, 26), Pair(25, 34), Pair(31, 49), Pair(32, 39), Pair(38, 38), Pair(0, 0), Pair(28, 32),
        Pair(5, 38), Pair(12, 32), Pair(9, 36), Pair(18, 40), Pair(45, 39), Pair(18, 46), Pair(66, 55), Pair(21, 48),
        Pair(-11, 35), Pair(7, 37), Pair(13, 33), Pair(10, 41), Pair(17, 38), Pair(1, 32), Pair(18, 42), Pair(-22, 19),
        Pair(9, 37), Pair(7, 42), Pair(-1, 46), Pair(5, 36), Pair(13, 34), Pair(-3, 31), Pair(14, 40), Pair(-1, 48),
        Pair(81, 12), Pair(-8, 27), Pair(-7, 31), Pair(20, 20), Pair(28, 34), Pair(0, 34), Pair(-6, 31), Pair(-67, 10)
      },
      { // Piece 2
        Pair(-18, 9), Pair(17, -32), Pair(89, 23), Pair(90, -25), Pair(204, -21), Pair(63, -16), Pair(-56, 45), Pair(-50, 35),
        Pair(4, -15), Pair(34, 20), Pair(-15, -12), Pair(101, -23), Pair(129, -32), Pair(105, -10), Pair(52, -27), Pair(76, 20),
        Pair(12, -2), Pair(22, -15), Pair(32, 13), Pair(51, -11), Pair(5, 28), Pair(88, 4), Pair(31, -3), Pair(0, -9),
        Pair(0, -9), Pair(16, 20), Pair(30, 3), Pair(41, 34), Pair(51, -7), Pair(54, 31), Pair(0, 0), Pair(20, 20),
        Pair(-18, 32), Pair(41, -1), Pair(19, 29), Pair(37, 0), Pair(33, 38), Pair(6, 14), Pair(28, 39), Pair(-39, -28),
        Pair(18, 5), Pair(19, 20), Pair(10, 13), Pair(17, 36), Pair(7, 8), Pair(9, 21), Pair(9, -1), Pair(31, 6),
        Pair(5, 14), Pair(15, 10), Pair(31, 26), Pair(4, 7), Pair(15, 27), Pair(14, -9), Pair(28, 19), Pair(-16, 18),
        Pair(41, 6), Pair(-5, 34), Pair(5, 4), Pair(-10, 33), Pair(-13, 12), Pair(19, 22), Pair(1, -39), Pair(10, 15)
      },
      { // Piece 3
        Pair(-20, 68), Pair(-8, 71), Pair(95, 20), Pair(-32, 69), Pair(127, 40), Pair(-15, 90), Pair(73, 3), Pair(-86, 87),
        Pair(-7, 67), Pair(25, 51), Pair(45, 40), Pair(21, 45), Pair(87, 15), Pair(7, 52), Pair(26, 43), Pair(-90, 85),
        Pair(7, 63), Pair(13, 50), Pair(13, 53), Pair(38, 40), Pair(50, 42), Pair(23, 59), Pair(18, 1), Pair(20, 53),
        Pair(25, 42), Pair(26, 51), Pair(26, 35), Pair(17, 53), Pair(16, 39), Pair(13, 46), Pair(0, 0), Pair(-34, 53),
        Pair(11, 58), Pair(-1, 50), Pair(0, 53), Pair(8, 47), Pair(29, 47), Pair(9, 51), Pair(43, 20), Pair(1, 67),
        Pair(12, 52), Pair(-23, 53), Pair(-12, 52), Pair(8, 44), Pair(20, 47), Pair(-5, 58), Pair(4, 17), Pair(7, 35),
        Pair(-22, 50), Pair(15, 58), Pair(7, 48), Pair(1, 51), Pair(4, 54), Pair(28, 23), Pair(33, -12), Pair(-9, 55),
        Pair(5, 42), Pair(5, 42), Pair(8, 41), Pair(12, 39), Pair(11, 38), Pair(14, 42), Pair(23, 12), Pair(-4, 40)
      },
      { // Piece 4
        Pair(-12, 91), Pair(-55, 138), Pair(-18, 102), Pair(21, 80), Pair(74, 47), Pair(30, -2), Pair(44, -54), Pair(52, -40),
        Pair(16, 14), Pair(8, 112), Pair(22, 55), Pair(11, 105), Pair(31, 71), Pair(82, -20), Pair(14, -40), Pair(7, 3),
        Pair(-31, 108), Pair(39, 42), Pair(26, 40), Pair(34, 74), Pair(10, 86), Pair(44, 52), Pair(21, -32), Pair(43, 68),
        Pair(14, 63), Pair(-19, 94), Pair(12, 81), Pair(28, 50), Pair(71, 27), Pair(31, 5), Pair(0, 0), Pair(14, -7),
        Pair(19, 17), Pair(-14, 74), Pair(-1, 67), Pair(23, 68), Pair(0, 78), Pair(8, 82), Pair(7, 13), Pair(10, 7),
        Pair(55, -23), Pair(4, 47), Pair(17, 62), Pair(12, 44), Pair(26, 23), Pair(3, 65), Pair(3, 36), Pair(10, 90),
        Pair(8, 51), Pair(18, 66), Pair(9, 64), Pair(14, 34), Pair(18, 29), Pair(6, 44), Pair(-3, 57), Pair(40, 50),
        Pair(15, 34), Pair(-38, 128), Pair(2, 62), Pair(-5, 72), Pair(22, 10), Pair(-15, 119), Pair(7, -19), Pair(15, 105)
      },
      { // Piece 5
        Pair(92, -50), Pair(-135, 40), Pair(8, 31), Pair(96, 42), Pair(-71, 49), Pair(-114, 122), Pair(19, 86), Pair(48, 12),
        Pair(-113, -22), Pair(-141, 20), Pair(-176, 35), Pair(-28, -4), Pair(113, 28), Pair(99, 65), Pair(127, 88), Pair(-16, 140),
        Pair(-86, -11), Pair(-68, 14), Pair(-14, 19), Pair(118, 10), Pair(42, 38), Pair(107, 16), Pair(91, 32), Pair(143, 10),
        Pair(-219, 35), Pair(-25, 25), Pair(7, 7), Pair(-54, 29), Pair(39, 16), Pair(12, 31), Pair(0, 0), Pair(-9, 49),
        Pair(-95, 13), Pair(-80, 25), Pair(-68, 10), Pair(-78, 24), Pair(-45, 28), Pair(-2, 10), Pair(51, 13), Pair(19, 12),
        Pair(-87, 21), Pair(-60, -9), Pair(-23, 0), Pair(-48, 12), Pair(23, -4), Pair(-7, 11), Pair(54, -8), Pair(48, 0),
        Pair(-30, -23), Pair(-40, -9), Pair(-63, 12), Pair(-39, -1), Pair(-9, -6), Pair(5, -18), Pair(20, -13), Pair(2, -15),
        Pair(-34, -36), Pair(-22, -2), Pair(-23, -23), Pair(-34, 7), Pair(-3, -26), Pair(3, -27), Pair(3, -14), Pair(0, -35)
      }
    }},
    {{ // Bucket 31
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(26, 6), Pair(14, 3), Pair(15, 15), Pair(47, 4), Pair(-8, -1), Pair(14, 3), Pair(1, 29), Pair(40, -11),
        Pair(-4, 15), Pair(-17, 25), Pair(20, 14), Pair(1, 22), Pair(3, 12), Pair(-1, 0), Pair(-16, 3), Pair(29, -42),
        Pair(-3, 15), Pair(0, 13), Pair(6, 12), Pair(3, 7), Pair(4, 8), Pair(-26, 0), Pair(-17, -6), Pair(2, -3),
        Pair(-3, 15), Pair(4, 17), Pair(-1, 15), Pair(4, 10), Pair(3, 8), Pair(2, 4), Pair(3, -6), Pair(13, -8),
        Pair(-6, 16), Pair(4, 13), Pair(1, 11), Pair(0, 9), Pair(3, 4), Pair(3, 3), Pair(3, 11), Pair(22, 6),
        Pair(-6, 18), Pair(0, 14), Pair(-3, 10), Pair(-10, 17), Pair(-3, 9), Pair(1, 9), Pair(-2, 18), Pair(11, 7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(39, 74), Pair(214, 4), Pair(193, 27), Pair(54, 3), Pair(152, -6), Pair(100, -14), Pair(58, -38), Pair(-155, 37),
        Pair(0, 9), Pair(-56, 54), Pair(48, 6), Pair(112, 7), Pair(-26, 26), Pair(-33, 51), Pair(-16, 4), Pair(-34, 28),
        Pair(-20, 29), Pair(7, 31), Pair(5, 32), Pair(36, 20), Pair(32, 21), Pair(47, 30), Pair(0, 5), Pair(7, 10),
        Pair(-8, 32), Pair(7, 19), Pair(9, 7), Pair(35, 19), Pair(35, 28), Pair(13, 32), Pair(31, 34), Pair(0, 0),
        Pair(6, 15), Pair(5, 39), Pair(20, 18), Pair(10, 30), Pair(23, 21), Pair(30, 18), Pair(22, 24), Pair(31, 30),
        Pair(17, 6), Pair(13, 13), Pair(9, 14), Pair(-2, 29), Pair(19, 19), Pair(12, 18), Pair(18, 6), Pair(-14, 68),
        Pair(-32, 13), Pair(-7, -7), Pair(4, 12), Pair(13, 16), Pair(15, 10), Pair(3, 35), Pair(-8, 28), Pair(0, 22),
        Pair(-62, -7), Pair(-6, 39), Pair(4, 11), Pair(-4, 19), Pair(4, 15), Pair(-23, 19), Pair(4, -9), Pair(29, -2)
      },
      { // Piece 2
        Pair(113, -57), Pair(65, -3), Pair(177, -73), Pair(61, 4), Pair(82, -46), Pair(-51, 15), Pair(90, -12), Pair(-12, 6),
        Pair(77, -11), Pair(6, -23), Pair(9, 8), Pair(78, -40), Pair(66, -18), Pair(133, -32), Pair(30, 23), Pair(68, 2),
        Pair(36, -18), Pair(-9, 15), Pair(28, -20), Pair(13, 15), Pair(73, -40), Pair(41, 4), Pair(2, 2), Pair(17, 0),
        Pair(18, 29), Pair(23, -15), Pair(60, 0), Pair(39, -26), Pair(25, 28), Pair(24, -7), Pair(20, 31), Pair(0, 0),
        Pair(52, -25), Pair(13, 13), Pair(12, -8), Pair(12, 20), Pair(32, -9), Pair(24, 24), Pair(18, -5), Pair(37, 38),
        Pair(-2, 31), Pair(22, -15), Pair(18, 18), Pair(22, -7), Pair(23, 16), Pair(14, -12), Pair(21, 12), Pair(23, -11),
        Pair(19, -24), Pair(14, 21), Pair(32, -16), Pair(14, 22), Pair(17, -4), Pair(10, 21), Pair(9, -10), Pair(33, 1),
        Pair(41, 17), Pair(32, -5), Pair(10, 27), Pair(26, -12), Pair(-24, 14), Pair(6, -18), Pair(39, 8), Pair(73, -55)
      },
      { // Piece 3
        Pair(24, 30), Pair(27, 30), Pair(108, 14), Pair(68, 10), Pair(72, 12), Pair(131, 5), Pair(6, 31), Pair(76, -37),
        Pair(51, 20), Pair(28, 25), Pair(31, 20), Pair(59, 22), Pair(76, -1), Pair(32, 30), Pair(-34, 43), Pair(-36, 20),
        Pair(10, 41), Pair(35, 22), Pair(14, 35), Pair(23, 25), Pair(14, 23), Pair(55, 22), Pair(15, 31), Pair(67, -36),
        Pair(14, 25), Pair(23, 27), Pair(9, 26), Pair(56, 9), Pair(10, 22), Pair(31, 23), Pair(44, 21), Pair(0, 0),
        Pair(42, 15), Pair(-10, 41), Pair(21, 22), Pair(4, 30), Pair(14, 28), Pair(12, 34), Pair(10, 28), Pair(-39, 10),
        Pair(12, 13), Pair(-13, 28), Pair(4, 16), Pair(-24, 29), Pair(8, 16), Pair(2, 24), Pair(0, 31), Pair(-45, 8),
        Pair(-8, 32), Pair(-13, 40), Pair(9, 13), Pair(7, 22), Pair(3, 33), Pair(2, 21), Pair(-39, 39), Pair(-81, 28),
        Pair(8, 13), Pair(16, 12), Pair(7, 19), Pair(15, 14), Pair(12, 19), Pair(11, 13), Pair(1, 19), Pair(-19, -16)
      },
      { // Piece 4
        Pair(49, 22), Pair(-24, 48), Pair(63, -20), Pair(36, 10), Pair(119, -10), Pair(-20, 68), Pair(-64, 53), Pair(129, -83),
        Pair(48, -14), Pair(-19, 51), Pair(2, 52), Pair(-32, 77), Pair(-13, 42), Pair(49, 34), Pair(101, -110), Pair(25, -5),
        Pair(11, 31), Pair(34, 14), Pair(-12, 71), Pair(18, 22), Pair(58, 11), Pair(46, 16), Pair(27, 57), Pair(4, 1),
        Pair(11, 10), Pair(39, -32), Pair(51, -2), Pair(17, 48), Pair(-12, 59), Pair(34, -5), Pair(41, -14), Pair(0, 0),
        Pair(17, 18), Pair(-5, 76), Pair(-2, 43), Pair(-6, 31), Pair(21, 15), Pair(16, 31), Pair(25, 9), Pair(7, -15),
        Pair(43, -16), Pair(28, 16), Pair(11, 48), Pair(28, 21), Pair(17, 0), Pair(13, 22), Pair(24, 1), Pair(-14, 20),
        Pair(24, 35), Pair(14, 29), Pair(16, 30), Pair(20, 21), Pair(10, 30), Pair(7, 37), Pair(32, -27), Pair(-8, 14),
        Pair(40, 11), Pair(13, 57), Pair(-4, 63), Pair(9, 31), Pair(13, 9), Pair(51, -26), Pair(40, -51), Pair(3, 55)
      },
      { // Piece 5
        Pair(-3, -24), Pair(83, 54), Pair(-38, -9), Pair(-3, 34), Pair(131, -12), Pair(-55, 82), Pair(-31, 99), Pair(9, 43),
        Pair(150, -53), Pair(11, -20), Pair(-79, 21), Pair(-37, 7), Pair(-83, 23), Pair(-11, 50), Pair(-84, 105), Pair(-145, 81),
        Pair(-17, -11), Pair(-1, 16), Pair(20, -2), Pair(-7, 24), Pair(109, 17), Pair(12, 47), Pair(10, 27), Pair(-50, 15),
        Pair(-29, 21), Pair(-96, 10), Pair(-135, 35), Pair(-72, 32), Pair(-25, 32), Pair(24, 26), Pair(-5, 23), Pair(0, 0),
        Pair(-94, 9), Pair(-137, 30), Pair(-88, 23), Pair(-76, 36), Pair(-59, 22), Pair(5, 19), Pair(-11, 4), Pair(25, -20),
        Pair(-146, 42), Pair(-57, 15), Pair(-73, 17), Pair(-51, 17), Pair(-11, 9), Pair(18, 3), Pair(21, 1), Pair(12, -2),
        Pair(-81, 8), Pair(-42, -6), Pair(-53, 14), Pair(-33, 2), Pair(-18, -1), Pair(-13, 4), Pair(15, -5), Pair(6, -8),
        Pair(-63, 11), Pair(-33, -6), Pair(-29, -6), Pair(-61, 4), Pair(-14, -15), Pair(-3, -8), Pair(8, -14), Pair(-2, -1)
      }
    }},
    {{ // Bucket 32
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-26, 17), Pair(1, 42), Pair(9, 16), Pair(6, 14), Pair(3, 1), Pair(-14, 16), Pair(-9, 21), Pair(4, 13),
        Pair(-18, 7), Pair(-3, 36), Pair(-1, 22), Pair(1, 14), Pair(-2, 13), Pair(2, 7), Pair(-4, 3), Pair(-7, 19),
        Pair(-9, -9), Pair(0, 9), Pair(-1, 12), Pair(-5, 13), Pair(-1, 11), Pair(5, 11), Pair(-5, 16), Pair(-4, 16),
        Pair(-1, 16), Pair(-9, -1), Pair(-1, 9), Pair(-1, 12), Pair(0, 11), Pair(0, 13), Pair(-2, 18), Pair(-6, 15),
        Pair(-2, 8), Pair(-4, 4), Pair(-1, 11), Pair(-3, 16), Pair(-3, 12), Pair(0, 13), Pair(-4, 18), Pair(-2, 21),
        Pair(1, 9), Pair(-3, 13), Pair(-4, 11), Pair(-1, 12), Pair(-8, 14), Pair(-5, 21), Pair(-7, 19), Pair(-3, 19),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-19, 29), Pair(11, 18), Pair(2, 85), Pair(-75, 47), Pair(-14, 61), Pair(-92, 36), Pair(-39, 74), Pair(-6, 119),
        Pair(-19, 54), Pair(-3, 55), Pair(-8, 53), Pair(8, 57), Pair(-8, 57), Pair(-22, 72), Pair(-56, 76), Pair(-24, 51),
        Pair(-2, 44), Pair(-18, 54), Pair(-2, 72), Pair(-12, 62), Pair(-7, 60), Pair(-50, 75), Pair(-6, 69), Pair(8, 39),
        Pair(-14, 42), Pair(-2, 57), Pair(-5, 64), Pair(-6, 70), Pair(-9, 76), Pair(-3, 58), Pair(-8, 65), Pair(-25, 72),
        Pair(0, 0), Pair(-9, 74), Pair(-2, 71), Pair(-5, 69), Pair(-17, 77), Pair(0, 70), Pair(-17, 74), Pair(-6, 45),
        Pair(-4, 76), Pair(-1, 67), Pair(-6, 49), Pair(0, 67), Pair(0, 72), Pair(-4, 59), Pair(-6, 62), Pair(-1, 54),
        Pair(-15, 44), Pair(-1, 40), Pair(-9, 70), Pair(-9, 68), Pair(-8, 58), Pair(-10, 68), Pair(-2, 51), Pair(-12, 67),
        Pair(62, 63), Pair(-13, 37), Pair(-4, 68), Pair(-13, 80), Pair(-12, 77), Pair(-9, 69), Pair(-3, 50), Pair(-8, 68)
      },
      { // Piece 2
        Pair(-5, 53), Pair(67, 53), Pair(27, 13), Pair(-64, 62), Pair(39, 14), Pair(22, 48), Pair(12, 24), Pair(-7, 44),
        Pair(0, 52), Pair(14, 41), Pair(-9, 58), Pair(54, 19), Pair(35, 33), Pair(18, 26), Pair(-25, 61), Pair(-26, 58),
        Pair(5, 46), Pair(6, 56), Pair(31, 25), Pair(1, 56), Pair(7, 33), Pair(-2, 41), Pair(12, 19), Pair(-22, 68),
        Pair(-3, 41), Pair(14, 54), Pair(-5, 57), Pair(4, 39), Pair(-6, 54), Pair(11, 27), Pair(0, 50), Pair(9, 32),
        Pair(0, 0), Pair(3, 56), Pair(10, 46), Pair(6, 49), Pair(-1, 51), Pair(-5, 55), Pair(4, 39), Pair(-2, 58),
        Pair(-2, 75), Pair(12, 34), Pair(1, 60), Pair(0, 50), Pair(-3, 66), Pair(1, 59), Pair(0, 57), Pair(6, 39),
        Pair(12, 0), Pair(-6, 50), Pair(-1, 49), Pair(-5, 62), Pair(3, 56), Pair(-7, 61), Pair(0, 53), Pair(3, 67),
        Pair(-8, 39), Pair(-10, 20), Pair(-7, 47), Pair(10, 39), Pair(1, 53), Pair(0, 50), Pair(-9, 56), Pair(-16, 78)
      },
      { // Piece 3
        Pair(-35, 69), Pair(-15, 102), Pair(-30, 97), Pair(-30, 99), Pair(-19, 110), Pair(-40, 92), Pair(-124, 129), Pair(-40, 114),
        Pair(-60, 80), Pair(-15, 103), Pair(-14, 93), Pair(-22, 104), Pair(-46, 108), Pair(-29, 99), Pair(-54, 119), Pair(-31, 105),
        Pair(-54, 97), Pair(-12, 95), Pair(-12, 102), Pair(-11, 96), Pair(-25, 102), Pair(-16, 96), Pair(-34, 102), Pair(-16, 103),
        Pair(-51, 70), Pair(-17, 113), Pair(-8, 107), Pair(-24, 100), Pair(-12, 104), Pair(-22, 94), Pair(-27, 109), Pair(-31, 98),
        Pair(0, 0), Pair(-10, 107), Pair(-3, 100), Pair(-4, 91), Pair(-23, 112), Pair(-23, 92), Pair(-5, 100), Pair(-20, 113),
        Pair(-35, 76), Pair(-15, 96), Pair(-6, 93), Pair(-9, 92), Pair(-16, 94), Pair(-15, 93), Pair(-22, 110), Pair(1, 83),
        Pair(-61, 70), Pair(-13, 98), Pair(-25, 107), Pair(-11, 93), Pair(-15, 94), Pair(-19, 85), Pair(-20, 84), Pair(-12, 84),
        Pair(-40, 70), Pair(-21, 100), Pair(-17, 99), Pair(-16, 98), Pair(-16, 94), Pair(-18, 95), Pair(-17, 95), Pair(-10, 85)
      },
      { // Piece 4
        Pair(6, 144), Pair(14, 139), Pair(45, 142), Pair(2, 158), Pair(-8, 159), Pair(39, 158), Pair(-38, 217), Pair(7, 142),
        Pair(-29, 163), Pair(1, 165), Pair(7, 160), Pair(26, 147), Pair(48, 118), Pair(23, 119), Pair(20, 142), Pair(-6, 162),
        Pair(-3, 145), Pair(9, 161), Pair(17, 143), Pair(4, 153), Pair(-13, 185), Pair(19, 129), Pair(14, 154), Pair(-4, 163),
        Pair(2, 132), Pair(15, 182), Pair(7, 165), Pair(8, 162), Pair(24, 146), Pair(17, 134), Pair(5, 156), Pair(13, 170),
        Pair(0, 0), Pair(26, 170), Pair(21, 160), Pair(12, 172), Pair(5, 177), Pair(17, 152), Pair(8, 162), Pair(19, 144),
        Pair(9, 125), Pair(18, 162), Pair(21, 160), Pair(16, 170), Pair(9, 182), Pair(15, 171), Pair(21, 148), Pair(22, 139),
        Pair(-1, 144), Pair(16, 151), Pair(16, 160), Pair(16, 171), Pair(18, 166), Pair(20, 177), Pair(12, 166), Pair(28, 89),
        Pair(8, 110), Pair(8, 146), Pair(17, 151), Pair(16, 167), Pair(9, 179), Pair(15, 172), Pair(-2, 193), Pair(16, 159)
      },
      { // Piece 5
        Pair(47, 127), Pair(-118, 204), Pair(-14, 21), Pair(-32, 6), Pair(-110, -6), Pair(20, 11), Pair(-129, -4), Pair(-111, 22),
        Pair(-37, 66), Pair(81, 71), Pair(15, 81), Pair(17, 44), Pair(24, -2), Pair(157, -8), Pair(26, 10), Pair(-9, -50),
        Pair(-108, 58), Pair(-137, 112), Pair(116, 61), Pair(-264, 101), Pair(13, 33), Pair(-147, 42), Pair(20, -3), Pair(-94, 32),
        Pair(30, 15), Pair(-2, 38), Pair(25, 68), Pair(2, 39), Pair(-47, 39), Pair(-39, 15), Pair(8, 20), Pair(-76, 11),
        Pair(0, 0), Pair(4, 46), Pair(0, 36), Pair(-14, 40), Pair(-51, 35), Pair(0, 16), Pair(-48, 14), Pair(-14, -4),
        Pair(33, -16), Pair(5, 19), Pair(35, 16), Pair(14, 19), Pair(0, 14), Pair(-13, 9), Pair(-12, 1), Pair(-37, -5),
        Pair(57, -40), Pair(87, 3), Pair(18, 11), Pair(11, 7), Pair(-6, 14), Pair(-17, 12), Pair(-8, -1), Pair(-9, -12),
        Pair(45, -48), Pair(119, -24), Pair(42, -9), Pair(7, 7), Pair(-5, -10), Pair(-6, 1), Pair(-7, -6), Pair(-9, -18)
      }
    }},
    {{ // Bucket 33
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-8, 32), Pair(-17, -5), Pair(-15, 29), Pair(-17, 25), Pair(68, -10), Pair(65, -2), Pair(18, 17), Pair(-7, 18),
        Pair(-6, 24), Pair(12, 4), Pair(-2, 29), Pair(8, 15), Pair(4, 12), Pair(1, 14), Pair(1, 14), Pair(3, 19),
        Pair(-7, 6), Pair(3, -13), Pair(8, 13), Pair(5, 6), Pair(8, 11), Pair(1, 16), Pair(-1, 14), Pair(6, 14),
        Pair(-8, 1), Pair(-5, 15), Pair(-7, 7), Pair(-1, 7), Pair(1, 16), Pair(4, 12), Pair(2, 18), Pair(1, 21),
        Pair(8, 10), Pair(-5, -5), Pair(5, 17), Pair(-3, 15), Pair(-1, 16), Pair(4, 13), Pair(4, 20), Pair(0, 18),
        Pair(-4, 15), Pair(-1, 6), Pair(-2, 23), Pair(2, 17), Pair(-5, 21), Pair(-1, 22), Pair(2, 21), Pair(1, 19),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-43, 115), Pair(101, 57), Pair(138, 57), Pair(-99, 79), Pair(16, 87), Pair(-33, 62), Pair(-87, 65), Pair(-45, 51),
        Pair(6, 67), Pair(37, 36), Pair(-7, 53), Pair(41, 83), Pair(23, 54), Pair(18, 81), Pair(37, 58), Pair(-46, 79),
        Pair(0, 64), Pair(-21, 75), Pair(24, 61), Pair(12, 73), Pair(4, 66), Pair(-8, 82), Pair(9, 77), Pair(-17, 68),
        Pair(29, 35), Pair(9, 47), Pair(27, 64), Pair(9, 67), Pair(17, 71), Pair(5, 83), Pair(8, 71), Pair(-2, 92),
        Pair(6, 86), Pair(0, 0), Pair(10, 72), Pair(20, 75), Pair(5, 71), Pair(15, 81), Pair(-7, 67), Pair(8, 62),
        Pair(14, 64), Pair(30, 91), Pair(8, 74), Pair(19, 64), Pair(22, 61), Pair(15, 69), Pair(10, 65), Pair(20, 50),
        Pair(-13, 49), Pair(26, 66), Pair(12, 65), Pair(12, 63), Pair(10, 73), Pair(19, 78), Pair(10, 64), Pair(13, 63),
        Pair(33, 30), Pair(9, 44), Pair(38, 38), Pair(8, 69), Pair(18, 76), Pair(10, 72), Pair(9, 58), Pair(-8, -20)
      },
      { // Piece 2
        Pair(90, 44), Pair(85, 16), Pair(51, 23), Pair(55, 2), Pair(28, 46), Pair(100, -1), Pair(4, 36), Pair(-9, 28),
        Pair(21, 20), Pair(16, 61), Pair(42, 17), Pair(-17, 50), Pair(78, 6), Pair(57, 14), Pair(-30, 19), Pair(6, 35),
        Pair(25, 73), Pair(15, 27), Pair(16, 56), Pair(15, 36), Pair(33, 40), Pair(47, 4), Pair(22, 54), Pair(-20, 56),
        Pair(-10, -55), Pair(-7, 57), Pair(48, 22), Pair(6, 44), Pair(21, 41), Pair(36, 33), Pair(5, 38), Pair(16, 63),
        Pair(37, 44), Pair(0, 0), Pair(15, 55), Pair(26, 30), Pair(20, 57), Pair(17, 39), Pair(14, 49), Pair(5, 51),
        Pair(-4, -10), Pair(24, 67), Pair(12, 37), Pair(12, 62), Pair(9, 46), Pair(26, 65), Pair(19, 46), Pair(20, 65),
        Pair(12, 32), Pair(4, 46), Pair(11, 66), Pair(5, 49), Pair(16, 73), Pair(9, 52), Pair(16, 69), Pair(19, 44),
        Pair(4, 9), Pair(27, 38), Pair(1, 39), Pair(15, 62), Pair(10, 54), Pair(7, 83), Pair(17, 64), Pair(19, 74)
      },
      { // Piece 3
        Pair(-48, 124), Pair(-8, 78), Pair(-35, 112), Pair(-5, 101), Pair(-29, 121), Pair(-56, 129), Pair(-82, 131), Pair(17, 86),
        Pair(-15, 104), Pair(-19, 88), Pair(-6, 107), Pair(16, 96), Pair(4, 108), Pair(-41, 123), Pair(1, 115), Pair(-23, 110),
        Pair(-3, 103), Pair(-15, 84), Pair(6, 103), Pair(-5, 112), Pair(32, 84), Pair(-27, 125), Pair(8, 99), Pair(-10, 108),
        Pair(-4, 117), Pair(-54, 76), Pair(0, 109), Pair(4, 100), Pair(13, 95), Pair(17, 91), Pair(-18, 107), Pair(9, 99),
        Pair(-12, 85), Pair(0, 0), Pair(7, 101), Pair(20, 104), Pair(5, 110), Pair(6, 96), Pair(-11, 107), Pair(-3, 88),
        Pair(6, 104), Pair(-3, 77), Pair(28, 96), Pair(9, 101), Pair(3, 102), Pair(-7, 106), Pair(-10, 100), Pair(11, 79),
        Pair(7, 103), Pair(-8, 79), Pair(0, 109), Pair(8, 102), Pair(9, 91), Pair(5, 87), Pair(5, 106), Pair(8, 100),
        Pair(1, 98), Pair(-6, 76), Pair(4, 106), Pair(9, 98), Pair(11, 95), Pair(5, 94), Pair(-2, 103), Pair(6, 90)
      },
      { // Piece 4
        Pair(11, 164), Pair(-53, 189), Pair(7, 146), Pair(-31, 170), Pair(11, 145), Pair(-21, 160), Pair(-59, 122), Pair(-27, 178),
        Pair(-7, 140), Pair(-5, 139), Pair(5, 165), Pair(12, 155), Pair(28, 118), Pair(-7, 153), Pair(-2, 122), Pair(-6, 184),
        Pair(2, 182), Pair(1, 143), Pair(34, 125), Pair(-8, 131), Pair(-9, 163), Pair(-12, 142), Pair(10, 122), Pair(32, 106),
        Pair(-1, 154), Pair(30, 95), Pair(18, 168), Pair(4, 145), Pair(12, 147), Pair(21, 139), Pair(-10, 166), Pair(-9, 161),
        Pair(9, 165), Pair(0, 0), Pair(26, 135), Pair(27, 138), Pair(4, 170), Pair(13, 173), Pair(12, 151), Pair(17, 90),
        Pair(12, 142), Pair(24, 126), Pair(18, 161), Pair(15, 180), Pair(8, 186), Pair(26, 143), Pair(15, 162), Pair(32, 122),
        Pair(20, 135), Pair(17, 125), Pair(23, 144), Pair(25, 156), Pair(23, 163), Pair(25, 156), Pair(31, 146), Pair(12, 106),
        Pair(10, 166), Pair(25, 87), Pair(20, 155), Pair(21, 158), Pair(22, 165), Pair(33, 142), Pair(10, 186), Pair(18, 201)
      },
      { // Piece 5
        Pair(-38, 124), Pair(-113, 43), Pair(-92, 154), Pair(198, 37), Pair(-16, 44), Pair(-49, 8), Pair(-57, -33), Pair(125, 2),
        Pair(-70, 143), Pair(-19, 100), Pair(-33, 130), Pair(113, 96), Pair(70, -17), Pair(142, -5), Pair(12, 19), Pair(77, -48),
        Pair(-3, 101), Pair(70, 57), Pair(214, 58), Pair(41, 50), Pair(88, 40), Pair(-21, 30), Pair(-60, 3), Pair(-20, 2),
        Pair(92, 41), Pair(69, 34), Pair(71, 42), Pair(-63, 75), Pair(19, 48), Pair(-9, 31), Pair(64, 3), Pair(-70, 16),
        Pair(-51, 81), Pair(0, 0), Pair(-12, 64), Pair(-25, 49), Pair(-24, 40), Pair(-51, 30), Pair(-53, 19), Pair(-50, 11),
        Pair(54, 35), Pair(18, 18), Pair(12, 39), Pair(11, 33), Pair(-17, 23), Pair(-23, 19), Pair(-32, 14), Pair(-59, 17),
        Pair(116, 2), Pair(34, 25), Pair(38, 30), Pair(6, 17), Pair(-8, 20), Pair(-9, 13), Pair(-10, 3), Pair(-13, -8),
        Pair(87, -46), Pair(53, -25), Pair(41, -1), Pair(-24, 20), Pair(-2, 4), Pair(-16, 4), Pair(-4, -7), Pair(-11, -16)
      }
    }},
    {{ // Bucket 34
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(3, 9), Pair(-19, 29), Pair(-35, -7), Pair(7, 17), Pair(1, 19), Pair(26, 12), Pair(8, 8), Pair(-32, 18),
        Pair(-4, 19), Pair(-15, 27), Pair(-12, -4), Pair(-12, 29), Pair(14, 6), Pair(-1, 15), Pair(2, 12), Pair(4, 2),
        Pair(-1, 10), Pair(2, 5), Pair(-7, -32), Pair(2, 12), Pair(6, 7), Pair(11, 11), Pair(1, 12), Pair(-3, 14),
        Pair(-3, 7), Pair(-8, 6), Pair(9, -1), Pair(-7, 21), Pair(-3, 4), Pair(6, 10), Pair(2, 13), Pair(0, 16),
        Pair(0, 9), Pair(7, 11), Pair(-7, -22), Pair(2, 15), Pair(-1, 10), Pair(6, 12), Pair(0, 14), Pair(1, 11),
        Pair(0, 12), Pair(-1, 11), Pair(2, -7), Pair(-1, 18), Pair(-2, 23), Pair(-3, 16), Pair(-2, 14), Pair(2, 20),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-77, 131), Pair(-29, 69), Pair(49, 56), Pair(79, 45), Pair(-59, 85), Pair(-82, 46), Pair(10, 76), Pair(-100, 74),
        Pair(-16, 68), Pair(22, 50), Pair(-3, 68), Pair(-55, 81), Pair(-50, 77), Pair(-17, 75), Pair(30, 71), Pair(-14, 59),
        Pair(18, 79), Pair(-9, 49), Pair(-25, 71), Pair(1, 49), Pair(-17, 71), Pair(-21, 86), Pair(-9, 79), Pair(-52, 89),
        Pair(-44, 65), Pair(-19, 70), Pair(-15, 48), Pair(13, 84), Pair(-18, 64), Pair(-6, 68), Pair(-17, 71), Pair(-15, 56),
        Pair(-8, 60), Pair(-22, 90), Pair(0, 0), Pair(-7, 63), Pair(-9, 72), Pair(-3, 72), Pair(-8, 71), Pair(-9, 58),
        Pair(-15, 27), Pair(-3, 66), Pair(2, 89), Pair(5, 71), Pair(0, 58), Pair(-5, 67), Pair(-3, 61), Pair(6, 49),
        Pair(-15, 34), Pair(-4, 32), Pair(-4, 69), Pair(-10, 60), Pair(-2, 63), Pair(5, 65), Pair(-1, 64), Pair(-9, 65),
        Pair(29, 29), Pair(-12, 63), Pair(-11, 65), Pair(-15, 51), Pair(2, 65), Pair(-7, 59), Pair(-4, 42), Pair(10, 0)
      },
      { // Piece 2
        Pair(28, 22), Pair(72, 43), Pair(33, 4), Pair(-36, 52), Pair(21, 13), Pair(21, 18), Pair(13, 7), Pair(53, 13),
        Pair(-19, 58), Pair(3, 23), Pair(6, 45), Pair(14, 22), Pair(26, 37), Pair(62, -16), Pair(-1, 36), Pair(23, 9),
        Pair(-30, -13), Pair(17, 39), Pair(19, 3), Pair(22, 47), Pair(5, 1), Pair(20, 33), Pair(-9, 20), Pair(-10, 45),
        Pair(8, 54), Pair(-34, 12), Pair(-8, 37), Pair(19, -9), Pair(7, 39), Pair(-1, 20), Pair(-4, 54), Pair(-7, 25),
        Pair(-12, 17), Pair(10, 61), Pair(0, 0), Pair(6, 55), Pair(-13, 35), Pair(4, 51), Pair(5, 28), Pair(-2, 50),
        Pair(-10, 60), Pair(-33, 9), Pair(12, 69), Pair(-11, 15), Pair(-1, 56), Pair(-2, 32), Pair(2, 58), Pair(-9, 35),
        Pair(-34, -21), Pair(-8, 68), Pair(-9, 27), Pair(-2, 56), Pair(-7, 27), Pair(2, 62), Pair(-12, 49), Pair(-3, 62),
        Pair(-3, 39), Pair(0, 8), Pair(-4, 57), Pair(3, 25), Pair(2, 48), Pair(-15, 27), Pair(1, 49), Pair(6, 32)
      },
      { // Piece 3
        Pair(-29, 85), Pair(-40, 89), Pair(-33, 73), Pair(-53, 93), Pair(-55, 105), Pair(-36, 88), Pair(-16, 88), Pair(-30, 87),
        Pair(-23, 89), Pair(-19, 89), Pair(-28, 69), Pair(-33, 89), Pair(-10, 84), Pair(-17, 78), Pair(-29, 89), Pair(-23, 84),
        Pair(-28, 97), Pair(-20, 88), Pair(-54, 89), Pair(-43, 90), Pair(-35, 97), Pair(-26, 98), Pair(-2, 78), Pair(-55, 104),
        Pair(-15, 87), Pair(-9, 82), Pair(-34, 60), Pair(-6, 89), Pair(-6, 78), Pair(-20, 91), Pair(-17, 90), Pair(-32, 94),
        Pair(-19, 60), Pair(-22, 68), Pair(0, 0), Pair(-9, 76), Pair(-8, 81), Pair(-8, 63), Pair(-7, 76), Pair(-8, 66),
        Pair(-7, 77), Pair(-4, 80), Pair(-16, 59), Pair(-5, 80), Pair(-16, 89), Pair(-13, 80), Pair(-27, 84), Pair(-5, 79),
        Pair(-10, 63), Pair(-6, 72), Pair(-25, 48), Pair(-22, 87), Pair(-4, 73), Pair(-25, 77), Pair(-16, 70), Pair(-35, 105),
        Pair(-16, 79), Pair(-10, 82), Pair(-17, 47), Pair(-13, 80), Pair(-15, 78), Pair(-13, 74), Pair(-13, 77), Pair(-14, 79)
      },
      { // Piece 4
        Pair(4, 119), Pair(-42, 162), Pair(9, 80), Pair(29, 94), Pair(-30, 143), Pair(-15, 135), Pair(9, 142), Pair(5, 115),
        Pair(-13, 119), Pair(20, 86), Pair(-33, 102), Pair(-2, 114), Pair(24, 92), Pair(40, 85), Pair(-20, 150), Pair(26, 80),
        Pair(-11, 87), Pair(-6, 134), Pair(1, 61), Pair(-11, 122), Pair(-21, 118), Pair(10, 102), Pair(5, 112), Pair(-6, 140),
        Pair(-15, 144), Pair(-8, 122), Pair(2, 59), Pair(-15, 140), Pair(2, 123), Pair(-8, 112), Pair(-10, 137), Pair(-5, 120),
        Pair(-2, 94), Pair(4, 108), Pair(0, 0), Pair(-8, 131), Pair(-6, 126), Pair(0, 134), Pair(0, 121), Pair(-1, 98),
        Pair(-2, 116), Pair(7, 98), Pair(7, 106), Pair(6, 117), Pair(4, 138), Pair(11, 119), Pair(-4, 121), Pair(15, 98),
        Pair(-1, 77), Pair(6, 113), Pair(6, 93), Pair(11, 112), Pair(5, 123), Pair(19, 91), Pair(19, 100), Pair(-25, 134),
        Pair(21, 77), Pair(8, 107), Pair(8, 89), Pair(6, 123), Pair(7, 141), Pair(16, 99), Pair(-10, 144), Pair(7, 126)
      },
      { // Piece 5
        Pair(27, 59), Pair(-9, 101), Pair(70, 89), Pair(157, 137), Pair(165, -26), Pair(-107, 14), Pair(13, -54), Pair(-2, 47),
        Pair(78, 78), Pair(134, 67), Pair(102, 82), Pair(52, 68), Pair(193, 21), Pair(-34, 30), Pair(-9, 23), Pair(-178, 18),
        Pair(-34, 72), Pair(94, 87), Pair(191, 27), Pair(63, 59), Pair(68, 34), Pair(87, 25), Pair(-13, 18), Pair(-108, 16),
        Pair(143, 79), Pair(51, 22), Pair(62, 30), Pair(50, 34), Pair(-23, 47), Pair(-43, 42), Pair(-57, 15), Pair(-49, 9),
        Pair(-65, 71), Pair(71, 32), Pair(0, 0), Pair(-5, 48), Pair(-31, 30), Pair(-24, 8), Pair(-36, 16), Pair(1, -14),
        Pair(99, 4), Pair(-28, 37), Pair(14, 22), Pair(-27, 26), Pair(5, 16), Pair(-2, 2), Pair(2, -2), Pair(-9, -7),
        Pair(19, 13), Pair(-11, 25), Pair(-1, 15), Pair(-4, 18), Pair(-1, 5), Pair(-4, 1), Pair(-6, -2), Pair(-11, -7),
        Pair(31, -21), Pair(19, -32), Pair(30, -26), Pair(20, -24), Pair(4, -10), Pair(-13, -4), Pair(-6, -15), Pair(-8, -21)
      }
    }},
    {{ // Bucket 35
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-5, 15), Pair(-21, 19), Pair(-13, 27), Pair(-6, 16), Pair(-9, 20), Pair(-43, 41), Pair(7, 5), Pair(13, -2),
        Pair(-4, 9), Pair(1, 11), Pair(-6, 24), Pair(2, -2), Pair(-3, 22), Pair(6, 17), Pair(-19, 14), Pair(-5, 21),
        Pair(2, 12), Pair(4, 8), Pair(12, 17), Pair(-2, -8), Pair(12, 10), Pair(3, 14), Pair(3, 14), Pair(1, 9),
        Pair(2, 15), Pair(1, 10), Pair(-6, 20), Pair(5, -18), Pair(-2, 18), Pair(0, 3), Pair(6, 15), Pair(1, 11),
        Pair(0, 14), Pair(2, 8), Pair(10, 20), Pair(6, -11), Pair(6, 21), Pair(4, 9), Pair(3, 15), Pair(2, 12),
        Pair(1, 14), Pair(3, 13), Pair(2, 23), Pair(11, -5), Pair(0, 21), Pair(0, 17), Pair(-1, 19), Pair(3, 14),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-7, 25), Pair(-125, 112), Pair(11, 62), Pair(-12, 51), Pair(-35, 75), Pair(-13, 69), Pair(-3, 74), Pair(-70, 82),
        Pair(6, 44), Pair(-15, 76), Pair(-4, 73), Pair(-16, 80), Pair(-9, 67), Pair(16, 45), Pair(38, 36), Pair(-4, 69),
        Pair(-11, 88), Pair(-7, 71), Pair(-9, 56), Pair(-23, 61), Pair(-12, 50), Pair(-49, 92), Pair(-2, 76), Pair(-19, 51),
        Pair(-6, 66), Pair(-11, 65), Pair(18, 61), Pair(-20, 35), Pair(0, 65), Pair(-4, 61), Pair(-15, 62), Pair(-28, 65),
        Pair(4, 68), Pair(7, 67), Pair(3, 61), Pair(0, 0), Pair(-13, 67), Pair(-5, 71), Pair(-20, 73), Pair(-3, 62),
        Pair(-6, 61), Pair(-9, 51), Pair(2, 74), Pair(18, 99), Pair(11, 73), Pair(-2, 51), Pair(-6, 70), Pair(1, 57),
        Pair(6, 71), Pair(36, 47), Pair(-8, 58), Pair(3, 58), Pair(-3, 54), Pair(1, 64), Pair(8, 69), Pair(1, 44),
        Pair(-41, 100), Pair(-4, 60), Pair(-1, 68), Pair(9, 60), Pair(9, 57), Pair(-3, 51), Pair(1, 72), Pair(27, 77)
      },
      { // Piece 2
        Pair(30, 37), Pair(48, -4), Pair(20, 32), Pair(31, -18), Pair(-55, 43), Pair(14, -7), Pair(-25, 63), Pair(1, -55),
        Pair(-29, -13), Pair(12, 49), Pair(7, 0), Pair(12, 33), Pair(8, 12), Pair(15, 41), Pair(-41, -27), Pair(-4, 44),
        Pair(19, 36), Pair(-6, -11), Pair(20, 28), Pair(-3, 17), Pair(6, 42), Pair(-4, -3), Pair(29, 17), Pair(-25, 29),
        Pair(-9, 17), Pair(9, 38), Pair(2, -9), Pair(-12, 34), Pair(-13, 13), Pair(0, 42), Pair(-12, 21), Pair(-7, 53),
        Pair(19, 41), Pair(-4, 26), Pair(5, 46), Pair(0, 0), Pair(-8, 48), Pair(-5, 29), Pair(16, 37), Pair(-8, 17),
        Pair(-11, 15), Pair(3, 41), Pair(-34, -18), Pair(12, 76), Pair(-16, 11), Pair(10, 48), Pair(-5, 33), Pair(6, 56),
        Pair(8, 54), Pair(-41, -19), Pair(11, 42), Pair(-7, 27), Pair(8, 48), Pair(-16, 10), Pair(-4, 55), Pair(1, 21),
        Pair(-58, -29), Pair(14, 46), Pair(-14, 17), Pair(24, 37), Pair(3, 16), Pair(2, 48), Pair(-23, 10), Pair(-4, 3)
      },
      { // Piece 3
        Pair(4, 74), Pair(21, 67), Pair(-44, 89), Pair(-23, 64), Pair(-19, 88), Pair(-2, 91), Pair(-22, 84), Pair(-10, 75),
        Pair(-10, 91), Pair(-19, 88), Pair(-15, 84), Pair(-33, 83), Pair(-29, 93), Pair(-12, 96), Pair(-28, 86), Pair(-23, 88),
        Pair(-17, 91), Pair(-6, 82), Pair(-26, 87), Pair(-14, 71), Pair(-34, 90), Pair(-17, 67), Pair(5, 83), Pair(-11, 79),
        Pair(3, 77), Pair(-8, 91), Pair(0, 75), Pair(-9, 50), Pair(7, 80), Pair(-10, 83), Pair(-30, 78), Pair(-7, 83),
        Pair(-3, 68), Pair(-1, 69), Pair(-16, 71), Pair(0, 0), Pair(-15, 70), Pair(-14, 63), Pair(3, 54), Pair(-25, 76),
        Pair(6, 75), Pair(-5, 86), Pair(7, 76), Pair(-2, 57), Pair(3, 64), Pair(-4, 58), Pair(-10, 67), Pair(2, 60),
        Pair(-3, 75), Pair(-12, 82), Pair(-3, 67), Pair(-7, 48), Pair(-6, 71), Pair(-9, 78), Pair(6, 62), Pair(-3, 73),
        Pair(-3, 73), Pair(-3, 72), Pair(-10, 78), Pair(1, 46), Pair(-8, 74), Pair(-9, 74), Pair(-5, 72), Pair(0, 60)
      },
      { // Piece 4
        Pair(26, 97), Pair(45, 112), Pair(-3, 112), Pair(31, 98), Pair(14, 116), Pair(57, 107), Pair(-105, 184), Pair(49, 88),
        Pair(-20, 117), Pair(7, 138), Pair(27, 103), Pair(18, 120), Pair(-28, 141), Pair(-16, 184), Pair(-4, 114), Pair(-32, 144),
        Pair(15, 125), Pair(4, 84), Pair(22, 88), Pair(13, 74), Pair(-3, 129), Pair(2, 113), Pair(-26, 174), Pair(-2, 132),
        Pair(12, 97), Pair(-2, 139), Pair(15, 107), Pair(-9, 71), Pair(7, 116), Pair(6, 132), Pair(1, 106), Pair(9, 97),
        Pair(11, 107), Pair(12, 101), Pair(11, 75), Pair(0, 0), Pair(-3, 114), Pair(2, 128), Pair(-4, 132), Pair(7, 95),
        Pair(7, 116), Pair(15, 116), Pair(7, 114), Pair(15, 108), Pair(14, 106), Pair(11, 133), Pair(6, 124), Pair(12, 132),
        Pair(23, 95), Pair(19, 82), Pair(15, 126), Pair(14, 104), Pair(12, 115), Pair(14, 110), Pair(22, 95), Pair(9, 105),
        Pair(30, 73), Pair(24, 110), Pair(14, 121), Pair(15, 104), Pair(11, 114), Pair(9, 136), Pair(46, 36), Pair(0, 113)
      },
      { // Piece 5
        Pair(-65, -24), Pair(12, 126), Pair(-56, 63), Pair(33, 183), Pair(-4, 72), Pair(74, 108), Pair(-61, 35), Pair(95, -36),
        Pair(-262, 71), Pair(32, 97), Pair(30, 55), Pair(54, 69), Pair(40, 67), Pair(195, 42), Pair(40, 70), Pair(72, 5),
        Pair(-255, 89), Pair(43, 20), Pair(85, 30), Pair(68, 44), Pair(-77, 64), Pair(-105, 61), Pair(15, 25), Pair(31, -5),
        Pair(-66, 39), Pair(-55, 44), Pair(-13, 34), Pair(-40, 35), Pair(-26, 18), Pair(75, 17), Pair(24, -9), Pair(-17, -6),
        Pair(38, 9), Pair(15, 26), Pair(0, 44), Pair(0, 0), Pair(-7, 43), Pair(-7, 17), Pair(41, -13), Pair(-72, 8),
        Pair(-30, -1), Pair(33, 3), Pair(8, 10), Pair(-54, 46), Pair(-34, 17), Pair(27, -6), Pair(5, -11), Pair(-8, -5),
        Pair(35, -23), Pair(2, 0), Pair(-13, 5), Pair(-33, 20), Pair(-19, 1), Pair(10, -15), Pair(-1, -11), Pair(8, -23),
        Pair(12, -21), Pair(-5, -16), Pair(0, -24), Pair(-11, 6), Pair(10, -39), Pair(4, -17), Pair(1, -23), Pair(5, -29)
      }
    }},
    {{ // Bucket 36
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-23, 19), Pair(-17, 15), Pair(-17, 25), Pair(-30, 27), Pair(-93, 21), Pair(-18, -3), Pair(14, 26), Pair(-17, 20),
        Pair(1, 14), Pair(-1, 10), Pair(6, 10), Pair(-7, 20), Pair(5, -7), Pair(7, 16), Pair(-1, 12), Pair(-1, 12),
        Pair(-1, 8), Pair(3, 16), Pair(5, 6), Pair(8, 19), Pair(5, -6), Pair(16, 11), Pair(0, 10), Pair(0, 8),
        Pair(1, 15), Pair(4, 16), Pair(-3, 6), Pair(-2, 21), Pair(1, -12), Pair(5, 9), Pair(-4, 9), Pair(1, 11),
        Pair(2, 13), Pair(4, 17), Pair(3, 9), Pair(12, 16), Pair(3, -5), Pair(21, 15), Pair(-2, 9), Pair(4, 13),
        Pair(2, 18), Pair(4, 15), Pair(2, 14), Pair(6, 18), Pair(2, 5), Pair(8, 27), Pair(2, 18), Pair(4, 15),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-21, 29), Pair(-21, 34), Pair(13, 60), Pair(61, 42), Pair(30, 42), Pair(95, 46), Pair(32, -1), Pair(-51, 62),
        Pair(17, 46), Pair(-33, 65), Pair(-5, 50), Pair(16, 59), Pair(-30, 79), Pair(6, 55), Pair(-19, 67), Pair(-68, 68),
        Pair(8, 50), Pair(0, 83), Pair(-5, 71), Pair(-8, 57), Pair(-45, 80), Pair(9, 43), Pair(-21, 71), Pair(-6, 84),
        Pair(-2, 70), Pair(0, 68), Pair(-5, 49), Pair(-4, 84), Pair(-27, 49), Pair(-1, 62), Pair(-20, 45), Pair(-14, 55),
        Pair(4, 51), Pair(14, 65), Pair(6, 64), Pair(10, 57), Pair(0, 0), Pair(0, 54), Pair(-16, 59), Pair(-6, 60),
        Pair(5, 60), Pair(5, 66), Pair(-1, 45), Pair(16, 70), Pair(15, 90), Pair(2, 78), Pair(-3, 32), Pair(-1, 54),
        Pair(15, 66), Pair(4, 53), Pair(0, 59), Pair(0, 50), Pair(8, 54), Pair(4, 50), Pair(-6, 56), Pair(-8, 65),
        Pair(47, -1), Pair(1, 77), Pair(5, 72), Pair(5, 58), Pair(5, 70), Pair(-12, 81), Pair(4, 52), Pair(-20, 46)
      },
      { // Piece 2
        Pair(-48, 2), Pair(57, 16), Pair(99, -29), Pair(61, 22), Pair(89, -7), Pair(48, 27), Pair(-18, 12), Pair(51, -7),
        Pair(20, 13), Pair(28, -12), Pair(-1, 33), Pair(60, -10), Pair(68, 0), Pair(18, 3), Pair(-11, 33), Pair(-114, 13),
        Pair(5, 20), Pair(17, 25), Pair(3, -3), Pair(20, 36), Pair(-12, 17), Pair(30, 24), Pair(-10, -1), Pair(-12, 49),
        Pair(17, 41), Pair(-5, 25), Pair(7, 36), Pair(15, -12), Pair(-15, 30), Pair(39, -14), Pair(3, 48), Pair(-15, 10),
        Pair(-9, 33), Pair(19, 27), Pair(-4, 22), Pair(7, 35), Pair(0, 0), Pair(4, 42), Pair(1, 14), Pair(-2, 49),
        Pair(8, 42), Pair(-9, 23), Pair(3, 56), Pair(-7, 10), Pair(9, 70), Pair(-33, -6), Pair(1, 48), Pair(-14, 24),
        Pair(17, 0), Pair(-3, 50), Pair(-10, 2), Pair(2, 47), Pair(-1, 18), Pair(2, 42), Pair(-35, -9), Pair(-12, 66),
        Pair(4, 45), Pair(-27, -26), Pair(-2, 46), Pair(1, 22), Pair(25, 24), Pair(-11, 24), Pair(6, 31), Pair(-28, -72)
      },
      { // Piece 3
        Pair(6, 70), Pair(26, 57), Pair(-4, 65), Pair(5, 72), Pair(85, 38), Pair(-38, 93), Pair(64, 46), Pair(43, 48),
        Pair(-8, 70), Pair(-18, 78), Pair(-19, 84), Pair(-4, 68), Pair(-9, 55), Pair(-20, 70), Pair(-16, 80), Pair(3, 81),
        Pair(8, 71), Pair(26, 65), Pair(1, 77), Pair(3, 59), Pair(-8, 62), Pair(-22, 69), Pair(-13, 81), Pair(25, 71),
        Pair(12, 76), Pair(11, 73), Pair(0, 80), Pair(5, 69), Pair(-5, 41), Pair(10, 76), Pair(29, 56), Pair(10, 61),
        Pair(12, 60), Pair(-12, 68), Pair(4, 62), Pair(4, 54), Pair(0, 0), Pair(-13, 55), Pair(-10, 53), Pair(-17, 69),
        Pair(12, 54), Pair(2, 71), Pair(8, 63), Pair(8, 66), Pair(8, 32), Pair(-2, 68), Pair(-9, 59), Pair(7, 43),
        Pair(5, 58), Pair(3, 71), Pair(9, 52), Pair(-4, 67), Pair(0, 30), Pair(-14, 68), Pair(-2, 50), Pair(23, 55),
        Pair(6, 66), Pair(4, 68), Pair(4, 67), Pair(3, 69), Pair(5, 41), Pair(-4, 70), Pair(7, 64), Pair(15, 57)
      },
      { // Piece 4
        Pair(-8, 111), Pair(27, 102), Pair(-9, 125), Pair(-21, 140), Pair(30, 93), Pair(21, 121), Pair(-107, 238), Pair(-9, 153),
        Pair(-13, 138), Pair(-3, 108), Pair(25, 116), Pair(18, 83), Pair(26, 89), Pair(-11, 150), Pair(46, 58), Pair(-21, 165),
        Pair(0, 163), Pair(-5, 124), Pair(1, 108), Pair(-2, 139), Pair(2, 89), Pair(1, 111), Pair(-12, 126), Pair(-25, 168),
        Pair(-2, 133), Pair(5, 110), Pair(3, 130), Pair(7, 100), Pair(8, 74), Pair(13, 99), Pair(4, 127), Pair(-7, 124),
        Pair(12, 81), Pair(16, 96), Pair(1, 109), Pair(6, 104), Pair(0, 0), Pair(6, 89), Pair(11, 103), Pair(-14, 131),
        Pair(25, 88), Pair(18, 111), Pair(11, 101), Pair(16, 108), Pair(16, 97), Pair(10, 105), Pair(6, 116), Pair(8, 129),
        Pair(3, 137), Pair(21, 97), Pair(16, 104), Pair(22, 95), Pair(14, 106), Pair(8, 102), Pair(16, 94), Pair(37, 91),
        Pair(21, 98), Pair(22, 86), Pair(15, 118), Pair(16, 120), Pair(20, 92), Pair(10, 126), Pair(-10, 161), Pair(34, 78)
      },
      { // Piece 5
        Pair(-72, -30), Pair(-153, 11), Pair(35, 36), Pair(-229, 129), Pair(295, -32), Pair(134, 79), Pair(22, 129), Pair(83, -65),
        Pair(67, -3), Pair(-52, 17), Pair(-17, 22), Pair(-43, 66), Pair(134, 97), Pair(10, 72), Pair(77, 43), Pair(-10, 94),
        Pair(-4, 23), Pair(-27, 26), Pair(-86, 44), Pair(43, 38), Pair(-19, 53), Pair(8, 54), Pair(42, 4), Pair(-86, 49),
        Pair(-84, 5), Pair(-43, 22), Pair(-22, 8), Pair(-10, 13), Pair(7, 14), Pair(-3, 4), Pair(29, 4), Pair(6, 6),
        Pair(31, -5), Pair(15, -11), Pair(14, 17), Pair(-43, 38), Pair(0, 0), Pair(-37, 24), Pair(50, 4), Pair(27, 0),
        Pair(32, -18), Pair(8, 9), Pair(4, -1), Pair(-35, 22), Pair(-24, 26), Pair(-18, 4), Pair(5, -4), Pair(32, -17),
        Pair(6, -12), Pair(-11, -16), Pair(-10, -11), Pair(-27, 10), Pair(-32, 11), Pair(-32, 3), Pair(5, -16), Pair(15, -23),
        Pair(0, -68), Pair(-16, -22), Pair(-12, -32), Pair(-11, -7), Pair(6, -22), Pair(-2, -24), Pair(2, -26), Pair(5, -31)
      }
    }},
    {{ // Bucket 37
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 11), Pair(-17, 16), Pair(17, 6), Pair(-4, 10), Pair(6, 4), Pair(-35, 0), Pair(-7, 16), Pair(-23, 18),
        Pair(-2, 16), Pair(0, 12), Pair(8, 11), Pair(11, 15), Pair(0, 16), Pair(-7, 7), Pair(-16, 21), Pair(-2, 11),
        Pair(2, 11), Pair(7, 9), Pair(7, 6), Pair(7, 11), Pair(9, 6), Pair(-5, -8), Pair(2, -3), Pair(3, 2),
        Pair(0, 11), Pair(10, 14), Pair(6, 11), Pair(-1, 5), Pair(3, 10), Pair(-6, -2), Pair(9, -6), Pair(-1, 2),
        Pair(-2, 12), Pair(2, 11), Pair(6, 9), Pair(2, 10), Pair(16, 9), Pair(4, -3), Pair(10, 3), Pair(-2, 7),
        Pair(2, 17), Pair(6, 15), Pair(1, 12), Pair(-3, 19), Pair(14, 15), Pair(4, 6), Pair(5, 14), Pair(-5, 8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(18, 49), Pair(-123, 95), Pair(-47, 66), Pair(105, 13), Pair(65, 31), Pair(74, 8), Pair(195, -6), Pair(12, 37),
        Pair(26, 50), Pair(15, 37), Pair(26, 46), Pair(17, 53), Pair(2, 51), Pair(-13, 50), Pair(48, 39), Pair(-28, 24),
        Pair(1, 44), Pair(21, 56), Pair(23, 55), Pair(-2, 56), Pair(8, 34), Pair(-53, 68), Pair(0, 34), Pair(-24, 59),
        Pair(-8, 54), Pair(14, 47), Pair(25, 49), Pair(7, 45), Pair(15, 51), Pair(-19, 43), Pair(-13, 36), Pair(-21, 41),
        Pair(4, 52), Pair(16, 36), Pair(16, 55), Pair(23, 47), Pair(-2, 54), Pair(0, 0), Pair(-14, 56), Pair(-2, 51),
        Pair(4, 63), Pair(17, 38), Pair(12, 53), Pair(12, 42), Pair(26, 54), Pair(11, 74), Pair(18, 58), Pair(-7, 14),
        Pair(9, 45), Pair(16, 40), Pair(11, 44), Pair(10, 46), Pair(2, 50), Pair(10, 37), Pair(-1, 34), Pair(-4, 55),
        Pair(-60, 43), Pair(13, 32), Pair(14, 50), Pair(20, 44), Pair(21, 43), Pair(11, 38), Pair(5, 24), Pair(12, 95)
      },
      { // Piece 2
        Pair(7, 12), Pair(-10, -15), Pair(75, -4), Pair(48, -9), Pair(16, 24), Pair(62, -14), Pair(194, -7), Pair(-7, 6),
        Pair(18, -3), Pair(15, 22), Pair(12, 1), Pair(30, 18), Pair(29, -3), Pair(0, 16), Pair(19, -1), Pair(2, 47),
        Pair(13, 28), Pair(13, -1), Pair(30, 20), Pair(19, 2), Pair(31, 25), Pair(-29, 9), Pair(10, 33), Pair(-57, 0),
        Pair(-9, 23), Pair(32, 22), Pair(-2, 11), Pair(19, 22), Pair(8, 4), Pair(14, 12), Pair(-30, 24), Pair(10, 38),
        Pair(16, 31), Pair(9, 14), Pair(20, 29), Pair(13, 19), Pair(13, 34), Pair(0, 0), Pair(11, 27), Pair(-24, 38),
        Pair(0, 22), Pair(13, 29), Pair(3, 19), Pair(21, 36), Pair(-1, 13), Pair(29, 51), Pair(-15, -25), Pair(14, 50),
        Pair(2, 44), Pair(-2, 22), Pair(19, 31), Pair(-9, 17), Pair(20, 33), Pair(10, 5), Pair(10, 40), Pair(-36, -26),
        Pair(10, 27), Pair(5, 37), Pair(-15, 17), Pair(16, 40), Pair(8, 17), Pair(17, 42), Pair(-5, 18), Pair(44, -21)
      },
      { // Piece 3
        Pair(42, 40), Pair(14, 45), Pair(59, 44), Pair(46, 36), Pair(18, 46), Pair(72, 18), Pair(29, 46), Pair(70, 36),
        Pair(34, 43), Pair(17, 51), Pair(25, 45), Pair(18, 47), Pair(0, 50), Pair(-25, 56), Pair(33, 40), Pair(6, 57),
        Pair(27, 47), Pair(43, 41), Pair(37, 43), Pair(31, 43), Pair(6, 55), Pair(17, 33), Pair(28, 34), Pair(-13, 56),
        Pair(20, 50), Pair(43, 41), Pair(26, 48), Pair(32, 42), Pair(30, 54), Pair(21, 14), Pair(22, 57), Pair(12, 60),
        Pair(23, 45), Pair(28, 36), Pair(19, 47), Pair(30, 40), Pair(15, 48), Pair(0, 0), Pair(8, 37), Pair(8, 36),
        Pair(16, 47), Pair(20, 49), Pair(8, 51), Pair(20, 48), Pair(25, 43), Pair(11, 27), Pair(17, 42), Pair(16, 44),
        Pair(1, 45), Pair(17, 35), Pair(19, 44), Pair(30, 36), Pair(20, 41), Pair(13, 20), Pair(18, 54), Pair(2, 68),
        Pair(19, 48), Pair(25, 45), Pair(24, 42), Pair(28, 41), Pair(20, 43), Pair(19, 15), Pair(15, 55), Pair(17, 38)
      },
      { // Piece 4
        Pair(-5, 148), Pair(41, 47), Pair(-39, 143), Pair(58, 69), Pair(8, 117), Pair(39, 78), Pair(-65, 114), Pair(-2, 129),
        Pair(6, 119), Pair(19, 84), Pair(31, 80), Pair(37, 73), Pair(20, 83), Pair(15, 12), Pair(-34, 180), Pair(-20, 151),
        Pair(7, 117), Pair(4, 95), Pair(15, 71), Pair(-19, 121), Pair(-24, 106), Pair(-24, 61), Pair(-15, 105), Pair(-13, 97),
        Pair(-1, 101), Pair(-5, 136), Pair(-12, 119), Pair(-11, 137), Pair(3, 92), Pair(0, 37), Pair(-4, 86), Pair(-18, 114),
        Pair(12, 120), Pair(16, 103), Pair(15, 84), Pair(4, 102), Pair(17, 67), Pair(0, 0), Pair(-18, 109), Pair(7, 53),
        Pair(13, 92), Pair(12, 102), Pair(14, 105), Pair(14, 93), Pair(3, 99), Pair(13, 89), Pair(-2, 79), Pair(18, 61),
        Pair(19, 94), Pair(19, 92), Pair(14, 101), Pair(11, 93), Pair(12, 103), Pair(5, 79), Pair(6, 106), Pair(-3, 83),
        Pair(21, 102), Pair(7, 120), Pair(11, 91), Pair(9, 111), Pair(15, 93), Pair(-1, 95), Pair(12, 73), Pair(8, 106)
      },
      { // Piece 5
        Pair(86, -117), Pair(-93, 71), Pair(-37, 10), Pair(84, 46), Pair(-134, 106), Pair(-22, 68), Pair(-29, 123), Pair(-37, 61),
        Pair(24, 5), Pair(2, 4), Pair(64, 14), Pair(-30, 44), Pair(-91, 77), Pair(-73, 71), Pair(157, 55), Pair(15, 2),
        Pair(-128, 15), Pair(20, 7), Pair(-11, 8), Pair(-111, 59), Pair(48, 53), Pair(-9, 47), Pair(-20, 45), Pair(15, 23),
        Pair(-72, 2), Pair(-45, 18), Pair(-60, 33), Pair(-34, 29), Pair(3, 14), Pair(21, 2), Pair(6, 9), Pair(20, 27),
        Pair(-38, -22), Pair(16, -3), Pair(-36, 23), Pair(-1, 28), Pair(29, 8), Pair(0, 0), Pair(46, -3), Pair(49, 17),
        Pair(-6, -13), Pair(-1, -2), Pair(-1, 2), Pair(0, 9), Pair(1, 11), Pair(-9, 11), Pair(7, -1), Pair(46, -8),
        Pair(-36, -10), Pair(-14, 1), Pair(-2, -7), Pair(-18, 10), Pair(4, 7), Pair(-47, 18), Pair(-14, 8), Pair(17, -5),
        Pair(-23, -13), Pair(-21, -12), Pair(-24, -9), Pair(-18, -22), Pair(6, -36), Pair(-4, -22), Pair(9, -35), Pair(8, -23)
      }
    }},
    {{ // Bucket 38
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-20, 15), Pair(18, 8), Pair(8, 11), Pair(33, 12), Pair(8, 11), Pair(-14, 17), Pair(27, -29), Pair(-12, 16),
        Pair(-1, 13), Pair(1, 17), Pair(12, 9), Pair(0, 13), Pair(6, 6), Pair(-2, 13), Pair(4, -19), Pair(7, 16),
        Pair(1, 14), Pair(5, 11), Pair(0, 12), Pair(8, 6), Pair(6, 10), Pair(6, 6), Pair(15, -28), Pair(5, -6),
        Pair(-4, 17), Pair(2, 17), Pair(4, 14), Pair(5, 15), Pair(-3, 7), Pair(8, -7), Pair(2, 6), Pair(10, -11),
        Pair(-1, 19), Pair(0, 17), Pair(4, 18), Pair(1, 16), Pair(-1, 14), Pair(21, 5), Pair(9, -15), Pair(16, 7),
        Pair(-4, 20), Pair(1, 18), Pair(-1, 18), Pair(0, 13), Pair(1, 17), Pair(10, 21), Pair(12, -8), Pair(4, 21),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-8, 60), Pair(127, 60), Pair(44, 44), Pair(86, 11), Pair(-86, 86), Pair(51, 14), Pair(-50, 60), Pair(11, 17),
        Pair(-24, 62), Pair(9, 32), Pair(8, 38), Pair(40, 43), Pair(32, 46), Pair(-7, 45), Pair(-9, 55), Pair(43, 39),
        Pair(20, 49), Pair(18, 46), Pair(14, 46), Pair(14, 54), Pair(12, 47), Pair(21, 35), Pair(3, 35), Pair(8, 23),
        Pair(-7, 61), Pair(10, 55), Pair(12, 56), Pair(25, 44), Pair(17, 42), Pair(19, 36), Pair(14, 26), Pair(-41, 1),
        Pair(-3, 62), Pair(17, 44), Pair(12, 52), Pair(16, 51), Pair(22, 49), Pair(19, 43), Pair(0, 0), Pair(7, 57),
        Pair(4, 54), Pair(19, 43), Pair(8, 54), Pair(25, 49), Pair(20, 32), Pair(14, 54), Pair(21, 62), Pair(24, 58),
        Pair(-4, 40), Pair(-12, 51), Pair(10, 45), Pair(9, 62), Pair(11, 49), Pair(14, 36), Pair(2, 44), Pair(-9, 38),
        Pair(-45, 51), Pair(-9, 33), Pair(-10, 51), Pair(-6, 58), Pair(16, 48), Pair(-4, 41), Pair(5, 34), Pair(10, 36)
      },
      { // Piece 2
        Pair(-12, -32), Pair(-32, 26), Pair(67, -10), Pair(94, 15), Pair(13, 13), Pair(76, 25), Pair(192, 0), Pair(-53, 66),
        Pair(5, 31), Pair(14, 7), Pair(-4, 21), Pair(99, -27), Pair(33, 20), Pair(9, 5), Pair(13, 40), Pair(22, 18),
        Pair(3, 24), Pair(42, 15), Pair(52, -7), Pair(43, 14), Pair(37, -3), Pair(82, 17), Pair(22, 14), Pair(16, 29),
        Pair(22, 29), Pair(27, 10), Pair(39, 31), Pair(25, 14), Pair(8, 31), Pair(46, -4), Pair(12, 23), Pair(-87, -34),
        Pair(16, 19), Pair(12, 37), Pair(16, 12), Pair(26, 29), Pair(15, 22), Pair(16, 39), Pair(0, 0), Pair(22, 25),
        Pair(11, 51), Pair(13, 18), Pair(10, 40), Pair(17, 23), Pair(17, 41), Pair(8, 15), Pair(23, 48), Pair(-17, -39),
        Pair(5, 28), Pair(10, 40), Pair(12, 29), Pair(18, 42), Pair(6, 24), Pair(19, 27), Pair(13, 15), Pair(7, 35),
        Pair(18, 43), Pair(31, 10), Pair(9, 44), Pair(-6, 32), Pair(32, 32), Pair(4, 23), Pair(2, 45), Pair(16, -2)
      },
      { // Piece 3
        Pair(30, 51), Pair(84, 33), Pair(81, 38), Pair(79, 36), Pair(36, 58), Pair(17, 66), Pair(192, -6), Pair(58, 44),
        Pair(49, 42), Pair(16, 57), Pair(17, 49), Pair(34, 49), Pair(49, 52), Pair(30, 55), Pair(41, 38), Pair(12, 52),
        Pair(10, 65), Pair(33, 48), Pair(13, 53), Pair(29, 45), Pair(13, 53), Pair(9, 59), Pair(16, 38), Pair(10, 53),
        Pair(11, 60), Pair(45, 51), Pair(-6, 63), Pair(51, 39), Pair(17, 56), Pair(7, 68), Pair(32, 19), Pair(-3, 73),
        Pair(16, 54), Pair(8, 63), Pair(21, 52), Pair(40, 41), Pair(17, 55), Pair(15, 54), Pair(0, 0), Pair(-40, 53),
        Pair(12, 61), Pair(15, 49), Pair(-6, 64), Pair(16, 52), Pair(19, 44), Pair(8, 55), Pair(6, 26), Pair(-18, 63),
        Pair(4, 58), Pair(20, 57), Pair(13, 48), Pair(9, 59), Pair(21, 49), Pair(12, 44), Pair(27, -6), Pair(-6, 60),
        Pair(20, 48), Pair(24, 49), Pair(23, 42), Pair(25, 42), Pair(18, 48), Pair(15, 48), Pair(31, -1), Pair(8, 42)
      },
      { // Piece 4
        Pair(22, 83), Pair(71, 55), Pair(3, 93), Pair(50, 98), Pair(2, 97), Pair(84, 87), Pair(86, 37), Pair(12, 99),
        Pair(-5, 104), Pair(8, 89), Pair(34, 94), Pair(35, 67), Pair(21, 100), Pair(56, 35), Pair(5, 37), Pair(45, 47),
        Pair(-1, 108), Pair(0, 99), Pair(19, 55), Pair(25, 62), Pair(30, 50), Pair(27, 44), Pair(15, 46), Pair(11, 69),
        Pair(15, 72), Pair(-3, 96), Pair(26, 92), Pair(55, 34), Pair(-7, 83), Pair(-1, 55), Pair(2, 72), Pair(21, 24),
        Pair(26, 59), Pair(24, 69), Pair(9, 91), Pair(25, 64), Pair(21, 85), Pair(-3, 90), Pair(0, 0), Pair(4, 68),
        Pair(19, 85), Pair(22, 76), Pair(27, 83), Pair(21, 78), Pair(24, 83), Pair(25, 65), Pair(7, 82), Pair(16, 31),
        Pair(28, 88), Pair(15, 88), Pair(29, 72), Pair(31, 80), Pair(30, 59), Pair(14, 68), Pair(6, 54), Pair(9, 121),
        Pair(35, 78), Pair(9, 125), Pair(13, 86), Pair(18, 107), Pair(23, 92), Pair(32, 39), Pair(31, -33), Pair(-16, 94)
      },
      { // Piece 5
        Pair(-37, 12), Pair(-89, 93), Pair(-93, -2), Pair(-22, 14), Pair(-82, 31), Pair(103, 36), Pair(37, 53), Pair(111, 246),
        Pair(-123, 22), Pair(32, 5), Pair(22, 21), Pair(-37, 41), Pair(-3, 68), Pair(44, 59), Pair(269, 50), Pair(29, 106),
        Pair(-91, 12), Pair(-154, 27), Pair(-118, 25), Pair(-46, 43), Pair(15, 32), Pair(150, 44), Pair(78, 50), Pair(41, 45),
        Pair(-77, 15), Pair(-46, 9), Pair(4, 14), Pair(-52, 36), Pair(-45, 40), Pair(-6, 16), Pair(36, 19), Pair(-94, 28),
        Pair(-34, -1), Pair(-12, 12), Pair(-89, 27), Pair(-29, 26), Pair(-16, 29), Pair(-1, 15), Pair(0, 0), Pair(12, 14),
        Pair(-58, -16), Pair(-37, 5), Pair(-4, 2), Pair(-58, 22), Pair(-6, 12), Pair(-10, 7), Pair(18, 1), Pair(-9, 3),
        Pair(-38, -5), Pair(-26, -6), Pair(-28, 2), Pair(-54, 10), Pair(-10, 3), Pair(-13, 11), Pair(7, -5), Pair(-23, 8),
        Pair(8, -67), Pair(-18, -13), Pair(-31, -13), Pair(-24, -12), Pair(-8, -4), Pair(24, -33), Pair(8, -16), Pair(-2, -31)
      }
    }},
    {{ // Bucket 39
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(17, 8), Pair(5, 24), Pair(14, 6), Pair(-12, 12), Pair(-21, 14), Pair(-31, 14), Pair(5, 8), Pair(34, 4),
        Pair(-5, 16), Pair(-15, 25), Pair(-3, 14), Pair(6, 9), Pair(-3, 14), Pair(-1, 9), Pair(-15, 23), Pair(22, -6),
        Pair(-3, 15), Pair(-1, 12), Pair(-1, 12), Pair(2, 9), Pair(-2, 8), Pair(3, 5), Pair(5, 4), Pair(12, -9),
        Pair(-4, 17), Pair(-1, 17), Pair(-1, 14), Pair(2, 13), Pair(2, 10), Pair(-2, 2), Pair(10, -8), Pair(15, -2),
        Pair(-2, 18), Pair(-1, 17), Pair(3, 16), Pair(0, 15), Pair(7, 12), Pair(7, 7), Pair(13, 4), Pair(6, 4),
        Pair(-2, 18), Pair(-1, 15), Pair(-3, 13), Pair(0, 10), Pair(0, 11), Pair(4, 11), Pair(3, 14), Pair(10, 5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(131, 4), Pair(231, -3), Pair(-65, 45), Pair(-5, 39), Pair(48, 37), Pair(64, 20), Pair(192, 20), Pair(39, 9),
        Pair(23, 29), Pair(-8, 49), Pair(2, 43), Pair(62, 27), Pair(66, 23), Pair(-2, 29), Pair(-28, 48), Pair(-20, 32),
        Pair(-15, 49), Pair(3, 45), Pair(20, 36), Pair(23, 37), Pair(12, 34), Pair(9, 29), Pair(43, 15), Pair(-3, 32),
        Pair(-14, 36), Pair(12, 39), Pair(2, 41), Pair(28, 34), Pair(14, 35), Pair(14, 27), Pair(18, 20), Pair(1, 33),
        Pair(5, 45), Pair(23, 34), Pair(12, 38), Pair(13, 34), Pair(11, 40), Pair(14, 36), Pair(12, 18), Pair(0, 0),
        Pair(3, 33), Pair(15, 34), Pair(3, 43), Pair(5, 48), Pair(10, 46), Pair(5, 33), Pair(8, 38), Pair(6, 56),
        Pair(-2, 56), Pair(2, 17), Pair(2, 35), Pair(2, 44), Pair(8, 33), Pair(-2, 42), Pair(-6, 35), Pair(-1, 37),
        Pair(-21, 82), Pair(-8, 34), Pair(-2, 45), Pair(-7, 54), Pair(5, 30), Pair(-5, 30), Pair(6, 27), Pair(-24, 2)
      },
      { // Piece 2
        Pair(68, 3), Pair(60, -5), Pair(0, 7), Pair(77, -10), Pair(134, -6), Pair(-94, 35), Pair(-71, 26), Pair(-9, 16),
        Pair(31, -2), Pair(43, 7), Pair(5, 1), Pair(61, -7), Pair(18, -3), Pair(-1, 9), Pair(-8, 29), Pair(2, 22),
        Pair(12, 24), Pair(17, 18), Pair(27, 12), Pair(24, -1), Pair(41, 14), Pair(8, 6), Pair(22, 20), Pair(1, 15),
        Pair(1, 21), Pair(18, 16), Pair(18, 9), Pair(18, 21), Pair(12, 17), Pair(8, 27), Pair(-3, 48), Pair(8, 16),
        Pair(35, 7), Pair(-7, 20), Pair(23, 18), Pair(13, 18), Pair(11, 30), Pair(8, 28), Pair(12, 26), Pair(0, 0),
        Pair(-1, 21), Pair(20, 21), Pair(11, 21), Pair(13, 28), Pair(17, 25), Pair(8, 30), Pair(16, 24), Pair(14, 44),
        Pair(17, 9), Pair(9, 29), Pair(14, 28), Pair(7, 28), Pair(9, 41), Pair(8, 22), Pair(10, 27), Pair(21, 14),
        Pair(19, 16), Pair(16, 13), Pair(7, 20), Pair(17, 29), Pair(12, 18), Pair(1, 31), Pair(19, 23), Pair(21, 32)
      },
      { // Piece 3
        Pair(23, 41), Pair(45, 36), Pair(57, 36), Pair(6, 46), Pair(72, 33), Pair(58, 29), Pair(44, 36), Pair(72, -2),
        Pair(17, 54), Pair(16, 47), Pair(33, 43), Pair(3, 52), Pair(38, 36), Pair(26, 43), Pair(-53, 62), Pair(44, 10),
        Pair(2, 63), Pair(18, 48), Pair(24, 49), Pair(22, 43), Pair(7, 51), Pair(16, 59), Pair(-34, 60), Pair(18, 25),
        Pair(-3, 56), Pair(14, 54), Pair(22, 46), Pair(29, 47), Pair(12, 48), Pair(8, 55), Pair(12, 60), Pair(16, 4),
        Pair(21, 44), Pair(7, 44), Pair(15, 49), Pair(18, 48), Pair(21, 44), Pair(2, 57), Pair(9, 63), Pair(0, 0),
        Pair(28, 43), Pair(-1, 52), Pair(24, 34), Pair(-6, 51), Pair(10, 44), Pair(-2, 50), Pair(-10, 50), Pair(-46, 28),
        Pair(-2, 56), Pair(1, 54), Pair(5, 46), Pair(12, 46), Pair(4, 58), Pair(-1, 56), Pair(4, 44), Pair(-35, 1),
        Pair(10, 39), Pair(11, 45), Pair(10, 43), Pair(16, 37), Pair(13, 43), Pair(12, 46), Pair(-6, 51), Pair(-14, 0)
      },
      { // Piece 4
        Pair(40, 50), Pair(64, 32), Pair(52, 12), Pair(48, 39), Pair(84, 41), Pair(6, 68), Pair(13, 68), Pair(41, 52),
        Pair(27, 51), Pair(7, 63), Pair(21, 51), Pair(44, 18), Pair(12, 48), Pair(-10, 101), Pair(40, 23), Pair(11, 1),
        Pair(26, 62), Pair(27, 53), Pair(22, 64), Pair(52, 33), Pair(12, 67), Pair(25, 18), Pair(34, 28), Pair(-14, 75),
        Pair(10, 68), Pair(35, 21), Pair(9, 83), Pair(15, 63), Pair(8, 65), Pair(13, 61), Pair(28, 57), Pair(-7, 33),
        Pair(14, 74), Pair(17, 72), Pair(6, 87), Pair(9, 67), Pair(5, 73), Pair(7, 73), Pair(9, 53), Pair(0, 0),
        Pair(28, 84), Pair(30, 51), Pair(18, 62), Pair(15, 83), Pair(16, 63), Pair(16, 62), Pair(23, 34), Pair(11, 30),
        Pair(26, 67), Pair(17, 65), Pair(21, 71), Pair(20, 78), Pair(16, 68), Pair(12, 62), Pair(7, 73), Pair(-5, 32),
        Pair(38, 46), Pair(6, 119), Pair(14, 97), Pair(18, 88), Pair(25, 55), Pair(16, 66), Pair(-26, 67), Pair(10, -20)
      },
      { // Piece 5
        Pair(-25, -15), Pair(-99, 44), Pair(-46, 23), Pair(-165, 30), Pair(-56, 35), Pair(-43, 87), Pair(-111, 114), Pair(57, 28),
        Pair(-1, -4), Pair(-4, 31), Pair(-173, 19), Pair(-27, 33), Pair(-75, 36), Pair(-151, 81), Pair(-86, 86), Pair(-75, 67),
        Pair(41, 6), Pair(-59, 14), Pair(-107, 21), Pair(-96, 34), Pair(-33, 46), Pair(-1, 38), Pair(3, 52), Pair(32, 31),
        Pair(-47, 6), Pair(-68, 20), Pair(-89, 26), Pair(-69, 35), Pair(-89, 37), Pair(-31, 33), Pair(-23, 17), Pair(-56, 17),
        Pair(-39, -9), Pair(-98, 19), Pair(-73, 20), Pair(-69, 32), Pair(-50, 23), Pair(-9, 19), Pair(-48, 1), Pair(0, 0),
        Pair(-149, 26), Pair(-81, 19), Pair(-87, 24), Pair(-67, 16), Pair(-19, 10), Pair(-1, 2), Pair(-16, -17), Pair(-17, -21),
        Pair(-67, -4), Pair(-66, 13), Pair(-39, 2), Pair(-37, 11), Pair(-16, -1), Pair(-13, -1), Pair(1, -7), Pair(-1, -22),
        Pair(-59, -4), Pair(-35, -2), Pair(-37, 3), Pair(-29, -6), Pair(-13, -8), Pair(-4, -14), Pair(16, -13), Pair(4, -27)
      }
    }},
    {{ // Bucket 40
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-4, 41), Pair(-19, 32), Pair(22, 13), Pair(2, 15), Pair(-2, 11), Pair(-22, 19), Pair(8, 2), Pair(-1, 25),
        Pair(-6, 32), Pair(-8, 23), Pair(-7, 20), Pair(-5, 12), Pair(2, 10), Pair(3, 8), Pair(-12, 7), Pair(0, 17),
        Pair(2, 14), Pair(1, 19), Pair(-1, 13), Pair(-1, 13), Pair(1, 14), Pair(5, 14), Pair(-2, 16), Pair(-3, 15),
        Pair(-1, 10), Pair(9, 9), Pair(1, 10), Pair(0, 10), Pair(2, 9), Pair(3, 15), Pair(-2, 17), Pair(-4, 16),
        Pair(-2, 10), Pair(0, 4), Pair(-4, 13), Pair(3, 18), Pair(-3, 17), Pair(2, 13), Pair(-1, 17), Pair(-6, 21),
        Pair(3, 0), Pair(5, 24), Pair(-6, 14), Pair(2, 14), Pair(-4, 19), Pair(0, 25), Pair(-3, 23), Pair(-4, 25),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(72, 12), Pair(-96, 48), Pair(14, 67), Pair(-84, 63), Pair(-53, 75), Pair(13, 37), Pair(3, 68), Pair(-70, 111),
        Pair(-9, 57), Pair(-3, 47), Pair(-13, 68), Pair(-8, 64), Pair(-6, 67), Pair(-16, 87), Pair(-15, 58), Pair(-22, 52),
        Pair(37, 22), Pair(3, 57), Pair(5, 61), Pair(-16, 71), Pair(6, 59), Pair(-31, 79), Pair(-27, 81), Pair(-11, 44),
        Pair(-2, 61), Pair(9, 57), Pair(5, 60), Pair(0, 66), Pair(-2, 73), Pair(1, 64), Pair(-5, 60), Pair(-20, 78),
        Pair(-4, 50), Pair(14, 56), Pair(4, 66), Pair(4, 62), Pair(-6, 69), Pair(5, 70), Pair(-10, 61), Pair(0, 49),
        Pair(0, 0), Pair(-1, 68), Pair(2, 60), Pair(3, 61), Pair(10, 71), Pair(3, 60), Pair(1, 68), Pair(3, 61),
        Pair(11, 76), Pair(5, 70), Pair(-4, 56), Pair(-1, 70), Pair(1, 69), Pair(-7, 74), Pair(10, 56), Pair(-1, 47),
        Pair(63, 18), Pair(-7, 58), Pair(3, 50), Pair(0, 65), Pair(-8, 74), Pair(4, 56), Pair(5, 51), Pair(61, -4)
      },
      { // Piece 2
        Pair(31, 59), Pair(25, 41), Pair(-48, 74), Pair(35, 25), Pair(13, 42), Pair(40, 8), Pair(-35, 44), Pair(-4, 15),
        Pair(14, 45), Pair(13, 56), Pair(2, 45), Pair(53, 23), Pair(4, 16), Pair(0, 47), Pair(10, 28), Pair(-5, 39),
        Pair(2, 41), Pair(14, 39), Pair(17, 53), Pair(18, 26), Pair(23, 43), Pair(-10, 28), Pair(6, 42), Pair(-11, 47),
        Pair(-3, 55), Pair(14, 59), Pair(17, 26), Pair(13, 51), Pair(2, 37), Pair(13, 46), Pair(7, 44), Pair(3, 59),
        Pair(5, 48), Pair(34, 48), Pair(10, 48), Pair(13, 33), Pair(5, 55), Pair(2, 47), Pair(10, 54), Pair(1, 38),
        Pair(0, 0), Pair(8, 50), Pair(9, 47), Pair(6, 59), Pair(6, 52), Pair(9, 60), Pair(9, 34), Pair(12, 46),
        Pair(28, 35), Pair(6, 42), Pair(4, 58), Pair(2, 53), Pair(8, 65), Pair(6, 52), Pair(6, 62), Pair(11, 58),
        Pair(12, 37), Pair(-9, 54), Pair(-3, 44), Pair(8, 66), Pair(6, 49), Pair(-1, 70), Pair(1, 35), Pair(-3, 62)
      },
      { // Piece 3
        Pair(-38, 81), Pair(-18, 99), Pair(-43, 108), Pair(-24, 99), Pair(-32, 109), Pair(3, 87), Pair(19, 93), Pair(-15, 101),
        Pair(-46, 81), Pair(-25, 102), Pair(-9, 97), Pair(-14, 93), Pair(-20, 93), Pair(-36, 102), Pair(-3, 74), Pair(-7, 95),
        Pair(-23, 79), Pair(-4, 92), Pair(-15, 102), Pair(0, 81), Pair(-13, 95), Pair(-22, 105), Pair(-16, 99), Pair(-11, 101),
        Pair(-54, 98), Pair(-6, 100), Pair(-1, 96), Pair(-7, 95), Pair(-8, 89), Pair(-11, 111), Pair(-12, 99), Pair(0, 84),
        Pair(-33, 89), Pair(-4, 106), Pair(-14, 110), Pair(-3, 98), Pair(-5, 96), Pair(-17, 90), Pair(-14, 111), Pair(-8, 103),
        Pair(0, 0), Pair(-8, 101), Pair(12, 96), Pair(-1, 93), Pair(-2, 90), Pair(-2, 93), Pair(-13, 103), Pair(5, 87),
        Pair(-43, 80), Pair(-1, 97), Pair(-12, 100), Pair(-4, 100), Pair(-10, 98), Pair(-10, 93), Pair(-3, 86), Pair(-14, 84),
        Pair(-29, 63), Pair(-10, 97), Pair(-8, 97), Pair(-7, 97), Pair(-5, 94), Pair(-8, 89), Pair(2, 86), Pair(0, 84)
      },
      { // Piece 4
        Pair(12, 133), Pair(22, 168), Pair(-23, 185), Pair(-65, 210), Pair(-31, 189), Pair(-18, 159), Pair(-11, 199), Pair(-30, 223),
        Pair(-22, 173), Pair(-3, 171), Pair(22, 143), Pair(25, 158), Pair(24, 151), Pair(-20, 171), Pair(24, 156), Pair(33, 125),
        Pair(-22, 194), Pair(8, 151), Pair(6, 174), Pair(2, 182), Pair(2, 150), Pair(-2, 171), Pair(11, 158), Pair(-20, 192),
        Pair(14, 148), Pair(10, 189), Pair(10, 164), Pair(-1, 173), Pair(33, 120), Pair(-4, 164), Pair(-2, 182), Pair(14, 148),
        Pair(-9, 164), Pair(27, 170), Pair(7, 186), Pair(17, 168), Pair(7, 177), Pair(8, 167), Pair(1, 170), Pair(14, 162),
        Pair(0, 0), Pair(17, 158), Pair(17, 167), Pair(12, 175), Pair(9, 196), Pair(11, 180), Pair(16, 171), Pair(26, 113),
        Pair(6, 138), Pair(13, 188), Pair(16, 173), Pair(15, 177), Pair(9, 182), Pair(20, 168), Pair(21, 158), Pair(16, 150),
        Pair(0, 150), Pair(7, 181), Pair(10, 186), Pair(12, 184), Pair(15, 164), Pair(13, 181), Pair(-4, 174), Pair(37, 109)
      },
      { // Piece 5
        Pair(-53, 101), Pair(91, 60), Pair(-32, 61), Pair(24, -20), Pair(-86, 91), Pair(-125, 76), Pair(112, -24), Pair(-110, -88),
        Pair(-157, 69), Pair(-108, 88), Pair(81, 41), Pair(-16, 52), Pair(-5, -3), Pair(-84, 15), Pair(11, 5), Pair(-98, 10),
        Pair(-46, 43), Pair(-12, 57), Pair(5, 45), Pair(-36, 65), Pair(-227, 73), Pair(67, -7), Pair(-50, 21), Pair(-71, 11),
        Pair(-78, 38), Pair(59, 27), Pair(1, 30), Pair(-47, 48), Pair(-81, 44), Pair(-50, 29), Pair(-59, 25), Pair(-40, 17),
        Pair(-31, 9), Pair(-69, 20), Pair(-57, 42), Pair(-52, 41), Pair(-61, 32), Pair(-2, 14), Pair(-13, 13), Pair(-33, 5),
        Pair(0, 0), Pair(8, 16), Pair(21, 19), Pair(-5, 25), Pair(-19, 20), Pair(-28, 17), Pair(-10, 7), Pair(-49, 1),
        Pair(29, -47), Pair(28, -16), Pair(5, 10), Pair(12, 11), Pair(-5, 11), Pair(-17, 17), Pair(-13, 6), Pair(-18, -1),
        Pair(62, -57), Pair(94, -15), Pair(63, -7), Pair(10, -8), Pair(2, -5), Pair(-7, 4), Pair(-8, 0), Pair(-6, -12)
      }
    }},
    {{ // Bucket 41
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-15, 27), Pair(-30, 15), Pair(-52, 24), Pair(-4, 7), Pair(-15, 21), Pair(10, 2), Pair(19, 12), Pair(-21, 17),
        Pair(-6, 19), Pair(5, 14), Pair(-9, 22), Pair(0, 10), Pair(-5, 13), Pair(4, 14), Pair(-13, 9), Pair(-1, 6),
        Pair(-6, 16), Pair(9, 8), Pair(0, 13), Pair(3, 13), Pair(2, 8), Pair(6, 10), Pair(1, 14), Pair(2, 11),
        Pair(0, 6), Pair(-3, -7), Pair(3, 6), Pair(7, 9), Pair(1, 11), Pair(7, 16), Pair(3, 17), Pair(-1, 15),
        Pair(3, 3), Pair(-8, 3), Pair(1, 11), Pair(-3, 14), Pair(2, 16), Pair(3, 15), Pair(3, 16), Pair(-2, 16),
        Pair(0, 20), Pair(2, -7), Pair(9, 30), Pair(3, 10), Pair(0, 17), Pair(-3, 20), Pair(4, 21), Pair(-2, 21),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-65, 101), Pair(-153, 93), Pair(16, 83), Pair(-17, 60), Pair(-55, 61), Pair(-58, 61), Pair(-161, 91), Pair(-59, 124),
        Pair(-9, 52), Pair(-12, 58), Pair(-14, 66), Pair(-15, 68), Pair(-44, 80), Pair(-33, 76), Pair(-45, 82), Pair(-67, 94),
        Pair(-36, 58), Pair(-13, 62), Pair(-11, 70), Pair(-17, 70), Pair(-18, 75), Pair(-18, 62), Pair(-29, 80), Pair(-41, 64),
        Pair(-26, 70), Pair(-6, 57), Pair(-1, 58), Pair(-11, 73), Pair(-10, 74), Pair(-13, 72), Pair(-19, 73), Pair(-15, 80),
        Pair(5, 51), Pair(-9, 61), Pair(-5, 56), Pair(-5, 67), Pair(-14, 73), Pair(-5, 74), Pair(-15, 67), Pair(-10, 69),
        Pair(-8, 70), Pair(0, 0), Pair(-3, 72), Pair(5, 67), Pair(-2, 69), Pair(-3, 67), Pair(-10, 74), Pair(6, 69),
        Pair(-16, 89), Pair(13, 88), Pair(2, 76), Pair(-9, 60), Pair(-5, 79), Pair(-4, 87), Pair(-5, 83), Pair(-6, 68),
        Pair(67, -37), Pair(-7, 51), Pair(-8, 74), Pair(-4, 79), Pair(-1, 76), Pair(-1, 63), Pair(2, 47), Pair(16, -18)
      },
      { // Piece 2
        Pair(61, 20), Pair(-97, 83), Pair(-2, 36), Pair(56, 46), Pair(41, 9), Pair(-1, 42), Pair(-53, 28), Pair(-5, 37),
        Pair(-16, 53), Pair(-16, 41), Pair(-9, 62), Pair(10, 23), Pair(24, 41), Pair(4, 33), Pair(-18, 47), Pair(-11, 45),
        Pair(-20, 45), Pair(6, 57), Pair(17, 19), Pair(2, 52), Pair(6, 25), Pair(0, 34), Pair(8, 29), Pair(-26, 59),
        Pair(-10, 59), Pair(-4, 30), Pair(1, 48), Pair(-7, 33), Pair(1, 38), Pair(4, 31), Pair(-6, 50), Pair(-11, 55),
        Pair(-60, -19), Pair(5, 52), Pair(-5, 46), Pair(3, 46), Pair(-6, 43), Pair(-4, 62), Pair(0, 48), Pair(7, 46),
        Pair(-1, 51), Pair(0, 0), Pair(3, 50), Pair(-6, 50), Pair(-2, 68), Pair(-1, 46), Pair(0, 70), Pair(-4, 50),
        Pair(-64, -10), Pair(4, 71), Pair(-12, 39), Pair(-1, 69), Pair(-6, 56), Pair(10, 61), Pair(-6, 55), Pair(-5, 83),
        Pair(3, 23), Pair(-6, 48), Pair(-5, 53), Pair(-8, 43), Pair(7, 49), Pair(-7, 61), Pair(6, 66), Pair(11, 26)
      },
      { // Piece 3
        Pair(-27, 90), Pair(-9, 78), Pair(-16, 81), Pair(-17, 76), Pair(-3, 85), Pair(20, 86), Pair(5, 87), Pair(-13, 80),
        Pair(-29, 86), Pair(-40, 81), Pair(-26, 91), Pair(3, 80), Pair(-4, 86), Pair(-16, 94), Pair(-68, 118), Pair(-14, 81),
        Pair(-23, 89), Pair(-47, 93), Pair(-24, 95), Pair(-23, 92), Pair(-17, 81), Pair(-55, 111), Pair(4, 66), Pair(-37, 89),
        Pair(-13, 87), Pair(-27, 95), Pair(-19, 85), Pair(-21, 89), Pair(-10, 81), Pair(-12, 89), Pair(-5, 79), Pair(-30, 96),
        Pair(-22, 100), Pair(-48, 86), Pair(1, 96), Pair(-14, 99), Pair(-19, 91), Pair(-13, 82), Pair(-19, 91), Pair(-23, 89),
        Pair(-10, 49), Pair(0, 0), Pair(-15, 93), Pair(-3, 90), Pair(-9, 89), Pair(-28, 99), Pair(-19, 86), Pair(-24, 82),
        Pair(-11, 67), Pair(-26, 50), Pair(-9, 85), Pair(2, 83), Pair(-11, 91), Pair(-12, 87), Pair(-12, 99), Pair(-13, 93),
        Pair(-15, 78), Pair(-26, 53), Pair(-15, 87), Pair(-8, 82), Pair(-12, 84), Pair(-12, 84), Pair(-13, 92), Pair(-8, 81)
      },
      { // Piece 4
        Pair(-17, 149), Pair(-29, 138), Pair(-32, 149), Pair(-8, 106), Pair(-29, 147), Pair(-35, 149), Pair(-7, 115), Pair(-25, 140),
        Pair(0, 113), Pair(-12, 123), Pair(5, 117), Pair(-13, 120), Pair(-36, 145), Pair(-9, 128), Pair(6, 104), Pair(-33, 168),
        Pair(-16, 152), Pair(-15, 117), Pair(-12, 147), Pair(-9, 126), Pair(-20, 122), Pair(-22, 145), Pair(-2, 115), Pair(-16, 143),
        Pair(-8, 131), Pair(-12, 131), Pair(-3, 149), Pair(-13, 141), Pair(1, 112), Pair(-4, 117), Pair(-4, 112), Pair(-6, 117),
        Pair(-13, 158), Pair(-16, 137), Pair(-3, 151), Pair(-4, 139), Pair(-4, 133), Pair(-7, 139), Pair(-3, 119), Pair(-12, 144),
        Pair(3, 68), Pair(0, 0), Pair(1, 136), Pair(-3, 154), Pair(7, 141), Pair(4, 146), Pair(-8, 141), Pair(13, 114),
        Pair(-15, 139), Pair(3, 115), Pair(5, 127), Pair(9, 139), Pair(8, 147), Pair(8, 137), Pair(16, 127), Pair(-1, 161),
        Pair(5, 109), Pair(14, 98), Pair(6, 128), Pair(5, 130), Pair(4, 162), Pair(20, 124), Pair(6, 152), Pair(69, 103)
      },
      { // Piece 5
        Pair(98, 45), Pair(20, 42), Pair(40, 83), Pair(-11, -32), Pair(100, -31), Pair(-35, -1), Pair(-61, -54), Pair(-33, 31),
        Pair(96, 12), Pair(113, 68), Pair(-62, 62), Pair(175, 35), Pair(27, 50), Pair(21, 19), Pair(-51, 10), Pair(-126, 36),
        Pair(-66, 62), Pair(48, 30), Pair(17, 55), Pair(58, 39), Pair(-132, 50), Pair(-62, 30), Pair(61, -10), Pair(-102, 5),
        Pair(21, 72), Pair(84, 22), Pair(77, 35), Pair(90, 23), Pair(-60, 42), Pair(-84, 27), Pair(17, 4), Pair(-87, 13),
        Pair(37, 12), Pair(24, 12), Pair(2, 16), Pair(-45, 38), Pair(-47, 38), Pair(-64, 28), Pair(4, 7), Pair(-52, 9),
        Pair(-10, 36), Pair(0, 0), Pair(-21, 32), Pair(-22, 29), Pair(4, 20), Pair(-12, 13), Pair(-23, 13), Pair(-49, 13),
        Pair(58, -9), Pair(20, -9), Pair(-10, 15), Pair(-6, 16), Pair(8, 10), Pair(-20, 14), Pair(-12, 7), Pair(-10, -3),
        Pair(74, -39), Pair(60, -19), Pair(53, -1), Pair(-3, 13), Pair(1, 5), Pair(-15, 8), Pair(-6, -2), Pair(-9, -8)
      }
    }},
    {{ // Bucket 42
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(11, 17), Pair(-44, 17), Pair(-48, 9), Pair(34, -1), Pair(-3, 12), Pair(-9, -7), Pair(1, 6), Pair(10, 18),
        Pair(-6, 13), Pair(-5, 22), Pair(-8, -3), Pair(-5, 14), Pair(3, 11), Pair(8, 9), Pair(6, 7), Pair(3, 10),
        Pair(-3, 16), Pair(-2, 14), Pair(1, -6), Pair(-5, 19), Pair(8, 11), Pair(8, 7), Pair(0, 10), Pair(1, 10),
        Pair(0, 14), Pair(7, 15), Pair(-9, -23), Pair(8, 22), Pair(4, 9), Pair(6, 8), Pair(3, 16), Pair(-2, 14),
        Pair(-5, 10), Pair(2, 15), Pair(-8, -3), Pair(1, 22), Pair(-8, 10), Pair(4, 11), Pair(3, 16), Pair(0, 16),
        Pair(-3, 12), Pair(11, 33), Pair(-8, -26), Pair(2, 29), Pair(-7, 17), Pair(0, 17), Pair(-1, 19), Pair(3, 17),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(42, 10), Pair(-141, 78), Pair(-47, 59), Pair(2, 66), Pair(22, 59), Pair(-20, 56), Pair(32, -6), Pair(24, 6),
        Pair(-5, 60), Pair(15, 68), Pair(-2, 43), Pair(-10, 50), Pair(-34, 56), Pair(6, 62), Pair(-6, 72), Pair(-60, 85),
        Pair(14, 54), Pair(10, 56), Pair(1, 63), Pair(12, 50), Pair(-24, 66), Pair(-7, 69), Pair(-3, 60), Pair(27, 47),
        Pair(-9, 74), Pair(-2, 49), Pair(4, 57), Pair(18, 57), Pair(3, 52), Pair(5, 64), Pair(-6, 66), Pair(9, 46),
        Pair(-8, 42), Pair(9, 55), Pair(8, 45), Pair(8, 63), Pair(2, 56), Pair(4, 65), Pair(-7, 74), Pair(3, 49),
        Pair(0, 64), Pair(4, 70), Pair(0, 0), Pair(11, 64), Pair(15, 62), Pair(6, 63), Pair(10, 46), Pair(9, 52),
        Pair(-11, 6), Pair(7, 62), Pair(9, 95), Pair(10, 71), Pair(-1, 53), Pair(4, 70), Pair(7, 74), Pair(2, 80),
        Pair(9, 57), Pair(-2, 36), Pair(13, 53), Pair(1, 65), Pair(8, 61), Pair(9, 50), Pair(5, 55), Pair(16, 62)
      },
      { // Piece 2
        Pair(24, 59), Pair(38, 14), Pair(99, 32), Pair(91, 8), Pair(35, 32), Pair(10, -6), Pair(22, 22), Pair(-48, 26),
        Pair(-10, 38), Pair(19, 30), Pair(41, 17), Pair(35, 10), Pair(-21, 22), Pair(41, 24), Pair(5, 8), Pair(22, 31),
        Pair(16, 49), Pair(30, 10), Pair(33, 30), Pair(18, 15), Pair(10, 29), Pair(6, 4), Pair(22, 28), Pair(-2, 20),
        Pair(-4, 22), Pair(15, 32), Pair(-3, 22), Pair(17, 42), Pair(5, 8), Pair(14, 22), Pair(1, 25), Pair(16, 45),
        Pair(31, 20), Pair(7, 12), Pair(11, 40), Pair(37, 20), Pair(8, 34), Pair(8, 31), Pair(21, 54), Pair(7, 22),
        Pair(4, 14), Pair(18, 36), Pair(0, 0), Pair(18, 40), Pair(4, 34), Pair(20, 47), Pair(16, 31), Pair(16, 41),
        Pair(29, 0), Pair(-19, -36), Pair(25, 68), Pair(-1, 21), Pair(16, 54), Pair(9, 29), Pair(16, 60), Pair(9, 57),
        Pair(-30, -109), Pair(22, 12), Pair(0, 23), Pair(20, 46), Pair(-4, 8), Pair(14, 61), Pair(17, 43), Pair(21, 73)
      },
      { // Piece 3
        Pair(-25, 85), Pair(-23, 83), Pair(-18, 71), Pair(-18, 69), Pair(7, 76), Pair(33, 59), Pair(7, 65), Pair(-12, 82),
        Pair(-2, 75), Pair(-1, 74), Pair(-30, 67), Pair(-13, 79), Pair(-7, 78), Pair(-20, 82), Pair(-16, 85), Pair(6, 67),
        Pair(-14, 87), Pair(-17, 80), Pair(8, 65), Pair(-15, 76), Pair(-6, 78), Pair(-25, 80), Pair(1, 71), Pair(-5, 69),
        Pair(0, 85), Pair(9, 68), Pair(6, 65), Pair(-13, 73), Pair(0, 68), Pair(-7, 84), Pair(1, 58), Pair(-7, 80),
        Pair(2, 82), Pair(5, 61), Pair(-19, 71), Pair(6, 91), Pair(-3, 81), Pair(-2, 67), Pair(2, 68), Pair(-12, 87),
        Pair(3, 47), Pair(-10, 57), Pair(0, 0), Pair(3, 63), Pair(13, 62), Pair(3, 60), Pair(-4, 72), Pair(1, 63),
        Pair(-6, 85), Pair(-5, 68), Pair(-19, 53), Pair(0, 81), Pair(11, 72), Pair(6, 62), Pair(0, 91), Pair(-12, 82),
        Pair(1, 75), Pair(1, 71), Pair(-5, 39), Pair(-1, 74), Pair(5, 75), Pair(2, 65), Pair(4, 77), Pair(7, 73)
      },
      { // Piece 4
        Pair(-12, 137), Pair(-46, 167), Pair(-50, 131), Pair(-54, 175), Pair(-39, 136), Pair(26, 119), Pair(63, 129), Pair(15, 112),
        Pair(1, 97), Pair(7, 107), Pair(-16, 111), Pair(-9, 101), Pair(18, 103), Pair(10, 103), Pair(10, 68), Pair(4, 95),
        Pair(-4, 124), Pair(-5, 134), Pair(-21, 152), Pair(-5, 113), Pair(-43, 173), Pair(-17, 144), Pair(9, 116), Pair(-20, 141),
        Pair(-4, 88), Pair(5, 101), Pair(26, 70), Pair(-9, 140), Pair(-10, 108), Pair(-3, 95), Pair(-16, 161), Pair(4, 104),
        Pair(-5, 152), Pair(16, 91), Pair(3, 120), Pair(7, 116), Pair(-4, 126), Pair(0, 133), Pair(6, 111), Pair(-5, 111),
        Pair(-4, 92), Pair(9, 75), Pair(0, 0), Pair(8, 128), Pair(12, 122), Pair(2, 140), Pair(1, 154), Pair(5, 160),
        Pair(24, 75), Pair(5, 96), Pair(4, 107), Pair(11, 124), Pair(8, 139), Pair(13, 114), Pair(6, 124), Pair(4, 141),
        Pair(20, 79), Pair(8, 110), Pair(6, 102), Pair(7, 135), Pair(13, 103), Pair(22, 113), Pair(21, 99), Pair(33, 61)
      },
      { // Piece 5
        Pair(-78, -47), Pair(46, 148), Pair(-104, 94), Pair(-277, -10), Pair(83, 90), Pair(-14, 15), Pair(10, -85), Pair(81, -77),
        Pair(103, 19), Pair(81, 83), Pair(45, 40), Pair(-25, 86), Pair(-8, 107), Pair(-37, 22), Pair(47, 30), Pair(122, -61),
        Pair(-123, 83), Pair(-7, 49), Pair(-55, 62), Pair(-70, 35), Pair(48, 22), Pair(-144, 47), Pair(91, -19), Pair(11, -7),
        Pair(85, 5), Pair(-92, 57), Pair(28, 28), Pair(63, 37), Pair(24, 17), Pair(-80, 28), Pair(-34, 6), Pair(-83, 2),
        Pair(29, 15), Pair(-70, 3), Pair(-11, 3), Pair(-16, 1), Pair(-37, 23), Pair(-36, 10), Pair(-8, 2), Pair(-51, 12),
        Pair(9, 33), Pair(17, 12), Pair(0, 0), Pair(3, 18), Pair(-6, 10), Pair(-7, -3), Pair(-7, 0), Pair(4, -14),
        Pair(56, -17), Pair(10, 7), Pair(-14, 5), Pair(-15, 8), Pair(1, 0), Pair(5, -5), Pair(-3, -9), Pair(0, -15),
        Pair(47, -7), Pair(-11, -9), Pair(5, -15), Pair(-5, 8), Pair(8, -1), Pair(0, -15), Pair(4, -20), Pair(0, -28)
      }
    }},
    {{ // Bucket 43
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-4, 9), Pair(-26, 17), Pair(-5, 8), Pair(-30, 17), Pair(2, 16), Pair(18, -9), Pair(30, -29), Pair(14, -6),
        Pair(-4, 14), Pair(-4, 8), Pair(-1, 18), Pair(1, 0), Pair(-8, 18), Pair(-5, 12), Pair(-9, 8), Pair(-5, 1),
        Pair(1, 9), Pair(3, 16), Pair(-4, 22), Pair(12, 5), Pair(3, 17), Pair(5, 15), Pair(-3, 11), Pair(-3, 10),
        Pair(-1, 11), Pair(-2, 16), Pair(5, 20), Pair(8, -6), Pair(10, 13), Pair(3, 11), Pair(1, 13), Pair(-3, 11),
        Pair(-3, 14), Pair(-4, 13), Pair(0, 23), Pair(2, -12), Pair(2, 23), Pair(-11, 11), Pair(1, 15), Pair(-3, 12),
        Pair(-2, 13), Pair(-8, 6), Pair(8, 36), Pair(-5, -10), Pair(8, 43), Pair(-7, 19), Pair(-3, 11), Pair(1, 17),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(42, 5), Pair(39, 40), Pair(20, 56), Pair(-98, 97), Pair(30, 36), Pair(-3, 37), Pair(-64, 92), Pair(-92, 71),
        Pair(4, 42), Pair(-6, 62), Pair(-5, 47), Pair(-22, 80), Pair(-65, 79), Pair(-37, 84), Pair(-73, 95), Pair(35, 16),
        Pair(-22, 51), Pair(-18, 46), Pair(-1, 58), Pair(-38, 64), Pair(-36, 72), Pair(-36, 62), Pair(-21, 82), Pair(-29, 65),
        Pair(-7, 51), Pair(-11, 44), Pair(-7, 32), Pair(-28, 62), Pair(-9, 49), Pair(-12, 66), Pair(-20, 69), Pair(-22, 58),
        Pair(-7, 35), Pair(-20, 41), Pair(-8, 60), Pair(-6, 54), Pair(6, 60), Pair(-14, 56), Pair(-20, 55), Pair(-12, 55),
        Pair(-3, 41), Pair(-1, 53), Pair(-9, 59), Pair(0, 0), Pair(-3, 45), Pair(1, 60), Pair(-17, 70), Pair(0, 34),
        Pair(15, 13), Pair(-17, 22), Pair(-4, 68), Pair(-2, 89), Pair(2, 60), Pair(-13, 31), Pair(-2, 54), Pair(-4, 47),
        Pair(22, 63), Pair(-9, 52), Pair(-20, 40), Pair(4, 49), Pair(-7, 44), Pair(-18, 62), Pair(2, 62), Pair(-28, 93)
      },
      { // Piece 2
        Pair(-46, 29), Pair(77, 30), Pair(30, 25), Pair(-13, 50), Pair(73, -20), Pair(-29, 10), Pair(5, -25), Pair(-74, 53),
        Pair(27, 14), Pair(-2, 35), Pair(8, 23), Pair(37, 0), Pair(40, 19), Pair(3, 17), Pair(-35, 53), Pair(-43, -5),
        Pair(-6, -2), Pair(9, 25), Pair(-9, 26), Pair(2, 33), Pair(-48, 37), Pair(-20, 48), Pair(24, -9), Pair(-22, 53),
        Pair(10, 28), Pair(-28, 14), Pair(3, 22), Pair(-22, 29), Pair(-4, 34), Pair(-15, 12), Pair(-3, 34), Pair(-13, 25),
        Pair(0, 8), Pair(10, 34), Pair(-20, 25), Pair(-5, 30), Pair(29, 31), Pair(-1, 34), Pair(-6, 18), Pair(-11, 54),
        Pair(2, 44), Pair(-9, 12), Pair(4, 39), Pair(0, 0), Pair(-5, 50), Pair(-4, 22), Pair(-7, 50), Pair(-7, 23),
        Pair(2, 26), Pair(-9, 49), Pair(-27, -24), Pair(9, 60), Pair(-6, -5), Pair(-2, 37), Pair(-7, 28), Pair(0, 41),
        Pair(-2, 40), Pair(-54, -38), Pair(-4, 42), Pair(-2, 13), Pair(-4, 49), Pair(-15, -15), Pair(7, 33), Pair(2, 16)
      },
      { // Piece 3
        Pair(-9, 65), Pair(10, 53), Pair(-10, 68), Pair(59, 29), Pair(-7, 62), Pair(-46, 64), Pair(-55, 81), Pair(31, 53),
        Pair(-14, 60), Pair(-14, 66), Pair(-37, 68), Pair(-10, 56), Pair(-20, 72), Pair(9, 44), Pair(2, 39), Pair(-21, 56),
        Pair(-18, 75), Pair(-12, 62), Pair(-16, 63), Pair(-14, 47), Pair(-25, 71), Pair(-26, 65), Pair(-18, 63), Pair(-15, 60),
        Pair(-12, 66), Pair(-7, 71), Pair(-19, 62), Pair(9, 44), Pair(-13, 56), Pair(2, 67), Pair(-8, 50), Pair(-11, 60),
        Pair(4, 54), Pair(-13, 67), Pair(-3, 66), Pair(3, 54), Pair(-5, 71), Pair(-11, 69), Pair(1, 69), Pair(-10, 52),
        Pair(4, 35), Pair(-13, 50), Pair(-19, 57), Pair(0, 0), Pair(-8, 44), Pair(-3, 39), Pair(-16, 55), Pair(-10, 46),
        Pair(-19, 58), Pair(-5, 62), Pair(-8, 45), Pair(-17, 42), Pair(-3, 53), Pair(-10, 52), Pair(-15, 55), Pair(13, 41),
        Pair(-6, 50), Pair(-2, 60), Pair(-14, 62), Pair(-2, 17), Pair(-11, 58), Pair(-7, 56), Pair(-8, 59), Pair(-1, 46)
      },
      { // Piece 4
        Pair(-13, 90), Pair(26, 77), Pair(-48, 118), Pair(-29, 95), Pair(-47, 112), Pair(35, 75), Pair(55, 37), Pair(-12, 92),
        Pair(-9, 89), Pair(-15, 111), Pair(12, 73), Pair(-10, 100), Pair(-15, 112), Pair(-3, 82), Pair(-34, 111), Pair(-36, 96),
        Pair(-26, 110), Pair(-14, 104), Pair(-6, 118), Pair(-23, 70), Pair(-23, 97), Pair(-12, 100), Pair(-38, 154), Pair(-24, 107),
        Pair(-14, 105), Pair(-21, 121), Pair(4, 69), Pair(-7, 68), Pair(-16, 96), Pair(-16, 95), Pair(-13, 95), Pair(-6, 91),
        Pair(1, 73), Pair(-1, 94), Pair(-10, 87), Pair(2, 76), Pair(12, 90), Pair(-12, 107), Pair(-9, 99), Pair(-6, 114),
        Pair(-16, 85), Pair(4, 56), Pair(-11, 98), Pair(0, 0), Pair(-4, 110), Pair(1, 92), Pair(0, 78), Pair(-1, 95),
        Pair(-7, 86), Pair(6, 75), Pair(0, 71), Pair(6, 76), Pair(-3, 98), Pair(9, 93), Pair(5, 121), Pair(4, 123),
        Pair(5, 76), Pair(6, 50), Pair(0, 87), Pair(4, 65), Pair(1, 104), Pair(7, 89), Pair(19, 119), Pair(8, 105)
      },
      { // Piece 5
        Pair(-10, -29), Pair(56, 173), Pair(11, -3), Pair(51, 84), Pair(49, -10), Pair(6, -17), Pair(46, -33), Pair(4, -66),
        Pair(51, 99), Pair(-110, 80), Pair(-63, 65), Pair(-59, 118), Pair(-68, 35), Pair(76, 69), Pair(127, -15), Pair(-129, -7),
        Pair(-60, 31), Pair(56, 31), Pair(-75, 66), Pair(-157, 103), Pair(139, 14), Pair(124, -4), Pair(-84, 17), Pair(-20, 5),
        Pair(-162, 45), Pair(60, -7), Pair(-113, 57), Pair(-32, 36), Pair(-24, 11), Pair(33, -2), Pair(-100, 12), Pair(-31, -16),
        Pair(95, -32), Pair(-18, 21), Pair(-7, -18), Pair(12, -1), Pair(-7, -28), Pair(14, -13), Pair(-2, -5), Pair(21, -17),
        Pair(10, -2), Pair(49, -10), Pair(-66, 32), Pair(0, 0), Pair(-35, 17), Pair(-3, -11), Pair(-4, -14), Pair(2, -20),
        Pair(-18, -15), Pair(-10, -8), Pair(-48, -3), Pair(-44, 15), Pair(-37, -9), Pair(3, -25), Pair(-1, -17), Pair(-1, -17),
        Pair(-7, -46), Pair(-18, -7), Pair(-39, -2), Pair(-42, 8), Pair(-16, -10), Pair(12, -28), Pair(0, -25), Pair(4, -28)
      }
    }},
    {{ // Bucket 44
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-14, 15), Pair(-10, 16), Pair(19, 6), Pair(-15, 9), Pair(8, -12), Pair(-29, 12), Pair(1, 5), Pair(0, 4),
        Pair(-3, 13), Pair(-7, 11), Pair(7, 5), Pair(-2, 12), Pair(3, 7), Pair(-7, 14), Pair(-8, 13), Pair(-3, 4),
        Pair(0, 12), Pair(0, 9), Pair(2, 14), Pair(0, 19), Pair(7, 7), Pair(1, 14), Pair(3, 13), Pair(4, 5),
        Pair(-2, 21), Pair(0, 17), Pair(1, 13), Pair(11, 24), Pair(2, -5), Pair(16, 9), Pair(1, 15), Pair(1, 6),
        Pair(0, 16), Pair(-1, 17), Pair(-8, 9), Pair(3, 28), Pair(2, -15), Pair(13, 13), Pair(-4, 9), Pair(6, 13),
        Pair(-4, 18), Pair(-3, 14), Pair(-2, 15), Pair(16, 37), Pair(5, -15), Pair(19, 34), Pair(1, 9), Pair(7, 12),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(33, 1), Pair(85, -11), Pair(-24, 53), Pair(-26, 51), Pair(23, 41), Pair(-105, 55), Pair(194, -69), Pair(30, 44),
        Pair(10, 27), Pair(-16, 68), Pair(-10, 49), Pair(-6, 52), Pair(-17, 52), Pair(-20, 50), Pair(-11, 51), Pair(-30, 3),
        Pair(9, 44), Pair(-10, 58), Pair(10, 50), Pair(-21, 67), Pair(-41, 67), Pair(-16, 42), Pair(-45, 52), Pair(-25, 41),
        Pair(-6, 52), Pair(-7, 55), Pair(-8, 55), Pair(-15, 50), Pair(-21, 49), Pair(-24, 47), Pair(-20, 47), Pair(-18, 55),
        Pair(-4, 64), Pair(7, 38), Pair(-6, 40), Pair(5, 61), Pair(-14, 51), Pair(-10, 46), Pair(-27, 41), Pair(-18, 37),
        Pair(-2, 34), Pair(-1, 64), Pair(-2, 54), Pair(1, 49), Pair(0, 0), Pair(-9, 56), Pair(-5, 59), Pair(-7, 42),
        Pair(5, 62), Pair(-4, 49), Pair(-14, 32), Pair(2, 59), Pair(-1, 84), Pair(5, 59), Pair(-21, 12), Pair(-16, 70),
        Pair(24, 37), Pair(3, 55), Pair(-3, 55), Pair(-1, 40), Pair(-10, 61), Pair(-11, 44), Pair(-1, 32), Pair(-33, 14)
      },
      { // Piece 2
        Pair(-6, 23), Pair(78, -30), Pair(53, 9), Pair(49, -14), Pair(37, 19), Pair(31, 27), Pair(95, -5), Pair(-44, 2),
        Pair(-29, 21), Pair(6, 18), Pair(-15, 13), Pair(51, 3), Pair(-7, 12), Pair(-27, 30), Pair(-28, 13), Pair(2, 19),
        Pair(11, 23), Pair(0, -1), Pair(6, 22), Pair(-17, 11), Pair(0, 29), Pair(-44, 15), Pair(8, 19), Pair(-51, 1),
        Pair(-9, 23), Pair(5, 26), Pair(-26, 21), Pair(0, 25), Pair(-31, 23), Pair(3, 22), Pair(-29, 8), Pair(-11, 37),
        Pair(5, 21), Pair(-7, 21), Pair(-5, 27), Pair(13, 14), Pair(-9, 42), Pair(-29, 8), Pair(9, 31), Pair(-22, 16),
        Pair(-18, 27), Pair(-1, 34), Pair(-15, 30), Pair(-3, 44), Pair(0, 0), Pair(2, 37), Pair(-15, 15), Pair(-4, 43),
        Pair(7, 25), Pair(-23, 28), Pair(-5, 45), Pair(-28, 1), Pair(10, 58), Pair(-36, -8), Pair(-4, 49), Pair(-17, 24),
        Pair(-15, 34), Pair(-6, 36), Pair(-37, -6), Pair(5, 40), Pair(-7, 16), Pair(-1, 35), Pair(-61, -25), Pair(0, 36)
      },
      { // Piece 3
        Pair(5, 51), Pair(-7, 57), Pair(-44, 66), Pair(-32, 59), Pair(-39, 54), Pair(-51, 61), Pair(-11, 58), Pair(11, 54),
        Pair(-11, 60), Pair(-21, 64), Pair(-12, 60), Pair(-14, 58), Pair(2, 46), Pair(-36, 58), Pair(-43, 61), Pair(-33, 64),
        Pair(-13, 64), Pair(6, 50), Pair(-15, 61), Pair(-12, 57), Pair(-25, 52), Pair(-76, 82), Pair(-17, 61), Pair(-10, 64),
        Pair(-8, 61), Pair(10, 50), Pair(6, 50), Pair(-6, 48), Pair(17, 45), Pair(-8, 41), Pair(-5, 50), Pair(-13, 51),
        Pair(2, 47), Pair(-13, 64), Pair(-1, 58), Pair(11, 53), Pair(-17, 42), Pair(0, 48), Pair(-18, 57), Pair(-12, 69),
        Pair(-4, 49), Pair(-3, 45), Pair(-12, 52), Pair(-16, 49), Pair(0, 0), Pair(-30, 47), Pair(-22, 36), Pair(-23, 43),
        Pair(3, 52), Pair(-13, 57), Pair(-5, 56), Pair(-3, 55), Pair(-15, 29), Pair(-6, 37), Pair(-14, 60), Pair(6, 49),
        Pair(-3, 53), Pair(-3, 54), Pair(-3, 53), Pair(-6, 53), Pair(-8, 15), Pair(-14, 55), Pair(-4, 50), Pair(-1, 50)
      },
      { // Piece 4
        Pair(2, 123), Pair(-53, 140), Pair(-14, 105), Pair(0, 106), Pair(34, 63), Pair(22, 89), Pair(-83, 153), Pair(-106, 134),
        Pair(-16, 105), Pair(-17, 117), Pair(-21, 98), Pair(18, 74), Pair(0, 82), Pair(-29, 117), Pair(-1, 77), Pair(-45, 120),
        Pair(-4, 107), Pair(-6, 94), Pair(-11, 126), Pair(-8, 98), Pair(-19, 81), Pair(-39, 100), Pair(-16, 101), Pair(-42, 94),
        Pair(0, 101), Pair(5, 80), Pair(-8, 81), Pair(-19, 108), Pair(-7, 82), Pair(-11, 86), Pair(-27, 107), Pair(-14, 83),
        Pair(0, 125), Pair(4, 80), Pair(-7, 89), Pair(-3, 91), Pair(-6, 91), Pair(-20, 93), Pair(-5, 68), Pair(-20, 102),
        Pair(15, 79), Pair(8, 84), Pair(8, 64), Pair(1, 81), Pair(0, 0), Pair(-7, 90), Pair(-15, 92), Pair(-21, 103),
        Pair(4, 107), Pair(13, 77), Pair(5, 95), Pair(1, 85), Pair(4, 84), Pair(-5, 90), Pair(15, 75), Pair(-19, 149),
        Pair(9, 101), Pair(13, 93), Pair(-5, 94), Pair(1, 100), Pair(1, 78), Pair(9, 100), Pair(-49, 158), Pair(-5, 111)
      },
      { // Piece 5
        Pair(114, 17), Pair(-86, 20), Pair(-9, 128), Pair(30, 76), Pair(-73, -1), Pair(-62, 66), Pair(-39, 54), Pair(39, -16),
        Pair(-43, 16), Pair(-134, 51), Pair(-164, 46), Pair(-81, 92), Pair(67, 30), Pair(-11, 31), Pair(-90, 37), Pair(-74, 32),
        Pair(-51, 5), Pair(-10, -4), Pair(-61, 42), Pair(130, 25), Pair(-42, 68), Pair(-28, 46), Pair(-122, 38), Pair(106, -5),
        Pair(6, 18), Pair(-75, 15), Pair(59, 11), Pair(-25, 36), Pair(-80, 44), Pair(-27, 29), Pair(-16, 3), Pair(-85, 21),
        Pair(51, -29), Pair(-78, 17), Pair(-3, 9), Pair(-30, 1), Pair(-28, 6), Pair(13, -23), Pair(39, -8), Pair(-21, -4),
        Pair(-42, 16), Pair(-9, 6), Pair(-1, 5), Pair(-65, 27), Pair(0, 0), Pair(-32, 2), Pair(16, -8), Pair(20, -13),
        Pair(9, -13), Pair(-10, -11), Pair(-5, -8), Pair(-38, 8), Pair(-36, 19), Pair(-24, -1), Pair(6, -16), Pair(10, -15),
        Pair(-10, -19), Pair(-6, -17), Pair(-2, -9), Pair(-9, -4), Pair(-25, 10), Pair(-29, 0), Pair(4, -16), Pair(3, -22)
      }
    }},
    {{ // Bucket 45
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(19, 3), Pair(-37, 15), Pair(-11, 5), Pair(4, 3), Pair(-16, 31), Pair(-2, -15), Pair(13, 15), Pair(4, 7),
        Pair(4, 17), Pair(-4, 17), Pair(11, 13), Pair(8, 7), Pair(-3, 14), Pair(-6, 8), Pair(-7, 17), Pair(-9, 11),
        Pair(4, 14), Pair(7, 13), Pair(4, 10), Pair(4, 13), Pair(-3, 15), Pair(10, 5), Pair(5, 10), Pair(6, 7),
        Pair(1, 16), Pair(6, 13), Pair(3, 11), Pair(7, 12), Pair(21, 11), Pair(0, -6), Pair(20, 4), Pair(7, 3),
        Pair(2, 12), Pair(5, 15), Pair(2, 13), Pair(-10, 12), Pair(14, 15), Pair(3, -6), Pair(16, 6), Pair(-3, 7),
        Pair(3, 17), Pair(3, 17), Pair(0, 14), Pair(-6, 14), Pair(10, 27), Pair(4, -7), Pair(15, 23), Pair(-2, 8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(53, 37), Pair(20, 17), Pair(-13, 57), Pair(89, 59), Pair(37, 45), Pair(20, 41), Pair(15, 60), Pair(-106, 50),
        Pair(20, 44), Pair(23, 43), Pair(17, 49), Pair(28, 32), Pair(33, 39), Pair(15, 33), Pair(58, 54), Pair(-21, 44),
        Pair(34, 50), Pair(20, 45), Pair(44, 40), Pair(26, 49), Pair(11, 56), Pair(-14, 55), Pair(13, 59), Pair(-56, 59),
        Pair(10, 52), Pair(30, 50), Pair(32, 50), Pair(22, 55), Pair(30, 34), Pair(5, 51), Pair(6, 44), Pair(3, 56),
        Pair(19, 71), Pair(39, 47), Pair(27, 54), Pair(33, 42), Pair(37, 49), Pair(12, 54), Pair(10, 46), Pair(-9, 29),
        Pair(26, 50), Pair(27, 51), Pair(25, 53), Pair(31, 54), Pair(27, 46), Pair(0, 0), Pair(8, 55), Pair(6, 53),
        Pair(23, 56), Pair(20, 55), Pair(22, 55), Pair(14, 47), Pair(23, 56), Pair(25, 70), Pair(23, 66), Pair(-5, 19),
        Pair(-29, 63), Pair(8, 53), Pair(19, 54), Pair(22, 63), Pair(18, 47), Pair(10, 39), Pair(2, 28), Pair(48, -4)
      },
      { // Piece 2
        Pair(-24, 13), Pair(-13, 26), Pair(-35, 32), Pair(88, 9), Pair(40, 10), Pair(102, 24), Pair(52, 21), Pair(27, 29),
        Pair(33, 13), Pair(15, 1), Pair(46, 12), Pair(73, -12), Pair(47, 27), Pair(-25, 38), Pair(71, 27), Pair(41, 19),
        Pair(15, 21), Pair(45, 22), Pair(31, 9), Pair(48, 11), Pair(5, 7), Pair(38, 11), Pair(25, 3), Pair(17, 25),
        Pair(34, 40), Pair(31, 14), Pair(29, 18), Pair(17, 11), Pair(39, 33), Pair(25, 15), Pair(24, 29), Pair(-51, 23),
        Pair(18, 32), Pair(32, 35), Pair(14, 18), Pair(35, 26), Pair(61, 22), Pair(21, 28), Pair(-1, 44), Pair(17, 41),
        Pair(27, 47), Pair(14, 32), Pair(38, 36), Pair(14, 30), Pair(29, 43), Pair(0, 0), Pair(25, 36), Pair(12, 29),
        Pair(26, 20), Pair(29, 40), Pair(19, 23), Pair(25, 46), Pair(19, 14), Pair(44, 45), Pair(-12, -13), Pair(40, 33),
        Pair(28, 35), Pair(1, 25), Pair(25, 55), Pair(-2, 31), Pair(58, 35), Pair(15, 25), Pair(52, -13), Pair(-24, -93)
      },
      { // Piece 3
        Pair(39, 48), Pair(41, 46), Pair(62, 40), Pair(54, 41), Pair(10, 65), Pair(46, 42), Pair(35, 51), Pair(113, 27),
        Pair(36, 53), Pair(30, 57), Pair(41, 48), Pair(65, 39), Pair(14, 60), Pair(56, 32), Pair(19, 55), Pair(24, 49),
        Pair(26, 58), Pair(44, 51), Pair(31, 57), Pair(31, 59), Pair(22, 50), Pair(22, 58), Pair(20, 45), Pair(39, 59),
        Pair(45, 48), Pair(39, 54), Pair(29, 45), Pair(44, 52), Pair(44, 46), Pair(67, 36), Pair(22, 49), Pair(40, 47),
        Pair(34, 60), Pair(22, 61), Pair(32, 55), Pair(40, 61), Pair(35, 65), Pair(13, 43), Pair(23, 72), Pair(32, 58),
        Pair(41, 50), Pair(15, 52), Pair(38, 51), Pair(25, 48), Pair(19, 58), Pair(0, 0), Pair(18, 47), Pair(-9, 34),
        Pair(25, 59), Pair(43, 43), Pair(35, 54), Pair(30, 59), Pair(30, 56), Pair(21, 34), Pair(17, 61), Pair(-8, 63),
        Pair(30, 53), Pair(33, 55), Pair(33, 54), Pair(37, 51), Pair(25, 55), Pair(22, 31), Pair(14, 66), Pair(27, 46)
      },
      { // Piece 4
        Pair(16, 100), Pair(50, 100), Pair(44, 80), Pair(-23, 145), Pair(32, 95), Pair(-40, 152), Pair(17, 96), Pair(7, 123),
        Pair(-3, 123), Pair(15, 93), Pair(9, 116), Pair(34, 106), Pair(-15, 135), Pair(34, 49), Pair(8, 108), Pair(-14, 110),
        Pair(12, 111), Pair(19, 110), Pair(22, 93), Pair(11, 112), Pair(5, 110), Pair(-23, 134), Pair(15, 97), Pair(-8, 116),
        Pair(-4, 130), Pair(-9, 150), Pair(7, 129), Pair(15, 101), Pair(-7, 134), Pair(11, 70), Pair(11, 95), Pair(-36, 115),
        Pair(36, 113), Pair(14, 126), Pair(28, 86), Pair(5, 129), Pair(44, 88), Pair(-3, 123), Pair(1, 104), Pair(-18, 115),
        Pair(10, 135), Pair(22, 122), Pair(27, 110), Pair(21, 98), Pair(18, 108), Pair(0, 0), Pair(1, 80), Pair(5, 49),
        Pair(-2, 138), Pair(25, 117), Pair(25, 105), Pair(26, 104), Pair(24, 95), Pair(13, 85), Pair(14, 103), Pair(11, 111),
        Pair(8, 127), Pair(19, 152), Pair(25, 120), Pair(21, 112), Pair(25, 106), Pair(49, 50), Pair(53, 101), Pair(-15, 63)
      },
      { // Piece 5
        Pair(-17, -49), Pair(-85, -48), Pair(238, 33), Pair(74, 43), Pair(72, 14), Pair(154, 8), Pair(-69, 53), Pair(82, -34),
        Pair(-6, -1), Pair(-105, 39), Pair(125, -8), Pair(192, 21), Pair(73, 57), Pair(59, 40), Pair(62, 29), Pair(-266, 48),
        Pair(-32, -15), Pair(-67, 14), Pair(-58, 19), Pair(-174, 56), Pair(179, 5), Pair(-10, 52), Pair(-32, 55), Pair(108, 1),
        Pair(-94, 12), Pair(-48, 13), Pair(-71, 21), Pair(-67, 33), Pair(-108, 46), Pair(-31, 26), Pair(-17, 29), Pair(-1, -1),
        Pair(-151, 24), Pair(-4, -4), Pair(-33, 8), Pair(-71, 25), Pair(-39, -7), Pair(13, -10), Pair(21, -22), Pair(74, -4),
        Pair(-79, 0), Pair(-59, 13), Pair(-8, 11), Pair(-19, 11), Pair(8, 3), Pair(0, 0), Pair(16, -15), Pair(35, -4),
        Pair(-33, -9), Pair(-6, 1), Pair(13, 2), Pair(-6, -4), Pair(-6, 3), Pair(-50, 16), Pair(-1, -2), Pair(27, -12),
        Pair(-10, -10), Pair(-4, -18), Pair(-9, -9), Pair(-11, -7), Pair(-12, 7), Pair(-27, 6), Pair(-4, 3), Pair(32, -20)
      }
    }},
    {{ // Bucket 46
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-15, 19), Pair(5, 7), Pair(7, 4), Pair(-4, 5), Pair(10, 8), Pair(-35, 20), Pair(7, -17), Pair(12, 12),
        Pair(-3, 19), Pair(5, 18), Pair(4, 16), Pair(-5, 14), Pair(3, 11), Pair(-2, 11), Pair(0, -5), Pair(3, 16),
        Pair(0, 15), Pair(3, 11), Pair(0, 13), Pair(4, 6), Pair(3, 13), Pair(-9, 11), Pair(10, -5), Pair(5, 12),
        Pair(0, 16), Pair(2, 20), Pair(3, 16), Pair(3, 11), Pair(9, 16), Pair(16, 8), Pair(10, -15), Pair(12, -2),
        Pair(-1, 21), Pair(2, 21), Pair(2, 16), Pair(2, 15), Pair(-1, 12), Pair(17, 7), Pair(-1, 3), Pair(3, 7),
        Pair(-2, 18), Pair(2, 24), Pair(-1, 18), Pair(2, 12), Pair(2, 15), Pair(19, 24), Pair(-6, -12), Pair(5, 25),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(46, 29), Pair(27, 40), Pair(84, 48), Pair(131, 11), Pair(-13, 45), Pair(82, 27), Pair(33, 67), Pair(83, -27),
        Pair(-9, 68), Pair(18, 46), Pair(17, 53), Pair(-8, 65), Pair(-11, 58), Pair(8, 41), Pair(36, 29), Pair(8, 45),
        Pair(1, 55), Pair(-1, 65), Pair(1, 59), Pair(-1, 55), Pair(2, 53), Pair(-14, 57), Pair(-8, 42), Pair(-16, 49),
        Pair(-2, 63), Pair(12, 56), Pair(9, 59), Pair(7, 58), Pair(0, 61), Pair(-4, 45), Pair(6, 41), Pair(-26, 59),
        Pair(10, 56), Pair(6, 59), Pair(6, 63), Pair(8, 59), Pair(7, 46), Pair(3, 47), Pair(2, 49), Pair(5, 29),
        Pair(5, 59), Pair(10, 60), Pair(8, 62), Pair(17, 54), Pair(8, 51), Pair(6, 55), Pair(0, 0), Pair(-5, 51),
        Pair(-9, 57), Pair(-2, 57), Pair(10, 59), Pair(7, 63), Pair(-6, 47), Pair(14, 42), Pair(0, 79), Pair(-8, 51),
        Pair(-11, 89), Pair(0, 53), Pair(11, 38), Pair(1, 74), Pair(1, 51), Pair(-7, 46), Pair(7, 42), Pair(-77, 71)
      },
      { // Piece 2
        Pair(-21, 32), Pair(-17, 30), Pair(31, 25), Pair(104, -1), Pair(54, 28), Pair(87, 11), Pair(56, 23), Pair(4, 25),
        Pair(-1, 23), Pair(15, 38), Pair(-15, 23), Pair(87, 2), Pair(35, 5), Pair(39, 34), Pair(15, 24), Pair(-11, 63),
        Pair(18, 34), Pair(26, 16), Pair(33, 28), Pair(-2, 27), Pair(17, 29), Pair(-10, 27), Pair(21, 40), Pair(-13, 22),
        Pair(4, 35), Pair(26, 39), Pair(15, 22), Pair(17, 37), Pair(-14, 31), Pair(3, 38), Pair(3, 15), Pair(5, 41),
        Pair(20, 32), Pair(10, 32), Pair(16, 41), Pair(8, 29), Pair(14, 46), Pair(-12, 23), Pair(10, 44), Pair(-44, -12),
        Pair(7, 30), Pair(9, 40), Pair(1, 34), Pair(10, 53), Pair(2, 37), Pair(14, 38), Pair(0, 0), Pair(10, 42),
        Pair(-4, 49), Pair(1, 33), Pair(8, 41), Pair(3, 38), Pair(10, 55), Pair(17, 13), Pair(20, 65), Pair(-71, -80),
        Pair(16, 32), Pair(7, 49), Pair(0, 38), Pair(0, 61), Pair(3, 37), Pair(16, 41), Pair(32, 7), Pair(18, 25)
      },
      { // Piece 3
        Pair(7, 70), Pair(19, 62), Pair(64, 49), Pair(29, 56), Pair(-4, 79), Pair(10, 64), Pair(44, 36), Pair(18, 67),
        Pair(29, 63), Pair(12, 71), Pair(16, 65), Pair(37, 62), Pair(26, 67), Pair(21, 66), Pair(73, 36), Pair(-6, 74),
        Pair(20, 70), Pair(38, 56), Pair(19, 69), Pair(18, 62), Pair(12, 69), Pair(-4, 70), Pair(91, 30), Pair(7, 70),
        Pair(19, 64), Pair(28, 61), Pair(15, 65), Pair(28, 55), Pair(23, 66), Pair(-9, 72), Pair(15, 59), Pair(-2, 74),
        Pair(16, 70), Pair(11, 74), Pair(11, 66), Pair(26, 62), Pair(13, 69), Pair(20, 79), Pair(22, 35), Pair(2, 82),
        Pair(14, 75), Pair(10, 59), Pair(0, 75), Pair(3, 66), Pair(18, 61), Pair(-13, 83), Pair(0, 0), Pair(-14, 29),
        Pair(19, 69), Pair(32, 64), Pair(11, 73), Pair(14, 74), Pair(18, 67), Pair(4, 62), Pair(12, 16), Pair(-24, 70),
        Pair(17, 63), Pair(23, 58), Pair(22, 58), Pair(18, 59), Pair(15, 67), Pair(11, 61), Pair(2, 25), Pair(-4, 58)
      },
      { // Piece 4
        Pair(31, 113), Pair(27, 68), Pair(-5, 123), Pair(14, 96), Pair(32, 93), Pair(-24, 116), Pair(78, 47), Pair(30, 90),
        Pair(10, 118), Pair(10, 120), Pair(12, 99), Pair(18, 110), Pair(35, 86), Pair(39, 85), Pair(40, 58), Pair(7, 112),
        Pair(18, 125), Pair(30, 98), Pair(13, 108), Pair(11, 98), Pair(-9, 121), Pair(43, 68), Pair(13, 113), Pair(-2, 95),
        Pair(14, 119), Pair(11, 125), Pair(7, 118), Pair(20, 106), Pair(14, 92), Pair(-16, 109), Pair(-2, 98), Pair(-6, 83),
        Pair(23, 129), Pair(22, 97), Pair(16, 118), Pair(10, 107), Pair(5, 108), Pair(-3, 99), Pair(7, 92), Pair(-11, 89),
        Pair(37, 86), Pair(28, 118), Pair(20, 120), Pair(19, 106), Pair(21, 105), Pair(10, 115), Pair(0, 0), Pair(-7, 55),
        Pair(32, 130), Pair(26, 121), Pair(24, 128), Pair(25, 114), Pair(24, 115), Pair(14, 88), Pair(4, 88), Pair(-17, 70),
        Pair(24, 126), Pair(32, 121), Pair(20, 131), Pair(21, 132), Pair(13, 129), Pair(4, 142), Pair(20, 79), Pair(-14, 112)
      },
      { // Piece 5
        Pair(-61, 57), Pair(27, -40), Pair(-68, 0), Pair(-23, 29), Pair(-146, 42), Pair(-170, 35), Pair(-49, 65), Pair(-182, 68),
        Pair(-129, -23), Pair(-113, 64), Pair(-64, 12), Pair(-133, 51), Pair(-119, 69), Pair(-166, 75), Pair(-59, 80), Pair(-59, 50),
        Pair(-145, 24), Pair(14, 3), Pair(-53, 11), Pair(-49, 37), Pair(-58, 45), Pair(-15, 56), Pair(45, 53), Pair(-84, 49),
        Pair(-44, 12), Pair(-145, 28), Pair(-108, 32), Pair(-58, 32), Pair(-70, 42), Pair(-9, 40), Pair(2, 45), Pair(26, 40),
        Pair(-43, 22), Pair(-55, 30), Pair(-29, 21), Pair(-39, 30), Pair(-5, 21), Pair(-41, 5), Pair(9, 14), Pair(-9, -8),
        Pair(-65, -2), Pair(-81, 27), Pair(-31, 24), Pair(-25, 18), Pair(0, 18), Pair(-15, 4), Pair(0, 0), Pair(35, -20),
        Pair(-51, 0), Pair(-55, 18), Pair(-45, 21), Pair(-26, 14), Pair(5, 3), Pair(-17, -1), Pair(4, -6), Pair(-9, -15),
        Pair(-68, 5), Pair(-36, 0), Pair(-36, 5), Pair(-11, -6), Pair(10, -13), Pair(-3, 1), Pair(10, -9), Pair(-23, -6)
      }
    }},
    {{ // Bucket 47
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-9, 24), Pair(-5, 26), Pair(6, 18), Pair(-7, 11), Pair(-14, 4), Pair(-13, 9), Pair(-12, 14), Pair(44, 0),
        Pair(-4, 22), Pair(-1, 22), Pair(4, 12), Pair(8, 14), Pair(-6, 14), Pair(-6, 11), Pair(-12, 20), Pair(0, -4),
        Pair(-2, 16), Pair(0, 15), Pair(1, 13), Pair(3, 8), Pair(0, 9), Pair(-3, 9), Pair(-4, 17), Pair(22, 3),
        Pair(-4, 16), Pair(4, 18), Pair(3, 18), Pair(1, 11), Pair(0, 8), Pair(2, 8), Pair(12, 5), Pair(3, 5),
        Pair(0, 18), Pair(1, 17), Pair(1, 12), Pair(1, 13), Pair(6, 14), Pair(2, 7), Pair(1, 6), Pair(3, -10),
        Pair(-2, 22), Pair(-2, 18), Pair(0, 17), Pair(-1, 10), Pair(6, 14), Pair(-7, 11), Pair(11, 26), Pair(-15, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(37, 17), Pair(84, 37), Pair(-59, 84), Pair(-51, 56), Pair(85, 6), Pair(11, 43), Pair(91, 12), Pair(-2, 70),
        Pair(19, 32), Pair(6, 45), Pair(4, 49), Pair(-2, 57), Pair(12, 42), Pair(1, 40), Pair(-13, 63), Pair(-23, 40),
        Pair(-2, 66), Pair(-5, 54), Pair(9, 50), Pair(14, 41), Pair(4, 49), Pair(26, 23), Pair(-11, 51), Pair(5, 52),
        Pair(-4, 53), Pair(8, 55), Pair(3, 54), Pair(9, 50), Pair(0, 45), Pair(-1, 45), Pair(4, 39), Pair(-5, 49),
        Pair(-5, 61), Pair(12, 50), Pair(8, 52), Pair(6, 49), Pair(3, 53), Pair(3, 43), Pair(-2, 46), Pair(-8, 38),
        Pair(3, 60), Pair(7, 55), Pair(3, 58), Pair(2, 60), Pair(2, 55), Pair(-2, 52), Pair(8, 39), Pair(0, 0),
        Pair(-5, 66), Pair(3, 47), Pair(2, 41), Pair(1, 56), Pair(6, 50), Pair(-10, 43), Pair(-13, 56), Pair(-9, 57),
        Pair(-50, 98), Pair(-9, 60), Pair(-6, 51), Pair(-22, 73), Pair(-1, 42), Pair(-9, 36), Pair(-1, 44), Pair(-54, 51)
      },
      { // Piece 2
        Pair(11, 6), Pair(60, 27), Pair(-9, 8), Pair(66, 24), Pair(121, 4), Pair(47, 34), Pair(-38, 44), Pair(-65, 66),
        Pair(8, 37), Pair(13, 23), Pair(9, 30), Pair(83, -19), Pair(43, 19), Pair(19, 30), Pair(16, 51), Pair(-11, 34),
        Pair(10, 28), Pair(22, 41), Pair(16, 19), Pair(6, 27), Pair(2, 19), Pair(13, 30), Pair(14, 29), Pair(6, 36),
        Pair(16, 35), Pair(13, 22), Pair(12, 39), Pair(10, 22), Pair(7, 47), Pair(17, 17), Pair(2, 46), Pair(-1, 28),
        Pair(0, 34), Pair(7, 44), Pair(18, 22), Pair(14, 40), Pair(6, 34), Pair(-4, 47), Pair(19, 60), Pair(5, 37),
        Pair(4, 51), Pair(5, 29), Pair(11, 42), Pair(6, 36), Pair(11, 53), Pair(-1, 35), Pair(5, 39), Pair(0, 0),
        Pair(16, 11), Pair(8, 50), Pair(9, 31), Pair(7, 50), Pair(-1, 47), Pair(15, 53), Pair(7, 31), Pair(12, 63),
        Pair(18, 49), Pair(1, 27), Pair(6, 48), Pair(-2, 35), Pair(21, 47), Pair(1, 39), Pair(37, 36), Pair(13, -2)
      },
      { // Piece 3
        Pair(23, 67), Pair(17, 70), Pair(44, 57), Pair(9, 71), Pair(7, 72), Pair(65, 53), Pair(56, 62), Pair(55, 26),
        Pair(15, 80), Pair(7, 81), Pair(36, 69), Pair(16, 78), Pair(26, 66), Pair(25, 70), Pair(1, 85), Pair(101, 18),
        Pair(8, 83), Pair(19, 73), Pair(24, 78), Pair(34, 68), Pair(19, 71), Pair(45, 67), Pair(13, 71), Pair(26, 40),
        Pair(15, 76), Pair(26, 75), Pair(20, 70), Pair(27, 69), Pair(23, 59), Pair(19, 81), Pair(0, 78), Pair(6, 52),
        Pair(9, 79), Pair(6, 79), Pair(4, 84), Pair(32, 64), Pair(14, 81), Pair(7, 69), Pair(-4, 101), Pair(13, 41),
        Pair(24, 69), Pair(2, 74), Pair(24, 65), Pair(12, 67), Pair(7, 77), Pair(8, 66), Pair(6, 74), Pair(0, 0),
        Pair(8, 85), Pair(10, 81), Pair(13, 80), Pair(4, 83), Pair(6, 84), Pair(-2, 83), Pair(21, 50), Pair(-59, 47),
        Pair(14, 69), Pair(16, 67), Pair(15, 65), Pair(19, 65), Pair(18, 68), Pair(17, 71), Pair(-7, 68), Pair(-16, 20)
      },
      { // Piece 4
        Pair(37, 96), Pair(19, 110), Pair(48, 88), Pair(55, 93), Pair(26, 127), Pair(8, 134), Pair(0, 122), Pair(32, 126),
        Pair(16, 128), Pair(14, 121), Pair(20, 111), Pair(16, 102), Pair(11, 119), Pair(15, 134), Pair(22, 104), Pair(-20, 146),
        Pair(24, 119), Pair(9, 131), Pair(31, 113), Pair(36, 102), Pair(35, 95), Pair(30, 107), Pair(4, 162), Pair(12, 113),
        Pair(20, 99), Pair(31, 107), Pair(33, 115), Pair(17, 104), Pair(1, 139), Pair(18, 113), Pair(28, 116), Pair(9, 101),
        Pair(26, 118), Pair(16, 138), Pair(19, 117), Pair(20, 114), Pair(6, 136), Pair(5, 111), Pair(14, 107), Pair(-6, 109),
        Pair(34, 116), Pair(31, 122), Pair(19, 136), Pair(22, 116), Pair(19, 126), Pair(16, 125), Pair(10, 130), Pair(0, 0),
        Pair(29, 138), Pair(14, 138), Pair(23, 130), Pair(20, 127), Pair(21, 119), Pair(23, 106), Pair(24, 116), Pair(-35, 92),
        Pair(34, 119), Pair(14, 142), Pair(23, 131), Pair(24, 137), Pair(21, 126), Pair(39, 106), Pair(-9, 134), Pair(-3, 44)
      },
      { // Piece 5
        Pair(22, -39), Pair(-172, -8), Pair(145, 11), Pair(-12, -38), Pair(-113, 38), Pair(-36, 118), Pair(-98, 85), Pair(-79, 21),
        Pair(1, -3), Pair(-11, 17), Pair(-62, 32), Pair(5, 46), Pair(-154, 72), Pair(79, 62), Pair(31, 63), Pair(-275, 74),
        Pair(-21, 0), Pair(-16, 32), Pair(-56, 26), Pair(-18, 25), Pair(-58, 38), Pair(-93, 70), Pair(-66, 66), Pair(-34, 58),
        Pair(-100, 35), Pair(-47, 19), Pair(-107, 38), Pair(-131, 47), Pair(-158, 51), Pair(-1, 33), Pair(22, 29), Pair(-30, 42),
        Pair(7, -8), Pair(-85, 34), Pair(-134, 43), Pair(-80, 36), Pair(-15, 26), Pair(-8, 21), Pair(-20, -8), Pair(-19, 5),
        Pair(-96, 16), Pair(-70, 26), Pair(-74, 29), Pair(-27, 20), Pair(-9, 13), Pair(-10, 13), Pair(-44, -13), Pair(0, 0),
        Pair(-59, 6), Pair(-62, 23), Pair(-34, 25), Pair(-37, 20), Pair(0, 3), Pair(-19, 7), Pair(-27, -18), Pair(-11, -29),
        Pair(-67, -9), Pair(-41, 12), Pair(-38, 12), Pair(-29, 7), Pair(5, -14), Pair(11, -11), Pair(16, -5), Pair(20, -22)
      }
    }},
    {{ // Bucket 48
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(2, 3), Pair(-11, 33), Pair(-27, 28), Pair(-8, 17), Pair(-2, 18), Pair(1, 13), Pair(-4, 17), Pair(-16, 28),
        Pair(-23, 26), Pair(-17, 26), Pair(-8, 23), Pair(-4, 16), Pair(-6, 15), Pair(3, 9), Pair(-7, 14), Pair(-10, 19),
        Pair(-2, 13), Pair(-5, 15), Pair(2, 13), Pair(-6, 17), Pair(0, 11), Pair(1, 19), Pair(-2, 13), Pair(-5, 19),
        Pair(4, 4), Pair(-2, 22), Pair(-3, 16), Pair(-2, 14), Pair(1, 11), Pair(-2, 13), Pair(0, 18), Pair(-7, 21),
        Pair(0, -3), Pair(7, 27), Pair(-3, 12), Pair(0, 12), Pair(-1, 14), Pair(-1, 16), Pair(4, 20), Pair(-3, 21),
        Pair(-2, 5), Pair(-2, 6), Pair(-7, 12), Pair(1, 14), Pair(-3, 18), Pair(-6, 22), Pair(1, 23), Pair(0, 26),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-27, 18), Pair(-76, 83), Pair(-25, 54), Pair(-80, 80), Pair(-79, 121), Pair(-15, 46), Pair(-43, 59), Pair(-36, -15),
        Pair(6, 36), Pair(-10, 66), Pair(-27, 70), Pair(-15, 84), Pair(-9, 71), Pair(-7, 89), Pair(4, 101), Pair(-2, 50),
        Pair(37, 54), Pair(-10, 72), Pair(-2, 71), Pair(-2, 70), Pair(-9, 66), Pair(-26, 92), Pair(-12, 89), Pair(-2, 51),
        Pair(-1, 61), Pair(3, 78), Pair(-2, 72), Pair(-4, 71), Pair(-2, 79), Pair(-12, 93), Pair(-2, 73), Pair(-18, 82),
        Pair(5, 68), Pair(9, 62), Pair(-1, 78), Pair(2, 70), Pair(-7, 87), Pair(7, 75), Pair(-14, 69), Pair(0, 63),
        Pair(-10, 52), Pair(7, 71), Pair(3, 66), Pair(4, 74), Pair(9, 79), Pair(3, 67), Pair(3, 79), Pair(10, 68),
        Pair(0, 0), Pair(7, 66), Pair(-4, 69), Pair(-3, 75), Pair(3, 72), Pair(-3, 73), Pair(4, 67), Pair(-1, 67),
        Pair(24, 56), Pair(-3, 22), Pair(14, 54), Pair(0, 80), Pair(0, 87), Pair(-5, 75), Pair(2, 62), Pair(10, 52)
      },
      { // Piece 2
        Pair(9, 61), Pair(24, 43), Pair(70, 25), Pair(11, 25), Pair(85, 28), Pair(62, -18), Pair(-13, 25), Pair(8, 8),
        Pair(9, 37), Pair(13, 53), Pair(10, 37), Pair(44, 27), Pair(37, 8), Pair(19, 28), Pair(-14, 53), Pair(-20, 65),
        Pair(10, 50), Pair(16, 44), Pair(25, 40), Pair(10, 50), Pair(28, 26), Pair(19, 34), Pair(-6, 46), Pair(-9, 60),
        Pair(8, 59), Pair(15, 59), Pair(11, 51), Pair(22, 32), Pair(0, 49), Pair(23, 39), Pair(7, 59), Pair(4, 50),
        Pair(10, 57), Pair(19, 51), Pair(8, 43), Pair(10, 41), Pair(5, 64), Pair(3, 60), Pair(11, 53), Pair(1, 74),
        Pair(-2, 45), Pair(20, 64), Pair(6, 50), Pair(6, 57), Pair(5, 66), Pair(11, 68), Pair(7, 61), Pair(18, 53),
        Pair(0, 0), Pair(3, 58), Pair(11, 58), Pair(1, 65), Pair(10, 63), Pair(4, 62), Pair(8, 66), Pair(11, 66),
        Pair(4, 47), Pair(-2, 44), Pair(2, 73), Pair(17, 61), Pair(5, 56), Pair(3, 68), Pair(5, 54), Pair(1, 57)
      },
      { // Piece 3
        Pair(-88, 104), Pair(6, 93), Pair(-8, 100), Pair(-18, 103), Pair(-12, 109), Pair(-125, 133), Pair(13, 109), Pair(-15, 105),
        Pair(-51, 90), Pair(-30, 113), Pair(-22, 108), Pair(-14, 106), Pair(-39, 110), Pair(-49, 111), Pair(-29, 115), Pair(-6, 95),
        Pair(-19, 98), Pair(-10, 106), Pair(-16, 103), Pair(-20, 110), Pair(-17, 107), Pair(-20, 109), Pair(-12, 110), Pair(12, 99),
        Pair(-36, 104), Pair(-11, 103), Pair(-22, 121), Pair(-2, 95), Pair(-23, 111), Pair(-15, 117), Pair(-16, 115), Pair(4, 94),
        Pair(-21, 104), Pair(-2, 107), Pair(-19, 114), Pair(-12, 115), Pair(-12, 107), Pair(-25, 109), Pair(0, 100), Pair(-7, 108),
        Pair(-26, 75), Pair(-11, 100), Pair(1, 103), Pair(-11, 113), Pair(-6, 98), Pair(-17, 107), Pair(-9, 106), Pair(5, 98),
        Pair(0, 0), Pair(-15, 118), Pair(-15, 114), Pair(-5, 110), Pair(-7, 103), Pair(-9, 99), Pair(-8, 92), Pair(5, 100),
        Pair(-33, 81), Pair(-15, 104), Pair(-11, 109), Pair(-10, 110), Pair(-8, 100), Pair(-13, 102), Pair(-6, 105), Pair(-1, 100)
      },
      { // Piece 4
        Pair(-5, 190), Pair(40, 139), Pair(26, 133), Pair(-26, 207), Pair(-24, 202), Pair(52, 157), Pair(-48, 241), Pair(-14, 228),
        Pair(-13, 190), Pair(-10, 191), Pair(1, 184), Pair(-3, 201), Pair(15, 160), Pair(-34, 184), Pair(9, 139), Pair(9, 145),
        Pair(-5, 201), Pair(10, 164), Pair(-7, 193), Pair(1, 185), Pair(-1, 176), Pair(-10, 193), Pair(0, 150), Pair(-3, 156),
        Pair(4, 205), Pair(3, 232), Pair(0, 192), Pair(-1, 184), Pair(29, 155), Pair(-4, 175), Pair(-8, 205), Pair(-1, 211),
        Pair(-7, 199), Pair(23, 171), Pair(16, 187), Pair(9, 195), Pair(6, 196), Pair(4, 197), Pair(6, 190), Pair(10, 168),
        Pair(-9, 187), Pair(16, 193), Pair(13, 191), Pair(10, 201), Pair(8, 209), Pair(7, 216), Pair(9, 199), Pair(10, 160),
        Pair(0, 0), Pair(15, 188), Pair(13, 195), Pair(14, 200), Pair(12, 203), Pair(16, 211), Pair(15, 201), Pair(20, 146),
        Pair(-1, 200), Pair(1, 210), Pair(11, 203), Pair(10, 213), Pair(12, 179), Pair(26, 171), Pair(-2, 237), Pair(23, 221)
      },
      { // Piece 5
        Pair(-88, 83), Pair(-99, 80), Pair(-96, 48), Pair(70, 22), Pair(8, -33), Pair(124, 64), Pair(-59, 102), Pair(-101, 34),
        Pair(6, 77), Pair(16, 127), Pair(-234, 129), Pair(-26, 90), Pair(-157, 45), Pair(47, 31), Pair(-139, 60), Pair(-78, 4),
        Pair(-80, 68), Pair(-26, 71), Pair(-9, 52), Pair(-178, 76), Pair(-106, 47), Pair(-238, 67), Pair(-79, 26), Pair(-139, 21),
        Pair(-110, 53), Pair(-100, 80), Pair(-80, 74), Pair(-142, 69), Pair(-54, 48), Pair(-75, 34), Pair(-82, 33), Pair(-148, 44),
        Pair(-39, 30), Pair(-71, 49), Pair(-55, 31), Pair(-54, 51), Pair(-54, 41), Pair(-24, 21), Pair(-58, 30), Pair(-64, 21),
        Pair(1, -10), Pair(7, -10), Pair(15, 14), Pair(-16, 28), Pair(-41, 33), Pair(-27, 25), Pair(-25, 20), Pair(-44, 10),
        Pair(0, 0), Pair(8, -5), Pair(28, -13), Pair(6, 7), Pair(-6, 15), Pair(-16, 22), Pair(-7, 12), Pair(-12, 2),
        Pair(21, -84), Pair(60, -45), Pair(64, -15), Pair(0, 4), Pair(-1, 5), Pair(-11, 17), Pair(-8, 10), Pair(-7, -1)
      }
    }},
    {{ // Bucket 49
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-10, 29), Pair(-15, 7), Pair(-10, 17), Pair(-6, 11), Pair(13, -2), Pair(14, 14), Pair(12, 7), Pair(-6, 26),
        Pair(-4, 20), Pair(2, 3), Pair(-14, 22), Pair(-8, 16), Pair(-5, 9), Pair(3, 11), Pair(-2, 11), Pair(-5, 7),
        Pair(-7, 16), Pair(7, 6), Pair(-7, 15), Pair(3, 9), Pair(2, 11), Pair(4, 14), Pair(0, 16), Pair(2, 14),
        Pair(-3, 14), Pair(1, 8), Pair(1, 16), Pair(1, 12), Pair(0, 16), Pair(3, 16), Pair(2, 20), Pair(0, 16),
        Pair(0, 15), Pair(-1, -9), Pair(9, 29), Pair(2, 14), Pair(0, 17), Pair(4, 17), Pair(0, 15), Pair(2, 20),
        Pair(-2, 10), Pair(0, 12), Pair(4, 14), Pair(1, -41), Pair(-3, 17), Pair(0, 20), Pair(0, 21), Pair(0, 19),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-29, 92), Pair(4, 83), Pair(-23, 96), Pair(-9, 41), Pair(-38, 55), Pair(-85, 68), Pair(7, 110), Pair(-37, 50),
        Pair(15, 31), Pair(-12, 42), Pair(-7, 60), Pair(-18, 80), Pair(-55, 80), Pair(-25, 73), Pair(-28, 75), Pair(-70, 74),
        Pair(-28, 64), Pair(0, 67), Pair(-5, 75), Pair(-21, 68), Pair(-13, 64), Pair(-43, 75), Pair(-39, 84), Pair(-49, 84),
        Pair(9, 48), Pair(-2, 62), Pair(-5, 65), Pair(-10, 75), Pair(-8, 73), Pair(-21, 65), Pair(-16, 80), Pair(-17, 79),
        Pair(-7, 77), Pair(8, 50), Pair(0, 63), Pair(-3, 71), Pair(-9, 68), Pair(1, 64), Pair(-18, 70), Pair(-7, 71),
        Pair(7, 65), Pair(-5, 61), Pair(7, 68), Pair(7, 62), Pair(3, 73), Pair(-2, 71), Pair(-3, 66), Pair(8, 57),
        Pair(-20, 81), Pair(0, 0), Pair(2, 67), Pair(-1, 65), Pair(-2, 72), Pair(3, 66), Pair(3, 67), Pair(-5, 65),
        Pair(-6, 86), Pair(-1, 92), Pair(10, 73), Pair(-1, 85), Pair(-3, 88), Pair(-3, 72), Pair(-1, 71), Pair(16, 16)
      },
      { // Piece 2
        Pair(27, 23), Pair(4, 58), Pair(-8, 43), Pair(-3, 37), Pair(40, 24), Pair(-9, 27), Pair(29, 65), Pair(13, 8),
        Pair(-1, 45), Pair(-5, 46), Pair(-12, 45), Pair(-25, 68), Pair(10, 29), Pair(36, 14), Pair(3, 8), Pair(-2, 28),
        Pair(-10, 64), Pair(7, 49), Pair(4, 45), Pair(-9, 45), Pair(11, 29), Pair(2, 30), Pair(13, 31), Pair(-18, 41),
        Pair(-3, 62), Pair(0, 42), Pair(4, 41), Pair(0, 44), Pair(-5, 44), Pair(7, 37), Pair(-7, 40), Pair(-15, 56),
        Pair(9, 41), Pair(4, 47), Pair(5, 39), Pair(3, 40), Pair(1, 53), Pair(2, 51), Pair(12, 46), Pair(0, 46),
        Pair(-19, 43), Pair(-6, 30), Pair(7, 66), Pair(-3, 52), Pair(-2, 55), Pair(3, 66), Pair(6, 59), Pair(-2, 56),
        Pair(0, 53), Pair(0, 0), Pair(5, 53), Pair(-4, 69), Pair(2, 59), Pair(9, 54), Pair(1, 64), Pair(1, 61),
        Pair(0, 0), Pair(8, 59), Pair(-12, 44), Pair(12, 57), Pair(-3, 73), Pair(-1, 67), Pair(-2, 69), Pair(10, 38)
      },
      { // Piece 3
        Pair(-50, 92), Pair(-23, 77), Pair(-7, 79), Pair(-30, 83), Pair(-28, 77), Pair(-14, 96), Pair(9, 62), Pair(-42, 93),
        Pair(-9, 69), Pair(-24, 76), Pair(-28, 85), Pair(-18, 82), Pair(-1, 75), Pair(-56, 109), Pair(-25, 98), Pair(3, 68),
        Pair(-18, 81), Pair(-25, 80), Pair(-18, 77), Pair(-19, 80), Pair(-21, 88), Pair(-49, 93), Pair(11, 66), Pair(-7, 72),
        Pair(-6, 77), Pair(-14, 76), Pair(-12, 80), Pair(-23, 80), Pair(-4, 71), Pair(-2, 73), Pair(-1, 60), Pair(-1, 69),
        Pair(-4, 67), Pair(-26, 85), Pair(-2, 83), Pair(9, 76), Pair(-12, 92), Pair(-15, 89), Pair(-10, 84), Pair(-3, 73),
        Pair(-3, 57), Pair(-24, 62), Pair(4, 72), Pair(-6, 91), Pair(-7, 80), Pair(-22, 98), Pair(-10, 76), Pair(9, 81),
        Pair(-16, 35), Pair(0, 0), Pair(-13, 89), Pair(-2, 84), Pair(-7, 88), Pair(-5, 81), Pair(8, 74), Pair(-5, 91),
        Pair(-9, 72), Pair(-19, 43), Pair(-11, 79), Pair(-7, 83), Pair(-9, 79), Pair(-10, 78), Pair(-6, 79), Pair(-5, 89)
      },
      { // Piece 4
        Pair(-14, 151), Pair(-30, 164), Pair(26, 100), Pair(11, 123), Pair(-94, 173), Pair(26, 114), Pair(47, 110), Pair(-49, 125),
        Pair(-10, 141), Pair(-9, 137), Pair(-21, 162), Pair(-27, 156), Pair(-38, 124), Pair(-13, 138), Pair(-6, 142), Pair(-46, 166),
        Pair(-14, 166), Pair(-18, 148), Pair(11, 112), Pair(-13, 138), Pair(-14, 132), Pair(-33, 160), Pair(-10, 152), Pair(-14, 139),
        Pair(-8, 165), Pair(-5, 147), Pair(-9, 161), Pair(-18, 153), Pair(-1, 109), Pair(-14, 123), Pair(-11, 131), Pair(-10, 127),
        Pair(0, 141), Pair(-12, 152), Pair(7, 127), Pair(-9, 146), Pair(4, 126), Pair(-13, 163), Pair(-8, 150), Pair(3, 109),
        Pair(-3, 150), Pair(-6, 119), Pair(-2, 162), Pair(-1, 159), Pair(8, 150), Pair(7, 137), Pair(-7, 150), Pair(6, 151),
        Pair(-18, 142), Pair(0, 0), Pair(0, 154), Pair(6, 156), Pair(8, 162), Pair(2, 174), Pair(16, 147), Pair(-11, 170),
        Pair(-5, 113), Pair(7, 81), Pair(0, 151), Pair(1, 158), Pair(5, 154), Pair(10, 163), Pair(0, 199), Pair(25, 172)
      },
      { // Piece 5
        Pair(-209, 66), Pair(49, 78), Pair(-170, 42), Pair(-152, 10), Pair(7, -1), Pair(-122, -40), Pair(11, 2), Pair(-62, -3),
        Pair(-23, 32), Pair(40, 48), Pair(12, 50), Pair(58, 12), Pair(54, 17), Pair(-134, 75), Pair(-216, 62), Pair(-246, 59),
        Pair(-278, 118), Pair(-81, 55), Pair(49, 48), Pair(-207, 93), Pair(-126, 36), Pair(-57, 36), Pair(-91, 21), Pair(-71, 30),
        Pair(21, 51), Pair(76, 42), Pair(48, 44), Pair(-131, 56), Pair(-112, 52), Pair(-50, 20), Pair(-106, 17), Pair(-104, 20),
        Pair(99, 17), Pair(50, 5), Pair(2, 43), Pair(-70, 36), Pair(-32, 33), Pair(-36, 18), Pair(-52, 21), Pair(-86, 26),
        Pair(114, -42), Pair(-42, 0), Pair(-20, 1), Pair(-22, 22), Pair(2, 18), Pair(1, 5), Pair(-13, 7), Pair(-44, 13),
        Pair(90, -4), Pair(0, 0), Pair(0, 8), Pair(9, 11), Pair(8, 11), Pair(-10, 13), Pair(-9, 6), Pair(-10, -3),
        Pair(87, -36), Pair(38, -18), Pair(42, -8), Pair(7, 11), Pair(12, 4), Pair(-10, 11), Pair(-6, 1), Pair(-8, -8)
      }
    }},
    {{ // Bucket 50
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-8, 24), Pair(-49, 25), Pair(-31, -9), Pair(0, -4), Pair(11, -1), Pair(-22, 24), Pair(-20, 18), Pair(-13, 22),
        Pair(-4, 8), Pair(-27, 31), Pair(-3, -4), Pair(-11, 21), Pair(11, 2), Pair(5, 1), Pair(-6, 17), Pair(1, 13),
        Pair(-1, 11), Pair(-9, 15), Pair(-2, -10), Pair(-3, 14), Pair(3, 9), Pair(0, 19), Pair(-3, 12), Pair(-2, 14),
        Pair(-3, 16), Pair(-2, 18), Pair(-5, -13), Pair(2, 22), Pair(1, 12), Pair(4, 16), Pair(1, 20), Pair(-2, 18),
        Pair(-6, 12), Pair(2, 25), Pair(-3, -26), Pair(4, 35), Pair(-7, 12), Pair(3, 15), Pair(-2, 17), Pair(-1, 13),
        Pair(-7, 13), Pair(4, 14), Pair(1, 2), Pair(0, 18), Pair(-6, 9), Pair(-3, 18), Pair(-3, 22), Pair(-3, 18),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-19, 24), Pair(3, 21), Pair(24, 39), Pair(130, 20), Pair(-172, 116), Pair(-61, 90), Pair(-85, 141), Pair(22, -23),
        Pair(-4, 58), Pair(-9, 72), Pair(3, 53), Pair(-18, 80), Pair(-2, 44), Pair(4, 54), Pair(27, 44), Pair(-13, 40),
        Pair(-16, 50), Pair(-11, 51), Pair(-23, 64), Pair(-10, 61), Pair(-30, 59), Pair(-11, 40), Pair(-15, 86), Pair(-12, 36),
        Pair(-1, 57), Pair(-6, 70), Pair(-14, 63), Pair(0, 61), Pair(-13, 58), Pair(-6, 72), Pair(-19, 74), Pair(-17, 60),
        Pair(-5, 60), Pair(12, 51), Pair(-2, 49), Pair(-2, 56), Pair(-9, 59), Pair(-7, 63), Pair(-14, 65), Pair(-8, 48),
        Pair(-9, 64), Pair(0, 66), Pair(-8, 42), Pair(-3, 70), Pair(5, 62), Pair(-6, 60), Pair(3, 54), Pair(-2, 41),
        Pair(-24, 56), Pair(20, 25), Pair(0, 0), Pair(-2, 68), Pair(-4, 62), Pair(-6, 70), Pair(4, 49), Pair(-7, 74),
        Pair(20, -42), Pair(-9, 48), Pair(-11, 82), Pair(-3, 64), Pair(-2, 54), Pair(-7, 66), Pair(-5, 56), Pair(24, -29)
      },
      { // Piece 2
        Pair(16, 46), Pair(-66, 97), Pair(31, 44), Pair(63, 21), Pair(65, 18), Pair(17, 47), Pair(-70, 51), Pair(26, 27),
        Pair(-4, 38), Pair(-5, 33), Pair(-5, 35), Pair(9, 24), Pair(35, 14), Pair(3, 20), Pair(9, 3), Pair(18, 15),
        Pair(-3, 50), Pair(16, 52), Pair(1, 49), Pair(10, 30), Pair(-3, 18), Pair(-1, 35), Pair(-6, 21), Pair(-5, 40),
        Pair(6, 42), Pair(0, 40), Pair(5, 43), Pair(-2, 30), Pair(-8, 53), Pair(-1, 22), Pair(1, 39), Pair(-14, 36),
        Pair(-10, 44), Pair(15, 36), Pair(-1, 32), Pair(16, 46), Pair(-5, 36), Pair(0, 50), Pair(3, 43), Pair(-5, 36),
        Pair(3, 40), Pair(-3, 39), Pair(1, 28), Pair(1, 65), Pair(-5, 54), Pair(-2, 49), Pair(0, 41), Pair(-11, 49),
        Pair(-14, -7), Pair(1, 66), Pair(0, 0), Pair(0, 56), Pair(-7, 56), Pair(-5, 59), Pair(-7, 57), Pair(-1, 81),
        Pair(-12, 52), Pair(-77, -79), Pair(1, 78), Pair(2, 21), Pair(-12, 64), Pair(-8, 53), Pair(24, 31), Pair(-4, 64)
      },
      { // Piece 3
        Pair(-33, 85), Pair(-26, 83), Pair(28, 45), Pair(-12, 67), Pair(-74, 108), Pair(61, 43), Pair(23, 56), Pair(49, 54),
        Pair(-33, 81), Pair(-13, 64), Pair(-38, 70), Pair(3, 53), Pair(-17, 48), Pair(-13, 62), Pair(-38, 70), Pair(14, 56),
        Pair(-14, 62), Pair(-6, 73), Pair(-29, 70), Pair(-37, 66), Pair(-19, 65), Pair(-6, 66), Pair(-15, 77), Pair(-17, 79),
        Pair(-16, 85), Pair(-18, 71), Pair(-23, 78), Pair(-20, 71), Pair(-17, 70), Pair(-21, 60), Pair(-35, 84), Pair(-17, 75),
        Pair(-5, 63), Pair(-10, 71), Pair(8, 65), Pair(-13, 74), Pair(-17, 70), Pair(-16, 58), Pair(12, 63), Pair(-22, 83),
        Pair(-1, 79), Pair(1, 63), Pair(11, 42), Pair(-16, 68), Pair(-4, 72), Pair(-22, 77), Pair(-21, 75), Pair(-1, 46),
        Pair(-28, 52), Pair(-19, 45), Pair(0, 0), Pair(-17, 76), Pair(-13, 74), Pair(-15, 64), Pair(-13, 49), Pair(-28, 85),
        Pair(-19, 73), Pair(-13, 67), Pair(-27, 34), Pair(-19, 74), Pair(-16, 73), Pair(-16, 70), Pair(-9, 73), Pair(-17, 88)
      },
      { // Piece 4
        Pair(20, 85), Pair(-20, 135), Pair(61, 35), Pair(38, 104), Pair(-28, 115), Pair(19, 68), Pair(53, -8), Pair(7, 59),
        Pair(-16, 117), Pair(-7, 123), Pair(-19, 101), Pair(-26, 118), Pair(34, 43), Pair(28, 62), Pair(-27, 144), Pair(-18, 145),
        Pair(2, 110), Pair(0, 102), Pair(8, 89), Pair(-16, 135), Pair(-21, 123), Pair(-37, 176), Pair(-31, 132), Pair(-17, 128),
        Pair(11, 87), Pair(2, 103), Pair(11, 80), Pair(-9, 111), Pair(0, 120), Pair(-17, 89), Pair(-12, 99), Pair(-27, 126),
        Pair(-18, 154), Pair(10, 87), Pair(-2, 122), Pair(4, 114), Pair(-8, 120), Pair(-13, 133), Pair(-8, 108), Pair(-4, 74),
        Pair(-21, 153), Pair(-4, 105), Pair(-7, 115), Pair(5, 109), Pair(11, 97), Pair(3, 106), Pair(-5, 120), Pair(-15, 143),
        Pair(4, 18), Pair(-7, 93), Pair(0, 0), Pair(4, 122), Pair(1, 116), Pair(5, 113), Pair(11, 112), Pair(-15, 174),
        Pair(8, 84), Pair(-5, 110), Pair(-2, 77), Pair(0, 98), Pair(1, 120), Pair(12, 101), Pair(3, 108), Pair(5, 114)
      },
      { // Piece 5
        Pair(31, 207), Pair(68, 102), Pair(40, -45), Pair(16, -63), Pair(107, -20), Pair(-50, 79), Pair(56, 30), Pair(59, 29),
        Pair(-44, 65), Pair(-87, 77), Pair(-207, 111), Pair(-60, 93), Pair(59, 38), Pair(-33, 18), Pair(44, 66), Pair(-115, -43),
        Pair(-40, 120), Pair(128, 26), Pair(-139, 70), Pair(45, 75), Pair(3, 46), Pair(-112, 52), Pair(-93, 7), Pair(-100, -4),
        Pair(76, 33), Pair(-110, 60), Pair(238, 5), Pair(19, 29), Pair(-137, 39), Pair(-195, 45), Pair(-43, 9), Pair(-78, 9),
        Pair(-13, 27), Pair(-37, 35), Pair(81, 6), Pair(22, 12), Pair(-65, 11), Pair(-44, 18), Pair(-28, 7), Pair(-39, 13),
        Pair(6, 25), Pair(-12, -14), Pair(8, -17), Pair(0, -12), Pair(9, 3), Pair(-37, 12), Pair(-17, 0), Pair(-10, 8),
        Pair(52, 27), Pair(41, -2), Pair(0, 0), Pair(-17, 14), Pair(2, -4), Pair(-1, -2), Pair(-12, 0), Pair(-6, -12),
        Pair(42, -6), Pair(7, 8), Pair(16, 7), Pair(-16, 12), Pair(11, 6), Pair(3, -5), Pair(-4, -10), Pair(-3, -15)
      }
    }},
    {{ // Bucket 51
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(8, -14), Pair(-17, -1), Pair(-11, -37), Pair(-55, 55), Pair(-105, 61), Pair(1, -17), Pair(20, -5), Pair(-24, 22),
        Pair(2, 10), Pair(7, 12), Pair(-15, 13), Pair(22, -25), Pair(-21, 23), Pair(14, -9), Pair(-10, 24), Pair(-3, 0),
        Pair(2, 0), Pair(2, 3), Pair(-3, 20), Pair(10, 5), Pair(-6, 22), Pair(3, 15), Pair(-4, 8), Pair(-9, 22),
        Pair(1, 15), Pair(0, 17), Pair(-2, 18), Pair(14, -1), Pair(6, 20), Pair(-1, 19), Pair(-1, 14), Pair(0, 8),
        Pair(1, 14), Pair(2, 9), Pair(5, 31), Pair(-6, -10), Pair(16, 36), Pair(-7, 13), Pair(2, 13), Pair(0, 9),
        Pair(-1, 13), Pair(3, -42), Pair(0, 17), Pair(-5, -5), Pair(7, 33), Pair(-8, 10), Pair(-4, 17), Pair(-2, 16),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(46, 6), Pair(-79, -47), Pair(-31, 51), Pair(-29, 20), Pair(12, -8), Pair(44, -102), Pair(-169, -35), Pair(3, 30),
        Pair(-25, 31), Pair(-16, 20), Pair(-57, 84), Pair(-135, 109), Pair(-93, 121), Pair(-53, 43), Pair(-57, 6), Pair(-12, -17),
        Pair(-11, 135), Pair(-11, 100), Pair(-39, 39), Pair(-38, 66), Pair(29, 17), Pair(-11, 10), Pair(33, -35), Pair(10, 40),
        Pair(-41, 19), Pair(-22, 43), Pair(-12, 40), Pair(-24, 69), Pair(-4, 64), Pair(-18, 26), Pair(-7, 35), Pair(-28, 64),
        Pair(-10, 32), Pair(-1, 51), Pair(-11, 37), Pair(-13, 42), Pair(-9, 56), Pair(-11, 27), Pair(-19, 51), Pair(-6, 39),
        Pair(-10, 15), Pair(-13, 18), Pair(-7, 37), Pair(-7, 20), Pair(-6, 37), Pair(-6, 45), Pair(-7, 37), Pair(-9, 47),
        Pair(1, 33), Pair(6, 32), Pair(0, 36), Pair(0, 0), Pair(-10, 50), Pair(-9, 46), Pair(-31, 52), Pair(-18, 35),
        Pair(-16, 81), Pair(-18, 5), Pair(19, 10), Pair(-12, 91), Pair(12, 49), Pair(18, 10), Pair(-11, 36), Pair(21, -6)
      },
      { // Piece 2
        Pair(-23, 24), Pair(27, -50), Pair(-83, 70), Pair(-95, -2), Pair(80, 18), Pair(-5, 25), Pair(-84, 57), Pair(17, 14),
        Pair(16, -53), Pair(-12, 22), Pair(-3, 17), Pair(31, -3), Pair(27, -48), Pair(1, -6), Pair(-2, 17), Pair(-3, 5),
        Pair(2, -6), Pair(16, 5), Pair(-14, 39), Pair(35, 0), Pair(-11, 10), Pair(-48, 68), Pair(-2, -32), Pair(-10, -28),
        Pair(-5, -5), Pair(0, 38), Pair(-16, 34), Pair(-13, 67), Pair(-13, 18), Pair(-17, 33), Pair(-16, -24), Pair(-31, 44),
        Pair(23, -24), Pair(-18, 18), Pair(-13, 36), Pair(-10, 41), Pair(2, 35), Pair(-28, 10), Pair(17, 8), Pair(1, -35),
        Pair(-8, -12), Pair(-6, 8), Pair(5, 25), Pair(-23, 19), Pair(-43, 37), Pair(-6, 45), Pair(-31, 72), Pair(-4, 36),
        Pair(15, 66), Pair(-13, 20), Pair(-3, -11), Pair(0, 0), Pair(-3, 44), Pair(-20, -24), Pair(-8, 49), Pair(-18, -108),
        Pair(-17, 13), Pair(-10, -2), Pair(-16, -55), Pair(36, 27), Pair(103, -195), Pair(-8, 50), Pair(-72, -7), Pair(-17, 24)
      },
      { // Piece 3
        Pair(-7, 58), Pair(11, 47), Pair(-39, 40), Pair(-77, 90), Pair(34, 59), Pair(83, 39), Pair(28, 31), Pair(21, 47),
        Pair(12, 16), Pair(-16, 34), Pair(-39, 67), Pair(-95, 70), Pair(-8, 56), Pair(-54, 71), Pair(-37, 52), Pair(-12, 80),
        Pair(-8, 54), Pair(15, 20), Pair(27, 19), Pair(73, -11), Pair(-26, 41), Pair(-50, 61), Pair(-35, 52), Pair(22, 77),
        Pair(-1, 49), Pair(-19, 54), Pair(4, 28), Pair(17, 49), Pair(-6, 49), Pair(-32, 49), Pair(-42, 28), Pair(19, 27),
        Pair(7, 56), Pair(-8, 39), Pair(1, 35), Pair(55, 11), Pair(-3, 19), Pair(-29, 69), Pair(1, 56), Pair(-4, 31),
        Pair(-6, 47), Pair(10, 43), Pair(-5, 49), Pair(-4, 53), Pair(-6, 31), Pair(-19, 40), Pair(-25, 55), Pair(-9, 67),
        Pair(-29, 36), Pair(-21, 52), Pair(2, 20), Pair(0, 0), Pair(-50, 70), Pair(-15, 30), Pair(11, 33), Pair(-8, 25),
        Pair(-14, 30), Pair(-7, 28), Pair(-16, 35), Pair(-21, -2), Pair(-22, 34), Pair(-13, 22), Pair(-6, 31), Pair(-14, 60)
      },
      { // Piece 4
        Pair(-56, 96), Pair(46, 132), Pair(39, 19), Pair(-12, 60), Pair(-132, 95), Pair(169, 82), Pair(7, 40), Pair(-53, 16),
        Pair(-36, 94), Pair(-55, 167), Pair(18, 63), Pair(37, -40), Pair(-18, -2), Pair(-10, 57), Pair(-17, 79), Pair(-39, 8),
        Pair(-20, 57), Pair(-10, 140), Pair(7, 63), Pair(-12, 25), Pair(-10, 44), Pair(6, 78), Pair(-23, 136), Pair(-46, 103),
        Pair(31, 38), Pair(-26, 79), Pair(-1, 7), Pair(14, 20), Pair(-18, 63), Pair(-11, 40), Pair(-12, 80), Pair(-1, 22),
        Pair(-18, 44), Pair(6, 29), Pair(-12, 99), Pair(0, 22), Pair(4, 50), Pair(-39, 122), Pair(-7, 97), Pair(-21, 88),
        Pair(-11, 51), Pair(-7, 27), Pair(16, 19), Pair(-20, 61), Pair(19, 16), Pair(-3, 43), Pair(-19, 76), Pair(-16, 141),
        Pair(-22, 57), Pair(0, 30), Pair(-1, 57), Pair(0, 0), Pair(0, 22), Pair(1, 25), Pair(-2, 114), Pair(-53, 129),
        Pair(1, 54), Pair(0, 44), Pair(3, 18), Pair(2, 2), Pair(-4, 52), Pair(26, -3), Pair(32, 152), Pair(-27, 70)
      },
      { // Piece 5
        Pair(6, 39), Pair(40, 55), Pair(17, 94), Pair(45, 159), Pair(-17, -120), Pair(-33, -133), Pair(-87, -72), Pair(-32, 17),
        Pair(-25, 182), Pair(5, 118), Pair(1, 50), Pair(18, 14), Pair(88, 112), Pair(-47, 74), Pair(-48, 13), Pair(-83, -62),
        Pair(-87, 16), Pair(78, 9), Pair(-46, 15), Pair(-13, 34), Pair(-113, 57), Pair(-41, 12), Pair(1, 41), Pair(112, 80),
        Pair(-31, -19), Pair(19, 78), Pair(-67, 46), Pair(-6, 46), Pair(61, 30), Pair(-50, 71), Pair(-169, 51), Pair(-25, -19),
        Pair(-82, 0), Pair(-76, 43), Pair(61, 2), Pair(-54, 16), Pair(0, 40), Pair(-124, 12), Pair(3, -28), Pair(-15, 5),
        Pair(-40, 62), Pair(-59, 26), Pair(34, -41), Pair(-35, -6), Pair(23, -38), Pair(-22, 7), Pair(48, -29), Pair(-13, -13),
        Pair(55, -13), Pair(-16, 26), Pair(-50, 26), Pair(0, 0), Pair(-59, 23), Pair(-4, -3), Pair(10, -28), Pair(9, -23),
        Pair(67, -29), Pair(9, 19), Pair(-1, 0), Pair(-49, 25), Pair(-13, -22), Pair(-12, 2), Pair(12, -15), Pair(0, -33)
      }
    }},
    {{ // Bucket 52
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-22, 27), Pair(13, 6), Pair(8, 33), Pair(-13, -1), Pair(-5, 0), Pair(-53, 69), Pair(-45, 29), Pair(-3, 5),
        Pair(-1, 17), Pair(-15, 20), Pair(-6, 24), Pair(-11, 18), Pair(5, 9), Pair(-31, 43), Pair(-23, 27), Pair(5, -3),
        Pair(-5, 15), Pair(-4, 16), Pair(-3, 17), Pair(-4, 32), Pair(2, 8), Pair(3, 23), Pair(0, 14), Pair(-1, 9),
        Pair(-6, 20), Pair(-5, 19), Pair(-5, 19), Pair(2, 27), Pair(2, 5), Pair(10, 16), Pair(0, 17), Pair(4, 11),
        Pair(-5, 17), Pair(-1, 17), Pair(-8, 18), Pair(8, 46), Pair(2, -13), Pair(11, 30), Pair(2, 15), Pair(1, 12),
        Pair(-6, 18), Pair(-2, 15), Pair(-6, 8), Pair(8, 34), Pair(-5, 0), Pair(6, 20), Pair(-1, -31), Pair(5, 12),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-7, 8), Pair(-68, 77), Pair(-20, 31), Pair(-38, 41), Pair(-97, 68), Pair(-33, -28), Pair(9, -17), Pair(-153, 91),
        Pair(30, -25), Pair(-9, 22), Pair(-14, 45), Pair(-36, 67), Pair(-2, 10), Pair(3, 55), Pair(39, 35), Pair(-12, 30),
        Pair(7, 5), Pair(-6, 68), Pair(-3, 15), Pair(-13, 41), Pair(-52, 59), Pair(-1, 27), Pair(-32, 54), Pair(-47, 56),
        Pair(0, 39), Pair(-4, 52), Pair(-10, 44), Pair(-2, 42), Pair(-24, 36), Pair(-6, 42), Pair(-23, 49), Pair(6, 62),
        Pair(3, 38), Pair(-3, 53), Pair(-3, 33), Pair(-6, 40), Pair(-9, 34), Pair(-9, 43), Pair(-43, 68), Pair(-16, 24),
        Pair(3, 33), Pair(1, 59), Pair(1, 47), Pair(-12, 54), Pair(-9, 29), Pair(-8, 52), Pair(-23, 59), Pair(-5, 15),
        Pair(5, 78), Pair(-11, 59), Pair(-15, 59), Pair(2, 32), Pair(0, 0), Pair(-9, 43), Pair(-11, 22), Pair(-14, 34),
        Pair(-68, 88), Pair(-1, 68), Pair(3, 42), Pair(-6, 56), Pair(-8, 83), Pair(-7, 67), Pair(-8, 25), Pair(-77, 0)
      },
      { // Piece 2
        Pair(7, 9), Pair(-68, 58), Pair(136, -65), Pair(3, 14), Pair(-73, 28), Pair(68, 4), Pair(100, 27), Pair(-21, 6),
        Pair(-14, 22), Pair(-18, 24), Pair(-21, 30), Pair(7, 11), Pair(27, -9), Pair(-27, 19), Pair(-72, 99), Pair(-43, 17),
        Pair(-25, 24), Pair(-16, 16), Pair(-5, 14), Pair(2, -7), Pair(-4, -1), Pair(-62, 64), Pair(3, 29), Pair(-8, 19),
        Pair(-6, 37), Pair(34, 15), Pair(-12, 30), Pair(-13, 15), Pair(-18, 39), Pair(-8, 25), Pair(-4, 14), Pair(-28, 19),
        Pair(-57, 47), Pair(3, 6), Pair(22, 20), Pair(-6, 39), Pair(-8, 21), Pair(-4, 16), Pair(16, -1), Pair(-4, 25),
        Pair(0, 36), Pair(0, 15), Pair(0, 19), Pair(-15, 50), Pair(-20, 6), Pair(-2, 31), Pair(-19, 37), Pair(-15, 7),
        Pair(-56, 59), Pair(-4, 28), Pair(56, -13), Pair(-9, 27), Pair(0, 0), Pair(-6, 32), Pair(-12, 17), Pair(4, 0),
        Pair(4, 16), Pair(22, -11), Pair(-9, 35), Pair(177, -109), Pair(7, 43), Pair(-23, -18), Pair(-9, 28), Pair(3, -11)
      },
      { // Piece 3
        Pair(36, 36), Pair(-1, 34), Pair(-17, 49), Pair(18, 21), Pair(68, 39), Pair(-69, 82), Pair(-81, 55), Pair(91, 18),
        Pair(-31, 60), Pair(-15, 42), Pair(8, 36), Pair(-2, 30), Pair(-36, 59), Pair(-100, 98), Pair(-31, 57), Pair(-3, 47),
        Pair(-2, 49), Pair(10, 35), Pair(-40, 63), Pair(-6, 43), Pair(-47, 69), Pair(16, 24), Pair(-7, 44), Pair(-5, 35),
        Pair(1, 44), Pair(-8, 62), Pair(-2, 39), Pair(-1, 29), Pair(-9, 41), Pair(-6, 59), Pair(5, 61), Pair(14, 26),
        Pair(-2, 37), Pair(-4, 49), Pair(13, 36), Pair(-10, 38), Pair(14, 19), Pair(-7, 24), Pair(-14, 61), Pair(-21, 38),
        Pair(14, 44), Pair(11, 23), Pair(-13, 61), Pair(9, 35), Pair(-3, 27), Pair(0, 30), Pair(-20, 82), Pair(-22, 52),
        Pair(-23, 61), Pair(-24, 66), Pair(2, 33), Pair(-20, 52), Pair(0, 0), Pair(-19, 24), Pair(-5, -23), Pair(-16, 18),
        Pair(-6, 39), Pair(-5, 35), Pair(-9, 42), Pair(-8, 30), Pair(-14, 4), Pair(-16, 40), Pair(-9, 45), Pair(-3, 34)
      },
      { // Piece 4
        Pair(-9, 60), Pair(7, 96), Pair(-1, 97), Pair(94, -51), Pair(46, -12), Pair(31, 148), Pair(15, 87), Pair(-131, 76),
        Pair(-31, 88), Pair(-29, 112), Pair(-22, 108), Pair(-10, 84), Pair(21, 12), Pair(41, 83), Pair(-71, 135), Pair(-46, 36),
        Pair(-11, 77), Pair(-12, 71), Pair(-21, 93), Pair(-4, 132), Pair(-12, 67), Pair(-48, 89), Pair(-26, 100), Pair(-53, 108),
        Pair(7, 60), Pair(-8, 70), Pair(-5, 65), Pair(-11, 44), Pair(-9, 57), Pair(-21, 54), Pair(-17, 59), Pair(-38, 69),
        Pair(3, 64), Pair(-1, 76), Pair(-5, 65), Pair(-1, 42), Pair(-14, 98), Pair(-7, 46), Pair(-19, 61), Pair(-13, 97),
        Pair(11, 65), Pair(8, 48), Pair(-2, 56), Pair(-3, 74), Pair(-11, 53), Pair(6, 59), Pair(-5, 26), Pair(-26, 31),
        Pair(7, 12), Pair(6, 51), Pair(5, 47), Pair(-1, 47), Pair(0, 0), Pair(-8, 53), Pair(14, 21), Pair(-21, 155),
        Pair(-4, 86), Pair(14, 58), Pair(-3, 41), Pair(-2, 37), Pair(-16, 56), Pair(-20, 85), Pair(19, 98), Pair(34, 119)
      },
      { // Piece 5
        Pair(-1, 37), Pair(-14, -75), Pair(77, 247), Pair(55, 185), Pair(-37, -83), Pair(-20, 50), Pair(-4, -37), Pair(-44, -47),
        Pair(-77, 35), Pair(4, 37), Pair(-21, 73), Pair(-79, 15), Pair(-60, 19), Pair(-101, 77), Pair(-70, 88), Pair(-8, -57),
        Pair(-43, -24), Pair(-87, 13), Pair(99, 22), Pair(-256, 52), Pair(-30, 28), Pair(-104, 61), Pair(-20, -21), Pair(-63, 56),
        Pair(-44, -15), Pair(59, -22), Pair(-88, 42), Pair(-127, 62), Pair(-43, 47), Pair(-11, -13), Pair(-100, 18), Pair(3, -8),
        Pair(7, 15), Pair(37, -41), Pair(22, -3), Pair(24, 22), Pair(9, 1), Pair(37, -15), Pair(-92, 30), Pair(-68, 19),
        Pair(-96, 40), Pair(-59, 28), Pair(26, -11), Pair(27, -26), Pair(7, -19), Pair(-11, -28), Pair(29, 6), Pair(64, -19),
        Pair(-27, -6), Pair(-17, -3), Pair(-11, 0), Pair(-61, 6), Pair(0, 0), Pair(-54, 15), Pair(14, -11), Pair(15, -6),
        Pair(-29, -30), Pair(-33, 3), Pair(-9, 7), Pair(-11, 8), Pair(-27, 21), Pair(-27, 5), Pair(7, -16), Pair(5, -20)
      }
    }},
    {{ // Bucket 53
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-1, 17), Pair(-13, 20), Pair(-10, 7), Pair(-13, 18), Pair(12, 6), Pair(-28, 16), Pair(3, 14), Pair(-16, 18),
        Pair(-7, 23), Pair(-8, 20), Pair(1, 17), Pair(1, 13), Pair(-3, 21), Pair(-8, 10), Pair(-13, 19), Pair(2, 11),
        Pair(-3, 20), Pair(-1, 15), Pair(1, 13), Pair(1, 14), Pair(-7, 20), Pair(1, 13), Pair(-1, 16), Pair(4, 12),
        Pair(-4, 18), Pair(2, 18), Pair(0, 14), Pair(-1, 16), Pair(0, 18), Pair(5, 6), Pair(13, 21), Pair(5, 9),
        Pair(-4, 17), Pair(1, 21), Pair(-2, 13), Pair(-6, 13), Pair(10, 35), Pair(2, -8), Pair(19, 23), Pair(3, 14),
        Pair(0, 21), Pair(0, 21), Pair(-4, 18), Pair(-8, 10), Pair(7, 19), Pair(9, -4), Pair(8, 10), Pair(-2, 8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(28, 10), Pair(72, 15), Pair(40, 44), Pair(53, 42), Pair(62, 34), Pair(30, 37), Pair(37, 36), Pair(-74, 90),
        Pair(11, 50), Pair(-26, 60), Pair(-7, 59), Pair(-14, 55), Pair(-27, 76), Pair(-41, 72), Pair(-2, 62), Pair(-25, 59),
        Pair(-1, 58), Pair(5, 65), Pair(4, 62), Pair(-22, 72), Pair(2, 55), Pair(-31, 68), Pair(-8, 66), Pair(-41, 61),
        Pair(-11, 72), Pair(1, 71), Pair(2, 68), Pair(-17, 71), Pair(-8, 63), Pair(-24, 62), Pair(-17, 69), Pair(-25, 63),
        Pair(-6, 71), Pair(-6, 73), Pair(-2, 73), Pair(6, 65), Pair(-8, 58), Pair(-9, 66), Pair(-20, 67), Pair(-22, 62),
        Pair(-5, 81), Pair(8, 66), Pair(-2, 71), Pair(1, 59), Pair(6, 67), Pair(-9, 51), Pair(-1, 71), Pair(-18, 45),
        Pair(-16, 67), Pair(3, 59), Pair(2, 71), Pair(1, 66), Pair(-3, 72), Pair(0, 0), Pair(-17, 70), Pair(-9, 51),
        Pair(-69, 44), Pair(6, 61), Pair(8, 65), Pair(-8, 70), Pair(6, 68), Pair(-10, 81), Pair(-6, 49), Pair(-65, 98)
      },
      { // Piece 2
        Pair(16, 40), Pair(7, 39), Pair(83, 24), Pair(50, 14), Pair(55, 35), Pair(46, 31), Pair(28, 40), Pair(-22, 59),
        Pair(-12, 38), Pair(1, 39), Pair(15, 25), Pair(32, 26), Pair(20, 33), Pair(-29, 50), Pair(-14, 41), Pair(14, 38),
        Pair(0, 40), Pair(-10, 40), Pair(29, 31), Pair(9, 32), Pair(6, 44), Pair(-16, 42), Pair(0, 46), Pair(-45, 65),
        Pair(-9, 44), Pair(17, 38), Pair(-8, 38), Pair(5, 42), Pair(-12, 43), Pair(18, 35), Pair(-16, 49), Pair(-12, 57),
        Pair(7, 56), Pair(-7, 44), Pair(2, 48), Pair(-14, 50), Pair(11, 45), Pair(-11, 50), Pair(16, 39), Pair(-29, 32),
        Pair(-8, 54), Pair(-6, 52), Pair(-12, 51), Pair(0, 50), Pair(-8, 65), Pair(8, 40), Pair(-15, 34), Pair(-1, 52),
        Pair(0, 50), Pair(-14, 63), Pair(-3, 58), Pair(-17, 62), Pair(16, 44), Pair(0, 0), Pair(3, 59), Pair(-21, 33),
        Pair(-12, 59), Pair(4, 37), Pair(-11, 66), Pair(1, 55), Pair(-10, 37), Pair(13, 66), Pair(-20, -76), Pair(19, 21)
      },
      { // Piece 3
        Pair(27, 73), Pair(31, 71), Pair(30, 72), Pair(32, 74), Pair(11, 86), Pair(75, 60), Pair(59, 66), Pair(63, 55),
        Pair(11, 80), Pair(-3, 89), Pair(1, 83), Pair(22, 77), Pair(-1, 81), Pair(15, 69), Pair(-5, 90), Pair(6, 80),
        Pair(12, 88), Pair(16, 79), Pair(11, 83), Pair(8, 83), Pair(5, 75), Pair(23, 69), Pair(-32, 85), Pair(-2, 85),
        Pair(-1, 88), Pair(12, 83), Pair(4, 80), Pair(16, 76), Pair(-2, 84), Pair(36, 68), Pair(-2, 88), Pair(15, 76),
        Pair(9, 83), Pair(4, 85), Pair(8, 90), Pair(14, 84), Pair(0, 90), Pair(31, 56), Pair(13, 82), Pair(13, 81),
        Pair(6, 83), Pair(2, 85), Pair(5, 85), Pair(3, 84), Pair(5, 90), Pair(13, 71), Pair(-5, 90), Pair(-17, 96),
        Pair(-13, 92), Pair(5, 78), Pair(-7, 87), Pair(4, 75), Pair(-6, 85), Pair(0, 0), Pair(-27, 60), Pair(-41, 83),
        Pair(4, 83), Pair(6, 87), Pair(5, 84), Pair(5, 80), Pair(-1, 78), Pair(-13, 59), Pair(-11, 80), Pair(-6, 77)
      },
      { // Piece 4
        Pair(35, 141), Pair(39, 119), Pair(31, 124), Pair(56, 114), Pair(38, 131), Pair(-46, 167), Pair(-4, 150), Pair(21, 144),
        Pair(-8, 144), Pair(-7, 174), Pair(-17, 156), Pair(11, 148), Pair(11, 146), Pair(9, 101), Pair(17, 150), Pair(10, 153),
        Pair(-11, 181), Pair(-9, 145), Pair(-2, 175), Pair(-22, 174), Pair(-24, 182), Pair(-53, 178), Pair(-8, 186), Pair(-37, 172),
        Pair(-14, 179), Pair(-5, 179), Pair(-5, 150), Pair(2, 153), Pair(-12, 141), Pair(-18, 140), Pair(-15, 145), Pair(-20, 158),
        Pair(12, 174), Pair(5, 158), Pair(12, 141), Pair(0, 151), Pair(14, 128), Pair(-4, 140), Pair(0, 139), Pair(-23, 154),
        Pair(21, 138), Pair(12, 161), Pair(13, 140), Pair(13, 139), Pair(13, 142), Pair(1, 130), Pair(-14, 145), Pair(-6, 144),
        Pair(23, 114), Pair(22, 136), Pair(16, 141), Pair(12, 138), Pair(13, 147), Pair(0, 0), Pair(3, 112), Pair(5, 125),
        Pair(15, 163), Pair(12, 167), Pair(17, 159), Pair(13, 158), Pair(5, 130), Pair(8, 117), Pair(28, 112), Pair(19, 109)
      },
      { // Piece 5
        Pair(-122, -56), Pair(175, -50), Pair(-181, 76), Pair(66, 74), Pair(26, 16), Pair(15, 84), Pair(-129, 32), Pair(-142, 80),
        Pair(-244, 48), Pair(6, 22), Pair(-169, 91), Pair(26, 57), Pair(-177, 114), Pair(17, 97), Pair(-168, 90), Pair(-102, 60),
        Pair(-64, 8), Pair(8, 19), Pair(-5, 21), Pair(-108, 72), Pair(-141, 64), Pair(-63, 71), Pair(-53, 80), Pair(4, 30),
        Pair(-295, 67), Pair(-95, 26), Pair(-246, 66), Pair(-80, 43), Pair(-75, 56), Pair(-80, 67), Pair(38, 24), Pair(-23, 33),
        Pair(-146, 10), Pair(-16, 16), Pair(-148, 47), Pair(-78, 32), Pair(-56, 35), Pair(-64, 36), Pair(25, 16), Pair(22, 12),
        Pair(-82, 26), Pair(-65, 22), Pair(-54, 28), Pair(-22, 19), Pair(-37, -5), Pair(-19, -14), Pair(-22, -16), Pair(36, 1),
        Pair(-34, -3), Pair(-5, 15), Pair(-10, 11), Pair(-21, 12), Pair(-1, -1), Pair(0, 0), Pair(30, -17), Pair(37, -4),
        Pair(-4, -18), Pair(-4, -8), Pair(-2, 0), Pair(-7, 3), Pair(-3, -8), Pair(-29, 14), Pair(6, 3), Pair(26, 7)
      }
    }},
    {{ // Bucket 54
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-16, 31), Pair(-6, 17), Pair(9, 6), Pair(5, 13), Pair(15, 0), Pair(7, -1), Pair(-5, -5), Pair(-11, 17),
        Pair(-2, 19), Pair(-2, 18), Pair(-6, 22), Pair(3, 16), Pair(-9, 18), Pair(0, 13), Pair(1, -13), Pair(0, 20),
        Pair(1, 22), Pair(1, 15), Pair(1, 12), Pair(2, 12), Pair(3, 19), Pair(-11, 17), Pair(11, -6), Pair(-1, 15),
        Pair(0, 20), Pair(3, 21), Pair(1, 17), Pair(1, 16), Pair(-3, 15), Pair(3, 20), Pair(14, -8), Pair(5, 20),
        Pair(2, 19), Pair(-3, 20), Pair(5, 19), Pair(2, 16), Pair(0, 18), Pair(15, 25), Pair(-8, -7), Pair(13, 24),
        Pair(-1, 19), Pair(4, 21), Pair(-3, 18), Pair(-2, 21), Pair(-3, -32), Pair(9, 11), Pair(11, 6), Pair(2, 9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(11, 48), Pair(-35, 83), Pair(36, 51), Pair(85, 17), Pair(-18, 28), Pair(6, 43), Pair(-89, 69), Pair(49, -44),
        Pair(-16, 55), Pair(8, 49), Pair(-4, 63), Pair(-12, 69), Pair(-19, 53), Pair(40, 31), Pair(32, 22), Pair(26, 23),
        Pair(-48, 67), Pair(-4, 63), Pair(2, 62), Pair(-7, 60), Pair(-5, 55), Pair(9, 32), Pair(-5, 40), Pair(2, 17),
        Pair(4, 58), Pair(4, 56), Pair(0, 63), Pair(-2, 58), Pair(-4, 52), Pair(-4, 53), Pair(2, 40), Pair(-15, 62),
        Pair(2, 61), Pair(-10, 73), Pair(2, 55), Pair(3, 57), Pair(1, 47), Pair(-3, 53), Pair(-1, 38), Pair(-9, 50),
        Pair(-3, 68), Pair(10, 49), Pair(3, 66), Pair(4, 61), Pair(-5, 48), Pair(6, 55), Pair(-5, 38), Pair(-6, 46),
        Pair(-16, 59), Pair(-9, 61), Pair(-3, 70), Pair(1, 61), Pair(-6, 53), Pair(-8, 46), Pair(0, 0), Pair(-13, 59),
        Pair(-49, 94), Pair(-9, 64), Pair(6, 55), Pair(-7, 66), Pair(0, 51), Pair(-2, 50), Pair(-2, 84), Pair(-6, 119)
      },
      { // Piece 2
        Pair(-50, 13), Pair(16, 20), Pair(-21, 10), Pair(62, 39), Pair(99, 5), Pair(122, -1), Pair(109, -12), Pair(23, 36),
        Pair(8, 31), Pair(-23, 33), Pair(3, 22), Pair(47, -2), Pair(27, 25), Pair(23, 20), Pair(-15, 42), Pair(-41, 33),
        Pair(-2, 25), Pair(23, 26), Pair(15, 14), Pair(15, 38), Pair(-11, 25), Pair(18, 43), Pair(-4, 24), Pair(-2, 43),
        Pair(-2, 49), Pair(5, 40), Pair(27, 26), Pair(-24, 42), Pair(0, 41), Pair(-7, 27), Pair(7, 33), Pair(-16, 48),
        Pair(14, 35), Pair(13, 44), Pair(-1, 35), Pair(11, 43), Pair(-8, 37), Pair(7, 41), Pair(-10, 33), Pair(-2, 43),
        Pair(10, 48), Pair(-4, 40), Pair(-1, 54), Pair(-4, 42), Pair(0, 53), Pair(-7, 39), Pair(-2, 34), Pair(-23, 6),
        Pair(6, 37), Pair(6, 51), Pair(-5, 37), Pair(6, 57), Pair(-7, 47), Pair(16, 29), Pair(0, 0), Pair(3, 16),
        Pair(25, 45), Pair(8, 34), Pair(7, 57), Pair(-9, 44), Pair(18, 45), Pair(-14, 35), Pair(38, 52), Pair(0, 0)
      },
      { // Piece 3
        Pair(21, 71), Pair(28, 64), Pair(26, 70), Pair(39, 59), Pair(23, 74), Pair(50, 69), Pair(-8, 60), Pair(80, 45),
        Pair(9, 77), Pair(2, 79), Pair(8, 73), Pair(16, 71), Pair(26, 71), Pair(20, 67), Pair(26, 54), Pair(-25, 81),
        Pair(14, 80), Pair(23, 71), Pair(13, 73), Pair(-5, 74), Pair(-10, 84), Pair(11, 73), Pair(39, 50), Pair(-3, 70),
        Pair(5, 76), Pair(9, 73), Pair(-2, 69), Pair(8, 74), Pair(19, 65), Pair(1, 78), Pair(36, 49), Pair(-2, 76),
        Pair(15, 72), Pair(7, 76), Pair(11, 75), Pair(13, 74), Pair(14, 68), Pair(12, 71), Pair(60, 35), Pair(-11, 77),
        Pair(13, 80), Pair(2, 73), Pair(-6, 83), Pair(-3, 77), Pair(10, 72), Pair(-3, 92), Pair(38, 39), Pair(-20, 75),
        Pair(9, 78), Pair(17, 66), Pair(8, 76), Pair(6, 75), Pair(3, 82), Pair(2, 72), Pair(0, 0), Pair(-61, 64),
        Pair(9, 78), Pair(14, 72), Pair(10, 69), Pair(12, 67), Pair(8, 76), Pair(3, 72), Pair(-2, 43), Pair(-14, 62)
      },
      { // Piece 4
        Pair(16, 108), Pair(31, 107), Pair(-7, 128), Pair(54, 83), Pair(49, 87), Pair(50, 93), Pair(31, 89), Pair(14, 131),
        Pair(-6, 140), Pair(1, 129), Pair(4, 131), Pair(15, 121), Pair(31, 96), Pair(12, 120), Pair(10, 130), Pair(31, 66),
        Pair(7, 140), Pair(14, 129), Pair(21, 115), Pair(0, 125), Pair(-14, 134), Pair(25, 111), Pair(10, 124), Pair(-2, 131),
        Pair(18, 125), Pair(0, 141), Pair(11, 122), Pair(22, 108), Pair(3, 123), Pair(-19, 116), Pair(-3, 153), Pair(1, 97),
        Pair(22, 117), Pair(20, 120), Pair(16, 123), Pair(10, 114), Pair(11, 112), Pair(-8, 129), Pair(14, 109), Pair(-2, 122),
        Pair(31, 108), Pair(29, 121), Pair(9, 152), Pair(24, 114), Pair(16, 123), Pair(17, 104), Pair(3, 126), Pair(-10, 125),
        Pair(30, 133), Pair(22, 139), Pair(20, 135), Pair(19, 141), Pair(21, 124), Pair(14, 118), Pair(0, 0), Pair(-3, 124),
        Pair(16, 162), Pair(28, 143), Pair(19, 138), Pair(18, 140), Pair(17, 138), Pair(13, 120), Pair(2, 112), Pair(0, 57)
      },
      { // Piece 5
        Pair(-2, 33), Pair(-183, 19), Pair(-107, 43), Pair(-7, 18), Pair(12, 51), Pair(24, 86), Pair(-27, 143), Pair(-72, 154),
        Pair(-181, 4), Pair(-64, 11), Pair(-76, 82), Pair(-83, 39), Pair(-69, 31), Pair(-79, 75), Pair(-119, 101), Pair(24, 75),
        Pair(-146, 42), Pair(7, 24), Pair(-27, 28), Pair(-243, 66), Pair(-139, 67), Pair(-115, 74), Pair(-34, 59), Pair(-80, 48),
        Pair(-146, 61), Pair(-59, 26), Pair(-65, 44), Pair(-161, 72), Pair(-83, 51), Pair(-77, 49), Pair(-36, 54), Pair(2, 38),
        Pair(-64, 29), Pair(-130, 41), Pair(-58, 39), Pair(-59, 47), Pair(-50, 34), Pair(-29, 26), Pair(24, 21), Pair(21, 22),
        Pair(-154, 35), Pair(-58, 33), Pair(-28, 26), Pair(-43, 36), Pair(4, 9), Pair(-34, -5), Pair(-12, -6), Pair(38, -37),
        Pair(-40, -6), Pair(-27, 7), Pair(-18, 20), Pair(-21, 23), Pair(10, 4), Pair(-12, -10), Pair(0, 0), Pair(12, -13),
        Pair(-26, -40), Pair(-20, 4), Pair(-25, 11), Pair(-3, 11), Pair(28, -2), Pair(-7, -3), Pair(15, -7), Pair(-1, -18)
      }
    }},
    {{ // Bucket 55
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-11, 29), Pair(-24, 29), Pair(-12, 18), Pair(-12, 17), Pair(-27, 16), Pair(1, 9), Pair(-19, 24), Pair(38, -2),
        Pair(-2, 24), Pair(-10, 23), Pair(-2, 17), Pair(4, 6), Pair(-11, 20), Pair(-4, 6), Pair(4, 9), Pair(-7, 13),
        Pair(-5, 21), Pair(-1, 12), Pair(3, 14), Pair(1, 10), Pair(-6, 11), Pair(-8, 12), Pair(-11, 21), Pair(11, 6),
        Pair(-3, 20), Pair(2, 20), Pair(-1, 14), Pair(1, 13), Pair(-2, 8), Pair(-2, 11), Pair(3, 14), Pair(10, 4),
        Pair(-5, 16), Pair(0, 20), Pair(-1, 15), Pair(-3, 13), Pair(4, 11), Pair(3, 9), Pair(5, 25), Pair(-14, 1),
        Pair(-6, 18), Pair(-2, 22), Pair(1, 17), Pair(0, 18), Pair(5, 15), Pair(-4, 10), Pair(-3, 8), Pair(2, -9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(50, 38), Pair(63, 44), Pair(7, 58), Pair(-41, 32), Pair(17, 44), Pair(37, 5), Pair(55, 61), Pair(-12, 34),
        Pair(6, 47), Pair(-15, 65), Pair(11, 55), Pair(-19, 71), Pair(2, 35), Pair(-31, 39), Pair(-8, 76), Pair(-7, 45),
        Pair(2, 48), Pair(-3, 68), Pair(8, 55), Pair(0, 57), Pair(-2, 62), Pair(18, 34), Pair(-14, 48), Pair(16, 27),
        Pair(6, 65), Pair(7, 62), Pair(7, 69), Pair(4, 59), Pair(0, 52), Pair(-4, 52), Pair(0, 50), Pair(-7, 50),
        Pair(2, 65), Pair(12, 62), Pair(10, 61), Pair(9, 54), Pair(-1, 60), Pair(-3, 58), Pair(9, 45), Pair(-2, 35),
        Pair(4, 71), Pair(5, 63), Pair(3, 61), Pair(4, 63), Pair(4, 62), Pair(-1, 51), Pair(9, 54), Pair(-16, 33),
        Pair(-10, 91), Pair(3, 60), Pair(7, 56), Pair(3, 63), Pair(0, 58), Pair(-2, 44), Pair(-4, 42), Pair(0, 0),
        Pair(5, 71), Pair(-5, 61), Pair(-5, 76), Pair(-8, 73), Pair(-1, 49), Pair(-10, 50), Pair(-3, 43), Pair(-8, 7)
      },
      { // Piece 2
        Pair(17, 25), Pair(63, 18), Pair(10, 25), Pair(30, 28), Pair(165, -5), Pair(3, 57), Pair(46, 59), Pair(-47, 69),
        Pair(4, 43), Pair(9, 41), Pair(19, 28), Pair(96, 5), Pair(20, 26), Pair(26, 35), Pair(7, 45), Pair(-6, 47),
        Pair(11, 43), Pair(5, 49), Pair(16, 37), Pair(5, 33), Pair(9, 39), Pair(19, 39), Pair(19, 27), Pair(0, 40),
        Pair(12, 46), Pair(15, 40), Pair(15, 38), Pair(8, 39), Pair(9, 38), Pair(15, 37), Pair(-5, 50), Pair(6, 51),
        Pair(12, 45), Pair(8, 44), Pair(17, 41), Pair(11, 46), Pair(7, 52), Pair(-6, 47), Pair(24, 40), Pair(5, 52),
        Pair(4, 57), Pair(2, 53), Pair(5, 55), Pair(9, 50), Pair(7, 56), Pair(0, 53), Pair(2, 54), Pair(1, 32),
        Pair(16, 24), Pair(6, 60), Pair(7, 50), Pair(4, 56), Pair(5, 63), Pair(5, 59), Pair(3, 43), Pair(0, 0),
        Pair(20, 52), Pair(1, 31), Pair(4, 53), Pair(0, 59), Pair(13, 44), Pair(8, 54), Pair(30, 69), Pair(13, 38)
      },
      { // Piece 3
        Pair(23, 87), Pair(18, 81), Pair(21, 89), Pair(17, 94), Pair(29, 83), Pair(32, 82), Pair(14, 85), Pair(31, 49),
        Pair(10, 98), Pair(-1, 96), Pair(10, 100), Pair(14, 92), Pair(27, 75), Pair(25, 84), Pair(-27, 101), Pair(21, 56),
        Pair(10, 99), Pair(21, 90), Pair(8, 100), Pair(6, 93), Pair(14, 89), Pair(9, 84), Pair(-7, 94), Pair(-4, 71),
        Pair(5, 95), Pair(13, 99), Pair(9, 89), Pair(39, 80), Pair(9, 79), Pair(35, 77), Pair(6, 101), Pair(-3, 77),
        Pair(13, 92), Pair(0, 97), Pair(1, 100), Pair(26, 83), Pair(8, 91), Pair(8, 90), Pair(-2, 99), Pair(16, 57),
        Pair(22, 90), Pair(-5, 101), Pair(13, 91), Pair(2, 97), Pair(3, 92), Pair(2, 87), Pair(-1, 92), Pair(7, 41),
        Pair(6, 109), Pair(3, 104), Pair(12, 97), Pair(14, 91), Pair(0, 105), Pair(0, 100), Pair(10, 73), Pair(0, 0),
        Pair(15, 92), Pair(14, 97), Pair(13, 89), Pair(17, 81), Pair(17, 87), Pair(18, 93), Pair(-12, 104), Pair(-10, 44)
      },
      { // Piece 4
        Pair(10, 139), Pair(30, 132), Pair(23, 143), Pair(70, 120), Pair(-3, 179), Pair(59, 134), Pair(27, 172), Pair(-35, 202),
        Pair(15, 158), Pair(13, 140), Pair(21, 130), Pair(10, 157), Pair(10, 138), Pair(-4, 156), Pair(-13, 162), Pair(5, 136),
        Pair(19, 157), Pair(-3, 162), Pair(33, 139), Pair(37, 109), Pair(18, 140), Pair(29, 136), Pair(31, 157), Pair(1, 164),
        Pair(-1, 170), Pair(35, 113), Pair(11, 173), Pair(10, 165), Pair(-6, 175), Pair(9, 158), Pair(20, 157), Pair(7, 136),
        Pair(20, 152), Pair(13, 175), Pair(6, 168), Pair(12, 158), Pair(-1, 170), Pair(-4, 156), Pair(11, 138), Pair(0, 153),
        Pair(27, 145), Pair(21, 167), Pair(15, 163), Pair(14, 156), Pair(10, 162), Pair(3, 162), Pair(5, 166), Pair(-3, 170),
        Pair(22, 148), Pair(11, 167), Pair(16, 172), Pair(16, 168), Pair(14, 158), Pair(15, 127), Pair(6, 161), Pair(0, 0),
        Pair(23, 161), Pair(9, 184), Pair(13, 184), Pair(16, 175), Pair(13, 157), Pair(15, 153), Pair(15, 125), Pair(-7, 117)
      },
      { // Piece 5
        Pair(-37, -14), Pair(-259, 108), Pair(-132, 21), Pair(65, 22), Pair(-13, 61), Pair(-44, 125), Pair(39, 59), Pair(-53, 123),
        Pair(11, -2), Pair(-97, 70), Pair(47, 42), Pair(-186, 82), Pair(-115, 63), Pair(-18, 89), Pair(-112, 98), Pair(-73, 63),
        Pair(-223, 52), Pair(-41, 45), Pair(-10, 57), Pair(-33, 36), Pair(-159, 90), Pair(-37, 65), Pair(-97, 71), Pair(-159, 103),
        Pair(-60, 49), Pair(-113, 55), Pair(-95, 54), Pair(-93, 66), Pair(-140, 58), Pair(-27, 48), Pair(-7, 59), Pair(-21, 41),
        Pair(-131, 40), Pair(-84, 42), Pair(-135, 55), Pair(-90, 55), Pair(-53, 38), Pair(-10, 24), Pair(-11, 25), Pair(-58, 36),
        Pair(-98, 36), Pair(-82, 53), Pair(-73, 49), Pair(-15, 33), Pair(-1, 25), Pair(16, 9), Pair(-10, -18), Pair(-8, -10),
        Pair(-48, 20), Pair(-44, 31), Pair(-20, 36), Pair(-13, 25), Pair(7, 16), Pair(6, 5), Pair(-24, -28), Pair(0, 0),
        Pair(-57, 35), Pair(-30, 34), Pair(-24, 25), Pair(-20, 30), Pair(22, -9), Pair(20, -3), Pair(4, -29), Pair(28, -42)
      }
    }},
    {{ // Bucket 56
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 5
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
    {{ // Bucket 57
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 5
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
    {{ // Bucket 58
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 5
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
    {{ // Bucket 59
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 5
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
    {{ // Bucket 60
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 5
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
    {{ // Bucket 61
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 5
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
    {{ // Bucket 62
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 5
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
    {{ // Bucket 63
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 2
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 3
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 4
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 5
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
  }}
}};

constexpr PieceSquareTable<ScorePair> kNormalPieceSquareTable = {{
  {{
    {Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)},
    {Pair(-115, -56), Pair(-66, -79), Pair(-30, -63), Pair(25, -18), Pair(-20, -8), Pair(-37, -19), Pair(45, -53), Pair(-15, -58), Pair(-53, -38), Pair(-66, -15), Pair(-16, -4), Pair(111, -5), Pair(91, 8), Pair(82, -29), Pair(-32, -44), Pair(63, -40), Pair(-60, -43), Pair(-42, -34), Pair(8, -3), Pair(52, 8), Pair(95, -6), Pair(113, -3), Pair(50, -9), Pair(86, -43), Pair(-43, -44), Pair(-13, -26), Pair(11, 23), Pair(54, 30), Pair(67, 52), Pair(76, 17), Pair(64, 35), Pair(48, -6), Pair(-41, -51), Pair(-35, -22), Pair(9, 7), Pair(22, 35), Pair(54, 30), Pair(52, 31), Pair(73, 6), Pair(33, 14), Pair(-57, -77), Pair(-42, -26), Pair(-9, -4), Pair(1, 19), Pair(8, 33), Pair(6, 28), Pair(17, 17), Pair(-18, -26), Pair(-67, -36), Pair(-48, -48), Pair(-41, -26), Pair(-23, -11), Pair(-20, 1), Pair(-13, 20), Pair(-37, -8), Pair(-34, -14), Pair(-76, -84), Pair(-57, -84), Pair(-68, -31), Pair(-64, -31), Pair(-49, -20), Pair(-31, -8), Pair(-50, -51), Pair(-84, -56)},
    {Pair(17, -7), Pair(-57, 16), Pair(-92, 44), Pair(-85, 4), Pair(-43, 7), Pair(2, -25), Pair(-44, -16), Pair(24, -35), Pair(-21, 5), Pair(-24, 15), Pair(-35, 15), Pair(-33, 18), Pair(-33, 20), Pair(-25, -21), Pair(16, -12), Pair(-9, 4), Pair(-19, -26), Pair(-17, 11), Pair(10, 26), Pair(13, 7), Pair(-7, 46), Pair(76, 7), Pair(37, 8), Pair(21, 18), Pair(-37, -15), Pair(-5, 18), Pair(-8, 15), Pair(49, 30), Pair(48, 18), Pair(46, 16), Pair(17, 19), Pair(23, -9), Pair(-37, -19), Pair(-13, 4), Pair(24, 18), Pair(26, 30), Pair(57, 32), Pair(24, 18), Pair(15, 1), Pair(21, 7), Pair(-20, -21), Pair(12, -10), Pair(10, 9), Pair(15, 21), Pair(9, 9), Pair(7, 34), Pair(26, 22), Pair(22, 7), Pair(-10, -37), Pair(-4, -3), Pair(6, -12), Pair(-9, -8), Pair(-17, 7), Pair(-14, 1), Pair(23, 30), Pair(0, -8), Pair(-7, -33), Pair(4, -9), Pair(-24, -23), Pair(-41, -4), Pair(-48, 6), Pair(-22, -20), Pair(-24, -26), Pair(0, -6)},
    {Pair(58, 22), Pair(21, 31), Pair(21, 27), Pair(19, 22), Pair(64, 3), Pair(46, 22), Pair(5, 48), Pair(29, 47), Pair(12, 15), Pair(42, -5), Pair(48, -2), Pair(42, 2), Pair(47, 2), Pair(10, -7), Pair(40, -14), Pair(90, -14), Pair(11, -5), Pair(44, 0), Pair(43, -8), Pair(73, -17), Pair(68, -13), Pair(92, -20), Pair(70, -14), Pair(62, -8), Pair(0, 9), Pair(17, 3), Pair(28, -4), Pair(31, 6), Pair(38, 14), Pair(50, -7), Pair(38, -12), Pair(61, 5), Pair(-16, 8), Pair(6, 1), Pair(10, 5), Pair(19, 2), Pair(12, 10), Pair(39, 16), Pair(47, -6), Pair(40, 3), Pair(-25, 9), Pair(13, -2), Pair(1, -1), Pair(1, -4), Pair(9, 4), Pair(23, 2), Pair(39, 4), Pair(19, 2), Pair(-40, -17), Pair(-19, -7), Pair(-5, -18), Pair(-12, -4), Pair(-7, -5), Pair(5, 8), Pair(-8, 20), Pair(-61, 1), Pair(-3, -12), Pair(-3, -12), Pair(7, -2), Pair(5, 3), Pair(7, 6), Pair(15, 8), Pair(15, 7), Pair(-23, -14)},
    {Pair(28, -25), Pair(27, 7), Pair(46, -28), Pair(17, 2), Pair(28, -25), Pair(16, -16), Pair(15, -27), Pair(75, -60), Pair(16, 4), Pair(-17, -4), Pair(15, 4), Pair(25, 25), Pair(21, 33), Pair(79, -9), Pair(17, -30), Pair(76, -26), Pair(-16, -11), Pair(5, 13), Pair(0, 30), Pair(45, 67), Pair(58, 43), Pair(77, 66), Pair(76, 22), Pair(65, 42), Pair(-12, -3), Pair(11, -7), Pair(3, 26), Pair(15, 54), Pair(41, 53), Pair(71, 57), Pair(69, 46), Pair(67, 55), Pair(0, -30), Pair(2, 13), Pair(16, 31), Pair(21, 59), Pair(34, 60), Pair(48, 64), Pair(45, 52), Pair(63, 19), Pair(-14, -31), Pair(6, 11), Pair(13, 30), Pair(6, 21), Pair(13, 18), Pair(18, 39), Pair(37, 14), Pair(47, 5), Pair(-26, -16), Pair(-9, 4), Pair(-1, 12), Pair(2, 27), Pair(4, 13), Pair(0, 11), Pair(-5, -24), Pair(-23, -6), Pair(-10, -5), Pair(-36, -15), Pair(-26, -21), Pair(-6, -2), Pair(-16, -14), Pair(-27, -39), Pair(-14, -58), Pair(-43, 48)},
    {Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(-24, 4), Pair(9, 10), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(6, -1), Pair(-18, -26)}
  }},
  {{
    {Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)},
    {Pair(-132, -56), Pair(-91, -55), Pair(-134, -22), Pair(-84, -19), Pair(-38, -41), Pair(-25, -40), Pair(-76, -4), Pair(-54, -31), Pair(-32, -60), Pair(-74, -15), Pair(-7, -32), Pair(78, -22), Pair(85, -5), Pair(56, -24), Pair(-58, -15), Pair(58, -53), Pair(-73, -43), Pair(-21, -40), Pair(1, 11), Pair(40, -8), Pair(101, -8), Pair(104, -13), Pair(39, -14), Pair(60, -43), Pair(-29, -26), Pair(-9, -21), Pair(23, 9), Pair(45, 22), Pair(63, 43), Pair(72, 9), Pair(68, 12), Pair(45, -33), Pair(-26, -45), Pair(-21, -14), Pair(15, 9), Pair(23, 24), Pair(57, 16), Pair(59, 15), Pair(72, -12), Pair(31, -1), Pair(-41, -66), Pair(-31, -18), Pair(4, 6), Pair(-5, 24), Pair(16, 24), Pair(9, 27), Pair(13, -2), Pair(-25, -9), Pair(-27, -72), Pair(-49, -32), Pair(-22, -12), Pair(-17, -17), Pair(-11, 6), Pair(-1, 20), Pair(-47, -15), Pair(-39, -103), Pair(-65, -18), Pair(-47, -72), Pair(-68, -40), Pair(-54, -28), Pair(-47, -10), Pair(-51, -2), Pair(-51, -60), Pair(-63, -66)},
    {Pair(8, 9), Pair(-113, 18), Pair(26, -21), Pair(-74, 3), Pair(-127, 7), Pair(-77, -7), Pair(-28, -21), Pair(-22, 2), Pair(-40, -8), Pair(-30, 14), Pair(-58, 21), Pair(-39, 29), Pair(-46, 19), Pair(-33, 12), Pair(-6, 7), Pair(-26, -1), Pair(-27, -36), Pair(-31, 14), Pair(7, 28), Pair(5, 13), Pair(-6, 22), Pair(49, 3), Pair(23, 2), Pair(25, 5), Pair(-32, -18), Pair(-1, 10), Pair(-7, 10), Pair(40, 21), Pair(49, 17), Pair(43, 12), Pair(17, -1), Pair(22, -6), Pair(-43, -4), Pair(-5, 2), Pair(40, 6), Pair(26, 33), Pair(63, 22), Pair(29, 8), Pair(9, -13), Pair(12, -5), Pair(-18, -24), Pair(27, -14), Pair(10, 14), Pair(22, 17), Pair(13, 16), Pair(12, 30), Pair(13, 23), Pair(-5, -16), Pair(4, -53), Pair(6, 2), Pair(24, -14), Pair(-5, 8), Pair(-9, 2), Pair(-17, 24), Pair(6, 20), Pair(-17, -16), Pair(-17, -11), Pair(5, 4), Pair(-27, -9), Pair(-42, -6), Pair(-40, 5), Pair(-34, -27), Pair(-55, 1), Pair(-28, 3)},
    {Pair(52, 24), Pair(11, 22), Pair(37, 0), Pair(-14, 28), Pair(8, 29), Pair(-51, 65), Pair(-19, 50), Pair(-18, 50), Pair(2, 9), Pair(38, -17), Pair(29, -10), Pair(30, -4), Pair(57, -10), Pair(25, -17), Pair(-11, -11), Pair(80, -15), Pair(2, -1), Pair(39, 0), Pair(12, -6), Pair(44, -12), Pair(88, -39), Pair(43, -12), Pair(64, -12), Pair(19, 4), Pair(1, 3), Pair(14, -10), Pair(-3, 3), Pair(12, 2), Pair(14, 15), Pair(33, -1), Pair(10, -12), Pair(30, 11), Pair(-28, 8), Pair(-8, 2), Pair(0, 7), Pair(-4, 4), Pair(12, 3), Pair(27, 12), Pair(-11, 19), Pair(27, 9), Pair(-27, -1), Pair(4, -5), Pair(-19, 5), Pair(-13, -1), Pair(2, -4), Pair(-2, 11), Pair(18, 6), Pair(15, -2), Pair(-48, -18), Pair(-33, -6), Pair(-26, -3), Pair(-37, -12), Pair(-10, -12), Pair(-16, 21), Pair(-39, 3), Pair(-56, -2), Pair(-7, -28), Pair(-17, -20), Pair(-8, -14), Pair(-9, -6), Pair(-4, -8), Pair(-19, -9), Pair(-16, -33), Pair(-7, -32)},
    {Pair(22, -44), Pair(13, -12), Pair(-35, 14), Pair(-53, 21), Pair(10, -23), Pair(-130, 49), Pair(48, -67), Pair(2, -41), Pair(5, -29), Pair(-26, -36), Pair(-6, -15), Pair(-2, 10), Pair(23, -15), Pair(14, 11), Pair(-9, -14), Pair(43, -60), Pair(-25, -27), Pair(-9, -18), Pair(-15, 8), Pair(27, 26), Pair(35, 36), Pair(24, 59), Pair(55, -13), Pair(65, 2), Pair(-39, 2), Pair(-4, -16), Pair(-6, -3), Pair(7, 36), Pair(20, 34), Pair(53, 60), Pair(49, 28), Pair(49, -5), Pair(-13, -51), Pair(-10, -23), Pair(1, 32), Pair(1, 58), Pair(1, 83), Pair(37, 23), Pair(24, 41), Pair(45, 1), Pair(-30, -65), Pair(-6, -10), Pair(3, 14), Pair(-6, 5), Pair(-19, 56), Pair(1, 45), Pair(14, 14), Pair(23, 0), Pair(-35, -76), Pair(-25, -33), Pair(-7, -44), Pair(-13, -11), Pair(-15, -20), Pair(-28, 10), Pair(-33, -1), Pair(-33, -72), Pair(-25, -56), Pair(-45, -104), Pair(-31, -93), Pair(-20, -65), Pair(-52, -56), Pair(-82, 0), Pair(-32, -57), Pair(-21, -4)},
    {Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(4, -5), Pair(-47, -14), Pair(-9, -12), Pair(-47, 18), Pair(0, 0), Pair(0, 0)}
  }},
  {{
    {Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)},
    {Pair(-148, -75), Pair(-6, -57), Pair(-156, -17), Pair(-67, 4), Pair(-1, -25), Pair(29, -30), Pair(-42, -24), Pair(-50, -106), Pair(-53, -36), Pair(-90, -15), Pair(-30, 3), Pair(92, -4), Pair(83, 13), Pair(98, -30), Pair(-39, -14), Pair(-3, -24), Pair(-84, -32), Pair(-45, -24), Pair(5, 2), Pair(47, 9), Pair(84, 11), Pair(149, -15), Pair(87, -16), Pair(87, -50), Pair(-56, -31), Pair(-22, -13), Pair(11, 18), Pair(56, 25), Pair(77, 37), Pair(95, 7), Pair(78, 12), Pair(67, -20), Pair(-50, -39), Pair(-48, -4), Pair(5, 12), Pair(20, 31), Pair(56, 22), Pair(61, 21), Pair(89, -8), Pair(44, -2), Pair(-70, -50), Pair(-54, -9), Pair(-10, 12), Pair(-8, 29), Pair(18, 31), Pair(6, 33), Pair(6, 19), Pair(-11, 0), Pair(-69, -52), Pair(-54, -26), Pair(-47, -4), Pair(-29, -6), Pair(-16, 10), Pair(-8, 13), Pair(-30, -17), Pair(-32, -20), Pair(-169, -51), Pair(-68, -65), Pair(-89, -14), Pair(-71, -17), Pair(-68, -18), Pair(-54, -11), Pair(-52, -34), Pair(-23, -55)},
    {Pair(-68, 10), Pair(-52, 22), Pair(-109, 23), Pair(-97, 22), Pair(-56, 2), Pair(-62, 11), Pair(-119, -12), Pair(-39, -7), Pair(-31, 4), Pair(-24, 4), Pair(-41, 15), Pair(-46, 21), Pair(-28, 9), Pair(-53, 14), Pair(-36, 21), Pair(-16, -3), Pair(-31, -25), Pair(-37, 14), Pair(4, 19), Pair(0, 15), Pair(24, 17), Pair(69, 9), Pair(42, -3), Pair(28, 4), Pair(-43, -6), Pair(-13, 16), Pair(-7, 16), Pair(52, 19), Pair(57, 15), Pair(68, -3), Pair(21, 2), Pair(20, -12), Pair(-48, -9), Pair(-7, 2), Pair(21, 15), Pair(36, 31), Pair(57, 24), Pair(30, 19), Pair(27, 0), Pair(16, 18), Pair(-28, -19), Pair(3, -7), Pair(5, 12), Pair(14, 17), Pair(12, 15), Pair(13, 22), Pair(23, 16), Pair(17, -9), Pair(-12, -45), Pair(-6, -2), Pair(4, -12), Pair(-12, 3), Pair(-18, 3), Pair(-12, 3), Pair(28, 10), Pair(8, -22), Pair(-19, -21), Pair(-14, -5), Pair(-28, -13), Pair(-58, 1), Pair(-56, 9), Pair(-50, -21), Pair(-49, -14), Pair(-7, -6)},
    {Pair(26, 40), Pair(-5, 39), Pair(23, 22), Pair(36, 18), Pair(50, 13), Pair(25, 29), Pair(9, 43), Pair(34, 44), Pair(0, 14), Pair(34, -1), Pair(52, -4), Pair(58, -5), Pair(55, -2), Pair(49, -16), Pair(-1, 2), Pair(105, -14), Pair(4, 7), Pair(31, 6), Pair(32, -1), Pair(63, -10), Pair(73, -10), Pair(96, -18), Pair(80, -15), Pair(67, 1), Pair(-26, 22), Pair(-4, 14), Pair(5, 10), Pair(18, 12), Pair(33, 9), Pair(50, -1), Pair(43, 3), Pair(48, 21), Pair(-41, 26), Pair(-10, 17), Pair(-4, 17), Pair(5, 14), Pair(6, 18), Pair(54, 16), Pair(35, 16), Pair(39, 21), Pair(-29, 6), Pair(-20, 17), Pair(-10, -1), Pair(-5, -5), Pair(0, 9), Pair(17, 10), Pair(40, 10), Pair(6, 28), Pair(-58, -6), Pair(-33, -8), Pair(-17, -5), Pair(-17, -5), Pair(-20, 1), Pair(5, 2), Pair(-27, 16), Pair(-42, -19), Pair(-19, -2), Pair(-22, 6), Pair(-13, 11), Pair(-13, 11), Pair(-5, 6), Pair(-1, 9), Pair(-7, 5), Pair(-16, 12)},
    {Pair(9, -39), Pair(17, -17), Pair(50, -46), Pair(33, -12), Pair(7, -12), Pair(82, -79), Pair(127, -113), Pair(97, -114), Pair(-23, 2), Pair(-25, -26), Pair(-14, 3), Pair(13, 3), Pair(55, -2), Pair(67, -32), Pair(-3, -21), Pair(68, -55), Pair(-33, -24), Pair(-15, -8), Pair(3, 16), Pair(32, 57), Pair(68, 27), Pair(121, 0), Pair(95, -16), Pair(71, -12), Pair(-31, -26), Pair(-12, 3), Pair(-18, 22), Pair(-4, 56), Pair(33, 49), Pair(66, 64), Pair(64, 34), Pair(69, 18), Pair(-28, -35), Pair(-14, 2), Pair(-2, 36), Pair(13, 45), Pair(26, 43), Pair(44, 47), Pair(47, 27), Pair(57, -11), Pair(-32, -69), Pair(-10, -6), Pair(-3, 19), Pair(-10, 20), Pair(-8, 26), Pair(13, 6), Pair(22, -3), Pair(27, -27), Pair(-29, -80), Pair(-25, -16), Pair(-19, -5), Pair(-10, -1), Pair(-14, -3), Pair(-13, -7), Pair(-24, -44), Pair(-32, -46), Pair(-29, -9), Pair(-65, -11), Pair(-60, -1), Pair(-17, -23), Pair(-35, -25), Pair(-46, -34), Pair(-22, -19), Pair(-13, -34)},
    {Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(18, 3), Pair(29, 1), Pair(-18, 3), Pair(-33, 3), Pair(-43, 4), Pair(-27, 17), Pair(-3, 12), Pair(8, 4), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)}
  }},
  {{
    {Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)},
    {Pair(-149, -87), Pair(-52, -59), Pair(-118, -13), Pair(11, -9), Pair(-37, -26), Pair(-16, -43), Pair(56, -5), Pair(-28, -62), Pair(-74, -35), Pair(-97, -11), Pair(-78, 11), Pair(42, 6), Pair(126, 5), Pair(45, -15), Pair(-27, -1), Pair(-19, -31), Pair(-114, -35), Pair(-46, -22), Pair(43, 1), Pair(50, 19), Pair(103, 5), Pair(117, -9), Pair(48, -6), Pair(108, -41), Pair(-78, -23), Pair(2, -19), Pair(48, 14), Pair(61, 21), Pair(93, 24), Pair(77, 12), Pair(107, -2), Pair(105, -35), Pair(-37, -30), Pair(-18, -8), Pair(2, 16), Pair(50, 28), Pair(82, 19), Pair(85, 21), Pair(95, -1), Pair(65, -8), Pair(-96, -31), Pair(-52, 1), Pair(10, 10), Pair(19, 21), Pair(8, 40), Pair(41, 13), Pair(-21, 22), Pair(25, -23), Pair(-165, -31), Pair(-116, -11), Pair(-69, 2), Pair(-39, 3), Pair(-20, 15), Pair(6, 13), Pair(-35, -4), Pair(-18, -40), Pair(-14, -67), Pair(-130, -38), Pair(-126, 0), Pair(-87, -21), Pair(-140, -1), Pair(-111, -8), Pair(-99, -27), Pair(-8, -57)},
    {Pair(-175, 10), Pair(-34, -1), Pair(-91, 28), Pair(-120, 16), Pair(-90, 3), Pair(-58, -4), Pair(9, -19), Pair(-102, 0), Pair(-62, 1), Pair(-35, 11), Pair(-42, 12), Pair(-83, 23), Pair(-101, 21), Pair(-43, 2), Pair(-32, 11), Pair(-38, 4), Pair(-46, -23), Pair(7, -3), Pair(8, 14), Pair(18, 10), Pair(32, 24), Pair(73, 3), Pair(40, -6), Pair(63, -10), Pair(-47, -6), Pair(-3, 11), Pair(17, 12), Pair(73, 10), Pair(57, 16), Pair(51, 4), Pair(57, -4), Pair(9, -10), Pair(-82, -7), Pair(6, -3), Pair(49, 6), Pair(35, 34), Pair(75, 21), Pair(46, 17), Pair(41, -8), Pair(-4, 12), Pair(-21, -28), Pair(-5, -4), Pair(7, 12), Pair(1, 16), Pair(27, 12), Pair(12, 20), Pair(30, 17), Pair(19, -15), Pair(-39, -34), Pair(1, -4), Pair(6, -9), Pair(9, -4), Pair(-5, -3), Pair(-23, 1), Pair(15, 7), Pair(-15, -18), Pair(-63, -5), Pair(-6, -15), Pair(-42, -6), Pair(-75, 1), Pair(-34, 2), Pair(-63, -15), Pair(-80, -14), Pair(-56, 4)},
    {Pair(44, 38), Pair(9, 36), Pair(12, 27), Pair(7, 23), Pair(59, 9), Pair(61, 17), Pair(68, 16), Pair(43, 38), Pair(43, 2), Pair(47, -6), Pair(31, 3), Pair(77, -14), Pair(62, -1), Pair(30, -5), Pair(55, -10), Pair(84, -6), Pair(-16, 15), Pair(-1, 17), Pair(54, -5), Pair(66, -8), Pair(65, -8), Pair(88, -7), Pair(20, 11), Pair(57, 1), Pair(-34, 27), Pair(13, 8), Pair(-2, 14), Pair(36, 9), Pair(29, 14), Pair(52, 7), Pair(36, 10), Pair(47, 23), Pair(-56, 34), Pair(-39, 29), Pair(-2, 15), Pair(-24, 26), Pair(-5, 24), Pair(17, 32), Pair(-12, 37), Pair(22, 25), Pair(-64, 15), Pair(-38, 22), Pair(-16, 2), Pair(-43, 7), Pair(-32, 19), Pair(-7, 17), Pair(-1, 21), Pair(-9, 16), Pair(-80, 9), Pair(-57, 3), Pair(-40, 3), Pair(-24, -6), Pair(-42, 12), Pair(-17, 11), Pair(-42, 14), Pair(-113, 35), Pair(-48, 14), Pair(-58, 23), Pair(-45, 30), Pair(-44, 28), Pair(-29, 20), Pair(-17, 22), Pair(-62, 35), Pair(-23, 15)},
    {Pair(-94, -32), Pair(22, -73), Pair(-62, -11), Pair(74, -98), Pair(-12, -47), Pair(43, -116), Pair(-79, -63), Pair(-49, -74), Pair(-94, -21), Pair(-154, 12), Pair(-53, -31), Pair(-75, 41), Pair(38, -32), Pair(73, -51), Pair(-130, 30), Pair(15, -90), Pair(-108, -25), Pair(-114, 3), Pair(-27, 6), Pair(-19, 43), Pair(27, 14), Pair(41, 11), Pair(51, -13), Pair(19, -65), Pair(-106, -23), Pair(-126, 15), Pair(-41, 2), Pair(-81, 73), Pair(-13, 29), Pair(0, 63), Pair(16, 3), Pair(-22, 32), Pair(-93, -49), Pair(-82, -24), Pair(-74, 34), Pair(-22, 30), Pair(-13, 40), Pair(3, 22), Pair(3, 4), Pair(-29, -17), Pair(-118, -90), Pair(-93, -1), Pair(-73, 0), Pair(-70, -12), Pair(-66, 8), Pair(-81, 43), Pair(-43, -35), Pair(-23, -118), Pair(-97, -105), Pair(-89, -45), Pair(-56, -44), Pair(-56, -5), Pair(-49, -30), Pair(-81, 18), Pair(-105, -40), Pair(-65, -85), Pair(-103, -25), Pair(-156, 0), Pair(-59, -95), Pair(-79, -45), Pair(-113, -13), Pair(-166, 33), Pair(-124, -18), Pair(-31, -85)},
    {Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(-46, -12), Pair(13, -1), Pair(41, -7), Pair(25, -4), Pair(0, 10), Pair(29, 3), Pair(10, 4), Pair(-50, -5), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)}
  }},
  {{
    {Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)},
    {Pair(-102, -97), Pair(16, -72), Pair(-122, -14), Pair(33, -45), Pair(23, -27), Pair(-89, -31), Pair(33, -64), Pair(-57, -23), Pair(-150, -20), Pair(-92, -17), Pair(-9, 2), Pair(136, -19), Pair(105, 10), Pair(107, -28), Pair(-21, -11), Pair(64, -46), Pair(-54, -47), Pair(-47, -21), Pair(40, 3), Pair(30, 21), Pair(146, -4), Pair(128, -6), Pair(84, -24), Pair(152, -49), Pair(30, -36), Pair(42, -24), Pair(56, 17), Pair(114, 10), Pair(128, 23), Pair(115, 12), Pair(191, -23), Pair(182, -47), Pair(-79, -45), Pair(-3, -12), Pair(56, 2), Pair(89, 20), Pair(108, 5), Pair(118, 13), Pair(80, -2), Pair(70, -22), Pair(-128, -52), Pair(-77, -4), Pair(-4, 5), Pair(39, 17), Pair(9, 29), Pair(82, 10), Pair(-13, 13), Pair(-25, -22), Pair(-33, -71), Pair(-7, -47), Pair(29, -28), Pair(4, -23), Pair(-53, 22), Pair(-15, -10), Pair(41, -44), Pair(-49, -49), Pair(-53, -109), Pair(-156, -59), Pair(-174, -4), Pair(-69, -20), Pair(-79, -11), Pair(-177, -6), Pair(-100, -50), Pair(-37, -66)},
    {Pair(-43, -24), Pair(6, -16), Pair(21, -22), Pair(-42, -8), Pair(42, -26), Pair(-88, -20), Pair(-9, -38), Pair(-85, -31), Pair(32, -15), Pair(15, -22), Pair(-6, -18), Pair(2, -12), Pair(67, -14), Pair(52, -32), Pair(89, -16), Pair(3, -25), Pair(10, -32), Pair(19, -21), Pair(64, -5), Pair(92, -13), Pair(134, -16), Pair(117, -12), Pair(139, -39), Pair(24, -1), Pair(-30, -23), Pair(60, -11), Pair(63, -6), Pair(163, -16), Pair(132, -5), Pair(137, -20), Pair(87, -18), Pair(70, -29), Pair(18, -29), Pair(21, -11), Pair(81, -13), Pair(113, 5), Pair(151, 0), Pair(83, 1), Pair(63, -18), Pair(52, -14), Pair(-28, -36), Pair(97, -37), Pair(34, -2), Pair(74, -11), Pair(25, 4), Pair(44, -2), Pair(24, 9), Pair(-19, -18), Pair(-26, -56), Pair(-1, -15), Pair(-12, -10), Pair(-38, -6), Pair(8, -24), Pair(-57, -14), Pair(21, -5), Pair(102, -71), Pair(-27, -33), Pair(-14, -33), Pair(-42, -17), Pair(-4, -23), Pair(-30, -6), Pair(-54, -36), Pair(70, -56), Pair(78, -51)},
    {Pair(34, 28), Pair(12, 25), Pair(68, 2), Pair(88, -8), Pair(46, 9), Pair(125, -9), Pair(55, 7), Pair(109, 7), Pair(58, -7), Pair(93, -22), Pair(56, -16), Pair(148, -41), Pair(63, -19), Pair(39, -13), Pair(80, -17), Pair(176, -34), Pair(42, -3), Pair(58, -5), Pair(90, -27), Pair(96, -20), Pair(97, -24), Pair(94, -13), Pair(56, -2), Pair(34, 11), Pair(-14, 16), Pair(50, -7), Pair(4, 8), Pair(53, -3), Pair(26, 11), Pair(86, -2), Pair(89, -7), Pair(-12, 38), Pair(-17, 3), Pair(-9, 3), Pair(25, -16), Pair(-31, 8), Pair(-2, 11), Pair(47, -1), Pair(-97, 57), Pair(-57, 23), Pair(-62, 12), Pair(-56, 14), Pair(-89, 17), Pair(-54, 14), Pair(-52, 19), Pair(-37, 13), Pair(-31, 26), Pair(-95, 54), Pair(-91, 5), Pair(-118, 25), Pair(-53, 0), Pair(-77, 3), Pair(-76, 19), Pair(-56, 9), Pair(-112, 36), Pair(-162, 27), Pair(-74, 17), Pair(-103, 32), Pair(-67, 27), Pair(-44, 15), Pair(-22, 3), Pair(-82, 31), Pair(-127, 45), Pair(-106, 40)},
    {Pair(-106, -47), Pair(-62, -52), Pair(-14, -115), Pair(25, -116), Pair(-82, -24), Pair(-6, -95), Pair(-46, -85), Pair(-145, -28), Pair(-131, -42), Pair(-64, -22), Pair(-78, -65), Pair(-100, 21), Pair(-35, -13), Pair(-150, 44), Pair(3, -87), Pair(-111, -54), Pair(-63, -126), Pair(-118, -7), Pair(70, -51), Pair(-92, 54), Pair(16, -7), Pair(15, 14), Pair(-62, -32), Pair(-30, -63), Pair(-123, -72), Pair(-118, -39), Pair(-139, 7), Pair(-71, 33), Pair(53, -44), Pair(22, 10), Pair(-37, -26), Pair(129, -107), Pair(-96, -112), Pair(-147, -38), Pair(-148, 14), Pair(-99, 37), Pair(-80, 12), Pair(-112, 46), Pair(15, -103), Pair(-135, -62), Pair(-181, -132), Pair(-153, -46), Pair(-161, 26), Pair(-108, -27), Pair(-70, -26), Pair(-125, -5), Pair(-144, -30), Pair(9, -83), Pair(-173, -74), Pair(-150, -42), Pair(-165, -8), Pair(-160, 22), Pair(-115, -31), Pair(-102, -94), Pair(-192, -27), Pair(-118, -120), Pair(-97, -163), Pair(-126, -104), Pair(-74, -94), Pair(-91, -97), Pair(-151, -59), Pair(-135, -43), Pair(-33, -45), Pair(-63, -138)},
    {Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(-44, -9), Pair(68, -17), Pair(108, -17), Pair(46, -3), Pair(17, 7), Pair(53, 1), Pair(54, -15), Pair(-51, -20), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)}
  }},
  {{
    {Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)},
    {Pair(-21, -128), Pair(113, -67), Pair(-39, -57), Pair(87, -84), Pair(76, -71), Pair(-51, -43), Pair(-34, -31), Pair(50, 18), Pair(41, -82), Pair(10, -56), Pair(20, -40), Pair(-3, -7), Pair(96, -10), Pair(121, -46), Pair(66, -35), Pair(-31, -50), Pair(-28, -63), Pair(-72, -28), Pair(161, -27), Pair(138, -14), Pair(246, -21), Pair(217, -26), Pair(135, -35), Pair(101, -57), Pair(-53, -42), Pair(62, -34), Pair(122, -15), Pair(89, 7), Pair(129, 5), Pair(235, -23), Pair(191, -42), Pair(62, -41), Pair(-46, -58), Pair(0, -30), Pair(52, -12), Pair(143, -10), Pair(166, -13), Pair(179, -14), Pair(132, -37), Pair(78, -37), Pair(-77, -73), Pair(-41, -29), Pair(107, -24), Pair(44, -2), Pair(54, -5), Pair(49, -5), Pair(55, -31), Pair(44, -38), Pair(-115, -62), Pair(-112, -43), Pair(-66, -24), Pair(-121, -10), Pair(-27, -6), Pair(14, -36), Pair(16, -35), Pair(-45, -66), Pair(30, -91), Pair(-223, -53), Pair(-141, -35), Pair(-113, -62), Pair(0, -39), Pair(-83, -57), Pair(-145, -67), Pair(-11, -81)},
    {Pair(70, -58), Pair(102, -56), Pair(89, -51), Pair(39, -47), Pair(73, -74), Pair(-36, -50), Pair(82, -96), Pair(6, -59), Pair(-116, -38), Pair(72, -56), Pair(126, -55), Pair(176, -63), Pair(29, -37), Pair(220, -72), Pair(59, -42), Pair(42, -64), Pair(25, -65), Pair(159, -61), Pair(170, -46), Pair(142, -46), Pair(140, -43), Pair(229, -48), Pair(255, -70), Pair(39, -37), Pair(54, -56), Pair(83, -44), Pair(212, -53), Pair(205, -45), Pair(208, -44), Pair(287, -70), Pair(191, -59), Pair(130, -66), Pair(-63, -49), Pair(63, -50), Pair(186, -53), Pair(210, -48), Pair(247, -53), Pair(227, -53), Pair(220, -76), Pair(4, -19), Pair(33, -80), Pair(112, -68), Pair(90, -46), Pair(164, -63), Pair(134, -48), Pair(113, -45), Pair(134, -44), Pair(30, -65), Pair(-100, -70), Pair(-54, -37), Pair(90, -70), Pair(32, -47), Pair(59, -58), Pair(-18, -53), Pair(-12, -31), Pair(28, -103), Pair(-3, -70), Pair(31, -62), Pair(-86, -23), Pair(-7, -47), Pair(-75, -29), Pair(-85, -50), Pair(57, -79), Pair(52, -77)},
    {Pair(128, -24), Pair(140, -32), Pair(140, -41), Pair(86, -30), Pair(1, -13), Pair(155, -46), Pair(94, -15), Pair(192, -36), Pair(129, -44), Pair(153, -53), Pair(163, -59), Pair(203, -71), Pair(197, -72), Pair(112, -52), Pair(96, -42), Pair(177, -55), Pair(60, -34), Pair(111, -43), Pair(81, -47), Pair(138, -67), Pair(106, -54), Pair(230, -77), Pair(143, -53), Pair(97, -33), Pair(53, -25), Pair(50, -37), Pair(18, -34), Pair(65, -34), Pair(64, -33), Pair(134, -48), Pair(35, -15), Pair(42, -17), Pair(-21, -23), Pair(-50, 0), Pair(78, -37), Pair(18, -21), Pair(-20, -16), Pair(62, -29), Pair(38, -15), Pair(0, 3), Pair(-84, 3), Pair(-8, -11), Pair(-110, -7), Pair(-10, -28), Pair(-60, -1), Pair(-9, -9), Pair(9, -6), Pair(-126, 20), Pair(-104, -7), Pair(-30, -39), Pair(-12, -24), Pair(-142, 2), Pair(-107, 2), Pair(-47, -12), Pair(-36, -3), Pair(-127, 5), Pair(-221, 34), Pair(-208, 48), Pair(-89, 7), Pair(-117, 5), Pair(-91, -5), Pair(-144, 21), Pair(-102, 12), Pair(-144, 27)},
    {Pair(-47, -113), Pair(-80, -63), Pair(7, -95), Pair(-65, -40), Pair(-72, -78), Pair(-58, -110), Pair(-108, -108), Pair(-56, -145), Pair(-63, -76), Pair(-153, -43), Pair(-70, -67), Pair(66, -51), Pair(12, -73), Pair(-67, -49), Pair(13, -98), Pair(-45, -104), Pair(-118, -91), Pair(-44, -111), Pair(-68, 27), Pair(-35, -4), Pair(-66, -8), Pair(62, -100), Pair(-56, -52), Pair(-17, -111), Pair(-97, -97), Pair(-142, -62), Pair(-79, -5), Pair(36, -67), Pair(-16, -6), Pair(-22, -35), Pair(-99, -26), Pair(-82, -66), Pair(-125, -76), Pair(-114, -35), Pair(-133, -72), Pair(-91, 3), Pair(-49, -5), Pair(-46, -53), Pair(-87, -41), Pair(-125, -85), Pair(-119, -106), Pair(-116, -22), Pair(-112, -22), Pair(-166, -77), Pair(-108, -76), Pair(-149, -70), Pair(-92, -81), Pair(-106, -140), Pair(-169, -164), Pair(-159, -79), Pair(-71, -62), Pair(-74, -53), Pair(-144, -134), Pair(-113, -72), Pair(-66, -80), Pair(-92, -158), Pair(-116, -124), Pair(-73, -72), Pair(-113, -88), Pair(-285, -21), Pair(-77, -114), Pair(-72, -128), Pair(-46, 0), Pair(-126, -123)},
    {Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(72, -22), Pair(120, 0), Pair(109, 2), Pair(135, -34), Pair(151, -27), Pair(142, -13), Pair(149, -9), Pair(-3, -14), Pair(117, -21), Pair(81, -4), Pair(77, 0), Pair(49, -2), Pair(109, -9), Pair(154, -8), Pair(99, -8), Pair(-10, -8), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)}
  }},
  {{
    {Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)},
    {Pair(-25, -71), Pair(-66, -46), Pair(18, -43), Pair(-29, -37), Pair(25, -26), Pair(-29, -29), Pair(23, 79), Pair(-14, -89), Pair(-35, -69), Pair(-7, -79), Pair(60, 1), Pair(1, 36), Pair(-24, 9), Pair(23, -32), Pair(-9, -10), Pair(-21, -93), Pair(18, -91), Pair(-38, -17), Pair(76, -25), Pair(93, 11), Pair(101, -8), Pair(42, 8), Pair(79, -27), Pair(-25, 3), Pair(-32, -42), Pair(-74, -44), Pair(80, -21), Pair(24, 27), Pair(110, 4), Pair(31, 10), Pair(39, 21), Pair(-21, -7), Pair(-45, -43), Pair(-51, -21), Pair(66, 10), Pair(-60, 4), Pair(108, 14), Pair(44, -3), Pair(22, -16), Pair(-19, 11), Pair(-31, -85), Pair(45, -17), Pair(-50, -20), Pair(8, 10), Pair(49, 4), Pair(-78, 12), Pair(72, 5), Pair(-31, -18), Pair(-16, -99), Pair(-47, -33), Pair(1, -61), Pair(-99, -11), Pair(-27, -13), Pair(33, -28), Pair(4, -1), Pair(-51, -33), Pair(-39, -176), Pair(-64, -54), Pair(-4, -34), Pair(36, -9), Pair(22, -29), Pair(-66, -17), Pair(-55, -41), Pair(-18, -92)},
    {Pair(-33, -51), Pair(-55, -60), Pair(25, -41), Pair(53, -52), Pair(-64, -14), Pair(-22, -50), Pair(-11, -81), Pair(1, -30), Pair(-13, -101), Pair(71, -56), Pair(-39, -55), Pair(37, -52), Pair(32, -7), Pair(62, -59), Pair(50, -51), Pair(54, 2), Pair(-7, -51), Pair(108, -48), Pair(25, -54), Pair(6, -28), Pair(90, -24), Pair(169, -46), Pair(38, -18), Pair(-22, -30), Pair(-16, -44), Pair(40, -14), Pair(136, -38), Pair(103, -45), Pair(109, -22), Pair(34, -46), Pair(65, -31), Pair(70, -69), Pair(54, -58), Pair(59, -26), Pair(125, -50), Pair(112, -23), Pair(83, -38), Pair(51, -19), Pair(6, -43), Pair(44, 54), Pair(17, -31), Pair(32, -28), Pair(55, -18), Pair(-77, -15), Pair(16, -49), Pair(25, -7), Pair(30, -39), Pair(-21, -36), Pair(-18, -74), Pair(26, -32), Pair(78, -74), Pair(-9, -37), Pair(69, -52), Pair(90, -10), Pair(-7, -59), Pair(-24, -22), Pair(28, 4), Pair(17, -25), Pair(-96, 5), Pair(-6, -63), Pair(-23, -33), Pair(-139, -18), Pair(-10, -147), Pair(51, -2)},
    {Pair(99, -22), Pair(-33, 6), Pair(86, -32), Pair(111, -60), Pair(89, -17), Pair(66, -21), Pair(-12, -16), Pair(158, -46), Pair(115, -68), Pair(89, -51), Pair(79, -57), Pair(39, -38), Pair(105, -36), Pair(51, -33), Pair(51, -65), Pair(88, -69), Pair(-1, -15), Pair(88, -42), Pair(-39, -11), Pair(98, -39), Pair(95, -34), Pair(82, -17), Pair(12, -24), Pair(28, -4), Pair(59, -15), Pair(-25, 11), Pair(45, -57), Pair(-83, 11), Pair(7, 9), Pair(78, -46), Pair(44, -14), Pair(-22, -8), Pair(64, -38), Pair(49, -23), Pair(8, -16), Pair(2, -18), Pair(104, -52), Pair(22, 6), Pair(81, 12), Pair(17, -1), Pair(2, -30), Pair(-44, -20), Pair(5, -44), Pair(10, -43), Pair(-91, 17), Pair(-26, 16), Pair(58, 20), Pair(-9, -21), Pair(-100, -33), Pair(68, -33), Pair(-91, -22), Pair(-21, -38), Pair(-28, 2), Pair(65, -54), Pair(-26, 24), Pair(-43, -19), Pair(-221, 50), Pair(24, -18), Pair(28, -29), Pair(-109, 0), Pair(16, -6), Pair(-27, 11), Pair(-71, 16), Pair(-91, 23)},
    {Pair(-4, -143), Pair(-35, -57), Pair(-28, -114), Pair(-20, -68), Pair(-18, -132), Pair(-88, -104), Pair(-59, -112), Pair(-4, -158), Pair(-3, 22), Pair(-61, -50), Pair(-12, -5), Pair(-68, -33), Pair(-47, 6), Pair(-20, 24), Pair(-68, -104), Pair(-40, -73), Pair(-2, -10), Pair(-15, -49), Pair(52, 8), Pair(42, 32), Pair(-12, 42), Pair(7, 35), Pair(-22, -46), Pair(-55, -90), Pair(53, -36), Pair(23, -65), Pair(2, 33), Pair(28, -2), Pair(12, -5), Pair(-26, -12), Pair(28, 29), Pair(-77, -110), Pair(-61, -100), Pair(55, -10), Pair(13, -49), Pair(15, -6), Pair(24, 28), Pair(-20, 35), Pair(0, -9), Pair(-43, -59), Pair(3, -47), Pair(-32, -46), Pair(-8, 6), Pair(-3, -41), Pair(-32, 11), Pair(-53, -38), Pair(-18, -35), Pair(-24, -69), Pair(-41, -87), Pair(-67, -83), Pair(-13, -43), Pair(3, 19), Pair(-68, -112), Pair(9, 37), Pair(-23, -44), Pair(-51, -90), Pair(-84, -113), Pair(-100, -153), Pair(-34, -53), Pair(-75, 3), Pair(-86, -146), Pair(-98, -107), Pair(-12, -75), Pair(-56, -76)},
    {Pair(-28, -38), Pair(19, -72), Pair(8, -35), Pair(2, -38), Pair(54, -39), Pair(55, -57), Pair(31, -38), Pair(71, -53), Pair(-18, -20), Pair(33, -19), Pair(85, -30), Pair(135, -54), Pair(141, -52), Pair(59, -18), Pair(89, -15), Pair(94, -49), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)}
  }}
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(14, 32), Pair(23, 19), Pair(25, 31), Pair(25, 39), Pair(26, 42), Pair(27, 45), Pair(29, 41), Pair(34, 33),
  Pair(35, 20)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(2, 2), Pair(9, -33), Pair(14, -13), Pair(17, 3), Pair(20, 15), Pair(23, 24), Pair(23, 28), Pair(23, 29),
  Pair(25, 30), Pair(31, 25), Pair(36, 18), Pair(53, 8), Pair(60, 17), Pair(71, -13)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-48, -99), Pair(-39, -93), Pair(-34, -52), Pair(-32, -24), Pair(-30, -6), Pair(-26, 0), Pair(-21, 8), Pair(-15, 11),
  Pair(-10, 15), Pair(-4, 18), Pair(0, 23), Pair(4, 25), Pair(13, 23), Pair(37, 8), Pair(81, -18)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-70, 266), Pair(-37, 197), Pair(-12, 112), Pair(-5, 107), Pair(-4, 128), Pair(-3, 149), Pair(-1, 170), Pair(0, 181),
  Pair(2, 192), Pair(3, 201), Pair(5, 206), Pair(5, 207), Pair(7, 207), Pair(10, 203), Pair(10, 200), Pair(12, 197),
  Pair(11, 189), Pair(15, 178), Pair(23, 159), Pair(35, 138), Pair(50, 109), Pair(55, 95), Pair(87, 56), Pair(90, 31),
  Pair(-7, 78), Pair(184, -42), Pair(118, -16), Pair(243, -77)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-30, -101), Pair(-22, -83), Pair(-6, -49), Pair(26, -9), Pair(25, 39), Pair(166, 173), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(6, 14), Pair(17, 21), Pair(25, 54), Pair(56, 113), Pair(153, 202), Pair(136, 304), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(8, -8), Pair(6, 22), Pair(18, 38), Pair(58, 75), Pair(250, 123), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-28, -65), Pair(-20, -17), Pair(1, 21), Pair(-24, -2), Pair(-18, -4), Pair(-9, -8), Pair(-14, 10), Pair(-18, -53)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-1, -8), Pair(-12, -13), Pair(-12, -7), Pair(-10, -5), Pair(-6, -7), Pair(-2, -12), Pair(-9, -8), Pair(1, -6)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
    Pair(8, -8), Pair(23, -8), Pair(26, -2), Pair(34, 0), Pair(37, -3), Pair(62, -11), Pair(71, -22), Pair(33, -20)
  },
  {
    Pair(-7, 11), Pair(2, 5), Pair(14, 0), Pair(22, 1), Pair(19, -2), Pair(24, -9), Pair(49, -26), Pair(3, -9)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(22, -13), Pair(40, -12), Pair(30, -14),
  Pair(53, -15), Pair(51, -17), Pair(51, -15),
  Pair(77, -6), Pair(0, 0), Pair(70, -5),
  Pair(41, 26), Pair(26, 20), Pair(44, 26)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-6, -10), Pair(-19, 7), Pair(-8, -8),
  Pair(-4, -6), Pair(-17, 5), Pair(-4, -6),
  Pair(0, -12), Pair(-12, -9), Pair(5, -14),
  Pair(19, -15), Pair(-3, -13), Pair(25, -16),
  Pair(73, -26), Pair(76, -24), Pair(66, -24),
  Pair(44, -23), Pair(-30, -66), Pair(52, -48),
  Pair(71, -93), Pair(0, 0), Pair(71, -89)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(-5, 84), Pair(-11, 74), Pair(-6, 60), Pair(1, 47), Pair(-1, 38), Pair(6, 32), Pair(11, 20)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-13, -4), Pair(-30, 29), Pair(-10, 57), Pair(-2, 69), Pair(8, 73), Pair(16, 81), Pair(18, 96)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-296, 128);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
    Pair(-48, -48), Pair(-26, -30), Pair(-23, -17), Pair(-50, -8), Pair(-21, -7), Pair(-44, -7), Pair(-39, -1), Pair(-26, -18)
  },
  {
    Pair(-56, 29), Pair(-15, 20), Pair(9, 13), Pair(-28, 25), Pair(-2, 15), Pair(-20, 14), Pair(-10, 24), Pair(-20, 23)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
    Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(0, 0), Pair(24, 0), Pair(41, -5), Pair(120, -29), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(0, 0), Pair(12, 2), Pair(37, -3), Pair(78, -11), Pair(114, -37), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(0, 0), Pair(29, -14), Pair(49, -14), Pair(81, -13), Pair(143, -24), Pair(200, -42), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(0, 0), Pair(10, 26), Pair(27, 55), Pair(55, 73), Pair(118, 64), Pair(163, 76), Pair(286, 37), Pair(429, 5)
  },
  {
    Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(41, 3), Pair(8, 7), Pair(33, -3), Pair(19, 25), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
    Pair(4, 32), Pair(10, 40)
  },
  {
    Pair(-42, -4), Pair(-26, -18)
  },
  {
    Pair(-27, 9), Pair(-20, -17)
  },
  {
    Pair(-71, 77), Pair(-61, 49)
  },
  {
    Pair(-61, 79), Pair(-60, 46)
  },
  {
    Pair(-16, 50), Pair(-26, 41)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(14, 35), Pair(12, 28), Pair(18, 31), Pair(11, 15), Pair(17, -4)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
    Pair(-10, -31), Pair(2, -7)
  },
  {
    Pair(-20, -10), Pair(-1, -30)
  },
  {
    Pair(-33, -48), Pair(-29, -70)
  },
  {
    Pair(-64, -27), Pair(-49, -48)
  },
  {
    Pair(-51, -30), Pair(-56, -4)
  },
  {
    Pair(-103, -20), Pair(-31, -67)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
    Pair(-10, -19), Pair(0, 1)
  },
  {
    Pair(-44, -37), Pair(-25, -57)
  },
  {
    Pair(-17, -37), Pair(-15, -45)
  },
  {
    Pair(-59, -23), Pair(-49, -48)
  },
  {
    Pair(-53, -7), Pair(-41, -39)
  },
  {
    Pair(-34, -23), Pair(-9, -47)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
    Pair(-2, -19), Pair(7, 4)
  },
  {
    Pair(-35, -25), Pair(0, -8)
  },
  {
    Pair(-31, -26), Pair(-5, -6)
  },
  {
    Pair(4, -17), Pair(3, -25)
  },
  {
    Pair(-58, -10), Pair(-45, -31)
  },
  {
    Pair(-9, -34), Pair(-3, -60)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(9, 73), Pair(60, 27), Pair(15, 47), Pair(11, 38), Pair(16, 26), Pair(54, 26), Pair(70, 34), Pair(97, 74),
  Pair(15, 31), Pair(20, 33), Pair(9, 34), Pair(17, 18), Pair(8, 28), Pair(9, 36), Pair(4, 37), Pair(49, 73),
  Pair(-8, 37), Pair(-4, 31), Pair(9, 28), Pair(7, 20), Pair(-11, 20), Pair(3, 31), Pair(2, 19), Pair(-8, 42)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-38, 19), Pair(30, -2), Pair(11, 18), Pair(21, 7), Pair(14, -26), Pair(45, -17), Pair(84, -8), Pair(-42, -19),
  Pair(-10, 79), Pair(13, 7), Pair(5, 25), Pair(12, 44), Pair(8, 19), Pair(-11, 34), Pair(17, -9), Pair(86, 40),
  Pair(31, 31), Pair(6, 9), Pair(15, 7), Pair(-8, 19), Pair(-26, 9), Pair(11, 21), Pair(2, -16), Pair(13, 25)
};

constexpr ScorePair kBishopPairBonus = Pair(27, 99);

constexpr ScorePair kTempoBonus = Pair(24, 26);


constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H