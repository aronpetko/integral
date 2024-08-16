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
  Pair(98, 113), Pair(401, 235), Pair(459, 296), Pair(624, 566), Pair(1235, 930), Pair(0, 0)
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
        Pair(0, 0), Pair(67, -19), Pair(37, -38), Pair(3, -6), Pair(23, -13), Pair(51, -12), Pair(7, 0), Pair(-28, 17),
        Pair(-50, 3), Pair(58, -24), Pair(33, -39), Pair(31, -33), Pair(14, -25), Pair(-16, -4), Pair(38, -13), Pair(-20, 8),
        Pair(-33, 0), Pair(11, -28), Pair(-6, -25), Pair(14, -37), Pair(-24, -1), Pair(36, -25), Pair(-39, -2), Pair(12, -19),
        Pair(0, -20), Pair(46, -43), Pair(15, -28), Pair(5, -24), Pair(7, -15), Pair(19, -22), Pair(3, -22), Pair(17, -25),
        Pair(-85, 71), Pair(17, -34), Pair(12, -35), Pair(9, -27), Pair(8, -23), Pair(20, -33), Pair(-13, -14), Pair(-4, -30),
        Pair(0, 0), Pair(10, 4), Pair(8, 3), Pair(21, -19), Pair(28, -30), Pair(14, -33), Pair(-19, -12), Pair(9, -30),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-30, -142), Pair(21, 61), Pair(268, -133), Pair(-16, -10), Pair(72, -97), Pair(362, -86), Pair(246, -107), Pair(175, -118),
        Pair(8, -56), Pair(43, -37), Pair(209, -61), Pair(155, -89), Pair(207, -79), Pair(71, -53), Pair(66, -30), Pair(221, -86),
        Pair(82, 11), Pair(161, -3), Pair(35, -7), Pair(12, -34), Pair(87, -64), Pair(-34, -38), Pair(135, -87), Pair(12, -63),
        Pair(42, 9), Pair(102, -42), Pair(137, -12), Pair(55, -44), Pair(58, -15), Pair(51, -48), Pair(134, -93), Pair(-68, -14),
        Pair(137, -98), Pair(153, -32), Pair(20, 22), Pair(46, 2), Pair(26, 18), Pair(59, -53), Pair(83, -53), Pair(19, -65),
        Pair(-32, 19), Pair(-13, 113), Pair(66, 14), Pair(121, -31), Pair(44, -28), Pair(46, -23), Pair(121, -48), Pair(-13, -99),
        Pair(0, 0), Pair(86, -74), Pair(37, 104), Pair(57, -29), Pair(72, -13), Pair(77, -66), Pair(81, -66), Pair(-9, -4),
        Pair(71, 161), Pair(-93, -43), Pair(294, 40), Pair(10, -16), Pair(82, -49), Pair(27, -52), Pair(-47, 15), Pair(121, -163)
      },
      { // Piece 2
        Pair(-49, -4), Pair(-179, 86), Pair(56, -39), Pair(-254, 67), Pair(79, 32), Pair(-246, 75), Pair(46, 26), Pair(-126, 232),
        Pair(-10, 126), Pair(6, -5), Pair(20, 45), Pair(10, -70), Pair(-5, 87), Pair(-85, 95), Pair(-155, 208), Pair(-39, -15),
        Pair(37, 62), Pair(-35, 99), Pair(31, -53), Pair(-55, 83), Pair(26, 63), Pair(-98, 213), Pair(-8, -5), Pair(7, -31),
        Pair(86, 51), Pair(25, -55), Pair(30, 43), Pair(14, 31), Pair(-64, 174), Pair(55, -12), Pair(-18, 84), Pair(-33, -21),
        Pair(-72, -13), Pair(36, 57), Pair(7, 66), Pair(-37, 214), Pair(114, -61), Pair(-11, 53), Pair(27, -35), Pair(-101, 15),
        Pair(44, 119), Pair(245, -38), Pair(-14, 216), Pair(7, 15), Pair(-4, 69), Pair(29, -18), Pair(42, 6), Pair(-18, 12),
        Pair(0, 0), Pair(-32, 239), Pair(13, 36), Pair(6, 81), Pair(-32, 25), Pair(-134, 79), Pair(11, -14), Pair(10, 41),
        Pair(113, 258), Pair(-39, 99), Pair(23, 86), Pair(51, -9), Pair(-54, 89), Pair(-21, 11), Pair(-57, 13), Pair(-138, 20)
      },
      { // Piece 3
        Pair(101, 96), Pair(71, 68), Pair(105, 22), Pair(15, 79), Pair(-140, 134), Pair(113, 26), Pair(338, -1), Pair(284, -35),
        Pair(83, 111), Pair(139, 32), Pair(36, 54), Pair(96, 44), Pair(20, 93), Pair(288, -44), Pair(191, -22), Pair(105, 22),
        Pair(149, 102), Pair(101, 9), Pair(-3, 64), Pair(-28, 57), Pair(66, 20), Pair(11, 59), Pair(58, 33), Pair(138, -1),
        Pair(78, 104), Pair(36, 64), Pair(-54, 38), Pair(55, 51), Pair(70, 1), Pair(91, -12), Pair(60, 39), Pair(32, 20),
        Pair(157, 79), Pair(76, 6), Pair(39, 15), Pair(64, -50), Pair(56, 12), Pair(111, -43), Pair(-57, 74), Pair(0, -4),
        Pair(83, 111), Pair(99, 24), Pair(89, 36), Pair(17, 54), Pair(103, 21), Pair(76, 36), Pair(127, -4), Pair(-44, 27),
        Pair(0, 0), Pair(20, 111), Pair(68, 70), Pair(77, 8), Pair(31, 59), Pair(44, 71), Pair(12, 153), Pair(-40, 93),
        Pair(84, 155), Pair(22, 5), Pair(54, 96), Pair(25, 107), Pair(28, 94), Pair(94, 90), Pair(69, 90), Pair(6, 136)
      },
      { // Piece 4
        Pair(140, 2), Pair(-60, 144), Pair(144, -62), Pair(38, 67), Pair(211, -37), Pair(94, 104), Pair(0, 57), Pair(154, -91),
        Pair(-39, 99), Pair(-101, 250), Pair(41, 54), Pair(86, 11), Pair(70, 100), Pair(123, 9), Pair(-41, 163), Pair(49, 99),
        Pair(64, 34), Pair(91, 101), Pair(95, 8), Pair(-88, 203), Pair(52, 93), Pair(81, 66), Pair(-33, 134), Pair(47, 120),
        Pair(81, 9), Pair(13, 3), Pair(-106, 211), Pair(-35, 122), Pair(18, 105), Pair(14, 32), Pair(89, 3), Pair(13, 106),
        Pair(119, -55), Pair(-25, 117), Pair(15, 47), Pair(7, 94), Pair(-65, 52), Pair(80, -6), Pair(19, 5), Pair(-39, 187),
        Pair(-18, 100), Pair(50, 133), Pair(47, 58), Pair(4, 21), Pair(-127, 232), Pair(13, 69), Pair(-63, 96), Pair(-16, 51),
        Pair(0, 0), Pair(-25, 102), Pair(13, -18), Pair(66, -8), Pair(-25, 46), Pair(59, -102), Pair(70, 104), Pair(-57, -97),
        Pair(-78, 55), Pair(-25, -57), Pair(45, 137), Pair(-2, 140), Pair(3, 45), Pair(-47, 75), Pair(-162, 86), Pair(-3, 263)
      },
      { // Piece 5
        Pair(11, 16), Pair(6, 63), Pair(-39, -49), Pair(81, -51), Pair(236, -84), Pair(5, -14), Pair(69, -48), Pair(14, -96),
        Pair(-102, -189), Pair(71, -13), Pair(-217, 86), Pair(-17, -61), Pair(-65, 42), Pair(347, -72), Pair(254, -65), Pair(113, -100),
        Pair(13, -93), Pair(-39, 57), Pair(-5, 49), Pair(-39, 79), Pair(47, 14), Pair(18, -35), Pair(184, -47), Pair(186, -60),
        Pair(-131, -12), Pair(-105, 66), Pair(-37, 24), Pair(53, 35), Pair(-20, 22), Pair(-61, -2), Pair(56, -16), Pair(196, -42),
        Pair(61, -34), Pair(-179, 76), Pair(66, 32), Pair(51, 12), Pair(95, 0), Pair(-7, -6), Pair(29, -10), Pair(93, -77),
        Pair(-231, 115), Pair(-18, 109), Pair(17, 62), Pair(-43, 45), Pair(18, 4), Pair(44, -28), Pair(-15, -38), Pair(71, -62),
        Pair(0, 0), Pair(-226, 238), Pair(-120, 102), Pair(-80, 81), Pair(-49, 19), Pair(-28, -33), Pair(-66, 24), Pair(-63, 16),
        Pair(137, 183), Pair(201, 134), Pair(-248, 150), Pair(-69, -20), Pair(-162, 11), Pair(58, -73), Pair(-39, -75), Pair(-31, -108)
      }
    }},
    {{ // Bucket 9
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-67, 18), Pair(0, 0), Pair(2, -10), Pair(37, -21), Pair(30, -7), Pair(-20, 11), Pair(-4, 8), Pair(-66, 30),
        Pair(-40, 15), Pair(18, -10), Pair(0, -8), Pair(37, -24), Pair(-20, 2), Pair(13, -19), Pair(35, -10), Pair(-20, 16),
        Pair(7, -19), Pair(9, -30), Pair(1, -28), Pair(4, -25), Pair(11, -16), Pair(-15, -8), Pair(5, -22), Pair(12, -2),
        Pair(23, -29), Pair(-25, 21), Pair(3, -11), Pair(-25, -24), Pair(-35, -11), Pair(-28, -10), Pair(-9, -20), Pair(-4, -11),
        Pair(23, -18), Pair(33, -34), Pair(39, -22), Pair(-14, -21), Pair(-9, -15), Pair(-24, -10), Pair(-14, -26), Pair(-7, -14),
        Pair(32, -15), Pair(0, 0), Pair(12, 8), Pair(35, -51), Pair(16, -26), Pair(3, -22), Pair(-14, -21), Pair(-1, -10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-71, 204), Pair(-114, -72), Pair(268, -134), Pair(-12, -13), Pair(17, -8), Pair(99, -27), Pair(30, -98), Pair(-15, 22),
        Pair(107, -113), Pair(-162, 2), Pair(104, -40), Pair(103, -80), Pair(102, -14), Pair(32, 97), Pair(-17, -30), Pair(130, 4),
        Pair(87, 55), Pair(84, 34), Pair(9, 31), Pair(-9, 19), Pair(-5, 29), Pair(79, -6), Pair(26, 11), Pair(-2, -56),
        Pair(-176, 136), Pair(46, 59), Pair(-75, 66), Pair(6, -39), Pair(53, 25), Pair(42, -13), Pair(44, 16), Pair(155, -45),
        Pair(70, 93), Pair(-30, 9), Pair(32, 63), Pair(25, 18), Pair(1, 69), Pair(7, 4), Pair(42, 9), Pair(-86, 37),
        Pair(-83, 246), Pair(-45, 51), Pair(-27, 139), Pair(-153, 114), Pair(2, 50), Pair(18, 33), Pair(18, 5), Pair(-51, -68),
        Pair(-61, -61), Pair(0, 0), Pair(48, 18), Pair(-50, 145), Pair(11, -9), Pair(81, -52), Pair(-50, -37), Pair(-50, -25),
        Pair(-22, -66), Pair(-21, 257), Pair(-281, 13), Pair(-16, 116), Pair(-10, -30), Pair(-21, 35), Pair(5, -165), Pair(-83, -24)
      },
      { // Piece 2
        Pair(-197, 132), Pair(35, -12), Pair(-226, 135), Pair(-68, 62), Pair(-586, 245), Pair(-53, 89), Pair(-36, 112), Pair(-195, 122),
        Pair(-4, 26), Pair(1, 130), Pair(48, 27), Pair(-288, 192), Pair(52, 59), Pair(-30, 120), Pair(6, 127), Pair(-64, 231),
        Pair(-39, 120), Pair(-94, 53), Pair(-90, 119), Pair(77, -19), Pair(-39, 131), Pair(56, 98), Pair(-39, 222), Pair(59, -24),
        Pair(-116, 50), Pair(-7, 113), Pair(-45, 23), Pair(-156, 141), Pair(64, 63), Pair(-98, 260), Pair(37, -41), Pair(39, 98),
        Pair(-16, 71), Pair(-72, 9), Pair(-19, 142), Pair(78, 72), Pair(-150, 252), Pair(-64, 21), Pair(-26, 100), Pair(10, -44),
        Pair(-78, 85), Pair(-63, 172), Pair(29, 32), Pair(-62, 234), Pair(50, 0), Pair(-33, 66), Pair(5, -3), Pair(1, 68),
        Pair(-47, 280), Pair(0, 0), Pair(-56, 243), Pair(-39, 69), Pair(-5, 39), Pair(17, 4), Pair(-47, 87), Pair(47, -22),
        Pair(23, -138), Pair(-60, 326), Pair(-21, 26), Pair(-76, 142), Pair(4, -43), Pair(-102, 116), Pair(-52, 23), Pair(-119, 124)
      },
      { // Piece 3
        Pair(90, 21), Pair(89, 88), Pair(-57, 90), Pair(116, 33), Pair(209, 6), Pair(206, 27), Pair(199, -3), Pair(352, -19),
        Pair(-50, 76), Pair(-13, 134), Pair(34, 51), Pair(79, 34), Pair(97, 18), Pair(148, 26), Pair(194, 27), Pair(-10, 81),
        Pair(2, 39), Pair(108, 126), Pair(-10, 18), Pair(55, -2), Pair(100, 6), Pair(123, 15), Pair(90, 15), Pair(47, 82),
        Pair(15, 29), Pair(109, 109), Pair(56, 33), Pair(-54, 106), Pair(-10, 50), Pair(-48, 79), Pair(202, -4), Pair(183, -42),
        Pair(59, 35), Pair(-36, 110), Pair(-13, 93), Pair(-56, 85), Pair(146, 34), Pair(-18, 99), Pair(8, 54), Pair(-31, 46),
        Pair(61, 6), Pair(15, 118), Pair(-16, -5), Pair(6, 48), Pair(-7, 44), Pair(23, 41), Pair(51, -29), Pair(102, 6),
        Pair(108, -84), Pair(0, 0), Pair(-1, 64), Pair(-106, 112), Pair(44, -11), Pair(106, 24), Pair(49, 39), Pair(63, -8),
        Pair(36, 50), Pair(39, 165), Pair(27, 3), Pair(-37, 111), Pair(-17, 108), Pair(8, 124), Pair(-9, 84), Pair(-35, 121)
      },
      { // Piece 4
        Pair(73, 73), Pair(14, 112), Pair(134, 57), Pair(112, -3), Pair(56, 111), Pair(12, 77), Pair(-63, 47), Pair(109, 31),
        Pair(-16, 76), Pair(-162, 257), Pair(-50, 173), Pair(-126, 119), Pair(-21, 159), Pair(-35, 193), Pair(36, 107), Pair(30, 47),
        Pair(-136, 250), Pair(-5, 118), Pair(-12, 80), Pair(-32, 116), Pair(4, 116), Pair(-38, 164), Pair(-38, 108), Pair(78, -79),
        Pair(-99, 125), Pair(-58, 173), Pair(-73, 105), Pair(116, -18), Pair(154, 59), Pair(30, 92), Pair(32, 120), Pair(139, -112),
        Pair(38, 67), Pair(-9, 131), Pair(-60, 141), Pair(-89, 117), Pair(-72, 145), Pair(1, 87), Pair(58, -24), Pair(42, -53),
        Pair(83, -143), Pair(58, 35), Pair(105, 5), Pair(-45, 119), Pair(43, -65), Pair(-55, 135), Pair(-30, -16), Pair(100, -248),
        Pair(-4, -5), Pair(0, 0), Pair(93, 28), Pair(11, 19), Pair(-3, 32), Pair(27, 89), Pair(113, 15), Pair(-36, 59),
        Pair(-204, 50), Pair(-16, 10), Pair(-49, -238), Pair(-24, 16), Pair(49, -68), Pair(-23, 59), Pair(-135, 152), Pair(-161, 278)
      },
      { // Piece 5
        Pair(-46, -123), Pair(-27, -103), Pair(11, 46), Pair(20, -138), Pair(98, -81), Pair(96, -154), Pair(100, -66), Pair(159, 26),
        Pair(30, -8), Pair(1, 93), Pair(54, -54), Pair(-71, -28), Pair(43, -15), Pair(-19, 17), Pair(159, -39), Pair(304, -26),
        Pair(-97, -74), Pair(42, -5), Pair(-45, -1), Pair(44, -19), Pair(-25, 25), Pair(-9, 17), Pair(107, -8), Pair(87, 1),
        Pair(-89, 11), Pair(-137, 24), Pair(-58, 29), Pair(132, 40), Pair(66, 2), Pair(-106, 40), Pair(-71, 17), Pair(-110, 23),
        Pair(-40, 31), Pair(-38, 51), Pair(125, 6), Pair(-104, 34), Pair(65, -1), Pair(105, -18), Pair(42, -22), Pair(105, -76),
        Pair(-3, 77), Pair(99, 42), Pair(-66, 121), Pair(-57, 35), Pair(-15, 13), Pair(4, -18), Pair(-58, -40), Pair(26, -104),
        Pair(-87, 196), Pair(0, 0), Pair(-48, 149), Pair(4, 32), Pair(-103, 16), Pair(-18, -13), Pair(21, -42), Pair(21, -82),
        Pair(-12, 22), Pair(48, 110), Pair(37, 107), Pair(-302, 73), Pair(-49, -34), Pair(13, -54), Pair(2, -100), Pair(74, -139)
      }
    }},
    {{ // Bucket 10
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-38, 38), Pair(-2, 10), Pair(0, 0), Pair(-13, 12), Pair(-3, 0), Pair(23, -10), Pair(27, 13), Pair(20, 17),
        Pair(-12, -11), Pair(-22, -6), Pair(24, 8), Pair(14, -6), Pair(31, -23), Pair(8, -19), Pair(-34, 17), Pair(1, 1),
        Pair(11, -11), Pair(-6, -24), Pair(33, -15), Pair(-8, -7), Pair(-7, 0), Pair(-35, -6), Pair(-36, 2), Pair(-16, -7),
        Pair(-31, -5), Pair(-2, -30), Pair(-21, -13), Pair(6, -15), Pair(26, -25), Pair(-19, -15), Pair(-12, -21), Pair(-33, -3),
        Pair(24, -21), Pair(17, -12), Pair(39, -5), Pair(-1, -9), Pair(0, -10), Pair(-8, -15), Pair(-27, -6), Pair(-28, -6),
        Pair(10, -21), Pair(29, -6), Pair(0, 0), Pair(-5, -43), Pair(-6, -14), Pair(-16, -17), Pair(-20, -15), Pair(-23, -7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-62, -36), Pair(72, -65), Pair(95, -12), Pair(303, -39), Pair(-30, -47), Pair(-140, -82), Pair(-69, 64), Pair(-167, -90),
        Pair(125, -114), Pair(-228, 86), Pair(-147, 72), Pair(-48, 32), Pair(72, -34), Pair(74, 42), Pair(131, -63), Pair(36, 14),
        Pair(-114, 115), Pair(54, 21), Pair(-27, 52), Pair(-53, 32), Pair(-31, 65), Pair(141, -53), Pair(42, 12), Pair(-45, 61),
        Pair(69, -14), Pair(-12, 42), Pair(-18, 49), Pair(-52, 109), Pair(62, 15), Pair(44, 24), Pair(18, -16), Pair(92, 39),
        Pair(30, 79), Pair(256, -27), Pair(14, -32), Pair(-22, 130), Pair(8, 24), Pair(8, 39), Pair(33, 5), Pair(-93, 41),
        Pair(101, 18), Pair(-131, 188), Pair(85, 25), Pair(-57, 172), Pair(4, 71), Pair(6, 53), Pair(-20, 72), Pair(31, -14),
        Pair(-54, 265), Pair(-105, 145), Pair(0, 0), Pair(51, -11), Pair(3, 171), Pair(24, 17), Pair(6, -20), Pair(28, -12),
        Pair(-23, 44), Pair(94, -257), Pair(118, 221), Pair(167, -66), Pair(-5, 150), Pair(173, -103), Pair(-24, 72), Pair(-66, -15)
      },
      { // Piece 2
        Pair(-101, 28), Pair(-33, 101), Pair(-303, 93), Pair(-40, 183), Pair(-50, 65), Pair(-98, 144), Pair(117, -20), Pair(-161, 161),
        Pair(-91, 98), Pair(-47, 23), Pair(-82, 153), Pair(-218, 131), Pair(-46, 141), Pair(-12, 73), Pair(-14, 190), Pair(258, 16),
        Pair(119, 44), Pair(22, 100), Pair(-71, 81), Pair(-56, 141), Pair(-64, 67), Pair(-93, 170), Pair(18, 146), Pair(-100, 208),
        Pair(-216, 157), Pair(-6, 75), Pair(92, 52), Pair(32, 33), Pair(-33, 134), Pair(110, 66), Pair(-77, 241), Pair(92, -4),
        Pair(229, 35), Pair(59, 42), Pair(54, 63), Pair(32, 128), Pair(115, 11), Pair(-62, 219), Pair(-1, 34), Pair(20, -2),
        Pair(-27, 235), Pair(-58, 117), Pair(95, 130), Pair(122, 71), Pair(-108, 244), Pair(17, 22), Pair(-55, 54), Pair(-70, -12),
        Pair(121, -69), Pair(9, 198), Pair(0, 0), Pair(-74, 221), Pair(19, 55), Pair(-62, 105), Pair(-4, 21), Pair(31, -79),
        Pair(-6, 156), Pair(13, 3), Pair(57, 288), Pair(-271, 49), Pair(56, 27), Pair(-29, 32), Pair(45, 73), Pair(97, -69)
      },
      { // Piece 3
        Pair(-73, 90), Pair(67, 15), Pair(199, 45), Pair(49, 50), Pair(185, 30), Pair(111, 14), Pair(285, -41), Pair(145, 42),
        Pair(84, 43), Pair(-52, 62), Pair(120, 99), Pair(97, 37), Pair(7, 89), Pair(43, 52), Pair(3, 66), Pair(146, 49),
        Pair(46, 20), Pair(45, 20), Pair(71, 108), Pair(-21, 91), Pair(72, 37), Pair(284, -71), Pair(55, 32), Pair(-112, 91),
        Pair(17, 46), Pair(22, 43), Pair(-3, 112), Pair(-40, 74), Pair(-86, 98), Pair(-5, 26), Pair(-26, 85), Pair(-98, 88),
        Pair(73, 54), Pair(114, -7), Pair(-43, 113), Pair(42, 63), Pair(47, 4), Pair(45, 29), Pair(22, 51), Pair(-53, 48),
        Pair(112, 28), Pair(144, 9), Pair(30, 140), Pair(-4, 86), Pair(111, -25), Pair(-23, 65), Pair(7, 4), Pair(136, -68),
        Pair(-45, 121), Pair(69, 80), Pair(0, 0), Pair(66, 115), Pair(114, 1), Pair(113, 38), Pair(-28, 103), Pair(22, 79),
        Pair(-16, 128), Pair(-17, 117), Pair(64, 188), Pair(19, 7), Pair(-4, 104), Pair(49, 118), Pair(36, 112), Pair(-52, 174)
      },
      { // Piece 4
        Pair(12, 12), Pair(142, -27), Pair(-194, 267), Pair(79, 77), Pair(125, -10), Pair(18, -26), Pair(88, 66), Pair(-15, 124),
        Pair(-11, 42), Pair(-21, 162), Pair(-42, 172), Pair(50, 53), Pair(-15, 105), Pair(78, 34), Pair(-12, 55), Pair(-12, 58),
        Pair(-58, 27), Pair(97, -23), Pair(0, 112), Pair(10, 34), Pair(-72, 175), Pair(132, -8), Pair(-5, 97), Pair(66, 6),
        Pair(-71, 184), Pair(64, -156), Pair(0, 109), Pair(-94, 127), Pair(33, 20), Pair(52, 61), Pair(130, -49), Pair(50, 29),
        Pair(-17, -14), Pair(-55, 59), Pair(83, -39), Pair(-36, 81), Pair(-1, 127), Pair(3, 111), Pair(2, 4), Pair(3, -73),
        Pair(-70, 132), Pair(99, -55), Pair(11, 36), Pair(-8, 15), Pair(-4, 13), Pair(53, -70), Pair(-61, 133), Pair(-34, 12),
        Pair(62, -124), Pair(-20, 76), Pair(0, 0), Pair(51, -80), Pair(-52, 95), Pair(41, 15), Pair(97, -200), Pair(-74, 72),
        Pair(-30, -58), Pair(55, -144), Pair(43, -9), Pair(46, -239), Pair(-111, 145), Pair(66, -59), Pair(-4, 4), Pair(144, 1)
      },
      { // Piece 5
        Pair(-23, 17), Pair(-10, -26), Pair(-29, -233), Pair(-9, 77), Pair(-31, -100), Pair(7, -75), Pair(136, -176), Pair(2, -33),
        Pair(47, -44), Pair(17, -54), Pair(-36, -33), Pair(-3, -21), Pair(-39, -22), Pair(-68, -47), Pair(-21, 5), Pair(-6, -92),
        Pair(-194, -34), Pair(-43, 56), Pair(-140, 12), Pair(137, 26), Pair(64, 15), Pair(49, 9), Pair(-97, 40), Pair(310, -75),
        Pair(60, -14), Pair(3, 39), Pair(231, -26), Pair(98, 35), Pair(-16, 79), Pair(-89, 34), Pair(78, -60), Pair(-32, -32),
        Pair(114, 28), Pair(77, 39), Pair(-35, 40), Pair(-85, 47), Pair(66, -18), Pair(27, -36), Pair(115, -39), Pair(34, -52),
        Pair(-127, 74), Pair(-53, 124), Pair(-196, 115), Pair(-15, 81), Pair(-33, 25), Pair(-34, 0), Pair(-77, -19), Pair(125, -121),
        Pair(126, -74), Pair(-130, 173), Pair(0, 0), Pair(-42, 117), Pair(16, 11), Pair(56, -50), Pair(-31, -48), Pair(-11, -100),
        Pair(-100, 54), Pair(275, -72), Pair(-97, 185), Pair(36, 60), Pair(-109, 25), Pair(20, -47), Pair(-18, -96), Pair(62, -128)
      }
    }},
    {{ // Bucket 11
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-3, 7), Pair(-38, 20), Pair(13, -12), Pair(0, 0), Pair(20, 27), Pair(20, 0), Pair(42, -8), Pair(17, 15),
        Pair(18, 0), Pair(-12, -17), Pair(-39, 16), Pair(12, -12), Pair(26, -12), Pair(10, -10), Pair(-16, 10), Pair(24, 6),
        Pair(7, -20), Pair(-17, -7), Pair(-7, -13), Pair(-10, -13), Pair(30, -16), Pair(-21, 6), Pair(-4, -13), Pair(-4, 9),
        Pair(3, -12), Pair(-10, -18), Pair(-18, -7), Pair(-13, -4), Pair(-6, -11), Pair(-41, 2), Pair(-19, -15), Pair(-4, -12),
        Pair(17, -25), Pair(15, -19), Pair(-5, -2), Pair(32, 16), Pair(10, -8), Pair(6, -5), Pair(-23, -11), Pair(10, -16),
        Pair(-1, -5), Pair(11, -6), Pair(11, -11), Pair(0, 0), Pair(5, 0), Pair(-6, -2), Pair(-2, -18), Pair(-5, -8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-89, 9), Pair(20, -34), Pair(-44, -9), Pair(-251, -10), Pair(-56, 13), Pair(70, -74), Pair(-20, -23), Pair(163, 11),
        Pair(86, -95), Pair(37, -17), Pair(-251, 52), Pair(-109, 46), Pair(99, -6), Pair(240, -42), Pair(48, 97), Pair(73, -62),
        Pair(-171, 131), Pair(32, -9), Pair(-35, 69), Pair(93, 7), Pair(9, -31), Pair(45, -9), Pair(61, -18), Pair(-243, 129),
        Pair(-77, 55), Pair(-23, 2), Pair(53, 14), Pair(60, -2), Pair(-22, 94), Pair(-10, 29), Pair(145, -54), Pair(38, -16),
        Pair(-117, 49), Pair(32, 26), Pair(-67, 118), Pair(38, 16), Pair(108, 22), Pair(53, 10), Pair(-35, 61), Pair(54, -26),
        Pair(-64, -6), Pair(5, 116), Pair(-11, 147), Pair(-111, 65), Pair(-81, 149), Pair(46, 56), Pair(-28, 12), Pair(-1, -21),
        Pair(-199, -2), Pair(-168, 228), Pair(18, 5), Pair(0, 0), Pair(27, -18), Pair(-31, 157), Pair(101, -32), Pair(-48, 201),
        Pair(-104, -20), Pair(113, -29), Pair(-111, 19), Pair(25, 204), Pair(118, -78), Pair(-22, 111), Pair(-19, 7), Pair(37, -33)
      },
      { // Piece 2
        Pair(-5, 48), Pair(-141, 123), Pair(-189, 107), Pair(24, -56), Pair(47, 149), Pair(-94, 43), Pair(35, 81), Pair(169, -93),
        Pair(-84, 58), Pair(41, 65), Pair(100, -62), Pair(47, 121), Pair(-24, 5), Pair(-33, 92), Pair(140, -12), Pair(6, 41),
        Pair(-8, -31), Pair(34, 52), Pair(-116, 132), Pair(195, -35), Pair(-111, 127), Pair(118, -49), Pair(-98, 138), Pair(-37, 108),
        Pair(66, 60), Pair(-142, 121), Pair(101, 7), Pair(-67, 92), Pair(10, 6), Pair(24, 112), Pair(21, 72), Pair(-85, 220),
        Pair(-112, 204), Pair(4, 100), Pair(34, 55), Pair(69, 32), Pair(31, 66), Pair(60, 60), Pair(-41, 203), Pair(-51, 49),
        Pair(53, -68), Pair(-33, 215), Pair(-9, 88), Pair(-12, 90), Pair(35, 87), Pair(-70, 194), Pair(-66, 79), Pair(-57, 114),
        Pair(59, 53), Pair(13, -28), Pair(-88, 236), Pair(0, 0), Pair(-79, 196), Pair(80, -31), Pair(3, 78), Pair(-33, 44),
        Pair(-18, -53), Pair(28, 101), Pair(44, -110), Pair(76, 260), Pair(-101, 75), Pair(-15, 89), Pair(-199, 116), Pair(-133, 133)
      },
      { // Piece 3
        Pair(122, 12), Pair(69, 30), Pair(-27, 57), Pair(30, 78), Pair(16, 55), Pair(295, 9), Pair(164, -19), Pair(102, 14),
        Pair(36, 0), Pair(-10, 72), Pair(61, 64), Pair(32, 73), Pair(-3, 39), Pair(195, 2), Pair(15, 46), Pair(87, 8),
        Pair(50, 21), Pair(-40, 62), Pair(88, 25), Pair(53, 82), Pair(-55, 108), Pair(177, 4), Pair(-9, 64), Pair(204, -21),
        Pair(36, 64), Pair(-97, 58), Pair(-71, 78), Pair(81, 80), Pair(84, 3), Pair(-32, 68), Pair(72, 19), Pair(236, -32),
        Pair(-48, 33), Pair(39, 11), Pair(73, -21), Pair(144, 65), Pair(110, -28), Pair(-10, 7), Pair(-62, 37), Pair(1, 32),
        Pair(-44, 78), Pair(37, 77), Pair(22, 33), Pair(-131, 134), Pair(-2, 34), Pair(122, -22), Pair(-98, 83), Pair(10, -25),
        Pair(124, -49), Pair(-27, 101), Pair(43, 61), Pair(0, 0), Pair(14, -1), Pair(55, 44), Pair(40, 45), Pair(-25, 62),
        Pair(-25, 108), Pair(-8, 121), Pair(13, 29), Pair(37, 162), Pair(-6, 40), Pair(-19, 118), Pair(14, 112), Pair(-94, 138)
      },
      { // Piece 4
        Pair(137, -169), Pair(-43, 56), Pair(-11, 26), Pair(-79, 183), Pair(113, -19), Pair(100, 31), Pair(179, -88), Pair(80, -43),
        Pair(72, -11), Pair(-15, 40), Pair(-19, 39), Pair(70, 76), Pair(4, 64), Pair(-31, 239), Pair(6, 31), Pair(145, -79),
        Pair(6, -1), Pair(-94, 218), Pair(-44, 35), Pair(73, 18), Pair(-24, 71), Pair(15, 100), Pair(178, -104), Pair(128, -53),
        Pair(39, 15), Pair(100, -97), Pair(57, -37), Pair(128, 32), Pair(78, -119), Pair(45, 12), Pair(1, -31), Pair(-17, 75),
        Pair(-53, 15), Pair(-23, -4), Pair(79, -51), Pair(125, 24), Pair(112, -33), Pair(143, -64), Pair(73, 14), Pair(81, 35),
        Pair(-64, 87), Pair(-2, 45), Pair(-91, 100), Pair(72, 48), Pair(96, -81), Pair(-57, 154), Pair(111, -154), Pair(11, -72),
        Pair(73, -211), Pair(165, -260), Pair(58, 31), Pair(0, 0), Pair(102, -61), Pair(-7, 37), Pair(-99, 76), Pair(-19, 93),
        Pair(-250, 158), Pair(-43, 15), Pair(-263, 166), Pair(32, -81), Pair(-163, -187), Pair(-42, 5), Pair(4, -73), Pair(-3, 150)
      },
      { // Piece 5
        Pair(14, -35), Pair(17, -42), Pair(7, 112), Pair(-27, -110), Pair(-35, -57), Pair(-59, -76), Pair(-25, -58), Pair(-28, -55),
        Pair(35, -75), Pair(-55, -121), Pair(41, -91), Pair(-14, -50), Pair(-39, -25), Pair(-76, 7), Pair(-104, 14), Pair(12, -63),
        Pair(-14, -13), Pair(18, -24), Pair(63, -39), Pair(-60, -1), Pair(176, -18), Pair(48, 19), Pair(54, -10), Pair(6, 1),
        Pair(-60, -63), Pair(180, -19), Pair(217, -16), Pair(-269, 34), Pair(55, 48), Pair(46, -7), Pair(5, 24), Pair(38, -38),
        Pair(-90, 19), Pair(50, -13), Pair(-104, 36), Pair(-1, 26), Pair(-165, 26), Pair(29, -24), Pair(42, -50), Pair(18, -78),
        Pair(44, 23), Pair(55, 30), Pair(-129, 95), Pair(-99, 43), Pair(17, 54), Pair(58, -20), Pair(50, -27), Pair(88, -133),
        Pair(-64, -2), Pair(-42, 64), Pair(-35, 78), Pair(0, 0), Pair(-96, 92), Pair(48, -13), Pair(-6, -43), Pair(1, -45),
        Pair(-71, -60), Pair(-19, -3), Pair(-52, -49), Pair(-3, 102), Pair(89, 100), Pair(37, -20), Pair(-22, -72), Pair(9, -107)
      }
    }},
    {{ // Bucket 12
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-23, 13), Pair(-30, 8), Pair(3, 1), Pair(-21, -26), Pair(0, 0), Pair(26, -39), Pair(-51, 38), Pair(-13, 13),
        Pair(20, -22), Pair(0, -17), Pair(-23, -20), Pair(50, -18), Pair(103, -36), Pair(18, 7), Pair(81, -14), Pair(-15, -12),
        Pair(11, -24), Pair(-21, -17), Pair(-8, -19), Pair(-1, -17), Pair(-27, -16), Pair(-15, -5), Pair(12, -20), Pair(-5, -8),
        Pair(4, -24), Pair(2, -17), Pair(9, -27), Pair(15, -18), Pair(-22, -1), Pair(11, -27), Pair(11, -21), Pair(2, -13),
        Pair(-19, -15), Pair(-24, -18), Pair(-38, 7), Pair(45, -18), Pair(8, -25), Pair(13, -12), Pair(41, -21), Pair(18, -30),
        Pair(4, -12), Pair(20, -24), Pair(-10, 11), Pair(11, 4), Pair(0, 0), Pair(10, -27), Pair(23, -9), Pair(-4, -11),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-13, -134), Pair(186, -43), Pair(-69, -1), Pair(143, -105), Pair(20, 18), Pair(-44, -109), Pair(19, -132), Pair(-156, 110),
        Pair(2, -38), Pair(9, 56), Pair(69, -53), Pair(18, 13), Pair(-280, 53), Pair(148, 26), Pair(46, -95), Pair(8, -45),
        Pair(-261, -36), Pair(-11, 30), Pair(-23, -33), Pair(-120, 17), Pair(54, 6), Pair(114, 71), Pair(187, -68), Pair(181, -88),
        Pair(-112, 51), Pair(-21, -23), Pair(-70, 40), Pair(1, 28), Pair(111, 11), Pair(-5, 29), Pair(118, -23), Pair(-108, 76),
        Pair(-52, 39), Pair(-192, 57), Pair(-68, 1), Pair(82, 50), Pair(-93, 28), Pair(10, 24), Pair(26, 35), Pair(4, 41),
        Pair(24, -7), Pair(144, -50), Pair(-105, 123), Pair(-90, 150), Pair(106, 68), Pair(-70, 117), Pair(41, 48), Pair(137, -145),
        Pair(-152, 8), Pair(-38, 40), Pair(-146, 204), Pair(-101, 25), Pair(0, 0), Pair(-128, -93), Pair(-59, 199), Pair(28, 6),
        Pair(34, -47), Pair(-123, -73), Pair(148, -37), Pair(-161, -72), Pair(-12, 185), Pair(-20, -148), Pair(104, -26), Pair(27, 22)
      },
      { // Piece 2
        Pair(334, -50), Pair(-93, 125), Pair(-12, 3), Pair(-168, 79), Pair(-186, 5), Pair(-5, 103), Pair(-94, 31), Pair(176, 145),
        Pair(-13, 93), Pair(0, 11), Pair(10, 74), Pair(-20, 58), Pair(-186, 116), Pair(118, -22), Pair(-34, 84), Pair(-103, 23),
        Pair(23, 84), Pair(-26, 93), Pair(59, 16), Pair(-18, 86), Pair(11, -3), Pair(-160, 186), Pair(18, 0), Pair(-29, 60),
        Pair(-179, 220), Pair(-121, 116), Pair(-78, 109), Pair(166, -85), Pair(-53, 72), Pair(-50, 53), Pair(13, 82), Pair(-18, 66),
        Pair(-204, 90), Pair(-127, 220), Pair(-72, 88), Pair(62, 52), Pair(-14, 52), Pair(-15, 77), Pair(-136, 126), Pair(-45, 218),
        Pair(-35, 41), Pair(141, -67), Pair(-27, 188), Pair(-8, 145), Pair(-11, 115), Pair(77, 24), Pair(-78, 183), Pair(5, -20),
        Pair(200, -80), Pair(-27, 98), Pair(-51, 74), Pair(-78, 203), Pair(0, 0), Pair(-140, 247), Pair(13, -6), Pair(-70, 15),
        Pair(143, -48), Pair(250, -39), Pair(-101, 105), Pair(-97, 80), Pair(160, 230), Pair(-74, -27), Pair(-1, 133), Pair(5, 79)
      },
      { // Piece 3
        Pair(-46, 9), Pair(-136, 64), Pair(18, 13), Pair(59, -13), Pair(141, 22), Pair(19, -2), Pair(-4, 18), Pair(154, -33),
        Pair(12, 15), Pair(-21, 10), Pair(4, 21), Pair(-69, 53), Pair(-1, 54), Pair(12, 9), Pair(104, 25), Pair(-63, 75),
        Pair(47, -24), Pair(51, -7), Pair(-31, 14), Pair(56, 9), Pair(111, 22), Pair(227, -105), Pair(169, -71), Pair(-29, 34),
        Pair(155, -43), Pair(-24, 31), Pair(2, 0), Pair(-73, 40), Pair(188, 11), Pair(110, -52), Pair(-99, 25), Pair(1, -52),
        Pair(-194, 96), Pair(34, 39), Pair(23, -23), Pair(-72, 39), Pair(80, 39), Pair(-19, 3), Pair(162, -90), Pair(-108, 34),
        Pair(-123, 85), Pair(-187, 25), Pair(141, -1), Pair(-54, 64), Pair(53, 83), Pair(98, -74), Pair(31, 44), Pair(157, -46),
        Pair(94, 14), Pair(69, -3), Pair(54, -10), Pair(180, -45), Pair(0, 0), Pair(-17, 63), Pair(63, -88), Pair(21, -85),
        Pair(-83, 96), Pair(-20, 86), Pair(-82, 119), Pair(-60, -24), Pair(49, 117), Pair(-49, 42), Pair(-14, 67), Pair(-24, 73)
      },
      { // Piece 4
        Pair(-68, 36), Pair(-11, -36), Pair(-86, 62), Pair(-61, 77), Pair(-4, -43), Pair(252, -94), Pair(-63, 0), Pair(48, -77),
        Pair(-66, 45), Pair(1, -79), Pair(32, -2), Pair(-88, 112), Pair(47, 35), Pair(-115, 193), Pair(-51, 107), Pair(-1, 22),
        Pair(-9, -88), Pair(17, -44), Pair(-104, 70), Pair(-138, 145), Pair(2, 15), Pair(186, -231), Pair(119, -84), Pair(26, -75),
        Pair(-152, 92), Pair(-143, 258), Pair(-25, -56), Pair(134, -230), Pair(193, -135), Pair(68, -14), Pair(105, -109), Pair(40, -58),
        Pair(-125, 202), Pair(-35, 5), Pair(25, 63), Pair(-41, 68), Pair(-92, 98), Pair(-3, -8), Pair(52, -69), Pair(-37, 55),
        Pair(-315, 70), Pair(108, -287), Pair(47, -21), Pair(182, -366), Pair(31, 22), Pair(-68, 71), Pair(-47, 27), Pair(-117, -48),
        Pair(171, -246), Pair(-220, 155), Pair(48, -155), Pair(105, -164), Pair(0, 0), Pair(-30, -53), Pair(-88, 16), Pair(77, -88),
        Pair(66, -113), Pair(-152, 79), Pair(107, -286), Pair(-138, 33), Pair(-37, -67), Pair(-110, -25), Pair(-149, 199), Pair(-16, 21)
      },
      { // Piece 5
        Pair(-126, 41), Pair(-49, -152), Pair(14, -39), Pair(-87, -132), Pair(74, 14), Pair(12, -4), Pair(6, 68), Pair(24, 2),
        Pair(4, 30), Pair(114, -70), Pair(-82, -55), Pair(123, -10), Pair(26, -37), Pair(89, -51), Pair(-108, 28), Pair(-23, -43),
        Pair(133, -101), Pair(-28, 6), Pair(-137, 56), Pair(-90, 69), Pair(-2, 99), Pair(191, 50), Pair(28, 3), Pair(-252, 38),
        Pair(-46, -25), Pair(-146, 35), Pair(-32, 34), Pair(-79, 42), Pair(-134, 66), Pair(-72, 22), Pair(54, 12), Pair(26, -56),
        Pair(303, -90), Pair(113, -12), Pair(79, 38), Pair(-139, 72), Pair(-95, 51), Pair(-24, 24), Pair(105, -20), Pair(-132, 11),
        Pair(64, -78), Pair(13, -29), Pair(-134, 47), Pair(23, 96), Pair(-13, 82), Pair(50, 53), Pair(-5, 40), Pair(69, -71),
        Pair(131, -121), Pair(115, -51), Pair(192, -41), Pair(-107, 98), Pair(0, 0), Pair(19, 80), Pair(-29, 11), Pair(23, -45),
        Pair(-116, -55), Pair(-15, -51), Pair(34, -60), Pair(-28, 81), Pair(-72, 140), Pair(25, 77), Pair(-38, 4), Pair(-25, -17)
      }
    }},
    {{ // Bucket 13
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-50, 12), Pair(20, -11), Pair(-23, 10), Pair(-20, 0), Pair(-26, 39), Pair(0, 0), Pair(-121, 79), Pair(-62, 32),
        Pair(-19, -14), Pair(6, 0), Pair(-89, 10), Pair(8, -28), Pair(-36, -4), Pair(-70, 13), Pair(3, 6), Pair(26, -3),
        Pair(-21, -24), Pair(14, -15), Pair(-29, -19), Pair(-9, -4), Pair(16, -26), Pair(30, -6), Pair(-15, -9), Pair(-24, -1),
        Pair(-38, -12), Pair(-16, -16), Pair(-11, -13), Pair(7, -20), Pair(-4, -33), Pair(-2, -33), Pair(-8, -10), Pair(8, -16),
        Pair(-5, -8), Pair(-34, -11), Pair(-28, -15), Pair(7, -10), Pair(-9, -13), Pair(-13, 9), Pair(39, -26), Pair(12, -17),
        Pair(-26, -12), Pair(-1, -9), Pair(-8, -12), Pair(-72, 35), Pair(9, -17), Pair(0, 0), Pair(47, -26), Pair(13, -36),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-49, -44), Pair(-144, -120), Pair(-121, 41), Pair(180, 45), Pair(-6, 8), Pair(-29, 56), Pair(-80, -57), Pair(-30, 145),
        Pair(-71, -295), Pair(-38, -21), Pair(174, 46), Pair(-8, -46), Pair(17, 18), Pair(-56, 82), Pair(103, -206), Pair(-175, -33),
        Pair(202, -102), Pair(-264, 126), Pair(67, 11), Pair(-32, 32), Pair(-3, 64), Pair(73, 24), Pair(205, 27), Pair(-22, 52),
        Pair(165, -47), Pair(23, -3), Pair(-34, 30), Pair(107, -20), Pair(-29, 50), Pair(175, 7), Pair(-62, 17), Pair(58, 7),
        Pair(18, -102), Pair(-156, 95), Pair(6, 32), Pair(42, -8), Pair(44, 62), Pair(62, 19), Pair(232, 78), Pair(41, -10),
        Pair(16, -102), Pair(-53, 17), Pair(15, -20), Pair(46, 2), Pair(-83, 168), Pair(33, -13), Pair(-103, 185), Pair(26, -32),
        Pair(-81, 8), Pair(-26, -59), Pair(-38, -34), Pair(-88, 167), Pair(27, 45), Pair(0, 0), Pair(13, -8), Pair(-77, 221),
        Pair(26, 94), Pair(-40, 23), Pair(23, -52), Pair(14, -27), Pair(-163, -51), Pair(2, 179), Pair(-86, -17), Pair(153, 105)
      },
      { // Piece 2
        Pair(-86, 86), Pair(-113, -80), Pair(-5, 114), Pair(-329, 52), Pair(-188, 136), Pair(-43, -192), Pair(26, 96), Pair(-32, -95),
        Pair(30, 48), Pair(13, 92), Pair(-10, 21), Pair(-222, 160), Pair(164, -1), Pair(-106, 140), Pair(45, -13), Pair(39, 72),
        Pair(-237, 260), Pair(146, 50), Pair(10, 93), Pair(76, -44), Pair(-227, 171), Pair(92, 21), Pair(-7, 108), Pair(51, -70),
        Pair(4, -48), Pair(-88, 185), Pair(-160, 115), Pair(-57, 101), Pair(-3, 3), Pair(205, -34), Pair(118, -55), Pair(70, 77),
        Pair(-78, 165), Pair(-4, -21), Pair(-100, 205), Pair(31, 97), Pair(96, 42), Pair(52, -30), Pair(-117, 173), Pair(65, 94),
        Pair(68, 6), Pair(-192, 103), Pair(-23, 48), Pair(-88, 203), Pair(33, 14), Pair(87, 30), Pair(-56, 39), Pair(-198, 230),
        Pair(-248, 32), Pair(10, 34), Pair(-38, 113), Pair(-63, 17), Pair(-19, 215), Pair(0, 0), Pair(-3, 167), Pair(2, -103),
        Pair(81, -108), Pair(129, 30), Pair(32, -69), Pair(-3, 75), Pair(-36, -33), Pair(-72, 286), Pair(43, -11), Pair(107, 26)
      },
      { // Piece 3
        Pair(141, -19), Pair(11, -1), Pair(-23, 7), Pair(-9, 4), Pair(93, -6), Pair(89, 46), Pair(42, 21), Pair(212, -9),
        Pair(69, -24), Pair(-108, 8), Pair(64, -33), Pair(-7, -9), Pair(-49, 21), Pair(134, 66), Pair(107, -20), Pair(179, -78),
        Pair(-28, 39), Pair(-106, 42), Pair(-6, 25), Pair(122, -30), Pair(90, -54), Pair(138, 31), Pair(5, -16), Pair(172, -16),
        Pair(-40, 46), Pair(41, -52), Pair(-76, 31), Pair(-120, 44), Pair(-79, 24), Pair(172, 8), Pair(68, -51), Pair(49, -42),
        Pair(-42, 22), Pair(99, -48), Pair(78, 46), Pair(-72, 43), Pair(71, -16), Pair(113, 59), Pair(-90, 18), Pair(-93, 54),
        Pair(3, 14), Pair(-189, 35), Pair(-153, 28), Pair(97, -64), Pair(-21, -33), Pair(67, 76), Pair(-201, 115), Pair(126, -4),
        Pair(73, -5), Pair(-113, 83), Pair(80, 31), Pair(-49, 1), Pair(-3, 26), Pair(0, 0), Pair(347, -75), Pair(37, 76),
        Pair(-49, 86), Pair(8, 64), Pair(-18, 67), Pair(-51, 67), Pair(10, -49), Pair(90, 114), Pair(-173, 79), Pair(37, 29)
      },
      { // Piece 4
        Pair(80, -204), Pair(-108, -55), Pair(-131, -1), Pair(-16, 18), Pair(126, -155), Pair(45, -25), Pair(45, -78), Pair(131, 12),
        Pair(-225, 111), Pair(-117, 129), Pair(-61, 92), Pair(-111, 104), Pair(82, 0), Pair(155, -114), Pair(-116, -45), Pair(18, -54),
        Pair(81, -150), Pair(156, -186), Pair(52, -35), Pair(49, -131), Pair(-57, -36), Pair(-291, 162), Pair(-63, 107), Pair(17, -157),
        Pair(-262, 147), Pair(35, -216), Pair(61, -151), Pair(58, 8), Pair(-110, 109), Pair(89, -85), Pair(-62, 73), Pair(63, -220),
        Pair(-42, -88), Pair(-158, 81), Pair(-12, -105), Pair(44, 21), Pair(-125, 22), Pair(224, -100), Pair(-55, 62), Pair(-95, 146),
        Pair(-27, 140), Pair(-39, -88), Pair(-11, -183), Pair(-129, 32), Pair(14, -76), Pair(-66, 57), Pair(107, -54), Pair(130, -109),
        Pair(14, -208), Pair(-51, 23), Pair(-83, 114), Pair(-32, 32), Pair(-107, 82), Pair(0, 0), Pair(-15, 28), Pair(-55, -121),
        Pair(61, -43), Pair(-146, -30), Pair(-50, -2), Pair(-50, -168), Pair(-134, -103), Pair(-79, -69), Pair(-19, -144), Pair(-40, -49)
      },
      { // Piece 5
        Pair(-30, -84), Pair(46, -72), Pair(85, -95), Pair(-33, 48), Pair(-108, -61), Pair(-59, -81), Pair(21, -74), Pair(67, 251),
        Pair(2, -39), Pair(-132, -87), Pair(153, -79), Pair(35, -110), Pair(-17, -5), Pair(93, -52), Pair(-27, -45), Pair(31, 3),
        Pair(-100, -79), Pair(124, -46), Pair(187, -1), Pair(136, -55), Pair(-25, 54), Pair(-258, 38), Pair(201, -16), Pair(147, -9),
        Pair(8, -128), Pair(-98, -34), Pair(-29, 6), Pair(227, -35), Pair(-196, 88), Pair(-16, 5), Pair(-29, 12), Pair(64, 34),
        Pair(-42, -14), Pair(22, -52), Pair(101, -14), Pair(131, -19), Pair(108, -1), Pair(40, 6), Pair(166, -7), Pair(240, -71),
        Pair(-138, -103), Pair(-183, -35), Pair(95, -68), Pair(23, 22), Pair(-68, 39), Pair(-111, 94), Pair(-32, 79), Pair(-83, 24),
        Pair(-34, -73), Pair(24, -30), Pair(57, -73), Pair(-75, 25), Pair(-32, 109), Pair(0, 0), Pair(-12, 92), Pair(-45, -17),
        Pair(-201, -51), Pair(-7, -106), Pair(-61, -42), Pair(0, -30), Pair(45, 48), Pair(-40, 134), Pair(61, 37), Pair(-115, 87)
      }
    }},
    {{ // Bucket 14
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-7, 0), Pair(4, -9), Pair(-27, -13), Pair(-43, 8), Pair(51, -38), Pair(121, -79), Pair(0, 0), Pair(23, -7),
        Pair(-5, -16), Pair(35, -21), Pair(24, -26), Pair(-41, -22), Pair(16, -11), Pair(15, -8), Pair(24, -23), Pair(25, 0),
        Pair(26, -25), Pair(-26, -34), Pair(-13, -20), Pair(-29, -18), Pair(-22, -13), Pair(41, -9), Pair(-6, -16), Pair(-25, -15),
        Pair(25, -35), Pair(15, -24), Pair(-23, -19), Pair(-9, -20), Pair(16, -27), Pair(-10, -25), Pair(-14, -34), Pair(47, -26),
        Pair(11, -39), Pair(-15, -24), Pair(11, -34), Pair(-30, -21), Pair(11, -24), Pair(4, -9), Pair(32, -15), Pair(16, -22),
        Pair(10, -40), Pair(-2, 0), Pair(3, -11), Pair(-25, 27), Pair(-51, -21), Pair(19, -1), Pair(0, 0), Pair(7, -2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(67, -45), Pair(-237, -85), Pair(164, -35), Pair(-123, 19), Pair(79, 30), Pair(298, -89), Pair(-82, -53), Pair(62, 31),
        Pair(-65, -131), Pair(-184, 1), Pair(201, -116), Pair(-135, 27), Pair(34, -8), Pair(-271, 66), Pair(-113, -11), Pair(-75, -45),
        Pair(16, 30), Pair(98, -79), Pair(12, 32), Pair(36, -100), Pair(6, 21), Pair(-17, 33), Pair(85, -42), Pair(223, -275),
        Pair(46, -18), Pair(-39, 36), Pair(-2, -10), Pair(99, 34), Pair(35, 4), Pair(-18, 23), Pair(106, 20), Pair(115, -14),
        Pair(5, 19), Pair(83, -30), Pair(44, -33), Pair(-21, 42), Pair(43, 34), Pair(46, 34), Pair(-169, 101), Pair(-87, 76),
        Pair(86, 57), Pair(-7, 32), Pair(56, 35), Pair(-74, 46), Pair(-38, 38), Pair(-18, 103), Pair(-7, 43), Pair(-139, 98),
        Pair(97, -2), Pair(183, 69), Pair(33, -4), Pair(-42, 120), Pair(-21, 129), Pair(40, -28), Pair(0, 0), Pair(48, -22),
        Pair(-62, -51), Pair(33, -66), Pair(2, 27), Pair(-27, -38), Pair(100, 1), Pair(-27, -41), Pair(-108, 186), Pair(-54, -70)
      },
      { // Piece 2
        Pair(83, 111), Pair(-180, 153), Pair(-176, 13), Pair(-204, 147), Pair(72, -26), Pair(-115, 121), Pair(14, 29), Pair(-82, -15),
        Pair(-190, 246), Pair(-125, 109), Pair(-116, 127), Pair(-43, -13), Pair(-38, 122), Pair(-165, 39), Pair(-9, 141), Pair(104, -137),
        Pair(2, -20), Pair(-299, 270), Pair(-56, 126), Pair(21, 111), Pair(41, -32), Pair(70, 134), Pair(117, -14), Pair(-49, 36),
        Pair(-150, 141), Pair(15, 9), Pair(-74, 209), Pair(-3, 70), Pair(-58, 128), Pair(12, 17), Pair(-115, 134), Pair(150, -38),
        Pair(62, 52), Pair(-208, 98), Pair(36, 54), Pair(-97, 201), Pair(47, 89), Pair(-84, 114), Pair(163, -97), Pair(40, 54),
        Pair(-40, 5), Pair(-69, 22), Pair(-101, 79), Pair(-10, 1), Pair(-100, 220), Pair(75, 3), Pair(5, 14), Pair(15, -26),
        Pair(153, -5), Pair(-73, 99), Pair(-90, 38), Pair(-101, 59), Pair(-1, -33), Pair(-3, 203), Pair(0, 0), Pair(-126, 264),
        Pair(92, -1), Pair(200, -82), Pair(-91, 70), Pair(128, -62), Pair(-264, 165), Pair(22, -68), Pair(-41, 315), Pair(77, 65)
      },
      { // Piece 3
        Pair(-117, 63), Pair(-69, -15), Pair(32, 33), Pair(47, 38), Pair(355, -52), Pair(46, 25), Pair(175, 21), Pair(330, 1),
        Pair(14, -7), Pair(-43, 14), Pair(38, -16), Pair(145, -55), Pair(21, -70), Pair(41, -61), Pair(107, 28), Pair(-11, 57),
        Pair(-75, 81), Pair(-27, 21), Pair(-49, 2), Pair(71, -17), Pair(12, 10), Pair(31, -1), Pair(-84, 79), Pair(16, 66),
        Pair(55, -44), Pair(110, -23), Pair(-73, 45), Pair(42, -52), Pair(87, -92), Pair(-28, -12), Pair(146, 47), Pair(229, -67),
        Pair(-99, 24), Pair(102, -28), Pair(-14, -28), Pair(-54, -34), Pair(26, -18), Pair(199, -74), Pair(274, -2), Pair(71, -29),
        Pair(-30, -14), Pair(63, -42), Pair(56, -33), Pair(31, 8), Pair(62, -55), Pair(157, -85), Pair(169, -3), Pair(140, -58),
        Pair(-134, 75), Pair(-116, 42), Pair(-24, 33), Pair(-46, 9), Pair(43, -13), Pair(149, -21), Pair(0, 0), Pair(71, -121),
        Pair(-45, 81), Pair(-16, 74), Pair(-17, 34), Pair(-18, 41), Pair(-10, 68), Pair(15, -46), Pair(93, 90), Pair(51, -10)
      },
      { // Piece 4
        Pair(-112, 78), Pair(-162, 7), Pair(-255, -22), Pair(-198, 32), Pair(-133, -52), Pair(39, 21), Pair(-150, -39), Pair(-49, -117),
        Pair(32, -38), Pair(-43, 37), Pair(-240, 233), Pair(-33, -25), Pair(38, -2), Pair(14, 10), Pair(9, 42), Pair(-12, 81),
        Pair(23, -160), Pair(131, -87), Pair(28, -37), Pair(-33, 54), Pair(-79, 114), Pair(-115, 46), Pair(-31, 51), Pair(54, -20),
        Pair(28, 42), Pair(73, -62), Pair(-3, -61), Pair(68, -5), Pair(37, 124), Pair(-38, -72), Pair(-213, 160), Pair(17, -47),
        Pair(-49, -39), Pair(1, 55), Pair(45, -122), Pair(25, 69), Pair(-83, 102), Pair(-77, 157), Pair(101, -182), Pair(77, -85),
        Pair(-14, 6), Pair(-54, 42), Pair(-100, 243), Pair(9, 70), Pair(8, -29), Pair(24, 38), Pair(15, -91), Pair(-8, -140),
        Pair(63, -66), Pair(14, -65), Pair(17, -20), Pair(-85, 84), Pair(-131, 191), Pair(10, 51), Pair(0, 0), Pair(-265, 22),
        Pair(-45, -9), Pair(84, -68), Pair(59, -173), Pair(-18, -5), Pair(50, -77), Pair(-338, -179), Pair(124, -90), Pair(3, 3)
      },
      { // Piece 5
        Pair(67, -68), Pair(30, -68), Pair(-44, -50), Pair(63, -30), Pair(-16, -45), Pair(32, -70), Pair(-22, -91), Pair(-29, -27),
        Pair(25, -60), Pair(-6, -51), Pair(147, -105), Pair(-41, -14), Pair(6, -46), Pair(77, 1), Pair(23, 10), Pair(28, -9),
        Pair(9, 1), Pair(-52, -25), Pair(-41, 2), Pair(-121, 5), Pair(309, -1), Pair(165, 77), Pair(-83, 56), Pair(34, 9),
        Pair(31, -33), Pair(80, -38), Pair(-92, 8), Pair(-122, 51), Pair(-55, 62), Pair(36, 52), Pair(185, -20), Pair(5, 1),
        Pair(-150, -57), Pair(16, -34), Pair(125, -58), Pair(-41, 0), Pair(289, -64), Pair(-118, 52), Pair(133, -80), Pair(38, -19),
        Pair(79, -181), Pair(-76, -55), Pair(62, -53), Pair(-122, 17), Pair(-99, 21), Pair(-122, 88), Pair(-269, 105), Pair(-23, 80),
        Pair(-2, -100), Pair(-179, -4), Pair(-27, -42), Pair(-9, -30), Pair(54, -4), Pair(-16, 103), Pair(0, 0), Pair(2, 149),
        Pair(0, -181), Pair(-32, -88), Pair(-9, -106), Pair(20, -122), Pair(-49, 38), Pair(37, 134), Pair(20, 155), Pair(230, 11)
      }
    }},
    {{ // Bucket 15
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(28, -16), Pair(66, -31), Pair(-20, -17), Pair(-16, -15), Pair(13, -13), Pair(62, -32), Pair(-23, 7), Pair(0, 0),
        Pair(19, -12), Pair(69, -48), Pair(52, -49), Pair(36, -33), Pair(29, -32), Pair(-25, -28), Pair(-5, 7), Pair(66, 38),
        Pair(39, -32), Pair(58, -34), Pair(17, -22), Pair(19, -31), Pair(-23, -15), Pair(8, -27), Pair(45, -32), Pair(-24, 24),
        Pair(50, -47), Pair(8, -35), Pair(20, -37), Pair(17, -22), Pair(17, -31), Pair(-14, -20), Pair(75, -55), Pair(11, -48),
        Pair(21, -32), Pair(21, -28), Pair(53, -46), Pair(4, -30), Pair(20, -31), Pair(7, -26), Pair(39, -18), Pair(29, 17),
        Pair(16, -39), Pair(15, -24), Pair(12, -37), Pair(18, -55), Pair(51, -32), Pair(-2, -22), Pair(49, 3), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-152, -53), Pair(36, -107), Pair(184, -129), Pair(-212, -15), Pair(135, -69), Pair(-6, -172), Pair(22, -119), Pair(95, -59),
        Pair(-23, -97), Pair(315, -188), Pair(32, -30), Pair(6, -57), Pair(271, -100), Pair(67, -90), Pair(362, -91), Pair(-253, -91),
        Pair(-8, -46), Pair(167, -101), Pair(-2, -33), Pair(21, -89), Pair(-9, -66), Pair(-63, -33), Pair(21, -128), Pair(-22, -69),
        Pair(-21, -86), Pair(43, -70), Pair(-26, -46), Pair(-18, -27), Pair(68, -10), Pair(153, -66), Pair(187, -100), Pair(154, -58),
        Pair(26, -91), Pair(92, -127), Pair(-10, -22), Pair(86, -55), Pair(114, -69), Pair(-25, -8), Pair(83, -4), Pair(114, -150),
        Pair(16, -74), Pair(74, -128), Pair(62, -10), Pair(20, 10), Pair(-8, 9), Pair(12, 4), Pair(14, 49), Pair(105, -122),
        Pair(-233, -54), Pair(-83, -52), Pair(-56, -79), Pair(24, -41), Pair(42, -56), Pair(70, 63), Pair(74, -82), Pair(0, 0),
        Pair(52, 78), Pair(50, 0), Pair(-300, 73), Pair(141, -129), Pair(-34, -55), Pair(-12, 77), Pair(-195, -218), Pair(-151, 188)
      },
      { // Piece 2
        Pair(5, 126), Pair(-102, 16), Pair(82, 30), Pair(168, -42), Pair(67, 46), Pair(238, -33), Pair(-6, 44), Pair(-50, -117),
        Pair(96, -118), Pair(32, 151), Pair(-104, 82), Pair(-88, 4), Pair(-99, -37), Pair(-105, 24), Pair(62, -76), Pair(106, 40),
        Pair(14, 28), Pair(190, -103), Pair(-55, 130), Pair(39, -4), Pair(107, -18), Pair(39, -20), Pair(-42, 46), Pair(-24, 27),
        Pair(75, -29), Pair(18, 25), Pair(128, -63), Pair(-10, 154), Pair(-34, 40), Pair(-17, -2), Pair(11, -127), Pair(69, 49),
        Pair(-35, 54), Pair(43, -93), Pair(62, -19), Pair(4, -6), Pair(14, 135), Pair(106, 2), Pair(66, -86), Pair(262, -123),
        Pair(-9, 7), Pair(-22, 11), Pair(45, -40), Pair(51, 26), Pair(102, -48), Pair(-43, 133), Pair(-53, 73), Pair(6, 58),
        Pair(-93, 63), Pair(31, -9), Pair(-90, 70), Pair(1, -30), Pair(-18, 5), Pair(140, -133), Pair(42, 117), Pair(0, 0),
        Pair(-194, 60), Pair(102, -31), Pair(-22, -33), Pair(-33, 37), Pair(135, -119), Pair(27, 7), Pair(-22, -99), Pair(99, 203)
      },
      { // Piece 3
        Pair(162, -29), Pair(-29, 33), Pair(-223, 58), Pair(49, -4), Pair(-84, 50), Pair(81, 12), Pair(167, -18), Pair(173, -5),
        Pair(40, 17), Pair(-82, 9), Pair(103, -11), Pair(97, -73), Pair(-98, 69), Pair(-55, 11), Pair(89, -27), Pair(197, 38),
        Pair(60, -21), Pair(1, 39), Pair(108, -33), Pair(-35, 26), Pair(138, -47), Pair(86, -58), Pair(92, -13), Pair(47, 47),
        Pair(145, -34), Pair(-24, 15), Pair(-11, 9), Pair(131, -50), Pair(-47, 5), Pair(149, -42), Pair(-38, 11), Pair(83, 46),
        Pair(113, -79), Pair(-13, -7), Pair(264, -126), Pair(1, 18), Pair(115, -34), Pair(160, -60), Pair(-52, -36), Pair(113, 3),
        Pair(80, -67), Pair(-83, 40), Pair(255, -106), Pair(11, 7), Pair(16, 2), Pair(-46, 42), Pair(151, -87), Pair(32, 69),
        Pair(77, 35), Pair(41, 18), Pair(-7, 46), Pair(-98, 32), Pair(-46, 61), Pair(124, -58), Pair(101, -52), Pair(0, 0),
        Pair(26, 102), Pair(-44, 79), Pair(6, 79), Pair(5, 65), Pair(15, 48), Pair(114, 60), Pair(198, -57), Pair(79, 145)
      },
      { // Piece 4
        Pair(18, -106), Pair(-89, 24), Pair(-26, -53), Pair(-80, 111), Pair(54, -8), Pair(246, -182), Pair(-99, 42), Pair(54, 73),
        Pair(-34, 110), Pair(-153, 148), Pair(-67, 161), Pair(-108, 195), Pair(-39, 95), Pair(-28, 42), Pair(81, -74), Pair(-35, 21),
        Pair(68, -140), Pair(-49, 146), Pair(58, -103), Pair(-96, -38), Pair(-211, 156), Pair(114, -95), Pair(108, 96), Pair(-162, 200),
        Pair(-8, -98), Pair(47, -16), Pair(-25, 154), Pair(-72, 98), Pair(14, 0), Pair(-19, -83), Pair(35, 52), Pair(88, -128),
        Pair(29, -63), Pair(-55, 57), Pair(-130, 110), Pair(70, -165), Pair(19, 41), Pair(-93, -101), Pair(-115, -13), Pair(82, -74),
        Pair(15, 131), Pair(-11, 15), Pair(-67, 66), Pair(-23, 66), Pair(-40, -78), Pair(-56, -2), Pair(-46, -29), Pair(-2, 54),
        Pair(111, -93), Pair(-39, 4), Pair(13, -18), Pair(-38, 7), Pair(-95, 87), Pair(-48, 221), Pair(23, -6), Pair(0, 0),
        Pair(155, -151), Pair(-196, 119), Pair(10, 11), Pair(-11, 17), Pair(-47, 7), Pair(1, 89), Pair(-235, -170), Pair(-184, 63)
      },
      { // Piece 5
        Pair(57, -52), Pair(149, -168), Pair(49, -111), Pair(23, -128), Pair(-34, 23), Pair(-7, 2), Pair(55, 41), Pair(-35, -155),
        Pair(215, -69), Pair(101, -73), Pair(-104, -41), Pair(56, -68), Pair(41, -30), Pair(63, 10), Pair(-11, 0), Pair(11, -60),
        Pair(49, -4), Pair(-81, -17), Pair(-31, 14), Pair(-60, 10), Pair(325, -26), Pair(188, 2), Pair(79, 56), Pair(26, -38),
        Pair(258, -109), Pair(-62, -1), Pair(-153, 2), Pair(80, -6), Pair(60, 24), Pair(35, 76), Pair(118, 36), Pair(58, 15),
        Pair(-27, -41), Pair(-18, -46), Pair(112, -47), Pair(19, -17), Pair(-11, 23), Pair(-38, 38), Pair(-43, 38), Pair(10, 18),
        Pair(74, -61), Pair(-50, -68), Pair(-33, -66), Pair(-19, -11), Pair(-60, 24), Pair(-21, 23), Pair(-146, 115), Pair(-174, 94),
        Pair(-10, -34), Pair(-151, 49), Pair(-103, -79), Pair(-121, -44), Pair(-112, 76), Pair(-118, 91), Pair(-214, 185), Pair(0, 0),
        Pair(-25, -162), Pair(-59, -80), Pair(-184, -38), Pair(-105, -40), Pair(-126, -21), Pair(-231, 109), Pair(46, 142), Pair(73, 212)
      }
    }},
    {{ // Bucket 16
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(50, -3), Pair(39, -18), Pair(12, 10), Pair(-18, 0), Pair(-22, 21), Pair(19, 14), Pair(6, 15), Pair(-18, 13),
        Pair(0, 0), Pair(11, -16), Pair(11, -7), Pair(9, -8), Pair(6, 5), Pair(-9, 9), Pair(-8, 11), Pair(3, 10),
        Pair(-7, -27), Pair(3, -5), Pair(7, -14), Pair(6, -11), Pair(-1, -7), Pair(-3, -3), Pair(5, 1), Pair(-1, 0),
        Pair(-14, 7), Pair(3, -8), Pair(-2, -6), Pair(2, -16), Pair(-4, -4), Pair(-9, -10), Pair(-9, -8), Pair(-3, -9),
        Pair(0, 0), Pair(-2, -7), Pair(-5, -10), Pair(1, -20), Pair(-11, -7), Pair(-13, -11), Pair(-6, -15), Pair(-4, -18),
        Pair(25, 53), Pair(-11, -5), Pair(8, -12), Pair(-10, -2), Pair(-5, -3), Pair(-2, -15), Pair(-9, -11), Pair(3, -16),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(35, -3), Pair(-97, -27), Pair(133, -38), Pair(147, -66), Pair(132, -36), Pair(83, 21), Pair(-41, -24), Pair(-138, 30),
        Pair(-127, 115), Pair(57, -6), Pair(106, 38), Pair(14, 18), Pair(56, 27), Pair(43, -6), Pair(55, -33), Pair(35, -8),
        Pair(154, 45), Pair(84, 14), Pair(11, 56), Pair(60, 9), Pair(13, 35), Pair(68, -8), Pair(41, -20), Pair(28, -18),
        Pair(-7, 38), Pair(36, 65), Pair(29, 41), Pair(32, 31), Pair(46, 18), Pair(44, 10), Pair(25, 5), Pair(58, -16),
        Pair(21, 50), Pair(3, 95), Pair(25, 50), Pair(17, 38), Pair(24, 47), Pair(38, 16), Pair(68, 8), Pair(49, -15),
        Pair(0, 0), Pair(-16, 66), Pair(15, 74), Pair(24, 18), Pair(10, 32), Pair(24, 30), Pair(22, 14), Pair(48, 22),
        Pair(113, 159), Pair(104, -166), Pair(8, 62), Pair(22, 33), Pair(30, 48), Pair(57, -47), Pair(44, 20), Pair(61, -51),
        Pair(-5, 96), Pair(28, 98), Pair(-8, 79), Pair(51, -64), Pair(38, 36), Pair(11, 9), Pair(-8, 53), Pair(-39, 14)
      },
      { // Piece 2
        Pair(-179, 112), Pair(11, 78), Pair(-159, 129), Pair(-106, 125), Pair(37, 129), Pair(6, 105), Pair(-152, 213), Pair(66, 105),
        Pair(7, 92), Pair(29, 75), Pair(44, 56), Pair(-32, 110), Pair(56, 100), Pair(-43, 174), Pair(-8, 115), Pair(28, 50),
        Pair(-46, 67), Pair(78, 63), Pair(-53, 84), Pair(25, 99), Pair(-70, 166), Pair(-38, 131), Pair(-45, 89), Pair(59, 72),
        Pair(39, 64), Pair(14, 67), Pair(46, 82), Pair(-21, 145), Pair(20, 88), Pair(-7, 79), Pair(46, 58), Pair(18, 30),
        Pair(20, 106), Pair(15, 108), Pair(-17, 135), Pair(31, 89), Pair(6, 56), Pair(9, 61), Pair(-13, 64), Pair(35, 55),
        Pair(0, 0), Pair(-22, 159), Pair(34, 94), Pair(5, 85), Pair(17, 80), Pair(22, 40), Pair(23, 60), Pair(-4, 48),
        Pair(17, 241), Pair(11, 53), Pair(14, 91), Pair(43, 71), Pair(-5, 53), Pair(15, 78), Pair(-5, 39), Pair(29, 4),
        Pair(23, 72), Pair(1, 143), Pair(28, 77), Pair(15, 45), Pair(14, 75), Pair(-10, 27), Pair(48, 35), Pair(30, 72)
      },
      { // Piece 3
        Pair(50, 136), Pair(2, 141), Pair(60, 115), Pair(12, 152), Pair(78, 101), Pair(184, 79), Pair(24, 128), Pair(94, 112),
        Pair(82, 166), Pair(19, 143), Pair(24, 129), Pair(30, 127), Pair(9, 110), Pair(41, 108), Pair(-35, 150), Pair(-15, 153),
        Pair(97, 164), Pair(36, 106), Pair(25, 132), Pair(65, 90), Pair(55, 101), Pair(-9, 120), Pair(-10, 110), Pair(11, 122),
        Pair(57, 158), Pair(32, 109), Pair(8, 123), Pair(-5, 120), Pair(19, 100), Pair(44, 90), Pair(24, 115), Pair(20, 93),
        Pair(22, 155), Pair(40, 111), Pair(17, 110), Pair(-2, 113), Pair(10, 96), Pair(39, 105), Pair(15, 105), Pair(69, 82),
        Pair(0, 0), Pair(47, 140), Pair(13, 132), Pair(28, 115), Pair(25, 117), Pair(31, 89), Pair(45, 119), Pair(54, 126),
        Pair(21, 158), Pair(75, -66), Pair(8, 137), Pair(11, 122), Pair(12, 121), Pair(8, 133), Pair(47, 106), Pair(-26, 155),
        Pair(-10, 141), Pair(24, 104), Pair(11, 129), Pair(15, 114), Pair(23, 113), Pair(14, 102), Pair(32, 102), Pair(46, 110)
      },
      { // Piece 4
        Pair(97, 164), Pair(190, 121), Pair(117, 158), Pair(-73, 268), Pair(134, 146), Pair(222, 159), Pair(62, 143), Pair(73, 211),
        Pair(109, 196), Pair(46, 225), Pair(52, 174), Pair(14, 252), Pair(-3, 240), Pair(29, 235), Pair(34, 244), Pair(91, 221),
        Pair(-3, 238), Pair(28, 221), Pair(35, 239), Pair(91, 200), Pair(19, 274), Pair(26, 226), Pair(85, 144), Pair(110, 141),
        Pair(63, 198), Pair(87, 188), Pair(54, 193), Pair(9, 249), Pair(72, 167), Pair(58, 194), Pair(64, 139), Pair(70, 169),
        Pair(69, 157), Pair(6, 252), Pair(21, 225), Pair(38, 167), Pair(36, 181), Pair(43, 147), Pair(57, 140), Pair(58, 156),
        Pair(0, 0), Pair(43, 200), Pair(27, 195), Pair(33, 161), Pair(33, 160), Pair(38, 165), Pair(62, 112), Pair(22, 161),
        Pair(-15, 204), Pair(31, 132), Pair(21, 200), Pair(37, 158), Pair(45, 142), Pair(47, 171), Pair(34, 132), Pair(35, 155),
        Pair(18, 193), Pair(-7, 190), Pair(29, 171), Pair(32, 156), Pair(46, 168), Pair(5, 216), Pair(36, 173), Pair(20, 295)
      },
      { // Piece 5
        Pair(-67, -70), Pair(-40, -29), Pair(-14, -38), Pair(205, -54), Pair(123, -19), Pair(135, -83), Pair(152, -69), Pair(218, -91),
        Pair(89, -115), Pair(-253, -35), Pair(95, -43), Pair(29, -24), Pair(85, -57), Pair(297, -77), Pair(268, -97), Pair(214, -49),
        Pair(65, -59), Pair(34, -7), Pair(124, -34), Pair(95, -16), Pair(118, -41), Pair(102, -34), Pair(239, -63), Pair(168, -69),
        Pair(25, -90), Pair(148, 4), Pair(-50, 9), Pair(100, -14), Pair(121, -27), Pair(173, -41), Pair(129, -53), Pair(138, -50),
        Pair(-85, 77), Pair(-189, 107), Pair(10, 0), Pair(53, -19), Pair(0, -4), Pair(17, -43), Pair(12, -37), Pair(85, -62),
        Pair(0, 0), Pair(-230, 123), Pair(-137, 64), Pair(-32, 15), Pair(15, -23), Pair(26, -40), Pair(43, -54), Pair(35, -50),
        Pair(31, 96), Pair(4, 32), Pair(-82, 59), Pair(-32, 6), Pair(20, -16), Pair(-30, -38), Pair(-23, -38), Pair(8, -44),
        Pair(-121, 167), Pair(-72, 102), Pair(-86, 20), Pair(-11, -10), Pair(-43, -24), Pair(10, -65), Pair(-11, -66), Pair(1, -69)
      }
    }},
    {{ // Bucket 17
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-58, 24), Pair(-18, 10), Pair(22, 10), Pair(12, 17), Pair(0, 16), Pair(-6, 1), Pair(-37, 21), Pair(-69, 47),
        Pair(-12, 15), Pair(0, 0), Pair(4, -5), Pair(12, -1), Pair(25, 3), Pair(1, 7), Pair(2, 7), Pair(2, 14),
        Pair(4, -11), Pair(7, -5), Pair(11, -11), Pair(6, -9), Pair(1, -9), Pair(7, 1), Pair(9, -6), Pair(2, 5),
        Pair(11, -13), Pair(1, -9), Pair(11, -9), Pair(1, -8), Pair(-3, -16), Pair(-7, -9), Pair(-8, -11), Pair(1, -6),
        Pair(9, -1), Pair(0, 0), Pair(13, -7), Pair(-7, -2), Pair(-5, -6), Pair(-6, -9), Pair(-11, -10), Pair(-8, -13),
        Pair(25, 19), Pair(33, 53), Pair(6, 5), Pair(-3, 7), Pair(-2, -11), Pair(-6, -14), Pair(-9, -6), Pair(-10, -5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(59, -8), Pair(-107, -95), Pair(-7, 69), Pair(-42, 9), Pair(-84, 75), Pair(49, -20), Pair(-69, -62), Pair(-58, 76),
        Pair(144, -5), Pair(93, 37), Pair(30, 44), Pair(56, 1), Pair(78, 20), Pair(10, 17), Pair(-30, 46), Pair(16, -9),
        Pair(128, -27), Pair(51, 64), Pair(30, 50), Pair(23, 51), Pair(51, 54), Pair(51, 68), Pair(70, 2), Pair(5, -4),
        Pair(52, 62), Pair(23, 46), Pair(31, 85), Pair(26, 56), Pair(59, 61), Pair(51, 30), Pair(56, 5), Pair(78, 7),
        Pair(-4, 135), Pair(9, 58), Pair(5, 146), Pair(5, 41), Pair(28, 60), Pair(43, 40), Pair(33, 47), Pair(33, 35),
        Pair(-29, 114), Pair(0, 0), Pair(28, 61), Pair(23, 134), Pair(3, 81), Pair(34, 66), Pair(21, 24), Pair(68, 18),
        Pair(-14, -16), Pair(28, 190), Pair(-31, 82), Pair(51, 67), Pair(22, 50), Pair(16, 63), Pair(38, -7), Pair(21, 76),
        Pair(-100, 8), Pair(22, 94), Pair(77, 26), Pair(-1, 124), Pair(33, -36), Pair(26, 38), Pair(30, -52), Pair(29, -8)
      },
      { // Piece 2
        Pair(22, 4), Pair(19, 98), Pair(-83, 72), Pair(-26, 102), Pair(-200, 70), Pair(-21, 131), Pair(-39, 110), Pair(-12, 214),
        Pair(-38, 85), Pair(-43, 97), Pair(0, 107), Pair(-23, 76), Pair(-20, 152), Pair(14, 119), Pair(-10, 202), Pair(-59, 112),
        Pair(-15, 101), Pair(-66, 59), Pair(44, 61), Pair(-17, 85), Pair(11, 86), Pair(-34, 197), Pair(-32, 159), Pair(23, 81),
        Pair(34, 52), Pair(33, 79), Pair(-54, 134), Pair(33, 85), Pair(-9, 166), Pair(11, 141), Pair(-12, 78), Pair(54, 49),
        Pair(-10, 45), Pair(-11, 54), Pair(4, 75), Pair(-37, 184), Pair(-19, 123), Pair(-18, 77), Pair(31, 85), Pair(-10, 50),
        Pair(-6, 184), Pair(0, 0), Pair(-3, 155), Pair(-26, 114), Pair(-1, 69), Pair(-21, 99), Pair(7, 64), Pair(5, 62),
        Pair(-147, 120), Pair(38, 243), Pair(18, -11), Pair(2, 54), Pair(-3, 90), Pair(-18, 74), Pair(-1, 57), Pair(13, 38),
        Pair(-84, 255), Pair(-35, 72), Pair(-41, 152), Pair(-13, 94), Pair(-61, 70), Pair(-5, 103), Pair(-71, 86), Pair(-32, 94)
      },
      { // Piece 3
        Pair(91, 99), Pair(66, 151), Pair(24, 121), Pair(63, 95), Pair(109, 92), Pair(139, 74), Pair(138, 80), Pair(85, 100),
        Pair(52, 100), Pair(58, 146), Pair(10, 131), Pair(16, 134), Pair(34, 100), Pair(115, 60), Pair(149, 78), Pair(97, 82),
        Pair(19, 87), Pair(100, 137), Pair(38, 120), Pair(58, 83), Pair(48, 108), Pair(34, 89), Pair(109, 61), Pair(79, 77),
        Pair(14, 105), Pair(55, 152), Pair(7, 114), Pair(60, 99), Pair(-4, 115), Pair(21, 106), Pair(34, 88), Pair(-6, 108),
        Pair(-29, 95), Pair(-11, 166), Pair(22, 110), Pair(-21, 123), Pair(-4, 107), Pair(-20, 118), Pair(52, 93), Pair(46, 57),
        Pair(5, 109), Pair(0, 0), Pair(28, 115), Pair(61, 123), Pair(-8, 125), Pair(58, 73), Pair(45, 50), Pair(45, 138),
        Pair(-80, 111), Pair(2, 160), Pair(22, 79), Pair(-40, 143), Pair(-1, 111), Pair(25, 115), Pair(-17, 150), Pair(-24, 164),
        Pair(-12, 100), Pair(-12, 150), Pair(-1, 120), Pair(-2, 104), Pair(7, 113), Pair(6, 132), Pair(38, 97), Pair(25, 105)
      },
      { // Piece 4
        Pair(163, 40), Pair(144, 137), Pair(0, 216), Pair(74, 189), Pair(83, 154), Pair(136, 151), Pair(37, 225), Pair(62, 181),
        Pair(101, 115), Pair(86, 140), Pair(121, 102), Pair(39, 188), Pair(109, 186), Pair(107, 245), Pair(58, 223), Pair(-50, 237),
        Pair(14, 236), Pair(116, 104), Pair(101, 111), Pair(25, 180), Pair(50, 206), Pair(66, 166), Pair(88, 204), Pair(100, 71),
        Pair(104, 41), Pair(82, 122), Pair(8, 207), Pair(65, 157), Pair(79, 182), Pair(58, 164), Pair(53, 145), Pair(101, 96),
        Pair(30, 193), Pair(82, 86), Pair(-13, 241), Pair(45, 245), Pair(64, 124), Pair(61, 116), Pair(31, 153), Pair(43, 189),
        Pair(50, 187), Pair(0, 0), Pair(46, 183), Pair(32, 156), Pair(32, 152), Pair(62, 172), Pair(60, 139), Pair(73, 153),
        Pair(47, -43), Pair(70, 115), Pair(78, 83), Pair(38, 135), Pair(41, 140), Pair(86, 98), Pair(63, 71), Pair(57, 40),
        Pair(34, 133), Pair(40, 108), Pair(15, 177), Pair(44, 70), Pair(59, 136), Pair(53, 54), Pair(114, -19), Pair(4, 20)
      },
      { // Piece 5
        Pair(-77, -143), Pair(-100, -115), Pair(50, -3), Pair(-25, -9), Pair(-24, 32), Pair(-28, -57), Pair(-31, -8), Pair(63, -21),
        Pair(-62, -31), Pair(41, -7), Pair(-66, -30), Pair(-122, 42), Pair(192, -12), Pair(126, -6), Pair(22, -16), Pair(187, -83),
        Pair(153, -52), Pair(28, -2), Pair(163, 0), Pair(151, 11), Pair(68, -18), Pair(61, 10), Pair(58, -20), Pair(162, -67),
        Pair(15, -52), Pair(149, -43), Pair(67, 13), Pair(117, -6), Pair(94, 8), Pair(-23, 26), Pair(-12, -6), Pair(179, -64),
        Pair(70, 8), Pair(-163, 62), Pair(-58, 80), Pair(32, -5), Pair(-20, 10), Pair(-116, 16), Pair(-14, -39), Pair(175, -100),
        Pair(-308, 133), Pair(0, 0), Pair(-122, 92), Pair(-69, 27), Pair(-17, -2), Pair(-53, -12), Pair(52, -67), Pair(25, -48),
        Pair(108, 74), Pair(-74, 95), Pair(-37, 89), Pair(-130, 19), Pair(-74, -1), Pair(-1, -38), Pair(-12, -54), Pair(-2, -61),
        Pair(-101, 67), Pair(-96, 57), Pair(-78, 67), Pair(-88, 16), Pair(-73, -15), Pair(-14, -56), Pair(6, -78), Pair(23, -99)
      }
    }},
    {{ // Bucket 18
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-33, 39), Pair(0, 8), Pair(-25, -8), Pair(39, -17), Pair(22, 20), Pair(90, -9), Pair(-24, 26), Pair(-52, 49),
        Pair(-12, 7), Pair(-4, 5), Pair(0, 0), Pair(5, -8), Pair(-4, -7), Pair(13, 3), Pair(-20, 15), Pair(-8, 18),
        Pair(-1, -4), Pair(5, -6), Pair(-15, 2), Pair(5, 4), Pair(4, -1), Pair(-10, -7), Pair(7, -6), Pair(-9, 5),
        Pair(-4, -9), Pair(5, -16), Pair(1, -19), Pair(-5, -4), Pair(-6, -12), Pair(-2, -8), Pair(-6, -9), Pair(-6, -6),
        Pair(1, -6), Pair(-2, 1), Pair(0, 0), Pair(6, -8), Pair(-1, -7), Pair(-18, -7), Pair(-10, -8), Pair(-3, -2),
        Pair(8, -11), Pair(10, 15), Pair(24, 55), Pair(9, -34), Pair(0, -5), Pair(-16, -10), Pair(-9, -9), Pair(-3, -7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-84, 22), Pair(147, -17), Pair(66, -21), Pair(76, -1), Pair(235, -35), Pair(126, -10), Pair(84, -102), Pair(-73, 10),
        Pair(-43, 44), Pair(51, 20), Pair(3, 65), Pair(37, -12), Pair(91, 29), Pair(-1, 68), Pair(54, 78), Pair(-25, -58),
        Pair(165, 13), Pair(12, 48), Pair(29, 58), Pair(50, 50), Pair(61, 43), Pair(12, 19), Pair(4, 57), Pair(64, 2),
        Pair(44, 31), Pair(32, 62), Pair(52, 73), Pair(50, 66), Pair(46, 53), Pair(52, 47), Pair(23, 19), Pair(75, 23),
        Pair(48, 74), Pair(-21, 136), Pair(18, 64), Pair(12, 160), Pair(5, 64), Pair(19, 70), Pair(17, 70), Pair(42, 22),
        Pair(-17, 170), Pair(-11, 76), Pair(0, 0), Pair(-8, 92), Pair(-16, 159), Pair(29, 38), Pair(14, 55), Pair(50, 7),
        Pair(48, 160), Pair(-34, -117), Pair(44, 208), Pair(-5, -17), Pair(53, 88), Pair(35, 39), Pair(23, 11), Pair(5, 21),
        Pair(-40, 154), Pair(37, -28), Pair(14, 109), Pair(-8, 56), Pair(-13, 151), Pair(10, 27), Pair(24, 33), Pair(235, -139)
      },
      { // Piece 2
        Pair(-47, 99), Pair(-135, 80), Pair(-8, 118), Pair(-73, 89), Pair(-92, 119), Pair(80, 88), Pair(7, 129), Pair(43, 44),
        Pair(9, 63), Pair(7, 110), Pair(4, 83), Pair(12, 94), Pair(28, 69), Pair(-94, 140), Pair(-32, 174), Pair(-4, 190),
        Pair(30, 77), Pair(7, 108), Pair(21, 104), Pair(-12, 97), Pair(10, 103), Pair(-29, 121), Pair(-29, 202), Pair(24, 101),
        Pair(-47, 99), Pair(22, 87), Pair(17, 121), Pair(-7, 98), Pair(38, 109), Pair(-14, 189), Pair(-3, 103), Pair(37, 108),
        Pair(6, 179), Pair(-19, 67), Pair(42, 97), Pair(12, 110), Pair(-18, 170), Pair(2, 110), Pair(-9, 101), Pair(-7, 51),
        Pair(1, 62), Pair(-12, 179), Pair(0, 0), Pair(23, 162), Pair(1, 114), Pair(-9, 82), Pair(1, 43), Pair(-7, 67),
        Pair(-57, 149), Pair(60, -85), Pair(57, 241), Pair(10, 30), Pair(5, 99), Pair(-39, 128), Pair(7, 80), Pair(23, 31),
        Pair(-44, -25), Pair(-41, 190), Pair(3, 70), Pair(-60, 206), Pair(-16, 68), Pair(13, 97), Pair(52, 77), Pair(37, 72)
      },
      { // Piece 3
        Pair(-23, 127), Pair(57, 109), Pair(37, 139), Pair(67, 83), Pair(10, 103), Pair(98, 113), Pair(-54, 119), Pair(-69, 145),
        Pair(11, 104), Pair(11, 131), Pair(39, 136), Pair(-16, 122), Pair(-19, 129), Pair(55, 104), Pair(123, 64), Pair(19, 124),
        Pair(9, 109), Pair(-16, 122), Pair(18, 154), Pair(12, 104), Pair(-4, 112), Pair(-43, 119), Pair(-101, 98), Pair(48, 94),
        Pair(8, 79), Pair(11, 104), Pair(-11, 156), Pair(38, 92), Pair(-24, 109), Pair(9, 85), Pair(41, 93), Pair(50, 78),
        Pair(-11, 95), Pair(-3, 99), Pair(-26, 181), Pair(-17, 109), Pair(43, 108), Pair(48, 98), Pair(-17, 113), Pair(-32, 118),
        Pair(-26, 125), Pair(-25, 118), Pair(0, 0), Pair(16, 129), Pair(22, 91), Pair(-36, 122), Pair(-50, 96), Pair(-20, 70),
        Pair(-48, 157), Pair(-35, 56), Pair(-22, 189), Pair(-53, 67), Pair(-7, 142), Pair(-13, 131), Pair(40, 124), Pair(32, 142),
        Pair(-11, 110), Pair(1, 105), Pair(-39, 155), Pair(-13, 112), Pair(17, 87), Pair(4, 108), Pair(14, 102), Pair(-2, 105)
      },
      { // Piece 4
        Pair(66, 131), Pair(152, 95), Pair(79, 212), Pair(74, 153), Pair(116, 162), Pair(59, 138), Pair(40, 143), Pair(67, 117),
        Pair(68, 146), Pair(37, 171), Pair(62, 145), Pair(129, 99), Pair(-23, 289), Pair(92, 176), Pair(183, 64), Pair(44, 186),
        Pair(69, 111), Pair(85, 49), Pair(28, 202), Pair(45, 152), Pair(51, 166), Pair(47, 180), Pair(50, 221), Pair(97, 76),
        Pair(58, 89), Pair(90, 146), Pair(55, 127), Pair(9, 196), Pair(87, 95), Pair(27, 200), Pair(81, 95), Pair(79, 96),
        Pair(41, 171), Pair(77, 94), Pair(99, 74), Pair(40, 144), Pair(32, 213), Pair(56, 103), Pair(60, 174), Pair(23, 197),
        Pair(-52, 162), Pair(52, 104), Pair(0, 0), Pair(53, 176), Pair(48, 123), Pair(41, 157), Pair(73, 109), Pair(63, 250),
        Pair(58, 148), Pair(91, -169), Pair(58, 106), Pair(72, 22), Pair(40, 133), Pair(72, 105), Pair(58, 115), Pair(63, 172),
        Pair(-47, 180), Pair(8, 151), Pair(39, 73), Pair(39, 103), Pair(45, 96), Pair(102, 86), Pair(97, 37), Pair(13, 165)
      },
      { // Piece 5
        Pair(-39, 13), Pair(-170, -164), Pair(-64, -283), Pair(65, 76), Pair(6, -25), Pair(-49, -124), Pair(57, -104), Pair(-62, -112),
        Pair(-38, -69), Pair(30, -70), Pair(-20, -38), Pair(41, -18), Pair(19, -30), Pair(-26, -10), Pair(190, -70), Pair(-104, -64),
        Pair(99, -54), Pair(35, -20), Pair(213, -13), Pair(226, -3), Pair(156, -15), Pair(62, 26), Pair(84, 8), Pair(21, -46),
        Pair(131, -40), Pair(181, 3), Pair(109, -2), Pair(240, 4), Pair(184, -13), Pair(115, 11), Pair(55, -3), Pair(34, -52),
        Pair(258, -49), Pair(59, 47), Pair(-4, 58), Pair(-3, 78), Pair(-11, 24), Pair(13, 0), Pair(25, -31), Pair(-3, -64),
        Pair(25, 34), Pair(-101, 101), Pair(0, 0), Pair(-104, 81), Pair(-38, 17), Pair(-9, 11), Pair(-4, -14), Pair(56, -96),
        Pair(-216, 71), Pair(-9, 49), Pair(-155, 109), Pair(105, 60), Pair(-83, 35), Pair(-26, -6), Pair(-4, -33), Pair(11, -68),
        Pair(-97, 19), Pair(-100, 23), Pair(-162, 108), Pair(-66, 90), Pair(-46, -10), Pair(-62, 2), Pair(-14, -46), Pair(11, -77)
      }
    }},
    {{ // Bucket 19
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-32, 32), Pair(-38, 25), Pair(-14, 5), Pair(-12, 12), Pair(-49, 18), Pair(-8, 28), Pair(41, 22), Pair(-37, 33),
        Pair(-11, 9), Pair(-14, 2), Pair(-4, 8), Pair(0, 0), Pair(40, -12), Pair(16, 1), Pair(5, 15), Pair(-5, 3),
        Pair(-14, 2), Pair(-12, -8), Pair(-2, 0), Pair(-2, 0), Pair(3, 2), Pair(-5, -1), Pair(-5, -1), Pair(-1, -2),
        Pair(-5, -11), Pair(5, -13), Pair(-8, 3), Pair(10, -5), Pair(1, -4), Pair(-1, -3), Pair(-4, -10), Pair(-4, -1),
        Pair(-9, -7), Pair(2, -12), Pair(-4, -4), Pair(0, 0), Pair(3, -1), Pair(-9, 3), Pair(-7, -5), Pair(-8, -6),
        Pair(-7, -8), Pair(2, -1), Pair(13, -25), Pair(-7, 53), Pair(9, -31), Pair(-5, -1), Pair(1, -9), Pair(-5, -10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-52, 76), Pair(-444, 200), Pair(-32, 19), Pair(266, -40), Pair(-178, 95), Pair(68, -17), Pair(108, -47), Pair(234, -197),
        Pair(-8, 76), Pair(-6, 84), Pair(31, 66), Pair(-6, 91), Pair(-14, 82), Pair(-6, 106), Pair(134, 27), Pair(15, 112),
        Pair(-1, 79), Pair(11, 97), Pair(23, 78), Pair(11, 77), Pair(32, 63), Pair(10, 48), Pair(7, 91), Pair(-34, 23),
        Pair(-3, 88), Pair(17, 73), Pair(-13, 95), Pair(35, 85), Pair(16, 75), Pair(20, 95), Pair(22, 61), Pair(26, 44),
        Pair(26, 84), Pair(-34, 79), Pair(9, 165), Pair(9, 62), Pair(8, 156), Pair(37, 38), Pair(8, 78), Pair(19, 63),
        Pair(-33, 39), Pair(-25, 155), Pair(7, 68), Pair(0, 0), Pair(0, 73), Pair(0, 144), Pair(10, 29), Pair(22, 76),
        Pair(6, 18), Pair(13, 80), Pair(1, 1), Pair(25, 214), Pair(-20, -6), Pair(26, 88), Pair(19, 44), Pair(-16, 68),
        Pair(-96, -19), Pair(4, 103), Pair(18, 33), Pair(-6, 119), Pair(36, 14), Pair(-5, 174), Pair(36, -20), Pair(-36, 45)
      },
      { // Piece 2
        Pair(-56, 80), Pair(-261, 194), Pair(67, 28), Pair(-96, 136), Pair(-29, 99), Pair(33, 75), Pair(-217, 103), Pair(139, 110),
        Pair(66, 46), Pair(4, 67), Pair(-13, 91), Pair(-44, 128), Pair(-86, 120), Pair(-20, 119), Pair(-59, 138), Pair(24, 109),
        Pair(18, 68), Pair(-35, 122), Pair(1, 67), Pair(19, 74), Pair(5, 87), Pair(-13, 122), Pair(29, 105), Pair(-9, 183),
        Pair(-21, 175), Pair(-26, 96), Pair(39, 74), Pair(6, 74), Pair(17, 70), Pair(-86, 134), Pair(-15, 187), Pair(-6, 83),
        Pair(-6, 92), Pair(-4, 167), Pair(19, 82), Pair(35, 67), Pair(18, 95), Pair(-17, 158), Pair(-39, 93), Pair(-21, 120),
        Pair(11, 82), Pair(17, 79), Pair(-2, 169), Pair(0, 0), Pair(-7, 166), Pair(-3, 91), Pair(-16, 63), Pair(11, 38),
        Pair(-58, 62), Pair(13, 60), Pair(-30, -9), Pair(25, 215), Pair(15, -42), Pair(-35, 66), Pair(13, 55), Pair(-4, 44),
        Pair(39, 41), Pair(-34, 34), Pair(-10, 137), Pair(43, 94), Pair(-29, 183), Pair(14, 5), Pair(15, 32), Pair(-14, 15)
      },
      { // Piece 3
        Pair(76, 47), Pair(-4, 91), Pair(40, 101), Pair(52, 98), Pair(-11, 125), Pair(115, 96), Pair(127, 88), Pair(35, 103),
        Pair(26, 59), Pair(21, 103), Pair(-12, 132), Pair(-18, 160), Pair(19, 97), Pair(48, 103), Pair(-25, 100), Pair(17, 99),
        Pair(16, 93), Pair(-8, 84), Pair(-20, 96), Pair(26, 130), Pair(4, 90), Pair(78, 73), Pair(-32, 118), Pair(-20, 120),
        Pair(45, 68), Pair(-1, 93), Pair(3, 95), Pair(74, 106), Pair(35, 70), Pair(26, 106), Pair(17, 94), Pair(60, 62),
        Pair(-34, 100), Pair(-31, 111), Pair(-7, 88), Pair(-29, 160), Pair(-14, 112), Pair(22, 126), Pair(3, 76), Pair(37, 81),
        Pair(17, 102), Pair(-12, 103), Pair(20, 114), Pair(0, 0), Pair(39, 66), Pair(40, 94), Pair(70, 35), Pair(-14, 64),
        Pair(31, 113), Pair(-25, 138), Pair(88, 12), Pair(14, 165), Pair(33, 35), Pair(-9, 136), Pair(4, 121), Pair(2, 127),
        Pair(2, 95), Pair(11, 84), Pair(-9, 97), Pair(-35, 157), Pair(0, 93), Pair(9, 101), Pair(1, 114), Pair(22, 102)
      },
      { // Piece 4
        Pair(28, 99), Pair(35, 133), Pair(55, 134), Pair(8, 225), Pair(-2, 223), Pair(-23, 209), Pair(11, 146), Pair(1, 200),
        Pair(60, 139), Pair(21, 180), Pair(56, 150), Pair(72, 135), Pair(76, 165), Pair(80, 216), Pair(110, 18), Pair(98, 40),
        Pair(67, 88), Pair(17, 119), Pair(60, 59), Pair(70, 205), Pair(26, 219), Pair(17, 207), Pair(2, 213), Pair(65, 185),
        Pair(-1, 191), Pair(113, 68), Pair(82, 73), Pair(88, 154), Pair(14, 165), Pair(21, 205), Pair(72, 189), Pair(53, 104),
        Pair(74, 42), Pair(11, 171), Pair(47, 72), Pair(75, 111), Pair(50, 136), Pair(56, 155), Pair(39, 146), Pair(45, 198),
        Pair(67, 57), Pair(44, 62), Pair(52, 123), Pair(0, 0), Pair(59, 123), Pair(47, 105), Pair(72, 52), Pair(75, 124),
        Pair(42, 107), Pair(19, 139), Pair(47, -62), Pair(48, 119), Pair(-7, 80), Pair(43, 127), Pair(61, 153), Pair(72, 124),
        Pair(13, 128), Pair(70, 31), Pair(-8, 184), Pair(32, 84), Pair(32, 142), Pair(65, 75), Pair(84, 27), Pair(92, 22)
      },
      { // Piece 5
        Pair(-33, -97), Pair(15, -73), Pair(38, -103), Pair(4, -52), Pair(-48, -82), Pair(-68, -21), Pair(-107, -124), Pair(-270, -44),
        Pair(65, 9), Pair(24, -58), Pair(31, -19), Pair(4, -54), Pair(-174, 5), Pair(-56, -51), Pair(-78, -9), Pair(25, -77),
        Pair(126, -68), Pair(-32, 4), Pair(108, -22), Pair(-13, -5), Pair(170, -8), Pair(-39, -5), Pair(-138, 28), Pair(-23, -18),
        Pair(73, -90), Pair(37, -38), Pair(278, -40), Pair(177, -26), Pair(73, 22), Pair(37, 1), Pair(-38, 1), Pair(-42, -23),
        Pair(-86, -26), Pair(85, 4), Pair(-59, 57), Pair(-31, 54), Pair(7, 77), Pair(84, -8), Pair(39, -18), Pair(3, -40),
        Pair(114, -21), Pair(-83, 25), Pair(-16, 57), Pair(0, 0), Pair(-19, 46), Pair(-46, 18), Pair(28, -12), Pair(39, -53),
        Pair(-3, -24), Pair(-61, 21), Pair(-40, 28), Pair(-69, 71), Pair(80, -11), Pair(-67, 22), Pair(-11, -15), Pair(33, -56),
        Pair(36, -45), Pair(-76, 12), Pair(-64, 63), Pair(-76, 71), Pair(-34, 69), Pair(-95, 14), Pair(3, -30), Pair(42, -71)
      }
    }},
    {{ // Bucket 20
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-13, 26), Pair(19, -3), Pair(-31, 24), Pair(-26, 13), Pair(-103, 36), Pair(36, 4), Pair(-16, 11), Pair(-29, 32),
        Pair(-6, -4), Pair(-25, -2), Pair(4, 9), Pair(-40, 13), Pair(0, 0), Pair(5, -2), Pair(20, -2), Pair(-3, 12),
        Pair(-10, -12), Pair(-13, -7), Pair(-13, -6), Pair(3, -5), Pair(-4, -3), Pair(-18, 4), Pair(13, -6), Pair(7, 0),
        Pair(-10, -4), Pair(-11, -16), Pair(1, -7), Pair(-7, -11), Pair(10, -17), Pair(-2, -6), Pair(5, -3), Pair(8, -8),
        Pair(-5, -8), Pair(-6, -14), Pair(-11, -8), Pair(2, 2), Pair(0, 0), Pair(-2, -4), Pair(-2, 2), Pair(-5, -2),
        Pair(-16, -7), Pair(-2, -12), Pair(3, -5), Pair(6, 11), Pair(12, 35), Pair(-14, -8), Pair(7, -3), Pair(5, -6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-83, 124), Pair(-51, 105), Pair(-34, 8), Pair(-172, 69), Pair(-222, 121), Pair(199, -31), Pair(145, 43), Pair(91, -102),
        Pair(97, -4), Pair(3, 35), Pair(59, 24), Pair(85, 18), Pair(-97, 50), Pair(-23, 88), Pair(-104, 10), Pair(90, -39),
        Pair(-151, 89), Pair(-5, 37), Pair(8, 49), Pair(-32, 56), Pair(-17, 38), Pair(37, 75), Pair(38, 40), Pair(113, 42),
        Pair(-26, 61), Pair(-12, 46), Pair(-41, 63), Pair(25, 57), Pair(-10, 44), Pair(-11, 50), Pair(-29, 38), Pair(-20, 20),
        Pair(-40, 44), Pair(-68, 83), Pair(2, 44), Pair(-25, 109), Pair(-22, 9), Pair(-6, 116), Pair(-53, 30), Pair(11, 26),
        Pair(18, 11), Pair(-49, 78), Pair(-27, 110), Pair(-12, 64), Pair(0, 0), Pair(-11, 64), Pair(14, 99), Pair(-32, 83),
        Pair(-30, 2), Pair(-64, 54), Pair(17, 92), Pair(-39, 6), Pair(26, 163), Pair(-21, -46), Pair(-20, 88), Pair(14, 78),
        Pair(-187, 229), Pair(-46, 4), Pair(28, 156), Pair(-24, 47), Pair(-34, 69), Pair(-41, 52), Pair(-7, 91), Pair(-251, -42)
      },
      { // Piece 2
        Pair(-36, 88), Pair(-219, 109), Pair(-29, 99), Pair(10, -2), Pair(-177, 158), Pair(-132, 94), Pair(95, 61), Pair(228, 107),
        Pair(73, 71), Pair(-56, 107), Pair(56, 58), Pair(-8, 114), Pair(-39, 79), Pair(-61, 102), Pair(-54, 74), Pair(4, 70),
        Pair(-27, 200), Pair(-58, 139), Pair(-32, 81), Pair(-17, 45), Pair(-69, 114), Pair(-64, 75), Pair(-76, 94), Pair(68, 18),
        Pair(-43, 74), Pair(-42, 157), Pair(-18, 71), Pair(-45, 95), Pair(-23, 57), Pair(-24, 78), Pair(-28, 79), Pair(35, 115),
        Pair(-40, 97), Pair(-3, 88), Pair(-37, 152), Pair(31, 61), Pair(-30, 90), Pair(-42, 68), Pair(-1, 136), Pair(19, 88),
        Pair(0, 33), Pair(-11, 37), Pair(-28, 80), Pair(-11, 161), Pair(0, 0), Pair(4, 121), Pair(-22, 90), Pair(-6, 61),
        Pair(-45, 56), Pair(20, 24), Pair(-27, 80), Pair(5, -18), Pair(10, 174), Pair(1, -23), Pair(-21, 76), Pair(37, 14),
        Pair(14, 22), Pair(-16, 74), Pair(1, -2), Pair(26, 136), Pair(-2, 63), Pair(-48, 156), Pair(-94, 65), Pair(-9, 53)
      },
      { // Piece 3
        Pair(-8, 71), Pair(-41, 90), Pair(-40, 67), Pair(44, 65), Pair(19, 70), Pair(-11, 87), Pair(-87, 132), Pair(33, 64),
        Pair(-59, 95), Pair(-11, 52), Pair(-3, 53), Pair(17, 58), Pair(-25, 93), Pair(2, 60), Pair(69, 39), Pair(-32, 81),
        Pair(-31, 75), Pair(-68, 72), Pair(-15, 67), Pair(-2, 64), Pair(0, 65), Pair(-23, 62), Pair(61, 57), Pair(58, 31),
        Pair(-53, 65), Pair(-7, 41), Pair(6, 52), Pair(0, 75), Pair(48, 92), Pair(14, 15), Pair(-34, 79), Pair(-21, 59),
        Pair(-33, 90), Pair(-10, 54), Pair(-11, 66), Pair(34, 47), Pair(45, 79), Pair(7, 60), Pair(64, 32), Pair(23, 34),
        Pair(-5, 77), Pair(9, 48), Pair(11, 42), Pair(-41, 71), Pair(0, 0), Pair(-25, 65), Pair(52, 32), Pair(-36, 28),
        Pair(-61, 107), Pair(-1, 80), Pair(-49, 117), Pair(-33, -49), Pair(-32, 137), Pair(-53, 63), Pair(2, 95), Pair(-45, 62),
        Pair(-29, 86), Pair(-40, 76), Pair(-31, 68), Pair(-38, 64), Pair(-41, 123), Pair(-21, 59), Pair(17, 57), Pair(-17, 63)
      },
      { // Piece 4
        Pair(-24, 144), Pair(29, 91), Pair(-135, 244), Pair(122, 3), Pair(-8, 163), Pair(-37, 197), Pair(-46, 235), Pair(137, 55),
        Pair(23, 50), Pair(15, 138), Pair(5, 79), Pair(12, 152), Pair(22, 96), Pair(38, 74), Pair(46, 75), Pair(5, 58),
        Pair(10, 84), Pair(75, 62), Pair(85, -13), Pair(-3, 86), Pair(-18, 181), Pair(8, 202), Pair(74, 18), Pair(37, 101),
        Pair(-1, 34), Pair(21, 94), Pair(15, 68), Pair(4, 97), Pair(11, 146), Pair(17, 143), Pair(86, 6), Pair(3, 133),
        Pair(23, 56), Pair(-47, 114), Pair(-21, 157), Pair(42, 56), Pair(48, 88), Pair(77, -2), Pair(12, 139), Pair(9, 77),
        Pair(48, 59), Pair(27, 13), Pair(17, 57), Pair(48, 68), Pair(0, 0), Pair(28, 65), Pair(-4, 67), Pair(-9, 40),
        Pair(54, -20), Pair(62, 23), Pair(-13, 98), Pair(18, -13), Pair(21, 79), Pair(25, -137), Pair(9, 174), Pair(-78, 156),
        Pair(18, 82), Pair(-15, 131), Pair(-15, 91), Pair(2, 55), Pair(-5, 13), Pair(11, 104), Pair(-69, 33), Pair(115, -82)
      },
      { // Piece 5
        Pair(-11, -107), Pair(46, -85), Pair(-73, -131), Pair(-132, -58), Pair(-74, -132), Pair(-27, 34), Pair(9, -68), Pair(-16, -59),
        Pair(88, -125), Pair(-35, -29), Pair(-62, -19), Pair(-11, 8), Pair(-75, -6), Pair(35, -28), Pair(4, -29), Pair(-30, -53),
        Pair(-114, -28), Pair(16, 8), Pair(54, -15), Pair(307, -89), Pair(204, -60), Pair(326, -9), Pair(4, 23), Pair(67, -33),
        Pair(-50, -68), Pair(6, -20), Pair(58, -37), Pair(58, -43), Pair(-18, 26), Pair(131, -27), Pair(35, -19), Pair(55, -23),
        Pair(94, -78), Pair(94, -27), Pair(-63, 14), Pair(-27, 37), Pair(-140, 72), Pair(2, 46), Pair(-15, 0), Pair(31, -52),
        Pair(101, -68), Pair(85, -49), Pair(25, -27), Pair(-124, 59), Pair(0, 0), Pair(-10, 35), Pair(-37, 2), Pair(29, -19),
        Pair(105, -58), Pair(-22, -6), Pair(-35, -5), Pair(-78, 16), Pair(-107, 69), Pair(109, -5), Pair(-43, 11), Pair(-8, -17),
        Pair(62, -8), Pair(-19, -67), Pair(-54, -20), Pair(-12, 60), Pair(-8, 45), Pair(-47, 46), Pair(-47, -10), Pair(-35, -7)
      }
    }},
    {{ // Bucket 21
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(16, 4), Pair(-13, 20), Pair(-8, 19), Pair(-11, 11), Pair(-18, -5), Pair(70, -13), Pair(-15, 8), Pair(25, 28),
        Pair(8, -12), Pair(1, -7), Pair(-11, -3), Pair(-17, -1), Pair(-4, 2), Pair(0, 0), Pair(-17, 11), Pair(-2, 2),
        Pair(3, -17), Pair(-6, -16), Pair(-6, -14), Pair(-3, -7), Pair(13, -13), Pair(-30, -1), Pair(-1, -9), Pair(8, -6),
        Pair(-3, -12), Pair(-17, -13), Pair(-8, -19), Pair(-3, -16), Pair(-4, -7), Pair(10, -14), Pair(16, -8), Pair(17, -7),
        Pair(4, -19), Pair(-8, -17), Pair(-4, -10), Pair(-12, 1), Pair(5, -8), Pair(0, 0), Pair(9, -16), Pair(19, -9),
        Pair(7, -16), Pair(-6, -20), Pair(3, -14), Pair(14, -13), Pair(11, 1), Pair(13, 9), Pair(14, -5), Pair(22, -6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(26, -11), Pair(-31, 29), Pair(36, 67), Pair(-8, 14), Pair(8, 13), Pair(-66, 0), Pair(-111, 5), Pair(173, -68),
        Pair(-32, 59), Pair(18, 8), Pair(-59, 24), Pair(-60, 76), Pair(52, 43), Pair(50, 23), Pair(-61, 24), Pair(-152, 101),
        Pair(-38, 16), Pair(-12, 19), Pair(-25, 70), Pair(6, 30), Pair(2, 71), Pair(108, 48), Pair(15, 39), Pair(-62, 49),
        Pair(-10, 13), Pair(-39, 32), Pair(-5, 25), Pair(2, 46), Pair(27, 59), Pair(-8, 70), Pair(52, 63), Pair(83, 1),
        Pair(-38, 61), Pair(-76, 38), Pair(18, 20), Pair(18, 19), Pair(-12, 112), Pair(15, 4), Pair(-19, 103), Pair(22, 24),
        Pair(18, 28), Pair(-14, 53), Pair(-17, 28), Pair(-23, 101), Pair(19, 43), Pair(0, 0), Pair(-1, 20), Pair(-4, 19),
        Pair(36, -10), Pair(-31, 41), Pair(20, 44), Pair(27, 64), Pair(-29, 3), Pair(-40, 163), Pair(-45, -22), Pair(-1, 73),
        Pair(0, -62), Pair(-24, 86), Pair(-7, -22), Pair(-41, 112), Pair(-16, 19), Pair(30, 15), Pair(-59, -63), Pair(-309, 138)
      },
      { // Piece 2
        Pair(-9, 108), Pair(-47, 96), Pair(44, 40), Pair(-97, 77), Pair(-140, 109), Pair(-63, 131), Pair(15, 26), Pair(-102, 52),
        Pair(-53, 127), Pair(-9, 105), Pair(-16, 107), Pair(-61, 77), Pair(-87, 84), Pair(-60, 68), Pair(-56, 61), Pair(25, 46),
        Pair(-24, 66), Pair(-60, 131), Pair(-41, 72), Pair(-63, 71), Pair(-37, 57), Pair(30, 92), Pair(-42, 118), Pair(-49, 89),
        Pair(-46, 65), Pair(2, 54), Pair(-93, 122), Pair(-9, 58), Pair(-33, 89), Pair(-1, 118), Pair(16, 50), Pair(-21, 26),
        Pair(-47, 45), Pair(-45, 77), Pair(-23, 60), Pair(-60, 82), Pair(-16, 42), Pair(4, 66), Pair(-30, 75), Pair(-107, 119),
        Pair(-39, 40), Pair(25, 34), Pair(-25, 62), Pair(10, 50), Pair(-21, 80), Pair(0, 0), Pair(-73, 109), Pair(9, 18),
        Pair(37, 132), Pair(-14, 28), Pair(-8, 70), Pair(-42, 46), Pair(15, -17), Pair(-15, 179), Pair(42, -110), Pair(-93, 43),
        Pair(-23, -5), Pair(-11, 55), Pair(-14, 46), Pair(-17, 34), Pair(-62, 96), Pair(-4, 21), Pair(-158, 183), Pair(-110, -56)
      },
      { // Piece 3
        Pair(-62, 72), Pair(-43, 59), Pair(-31, 68), Pair(-62, 77), Pair(-39, 83), Pair(-6, 67), Pair(-33, 64), Pair(39, 71),
        Pair(-11, 56), Pair(-45, 45), Pair(37, 25), Pair(-29, 35), Pair(-83, 92), Pair(46, 75), Pair(8, 54), Pair(-38, 48),
        Pair(4, 33), Pair(-60, 55), Pair(-7, 47), Pair(-37, 54), Pair(14, 50), Pair(45, 66), Pair(-45, 68), Pair(41, 28),
        Pair(2, 34), Pair(-39, 61), Pair(-17, 35), Pair(-48, 70), Pair(-25, 41), Pair(55, 60), Pair(15, 43), Pair(51, 41),
        Pair(-19, 23), Pair(-80, 83), Pair(-20, 53), Pair(-43, 39), Pair(-16, 54), Pair(-11, 88), Pair(56, 22), Pair(4, 66),
        Pair(-5, 38), Pair(29, 19), Pair(-6, 16), Pair(-29, 55), Pair(-19, 58), Pair(0, 0), Pair(119, -9), Pair(32, -31),
        Pair(-15, 38), Pair(-65, 85), Pair(-49, 61), Pair(-18, 53), Pair(4, -120), Pair(-34, 119), Pair(145, -100), Pair(-3, 59),
        Pair(-26, 29), Pair(-34, 45), Pair(-39, 39), Pair(-14, 40), Pair(-30, 36), Pair(-42, 51), Pair(-13, 32), Pair(-15, 24)
      },
      { // Piece 4
        Pair(-56, 75), Pair(-42, 124), Pair(-9, 35), Pair(20, -4), Pair(-65, 156), Pair(-3, 87), Pair(72, 31), Pair(-67, 137),
        Pair(-24, 58), Pair(-37, 81), Pair(22, 67), Pair(-23, 41), Pair(-40, 153), Pair(77, 35), Pair(-98, 173), Pair(94, -69),
        Pair(0, -9), Pair(-30, 67), Pair(-8, 90), Pair(12, 89), Pair(28, 31), Pair(90, 3), Pair(79, -54), Pair(16, -3),
        Pair(24, 25), Pair(17, -16), Pair(-25, 54), Pair(-47, 104), Pair(-25, 76), Pair(59, 14), Pair(20, -14), Pair(45, 10),
        Pair(-18, -5), Pair(-10, 59), Pair(-2, -6), Pair(-3, 61), Pair(-41, 98), Pair(27, 82), Pair(-13, 27), Pair(-33, 77),
        Pair(6, -1), Pair(-10, 30), Pair(-5, 45), Pair(14, 21), Pair(23, 40), Pair(0, 0), Pair(-9, 1), Pair(-8, -11),
        Pair(-48, 60), Pair(-34, 88), Pair(-40, 29), Pair(-28, 44), Pair(45, -54), Pair(-37, 66), Pair(-113, 44), Pair(-20, 69),
        Pair(-59, 97), Pair(0, -21), Pair(-30, 28), Pair(13, -41), Pair(-47, 73), Pair(9, -27), Pair(-48, 146), Pair(-2, 133)
      },
      { // Piece 5
        Pair(121, -39), Pair(-26, -58), Pair(-68, -118), Pair(-228, 5), Pair(-103, -23), Pair(40, -122), Pair(34, -164), Pair(10, 32),
        Pair(30, -78), Pair(75, -85), Pair(254, -66), Pair(88, -80), Pair(-60, -6), Pair(9, -12), Pair(100, -32), Pair(98, -59),
        Pair(123, -118), Pair(-125, -19), Pair(38, -3), Pair(-41, 4), Pair(96, 12), Pair(135, 4), Pair(56, 0), Pair(56, -82),
        Pair(54, -93), Pair(109, -64), Pair(17, -20), Pair(81, -8), Pair(229, -28), Pair(154, 18), Pair(81, -7), Pair(255, -60),
        Pair(262, -99), Pair(57, -68), Pair(69, -34), Pair(97, -21), Pair(-3, 48), Pair(17, 48), Pair(42, 35), Pair(33, 16),
        Pair(0, -38), Pair(85, -87), Pair(50, -28), Pair(-44, -11), Pair(-43, 26), Pair(0, 0), Pair(-32, 37), Pair(14, 55),
        Pair(3, -73), Pair(16, -35), Pair(32, -31), Pair(-62, 29), Pair(157, -1), Pair(-96, 51), Pair(-29, 34), Pair(-105, 55),
        Pair(16, -75), Pair(-16, -9), Pair(-33, -21), Pair(-25, -17), Pair(-23, 35), Pair(-132, 61), Pair(-56, 29), Pair(-79, 43)
      }
    }},
    {{ // Bucket 22
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-36, 13), Pair(-34, 10), Pair(34, -16), Pair(16, -10), Pair(-80, 15), Pair(-3, -6), Pair(-24, 23), Pair(5, -7),
        Pair(7, -8), Pair(-1, -8), Pair(20, -15), Pair(-7, -16), Pair(-20, 3), Pair(17, -13), Pair(0, 0), Pair(13, 0),
        Pair(-4, -12), Pair(5, -18), Pair(8, -12), Pair(1, -10), Pair(-1, -5), Pair(4, -11), Pair(8, 3), Pair(7, -2),
        Pair(-3, -19), Pair(1, -19), Pair(-1, -15), Pair(2, -17), Pair(2, -12), Pair(-2, -4), Pair(-7, -5), Pair(8, -1),
        Pair(3, -23), Pair(-12, -12), Pair(3, -17), Pair(6, -12), Pair(-6, -2), Pair(-5, -1), Pair(0, 0), Pair(14, -4),
        Pair(-10, -18), Pair(-10, -13), Pair(19, -11), Pair(-8, -8), Pair(-14, -10), Pair(0, -15), Pair(2, 18), Pair(19, 5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(57, 17), Pair(81, -86), Pair(1, 5), Pair(-179, 42), Pair(114, 33), Pair(-76, 41), Pair(126, -10), Pair(0, -13),
        Pair(9, 32), Pair(50, -10), Pair(-19, 76), Pair(64, 32), Pair(-25, 69), Pair(5, 33), Pair(67, -6), Pair(38, -14),
        Pair(-30, -16), Pair(-35, 24), Pair(11, 0), Pair(3, 11), Pair(7, 42), Pair(-39, 44), Pair(38, 25), Pair(-22, 99),
        Pair(17, 3), Pair(-52, 58), Pair(-18, 26), Pair(-41, 50), Pair(14, 30), Pair(4, 61), Pair(1, 65), Pair(-31, 53),
        Pair(0, -4), Pair(-43, 26), Pair(-24, 18), Pair(23, 38), Pair(-1, 49), Pair(-24, 88), Pair(-54, 26), Pair(-20, 93),
        Pair(-44, 10), Pair(11, -14), Pair(-1, 52), Pair(-4, 26), Pair(1, 93), Pair(7, 22), Pair(0, 0), Pair(32, 39),
        Pair(49, 14), Pair(49, -14), Pair(15, 34), Pair(-20, 62), Pair(14, 23), Pair(57, -17), Pair(-28, 109), Pair(-23, -14),
        Pair(76, -68), Pair(-5, -9), Pair(25, -22), Pair(35, 5), Pair(-34, 74), Pair(34, 58), Pair(-22, 72), Pair(-146, 37)
      },
      { // Piece 2
        Pair(-57, 166), Pair(-31, 128), Pair(-343, 122), Pair(-248, 92), Pair(-182, 99), Pair(-30, 13), Pair(-274, 100), Pair(-68, 16),
        Pair(-116, 85), Pair(-86, 150), Pair(-31, 105), Pair(-1, 101), Pair(-95, 88), Pair(-121, 89), Pair(-172, 113), Pair(20, 50),
        Pair(-53, 69), Pair(-102, 103), Pair(-148, 159), Pair(-61, 131), Pair(22, 75), Pair(-129, 119), Pair(-7, 87), Pair(-36, 58),
        Pair(-52, 4), Pair(-18, 80), Pair(-17, 70), Pair(-73, 136), Pair(-74, 101), Pair(5, 88), Pair(-17, 44), Pair(-23, 36),
        Pair(-47, 56), Pair(-38, 78), Pair(-38, 55), Pair(-54, 103), Pair(-50, 111), Pair(-55, 68), Pair(-14, 74), Pair(-34, 32),
        Pair(1, 48), Pair(-33, 25), Pair(-41, 84), Pair(-28, 44), Pair(-40, 60), Pair(-25, 118), Pair(0, 0), Pair(11, 161),
        Pair(-72, 63), Pair(-25, 33), Pair(-40, 46), Pair(-22, 60), Pair(-60, 60), Pair(-95, 45), Pair(-5, 193), Pair(-100, 80),
        Pair(107, -61), Pair(-15, 35), Pair(-11, 17), Pair(-50, 27), Pair(-8, 55), Pair(-47, 95), Pair(-113, 83), Pair(-74, 181)
      },
      { // Piece 3
        Pair(-74, 76), Pair(57, 43), Pair(24, 54), Pair(27, 56), Pair(-80, 80), Pair(-4, 61), Pair(137, 28), Pair(-135, 94),
        Pair(68, 12), Pair(9, 19), Pair(-22, 30), Pair(41, 13), Pair(6, 43), Pair(25, 35), Pair(71, 65), Pair(48, 58),
        Pair(-35, 28), Pair(14, 30), Pair(3, 39), Pair(49, 33), Pair(-24, 52), Pair(15, 44), Pair(18, 66), Pair(50, 32),
        Pair(27, 33), Pair(33, 10), Pair(32, 31), Pair(-13, 25), Pair(4, 14), Pair(36, 28), Pair(6, 61), Pair(35, 24),
        Pair(38, 34), Pair(-19, 35), Pair(30, 34), Pair(6, 58), Pair(28, 35), Pair(66, -24), Pair(-27, 96), Pair(87, 25),
        Pair(9, 34), Pair(37, 6), Pair(1, 23), Pair(3, 17), Pair(40, 14), Pair(21, 70), Pair(0, 0), Pair(-28, 49),
        Pair(-56, 107), Pair(-9, 62), Pair(34, 71), Pair(10, 64), Pair(0, 73), Pair(20, -122), Pair(-35, 87), Pair(109, -124),
        Pair(9, 37), Pair(47, -1), Pair(17, 23), Pair(13, 22), Pair(-10, 32), Pair(28, 21), Pair(-46, 71), Pair(-13, 56)
      },
      { // Piece 4
        Pair(-33, 139), Pair(-21, 93), Pair(9, 48), Pair(113, -17), Pair(253, -99), Pair(-149, 177), Pair(136, -12), Pair(121, 25),
        Pair(101, -97), Pair(-41, 108), Pair(19, 67), Pair(27, 63), Pair(-106, 161), Pair(53, 49), Pair(108, -43), Pair(126, -132),
        Pair(-13, -8), Pair(40, -46), Pair(-34, 5), Pair(-48, 141), Pair(-47, 134), Pair(-8, 8), Pair(-33, 48), Pair(14, 32),
        Pair(-40, 53), Pair(8, 8), Pair(-9, 69), Pair(-45, 50), Pair(-33, 56), Pair(-2, 72), Pair(-30, 77), Pair(42, -29),
        Pair(30, 50), Pair(-50, 140), Pair(-14, -49), Pair(-51, 100), Pair(-68, 126), Pair(-45, 95), Pair(-26, 57), Pair(-42, 103),
        Pair(23, -8), Pair(-43, 29), Pair(-41, 48), Pair(-35, 34), Pair(-7, 12), Pair(-22, 110), Pair(0, 0), Pair(-99, 124),
        Pair(-31, -43), Pair(-4, 17), Pair(-20, 42), Pair(-17, -5), Pair(-73, 68), Pair(-96, 87), Pair(-147, 236), Pair(94, -14),
        Pair(-46, 55), Pair(85, -87), Pair(-26, 29), Pair(-32, -10), Pair(7, -34), Pair(36, -4), Pair(-5, -150), Pair(-101, 84)
      },
      { // Piece 5
        Pair(87, -127), Pair(263, -112), Pair(124, -107), Pair(-8, 46), Pair(19, 29), Pair(-35, -61), Pair(-112, -148), Pair(33, 39),
        Pair(103, -73), Pair(97, -85), Pair(134, -26), Pair(-113, 6), Pair(-8, -17), Pair(158, 42), Pair(260, -56), Pair(-9, -18),
        Pair(353, -94), Pair(-19, -36), Pair(21, -10), Pair(155, -23), Pair(111, 7), Pair(253, 24), Pair(61, 12), Pair(-51, 5),
        Pair(151, -83), Pair(209, -53), Pair(22, -31), Pair(96, 15), Pair(121, 5), Pair(172, -5), Pair(187, -21), Pair(180, -15),
        Pair(85, -49), Pair(152, -78), Pair(33, -31), Pair(71, -13), Pair(36, 12), Pair(32, 47), Pair(-16, 41), Pair(46, 43),
        Pair(158, -86), Pair(88, -85), Pair(48, -47), Pair(10, 0), Pair(-48, 38), Pair(-118, 64), Pair(0, 0), Pair(-61, 85),
        Pair(-13, -89), Pair(-16, -67), Pair(9, -57), Pair(-20, -24), Pair(-59, 33), Pair(49, 58), Pair(-83, 60), Pair(-18, 123),
        Pair(-64, -133), Pair(-70, -83), Pair(-74, -54), Pair(-120, -24), Pair(-137, 20), Pair(-79, 56), Pair(-107, 71), Pair(-99, 30)
      }
    }},
    {{ // Bucket 23
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(19, -9), Pair(20, -15), Pair(-2, -3), Pair(-26, -8), Pair(15, 12), Pair(-24, 2), Pair(-25, 0), Pair(-66, -38),
        Pair(-5, -12), Pair(-1, -14), Pair(8, -19), Pair(6, -2), Pair(3, -11), Pair(2, -4), Pair(-12, 0), Pair(0, 0),
        Pair(3, -17), Pair(16, -25), Pair(1, -13), Pair(2, -20), Pair(9, -13), Pair(-7, -10), Pair(5, -14), Pair(14, -10),
        Pair(13, -29), Pair(6, -23), Pair(8, -22), Pair(9, -18), Pair(14, -21), Pair(2, -14), Pair(0, -15), Pair(-30, 34),
        Pair(6, -27), Pair(8, -25), Pair(6, -20), Pair(11, -23), Pair(4, -20), Pair(1, -9), Pair(-7, -10), Pair(0, 0),
        Pair(9, -21), Pair(6, -24), Pair(8, -16), Pair(-1, -16), Pair(0, -9), Pair(-1, -14), Pair(-21, -16), Pair(-14, 28),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(13, -80), Pair(-51, 8), Pair(140, -83), Pair(-78, 27), Pair(55, -48), Pair(13, -31), Pair(105, -66), Pair(-75, -85),
        Pair(14, -70), Pair(26, -36), Pair(27, -34), Pair(36, -21), Pair(43, 13), Pair(50, -64), Pair(68, -51), Pair(99, -54),
        Pair(59, -59), Pair(56, -50), Pair(74, -32), Pair(34, -2), Pair(41, -31), Pair(-41, -5), Pair(70, -25), Pair(33, 48),
        Pair(16, -57), Pair(34, -38), Pair(51, -10), Pair(48, -31), Pair(75, -33), Pair(13, -16), Pair(47, -25), Pair(48, -2),
        Pair(75, -26), Pair(29, -39), Pair(40, -15), Pair(30, -15), Pair(31, 10), Pair(46, -4), Pair(28, 43), Pair(19, -14),
        Pair(32, -29), Pair(26, -35), Pair(38, -21), Pair(34, 14), Pair(27, 21), Pair(35, 22), Pair(53, -14), Pair(0, 0),
        Pair(12, -21), Pair(3, -34), Pair(41, -21), Pair(42, 12), Pair(41, -8), Pair(79, 11), Pair(10, -123), Pair(59, 115),
        Pair(119, -102), Pair(38, -22), Pair(31, -8), Pair(23, 12), Pair(74, -38), Pair(29, 20), Pair(41, 30), Pair(49, 23)
      },
      { // Piece 2
        Pair(26, 107), Pair(-36, 140), Pair(28, 56), Pair(-73, 54), Pair(-262, 86), Pair(-51, 31), Pair(11, 44), Pair(-35, -26),
        Pair(-24, 5), Pair(46, 48), Pair(-65, 111), Pair(-76, 40), Pair(-7, 39), Pair(127, -7), Pair(3, 18), Pair(76, -12),
        Pair(74, -9), Pair(11, 15), Pair(20, 67), Pair(17, 101), Pair(41, 27), Pair(-2, 38), Pair(14, 3), Pair(42, -4),
        Pair(51, -14), Pair(43, 5), Pair(-38, 30), Pair(40, 48), Pair(-58, 106), Pair(65, 57), Pair(0, 23), Pair(33, 63),
        Pair(82, 15), Pair(23, 20), Pair(24, 41), Pair(39, 4), Pair(20, 34), Pair(12, 47), Pair(47, 25), Pair(30, 28),
        Pair(8, 22), Pair(18, 9), Pair(12, 30), Pair(34, 20), Pair(3, 9), Pair(53, 40), Pair(6, 81), Pair(0, 0),
        Pair(21, 16), Pair(12, 19), Pair(24, 48), Pair(14, -3), Pair(56, 34), Pair(43, -2), Pair(11, -3), Pair(32, 172),
        Pair(30, -57), Pair(22, -30), Pair(3, 2), Pair(50, 37), Pair(49, 3), Pair(20, 26), Pair(-124, 95), Pair(23, 14)
      },
      { // Piece 3
        Pair(73, 6), Pair(9, 56), Pair(43, 16), Pair(-71, 67), Pair(36, 19), Pair(39, 39), Pair(83, 29), Pair(26, 44),
        Pair(52, 12), Pair(40, -3), Pair(-24, 21), Pair(-14, 62), Pair(101, 16), Pair(-29, 51), Pair(30, 38), Pair(98, 54),
        Pair(39, -12), Pair(50, 10), Pair(-32, 30), Pair(-1, 39), Pair(53, -6), Pair(0, 76), Pair(0, 39), Pair(67, 66),
        Pair(18, 13), Pair(72, 1), Pair(14, 18), Pair(42, -15), Pair(24, 26), Pair(26, 25), Pair(-3, 16), Pair(80, 57),
        Pair(34, 0), Pair(64, 1), Pair(71, 4), Pair(57, 17), Pair(23, 40), Pair(30, 29), Pair(74, 9), Pair(26, 98),
        Pair(24, 35), Pair(60, -4), Pair(29, 10), Pair(28, 37), Pair(33, 34), Pair(17, 33), Pair(41, 80), Pair(0, 0),
        Pair(9, 55), Pair(23, 77), Pair(1, 54), Pair(46, 46), Pair(19, 59), Pair(23, 70), Pair(-71, -27), Pair(-54, 85),
        Pair(29, 18), Pair(72, 0), Pair(41, 19), Pair(37, 18), Pair(32, 28), Pair(46, -6), Pair(18, 70), Pair(-30, 69)
      },
      { // Piece 4
        Pair(-40, 123), Pair(-62, 146), Pair(28, 138), Pair(-71, 147), Pair(2, 102), Pair(195, -21), Pair(49, 39), Pair(96, 52),
        Pair(49, 58), Pair(25, 22), Pair(8, 111), Pair(6, 174), Pair(-32, 192), Pair(-45, 211), Pair(-21, 99), Pair(-10, 152),
        Pair(52, -20), Pair(-8, 70), Pair(32, 90), Pair(-41, 161), Pair(-57, 195), Pair(-103, 112), Pair(49, 105), Pair(18, -24),
        Pair(75, -66), Pair(15, 65), Pair(71, 50), Pair(9, 90), Pair(-2, 102), Pair(-2, 161), Pair(-17, 125), Pair(21, 126),
        Pair(11, -28), Pair(-35, 79), Pair(44, 16), Pair(22, 46), Pair(12, 64), Pair(-34, 76), Pair(-48, 171), Pair(46, 13),
        Pair(45, -53), Pair(-5, 88), Pair(8, -15), Pair(0, 127), Pair(5, 65), Pair(17, 81), Pair(-36, 99), Pair(0, 0),
        Pair(21, 29), Pair(21, 11), Pair(-20, 92), Pair(-14, 110), Pair(-3, 45), Pair(22, 84), Pair(-185, -15), Pair(-119, 111),
        Pair(25, 54), Pair(-23, 80), Pair(39, 25), Pair(6, 10), Pair(-8, -18), Pair(25, 80), Pair(-12, 134), Pair(-150, 206)
      },
      { // Piece 5
        Pair(-144, -74), Pair(61, -80), Pair(138, -116), Pair(-59, -97), Pair(0, -61), Pair(152, -98), Pair(-70, -25), Pair(10, -1),
        Pair(-13, -67), Pair(191, -104), Pair(74, -42), Pair(111, -70), Pair(28, -39), Pair(-87, 3), Pair(172, -32), Pair(100, -147),
        Pair(156, -69), Pair(233, -66), Pair(47, -59), Pair(213, -60), Pair(219, -42), Pair(180, -8), Pair(188, -26), Pair(185, -83),
        Pair(43, -69), Pair(94, -76), Pair(112, -55), Pair(74, -20), Pair(128, -5), Pair(102, -17), Pair(237, -19), Pair(287, -61),
        Pair(184, -116), Pair(53, -87), Pair(33, -64), Pair(83, -45), Pair(19, 10), Pair(55, 14), Pair(-3, 78), Pair(20, 73),
        Pair(30, -85), Pair(118, -90), Pair(23, -65), Pair(5, -28), Pair(29, 12), Pair(-85, 48), Pair(-92, 82), Pair(0, 0),
        Pair(19, -58), Pair(48, -68), Pair(-6, -53), Pair(-4, -26), Pair(-32, 11), Pair(-79, 52), Pair(44, 37), Pair(18, 64),
        Pair(-26, -88), Pair(-68, -50), Pair(-30, -53), Pair(-2, -30), Pair(-68, 33), Pair(-89, 27), Pair(-49, 76), Pair(-49, 129)
      }
    }},
    {{ // Bucket 24
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(33, 0), Pair(-8, 18), Pair(-11, 12), Pair(-8, 18), Pair(-10, 23), Pair(20, 24), Pair(-26, 25), Pair(-38, 31),
        Pair(6, 27), Pair(-5, 11), Pair(2, 4), Pair(15, -1), Pair(13, 12), Pair(-4, 13), Pair(5, 13), Pair(-5, 19),
        Pair(0, 0), Pair(-3, 1), Pair(-1, -4), Pair(3, -3), Pair(1, 2), Pair(-4, 7), Pair(-6, 8), Pair(-8, 7),
        Pair(0, 0), Pair(2, -5), Pair(0, -4), Pair(1, -7), Pair(-1, -2), Pair(-2, -2), Pair(-1, -3), Pair(-4, -1),
        Pair(13, 16), Pair(-12, -3), Pair(-3, -4), Pair(2, -7), Pair(-1, -4), Pair(-6, -3), Pair(-2, -6), Pair(-2, -3),
        Pair(11, 7), Pair(-14, -11), Pair(1, -1), Pair(-1, -7), Pair(-5, -8), Pair(-7, -4), Pair(-2, -7), Pair(0, -7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(28, 103), Pair(105, -27), Pair(5, 31), Pair(231, 8), Pair(86, 9), Pair(63, 42), Pair(81, 18), Pair(-23, 62),
        Pair(49, 46), Pair(38, 36), Pair(74, 43), Pair(12, 51), Pair(75, 22), Pair(85, 14), Pair(-6, -4), Pair(-1, 63),
        Pair(57, 48), Pair(47, 75), Pair(28, 48), Pair(41, 32), Pair(16, 38), Pair(54, 24), Pair(45, -1), Pair(18, 25),
        Pair(-45, 75), Pair(21, 49), Pair(-13, 55), Pair(27, 45), Pair(19, 40), Pair(14, 57), Pair(25, 37), Pair(26, -5),
        Pair(0, 0), Pair(18, 66), Pair(2, 68), Pair(18, 36), Pair(11, 71), Pair(10, 44), Pair(37, 20), Pair(24, 28),
        Pair(26, 105), Pair(-37, -15), Pair(12, 57), Pair(7, 46), Pair(17, 51), Pair(11, 41), Pair(17, 38), Pair(17, 65),
        Pair(39, 82), Pair(42, 49), Pair(20, 20), Pair(3, 34), Pair(4, 53), Pair(6, 23), Pair(-2, 16), Pair(26, 32),
        Pair(-44, 58), Pair(15, 91), Pair(11, 47), Pair(14, 46), Pair(-3, 49), Pair(10, 26), Pair(23, 41), Pair(23, -14)
      },
      { // Piece 2
        Pair(58, 105), Pair(-26, 95), Pair(-55, 87), Pair(-73, 125), Pair(16, 135), Pair(-71, 153), Pair(122, 89), Pair(24, 120),
        Pair(42, 92), Pair(-17, 92), Pair(1, 105), Pair(-74, 130), Pair(1, 133), Pair(28, 115), Pair(-25, 93), Pair(28, 66),
        Pair(-50, 114), Pair(4, 105), Pair(10, 94), Pair(-4, 121), Pair(-34, 113), Pair(-2, 114), Pair(30, 101), Pair(10, 77),
        Pair(55, 60), Pair(-4, 93), Pair(-26, 114), Pair(-11, 97), Pair(3, 93), Pair(-11, 84), Pair(9, 68), Pair(8, 88),
        Pair(0, 0), Pair(-11, 96), Pair(10, 82), Pair(-7, 90), Pair(6, 70), Pair(2, 71), Pair(-3, 77), Pair(5, 89),
        Pair(23, 167), Pair(-56, 6), Pair(-1, 93), Pair(-2, 91), Pair(2, 79), Pair(0, 76), Pair(-8, 70), Pair(12, 68),
        Pair(15, 122), Pair(-2, 81), Pair(2, 91), Pair(4, 71), Pair(-5, 81), Pair(0, 51), Pair(3, 58), Pair(10, 31),
        Pair(9, 77), Pair(-4, 105), Pair(4, 84), Pair(12, 84), Pair(-14, 72), Pair(3, 65), Pair(-27, 55), Pair(16, 34)
      },
      { // Piece 3
        Pair(59, 124), Pair(31, 135), Pair(26, 133), Pair(3, 142), Pair(59, 121), Pair(40, 140), Pair(8, 157), Pair(71, 127),
        Pair(42, 156), Pair(18, 142), Pair(-1, 157), Pair(-28, 173), Pair(11, 152), Pair(74, 128), Pair(62, 126), Pair(-66, 171),
        Pair(53, 156), Pair(11, 141), Pair(23, 137), Pair(17, 133), Pair(14, 129), Pair(38, 124), Pair(-7, 130), Pair(-10, 132),
        Pair(28, 151), Pair(-1, 132), Pair(-15, 147), Pair(-13, 148), Pair(13, 136), Pair(-3, 121), Pair(36, 107), Pair(16, 114),
        Pair(0, 0), Pair(-2, 146), Pair(-19, 151), Pair(-14, 132), Pair(-2, 126), Pair(-7, 109), Pair(-1, 107), Pair(8, 108),
        Pair(-19, 128), Pair(1, 35), Pair(-22, 140), Pair(-9, 129), Pair(-14, 119), Pair(-21, 131), Pair(9, 105), Pair(4, 122),
        Pair(-44, 121), Pair(8, 124), Pair(-19, 119), Pair(-23, 128), Pair(2, 110), Pair(-8, 119), Pair(-6, 123), Pair(13, 95),
        Pair(-21, 115), Pair(-20, 119), Pair(-18, 134), Pair(-14, 124), Pair(-7, 127), Pair(-8, 130), Pair(14, 114), Pair(-10, 139)
      },
      { // Piece 4
        Pair(42, 277), Pair(86, 212), Pair(89, 266), Pair(128, 195), Pair(3, 301), Pair(60, 287), Pair(64, 280), Pair(55, 297),
        Pair(94, 239), Pair(49, 255), Pair(35, 269), Pair(10, 276), Pair(66, 248), Pair(88, 201), Pair(29, 255), Pair(51, 273),
        Pair(82, 264), Pair(77, 212), Pair(46, 278), Pair(59, 240), Pair(44, 229), Pair(41, 252), Pair(58, 206), Pair(67, 232),
        Pair(59, 245), Pair(30, 248), Pair(34, 255), Pair(46, 235), Pair(39, 246), Pair(49, 266), Pair(67, 207), Pair(77, 211),
        Pair(0, 0), Pair(36, 240), Pair(42, 240), Pair(46, 217), Pair(27, 251), Pair(55, 217), Pair(69, 172), Pair(37, 227),
        Pair(19, 248), Pair(30, 109), Pair(24, 217), Pair(35, 216), Pair(31, 202), Pair(54, 199), Pair(58, 182), Pair(73, 187),
        Pair(64, 177), Pair(47, 179), Pair(36, 218), Pair(40, 218), Pair(39, 213), Pair(47, 206), Pair(45, 206), Pair(59, 201),
        Pair(43, 169), Pair(34, 214), Pair(41, 198), Pair(41, 211), Pair(42, 220), Pair(37, 204), Pair(67, 227), Pair(-2, 288)
      },
      { // Piece 5
        Pair(-189, -5), Pair(16, 32), Pair(65, -26), Pair(29, 10), Pair(147, -52), Pair(7, -5), Pair(-21, -8), Pair(165, 16),
        Pair(56, -15), Pair(-18, -25), Pair(178, -27), Pair(-173, 32), Pair(28, -18), Pair(68, -21), Pair(116, -28), Pair(202, -48),
        Pair(-4, -37), Pair(132, -4), Pair(61, -13), Pair(41, -14), Pair(137, -19), Pair(39, 5), Pair(83, 5), Pair(158, -56),
        Pair(75, 21), Pair(-38, 40), Pair(65, 2), Pair(133, 0), Pair(122, -15), Pair(25, 8), Pair(77, -14), Pair(54, -5),
        Pair(0, 0), Pair(-105, 32), Pair(-94, 26), Pair(-30, 9), Pair(42, -6), Pair(15, -12), Pair(34, -18), Pair(104, -34),
        Pair(-19, 32), Pair(-68, -2), Pair(-67, 28), Pair(9, 6), Pair(-12, -1), Pair(31, -15), Pair(13, -21), Pair(79, -24),
        Pair(-44, 49), Pair(-39, 52), Pair(-58, 29), Pair(-38, 22), Pair(3, -5), Pair(7, -12), Pair(5, -22), Pair(1, -15),
        Pair(-5, 16), Pair(28, 16), Pair(-14, 35), Pair(-18, 18), Pair(0, -15), Pair(20, -29), Pair(-3, -22), Pair(-2, -27)
      }
    }},
    {{ // Bucket 25
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-11, 26), Pair(-9, 30), Pair(4, 25), Pair(17, 9), Pair(22, 16), Pair(-15, 13), Pair(27, 34), Pair(-58, 35),
        Pair(-3, 5), Pair(-9, 5), Pair(-4, 6), Pair(10, 6), Pair(11, 6), Pair(7, 16), Pair(-6, 18), Pair(-19, 24),
        Pair(2, 0), Pair(0, 0), Pair(4, -5), Pair(1, 1), Pair(3, 2), Pair(-1, 0), Pair(-5, 5), Pair(-7, 5),
        Pair(6, 1), Pair(0, 0), Pair(0, -3), Pair(1, 0), Pair(-3, -2), Pair(-4, -3), Pair(-9, -3), Pair(-7, 2),
        Pair(6, 1), Pair(10, 14), Pair(1, -5), Pair(4, -6), Pair(-3, -6), Pair(-10, -4), Pair(-10, -6), Pair(-6, 0),
        Pair(2, -9), Pair(12, 8), Pair(-5, -8), Pair(0, -12), Pair(-1, -14), Pair(-5, -10), Pair(-7, -8), Pair(-5, -5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-54, 85), Pair(36, 35), Pair(1, 34), Pair(-49, 81), Pair(42, 41), Pair(38, 3), Pair(-3, -10), Pair(-15, 6),
        Pair(-4, 79), Pair(-31, 92), Pair(29, 65), Pair(-5, 58), Pair(31, 65), Pair(29, 71), Pair(57, 35), Pair(59, 18),
        Pair(24, 79), Pair(17, 74), Pair(0, 91), Pair(18, 59), Pair(20, 44), Pair(-32, 71), Pair(15, 67), Pair(16, 16),
        Pair(-11, 78), Pair(-15, 26), Pair(10, 83), Pair(1, 49), Pair(12, 72), Pair(13, 42), Pair(20, 45), Pair(18, 31),
        Pair(-8, 43), Pair(0, 0), Pair(3, 76), Pair(5, 82), Pair(-6, 57), Pair(1, 56), Pair(23, 33), Pair(3, 63),
        Pair(-38, -2), Pair(29, 118), Pair(-39, -17), Pair(6, 59), Pair(7, 48), Pair(5, 64), Pair(3, 45), Pair(14, 43),
        Pair(-20, 44), Pair(-14, 96), Pair(12, 50), Pair(4, 66), Pair(-1, 29), Pair(12, 60), Pair(-10, 44), Pair(14, 33),
        Pair(-13, 108), Pair(-22, -45), Pair(0, 77), Pair(2, 30), Pair(4, 66), Pair(2, 49), Pair(-6, 55), Pair(35, 74)
      },
      { // Piece 2
        Pair(-8, 76), Pair(17, 119), Pair(-133, 95), Pair(-98, 96), Pair(-79, 106), Pair(-56, 75), Pair(-22, 144), Pair(-50, 134),
        Pair(-14, 117), Pair(-37, 89), Pair(-23, 98), Pair(-75, 112), Pair(-86, 133), Pair(21, 132), Pair(3, 103), Pair(0, 112),
        Pair(-11, 71), Pair(-39, 98), Pair(-8, 78), Pair(-38, 92), Pair(-16, 127), Pair(-25, 114), Pair(-29, 111), Pair(-2, 83),
        Pair(-24, 43), Pair(-8, 84), Pair(-22, 85), Pair(-31, 120), Pair(-9, 87), Pair(-9, 105), Pair(-8, 66), Pair(-9, 80),
        Pair(-14, 124), Pair(0, 0), Pair(-12, 96), Pair(-14, 77), Pair(-17, 84), Pair(-4, 76), Pair(-14, 76), Pair(24, 58),
        Pair(-37, -51), Pair(-4, 165), Pair(-66, -7), Pair(-10, 83), Pair(-5, 75), Pair(-14, 67), Pair(0, 44), Pair(8, 50),
        Pair(-7, 110), Pair(6, 46), Pair(-5, 94), Pair(-15, 49), Pair(-14, 75), Pair(-1, 60), Pair(-5, 56), Pair(2, 56),
        Pair(1, 35), Pair(-23, 91), Pair(0, 59), Pair(-19, 97), Pair(-19, 59), Pair(-7, 80), Pair(25, 64), Pair(-24, 70)
      },
      { // Piece 3
        Pair(-57, 117), Pair(17, 108), Pair(-29, 117), Pair(-6, 114), Pair(-10, 130), Pair(15, 103), Pair(-37, 114), Pair(-34, 129),
        Pair(12, 98), Pair(24, 119), Pair(-6, 105), Pair(-16, 123), Pair(-20, 124), Pair(0, 117), Pair(17, 97), Pair(-21, 100),
        Pair(2, 94), Pair(5, 132), Pair(-4, 110), Pair(-5, 111), Pair(-23, 125), Pair(6, 102), Pair(18, 94), Pair(28, 82),
        Pair(20, 76), Pair(8, 126), Pair(-8, 100), Pair(-6, 117), Pair(-15, 104), Pair(-11, 95), Pair(14, 91), Pair(1, 92),
        Pair(-18, 78), Pair(0, 0), Pair(-16, 111), Pair(-28, 111), Pair(-7, 89), Pair(-6, 92), Pair(-11, 87), Pair(13, 81),
        Pair(19, -3), Pair(-13, 104), Pair(-58, 12), Pair(-15, 85), Pair(-25, 98), Pair(-10, 96), Pair(5, 79), Pair(29, 84),
        Pair(-40, 78), Pair(-34, 86), Pair(-21, 95), Pair(-14, 82), Pair(5, 83), Pair(-16, 93), Pair(0, 96), Pair(-8, 104),
        Pair(-19, 88), Pair(-18, 69), Pair(-16, 90), Pair(-18, 100), Pair(-8, 87), Pair(-9, 92), Pair(6, 89), Pair(-3, 95)
      },
      { // Piece 4
        Pair(77, 84), Pair(-48, 199), Pair(35, 166), Pair(70, 139), Pair(41, 168), Pair(55, 163), Pair(78, 217), Pair(32, 140),
        Pair(66, 127), Pair(56, 135), Pair(58, 185), Pair(24, 178), Pair(29, 215), Pair(11, 238), Pair(0, 244), Pair(44, 175),
        Pair(36, 141), Pair(58, 139), Pair(23, 186), Pair(40, 150), Pair(44, 174), Pair(33, 126), Pair(67, 162), Pair(68, 148),
        Pair(44, 104), Pair(39, 119), Pair(54, 134), Pair(44, 159), Pair(33, 172), Pair(9, 198), Pair(38, 154), Pair(38, 156),
        Pair(34, 112), Pair(0, 0), Pair(27, 149), Pair(34, 142), Pair(35, 142), Pair(41, 137), Pair(32, 145), Pair(46, 131),
        Pair(52, 39), Pair(25, 120), Pair(23, 55), Pair(29, 120), Pair(24, 128), Pair(32, 131), Pair(44, 140), Pair(41, 146),
        Pair(18, 118), Pair(22, 90), Pair(24, 106), Pair(30, 112), Pair(32, 113), Pair(33, 115), Pair(47, 117), Pair(18, 170),
        Pair(8, 144), Pair(29, 111), Pair(29, 114), Pair(25, 120), Pair(29, 119), Pair(31, 104), Pair(39, 107), Pair(31, 142)
      },
      { // Piece 5
        Pair(-55, -188), Pair(-37, -74), Pair(6, -37), Pair(-60, -2), Pair(-142, 38), Pair(-93, -27), Pair(54, -61), Pair(63, -34),
        Pair(118, -46), Pair(195, -52), Pair(-28, 38), Pair(-4, 18), Pair(-84, 13), Pair(-67, 33), Pair(-95, 6), Pair(-27, -11),
        Pair(201, -22), Pair(-56, 7), Pair(259, -27), Pair(51, 24), Pair(62, 8), Pair(-30, 20), Pair(-14, 22), Pair(84, 9),
        Pair(27, -9), Pair(27, 19), Pair(25, 41), Pair(102, -4), Pair(81, 7), Pair(21, 24), Pair(60, -4), Pair(95, -32),
        Pair(-10, 11), Pair(0, 0), Pair(-24, 14), Pair(43, 7), Pair(36, 10), Pair(62, -10), Pair(-4, -5), Pair(45, -21),
        Pair(66, 26), Pair(-135, 18), Pair(-13, 38), Pair(-35, 21), Pair(22, 8), Pair(-2, 5), Pair(27, -16), Pair(74, -25),
        Pair(-53, 37), Pair(-67, 28), Pair(-16, 21), Pair(-24, 9), Pair(-10, 11), Pair(-3, -3), Pair(-2, -9), Pair(-4, -10),
        Pair(-11, -9), Pair(-14, -1), Pair(-3, 12), Pair(-17, 32), Pair(-4, 2), Pair(15, -5), Pair(-4, -17), Pair(7, -25)
      }
    }},
    {{ // Bucket 26
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(7, 23), Pair(-1, 29), Pair(-32, 14), Pair(7, 15), Pair(7, 19), Pair(30, 19), Pair(14, 19), Pair(-16, 21),
        Pair(-9, 13), Pair(-12, 8), Pair(15, -2), Pair(6, 2), Pair(14, 5), Pair(8, 15), Pair(-8, 14), Pair(0, 12),
        Pair(-2, 2), Pair(-4, 4), Pair(0, 0), Pair(1, 1), Pair(3, 7), Pair(-2, 4), Pair(-1, 7), Pair(1, 4),
        Pair(3, -5), Pair(1, -4), Pair(0, 0), Pair(2, -2), Pair(-2, -3), Pair(-3, -2), Pair(6, -10), Pair(-4, -2),
        Pair(5, -2), Pair(4, -30), Pair(8, 16), Pair(7, -8), Pair(-3, -2), Pair(-14, -2), Pair(-7, -1), Pair(-6, -4),
        Pair(1, -2), Pair(-3, -16), Pair(9, 5), Pair(-8, -14), Pair(5, -6), Pair(-10, -4), Pair(-7, -5), Pair(-2, -4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-24, 72), Pair(33, 98), Pair(50, 59), Pair(26, 75), Pair(3, 79), Pair(66, 66), Pair(149, 70), Pair(-12, 30),
        Pair(-2, 69), Pair(-15, 82), Pair(0, 70), Pair(9, 58), Pair(40, 72), Pair(5, 61), Pair(45, 18), Pair(29, 21),
        Pair(6, 107), Pair(45, 65), Pair(3, 69), Pair(-1, 102), Pair(7, 88), Pair(-24, 77), Pair(31, 51), Pair(35, 75),
        Pair(-21, 25), Pair(7, 107), Pair(-10, 49), Pair(-5, 111), Pair(15, 48), Pair(22, 75), Pair(20, 54), Pair(33, 41),
        Pair(8, 112), Pair(-2, 67), Pair(0, 0), Pair(1, 88), Pair(5, 98), Pair(4, 71), Pair(21, 63), Pair(19, 53),
        Pair(9, 94), Pair(-37, 19), Pair(19, 151), Pair(-55, -8), Pair(24, 80), Pair(9, 61), Pair(7, 85), Pair(14, 80),
        Pair(-36, 129), Pair(44, 101), Pair(7, 83), Pair(12, 50), Pair(14, 74), Pair(-2, 59), Pair(37, 62), Pair(26, 32),
        Pair(-26, -22), Pair(11, 113), Pair(-30, 48), Pair(25, 75), Pair(7, 50), Pair(19, 70), Pair(2, 67), Pair(61, 72)
      },
      { // Piece 2
        Pair(14, 72), Pair(9, 82), Pair(8, 85), Pair(-44, 112), Pair(-32, 82), Pair(-50, 127), Pair(-133, 82), Pair(0, 157),
        Pair(-18, 98), Pair(-17, 99), Pair(0, 118), Pair(-13, 75), Pair(-12, 117), Pair(42, 56), Pair(1, 143), Pair(-2, 97),
        Pair(-36, 77), Pair(-27, 103), Pair(-15, 70), Pair(0, 91), Pair(25, 79), Pair(-1, 134), Pair(5, 99), Pair(15, 97),
        Pair(-11, 118), Pair(-32, 75), Pair(1, 99), Pair(-5, 72), Pair(0, 114), Pair(-15, 91), Pair(-7, 107), Pair(26, 78),
        Pair(-7, 82), Pair(-9, 126), Pair(0, 0), Pair(-7, 115), Pair(-1, 79), Pair(7, 90), Pair(20, 64), Pair(7, 64),
        Pair(-12, 103), Pair(-80, -45), Pair(15, 161), Pair(-51, -18), Pair(-8, 90), Pair(-2, 62), Pair(-3, 65), Pair(-2, 71),
        Pair(-57, -15), Pair(-2, 66), Pair(3, 83), Pair(-5, 96), Pair(-10, 39), Pair(-6, 67), Pair(2, 59), Pair(13, 84),
        Pair(-6, 77), Pair(9, 93), Pair(4, 86), Pair(-3, 56), Pair(3, 98), Pair(-1, 29), Pair(21, 65), Pair(-12, 76)
      },
      { // Piece 3
        Pair(10, 114), Pair(18, 104), Pair(83, 92), Pair(-35, 121), Pair(-3, 109), Pair(6, 124), Pair(29, 105), Pair(35, 92),
        Pair(2, 123), Pair(-2, 117), Pair(25, 126), Pair(33, 109), Pair(23, 130), Pair(31, 97), Pair(14, 105), Pair(3, 106),
        Pair(4, 121), Pair(9, 109), Pair(-25, 137), Pair(5, 125), Pair(19, 116), Pair(18, 105), Pair(20, 103), Pair(7, 112),
        Pair(-1, 97), Pair(-8, 115), Pair(0, 127), Pair(-17, 120), Pair(6, 104), Pair(17, 99), Pair(26, 113), Pair(10, 86),
        Pair(-11, 107), Pair(-23, 100), Pair(0, 0), Pair(-2, 128), Pair(6, 93), Pair(-12, 93), Pair(39, 65), Pair(5, 81),
        Pair(-22, 127), Pair(19, -26), Pair(-46, 123), Pair(5, 1), Pair(-16, 118), Pair(-18, 114), Pair(-7, 111), Pair(-19, 119),
        Pair(3, 95), Pair(-19, 79), Pair(-31, 88), Pair(-8, 91), Pair(-15, 92), Pair(3, 99), Pair(-4, 107), Pair(7, 77),
        Pair(-7, 104), Pair(-14, 95), Pair(-22, 90), Pair(-15, 101), Pair(-5, 103), Pair(-3, 104), Pair(14, 99), Pair(4, 108)
      },
      { // Piece 4
        Pair(34, 146), Pair(64, 131), Pair(26, 177), Pair(9, 214), Pair(72, 220), Pair(96, 131), Pair(93, 170), Pair(68, 209),
        Pair(32, 193), Pair(48, 192), Pair(82, 131), Pair(28, 160), Pair(43, 219), Pair(79, 199), Pair(54, 180), Pair(71, 197),
        Pair(33, 156), Pair(13, 203), Pair(55, 188), Pair(24, 191), Pair(16, 208), Pair(28, 200), Pair(47, 189), Pair(65, 195),
        Pair(48, 180), Pair(24, 123), Pair(34, 209), Pair(49, 155), Pair(26, 222), Pair(45, 215), Pair(71, 145), Pair(58, 173),
        Pair(41, 131), Pair(12, 178), Pair(0, 0), Pair(49, 191), Pair(37, 154), Pair(46, 182), Pair(48, 164), Pair(60, 148),
        Pair(46, 163), Pair(54, 60), Pair(42, 133), Pair(44, 31), Pair(33, 173), Pair(50, 146), Pair(54, 155), Pair(44, 169),
        Pair(0, 213), Pair(26, 157), Pair(38, 118), Pair(32, 136), Pair(36, 140), Pair(51, 157), Pair(54, 166), Pair(70, 140),
        Pair(14, 174), Pair(29, 135), Pair(36, 106), Pair(37, 121), Pair(35, 170), Pair(38, 173), Pair(65, 144), Pair(101, 164)
      },
      { // Piece 5
        Pair(-77, -102), Pair(28, -39), Pair(-65, -133), Pair(-15, -35), Pair(-195, -15), Pair(17, -31), Pair(73, -7), Pair(-21, -8),
        Pair(74, -31), Pair(56, -31), Pair(-251, 21), Pair(100, 43), Pair(218, -41), Pair(94, -23), Pair(276, -48), Pair(-18, 0),
        Pair(-66, -21), Pair(91, -28), Pair(28, 14), Pair(153, -5), Pair(156, -13), Pair(245, -16), Pair(14, 13), Pair(228, -44),
        Pair(-2, -2), Pair(137, 10), Pair(52, 20), Pair(42, 25), Pair(145, -12), Pair(117, 0), Pair(72, -2), Pair(68, -20),
        Pair(7, 27), Pair(-66, 11), Pair(0, 0), Pair(93, -25), Pair(33, 5), Pair(13, 14), Pair(75, -1), Pair(11, 1),
        Pair(-65, 63), Pair(150, -74), Pair(-108, 19), Pair(-136, 27), Pair(-32, 25), Pair(31, 8), Pair(3, 6), Pair(48, -19),
        Pair(-108, 65), Pair(-43, 38), Pair(-54, 29), Pair(33, 13), Pair(-4, 4), Pair(1, 12), Pair(-1, 5), Pair(14, -11),
        Pair(-34, 62), Pair(-37, 37), Pair(-40, 21), Pair(8, -3), Pair(-20, 14), Pair(21, 5), Pair(1, -4), Pair(12, -7)
      }
    }},
    {{ // Bucket 27
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-16, 36), Pair(-5, 23), Pair(8, 7), Pair(10, 14), Pair(0, 17), Pair(6, 4), Pair(28, 17), Pair(-19, 30),
        Pair(-9, 12), Pair(-5, 12), Pair(-5, -3), Pair(4, 1), Pair(-3, 5), Pair(2, 8), Pair(-3, 8), Pair(-3, 20),
        Pair(-5, 2), Pair(-1, -2), Pair(-2, 0), Pair(0, 0), Pair(1, 1), Pair(-2, 4), Pair(2, 4), Pair(0, 6),
        Pair(-1, -1), Pair(2, -9), Pair(-4, -1), Pair(0, 0), Pair(-6, -5), Pair(-5, 1), Pair(-1, -5), Pair(-1, -2),
        Pair(-5, -5), Pair(-2, -6), Pair(-1, -42), Pair(11, 19), Pair(-6, -20), Pair(-9, 1), Pair(-3, -5), Pair(-3, -7),
        Pair(2, -3), Pair(-7, -3), Pair(-6, -17), Pair(-8, 5), Pair(-21, -9), Pair(-6, -4), Pair(-1, -3), Pair(2, -5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-99, 108), Pair(-77, 68), Pair(62, 68), Pair(-3, 61), Pair(52, 89), Pair(-72, 121), Pair(60, -23), Pair(-44, 98),
        Pair(22, 54), Pair(32, 60), Pair(-14, 79), Pair(-32, 91), Pair(45, 38), Pair(53, 80), Pair(7, 50), Pair(-9, 73),
        Pair(57, 92), Pair(-7, 60), Pair(-6, 77), Pair(14, 65), Pair(21, 57), Pair(-2, 56), Pair(33, 49), Pair(-26, 72),
        Pair(-2, 69), Pair(-8, 21), Pair(4, 80), Pair(-17, 39), Pair(7, 85), Pair(-3, 63), Pair(7, 76), Pair(11, 83),
        Pair(-17, 61), Pair(-13, 73), Pair(2, 66), Pair(0, 0), Pair(-3, 80), Pair(-7, 90), Pair(1, 44), Pair(18, 68),
        Pair(-2, 45), Pair(-2, 49), Pair(-44, -32), Pair(22, 141), Pair(-56, -9), Pair(9, 57), Pair(14, 47), Pair(21, 56),
        Pair(4, 0), Pair(-20, 76), Pair(0, 32), Pair(7, 77), Pair(2, 22), Pair(-1, 76), Pair(25, 8), Pair(18, 59),
        Pair(-48, 101), Pair(-6, 26), Pair(16, 63), Pair(-34, -19), Pair(7, 67), Pair(-16, 53), Pair(2, 73), Pair(25, 115)
      },
      { // Piece 2
        Pair(-17, 97), Pair(-90, 93), Pair(-69, 93), Pair(-66, 91), Pair(-55, 104), Pair(-39, 60), Pair(-36, 91), Pair(0, 77),
        Pair(-8, 78), Pair(-17, 73), Pair(15, 60), Pair(-81, 103), Pair(-38, 107), Pair(13, 95), Pair(-31, 90), Pair(49, 107),
        Pair(-19, 114), Pair(-19, 63), Pair(8, 64), Pair(-26, 81), Pair(-23, 88), Pair(-23, 65), Pair(-4, 109), Pair(7, 45),
        Pair(-6, 61), Pair(0, 99), Pair(-34, 56), Pair(-8, 82), Pair(11, 37), Pair(0, 102), Pair(-5, 65), Pair(8, 79),
        Pair(-23, 82), Pair(-27, 69), Pair(-4, 113), Pair(0, 0), Pair(9, 89), Pair(-2, 53), Pair(7, 77), Pair(3, 65),
        Pair(-9, 55), Pair(-8, 88), Pair(-89, -14), Pair(15, 154), Pair(-23, -88), Pair(1, 71), Pair(1, 55), Pair(16, 68),
        Pair(2, 88), Pair(-41, -24), Pair(-31, 96), Pair(-1, 42), Pair(-12, 70), Pair(-33, 34), Pair(-3, 69), Pair(-4, 46),
        Pair(-84, -37), Pair(-40, 111), Pair(2, 43), Pair(-1, 75), Pair(-13, 52), Pair(0, 73), Pair(-46, 38), Pair(-6, 103)
      },
      { // Piece 3
        Pair(33, 94), Pair(-4, 95), Pair(-10, 87), Pair(-13, 97), Pair(-12, 93), Pair(-3, 116), Pair(34, 90), Pair(-39, 99),
        Pair(12, 87), Pair(-10, 98), Pair(0, 103), Pair(-41, 121), Pair(-7, 104), Pair(-12, 108), Pair(3, 85), Pair(-38, 105),
        Pair(6, 89), Pair(5, 94), Pair(-6, 99), Pair(-12, 111), Pair(-3, 85), Pair(15, 86), Pair(-2, 90), Pair(4, 79),
        Pair(0, 82), Pair(-14, 98), Pair(-6, 90), Pair(-30, 116), Pair(1, 85), Pair(-6, 99), Pair(22, 81), Pair(-19, 85),
        Pair(-5, 67), Pair(-10, 89), Pair(-6, 77), Pair(0, 0), Pair(-7, 77), Pair(-30, 99), Pair(-9, 59), Pair(-5, 76),
        Pair(-18, 90), Pair(-32, 83), Pair(-27, 0), Pair(-20, 96), Pair(-42, 5), Pair(-18, 87), Pair(-16, 76), Pair(-3, 72),
        Pair(19, 49), Pair(-3, 86), Pair(-7, 68), Pair(-47, 82), Pair(-3, 66), Pair(0, 72), Pair(24, 71), Pair(4, 77),
        Pair(-6, 83), Pair(-13, 88), Pair(-10, 72), Pair(-31, 77), Pair(-11, 84), Pair(-3, 91), Pair(-3, 70), Pair(8, 78)
      },
      { // Piece 4
        Pair(2, 187), Pair(32, 134), Pair(36, 165), Pair(31, 156), Pair(61, 140), Pair(36, 184), Pair(33, 187), Pair(59, 131),
        Pair(36, 117), Pair(25, 171), Pair(6, 217), Pair(34, 163), Pair(18, 179), Pair(5, 215), Pair(10, 248), Pair(17, 165),
        Pair(38, 141), Pair(34, 120), Pair(43, 151), Pair(37, 130), Pair(27, 209), Pair(20, 168), Pair(11, 201), Pair(22, 168),
        Pair(36, 143), Pair(39, 140), Pair(28, 139), Pair(25, 145), Pair(46, 151), Pair(19, 196), Pair(0, 227), Pair(31, 180),
        Pair(28, 151), Pair(33, 130), Pair(28, 115), Pair(0, 0), Pair(33, 135), Pair(24, 142), Pair(34, 157), Pair(22, 164),
        Pair(34, 143), Pair(16, 125), Pair(25, 36), Pair(40, 129), Pair(24, -8), Pair(22, 149), Pair(31, 129), Pair(13, 171),
        Pair(3, 149), Pair(12, 118), Pair(9, 142), Pair(13, 141), Pair(15, 153), Pair(24, 145), Pair(34, 129), Pair(38, 147),
        Pair(15, 117), Pair(12, 160), Pair(16, 113), Pair(26, 143), Pair(22, 132), Pair(18, 154), Pair(31, 53), Pair(11, 122)
      },
      { // Piece 5
        Pair(-55, -29), Pair(-72, -31), Pair(44, -20), Pair(-113, -31), Pair(51, -9), Pair(-20, -54), Pair(53, -79), Pair(-12, -77),
        Pair(188, -10), Pair(47, -47), Pair(182, -70), Pair(-6, -78), Pair(26, -60), Pair(-52, -38), Pair(94, -34), Pair(-53, -17),
        Pair(103, -53), Pair(137, -26), Pair(194, -39), Pair(170, -23), Pair(71, 11), Pair(200, 8), Pair(99, 22), Pair(119, -37),
        Pair(26, -25), Pair(127, 4), Pair(127, 6), Pair(115, -7), Pair(80, 35), Pair(101, 6), Pair(77, 24), Pair(109, 1),
        Pair(45, 15), Pair(-27, 38), Pair(55, -10), Pair(0, 0), Pair(47, -18), Pair(21, 9), Pair(67, 12), Pair(89, -27),
        Pair(-49, 28), Pair(17, 4), Pair(185, -29), Pair(-45, 7), Pair(186, -62), Pair(23, 16), Pair(43, 8), Pair(78, -6),
        Pair(-8, 25), Pair(-35, 34), Pair(-19, 14), Pair(35, 0), Pair(24, 4), Pair(2, 12), Pair(5, 22), Pair(14, 15),
        Pair(5, 35), Pair(-40, 52), Pair(2, 17), Pair(-4, 2), Pair(3, 14), Pair(1, 22), Pair(4, 20), Pair(7, 7)
      }
    }},
    {{ // Bucket 28
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(24, 4), Pair(-11, 17), Pair(8, 1), Pair(-29, 17), Pair(27, 17), Pair(-19, 25), Pair(24, 14), Pair(24, 14),
        Pair(0, 6), Pair(0, 7), Pair(-2, 3), Pair(-5, -3), Pair(4, 4), Pair(-14, 11), Pair(0, 4), Pair(-10, 12),
        Pair(0, -4), Pair(-1, -2), Pair(-4, -7), Pair(-1, 0), Pair(0, 0), Pair(0, -2), Pair(6, 3), Pair(3, 7),
        Pair(4, -7), Pair(-2, -6), Pair(0, -5), Pair(-6, -9), Pair(0, 0), Pair(-3, -2), Pair(8, -6), Pair(1, 0),
        Pair(-1, -10), Pair(-3, -8), Pair(-6, -12), Pair(8, -20), Pair(7, 11), Pair(6, -28), Pair(-4, -4), Pair(0, -1),
        Pair(2, -6), Pair(-4, -9), Pair(-2, -11), Pair(-10, -14), Pair(5, -1), Pair(-12, -14), Pair(3, 2), Pair(6, -6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(1, 51), Pair(-12, 51), Pair(-51, 83), Pair(-28, 42), Pair(4, 69), Pair(-14, 45), Pair(-125, 105), Pair(-29, 8),
        Pair(-2, 52), Pair(-2, 58), Pair(12, 43), Pair(5, 49), Pair(-6, 53), Pair(-45, 105), Pair(-4, 75), Pair(0, 49),
        Pair(22, 47), Pair(-4, 62), Pair(-22, 63), Pair(2, 60), Pair(-19, 74), Pair(-16, 62), Pair(-19, 55), Pair(-27, 75),
        Pair(15, 49), Pair(6, 59), Pair(1, 43), Pair(-10, 70), Pair(-5, 37), Pair(-10, 97), Pair(-12, 25), Pair(-6, 88),
        Pair(7, 68), Pair(11, 29), Pair(-10, 59), Pair(1, 65), Pair(0, 0), Pair(-12, 67), Pair(-24, 76), Pair(-29, 15),
        Pair(-3, 81), Pair(-6, 60), Pair(6, 61), Pair(-67, -13), Pair(13, 124), Pair(-52, -30), Pair(5, 55), Pair(5, 36),
        Pair(2, 88), Pair(-28, 54), Pair(4, 47), Pair(-6, 35), Pair(4, 63), Pair(3, 0), Pair(-4, 39), Pair(-5, -2),
        Pair(-23, 70), Pair(6, 76), Pair(13, 16), Pair(2, 45), Pair(-27, -26), Pair(-9, 63), Pair(-13, 17), Pair(-76, 75)
      },
      { // Piece 2
        Pair(-54, 80), Pair(-27, 69), Pair(-46, 79), Pair(-121, 106), Pair(-38, 71), Pair(-90, 77), Pair(7, 64), Pair(14, 74),
        Pair(-10, 57), Pair(-41, 65), Pair(21, 57), Pair(-62, 76), Pair(-42, 71), Pair(-13, 74), Pair(-14, 68), Pair(-31, 33),
        Pair(-11, 55), Pair(-27, 95), Pair(-29, 55), Pair(-16, 68), Pair(-47, 70), Pair(-49, 81), Pair(-16, 56), Pair(7, 92),
        Pair(-2, 58), Pair(-13, 60), Pair(-7, 70), Pair(-38, 61), Pair(-2, 69), Pair(-14, 50), Pair(1, 76), Pair(-17, 67),
        Pair(-14, 61), Pair(-12, 65), Pair(-21, 65), Pair(3, 71), Pair(0, 0), Pair(3, 84), Pair(-23, 64), Pair(12, 57),
        Pair(-3, 57), Pair(-6, 52), Pair(-5, 67), Pair(-68, -70), Pair(9, 124), Pair(-82, -26), Pair(4, 63), Pair(-10, 42),
        Pair(-14, 62), Pair(-3, 49), Pair(-40, 51), Pair(-9, 45), Pair(-3, 34), Pair(-36, 86), Pair(-42, -17), Pair(8, 46),
        Pair(-8, 51), Pair(-34, -5), Pair(-2, 54), Pair(-12, 43), Pair(-8, 66), Pair(-8, 40), Pair(-38, 133), Pair(-103, -28)
      },
      { // Piece 3
        Pair(-18, 91), Pair(-3, 77), Pair(14, 73), Pair(10, 68), Pair(-31, 94), Pair(-8, 82), Pair(12, 81), Pair(49, 64),
        Pair(-8, 72), Pair(-14, 82), Pair(-5, 75), Pair(7, 77), Pair(6, 82), Pair(7, 78), Pair(-8, 96), Pair(30, 77),
        Pair(3, 67), Pair(-21, 81), Pair(6, 73), Pair(-7, 86), Pair(15, 71), Pair(19, 73), Pair(19, 69), Pair(31, 65),
        Pair(0, 64), Pair(-20, 79), Pair(-10, 79), Pair(-15, 74), Pair(-6, 86), Pair(14, 61), Pair(-10, 74), Pair(14, 65),
        Pair(10, 60), Pair(11, 64), Pair(-30, 80), Pair(-3, 70), Pair(0, 0), Pair(-5, 63), Pair(4, 77), Pair(-18, 63),
        Pair(1, 67), Pair(-15, 60), Pair(-18, 63), Pair(-44, -32), Pair(-27, 80), Pair(-18, -33), Pair(-11, 69), Pair(-1, 56),
        Pair(-1, 77), Pair(14, 45), Pair(-13, 61), Pair(-7, 50), Pair(-25, 67), Pair(10, 72), Pair(29, 48), Pair(1, 65),
        Pair(0, 64), Pair(-2, 76), Pair(-8, 73), Pair(-16, 69), Pair(-22, 59), Pair(-4, 68), Pair(10, 65), Pair(0, 74)
      },
      { // Piece 4
        Pair(9, 145), Pair(53, 126), Pair(-16, 164), Pair(-16, 158), Pair(34, 149), Pair(43, 116), Pair(69, 131), Pair(-37, 186),
        Pair(28, 125), Pair(9, 130), Pair(22, 141), Pair(33, 129), Pair(23, 131), Pair(5, 149), Pair(-15, 202), Pair(28, 123),
        Pair(32, 141), Pair(25, 136), Pair(20, 91), Pair(16, 121), Pair(37, 148), Pair(15, 130), Pair(22, 131), Pair(-4, 160),
        Pair(28, 111), Pair(19, 109), Pair(17, 137), Pair(36, 80), Pair(35, 120), Pair(14, 125), Pair(31, 124), Pair(23, 137),
        Pair(20, 116), Pair(30, 105), Pair(15, 98), Pair(31, 101), Pair(0, 0), Pair(17, 123), Pair(27, 113), Pair(31, 104),
        Pair(21, 133), Pair(17, 110), Pair(20, 119), Pair(32, -15), Pair(33, 79), Pair(33, -26), Pair(21, 129), Pair(22, 133),
        Pair(23, 104), Pair(17, 124), Pair(16, 100), Pair(9, 114), Pair(29, 82), Pair(9, 122), Pair(25, 102), Pair(13, 186),
        Pair(17, 90), Pair(13, 101), Pair(16, 99), Pair(20, 85), Pair(17, 130), Pair(16, 101), Pair(46, 92), Pair(53, 47)
      },
      { // Piece 5
        Pair(-26, -1), Pair(65, -53), Pair(292, -80), Pair(96, 14), Pair(23, -35), Pair(49, -64), Pair(-54, -18), Pair(12, -60),
        Pair(75, -51), Pair(122, -55), Pair(66, -28), Pair(206, -39), Pair(229, -112), Pair(99, 7), Pair(151, -51), Pair(9, -2),
        Pair(73, -9), Pair(-2, -13), Pair(-1, 2), Pair(67, -6), Pair(328, -52), Pair(287, -62), Pair(200, -33), Pair(-120, 1),
        Pair(159, -30), Pair(191, -31), Pair(102, -19), Pair(30, 22), Pair(85, -1), Pair(141, -1), Pair(81, -4), Pair(154, -24),
        Pair(52, -6), Pair(46, 7), Pair(6, -8), Pair(53, -23), Pair(0, 0), Pair(96, -39), Pair(27, 8), Pair(66, 7),
        Pair(78, -16), Pair(-5, 10), Pair(3, 8), Pair(-69, -17), Pair(-70, 2), Pair(-25, 24), Pair(3, 22), Pair(-30, 31),
        Pair(38, 2), Pair(38, 3), Pair(3, 12), Pair(72, -18), Pair(28, -2), Pair(42, -5), Pair(-20, 25), Pair(-4, 32),
        Pair(42, -13), Pair(6, 6), Pair(12, 20), Pair(29, 7), Pair(-20, 10), Pair(4, 13), Pair(-14, 30), Pair(-4, 30)
      }
    }},
    {{ // Bucket 29
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-36, 25), Pair(18, 9), Pair(36, 6), Pair(21, -4), Pair(16, 5), Pair(-30, 6), Pair(-42, 9), Pair(-8, 28),
        Pair(6, 4), Pair(-6, 1), Pair(8, 3), Pair(3, 3), Pair(19, -3), Pair(30, 1), Pair(-3, 12), Pair(6, 8),
        Pair(5, -3), Pair(0, -1), Pair(5, -2), Pair(4, -3), Pair(-1, 2), Pair(0, 0), Pair(12, -6), Pair(3, 7),
        Pair(4, -8), Pair(2, -8), Pair(-1, -7), Pair(0, -5), Pair(4, -5), Pair(0, 0), Pair(6, -5), Pair(-3, 6),
        Pair(1, -9), Pair(2, -9), Pair(-3, -10), Pair(0, -5), Pair(-1, -6), Pair(15, 5), Pair(-5, -24), Pair(5, -2),
        Pair(-1, -9), Pair(1, -10), Pair(0, -11), Pair(1, -3), Pair(-12, -17), Pair(5, -3), Pair(-2, -16), Pair(7, -3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-47, 50), Pair(58, 60), Pair(-62, 67), Pair(-80, 37), Pair(-20, 67), Pair(-40, 85), Pair(118, -1), Pair(16, 92),
        Pair(50, 34), Pair(30, 60), Pair(24, 53), Pair(25, 71), Pair(-15, 79), Pair(38, 86), Pair(-36, 47), Pair(12, 64),
        Pair(-15, 62), Pair(17, 66), Pair(28, 38), Pair(-1, 52), Pair(50, 55), Pair(24, 60), Pair(11, 76), Pair(-56, 73),
        Pair(27, 36), Pair(19, 47), Pair(12, 55), Pair(10, 28), Pair(9, 81), Pair(-3, 46), Pair(17, 58), Pair(-43, 6),
        Pair(15, 31), Pair(12, 52), Pair(2, 35), Pair(11, 66), Pair(11, 53), Pair(0, 0), Pair(5, 46), Pair(7, 65),
        Pair(25, 45), Pair(10, 42), Pair(11, 47), Pair(24, 50), Pair(-32, -2), Pair(32, 103), Pair(-52, -24), Pair(32, 71),
        Pair(1, 43), Pair(-5, 40), Pair(-11, 35), Pair(20, 55), Pair(7, 38), Pair(13, 65), Pair(-17, 4), Pair(28, 46),
        Pair(-58, 36), Pair(11, 91), Pair(50, 18), Pair(4, 14), Pair(34, 59), Pair(-31, 1), Pair(44, 50), Pair(-38, 64)
      },
      { // Piece 2
        Pair(31, 123), Pair(23, 70), Pair(-18, 65), Pair(-10, 86), Pair(-30, 73), Pair(-98, 79), Pair(-80, 74), Pair(-29, 46),
        Pair(-29, 53), Pair(-18, 101), Pair(6, 60), Pair(0, 89), Pair(-39, 75), Pair(-30, 54), Pair(-54, 79), Pair(25, 84),
        Pair(-30, 108), Pair(-26, 76), Pair(3, 89), Pair(-42, 65), Pair(-15, 73), Pair(-50, 91), Pair(-24, 85), Pair(-50, 43),
        Pair(12, 51), Pair(13, 63), Pair(-11, 77), Pair(0, 70), Pair(-19, 61), Pair(-14, 96), Pair(-20, 41), Pair(-4, 97),
        Pair(6, 50), Pair(-8, 40), Pair(-3, 68), Pair(-6, 55), Pair(3, 82), Pair(0, 0), Pair(13, 82), Pair(-47, 58),
        Pair(1, 43), Pair(-11, 55), Pair(-5, 54), Pair(3, 71), Pair(-86, -21), Pair(26, 114), Pair(-125, -55), Pair(0, 77),
        Pair(26, 48), Pair(-1, 54), Pair(8, 64), Pair(-18, 28), Pair(5, 67), Pair(-17, 54), Pair(3, 47), Pair(-83, -58),
        Pair(-19, 48), Pair(-13, 102), Pair(-15, 13), Pair(11, 61), Pair(-19, 67), Pair(12, 49), Pair(-40, 51), Pair(-26, 143)
      },
      { // Piece 3
        Pair(16, 72), Pair(2, 87), Pair(67, 68), Pair(20, 77), Pair(-34, 89), Pair(27, 70), Pair(45, 70), Pair(26, 70),
        Pair(13, 60), Pair(12, 53), Pair(23, 67), Pair(-5, 73), Pair(37, 65), Pair(26, 63), Pair(83, 49), Pair(48, 67),
        Pair(13, 68), Pair(14, 69), Pair(22, 58), Pair(-1, 75), Pair(26, 52), Pair(33, 73), Pair(26, 73), Pair(-15, 76),
        Pair(9, 69), Pair(3, 76), Pair(20, 65), Pair(8, 66), Pair(9, 65), Pair(70, 77), Pair(22, 61), Pair(17, 65),
        Pair(15, 52), Pair(20, 65), Pair(10, 36), Pair(1, 46), Pair(19, 46), Pair(0, 0), Pair(10, 42), Pair(-16, 57),
        Pair(19, 38), Pair(-5, 71), Pair(-24, 66), Pair(8, 49), Pair(15, -52), Pair(-32, 93), Pair(71, -50), Pair(9, 58),
        Pair(39, 45), Pair(-7, 91), Pair(-3, 64), Pair(20, 50), Pair(17, 36), Pair(-18, 57), Pair(35, 67), Pair(14, 52),
        Pair(9, 51), Pair(12, 63), Pair(15, 53), Pair(8, 59), Pair(9, 54), Pair(2, 49), Pair(27, 34), Pair(8, 62)
      },
      { // Piece 4
        Pair(47, 34), Pair(37, 97), Pair(21, 131), Pair(-17, 131), Pair(126, -1), Pair(-101, 156), Pair(33, 82), Pair(80, 81),
        Pair(1, 102), Pair(18, 125), Pair(40, 90), Pair(-31, 146), Pair(-30, 135), Pair(5, 82), Pair(39, 92), Pair(3, 133),
        Pair(18, 96), Pair(10, 97), Pair(13, 127), Pair(29, 86), Pair(29, 138), Pair(99, 50), Pair(32, 91), Pair(59, 9),
        Pair(37, 112), Pair(14, 92), Pair(18, 79), Pair(31, 121), Pair(50, 68), Pair(34, 90), Pair(2, 59), Pair(20, 87),
        Pair(11, 115), Pair(30, 107), Pair(31, 59), Pair(19, 94), Pair(17, 87), Pair(0, 0), Pair(12, 71), Pair(-2, 96),
        Pair(7, 115), Pair(14, 113), Pair(31, 71), Pair(5, 94), Pair(6, -55), Pair(27, 65), Pair(99, -229), Pair(0, 83),
        Pair(37, 104), Pair(13, 128), Pair(18, 97), Pair(16, 89), Pair(5, 80), Pair(31, 44), Pair(27, 76), Pair(-25, 77),
        Pair(12, 105), Pair(37, 83), Pair(27, 21), Pair(22, 75), Pair(26, 58), Pair(22, 103), Pair(58, -42), Pair(-18, 107)
      },
      { // Piece 5
        Pair(15, -33), Pair(158, -77), Pair(-181, -101), Pair(-109, -59), Pair(116, -51), Pair(-182, -35), Pair(-81, -56), Pair(73, -64),
        Pair(-6, -11), Pair(40, -32), Pair(96, -24), Pair(105, -44), Pair(59, -33), Pair(174, -21), Pair(-4, -27), Pair(38, -37),
        Pair(-30, -2), Pair(-9, -10), Pair(-73, 18), Pair(-107, 13), Pair(39, 0), Pair(302, -16), Pair(141, 27), Pair(169, -17),
        Pair(-19, 34), Pair(-33, 17), Pair(66, 3), Pair(47, 13), Pair(78, 36), Pair(75, 20), Pair(52, 33), Pair(1, 25),
        Pair(111, -35), Pair(69, -13), Pair(40, -5), Pair(44, -1), Pair(47, -12), Pair(0, 0), Pair(19, -8), Pair(-20, 47),
        Pair(88, -6), Pair(57, -12), Pair(56, -1), Pair(10, 8), Pair(46, -15), Pair(-30, -5), Pair(137, 5), Pair(-24, 31),
        Pair(18, -20), Pair(26, -9), Pair(29, 0), Pair(-13, 7), Pair(25, 12), Pair(31, 14), Pair(18, 17), Pair(-20, 29),
        Pair(34, -26), Pair(-12, 17), Pair(3, 12), Pair(-29, 37), Pair(-7, 20), Pair(-26, 17), Pair(-15, 27), Pair(-19, 35)
      }
    }},
    {{ // Bucket 30
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(38, 2), Pair(-4, 24), Pair(36, 0), Pair(2, 12), Pair(-12, 21), Pair(15, 9), Pair(6, 16), Pair(-47, 31),
        Pair(-5, 0), Pair(-10, 6), Pair(-6, 6), Pair(6, 2), Pair(-11, 6), Pair(1, 8), Pair(-8, -2), Pair(-2, 12),
        Pair(4, -7), Pair(4, -6), Pair(1, -5), Pair(-1, -3), Pair(-5, -2), Pair(-9, 7), Pair(0, 0), Pair(11, 0),
        Pair(4, -9), Pair(4, -10), Pair(-2, -10), Pair(-7, -6), Pair(-5, -3), Pair(-4, -2), Pair(0, 0), Pair(15, 2),
        Pair(1, -8), Pair(2, -8), Pair(0, -9), Pair(-1, -8), Pair(0, -4), Pair(-6, -3), Pair(2, 0), Pair(10, 2),
        Pair(-1, -8), Pair(3, -12), Pair(-1, -16), Pair(-6, 8), Pair(-3, -7), Pair(-7, -10), Pair(-1, -2), Pair(1, -5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(70, 0), Pair(-67, 67), Pair(-120, 59), Pair(51, 33), Pair(-37, 62), Pair(-66, 85), Pair(31, 56), Pair(-30, -65),
        Pair(27, 56), Pair(52, 18), Pair(23, 21), Pair(-60, 64), Pair(108, 43), Pair(8, 66), Pair(-34, 47), Pair(0, 48),
        Pair(-46, 61), Pair(19, 51), Pair(20, 54), Pair(6, 47), Pair(-9, 65), Pair(-43, 74), Pair(-26, 77), Pair(-11, 42),
        Pair(30, 23), Pair(15, 45), Pair(11, 53), Pair(26, 41), Pair(-4, 40), Pair(-1, 66), Pair(-54, 53), Pair(27, 51),
        Pair(22, 48), Pair(10, 46), Pair(12, 49), Pair(2, 43), Pair(-4, 65), Pair(5, 43), Pair(0, 0), Pair(-6, 25),
        Pair(21, 28), Pair(8, 64), Pair(11, 57), Pair(7, 52), Pair(16, 39), Pair(-52, 10), Pair(31, 88), Pair(-68, -17),
        Pair(-20, 86), Pair(41, 26), Pair(8, 55), Pair(2, 29), Pair(15, 41), Pair(-17, 50), Pair(-2, 78), Pair(-5, 21),
        Pair(6, 11), Pair(-1, 62), Pair(-3, 61), Pair(39, 34), Pair(-4, 22), Pair(20, 42), Pair(-13, -62), Pair(-62, 133)
      },
      { // Piece 2
        Pair(-119, 108), Pair(-120, 142), Pair(-147, 96), Pair(-37, 75), Pair(-84, 79), Pair(-43, 53), Pair(8, 86), Pair(20, 47),
        Pair(-54, 65), Pair(-15, 77), Pair(-23, 99), Pair(-64, 83), Pair(-40, 80), Pair(-16, 91), Pair(-114, 96), Pair(-47, 106),
        Pair(-11, 89), Pair(40, 62), Pair(-21, 72), Pair(-36, 82), Pair(-54, 81), Pair(-58, 98), Pair(-23, 90), Pair(4, 57),
        Pair(5, 47), Pair(14, 52), Pair(-2, 74), Pair(-28, 91), Pair(0, 69), Pair(-40, 91), Pair(16, 71), Pair(-63, 31),
        Pair(10, 45), Pair(6, 59), Pair(-9, 53), Pair(-12, 68), Pair(-15, 63), Pair(-5, 62), Pair(0, 0), Pair(-17, 91),
        Pair(10, 56), Pair(10, 57), Pair(-2, 60), Pair(-7, 60), Pair(7, 54), Pair(-84, 19), Pair(0, 126), Pair(-22, -95),
        Pair(4, 90), Pair(8, 56), Pair(-9, 69), Pair(-2, 53), Pair(-12, 44), Pair(-25, 100), Pair(7, 26), Pair(-26, 72),
        Pair(8, 62), Pair(17, 47), Pair(2, 44), Pair(-35, 51), Pair(7, 73), Pair(-12, 50), Pair(-67, 104), Pair(-11, 35)
      },
      { // Piece 3
        Pair(41, 67), Pair(-37, 92), Pair(-44, 94), Pair(12, 79), Pair(-19, 79), Pair(-9, 81), Pair(3, 80), Pair(-112, 111),
        Pair(6, 53), Pair(3, 70), Pair(-7, 76), Pair(-35, 88), Pair(-1, 77), Pair(44, 58), Pair(32, 84), Pair(18, 55),
        Pair(22, 52), Pair(9, 72), Pair(13, 61), Pair(7, 67), Pair(4, 67), Pair(-12, 72), Pair(-5, 101), Pair(50, 43),
        Pair(15, 48), Pair(18, 69), Pair(17, 64), Pair(19, 70), Pair(20, 70), Pair(5, 56), Pair(54, 98), Pair(13, 61),
        Pair(25, 33), Pair(19, 63), Pair(7, 61), Pair(15, 57), Pair(7, 68), Pair(39, 76), Pair(0, 0), Pair(-1, 42),
        Pair(3, 65), Pair(28, 59), Pair(-20, 63), Pair(-21, 63), Pair(15, 73), Pair(-20, -72), Pair(-2, 66), Pair(-28, -28),
        Pair(24, 74), Pair(20, 50), Pair(20, 63), Pair(15, 55), Pair(28, 57), Pair(35, 49), Pair(3, 49), Pair(-12, 29),
        Pair(14, 52), Pair(21, 62), Pair(15, 58), Pair(17, 59), Pair(16, 61), Pair(13, 54), Pair(-19, 67), Pair(-1, 68)
      },
      { // Piece 4
        Pair(25, 73), Pair(20, 95), Pair(23, 69), Pair(90, 89), Pair(38, 94), Pair(107, 5), Pair(-1, 119), Pair(20, 94),
        Pair(19, 70), Pair(45, 87), Pair(-1, 141), Pair(5, 120), Pair(-13, 153), Pair(-27, 128), Pair(93, 41), Pair(37, 107),
        Pair(15, 78), Pair(24, 93), Pair(22, 92), Pair(5, 111), Pair(-29, 160), Pair(-17, 161), Pair(2, 143), Pair(33, 58),
        Pair(16, 98), Pair(12, 73), Pair(39, 102), Pair(5, 102), Pair(2, 126), Pair(26, 110), Pair(22, 74), Pair(-11, 85),
        Pair(23, 73), Pair(17, 99), Pair(17, 95), Pair(-13, 125), Pair(17, 125), Pair(31, 108), Pair(0, 0), Pair(-36, 61),
        Pair(14, 165), Pair(19, 97), Pair(17, 87), Pair(17, 93), Pair(28, 67), Pair(-34, 50), Pair(14, 94), Pair(28, -9),
        Pair(12, 99), Pair(19, 81), Pair(24, 92), Pair(22, 69), Pair(12, 98), Pair(15, 99), Pair(1, 80), Pair(25, 66),
        Pair(28, 34), Pair(43, 17), Pair(20, 95), Pair(26, 46), Pair(20, 65), Pair(26, 28), Pair(-9, 88), Pair(-43, 119)
      },
      { // Piece 5
        Pair(156, -34), Pair(187, -22), Pair(42, -89), Pair(127, -2), Pair(212, -3), Pair(31, -73), Pair(-151, -62), Pair(27, -237),
        Pair(-35, -23), Pair(-18, -15), Pair(130, -12), Pair(115, -29), Pair(-35, 9), Pair(191, 15), Pair(117, -65), Pair(-1, -35),
        Pair(314, -46), Pair(55, 15), Pair(-8, 2), Pair(72, 4), Pair(45, 20), Pair(221, -19), Pair(165, -12), Pair(390, -45),
        Pair(61, -6), Pair(104, -23), Pair(150, -25), Pair(17, 8), Pair(96, 4), Pair(22, 45), Pair(73, 16), Pair(153, 29),
        Pair(8, -32), Pair(107, -18), Pair(59, -13), Pair(68, 2), Pair(11, 15), Pair(29, -15), Pair(0, 0), Pair(-39, 11),
        Pair(132, -66), Pair(39, -30), Pair(46, -17), Pair(9, 3), Pair(-18, 12), Pair(120, 16), Pair(-53, -15), Pair(14, 67),
        Pair(7, -12), Pair(2, -6), Pair(19, -9), Pair(1, 1), Pair(-8, 3), Pair(19, 5), Pair(6, 10), Pair(4, 9),
        Pair(-38, -32), Pair(-24, -25), Pair(-26, -4), Pair(-6, 7), Pair(-22, 19), Pair(2, 18), Pair(-13, 7), Pair(-15, 11)
      }
    }},
    {{ // Bucket 31
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-12, 18), Pair(-14, 2), Pair(16, 5), Pair(4, -8), Pair(6, 9), Pair(23, 2), Pair(25, 15), Pair(24, -24),
        Pair(1, -1), Pair(1, -4), Pair(9, -4), Pair(-2, -1), Pair(-6, 0), Pair(-7, 7), Pair(-8, 1), Pair(-14, 9),
        Pair(7, -8), Pair(7, -5), Pair(-2, -5), Pair(0, -6), Pair(-2, -7), Pair(-3, -6), Pair(-12, 1), Pair(0, 0),
        Pair(3, -11), Pair(5, -14), Pair(0, -7), Pair(-1, -9), Pair(-5, -9), Pair(0, -4), Pair(-1, -14), Pair(0, 0),
        Pair(3, -15), Pair(4, -12), Pair(0, -14), Pair(5, -8), Pair(0, -8), Pair(-1, -4), Pair(-27, -14), Pair(9, 4),
        Pair(7, -11), Pair(3, -15), Pair(-1, -12), Pair(-3, -13), Pair(-2, 0), Pair(2, -8), Pair(-11, -13), Pair(-6, 7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(69, -69), Pair(20, 25), Pair(85, 2), Pair(76, -5), Pair(-71, 33), Pair(-180, 77), Pair(94, -37), Pair(31, -9),
        Pair(20, 10), Pair(75, -2), Pair(-2, 18), Pair(24, 10), Pair(23, 15), Pair(68, 13), Pair(-6, 22), Pair(21, 43),
        Pair(55, 6), Pair(69, 7), Pair(54, 14), Pair(17, 22), Pair(-11, 19), Pair(-40, 47), Pair(39, 18), Pair(-91, 95),
        Pair(40, -24), Pair(18, 15), Pair(20, 28), Pair(2, 11), Pair(30, 18), Pair(3, 26), Pair(5, 39), Pair(16, 32),
        Pair(30, -9), Pair(43, -21), Pair(7, 10), Pair(34, 30), Pair(4, 25), Pair(22, 23), Pair(16, 36), Pair(0, 0),
        Pair(14, 37), Pair(21, 8), Pair(18, 19), Pair(16, 9), Pair(22, 23), Pair(31, 21), Pair(-46, -45), Pair(46, 80),
        Pair(26, 2), Pair(27, 10), Pair(4, 10), Pair(23, 32), Pair(17, 15), Pair(35, 12), Pair(14, 51), Pair(54, 21),
        Pair(75, -82), Pair(18, 19), Pair(37, 13), Pair(8, 3), Pair(19, 16), Pair(10, 2), Pair(31, 59), Pair(3, -58)
      },
      { // Piece 2
        Pair(-30, 66), Pair(-80, 75), Pair(-133, 103), Pair(-30, 79), Pair(-119, 74), Pair(-9, 40), Pair(-28, 32), Pair(-48, 80),
        Pair(0, 30), Pair(0, 64), Pair(8, 72), Pair(-101, 113), Pair(-86, 87), Pair(5, 38), Pair(-22, 50), Pair(73, 27),
        Pair(8, 62), Pair(23, 62), Pair(-15, 67), Pair(28, 37), Pair(23, 82), Pair(-60, 82), Pair(-16, 46), Pair(23, 56),
        Pair(29, 38), Pair(19, 36), Pair(11, 48), Pair(-28, 65), Pair(-9, 55), Pair(-18, 70), Pair(13, 62), Pair(-8, 39),
        Pair(24, 46), Pair(-2, 23), Pair(-7, 36), Pair(16, 25), Pair(9, 41), Pair(17, 50), Pair(13, 65), Pair(0, 0),
        Pair(2, 39), Pair(11, 39), Pair(9, 40), Pair(3, 35), Pair(10, 31), Pair(11, 53), Pair(-69, -32), Pair(24, 125),
        Pair(21, 52), Pair(18, 25), Pair(-5, 36), Pair(11, 42), Pair(11, 41), Pair(9, 45), Pair(15, 38), Pair(39, 22),
        Pair(30, 13), Pair(-41, 41), Pair(17, 44), Pair(11, 31), Pair(8, 49), Pair(16, 45), Pair(21, 42), Pair(12, 71)
      },
      { // Piece 3
        Pair(21, 39), Pair(-3, 50), Pair(-20, 55), Pair(-32, 65), Pair(-73, 66), Pair(-64, 92), Pair(26, 59), Pair(49, 51),
        Pair(34, 37), Pair(28, 36), Pair(15, 45), Pair(-3, 49), Pair(23, 34), Pair(51, 44), Pair(45, 47), Pair(89, 55),
        Pair(13, 47), Pair(4, 56), Pair(-21, 53), Pair(-6, 54), Pair(23, 34), Pair(-24, 87), Pair(-21, 60), Pair(62, 68),
        Pair(35, 39), Pair(43, 37), Pair(1, 53), Pair(17, 43), Pair(19, 44), Pair(6, 63), Pair(2, 53), Pair(108, 56),
        Pair(30, 28), Pair(38, 42), Pair(24, 40), Pair(17, 42), Pair(12, 34), Pair(16, 67), Pair(35, 53), Pair(0, 0),
        Pair(2, 60), Pair(20, 51), Pair(11, 40), Pair(24, 36), Pair(11, 37), Pair(-6, 64), Pair(-18, -30), Pair(-17, 70),
        Pair(41, 39), Pair(8, 51), Pair(19, 28), Pair(18, 35), Pair(5, 44), Pair(25, 47), Pair(8, 73), Pair(10, 26),
        Pair(23, 38), Pair(21, 41), Pair(17, 41), Pair(18, 38), Pair(22, 47), Pair(21, 42), Pair(-7, 58), Pair(-18, 39)
      },
      { // Piece 4
        Pair(7, 71), Pair(-15, 96), Pair(4, 81), Pair(-15, 103), Pair(61, 43), Pair(13, 75), Pair(-45, 103), Pair(36, 101),
        Pair(33, 39), Pair(31, 38), Pair(-18, 90), Pair(7, 81), Pair(24, 71), Pair(2, 88), Pair(13, 90), Pair(68, 83),
        Pair(14, 60), Pair(61, 34), Pair(38, 75), Pair(19, 84), Pair(52, 47), Pair(42, 71), Pair(-4, 74), Pair(34, 63),
        Pair(41, 44), Pair(41, 46), Pair(28, 54), Pair(-17, 91), Pair(16, 94), Pair(26, 78), Pair(-23, 95), Pair(23, 104),
        Pair(18, 73), Pair(33, 51), Pair(15, 56), Pair(25, 69), Pair(14, 92), Pair(-6, 72), Pair(19, 66), Pair(0, 0),
        Pair(28, 46), Pair(4, 76), Pair(30, 57), Pair(16, 56), Pair(21, 71), Pair(5, 81), Pair(46, -185), Pair(-24, 130),
        Pair(7, 98), Pair(29, 44), Pair(16, 72), Pair(19, 60), Pair(14, 78), Pair(36, 39), Pair(35, 31), Pair(5, -10),
        Pair(9, 71), Pair(9, 61), Pair(27, 62), Pair(17, 63), Pair(43, 67), Pair(-3, 102), Pair(22, 46), Pair(-40, 76)
      },
      { // Piece 5
        Pair(-4, -49), Pair(152, -47), Pair(42, -55), Pair(-75, -47), Pair(77, -42), Pair(80, -40), Pair(-23, -62), Pair(-13, -150),
        Pair(329, -83), Pair(146, -64), Pair(38, -45), Pair(67, -35), Pair(11, -20), Pair(144, -4), Pair(-38, -32), Pair(-6, -23),
        Pair(191, -66), Pair(28, -15), Pair(99, -22), Pair(90, -25), Pair(190, -18), Pair(95, 9), Pair(195, -18), Pair(317, -88),
        Pair(111, -49), Pair(-30, -16), Pair(62, -16), Pair(124, -12), Pair(89, 8), Pair(86, 10), Pair(69, 33), Pair(153, 20),
        Pair(53, -54), Pair(53, -53), Pair(47, -28), Pair(52, -17), Pair(21, 9), Pair(-10, 22), Pair(-37, 7), Pair(0, 0),
        Pair(88, -61), Pair(5, -27), Pair(-18, -33), Pair(10, -11), Pair(24, 8), Pair(-36, 24), Pair(-26, -2), Pair(91, -27),
        Pair(1, -9), Pair(-32, -23), Pair(24, -31), Pair(-8, -10), Pair(-6, 14), Pair(-36, 24), Pair(11, 30), Pair(21, 15),
        Pair(29, -78), Pair(-32, -40), Pair(-19, -27), Pair(31, -20), Pair(-20, 26), Pair(-32, 37), Pair(2, 18), Pair(-14, 20)
      }
    }},
    {{ // Bucket 32
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 20), Pair(-23, 30), Pair(29, 4), Pair(-2, 10), Pair(-3, 23), Pair(40, 13), Pair(-28, 33), Pair(-53, 45),
        Pair(14, -7), Pair(-12, 14), Pair(6, 8), Pair(2, 10), Pair(10, 8), Pair(3, 13), Pair(1, 16), Pair(-12, 29),
        Pair(0, 0), Pair(-7, -3), Pair(-4, 2), Pair(0, 2), Pair(-6, 5), Pair(-4, 6), Pair(-5, 8), Pair(-3, 9),
        Pair(0, 0), Pair(-18, -5), Pair(-5, -1), Pair(-4, 1), Pair(-3, 5), Pair(-3, 3), Pair(-2, -3), Pair(-4, 3),
        Pair(-2, 10), Pair(-6, 0), Pair(0, -1), Pair(-4, -2), Pair(-5, 0), Pair(-10, -2), Pair(-6, 0), Pair(-7, -1),
        Pair(9, 3), Pair(-8, -6), Pair(5, -2), Pair(-5, 4), Pair(-4, -2), Pair(-5, -2), Pair(-2, -1), Pair(-2, -1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-14, 29), Pair(41, 17), Pair(-4, 56), Pair(35, 59), Pair(-8, 51), Pair(-73, 106), Pair(31, 125), Pair(54, 31),
        Pair(25, 88), Pair(-2, 101), Pair(10, 53), Pair(43, 58), Pair(-9, 82), Pair(58, 53), Pair(11, 33), Pair(22, 58),
        Pair(36, 32), Pair(2, 60), Pair(6, 60), Pair(13, 69), Pair(-9, 75), Pair(12, 61), Pair(16, 48), Pair(29, 58),
        Pair(0, 0), Pair(2, 76), Pair(-13, 82), Pair(-5, 55), Pair(1, 68), Pair(0, 66), Pair(0, 60), Pair(12, 34),
        Pair(3, 105), Pair(-201, -48), Pair(3, 72), Pair(-4, 69), Pair(-8, 72), Pair(-5, 57), Pair(7, 60), Pair(0, 60),
        Pair(-4, 85), Pair(-16, 82), Pair(-10, 73), Pair(-18, 58), Pair(-3, 62), Pair(-5, 65), Pair(-2, 51), Pair(11, 44),
        Pair(-10, 15), Pair(-5, 72), Pair(-13, 56), Pair(-4, 67), Pair(-3, 66), Pair(3, 52), Pair(3, 48), Pair(1, 44),
        Pair(-55, 46), Pair(-2, 76), Pair(1, 67), Pair(13, 54), Pair(-11, 49), Pair(-8, 57), Pair(5, 56), Pair(41, 28)
      },
      { // Piece 2
        Pair(-55, 91), Pair(6, 112), Pair(-77, 117), Pair(-57, 148), Pair(-81, 132), Pair(-46, 143), Pair(-48, 109), Pair(-99, 134),
        Pair(18, 129), Pair(-32, 99), Pair(-22, 133), Pair(-60, 124), Pair(7, 113), Pair(-27, 112), Pair(24, 130), Pair(-16, 76),
        Pair(-17, 110), Pair(-23, 128), Pair(-66, 113), Pair(-5, 107), Pair(-22, 115), Pair(-14, 119), Pair(-17, 106), Pair(14, 87),
        Pair(0, 0), Pair(-24, 99), Pair(-9, 89), Pair(-34, 98), Pair(-10, 125), Pair(-31, 99), Pair(-2, 91), Pair(1, 78),
        Pair(-11, 144), Pair(-249, 41), Pair(-19, 92), Pair(-19, 113), Pair(-13, 80), Pair(-11, 102), Pair(-20, 89), Pair(-4, 99),
        Pair(-2, 113), Pair(-28, 91), Pair(-15, 103), Pair(-18, 92), Pair(-8, 92), Pair(-23, 80), Pair(-5, 82), Pair(-18, 80),
        Pair(-23, 128), Pair(-5, 104), Pair(-14, 96), Pair(-8, 90), Pair(-21, 75), Pair(-28, 93), Pair(-17, 66), Pair(-4, 75),
        Pair(0, 104), Pair(1, 88), Pair(-1, 99), Pair(-21, 87), Pair(-32, 107), Pair(-17, 75), Pair(3, 87), Pair(-22, 82)
      },
      { // Piece 3
        Pair(36, 130), Pair(-30, 164), Pair(-15, 150), Pair(-7, 148), Pair(-58, 165), Pair(-50, 172), Pair(15, 136), Pair(-35, 155),
        Pair(14, 164), Pair(-22, 153), Pair(-32, 160), Pair(-13, 152), Pair(-7, 150), Pair(15, 143), Pair(54, 135), Pair(-38, 159),
        Pair(1, 165), Pair(-17, 141), Pair(-17, 146), Pair(-8, 147), Pair(-24, 146), Pair(-10, 150), Pair(-39, 141), Pair(-27, 154),
        Pair(0, 0), Pair(-15, 153), Pair(-35, 173), Pair(-33, 169), Pair(-24, 152), Pair(-12, 132), Pair(-10, 139), Pair(5, 136),
        Pair(-32, 141), Pair(-22, -28), Pair(-41, 145), Pair(-33, 140), Pair(-23, 129), Pair(-25, 127), Pair(-18, 140), Pair(-11, 133),
        Pair(-48, 124), Pair(-43, 137), Pair(-37, 131), Pair(-38, 125), Pair(-30, 131), Pair(-16, 128), Pair(-11, 133), Pair(-17, 129),
        Pair(-36, 124), Pair(-50, 142), Pair(-26, 123), Pair(-37, 128), Pair(-24, 131), Pair(-27, 133), Pair(-22, 138), Pair(-9, 131),
        Pair(-38, 125), Pair(-37, 133), Pair(-33, 131), Pair(-28, 129), Pair(-31, 135), Pair(-29, 136), Pair(-15, 129), Pair(-25, 143)
      },
      { // Piece 4
        Pair(-8, 292), Pair(38, 215), Pair(20, 300), Pair(-23, 318), Pair(54, 251), Pair(73, 216), Pair(115, 174), Pair(44, 265),
        Pair(37, 265), Pair(53, 235), Pair(32, 262), Pair(19, 295), Pair(24, 300), Pair(14, 271), Pair(51, 266), Pair(43, 238),
        Pair(33, 241), Pair(59, 225), Pair(27, 246), Pair(37, 246), Pair(27, 260), Pair(41, 255), Pair(49, 237), Pair(56, 250),
        Pair(0, 0), Pair(29, 250), Pair(43, 239), Pair(27, 255), Pair(36, 266), Pair(22, 283), Pair(41, 249), Pair(38, 239),
        Pair(27, 218), Pair(25, 71), Pair(33, 212), Pair(34, 227), Pair(37, 220), Pair(33, 220), Pair(42, 230), Pair(38, 236),
        Pair(25, 234), Pair(33, 209), Pair(26, 221), Pair(35, 200), Pair(23, 224), Pair(39, 213), Pair(49, 201), Pair(56, 204),
        Pair(24, 252), Pair(33, 211), Pair(31, 211), Pair(30, 225), Pair(40, 202), Pair(40, 184), Pair(27, 235), Pair(33, 217),
        Pair(30, 225), Pair(34, 211), Pair(24, 231), Pair(34, 214), Pair(25, 224), Pair(24, 232), Pair(69, 178), Pair(15, 240)
      },
      { // Piece 5
        Pair(-35, 33), Pair(-142, -69), Pair(75, -15), Pair(26, -18), Pair(-131, 14), Pair(1, -4), Pair(3, -7), Pair(-16, 2),
        Pair(116, -34), Pair(-141, -10), Pair(160, -13), Pair(107, -26), Pair(80, -23), Pair(122, -15), Pair(69, -16), Pair(76, 1),
        Pair(-24, 14), Pair(123, 8), Pair(20, -1), Pair(106, -1), Pair(207, -27), Pair(57, 14), Pair(26, 24), Pair(78, 17),
        Pair(0, 0), Pair(23, -29), Pair(65, -15), Pair(48, 8), Pair(95, 3), Pair(44, 11), Pair(37, 12), Pair(101, -15),
        Pair(49, -54), Pair(73, -117), Pair(-41, 12), Pair(5, 2), Pair(33, -2), Pair(9, 4), Pair(9, 2), Pair(60, -16),
        Pair(-34, 15), Pair(-19, 3), Pair(-29, -4), Pair(11, 4), Pair(9, -5), Pair(-1, -2), Pair(21, -14), Pair(34, -3),
        Pair(18, -22), Pair(-18, 22), Pair(9, 8), Pair(26, 1), Pair(14, -4), Pair(24, -15), Pair(3, -10), Pair(7, -5),
        Pair(-13, -2), Pair(22, 5), Pair(7, 14), Pair(-3, 19), Pair(11, 3), Pair(19, -11), Pair(-2, -11), Pair(8, -9)
      }
    }},
    {{ // Bucket 33
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-47, 43), Pair(25, -21), Pair(3, 32), Pair(9, 17), Pair(-1, 18), Pair(15, 16), Pair(-13, 28), Pair(-6, 33),
        Pair(-2, 8), Pair(-2, 9), Pair(-6, 14), Pair(-5, 13), Pair(12, 16), Pair(12, 14), Pair(-1, 18), Pair(-8, 21),
        Pair(-2, 4), Pair(0, 0), Pair(0, 5), Pair(-4, 9), Pair(2, 8), Pair(0, 10), Pair(-3, 12), Pair(-4, 13),
        Pair(20, 6), Pair(0, 0), Pair(1, 14), Pair(0, 0), Pair(-5, 2), Pair(-6, 3), Pair(-3, 4), Pair(-3, 8),
        Pair(8, -1), Pair(3, 5), Pair(-3, 10), Pair(1, 0), Pair(-5, 5), Pair(-8, -2), Pair(-6, -2), Pair(-3, 2),
        Pair(4, 5), Pair(13, 9), Pair(-4, 1), Pair(-3, 10), Pair(-3, -2), Pair(-6, -4), Pair(-5, -3), Pair(-1, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(28, 82), Pair(38, 43), Pair(-1, 61), Pair(-60, 105), Pair(-8, 108), Pair(33, 62), Pair(-43, 47), Pair(-59, 108),
        Pair(-1, 77), Pair(39, 57), Pair(44, 80), Pair(46, 39), Pair(-6, 75), Pair(42, 85), Pair(36, 71), Pair(44, 75),
        Pair(25, 80), Pair(23, 19), Pair(-7, 99), Pair(16, 60), Pair(13, 86), Pair(26, 72), Pair(49, 65), Pair(27, 42),
        Pair(2, 57), Pair(0, 0), Pair(-12, 82), Pair(3, 89), Pair(10, 74), Pair(19, 78), Pair(24, 78), Pair(36, 55),
        Pair(-48, 2), Pair(22, 120), Pair(-61, 28), Pair(13, 76), Pair(7, 86), Pair(14, 71), Pair(40, 74), Pair(28, 76),
        Pair(-17, 66), Pair(14, 85), Pair(-5, 65), Pair(2, 84), Pair(-5, 69), Pair(11, 79), Pair(22, 68), Pair(25, 70),
        Pair(11, 79), Pair(-13, 17), Pair(11, 80), Pair(5, 61), Pair(12, 70), Pair(13, 67), Pair(23, 77), Pair(15, 78),
        Pair(70, 45), Pair(9, 69), Pair(29, 80), Pair(2, 79), Pair(28, 70), Pair(19, 63), Pair(13, 73), Pair(-19, 85)
      },
      { // Piece 2
        Pair(-11, 112), Pair(13, 91), Pair(-84, 99), Pair(-115, 113), Pair(-97, 135), Pair(-61, 131), Pair(-37, 139), Pair(-14, 135),
        Pair(10, 85), Pair(-51, 140), Pair(17, 96), Pair(-27, 140), Pair(-32, 121), Pair(14, 112), Pair(36, 107), Pair(14, 114),
        Pair(-89, 95), Pair(-21, 100), Pair(-10, 109), Pair(-4, 104), Pair(2, 110), Pair(12, 112), Pair(10, 104), Pair(26, 67),
        Pair(6, 93), Pair(0, 0), Pair(-5, 114), Pair(-17, 110), Pair(5, 97), Pair(-4, 111), Pair(1, 106), Pair(13, 100),
        Pair(-72, 18), Pair(11, 139), Pair(-54, -25), Pair(-6, 103), Pair(-15, 107), Pair(1, 85), Pair(-6, 93), Pair(11, 76),
        Pair(-9, 88), Pair(-2, 102), Pair(-8, 93), Pair(7, 79), Pair(7, 87), Pair(-1, 91), Pair(4, 74), Pair(9, 101),
        Pair(8, 91), Pair(11, 90), Pair(8, 79), Pair(3, 92), Pair(4, 77), Pair(15, 65), Pair(6, 85), Pair(4, 43),
        Pair(19, 110), Pair(13, 100), Pair(9, 93), Pair(1, 92), Pair(10, 81), Pair(6, 64), Pair(20, 83), Pair(15, 80)
      },
      { // Piece 3
        Pair(-58, 156), Pair(11, 143), Pair(-19, 151), Pair(12, 141), Pair(-11, 139), Pair(-40, 159), Pair(-44, 153), Pair(24, 129),
        Pair(3, 149), Pair(59, 146), Pair(-11, 144), Pair(-19, 166), Pair(4, 145), Pair(23, 140), Pair(-3, 157), Pair(8, 131),
        Pair(-9, 130), Pair(-28, 162), Pair(27, 128), Pair(2, 142), Pair(5, 144), Pair(6, 125), Pair(-17, 140), Pair(7, 128),
        Pair(-2, 118), Pair(0, 0), Pair(2, 144), Pair(-1, 150), Pair(-2, 149), Pair(-10, 140), Pair(38, 122), Pair(20, 132),
        Pair(-6, 2), Pair(0, 122), Pair(-24, 49), Pair(-19, 128), Pair(-16, 132), Pair(3, 111), Pair(20, 118), Pair(9, 121),
        Pair(-27, 127), Pair(-29, 123), Pair(-44, 128), Pair(-4, 123), Pair(-2, 120), Pair(13, 121), Pair(8, 118), Pair(11, 131),
        Pair(-5, 100), Pair(-20, 103), Pair(-6, 113), Pair(4, 117), Pair(13, 111), Pair(4, 115), Pair(-4, 137), Pair(12, 140),
        Pair(-8, 122), Pair(-10, 115), Pair(-13, 122), Pair(-2, 125), Pair(0, 123), Pair(-2, 128), Pair(14, 119), Pair(8, 125)
      },
      { // Piece 4
        Pair(42, 243), Pair(48, 189), Pair(18, 243), Pair(68, 219), Pair(62, 233), Pair(163, 130), Pair(16, 219), Pair(32, 251),
        Pair(62, 204), Pair(63, 213), Pair(31, 249), Pair(34, 254), Pair(23, 248), Pair(43, 243), Pair(56, 262), Pair(56, 230),
        Pair(50, 174), Pair(35, 215), Pair(31, 234), Pair(43, 226), Pair(53, 243), Pair(92, 184), Pair(50, 203), Pair(50, 221),
        Pair(19, 193), Pair(0, 0), Pair(31, 229), Pair(43, 225), Pair(37, 251), Pair(58, 217), Pair(45, 210), Pair(40, 220),
        Pair(42, 78), Pair(24, 206), Pair(16, 171), Pair(35, 196), Pair(46, 199), Pair(43, 200), Pair(42, 198), Pair(50, 189),
        Pair(26, 223), Pair(33, 179), Pair(30, 189), Pair(26, 201), Pair(26, 223), Pair(41, 199), Pair(42, 204), Pair(46, 190),
        Pair(28, 212), Pair(30, 202), Pair(30, 183), Pair(37, 192), Pair(35, 183), Pair(41, 174), Pair(48, 176), Pair(50, 179),
        Pair(37, 189), Pair(60, 151), Pair(42, 202), Pair(37, 181), Pair(40, 208), Pair(31, 206), Pair(64, 168), Pair(11, 255)
      },
      { // Piece 5
        Pair(85, 27), Pair(169, 15), Pair(98, -92), Pair(74, -36), Pair(46, -20), Pair(-216, 22), Pair(-71, -11), Pair(140, -4),
        Pair(20, -33), Pair(110, -44), Pair(-60, -12), Pair(90, -1), Pair(66, 8), Pair(32, 31), Pair(-31, 17), Pair(75, 3),
        Pair(173, -31), Pair(-26, 2), Pair(183, -3), Pair(181, -5), Pair(150, -7), Pair(161, -4), Pair(45, 5), Pair(99, 21),
        Pair(1, -13), Pair(0, 0), Pair(66, -32), Pair(116, -14), Pair(153, 8), Pair(-2, 16), Pair(48, 7), Pair(110, -1),
        Pair(-35, 14), Pair(13, -62), Pair(-114, -19), Pair(7, -4), Pair(32, -1), Pair(40, 1), Pair(22, 2), Pair(41, -11),
        Pair(-47, 16), Pair(-44, -2), Pair(-6, -2), Pair(-17, 0), Pair(30, -1), Pair(34, -5), Pair(36, -15), Pair(48, -13),
        Pair(-25, 18), Pair(-14, -4), Pair(5, -6), Pair(13, 2), Pair(11, 4), Pair(14, -6), Pair(14, -10), Pair(23, -11),
        Pair(4, 4), Pair(-2, -10), Pair(0, 8), Pair(26, 19), Pair(9, 10), Pair(24, -2), Pair(11, -9), Pair(18, -8)
      }
    }},
    {{ // Bucket 34
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-14, 27), Pair(-3, 9), Pair(19, 13), Pair(18, 7), Pair(-11, 25), Pair(12, 10), Pair(22, 19), Pair(-21, 36),
        Pair(2, 4), Pair(-10, 9), Pair(-2, 22), Pair(9, -2), Pair(0, 12), Pair(8, 18), Pair(0, 16), Pair(-10, 24),
        Pair(1, 2), Pair(3, 2), Pair(0, 0), Pair(4, -1), Pair(0, 2), Pair(1, 6), Pair(-1, 7), Pair(-1, 7),
        Pair(3, -1), Pair(1, -13), Pair(0, 0), Pair(-9, 7), Pair(-2, -2), Pair(-1, 4), Pair(-1, 3), Pair(-3, 4),
        Pair(4, -2), Pair(4, -5), Pair(2, 3), Pair(-3, 2), Pair(-2, 4), Pair(-9, 1), Pair(-6, 2), Pair(-3, 1),
        Pair(1, -2), Pair(0, -9), Pair(9, 9), Pair(-14, -3), Pair(-2, -1), Pair(-7, -4), Pair(-2, -3), Pair(4, -1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-30, 48), Pair(98, 32), Pair(1, 91), Pair(-4, 83), Pair(51, 44), Pair(-1, 118), Pair(-45, 80), Pair(70, 31),
        Pair(-10, 66), Pair(7, 75), Pair(0, 75), Pair(-35, 104), Pair(27, 71), Pair(-28, 98), Pair(-66, 73), Pair(10, 80),
        Pair(5, 18), Pair(-2, 101), Pair(-42, 71), Pair(-14, 95), Pair(-26, 70), Pair(-2, 82), Pair(-11, 76), Pair(-15, 68),
        Pair(-14, 90), Pair(-14, 75), Pair(0, 0), Pair(-7, 82), Pair(-5, 93), Pair(-11, 66), Pair(1, 90), Pair(20, 62),
        Pair(-10, 98), Pair(-134, 35), Pair(6, 128), Pair(-112, 27), Pair(-6, 80), Pair(-10, 69), Pair(-7, 81), Pair(4, 82),
        Pair(-11, 102), Pair(-30, 61), Pair(-9, 82), Pair(-18, 55), Pair(-13, 86), Pair(-13, 60), Pair(-4, 67), Pair(-2, 85),
        Pair(-11, 49), Pair(-4, 83), Pair(-30, 43), Pair(-5, 89), Pair(-9, 51), Pair(3, 76), Pair(10, 68), Pair(4, 64),
        Pair(41, 66), Pair(-3, 86), Pair(0, 36), Pair(1, 76), Pair(-11, 68), Pair(5, 78), Pair(-12, 97), Pair(29, 79)
      },
      { // Piece 2
        Pair(-25, 95), Pair(25, 76), Pair(-50, 91), Pair(11, 103), Pair(-9, 104), Pair(-25, 85), Pair(-26, 127), Pair(3, 82),
        Pair(-72, 82), Pair(-16, 88), Pair(7, 93), Pair(-67, 95), Pair(-41, 70), Pair(-4, 115), Pair(-39, 109), Pair(-17, 92),
        Pair(-17, 103), Pair(-68, 74), Pair(-49, 101), Pair(-31, 94), Pair(-12, 91), Pair(-39, 102), Pair(10, 89), Pair(1, 74),
        Pair(-26, 86), Pair(-18, 95), Pair(0, 0), Pair(-22, 99), Pair(-19, 86), Pair(-23, 90), Pair(-16, 80), Pair(-15, 91),
        Pair(-20, 87), Pair(-151, -29), Pair(-3, 137), Pair(-132, -99), Pair(-12, 80), Pair(-14, 75), Pair(-12, 69), Pair(-7, 87),
        Pair(-34, 28), Pair(-28, 69), Pair(-19, 73), Pair(-16, 76), Pair(-22, 52), Pair(-18, 84), Pair(-5, 67), Pair(-5, 87),
        Pair(-37, 87), Pair(-13, 48), Pair(-9, 89), Pair(-15, 64), Pair(-17, 77), Pair(-24, 58), Pair(-10, 63), Pair(3, 71),
        Pair(-11, 52), Pair(1, 80), Pair(-8, 54), Pair(-10, 91), Pair(-16, 61), Pair(-16, 81), Pair(-40, 57), Pair(-37, 88)
      },
      { // Piece 3
        Pair(2, 109), Pair(-17, 113), Pair(-41, 108), Pair(-22, 114), Pair(-26, 111), Pair(-2, 113), Pair(51, 94), Pair(30, 109),
        Pair(-10, 118), Pair(-20, 122), Pair(-35, 133), Pair(6, 118), Pair(-31, 130), Pair(1, 113), Pair(-1, 106), Pair(-1, 108),
        Pair(-3, 101), Pair(-18, 116), Pair(-16, 112), Pair(1, 97), Pair(-12, 119), Pair(1, 109), Pair(-49, 114), Pair(-5, 99),
        Pair(-21, 102), Pair(-14, 103), Pair(0, 0), Pair(-17, 114), Pair(-12, 107), Pair(-11, 102), Pair(-15, 94), Pair(9, 88),
        Pair(-34, 104), Pair(-34, 12), Pair(-38, 99), Pair(-40, -10), Pair(-30, 102), Pair(-31, 98), Pair(-33, 107), Pair(-6, 87),
        Pair(-20, 109), Pair(-33, 103), Pair(-48, 99), Pair(-26, 83), Pair(-34, 110), Pair(-15, 102), Pair(-1, 68), Pair(2, 79),
        Pair(-11, 102), Pair(-26, 96), Pair(-29, 93), Pair(-25, 88), Pair(-15, 86), Pair(-11, 86), Pair(-13, 90), Pair(-11, 104),
        Pair(-26, 102), Pair(-27, 98), Pair(-30, 91), Pair(-25, 88), Pair(-22, 102), Pair(-18, 104), Pair(-10, 105), Pair(-11, 105)
      },
      { // Piece 4
        Pair(33, 167), Pair(-6, 200), Pair(57, 148), Pair(28, 193), Pair(85, 146), Pair(138, 141), Pair(56, 152), Pair(67, 145),
        Pair(23, 163), Pair(23, 188), Pair(18, 172), Pair(19, 174), Pair(32, 194), Pair(57, 207), Pair(12, 187), Pair(28, 202),
        Pair(30, 162), Pair(21, 147), Pair(30, 173), Pair(46, 143), Pair(32, 182), Pair(24, 193), Pair(35, 188), Pair(31, 193),
        Pair(31, 147), Pair(6, 170), Pair(0, 0), Pair(42, 141), Pair(32, 173), Pair(20, 202), Pair(27, 167), Pair(29, 183),
        Pair(15, 153), Pair(1, 48), Pair(36, 132), Pair(-4, 84), Pair(20, 153), Pair(22, 163), Pair(25, 176), Pair(30, 180),
        Pair(20, 136), Pair(16, 162), Pair(31, 126), Pair(16, 147), Pair(26, 131), Pair(19, 171), Pair(25, 178), Pair(24, 230),
        Pair(-2, 173), Pair(11, 140), Pair(24, 155), Pair(14, 147), Pair(21, 166), Pair(23, 141), Pair(9, 180), Pair(10, 176),
        Pair(18, 152), Pair(10, 171), Pair(16, 141), Pair(22, 152), Pair(16, 168), Pair(25, 161), Pair(34, 78), Pair(15, 214)
      },
      { // Piece 5
        Pair(83, -92), Pair(101, -52), Pair(200, -38), Pair(66, -15), Pair(15, -33), Pair(72, -63), Pair(52, -44), Pair(134, -36),
        Pair(40, -21), Pair(62, -5), Pair(-153, 23), Pair(-78, 19), Pair(131, -37), Pair(11, 0), Pair(71, -5), Pair(0, 9),
        Pair(7, -46), Pair(110, 2), Pair(-1, 34), Pair(209, -7), Pair(59, 22), Pair(33, 17), Pair(-19, 27), Pair(34, -5),
        Pair(-137, 51), Pair(60, -39), Pair(0, 0), Pair(63, -24), Pair(89, -9), Pair(66, 9), Pair(42, 19), Pair(61, 9),
        Pair(-31, 20), Pair(-184, -29), Pair(-57, -30), Pair(-112, -49), Pair(25, -3), Pair(16, 14), Pair(-15, 20), Pair(41, 2),
        Pair(-63, 28), Pair(17, -10), Pair(17, -18), Pair(45, -24), Pair(-15, 3), Pair(13, 6), Pair(15, 5), Pair(38, 3),
        Pair(-44, 33), Pair(-32, 2), Pair(-30, 6), Pair(-3, -1), Pair(8, 13), Pair(11, 5), Pair(4, 6), Pair(7, 2),
        Pair(-18, 39), Pair(-13, 3), Pair(-10, 6), Pair(27, 14), Pair(1, 20), Pair(20, 5), Pair(2, 10), Pair(2, 5)
      }
    }},
    {{ // Bucket 35
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-8, 22), Pair(26, 24), Pair(-6, 15), Pair(12, 4), Pair(-15, 17), Pair(-6, 22), Pair(8, 20), Pair(-18, 23),
        Pair(-3, 17), Pair(0, 8), Pair(4, 2), Pair(-13, 6), Pair(11, 15), Pair(1, 17), Pair(-3, 19), Pair(-8, 15),
        Pair(-2, 6), Pair(5, 6), Pair(-4, 0), Pair(0, 0), Pair(4, 1), Pair(-1, 2), Pair(4, 5), Pair(3, 10),
        Pair(3, -2), Pair(1, -6), Pair(9, -6), Pair(0, 0), Pair(1, 3), Pair(-2, -1), Pair(5, -3), Pair(0, 3),
        Pair(4, -5), Pair(2, -5), Pair(0, -6), Pair(0, 5), Pair(-1, 1), Pair(-4, 3), Pair(1, -2), Pair(-4, -1),
        Pair(4, 0), Pair(6, -1), Pair(-3, -4), Pair(4, 12), Pair(-5, -1), Pair(-2, 2), Pair(3, -3), Pair(4, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-66, 65), Pair(-8, 94), Pair(-17, 76), Pair(8, 117), Pair(-3, 66), Pair(-40, 105), Pair(-128, 57), Pair(-24, 99),
        Pair(0, 80), Pair(-20, 78), Pair(-4, 83), Pair(-70, 103), Pair(22, 84), Pair(-47, 94), Pair(16, 88), Pair(13, 72),
        Pair(-5, 102), Pair(-20, 39), Pair(-28, 100), Pair(-31, 60), Pair(3, 87), Pair(5, 45), Pair(-8, 86), Pair(18, 63),
        Pair(-20, 67), Pair(-8, 70), Pair(-9, 71), Pair(0, 0), Pair(-11, 76), Pair(-19, 102), Pair(-12, 63), Pair(-8, 99),
        Pair(-7, 72), Pair(11, 63), Pair(-71, -18), Pair(13, 119), Pair(-147, 17), Pair(-8, 78), Pair(3, 73), Pair(-1, 69),
        Pair(-4, 30), Pair(-7, 72), Pair(-12, 40), Pair(-8, 81), Pair(-23, 51), Pair(-1, 80), Pair(-8, 51), Pair(6, 78),
        Pair(8, 77), Pair(-16, 41), Pair(5, 73), Pair(-13, 17), Pair(7, 70), Pair(-13, 52), Pair(9, 69), Pair(4, 104),
        Pair(2, 104), Pair(1, 47), Pair(5, 89), Pair(5, 43), Pair(2, 87), Pair(-2, 62), Pair(5, 76), Pair(19, 84)
      },
      { // Piece 2
        Pair(-12, 83), Pair(-115, 100), Pair(-108, 87), Pair(-20, 78), Pair(-84, 103), Pair(-50, 114), Pair(-134, 134), Pair(72, 57),
        Pair(3, 93), Pair(-39, 58), Pair(-13, 87), Pair(-69, 90), Pair(-72, 91), Pair(8, 71), Pair(-27, 99), Pair(-27, 67),
        Pair(-34, 79), Pair(-4, 76), Pair(-69, 43), Pair(-25, 83), Pair(-35, 87), Pair(-46, 106), Pair(-13, 97), Pair(-3, 79),
        Pair(-21, 95), Pair(-22, 63), Pair(-13, 84), Pair(0, 0), Pair(-14, 85), Pair(-27, 87), Pair(-7, 75), Pair(-25, 63),
        Pair(-23, 76), Pair(-21, 70), Pair(-67, -140), Pair(17, 116), Pair(-190, -283), Pair(-4, 65), Pair(-23, 65), Pair(-6, 86),
        Pair(-5, 63), Pair(-45, 42), Pair(-21, 76), Pair(-16, 52), Pair(-8, 51), Pair(-30, 40), Pair(-5, 66), Pair(-12, 59),
        Pair(-51, 11), Pair(-8, 56), Pair(-21, 61), Pair(0, 64), Pair(-19, 49), Pair(3, 65), Pair(-22, 19), Pair(-4, 62),
        Pair(-25, 71), Pair(-28, 68), Pair(-2, 75), Pair(-14, 63), Pair(-3, 72), Pair(-13, 53), Pair(-6, 59), Pair(-47, 72)
      },
      { // Piece 3
        Pair(-10, 94), Pair(-25, 112), Pair(-36, 104), Pair(10, 94), Pair(-10, 97), Pair(-74, 133), Pair(-6, 85), Pair(-57, 118),
        Pair(-8, 100), Pair(-17, 107), Pair(-19, 112), Pair(-61, 136), Pair(-11, 114), Pair(23, 92), Pair(13, 86), Pair(-20, 104),
        Pair(-9, 99), Pair(-10, 98), Pair(-22, 101), Pair(4, 101), Pair(-1, 93), Pair(4, 106), Pair(-27, 102), Pair(-5, 74),
        Pair(-18, 93), Pair(-8, 78), Pair(-17, 95), Pair(0, 0), Pair(-9, 94), Pair(-8, 88), Pair(5, 81), Pair(-10, 80),
        Pair(-7, 74), Pair(-32, 90), Pair(4, -48), Pair(-20, 76), Pair(-65, -54), Pair(-39, 97), Pair(-29, 86), Pair(1, 68),
        Pair(-9, 86), Pair(-5, 67), Pair(-16, 64), Pair(-29, 74), Pair(-32, 87), Pair(-4, 80), Pair(-13, 101), Pair(7, 75),
        Pair(8, 65), Pair(-22, 99), Pair(-16, 77), Pair(-20, 69), Pair(-16, 76), Pair(-14, 81), Pair(-20, 113), Pair(-20, 92),
        Pair(-14, 92), Pair(-11, 87), Pair(-20, 87), Pair(-24, 76), Pair(-20, 86), Pair(-14, 89), Pair(-9, 80), Pair(5, 82)
      },
      { // Piece 4
        Pair(-42, 186), Pair(27, 162), Pair(39, 172), Pair(13, 176), Pair(-27, 205), Pair(10, 203), Pair(83, 162), Pair(-6, 210),
        Pair(10, 207), Pair(27, 147), Pair(44, 169), Pair(43, 128), Pair(7, 206), Pair(-46, 226), Pair(46, 197), Pair(26, 165),
        Pair(34, 162), Pair(18, 198), Pair(19, 130), Pair(32, 148), Pair(35, 161), Pair(12, 217), Pair(4, 205), Pair(35, 176),
        Pair(16, 161), Pair(30, 136), Pair(14, 144), Pair(0, 0), Pair(27, 134), Pair(14, 174), Pair(23, 183), Pair(28, 156),
        Pair(19, 138), Pair(18, 156), Pair(16, -3), Pair(41, 127), Pair(29, -23), Pair(25, 153), Pair(22, 147), Pair(17, 184),
        Pair(17, 178), Pair(17, 135), Pair(17, 145), Pair(27, 141), Pair(19, 145), Pair(15, 136), Pair(36, 139), Pair(34, 163),
        Pair(20, 147), Pair(24, 160), Pair(18, 138), Pair(26, 150), Pair(14, 154), Pair(19, 166), Pair(23, 132), Pair(48, 130),
        Pair(18, 150), Pair(25, 139), Pair(21, 171), Pair(29, 150), Pair(25, 150), Pair(29, 150), Pair(46, 70), Pair(26, 128)
      },
      { // Piece 5
        Pair(11, 123), Pair(-56, -41), Pair(-69, -23), Pair(-42, -2), Pair(72, 1), Pair(129, -56), Pair(48, -33), Pair(246, -9),
        Pair(109, 53), Pair(-94, 14), Pair(34, 24), Pair(100, -63), Pair(-25, -17), Pair(20, -13), Pair(93, 14), Pair(56, -19),
        Pair(67, 22), Pair(18, 28), Pair(94, -15), Pair(131, -29), Pair(69, 10), Pair(115, 4), Pair(49, 33), Pair(28, -3),
        Pair(59, 11), Pair(98, 11), Pair(30, -46), Pair(0, 0), Pair(153, -61), Pair(-7, 5), Pair(66, 24), Pair(34, 9),
        Pair(45, 17), Pair(-46, 34), Pair(-115, 45), Pair(-6, -50), Pair(45, -26), Pair(46, -5), Pair(31, 3), Pair(89, 3),
        Pair(32, 35), Pair(22, 14), Pair(39, -16), Pair(27, -42), Pair(27, -24), Pair(-2, 3), Pair(10, 9), Pair(62, -3),
        Pair(-37, 34), Pair(-4, 11), Pair(-7, 5), Pair(7, -11), Pair(-4, 2), Pair(-1, 16), Pair(3, 14), Pair(6, 11),
        Pair(18, 5), Pair(-18, 24), Pair(-13, 12), Pair(13, -10), Pair(-8, 15), Pair(-3, 19), Pair(-2, 19), Pair(5, 17)
      }
    }},
    {{ // Bucket 36
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-6, 20), Pair(35, 12), Pair(-27, 26), Pair(4, 10), Pair(22, 2), Pair(4, 33), Pair(-15, 28), Pair(-17, 29),
        Pair(7, 6), Pair(-2, 13), Pair(3, 8), Pair(0, 4), Pair(-8, 16), Pair(5, 4), Pair(0, 14), Pair(-12, 18),
        Pair(1, 1), Pair(2, 0), Pair(1, 4), Pair(5, 0), Pair(0, 0), Pair(-2, 8), Pair(2, 3), Pair(3, 10),
        Pair(3, -6), Pair(2, -3), Pair(3, -6), Pair(0, 2), Pair(0, 0), Pair(-3, -5), Pair(3, -1), Pair(0, 6),
        Pair(-1, -5), Pair(2, -5), Pair(-3, -1), Pair(0, 0), Pair(1, 5), Pair(-6, -3), Pair(-1, 1), Pair(-1, 1),
        Pair(5, -4), Pair(2, 0), Pair(1, -3), Pair(-7, -1), Pair(2, 6), Pair(-8, -4), Pair(4, 6), Pair(-1, -1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-34, 89), Pair(-132, 83), Pair(22, 68), Pair(36, 50), Pair(-11, 74), Pair(-43, 64), Pair(-95, 62), Pair(34, 78),
        Pair(-7, 56), Pair(-9, 76), Pair(7, 71), Pair(-1, 46), Pair(-55, 102), Pair(-74, 106), Pair(-11, 56), Pair(-23, 104),
        Pair(11, 79), Pair(10, 70), Pair(0, 25), Pair(-19, 85), Pair(-15, 54), Pair(-60, 85), Pair(-27, 37), Pair(-4, 48),
        Pair(11, 61), Pair(-6, 59), Pair(-2, 89), Pair(-7, 62), Pair(0, 0), Pair(-20, 66), Pair(-7, 69), Pair(-44, 67),
        Pair(7, 87), Pair(-7, 54), Pair(-3, 69), Pair(-112, -5), Pair(10, 113), Pair(-46, -25), Pair(-6, 58), Pair(-1, 55),
        Pair(5, 81), Pair(-13, 55), Pair(-3, 72), Pair(-23, 52), Pair(-7, 71), Pair(-10, 31), Pair(-3, 58), Pair(-12, 23),
        Pair(-1, 100), Pair(18, 54), Pair(2, 40), Pair(4, 73), Pair(-14, 13), Pair(-9, 78), Pair(-9, 34), Pair(0, 74),
        Pair(42, 36), Pair(9, 101), Pair(6, 38), Pair(21, 74), Pair(3, 49), Pair(15, 54), Pair(-11, 56), Pair(41, 31)
      },
      { // Piece 2
        Pair(2, 100), Pair(-35, 80), Pair(-75, 104), Pair(-72, 110), Pair(-97, 105), Pair(-69, 79), Pair(12, 74), Pair(15, 55),
        Pair(-31, 70), Pair(-17, 75), Pair(2, 57), Pair(-73, 99), Pair(-57, 92), Pair(-17, 78), Pair(97, 21), Pair(19, 86),
        Pair(-5, 73), Pair(-14, 69), Pair(-38, 87), Pair(-28, 55), Pair(-15, 78), Pair(-91, 51), Pair(-18, 90), Pair(-15, 71),
        Pair(-18, 73), Pair(-7, 82), Pair(-21, 71), Pair(-6, 77), Pair(0, 0), Pair(-21, 94), Pair(-19, 63), Pair(-2, 67),
        Pair(-6, 64), Pair(-10, 74), Pair(-15, 85), Pair(-140, -121), Pair(8, 110), Pair(-42, -65), Pair(-2, 69), Pair(-20, 56),
        Pair(-1, 54), Pair(-10, 78), Pair(-25, 40), Pair(-14, 58), Pair(-11, 38), Pair(-16, 57), Pair(-24, -2), Pair(-8, 67),
        Pair(1, 118), Pair(-12, 20), Pair(-6, 80), Pair(-8, 40), Pair(-3, 66), Pair(-7, 49), Pair(-9, 50), Pair(-24, -25),
        Pair(-42, 17), Pair(-5, 79), Pair(0, 49), Pair(0, 69), Pair(-6, 58), Pair(-3, 68), Pair(-20, 61), Pair(7, 72)
      },
      { // Piece 3
        Pair(-15, 88), Pair(14, 91), Pair(-14, 96), Pair(-56, 105), Pair(-25, 83), Pair(-46, 103), Pair(-1, 90), Pair(-25, 100),
        Pair(0, 82), Pair(1, 83), Pair(-6, 98), Pair(-6, 88), Pair(-1, 104), Pair(12, 88), Pair(8, 94), Pair(0, 92),
        Pair(5, 83), Pair(-3, 86), Pair(13, 89), Pair(-14, 92), Pair(29, 74), Pair(4, 81), Pair(19, 74), Pair(-27, 98),
        Pair(-7, 82), Pair(2, 77), Pair(-14, 84), Pair(7, 64), Pair(0, 0), Pair(-7, 71), Pair(17, 75), Pair(-21, 74),
        Pair(11, 77), Pair(4, 77), Pair(0, 76), Pair(-36, -2), Pair(-1, 56), Pair(-36, -57), Pair(-20, 80), Pair(-27, 86),
        Pair(9, 75), Pair(6, 73), Pair(-20, 78), Pair(-11, 63), Pair(-19, 56), Pair(-15, 78), Pair(-3, 77), Pair(3, 64),
        Pair(19, 78), Pair(0, 84), Pair(4, 78), Pair(-4, 65), Pair(-13, 66), Pair(-2, 72), Pair(6, 79), Pair(24, 49),
        Pair(5, 78), Pair(1, 74), Pair(-1, 74), Pair(-12, 72), Pair(-7, 63), Pair(-3, 76), Pair(1, 73), Pair(0, 87)
      },
      { // Piece 4
        Pair(32, 190), Pair(25, 119), Pair(-17, 226), Pair(20, 177), Pair(-2, 183), Pair(-40, 222), Pair(8, 240), Pair(-15, 139),
        Pair(41, 145), Pair(14, 180), Pair(-7, 187), Pair(30, 157), Pair(9, 161), Pair(-14, 231), Pair(15, 144), Pair(12, 169),
        Pair(36, 155), Pair(31, 144), Pair(24, 187), Pair(34, 126), Pair(49, 135), Pair(9, 181), Pair(2, 211), Pair(24, 191),
        Pair(28, 137), Pair(17, 169), Pair(15, 118), Pair(34, 132), Pair(0, 0), Pair(10, 161), Pair(18, 121), Pair(15, 164),
        Pair(26, 162), Pair(9, 181), Pair(26, 136), Pair(14, 60), Pair(45, 116), Pair(49, -21), Pair(20, 155), Pair(5, 179),
        Pair(30, 188), Pair(19, 149), Pair(12, 137), Pair(7, 138), Pair(27, 118), Pair(24, 121), Pair(16, 135), Pair(22, 147),
        Pair(21, 149), Pair(13, 132), Pair(17, 145), Pair(16, 137), Pair(30, 140), Pair(20, 152), Pair(30, 135), Pair(1, 156),
        Pair(-1, 176), Pair(18, 158), Pair(19, 126), Pair(21, 146), Pair(27, 134), Pair(43, 142), Pair(-32, 153), Pair(-3, 184)
      },
      { // Piece 5
        Pair(-183, 12), Pair(-46, -38), Pair(57, -27), Pair(-51, 71), Pair(30, -11), Pair(39, 0), Pair(86, -61), Pair(-22, -71),
        Pair(-36, 11), Pair(13, 12), Pair(27, 7), Pair(19, 6), Pair(36, -39), Pair(50, 14), Pair(59, 7), Pair(174, -3),
        Pair(45, 27), Pair(86, 5), Pair(29, 13), Pair(114, 14), Pair(119, -6), Pair(232, -8), Pair(90, 20), Pair(102, 14),
        Pair(69, 2), Pair(15, 19), Pair(39, 3), Pair(154, -63), Pair(0, 0), Pair(143, -43), Pair(110, 2), Pair(63, 18),
        Pair(-20, 24), Pair(-27, 27), Pair(-11, 13), Pair(195, -78), Pair(15, -36), Pair(43, -52), Pair(11, 15), Pair(36, 17),
        Pair(23, 16), Pair(10, 6), Pair(21, 4), Pair(75, -24), Pair(56, -32), Pair(66, -15), Pair(2, 17), Pair(20, 20),
        Pair(10, 30), Pair(11, 21), Pair(10, 20), Pair(10, 9), Pair(25, -9), Pair(24, 1), Pair(-1, 27), Pair(12, 21),
        Pair(15, 13), Pair(-3, 29), Pair(-1, 36), Pair(16, 14), Pair(2, 15), Pair(31, 10), Pair(-1, 33), Pair(9, 39)
      }
    }},
    {{ // Bucket 37
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-15, 24), Pair(28, 7), Pair(18, 13), Pair(40, -4), Pair(-13, 28), Pair(2, 34), Pair(10, 24), Pair(15, 19),
        Pair(7, 11), Pair(7, 7), Pair(5, 9), Pair(5, 4), Pair(0, 4), Pair(-9, 15), Pair(2, 6), Pair(-1, 15),
        Pair(5, 0), Pair(4, 0), Pair(3, 3), Pair(3, -4), Pair(4, 1), Pair(0, 0), Pair(2, 1), Pair(2, 4),
        Pair(5, -3), Pair(2, -6), Pair(4, -2), Pair(3, -4), Pair(5, 5), Pair(0, 0), Pair(-3, -9), Pair(0, 0),
        Pair(3, -5), Pair(4, -5), Pair(0, -3), Pair(4, -2), Pair(0, -1), Pair(1, 2), Pair(-7, -4), Pair(1, -1),
        Pair(4, -7), Pair(4, -5), Pair(4, -6), Pair(-2, 1), Pair(-3, 2), Pair(9, 1), Pair(-5, -6), Pair(1, -5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(20, 63), Pair(-44, 66), Pair(-13, 59), Pair(-15, 72), Pair(9, 48), Pair(19, 78), Pair(17, 31), Pair(-6, 136),
        Pair(-26, 75), Pair(5, 62), Pair(17, 61), Pair(11, 57), Pair(-28, 73), Pair(-8, 100), Pair(-30, 70), Pair(22, 48),
        Pair(13, 62), Pair(6, 60), Pair(9, 64), Pair(1, 42), Pair(-19, 85), Pair(-37, 52), Pair(-10, 67), Pair(-41, 33),
        Pair(22, 60), Pair(12, 66), Pair(4, 40), Pair(3, 59), Pair(-6, 67), Pair(0, 0), Pair(-12, 46), Pair(-9, 57),
        Pair(25, 50), Pair(9, 55), Pair(5, 54), Pair(10, 55), Pair(-109, 8), Pair(6, 97), Pair(-95, -12), Pair(4, 50),
        Pair(18, 45), Pair(5, 62), Pair(2, 42), Pair(7, 57), Pair(-10, 40), Pair(7, 59), Pair(-20, 33), Pair(-1, 60),
        Pair(-2, 71), Pair(21, 51), Pair(-2, 57), Pair(2, 39), Pair(7, 58), Pair(-22, 17), Pair(1, 72), Pair(0, 8),
        Pair(21, 71), Pair(11, 75), Pair(21, 38), Pair(21, 46), Pair(3, 77), Pair(1, 48), Pair(6, 37), Pair(-23, 35)
      },
      { // Piece 2
        Pair(-17, 84), Pair(13, 89), Pair(-56, 84), Pair(-15, 70), Pair(-88, 95), Pair(-81, 74), Pair(-76, 74), Pair(14, 61),
        Pair(4, 56), Pair(-18, 68), Pair(5, 73), Pair(-17, 61), Pair(-42, 80), Pair(0, 77), Pair(-2, 77), Pair(-72, 29),
        Pair(-8, 79), Pair(-7, 78), Pair(-25, 75), Pair(-1, 65), Pair(-33, 65), Pair(-23, 74), Pair(-61, 51), Pair(-8, 68),
        Pair(12, 62), Pair(-10, 76), Pair(4, 62), Pair(-21, 61), Pair(-9, 67), Pair(0, 0), Pair(-6, 71), Pair(-16, 68),
        Pair(-8, 71), Pair(12, 51), Pair(-13, 62), Pair(-4, 60), Pair(-135, -40), Pair(7, 104), Pair(-145, -84), Pair(-9, 52),
        Pair(12, 54), Pair(0, 60), Pair(5, 61), Pair(-17, 44), Pair(-4, 42), Pair(-10, 43), Pair(-15, 52), Pair(-39, 28),
        Pair(1, 51), Pair(13, 54), Pair(-21, 60), Pair(5, 55), Pair(-6, 45), Pair(4, 61), Pair(-18, 35), Pair(-6, 54),
        Pair(-7, 65), Pair(-39, 48), Pair(6, 49), Pair(6, 51), Pair(15, 61), Pair(-3, 56), Pair(-41, 88), Pair(-20, 53)
      },
      { // Piece 3
        Pair(29, 63), Pair(10, 87), Pair(-1, 86), Pair(25, 80), Pair(59, 57), Pair(65, 55), Pair(12, 70), Pair(7, 80),
        Pair(20, 68), Pair(12, 72), Pair(7, 73), Pair(7, 80), Pair(0, 83), Pair(36, 89), Pair(60, 56), Pair(17, 71),
        Pair(25, 62), Pair(16, 79), Pair(15, 67), Pair(26, 73), Pair(13, 63), Pair(104, 54), Pair(24, 56), Pair(14, 81),
        Pair(12, 62), Pair(12, 70), Pair(10, 65), Pair(9, 69), Pair(37, 57), Pair(0, 0), Pair(7, 55), Pair(4, 55),
        Pair(10, 66), Pair(18, 64), Pair(21, 59), Pair(-18, 73), Pair(-15, -49), Pair(3, 59), Pair(7, -78), Pair(-1, 59),
        Pair(23, 58), Pair(24, 62), Pair(4, 67), Pair(12, 63), Pair(13, 51), Pair(7, 56), Pair(-18, 79), Pair(2, 71),
        Pair(3, 82), Pair(19, 51), Pair(16, 60), Pair(17, 66), Pair(3, 49), Pair(16, 54), Pair(17, 62), Pair(43, 32),
        Pair(15, 68), Pair(15, 64), Pair(14, 69), Pair(12, 65), Pair(9, 57), Pair(9, 61), Pair(6, 62), Pair(6, 71)
      },
      { // Piece 4
        Pair(48, 97), Pair(16, 153), Pair(80, 69), Pair(0, 153), Pair(52, 111), Pair(24, 120), Pair(62, 171), Pair(69, 120),
        Pair(41, 136), Pair(12, 136), Pair(23, 135), Pair(35, 128), Pair(13, 161), Pair(36, 118), Pair(-4, 155), Pair(21, 144),
        Pair(32, 117), Pair(8, 140), Pair(18, 107), Pair(27, 149), Pair(20, 111), Pair(43, 113), Pair(-2, 102), Pair(15, 154),
        Pair(41, 123), Pair(33, 122), Pair(39, 122), Pair(35, 105), Pair(26, 98), Pair(0, 0), Pair(4, 138), Pair(25, 65),
        Pair(15, 133), Pair(30, 128), Pair(21, 108), Pair(14, 114), Pair(-25, 66), Pair(36, 71), Pair(31, -12), Pair(20, 123),
        Pair(35, 132), Pair(22, 140), Pair(25, 114), Pair(11, 113), Pair(20, 106), Pair(31, 69), Pair(15, 113), Pair(19, 49),
        Pair(30, 136), Pair(20, 135), Pair(24, 95), Pair(20, 121), Pair(23, 104), Pair(25, 98), Pair(19, 120), Pair(51, 103),
        Pair(35, 106), Pair(25, 95), Pair(36, 95), Pair(25, 107), Pair(35, 92), Pair(48, 48), Pair(6, 132), Pair(59, 92)
      },
      { // Piece 5
        Pair(108, 23), Pair(112, -40), Pair(-245, 26), Pair(28, -30), Pair(-49, -43), Pair(143, -107), Pair(-198, -15), Pair(-122, 10),
        Pair(-121, 6), Pair(20, -13), Pair(50, 4), Pair(-64, -36), Pair(119, -41), Pair(27, -4), Pair(53, 3), Pair(-19, -2),
        Pair(94, -8), Pair(37, 4), Pair(-103, 30), Pair(37, 4), Pair(58, -7), Pair(176, -1), Pair(19, 25), Pair(43, -9),
        Pair(22, 6), Pair(0, 23), Pair(73, 11), Pair(61, 1), Pair(111, -34), Pair(0, 0), Pair(101, -36), Pair(26, 21),
        Pair(98, -8), Pair(32, 6), Pair(29, 5), Pair(9, 1), Pair(-13, -55), Pair(-24, -28), Pair(-88, -41), Pair(-3, 30),
        Pair(73, -11), Pair(31, -8), Pair(44, 2), Pair(19, -3), Pair(68, -20), Pair(38, -12), Pair(19, 0), Pair(-3, 13),
        Pair(-17, 6), Pair(25, -13), Pair(28, 6), Pair(9, 11), Pair(16, 6), Pair(8, -1), Pair(11, 5), Pair(2, 21),
        Pair(5, -31), Pair(-14, 11), Pair(-2, 15), Pair(8, 36), Pair(0, 18), Pair(21, 1), Pair(-6, 14), Pair(0, 23)
      }
    }},
    {{ // Bucket 38
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-2, 22), Pair(11, 20), Pair(10, 17), Pair(17, 14), Pair(-11, 22), Pair(9, 9), Pair(14, 34), Pair(-75, 54),
        Pair(5, 7), Pair(9, 10), Pair(7, 9), Pair(5, 12), Pair(-4, 4), Pair(-14, 12), Pair(6, 6), Pair(0, 16),
        Pair(0, 5), Pair(6, 1), Pair(-6, 7), Pair(1, 6), Pair(-5, 6), Pair(-3, 8), Pair(0, 0), Pair(3, 15),
        Pair(1, -2), Pair(8, -1), Pair(-1, 2), Pair(-4, 0), Pair(-5, 1), Pair(2, 8), Pair(0, 0), Pair(20, 6),
        Pair(1, -3), Pair(3, -5), Pair(-4, -2), Pair(0, 0), Pair(-3, 2), Pair(-2, 2), Pair(-7, 7), Pair(3, 5),
        Pair(1, -7), Pair(3, -9), Pair(-1, -4), Pair(1, 4), Pair(-1, -4), Pair(2, 0), Pair(1, 2), Pair(1, 4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(68, 69), Pair(2, 68), Pair(-95, 125), Pair(-67, 90), Pair(89, 85), Pair(-113, 86), Pair(19, 62), Pair(10, 16),
        Pair(51, 61), Pair(33, 67), Pair(39, 65), Pair(-15, 81), Pair(24, 66), Pair(47, 76), Pair(-54, 88), Pair(64, 39),
        Pair(30, 71), Pair(41, 58), Pair(43, 62), Pair(23, 66), Pair(24, 58), Pair(-24, 86), Pair(4, 35), Pair(38, 57),
        Pair(47, 40), Pair(32, 65), Pair(13, 71), Pair(10, 53), Pair(18, 72), Pair(16, 68), Pair(0, 0), Pair(-6, 60),
        Pair(20, 67), Pair(25, 58), Pair(30, 56), Pair(12, 70), Pair(5, 63), Pair(-61, 14), Pair(23, 119), Pair(-55, 32),
        Pair(27, 55), Pair(20, 65), Pair(14, 60), Pair(5, 68), Pair(13, 67), Pair(7, 45), Pair(8, 73), Pair(-19, 3),
        Pair(49, 42), Pair(21, 65), Pair(22, 62), Pair(15, 71), Pair(-1, 60), Pair(21, 70), Pair(-3, -2), Pair(31, 90),
        Pair(71, 55), Pair(11, 92), Pair(20, 50), Pair(37, 34), Pair(29, 62), Pair(14, 84), Pair(-2, 77), Pair(-37, 143)
      },
      { // Piece 2
        Pair(15, 100), Pair(-21, 91), Pair(-70, 137), Pair(-92, 104), Pair(-18, 91), Pair(-158, 109), Pair(90, 64), Pair(-10, 81),
        Pair(41, 88), Pair(23, 93), Pair(-35, 100), Pair(-42, 116), Pair(-21, 106), Pair(-16, 86), Pair(-43, 116), Pair(49, 76),
        Pair(12, 82), Pair(5, 92), Pair(9, 98), Pair(-19, 95), Pair(22, 92), Pair(-40, 99), Pair(7, 81), Pair(-98, 47),
        Pair(36, 68), Pair(3, 79), Pair(0, 86), Pair(1, 89), Pair(-6, 75), Pair(-18, 99), Pair(0, 0), Pair(6, 91),
        Pair(14, 93), Pair(21, 75), Pair(8, 80), Pair(-5, 87), Pair(-4, 74), Pair(-68, -10), Pair(25, 113), Pair(-70, -8),
        Pair(8, 78), Pair(30, 64), Pair(11, 74), Pair(3, 75), Pair(-7, 64), Pair(8, 75), Pair(-12, 69), Pair(-3, 84),
        Pair(-13, 84), Pair(11, 75), Pair(18, 75), Pair(0, 60), Pair(12, 69), Pair(-4, 71), Pair(21, 62), Pair(5, 35),
        Pair(40, 53), Pair(12, 67), Pair(1, 54), Pair(19, 61), Pair(14, 73), Pair(12, 86), Pair(-16, 72), Pair(15, 89)
      },
      { // Piece 3
        Pair(5, 107), Pair(-6, 119), Pair(-6, 124), Pair(12, 102), Pair(-1, 108), Pair(-65, 118), Pair(20, 112), Pair(-97, 144),
        Pair(37, 92), Pair(15, 99), Pair(28, 108), Pair(22, 101), Pair(14, 120), Pair(33, 103), Pair(121, 92), Pair(-9, 116),
        Pair(17, 99), Pair(15, 100), Pair(37, 97), Pair(35, 95), Pair(24, 90), Pair(10, 106), Pair(51, 109), Pair(0, 114),
        Pair(31, 97), Pair(26, 93), Pair(16, 90), Pair(15, 94), Pair(54, 86), Pair(18, 93), Pair(0, 0), Pair(-15, 95),
        Pair(27, 84), Pair(16, 94), Pair(16, 89), Pair(10, 91), Pair(24, 75), Pair(-40, 17), Pair(6, 80), Pair(-80, -5),
        Pair(22, 89), Pair(36, 78), Pair(32, 85), Pair(38, 82), Pair(34, 75), Pair(7, 80), Pair(-24, 94), Pair(-18, 70),
        Pair(52, 87), Pair(35, 87), Pair(27, 94), Pair(25, 100), Pair(50, 72), Pair(21, 85), Pair(21, 73), Pair(27, 67),
        Pair(29, 95), Pair(32, 90), Pair(22, 94), Pair(28, 90), Pair(27, 90), Pair(18, 93), Pair(-2, 89), Pair(14, 81)
      },
      { // Piece 4
        Pair(51, 142), Pair(-2, 179), Pair(10, 161), Pair(3, 148), Pair(-4, 186), Pair(27, 187), Pair(58, 169), Pair(53, 162),
        Pair(67, 137), Pair(44, 163), Pair(39, 122), Pair(35, 169), Pair(13, 172), Pair(60, 162), Pair(11, 196), Pair(41, 207),
        Pair(60, 106), Pair(55, 130), Pair(44, 132), Pair(36, 119), Pair(41, 174), Pair(2, 118), Pair(9, 206), Pair(-24, 157),
        Pair(67, 124), Pair(48, 145), Pair(60, 117), Pair(31, 150), Pair(28, 153), Pair(18, 147), Pair(0, 0), Pair(38, 64),
        Pair(45, 126), Pair(26, 163), Pair(30, 135), Pair(28, 147), Pair(26, 128), Pair(11, 19), Pair(40, 100), Pair(13, 55),
        Pair(40, 169), Pair(25, 161), Pair(32, 164), Pair(21, 151), Pair(18, 137), Pair(26, 115), Pair(34, 102), Pair(3, 180),
        Pair(33, 136), Pair(43, 148), Pair(36, 141), Pair(37, 136), Pair(30, 150), Pair(36, 125), Pair(17, 164), Pair(0, 223),
        Pair(17, 180), Pair(46, 120), Pair(40, 115), Pair(41, 130), Pair(34, 150), Pair(41, 139), Pair(79, 76), Pair(59, 112)
      },
      { // Piece 5
        Pair(18, 21), Pair(39, -42), Pair(202, -104), Pair(158, -18), Pair(96, -27), Pair(-57, -75), Pair(-111, -22), Pair(-45, -266),
        Pair(117, -33), Pair(93, -6), Pair(167, -48), Pair(136, -19), Pair(220, -46), Pair(70, 13), Pair(126, -23), Pair(125, -101),
        Pair(95, -24), Pair(16, 1), Pair(22, 6), Pair(79, 2), Pair(55, 3), Pair(64, 23), Pair(111, 0), Pair(118, -5),
        Pair(91, -27), Pair(42, 5), Pair(89, -4), Pair(130, -9), Pair(61, -7), Pair(53, -25), Pair(0, 0), Pair(-13, -25),
        Pair(119, -34), Pair(57, -14), Pair(22, -1), Pair(68, -8), Pair(11, -8), Pair(-140, -17), Pair(-7, -55), Pair(-511, -12),
        Pair(52, -24), Pair(59, -26), Pair(41, -21), Pair(34, -12), Pair(-23, -5), Pair(26, -16), Pair(-7, -17), Pair(-30, -7),
        Pair(-1, -13), Pair(-35, -13), Pair(8, -9), Pair(7, -9), Pair(1, 2), Pair(20, -4), Pair(-16, -5), Pair(-1, -4),
        Pair(-1, -59), Pair(-4, -36), Pair(-6, -17), Pair(-14, 6), Pair(-10, 16), Pair(21, -6), Pair(-8, -4), Pair(-3, -7)
      }
    }},
    {{ // Bucket 39
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-17, 28), Pair(4, 11), Pair(31, 3), Pair(3, 11), Pair(-2, 14), Pair(-10, 15), Pair(-47, 27), Pair(-11, 48),
        Pair(2, 11), Pair(-3, 6), Pair(7, 5), Pair(4, 4), Pair(-6, 9), Pair(-19, 6), Pair(-10, 1), Pair(30, -35),
        Pair(4, -1), Pair(3, 1), Pair(3, 3), Pair(1, -2), Pair(-5, -2), Pair(0, -4), Pair(-13, -5), Pair(0, 0),
        Pair(4, -4), Pair(3, -3), Pair(4, -3), Pair(2, -3), Pair(2, -5), Pair(-1, -2), Pair(-21, -5), Pair(0, 0),
        Pair(2, -4), Pair(0, -9), Pair(2, -4), Pair(-3, -6), Pair(1, -2), Pair(4, -2), Pair(-3, -7), Pair(6, 2),
        Pair(3, -5), Pair(1, -7), Pair(-1, -6), Pair(-1, -15), Pair(1, -9), Pair(5, -1), Pair(0, -8), Pair(4, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-1, 34), Pair(8, 60), Pair(-31, 28), Pair(40, 38), Pair(-2, 61), Pair(-81, 45), Pair(-61, 25), Pair(-84, 70),
        Pair(21, 36), Pair(19, 32), Pair(1, 43), Pair(-12, 55), Pair(44, 39), Pair(3, 56), Pair(28, 57), Pair(-36, 87),
        Pair(46, 20), Pair(24, 35), Pair(3, 48), Pair(28, 36), Pair(34, 49), Pair(-23, 51), Pair(-32, 48), Pair(-31, 45),
        Pair(23, 30), Pair(18, 28), Pair(8, 45), Pair(1, 37), Pair(11, 33), Pair(-5, 62), Pair(-3, 59), Pair(0, 0),
        Pair(17, 29), Pair(24, 31), Pair(10, 34), Pair(6, 48), Pair(9, 43), Pair(7, 50), Pair(-72, -9), Pair(6, 84),
        Pair(12, 46), Pair(14, 37), Pair(16, 31), Pair(1, 46), Pair(3, 26), Pair(9, 42), Pair(4, 45), Pair(21, 45),
        Pair(17, 1), Pair(-1, 53), Pair(2, 31), Pair(12, 38), Pair(17, 48), Pair(6, 20), Pair(25, 23), Pair(7, -1),
        Pair(-5, -31), Pair(10, 50), Pair(24, 42), Pair(22, 25), Pair(10, 44), Pair(5, 29), Pair(12, 51), Pair(27, -9)
      },
      { // Piece 2
        Pair(-16, 84), Pair(-38, 89), Pair(-77, 89), Pair(-68, 88), Pair(-103, 120), Pair(-58, 72), Pair(-48, 97), Pair(7, 53),
        Pair(-15, 69), Pair(-2, 94), Pair(-9, 84), Pair(-42, 107), Pair(-74, 93), Pair(-16, 81), Pair(-74, 76), Pair(43, 84),
        Pair(-9, 83), Pair(-12, 65), Pair(-10, 86), Pair(-11, 68), Pair(6, 76), Pair(-45, 84), Pair(28, 87), Pair(15, 58),
        Pair(0, 53), Pair(7, 73), Pair(-13, 72), Pair(-4, 75), Pair(-10, 68), Pair(-11, 72), Pair(-19, 64), Pair(0, 0),
        Pair(20, 64), Pair(5, 50), Pair(-2, 71), Pair(-11, 48), Pair(0, 70), Pair(-6, 54), Pair(-244, -72), Pair(8, 94),
        Pair(1, 57), Pair(17, 52), Pair(3, 49), Pair(4, 63), Pair(-2, 50), Pair(3, 59), Pair(-12, 58), Pair(18, 64),
        Pair(10, 88), Pair(9, 48), Pair(0, 58), Pair(-3, 50), Pair(4, 56), Pair(-9, 60), Pair(11, 60), Pair(9, 48),
        Pair(-11, 43), Pair(-4, 63), Pair(1, 45), Pair(-5, 71), Pair(0, 51), Pair(9, 68), Pair(-22, 64), Pair(-17, 95)
      },
      { // Piece 3
        Pair(2, 80), Pair(-15, 96), Pair(-24, 100), Pair(-1, 88), Pair(-17, 89), Pair(-42, 92), Pair(-27, 98), Pair(44, 85),
        Pair(24, 73), Pair(15, 84), Pair(12, 79), Pair(5, 80), Pair(12, 81), Pair(42, 87), Pair(46, 66), Pair(105, 76),
        Pair(37, 72), Pair(9, 83), Pair(13, 81), Pair(-5, 86), Pair(28, 70), Pair(13, 81), Pair(-34, 93), Pair(49, 103),
        Pair(22, 76), Pair(7, 82), Pair(14, 79), Pair(19, 71), Pair(4, 80), Pair(6, 84), Pair(30, 81), Pair(0, 0),
        Pair(25, 61), Pair(19, 74), Pair(23, 63), Pair(2, 78), Pair(3, 66), Pair(-16, 78), Pair(-29, -93), Pair(-44, 95),
        Pair(16, 66), Pair(26, 77), Pair(22, 70), Pair(15, 66), Pair(11, 69), Pair(19, 58), Pair(1, 83), Pair(-17, 73),
        Pair(36, 68), Pair(27, 75), Pair(26, 60), Pair(22, 67), Pair(28, 59), Pair(9, 68), Pair(10, 80), Pair(-2, 72),
        Pair(12, 78), Pair(18, 75), Pair(14, 71), Pair(11, 74), Pair(15, 66), Pair(16, 62), Pair(-15, 89), Pair(-10, 81)
      },
      { // Piece 4
        Pair(36, 111), Pair(44, 122), Pair(28, 101), Pair(-14, 123), Pair(11, 139), Pair(84, 96), Pair(59, 86), Pair(79, 98),
        Pair(39, 115), Pair(33, 135), Pair(27, 101), Pair(14, 139), Pair(-2, 148), Pair(-24, 176), Pair(-3, 161), Pair(60, 129),
        Pair(53, 92), Pair(22, 117), Pair(29, 95), Pair(16, 132), Pair(8, 136), Pair(25, 140), Pair(-32, 169), Pair(14, 157),
        Pair(37, 88), Pair(9, 141), Pair(26, 122), Pair(5, 148), Pair(18, 135), Pair(17, 146), Pair(20, 119), Pair(0, 0),
        Pair(23, 109), Pair(27, 109), Pair(17, 101), Pair(19, 112), Pair(20, 118), Pair(25, 97), Pair(7, 69), Pair(6, 76),
        Pair(15, 113), Pair(18, 114), Pair(31, 116), Pair(21, 114), Pair(16, 118), Pair(17, 113), Pair(21, 92), Pair(-23, 114),
        Pair(33, 107), Pair(28, 85), Pair(24, 96), Pair(23, 94), Pair(20, 111), Pair(26, 110), Pair(46, 85), Pair(-6, 139),
        Pair(29, 86), Pair(26, 109), Pair(28, 79), Pair(26, 86), Pair(29, 96), Pair(25, 141), Pair(-5, 122), Pair(-33, 83)
      },
      { // Piece 5
        Pair(99, -12), Pair(167, -48), Pair(294, -61), Pair(-1, -49), Pair(167, -50), Pair(95, -46), Pair(77, -89), Pair(27, 129),
        Pair(165, -22), Pair(123, -8), Pair(69, -23), Pair(-37, 5), Pair(-78, -2), Pair(96, -36), Pair(81, -55), Pair(88, -64),
        Pair(60, -6), Pair(88, -7), Pair(100, -4), Pair(32, -4), Pair(157, -7), Pair(160, -6), Pair(-19, 40), Pair(-26, 4),
        Pair(54, -26), Pair(111, -23), Pair(85, -13), Pair(99, -12), Pair(92, 7), Pair(-17, 13), Pair(12, -37), Pair(0, 0),
        Pair(77, -45), Pair(78, -28), Pair(93, -26), Pair(79, -12), Pair(29, 7), Pair(-19, 7), Pair(-385, 13), Pair(106, -55),
        Pair(67, -13), Pair(46, -28), Pair(20, -12), Pair(29, -3), Pair(9, 7), Pair(-29, 9), Pair(32, 3), Pair(29, 3),
        Pair(2, -9), Pair(-5, -24), Pair(16, -20), Pair(13, -6), Pair(32, 2), Pair(-4, 12), Pair(13, 5), Pair(6, -6),
        Pair(3, -32), Pair(-14, -29), Pair(-5, -7), Pair(26, 4), Pair(-3, 11), Pair(6, 22), Pair(6, 13), Pair(-2, 14)
      }
    }},
    {{ // Bucket 40
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(85, -71), Pair(-25, 16), Pair(-24, 23), Pair(-16, 26), Pair(19, 16), Pair(5, 11), Pair(-11, 42), Pair(-21, 35),
        Pair(0, 0), Pair(-7, 2), Pair(-1, 6), Pair(9, 6), Pair(8, 8), Pair(-6, 20), Pair(0, 23), Pair(-10, 25),
        Pair(-9, -13), Pair(-8, -2), Pair(-8, 3), Pair(0, 1), Pair(-1, 9), Pair(-4, 10), Pair(1, 7), Pair(-5, 13),
        Pair(-6, -7), Pair(-8, -5), Pair(0, 2), Pair(-1, 0), Pair(-3, 3), Pair(-2, 6), Pair(0, 2), Pair(1, 6),
        Pair(0, 0), Pair(-5, 1), Pair(2, 3), Pair(3, 0), Pair(-3, 7), Pair(-6, 3), Pair(-2, 0), Pair(-1, 1),
        Pair(11, -6), Pair(-3, -4), Pair(1, 0), Pair(-2, 0), Pair(-2, -2), Pair(-3, -2), Pair(-4, -2), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(13, 68), Pair(53, 120), Pair(46, 72), Pair(98, 40), Pair(-25, 65), Pair(30, 83), Pair(140, 46), Pair(13, 74),
        Pair(-18, 11), Pair(2, 78), Pair(-21, 49), Pair(13, 75), Pair(26, 60), Pair(55, 44), Pair(-10, 57), Pair(-13, 70),
        Pair(0, 0), Pair(14, 72), Pair(3, 70), Pair(19, 53), Pair(-8, 77), Pair(33, 48), Pair(20, 54), Pair(23, 47),
        Pair(14, 108), Pair(-58, 3), Pair(4, 79), Pair(3, 64), Pair(11, 69), Pair(11, 61), Pair(18, 48), Pair(28, 58),
        Pair(9, 86), Pair(-34, 99), Pair(6, 59), Pair(1, 52), Pair(5, 65), Pair(7, 59), Pair(13, 58), Pair(12, 63),
        Pair(-16, 34), Pair(4, 64), Pair(-8, 56), Pair(2, 65), Pair(2, 58), Pair(6, 59), Pair(13, 57), Pair(30, 41),
        Pair(25, 65), Pair(5, 78), Pair(2, 58), Pair(7, 64), Pair(8, 58), Pair(10, 49), Pair(3, 63), Pair(19, 52),
        Pair(-14, 92), Pair(4, 71), Pair(0, 69), Pair(16, 57), Pair(8, 55), Pair(13, 55), Pair(16, 64), Pair(13, 119)
      },
      { // Piece 2
        Pair(-7, 132), Pair(-51, 100), Pair(-73, 123), Pair(-89, 131), Pair(-61, 106), Pair(-104, 107), Pair(-53, 98), Pair(-87, 105),
        Pair(38, 87), Pair(-13, 121), Pair(4, 108), Pair(-27, 107), Pair(-21, 108), Pair(-14, 105), Pair(20, 100), Pair(7, 88),
        Pair(0, 0), Pair(-7, 100), Pair(-36, 97), Pair(-3, 106), Pair(-22, 125), Pair(-18, 111), Pair(9, 103), Pair(24, 77),
        Pair(32, 106), Pair(-57, -36), Pair(-9, 103), Pair(-11, 95), Pair(-1, 105), Pair(-5, 100), Pair(5, 79), Pair(4, 81),
        Pair(-11, 117), Pair(-32, 90), Pair(-17, 96), Pair(-7, 92), Pair(-9, 84), Pair(-1, 92), Pair(-18, 94), Pair(2, 96),
        Pair(9, 99), Pair(-7, 88), Pair(-1, 91), Pair(-7, 87), Pair(2, 80), Pair(-9, 96), Pair(2, 83), Pair(-5, 89),
        Pair(3, 132), Pair(2, 95), Pair(-5, 98), Pair(2, 88), Pair(-7, 83), Pair(-9, 88), Pair(4, 70), Pair(5, 74),
        Pair(-11, 118), Pair(7, 103), Pair(6, 90), Pair(-11, 97), Pair(2, 72), Pair(-2, 76), Pair(21, 89), Pair(7, 110)
      },
      { // Piece 3
        Pair(14, 142), Pair(-35, 156), Pair(-29, 158), Pair(-28, 142), Pair(-34, 160), Pair(29, 131), Pair(58, 142), Pair(25, 149),
        Pair(32, 158), Pair(-15, 151), Pair(-19, 168), Pair(-9, 160), Pair(-36, 165), Pair(7, 147), Pair(-4, 154), Pair(-18, 152),
        Pair(0, 0), Pair(-16, 167), Pair(-8, 171), Pair(-4, 157), Pair(-42, 171), Pair(-16, 159), Pair(-10, 144), Pair(-14, 149),
        Pair(-15, 153), Pair(-68, -57), Pair(-24, 155), Pair(-30, 151), Pair(-12, 142), Pair(-10, 139), Pair(-6, 139), Pair(13, 136),
        Pair(-25, 133), Pair(-36, 145), Pair(-28, 142), Pair(-21, 137), Pair(-19, 143), Pair(-7, 133), Pair(-6, 125), Pair(-6, 144),
        Pair(-25, 132), Pair(-26, 133), Pair(-20, 136), Pair(-17, 128), Pair(-25, 139), Pair(-9, 124), Pair(0, 124), Pair(14, 123),
        Pair(1, 103), Pair(-17, 132), Pair(-13, 134), Pair(-18, 132), Pair(-19, 137), Pair(-15, 135), Pair(-14, 133), Pair(9, 153),
        Pair(-19, 126), Pair(-18, 129), Pair(-14, 127), Pair(-16, 132), Pair(-15, 130), Pair(-13, 133), Pair(-4, 137), Pair(-6, 146)
      },
      { // Piece 4
        Pair(-40, 330), Pair(-12, 270), Pair(-42, 317), Pair(23, 289), Pair(-36, 332), Pair(-40, 321), Pair(-33, 300), Pair(48, 237),
        Pair(28, 255), Pair(38, 257), Pair(25, 276), Pair(2, 293), Pair(0, 307), Pair(-6, 280), Pair(2, 336), Pair(14, 277),
        Pair(0, 0), Pair(35, 276), Pair(24, 294), Pair(17, 305), Pair(31, 258), Pair(15, 264), Pair(29, 263), Pair(46, 268),
        Pair(24, 268), Pair(22, 30), Pair(12, 268), Pair(29, 259), Pair(14, 276), Pair(14, 274), Pair(37, 263), Pair(43, 227),
        Pair(22, 223), Pair(19, 226), Pair(31, 237), Pair(23, 249), Pair(32, 238), Pair(24, 239), Pair(45, 218), Pair(45, 235),
        Pair(29, 243), Pair(22, 236), Pair(23, 245), Pair(24, 239), Pair(22, 225), Pair(34, 229), Pair(38, 234), Pair(50, 211),
        Pair(31, 232), Pair(30, 211), Pair(27, 219), Pair(23, 231), Pair(32, 222), Pair(32, 220), Pair(36, 218), Pair(12, 240),
        Pair(34, 234), Pair(29, 215), Pair(33, 232), Pair(24, 231), Pair(27, 223), Pair(39, 229), Pair(39, 250), Pair(38, 200)
      },
      { // Piece 5
        Pair(-55, -34), Pair(130, -36), Pair(148, -67), Pair(115, -13), Pair(45, -9), Pair(116, -12), Pair(73, -5), Pair(-67, 5),
        Pair(-3, 102), Pair(-46, 16), Pair(69, -24), Pair(18, 11), Pair(-68, 34), Pair(69, -8), Pair(-54, 24), Pair(-65, 41),
        Pair(0, 0), Pair(-66, -27), Pair(-31, 32), Pair(113, 7), Pair(60, 11), Pair(106, 17), Pair(47, 19), Pair(96, 11),
        Pair(-21, -80), Pair(-135, -68), Pair(-98, 22), Pair(106, 8), Pair(97, 7), Pair(46, 19), Pair(21, 19), Pair(77, -6),
        Pair(58, -25), Pair(-41, -8), Pair(-17, 1), Pair(10, 9), Pair(9, 12), Pair(1, 13), Pair(19, 13), Pair(84, -2),
        Pair(-77, 18), Pair(-32, 0), Pair(-34, 18), Pair(9, 0), Pair(-1, 8), Pair(3, 7), Pair(6, 7), Pair(23, 8),
        Pair(-30, 7), Pair(-16, 4), Pair(2, 15), Pair(6, 8), Pair(20, 6), Pair(17, 1), Pair(-5, 5), Pair(-1, 9),
        Pair(4, -1), Pair(24, 6), Pair(21, 16), Pair(31, 9), Pair(9, -2), Pair(16, 4), Pair(-3, 1), Pair(2, 1)
      }
    }},
    {{ // Bucket 41
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-16, 34), Pair(-33, 34), Pair(-15, 11), Pair(-15, 18), Pair(21, 19), Pair(38, 14), Pair(16, 23), Pair(-25, 29),
        Pair(4, 9), Pair(0, 0), Pair(3, -1), Pair(-5, 8), Pair(8, 16), Pair(9, 19), Pair(12, 14), Pair(-8, 26),
        Pair(12, 3), Pair(-13, -15), Pair(-5, 29), Pair(-2, 6), Pair(2, 7), Pair(-2, 10), Pair(-1, 12), Pair(-2, 15),
        Pair(8, 3), Pair(-6, -6), Pair(5, 10), Pair(-6, 7), Pair(-2, 4), Pair(-5, 8), Pair(-1, 4), Pair(-2, 6),
        Pair(2, 2), Pair(0, 0), Pair(-1, 4), Pair(-2, 3), Pair(-3, 6), Pair(-8, 3), Pair(-4, 4), Pair(-4, 4),
        Pair(-1, -3), Pair(2, 1), Pair(-2, -1), Pair(-6, 7), Pair(-3, 1), Pair(-9, 0), Pair(-10, -2), Pair(-2, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-61, 101), Pair(-52, 91), Pair(-3, 110), Pair(47, 61), Pair(2, 107), Pair(86, 58), Pair(-3, 53), Pair(19, 107),
        Pair(3, 86), Pair(-19, -2), Pair(11, 71), Pair(-5, 47), Pair(21, 86), Pair(24, 95), Pair(-49, 70), Pair(-4, 80),
        Pair(-27, 45), Pair(0, 0), Pair(-23, 74), Pair(-10, 91), Pair(-4, 60), Pair(-35, 96), Pair(32, 62), Pair(25, 52),
        Pair(-45, 76), Pair(-5, 113), Pair(-138, 11), Pair(-5, 75), Pair(-2, 69), Pair(1, 82), Pair(5, 73), Pair(1, 71),
        Pair(-29, 46), Pair(-5, 92), Pair(-32, 71), Pair(-9, 79), Pair(-7, 60), Pair(-6, 73), Pair(7, 62), Pair(13, 64),
        Pair(0, 77), Pair(-22, 29), Pair(-7, 81), Pair(-29, 66), Pair(-5, 75), Pair(-4, 68), Pair(3, 72), Pair(10, 63),
        Pair(16, 66), Pair(-12, 74), Pair(5, 66), Pair(-5, 65), Pair(-4, 73), Pair(0, 65), Pair(9, 70), Pair(9, 77),
        Pair(44, 99), Pair(3, 90), Pair(13, 53), Pair(6, 86), Pair(0, 75), Pair(-1, 72), Pair(3, 70), Pair(-7, 116)
      },
      { // Piece 2
        Pair(-7, 77), Pair(-13, 99), Pair(-99, 111), Pair(-38, 93), Pair(-101, 123), Pair(-82, 103), Pair(-35, 112), Pair(-57, 148),
        Pair(-167, 9), Pair(-77, 116), Pair(-12, 102), Pair(-50, 110), Pair(-43, 106), Pair(-17, 128), Pair(-21, 115), Pair(3, 110),
        Pair(-11, 100), Pair(0, 0), Pair(-33, 100), Pair(-24, 97), Pair(12, 103), Pair(-11, 100), Pair(-40, 128), Pair(-2, 84),
        Pair(-99, -18), Pair(-12, 121), Pair(-194, -56), Pair(-19, 104), Pair(-10, 100), Pair(-18, 112), Pair(-11, 95), Pair(7, 91),
        Pair(-28, 93), Pair(-31, 79), Pair(-31, 104), Pair(-31, 86), Pair(-13, 88), Pair(-10, 85), Pair(-13, 91), Pair(7, 75),
        Pair(-13, 74), Pair(-10, 91), Pair(-19, 79), Pair(-16, 95), Pair(-16, 67), Pair(-10, 85), Pair(-7, 79), Pair(-4, 97),
        Pair(4, 96), Pair(-1, 85), Pair(-6, 92), Pair(-11, 69), Pair(-11, 85), Pair(-13, 68), Pair(-3, 78), Pair(-4, 60),
        Pair(-6, 101), Pair(2, 95), Pair(-5, 81), Pair(-9, 85), Pair(-15, 86), Pair(-2, 84), Pair(-4, 54), Pair(-7, 99)
      },
      { // Piece 3
        Pair(-26, 117), Pair(-18, 126), Pair(-27, 139), Pair(-30, 119), Pair(12, 120), Pair(-9, 128), Pair(-54, 140), Pair(29, 129),
        Pair(-30, 129), Pair(26, 120), Pair(-22, 127), Pair(-22, 136), Pair(-2, 124), Pair(3, 125), Pair(27, 117), Pair(-23, 142),
        Pair(-37, 118), Pair(0, 0), Pair(-14, 134), Pair(-4, 124), Pair(-11, 127), Pair(1, 123), Pair(-3, 121), Pair(8, 128),
        Pair(-73, -33), Pair(-33, 108), Pair(-44, -78), Pair(-24, 121), Pair(-24, 122), Pair(-16, 108), Pair(4, 116), Pair(-9, 108),
        Pair(-31, 95), Pair(-30, 108), Pair(-43, 110), Pair(-22, 106), Pair(-15, 100), Pair(-15, 118), Pair(0, 96), Pair(11, 105),
        Pair(-30, 113), Pair(-27, 100), Pair(-24, 109), Pair(-13, 103), Pair(-23, 121), Pair(-5, 105), Pair(-8, 109), Pair(-4, 110),
        Pair(-30, 101), Pair(-26, 96), Pair(-32, 102), Pair(-9, 103), Pair(-24, 114), Pair(-17, 110), Pair(0, 106), Pair(1, 118),
        Pair(-25, 112), Pair(-26, 100), Pair(-28, 108), Pair(-22, 114), Pair(-22, 117), Pair(-19, 119), Pair(-6, 118), Pair(-10, 130)
      },
      { // Piece 4
        Pair(21, 180), Pair(-8, 198), Pair(-12, 221), Pair(31, 184), Pair(-22, 237), Pair(-46, 210), Pair(-66, 282), Pair(34, 189),
        Pair(31, 140), Pair(10, 203), Pair(31, 176), Pair(26, 209), Pair(28, 214), Pair(28, 198), Pair(-15, 219), Pair(29, 205),
        Pair(41, 115), Pair(0, 0), Pair(25, 194), Pair(24, 188), Pair(49, 179), Pair(7, 220), Pair(30, 190), Pair(42, 188),
        Pair(-8, 181), Pair(33, 160), Pair(-12, 154), Pair(27, 172), Pair(40, 174), Pair(28, 190), Pair(47, 182), Pair(34, 190),
        Pair(19, 177), Pair(13, 177), Pair(18, 161), Pair(26, 162), Pair(24, 180), Pair(29, 185), Pair(37, 177), Pair(42, 180),
        Pair(22, 194), Pair(25, 178), Pair(20, 148), Pair(18, 176), Pair(29, 160), Pair(24, 173), Pair(33, 186), Pair(28, 204),
        Pair(40, 178), Pair(23, 171), Pair(21, 167), Pair(24, 166), Pair(24, 166), Pair(32, 168), Pair(36, 175), Pair(49, 138),
        Pair(37, 160), Pair(29, 177), Pair(20, 174), Pair(25, 177), Pair(25, 175), Pair(19, 159), Pair(62, 109), Pair(56, 153)
      },
      { // Piece 5
        Pair(79, -268), Pair(-7, -71), Pair(2, -17), Pair(4, 16), Pair(135, 1), Pair(12, 29), Pair(-30, 64), Pair(161, -35),
        Pair(177, -68), Pair(86, -64), Pair(120, -39), Pair(119, -21), Pair(-275, 85), Pair(125, -3), Pair(-33, 35), Pair(37, -6),
        Pair(66, -49), Pair(0, 0), Pair(-56, -20), Pair(127, -15), Pair(53, 3), Pair(76, 9), Pair(38, 8), Pair(24, 24),
        Pair(18, 27), Pair(57, -88), Pair(12, 17), Pair(48, -3), Pair(53, 4), Pair(39, 14), Pair(-1, 19), Pair(136, -24),
        Pair(65, -56), Pair(-41, -64), Pair(18, -29), Pair(-2, -15), Pair(15, -2), Pair(22, 6), Pair(-16, 15), Pair(34, 0),
        Pair(52, -26), Pair(-5, -37), Pair(9, -17), Pair(-7, 0), Pair(3, -5), Pair(-16, 3), Pair(10, -1), Pair(26, -1),
        Pair(-4, -25), Pair(7, -24), Pair(-2, -9), Pair(2, 5), Pair(21, -4), Pair(-5, 3), Pair(2, -2), Pair(-2, 1),
        Pair(33, -24), Pair(21, -16), Pair(32, -21), Pair(9, 3), Pair(2, 11), Pair(21, -4), Pair(-1, -3), Pair(-1, -10)
      }
    }},
    {{ // Bucket 42
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-15, 33), Pair(-38, 23), Pair(-39, 5), Pair(6, 2), Pair(38, -8), Pair(26, 13), Pair(-8, 32), Pair(-50, 45),
        Pair(5, 7), Pair(-12, 8), Pair(0, 0), Pair(5, 4), Pair(10, 4), Pair(3, 10), Pair(-1, 20), Pair(-4, 20),
        Pair(-2, -1), Pair(-4, 8), Pair(-8, -18), Pair(1, 41), Pair(1, 4), Pair(2, 11), Pair(0, 10), Pair(0, 16),
        Pair(4, 0), Pair(5, -7), Pair(-4, -4), Pair(0, 4), Pair(0, 2), Pair(2, 5), Pair(3, 2), Pair(-3, 6),
        Pair(2, 4), Pair(-1, -5), Pair(0, 0), Pair(2, 4), Pair(-2, 3), Pair(-5, 2), Pair(-1, 3), Pair(-3, -2),
        Pair(1, -2), Pair(-4, -9), Pair(4, -2), Pair(-6, 4), Pair(1, -1), Pair(-5, -2), Pair(-1, 2), Pair(-3, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(1, 52), Pair(65, 74), Pair(-22, 109), Pair(-33, 101), Pair(13, 49), Pair(-1, 95), Pair(132, -21), Pair(41, -34),
        Pair(-43, -25), Pair(-17, 92), Pair(12, 4), Pair(11, 86), Pair(40, 23), Pair(30, 51), Pair(9, 72), Pair(38, 60),
        Pair(44, 90), Pair(-20, 63), Pair(0, 0), Pair(5, 67), Pair(6, 78), Pair(-13, 55), Pair(27, 59), Pair(12, 45),
        Pair(6, 91), Pair(-49, -11), Pair(9, 113), Pair(-96, -42), Pair(13, 66), Pair(1, 68), Pair(20, 66), Pair(26, 40),
        Pair(8, 75), Pair(-28, 88), Pair(4, 88), Pair(-16, 55), Pair(7, 70), Pair(-3, 44), Pair(16, 68), Pair(17, 69),
        Pair(-4, 45), Pair(3, 91), Pair(-13, 32), Pair(-1, 74), Pair(-12, 52), Pair(9, 71), Pair(11, 62), Pair(16, 76),
        Pair(3, 65), Pair(14, 87), Pair(0, 62), Pair(12, 74), Pair(10, 56), Pair(10, 61), Pair(9, 77), Pair(30, 36),
        Pair(87, 43), Pair(9, 70), Pair(33, 48), Pair(17, 57), Pair(2, 80), Pair(17, 84), Pair(8, 65), Pair(27, 58)
      },
      { // Piece 2
        Pair(-120, -39), Pair(-44, 107), Pair(-40, 69), Pair(-30, 101), Pair(-39, 72), Pair(-62, 89), Pair(-25, 67), Pair(2, 103),
        Pair(-5, 114), Pair(-64, 59), Pair(9, 93), Pair(-15, 85), Pair(27, 86), Pair(-52, 108), Pair(-13, 78), Pair(-21, 107),
        Pair(-39, 70), Pair(-10, 86), Pair(0, 0), Pair(9, 90), Pair(-12, 77), Pair(-13, 101), Pair(7, 97), Pair(13, 79),
        Pair(4, 68), Pair(-55, -8), Pair(10, 113), Pair(-150, -175), Pair(-1, 75), Pair(-14, 85), Pair(0, 82), Pair(9, 59),
        Pair(-7, 31), Pair(-5, 77), Pair(-15, 53), Pair(-24, 80), Pair(-12, 43), Pair(9, 75), Pair(-11, 75), Pair(12, 47),
        Pair(12, 60), Pair(-17, 65), Pair(12, 77), Pair(-7, 55), Pair(9, 72), Pair(-3, 38), Pair(11, 83), Pair(10, 55),
        Pair(-3, 71), Pair(17, 65), Pair(11, 61), Pair(13, 69), Pair(-4, 58), Pair(16, 55), Pair(-5, 32), Pair(23, 72),
        Pair(10, 84), Pair(13, 56), Pair(16, 78), Pair(-5, 67), Pair(10, 74), Pair(-4, 65), Pair(25, 82), Pair(-5, 43)
      },
      { // Piece 3
        Pair(7, 86), Pair(14, 93), Pair(71, 57), Pair(-9, 85), Pair(39, 81), Pair(37, 89), Pair(-20, 97), Pair(6, 99),
        Pair(-3, 96), Pair(0, 80), Pair(-7, 107), Pair(-5, 90), Pair(18, 102), Pair(2, 101), Pair(-14, 107), Pair(5, 100),
        Pair(3, 94), Pair(-24, 100), Pair(0, 0), Pair(9, 78), Pair(38, 85), Pair(21, 81), Pair(-10, 99), Pair(-9, 88),
        Pair(-8, 76), Pair(47, -110), Pair(-8, 88), Pair(-46, -78), Pair(-16, 93), Pair(13, 71), Pair(1, 66), Pair(7, 82),
        Pair(14, 69), Pair(-10, 69), Pair(-17, 86), Pair(-11, 74), Pair(-9, 84), Pair(0, 83), Pair(4, 84), Pair(22, 76),
        Pair(3, 74), Pair(-5, 68), Pair(-10, 84), Pair(-20, 76), Pair(-7, 89), Pair(3, 64), Pair(-8, 91), Pair(2, 90),
        Pair(23, 81), Pair(3, 80), Pair(-7, 75), Pair(-9, 71), Pair(-2, 80), Pair(5, 84), Pair(21, 75), Pair(3, 88),
        Pair(-4, 86), Pair(-6, 81), Pair(-7, 77), Pair(-10, 78), Pair(-3, 83), Pair(-1, 88), Pair(9, 84), Pair(13, 85)
      },
      { // Piece 4
        Pair(38, 155), Pair(6, 202), Pair(46, 152), Pair(-24, 233), Pair(28, 163), Pair(1, 180), Pair(-42, 240), Pair(-6, 183),
        Pair(35, 162), Pair(21, 143), Pair(51, 153), Pair(21, 164), Pair(33, 211), Pair(47, 172), Pair(-26, 161), Pair(-7, 177),
        Pair(32, 138), Pair(21, 167), Pair(0, 0), Pair(32, 141), Pair(34, 192), Pair(16, 180), Pair(-2, 211), Pair(35, 168),
        Pair(27, 164), Pair(2, 150), Pair(50, 141), Pair(-11, 137), Pair(7, 183), Pair(29, 170), Pair(21, 158), Pair(12, 188),
        Pair(23, 142), Pair(12, 168), Pair(30, 119), Pair(8, 154), Pair(18, 125), Pair(29, 168), Pair(26, 145), Pair(23, 159),
        Pair(23, 179), Pair(17, 156), Pair(37, 143), Pair(19, 156), Pair(27, 136), Pair(22, 145), Pair(26, 147), Pair(24, 169),
        Pair(14, 152), Pair(30, 145), Pair(31, 142), Pair(21, 148), Pair(23, 154), Pair(21, 153), Pair(24, 132), Pair(39, 137),
        Pair(20, 159), Pair(6, 171), Pair(32, 130), Pair(22, 145), Pair(21, 156), Pair(30, 166), Pair(-15, 229), Pair(20, 162)
      },
      { // Piece 5
        Pair(-7, 31), Pair(-12, -42), Pair(-160, -74), Pair(36, -68), Pair(66, -31), Pair(-42, 37), Pair(-26, -32), Pair(164, 9),
        Pair(120, -58), Pair(124, -60), Pair(126, -38), Pair(117, -10), Pair(-7, 10), Pair(36, 32), Pair(83, 22), Pair(-115, 53),
        Pair(-174, 11), Pair(28, -55), Pair(0, 0), Pair(117, -62), Pair(125, -4), Pair(18, 34), Pair(-17, 51), Pair(-84, 45),
        Pair(26, -32), Pair(-4, 42), Pair(-57, -56), Pair(-11, -57), Pair(-70, 19), Pair(41, 15), Pair(65, 18), Pair(52, 4),
        Pair(6, -34), Pair(22, -11), Pair(69, -49), Pair(96, -34), Pair(10, -6), Pair(-31, 24), Pair(19, 15), Pair(1, 9),
        Pair(15, -1), Pair(-15, 5), Pair(-42, -7), Pair(7, -8), Pair(-23, 11), Pair(-5, 10), Pair(-25, 16), Pair(26, 11),
        Pair(-13, 13), Pair(-4, -1), Pair(12, -8), Pair(8, -2), Pair(-1, 15), Pair(11, 17), Pair(4, 14), Pair(1, 11),
        Pair(-2, 34), Pair(0, 7), Pair(-1, 18), Pair(3, 14), Pair(-4, 24), Pair(10, 15), Pair(-3, 14), Pair(7, 8)
      }
    }},
    {{ // Bucket 43
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-11, 24), Pair(16, 20), Pair(1, 10), Pair(-32, -16), Pair(-43, 18), Pair(-9, 7), Pair(32, 20), Pair(-5, 28),
        Pair(-1, 18), Pair(7, 3), Pair(-11, 8), Pair(0, 0), Pair(-3, -5), Pair(11, 0), Pair(-4, 12), Pair(-10, 27),
        Pair(-6, 6), Pair(-5, 6), Pair(-5, 11), Pair(-11, -16), Pair(-9, 19), Pair(1, 8), Pair(2, 9), Pair(-3, 10),
        Pair(-2, 3), Pair(-2, -2), Pair(4, 0), Pair(-6, -8), Pair(1, -2), Pair(0, 4), Pair(3, 2), Pair(-1, 6),
        Pair(2, 0), Pair(1, -3), Pair(-2, -5), Pair(0, 0), Pair(-2, 0), Pair(-5, 3), Pair(-4, 4), Pair(0, 4),
        Pair(1, -4), Pair(-4, -1), Pair(-6, -9), Pair(1, -4), Pair(1, -1), Pair(0, 1), Pair(-2, -1), Pair(-3, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-34, 89), Pair(37, 54), Pair(-49, 90), Pair(-9, 91), Pair(-96, 98), Pair(-103, 63), Pair(-94, 100), Pair(26, 34),
        Pair(-26, 103), Pair(-33, -1), Pair(4, 72), Pair(-24, -6), Pair(-63, 103), Pair(-40, 33), Pair(-59, 86), Pair(-19, 89),
        Pair(-9, 34), Pair(-9, 83), Pair(-41, 61), Pair(0, 0), Pair(-6, 71), Pair(-68, 100), Pair(-11, 54), Pair(3, 68),
        Pair(-3, 59), Pair(-1, 54), Pair(-188, 17), Pair(-7, 111), Pair(-125, -37), Pair(-22, 82), Pair(-14, 60), Pair(14, 20),
        Pair(-12, 23), Pair(9, 56), Pair(-31, 41), Pair(-8, 80), Pair(-24, 51), Pair(-9, 67), Pair(-19, 45), Pair(-7, 73),
        Pair(5, 51), Pair(-17, 36), Pair(-6, 63), Pair(-37, 17), Pair(-16, 66), Pair(-20, 35), Pair(-4, 77), Pair(-6, 70),
        Pair(6, 83), Pair(-7, 48), Pair(13, 58), Pair(-9, 52), Pair(-4, 62), Pair(-8, 35), Pair(1, 59), Pair(3, 51),
        Pair(53, 84), Pair(4, 67), Pair(18, 49), Pair(10, 38), Pair(-1, 53), Pair(-2, 45), Pair(-5, 55), Pair(-35, 117)
      },
      { // Piece 2
        Pair(-59, 94), Pair(-31, 62), Pair(-87, 105), Pair(38, 29), Pair(-77, 98), Pair(-59, 27), Pair(-1, 73), Pair(-22, 57),
        Pair(-11, 56), Pair(-13, 83), Pair(-99, 58), Pair(-106, 126), Pair(-31, 44), Pair(16, 72), Pair(-4, 67), Pair(-18, 68),
        Pair(-14, 83), Pair(-27, 60), Pair(-36, 77), Pair(0, 0), Pair(-37, 98), Pair(-46, 57), Pair(-14, 87), Pair(9, 55),
        Pair(-11, 53), Pair(-25, 81), Pair(-147, -230), Pair(-3, 102), Pair(-181, -326), Pair(-3, 73), Pair(-11, 61), Pair(-17, 72),
        Pair(-20, 73), Pair(-12, 34), Pair(-34, 75), Pair(-17, 37), Pair(-22, 62), Pair(-15, 33), Pair(-14, 80), Pair(-8, 57),
        Pair(-5, 22), Pair(-22, 62), Pair(-19, 47), Pair(-10, 64), Pair(-11, 42), Pair(-13, 69), Pair(-24, 23), Pair(-2, 63),
        Pair(-25, 75), Pair(-11, 42), Pair(-9, 71), Pair(-8, 55), Pair(-11, 60), Pair(-21, 45), Pair(-6, 54), Pair(-22, 17),
        Pair(-26, 65), Pair(-2, 65), Pair(-3, 50), Pair(-11, 65), Pair(-6, 63), Pair(0, 69), Pair(-24, 33), Pair(-7, 61)
      },
      { // Piece 3
        Pair(-4, 81), Pair(13, 65), Pair(-40, 79), Pair(81, 50), Pair(-25, 86), Pair(-33, 90), Pair(-12, 73), Pair(4, 82),
        Pair(-6, 78), Pair(-2, 76), Pair(-34, 77), Pair(-51, 91), Pair(-36, 75), Pair(22, 76), Pair(36, 63), Pair(-35, 95),
        Pair(-19, 62), Pair(-28, 77), Pair(-34, 66), Pair(0, 0), Pair(-12, 61), Pair(30, 57), Pair(-25, 83), Pair(14, 56),
        Pair(-20, 70), Pair(-28, 62), Pair(-62, -149), Pair(-3, 60), Pair(-157, -4), Pair(-26, 63), Pair(-20, 58), Pair(-28, 66),
        Pair(-24, 77), Pair(-19, 71), Pair(-27, 70), Pair(-15, 51), Pair(-29, 69), Pair(-27, 72), Pair(-15, 68), Pair(2, 70),
        Pair(-10, 70), Pair(-7, 60), Pair(-20, 65), Pair(-13, 62), Pair(-25, 66), Pair(-4, 72), Pair(-21, 76), Pair(1, 63),
        Pair(4, 51), Pair(-8, 74), Pair(-19, 61), Pair(-4, 51), Pair(-15, 54), Pair(-8, 58), Pair(-16, 93), Pair(13, 75),
        Pair(-14, 70), Pair(-15, 67), Pair(-17, 65), Pair(-22, 66), Pair(-18, 62), Pair(-12, 69), Pair(-10, 78), Pair(3, 68)
      },
      { // Piece 4
        Pair(7, 150), Pair(-4, 103), Pair(14, 138), Pair(-15, 139), Pair(4, 164), Pair(-76, 207), Pair(36, 156), Pair(27, 92),
        Pair(35, 108), Pair(23, 157), Pair(-14, 83), Pair(8, 129), Pair(-34, 157), Pair(55, 143), Pair(12, 186), Pair(22, 160),
        Pair(20, 141), Pair(17, 104), Pair(0, 140), Pair(0, 0), Pair(6, 115), Pair(16, 132), Pair(4, 127), Pair(37, 123),
        Pair(29, 99), Pair(15, 109), Pair(6, -110), Pair(39, 93), Pair(13, -8), Pair(10, 154), Pair(16, 148), Pair(21, 139),
        Pair(14, 142), Pair(15, 127), Pair(4, 125), Pair(27, 84), Pair(-2, 130), Pair(20, 79), Pair(12, 147), Pair(6, 151),
        Pair(17, 122), Pair(12, 136), Pair(11, 101), Pair(24, 118), Pair(4, 113), Pair(-3, 141), Pair(22, 111), Pair(17, 145),
        Pair(4, 158), Pair(10, 143), Pair(15, 109), Pair(20, 125), Pair(9, 118), Pair(8, 120), Pair(6, 145), Pair(49, 41),
        Pair(9, 119), Pair(25, 127), Pair(4, 142), Pair(21, 121), Pair(12, 115), Pair(24, 130), Pair(-3, 113), Pair(77, 9)
      },
      { // Piece 5
        Pair(42, -43), Pair(-88, -36), Pair(-23, -132), Pair(57, -102), Pair(83, -27), Pair(-3, 16), Pair(-4, 15), Pair(27, -87),
        Pair(34, 53), Pair(-16, 12), Pair(285, -55), Pair(-113, -19), Pair(-2, 11), Pair(21, 9), Pair(118, -9), Pair(164, -76),
        Pair(80, 18), Pair(-52, -14), Pair(116, -70), Pair(0, 0), Pair(155, -62), Pair(28, 14), Pair(29, 18), Pair(108, 21),
        Pair(100, -1), Pair(127, 10), Pair(-8, -114), Pair(100, -73), Pair(12, 35), Pair(10, 15), Pair(53, 3), Pair(87, 10),
        Pair(-15, 18), Pair(83, -35), Pair(92, -30), Pair(73, -59), Pair(52, -32), Pair(20, -10), Pair(-17, 18), Pair(49, -3),
        Pair(-27, 15), Pair(21, 8), Pair(22, -18), Pair(-4, -30), Pair(15, -16), Pair(4, 9), Pair(26, 6), Pair(47, 0),
        Pair(-30, 36), Pair(-3, 19), Pair(-21, 4), Pair(20, -22), Pair(17, -12), Pair(17, 14), Pair(3, 13), Pair(10, 16),
        Pair(-16, 29), Pair(-15, 29), Pair(-8, -5), Pair(25, -4), Pair(-2, 12), Pair(-1, 17), Pair(1, 25), Pair(5, 16)
      }
    }},
    {{ // Bucket 44
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-11, 19), Pair(9, 15), Pair(1, 11), Pair(-8, 9), Pair(-8, 26), Pair(11, 13), Pair(-14, 25), Pair(-20, 29),
        Pair(8, 5), Pair(5, 6), Pair(-1, 4), Pair(-5, 1), Pair(0, 0), Pair(-6, 9), Pair(7, 7), Pair(-6, 17),
        Pair(2, 2), Pair(0, 3), Pair(6, -2), Pair(4, 20), Pair(-6, -6), Pair(-1, 4), Pair(1, 5), Pair(1, 11),
        Pair(5, -4), Pair(6, 1), Pair(3, 0), Pair(6, 4), Pair(1, -2), Pair(-1, 1), Pair(5, 1), Pair(2, 5),
        Pair(5, -1), Pair(6, -2), Pair(1, -1), Pair(4, -1), Pair(0, 0), Pair(-2, 1), Pair(-4, 4), Pair(-1, 2),
        Pair(4, -1), Pair(3, 0), Pair(1, 0), Pair(-1, -2), Pair(3, 1), Pair(-2, -3), Pair(-9, 0), Pair(0, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-20, 62), Pair(-80, 47), Pair(-6, 63), Pair(-62, 70), Pair(10, 33), Pair(-85, 60), Pair(-100, 91), Pair(19, 34),
        Pair(-16, 59), Pair(-17, 58), Pair(-18, 14), Pair(-40, 65), Pair(-45, 36), Pair(-84, 94), Pair(-9, 5), Pair(-52, 112),
        Pair(-7, 56), Pair(-15, 30), Pair(-21, 66), Pair(-32, 56), Pair(0, 0), Pair(-42, 64), Pair(-22, 59), Pair(-21, 70),
        Pair(-1, 53), Pair(-19, 51), Pair(4, 51), Pair(-158, -74), Pair(-6, 91), Pair(-176, 50), Pair(-10, 51), Pair(-17, 38),
        Pair(-8, 52), Pair(-20, 26), Pair(-13, 59), Pair(-37, 40), Pair(-18, 61), Pair(-33, 8), Pair(-16, 69), Pair(-19, 23),
        Pair(-5, 53), Pair(-10, 48), Pair(-22, 30), Pair(-16, 65), Pair(-33, 17), Pair(-12, 61), Pair(-26, 33), Pair(-4, 50),
        Pair(-13, 51), Pair(13, 63), Pair(-8, 31), Pair(-5, 57), Pair(-17, 43), Pair(-28, 60), Pair(-18, 59), Pair(-3, 54),
        Pair(-1, 85), Pair(-3, 64), Pair(6, 43), Pair(2, 42), Pair(6, 44), Pair(-1, 47), Pair(-6, 65), Pair(-35, 16)
      },
      { // Piece 2
        Pair(-55, 66), Pair(10, 58), Pair(-34, 45), Pair(-42, 86), Pair(-28, 74), Pair(-75, 86), Pair(-49, 22), Pair(0, 82),
        Pair(10, 55), Pair(-53, 52), Pair(9, 78), Pair(-123, 89), Pair(-38, 93), Pair(-88, 39), Pair(-27, 77), Pair(-24, 51),
        Pair(-36, 48), Pair(-1, 82), Pair(-50, 51), Pair(-13, 74), Pair(0, 0), Pair(-22, 81), Pair(-40, 67), Pair(1, 56),
        Pair(-6, 77), Pair(-31, 57), Pair(-6, 68), Pair(-236, -233), Pair(-2, 93), Pair(-229, -160), Pair(-17, 63), Pair(-18, 52),
        Pair(-29, 62), Pair(-1, 56), Pair(-41, 35), Pair(-38, 52), Pair(-36, 38), Pair(-14, 55), Pair(-34, 36), Pair(-16, 70),
        Pair(6, 64), Pair(-43, 38), Pair(-16, 61), Pair(-25, 42), Pair(-7, 55), Pair(-29, 38), Pair(-16, 60), Pair(-28, 15),
        Pair(-35, 68), Pair(-2, 54), Pair(-19, 48), Pair(-3, 58), Pair(-21, 43), Pair(-6, 54), Pair(-34, 31), Pair(-10, 48),
        Pair(-8, 51), Pair(-18, 48), Pair(3, 67), Pair(-21, 41), Pair(-1, 61), Pair(-18, 40), Pair(-9, 55), Pair(-28, 60)
      },
      { // Piece 3
        Pair(-27, 79), Pair(-27, 80), Pair(2, 69), Pair(-15, 68), Pair(78, 45), Pair(-42, 73), Pair(-7, 68), Pair(18, 64),
        Pair(4, 60), Pair(-10, 75), Pair(-6, 71), Pair(-24, 73), Pair(-35, 80), Pair(-52, 66), Pair(-6, 64), Pair(-23, 68),
        Pair(-4, 58), Pair(-14, 69), Pair(-2, 55), Pair(-30, 63), Pair(0, 0), Pair(12, 51), Pair(-7, 68), Pair(-39, 59),
        Pair(2, 54), Pair(-28, 64), Pair(-16, 65), Pair(-149, -75), Pair(7, 35), Pair(-31, -126), Pair(-6, 49), Pair(-34, 59),
        Pair(-5, 59), Pair(-18, 74), Pair(-7, 60), Pair(-16, 55), Pair(-11, 42), Pair(-40, 60), Pair(-7, 55), Pair(-3, 57),
        Pair(-4, 62), Pair(-12, 63), Pair(-19, 69), Pair(-11, 48), Pair(-13, 46), Pair(-7, 45), Pair(-2, 55), Pair(-15, 55),
        Pair(10, 50), Pair(-2, 62), Pair(-11, 58), Pair(-9, 43), Pair(-18, 49), Pair(-12, 53), Pair(-14, 73), Pair(2, 23),
        Pair(-8, 61), Pair(-9, 63), Pair(-8, 64), Pair(-17, 52), Pair(-9, 48), Pair(-12, 60), Pair(-9, 57), Pair(-5, 62)
      },
      { // Piece 4
        Pair(9, 117), Pair(7, 160), Pair(31, 85), Pair(13, 139), Pair(61, 92), Pair(73, 121), Pair(27, 115), Pair(-23, 187),
        Pair(38, 123), Pair(19, 134), Pair(16, 147), Pair(-15, 112), Pair(-2, 128), Pair(9, 99), Pair(10, 166), Pair(33, 136),
        Pair(38, 116), Pair(15, 107), Pair(19, 92), Pair(14, 86), Pair(0, 0), Pair(12, 111), Pair(-6, 135), Pair(31, 102),
        Pair(34, 84), Pair(16, 109), Pair(9, 104), Pair(-32, -36), Pair(49, 76), Pair(69, -52), Pair(21, 105), Pair(27, 124),
        Pair(19, 129), Pair(25, 106), Pair(15, 117), Pair(16, 103), Pair(28, 77), Pair(15, 124), Pair(16, 82), Pair(15, 133),
        Pair(18, 132), Pair(17, 103), Pair(5, 125), Pair(11, 106), Pair(27, 105), Pair(18, 90), Pair(18, 102), Pair(18, 84),
        Pair(22, 99), Pair(10, 119), Pair(13, 110), Pair(11, 109), Pair(29, 94), Pair(11, 116), Pair(-1, 134), Pair(31, 126),
        Pair(15, 123), Pair(18, 124), Pair(19, 107), Pair(17, 106), Pair(24, 110), Pair(25, 112), Pair(10, 123), Pair(12, 131)
      },
      { // Piece 5
        Pair(-5, 28), Pair(66, -4), Pair(125, -34), Pair(138, -86), Pair(150, -56), Pair(-76, -61), Pair(-110, -18), Pair(7, 25),
        Pair(158, 0), Pair(103, 19), Pair(-6, -5), Pair(82, -21), Pair(87, -41), Pair(145, -36), Pair(-2, -10), Pair(-212, 46),
        Pair(6, 6), Pair(118, -6), Pair(69, 2), Pair(103, -82), Pair(0, 0), Pair(97, -58), Pair(3, 7), Pair(40, -4),
        Pair(105, 16), Pair(97, 2), Pair(36, -5), Pair(-5, 89), Pair(-8, -60), Pair(-1, -13), Pair(22, 6), Pair(61, -2),
        Pair(46, 1), Pair(16, 15), Pair(-16, 1), Pair(86, -32), Pair(23, -34), Pair(87, -38), Pair(23, -5), Pair(21, 4),
        Pair(69, 5), Pair(29, -10), Pair(5, 14), Pair(18, -9), Pair(24, -24), Pair(25, -6), Pair(4, 15), Pair(13, 10),
        Pair(6, 34), Pair(0, 20), Pair(15, 22), Pair(9, 4), Pair(16, 0), Pair(13, 7), Pair(2, 22), Pair(0, 21),
        Pair(-10, 13), Pair(-6, 26), Pair(-6, 31), Pair(30, 2), Pair(-3, 22), Pair(28, 3), Pair(-2, 23), Pair(1, 26)
      }
    }},
    {{ // Bucket 45
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-19, 34), Pair(23, 7), Pair(6, 13), Pair(-5, 5), Pair(-15, 11), Pair(13, -9), Pair(-2, 9), Pair(-7, 29),
        Pair(11, 11), Pair(8, 7), Pair(18, 8), Pair(10, -3), Pair(4, 5), Pair(0, 0), Pair(7, -1), Pair(-2, 10),
        Pair(7, 1), Pair(5, 4), Pair(13, 5), Pair(8, -3), Pair(-3, 29), Pair(-11, -1), Pair(5, 2), Pair(1, 4),
        Pair(4, -1), Pair(3, 0), Pair(6, -3), Pair(7, 0), Pair(5, 4), Pair(0, 0), Pair(-2, 1), Pair(2, 3),
        Pair(5, 3), Pair(8, -2), Pair(5, 0), Pair(4, -2), Pair(4, 3), Pair(0, 0), Pair(-3, -4), Pair(-2, -1),
        Pair(8, -3), Pair(5, 1), Pair(8, -2), Pair(2, 0), Pair(-1, 4), Pair(8, -3), Pair(0, -8), Pair(-1, -1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(5, 75), Pair(6, 69), Pair(37, 87), Pair(27, 76), Pair(67, 27), Pair(20, 75), Pair(-215, 123), Pair(57, 73),
        Pair(26, 68), Pair(62, 60), Pair(35, 80), Pair(24, 14), Pair(50, 61), Pair(39, 38), Pair(37, 70), Pair(-50, 21),
        Pair(2, 81), Pair(16, 82), Pair(-2, 65), Pair(24, 71), Pair(27, 66), Pair(0, 0), Pair(9, 47), Pair(18, 92),
        Pair(33, 70), Pair(26, 64), Pair(22, 57), Pair(27, 54), Pair(-71, -13), Pair(40, 99), Pair(-49, -6), Pair(35, 51),
        Pair(38, 62), Pair(23, 62), Pair(17, 45), Pair(15, 81), Pair(-6, 67), Pair(20, 74), Pair(10, 23), Pair(23, 72),
        Pair(28, 80), Pair(32, 65), Pair(31, 62), Pair(4, 56), Pair(21, 71), Pair(2, 28), Pair(17, 68), Pair(-11, 33),
        Pair(39, 75), Pair(37, 51), Pair(19, 53), Pair(27, 48), Pair(28, 68), Pair(6, 63), Pair(43, 80), Pair(24, 57),
        Pair(63, 69), Pair(32, 81), Pair(24, 47), Pair(12, 73), Pair(19, 64), Pair(30, 62), Pair(3, 65), Pair(55, 97)
      },
      { // Piece 2
        Pair(39, 114), Pair(-30, 64), Pair(-36, 113), Pair(-37, 67), Pair(-45, 102), Pair(-38, 75), Pair(-125, 113), Pair(-191, 8),
        Pair(-1, 74), Pair(-7, 94), Pair(-21, 64), Pair(11, 92), Pair(-3, 75), Pair(22, 83), Pair(-19, -13), Pair(38, 82),
        Pair(25, 85), Pair(-17, 97), Pair(5, 88), Pair(-23, 72), Pair(4, 89), Pair(0, 0), Pair(8, 69), Pair(-6, 58),
        Pair(18, 63), Pair(28, 74), Pair(9, 71), Pair(8, 81), Pair(-93, -43), Pair(31, 110), Pair(-35, -35), Pair(27, 69),
        Pair(22, 88), Pair(-8, 77), Pair(26, 70), Pair(-2, 59), Pair(-7, 82), Pair(-11, 59), Pair(5, 85), Pair(3, 37),
        Pair(10, 61), Pair(30, 65), Pair(12, 53), Pair(20, 72), Pair(1, 57), Pair(26, 74), Pair(-20, 54), Pair(9, 97),
        Pair(34, 76), Pair(12, 45), Pair(21, 74), Pair(7, 50), Pair(32, 65), Pair(16, 66), Pair(30, 59), Pair(0, 46),
        Pair(-13, 73), Pair(14, 74), Pair(16, 52), Pair(35, 76), Pair(18, 64), Pair(27, 82), Pair(28, 46), Pair(5, 98)
      },
      { // Piece 3
        Pair(35, 80), Pair(9, 101), Pair(31, 93), Pair(15, 84), Pair(60, 70), Pair(78, 72), Pair(-13, 94), Pair(30, 91),
        Pair(45, 79), Pair(14, 88), Pair(40, 78), Pair(45, 75), Pair(33, 82), Pair(101, 75), Pair(23, 80), Pair(0, 88),
        Pair(37, 73), Pair(19, 80), Pair(27, 72), Pair(28, 78), Pair(24, 72), Pair(0, 0), Pair(4, 52), Pair(-1, 89),
        Pair(35, 72), Pair(30, 77), Pair(35, 75), Pair(4, 76), Pair(-12, -35), Pair(47, 56), Pair(29, -77), Pair(-1, 80),
        Pair(32, 75), Pair(27, 78), Pair(18, 74), Pair(12, 85), Pair(14, 67), Pair(15, 78), Pair(31, 72), Pair(-21, 85),
        Pair(55, 73), Pair(13, 82), Pair(21, 83), Pair(37, 69), Pair(31, 74), Pair(39, 74), Pair(10, 77), Pair(20, 86),
        Pair(39, 76), Pair(25, 92), Pair(26, 88), Pair(34, 71), Pair(28, 70), Pair(31, 73), Pair(17, 87), Pair(24, 62),
        Pair(35, 84), Pair(32, 85), Pair(34, 75), Pair(31, 78), Pair(29, 68), Pair(29, 80), Pair(26, 69), Pair(21, 91)
      },
      { // Piece 4
        Pair(24, 150), Pair(49, 146), Pair(32, 161), Pair(129, 86), Pair(22, 162), Pair(36, 134), Pair(36, 206), Pair(61, 97),
        Pair(66, 137), Pair(46, 149), Pair(71, 127), Pair(67, 176), Pair(38, 106), Pair(61, 142), Pair(93, 99), Pair(85, 155),
        Pair(60, 127), Pair(68, 111), Pair(55, 103), Pair(60, 118), Pair(52, 93), Pair(0, 0), Pair(76, 85), Pair(63, 104),
        Pair(72, 115), Pair(63, 132), Pair(68, 135), Pair(42, 141), Pair(42, 10), Pair(92, 71), Pair(12, 132), Pair(51, 160),
        Pair(60, 120), Pair(52, 152), Pair(58, 128), Pair(44, 119), Pair(39, 136), Pair(70, 73), Pair(44, 152), Pair(57, 133),
        Pair(48, 168), Pair(46, 142), Pair(57, 112), Pair(51, 138), Pair(50, 132), Pair(59, 129), Pair(68, 135), Pair(65, 130),
        Pair(77, 121), Pair(58, 116), Pair(58, 117), Pair(53, 142), Pair(47, 143), Pair(66, 116), Pair(52, 171), Pair(70, 129),
        Pair(65, 94), Pair(69, 110), Pair(59, 97), Pair(54, 123), Pair(57, 118), Pair(59, 112), Pair(61, 120), Pair(36, 127)
      },
      { // Piece 5
        Pair(-21, 10), Pair(-87, 0), Pair(2, -3), Pair(89, -18), Pair(95, -9), Pair(5, -61), Pair(-93, -16), Pair(43, -72),
        Pair(-5, 20), Pair(-2, 4), Pair(-166, 55), Pair(-101, 19), Pair(24, -22), Pair(228, -72), Pair(61, -20), Pair(83, -30),
        Pair(140, 6), Pair(33, 24), Pair(48, 8), Pair(-17, 5), Pair(45, -63), Pair(0, 0), Pair(91, -51), Pair(114, -18),
        Pair(94, -5), Pair(18, 2), Pair(106, 11), Pair(11, -21), Pair(-228, -121), Pair(-34, -50), Pair(-59, -81), Pair(12, -1),
        Pair(30, 9), Pair(85, -4), Pair(33, 4), Pair(35, -11), Pair(50, -25), Pair(30, -29), Pair(28, -12), Pair(10, -8),
        Pair(49, -9), Pair(8, -8), Pair(43, -4), Pair(18, -2), Pair(27, -11), Pair(-6, -12), Pair(17, 2), Pair(16, 8),
        Pair(27, -8), Pair(15, -2), Pair(29, 3), Pair(20, 6), Pair(19, 2), Pair(43, -7), Pair(6, 1), Pair(12, 16),
        Pair(46, -24), Pair(-5, 7), Pair(6, 14), Pair(16, 15), Pair(7, 7), Pair(2, 14), Pair(-4, 10), Pair(13, 10)
      }
    }},
    {{ // Bucket 46
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(15, 17), Pair(11, 23), Pair(30, 6), Pair(23, 9), Pair(-40, 20), Pair(-39, 24), Pair(-34, 15), Pair(-39, 18),
        Pair(8, 12), Pair(11, 13), Pair(8, 8), Pair(5, 3), Pair(1, -1), Pair(-10, 12), Pair(0, 0), Pair(7, 7),
        Pair(4, 8), Pair(7, 4), Pair(8, 3), Pair(2, 6), Pair(1, -1), Pair(4, 26), Pair(-7, -5), Pair(29, 14),
        Pair(5, 2), Pair(6, -4), Pair(2, 1), Pair(0, 1), Pair(0, 1), Pair(6, 3), Pair(9, -1), Pair(7, 5),
        Pair(3, -2), Pair(5, -2), Pair(2, -2), Pair(3, -2), Pair(6, 1), Pair(0, 2), Pair(0, 0), Pair(1, 3),
        Pair(4, -2), Pair(2, -3), Pair(-4, -2), Pair(-2, 0), Pair(4, -1), Pair(7, 1), Pair(2, -5), Pair(-4, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-7, 72), Pair(-124, 97), Pair(33, 51), Pair(-61, 90), Pair(53, 62), Pair(-92, 91), Pair(-58, 62), Pair(51, 30),
        Pair(16, 57), Pair(36, 49), Pair(32, 54), Pair(10, 50), Pair(-2, 13), Pair(34, 62), Pair(-62, 2), Pair(1, 72),
        Pair(-6, 63), Pair(23, 49), Pair(20, 50), Pair(-15, 48), Pair(6, 80), Pair(-5, 61), Pair(0, 0), Pair(-50, 27),
        Pair(23, 37), Pair(18, 55), Pair(9, 61), Pair(1, 54), Pair(7, 51), Pair(-102, 16), Pair(-6, 105), Pair(-43, 69),
        Pair(23, 49), Pair(6, 56), Pair(10, 51), Pair(-7, 48), Pair(-7, 69), Pair(-25, 43), Pair(-1, 68), Pair(-27, 20),
        Pair(14, 40), Pair(10, 49), Pair(9, 53), Pair(12, 52), Pair(-12, 43), Pair(6, 59), Pair(-33, 17), Pair(-8, 60),
        Pair(37, 57), Pair(19, 41), Pair(-2, 49), Pair(8, 54), Pair(-1, 48), Pair(10, 63), Pair(20, 36), Pair(18, 78),
        Pair(20, 15), Pair(13, 73), Pair(8, 54), Pair(20, 50), Pair(9, 51), Pair(11, 57), Pair(2, 56), Pair(11, 85)
      },
      { // Piece 2
        Pair(-27, 94), Pair(31, 106), Pair(-98, 95), Pair(6, 92), Pair(-103, 99), Pair(-73, 92), Pair(-14, 92), Pair(28, 59),
        Pair(0, 86), Pair(-3, 85), Pair(15, 85), Pair(-52, 92), Pair(-32, 103), Pair(-59, 88), Pair(-137, 112), Pair(-159, 17),
        Pair(-2, 78), Pair(-8, 83), Pair(-5, 74), Pair(-6, 90), Pair(-29, 59), Pair(5, 89), Pair(0, 0), Pair(2, 78),
        Pair(1, 79), Pair(-2, 70), Pair(3, 81), Pair(-15, 75), Pair(-9, 77), Pair(-180, -69), Pair(-9, 104), Pair(-79, -19),
        Pair(-17, 71), Pair(3, 86), Pair(-5, 68), Pair(-3, 72), Pair(-27, 50), Pair(-17, 67), Pair(-20, 56), Pair(-22, 77),
        Pair(12, 68), Pair(10, 61), Pair(9, 72), Pair(-13, 54), Pair(-1, 68), Pair(0, 50), Pair(3, 66), Pair(-18, 58),
        Pair(8, 66), Pair(13, 66), Pair(-16, 48), Pair(5, 65), Pair(0, 49), Pair(15, 76), Pair(2, 51), Pair(8, 80),
        Pair(17, 68), Pair(-28, 48), Pair(10, 69), Pair(-3, 47), Pair(18, 76), Pair(6, 62), Pair(-1, 82), Pair(4, 68)
      },
      { // Piece 3
        Pair(9, 90), Pair(-8, 108), Pair(-18, 98), Pair(-4, 98), Pair(9, 80), Pair(-17, 91), Pair(19, 81), Pair(-23, 91),
        Pair(16, 88), Pair(22, 86), Pair(-3, 97), Pair(-1, 97), Pair(3, 100), Pair(15, 83), Pair(110, 76), Pair(2, 94),
        Pair(9, 83), Pair(10, 78), Pair(10, 77), Pair(-1, 85), Pair(1, 80), Pair(-9, 77), Pair(0, 0), Pair(-40, 92),
        Pair(28, 76), Pair(16, 78), Pair(18, 70), Pair(8, 89), Pair(11, 63), Pair(5, -93), Pair(8, 71), Pair(-23, -41),
        Pair(13, 79), Pair(23, 71), Pair(18, 77), Pair(8, 75), Pair(8, 70), Pair(-3, 66), Pair(1, 61), Pair(-20, 75),
        Pair(23, 71), Pair(17, 69), Pair(15, 72), Pair(16, 79), Pair(23, 69), Pair(2, 69), Pair(-14, 74), Pair(-8, 75),
        Pair(36, 86), Pair(29, 71), Pair(13, 81), Pair(27, 69), Pair(32, 63), Pair(18, 69), Pair(-5, 65), Pair(-4, 67),
        Pair(20, 82), Pair(16, 80), Pair(17, 77), Pair(15, 77), Pair(14, 77), Pair(11, 76), Pair(3, 71), Pair(8, 72)
      },
      { // Piece 4
        Pair(-47, 175), Pair(-50, 191), Pair(-35, 153), Pair(-29, 171), Pair(-14, 142), Pair(19, 195), Pair(-6, 127), Pair(38, 185),
        Pair(23, 111), Pair(3, 140), Pair(8, 145), Pair(-14, 167), Pair(-58, 209), Pair(3, 142), Pair(19, 134), Pair(27, 88),
        Pair(4, 115), Pair(25, 91), Pair(2, 114), Pair(-3, 101), Pair(16, 87), Pair(-34, 129), Pair(0, 0), Pair(-10, 55),
        Pair(18, 106), Pair(12, 128), Pair(15, 101), Pair(14, 118), Pair(-19, 142), Pair(-28, 91), Pair(-11, 75), Pair(35, 0),
        Pair(20, 113), Pair(8, 131), Pair(5, 123), Pair(-9, 160), Pair(-3, 130), Pair(-1, 101), Pair(-6, 101), Pair(-18, 135),
        Pair(7, 157), Pair(5, 136), Pair(2, 137), Pair(-2, 138), Pair(3, 118), Pair(-8, 128), Pair(20, 96), Pair(3, 133),
        Pair(13, 116), Pair(9, 129), Pair(10, 111), Pair(5, 118), Pair(0, 131), Pair(9, 119), Pair(10, 131), Pair(30, 135),
        Pair(1, 135), Pair(11, 99), Pair(17, 99), Pair(12, 110), Pair(9, 122), Pair(-3, 133), Pair(-12, 125), Pair(9, 167)
      },
      { // Piece 5
        Pair(462, -89), Pair(114, -15), Pair(-23, -21), Pair(220, -14), Pair(35, 13), Pair(103, -23), Pair(252, -104), Pair(-15, -124),
        Pair(195, 2), Pair(81, -17), Pair(187, -16), Pair(11, -5), Pair(134, -28), Pair(89, -16), Pair(-26, 9), Pair(325, -60),
        Pair(260, -15), Pair(161, 16), Pair(39, 15), Pair(61, 13), Pair(102, -23), Pair(14, -21), Pair(0, 0), Pair(190, -56),
        Pair(79, 15), Pair(139, 12), Pair(97, 5), Pair(143, -8), Pair(17, -2), Pair(-10, -50), Pair(53, -59), Pair(-229, -392),
        Pair(148, -18), Pair(67, 2), Pair(41, 11), Pair(65, -7), Pair(34, -5), Pair(59, -16), Pair(-5, -11), Pair(8, -8),
        Pair(88, -7), Pair(47, -7), Pair(53, 3), Pair(53, 0), Pair(9, 6), Pair(18, 4), Pair(-1, -6), Pair(-14, 17),
        Pair(4, 10), Pair(-4, 4), Pair(5, 12), Pair(-3, 14), Pair(9, 17), Pair(24, 7), Pair(3, 6), Pair(8, 11),
        Pair(-20, -6), Pair(-24, 6), Pair(-22, 11), Pair(0, 15), Pair(-9, 19), Pair(13, 9), Pair(2, 15), Pair(8, 7)
      }
    }},
    {{ // Bucket 47
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(5, 27), Pair(5, 12), Pair(24, 2), Pair(-11, 16), Pair(-19, 32), Pair(-10, 18), Pair(-19, 23), Pair(-29, -17),
        Pair(-3, 15), Pair(3, 8), Pair(3, 5), Pair(10, 6), Pair(6, 2), Pair(-19, 8), Pair(-18, 4), Pair(0, 0),
        Pair(3, 7), Pair(3, 4), Pair(6, 2), Pair(1, 3), Pair(-4, -1), Pair(-9, 0), Pair(-12, -3), Pair(-8, -3),
        Pair(4, -3), Pair(2, -1), Pair(5, 1), Pair(-3, -2), Pair(-2, 2), Pair(3, 3), Pair(-2, -7), Pair(-5, -2),
        Pair(1, -1), Pair(1, -5), Pair(-2, -5), Pair(0, -3), Pair(1, 1), Pair(1, 0), Pair(-1, -3), Pair(0, 0),
        Pair(-1, -3), Pair(-4, -6), Pair(-2, -5), Pair(-3, 0), Pair(-1, -1), Pair(2, -1), Pair(-1, -5), Pair(1, -3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-39, 73), Pair(-137, 97), Pair(-51, 48), Pair(9, 40), Pair(-7, 65), Pair(30, 97), Pair(-72, 102), Pair(-8, 112),
        Pair(25, 23), Pair(37, 39), Pair(4, 51), Pair(6, 56), Pair(-1, 57), Pair(-24, 29), Pair(11, 40), Pair(-46, 37),
        Pair(33, 45), Pair(23, 45), Pair(1, 55), Pair(7, 56), Pair(-6, 46), Pair(-17, 87), Pair(-16, 68), Pair(0, 0),
        Pair(9, 34), Pair(11, 45), Pair(6, 45), Pair(2, 53), Pair(3, 48), Pair(1, 57), Pair(-66, -12), Pair(41, 84),
        Pair(15, 40), Pair(20, 31), Pair(5, 51), Pair(6, 50), Pair(-4, 49), Pair(3, 49), Pair(-5, 54), Pair(-4, 60),
        Pair(11, 38), Pair(17, 31), Pair(14, 40), Pair(7, 46), Pair(9, 44), Pair(-5, 36), Pair(9, 58), Pair(-19, 14),
        Pair(33, 30), Pair(-19, 85), Pair(-2, 41), Pair(10, 43), Pair(17, 52), Pair(0, 45), Pair(25, 45), Pair(16, 67),
        Pair(6, 34), Pair(16, 43), Pair(22, 44), Pair(1, 35), Pair(13, 48), Pair(11, 43), Pair(2, 54), Pair(8, 45)
      },
      { // Piece 2
        Pair(-30, 112), Pair(-90, 121), Pair(-91, 114), Pair(-74, 95), Pair(-58, 108), Pair(-64, 118), Pair(6, 86), Pair(43, 78),
        Pair(-28, 84), Pair(24, 82), Pair(8, 90), Pair(-69, 113), Pair(-21, 84), Pair(-10, 92), Pair(-49, 92), Pair(27, 85),
        Pair(21, 74), Pair(-10, 80), Pair(-7, 90), Pair(-9, 74), Pair(12, 96), Pair(-64, 91), Pair(15, 69), Pair(0, 0),
        Pair(-2, 67), Pair(10, 71), Pair(-20, 82), Pair(-1, 88), Pair(-12, 86), Pair(-10, 79), Pair(-58, -23), Pair(18, 102),
        Pair(18, 64), Pair(-5, 74), Pair(-2, 80), Pair(-8, 66), Pair(5, 74), Pair(-12, 63), Pair(-15, 68), Pair(-8, 61),
        Pair(3, 64), Pair(20, 71), Pair(5, 66), Pair(5, 73), Pair(-7, 60), Pair(6, 71), Pair(-6, 72), Pair(16, 93),
        Pair(7, 89), Pair(10, 61), Pair(7, 65), Pair(-6, 55), Pair(5, 71), Pair(9, 57), Pair(11, 62), Pair(16, 55),
        Pair(3, 65), Pair(11, 71), Pair(-3, 62), Pair(-2, 74), Pair(12, 67), Pair(14, 80), Pair(-21, 72), Pair(13, 66)
      },
      { // Piece 3
        Pair(-17, 109), Pair(1, 111), Pair(-32, 127), Pair(-8, 116), Pair(1, 112), Pair(21, 95), Pair(-32, 122), Pair(55, 92),
        Pair(14, 103), Pair(17, 105), Pair(9, 108), Pair(5, 108), Pair(17, 103), Pair(15, 107), Pair(16, 95), Pair(164, 83),
        Pair(16, 105), Pair(15, 104), Pair(11, 106), Pair(-3, 111), Pair(17, 104), Pair(-1, 112), Pair(-5, 109), Pair(0, 0),
        Pair(18, 104), Pair(6, 108), Pair(18, 100), Pair(13, 98), Pair(-8, 106), Pair(-10, 100), Pair(7, -50), Pair(-17, 102),
        Pair(22, 86), Pair(26, 95), Pair(14, 98), Pair(2, 97), Pair(15, 89), Pair(3, 92), Pair(9, 82), Pair(-28, 89),
        Pair(17, 99), Pair(29, 93), Pair(23, 87), Pair(12, 96), Pair(12, 90), Pair(11, 92), Pair(-5, 88), Pair(0, 85),
        Pair(34, 87), Pair(28, 96), Pair(20, 90), Pair(24, 84), Pair(18, 90), Pair(17, 87), Pair(23, 86), Pair(1, 98),
        Pair(16, 95), Pair(15, 99), Pair(15, 96), Pair(13, 95), Pair(16, 91), Pair(14, 87), Pair(-5, 100), Pair(4, 95)
      },
      { // Piece 4
        Pair(-20, 206), Pair(-42, 208), Pair(-31, 228), Pair(-19, 176), Pair(4, 190), Pair(40, 173), Pair(70, 153), Pair(-114, 265),
        Pair(17, 166), Pair(21, 169), Pair(12, 179), Pair(-33, 231), Pair(3, 209), Pair(-25, 246), Pair(14, 196), Pair(30, 188),
        Pair(24, 166), Pair(10, 171), Pair(14, 175), Pair(-2, 183), Pair(-5, 201), Pair(-8, 229), Pair(-29, 213), Pair(0, 0),
        Pair(24, 157), Pair(16, 190), Pair(15, 180), Pair(0, 196), Pair(6, 176), Pair(1, 216), Pair(14, -8), Pair(9, 147),
        Pair(20, 173), Pair(19, 166), Pair(5, 169), Pair(14, 184), Pair(8, 188), Pair(15, 175), Pair(13, 148), Pair(0, 119),
        Pair(24, 157), Pair(10, 167), Pair(18, 170), Pair(14, 176), Pair(15, 167), Pair(16, 162), Pair(25, 149), Pair(5, 141),
        Pair(18, 183), Pair(21, 158), Pair(17, 155), Pair(18, 158), Pair(13, 163), Pair(28, 155), Pair(45, 133), Pair(2, 142),
        Pair(14, 152), Pair(19, 162), Pair(13, 158), Pair(19, 154), Pair(30, 148), Pair(14, 188), Pair(-9, 191), Pair(-14, 139)
      },
      { // Piece 5
        Pair(107, -14), Pair(90, -83), Pair(-106, -20), Pair(82, -66), Pair(-11, 1), Pair(-267, -11), Pair(206, -111), Pair(70, -72),
        Pair(151, -42), Pair(42, 13), Pair(-12, 19), Pair(-79, 36), Pair(-139, 23), Pair(143, -15), Pair(-48, 22), Pair(100, -16),
        Pair(46, -38), Pair(-21, 21), Pair(51, 5), Pair(68, 6), Pair(54, 4), Pair(5, 17), Pair(-83, -17), Pair(0, 0),
        Pair(104, -11), Pair(117, -2), Pair(76, -3), Pair(60, 4), Pair(77, 6), Pair(-57, 15), Pair(-269, -121), Pair(86, -55),
        Pair(27, 0), Pair(27, -7), Pair(45, -8), Pair(51, 7), Pair(22, 5), Pair(-14, -3), Pair(46, -11), Pair(68, -16),
        Pair(61, -38), Pair(35, -13), Pair(33, -5), Pair(28, 4), Pair(40, 1), Pair(-3, 9), Pair(21, -1), Pair(19, -19),
        Pair(-8, 12), Pair(-31, -11), Pair(-5, -1), Pair(9, 0), Pair(5, 14), Pair(11, 12), Pair(9, 10), Pair(8, 2),
        Pair(-8, -28), Pair(-25, -9), Pair(-16, 7), Pair(7, 4), Pair(-4, 23), Pair(6, 21), Pair(8, 12), Pair(6, 19)
      }
    }},
    {{ // Bucket 48
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(-30, 17), Pair(-8, 22), Pair(1, 6), Pair(-4, 14), Pair(25, 9), Pair(-12, 37), Pair(-15, 38),
        Pair(-27, -53), Pair(-25, -19), Pair(-9, 7), Pair(9, 6), Pair(16, 5), Pair(-5, 19), Pair(8, 15), Pair(-8, 19),
        Pair(-12, -6), Pair(-4, 9), Pair(-4, 5), Pair(5, 3), Pair(0, 9), Pair(3, 7), Pair(1, 5), Pair(0, 19),
        Pair(-6, 3), Pair(-5, 3), Pair(-7, 0), Pair(-1, 2), Pair(3, 7), Pair(-1, 8), Pair(-2, 3), Pair(2, 4),
        Pair(-2, 6), Pair(-3, 3), Pair(-2, -1), Pair(-1, 0), Pair(-3, 3), Pair(-7, 5), Pair(-3, 0), Pair(-3, 1),
        Pair(0, 0), Pair(2, -1), Pair(-1, 0), Pair(-6, -3), Pair(-1, -3), Pair(-4, 4), Pair(-5, 2), Pair(0, 7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-45, -55), Pair(130, 47), Pair(-61, 135), Pair(10, 88), Pair(37, 56), Pair(-37, 63), Pair(85, 99), Pair(79, -22),
        Pair(0, 0), Pair(24, 65), Pair(30, 50), Pair(12, 23), Pair(12, 69), Pair(63, 40), Pair(9, 17), Pair(18, 17),
        Pair(39, 101), Pair(-265, 14), Pair(13, 83), Pair(13, 67), Pair(11, 59), Pair(16, 58), Pair(35, 47), Pair(39, 26),
        Pair(27, 69), Pair(-7, 82), Pair(11, 65), Pair(1, 52), Pair(17, 60), Pair(18, 62), Pair(18, 58), Pair(19, 58),
        Pair(-2, 50), Pair(-20, 62), Pair(1, 57), Pair(8, 69), Pair(8, 63), Pair(16, 53), Pair(22, 68), Pair(19, 51),
        Pair(6, 73), Pair(5, 75), Pair(1, 68), Pair(10, 61), Pair(6, 64), Pair(10, 62), Pair(16, 58), Pair(29, 45),
        Pair(22, 66), Pair(0, 74), Pair(14, 49), Pair(12, 60), Pair(14, 53), Pair(16, 59), Pair(6, 61), Pair(27, 55),
        Pair(-71, 115), Pair(13, 63), Pair(-14, 93), Pair(24, 57), Pair(17, 50), Pair(15, 59), Pair(25, 55), Pair(16, 128)
      },
      { // Piece 2
        Pair(5, 82), Pair(-67, 142), Pair(-50, 97), Pair(-31, 112), Pair(-46, 113), Pair(-39, 121), Pair(45, 73), Pair(-80, 95),
        Pair(0, 0), Pair(-14, 100), Pair(2, 92), Pair(-27, 125), Pair(-21, 131), Pair(-2, 99), Pair(17, 84), Pair(18, 87),
        Pair(8, 122), Pair(-223, 107), Pair(-14, 100), Pair(-4, 117), Pair(-1, 102), Pair(5, 108), Pair(22, 96), Pair(18, 84),
        Pair(27, 89), Pair(-26, 100), Pair(4, 112), Pair(-11, 88), Pair(-1, 110), Pair(-1, 96), Pair(8, 92), Pair(1, 83),
        Pair(2, 94), Pair(-29, 95), Pair(-5, 94), Pair(-6, 99), Pair(-3, 86), Pair(5, 98), Pair(-8, 88), Pair(6, 97),
        Pair(11, 108), Pair(-3, 94), Pair(8, 90), Pair(-1, 87), Pair(5, 82), Pair(-1, 79), Pair(5, 96), Pair(12, 73),
        Pair(-8, 140), Pair(11, 92), Pair(1, 94), Pair(8, 88), Pair(-1, 79), Pair(3, 88), Pair(9, 70), Pair(17, 73),
        Pair(-10, 113), Pair(0, 114), Pair(12, 92), Pair(2, 86), Pair(-7, 94), Pair(6, 79), Pair(23, 109), Pair(11, 80)
      },
      { // Piece 3
        Pair(10, 139), Pair(-51, 186), Pair(-65, 178), Pair(-31, 160), Pair(-51, 161), Pair(-69, 172), Pair(8, 159), Pair(19, 153),
        Pair(0, 0), Pair(-21, 178), Pair(-24, 180), Pair(-31, 178), Pair(-28, 183), Pair(-4, 162), Pair(0, 152), Pair(-37, 173),
        Pair(-4, 160), Pair(-22, -246), Pair(-12, 149), Pair(-26, 161), Pair(-15, 152), Pair(-2, 145), Pair(-46, 154), Pair(-23, 155),
        Pair(-13, 154), Pair(-34, 156), Pair(-15, 149), Pair(-18, 151), Pair(-23, 152), Pair(-18, 139), Pair(-7, 141), Pair(-10, 157),
        Pair(-16, 141), Pair(-49, 126), Pair(-30, 147), Pair(-20, 141), Pair(-18, 144), Pair(-8, 128), Pair(2, 139), Pair(-5, 132),
        Pair(-21, 133), Pair(-13, 124), Pair(-27, 149), Pair(-15, 133), Pair(-11, 145), Pair(-4, 136), Pair(7, 137), Pair(18, 132),
        Pair(-5, 110), Pair(-33, 145), Pair(-13, 140), Pair(-19, 135), Pair(-7, 134), Pair(-9, 133), Pair(-10, 144), Pair(14, 127),
        Pair(-22, 141), Pair(-21, 131), Pair(-18, 135), Pair(-19, 138), Pair(-16, 141), Pair(-14, 141), Pair(3, 147), Pair(-12, 161)
      },
      { // Piece 4
        Pair(-58, 331), Pair(14, 277), Pair(-16, 320), Pair(-34, 326), Pair(20, 283), Pair(-4, 326), Pair(18, 283), Pair(5, 293),
        Pair(0, 0), Pair(37, 288), Pair(7, 320), Pair(0, 323), Pair(-8, 335), Pair(17, 330), Pair(11, 257), Pair(25, 300),
        Pair(45, 280), Pair(-420, -195), Pair(10, 285), Pair(0, 299), Pair(5, 275), Pair(19, 261), Pair(17, 241), Pair(23, 275),
        Pair(33, 274), Pair(16, 242), Pair(15, 268), Pair(16, 268), Pair(-2, 287), Pair(18, 270), Pair(21, 278), Pair(19, 274),
        Pair(17, 265), Pair(4, 233), Pair(7, 264), Pair(11, 259), Pair(7, 274), Pair(13, 263), Pair(18, 256), Pair(20, 275),
        Pair(15, 288), Pair(12, 249), Pair(8, 252), Pair(8, 258), Pair(1, 267), Pair(15, 261), Pair(20, 250), Pair(40, 269),
        Pair(8, 301), Pair(10, 243), Pair(8, 258), Pair(11, 248), Pair(14, 254), Pair(12, 246), Pair(18, 241), Pair(32, 248),
        Pair(13, 277), Pair(18, 231), Pair(13, 266), Pair(7, 252), Pair(11, 256), Pair(16, 279), Pair(53, 192), Pair(15, 255)
      },
      { // Piece 5
        Pair(124, 68), Pair(-71, 28), Pair(-65, 7), Pair(39, -8), Pair(18, -12), Pair(177, -54), Pair(163, -38), Pair(115, 70),
        Pair(0, 0), Pair(-49, -69), Pair(-63, 35), Pair(-63, 26), Pair(-107, -16), Pair(47, -7), Pair(142, -17), Pair(112, -50),
        Pair(13, -52), Pair(0, 0), Pair(-143, 27), Pair(38, -13), Pair(-19, -6), Pair(-1, 30), Pair(64, 8), Pair(91, 7),
        Pair(-79, -21), Pair(-70, -16), Pair(-41, -33), Pair(34, -7), Pair(97, -18), Pair(27, 6), Pair(51, 9), Pair(59, -13),
        Pair(10, -43), Pair(-48, -12), Pair(-87, 6), Pair(-20, -9), Pair(47, -8), Pair(21, -2), Pair(6, -4), Pair(7, 7),
        Pair(-33, -16), Pair(-38, -15), Pair(-19, -3), Pair(-26, 3), Pair(-14, -6), Pair(20, -12), Pair(9, -7), Pair(23, -2),
        Pair(-37, 12), Pair(-25, 0), Pair(17, -13), Pair(9, -8), Pair(2, 2), Pair(28, -15), Pair(1, -9), Pair(5, -2),
        Pair(-10, 32), Pair(9, 2), Pair(17, 5), Pair(19, -4), Pair(14, -5), Pair(24, -13), Pair(1, -11), Pair(4, -8)
      }
    }},
    {{ // Bucket 49
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-11, -3), Pair(0, 0), Pair(-27, 10), Pair(-10, 3), Pair(-18, 25), Pair(1, 10), Pair(2, -1), Pair(-17, 25),
        Pair(13, 6), Pair(-30, -50), Pair(-8, -17), Pair(-3, 4), Pair(4, 9), Pair(7, 21), Pair(10, 15), Pair(-6, 23),
        Pair(11, 5), Pair(-12, -9), Pair(2, 16), Pair(-1, 3), Pair(-5, 8), Pair(-2, 8), Pair(-3, 12), Pair(-2, 16),
        Pair(6, 0), Pair(-8, -6), Pair(4, 9), Pair(-1, 4), Pair(0, 3), Pair(-1, 7), Pair(-1, 5), Pair(-1, 10),
        Pair(4, 3), Pair(-7, 0), Pair(-3, 4), Pair(-1, -5), Pair(-3, 4), Pair(-2, 2), Pair(-3, 6), Pair(-6, 4),
        Pair(2, 1), Pair(0, 0), Pair(0, -2), Pair(-8, 11), Pair(-1, -3), Pair(-4, 0), Pair(-3, 2), Pair(-2, -4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-10, 70), Pair(-177, -89), Pair(4, 73), Pair(10, 39), Pair(7, 56), Pair(-41, 84), Pair(-191, 83), Pair(-2, 108),
        Pair(-17, 13), Pair(0, 0), Pair(-9, 73), Pair(-67, 69), Pair(-25, 62), Pair(-23, 85), Pair(1, 50), Pair(45, 23),
        Pair(10, -26), Pair(20, 91), Pair(-366, 4), Pair(4, 76), Pair(-17, 68), Pair(-8, 68), Pair(9, 61), Pair(10, 44),
        Pair(-1, 72), Pair(-9, 87), Pair(-41, 80), Pair(-7, 71), Pair(-11, 50), Pair(5, 63), Pair(6, 63), Pair(7, 45),
        Pair(-11, 67), Pair(-23, 17), Pair(-24, 70), Pair(-16, 61), Pair(-3, 65), Pair(2, 54), Pair(6, 62), Pair(5, 65),
        Pair(1, 75), Pair(0, 59), Pair(-3, 62), Pair(-5, 57), Pair(2, 53), Pair(1, 59), Pair(5, 57), Pair(6, 66),
        Pair(21, 74), Pair(9, 49), Pair(7, 62), Pair(0, 67), Pair(6, 59), Pair(2, 50), Pair(12, 51), Pair(3, 76),
        Pair(63, 12), Pair(8, 72), Pair(12, 49), Pair(4, 64), Pair(12, 60), Pair(15, 54), Pair(3, 79), Pair(-16, 37)
      },
      { // Piece 2
        Pair(0, 0), Pair(-26, 112), Pair(-103, 128), Pair(-51, 94), Pair(-55, 115), Pair(-59, 99), Pair(-53, 132), Pair(12, 115),
        Pair(-30, 88), Pair(0, 0), Pair(-13, 86), Pair(-131, 135), Pair(-31, 103), Pair(-5, 116), Pair(-15, 108), Pair(-5, 109),
        Pair(-232, 106), Pair(-3, 103), Pair(-345, -324), Pair(0, 72), Pair(-22, 103), Pair(-21, 102), Pair(-45, 87), Pair(8, 85),
        Pair(-16, 77), Pair(-20, 84), Pair(-52, 94), Pair(-21, 94), Pair(-4, 85), Pair(-30, 105), Pair(-8, 94), Pair(-9, 92),
        Pair(-21, 89), Pair(-22, 85), Pair(-35, 93), Pair(-18, 79), Pair(-15, 79), Pair(-6, 80), Pair(-19, 91), Pair(4, 73),
        Pair(-2, 77), Pair(-8, 89), Pair(-8, 85), Pair(-13, 79), Pair(-1, 71), Pair(-12, 81), Pair(-5, 80), Pair(-7, 94),
        Pair(6, 108), Pair(5, 83), Pair(-11, 90), Pair(-4, 71), Pair(-12, 78), Pair(11, 71), Pair(-5, 74), Pair(0, 80),
        Pair(2, 95), Pair(4, 83), Pair(3, 83), Pair(-2, 83), Pair(1, 85), Pair(-4, 85), Pair(17, 65), Pair(-9, 82)
      },
      { // Piece 3
        Pair(-10, 95), Pair(-48, 127), Pair(6, 97), Pair(-35, 127), Pair(-10, 111), Pair(-92, 155), Pair(-105, 144), Pair(-69, 128),
        Pair(-33, 110), Pair(0, 0), Pair(-20, 125), Pair(-13, 137), Pair(-9, 116), Pair(-25, 131), Pair(-10, 111), Pair(-40, 120),
        Pair(-261, -67), Pair(-14, 107), Pair(-237, -186), Pair(-4, 103), Pair(-25, 117), Pair(0, 111), Pair(-4, 118), Pair(3, 113),
        Pair(-23, 95), Pair(-14, 121), Pair(-36, 107), Pair(-13, 110), Pair(-35, 124), Pair(-36, 126), Pair(-8, 116), Pair(-7, 110),
        Pair(-24, 96), Pair(-25, 95), Pair(-46, 97), Pair(-29, 107), Pair(-15, 99), Pair(-17, 105), Pair(-1, 99), Pair(6, 102),
        Pair(-28, 101), Pair(-15, 93), Pair(-31, 106), Pair(-22, 111), Pair(-18, 112), Pair(-3, 105), Pair(4, 95), Pair(2, 107),
        Pair(-12, 103), Pair(2, 84), Pair(-30, 105), Pair(-2, 84), Pair(-16, 104), Pair(-16, 100), Pair(15, 94), Pair(0, 107),
        Pair(-17, 100), Pair(-13, 102), Pair(-24, 98), Pair(-15, 100), Pair(-14, 108), Pair(-12, 111), Pair(-6, 113), Pair(-2, 125)
      },
      { // Piece 4
        Pair(-5, 192), Pair(7, 187), Pair(50, 190), Pair(6, 238), Pair(38, 180), Pair(17, 221), Pair(-17, 277), Pair(14, 169),
        Pair(45, 136), Pair(0, 0), Pair(13, 187), Pair(10, 213), Pair(-7, 224), Pair(-18, 223), Pair(15, 189), Pair(24, 166),
        Pair(-7, 93), Pair(34, 149), Pair(-368, -170), Pair(26, 174), Pair(10, 191), Pair(26, 161), Pair(14, 203), Pair(23, 211),
        Pair(23, 166), Pair(19, 183), Pair(-4, 190), Pair(20, 188), Pair(15, 211), Pair(13, 212), Pair(25, 185), Pair(14, 199),
        Pair(7, 164), Pair(7, 193), Pair(-2, 165), Pair(5, 221), Pair(10, 179), Pair(6, 188), Pair(9, 185), Pair(17, 202),
        Pair(14, 174), Pair(9, 190), Pair(11, 160), Pair(6, 176), Pair(10, 187), Pair(9, 190), Pair(10, 188), Pair(6, 214),
        Pair(35, 161), Pair(5, 201), Pair(10, 173), Pair(10, 175), Pair(4, 182), Pair(10, 169), Pair(18, 154), Pair(-4, 227),
        Pair(12, 167), Pair(17, 196), Pair(10, 176), Pair(10, 185), Pair(13, 184), Pair(15, 161), Pair(32, 131), Pair(-3, 199)
      },
      { // Piece 5
        Pair(-15, -12), Pair(120, -98), Pair(-67, -44), Pair(-87, -9), Pair(-121, -16), Pair(177, -56), Pair(-39, -32), Pair(51, -66),
        Pair(-67, -84), Pair(0, 0), Pair(-2, -70), Pair(23, -52), Pair(-56, -12), Pair(26, 41), Pair(3, -5), Pair(93, 19),
        Pair(0, 0), Pair(-94, -58), Pair(0, 0), Pair(-97, -20), Pair(-111, 15), Pair(12, 17), Pair(-8, 13), Pair(119, -19),
        Pair(-57, -25), Pair(-55, -39), Pair(-25, -20), Pair(-109, -5), Pair(52, -3), Pair(11, 24), Pair(-24, 30), Pair(48, -4),
        Pair(-16, -26), Pair(-91, -20), Pair(-34, -28), Pair(2, -11), Pair(17, -14), Pair(8, 6), Pair(19, 5), Pair(46, -12),
        Pair(-2, -17), Pair(-43, -13), Pair(-12, -19), Pair(4, -8), Pair(18, -5), Pair(-3, 4), Pair(15, 0), Pair(31, -7),
        Pair(-1, -13), Pair(-13, -10), Pair(2, -16), Pair(25, 2), Pair(17, -2), Pair(3, 1), Pair(11, -5), Pair(8, -1),
        Pair(8, -6), Pair(2, -7), Pair(15, -17), Pair(24, 5), Pair(12, 2), Pair(30, -7), Pair(5, -5), Pair(12, -1)
      }
    }},
    {{ // Bucket 50
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-12, -4), Pair(-12, -7), Pair(0, 0), Pair(-9, 12), Pair(9, -10), Pair(9, 8), Pair(-4, 8), Pair(-14, 36),
        Pair(-7, 17), Pair(-6, -6), Pair(-23, -53), Pair(-18, 23), Pair(-1, 8), Pair(-2, 15), Pair(-17, 12), Pair(-7, 12),
        Pair(-4, 5), Pair(6, 12), Pair(-8, -7), Pair(3, 13), Pair(-2, 8), Pair(5, 11), Pair(3, 18), Pair(1, 12),
        Pair(-4, -1), Pair(4, -6), Pair(-11, -4), Pair(0, 8), Pair(-7, 3), Pair(0, 6), Pair(5, 4), Pair(0, 7),
        Pair(-1, 3), Pair(-4, -1), Pair(-6, -2), Pair(-4, 1), Pair(-3, 1), Pair(-5, 4), Pair(0, 3), Pair(-2, 2),
        Pair(-5, -1), Pair(-5, -4), Pair(0, 0), Pair(-6, 0), Pair(0, -3), Pair(-7, -1), Pair(4, 4), Pair(1, 4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-108, -31), Pair(-23, 109), Pair(-75, -5), Pair(-91, 78), Pair(-19, 21), Pair(-28, 67), Pair(-171, 103), Pair(93, -48),
        Pair(6, 64), Pair(-27, 54), Pair(0, 0), Pair(-16, 66), Pair(-53, 82), Pair(-41, 36), Pair(1, 51), Pair(-39, 73),
        Pair(43, 77), Pair(-84, -181), Pair(-9, 106), Pair(-456, 3), Pair(-9, 57), Pair(-7, 70), Pair(-6, 66), Pair(-8, 59),
        Pair(-1, 68), Pair(-28, 39), Pair(-2, 85), Pair(-44, 53), Pair(-6, 68), Pair(-22, 54), Pair(7, 52), Pair(25, 53),
        Pair(-11, 39), Pair(-24, 69), Pair(-20, 33), Pair(-35, 59), Pair(-17, 42), Pair(-11, 63), Pair(-3, 55), Pair(-2, 57),
        Pair(-10, 71), Pair(-8, 78), Pair(-11, 64), Pair(-7, 81), Pair(-16, 49), Pair(-3, 54), Pair(-3, 64), Pair(-1, 57),
        Pair(2, 71), Pair(-4, 66), Pair(-10, 76), Pair(-2, 54), Pair(-2, 50), Pair(-3, 62), Pair(5, 48), Pair(6, 40),
        Pair(-31, 81), Pair(-1, 72), Pair(24, 48), Pair(-6, 65), Pair(15, 72), Pair(9, 42), Pair(-5, 63), Pair(10, 22)
      },
      { // Piece 2
        Pair(-24, 76), Pair(14, -14), Pair(-42, 125), Pair(-147, 123), Pair(-27, 122), Pair(-77, 106), Pair(-136, 107), Pair(-27, 111),
        Pair(-5, 16), Pair(-33, 75), Pair(0, 0), Pair(-52, 102), Pair(-77, 110), Pair(-1, 94), Pair(-16, 97), Pair(2, 80),
        Pair(-21, 76), Pair(-106, -66), Pair(-17, 111), Pair(-505, -132), Pair(-9, 87), Pair(-54, 96), Pair(11, 86), Pair(-31, 73),
        Pair(-18, 47), Pair(-25, 70), Pair(-16, 73), Pair(-55, 81), Pair(-18, 63), Pair(-35, 89), Pair(-10, 72), Pair(5, 93),
        Pair(8, 75), Pair(-35, 75), Pair(-13, 79), Pair(-50, 71), Pair(-8, 82), Pair(-17, 62), Pair(-3, 75), Pair(1, 46),
        Pair(-14, 52), Pair(-19, 89), Pair(-13, 72), Pair(-10, 79), Pair(-15, 55), Pair(-9, 71), Pair(-6, 60), Pair(2, 62),
        Pair(-26, 107), Pair(-1, 58), Pair(7, 79), Pair(-8, 68), Pair(-3, 74), Pair(-3, 70), Pair(3, 64), Pair(-5, 77),
        Pair(0, 59), Pair(-11, 84), Pair(-4, 64), Pair(-3, 92), Pair(-11, 60), Pair(-3, 83), Pair(-11, 73), Pair(-9, 93)
      },
      { // Piece 3
        Pair(-74, 96), Pair(-73, 95), Pair(-132, 100), Pair(-131, 108), Pair(-46, 102), Pair(-60, 122), Pair(-80, 101), Pair(-134, 132),
        Pair(-14, 64), Pair(-55, 75), Pair(0, 0), Pair(-45, 86), Pair(-34, 115), Pair(-39, 103), Pair(-53, 100), Pair(-17, 85),
        Pair(-14, 67), Pair(-30, -274), Pair(-18, 80), Pair(-281, -7), Pair(-3, 69), Pair(-20, 79), Pair(-34, 74), Pair(-35, 86),
        Pair(-30, 86), Pair(-32, 67), Pair(-23, 88), Pair(-52, 77), Pair(-24, 84), Pair(-28, 90), Pair(-14, 77), Pair(-7, 72),
        Pair(-18, 74), Pair(-46, 67), Pair(-18, 66), Pair(-45, 72), Pair(-20, 79), Pair(-30, 78), Pair(-21, 81), Pair(-10, 84),
        Pair(-12, 81), Pair(-29, 87), Pair(-30, 91), Pair(-42, 80), Pair(-28, 85), Pair(-19, 86), Pair(-33, 79), Pair(-2, 88),
        Pair(-29, 87), Pair(-13, 62), Pair(-10, 74), Pair(-37, 77), Pair(-20, 74), Pair(-16, 86), Pair(-20, 85), Pair(-10, 73),
        Pair(-24, 81), Pair(-26, 77), Pair(-24, 82), Pair(-24, 72), Pair(-21, 80), Pair(-19, 88), Pair(-13, 85), Pair(-14, 89)
      },
      { // Piece 4
        Pair(44, 96), Pair(-47, 145), Pair(27, 121), Pair(-35, 171), Pair(-54, 187), Pair(-66, 226), Pair(-48, 206), Pair(12, 113),
        Pair(20, 149), Pair(2, 131), Pair(0, 0), Pair(20, 111), Pair(-8, 178), Pair(-14, 161), Pair(-11, 88), Pair(5, 117),
        Pair(32, 128), Pair(-134, 49), Pair(19, 147), Pair(-390, -92), Pair(5, 135), Pair(-5, 147), Pair(3, 145), Pair(15, 125),
        Pair(10, 176), Pair(17, 137), Pair(27, 120), Pair(16, 136), Pair(11, 134), Pair(3, 176), Pair(17, 115), Pair(9, 140),
        Pair(15, 129), Pair(1, 142), Pair(13, 159), Pair(-9, 146), Pair(7, 148), Pair(9, 126), Pair(0, 153), Pair(5, 139),
        Pair(2, 144), Pair(4, 148), Pair(23, 126), Pair(1, 140), Pair(7, 149), Pair(1, 140), Pair(13, 129), Pair(-13, 178),
        Pair(-2, 131), Pair(5, 131), Pair(15, 121), Pair(8, 130), Pair(3, 139), Pair(2, 158), Pair(4, 140), Pair(11, 57),
        Pair(-3, 158), Pair(5, 128), Pair(16, 130), Pair(4, 127), Pair(2, 138), Pair(13, 141), Pair(20, 76), Pair(-8, 114)
      },
      { // Piece 5
        Pair(0, 282), Pair(-23, -20), Pair(79, -79), Pair(-10, -56), Pair(74, -12), Pair(-70, 42), Pair(36, -8), Pair(-44, -12),
        Pair(-17, -35), Pair(116, -114), Pair(0, 0), Pair(78, -88), Pair(-56, -2), Pair(-88, 41), Pair(-60, 28), Pair(63, 5),
        Pair(28, -13), Pair(0, 0), Pair(-245, -17), Pair(0, 0), Pair(1, -9), Pair(54, -10), Pair(68, 32), Pair(-71, 49),
        Pair(-176, 16), Pair(-93, -27), Pair(-94, -38), Pair(-48, -36), Pair(-52, 1), Pair(10, 11), Pair(-17, 8), Pair(4, 13),
        Pair(-41, 3), Pair(-17, -30), Pair(-108, -19), Pair(-18, -17), Pair(25, -10), Pair(33, 16), Pair(-23, 3), Pair(-47, -6),
        Pair(34, -17), Pair(-20, -23), Pair(0, -32), Pair(-10, -3), Pair(-21, 5), Pair(3, -2), Pair(12, -1), Pair(17, -7),
        Pair(-30, 16), Pair(-1, -10), Pair(18, -18), Pair(10, -17), Pair(4, 10), Pair(20, -10), Pair(-2, 1), Pair(9, -2),
        Pair(16, -28), Pair(8, -26), Pair(8, -6), Pair(15, -26), Pair(7, 17), Pair(5, 3), Pair(1, 0), Pair(3, -11)
      }
    }},
    {{ // Bucket 51
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-21, 19), Pair(-34, 51), Pair(5, 43), Pair(0, 0), Pair(-11, -4), Pair(72, -35), Pair(25, -27), Pair(-17, 55),
        Pair(7, 3), Pair(2, -5), Pair(-9, 34), Pair(11, -50), Pair(-6, -11), Pair(-13, 14), Pair(7, 8), Pair(1, 16),
        Pair(3, 7), Pair(-1, 11), Pair(7, 14), Pair(6, -6), Pair(10, 12), Pair(-2, 3), Pair(4, -8), Pair(1, 13),
        Pair(8, 0), Pair(4, -11), Pair(12, 3), Pair(0, -10), Pair(4, 1), Pair(-1, -2), Pair(1, -4), Pair(0, 12),
        Pair(4, 3), Pair(7, -6), Pair(5, -4), Pair(-2, 4), Pair(-1, -1), Pair(0, 2), Pair(1, -1), Pair(3, -2),
        Pair(3, -1), Pair(8, -12), Pair(4, -1), Pair(0, 0), Pair(-1, 1), Pair(-2, -4), Pair(0, -1), Pair(1, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(19, 105), Pair(36, -269), Pair(37, 37), Pair(-12, -91), Pair(31, 3), Pair(3, 11), Pair(-104, 45), Pair(93, -45),
        Pair(20, 7), Pair(-33, 54), Pair(4, 38), Pair(0, 0), Pair(-73, -6), Pair(-56, 112), Pair(17, -15), Pair(44, -40),
        Pair(-68, 95), Pair(17, 59), Pair(-329, -134), Pair(27, 39), Pair(-144, -31), Pair(5, 47), Pair(7, -11), Pair(55, 40),
        Pair(2, 34), Pair(4, 47), Pair(-38, 43), Pair(4, 67), Pair(-38, 28), Pair(2, 23), Pair(6, 1), Pair(-12, 7),
        Pair(15, 29), Pair(-31, 26), Pair(-17, 37), Pair(-6, 2), Pair(-17, 27), Pair(4, 36), Pair(9, 2), Pair(15, 14),
        Pair(16, 16), Pair(-6, 44), Pair(3, 40), Pair(-8, 57), Pair(-3, 43), Pair(1, 3), Pair(3, 15), Pair(8, 60),
        Pair(44, 48), Pair(5, 1), Pair(24, 4), Pair(3, 45), Pair(9, 36), Pair(8, 22), Pair(18, 2), Pair(-8, 2),
        Pair(-19, -50), Pair(13, 34), Pair(-19, 57), Pair(-22, 79), Pair(12, 9), Pair(10, 33), Pair(1, -2), Pair(-65, 150)
      },
      { // Piece 2
        Pair(59, -16), Pair(-88, 75), Pair(27, -10), Pair(-40, 71), Pair(-43, 48), Pair(7, 5), Pair(98, -68), Pair(84, -3),
        Pair(-48, 124), Pair(-143, 99), Pair(-15, 79), Pair(0, 0), Pair(-94, 77), Pair(-17, 77), Pair(-39, 114), Pair(2, 11),
        Pair(-14, 13), Pair(-49, 76), Pair(-323, -510), Pair(24, 57), Pair(-72, -114), Pair(-27, 83), Pair(19, -7), Pair(-10, 82),
        Pair(-7, 36), Pair(-27, 19), Pair(-54, 78), Pair(-13, 55), Pair(-25, 54), Pair(-2, 17), Pair(3, 52), Pair(-12, 40),
        Pair(-33, 35), Pair(-41, 45), Pair(-47, 38), Pair(-7, 60), Pair(-38, 44), Pair(1, 66), Pair(-30, 42), Pair(-13, 43),
        Pair(-2, 70), Pair(-28, 26), Pair(-6, 69), Pair(-15, 47), Pair(2, 37), Pair(-24, 44), Pair(13, 21), Pair(-10, 43),
        Pair(-36, 66), Pair(0, 59), Pair(-5, 63), Pair(8, 40), Pair(-10, 30), Pair(1, 41), Pair(1, 40), Pair(-11, 85),
        Pair(-3, 56), Pair(-8, 12), Pair(9, 48), Pair(-24, 50), Pair(-10, 43), Pair(-7, 36), Pair(-22, 68), Pair(-14, 53)
      },
      { // Piece 3
        Pair(-264, 111), Pair(-25, 69), Pair(35, -5), Pair(-84, 54), Pair(-26, 31), Pair(24, 42), Pair(-173, 109), Pair(-97, 65),
        Pair(-10, 28), Pair(-51, 60), Pair(0, 11), Pair(0, 0), Pair(23, 23), Pair(42, 55), Pair(-50, 64), Pair(-20, 19),
        Pair(-32, 56), Pair(-25, 3), Pair(-221, 171), Pair(52, -4), Pair(4, 15), Pair(1, 46), Pair(24, 42), Pair(-38, 54),
        Pair(-45, 54), Pair(-1, 14), Pair(-39, 46), Pair(-18, 4), Pair(-27, 38), Pair(-16, 27), Pair(-20, 65), Pair(-12, 45),
        Pair(-26, 51), Pair(-51, 60), Pair(-36, 16), Pair(-6, 11), Pair(-43, 18), Pair(-33, 60), Pair(-30, 45), Pair(-6, 40),
        Pair(4, 53), Pair(-18, 38), Pair(-13, 37), Pair(-5, 22), Pair(-46, 10), Pair(-19, 60), Pair(-14, 43), Pair(-31, 101),
        Pair(13, 14), Pair(-6, -17), Pair(-21, 37), Pair(-13, 11), Pair(-13, 2), Pair(-15, 25), Pair(-20, 61), Pair(-22, 79),
        Pair(-17, 52), Pair(-7, 27), Pair(-17, 9), Pair(-24, 38), Pair(-19, 31), Pair(-18, 40), Pair(-11, 45), Pair(-13, 43)
      },
      { // Piece 4
        Pair(14, 29), Pair(92, -19), Pair(93, -92), Pair(110, -74), Pair(-66, 160), Pair(-44, 104), Pair(91, 2), Pair(101, -62),
        Pair(53, 15), Pair(-35, 109), Pair(14, 1), Pair(0, 0), Pair(-29, 60), Pair(-19, 57), Pair(2, 100), Pair(-18, 158),
        Pair(10, 53), Pair(25, 35), Pair(75, -4), Pair(27, 103), Pair(-81, -44), Pair(-8, 58), Pair(23, 34), Pair(-8, 113),
        Pair(63, 39), Pair(25, 59), Pair(-5, 71), Pair(53, -35), Pair(26, 47), Pair(39, 10), Pair(18, 68), Pair(27, 42),
        Pair(0, 68), Pair(15, 32), Pair(16, 42), Pair(16, 65), Pair(7, 73), Pair(17, 68), Pair(-14, 129), Pair(-2, 60),
        Pair(5, 98), Pair(7, 68), Pair(10, 25), Pair(13, 53), Pair(12, 37), Pair(3, 52), Pair(0, 57), Pair(21, 115),
        Pair(15, -46), Pair(3, 67), Pair(1, 34), Pair(13, 57), Pair(3, 64), Pair(-1, 46), Pair(-3, 149), Pair(6, 1),
        Pair(-19, 46), Pair(9, 44), Pair(-3, 69), Pair(13, 43), Pair(3, 55), Pair(14, 28), Pair(21, 86), Pair(44, 23)
      },
      { // Piece 5
        Pair(-29, 169), Pair(24, -60), Pair(33, 155), Pair(-26, -57), Pair(-15, 6), Pair(9, 111), Pair(13, -96), Pair(-64, -102),
        Pair(34, -39), Pair(-60, 3), Pair(64, -8), Pair(0, 0), Pair(-51, -33), Pair(-10, 41), Pair(27, -82), Pair(-93, -103),
        Pair(-48, -4), Pair(11, 55), Pair(0, 0), Pair(-4, -36), Pair(0, 0), Pair(-75, -5), Pair(158, -28), Pair(-48, -11),
        Pair(52, 47), Pair(-164, 94), Pair(-202, 2), Pair(31, -75), Pair(181, -78), Pair(144, -60), Pair(-29, 20), Pair(19, -38),
        Pair(29, -52), Pair(-8, 9), Pair(149, -66), Pair(-20, -12), Pair(14, -25), Pair(-56, 21), Pair(6, -21), Pair(169, -65),
        Pair(-186, 62), Pair(-12, 24), Pair(0, -24), Pair(5, -29), Pair(-15, 10), Pair(-12, 22), Pair(15, 2), Pair(-27, 39),
        Pair(44, -3), Pair(22, 17), Pair(2, -18), Pair(31, -13), Pair(-16, 10), Pair(5, -4), Pair(14, 1), Pair(8, 3),
        Pair(-4, 24), Pair(10, 10), Pair(0, 2), Pair(14, -17), Pair(0, -4), Pair(26, 11), Pair(0, 16), Pair(0, -4)
      }
    }},
    {{ // Bucket 52
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-30, 27), Pair(-17, 26), Pair(6, 14), Pair(-5, 0), Pair(0, 0), Pair(-8, 17), Pair(51, 21), Pair(-50, 33),
        Pair(5, 3), Pair(3, 13), Pair(-1, 2), Pair(-11, 33), Pair(-13, -31), Pair(-11, -1), Pair(14, 9), Pair(1, 13),
        Pair(5, 9), Pair(2, 15), Pair(-5, 8), Pair(21, 7), Pair(-2, 2), Pair(12, 17), Pair(5, 5), Pair(5, 0),
        Pair(5, 6), Pair(0, 1), Pair(0, 3), Pair(4, 3), Pair(-4, -6), Pair(2, 0), Pair(2, 3), Pair(0, 7),
        Pair(4, 3), Pair(6, 4), Pair(-3, 0), Pair(4, 6), Pair(-6, 0), Pair(-2, -4), Pair(-1, 3), Pair(0, 1),
        Pair(3, 2), Pair(3, 8), Pair(2, 3), Pair(4, -2), Pair(0, 0), Pair(-3, -5), Pair(-1, 1), Pair(-1, 9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-18, 21), Pair(0, 3), Pair(-57, 78), Pair(-103, 114), Pair(-42, -71), Pair(-31, 72), Pair(-74, -25), Pair(128, 14),
        Pair(-1, 72), Pair(-15, 16), Pair(-22, 47), Pair(-58, 52), Pair(0, 0), Pair(-70, 51), Pair(-20, 69), Pair(-29, -7),
        Pair(13, 32), Pair(1, 57), Pair(-2, 27), Pair(-169, -46), Pair(21, 52), Pair(-400, 181), Pair(-44, 20), Pair(-23, 16),
        Pair(-5, 49), Pair(-11, 26), Pair(5, 39), Pair(-41, 0), Pair(-13, 46), Pair(-58, 33), Pair(-1, 20), Pair(22, 25),
        Pair(-7, 63), Pair(-4, 32), Pair(-14, 36), Pair(-29, 28), Pair(-10, -4), Pair(-12, 23), Pair(7, 3), Pair(5, 17),
        Pair(-1, 29), Pair(-2, 45), Pair(-9, 26), Pair(-9, 37), Pair(-21, 33), Pair(-5, 32), Pair(-17, 25), Pair(-2, 30),
        Pair(-7, 64), Pair(19, -5), Pair(-4, 36), Pair(2, 28), Pair(-7, 41), Pair(-16, 54), Pair(-7, 9), Pair(13, 14),
        Pair(84, -66), Pair(5, 39), Pair(3, 48), Pair(12, 23), Pair(12, 36), Pair(7, 23), Pair(0, 46), Pair(11, -86)
      },
      { // Piece 2
        Pair(24, 49), Pair(-41, 96), Pair(-82, 53), Pair(-89, 77), Pair(-129, 102), Pair(-176, -1), Pair(38, 62), Pair(74, -22),
        Pair(-33, 72), Pair(-10, 54), Pair(-22, 46), Pair(-181, 125), Pair(0, 0), Pair(-7, 74), Pair(-225, 9), Pair(-10, 58),
        Pair(-3, 89), Pair(-30, 69), Pair(-36, 69), Pair(-321, 79), Pair(35, 65), Pair(-355, 103), Pair(-8, 66), Pair(-32, 46),
        Pair(-11, 53), Pair(-11, 69), Pair(11, 48), Pair(-60, 78), Pair(-11, 13), Pair(-69, 92), Pair(-9, 1), Pair(-12, 63),
        Pair(-25, 90), Pair(4, 22), Pair(-26, 70), Pair(-30, 22), Pair(-11, 61), Pair(-21, 29), Pair(-35, 58), Pair(-10, 13),
        Pair(-2, 24), Pair(-29, 69), Pair(-24, 57), Pair(-12, 59), Pair(-15, 37), Pair(-9, 61), Pair(-10, 19), Pair(-7, 52),
        Pair(-17, 66), Pair(-12, 31), Pair(-2, 50), Pair(-12, 28), Pair(-2, 61), Pair(-18, 58), Pair(-3, 47), Pair(-21, 42),
        Pair(-16, 19), Pair(-2, 65), Pair(-9, 43), Pair(-10, 55), Pair(-4, 45), Pair(-2, 60), Pair(-31, 52), Pair(3, 102)
      },
      { // Piece 3
        Pair(-65, 74), Pair(-51, 55), Pair(-85, 85), Pair(-66, 64), Pair(11, 53), Pair(-52, 30), Pair(-46, 49), Pair(-151, 92),
        Pair(-9, 36), Pair(-7, 55), Pair(-12, 53), Pair(-57, 64), Pair(0, 0), Pair(-5, 68), Pair(-8, 45), Pair(-74, 28),
        Pair(4, 33), Pair(-17, 44), Pair(-15, 36), Pair(-307, -87), Pair(38, 18), Pair(-165, -311), Pair(-49, 43), Pair(-17, 42),
        Pair(-2, 48), Pair(-17, 43), Pair(6, 26), Pair(-33, 19), Pair(22, 26), Pair(-32, 33), Pair(-7, 30), Pair(3, 8),
        Pair(-17, 46), Pair(-6, 59), Pair(-15, 52), Pair(-23, 28), Pair(9, 25), Pair(8, 7), Pair(-27, 58), Pair(-2, 20),
        Pair(-26, 46), Pair(-20, 22), Pair(-14, 32), Pair(-13, 24), Pair(-21, 29), Pair(6, -11), Pair(-8, 20), Pair(-25, 65),
        Pair(11, 77), Pair(-10, 38), Pair(-11, 28), Pair(-14, 22), Pair(-3, 7), Pair(5, 3), Pair(-10, 55), Pair(13, 21),
        Pair(-2, 36), Pair(-6, 43), Pair(-2, 33), Pair(-8, 25), Pair(0, 35), Pair(-2, 32), Pair(-10, 18), Pair(3, 51)
      },
      { // Piece 4
        Pair(36, 33), Pair(21, 71), Pair(39, 35), Pair(11, -4), Pair(43, 42), Pair(9, 16), Pair(-87, 98), Pair(-53, 164),
        Pair(29, 44), Pair(12, 83), Pair(30, 39), Pair(-3, -2), Pair(0, 0), Pair(-19, 34), Pair(33, -11), Pair(-42, 107),
        Pair(43, 17), Pair(8, 83), Pair(24, 42), Pair(43, 11), Pair(73, 10), Pair(-121, -91), Pair(-18, 77), Pair(11, 112),
        Pair(24, 42), Pair(30, 67), Pair(13, 34), Pair(12, 33), Pair(29, 46), Pair(13, 86), Pair(17, 45), Pair(52, 29),
        Pair(12, 16), Pair(12, 77), Pair(4, 92), Pair(12, 41), Pair(14, 63), Pair(27, 45), Pair(10, 46), Pair(29, 31),
        Pair(26, 49), Pair(-3, 80), Pair(4, 56), Pair(9, 53), Pair(6, 63), Pair(12, 47), Pair(20, 27), Pair(24, 36),
        Pair(25, 83), Pair(5, 70), Pair(5, 51), Pair(-1, 54), Pair(17, 51), Pair(-1, 52), Pair(-1, 82), Pair(-12, 81),
        Pair(6, 59), Pair(6, 43), Pair(10, 44), Pair(4, 64), Pair(13, 50), Pair(12, 57), Pair(71, -3), Pair(15, -10)
      },
      { // Piece 5
        Pair(-26, 122), Pair(14, 50), Pair(-29, 37), Pair(7, 47), Pair(-12, -25), Pair(18, -78), Pair(7, 38), Pair(7, 103),
        Pair(40, 69), Pair(-32, 47), Pair(75, 2), Pair(-50, -139), Pair(0, 0), Pair(134, -54), Pair(-184, 2), Pair(27, 33),
        Pair(-129, 33), Pair(-25, 65), Pair(-51, 6), Pair(0, 0), Pair(175, -97), Pair(0, 0), Pair(-53, 2), Pair(259, -48),
        Pair(152, 17), Pair(-152, 56), Pair(-170, 21), Pair(9, -25), Pair(11, -71), Pair(115, -36), Pair(-69, 13), Pair(-86, 24),
        Pair(-108, 6), Pair(-14, 31), Pair(-57, 40), Pair(-13, 14), Pair(-78, -14), Pair(-22, -9), Pair(-9, 6), Pair(-107, 18),
        Pair(32, 27), Pair(18, 9), Pair(-28, 13), Pair(22, -24), Pair(20, -16), Pair(19, -6), Pair(41, -4), Pair(-13, 20),
        Pair(-66, 27), Pair(-24, 10), Pair(-8, 24), Pair(22, -8), Pair(11, 0), Pair(23, -11), Pair(3, 12), Pair(7, 0),
        Pair(-10, 9), Pair(-25, 16), Pair(-14, 28), Pair(-5, 21), Pair(-5, -10), Pair(5, -16), Pair(-2, 7), Pair(0, 12)
      }
    }},
    {{ // Bucket 53
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-14, 32), Pair(-4, 20), Pair(15, 18), Pair(6, 5), Pair(-9, 25), Pair(0, 0), Pair(-17, 3), Pair(1, 24),
        Pair(3, 15), Pair(6, 14), Pair(13, 9), Pair(4, 2), Pair(15, 9), Pair(-13, -8), Pair(-1, 15), Pair(3, 16),
        Pair(4, 6), Pair(4, 6), Pair(8, 5), Pair(4, 3), Pair(11, 12), Pair(-6, 2), Pair(5, 8), Pair(-3, 9),
        Pair(7, 2), Pair(4, 3), Pair(4, 5), Pair(2, -2), Pair(7, 7), Pair(-10, 1), Pair(0, 2), Pair(-3, 8),
        Pair(6, 3), Pair(7, 3), Pair(2, 1), Pair(5, 2), Pair(4, 6), Pair(-7, 3), Pair(-6, 6), Pair(-5, 4),
        Pair(4, 5), Pair(9, 2), Pair(5, -1), Pair(-2, 2), Pair(3, 7), Pair(0, 0), Pair(-6, -2), Pair(-2, 4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-47, 98), Pair(-86, 111), Pair(-63, 102), Pair(-97, 81), Pair(-2, 86), Pair(-44, -16), Pair(-43, 131), Pair(95, -62),
        Pair(-22, 102), Pair(7, 79), Pair(-10, 74), Pair(-48, 101), Pair(-45, 80), Pair(0, 0), Pair(-17, 30), Pair(-10, 81),
        Pair(-14, 95), Pair(-4, 88), Pair(-3, 83), Pair(-4, 65), Pair(-415, 7), Pair(4, 114), Pair(-210, 59), Pair(-23, 61),
        Pair(24, 81), Pair(0, 82), Pair(-8, 58), Pair(-11, 86), Pair(-51, 58), Pair(17, 81), Pair(-36, 23), Pair(7, 72),
        Pair(5, 81), Pair(-3, 81), Pair(-3, 75), Pair(-16, 68), Pair(-37, 71), Pair(-26, 52), Pair(-13, 70), Pair(-15, 70),
        Pair(12, 85), Pair(-2, 74), Pair(1, 78), Pair(-9, 72), Pair(-5, 81), Pair(-6, 64), Pair(-9, 77), Pair(-18, 81),
        Pair(21, 81), Pair(10, 82), Pair(0, 74), Pair(2, 74), Pair(-3, 75), Pair(-5, 68), Pair(-3, 68), Pair(8, 79),
        Pair(36, 34), Pair(12, 83), Pair(-1, 71), Pair(13, 85), Pair(6, 82), Pair(10, 77), Pair(-2, 69), Pair(14, 52)
      },
      { // Piece 2
        Pair(-42, 96), Pair(-12, 101), Pair(-77, 103), Pair(-44, 123), Pair(-117, 77), Pair(-76, 110), Pair(-160, -6), Pair(-50, 88),
        Pair(-8, 96), Pair(-37, 92), Pair(6, 108), Pair(-95, 106), Pair(-45, 133), Pair(0, 0), Pair(-20, 106), Pair(12, 68),
        Pair(-40, 98), Pair(0, 108), Pair(-47, 107), Pair(-13, 103), Pair(-330, -246), Pair(4, 141), Pair(-140, -52), Pair(9, 87),
        Pair(-1, 100), Pair(-25, 91), Pair(-16, 116), Pair(-35, 71), Pair(-47, 93), Pair(-33, 80), Pair(-11, 84), Pair(-34, 68),
        Pair(-11, 82), Pair(-3, 103), Pair(-37, 76), Pair(-11, 95), Pair(-57, 77), Pair(-11, 95), Pair(-40, 72), Pair(0, 83),
        Pair(-2, 87), Pair(-24, 77), Pair(-5, 97), Pair(-27, 75), Pair(-6, 92), Pair(-21, 80), Pair(-12, 96), Pair(-30, 73),
        Pair(-24, 77), Pair(7, 79), Pair(-28, 92), Pair(-1, 91), Pair(-21, 73), Pair(0, 98), Pair(-21, 68), Pair(-14, 89),
        Pair(9, 79), Pair(-40, 97), Pair(8, 88), Pair(-9, 80), Pair(9, 96), Pair(-15, 86), Pair(-13, 100), Pair(-9, 106)
      },
      { // Piece 3
        Pair(-41, 124), Pair(-39, 125), Pair(-74, 132), Pair(-52, 130), Pair(-68, 126), Pair(-49, 107), Pair(-59, 117), Pair(-74, 135),
        Pair(-5, 105), Pair(-17, 109), Pair(-17, 109), Pair(-16, 114), Pair(-21, 103), Pair(0, 0), Pair(-55, 107), Pair(-25, 94),
        Pair(-5, 98), Pair(-16, 110), Pair(-8, 107), Pair(4, 102), Pair(-288, -69), Pair(30, 95), Pair(-32, -174), Pair(2, 91),
        Pair(16, 96), Pair(-1, 102), Pair(6, 101), Pair(-14, 109), Pair(-12, 106), Pair(10, 92), Pair(8, 82), Pair(2, 89),
        Pair(15, 103), Pair(4, 103), Pair(-2, 99), Pair(-9, 101), Pair(-15, 79), Pair(-4, 91), Pair(-14, 86), Pair(-9, 98),
        Pair(22, 102), Pair(9, 104), Pair(-9, 105), Pair(-4, 103), Pair(1, 99), Pair(17, 95), Pair(4, 93), Pair(8, 100),
        Pair(9, 105), Pair(2, 104), Pair(15, 98), Pair(5, 105), Pair(6, 85), Pair(16, 89), Pair(25, 77), Pair(1, 105),
        Pair(9, 109), Pair(5, 108), Pair(8, 99), Pair(4, 101), Pair(2, 91), Pair(6, 103), Pair(-5, 101), Pair(6, 95)
      },
      { // Piece 4
        Pair(17, 171), Pair(33, 179), Pair(-9, 182), Pair(-23, 191), Pair(-30, 139), Pair(21, 59), Pair(-29, 233), Pair(18, 143),
        Pair(20, 158), Pair(10, 160), Pair(33, 140), Pair(23, 105), Pair(4, 86), Pair(0, 0), Pair(15, 171), Pair(3, 169),
        Pair(31, 124), Pair(16, 155), Pair(13, 144), Pair(25, 139), Pair(-155, -39), Pair(59, 88), Pair(-32, 227), Pair(54, 162),
        Pair(21, 159), Pair(11, 176), Pair(14, 175), Pair(29, 124), Pair(16, 154), Pair(55, 104), Pair(41, 168), Pair(33, 140),
        Pair(11, 160), Pair(15, 171), Pair(15, 155), Pair(8, 178), Pair(8, 150), Pair(38, 126), Pair(20, 176), Pair(26, 175),
        Pair(8, 182), Pair(13, 160), Pair(15, 160), Pair(6, 171), Pair(17, 147), Pair(30, 134), Pair(27, 180), Pair(38, 118),
        Pair(-2, 156), Pair(20, 155), Pair(16, 153), Pair(15, 159), Pair(14, 160), Pair(29, 141), Pair(18, 185), Pair(38, 170),
        Pair(20, 155), Pair(19, 153), Pair(31, 130), Pair(16, 154), Pair(26, 146), Pair(25, 155), Pair(1, 197), Pair(66, 99)
      },
      { // Piece 5
        Pair(-26, 16), Pair(159, -39), Pair(-60, -15), Pair(165, -79), Pair(-68, -17), Pair(141, -105), Pair(29, -82), Pair(-52, 19),
        Pair(172, -32), Pair(55, -15), Pair(-1, 5), Pair(74, -25), Pair(-57, -73), Pair(0, 0), Pair(77, -79), Pair(23, 7),
        Pair(83, 6), Pair(-36, 24), Pair(38, -2), Pair(-18, -20), Pair(0, 0), Pair(-52, -45), Pair(0, 0), Pair(7, 5),
        Pair(79, 0), Pair(65, -2), Pair(40, -3), Pair(35, -33), Pair(19, -42), Pair(18, -47), Pair(-52, -16), Pair(-67, -7),
        Pair(66, -31), Pair(1, 7), Pair(63, -13), Pair(45, -9), Pair(21, -28), Pair(-40, -17), Pair(10, -17), Pair(-38, 1),
        Pair(7, 7), Pair(47, -12), Pair(-10, 10), Pair(32, -3), Pair(-1, -6), Pair(19, -17), Pair(1, -6), Pair(17, -2),
        Pair(-48, -2), Pair(-10, 8), Pair(6, 0), Pair(3, 8), Pair(2, 0), Pair(7, 5), Pair(-2, 0), Pair(5, 1),
        Pair(-16, 9), Pair(-16, 4), Pair(-21, 11), Pair(-4, 17), Pair(-10, -8), Pair(1, 3), Pair(-13, -14), Pair(12, 0)
      }
    }},
    {{ // Bucket 54
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(24, 16), Pair(13, 19), Pair(21, 14), Pair(3, 19), Pair(-21, 11), Pair(-46, 25), Pair(0, 0), Pair(-48, -3),
        Pair(10, 12), Pair(10, 5), Pair(7, 12), Pair(-2, 8), Pair(-11, 2), Pair(-14, 9), Pair(0, -18), Pair(23, 16),
        Pair(0, 8), Pair(6, 5), Pair(5, 5), Pair(-1, 8), Pair(1, 4), Pair(-1, 15), Pair(3, 0), Pair(15, 15),
        Pair(7, 4), Pair(7, 6), Pair(3, 5), Pair(-1, 1), Pair(1, 6), Pair(2, 7), Pair(-2, -4), Pair(-1, 7),
        Pair(1, -1), Pair(2, -3), Pair(0, -3), Pair(0, -1), Pair(-1, -1), Pair(0, 6), Pair(-6, 2), Pair(-5, 4),
        Pair(0, 2), Pair(3, -2), Pair(-1, 0), Pair(-3, -1), Pair(-2, -1), Pair(4, 0), Pair(0, 0), Pair(-7, -1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-5, 38), Pair(-93, 86), Pair(-34, 58), Pair(-98, 113), Pair(-94, 62), Pair(-72, 81), Pair(55, -14), Pair(-39, 78),
        Pair(15, 59), Pair(16, 63), Pair(17, 47), Pair(-22, 54), Pair(-45, 85), Pair(23, 53), Pair(0, 0), Pair(-35, 37),
        Pair(-11, 64), Pair(20, 56), Pair(6, 65), Pair(-27, 54), Pair(-6, 51), Pair(-412, 57), Pair(16, 95), Pair(-38, 107),
        Pair(16, 56), Pair(14, 54), Pair(1, 61), Pair(-1, 43), Pair(-9, 66), Pair(-49, 36), Pair(-17, 85), Pair(-12, 5),
        Pair(19, 56), Pair(3, 55), Pair(8, 49), Pair(-7, 59), Pair(-6, 40), Pair(-35, 50), Pair(9, 19), Pair(-19, 53),
        Pair(16, 39), Pair(5, 52), Pair(4, 52), Pair(-2, 53), Pair(-8, 56), Pair(2, 52), Pair(-17, 43), Pair(-13, 48),
        Pair(16, 54), Pair(29, 49), Pair(2, 45), Pair(5, 57), Pair(-6, 54), Pair(3, 47), Pair(12, 56), Pair(17, 43),
        Pair(6, 37), Pair(13, 73), Pair(10, 60), Pair(28, 53), Pair(18, 42), Pair(14, 51), Pair(-3, 63), Pair(-7, 67)
      },
      { // Piece 2
        Pair(-25, 95), Pair(-52, 94), Pair(-86, 108), Pair(-39, 83), Pair(-121, 117), Pair(-106, 78), Pair(135, 52), Pair(9, 0),
        Pair(-35, 77), Pair(16, 95), Pair(-10, 76), Pair(-32, 115), Pair(-127, 100), Pair(-21, 106), Pair(0, 0), Pair(16, 60),
        Pair(-7, 106), Pair(-41, 85), Pair(-3, 96), Pair(-43, 84), Pair(-22, 84), Pair(-309, -144), Pair(5, 121), Pair(-133, 42),
        Pair(-25, 73), Pair(6, 86), Pair(-30, 70), Pair(-11, 96), Pair(-28, 47), Pair(-53, 90), Pair(-11, 53), Pair(-19, 89),
        Pair(9, 89), Pair(-24, 76), Pair(1, 88), Pair(-29, 53), Pair(-11, 79), Pair(-37, 49), Pair(-16, 98), Pair(-28, 41),
        Pair(-5, 55), Pair(18, 86), Pair(-15, 49), Pair(-3, 74), Pair(-15, 55), Pair(9, 76), Pair(-12, 59), Pair(0, 80),
        Pair(4, 79), Pair(-13, 42), Pair(5, 72), Pair(-13, 49), Pair(6, 77), Pair(-22, 71), Pair(12, 77), Pair(-13, 58),
        Pair(-13, 47), Pair(5, 75), Pair(-8, 59), Pair(6, 81), Pair(-10, 70), Pair(11, 89), Pair(-39, 110), Pair(9, 114)
      },
      { // Piece 3
        Pair(-18, 109), Pair(-22, 123), Pair(-46, 116), Pair(-35, 117), Pair(-39, 109), Pair(-76, 114), Pair(-21, 125), Pair(18, 94),
        Pair(2, 92), Pair(6, 97), Pair(-26, 113), Pair(-26, 109), Pair(-9, 103), Pair(-22, 93), Pair(0, 0), Pair(-18, 98),
        Pair(4, 92), Pair(-17, 102), Pair(-7, 96), Pair(-23, 100), Pair(1, 80), Pair(-152, -5), Pair(-16, 101), Pair(207, -230),
        Pair(15, 92), Pair(-3, 95), Pair(11, 94), Pair(-5, 100), Pair(0, 90), Pair(-24, 93), Pair(-24, 102), Pair(-21, 100),
        Pair(1, 99), Pair(9, 94), Pair(10, 84), Pair(2, 90), Pair(-5, 80), Pair(-11, 65), Pair(-8, 82), Pair(-8, 63),
        Pair(17, 85), Pair(9, 83), Pair(5, 88), Pair(8, 91), Pair(6, 89), Pair(12, 67), Pair(0, 70), Pair(6, 74),
        Pair(41, 90), Pair(13, 95), Pair(19, 84), Pair(20, 85), Pair(26, 72), Pair(12, 82), Pair(-1, 73), Pair(7, 69),
        Pair(21, 93), Pair(11, 92), Pair(11, 92), Pair(11, 88), Pair(10, 85), Pair(9, 83), Pair(4, 74), Pair(4, 86)
      },
      { // Piece 4
        Pair(-35, 186), Pair(-43, 190), Pair(-32, 204), Pair(0, 158), Pair(1, 187), Pair(-16, 125), Pair(10, 147), Pair(46, 87),
        Pair(8, 137), Pair(-4, 156), Pair(-9, 152), Pair(-31, 171), Pair(-59, 181), Pair(35, 61), Pair(0, 0), Pair(38, 108),
        Pair(9, 114), Pair(15, 130), Pair(-6, 141), Pair(-5, 138), Pair(33, 90), Pair(-49, -219), Pair(23, 103), Pair(-10, -43),
        Pair(13, 129), Pair(-7, 156), Pair(-3, 154), Pair(-10, 178), Pair(-11, 126), Pair(-19, 158), Pair(-11, 118), Pair(0, 142),
        Pair(11, 134), Pair(-9, 157), Pair(-8, 146), Pair(-8, 142), Pair(-8, 161), Pair(0, 131), Pair(0, 122), Pair(-8, 147),
        Pair(5, 170), Pair(-9, 167), Pair(1, 145), Pair(-10, 154), Pair(-6, 149), Pair(-4, 149), Pair(15, 112), Pair(13, 126),
        Pair(-3, 142), Pair(-1, 145), Pair(-2, 126), Pair(-8, 157), Pair(-2, 136), Pair(-4, 148), Pair(8, 120), Pair(8, 161),
        Pair(7, 131), Pair(3, 115), Pair(9, 129), Pair(2, 139), Pair(1, 140), Pair(-9, 141), Pair(-23, 140), Pair(-35, 186)
      },
      { // Piece 5
        Pair(97, -3), Pair(187, -72), Pair(6, -66), Pair(-1, 2), Pair(147, -16), Pair(69, -59), Pair(207, -50), Pair(24, 15),
        Pair(-116, 49), Pair(116, -10), Pair(79, 5), Pair(150, -21), Pair(31, -2), Pair(-51, -34), Pair(0, 0), Pair(64, -43),
        Pair(191, -11), Pair(46, 9), Pair(-6, 33), Pair(102, -5), Pair(-8, -23), Pair(0, 0), Pair(-73, -27), Pair(0, 0),
        Pair(-44, 17), Pair(87, 1), Pair(82, -7), Pair(123, -6), Pair(0, -12), Pair(-30, -11), Pair(-6, -25), Pair(-31, -15),
        Pair(55, -31), Pair(80, -12), Pair(44, 2), Pair(64, -11), Pair(30, 0), Pair(27, -15), Pair(-28, -9), Pair(-56, 0),
        Pair(74, -9), Pair(45, -15), Pair(43, -10), Pair(26, 1), Pair(15, 5), Pair(4, -2), Pair(1, -8), Pair(5, 0),
        Pair(2, -10), Pair(13, -15), Pair(10, 8), Pair(13, -1), Pair(7, 13), Pair(21, -4), Pair(-1, 7), Pair(3, 1),
        Pair(23, -20), Pair(-16, 9), Pair(-14, 11), Pair(9, 11), Pair(-4, 11), Pair(-5, 5), Pair(-9, 14), Pair(1, -6)
      }
    }},
    {{ // Bucket 55
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-9, 32), Pair(2, 14), Pair(23, 5), Pair(3, 5), Pair(9, 16), Pair(-13, 37), Pair(-8, 1), Pair(0, 0),
        Pair(-2, 17), Pair(9, 7), Pair(2, 4), Pair(4, 10), Pair(-2, 5), Pair(-20, 9), Pair(-21, -5), Pair(11, -27),
        Pair(1, 10), Pair(4, 5), Pair(4, 4), Pair(-1, 3), Pair(-8, 3), Pair(-6, 4), Pair(-2, 3), Pair(7, -6),
        Pair(5, 5), Pair(1, 0), Pair(4, 0), Pair(0, 2), Pair(-4, 2), Pair(-1, 3), Pair(-3, 0), Pair(-5, 1),
        Pair(1, 1), Pair(-3, -5), Pair(-7, -2), Pair(-6, -3), Pair(3, 2), Pair(4, 3), Pair(-1, 2), Pair(-1, 2),
        Pair(2, 3), Pair(-4, -8), Pair(-1, -3), Pair(-2, -2), Pair(2, -4), Pair(7, 3), Pair(1, -4), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-3, 79), Pair(22, 46), Pair(-20, 52), Pair(95, 49), Pair(-43, 86), Pair(-131, 32), Pair(-168, 74), Pair(-92, -20),
        Pair(15, 52), Pair(29, 46), Pair(3, 68), Pair(-4, 58), Pair(19, 55), Pair(14, 71), Pair(64, 20), Pair(0, 0),
        Pair(60, 36), Pair(36, 56), Pair(0, 64), Pair(6, 64), Pair(-20, 53), Pair(-14, 60), Pair(-199, -53), Pair(36, 106),
        Pair(3, 49), Pair(15, 52), Pair(10, 60), Pair(1, 62), Pair(-5, 60), Pair(4, 69), Pair(-22, 48), Pair(32, 67),
        Pair(15, 54), Pair(38, 34), Pair(11, 53), Pair(8, 55), Pair(2, 63), Pair(9, 47), Pair(-15, 64), Pair(-8, 44),
        Pair(24, 55), Pair(18, 41), Pair(17, 50), Pair(8, 51), Pair(12, 49), Pair(7, 52), Pair(10, 61), Pair(1, 72),
        Pair(39, 30), Pair(12, 66), Pair(12, 47), Pair(14, 56), Pair(18, 58), Pair(19, 45), Pair(20, 41), Pair(28, 58),
        Pair(88, -5), Pair(21, 68), Pair(27, 42), Pair(11, 39), Pair(27, 39), Pair(15, 48), Pair(10, 56), Pair(43, 14)
      },
      { // Piece 2
        Pair(-8, 108), Pair(-57, 101), Pair(-76, 102), Pair(-50, 116), Pair(-119, 93), Pair(-59, 115), Pair(-69, 113), Pair(27, 78),
        Pair(-14, 95), Pair(12, 92), Pair(7, 89), Pair(-67, 111), Pair(-4, 98), Pair(-29, 99), Pair(-25, 86), Pair(0, 0),
        Pair(5, 82), Pair(13, 93), Pair(-14, 92), Pair(-4, 97), Pair(6, 88), Pair(-50, 113), Pair(-141, -80), Pair(28, 121),
        Pair(13, 78), Pair(3, 80), Pair(-2, 90), Pair(-6, 95), Pair(2, 87), Pair(-19, 77), Pair(-21, 83), Pair(-16, 91),
        Pair(6, 81), Pair(5, 80), Pair(-6, 86), Pair(-3, 78), Pair(-8, 82), Pair(-3, 78), Pair(-20, 74), Pair(6, 71),
        Pair(16, 80), Pair(11, 76), Pair(6, 77), Pair(-6, 74), Pair(3, 73), Pair(4, 83), Pair(3, 79), Pair(15, 75),
        Pair(5, 74), Pair(17, 68), Pair(-7, 62), Pair(3, 73), Pair(3, 76), Pair(14, 69), Pair(10, 76), Pair(17, 80),
        Pair(12, 67), Pair(-24, 69), Pair(11, 70), Pair(-7, 84), Pair(15, 81), Pair(10, 84), Pair(14, 56), Pair(-8, 123)
      },
      { // Piece 3
        Pair(-13, 137), Pair(2, 136), Pair(-31, 151), Pair(-17, 147), Pair(-33, 146), Pair(-240, 204), Pair(-28, 121), Pair(-61, 156),
        Pair(8, 129), Pair(1, 133), Pair(-5, 133), Pair(-1, 135), Pair(5, 132), Pair(45, 139), Pair(21, 130), Pair(0, 0),
        Pair(15, 127), Pair(5, 135), Pair(3, 134), Pair(-12, 145), Pair(0, 129), Pair(-20, 139), Pair(-66, -186), Pair(1, 135),
        Pair(18, 130), Pair(10, 135), Pair(9, 133), Pair(19, 115), Pair(-1, 120), Pair(-6, 124), Pair(-9, 109), Pair(-11, 120),
        Pair(36, 102), Pair(19, 124), Pair(21, 112), Pair(9, 125), Pair(13, 115), Pair(3, 114), Pair(-20, 105), Pair(-22, 112),
        Pair(30, 126), Pair(31, 115), Pair(24, 123), Pair(17, 117), Pair(12, 113), Pair(17, 110), Pair(3, 98), Pair(-16, 109),
        Pair(48, 105), Pair(29, 122), Pair(30, 116), Pair(31, 113), Pair(19, 119), Pair(25, 104), Pair(23, 145), Pair(18, 104),
        Pair(21, 123), Pair(20, 125), Pair(18, 122), Pair(15, 120), Pair(16, 117), Pair(14, 113), Pair(-17, 125), Pair(3, 120)
      },
      { // Piece 4
        Pair(-22, 247), Pair(-65, 300), Pair(-8, 235), Pair(-64, 284), Pair(-57, 264), Pair(-26, 278), Pair(62, 157), Pair(-140, 338),
        Pair(3, 246), Pair(9, 234), Pair(-16, 266), Pair(-33, 259), Pair(-21, 289), Pair(-14, 290), Pair(31, 260), Pair(0, 0),
        Pair(3, 232), Pair(3, 237), Pair(-6, 242), Pair(-18, 250), Pair(-36, 291), Pair(-40, 281), Pair(-220, 115), Pair(20, 176),
        Pair(9, 216), Pair(10, 226), Pair(-5, 245), Pair(-16, 258), Pair(-19, 265), Pair(-19, 267), Pair(-12, 232), Pair(-9, 195),
        Pair(8, 244), Pair(10, 236), Pair(-3, 229), Pair(3, 241), Pair(-5, 237), Pair(-1, 231), Pair(-4, 210), Pair(-17, 216),
        Pair(8, 237), Pair(2, 232), Pair(8, 226), Pair(3, 223), Pair(-6, 240), Pair(-2, 230), Pair(4, 231), Pair(-14, 218),
        Pair(13, 245), Pair(9, 217), Pair(7, 208), Pair(10, 215), Pair(4, 216), Pair(16, 209), Pair(17, 201), Pair(10, 184),
        Pair(5, 216), Pair(16, 199), Pair(10, 209), Pair(11, 208), Pair(18, 221), Pair(6, 249), Pair(-29, 274), Pair(-26, 256)
      },
      { // Piece 5
        Pair(23, -45), Pair(122, -21), Pair(236, -51), Pair(-98, -10), Pair(-156, 39), Pair(57, -43), Pair(-4, 0), Pair(-10, 85),
        Pair(-68, 10), Pair(138, -51), Pair(-23, -1), Pair(-95, 41), Pair(-33, 18), Pair(-112, 15), Pair(-135, -22), Pair(0, 0),
        Pair(14, -21), Pair(9, 0), Pair(-39, 16), Pair(-21, 11), Pair(-7, -23), Pair(-71, 8), Pair(0, 0), Pair(94, -38),
        Pair(131, -33), Pair(90, -8), Pair(108, -17), Pair(21, 0), Pair(95, -7), Pair(-54, 4), Pair(5, -6), Pair(2, -16),
        Pair(54, -23), Pair(49, -12), Pair(62, -15), Pair(62, -9), Pair(30, -3), Pair(1, 6), Pair(-26, -7), Pair(-14, -17),
        Pair(103, -46), Pair(25, -11), Pair(11, -1), Pair(41, -7), Pair(25, 4), Pair(-4, 12), Pair(12, 2), Pair(17, -5),
        Pair(-3, 5), Pair(-17, -5), Pair(1, -1), Pair(8, 0), Pair(20, 7), Pair(22, 5), Pair(11, 7), Pair(12, 10),
        Pair(4, -5), Pair(-18, 4), Pair(-8, 2), Pair(14, 10), Pair(5, 14), Pair(11, 18), Pair(1, 17), Pair(-7, 34)
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
        Pair(32, -16), Pair(-60, 40), Pair(-14, 48), Pair(-34, 39), Pair(88, 45), Pair(-98, 86), Pair(37, -1), Pair(111, 31),
        Pair(-62, -82), Pair(-66, 15), Pair(-32, 26), Pair(-27, 47), Pair(-99, 73), Pair(-40, 56), Pair(7, -4), Pair(-60, 28),
        Pair(-7, 9), Pair(-19, 50), Pair(21, 6), Pair(9, 14), Pair(-1, 30), Pair(-37, 35), Pair(-27, 45), Pair(-14, 24),
        Pair(-49, 7), Pair(-2, 30), Pair(18, 22), Pair(-17, 27), Pair(-26, 28), Pair(-2, 18), Pair(-30, 27), Pair(-4, 18),
        Pair(-13, 42), Pair(-38, 41), Pair(-15, 28), Pair(-9, 9), Pair(9, 4), Pair(10, 8), Pair(-21, 17), Pair(-15, 26),
        Pair(-25, 28), Pair(-10, 36), Pair(-36, 27), Pair(-16, 20), Pair(29, 9), Pair(17, 27), Pair(-21, 29), Pair(-9, 29),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-146, 50), Pair(36, 101), Pair(214, 37), Pair(40, 114), Pair(146, 10), Pair(-125, 45), Pair(7, 27), Pair(-13, -24),
        Pair(0, 0), Pair(9, 23), Pair(-51, 164), Pair(101, 3), Pair(0, 86), Pair(-153, 96), Pair(-19, 91), Pair(-198, 107),
        Pair(97, 87), Pair(47, 148), Pair(163, 19), Pair(95, 23), Pair(104, 47), Pair(-20, 54), Pair(151, 34), Pair(21, 53),
        Pair(1, 37), Pair(71, 45), Pair(37, 18), Pair(12, 91), Pair(18, 30), Pair(42, 66), Pair(8, 74), Pair(41, 28),
        Pair(-37, 112), Pair(66, 47), Pair(21, 40), Pair(75, 30), Pair(36, 23), Pair(-49, 51), Pair(-26, 34), Pair(74, 60),
        Pair(124, 0), Pair(35, 6), Pair(11, 29), Pair(138, -6), Pair(67, 32), Pair(98, -28), Pair(44, 11), Pair(-22, 44),
        Pair(144, 44), Pair(-100, 13), Pair(103, -37), Pair(41, -7), Pair(20, 17), Pair(108, 20), Pair(34, 11), Pair(16, 4),
        Pair(-42, 30), Pair(-35, 72), Pair(104, 7), Pair(-81, 60), Pair(37, -33), Pair(34, 6), Pair(-37, 87), Pair(172, -2)
      },
      { // Piece 2
        Pair(103, -112), Pair(247, 18), Pair(-79, 87), Pair(242, -61), Pair(3, 56), Pair(74, -92), Pair(163, 25), Pair(-141, -121),
        Pair(0, 0), Pair(36, 132), Pair(256, -35), Pair(60, 74), Pair(103, -50), Pair(111, 19), Pair(546, -128), Pair(2, 11),
        Pair(201, 63), Pair(259, -41), Pair(154, 81), Pair(164, -24), Pair(101, 16), Pair(273, -70), Pair(273, 12), Pair(69, -78),
        Pair(141, -32), Pair(11, 67), Pair(180, -26), Pair(66, 104), Pair(155, -46), Pair(-93, 96), Pair(63, -72), Pair(27, 51),
        Pair(-107, 73), Pair(97, -32), Pair(19, 58), Pair(129, -9), Pair(51, 95), Pair(93, -31), Pair(5, 39), Pair(166, -52),
        Pair(45, -36), Pair(25, 40), Pair(4, -2), Pair(80, 11), Pair(119, -20), Pair(33, 60), Pair(93, -19), Pair(39, 63),
        Pair(-17, -62), Pair(69, -75), Pair(-12, 71), Pair(40, 7), Pair(28, 35), Pair(207, -47), Pair(45, 40), Pair(23, 32),
        Pair(-11, -8), Pair(-53, 58), Pair(35, -18), Pair(45, 17), Pair(96, -51), Pair(10, 59), Pair(133, -26), Pair(40, 49)
      },
      { // Piece 3
        Pair(107, -170), Pair(77, 170), Pair(-58, 140), Pair(-48, 153), Pair(-98, 153), Pair(-68, 156), Pair(-217, 207), Pair(-185, 180),
        Pair(0, 0), Pair(186, 42), Pair(83, 48), Pair(148, 15), Pair(116, 7), Pair(162, 36), Pair(86, 54), Pair(86, 39),
        Pair(-5, 82), Pair(12, 94), Pair(-68, 131), Pair(-5, 91), Pair(-95, 138), Pair(102, 88), Pair(29, 122), Pair(13, 112),
        Pair(21, 99), Pair(1, 96), Pair(69, 91), Pair(137, 59), Pair(76, 60), Pair(-39, 108), Pair(-115, 154), Pair(-222, 172),
        Pair(29, 86), Pair(76, 99), Pair(-57, 115), Pair(148, -7), Pair(22, 116), Pair(71, 54), Pair(-2, 119), Pair(-12, 48),
        Pair(23, 86), Pair(-40, 104), Pair(80, 69), Pair(-74, 114), Pair(-2, 94), Pair(48, 37), Pair(-62, 84), Pair(-47, 35),
        Pair(44, 47), Pair(35, 109), Pair(-79, 110), Pair(72, 29), Pair(38, 27), Pair(-26, 78), Pair(76, 63), Pair(90, 29),
        Pair(33, 45), Pair(67, 79), Pair(56, 41), Pair(41, 36), Pair(18, 57), Pair(0, 56), Pair(-5, 82), Pair(-9, 59)
      },
      { // Piece 4
        Pair(9, -115), Pair(240, 39), Pair(16, 110), Pair(-29, 106), Pair(-61, 184), Pair(67, 59), Pair(174, 50), Pair(-45, 110),
        Pair(0, 0), Pair(80, 161), Pair(6, 120), Pair(180, -35), Pair(-15, 32), Pair(-245, 124), Pair(139, 54), Pair(101, -6),
        Pair(94, 67), Pair(-2, 148), Pair(121, 52), Pair(60, 22), Pair(198, -76), Pair(-7, 109), Pair(227, -115), Pair(52, 48),
        Pair(13, 106), Pair(23, 125), Pair(82, 58), Pair(-42, 252), Pair(28, 76), Pair(131, -96), Pair(97, 6), Pair(39, -63),
        Pair(33, 111), Pair(28, 205), Pair(36, 109), Pair(58, 70), Pair(145, -130), Pair(84, 53), Pair(-15, 96), Pair(67, 40),
        Pair(-49, 141), Pair(37, 80), Pair(-33, 121), Pair(69, 15), Pair(3, 128), Pair(21, 136), Pair(11, 24), Pair(106, -194),
        Pair(76, 77), Pair(76, -1), Pair(63, -6), Pair(49, -22), Pair(92, 42), Pair(54, 32), Pair(-113, 159), Pair(25, -49),
        Pair(12, -42), Pair(-69, 112), Pair(54, 15), Pair(25, 60), Pair(154, -52), Pair(130, -60), Pair(94, -42), Pair(-20, 42)
      },
      { // Piece 5
        Pair(-12, -388), Pair(-190, 89), Pair(-46, 69), Pair(-12, -13), Pair(63, -68), Pair(98, -115), Pair(-31, -33), Pair(18, 123),
        Pair(0, 0), Pair(36, 67), Pair(-111, 66), Pair(203, -118), Pair(209, -96), Pair(-55, -26), Pair(131, -35), Pair(-1, 19),
        Pair(-75, 39), Pair(74, 15), Pair(128, 31), Pair(-83, 14), Pair(-88, 6), Pair(102, -32), Pair(-32, 12), Pair(12, 21),
        Pair(55, 15), Pair(61, 39), Pair(48, -18), Pair(25, -13), Pair(224, -30), Pair(70, -9), Pair(-56, 18), Pair(-223, 52),
        Pair(-298, 128), Pair(154, 29), Pair(119, -28), Pair(72, -31), Pair(120, -12), Pair(-27, 15), Pair(-15, 13), Pair(-114, 33),
        Pair(-200, 113), Pair(90, -8), Pair(109, -20), Pair(-48, 12), Pair(40, -1), Pair(7, -22), Pair(-62, -4), Pair(-59, -26),
        Pair(26, 100), Pair(128, -6), Pair(53, -12), Pair(-133, 33), Pair(-51, 8), Pair(5, -6), Pair(-24, -21), Pair(-6, -25),
        Pair(-69, -1), Pair(138, -30), Pair(33, -21), Pair(-108, 33), Pair(-50, -19), Pair(-64, -24), Pair(-16, -32), Pair(-73, -30)
      }
    }},
    {{ // Bucket 9
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-60, 40), Pair(6, 48), Pair(87, -8), Pair(-30, 60), Pair(-44, 58), Pair(-84, 49), Pair(-56, 25), Pair(36, 56),
        Pair(34, -15), Pair(-2, -92), Pair(30, -16), Pair(-1, 55), Pair(1, 35), Pair(21, 55), Pair(-10, 24), Pair(62, 17),
        Pair(8, 31), Pair(-5, -18), Pair(4, 37), Pair(-40, 50), Pair(-9, 30), Pair(-45, 31), Pair(-34, 31), Pair(-5, 9),
        Pair(-11, 37), Pair(3, 5), Pair(-2, 22), Pair(-23, 16), Pair(-30, 25), Pair(-21, 23), Pair(-6, 29), Pair(-21, 30),
        Pair(-2, 28), Pair(-21, 24), Pair(-40, 13), Pair(-38, 18), Pair(5, 12), Pair(-36, 20), Pair(-10, 18), Pair(-9, 26),
        Pair(-19, 37), Pair(-19, 10), Pair(-26, 30), Pair(-65, 35), Pair(-3, 28), Pair(-3, 18), Pair(-24, 32), Pair(-8, 28),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-88, -69), Pair(-33, 96), Pair(22, 57), Pair(95, 49), Pair(-104, -58), Pair(-5, 29), Pair(-114, -142), Pair(-42, -71),
        Pair(-56, 135), Pair(0, 0), Pair(132, 75), Pair(33, 111), Pair(34, 59), Pair(-211, 129), Pair(-47, 66), Pair(76, 35),
        Pair(34, 53), Pair(44, 97), Pair(197, 85), Pair(64, 9), Pair(117, 55), Pair(-80, 66), Pair(-181, 116), Pair(43, 35),
        Pair(114, 27), Pair(-86, 90), Pair(64, 50), Pair(-6, 101), Pair(5, 91), Pair(-185, 138), Pair(-103, 84), Pair(35, 55),
        Pair(57, 106), Pair(89, 73), Pair(1, 80), Pair(-23, 34), Pair(120, -3), Pair(-1, 66), Pair(-8, 49), Pair(-30, 59),
        Pair(-54, 0), Pair(25, 25), Pair(-29, 13), Pair(55, 67), Pair(56, 18), Pair(27, 7), Pair(24, 44), Pair(25, 73),
        Pair(50, 1), Pair(198, -62), Pair(-55, 14), Pair(-36, 36), Pair(28, 27), Pair(-10, -1), Pair(-22, 21), Pair(38, 11),
        Pair(-77, 25), Pair(-87, 51), Pair(11, -37), Pair(64, 16), Pair(-40, 64), Pair(54, 7), Pair(23, -137), Pair(65, -51)
      },
      { // Piece 2
        Pair(-34, -79), Pair(124, -111), Pair(255, 6), Pair(-24, 89), Pair(119, -68), Pair(11, 85), Pair(90, -82), Pair(79, 92),
        Pair(166, 62), Pair(0, 0), Pair(197, 101), Pair(197, -94), Pair(127, 68), Pair(35, -64), Pair(-243, 146), Pair(118, -55),
        Pair(78, 14), Pair(127, 28), Pair(246, -48), Pair(3, 171), Pair(151, -26), Pair(356, -53), Pair(219, -58), Pair(-22, 54),
        Pair(40, 47), Pair(131, -62), Pair(67, 60), Pair(133, 33), Pair(85, 86), Pair(232, -49), Pair(-75, 80), Pair(159, -65),
        Pair(140, -60), Pair(6, 62), Pair(101, -34), Pair(-34, 79), Pair(132, 13), Pair(37, 186), Pair(-18, -4), Pair(91, 22),
        Pair(-24, 106), Pair(-4, -58), Pair(4, 67), Pair(72, -23), Pair(-14, 62), Pair(57, 2), Pair(115, 28), Pair(63, 4),
        Pair(167, -96), Pair(6, 91), Pair(-1, -5), Pair(-27, 103), Pair(-3, -1), Pair(157, -41), Pair(86, -17), Pair(10, 80),
        Pair(-120, 115), Pair(90, -102), Pair(1, 86), Pair(9, -8), Pair(3, 25), Pair(42, 0), Pair(202, -38), Pair(206, -19)
      },
      { // Piece 3
        Pair(41, 99), Pair(94, -154), Pair(227, 91), Pair(2, 139), Pair(-50, 88), Pair(-90, 92), Pair(56, 106), Pair(29, 103),
        Pair(10, 56), Pair(0, 0), Pair(114, 21), Pair(138, 16), Pair(270, -34), Pair(-6, 64), Pair(-54, 90), Pair(43, 50),
        Pair(10, 57), Pair(-22, 72), Pair(42, 127), Pair(43, 40), Pair(-162, 126), Pair(53, 36), Pair(166, 28), Pair(8, 79),
        Pair(52, 52), Pair(136, 10), Pair(50, 83), Pair(-32, 72), Pair(1, 50), Pair(-102, 110), Pair(132, 46), Pair(-35, 89),
        Pair(-90, 166), Pair(85, 31), Pair(10, 126), Pair(3, 86), Pair(53, 66), Pair(67, 33), Pair(-50, 112), Pair(-136, 151),
        Pair(-16, 84), Pair(11, 40), Pair(12, 101), Pair(146, 15), Pair(-69, 96), Pair(-62, 118), Pair(-79, 174), Pair(-117, 52),
        Pair(60, -4), Pair(-23, 48), Pair(-29, 109), Pair(99, 41), Pair(52, 12), Pair(50, 46), Pair(84, -6), Pair(14, 76),
        Pair(19, 76), Pair(36, 46), Pair(44, 79), Pair(-21, 93), Pair(-14, 61), Pair(30, 55), Pair(-48, 4), Pair(-59, 61)
      },
      { // Piece 4
        Pair(73, -154), Pair(-8, -105), Pair(132, -7), Pair(203, 37), Pair(30, 32), Pair(55, -22), Pair(-84, -29), Pair(159, 50),
        Pair(-61, 127), Pair(0, 0), Pair(81, 88), Pair(-1, 89), Pair(71, -6), Pair(177, -176), Pair(-83, -7), Pair(153, -96),
        Pair(40, 100), Pair(62, 67), Pair(11, 111), Pair(179, 22), Pair(-114, 92), Pair(33, -20), Pair(-24, 72), Pair(-175, 103),
        Pair(73, 1), Pair(-58, 231), Pair(-60, 171), Pair(-19, 78), Pair(22, 107), Pair(150, 32), Pair(-116, 134), Pair(134, -75),
        Pair(90, -40), Pair(2, 114), Pair(-24, 221), Pair(90, -13), Pair(42, 49), Pair(3, 63), Pair(114, -47), Pair(22, -72),
        Pair(185, -343), Pair(-10, 114), Pair(-10, 105), Pair(36, 58), Pair(146, -113), Pair(15, 111), Pair(-43, 283), Pair(-83, 25),
        Pair(-60, 33), Pair(20, 46), Pair(3, 53), Pair(-80, 150), Pair(47, 40), Pair(132, -65), Pair(99, 0), Pair(-39, -51),
        Pair(116, -151), Pair(-62, 114), Pair(90, -109), Pair(-43, 189), Pair(-105, 100), Pair(-33, 126), Pair(17, -42), Pair(139, -28)
      },
      { // Piece 5
        Pair(-44, 238), Pair(97, -97), Pair(111, -18), Pair(164, 41), Pair(-51, -44), Pair(-35, -31), Pair(-13, -24), Pair(-5, 23),
        Pair(-94, 125), Pair(0, 0), Pair(122, 82), Pair(-86, 28), Pair(163, -49), Pair(57, 71), Pair(-56, -5), Pair(1, -28),
        Pair(-65, 83), Pair(157, 42), Pair(190, 11), Pair(-41, 56), Pair(132, 8), Pair(-5, 13), Pair(17, 8), Pair(-37, 85),
        Pair(95, 22), Pair(50, 23), Pair(92, 23), Pair(95, 12), Pair(-6, 22), Pair(122, 10), Pair(-206, 25), Pair(-12, -15),
        Pair(164, -17), Pair(159, -2), Pair(62, 16), Pair(90, -27), Pair(108, -23), Pair(-239, 24), Pair(-165, 13), Pair(-122, -6),
        Pair(31, 29), Pair(42, -54), Pair(5, -7), Pair(-23, -16), Pair(-103, -37), Pair(-29, -32), Pair(-40, -22), Pair(-112, -67),
        Pair(-5, 0), Pair(99, 42), Pair(25, 20), Pair(-40, -13), Pair(-36, -31), Pair(-105, -8), Pair(-29, -41), Pair(-94, -40),
        Pair(-19, 5), Pair(8, 12), Pair(52, 63), Pair(10, -39), Pair(-74, -13), Pair(-94, -21), Pair(-88, -18), Pair(-76, -44)
      }
    }},
    {{ // Bucket 10
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-13, 48), Pair(87, -8), Pair(-3, 34), Pair(58, -7), Pair(-86, 19), Pair(75, 24), Pair(-45, 59), Pair(105, 27),
        Pair(-2, 34), Pair(58, -8), Pair(-56, -73), Pair(-49, 42), Pair(26, 53), Pair(-40, 70), Pair(-114, 46), Pair(97, 28),
        Pair(-51, 39), Pair(12, 41), Pair(-53, 7), Pair(-20, 52), Pair(-10, 23), Pair(22, 22), Pair(-11, 15), Pair(9, 15),
        Pair(-4, 24), Pair(16, 39), Pair(-23, -14), Pair(-18, 26), Pair(-24, 27), Pair(-17, 19), Pair(-13, 13), Pair(-12, 19),
        Pair(-1, 20), Pair(-50, 42), Pair(-25, -3), Pair(-39, 19), Pair(1, 5), Pair(-4, 14), Pair(2, 6), Pair(-1, 19),
        Pair(-15, 29), Pair(12, 4), Pair(-37, -7), Pair(-35, 7), Pair(0, 41), Pair(-6, 20), Pair(-7, 21), Pair(-24, 37),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(283, -49), Pair(81, 114), Pair(-6, -39), Pair(9, 122), Pair(146, 55), Pair(-117, 26), Pair(13, -41), Pair(34, 37),
        Pair(16, 200), Pair(199, 5), Pair(0, 0), Pair(90, 4), Pair(140, 136), Pair(-198, 127), Pair(110, -8), Pair(-172, -2),
        Pair(80, 30), Pair(108, 156), Pair(133, 81), Pair(-19, 169), Pair(55, 59), Pair(5, 78), Pair(98, 29), Pair(-54, 120),
        Pair(-36, 48), Pair(49, 76), Pair(-107, 134), Pair(135, 19), Pair(-47, 91), Pair(13, 89), Pair(-63, 109), Pair(-22, 32),
        Pair(68, 84), Pair(79, 63), Pair(-7, 94), Pair(44, 58), Pair(-61, 135), Pair(81, -28), Pair(-51, 119), Pair(-13, 95),
        Pair(60, -9), Pair(-77, 25), Pair(-9, 68), Pair(26, 43), Pair(62, 66), Pair(35, -6), Pair(119, -73), Pair(-36, 48),
        Pair(176, 85), Pair(-150, 84), Pair(105, -25), Pair(15, 21), Pair(38, 54), Pair(101, -23), Pair(11, 9), Pair(48, 10),
        Pair(-99, 10), Pair(-11, 7), Pair(9, 110), Pair(-5, 25), Pair(42, 44), Pair(-95, 46), Pair(35, -51), Pair(53, -12)
      },
      { // Piece 2
        Pair(-125, 121), Pair(179, 12), Pair(-130, 20), Pair(496, 20), Pair(-37, 97), Pair(255, -40), Pair(-26, 73), Pair(19, -71),
        Pair(200, -21), Pair(-113, 221), Pair(0, 0), Pair(34, 83), Pair(140, -17), Pair(210, -21), Pair(128, -75), Pair(90, 34),
        Pair(170, 108), Pair(110, 1), Pair(32, 166), Pair(116, -7), Pair(117, 106), Pair(206, -71), Pair(130, 52), Pair(27, -42),
        Pair(21, 55), Pair(70, 58), Pair(252, 6), Pair(11, 78), Pair(166, -12), Pair(258, 5), Pair(115, -6), Pair(-48, 131),
        Pair(-17, 63), Pair(39, -13), Pair(67, 88), Pair(100, -35), Pair(-23, 95), Pair(117, -3), Pair(10, 93), Pair(109, -25),
        Pair(11, -68), Pair(40, 27), Pair(82, -4), Pair(11, 53), Pair(62, 15), Pair(17, 65), Pair(153, 12), Pair(94, 14),
        Pair(162, -74), Pair(40, -12), Pair(-74, -12), Pair(-36, -7), Pair(1, 41), Pair(76, 0), Pair(40, 51), Pair(58, 70),
        Pair(3, -24), Pair(-163, 62), Pair(24, -36), Pair(29, 82), Pair(50, 10), Pair(9, 43), Pair(107, 24), Pair(145, 38)
      },
      { // Piece 3
        Pair(-75, 147), Pair(-10, 179), Pair(139, -148), Pair(154, 140), Pair(126, 66), Pair(99, 50), Pair(13, 78), Pair(221, 9),
        Pair(-45, 113), Pair(84, 58), Pair(0, 0), Pair(120, 57), Pair(28, 51), Pair(48, 76), Pair(28, 90), Pair(201, 15),
        Pair(74, 88), Pair(-21, 127), Pair(108, 27), Pair(53, 85), Pair(-25, 76), Pair(-15, 104), Pair(-89, 117), Pair(-81, 144),
        Pair(30, 81), Pair(-34, 134), Pair(97, 22), Pair(53, 77), Pair(-52, 128), Pair(-98, 143), Pair(-20, 114), Pair(127, 3),
        Pair(-41, 86), Pair(9, 96), Pair(4, 98), Pair(-56, 129), Pair(70, 118), Pair(67, 42), Pair(189, 44), Pair(-10, 134),
        Pair(-34, 71), Pair(75, 74), Pair(167, -4), Pair(50, 53), Pair(40, 47), Pair(46, 92), Pair(-22, 55), Pair(-79, 155),
        Pair(-88, 97), Pair(98, 29), Pair(77, 83), Pair(-13, 131), Pair(35, 47), Pair(-65, 54), Pair(7, 39), Pair(74, 84),
        Pair(-38, 92), Pair(47, 73), Pair(55, 36), Pair(58, 51), Pair(44, 70), Pair(1, 81), Pair(48, -13), Pair(-45, 64)
      },
      { // Piece 4
        Pair(-173, 126), Pair(85, -20), Pair(51, -227), Pair(26, 36), Pair(71, 26), Pair(59, 29), Pair(-31, -129), Pair(27, -35),
        Pair(29, -18), Pair(-25, 91), Pair(0, 0), Pair(39, 106), Pair(-29, 59), Pair(100, -88), Pair(55, 54), Pair(-10, -4),
        Pair(75, -30), Pair(31, 30), Pair(-94, 176), Pair(11, 102), Pair(127, -21), Pair(73, -21), Pair(-160, 69), Pair(96, -45),
        Pair(81, -12), Pair(-157, 250), Pair(-18, 72), Pair(-1, 89), Pair(42, 44), Pair(62, -57), Pair(50, -36), Pair(87, -77),
        Pair(118, -86), Pair(91, 5), Pair(29, 2), Pair(12, 33), Pair(-94, 207), Pair(102, -42), Pair(-32, 145), Pair(-37, 151),
        Pair(-9, 96), Pair(-68, 27), Pair(78, 14), Pair(54, -7), Pair(10, -5), Pair(20, 10), Pair(92, -73), Pair(209, -43),
        Pair(15, -16), Pair(-18, 26), Pair(1, -12), Pair(26, -15), Pair(-71, 152), Pair(26, -88), Pair(55, -125), Pair(52, 20),
        Pair(-16, 61), Pair(-16, 60), Pair(30, 9), Pair(-19, 35), Pair(95, -247), Pair(-101, 104), Pair(-95, 149), Pair(-39, -22)
      },
      { // Piece 5
        Pair(0, 124), Pair(171, 54), Pair(-106, -33), Pair(-119, -10), Pair(-67, 86), Pair(99, 3), Pair(39, 100), Pair(14, 46),
        Pair(-126, 81), Pair(81, 102), Pair(0, 0), Pair(-38, 64), Pair(-57, -31), Pair(-1, 40), Pair(-86, -65), Pair(17, 33),
        Pair(110, 44), Pair(117, 68), Pair(170, 15), Pair(308, 21), Pair(-109, 62), Pair(156, -34), Pair(119, -26), Pair(-3, 0),
        Pair(206, -37), Pair(249, 43), Pair(159, -5), Pair(172, 13), Pair(51, 14), Pair(111, -47), Pair(-166, 8), Pair(70, -41),
        Pair(88, -2), Pair(117, 16), Pair(136, -19), Pair(-101, 5), Pair(-59, 12), Pair(25, -27), Pair(-53, -54), Pair(35, -42),
        Pair(-328, 113), Pair(-150, 45), Pair(11, 13), Pair(17, 7), Pair(36, -18), Pair(-91, -27), Pair(-19, -59), Pair(-147, -32),
        Pair(-51, 51), Pair(77, -56), Pair(68, -16), Pair(-30, -6), Pair(-96, -28), Pair(-125, -13), Pair(-74, -12), Pair(-47, -8),
        Pair(-102, -27), Pair(33, 37), Pair(-124, -33), Pair(-113, 23), Pair(-86, -21), Pair(-75, -27), Pair(-47, -52), Pair(-64, -45)
      }
    }},
    {{ // Bucket 11
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-34, 39), Pair(-30, 60), Pair(58, -7), Pair(34, 11), Pair(49, 16), Pair(-64, 71), Pair(145, 9), Pair(-215, 117),
        Pair(-26, 74), Pair(-58, 42), Pair(59, -5), Pair(-51, -51), Pair(30, -5), Pair(48, 57), Pair(-87, 61), Pair(-61, 64),
        Pair(7, 31), Pair(21, 15), Pair(8, 53), Pair(-15, -11), Pair(10, 48), Pair(-20, 37), Pair(11, 26), Pair(24, 7),
        Pair(-9, 32), Pair(4, 17), Pair(-23, 26), Pair(-34, -13), Pair(-11, 17), Pair(-5, 11), Pair(22, 4), Pair(13, 2),
        Pair(22, 19), Pair(5, 6), Pair(-8, 5), Pair(-24, 9), Pair(-12, 14), Pair(14, 7), Pair(0, 21), Pair(4, 8),
        Pair(-1, 24), Pair(-18, 12), Pair(-41, 0), Pair(-71, 33), Pair(-17, -6), Pair(-14, 15), Pair(-14, 18), Pair(-10, 20),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-134, 0), Pair(9, 73), Pair(80, 117), Pair(-185, -33), Pair(56, 67), Pair(72, 34), Pair(-12, 28), Pair(0, -2),
        Pair(74, 68), Pair(12, 136), Pair(-93, 143), Pair(0, 0), Pair(-37, 118), Pair(-23, 134), Pair(138, 81), Pair(-153, 133),
        Pair(-23, 69), Pair(185, 4), Pair(50, 137), Pair(132, 98), Pair(16, 121), Pair(182, -17), Pair(-16, 125), Pair(111, 5),
        Pair(-35, 128), Pair(24, 67), Pair(65, 44), Pair(71, 59), Pair(16, 78), Pair(100, 32), Pair(116, 53), Pair(-35, 48),
        Pair(-17, 75), Pair(101, 80), Pair(52, 93), Pair(34, 92), Pair(38, 27), Pair(-45, 85), Pair(70, 41), Pair(51, 27),
        Pair(21, 14), Pair(43, 73), Pair(39, 35), Pair(103, 34), Pair(45, 0), Pair(-18, 65), Pair(72, 8), Pair(122, 36),
        Pair(143, 10), Pair(-12, 18), Pair(65, 39), Pair(-97, 114), Pair(-2, 51), Pair(85, 13), Pair(-116, 88), Pair(19, 33),
        Pair(29, 57), Pair(19, -27), Pair(83, 100), Pair(12, 76), Pair(-104, 36), Pair(5, 63), Pair(7, -58), Pair(51, -13)
      },
      { // Piece 2
        Pair(253, -37), Pair(26, -3), Pair(41, -77), Pair(-282, -13), Pair(-40, 13), Pair(-146, 30), Pair(50, -5), Pair(-72, 28),
        Pair(-162, 160), Pair(152, -48), Pair(-13, 144), Pair(0, 0), Pair(178, 62), Pair(137, -68), Pair(190, -24), Pair(-18, 7),
        Pair(88, -26), Pair(-83, 170), Pair(124, -14), Pair(177, 21), Pair(142, -32), Pair(270, 57), Pair(5, -18), Pair(283, -40),
        Pair(-5, 139), Pair(69, 17), Pair(36, 77), Pair(66, -21), Pair(8, 77), Pair(160, -1), Pair(24, 89), Pair(142, -20),
        Pair(87, 10), Pair(100, 54), Pair(25, 5), Pair(37, 47), Pair(79, -27), Pair(16, 94), Pair(57, 7), Pair(105, 57),
        Pair(161, -13), Pair(26, -6), Pair(106, 41), Pair(24, -24), Pair(49, 54), Pair(21, 14), Pair(71, 24), Pair(60, 1),
        Pair(-125, 8), Pair(30, -2), Pair(-39, -17), Pair(-59, 122), Pair(21, 10), Pair(-18, 50), Pair(10, 17), Pair(92, -2),
        Pair(74, -4), Pair(31, 30), Pair(67, 9), Pair(152, -54), Pair(29, 23), Pair(84, -10), Pair(219, -131), Pair(233, -50)
      },
      { // Piece 3
        Pair(-35, 117), Pair(-29, 123), Pair(40, 149), Pair(64, -101), Pair(120, 138), Pair(-33, 143), Pair(153, 84), Pair(100, 118),
        Pair(55, 50), Pair(20, 74), Pair(-6, 79), Pair(0, 0), Pair(66, 37), Pair(23, 56), Pair(-197, 118), Pair(-23, 100),
        Pair(21, 72), Pair(44, 96), Pair(41, 103), Pair(64, 50), Pair(-120, 162), Pair(62, 47), Pair(-69, 130), Pair(-50, 82),
        Pair(90, 55), Pair(149, 27), Pair(86, 28), Pair(-54, 110), Pair(-125, 170), Pair(53, 80), Pair(222, -24), Pair(40, 94),
        Pair(55, 8), Pair(-51, 119), Pair(-8, 120), Pair(13, 65), Pair(-72, 123), Pair(-95, 124), Pair(109, 82), Pair(-77, 109),
        Pair(-97, 94), Pair(-213, 172), Pair(29, 61), Pair(29, 85), Pair(24, 131), Pair(3, 87), Pair(-25, 72), Pair(-127, 102),
        Pair(3, 28), Pair(-29, 67), Pair(-162, 142), Pair(27, 58), Pair(-16, 106), Pair(8, 73), Pair(-35, 89), Pair(28, 1),
        Pair(-47, 82), Pair(-22, 72), Pair(26, 53), Pair(40, 57), Pair(18, 73), Pair(-22, 74), Pair(-20, 63), Pair(-86, 73)
      },
      { // Piece 4
        Pair(-33, 186), Pair(-16, 46), Pair(-22, 65), Pair(-145, -83), Pair(135, -89), Pair(-23, 24), Pair(-41, 36), Pair(-86, -39),
        Pair(-55, 109), Pair(22, 66), Pair(-21, 103), Pair(0, 0), Pair(66, -38), Pair(179, -51), Pair(-48, -96), Pair(178, -136),
        Pair(40, -45), Pair(-102, 103), Pair(115, -79), Pair(56, -35), Pair(48, 35), Pair(95, 77), Pair(47, 98), Pair(-65, 45),
        Pair(122, -18), Pair(-2, 47), Pair(155, -102), Pair(19, 9), Pair(-44, 128), Pair(76, 6), Pair(-21, 157), Pair(44, 188),
        Pair(-56, 81), Pair(-24, 55), Pair(-7, 51), Pair(27, 70), Pair(43, 85), Pair(-54, 202), Pair(84, -50), Pair(110, -111),
        Pair(-19, 18), Pair(-104, 108), Pair(95, -32), Pair(30, 26), Pair(-23, 57), Pair(-26, 101), Pair(36, 31), Pair(-52, 70),
        Pair(55, -74), Pair(-110, 112), Pair(20, 108), Pair(-7, 97), Pair(0, 90), Pair(96, -12), Pair(-33, -78), Pair(85, -81),
        Pair(223, -153), Pair(129, -39), Pair(-55, 177), Pair(45, -55), Pair(43, 10), Pair(-92, -126), Pair(90, -87), Pair(32, -55)
      },
      { // Piece 5
        Pair(-31, 76), Pair(44, 112), Pair(31, -9), Pair(191, -43), Pair(-66, 71), Pair(-47, 102), Pair(-5, -73), Pair(6, 237),
        Pair(-14, 3), Pair(22, 33), Pair(225, 43), Pair(0, 0), Pair(-111, 134), Pair(4, 72), Pair(35, -86), Pair(59, 101),
        Pair(23, 42), Pair(-23, 20), Pair(51, 49), Pair(92, 24), Pair(96, 43), Pair(-6, 41), Pair(-143, 11), Pair(-119, 11),
        Pair(257, -12), Pair(105, -23), Pair(146, 12), Pair(83, 26), Pair(183, -4), Pair(44, -28), Pair(45, -13), Pair(99, -60),
        Pair(-82, 11), Pair(-12, 38), Pair(-11, 12), Pair(60, 0), Pair(118, -35), Pair(61, -32), Pair(-110, 11), Pair(-166, -2),
        Pair(79, -46), Pair(110, -14), Pair(33, -28), Pair(-18, -14), Pair(-56, -37), Pair(-40, -5), Pair(-34, -20), Pair(-51, -22),
        Pair(-38, -20), Pair(-12, 5), Pair(-12, 9), Pair(-114, 35), Pair(-137, -1), Pair(-79, -20), Pair(-76, -15), Pair(-69, -27),
        Pair(157, -132), Pair(-2, -49), Pair(-23, 36), Pair(-14, -43), Pair(-99, 40), Pair(-45, -38), Pair(-56, -44), Pair(-42, -58)
      }
    }},
    {{ // Bucket 12
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(88, 45), Pair(-44, 58), Pair(-86, 19), Pair(49, 16), Pair(56, -7), Pair(127, -29), Pair(-67, 28), Pair(91, 57),
        Pair(-37, 66), Pair(-31, 26), Pair(-105, 65), Pair(6, -4), Pair(133, -70), Pair(111, -37), Pair(22, 28), Pair(-29, 31),
        Pair(-19, 28), Pair(-80, 50), Pair(-33, 44), Pair(-17, 62), Pair(-4, -10), Pair(-21, 34), Pair(1, 12), Pair(-1, 21),
        Pair(6, -3), Pair(22, 16), Pair(16, 19), Pair(-15, 35), Pair(-61, 25), Pair(-11, 22), Pair(17, 4), Pair(-7, 11),
        Pair(6, 9), Pair(-9, 17), Pair(-15, 30), Pair(1, 0), Pair(-7, -10), Pair(-30, 21), Pair(-3, 8), Pair(-24, 5),
        Pair(-8, 8), Pair(30, 6), Pair(6, 4), Pair(-18, -29), Pair(-71, 12), Pair(-15, 24), Pair(10, 5), Pair(-31, 29),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(89, 90), Pair(-238, 15), Pair(166, 7), Pair(178, 31), Pair(-3, -91), Pair(331, -18), Pair(106, 71), Pair(-35, -62),
        Pair(-259, 47), Pair(-318, 252), Pair(190, 2), Pair(203, 40), Pair(0, 0), Pair(-138, 148), Pair(-17, 66), Pair(75, -67),
        Pair(79, 74), Pair(1, 61), Pair(67, 28), Pair(-47, 102), Pair(135, 28), Pair(80, 34), Pair(142, -12), Pair(-119, 76),
        Pair(-245, 178), Pair(33, -4), Pair(-20, 85), Pair(8, 39), Pair(88, -9), Pair(28, 77), Pair(-56, 46), Pair(300, -55),
        Pair(-96, -14), Pair(-7, -45), Pair(-10, -14), Pair(-1, 59), Pair(-29, 112), Pair(-1, 56), Pair(-7, 22), Pair(24, 33),
        Pair(-21, -54), Pair(-62, 33), Pair(-34, 73), Pair(11, 7), Pair(62, -18), Pair(-27, 11), Pair(158, -13), Pair(85, -87),
        Pair(125, -73), Pair(50, -37), Pair(77, -16), Pair(-50, 30), Pair(16, -23), Pair(52, -29), Pair(133, 24), Pair(5, 43),
        Pair(18, 9), Pair(-71, 18), Pair(36, 127), Pair(153, -79), Pair(-68, -53), Pair(18, -82), Pair(34, 6), Pair(-8, 42)
      },
      { // Piece 2
        Pair(251, 73), Pair(-108, -38), Pair(-6, 78), Pair(290, -32), Pair(74, 35), Pair(152, -35), Pair(-213, 20), Pair(-12, -15),
        Pair(20, -24), Pair(165, 58), Pair(48, -2), Pair(231, 172), Pair(0, 0), Pair(76, 102), Pair(158, -64), Pair(227, -20),
        Pair(-116, 101), Pair(112, -51), Pair(-73, 174), Pair(134, -49), Pair(-59, 93), Pair(7, -2), Pair(16, 82), Pair(-4, -50),
        Pair(29, -21), Pair(-106, 170), Pair(93, -15), Pair(-140, 97), Pair(203, -61), Pair(118, 5), Pair(137, -13), Pair(-42, 119),
        Pair(-192, 135), Pair(144, -65), Pair(-21, 89), Pair(142, -61), Pair(173, 9), Pair(89, -9), Pair(81, 16), Pair(77, -10),
        Pair(169, -56), Pair(68, 20), Pair(96, -98), Pair(-28, 42), Pair(120, -49), Pair(97, -21), Pair(114, -140), Pair(86, 15),
        Pair(-159, 157), Pair(-4, -30), Pair(213, -81), Pair(44, -39), Pair(12, 51), Pair(67, -30), Pair(44, 67), Pair(-45, -11),
        Pair(194, -76), Pair(6, -13), Pair(-80, 20), Pair(-43, 10), Pair(-36, -70), Pair(9, 35), Pair(238, -96), Pair(-175, 79)
      },
      { // Piece 3
        Pair(-182, 148), Pair(119, 113), Pair(-92, 100), Pair(56, 124), Pair(-201, -78), Pair(296, 63), Pair(132, 42), Pair(130, 23),
        Pair(-70, 51), Pair(-37, 35), Pair(-2, 17), Pair(92, 23), Pair(0, 0), Pair(55, 52), Pair(-27, 27), Pair(-181, 76),
        Pair(33, 85), Pair(107, 41), Pair(19, 58), Pair(55, 72), Pair(35, 1), Pair(91, 34), Pair(-91, 60), Pair(31, 53),
        Pair(-33, 44), Pair(129, -11), Pair(-27, 85), Pair(64, 91), Pair(91, 41), Pair(-29, 65), Pair(-96, 93), Pair(39, 62),
        Pair(173, 31), Pair(14, 68), Pair(-184, 119), Pair(-147, 116), Pair(79, 27), Pair(62, 67), Pair(-25, 124), Pair(-29, 43),
        Pair(59, -41), Pair(58, 33), Pair(71, 61), Pair(59, 33), Pair(-39, 49), Pair(-76, 42), Pair(-14, 27), Pair(-25, 46),
        Pair(97, -8), Pair(58, 19), Pair(33, 12), Pair(-23, 44), Pair(95, -24), Pair(8, 77), Pair(-120, 32), Pair(-213, 60),
        Pair(-65, 17), Pair(-52, 48), Pair(-19, 55), Pair(26, 29), Pair(-4, 45), Pair(-29, 45), Pair(25, 2), Pair(-117, 62)
      },
      { // Piece 4
        Pair(-17, -80), Pair(190, 141), Pair(-11, 62), Pair(-28, -17), Pair(-302, -112), Pair(-39, -15), Pair(-45, -139), Pair(-32, -49),
        Pair(69, -111), Pair(-89, 15), Pair(-133, -6), Pair(-3, -64), Pair(0, 0), Pair(173, -85), Pair(-40, -75), Pair(-169, 81),
        Pair(28, 257), Pair(24, -66), Pair(48, -69), Pair(18, -33), Pair(32, -117), Pair(69, -42), Pair(14, 53), Pair(19, 49),
        Pair(-67, -42), Pair(-58, 93), Pair(28, 20), Pair(122, -55), Pair(-21, 6), Pair(131, -81), Pair(5, 44), Pair(1, -42),
        Pair(-123, 108), Pair(58, -85), Pair(22, 33), Pair(119, -136), Pair(95, -55), Pair(-6, 95), Pair(158, -245), Pair(55, -218),
        Pair(23, -94), Pair(-113, 120), Pair(63, 19), Pair(0, 8), Pair(-121, 121), Pair(-26, 2), Pair(8, -33), Pair(-57, -50),
        Pair(-32, -71), Pair(-15, -94), Pair(10, -11), Pair(10, -56), Pair(-21, -37), Pair(-67, 27), Pair(-17, -17), Pair(-61, -110),
        Pair(-88, -34), Pair(218, -103), Pair(-153, -64), Pair(-117, 158), Pair(-5, -10), Pair(-70, 14), Pair(18, -19), Pair(72, 12)
      },
      { // Piece 5
        Pair(113, 47), Pair(-4, -76), Pair(-11, 51), Pair(-115, 24), Pair(-18, -96), Pair(50, -48), Pair(49, 30), Pair(9, 81),
        Pair(-142, -16), Pair(19, -46), Pair(-26, 21), Pair(-165, 82), Pair(0, 0), Pair(36, 153), Pair(131, -10), Pair(84, 85),
        Pair(-47, 7), Pair(189, -81), Pair(5, 37), Pair(48, 76), Pair(185, 27), Pair(121, 42), Pair(121, 23), Pair(118, -47),
        Pair(-130, 33), Pair(-36, 2), Pair(81, 2), Pair(-47, 56), Pair(-77, 31), Pair(64, 6), Pair(37, -30), Pair(-105, -3),
        Pair(-134, 20), Pair(92, -49), Pair(-137, 45), Pair(252, -49), Pair(-74, 4), Pair(89, -18), Pair(30, 2), Pair(-10, -18),
        Pair(-98, -27), Pair(-94, -16), Pair(215, -82), Pair(-209, 39), Pair(-18, -26), Pair(-44, -38), Pair(47, -65), Pair(7, -50),
        Pair(-249, 95), Pair(91, -55), Pair(-26, 22), Pair(29, -48), Pair(-162, 10), Pair(-56, -14), Pair(-6, -48), Pair(55, -49),
        Pair(-85, 40), Pair(61, -94), Pair(-111, 17), Pair(15, -3), Pair(-84, -45), Pair(11, -28), Pair(34, -38), Pair(29, -64)
      }
    }},
    {{ // Bucket 13
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-98, 86), Pair(-84, 49), Pair(75, 24), Pair(-64, 71), Pair(127, -29), Pair(0, 28), Pair(33, 18), Pair(-16, 38),
        Pair(40, 2), Pair(-104, 83), Pair(-40, 73), Pair(-1, 42), Pair(-38, -5), Pair(-9, -43), Pair(7, -17), Pair(74, -13),
        Pair(3, 44), Pair(3, 38), Pair(-46, 30), Pair(12, -8), Pair(-25, 26), Pair(-9, -3), Pair(23, 5), Pair(-55, -2),
        Pair(-35, 36), Pair(61, -5), Pair(16, 18), Pair(-18, 26), Pair(-20, 7), Pair(-33, -25), Pair(14, 16), Pair(-6, -7),
        Pair(-4, 25), Pair(-3, 7), Pair(-14, 4), Pair(34, -9), Pair(-31, 26), Pair(-37, 7), Pair(-20, 8), Pair(31, 0),
        Pair(-6, 10), Pair(15, 12), Pair(-41, 24), Pair(0, -8), Pair(-67, 31), Pair(-20, 7), Pair(7, -4), Pair(-7, 16),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-16, 102), Pair(33, 1), Pair(-4, 97), Pair(210, -19), Pair(94, 95), Pair(149, -7), Pair(180, 23), Pair(-22, -76),
        Pair(-9, 114), Pair(-50, 16), Pair(99, 4), Pair(-47, 74), Pair(-141, 23), Pair(0, 0), Pair(126, -25), Pair(15, 178),
        Pair(-13, -7), Pair(-20, 29), Pair(-228, 49), Pair(102, -37), Pair(161, 30), Pair(-40, 46), Pair(183, 53), Pair(26, 8),
        Pair(-142, -110), Pair(-113, 26), Pair(-114, 27), Pair(-9, 20), Pair(118, 52), Pair(-115, 79), Pair(73, 26), Pair(131, -4),
        Pair(71, 7), Pair(-121, -16), Pair(0, 33), Pair(121, -17), Pair(-13, 24), Pair(79, 2), Pair(12, 47), Pair(137, -20),
        Pair(-69, 70), Pair(65, 14), Pair(-7, 28), Pair(46, 51), Pair(-67, 83), Pair(-7, 35), Pair(-44, -28), Pair(-31, 4),
        Pair(64, 35), Pair(171, 2), Pair(34, -67), Pair(-30, -11), Pair(-24, -3), Pair(-53, 9), Pair(205, -111), Pair(12, -70),
        Pair(-22, -11), Pair(-8, 33), Pair(-25, 34), Pair(149, -35), Pair(-257, -59), Pair(-240, 138), Pair(-11, 168), Pair(40, -80)
      },
      { // Piece 2
        Pair(-69, -97), Pair(-32, 98), Pair(-141, -43), Pair(-4, 41), Pair(54, -5), Pair(-149, 92), Pair(172, -66), Pair(-14, 89),
        Pair(15, 7), Pair(117, -26), Pair(107, 144), Pair(187, -118), Pair(-131, 143), Pair(0, 0), Pair(210, 71), Pair(335, -102),
        Pair(-51, -63), Pair(-80, 8), Pair(-34, -71), Pair(212, 120), Pair(131, -82), Pair(27, 136), Pair(152, -15), Pair(113, 113),
        Pair(17, 61), Pair(7, -59), Pair(-69, 174), Pair(25, -9), Pair(-45, 70), Pair(4, 35), Pair(-99, 115), Pair(92, -18),
        Pair(-68, -36), Pair(-221, 98), Pair(63, -19), Pair(242, -13), Pair(-10, -1), Pair(8, 82), Pair(166, -83), Pair(170, 16),
        Pair(58, 45), Pair(126, -55), Pair(40, 35), Pair(-30, -20), Pair(-7, 72), Pair(52, -67), Pair(65, 67), Pair(101, -107),
        Pair(-153, 9), Pair(-12, 38), Pair(-27, 1), Pair(47, 24), Pair(0, -15), Pair(-25, 46), Pair(1, -73), Pair(209, -53),
        Pair(26, 34), Pair(-11, -33), Pair(-26, 56), Pair(-83, -33), Pair(238, -65), Pair(26, 25), Pair(92, -16), Pair(194, -141)
      },
      { // Piece 3
        Pair(49, 55), Pair(-62, 85), Pair(275, -19), Pair(138, 90), Pair(52, 97), Pair(19, -205), Pair(-169, 176), Pair(138, 90),
        Pair(-13, -8), Pair(73, -12), Pair(-22, -9), Pair(21, 48), Pair(-17, -6), Pair(0, 0), Pair(-35, 72), Pair(-31, 72),
        Pair(73, 11), Pair(206, -29), Pair(-37, 21), Pair(15, -5), Pair(-111, 40), Pair(116, -50), Pair(188, 46), Pair(-13, 72),
        Pair(30, -25), Pair(321, -74), Pair(12, -52), Pair(46, 7), Pair(20, 32), Pair(10, 52), Pair(74, 25), Pair(44, 29),
        Pair(45, 3), Pair(15, 13), Pair(2, -64), Pair(26, 46), Pair(27, 35), Pair(41, 31), Pair(-66, 70), Pair(-15, 38),
        Pair(-15, 26), Pair(-204, 75), Pair(-129, -8), Pair(-61, 19), Pair(-20, 50), Pair(46, -3), Pair(-58, 86), Pair(27, -8),
        Pair(-28, -46), Pair(-101, 24), Pair(-105, 60), Pair(-120, 98), Pair(-36, 50), Pair(-14, 41), Pair(-6, 11), Pair(85, -57),
        Pair(-79, 7), Pair(-104, 34), Pair(-34, 27), Pair(-23, 35), Pair(-23, 40), Pair(25, 31), Pair(-31, 37), Pair(23, -30)
      },
      { // Piece 4
        Pair(-42, 12), Pair(-106, -165), Pair(-8, -160), Pair(-59, -15), Pair(98, -176), Pair(-110, -141), Pair(1, -79), Pair(69, -134),
        Pair(-10, 47), Pair(-10, 97), Pair(-207, 93), Pair(-100, 146), Pair(131, -91), Pair(0, 0), Pair(69, -118), Pair(-114, 194),
        Pair(87, -110), Pair(208, -416), Pair(34, -120), Pair(-4, -93), Pair(-15, 95), Pair(115, -136), Pair(2, -6), Pair(-43, -60),
        Pair(106, -139), Pair(-15, -139), Pair(94, -122), Pair(55, -141), Pair(143, -41), Pair(83, -67), Pair(131, -293), Pair(-76, 92),
        Pair(1, 7), Pair(-113, -117), Pair(89, -107), Pair(26, 24), Pair(-33, -109), Pair(-26, 192), Pair(-26, 84), Pair(-37, 4),
        Pair(9, -8), Pair(-163, 36), Pair(24, -11), Pair(66, -185), Pair(-18, -150), Pair(12, -68), Pair(-7, 5), Pair(-72, 43),
        Pair(-32, -109), Pair(1, -145), Pair(-25, 33), Pair(-39, -23), Pair(-60, -58), Pair(32, -123), Pair(-185, 269), Pair(41, -114),
        Pair(111, 27), Pair(-159, 36), Pair(-158, 86), Pair(-28, -74), Pair(82, -57), Pair(-123, 7), Pair(-63, -63), Pair(-97, -8)
      },
      { // Piece 5
        Pair(-44, -47), Pair(-8, -44), Pair(17, -143), Pair(86, 28), Pair(82, -26), Pair(48, -78), Pair(98, 180), Pair(-9, 128),
        Pair(1, -21), Pair(-40, -26), Pair(6, -22), Pair(114, -18), Pair(-2, 74), Pair(0, 0), Pair(78, 113), Pair(10, 215),
        Pair(44, -57), Pair(49, -49), Pair(54, -5), Pair(-131, 61), Pair(2, 60), Pair(0, 65), Pair(333, 51), Pair(136, 18),
        Pair(-42, 55), Pair(-142, -4), Pair(-84, 46), Pair(149, -4), Pair(21, 35), Pair(87, 19), Pair(54, 58), Pair(59, 53),
        Pair(-54, -57), Pair(-187, 22), Pair(-141, 21), Pair(-86, 29), Pair(-25, 36), Pair(72, -13), Pair(222, 12), Pair(-9, 42),
        Pair(-55, 5), Pair(-173, -15), Pair(104, -51), Pair(220, -52), Pair(-80, -24), Pair(11, -4), Pair(-143, 20), Pair(87, -32),
        Pair(-84, -44), Pair(-184, 85), Pair(138, -49), Pair(-111, -8), Pair(-32, -36), Pair(0, -33), Pair(56, -26), Pair(32, -21),
        Pair(-182, -66), Pair(-119, 21), Pair(-39, -43), Pair(-74, -12), Pair(-117, -16), Pair(-46, 43), Pair(-12, -48), Pair(-15, -10)
      }
    }},
    {{ // Bucket 14
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(37, -1), Pair(-56, 25), Pair(-45, 59), Pair(145, 9), Pair(-67, 28), Pair(33, 18), Pair(-81, 18), Pair(-37, -43),
        Pair(5, -9), Pair(-57, 66), Pair(-40, 42), Pair(87, 2), Pair(10, -13), Pair(41, -16), Pair(94, -85), Pair(-7, -24),
        Pair(42, -5), Pair(-36, 37), Pair(-18, 8), Pair(24, 19), Pair(-15, 10), Pair(43, 40), Pair(13, -17), Pair(-16, 25),
        Pair(-2, 5), Pair(-8, 14), Pair(-18, 30), Pair(21, 6), Pair(-8, 11), Pair(-17, 14), Pair(39, -50), Pair(-10, 26),
        Pair(-2, 24), Pair(12, -2), Pair(-4, 11), Pair(13, -1), Pair(-24, 11), Pair(0, 30), Pair(3, -15), Pair(-29, 20),
        Pair(-28, 50), Pair(15, -10), Pair(-15, 30), Pair(17, -13), Pair(-38, 17), Pair(3, 23), Pair(3, -23), Pair(-23, -4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(37, 74), Pair(28, 35), Pair(31, -64), Pair(-82, 62), Pair(180, 32), Pair(-314, 149), Pair(143, -78), Pair(-15, -2),
        Pair(-124, 15), Pair(-173, 102), Pair(106, 51), Pair(-26, 26), Pair(248, 40), Pair(220, 10), Pair(0, 0), Pair(245, -69),
        Pair(93, 38), Pair(4, 44), Pair(-52, 68), Pair(87, 29), Pair(141, -12), Pair(93, 58), Pair(40, 40), Pair(118, 72),
        Pair(41, 55), Pair(49, 72), Pair(53, 46), Pair(123, 78), Pair(-9, 40), Pair(135, 22), Pair(40, 32), Pair(76, 82),
        Pair(-48, 4), Pair(72, 9), Pair(43, 21), Pair(49, 7), Pair(83, 51), Pair(37, 47), Pair(73, 54), Pair(19, -6),
        Pair(-32, 41), Pair(-14, 80), Pair(73, -61), Pair(28, 73), Pair(-54, 54), Pair(17, -25), Pair(-44, 71), Pair(15, -142),
        Pair(178, 16), Pair(56, 18), Pair(-3, -1), Pair(-18, 12), Pair(-59, 55), Pair(25, 0), Pair(-24, -103), Pair(221, -81),
        Pair(-67, -37), Pair(-18, 33), Pair(-101, 112), Pair(-205, 141), Pair(90, -45), Pair(35, -17), Pair(-37, -25), Pair(44, 64)
      },
      { // Piece 2
        Pair(-82, 33), Pair(80, -58), Pair(-59, 54), Pair(137, -105), Pair(-52, 61), Pair(10, 1), Pair(-223, -26), Pair(-52, -96),
        Pair(-182, -117), Pair(30, 42), Pair(284, -85), Pair(167, -69), Pair(397, -150), Pair(27, 103), Pair(0, 0), Pair(-32, 149),
        Pair(166, -19), Pair(184, -116), Pair(13, 18), Pair(159, -49), Pair(176, 50), Pair(102, -25), Pair(94, 89), Pair(9, -24),
        Pair(-83, -71), Pair(2, 114), Pair(44, -43), Pair(137, -34), Pair(170, -8), Pair(-53, 97), Pair(95, -80), Pair(93, 58),
        Pair(-115, 49), Pair(174, -65), Pair(5, 57), Pair(127, 0), Pair(-20, 83), Pair(25, -62), Pair(99, -10), Pair(89, -94),
        Pair(-100, 60), Pair(204, -2), Pair(156, -21), Pair(109, -16), Pair(56, -109), Pair(16, 27), Pair(29, -81), Pair(30, 15),
        Pair(-58, 5), Pair(79, -20), Pair(-79, 59), Pair(-6, -47), Pair(8, 41), Pair(23, -40), Pair(11, 62), Pair(-138, 67),
        Pair(91, 12), Pair(87, -65), Pair(-4, -63), Pair(-22, 36), Pair(-16, -59), Pair(-100, 26), Pair(40, -111), Pair(-12, -80)
      },
      { // Piece 3
        Pair(-208, 144), Pair(260, 40), Pair(84, 33), Pair(-26, 83), Pair(-8, 71), Pair(32, 131), Pair(-100, -169), Pair(102, 102),
        Pair(341, -70), Pair(38, 1), Pair(-7, 11), Pair(131, -69), Pair(44, 5), Pair(28, 21), Pair(0, 0), Pair(-30, 66),
        Pair(49, 45), Pair(56, 10), Pair(136, 29), Pair(334, -76), Pair(48, -20), Pair(-55, 61), Pair(87, 31), Pair(181, 23),
        Pair(-218, 111), Pair(-51, 50), Pair(-56, 60), Pair(-56, 17), Pair(25, -84), Pair(12, 54), Pair(49, 22), Pair(-15, 46),
        Pair(2, 71), Pair(27, 20), Pair(29, -17), Pair(135, -20), Pair(56, 102), Pair(-41, 111), Pair(181, -12), Pair(21, 106),
        Pair(-201, 57), Pair(-140, 79), Pair(-258, 233), Pair(3, 78), Pair(19, 34), Pair(12, -8), Pair(170, -3), Pair(-151, 79),
        Pair(-49, -51), Pair(-97, 63), Pair(24, 21), Pair(32, -30), Pair(79, 2), Pair(-40, 47), Pair(100, -41), Pair(-29, 21),
        Pair(24, -58), Pair(-22, 1), Pair(-29, -14), Pair(8, -7), Pair(57, -3), Pair(-37, 12), Pair(109, -20), Pair(33, -17)
      },
      { // Piece 4
        Pair(324, -110), Pair(-191, -127), Pair(-8, 31), Pair(-104, -50), Pair(-51, 14), Pair(268, -236), Pair(-36, -36), Pair(140, -208),
        Pair(86, -77), Pair(13, -91), Pair(-120, 49), Pair(77, 35), Pair(209, -272), Pair(202, -66), Pair(0, 0), Pair(-50, -195),
        Pair(-1, -4), Pair(-86, -160), Pair(157, -68), Pair(-144, 129), Pair(103, -53), Pair(132, -188), Pair(-126, 48), Pair(6, 20),
        Pair(156, -163), Pair(-132, 42), Pair(68, -65), Pair(11, 4), Pair(-30, -81), Pair(1, 61), Pair(-53, -31), Pair(25, -28),
        Pair(-52, -192), Pair(-125, -48), Pair(0, -105), Pair(-11, -77), Pair(29, -42), Pair(-173, 79), Pair(-65, 96), Pair(-70, -19),
        Pair(56, -206), Pair(-127, 71), Pair(-72, 22), Pair(58, -97), Pair(-123, 87), Pair(-26, 6), Pair(-61, 16), Pair(31, -19),
        Pair(-125, 2), Pair(-45, -184), Pair(-56, -13), Pair(-87, 20), Pair(-115, -59), Pair(-96, 63), Pair(27, -90), Pair(87, -136),
        Pair(-8, -139), Pair(-26, -85), Pair(-156, 268), Pair(-148, 227), Pair(20, -131), Pair(-35, -77), Pair(-289, 141), Pair(367, 59)
      },
      { // Piece 5
        Pair(-1, -69), Pair(6, -129), Pair(0, -29), Pair(-24, 195), Pair(29, 23), Pair(-89, 8), Pair(-108, -114), Pair(-72, 10),
        Pair(-51, -8), Pair(-14, 0), Pair(-43, -27), Pair(68, -52), Pair(61, -6), Pair(-146, 151), Pair(0, 0), Pair(-135, 139),
        Pair(-201, 26), Pair(-93, -11), Pair(-28, 4), Pair(-17, -28), Pair(95, 47), Pair(220, 39), Pair(51, 66), Pair(-2, 93),
        Pair(-45, -28), Pair(-65, 12), Pair(-8, 15), Pair(297, -19), Pair(100, -10), Pair(100, 47), Pair(22, 59), Pair(90, 69),
        Pair(15, -32), Pair(143, -28), Pair(-188, 33), Pair(23, -33), Pair(-103, 23), Pair(60, -16), Pair(56, 7), Pair(-40, 28),
        Pair(-142, -20), Pair(-35, 19), Pair(51, 0), Pair(-10, 31), Pair(21, -13), Pair(-102, 0), Pair(109, -39), Pair(24, -1),
        Pair(36, -41), Pair(30, -78), Pair(-89, -3), Pair(-41, -3), Pair(-43, -2), Pair(-53, 5), Pair(65, 1), Pair(96, -10),
        Pair(62, -109), Pair(-52, -24), Pair(-26, -8), Pair(-149, 53), Pair(-84, 33), Pair(38, -15), Pair(43, -57), Pair(49, -26)
      }
    }},
    {{ // Bucket 15
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(111, 31), Pair(36, 56), Pair(105, 27), Pair(-215, 117), Pair(91, 57), Pair(-16, 38), Pair(-37, -43), Pair(23, -70),
        Pair(15, 55), Pair(-33, 31), Pair(-58, 45), Pair(77, 22), Pair(61, -5), Pair(-21, 10), Pair(-83, -3), Pair(-2, -108),
        Pair(-3, 21), Pair(-19, 13), Pair(1, 26), Pair(-7, 33), Pair(4, 34), Pair(-9, 24), Pair(-10, 44), Pair(16, -30),
        Pair(-6, 24), Pair(-42, 23), Pair(-13, 29), Pair(4, 16), Pair(2, 17), Pair(-10, 14), Pair(-2, 40), Pair(15, -5),
        Pair(-32, 40), Pair(-24, 15), Pair(2, 20), Pair(11, 4), Pair(21, 15), Pair(23, 14), Pair(-27, 18), Pair(7, 28),
        Pair(-27, 43), Pair(-27, 28), Pair(-5, 13), Pair(-7, -13), Pair(12, 25), Pair(-1, 21), Pair(-26, 25), Pair(15, 14),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(14, 218), Pair(0, 46), Pair(-41, -31), Pair(-11, -1), Pair(6, 52), Pair(-69, 73), Pair(43, 18), Pair(146, 168),
        Pair(176, 48), Pair(17, 69), Pair(59, -18), Pair(2, 23), Pair(142, -22), Pair(183, 94), Pair(-300, 45), Pair(0, 0),
        Pair(-218, 64), Pair(-52, 46), Pair(172, -8), Pair(-49, 9), Pair(128, 20), Pair(65, -49), Pair(57, 93), Pair(30, 60),
        Pair(-53, -6), Pair(14, 44), Pair(-11, 78), Pair(50, 42), Pair(104, 76), Pair(1, 52), Pair(146, -11), Pair(76, 60),
        Pair(41, 59), Pair(-162, 91), Pair(43, 5), Pair(32, -15), Pair(122, -25), Pair(13, 22), Pair(5, 28), Pair(133, 0),
        Pair(14, 18), Pair(115, -78), Pair(31, -56), Pair(181, -25), Pair(-53, -53), Pair(61, -14), Pair(-17, -7), Pair(82, -46),
        Pair(90, -2), Pair(49, -38), Pair(4, 27), Pair(10, -11), Pair(8, -38), Pair(-6, 13), Pair(22, 35), Pair(-40, 26),
        Pair(-128, 49), Pair(-53, 19), Pair(-1, -33), Pair(-112, -76), Pair(-112, 28), Pair(-156, 60), Pair(58, -44), Pair(-80, 26)
      },
      { // Piece 2
        Pair(43, -133), Pair(-20, 5), Pair(140, -88), Pair(-53, 44), Pair(68, -48), Pair(24, 132), Pair(225, -44), Pair(108, -14),
        Pair(-150, 42), Pair(107, -100), Pair(173, -9), Pair(-132, -58), Pair(255, 15), Pair(297, -110), Pair(81, 80), Pair(0, 0),
        Pair(-69, -58), Pair(-54, 67), Pair(2, -70), Pair(21, 70), Pair(251, -77), Pair(-18, 163), Pair(241, -92), Pair(99, 117),
        Pair(-67, 68), Pair(150, -116), Pair(-28, 70), Pair(44, -55), Pair(171, 65), Pair(202, -71), Pair(8, 55), Pair(-21, 30),
        Pair(61, -46), Pair(-21, 22), Pair(33, -62), Pair(86, 66), Pair(235, -85), Pair(53, 37), Pair(24, -9), Pair(-62, -50),
        Pair(66, 17), Pair(56, -27), Pair(160, 8), Pair(131, -74), Pair(84, 18), Pair(112, -100), Pair(-7, -8), Pair(111, -126),
        Pair(-99, 25), Pair(98, -1), Pair(197, -107), Pair(19, 5), Pair(26, -98), Pair(120, -14), Pair(32, -119), Pair(126, -195),
        Pair(83, 74), Pair(232, -83), Pair(72, -17), Pair(97, -117), Pair(-178, 98), Pair(60, -125), Pair(122, -67), Pair(67, -24)
      },
      { // Piece 3
        Pair(-131, 91), Pair(-133, 111), Pair(-234, 138), Pair(112, 52), Pair(147, 28), Pair(103, 59), Pair(60, 107), Pair(273, -253),
        Pair(90, 13), Pair(270, -25), Pair(12, 38), Pair(44, 25), Pair(218, -31), Pair(157, 14), Pair(4, 83), Pair(0, 0),
        Pair(141, -19), Pair(38, -11), Pair(144, -10), Pair(22, 57), Pair(105, 22), Pair(47, 58), Pair(-3, 93), Pair(-49, 96),
        Pair(-43, 77), Pair(170, -20), Pair(200, -42), Pair(90, 3), Pair(99, 0), Pair(214, -27), Pair(-9, 106), Pair(-12, 74),
        Pair(15, 64), Pair(-58, 83), Pair(-56, 67), Pair(203, -21), Pair(115, 10), Pair(20, 17), Pair(54, 90), Pair(-14, 42),
        Pair(-104, 28), Pair(-17, 49), Pair(203, 26), Pair(-21, 74), Pair(-46, 35), Pair(-95, 40), Pair(95, 1), Pair(-80, 66),
        Pair(-34, 35), Pair(72, 29), Pair(16, 57), Pair(-60, 36), Pair(44, 11), Pair(92, 17), Pair(49, 31), Pair(85, 20),
        Pair(15, -18), Pair(24, 12), Pair(44, -37), Pair(56, 33), Pair(91, -22), Pair(89, -13), Pair(36, 70), Pair(100, -30)
      },
      { // Piece 4
        Pair(-71, 30), Pair(-102, -67), Pair(21, 6), Pair(-44, -66), Pair(130, 53), Pair(-91, -86), Pair(-21, 12), Pair(-44, -156),
        Pair(112, 9), Pair(240, -263), Pair(68, -96), Pair(161, -213), Pair(73, -63), Pair(24, -78), Pair(147, -17), Pair(0, 0),
        Pair(-3, -58), Pair(147, -53), Pair(-18, -92), Pair(-7, 87), Pair(-10, -56), Pair(14, -108), Pair(-17, 29), Pair(37, 183),
        Pair(41, -34), Pair(-3, 101), Pair(80, -41), Pair(88, -127), Pair(82, -57), Pair(4, 56), Pair(35, -35), Pair(-42, 26),
        Pair(45, -116), Pair(-38, -66), Pair(46, 10), Pair(39, 22), Pair(69, -5), Pair(-29, 91), Pair(-37, 103), Pair(147, -189),
        Pair(-99, 18), Pair(1, 99), Pair(37, 36), Pair(-32, 91), Pair(-17, 168), Pair(-68, 117), Pair(110, -123), Pair(73, -240),
        Pair(-56, 69), Pair(-80, 112), Pair(75, 87), Pair(-24, -55), Pair(-53, -13), Pair(56, -44), Pair(30, 26), Pair(-78, -30),
        Pair(-37, -5), Pair(20, 119), Pair(29, -72), Pair(20, 29), Pair(-52, 88), Pair(-90, -22), Pair(80, -76), Pair(-35, -1)
      },
      { // Piece 5
        Pair(2, 78), Pair(-104, 97), Pair(-21, -45), Pair(-54, -94), Pair(-25, -16), Pair(-95, 64), Pair(76, 18), Pair(250, -390),
        Pair(71, 87), Pair(50, 10), Pair(-167, 47), Pair(-97, -84), Pair(32, -74), Pair(-57, 134), Pair(228, 75), Pair(0, 0),
        Pair(5, 71), Pair(55, 32), Pair(184, -31), Pair(-20, -14), Pair(109, -12), Pair(-83, 101), Pair(162, 34), Pair(-160, 81),
        Pair(243, -19), Pair(-36, 34), Pair(71, 0), Pair(26, -6), Pair(122, -36), Pair(122, 8), Pair(175, 5), Pair(186, 38),
        Pair(-37, -23), Pair(-1, 10), Pair(32, 5), Pair(101, -24), Pair(-45, -4), Pair(24, -33), Pair(57, 11), Pair(63, 10),
        Pair(-162, 22), Pair(-85, 23), Pair(29, 6), Pair(1, 3), Pair(-72, 23), Pair(-43, -15), Pair(-28, 1), Pair(56, 1),
        Pair(-62, -46), Pair(-50, 0), Pair(-146, 13), Pair(51, -19), Pair(-108, 37), Pair(-87, 21), Pair(-4, 13), Pair(21, 22),
        Pair(-2, -114), Pair(-7, -33), Pair(-29, 1), Pair(-43, 3), Pair(-17, -30), Pair(-26, 6), Pair(-5, 34), Pair(-54, 2)
      }
    }},
    {{ // Bucket 16
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-62, -82), Pair(33, -16), Pair(-1, 34), Pair(-26, 73), Pair(-36, 66), Pair(40, 2), Pair(5, -9), Pair(15, 55),
        Pair(3, 53), Pair(-22, 1), Pair(5, 25), Pair(6, 37), Pair(15, 39), Pair(2, 17), Pair(-1, 25), Pair(-26, 43),
        Pair(-15, -13), Pair(-17, -1), Pair(-3, 19), Pair(-12, 22), Pair(-7, 20), Pair(15, 17), Pair(-17, 27), Pair(-16, 19),
        Pair(-2, 2), Pair(-9, 31), Pair(-8, 16), Pair(2, 12), Pair(-4, 18), Pair(-6, 14), Pair(-4, 18), Pair(-7, 22),
        Pair(-14, 41), Pair(-12, 21), Pair(-11, 13), Pair(-5, 9), Pair(-5, 14), Pair(4, 20), Pair(-4, 21), Pair(-8, 23),
        Pair(-12, 24), Pair(-13, 21), Pair(-7, 14), Pair(-10, 27), Pair(-9, 17), Pair(-1, 22), Pair(-6, 24), Pair(-7, 22),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(217, -53), Pair(-147, 56), Pair(120, 71), Pair(36, 40), Pair(52, 40), Pair(70, 55), Pair(46, 97), Pair(194, 53),
        Pair(17, -29), Pair(91, 35), Pair(81, 89), Pair(31, 87), Pair(20, 100), Pair(67, 56), Pair(-55, 85), Pair(-128, 137),
        Pair(0, 0), Pair(47, 98), Pair(52, 112), Pair(28, 76), Pair(5, 90), Pair(-33, 62), Pair(-52, 112), Pair(-9, 71),
        Pair(60, 100), Pair(41, 97), Pair(34, 50), Pair(32, 87), Pair(29, 78), Pair(11, 73), Pair(19, 30), Pair(-29, 58),
        Pair(-8, 75), Pair(32, 75), Pair(11, 87), Pair(43, 73), Pair(-6, 80), Pair(31, 62), Pair(9, 83), Pair(19, 69),
        Pair(27, 72), Pair(27, 57), Pair(25, 52), Pair(24, 60), Pair(8, 69), Pair(27, 39), Pair(27, 46), Pair(-17, 29),
        Pair(30, 34), Pair(33, 48), Pair(45, 49), Pair(25, 38), Pair(41, 27), Pair(5, 48), Pair(3, 68), Pair(38, 66),
        Pair(-222, 87), Pair(19, 5), Pair(30, 7), Pair(26, 46), Pair(-14, 41), Pair(24, 20), Pair(19, 48), Pair(-36, 7)
      },
      { // Piece 2
        Pair(22, 47), Pair(241, 30), Pair(111, -8), Pair(56, 12), Pair(89, -26), Pair(3, 57), Pair(230, -40), Pair(45, 42),
        Pair(31, -16), Pair(173, 42), Pair(100, 44), Pair(95, -2), Pair(86, 28), Pair(51, 38), Pair(89, -16), Pair(27, 18),
        Pair(0, 0), Pair(110, 67), Pair(140, 13), Pair(76, 60), Pair(72, 12), Pair(29, 32), Pair(75, -1), Pair(-8, 80),
        Pair(46, 62), Pair(87, 40), Pair(73, 71), Pair(105, 36), Pair(47, 41), Pair(19, 25), Pair(48, 47), Pair(22, 31),
        Pair(94, 32), Pair(51, 66), Pair(43, 36), Pair(61, 38), Pair(35, 39), Pair(32, 77), Pair(67, 37), Pair(51, 73),
        Pair(30, 28), Pair(50, 30), Pair(20, 46), Pair(55, 40), Pair(47, 55), Pair(52, 49), Pair(51, 66), Pair(14, 22),
        Pair(13, 4), Pair(18, 37), Pair(43, 23), Pair(35, 36), Pair(44, 46), Pair(79, 58), Pair(38, 43), Pair(66, 49),
        Pair(33, -18), Pair(25, 40), Pair(20, 25), Pair(17, 43), Pair(56, 34), Pair(52, 39), Pair(108, 37), Pair(63, 65)
      },
      { // Piece 3
        Pair(62, 39), Pair(58, 115), Pair(-20, 114), Pair(82, 112), Pair(-25, 120), Pair(64, 84), Pair(35, 94), Pair(53, 113),
        Pair(8, -7), Pair(50, 132), Pair(-1, 151), Pair(36, 124), Pair(57, 116), Pair(79, 100), Pair(-8, 151), Pair(33, 152),
        Pair(0, 0), Pair(54, 106), Pair(62, 106), Pair(64, 104), Pair(101, 88), Pair(-46, 135), Pair(-2, 135), Pair(61, 128),
        Pair(-28, 103), Pair(-29, 145), Pair(45, 131), Pair(47, 109), Pair(31, 98), Pair(-6, 126), Pair(-24, 115), Pair(15, 127),
        Pair(18, 100), Pair(-5, 167), Pair(20, 127), Pair(9, 130), Pair(31, 146), Pair(56, 69), Pair(83, 97), Pair(-22, 146),
        Pair(2, 97), Pair(-14, 135), Pair(16, 109), Pair(49, 77), Pair(25, 107), Pair(12, 93), Pair(71, 105), Pair(9, 112),
        Pair(26, 100), Pair(37, 101), Pair(29, 100), Pair(20, 107), Pair(9, 113), Pair(3, 95), Pair(-12, 120), Pair(28, 143),
        Pair(1, 91), Pair(28, 115), Pair(30, 103), Pair(27, 98), Pair(28, 91), Pair(26, 93), Pair(11, 101), Pair(21, 105)
      },
      { // Piece 4
        Pair(90, 101), Pair(72, 141), Pair(81, 146), Pair(44, 136), Pair(186, 38), Pair(14, 178), Pair(5, 203), Pair(55, 137),
        Pair(50, -34), Pair(95, 174), Pair(147, 127), Pair(46, 164), Pair(116, 144), Pair(91, 146), Pair(81, 142), Pair(35, 158),
        Pair(0, 0), Pair(37, 213), Pair(67, 153), Pair(96, 138), Pair(25, 158), Pair(117, 106), Pair(46, 166), Pair(75, 125),
        Pair(78, 137), Pair(44, 196), Pair(78, 138), Pair(82, 163), Pair(59, 197), Pair(34, 210), Pair(51, 120), Pair(93, 131),
        Pair(56, 158), Pair(72, 130), Pair(65, 161), Pair(70, 175), Pair(79, 178), Pair(66, 180), Pair(56, 117), Pair(54, 129),
        Pair(15, 196), Pair(58, 149), Pair(49, 152), Pair(79, 119), Pair(88, 154), Pair(65, 149), Pair(71, 144), Pair(61, 87),
        Pair(55, 149), Pair(52, 170), Pair(57, 134), Pair(74, 135), Pair(63, 142), Pair(93, 96), Pair(56, 123), Pair(96, 68),
        Pair(56, 134), Pair(77, 138), Pair(83, 141), Pair(70, 114), Pair(60, 139), Pair(104, 91), Pair(54, 171), Pair(111, -16)
      },
      { // Piece 5
        Pair(-5, -50), Pair(-96, 51), Pair(-105, 57), Pair(-2, -21), Pair(-11, 20), Pair(9, 33), Pair(-9, 4), Pair(61, -34),
        Pair(-59, -135), Pair(-46, 70), Pair(-108, 110), Pair(-13, -9), Pair(122, -17), Pair(195, 8), Pair(257, -13), Pair(144, 4),
        Pair(0, 0), Pair(277, 0), Pair(161, 33), Pair(167, 39), Pair(179, -1), Pair(80, 40), Pair(104, 5), Pair(-247, 77),
        Pair(142, 47), Pair(261, 17), Pair(119, 62), Pair(294, -1), Pair(-89, 81), Pair(-33, 33), Pair(-78, 42), Pair(-61, 32),
        Pair(44, 42), Pair(165, 64), Pair(95, 40), Pair(56, 53), Pair(-29, 47), Pair(-24, 32), Pair(0, 36), Pair(-72, 23),
        Pair(97, 100), Pair(53, 66), Pair(73, 25), Pair(-36, 58), Pair(-16, 33), Pair(-47, 31), Pair(-56, 14), Pair(-108, 6),
        Pair(63, 64), Pair(100, 6), Pair(18, 37), Pair(-29, 29), Pair(-21, 18), Pair(-27, 19), Pair(-28, 7), Pair(-28, -18),
        Pair(139, 5), Pair(66, 23), Pair(49, -3), Pair(-13, 12), Pair(-19, -2), Pair(-19, 13), Pair(-13, 0), Pair(-27, -21)
      }
    }},
    {{ // Bucket 17
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-65, 15), Pair(-2, -92), Pair(58, -8), Pair(-58, 43), Pair(-31, 26), Pair(-104, 83), Pair(-57, 66), Pair(-33, 31),
        Pair(-23, 1), Pair(-6, 61), Pair(-1, 35), Pair(-2, 30), Pair(-37, 38), Pair(-21, 21), Pair(-14, 55), Pair(13, 29),
        Pair(-8, 23), Pair(-5, -60), Pair(2, 9), Pair(-1, 16), Pair(1, 18), Pair(-8, 19), Pair(-16, 17), Pair(-23, 34),
        Pair(-5, 27), Pair(-13, 6), Pair(-18, 21), Pair(-2, 19), Pair(-3, 17), Pair(-3, 16), Pair(-1, 25), Pair(-6, 22),
        Pair(-7, 19), Pair(-9, 18), Pair(-13, 29), Pair(-10, 18), Pair(-9, 15), Pair(4, 21), Pair(1, 17), Pair(-5, 23),
        Pair(-26, 34), Pair(-3, 1), Pair(-15, 24), Pair(5, 1), Pair(-15, 17), Pair(-1, 22), Pair(2, 19), Pair(-9, 30),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(60, 79), Pair(-344, 138), Pair(17, 77), Pair(-92, 115), Pair(-80, 35), Pair(79, 46), Pair(-152, 97), Pair(70, 396),
        Pair(34, 107), Pair(-71, -12), Pair(94, 108), Pair(112, 61), Pair(-7, 66), Pair(-5, 111), Pair(138, 44), Pair(144, -10),
        Pair(-36, 157), Pair(0, 0), Pair(90, 92), Pair(25, 81), Pair(26, 97), Pair(126, 46), Pair(87, 5), Pair(-89, 105),
        Pair(93, 91), Pair(30, 119), Pair(45, 103), Pair(56, 63), Pair(31, 80), Pair(55, 68), Pair(5, 26), Pair(50, 34),
        Pair(23, 76), Pair(70, 95), Pair(66, 55), Pair(34, 62), Pair(18, 75), Pair(33, 72), Pair(-14, 106), Pair(30, -1),
        Pair(56, 30), Pair(39, 74), Pair(32, 61), Pair(35, 70), Pair(37, 76), Pair(41, 32), Pair(63, 35), Pair(-1, 68),
        Pair(5, 12), Pair(95, 79), Pair(63, 30), Pair(33, 65), Pair(15, 43), Pair(61, 41), Pair(67, 33), Pair(52, 57),
        Pair(37, -6), Pair(26, 46), Pair(11, 22), Pair(-11, 53), Pair(97, 3), Pair(75, 60), Pair(41, 44), Pair(24, 50)
      },
      { // Piece 2
        Pair(201, 35), Pair(102, -3), Pair(99, 15), Pair(118, 3), Pair(31, 48), Pair(314, -22), Pair(-99, 88), Pair(20, -4),
        Pair(60, -33), Pair(38, 16), Pair(121, 34), Pair(66, 54), Pair(180, -4), Pair(-26, 73), Pair(28, -18), Pair(-5, 30),
        Pair(76, 64), Pair(0, 0), Pair(158, 44), Pair(84, 3), Pair(17, 110), Pair(188, -12), Pair(9, 66), Pair(26, -14),
        Pair(42, 18), Pair(74, 93), Pair(104, 4), Pair(57, 84), Pair(79, 41), Pair(25, 54), Pair(21, 7), Pair(28, 80),
        Pair(4, 97), Pair(45, 59), Pair(38, 75), Pair(81, 28), Pair(27, 103), Pair(73, 41), Pair(73, 48), Pair(34, 1),
        Pair(42, 40), Pair(19, 31), Pair(35, 19), Pair(42, 75), Pair(80, 18), Pair(63, 80), Pair(58, 34), Pair(59, 44),
        Pair(75, -10), Pair(47, 1), Pair(41, 71), Pair(57, 24), Pair(41, 70), Pair(86, 12), Pair(55, 58), Pair(83, 13),
        Pair(-2, 21), Pair(67, 10), Pair(12, 22), Pair(41, 36), Pair(38, 32), Pair(31, 79), Pair(23, 37), Pair(7, 59)
      },
      { // Piece 3
        Pair(12, 133), Pair(-24, 69), Pair(-15, 153), Pair(8, 135), Pair(42, 107), Pair(40, 104), Pair(-49, 145), Pair(141, 44),
        Pair(30, 142), Pair(-62, 10), Pair(45, 148), Pair(37, 138), Pair(60, 132), Pair(71, 106), Pair(-31, 159), Pair(-65, 172),
        Pair(55, 118), Pair(0, 0), Pair(103, 93), Pair(15, 114), Pair(-15, 138), Pair(-16, 123), Pair(-24, 144), Pair(94, 120),
        Pair(21, 116), Pair(26, 90), Pair(32, 129), Pair(49, 128), Pair(26, 115), Pair(70, 109), Pair(-3, 157), Pair(32, 107),
        Pair(41, 100), Pair(-15, 93), Pair(61, 132), Pair(25, 107), Pair(30, 118), Pair(95, 77), Pair(-44, 105), Pair(11, 110),
        Pair(21, 119), Pair(-26, 138), Pair(25, 122), Pair(40, 112), Pair(-8, 157), Pair(36, 116), Pair(11, 118), Pair(22, 128),
        Pair(-2, 125), Pair(-10, 127), Pair(9, 133), Pair(39, 101), Pair(9, 121), Pair(32, 80), Pair(-3, 86), Pair(72, 116),
        Pair(19, 109), Pair(17, 91), Pair(23, 115), Pair(44, 90), Pair(21, 127), Pair(18, 115), Pair(1, 110), Pair(32, 73)
      },
      { // Piece 4
        Pair(30, 209), Pair(77, 52), Pair(46, 131), Pair(35, 159), Pair(69, 160), Pair(125, 141), Pair(158, 74), Pair(7, 187),
        Pair(37, 134), Pair(37, 13), Pair(22, 199), Pair(77, 189), Pair(6, 147), Pair(48, 251), Pair(-31, 329), Pair(-49, 297),
        Pair(28, 172), Pair(0, 0), Pair(71, 137), Pair(45, 164), Pair(119, 114), Pair(-46, 246), Pair(99, 75), Pair(16, 160),
        Pair(104, 82), Pair(59, 175), Pair(94, 138), Pair(86, 187), Pair(1, 200), Pair(99, 122), Pair(62, 104), Pair(12, 204),
        Pair(49, 142), Pair(54, 152), Pair(83, 123), Pair(76, 156), Pair(47, 154), Pair(23, 184), Pair(40, 181), Pair(123, 46),
        Pair(54, 190), Pair(45, 120), Pair(12, 225), Pair(26, 143), Pair(49, 170), Pair(47, 137), Pair(36, 186), Pair(76, 125),
        Pair(54, 108), Pair(62, 127), Pair(38, 153), Pair(49, 182), Pair(51, 164), Pair(82, 123), Pair(97, 112), Pair(114, 93),
        Pair(55, 73), Pair(48, 176), Pair(37, 135), Pair(35, 158), Pair(49, 112), Pair(75, 128), Pair(45, 24), Pair(143, 24)
      },
      { // Piece 5
        Pair(-31, 255), Pair(111, 78), Pair(-196, 207), Pair(52, 28), Pair(5, -5), Pair(50, 18), Pair(-109, 7), Pair(-48, -40),
        Pair(28, -1), Pair(209, -7), Pair(237, 0), Pair(37, 66), Pair(187, -7), Pair(-68, 71), Pair(72, -7), Pair(-71, 53),
        Pair(20, 84), Pair(0, 0), Pair(210, 57), Pair(-8, 108), Pair(29, 66), Pair(-12, 21), Pair(-8, 52), Pair(-136, 52),
        Pair(113, 65), Pair(223, 39), Pair(245, 49), Pair(63, 59), Pair(56, 38), Pair(-79, 51), Pair(69, -7), Pair(-74, 20),
        Pair(213, 49), Pair(151, 38), Pair(116, 67), Pair(83, 46), Pair(12, 28), Pair(-11, 22), Pair(-136, 36), Pair(-58, 21),
        Pair(78, 83), Pair(31, 27), Pair(59, 55), Pair(-1, 51), Pair(-42, 21), Pair(-21, 0), Pair(-71, 18), Pair(-106, 3),
        Pair(27, 21), Pair(71, -1), Pair(-6, 48), Pair(16, 26), Pair(-28, 17), Pair(-34, 20), Pair(-28, -13), Pair(-24, -10),
        Pair(-92, 58), Pair(69, 73), Pair(66, 43), Pair(20, 2), Pair(-43, 10), Pair(-45, -5), Pair(-24, -8), Pair(-45, -29)
      }
    }},
    {{ // Bucket 18
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-32, 27), Pair(31, -16), Pair(-56, -73), Pair(59, -4), Pair(-105, 66), Pair(-40, 73), Pair(-40, 42), Pair(-58, 44),
        Pair(5, 24), Pair(-1, 34), Pair(12, 41), Pair(-11, 63), Pair(7, 12), Pair(24, 20), Pair(19, 35), Pair(-41, 49),
        Pair(8, 20), Pair(16, 26), Pair(-6, -51), Pair(-4, 36), Pair(0, 27), Pair(10, 21), Pair(-12, 23), Pair(14, 9),
        Pair(-11, 27), Pair(6, 20), Pair(-6, -13), Pair(-11, 27), Pair(-1, 18), Pair(8, 10), Pair(5, 18), Pair(-6, 19),
        Pair(-11, 21), Pair(-4, 11), Pair(-9, 3), Pair(-13, 19), Pair(5, 8), Pair(-7, 21), Pair(1, 11), Pair(3, 20),
        Pair(-14, 24), Pair(-14, 18), Pair(-15, -9), Pair(-5, 9), Pair(-2, 2), Pair(-8, 24), Pair(0, 15), Pair(5, 25),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-104, 137), Pair(191, 27), Pair(84, 80), Pair(-79, 59), Pair(-68, 70), Pair(-63, 27), Pair(64, 132), Pair(53, 91),
        Pair(58, 136), Pair(52, 122), Pair(23, 30), Pair(52, 69), Pair(53, 120), Pair(-35, 65), Pair(285, 7), Pair(-4, 22),
        Pair(54, 72), Pair(103, 73), Pair(0, 0), Pair(57, 107), Pair(104, 82), Pair(60, 47), Pair(105, 16), Pair(-15, 117),
        Pair(-22, 85), Pair(43, 143), Pair(4, 104), Pair(63, 122), Pair(20, 67), Pair(77, 91), Pair(-12, 55), Pair(85, 46),
        Pair(45, 52), Pair(59, 58), Pair(28, 131), Pair(43, 68), Pair(1, 94), Pair(19, 86), Pair(35, 49), Pair(-8, 95),
        Pair(20, 88), Pair(26, 59), Pair(28, 80), Pair(18, 80), Pair(31, 67), Pair(25, 57), Pair(40, 67), Pair(-21, 60),
        Pair(-20, 28), Pair(13, 14), Pair(34, 112), Pair(22, 65), Pair(10, 67), Pair(27, 68), Pair(-25, 101), Pair(23, 32),
        Pair(124, -16), Pair(13, 71), Pair(16, 41), Pair(29, 76), Pair(27, 24), Pair(-24, 51), Pair(-13, 19), Pair(37, 34)
      },
      { // Piece 2
        Pair(-46, -8), Pair(79, 59), Pair(239, -38), Pair(189, 50), Pair(71, 1), Pair(192, -8), Pair(113, 7), Pair(118, 7),
        Pair(10, 87), Pair(58, 9), Pair(52, -29), Pair(159, 23), Pair(30, 45), Pair(77, -8), Pair(25, 43), Pair(22, -20),
        Pair(33, 58), Pair(115, 68), Pair(0, 0), Pair(180, 37), Pair(88, 17), Pair(73, 73), Pair(54, 3), Pair(66, -22),
        Pair(59, 80), Pair(61, 25), Pair(76, 73), Pair(79, 33), Pair(80, 92), Pair(92, 35), Pair(49, 20), Pair(-6, 29),
        Pair(74, 45), Pair(76, 72), Pair(32, 32), Pair(35, 75), Pair(40, 40), Pair(88, 76), Pair(77, 25), Pair(101, 78),
        Pair(51, 31), Pair(37, 32), Pair(36, 78), Pair(37, 29), Pair(45, 83), Pair(37, 22), Pair(61, 66), Pair(49, 55),
        Pair(21, -10), Pair(20, 59), Pair(15, 14), Pair(33, 92), Pair(24, 33), Pair(78, 57), Pair(51, 36), Pair(40, 96),
        Pair(36, -13), Pair(30, 20), Pair(26, 75), Pair(-14, 39), Pair(26, 54), Pair(27, 59), Pair(89, 28), Pair(55, 18)
      },
      { // Piece 3
        Pair(-4, 128), Pair(106, 110), Pair(41, 57), Pair(-84, 215), Pair(80, 142), Pair(30, 138), Pair(-171, 182), Pair(45, 130),
        Pair(-9, 152), Pair(29, 151), Pair(-46, 27), Pair(40, 139), Pair(15, 122), Pair(34, 144), Pair(-135, 167), Pair(-18, 160),
        Pair(13, 144), Pair(-16, 130), Pair(0, 0), Pair(48, 113), Pair(29, 138), Pair(-9, 107), Pair(10, 147), Pair(-47, 158),
        Pair(45, 128), Pair(-7, 152), Pair(5, 101), Pair(-69, 141), Pair(22, 99), Pair(19, 121), Pair(-46, 164), Pair(-61, 142),
        Pair(7, 142), Pair(-54, 161), Pair(47, 107), Pair(-6, 138), Pair(1, 106), Pair(-43, 117), Pair(-32, 127), Pair(-23, 120),
        Pair(-8, 108), Pair(30, 109), Pair(9, 107), Pair(-3, 134), Pair(6, 129), Pair(23, 79), Pair(-6, 104), Pair(-50, 184),
        Pair(-10, 138), Pair(-8, 121), Pair(23, 95), Pair(-21, 143), Pair(23, 103), Pair(-19, 159), Pair(-13, 53), Pair(64, 89),
        Pair(4, 99), Pair(19, 122), Pair(18, 94), Pair(-2, 126), Pair(20, 112), Pair(-1, 108), Pair(-41, 128), Pair(-15, 90)
      },
      { // Piece 4
        Pair(23, 82), Pair(-8, 256), Pair(97, 38), Pair(191, 8), Pair(129, 103), Pair(-3, 207), Pair(33, 74), Pair(371, -99),
        Pair(99, 96), Pair(73, 149), Pair(91, -90), Pair(71, 140), Pair(123, 61), Pair(114, 106), Pair(105, 270), Pair(50, 93),
        Pair(95, 87), Pair(32, 134), Pair(0, 0), Pair(30, 174), Pair(31, 177), Pair(18, 156), Pair(42, 141), Pair(93, 69),
        Pair(67, 109), Pair(59, 144), Pair(29, 153), Pair(12, 162), Pair(50, 141), Pair(31, 235), Pair(32, 146), Pair(56, 170),
        Pair(68, 58), Pair(17, 139), Pair(50, 130), Pair(81, 134), Pair(76, 81), Pair(-30, 254), Pair(-22, 220), Pair(54, 121),
        Pair(73, 53), Pair(53, 139), Pair(53, 115), Pair(65, 97), Pair(18, 185), Pair(49, 145), Pair(29, 238), Pair(51, 121),
        Pair(90, 104), Pair(56, 103), Pair(40, 114), Pair(54, 89), Pair(45, 130), Pair(47, 74), Pair(53, 95), Pair(44, 160),
        Pair(82, 34), Pair(83, 48), Pair(47, 110), Pair(44, 157), Pair(45, 157), Pair(84, 44), Pair(147, -11), Pair(-15, 134)
      },
      { // Piece 5
        Pair(175, 99), Pair(47, 156), Pair(201, 5), Pair(44, 159), Pair(-19, 38), Pair(-13, 90), Pair(-59, -16), Pair(1, -49),
        Pair(25, 151), Pair(216, 11), Pair(221, 5), Pair(282, -23), Pair(357, 15), Pair(-7, 81), Pair(-48, 46), Pair(32, -57),
        Pair(174, 39), Pair(179, 87), Pair(0, 0), Pair(173, 75), Pair(132, 82), Pair(-157, 93), Pair(112, 49), Pair(7, 14),
        Pair(9, 79), Pair(238, 58), Pair(140, 66), Pair(143, 72), Pair(49, 72), Pair(-5, 58), Pair(-101, 42), Pair(-58, 37),
        Pair(107, 24), Pair(47, 81), Pair(115, 43), Pair(79, 70), Pair(35, 37), Pair(-43, 34), Pair(-14, 32), Pair(-165, 40),
        Pair(54, 21), Pair(23, 46), Pair(57, 13), Pair(6, 34), Pair(-22, 26), Pair(-55, 22), Pair(-35, 0), Pair(-77, 7),
        Pair(30, 20), Pair(-43, 20), Pair(-41, 32), Pair(-120, 68), Pair(-78, 27), Pair(-56, 4), Pair(-41, -5), Pair(-61, -3),
        Pair(75, -70), Pair(9, 16), Pair(-37, 4), Pair(-53, 17), Pair(-26, 9), Pair(-72, -3), Pair(-38, -12), Pair(-28, -18)
      }
    }},
    {{ // Bucket 19
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-27, 47), Pair(-1, 54), Pair(-49, 42), Pair(-52, -51), Pair(6, -4), Pair(-1, 42), Pair(86, 2), Pair(77, 23),
        Pair(6, 36), Pair(-2, 31), Pair(-9, 61), Pair(16, 32), Pair(7, 39), Pair(20, 16), Pair(-28, 36), Pair(1, 37),
        Pair(11, 17), Pair(3, 23), Pair(16, 42), Pair(-10, -47), Pair(12, 32), Pair(-3, 18), Pair(1, 22), Pair(-5, 21),
        Pair(-6, 22), Pair(3, 14), Pair(-14, 33), Pair(0, 2), Pair(-8, 33), Pair(5, 12), Pair(-8, 15), Pair(0, 21),
        Pair(-4, 20), Pair(-1, 14), Pair(-13, 19), Pair(-3, 4), Pair(-7, 21), Pair(2, 19), Pair(-1, 9), Pair(3, 12),
        Pair(-8, 18), Pair(-1, 13), Pair(-16, 6), Pair(-5, -17), Pair(-19, 36), Pair(-4, 15), Pair(-3, 10), Pair(1, 17),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(75, -9), Pair(-43, 90), Pair(33, 78), Pair(60, 61), Pair(-72, 119), Pair(-190, 119), Pair(-245, 119), Pair(100, 195),
        Pair(108, 62), Pair(78, 131), Pair(35, 108), Pair(-20, -31), Pair(92, 82), Pair(-85, 157), Pair(20, 77), Pair(62, 47),
        Pair(19, 117), Pair(0, 122), Pair(39, 77), Pair(0, 0), Pair(120, 68), Pair(63, 92), Pair(-2, 91), Pair(14, 96),
        Pair(-2, 109), Pair(46, 57), Pair(46, 117), Pair(44, 134), Pair(15, 134), Pair(36, 61), Pair(-3, 98), Pair(-22, 95),
        Pair(56, 50), Pair(112, 38), Pair(52, 83), Pair(-9, 108), Pair(20, 98), Pair(14, 83), Pair(22, 60), Pair(32, 54),
        Pair(-9, 133), Pair(40, 63), Pair(11, 84), Pair(13, 88), Pair(60, 50), Pair(18, 50), Pair(29, 67), Pair(26, 99),
        Pair(23, 47), Pair(1, 57), Pair(12, 52), Pair(10, 73), Pair(-5, 56), Pair(1, 85), Pair(63, 2), Pair(14, 112),
        Pair(63, 29), Pair(-6, 57), Pair(8, 70), Pair(5, 68), Pair(22, 65), Pair(8, 102), Pair(-21, 54), Pair(-34, -20)
      },
      { // Piece 2
        Pair(-51, 87), Pair(-12, 101), Pair(284, 4), Pair(-28, 33), Pair(-22, 101), Pair(-108, 70), Pair(-194, 72), Pair(80, 24),
        Pair(65, 36), Pair(18, 86), Pair(100, 45), Pair(-24, -1), Pair(209, -2), Pair(93, 59), Pair(-56, 56), Pair(-9, 81),
        Pair(87, 72), Pair(56, 23), Pair(89, 84), Pair(0, 0), Pair(83, 79), Pair(66, 51), Pair(92, 77), Pair(18, 56),
        Pair(83, 34), Pair(14, 110), Pair(38, 30), Pair(79, 72), Pair(39, 60), Pair(65, 75), Pair(58, 54), Pair(48, 97),
        Pair(64, 25), Pair(41, 46), Pair(4, 90), Pair(54, 22), Pair(8, 79), Pair(38, 47), Pair(24, 113), Pair(49, 18),
        Pair(13, 46), Pair(47, 37), Pair(44, 42), Pair(23, 76), Pair(15, 33), Pair(22, 71), Pair(62, 35), Pair(27, 78),
        Pair(51, 13), Pair(7, 74), Pair(1, 49), Pair(16, 35), Pair(5, 100), Pair(35, 51), Pair(32, 50), Pair(55, 34),
        Pair(21, 47), Pair(24, 48), Pair(2, 65), Pair(38, 53), Pair(69, 31), Pair(17, 80), Pair(5, 52), Pair(87, 62)
      },
      { // Piece 3
        Pair(-34, 142), Pair(-16, 173), Pair(26, 140), Pair(-21, 98), Pair(85, 141), Pair(104, 124), Pair(-69, 135), Pair(-77, 161),
        Pair(58, 120), Pair(45, 131), Pair(33, 140), Pair(-69, 30), Pair(69, 130), Pair(-55, 153), Pair(118, 130), Pair(-42, 172),
        Pair(9, 118), Pair(29, 104), Pair(-4, 117), Pair(0, 0), Pair(74, 106), Pair(-4, 149), Pair(59, 103), Pair(34, 140),
        Pair(41, 107), Pair(38, 118), Pair(21, 121), Pair(20, 86), Pair(2, 132), Pair(32, 109), Pair(-25, 129), Pair(-55, 129),
        Pair(-16, 138), Pair(10, 119), Pair(9, 131), Pair(29, 93), Pair(-31, 156), Pair(48, 96), Pair(47, 78), Pair(1, 105),
        Pair(10, 87), Pair(-3, 94), Pair(-15, 128), Pair(-9, 114), Pair(24, 109), Pair(-11, 121), Pair(-1, 103), Pair(32, 94),
        Pair(-35, 122), Pair(-8, 112), Pair(10, 102), Pair(-6, 113), Pair(-9, 104), Pair(22, 107), Pair(21, 102), Pair(-82, 85),
        Pair(8, 106), Pair(7, 101), Pair(-2, 117), Pair(37, 75), Pair(18, 107), Pair(8, 93), Pair(32, 89), Pair(3, 88)
      },
      { // Piece 4
        Pair(85, 150), Pair(58, 120), Pair(73, 130), Pair(40, 106), Pair(-24, 226), Pair(157, 15), Pair(194, 45), Pair(166, 19),
        Pair(60, 149), Pair(132, 116), Pair(84, 141), Pair(14, 25), Pair(84, 68), Pair(162, 81), Pair(153, 78), Pair(98, 179),
        Pair(63, 104), Pair(82, 145), Pair(25, 152), Pair(0, 0), Pair(37, 145), Pair(53, 199), Pair(34, 232), Pair(117, 113),
        Pair(42, 172), Pair(31, 211), Pair(32, 173), Pair(90, 80), Pair(66, 112), Pair(73, 113), Pair(80, 139), Pair(77, 152),
        Pair(54, 100), Pair(94, 134), Pair(49, 148), Pair(55, 154), Pair(23, 193), Pair(3, 149), Pair(89, 106), Pair(63, 78),
        Pair(21, 103), Pair(73, 87), Pair(64, 99), Pair(68, 89), Pair(66, 153), Pair(67, 131), Pair(79, 45), Pair(99, 53),
        Pair(53, 103), Pair(56, 143), Pair(51, 135), Pair(57, 125), Pair(11, 184), Pair(34, 118), Pair(66, 117), Pair(-10, 136),
        Pair(70, 15), Pair(73, 107), Pair(65, 94), Pair(52, 132), Pair(87, 47), Pair(52, 101), Pair(103, -13), Pair(102, 8)
      },
      { // Piece 5
        Pair(75, -12), Pair(-54, 131), Pair(103, 178), Pair(29, 84), Pair(6, 117), Pair(22, 5), Pair(-9, 44), Pair(-34, -91),
        Pair(23, 5), Pair(71, 82), Pair(235, 27), Pair(-120, 50), Pair(117, 2), Pair(9, 99), Pair(133, 1), Pair(54, -29),
        Pair(-13, 71), Pair(220, 14), Pair(235, 62), Pair(0, 0), Pair(41, 94), Pair(87, 45), Pair(128, 14), Pair(-156, 35),
        Pair(-8, 39), Pair(50, 28), Pair(143, 48), Pair(32, 110), Pair(148, 46), Pair(-121, 68), Pair(22, -19), Pair(31, 1),
        Pair(21, 22), Pair(81, 15), Pair(21, 51), Pair(5, 43), Pair(-55, 51), Pair(62, -6), Pair(-51, 24), Pair(-4, -4),
        Pair(2, 40), Pair(19, 4), Pair(-19, 29), Pair(-19, 32), Pair(-2, -4), Pair(5, -12), Pair(-22, -7), Pair(-4, -37),
        Pair(-2, 41), Pair(54, -21), Pair(52, -36), Pair(-49, 19), Pair(-59, -7), Pair(6, -17), Pair(-9, -24), Pair(-4, -23),
        Pair(7, -14), Pair(5, -3), Pair(0, -22), Pair(-87, 50), Pair(-29, -28), Pair(-19, -24), Pair(-5, -29), Pair(6, -33)
      }
    }},
    {{ // Bucket 20
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-99, 73), Pair(1, 33), Pair(26, 53), Pair(30, -6), Pair(133, -70), Pair(-38, -6), Pair(10, -13), Pair(61, -4),
        Pair(15, 39), Pair(-36, 38), Pair(7, 12), Pair(6, 39), Pair(2, 25), Pair(-8, 6), Pair(-27, 29), Pair(-7, 30),
        Pair(20, 21), Pair(3, 4), Pair(-12, 14), Pair(13, 37), Pair(5, -46), Pair(34, 18), Pair(1, 16), Pair(31, -1),
        Pair(1, 13), Pair(-2, 18), Pair(10, 9), Pair(-6, 27), Pair(4, 5), Pair(-3, 21), Pair(-2, 18), Pair(0, 15),
        Pair(7, 12), Pair(1, 15), Pair(-3, 16), Pair(-16, 19), Pair(3, -1), Pair(-12, 20), Pair(-11, 16), Pair(0, 14),
        Pair(-3, 20), Pair(-6, 18), Pair(-8, 20), Pair(-14, 23), Pair(1, 1), Pair(-1, 18), Pair(-12, 11), Pair(-10, 14),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(97, 205), Pair(-165, 98), Pair(-26, 83), Pair(102, 41), Pair(36, 102), Pair(29, 30), Pair(193, 12), Pair(-215, 301),
        Pair(-70, 58), Pair(-89, 102), Pair(31, 78), Pair(120, 40), Pair(34, -12), Pair(16, 63), Pair(149, 73), Pair(-56, 107),
        Pair(123, 13), Pair(69, 74), Pair(61, 80), Pair(42, 76), Pair(0, 0), Pair(0, 64), Pair(-4, 87), Pair(-15, 56),
        Pair(-37, 91), Pair(4, 115), Pair(27, 32), Pair(46, 102), Pair(18, 87), Pair(45, 131), Pair(-9, 51), Pair(-30, 98),
        Pair(-30, 43), Pair(92, 31), Pair(-3, 52), Pair(18, 63), Pair(4, 69), Pair(11, 65), Pair(48, 47), Pair(-9, 76),
        Pair(-36, 43), Pair(-26, 31), Pair(5, 45), Pair(11, 43), Pair(0, 67), Pair(-6, 47), Pair(11, 63), Pair(6, 32),
        Pair(-105, 60), Pair(28, -2), Pair(-2, 39), Pair(-27, 42), Pair(-45, 70), Pair(20, 63), Pair(34, 67), Pair(-7, -36),
        Pair(-100, 42), Pair(-23, -18), Pair(64, -46), Pair(21, -22), Pair(-71, 44), Pair(17, 37), Pair(-7, 41), Pair(-81, 22)
      },
      { // Piece 2
        Pair(96, -24), Pair(94, 17), Pair(118, 18), Pair(340, -36), Pair(212, -39), Pair(109, -1), Pair(155, 34), Pair(14, 43),
        Pair(6, 81), Pair(40, 25), Pair(43, 33), Pair(83, 48), Pair(31, -22), Pair(69, 37), Pair(3, 93), Pair(129, -49),
        Pair(-46, 7), Pair(139, 22), Pair(80, -16), Pair(64, 42), Pair(0, 0), Pair(122, 28), Pair(56, 7), Pair(3, 70),
        Pair(14, 48), Pair(20, 35), Pair(60, 82), Pair(28, 29), Pair(27, 94), Pair(56, 13), Pair(3, 88), Pair(35, 26),
        Pair(87, -31), Pair(-22, 71), Pair(2, 33), Pair(50, 47), Pair(-14, 37), Pair(4, 53), Pair(17, 22), Pair(67, 38),
        Pair(14, 55), Pair(-19, 32), Pair(24, 57), Pair(16, 8), Pair(5, 72), Pair(-2, 31), Pair(29, 40), Pair(-12, 41),
        Pair(-7, 53), Pair(-11, 62), Pair(10, -3), Pair(-9, 59), Pair(5, 34), Pair(9, 50), Pair(-11, 36), Pair(-10, 51),
        Pair(-14, 28), Pair(-20, 17), Pair(-20, 45), Pair(25, -2), Pair(-49, 15), Pair(-21, 15), Pair(11, 44), Pair(5, 20)
      },
      { // Piece 3
        Pair(-46, 122), Pair(-72, 158), Pair(26, 101), Pair(-69, 158), Pair(-45, 67), Pair(44, 95), Pair(-282, 186), Pair(-84, 145),
        Pair(8, 79), Pair(-69, 138), Pair(33, 91), Pair(4, 121), Pair(-66, -2), Pair(54, 89), Pair(59, 98), Pair(65, 95),
        Pair(28, 81), Pair(-20, 87), Pair(14, 51), Pair(-3, 74), Pair(0, 0), Pair(-10, 101), Pair(53, 57), Pair(29, 81),
        Pair(53, 60), Pair(-32, 78), Pair(28, 61), Pair(-45, 63), Pair(9, 58), Pair(-58, 99), Pair(10, 42), Pair(-63, 94),
        Pair(-56, 113), Pair(22, 57), Pair(-38, 85), Pair(0, 97), Pair(-45, 79), Pair(-17, 95), Pair(-29, 104), Pair(-24, 66),
        Pair(-44, 57), Pair(-59, 117), Pair(-51, 91), Pair(-14, 75), Pair(13, 56), Pair(-39, 126), Pair(-13, 76), Pair(-50, 83),
        Pair(-45, 74), Pair(-43, 88), Pair(-34, 113), Pair(-39, 60), Pair(-29, 106), Pair(-11, 81), Pair(-32, 68), Pair(-38, 89),
        Pair(-33, 62), Pair(-32, 98), Pair(-22, 84), Pair(-17, 75), Pair(-20, 72), Pair(-29, 100), Pair(-26, 78), Pair(-30, 74)
      },
      { // Piece 4
        Pair(14, 39), Pair(8, 127), Pair(17, 62), Pair(213, -17), Pair(26, -10), Pair(108, -14), Pair(20, 98), Pair(-24, 149),
        Pair(1, 108), Pair(24, 70), Pair(84, -5), Pair(95, 51), Pair(-35, -31), Pair(108, 14), Pair(142, 99), Pair(89, 68),
        Pair(6, 94), Pair(91, 32), Pair(132, -18), Pair(59, 87), Pair(0, 0), Pair(113, 53), Pair(114, -10), Pair(114, 82),
        Pair(89, 83), Pair(98, 2), Pair(72, 70), Pair(18, 68), Pair(58, 37), Pair(71, 33), Pair(76, 127), Pair(91, 114),
        Pair(-6, 124), Pair(57, -11), Pair(44, 92), Pair(68, 57), Pair(40, 99), Pair(47, 89), Pair(4, 86), Pair(9, 65),
        Pair(98, -35), Pair(26, 37), Pair(34, 50), Pair(61, 29), Pair(27, 60), Pair(26, 38), Pair(67, 30), Pair(26, 110),
        Pair(22, -37), Pair(52, 45), Pair(34, 97), Pair(23, 59), Pair(45, 28), Pair(15, 55), Pair(43, 25), Pair(14, 189),
        Pair(45, 18), Pair(55, 38), Pair(49, -39), Pair(26, 67), Pair(31, 21), Pair(55, 49), Pair(121, 9), Pair(192, -135)
      },
      { // Piece 5
        Pair(54, 9), Pair(19, -29), Pair(14, 9), Pair(21, 42), Pair(131, 29), Pair(-42, 129), Pair(-36, -66), Pair(-37, 51),
        Pair(-40, -5), Pair(52, -4), Pair(-43, 16), Pair(98, -6), Pair(42, -21), Pair(198, 33), Pair(133, 41), Pair(-30, 69),
        Pair(71, -49), Pair(-46, 60), Pair(245, -11), Pair(38, 76), Pair(0, 0), Pair(36, 90), Pair(133, 37), Pair(-13, 27),
        Pair(105, -23), Pair(75, -6), Pair(-35, 26), Pair(78, 63), Pair(-37, 86), Pair(78, 54), Pair(-37, 46), Pair(-97, 23),
        Pair(50, -20), Pair(-237, 58), Pair(-2, 21), Pair(-16, 59), Pair(8, 42), Pair(-22, 46), Pair(27, -25), Pair(-39, -6),
        Pair(-229, 79), Pair(19, 4), Pair(-46, -18), Pair(50, 0), Pair(2, 13), Pair(24, -7), Pair(-39, -7), Pair(38, -37),
        Pair(25, -7), Pair(11, -56), Pair(22, -5), Pair(21, -7), Pair(-18, -17), Pair(27, -32), Pair(-1, -22), Pair(-9, -3),
        Pair(-6, -66), Pair(-10, -11), Pair(-2, -29), Pair(15, -13), Pair(-24, -7), Pair(-15, -5), Pair(14, -38), Pair(19, -33)
      }
    }},
    {{ // Bucket 21
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-40, 56), Pair(21, 55), Pair(-40, 70), Pair(48, 57), Pair(110, -40), Pair(-9, -43), Pair(42, -16), Pair(-21, 10),
        Pair(1, 16), Pair(-22, 21), Pair(24, 20), Pair(20, 17), Pair(-10, 6), Pair(16, 17), Pair(14, -1), Pair(-65, 7),
        Pair(1, 14), Pair(14, 8), Pair(14, 25), Pair(-2, 15), Pair(16, 5), Pair(22, -35), Pair(15, 5), Pair(-11, 9),
        Pair(-8, 13), Pair(5, 11), Pair(-5, 15), Pair(16, 14), Pair(0, 21), Pair(-10, 16), Pair(-1, 25), Pair(-12, 11),
        Pair(-3, 13), Pair(-5, 17), Pair(2, 1), Pair(2, 4), Pair(-28, 20), Pair(4, 0), Pair(-5, 14), Pair(-15, 15),
        Pair(-5, 9), Pair(-4, 9), Pair(-9, 15), Pair(19, -18), Pair(-21, 60), Pair(5, 6), Pair(5, 14), Pair(-13, 9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(37, -36), Pair(-7, 61), Pair(27, 1), Pair(129, 60), Pair(-92, 51), Pair(-41, 20), Pair(-102, 101), Pair(-224, -20),
        Pair(29, 30), Pair(123, 28), Pair(34, 78), Pair(63, 39), Pair(24, 62), Pair(-71, 63), Pair(-7, 91), Pair(12, 23),
        Pair(-102, 65), Pair(-86, 62), Pair(20, 33), Pair(0, 80), Pair(20, 72), Pair(0, 0), Pair(141, 67), Pair(36, 67),
        Pair(-78, 63), Pair(-32, 45), Pair(-3, 79), Pair(21, 12), Pair(65, 111), Pair(4, 88), Pair(41, 128), Pair(-50, 56),
        Pair(6, 32), Pair(-27, 67), Pair(-16, 83), Pair(-25, 76), Pair(3, 71), Pair(-41, 56), Pair(58, 39), Pair(5, 21),
        Pair(-81, 88), Pair(-32, 34), Pair(-35, 43), Pair(-12, 65), Pair(6, 69), Pair(-9, 54), Pair(-52, 55), Pair(-28, 76),
        Pair(-62, 29), Pair(-15, -29), Pair(-87, 49), Pair(-42, 24), Pair(1, 3), Pair(-17, 42), Pair(18, 44), Pair(-16, 13),
        Pair(-171, 127), Pair(-38, 10), Pair(-13, 17), Pair(-15, 58), Pair(-5, 5), Pair(-33, 36), Pair(58, -13), Pair(79, -26)
      },
      { // Piece 2
        Pair(76, 29), Pair(199, -76), Pair(84, -10), Pair(76, 3), Pair(-191, 92), Pair(60, -14), Pair(43, 59), Pair(-31, 1),
        Pair(43, -29), Pair(67, -25), Pair(-13, -42), Pair(251, 16), Pair(116, -32), Pair(49, -41), Pair(170, 9), Pair(33, 62),
        Pair(26, 23), Pair(17, -4), Pair(64, 72), Pair(108, -71), Pair(66, 42), Pair(0, 0), Pair(130, 60), Pair(-22, 10),
        Pair(-81, 36), Pair(-23, 78), Pair(80, -49), Pair(26, 74), Pair(61, -12), Pair(-9, 89), Pair(15, 23), Pair(53, 61),
        Pair(32, 56), Pair(-1, -34), Pair(76, 42), Pair(-26, 21), Pair(36, 91), Pair(7, 7), Pair(16, 57), Pair(-15, 14),
        Pair(-7, 9), Pair(1, 23), Pair(8, 2), Pair(-24, 60), Pair(5, -7), Pair(17, 57), Pair(-5, -31), Pair(47, 29),
        Pair(-51, 14), Pair(-3, 9), Pair(39, 43), Pair(-1, -11), Pair(-9, 35), Pair(10, -43), Pair(12, 38), Pair(-6, -39),
        Pair(-35, 23), Pair(29, 34), Pair(-12, -16), Pair(13, 39), Pair(6, -44), Pair(-7, 24), Pair(60, -46), Pair(-27, -28)
      },
      { // Piece 3
        Pair(11, 89), Pair(60, 58), Pair(29, 82), Pair(-8, 115), Pair(42, 91), Pair(-4, 61), Pair(-51, 115), Pair(-4, 116),
        Pair(51, 72), Pair(-12, 76), Pair(-25, 96), Pair(7, 78), Pair(65, 44), Pair(-71, -8), Pair(10, 99), Pair(31, 63),
        Pair(-39, 69), Pair(-34, 68), Pair(42, 22), Pair(7, 53), Pair(-26, 111), Pair(0, 0), Pair(74, 63), Pair(29, 62),
        Pair(-94, 97), Pair(-48, 77), Pair(-7, 57), Pair(3, 59), Pair(-23, 74), Pair(5, 43), Pair(14, 65), Pair(-1, 55),
        Pair(-106, 72), Pair(23, 52), Pair(-78, 69), Pair(-44, 71), Pair(-40, 78), Pair(-4, 37), Pair(59, 32), Pair(50, 46),
        Pair(-39, 97), Pair(-45, 46), Pair(-25, 75), Pair(-50, 59), Pair(-82, 77), Pair(17, 31), Pair(-11, 55), Pair(29, 47),
        Pair(-22, 78), Pair(-9, 38), Pair(-81, 73), Pair(-51, 71), Pair(-71, 59), Pair(-11, 18), Pair(-26, 57), Pair(-37, 103),
        Pair(-29, 44), Pair(-28, 66), Pair(-27, 49), Pair(-13, 45), Pair(-22, 46), Pair(9, 17), Pair(-6, 55), Pair(0, 49)
      },
      { // Piece 4
        Pair(142, -13), Pair(61, 72), Pair(-181, 228), Pair(157, -55), Pair(138, 13), Pair(124, -26), Pair(176, -58), Pair(136, -137),
        Pair(-7, 83), Pair(21, 87), Pair(98, -9), Pair(75, 1), Pair(60, 46), Pair(114, -209), Pair(36, 61), Pair(55, 49),
        Pair(53, 71), Pair(0, 94), Pair(-35, 55), Pair(18, 65), Pair(-103, 140), Pair(0, 0), Pair(137, 12), Pair(149, -1),
        Pair(-28, 96), Pair(20, 54), Pair(83, 17), Pair(61, 72), Pair(35, 22), Pair(67, -30), Pair(75, 103), Pair(99, 104),
        Pair(-3, 51), Pair(10, 77), Pair(45, 54), Pair(-61, 65), Pair(-22, 69), Pair(40, 46), Pair(78, 25), Pair(42, 72),
        Pair(-12, 71), Pair(-66, 146), Pair(25, -17), Pair(3, -3), Pair(-12, 83), Pair(25, 7), Pair(5, 50), Pair(25, 71),
        Pair(44, 49), Pair(4, -12), Pair(5, 21), Pair(28, -15), Pair(-18, 66), Pair(45, -47), Pair(31, 60), Pair(100, -93),
        Pair(27, 38), Pair(-8, 45), Pair(25, 44), Pair(1, 35), Pair(-30, 42), Pair(8, 32), Pair(66, -37), Pair(-35, 195)
      },
      { // Piece 5
        Pair(17, 57), Pair(136, -9), Pair(-56, 22), Pair(82, 15), Pair(-78, 95), Pair(108, 47), Pair(-18, 146), Pair(-43, -2),
        Pair(-3, 58), Pair(-107, 1), Pair(83, -19), Pair(98, -18), Pair(206, -11), Pair(100, 57), Pair(99, 34), Pair(98, 74),
        Pair(-48, -4), Pair(70, -3), Pair(-36, -4), Pair(86, 26), Pair(12, 83), Pair(0, 0), Pair(210, 52), Pair(95, 14),
        Pair(17, -2), Pair(-176, 13), Pair(56, 2), Pair(-63, 65), Pair(144, 44), Pair(0, 40), Pair(72, 20), Pair(122, 54),
        Pair(-218, 44), Pair(18, -27), Pair(-102, 36), Pair(-43, 36), Pair(-21, 66), Pair(0, 31), Pair(61, 26), Pair(34, 21),
        Pair(-11, -27), Pair(-131, -5), Pair(-65, 7), Pair(25, -16), Pair(41, -7), Pair(36, -5), Pair(36, -22), Pair(43, -15),
        Pair(38, -17), Pair(21, -32), Pair(-23, -12), Pair(-75, 6), Pair(23, -42), Pair(-22, -14), Pair(-1, -42), Pair(1, 4),
        Pair(31, -68), Pair(-13, -36), Pair(-25, -30), Pair(0, -6), Pair(-13, -25), Pair(-51, -32), Pair(19, -28), Pair(17, -22)
      }
    }},
    {{ // Bucket 22
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(7, -4), Pair(-10, 24), Pair(-114, 46), Pair(-87, 61), Pair(22, 28), Pair(7, -17), Pair(94, -85), Pair(-82, -3),
        Pair(-1, 25), Pair(-14, 56), Pair(18, 34), Pair(-28, 36), Pair(-26, 29), Pair(13, -4), Pair(7, 40), Pair(-14, -33),
        Pair(-11, 15), Pair(1, 17), Pair(-8, 17), Pair(-11, 30), Pair(8, 11), Pair(0, 2), Pair(9, -67), Pair(-10, 2),
        Pair(-1, 16), Pair(4, 16), Pair(-4, 7), Pair(-13, 26), Pair(-4, 19), Pair(-26, 28), Pair(12, -22), Pair(-2, 21),
        Pair(-7, 18), Pair(-9, 15), Pair(10, 2), Pair(-11, 15), Pair(-12, 13), Pair(-12, 25), Pair(0, -5), Pair(-9, 13),
        Pair(-6, 19), Pair(-5, 15), Pair(2, 12), Pair(-13, -6), Pair(-23, 17), Pair(-18, 23), Pair(-10, -2), Pair(-10, 7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-105, -63), Pair(-129, 126), Pair(-174, 39), Pair(175, -8), Pair(-93, 78), Pair(-47, 67), Pair(-115, 82), Pair(85, 1),
        Pair(-195, 84), Pair(-62, 100), Pair(-75, 124), Pair(-51, 98), Pair(28, 33), Pair(83, 42), Pair(-68, 16), Pair(-40, 100),
        Pair(163, -57), Pair(-143, 103), Pair(62, 46), Pair(-80, 83), Pair(-2, 92), Pair(21, 96), Pair(0, 0), Pair(102, 46),
        Pair(-63, 76), Pair(2, 123), Pair(-24, 36), Pair(5, 79), Pair(25, 34), Pair(22, 79), Pair(-1, 53), Pair(52, 95),
        Pair(-10, 24), Pair(-36, 2), Pair(-47, 47), Pair(-12, 57), Pair(-18, 85), Pair(-24, 57), Pair(4, 62), Pair(-16, 27),
        Pair(-49, 18), Pair(-25, 75), Pair(-19, 30), Pair(-54, 88), Pair(-16, 51), Pair(-28, 54), Pair(-36, 61), Pair(-50, 46),
        Pair(-18, -2), Pair(-92, 6), Pair(-47, 48), Pair(-53, 40), Pair(-26, 53), Pair(-53, 25), Pair(-85, 12), Pair(36, -49),
        Pair(-164, 99), Pair(-33, 7), Pair(46, -23), Pair(-96, 96), Pair(2, -17), Pair(-27, 54), Pair(-28, 47), Pair(-126, -65)
      },
      { // Piece 2
        Pair(-115, -11), Pair(103, -10), Pair(-26, -26), Pair(-65, 32), Pair(229, -39), Pair(243, 3), Pair(53, 0), Pair(17, 25),
        Pair(-33, -42), Pair(81, -27), Pair(-63, 22), Pair(73, -42), Pair(105, 60), Pair(140, -8), Pair(-68, 69), Pair(-40, -92),
        Pair(74, 1), Pair(75, 41), Pair(-31, -38), Pair(43, 40), Pair(76, -53), Pair(10, 106), Pair(0, 0), Pair(4, 23),
        Pair(59, 51), Pair(24, -23), Pair(-10, 70), Pair(50, -18), Pair(4, 84), Pair(36, 14), Pair(-15, 50), Pair(25, 16),
        Pair(-58, -7), Pair(-28, 26), Pair(40, -6), Pair(4, 74), Pair(-19, 13), Pair(-3, 58), Pair(0, -30), Pair(-34, 41),
        Pair(-13, 99), Pair(-17, -20), Pair(-40, 81), Pair(-14, 9), Pair(-2, 42), Pair(4, -28), Pair(-40, 42), Pair(-31, 18),
        Pair(71, -19), Pair(-31, 60), Pair(-5, 19), Pair(-30, 36), Pair(-19, 7), Pair(-27, 27), Pair(-3, -26), Pair(-102, 61),
        Pair(0, 65), Pair(13, -21), Pair(-11, 45), Pair(26, -42), Pair(-85, 85), Pair(-20, -8), Pair(-63, 13), Pair(9, -68)
      },
      { // Piece 3
        Pair(11, 44), Pair(41, 61), Pair(57, 59), Pair(80, 42), Pair(128, 93), Pair(-48, 113), Pair(54, 15), Pair(60, 127),
        Pair(41, 85), Pair(-34, 101), Pair(130, 85), Pair(152, 41), Pair(-16, 107), Pair(79, 111), Pair(-76, -20), Pair(-22, 101),
        Pair(-23, 91), Pair(-10, 70), Pair(19, 79), Pair(-47, 86), Pair(12, 86), Pair(8, 80), Pair(0, 0), Pair(-90, 116),
        Pair(1, 73), Pair(-47, 81), Pair(29, 76), Pair(-67, 102), Pair(-6, 49), Pair(1, 95), Pair(-26, 38), Pair(-21, 66),
        Pair(-39, 87), Pair(-23, 81), Pair(-56, 82), Pair(-18, 61), Pair(-61, 128), Pair(-63, 128), Pair(-49, 5), Pair(-34, 89),
        Pair(-30, 72), Pair(-31, 49), Pair(-58, 58), Pair(-69, 82), Pair(-44, 73), Pair(-8, 95), Pair(13, 8), Pair(-84, 96),
        Pair(-97, 60), Pair(-28, 29), Pair(-59, 104), Pair(-27, 57), Pair(-65, 74), Pair(-20, 32), Pair(-10, 14), Pair(-34, 65),
        Pair(-27, 27), Pair(-30, 63), Pair(-32, 58), Pair(-28, 53), Pair(-17, 57), Pair(-25, 49), Pair(18, -2), Pair(-33, 35)
      },
      { // Piece 4
        Pair(92, -45), Pair(-104, 88), Pair(61, -18), Pair(102, -47), Pair(60, -13), Pair(67, 36), Pair(-18, 58), Pair(88, 45),
        Pair(-64, 134), Pair(49, 28), Pair(37, -77), Pair(-9, -5), Pair(194, -94), Pair(14, 14), Pair(201, -300), Pair(74, -22),
        Pair(63, -63), Pair(59, -9), Pair(-25, 141), Pair(-42, 45), Pair(80, -33), Pair(183, -120), Pair(0, 0), Pair(95, -104),
        Pair(21, -90), Pair(-34, 50), Pair(30, -55), Pair(111, 36), Pair(38, 20), Pair(-10, 34), Pair(15, -80), Pair(51, 8),
        Pair(31, 11), Pair(-51, 145), Pair(26, -36), Pair(15, 11), Pair(54, -3), Pair(-11, -11), Pair(-3, 25), Pair(66, 13),
        Pair(-16, -39), Pair(16, 0), Pair(38, -15), Pair(3, 6), Pair(3, 33), Pair(41, -15), Pair(3, 55), Pair(33, -134),
        Pair(145, -29), Pair(46, -112), Pair(22, 33), Pair(17, -39), Pair(32, -66), Pair(-7, 23), Pair(-26, 62), Pair(16, 26),
        Pair(14, 38), Pair(-6, -31), Pair(-35, 31), Pair(21, -39), Pair(-1, -95), Pair(-5, 54), Pair(-27, 30), Pair(151, -97)
      },
      { // Piece 5
        Pair(-19, 117), Pair(55, -8), Pair(-32, 26), Pair(-34, 12), Pair(-41, 20), Pair(-8, 122), Pair(-47, 28), Pair(-88, 142),
        Pair(-20, 69), Pair(148, -51), Pair(35, -28), Pair(69, -37), Pair(-171, 40), Pair(128, 59), Pair(41, -9), Pair(36, 55),
        Pair(-240, -24), Pair(86, 10), Pair(112, -40), Pair(47, 20), Pair(44, 25), Pair(113, 59), Pair(0, 0), Pair(164, 13),
        Pair(86, 22), Pair(-49, -1), Pair(-104, 6), Pair(210, -20), Pair(-3, 50), Pair(-17, 49), Pair(133, 15), Pair(48, 59),
        Pair(-281, 23), Pair(-40, 13), Pair(103, -28), Pair(-77, 5), Pair(-7, 24), Pair(0, 22), Pair(47, 19), Pair(102, 23),
        Pair(-31, -33), Pair(-21, -6), Pair(-109, 26), Pair(-35, -1), Pair(-60, 3), Pair(44, -9), Pair(7, -8), Pair(48, 10),
        Pair(46, -70), Pair(-13, -16), Pair(-56, -18), Pair(-89, 3), Pair(8, -20), Pair(7, -15), Pair(17, 4), Pair(28, -5),
        Pair(-44, -62), Pair(10, -31), Pair(-37, -16), Pair(-4, -3), Pair(-4, -28), Pair(9, -9), Pair(11, -13), Pair(13, -8)
      }
    }},
    {{ // Bucket 23
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-59, 27), Pair(62, 17), Pair(97, 28), Pair(-61, 63), Pair(-30, 31), Pair(74, -12), Pair(-6, -24), Pair(-2, -108),
        Pair(-27, 43), Pair(14, 30), Pair(-42, 49), Pair(2, 37), Pair(-6, 30), Pair(-65, 9), Pair(-13, -33), Pair(9, 15),
        Pair(-2, 13), Pair(-9, 26), Pair(-19, 22), Pair(6, 16), Pair(-7, 22), Pair(24, -10), Pair(-23, -11), Pair(29, -54),
        Pair(-4, 15), Pair(-2, 13), Pair(0, 12), Pair(-10, 15), Pair(4, 11), Pair(-7, 12), Pair(-4, 25), Pair(14, -4),
        Pair(-1, 21), Pair(-9, 19), Pair(-4, 16), Pair(-5, 1), Pair(-6, 8), Pair(-4, 10), Pair(0, 16), Pair(-5, 2),
        Pair(-8, 25), Pair(-7, 13), Pair(-5, 17), Pair(-16, 7), Pair(1, 18), Pair(-7, 11), Pair(-4, 17), Pair(-7, 9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-39, -21), Pair(4, 132), Pair(-139, 54), Pair(-142, 44), Pair(178, -3), Pair(260, 16), Pair(-68, 120), Pair(17, 21),
        Pair(-74, 34), Pair(42, 51), Pair(-14, 47), Pair(8, 96), Pair(115, 46), Pair(5, 65), Pair(51, 68), Pair(84, -44),
        Pair(-16, 40), Pair(76, 40), Pair(59, 16), Pair(33, 34), Pair(40, 38), Pair(-22, 83), Pair(11, 94), Pair(0, 0),
        Pair(65, -9), Pair(35, 17), Pair(40, 36), Pair(28, 42), Pair(22, 56), Pair(-12, 41), Pair(43, 111), Pair(85, 24),
        Pair(52, 20), Pair(73, 19), Pair(42, 14), Pair(23, 33), Pair(39, 33), Pair(12, 59), Pair(54, 20), Pair(16, 58),
        Pair(38, 8), Pair(28, -9), Pair(24, 4), Pair(15, 20), Pair(20, 49), Pair(19, 20), Pair(27, 24), Pair(62, 24),
        Pair(-10, -25), Pair(29, 0), Pair(57, 9), Pair(38, -6), Pair(50, -37), Pair(33, 7), Pair(-54, 84), Pair(32, -22),
        Pair(54, -98), Pair(44, 8), Pair(-26, 22), Pair(29, 23), Pair(60, -24), Pair(66, -47), Pair(47, -47), Pair(-227, 90)
      },
      { // Piece 2
        Pair(213, -101), Pair(77, -2), Pair(74, -64), Pair(229, -59), Pair(278, -33), Pair(108, -27), Pair(81, 51), Pair(-40, 47),
        Pair(48, -21), Pair(66, -42), Pair(35, -2), Pair(115, -69), Pair(66, -27), Pair(43, 8), Pair(185, 1), Pair(-29, -41),
        Pair(2, -16), Pair(49, -12), Pair(61, -25), Pair(62, -41), Pair(55, 8), Pair(22, -1), Pair(167, -25), Pair(0, 0),
        Pair(21, 14), Pair(61, -41), Pair(-14, 21), Pair(75, -27), Pair(41, 22), Pair(145, -33), Pair(77, 21), Pair(79, 50),
        Pair(48, -8), Pair(20, -24), Pair(54, -2), Pair(38, 8), Pair(99, -51), Pair(28, 20), Pair(46, 12), Pair(67, -23),
        Pair(31, -30), Pair(-6, 0), Pair(27, 14), Pair(60, -66), Pair(34, 13), Pair(30, -26), Pair(5, -40), Pair(57, -41),
        Pair(55, -26), Pair(33, 37), Pair(64, -65), Pair(39, 10), Pair(37, -17), Pair(24, 8), Pair(44, -24), Pair(2, 27),
        Pair(26, 1), Pair(72, -61), Pair(43, -3), Pair(36, -10), Pair(2, -39), Pair(20, -20), Pair(34, 7), Pair(74, -76)
      },
      { // Piece 3
        Pair(82, 31), Pair(34, 41), Pair(3, 68), Pair(168, 21), Pair(72, 34), Pair(42, 59), Pair(147, 39), Pair(64, 1),
        Pair(11, 77), Pair(3, 72), Pair(60, 61), Pair(105, 40), Pair(82, 71), Pair(45, 90), Pair(46, 90), Pair(105, -73),
        Pair(13, 61), Pair(12, 57), Pair(41, 50), Pair(54, 41), Pair(16, 60), Pair(73, 42), Pair(45, 44), Pair(0, 0),
        Pair(16, 74), Pair(0, 37), Pair(61, 34), Pair(16, 56), Pair(53, 31), Pair(11, 33), Pair(-58, 108), Pair(6, -24),
        Pair(60, 30), Pair(-9, 70), Pair(-6, 58), Pair(14, 66), Pair(3, 28), Pair(9, 55), Pair(-65, 80), Pair(-21, 39),
        Pair(1, 44), Pair(-1, 50), Pair(13, 22), Pair(51, -12), Pair(9, 69), Pair(7, 59), Pair(-5, 52), Pair(22, -42),
        Pair(22, 56), Pair(-6, 31), Pair(28, 37), Pair(3, 19), Pair(-1, 73), Pair(24, 35), Pair(-23, 64), Pair(-59, 44),
        Pair(29, 17), Pair(26, 28), Pair(3, 31), Pair(37, 7), Pair(10, 39), Pair(4, 44), Pair(6, 40), Pair(-1, 2)
      },
      { // Piece 4
        Pair(51, 80), Pair(-1, 104), Pair(124, 14), Pair(82, 17), Pair(112, -30), Pair(133, 6), Pair(0, 54), Pair(158, 67),
        Pair(-8, 197), Pair(-20, 113), Pair(51, 46), Pair(-47, 191), Pair(148, 7), Pair(135, 26), Pair(73, 105), Pair(-37, -37),
        Pair(-11, 184), Pair(-39, 109), Pair(28, 68), Pair(69, 108), Pair(33, 68), Pair(171, 16), Pair(36, 62), Pair(0, 0),
        Pair(-49, 138), Pair(1, 99), Pair(89, 66), Pair(17, 158), Pair(71, 76), Pair(53, 58), Pair(75, 68), Pair(72, -116),
        Pair(23, 36), Pair(27, 17), Pair(7, 118), Pair(81, 14), Pair(24, 79), Pair(45, 63), Pair(15, 45), Pair(27, 78),
        Pair(47, -42), Pair(4, 90), Pair(5, 147), Pair(39, 37), Pair(27, 96), Pair(32, 47), Pair(25, 69), Pair(-19, 88),
        Pair(-92, 149), Pair(25, 4), Pair(45, -24), Pair(36, 63), Pair(38, 14), Pair(32, 31), Pair(63, -2), Pair(-4, -13),
        Pair(0, 225), Pair(23, -8), Pair(32, 48), Pair(25, 41), Pair(3, 73), Pair(36, 48), Pair(49, -29), Pair(42, -7)
      },
      { // Piece 5
        Pair(-30, 31), Pair(-133, 23), Pair(-8, -35), Pair(-112, -64), Pair(134, -37), Pair(-44, 45), Pair(-224, 19), Pair(160, -141),
        Pair(-102, -7), Pair(141, -23), Pair(97, -46), Pair(-19, 18), Pair(143, -30), Pair(-61, 148), Pair(19, 43), Pair(65, -170),
        Pair(-60, 53), Pair(48, -12), Pair(5, -6), Pair(121, -31), Pair(54, 39), Pair(185, -2), Pair(394, -54), Pair(0, 0),
        Pair(-112, 7), Pair(-22, 1), Pair(155, -17), Pair(-123, 26), Pair(110, 4), Pair(29, 36), Pair(222, -20), Pair(189, -1),
        Pair(-49, 8), Pair(46, 19), Pair(-165, 34), Pair(-21, 24), Pair(-24, 21), Pair(85, 8), Pair(44, 36), Pair(2, 16),
        Pair(-197, 18), Pair(-35, 20), Pair(-45, 18), Pair(-90, 18), Pair(17, -8), Pair(-12, 9), Pair(54, -9), Pair(45, -22),
        Pair(-12, -53), Pair(-48, 4), Pair(-42, -1), Pair(0, -14), Pair(9, -9), Pair(-16, 11), Pair(6, -9), Pair(20, 24),
        Pair(-16, -46), Pair(-17, -19), Pair(-36, -16), Pair(-7, -15), Pair(-14, -25), Pair(-13, -10), Pair(23, 15), Pair(42, 0)
      }
    }},
    {{ // Bucket 24
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-6, 8), Pair(8, 34), Pair(-52, 39), Pair(7, 31), Pair(-19, 29), Pair(3, 43), Pair(43, -6), Pair(-3, 22),
        Pair(-14, -14), Pair(-8, 22), Pair(8, 20), Pair(14, 19), Pair(19, 20), Pair(3, 15), Pair(-10, 15), Pair(-1, 14),
        Pair(-5, 9), Pair(-18, 1), Pair(-5, 9), Pair(3, 19), Pair(2, 11), Pair(6, 13), Pair(-11, 23), Pair(-6, 16),
        Pair(-3, -9), Pair(-7, 3), Pair(-1, 15), Pair(4, 13), Pair(5, 17), Pair(4, 11), Pair(-2, 23), Pair(-3, 20),
        Pair(2, 17), Pair(-7, 11), Pair(-2, 14), Pair(0, 12), Pair(-2, 16), Pair(-1, 14), Pair(-1, 18), Pair(-2, 20),
        Pair(3, 9), Pair(-5, 8), Pair(-1, 14), Pair(-5, 17), Pair(1, 16), Pair(-6, 18), Pair(-4, 17), Pair(-1, 20),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-38, 124), Pair(-145, 113), Pair(-33, 94), Pair(66, 36), Pair(-14, 47), Pair(32, 10), Pair(94, 6), Pair(-45, 10),
        Pair(21, 43), Pair(32, 57), Pair(30, 80), Pair(20, 76), Pair(23, 57), Pair(14, 66), Pair(-67, 84), Pair(-27, 47),
        Pair(-47, 48), Pair(4, 86), Pair(52, 65), Pair(2, 83), Pair(-4, 75), Pair(-17, 83), Pair(9, 53), Pair(5, 71),
        Pair(0, 0), Pair(7, 78), Pair(17, 82), Pair(30, 73), Pair(6, 82), Pair(2, 74), Pair(-1, 75), Pair(-11, 50),
        Pair(32, 94), Pair(20, 79), Pair(25, 67), Pair(16, 75), Pair(2, 82), Pair(13, 79), Pair(-2, 91), Pair(11, 46),
        Pair(-4, 84), Pair(15, 51), Pair(14, 55), Pair(8, 73), Pair(20, 75), Pair(13, 47), Pair(2, 72), Pair(-2, 76),
        Pair(9, 75), Pair(52, 26), Pair(-2, 74), Pair(12, 54), Pair(9, 66), Pair(1, 69), Pair(-8, 50), Pair(5, 55),
        Pair(67, -48), Pair(5, 17), Pair(-6, 60), Pair(20, 57), Pair(4, 58), Pair(13, 39), Pair(18, 32), Pair(55, -52)
      },
      { // Piece 2
        Pair(-8, 72), Pair(149, 39), Pair(10, 96), Pair(148, -4), Pair(20, 51), Pair(90, 19), Pair(-12, 24), Pair(-30, -3),
        Pair(86, 35), Pair(48, 98), Pair(21, 39), Pair(40, 70), Pair(74, 12), Pair(-26, 66), Pair(0, 3), Pair(-17, 88),
        Pair(20, 46), Pair(45, 66), Pair(32, 79), Pair(19, 32), Pair(8, 61), Pair(26, 27), Pair(-29, 79), Pair(10, 43),
        Pair(0, 0), Pair(19, 72), Pair(22, 50), Pair(22, 84), Pair(22, 42), Pair(22, 84), Pair(24, 38), Pair(6, 77),
        Pair(17, 83), Pair(32, 60), Pair(28, 73), Pair(27, 43), Pair(-2, 97), Pair(21, 32), Pair(32, 62), Pair(17, 14),
        Pair(24, 32), Pair(27, 70), Pair(16, 45), Pair(15, 79), Pair(23, 46), Pair(16, 67), Pair(17, 43), Pair(13, 45),
        Pair(20, 29), Pair(5, 38), Pair(11, 66), Pair(18, 42), Pair(15, 75), Pair(11, 69), Pair(14, 81), Pair(24, 40),
        Pair(44, -18), Pair(-6, 60), Pair(8, 40), Pair(22, 50), Pair(30, 40), Pair(13, 76), Pair(-9, 38), Pair(-8, 84)
      },
      { // Piece 3
        Pair(24, 73), Pair(-34, 130), Pair(-25, 122), Pair(-9, 129), Pair(-63, 144), Pair(42, 99), Pair(-53, 134), Pair(42, 113),
        Pair(-34, 103), Pair(14, 133), Pair(7, 119), Pair(-11, 113), Pair(22, 116), Pair(-15, 121), Pair(-63, 166), Pair(23, 123),
        Pair(-43, 79), Pair(5, 130), Pair(6, 139), Pair(-20, 127), Pair(3, 117), Pair(-24, 119), Pair(29, 130), Pair(-14, 133),
        Pair(0, 0), Pair(11, 137), Pair(4, 133), Pair(6, 119), Pair(22, 110), Pair(-2, 125), Pair(1, 136), Pair(-34, 138),
        Pair(-21, 111), Pair(1, 131), Pair(0, 130), Pair(10, 120), Pair(11, 117), Pair(9, 105), Pair(-17, 116), Pair(4, 95),
        Pair(-24, 107), Pair(-13, 139), Pair(15, 111), Pair(4, 119), Pair(10, 110), Pair(11, 90), Pair(-7, 118), Pair(2, 126),
        Pair(-37, 107), Pair(-1, 112), Pair(7, 104), Pair(10, 118), Pair(-4, 110), Pair(5, 108), Pair(-24, 126), Pair(-21, 122),
        Pair(-19, 92), Pair(-6, 126), Pair(0, 119), Pair(-2, 118), Pair(1, 113), Pair(-1, 109), Pair(2, 116), Pair(10, 96)
      },
      { // Piece 4
        Pair(47, 164), Pair(55, 168), Pair(6, 250), Pair(-35, 240), Pair(-5, 224), Pair(26, 169), Pair(174, 111), Pair(61, 211),
        Pair(7, 211), Pair(40, 193), Pair(56, 176), Pair(36, 171), Pair(66, 172), Pair(26, 233), Pair(12, 226), Pair(54, 150),
        Pair(-22, 148), Pair(38, 215), Pair(22, 212), Pair(21, 180), Pair(60, 177), Pair(11, 218), Pair(41, 154), Pair(8, 192),
        Pair(0, 0), Pair(45, 218), Pair(40, 187), Pair(33, 182), Pair(32, 212), Pair(22, 172), Pair(7, 197), Pair(28, 199),
        Pair(51, 156), Pair(50, 200), Pair(36, 223), Pair(48, 200), Pair(35, 190), Pair(31, 213), Pair(26, 203), Pair(37, 175),
        Pair(3, 246), Pair(45, 170), Pair(37, 189), Pair(49, 187), Pair(58, 204), Pair(37, 201), Pair(50, 153), Pair(75, 156),
        Pair(17, 201), Pair(45, 161), Pair(30, 206), Pair(44, 202), Pair(50, 196), Pair(59, 173), Pair(54, 185), Pair(91, 108),
        Pair(40, 132), Pair(33, 180), Pair(41, 171), Pair(37, 192), Pair(40, 206), Pair(59, 133), Pair(9, 186), Pair(23, 218)
      },
      { // Piece 5
        Pair(121, 1), Pair(134, 92), Pair(-83, 31), Pair(-6, 25), Pair(-41, 64), Pair(-36, 73), Pair(38, -37), Pair(107, -20),
        Pair(-90, 60), Pair(-78, 92), Pair(-19, 54), Pair(-49, 22), Pair(-2, 13), Pair(47, 33), Pair(148, -5), Pair(143, -14),
        Pair(-48, 21), Pair(97, 48), Pair(145, 73), Pair(72, 35), Pair(23, 35), Pair(28, 31), Pair(-57, 60), Pair(-89, 25),
        Pair(0, 0), Pair(70, 67), Pair(51, 52), Pair(30, 59), Pair(29, 31), Pair(-16, 49), Pair(5, 19), Pair(-103, 25),
        Pair(-58, 67), Pair(74, 35), Pair(25, 65), Pair(24, 49), Pair(-30, 51), Pair(-31, 34), Pair(-54, 25), Pair(-95, 28),
        Pair(70, 46), Pair(101, 28), Pair(4, 41), Pair(-6, 36), Pair(-44, 37), Pair(-14, 24), Pair(-25, 17), Pair(-46, 2),
        Pair(60, 32), Pair(121, 4), Pair(71, 15), Pair(-3, 26), Pair(-12, 18), Pair(-12, 18), Pair(-19, 11), Pair(-20, -1),
        Pair(63, -22), Pair(109, -11), Pair(22, -1), Pair(8, 9), Pair(-21, 19), Pair(-41, 17), Pair(-10, 3), Pair(-13, -15)
      }
    }},
    {{ // Bucket 25
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-20, 49), Pair(-5, -19), Pair(12, 40), Pair(20, 13), Pair(-80, 50), Pair(3, 38), Pair(-37, 38), Pair(-19, 12),
        Pair(-17, 0), Pair(-4, -58), Pair(14, 24), Pair(4, 21), Pair(3, 5), Pair(14, 8), Pair(1, 19), Pair(-9, 26),
        Pair(-16, 1), Pair(-3, 18), Pair(-4, 9), Pair(-7, 2), Pair(5, 18), Pair(6, 9), Pair(-5, 16), Pair(-6, 19),
        Pair(-1, 10), Pair(0, -15), Pair(-2, 12), Pair(2, 8), Pair(1, 12), Pair(5, 14), Pair(-3, 19), Pair(-2, 16),
        Pair(-5, 14), Pair(4, 13), Pair(-6, 13), Pair(0, 12), Pair(2, 12), Pair(4, 11), Pair(2, 19), Pair(1, 15),
        Pair(-9, 14), Pair(6, 9), Pair(-10, 19), Pair(3, 4), Pair(-5, 15), Pair(4, 16), Pair(-3, 19), Pair(0, 19),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(4, 69), Pair(256, 19), Pair(89, 50), Pair(1, 108), Pair(45, 26), Pair(-88, 122), Pair(149, 10), Pair(94, -12),
        Pair(48, 52), Pair(4, 67), Pair(-5, 48), Pair(0, 96), Pair(9, 82), Pair(-1, 61), Pair(24, 57), Pair(-9, 59),
        Pair(5, 36), Pair(3, 57), Pair(77, 36), Pair(4, 54), Pair(-2, 83), Pair(10, 65), Pair(-19, 77), Pair(4, 37),
        Pair(12, 89), Pair(0, 0), Pair(17, 83), Pair(14, 74), Pair(16, 74), Pair(1, 75), Pair(-9, 52), Pair(5, 47),
        Pair(8, 113), Pair(47, 77), Pair(23, 80), Pair(9, 57), Pair(-1, 85), Pair(9, 67), Pair(-2, 80), Pair(-2, 58),
        Pair(-11, 14), Pair(21, 60), Pair(-2, 60), Pair(19, 66), Pair(13, 49), Pair(11, 55), Pair(5, 57), Pair(2, 53),
        Pair(-49, 47), Pair(47, 70), Pair(4, 64), Pair(10, 54), Pair(10, 55), Pair(14, 38), Pair(17, 55), Pair(11, 54),
        Pair(-27, 49), Pair(0, 47), Pair(-7, 61), Pair(1, 57), Pair(12, 51), Pair(16, 64), Pair(12, 10), Pair(32, -17)
      },
      { // Piece 2
        Pair(81, 58), Pair(-21, 80), Pair(58, 0), Pair(47, 47), Pair(61, 21), Pair(18, 57), Pair(145, 11), Pair(-93, 56),
        Pair(13, 65), Pair(26, 27), Pair(3, 92), Pair(38, 9), Pair(9, 65), Pair(14, 24), Pair(20, 49), Pair(0, 14),
        Pair(10, 16), Pair(36, 34), Pair(67, -7), Pair(26, 59), Pair(60, 2), Pair(17, 43), Pair(22, 25), Pair(-8, 50),
        Pair(-17, 75), Pair(0, 0), Pair(36, 53), Pair(33, 27), Pair(15, 62), Pair(32, 31), Pair(6, 66), Pair(17, 27),
        Pair(-31, 25), Pair(20, 71), Pair(19, 18), Pair(12, 65), Pair(4, 31), Pair(6, 69), Pair(24, 27), Pair(13, 47),
        Pair(1, 69), Pair(11, 19), Pair(15, 50), Pair(8, 35), Pair(8, 82), Pair(19, 36), Pair(26, 44), Pair(12, 15),
        Pair(24, 24), Pair(7, 50), Pair(10, 26), Pair(5, 61), Pair(12, 28), Pair(10, 75), Pair(18, 38), Pair(20, 92),
        Pair(-4, 55), Pair(4, 27), Pair(8, 50), Pair(22, 16), Pair(1, 54), Pair(2, 37), Pair(76, 23), Pair(22, -10)
      },
      { // Piece 3
        Pair(29, 84), Pair(-69, 75), Pair(-46, 111), Pair(14, 97), Pair(-45, 118), Pair(-83, 135), Pair(-33, 142), Pair(-18, 87),
        Pair(-12, 93), Pair(-72, 89), Pair(-2, 94), Pair(19, 88), Pair(2, 98), Pair(-59, 116), Pair(2, 91), Pair(-44, 94),
        Pair(-26, 115), Pair(-81, 51), Pair(16, 114), Pair(-21, 127), Pair(4, 107), Pair(-45, 110), Pair(-14, 101), Pair(21, 113),
        Pair(-29, 107), Pair(0, 0), Pair(-3, 99), Pair(-18, 102), Pair(-3, 97), Pair(0, 108), Pair(20, 104), Pair(-15, 92),
        Pair(-2, 112), Pair(-2, 64), Pair(10, 111), Pair(-8, 112), Pair(-8, 99), Pair(-3, 96), Pair(-28, 99), Pair(-20, 125),
        Pair(5, 84), Pair(-24, 68), Pair(6, 76), Pair(6, 88), Pair(14, 73), Pair(-17, 76), Pair(-30, 89), Pair(4, 75),
        Pair(-15, 92), Pair(-33, 73), Pair(8, 87), Pair(-4, 93), Pair(-14, 83), Pair(4, 94), Pair(7, 80), Pair(3, 94),
        Pair(-4, 79), Pair(-9, 54), Pair(-2, 95), Pair(0, 90), Pair(-6, 91), Pair(-6, 84), Pair(-11, 74), Pair(0, 77)
      },
      { // Piece 4
        Pair(67, 113), Pair(16, 88), Pair(50, 130), Pair(-29, 138), Pair(-4, 128), Pair(63, 81), Pair(71, 109), Pair(75, 126),
        Pair(14, 87), Pair(-2, 93), Pair(12, 117), Pair(14, 137), Pair(-6, 153), Pair(27, 106), Pair(-8, 142), Pair(-53, 210),
        Pair(1, 64), Pair(-1, 57), Pair(14, 129), Pair(-11, 138), Pair(6, 152), Pair(5, 165), Pair(4, 159), Pair(-47, 167),
        Pair(7, 131), Pair(0, 0), Pair(18, 128), Pair(21, 142), Pair(4, 94), Pair(8, 115), Pair(-19, 141), Pair(-6, 132),
        Pair(-1, 120), Pair(23, 110), Pair(24, 133), Pair(6, 139), Pair(13, 132), Pair(2, 135), Pair(4, 120), Pair(7, 96),
        Pair(11, 96), Pair(16, 84), Pair(8, 132), Pair(22, 124), Pair(10, 118), Pair(18, 133), Pair(3, 98), Pair(18, 95),
        Pair(8, 75), Pair(18, 74), Pair(21, 111), Pair(13, 128), Pair(16, 120), Pair(41, 90), Pair(19, 108), Pair(54, 95),
        Pair(38, 86), Pair(3, 80), Pair(15, 131), Pair(16, 111), Pair(6, 128), Pair(12, 120), Pair(36, 113), Pair(85, 76)
      },
      { // Piece 5
        Pair(-81, 93), Pair(87, 31), Pair(2, 95), Pair(142, 52), Pair(-140, 94), Pair(87, -40), Pair(17, -38), Pair(-6, 78),
        Pair(-211, 94), Pair(-93, 107), Pair(157, 65), Pair(103, 3), Pair(132, 35), Pair(131, 35), Pair(112, 22), Pair(106, 3),
        Pair(62, 52), Pair(-9, 65), Pair(238, 2), Pair(-88, 89), Pair(141, 39), Pair(-16, 58), Pair(15, 35), Pair(-92, 11),
        Pair(66, 35), Pair(0, 0), Pair(105, 62), Pair(98, 45), Pair(-13, 69), Pair(-30, 34), Pair(-87, 23), Pair(-67, 26),
        Pair(81, 50), Pair(92, 40), Pair(97, 38), Pair(43, 44), Pair(-34, 39), Pair(-50, 36), Pair(0, 10), Pair(37, -18),
        Pair(71, 32), Pair(36, 34), Pair(19, 50), Pair(0, 28), Pair(2, 20), Pair(-45, 21), Pair(-39, 12), Pair(-47, 5),
        Pair(109, -6), Pair(40, 24), Pair(7, 38), Pair(-2, 17), Pair(-30, 18), Pair(-21, 9), Pair(-14, 4), Pair(-10, -8),
        Pair(77, -46), Pair(58, -28), Pair(36, 5), Pair(-20, -4), Pair(-10, -9), Pair(-11, -2), Pair(-6, -7), Pair(-9, -15)
      }
    }},
    {{ // Bucket 26
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(19, 3), Pair(3, 38), Pair(-54, 6), Pair(8, 52), Pair(-32, 43), Pair(-46, 30), Pair(-17, 8), Pair(2, 27),
        Pair(-2, 18), Pair(4, 11), Pair(-7, -52), Pair(17, 43), Pair(-13, 11), Pair(15, 23), Pair(-8, 16), Pair(-19, 21),
        Pair(-9, 8), Pair(-4, 9), Pair(1, 0), Pair(-1, 17), Pair(-1, 7), Pair(9, 13), Pair(-1, 22), Pair(-2, 16),
        Pair(-4, 11), Pair(9, 14), Pair(-13, -29), Pair(11, 21), Pair(0, 14), Pair(6, 14), Pair(1, 18), Pair(-4, 20),
        Pair(4, 15), Pair(-6, 13), Pair(1, -8), Pair(-8, 20), Pair(1, 19), Pair(6, 13), Pair(5, 14), Pair(2, 18),
        Pair(-5, 12), Pair(-9, 15), Pair(-2, -6), Pair(0, 35), Pair(-1, 19), Pair(0, 20), Pair(3, 15), Pair(0, 15),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-67, 179), Pair(135, 15), Pair(47, 55), Pair(150, 88), Pair(-31, 134), Pair(51, 47), Pair(-122, 92), Pair(13, 38),
        Pair(48, 95), Pair(34, 98), Pair(37, 71), Pair(-2, 55), Pair(13, 95), Pair(50, 69), Pair(-2, 66), Pair(33, 18),
        Pair(17, 94), Pair(-16, 88), Pair(-42, 50), Pair(52, 79), Pair(15, 66), Pair(30, 70), Pair(11, 72), Pair(-56, 77),
        Pair(-11, 79), Pair(11, 82), Pair(0, 0), Pair(32, 84), Pair(9, 82), Pair(38, 82), Pair(15, 62), Pair(14, 74),
        Pair(-8, 59), Pair(48, 91), Pair(36, 108), Pair(26, 96), Pair(7, 69), Pair(24, 68), Pair(0, 87), Pair(7, 67),
        Pair(8, 91), Pair(13, 57), Pair(18, 75), Pair(17, 71), Pair(30, 82), Pair(10, 77), Pair(3, 77), Pair(26, 64),
        Pair(27, 95), Pair(-3, 55), Pair(12, 88), Pair(11, 84), Pair(0, 74), Pair(25, 55), Pair(-10, 42), Pair(-3, 63),
        Pair(26, 20), Pair(4, 70), Pair(24, 44), Pair(4, 77), Pair(10, 65), Pair(-1, 71), Pair(5, 66), Pair(84, 52)
      },
      { // Piece 2
        Pair(-23, 79), Pair(94, 26), Pair(103, 57), Pair(-8, 21), Pair(59, 51), Pair(25, 17), Pair(65, 21), Pair(116, -25),
        Pair(-8, 28), Pair(55, 70), Pair(0, 37), Pair(76, 44), Pair(67, -6), Pair(61, 35), Pair(48, 5), Pair(24, 40),
        Pair(12, 79), Pair(-42, 44), Pair(-19, 49), Pair(69, 43), Pair(34, 59), Pair(11, 42), Pair(32, 42), Pair(5, 51),
        Pair(-6, 40), Pair(13, 67), Pair(0, 0), Pair(31, 66), Pair(29, 38), Pair(36, 60), Pair(9, 43), Pair(21, 67),
        Pair(35, 56), Pair(0, 4), Pair(28, 93), Pair(20, 24), Pair(30, 73), Pair(23, 41), Pair(26, 54), Pair(18, 31),
        Pair(-18, 3), Pair(22, 70), Pair(8, 29), Pair(12, 72), Pair(7, 34), Pair(12, 78), Pair(25, 13), Pair(-5, 56),
        Pair(8, 20), Pair(-2, 52), Pair(26, 73), Pair(5, 33), Pair(17, 67), Pair(14, 33), Pair(15, 74), Pair(39, 15),
        Pair(11, 52), Pair(36, 52), Pair(-3, 33), Pair(7, 78), Pair(16, 32), Pair(11, 68), Pair(-22, 51), Pair(24, 53)
      },
      { // Piece 3
        Pair(26, 102), Pair(-31, 120), Pair(-34, 81), Pair(10, 127), Pair(-33, 137), Pair(-17, 113), Pair(-1, 121), Pair(16, 111),
        Pair(-13, 128), Pair(2, 116), Pair(-42, 115), Pair(-15, 111), Pair(-15, 113), Pair(-2, 133), Pair(-5, 111), Pair(-31, 128),
        Pair(-6, 120), Pair(19, 113), Pair(-24, 61), Pair(34, 118), Pair(-30, 111), Pair(-21, 122), Pair(16, 107), Pair(26, 106),
        Pair(6, 88), Pair(-14, 103), Pair(0, 0), Pair(-1, 98), Pair(9, 91), Pair(-28, 111), Pair(17, 116), Pair(0, 101),
        Pair(11, 103), Pair(-1, 112), Pair(19, 68), Pair(-14, 129), Pair(-9, 126), Pair(-23, 102), Pair(17, 115), Pair(-24, 124),
        Pair(9, 111), Pair(-3, 120), Pair(7, 62), Pair(-6, 104), Pair(13, 110), Pair(-4, 93), Pair(-18, 111), Pair(-2, 98),
        Pair(-37, 134), Pair(-8, 117), Pair(-18, 73), Pair(-21, 111), Pair(0, 90), Pair(-20, 103), Pair(-22, 104), Pair(-62, 109),
        Pair(-1, 102), Pair(-3, 107), Pair(-8, 77), Pair(0, 92), Pair(-3, 102), Pair(-3, 87), Pair(7, 87), Pair(4, 75)
      },
      { // Piece 4
        Pair(79, 60), Pair(51, 146), Pair(-14, 129), Pair(21, 134), Pair(-5, 175), Pair(12, 138), Pair(29, 171), Pair(78, 148),
        Pair(0, 136), Pair(52, 120), Pair(-6, 81), Pair(5, 164), Pair(42, 104), Pair(-9, 218), Pair(34, 218), Pair(32, 125),
        Pair(12, 180), Pair(28, 126), Pair(27, 16), Pair(6, 180), Pair(8, 175), Pair(-40, 231), Pair(30, 174), Pair(3, 159),
        Pair(11, 143), Pair(1, 133), Pair(0, 0), Pair(41, 164), Pair(23, 173), Pair(15, 169), Pair(36, 135), Pair(-9, 146),
        Pair(30, 145), Pair(42, 122), Pair(33, 125), Pair(35, 123), Pair(27, 154), Pair(-10, 193), Pair(14, 186), Pair(0, 175),
        Pair(18, 117), Pair(37, 125), Pair(13, 144), Pair(33, 123), Pair(18, 158), Pair(27, 154), Pair(15, 186), Pair(17, 141),
        Pair(13, 173), Pair(18, 159), Pair(29, 123), Pair(28, 150), Pair(25, 141), Pair(20, 139), Pair(33, 130), Pair(21, 122),
        Pair(28, 138), Pair(13, 147), Pair(7, 130), Pair(23, 138), Pair(21, 141), Pair(31, 110), Pair(55, 81), Pair(7, 146)
      },
      { // Piece 5
        Pair(-39, 66), Pair(-12, 51), Pair(115, 13), Pair(91, 65), Pair(-22, 22), Pair(352, -115), Pair(-11, 35), Pair(-114, 39),
        Pair(103, -28), Pair(86, 70), Pair(130, 67), Pair(131, 84), Pair(162, 19), Pair(-29, 37), Pair(-203, 6), Pair(-92, 27),
        Pair(248, 31), Pair(259, -13), Pair(122, 23), Pair(208, 9), Pair(84, 74), Pair(92, 21), Pair(65, 9), Pair(-127, 20),
        Pair(118, 27), Pair(138, 47), Pair(0, 0), Pair(190, 45), Pair(109, 20), Pair(120, 12), Pair(12, 1), Pair(-117, 20),
        Pair(-58, 74), Pair(143, 16), Pair(77, 51), Pair(13, 43), Pair(-24, 40), Pair(-50, 18), Pair(-70, 13), Pair(-6, -24),
        Pair(104, 9), Pair(23, 33), Pair(31, 23), Pair(3, 33), Pair(-9, 12), Pair(-10, 1), Pair(9, -13), Pair(-37, -6),
        Pair(23, 2), Pair(50, 7), Pair(51, -14), Pair(35, 1), Pair(-21, -5), Pair(-20, -6), Pair(-9, -15), Pair(-12, -26),
        Pair(39, -16), Pair(12, -17), Pair(31, -11), Pair(40, -33), Pair(-8, -25), Pair(0, -17), Pair(-5, -19), Pair(-12, -33)
      }
    }},
    {{ // Bucket 27
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(8, 14), Pair(-40, 50), Pair(-19, 52), Pair(-15, -11), Pair(-17, 62), Pair(11, -9), Pair(24, 17), Pair(-7, 33),
        Pair(-12, 23), Pair(-3, 18), Pair(-6, 36), Pair(-9, -46), Pair(13, 37), Pair(-3, 14), Pair(-13, 30), Pair(7, 17),
        Pair(0, 15), Pair(-6, 2), Pair(-1, 16), Pair(6, -14), Pair(-4, 23), Pair(-5, 4), Pair(6, 11), Pair(0, 10),
        Pair(-4, 13), Pair(1, 8), Pair(6, 16), Pair(-4, -8), Pair(9, 24), Pair(3, 12), Pair(6, 10), Pair(2, 12),
        Pair(-3, 11), Pair(4, 15), Pair(-8, 18), Pair(12, 8), Pair(-5, 21), Pair(5, 15), Pair(3, 14), Pair(4, 12),
        Pair(-3, 16), Pair(0, 14), Pair(-3, 18), Pair(5, 6), Pair(-2, 23), Pair(-4, 18), Pair(2, 12), Pair(4, 13),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(11, 75), Pair(-22, 101), Pair(68, 94), Pair(-27, 124), Pair(-81, 81), Pair(54, 67), Pair(87, 63), Pair(-31, -7),
        Pair(7, 97), Pair(-25, 137), Pair(-18, 57), Pair(-18, 86), Pair(65, 61), Pair(-10, 82), Pair(67, 50), Pair(-28, 112),
        Pair(24, 56), Pair(19, 50), Pair(62, 58), Pair(-30, 51), Pair(62, 81), Pair(56, 45), Pair(-32, 76), Pair(2, 77),
        Pair(38, 78), Pair(4, 85), Pair(8, 80), Pair(0, 0), Pair(-3, 86), Pair(20, 85), Pair(-1, 89), Pair(-26, 93),
        Pair(5, 71), Pair(-3, 70), Pair(26, 111), Pair(34, 90), Pair(8, 96), Pair(4, 62), Pair(1, 67), Pair(3, 76),
        Pair(11, 83), Pair(6, 76), Pair(-2, 59), Pair(37, 72), Pair(7, 53), Pair(6, 78), Pair(5, 88), Pair(8, 49),
        Pair(9, 5), Pair(21, 53), Pair(-4, 78), Pair(8, 85), Pair(2, 69), Pair(18, 49), Pair(16, 54), Pair(3, 67),
        Pair(-10, 95), Pair(-2, 54), Pair(-9, 46), Pair(18, 58), Pair(1, 59), Pair(1, 83), Pair(14, 40), Pair(50, -9)
      },
      { // Piece 2
        Pair(-117, -26), Pair(14, 25), Pair(125, -36), Pair(68, 50), Pair(140, -38), Pair(23, -2), Pair(14, 6), Pair(32, -6),
        Pair(22, 56), Pair(19, -31), Pair(39, 64), Pair(65, -8), Pair(94, 42), Pair(3, -13), Pair(13, 30), Pair(13, 28),
        Pair(21, 11), Pair(34, 64), Pair(13, -31), Pair(-12, 30), Pair(68, 17), Pair(30, 45), Pair(23, 19), Pair(-3, 88),
        Pair(25, 84), Pair(11, 22), Pair(43, 44), Pair(0, 0), Pair(11, 48), Pair(17, 13), Pair(4, 70), Pair(2, 28),
        Pair(9, 28), Pair(33, 60), Pair(3, -10), Pair(28, 91), Pair(-11, 13), Pair(9, 74), Pair(8, 16), Pair(5, 52),
        Pair(11, 78), Pair(-19, 21), Pair(21, 61), Pair(8, 30), Pair(13, 63), Pair(-8, 7), Pair(17, 65), Pair(10, 3),
        Pair(-26, 10), Pair(8, 63), Pair(3, 12), Pair(18, 65), Pair(-3, 33), Pair(22, 50), Pair(-11, 11), Pair(7, 77),
        Pair(12, 32), Pair(-4, 39), Pair(4, 64), Pair(5, 24), Pair(25, 34), Pair(-8, 40), Pair(29, 44), Pair(6, 4)
      },
      { // Piece 3
        Pair(4, 81), Pair(-27, 120), Pair(-25, 111), Pair(-6, 88), Pair(-23, 114), Pair(-27, 114), Pair(5, 101), Pair(32, 104),
        Pair(-23, 105), Pair(-9, 97), Pair(-15, 105), Pair(-57, 96), Pair(-8, 102), Pair(-13, 99), Pair(-41, 116), Pair(25, 97),
        Pair(-21, 110), Pair(-19, 116), Pair(1, 116), Pair(-72, 43), Pair(0, 119), Pair(8, 99), Pair(-7, 113), Pair(-18, 115),
        Pair(-13, 79), Pair(-12, 88), Pair(3, 81), Pair(0, 0), Pair(-11, 102), Pair(-20, 103), Pair(7, 75), Pair(10, 89),
        Pair(2, 95), Pair(-22, 97), Pair(12, 89), Pair(28, 62), Pair(-1, 109), Pair(1, 79), Pair(-8, 88), Pair(-9, 85),
        Pair(13, 62), Pair(-12, 104), Pair(-2, 86), Pair(-2, 63), Pair(8, 84), Pair(-14, 91), Pair(5, 99), Pair(-10, 89),
        Pair(-18, 79), Pair(-8, 85), Pair(-8, 81), Pair(-11, 77), Pair(-5, 92), Pair(-16, 85), Pair(-13, 74), Pair(4, 70),
        Pair(-2, 83), Pair(-8, 88), Pair(-5, 81), Pair(1, 64), Pair(-7, 82), Pair(-6, 78), Pair(-6, 90), Pair(1, 75)
      },
      { // Piece 4
        Pair(-19, 109), Pair(23, 145), Pair(9, 170), Pair(20, 92), Pair(-26, 180), Pair(114, 101), Pair(54, 133), Pair(26, 158),
        Pair(-4, 134), Pair(9, 92), Pair(17, 165), Pair(40, 95), Pair(32, 113), Pair(-9, 135), Pair(23, 169), Pair(26, 142),
        Pair(-12, 160), Pair(13, 131), Pair(-1, 133), Pair(-23, 23), Pair(-18, 166), Pair(-17, 187), Pair(-41, 214), Pair(-10, 127),
        Pair(-15, 130), Pair(-12, 125), Pair(46, 68), Pair(0, 0), Pair(12, 130), Pair(5, 124), Pair(-11, 142), Pair(-19, 152),
        Pair(12, 123), Pair(22, 123), Pair(15, 113), Pair(36, 97), Pair(-9, 128), Pair(5, 153), Pair(-8, 159), Pair(3, 130),
        Pair(29, 115), Pair(15, 78), Pair(23, 121), Pair(11, 110), Pair(17, 124), Pair(11, 119), Pair(3, 131), Pair(-9, 117),
        Pair(22, 84), Pair(26, 97), Pair(8, 136), Pair(21, 97), Pair(7, 145), Pair(6, 113), Pair(-10, 132), Pair(9, 132),
        Pair(32, 89), Pair(5, 125), Pair(12, 122), Pair(11, 129), Pair(12, 125), Pair(-10, 150), Pair(25, 96), Pair(39, 163)
      },
      { // Piece 5
        Pair(-5, 55), Pair(74, 81), Pair(100, 137), Pair(-166, 141), Pair(84, 42), Pair(118, -5), Pair(18, 26), Pair(-41, 15),
        Pair(100, -7), Pair(213, -3), Pair(-60, 97), Pair(117, 73), Pair(-68, 77), Pair(-30, 55), Pair(20, 14), Pair(190, 16),
        Pair(-159, 50), Pair(76, 43), Pair(204, 12), Pair(62, 42), Pair(98, 52), Pair(89, 26), Pair(91, 21), Pair(-204, 38),
        Pair(93, 3), Pair(37, 17), Pair(-11, 72), Pair(0, 0), Pair(-23, 87), Pair(-11, 23), Pair(-58, 25), Pair(-107, 20),
        Pair(37, 50), Pair(36, 35), Pair(-17, 52), Pair(-43, 76), Pair(-21, 36), Pair(-20, 22), Pair(3, -3), Pair(-26, 6),
        Pair(2, -8), Pair(13, 19), Pair(18, 25), Pair(-34, 56), Pair(2, 17), Pair(3, 6), Pair(-11, -5), Pair(-10, -12),
        Pair(18, 5), Pair(10, 7), Pair(25, 2), Pair(-7, 20), Pair(-26, -5), Pair(-6, -3), Pair(1, -8), Pair(7, -23),
        Pair(-4, -7), Pair(-10, -9), Pair(-7, -33), Pair(-33, -16), Pair(3, -38), Pair(-1, -18), Pair(3, -28), Pair(8, -31)
      }
    }},
    {{ // Bucket 28
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 32), Pair(-8, 29), Pair(-12, 23), Pair(10, 48), Pair(-4, -10), Pair(-25, 28), Pair(-15, 10), Pair(4, 34),
        Pair(-6, 18), Pair(1, 18), Pair(0, 26), Pair(12, 33), Pair(9, -45), Pair(17, 8), Pair(8, 10), Pair(-7, 24),
        Pair(5, 15), Pair(4, 17), Pair(-2, 6), Pair(-3, 23), Pair(10, -18), Pair(9, 15), Pair(-17, 4), Pair(6, 14),
        Pair(-1, 15), Pair(4, 13), Pair(5, 13), Pair(12, 16), Pair(-8, -5), Pair(15, 17), Pair(4, 12), Pair(3, 11),
        Pair(2, 14), Pair(4, 17), Pair(4, 15), Pair(0, 17), Pair(9, 7), Pair(1, 17), Pair(-3, 14), Pair(-5, 13),
        Pair(1, 13), Pair(1, 16), Pair(6, 12), Pair(4, 16), Pair(6, 21), Pair(-7, 21), Pair(-9, 11), Pair(-3, 12),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(27, 20), Pair(-45, 110), Pair(-21, 83), Pair(6, 72), Pair(86, 62), Pair(10, 63), Pair(-74, 164), Pair(-73, 98),
        Pair(17, 71), Pair(47, 57), Pair(-14, 77), Pair(0, 72), Pair(-9, 68), Pair(-5, 31), Pair(-1, 69), Pair(-6, 50),
        Pair(-10, 92), Pair(5, 77), Pair(19, 53), Pair(55, 70), Pair(-16, 45), Pair(24, 86), Pair(2, 57), Pair(34, 23),
        Pair(5, 53), Pair(10, 75), Pair(15, 74), Pair(3, 85), Pair(0, 0), Pair(27, 71), Pair(13, 78), Pair(13, 67),
        Pair(7, 63), Pair(33, 56), Pair(15, 46), Pair(16, 78), Pair(32, 103), Pair(22, 91), Pair(11, 50), Pair(-2, 89),
        Pair(0, 66), Pair(13, 73), Pair(-1, 69), Pair(6, 57), Pair(17, 61), Pair(0, 43), Pair(15, 54), Pair(-10, 56),
        Pair(15, 15), Pair(1, 11), Pair(-7, 79), Pair(0, 56), Pair(3, 78), Pair(-3, 66), Pair(22, 51), Pair(11, 35),
        Pair(32, 17), Pair(2, 32), Pair(17, 38), Pair(-1, 39), Pair(7, 44), Pair(-1, 42), Pair(5, 59), Pair(-21, 99)
      },
      { // Piece 2
        Pair(-44, 63), Pair(-3, -25), Pair(18, 32), Pair(104, -10), Pair(93, 56), Pair(21, -13), Pair(124, 12), Pair(6, 32),
        Pair(13, 11), Pair(15, 60), Pair(-17, -8), Pair(75, 36), Pair(5, 12), Pair(27, 50), Pair(55, -38), Pair(36, 26),
        Pair(24, 62), Pair(12, 22), Pair(19, 56), Pair(35, 31), Pair(-6, 5), Pair(67, -8), Pair(14, 55), Pair(-6, 19),
        Pair(25, 7), Pair(13, 60), Pair(23, 5), Pair(25, 60), Pair(0, 0), Pair(48, 41), Pair(14, 30), Pair(14, 60),
        Pair(20, 40), Pair(17, 13), Pair(18, 52), Pair(-8, 16), Pair(35, 79), Pair(0, -18), Pair(22, 60), Pair(10, 29),
        Pair(-7, 31), Pair(3, 56), Pair(-7, 8), Pair(18, 49), Pair(1, 29), Pair(12, 48), Pair(-31, -3), Pair(1, 78),
        Pair(32, 33), Pair(-19, 22), Pair(27, 33), Pair(-2, 23), Pair(13, 57), Pair(5, 9), Pair(0, 57), Pair(-35, 9),
        Pair(-36, 37), Pair(51, 13), Pair(-11, 28), Pair(5, 46), Pair(0, 3), Pair(9, 39), Pair(-4, 19), Pair(6, 56)
      },
      { // Piece 3
        Pair(12, 75), Pair(37, 77), Pair(5, 83), Pair(28, 75), Pair(-43, 64), Pair(-33, 109), Pair(30, 82), Pair(110, 46),
        Pair(2, 88), Pair(-17, 85), Pair(17, 73), Pair(-13, 79), Pair(-38, 79), Pair(14, 79), Pair(-30, 91), Pair(-22, 96),
        Pair(1, 88), Pair(16, 84), Pair(-17, 95), Pair(6, 97), Pair(-58, 39), Pair(47, 88), Pair(50, 82), Pair(32, 85),
        Pair(-4, 80), Pair(0, 73), Pair(-13, 81), Pair(-6, 66), Pair(0, 0), Pair(3, 52), Pair(-40, 86), Pair(-17, 90),
        Pair(-11, 80), Pair(-4, 77), Pair(4, 70), Pair(-6, 93), Pair(24, 64), Pair(11, 75), Pair(18, 87), Pair(-11, 85),
        Pair(0, 67), Pair(4, 62), Pair(9, 63), Pair(7, 67), Pair(12, 39), Pair(-13, 94), Pair(12, 86), Pair(-7, 75),
        Pair(-14, 83), Pair(-12, 73), Pair(-19, 79), Pair(-10, 80), Pair(-1, 39), Pair(-13, 81), Pair(-6, 86), Pair(-22, 78),
        Pair(-3, 65), Pair(-5, 65), Pair(-7, 75), Pair(-4, 64), Pair(1, 39), Pair(-5, 70), Pair(14, 60), Pair(6, 69)
      },
      { // Piece 4
        Pair(13, 101), Pair(-22, 75), Pair(41, 93), Pair(-1, 146), Pair(-21, 65), Pair(-21, 140), Pair(-30, 115), Pair(84, 87),
        Pair(15, 72), Pair(17, 110), Pair(19, 49), Pair(15, 115), Pair(40, 46), Pair(61, 74), Pair(13, 100), Pair(17, 134),
        Pair(17, 85), Pair(5, 69), Pair(3, 103), Pair(-11, 126), Pair(-14, 26), Pair(53, 134), Pair(24, 186), Pair(38, 151),
        Pair(-10, 119), Pair(22, 60), Pair(5, 72), Pair(24, 65), Pair(0, 0), Pair(20, 89), Pair(14, 136), Pair(26, 83),
        Pair(5, 99), Pair(16, 96), Pair(14, 87), Pair(1, 85), Pair(31, 84), Pair(23, 75), Pair(31, 102), Pair(21, 141),
        Pair(19, 117), Pair(7, 106), Pair(9, 98), Pair(25, 93), Pair(14, 89), Pair(22, 87), Pair(22, 82), Pair(11, 125),
        Pair(1, 64), Pair(14, 66), Pair(17, 92), Pair(21, 88), Pair(25, 72), Pair(17, 91), Pair(22, 81), Pair(19, 55),
        Pair(-6, 91), Pair(27, 84), Pair(24, 81), Pair(12, 100), Pair(20, 75), Pair(11, 73), Pair(-9, 127), Pair(0, 66)
      },
      { // Piece 5
        Pair(-128, 16), Pair(-92, 32), Pair(135, 33), Pair(-75, 34), Pair(-131, 59), Pair(-9, 55), Pair(76, -33), Pair(-87, -84),
        Pair(-60, 8), Pair(131, -21), Pair(88, 3), Pair(93, 82), Pair(144, 42), Pair(-3, 124), Pair(123, 22), Pair(119, 8),
        Pair(52, -23), Pair(-19, 20), Pair(5, 19), Pair(12, 32), Pair(11, 24), Pair(92, 23), Pair(102, 37), Pair(45, 6),
        Pair(-10, 1), Pair(-15, 13), Pair(-39, 31), Pair(-14, 47), Pair(0, 0), Pair(32, 39), Pair(67, 0), Pair(35, 11),
        Pair(-29, 2), Pair(43, -13), Pair(-45, 30), Pair(-46, 37), Pair(2, 48), Pair(-10, 25), Pair(22, 1), Pair(66, -22),
        Pair(-53, 5), Pair(21, -21), Pair(-2, -7), Pair(-30, 17), Pair(-6, 18), Pair(-19, 9), Pair(30, -22), Pair(23, -28),
        Pair(-8, -35), Pair(-28, -19), Pair(-8, -22), Pair(-5, -16), Pair(15, -23), Pair(-12, -16), Pair(9, -28), Pair(13, -32),
        Pair(-20, -27), Pair(-21, -13), Pair(-24, -21), Pair(-28, -37), Pair(2, -56), Pair(-7, -55), Pair(5, -36), Pair(11, -48)
      }
    }},
    {{ // Bucket 29
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-37, 35), Pair(-44, 31), Pair(22, 23), Pair(-21, 37), Pair(-21, 34), Pair(-9, -3), Pair(42, 40), Pair(-9, 24),
        Pair(14, 16), Pair(-8, 20), Pair(9, 21), Pair(-2, 17), Pair(32, 16), Pair(22, -35), Pair(1, 0), Pair(23, -10),
        Pair(3, 11), Pair(8, 12), Pair(10, 11), Pair(-6, 2), Pair(10, 16), Pair(-4, -4), Pair(-10, 4), Pair(-14, -4),
        Pair(0, 13), Pair(1, 18), Pair(12, 8), Pair(6, 10), Pair(14, 10), Pair(-6, -7), Pair(10, 6), Pair(2, 5),
        Pair(0, 15), Pair(6, 13), Pair(2, 12), Pair(7, 12), Pair(-1, 21), Pair(5, 3), Pair(-8, 12), Pair(-2, 15),
        Pair(-1, 15), Pair(1, 13), Pair(0, 14), Pair(4, 22), Pair(3, 24), Pair(5, 11), Pair(-9, 17), Pair(-7, 10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-11, -47), Pair(171, 23), Pair(-43, 81), Pair(-9, 83), Pair(31, 58), Pair(7, 97), Pair(3, 88), Pair(45, 19),
        Pair(-62, 25), Pair(40, 52), Pair(28, 68), Pair(22, 63), Pair(-25, 44), Pair(28, 45), Pair(22, 67), Pair(-48, 32),
        Pair(81, 44), Pair(32, 61), Pair(37, 62), Pair(31, 71), Pair(77, 78), Pair(-12, 57), Pair(11, 57), Pair(-7, 88),
        Pair(5, 43), Pair(20, 63), Pair(41, 78), Pair(13, 84), Pair(16, 75), Pair(0, 0), Pair(17, 80), Pair(-15, 77),
        Pair(2, 78), Pair(13, 55), Pair(16, 52), Pair(7, 58), Pair(40, 92), Pair(25, 99), Pair(21, 83), Pair(-2, 45),
        Pair(-3, 41), Pair(0, 66), Pair(9, 56), Pair(16, 74), Pair(10, 65), Pair(9, 69), Pair(4, 56), Pair(14, 53),
        Pair(-1, 81), Pair(-11, 12), Pair(7, 36), Pair(2, 59), Pair(5, 64), Pair(26, 56), Pair(2, 27), Pair(2, 37),
        Pair(-60, 21), Pair(-9, 43), Pair(-11, 63), Pair(13, 70), Pair(5, 40), Pair(12, 57), Pair(22, 29), Pair(-27, 38)
      },
      { // Piece 2
        Pair(-33, -22), Pair(31, 38), Pair(155, -19), Pair(98, 9), Pair(138, -29), Pair(-1, 61), Pair(170, -9), Pair(67, 63),
        Pair(5, 36), Pair(0, -3), Pair(55, 18), Pair(42, -36), Pair(35, 44), Pair(24, 11), Pair(95, 57), Pair(-90, 50),
        Pair(18, 23), Pair(22, 38), Pair(49, 7), Pair(60, 24), Pair(102, 24), Pair(1, 41), Pair(-63, 37), Pair(28, 60),
        Pair(34, 28), Pair(33, 0), Pair(23, 52), Pair(31, 15), Pair(11, 58), Pair(0, 0), Pair(33, 50), Pair(2, 26),
        Pair(10, -2), Pair(32, 80), Pair(30, 5), Pair(25, 48), Pair(15, 17), Pair(24, 83), Pair(0, -8), Pair(21, 48),
        Pair(7, 39), Pair(15, -1), Pair(20, 48), Pair(0, 15), Pair(23, 61), Pair(15, 26), Pair(13, 44), Pair(-14, -26),
        Pair(39, 18), Pair(13, 60), Pair(6, 22), Pair(22, 57), Pair(8, 8), Pair(20, 30), Pair(1, 19), Pair(3, 47),
        Pair(-5, 63), Pair(-35, 33), Pair(16, 49), Pair(-5, 14), Pair(65, 47), Pair(3, 2), Pair(19, 28), Pair(5, -15)
      },
      { // Piece 3
        Pair(52, 80), Pair(70, 65), Pair(81, 61), Pair(50, 97), Pair(68, 67), Pair(16, 75), Pair(54, 78), Pair(87, 53),
        Pair(38, 79), Pair(21, 93), Pair(50, 67), Pair(32, 73), Pair(-20, 92), Pair(-64, 76), Pair(-12, 99), Pair(-8, 79),
        Pair(32, 81), Pair(16, 94), Pair(16, 72), Pair(50, 78), Pair(61, 69), Pair(77, 4), Pair(75, 76), Pair(46, 74),
        Pair(14, 77), Pair(27, 77), Pair(36, 67), Pair(13, 71), Pair(11, 82), Pair(0, 0), Pair(43, 58), Pair(15, 62),
        Pair(4, 78), Pair(4, 85), Pair(33, 62), Pair(28, 66), Pair(24, 88), Pair(12, 50), Pair(11, 83), Pair(35, 84),
        Pair(10, 67), Pair(45, 65), Pair(13, 83), Pair(41, 58), Pair(21, 69), Pair(-14, 31), Pair(32, 60), Pair(16, 73),
        Pair(-19, 93), Pair(24, 58), Pair(-1, 86), Pair(1, 79), Pair(2, 79), Pair(21, 34), Pair(20, 63), Pair(-19, 66),
        Pair(24, 51), Pair(21, 52), Pair(22, 58), Pair(23, 60), Pair(22, 63), Pair(23, 26), Pair(29, 56), Pair(17, 54)
      },
      { // Piece 4
        Pair(145, 7), Pair(21, 112), Pair(17, 26), Pair(47, 132), Pair(82, 99), Pair(52, 76), Pair(78, 57), Pair(80, 74),
        Pair(29, 86), Pair(-6, 111), Pair(32, 76), Pair(75, -7), Pair(46, 83), Pair(10, 21), Pair(47, 85), Pair(-45, 179),
        Pair(52, 56), Pair(11, 101), Pair(37, 105), Pair(40, 107), Pair(19, 93), Pair(52, -5), Pair(23, 121), Pair(38, 101),
        Pair(40, 106), Pair(6, 95), Pair(2, 75), Pair(25, 89), Pair(13, 67), Pair(0, 0), Pair(0, 103), Pair(37, 75),
        Pair(14, 137), Pair(43, 96), Pair(17, 122), Pair(34, 88), Pair(29, 62), Pair(-7, 84), Pair(32, 63), Pair(60, 33),
        Pair(23, 125), Pair(18, 111), Pair(29, 55), Pair(21, 83), Pair(28, 92), Pair(23, 43), Pair(12, 97), Pair(22, 45),
        Pair(38, 108), Pair(28, 87), Pair(21, 68), Pair(28, 68), Pair(28, 78), Pair(21, 45), Pair(23, 72), Pair(78, 42),
        Pair(27, 63), Pair(23, 73), Pair(9, 125), Pair(24, 87), Pair(26, 54), Pair(39, 32), Pair(76, 28), Pair(30, 19)
      },
      { // Piece 5
        Pair(14, 13), Pair(-346, 114), Pair(-90, -46), Pair(9, -14), Pair(-150, 32), Pair(64, 23), Pair(-20, 15), Pair(78, 106),
        Pair(41, 48), Pair(-244, 19), Pair(203, -38), Pair(34, -10), Pair(-65, 61), Pair(142, 79), Pair(-115, 89), Pair(218, -24),
        Pair(150, -39), Pair(17, 0), Pair(4, 18), Pair(-154, 47), Pair(8, 24), Pair(13, 43), Pair(143, 5), Pair(88, 16),
        Pair(-176, 34), Pair(58, -12), Pair(-84, 26), Pair(47, 21), Pair(48, 34), Pair(0, 0), Pair(32, 19), Pair(111, 0),
        Pair(-2, -38), Pair(-90, 37), Pair(-51, 10), Pair(-37, 27), Pair(0, 30), Pair(-14, 26), Pair(52, 7), Pair(71, 12),
        Pair(-74, 3), Pair(-36, 4), Pair(-11, -10), Pair(6, -2), Pair(-13, 14), Pair(-18, 12), Pair(2, 2), Pair(23, -10),
        Pair(-35, 3), Pair(-7, -17), Pair(-49, -4), Pair(-44, -4), Pair(-4, -22), Pair(-33, -17), Pair(2, -29), Pair(1, -18),
        Pair(2, -63), Pair(-18, -28), Pair(-28, -42), Pair(-29, -38), Pair(-8, -33), Pair(16, -53), Pair(8, -49), Pair(-7, -25)
      }
    }},
    {{ // Bucket 30
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-28, 43), Pair(-34, 31), Pair(-11, 12), Pair(12, 28), Pair(2, 13), Pair(22, 3), Pair(13, -17), Pair(-10, 44),
        Pair(-18, 26), Pair(-15, 17), Pair(-12, 23), Pair(0, 20), Pair(0, 15), Pair(12, 6), Pair(8, -67), Pair(-23, -10),
        Pair(-10, 21), Pair(-4, 15), Pair(0, 21), Pair(7, 14), Pair(-19, 4), Pair(-10, 5), Pair(16, 4), Pair(-18, -6),
        Pair(-4, 16), Pair(-3, 16), Pair(1, 13), Pair(-2, 16), Pair(5, 9), Pair(7, 5), Pair(16, -26), Pair(4, 2),
        Pair(-2, 16), Pair(4, 15), Pair(2, 11), Pair(-2, 18), Pair(3, 14), Pair(9, 10), Pair(16, -8), Pair(-3, 16),
        Pair(-4, 23), Pair(2, 14), Pair(2, 12), Pair(-4, 17), Pair(0, 11), Pair(1, 19), Pair(18, -6), Pair(-10, 20),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(85, -43), Pair(226, -13), Pair(14, 88), Pair(13, 64), Pair(162, 40), Pair(-87, 75), Pair(169, -5), Pair(9, -45),
        Pair(-39, 7), Pair(-47, 26), Pair(-18, 75), Pair(49, 52), Pair(56, 86), Pair(14, 44), Pair(57, 41), Pair(37, 24),
        Pair(53, 34), Pair(-24, 88), Pair(-15, 72), Pair(22, 64), Pair(23, 52), Pair(59, 66), Pair(14, 62), Pair(-27, -6),
        Pair(6, 62), Pair(25, 42), Pair(24, 50), Pair(26, 73), Pair(19, 69), Pair(-2, 81), Pair(0, 0), Pair(13, 43),
        Pair(-5, 43), Pair(37, 40), Pair(8, 52), Pair(-6, 69), Pair(48, 46), Pair(6, 65), Pair(50, 91), Pair(23, 68),
        Pair(8, 34), Pair(2, 45), Pair(12, 36), Pair(-5, 72), Pair(22, 57), Pair(-3, 36), Pair(19, 44), Pair(-4, 19),
        Pair(-5, 42), Pair(41, 46), Pair(19, 40), Pair(6, 40), Pair(6, 37), Pair(22, 18), Pair(5, 35), Pair(5, 9),
        Pair(51, 11), Pair(-7, 53), Pair(22, 34), Pair(8, 47), Pair(27, 35), Pair(28, 29), Pair(1, 21), Pair(-6, 86)
      },
      { // Piece 2
        Pair(-3, 16), Pair(30, -23), Pair(84, -3), Pair(138, 15), Pair(236, -6), Pair(93, 3), Pair(-8, 42), Pair(1, 44),
        Pair(39, 1), Pair(18, 28), Pair(46, -10), Pair(28, 19), Pair(88, 10), Pair(5, 27), Pair(50, -6), Pair(60, 52),
        Pair(2, 44), Pair(46, -6), Pair(37, 30), Pair(49, 2), Pair(44, 38), Pair(94, 29), Pair(-20, 29), Pair(-19, 21),
        Pair(-6, 6), Pair(16, 40), Pair(32, 14), Pair(31, 50), Pair(32, 23), Pair(-3, 68), Pair(0, 0), Pair(-5, 44),
        Pair(74, 17), Pair(41, 4), Pair(8, 51), Pair(32, 22), Pair(27, 50), Pair(19, 17), Pair(21, 68), Pair(-49, -8),
        Pair(13, 30), Pair(22, 33), Pair(17, 25), Pair(11, 54), Pair(6, 28), Pair(16, 54), Pair(10, -2), Pair(15, 37),
        Pair(-15, 60), Pair(14, 25), Pair(21, 42), Pair(3, 16), Pair(8, 47), Pair(-13, 8), Pair(21, 42), Pair(-8, -7),
        Pair(30, 49), Pair(42, 50), Pair(6, 14), Pair(19, 35), Pair(-5, 2), Pair(15, 18), Pair(-27, -5), Pair(9, 22)
      },
      { // Piece 3
        Pair(25, 74), Pair(41, 80), Pair(54, 72), Pair(69, 72), Pair(29, 89), Pair(-35, 116), Pair(45, 37), Pair(-16, 88),
        Pair(15, 68), Pair(-8, 99), Pair(36, 77), Pair(0, 75), Pair(55, 51), Pair(-59, 93), Pair(-22, 72), Pair(-40, 82),
        Pair(-6, 83), Pair(4, 71), Pair(-51, 110), Pair(55, 62), Pair(-10, 81), Pair(38, 88), Pair(27, 3), Pair(29, 83),
        Pair(7, 71), Pair(44, 75), Pair(3, 77), Pair(13, 62), Pair(-15, 84), Pair(-1, 66), Pair(0, 0), Pair(-6, 41),
        Pair(-12, 76), Pair(-15, 74), Pair(2, 69), Pair(6, 65), Pair(28, 67), Pair(16, 75), Pair(60, 23), Pair(-1, 67),
        Pair(-6, 73), Pair(-1, 84), Pair(9, 60), Pair(21, 67), Pair(5, 63), Pair(-14, 86), Pair(13, 16), Pair(-6, 82),
        Pair(6, 72), Pair(16, 57), Pair(-1, 73), Pair(6, 61), Pair(-15, 74), Pair(8, 50), Pair(56, -7), Pair(31, 60),
        Pair(5, 51), Pair(6, 59), Pair(8, 53), Pair(12, 63), Pair(10, 58), Pair(8, 59), Pair(26, 5), Pair(4, 56)
      },
      { // Piece 4
        Pair(-10, 111), Pair(-82, 145), Pair(-34, 146), Pair(28, 131), Pair(32, 92), Pair(79, 55), Pair(107, -14), Pair(18, 73),
        Pair(-17, 112), Pair(-14, 134), Pair(-5, 113), Pair(18, 132), Pair(15, 77), Pair(27, 125), Pair(31, -23), Pair(51, 11),
        Pair(-10, 81), Pair(5, 92), Pair(-14, 130), Pair(-8, 140), Pair(14, 103), Pair(40, 67), Pair(-1, 31), Pair(59, 49),
        Pair(69, 43), Pair(45, 51), Pair(48, 86), Pair(39, 70), Pair(29, 79), Pair(13, 60), Pair(0, 0), Pair(10, 39),
        Pair(-2, 81), Pair(9, 64), Pair(6, 84), Pair(30, 77), Pair(2, 118), Pair(1, 114), Pair(8, 40), Pair(10, 29),
        Pair(17, 48), Pair(2, 99), Pair(12, 83), Pair(39, 37), Pair(24, 39), Pair(23, 64), Pair(-16, 64), Pair(22, 68),
        Pair(-24, 144), Pair(32, 55), Pair(11, 60), Pair(-1, 74), Pair(17, 46), Pair(14, 80), Pair(11, 16), Pair(26, 86),
        Pair(12, 109), Pair(8, 94), Pair(10, 84), Pair(7, 81), Pair(12, 37), Pair(11, 78), Pair(41, -18), Pair(1, 117)
      },
      { // Piece 5
        Pair(113, -87), Pair(-167, 27), Pair(-19, -8), Pair(106, -19), Pair(-62, 28), Pair(-138, 100), Pair(23, 47), Pair(24, 61),
        Pair(-123, 5), Pair(-185, 39), Pair(-200, 24), Pair(-3, 4), Pair(167, -7), Pair(134, 73), Pair(146, 60), Pair(-36, 100),
        Pair(-119, -16), Pair(-102, -4), Pair(-58, 1), Pair(83, 10), Pair(12, 50), Pair(160, 25), Pair(21, 59), Pair(67, 14),
        Pair(-163, -2), Pair(-61, 15), Pair(8, 14), Pair(-50, 41), Pair(27, 33), Pair(52, 30), Pair(0, 0), Pair(39, 20),
        Pair(-164, 4), Pair(-115, 35), Pair(-89, 27), Pair(-89, 18), Pair(17, 21), Pair(7, 7), Pair(58, 10), Pair(18, 17),
        Pair(-106, 21), Pair(-40, 1), Pair(-40, 3), Pair(-43, 8), Pair(11, -2), Pair(7, 7), Pair(25, -9), Pair(63, -7),
        Pair(-29, -26), Pair(-24, -8), Pair(-67, -1), Pair(-40, 1), Pair(-21, -2), Pair(27, -20), Pair(15, -20), Pair(13, -16),
        Pair(-9, -49), Pair(-25, -20), Pair(-34, -17), Pair(-36, -10), Pair(-2, -25), Pair(20, -44), Pair(1, -22), Pair(-3, -41)
      }
    }},
    {{ // Bucket 31
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-13, 27), Pair(-6, 9), Pair(10, 15), Pair(21, 6), Pair(-1, 19), Pair(-55, -2), Pair(-17, 25), Pair(17, -30),
        Pair(-16, 17), Pair(-24, 34), Pair(13, 9), Pair(-6, 23), Pair(33, 1), Pair(-10, 11), Pair(-10, 4), Pair(31, -54),
        Pair(-5, 15), Pair(-8, 18), Pair(-2, 14), Pair(-1, 11), Pair(3, 12), Pair(-15, -3), Pair(-18, -7), Pair(2, -7),
        Pair(-6, 15), Pair(5, 17), Pair(0, 17), Pair(3, 12), Pair(2, 11), Pair(0, 5), Pair(-1, -1), Pair(21, -18),
        Pair(-5, 18), Pair(-2, 17), Pair(-2, 12), Pair(0, 13), Pair(1, 6), Pair(0, 3), Pair(-2, 13), Pair(9, 3),
        Pair(-2, 18), Pair(-3, 15), Pair(-2, 13), Pair(-2, 5), Pair(1, 3), Pair(-3, 9), Pair(-6, 18), Pair(2, 11),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(44, 12), Pair(248, 16), Pair(189, 13), Pair(14, 58), Pair(127, -27), Pair(80, 24), Pair(60, 0), Pair(-101, 39),
        Pair(46, 37), Pair(-51, 30), Pair(5, 32), Pair(30, 45), Pair(62, 16), Pair(13, 53), Pair(41, 44), Pair(-12, 15),
        Pair(-25, 68), Pair(19, 44), Pair(-4, 40), Pair(43, 31), Pair(25, 44), Pair(7, 37), Pair(1, 14), Pair(-39, 34),
        Pair(-12, 33), Pair(18, 33), Pair(-5, 42), Pair(17, 41), Pair(24, 54), Pair(-3, 57), Pair(33, 42), Pair(0, 0),
        Pair(8, 12), Pair(-2, 55), Pair(22, 30), Pair(8, 37), Pair(19, 39), Pair(18, 44), Pair(-2, 60), Pair(36, 52),
        Pair(25, 4), Pair(4, 24), Pair(13, 18), Pair(24, 34), Pair(24, 34), Pair(13, 27), Pair(22, 36), Pair(-3, 59),
        Pair(1, 35), Pair(27, 4), Pair(18, 25), Pair(15, 29), Pair(17, 21), Pair(2, 47), Pair(-1, 35), Pair(-8, 45),
        Pair(-96, 2), Pair(10, 19), Pair(15, 14), Pair(-4, 9), Pair(-6, 32), Pair(2, 27), Pair(7, 13), Pair(-35, -15)
      },
      { // Piece 2
        Pair(37, -27), Pair(84, 5), Pair(140, -48), Pair(67, 22), Pair(96, -37), Pair(-77, 46), Pair(36, -23), Pair(41, 18),
        Pair(54, 33), Pair(32, -12), Pair(33, 11), Pair(82, -55), Pair(53, -3), Pair(55, -13), Pair(26, 54), Pair(7, 18),
        Pair(27, 2), Pair(31, 30), Pair(44, -17), Pair(12, 15), Pair(99, -31), Pair(48, 37), Pair(-4, 28), Pair(13, 15),
        Pair(11, 36), Pair(25, -7), Pair(14, 42), Pair(48, 0), Pair(34, 40), Pair(32, 3), Pair(34, 45), Pair(0, 0),
        Pair(35, -16), Pair(6, 34), Pair(26, 1), Pair(25, 48), Pair(9, 3), Pair(22, 49), Pair(21, 4), Pair(31, 63),
        Pair(20, 23), Pair(-11, 22), Pair(23, 30), Pair(26, -2), Pair(21, 44), Pair(22, -5), Pair(2, 36), Pair(25, -10),
        Pair(28, 1), Pair(21, 29), Pair(28, -15), Pair(12, 45), Pair(20, 0), Pair(12, 44), Pair(15, 6), Pair(17, 14),
        Pair(32, 34), Pair(38, -13), Pair(20, 38), Pair(26, -7), Pair(9, 15), Pair(17, -18), Pair(-5, 33), Pair(27, -31)
      },
      { // Piece 3
        Pair(65, 49), Pair(25, 51), Pair(90, 25), Pair(3, 50), Pair(57, 42), Pair(69, 51), Pair(40, 49), Pair(65, -2),
        Pair(40, 55), Pair(16, 62), Pair(33, 42), Pair(29, 46), Pair(56, 35), Pair(-9, 72), Pair(-25, 69), Pair(-12, 34),
        Pair(9, 62), Pair(5, 64), Pair(-1, 57), Pair(-1, 47), Pair(25, 56), Pair(18, 54), Pair(7, 69), Pair(18, -3),
        Pair(-11, 56), Pair(-4, 61), Pair(24, 34), Pair(33, 35), Pair(8, 45), Pair(3, 53), Pair(0, 65), Pair(0, 0),
        Pair(28, 59), Pair(-1, 44), Pair(27, 43), Pair(1, 39), Pair(12, 42), Pair(22, 51), Pair(-2, 66), Pair(-5, 20),
        Pair(24, 36), Pair(-16, 71), Pair(-7, 41), Pair(-11, 45), Pair(27, 24), Pair(-4, 38), Pair(7, 43), Pair(-20, 7),
        Pair(15, 45), Pair(2, 41), Pair(19, 31), Pair(-13, 53), Pair(-8, 49), Pair(-7, 35), Pair(-35, 58), Pair(-23, 17),
        Pair(14, 30), Pair(20, 25), Pair(13, 27), Pair(17, 25), Pair(12, 32), Pair(9, 32), Pair(-9, 45), Pair(-6, -8)
      },
      { // Piece 4
        Pair(54, 44), Pair(23, 15), Pair(50, 8), Pair(35, 47), Pair(123, 25), Pair(-20, 140), Pair(14, 118), Pair(134, -29),
        Pair(7, 64), Pair(-10, 76), Pair(28, 30), Pair(15, 39), Pair(57, -14), Pair(11, 74), Pair(101, -24), Pair(-27, 51),
        Pair(-1, 96), Pair(1, 73), Pair(28, 36), Pair(60, 17), Pair(60, 40), Pair(63, 64), Pair(18, 108), Pair(19, -47),
        Pair(-11, 51), Pair(28, 0), Pair(57, 2), Pair(19, 65), Pair(14, 44), Pair(38, 31), Pair(22, 17), Pair(0, 0),
        Pair(42, 31), Pair(-4, 94), Pair(31, 56), Pair(19, 48), Pair(13, 66), Pair(46, 44), Pair(26, 33), Pair(6, -1),
        Pair(29, 33), Pair(41, 30), Pair(16, 52), Pair(34, 47), Pair(29, 40), Pair(20, 62), Pair(34, 27), Pair(7, 57),
        Pair(20, 117), Pair(32, 71), Pair(31, 49), Pair(36, 30), Pair(17, 47), Pair(3, 30), Pair(31, -2), Pair(14, 45),
        Pair(75, -31), Pair(23, 104), Pair(43, 55), Pair(22, 53), Pair(37, 22), Pair(49, 52), Pair(58, -28), Pair(-54, 110)
      },
      { // Piece 5
        Pair(-10, -21), Pair(84, 23), Pair(-38, -31), Pair(-35, 1), Pair(160, -55), Pair(-81, 22), Pair(-60, 12), Pair(20, 57),
        Pair(204, -48), Pair(44, -20), Pair(-40, 35), Pair(-32, -28), Pair(-82, 17), Pair(15, 61), Pair(-53, 81), Pair(-112, 32),
        Pair(-18, 18), Pair(-5, 17), Pair(100, -26), Pair(5, 15), Pair(85, 27), Pair(-10, 56), Pair(132, 18), Pair(-27, 9),
        Pair(-69, 9), Pair(-41, 13), Pair(-57, 23), Pair(-40, 14), Pair(2, 28), Pair(57, 16), Pair(30, 4), Pair(0, 0),
        Pair(-28, -29), Pair(-162, 29), Pair(-90, 27), Pair(-53, 24), Pair(-44, 21), Pair(19, 19), Pair(4, 0), Pair(57, -18),
        Pair(-58, 10), Pair(-45, 11), Pair(-103, 19), Pair(-62, 19), Pair(-8, 5), Pair(6, -1), Pair(24, -1), Pair(24, -5),
        Pair(-55, -16), Pair(-57, 13), Pair(-46, 7), Pair(-35, 6), Pair(3, -5), Pair(-24, 1), Pair(12, -6), Pair(4, -7),
        Pair(-27, -35), Pair(-40, -12), Pair(-31, -8), Pair(-21, -24), Pair(-19, -3), Pair(-18, -8), Pair(10, -17), Pair(-5, -15)
      }
    }},
    {{ // Bucket 32
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-49, 8), Pair(-13, 34), Pair(-4, 24), Pair(-9, 34), Pair(7, -1), Pair(-35, 36), Pair(0, 5), Pair(-9, 24),
        Pair(-2, 1), Pair(-6, 26), Pair(-14, 26), Pair(-9, 19), Pair(4, 14), Pair(-6, 15), Pair(-3, 12), Pair(-2, 16),
        Pair(-3, -9), Pair(-2, 11), Pair(-3, 11), Pair(-6, 14), Pair(-1, 13), Pair(1, 17), Pair(-4, 18), Pair(-6, 17),
        Pair(-1, 12), Pair(-8, -2), Pair(-5, 11), Pair(-3, 15), Pair(0, 16), Pair(-1, 16), Pair(-6, 22), Pair(-8, 20),
        Pair(-3, 12), Pair(-2, 4), Pair(-2, 11), Pair(-4, 17), Pair(-3, 15), Pair(-4, 16), Pair(-3, 21), Pair(-2, 24),
        Pair(2, 12), Pair(-5, 14), Pair(-5, 14), Pair(-3, 8), Pair(-6, 15), Pair(-8, 22), Pair(-7, 21), Pair(-5, 21),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(34, 44), Pair(-74, 89), Pair(-6, 99), Pair(-118, 85), Pair(-105, 97), Pair(-50, 64), Pair(-19, 67), Pair(-1, 116),
        Pair(17, 54), Pair(-4, 73), Pair(1, 73), Pair(-28, 83), Pair(-36, 78), Pair(-36, 94), Pair(-19, 93), Pair(29, 60),
        Pair(-14, 66), Pair(7, 77), Pair(-9, 82), Pair(-16, 89), Pair(-31, 79), Pair(-43, 86), Pair(-13, 77), Pair(-17, 103),
        Pair(-17, 56), Pair(1, 70), Pair(-1, 76), Pair(-12, 87), Pair(-14, 90), Pair(-10, 84), Pair(-17, 83), Pair(-27, 83),
        Pair(0, 0), Pair(-3, 77), Pair(-11, 93), Pair(-8, 78), Pair(-17, 91), Pair(-11, 90), Pair(-18, 94), Pair(-11, 63),
        Pair(-6, 80), Pair(1, 77), Pair(-8, 59), Pair(0, 86), Pair(-6, 84), Pair(-7, 76), Pair(-7, 75), Pair(-15, 79),
        Pair(-3, 71), Pair(11, 60), Pair(-7, 66), Pair(-10, 78), Pair(-9, 77), Pair(-16, 80), Pair(-16, 80), Pair(-10, 76),
        Pair(76, 45), Pair(-8, 44), Pair(-3, 52), Pair(-19, 70), Pair(-7, 81), Pair(-9, 77), Pair(0, 62), Pair(0, 57)
      },
      { // Piece 2
        Pair(-14, 76), Pair(46, 55), Pair(60, 29), Pair(-19, 68), Pair(48, 25), Pair(-15, 54), Pair(57, 33), Pair(77, 27),
        Pair(10, 70), Pair(28, 61), Pair(-13, 66), Pair(38, 41), Pair(28, 45), Pair(38, 27), Pair(-22, 70), Pair(-15, 43),
        Pair(14, 54), Pair(18, 74), Pair(39, 50), Pair(-2, 62), Pair(-10, 39), Pair(-2, 62), Pair(29, 35), Pair(-23, 72),
        Pair(-4, 64), Pair(7, 80), Pair(5, 66), Pair(-12, 63), Pair(-9, 76), Pair(-3, 40), Pair(-9, 63), Pair(4, 40),
        Pair(0, 0), Pair(0, 73), Pair(12, 55), Pair(-2, 70), Pair(-1, 69), Pair(-6, 69), Pair(-1, 64), Pair(-18, 70),
        Pair(3, 82), Pair(18, 51), Pair(-3, 72), Pair(-2, 65), Pair(-8, 87), Pair(-2, 68), Pair(3, 71), Pair(-5, 63),
        Pair(10, 55), Pair(-9, 64), Pair(-2, 58), Pair(-9, 84), Pair(0, 73), Pair(-8, 81), Pair(-4, 74), Pair(1, 64),
        Pair(-14, 45), Pair(-9, 41), Pair(-13, 67), Pair(1, 64), Pair(-9, 82), Pair(-5, 65), Pair(6, 74), Pair(0, 82)
      },
      { // Piece 3
        Pair(-32, 95), Pair(-10, 111), Pair(-33, 127), Pair(-48, 120), Pair(-13, 113), Pair(-27, 107), Pair(-50, 136), Pair(-19, 125),
        Pair(-59, 106), Pair(-24, 118), Pair(-36, 126), Pair(-28, 123), Pair(-37, 129), Pair(-21, 118), Pair(-58, 148), Pair(-31, 126),
        Pair(-67, 114), Pair(-18, 126), Pair(-11, 119), Pair(-41, 127), Pair(-36, 128), Pair(-39, 125), Pair(-48, 138), Pair(-18, 123),
        Pair(-52, 91), Pair(-11, 132), Pair(1, 131), Pair(-35, 126), Pair(-23, 122), Pair(-41, 138), Pair(-42, 140), Pair(-27, 129),
        Pair(0, 0), Pair(-9, 135), Pair(-14, 129), Pair(-18, 124), Pair(-23, 133), Pair(-25, 128), Pair(-34, 130), Pair(-22, 119),
        Pair(-38, 87), Pair(-34, 147), Pair(-7, 119), Pair(-16, 123), Pair(-15, 118), Pair(-27, 112), Pair(-12, 122), Pair(-23, 131),
        Pair(-59, 92), Pair(-24, 128), Pair(-21, 128), Pair(-28, 113), Pair(-21, 115), Pair(-15, 107), Pair(-29, 121), Pair(-20, 123),
        Pair(-39, 87), Pair(-28, 119), Pair(-26, 124), Pair(-22, 118), Pair(-21, 116), Pair(-22, 110), Pair(-35, 116), Pair(-11, 96)
      },
      { // Piece 4
        Pair(1, 185), Pair(51, 192), Pair(30, 164), Pair(-12, 212), Pair(-43, 227), Pair(30, 216), Pair(35, 236), Pair(-16, 235),
        Pair(-14, 204), Pair(23, 192), Pair(5, 203), Pair(16, 188), Pair(22, 158), Pair(39, 180), Pair(51, 197), Pair(2, 224),
        Pair(-9, 189), Pair(9, 205), Pair(16, 196), Pair(0, 201), Pair(-15, 241), Pair(-2, 217), Pair(4, 213), Pair(4, 193),
        Pair(3, 161), Pair(14, 231), Pair(-6, 227), Pair(6, 202), Pair(4, 200), Pair(17, 183), Pair(12, 206), Pair(16, 189),
        Pair(0, 0), Pair(20, 209), Pair(15, 211), Pair(16, 198), Pair(15, 207), Pair(12, 217), Pair(11, 198), Pair(14, 178),
        Pair(9, 169), Pair(20, 192), Pair(26, 195), Pair(18, 215), Pair(21, 228), Pair(18, 210), Pair(17, 195), Pair(19, 184),
        Pair(13, 159), Pair(19, 183), Pair(19, 196), Pair(17, 203), Pair(20, 208), Pair(22, 207), Pair(36, 180), Pair(19, 177),
        Pair(2, 126), Pair(12, 201), Pair(22, 202), Pair(19, 202), Pair(24, 208), Pair(34, 196), Pair(21, 203), Pair(61, 153)
      },
      { // Piece 5
        Pair(27, 19), Pair(-139, 120), Pair(-24, -22), Pair(-33, 5), Pair(-92, -17), Pair(19, -24), Pair(-141, 13), Pair(-165, -31),
        Pair(14, 55), Pair(41, 39), Pair(5, 42), Pair(-40, 42), Pair(27, 21), Pair(157, 6), Pair(50, 20), Pair(-12, -29),
        Pair(-3, 58), Pair(-49, 79), Pair(101, 30), Pair(-175, 103), Pair(115, 23), Pair(-93, 48), Pair(79, 1), Pair(-46, -6),
        Pair(25, 31), Pair(-28, 39), Pair(47, 55), Pair(28, 37), Pair(17, 38), Pair(-11, 19), Pair(-15, 12), Pair(-90, 11),
        Pair(0, 0), Pair(-33, 53), Pair(-13, 48), Pair(-35, 51), Pair(-50, 34), Pair(-28, 19), Pair(-11, 13), Pair(-15, -10),
        Pair(110, 4), Pair(33, 0), Pair(2, 29), Pair(-16, 20), Pair(9, 16), Pair(-28, 18), Pair(-22, 7), Pair(-42, 0),
        Pair(76, -7), Pair(87, -7), Pair(19, 5), Pair(-6, 8), Pair(-13, 13), Pair(-14, 5), Pair(-14, 1), Pair(-10, -18),
        Pair(77, -25), Pair(116, -27), Pair(60, -12), Pair(0, 0), Pair(-2, -21), Pair(-24, 4), Pair(-8, -10), Pair(-8, -27)
      }
    }},
    {{ // Bucket 33
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-1, 31), Pair(5, 6), Pair(16, 38), Pair(3, 14), Pair(22, 15), Pair(60, -6), Pair(-8, 14), Pair(-42, 22),
        Pair(-10, 32), Pair(-13, 5), Pair(9, 20), Pair(2, 15), Pair(-2, 17), Pair(6, 10), Pair(4, 19), Pair(-1, 17),
        Pair(-6, 7), Pair(-2, -15), Pair(8, 13), Pair(3, 9), Pair(5, 12), Pair(3, 16), Pair(-2, 15), Pair(6, 14),
        Pair(-6, 0), Pair(-7, 14), Pair(-7, 6), Pair(-3, 6), Pair(-1, 20), Pair(2, 15), Pair(1, 19), Pair(0, 22),
        Pair(9, 9), Pair(-7, 3), Pair(5, 19), Pair(-2, 18), Pair(-2, 18), Pair(6, 16), Pair(5, 18), Pair(-2, 20),
        Pair(-6, 14), Pair(0, 2), Pair(-1, 24), Pair(1, 19), Pair(-2, 19), Pair(-1, 25), Pair(3, 21), Pair(1, 22),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-19, 104), Pair(40, 26), Pair(46, 68), Pair(3, 82), Pair(-40, 64), Pair(-64, 67), Pair(-54, 84), Pair(1, 100),
        Pair(15, 96), Pair(2, 69), Pair(10, 89), Pair(9, 95), Pair(-43, 103), Pair(-6, 75), Pair(21, 93), Pair(-40, 109),
        Pair(4, 75), Pair(1, 100), Pair(12, 79), Pair(21, 90), Pair(24, 80), Pair(0, 86), Pair(-17, 96), Pair(37, 86),
        Pair(36, 61), Pair(8, 61), Pair(35, 87), Pair(9, 75), Pair(6, 98), Pair(4, 102), Pair(2, 87), Pair(17, 84),
        Pair(9, 99), Pair(0, 0), Pair(17, 107), Pair(20, 91), Pair(11, 83), Pair(16, 95), Pair(-2, 93), Pair(5, 89),
        Pair(21, 98), Pair(32, 97), Pair(17, 90), Pair(22, 88), Pair(29, 80), Pair(18, 80), Pair(16, 81), Pair(6, 71),
        Pair(-17, 57), Pair(36, 104), Pair(15, 84), Pair(17, 73), Pair(18, 90), Pair(21, 96), Pair(22, 95), Pair(19, 76),
        Pair(60, 57), Pair(11, 69), Pair(38, 59), Pair(0, 98), Pair(15, 79), Pair(8, 93), Pair(8, 90), Pair(25, 53)
      },
      { // Piece 2
        Pair(81, 43), Pair(41, 44), Pair(-8, 60), Pair(90, 17), Pair(25, 70), Pair(172, -14), Pair(-69, 68), Pair(-7, 29),
        Pair(31, 50), Pair(21, 71), Pair(2, 41), Pair(24, 52), Pair(82, 30), Pair(13, 59), Pair(12, 39), Pair(4, 39),
        Pair(17, 70), Pair(14, 50), Pair(40, 69), Pair(18, 26), Pair(33, 51), Pair(18, 42), Pair(-7, 74), Pair(-16, 70),
        Pair(-28, -76), Pair(-7, 76), Pair(67, 22), Pair(10, 77), Pair(30, 51), Pair(30, 62), Pair(19, 35), Pair(11, 83),
        Pair(29, 78), Pair(0, 0), Pair(20, 83), Pair(29, 50), Pair(25, 80), Pair(27, 53), Pair(27, 82), Pair(16, 75),
        Pair(-14, 6), Pair(31, 78), Pair(3, 59), Pair(13, 89), Pair(14, 62), Pair(26, 89), Pair(17, 65), Pair(13, 89),
        Pair(-1, 56), Pair(7, 61), Pair(16, 77), Pair(10, 55), Pair(19, 87), Pair(17, 75), Pair(17, 90), Pair(7, 60),
        Pair(-1, 44), Pair(23, 58), Pair(5, 57), Pair(31, 79), Pair(8, 55), Pair(17, 89), Pair(23, 30), Pair(25, 55)
      },
      { // Piece 3
        Pair(-11, 120), Pair(2, 96), Pair(20, 116), Pair(-2, 131), Pair(12, 125), Pair(16, 110), Pair(-9, 138), Pair(38, 98),
        Pair(-20, 129), Pair(-33, 99), Pair(-3, 121), Pair(-1, 128), Pair(19, 110), Pair(-9, 125), Pair(-36, 139), Pair(-59, 145),
        Pair(5, 125), Pair(-4, 104), Pair(-1, 129), Pair(9, 131), Pair(10, 122), Pair(-31, 136), Pair(2, 128), Pair(-18, 144),
        Pair(16, 128), Pair(-45, 90), Pair(11, 133), Pair(8, 134), Pair(20, 121), Pair(-1, 128), Pair(-3, 135), Pair(16, 115),
        Pair(12, 91), Pair(0, 0), Pair(4, 131), Pair(16, 128), Pair(10, 126), Pair(2, 122), Pair(-42, 139), Pair(15, 113),
        Pair(6, 121), Pair(7, 77), Pair(22, 139), Pair(21, 124), Pair(15, 119), Pair(-2, 117), Pair(-10, 115), Pair(-7, 117),
        Pair(-6, 130), Pair(-19, 105), Pair(16, 122), Pair(3, 114), Pair(9, 120), Pair(11, 108), Pair(-5, 128), Pair(17, 104),
        Pair(-2, 118), Pair(-1, 75), Pair(5, 125), Pair(10, 114), Pair(6, 120), Pair(2, 119), Pair(7, 112), Pair(2, 107)
      },
      { // Piece 4
        Pair(-1, 177), Pair(-26, 203), Pair(29, 148), Pair(-28, 203), Pair(-4, 212), Pair(-10, 244), Pair(8, 179), Pair(-14, 192),
        Pair(-10, 187), Pair(-7, 159), Pair(28, 170), Pair(36, 172), Pair(-2, 178), Pair(18, 173), Pair(34, 150), Pair(-46, 202),
        Pair(6, 181), Pair(23, 131), Pair(36, 151), Pair(31, 141), Pair(-7, 191), Pair(34, 159), Pair(34, 157), Pair(13, 183),
        Pair(-15, 184), Pair(25, 141), Pair(-19, 220), Pair(-1, 205), Pair(13, 180), Pair(4, 187), Pair(4, 195), Pair(-7, 180),
        Pair(18, 175), Pair(0, 0), Pair(37, 170), Pair(40, 173), Pair(12, 181), Pair(10, 217), Pair(13, 187), Pair(8, 182),
        Pair(15, 147), Pair(24, 147), Pair(24, 185), Pair(22, 205), Pair(20, 212), Pair(21, 201), Pair(18, 186), Pair(17, 191),
        Pair(22, 160), Pair(20, 160), Pair(26, 181), Pair(23, 192), Pair(33, 182), Pair(21, 197), Pair(42, 151), Pair(30, 143),
        Pair(23, 199), Pair(17, 133), Pair(16, 188), Pair(26, 187), Pair(21, 183), Pair(25, 160), Pair(26, 182), Pair(2, 254)
      },
      { // Piece 5
        Pair(-58, 112), Pair(-128, 108), Pair(-140, 146), Pair(264, 8), Pair(-8, 52), Pair(-9, 30), Pair(-53, -30), Pair(167, -26),
        Pair(-70, 98), Pair(16, 94), Pair(-22, 81), Pair(112, 42), Pair(125, 15), Pair(187, 6), Pair(34, 17), Pair(67, -32),
        Pair(-37, 95), Pair(111, 62), Pair(145, 57), Pair(18, 56), Pair(39, 68), Pair(11, 39), Pair(-22, 30), Pair(20, -4),
        Pair(66, 53), Pair(36, 42), Pair(27, 30), Pair(-35, 68), Pair(39, 45), Pair(36, 27), Pair(16, 11), Pair(-62, 17),
        Pair(-13, 70), Pair(0, 0), Pair(27, 56), Pair(-33, 51), Pair(-29, 42), Pair(-37, 26), Pair(-35, 17), Pair(-86, 10),
        Pair(93, 29), Pair(50, 25), Pair(44, 28), Pair(28, 32), Pair(2, 21), Pair(-32, 19), Pair(-30, 10), Pair(-53, 10),
        Pair(112, 3), Pair(16, 22), Pair(24, 34), Pair(-3, 24), Pair(9, 11), Pair(-11, 10), Pair(-13, 1), Pair(-17, -7),
        Pair(93, -39), Pair(38, -30), Pair(33, 5), Pair(-14, 16), Pair(-3, 2), Pair(-5, 1), Pair(-6, -7), Pair(-11, -31)
      }
    }},
    {{ // Bucket 34
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(16, 22), Pair(-1, 20), Pair(-24, -16), Pair(-21, 26), Pair(16, 19), Pair(15, 18), Pair(-17, 30), Pair(-14, 30),
        Pair(-9, 17), Pair(-15, 24), Pair(-4, -9), Pair(-17, 32), Pair(12, 13), Pair(-5, 16), Pair(-5, 10), Pair(-1, 10),
        Pair(-4, 12), Pair(-3, 9), Pair(-13, -30), Pair(2, 15), Pair(1, 14), Pair(13, 10), Pair(4, 13), Pair(-2, 16),
        Pair(-4, 11), Pair(-7, 5), Pair(12, -9), Pair(-6, 19), Pair(-4, 8), Pair(3, 13), Pair(0, 16), Pair(0, 17),
        Pair(-1, 6), Pair(7, 14), Pair(-13, -21), Pair(4, 18), Pair(-1, 14), Pair(5, 14), Pair(0, 15), Pair(-2, 13),
        Pair(-1, 13), Pair(-4, 7), Pair(1, -10), Pair(6, 17), Pair(1, 19), Pair(-2, 18), Pair(-3, 16), Pair(2, 21),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-26, 81), Pair(12, 60), Pair(39, 69), Pair(-19, 83), Pair(-68, 110), Pair(-111, 83), Pair(-70, 65), Pair(-21, 33),
        Pair(-28, 79), Pair(19, 67), Pair(-22, 80), Pair(-16, 76), Pair(-25, 79), Pair(-57, 100), Pair(27, 67), Pair(28, 54),
        Pair(-72, 97), Pair(-17, 68), Pair(-29, 90), Pair(-9, 60), Pair(-24, 93), Pair(-30, 94), Pair(-27, 75), Pair(-49, 87),
        Pair(-39, 70), Pair(-16, 75), Pair(-24, 62), Pair(9, 99), Pair(-23, 73), Pair(-15, 88), Pair(-18, 89), Pair(4, 64),
        Pair(-9, 66), Pair(-24, 92), Pair(0, 0), Pair(-10, 81), Pair(-12, 84), Pair(-8, 86), Pair(-14, 81), Pair(-12, 78),
        Pair(-13, 28), Pair(-2, 74), Pair(1, 99), Pair(-2, 105), Pair(1, 65), Pair(-7, 77), Pair(-5, 69), Pair(3, 62),
        Pair(-12, 73), Pair(-16, 48), Pair(1, 68), Pair(-10, 69), Pair(-5, 70), Pair(3, 76), Pair(-3, 61), Pair(-9, 80),
        Pair(4, 105), Pair(-8, 69), Pair(1, 88), Pair(-15, 71), Pair(-8, 89), Pair(-8, 70), Pair(4, 68), Pair(-17, 33)
      },
      { // Piece 2
        Pair(36, 19), Pair(15, 51), Pair(26, 10), Pair(34, 55), Pair(76, -13), Pair(27, 27), Pair(-16, 6), Pair(55, 5),
        Pair(-19, 54), Pair(6, 36), Pair(-15, 52), Pair(43, 17), Pair(15, 51), Pair(16, -9), Pair(-11, 48), Pair(-12, 35),
        Pair(-41, 17), Pair(3, 58), Pair(13, 26), Pair(22, 55), Pair(5, 14), Pair(7, 74), Pair(-11, 28), Pair(-9, 62),
        Pair(3, 59), Pair(-38, 31), Pair(-2, 45), Pair(28, -7), Pair(4, 51), Pair(-5, 30), Pair(1, 74), Pair(-9, 37),
        Pair(-10, 24), Pair(-2, 63), Pair(0, 0), Pair(9, 69), Pair(-7, 43), Pair(4, 65), Pair(-15, 48), Pair(-4, 53),
        Pair(-10, 66), Pair(-35, -1), Pair(13, 78), Pair(-12, 25), Pair(-4, 69), Pair(-4, 42), Pair(-6, 65), Pair(-20, 34),
        Pair(-56, 33), Pair(-9, 71), Pair(-16, 30), Pair(-3, 70), Pair(-9, 31), Pair(12, 57), Pair(-13, 64), Pair(-2, 74),
        Pair(6, 62), Pair(-2, 24), Pair(-4, 56), Pair(-8, 25), Pair(-3, 49), Pair(-13, 34), Pair(30, 42), Pair(12, 32)
      },
      { // Piece 3
        Pair(-14, 94), Pair(-32, 105), Pair(-1, 64), Pair(-36, 108), Pair(-58, 111), Pair(-19, 95), Pair(-34, 95), Pair(-64, 103),
        Pair(-32, 106), Pair(-24, 100), Pair(-26, 80), Pair(-28, 109), Pair(-13, 107), Pair(-53, 115), Pair(-51, 113), Pair(-6, 97),
        Pair(-38, 115), Pair(-31, 110), Pair(-59, 99), Pair(-42, 115), Pair(-35, 112), Pair(-37, 117), Pair(-22, 111), Pair(-37, 117),
        Pair(-9, 101), Pair(-12, 103), Pair(-51, 79), Pair(-15, 110), Pair(-6, 99), Pair(-15, 108), Pair(-14, 105), Pair(-31, 107),
        Pair(-7, 72), Pair(-30, 103), Pair(0, 0), Pair(-20, 111), Pair(-8, 100), Pair(-11, 95), Pair(14, 84), Pair(-20, 87),
        Pair(-13, 102), Pair(-2, 88), Pair(-17, 61), Pair(-8, 106), Pair(-14, 106), Pair(-14, 101), Pair(-13, 102), Pair(-14, 100),
        Pair(-5, 85), Pair(-26, 111), Pair(-25, 61), Pair(-25, 109), Pair(-7, 87), Pair(-20, 96), Pair(-1, 93), Pair(-16, 104),
        Pair(-16, 99), Pair(-18, 107), Pair(-19, 57), Pair(-14, 103), Pair(-15, 103), Pair(-14, 91), Pair(-9, 95), Pair(-17, 97)
      },
      { // Piece 4
        Pair(-3, 120), Pair(14, 156), Pair(-26, 149), Pair(9, 159), Pair(-6, 148), Pair(-30, 170), Pair(39, 124), Pair(-10, 192),
        Pair(-15, 165), Pair(5, 127), Pair(2, 137), Pair(-10, 148), Pair(42, 106), Pair(38, 90), Pair(32, 134), Pair(24, 122),
        Pair(-21, 114), Pair(-12, 166), Pair(-3, 90), Pair(-11, 135), Pair(-21, 127), Pair(2, 144), Pair(10, 139), Pair(-13, 163),
        Pair(-15, 163), Pair(-19, 143), Pair(-10, 97), Pair(6, 141), Pair(-6, 156), Pair(-8, 155), Pair(0, 149), Pair(-6, 145),
        Pair(1, 112), Pair(2, 111), Pair(0, 0), Pair(-4, 145), Pair(3, 154), Pair(0, 154), Pair(5, 142), Pair(-7, 143),
        Pair(-9, 145), Pair(2, 115), Pair(8, 140), Pair(10, 142), Pair(8, 155), Pair(7, 152), Pair(6, 138), Pair(-6, 159),
        Pair(10, 123), Pair(7, 158), Pair(5, 118), Pair(9, 143), Pair(6, 149), Pair(15, 147), Pair(7, 149), Pair(-7, 177),
        Pair(10, 138), Pair(15, 115), Pair(15, 113), Pair(5, 151), Pair(10, 143), Pair(23, 135), Pair(32, 131), Pair(35, 133)
      },
      { // Piece 5
        Pair(41, 91), Pair(38, 119), Pair(78, 53), Pair(158, 50), Pair(202, -17), Pair(-107, 85), Pair(64, 13), Pair(2, 18),
        Pair(122, 36), Pair(153, 84), Pair(138, 49), Pair(22, 31), Pair(227, 15), Pair(-29, 59), Pair(11, 6), Pair(-131, 36),
        Pair(26, 34), Pair(92, 67), Pair(153, 26), Pair(129, 56), Pair(142, 38), Pair(40, 48), Pair(18, 26), Pair(-55, 14),
        Pair(182, 26), Pair(46, 6), Pair(171, 15), Pair(108, 16), Pair(32, 38), Pair(3, 22), Pair(-25, 5), Pair(-66, 14),
        Pair(37, 46), Pair(63, 40), Pair(0, 0), Pair(-1, 52), Pair(7, 26), Pair(-16, 8), Pair(6, 5), Pair(-60, -1),
        Pair(67, 22), Pair(-6, 30), Pair(17, 28), Pair(-9, 26), Pair(28, 8), Pair(-13, 7), Pair(-27, 1), Pair(-31, -2),
        Pair(41, 5), Pair(-8, 26), Pair(26, -2), Pair(8, 21), Pair(-12, 2), Pair(-4, 1), Pair(-5, -8), Pair(-8, -12),
        Pair(41, -45), Pair(16, -30), Pair(34, -28), Pair(9, -12), Pair(10, -12), Pair(-8, -5), Pair(-6, -19), Pair(-11, -24)
      }
    }},
    {{ // Bucket 35
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-15, 30), Pair(-25, 15), Pair(-17, 28), Pair(-32, -11), Pair(-16, 33), Pair(-16, 27), Pair(22, 6), Pair(8, 19),
        Pair(0, 11), Pair(-3, 18), Pair(-13, 26), Pair(0, 1), Pair(-8, 24), Pair(13, 14), Pair(-14, 25), Pair(-7, 16),
        Pair(2, 12), Pair(3, 9), Pair(11, 21), Pair(-3, -7), Pair(14, 14), Pair(6, 11), Pair(2, 15), Pair(0, 11),
        Pair(1, 18), Pair(0, 10), Pair(-6, 18), Pair(5, -22), Pair(-4, 24), Pair(-2, 5), Pair(2, 19), Pair(3, 13),
        Pair(1, 18), Pair(1, 9), Pair(13, 23), Pair(7, -12), Pair(9, 23), Pair(3, 11), Pair(2, 16), Pair(2, 13),
        Pair(1, 13), Pair(3, 13), Pair(3, 24), Pair(15, -13), Pair(4, 20), Pair(1, 19), Pair(0, 20), Pair(3, 17),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-10, 30), Pair(-88, 96), Pair(33, 60), Pair(-91, 93), Pair(-12, 108), Pair(-33, 77), Pair(-60, 51), Pair(1, 48),
        Pair(7, 77), Pair(4, 93), Pair(-38, 91), Pair(-34, 106), Pair(-5, 64), Pair(25, 68), Pair(16, 84), Pair(-10, 72),
        Pair(-10, 74), Pair(-12, 93), Pair(7, 58), Pair(-15, 75), Pair(4, 57), Pair(-61, 103), Pair(-8, 80), Pair(-34, 93),
        Pair(-9, 80), Pair(-9, 72), Pair(13, 79), Pair(-35, 63), Pair(3, 82), Pair(-18, 72), Pair(-12, 81), Pair(-27, 84),
        Pair(11, 76), Pair(2, 77), Pair(2, 73), Pair(0, 0), Pair(-15, 88), Pair(-3, 92), Pair(-21, 77), Pair(1, 58),
        Pair(1, 73), Pair(-5, 58), Pair(0, 92), Pair(26, 97), Pair(11, 91), Pair(0, 54), Pair(-5, 68), Pair(2, 60),
        Pair(18, 46), Pair(27, 44), Pair(-5, 73), Pair(4, 70), Pair(3, 60), Pair(6, 76), Pair(16, 62), Pair(0, 65),
        Pair(25, 71), Pair(4, 84), Pair(-3, 79), Pair(0, 80), Pair(4, 79), Pair(1, 69), Pair(13, 74), Pair(34, 95)
      },
      { // Piece 2
        Pair(52, 20), Pair(37, -14), Pair(32, 70), Pair(-6, 20), Pair(58, 42), Pair(56, -2), Pair(8, 27), Pair(17, -26),
        Pair(-51, -7), Pair(11, 65), Pair(13, 12), Pair(13, 59), Pair(-4, 14), Pair(-21, 59), Pair(-14, -8), Pair(11, 52),
        Pair(14, 59), Pair(-14, 9), Pair(16, 61), Pair(-26, 31), Pair(28, 40), Pair(-24, -6), Pair(-1, 44), Pair(-18, 24),
        Pair(-18, 31), Pair(12, 53), Pair(14, -3), Pair(-24, 42), Pair(-18, 22), Pair(-1, 68), Pair(-11, 29), Pair(0, 67),
        Pair(29, 53), Pair(-11, 33), Pair(5, 57), Pair(0, 0), Pair(-8, 67), Pair(-11, 42), Pair(8, 58), Pair(-6, 27),
        Pair(-13, 31), Pair(6, 64), Pair(-40, -3), Pair(19, 84), Pair(-15, 13), Pair(6, 63), Pair(-6, 38), Pair(4, 69),
        Pair(1, 82), Pair(-44, -11), Pair(8, 67), Pair(-2, 29), Pair(8, 64), Pair(-19, 4), Pair(-4, 74), Pair(-6, 49),
        Pair(-61, -17), Pair(14, 70), Pair(-12, 30), Pair(14, 51), Pair(2, 21), Pair(9, 63), Pair(-29, 48), Pair(-1, 55)
      },
      { // Piece 3
        Pair(-20, 100), Pair(0, 97), Pair(-58, 108), Pair(-17, 77), Pair(-61, 115), Pair(-32, 98), Pair(26, 89), Pair(-17, 88),
        Pair(-29, 117), Pair(-40, 117), Pair(-36, 111), Pair(-41, 97), Pair(-36, 101), Pair(-18, 106), Pair(-61, 115), Pair(-17, 107),
        Pair(-24, 110), Pair(-16, 99), Pair(-30, 108), Pair(-39, 98), Pair(-37, 120), Pair(-40, 102), Pair(-21, 90), Pair(7, 92),
        Pair(1, 96), Pair(-10, 105), Pair(-7, 107), Pair(-27, 82), Pair(-11, 109), Pair(-13, 96), Pair(-20, 104), Pair(0, 99),
        Pair(-19, 84), Pair(-14, 75), Pair(-13, 83), Pair(0, 0), Pair(-15, 88), Pair(-3, 74), Pair(-14, 89), Pair(-23, 85),
        Pair(-6, 87), Pair(-10, 100), Pair(-3, 94), Pair(-1, 61), Pair(-7, 90), Pair(-14, 86), Pair(-33, 100), Pair(3, 64),
        Pair(-22, 95), Pair(-6, 88), Pair(-5, 91), Pair(-20, 77), Pair(-9, 92), Pair(-12, 91), Pair(-14, 80), Pair(-1, 101),
        Pair(-7, 93), Pair(-9, 95), Pair(-12, 94), Pair(-3, 55), Pair(-11, 92), Pair(-12, 88), Pair(-8, 94), Pair(-1, 85)
      },
      { // Piece 4
        Pair(14, 140), Pair(-13, 167), Pair(11, 132), Pair(102, 75), Pair(18, 122), Pair(10, 163), Pair(-24, 217), Pair(17, 158),
        Pair(-16, 145), Pair(10, 163), Pair(1, 144), Pair(16, 124), Pair(-3, 131), Pair(-6, 191), Pair(15, 116), Pair(-7, 162),
        Pair(-4, 169), Pair(9, 99), Pair(8, 145), Pair(-6, 123), Pair(-15, 159), Pair(11, 126), Pair(-21, 196), Pair(-4, 160),
        Pair(2, 158), Pair(6, 155), Pair(-8, 159), Pair(7, 66), Pair(4, 139), Pair(-9, 158), Pair(-13, 160), Pair(-4, 141),
        Pair(15, 100), Pair(22, 95), Pair(3, 113), Pair(0, 0), Pair(5, 127), Pair(1, 144), Pair(0, 153), Pair(-1, 141),
        Pair(17, 128), Pair(19, 120), Pair(4, 135), Pair(23, 115), Pair(17, 139), Pair(13, 152), Pair(0, 155), Pair(14, 127),
        Pair(32, 99), Pair(12, 111), Pair(15, 146), Pair(17, 124), Pair(13, 145), Pair(17, 132), Pair(17, 127), Pair(-7, 242),
        Pair(7, 118), Pair(22, 148), Pair(14, 148), Pair(15, 124), Pair(12, 142), Pair(13, 160), Pair(12, 120), Pair(20, 139)
      },
      { // Piece 5
        Pair(-75, -16), Pair(20, 105), Pair(-20, 106), Pair(40, 78), Pair(29, 43), Pair(76, 44), Pair(-51, 92), Pair(143, -45),
        Pair(-306, 91), Pair(23, 24), Pair(63, 46), Pair(117, 65), Pair(96, 45), Pair(257, 50), Pair(102, 48), Pair(67, -24),
        Pair(-282, 97), Pair(147, 34), Pair(134, 49), Pair(132, 56), Pair(-19, 66), Pair(-53, 47), Pair(3, 34), Pair(16, 3),
        Pair(-38, 55), Pair(16, 26), Pair(36, 8), Pair(62, 29), Pair(-31, 21), Pair(69, 17), Pair(10, -2), Pair(-19, -1),
        Pair(-51, 38), Pair(19, 38), Pair(-14, 50), Pair(0, 0), Pair(-24, 51), Pair(-29, 25), Pair(38, 6), Pair(-38, 4),
        Pair(-63, 5), Pair(-6, 10), Pair(-33, 21), Pair(-32, 57), Pair(1, 14), Pair(15, -4), Pair(10, -7), Pair(8, -15),
        Pair(28, -27), Pair(-28, 8), Pair(-17, 13), Pair(-36, 28), Pair(-22, 8), Pair(16, -15), Pair(2, -14), Pair(8, -26),
        Pair(9, -38), Pair(-3, -12), Pair(-5, -19), Pair(-14, 13), Pair(11, -29), Pair(16, -23), Pair(3, -24), Pair(2, -29)
      }
    }},
    {{ // Bucket 36
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-27, 27), Pair(-31, 24), Pair(-24, 29), Pair(-9, 19), Pair(-61, 24), Pair(-23, 9), Pair(-7, 11), Pair(4, 16),
        Pair(0, 20), Pair(-1, 16), Pair(-1, 15), Pair(-10, 30), Pair(4, 4), Pair(-2, 21), Pair(-2, 18), Pair(5, 12),
        Pair(-2, 10), Pair(2, 14), Pair(0, 14), Pair(7, 22), Pair(-4, -3), Pair(16, 13), Pair(2, 9), Pair(-1, 10),
        Pair(1, 20), Pair(2, 19), Pair(-5, 9), Pair(-3, 27), Pair(0, -11), Pair(5, 11), Pair(-6, 11), Pair(3, 12),
        Pair(2, 17), Pair(5, 21), Pair(0, 13), Pair(13, 19), Pair(1, -4), Pair(19, 20), Pair(-2, 8), Pair(5, 15),
        Pair(1, 21), Pair(5, 12), Pair(0, 17), Pair(7, 23), Pair(7, 9), Pair(8, 31), Pair(4, 20), Pair(6, 20),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-13, 67), Pair(-45, 24), Pair(-10, 92), Pair(24, 65), Pair(26, 51), Pair(11, 51), Pair(71, 62), Pair(-30, 1),
        Pair(9, 58), Pair(-8, 69), Pair(-9, 64), Pair(-7, 80), Pair(-38, 115), Pair(-9, 53), Pair(25, 58), Pair(-14, 29),
        Pair(30, 61), Pair(0, 83), Pair(-6, 81), Pair(-5, 59), Pair(-51, 86), Pair(19, 47), Pair(-19, 70), Pair(-15, 91),
        Pair(-2, 90), Pair(2, 65), Pair(3, 46), Pair(1, 94), Pair(-32, 71), Pair(-2, 77), Pair(-17, 53), Pair(-18, 76),
        Pair(4, 71), Pair(15, 94), Pair(5, 75), Pair(2, 74), Pair(0, 0), Pair(-6, 78), Pair(-23, 76), Pair(-9, 74),
        Pair(3, 76), Pair(7, 70), Pair(-2, 51), Pair(31, 67), Pair(15, 97), Pair(4, 79), Pair(-5, 38), Pair(7, 78),
        Pair(14, 83), Pair(10, 64), Pair(6, 62), Pair(0, 57), Pair(3, 62), Pair(10, 57), Pair(4, 68), Pair(-5, 91),
        Pair(38, 42), Pair(5, 72), Pair(20, 73), Pair(7, 67), Pair(3, 89), Pair(-11, 82), Pair(10, 67), Pair(-15, 60)
      },
      { // Piece 2
        Pair(26, 0), Pair(0, 37), Pair(75, -15), Pair(110, 19), Pair(82, -15), Pair(17, 71), Pair(-28, 26), Pair(66, 3),
        Pair(13, 22), Pair(15, -6), Pair(7, 50), Pair(50, 6), Pair(21, 39), Pair(18, 14), Pair(-34, 60), Pair(-62, 7),
        Pair(9, 22), Pair(29, 35), Pair(4, 8), Pair(22, 43), Pair(6, 21), Pair(-4, 44), Pair(29, -19), Pair(-20, 48),
        Pair(20, 49), Pair(7, 21), Pair(21, 36), Pair(33, -9), Pair(-22, 48), Pair(56, -1), Pair(2, 58), Pair(-1, 20),
        Pair(1, 27), Pair(20, 40), Pair(-2, 34), Pair(8, 46), Pair(0, 0), Pair(3, 58), Pair(3, 12), Pair(1, 54),
        Pair(15, 60), Pair(3, 28), Pair(4, 57), Pair(-6, 8), Pair(13, 82), Pair(-31, -9), Pair(0, 62), Pair(-14, 41),
        Pair(4, -3), Pair(-2, 62), Pair(-10, 2), Pair(6, 64), Pair(0, 31), Pair(4, 61), Pair(-35, -8), Pair(-5, 55),
        Pair(14, 51), Pair(-28, -21), Pair(2, 61), Pair(6, 13), Pair(15, 40), Pair(-4, 22), Pair(25, 37), Pair(-60, -8)
      },
      { // Piece 3
        Pair(-14, 92), Pair(-19, 97), Pair(-51, 100), Pair(-1, 88), Pair(65, 46), Pair(-59, 83), Pair(22, 78), Pair(31, 73),
        Pair(-20, 103), Pair(-15, 98), Pair(-2, 96), Pair(5, 87), Pair(-11, 67), Pair(-35, 93), Pair(-27, 95), Pair(17, 91),
        Pair(10, 89), Pair(13, 89), Pair(-8, 85), Pair(-21, 86), Pair(-13, 79), Pair(-22, 83), Pair(-17, 103), Pair(9, 84),
        Pair(20, 83), Pair(3, 82), Pair(13, 86), Pair(15, 89), Pair(9, 45), Pair(5, 81), Pair(-7, 92), Pair(12, 76),
        Pair(7, 67), Pair(-3, 91), Pair(1, 78), Pair(3, 73), Pair(0, 0), Pair(-20, 65), Pair(15, 76), Pair(1, 81),
        Pair(6, 87), Pair(5, 90), Pair(28, 72), Pair(5, 85), Pair(2, 45), Pair(-3, 71), Pair(-7, 72), Pair(-13, 84),
        Pair(11, 90), Pair(-4, 79), Pair(10, 65), Pair(-1, 77), Pair(-4, 37), Pair(-15, 98), Pair(4, 75), Pair(16, 95),
        Pair(7, 80), Pair(6, 81), Pair(6, 77), Pair(3, 78), Pair(3, 37), Pair(-6, 79), Pair(5, 83), Pair(17, 72)
      },
      { // Piece 4
        Pair(-3, 123), Pair(57, 110), Pair(9, 129), Pair(24, 144), Pair(-29, 140), Pair(3, 179), Pair(-86, 230), Pair(-19, 232),
        Pair(-13, 167), Pair(3, 137), Pair(26, 130), Pair(15, 133), Pair(32, 98), Pair(-2, 152), Pair(12, 186), Pair(-55, 200),
        Pair(0, 177), Pair(2, 143), Pair(14, 134), Pair(3, 135), Pair(-18, 131), Pair(-14, 184), Pair(-13, 124), Pair(-24, 180),
        Pair(16, 128), Pair(11, 147), Pair(17, 118), Pair(7, 125), Pair(-13, 108), Pair(0, 121), Pair(7, 161), Pair(0, 124),
        Pair(10, 136), Pair(25, 95), Pair(12, 117), Pair(7, 100), Pair(0, 0), Pair(-11, 146), Pair(0, 143), Pair(5, 135),
        Pair(7, 147), Pair(17, 149), Pair(20, 132), Pair(15, 131), Pair(17, 114), Pair(13, 124), Pair(10, 124), Pair(-2, 149),
        Pair(30, 104), Pair(19, 142), Pair(19, 122), Pair(20, 139), Pair(19, 116), Pair(15, 129), Pair(22, 119), Pair(28, 138),
        Pair(36, 106), Pair(15, 117), Pair(18, 167), Pair(19, 140), Pair(26, 110), Pair(7, 141), Pair(17, 113), Pair(42, 106)
      },
      { // Piece 5
        Pair(-48, -26), Pair(-151, 2), Pair(48, 74), Pair(-290, 73), Pair(341, -32), Pair(138, 23), Pair(22, 29), Pair(104, -9),
        Pair(100, -16), Pair(-3, 8), Pair(14, 56), Pair(-1, 83), Pair(143, 40), Pair(25, 79), Pair(94, 29), Pair(68, 23),
        Pair(12, -14), Pair(-33, -7), Pair(-43, 29), Pair(83, 37), Pair(39, 46), Pair(18, 60), Pair(96, 12), Pair(-98, 21),
        Pair(-85, -7), Pair(-137, 21), Pair(-23, 13), Pair(3, 22), Pair(77, 11), Pair(-64, 16), Pair(11, 14), Pair(8, 4),
        Pair(-27, 0), Pair(-21, -3), Pair(26, 9), Pair(-13, 38), Pair(0, 0), Pair(-40, 25), Pair(35, 3), Pair(25, 7),
        Pair(18, -29), Pair(-30, 7), Pair(12, -5), Pair(-33, 23), Pair(-14, 30), Pair(-26, 11), Pair(14, -5), Pair(4, -4),
        Pair(2, -21), Pair(10, -18), Pair(-4, -23), Pair(-30, 11), Pair(-28, 13), Pair(-24, 7), Pair(6, -16), Pair(8, -22),
        Pair(1, -63), Pair(-12, -27), Pair(-16, -26), Pair(7, -14), Pair(1, -23), Pair(-11, -19), Pair(1, -28), Pair(4, -38)
      }
    }},
    {{ // Bucket 37
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-4, 19), Pair(-25, 18), Pair(-17, 18), Pair(-4, 12), Pair(-8, 22), Pair(-32, -25), Pair(-15, 15), Pair(-8, 12),
        Pair(-2, 18), Pair(-2, 19), Pair(3, 9), Pair(10, 16), Pair(-6, 17), Pair(-11, 14), Pair(-26, 27), Pair(-8, 12),
        Pair(2, 11), Pair(4, 13), Pair(4, 10), Pair(5, 16), Pair(9, 11), Pair(-6, -10), Pair(3, 2), Pair(2, 3),
        Pair(-1, 14), Pair(9, 18), Pair(5, 17), Pair(-3, 7), Pair(3, 12), Pair(-7, -5), Pair(7, 0), Pair(-5, 5),
        Pair(-2, 15), Pair(0, 14), Pair(3, 13), Pair(4, 9), Pair(17, 14), Pair(4, -3), Pair(9, 5), Pair(-3, 8),
        Pair(3, 17), Pair(5, 16), Pair(0, 11), Pair(2, 24), Pair(14, 17), Pair(5, 7), Pair(5, 17), Pair(-5, 9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(74, 12), Pair(-48, 55), Pair(39, 62), Pair(74, 64), Pair(40, 63), Pair(49, 39), Pair(180, 41), Pair(-81, 20),
        Pair(23, 49), Pair(14, 59), Pair(-2, 72), Pair(5, 75), Pair(13, 74), Pair(-30, 60), Pair(-38, 83), Pair(-28, 74),
        Pair(-11, 63), Pair(11, 68), Pair(22, 66), Pair(-5, 70), Pair(-11, 60), Pair(-34, 77), Pair(-11, 53), Pair(-29, 75),
        Pair(3, 56), Pair(16, 65), Pair(16, 74), Pair(-5, 66), Pair(15, 73), Pair(-21, 64), Pair(-11, 62), Pair(-35, 49),
        Pair(14, 61), Pair(14, 61), Pair(11, 66), Pair(19, 71), Pair(-2, 74), Pair(0, 0), Pair(-29, 86), Pair(1, 72),
        Pair(10, 62), Pair(22, 58), Pair(10, 65), Pair(20, 44), Pair(18, 77), Pair(16, 82), Pair(15, 57), Pair(-7, 34),
        Pair(33, 54), Pair(29, 47), Pair(25, 65), Pair(13, 55), Pair(10, 53), Pair(22, 42), Pair(5, 45), Pair(7, 43),
        Pair(-18, 73), Pair(17, 55), Pair(18, 47), Pair(24, 62), Pair(23, 55), Pair(10, 56), Pair(16, 53), Pair(48, 27)
      },
      { // Piece 2
        Pair(23, 4), Pair(-22, -23), Pair(22, 8), Pair(85, 3), Pair(26, 19), Pair(-6, 3), Pair(173, 8), Pair(15, 0),
        Pair(3, 4), Pair(20, 34), Pair(23, 7), Pair(73, 19), Pair(40, -4), Pair(-31, 41), Pair(28, 9), Pair(-4, 57),
        Pair(17, 37), Pair(31, 15), Pair(36, 26), Pair(26, -1), Pair(48, 36), Pair(-26, 21), Pair(20, 37), Pair(-36, 10),
        Pair(13, 24), Pair(30, 32), Pair(10, 27), Pair(-1, 49), Pair(19, 10), Pair(-6, 39), Pair(-29, 23), Pair(-9, 48),
        Pair(18, 37), Pair(14, 32), Pair(15, 43), Pair(7, 33), Pair(3, 52), Pair(0, 0), Pair(20, 41), Pair(-13, 24),
        Pair(-4, 35), Pair(5, 51), Pair(-4, 30), Pair(22, 49), Pair(-6, 20), Pair(27, 64), Pair(-20, -2), Pair(5, 56),
        Pair(12, 40), Pair(-6, 44), Pair(19, 47), Pair(-10, 23), Pair(19, 51), Pair(4, 18), Pair(12, 52), Pair(-36, -32),
        Pair(4, 42), Pair(11, 53), Pair(-15, 24), Pair(30, 44), Pair(4, 29), Pair(22, 45), Pair(-13, 45), Pair(50, 6)
      },
      { // Piece 3
        Pair(44, 59), Pair(44, 57), Pair(59, 57), Pair(22, 71), Pair(23, 70), Pair(156, 6), Pair(41, 65), Pair(1, 73),
        Pair(30, 73), Pair(29, 68), Pair(33, 67), Pair(20, 70), Pair(14, 77), Pair(-14, 69), Pair(17, 74), Pair(7, 91),
        Pair(26, 67), Pair(30, 63), Pair(38, 63), Pair(18, 66), Pair(-12, 82), Pair(-16, 55), Pair(21, 66), Pair(-11, 84),
        Pair(22, 67), Pair(26, 66), Pair(23, 66), Pair(32, 63), Pair(39, 76), Pair(4, 39), Pair(7, 85), Pair(-6, 79),
        Pair(23, 66), Pair(31, 60), Pair(20, 67), Pair(35, 59), Pair(14, 74), Pair(0, 0), Pair(21, 41), Pair(4, 54),
        Pair(22, 59), Pair(15, 70), Pair(24, 66), Pair(37, 58), Pair(25, 66), Pair(6, 44), Pair(15, 58), Pair(9, 72),
        Pair(36, 55), Pair(30, 56), Pair(33, 58), Pair(32, 65), Pair(22, 76), Pair(4, 32), Pair(41, 65), Pair(41, 67),
        Pair(24, 59), Pair(28, 59), Pair(26, 62), Pair(30, 57), Pair(20, 63), Pair(15, 32), Pair(20, 71), Pair(19, 59)
      },
      { // Piece 4
        Pair(42, 144), Pair(40, 103), Pair(-4, 160), Pair(20, 126), Pair(15, 146), Pair(-55, 147), Pair(-75, 197), Pair(-31, 162),
        Pair(-12, 142), Pair(9, 130), Pair(-1, 113), Pair(-1, 128), Pair(-14, 124), Pair(-6, 91), Pair(-35, 155), Pair(-6, 151),
        Pair(-4, 154), Pair(-8, 158), Pair(11, 117), Pair(-1, 114), Pair(-12, 130), Pair(-36, 115), Pair(-18, 108), Pair(-19, 139),
        Pair(7, 127), Pair(-2, 155), Pair(8, 117), Pair(-10, 147), Pair(-5, 121), Pair(-6, 55), Pair(-12, 146), Pair(-22, 162),
        Pair(8, 147), Pair(17, 119), Pair(16, 115), Pair(4, 114), Pair(11, 105), Pair(0, 0), Pair(-6, 132), Pair(1, 98),
        Pair(18, 136), Pair(18, 125), Pair(18, 127), Pair(16, 125), Pair(5, 121), Pair(15, 92), Pair(2, 109), Pair(23, 96),
        Pair(8, 122), Pair(18, 123), Pair(14, 127), Pair(12, 120), Pair(15, 120), Pair(20, 84), Pair(4, 136), Pair(-2, 72),
        Pair(15, 147), Pair(21, 111), Pair(6, 119), Pair(12, 133), Pair(15, 122), Pair(20, 100), Pair(35, 115), Pair(15, 163)
      },
      { // Piece 5
        Pair(119, -78), Pair(-95, -15), Pair(-19, -39), Pair(74, 11), Pair(-162, 53), Pair(-1, 23), Pair(-32, 33), Pair(-36, 6),
        Pair(29, 18), Pair(10, 16), Pair(19, 3), Pair(-25, 45), Pair(-37, 56), Pair(-40, 75), Pair(144, 41), Pair(75, 60),
        Pair(-152, 43), Pair(17, 0), Pair(21, 7), Pair(-77, 41), Pair(96, 41), Pair(104, 50), Pair(44, 63), Pair(84, 34),
        Pair(-56, 18), Pair(-29, 6), Pair(-18, 17), Pair(-24, 33), Pair(14, 18), Pair(70, 6), Pair(29, 3), Pair(63, 24),
        Pair(-36, 5), Pair(28, 1), Pair(-91, 26), Pair(-23, 27), Pair(50, 15), Pair(0, 0), Pair(48, 1), Pair(100, 6),
        Pair(-65, -13), Pair(-45, 14), Pair(-21, -1), Pair(4, 13), Pair(-14, 13), Pair(3, 9), Pair(18, 3), Pair(32, -10),
        Pair(-21, -17), Pair(-24, 13), Pair(-21, 3), Pair(5, 5), Pair(-1, 10), Pair(-14, 1), Pair(-13, 11), Pair(17, -4),
        Pair(-10, -31), Pair(-17, -14), Pair(-28, -7), Pair(-3, -15), Pair(7, -27), Pair(14, -32), Pair(5, -34), Pair(7, -34)
      }
    }},
    {{ // Bucket 38
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-32, 25), Pair(-6, 31), Pair(-11, 18), Pair(24, 6), Pair(17, 5), Pair(15, 15), Pair(40, -48), Pair(-3, 40),
        Pair(-5, 17), Pair(-2, 23), Pair(7, 15), Pair(-6, 17), Pair(-4, 19), Pair(3, 25), Pair(11, -23), Pair(-3, 24),
        Pair(-4, 22), Pair(-3, 17), Pair(-1, 16), Pair(5, 8), Pair(4, 12), Pair(12, 9), Pair(17, -27), Pair(1, -1),
        Pair(-7, 21), Pair(3, 18), Pair(1, 19), Pair(4, 18), Pair(-4, 8), Pair(6, -2), Pair(4, 5), Pair(9, -9),
        Pair(-3, 23), Pair(0, 21), Pair(2, 19), Pair(2, 18), Pair(-4, 16), Pair(25, 9), Pair(14, -16), Pair(18, 11),
        Pair(-6, 26), Pair(1, 22), Pair(-1, 18), Pair(3, 9), Pair(0, 18), Pair(9, 27), Pair(14, -9), Pair(2, 26),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-9, 56), Pair(155, 19), Pair(26, 58), Pair(71, 49), Pair(-27, 90), Pair(89, 67), Pair(-34, 52), Pair(-90, 61),
        Pair(58, 30), Pair(40, 53), Pair(35, 73), Pair(16, 68), Pair(44, 76), Pair(23, 72), Pair(-17, 89), Pair(12, 58),
        Pair(11, 51), Pair(13, 84), Pair(25, 80), Pair(22, 73), Pair(-1, 77), Pair(5, 64), Pair(1, 63), Pair(20, 60),
        Pair(17, 55), Pair(22, 64), Pair(25, 68), Pair(24, 72), Pair(12, 72), Pair(27, 56), Pair(15, 69), Pair(-43, 8),
        Pair(22, 71), Pair(19, 87), Pair(12, 78), Pair(7, 74), Pair(31, 81), Pair(12, 69), Pair(0, 0), Pair(-14, 81),
        Pair(16, 50), Pair(22, 62), Pair(16, 66), Pair(14, 71), Pair(20, 61), Pair(15, 75), Pair(31, 77), Pair(17, 84),
        Pair(-18, 54), Pair(23, 59), Pair(17, 68), Pair(11, 71), Pair(10, 64), Pair(15, 69), Pair(-4, 65), Pair(0, 31),
        Pair(37, 37), Pair(-2, 68), Pair(9, 51), Pair(22, 88), Pair(7, 77), Pair(15, 49), Pair(7, 40), Pair(2, 7)
      },
      { // Piece 2
        Pair(3, 13), Pair(37, 31), Pair(114, -18), Pair(123, 19), Pair(83, 0), Pair(26, 46), Pair(155, 18), Pair(10, 61),
        Pair(48, 27), Pair(31, 23), Pair(10, 40), Pair(86, 8), Pair(77, 18), Pair(33, 20), Pair(82, 44), Pair(-24, 43),
        Pair(29, 25), Pair(38, 41), Pair(53, 16), Pair(36, 41), Pair(19, 27), Pair(45, 59), Pair(55, 44), Pair(11, 44),
        Pair(24, 43), Pair(25, 36), Pair(48, 45), Pair(34, 27), Pair(10, 60), Pair(91, 26), Pair(21, 47), Pair(-107, -22),
        Pair(-3, 28), Pair(20, 59), Pair(23, 30), Pair(13, 57), Pair(23, 43), Pair(18, 64), Pair(0, 0), Pair(28, 72),
        Pair(16, 70), Pair(23, 31), Pair(13, 62), Pair(19, 42), Pair(21, 62), Pair(9, 33), Pair(32, 69), Pair(-31, -4),
        Pair(6, 21), Pair(15, 68), Pair(9, 49), Pair(22, 59), Pair(13, 36), Pair(17, 67), Pair(13, 37), Pair(17, 41),
        Pair(15, 68), Pair(25, 30), Pair(22, 57), Pair(15, 41), Pair(10, 56), Pair(9, 19), Pair(35, 85), Pair(10, 18)
      },
      { // Piece 3
        Pair(39, 88), Pair(41, 87), Pair(38, 85), Pair(81, 78), Pair(38, 92), Pair(-11, 109), Pair(179, -2), Pair(18, 94),
        Pair(37, 84), Pair(25, 97), Pair(6, 91), Pair(37, 85), Pair(53, 79), Pair(16, 95), Pair(0, 69), Pair(11, 84),
        Pair(7, 99), Pair(9, 98), Pair(33, 90), Pair(26, 84), Pair(29, 87), Pair(11, 95), Pair(19, 67), Pair(-4, 101),
        Pair(8, 95), Pair(4, 95), Pair(7, 93), Pair(45, 75), Pair(32, 94), Pair(12, 104), Pair(54, 36), Pair(22, 100),
        Pair(34, 76), Pair(14, 93), Pair(42, 89), Pair(41, 79), Pair(34, 94), Pair(-1, 103), Pair(0, 0), Pair(-9, 68),
        Pair(24, 92), Pair(30, 76), Pair(15, 90), Pair(28, 92), Pair(16, 95), Pair(3, 89), Pair(21, 44), Pair(-20, 104),
        Pair(20, 86), Pair(31, 83), Pair(30, 73), Pair(23, 89), Pair(24, 80), Pair(17, 71), Pair(51, 9), Pair(24, 82),
        Pair(16, 80), Pair(25, 77), Pair(19, 82), Pair(26, 78), Pair(24, 84), Pair(15, 80), Pair(36, 15), Pair(4, 87)
      },
      { // Piece 4
        Pair(70, 98), Pair(65, 127), Pair(41, 90), Pair(67, 114), Pair(75, 113), Pair(110, 130), Pair(74, 112), Pair(74, 98),
        Pair(16, 143), Pair(20, 131), Pair(19, 152), Pair(20, 125), Pair(21, 142), Pair(29, 146), Pair(35, 48), Pair(60, 51),
        Pair(4, 145), Pair(21, 145), Pair(16, 125), Pair(23, 123), Pair(7, 125), Pair(15, 119), Pair(35, 50), Pair(10, 104),
        Pair(-4, 161), Pair(7, 143), Pair(16, 135), Pair(40, 109), Pair(29, 120), Pair(-6, 108), Pair(10, 93), Pair(-8, 90),
        Pair(27, 109), Pair(49, 120), Pair(37, 126), Pair(21, 111), Pair(37, 112), Pair(22, 99), Pair(0, 0), Pair(28, 69),
        Pair(20, 130), Pair(42, 109), Pair(28, 115), Pair(38, 112), Pair(41, 112), Pair(27, 122), Pair(27, 66), Pair(26, 87),
        Pair(56, 122), Pair(41, 121), Pair(31, 136), Pair(29, 132), Pair(40, 83), Pair(23, 104), Pair(26, 80), Pair(10, 150),
        Pair(40, 117), Pair(36, 133), Pair(34, 148), Pair(28, 149), Pair(21, 155), Pair(39, 86), Pair(67, -18), Pair(49, 137)
      },
      { // Piece 5
        Pair(0, -15), Pair(-101, 49), Pair(-113, 31), Pair(-11, 37), Pair(-98, 1), Pair(113, 50), Pair(52, -20), Pair(119, 188),
        Pair(-114, -14), Pair(65, -32), Pair(27, -17), Pair(-45, 0), Pair(55, 35), Pair(128, 18), Pair(236, 37), Pair(46, 70),
        Pair(-93, 24), Pair(-104, 26), Pair(-29, 4), Pair(-63, 22), Pair(1, 48), Pair(218, 36), Pair(74, 75), Pair(95, 48),
        Pair(-81, -1), Pair(-2, -3), Pair(48, 8), Pair(-19, 29), Pair(-28, 44), Pair(50, 15), Pair(30, 31), Pair(-9, 31),
        Pair(-80, 29), Pair(-28, 12), Pair(-57, 22), Pair(-76, 26), Pair(-37, 38), Pair(5, 25), Pair(0, 0), Pair(45, 5),
        Pair(-85, 1), Pair(-44, 11), Pair(-33, 9), Pair(-56, 22), Pair(-11, 23), Pair(-34, 16), Pair(3, 6), Pair(0, -1),
        Pair(-65, -2), Pair(-12, -5), Pair(-36, 6), Pair(-24, 7), Pair(-18, 8), Pair(-2, 8), Pair(7, -9), Pair(-24, 10),
        Pair(-22, -66), Pair(-19, -13), Pair(-19, -23), Pair(-15, -13), Pair(1, -21), Pair(12, -32), Pair(2, -19), Pair(-3, -45)
      }
    }},
    {{ // Bucket 39
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-3, 17), Pair(-20, 34), Pair(-12, 18), Pair(14, 1), Pair(-5, 14), Pair(-6, -5), Pair(-10, 26), Pair(16, -5),
        Pair(-6, 24), Pair(-4, 26), Pair(-2, 17), Pair(-2, 20), Pair(1, 14), Pair(-15, 10), Pair(-3, 22), Pair(12, -5),
        Pair(-4, 18), Pair(-2, 16), Pair(-3, 17), Pair(1, 12), Pair(-1, 9), Pair(2, 8), Pair(4, 9), Pair(20, -19),
        Pair(-6, 22), Pair(-2, 17), Pair(-1, 15), Pair(3, 14), Pair(4, 12), Pair(-5, 4), Pair(9, -6), Pair(13, -4),
        Pair(-2, 22), Pair(0, 18), Pair(2, 16), Pair(0, 20), Pair(7, 13), Pair(11, 8), Pair(13, 5), Pair(6, 4),
        Pair(-2, 21), Pair(-3, 19), Pair(1, 14), Pair(1, 17), Pair(3, 10), Pair(5, 12), Pair(3, 15), Pair(7, 6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(55, -7), Pair(238, -6), Pair(13, 27), Pair(-35, 52), Pair(16, 40), Pair(53, 72), Pair(251, -1), Pair(-50, -22),
        Pair(20, 30), Pair(4, 37), Pair(18, 34), Pair(3, 56), Pair(0, 43), Pair(-46, 63), Pair(-33, 80), Pair(11, 51),
        Pair(-15, 53), Pair(12, 49), Pair(8, 54), Pair(-1, 55), Pair(-1, 69), Pair(2, 51), Pair(27, 37), Pair(-52, 56),
        Pair(-3, 46), Pair(1, 48), Pair(0, 56), Pair(11, 54), Pair(0, 62), Pair(-8, 55), Pair(6, 34), Pair(-4, 43),
        Pair(-1, 55), Pair(-22, 63), Pair(13, 47), Pair(7, 52), Pair(4, 59), Pair(2, 56), Pair(-11, 69), Pair(0, 0),
        Pair(5, 55), Pair(10, 34), Pair(5, 49), Pair(0, 52), Pair(11, 56), Pair(0, 38), Pair(12, 52), Pair(14, 71),
        Pair(-13, 60), Pair(-1, 41), Pair(17, 40), Pair(10, 52), Pair(8, 41), Pair(12, 48), Pair(4, 49), Pair(-2, 29),
        Pair(-59, 64), Pair(2, 50), Pair(2, 54), Pair(20, 22), Pair(17, 51), Pair(-4, 38), Pair(1, 55), Pair(-47, 43)
      },
      { // Piece 2
        Pair(1, 20), Pair(41, 8), Pair(16, 30), Pair(28, 13), Pair(121, 0), Pair(0, 30), Pair(-29, 34), Pair(48, 23),
        Pair(19, 12), Pair(13, 21), Pair(27, 16), Pair(11, 16), Pair(-13, 24), Pair(31, 32), Pair(-11, 44), Pair(-39, 44),
        Pair(4, 38), Pair(12, 15), Pair(17, 35), Pair(21, 16), Pair(27, 33), Pair(-25, 43), Pair(14, 36), Pair(-3, 30),
        Pair(7, 28), Pair(13, 24), Pair(11, 21), Pair(22, 37), Pair(11, 27), Pair(-6, 62), Pair(-3, 57), Pair(5, 38),
        Pair(13, 38), Pair(0, 33), Pair(15, 31), Pair(19, 35), Pair(4, 47), Pair(12, 36), Pair(-1, 44), Pair(0, 0),
        Pair(12, 28), Pair(4, 39), Pair(11, 30), Pair(5, 40), Pair(10, 40), Pair(12, 40), Pair(21, 20), Pair(14, 50),
        Pair(12, 26), Pair(8, 30), Pair(10, 47), Pair(7, 36), Pair(8, 45), Pair(8, 34), Pair(10, 34), Pair(4, 20),
        Pair(31, 28), Pair(13, 41), Pair(12, 28), Pair(5, 45), Pair(19, 24), Pair(2, 37), Pair(32, 28), Pair(-4, 32)
      },
      { // Piece 3
        Pair(1, 73), Pair(40, 56), Pair(51, 51), Pair(1, 64), Pair(28, 62), Pair(-38, 76), Pair(4, 70), Pair(91, -3),
        Pair(12, 71), Pair(4, 71), Pair(12, 75), Pair(0, 67), Pair(0, 66), Pair(-9, 62), Pair(-6, 64), Pair(6, 29),
        Pair(3, 82), Pair(12, 70), Pair(8, 74), Pair(21, 64), Pair(2, 68), Pair(5, 81), Pair(14, 65), Pair(7, 51),
        Pair(-15, 80), Pair(2, 77), Pair(7, 76), Pair(24, 70), Pair(1, 75), Pair(21, 67), Pair(-2, 80), Pair(33, 10),
        Pair(20, 63), Pair(3, 72), Pair(14, 69), Pair(12, 67), Pair(6, 73), Pair(10, 80), Pair(0, 85), Pair(0, 0),
        Pair(19, 57), Pair(-2, 72), Pair(4, 62), Pair(-11, 74), Pair(0, 63), Pair(-18, 76), Pair(0, 56), Pair(-37, 5),
        Pair(14, 54), Pair(5, 57), Pair(11, 65), Pair(4, 65), Pair(3, 74), Pair(1, 64), Pair(12, 43), Pair(-46, 34),
        Pair(11, 58), Pair(14, 59), Pair(13, 60), Pair(16, 51), Pair(13, 56), Pair(7, 61), Pair(-6, 64), Pair(-6, 8)
      },
      { // Piece 4
        Pair(12, 78), Pair(39, 67), Pair(43, 55), Pair(46, 55), Pair(83, 48), Pair(41, 61), Pair(56, 65), Pair(30, 72),
        Pair(4, 99), Pair(25, 69), Pair(28, 84), Pair(37, 63), Pair(34, 84), Pair(35, 91), Pair(-2, 74), Pair(-1, 70),
        Pair(28, 83), Pair(32, 85), Pair(11, 88), Pair(46, 58), Pair(31, 85), Pair(7, 63), Pair(21, 48), Pair(-30, 78),
        Pair(32, 78), Pair(41, 56), Pair(18, 84), Pair(21, 84), Pair(7, 94), Pair(3, 101), Pair(4, 101), Pair(11, 41),
        Pair(21, 92), Pair(25, 94), Pair(18, 96), Pair(16, 95), Pair(16, 82), Pair(4, 100), Pair(18, 82), Pair(0, 0),
        Pair(29, 75), Pair(32, 86), Pair(21, 77), Pair(23, 88), Pair(23, 91), Pair(11, 79), Pair(17, 69), Pair(38, 8),
        Pair(32, 96), Pair(17, 109), Pair(28, 98), Pair(26, 103), Pair(22, 87), Pair(18, 78), Pair(22, 81), Pair(33, -34),
        Pair(40, 79), Pair(21, 97), Pair(29, 119), Pair(24, 101), Pair(23, 93), Pair(23, 78), Pair(21, 111), Pair(7, 14)
      },
      { // Piece 5
        Pair(20, 34), Pair(-95, 30), Pair(-80, -19), Pair(-150, 46), Pair(-75, 30), Pair(-9, 15), Pair(-117, 84), Pair(83, 44),
        Pair(43, -9), Pair(-64, -27), Pair(-192, 23), Pair(30, -6), Pair(-63, 18), Pair(-89, 110), Pair(-36, 66), Pair(-18, 45),
        Pair(33, -10), Pair(-114, 13), Pair(-84, 6), Pair(-58, 23), Pair(-7, 41), Pair(6, 44), Pair(72, 57), Pair(60, 23),
        Pair(-11, -19), Pair(-14, -1), Pair(-72, 12), Pair(-41, 30), Pair(-37, 26), Pair(-3, 42), Pair(20, 13), Pair(16, 10),
        Pair(-105, -3), Pair(-113, 28), Pair(-112, 31), Pair(-60, 31), Pair(-59, 24), Pair(-3, 21), Pair(-33, 3), Pair(0, 0),
        Pair(-92, -4), Pair(-26, 5), Pair(-91, 21), Pair(-72, 18), Pair(-21, 8), Pair(-12, 4), Pair(-30, -9), Pair(-7, -19),
        Pair(-54, -18), Pair(-58, 7), Pair(-44, 4), Pair(-44, 14), Pair(-24, -6), Pair(-1, -2), Pair(-1, -5), Pair(-1, -16),
        Pair(-58, -52), Pair(-39, -10), Pair(-38, 8), Pair(-33, -8), Pair(-11, -9), Pair(-9, -16), Pair(14, -15), Pair(2, -25)
      }
    }},
    {{ // Bucket 40
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-13, 41), Pair(-2, 28), Pair(2, 19), Pair(28, 25), Pair(7, 12), Pair(-4, 25), Pair(-1, 24), Pair(-31, 42),
        Pair(-14, 39), Pair(-10, 19), Pair(-11, 19), Pair(-8, 16), Pair(11, 9), Pair(-3, 11), Pair(-11, 18), Pair(-2, 20),
        Pair(2, 15), Pair(-1, 19), Pair(-2, 11), Pair(-1, 11), Pair(1, 15), Pair(-1, 18), Pair(1, 15), Pair(-2, 18),
        Pair(-3, 14), Pair(9, 6), Pair(1, 11), Pair(0, 12), Pair(2, 12), Pair(4, 20), Pair(-4, 21), Pair(-4, 21),
        Pair(-4, 9), Pair(3, 3), Pair(-4, 12), Pair(3, 17), Pair(-3, 17), Pair(4, 17), Pair(-1, 18), Pair(-6, 23),
        Pair(2, 2), Pair(6, 21), Pair(-7, 15), Pair(2, 19), Pair(0, 19), Pair(0, 21), Pair(-3, 24), Pair(-3, 28),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-1, 17), Pair(-132, 85), Pair(-8, 81), Pair(-58, 50), Pair(-81, 100), Pair(20, 34), Pair(14, 22), Pair(-32, 78),
        Pair(-10, 67), Pair(-8, 71), Pair(4, 67), Pair(-10, 78), Pair(-47, 80), Pair(5, 71), Pair(-6, 89), Pair(-21, 76),
        Pair(1, 62), Pair(21, 63), Pair(1, 79), Pair(-12, 74), Pair(-9, 60), Pair(-29, 89), Pair(-23, 102), Pair(-26, 70),
        Pair(-4, 64), Pair(7, 74), Pair(0, 71), Pair(-3, 80), Pair(-4, 81), Pair(-3, 84), Pair(-10, 76), Pair(-25, 80),
        Pair(2, 63), Pair(37, 74), Pair(2, 68), Pair(3, 79), Pair(-6, 80), Pair(-4, 87), Pair(-17, 82), Pair(0, 63),
        Pair(0, 0), Pair(4, 75), Pair(6, 70), Pair(9, 74), Pair(-1, 93), Pair(2, 78), Pair(0, 85), Pair(-2, 74),
        Pair(2, 104), Pair(12, 68), Pair(-10, 77), Pair(1, 79), Pair(4, 82), Pair(-6, 92), Pair(-8, 76), Pair(-8, 84),
        Pair(71, -2), Pair(2, 54), Pair(-9, 53), Pair(-2, 81), Pair(0, 76), Pair(-4, 77), Pair(13, 77), Pair(11, 70)
      },
      { // Piece 2
        Pair(33, 43), Pair(34, 42), Pair(7, 73), Pair(20, 29), Pair(-32, 66), Pair(66, 25), Pair(6, 47), Pair(21, 13),
        Pair(16, 60), Pair(16, 73), Pair(6, 39), Pair(45, 56), Pair(16, 42), Pair(-19, 85), Pair(16, 42), Pair(-13, 67),
        Pair(25, 45), Pair(23, 50), Pair(26, 71), Pair(6, 38), Pair(-16, 72), Pair(-4, 42), Pair(5, 62), Pair(-17, 64),
        Pair(12, 61), Pair(11, 74), Pair(24, 38), Pair(1, 71), Pair(5, 53), Pair(2, 69), Pair(-2, 56), Pair(3, 66),
        Pair(-1, 70), Pair(53, 46), Pair(8, 70), Pair(8, 58), Pair(-5, 78), Pair(3, 59), Pair(0, 73), Pair(4, 26),
        Pair(0, 0), Pair(9, 61), Pair(6, 60), Pair(4, 77), Pair(5, 63), Pair(7, 69), Pair(14, 59), Pair(8, 61),
        Pair(16, 62), Pair(4, 49), Pair(2, 73), Pair(2, 68), Pair(8, 79), Pair(9, 62), Pair(2, 81), Pair(4, 61),
        Pair(1, 52), Pair(3, 64), Pair(-3, 55), Pair(4, 65), Pair(13, 55), Pair(5, 82), Pair(23, 41), Pair(12, 88)
      },
      { // Piece 3
        Pair(9, 78), Pair(-9, 117), Pair(-35, 128), Pair(-28, 114), Pair(-41, 122), Pair(-24, 113), Pair(-12, 122), Pair(-16, 114),
        Pair(-38, 101), Pair(-28, 118), Pair(-14, 115), Pair(-13, 105), Pair(-29, 120), Pair(-29, 114), Pair(-13, 116), Pair(-8, 109),
        Pair(-21, 101), Pair(-11, 113), Pair(-20, 116), Pair(-34, 118), Pair(-14, 118), Pair(-38, 124), Pair(-10, 115), Pair(-11, 111),
        Pair(-50, 115), Pair(-9, 111), Pair(-5, 113), Pair(-17, 112), Pair(-12, 101), Pair(-26, 136), Pair(-26, 126), Pair(-14, 117),
        Pair(-19, 93), Pair(-3, 139), Pair(-16, 127), Pair(-4, 123), Pair(-10, 127), Pair(-20, 118), Pair(-30, 124), Pair(-20, 121),
        Pair(0, 0), Pair(-16, 131), Pair(5, 112), Pair(0, 115), Pair(-12, 114), Pair(-11, 111), Pair(-11, 114), Pair(-4, 114),
        Pair(-59, 105), Pair(-14, 111), Pair(-8, 122), Pair(-7, 113), Pair(-9, 118), Pair(-9, 113), Pair(-15, 102), Pair(-4, 101),
        Pair(-27, 73), Pair(-13, 117), Pair(-12, 120), Pair(-10, 123), Pair(-9, 113), Pair(-10, 107), Pair(-23, 119), Pair(1, 103)
      },
      { // Piece 4
        Pair(-15, 216), Pair(-20, 232), Pair(-27, 240), Pair(-43, 239), Pair(-26, 219), Pair(43, 162), Pair(18, 186), Pair(-29, 219),
        Pair(-36, 212), Pair(11, 184), Pair(7, 179), Pair(24, 191), Pair(1, 182), Pair(-2, 208), Pair(33, 230), Pair(13, 178),
        Pair(-23, 203), Pair(4, 188), Pair(-8, 223), Pair(-27, 223), Pair(-3, 203), Pair(-21, 249), Pair(-5, 203), Pair(-16, 232),
        Pair(-2, 193), Pair(3, 221), Pair(2, 195), Pair(2, 195), Pair(23, 166), Pair(-4, 201), Pair(4, 209), Pair(6, 195),
        Pair(-4, 233), Pair(14, 225), Pair(8, 212), Pair(21, 211), Pair(-2, 225), Pair(13, 222), Pair(1, 202), Pair(26, 165),
        Pair(0, 0), Pair(14, 207), Pair(20, 203), Pair(13, 207), Pair(16, 229), Pair(11, 211), Pair(14, 208), Pair(31, 165),
        Pair(-11, 183), Pair(21, 200), Pair(16, 202), Pair(16, 209), Pair(16, 214), Pair(21, 213), Pair(18, 234), Pair(21, 181),
        Pair(1, 155), Pair(8, 226), Pair(14, 221), Pair(14, 207), Pair(20, 210), Pair(10, 235), Pair(-34, 237), Pair(52, 158)
      },
      { // Piece 5
        Pair(-89, 73), Pair(100, -2), Pair(-91, 0), Pair(45, 14), Pair(-107, 2), Pair(-133, 5), Pair(165, -9), Pair(-95, -25),
        Pair(-168, 70), Pair(-131, 97), Pair(78, 47), Pair(-20, 27), Pair(13, 3), Pair(-49, 30), Pair(37, -19), Pair(-84, 21),
        Pair(-49, 25), Pair(-52, 53), Pair(-17, 31), Pair(-47, 43), Pair(-171, 43), Pair(18, -9), Pair(-36, 18), Pair(-46, -14),
        Pair(-31, 59), Pair(38, 32), Pair(55, 22), Pair(22, 46), Pair(-43, 30), Pair(-2, 14), Pair(-76, 23), Pair(-117, 20),
        Pair(-25, 57), Pair(-15, 15), Pair(-37, 42), Pair(-22, 37), Pair(-42, 31), Pair(11, 23), Pair(-21, 16), Pair(-45, 13),
        Pair(0, 0), Pair(9, 3), Pair(-14, 23), Pair(-27, 27), Pair(-30, 26), Pair(-33, 15), Pair(-8, 9), Pair(-43, -1),
        Pair(54, -14), Pair(41, -17), Pair(26, 2), Pair(-2, 13), Pair(-13, 18), Pair(-15, 17), Pair(-18, 8), Pair(-18, 3),
        Pair(85, -36), Pair(96, -11), Pair(59, -17), Pair(13, -14), Pair(2, -1), Pair(-11, 2), Pair(-7, -1), Pair(-4, -17)
      }
    }},
    {{ // Bucket 41
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-36, 40), Pair(-20, 25), Pair(-51, 43), Pair(6, 6), Pair(-9, 17), Pair(-3, 9), Pair(13, -4), Pair(-22, 16),
        Pair(-11, 20), Pair(-7, 19), Pair(-5, 12), Pair(0, 14), Pair(-5, 12), Pair(-2, 18), Pair(-11, 13), Pair(-10, 13),
        Pair(-2, 15), Pair(7, 16), Pair(-3, 14), Pair(0, 16), Pair(-1, 11), Pair(3, 11), Pair(2, 16), Pair(-4, 16),
        Pair(2, 7), Pair(-6, 0), Pair(2, 7), Pair(8, 8), Pair(1, 13), Pair(7, 21), Pair(3, 22), Pair(-1, 17),
        Pair(6, 2), Pair(-8, 3), Pair(2, 15), Pair(-4, 16), Pair(0, 18), Pair(3, 20), Pair(3, 17), Pair(-4, 18),
        Pair(3, 20), Pair(6, -6), Pair(12, 33), Pair(4, 18), Pair(-2, 24), Pair(-2, 23), Pair(4, 25), Pair(-2, 22),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-76, 118), Pair(-98, 109), Pair(-21, 69), Pair(-6, 60), Pair(-3, 56), Pair(-17, 68), Pair(-107, 52), Pair(-101, 63),
        Pair(-27, 73), Pair(-32, 76), Pair(-49, 96), Pair(-25, 77), Pair(-36, 66), Pair(-27, 82), Pair(-21, 94), Pair(-38, 56),
        Pair(-19, 65), Pair(-3, 72), Pair(-10, 86), Pair(-22, 81), Pair(-13, 92), Pair(-14, 68), Pair(-29, 93), Pair(-22, 76),
        Pair(-14, 65), Pair(-12, 69), Pair(3, 67), Pair(-14, 84), Pair(-14, 86), Pair(-10, 93), Pair(-19, 87), Pair(-6, 99),
        Pair(7, 49), Pair(-6, 87), Pair(-6, 68), Pair(-6, 75), Pair(-13, 87), Pair(-1, 86), Pair(-26, 86), Pair(-9, 75),
        Pair(-1, 94), Pair(0, 0), Pair(-3, 78), Pair(5, 83), Pair(-4, 82), Pair(-5, 88), Pair(-7, 83), Pair(-5, 93),
        Pair(-26, 112), Pair(-3, 122), Pair(4, 102), Pair(-9, 74), Pair(-5, 86), Pair(-4, 84), Pair(-4, 89), Pair(-12, 83),
        Pair(11, -25), Pair(-3, 69), Pair(-7, 70), Pair(-2, 83), Pair(3, 81), Pair(-1, 72), Pair(-3, 78), Pair(21, 2)
      },
      { // Piece 2
        Pair(34, 45), Pair(-4, 74), Pair(22, 39), Pair(-16, 61), Pair(-37, 33), Pair(8, 26), Pair(-21, 15), Pair(-58, 77),
        Pair(1, 73), Pair(-7, 57), Pair(1, 75), Pair(38, 27), Pair(12, 39), Pair(20, 27), Pair(-13, 47), Pair(-28, 61),
        Pair(-23, 40), Pair(-8, 79), Pair(15, 41), Pair(-6, 59), Pair(-8, 42), Pair(-8, 61), Pair(1, 25), Pair(-11, 59),
        Pair(-9, 75), Pair(-8, 47), Pair(-4, 69), Pair(-12, 49), Pair(2, 52), Pair(6, 48), Pair(3, 62), Pair(-25, 59),
        Pair(-77, -29), Pair(-9, 68), Pair(-6, 69), Pair(-2, 66), Pair(-6, 62), Pair(-5, 76), Pair(6, 55), Pair(5, 59),
        Pair(-5, 69), Pair(0, 0), Pair(3, 73), Pair(-7, 65), Pair(-4, 82), Pair(-2, 65), Pair(1, 79), Pair(-8, 66),
        Pair(-70, 28), Pair(1, 82), Pair(-16, 50), Pair(-3, 75), Pair(-8, 75), Pair(4, 83), Pair(-8, 67), Pair(0, 85),
        Pair(7, 46), Pair(-12, 77), Pair(-5, 63), Pair(1, 47), Pair(6, 66), Pair(-3, 67), Pair(-16, 57), Pair(-2, 70)
      },
      { // Piece 3
        Pair(-42, 107), Pair(-18, 85), Pair(-41, 114), Pair(-25, 108), Pair(-19, 111), Pair(-7, 103), Pair(-15, 119), Pair(-18, 100),
        Pair(-39, 105), Pair(-56, 91), Pair(-32, 104), Pair(-27, 104), Pair(5, 96), Pair(-35, 107), Pair(-37, 112), Pair(-36, 102),
        Pair(-21, 105), Pair(-38, 101), Pair(-28, 112), Pair(-20, 115), Pair(-29, 115), Pair(-59, 119), Pair(-6, 108), Pair(-40, 122),
        Pair(-10, 104), Pair(-53, 104), Pair(-19, 101), Pair(-10, 98), Pair(-8, 111), Pair(-10, 114), Pair(-8, 108), Pair(-17, 106),
        Pair(-4, 108), Pair(-39, 96), Pair(2, 109), Pair(-13, 113), Pair(-18, 114), Pair(-13, 107), Pair(-16, 105), Pair(-11, 109),
        Pair(-25, 73), Pair(0, 0), Pair(-11, 109), Pair(-7, 122), Pair(-4, 108), Pair(-23, 107), Pair(-48, 118), Pair(-38, 122),
        Pair(-19, 101), Pair(-28, 65), Pair(-19, 108), Pair(0, 106), Pair(-18, 111), Pair(-14, 111), Pair(-18, 107), Pair(7, 88),
        Pair(-17, 90), Pair(-28, 60), Pair(-18, 101), Pair(-11, 100), Pair(-19, 103), Pair(-15, 98), Pair(-8, 96), Pair(-11, 103)
      },
      { // Piece 4
        Pair(-42, 205), Pair(-11, 168), Pair(-47, 171), Pair(-46, 166), Pair(-29, 187), Pair(-80, 234), Pair(-23, 153), Pair(-17, 162),
        Pair(-19, 166), Pair(-8, 147), Pair(-7, 161), Pair(-4, 150), Pair(-19, 151), Pair(25, 127), Pair(-41, 167), Pair(-22, 179),
        Pair(-6, 145), Pair(-11, 152), Pair(5, 144), Pair(-12, 179), Pair(-29, 166), Pair(-41, 198), Pair(1, 163), Pair(-27, 168),
        Pair(4, 153), Pair(-5, 155), Pair(-23, 162), Pair(-1, 156), Pair(-1, 164), Pair(3, 144), Pair(-17, 172), Pair(-9, 142),
        Pair(-35, 204), Pair(2, 147), Pair(4, 161), Pair(-3, 173), Pair(-7, 169), Pair(-7, 167), Pair(5, 144), Pair(-1, 155),
        Pair(-18, 99), Pair(0, 0), Pair(-1, 170), Pair(-3, 187), Pair(3, 170), Pair(-4, 187), Pair(-11, 188), Pair(-11, 158),
        Pair(-9, 170), Pair(5, 127), Pair(3, 166), Pair(10, 168), Pair(8, 172), Pair(12, 170), Pair(10, 178), Pair(19, 178),
        Pair(10, 127), Pair(-8, 139), Pair(3, 150), Pair(3, 156), Pair(5, 166), Pair(-7, 171), Pair(3, 199), Pair(-4, 196)
      },
      { // Piece 5
        Pair(143, 59), Pair(-12, 26), Pair(49, 15), Pair(-6, -12), Pair(161, 16), Pair(-65, 8), Pair(-40, 1), Pair(-23, 9),
        Pair(99, -2), Pair(88, 25), Pair(19, 56), Pair(168, 11), Pair(80, 20), Pair(46, 20), Pair(-97, 25), Pair(-98, 12),
        Pair(-8, 49), Pair(-28, 56), Pair(78, 31), Pair(97, 26), Pair(-92, 50), Pair(-31, 23), Pair(58, -12), Pair(-15, -8),
        Pair(95, 37), Pair(38, 19), Pair(66, 45), Pair(68, 21), Pair(-100, 36), Pair(-61, 15), Pair(-3, 0), Pair(-58, 15),
        Pair(58, 20), Pair(-20, 38), Pair(31, 11), Pair(-8, 46), Pair(-18, 30), Pair(-36, 23), Pair(-3, 9), Pair(-56, 1),
        Pair(38, 18), Pair(0, 0), Pair(-17, 36), Pair(-9, 32), Pair(1, 15), Pair(-10, 16), Pair(-28, 9), Pair(-39, 3),
        Pair(71, -14), Pair(33, -6), Pair(5, 21), Pair(21, 12), Pair(5, 19), Pair(-16, 13), Pair(-13, 11), Pair(-11, -5),
        Pair(79, -34), Pair(48, -22), Pair(54, 12), Pair(13, -6), Pair(5, 3), Pair(0, 3), Pair(-5, -3), Pair(-9, -15)
      }
    }},
    {{ // Bucket 42
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-16, 26), Pair(-40, 14), Pair(-25, -5), Pair(-9, 5), Pair(-12, 33), Pair(-14, 5), Pair(-1, 13), Pair(1, 21),
        Pair(-9, 15), Pair(-12, 30), Pair(-12, 2), Pair(-11, 20), Pair(-5, 11), Pair(3, 5), Pair(9, 1), Pair(-3, 17),
        Pair(-3, 16), Pair(-3, 17), Pair(1, -9), Pair(-5, 19), Pair(8, 13), Pair(8, 11), Pair(-2, 7), Pair(-2, 12),
        Pair(0, 17), Pair(7, 16), Pair(-15, -22), Pair(10, 24), Pair(3, 13), Pair(3, 12), Pair(2, 17), Pair(-2, 15),
        Pair(-6, 10), Pair(3, 19), Pair(-9, -5), Pair(5, 23), Pair(-10, 12), Pair(5, 14), Pair(3, 15), Pair(0, 20),
        Pair(-3, 12), Pair(12, 34), Pair(-9, -23), Pair(12, 31), Pair(-5, 15), Pair(0, 20), Pair(-1, 19), Pair(4, 21),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-3, 74), Pair(-114, 112), Pair(-38, 79), Pair(-30, 56), Pair(38, 95), Pair(-15, 54), Pair(66, 32), Pair(-3, -10),
        Pair(-1, 51), Pair(7, 82), Pair(-29, 75), Pair(-28, 81), Pair(-9, 63), Pair(-23, 82), Pair(-12, 73), Pair(-23, 58),
        Pair(3, 61), Pair(0, 65), Pair(-13, 78), Pair(-3, 88), Pair(-9, 83), Pair(17, 82), Pair(-1, 72), Pair(-17, 71),
        Pair(-11, 78), Pair(-1, 68), Pair(5, 68), Pair(23, 60), Pair(0, 68), Pair(2, 78), Pair(2, 72), Pair(-7, 78),
        Pair(-17, 58), Pair(42, 86), Pair(10, 67), Pair(13, 75), Pair(0, 63), Pair(2, 77), Pair(-6, 69), Pair(8, 67),
        Pair(15, 57), Pair(8, 88), Pair(0, 0), Pair(11, 78), Pair(21, 73), Pair(8, 72), Pair(12, 65), Pair(16, 63),
        Pair(7, 26), Pair(-1, 85), Pair(12, 105), Pair(15, 88), Pair(1, 55), Pair(17, 72), Pair(3, 89), Pair(7, 85),
        Pair(-10, 68), Pair(7, 35), Pair(12, 56), Pair(18, 68), Pair(7, 65), Pair(12, 73), Pair(12, 49), Pair(21, 35)
      },
      { // Piece 2
        Pair(20, 60), Pair(23, 22), Pair(46, 46), Pair(87, 10), Pair(8, 42), Pair(-13, 8), Pair(34, 20), Pair(1, -24),
        Pair(5, 35), Pair(3, 55), Pair(19, 31), Pair(35, 30), Pair(10, 22), Pair(29, 40), Pair(-45, 4), Pair(25, 34),
        Pair(20, 57), Pair(10, 45), Pair(26, 49), Pair(18, 37), Pair(22, 61), Pair(2, 26), Pair(33, 34), Pair(5, 17),
        Pair(-1, 11), Pair(16, 41), Pair(-2, 42), Pair(25, 59), Pair(11, 11), Pair(33, 29), Pair(9, 29), Pair(23, 63),
        Pair(30, 64), Pair(27, 1), Pair(13, 46), Pair(44, 35), Pair(15, 39), Pair(9, 41), Pair(20, 63), Pair(8, 47),
        Pair(-1, 30), Pair(16, 67), Pair(0, 0), Pair(24, 53), Pair(6, 46), Pair(28, 51), Pair(17, 41), Pair(17, 69),
        Pair(27, 17), Pair(-22, -33), Pair(32, 73), Pair(-1, 29), Pair(19, 66), Pair(8, 56), Pair(15, 69), Pair(11, 60),
        Pair(-32, -79), Pair(9, 25), Pair(3, 37), Pair(42, 48), Pair(-14, 15), Pair(20, 70), Pair(29, 49), Pair(12, 59)
      },
      { // Piece 3
        Pair(-36, 111), Pair(-24, 95), Pair(12, 72), Pair(-4, 96), Pair(-23, 118), Pair(-26, 98), Pair(-4, 84), Pair(-21, 101),
        Pair(-19, 102), Pair(-6, 83), Pair(-17, 75), Pair(1, 82), Pair(-3, 88), Pair(-11, 85), Pair(-25, 106), Pair(-2, 94),
        Pair(-25, 109), Pair(-13, 90), Pair(-18, 77), Pair(-16, 99), Pair(-8, 101), Pair(-38, 103), Pair(27, 79), Pair(-2, 82),
        Pair(11, 92), Pair(3, 77), Pair(-4, 82), Pair(-4, 95), Pair(10, 81), Pair(-7, 106), Pair(-18, 85), Pair(-12, 95),
        Pair(3, 102), Pair(14, 83), Pair(-19, 92), Pair(5, 108), Pair(-1, 91), Pair(-2, 87), Pair(-17, 104), Pair(-9, 100),
        Pair(-4, 50), Pair(-4, 61), Pair(0, 0), Pair(-4, 83), Pair(12, 79), Pair(2, 83), Pair(1, 77), Pair(7, 74),
        Pair(-5, 113), Pair(-12, 109), Pair(-16, 60), Pair(-12, 104), Pair(12, 85), Pair(2, 84), Pair(12, 81), Pair(-8, 113),
        Pair(2, 90), Pair(-4, 94), Pair(-2, 45), Pair(-1, 88), Pair(3, 89), Pair(3, 84), Pair(6, 92), Pair(5, 94)
      },
      { // Piece 4
        Pair(4, 137), Pair(-9, 184), Pair(-20, 139), Pair(-57, 188), Pair(-33, 171), Pair(31, 146), Pair(-27, 174), Pair(40, 130),
        Pair(0, 127), Pair(7, 136), Pair(-31, 153), Pair(-6, 140), Pair(4, 138), Pair(21, 155), Pair(18, 114), Pair(-19, 153),
        Pair(-19, 133), Pair(5, 148), Pair(0, 134), Pair(10, 155), Pair(-12, 166), Pair(-15, 144), Pair(-2, 152), Pair(-7, 160),
        Pair(-7, 132), Pair(6, 150), Pair(19, 113), Pair(5, 161), Pair(11, 125), Pair(-5, 140), Pair(0, 163), Pair(-6, 166),
        Pair(2, 171), Pair(6, 137), Pair(12, 126), Pair(11, 143), Pair(-3, 162), Pair(-6, 160), Pair(4, 165), Pair(7, 153),
        Pair(-12, 109), Pair(6, 98), Pair(0, 0), Pair(11, 150), Pair(18, 140), Pair(8, 150), Pair(3, 180), Pair(-7, 186),
        Pair(15, 121), Pair(6, 130), Pair(6, 134), Pair(13, 140), Pair(14, 157), Pair(16, 153), Pair(18, 149), Pair(9, 170),
        Pair(15, 94), Pair(11, 157), Pair(17, 119), Pair(8, 159), Pair(15, 138), Pair(30, 128), Pair(47, 80), Pair(3, 117)
      },
      { // Piece 5
        Pair(-98, -73), Pair(39, 87), Pair(-107, 100), Pair(-316, 30), Pair(76, -20), Pair(-19, -13), Pair(38, -61), Pair(114, -54),
        Pair(98, 23), Pair(89, 70), Pair(66, -2), Pair(-31, 50), Pair(-7, 16), Pair(14, 37), Pair(80, -1), Pair(115, -47),
        Pair(-107, 67), Pair(57, 54), Pair(-26, 57), Pair(-34, 44), Pair(42, 21), Pair(-147, 35), Pair(98, -25), Pair(-11, -21),
        Pair(96, -11), Pair(-1, 49), Pair(120, 13), Pair(66, 29), Pair(47, 17), Pair(-18, 15), Pair(15, -11), Pair(-56, 13),
        Pair(72, 13), Pair(-59, 3), Pair(0, 20), Pair(-58, 20), Pair(-50, 24), Pair(-7, 4), Pair(3, -10), Pair(-33, 3),
        Pair(56, 8), Pair(6, 26), Pair(0, 0), Pair(0, 23), Pair(9, 8), Pair(-2, -1), Pair(-16, -1), Pair(-12, -17),
        Pair(54, -9), Pair(25, -2), Pair(-2, 17), Pair(-5, 10), Pair(1, -4), Pair(9, -13), Pair(-1, -15), Pair(-4, -16),
        Pair(49, -54), Pair(-8, -7), Pair(9, -6), Pair(13, -6), Pair(13, -5), Pair(-10, -13), Pair(1, -21), Pair(-4, -32)
      }
    }},
    {{ // Bucket 43
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-5, 11), Pair(-38, 19), Pair(-39, 18), Pair(-21, 9), Pair(1, 0), Pair(34, -10), Pair(12, -1), Pair(11, 4),
        Pair(-6, 7), Pair(-13, 17), Pair(-12, 19), Pair(-4, 7), Pair(-17, 18), Pair(0, 5), Pair(-12, 15), Pair(-3, -3),
        Pair(-4, 13), Pair(2, 17), Pair(-5, 24), Pair(10, 5), Pair(3, 18), Pair(10, 13), Pair(-5, 17), Pair(-2, 14),
        Pair(0, 13), Pair(-3, 18), Pair(6, 25), Pair(9, -9), Pair(11, 17), Pair(5, 11), Pair(1, 15), Pair(-3, 15),
        Pair(-3, 14), Pair(-5, 15), Pair(4, 24), Pair(-2, -17), Pair(5, 23), Pair(-8, 11), Pair(1, 17), Pair(-2, 15),
        Pair(-2, 12), Pair(-10, 10), Pair(12, 39), Pair(10, -30), Pair(15, 42), Pair(-5, 21), Pair(-4, 13), Pair(2, 20),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(62, 46), Pair(-24, 54), Pair(-76, 81), Pair(-32, 48), Pair(24, 29), Pair(-90, 80), Pair(-75, 142), Pair(-81, 104),
        Pair(-22, 53), Pair(-9, 72), Pair(-6, 58), Pair(-67, 83), Pair(-80, 89), Pair(-43, 68), Pair(25, 56), Pair(8, 25),
        Pair(-26, 52), Pair(-31, 63), Pair(-11, 63), Pair(-44, 88), Pair(-38, 78), Pair(-45, 100), Pair(-32, 61), Pair(-30, 88),
        Pair(-10, 83), Pair(-13, 69), Pair(-6, 49), Pair(-30, 79), Pair(-13, 60), Pair(-10, 69), Pair(-19, 76), Pair(-35, 76),
        Pair(-9, 45), Pair(-7, 63), Pair(-8, 71), Pair(-10, 60), Pair(13, 67), Pair(-7, 61), Pair(-28, 70), Pair(-14, 63),
        Pair(3, 43), Pair(5, 51), Pair(-10, 68), Pair(0, 0), Pair(1, 61), Pair(0, 77), Pair(-17, 87), Pair(3, 63),
        Pair(-6, 50), Pair(-7, 15), Pair(0, 67), Pair(-3, 97), Pair(0, 71), Pair(-17, 48), Pair(-2, 63), Pair(-5, 60),
        Pair(52, 39), Pair(-1, 61), Pair(-26, 60), Pair(-4, 42), Pair(-4, 47), Pair(-4, 81), Pair(12, 77), Pair(-18, 26)
      },
      { // Piece 2
        Pair(-2, 33), Pair(-4, 34), Pair(18, 40), Pair(-25, 34), Pair(43, -7), Pair(38, 24), Pair(38, 15), Pair(-97, 75),
        Pair(12, 37), Pair(-8, 48), Pair(-4, 41), Pair(33, 22), Pair(16, 37), Pair(-1, 11), Pair(-24, 27), Pair(9, -5),
        Pair(-7, 11), Pair(-11, 50), Pair(2, 30), Pair(-8, 44), Pair(-12, 36), Pair(6, 37), Pair(0, 10), Pair(-24, 58),
        Pair(-2, 46), Pair(-29, 15), Pair(4, 43), Pair(-13, 29), Pair(-2, 52), Pair(0, 1), Pair(-3, 43), Pair(-11, 27),
        Pair(4, 8), Pair(14, 40), Pair(-19, 37), Pair(-6, 44), Pair(36, 48), Pair(0, 48), Pair(-9, 42), Pair(-17, 41),
        Pair(1, 50), Pair(-15, 34), Pair(1, 61), Pair(0, 0), Pair(-3, 63), Pair(-8, 38), Pair(-5, 61), Pair(-6, 21),
        Pair(1, 70), Pair(-10, 63), Pair(-30, -12), Pair(14, 68), Pair(-10, 4), Pair(0, 65), Pair(-12, 43), Pair(-4, 65),
        Pair(-1, 55), Pair(-42, -35), Pair(0, 57), Pair(-2, 25), Pair(-4, 55), Pair(-15, -12), Pair(2, 25), Pair(-3, 34)
      },
      { // Piece 3
        Pair(-42, 89), Pair(-10, 77), Pair(-38, 85), Pair(51, 57), Pair(-14, 80), Pair(-104, 124), Pair(-28, 81), Pair(-31, 101),
        Pair(-21, 84), Pair(-20, 87), Pair(-39, 85), Pair(-7, 72), Pair(-35, 95), Pair(7, 79), Pair(-37, 81), Pair(-19, 91),
        Pair(-27, 100), Pair(-12, 74), Pair(-31, 99), Pair(-19, 64), Pair(-45, 102), Pair(-48, 98), Pair(-51, 103), Pair(-27, 83),
        Pair(-7, 77), Pair(1, 74), Pair(-16, 84), Pair(-14, 82), Pair(-29, 85), Pair(8, 84), Pair(-14, 78), Pair(12, 95),
        Pair(-14, 91), Pair(-7, 79), Pair(-11, 94), Pair(5, 68), Pair(-4, 88), Pair(-10, 86), Pair(-19, 88), Pair(-7, 82),
        Pair(-5, 54), Pair(-23, 68), Pair(-5, 67), Pair(0, 0), Pair(-13, 72), Pair(-4, 48), Pair(-30, 87), Pair(-12, 77),
        Pair(-21, 89), Pair(-7, 88), Pair(-18, 76), Pair(-15, 52), Pair(-2, 74), Pair(-9, 70), Pair(-22, 62), Pair(13, 77),
        Pair(-8, 72), Pair(-8, 82), Pair(-14, 85), Pair(-7, 27), Pair(-15, 74), Pair(-11, 74), Pair(-10, 91), Pair(-2, 76)
      },
      { // Piece 4
        Pair(-16, 137), Pair(23, 121), Pair(-41, 149), Pair(-37, 133), Pair(-29, 144), Pair(22, 118), Pair(6, 106), Pair(-15, 135),
        Pair(-17, 149), Pair(-26, 136), Pair(-26, 150), Pair(-18, 149), Pair(-43, 148), Pair(-50, 178), Pair(-37, 135), Pair(-24, 143),
        Pair(-28, 133), Pair(-12, 130), Pair(-14, 120), Pair(-17, 121), Pair(-25, 140), Pair(-10, 123), Pair(-34, 177), Pair(-31, 153),
        Pair(2, 120), Pair(-12, 126), Pair(-13, 121), Pair(-10, 115), Pair(-4, 125), Pair(12, 89), Pair(-6, 120), Pair(-18, 133),
        Pair(5, 112), Pair(1, 124), Pair(-16, 119), Pair(-10, 115), Pair(0, 138), Pair(-11, 150), Pair(-7, 123), Pair(-6, 132),
        Pair(-4, 77), Pair(3, 77), Pair(-8, 115), Pair(0, 0), Pair(4, 105), Pair(0, 121), Pair(0, 126), Pair(-3, 115),
        Pair(18, 129), Pair(11, 100), Pair(-1, 99), Pair(5, 99), Pair(-3, 125), Pair(12, 124), Pair(12, 114), Pair(7, 165),
        Pair(11, 85), Pair(4, 109), Pair(7, 130), Pair(4, 88), Pair(3, 137), Pair(17, 84), Pair(7, 229), Pair(16, 113)
      },
      { // Piece 5
        Pair(-9, -46), Pair(97, 102), Pair(25, 29), Pair(74, 51), Pair(66, -22), Pair(9, -13), Pair(48, -88), Pair(12, -100),
        Pair(62, 49), Pair(-122, 42), Pair(-21, 55), Pair(-40, 80), Pair(-79, 75), Pair(67, 1), Pair(144, -8), Pair(-101, -40),
        Pair(-76, -2), Pair(35, 12), Pair(-58, 30), Pair(-140, 90), Pair(136, 12), Pair(93, -4), Pair(-58, 2), Pair(-17, 10),
        Pair(-128, 34), Pair(137, -11), Pair(-24, 24), Pair(-36, 31), Pair(-2, 22), Pair(1, -6), Pair(-75, 5), Pair(-17, -27),
        Pair(20, -16), Pair(-2, 15), Pair(-52, -10), Pair(-16, 19), Pair(5, -25), Pair(30, -7), Pair(38, -23), Pair(14, -2),
        Pair(17, 1), Pair(-10, 2), Pair(-38, 25), Pair(0, 0), Pair(-63, 29), Pair(-16, -4), Pair(10, -25), Pair(-20, -9),
        Pair(-24, -1), Pair(-24, -8), Pair(-46, 20), Pair(-27, 24), Pair(-42, 0), Pair(1, -24), Pair(-3, -17), Pair(-1, -24),
        Pair(-10, -65), Pair(-11, -16), Pair(-36, 11), Pair(-28, 1), Pair(-17, -2), Pair(1, -17), Pair(-2, -29), Pair(-2, -29)
      }
    }},
    {{ // Bucket 44
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(11, 4), Pair(6, 14), Pair(2, 8), Pair(-13, 15), Pair(-6, -8), Pair(-31, 25), Pair(-24, 12), Pair(23, 14),
        Pair(-6, 17), Pair(-8, 14), Pair(2, 7), Pair(-10, 19), Pair(5, 2), Pair(-27, 20), Pair(-9, 15), Pair(-6, 7),
        Pair(-1, 14), Pair(-1, 11), Pair(-2, 16), Pair(-1, 21), Pair(5, 11), Pair(-3, 20), Pair(1, 13), Pair(2, 7),
        Pair(-3, 22), Pair(-1, 19), Pair(1, 15), Pair(10, 28), Pair(2, -5), Pair(17, 13), Pair(-2, 18), Pair(0, 6),
        Pair(2, 16), Pair(-2, 18), Pair(-10, 10), Pair(7, 27), Pair(4, -21), Pair(16, 20), Pair(-5, 9), Pair(6, 14),
        Pair(-3, 20), Pair(-4, 16), Pair(-4, 18), Pair(21, 41), Pair(10, -16), Pair(18, 37), Pair(1, 9), Pair(7, 14),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-20, 54), Pair(19, 32), Pair(-43, 90), Pair(-11, 65), Pair(-69, 90), Pair(-40, 69), Pair(162, -39), Pair(-31, -4),
        Pair(-3, 47), Pair(-3, 79), Pair(-5, 55), Pair(-56, 77), Pair(-71, 99), Pair(-29, 57), Pair(-12, 53), Pair(-74, 51),
        Pair(27, 44), Pair(-18, 67), Pair(-14, 60), Pair(-25, 75), Pair(-32, 76), Pair(-6, 61), Pair(-48, 70), Pair(-83, 74),
        Pair(-10, 58), Pair(-7, 61), Pair(-4, 68), Pair(-17, 53), Pair(-25, 63), Pair(-31, 54), Pair(-20, 58), Pair(-34, 70),
        Pair(-3, 62), Pair(-4, 63), Pair(-8, 49), Pair(9, 70), Pair(-21, 71), Pair(-11, 65), Pair(-31, 50), Pair(-20, 53),
        Pair(-8, 61), Pair(2, 70), Pair(-4, 69), Pair(3, 62), Pair(0, 0), Pair(-9, 65), Pair(-6, 69), Pair(-8, 55),
        Pair(11, 52), Pair(0, 50), Pair(-25, 44), Pair(3, 72), Pair(-2, 93), Pair(13, 61), Pair(-17, 12), Pair(-15, 60),
        Pair(-2, 53), Pair(9, 63), Pair(-2, 59), Pair(0, 60), Pair(-9, 59), Pair(-11, 48), Pair(-2, 51), Pair(-1, 35)
      },
      { // Piece 2
        Pair(-18, 50), Pair(45, -11), Pair(64, 28), Pair(38, -2), Pair(87, 12), Pair(16, 21), Pair(-8, 17), Pair(-5, 28),
        Pair(-38, 16), Pair(-3, 36), Pair(-3, 15), Pair(33, 29), Pair(-7, 13), Pair(-12, 34), Pair(-17, 17), Pair(-7, 41),
        Pair(10, 43), Pair(-11, 18), Pair(15, 31), Pair(-6, 24), Pair(7, 44), Pair(-33, 41), Pair(-16, 34), Pair(-52, 7),
        Pair(7, 17), Pair(6, 28), Pair(-31, 25), Pair(3, 37), Pair(-19, 19), Pair(1, 32), Pair(-20, 12), Pair(-8, 30),
        Pair(-8, 41), Pair(-10, 25), Pair(-5, 42), Pair(18, 19), Pair(-9, 41), Pair(-26, 1), Pair(9, 42), Pair(-26, 39),
        Pair(-20, 33), Pair(0, 47), Pair(-17, 25), Pair(-1, 50), Pair(0, 0), Pair(1, 44), Pair(-21, 38), Pair(-8, 51),
        Pair(7, 48), Pair(-24, 34), Pair(-5, 45), Pair(-28, 9), Pair(12, 64), Pair(-45, 16), Pair(-5, 58), Pair(-9, 25),
        Pair(-14, 38), Pair(-12, 56), Pair(-38, -7), Pair(13, 39), Pair(-12, 32), Pair(7, 36), Pair(-40, -14), Pair(19, 40)
      },
      { // Piece 3
        Pair(-14, 76), Pair(5, 69), Pair(-39, 79), Pair(-38, 86), Pair(-52, 60), Pair(-63, 90), Pair(25, 70), Pair(23, 64),
        Pair(-15, 80), Pair(-28, 82), Pair(-13, 78), Pair(-8, 67), Pair(-15, 59), Pair(-29, 77), Pair(-23, 77), Pair(-21, 68),
        Pair(-12, 82), Pair(3, 73), Pair(-13, 82), Pair(-26, 81), Pair(-38, 71), Pair(-60, 83), Pair(-5, 79), Pair(-21, 77),
        Pair(-8, 75), Pair(5, 68), Pair(6, 75), Pair(1, 64), Pair(11, 58), Pair(-4, 63), Pair(-30, 93), Pair(-12, 65),
        Pair(1, 70), Pair(-3, 71), Pair(0, 68), Pair(12, 75), Pair(-9, 53), Pair(-7, 74), Pair(-34, 82), Pair(-7, 73),
        Pair(-4, 60), Pair(-2, 59), Pair(-3, 60), Pair(-7, 55), Pair(0, 0), Pair(-27, 37), Pair(-17, 46), Pair(-9, 37),
        Pair(-5, 66), Pair(-10, 79), Pair(-1, 69), Pair(-7, 72), Pair(-9, 28), Pair(-18, 65), Pair(-17, 67), Pair(7, 64),
        Pair(-4, 68), Pair(-6, 67), Pair(-2, 70), Pair(-9, 68), Pair(-13, 18), Pair(-15, 64), Pair(-10, 68), Pair(-6, 68)
      },
      { // Piece 4
        Pair(-31, 142), Pair(-25, 138), Pair(-37, 140), Pair(-6, 124), Pair(46, 67), Pair(37, 121), Pair(-58, 158), Pair(-34, 151),
        Pair(-16, 138), Pair(-23, 136), Pair(-18, 126), Pair(5, 136), Pair(9, 84), Pair(8, 113), Pair(-30, 109), Pair(-19, 138),
        Pair(-17, 137), Pair(-9, 102), Pair(-8, 142), Pair(-5, 127), Pair(-26, 106), Pair(-43, 139), Pair(-11, 124), Pair(-39, 109),
        Pair(-10, 137), Pair(-4, 104), Pair(6, 82), Pair(-13, 125), Pair(-7, 104), Pair(-34, 122), Pair(-31, 142), Pair(-20, 106),
        Pair(4, 125), Pair(1, 122), Pair(2, 100), Pair(1, 110), Pair(-4, 93), Pair(-35, 127), Pair(-13, 115), Pair(-22, 130),
        Pair(14, 93), Pair(5, 99), Pair(10, 80), Pair(4, 92), Pair(0, 0), Pair(-7, 114), Pair(-22, 124), Pair(-20, 94),
        Pair(2, 122), Pair(11, 104), Pair(8, 114), Pair(-2, 104), Pair(3, 100), Pair(-3, 111), Pair(29, 81), Pair(10, 146),
        Pair(10, 105), Pair(12, 126), Pair(7, 101), Pair(2, 118), Pair(1, 81), Pair(7, 118), Pair(-11, 119), Pair(1, 142)
      },
      { // Piece 5
        Pair(132, 8), Pair(-123, 13), Pair(-22, -3), Pair(21, 22), Pair(-91, 11), Pair(-81, 63), Pair(-29, 87), Pair(52, -31),
        Pair(-78, 0), Pair(-120, 59), Pair(-125, 19), Pair(-95, 50), Pair(98, 27), Pair(15, 61), Pair(-103, 19), Pair(-88, 31),
        Pair(-50, 19), Pair(-14, 10), Pair(-50, 42), Pair(118, 5), Pair(14, 58), Pair(-8, 42), Pair(-82, 36), Pair(124, -27),
        Pair(51, -15), Pair(-119, 20), Pair(21, 7), Pair(-36, 35), Pair(15, 28), Pair(-25, 31), Pair(37, -7), Pair(-13, 11),
        Pair(-23, -18), Pair(-36, 7), Pair(7, 5), Pair(-26, 3), Pair(7, 9), Pair(-11, -16), Pair(23, -4), Pair(-9, -7),
        Pair(-42, 10), Pair(14, -4), Pair(-23, 12), Pair(-54, 25), Pair(0, 0), Pair(-25, 4), Pair(9, -7), Pair(11, -14),
        Pair(13, -23), Pair(-19, 4), Pair(-7, -2), Pair(-18, 3), Pair(-25, 16), Pair(-30, 2), Pair(5, -19), Pair(7, -14),
        Pair(8, -44), Pair(-1, -35), Pair(-3, -20), Pair(1, -15), Pair(-20, -1), Pair(-35, -4), Pair(3, -20), Pair(-1, -32)
      }
    }},
    {{ // Bucket 45
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(10, 10), Pair(-35, 20), Pair(-4, 13), Pair(14, 5), Pair(-31, 21), Pair(-37, 7), Pair(0, 30), Pair(24, 13),
        Pair(2, 21), Pair(1, 22), Pair(-6, 20), Pair(-2, 14), Pair(-13, 21), Pair(6, 0), Pair(-10, 26), Pair(-5, 9),
        Pair(3, 18), Pair(5, 15), Pair(3, 14), Pair(1, 14), Pair(-2, 20), Pair(5, 5), Pair(10, 13), Pair(4, 8),
        Pair(-2, 20), Pair(7, 16), Pair(3, 14), Pair(6, 16), Pair(20, 19), Pair(-1, -6), Pair(24, 10), Pair(10, 3),
        Pair(2, 16), Pair(6, 21), Pair(2, 18), Pair(-8, 10), Pair(15, 21), Pair(3, -5), Pair(18, 10), Pair(-2, 7),
        Pair(3, 19), Pair(5, 18), Pair(2, 15), Pair(-3, 17), Pair(18, 29), Pair(7, -6), Pair(17, 26), Pair(2, 9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(34, 38), Pair(18, 29), Pair(-4, 62), Pair(69, 60), Pair(57, 81), Pair(138, 32), Pair(8, 77), Pair(-158, 95),
        Pair(23, 72), Pair(0, 76), Pair(35, 60), Pair(10, 61), Pair(27, 63), Pair(44, 33), Pair(17, 68), Pair(-52, 58),
        Pair(38, 66), Pair(34, 54), Pair(41, 64), Pair(10, 74), Pair(7, 74), Pair(-30, 78), Pair(15, 66), Pair(-13, 79),
        Pair(18, 59), Pair(29, 61), Pair(24, 75), Pair(6, 75), Pair(23, 57), Pair(10, 68), Pair(4, 75), Pair(-22, 79),
        Pair(27, 77), Pair(48, 70), Pair(36, 68), Pair(28, 65), Pair(43, 67), Pair(15, 71), Pair(18, 64), Pair(-3, 52),
        Pair(42, 39), Pair(44, 63), Pair(26, 69), Pair(40, 65), Pair(35, 69), Pair(0, 0), Pair(12, 75), Pair(16, 70),
        Pair(29, 63), Pair(21, 71), Pair(39, 65), Pair(18, 59), Pair(32, 67), Pair(31, 71), Pair(37, 73), Pair(18, 30),
        Pair(9, 88), Pair(19, 69), Pair(77, 44), Pair(19, 72), Pair(29, 55), Pair(20, 65), Pair(12, 51), Pair(49, 53)
      },
      { // Piece 2
        Pair(30, -11), Pair(7, 59), Pair(19, 39), Pair(86, 25), Pair(49, 32), Pair(91, 29), Pair(84, 8), Pair(62, 29),
        Pair(28, 46), Pair(11, 13), Pair(50, 31), Pair(33, 3), Pair(51, 31), Pair(16, 38), Pair(57, 27), Pair(17, 15),
        Pair(32, 19), Pair(40, 36), Pair(31, 16), Pair(39, 36), Pair(24, 22), Pair(14, 38), Pair(9, 40), Pair(20, 34),
        Pair(45, 46), Pair(31, 30), Pair(35, 41), Pair(2, 29), Pair(38, 49), Pair(-1, 27), Pair(38, 44), Pair(-72, 46),
        Pair(28, 38), Pair(62, 32), Pair(12, 33), Pair(37, 44), Pair(56, 43), Pair(25, 42), Pair(16, 62), Pair(22, 64),
        Pair(40, 50), Pair(13, 45), Pair(40, 51), Pair(16, 43), Pair(40, 54), Pair(0, 0), Pair(30, 47), Pair(6, 43),
        Pair(19, 34), Pair(33, 54), Pair(26, 36), Pair(34, 55), Pair(20, 24), Pair(45, 65), Pair(-18, -4), Pair(27, 50),
        Pair(30, 34), Pair(20, 35), Pair(32, 68), Pair(-4, 49), Pair(43, 48), Pair(16, 36), Pair(27, 35), Pair(-35, -41)
      },
      { // Piece 3
        Pair(45, 71), Pair(67, 64), Pair(41, 64), Pair(60, 68), Pair(5, 82), Pair(54, 61), Pair(0, 86), Pair(7, 82),
        Pair(19, 80), Pair(27, 83), Pair(31, 75), Pair(49, 69), Pair(31, 70), Pair(22, 52), Pair(42, 87), Pair(30, 77),
        Pair(27, 84), Pair(29, 82), Pair(38, 80), Pair(24, 86), Pair(38, 75), Pair(-25, 85), Pair(67, 61), Pair(29, 86),
        Pair(34, 78), Pair(42, 83), Pair(43, 72), Pair(47, 74), Pair(35, 84), Pair(23, 74), Pair(21, 73), Pair(22, 86),
        Pair(48, 78), Pair(19, 87), Pair(31, 73), Pair(35, 84), Pair(48, 95), Pair(10, 75), Pair(8, 115), Pair(20, 86),
        Pair(34, 72), Pair(33, 73), Pair(51, 59), Pair(33, 72), Pair(33, 75), Pair(0, 0), Pair(25, 40), Pair(27, 31),
        Pair(34, 83), Pair(51, 63), Pair(36, 82), Pair(41, 84), Pair(33, 80), Pair(30, 34), Pair(33, 49), Pair(14, 100),
        Pair(35, 74), Pair(37, 77), Pair(42, 76), Pair(40, 76), Pair(27, 82), Pair(24, 40), Pair(23, 83), Pair(33, 72)
      },
      { // Piece 4
        Pair(5, 163), Pair(15, 155), Pair(59, 135), Pair(7, 177), Pair(16, 152), Pair(14, 159), Pair(68, 135), Pair(-11, 164),
        Pair(-9, 179), Pair(14, 141), Pair(-16, 200), Pair(20, 146), Pair(-6, 176), Pair(59, 74), Pair(-26, 193), Pair(-10, 156),
        Pair(27, 152), Pair(28, 154), Pair(15, 141), Pair(12, 160), Pair(-9, 153), Pair(-48, 163), Pair(41, 137), Pair(-22, 183),
        Pair(23, 159), Pair(24, 161), Pair(12, 161), Pair(2, 160), Pair(12, 169), Pair(17, 125), Pair(15, 139), Pair(-37, 163),
        Pair(26, 152), Pair(34, 157), Pair(26, 145), Pair(3, 166), Pair(34, 144), Pair(9, 141), Pair(10, 145), Pair(-4, 171),
        Pair(22, 177), Pair(32, 163), Pair(43, 132), Pair(32, 145), Pair(33, 139), Pair(0, 0), Pair(4, 135), Pair(15, 129),
        Pair(41, 162), Pair(31, 173), Pair(39, 146), Pair(36, 143), Pair(37, 120), Pair(32, 112), Pair(19, 119), Pair(54, 123),
        Pair(34, 154), Pair(36, 171), Pair(43, 145), Pair(32, 155), Pair(23, 168), Pair(32, 118), Pair(29, 195), Pair(30, 108)
      },
      { // Piece 5
        Pair(19, -91), Pair(-72, 63), Pair(242, -34), Pair(83, 3), Pair(71, -20), Pair(190, -59), Pair(-69, 28), Pair(93, 3),
        Pair(-26, -38), Pair(-61, 20), Pair(187, -41), Pair(157, -3), Pair(116, 26), Pair(141, 26), Pair(45, 25), Pair(-301, 87),
        Pair(-52, -13), Pair(-21, 10), Pair(-75, 4), Pair(-81, 56), Pair(157, 17), Pair(108, 30), Pair(12, 26), Pair(25, 17),
        Pair(-71, 6), Pair(-39, 3), Pair(-87, 26), Pair(-69, 43), Pair(-31, 35), Pair(29, 15), Pair(29, 21), Pair(33, -3),
        Pair(-95, 20), Pair(-30, 9), Pair(-38, 18), Pair(-60, 22), Pair(-86, 14), Pair(15, -3), Pair(-11, -7), Pair(45, -7),
        Pair(-53, -3), Pair(-30, -3), Pair(-37, 12), Pair(-25, 14), Pair(-10, 10), Pair(0, 0), Pair(21, -12), Pair(36, -7),
        Pair(-34, 0), Pair(5, -7), Pair(27, -5), Pair(28, -6), Pair(-22, 10), Pair(-35, 9), Pair(-2, 0), Pair(19, -8),
        Pair(-6, 4), Pair(-4, -17), Pair(-5, -11), Pair(12, -22), Pair(-11, 5), Pair(-17, -3), Pair(-10, 5), Pair(25, -24)
      }
    }},
    {{ // Bucket 46
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-21, 18), Pair(-8, 17), Pair(0, 3), Pair(-5, 15), Pair(-3, 4), Pair(-22, 6), Pair(2, -17), Pair(-25, 19),
        Pair(-8, 21), Pair(1, 17), Pair(5, 13), Pair(3, 13), Pair(-10, 16), Pair(-4, 12), Pair(2, -4), Pair(-1, 16),
        Pair(-3, 17), Pair(1, 13), Pair(2, 11), Pair(-1, 8), Pair(3, 15), Pair(-7, 13), Pair(17, -5), Pair(0, 15),
        Pair(1, 17), Pair(2, 20), Pair(3, 17), Pair(2, 12), Pair(9, 16), Pair(19, 13), Pair(14, -16), Pair(13, 1),
        Pair(-1, 23), Pair(2, 23), Pair(2, 12), Pair(3, 17), Pair(-2, 12), Pair(19, 11), Pair(-1, 3), Pair(4, 9),
        Pair(-3, 20), Pair(1, 25), Pair(1, 19), Pair(5, 15), Pair(4, 16), Pair(20, 27), Pair(-4, -10), Pair(7, 25),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(8, 54), Pair(52, 31), Pair(93, 70), Pair(109, 14), Pair(-8, 83), Pair(10, 65), Pair(-26, 76), Pair(-50, 24),
        Pair(-4, 62), Pair(18, 49), Pair(2, 65), Pair(-2, 62), Pair(8, 64), Pair(-14, 59), Pair(-26, 54), Pair(-22, 54),
        Pair(22, 51), Pair(0, 68), Pair(5, 57), Pair(-2, 64), Pair(-4, 60), Pair(20, 59), Pair(-15, 70), Pair(3, 75),
        Pair(10, 43), Pair(15, 60), Pair(13, 66), Pair(3, 68), Pair(-6, 67), Pair(-10, 60), Pair(6, 61), Pair(-31, 59),
        Pair(14, 61), Pair(25, 61), Pair(7, 72), Pair(3, 63), Pair(6, 55), Pair(2, 56), Pair(-5, 66), Pair(7, 29),
        Pair(21, 48), Pair(11, 65), Pair(9, 63), Pair(8, 65), Pair(11, 67), Pair(9, 60), Pair(0, 0), Pair(9, 62),
        Pair(-9, 30), Pair(-4, 67), Pair(10, 67), Pair(8, 67), Pair(-10, 54), Pair(16, 61), Pair(5, 80), Pair(-9, 68),
        Pair(-17, 83), Pair(13, 65), Pair(16, 54), Pair(2, 84), Pair(8, 61), Pair(2, 51), Pair(9, 52), Pair(11, 18)
      },
      { // Piece 2
        Pair(8, 36), Pair(9, -3), Pair(88, 27), Pair(107, 0), Pair(57, 22), Pair(25, 40), Pair(-28, 60), Pair(-8, 38),
        Pair(-2, 24), Pair(14, 43), Pair(-11, 20), Pair(49, 21), Pair(51, 12), Pair(35, 36), Pair(5, 39), Pair(5, 54),
        Pair(30, 39), Pair(19, 30), Pair(28, 39), Pair(-11, 24), Pair(1, 54), Pair(-11, 36), Pair(-14, 49), Pair(-13, 33),
        Pair(9, 41), Pair(22, 50), Pair(17, 27), Pair(17, 49), Pair(-13, 43), Pair(6, 50), Pair(2, 28), Pair(-1, 51),
        Pair(1, 58), Pair(6, 30), Pair(16, 51), Pair(7, 35), Pair(13, 52), Pair(-12, 37), Pair(15, 52), Pair(-64, -18),
        Pair(2, 38), Pair(6, 55), Pair(1, 36), Pair(9, 61), Pair(1, 48), Pair(19, 45), Pair(0, 0), Pair(12, 46),
        Pair(0, 34), Pair(1, 41), Pair(7, 52), Pair(3, 50), Pair(16, 60), Pair(10, 25), Pair(21, 67), Pair(-66, -54),
        Pair(2, 52), Pair(2, 67), Pair(6, 42), Pair(9, 62), Pair(2, 35), Pair(17, 45), Pair(28, 15), Pair(18, 29)
      },
      { // Piece 3
        Pair(23, 75), Pair(41, 72), Pair(45, 73), Pair(42, 75), Pair(21, 83), Pair(-1, 96), Pair(75, 26), Pair(20, 86),
        Pair(24, 77), Pair(13, 88), Pair(28, 79), Pair(30, 76), Pair(30, 75), Pair(0, 90), Pair(25, 56), Pair(-13, 92),
        Pair(11, 90), Pair(27, 80), Pair(3, 94), Pair(19, 82), Pair(7, 95), Pair(6, 92), Pair(43, 41), Pair(3, 98),
        Pair(19, 81), Pair(34, 81), Pair(25, 79), Pair(25, 78), Pair(28, 79), Pair(-10, 88), Pair(44, 53), Pair(-11, 91),
        Pair(19, 83), Pair(25, 79), Pair(10, 88), Pair(22, 77), Pair(19, 84), Pair(20, 96), Pair(50, 39), Pair(6, 87),
        Pair(21, 77), Pair(18, 83), Pair(15, 82), Pair(11, 79), Pair(15, 72), Pair(-8, 92), Pair(0, 0), Pair(-21, 32),
        Pair(23, 78), Pair(27, 73), Pair(9, 91), Pair(15, 94), Pair(15, 84), Pair(-7, 88), Pair(11, 12), Pair(-27, 100),
        Pair(18, 74), Pair(23, 72), Pair(23, 76), Pair(20, 72), Pair(18, 81), Pair(9, 77), Pair(4, 13), Pair(0, 61)
      },
      { // Piece 4
        Pair(-13, 160), Pair(28, 87), Pair(-16, 142), Pair(18, 129), Pair(41, 108), Pair(-27, 168), Pair(21, 108), Pair(-7, 132),
        Pair(10, 129), Pair(2, 136), Pair(8, 119), Pair(13, 129), Pair(6, 140), Pair(29, 131), Pair(35, 79), Pair(15, 117),
        Pair(11, 147), Pair(13, 127), Pair(22, 120), Pair(10, 107), Pair(-15, 136), Pair(20, 100), Pair(8, 132), Pair(-23, 136),
        Pair(13, 130), Pair(6, 139), Pair(11, 133), Pair(10, 130), Pair(6, 122), Pair(-20, 143), Pair(-6, 123), Pair(-13, 113),
        Pair(23, 140), Pair(26, 135), Pair(14, 140), Pair(15, 117), Pair(10, 125), Pair(-1, 117), Pair(2, 116), Pair(-15, 116),
        Pair(34, 99), Pair(31, 132), Pair(17, 133), Pair(22, 126), Pair(19, 121), Pair(15, 121), Pair(0, 0), Pair(1, 69),
        Pair(41, 159), Pair(26, 142), Pair(24, 148), Pair(24, 134), Pair(28, 121), Pair(20, 105), Pair(-5, 125), Pair(-4, 77),
        Pair(18, 154), Pair(32, 148), Pair(30, 149), Pair(26, 151), Pair(22, 143), Pair(8, 171), Pair(0, 122), Pair(25, 94)
      },
      { // Piece 5
        Pair(-70, -39), Pair(63, -31), Pair(-72, 3), Pair(-9, -29), Pair(-102, 34), Pair(-156, 34), Pair(-49, 23), Pair(-239, 116),
        Pair(-109, -10), Pair(-124, 7), Pair(-17, -13), Pair(-118, 40), Pair(-92, 16), Pair(-107, 81), Pair(-53, 98), Pair(-47, 43),
        Pair(-114, 12), Pair(-31, -7), Pair(-24, 15), Pair(2, 19), Pair(-66, 55), Pair(29, 44), Pair(13, 52), Pair(-35, 36),
        Pair(-27, -19), Pair(-26, 18), Pair(-67, 30), Pair(-31, 34), Pair(-38, 40), Pair(7, 38), Pair(-22, 46), Pair(10, 37),
        Pair(-19, 29), Pair(-51, 26), Pair(-3, 16), Pair(-40, 32), Pair(-17, 23), Pair(-43, 15), Pair(-15, 24), Pair(-21, 0),
        Pair(-102, 13), Pair(-50, 16), Pair(-46, 28), Pair(-2, 18), Pair(-5, 20), Pair(-5, 4), Pair(0, 0), Pair(43, -16),
        Pair(-58, 5), Pair(-39, 9), Pair(-44, 18), Pair(-30, 19), Pair(9, 7), Pair(-12, 1), Pair(7, -6), Pair(-5, -9),
        Pair(-34, -13), Pair(-39, -4), Pair(-38, 20), Pair(-30, 1), Pair(19, -13), Pair(6, 0), Pair(8, -9), Pair(-24, -14)
      }
    }},
    {{ // Bucket 47
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-17, 27), Pair(-5, 27), Pair(2, 22), Pair(5, 9), Pair(-24, 5), Pair(29, -1), Pair(-27, 20), Pair(5, 27),
        Pair(-7, 23), Pair(-6, 25), Pair(1, 19), Pair(5, 17), Pair(1, 14), Pair(-14, 13), Pair(-8, 13), Pair(-7, 0),
        Pair(-2, 20), Pair(0, 14), Pair(0, 17), Pair(4, 10), Pair(0, 14), Pair(-4, 9), Pair(-4, 16), Pair(9, -2),
        Pair(-5, 19), Pair(3, 20), Pair(4, 21), Pair(1, 12), Pair(0, 9), Pair(2, 8), Pair(10, 6), Pair(4, 4),
        Pair(1, 20), Pair(3, 20), Pair(1, 15), Pair(3, 18), Pair(6, 15), Pair(2, 8), Pair(2, 7), Pair(2, -12),
        Pair(-2, 22), Pair(-2, 18), Pair(0, 20), Pair(2, 12), Pair(5, 16), Pair(-7, 13), Pair(10, 27), Pair(-11, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(66, 4), Pair(88, 55), Pair(-4, 50), Pair(44, 45), Pair(48, 40), Pair(42, 53), Pair(94, 26), Pair(28, 8),
        Pair(22, 51), Pair(5, 66), Pair(5, 57), Pair(-20, 69), Pair(-7, 68), Pair(-20, 62), Pair(23, 68), Pair(36, 37),
        Pair(-27, 62), Pair(5, 57), Pair(8, 56), Pair(11, 63), Pair(-18, 75), Pair(-10, 53), Pair(-9, 66), Pair(-21, 61),
        Pair(-1, 65), Pair(7, 59), Pair(5, 66), Pair(-3, 65), Pair(-7, 64), Pair(-20, 62), Pair(-8, 63), Pair(-1, 59),
        Pair(6, 60), Pair(-2, 68), Pair(6, 65), Pair(3, 62), Pair(-1, 68), Pair(-4, 63), Pair(8, 62), Pair(-8, 47),
        Pair(3, 67), Pair(5, 65), Pair(7, 67), Pair(1, 67), Pair(3, 64), Pair(-1, 59), Pair(9, 54), Pair(0, 0),
        Pair(5, 44), Pair(-11, 54), Pair(12, 56), Pair(6, 62), Pair(10, 57), Pair(-12, 54), Pair(-11, 58), Pair(-8, 64),
        Pair(-78, 87), Pair(10, 70), Pair(7, 71), Pair(-6, 60), Pair(-2, 61), Pair(-2, 46), Pair(11, 55), Pair(-67, 63)
      },
      { // Piece 2
        Pair(50, 0), Pair(64, 39), Pair(7, 1), Pair(58, 43), Pair(109, 17), Pair(-30, 71), Pair(-23, 33), Pair(-27, 65),
        Pair(19, 46), Pair(13, 24), Pair(14, 32), Pair(44, 3), Pair(29, 42), Pair(30, 32), Pair(-18, 75), Pair(-21, 40),
        Pair(14, 33), Pair(16, 52), Pair(27, 30), Pair(13, 42), Pair(15, 17), Pair(15, 62), Pair(-13, 46), Pair(8, 61),
        Pair(1, 59), Pair(11, 31), Pair(4, 63), Pair(12, 34), Pair(-2, 63), Pair(6, 37), Pair(10, 65), Pair(3, 44),
        Pair(4, 34), Pair(4, 58), Pair(8, 42), Pair(6, 61), Pair(0, 44), Pair(0, 58), Pair(42, 75), Pair(-4, 61),
        Pair(9, 60), Pair(6, 32), Pair(7, 55), Pair(5, 44), Pair(5, 67), Pair(0, 44), Pair(2, 51), Pair(0, 0),
        Pair(-3, 29), Pair(8, 55), Pair(7, 40), Pair(7, 59), Pair(2, 48), Pair(18, 64), Pair(9, 40), Pair(12, 77),
        Pair(19, 62), Pair(21, 25), Pair(11, 58), Pair(10, 37), Pair(23, 59), Pair(2, 46), Pair(41, 45), Pair(-4, 28)
      },
      { // Piece 3
        Pair(9, 95), Pair(35, 85), Pair(47, 71), Pair(-8, 92), Pair(12, 91), Pair(30, 86), Pair(56, 70), Pair(102, 24),
        Pair(13, 92), Pair(4, 98), Pair(16, 101), Pair(16, 88), Pair(2, 91), Pair(27, 74), Pair(4, 93), Pair(54, 36),
        Pair(11, 94), Pair(14, 94), Pair(18, 99), Pair(20, 88), Pair(9, 96), Pair(15, 92), Pair(37, 83), Pair(51, 54),
        Pair(10, 93), Pair(21, 94), Pair(16, 96), Pair(29, 91), Pair(9, 92), Pair(14, 92), Pair(3, 104), Pair(16, 64),
        Pair(21, 81), Pair(8, 93), Pair(15, 93), Pair(23, 79), Pair(20, 93), Pair(2, 94), Pair(3, 111), Pair(19, 60),
        Pair(19, 87), Pair(14, 85), Pair(15, 78), Pair(3, 89), Pair(8, 92), Pair(3, 86), Pair(9, 96), Pair(0, 0),
        Pair(14, 101), Pair(26, 94), Pair(13, 86), Pair(14, 86), Pair(8, 101), Pair(8, 91), Pair(-6, 92), Pair(-88, 74),
        Pair(19, 81), Pair(22, 81), Pair(17, 82), Pair(21, 75), Pair(16, 82), Pair(16, 82), Pair(-12, 85), Pair(-12, 24)
      },
      { // Piece 4
        Pair(49, 134), Pair(23, 124), Pair(54, 110), Pair(42, 128), Pair(28, 159), Pair(0, 159), Pair(44, 124), Pair(-19, 161),
        Pair(12, 147), Pair(15, 151), Pair(16, 158), Pair(6, 139), Pair(3, 164), Pair(17, 149), Pair(-2, 173), Pair(-8, 166),
        Pair(29, 139), Pair(18, 158), Pair(18, 145), Pair(21, 151), Pair(13, 135), Pair(23, 160), Pair(3, 165), Pair(-10, 137),
        Pair(16, 142), Pair(19, 141), Pair(32, 145), Pair(24, 144), Pair(-5, 160), Pair(0, 157), Pair(16, 150), Pair(3, 141),
        Pair(21, 160), Pair(18, 172), Pair(25, 150), Pair(17, 154), Pair(5, 164), Pair(15, 136), Pair(16, 149), Pair(-4, 143),
        Pair(37, 141), Pair(36, 136), Pair(17, 158), Pair(23, 150), Pair(15, 154), Pair(14, 150), Pair(2, 169), Pair(0, 0),
        Pair(39, 176), Pair(28, 157), Pair(32, 150), Pair(28, 151), Pair(23, 137), Pair(18, 143), Pair(24, 148), Pair(-14, 104),
        Pair(39, 135), Pair(26, 155), Pair(29, 162), Pair(30, 157), Pair(26, 143), Pair(47, 124), Pair(51, 123), Pair(-9, 100)
      },
      { // Piece 5
        Pair(64, -74), Pair(-165, 2), Pair(106, -57), Pair(26, -12), Pair(-133, 15), Pair(-89, 89), Pair(-120, 83), Pair(-82, 74),
        Pair(66, 0), Pair(-70, 0), Pair(-21, 20), Pair(-7, -3), Pair(-106, 36), Pair(125, 37), Pair(1, 49), Pair(-283, 71),
        Pair(-97, -1), Pair(-20, 7), Pair(-4, 9), Pair(96, 11), Pair(-3, 24), Pair(14, 41), Pair(33, 51), Pair(-8, 55),
        Pair(-59, 10), Pair(-107, 22), Pair(-82, 21), Pair(-80, 23), Pair(-87, 40), Pair(-25, 36), Pair(35, 27), Pair(12, 37),
        Pair(2, -22), Pair(-101, 29), Pair(-88, 34), Pair(-68, 31), Pair(-26, 32), Pair(-20, 26), Pair(-13, -3), Pair(-26, 14),
        Pair(-142, 16), Pair(-96, 35), Pair(-82, 27), Pair(-46, 31), Pair(-19, 14), Pair(-19, 12), Pair(-54, -9), Pair(0, 0),
        Pair(-27, -8), Pair(-44, 17), Pair(-45, 21), Pair(-43, 26), Pair(-10, 2), Pair(-19, 3), Pair(-33, -13), Pair(-12, -25),
        Pair(-52, -37), Pair(-34, 2), Pair(-34, 12), Pair(-13, 5), Pair(7, -16), Pair(2, -13), Pair(14, -6), Pair(18, -26)
      }
    }},
    {{ // Bucket 48
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-24, 29), Pair(-22, 33), Pair(-14, 30), Pair(-1, 23), Pair(-5, 7), Pair(-6, 14), Pair(-31, 47), Pair(-27, 41),
        Pair(-12, 26), Pair(-31, 30), Pair(-14, 24), Pair(-10, 17), Pair(-4, 19), Pair(-2, 13), Pair(-7, 19), Pair(-11, 23),
        Pair(-1, 9), Pair(-8, 17), Pair(-2, 13), Pair(-5, 17), Pair(2, 9), Pair(0, 17), Pair(-9, 19), Pair(-1, 19),
        Pair(5, 6), Pair(-4, 22), Pair(-4, 17), Pair(-1, 14), Pair(2, 14), Pair(-1, 16), Pair(-4, 22), Pair(-7, 23),
        Pair(-2, -2), Pair(10, 26), Pair(-4, 12), Pair(0, 13), Pair(0, 14), Pair(-1, 18), Pair(3, 23), Pair(-4, 24),
        Pair(-1, 4), Pair(-4, 3), Pair(-9, 12), Pair(-1, 19), Pair(-2, 21), Pair(-5, 24), Pair(-1, 25), Pair(1, 28),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(3, 22), Pair(-150, 90), Pair(-14, 58), Pair(-99, 84), Pair(-30, 87), Pair(-13, 45), Pair(-59, 26), Pair(-12, 51),
        Pair(23, 34), Pair(-13, 65), Pair(4, 84), Pair(-47, 107), Pair(-63, 91), Pair(10, 69), Pair(-7, 123), Pair(3, 95),
        Pair(-18, 82), Pair(18, 77), Pair(1, 75), Pair(-2, 77), Pair(-14, 79), Pair(-14, 95), Pair(-20, 89), Pair(-29, 99),
        Pair(15, 73), Pair(14, 79), Pair(5, 84), Pair(5, 90), Pair(-3, 89), Pair(-4, 92), Pair(-4, 90), Pair(-25, 91),
        Pair(12, 75), Pair(22, 61), Pair(1, 83), Pair(7, 79), Pair(-2, 85), Pair(2, 88), Pair(-21, 79), Pair(3, 76),
        Pair(-3, 62), Pair(12, 85), Pair(12, 69), Pair(7, 87), Pair(8, 80), Pair(5, 78), Pair(10, 86), Pair(8, 57),
        Pair(0, 0), Pair(23, 71), Pair(0, 82), Pair(1, 85), Pair(8, 85), Pair(4, 91), Pair(7, 74), Pair(-1, 86),
        Pair(36, 70), Pair(23, 33), Pair(14, 49), Pair(4, 80), Pair(7, 87), Pair(6, 80), Pair(14, 81), Pair(-23, 117)
      },
      { // Piece 2
        Pair(-12, 85), Pair(12, 64), Pair(44, 22), Pair(14, 50), Pair(72, 23), Pair(70, 17), Pair(10, 23), Pair(53, 32),
        Pair(34, 47), Pair(32, 50), Pair(30, 42), Pair(10, 48), Pair(26, 33), Pair(35, 24), Pair(4, 59), Pair(-10, 34),
        Pair(18, 84), Pair(10, 62), Pair(27, 63), Pair(11, 54), Pair(18, 28), Pair(33, 34), Pair(-8, 59), Pair(-8, 68),
        Pair(11, 71), Pair(9, 76), Pair(17, 62), Pair(11, 53), Pair(7, 55), Pair(2, 68), Pair(4, 61), Pair(1, 65),
        Pair(8, 67), Pair(16, 66), Pair(10, 57), Pair(8, 66), Pair(5, 77), Pair(6, 71), Pair(11, 78), Pair(-2, 75),
        Pair(-2, 52), Pair(30, 75), Pair(3, 65), Pair(10, 69), Pair(7, 72), Pair(15, 75), Pair(17, 66), Pair(10, 76),
        Pair(0, 0), Pair(9, 60), Pair(13, 71), Pair(3, 73), Pair(14, 70), Pair(4, 74), Pair(10, 77), Pair(13, 65),
        Pair(7, 51), Pair(17, 37), Pair(5, 77), Pair(21, 61), Pair(11, 71), Pair(6, 81), Pair(15, 88), Pair(15, 51)
      },
      { // Piece 3
        Pair(-6, 92), Pair(-25, 124), Pair(-30, 120), Pair(-15, 126), Pair(-54, 129), Pair(-63, 135), Pair(-26, 129), Pair(-17, 115),
        Pair(-48, 105), Pair(-26, 126), Pair(-27, 126), Pair(-19, 122), Pair(-42, 125), Pair(-27, 127), Pair(-19, 140), Pair(-20, 123),
        Pair(-30, 114), Pair(-3, 124), Pair(-20, 121), Pair(-41, 130), Pair(-7, 118), Pair(-27, 128), Pair(-42, 137), Pair(2, 112),
        Pair(-20, 119), Pair(-13, 126), Pair(-7, 123), Pair(-13, 124), Pair(-11, 120), Pair(-17, 134), Pair(-25, 133), Pair(-4, 126),
        Pair(-30, 119), Pair(-6, 123), Pair(-23, 131), Pair(-1, 128), Pair(-3, 122), Pair(-38, 136), Pair(-31, 125), Pair(-14, 112),
        Pair(-39, 102), Pair(-9, 111), Pair(-5, 119), Pair(-13, 131), Pair(-7, 110), Pair(-23, 127), Pair(-8, 125), Pair(-2, 103),
        Pair(0, 0), Pair(-8, 127), Pair(-1, 130), Pair(-11, 128), Pair(-7, 127), Pair(-13, 130), Pair(-21, 122), Pair(17, 119),
        Pair(-29, 90), Pair(-14, 118), Pair(-12, 125), Pair(-8, 120), Pair(-11, 118), Pair(-12, 117), Pair(-16, 125), Pair(-3, 112)
      },
      { // Piece 4
        Pair(-3, 210), Pair(24, 199), Pair(1, 187), Pair(0, 209), Pair(-32, 224), Pair(51, 198), Pair(0, 264), Pair(-24, 244),
        Pair(-20, 222), Pair(-12, 212), Pair(3, 204), Pair(-3, 202), Pair(9, 181), Pair(-15, 210), Pair(21, 193), Pair(4, 186),
        Pair(-23, 238), Pair(-4, 207), Pair(-11, 227), Pair(1, 225), Pair(-12, 229), Pair(-25, 219), Pair(-12, 216), Pair(-10, 218),
        Pair(-7, 251), Pair(-3, 250), Pair(-7, 247), Pair(-3, 219), Pair(10, 190), Pair(-13, 211), Pair(3, 217), Pair(-2, 222),
        Pair(-6, 245), Pair(8, 219), Pair(5, 223), Pair(8, 220), Pair(4, 242), Pair(15, 215), Pair(1, 234), Pair(18, 201),
        Pair(-18, 233), Pair(12, 216), Pair(10, 226), Pair(8, 232), Pair(16, 229), Pair(13, 237), Pair(13, 212), Pair(17, 186),
        Pair(0, 0), Pair(10, 227), Pair(10, 223), Pair(14, 224), Pair(14, 237), Pair(19, 228), Pair(22, 223), Pair(27, 197),
        Pair(-18, 210), Pair(9, 226), Pair(8, 225), Pair(11, 227), Pair(4, 249), Pair(12, 229), Pair(-28, 260), Pair(0, 247)
      },
      { // Piece 5
        Pair(-82, 97), Pair(-133, 31), Pair(-110, 20), Pair(44, -46), Pair(27, -33), Pair(104, -40), Pair(-56, 17), Pair(-141, -20),
        Pair(2, 56), Pair(-17, 53), Pair(-212, 115), Pair(-69, 25), Pair(-146, 55), Pair(112, -12), Pair(-113, 25), Pair(-60, -7),
        Pair(-73, 82), Pair(-8, 63), Pair(59, 27), Pair(-162, 104), Pair(-72, 41), Pair(-150, 55), Pair(-82, 23), Pair(-119, 16),
        Pair(-57, 74), Pair(-45, 53), Pair(-87, 72), Pair(-117, 55), Pair(-84, 42), Pair(-21, 28), Pair(-52, 21), Pair(-79, 23),
        Pair(-85, 72), Pair(-11, 30), Pair(-13, 27), Pair(-72, 58), Pair(-98, 49), Pair(-35, 27), Pair(-53, 28), Pair(-52, 24),
        Pair(-52, 63), Pair(-20, -6), Pair(-1, 27), Pair(-10, 32), Pair(-33, 31), Pair(-33, 28), Pair(-24, 24), Pair(-40, 16),
        Pair(0, 0), Pair(1, -7), Pair(26, 1), Pair(5, 12), Pair(-16, 19), Pair(-2, 13), Pair(-12, 16), Pair(-13, 0),
        Pair(67, -64), Pair(63, -53), Pair(64, -11), Pair(9, 5), Pair(5, 10), Pair(-18, 17), Pair(-7, 8), Pair(-5, -5)
      }
    }},
    {{ // Bucket 49
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-12, 34), Pair(-19, 10), Pair(14, 8), Pair(-14, 13), Pair(28, 7), Pair(18, 12), Pair(14, -11), Pair(-24, 31),
        Pair(-10, 20), Pair(-1, 5), Pair(-13, 20), Pair(-2, 7), Pair(-10, 16), Pair(-2, 12), Pair(-7, 13), Pair(-8, 9),
        Pair(-5, 12), Pair(6, 9), Pair(-8, 16), Pair(0, 9), Pair(0, 14), Pair(2, 16), Pair(1, 14), Pair(1, 15),
        Pair(-5, 13), Pair(1, 4), Pair(3, 20), Pair(1, 14), Pair(2, 15), Pair(3, 17), Pair(2, 22), Pair(-2, 20),
        Pair(1, 15), Pair(3, -8), Pair(11, 31), Pair(2, 19), Pair(-3, 21), Pair(7, 19), Pair(0, 17), Pair(1, 20),
        Pair(-3, 9), Pair(-1, 12), Pair(3, 15), Pair(-3, -33), Pair(-1, 21), Pair(-1, 21), Pair(-2, 22), Pair(1, 22),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-25, 70), Pair(61, 35), Pair(8, 76), Pair(-49, 63), Pair(-11, 41), Pair(-3, 25), Pair(27, 56), Pair(-72, 89),
        Pair(0, 57), Pair(-18, 77), Pair(-9, 65), Pair(-27, 77), Pair(-68, 103), Pair(-34, 93), Pair(19, 65), Pair(-28, 45),
        Pair(-29, 73), Pair(-5, 72), Pair(-10, 66), Pair(-22, 83), Pair(-17, 92), Pair(-24, 73), Pair(-22, 79), Pair(-46, 96),
        Pair(12, 63), Pair(-6, 70), Pair(-2, 66), Pair(-9, 69), Pair(-5, 78), Pair(-17, 77), Pair(-15, 85), Pair(-11, 77),
        Pair(7, 69), Pair(8, 76), Pair(2, 68), Pair(-3, 75), Pair(-4, 77), Pair(1, 82), Pair(-24, 86), Pair(-6, 78),
        Pair(13, 86), Pair(3, 61), Pair(12, 77), Pair(13, 71), Pair(11, 70), Pair(3, 75), Pair(0, 69), Pair(8, 70),
        Pair(-7, 78), Pair(0, 0), Pair(6, 77), Pair(1, 77), Pair(3, 79), Pair(9, 61), Pair(0, 71), Pair(-1, 70),
        Pair(-31, 123), Pair(7, 102), Pair(18, 76), Pair(13, 78), Pair(4, 87), Pair(0, 71), Pair(7, 80), Pair(35, 16)
      },
      { // Piece 2
        Pair(14, 43), Pair(-22, 54), Pair(7, 67), Pair(-14, 40), Pair(-8, 47), Pair(3, 23), Pair(3, 56), Pair(3, 26),
        Pair(4, 50), Pair(12, 45), Pair(-15, 47), Pair(26, 71), Pair(-20, 34), Pair(29, 38), Pair(-6, 40), Pair(-8, 27),
        Pair(-6, 48), Pair(7, 64), Pair(17, 56), Pair(6, 48), Pair(1, 57), Pair(-16, 51), Pair(3, 28), Pair(-13, 51),
        Pair(-16, 75), Pair(1, 54), Pair(19, 52), Pair(5, 57), Pair(1, 55), Pair(-5, 59), Pair(2, 54), Pair(-9, 64),
        Pair(15, 48), Pair(-3, 39), Pair(6, 58), Pair(4, 46), Pair(2, 58), Pair(3, 56), Pair(9, 66), Pair(10, 39),
        Pair(-5, 49), Pair(-4, 32), Pair(7, 85), Pair(-2, 65), Pair(-1, 65), Pair(6, 69), Pair(8, 64), Pair(1, 55),
        Pair(12, 52), Pair(0, 0), Pair(4, 61), Pair(0, 71), Pair(4, 69), Pair(8, 70), Pair(4, 70), Pair(6, 62),
        Pair(0, 0), Pair(7, 88), Pair(-7, 47), Pair(22, 65), Pair(6, 67), Pair(3, 77), Pair(-4, 77), Pair(19, 50)
      },
      { // Piece 3
        Pair(-82, 126), Pair(12, 63), Pair(-35, 109), Pair(-22, 112), Pair(-15, 93), Pair(0, 94), Pair(-10, 105), Pair(-30, 104),
        Pair(-30, 92), Pair(-42, 88), Pair(-13, 95), Pair(-20, 103), Pair(-28, 96), Pair(-39, 104), Pair(-46, 108), Pair(-25, 98),
        Pair(-19, 105), Pair(-30, 88), Pair(-24, 92), Pair(-6, 95), Pair(-6, 93), Pair(-45, 114), Pair(-25, 93), Pair(-14, 99),
        Pair(-14, 98), Pair(-8, 91), Pair(-5, 96), Pair(-17, 103), Pair(-9, 99), Pair(-12, 95), Pair(-3, 91), Pair(-1, 104),
        Pair(-1, 86), Pair(-5, 92), Pair(1, 99), Pair(3, 91), Pair(-12, 117), Pair(-13, 110), Pair(-4, 104), Pair(-13, 112),
        Pair(-9, 92), Pair(-6, 63), Pair(6, 98), Pair(3, 103), Pair(-5, 101), Pair(-18, 116), Pair(-33, 102), Pair(-19, 116),
        Pair(-31, 76), Pair(0, 0), Pair(-16, 117), Pair(-9, 109), Pair(-8, 111), Pair(-5, 101), Pair(-1, 92), Pair(3, 106),
        Pair(-11, 87), Pair(-13, 42), Pair(-12, 97), Pair(-6, 95), Pair(-9, 96), Pair(-11, 93), Pair(-5, 89), Pair(-2, 108)
      },
      { // Piece 4
        Pair(-13, 158), Pair(-3, 186), Pair(51, 104), Pair(-38, 170), Pair(-51, 195), Pair(10, 152), Pair(5, 143), Pair(-8, 148),
        Pair(-34, 197), Pair(-13, 162), Pair(-20, 188), Pair(-28, 201), Pair(-12, 146), Pair(-22, 179), Pair(-3, 167), Pair(-31, 224),
        Pair(-33, 194), Pair(-20, 187), Pair(-1, 168), Pair(-22, 185), Pair(-18, 163), Pair(-33, 156), Pair(-4, 185), Pair(-21, 158),
        Pair(-24, 200), Pair(0, 172), Pair(-8, 175), Pair(-11, 167), Pair(-7, 145), Pair(-8, 139), Pair(-28, 161), Pair(-20, 170),
        Pair(0, 165), Pair(-7, 167), Pair(6, 164), Pair(-9, 155), Pair(-3, 166), Pair(-13, 178), Pair(2, 161), Pair(-13, 156),
        Pair(-7, 172), Pair(-8, 142), Pair(-6, 198), Pair(1, 180), Pair(-5, 180), Pair(-1, 166), Pair(-12, 189), Pair(-5, 167),
        Pair(-18, 132), Pair(0, 0), Pair(1, 182), Pair(5, 183), Pair(5, 194), Pair(5, 178), Pair(18, 182), Pair(26, 178),
        Pair(2, 153), Pair(0, 98), Pair(-10, 177), Pair(0, 182), Pair(4, 188), Pair(-1, 179), Pair(-10, 222), Pair(2, 220)
      },
      { // Piece 5
        Pair(-269, 98), Pair(29, 3), Pair(-216, -12), Pair(-181, -34), Pair(32, 8), Pair(-155, 3), Pair(1, -47), Pair(-54, 5),
        Pair(-46, 56), Pair(-5, 81), Pair(31, 16), Pair(88, 16), Pair(120, 26), Pair(-108, 50), Pair(-231, 53), Pair(-268, 21),
        Pair(-293, 123), Pair(-79, 66), Pair(59, 29), Pair(-160, 52), Pair(-94, 80), Pair(-54, 26), Pair(-98, 28), Pair(-46, 18),
        Pair(38, 30), Pair(18, 48), Pair(31, 42), Pair(-50, 51), Pair(-106, 26), Pair(-100, 40), Pair(-109, 22), Pair(-19, 5),
        Pair(66, 32), Pair(34, 18), Pair(35, 44), Pair(-40, 34), Pair(-32, 36), Pair(-40, 21), Pair(-54, 13), Pair(-73, 9),
        Pair(81, -26), Pair(-11, 8), Pair(-25, 9), Pair(1, 17), Pair(-26, 25), Pair(-13, 12), Pair(-27, 7), Pair(-48, 4),
        Pair(94, -8), Pair(0, 0), Pair(-8, 17), Pair(14, 19), Pair(5, 14), Pair(-7, 12), Pair(-10, 4), Pair(-14, -3),
        Pair(83, -8), Pair(29, -14), Pair(38, 0), Pair(-1, 12), Pair(14, 6), Pair(-9, 14), Pair(-4, -2), Pair(-10, -12)
      }
    }},
    {{ // Bucket 50
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-35, 32), Pair(-24, 29), Pair(-37, -8), Pair(-41, 0), Pair(5, 4), Pair(-40, 24), Pair(-14, 31), Pair(-7, 11),
        Pair(-9, 12), Pair(-20, 24), Pair(-15, -8), Pair(-14, 8), Pair(-6, 17), Pair(-7, 14), Pair(3, 11), Pair(-5, 19),
        Pair(-2, 16), Pair(-11, 17), Pair(-3, -7), Pair(-4, 15), Pair(0, 9), Pair(2, 19), Pair(-3, 9), Pair(0, 17),
        Pair(-4, 16), Pair(-2, 19), Pair(-8, -20), Pair(4, 22), Pair(0, 15), Pair(5, 14), Pair(-1, 20), Pair(0, 18),
        Pair(-7, 12), Pair(2, 23), Pair(-7, -25), Pair(8, 38), Pair(-8, 15), Pair(4, 16), Pair(0, 17), Pair(-1, 16),
        Pair(-10, 10), Pair(3, 14), Pair(-1, 2), Pair(5, 24), Pair(-4, 8), Pair(-3, 21), Pair(-1, 23), Pair(-4, 22),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(39, -4), Pair(-60, 85), Pair(-20, 52), Pair(81, 45), Pair(-57, 65), Pair(12, 59), Pair(-97, 60), Pair(-3, -36),
        Pair(-23, 51), Pair(9, 64), Pair(-2, 53), Pair(-60, 110), Pair(-5, 72), Pair(14, 48), Pair(-42, 85), Pair(-35, 83),
        Pair(-43, 74), Pair(-1, 58), Pair(-23, 64), Pair(-5, 62), Pair(-17, 54), Pair(-27, 65), Pair(0, 54), Pair(-13, 73),
        Pair(6, 57), Pair(-4, 58), Pair(-23, 69), Pair(0, 60), Pair(-16, 68), Pair(-13, 81), Pair(-17, 73), Pair(-14, 78),
        Pair(-1, 56), Pair(18, 50), Pair(-1, 57), Pair(0, 65), Pair(-18, 74), Pair(-6, 66), Pair(-16, 75), Pair(-2, 58),
        Pair(4, 56), Pair(9, 62), Pair(-8, 59), Pair(1, 77), Pair(7, 67), Pair(-6, 65), Pair(1, 65), Pair(2, 51),
        Pair(-14, 47), Pair(11, 37), Pair(0, 0), Pair(4, 67), Pair(-2, 59), Pair(5, 58), Pair(5, 67), Pair(-2, 73),
        Pair(22, -6), Pair(-4, 80), Pair(20, 85), Pair(9, 58), Pair(-17, 54), Pair(-6, 59), Pair(3, 70), Pair(19, 71)
      },
      { // Piece 2
        Pair(5, 13), Pair(21, 35), Pair(34, 22), Pair(35, 11), Pair(64, -4), Pair(41, 30), Pair(-36, 93), Pair(72, -32),
        Pair(-24, 72), Pair(-3, 46), Pair(-4, 39), Pair(1, 46), Pair(-2, 47), Pair(-5, 20), Pair(-25, 32), Pair(-12, 15),
        Pair(20, 47), Pair(17, 70), Pair(-29, 62), Pair(3, 43), Pair(-4, 31), Pair(-14, 49), Pair(6, 21), Pair(1, 43),
        Pair(-4, 56), Pair(-3, 41), Pair(15, 37), Pair(3, 39), Pair(1, 34), Pair(17, 30), Pair(7, 47), Pair(-3, 42),
        Pair(-11, 37), Pair(6, 50), Pair(0, 28), Pair(13, 51), Pair(-6, 41), Pair(6, 53), Pair(-1, 38), Pair(2, 48),
        Pair(-5, 51), Pair(2, 43), Pair(0, 39), Pair(5, 74), Pair(-5, 65), Pair(-3, 57), Pair(4, 48), Pair(-12, 55),
        Pair(-7, -16), Pair(2, 70), Pair(0, 0), Pair(4, 49), Pair(-5, 53), Pair(0, 61), Pair(-5, 63), Pair(-3, 50),
        Pair(-13, 42), Pair(-103, -68), Pair(5, 77), Pair(-13, 27), Pair(-15, 56), Pair(-6, 68), Pair(7, 21), Pair(6, 43)
      },
      { // Piece 3
        Pair(-51, 89), Pair(-26, 83), Pair(23, 48), Pair(-36, 78), Pair(-36, 80), Pair(-94, 127), Pair(-7, 53), Pair(19, 69),
        Pair(-23, 85), Pair(-24, 86), Pair(-26, 78), Pair(-8, 80), Pair(-24, 76), Pair(-29, 79), Pair(-29, 88), Pair(5, 65),
        Pair(-47, 91), Pair(-32, 80), Pair(-52, 89), Pair(-28, 70), Pair(-38, 88), Pair(-50, 85), Pair(-6, 70), Pair(15, 80),
        Pair(-15, 95), Pair(-21, 67), Pair(-14, 89), Pair(-30, 86), Pair(-13, 66), Pair(-30, 84), Pair(-16, 74), Pair(-27, 86),
        Pair(-16, 92), Pair(-1, 64), Pair(0, 79), Pair(-13, 81), Pair(-20, 75), Pair(-19, 69), Pair(-14, 69), Pair(-12, 73),
        Pair(-30, 82), Pair(-4, 79), Pair(-14, 59), Pair(-9, 73), Pair(-12, 75), Pair(-28, 89), Pair(-14, 65), Pair(-22, 96),
        Pair(-39, 64), Pair(-37, 73), Pair(0, 0), Pair(-20, 80), Pair(-14, 72), Pair(-26, 74), Pair(-8, 64), Pair(-25, 96),
        Pair(-22, 74), Pair(-25, 82), Pair(-33, 34), Pair(-21, 80), Pair(-19, 82), Pair(-17, 75), Pair(-13, 80), Pair(-16, 87)
      },
      { // Piece 4
        Pair(-21, 158), Pair(-35, 199), Pair(45, 71), Pair(19, 121), Pair(-30, 151), Pair(9, 139), Pair(-12, 127), Pair(4, 102),
        Pair(14, 142), Pair(5, 139), Pair(-9, 134), Pair(-23, 121), Pair(22, 92), Pair(-3, 101), Pair(-33, 164), Pair(-11, 129),
        Pair(-9, 147), Pair(1, 133), Pair(6, 117), Pair(-9, 130), Pair(-2, 140), Pair(-40, 162), Pair(-21, 131), Pair(-18, 145),
        Pair(-15, 153), Pair(0, 140), Pair(15, 125), Pair(-3, 141), Pair(2, 116), Pair(-14, 99), Pair(-7, 115), Pair(-5, 113),
        Pair(-19, 173), Pair(2, 142), Pair(-6, 143), Pair(0, 142), Pair(4, 137), Pair(-10, 136), Pair(-14, 143), Pair(-3, 124),
        Pair(3, 107), Pair(-4, 115), Pair(-5, 133), Pair(4, 147), Pair(6, 136), Pair(-1, 148), Pair(1, 148), Pair(-6, 129),
        Pair(0, 79), Pair(-7, 101), Pair(0, 0), Pair(2, 131), Pair(3, 131), Pair(4, 135), Pair(7, 132), Pair(-34, 189),
        Pair(9, 94), Pair(-11, 85), Pair(-1, 68), Pair(-2, 120), Pair(8, 130), Pair(12, 132), Pair(3, 175), Pair(15, 115)
      },
      { // Piece 5
        Pair(25, 148), Pair(64, 65), Pair(60, -46), Pair(14, -38), Pair(126, -27), Pair(-90, 40), Pair(56, 55), Pair(74, 20),
        Pair(-81, 54), Pair(-101, 74), Pair(-200, 46), Pair(-75, 64), Pair(56, -11), Pair(-7, 16), Pair(51, 39), Pair(-133, -1),
        Pair(-70, 64), Pair(104, 19), Pair(-88, 69), Pair(27, 67), Pair(17, 61), Pair(-171, 48), Pair(-133, 2), Pair(-168, 33),
        Pair(15, 18), Pair(-38, 39), Pair(151, -5), Pair(27, 39), Pair(-120, 22), Pair(-144, 39), Pair(-61, 9), Pair(-129, 12),
        Pair(-51, 26), Pair(55, 16), Pair(14, 16), Pair(-1, 20), Pair(-86, 24), Pair(-18, 5), Pair(-55, 16), Pair(-67, -1),
        Pair(42, 4), Pair(-19, 1), Pair(4, -15), Pair(-25, 2), Pair(-4, 3), Pair(-16, 5), Pair(-14, -7), Pair(-47, 0),
        Pair(86, 1), Pair(29, 4), Pair(0, 0), Pair(-23, 17), Pair(0, -5), Pair(-14, 1), Pair(-16, 4), Pair(-9, -8),
        Pair(72, 9), Pair(10, 6), Pair(18, 12), Pair(-30, 9), Pair(12, 5), Pair(-5, -2), Pair(-5, -15), Pair(-5, -18)
      }
    }},
    {{ // Bucket 51
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-16, 19), Pair(-64, 37), Pair(-37, 7), Pair(-71, 33), Pair(-18, -28), Pair(0, -8), Pair(18, -13), Pair(-7, -13),
        Pair(-9, 28), Pair(6, 1), Pair(-5, 9), Pair(-5, -20), Pair(-14, 23), Pair(18, -20), Pair(-9, -6), Pair(-15, 8),
        Pair(-2, 17), Pair(2, 3), Pair(0, 36), Pair(4, 4), Pair(3, 14), Pair(4, 23), Pair(-7, 15), Pair(-1, 9),
        Pair(0, 12), Pair(-1, 19), Pair(5, 16), Pair(18, -10), Pair(8, 24), Pair(4, 25), Pair(2, 10), Pair(0, 16),
        Pair(0, 20), Pair(2, 17), Pair(16, 34), Pair(9, -28), Pair(20, 40), Pair(-3, 15), Pair(5, 15), Pair(3, 11),
        Pair(-3, 18), Pair(-1, -34), Pair(5, 23), Pair(-6, -8), Pair(17, 37), Pair(-2, 8), Pair(5, 14), Pair(5, 16),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-16, -12), Pair(-61, -47), Pair(-12, -16), Pair(-101, 72), Pair(72, 60), Pair(-56, -58), Pair(-114, -27), Pair(-65, 95),
        Pair(-21, 18), Pair(-32, 22), Pair(-76, 45), Pair(-135, 72), Pair(-175, 152), Pair(-53, -7), Pair(-48, -14), Pair(-17, 56),
        Pair(-28, 51), Pair(-31, 43), Pair(-24, 63), Pair(-20, 44), Pair(-9, 33), Pair(-27, 31), Pair(1, -8), Pair(-8, 7),
        Pair(16, 32), Pair(-17, 68), Pair(-4, 47), Pair(-33, 55), Pair(-2, 29), Pair(-32, 41), Pair(-5, 60), Pair(-36, 71),
        Pair(2, 28), Pair(-30, 49), Pair(-7, 12), Pair(-7, 32), Pair(-13, 28), Pair(-14, 70), Pair(-20, 31), Pair(-3, 43),
        Pair(0, 40), Pair(8, 43), Pair(-1, 55), Pair(-7, 43), Pair(-7, 51), Pair(-1, 31), Pair(-4, 45), Pair(-3, 60),
        Pair(-11, 83), Pair(-3, 65), Pair(-5, 28), Pair(0, 0), Pair(-7, 40), Pair(5, 44), Pair(-4, 36), Pair(-10, 44),
        Pair(-82, 61), Pair(-7, -7), Pair(24, -33), Pair(-6, 42), Pair(9, 45), Pair(18, 16), Pair(5, 30), Pair(-19, 23)
      },
      { // Piece 2
        Pair(33, -21), Pair(44, -88), Pair(23, 14), Pair(-88, 14), Pair(79, -29), Pair(-68, 30), Pair(-170, 74), Pair(56, -26),
        Pair(1, 20), Pair(-6, 27), Pair(10, -1), Pair(-44, 26), Pair(-140, 52), Pair(18, -2), Pair(-12, 7), Pair(-40, 44),
        Pair(-24, 11), Pair(-15, 1), Pair(-32, 35), Pair(7, 27), Pair(-1, 21), Pair(-39, -4), Pair(7, 27), Pair(-29, 40),
        Pair(-5, 26), Pair(6, 23), Pair(-1, 43), Pair(4, 14), Pair(-4, 28), Pair(11, -5), Pair(-82, 39), Pair(9, -22),
        Pair(53, -83), Pair(-27, 8), Pair(-5, 37), Pair(-21, 32), Pair(-1, 20), Pair(-12, 8), Pair(13, 36), Pair(-51, 9),
        Pair(-9, 22), Pair(2, -18), Pair(13, 14), Pair(-24, 23), Pair(-24, 22), Pair(4, 40), Pair(-43, 23), Pair(16, 13),
        Pair(-13, 45), Pair(-11, 22), Pair(-10, 27), Pair(0, 0), Pair(3, 39), Pair(19, 1), Pair(9, 20), Pair(53, -122),
        Pair(-12, 54), Pair(-22, 33), Pair(-11, -47), Pair(54, -36), Pair(89, -208), Pair(5, 30), Pair(-125, 77), Pair(5, 53)
      },
      { // Piece 3
        Pair(-82, 94), Pair(-33, 58), Pair(-94, 82), Pair(-72, 54), Pair(-83, 70), Pair(-40, 12), Pair(-112, 53), Pair(-82, 69),
        Pair(1, 48), Pair(-36, 72), Pair(-18, 51), Pair(-116, 60), Pair(-11, 68), Pair(-48, 11), Pair(-77, 65), Pair(14, 33),
        Pair(8, 42), Pair(-27, 72), Pair(1, 23), Pair(86, -10), Pair(-68, 75), Pair(-62, 51), Pair(-52, 44), Pair(9, 36),
        Pair(6, 41), Pair(-28, 81), Pair(-32, 53), Pair(21, 36), Pair(-8, 53), Pair(-24, 47), Pair(-34, 71), Pair(-22, 54),
        Pair(-1, 46), Pair(-38, 79), Pair(-17, 37), Pair(28, 5), Pair(-18, 43), Pair(-10, 74), Pair(22, 60), Pair(19, 37),
        Pair(-16, 67), Pair(-17, 56), Pair(6, 73), Pair(-40, 42), Pair(-15, 35), Pair(-8, 24), Pair(-21, 43), Pair(21, 87),
        Pair(-18, 14), Pair(-12, 60), Pair(-46, 64), Pair(0, 0), Pair(-29, 20), Pair(-11, 16), Pair(-14, 49), Pair(7, 60),
        Pair(-11, 37), Pair(-15, 38), Pair(-17, 48), Pair(-18, -16), Pair(-14, 45), Pair(-14, 37), Pair(1, 31), Pair(2, 60)
      },
      { // Piece 4
        Pair(36, 135), Pair(40, 70), Pair(-3, 95), Pair(10, 81), Pair(-82, 122), Pair(134, 17), Pair(-53, 72), Pair(16, 11),
        Pair(-23, 110), Pair(-41, 87), Pair(-37, 75), Pair(-6, 16), Pair(28, 14), Pair(-15, -18), Pair(-47, 104), Pair(-62, -14),
        Pair(-10, 81), Pair(7, 97), Pair(-8, 98), Pair(-34, 42), Pair(-4, 83), Pair(-55, 108), Pair(-12, 132), Pair(-75, 99),
        Pair(-6, 32), Pair(-9, 49), Pair(-16, 68), Pair(9, 15), Pair(-13, 63), Pair(-21, 40), Pair(-9, 121), Pair(1, 50),
        Pair(-15, 86), Pair(2, 25), Pair(-22, 120), Pair(-15, 55), Pair(-10, 108), Pair(-18, 104), Pair(-18, 90), Pair(-20, 49),
        Pair(3, 31), Pair(4, 34), Pair(-3, 69), Pair(-12, 47), Pair(-6, 111), Pair(-1, 41), Pair(-1, 65), Pair(-31, 116),
        Pair(12, 12), Pair(2, 48), Pair(9, 37), Pair(0, 0), Pair(-7, 66), Pair(2, 55), Pair(5, 87), Pair(23, 93),
        Pair(-7, 38), Pair(12, 46), Pair(1, -1), Pair(-1, 27), Pair(-6, 47), Pair(18, 31), Pair(67, 59), Pair(19, 49)
      },
      { // Piece 5
        Pair(9, 47), Pair(51, 50), Pair(26, 137), Pair(44, 168), Pair(-16, -134), Pair(-32, -133), Pair(-92, -59), Pair(-39, 25),
        Pair(-47, 174), Pair(0, 150), Pair(-6, 54), Pair(37, 96), Pair(95, 65), Pair(-60, 99), Pair(-59, 62), Pair(-101, -67),
        Pair(-135, -34), Pair(38, -104), Pair(-81, 29), Pair(-28, 32), Pair(-142, 86), Pair(-38, 56), Pair(-6, -12), Pair(124, 26),
        Pair(-63, 5), Pair(-11, 16), Pair(-55, 78), Pair(-25, 22), Pair(33, 28), Pair(-64, 36), Pair(-202, 46), Pair(-48, -4),
        Pair(-167, -81), Pair(-77, 17), Pair(45, -14), Pair(-66, 22), Pair(-44, 18), Pair(-83, 10), Pair(28, -22), Pair(-55, 14),
        Pair(-105, 25), Pair(-51, -17), Pair(104, -56), Pair(-27, -14), Pair(14, -31), Pair(-26, 5), Pair(18, -31), Pair(-25, 7),
        Pair(81, -47), Pair(17, -3), Pair(-9, 11), Pair(0, 0), Pair(-47, 9), Pair(16, -16), Pair(29, -40), Pair(8, -26),
        Pair(24, -34), Pair(19, 14), Pair(-5, 31), Pair(-32, 37), Pair(-27, 6), Pair(16, -8), Pair(16, -20), Pair(4, -30)
      }
    }},
    {{ // Bucket 52
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(27, 8), Pair(-4, 28), Pair(1, 42), Pair(-18, -6), Pair(-71, 13), Pair(-67, 32), Pair(-38, 18), Pair(13, 24),
        Pair(-8, 21), Pair(-12, 16), Pair(-3, 4), Pair(-16, 34), Pair(2, 2), Pair(-23, 60), Pair(-26, 16), Pair(2, 18),
        Pair(-2, 13), Pair(-4, 14), Pair(-3, 18), Pair(-3, 26), Pair(1, 16), Pair(5, 24), Pair(-1, 9), Pair(4, 3),
        Pair(-4, 21), Pair(-1, 16), Pair(-3, 15), Pair(6, 25), Pair(6, 10), Pair(10, 17), Pair(-1, 18), Pair(7, 11),
        Pair(-1, 18), Pair(-3, 24), Pair(-6, 16), Pair(15, 44), Pair(7, -15), Pair(19, 32), Pair(3, 16), Pair(0, 13),
        Pair(-5, 20), Pair(1, 19), Pair(-4, 7), Pair(18, 38), Pair(-5, 1), Pair(11, 20), Pair(0, -33), Pair(5, 14),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(34, 8), Pair(-27, 50), Pair(47, 67), Pair(-7, 60), Pair(-137, 73), Pair(12, -47), Pair(65, 94), Pair(-86, 77),
        Pair(16, 27), Pair(13, 24), Pair(-15, 41), Pair(-102, 66), Pair(-64, 77), Pair(-32, 54), Pair(-29, 57), Pair(-83, 42),
        Pair(64, -15), Pair(-14, 56), Pair(9, 51), Pair(2, 43), Pair(-72, 71), Pair(-26, 39), Pair(-36, 47), Pair(-46, 91),
        Pair(-4, 58), Pair(2, 49), Pair(3, 31), Pair(-4, 29), Pair(-28, 25), Pair(-20, 52), Pair(-20, 44), Pair(-27, 57),
        Pair(17, 45), Pair(-8, 40), Pair(-3, 43), Pair(2, 24), Pair(-5, 41), Pair(-13, 44), Pair(-40, 52), Pair(-20, 35),
        Pair(-3, 48), Pair(7, 59), Pair(3, 45), Pair(1, 49), Pair(-17, 39), Pair(-7, 55), Pair(18, -3), Pair(-1, 8),
        Pair(0, 37), Pair(0, 31), Pair(-2, 49), Pair(5, 40), Pair(0, 0), Pair(13, 30), Pair(-9, 32), Pair(-14, 42),
        Pair(-20, 110), Pair(15, 54), Pair(-12, 43), Pair(6, 63), Pair(-9, 77), Pair(-2, 53), Pair(-1, 28), Pair(8, -47)
      },
      { // Piece 2
        Pair(23, 8), Pair(-21, 19), Pair(-1, -23), Pair(-50, 47), Pair(10, 2), Pair(6, 37), Pair(175, 32), Pair(32, 31),
        Pair(-7, 3), Pair(-16, 24), Pair(12, 22), Pair(10, 14), Pair(-81, 37), Pair(11, 2), Pair(-3, 9), Pair(-22, 12),
        Pair(-6, 13), Pair(7, 21), Pair(-5, 19), Pair(-7, 29), Pair(-12, 22), Pair(-81, 68), Pair(-25, 30), Pair(-40, 23),
        Pair(3, 11), Pair(31, -1), Pair(-6, 47), Pair(-11, 8), Pair(-12, 38), Pair(-7, 30), Pair(-5, 34), Pair(-7, 23),
        Pair(14, 26), Pair(24, 1), Pair(43, 3), Pair(-6, 22), Pair(-26, 25), Pair(-10, 24), Pair(-27, -5), Pair(3, -2),
        Pair(-6, 50), Pair(5, -10), Pair(-3, 27), Pair(19, 29), Pair(-20, 17), Pair(-5, 34), Pair(5, 23), Pair(-10, 6),
        Pair(11, -5), Pair(-3, 36), Pair(4, 1), Pair(-3, 23), Pair(0, 0), Pair(-1, 44), Pair(-16, 22), Pair(-5, 27),
        Pair(-4, 60), Pair(31, 20), Pair(-8, 47), Pair(182, -131), Pair(19, 37), Pair(-20, -24), Pair(-23, 42), Pair(-12, 7)
      },
      { // Piece 3
        Pair(4, 59), Pair(14, 30), Pair(-2, 53), Pair(-17, 69), Pair(23, 41), Pair(-152, 111), Pair(-68, 78), Pair(-67, 66),
        Pair(-8, 60), Pair(-36, 65), Pair(9, 44), Pair(-18, 36), Pair(24, 25), Pair(-45, 75), Pair(-8, 49), Pair(-11, 48),
        Pair(2, 47), Pair(3, 59), Pair(-6, 59), Pair(-19, 49), Pair(-31, 65), Pair(-27, 51), Pair(-4, 74), Pair(6, 48),
        Pair(4, 50), Pair(-9, 73), Pair(-2, 58), Pair(-10, 60), Pair(11, 39), Pair(-12, 44), Pair(-55, 53), Pair(-12, 43),
        Pair(-12, 47), Pair(5, 57), Pair(21, 51), Pair(-15, 61), Pair(-16, 42), Pair(-9, 42), Pair(-10, 60), Pair(-17, 69),
        Pair(3, 74), Pair(-3, 44), Pair(-19, 56), Pair(-10, 51), Pair(-12, 43), Pair(-25, 57), Pair(-38, 91), Pair(-39, 49),
        Pair(11, 22), Pair(-11, 58), Pair(-10, 34), Pair(-17, 37), Pair(0, 0), Pair(-20, 14), Pair(9, -2), Pair(-30, 8),
        Pair(-7, 53), Pair(-2, 59), Pair(-3, 56), Pair(-10, 43), Pair(-17, -10), Pair(-16, 45), Pair(-12, 68), Pair(-9, 46)
      },
      { // Piece 4
        Pair(-21, 109), Pair(-8, 74), Pair(-11, 119), Pair(113, -12), Pair(105, -35), Pair(19, 138), Pair(73, 45), Pair(-10, 66),
        Pair(-25, 118), Pair(-33, 93), Pair(-26, 112), Pair(6, 86), Pair(-16, 86), Pair(-21, 80), Pair(6, 82), Pair(-34, 84),
        Pair(-9, 108), Pair(-7, 90), Pair(-19, 105), Pair(-17, 100), Pair(-27, 84), Pair(-36, 102), Pair(-31, 150), Pair(-84, 135),
        Pair(-15, 72), Pair(-15, 85), Pair(-4, 77), Pair(-15, 79), Pair(-5, 68), Pair(-33, 75), Pair(-36, 63), Pair(-33, 94),
        Pair(0, 71), Pair(-3, 55), Pair(-5, 80), Pair(-16, 65), Pair(-4, 76), Pair(-23, 93), Pair(-16, 42), Pair(-13, 91),
        Pair(14, 101), Pair(1, 68), Pair(-2, 73), Pair(5, 52), Pair(-16, 81), Pair(-22, 84), Pair(8, 51), Pair(-37, 60),
        Pair(15, 47), Pair(17, 48), Pair(7, 51), Pair(-4, 64), Pair(0, 0), Pair(-3, 18), Pair(0, 77), Pair(-50, 180),
        Pair(-5, 99), Pair(7, 46), Pair(3, 47), Pair(-5, 40), Pair(-10, 30), Pair(7, 37), Pair(27, 150), Pair(30, 150)
      },
      { // Piece 5
        Pair(-8, 2), Pair(-3, -42), Pair(72, 262), Pair(59, 181), Pair(-56, -99), Pair(-27, 23), Pair(-20, -85), Pair(-61, -66),
        Pair(-98, -17), Pair(-23, -25), Pair(-19, 47), Pair(-116, -31), Pair(-83, 9), Pair(-105, 63), Pair(-93, 89), Pair(-16, -23),
        Pair(-39, -10), Pair(-70, 25), Pair(102, 12), Pair(-305, 77), Pair(-25, 44), Pair(-125, 71), Pair(-52, -26), Pair(-83, 46),
        Pair(-54, 7), Pair(64, 9), Pair(-137, 24), Pair(-133, 59), Pair(-83, 53), Pair(-36, 17), Pair(-100, 35), Pair(-23, 0),
        Pair(-12, -26), Pair(66, -42), Pair(21, -11), Pair(-33, 16), Pair(29, 9), Pair(-8, 7), Pair(5, 7), Pair(-33, 7),
        Pair(-111, 38), Pair(-4, -22), Pair(-51, 3), Pair(-74, -2), Pair(-21, -10), Pair(-16, -18), Pair(37, 2), Pair(51, -33),
        Pair(-36, -3), Pair(-36, -2), Pair(16, -17), Pair(-54, 11), Pair(0, 0), Pair(-33, 16), Pair(10, -14), Pair(9, -18),
        Pair(-34, -27), Pair(-28, 9), Pair(-16, 5), Pair(-21, 10), Pair(-19, 10), Pair(-29, 14), Pair(6, -14), Pair(4, -9)
      }
    }},
    {{ // Bucket 53
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(10, 22), Pair(-3, 16), Pair(-4, 22), Pair(-11, 18), Pair(-14, 23), Pair(-18, 8), Pair(1, 24), Pair(0, 21),
        Pair(-2, 22), Pair(-3, 21), Pair(-2, 26), Pair(-5, 14), Pair(-2, 15), Pair(2, 6), Pair(-18, 24), Pair(-4, 14),
        Pair(1, 22), Pair(-1, 16), Pair(-3, 16), Pair(1, 15), Pair(-6, 21), Pair(2, 9), Pair(0, 18), Pair(0, 12),
        Pair(-1, 22), Pair(2, 21), Pair(1, 19), Pair(-1, 18), Pair(1, 21), Pair(5, 6), Pair(8, 27), Pair(6, 11),
        Pair(0, 21), Pair(1, 24), Pair(-2, 16), Pair(-8, 12), Pair(13, 42), Pair(3, -9), Pair(21, 27), Pair(3, 16),
        Pair(2, 25), Pair(1, 23), Pair(-4, 20), Pair(-1, 8), Pair(12, 18), Pair(12, -4), Pair(8, 12), Pair(-3, 11),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(25, 6), Pair(61, 44), Pair(31, 65), Pair(56, 60), Pair(69, 68), Pair(-43, 76), Pair(114, 55), Pair(-49, 84),
        Pair(23, 50), Pair(-8, 68), Pair(-6, 84), Pair(-18, 79), Pair(-41, 93), Pair(-46, 69), Pair(-22, 80), Pair(-41, 81),
        Pair(9, 61), Pair(-7, 77), Pair(7, 71), Pair(-12, 81), Pair(-7, 76), Pair(-5, 69), Pair(-19, 94), Pair(-56, 82),
        Pair(-7, 76), Pair(5, 82), Pair(-3, 79), Pair(-20, 89), Pair(-9, 78), Pair(-24, 84), Pair(-13, 87), Pair(-33, 83),
        Pair(4, 78), Pair(-2, 94), Pair(-4, 82), Pair(8, 75), Pair(-11, 69), Pair(-8, 78), Pair(-18, 71), Pair(-16, 79),
        Pair(9, 73), Pair(15, 73), Pair(-2, 83), Pair(5, 63), Pair(11, 83), Pair(-7, 63), Pair(0, 87), Pair(-18, 56),
        Pair(3, 80), Pair(9, 57), Pair(10, 86), Pair(4, 75), Pair(3, 74), Pair(0, 0), Pair(-8, 86), Pair(-3, 62),
        Pair(-23, 87), Pair(15, 69), Pair(25, 70), Pair(-1, 62), Pair(21, 66), Pair(-9, 107), Pair(7, 65), Pair(-13, 30)
      },
      { // Piece 2
        Pair(28, 49), Pair(31, 49), Pair(59, 46), Pair(72, 37), Pair(43, 46), Pair(44, 32), Pair(79, 37), Pair(-12, 69),
        Pair(-20, 49), Pair(1, 57), Pair(-12, 52), Pair(54, 41), Pair(12, 52), Pair(-22, 53), Pair(-11, 55), Pair(8, 44),
        Pair(19, 37), Pair(16, 40), Pair(38, 46), Pair(13, 39), Pair(25, 52), Pair(-21, 64), Pair(18, 50), Pair(-39, 61),
        Pair(3, 40), Pair(17, 50), Pair(-5, 56), Pair(4, 55), Pair(-5, 61), Pair(19, 42), Pair(-15, 68), Pair(-13, 61),
        Pair(23, 46), Pair(-1, 55), Pair(8, 48), Pair(-13, 56), Pair(11, 59), Pair(-11, 54), Pair(18, 54), Pair(-21, 50),
        Pair(-2, 67), Pair(-5, 63), Pair(-11, 62), Pair(6, 60), Pair(-9, 77), Pair(2, 48), Pair(-10, 43), Pair(3, 50),
        Pair(7, 43), Pair(-13, 71), Pair(6, 56), Pair(-16, 73), Pair(16, 56), Pair(0, 0), Pair(4, 70), Pair(-20, 35),
        Pair(-10, 79), Pair(9, 60), Pair(-8, 70), Pair(16, 53), Pair(-18, 37), Pair(19, 64), Pair(-52, -33), Pair(14, 40)
      },
      { // Piece 3
        Pair(50, 83), Pair(38, 83), Pair(60, 77), Pair(44, 82), Pair(19, 91), Pair(162, 44), Pair(14, 88), Pair(22, 93),
        Pair(1, 100), Pair(-1, 102), Pair(15, 91), Pair(11, 94), Pair(0, 93), Pair(47, 66), Pair(4, 98), Pair(4, 108),
        Pair(7, 102), Pair(18, 92), Pair(-5, 98), Pair(-5, 96), Pair(-16, 96), Pair(-10, 95), Pair(5, 101), Pair(-11, 103),
        Pair(3, 103), Pair(13, 98), Pair(14, 93), Pair(7, 100), Pair(9, 96), Pair(23, 79), Pair(-14, 95), Pair(-7, 103),
        Pair(7, 104), Pair(5, 103), Pair(15, 100), Pair(8, 102), Pair(4, 107), Pair(26, 81), Pair(-8, 107), Pair(-2, 115),
        Pair(15, 92), Pair(9, 106), Pair(22, 94), Pair(24, 99), Pair(11, 95), Pair(5, 67), Pair(-8, 97), Pair(-9, 108),
        Pair(8, 100), Pair(6, 96), Pair(-4, 103), Pair(2, 99), Pair(-13, 109), Pair(0, 0), Pair(-8, 54), Pair(-20, 74),
        Pair(5, 97), Pair(3, 104), Pair(5, 100), Pair(3, 96), Pair(-2, 96), Pair(-20, 65), Pair(-10, 91), Pair(-5, 95)
      },
      { // Piece 4
        Pair(36, 166), Pair(32, 162), Pair(2, 193), Pair(36, 163), Pair(13, 170), Pair(3, 172), Pair(-65, 239), Pair(32, 136),
        Pair(-4, 174), Pair(-22, 214), Pair(-20, 189), Pair(-22, 205), Pair(-10, 176), Pair(-14, 174), Pair(-13, 195), Pair(-31, 199),
        Pair(-10, 214), Pair(-18, 190), Pair(-7, 201), Pair(-20, 208), Pair(-16, 211), Pair(-47, 202), Pair(-5, 200), Pair(-44, 177),
        Pair(-3, 205), Pair(-2, 211), Pair(4, 164), Pair(-14, 185), Pair(-18, 184), Pair(-2, 157), Pair(-24, 204), Pair(-18, 192),
        Pair(17, 204), Pair(9, 196), Pair(6, 183), Pair(3, 161), Pair(2, 181), Pair(-12, 164), Pair(1, 180), Pair(-23, 180),
        Pair(27, 173), Pair(19, 187), Pair(10, 175), Pair(14, 160), Pair(15, 171), Pair(-4, 167), Pair(-14, 170), Pair(-3, 192),
        Pair(22, 164), Pair(22, 166), Pair(17, 164), Pair(13, 166), Pair(12, 173), Pair(0, 0), Pair(1, 140), Pair(16, 83),
        Pair(17, 199), Pair(19, 186), Pair(14, 187), Pair(17, 185), Pair(6, 161), Pair(-2, 132), Pair(55, 95), Pair(-27, 184)
      },
      { // Piece 5
        Pair(-175, 4), Pair(219, 26), Pair(-239, 6), Pair(66, -6), Pair(31, 17), Pair(20, 11), Pair(-166, 28), Pair(-207, 74),
        Pair(-254, 22), Pair(-35, 56), Pair(-150, 68), Pair(33, 15), Pair(-160, 76), Pair(88, 49), Pair(-177, 72), Pair(-105, 50),
        Pair(-89, 2), Pair(-18, 4), Pair(-58, 11), Pair(-165, 62), Pair(-158, 64), Pair(-72, 97), Pair(-119, 73), Pair(9, 27),
        Pair(-248, 58), Pair(-140, 28), Pair(-191, 53), Pair(-152, 64), Pair(-29, 50), Pair(-66, 47), Pair(-35, 28), Pair(-4, 36),
        Pair(-219, 45), Pair(-49, 36), Pair(-117, 47), Pair(-102, 34), Pair(-47, 39), Pair(-29, 23), Pair(7, 24), Pair(9, 17),
        Pair(-100, 17), Pair(-44, 30), Pair(-47, 24), Pair(-22, 20), Pair(-41, 1), Pair(-20, -15), Pair(-27, -10), Pair(36, 0),
        Pair(-20, 2), Pair(-4, 10), Pair(-12, 5), Pair(-7, 18), Pair(-3, 0), Pair(0, 0), Pair(31, -15), Pair(29, -1),
        Pair(2, -14), Pair(-10, -7), Pair(2, 3), Pair(-16, 14), Pair(-3, -6), Pair(-8, 11), Pair(6, 4), Pair(22, -2)
      }
    }},
    {{ // Bucket 54
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-23, 29), Pair(-26, 27), Pair(-9, 20), Pair(-16, 16), Pair(11, 5), Pair(6, -6), Pair(2, -23), Pair(-27, 25),
        Pair(-9, 25), Pair(-1, 19), Pair(-1, 18), Pair(1, 14), Pair(-12, 15), Pair(5, 14), Pair(-6, -2), Pair(-3, 17),
        Pair(0, 23), Pair(-3, 18), Pair(2, 11), Pair(1, 12), Pair(3, 22), Pair(-9, 20), Pair(18, -7), Pair(-4, 16),
        Pair(1, 22), Pair(4, 21), Pair(2, 20), Pair(4, 19), Pair(-3, 15), Pair(4, 23), Pair(17, -8), Pair(5, 20),
        Pair(2, 19), Pair(-5, 24), Pair(5, 19), Pair(3, 20), Pair(-1, 19), Pair(16, 29), Pair(-9, -8), Pair(13, 26),
        Pair(-4, 22), Pair(4, 24), Pair(-1, 19), Pair(7, 19), Pair(0, -33), Pair(8, 13), Pair(10, 6), Pair(2, 7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(29, 51), Pair(-7, 70), Pair(34, 57), Pair(44, 51), Pair(20, 31), Pair(24, 56), Pair(-57, 126), Pair(12, -52),
        Pair(-23, 54), Pair(4, 45), Pair(-10, 76), Pair(-22, 68), Pair(-10, 69), Pair(0, 51), Pair(-9, 83), Pair(-21, 59),
        Pair(26, 62), Pair(10, 60), Pair(-6, 72), Pair(-6, 66), Pair(-27, 70), Pair(1, 57), Pair(-6, 63), Pair(14, 46),
        Pair(10, 57), Pair(11, 60), Pair(-1, 69), Pair(-3, 71), Pair(-12, 64), Pair(-11, 71), Pair(-1, 58), Pair(-24, 67),
        Pair(6, 66), Pair(-3, 75), Pair(6, 65), Pair(-1, 62), Pair(2, 66), Pair(-2, 61), Pair(-2, 49), Pair(-13, 54),
        Pair(11, 67), Pair(10, 61), Pair(4, 69), Pair(2, 63), Pair(-1, 56), Pair(7, 58), Pair(-1, 46), Pair(10, 55),
        Pair(-14, 60), Pair(8, 73), Pair(-2, 77), Pair(4, 64), Pair(-8, 60), Pair(1, 52), Pair(0, 0), Pair(-11, 56),
        Pair(-31, 89), Pair(11, 68), Pair(4, 60), Pair(-4, 78), Pair(0, 60), Pair(5, 53), Pair(9, 76), Pair(-9, 52)
      },
      { // Piece 2
        Pair(-47, 17), Pair(41, 1), Pair(59, 20), Pair(84, 30), Pair(65, -1), Pair(71, 26), Pair(73, 37), Pair(44, 24),
        Pair(6, 33), Pair(-32, 38), Pair(20, 22), Pair(6, 19), Pair(63, 20), Pair(9, 22), Pair(-9, 48), Pair(-27, 46),
        Pair(-2, 39), Pair(16, 27), Pair(6, 17), Pair(15, 28), Pair(-18, 39), Pair(19, 41), Pair(-32, 55), Pair(-14, 50),
        Pair(12, 48), Pair(9, 41), Pair(24, 30), Pair(-21, 42), Pair(1, 48), Pair(-6, 41), Pair(11, 39), Pair(-14, 48),
        Pair(9, 42), Pair(20, 42), Pair(2, 43), Pair(14, 49), Pair(-13, 37), Pair(13, 47), Pair(-4, 37), Pair(0, 51),
        Pair(11, 49), Pair(-9, 62), Pair(4, 53), Pair(-6, 44), Pair(4, 60), Pair(-6, 44), Pair(-7, 46), Pair(-25, 19),
        Pair(14, 55), Pair(8, 52), Pair(-2, 47), Pair(10, 61), Pair(-2, 51), Pair(17, 36), Pair(0, 0), Pair(7, 42),
        Pair(23, 51), Pair(1, 39), Pair(14, 60), Pair(-1, 49), Pair(23, 36), Pair(-14, 38), Pair(30, 72), Pair(0, 0)
      },
      { // Piece 3
        Pair(19, 85), Pair(18, 80), Pair(31, 74), Pair(32, 78), Pair(11, 90), Pair(39, 83), Pair(40, 50), Pair(-31, 106),
        Pair(10, 87), Pair(1, 93), Pair(17, 82), Pair(-6, 87), Pair(15, 92), Pair(-6, 96), Pair(8, 59), Pair(-17, 96),
        Pair(4, 93), Pair(15, 89), Pair(2, 94), Pair(6, 85), Pair(-11, 102), Pair(23, 87), Pair(33, 49), Pair(7, 89),
        Pair(15, 89), Pair(12, 86), Pair(5, 82), Pair(10, 85), Pair(7, 84), Pair(10, 85), Pair(46, 58), Pair(-10, 96),
        Pair(19, 87), Pair(14, 91), Pair(13, 94), Pair(20, 87), Pair(19, 86), Pair(20, 79), Pair(38, 59), Pair(-7, 90),
        Pair(18, 89), Pair(6, 90), Pair(2, 98), Pair(-1, 88), Pair(7, 79), Pair(-7, 102), Pair(45, 24), Pair(-26, 76),
        Pair(16, 76), Pair(16, 77), Pair(4, 91), Pair(0, 97), Pair(8, 84), Pair(-9, 92), Pair(0, 0), Pair(-78, 80),
        Pair(10, 90), Pair(17, 80), Pair(14, 83), Pair(14, 79), Pair(10, 88), Pair(2, 87), Pair(-19, 38), Pair(-20, 71)
      },
      { // Piece 4
        Pair(2, 143), Pair(48, 122), Pair(-12, 146), Pair(46, 126), Pair(42, 103), Pair(23, 158), Pair(0, 149), Pair(-5, 140),
        Pair(-2, 156), Pair(-1, 143), Pair(1, 160), Pair(24, 137), Pair(24, 140), Pair(24, 147), Pair(-2, 148), Pair(9, 132),
        Pair(13, 146), Pair(5, 156), Pair(10, 127), Pair(6, 152), Pair(-15, 152), Pair(14, 142), Pair(9, 151), Pair(-22, 171),
        Pair(4, 154), Pair(8, 147), Pair(13, 138), Pair(15, 124), Pair(12, 138), Pair(-18, 137), Pair(-8, 163), Pair(-8, 130),
        Pair(19, 161), Pair(24, 146), Pair(16, 150), Pair(8, 141), Pair(18, 123), Pair(-6, 159), Pair(11, 137), Pair(1, 151),
        Pair(21, 130), Pair(30, 148), Pair(13, 162), Pair(21, 142), Pair(24, 148), Pair(17, 129), Pair(1, 142), Pair(-19, 159),
        Pair(43, 134), Pair(28, 146), Pair(20, 161), Pair(22, 151), Pair(20, 145), Pair(17, 144), Pair(0, 0), Pair(-10, 195),
        Pair(17, 171), Pair(34, 157), Pair(31, 163), Pair(23, 158), Pair(20, 176), Pair(4, 162), Pair(32, 153), Pair(-2, 31)
      },
      { // Piece 5
        Pair(0, 54), Pair(-203, 72), Pair(-127, 26), Pair(-14, 51), Pair(7, 35), Pair(14, 60), Pair(-58, 54), Pair(-115, 151),
        Pair(-212, -42), Pair(-65, 39), Pair(-99, 62), Pair(-92, 36), Pair(-71, 29), Pair(-81, 87), Pair(-135, 75), Pair(3, 19),
        Pair(-153, 38), Pair(-32, 34), Pair(39, 13), Pair(-204, 70), Pair(-156, 59), Pair(-67, 64), Pair(-64, 52), Pair(-125, 46),
        Pair(-110, 21), Pair(-86, 29), Pair(-44, 41), Pair(-152, 62), Pair(-102, 65), Pair(-19, 45), Pair(0, 46), Pair(-27, 50),
        Pair(-59, 37), Pair(-131, 44), Pair(-80, 48), Pair(-42, 39), Pair(-82, 40), Pair(-26, 27), Pair(-9, 25), Pair(26, 17),
        Pair(-107, 22), Pair(-24, 25), Pair(-53, 33), Pair(-27, 40), Pair(7, 12), Pair(-39, 4), Pair(-28, -1), Pair(-14, -13),
        Pair(-49, -9), Pair(-21, 16), Pair(-17, 16), Pair(-2, 16), Pair(15, 4), Pair(-7, -7), Pair(0, 0), Pair(13, -11),
        Pair(-40, -30), Pair(-13, -4), Pair(-21, 13), Pair(-8, 2), Pair(41, -9), Pair(-6, 0), Pair(13, -8), Pair(-3, -16)
      }
    }},
    {{ // Bucket 55
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-11, 32), Pair(-10, 27), Pair(-22, 35), Pair(-11, 20), Pair(-29, 33), Pair(-11, 12), Pair(-26, -5), Pair(14, 13),
        Pair(-6, 24), Pair(-12, 25), Pair(5, 26), Pair(-3, 15), Pair(-12, 15), Pair(-11, 11), Pair(-7, 8), Pair(-9, 5),
        Pair(-2, 24), Pair(0, 12), Pair(0, 17), Pair(3, 10), Pair(-5, 14), Pair(-7, 13), Pair(-12, 19), Pair(4, 10),
        Pair(-3, 25), Pair(1, 23), Pair(0, 15), Pair(2, 15), Pair(-2, 10), Pair(-2, 11), Pair(-2, 16), Pair(7, 6),
        Pair(-4, 16), Pair(0, 23), Pair(-1, 19), Pair(-1, 15), Pair(3, 13), Pair(5, 10), Pair(8, 25), Pair(-9, 1),
        Pair(-6, 17), Pair(-3, 23), Pair(3, 23), Pair(7, 18), Pair(6, 17), Pair(-6, 13), Pair(-3, 7), Pair(3, -8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(71, 19), Pair(116, 63), Pair(-19, 53), Pair(23, 60), Pair(40, 57), Pair(36, 52), Pair(27, 34), Pair(-26, 34),
        Pair(12, 82), Pair(6, 72), Pair(9, 68), Pair(-22, 78), Pair(-18, 69), Pair(-54, 77), Pair(10, 77), Pair(-5, 39),
        Pair(-21, 84), Pair(11, 70), Pair(9, 64), Pair(1, 75), Pair(-1, 70), Pair(-29, 61), Pair(-2, 62), Pair(-23, 50),
        Pair(10, 71), Pair(9, 71), Pair(-2, 79), Pair(-5, 80), Pair(-7, 75), Pair(-17, 74), Pair(-8, 65), Pair(9, 50),
        Pair(12, 63), Pair(0, 95), Pair(8, 77), Pair(9, 68), Pair(0, 76), Pair(-7, 74), Pair(7, 70), Pair(-8, 52),
        Pair(11, 89), Pair(11, 71), Pair(9, 71), Pair(4, 76), Pair(4, 73), Pair(3, 53), Pair(14, 67), Pair(-3, 45),
        Pair(2, 71), Pair(0, 69), Pair(19, 70), Pair(9, 69), Pair(7, 66), Pair(2, 68), Pair(-9, 62), Pair(0, 0),
        Pair(-44, 98), Pair(13, 84), Pair(-6, 88), Pair(19, 61), Pair(4, 63), Pair(1, 50), Pair(24, 37), Pair(-6, 42)
      },
      { // Piece 2
        Pair(24, 35), Pair(67, 29), Pair(12, 45), Pair(10, 49), Pair(130, 15), Pair(-3, 62), Pair(-1, 68), Pair(29, 68),
        Pair(1, 57), Pair(-6, 56), Pair(15, 47), Pair(40, 39), Pair(5, 40), Pair(9, 47), Pair(-1, 65), Pair(-28, 52),
        Pair(17, 48), Pair(6, 58), Pair(29, 50), Pair(20, 38), Pair(13, 48), Pair(30, 55), Pair(-13, 68), Pair(-8, 54),
        Pair(3, 62), Pair(17, 51), Pair(12, 52), Pair(14, 55), Pair(-2, 55), Pair(11, 63), Pair(7, 75), Pair(21, 57),
        Pair(21, 48), Pair(11, 62), Pair(14, 58), Pair(13, 65), Pair(4, 59), Pair(-2, 60), Pair(16, 67), Pair(1, 51),
        Pair(10, 67), Pair(3, 66), Pair(5, 68), Pair(10, 62), Pair(5, 71), Pair(0, 64), Pair(6, 69), Pair(-1, 39),
        Pair(7, 30), Pair(7, 72), Pair(14, 56), Pair(8, 62), Pair(9, 67), Pair(11, 73), Pair(8, 49), Pair(0, 0),
        Pair(25, 52), Pair(14, 59), Pair(11, 65), Pair(6, 57), Pair(11, 61), Pair(8, 64), Pair(50, 54), Pair(12, 66)
      },
      { // Piece 3
        Pair(0, 121), Pair(22, 108), Pair(16, 113), Pair(-15, 119), Pair(-2, 115), Pair(-33, 120), Pair(27, 100), Pair(38, 58),
        Pair(8, 115), Pair(6, 116), Pair(11, 119), Pair(5, 113), Pair(-17, 112), Pair(-14, 109), Pair(-34, 128), Pair(25, 64),
        Pair(5, 123), Pair(5, 124), Pair(14, 119), Pair(3, 116), Pair(-5, 114), Pair(-11, 101), Pair(18, 113), Pair(36, 79),
        Pair(15, 114), Pair(8, 116), Pair(14, 114), Pair(35, 107), Pair(-2, 112), Pair(14, 113), Pair(-11, 116), Pair(17, 87),
        Pair(19, 119), Pair(10, 106), Pair(15, 117), Pair(11, 119), Pair(12, 115), Pair(10, 110), Pair(-16, 128), Pair(26, 75),
        Pair(16, 111), Pair(-8, 121), Pair(10, 104), Pair(-7, 123), Pair(6, 113), Pair(-12, 118), Pair(5, 123), Pair(37, 54),
        Pair(10, 123), Pair(26, 111), Pair(11, 113), Pair(13, 111), Pair(3, 116), Pair(10, 106), Pair(9, 94), Pair(0, 0),
        Pair(20, 107), Pair(22, 110), Pair(16, 106), Pair(18, 98), Pair(18, 104), Pair(18, 108), Pair(-12, 117), Pair(-9, 53)
      },
      { // Piece 4
        Pair(1, 199), Pair(5, 181), Pair(11, 185), Pair(37, 169), Pair(16, 202), Pair(-8, 175), Pair(-10, 242), Pair(-31, 184),
        Pair(8, 181), Pair(16, 176), Pair(25, 154), Pair(11, 204), Pair(-22, 215), Pair(-19, 217), Pair(-30, 253), Pair(-28, 185),
        Pair(12, 200), Pair(12, 182), Pair(9, 182), Pair(32, 161), Pair(6, 190), Pair(12, 210), Pair(19, 194), Pair(-21, 196),
        Pair(6, 193), Pair(22, 159), Pair(14, 182), Pair(12, 191), Pair(-14, 213), Pair(-7, 181), Pair(-3, 194), Pair(-1, 167),
        Pair(13, 184), Pair(22, 174), Pair(16, 187), Pair(17, 182), Pair(2, 188), Pair(-10, 200), Pair(4, 188), Pair(-8, 194),
        Pair(20, 192), Pair(24, 186), Pair(14, 188), Pair(16, 185), Pair(12, 178), Pair(-1, 179), Pair(1, 187), Pair(-13, 194),
        Pair(32, 185), Pair(17, 207), Pair(21, 193), Pair(20, 189), Pair(11, 187), Pair(-3, 188), Pair(1, 210), Pair(0, 0),
        Pair(34, 164), Pair(15, 210), Pair(23, 198), Pair(17, 208), Pair(15, 181), Pair(14, 156), Pair(41, 148), Pair(13, 68)
      },
      { // Piece 5
        Pair(-25, -35), Pair(-261, 70), Pair(-118, 25), Pair(102, 13), Pair(11, 45), Pair(-64, 113), Pair(35, 36), Pair(-73, 86),
        Pair(63, -30), Pair(-98, 41), Pair(111, 5), Pair(-209, 53), Pair(-119, 54), Pair(-7, 58), Pair(-96, 87), Pair(-93, 70),
        Pair(-200, 28), Pair(-90, 40), Pair(16, 32), Pair(-11, 21), Pair(-115, 79), Pair(-8, 61), Pair(-66, 63), Pair(-151, 84),
        Pair(-101, 35), Pair(-124, 50), Pair(-48, 40), Pair(-92, 45), Pair(-135, 60), Pair(-62, 67), Pair(6, 54), Pair(-8, 55),
        Pair(-174, 34), Pair(-87, 44), Pair(-138, 64), Pair(-53, 53), Pair(-60, 43), Pair(-15, 32), Pair(24, 13), Pair(13, 24),
        Pair(-96, 35), Pair(-81, 57), Pair(-65, 50), Pair(-37, 36), Pair(-8, 25), Pair(-1, 15), Pair(-21, -13), Pair(-10, -3),
        Pair(-15, 13), Pair(-51, 45), Pair(-35, 38), Pair(-37, 36), Pair(2, 14), Pair(3, 10), Pair(-28, -29), Pair(0, 0),
        Pair(-40, -15), Pair(-21, 16), Pair(-10, 22), Pair(-2, 8), Pair(32, -16), Pair(6, 0), Pair(2, -27), Pair(27, -41)
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
    {Pair(-232, -28), Pair(-21, -67), Pair(-138, -34), Pair(-46, -35), Pair(6, -65), Pair(-15, -6), Pair(48, -72), Pair(-18, -27), Pair(-81, -33), Pair(-93, -31), Pair(13, -18), Pair(225, -55), Pair(188, -62), Pair(179, -90), Pair(5, -46), Pair(111, -61), Pair(-95, -48), Pair(-66, -25), Pair(35, 7), Pair(103, -2), Pair(163, -32), Pair(214, -36), Pair(94, -41), Pair(155, -77), Pair(-65, -27), Pair(-12, -18), Pair(47, 9), Pair(112, 11), Pair(136, 14), Pair(162, -31), Pair(120, -23), Pair(79, -19), Pair(-86, -50), Pair(-31, -21), Pair(24, 14), Pair(49, 28), Pair(112, -6), Pair(101, 11), Pair(123, -32), Pair(53, -10), Pair(-115, -65), Pair(-61, -5), Pair(-15, 12), Pair(2, 15), Pair(15, 26), Pair(13, 46), Pair(19, 17), Pair(-29, -12), Pair(-149, -36), Pair(-117, -36), Pair(-64, -10), Pair(-51, 4), Pair(-37, 13), Pair(-37, 24), Pair(-56, 20), Pair(-67, -5), Pair(-202, -102), Pair(-146, -122), Pair(-153, -7), Pair(-117, -1), Pair(-86, -15), Pair(-51, -8), Pair(-105, -32), Pair(-114, -34)},
    {Pair(-21, -18), Pair(-121, 40), Pair(-79, 14), Pair(-141, 1), Pair(-42, 8), Pair(-16, -11), Pair(-30, 2), Pair(-63, 22), Pair(-35, 7), Pair(-19, -7), Pair(-69, 21), Pair(27, -8), Pair(-7, -9), Pair(0, -17), Pair(48, -23), Pair(-17, -6), Pair(-32, -27), Pair(-25, -7), Pair(27, 0), Pair(20, 25), Pair(31, 16), Pair(139, -46), Pair(64, -18), Pair(45, 2), Pair(-51, -16), Pair(-8, 11), Pair(8, -5), Pair(95, -1), Pair(87, 5), Pair(86, -16), Pair(37, -4), Pair(25, -13), Pair(-65, -16), Pair(-6, -2), Pair(47, 7), Pair(55, 9), Pair(103, 3), Pair(43, 12), Pair(28, -12), Pair(18, -1), Pair(-41, -19), Pair(22, -11), Pair(19, 5), Pair(25, 16), Pair(19, 8), Pair(17, 31), Pair(36, 7), Pair(27, 4), Pair(-12, -47), Pair(-10, 4), Pair(7, -14), Pair(-21, 11), Pair(-27, 17), Pair(-16, -3), Pair(30, 28), Pair(1, -4), Pair(-6, -27), Pair(18, -22), Pair(-50, -11), Pair(-67, 1), Pair(-68, 8), Pair(-40, -8), Pair(-48, -11), Pair(-9, -36)},
    {Pair(73, 13), Pair(31, 10), Pair(48, 18), Pair(45, 2), Pair(122, -16), Pair(37, 14), Pair(63, 7), Pair(116, -10), Pair(42, -1), Pair(59, -8), Pair(70, -19), Pair(101, -20), Pair(88, -17), Pair(71, -37), Pair(48, -6), Pair(132, -38), Pair(30, -22), Pair(69, -23), Pair(67, -24), Pair(120, -37), Pair(124, -38), Pair(149, -53), Pair(116, -20), Pair(66, -43), Pair(-19, -3), Pair(30, -2), Pair(32, -5), Pair(58, -14), Pair(70, -7), Pair(94, -23), Pair(75, -17), Pair(55, -3), Pair(-41, 12), Pair(0, 7), Pair(-2, 12), Pair(15, 0), Pair(17, 2), Pair(63, 3), Pair(51, 4), Pair(54, -9), Pair(-55, 16), Pair(0, 16), Pair(-13, 23), Pair(-2, 6), Pair(13, 15), Pair(41, 8), Pair(48, 29), Pair(17, 8), Pair(-81, -11), Pair(-35, -2), Pair(-10, -1), Pair(-12, 0), Pair(-6, 10), Pair(24, 3), Pair(-12, 17), Pair(-56, 0), Pair(-16, 0), Pair(-11, 4), Pair(4, 5), Pair(6, 18), Pair(16, 10), Pair(30, 11), Pair(22, 19), Pair(-48, -2)},
    {Pair(72, -47), Pair(52, -37), Pair(102, -27), Pair(79, -13), Pair(101, -32), Pair(58, -39), Pair(123, -133), Pair(197, -126), Pair(33, -2), Pair(-10, 27), Pair(60, 6), Pair(71, -5), Pair(100, 5), Pair(99, -14), Pair(50, -23), Pair(154, -85), Pair(2, 10), Pair(16, 38), Pair(32, 76), Pair(61, 82), Pair(107, 37), Pair(153, 32), Pair(143, -18), Pair(120, 19), Pair(-1, 22), Pair(25, 23), Pair(22, 65), Pair(16, 121), Pair(80, 88), Pair(117, 43), Pair(116, 39), Pair(114, 48), Pair(-3, -19), Pair(0, 28), Pair(25, 77), Pair(30, 109), Pair(51, 95), Pair(74, 70), Pair(67, 52), Pair(112, -6), Pair(-15, -37), Pair(6, 42), Pair(16, 69), Pair(14, 64), Pair(17, 58), Pair(36, 74), Pair(49, 22), Pair(63, -16), Pair(-42, -29), Pair(-16, 21), Pair(1, 24), Pair(-2, 50), Pair(5, 39), Pair(-3, 33), Pair(4, -33), Pair(-22, -21), Pair(-9, 10), Pair(-44, 20), Pair(-40, 2), Pair(-11, -2), Pair(-22, 7), Pair(-34, -20), Pair(-11, -72), Pair(-21, 33)},
    {Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(-113, 67), Pair(9, 16), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(-4, -3), Pair(-34, -15)}
  }},
  {{
    {Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)},
    {Pair(-171, -90), Pair(-175, -24), Pair(-209, -11), Pair(-169, -7), Pair(-48, -56), Pair(-103, -39), Pair(-33, -4), Pair(-23, -101), Pair(-49, -51), Pair(-90, -35), Pair(21, -57), Pair(74, -4), Pair(121, -55), Pair(132, -63), Pair(-37, -27), Pair(61, -77), Pair(-82, -63), Pair(-49, -17), Pair(26, 16), Pair(103, -24), Pair(129, -15), Pair(176, -48), Pair(89, -47), Pair(105, -52), Pair(-64, -22), Pair(-9, -14), Pair(42, 3), Pair(104, -1), Pair(125, 1), Pair(150, -38), Pair(113, -38), Pair(77, -47), Pair(-74, -45), Pair(-36, -14), Pair(34, 8), Pair(49, 15), Pair(103, -25), Pair(100, -9), Pair(98, -35), Pair(41, -12), Pair(-113, -40), Pair(-55, -9), Pair(-4, 10), Pair(-11, 21), Pair(17, 15), Pair(16, 41), Pair(10, -11), Pair(-41, -19), Pair(-117, -62), Pair(-94, -29), Pair(-52, 4), Pair(-48, -2), Pair(-29, 16), Pair(-32, 38), Pair(-58, 14), Pair(-81, -60), Pair(-216, -32), Pair(-144, -93), Pair(-145, -7), Pair(-97, 1), Pair(-87, 3), Pair(-80, -9), Pair(-115, -40), Pair(-85, -81)},
    {Pair(-29, -31), Pair(-109, 10), Pair(-147, 5), Pair(-223, 11), Pair(-210, 27), Pair(-144, 15), Pair(-157, 3), Pair(-85, -2), Pair(-18, -14), Pair(-47, -2), Pair(-66, -1), Pair(-103, 16), Pair(-118, 27), Pair(-29, 20), Pair(6, -19), Pair(-10, 11), Pair(-48, -17), Pair(-31, -6), Pair(-10, 19), Pair(6, 37), Pair(7, -7), Pair(95, -37), Pair(28, -30), Pair(23, -1), Pair(-54, -1), Pair(0, -8), Pair(-27, 22), Pair(78, 6), Pair(78, -1), Pair(74, -17), Pair(27, -23), Pair(34, -27), Pair(-53, -25), Pair(-11, -5), Pair(58, -5), Pair(57, 11), Pair(89, 9), Pair(43, 1), Pair(15, -24), Pair(21, -30), Pair(-40, -8), Pair(30, -10), Pair(23, 10), Pair(32, 12), Pair(27, 14), Pair(25, 19), Pair(23, 7), Pair(-2, -17), Pair(11, -52), Pair(2, 6), Pair(19, -9), Pair(-15, 18), Pair(-18, 16), Pair(-15, 15), Pair(9, 12), Pair(-17, -11), Pair(4, -30), Pair(6, -14), Pair(-60, 10), Pair(-66, 9), Pair(-65, 7), Pair(-65, -12), Pair(-78, -15), Pair(-36, -37)},
    {Pair(-3, 30), Pair(12, 10), Pair(-66, 45), Pair(-22, 21), Pair(12, 16), Pair(-102, 41), Pair(-2, 47), Pair(5, 30), Pair(44, -4), Pair(56, -17), Pair(43, -24), Pair(64, -18), Pair(75, -18), Pair(22, -25), Pair(37, -27), Pair(98, -22), Pair(40, -28), Pair(36, -22), Pair(48, -20), Pair(87, -35), Pair(101, -43), Pair(74, -27), Pair(83, -23), Pair(30, -21), Pair(-31, 6), Pair(16, -8), Pair(-20, -2), Pair(20, -9), Pair(25, 6), Pair(75, -21), Pair(40, -4), Pair(51, -9), Pair(-55, 23), Pair(-29, 7), Pair(-20, 12), Pair(-16, 0), Pair(17, -7), Pair(64, -14), Pair(6, 26), Pair(37, 7), Pair(-72, 16), Pair(-16, 13), Pair(-40, 34), Pair(-19, 6), Pair(3, 6), Pair(11, 12), Pair(39, 8), Pair(16, 18), Pair(-111, 0), Pair(-43, 8), Pair(-26, 6), Pair(-37, -2), Pair(-14, -9), Pair(-14, 32), Pair(-43, 13), Pair(-48, -18), Pair(-21, -21), Pair(-28, -10), Pair(-16, -4), Pair(-8, 6), Pair(8, -11), Pair(-17, -8), Pair(-8, -24), Pair(-17, -43)},
    {Pair(54, -57), Pair(59, -51), Pair(36, -3), Pair(31, 10), Pair(52, 21), Pair(-2, -24), Pair(102, -132), Pair(43, -27), Pair(6, -39), Pair(-30, 1), Pair(30, -9), Pair(15, 9), Pair(33, 25), Pair(60, -50), Pair(16, -57), Pair(97, -74), Pair(-11, -11), Pair(25, -15), Pair(6, 55), Pair(26, 42), Pair(60, 22), Pair(91, 28), Pair(123, -65), Pair(107, -51), Pair(-17, -11), Pair(-4, 2), Pair(-14, 67), Pair(-7, 96), Pair(49, 63), Pair(70, 59), Pair(87, -38), Pair(85, -15), Pair(-26, -20), Pair(-35, 11), Pair(10, 52), Pair(-6, 144), Pair(17, 96), Pair(54, 42), Pair(28, 22), Pair(72, -41), Pair(-44, -61), Pair(-17, 8), Pair(-13, 57), Pair(-7, 33), Pair(-20, 56), Pair(6, 80), Pair(8, 30), Pair(33, -21), Pair(-55, -99), Pair(-41, -50), Pair(-20, -5), Pair(-28, 21), Pair(-29, 15), Pair(-28, -7), Pair(-32, -18), Pair(-38, -63), Pair(-17, -84), Pair(-69, -98), Pair(-61, -81), Pair(-41, -49), Pair(-62, -39), Pair(-82, -36), Pair(-23, -114), Pair(-3, -69)},
    {Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(9, -7), Pair(-69, -7), Pair(-15, -14), Pair(-66, 23), Pair(0, 0), Pair(0, 0)}
  }},
  {{
    {Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)},
    {Pair(-297, -4), Pair(-91, -29), Pair(-153, -16), Pair(-39, -33), Pair(-38, -29), Pair(-2, -6), Pair(-64, 0), Pair(-83, -13), Pair(-96, -36), Pair(-119, -19), Pair(-24, -18), Pair(203, -34), Pair(193, -52), Pair(132, -60), Pair(16, -42), Pair(81, -44), Pair(-100, -53), Pair(-53, -22), Pair(37, 9), Pair(102, -5), Pair(151, -23), Pair(224, -39), Pair(117, -41), Pair(142, -74), Pair(-80, -10), Pair(-17, -12), Pair(40, 7), Pair(118, 9), Pair(147, -5), Pair(173, -33), Pair(131, -37), Pair(98, -43), Pair(-90, -41), Pair(-40, -16), Pair(16, 15), Pair(52, 16), Pair(106, -9), Pair(104, 4), Pair(140, -38), Pair(62, -21), Pair(-133, -37), Pair(-69, 11), Pair(-18, 18), Pair(-4, 26), Pair(20, 25), Pair(18, 44), Pair(21, 16), Pair(-29, -4), Pair(-151, -56), Pair(-117, -10), Pair(-67, 3), Pair(-56, 5), Pair(-35, 18), Pair(-33, 21), Pair(-42, 5), Pair(-64, -25), Pair(-188, -81), Pair(-156, -98), Pair(-164, 7), Pair(-131, 5), Pair(-105, -9), Pair(-87, -2), Pair(-108, -32), Pair(-95, -63)},
    {Pair(-78, 7), Pair(-116, 9), Pair(-72, 9), Pair(-169, 22), Pair(-45, 11), Pair(-89, 27), Pair(-85, 1), Pair(-112, 34), Pair(-57, 4), Pair(-28, -11), Pair(-71, 8), Pair(14, -1), Pair(-12, -9), Pair(-50, 12), Pair(16, -10), Pair(-29, 4), Pair(-39, -29), Pair(-45, -10), Pair(-4, 14), Pair(16, 19), Pair(57, 0), Pair(136, -35), Pair(44, -19), Pair(52, -9), Pair(-79, -1), Pair(-17, 3), Pair(3, 4), Pair(89, -2), Pair(89, -1), Pair(97, -26), Pair(30, -3), Pair(25, -18), Pair(-73, -11), Pair(-8, -4), Pair(49, 3), Pair(51, 15), Pair(95, -1), Pair(50, 10), Pair(35, -20), Pair(30, -12), Pair(-43, -15), Pair(21, -6), Pair(15, 5), Pair(23, 8), Pair(24, 13), Pair(14, 22), Pair(35, 10), Pair(26, -22), Pair(-34, -39), Pair(-12, 1), Pair(6, -15), Pair(-22, 14), Pair(-33, 17), Pair(-18, -3), Pair(34, 2), Pair(5, 0), Pair(-16, -20), Pair(-5, -25), Pair(-57, -6), Pair(-56, -2), Pair(-90, 12), Pair(-64, -15), Pair(-38, -32), Pair(-55, -10)},
    {Pair(45, 25), Pair(15, 17), Pair(51, 13), Pair(67, -3), Pair(85, 1), Pair(113, -15), Pair(41, 28), Pair(64, 12), Pair(23, 7), Pair(51, -10), Pair(81, -26), Pair(110, -22), Pair(91, -16), Pair(71, -28), Pair(35, -1), Pair(120, -25), Pair(18, -4), Pair(52, -10), Pair(52, -9), Pair(101, -29), Pair(125, -35), Pair(132, -40), Pair(129, -22), Pair(59, -15), Pair(-35, 18), Pair(4, 4), Pair(6, 9), Pair(47, -7), Pair(55, -7), Pair(93, -18), Pair(44, 7), Pair(52, 12), Pair(-59, 30), Pair(-12, 19), Pair(-11, 22), Pair(-4, 15), Pair(6, 15), Pair(66, 8), Pair(23, 28), Pair(33, 16), Pair(-65, 27), Pair(-35, 24), Pair(-17, 16), Pair(-7, 8), Pair(-5, 14), Pair(23, 17), Pair(33, 41), Pair(26, 14), Pair(-110, 2), Pair(-49, 8), Pair(-9, -8), Pair(-26, 0), Pair(-20, 10), Pair(24, -4), Pair(-24, 22), Pair(-97, 18), Pair(-34, 9), Pair(-34, 23), Pair(-19, 16), Pair(-17, 27), Pair(-3, 16), Pair(10, 11), Pair(-2, 20), Pair(-34, 6)},
    {Pair(44, -46), Pair(43, -37), Pair(93, -42), Pair(121, -69), Pair(81, -19), Pair(119, -88), Pair(140, -147), Pair(157, -128), Pair(-15, -2), Pair(-22, -1), Pair(24, 16), Pair(68, -12), Pair(93, -2), Pair(90, -48), Pair(15, -26), Pair(124, -84), Pair(-8, -14), Pair(3, 13), Pair(18, 67), Pair(46, 66), Pair(99, 33), Pair(170, 7), Pair(137, -47), Pair(113, -44), Pair(-27, -7), Pair(-1, 27), Pair(-4, 67), Pair(6, 109), Pair(56, 93), Pair(121, 33), Pair(100, 14), Pair(113, 3), Pair(-5, -64), Pair(-34, 31), Pair(8, 78), Pair(19, 107), Pair(23, 92), Pair(66, 61), Pair(62, 25), Pair(93, -40), Pair(-43, -58), Pair(-12, 26), Pair(-7, 61), Pair(-4, 51), Pair(-6, 48), Pair(20, 54), Pair(30, -1), Pair(27, -32), Pair(-46, -62), Pair(-30, -10), Pair(-14, 0), Pair(-17, 19), Pair(-18, 20), Pair(-32, 33), Pair(-25, -53), Pair(-20, -93), Pair(-35, 4), Pair(-90, 27), Pair(-64, -7), Pair(-32, -19), Pair(-45, -6), Pair(-60, -28), Pair(-41, -12), Pair(-12, -79)},
    {Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(28, -37), Pair(40, -10), Pair(-21, -2), Pair(-69, -6), Pair(-73, 4), Pair(-71, 25), Pair(-5, 9), Pair(8, -11), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)}
  }},
  {{
    {Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)},
    {Pair(-248, -49), Pair(-75, -21), Pair(-137, -18), Pair(-23, -46), Pair(-113, -13), Pair(13, -31), Pair(65, -35), Pair(-22, -31), Pair(-65, -45), Pair(-106, -11), Pair(-61, -12), Pair(137, -24), Pair(135, -42), Pair(114, -55), Pair(-23, -18), Pair(37, -38), Pair(-82, -54), Pair(-43, -17), Pair(44, 4), Pair(73, 11), Pair(168, -15), Pair(180, -21), Pair(114, -33), Pair(168, -72), Pair(-70, -11), Pair(-18, -16), Pair(34, 9), Pair(122, 7), Pair(156, -5), Pair(138, -17), Pair(156, -51), Pair(74, -32), Pair(-81, -37), Pair(-63, -8), Pair(31, 18), Pair(76, 13), Pair(118, -10), Pair(103, 13), Pair(137, -35), Pair(46, -19), Pair(-169, -18), Pair(-64, 10), Pair(-23, 23), Pair(-6, 22), Pair(18, 27), Pair(62, 16), Pair(17, 22), Pair(-29, -11), Pair(-203, -35), Pair(-135, -11), Pair(-104, 8), Pair(-64, 12), Pair(-33, 22), Pair(-21, 10), Pair(-49, 13), Pair(-37, -48), Pair(-99, -50), Pair(-147, -99), Pair(-142, 22), Pair(-153, -1), Pair(-153, -1), Pair(-173, -1), Pair(-127, -46), Pair(-79, -33)},
    {Pair(-134, 5), Pair(-140, 16), Pair(-57, 1), Pair(-131, 1), Pair(-50, 2), Pair(-146, 7), Pair(-27, -6), Pair(-149, 21), Pair(-82, 11), Pair(-56, -8), Pair(-114, 14), Pair(-5, -7), Pair(-58, -7), Pair(-35, -4), Pair(-5, -11), Pair(-68, 7), Pair(-27, -26), Pair(-43, -21), Pair(-9, -2), Pair(39, 14), Pair(38, 7), Pair(103, -32), Pair(33, -15), Pair(18, -11), Pair(-95, -1), Pair(-5, -7), Pair(23, -3), Pair(93, -11), Pair(109, -7), Pair(64, -22), Pair(47, -9), Pair(-1, -18), Pair(-101, -4), Pair(-8, -11), Pair(63, -9), Pair(69, 9), Pair(114, -2), Pair(62, 7), Pair(53, -21), Pair(43, -22), Pair(-59, -10), Pair(6, -4), Pair(-4, 13), Pair(32, 1), Pair(16, 19), Pair(27, 13), Pair(30, 2), Pair(24, -20), Pair(-16, -50), Pair(-24, -2), Pair(-5, -14), Pair(-18, 8), Pair(-24, 4), Pair(-23, -12), Pair(-5, 21), Pair(3, -21), Pair(-73, -1), Pair(-16, -15), Pair(-57, -3), Pair(-90, 15), Pair(-79, 2), Pair(-86, -3), Pair(-44, -25), Pair(-78, -7)},
    {Pair(43, 24), Pair(14, 9), Pair(0, 26), Pair(51, -6), Pair(89, -10), Pair(153, -28), Pair(74, 15), Pair(36, 19), Pair(48, -7), Pair(58, -13), Pair(57, -17), Pair(141, -38), Pair(100, -25), Pair(103, -42), Pair(108, -22), Pair(108, -19), Pair(2, 2), Pair(20, -4), Pair(45, -11), Pair(110, -34), Pair(91, -25), Pair(90, -22), Pair(84, -8), Pair(9, -4), Pair(-46, 22), Pair(-14, 14), Pair(4, 9), Pair(39, -1), Pair(32, 3), Pair(75, -13), Pair(45, 13), Pair(42, 20), Pair(-58, 29), Pair(-37, 24), Pair(-23, 19), Pair(-27, 19), Pair(-4, 17), Pair(39, 16), Pair(6, 37), Pair(1, 26), Pair(-102, 26), Pair(-28, 22), Pair(-63, 28), Pair(-30, 7), Pair(-23, 18), Pair(-11, 20), Pair(19, 24), Pair(-60, 36), Pair(-161, 24), Pair(-85, 11), Pair(-39, 5), Pair(-46, 6), Pair(-58, 23), Pair(5, -3), Pair(-53, 25), Pair(-144, 44), Pair(-58, 15), Pair(-46, 22), Pair(-29, 22), Pair(-31, 30), Pair(-21, 18), Pair(-13, 16), Pair(-35, 33), Pair(-45, 11)},
    {Pair(-70, -30), Pair(-47, -60), Pair(3, -46), Pair(73, -103), Pair(-17, -16), Pair(48, -118), Pair(-33, -123), Pair(2, -132), Pair(-124, -25), Pair(-158, -9), Pair(-65, 23), Pair(-46, -7), Pair(19, 6), Pair(27, -46), Pair(-139, 5), Pair(50, -135), Pair(-104, -13), Pair(-121, 21), Pair(-37, 47), Pair(-27, 70), Pair(47, 24), Pair(99, -21), Pair(87, -54), Pair(80, -112), Pair(-177, 27), Pair(-135, 45), Pair(-99, 86), Pair(-82, 128), Pair(10, 59), Pair(84, 3), Pair(19, 1), Pair(36, -45), Pair(-87, -85), Pair(-139, 18), Pair(-75, 78), Pair(-65, 116), Pair(3, 48), Pair(0, 39), Pair(-6, -17), Pair(-15, -48), Pair(-155, -63), Pair(-108, -4), Pair(-85, 32), Pair(-95, 27), Pair(-84, 45), Pair(-76, 67), Pair(-18, -78), Pair(-2, -93), Pair(-73, -95), Pair(-128, -21), Pair(-85, -21), Pair(-85, -1), Pair(-86, 15), Pair(-93, 8), Pair(-73, -38), Pair(-97, -94), Pair(-139, -29), Pair(-103, -80), Pair(-126, -51), Pair(-86, -73), Pair(-150, -20), Pair(-139, -39), Pair(-137, 13), Pair(-75, -87)},
    {Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(-27, -57), Pair(72, -24), Pair(76, -24), Pair(1, -15), Pair(-1, 0), Pair(39, 0), Pair(43, -6), Pair(-45, -11), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)}
  }},
  {{
    {Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)},
    {Pair(-183, -60), Pair(12, -88), Pair(-193, -51), Pair(33, -50), Pair(30, -64), Pair(-134, -15), Pair(107, -40), Pair(-136, -95), Pair(-128, -45), Pair(-84, -29), Pair(-44, -25), Pair(164, -48), Pair(137, -48), Pair(52, -58), Pair(-20, -20), Pair(83, -58), Pair(-18, -63), Pair(-36, -35), Pair(33, -3), Pair(93, -10), Pair(139, -17), Pair(212, -36), Pair(120, -33), Pair(160, -80), Pair(-40, -31), Pair(-22, -21), Pair(73, -9), Pair(160, -9), Pair(158, -12), Pair(179, -26), Pair(168, -56), Pair(149, -42), Pair(-101, -34), Pair(-47, -21), Pair(43, -3), Pair(63, 8), Pair(144, -24), Pair(140, -5), Pair(75, -28), Pair(28, -34), Pair(-109, -50), Pair(-119, 8), Pair(-30, 15), Pair(0, 1), Pair(18, 12), Pair(75, 6), Pair(-16, 0), Pair(-25, -20), Pair(-170, -40), Pair(-36, -38), Pair(-108, -13), Pair(-84, -14), Pair(-40, 0), Pair(-57, 4), Pair(-29, -13), Pair(-97, -34), Pair(-92, -84), Pair(-257, -58), Pair(-239, 0), Pair(-50, -22), Pair(-159, -17), Pair(-148, -9), Pair(-282, -33), Pair(-56, -57)},
    {Pair(-91, -45), Pair(-12, -40), Pair(0, -32), Pair(-70, -33), Pair(-1, -24), Pair(-70, -30), Pair(49, -45), Pair(-79, -23), Pair(44, -36), Pair(-20, -41), Pair(2, -44), Pair(-5, -28), Pair(22, -33), Pair(45, -34), Pair(26, -43), Pair(-33, -24), Pair(-22, -50), Pair(3, -48), Pair(101, -32), Pair(109, -13), Pair(135, -40), Pair(141, -59), Pair(108, -52), Pair(70, -30), Pair(-72, -26), Pair(-20, -19), Pair(63, -24), Pair(184, -39), Pair(167, -34), Pair(176, -51), Pair(85, -41), Pair(15, -41), Pair(-54, -24), Pair(28, -37), Pair(91, -36), Pair(129, -22), Pair(147, -21), Pair(68, -21), Pair(72, -45), Pair(62, -31), Pair(-36, -35), Pair(17, -23), Pair(9, -18), Pair(55, -28), Pair(54, -18), Pair(42, -15), Pair(27, -3), Pair(-2, -28), Pair(-2, -65), Pair(-37, -15), Pair(31, -39), Pair(12, -20), Pair(-21, -24), Pair(-36, -34), Pair(31, -21), Pair(97, -84), Pair(-25, -38), Pair(-93, -33), Pair(-106, -9), Pair(-104, -8), Pair(-103, -12), Pair(-101, -23), Pair(0, -66), Pair(74, -60)},
    {Pair(105, -29), Pair(39, -28), Pair(112, -39), Pair(105, -50), Pair(151, -57), Pair(190, -70), Pair(140, -32), Pair(82, -29), Pair(81, -40), Pair(102, -47), Pair(93, -53), Pair(183, -76), Pair(139, -65), Pair(90, -56), Pair(88, -43), Pair(114, -55), Pair(53, -43), Pair(75, -44), Pair(105, -56), Pair(171, -76), Pair(135, -59), Pair(92, -53), Pair(108, -34), Pair(99, -45), Pair(-49, -1), Pair(33, -22), Pair(12, -17), Pair(35, -27), Pair(42, -20), Pair(120, -39), Pair(44, -9), Pair(7, 5), Pair(-44, -13), Pair(-6, -10), Pair(-20, -21), Pair(-19, -23), Pair(-14, -13), Pair(54, -20), Pair(-14, -3), Pair(-85, 10), Pair(-80, -12), Pair(-55, 0), Pair(-98, 8), Pair(-53, -5), Pair(-42, -17), Pair(-52, 0), Pair(-71, 23), Pair(-130, 25), Pair(-205, 0), Pair(-140, -2), Pair(-48, -21), Pair(-106, -10), Pair(-91, 9), Pair(-44, -19), Pair(-99, 21), Pair(-205, 27), Pair(-145, 17), Pair(-104, 17), Pair(-56, -1), Pair(-60, 9), Pair(-64, -4), Pair(-32, -6), Pair(-117, 35), Pair(-124, 5)},
    {Pair(-145, -39), Pair(-109, -89), Pair(-21, -139), Pair(-9, -163), Pair(-96, -68), Pair(-39, -159), Pair(-62, -190), Pair(-187, -74), Pair(-195, -53), Pair(-157, -44), Pair(-125, -23), Pair(-140, -3), Pair(-129, -21), Pair(-199, 1), Pair(-13, -140), Pair(-114, -106), Pair(-101, -85), Pair(-203, 4), Pair(13, -25), Pair(-172, 53), Pair(-7, -58), Pair(23, -10), Pair(-144, -39), Pair(-44, -128), Pair(-235, -3), Pair(-260, 5), Pair(-207, 58), Pair(-190, 106), Pair(-23, 1), Pair(-101, -23), Pair(-95, -75), Pair(55, -167), Pair(-180, -126), Pair(-263, -21), Pair(-248, 54), Pair(-159, 20), Pair(-54, -35), Pair(-111, 1), Pair(-8, -169), Pair(-184, -125), Pair(-282, -142), Pair(-234, -68), Pair(-227, 38), Pair(-181, 15), Pair(-170, 5), Pair(-121, -14), Pair(-208, -64), Pair(-37, -217), Pair(-328, -23), Pair(-213, -41), Pair(-215, -29), Pair(-197, 8), Pair(-222, -16), Pair(-172, -69), Pair(-289, -12), Pair(-245, -105), Pair(-181, -143), Pair(-181, -153), Pair(-137, -159), Pair(-211, -99), Pair(-261, 19), Pair(-213, -60), Pair(-140, -107), Pair(-68, -207)},
    {Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(68, -42), Pair(189, -39), Pair(164, -23), Pair(37, -5), Pair(77, -9), Pair(124, -2), Pair(149, -19), Pair(1, -17), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)}
  }},
  {{
    {Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)},
    {Pair(-54, -107), Pair(181, -126), Pair(-38, -99), Pair(102, -141), Pair(130, -135), Pair(-33, -91), Pair(-80, -83), Pair(64, -146), Pair(50, -146), Pair(46, -119), Pair(45, -91), Pair(174, -86), Pair(-19, -61), Pair(153, -132), Pair(32, -102), Pair(40, -108), Pair(25, -130), Pair(1, -89), Pair(150, -68), Pair(163, -71), Pair(295, -102), Pair(267, -84), Pair(148, -91), Pair(166, -131), Pair(-6, -91), Pair(79, -108), Pair(179, -88), Pair(171, -76), Pair(158, -89), Pair(172, -100), Pair(197, -148), Pair(94, -104), Pair(-107, -101), Pair(42, -84), Pair(115, -83), Pair(125, -76), Pair(193, -111), Pair(190, -85), Pair(172, -120), Pair(27, -93), Pair(-69, -125), Pair(-22, -83), Pair(-9, -69), Pair(34, -67), Pair(16, -76), Pair(4, -68), Pair(13, -92), Pair(-28, -122), Pair(-164, -102), Pair(-168, -76), Pair(2, -99), Pair(-127, -80), Pair(-70, -62), Pair(35, -85), Pair(18, -124), Pair(-35, -108), Pair(39, -181), Pair(-343, -140), Pair(-267, -43), Pair(-142, -99), Pair(-82, -101), Pair(-165, -80), Pair(-238, -88), Pair(3, -154)},
    {Pair(6, -159), Pair(79, -128), Pair(101, -115), Pair(-20, -102), Pair(131, -121), Pair(11, -115), Pair(159, -148), Pair(18, -102), Pair(-33, -115), Pair(19, -130), Pair(142, -127), Pair(190, -139), Pair(174, -133), Pair(207, -126), Pair(94, -116), Pair(69, -125), Pair(1, -166), Pair(260, -170), Pair(159, -119), Pair(255, -115), Pair(228, -129), Pair(229, -152), Pair(325, -172), Pair(119, -118), Pair(101, -124), Pair(148, -130), Pair(255, -132), Pair(236, -137), Pair(281, -125), Pair(351, -182), Pair(242, -134), Pair(95, -116), Pair(6, -100), Pair(176, -133), Pair(237, -132), Pair(351, -149), Pair(378, -167), Pair(243, -130), Pair(180, -141), Pair(21, -83), Pair(66, -127), Pair(195, -134), Pair(115, -122), Pair(263, -161), Pair(194, -126), Pair(122, -113), Pair(219, -120), Pair(-15, -122), Pair(-12, -153), Pair(-1, -111), Pair(171, -157), Pair(57, -126), Pair(82, -116), Pair(25, -130), Pair(-12, -110), Pair(103, -139), Pair(43, -142), Pair(130, -164), Pair(-93, -96), Pair(-13, -101), Pair(-46, -91), Pair(-110, -114), Pair(115, -186), Pair(94, -160)},
    {Pair(167, -141), Pair(193, -169), Pair(383, -212), Pair(240, -186), Pair(249, -190), Pair(299, -189), Pair(144, -121), Pair(213, -136), Pair(128, -152), Pair(142, -157), Pair(222, -180), Pair(262, -196), Pair(212, -178), Pair(118, -154), Pair(119, -134), Pair(172, -158), Pair(72, -143), Pair(89, -155), Pair(164, -169), Pair(171, -183), Pair(173, -169), Pair(186, -164), Pair(168, -146), Pair(108, -146), Pair(29, -118), Pair(59, -140), Pair(31, -133), Pair(81, -150), Pair(41, -131), Pair(110, -138), Pair(66, -116), Pair(51, -109), Pair(8, -121), Pair(-44, -115), Pair(52, -157), Pair(-12, -122), Pair(24, -133), Pair(54, -130), Pair(19, -114), Pair(-33, -102), Pair(-134, -92), Pair(-39, -118), Pair(-29, -129), Pair(-77, -115), Pair(-41, -118), Pair(-18, -115), Pair(-76, -77), Pair(-168, -70), Pair(-218, -80), Pair(-192, -97), Pair(-91, -125), Pair(-142, -107), Pair(-135, -93), Pair(-39, -117), Pair(-101, -84), Pair(-170, -90), Pair(-203, -70), Pair(-239, -72), Pair(-155, -82), Pair(-159, -80), Pair(-132, -85), Pair(-172, -81), Pair(-206, -55), Pair(-316, -50)},
    {Pair(-128, -296), Pair(-198, -273), Pair(-60, -276), Pair(-202, -204), Pair(-130, -261), Pair(-197, -267), Pair(-228, -285), Pair(-176, -295), Pair(-226, -246), Pair(-347, -194), Pair(-195, -199), Pair(-27, -284), Pair(-18, -297), Pair(-167, -245), Pair(-47, -332), Pair(-133, -319), Pair(-247, -205), Pair(-122, -278), Pair(-193, -95), Pair(-173, -154), Pair(-178, -163), Pair(-34, -260), Pair(-198, -250), Pair(-79, -346), Pair(-258, -269), Pair(-309, -204), Pair(-216, -163), Pair(11, -252), Pair(-150, -178), Pair(-143, -220), Pair(-279, -211), Pair(-242, -274), Pair(-297, -231), Pair(-313, -196), Pair(-309, -147), Pair(-201, -183), Pair(-204, -188), Pair(-132, -254), Pair(-254, -268), Pair(-286, -239), Pair(-283, -271), Pair(-305, -130), Pair(-305, -149), Pair(-308, -206), Pair(-286, -182), Pair(-303, -189), Pair(-202, -245), Pair(-209, -310), Pair(-348, -270), Pair(-358, -234), Pair(-263, -270), Pair(-247, -235), Pair(-263, -263), Pair(-315, -273), Pair(-231, -342), Pair(-195, -378), Pair(-280, -301), Pair(-256, -258), Pair(-323, -292), Pair(-618, -107), Pair(-191, -320), Pair(-199, -375), Pair(-230, -272), Pair(-274, -344)},
    {Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(365, 33), Pair(485, 25), Pair(374, 51), Pair(332, 25), Pair(278, 26), Pair(356, 4), Pair(395, -10), Pair(297, 10), Pair(374, 19), Pair(436, 23), Pair(346, 52), Pair(248, 36), Pair(284, 28), Pair(410, 25), Pair(423, 16), Pair(274, 19), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)}
  }},
  {{
    {Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)},
    {Pair(-53, -92), Pair(-84, -91), Pair(14, -115), Pair(-35, -40), Pair(65, 12), Pair(-48, 10), Pair(1, -89), Pair(-22, -73), Pair(-53, -119), Pair(-12, -134), Pair(72, -63), Pair(-47, 8), Pair(-166, -80), Pair(-34, -108), Pair(-3, -45), Pair(-22, -102), Pair(43, -192), Pair(-48, -135), Pair(82, -89), Pair(64, -91), Pair(221, -126), Pair(93, -82), Pair(49, -153), Pair(-59, -138), Pair(-20, -113), Pair(-74, -139), Pair(174, -124), Pair(13, -113), Pair(112, -140), Pair(4, -149), Pair(71, -141), Pair(-35, -94), Pair(-95, -106), Pair(-86, -110), Pair(80, -146), Pair(-38, -105), Pair(125, -128), Pair(93, -112), Pair(64, -261), Pair(-88, -123), Pair(-37, -117), Pair(25, -136), Pair(-86, -111), Pair(13, -106), Pair(97, -139), Pair(-135, -80), Pair(67, -145), Pair(-81, -123), Pair(-41, -154), Pair(-100, -102), Pair(-24, -134), Pair(-204, -74), Pair(-61, -84), Pair(62, -110), Pair(-21, -163), Pair(-110, -128), Pair(-61, -253), Pair(-136, -134), Pair(-48, -139), Pair(27, -118), Pair(33, -106), Pair(-143, -62), Pair(-118, -102), Pair(-23, -148)},
    {Pair(-108, -195), Pair(-95, -148), Pair(34, -123), Pair(35, -126), Pair(-115, -62), Pair(-33, -112), Pair(-24, -128), Pair(15, -31), Pair(-13, -174), Pair(41, -176), Pair(-30, -121), Pair(50, -117), Pair(-11, -115), Pair(74, -149), Pair(88, -141), Pair(78, -109), Pair(-90, -177), Pair(141, -170), Pair(36, -133), Pair(10, -105), Pair(107, -111), Pair(39, -201), Pair(47, -165), Pair(-5, -124), Pair(-44, -103), Pair(24, -109), Pair(217, -130), Pair(164, -144), Pair(123, -155), Pair(109, -138), Pair(121, -140), Pair(131, -109), Pair(75, -94), Pair(171, -154), Pair(219, -125), Pair(216, -141), Pair(182, -162), Pair(114, -130), Pair(-12, -123), Pair(31, -104), Pair(34, -133), Pair(62, -107), Pair(53, -107), Pair(-41, -134), Pair(100, -129), Pair(3, -86), Pair(78, -97), Pair(-13, -89), Pair(-27, -141), Pair(54, -132), Pair(125, -146), Pair(1, -134), Pair(126, -138), Pair(196, -156), Pair(-33, -139), Pair(-80, -148), Pair(39, -133), Pair(52, -138), Pair(-181, -84), Pair(15, -111), Pair(-60, -67), Pair(-197, -139), Pair(2, -187), Pair(52, -161)},
    {Pair(205, -165), Pair(53, -157), Pair(289, -128), Pair(247, -184), Pair(298, -140), Pair(195, -135), Pair(53, -91), Pair(191, -152), Pair(153, -179), Pair(146, -189), Pair(228, -158), Pair(216, -143), Pair(245, -141), Pair(168, -113), Pair(137, -125), Pair(157, -171), Pair(-12, -122), Pair(149, -170), Pair(79, -132), Pair(161, -186), Pair(242, -197), Pair(207, -159), Pair(116, -107), Pair(39, -129), Pair(64, -149), Pair(-7, -138), Pair(77, -138), Pair(-151, -112), Pair(69, -161), Pair(151, -145), Pair(107, -148), Pair(-51, -84), Pair(69, -123), Pair(-13, -135), Pair(-16, -149), Pair(-11, -131), Pair(191, -166), Pair(-4, -123), Pair(48, -114), Pair(-13, -104), Pair(23, -136), Pair(-83, -134), Pair(54, -147), Pair(-25, -139), Pair(-161, -90), Pair(-82, -113), Pair(47, -122), Pair(-60, -114), Pair(-180, -117), Pair(55, -196), Pair(-112, -164), Pair(-81, -111), Pair(-71, -131), Pair(66, -178), Pair(-102, -107), Pair(-103, -108), Pair(-303, -47), Pair(-32, -111), Pair(-42, -112), Pair(-203, -87), Pair(-18, -78), Pair(-85, -102), Pair(-78, -88), Pair(-95, -90)},
    {Pair(-41, -373), Pair(-116, -283), Pair(-90, -319), Pair(-144, -236), Pair(-50, -304), Pair(-168, -284), Pair(-203, -374), Pair(-16, -414), Pair(-114, -165), Pair(-178, -206), Pair(-124, -208), Pair(-163, -174), Pair(-155, -149), Pair(-168, -195), Pair(-142, -284), Pair(-125, -270), Pair(-90, -178), Pair(-99, -260), Pair(-13, -190), Pair(-35, -192), Pair(-132, -110), Pair(-108, -194), Pair(-117, -238), Pair(-138, -272), Pair(23, -255), Pair(-9, -222), Pair(-131, -221), Pair(-75, -219), Pair(-51, -180), Pair(-137, -217), Pair(-97, -215), Pair(-112, -188), Pair(-151, -256), Pair(13, -220), Pair(-42, -296), Pair(-48, -217), Pair(-102, -205), Pair(-181, -202), Pair(-125, -230), Pair(-148, -239), Pair(-69, -222), Pair(-60, -174), Pair(-97, -125), Pair(-89, -260), Pair(-179, -169), Pair(-133, -171), Pair(-107, -209), Pair(-107, -238), Pair(-99, -274), Pair(-172, -266), Pair(-88, -251), Pair(-111, -185), Pair(-139, -270), Pair(-124, -191), Pair(-155, -298), Pair(-93, -165), Pair(-163, -218), Pair(-156, -315), Pair(-155, -252), Pair(-242, -150), Pair(-155, -311), Pair(-215, -274), Pair(-105, -332), Pair(-189, -293)},
    {Pair(114, 106), Pair(204, 148), Pair(293, 172), Pair(183, 138), Pair(176, 113), Pair(352, 134), Pair(334, 109), Pair(238, 48), Pair(219, 85), Pair(334, 109), Pair(323, 95), Pair(420, 83), Pair(355, 78), Pair(277, 3), Pair(396, 38), Pair(335, 35), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)}
  }}
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(9, -7), Pair(20, -9), Pair(24, -1), Pair(26, 2), Pair(27, 5), Pair(28, 5), Pair(30, 0), Pair(33, -11),
  Pair(33, -30)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(1, -33), Pair(10, -66), Pair(15, -48), Pair(18, -33), Pair(22, -23), Pair(23, -13), Pair(24, -11), Pair(24, -13),
  Pair(24, -11), Pair(29, -19), Pair(36, -24), Pair(45, -37), Pair(49, -24), Pair(55, -61)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-69, -121), Pair(-41, -113), Pair(-36, -78), Pair(-31, -50), Pair(-28, -33), Pair(-24, -25), Pair(-19, -17), Pair(-13, -15),
  Pair(-9, -10), Pair(-3, -8), Pair(0, -4), Pair(4, -2), Pair(14, -5), Pair(43, -23), Pair(107, -57)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-32, 198), Pair(-19, 130), Pair(-16, 124), Pair(-8, 73), Pair(-7, 112), Pair(-6, 127), Pair(-4, 145), Pair(-2, 163),
  Pair(0, 178), Pair(2, 181), Pair(3, 187), Pair(4, 191), Pair(7, 183), Pair(7, 185), Pair(10, 174), Pair(13, 166),
  Pair(16, 153), Pair(27, 129), Pair(31, 110), Pair(53, 78), Pair(79, 38), Pair(133, -32), Pair(128, -46), Pair(251, -156),
  Pair(197, -139), Pair(324, -261), Pair(120, -134), Pair(283, -352)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-33, -98), Pair(-25, -78), Pair(-5, -46), Pair(30, -7), Pair(41, 21), Pair(201, 136), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(7, 15), Pair(17, 19), Pair(26, 58), Pair(57, 115), Pair(135, 214), Pair(217, 309), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(6, -8), Pair(6, 21), Pair(20, 37), Pair(69, 81), Pair(248, 139), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-33, -69), Pair(-22, -16), Pair(0, 27), Pair(-27, 5), Pair(-23, -2), Pair(-8, -6), Pair(-8, 8), Pair(-20, -51)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-2, -12), Pair(-9, -14), Pair(-14, -6), Pair(-9, -5), Pair(-6, -8), Pair(-3, -8), Pair(-13, -5), Pair(-3, -7)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
    Pair(20, -16), Pair(29, -23), Pair(30, -11), Pair(39, -10), Pair(39, -12), Pair(59, -15), Pair(73, -46), Pair(52, -34)
  },
  {
    Pair(3, 10), Pair(7, -5), Pair(16, -8), Pair(26, -5), Pair(15, -6), Pair(23, -18), Pair(59, -45), Pair(21, -15)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(22, -14), Pair(40, -13), Pair(28, -15),
  Pair(52, -16), Pair(49, -18), Pair(51, -17),
  Pair(76, -6), Pair(0, 0), Pair(71, -6),
  Pair(57, 19), Pair(38, 13), Pair(55, 20)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-9, -11), Pair(-19, 6), Pair(-8, -10),
  Pair(-5, -6), Pair(-16, 4), Pair(-5, -6),
  Pair(3, -12), Pair(-11, -10), Pair(6, -12),
  Pair(20, -16), Pair(-7, -18), Pair(25, -18),
  Pair(79, -28), Pair(80, -28), Pair(70, -27),
  Pair(72, -32), Pair(-46, -63), Pair(69, -25),
  Pair(66, -91), Pair(0, 0), Pair(73, -93)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(2, 78), Pair(-10, 70), Pair(-7, 57), Pair(2, 45), Pair(-1, 35), Pair(8, 26), Pair(11, 24)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-27, 3), Pair(-28, 25), Pair(-11, 54), Pair(-1, 68), Pair(8, 73), Pair(18, 79), Pair(19, 97)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-204, 164);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
    Pair(-50, 2), Pair(-63, -10), Pair(-12, -19), Pair(-31, -5), Pair(-24, -8), Pair(-23, -17), Pair(-52, -1), Pair(-36, -5)
  },
  {
    Pair(-22, 51), Pair(-22, 29), Pair(5, 12), Pair(-20, 30), Pair(-8, 17), Pair(-5, 4), Pair(-14, 22), Pair(-22, 28)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
    Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(0, 0), Pair(19, 1), Pair(34, -4), Pair(101, -26), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(0, 0), Pair(12, 2), Pair(35, -3), Pair(72, -11), Pair(8, -18), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(0, 0), Pair(29, -17), Pair(47, -16), Pair(79, -17), Pair(141, -32), Pair(166, -43), Pair(0, 0), Pair(0, 0)
  },
  {
    Pair(0, 0), Pair(9, 31), Pair(24, 60), Pair(49, 78), Pair(120, 64), Pair(168, 67), Pair(312, 8), Pair(429, -49)
  },
  {
    Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(40, 1), Pair(10, 5), Pair(37, -4), Pair(24, 17), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
    Pair(-8, 54), Pair(8, 65)
  },
  {
    Pair(-51, -13), Pair(-13, -24)
  },
  {
    Pair(-37, -21), Pair(-17, -16)
  },
  {
    Pair(-122, 47), Pair(-78, 44)
  },
  {
    Pair(-40, 26), Pair(-42, 42)
  },
  {
    Pair(-35, 38), Pair(-55, 34)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(14, 35), Pair(11, 34), Pair(18, 31), Pair(12, 12), Pair(17, -4)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
    Pair(-15, -34), Pair(3, -8)
  },
  {
    Pair(-32, -32), Pair(-2, -62)
  },
  {
    Pair(-50, -50), Pair(-34, -73)
  },
  {
    Pair(-80, -36), Pair(-52, -61)
  },
  {
    Pair(-51, -59), Pair(-55, -28)
  },
  {
    Pair(-121, -15), Pair(-42, -73)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
    Pair(-14, -24), Pair(0, 1)
  },
  {
    Pair(-67, -32), Pair(-26, -57)
  },
  {
    Pair(-20, -53), Pair(-12, -63)
  },
  {
    Pair(-85, -38), Pair(-56, -62)
  },
  {
    Pair(-46, -56), Pair(-40, -67)
  },
  {
    Pair(-46, -5), Pair(-13, -53)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
    Pair(-9, -23), Pair(5, 4)
  },
  {
    Pair(-57, -19), Pair(-4, -10)
  },
  {
    Pair(-58, -21), Pair(-8, -8)
  },
  {
    Pair(-24, -15), Pair(-3, -28)
  },
  {
    Pair(-54, -49), Pair(-44, -72)
  },
  {
    Pair(-16, -34), Pair(-11, -52)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(7, 70), Pair(61, 11), Pair(12, 49), Pair(11, 36), Pair(1, 16), Pair(21, 12), Pair(69, 38), Pair(87, 108),
  Pair(12, 47), Pair(17, 36), Pair(9, 25), Pair(15, 16), Pair(2, 28), Pair(1, 48), Pair(8, 40), Pair(49, 76),
  Pair(-4, 38), Pair(-21, 9), Pair(8, 33), Pair(4, 22), Pair(-20, 32), Pair(7, 26), Pair(-6, 19), Pair(-6, 50)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-19, 20), Pair(27, 5), Pair(22, 33), Pair(12, -7), Pair(18, -19), Pair(13, -7), Pair(68, -4), Pair(-67, 5),
  Pair(5, 108), Pair(23, 8), Pair(1, 35), Pair(11, 51), Pair(10, 24), Pair(-33, 26), Pair(26, 0), Pair(60, 68),
  Pair(50, 65), Pair(-14, 28), Pair(10, 4), Pair(-14, 25), Pair(-28, 5), Pair(11, 25), Pair(-21, -15), Pair(44, 18)
};

constexpr ScorePair kBishopPairBonus = Pair(34, 94);

constexpr ScorePair kTempoBonus = Pair(31, 27);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H