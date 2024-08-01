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
using PieceSquareTable = KingBuckets<KingBuckets<PieceTable<SquareTable<T>>>>;

// [is_our_piece][pawn_position][piece_position]
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
  Pair(80, 103), Pair(357, 329), Pair(407, 406), Pair(543, 775), Pair(1246, 1323), Pair(0, 0)
};

constexpr PawnRelativePSQT<ScorePair> kPieceSquareTable = {{
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
        Pair(11, 5), Pair(-27, 2), Pair(-63, 24), Pair(-45, 42), Pair(32, 31), Pair(17, -36), Pair(-59, -15), Pair(41, 34),
        Pair(-6, -37), Pair(-24, 21), Pair(8, -9), Pair(15, -3), Pair(47, 2), Pair(-4, -4), Pair(-5, 3), Pair(0, 21),
        Pair(-13, -11), Pair(1, 8), Pair(-4, -3), Pair(8, 3), Pair(2, 8), Pair(3, -2), Pair(6, 10), Pair(7, 9),
        Pair(-9, 2), Pair(0, -5), Pair(-1, -4), Pair(1, 2), Pair(-1, -1), Pair(-1, 2), Pair(3, 2), Pair(3, 0),
        Pair(-2, 5), Pair(1, -1), Pair(3, -3), Pair(1, -5), Pair(1, -3), Pair(-1, -3), Pair(1, -4), Pair(0, -1),
        Pair(-2, 3), Pair(2, -2), Pair(2, -2), Pair(-2, -3), Pair(1, -1), Pair(-2, -3), Pair(2, -3), Pair(1, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-70, -47), Pair(42, 0), Pair(-76, -10), Pair(3, 41), Pair(15, -48), Pair(-68, -10), Pair(71, -64), Pair(17, 0),
        Pair(0, -9), Pair(21, -2), Pair(9, 16), Pair(33, -65), Pair(17, 7), Pair(11, -31), Pair(29, -49), Pair(13, 5),
        Pair(25, 51), Pair(-60, -73), Pair(9, -3), Pair(25, -7), Pair(-3, -14), Pair(22, -32), Pair(63, -43), Pair(32, 2),
        Pair(11, 19), Pair(-10, 42), Pair(14, 3), Pair(12, 0), Pair(11, -5), Pair(35, -22), Pair(27, -2), Pair(27, -19),
        Pair(-9, -39), Pair(-11, -14), Pair(-4, -3), Pair(11, -6), Pair(9, -8), Pair(14, -1), Pair(9, -10), Pair(8, 13),
        Pair(-3, 5), Pair(12, 6), Pair(-1, 3), Pair(5, -1), Pair(7, -8), Pair(1, 12), Pair(16, -6), Pair(7, 5),
        Pair(-5, 1), Pair(-1, -15), Pair(1, -9), Pair(1, 1), Pair(-2, 5), Pair(15, -25), Pair(9, -11), Pair(1, 16),
        Pair(-61, 64), Pair(-3, -5), Pair(28, -21), Pair(3, 0), Pair(8, -1), Pair(-5, 7), Pair(-3, 3), Pair(9, -11)
      },
      { // Piece 2
        Pair(35, 15), Pair(-11, 21), Pair(-51, 19), Pair(-95, 70), Pair(12, 1), Pair(-26, 38), Pair(-5, 12), Pair(-133, 79),
        Pair(-39, 20), Pair(-9, 7), Pair(-17, 20), Pair(30, 12), Pair(1, -1), Pair(12, 28), Pair(-8, 56), Pair(-7, -3),
        Pair(8, 30), Pair(-213, 125), Pair(-13, 19), Pair(16, 23), Pair(11, 43), Pair(24, 24), Pair(-25, 37), Pair(23, 18),
        Pair(22, 2), Pair(-20, 5), Pair(7, 35), Pair(-9, 10), Pair(-7, 35), Pair(4, 26), Pair(5, 34), Pair(14, -11),
        Pair(-7, 11), Pair(-19, 37), Pair(1, 14), Pair(-1, 45), Pair(11, 0), Pair(1, 19), Pair(1, 4), Pair(-4, 7),
        Pair(4, 30), Pair(-16, 21), Pair(5, 13), Pair(3, 16), Pair(3, 20), Pair(7, -11), Pair(6, 9), Pair(8, 5),
        Pair(1, 48), Pair(2, 28), Pair(-3, -4), Pair(1, 19), Pair(-2, 9), Pair(-18, 17), Pair(8, 5), Pair(-10, 13),
        Pair(2, 85), Pair(0, 29), Pair(-2, 27), Pair(-2, 6), Pair(-4, 23), Pair(-6, 12), Pair(-37, 34), Pair(6, 40)
      },
      { // Piece 3
        Pair(30, 1), Pair(39, 5), Pair(10, 13), Pair(-32, 34), Pair(-27, 43), Pair(-16, 39), Pair(-4, 48), Pair(54, -10),
        Pair(-41, 52), Pair(5, 36), Pair(-14, 42), Pair(7, 21), Pair(14, 37), Pair(7, 29), Pair(5, 29), Pair(-13, 35),
        Pair(14, 34), Pair(62, -89), Pair(13, 16), Pair(7, 56), Pair(52, 13), Pair(23, 13), Pair(15, 8), Pair(20, -6),
        Pair(-10, 33), Pair(3, 7), Pair(-13, 53), Pair(-6, 18), Pair(2, 34), Pair(22, 21), Pair(31, -3), Pair(20, 7),
        Pair(-3, 18), Pair(1, 3), Pair(-16, 21), Pair(-19, 34), Pair(11, 10), Pair(12, 8), Pair(-3, 19), Pair(-9, 43),
        Pair(-10, 1), Pair(7, 19), Pair(-7, 18), Pair(-13, 24), Pair(-6, 43), Pair(2, 11), Pair(32, -12), Pair(-14, 27),
        Pair(-4, 16), Pair(-2, 23), Pair(17, 8), Pair(1, 12), Pair(0, 24), Pair(8, 32), Pair(-3, 15), Pair(-1, 32),
        Pair(-2, 14), Pair(-7, 16), Pair(-1, 16), Pair(-2, 18), Pair(2, 16), Pair(3, 22), Pair(6, 19), Pair(1, 26)
      },
      { // Piece 4
        Pair(-56, 72), Pair(64, -39), Pair(8, 31), Pair(40, 27), Pair(-19, 55), Pair(53, 7), Pair(-14, 70), Pair(55, 9),
        Pair(-17, 56), Pair(25, 61), Pair(-1, 48), Pair(-23, 70), Pair(12, 57), Pair(10, 81), Pair(-16, 8), Pair(56, 17),
        Pair(2, 43), Pair(97, -28), Pair(41, 29), Pair(13, -1), Pair(11, 27), Pair(23, 59), Pair(45, -12), Pair(16, 93),
        Pair(11, 24), Pair(-1, 26), Pair(11, 19), Pair(-9, 70), Pair(10, 21), Pair(5, 61), Pair(-5, 87), Pair(31, 7),
        Pair(-2, -8), Pair(2, -33), Pair(2, 27), Pair(-1, 27), Pair(-11, 38), Pair(10, 53), Pair(5, 8), Pair(4, 35),
        Pair(-6, 62), Pair(1, 2), Pair(11, 21), Pair(1, 7), Pair(-16, 49), Pair(5, 22), Pair(4, 27), Pair(36, 25),
        Pair(3, 28), Pair(-4, 20), Pair(-1, 2), Pair(-6, 15), Pair(2, 21), Pair(-2, 12), Pair(-3, 32), Pair(-5, 9),
        Pair(10, -20), Pair(9, 11), Pair(2, -5), Pair(-2, 14), Pair(-1, 19), Pair(30, 18), Pair(6, 56), Pair(-2, 48)
      },
      { // Piece 5
        Pair(46, 40), Pair(-38, -56), Pair(10, -51), Pair(3, -12), Pair(54, -82), Pair(85, 16), Pair(-1, -25), Pair(31, -61),
        Pair(-1, -8), Pair(42, -108), Pair(-71, 38), Pair(-21, -38), Pair(17, -21), Pair(20, 12), Pair(76, -33), Pair(23, 17),
        Pair(-45, -63), Pair(-79, -65), Pair(1, -22), Pair(63, -11), Pair(1, 6), Pair(59, -32), Pair(149, -52), Pair(-59, 16),
        Pair(-85, -55), Pair(-31, -15), Pair(3, 13), Pair(13, -19), Pair(38, -12), Pair(39, 6), Pair(26, -15), Pair(20, 5),
        Pair(-58, -53), Pair(-18, 9), Pair(-4, -3), Pair(16, -15), Pair(6, -3), Pair(53, 4), Pair(0, 10), Pair(49, -4),
        Pair(-73, 46), Pair(-78, 35), Pair(20, 3), Pair(1, 1), Pair(-47, 4), Pair(9, -1), Pair(-13, 5), Pair(-39, 8),
        Pair(-15, 34), Pair(6, 26), Pair(-10, 19), Pair(12, 15), Pair(-3, 5), Pair(0, 2), Pair(-2, -1), Pair(0, 1),
        Pair(9, 50), Pair(16, 21), Pair(21, 1), Pair(28, 22), Pair(10, 0), Pair(1, 3), Pair(2, -6), Pair(1, 5)
      }
    }},
    {{ // Bucket 9
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-20, -34), Pair(87, -10), Pair(-45, 13), Pair(23, -8), Pair(2, -27), Pair(-4, 24), Pair(-5, 50), Pair(-42, 57),
        Pair(13, 63), Pair(5, -22), Pair(-16, 58), Pair(-6, 19), Pair(-22, 33), Pair(-2, 16), Pair(-2, 34), Pair(-3, 8),
        Pair(10, 10), Pair(-3, -6), Pair(-1, 12), Pair(0, 6), Pair(8, 6), Pair(11, -3), Pair(1, 10), Pair(-8, 14),
        Pair(0, -4), Pair(-5, 0), Pair(1, 1), Pair(2, -2), Pair(0, 2), Pair(0, 1), Pair(1, 1), Pair(2, 2),
        Pair(3, 1), Pair(-3, -1), Pair(1, 4), Pair(-1, -1), Pair(-1, 0), Pair(-4, 2), Pair(-1, 1), Pair(0, 3),
        Pair(-2, 0), Pair(1, -1), Pair(3, 2), Pair(1, 6), Pair(-1, -8), Pair(-2, -1), Pair(0, -1), Pair(1, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, 13), Pair(-4, -135), Pair(-19, -7), Pair(-25, 22), Pair(49, -27), Pair(-28, -28), Pair(-128, 52), Pair(-20, -49),
        Pair(12, -30), Pair(-22, -44), Pair(-14, 16), Pair(6, -2), Pair(-12, 19), Pair(1, 35), Pair(-35, 6), Pair(-12, 4),
        Pair(144, -50), Pair(3, 26), Pair(-192, 105), Pair(-3, 43), Pair(14, 13), Pair(-12, 12), Pair(-25, 43), Pair(17, -25),
        Pair(-16, 16), Pair(-1, 21), Pair(-8, 18), Pair(-2, 12), Pair(7, 8), Pair(-2, 36), Pair(16, -5), Pair(0, 6),
        Pair(7, 4), Pair(13, -36), Pair(-17, 21), Pair(-3, -1), Pair(9, 15), Pair(9, 2), Pair(7, 23), Pair(12, 27),
        Pair(3, 14), Pair(-3, 3), Pair(1, 10), Pair(5, -7), Pair(0, 3), Pair(5, 9), Pair(3, -3), Pair(4, 4),
        Pair(16, 13), Pair(-28, 47), Pair(10, 1), Pair(3, 14), Pair(6, 5), Pair(3, 12), Pair(7, 13), Pair(6, 8),
        Pair(101, -80), Pair(0, 20), Pair(31, 16), Pair(14, -8), Pair(5, 6), Pair(13, 9), Pair(-1, 14), Pair(-14, -4)
      },
      { // Piece 2
        Pair(4, 72), Pair(-8, 33), Pair(70, 9), Pair(-4, 24), Pair(-89, 32), Pair(-22, 40), Pair(-44, 7), Pair(-68, 52),
        Pair(17, 2), Pair(-33, 67), Pair(-19, 12), Pair(-67, 68), Pair(-8, 23), Pair(33, 27), Pair(13, 34), Pair(-26, 26),
        Pair(66, -18), Pair(-5, 40), Pair(-184, 13), Pair(-31, 31), Pair(-2, 33), Pair(-3, 8), Pair(-14, 58), Pair(7, -1),
        Pair(-2, 2), Pair(-5, 45), Pair(-14, 10), Pair(10, 30), Pair(-6, 39), Pair(-30, 50), Pair(3, 20), Pair(-9, 33),
        Pair(-10, 7), Pair(-5, -7), Pair(-22, 26), Pair(5, 10), Pair(11, 25), Pair(-1, 8), Pair(-1, 20), Pair(24, -16),
        Pair(-1, 21), Pair(5, 21), Pair(0, 17), Pair(4, 13), Pair(2, 10), Pair(4, 18), Pair(10, -6), Pair(-1, 24),
        Pair(3, 48), Pair(7, 15), Pair(6, 14), Pair(7, 4), Pair(-4, 21), Pair(22, 7), Pair(4, 13), Pair(0, 11),
        Pair(14, 41), Pair(-34, 115), Pair(3, 23), Pair(5, 33), Pair(28, -9), Pair(-1, 24), Pair(1, 7), Pair(0, -2)
      },
      { // Piece 3
        Pair(16, -1), Pair(16, -6), Pair(17, -17), Pair(45, 3), Pair(9, 9), Pair(-69, 54), Pair(-32, 16), Pair(88, -12),
        Pair(-17, 9), Pair(0, 3), Pair(19, -3), Pair(-20, 20), Pair(7, 28), Pair(-6, -8), Pair(-49, 40), Pair(5, 22),
        Pair(-64, -24), Pair(-31, 7), Pair(13, -82), Pair(11, 1), Pair(1, 23), Pair(24, 11), Pair(-10, 31), Pair(5, 15),
        Pair(-8, 5), Pair(-13, 14), Pair(-10, 9), Pair(8, 5), Pair(-18, 35), Pair(-23, 36), Pair(18, 24), Pair(-27, 22),
        Pair(-6, 4), Pair(-42, 23), Pair(-5, -3), Pair(-5, 9), Pair(-13, 0), Pair(6, 6), Pair(49, -16), Pair(2, 14),
        Pair(-7, 9), Pair(5, -11), Pair(-24, 23), Pair(5, 7), Pair(-5, 8), Pair(-19, 17), Pair(11, -9), Pair(-14, 12),
        Pair(15, -20), Pair(-10, 22), Pair(-16, 1), Pair(3, -4), Pair(3, 14), Pair(8, -1), Pair(2, 8), Pair(17, 7),
        Pair(-4, 7), Pair(-2, 8), Pair(-9, 10), Pair(1, 6), Pair(0, 10), Pair(3, 11), Pair(1, 11), Pair(8, 9)
      },
      { // Piece 4
        Pair(0, 26), Pair(-60, 13), Pair(10, 39), Pair(-7, 75), Pair(39, -11), Pair(45, 23), Pair(-66, 87), Pair(52, -2),
        Pair(17, 33), Pair(-74, -17), Pair(15, 72), Pair(-24, 52), Pair(28, 37), Pair(-38, 71), Pair(18, -16), Pair(-32, 49),
        Pair(-49, 44), Pair(6, 4), Pair(-103, -4), Pair(21, 29), Pair(27, -3), Pair(6, -3), Pair(2, 53), Pair(31, 31),
        Pair(-3, 8), Pair(14, 33), Pair(6, 10), Pair(24, 3), Pair(5, 67), Pair(21, 14), Pair(15, 16), Pair(24, 27),
        Pair(-9, 15), Pair(22, 6), Pair(-4, 19), Pair(-4, 32), Pair(5, 25), Pair(0, 26), Pair(4, -15), Pair(-6, 33),
        Pair(13, -11), Pair(3, 23), Pair(6, 0), Pair(-1, 22), Pair(10, 18), Pair(0, 20), Pair(7, 39), Pair(19, 11),
        Pair(-15, 24), Pair(4, 33), Pair(2, 12), Pair(-1, 10), Pair(-2, 34), Pair(-5, 13), Pair(-9, 24), Pair(22, 1),
        Pair(11, -15), Pair(0, 6), Pair(5, -3), Pair(2, 11), Pair(-3, -3), Pair(11, -20), Pair(20, 58), Pair(-22, 39)
      },
      { // Piece 5
        Pair(-15, -38), Pair(-5, -97), Pair(-62, -16), Pair(14, -93), Pair(-2, -54), Pair(82, -27), Pair(-23, -115), Pair(3, -91),
        Pair(-16, -29), Pair(-6, -14), Pair(-37, -118), Pair(-27, -30), Pair(-6, -32), Pair(33, 48), Pair(38, -34), Pair(65, -62),
        Pair(-23, -61), Pair(-135, -83), Pair(-5, -16), Pair(-83, 1), Pair(-115, 12), Pair(52, 8), Pair(0, 10), Pair(157, -71),
        Pair(-117, -57), Pair(-12, -68), Pair(-31, -21), Pair(-110, -8), Pair(74, -30), Pair(20, 20), Pair(-91, 23), Pair(-14, -30),
        Pair(-105, -64), Pair(-90, -4), Pair(-100, 18), Pair(-19, -18), Pair(-77, -7), Pair(-1, 1), Pair(-63, 22), Pair(15, -17),
        Pair(-9, 14), Pair(-13, -20), Pair(-23, 18), Pair(-3, -9), Pair(0, 4), Pair(-19, -1), Pair(5, -12), Pair(-7, 1),
        Pair(-7, 24), Pair(8, -5), Pair(-5, 26), Pair(14, 1), Pair(-2, -1), Pair(4, -4), Pair(4, -6), Pair(-1, 0),
        Pair(0, 26), Pair(20, 22), Pair(23, -6), Pair(-1, -5), Pair(9, 7), Pair(16, -4), Pair(1, -1), Pair(6, 9)
      }
    }},
    {{ // Bucket 10
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-16, 24), Pair(-67, -11), Pair(-12, -5), Pair(-90, -4), Pair(-73, -7), Pair(79, -50), Pair(-56, 102), Pair(5, 61),
        Pair(-1, 5), Pair(19, 60), Pair(-18, -18), Pair(11, 80), Pair(-29, 49), Pair(27, 11), Pair(-12, 35), Pair(-1, 21),
        Pair(4, -3), Pair(3, 17), Pair(-12, -11), Pair(7, 11), Pair(4, 2), Pair(12, 9), Pair(17, -13), Pair(7, 3),
        Pair(-2, -3), Pair(-4, -8), Pair(-6, -8), Pair(0, -3), Pair(-1, -1), Pair(-3, 5), Pair(1, 6), Pair(2, -2),
        Pair(2, -1), Pair(-4, -1), Pair(-1, -3), Pair(2, 5), Pair(0, -1), Pair(-7, 1), Pair(3, 1), Pair(2, 3),
        Pair(-2, 1), Pair(-2, -1), Pair(-1, -1), Pair(5, -7), Pair(3, -13), Pair(-1, -1), Pair(3, 0), Pair(5, 4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-66, -60), Pair(48, 84), Pair(-165, -26), Pair(-9, -16), Pair(23, -38), Pair(-96, 4), Pair(-62, 13), Pair(-85, 66),
        Pair(-13, 21), Pair(-10, -9), Pair(-10, -111), Pair(-12, 36), Pair(-37, 24), Pair(-4, -24), Pair(66, -38), Pair(44, -36),
        Pair(-55, 47), Pair(101, -39), Pair(17, 40), Pair(-173, 23), Pair(1, -3), Pair(-39, 25), Pair(18, 1), Pair(-5, 41),
        Pair(6, 10), Pair(-15, 19), Pair(10, 18), Pair(-26, 12), Pair(3, 1), Pair(-1, 9), Pair(23, 11), Pair(29, 3),
        Pair(-9, 24), Pair(-18, 30), Pair(-12, 16), Pair(-21, 17), Pair(-3, 18), Pair(-7, 22), Pair(8, 25), Pair(5, 3),
        Pair(-3, -2), Pair(5, 32), Pair(1, 6), Pair(6, 28), Pair(0, 12), Pair(2, 11), Pair(4, 1), Pair(4, 32),
        Pair(-16, 8), Pair(-9, -3), Pair(-9, 20), Pair(1, 7), Pair(2, 16), Pair(20, 3), Pair(9, 7), Pair(5, 28),
        Pair(60, 42), Pair(3, 22), Pair(9, 54), Pair(0, 30), Pair(20, -7), Pair(-1, 19), Pair(0, 18), Pair(16, -81)
      },
      { // Piece 2
        Pair(-15, -37), Pair(70, 59), Pair(-90, -28), Pair(-24, 20), Pair(32, 40), Pair(-22, -16), Pair(-51, 26), Pair(-21, 11),
        Pair(-27, 3), Pair(-1, 7), Pair(-71, 90), Pair(-26, 65), Pair(-46, 40), Pair(0, -9), Pair(-6, 31), Pair(-14, 31),
        Pair(13, 13), Pair(8, -71), Pair(11, 47), Pair(-202, 97), Pair(13, 3), Pair(-9, 33), Pair(-2, 40), Pair(25, -2),
        Pair(10, -29), Pair(-9, 23), Pair(-12, 12), Pair(-32, 23), Pair(5, 16), Pair(24, 9), Pair(-5, 36), Pair(12, 31),
        Pair(12, 30), Pair(-24, -2), Pair(-2, 24), Pair(-30, 9), Pair(-5, 24), Pair(-2, 28), Pair(3, 24), Pair(1, -19),
        Pair(-8, 7), Pair(1, 24), Pair(-4, 15), Pair(4, 25), Pair(-5, 14), Pair(-1, 4), Pair(10, 19), Pair(-11, 13),
        Pair(-6, 25), Pair(3, 13), Pair(21, 9), Pair(-2, 32), Pair(9, 8), Pair(4, 3), Pair(14, 11), Pair(7, 1),
        Pair(0, 34), Pair(-37, 68), Pair(-7, 31), Pair(-1, 38), Pair(-20, 48), Pair(-2, 44), Pair(-8, 21), Pair(11, 63)
      },
      { // Piece 3
        Pair(15, -3), Pair(2, -26), Pair(37, -28), Pair(-62, 29), Pair(26, -16), Pair(-19, 31), Pair(49, -20), Pair(-92, 84),
        Pair(-18, -3), Pair(-3, 7), Pair(-41, -12), Pair(12, 8), Pair(-13, 30), Pair(-23, 44), Pair(-30, 25), Pair(-10, 9),
        Pair(-5, -17), Pair(17, -92), Pair(18, -8), Pair(36, -55), Pair(18, -8), Pair(73, 6), Pair(-17, 27), Pair(-6, 1),
        Pair(-5, 18), Pair(-24, 16), Pair(12, -3), Pair(-22, 38), Pair(-6, 0), Pair(-4, -4), Pair(-10, 20), Pair(13, -19),
        Pair(23, -12), Pair(-1, -16), Pair(-14, -2), Pair(-34, 17), Pair(0, 8), Pair(15, 9), Pair(1, 0), Pair(1, 23),
        Pair(8, -12), Pair(-6, 24), Pair(5, -3), Pair(-8, 16), Pair(-5, 15), Pair(5, 10), Pair(18, 16), Pair(12, -3),
        Pair(-5, -7), Pair(14, -34), Pair(5, -6), Pair(-30, 10), Pair(12, -3), Pair(-4, 26), Pair(-7, 38), Pair(-13, -29),
        Pair(-6, 3), Pair(-12, 4), Pair(-5, 7), Pair(-3, 1), Pair(0, 11), Pair(0, 8), Pair(3, 20), Pair(2, 19)
      },
      { // Piece 4
        Pair(74, 4), Pair(-53, 48), Pair(15, -27), Pair(-8, 50), Pair(11, 39), Pair(0, 62), Pair(-46, 59), Pair(-8, -6),
        Pair(21, 2), Pair(-4, 7), Pair(-63, 6), Pair(-37, 58), Pair(-7, -67), Pair(-68, 34), Pair(-46, 68), Pair(-5, -40),
        Pair(16, 2), Pair(0, 94), Pair(33, 19), Pair(-108, 23), Pair(-2, 30), Pair(-18, 29), Pair(3, -17), Pair(-9, 70),
        Pair(29, 8), Pair(-1, 45), Pair(22, -39), Pair(17, 35), Pair(-12, 16), Pair(-5, 23), Pair(3, -20), Pair(4, 18),
        Pair(6, 32), Pair(2, 25), Pair(-10, 19), Pair(-2, -11), Pair(-5, 46), Pair(13, -3), Pair(-6, 54), Pair(-7, 26),
        Pair(-12, -23), Pair(-1, 9), Pair(6, -14), Pair(5, -33), Pair(10, 1), Pair(-12, 28), Pair(-2, 19), Pair(9, 5),
        Pair(-12, 17), Pair(18, -16), Pair(3, 9), Pair(0, 21), Pair(-8, 16), Pair(12, 1), Pair(-4, 1), Pair(16, -5),
        Pair(-8, 7), Pair(-8, 62), Pair(-4, 15), Pair(-1, -5), Pair(9, 20), Pair(23, -38), Pair(-4, -49), Pair(-38, -33)
      },
      { // Piece 5
        Pair(15, 32), Pair(-15, -29), Pair(-8, -102), Pair(-6, 4), Pair(33, -26), Pair(10, -77), Pair(15, -41), Pair(2, 32),
        Pair(-63, -88), Pair(9, -144), Pair(2, 29), Pair(5, -179), Pair(24, -60), Pair(27, -4), Pair(19, 51), Pair(11, 13),
        Pair(-6, -36), Pair(-9, -41), Pair(-202, -30), Pair(35, 9), Pair(-5, -36), Pair(85, -12), Pair(63, 6), Pair(20, -6),
        Pair(-82, -18), Pair(-144, -14), Pair(-186, -64), Pair(-133, 13), Pair(-39, 20), Pair(31, -19), Pair(-20, 25), Pair(-204, 4),
        Pair(-48, -20), Pair(-23, -30), Pair(-67, -32), Pair(-36, 9), Pair(-11, 3), Pair(-18, -9), Pair(0, -3), Pair(-36, 11),
        Pair(76, 34), Pair(2, 9), Pair(-63, 5), Pair(-18, 16), Pair(-3, -1), Pair(-39, 7), Pair(-13, -5), Pair(12, -27),
        Pair(-26, 11), Pair(5, 5), Pair(5, 10), Pair(-16, 24), Pair(-1, 15), Pair(0, 0), Pair(-1, -4), Pair(8, -4),
        Pair(12, -17), Pair(5, -11), Pair(4, 28), Pair(13, 5), Pair(7, 8), Pair(2, 10), Pair(-1, -8), Pair(2, -13)
      }
    }},
    {{ // Bucket 11
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(43, -4), Pair(-47, 1), Pair(-92, 9), Pair(20, -27), Pair(69, 54), Pair(180, 36), Pair(125, -90), Pair(42, 12),
        Pair(6, -9), Pair(-7, -18), Pair(69, -73), Pair(13, -23), Pair(-7, 8), Pair(2, 12), Pair(-21, 0), Pair(28, -4),
        Pair(-12, 28), Pair(-6, 10), Pair(14, -12), Pair(12, 12), Pair(-7, 20), Pair(-12, 4), Pair(-10, -16), Pair(4, 26),
        Pair(-5, 11), Pair(-5, -4), Pair(7, -11), Pair(-8, -5), Pair(-2, -6), Pair(-1, 3), Pair(-8, 1), Pair(-5, 4),
        Pair(-1, 11), Pair(-4, 9), Pair(-3, 4), Pair(1, -4), Pair(-6, 7), Pair(-1, -5), Pair(-2, 1), Pair(-3, 5),
        Pair(-1, 3), Pair(1, -3), Pair(4, -5), Pair(-8, -3), Pair(-2, 7), Pair(-2, -1), Pair(-3, 1), Pair(-1, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-23, 42), Pair(8, -61), Pair(-62, 114), Pair(-157, -133), Pair(-31, -32), Pair(60, -71), Pair(-5, 36), Pair(-188, -106),
        Pair(29, 36), Pair(-70, 92), Pair(3, 20), Pair(-47, 67), Pair(4, 0), Pair(-71, 5), Pair(132, -143), Pair(-56, -13),
        Pair(-71, 29), Pair(48, -47), Pair(-209, 55), Pair(50, 41), Pair(3, 47), Pair(-16, 9), Pair(-40, 11), Pair(-2, 29),
        Pair(-83, 69), Pair(-9, 79), Pair(-12, 43), Pair(4, 36), Pair(-16, 25), Pair(26, -1), Pair(7, -52), Pair(-4, -4),
        Pair(-8, 59), Pair(-5, 40), Pair(-1, 22), Pair(9, -20), Pair(0, -2), Pair(30, -5), Pair(-19, 71), Pair(9, 30),
        Pair(2, 32), Pair(-8, -30), Pair(10, -2), Pair(-6, 34), Pair(-29, 56), Pair(5, -13), Pair(18, -18), Pair(-8, 81),
        Pair(32, -72), Pair(-20, -4), Pair(21, 5), Pair(2, 23), Pair(7, 3), Pair(-7, 9), Pair(2, -29), Pair(18, 58),
        Pair(47, -35), Pair(5, 37), Pair(-16, -45), Pair(-53, 101), Pair(-14, -5), Pair(37, 38), Pair(1, -36), Pair(-25, -12)
      },
      { // Piece 2
        Pair(-71, 11), Pair(-118, 99), Pair(-92, -2), Pair(66, -61), Pair(75, 37), Pair(114, -82), Pair(41, -8), Pair(91, -105),
        Pair(-54, 84), Pair(-87, 68), Pair(6, -6), Pair(-14, 4), Pair(4, -28), Pair(14, 38), Pair(5, -7), Pair(-35, -39),
        Pair(-23, 51), Pair(-36, 42), Pair(-135, 61), Pair(4, 43), Pair(-74, -15), Pair(17, -63), Pair(12, 39), Pair(18, 23),
        Pair(-1, 3), Pair(-1, -5), Pair(-43, 56), Pair(28, 16), Pair(21, -44), Pair(0, 59), Pair(12, 26), Pair(-37, 73),
        Pair(-46, 34), Pair(-31, -27), Pair(-12, -2), Pair(-10, 4), Pair(5, 10), Pair(5, 6), Pair(-32, 108), Pair(33, -101),
        Pair(2, -48), Pair(-3, 9), Pair(12, -2), Pair(-10, 31), Pair(-1, -23), Pair(-13, 21), Pair(6, -23), Pair(-16, -20),
        Pair(49, -7), Pair(7, 16), Pair(-4, 51), Pair(15, -9), Pair(-7, 41), Pair(-16, -33), Pair(2, 23), Pair(-1, -14),
        Pair(12, -12), Pair(-57, 22), Pair(0, 9), Pair(-20, 142), Pair(16, -8), Pair(-3, 8), Pair(4, 19), Pair(36, -70)
      },
      { // Piece 3
        Pair(48, 25), Pair(20, -10), Pair(63, -12), Pair(-12, -20), Pair(-4, -15), Pair(164, -56), Pair(-24, 70), Pair(-28, -5),
        Pair(34, -16), Pair(50, -27), Pair(26, -20), Pair(-4, 32), Pair(-4, 13), Pair(67, 49), Pair(54, -16), Pair(25, 54),
        Pair(21, -17), Pair(-19, -24), Pair(98, 24), Pair(31, -34), Pair(-27, -30), Pair(-21, -31), Pair(52, 35), Pair(25, -45),
        Pair(-9, 10), Pair(24, 44), Pair(27, 12), Pair(54, -25), Pair(15, -33), Pair(3, -9), Pair(34, -25), Pair(-34, 25),
        Pair(-9, 0), Pair(3, -8), Pair(-4, -27), Pair(17, -7), Pair(-2, -28), Pair(27, -23), Pair(28, 29), Pair(26, -4),
        Pair(42, -26), Pair(3, 0), Pair(12, 58), Pair(-5, -25), Pair(3, -39), Pair(-10, 16), Pair(-29, -14), Pair(8, 12),
        Pair(-5, 24), Pair(-3, -37), Pair(-52, -20), Pair(12, -21), Pair(-13, -13), Pair(40, -22), Pair(38, -45), Pair(42, -19),
        Pair(3, -1), Pair(20, -4), Pair(-2, -2), Pair(-10, 20), Pair(-6, 6), Pair(-5, 3), Pair(2, -11), Pair(8, -1)
      },
      { // Piece 4
        Pair(-25, -11), Pair(-26, -18), Pair(62, -71), Pair(58, 10), Pair(-28, 111), Pair(13, 28), Pair(49, 8), Pair(48, -45),
        Pair(42, 38), Pair(-29, 12), Pair(-35, -60), Pair(-5, 55), Pair(-58, -30), Pair(-26, -13), Pair(59, -15), Pair(-21, -11),
        Pair(-1, 10), Pair(-48, 104), Pair(63, 11), Pair(23, 23), Pair(16, -39), Pair(61, 57), Pair(49, -29), Pair(-7, -15),
        Pair(-5, 24), Pair(21, -26), Pair(0, 11), Pair(-5, 35), Pair(-19, 53), Pair(48, -37), Pair(57, -77), Pair(-2, 60),
        Pair(-26, 45), Pair(-21, -14), Pair(41, -87), Pair(12, 37), Pair(-9, 2), Pair(-12, 27), Pair(-5, 44), Pair(-3, -46),
        Pair(-20, 21), Pair(-13, 28), Pair(-11, 1), Pair(3, -22), Pair(-5, -1), Pair(14, 5), Pair(-21, 37), Pair(10, 1),
        Pair(23, -50), Pair(2, -3), Pair(1, -30), Pair(12, -54), Pair(-11, 25), Pair(7, -57), Pair(11, 8), Pair(68, -69),
        Pair(-33, 43), Pair(-19, -6), Pair(5, 39), Pair(10, 2), Pair(8, -16), Pair(-2, 54), Pair(-31, 85), Pair(-106, -10)
      },
      { // Piece 5
        Pair(-7, -56), Pair(0, -59), Pair(13, 91), Pair(-3, -24), Pair(-7, -36), Pair(-5, -62), Pair(-11, -108), Pair(-28, -78),
        Pair(-5, -36), Pair(-41, -108), Pair(39, -11), Pair(-19, -73), Pair(8, -12), Pair(-11, -52), Pair(-25, -19), Pair(-62, -122),
        Pair(-27, -78), Pair(32, -8), Pair(-3, -64), Pair(41, -87), Pair(-13, -44), Pair(53, 7), Pair(34, -69), Pair(-6, -37),
        Pair(-27, 12), Pair(28, 4), Pair(12, 0), Pair(-74, -6), Pair(-60, -50), Pair(78, 14), Pair(-32, -5), Pair(4, 26),
        Pair(-103, -77), Pair(-12, -42), Pair(8, 19), Pair(17, -26), Pair(-12, -2), Pair(-64, 30), Pair(111, -54), Pair(120, -43),
        Pair(-6, 2), Pair(27, -52), Pair(-57, 33), Pair(-29, 13), Pair(-47, 24), Pair(7, -1), Pair(-8, 16), Pair(-9, -3),
        Pair(57, 23), Pair(-45, 12), Pair(-33, 57), Pair(11, -1), Pair(-14, 21), Pair(10, 13), Pair(2, 8), Pair(-4, -8),
        Pair(107, -65), Pair(11, -15), Pair(27, -14), Pair(-17, 58), Pair(6, 2), Pair(26, 14), Pair(0, 3), Pair(2, -1)
      }
    }},
    {{ // Bucket 12
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-7, 36), Pair(-86, 48), Pair(-41, 1), Pair(-20, 18), Pair(-36, -21), Pair(-64, -32), Pair(67, -4), Pair(-14, 78),
        Pair(-1, -15), Pair(37, 5), Pair(-11, -10), Pair(45, 60), Pair(13, -12), Pair(-1, 143), Pair(47, -13), Pair(1, 41),
        Pair(11, 8), Pair(8, -3), Pair(-12, 1), Pair(21, 16), Pair(-14, 11), Pair(-6, 16), Pair(0, 5), Pair(7, 5),
        Pair(2, 1), Pair(-4, 1), Pair(0, 3), Pair(-5, 2), Pair(-3, 3), Pair(0, -1), Pair(1, -11), Pair(3, -3),
        Pair(0, 1), Pair(2, -1), Pair(1, -5), Pair(2, 4), Pair(-2, 1), Pair(1, -1), Pair(1, 2), Pair(0, 0),
        Pair(1, 0), Pair(1, 10), Pair(5, -8), Pair(-8, 9), Pair(2, 0), Pair(-4, -2), Pair(0, -2), Pair(0, -3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(108, -20), Pair(62, 14), Pair(73, -31), Pair(-1, 3), Pair(45, 43), Pair(-94, 51), Pair(4, 27), Pair(6, -104),
        Pair(-41, 29), Pair(-16, 36), Pair(13, -34), Pair(-27, -9), Pair(-42, -27), Pair(-59, 33), Pair(63, -101), Pair(-44, 32),
        Pair(133, -19), Pair(-2, 18), Pair(29, 24), Pair(56, -54), Pair(24, 92), Pair(-254, 31), Pair(11, -66), Pair(69, -48),
        Pair(-3, -39), Pair(13, 9), Pair(-9, 20), Pair(-23, 32), Pair(-8, 10), Pair(45, -12), Pair(-5, 18), Pair(-23, 19),
        Pair(7, 40), Pair(0, 12), Pair(-7, 18), Pair(-14, 1), Pair(19, 3), Pair(8, 1), Pair(12, 4), Pair(-2, 45),
        Pair(4, 15), Pair(-1, 34), Pair(2, 0), Pair(-3, 2), Pair(10, 15), Pair(7, -5), Pair(-15, -2), Pair(11, 82),
        Pair(-10, -15), Pair(-16, -61), Pair(2, 17), Pair(8, -12), Pair(-1, 3), Pair(26, -20), Pair(31, 13), Pair(10, 6),
        Pair(1, -57), Pair(2, -4), Pair(23, -7), Pair(-20, 49), Pair(-16, 36), Pair(-5, 0), Pair(-2, 36), Pair(-100, -24)
      },
      { // Piece 2
        Pair(32, -47), Pair(10, 18), Pair(14, 50), Pair(-117, 49), Pair(-45, 51), Pair(-87, 75), Pair(-20, 0), Pair(23, 62),
        Pair(-35, 9), Pair(-12, 17), Pair(22, -37), Pair(-88, 32), Pair(-43, 63), Pair(-8, 44), Pair(23, 11), Pair(-51, 46),
        Pair(-2, 37), Pair(-20, 58), Pair(-13, 22), Pair(-57, 92), Pair(1, 69), Pair(-199, 115), Pair(-24, 74), Pair(-11, 20),
        Pair(-4, 46), Pair(5, -26), Pair(22, 13), Pair(-26, 37), Pair(36, -24), Pair(-10, 36), Pair(10, 14), Pair(12, -8),
        Pair(-20, 72), Pair(-19, 43), Pair(-20, 14), Pair(-8, 19), Pair(3, -10), Pair(-10, 14), Pair(-21, 41), Pair(-9, 46),
        Pair(9, 22), Pair(0, 24), Pair(-8, 27), Pair(-1, 19), Pair(-5, 9), Pair(-3, 14), Pair(-9, -9), Pair(14, 0),
        Pair(-14, 9), Pair(-6, -7), Pair(20, 50), Pair(0, 2), Pair(5, 35), Pair(-2, 31), Pair(-4, 12), Pair(11, 4),
        Pair(-2, 31), Pair(57, -40), Pair(-1, 39), Pair(8, -15), Pair(-27, 105), Pair(8, 2), Pair(-2, 88), Pair(10, 70)
      },
      { // Piece 3
        Pair(-47, 3), Pair(-43, 39), Pair(-70, 29), Pair(-3, -22), Pair(1, 33), Pair(14, 22), Pair(-60, -14), Pair(84, 13),
        Pair(-17, 30), Pair(12, 15), Pair(-37, 14), Pair(-23, 17), Pair(-43, -29), Pair(-73, 35), Pair(-115, 14), Pair(-28, -19),
        Pair(-22, -7), Pair(-36, 0), Pair(26, -11), Pair(-25, -64), Pair(52, -31), Pair(25, -43), Pair(102, -62), Pair(11, -51),
        Pair(6, 16), Pair(-4, -2), Pair(29, -36), Pair(6, -11), Pair(17, -38), Pair(9, 1), Pair(-12, 1), Pair(3, -1),
        Pair(17, 39), Pair(-32, 40), Pair(32, -8), Pair(5, -39), Pair(-7, -2), Pair(30, -30), Pair(-70, 9), Pair(15, 42),
        Pair(-29, 39), Pair(-11, 14), Pair(1, -13), Pair(14, 31), Pair(-1, -10), Pair(34, -51), Pair(30, -30), Pair(-15, 65),
        Pair(37, -1), Pair(-16, 36), Pair(-13, 21), Pair(-13, -9), Pair(-2, -17), Pair(13, 9), Pair(-37, 44), Pair(18, -17),
        Pair(4, -10), Pair(-7, 6), Pair(7, -11), Pair(-5, -16), Pair(1, -11), Pair(0, 3), Pair(11, -44), Pair(3, 4)
      },
      { // Piece 4
        Pair(45, 22), Pair(-9, -8), Pair(89, -6), Pair(31, -33), Pair(-27, -49), Pair(21, 55), Pair(79, -49), Pair(-87, 31),
        Pair(16, -63), Pair(-17, 32), Pair(-7, -76), Pair(-35, 88), Pair(111, 19), Pair(-22, 36), Pair(-35, -43), Pair(-3, 12),
        Pair(-33, -31), Pair(-27, 63), Pair(23, -33), Pair(25, -36), Pair(40, -11), Pair(68, 3), Pair(-1, -4), Pair(-19, 75),
        Pair(15, 19), Pair(-13, -1), Pair(54, -71), Pair(9, -15), Pair(43, -9), Pair(-58, 84), Pair(41, 6), Pair(-14, 23),
        Pair(4, 27), Pair(-7, 48), Pair(-3, 14), Pair(17, -29), Pair(8, 13), Pair(2, 13), Pair(-37, 6), Pair(27, -23),
        Pair(-17, 0), Pair(-2, 8), Pair(-3, -9), Pair(-1, 33), Pair(-4, -11), Pair(7, -5), Pair(-9, -38), Pair(19, 64),
        Pair(-11, 71), Pair(-1, 9), Pair(-5, 1), Pair(1, -12), Pair(12, -26), Pair(13, -92), Pair(-27, -29), Pair(39, -56),
        Pair(1, 54), Pair(-13, 29), Pair(16, -38), Pair(2, 0), Pair(19, 11), Pair(22, -22), Pair(15, -73), Pair(43, 7)
      },
      { // Piece 5
        Pair(9, 84), Pair(-9, -135), Pair(2, -39), Pair(-9, -47), Pair(-8, -81), Pair(-5, -32), Pair(20, 60), Pair(-1, -17),
        Pair(-17, -49), Pair(-22, -62), Pair(-49, -170), Pair(-11, -57), Pair(-11, -10), Pair(-3, -138), Pair(-78, -21), Pair(-21, -22),
        Pair(24, -63), Pair(50, 4), Pair(-32, -33), Pair(-13, -93), Pair(16, -110), Pair(12, -28), Pair(30, -53), Pair(-25, -44),
        Pair(-68, -67), Pair(43, 14), Pair(-43, 26), Pair(7, -12), Pair(30, -81), Pair(15, -22), Pair(-67, -12), Pair(-55, 27),
        Pair(-34, -96), Pair(-75, -9), Pair(-26, -26), Pair(-64, 11), Pair(-35, -12), Pair(22, -9), Pair(-38, -6), Pair(-105, -35),
        Pair(43, 0), Pair(33, -10), Pair(-40, 42), Pair(30, 5), Pair(-19, 16), Pair(8, 25), Pair(10, 15), Pair(21, -21),
        Pair(11, -22), Pair(-108, 71), Pair(36, 24), Pair(-6, 51), Pair(8, 6), Pair(4, 13), Pair(-8, 15), Pair(10, 0),
        Pair(-25, -13), Pair(-15, -6), Pair(5, 15), Pair(52, -9), Pair(7, 12), Pair(-17, 11), Pair(0, 0), Pair(6, -2)
      }
    }},
    {{ // Bucket 13
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(29, 18), Pair(-7, 34), Pair(1, 27), Pair(4, 28), Pair(-19, 49), Pair(-31, -63), Pair(-90, 25), Pair(27, -19),
        Pair(15, 11), Pair(-14, 34), Pair(6, 6), Pair(25, -1), Pair(48, 57), Pair(12, -9), Pair(4, 62), Pair(18, -11),
        Pair(2, 5), Pair(2, 3), Pair(8, 9), Pair(2, 7), Pair(15, 11), Pair(2, -10), Pair(2, 9), Pair(7, -3),
        Pair(4, 1), Pair(0, 1), Pair(4, 0), Pair(1, -2), Pair(0, -7), Pair(-1, -3), Pair(-2, -8), Pair(-2, 1),
        Pair(2, -2), Pair(6, 1), Pair(3, 0), Pair(2, 0), Pair(1, 3), Pair(-4, 0), Pair(-3, 1), Pair(-3, 3),
        Pair(2, 2), Pair(3, -1), Pair(3, 3), Pair(-3, -7), Pair(1, 1), Pair(1, 1), Pair(0, -5), Pair(-4, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-47, -4), Pair(-11, 3), Pair(-15, 11), Pair(-80, 36), Pair(12, 81), Pair(-135, 26), Pair(-23, 50), Pair(-78, -10),
        Pair(-19, 45), Pair(13, 13), Pair(8, -11), Pair(-45, 4), Pair(4, 24), Pair(27, 35), Pair(-56, -36), Pair(50, -51),
        Pair(-58, 4), Pair(7, 28), Pair(16, 9), Pair(5, 1), Pair(-153, 39), Pair(39, 31), Pair(-68, 78), Pair(30, 31),
        Pair(-3, 16), Pair(15, 11), Pair(9, 11), Pair(-4, 17), Pair(-22, 5), Pair(18, 25), Pair(-15, -4), Pair(9, 9),
        Pair(0, 8), Pair(9, 1), Pair(-1, 15), Pair(0, 10), Pair(-18, 16), Pair(0, 6), Pair(-8, 7), Pair(7, -15),
        Pair(3, 9), Pair(-5, 14), Pair(6, 16), Pair(-6, 8), Pair(1, 15), Pair(1, 7), Pair(-7, 13), Pair(-9, -2),
        Pair(12, 9), Pair(-22, 45), Pair(0, 16), Pair(0, 10), Pair(-1, 9), Pair(-6, 18), Pair(-2, 40), Pair(-7, 16),
        Pair(-59, -14), Pair(5, 20), Pair(11, -18), Pair(20, 16), Pair(1, 11), Pair(12, 20), Pair(-5, 21), Pair(-24, -72)
      },
      { // Piece 2
        Pair(-32, 38), Pair(16, 19), Pair(-40, -3), Pair(12, 42), Pair(-140, 31), Pair(3, 31), Pair(-98, 86), Pair(-30, 67),
        Pair(-21, 31), Pair(-27, 29), Pair(31, 32), Pair(28, 3), Pair(-9, 52), Pair(-51, 108), Pair(-7, 37), Pair(3, 18),
        Pair(-15, 26), Pair(8, 30), Pair(-18, 24), Pair(0, 34), Pair(-142, 54), Pair(28, 66), Pair(-93, -45), Pair(21, -2),
        Pair(-1, 8), Pair(-13, 32), Pair(-7, 37), Pair(-9, 16), Pair(-18, 31), Pair(-10, 30), Pair(-4, 25), Pair(-4, -7),
        Pair(-6, 14), Pair(-5, 33), Pair(-13, 21), Pair(-7, 18), Pair(-24, 7), Pair(3, 19), Pair(-6, 2), Pair(10, 10),
        Pair(-9, 14), Pair(-14, 13), Pair(5, 21), Pair(-3, 4), Pair(-4, 15), Pair(-4, 16), Pair(-11, 29), Pair(-8, 1),
        Pair(4, 10), Pair(4, 11), Pair(-2, 5), Pair(4, 11), Pair(-6, 8), Pair(-1, 5), Pair(-4, -5), Pair(-7, 20),
        Pair(-1, 2), Pair(-15, 39), Pair(2, 15), Pair(6, 27), Pair(-6, 23), Pair(-2, 0), Pair(-2, 0), Pair(-16, 59)
      },
      { // Piece 3
        Pair(-9, 24), Pair(-3, 25), Pair(-41, 31), Pair(-31, 23), Pair(-9, 10), Pair(-80, 39), Pair(-33, 14), Pair(34, -15),
        Pair(-16, 14), Pair(-2, 13), Pair(-4, 3), Pair(-18, 14), Pair(5, 17), Pair(-3, -4), Pair(-26, -11), Pair(17, 6),
        Pair(-2, 10), Pair(-16, 21), Pair(-5, 8), Pair(-5, 21), Pair(-129, 50), Pair(36, -11), Pair(-85, -25), Pair(-19, 7),
        Pair(4, 12), Pair(-5, 14), Pair(-5, 22), Pair(-11, 18), Pair(-11, 8), Pair(14, -1), Pair(-13, 9), Pair(22, 14),
        Pair(-8, 13), Pair(-2, 14), Pair(11, 6), Pair(-9, 10), Pair(-10, -19), Pair(11, -4), Pair(-23, -9), Pair(-27, 32),
        Pair(-4, 22), Pair(-6, 12), Pair(-1, 12), Pair(-12, 9), Pair(0, 14), Pair(30, -6), Pair(24, 2), Pair(13, 10),
        Pair(1, 22), Pair(0, 10), Pair(-2, 7), Pair(1, 4), Pair(5, -10), Pair(15, -3), Pair(18, -20), Pair(-2, 12),
        Pair(5, 14), Pair(-4, 11), Pair(1, 7), Pair(2, 10), Pair(2, 4), Pair(3, 9), Pair(-1, 9), Pair(2, 7)
      },
      { // Piece 4
        Pair(-16, 8), Pair(46, -17), Pair(-28, 19), Pair(-26, 39), Pair(5, -35), Pair(11, -51), Pair(-22, -3), Pair(-28, 58),
        Pair(-16, 7), Pair(6, -19), Pair(1, 17), Pair(-32, -20), Pair(-17, -55), Pair(21, 38), Pair(-67, 61), Pair(-20, -8),
        Pair(-8, 8), Pair(-9, 1), Pair(-3, -21), Pair(5, -27), Pair(-177, -29), Pair(22, -44), Pair(-83, 88), Pair(20, 15),
        Pair(4, 4), Pair(-7, 6), Pair(-23, 26), Pair(5, -14), Pair(5, 4), Pair(-2, -4), Pair(35, 10), Pair(20, -7),
        Pair(2, -3), Pair(-3, -25), Pair(4, 2), Pair(9, -2), Pair(-3, 5), Pair(12, -30), Pair(1, 20), Pair(8, 5),
        Pair(-22, -7), Pair(-5, -7), Pair(-3, -8), Pair(-3, 5), Pair(-10, 2), Pair(12, -12), Pair(3, -2), Pair(-4, -4),
        Pair(-11, -10), Pair(4, -16), Pair(-2, -5), Pair(-4, -3), Pair(-1, -4), Pair(-5, -14), Pair(-11, 9), Pair(-1, -10),
        Pair(-12, -29), Pair(0, -21), Pair(2, -19), Pair(-2, -6), Pair(5, -16), Pair(1, -20), Pair(-3, 20), Pair(12, -13)
      },
      { // Piece 5
        Pair(-32, -92), Pair(101, -19), Pair(125, 38), Pair(-29, -11), Pair(-58, -65), Pair(-24, -138), Pair(-55, -136), Pair(-17, -30),
        Pair(51, -40), Pair(36, -5), Pair(-128, -33), Pair(31, -61), Pair(-42, -70), Pair(65, 2), Pair(9, -101), Pair(-31, -15),
        Pair(-7, 24), Pair(-57, -16), Pair(-80, -25), Pair(12, -38), Pair(9, -69), Pair(-134, -55), Pair(-6, -19), Pair(9, -35),
        Pair(-49, -18), Pair(-21, -7), Pair(-10, 9), Pair(-81, -2), Pair(-53, -25), Pair(-50, -51), Pair(-33, -32), Pair(-90, -22),
        Pair(-2, -5), Pair(96, -35), Pair(-8, 18), Pair(6, -14), Pair(-47, 8), Pair(-39, 1), Pair(-22, -6), Pair(-56, -6),
        Pair(26, 12), Pair(-19, -21), Pair(32, -13), Pair(12, -1), Pair(-17, 12), Pair(0, 4), Pair(-24, 11), Pair(-7, 1),
        Pair(6, -6), Pair(-1, 8), Pair(-6, 11), Pair(3, -10), Pair(1, 15), Pair(6, 8), Pair(-9, 18), Pair(3, -4),
        Pair(-3, -11), Pair(-6, -12), Pair(1, -7), Pair(-4, -5), Pair(5, 2), Pair(1, 23), Pair(-1, -4), Pair(15, -16)
      }
    }},
    {{ // Bucket 14
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-6, 63), Pair(-28, 76), Pair(15, 41), Pair(8, 33), Pair(23, -9), Pair(44, -36), Pair(-60, -17), Pair(-70, -29),
        Pair(-2, 12), Pair(7, 19), Pair(7, 28), Pair(-14, 21), Pair(14, -2), Pair(-14, 13), Pair(37, -12), Pair(47, 41),
        Pair(3, 7), Pair(7, 6), Pair(10, 7), Pair(4, 14), Pair(-7, -4), Pair(-1, 9), Pair(16, -8), Pair(23, 8),
        Pair(0, 1), Pair(-2, -2), Pair(1, -1), Pair(-2, 0), Pair(6, 0), Pair(2, 2), Pair(-5, -2), Pair(-1, -5),
        Pair(1, 1), Pair(1, 0), Pair(0, -6), Pair(-1, 1), Pair(0, -4), Pair(-2, 4), Pair(-1, 1), Pair(-2, 5),
        Pair(0, 1), Pair(0, 0), Pair(-3, 0), Pair(-5, 9), Pair(-2, -1), Pair(1, 4), Pair(1, 0), Pair(-3, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-62, -37), Pair(-73, 27), Pair(-26, 8), Pair(-104, 34), Pair(-106, 38), Pair(29, 33), Pair(60, 47), Pair(-17, 29),
        Pair(-11, 10), Pair(-37, 22), Pair(11, 29), Pair(26, -9), Pair(7, 33), Pair(21, -25), Pair(-4, -22), Pair(-66, -44),
        Pair(-14, -1), Pair(5, 0), Pair(-2, 6), Pair(-5, 1), Pair(-10, -3), Pair(-358, 53), Pair(-10, 41), Pair(67, -11),
        Pair(-9, 0), Pair(4, -6), Pair(-5, 18), Pair(17, -1), Pair(6, 16), Pair(-23, -2), Pair(-10, 39), Pair(-21, 20),
        Pair(-2, 13), Pair(16, -4), Pair(7, 8), Pair(-5, 24), Pair(16, -7), Pair(-24, 7), Pair(22, 5), Pair(-14, 7),
        Pair(2, -2), Pair(-1, 21), Pair(-1, 9), Pair(7, -2), Pair(-6, 12), Pair(2, 9), Pair(-5, 2), Pair(-5, 20),
        Pair(-7, 23), Pair(-23, 1), Pair(-4, 8), Pair(-2, 8), Pair(-3, 11), Pair(5, 14), Pair(3, 10), Pair(4, 14),
        Pair(2, -17), Pair(1, 14), Pair(-5, 19), Pair(-9, 17), Pair(14, 3), Pair(3, 20), Pair(5, -2), Pair(-33, 23)
      },
      { // Piece 2
        Pair(-4, 41), Pair(2, 5), Pair(-103, 74), Pair(-66, 54), Pair(12, 47), Pair(-129, 12), Pair(42, 19), Pair(18, -2),
        Pair(-38, 29), Pair(0, 33), Pair(-22, 19), Pair(-8, 48), Pair(-32, 33), Pair(-17, 40), Pair(125, -36), Pair(-26, 21),
        Pair(-4, 19), Pair(-4, 12), Pair(19, 29), Pair(-9, 11), Pair(-9, 25), Pair(-168, 103), Pair(-15, 61), Pair(-37, 63),
        Pair(-22, 24), Pair(8, 25), Pair(-5, 15), Pair(11, 32), Pair(5, 11), Pair(-36, 46), Pair(16, 16), Pair(-29, 27),
        Pair(-2, 8), Pair(-2, 12), Pair(7, 26), Pair(-2, 10), Pair(4, 12), Pair(-11, 0), Pair(-2, 21), Pair(-23, 18),
        Pair(-12, -7), Pair(23, -1), Pair(-5, -3), Pair(-2, 18), Pair(-6, 12), Pair(7, 30), Pair(-1, 8), Pair(11, 32),
        Pair(-14, 18), Pair(-5, -7), Pair(4, 23), Pair(-9, 11), Pair(3, 21), Pair(-4, 9), Pair(9, 26), Pair(-4, 3),
        Pair(-9, 6), Pair(16, 16), Pair(-1, 3), Pair(7, 23), Pair(-14, 18), Pair(8, 19), Pair(-34, 36), Pair(-13, 56)
      },
      { // Piece 3
        Pair(-3, 19), Pair(23, 17), Pair(-19, 40), Pair(-7, 27), Pair(23, 18), Pair(-23, 27), Pair(58, 8), Pair(-34, 36),
        Pair(-11, 10), Pair(12, 11), Pair(-9, 23), Pair(1, 15), Pair(14, 14), Pair(-8, -8), Pair(20, 14), Pair(-3, 0),
        Pair(1, 5), Pair(-7, 15), Pair(10, 2), Pair(-5, 14), Pair(-18, 7), Pair(-22, 24), Pair(3, 44), Pair(139, 59),
        Pair(-2, 11), Pair(-12, 14), Pair(0, 33), Pair(9, 5), Pair(4, 23), Pair(-27, 26), Pair(-8, 4), Pair(20, 20),
        Pair(0, 6), Pair(-20, 38), Pair(4, 8), Pair(9, 7), Pair(-3, 3), Pair(-35, 11), Pair(-39, 12), Pair(-15, 1),
        Pair(-6, 35), Pair(-10, 21), Pair(-5, 6), Pair(0, 24), Pair(-8, 36), Pair(-1, 2), Pair(-2, -4), Pair(17, 7),
        Pair(2, -5), Pair(9, -3), Pair(3, 5), Pair(-5, 24), Pair(0, 12), Pair(-2, 13), Pair(-16, 11), Pair(8, 12),
        Pair(5, 15), Pair(-3, 12), Pair(0, 13), Pair(2, 13), Pair(-1, 10), Pair(1, 8), Pair(5, 2), Pair(-8, 7)
      },
      { // Piece 4
        Pair(-18, 26), Pair(-60, 16), Pair(3, 58), Pair(6, -1), Pair(5, -2), Pair(-7, 16), Pair(-58, 59), Pair(5, 5),
        Pair(6, -10), Pair(-11, -12), Pair(-10, 17), Pair(-29, -8), Pair(-5, 9), Pair(38, -79), Pair(34, 61), Pair(37, -25),
        Pair(-8, -28), Pair(17, -10), Pair(-19, 5), Pair(-11, -3), Pair(2, -7), Pair(22, -14), Pair(22, -20), Pair(-1, -59),
        Pair(3, -10), Pair(-21, -7), Pair(-32, 25), Pair(-15, 38), Pair(-10, 4), Pair(-10, 37), Pair(12, -18), Pair(2, 2),
        Pair(-5, -35), Pair(-10, 20), Pair(0, 14), Pair(-1, 24), Pair(-11, 20), Pair(7, 23), Pair(-1, -5), Pair(4, 20),
        Pair(-9, -1), Pair(-10, 5), Pair(-6, 21), Pair(-4, 4), Pair(-7, 4), Pair(0, 15), Pair(7, 5), Pair(22, -9),
        Pair(-6, -36), Pair(-7, -10), Pair(-5, -13), Pair(-3, 2), Pair(-4, -4), Pair(-11, 2), Pair(-4, -2), Pair(20, 46),
        Pair(-14, -10), Pair(3, -28), Pair(-3, 7), Pair(-1, -3), Pair(-3, 5), Pair(-9, 24), Pair(5, -80), Pair(-9, -5)
      },
      { // Piece 5
        Pair(-55, -69), Pair(57, -32), Pair(-42, -45), Pair(-5, -86), Pair(-13, -42), Pair(-49, 50), Pair(40, -16), Pair(-14, 17),
        Pair(-182, -53), Pair(71, -71), Pair(-3, -19), Pair(-14, -27), Pair(5, -73), Pair(-40, -69), Pair(-39, -170), Pair(-14, -88),
        Pair(33, -28), Pair(91, -35), Pair(42, -22), Pair(30, 10), Pair(-21, -43), Pair(23, 8), Pair(-51, -90), Pair(-26, -102),
        Pair(-59, -20), Pair(49, -37), Pair(13, -19), Pair(12, -33), Pair(-166, 10), Pair(-91, -31), Pair(-80, -54), Pair(-186, -2),
        Pair(10, 3), Pair(41, -37), Pair(82, -36), Pair(-15, -28), Pair(-7, -22), Pair(-16, -3), Pair(-42, -13), Pair(-66, 24),
        Pair(18, -26), Pair(59, -13), Pair(19, -23), Pair(-47, 5), Pair(-26, -11), Pair(9, 2), Pair(-17, 5), Pair(-37, 7),
        Pair(31, -30), Pair(-7, -13), Pair(6, -11), Pair(10, -10), Pair(-1, -5), Pair(-8, 10), Pair(-2, 3), Pair(-18, 12),
        Pair(-11, -25), Pair(-11, -22), Pair(-8, -14), Pair(0, -14), Pair(4, -13), Pair(-14, 5), Pair(3, 9), Pair(-3, -6)
      }
    }},
    {{ // Bucket 15
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(17, 40), Pair(11, 44), Pair(-15, 22), Pair(-29, 44), Pair(-32, 42), Pair(-89, 8), Pair(-109, -68), Pair(-32, -120),
        Pair(6, 32), Pair(16, 22), Pair(15, 1), Pair(14, 3), Pair(-4, -9), Pair(-26, -4), Pair(-24, 38), Pair(38, -24),
        Pair(3, 0), Pair(2, 5), Pair(4, 16), Pair(-2, 3), Pair(-13, 1), Pair(-8, 6), Pair(-5, 6), Pair(23, -18),
        Pair(-1, 0), Pair(2, -1), Pair(1, -2), Pair(-1, -3), Pair(1, -2), Pair(2, 1), Pair(-3, -4), Pair(1, -5),
        Pair(-1, 0), Pair(-1, -3), Pair(0, -5), Pair(-2, -4), Pair(3, -1), Pair(6, -2), Pair(3, -1), Pair(1, 0),
        Pair(-3, -1), Pair(0, -1), Pair(-3, -6), Pair(0, -5), Pair(2, -2), Pair(5, -2), Pair(5, -3), Pair(1, -2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(3, -48), Pair(24, -34), Pair(41, -23), Pair(55, -19), Pair(-15, 85), Pair(-34, -48), Pair(-57, 69), Pair(-7, -138),
        Pair(-15, 34), Pair(-23, -10), Pair(-34, -24), Pair(11, -8), Pair(22, -18), Pair(31, -36), Pair(45, -36), Pair(-43, -46),
        Pair(-2, -29), Pair(-18, 6), Pair(11, 6), Pair(8, 12), Pair(-15, 13), Pair(20, 20), Pair(-129, 4), Pair(-15, 42),
        Pair(0, -8), Pair(5, -2), Pair(11, -5), Pair(17, -1), Pair(5, 5), Pair(0, 23), Pair(-11, 12), Pair(8, 21),
        Pair(-8, -1), Pair(6, -19), Pair(5, -10), Pair(4, 1), Pair(2, 6), Pair(22, -2), Pair(-16, 15), Pair(-9, 4),
        Pair(-9, -16), Pair(0, -11), Pair(3, 1), Pair(0, -12), Pair(14, -17), Pair(3, 0), Pair(2, 11), Pair(0, 5),
        Pair(2, -55), Pair(-4, 5), Pair(-14, 8), Pair(0, 4), Pair(3, -1), Pair(12, 11), Pair(13, -7), Pair(1, 28),
        Pair(-15, -30), Pair(-10, 6), Pair(-17, -28), Pair(13, -11), Pair(-13, -12), Pair(-13, 9), Pair(-7, 9), Pair(-10, 14)
      },
      { // Piece 2
        Pair(-24, 49), Pair(-38, 31), Pair(-102, 57), Pair(-22, 26), Pair(-116, 38), Pair(4, 33), Pair(27, 31), Pair(36, -11),
        Pair(-12, 15), Pair(3, 18), Pair(6, 44), Pair(-78, 83), Pair(-40, 54), Pair(-33, 48), Pair(-16, 24), Pair(17, 70),
        Pair(-20, 52), Pair(23, 12), Pair(-7, 32), Pair(-5, 34), Pair(-8, 47), Pair(13, 0), Pair(-31, 16), Pair(14, 48),
        Pair(-6, 30), Pair(-8, 28), Pair(15, 13), Pair(4, 26), Pair(6, 21), Pair(-5, 13), Pair(-16, 12), Pair(20, 15),
        Pair(-10, 25), Pair(-3, 25), Pair(-6, 10), Pair(0, 10), Pair(-7, 18), Pair(-1, 27), Pair(6, -10), Pair(-5, 37),
        Pair(3, 2), Pair(-4, 12), Pair(6, 22), Pair(-10, 12), Pair(1, 17), Pair(-1, 20), Pair(10, 25), Pair(0, 15),
        Pair(3, 22), Pair(7, 3), Pair(-20, 10), Pair(0, 16), Pair(-5, 9), Pair(-3, 17), Pair(6, 16), Pair(22, 19),
        Pair(17, -17), Pair(-15, -34), Pair(-3, 14), Pair(-12, 13), Pair(-4, 9), Pair(-1, 20), Pair(2, -10), Pair(-9, 88)
      },
      { // Piece 3
        Pair(0, 33), Pair(0, 32), Pair(46, 5), Pair(-45, 43), Pair(11, 42), Pair(31, 40), Pair(55, 12), Pair(-27, 81),
        Pair(-11, 32), Pair(-4, 25), Pair(-1, 30), Pair(22, 30), Pair(17, 19), Pair(-35, 47), Pair(35, 5), Pair(-30, -2),
        Pair(-13, 36), Pair(-12, 41), Pair(1, 29), Pair(-15, 34), Pair(-6, 23), Pair(-33, 21), Pair(-9, -26), Pair(-13, 4),
        Pair(11, 28), Pair(-3, 14), Pair(9, 25), Pair(8, 5), Pair(0, 9), Pair(7, 35), Pair(-16, 41), Pair(-22, 25),
        Pair(-3, 0), Pair(12, 28), Pair(14, 7), Pair(11, 15), Pair(10, 32), Pair(7, 14), Pair(-32, 53), Pair(-27, 7),
        Pair(-17, 24), Pair(13, 23), Pair(2, 19), Pair(-3, 2), Pair(5, 24), Pair(1, 24), Pair(-23, 28), Pair(-16, 13),
        Pair(35, -15), Pair(-1, 16), Pair(-4, 36), Pair(6, 19), Pair(-8, 24), Pair(-2, 29), Pair(0, 28), Pair(-19, 46),
        Pair(2, 23), Pair(0, 21), Pair(0, 19), Pair(3, 21), Pair(2, 23), Pair(3, 16), Pair(-25, 24), Pair(-6, 10)
      },
      { // Piece 4
        Pair(-23, 72), Pair(50, 18), Pair(18, 13), Pair(-32, 46), Pair(20, 48), Pair(3, 78), Pair(191, -45), Pair(10, 23),
        Pair(-12, 48), Pair(-7, 43), Pair(3, 26), Pair(-26, 92), Pair(-2, 52), Pair(-48, 53), Pair(-70, 103), Pair(16, 60),
        Pair(8, 34), Pair(8, 47), Pair(-18, 23), Pair(-7, 25), Pair(0, 81), Pair(-15, 62), Pair(124, 109), Pair(8, 26),
        Pair(-15, 20), Pair(3, 12), Pair(-18, 70), Pair(-12, 30), Pair(-3, 79), Pair(1, 10), Pair(-30, 59), Pair(-26, 7),
        Pair(5, 32), Pair(-14, 52), Pair(-5, 10), Pair(2, 35), Pair(-2, 44), Pair(4, 25), Pair(1, 1), Pair(-8, 41),
        Pair(5, 35), Pair(-1, 26), Pair(-5, 28), Pair(-1, 22), Pair(5, 12), Pair(-11, 13), Pair(-2, 32), Pair(-5, 26),
        Pair(-13, 25), Pair(7, -4), Pair(2, 3), Pair(2, 18), Pair(-1, 12), Pair(0, 14), Pair(14, -20), Pair(23, -32),
        Pair(-7, 14), Pair(-3, 12), Pair(8, 1), Pair(5, 2), Pair(-2, 2), Pair(-35, 49), Pair(-20, 48), Pair(30, -56)
      },
      { // Piece 5
        Pair(-14, 81), Pair(113, -60), Pair(18, -80), Pair(-10, -44), Pair(-42, 55), Pair(75, 15), Pair(2, 23), Pair(-22, -50),
        Pair(-52, -37), Pair(39, -3), Pair(-104, -37), Pair(-28, -20), Pair(62, -55), Pair(-83, -43), Pair(-85, -129), Pair(-9, -42),
        Pair(-69, -32), Pair(19, -18), Pair(-78, -19), Pair(11, -56), Pair(56, -50), Pair(-62, -20), Pair(2, -22), Pair(42, -64),
        Pair(66, -30), Pair(-55, 5), Pair(-7, -34), Pair(-25, -23), Pair(-67, -17), Pair(-60, -18), Pair(-98, 3), Pair(-162, -2),
        Pair(-26, -47), Pair(28, -35), Pair(43, -21), Pair(15, -24), Pair(-70, -7), Pair(-31, -7), Pair(4, -6), Pair(-67, -11),
        Pair(-54, -9), Pair(30, -30), Pair(11, -33), Pair(12, -21), Pair(18, -21), Pair(-11, 5), Pair(6, 7), Pair(-5, 16),
        Pair(-14, -6), Pair(-8, -24), Pair(9, -15), Pair(-21, -12), Pair(-3, -9), Pair(-1, -5), Pair(-14, 17), Pair(-7, 17),
        Pair(20, -18), Pair(-7, -21), Pair(-11, 0), Pair(16, -25), Pair(4, 0), Pair(-5, -3), Pair(4, 10), Pair(-7, 38)
      }
    }},
    {{ // Bucket 16
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(108, -79), Pair(21, 64), Pair(-61, 37), Pair(-33, 38), Pair(-19, 29), Pair(-2, 53), Pair(19, -18), Pair(3, 31),
        Pair(72, 1), Pair(-22, 6), Pair(27, -14), Pair(-7, 19), Pair(25, 18), Pair(6, 5), Pair(18, 30), Pair(-7, 16),
        Pair(-3, -7), Pair(6, 13), Pair(-4, -8), Pair(7, 2), Pair(4, 3), Pair(1, 10), Pair(5, 2), Pair(0, 13),
        Pair(1, 7), Pair(-4, -4), Pair(0, -2), Pair(-2, -3), Pair(-3, 2), Pair(-1, 2), Pair(0, 1), Pair(2, -2),
        Pair(1, 0), Pair(-1, -2), Pair(2, -4), Pair(0, -3), Pair(-2, -3), Pair(-9, -2), Pair(2, -1), Pair(-1, -1),
        Pair(2, 3), Pair(-1, -3), Pair(2, -3), Pair(1, -3), Pair(2, -4), Pair(-1, -3), Pair(1, -2), Pair(0, -3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(5, -59), Pair(21, 9), Pair(3, -9), Pair(60, -28), Pair(-66, 28), Pair(47, 1), Pair(-29, -90), Pair(-99, -30),
        Pair(-38, -29), Pair(4, -14), Pair(-11, 6), Pair(22, -26), Pair(5, -11), Pair(-1, -45), Pair(73, -46), Pair(-9, -10),
        Pair(147, -1), Pair(7, -2), Pair(-14, -9), Pair(5, -1), Pair(36, -12), Pair(47, -41), Pair(49, -58), Pair(14, -20),
        Pair(12, 21), Pair(3, -2), Pair(10, 10), Pair(22, -2), Pair(14, -4), Pair(25, -21), Pair(15, -13), Pair(27, -18),
        Pair(-2, 27), Pair(-31, -15), Pair(7, 1), Pair(2, 5), Pair(8, 10), Pair(9, 5), Pair(9, -21), Pair(14, -5),
        Pair(-14, -3), Pair(3, -10), Pair(-10, 11), Pair(9, -4), Pair(5, -1), Pair(1, 1), Pair(8, 13), Pair(0, -8),
        Pair(8, 62), Pair(-11, -23), Pair(0, 10), Pair(3, 0), Pair(1, -1), Pair(11, -26), Pair(19, -20), Pair(0, -11),
        Pair(1, 24), Pair(-3, 13), Pair(15, 15), Pair(10, 5), Pair(-18, 11), Pair(-8, -17), Pair(12, -5), Pair(-33, -7)
      },
      { // Piece 2
        Pair(7, 20), Pair(3, 48), Pair(1, 53), Pair(-11, 47), Pair(28, 30), Pair(-91, 26), Pair(-70, 75), Pair(-19, 36),
        Pair(13, 43), Pair(-8, 35), Pair(-1, 32), Pair(-8, 41), Pair(37, 26), Pair(-53, 64), Pair(24, 44), Pair(11, 2),
        Pair(-13, -21), Pair(-14, 25), Pair(-50, 68), Pair(-1, 30), Pair(-8, 54), Pair(35, 31), Pair(-42, 40), Pair(34, -14),
        Pair(24, 27), Pair(14, -40), Pair(-12, 19), Pair(-22, 50), Pair(12, 18), Pair(9, 23), Pair(8, 17), Pair(-5, 34),
        Pair(-21, 43), Pair(-18, -4), Pair(1, 31), Pair(2, 23), Pair(11, 13), Pair(10, 5), Pair(-12, 31), Pair(-5, 0),
        Pair(11, 45), Pair(-11, 38), Pair(-7, 16), Pair(3, 14), Pair(3, 10), Pair(0, 16), Pair(9, 6), Pair(7, 15),
        Pair(7, 94), Pair(1, 7), Pair(5, 13), Pair(2, 2), Pair(-1, 11), Pair(2, 6), Pair(8, 6), Pair(0, 34),
        Pair(-18, 46), Pair(16, 57), Pair(0, 20), Pair(0, -2), Pair(0, 26), Pair(-4, 8), Pair(-30, 43), Pair(-9, -2)
      },
      { // Piece 3
        Pair(-10, 37), Pair(-24, 44), Pair(7, 45), Pair(-6, 22), Pair(2, 34), Pair(61, 11), Pair(51, 12), Pair(65, 25),
        Pair(8, 50), Pair(-4, 24), Pair(15, 28), Pair(-4, 32), Pair(8, 28), Pair(-28, 47), Pair(59, 26), Pair(-16, 48),
        Pair(-6, 67), Pair(6, 35), Pair(-6, 39), Pair(22, 29), Pair(-11, 49), Pair(29, 27), Pair(13, 20), Pair(15, 16),
        Pair(-15, 39), Pair(7, 50), Pair(14, 13), Pair(13, 9), Pair(14, 45), Pair(35, 15), Pair(51, 6), Pair(5, 30),
        Pair(-12, 40), Pair(18, 18), Pair(0, 13), Pair(-20, 16), Pair(2, 16), Pair(-9, 10), Pair(20, 5), Pair(4, 40),
        Pair(-14, 17), Pair(-4, 22), Pair(-7, 14), Pair(-20, 24), Pair(-1, 27), Pair(-7, 11), Pair(-1, 28), Pair(9, 42),
        Pair(-3, 20), Pair(-13, 12), Pair(-4, 29), Pair(9, 7), Pair(4, 10), Pair(6, 28), Pair(-22, 41), Pair(15, -3),
        Pair(-2, 7), Pair(-4, 13), Pair(-1, 21), Pair(-1, 13), Pair(2, 12), Pair(6, 16), Pair(10, 29), Pair(4, 23)
      },
      { // Piece 4
        Pair(-24, 85), Pair(-47, 104), Pair(-21, 37), Pair(-38, 70), Pair(13, 33), Pair(-97, 100), Pair(62, 5), Pair(27, -8),
        Pair(3, 72), Pair(20, 12), Pair(8, 35), Pair(-5, 45), Pair(-6, 85), Pair(22, 73), Pair(-8, 80), Pair(1, 58),
        Pair(-184, 94), Pair(25, 24), Pair(-13, 103), Pair(8, 65), Pair(-12, 34), Pair(35, 49), Pair(18, 88), Pair(36, 15),
        Pair(21, -17), Pair(2, 12), Pair(-2, 17), Pair(3, 63), Pair(-13, 65), Pair(39, 34), Pair(23, 25), Pair(28, 31),
        Pair(4, -7), Pair(12, 16), Pair(7, 28), Pair(-6, 33), Pair(-2, 43), Pair(15, 42), Pair(32, -13), Pair(13, 17),
        Pair(-10, 46), Pair(-2, 19), Pair(4, 25), Pair(5, 22), Pair(-5, 11), Pair(6, 36), Pair(9, 24), Pair(35, -4),
        Pair(-12, 41), Pair(3, 6), Pair(4, 8), Pair(5, 12), Pair(9, 11), Pair(-3, 35), Pair(10, 15), Pair(16, 16),
        Pair(6, 22), Pair(6, 13), Pair(-8, 54), Pair(0, 17), Pair(8, 18), Pair(2, 14), Pair(42, 52), Pair(-4, -3)
      },
      { // Piece 5
        Pair(-34, -78), Pair(21, 39), Pair(68, 11), Pair(65, -4), Pair(45, -65), Pair(5, -119), Pair(-21, -3), Pair(-32, -114),
        Pair(-30, -117), Pair(90, -36), Pair(14, -76), Pair(90, -13), Pair(44, -20), Pair(40, -26), Pair(34, -31), Pair(-23, 39),
        Pair(1, 10), Pair(-49, -46), Pair(29, -22), Pair(33, 5), Pair(136, -46), Pair(107, -43), Pair(-8, 2), Pair(8, -3),
        Pair(-8, -139), Pair(96, 5), Pair(-37, 3), Pair(10, -6), Pair(38, -9), Pair(68, -2), Pair(2, 19), Pair(4, -25),
        Pair(-66, -24), Pair(-53, -7), Pair(94, -29), Pair(71, 0), Pair(8, 22), Pair(12, 4), Pair(37, -7), Pair(35, -3),
        Pair(82, -69), Pair(5, 40), Pair(0, 10), Pair(12, 11), Pair(3, -3), Pair(45, -5), Pair(-15, 11), Pair(21, -16),
        Pair(-8, 41), Pair(4, 13), Pair(20, 14), Pair(16, 10), Pair(15, -8), Pair(4, -5), Pair(1, 2), Pair(-4, 7),
        Pair(6, 44), Pair(12, 24), Pair(10, 10), Pair(9, 21), Pair(4, -4), Pair(-8, 4), Pair(-1, -4), Pair(6, -7)
      }
    }},
    {{ // Bucket 17
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-54, 59), Pair(-1, -3), Pair(52, -13), Pair(60, 7), Pair(39, 0), Pair(183, -11), Pair(41, 32), Pair(-3, 21),
        Pair(0, 6), Pair(-14, -15), Pair(16, 10), Pair(17, 10), Pair(-9, 15), Pair(16, 17), Pair(25, 11), Pair(-8, 38),
        Pair(8, 27), Pair(-5, -8), Pair(-6, 6), Pair(6, -1), Pair(9, 4), Pair(4, 2), Pair(6, 8), Pair(-7, 5),
        Pair(2, 3), Pair(-1, 5), Pair(1, 7), Pair(-3, 0), Pair(-3, -1), Pair(-2, 5), Pair(0, -4), Pair(-1, 2),
        Pair(2, -1), Pair(-1, -1), Pair(1, -2), Pair(0, -6), Pair(0, -1), Pair(-7, 0), Pair(-1, -3), Pair(-1, -2),
        Pair(-1, 3), Pair(4, 1), Pair(1, 2), Pair(-1, -5), Pair(-3, -7), Pair(-5, -1), Pair(-1, 0), Pair(-1, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-25, -84), Pair(-95, -26), Pair(7, 2), Pair(35, -46), Pair(-48, 59), Pair(28, 12), Pair(125, -56), Pair(7, 34),
        Pair(10, 1), Pair(-53, -65), Pair(28, -12), Pair(18, -13), Pair(70, -20), Pair(24, -19), Pair(-34, 1), Pair(2, -4),
        Pair(0, -10), Pair(-3, 56), Pair(-8, 9), Pair(-2, 35), Pair(37, -13), Pair(-30, 6), Pair(19, -32), Pair(30, -20),
        Pair(-9, 4), Pair(3, 33), Pair(-49, 46), Pair(4, 13), Pair(4, 4), Pair(3, 11), Pair(13, 10), Pair(7, -11),
        Pair(-16, -6), Pair(-25, 28), Pair(-11, 17), Pair(1, 10), Pair(3, 5), Pair(-1, 11), Pair(13, -6), Pair(17, -6),
        Pair(4, 13), Pair(-22, -2), Pair(1, 2), Pair(-14, 15), Pair(3, -2), Pair(3, 7), Pair(5, 11), Pair(7, 11),
        Pair(35, -30), Pair(-17, 53), Pair(-3, 7), Pair(0, 2), Pair(2, 4), Pair(9, 2), Pair(11, 7), Pair(7, 21),
        Pair(-32, -56), Pair(-4, 7), Pair(12, -13), Pair(-22, 52), Pair(2, 9), Pair(16, 15), Pair(4, 21), Pair(-41, -24)
      },
      { // Piece 2
        Pair(-42, 35), Pair(-142, 45), Pair(-100, 43), Pair(-42, 60), Pair(-68, 68), Pair(-123, 63), Pair(61, 44), Pair(116, 16),
        Pair(-85, 43), Pair(-5, 24), Pair(1, 37), Pair(-10, 30), Pair(-53, 35), Pair(4, 68), Pair(-45, 62), Pair(20, 25),
        Pair(9, 9), Pair(-19, 6), Pair(-2, 36), Pair(-1, 18), Pair(5, 26), Pair(-17, 52), Pair(-8, 35), Pair(16, 22),
        Pair(-6, -3), Pair(8, 32), Pair(-101, 45), Pair(15, 17), Pair(-20, 39), Pair(-1, 30), Pair(16, 13), Pair(3, 5),
        Pair(-26, 28), Pair(-15, 13), Pair(-16, 27), Pair(-5, 35), Pair(7, 9), Pair(-6, 12), Pair(5, 11), Pair(9, -6),
        Pair(-6, 21), Pair(2, 16), Pair(-8, 12), Pair(9, 16), Pair(-4, 8), Pair(5, 27), Pair(14, 0), Pair(7, 29),
        Pair(-2, 55), Pair(4, 29), Pair(13, 3), Pair(-1, 9), Pair(1, 15), Pair(-1, 9), Pair(9, 18), Pair(6, 1),
        Pair(6, 47), Pair(5, 57), Pair(1, 19), Pair(6, 3), Pair(11, 6), Pair(10, 3), Pair(21, 28), Pair(-9, -9)
      },
      { // Piece 3
        Pair(-2, 27), Pair(-50, 31), Pair(-21, 35), Pair(-5, 14), Pair(27, 2), Pair(-26, 38), Pair(14, 20), Pair(-15, 45),
        Pair(3, 20), Pair(35, 25), Pair(-35, 35), Pair(3, 18), Pair(-4, 23), Pair(13, -14), Pair(-25, 52), Pair(53, 10),
        Pair(-14, 10), Pair(42, 53), Pair(-2, 12), Pair(14, 7), Pair(43, 9), Pair(16, 7), Pair(-2, 14), Pair(39, 25),
        Pair(46, -3), Pair(-6, 10), Pair(53, 14), Pair(-1, 7), Pair(-11, 7), Pair(14, -2), Pair(7, 9), Pair(14, 6),
        Pair(12, 6), Pair(-34, 23), Pair(-23, 6), Pair(-8, 7), Pair(4, 2), Pair(2, 35), Pair(27, 4), Pair(23, -7),
        Pair(-2, 1), Pair(-5, -11), Pair(-8, 15), Pair(14, 15), Pair(0, 1), Pair(-8, 28), Pair(0, 18), Pair(4, 42),
        Pair(-23, 2), Pair(-14, 12), Pair(-11, 2), Pair(-8, 14), Pair(9, 8), Pair(0, 4), Pair(-20, 25), Pair(-26, 31),
        Pair(-3, 9), Pair(-7, 2), Pair(-7, 9), Pair(0, 5), Pair(2, 8), Pair(2, 12), Pair(0, 11), Pair(3, 18)
      },
      { // Piece 4
        Pair(30, 11), Pair(1, -15), Pair(-64, 20), Pair(65, 19), Pair(-18, 29), Pair(-20, 10), Pair(-62, 95), Pair(39, -20),
        Pair(14, -36), Pair(-12, 66), Pair(29, 17), Pair(-9, 30), Pair(40, 36), Pair(18, 23), Pair(42, -43), Pair(4, 15),
        Pair(3, 28), Pair(138, -84), Pair(-25, 95), Pair(21, 34), Pair(15, 7), Pair(16, 32), Pair(-14, 49), Pair(17, -1),
        Pair(-22, 1), Pair(13, 31), Pair(-42, 134), Pair(13, 5), Pair(21, 13), Pair(18, 26), Pair(16, 1), Pair(29, 20),
        Pair(-9, 15), Pair(1, 20), Pair(-17, 23), Pair(3, 13), Pair(3, 30), Pair(10, 29), Pair(13, 30), Pair(-2, 6),
        Pair(-1, 2), Pair(9, 12), Pair(8, 6), Pair(0, 30), Pair(17, 0), Pair(-1, 11), Pair(13, 21), Pair(-1, 29),
        Pair(11, 31), Pair(11, 11), Pair(1, -6), Pair(3, 4), Pair(4, 17), Pair(3, 20), Pair(13, -13), Pair(29, 3),
        Pair(-2, 41), Pair(-8, 16), Pair(1, -13), Pair(4, 18), Pair(-3, 16), Pair(-16, 12), Pair(55, 26), Pair(36, 2)
      },
      { // Piece 5
        Pair(-5, -197), Pair(0, -38), Pair(-2, 26), Pair(4, 14), Pair(65, 120), Pair(-7, 22), Pair(-18, 95), Pair(32, -25),
        Pair(-24, -19), Pair(16, -81), Pair(60, -71), Pair(92, -20), Pair(-65, -22), Pair(14, -55), Pair(58, -33), Pair(-48, 46),
        Pair(-103, -11), Pair(-13, -81), Pair(35, -85), Pair(29, -24), Pair(-38, 8), Pair(37, -22), Pair(66, -52), Pair(52, -27),
        Pair(-12, -121), Pair(8, -126), Pair(140, 0), Pair(7, -37), Pair(-1, -9), Pair(64, -10), Pair(-3, 16), Pair(-58, -1),
        Pair(23, -38), Pair(-4, -72), Pair(18, -32), Pair(-19, -22), Pair(-8, 7), Pair(30, -9), Pair(7, -4), Pair(-18, 0),
        Pair(-31, 54), Pair(75, -53), Pair(-34, 12), Pair(22, -5), Pair(26, 3), Pair(3, -4), Pair(13, -3), Pair(43, -15),
        Pair(-27, -15), Pair(-17, 24), Pair(-3, 10), Pair(18, 0), Pair(3, -3), Pair(2, -9), Pair(0, 1), Pair(0, 2),
        Pair(1, -16), Pair(15, 6), Pair(16, 14), Pair(8, 6), Pair(-1, 18), Pair(6, -3), Pair(-1, -3), Pair(2, -12)
      }
    }},
    {{ // Bucket 18
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-2, 43), Pair(-33, 36), Pair(-14, -45), Pair(11, 14), Pair(37, 26), Pair(35, 14), Pair(-29, 59), Pair(-20, 19),
        Pair(6, 22), Pair(0, 18), Pair(5, -11), Pair(-6, -7), Pair(-7, 11), Pair(-10, 9), Pair(14, 10), Pair(-9, 16),
        Pair(9, -3), Pair(7, 17), Pair(-9, -11), Pair(3, 44), Pair(3, 5), Pair(6, 4), Pair(11, -2), Pair(-4, 13),
        Pair(0, -1), Pair(-2, -4), Pair(-1, -1), Pair(-2, 4), Pair(-4, -1), Pair(0, 1), Pair(3, -2), Pair(-4, 4),
        Pair(0, -1), Pair(-2, -4), Pair(1, 1), Pair(0, 1), Pair(2, -1), Pair(-5, -2), Pair(0, -6), Pair(0, 3),
        Pair(-2, 2), Pair(-3, -2), Pair(1, 6), Pair(-1, 1), Pair(5, -9), Pair(-2, -5), Pair(1, -1), Pair(2, -2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(30, -6), Pair(7, 2), Pair(-32, 30), Pair(8, -8), Pair(38, -39), Pair(175, -45), Pair(89, -26), Pair(-91, -55),
        Pair(-19, 1), Pair(17, 19), Pair(-59, 30), Pair(-36, 62), Pair(38, -2), Pair(-14, 10), Pair(6, -25), Pair(105, -6),
        Pair(-25, 60), Pair(-19, 34), Pair(-2, 42), Pair(23, 14), Pair(17, 31), Pair(22, 21), Pair(1, 1), Pair(21, 21),
        Pair(10, 31), Pair(-16, -24), Pair(-2, 46), Pair(-57, 77), Pair(11, 19), Pair(-7, 13), Pair(10, 15), Pair(36, -6),
        Pair(5, 4), Pair(-23, 25), Pair(-1, 22), Pair(-16, 29), Pair(0, 33), Pair(-5, 0), Pair(7, 25), Pair(5, 22),
        Pair(-19, 29), Pair(11, 16), Pair(-8, 12), Pair(11, 12), Pair(-13, 30), Pair(8, 13), Pair(-1, 26), Pair(9, 12),
        Pair(-3, 19), Pair(-14, 62), Pair(10, 27), Pair(0, 22), Pair(6, 12), Pair(4, 5), Pair(8, -5), Pair(17, -24),
        Pair(1, 62), Pair(3, 4), Pair(8, -41), Pair(28, 8), Pair(3, 26), Pair(20, -16), Pair(7, 22), Pair(15, -12)
      },
      { // Piece 2
        Pair(-86, -104), Pair(-21, 18), Pair(2, 42), Pair(-59, 6), Pair(0, 21), Pair(-10, 29), Pair(16, 38), Pair(38, -25),
        Pair(-1, 20), Pair(-84, 31), Pair(7, 34), Pair(-15, 37), Pair(27, 0), Pair(36, 39), Pair(-52, 33), Pair(4, 26),
        Pair(-12, 34), Pair(-38, 39), Pair(2, 60), Pair(11, 23), Pair(4, 37), Pair(-46, 34), Pair(-12, 52), Pair(20, -12),
        Pair(-19, 18), Pair(-21, 29), Pair(0, 44), Pair(-56, 8), Pair(-6, 19), Pair(-30, 67), Pair(7, 13), Pair(3, 17),
        Pair(-26, 51), Pair(-28, 22), Pair(3, 29), Pair(-25, 31), Pair(0, 22), Pair(-4, 30), Pair(2, 25), Pair(-3, 43),
        Pair(2, 11), Pair(7, 28), Pair(3, 20), Pair(4, 21), Pair(1, 9), Pair(0, 11), Pair(23, 18), Pair(11, 7),
        Pair(-3, 27), Pair(7, 16), Pair(8, 56), Pair(12, 13), Pair(1, -1), Pair(-3, 17), Pair(1, 2), Pair(4, 2),
        Pair(16, -7), Pair(16, 41), Pair(8, 17), Pair(-32, 53), Pair(-3, 30), Pair(9, 16), Pair(-18, 64), Pair(-14, 18)
      },
      { // Piece 3
        Pair(-8, 5), Pair(-2, 11), Pair(14, 10), Pair(23, 10), Pair(58, -24), Pair(20, 19), Pair(-26, 18), Pair(-38, 32),
        Pair(-9, 14), Pair(-10, 20), Pair(0, 18), Pair(5, 12), Pair(28, -3), Pair(34, 27), Pair(64, -2), Pair(38, -3),
        Pair(-15, 22), Pair(1, -3), Pair(14, 8), Pair(9, -5), Pair(-36, 13), Pair(-23, 14), Pair(-25, 27), Pair(-40, 32),
        Pair(6, -4), Pair(-19, -30), Pair(1, 2), Pair(10, -34), Pair(-8, -3), Pair(14, 5), Pair(18, -13), Pair(10, -5),
        Pair(-4, 16), Pair(-12, 11), Pair(13, -13), Pair(-20, 16), Pair(13, 13), Pair(6, 18), Pair(20, 6), Pair(42, -29),
        Pair(-14, 11), Pair(-16, 17), Pair(-11, 29), Pair(-10, 27), Pair(-13, 16), Pair(4, 16), Pair(14, -2), Pair(-3, 30),
        Pair(-13, 38), Pair(10, 2), Pair(-26, 29), Pair(-3, 8), Pair(-9, 28), Pair(6, 23), Pair(5, -3), Pair(19, 14),
        Pair(1, 2), Pair(-4, 1), Pair(0, 4), Pair(-7, 2), Pair(-2, 4), Pair(0, 9), Pair(19, -7), Pair(7, 13)
      },
      { // Piece 4
        Pair(13, 0), Pair(-1, 25), Pair(36, -24), Pair(10, 13), Pair(49, 23), Pair(62, -6), Pair(101, -1), Pair(75, -1),
        Pair(5, 24), Pair(-8, 18), Pair(9, 35), Pair(-31, 10), Pair(-18, 42), Pair(-2, 60), Pair(18, 26), Pair(-43, 36),
        Pair(17, -6), Pair(-7, 61), Pair(36, -24), Pair(40, 29), Pair(6, 77), Pair(3, 41), Pair(-11, 68), Pair(14, -11),
        Pair(-7, 20), Pair(28, -24), Pair(31, 11), Pair(-17, 147), Pair(16, 41), Pair(6, 39), Pair(1, 20), Pair(7, 65),
        Pair(-4, 24), Pair(-16, 34), Pair(9, -5), Pair(5, 17), Pair(8, 40), Pair(15, -5), Pair(25, -1), Pair(14, 24),
        Pair(-3, 35), Pair(7, 0), Pair(12, 8), Pair(1, 33), Pair(9, -22), Pair(0, 3), Pair(3, 30), Pair(2, 30),
        Pair(16, 17), Pair(7, -6), Pair(9, 23), Pair(7, 11), Pair(1, 2), Pair(2, 12), Pair(2, -12), Pair(57, -18),
        Pair(15, -7), Pair(8, -6), Pair(-2, 22), Pair(3, 17), Pair(4, 31), Pair(11, 28), Pair(-25, 29), Pair(14, -70)
      },
      { // Piece 5
        Pair(7, 43), Pair(-78, -68), Pair(-72, -79), Pair(-26, 6), Pair(23, 56), Pair(46, 9), Pair(11, -94), Pair(-29, -137),
        Pair(-24, -36), Pair(22, -67), Pair(-20, -58), Pair(78, -24), Pair(8, -31), Pair(-42, 17), Pair(-12, -7), Pair(-39, 23),
        Pair(-14, 0), Pair(-18, -59), Pair(-19, -134), Pair(70, -94), Pair(71, -15), Pair(-17, 3), Pair(-85, 29), Pair(53, 9),
        Pair(-57, 42), Pair(58, -10), Pair(26, -83), Pair(53, 15), Pair(-72, -3), Pair(74, -16), Pair(63, -17), Pair(21, 5),
        Pair(32, -6), Pair(3, -29), Pair(43, -54), Pair(77, -26), Pair(-16, 4), Pair(-21, 6), Pair(1, -5), Pair(-47, 32),
        Pair(-11, 30), Pair(-44, 42), Pair(-45, -6), Pair(0, 13), Pair(-6, -1), Pair(-6, 7), Pair(5, 2), Pair(20, -17),
        Pair(-65, 30), Pair(0, 13), Pair(-32, 31), Pair(-5, 15), Pair(-1, 12), Pair(-2, 10), Pair(2, 5), Pair(12, -9),
        Pair(35, -23), Pair(14, -5), Pair(1, 14), Pair(-30, 39), Pair(-2, 5), Pair(2, 18), Pair(1, 1), Pair(6, -17)
      }
    }},
    {{ // Bucket 19
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(9, 27), Pair(20, 3), Pair(-71, 70), Pair(85, -11), Pair(-24, 75), Pair(-33, -5), Pair(-44, 48), Pair(-1, -3),
        Pair(3, 7), Pair(13, -3), Pair(-3, 32), Pair(-19, 8), Pair(-7, 20), Pair(8, -5), Pair(15, -4), Pair(-11, 20),
        Pair(3, 2), Pair(-7, 2), Pair(-6, -3), Pair(-6, -7), Pair(-8, 7), Pair(-5, -2), Pair(15, 7), Pair(-5, 9),
        Pair(1, 1), Pair(1, -7), Pair(2, -2), Pair(0, 1), Pair(0, -1), Pair(1, 3), Pair(-4, -4), Pair(2, 2),
        Pair(1, -2), Pair(-2, -1), Pair(-3, -7), Pair(2, 4), Pair(-2, -3), Pair(0, -1), Pair(0, 0), Pair(0, 4),
        Pair(-1, 3), Pair(1, -2), Pair(-4, -2), Pair(-3, 12), Pair(-2, -6), Pair(0, -2), Pair(2, 0), Pair(0, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-2, 20), Pair(-86, 25), Pair(29, 27), Pair(-90, 75), Pair(-93, 42), Pair(87, -14), Pair(-82, -3), Pair(-81, 29),
        Pair(-32, 29), Pair(-28, 7), Pair(6, 50), Pair(76, -48), Pair(-47, 49), Pair(-9, -22), Pair(47, -13), Pair(30, -13),
        Pair(104, -35), Pair(9, 23), Pair(-6, 22), Pair(-35, 28), Pair(13, 20), Pair(19, 20), Pair(4, 42), Pair(62, -34),
        Pair(-24, 21), Pair(5, 19), Pair(12, -3), Pair(-6, 48), Pair(5, 16), Pair(-4, 28), Pair(-5, 14), Pair(-3, -3),
        Pair(-9, -4), Pair(7, 4), Pair(-20, 29), Pair(1, 28), Pair(14, 13), Pair(-4, 23), Pair(-28, 24), Pair(9, 14),
        Pair(1, -20), Pair(-10, 2), Pair(2, 3), Pair(-15, 19), Pair(-11, 22), Pair(-5, 10), Pair(3, 13), Pair(-3, 19),
        Pair(1, -14), Pair(-8, 23), Pair(9, -5), Pair(-5, 42), Pair(3, 1), Pair(2, 20), Pair(-2, 39), Pair(5, 8),
        Pair(65, -152), Pair(1, -9), Pair(-23, 36), Pair(-27, 27), Pair(8, 32), Pair(13, 15), Pair(3, 29), Pair(-31, 79)
      },
      { // Piece 2
        Pair(-73, 65), Pair(-167, -48), Pair(41, 15), Pair(20, -3), Pair(1, 19), Pair(-17, 18), Pair(-49, 35), Pair(95, -44),
        Pair(-16, 43), Pair(11, 40), Pair(-21, -7), Pair(-19, 43), Pair(-19, 77), Pair(-32, 47), Pair(18, 53), Pair(22, -41),
        Pair(-2, 24), Pair(-4, 32), Pair(-7, 33), Pair(75, -12), Pair(-12, 23), Pair(35, -8), Pair(-2, 37), Pair(-6, 31),
        Pair(2, 29), Pair(-13, 28), Pair(2, 48), Pair(8, 46), Pair(-26, 8), Pair(18, 13), Pair(-6, 43), Pair(-11, 6),
        Pair(-17, -10), Pair(9, 27), Pair(-14, 10), Pair(-4, 25), Pair(-31, 29), Pair(-4, 22), Pair(-6, 12), Pair(7, 34),
        Pair(8, 14), Pair(-2, 10), Pair(-3, 31), Pair(-4, 13), Pair(-3, 27), Pair(-10, 14), Pair(-5, -9), Pair(6, 28),
        Pair(10, -14), Pair(10, 3), Pair(-4, 12), Pair(1, 35), Pair(-4, 6), Pair(8, 23), Pair(2, -4), Pair(0, -30),
        Pair(-13, 26), Pair(9, 0), Pair(3, 19), Pair(-15, 3), Pair(-14, 6), Pair(6, -2), Pair(34, 21), Pair(24, -18)
      },
      { // Piece 3
        Pair(-4, 10), Pair(-47, 10), Pair(14, 13), Pair(-30, 45), Pair(-61, 25), Pair(-11, -16), Pair(110, -2), Pair(-15, 26),
        Pair(-8, 11), Pair(-2, 16), Pair(-6, 0), Pair(-46, -5), Pair(14, 5), Pair(9, -8), Pair(-13, 27), Pair(7, -16),
        Pair(-28, 21), Pair(0, -10), Pair(17, 3), Pair(94, -13), Pair(33, -16), Pair(48, -24), Pair(-10, -10), Pair(19, 14),
        Pair(16, -20), Pair(-17, 0), Pair(13, 17), Pair(0, 0), Pair(31, -2), Pair(-3, 0), Pair(28, 6), Pair(-21, 10),
        Pair(-3, 4), Pair(-9, -14), Pair(16, -2), Pair(-2, 2), Pair(6, 0), Pair(-9, 19), Pair(-6, -21), Pair(7, 1),
        Pair(6, 1), Pair(12, 14), Pair(1, 10), Pair(8, -10), Pair(-8, 25), Pair(14, 11), Pair(-2, -11), Pair(-14, 68),
        Pair(-5, 13), Pair(18, -2), Pair(-14, 13), Pair(-12, 11), Pair(-2, 0), Pair(10, 1), Pair(-3, -3), Pair(27, 12),
        Pair(2, -3), Pair(2, -6), Pair(-2, -1), Pair(-7, 0), Pair(-3, -3), Pair(1, 8), Pair(-7, -1), Pair(6, -3)
      },
      { // Piece 4
        Pair(9, 50), Pair(3, -15), Pair(16, 13), Pair(-14, 69), Pair(30, -32), Pair(-66, 49), Pair(-40, -21), Pair(39, 81),
        Pair(28, -3), Pair(-19, 16), Pair(-29, 17), Pair(-18, 68), Pair(39, -5), Pair(5, 62), Pair(17, 45), Pair(1, -24),
        Pair(-4, 8), Pair(-6, 14), Pair(-44, 52), Pair(47, 75), Pair(-7, 45), Pair(21, 53), Pair(8, 61), Pair(7, 31),
        Pair(-4, 6), Pair(5, -30), Pair(-23, -62), Pair(22, 23), Pair(70, -29), Pair(12, 24), Pair(-5, 64), Pair(-9, 42),
        Pair(0, 35), Pair(6, -23), Pair(-11, 30), Pair(9, 11), Pair(1, -1), Pair(10, -1), Pair(6, 30), Pair(-6, 3),
        Pair(-1, 26), Pair(-6, 18), Pair(-8, -10), Pair(2, 9), Pair(-2, 1), Pair(-2, -5), Pair(-6, 6), Pair(-22, 8),
        Pair(6, -22), Pair(5, -12), Pair(-2, 0), Pair(4, 16), Pair(2, 1), Pair(5, -3), Pair(-12, 18), Pair(14, -22),
        Pair(4, 17), Pair(-5, -5), Pair(-3, 9), Pair(6, 16), Pair(8, 8), Pair(-6, 15), Pair(-6, 4), Pair(53, -16)
      },
      { // Piece 5
        Pair(-5, -117), Pair(-18, -32), Pair(-9, -36), Pair(10, -10), Pair(0, -86), Pair(-10, 12), Pair(-4, -56), Pair(-47, -106),
        Pair(-11, -42), Pair(4, -122), Pair(57, -50), Pair(-5, -118), Pair(-38, 10), Pair(-4, 23), Pair(15, 2), Pair(2, 13),
        Pair(43, -76), Pair(-83, 1), Pair(-20, -73), Pair(17, -92), Pair(70, -58), Pair(64, -21), Pair(8, 11), Pair(43, 13),
        Pair(17, -22), Pair(-1, 3), Pair(30, -67), Pair(50, -95), Pair(-35, 0), Pair(-26, -3), Pair(-12, -31), Pair(45, -13),
        Pair(82, -10), Pair(61, -33), Pair(-1, -17), Pair(29, -52), Pair(68, -50), Pair(62, -23), Pair(6, -5), Pair(73, -46),
        Pair(22, -20), Pair(-70, 17), Pair(-39, 18), Pair(-41, 1), Pair(-12, 10), Pair(-17, 3), Pair(-15, 4), Pair(50, -21),
        Pair(-20, 22), Pair(32, -10), Pair(-13, 30), Pair(-19, 21), Pair(2, 4), Pair(-13, 13), Pair(3, 5), Pair(5, 0),
        Pair(-30, 22), Pair(-12, 20), Pair(-6, 4), Pair(8, 5), Pair(1, 24), Pair(8, -11), Pair(3, 5), Pair(-6, 3)
      }
    }},
    {{ // Bucket 20
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-46, 23), Pair(41, 7), Pair(-3, 13), Pair(-23, 23), Pair(-26, 13), Pair(-54, 119), Pair(-47, 33), Pair(11, -17),
        Pair(-3, 8), Pair(-8, 14), Pair(-5, 7), Pair(13, 0), Pair(9, 27), Pair(11, 12), Pair(-17, 6), Pair(-18, 11),
        Pair(-1, 6), Pair(5, 2), Pair(9, 7), Pair(0, 60), Pair(-5, -4), Pair(14, -3), Pair(10, -3), Pair(-6, 8),
        Pair(-1, -2), Pair(0, 1), Pair(0, -2), Pair(1, 1), Pair(7, -2), Pair(-2, -1), Pair(-1, -1), Pair(-4, 3),
        Pair(1, -1), Pair(2, -2), Pair(0, -4), Pair(2, -1), Pair(0, 1), Pair(-1, 0), Pair(-4, 2), Pair(-3, 1),
        Pair(0, 1), Pair(2, 2), Pair(1, -3), Pair(3, 1), Pair(5, 1), Pair(-1, -4), Pair(0, 1), Pair(-2, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(35, -11), Pair(-131, -2), Pair(-76, 50), Pair(-32, -27), Pair(-3, -38), Pair(11, 54), Pair(23, -27), Pair(96, -36),
        Pair(3, 55), Pair(-4, 29), Pair(-12, 5), Pair(-36, 34), Pair(-37, -9), Pair(-52, 23), Pair(9, -16), Pair(63, 13),
        Pair(28, -9), Pair(-15, 11), Pair(-16, 31), Pair(-37, 35), Pair(-78, 56), Pair(12, 26), Pair(-27, 39), Pair(33, 22),
        Pair(9, 25), Pair(0, 2), Pair(6, 3), Pair(-11, 50), Pair(7, 42), Pair(10, -10), Pair(11, 10), Pair(4, 9),
        Pair(19, 0), Pair(-14, -10), Pair(-3, 11), Pair(-15, 6), Pair(4, 5), Pair(-10, -15), Pair(-8, 22), Pair(-14, -1),
        Pair(0, 15), Pair(2, 13), Pair(-7, 6), Pair(2, -5), Pair(-4, -17), Pair(0, 11), Pair(-6, 13), Pair(9, 19),
        Pair(-12, -1), Pair(-6, 4), Pair(9, 4), Pair(3, 17), Pair(-6, 17), Pair(-6, 3), Pair(12, -15), Pair(-3, -10),
        Pair(56, 43), Pair(6, 11), Pair(-32, -11), Pair(15, 1), Pair(6, 11), Pair(10, 10), Pair(9, 18), Pair(47, -24)
      },
      { // Piece 2
        Pair(45, 38), Pair(-85, 63), Pair(52, 17), Pair(-23, 53), Pair(-30, 19), Pair(-60, 39), Pair(2, -53), Pair(6, 37),
        Pair(-2, -3), Pair(-14, 20), Pair(-9, 12), Pair(-49, 1), Pair(-5, 26), Pair(28, -10), Pair(7, -2), Pair(15, 17),
        Pair(-5, -5), Pair(16, 25), Pair(-6, 20), Pair(-14, 31), Pair(23, 9), Pair(-50, 47), Pair(-17, 30), Pair(-9, 18),
        Pair(13, -2), Pair(-8, 7), Pair(6, 17), Pair(-115, -24), Pair(4, 47), Pair(-117, 48), Pair(-8, 8), Pair(2, 20),
        Pair(-4, 10), Pair(-2, 25), Pair(-8, 4), Pair(-20, 4), Pair(-9, 1), Pair(-11, 10), Pair(-12, 9), Pair(7, 6),
        Pair(8, 20), Pair(0, 4), Pair(4, -3), Pair(-4, 1), Pair(0, 9), Pair(-11, 1), Pair(-14, 13), Pair(-13, 1),
        Pair(-20, -22), Pair(1, 0), Pair(-3, 17), Pair(4, 12), Pair(-3, 0), Pair(-1, 4), Pair(-11, -1), Pair(-5, -9),
        Pair(1, -9), Pair(4, 17), Pair(4, 13), Pair(-23, 0), Pair(-5, 21), Pair(-6, 4), Pair(-28, 48), Pair(-14, 9)
      },
      { // Piece 3
        Pair(-4, 0), Pair(-20, -4), Pair(-12, 5), Pair(-10, 12), Pair(90, -17), Pair(97, -43), Pair(-107, 33), Pair(49, 6),
        Pair(22, 2), Pair(-19, 24), Pair(28, 8), Pair(2, 0), Pair(20, 1), Pair(-15, -19), Pair(-14, 10), Pair(24, -17),
        Pair(-10, 9), Pair(10, -15), Pair(5, 3), Pair(-8, 16), Pair(12, -23), Pair(8, 32), Pair(18, -23), Pair(14, -17),
        Pair(14, -9), Pair(-11, 11), Pair(-3, 4), Pair(14, -33), Pair(12, -21), Pair(16, -31), Pair(-9, -8), Pair(-1, 7),
        Pair(-7, 22), Pair(-26, 14), Pair(2, -3), Pair(-11, 2), Pair(3, -9), Pair(18, -16), Pair(-29, 6), Pair(5, -24),
        Pair(-3, -3), Pair(5, 8), Pair(-3, 5), Pair(1, 12), Pair(0, -8), Pair(-1, -18), Pair(14, 14), Pair(-4, 18),
        Pair(-12, 19), Pair(9, -4), Pair(-9, 13), Pair(-6, 2), Pair(-14, 1), Pair(14, -3), Pair(-3, -5), Pair(8, 2),
        Pair(4, 0), Pair(1, -2), Pair(3, 2), Pair(-2, -8), Pair(0, -8), Pair(0, 0), Pair(3, 2), Pair(7, -6)
      },
      { // Piece 4
        Pair(0, 18), Pair(-5, 23), Pair(5, -22), Pair(25, 26), Pair(-57, 5), Pair(67, -15), Pair(4, -32), Pair(39, -11),
        Pair(14, 20), Pair(-18, 56), Pair(41, -1), Pair(-19, 13), Pair(-51, 22), Pair(31, -16), Pair(20, -12), Pair(13, 49),
        Pair(5, 16), Pair(-6, 6), Pair(6, -4), Pair(-17, 18), Pair(-40, 10), Pair(-3, 61), Pair(19, 16), Pair(18, 24),
        Pair(-23, 4), Pair(14, 17), Pair(4, 8), Pair(0, 61), Pair(18, -17), Pair(59, -48), Pair(25, 22), Pair(22, -1),
        Pair(-5, 24), Pair(-18, 50), Pair(0, 25), Pair(8, 18), Pair(16, -24), Pair(-1, 12), Pair(5, 17), Pair(3, 25),
        Pair(5, -6), Pair(4, -4), Pair(6, 2), Pair(0, 4), Pair(6, 16), Pair(7, -8), Pair(-3, -11), Pair(-20, -16),
        Pair(13, -8), Pair(4, 8), Pair(2, -15), Pair(0, 11), Pair(5, 12), Pair(3, 7), Pair(-11, 53), Pair(-23, 44),
        Pair(-3, 29), Pair(-4, 14), Pair(6, 7), Pair(1, 5), Pair(5, 11), Pair(18, -40), Pair(-80, 16), Pair(29, 81)
      },
      { // Piece 5
        Pair(0, -37), Pair(52, -104), Pair(30, -62), Pair(-49, -135), Pair(-36, -71), Pair(-7, 22), Pair(-27, -32), Pair(-34, -83),
        Pair(89, 3), Pair(33, -1), Pair(40, -75), Pair(-30, -37), Pair(48, -33), Pair(46, -59), Pair(19, -82), Pair(-49, -31),
        Pair(74, -1), Pair(146, -28), Pair(-9, 0), Pair(22, -95), Pair(-14, -49), Pair(63, -85), Pair(-33, -18), Pair(65, -3),
        Pair(182, -24), Pair(97, -20), Pair(53, -27), Pair(20, -70), Pair(-69, -64), Pair(74, -54), Pair(-4, -27), Pair(20, 3),
        Pair(-11, -7), Pair(-22, 6), Pair(20, -8), Pair(28, -38), Pair(-33, -47), Pair(35, -28), Pair(11, 1), Pair(-38, -1),
        Pair(51, 2), Pair(51, -28), Pair(13, -4), Pair(-14, 12), Pair(-10, -5), Pair(16, 1), Pair(0, 6), Pair(17, -13),
        Pair(47, -22), Pair(8, 8), Pair(-28, 27), Pair(-11, 28), Pair(-3, 16), Pair(10, 12), Pair(0, 8), Pair(6, 6),
        Pair(-18, 25), Pair(5, -2), Pair(2, 15), Pair(1, 18), Pair(-6, 19), Pair(-4, 32), Pair(1, 7), Pair(2, 5)
      }
    }},
    {{ // Bucket 21
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-29, 46), Pair(50, -15), Pair(-73, 62), Pair(4, 12), Pair(-38, 20), Pair(43, 9), Pair(9, 30), Pair(61, -24),
        Pair(12, 13), Pair(-34, 33), Pair(16, 0), Pair(48, -20), Pair(20, -10), Pair(50, -5), Pair(10, 7), Pair(-1, -4),
        Pair(3, 9), Pair(-5, 2), Pair(11, -4), Pair(-2, 2), Pair(7, 36), Pair(-11, -8), Pair(0, -3), Pair(4, -1),
        Pair(0, -3), Pair(-2, 0), Pair(1, 1), Pair(-1, 1), Pair(0, 3), Pair(2, -3), Pair(0, -4), Pair(2, 2),
        Pair(2, -1), Pair(1, -1), Pair(0, -1), Pair(-2, 3), Pair(0, -1), Pair(3, -2), Pair(-3, -5), Pair(-7, 4),
        Pair(1, -2), Pair(0, 2), Pair(1, 2), Pair(-4, -4), Pair(-4, -2), Pair(3, -1), Pair(0, -7), Pair(-5, 4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(74, 3), Pair(-87, 10), Pair(-20, -6), Pair(46, -7), Pair(-37, 4), Pair(57, 37), Pair(-82, 2), Pair(51, 15),
        Pair(-24, 17), Pair(11, -2), Pair(8, 1), Pair(-56, -13), Pair(21, -11), Pair(-54, 58), Pair(-17, -9), Pair(-36, 13),
        Pair(13, 19), Pair(3, -5), Pair(8, 15), Pair(23, 21), Pair(-3, 31), Pair(127, 14), Pair(24, 2), Pair(10, 26),
        Pair(0, -4), Pair(12, 8), Pair(-5, 24), Pair(23, 8), Pair(2, 51), Pair(35, 33), Pair(-1, -39), Pair(32, 3),
        Pair(-4, 10), Pair(17, -13), Pair(-2, 26), Pair(8, 15), Pair(-6, 26), Pair(16, 10), Pair(20, 2), Pair(18, 35),
        Pair(-1, 15), Pair(-1, 13), Pair(10, 10), Pair(-20, 20), Pair(-8, 33), Pair(-4, 10), Pair(-13, 31), Pair(-15, 20),
        Pair(-14, 45), Pair(-37, 22), Pair(-9, 14), Pair(8, 4), Pair(11, 22), Pair(4, 31), Pair(9, 46), Pair(3, 3),
        Pair(-5, -2), Pair(3, 45), Pair(5, -46), Pair(5, 2), Pair(5, 13), Pair(13, 20), Pair(2, 29), Pair(-34, -27)
      },
      { // Piece 2
        Pair(18, 44), Pair(51, -26), Pair(86, -2), Pair(-6, -9), Pair(72, 34), Pair(-74, 33), Pair(56, 36), Pair(-141, -79),
        Pair(-40, 36), Pair(7, 36), Pair(-59, 49), Pair(-52, 40), Pair(-5, 27), Pair(7, 20), Pair(-5, -12), Pair(-8, 59),
        Pair(17, 5), Pair(17, 32), Pair(13, 27), Pair(-26, 20), Pair(21, 11), Pair(47, 69), Pair(-11, 28), Pair(-15, -3),
        Pair(-12, 31), Pair(8, 19), Pair(1, 46), Pair(0, 20), Pair(-11, 34), Pair(50, 31), Pair(29, 11), Pair(12, -8),
        Pair(24, 7), Pair(33, 4), Pair(4, 23), Pair(1, 23), Pair(-10, 14), Pair(4, 10), Pair(6, 4), Pair(-12, 26),
        Pair(-13, 33), Pair(29, 9), Pair(-4, 17), Pair(11, 6), Pair(-5, 15), Pair(19, 18), Pair(-21, 32), Pair(9, 12),
        Pair(41, 0), Pair(0, 7), Pair(23, 14), Pair(-4, 10), Pair(14, 7), Pair(9, 25), Pair(17, 7), Pair(-22, -6),
        Pair(-8, 0), Pair(30, 32), Pair(-7, 16), Pair(26, 0), Pair(1, 23), Pair(12, 12), Pair(3, -26), Pair(27, -42)
      },
      { // Piece 3
        Pair(-10, 24), Pair(-19, 10), Pair(-20, 24), Pair(1, 6), Pair(-41, 22), Pair(43, -17), Pair(-24, 13), Pair(45, 11),
        Pair(17, 6), Pair(-24, 30), Pair(10, 4), Pair(-22, 26), Pair(-2, 34), Pair(-70, 37), Pair(-37, 19), Pair(38, 4),
        Pair(-14, 11), Pair(34, -2), Pair(-10, 14), Pair(46, -5), Pair(13, 15), Pair(61, -23), Pair(4, 5), Pair(-35, 19),
        Pair(-16, 9), Pair(-10, 7), Pair(-2, 11), Pair(-13, 18), Pair(38, -4), Pair(11, 3), Pair(170, -66), Pair(-24, 6),
        Pair(-4, 12), Pair(5, 8), Pair(-7, 16), Pair(5, 12), Pair(20, -1), Pair(33, -7), Pair(-12, 18), Pair(22, -4),
        Pair(9, 4), Pair(4, 19), Pair(-14, 5), Pair(-8, 21), Pair(16, 3), Pair(44, -34), Pair(0, 21), Pair(14, 3),
        Pair(17, -6), Pair(-7, 18), Pair(-3, 22), Pair(10, -7), Pair(25, -18), Pair(37, -24), Pair(1, 13), Pair(-9, 31),
        Pair(9, 14), Pair(5, 12), Pair(9, 1), Pair(-2, 11), Pair(4, 8), Pair(0, 4), Pair(3, 5), Pair(-4, 15)
      },
      { // Piece 4
        Pair(-58, -4), Pair(41, -30), Pair(34, -20), Pair(28, 10), Pair(48, -14), Pair(-45, 6), Pair(42, 72), Pair(45, 15),
        Pair(26, 0), Pair(3, -20), Pair(2, 14), Pair(8, 16), Pair(-30, 26), Pair(53, 21), Pair(-2, 38), Pair(3, 22),
        Pair(17, 22), Pair(2, -18), Pair(-3, 14), Pair(13, -30), Pair(2, -31), Pair(95, 47), Pair(39, -1), Pair(-6, 19),
        Pair(4, 17), Pair(-8, 33), Pair(-4, -5), Pair(15, 18), Pair(-27, 50), Pair(51, -49), Pair(55, -47), Pair(20, 1),
        Pair(18, -16), Pair(-12, 43), Pair(24, -16), Pair(10, 15), Pair(6, -21), Pair(15, -4), Pair(30, 11), Pair(31, 15),
        Pair(-28, 12), Pair(-1, 37), Pair(-6, 43), Pair(3, 29), Pair(-4, 1), Pair(22, -6), Pair(25, -29), Pair(-5, 15),
        Pair(23, -24), Pair(9, -2), Pair(7, -6), Pair(8, -1), Pair(2, 10), Pair(-12, 9), Pair(1, 25), Pair(-2, -77),
        Pair(5, -15), Pair(-5, 5), Pair(1, 13), Pair(3, 20), Pair(9, -20), Pair(-4, -10), Pair(-78, 92), Pair(54, -63)
      },
      { // Piece 5
        Pair(-40, -30), Pair(-54, -137), Pair(-47, -62), Pair(62, 17), Pair(-61, -129), Pair(-25, -120), Pair(-26, -139), Pair(-39, -54),
        Pair(-47, -38), Pair(48, -24), Pair(-67, -26), Pair(-11, -33), Pair(44, -92), Pair(45, -116), Pair(-32, -10), Pair(13, -29),
        Pair(16, 26), Pair(59, -16), Pair(108, -11), Pair(-122, 15), Pair(-39, -90), Pair(6, 10), Pair(57, -69), Pair(51, -29),
        Pair(-53, -17), Pair(136, -31), Pair(11, -9), Pair(67, -49), Pair(26, -66), Pair(-63, -76), Pair(-17, -70), Pair(63, -16),
        Pair(98, -31), Pair(54, -24), Pair(-28, 1), Pair(5, -24), Pair(57, -22), Pair(24, -36), Pair(18, -38), Pair(-45, -10),
        Pair(48, -25), Pair(89, -32), Pair(64, -26), Pair(11, -13), Pair(-2, -5), Pair(-27, -2), Pair(0, -2), Pair(10, -5),
        Pair(-35, -12), Pair(60, -30), Pair(56, -12), Pair(19, -3), Pair(16, 7), Pair(9, 10), Pair(-8, 13), Pair(5, 2),
        Pair(-32, -17), Pair(-2, -29), Pair(6, 4), Pair(-7, -1), Pair(-5, 8), Pair(-8, 12), Pair(-2, 10), Pair(9, 4)
      }
    }},
    {{ // Bucket 22
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(40, 23), Pair(53, 5), Pair(22, 25), Pair(6, 5), Pair(-48, 25), Pair(-95, -24), Pair(-7, 23), Pair(-6, 2),
        Pair(-1, 19), Pair(7, 15), Pair(8, 20), Pair(6, 18), Pair(3, 15), Pair(-8, 12), Pair(25, -13), Pair(12, 1),
        Pair(-1, 13), Pair(5, 8), Pair(17, 5), Pair(0, 1), Pair(10, -6), Pair(5, 24), Pair(0, -1), Pair(35, 11),
        Pair(-1, 1), Pair(-4, -1), Pair(1, -3), Pair(0, 2), Pair(-4, -1), Pair(4, 4), Pair(4, -4), Pair(5, 5),
        Pair(-3, -2), Pair(-1, 0), Pair(-1, -5), Pair(-2, -2), Pair(2, -3), Pair(-1, 1), Pair(-1, -2), Pair(-1, 4),
        Pair(-1, 0), Pair(1, 0), Pair(-3, -2), Pair(-4, -7), Pair(-1, -9), Pair(1, 2), Pair(0, -3), Pair(-1, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-49, -23), Pair(-27, -6), Pair(-38, 0), Pair(-12, -13), Pair(2, 22), Pair(46, 6), Pair(-39, -4), Pair(-7, 4),
        Pair(17, 0), Pair(25, 8), Pair(30, 13), Pair(-27, 24), Pair(38, -26), Pair(57, -7), Pair(41, -75), Pair(35, -2),
        Pair(-36, -8), Pair(12, -15), Pair(11, 14), Pair(11, 5), Pair(18, 17), Pair(56, 8), Pair(21, -104), Pair(-76, 20),
        Pair(-1, 1), Pair(3, 7), Pair(2, 16), Pair(3, 8), Pair(20, 9), Pair(-14, -20), Pair(6, 50), Pair(17, -21),
        Pair(-12, -2), Pair(3, -3), Pair(9, 8), Pair(-1, 14), Pair(2, 9), Pair(-5, 11), Pair(1, 23), Pair(-21, -6),
        Pair(-3, 17), Pair(2, 3), Pair(1, 6), Pair(6, 11), Pair(-9, 15), Pair(2, 17), Pair(-13, -18), Pair(-1, 8),
        Pair(28, 20), Pair(-22, 20), Pair(3, -4), Pair(0, 5), Pair(-3, 6), Pair(4, 5), Pair(-11, 10), Pair(-16, 56),
        Pair(8, 49), Pair(-6, 23), Pair(-17, 3), Pair(9, -17), Pair(9, 3), Pair(-5, 24), Pair(11, 7), Pair(-14, 5)
      },
      { // Piece 2
        Pair(-96, 50), Pair(-44, 61), Pair(-65, 37), Pair(17, 10), Pair(-93, 34), Pair(-90, 23), Pair(4, 5), Pair(36, 26),
        Pair(-2, 37), Pair(1, 20), Pair(0, 7), Pair(15, 34), Pair(-63, 22), Pair(-70, 10), Pair(-74, 43), Pair(-48, -19),
        Pair(-15, 22), Pair(23, 14), Pair(1, 30), Pair(-5, 34), Pair(-12, 11), Pair(-1, 30), Pair(96, -7), Pair(-8, 26),
        Pair(4, 20), Pair(1, 18), Pair(25, 10), Pair(17, 19), Pair(3, 6), Pair(-38, 31), Pair(2, 57), Pair(-45, 42),
        Pair(-3, 8), Pair(4, 15), Pair(3, 14), Pair(5, 23), Pair(-1, 14), Pair(-8, 4), Pair(-17, 30), Pair(-23, 14),
        Pair(4, 6), Pair(-4, 15), Pair(3, 22), Pair(-8, 5), Pair(0, 20), Pair(3, 15), Pair(3, 8), Pair(-9, 9),
        Pair(-13, -1), Pair(9, 16), Pair(-5, 16), Pair(-5, 20), Pair(-5, 7), Pair(2, 12), Pair(2, 13), Pair(21, 3),
        Pair(12, 7), Pair(-26, 27), Pair(8, 12), Pair(-1, 21), Pair(-17, 22), Pair(3, 9), Pair(-14, 52), Pair(-10, 36)
      },
      { // Piece 3
        Pair(12, 3), Pair(7, 9), Pair(16, 5), Pair(1, 15), Pair(35, -7), Pair(-86, 31), Pair(-7, 14), Pair(2, 21),
        Pair(-2, 14), Pair(23, 12), Pair(-8, 22), Pair(-3, 18), Pair(-17, 33), Pair(-17, 13), Pair(103, -17), Pair(-35, 19),
        Pair(9, -1), Pair(2, -4), Pair(1, 9), Pair(10, -2), Pair(-8, 8), Pair(-5, -3), Pair(-5, 14), Pair(-50, 11),
        Pair(3, -1), Pair(-11, 19), Pair(10, 4), Pair(20, 5), Pair(0, 17), Pair(5, -1), Pair(-20, -7), Pair(19, -5),
        Pair(1, 12), Pair(3, 5), Pair(0, 6), Pair(-8, 21), Pair(-15, 10), Pair(-9, 2), Pair(0, 10), Pair(-26, 21),
        Pair(1, 17), Pair(5, 11), Pair(-10, 13), Pair(8, 4), Pair(3, -10), Pair(-10, 9), Pair(-3, -1), Pair(-20, 3),
        Pair(-21, 12), Pair(6, -12), Pair(7, 7), Pair(2, 1), Pair(12, 0), Pair(-2, -5), Pair(-20, 13), Pair(28, -1),
        Pair(0, 16), Pair(2, 11), Pair(3, 6), Pair(6, 6), Pair(0, 12), Pair(-1, 10), Pair(2, 9), Pair(-4, -6)
      },
      { // Piece 4
        Pair(15, -29), Pair(-18, -24), Pair(-20, 33), Pair(-11, 5), Pair(-36, -8), Pair(19, 31), Pair(-47, -49), Pair(24, 62),
        Pair(24, -18), Pair(-3, -9), Pair(-11, 19), Pair(-20, 7), Pair(-22, 52), Pair(-15, -38), Pair(-40, 13), Pair(8, 70),
        Pair(-8, -18), Pair(1, -10), Pair(-13, 12), Pair(-15, 21), Pair(-29, -17), Pair(-20, 23), Pair(52, -43), Pair(-34, -35),
        Pair(14, -26), Pair(-15, -1), Pair(-14, -3), Pair(7, 13), Pair(-24, 25), Pair(-21, 7), Pair(-28, 17), Pair(54, 31),
        Pair(1, -25), Pair(6, 33), Pair(4, 23), Pair(-3, 36), Pair(8, -6), Pair(-12, 16), Pair(-6, -6), Pair(4, 3),
        Pair(12, -15), Pair(-3, 1), Pair(0, 0), Pair(-2, 5), Pair(-2, -10), Pair(-3, 5), Pair(6, -8), Pair(9, -9),
        Pair(-10, -9), Pair(-6, 20), Pair(-1, -4), Pair(-1, -6), Pair(-8, 13), Pair(-3, -13), Pair(-17, -19), Pair(-12, 18),
        Pair(-12, 0), Pair(0, -15), Pair(0, -19), Pair(3, -5), Pair(-8, -7), Pair(-1, 5), Pair(-43, -6), Pair(6, 8)
      },
      { // Piece 5
        Pair(110, -63), Pair(85, -98), Pair(-5, -29), Pair(23, 15), Pair(2, -115), Pair(-11, -69), Pair(-5, -25), Pair(4, -38),
        Pair(95, -27), Pair(-71, -10), Pair(178, -106), Pair(24, 8), Pair(72, -66), Pair(-24, -39), Pair(1, -56), Pair(61, -61),
        Pair(103, -25), Pair(112, -55), Pair(27, -5), Pair(128, -39), Pair(-12, -32), Pair(-23, -62), Pair(40, -43), Pair(7, -86),
        Pair(-3, -19), Pair(130, -24), Pair(49, -25), Pair(20, -19), Pair(-115, -4), Pair(48, 7), Pair(41, -101), Pair(16, -41),
        Pair(-19, -32), Pair(61, -34), Pair(71, -35), Pair(13, -11), Pair(27, -25), Pair(12, -12), Pair(-21, -47), Pair(-22, -12),
        Pair(5, -22), Pair(75, -27), Pair(50, -37), Pair(19, -18), Pair(-25, -9), Pair(7, 5), Pair(0, -13), Pair(-42, 23),
        Pair(25, -22), Pair(-23, -6), Pair(19, -13), Pair(-18, 5), Pair(1, -2), Pair(0, 18), Pair(-3, 8), Pair(-8, 9),
        Pair(-23, -24), Pair(-19, -18), Pair(-28, 6), Pair(-38, 12), Pair(-12, 3), Pair(-2, 13), Pair(1, 3), Pair(-1, 7)
      }
    }},
    {{ // Bucket 23
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(60, 25), Pair(54, 27), Pair(37, 29), Pair(-23, 28), Pair(-5, 21), Pair(-56, 30), Pair(-35, -12), Pair(-51, -54),
        Pair(19, 17), Pair(14, 13), Pair(9, 13), Pair(17, 4), Pair(-20, 9), Pair(-11, 4), Pair(-26, 1), Pair(-121, 8),
        Pair(1, 9), Pair(7, 7), Pair(4, 11), Pair(8, -7), Pair(-5, 1), Pair(-12, 6), Pair(-1, -12), Pair(-7, -3),
        Pair(-1, -1), Pair(3, 3), Pair(3, -3), Pair(1, -1), Pair(0, 3), Pair(3, 4), Pair(0, -5), Pair(1, 2),
        Pair(-1, 0), Pair(1, -5), Pair(0, -4), Pair(0, -3), Pair(3, -1), Pair(4, -2), Pair(-2, -4), Pair(-1, -1),
        Pair(-1, -2), Pair(1, 0), Pair(-3, -4), Pair(3, 3), Pair(1, -3), Pair(2, 1), Pair(2, -2), Pair(-2, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-78, -52), Pair(-83, -14), Pair(-39, -19), Pair(10, 14), Pair(-10, 11), Pair(57, 37), Pair(-35, -27), Pair(-39, 45),
        Pair(-18, -28), Pair(6, 1), Pair(5, -28), Pair(45, 3), Pair(23, -12), Pair(-26, -10), Pair(16, -49), Pair(-37, -4),
        Pair(36, -45), Pair(-12, -11), Pair(-4, -1), Pair(15, 10), Pair(-6, -1), Pair(49, 18), Pair(16, 6), Pair(45, -2),
        Pair(-11, -24), Pair(1, -4), Pair(3, -3), Pair(18, 1), Pair(8, 2), Pair(12, 8), Pair(13, 11), Pair(26, 34),
        Pair(-4, -15), Pair(1, -4), Pair(5, 4), Pair(4, 7), Pair(3, 2), Pair(18, 3), Pair(7, -18), Pair(-2, 28),
        Pair(-12, -16), Pair(-8, -5), Pair(-2, 1), Pair(2, -5), Pair(10, 3), Pair(-1, -3), Pair(4, 18), Pair(-16, 2),
        Pair(32, -21), Pair(2, 10), Pair(-2, -9), Pair(-1, -4), Pair(-1, 10), Pair(-5, 2), Pair(4, 18), Pair(-6, 18),
        Pair(-65, -33), Pair(-16, 15), Pair(-38, 0), Pair(-11, -6), Pair(-6, 7), Pair(2, 12), Pair(-8, 3), Pair(-65, 68)
      },
      { // Piece 2
        Pair(41, -4), Pair(-31, 47), Pair(71, 22), Pair(-96, 10), Pair(-73, 61), Pair(-32, 72), Pair(13, 41), Pair(-35, 13),
        Pair(-25, 26), Pair(-4, 34), Pair(-16, 12), Pair(-38, 48), Pair(-37, 22), Pair(-7, 43), Pair(1, 12), Pair(30, 14),
        Pair(5, 31), Pair(-13, 26), Pair(-9, 39), Pair(-22, 35), Pair(-17, 64), Pair(7, 15), Pair(14, 31), Pair(-47, -2),
        Pair(-14, 25), Pair(1, 18), Pair(-3, 22), Pair(3, 26), Pair(2, 14), Pair(12, 21), Pair(7, 72), Pair(27, 45),
        Pair(4, 5), Pair(-22, 27), Pair(7, 6), Pair(-10, 7), Pair(6, 13), Pair(1, 17), Pair(-17, 7), Pair(-9, 48),
        Pair(-3, 4), Pair(5, 21), Pair(7, 13), Pair(1, 9), Pair(1, 0), Pair(1, 20), Pair(-1, 24), Pair(-2, 46),
        Pair(3, 17), Pair(4, 13), Pair(5, 13), Pair(-3, 1), Pair(2, 9), Pair(4, 7), Pair(12, 9), Pair(5, 25),
        Pair(8, 5), Pair(13, 0), Pair(-4, 5), Pair(-5, 4), Pair(-9, 4), Pair(9, 13), Pair(-24, 23), Pair(23, 8)
      },
      { // Piece 3
        Pair(-1, 19), Pair(-26, 23), Pair(-7, 30), Pair(-6, 13), Pair(-3, 12), Pair(-4, 23), Pair(27, 25), Pair(-12, 55),
        Pair(5, 19), Pair(12, 20), Pair(-13, 31), Pair(24, 15), Pair(16, 9), Pair(-1, 29), Pair(88, -9), Pair(45, 29),
        Pair(0, 16), Pair(2, 22), Pair(1, 21), Pair(8, 17), Pair(20, -7), Pair(22, 2), Pair(21, 15), Pair(-2, 68),
        Pair(9, 8), Pair(16, 5), Pair(7, 21), Pair(3, 11), Pair(-7, 23), Pair(6, 15), Pair(21, 4), Pair(-12, 16),
        Pair(7, 8), Pair(23, 7), Pair(16, 11), Pair(-1, 10), Pair(23, 2), Pair(-3, 13), Pair(13, 11), Pair(-27, 16),
        Pair(6, -16), Pair(14, 21), Pair(2, 8), Pair(2, 9), Pair(8, 11), Pair(2, 17), Pair(12, -12), Pair(12, -11),
        Pair(16, 8), Pair(8, 6), Pair(-3, 22), Pair(-4, 18), Pair(-5, 10), Pair(-14, 23), Pair(3, -14), Pair(-26, 12),
        Pair(1, 15), Pair(1, 16), Pair(0, 11), Pair(3, 18), Pair(4, 12), Pair(6, 11), Pair(-8, 11), Pair(-5, 11)
      },
      { // Piece 4
        Pair(-9, 15), Pair(-13, 47), Pair(-16, 67), Pair(6, 18), Pair(6, 37), Pair(-4, 0), Pair(69, -12), Pair(-28, 30),
        Pair(5, -5), Pair(0, 0), Pair(6, 3), Pair(-2, 21), Pair(-2, 33), Pair(-52, 107), Pair(-15, 16), Pair(-21, 56),
        Pair(18, 4), Pair(2, 2), Pair(-6, 5), Pair(-25, 28), Pair(16, 54), Pair(-7, 20), Pair(-68, 102), Pair(18, -12),
        Pair(2, -2), Pair(-1, 28), Pair(5, 6), Pair(-13, 41), Pair(-10, 27), Pair(-16, 58), Pair(-33, 15), Pair(-6, 20),
        Pair(10, -10), Pair(-3, 14), Pair(-15, 14), Pair(1, 7), Pair(5, 34), Pair(12, 10), Pair(-6, 15), Pair(8, 3),
        Pair(1, -24), Pair(2, -14), Pair(-3, 7), Pair(3, 9), Pair(7, 12), Pair(-3, 2), Pair(11, -8), Pair(-4, -26),
        Pair(-3, -8), Pair(-4, 3), Pair(-3, -2), Pair(-2, 11), Pair(-2, 5), Pair(8, 13), Pair(25, -32), Pair(-42, 33),
        Pair(-9, 10), Pair(-17, 29), Pair(-5, 7), Pair(2, 10), Pair(-2, -4), Pair(-5, 8), Pair(5, 21), Pair(-12, -9)
      },
      { // Piece 5
        Pair(-61, -70), Pair(24, -42), Pair(-33, 32), Pair(52, -2), Pair(52, -31), Pair(-133, -77), Pair(66, 30), Pair(26, 10),
        Pair(-14, -111), Pair(93, -70), Pair(167, -52), Pair(-64, -5), Pair(-69, 0), Pair(7, -23), Pair(-66, -70), Pair(6, -17),
        Pair(-42, -37), Pair(61, -47), Pair(-23, -56), Pair(118, -47), Pair(26, -38), Pair(39, -36), Pair(-19, -73), Pair(12, -35),
        Pair(86, -25), Pair(116, -52), Pair(88, -47), Pair(-13, -35), Pair(50, -17), Pair(-48, -14), Pair(63, -42), Pair(124, -98),
        Pair(-14, -60), Pair(11, -18), Pair(76, -28), Pair(47, -28), Pair(13, -18), Pair(-23, -24), Pair(42, -20), Pair(14, -44),
        Pair(66, -39), Pair(11, -5), Pair(10, -35), Pair(57, -28), Pair(36, -17), Pair(-9, -8), Pair(7, 1), Pair(13, -17),
        Pair(-17, 1), Pair(-15, -11), Pair(16, -39), Pair(-5, -21), Pair(-5, -5), Pair(16, -6), Pair(0, 15), Pair(-3, 7),
        Pair(16, -31), Pair(-12, -19), Pair(0, -23), Pair(2, -11), Pair(3, 2), Pair(-14, 10), Pair(3, 12), Pair(-1, 1)
      }
    }},
    {{ // Bucket 24
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-6, -136), Pair(52, 21), Pair(5, 42), Pair(8, 11), Pair(-5, 28), Pair(107, -5), Pair(42, -23), Pair(-13, 19),
        Pair(40, -14), Pair(8, 22), Pair(-25, 27), Pair(8, 13), Pair(9, 21), Pair(31, 9), Pair(-6, 23), Pair(-9, 17),
        Pair(15, 47), Pair(1, -5), Pair(-9, 0), Pair(4, 1), Pair(4, -1), Pair(2, 5), Pair(3, 8), Pair(-10, 3),
        Pair(-2, 1), Pair(-2, -16), Pair(2, -6), Pair(1, -6), Pair(-1, 0), Pair(-3, 0), Pair(-1, -1), Pair(-2, -3),
        Pair(10, 17), Pair(-3, -2), Pair(2, -3), Pair(5, -5), Pair(-2, -2), Pair(-4, -2), Pair(2, -2), Pair(-8, -1),
        Pair(7, 1), Pair(-4, -5), Pair(4, -4), Pair(-1, -16), Pair(-2, -4), Pair(-3, -5), Pair(-1, -2), Pair(-6, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-102, -12), Pair(40, -41), Pair(21, -17), Pair(-13, -24), Pair(-44, 25), Pair(34, -16), Pair(-85, -3), Pair(-1, -24),
        Pair(43, -28), Pair(-20, 23), Pair(43, -33), Pair(18, -6), Pair(2, 23), Pair(42, -23), Pair(18, -42), Pair(26, -4),
        Pair(41, 7), Pair(16, 9), Pair(4, 12), Pair(16, -4), Pair(-9, 24), Pair(50, -15), Pair(50, -40), Pair(63, -31),
        Pair(-31, 23), Pair(4, 11), Pair(1, 12), Pair(11, 6), Pair(7, 0), Pair(16, 2), Pair(18, 3), Pair(31, -8),
        Pair(10, 34), Pair(22, 16), Pair(12, 10), Pair(6, -9), Pair(14, 17), Pair(11, 2), Pair(25, -10), Pair(15, 4),
        Pair(5, 22), Pair(9, 19), Pair(1, 9), Pair(1, -5), Pair(8, -6), Pair(3, 1), Pair(5, 0), Pair(3, -6),
        Pair(0, -16), Pair(18, -15), Pair(10, 5), Pair(1, 5), Pair(-2, 4), Pair(12, -16), Pair(5, -3), Pair(-1, 11),
        Pair(-167, 77), Pair(-5, 10), Pair(9, 1), Pair(14, -24), Pair(-2, -2), Pair(7, 4), Pair(0, -1), Pair(-2, -125)
      },
      { // Piece 2
        Pair(7, -20), Pair(39, -11), Pair(-73, 29), Pair(-31, 29), Pair(56, 33), Pair(-13, 57), Pair(33, 14), Pair(-12, 22),
        Pair(-1, 41), Pair(-28, 23), Pair(-22, 49), Pair(-32, 48), Pair(-54, 57), Pair(-8, 27), Pair(17, 52), Pair(-1, 32),
        Pair(7, 31), Pair(-33, 45), Pair(-12, 39), Pair(-4, 41), Pair(-34, 45), Pair(5, 52), Pair(-21, 45), Pair(11, 36),
        Pair(-36, 15), Pair(1, 21), Pair(-21, 42), Pair(-2, 19), Pair(3, 35), Pair(2, 16), Pair(5, 22), Pair(10, 10),
        Pair(-6, 62), Pair(-9, 15), Pair(12, 16), Pair(2, 30), Pair(19, 0), Pair(0, 27), Pair(-13, 10), Pair(-2, 9),
        Pair(4, 88), Pair(-24, 32), Pair(-2, 28), Pair(-5, 17), Pair(3, 10), Pair(0, 7), Pair(-5, 24), Pair(-1, -3),
        Pair(-5, 70), Pair(3, 27), Pair(-10, 25), Pair(-2, 19), Pair(-11, 12), Pair(-16, 7), Pair(-1, 4), Pair(9, -1),
        Pair(-5, 46), Pair(-5, 54), Pair(-3, 28), Pair(-16, 16), Pair(-6, 22), Pair(-12, 19), Pair(-12, 24), Pair(24, -27)
      },
      { // Piece 3
        Pair(75, 21), Pair(35, 22), Pair(17, 27), Pair(-43, 60), Pair(39, 14), Pair(-14, 55), Pair(80, 17), Pair(44, 7),
        Pair(-15, 55), Pair(-9, 40), Pair(20, 26), Pair(18, 24), Pair(-12, 53), Pair(59, 32), Pair(48, 11), Pair(-4, 41),
        Pair(33, 21), Pair(1, 35), Pair(15, 32), Pair(9, 51), Pair(23, 24), Pair(27, 40), Pair(-34, 40), Pair(-6, 41),
        Pair(34, 46), Pair(9, 34), Pair(23, 27), Pair(14, 33), Pair(15, 25), Pair(0, 22), Pair(18, 29), Pair(6, 11),
        Pair(4, 11), Pair(0, 38), Pair(-10, 32), Pair(-10, 19), Pair(-1, 27), Pair(-10, 17), Pair(22, 15), Pair(22, 19),
        Pair(-32, 25), Pair(-19, 49), Pair(-19, 28), Pair(1, 13), Pair(-15, 40), Pair(-4, 24), Pair(43, -9), Pair(-30, 35),
        Pair(-2, -4), Pair(-10, 27), Pair(-5, 13), Pair(-2, 15), Pair(1, 11), Pair(18, 4), Pair(-4, 18), Pair(14, 41),
        Pair(-2, 3), Pair(-6, 17), Pair(-6, 22), Pair(-1, 14), Pair(-1, 17), Pair(2, 16), Pair(18, 12), Pair(8, 25)
      },
      { // Piece 4
        Pair(80, 27), Pair(60, 8), Pair(19, 32), Pair(46, 54), Pair(39, 53), Pair(43, 56), Pair(67, 1), Pair(56, 30),
        Pair(-10, 80), Pair(16, 50), Pair(-12, 69), Pair(-43, 107), Pair(7, 79), Pair(20, 100), Pair(7, 78), Pair(76, -5),
        Pair(5, 45), Pair(5, 64), Pair(10, 48), Pair(14, 43), Pair(-8, 82), Pair(47, 49), Pair(85, -5), Pair(34, 35),
        Pair(48, 35), Pair(-12, 46), Pair(30, 18), Pair(17, 45), Pair(-8, 82), Pair(1, 64), Pair(38, 41), Pair(39, 26),
        Pair(2, 29), Pair(-15, 103), Pair(13, 15), Pair(10, 63), Pair(12, 33), Pair(18, 30), Pair(38, 9), Pair(15, 39),
        Pair(-12, 81), Pair(1, 11), Pair(-1, 18), Pair(5, 22), Pair(4, 21), Pair(10, 34), Pair(13, 8), Pair(28, 56),
        Pair(-6, 31), Pair(1, 36), Pair(5, 21), Pair(-2, 38), Pair(7, 11), Pair(-2, 29), Pair(-3, 29), Pair(-15, 28),
        Pair(-2, 5), Pair(-4, 14), Pair(-3, 24), Pair(1, 8), Pair(-15, 48), Pair(-7, 16), Pair(26, -18), Pair(7, 33)
      },
      { // Piece 5
        Pair(-34, 72), Pair(45, 1), Pair(28, -6), Pair(12, -32), Pair(-10, -23), Pair(-10, -41), Pair(-75, -57), Pair(30, -10),
        Pair(40, -29), Pair(-16, -63), Pair(116, -38), Pair(102, -79), Pair(-15, 16), Pair(114, -11), Pair(-81, 27), Pair(-4, -11),
        Pair(-40, -42), Pair(-1, -26), Pair(49, -28), Pair(22, -43), Pair(14, -13), Pair(62, -27), Pair(35, -11), Pair(-43, -13),
        Pair(90, -25), Pair(61, -39), Pair(18, 6), Pair(47, -20), Pair(65, -1), Pair(37, -14), Pair(63, -13), Pair(24, -17),
        Pair(49, -110), Pair(-59, -30), Pair(19, -4), Pair(24, -13), Pair(43, -5), Pair(-1, -3), Pair(35, -10), Pair(69, -29),
        Pair(-3, -30), Pair(5, 3), Pair(14, -9), Pair(37, -4), Pair(24, -12), Pair(21, -7), Pair(-3, -5), Pair(9, -6),
        Pair(18, -8), Pair(0, 28), Pair(-17, 14), Pair(-6, 8), Pair(8, -8), Pair(8, -7), Pair(8, -7), Pair(11, -11),
        Pair(32, 6), Pair(17, 24), Pair(1, 23), Pair(-15, 26), Pair(1, -14), Pair(-1, -12), Pair(-2, -8), Pair(8, -2)
      }
    }},
    {{ // Bucket 25
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-70, 51), Pair(10, 23), Pair(17, 0), Pair(51, 18), Pair(29, 9), Pair(46, 18), Pair(36, 40), Pair(25, -35),
        Pair(-20, 12), Pair(16, -11), Pair(12, 9), Pair(8, 33), Pair(-17, 24), Pair(26, 17), Pair(11, 10), Pair(-4, 31),
        Pair(-10, 4), Pair(3, -2), Pair(-2, -7), Pair(3, 3), Pair(6, 5), Pair(8, 8), Pair(2, 4), Pair(-12, 14),
        Pair(2, 7), Pair(0, 4), Pair(-8, 10), Pair(1, 3), Pair(-7, 3), Pair(-2, 5), Pair(-3, 2), Pair(-7, 7),
        Pair(5, 1), Pair(8, 11), Pair(-3, 6), Pair(3, 0), Pair(-3, 2), Pair(-5, -1), Pair(-5, 0), Pair(-1, 4),
        Pair(5, 2), Pair(11, 8), Pair(-6, 8), Pair(2, 4), Pair(0, -4), Pair(0, 0), Pair(-7, 1), Pair(-2, 7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-93, -73), Pair(33, -56), Pair(12, -28), Pair(-77, 38), Pair(-24, -8), Pair(88, -77), Pair(-81, -54), Pair(-129, 97),
        Pair(-7, 4), Pair(-41, 25), Pair(53, 20), Pair(78, -11), Pair(61, -27), Pair(21, 17), Pair(8, -20), Pair(84, -62),
        Pair(13, 18), Pair(-4, 15), Pair(12, 26), Pair(16, 32), Pair(45, 29), Pair(16, 23), Pair(89, 4), Pair(50, 3),
        Pair(-21, 39), Pair(6, 24), Pair(-6, 37), Pair(2, 33), Pair(10, 28), Pair(27, 18), Pair(24, 23), Pair(28, 22),
        Pair(1, -6), Pair(14, 55), Pair(13, 48), Pair(5, 27), Pair(6, 24), Pair(18, 9), Pair(20, 6), Pair(10, 34),
        Pair(-6, -28), Pair(5, 54), Pair(4, 21), Pair(4, 23), Pair(-7, 24), Pair(7, 15), Pair(1, 2), Pair(7, 1),
        Pair(8, 41), Pair(-1, -4), Pair(-3, 11), Pair(0, 21), Pair(0, 15), Pair(16, 13), Pair(-2, 22), Pair(10, 55),
        Pair(-78, 1), Pair(-11, -32), Pair(32, -16), Pair(-12, 5), Pair(-1, 14), Pair(-7, 18), Pair(-6, 38), Pair(-11, 38)
      },
      { // Piece 2
        Pair(-36, 45), Pair(-13, 42), Pair(-48, 11), Pair(-101, 67), Pair(15, 60), Pair(-55, 48), Pair(38, 20), Pair(66, 20),
        Pair(9, -2), Pair(7, 62), Pair(-9, 18), Pair(-58, 65), Pair(-50, 46), Pair(26, 83), Pair(-24, 58), Pair(4, 17),
        Pair(0, 21), Pair(27, 10), Pair(11, 37), Pair(-22, 53), Pair(48, 40), Pair(9, 49), Pair(15, 41), Pair(26, 56),
        Pair(22, 30), Pair(5, 18), Pair(1, 16), Pair(9, 45), Pair(-13, 45), Pair(0, 57), Pair(19, 23), Pair(4, 30),
        Pair(-4, 82), Pair(10, 55), Pair(15, 34), Pair(15, 23), Pair(13, 40), Pair(5, 13), Pair(6, 37), Pair(31, 9),
        Pair(-26, 25), Pair(1, 70), Pair(-8, 28), Pair(15, 25), Pair(10, 19), Pair(3, 31), Pair(7, 4), Pair(5, 22),
        Pair(6, 43), Pair(5, 15), Pair(9, 31), Pair(3, 6), Pair(0, 23), Pair(-5, 39), Pair(6, 31), Pair(4, -1),
        Pair(13, 34), Pair(11, 44), Pair(6, -2), Pair(22, 22), Pair(-8, 40), Pair(8, 14), Pair(20, -9), Pair(-5, 83)
      },
      { // Piece 3
        Pair(10, 33), Pair(107, 5), Pair(-14, 51), Pair(28, 31), Pair(16, 35), Pair(18, 26), Pair(37, 38), Pair(32, 23),
        Pair(-1, 49), Pair(37, 59), Pair(8, 43), Pair(-4, 50), Pair(-20, 74), Pair(18, 44), Pair(37, 43), Pair(-21, 37),
        Pair(-10, 49), Pair(-21, 64), Pair(10, 55), Pair(0, 47), Pair(56, 19), Pair(69, 15), Pair(48, 31), Pair(63, 20),
        Pair(19, 23), Pair(20, 53), Pair(17, 18), Pair(-2, 65), Pair(6, 40), Pair(-18, 57), Pair(73, 8), Pair(65, -5),
        Pair(29, -25), Pair(0, 30), Pair(14, 47), Pair(1, 34), Pair(-2, 45), Pair(-2, 30), Pair(45, 23), Pair(39, 4),
        Pair(27, 18), Pair(-3, 34), Pair(-2, 38), Pair(10, 17), Pair(-15, 27), Pair(17, 29), Pair(15, 38), Pair(-1, 67),
        Pair(17, -7), Pair(-22, 21), Pair(12, 4), Pair(-10, 16), Pair(12, 26), Pair(-4, 38), Pair(-11, 51), Pair(-26, 46),
        Pair(-7, 34), Pair(-3, 15), Pair(-7, 26), Pair(-1, 33), Pair(5, 27), Pair(4, 29), Pair(-6, 48), Pair(9, 34)
      },
      { // Piece 4
        Pair(67, -11), Pair(-42, 75), Pair(21, 32), Pair(-12, 35), Pair(-26, 104), Pair(117, 11), Pair(63, 32), Pair(-43, 104),
        Pair(21, 2), Pair(-17, 65), Pair(24, -6), Pair(25, 47), Pair(7, 65), Pair(-2, 81), Pair(60, 65), Pair(37, -5),
        Pair(13, -1), Pair(-17, 119), Pair(-6, 52), Pair(3, 62), Pair(0, 121), Pair(37, 9), Pair(65, 20), Pair(21, 45),
        Pair(20, -15), Pair(31, 49), Pair(3, 41), Pair(45, 21), Pair(30, 44), Pair(-15, 67), Pair(17, 59), Pair(39, 10),
        Pair(-4, 53), Pair(24, 22), Pair(-13, 93), Pair(13, 46), Pair(25, 38), Pair(9, 46), Pair(12, 32), Pair(11, 45),
        Pair(5, -11), Pair(7, 35), Pair(11, 8), Pair(1, 40), Pair(18, 22), Pair(15, 51), Pair(39, 4), Pair(23, 30),
        Pair(-1, 29), Pair(-9, 61), Pair(4, 29), Pair(12, 16), Pair(15, 24), Pair(10, 28), Pair(26, -11), Pair(34, 13),
        Pair(-7, 4), Pair(13, 10), Pair(-3, 18), Pair(8, 30), Pair(3, 31), Pair(-8, 62), Pair(-4, -34), Pair(-69, 23)
      },
      { // Piece 5
        Pair(-2, -74), Pair(11, -87), Pair(28, -97), Pair(-6, 93), Pair(32, -10), Pair(-36, -77), Pair(12, -127), Pair(-18, -162),
        Pair(4, -25), Pair(-54, -70), Pair(-23, -82), Pair(99, -39), Pair(42, 9), Pair(-43, 6), Pair(17, -49), Pair(11, 4),
        Pair(4, -83), Pair(43, -64), Pair(92, -28), Pair(111, -15), Pair(154, -33), Pair(43, -14), Pair(38, -4), Pair(-31, -19),
        Pair(47, -90), Pair(39, -55), Pair(43, -35), Pair(33, -16), Pair(33, -12), Pair(-51, 0), Pair(89, -27), Pair(73, -24),
        Pair(30, -41), Pair(-13, -90), Pair(40, -35), Pair(-26, -15), Pair(12, -12), Pair(61, -14), Pair(18, -9), Pair(35, -32),
        Pair(-65, -17), Pair(29, -70), Pair(14, -16), Pair(10, -22), Pair(-21, 11), Pair(13, -10), Pair(16, -16), Pair(35, -21),
        Pair(-26, 16), Pair(-26, 10), Pair(29, 4), Pair(21, -13), Pair(-13, -2), Pair(12, -4), Pair(13, -13), Pair(1, -6),
        Pair(-71, 59), Pair(-14, 10), Pair(-14, 16), Pair(2, 0), Pair(-13, -3), Pair(23, -18), Pair(2, -13), Pair(13, -23)
      }
    }},
    {{ // Bucket 26
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-68, 48), Pair(-84, 58), Pair(139, 13), Pair(15, 24), Pair(52, 29), Pair(37, 12), Pair(102, 7), Pair(73, -2),
        Pair(-10, 15), Pair(-4, 28), Pair(24, 15), Pair(8, -16), Pair(17, 6), Pair(22, 15), Pair(24, 3), Pair(-10, 34),
        Pair(1, 1), Pair(6, -4), Pair(7, -3), Pair(6, -6), Pair(-2, 3), Pair(7, 4), Pair(6, 1), Pair(-3, 9),
        Pair(0, 2), Pair(0, -19), Pair(-1, 1), Pair(-5, 10), Pair(-2, 1), Pair(-1, 4), Pair(-1, 1), Pair(-2, 4),
        Pair(1, -1), Pair(1, -8), Pair(8, 11), Pair(-2, 2), Pair(-2, 1), Pair(-7, -6), Pair(-2, 0), Pair(-1, 2),
        Pair(2, 1), Pair(-1, -7), Pair(9, 2), Pair(-7, -4), Pair(3, 0), Pair(-5, -2), Pair(-3, -3), Pair(2, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(71, -8), Pair(20, -59), Pair(-51, 31), Pair(58, -37), Pair(35, -33), Pair(-78, 13), Pair(-61, 107), Pair(19, -58),
        Pair(-34, 8), Pair(-32, 19), Pair(-2, 13), Pair(22, 28), Pair(35, 34), Pair(16, -3), Pair(-20, 38), Pair(71, -22),
        Pair(6, 47), Pair(-25, 42), Pair(-12, 3), Pair(5, 27), Pair(-8, 33), Pair(40, 16), Pair(28, 16), Pair(19, 7),
        Pair(8, 24), Pair(1, 10), Pair(-8, 2), Pair(4, 22), Pair(-3, 39), Pair(2, 27), Pair(9, 19), Pair(1, 38),
        Pair(2, 54), Pair(-12, 32), Pair(14, 58), Pair(-10, 39), Pair(11, 29), Pair(7, 15), Pair(27, 19), Pair(16, 33),
        Pair(-1, 17), Pair(3, 11), Pair(4, 42), Pair(2, 22), Pair(-4, 20), Pair(-2, 15), Pair(4, 13), Pair(5, 16),
        Pair(-15, 0), Pair(-2, 18), Pair(-10, 10), Pair(-3, 22), Pair(1, 19), Pair(-1, 23), Pair(1, 15), Pair(14, 34),
        Pair(-72, 28), Pair(3, 16), Pair(-29, 5), Pair(9, 18), Pair(-1, 4), Pair(17, 19), Pair(3, 56), Pair(61, -5)
      },
      { // Piece 2
        Pair(38, 23), Pair(-41, 32), Pair(-97, 17), Pair(-93, 54), Pair(-41, 23), Pair(48, 18), Pair(-69, 38), Pair(52, 41),
        Pair(17, 46), Pair(-1, 2), Pair(17, 27), Pair(-31, 31), Pair(27, 47), Pair(28, -13), Pair(-4, 59), Pair(-56, 48),
        Pair(-2, 4), Pair(-10, 27), Pair(-21, 41), Pair(-26, 40), Pair(-4, 42), Pair(-14, 58), Pair(34, 20), Pair(11, 20),
        Pair(-5, 17), Pair(-2, 16), Pair(-8, 22), Pair(7, 25), Pair(8, 18), Pair(-12, 30), Pair(-5, 19), Pair(-2, 20),
        Pair(-10, 23), Pair(-5, 45), Pair(17, 57), Pair(-36, 50), Pair(6, -2), Pair(3, 27), Pair(4, 19), Pair(-12, 36),
        Pair(0, -23), Pair(-8, 3), Pair(-4, 52), Pair(1, 8), Pair(-7, 12), Pair(0, 9), Pair(12, 9), Pair(2, 18),
        Pair(-40, -3), Pair(-1, 6), Pair(-1, 18), Pair(3, 12), Pair(-2, 1), Pair(-19, 29), Pair(3, 6), Pair(7, 14),
        Pair(-12, 19), Pair(0, -1), Pair(0, 1), Pair(-3, 37), Pair(-3, 26), Pair(8, -7), Pair(11, -23), Pair(-23, 28)
      },
      { // Piece 3
        Pair(39, 6), Pair(2, 22), Pair(125, -2), Pair(-26, 42), Pair(11, 15), Pair(74, 28), Pair(37, 20), Pair(-5, 22),
        Pair(11, 27), Pair(12, 26), Pair(12, 16), Pair(29, 17), Pair(10, 20), Pair(58, 12), Pair(27, 38), Pair(9, 17),
        Pair(-4, 22), Pair(5, 16), Pair(13, 32), Pair(14, 14), Pair(4, 26), Pair(47, 5), Pair(33, 11), Pair(5, 11),
        Pair(-11, 15), Pair(2, 11), Pair(-21, 78), Pair(25, 15), Pair(7, 20), Pair(-15, 20), Pair(-13, 25), Pair(7, 20),
        Pair(-2, -3), Pair(24, -7), Pair(-21, 17), Pair(7, -4), Pair(8, 15), Pair(4, 14), Pair(-1, 7), Pair(8, 4),
        Pair(-23, 26), Pair(-2, -6), Pair(-8, -3), Pair(-12, -1), Pair(11, -5), Pair(-15, 12), Pair(-20, 31), Pair(-9, 12),
        Pair(4, -1), Pair(-6, -1), Pair(-20, 12), Pair(8, -3), Pair(9, -2), Pair(7, 19), Pair(7, 24), Pair(36, -10),
        Pair(-3, 13), Pair(0, 2), Pair(-5, -10), Pair(-4, 4), Pair(-2, 11), Pair(1, 13), Pair(8, 18), Pair(9, 22)
      },
      { // Piece 4
        Pair(-12, 62), Pair(-4, 49), Pair(-38, 57), Pair(19, 63), Pair(53, 10), Pair(-35, 55), Pair(10, 25), Pair(57, -9),
        Pair(10, 47), Pair(-16, 42), Pair(-21, 83), Pair(14, 29), Pair(-55, 107), Pair(18, -3), Pair(40, 90), Pair(9, 25),
        Pair(3, 37), Pair(7, 0), Pair(25, 32), Pair(4, 15), Pair(8, 10), Pair(-13, 66), Pair(31, 23), Pair(24, 61),
        Pair(-22, 55), Pair(-10, 29), Pair(16, -19), Pair(18, 23), Pair(-6, 44), Pair(46, 26), Pair(7, -8), Pair(16, 48),
        Pair(-6, 50), Pair(-19, 9), Pair(22, -1), Pair(-8, 53), Pair(-4, 41), Pair(11, 21), Pair(15, 22), Pair(24, 32),
        Pair(-6, -8), Pair(-5, 16), Pair(5, 7), Pair(10, 20), Pair(3, 22), Pair(3, 16), Pair(14, 19), Pair(-4, 13),
        Pair(2, 44), Pair(0, 17), Pair(4, 18), Pair(2, 12), Pair(2, 7), Pair(5, 39), Pair(11, 8), Pair(-24, 112),
        Pair(11, 8), Pair(12, 9), Pair(3, 0), Pair(2, 12), Pair(-4, 58), Pair(6, 15), Pair(15, 41), Pair(-5, -10)
      },
      { // Piece 5
        Pair(1, -96), Pair(25, -25), Pair(18, 11), Pair(21, 1), Pair(-36, 33), Pair(-74, -63), Pair(44, -91), Pair(22, -35),
        Pair(-8, -39), Pair(14, -57), Pair(-236, -32), Pair(10, -88), Pair(72, -15), Pair(-70, 20), Pair(49, -2), Pair(-12, 24),
        Pair(-73, -35), Pair(-56, 8), Pair(8, -21), Pair(17, -41), Pair(13, -27), Pair(28, -11), Pair(-39, -13), Pair(-4, -47),
        Pair(-77, -18), Pair(33, -39), Pair(108, -38), Pair(-77, -36), Pair(-10, 3), Pair(20, -10), Pair(-30, 3), Pair(-20, -7),
        Pair(56, -52), Pair(-75, -20), Pair(-96, -50), Pair(106, -53), Pair(4, -12), Pair(29, -6), Pair(27, 3), Pair(-11, 10),
        Pair(-28, 2), Pair(-2, 5), Pair(-2, -35), Pair(29, -22), Pair(-7, -5), Pair(-6, 12), Pair(-2, 7), Pair(22, -1),
        Pair(-42, 20), Pair(-19, 18), Pair(1, -2), Pair(14, 1), Pair(-2, 6), Pair(7, 3), Pair(2, 0), Pair(-1, 9),
        Pair(-30, 25), Pair(-5, 7), Pair(-5, 14), Pair(-10, 26), Pair(-1, 18), Pair(10, 1), Pair(3, 3), Pair(2, -6)
      }
    }},
    {{ // Bucket 27
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-60, 51), Pair(13, 0), Pair(-66, 58), Pair(4, 10), Pair(2, 1), Pair(14, -13), Pair(12, 12), Pair(-20, -1),
        Pair(-9, 18), Pair(4, 3), Pair(24, -10), Pair(-11, -1), Pair(20, 7), Pair(46, -7), Pair(27, -2), Pair(-4, 3),
        Pair(-3, -1), Pair(-5, 4), Pair(-6, 6), Pair(-2, -4), Pair(5, 0), Pair(11, 0), Pair(0, 3), Pair(1, 6),
        Pair(5, -3), Pair(0, -1), Pair(1, -5), Pair(-1, 2), Pair(-7, -3), Pair(-1, 3), Pair(1, -2), Pair(0, 3),
        Pair(0, -1), Pair(0, -3), Pair(-1, -6), Pair(9, 13), Pair(-2, -2), Pair(-2, -4), Pair(1, -3), Pair(-1, 3),
        Pair(1, 6), Pair(-1, 1), Pair(-1, -8), Pair(5, -2), Pair(-5, -5), Pair(-1, 2), Pair(1, -3), Pair(1, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-74, 58), Pair(-42, -1), Pair(10, 2), Pair(-46, 21), Pair(-34, -2), Pair(25, 45), Pair(-60, 13), Pair(67, -61),
        Pair(-7, 25), Pair(22, 23), Pair(13, 16), Pair(15, 1), Pair(-1, 30), Pair(-3, 15), Pair(-43, 11), Pair(-15, 23),
        Pair(50, 20), Pair(-6, 19), Pair(-1, 23), Pair(-3, 27), Pair(-14, 13), Pair(9, 25), Pair(-19, 33), Pair(22, -3),
        Pair(-19, 2), Pair(-8, 21), Pair(-13, 31), Pair(-10, 17), Pair(-1, 40), Pair(9, 35), Pair(0, 36), Pair(5, 9),
        Pair(-8, -1), Pair(5, 31), Pair(2, 43), Pair(20, 59), Pair(-6, 61), Pair(1, 36), Pair(4, 22), Pair(7, 15),
        Pair(-13, 13), Pair(-1, 5), Pair(2, 1), Pair(14, 36), Pair(-5, 23), Pair(7, 12), Pair(2, 6), Pair(9, 46),
        Pair(-23, 2), Pair(-21, 15), Pair(1, 12), Pair(-5, 6), Pair(1, 19), Pair(2, 6), Pair(-17, 38), Pair(15, 12),
        Pair(-11, 26), Pair(0, -16), Pair(-9, 45), Pair(-21, -3), Pair(8, 12), Pair(7, -6), Pair(4, 39), Pair(2, 12)
      },
      { // Piece 2
        Pair(-28, -5), Pair(-61, 42), Pair(-71, 45), Pair(58, 21), Pair(-41, 34), Pair(-5, -2), Pair(-22, 44), Pair(3, 33),
        Pair(-46, 14), Pair(-19, 20), Pair(7, 10), Pair(-28, 40), Pair(-13, 30), Pair(-7, 33), Pair(0, 55), Pair(38, 21),
        Pair(3, 35), Pair(-40, 30), Pair(-8, 15), Pair(-22, 34), Pair(58, 6), Pair(13, 25), Pair(9, 40), Pair(6, 5),
        Pair(-1, 27), Pair(3, 27), Pair(-24, 18), Pair(-20, 27), Pair(-5, 28), Pair(10, 35), Pair(-9, 27), Pair(1, 31),
        Pair(-14, 34), Pair(-5, 13), Pair(26, 17), Pair(8, 57), Pair(5, 38), Pair(-7, 24), Pair(11, 14), Pair(4, -4),
        Pair(-12, 12), Pair(1, 4), Pair(-8, -10), Pair(-3, 40), Pair(-10, 3), Pair(6, 1), Pair(-3, -8), Pair(3, 10),
        Pair(-6, 14), Pair(-15, -15), Pair(6, 14), Pair(-2, 5), Pair(0, 9), Pair(-5, 10), Pair(0, 0), Pair(7, -23),
        Pair(-29, -19), Pair(16, 26), Pair(-2, 14), Pair(10, 5), Pair(0, 6), Pair(4, 12), Pair(-16, 12), Pair(-7, 47)
      },
      { // Piece 3
        Pair(-26, 21), Pair(0, 22), Pair(-23, 8), Pair(30, 15), Pair(-22, 41), Pair(15, 13), Pair(50, 30), Pair(-14, 27),
        Pair(13, 18), Pair(1, 26), Pair(-12, 28), Pair(-13, 21), Pair(-29, 29), Pair(15, 18), Pair(19, 3), Pair(-41, 39),
        Pair(-9, 20), Pair(-13, 22), Pair(7, 10), Pair(-11, 26), Pair(21, 4), Pair(38, -13), Pair(47, -8), Pair(-9, 40),
        Pair(-2, 17), Pair(18, 6), Pair(3, 13), Pair(-22, 26), Pair(11, 7), Pair(11, 2), Pair(14, 6), Pair(4, 18),
        Pair(-9, 5), Pair(1, -5), Pair(0, -1), Pair(-1, -3), Pair(-2, 12), Pair(-3, 6), Pair(-21, 4), Pair(-6, 10),
        Pair(-6, 9), Pair(9, 2), Pair(7, -5), Pair(-20, -2), Pair(-13, 33), Pair(-11, 22), Pair(10, 26), Pair(3, 26),
        Pair(7, 14), Pair(-7, 26), Pair(9, 6), Pair(-10, -7), Pair(3, -5), Pair(-7, 9), Pair(13, 0), Pair(-14, 21),
        Pair(-2, 10), Pair(0, 10), Pair(0, 4), Pair(-11, 0), Pair(-5, 14), Pair(0, 13), Pair(8, 4), Pair(11, 3)
      },
      { // Piece 4
        Pair(-30, 66), Pair(16, -1), Pair(-42, 49), Pair(15, 42), Pair(42, 61), Pair(20, 38), Pair(87, 50), Pair(38, 53),
        Pair(18, 30), Pair(-3, 54), Pair(-4, 56), Pair(29, -13), Pair(6, 82), Pair(-87, 137), Pair(4, 35), Pair(36, 29),
        Pair(13, 28), Pair(7, 35), Pair(-13, 18), Pair(-24, 78), Pair(6, 43), Pair(-8, 59), Pair(29, 47), Pair(10, 25),
        Pair(-27, 74), Pair(1, 30), Pair(-16, 28), Pair(28, 47), Pair(14, 30), Pair(-8, 42), Pair(13, 38), Pair(-5, 43),
        Pair(2, 37), Pair(8, -9), Pair(-1, 1), Pair(14, 30), Pair(8, 29), Pair(7, 20), Pair(17, 13), Pair(14, 43),
        Pair(-6, 18), Pair(2, 6), Pair(-7, 11), Pair(4, 30), Pair(-2, 24), Pair(1, 21), Pair(-2, 43), Pair(5, 44),
        Pair(-10, 13), Pair(-11, 9), Pair(0, -8), Pair(0, 20), Pair(-3, 24), Pair(7, 20), Pair(4, -5), Pair(5, 42),
        Pair(7, 16), Pair(7, 24), Pair(0, 20), Pair(6, 8), Pair(2, 25), Pair(-13, 60), Pair(9, 7), Pair(-25, 22)
      },
      { // Piece 5
        Pair(12, 167), Pair(12, -55), Pair(-26, -5), Pair(-34, -16), Pair(3, -51), Pair(-23, -76), Pair(-5, -96), Pair(20, -100),
        Pair(-21, 7), Pair(-28, -35), Pair(28, -47), Pair(-17, -61), Pair(-67, -78), Pair(8, -40), Pair(-11, -7), Pair(18, -26),
        Pair(-8, -30), Pair(-29, -54), Pair(-25, -29), Pair(108, -62), Pair(-17, -33), Pair(88, -40), Pair(-3, 15), Pair(6, -6),
        Pair(11, -10), Pair(69, -22), Pair(31, -66), Pair(-12, -20), Pair(6, -57), Pair(53, -22), Pair(103, -9), Pair(-32, 18),
        Pair(126, 21), Pair(-76, 38), Pair(-63, -41), Pair(-45, -59), Pair(54, -52), Pair(39, -17), Pair(41, -1), Pair(21, -9),
        Pair(10, 11), Pair(-52, 19), Pair(71, -38), Pair(-20, -42), Pair(0, -16), Pair(9, -1), Pair(0, 11), Pair(39, 3),
        Pair(-30, 26), Pair(-20, 26), Pair(16, 8), Pair(-20, 4), Pair(-17, 20), Pair(-14, 17), Pair(-3, 10), Pair(7, 9),
        Pair(2, 10), Pair(-16, 23), Pair(-10, 25), Pair(-16, 0), Pair(-2, 15), Pair(-9, 16), Pair(1, 11), Pair(2, 1)
      }
    }},
    {{ // Bucket 28
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-1, 14), Pair(-40, 34), Pair(26, -6), Pair(-56, 56), Pair(21, 8), Pair(51, -63), Pair(-50, 41), Pair(46, -22),
        Pair(13, -9), Pair(14, -1), Pair(9, -10), Pair(-30, 21), Pair(-16, -12), Pair(13, 17), Pair(12, 0), Pair(-14, 20),
        Pair(7, -4), Pair(-2, 3), Pair(3, 4), Pair(4, 0), Pair(3, 1), Pair(-3, 4), Pair(1, 5), Pair(-7, 1),
        Pair(3, 0), Pair(1, -3), Pair(1, -5), Pair(-4, 3), Pair(0, 1), Pair(-7, 7), Pair(-2, -1), Pair(0, 1),
        Pair(-1, -3), Pair(-2, 3), Pair(-1, -2), Pair(0, 1), Pair(5, 4), Pair(-2, -3), Pair(1, -3), Pair(0, 2),
        Pair(1, 1), Pair(-2, 1), Pair(4, -3), Pair(-4, -13), Pair(5, -1), Pair(-5, -3), Pair(-1, 3), Pair(0, -2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-66, 19), Pair(-118, 8), Pair(71, 22), Pair(78, -18), Pair(-38, 27), Pair(-15, 14), Pair(-41, 63), Pair(-14, -2),
        Pair(25, 40), Pair(-21, 36), Pair(9, 30), Pair(14, 42), Pair(-13, 18), Pair(-79, 44), Pair(-47, 62), Pair(49, 1),
        Pair(-43, 25), Pair(-4, 30), Pair(-8, 20), Pair(16, 13), Pair(5, 10), Pair(-15, 30), Pair(-16, 31), Pair(40, 28),
        Pair(9, 19), Pair(-7, 35), Pair(15, 7), Pair(5, 24), Pair(2, 43), Pair(-7, 32), Pair(4, -2), Pair(-3, 18),
        Pair(16, 19), Pair(-22, 7), Pair(3, 25), Pair(3, 40), Pair(19, 62), Pair(-8, 24), Pair(-5, 26), Pair(-4, 4),
        Pair(3, 12), Pair(-4, 20), Pair(3, 11), Pair(-8, 8), Pair(-1, 48), Pair(1, 10), Pair(3, 22), Pair(-11, -13),
        Pair(-6, 39), Pair(10, 3), Pair(-2, 9), Pair(4, 13), Pair(-7, -5), Pair(7, -1), Pair(-17, 25), Pair(1, 23),
        Pair(63, -13), Pair(11, 28), Pair(-8, -13), Pair(10, -2), Pair(-16, -18), Pair(-1, 14), Pair(1, -9), Pair(84, -54)
      },
      { // Piece 2
        Pair(32, -28), Pair(75, -7), Pair(-16, -11), Pair(-141, 61), Pair(-25, 33), Pair(-21, 36), Pair(134, -14), Pair(-66, 79),
        Pair(-22, 43), Pair(-4, 26), Pair(4, 18), Pair(-70, 46), Pair(4, 26), Pair(-26, 38), Pair(4, 25), Pair(18, 5),
        Pair(-7, 29), Pair(2, 40), Pair(-40, 15), Pair(-21, 22), Pair(10, 13), Pair(-29, 41), Pair(-17, 15), Pair(-6, 32),
        Pair(-9, 7), Pair(3, 17), Pair(17, 25), Pair(-4, 40), Pair(0, 11), Pair(17, 11), Pair(-5, 20), Pair(9, 8),
        Pair(-3, 5), Pair(-9, 21), Pair(-5, 17), Pair(-2, 32), Pair(9, 57), Pair(1, 41), Pair(4, 21), Pair(11, 14),
        Pair(-2, 16), Pair(-1, 13), Pair(-3, 1), Pair(-3, 3), Pair(3, 34), Pair(-4, 1), Pair(-10, 14), Pair(2, 8),
        Pair(-6, 52), Pair(-3, -3), Pair(-6, -2), Pair(0, 7), Pair(4, 16), Pair(-6, 16), Pair(-12, -3), Pair(-7, -18),
        Pair(-31, 23), Pair(-5, 38), Pair(2, 10), Pair(3, 4), Pair(-5, 7), Pair(0, 15), Pair(11, 41), Pair(-39, 37)
      },
      { // Piece 3
        Pair(-16, 33), Pair(44, 24), Pair(8, 21), Pair(-36, 39), Pair(7, 25), Pair(13, 8), Pair(-59, 58), Pair(-30, 33),
        Pair(18, 16), Pair(7, 24), Pair(22, 8), Pair(14, 12), Pair(-26, 35), Pair(38, 6), Pair(18, 10), Pair(37, 3),
        Pair(-6, 27), Pair(-6, 19), Pair(-21, 26), Pair(-9, 25), Pair(27, 20), Pair(39, -5), Pair(32, 12), Pair(9, 18),
        Pair(3, 17), Pair(3, 7), Pair(-6, 23), Pair(-5, 11), Pair(53, 39), Pair(26, -2), Pair(8, 18), Pair(2, 6),
        Pair(7, 3), Pair(24, 10), Pair(-18, 10), Pair(-5, 31), Pair(19, -2), Pair(35, -25), Pair(-34, 10), Pair(-11, -8),
        Pair(-22, 19), Pair(-10, 11), Pair(-8, 4), Pair(-10, 6), Pair(-8, 0), Pair(-5, -12), Pair(6, 0), Pair(4, -5),
        Pair(-27, 23), Pair(-17, 21), Pair(-4, 11), Pair(-5, 4), Pair(-9, -7), Pair(13, 7), Pair(-2, 7), Pair(28, -17),
        Pair(4, 8), Pair(-1, 8), Pair(1, 8), Pair(-3, 5), Pair(-9, 2), Pair(-2, 8), Pair(6, 14), Pair(0, 4)
      },
      { // Piece 4
        Pair(-26, 37), Pair(13, 25), Pair(-21, 62), Pair(97, -18), Pair(2, 60), Pair(-64, 121), Pair(43, 44), Pair(49, -34),
        Pair(22, 7), Pair(-16, 28), Pair(7, 44), Pair(-35, 70), Pair(-25, 71), Pair(-42, 99), Pair(-60, 9), Pair(44, -9),
        Pair(4, 13), Pair(4, 15), Pair(19, -2), Pair(2, 29), Pair(20, 25), Pair(2, 71), Pair(24, 33), Pair(-5, 56),
        Pair(-15, 7), Pair(30, 31), Pair(-3, 53), Pair(-4, 51), Pair(24, 68), Pair(8, 58), Pair(7, 43), Pair(-4, 48),
        Pair(8, 9), Pair(2, 4), Pair(6, 13), Pair(-12, 45), Pair(18, 13), Pair(-24, 55), Pair(4, 16), Pair(0, 55),
        Pair(16, 23), Pair(-4, 9), Pair(-8, 14), Pair(-9, 33), Pair(-2, 38), Pair(3, 13), Pair(1, 28), Pair(-1, 62),
        Pair(20, -7), Pair(1, 18), Pair(-3, 5), Pair(1, -3), Pair(6, 19), Pair(-13, 24), Pair(-12, 16), Pair(-10, 4),
        Pair(21, 7), Pair(-4, 26), Pair(2, 6), Pair(5, 6), Pair(0, 45), Pair(-22, 45), Pair(23, 62), Pair(12, 18)
      },
      { // Piece 5
        Pair(-76, -112), Pair(85, 0), Pair(-23, -52), Pair(-21, 36), Pair(29, -55), Pair(69, -82), Pair(9, -15), Pair(-6, -54),
        Pair(-68, -9), Pair(-5, 9), Pair(85, -44), Pair(65, 27), Pair(12, -95), Pair(57, -75), Pair(59, -84), Pair(77, -33),
        Pair(-38, 17), Pair(75, -21), Pair(-80, -22), Pair(5, -62), Pair(102, -61), Pair(162, -66), Pair(48, -18), Pair(-2, -38),
        Pair(12, -10), Pair(47, -7), Pair(7, 18), Pair(-62, -35), Pair(57, -31), Pair(45, -46), Pair(16, -10), Pair(79, -20),
        Pair(41, 19), Pair(112, -25), Pair(-42, 7), Pair(71, -56), Pair(-68, -49), Pair(92, -54), Pair(42, -14), Pair(33, 3),
        Pair(28, 18), Pair(24, -8), Pair(-17, -17), Pair(54, -19), Pair(8, -37), Pair(40, -25), Pair(-6, 3), Pair(-24, 24),
        Pair(36, -22), Pair(24, 14), Pair(1, 10), Pair(18, 12), Pair(0, 0), Pair(23, 5), Pair(-10, 19), Pair(9, 13),
        Pair(19, 10), Pair(1, 16), Pair(0, 13), Pair(1, 29), Pair(-4, 26), Pair(15, 18), Pair(-2, 18), Pair(4, 24)
      }
    }},
    {{ // Bucket 29
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(50, -1), Pair(15, 18), Pair(-34, 32), Pair(-1, -5), Pair(13, -6), Pair(2, -21), Pair(13, 57), Pair(-5, -2),
        Pair(14, 0), Pair(30, -7), Pair(2, 1), Pair(9, 18), Pair(-6, 0), Pair(54, 15), Pair(40, -5), Pair(-9, 1),
        Pair(3, -1), Pair(-2, 5), Pair(-3, 8), Pair(4, 3), Pair(5, -10), Pair(8, -10), Pair(5, 1), Pair(1, -2),
        Pair(3, -2), Pair(-3, -2), Pair(1, -4), Pair(1, -2), Pair(4, 2), Pair(-1, 1), Pair(5, -12), Pair(-1, 1),
        Pair(2, -5), Pair(0, -3), Pair(-3, 0), Pair(1, -3), Pair(-1, 0), Pair(7, 2), Pair(-4, -5), Pair(2, -2),
        Pair(1, -2), Pair(0, -5), Pair(0, -6), Pair(2, -12), Pair(-2, -1), Pair(4, 5), Pair(-2, -5), Pair(2, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-18, -7), Pair(12, 45), Pair(-12, -4), Pair(-54, 41), Pair(-67, 25), Pair(-186, 80), Pair(107, -67), Pair(-57, -12),
        Pair(-25, 26), Pair(23, -7), Pair(26, -10), Pair(-6, 4), Pair(-19, 35), Pair(-3, 25), Pair(34, -8), Pair(-8, 31),
        Pair(23, -12), Pair(8, 14), Pair(10, 8), Pair(10, 1), Pair(-1, 16), Pair(-18, 10), Pair(-30, 6), Pair(40, -31),
        Pair(22, -17), Pair(12, 4), Pair(-15, 8), Pair(-6, 24), Pair(11, 30), Pair(-25, 46), Pair(-9, 18), Pair(9, -18),
        Pair(18, -23), Pair(-2, 6), Pair(5, 8), Pair(11, 5), Pair(-4, 32), Pair(12, 32), Pair(8, -5), Pair(-3, 37),
        Pair(-1, 22), Pair(4, 13), Pair(-2, 11), Pair(-2, 13), Pair(-9, 28), Pair(10, 23), Pair(-18, 5), Pair(-1, -7),
        Pair(-37, 26), Pair(-29, -13), Pair(1, 15), Pair(-2, 9), Pair(0, 19), Pair(-12, 27), Pair(2, 15), Pair(-19, -36),
        Pair(-50, -14), Pair(3, 19), Pair(3, -20), Pair(29, -9), Pair(2, 2), Pair(-9, 4), Pair(-5, 18), Pair(-33, -79)
      },
      { // Piece 2
        Pair(15, 15), Pair(58, 17), Pair(-33, 15), Pair(-20, 9), Pair(3, 22), Pair(8, -26), Pair(55, 45), Pair(92, -1),
        Pair(23, -2), Pair(-58, 39), Pair(30, 6), Pair(17, 23), Pair(42, 1), Pair(-55, 36), Pair(-20, 23), Pair(-11, 37),
        Pair(9, 5), Pair(-9, 20), Pair(-28, 42), Pair(22, 11), Pair(-6, 24), Pair(-1, 5), Pair(-53, 7), Pair(-17, 33),
        Pair(-20, 16), Pair(-3, 17), Pair(2, 7), Pair(11, 19), Pair(10, 12), Pair(6, 37), Pair(4, 10), Pair(-10, 17),
        Pair(-4, 9), Pair(16, -2), Pair(2, 9), Pair(1, 1), Pair(-20, 38), Pair(14, 46), Pair(-14, 1), Pair(-1, 5),
        Pair(-2, -3), Pair(2, -7), Pair(6, 11), Pair(0, 7), Pair(-5, -12), Pair(4, 27), Pair(-29, 11), Pair(2, -16),
        Pair(21, -30), Pair(-1, 15), Pair(-22, 23), Pair(-6, 3), Pair(3, 4), Pair(-6, 25), Pair(-6, -9), Pair(-30, -50),
        Pair(-12, 2), Pair(-12, 15), Pair(-1, 4), Pair(9, 9), Pair(-3, -2), Pair(4, 5), Pair(-45, 50), Pair(-5, 36)
      },
      { // Piece 3
        Pair(-3, 15), Pair(2, 24), Pair(19, 7), Pair(-16, 23), Pair(-7, 23), Pair(-12, 30), Pair(7, 17), Pair(-24, 32),
        Pair(13, 4), Pair(14, 3), Pair(5, 12), Pair(-24, 34), Pair(5, 15), Pair(-9, 18), Pair(93, -14), Pair(5, 2),
        Pair(11, 5), Pair(4, 20), Pair(15, 4), Pair(46, 1), Pair(16, -16), Pair(23, -9), Pair(-27, 18), Pair(-29, 36),
        Pair(3, 8), Pair(15, -8), Pair(-5, 12), Pair(-20, 19), Pair(23, -13), Pair(21, 20), Pair(4, 7), Pair(19, -12),
        Pair(-10, 8), Pair(6, 10), Pair(-3, 15), Pair(-19, 14), Pair(35, -30), Pair(14, 7), Pair(5, -6), Pair(-36, 22),
        Pair(-10, 7), Pair(-14, 22), Pair(-8, 2), Pair(-10, 12), Pair(9, -19), Pair(16, -18), Pair(5, 12), Pair(-1, 30),
        Pair(0, 14), Pair(6, 1), Pair(8, -6), Pair(14, -1), Pair(3, -13), Pair(12, -1), Pair(3, -10), Pair(6, 10),
        Pair(-1, 11), Pair(-5, 14), Pair(0, 7), Pair(-2, 5), Pair(1, 5), Pair(-3, 0), Pair(4, -5), Pair(-1, 13)
      },
      { // Piece 4
        Pair(2, 33), Pair(-35, 50), Pair(44, -37), Pair(-13, 76), Pair(-32, 12), Pair(3, -7), Pair(69, -50), Pair(34, 5),
        Pair(9, 16), Pair(-8, 21), Pair(36, 7), Pair(-9, 59), Pair(42, 39), Pair(7, 6), Pair(3, 37), Pair(39, 14),
        Pair(19, -5), Pair(-5, 12), Pair(7, 14), Pair(34, 0), Pair(1, 20), Pair(-17, 25), Pair(12, 8), Pair(-6, 19),
        Pair(2, 6), Pair(4, 9), Pair(15, 1), Pair(33, 19), Pair(14, 11), Pair(25, 37), Pair(11, -1), Pair(1, 3),
        Pair(-8, 25), Pair(14, -4), Pair(10, 4), Pair(3, -5), Pair(-5, 67), Pair(10, 4), Pair(23, 12), Pair(-7, 26),
        Pair(9, 9), Pair(-3, 31), Pair(5, 4), Pair(-1, 26), Pair(-3, 18), Pair(12, -1), Pair(-2, -15), Pair(-20, 26),
        Pair(3, 33), Pair(-10, 20), Pair(2, 5), Pair(-6, 17), Pair(0, 8), Pair(14, -14), Pair(4, 6), Pair(10, 20),
        Pair(-5, 4), Pair(1, 20), Pair(-5, -6), Pair(2, 2), Pair(16, -27), Pair(-4, -13), Pair(35, -31), Pair(26, -2)
      },
      { // Piece 5
        Pair(88, -126), Pair(-59, -32), Pair(-28, -70), Pair(-38, -39), Pair(17, -63), Pair(34, -63), Pair(-91, -68), Pair(-12, -4),
        Pair(-79, -71), Pair(48, -42), Pair(40, -48), Pair(-132, -32), Pair(-4, -40), Pair(-49, -66), Pair(-29, -60), Pair(-32, -25),
        Pair(-53, -17), Pair(23, -22), Pair(-54, -8), Pair(35, 7), Pair(6, -34), Pair(177, -43), Pair(-21, -30), Pair(72, -23),
        Pair(-71, -31), Pair(-42, -13), Pair(83, -19), Pair(19, -26), Pair(10, -63), Pair(65, -40), Pair(89, -50), Pair(7, -17),
        Pair(6, -3), Pair(14, -20), Pair(63, -19), Pair(17, -8), Pair(68, -40), Pair(-74, -50), Pair(-7, -34), Pair(16, -9),
        Pair(-11, -24), Pair(27, -5), Pair(3, 4), Pair(16, -6), Pair(-4, -17), Pair(13, -29), Pair(-14, -4), Pair(-20, 7),
        Pair(16, -4), Pair(17, 0), Pair(42, -11), Pair(16, -6), Pair(9, 6), Pair(-24, 5), Pair(-4, 13), Pair(-4, 6),
        Pair(14, -9), Pair(-5, 13), Pair(-1, 5), Pair(20, -24), Pair(-8, 14), Pair(-12, 17), Pair(-4, 15), Pair(-4, 11)
      }
    }},
    {{ // Bucket 30
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(74, 15), Pair(-13, 12), Pair(-39, 23), Pair(19, 20), Pair(63, 1), Pair(12, -15), Pair(53, -70), Pair(-72, 24),
        Pair(23, -9), Pair(36, -2), Pair(29, -3), Pair(-8, 22), Pair(30, -2), Pair(-14, -11), Pair(-47, -4), Pair(-10, 15),
        Pair(7, 4), Pair(4, -1), Pair(3, 7), Pair(0, 0), Pair(-10, 5), Pair(-1, -2), Pair(-16, 34), Pair(0, 1),
        Pair(-2, 3), Pair(2, -3), Pair(4, -3), Pair(-5, 0), Pair(-6, -2), Pair(-3, 7), Pair(-3, 0), Pair(16, 4),
        Pair(-2, -3), Pair(1, -2), Pair(-2, -2), Pair(-4, -5), Pair(1, 0), Pair(-7, 4), Pair(-6, 7), Pair(-1, 4),
        Pair(-2, 4), Pair(3, 1), Pair(-4, -2), Pair(6, -1), Pair(-1, -11), Pair(1, 3), Pair(2, 3), Pair(-1, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-16, -34), Pair(-25, 42), Pair(-79, 19), Pair(-17, 8), Pair(-11, 10), Pair(-20, 34), Pair(12, 8), Pair(10, -36),
        Pair(45, 4), Pair(14, 8), Pair(39, 8), Pair(-49, 27), Pair(87, -1), Pair(-14, 1), Pair(-8, 24), Pair(-34, 26),
        Pair(-37, -15), Pair(26, -13), Pair(48, -7), Pair(3, 4), Pair(71, -6), Pair(39, -5), Pair(14, -26), Pair(49, -17),
        Pair(6, 6), Pair(12, 4), Pair(17, -4), Pair(0, 13), Pair(27, 11), Pair(24, 3), Pair(-2, -12), Pair(-24, 13),
        Pair(-21, 2), Pair(-6, 30), Pair(28, 4), Pair(15, 14), Pair(17, 10), Pair(11, 18), Pair(22, 54), Pair(7, -5),
        Pair(-4, 3), Pair(4, -8), Pair(0, 12), Pair(4, 16), Pair(23, 4), Pair(8, 15), Pair(6, 19), Pair(-19, -16),
        Pair(-41, 5), Pair(10, 1), Pair(-18, 26), Pair(-5, 12), Pair(-6, 2), Pair(-5, 17), Pair(-15, -1), Pair(4, 25),
        Pair(-54, 45), Pair(-5, -6), Pair(-16, 8), Pair(-1, -10), Pair(14, -9), Pair(14, -10), Pair(4, -25), Pair(16, 25)
      },
      { // Piece 2
        Pair(7, 40), Pair(-39, 48), Pair(-63, 75), Pair(-37, 30), Pair(-74, 42), Pair(-6, 38), Pair(51, 33), Pair(73, -16),
        Pair(-38, 24), Pair(-19, 32), Pair(22, 31), Pair(-14, 45), Pair(-38, 50), Pair(-60, 22), Pair(-40, 15), Pair(-16, -13),
        Pair(-18, 14), Pair(26, 11), Pair(-2, 38), Pair(-24, 23), Pair(-4, 21), Pair(-8, 9), Pair(-46, 44), Pair(13, -20),
        Pair(-1, 10), Pair(24, 13), Pair(21, 13), Pair(18, 25), Pair(7, 18), Pair(-12, 19), Pair(14, 44), Pair(-14, 4),
        Pair(11, -9), Pair(16, 17), Pair(0, 12), Pair(15, 24), Pair(14, 12), Pair(-13, 21), Pair(16, 33), Pair(-20, 11),
        Pair(-14, 10), Pair(-1, 20), Pair(7, 15), Pair(-3, 19), Pair(8, 8), Pair(0, 13), Pair(-1, 19), Pair(16, 5),
        Pair(-40, 40), Pair(2, 10), Pair(14, -1), Pair(-1, 20), Pair(-6, 11), Pair(9, -6), Pair(16, 1), Pair(10, -37),
        Pair(37, -21), Pair(18, -1), Pair(-2, -5), Pair(-16, 5), Pair(10, 19), Pair(4, 13), Pair(-27, 32), Pair(-31, 12)
      },
      { // Piece 3
        Pair(-11, 31), Pair(-31, 44), Pair(-7, 28), Pair(1, 9), Pair(7, 19), Pair(-71, 39), Pair(45, 20), Pair(14, 22),
        Pair(4, 5), Pair(10, 6), Pair(3, 20), Pair(13, 10), Pair(33, 16), Pair(53, -8), Pair(32, 21), Pair(11, 9),
        Pair(12, -7), Pair(-30, 15), Pair(36, 3), Pair(-1, 10), Pair(-26, 4), Pair(82, -20), Pair(-35, 50), Pair(-9, 8),
        Pair(-8, 7), Pair(15, 9), Pair(-3, 8), Pair(23, -4), Pair(41, 3), Pair(-8, 21), Pair(13, 25), Pair(2, 4),
        Pair(3, 2), Pair(-17, 19), Pair(-6, 11), Pair(-12, 1), Pair(-2, 13), Pair(38, -15), Pair(-2, 7), Pair(55, -47),
        Pair(0, -6), Pair(14, 6), Pair(-3, 3), Pair(-44, 33), Pair(9, -6), Pair(-7, 12), Pair(-8, 20), Pair(-56, 55),
        Pair(6, -9), Pair(26, 1), Pair(-14, 17), Pair(14, 3), Pair(8, -3), Pair(-24, 33), Pair(-14, -24), Pair(5, -5),
        Pair(1, 8), Pair(1, 13), Pair(1, 5), Pair(4, 7), Pair(1, 17), Pair(0, 9), Pair(-1, 5), Pair(-6, 3)
      },
      { // Piece 4
        Pair(21, 9), Pair(56, -90), Pair(61, -2), Pair(51, -2), Pair(-44, 30), Pair(70, -11), Pair(2, -12), Pair(-30, 11),
        Pair(7, -10), Pair(5, -1), Pair(8, -12), Pair(-31, 20), Pair(-23, 41), Pair(35, 22), Pair(-4, 74), Pair(-1, 11),
        Pair(21, -60), Pair(19, 25), Pair(25, -9), Pair(1, 20), Pair(-4, 73), Pair(3, -25), Pair(21, 45), Pair(-13, 0),
        Pair(-14, -6), Pair(10, -28), Pair(-14, 11), Pair(9, -5), Pair(15, 14), Pair(5, 11), Pair(16, 45), Pair(-12, 42),
        Pair(-6, 24), Pair(31, -10), Pair(40, -39), Pair(-2, 39), Pair(9, 27), Pair(-6, 51), Pair(13, 3), Pair(-25, 101),
        Pair(11, -14), Pair(-8, 25), Pair(1, 4), Pair(7, -13), Pair(0, -16), Pair(-20, 41), Pair(-8, 27), Pair(-42, 57),
        Pair(-2, 4), Pair(8, -15), Pair(8, 0), Pair(14, -12), Pair(2, 16), Pair(-12, 18), Pair(-22, -21), Pair(-10, -11),
        Pair(-11, -29), Pair(2, 11), Pair(-9, 1), Pair(3, 19), Pair(17, -30), Pair(-23, 22), Pair(-12, 79), Pair(16, -65)
      },
      { // Piece 5
        Pair(23, -127), Pair(-29, -6), Pair(10, -132), Pair(61, -1), Pair(55, -9), Pair(-44, -39), Pair(1, -102), Pair(-19, -192),
        Pair(69, -38), Pair(-43, -35), Pair(176, -51), Pair(55, -26), Pair(96, -48), Pair(59, -35), Pair(110, -86), Pair(15, -13),
        Pair(218, -9), Pair(-76, -32), Pair(36, -26), Pair(-83, -9), Pair(15, -10), Pair(47, -3), Pair(100, -19), Pair(114, -16),
        Pair(13, -33), Pair(32, -20), Pair(44, -22), Pair(67, -31), Pair(6, -7), Pair(121, -40), Pair(-3, 3), Pair(-83, -56),
        Pair(43, -38), Pair(83, -39), Pair(51, -34), Pair(-1, -6), Pair(3, -14), Pair(49, -36), Pair(-48, -70), Pair(-147, -33),
        Pair(127, -51), Pair(83, -40), Pair(10, -20), Pair(19, -8), Pair(-28, -4), Pair(25, -14), Pair(2, -35), Pair(-24, -19),
        Pair(24, -23), Pair(-38, 0), Pair(12, -11), Pair(36, -21), Pair(27, -9), Pair(28, 2), Pair(2, 1), Pair(-7, 14),
        Pair(-10, -4), Pair(11, -35), Pair(-7, 0), Pair(30, -26), Pair(-19, 17), Pair(-13, 28), Pair(-3, 8), Pair(0, 8)
      }
    }},
    {{ // Bucket 31
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(73, -1), Pair(74, 23), Pair(81, 0), Pair(36, 1), Pair(56, -1), Pair(-48, -1), Pair(-111, 38), Pair(-60, 7),
        Pair(33, -5), Pair(22, 1), Pair(9, 7), Pair(31, 7), Pair(2, 6), Pair(-33, 9), Pair(26, 21), Pair(26, -50),
        Pair(16, -8), Pair(5, 4), Pair(8, 0), Pair(-2, 11), Pair(-7, 3), Pair(-13, 6), Pair(-13, 8), Pair(17, 24),
        Pair(1, -4), Pair(6, -5), Pair(1, -5), Pair(-3, -6), Pair(0, -3), Pair(3, 1), Pair(-4, -6), Pair(4, -1),
        Pair(1, -5), Pair(5, -6), Pair(-2, -4), Pair(-4, -2), Pair(3, -5), Pair(4, -2), Pair(-4, -4), Pair(6, 7),
        Pair(-2, -4), Pair(3, -4), Pair(-5, -6), Pair(-3, -16), Pair(-2, -4), Pair(1, -2), Pair(-4, -6), Pair(0, 7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-11, 36), Pair(61, -6), Pair(-6, -1), Pair(73, 23), Pair(60, -13), Pair(-75, 9), Pair(24, -11), Pair(9, -87),
        Pair(11, -40), Pair(8, -22), Pair(-9, -9), Pair(7, 15), Pair(60, -9), Pair(2, -18), Pair(59, 16), Pair(44, 73),
        Pair(18, -30), Pair(-1, 2), Pair(24, -9), Pair(5, 17), Pair(20, 0), Pair(28, -10), Pair(-19, 13), Pair(-64, 56),
        Pair(12, 3), Pair(4, -2), Pair(8, 1), Pair(12, 8), Pair(24, 12), Pair(19, -3), Pair(3, 10), Pair(40, 20),
        Pair(-16, 4), Pair(12, -17), Pair(9, 6), Pair(8, 7), Pair(17, 6), Pair(25, 9), Pair(4, 41), Pair(25, 23),
        Pair(-11, -3), Pair(-1, 1), Pair(5, 3), Pair(-6, 10), Pair(7, 8), Pair(6, 12), Pair(5, 27), Pair(14, 30),
        Pair(4, -34), Pair(-20, 12), Pair(-5, -6), Pair(3, 3), Pair(-3, 26), Pair(-5, 26), Pair(-10, 26), Pair(-8, -29),
        Pair(54, -92), Pair(-7, 26), Pair(-33, -2), Pair(-12, -1), Pair(11, -12), Pair(-3, -6), Pair(-11, 6), Pair(0, -71)
      },
      { // Piece 2
        Pair(40, 43), Pair(15, 12), Pair(-38, 66), Pair(-46, 27), Pair(-94, 57), Pair(84, 23), Pair(-94, 45), Pair(-84, 25),
        Pair(-48, 54), Pair(11, 28), Pair(9, 24), Pair(-27, 62), Pair(-45, 55), Pair(-38, 60), Pair(-61, 6), Pair(107, 4),
        Pair(-14, 43), Pair(-30, 32), Pair(-25, 41), Pair(24, 7), Pair(18, 22), Pair(1, 12), Pair(21, 53), Pair(14, 21),
        Pair(-32, 43), Pair(6, 25), Pair(13, 19), Pair(4, 26), Pair(24, 7), Pair(8, 37), Pair(2, 28), Pair(29, 8),
        Pair(-15, 32), Pair(7, 13), Pair(18, 12), Pair(14, -7), Pair(-17, 40), Pair(15, 4), Pair(-5, 26), Pair(-2, 62),
        Pair(-4, 9), Pair(13, 4), Pair(10, -1), Pair(6, 19), Pair(7, 5), Pair(-2, 27), Pair(3, 0), Pair(2, 65),
        Pair(28, 15), Pair(3, 18), Pair(-13, 11), Pair(1, 13), Pair(1, 15), Pair(-1, 17), Pair(12, 16), Pair(24, 42),
        Pair(21, -20), Pair(27, -9), Pair(-7, 10), Pair(0, 13), Pair(-7, 12), Pair(2, 23), Pair(-6, 17), Pair(33, 13)
      },
      { // Piece 3
        Pair(-20, 15), Pair(13, 13), Pair(14, 34), Pair(-5, 14), Pair(-21, 13), Pair(35, 32), Pair(-17, 26), Pair(-9, 36),
        Pair(10, 5), Pair(12, 6), Pair(22, 9), Pair(23, 5), Pair(17, -13), Pair(23, -5), Pair(38, 6), Pair(108, -3),
        Pair(23, 13), Pair(20, 2), Pair(1, 6), Pair(10, 7), Pair(9, 3), Pair(6, 6), Pair(-10, 13), Pair(121, 6),
        Pair(-3, 16), Pair(12, 1), Pair(-2, 16), Pair(23, -4), Pair(3, 12), Pair(33, 2), Pair(15, 30), Pair(100, 2),
        Pair(-19, 14), Pair(22, -5), Pair(19, 11), Pair(4, 6), Pair(17, 11), Pair(-13, 14), Pair(42, -16), Pair(-4, 41),
        Pair(-17, -1), Pair(0, 21), Pair(14, 0), Pair(14, -12), Pair(2, 16), Pair(-11, 29), Pair(32, -10), Pair(-16, 13),
        Pair(19, -2), Pair(1, 18), Pair(8, 1), Pair(1, 19), Pair(-21, 16), Pair(-4, -2), Pair(-15, 7), Pair(-40, 14),
        Pair(-3, 12), Pair(-5, 18), Pair(1, 13), Pair(5, 6), Pair(0, 10), Pair(5, -4), Pair(-3, 15), Pair(-9, -1)
      },
      { // Piece 4
        Pair(27, -13), Pair(88, -22), Pair(15, 7), Pair(73, -26), Pair(-9, 28), Pair(-53, 31), Pair(29, 44), Pair(2, 15),
        Pair(24, -16), Pair(-21, 65), Pair(31, -9), Pair(25, 2), Pair(-11, 18), Pair(-43, 35), Pair(4, 27), Pair(65, -42),
        Pair(10, -16), Pair(32, -39), Pair(-2, -8), Pair(-14, 13), Pair(-13, 47), Pair(6, 41), Pair(-7, -4), Pair(0, 44),
        Pair(18, -1), Pair(10, -11), Pair(18, 3), Pair(2, -6), Pair(40, 9), Pair(16, 24), Pair(-2, 47), Pair(39, 9),
        Pair(14, -19), Pair(18, -11), Pair(-10, 18), Pair(-4, 12), Pair(8, 38), Pair(11, 5), Pair(14, -39), Pair(-1, -13),
        Pair(13, -20), Pair(5, -3), Pair(-12, 4), Pair(19, -25), Pair(-3, 13), Pair(-17, 32), Pair(2, 10), Pair(-46, 60),
        Pair(-18, 22), Pair(-2, -8), Pair(5, -17), Pair(5, 0), Pair(4, -7), Pair(12, -23), Pair(25, -18), Pair(-14, 18),
        Pair(-6, 11), Pair(-10, 5), Pair(-4, 11), Pair(3, 9), Pair(1, 10), Pair(-3, 26), Pair(-15, 3), Pair(-46, 38)
      },
      { // Piece 5
        Pair(-19, -109), Pair(-14, -33), Pair(196, -43), Pair(71, -103), Pair(77, -40), Pair(35, -93), Pair(-6, -13), Pair(30, 16),
        Pair(21, -55), Pair(46, -46), Pair(109, -39), Pair(-21, -1), Pair(-18, -19), Pair(-25, -55), Pair(0, -107), Pair(24, -27),
        Pair(94, -81), Pair(44, -38), Pair(5, -40), Pair(32, -50), Pair(113, -30), Pair(66, -57), Pair(-94, 5), Pair(-47, -39),
        Pair(47, -43), Pair(26, -23), Pair(45, -49), Pair(40, -19), Pair(-24, -13), Pair(-38, -20), Pair(56, -62), Pair(-34, -9),
        Pair(164, -34), Pair(84, -51), Pair(74, -18), Pair(29, -24), Pair(-18, -10), Pair(-22, -7), Pair(-30, -39), Pair(110, -98),
        Pair(20, -18), Pair(50, -35), Pair(16, -40), Pair(27, -18), Pair(5, -12), Pair(-26, 1), Pair(11, -7), Pair(24, -32),
        Pair(-7, -24), Pair(-37, -17), Pair(11, -37), Pair(3, -20), Pair(2, -3), Pair(-27, 5), Pair(-7, 14), Pair(-10, -3),
        Pair(7, -34), Pair(-1, -34), Pair(-29, -14), Pair(2, -1), Pair(-13, 8), Pair(-29, 18), Pair(5, 14), Pair(0, -6)
      }
    }},
    {{ // Bucket 32
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(60, 49), Pair(-6, 23), Pair(-41, 56), Pair(40, 35), Pair(11, 30), Pair(73, 18), Pair(-35, -12), Pair(42, 1),
        Pair(-10, -3), Pair(-6, 31), Pair(-5, 17), Pair(20, 13), Pair(21, 9), Pair(26, 19), Pair(-2, 27), Pair(3, 31),
        Pair(-15, -47), Pair(-3, 2), Pair(2, -2), Pair(1, -1), Pair(3, 2), Pair(0, 9), Pair(-4, 7), Pair(-7, 13),
        Pair(1, 0), Pair(-6, -3), Pair(3, -4), Pair(1, 4), Pair(-3, -1), Pair(-5, -2), Pair(4, -5), Pair(0, 1),
        Pair(9, 7), Pair(-3, -4), Pair(0, -5), Pair(-1, -5), Pair(-1, -2), Pair(-4, -1), Pair(2, -6), Pair(-5, 1),
        Pair(8, 0), Pair(-8, -6), Pair(3, 0), Pair(4, -22), Pair(-3, -5), Pair(-4, -5), Pair(-1, -6), Pair(2, -1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-103, 55), Pair(-78, 19), Pair(4, -17), Pair(34, 65), Pair(-5, -21), Pair(-49, -8), Pair(-93, -1), Pair(-21, 23),
        Pair(52, 15), Pair(18, 21), Pair(39, -29), Pair(46, 18), Pair(-20, 21), Pair(83, -40), Pair(136, -48), Pair(111, -72),
        Pair(42, -32), Pair(36, -16), Pair(4, 11), Pair(17, 14), Pair(-9, 10), Pair(35, -19), Pair(64, -23), Pair(55, -22),
        Pair(18, 70), Pair(11, -4), Pair(9, 7), Pair(13, -8), Pair(7, 5), Pair(5, 20), Pair(18, 8), Pair(19, -14),
        Pair(-1, 53), Pair(-4, -8), Pair(7, 12), Pair(6, -4), Pair(10, 0), Pair(11, -6), Pair(-1, 1), Pair(10, -21),
        Pair(4, 18), Pair(-7, 17), Pair(-1, 14), Pair(-20, -1), Pair(3, 1), Pair(2, 9), Pair(7, -7), Pair(10, -16),
        Pair(18, 0), Pair(26, 12), Pair(3, -16), Pair(-5, 2), Pair(2, 1), Pair(5, -9), Pair(-16, 4), Pair(5, -4),
        Pair(-85, -35), Pair(-4, -20), Pair(-33, 3), Pair(-1, -26), Pair(-22, 26), Pair(-4, -17), Pair(-2, 21), Pair(-14, 38)
      },
      { // Piece 2
        Pair(-92, 40), Pair(-57, 39), Pair(-53, 24), Pair(-54, 42), Pair(-24, 28), Pair(-41, 53), Pair(-8, 54), Pair(68, 57),
        Pair(47, 38), Pair(-26, 31), Pair(-6, 39), Pair(-33, 47), Pair(-2, 44), Pair(35, 31), Pair(-23, 71), Pair(-3, -5),
        Pair(-13, 13), Pair(0, 27), Pair(-40, 46), Pair(-13, 54), Pair(12, 32), Pair(24, 41), Pair(10, 13), Pair(20, 29),
        Pair(26, 14), Pair(-12, 22), Pair(3, 41), Pair(-7, 37), Pair(7, 29), Pair(-3, 23), Pair(2, 40), Pair(-1, 21),
        Pair(2, 59), Pair(-15, 41), Pair(-4, 22), Pair(-11, 30), Pair(9, 13), Pair(5, 4), Pair(9, 1), Pair(17, -17),
        Pair(6, 64), Pair(-9, 6), Pair(-2, 36), Pair(-3, 15), Pair(0, 20), Pair(-5, 7), Pair(-3, 25), Pair(-9, 26),
        Pair(-10, 47), Pair(4, 26), Pair(0, 13), Pair(-5, 31), Pair(-6, 13), Pair(0, 3), Pair(-2, 1), Pair(8, -8),
        Pair(-2, 42), Pair(12, 32), Pair(-2, 21), Pair(-13, 13), Pair(-12, 28), Pair(-4, 7), Pair(-35, 66), Pair(20, -6)
      },
      { // Piece 3
        Pair(42, 33), Pair(38, 11), Pair(30, 29), Pair(35, 26), Pair(9, 34), Pair(-6, 55), Pair(58, 26), Pair(14, 29),
        Pair(27, 50), Pair(22, 32), Pair(-5, 42), Pair(22, 21), Pair(8, 53), Pair(15, 23), Pair(99, 11), Pair(-21, 41),
        Pair(36, 38), Pair(-8, 31), Pair(2, 40), Pair(-1, 40), Pair(32, 23), Pair(44, 33), Pair(-5, 27), Pair(14, 19),
        Pair(-39, 53), Pair(5, 26), Pair(0, 49), Pair(7, 44), Pair(24, 19), Pair(18, 16), Pair(26, 20), Pair(-5, 31),
        Pair(2, 17), Pair(23, 0), Pair(-12, 30), Pair(10, 19), Pair(22, 17), Pair(-1, 34), Pair(24, 12), Pair(19, 9),
        Pair(-12, 6), Pair(-3, 23), Pair(-19, 34), Pair(-9, 7), Pair(5, 16), Pair(-3, 21), Pair(2, 21), Pair(21, 0),
        Pair(-37, 5), Pair(-8, 22), Pair(3, 11), Pair(-19, 21), Pair(0, 13), Pair(11, 7), Pair(27, 13), Pair(3, 58),
        Pair(-3, 3), Pair(-10, 21), Pair(-5, 19), Pair(-1, 16), Pair(2, 17), Pair(4, 18), Pair(14, 24), Pair(5, 31)
      },
      { // Piece 4
        Pair(6, 65), Pair(41, 40), Pair(17, 54), Pair(32, 76), Pair(-8, 84), Pair(22, 59), Pair(25, 44), Pair(39, 41),
        Pair(-21, 104), Pair(9, 45), Pair(9, 75), Pair(14, 88), Pair(-6, 69), Pair(35, 49), Pair(33, 52), Pair(27, 11),
        Pair(-27, 85), Pair(11, 48), Pair(-5, 76), Pair(-8, 58), Pair(0, 49), Pair(45, 41), Pair(44, 44), Pair(32, 41),
        Pair(30, 71), Pair(10, 10), Pair(-1, 63), Pair(-3, 49), Pair(22, 30), Pair(27, 57), Pair(10, 84), Pair(31, 47),
        Pair(0, 31), Pair(1, 38), Pair(4, 43), Pair(-5, 40), Pair(2, 39), Pair(9, 32), Pair(29, 6), Pair(24, -21),
        Pair(3, 35), Pair(-3, 35), Pair(1, 41), Pair(8, 10), Pair(1, 34), Pair(7, 29), Pair(16, 15), Pair(8, 48),
        Pair(12, -14), Pair(6, 5), Pair(2, 22), Pair(0, 26), Pair(5, 9), Pair(-2, 8), Pair(-1, 20), Pair(-5, 55),
        Pair(0, 9), Pair(-11, 21), Pair(-3, 9), Pair(1, 18), Pair(6, 12), Pair(8, 4), Pair(11, 29), Pair(-13, -33)
      },
      { // Piece 5
        Pair(20, 104), Pair(-54, -13), Pair(-18, 2), Pair(52, -51), Pair(-9, -47), Pair(-24, -13), Pair(5, -93), Pair(5, 18),
        Pair(46, 42), Pair(-13, -56), Pair(96, -34), Pair(8, -3), Pair(-29, -13), Pair(2, -9), Pair(43, -29), Pair(66, -41),
        Pair(-70, -31), Pair(68, -49), Pair(133, -17), Pair(51, -10), Pair(69, -5), Pair(-67, 11), Pair(23, -18), Pair(69, -30),
        Pair(6, 52), Pair(8, -23), Pair(35, -21), Pair(-54, -12), Pair(88, -23), Pair(51, -16), Pair(10, -2), Pair(-13, 4),
        Pair(-20, -62), Pair(-160, 25), Pair(4, -7), Pair(-15, 0), Pair(35, -2), Pair(35, -6), Pair(7, -1), Pair(56, -25),
        Pair(-7, -14), Pair(-68, 19), Pair(-49, 5), Pair(-9, -6), Pair(-8, 1), Pair(13, -1), Pair(0, -12), Pair(16, -1),
        Pair(12, -13), Pair(9, 17), Pair(-17, 14), Pair(8, 3), Pair(11, 0), Pair(19, -10), Pair(5, -4), Pair(11, -9),
        Pair(36, 7), Pair(18, 13), Pair(2, 14), Pair(2, 1), Pair(-2, -10), Pair(16, -8), Pair(1, -13), Pair(4, 4)
      }
    }},
    {{ // Bucket 33
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-34, 41), Pair(49, 40), Pair(-52, 35), Pair(35, 12), Pair(14, 3), Pair(-4, 16), Pair(36, 37), Pair(62, 18),
        Pair(-14, 24), Pair(-2, 32), Pair(28, -4), Pair(1, 16), Pair(17, 19), Pair(14, 7), Pair(-5, 17), Pair(2, 22),
        Pair(-3, 5), Pair(-3, 1), Pair(2, 1), Pair(-2, 9), Pair(3, 8), Pair(1, 5), Pair(-3, 12), Pair(1, 6),
        Pair(6, 2), Pair(1, -3), Pair(1, 5), Pair(3, 2), Pair(-6, 1), Pair(-3, 3), Pair(-11, 6), Pair(-4, 3),
        Pair(4, 4), Pair(11, 10), Pair(3, 3), Pair(7, -10), Pair(0, -4), Pair(-7, 1), Pair(-5, 2), Pair(-4, 0),
        Pair(1, -2), Pair(7, 7), Pair(-7, 2), Pair(5, 1), Pair(-7, 1), Pair(-6, 2), Pair(-10, 0), Pair(-1, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-86, 7), Pair(-7, -38), Pair(-30, -35), Pair(48, 24), Pair(48, -32), Pair(36, 37), Pair(-6, 52), Pair(68, -34),
        Pair(-5, 28), Pair(50, 14), Pair(84, -21), Pair(56, 21), Pair(-3, 50), Pair(42, -7), Pair(17, -28), Pair(-8, 9),
        Pair(6, 69), Pair(21, 6), Pair(31, 11), Pair(10, 33), Pair(17, 8), Pair(77, -3), Pair(-13, 29), Pair(49, 0),
        Pair(-23, 31), Pair(-3, -13), Pair(-9, 30), Pair(8, 47), Pair(8, 33), Pair(17, 26), Pair(24, 26), Pair(28, -5),
        Pair(0, 7), Pair(26, 47), Pair(4, 39), Pair(8, 24), Pair(5, 49), Pair(4, 23), Pair(15, 22), Pair(11, 38),
        Pair(11, -17), Pair(25, 55), Pair(5, 27), Pair(11, 20), Pair(3, 16), Pair(8, 26), Pair(9, 20), Pair(3, 44),
        Pair(-1, 34), Pair(-6, 24), Pair(-4, 46), Pair(3, 17), Pair(11, 5), Pair(17, -6), Pair(4, 34), Pair(4, 46),
        Pair(69, -32), Pair(-15, -11), Pair(32, 1), Pair(22, 4), Pair(2, 31), Pair(-3, 29), Pair(-6, 23), Pair(34, -31)
      },
      { // Piece 2
        Pair(78, 23), Pair(-45, 40), Pair(14, 42), Pair(14, 44), Pair(-98, 74), Pair(-6, 53), Pair(-98, 86), Pair(-12, 51),
        Pair(5, 27), Pair(-75, 79), Pair(34, 27), Pair(-22, 83), Pair(40, 64), Pair(-11, 90), Pair(55, 39), Pair(3, 27),
        Pair(-27, 25), Pair(-24, 47), Pair(14, 56), Pair(2, 42), Pair(63, 16), Pair(1, 42), Pair(39, 57), Pair(9, 40),
        Pair(11, 13), Pair(1, 33), Pair(8, 38), Pair(-4, 61), Pair(-1, 52), Pair(-14, 63), Pair(9, 25), Pair(22, 32),
        Pair(2, 67), Pair(19, 45), Pair(13, 46), Pair(-4, 34), Pair(1, 48), Pair(3, 30), Pair(27, 30), Pair(7, 6),
        Pair(-12, 31), Pair(-1, 70), Pair(-5, 27), Pair(7, 33), Pair(4, 29), Pair(6, 32), Pair(15, 4), Pair(12, 16),
        Pair(8, 17), Pair(0, 33), Pair(-2, 26), Pair(-8, 27), Pair(-4, 25), Pair(24, 7), Pair(1, 20), Pair(16, -41),
        Pair(1, 36), Pair(31, 50), Pair(-5, 40), Pair(-2, 47), Pair(-4, 22), Pair(-5, 21), Pair(0, 38), Pair(31, 25)
      },
      { // Piece 3
        Pair(6, 51), Pair(58, 31), Pair(6, 66), Pair(23, 33), Pair(25, 34), Pair(19, 22), Pair(40, 46), Pair(31, 51),
        Pair(17, 51), Pair(-2, 61), Pair(35, 37), Pair(10, 47), Pair(3, 48), Pair(12, 50), Pair(30, 28), Pair(-14, 56),
        Pair(-6, 38), Pair(-12, 54), Pair(2, 47), Pair(11, 37), Pair(7, 56), Pair(40, 38), Pair(49, 50), Pair(20, 43),
        Pair(30, -5), Pair(-10, 51), Pair(11, 47), Pair(18, 36), Pair(-1, 54), Pair(22, 5), Pair(38, 40), Pair(-17, 39),
        Pair(1, 15), Pair(-4, 15), Pair(-6, 47), Pair(-8, 54), Pair(-4, 39), Pair(28, 29), Pair(-15, 37), Pair(63, -5),
        Pair(-13, 45), Pair(-14, 30), Pair(22, 1), Pair(-17, 43), Pair(-3, 28), Pair(-7, 36), Pair(10, 23), Pair(17, 31),
        Pair(0, 2), Pair(-11, 14), Pair(9, 20), Pair(8, 17), Pair(19, 22), Pair(-5, 28), Pair(-5, 44), Pair(-58, 82),
        Pair(-2, 30), Pair(7, 3), Pair(-4, 29), Pair(7, 33), Pair(4, 36), Pair(4, 33), Pair(10, 40), Pair(6, 44)
      },
      { // Piece 4
        Pair(27, 28), Pair(-16, 75), Pair(16, 60), Pair(44, 5), Pair(-44, 105), Pair(3, 13), Pair(51, 52), Pair(-21, 45),
        Pair(15, 35), Pair(-8, 60), Pair(-4, 32), Pair(46, 20), Pair(36, 51), Pair(-41, 137), Pair(49, 84), Pair(4, 61),
        Pair(32, 8), Pair(-1, 51), Pair(-22, 124), Pair(-4, 76), Pair(1, 83), Pair(-37, 76), Pair(22, 23), Pair(34, 39),
        Pair(20, 11), Pair(46, -31), Pair(-29, 77), Pair(13, 73), Pair(46, 20), Pair(35, 41), Pair(-11, 89), Pair(31, 44),
        Pair(25, -19), Pair(-8, 36), Pair(31, 23), Pair(7, 64), Pair(19, 55), Pair(27, 25), Pair(9, 70), Pair(21, 65),
        Pair(11, 2), Pair(13, 41), Pair(16, 25), Pair(15, 6), Pair(24, 14), Pair(6, 63), Pair(38, 13), Pair(14, 44),
        Pair(-15, 67), Pair(2, 27), Pair(6, 25), Pair(7, 29), Pair(11, 30), Pair(12, 9), Pair(20, 3), Pair(-9, 96),
        Pair(0, 37), Pair(15, -5), Pair(6, 14), Pair(11, 25), Pair(6, 17), Pair(29, 12), Pair(40, -23), Pair(-40, 33)
      },
      { // Piece 5
        Pair(-35, -125), Pair(5, -27), Pair(19, -64), Pair(8, -50), Pair(-45, 43), Pair(-43, -2), Pair(0, -28), Pair(12, -130),
        Pair(23, 4), Pair(46, -86), Pair(-21, -156), Pair(-11, -23), Pair(-67, -24), Pair(-76, -32), Pair(-21, -48), Pair(-68, -50),
        Pair(-81, -29), Pair(-40, -41), Pair(115, -38), Pair(77, -23), Pair(18, -24), Pair(69, -3), Pair(49, -18), Pair(66, -14),
        Pair(-95, -48), Pair(-33, -18), Pair(60, -68), Pair(98, -31), Pair(-8, -20), Pair(-12, -11), Pair(-24, 0), Pair(10, -17),
        Pair(-54, -23), Pair(-48, -88), Pair(-3, -27), Pair(39, -17), Pair(54, -13), Pair(-9, 0), Pair(7, 4), Pair(-8, 9),
        Pair(-53, -29), Pair(-73, -31), Pair(-16, -30), Pair(-30, -8), Pair(-26, 0), Pair(19, -8), Pair(44, -20), Pair(63, -30),
        Pair(-20, 8), Pair(-22, -19), Pair(41, -13), Pair(-22, 8), Pair(28, -6), Pair(-7, -7), Pair(4, -17), Pair(5, -12),
        Pair(17, 23), Pair(1, 4), Pair(6, 16), Pair(-11, -9), Pair(-9, 1), Pair(23, -13), Pair(-1, -12), Pair(7, -16)
      }
    }},
    {{ // Bucket 34
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-9, 43), Pair(5, 52), Pair(11, -1), Pair(-3, 17), Pair(-15, 14), Pair(61, 33), Pair(17, 45), Pair(-11, 40),
        Pair(-22, 9), Pair(-4, 10), Pair(1, 17), Pair(13, -3), Pair(15, 12), Pair(8, 25), Pair(-9, 8), Pair(-15, 17),
        Pair(-8, 3), Pair(2, 4), Pair(-6, 4), Pair(8, -6), Pair(-1, 5), Pair(11, -3), Pair(12, 0), Pair(8, 1),
        Pair(-2, 0), Pair(-4, -4), Pair(1, -1), Pair(-2, 6), Pair(-5, -2), Pair(-2, -3), Pair(-2, 1), Pair(-3, -6),
        Pair(-1, 0), Pair(0, -8), Pair(4, 9), Pair(-2, 2), Pair(-3, 2), Pair(-8, -3), Pair(-2, -1), Pair(-4, 0),
        Pair(-1, 3), Pair(-2, -7), Pair(9, 6), Pair(-8, 5), Pair(-3, -8), Pair(-5, -7), Pair(-2, -3), Pair(-2, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-43, 55), Pair(-4, 30), Pair(114, -54), Pair(109, -5), Pair(-109, 48), Pair(89, 78), Pair(-17, 78), Pair(-37, 70),
        Pair(-8, 20), Pair(15, -9), Pair(-1, 20), Pair(-10, 53), Pair(-8, 26), Pair(-13, 41), Pair(-15, 50), Pair(71, 3),
        Pair(-2, -18), Pair(0, 28), Pair(-31, 24), Pair(1, 28), Pair(-1, 21), Pair(-39, 25), Pair(-17, 17), Pair(-9, 7),
        Pair(-4, 26), Pair(-8, 36), Pair(-18, 3), Pair(3, 38), Pair(4, 35), Pair(25, 25), Pair(19, 20), Pair(13, 23),
        Pair(1, 17), Pair(-31, 21), Pair(17, 55), Pair(15, 23), Pair(19, 28), Pair(-2, 18), Pair(8, 5), Pair(2, 20),
        Pair(-3, 0), Pair(-4, -11), Pair(3, 28), Pair(-1, 1), Pair(7, 20), Pair(0, 15), Pair(3, 18), Pair(15, 28),
        Pair(-28, 39), Pair(13, 26), Pair(-23, 21), Pair(3, 16), Pair(3, 21), Pair(-5, 26), Pair(26, 3), Pair(11, 26),
        Pair(30, -29), Pair(9, -2), Pair(-27, 13), Pair(13, 8), Pair(10, 11), Pair(9, 8), Pair(5, 21), Pair(72, 67)
      },
      { // Piece 2
        Pair(24, 27), Pair(38, 24), Pair(16, -6), Pair(44, 29), Pair(11, 30), Pair(-11, 60), Pair(16, 8), Pair(18, 43),
        Pair(-11, 1), Pair(4, 45), Pair(-5, 42), Pair(-6, 13), Pair(-29, 39), Pair(-33, 42), Pair(-16, 48), Pair(-39, 42),
        Pair(32, 19), Pair(-54, 45), Pair(-31, 31), Pair(1, 28), Pair(-11, 21), Pair(5, 50), Pair(4, 32), Pair(7, 35),
        Pair(-22, 33), Pair(-5, 22), Pair(24, 4), Pair(3, 44), Pair(-5, 39), Pair(-13, 28), Pair(-5, 21), Pair(7, -10),
        Pair(-21, 46), Pair(-5, 20), Pair(10, 57), Pair(6, 20), Pair(1, 15), Pair(5, 15), Pair(8, -1), Pair(5, 23),
        Pair(-1, -7), Pair(-17, 16), Pair(-4, 48), Pair(0, 3), Pair(-9, 19), Pair(2, 10), Pair(15, -3), Pair(4, 7),
        Pair(-49, 9), Pair(-1, -1), Pair(5, 25), Pair(-5, 9), Pair(-2, 1), Pair(-10, 0), Pair(-1, 8), Pair(9, -26),
        Pair(-14, 9), Pair(-6, 48), Pair(1, 13), Pair(-10, 10), Pair(13, 15), Pair(-2, 15), Pair(-5, 7), Pair(-13, 23)
      },
      { // Piece 3
        Pair(-10, 31), Pair(-27, 34), Pair(-9, 39), Pair(-52, 54), Pair(-10, 25), Pair(-30, 44), Pair(21, 14), Pair(13, 17),
        Pair(-4, 17), Pair(11, 37), Pair(23, 14), Pair(-14, 42), Pair(15, 27), Pair(-35, 45), Pair(37, 34), Pair(51, 10),
        Pair(0, 30), Pair(-12, 24), Pair(-11, 36), Pair(27, 15), Pair(14, 21), Pair(55, 5), Pair(-17, 42), Pair(-1, 13),
        Pair(-4, 6), Pair(0, 3), Pair(9, 60), Pair(11, 20), Pair(-4, 6), Pair(18, 16), Pair(-22, 34), Pair(23, -5),
        Pair(10, -10), Pair(27, 2), Pair(-19, 11), Pair(22, 19), Pair(-9, 21), Pair(10, 0), Pair(-30, 13), Pair(23, 10),
        Pair(-19, 16), Pair(9, -26), Pair(-8, -2), Pair(1, 8), Pair(-3, 25), Pair(-5, -1), Pair(7, 25), Pair(13, 0),
        Pair(4, 19), Pair(-6, -9), Pair(-17, 26), Pair(-4, 1), Pair(-5, 12), Pair(4, 9), Pair(12, 6), Pair(32, -23),
        Pair(-5, 8), Pair(-6, 8), Pair(-10, 5), Pair(-1, 9), Pair(-1, 8), Pair(0, 20), Pair(16, 6), Pair(8, 12)
      },
      { // Piece 4
        Pair(15, 13), Pair(9, 35), Pair(43, 21), Pair(13, 63), Pair(86, -2), Pair(105, 15), Pair(-102, 84), Pair(12, 74),
        Pair(-19, 60), Pair(12, 37), Pair(21, 55), Pair(-2, 72), Pair(-17, 86), Pair(-16, 64), Pair(42, 35), Pair(14, 20),
        Pair(-2, 20), Pair(13, -8), Pair(-9, 73), Pair(17, 23), Pair(-6, 60), Pair(39, 42), Pair(-22, 40), Pair(31, 41),
        Pair(-30, 57), Pair(-17, 62), Pair(-17, 117), Pair(18, 50), Pair(27, 6), Pair(20, 57), Pair(23, 39), Pair(16, 55),
        Pair(3, 15), Pair(-29, 32), Pair(12, 39), Pair(21, 60), Pair(17, 14), Pair(20, 10), Pair(3, 53), Pair(25, 30),
        Pair(9, -7), Pair(-4, 8), Pair(2, 16), Pair(13, 10), Pair(4, 7), Pair(3, 23), Pair(9, 28), Pair(13, 3),
        Pair(-13, 57), Pair(4, 7), Pair(7, 12), Pair(3, 1), Pair(2, 15), Pair(8, 6), Pair(18, 25), Pair(27, 1),
        Pair(6, 1), Pair(-2, 20), Pair(3, 29), Pair(4, 6), Pair(7, 20), Pair(-26, 49), Pair(-1, 15), Pair(-9, 36)
      },
      { // Piece 5
        Pair(-13, -99), Pair(-2, -45), Pair(-19, -114), Pair(-5, -69), Pair(8, -94), Pair(80, -26), Pair(-12, -49), Pair(-66, -183),
        Pair(16, -91), Pair(-28, -50), Pair(-4, -28), Pair(-82, -43), Pair(-27, -21), Pair(97, -83), Pair(111, -45), Pair(-42, -14),
        Pair(-23, -25), Pair(106, -4), Pair(-3, -28), Pair(57, -16), Pair(77, -26), Pair(70, -16), Pair(-29, 16), Pair(-1, -21),
        Pair(-65, 0), Pair(63, -47), Pair(69, -26), Pair(119, -76), Pair(48, -1), Pair(54, -1), Pair(2, -9), Pair(-8, 3),
        Pair(-132, 27), Pair(-63, -7), Pair(-8, -77), Pair(-11, -17), Pair(-15, -12), Pair(41, -9), Pair(-5, 5), Pair(-43, 1),
        Pair(37, -8), Pair(29, -18), Pair(0, -43), Pair(22, -24), Pair(22, -12), Pair(0, 11), Pair(-22, 10), Pair(10, 1),
        Pair(-36, 33), Pair(-41, 22), Pair(-3, -6), Pair(-26, 17), Pair(-12, 7), Pair(1, 3), Pair(-3, 1), Pair(4, -7),
        Pair(-24, 47), Pair(-20, 12), Pair(-22, 10), Pair(15, 19), Pair(-7, 15), Pair(-6, 9), Pair(2, -3), Pair(6, -11)
      }
    }},
    {{ // Bucket 35
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-23, 26), Pair(8, 6), Pair(-5, 36), Pair(33, -14), Pair(-21, 14), Pair(14, -9), Pair(-26, 2), Pair(-37, 21),
        Pair(-9, 30), Pair(-7, 17), Pair(-14, 20), Pair(3, 8), Pair(15, 24), Pair(41, -1), Pair(-5, -6), Pair(-11, 11),
        Pair(-4, 2), Pair(-6, 6), Pair(-7, 6), Pair(2, 4), Pair(8, 2), Pair(7, -3), Pair(4, 3), Pair(8, 9),
        Pair(-2, -1), Pair(5, -4), Pair(0, -3), Pair(1, -2), Pair(-6, -1), Pair(-5, 5), Pair(5, 0), Pair(1, 1),
        Pair(-1, 0), Pair(-2, -3), Pair(1, -5), Pair(9, 9), Pair(-2, -2), Pair(-4, 0), Pair(0, -1), Pair(1, 0),
        Pair(-2, 3), Pair(-1, 1), Pair(-3, -8), Pair(6, 8), Pair(-3, -16), Pair(-3, 1), Pair(0, -2), Pair(1, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-24, 27), Pair(-39, 56), Pair(-62, 46), Pair(8, 29), Pair(-14, -1), Pair(-4, 54), Pair(-44, 22), Pair(-40, 15),
        Pair(11, 2), Pair(0, 19), Pair(-34, 38), Pair(-38, 49), Pair(34, 42), Pair(-10, 24), Pair(24, -20), Pair(-70, 35),
        Pair(54, -1), Pair(-18, 11), Pair(-4, 19), Pair(-7, 25), Pair(-9, 47), Pair(5, 4), Pair(38, -2), Pair(-40, 46),
        Pair(-5, 18), Pair(-1, 11), Pair(-12, 35), Pair(-2, 2), Pair(3, 36), Pair(1, 12), Pair(7, 14), Pair(-9, 35),
        Pair(1, 13), Pair(-11, 32), Pair(-2, 28), Pair(21, 54), Pair(-6, 35), Pair(1, 37), Pair(8, 22), Pair(10, 27),
        Pair(-2, -11), Pair(-16, 30), Pair(1, 5), Pair(7, 46), Pair(-3, 15), Pair(5, 25), Pair(1, 15), Pair(5, 38),
        Pair(-6, -20), Pair(-23, 58), Pair(12, 15), Pair(-2, 3), Pair(4, 12), Pair(3, 18), Pair(22, -5), Pair(7, 13),
        Pair(-55, 54), Pair(-3, -7), Pair(-24, 42), Pair(-29, -3), Pair(-6, 26), Pair(-18, 30), Pair(5, 56), Pair(16, 98)
      },
      { // Piece 2
        Pair(14, 77), Pair(-77, 7), Pair(28, 29), Pair(-13, 29), Pair(-129, 59), Pair(54, 22), Pair(-101, 69), Pair(-6, 25),
        Pair(35, -11), Pair(-4, 28), Pair(1, 21), Pair(-38, 34), Pair(-34, 29), Pair(-13, 33), Pair(22, 35), Pair(-13, 40),
        Pair(-21, 34), Pair(-42, 37), Pair(-48, 37), Pair(-9, 24), Pair(20, 3), Pair(-34, 27), Pair(11, 39), Pair(6, 21),
        Pair(-15, 16), Pair(-8, 29), Pair(9, 6), Pair(-3, 37), Pair(-3, 22), Pair(10, 16), Pair(14, 19), Pair(-9, 33),
        Pair(-2, -5), Pair(-21, 18), Pair(-9, 41), Pair(11, 56), Pair(-11, 21), Pair(5, 10), Pair(2, 38), Pair(5, 29),
        Pair(-12, 14), Pair(-18, 18), Pair(-14, -2), Pair(2, 39), Pair(-4, -1), Pair(-3, 17), Pair(-1, -1), Pair(3, 10),
        Pair(-5, 36), Pair(-15, -21), Pair(-7, 18), Pair(-2, 10), Pair(0, 7), Pair(-3, 3), Pair(-4, 3), Pair(3, -17),
        Pair(-14, -31), Pair(-18, 57), Pair(-1, 2), Pair(10, 4), Pair(7, 3), Pair(4, 0), Pair(-18, 21), Pair(-19, -13)
      },
      { // Piece 3
        Pair(-2, 19), Pair(10, 20), Pair(9, 12), Pair(-19, 27), Pair(15, -6), Pair(-27, 33), Pair(-44, 14), Pair(19, 11),
        Pair(-1, 19), Pair(-9, 15), Pair(6, 22), Pair(1, 19), Pair(0, 19), Pair(36, 12), Pair(74, -6), Pair(29, 2),
        Pair(-11, 29), Pair(7, 17), Pair(-12, 17), Pair(2, 9), Pair(11, 11), Pair(37, 2), Pair(19, 3), Pair(10, 24),
        Pair(7, -4), Pair(4, -2), Pair(6, 3), Pair(19, 22), Pair(3, 5), Pair(-23, 44), Pair(-14, 27), Pair(4, 14),
        Pair(-23, 18), Pair(5, 19), Pair(8, -1), Pair(21, -4), Pair(6, 1), Pair(-14, 24), Pair(6, -7), Pair(15, 7),
        Pair(-17, 18), Pair(-10, 11), Pair(-4, -4), Pair(-19, 20), Pair(-6, 24), Pair(-10, 12), Pair(8, 7), Pair(5, 14),
        Pair(18, -9), Pair(2, 15), Pair(-7, 18), Pair(-29, 9), Pair(8, -3), Pair(3, 17), Pair(32, 9), Pair(1, -11),
        Pair(-3, 9), Pair(-2, 9), Pair(-3, 13), Pair(-11, 0), Pair(-2, 12), Pair(1, 10), Pair(4, 5), Pair(11, 4)
      },
      { // Piece 4
        Pair(32, -17), Pair(34, 5), Pair(35, 13), Pair(-50, 50), Pair(8, 33), Pair(76, 53), Pair(4, 43), Pair(-55, 43),
        Pair(-7, 34), Pair(8, -11), Pair(-9, 79), Pair(-1, 92), Pair(-4, 86), Pair(15, 73), Pair(-32, 86), Pair(37, 34),
        Pair(17, 40), Pair(-22, 60), Pair(-28, 36), Pair(26, 49), Pair(-29, 80), Pair(-22, 113), Pair(8, 20), Pair(25, 23),
        Pair(-6, 27), Pair(1, 28), Pair(4, 0), Pair(2, 12), Pair(-12, 42), Pair(7, 51), Pair(-2, 80), Pair(0, 80),
        Pair(-3, 47), Pair(-2, 42), Pair(0, 15), Pair(17, 31), Pair(8, 32), Pair(8, 22), Pair(3, 64), Pair(11, 60),
        Pair(2, 37), Pair(-2, 6), Pair(-13, 12), Pair(0, 23), Pair(7, 24), Pair(2, 15), Pair(1, 57), Pair(7, 14),
        Pair(-12, 35), Pair(-6, 26), Pair(-1, -7), Pair(2, 25), Pair(-1, 12), Pair(4, 44), Pair(-2, 28), Pair(21, -29),
        Pair(-13, -17), Pair(0, -4), Pair(-5, 19), Pair(7, 19), Pair(3, 23), Pair(16, 29), Pair(35, 18), Pair(-11, 58)
      },
      { // Piece 5
        Pair(36, 49), Pair(-14, 39), Pair(-13, -77), Pair(2, -44), Pair(30, 3), Pair(48, -96), Pair(4, 6), Pair(61, -50),
        Pair(-1, 19), Pair(20, -38), Pair(46, -56), Pair(20, -34), Pair(49, 1), Pair(-83, -13), Pair(37, -28), Pair(-92, 27),
        Pair(-22, -28), Pair(-18, -15), Pair(102, -99), Pair(78, -61), Pair(36, -44), Pair(76, -16), Pair(-2, 14), Pair(77, 0),
        Pair(-1, -3), Pair(30, 10), Pair(127, -92), Pair(114, -37), Pair(73, -56), Pair(10, 16), Pair(-56, 28), Pair(31, 18),
        Pair(-33, 25), Pair(-23, 31), Pair(-26, -56), Pair(6, -73), Pair(53, -46), Pair(-5, 4), Pair(38, -9), Pair(12, 8),
        Pair(-34, -4), Pair(-63, 18), Pair(25, -15), Pair(5, -42), Pair(46, -31), Pair(-20, 5), Pair(0, 10), Pair(14, 15),
        Pair(9, 14), Pair(-38, 24), Pair(-8, 18), Pair(-15, 5), Pair(-16, 14), Pair(-5, 9), Pair(9, 3), Pair(9, 0),
        Pair(-14, 40), Pair(-15, 24), Pair(-11, 13), Pair(-35, 5), Pair(-6, 21), Pair(0, 11), Pair(1, 10), Pair(3, 5)
      }
    }},
    {{ // Bucket 36
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-19, 44), Pair(21, -7), Pair(-21, 20), Pair(12, -6), Pair(61, 18), Pair(28, 39), Pair(4, 30), Pair(52, -23),
        Pair(1, 4), Pair(-23, 24), Pair(-5, 17), Pair(-25, 11), Pair(-2, -21), Pair(21, -8), Pair(-15, 18), Pair(-8, 24),
        Pair(-2, 0), Pair(-4, 2), Pair(0, 3), Pair(4, -7), Pair(-3, -2), Pair(3, 7), Pair(4, -1), Pair(-3, 4),
        Pair(2, -4), Pair(-1, -8), Pair(2, -5), Pair(-6, -2), Pair(0, -1), Pair(0, 3), Pair(5, -3), Pair(7, 1),
        Pair(1, -3), Pair(1, -6), Pair(0, -4), Pair(0, 0), Pair(6, 4), Pair(-1, -5), Pair(3, 1), Pair(3, 0),
        Pair(0, -2), Pair(0, -1), Pair(3, -2), Pair(-2, -12), Pair(10, -10), Pair(-5, -6), Pair(4, 0), Pair(5, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-29, -37), Pair(18, 42), Pair(-11, 18), Pair(30, 33), Pair(3, 7), Pair(-36, 42), Pair(-97, 13), Pair(-45, 2),
        Pair(-2, 17), Pair(-2, 24), Pair(-3, 16), Pair(-26, 40), Pair(-36, 34), Pair(-72, 39), Pair(-18, 11), Pair(-10, 34),
        Pair(-13, 36), Pair(-1, 46), Pair(-11, 18), Pair(-14, 34), Pair(-13, 29), Pair(-15, 26), Pair(-12, 16), Pair(-26, 48),
        Pair(-5, 21), Pair(-8, 26), Pair(5, 36), Pair(-5, 29), Pair(0, 46), Pair(-4, 24), Pair(-4, 15), Pair(-1, 5),
        Pair(4, 15), Pair(16, 12), Pair(8, 30), Pair(0, 28), Pair(22, 54), Pair(-10, 46), Pair(7, 22), Pair(-5, 4),
        Pair(3, -8), Pair(-7, 15), Pair(3, 18), Pair(2, 18), Pair(6, 52), Pair(-2, 9), Pair(5, 21), Pair(4, -25),
        Pair(-8, 10), Pair(-31, 14), Pair(-5, 11), Pair(1, 18), Pair(-1, 13), Pair(2, 28), Pair(-14, 22), Pair(0, -5),
        Pair(-13, -12), Pair(3, 39), Pair(-3, -5), Pair(24, 13), Pair(-9, 1), Pair(5, 15), Pair(-4, -25), Pair(73, -91)
      },
      { // Piece 2
        Pair(-50, 12), Pair(-13, 31), Pair(-88, 68), Pair(-6, 37), Pair(-91, 23), Pair(-64, 12), Pair(36, -3), Pair(-35, 7),
        Pair(-1, -3), Pair(-27, 31), Pair(-9, -10), Pair(51, 21), Pair(-21, 41), Pair(17, 8), Pair(50, 20), Pair(35, 33),
        Pair(-5, 35), Pair(-8, 35), Pair(-43, 46), Pair(-32, 28), Pair(-1, 34), Pair(-15, 29), Pair(7, 38), Pair(-4, 22),
        Pair(-8, 20), Pair(0, 36), Pair(-8, 39), Pair(-12, 15), Pair(10, 11), Pair(9, 29), Pair(-4, 31), Pair(1, 2),
        Pair(-3, 13), Pair(-2, 15), Pair(-6, 20), Pair(-3, 39), Pair(14, 55), Pair(7, 44), Pair(-7, 33), Pair(6, 17),
        Pair(5, -1), Pair(6, 7), Pair(-2, 13), Pair(-4, 9), Pair(1, 38), Pair(-6, -4), Pair(-5, 29), Pair(4, 0),
        Pair(-2, 17), Pair(-3, 6), Pair(-1, 4), Pair(3, 6), Pair(6, 10), Pair(-7, 28), Pair(-10, -16), Pair(6, -45),
        Pair(-10, 6), Pair(-19, 16), Pair(6, 7), Pair(5, 11), Pair(-26, 25), Pair(3, 13), Pair(12, 37), Pair(-13, -65)
      },
      { // Piece 3
        Pair(5, 9), Pair(-6, 15), Pair(0, 20), Pair(31, -4), Pair(-14, 6), Pair(-13, 15), Pair(45, 1), Pair(-15, 24),
        Pair(-10, 24), Pair(-5, 19), Pair(-12, 29), Pair(-27, 22), Pair(-10, 22), Pair(-27, 30), Pair(49, 2), Pair(-4, 6),
        Pair(7, 10), Pair(20, 11), Pair(-8, 24), Pair(3, 20), Pair(51, 0), Pair(-7, 30), Pair(-13, 35), Pair(-41, 25),
        Pair(-10, 19), Pair(10, 13), Pair(-7, 28), Pair(18, 1), Pair(14, 19), Pair(31, -10), Pair(2, 25), Pair(33, -4),
        Pair(11, 11), Pair(4, 0), Pair(1, 14), Pair(31, 7), Pair(-8, 16), Pair(-21, -11), Pair(5, -4), Pair(-4, 17),
        Pair(-1, 7), Pair(-6, 13), Pair(8, 6), Pair(1, 17), Pair(-13, 8), Pair(-15, 13), Pair(-18, 25), Pair(23, -4),
        Pair(-13, 30), Pair(12, 0), Pair(1, 9), Pair(-9, 13), Pair(-22, 7), Pair(-6, 6), Pair(3, 4), Pair(44, -26),
        Pair(6, 10), Pair(-2, 13), Pair(1, 17), Pair(-5, 14), Pair(-6, -5), Pair(-2, 15), Pair(19, 6), Pair(4, 17)
      },
      { // Piece 4
        Pair(-6, 34), Pair(0, 39), Pair(-54, 68), Pair(-42, 75), Pair(37, 37), Pair(-32, 94), Pair(23, 5), Pair(-16, 35),
        Pair(1, 72), Pair(-3, 52), Pair(16, 36), Pair(26, 7), Pair(-13, 61), Pair(2, 31), Pair(-26, 78), Pair(4, 65),
        Pair(-19, 68), Pair(10, 21), Pair(6, 26), Pair(-2, 35), Pair(44, 36), Pair(-10, 106), Pair(2, 76), Pair(-10, 58),
        Pair(19, -8), Pair(14, 23), Pair(-28, 52), Pair(22, 12), Pair(-28, 66), Pair(-11, 6), Pair(8, 29), Pair(4, 37),
        Pair(1, 32), Pair(2, 22), Pair(4, 22), Pair(4, 47), Pair(25, 6), Pair(-1, 45), Pair(16, 29), Pair(20, 1),
        Pair(3, 16), Pair(4, 8), Pair(-8, 28), Pair(-8, 26), Pair(-10, 44), Pair(-2, 25), Pair(-2, 19), Pair(-18, 70),
        Pair(5, -26), Pair(-2, 17), Pair(-1, 11), Pair(-5, 26), Pair(7, 11), Pair(-3, 64), Pair(-3, 15), Pair(6, 73),
        Pair(11, 9), Pair(-1, 19), Pair(1, -7), Pair(1, 8), Pair(11, 27), Pair(19, -38), Pair(8, 39), Pair(-14, 21)
      },
      { // Piece 5
        Pair(-40, 7), Pair(-89, -69), Pair(107, 26), Pair(11, 28), Pair(7, -48), Pair(-20, 8), Pair(-27, 18), Pair(20, 10),
        Pair(-28, -17), Pair(54, -70), Pair(-23, -3), Pair(17, 9), Pair(29, -30), Pair(-78, -48), Pair(-45, 4), Pair(-17, -29),
        Pair(9, 12), Pair(-18, 36), Pair(59, -2), Pair(99, -29), Pair(97, -42), Pair(128, -35), Pair(-14, 2), Pair(-80, 23),
        Pair(-35, 26), Pair(76, -11), Pair(62, -19), Pair(49, -78), Pair(79, -11), Pair(118, -65), Pair(33, 0), Pair(47, -5),
        Pair(-43, 36), Pair(76, 4), Pair(-10, 6), Pair(-22, -65), Pair(-11, -59), Pair(76, -57), Pair(-48, 15), Pair(9, 13),
        Pair(52, -15), Pair(17, 4), Pair(31, -18), Pair(54, -21), Pair(8, -38), Pair(12, -15), Pair(-17, 14), Pair(-1, 17),
        Pair(9, 12), Pair(28, 1), Pair(-1, 14), Pair(55, -3), Pair(-7, -2), Pair(15, 8), Pair(-9, 14), Pair(0, 18),
        Pair(-4, 43), Pair(-4, 21), Pair(-1, 14), Pair(10, 28), Pair(-9, 11), Pair(8, 21), Pair(-3, 19), Pair(4, 22)
      }
    }},
    {{ // Bucket 37
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-41, 22), Pair(20, 10), Pair(-25, 40), Pair(35, -4), Pair(-34, 34), Pair(-9, 57), Pair(-10, 5), Pair(-62, 28),
        Pair(-9, 17), Pair(-7, 13), Pair(18, -5), Pair(13, 3), Pair(7, -10), Pair(-28, -31), Pair(10, 17), Pair(-1, 16),
        Pair(0, -5), Pair(1, 0), Pair(-3, 5), Pair(-3, 1), Pair(7, -6), Pair(-7, 11), Pair(-2, 2), Pair(0, -1),
        Pair(2, -3), Pair(4, -1), Pair(4, -3), Pair(1, -2), Pair(2, -2), Pair(1, -1), Pair(4, -10), Pair(-4, 0),
        Pair(2, -4), Pair(1, -6), Pair(-1, -1), Pair(1, -6), Pair(2, 0), Pair(10, 3), Pair(-3, -4), Pair(4, -3),
        Pair(1, -2), Pair(0, -2), Pair(1, -4), Pair(2, -3), Pair(-2, -5), Pair(4, 3), Pair(-3, -7), Pair(0, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(9, 26), Pair(84, -41), Pair(-29, 6), Pair(78, 13), Pair(120, -54), Pair(-7, 41), Pair(-1, 40), Pair(-23, -5),
        Pair(0, 15), Pair(21, -6), Pair(-10, 30), Pair(-36, 17), Pair(26, -1), Pair(78, -15), Pair(-25, -18), Pair(-7, 17),
        Pair(13, 31), Pair(8, 2), Pair(24, 5), Pair(21, -1), Pair(-16, 16), Pair(14, 25), Pair(27, 24), Pair(4, -30),
        Pair(5, 0), Pair(1, 16), Pair(-5, 18), Pair(1, 19), Pair(9, 26), Pair(-4, 28), Pair(6, 21), Pair(-17, 9),
        Pair(-3, 8), Pair(-9, 23), Pair(2, 3), Pair(17, 8), Pair(-4, 21), Pair(16, 37), Pair(-30, 34), Pair(1, 19),
        Pair(5, 4), Pair(-3, 11), Pair(2, 11), Pair(2, 15), Pair(10, 4), Pair(7, 28), Pair(-7, -10), Pair(4, -6),
        Pair(-18, -16), Pair(-17, 1), Pair(7, 17), Pair(-3, 12), Pair(-3, 20), Pair(-13, 5), Pair(-17, -1), Pair(-27, -13),
        Pair(-59, -27), Pair(5, 7), Pair(-30, 12), Pair(-38, 29), Pair(-8, -3), Pair(-23, 30), Pair(-11, 36), Pair(-42, -7)
      },
      { // Piece 2
        Pair(-51, 43), Pair(105, 24), Pair(-8, 23), Pair(-38, 22), Pair(-94, 61), Pair(-80, 20), Pair(-99, 25), Pair(-16, 44),
        Pair(-9, 3), Pair(-17, 26), Pair(-22, 35), Pair(-40, 20), Pair(-7, 15), Pair(-20, 40), Pair(-2, 14), Pair(-36, 61),
        Pair(8, 23), Pair(-19, 31), Pair(-13, 19), Pair(28, 8), Pair(-11, 14), Pair(-4, 25), Pair(-9, 19), Pair(3, 20),
        Pair(-9, 12), Pair(17, 15), Pair(-16, 18), Pair(-3, 15), Pair(10, 15), Pair(-5, 48), Pair(0, 22), Pair(0, 18),
        Pair(-9, 1), Pair(16, -3), Pair(-6, 14), Pair(-13, 21), Pair(2, 9), Pair(13, 28), Pair(16, 37), Pair(-20, 6),
        Pair(8, 9), Pair(3, 11), Pair(0, 17), Pair(0, 6), Pair(-10, 9), Pair(7, 27), Pair(-19, -13), Pair(-21, -1),
        Pair(-8, 27), Pair(-2, 4), Pair(-4, 17), Pair(-1, -2), Pair(5, 4), Pair(5, 19), Pair(-1, -1), Pair(-23, -83),
        Pair(-25, 17), Pair(-33, 47), Pair(-4, 2), Pair(-24, 16), Pair(-14, 7), Pair(9, 2), Pair(-31, -9), Pair(10, -2)
      },
      { // Piece 3
        Pair(0, 17), Pair(-25, 30), Pair(-17, 20), Pair(56, 0), Pair(3, 23), Pair(-19, 21), Pair(-40, 22), Pair(-28, 24),
        Pair(-11, 12), Pair(6, 1), Pair(12, 6), Pair(-11, 23), Pair(-1, 13), Pair(9, -5), Pair(51, 5), Pair(59, -15),
        Pair(6, 8), Pair(24, 12), Pair(11, -8), Pair(13, 6), Pair(-19, 10), Pair(-8, 44), Pair(5, 18), Pair(4, 15),
        Pair(-5, 1), Pair(7, -4), Pair(1, 7), Pair(7, 15), Pair(-3, 0), Pair(16, -31), Pair(-2, 3), Pair(-14, 3),
        Pair(6, -16), Pair(-16, 3), Pair(9, -8), Pair(-15, 5), Pair(8, -16), Pair(0, 5), Pair(32, -34), Pair(-10, 8),
        Pair(-4, 19), Pair(-19, 23), Pair(-20, 25), Pair(12, -4), Pair(-10, 13), Pair(19, -19), Pair(-13, 4), Pair(-12, 15),
        Pair(-5, 12), Pair(6, 5), Pair(1, -5), Pair(-14, 12), Pair(1, -3), Pair(0, -19), Pair(-9, -2), Pair(55, -25),
        Pair(0, 9), Pair(-4, 17), Pair(1, 5), Pair(-3, 7), Pair(1, 4), Pair(-5, 5), Pair(-12, 17), Pair(-13, 11)
      },
      { // Piece 4
        Pair(13, -11), Pair(-31, 19), Pair(-43, 13), Pair(-21, 23), Pair(31, -4), Pair(13, 0), Pair(21, -8), Pair(-21, 43),
        Pair(-13, 17), Pair(-5, 11), Pair(-26, 15), Pair(-4, 56), Pair(0, 59), Pair(6, 57), Pair(-53, 65), Pair(27, 66),
        Pair(-14, 39), Pair(2, -5), Pair(8, 46), Pair(14, -8), Pair(5, -5), Pair(74, -15), Pair(39, -54), Pair(-4, 63),
        Pair(2, 20), Pair(-3, 35), Pair(13, -2), Pair(16, 20), Pair(6, 31), Pair(-9, 89), Pair(-3, 29), Pair(-4, -9),
        Pair(-3, -7), Pair(-18, 25), Pair(-1, 29), Pair(4, 7), Pair(-7, 25), Pair(30, -15), Pair(-38, 43), Pair(-1, 44),
        Pair(-13, 54), Pair(-7, 36), Pair(-3, 14), Pair(-1, 17), Pair(-7, 4), Pair(6, 9), Pair(-9, -5), Pair(4, -46),
        Pair(-17, 2), Pair(1, 8), Pair(0, 12), Pair(1, 5), Pair(2, 12), Pair(-6, -14), Pair(-6, 23), Pair(-5, 21),
        Pair(1, 1), Pair(-30, 33), Pair(10, -25), Pair(2, 4), Pair(9, -5), Pair(-3, 3), Pair(-53, -6), Pair(-1, 36)
      },
      { // Piece 5
        Pair(-16, -49), Pair(85, -122), Pair(-46, -73), Pair(43, -104), Pair(19, -11), Pair(-79, -77), Pair(-34, -22), Pair(-11, -23),
        Pair(-102, -24), Pair(-34, -26), Pair(86, -53), Pair(58, -133), Pair(-58, -39), Pair(25, -33), Pair(24, -29), Pair(-99, -39),
        Pair(9, 1), Pair(79, -42), Pair(-46, 18), Pair(52, -28), Pair(-42, -33), Pair(141, -45), Pair(64, -18), Pair(49, -26),
        Pair(-85, 37), Pair(-73, 3), Pair(59, -18), Pair(-108, 3), Pair(47, -57), Pair(-28, 4), Pair(101, -67), Pair(-13, -4),
        Pair(113, -27), Pair(-1, -10), Pair(51, -24), Pair(31, -10), Pair(7, -60), Pair(-33, -51), Pair(-24, -36), Pair(19, -13),
        Pair(-28, 12), Pair(71, -25), Pair(20, 0), Pair(30, -8), Pair(2, -9), Pair(30, -23), Pair(-9, -12), Pair(-39, 4),
        Pair(20, -19), Pair(-7, 6), Pair(12, -7), Pair(8, 11), Pair(-14, 19), Pair(1, 3), Pair(-2, 17), Pair(-3, 7),
        Pair(-36, 1), Pair(-4, 2), Pair(-3, -9), Pair(-23, 11), Pair(-5, 15), Pair(3, 11), Pair(-1, 16), Pair(2, 5)
      }
    }},
    {{ // Bucket 38
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-10, 37), Pair(59, 25), Pair(9, 7), Pair(12, 17), Pair(-54, 33), Pair(38, -18), Pair(-86, 54), Pair(-82, 62),
        Pair(9, 8), Pair(5, 6), Pair(18, -5), Pair(33, 5), Pair(4, 23), Pair(5, -11), Pair(12, 35), Pair(2, -16),
        Pair(1, 7), Pair(10, -8), Pair(-9, 9), Pair(4, 2), Pair(6, 0), Pair(-2, -5), Pair(15, -34), Pair(-5, -4),
        Pair(-2, 0), Pair(0, -3), Pair(-3, 1), Pair(-4, 2), Pair(-3, -2), Pair(5, 7), Pair(3, 0), Pair(6, 9),
        Pair(0, -3), Pair(-3, -2), Pair(-7, 4), Pair(-6, -4), Pair(2, -4), Pair(2, 5), Pair(-2, 7), Pair(1, 5),
        Pair(2, -5), Pair(-1, -2), Pair(-6, -5), Pair(-16, -7), Pair(0, 5), Pair(4, 1), Pair(1, 5), Pair(-1, 6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-37, 9), Pair(20, 1), Pair(-83, 47), Pair(-7, -17), Pair(59, 16), Pair(-28, 6), Pair(86, -46), Pair(21, -54),
        Pair(49, -21), Pair(35, -3), Pair(0, -6), Pair(-26, 22), Pair(109, 3), Pair(58, 3), Pair(-59, 33), Pair(31, 4),
        Pair(-51, 48), Pair(14, 28), Pair(21, 10), Pair(47, 6), Pair(62, -16), Pair(18, 18), Pair(26, -51), Pair(20, 24),
        Pair(-21, 17), Pair(22, 1), Pair(6, 9), Pair(2, 19), Pair(38, 4), Pair(11, 24), Pair(8, 17), Pair(5, 18),
        Pair(13, -8), Pair(-30, 26), Pair(24, -4), Pair(14, 10), Pair(35, -4), Pair(-3, 40), Pair(6, 59), Pair(-17, 33),
        Pair(-17, 11), Pair(9, -3), Pair(3, 15), Pair(11, 12), Pair(6, 14), Pair(6, 22), Pair(30, 28), Pair(-28, 23),
        Pair(-20, 12), Pair(-40, 47), Pair(-5, 3), Pair(2, 7), Pair(1, 14), Pair(-17, 5), Pair(7, -6), Pair(-5, 22),
        Pair(-79, -34), Pair(-7, 14), Pair(-30, -14), Pair(3, 30), Pair(13, -3), Pair(-5, 35), Pair(-26, -19), Pair(-37, -24)
      },
      { // Piece 2
        Pair(-63, 31), Pair(-19, 63), Pair(-150, 47), Pair(-14, 45), Pair(-30, 33), Pair(-13, 51), Pair(69, -4), Pair(-10, 80),
        Pair(-42, 37), Pair(16, 32), Pair(-16, 27), Pair(-62, 67), Pair(37, 15), Pair(16, 21), Pair(34, 23), Pair(-3, 58),
        Pair(-23, 22), Pair(1, 27), Pair(-7, 37), Pair(-12, 50), Pair(-5, 29), Pair(20, -2), Pair(-20, 28), Pair(18, -19),
        Pair(7, 22), Pair(4, 12), Pair(-31, 29), Pair(-5, 38), Pair(21, 20), Pair(23, 14), Pair(-15, 46), Pair(-7, 5),
        Pair(11, 4), Pair(1, 3), Pair(9, 12), Pair(19, 15), Pair(-11, 17), Pair(-5, 25), Pair(12, 43), Pair(-50, 63),
        Pair(-19, 15), Pair(6, 22), Pair(-10, 14), Pair(-3, 10), Pair(-1, 18), Pair(-9, 15), Pair(-9, 48), Pair(-6, 11),
        Pair(-5, 36), Pair(-2, 6), Pair(15, 14), Pair(0, 16), Pair(-7, 18), Pair(-14, 32), Pair(14, 3), Pair(0, 12),
        Pair(27, 5), Pair(2, -7), Pair(-13, 13), Pair(10, 6), Pair(-6, 18), Pair(9, 9), Pair(21, 23), Pair(4, 9)
      },
      { // Piece 3
        Pair(-16, 15), Pair(-26, 21), Pair(-15, 28), Pair(-5, 20), Pair(-25, 22), Pair(-73, 55), Pair(-48, 39), Pair(-20, 56),
        Pair(-10, 11), Pair(17, 14), Pair(16, 13), Pair(20, -1), Pair(47, -1), Pair(12, 8), Pair(131, -15), Pair(51, 3),
        Pair(18, 6), Pair(1, -3), Pair(15, 3), Pair(11, 2), Pair(43, 8), Pair(-33, 32), Pair(23, 11), Pair(1, 8),
        Pair(9, 2), Pair(21, 6), Pair(7, 8), Pair(7, 13), Pair(12, 19), Pair(23, 4), Pair(-45, 49), Pair(-20, 5),
        Pair(9, 2), Pair(-27, 11), Pair(-48, 27), Pair(-4, 19), Pair(11, -2), Pair(42, -20), Pair(-40, 2), Pair(-34, -2),
        Pair(4, 6), Pair(8, 7), Pair(-13, 11), Pair(-2, 6), Pair(-6, 31), Pair(8, 21), Pair(31, -26), Pair(-26, 22),
        Pair(5, 3), Pair(13, 0), Pair(-6, 10), Pair(3, 6), Pair(2, 10), Pair(13, -16), Pair(-17, 22), Pair(11, -5),
        Pair(3, 15), Pair(5, 16), Pair(6, 15), Pair(9, 6), Pair(5, 6), Pair(4, -1), Pair(-30, 29), Pair(-2, 2)
      },
      { // Piece 4
        Pair(13, 11), Pair(-11, 6), Pair(-34, 8), Pair(8, -44), Pair(4, 32), Pair(66, 2), Pair(-6, 75), Pair(-7, 80),
        Pair(28, -30), Pair(10, -9), Pair(-2, 1), Pair(42, 8), Pair(19, 12), Pair(0, 2), Pair(28, 44), Pair(46, 40),
        Pair(-31, 33), Pair(0, 12), Pair(26, -3), Pair(20, -17), Pair(-1, 60), Pair(11, 1), Pair(-31, 78), Pair(-12, 10),
        Pair(4, -6), Pair(3, -18), Pair(6, 17), Pair(-28, 71), Pair(-13, 59), Pair(-13, 38), Pair(2, 35), Pair(-20, -1),
        Pair(5, -12), Pair(-4, -10), Pair(22, -11), Pair(8, 11), Pair(3, 10), Pair(23, 37), Pair(-1, -48), Pair(-28, 58),
        Pair(-12, 69), Pair(9, -3), Pair(4, 30), Pair(5, 0), Pair(-6, -17), Pair(-4, -3), Pair(-10, 42), Pair(13, -5),
        Pair(6, 21), Pair(5, -8), Pair(7, -24), Pair(7, -25), Pair(3, -10), Pair(16, -9), Pair(-38, 54), Pair(-22, -31),
        Pair(-25, 83), Pair(-2, -62), Pair(7, -8), Pair(11, -11), Pair(29, -36), Pair(0, -10), Pair(-65, 0), Pair(-2, 81)
      },
      { // Piece 5
        Pair(-11, -61), Pair(17, -56), Pair(4, -60), Pair(73, -65), Pair(37, -33), Pair(-4, -1), Pair(-46, -79), Pair(-9, -148),
        Pair(-65, -26), Pair(7, -48), Pair(86, -60), Pair(70, -75), Pair(90, -92), Pair(80, -74), Pair(46, -94), Pair(10, -89),
        Pair(34, -24), Pair(105, -38), Pair(39, -49), Pair(-46, -26), Pair(31, -59), Pair(68, -33), Pair(158, -67), Pair(-40, -39),
        Pair(65, -9), Pair(33, 7), Pair(82, -45), Pair(-35, -11), Pair(-23, 5), Pair(53, -49), Pair(-35, -56), Pair(-15, -47),
        Pair(-12, -12), Pair(93, -56), Pair(52, -25), Pair(26, -7), Pair(1, -10), Pair(14, -29), Pair(-13, -77), Pair(-39, -40),
        Pair(1, -45), Pair(10, -28), Pair(60, -27), Pair(25, -16), Pair(6, -15), Pair(45, -24), Pair(23, -36), Pair(-48, -17),
        Pair(1, -7), Pair(4, -3), Pair(-14, -10), Pair(1, -8), Pair(4, -6), Pair(12, 5), Pair(0, -7), Pair(-8, 7),
        Pair(5, -40), Pair(-8, -32), Pair(-5, -9), Pair(-28, 9), Pair(-2, -9), Pair(-14, 22), Pair(-2, 8), Pair(2, 2)
      }
    }},
    {{ // Bucket 39
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(40, 16), Pair(32, 23), Pair(105, -36), Pair(26, 16), Pair(43, 4), Pair(-17, -1), Pair(26, -40), Pair(34, 8),
        Pair(21, 4), Pair(16, 9), Pair(27, 11), Pair(29, 8), Pair(-3, 10), Pair(-39, 16), Pair(19, 20), Pair(14, -40),
        Pair(4, -1), Pair(-1, 1), Pair(2, 3), Pair(2, 3), Pair(-4, -3), Pair(-4, -1), Pair(-4, -4), Pair(-17, -24),
        Pair(1, -3), Pair(3, -6), Pair(-1, -4), Pair(2, -2), Pair(6, 0), Pair(0, -1), Pair(8, -17), Pair(-3, 2),
        Pair(-1, -1), Pair(0, -5), Pair(1, -3), Pair(-2, -3), Pair(4, -4), Pair(-1, -1), Pair(-6, -5), Pair(4, 6),
        Pair(-1, 0), Pair(-2, -4), Pair(-5, -1), Pair(6, -10), Pair(-3, 3), Pair(2, -4), Pair(-2, -8), Pair(-2, 8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(19, -9), Pair(-63, 29), Pair(-25, -21), Pair(32, -15), Pair(-10, 1), Pair(15, 25), Pair(41, 3), Pair(-43, 30),
        Pair(4, -33), Pair(30, -30), Pair(-17, -2), Pair(30, -1), Pair(33, 22), Pair(6, 15), Pair(7, -30), Pair(11, 73),
        Pair(-7, -19), Pair(-11, -9), Pair(20, 2), Pair(43, -10), Pair(29, -12), Pair(64, -12), Pair(22, -2), Pair(24, 1),
        Pair(21, -3), Pair(9, -14), Pair(28, -6), Pair(24, -7), Pair(28, -2), Pair(9, 9), Pair(6, 12), Pair(-2, -26),
        Pair(9, -20), Pair(8, -14), Pair(5, -11), Pair(14, 7), Pair(18, -7), Pair(31, -4), Pair(31, 21), Pair(9, 42),
        Pair(-8, 9), Pair(-1, -4), Pair(6, 4), Pair(2, 10), Pair(-3, 5), Pair(9, 12), Pair(17, 6), Pair(20, 65),
        Pair(36, 17), Pair(-16, -5), Pair(-15, -8), Pair(6, -1), Pair(4, 10), Pair(-13, 16), Pair(10, 12), Pair(-5, -12),
        Pair(-21, -8), Pair(-6, -2), Pair(-1, -22), Pair(22, 9), Pair(-1, -7), Pair(2, 13), Pair(-12, 14), Pair(-82, -80)
      },
      { // Piece 2
        Pair(-43, 48), Pair(-35, 17), Pair(32, 30), Pair(-20, 40), Pair(-43, 37), Pair(5, 43), Pair(-68, 54), Pair(60, 0),
        Pair(-42, 32), Pair(15, 37), Pair(-48, 24), Pair(-39, 43), Pair(-10, 26), Pair(-16, 36), Pair(-23, 3), Pair(26, 27),
        Pair(-53, 40), Pair(-7, 3), Pair(-3, 37), Pair(-6, 38), Pair(23, 21), Pair(-9, 22), Pair(57, 10), Pair(53, 12),
        Pair(-22, 5), Pair(15, 14), Pair(-8, 25), Pair(31, 15), Pair(18, 12), Pair(-15, 24), Pair(7, 7), Pair(66, -20),
        Pair(-15, 7), Pair(-2, 13), Pair(2, 14), Pair(-3, -1), Pair(2, 15), Pair(9, 11), Pair(20, 12), Pair(5, 34),
        Pair(3, -2), Pair(3, 15), Pair(6, 19), Pair(-3, 24), Pair(8, 0), Pair(2, 22), Pair(11, 15), Pair(5, 46),
        Pair(2, 14), Pair(0, 6), Pair(-12, 16), Pair(-6, 3), Pair(0, 21), Pair(10, -4), Pair(8, 31), Pair(17, 7),
        Pair(17, -18), Pair(13, 27), Pair(-7, 16), Pair(-21, 17), Pair(-20, 25), Pair(-4, 30), Pair(22, 15), Pair(6, 48)
      },
      { // Piece 3
        Pair(42, -2), Pair(13, 20), Pair(-62, 37), Pair(24, 0), Pair(4, 5), Pair(-4, 29), Pair(-6, 29), Pair(95, 13),
        Pair(33, 7), Pair(9, 20), Pair(33, 5), Pair(-4, 18), Pair(12, 16), Pair(18, -9), Pair(81, -22), Pair(51, 19),
        Pair(-16, 11), Pair(8, 12), Pair(10, 15), Pair(28, 1), Pair(-5, 7), Pair(-19, 12), Pair(4, 23), Pair(90, -4),
        Pair(6, 6), Pair(-5, 11), Pair(-1, 14), Pair(12, -2), Pair(41, -11), Pair(13, 10), Pair(46, -5), Pair(78, 12),
        Pair(1, 2), Pair(-11, 8), Pair(17, 8), Pair(-8, 2), Pair(-19, 26), Pair(-5, 14), Pair(-13, 25), Pair(8, 23),
        Pair(-3, -3), Pair(10, 29), Pair(19, -2), Pair(-7, 21), Pair(25, 7), Pair(9, 23), Pair(16, 4), Pair(-29, 45),
        Pair(18, 13), Pair(-8, 8), Pair(8, 14), Pair(-2, 14), Pair(1, -3), Pair(14, 4), Pair(-29, 39), Pair(-55, 39),
        Pair(1, 12), Pair(-4, 8), Pair(2, 16), Pair(4, 13), Pair(-1, 17), Pair(2, 12), Pair(-5, 18), Pair(-6, 10)
      },
      { // Piece 4
        Pair(38, -2), Pair(0, 19), Pair(65, -34), Pair(5, -6), Pair(78, -52), Pair(106, -27), Pair(-23, 17), Pair(-4, -5),
        Pair(18, -29), Pair(-17, 28), Pair(-38, 31), Pair(-11, 18), Pair(18, 5), Pair(-19, 37), Pair(15, -52), Pair(-46, 90),
        Pair(-8, -14), Pair(13, -4), Pair(3, 3), Pair(10, -20), Pair(42, 12), Pair(25, -13), Pair(-23, 32), Pair(-7, 70),
        Pair(-2, 8), Pair(0, 15), Pair(-8, 17), Pair(-8, 47), Pair(12, 30), Pair(-9, 20), Pair(24, -31), Pair(1, -15),
        Pair(-27, 21), Pair(1, -7), Pair(5, -6), Pair(-3, 27), Pair(-5, 19), Pair(8, 1), Pair(-5, 6), Pair(2, -10),
        Pair(0, -4), Pair(3, -6), Pair(-3, 13), Pair(0, 10), Pair(-3, -5), Pair(5, 7), Pair(-7, 18), Pair(-20, -2),
        Pair(-18, 21), Pair(-5, 0), Pair(5, -4), Pair(-2, -1), Pair(-4, -6), Pair(11, -8), Pair(-25, 21), Pair(-22, 53),
        Pair(15, -21), Pair(4, -10), Pair(6, 23), Pair(2, -7), Pair(5, -14), Pair(-26, 28), Pair(1, 19), Pair(-84, 60)
      },
      { // Piece 5
        Pair(-21, -180), Pair(15, -91), Pair(50, -55), Pair(-39, -4), Pair(0, -56), Pair(29, -11), Pair(44, -49), Pair(-25, 7),
        Pair(67, -77), Pair(-31, -33), Pair(33, -35), Pair(63, -26), Pair(-27, -69), Pair(66, -52), Pair(-52, -65), Pair(-18, -82),
        Pair(-48, -10), Pair(141, -39), Pair(86, -30), Pair(35, -48), Pair(119, -28), Pair(149, -41), Pair(40, -32), Pair(145, -71),
        Pair(24, -26), Pair(85, -47), Pair(73, -32), Pair(24, -27), Pair(-11, -11), Pair(-24, -9), Pair(59, -52), Pair(99, -8),
        Pair(0, 11), Pair(27, -34), Pair(23, -30), Pair(64, -22), Pair(-4, -14), Pair(7, -16), Pair(20, -53), Pair(120, -108),
        Pair(18, -13), Pair(-9, -37), Pair(50, -33), Pair(-4, -10), Pair(-2, -8), Pair(-9, 0), Pair(9, 0), Pair(2, -35),
        Pair(24, -29), Pair(-2, -31), Pair(-11, -16), Pair(-22, -12), Pair(-1, -4), Pair(-27, 9), Pair(-9, 16), Pair(-4, 0),
        Pair(-55, 43), Pair(-12, -29), Pair(-17, -35), Pair(7, -10), Pair(-14, 2), Pair(-17, 10), Pair(8, 8), Pair(2, 2)
      }
    }},
    {{ // Bucket 40
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-6, -80), Pair(-13, 90), Pair(-7, 37), Pair(-1, 20), Pair(49, 19), Pair(126, -22), Pair(-11, 33), Pair(-47, 40),
        Pair(-72, -1), Pair(-33, 10), Pair(19, 2), Pair(10, -4), Pair(20, 10), Pair(16, 7), Pair(15, 29), Pair(-18, 31),
        Pair(-10, -10), Pair(6, -20), Pair(-1, -2), Pair(5, 0), Pair(7, 2), Pair(-6, 9), Pair(-1, 5), Pair(-8, 12),
        Pair(4, 7), Pair(-5, -2), Pair(1, 5), Pair(-2, -3), Pair(-3, -2), Pair(-2, 0), Pair(1, 0), Pair(-1, 0),
        Pair(-1, -1), Pair(-1, -2), Pair(-1, -1), Pair(0, -3), Pair(-1, -2), Pair(-4, -3), Pair(-1, -5), Pair(1, -3),
        Pair(3, -3), Pair(-3, -2), Pair(-1, 0), Pair(2, -11), Pair(0, -4), Pair(-2, -1), Pair(-2, -2), Pair(1, -1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-73, -1), Pair(4, -27), Pair(8, 10), Pair(111, -47), Pair(62, -51), Pair(33, -62), Pair(120, -37), Pair(40, -24),
        Pair(-23, -51), Pair(0, -9), Pair(10, -55), Pair(-5, 5), Pair(46, -9), Pair(29, -28), Pair(14, -6), Pair(-26, 2),
        Pair(-10, -23), Pair(18, -4), Pair(-13, 10), Pair(4, 14), Pair(4, -2), Pair(13, -4), Pair(62, -29), Pair(63, -3),
        Pair(24, 31), Pair(10, -53), Pair(9, 0), Pair(4, -1), Pair(8, -5), Pair(25, -15), Pair(12, -12), Pair(30, -31),
        Pair(12, 25), Pair(-35, 25), Pair(-2, 13), Pair(-1, 1), Pair(9, -9), Pair(15, -15), Pair(29, 13), Pair(1, 29),
        Pair(-15, -10), Pair(-3, -5), Pair(-6, 6), Pair(2, -22), Pair(9, -14), Pair(-1, 2), Pair(6, -10), Pair(12, 31),
        Pair(2, 49), Pair(13, -48), Pair(4, -1), Pair(5, 4), Pair(5, -2), Pair(10, -4), Pair(6, 1), Pair(5, 1),
        Pair(-24, 35), Pair(-3, -12), Pair(24, 18), Pair(0, -1), Pair(-10, -11), Pair(19, -35), Pair(-5, 55), Pair(-6, -24)
      },
      { // Piece 2
        Pair(-15, 22), Pair(-78, 55), Pair(28, 37), Pair(-1, 28), Pair(-23, 5), Pair(16, 16), Pair(-42, 22), Pair(-9, 34),
        Pair(35, 49), Pair(-5, 37), Pair(-8, 43), Pair(-7, 47), Pair(-19, 28), Pair(-47, 87), Pair(-20, 18), Pair(-17, 32),
        Pair(-108, 27), Pair(16, 8), Pair(-17, 30), Pair(3, 27), Pair(-35, 71), Pair(41, 28), Pair(-31, 45), Pair(20, 33),
        Pair(22, 40), Pair(2, 12), Pair(5, 19), Pair(-4, 39), Pair(11, 35), Pair(1, 26), Pair(11, 20), Pair(2, 28),
        Pair(4, 8), Pair(-8, 25), Pair(-8, 44), Pair(3, 20), Pair(15, 1), Pair(10, 5), Pair(-18, 46), Pair(3, 14),
        Pair(11, 33), Pair(3, 32), Pair(2, 20), Pair(4, 11), Pair(5, 18), Pair(-5, 9), Pair(-8, 2), Pair(-7, 32),
        Pair(-6, 84), Pair(5, 17), Pair(4, 10), Pair(4, 25), Pair(-2, 11), Pair(-7, 25), Pair(4, 9), Pair(2, -5),
        Pair(12, 38), Pair(1, 69), Pair(1, 18), Pair(4, 2), Pair(-9, 8), Pair(1, 17), Pair(-1, 26), Pair(14, -18)
      },
      { // Piece 3
        Pair(-25, 54), Pair(-22, 29), Pair(-14, 48), Pair(-58, 53), Pair(0, 8), Pair(-20, 39), Pair(47, 15), Pair(26, 10),
        Pair(12, 47), Pair(3, 28), Pair(-5, 40), Pair(3, 16), Pair(8, 38), Pair(55, 0), Pair(52, 12), Pair(-9, 43),
        Pair(13, 55), Pair(13, 24), Pair(25, 22), Pair(4, 35), Pair(6, 20), Pair(1, 22), Pair(42, -7), Pair(-32, 50),
        Pair(-9, 43), Pair(20, -4), Pair(3, 24), Pair(-1, 30), Pair(17, 23), Pair(-26, 33), Pair(10, 41), Pair(11, 2),
        Pair(-17, 15), Pair(1, 10), Pair(0, 8), Pair(0, 9), Pair(13, 10), Pair(7, 9), Pair(20, 5), Pair(8, 24),
        Pair(-12, -7), Pair(-7, 26), Pair(-19, 37), Pair(0, 10), Pair(-12, 23), Pair(10, 18), Pair(14, 26), Pair(13, 3),
        Pair(-16, 26), Pair(19, -1), Pair(6, 19), Pair(-8, 25), Pair(2, 23), Pair(5, 18), Pair(29, -3), Pair(62, 4),
        Pair(-2, 9), Pair(-5, 15), Pair(-3, 21), Pair(0, 15), Pair(0, 16), Pair(3, 16), Pair(10, 17), Pair(5, 14)
      },
      { // Piece 4
        Pair(16, 40), Pair(-3, 31), Pair(-36, 86), Pair(-56, 57), Pair(-1, 67), Pair(-8, 58), Pair(22, 75), Pair(26, 33),
        Pair(15, 9), Pair(-3, 41), Pair(1, 55), Pair(-4, 39), Pair(6, 60), Pair(4, 87), Pair(45, 32), Pair(64, 24),
        Pair(-30, 106), Pair(14, 46), Pair(-17, 58), Pair(-22, 74), Pair(6, 52), Pair(3, 22), Pair(81, -15), Pair(23, 35),
        Pair(34, 38), Pair(54, 11), Pair(25, 17), Pair(-8, 26), Pair(5, 46), Pair(37, 41), Pair(26, 21), Pair(21, 19),
        Pair(6, 18), Pair(9, 18), Pair(-2, 48), Pair(16, 7), Pair(4, 40), Pair(17, 21), Pair(16, 50), Pair(22, 8),
        Pair(-15, 51), Pair(2, 23), Pair(0, 36), Pair(4, 20), Pair(5, 30), Pair(10, 0), Pair(6, 29), Pair(-1, 28),
        Pair(-10, 19), Pair(7, 18), Pair(0, 9), Pair(1, 4), Pair(5, 7), Pair(6, -11), Pair(-10, -4), Pair(-8, 9),
        Pair(1, 16), Pair(7, -4), Pair(-3, 26), Pair(2, 10), Pair(0, -7), Pair(18, -9), Pair(-41, 62), Pair(-51, 52)
      },
      { // Piece 5
        Pair(1, 93), Pair(20, 21), Pair(22, -125), Pair(82, -42), Pair(-21, -26), Pair(54, -121), Pair(68, -83), Pair(48, -7),
        Pair(10, -69), Pair(-105, -72), Pair(84, 17), Pair(-59, 50), Pair(49, 49), Pair(43, -6), Pair(-8, -14), Pair(-49, -34),
        Pair(26, -84), Pair(-63, -86), Pair(25, -5), Pair(123, -16), Pair(29, 0), Pair(19, -16), Pair(9, -12), Pair(-63, -29),
        Pair(-142, -89), Pair(45, 3), Pair(-112, -9), Pair(54, -12), Pair(23, 1), Pair(88, 2), Pair(57, -18), Pair(19, -21),
        Pair(75, -38), Pair(-22, 5), Pair(15, 12), Pair(-3, -11), Pair(7, 14), Pair(36, -4), Pair(15, -5), Pair(5, 4),
        Pair(-118, 23), Pair(-54, 51), Pair(8, 18), Pair(11, 4), Pair(2, 6), Pair(18, 0), Pair(18, -3), Pair(35, -11),
        Pair(2, 29), Pair(-21, 16), Pair(-15, 21), Pair(-5, 3), Pair(0, 4), Pair(15, -9), Pair(4, -1), Pair(-3, 6),
        Pair(66, 0), Pair(16, 20), Pair(8, 13), Pair(19, 4), Pair(1, 3), Pair(15, -10), Pair(1, -11), Pair(0, 13)
      }
    }},
    {{ // Bucket 41
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-41, 52), Pair(21, 40), Pair(20, 35), Pair(-37, 19), Pair(79, -31), Pair(-17, 27), Pair(25, -6), Pair(16, 27),
        Pair(1, -4), Pair(14, 15), Pair(-11, 5), Pair(11, 4), Pair(-1, 37), Pair(24, 23), Pair(23, 8), Pair(3, 17),
        Pair(14, -6), Pair(-6, -8), Pair(-6, 25), Pair(9, 2), Pair(8, 3), Pair(6, -1), Pair(1, 9), Pair(2, 9),
        Pair(3, 1), Pair(1, -2), Pair(-1, 7), Pair(-1, 2), Pair(-2, -5), Pair(-1, 2), Pair(-2, 1), Pair(-1, 7),
        Pair(1, 1), Pair(1, 1), Pair(1, -1), Pair(1, -1), Pair(-3, -4), Pair(-2, 0), Pair(-1, -3), Pair(-1, -1),
        Pair(-1, 0), Pair(2, 2), Pair(2, 1), Pair(3, -9), Pair(-2, 0), Pair(-6, -2), Pair(-1, -1), Pair(1, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-81, -4), Pair(77, -71), Pair(-15, 4), Pair(-50, -10), Pair(21, -29), Pair(61, -38), Pair(-95, 13), Pair(-2, 5),
        Pair(-7, 19), Pair(-20, -25), Pair(4, 26), Pair(24, 5), Pair(41, 15), Pair(39, -5), Pair(10, -55), Pair(29, 18),
        Pair(2, -2), Pair(-31, -29), Pair(8, 1), Pair(12, 11), Pair(-1, -1), Pair(27, 20), Pair(15, -24), Pair(17, 9),
        Pair(-6, 56), Pair(0, 34), Pair(-24, 59), Pair(9, 2), Pair(5, 16), Pair(25, -6), Pair(23, 6), Pair(21, 0),
        Pair(-12, -3), Pair(-2, -16), Pair(-12, 20), Pair(3, 9), Pair(4, 23), Pair(10, 2), Pair(20, 9), Pair(16, 3),
        Pair(0, 6), Pair(-9, -3), Pair(1, 1), Pair(-12, 2), Pair(4, 9), Pair(3, 8), Pair(6, 0), Pair(12, 36),
        Pair(1, -18), Pair(-43, 53), Pair(-2, 29), Pair(-1, 7), Pair(0, 3), Pair(-6, 6), Pair(-2, 33), Pair(3, 35),
        Pair(14, -19), Pair(1, 14), Pair(-46, 42), Pair(-13, 7), Pair(1, 17), Pair(14, 5), Pair(6, 55), Pair(9, 91)
      },
      { // Piece 2
        Pair(26, -8), Pair(-23, 5), Pair(-179, 47), Pair(-78, 65), Pair(-24, 60), Pair(-82, 70), Pair(37, 47), Pair(-57, 80),
        Pair(-88, 7), Pair(-42, 49), Pair(-6, 38), Pair(-4, 36), Pair(27, 11), Pair(17, 36), Pair(-11, 72), Pair(9, -10),
        Pair(-3, 3), Pair(-80, 20), Pair(-17, 44), Pair(-17, 28), Pair(3, 44), Pair(-8, 44), Pair(10, 30), Pair(6, 22),
        Pair(-6, -32), Pair(-8, 52), Pair(-75, 48), Pair(6, 24), Pair(-7, 39), Pair(-28, 36), Pair(5, 31), Pair(25, 14),
        Pair(-10, 27), Pair(-13, 4), Pair(-19, 27), Pair(-9, 33), Pair(-2, 7), Pair(-1, 9), Pair(-13, 23), Pair(18, 4),
        Pair(10, 3), Pair(-2, 18), Pair(-10, 22), Pair(-1, 9), Pair(-3, 19), Pair(2, 9), Pair(6, 18), Pair(10, 7),
        Pair(10, 42), Pair(4, 29), Pair(3, 20), Pair(-3, 7), Pair(2, 5), Pair(-7, 21), Pair(7, 13), Pair(1, -8),
        Pair(17, 26), Pair(6, 27), Pair(-3, 18), Pair(8, 13), Pair(-10, 10), Pair(-1, 9), Pair(36, 4), Pair(14, -1)
      },
      { // Piece 3
        Pair(15, 4), Pair(-21, 13), Pair(-9, 13), Pair(17, 1), Pair(26, -4), Pair(35, 0), Pair(-36, 29), Pair(48, 13),
        Pair(-11, 30), Pair(-17, 17), Pair(35, 1), Pair(-24, 46), Pair(20, 8), Pair(55, -7), Pair(16, 24), Pair(48, -5),
        Pair(32, -12), Pair(67, 32), Pair(5, 25), Pair(-11, 17), Pair(-12, 18), Pair(17, 5), Pair(92, -4), Pair(46, 7),
        Pair(50, -42), Pair(-21, 20), Pair(-2, 36), Pair(-23, 6), Pair(-16, 19), Pair(13, -1), Pair(22, 20), Pair(20, -3),
        Pair(-5, -4), Pair(-36, 20), Pair(-1, 9), Pair(-8, 12), Pair(6, 8), Pair(1, 8), Pair(-9, 18), Pair(37, -2),
        Pair(-18, 12), Pair(-11, 5), Pair(-8, 1), Pair(5, 6), Pair(-1, 14), Pair(20, 6), Pair(21, 0), Pair(37, 16),
        Pair(-19, 9), Pair(-15, -4), Pair(-10, 0), Pair(10, 4), Pair(6, -1), Pair(-7, 25), Pair(8, 1), Pair(-41, 7),
        Pair(-3, 3), Pair(0, 3), Pair(0, 6), Pair(-1, 8), Pair(-1, 6), Pair(0, 13), Pair(12, 8), Pair(5, 15)
      },
      { // Piece 4
        Pair(40, -18), Pair(12, -5), Pair(-20, 47), Pair(-32, 15), Pair(-14, 50), Pair(46, -10), Pair(-11, 59), Pair(75, -15),
        Pair(5, 18), Pair(-20, 30), Pair(-6, 10), Pair(23, 14), Pair(5, 54), Pair(49, -35), Pair(-18, 62), Pair(-4, 28),
        Pair(12, 3), Pair(54, 28), Pair(18, 13), Pair(28, 21), Pair(9, 22), Pair(-2, 70), Pair(16, 11), Pair(18, 41),
        Pair(11, -65), Pair(2, 18), Pair(4, 84), Pair(11, 1), Pair(12, 34), Pair(1, 32), Pair(6, -1), Pair(16, 2),
        Pair(4, 6), Pair(-2, 22), Pair(-4, -16), Pair(3, 25), Pair(4, 25), Pair(-2, 29), Pair(1, 28), Pair(19, 31),
        Pair(-21, 32), Pair(4, 9), Pair(-2, 11), Pair(3, 16), Pair(5, 6), Pair(-2, 27), Pair(17, 19), Pair(13, 35),
        Pair(13, 4), Pair(-2, 2), Pair(3, 16), Pair(2, 3), Pair(2, 17), Pair(2, 15), Pair(12, 1), Pair(29, 37),
        Pair(-2, 34), Pair(-2, 60), Pair(3, 15), Pair(2, 11), Pair(-8, 3), Pair(17, -8), Pair(25, -106), Pair(10, -8)
      },
      { // Piece 5
        Pair(-50, -201), Pair(-9, -53), Pair(7, -20), Pair(-25, -55), Pair(29, 67), Pair(87, -36), Pair(24, -8), Pair(-6, 5),
        Pair(60, -56), Pair(21, -42), Pair(24, -65), Pair(-9, -21), Pair(-80, -20), Pair(-47, 18), Pair(-38, 1), Pair(-28, 17),
        Pair(-92, -54), Pair(12, -41), Pair(4, -102), Pair(149, -57), Pair(48, -42), Pair(70, -7), Pair(-10, -17), Pair(-49, -15),
        Pair(-42, -58), Pair(27, -103), Pair(48, -5), Pair(-34, -12), Pair(-10, -10), Pair(-21, -1), Pair(64, -14), Pair(74, -13),
        Pair(198, -52), Pair(-62, -41), Pair(79, -33), Pair(-3, -25), Pair(35, -15), Pair(6, -7), Pair(26, -15), Pair(-3, 5),
        Pair(-37, 38), Pair(17, -34), Pair(0, 3), Pair(-13, -11), Pair(-4, -13), Pair(6, -2), Pair(14, -6), Pair(33, -6),
        Pair(-8, 36), Pair(-4, 2), Pair(35, 12), Pair(-4, -3), Pair(-2, 4), Pair(2, -6), Pair(-2, -5), Pair(-4, -3),
        Pair(58, 18), Pair(12, 7), Pair(22, 9), Pair(42, -2), Pair(6, -6), Pair(22, -7), Pair(-2, -6), Pair(1, -14)
      }
    }},
    {{ // Bucket 42
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-19, 25), Pair(-27, 34), Pair(-78, 41), Pair(26, -40), Pair(-53, -4), Pair(93, 24), Pair(42, -15), Pair(-8, 10),
        Pair(-4, 11), Pair(-3, 12), Pair(-4, 11), Pair(6, -4), Pair(7, 15), Pair(32, -9), Pair(3, 18), Pair(-28, 28),
        Pair(-6, 0), Pair(-3, 8), Pair(-10, -9), Pair(11, 24), Pair(4, 5), Pair(3, 0), Pair(-2, 2), Pair(16, -3),
        Pair(-2, 2), Pair(2, -7), Pair(-1, 7), Pair(1, 4), Pair(0, 3), Pair(2, -1), Pair(0, 3), Pair(1, 1),
        Pair(-3, 2), Pair(-2, 1), Pair(-1, -1), Pair(1, 4), Pair(0, 1), Pair(-2, 0), Pair(-1, -1), Pair(0, -3),
        Pair(-2, 3), Pair(-3, -4), Pair(3, 6), Pair(2, -4), Pair(-2, 3), Pair(-4, -3), Pair(-1, 3), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-34, 46), Pair(96, -66), Pair(5, -9), Pair(-86, -43), Pair(57, -83), Pair(135, -4), Pair(52, 48), Pair(76, 10),
        Pair(-89, -86), Pair(8, 18), Pair(-10, -26), Pair(-1, 19), Pair(11, -19), Pair(-25, 46), Pair(18, 4), Pair(35, -25),
        Pair(30, 18), Pair(7, 2), Pair(-2, 30), Pair(10, 33), Pair(-14, 18), Pair(32, 16), Pair(7, 7), Pair(1, 22),
        Pair(24, 7), Pair(13, 19), Pair(22, 39), Pair(10, -6), Pair(17, 8), Pair(17, 0), Pair(16, 0), Pair(30, 13),
        Pair(12, 13), Pair(-35, 40), Pair(-5, 25), Pair(-19, 43), Pair(0, 22), Pair(2, 16), Pair(17, 11), Pair(8, 20),
        Pair(-14, 29), Pair(-7, 24), Pair(-9, 6), Pair(4, 19), Pair(-15, 3), Pair(5, 19), Pair(8, 22), Pair(4, 5),
        Pair(-10, 50), Pair(-3, 24), Pair(-10, 63), Pair(6, 15), Pair(8, 16), Pair(9, 9), Pair(5, -6), Pair(8, 43),
        Pair(68, 48), Pair(4, 5), Pair(43, -36), Pair(-11, 30), Pair(7, 34), Pair(12, 31), Pair(16, -10), Pair(20, -39)
      },
      { // Piece 2
        Pair(-63, -74), Pair(-29, 31), Pair(97, 26), Pair(22, 22), Pair(-10, 0), Pair(-8, 27), Pair(82, 24), Pair(37, 41),
        Pair(6, 11), Pair(-7, 8), Pair(-17, 45), Pair(6, 49), Pair(-26, 26), Pair(-40, 38), Pair(-53, 52), Pair(-20, 32),
        Pair(6, 6), Pair(-8, 12), Pair(-39, 12), Pair(-5, 35), Pair(30, 10), Pair(59, 1), Pair(-38, 68), Pair(2, 58),
        Pair(-1, 7), Pair(11, 11), Pair(17, 35), Pair(14, 22), Pair(10, 31), Pair(-3, 29), Pair(16, 15), Pair(11, 23),
        Pair(-9, 31), Pair(-7, -7), Pair(1, 13), Pair(-18, 14), Pair(-6, 31), Pair(1, 34), Pair(1, 20), Pair(14, -6),
        Pair(8, -3), Pair(-8, 38), Pair(7, 20), Pair(0, 19), Pair(3, 20), Pair(2, 11), Pair(9, 4), Pair(1, 30),
        Pair(-7, 3), Pair(7, 11), Pair(-1, 54), Pair(7, 11), Pair(2, 16), Pair(7, 8), Pair(-1, 7), Pair(-4, 69),
        Pair(-4, 25), Pair(22, 20), Pair(9, 26), Pair(-15, 37), Pair(4, 10), Pair(0, 20), Pair(40, 31), Pair(-2, 24)
      },
      { // Piece 3
        Pair(4, 14), Pair(58, -19), Pair(85, -20), Pair(-23, 13), Pair(4, -3), Pair(-10, 39), Pair(-90, 56), Pair(-20, 27),
        Pair(2, 17), Pair(25, 0), Pair(-9, 40), Pair(0, 11), Pair(52, -3), Pair(74, -13), Pair(32, 5), Pair(0, -6),
        Pair(27, -10), Pair(-19, 30), Pair(75, 3), Pair(30, -6), Pair(6, 29), Pair(28, -11), Pair(36, 8), Pair(11, -9),
        Pair(11, 1), Pair(20, 2), Pair(7, -2), Pair(-1, -3), Pair(-17, 33), Pair(14, 3), Pair(51, -20), Pair(-2, 4),
        Pair(-18, 6), Pair(12, 2), Pair(-13, -4), Pair(3, 11), Pair(6, 13), Pair(2, 6), Pair(-1, -14), Pair(-14, 8),
        Pair(-3, 21), Pair(-2, -4), Pair(-11, -17), Pair(-12, 2), Pair(-10, 15), Pair(-4, 12), Pair(4, 16), Pair(-2, 40),
        Pair(-2, 2), Pair(-6, 13), Pair(-4, 7), Pair(-13, 25), Pair(1, 12), Pair(-11, 18), Pair(9, 6), Pair(11, -11),
        Pair(0, 4), Pair(1, 2), Pair(-1, -4), Pair(-2, -2), Pair(3, 4), Pair(2, -1), Pair(0, 10), Pair(4, 7)
      },
      { // Piece 4
        Pair(4, -13), Pair(16, 49), Pair(34, 6), Pair(-71, 124), Pair(47, -9), Pair(23, 6), Pair(-22, -33), Pair(16, 25),
        Pair(16, 18), Pair(-14, 25), Pair(16, 41), Pair(-6, -16), Pair(-18, 64), Pair(16, -25), Pair(34, 43), Pair(28, 23),
        Pair(-4, -16), Pair(32, 0), Pair(-97, 152), Pair(17, 36), Pair(26, 25), Pair(-2, -9), Pair(-20, 104), Pair(28, 4),
        Pair(9, -37), Pair(-9, 5), Pair(36, 22), Pair(-34, 31), Pair(16, 24), Pair(-22, 79), Pair(23, 31), Pair(1, 31),
        Pair(11, 16), Pair(2, 30), Pair(8, 14), Pair(-8, 30), Pair(22, 11), Pair(20, 32), Pair(17, 14), Pair(8, 54),
        Pair(7, 13), Pair(-5, 33), Pair(5, 0), Pair(-4, 17), Pair(0, 12), Pair(3, 20), Pair(7, 31), Pair(11, -21),
        Pair(-8, 14), Pair(11, 27), Pair(8, 26), Pair(-1, 22), Pair(4, 20), Pair(5, 43), Pair(7, -1), Pair(3, 56),
        Pair(10, 13), Pair(7, 25), Pair(15, -27), Pair(2, 0), Pair(-12, 30), Pair(13, -6), Pair(-8, 6), Pair(-28, 54)
      },
      { // Piece 5
        Pair(-1, 22), Pair(45, 4), Pair(-47, -116), Pair(26, -55), Pair(17, -26), Pair(8, 14), Pair(-2, -26), Pair(35, -46),
        Pair(-39, -170), Pair(-33, -42), Pair(11, -28), Pair(20, -47), Pair(-17, -15), Pair(110, -3), Pair(36, 10), Pair(27, -3),
        Pair(-68, -44), Pair(-58, -60), Pair(-17, -73), Pair(161, -129), Pair(33, -37), Pair(59, -23), Pair(-34, 10), Pair(-112, 27),
        Pair(30, -33), Pair(29, -57), Pair(57, -96), Pair(70, -13), Pair(-20, -19), Pair(2, 4), Pair(28, -8), Pair(19, 10),
        Pair(5, -46), Pair(24, -8), Pair(-53, -52), Pair(75, -26), Pair(-26, -6), Pair(31, 4), Pair(32, -9), Pair(1, -4),
        Pair(86, -15), Pair(-4, 17), Pair(-76, 7), Pair(26, 12), Pair(24, 2), Pair(2, 17), Pair(26, 0), Pair(-15, -8),
        Pair(-37, 12), Pair(9, -3), Pair(1, 15), Pair(21, 5), Pair(-11, 14), Pair(5, 3), Pair(-7, 6), Pair(3, 7),
        Pair(17, -2), Pair(-2, 9), Pair(-1, 6), Pair(13, 50), Pair(2, 9), Pair(7, 13), Pair(0, -3), Pair(4, 2)
      }
    }},
    {{ // Bucket 43
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-85, 24), Pair(-21, 38), Pair(15, 44), Pair(34, -45), Pair(-26, 83), Pair(-4, -43), Pair(71, 0), Pair(11, 31),
        Pair(-1, 20), Pair(1, 10), Pair(-1, 7), Pair(19, -8), Pair(14, -20), Pair(16, -9), Pair(5, 11), Pair(-14, -5),
        Pair(5, 7), Pair(-10, 6), Pair(4, -10), Pair(-9, -12), Pair(-8, 10), Pair(3, -2), Pair(22, 8), Pair(-2, -5),
        Pair(0, 6), Pair(2, 0), Pair(2, -3), Pair(1, -2), Pair(-1, -2), Pair(-1, 2), Pair(-3, 1), Pair(3, 1),
        Pair(-1, 2), Pair(-2, 3), Pair(-3, -4), Pair(-2, -4), Pair(-2, 0), Pair(-2, -3), Pair(1, -2), Pair(-1, 0),
        Pair(-1, 3), Pair(0, -1), Pair(-2, -7), Pair(-7, 5), Pair(-2, -7), Pair(-3, -2), Pair(2, -3), Pair(2, 4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-101, 124), Pair(48, 64), Pair(-58, 21), Pair(20, 46), Pair(-7, -26), Pair(-42, 31), Pair(-1, 63), Pair(89, -111),
        Pair(-18, -5), Pair(4, -22), Pair(35, 5), Pair(79, -49), Pair(-36, 49), Pair(14, 11), Pair(-46, -24), Pair(-38, 20),
        Pair(29, 13), Pair(3, 7), Pair(-21, 30), Pair(83, -23), Pair(-26, 52), Pair(8, 22), Pair(-4, -24), Pair(-45, 36),
        Pair(12, 2), Pair(8, 4), Pair(50, 11), Pair(-3, 52), Pair(-7, 25), Pair(8, 20), Pair(-11, 37), Pair(2, -11),
        Pair(0, 13), Pair(-15, -15), Pair(-9, 17), Pair(-6, 24), Pair(-8, 30), Pair(1, 22), Pair(2, 4), Pair(3, 37),
        Pair(12, -5), Pair(-10, 31), Pair(5, 12), Pair(-17, 0), Pair(-4, 15), Pair(-8, 15), Pair(7, 25), Pair(6, 18),
        Pair(-16, 10), Pair(-32, 45), Pair(5, 20), Pair(1, 33), Pair(4, -1), Pair(0, 20), Pair(-11, 44), Pair(2, 31),
        Pair(13, 56), Pair(10, -4), Pair(48, -33), Pair(11, 20), Pair(-14, 20), Pair(5, 26), Pair(6, 24), Pair(19, 62)
      },
      { // Piece 2
        Pair(3, -8), Pair(-79, 29), Pair(42, 37), Pair(-56, 25), Pair(-40, 32), Pair(33, 11), Pair(22, -53), Pair(-8, 35),
        Pair(7, 11), Pair(28, -10), Pair(-9, 48), Pair(-2, 4), Pair(-64, 28), Pair(-9, 25), Pair(-14, 26), Pair(-40, 16),
        Pair(-28, 63), Pair(-21, 22), Pair(-15, 26), Pair(-39, 8), Pair(12, 20), Pair(49, 28), Pair(14, -2), Pair(14, 27),
        Pair(-1, 28), Pair(-6, 10), Pair(29, 10), Pair(-3, 44), Pair(-26, -21), Pair(-4, 26), Pair(-2, 18), Pair(3, 26),
        Pair(-34, 31), Pair(1, 14), Pair(-6, 9), Pair(3, -4), Pair(-5, 0), Pair(-6, 23), Pair(8, 22), Pair(-7, 12),
        Pair(-3, 29), Pair(-2, 12), Pair(3, 35), Pair(-2, 7), Pair(-1, 25), Pair(-5, 16), Pair(-7, 10), Pair(-5, 33),
        Pair(-1, 49), Pair(5, 11), Pair(-5, 17), Pair(0, 37), Pair(1, -6), Pair(-1, 8), Pair(0, -8), Pair(8, -7),
        Pair(-1, -12), Pair(1, 13), Pair(5, 18), Pair(-6, 19), Pair(19, 10), Pair(6, 8), Pair(-26, 26), Pair(-28, -3)
      },
      { // Piece 3
        Pair(-18, 20), Pair(25, 8), Pair(40, 4), Pair(144, -63), Pair(21, 8), Pair(42, 13), Pair(29, 8), Pair(1, 31),
        Pair(15, 8), Pair(15, -4), Pair(1, -17), Pair(-48, 49), Pair(-56, 29), Pair(73, -6), Pair(-21, 8), Pair(15, 3),
        Pair(-17, 2), Pair(-26, 22), Pair(27, -1), Pair(-33, -1), Pair(6, -4), Pair(26, -18), Pair(12, -8), Pair(19, -14),
        Pair(-3, -10), Pair(-16, -3), Pair(-37, -20), Pair(32, -12), Pair(0, -33), Pair(-8, 6), Pair(11, -6), Pair(-26, 15),
        Pair(-10, -2), Pair(-8, 13), Pair(-3, -10), Pair(-9, 8), Pair(-22, 19), Pair(-15, 11), Pair(-1, 4), Pair(18, -22),
        Pair(16, -15), Pair(-2, -10), Pair(-1, -11), Pair(-3, -16), Pair(-5, -22), Pair(7, -8), Pair(26, -19), Pair(22, -7),
        Pair(4, -13), Pair(-2, 11), Pair(9, 1), Pair(-7, 0), Pair(-1, 2), Pair(0, -1), Pair(3, 14), Pair(-16, 15),
        Pair(-1, 0), Pair(3, -5), Pair(0, -3), Pair(-5, -3), Pair(0, -1), Pair(4, -3), Pair(-6, 15), Pair(8, -6)
      },
      { // Piece 4
        Pair(5, -12), Pair(23, -53), Pair(13, 48), Pair(-25, 63), Pair(-17, 48), Pair(-121, 113), Pair(42, -21), Pair(-1, -17),
        Pair(14, 13), Pair(2, 27), Pair(8, 18), Pair(-12, -21), Pair(-55, 83), Pair(48, 7), Pair(12, 1), Pair(-1, 72),
        Pair(-13, 58), Pair(2, 18), Pair(-16, 23), Pair(45, 16), Pair(1, 13), Pair(-12, 28), Pair(-31, 38), Pair(-2, 68),
        Pair(-8, 9), Pair(16, 30), Pair(73, -32), Pair(21, 1), Pair(-26, 16), Pair(-20, 54), Pair(11, 40), Pair(-16, 35),
        Pair(-1, 41), Pair(-6, 16), Pair(0, 14), Pair(-4, 1), Pair(-9, 41), Pair(-14, 12), Pair(-8, 44), Pair(-2, 47),
        Pair(-5, 19), Pair(2, 11), Pair(6, -11), Pair(5, 14), Pair(-10, 20), Pair(-1, 25), Pair(5, 35), Pair(-12, 23),
        Pair(39, -14), Pair(-3, 31), Pair(4, -17), Pair(5, 6), Pair(-1, -2), Pair(-4, 4), Pair(-10, 18), Pair(54, -104),
        Pair(7, 5), Pair(-1, 9), Pair(-6, 36), Pair(6, 3), Pair(2, -7), Pair(9, 22), Pair(34, -67), Pair(25, 50)
      },
      { // Piece 5
        Pair(4, -23), Pair(-60, -49), Pair(8, -38), Pair(-10, -101), Pair(2, -53), Pair(5, -79), Pair(-41, 15), Pair(17, -38),
        Pair(2, 53), Pair(40, -31), Pair(58, 16), Pair(-24, -90), Pair(-77, 9), Pair(-6, 10), Pair(50, -23), Pair(56, 79),
        Pair(-4, -22), Pair(57, -68), Pair(40, -101), Pair(-41, -77), Pair(48, -124), Pair(84, -60), Pair(-27, -3), Pair(-26, 8),
        Pair(-85, 42), Pair(-37, -10), Pair(97, -15), Pair(10, -70), Pair(-15, 1), Pair(-30, 11), Pair(9, 23), Pair(48, -34),
        Pair(-115, 8), Pair(16, -13), Pair(34, -33), Pair(11, -49), Pair(71, -29), Pair(15, -14), Pair(-5, -2), Pair(-55, 27),
        Pair(-81, -6), Pair(-58, -4), Pair(-24, 24), Pair(7, -22), Pair(-33, 11), Pair(-14, 3), Pair(-5, 3), Pair(0, -9),
        Pair(-8, 10), Pair(-5, 21), Pair(-20, 24), Pair(-10, 13), Pair(-23, 22), Pair(5, 5), Pair(-3, 9), Pair(10, -12),
        Pair(-35, 8), Pair(0, 26), Pair(-9, 13), Pair(7, 5), Pair(1, 17), Pair(3, 6), Pair(0, 4), Pair(8, -7)
      }
    }},
    {{ // Bucket 44
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-11, 24), Pair(-15, 12), Pair(-41, 36), Pair(-71, 19), Pair(-21, 67), Pair(25, 70), Pair(23, -19), Pair(94, -54),
        Pair(5, 17), Pair(22, 12), Pair(17, -9), Pair(-12, -1), Pair(-9, -27), Pair(19, 7), Pair(-9, 7), Pair(10, 0),
        Pair(3, 6), Pair(-1, 4), Pair(6, 1), Pair(12, 36), Pair(-6, -3), Pair(18, -9), Pair(-3, 6), Pair(3, 4),
        Pair(2, 0), Pair(-1, -4), Pair(1, -1), Pair(1, 0), Pair(-1, -3), Pair(2, 0), Pair(-4, 3), Pair(1, -1),
        Pair(1, 1), Pair(0, -1), Pair(-1, -2), Pair(1, 3), Pair(1, 0), Pair(-2, 0), Pair(-2, 3), Pair(-2, 1),
        Pair(0, 3), Pair(1, -1), Pair(0, 2), Pair(4, -9), Pair(2, -4), Pair(-1, -4), Pair(0, 4), Pair(-3, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-23, 15), Pair(105, -14), Pair(109, 3), Pair(-34, 36), Pair(8, 50), Pair(61, 10), Pair(-84, 28), Pair(-100, 68),
        Pair(0, 4), Pair(-5, -17), Pair(-32, 14), Pair(-12, 26), Pair(-43, 2), Pair(-2, 8), Pair(19, -104), Pair(-34, 26),
        Pair(-23, 11), Pair(5, -9), Pair(19, 7), Pair(-11, 17), Pair(38, 9), Pair(12, 2), Pair(-3, 15), Pair(0, 28),
        Pair(24, 1), Pair(-4, 13), Pair(15, 3), Pair(-9, 4), Pair(4, 35), Pair(12, -1), Pair(16, 15), Pair(0, 3),
        Pair(-1, 9), Pair(-23, 15), Pair(-1, 11), Pair(-11, 17), Pair(5, 16), Pair(-9, 9), Pair(-3, 18), Pair(0, 10),
        Pair(1, -1), Pair(-2, 6), Pair(-9, -3), Pair(-8, 12), Pair(-12, 1), Pair(1, 8), Pair(-12, 7), Pair(8, 10),
        Pair(-3, -16), Pair(-11, 19), Pair(-4, 1), Pair(2, 7), Pair(-2, 21), Pair(1, 7), Pair(-16, 35), Pair(-2, 33),
        Pair(-44, 33), Pair(6, 6), Pair(-9, 47), Pair(6, -4), Pair(5, -8), Pair(13, -15), Pair(1, 11), Pair(6, -10)
      },
      { // Piece 2
        Pair(-19, -3), Pair(-70, 14), Pair(-51, 76), Pair(-32, 35), Pair(29, 41), Pair(-139, 47), Pair(8, -6), Pair(4, 45),
        Pair(-11, 23), Pair(5, 24), Pair(-11, 13), Pair(-11, 60), Pair(-7, 44), Pair(0, 21), Pair(22, -9), Pair(-10, 51),
        Pair(-8, 9), Pair(22, 7), Pair(-26, 34), Pair(0, 22), Pair(-10, 15), Pair(-35, 38), Pair(0, -8), Pair(18, 13),
        Pair(-4, 4), Pair(-7, 17), Pair(-2, 16), Pair(-70, 13), Pair(16, 38), Pair(-72, 25), Pair(2, 19), Pair(-2, 13),
        Pair(-13, 16), Pair(19, 3), Pair(-14, 9), Pair(-19, 8), Pair(-20, 10), Pair(-1, 17), Pair(-19, 21), Pair(-1, 11),
        Pair(9, 19), Pair(-1, -5), Pair(-1, 11), Pair(3, 19), Pair(9, 8), Pair(-6, 9), Pair(-5, 36), Pair(-12, 14),
        Pair(-19, 8), Pair(2, 6), Pair(2, -2), Pair(5, 12), Pair(-2, 19), Pair(-3, 35), Pair(-7, -2), Pair(14, -25),
        Pair(-9, 1), Pair(-3, 25), Pair(10, 23), Pair(-10, -13), Pair(9, 10), Pair(-7, 15), Pair(-1, -10), Pair(-5, 22)
      },
      { // Piece 3
        Pair(15, -1), Pair(38, 0), Pair(17, 5), Pair(0, 12), Pair(0, 6), Pair(-5, -28), Pair(11, -5), Pair(-14, 14),
        Pair(21, 3), Pair(14, 9), Pair(-13, 16), Pair(-17, 3), Pair(11, 11), Pair(-11, -10), Pair(34, -13), Pair(14, -11),
        Pair(12, -19), Pair(-7, 7), Pair(18, -3), Pair(-7, 17), Pair(12, -27), Pair(29, -4), Pair(-34, 3), Pair(-13, -8),
        Pair(11, -1), Pair(-2, 12), Pair(15, -1), Pair(22, -15), Pair(10, -2), Pair(56, -36), Pair(-9, 14), Pair(-17, 4),
        Pair(-3, -3), Pair(7, -2), Pair(-2, 1), Pair(-5, -3), Pair(-2, -9), Pair(-19, 1), Pair(-4, -1), Pair(30, 0),
        Pair(1, -1), Pair(-5, -18), Pair(2, -2), Pair(3, -13), Pair(1, -14), Pair(-3, -2), Pair(5, 1), Pair(9, 9),
        Pair(-1, 8), Pair(12, 0), Pair(9, 2), Pair(-4, -4), Pair(-18, 17), Pair(2, -9), Pair(-11, -25), Pair(14, 11),
        Pair(2, -4), Pair(0, -2), Pair(3, 4), Pair(-3, -4), Pair(-2, -7), Pair(-2, 5), Pair(-3, 8), Pair(4, -3)
      },
      { // Piece 4
        Pair(-16, 58), Pair(-22, 42), Pair(-13, 13), Pair(18, -5), Pair(15, 35), Pair(-1, 30), Pair(101, -34), Pair(42, 7),
        Pair(21, 18), Pair(1, 26), Pair(2, 15), Pair(-37, 33), Pair(35, -16), Pair(-5, -1), Pair(-15, 47), Pair(31, -14),
        Pair(-15, 20), Pair(-7, 26), Pair(-2, -24), Pair(-5, 18), Pair(-1, -24), Pair(20, -2), Pair(-14, 19), Pair(3, -19),
        Pair(19, 5), Pair(13, 32), Pair(9, 10), Pair(-101, 76), Pair(-6, 7), Pair(4, 44), Pair(1, 22), Pair(4, 47),
        Pair(9, 16), Pair(-3, 29), Pair(6, 12), Pair(-8, 18), Pair(10, -31), Pair(7, 6), Pair(-8, 31), Pair(13, 32),
        Pair(11, 22), Pair(6, 4), Pair(-15, 7), Pair(4, -5), Pair(9, 16), Pair(6, -2), Pair(14, -10), Pair(8, -25),
        Pair(16, 17), Pair(-3, 10), Pair(-4, 14), Pair(-1, 10), Pair(12, 0), Pair(-6, 26), Pair(-11, 33), Pair(5, 78),
        Pair(20, 13), Pair(12, -1), Pair(0, 21), Pair(3, 5), Pair(13, 10), Pair(-4, -7), Pair(25, -22), Pair(-27, -24)
      },
      { // Piece 5
        Pair(3, -30), Pair(-3, -72), Pair(27, -40), Pair(27, -12), Pair(14, -15), Pair(-6, -33), Pair(-14, -136), Pair(-5, -47),
        Pair(-12, 2), Pair(102, -8), Pair(28, -31), Pair(16, -83), Pair(-1, -68), Pair(48, -91), Pair(-59, -36), Pair(-13, 29),
        Pair(-55, 25), Pair(68, 17), Pair(73, -14), Pair(-20, -99), Pair(74, -36), Pair(82, -116), Pair(55, -30), Pair(-18, 1),
        Pair(3, -31), Pair(86, -24), Pair(-84, -14), Pair(4, 8), Pair(64, -84), Pair(99, -49), Pair(5, 2), Pair(-51, 0),
        Pair(104, 13), Pair(47, -6), Pair(-42, 4), Pair(-37, -11), Pair(0, -33), Pair(40, -28), Pair(-37, 3), Pair(1, 3),
        Pair(28, 36), Pair(8, -14), Pair(0, -5), Pair(12, 5), Pair(4, -9), Pair(-23, 11), Pair(-5, -2), Pair(16, -1),
        Pair(-13, 8), Pair(-12, 8), Pair(21, -3), Pair(-9, 22), Pair(-6, 16), Pair(11, 13), Pair(-1, 8), Pair(2, 5),
        Pair(-4, 13), Pair(8, 2), Pair(4, 2), Pair(5, 3), Pair(-4, 25), Pair(8, 23), Pair(2, 6), Pair(-1, 14)
      }
    }},
    {{ // Bucket 45
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-38, 49), Pair(-72, 42), Pair(65, 9), Pair(-23, 35), Pair(17, 58), Pair(-64, 33), Pair(-34, 38), Pair(24, 15),
        Pair(25, -7), Pair(51, -3), Pair(43, -1), Pair(24, -9), Pair(10, -6), Pair(-50, 5), Pair(24, 6), Pair(28, -10),
        Pair(3, 3), Pair(7, 1), Pair(26, -4), Pair(8, -1), Pair(11, 29), Pair(-17, 3), Pair(6, 0), Pair(1, -7),
        Pair(4, 1), Pair(2, 2), Pair(2, -1), Pair(0, 3), Pair(1, 0), Pair(4, 3), Pair(6, -3), Pair(1, 0),
        Pair(2, -5), Pair(2, -6), Pair(2, 0), Pair(-2, -1), Pair(-3, 0), Pair(-3, 2), Pair(-1, -5), Pair(-4, -2),
        Pair(0, 0), Pair(4, -2), Pair(6, -3), Pair(0, 0), Pair(-1, 0), Pair(3, -2), Pair(2, -6), Pair(-6, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-43, -66), Pair(83, 14), Pair(63, -2), Pair(-41, 4), Pair(94, 10), Pair(22, 20), Pair(-25, 11), Pair(62, 116),
        Pair(-54, 49), Pair(-6, 33), Pair(32, 14), Pair(2, -26), Pair(8, -3), Pair(-62, 49), Pair(87, 3), Pair(-85, 22),
        Pair(-7, 19), Pair(17, -11), Pair(-6, 27), Pair(13, 22), Pair(40, 14), Pair(145, 28), Pair(-37, 4), Pair(-34, 28),
        Pair(-7, 26), Pair(7, 1), Pair(12, -11), Pair(11, 14), Pair(-23, 29), Pair(43, 50), Pair(32, -7), Pair(44, -31),
        Pair(-15, 31), Pair(29, 42), Pair(3, 16), Pair(9, 19), Pair(-5, 23), Pair(8, 22), Pair(-2, -4), Pair(7, 3),
        Pair(9, 36), Pair(7, 25), Pair(9, 21), Pair(8, 9), Pair(1, 22), Pair(-7, 6), Pair(14, 22), Pair(-8, -10),
        Pair(2, -56), Pair(-26, 35), Pair(1, 3), Pair(4, 11), Pair(19, 14), Pair(0, 36), Pair(26, 12), Pair(-3, 17),
        Pair(34, -41), Pair(10, 35), Pair(-57, 50), Pair(-37, 26), Pair(-25, 19), Pair(32, 29), Pair(0, 25), Pair(-135, 38)
      },
      { // Piece 2
        Pair(27, 20), Pair(51, 13), Pair(23, 19), Pair(-21, -8), Pair(-54, 50), Pair(34, 41), Pair(14, 22), Pair(-108, -70),
        Pair(-38, 7), Pair(12, -3), Pair(-33, 36), Pair(49, 0), Pair(-57, 31), Pair(1, 39), Pair(51, -61), Pair(16, 47),
        Pair(27, 21), Pair(-37, 47), Pair(30, 1), Pair(-21, 22), Pair(13, 39), Pair(0, 51), Pair(-8, 22), Pair(-11, 34),
        Pair(-8, 12), Pair(3, 6), Pair(-3, 21), Pair(-5, 17), Pair(-22, 70), Pair(23, 48), Pair(-4, 21), Pair(6, 3),
        Pair(8, 13), Pair(-30, 54), Pair(31, 2), Pair(4, 21), Pair(-2, -3), Pair(7, 2), Pair(-10, 26), Pair(-11, -14),
        Pair(-3, 26), Pair(-7, -2), Pair(1, 11), Pair(19, 5), Pair(2, 5), Pair(3, 13), Pair(-10, 21), Pair(-2, 20),
        Pair(-2, -31), Pair(4, 8), Pair(3, 11), Pair(-6, 6), Pair(7, -3), Pair(0, 28), Pair(8, 0), Pair(-16, 17),
        Pair(-43, 28), Pair(47, 7), Pair(0, 24), Pair(8, 23), Pair(-13, 10), Pair(14, 4), Pair(-4, 28), Pair(-19, -21)
      },
      { // Piece 3
        Pair(8, 11), Pair(-25, 26), Pair(45, 10), Pair(20, 25), Pair(32, 10), Pair(11, -12), Pair(-18, -3), Pair(-66, 45),
        Pair(14, 3), Pair(5, 3), Pair(36, -9), Pair(34, 6), Pair(9, 1), Pair(37, 2), Pair(-30, 21), Pair(52, 5),
        Pair(3, 11), Pair(4, 15), Pair(-14, 16), Pair(1, 20), Pair(4, 28), Pair(-28, 40), Pair(-10, -6), Pair(-34, 28),
        Pair(-7, 7), Pair(-7, 4), Pair(25, -9), Pair(-8, 20), Pair(8, 26), Pair(12, -11), Pair(55, -21), Pair(-22, 3),
        Pair(25, -12), Pair(-1, 1), Pair(16, 0), Pair(1, 9), Pair(5, -15), Pair(-22, 3), Pair(-9, 12), Pair(-16, 10),
        Pair(0, 40), Pair(-7, 20), Pair(-21, 20), Pair(3, 4), Pair(-15, 17), Pair(-23, 18), Pair(17, 10), Pair(-33, 37),
        Pair(46, 22), Pair(-6, 25), Pair(-3, 6), Pair(1, -10), Pair(-2, 10), Pair(5, 8), Pair(-1, -5), Pair(-14, 5),
        Pair(0, 11), Pair(2, 10), Pair(5, 1), Pair(0, 12), Pair(1, 7), Pair(4, 7), Pair(11, -18), Pair(-9, 19)
      },
      { // Piece 4
        Pair(-29, 22), Pair(-42, 0), Pair(18, 23), Pair(81, -54), Pair(-30, 2), Pair(55, -73), Pair(104, -8), Pair(69, -35),
        Pair(4, 26), Pair(-16, 36), Pair(-9, 2), Pair(-27, 76), Pair(35, -25), Pair(8, 53), Pair(35, -70), Pair(-23, 60),
        Pair(7, 23), Pair(-2, -9), Pair(13, -17), Pair(-46, 57), Pair(29, -18), Pair(203, -13), Pair(6, -23), Pair(11, -58),
        Pair(1, -43), Pair(-2, 15), Pair(-15, 23), Pair(2, 5), Pair(50, -78), Pair(34, -22), Pair(52, 17), Pair(-9, 14),
        Pair(41, -67), Pair(8, -22), Pair(-2, 25), Pair(-9, 31), Pair(0, -18), Pair(25, 12), Pair(4, 28), Pair(7, -8),
        Pair(27, -94), Pair(-4, -9), Pair(16, 8), Pair(10, 11), Pair(6, -7), Pair(16, -35), Pair(21, -22), Pair(-10, -9),
        Pair(34, -42), Pair(-8, -7), Pair(2, -13), Pair(3, -6), Pair(-1, 5), Pair(-7, 7), Pair(18, -14), Pair(17, -24),
        Pair(-12, 14), Pair(-4, 1), Pair(-12, -9), Pair(-2, 7), Pair(11, -16), Pair(24, -43), Pair(27, 33), Pair(8, 39)
      },
      { // Piece 5
        Pair(6, -71), Pair(-1, -47), Pair(-13, -101), Pair(40, -37), Pair(33, 38), Pair(-24, -100), Pair(-19, -94), Pair(-8, -176),
        Pair(-35, -48), Pair(-22, -78), Pair(-14, -3), Pair(-43, -75), Pair(-2, -23), Pair(76, -70), Pair(-21, -46), Pair(54, -67),
        Pair(9, -14), Pair(113, -48), Pair(43, -51), Pair(51, -25), Pair(-133, -66), Pair(0, -40), Pair(20, -78), Pair(-27, -69),
        Pair(-127, -24), Pair(30, -21), Pair(-23, -24), Pair(-34, -15), Pair(111, -32), Pair(-77, -87), Pair(31, -74), Pair(-14, -13),
        Pair(22, -12), Pair(95, -24), Pair(27, -29), Pair(54, -33), Pair(30, -24), Pair(5, -41), Pair(17, -25), Pair(17, -29),
        Pair(58, 4), Pair(-23, -22), Pair(62, -33), Pair(11, -10), Pair(27, -4), Pair(-3, -10), Pair(-14, 5), Pair(19, -20),
        Pair(18, -19), Pair(18, -14), Pair(24, 2), Pair(5, -2), Pair(3, 8), Pair(3, 13), Pair(7, 8), Pair(8, -3),
        Pair(7, -24), Pair(10, -23), Pair(2, -21), Pair(36, -15), Pair(-9, 22), Pair(-33, 15), Pair(-6, 12), Pair(18, -10)
      }
    }},
    {{ // Bucket 46
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(92, 10), Pair(42, 31), Pair(82, -25), Pair(10, 22), Pair(-3, 24), Pair(-31, -46), Pair(51, -50), Pair(-4, 14),
        Pair(6, 16), Pair(14, 8), Pair(14, 18), Pair(8, 10), Pair(-4, -10), Pair(-6, -2), Pair(-25, 13), Pair(3, 5),
        Pair(-2, 11), Pair(6, 5), Pair(7, 2), Pair(0, -6), Pair(4, -1), Pair(11, 12), Pair(-5, -2), Pair(25, 6),
        Pair(5, 3), Pair(2, -3), Pair(4, -5), Pair(0, 3), Pair(-5, 2), Pair(4, 4), Pair(5, -3), Pair(3, 4),
        Pair(0, -1), Pair(0, -2), Pair(-5, -2), Pair(1, -1), Pair(0, -2), Pair(2, 4), Pair(1, 3), Pair(-1, 2),
        Pair(-2, 3), Pair(1, -3), Pair(-3, -2), Pair(2, -3), Pair(-1, -2), Pair(3, -1), Pair(1, -1), Pair(-4, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(40, -20), Pair(-27, 30), Pair(-56, 27), Pair(-42, 10), Pair(-42, 23), Pair(-120, 28), Pair(-109, 12), Pair(108, -75),
        Pair(-16, 10), Pair(11, -14), Pair(11, 7), Pair(-37, -22), Pair(14, -21), Pair(-21, 17), Pair(-37, -16), Pair(15, 3),
        Pair(-42, 8), Pair(11, -11), Pair(12, 13), Pair(-10, 25), Pair(26, 20), Pair(1, 22), Pair(-48, -19), Pair(-77, 30),
        Pair(1, 2), Pair(6, 6), Pair(8, -3), Pair(5, 17), Pair(18, 0), Pair(-13, 17), Pair(4, 42), Pair(28, 42),
        Pair(-9, -1), Pair(12, 20), Pair(5, 13), Pair(6, 1), Pair(6, 8), Pair(-11, 27), Pair(-4, 18), Pair(-14, 6),
        Pair(-1, 40), Pair(0, 12), Pair(1, 11), Pair(-2, 12), Pair(-2, 8), Pair(3, 11), Pair(-15, 16), Pair(-8, 0),
        Pair(-16, 22), Pair(26, -15), Pair(-10, 1), Pair(-1, 5), Pair(-7, 16), Pair(-8, 18), Pair(-1, 35), Pair(6, 47),
        Pair(-19, -50), Pair(-1, 0), Pair(-29, 9), Pair(-22, -9), Pair(-10, 2), Pair(-6, -4), Pair(10, -17), Pair(-23, 16)
      },
      { // Piece 2
        Pair(22, 19), Pair(-22, 22), Pair(19, -10), Pair(-9, 47), Pair(14, 32), Pair(57, 40), Pair(-92, 39), Pair(88, -34),
        Pair(5, 8), Pair(-16, 34), Pair(0, 47), Pair(-46, 32), Pair(-49, 62), Pair(-6, 27), Pair(-42, 38), Pair(-136, -46),
        Pair(-6, 35), Pair(-11, 35), Pair(15, 16), Pair(-4, 43), Pair(-26, 39), Pair(-11, 36), Pair(-49, 43), Pair(0, 30),
        Pair(-3, 24), Pair(7, 7), Pair(6, 19), Pair(8, 25), Pair(1, 14), Pair(-30, 8), Pair(-6, 48), Pair(-57, 10),
        Pair(-4, 14), Pair(-7, 18), Pair(1, 13), Pair(-2, 11), Pair(-5, 5), Pair(-11, 17), Pair(-18, 20), Pair(-32, 16),
        Pair(-5, 25), Pair(1, 7), Pair(3, 4), Pair(-5, 6), Pair(1, 11), Pair(0, 7), Pair(2, 8), Pair(-3, 29),
        Pair(3, -7), Pair(2, 16), Pair(-3, 14), Pair(4, 9), Pair(-4, -2), Pair(-1, 9), Pair(5, 11), Pair(11, 37),
        Pair(0, 39), Pair(-3, -19), Pair(3, 10), Pair(-16, 7), Pair(16, -11), Pair(-3, 8), Pair(-5, 26), Pair(-12, 24)
      },
      { // Piece 3
        Pair(16, 26), Pair(14, 24), Pair(-26, 31), Pair(-12, 34), Pair(4, 5), Pair(4, 9), Pair(-28, 11), Pair(-42, 48),
        Pair(-6, 18), Pair(24, 14), Pair(16, 19), Pair(4, 15), Pair(-5, 35), Pair(-17, 26), Pair(22, 22), Pair(3, 10),
        Pair(-1, 5), Pair(5, 2), Pair(15, 4), Pair(12, 2), Pair(-20, 21), Pair(-30, 23), Pair(76, 4), Pair(12, -21),
        Pair(19, 6), Pair(-7, 16), Pair(10, 3), Pair(-14, 14), Pair(5, 3), Pair(-10, -51), Pair(22, 9), Pair(54, -5),
        Pair(-8, 9), Pair(-12, 15), Pair(-2, 20), Pair(-5, 16), Pair(2, 3), Pair(3, -2), Pair(-11, -11), Pair(-34, 9),
        Pair(-5, 22), Pair(2, 12), Pair(-5, 11), Pair(-6, 16), Pair(4, -4), Pair(0, 7), Pair(13, -18), Pair(-7, 0),
        Pair(3, 18), Pair(15, 24), Pair(0, 10), Pair(18, -3), Pair(1, -3), Pair(-4, 12), Pair(-10, -7), Pair(-30, 9),
        Pair(1, 15), Pair(-2, 14), Pair(-2, 16), Pair(0, 13), Pair(-2, 11), Pair(-3, 7), Pair(-4, -5), Pair(-3, 2)
      },
      { // Piece 4
        Pair(-42, -23), Pair(-30, 27), Pair(-33, 13), Pair(39, -6), Pair(52, -50), Pair(22, 61), Pair(-30, 66), Pair(25, 68),
        Pair(11, 4), Pair(-5, 14), Pair(9, 4), Pair(-31, 33), Pair(-46, 54), Pair(-12, 9), Pair(2, 10), Pair(45, -25),
        Pair(-7, -8), Pair(15, -17), Pair(3, -8), Pair(-7, -21), Pair(13, 1), Pair(-7, 6), Pair(-34, 14), Pair(-38, -24),
        Pair(0, -19), Pair(8, -17), Pair(-6, -11), Pair(-1, -1), Pair(-12, 50), Pair(15, 29), Pair(-9, -17), Pair(10, -18),
        Pair(9, -33), Pair(1, 0), Pair(4, 1), Pair(-16, 8), Pair(-13, 14), Pair(-14, 12), Pair(-13, 3), Pair(-4, 26),
        Pair(11, -9), Pair(-2, -8), Pair(0, 2), Pair(2, -12), Pair(-6, -6), Pair(-11, 14), Pair(16, -21), Pair(4, 11),
        Pair(-9, -17), Pair(-1, -6), Pair(1, 0), Pair(-4, -7), Pair(-5, 2), Pair(-3, -22), Pair(1, -28), Pair(6, -19),
        Pair(-9, -19), Pair(6, -23), Pair(-1, -15), Pair(2, -6), Pair(-4, -20), Pair(-4, -5), Pair(35, -28), Pair(44, 2)
      },
      { // Piece 5
        Pair(150, -90), Pair(40, -44), Pair(40, -85), Pair(23, -16), Pair(21, -65), Pair(7, -23), Pair(-18, -81), Pair(-30, -89),
        Pair(-2, -27), Pair(58, -69), Pair(116, -58), Pair(-24, -74), Pair(30, -75), Pair(-79, -70), Pair(-27, -14), Pair(51, -64),
        Pair(166, -14), Pair(184, -65), Pair(-16, -31), Pair(-47, -2), Pair(-20, -39), Pair(10, -67), Pair(-9, -111), Pair(100, -90),
        Pair(152, -47), Pair(63, -7), Pair(37, -15), Pair(82, -22), Pair(-18, -18), Pair(100, 18), Pair(-2, -85), Pair(27, -55),
        Pair(31, -42), Pair(41, -14), Pair(6, -16), Pair(-25, -12), Pair(10, -22), Pair(27, -15), Pair(18, -45), Pair(-35, -17),
        Pair(25, -19), Pair(10, -15), Pair(36, -19), Pair(-14, -8), Pair(-19, -8), Pair(0, 7), Pair(-15, -8), Pair(-33, 25),
        Pair(25, -19), Pair(8, -14), Pair(-21, -14), Pair(10, -17), Pair(-1, -2), Pair(-2, 4), Pair(-6, 11), Pair(2, 9),
        Pair(-12, -16), Pair(-4, -21), Pair(-17, -6), Pair(-14, -11), Pair(-7, -2), Pair(-7, 18), Pair(0, 0), Pair(-7, 0)
      }
    }},
    {{ // Bucket 47
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(25, 33), Pair(-4, 22), Pair(24, 1), Pair(-16, 17), Pair(-19, 27), Pair(23, -44), Pair(5, -7), Pair(36, 1),
        Pair(23, 10), Pair(-5, 18), Pair(15, 21), Pair(27, 9), Pair(0, 0), Pair(-34, -15), Pair(-19, 5), Pair(121, -8),
        Pair(4, 0), Pair(-1, -1), Pair(5, 12), Pair(-3, 0), Pair(2, -2), Pair(-17, -3), Pair(8, 1), Pair(-5, -1),
        Pair(0, -2), Pair(3, 0), Pair(1, -2), Pair(3, 0), Pair(5, 2), Pair(3, -5), Pair(1, -4), Pair(-2, 1),
        Pair(1, -1), Pair(1, -3), Pair(0, -5), Pair(0, -4), Pair(3, -2), Pair(6, -5), Pair(0, -4), Pair(1, 2),
        Pair(0, -2), Pair(1, -5), Pair(-1, -6), Pair(4, -12), Pair(-1, -1), Pair(2, -4), Pair(3, -5), Pair(-2, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-24, -17), Pair(-53, -38), Pair(-18, -37), Pair(-44, 26), Pair(-8, 24), Pair(-37, 4), Pair(9, -25), Pair(30, 19),
        Pair(-6, -1), Pair(-49, -19), Pair(-9, 11), Pair(51, -16), Pair(35, -1), Pair(-11, -21), Pair(-47, -14), Pair(42, -41),
        Pair(34, -28), Pair(2, -23), Pair(7, 4), Pair(3, 4), Pair(-16, -11), Pair(20, -2), Pair(-7, 5), Pair(-76, -14),
        Pair(23, -11), Pair(1, -11), Pair(20, -9), Pair(15, -11), Pair(14, 5), Pair(15, 6), Pair(3, 4), Pair(23, 32),
        Pair(-4, -1), Pair(-6, -11), Pair(-2, 0), Pair(10, 5), Pair(7, 5), Pair(6, 19), Pair(2, 10), Pair(0, 12),
        Pair(-2, -19), Pair(0, -16), Pair(2, -4), Pair(-1, -11), Pair(5, 2), Pair(-3, 9), Pair(9, 11), Pair(-12, -5),
        Pair(-4, 16), Pair(-26, 21), Pair(-11, -3), Pair(-5, 3), Pair(0, 3), Pair(-5, 9), Pair(8, 14), Pair(-1, 4),
        Pair(12, -43), Pair(-5, -14), Pair(-37, -8), Pair(-2, 12), Pair(-6, 6), Pair(-12, 28), Pair(-9, -20), Pair(-16, 57)
      },
      { // Piece 2
        Pair(-11, 61), Pair(-20, 54), Pair(-44, 30), Pair(-41, 26), Pair(-24, 31), Pair(-44, 89), Pair(16, 14), Pair(-3, -11),
        Pair(-8, 5), Pair(14, 30), Pair(-5, 40), Pair(-70, 35), Pair(-61, 47), Pair(-14, 28), Pair(-41, 40), Pair(14, 33),
        Pair(-14, 14), Pair(-17, 11), Pair(-7, 30), Pair(-7, 36), Pair(-12, 37), Pair(-17, -3), Pair(-23, 57), Pair(78, 60),
        Pair(-9, 3), Pair(17, 12), Pair(-18, 22), Pair(15, 26), Pair(-3, 28), Pair(10, 17), Pair(-3, -7), Pair(20, 49),
        Pair(5, 0), Pair(-14, 30), Pair(9, 8), Pair(-14, 24), Pair(11, 2), Pair(-1, 15), Pair(7, 1), Pair(11, 11),
        Pair(-10, 9), Pair(21, 5), Pair(3, 7), Pair(3, 15), Pair(0, 5), Pair(3, 21), Pair(-1, 18), Pair(-4, 38),
        Pair(13, 4), Pair(0, 1), Pair(4, 12), Pair(-14, 7), Pair(0, 19), Pair(-9, 9), Pair(9, 19), Pair(4, 43),
        Pair(0, 12), Pair(29, 5), Pair(-5, 3), Pair(-1, 1), Pair(-19, 14), Pair(8, 17), Pair(-19, 19), Pair(1, 36)
      },
      { // Piece 3
        Pair(-11, 26), Pair(21, 14), Pair(-48, 41), Pair(15, 17), Pair(-67, 34), Pair(42, 7), Pair(-35, 31), Pair(45, 22),
        Pair(9, 20), Pair(-15, 32), Pair(-2, 22), Pair(19, 10), Pair(4, 8), Pair(12, 8), Pair(5, 24), Pair(167, 2),
        Pair(16, -3), Pair(14, 10), Pair(16, 13), Pair(3, 9), Pair(7, 12), Pair(-18, 21), Pair(29, 11), Pair(-10, 11),
        Pair(-10, 30), Pair(-7, 6), Pair(0, 16), Pair(4, 7), Pair(0, 7), Pair(-1, 14), Pair(25, 63), Pair(8, 12),
        Pair(-7, 0), Pair(-3, 8), Pair(3, 18), Pair(-12, 21), Pair(0, 14), Pair(-4, 17), Pair(5, 25), Pair(-21, 19),
        Pair(2, -1), Pair(12, 16), Pair(11, -2), Pair(13, 11), Pair(-7, 27), Pair(-5, 22), Pair(5, 21), Pair(-19, 12),
        Pair(-2, 0), Pair(1, -6), Pair(0, 12), Pair(10, 8), Pair(-6, 1), Pair(8, -7), Pair(-5, 22), Pair(-23, 58),
        Pair(0, 13), Pair(-1, 16), Pair(1, 20), Pair(3, 13), Pair(-1, 10), Pair(3, 10), Pair(-7, 19), Pair(-9, 19)
      },
      { // Piece 4
        Pair(-7, -1), Pair(-22, 38), Pair(33, 65), Pair(-28, 29), Pair(34, -8), Pair(6, 25), Pair(38, -16), Pair(-15, 64),
        Pair(-3, 1), Pair(-1, 23), Pair(14, -20), Pair(-35, 44), Pair(-30, 67), Pair(21, 21), Pair(-11, 51), Pair(37, 19),
        Pair(12, 7), Pair(-15, 14), Pair(2, 16), Pair(-3, -2), Pair(31, 42), Pair(-33, 56), Pair(-28, 1), Pair(91, -87),
        Pair(-6, 22), Pair(-22, -6), Pair(-15, 30), Pair(2, 30), Pair(7, 39), Pair(-14, 57), Pair(-39, 124), Pair(3, -8),
        Pair(1, 5), Pair(-2, 15), Pair(-5, 5), Pair(-14, 36), Pair(-7, 13), Pair(-8, 13), Pair(2, 24), Pair(-13, -13),
        Pair(1, -9), Pair(-6, 7), Pair(6, 0), Pair(-9, 18), Pair(-1, -6), Pair(-9, 29), Pair(10, 4), Pair(8, 6),
        Pair(2, 8), Pair(-2, -4), Pair(-5, 8), Pair(-4, -11), Pair(0, -3), Pair(9, -8), Pair(12, -8), Pair(-27, -6),
        Pair(10, -28), Pair(-7, -15), Pair(0, -3), Pair(-2, -1), Pair(-2, -14), Pair(7, -27), Pair(19, 5), Pair(32, 16)
      },
      { // Piece 5
        Pair(36, -67), Pair(47, -160), Pair(-63, -121), Pair(-80, -57), Pair(76, -86), Pair(7, -101), Pair(39, -74), Pair(4, -5),
        Pair(28, -42), Pair(79, -85), Pair(-64, -25), Pair(26, -50), Pair(-95, -9), Pair(17, -72), Pair(27, -39), Pair(32, -123),
        Pair(22, -64), Pair(22, -28), Pair(12, -55), Pair(-25, -8), Pair(-2, -29), Pair(2, -35), Pair(56, -87), Pair(-11, -57),
        Pair(34, -64), Pair(81, -28), Pair(48, -22), Pair(64, -41), Pair(-5, -2), Pair(-20, -19), Pair(19, -87), Pair(107, -109),
        Pair(72, -20), Pair(72, -49), Pair(77, -26), Pair(90, -28), Pair(-9, -16), Pair(18, -20), Pair(37, -20), Pair(27, -59),
        Pair(55, -42), Pair(66, -42), Pair(27, -19), Pair(26, -13), Pair(29, -19), Pair(-20, -5), Pair(-2, 10), Pair(-12, -22),
        Pair(-25, 33), Pair(-16, -5), Pair(12, -22), Pair(2, -20), Pair(14, -15), Pair(-10, 0), Pair(-5, 8), Pair(-5, 18),
        Pair(-40, 2), Pair(-12, -24), Pair(-11, 9), Pair(7, -30), Pair(7, 3), Pair(-7, -2), Pair(5, 9), Pair(3, 3)
      }
    }},
    {{ // Bucket 48
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-11, -5), Pair(-14, 28), Pair(-61, 62), Pair(-3, 46), Pair(57, 29), Pair(41, -20), Pair(-42, 44), Pair(-31, 15),
        Pair(-14, -40), Pair(-16, 69), Pair(-9, 1), Pair(-28, 31), Pair(16, -4), Pair(10, 15), Pair(27, 23), Pair(-3, 27),
        Pair(-1, -6), Pair(-7, 12), Pair(-3, 2), Pair(6, -8), Pair(1, 2), Pair(8, 2), Pair(-3, 7), Pair(0, 5),
        Pair(-2, -1), Pair(0, -3), Pair(4, -1), Pair(3, 0), Pair(2, 2), Pair(-1, 2), Pair(5, -5), Pair(-1, 0),
        Pair(-2, 4), Pair(1, -3), Pair(2, -2), Pair(0, -4), Pair(0, -1), Pair(-1, 1), Pair(1, 0), Pair(0, 0),
        Pair(3, -2), Pair(2, -1), Pair(2, -2), Pair(1, -6), Pair(0, 0), Pair(-2, -3), Pair(0, -1), Pair(2, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-57, -66), Pair(55, -8), Pair(-102, 6), Pair(-1, 17), Pair(109, -31), Pair(-104, 35), Pair(-23, -27), Pair(-45, -80),
        Pair(38, 19), Pair(3, -10), Pair(27, -4), Pair(18, -12), Pair(50, -39), Pair(-17, -3), Pair(3, -4), Pair(56, -30),
        Pair(-11, 27), Pair(-43, -18), Pair(-1, 15), Pair(20, -5), Pair(-8, 14), Pair(58, 0), Pair(29, -16), Pair(25, 13),
        Pair(-5, 10), Pair(-9, 37), Pair(3, -6), Pair(-6, -1), Pair(11, -3), Pair(19, 6), Pair(13, -2), Pair(8, -21),
        Pair(-14, 33), Pair(-3, -6), Pair(-4, 3), Pair(5, -3), Pair(11, -11), Pair(15, -7), Pair(27, -13), Pair(15, 5),
        Pair(-7, 3), Pair(3, -5), Pair(-4, 7), Pair(-5, -8), Pair(2, -4), Pair(3, 5), Pair(4, 8), Pair(10, 8),
        Pair(-5, -32), Pair(32, 11), Pair(-4, -9), Pair(2, 0), Pair(2, -6), Pair(8, 4), Pair(16, -1), Pair(19, -7),
        Pair(-128, 32), Pair(-2, 21), Pair(-4, 36), Pair(27, -29), Pair(-15, -5), Pair(5, -5), Pair(0, -5), Pair(41, 35)
      },
      { // Piece 2
        Pair(-12, 32), Pair(-99, 71), Pair(39, 41), Pair(78, -25), Pair(-56, 25), Pair(-20, 11), Pair(-80, -5), Pair(-11, 97),
        Pair(53, 82), Pair(8, 7), Pair(-11, 52), Pair(42, 64), Pair(-53, 50), Pair(27, 22), Pair(-36, 20), Pair(24, 30),
        Pair(12, 32), Pair(-148, 55), Pair(-26, 32), Pair(9, 26), Pair(17, 26), Pair(4, 51), Pair(23, 22), Pair(2, 18),
        Pair(25, -18), Pair(-20, 22), Pair(16, 41), Pair(7, 12), Pair(7, 29), Pair(9, 28), Pair(12, 14), Pair(7, -1),
        Pair(-7, 11), Pair(-2, 35), Pair(5, 23), Pair(9, 17), Pair(14, 13), Pair(8, 16), Pair(-9, 30), Pair(7, 6),
        Pair(8, 40), Pair(1, 13), Pair(2, 17), Pair(5, 20), Pair(-2, 24), Pair(0, 10), Pair(3, 10), Pair(10, 13),
        Pair(8, 79), Pair(4, 22), Pair(4, 19), Pair(2, 17), Pair(-2, 3), Pair(-4, 10), Pair(8, 12), Pair(11, 13),
        Pair(-16, 71), Pair(6, 72), Pair(3, 18), Pair(1, -3), Pair(-28, 43), Pair(-1, 15), Pair(-20, -9), Pair(19, -4)
      },
      { // Piece 3
        Pair(8, 18), Pair(-41, 31), Pair(22, 13), Pair(3, 23), Pair(2, 30), Pair(13, 31), Pair(44, 27), Pair(-4, 43),
        Pair(-22, 31), Pair(-5, 47), Pair(-7, 39), Pair(-17, 42), Pair(8, 43), Pair(49, 4), Pair(9, 20), Pair(15, 20),
        Pair(-5, 43), Pair(18, -90), Pair(-4, 24), Pair(11, 11), Pair(30, 1), Pair(33, 9), Pair(-13, 30), Pair(11, 10),
        Pair(3, 34), Pair(-23, 27), Pair(4, 32), Pair(4, 16), Pair(13, 5), Pair(-12, -4), Pair(9, 47), Pair(14, 14),
        Pair(-6, 13), Pair(-9, -18), Pair(-9, 3), Pair(2, -3), Pair(2, 19), Pair(-8, 30), Pair(-8, 43), Pair(0, 28),
        Pair(-7, -6), Pair(-9, 26), Pair(4, 12), Pair(-2, 11), Pair(2, 16), Pair(11, 9), Pair(4, 24), Pair(26, -11),
        Pair(-8, 4), Pair(-10, -1), Pair(19, 3), Pair(-4, 14), Pair(-9, 23), Pair(20, 2), Pair(12, 31), Pair(-12, 40),
        Pair(-3, 16), Pair(-4, 10), Pair(-3, 17), Pair(0, 9), Pair(1, 16), Pair(2, 16), Pair(1, 23), Pair(2, 25)
      },
      { // Piece 4
        Pair(-77, 152), Pair(14, -10), Pair(-16, 65), Pair(-41, 77), Pair(-28, 38), Pair(82, 1), Pair(-14, 40), Pair(9, 46),
        Pair(29, -31), Pair(-2, 100), Pair(7, 80), Pair(5, 69), Pair(31, 32), Pair(12, 86), Pair(-47, 60), Pair(7, 42),
        Pair(5, 69), Pair(-28, -20), Pair(-16, 48), Pair(-35, 69), Pair(40, 6), Pair(37, -4), Pair(40, 31), Pair(11, 38),
        Pair(26, 10), Pair(-14, 29), Pair(34, 1), Pair(0, 37), Pair(-6, 42), Pair(21, 45), Pair(-5, 39), Pair(13, 30),
        Pair(3, 36), Pair(-5, 8), Pair(3, 40), Pair(3, 33), Pair(15, 10), Pair(20, -26), Pair(19, 33), Pair(5, 7),
        Pair(-6, 48), Pair(1, 17), Pair(0, 14), Pair(3, 6), Pair(7, 27), Pair(3, 32), Pair(7, 15), Pair(23, 7),
        Pair(6, 10), Pair(0, 9), Pair(0, 11), Pair(2, 2), Pair(-2, 20), Pair(0, 13), Pair(-17, 12), Pair(16, -16),
        Pair(-5, 3), Pair(-6, 4), Pair(-6, 7), Pair(0, 11), Pair(0, 16), Pair(-6, 24), Pair(-5, -11), Pair(-16, -74)
      },
      { // Piece 5
        Pair(7, 49), Pair(-2, 66), Pair(30, 35), Pair(74, -41), Pair(39, -29), Pair(17, -78), Pair(-23, -74), Pair(16, -3),
        Pair(-56, -107), Pair(-8, -38), Pair(57, -79), Pair(-48, -5), Pair(-30, -107), Pair(91, -53), Pair(86, -56), Pair(48, 2),
        Pair(-42, -87), Pair(36, 15), Pair(-3, -63), Pair(-60, 6), Pair(-75, 6), Pair(-5, -22), Pair(-7, 9), Pair(-28, -20),
        Pair(-92, -59), Pair(54, -36), Pair(14, -5), Pair(72, -2), Pair(6, -28), Pair(-58, 3), Pair(1, -5), Pair(-21, -20),
        Pair(48, -54), Pair(46, -3), Pair(-20, 11), Pair(12, -4), Pair(31, -4), Pair(5, -2), Pair(8, 5), Pair(12, 0),
        Pair(48, -12), Pair(-7, 13), Pair(-56, 16), Pair(-59, 16), Pair(10, -1), Pair(4, -2), Pair(17, -9), Pair(-3, -1),
        Pair(-27, 0), Pair(-42, 61), Pair(4, 7), Pair(25, -8), Pair(0, 3), Pair(20, 0), Pair(3, -1), Pair(8, -2),
        Pair(-3, 86), Pair(26, 21), Pair(10, 13), Pair(16, -20), Pair(8, -8), Pair(13, 3), Pair(3, -6), Pair(0, 13)
      }
    }},
    {{ // Bucket 49
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(51, 11), Pair(-87, 10), Pair(-51, -19), Pair(29, -15), Pair(3, 1), Pair(-67, 45), Pair(-37, 14), Pair(21, 23),
        Pair(17, 53), Pair(-14, -12), Pair(25, 40), Pair(14, 8), Pair(21, -5), Pair(3, 3), Pair(-17, 21), Pair(-11, -5),
        Pair(7, 5), Pair(-11, -5), Pair(0, 7), Pair(1, 6), Pair(9, 1), Pair(2, 6), Pair(3, -3), Pair(-8, 12),
        Pair(1, -3), Pair(-5, -3), Pair(0, 1), Pair(0, 0), Pair(0, -3), Pair(1, 3), Pair(1, 2), Pair(-2, 0),
        Pair(1, 2), Pair(-4, -1), Pair(4, 2), Pair(-2, 0), Pair(-1, -2), Pair(0, -3), Pair(-1, 0), Pair(-1, -1),
        Pair(-1, 2), Pair(-1, 1), Pair(2, 2), Pair(-1, 3), Pair(-1, -9), Pair(-3, -1), Pair(-1, -2), Pair(1, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-59, 49), Pair(-223, -72), Pair(-32, 56), Pair(-33, 9), Pair(29, 37), Pair(123, -41), Pair(-27, 33), Pair(-17, 74),
        Pair(-7, -8), Pair(-75, -33), Pair(-22, 11), Pair(-56, 14), Pair(12, -53), Pair(22, 22), Pair(-37, 31), Pair(46, -37),
        Pair(122, 55), Pair(14, 46), Pair(-222, 59), Pair(16, 10), Pair(-8, 16), Pair(48, -33), Pair(-27, -8), Pair(4, -58),
        Pair(-10, 34), Pair(-6, 1), Pair(-28, 39), Pair(-2, 4), Pair(0, 14), Pair(22, 15), Pair(10, 17), Pair(17, -27),
        Pair(-4, 1), Pair(-6, -7), Pair(-17, 10), Pair(-1, -10), Pair(11, 13), Pair(2, 5), Pair(-6, -5), Pair(7, 2),
        Pair(0, 20), Pair(2, 4), Pair(1, 6), Pair(-1, -2), Pair(3, 5), Pair(3, 7), Pair(2, 23), Pair(3, 38),
        Pair(5, -18), Pair(-17, 41), Pair(4, -4), Pair(1, 12), Pair(10, 0), Pair(3, 8), Pair(-3, 5), Pair(11, 3),
        Pair(60, -36), Pair(3, 20), Pair(10, -8), Pair(17, 8), Pair(4, 8), Pair(15, -1), Pair(-2, 24), Pair(37, -2)
      },
      { // Piece 2
        Pair(8, -20), Pair(-58, 23), Pair(-92, 65), Pair(22, 13), Pair(-10, 75), Pair(-57, 26), Pair(7, 31), Pair(43, 18),
        Pair(4, 19), Pair(7, 84), Pair(-17, 31), Pair(-12, 42), Pair(0, 45), Pair(27, 14), Pair(-19, 40), Pair(-17, 11),
        Pair(5, 18), Pair(3, 28), Pair(-82, 16), Pair(-14, 30), Pair(1, 25), Pair(-24, 39), Pair(9, 43), Pair(13, 4),
        Pair(3, 8), Pair(-7, 19), Pair(-43, 33), Pair(-11, 42), Pair(2, 16), Pair(-34, 59), Pair(7, -3), Pair(9, 32),
        Pair(-13, -5), Pair(0, -15), Pair(-17, 14), Pair(-5, 21), Pair(-1, 17), Pair(4, 11), Pair(-14, 30), Pair(22, 5),
        Pair(2, 14), Pair(-4, 24), Pair(-3, 18), Pair(0, 22), Pair(4, 6), Pair(4, 4), Pair(2, 11), Pair(5, 19),
        Pair(3, 53), Pair(7, 17), Pair(-1, 3), Pair(1, 7), Pair(1, 13), Pair(5, 30), Pair(2, 14), Pair(1, 32),
        Pair(23, 26), Pair(-8, 82), Pair(5, 13), Pair(10, 16), Pair(3, -3), Pair(-3, 10), Pair(3, 28), Pair(32, -9)
      },
      { // Piece 3
        Pair(-22, -13), Pair(17, 21), Pair(-15, 15), Pair(0, 25), Pair(46, 16), Pair(38, 36), Pair(77, -23), Pair(74, 18),
        Pair(-17, -2), Pair(-44, 20), Pair(-12, 19), Pair(19, 8), Pair(-12, 8), Pair(-43, 32), Pair(13, 38), Pair(-54, 44),
        Pair(-19, -2), Pair(10, 7), Pair(-197, 16), Pair(-39, 35), Pair(2, -1), Pair(17, 11), Pair(45, 15), Pair(37, 5),
        Pair(-15, 0), Pair(-23, 4), Pair(-6, 17), Pair(-6, 17), Pair(-17, 10), Pair(-16, 32), Pair(10, 3), Pair(-6, 19),
        Pair(14, -24), Pair(-15, -11), Pair(-7, -1), Pair(-11, 24), Pair(23, -26), Pair(26, 17), Pair(-10, 13), Pair(18, 18),
        Pair(-12, -2), Pair(-13, 22), Pair(-9, 11), Pair(8, 8), Pair(14, 1), Pair(11, 13), Pair(8, -15), Pair(24, 21),
        Pair(-16, 1), Pair(-2, -2), Pair(-12, 13), Pair(-2, 14), Pair(1, 13), Pair(6, 16), Pair(5, -17), Pair(17, -34),
        Pair(-5, 3), Pair(6, -2), Pair(-5, 6), Pair(-1, 9), Pair(0, 9), Pair(3, 13), Pair(11, -2), Pair(16, 12)
      },
      { // Piece 4
        Pair(10, -9), Pair(-12, 33), Pair(47, -4), Pair(44, 13), Pair(-44, 37), Pair(-1, -32), Pair(-6, 30), Pair(-8, 0),
        Pair(15, 17), Pair(-162, -13), Pair(-28, 66), Pair(28, 17), Pair(-11, -3), Pair(-2, 29), Pair(-4, 1), Pair(2, -39),
        Pair(-141, 16), Pair(-5, 22), Pair(-73, -137), Pair(20, 43), Pair(28, 4), Pair(58, -8), Pair(11, 17), Pair(25, 41),
        Pair(-14, 7), Pair(6, 48), Pair(10, 9), Pair(18, 25), Pair(9, 37), Pair(16, 17), Pair(-9, 39), Pair(2, 14),
        Pair(-6, -1), Pair(-3, 13), Pair(-8, 22), Pair(-4, 38), Pair(6, 19), Pair(-14, 55), Pair(-5, 53), Pair(-2, 33),
        Pair(-13, 27), Pair(6, -5), Pair(7, 13), Pair(4, 11), Pair(5, -2), Pair(4, 15), Pair(9, 47), Pair(-5, 40),
        Pair(-1, 16), Pair(-1, 16), Pair(0, 4), Pair(-1, 6), Pair(-3, 11), Pair(-9, 16), Pair(9, 1), Pair(-13, 106),
        Pair(-4, 33), Pair(7, 1), Pair(-1, 2), Pair(0, 3), Pair(12, -3), Pair(-3, 4), Pair(-34, -22), Pair(-3, -3)
      },
      { // Piece 5
        Pair(-8, -42), Pair(2, -86), Pair(10, 4), Pair(21, -39), Pair(19, -50), Pair(56, 44), Pair(-40, -32), Pair(2, -152),
        Pair(-18, -89), Pair(-14, -11), Pair(14, -84), Pair(9, -47), Pair(-46, -50), Pair(14, 9), Pair(-4, -29), Pair(-7, -41),
        Pair(-13, -32), Pair(49, -100), Pair(-3, -11), Pair(27, -54), Pair(-78, 13), Pair(60, -12), Pair(-50, 19), Pair(-138, -12),
        Pair(-15, -51), Pair(-100, -48), Pair(-22, -25), Pair(-120, -4), Pair(134, -49), Pair(0, 13), Pair(-58, 23), Pair(43, -51),
        Pair(33, -37), Pair(-55, -36), Pair(-61, 15), Pair(-18, 4), Pair(0, -21), Pair(-6, -8), Pair(32, -2), Pair(17, 15),
        Pair(-53, 31), Pair(-4, -31), Pair(-20, 14), Pair(-27, -12), Pair(-10, 0), Pair(10, -11), Pair(-20, 9), Pair(3, 3),
        Pair(-45, 50), Pair(-14, 5), Pair(5, 12), Pair(6, 15), Pair(2, -4), Pair(-8, -1), Pair(3, 0), Pair(5, -2),
        Pair(33, -1), Pair(9, 25), Pair(15, 7), Pair(17, -21), Pair(8, -7), Pair(28, -10), Pair(1, -3), Pair(7, -6)
      }
    }},
    {{ // Bucket 50
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-35, 10), Pair(-93, 46), Pair(12, 5), Pair(-10, -8), Pair(-47, 26), Pair(-10, 64), Pair(-140, 77), Pair(-12, 31),
        Pair(-11, -11), Pair(-10, 8), Pair(-4, -16), Pair(20, 79), Pair(21, -14), Pair(28, -6), Pair(-30, 13), Pair(-23, 41),
        Pair(-2, 4), Pair(3, 8), Pair(-12, -3), Pair(3, 6), Pair(2, 2), Pair(18, -10), Pair(8, -14), Pair(6, 6),
        Pair(-4, 0), Pair(6, -16), Pair(-7, 0), Pair(3, 1), Pair(-3, 3), Pair(0, 3), Pair(-1, 6), Pair(2, 7),
        Pair(-2, 2), Pair(-1, -4), Pair(0, -4), Pair(4, 2), Pair(-1, 1), Pair(-2, -2), Pair(3, 2), Pair(3, 0),
        Pair(-2, 2), Pair(-2, -1), Pair(1, 2), Pair(-3, 10), Pair(-4, 9), Pair(-2, -3), Pair(3, -1), Pair(3, 5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(31, -23), Pair(6, -48), Pair(117, -32), Pair(-67, 62), Pair(75, -30), Pair(1, 41), Pair(17, 95), Pair(-18, -12),
        Pair(-14, 12), Pair(-22, 53), Pair(-12, 67), Pair(15, 3), Pair(-18, 10), Pair(-41, 75), Pair(-24, 48), Pair(-46, 30),
        Pair(-28, 33), Pair(60, -35), Pair(10, 53), Pair(-172, 79), Pair(-4, 21), Pair(17, -7), Pair(-4, 16), Pair(30, -13),
        Pair(22, 31), Pair(-17, 1), Pair(16, 21), Pair(-29, 28), Pair(-1, 23), Pair(2, -8), Pair(7, 7), Pair(15, 37),
        Pair(-9, 37), Pair(22, 4), Pair(-6, -7), Pair(-16, 28), Pair(-8, 19), Pair(2, 13), Pair(23, -14), Pair(4, 6),
        Pair(-4, -1), Pair(-9, 32), Pair(-2, 10), Pair(-8, 25), Pair(-4, 2), Pair(2, 10), Pair(3, 8), Pair(4, 9),
        Pair(-26, -23), Pair(7, -6), Pair(7, -6), Pair(-2, 9), Pair(7, 10), Pair(4, 5), Pair(-6, 21), Pair(7, 8),
        Pair(-27, -44), Pair(5, 17), Pair(25, 7), Pair(-16, 35), Pair(2, 31), Pair(5, 7), Pair(3, 10), Pair(77, 16)
      },
      { // Piece 2
        Pair(-21, 38), Pair(-42, -29), Pair(35, 33), Pair(-33, 47), Pair(19, 28), Pair(-70, 59), Pair(-38, 88), Pair(63, 51),
        Pair(14, -32), Pair(-20, 48), Pair(-138, 20), Pair(4, 29), Pair(19, 24), Pair(-34, 46), Pair(4, 53), Pair(-56, 42),
        Pair(20, 5), Pair(1, 154), Pair(-6, 60), Pair(-299, 155), Pair(-55, 16), Pair(-9, 14), Pair(-2, 61), Pair(-24, 28),
        Pair(-22, 10), Pair(-18, 11), Pair(-14, 44), Pair(-16, 26), Pair(10, 18), Pair(-9, 38), Pair(-1, 10), Pair(2, 23),
        Pair(-7, 47), Pair(-15, 12), Pair(6, 20), Pair(-19, 19), Pair(-3, 15), Pair(0, 21), Pair(5, 39), Pair(12, 52),
        Pair(-4, -12), Pair(-10, 32), Pair(-2, 22), Pair(2, 15), Pair(-3, 10), Pair(5, 23), Pair(9, 11), Pair(13, -1),
        Pair(-14, 31), Pair(1, 14), Pair(13, 19), Pair(1, 9), Pair(2, 9), Pair(9, 8), Pair(7, 4), Pair(-4, 35),
        Pair(9, 0), Pair(1, 34), Pair(1, 35), Pair(-14, 52), Pair(8, 20), Pair(-4, 27), Pair(-22, 8), Pair(-7, -8)
      },
      { // Piece 3
        Pair(-1, -11), Pair(14, -13), Pair(38, -25), Pair(-21, -20), Pair(34, 29), Pair(10, 22), Pair(-50, 28), Pair(-46, 25),
        Pair(8, -28), Pair(-11, -10), Pair(105, -23), Pair(20, -13), Pair(-5, 4), Pair(-3, 33), Pair(15, -4), Pair(-8, 15),
        Pair(17, -13), Pair(118, -110), Pair(-1, -21), Pair(-51, 14), Pair(-4, 26), Pair(24, -4), Pair(-25, 2), Pair(7, 4),
        Pair(-8, 28), Pair(20, -28), Pair(19, -25), Pair(-2, -1), Pair(-10, -6), Pair(-8, 6), Pair(-11, -1), Pair(5, -5),
        Pair(-8, -2), Pair(-12, -5), Pair(-7, -2), Pair(-24, -1), Pair(-19, 4), Pair(19, 7), Pair(36, -30), Pair(22, -15),
        Pair(3, -9), Pair(-1, -10), Pair(0, 6), Pair(-11, 0), Pair(-6, 4), Pair(-2, -2), Pair(4, 33), Pair(4, 7),
        Pair(-16, 17), Pair(12, -16), Pair(-2, 6), Pair(-6, -8), Pair(12, 3), Pair(-10, 10), Pair(11, 7), Pair(54, -27),
        Pair(-6, 6), Pair(-7, -6), Pair(-5, 12), Pair(-5, -2), Pair(-2, 2), Pair(-4, 10), Pair(-6, 11), Pair(0, -7)
      },
      { // Piece 4
        Pair(43, -6), Pair(-46, 18), Pair(-30, 11), Pair(-19, 70), Pair(56, 20), Pair(-154, 128), Pair(-10, 41), Pair(-23, 70),
        Pair(17, -3), Pair(-6, -1), Pair(-56, -69), Pair(23, 41), Pair(-21, 75), Pair(-85, 64), Pair(-19, 49), Pair(-22, 23),
        Pair(9, -48), Pair(-34, 30), Pair(-3, 6), Pair(48, -35), Pair(5, -14), Pair(7, 59), Pair(27, 21), Pair(20, 22),
        Pair(1, 68), Pair(6, 4), Pair(49, 6), Pair(13, -1), Pair(6, 21), Pair(-22, 47), Pair(21, 3), Pair(7, 28),
        Pair(0, 15), Pair(3, -5), Pair(1, 13), Pair(-16, 42), Pair(15, 1), Pair(4, 32), Pair(23, 3), Pair(9, 49),
        Pair(13, -55), Pair(-6, 14), Pair(-5, 20), Pair(-11, 20), Pair(-4, -7), Pair(0, -10), Pair(2, -31), Pair(30, 37),
        Pair(-10, -16), Pair(8, 11), Pair(6, 5), Pair(3, -2), Pair(-3, 3), Pair(2, 0), Pair(8, -26), Pair(3, -4),
        Pair(13, -44), Pair(-21, 34), Pair(5, -15), Pair(-2, -1), Pair(-13, 20), Pair(-3, -4), Pair(-4, 1), Pair(7, -38)
      },
      { // Piece 5
        Pair(0, 41), Pair(-3, 2), Pair(11, -105), Pair(-4, -68), Pair(11, -51), Pair(-26, -48), Pair(47, -26), Pair(-35, -15),
        Pair(-32, -80), Pair(67, -84), Pair(-9, -40), Pair(33, -128), Pair(-74, -62), Pair(-79, -14), Pair(-64, -37), Pair(-15, -116),
        Pair(-132, -88), Pair(7, 7), Pair(48, -33), Pair(14, 30), Pair(22, -47), Pair(45, -26), Pair(-50, 9), Pair(-10, 34),
        Pair(-81, -4), Pair(-79, -35), Pair(15, -85), Pair(59, -37), Pair(-26, -11), Pair(-5, 11), Pair(52, -30), Pair(122, 5),
        Pair(103, -20), Pair(-154, 4), Pair(-77, -16), Pair(-22, -2), Pair(16, -24), Pair(0, -8), Pair(-23, 10), Pair(-17, -9),
        Pair(-23, -35), Pair(-69, 29), Pair(-1, -3), Pair(-12, 5), Pair(-13, 1), Pair(-44, 25), Pair(-12, 6), Pair(-11, 0),
        Pair(-45, 9), Pair(-29, 53), Pair(-1, 16), Pair(-39, 46), Pair(16, 8), Pair(1, 1), Pair(-3, -13), Pair(10, -20),
        Pair(22, -29), Pair(18, -11), Pair(13, 28), Pair(22, -15), Pair(6, 1), Pair(-5, -10), Pair(0, -5), Pair(-6, -7)
      }
    }},
    {{ // Bucket 51
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(90, 11), Pair(-67, 37), Pair(10, -15), Pair(-20, 27), Pair(86, -17), Pair(118, 31), Pair(23, 64), Pair(169, 9),
        Pair(-9, -18), Pair(56, -29), Pair(30, -8), Pair(21, 3), Pair(79, 11), Pair(1, 5), Pair(12, -17), Pair(-29, 22),
        Pair(10, 19), Pair(1, 3), Pair(-5, 26), Pair(11, -12), Pair(7, 6), Pair(1, 13), Pair(28, -4), Pair(-18, 23),
        Pair(2, -4), Pair(-2, -14), Pair(6, 4), Pair(-9, -6), Pair(5, -8), Pair(-2, 12), Pair(-1, 6), Pair(-2, -4),
        Pair(-1, 1), Pair(2, 6), Pair(-1, 10), Pair(0, 2), Pair(-2, 4), Pair(2, -5), Pair(4, 2), Pair(-4, -5),
        Pair(1, 2), Pair(-1, -3), Pair(-3, 5), Pair(8, 3), Pair(6, -14), Pair(3, 7), Pair(6, -8), Pair(0, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-27, 4), Pair(-8, -22), Pair(36, 10), Pair(-9, -27), Pair(27, 66), Pair(-36, -30), Pair(52, 8), Pair(140, 50),
        Pair(89, -65), Pair(-3, -13), Pair(-13, -46), Pair(-15, 5), Pair(68, -70), Pair(-8, -14), Pair(-33, 78), Pair(50, -33),
        Pair(42, 65), Pair(18, 8), Pair(-257, 40), Pair(15, 86), Pair(-2, -96), Pair(25, -9), Pair(18, -8), Pair(-14, 7),
        Pair(10, -29), Pair(4, 24), Pair(-3, 22), Pair(-13, 26), Pair(2, 39), Pair(26, -13), Pair(-7, 15), Pair(-19, -19),
        Pair(19, -42), Pair(-44, 75), Pair(-5, 39), Pair(7, -11), Pair(9, 5), Pair(6, 6), Pair(-25, 47), Pair(3, 33),
        Pair(14, -16), Pair(26, -42), Pair(17, 22), Pair(-2, 14), Pair(-7, 45), Pair(-8, 14), Pair(-1, -34), Pair(12, 71),
        Pair(30, 46), Pair(-25, 77), Pair(18, -37), Pair(5, 15), Pair(21, -35), Pair(7, -16), Pair(17, -26), Pair(6, 26),
        Pair(41, 17), Pair(1, -5), Pair(53, -18), Pair(-15, 129), Pair(11, -18), Pair(40, 56), Pair(-6, -12), Pair(-19, 4)
      },
      { // Piece 2
        Pair(25, 3), Pair(-9, -21), Pair(-4, 11), Pair(-17, -2), Pair(-5, 16), Pair(1, -53), Pair(14, 120), Pair(-17, -65),
        Pair(18, 35), Pair(71, 26), Pair(-4, 123), Pair(-66, 29), Pair(-88, 22), Pair(-84, 74), Pair(-40, 18), Pair(2, 13),
        Pair(-6, 39), Pair(-12, -60), Pair(-42, 61), Pair(9, 39), Pair(-53, 25), Pair(-15, 53), Pair(-1, 52), Pair(36, 16),
        Pair(33, 33), Pair(6, 10), Pair(-18, 45), Pair(-6, 32), Pair(-13, 42), Pair(-21, 44), Pair(34, -49), Pair(-17, 104),
        Pair(-2, 55), Pair(-47, 53), Pair(-11, 34), Pair(35, -7), Pair(11, 17), Pair(10, 22), Pair(13, 50), Pair(23, 4),
        Pair(4, 9), Pair(-4, 21), Pair(11, 40), Pair(7, -5), Pair(10, -35), Pair(-19, 77), Pair(3, 0), Pair(24, -12),
        Pair(-22, -25), Pair(5, 26), Pair(-14, 84), Pair(10, 3), Pair(-2, 29), Pair(38, 26), Pair(7, 18), Pair(24, -14),
        Pair(13, 40), Pair(-51, 97), Pair(13, 10), Pair(-19, 140), Pair(-23, 26), Pair(4, 5), Pair(-46, -5), Pair(2, 7)
      },
      { // Piece 3
        Pair(18, -14), Pair(-24, -13), Pair(76, -62), Pair(95, 21), Pair(-3, 12), Pair(-40, -18), Pair(-84, 48), Pair(14, -41),
        Pair(-46, 8), Pair(26, -29), Pair(49, -25), Pair(0, -8), Pair(19, -4), Pair(89, -57), Pair(-61, -2), Pair(44, 30),
        Pair(-13, 2), Pair(-55, -45), Pair(27, 0), Pair(43, -45), Pair(-98, -7), Pair(69, -50), Pair(28, 0), Pair(19, 50),
        Pair(-3, -59), Pair(-13, -36), Pair(-28, -22), Pair(2, -29), Pair(-2, -29), Pair(53, 10), Pair(7, 46), Pair(-29, 2),
        Pair(-16, -47), Pair(1, -3), Pair(-34, -22), Pair(14, 3), Pair(-3, -29), Pair(44, 24), Pair(-4, 105), Pair(3, -1),
        Pair(-26, 24), Pair(20, -27), Pair(-45, 31), Pair(-18, 0), Pair(-3, -36), Pair(-18, 21), Pair(-27, 25), Pair(-26, 1),
        Pair(-17, -24), Pair(-8, -39), Pair(-13, -43), Pair(1, 5), Pair(-28, 30), Pair(-15, 2), Pair(3, 28), Pair(20, -103),
        Pair(-9, 8), Pair(-22, 6), Pair(-3, 1), Pair(-13, 25), Pair(-2, -4), Pair(-1, 5), Pair(-13, -20), Pair(-5, -5)
      },
      { // Piece 4
        Pair(6, 24), Pair(16, 61), Pair(-27, -30), Pair(-7, -45), Pair(-52, -2), Pair(34, -29), Pair(51, -6), Pair(13, 31),
        Pair(0, 2), Pair(-35, 21), Pair(39, -60), Pair(37, 9), Pair(37, 58), Pair(82, 109), Pair(-6, 79), Pair(6, 9),
        Pair(-21, 139), Pair(70, -65), Pair(19, -38), Pair(56, -38), Pair(0, 118), Pair(-56, 39), Pair(65, -72), Pair(-15, 47),
        Pair(37, 27), Pair(-28, -12), Pair(7, -27), Pair(9, 42), Pair(-22, 7), Pair(-10, 16), Pair(19, 15), Pair(13, -18),
        Pair(1, 7), Pair(-23, 77), Pair(2, -11), Pair(10, 8), Pair(22, -19), Pair(31, -48), Pair(19, -35), Pair(-29, 34),
        Pair(27, -69), Pair(5, -42), Pair(-12, 27), Pair(22, -43), Pair(1, 36), Pair(-21, -16), Pair(4, 25), Pair(-69, 9),
        Pair(33, -39), Pair(6, -7), Pair(0, 4), Pair(1, 25), Pair(4, -20), Pair(23, -21), Pair(47, -72), Pair(24, -84),
        Pair(-50, 64), Pair(-9, 43), Pair(-14, 13), Pair(-1, -19), Pair(-11, -3), Pair(34, -77), Pair(48, -49), Pair(-74, -69)
      },
      { // Piece 5
        Pair(-17, -66), Pair(1, -54), Pair(15, 34), Pair(-3, -4), Pair(1, 18), Pair(-59, -119), Pair(-3, -17), Pair(3, 40),
        Pair(13, 32), Pair(-31, -65), Pair(27, -93), Pair(5, 6), Pair(-7, -37), Pair(-25, -70), Pair(-18, -45), Pair(9, -18),
        Pair(-13, -51), Pair(-14, 57), Pair(6, -11), Pair(-34, -75), Pair(38, -48), Pair(48, -10), Pair(49, -57), Pair(8, 14),
        Pair(-1, -20), Pair(-46, 35), Pair(-35, -25), Pair(-42, -39), Pair(6, 2), Pair(94, -20), Pair(44, 31), Pair(-26, -66),
        Pair(-65, -67), Pair(4, 59), Pair(61, 3), Pair(20, -51), Pair(-120, 32), Pair(-39, 19), Pair(-21, 17), Pair(-50, -13),
        Pair(-106, -37), Pair(-104, -30), Pair(-66, 2), Pair(29, -7), Pair(25, 17), Pair(60, 8), Pair(1, 60), Pair(-44, 17),
        Pair(-8, -52), Pair(34, -9), Pair(-32, 10), Pair(62, -38), Pair(-65, 35), Pair(-25, 6), Pair(24, -12), Pair(-10, 25),
        Pair(-28, 32), Pair(5, 10), Pair(11, 4), Pair(-46, 41), Pair(-1, 17), Pair(49, -3), Pair(-1, -1), Pair(6, 10)
      }
    }},
    {{ // Bucket 52
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(34, 21), Pair(-14, 17), Pair(-54, 29), Pair(-19, 19), Pair(36, 21), Pair(-89, -5), Pair(-74, 51), Pair(89, -33),
        Pair(23, 11), Pair(16, 25), Pair(-10, 15), Pair(69, 78), Pair(-9, 12), Pair(1, 12), Pair(16, -15), Pair(34, 11),
        Pair(10, -1), Pair(6, 0), Pair(7, -1), Pair(14, 13), Pair(-8, 1), Pair(12, 20), Pair(-2, 15), Pair(-9, 8),
        Pair(3, 1), Pair(-4, 6), Pair(-1, 1), Pair(-2, -5), Pair(-1, -11), Pair(3, -5), Pair(3, 2), Pair(0, 2),
        Pair(-1, 4), Pair(2, 6), Pair(-4, 11), Pair(0, 3), Pair(-5, -3), Pair(1, -7), Pair(1, 7), Pair(-2, 0),
        Pair(-1, -1), Pair(1, 7), Pair(-3, 12), Pair(1, 4), Pair(-2, -1), Pair(-1, -1), Pair(4, 2), Pair(-2, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(27, -11), Pair(78, 9), Pair(34, -34), Pair(-109, 49), Pair(-20, 20), Pair(54, -118), Pair(-9, -64), Pair(-43, -67),
        Pair(35, 94), Pair(-53, 24), Pair(-28, 16), Pair(47, 47), Pair(-196, -82), Pair(32, 15), Pair(-68, 16), Pair(39, -46),
        Pair(19, 34), Pair(-11, 29), Pair(38, -41), Pair(-38, -128), Pair(30, 12), Pair(-249, 128), Pair(29, -16), Pair(-56, 17),
        Pair(-21, 59), Pair(0, 27), Pair(2, 23), Pair(-6, -3), Pair(3, 29), Pair(-20, 27), Pair(10, 22), Pair(-13, 9),
        Pair(-4, -4), Pair(-27, 37), Pair(-6, 20), Pair(-10, 1), Pair(-2, 16), Pair(-5, -46), Pair(16, 18), Pair(3, 3),
        Pair(-10, 8), Pair(3, 21), Pair(3, -7), Pair(-2, 32), Pair(-7, 22), Pair(0, 6), Pair(-1, 34), Pair(-6, 36),
        Pair(8, 3), Pair(19, 31), Pair(6, -9), Pair(-5, 18), Pair(-9, 11), Pair(8, 8), Pair(14, -1), Pair(-2, -24),
        Pair(-98, -32), Pair(14, -13), Pair(2, 56), Pair(19, -8), Pair(20, 41), Pair(5, 6), Pair(-3, 10), Pair(29, 26)
      },
      { // Piece 2
        Pair(-3, -19), Pair(91, -38), Pair(-17, 60), Pair(77, -30), Pair(-5, 5), Pair(-64, -83), Pair(22, -43), Pair(-155, 17),
        Pair(-29, 67), Pair(9, 30), Pair(-13, 28), Pair(9, 44), Pair(-3, 31), Pair(-60, 38), Pair(-28, 3), Pair(3, 23),
        Pair(54, 7), Pair(-42, 16), Pair(-27, 32), Pair(-132, 78), Pair(32, 45), Pair(-269, 27), Pair(4, -12), Pair(9, -43),
        Pair(-9, 18), Pair(1, 40), Pair(20, 10), Pair(-44, 49), Pair(25, 15), Pair(-34, 26), Pair(15, 11), Pair(-27, 32),
        Pair(-2, -37), Pair(1, 29), Pair(1, -2), Pair(-3, 24), Pair(-10, 7), Pair(-13, -11), Pair(-6, 29), Pair(-3, -28),
        Pair(14, -12), Pair(1, 3), Pair(-5, 37), Pair(10, 5), Pair(-3, -2), Pair(-1, 4), Pair(-9, 25), Pair(11, -43),
        Pair(-11, -65), Pair(-3, 19), Pair(-5, 34), Pair(-4, 18), Pair(8, -1), Pair(-2, 37), Pair(0, 21), Pair(-8, 48),
        Pair(-16, 30), Pair(5, -5), Pair(-4, 5), Pair(10, -11), Pair(-51, 134), Pair(5, 21), Pair(-65, 39), Pair(48, -4)
      },
      { // Piece 3
        Pair(43, -8), Pair(-108, 39), Pair(-38, 10), Pair(-19, 18), Pair(36, -52), Pair(-4, -35), Pair(65, -17), Pair(-20, 9),
        Pair(11, -11), Pair(18, 25), Pair(22, -11), Pair(27, 20), Pair(49, -23), Pair(42, -52), Pair(69, 25), Pair(-6, 43),
        Pair(51, -12), Pair(-17, 15), Pair(-21, -10), Pair(-19, 9), Pair(53, -48), Pair(185, -134), Pair(33, 6), Pair(-45, -5),
        Pair(-11, 6), Pair(11, -3), Pair(37, -32), Pair(27, -52), Pair(15, 4), Pair(24, -4), Pair(-11, -28), Pair(1, -2),
        Pair(5, -35), Pair(22, -21), Pair(15, 29), Pair(-20, 2), Pair(-19, 8), Pair(-63, 13), Pair(-3, 9), Pair(50, 37),
        Pair(4, 18), Pair(-10, 3), Pair(15, -47), Pair(5, -5), Pair(2, -26), Pair(36, -45), Pair(36, 29), Pair(-14, 1),
        Pair(-32, 27), Pair(-26, 28), Pair(9, 15), Pair(-10, -25), Pair(5, -38), Pair(17, 13), Pair(5, -5), Pair(-15, -5),
        Pair(4, -1), Pair(-1, -1), Pair(5, -4), Pair(-3, -6), Pair(4, 8), Pair(1, 7), Pair(17, -21), Pair(0, -4)
      },
      { // Piece 4
        Pair(76, 14), Pair(-16, 36), Pair(7, 6), Pair(-59, -41), Pair(-98, 75), Pair(-16, -31), Pair(17, 24), Pair(-8, 52),
        Pair(20, -5), Pair(15, -27), Pair(52, -68), Pair(19, -90), Pair(39, 140), Pair(-50, 89), Pair(48, -14), Pair(40, -87),
        Pair(6, -45), Pair(-23, 6), Pair(4, 96), Pair(-37, 72), Pair(27, 17), Pair(69, 45), Pair(55, -26), Pair(6, 18),
        Pair(-19, -2), Pair(-10, 55), Pair(22, -32), Pair(37, -39), Pair(30, 27), Pair(46, -10), Pair(3, 0), Pair(15, 45),
        Pair(5, -15), Pair(13, -9), Pair(7, 7), Pair(6, -43), Pair(1, -1), Pair(11, -42), Pair(3, 24), Pair(44, -1),
        Pair(6, -61), Pair(7, -3), Pair(-8, -9), Pair(-6, -14), Pair(-1, -30), Pair(8, 4), Pair(-20, 8), Pair(5, -65),
        Pair(31, -77), Pair(-6, -32), Pair(1, -11), Pair(-3, 34), Pair(6, -1), Pair(9, -2), Pair(-13, -33), Pair(66, 27),
        Pair(-2, 47), Pair(-14, -9), Pair(-6, -9), Pair(-1, 4), Pair(24, -42), Pair(-33, 3), Pair(-8, -108), Pair(-10, -84)
      },
      { // Piece 5
        Pair(-29, -107), Pair(-23, -19), Pair(-5, 3), Pair(-35, -34), Pair(18, 28), Pair(-11, -87), Pair(14, 63), Pair(12, 29),
        Pair(42, 51), Pair(5, 19), Pair(-39, -76), Pair(-27, -143), Pair(11, -17), Pair(12, -4), Pair(-57, -37), Pair(14, -31),
        Pair(8, 19), Pair(-21, -44), Pair(5, -9), Pair(-8, 30), Pair(52, -122), Pair(3, -40), Pair(-12, -23), Pair(62, -37),
        Pair(32, -5), Pair(-81, 17), Pair(-102, -1), Pair(-34, -72), Pair(-46, -33), Pair(92, -27), Pair(-96, 23), Pair(-53, -19),
        Pair(-46, -21), Pair(4, -20), Pair(24, -17), Pair(-39, -6), Pair(-60, -6), Pair(-15, 21), Pair(-19, -10), Pair(-24, -12),
        Pair(-24, -39), Pair(-58, 2), Pair(-12, -11), Pair(-17, 6), Pair(44, -3), Pair(-33, 20), Pair(48, -13), Pair(3, -2),
        Pair(-90, 31), Pair(11, -2), Pair(-57, 43), Pair(6, 10), Pair(-11, 24), Pair(-9, 21), Pair(-5, 3), Pair(4, -3),
        Pair(-25, 23), Pair(-1, -27), Pair(-9, -11), Pair(3, 9), Pair(7, 19), Pair(23, -13), Pair(2, -1), Pair(-6, -6)
      }
    }},
    {{ // Bucket 53
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-42, 40), Pair(-33, 47), Pair(27, 14), Pair(-22, 8), Pair(3, -16), Pair(31, 63), Pair(-99, -30), Pair(-25, 4),
        Pair(-3, 19), Pair(4, 19), Pair(1, 24), Pair(2, -6), Pair(36, 72), Pair(-13, 1), Pair(23, 38), Pair(14, 1),
        Pair(0, 4), Pair(2, 5), Pair(8, 5), Pair(3, -6), Pair(9, 8), Pair(-2, -5), Pair(-5, 7), Pair(0, -4),
        Pair(2, -1), Pair(4, 3), Pair(3, 1), Pair(4, -2), Pair(4, -1), Pair(-2, -2), Pair(1, -3), Pair(-3, 2),
        Pair(1, 1), Pair(4, -1), Pair(2, 3), Pair(-2, 2), Pair(1, 4), Pair(-3, 0), Pair(-1, -2), Pair(-2, 0),
        Pair(2, 3), Pair(2, 1), Pair(2, 2), Pair(2, -2), Pair(4, 1), Pair(2, 1), Pair(0, -3), Pair(-5, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(13, -58), Pair(-26, -7), Pair(-136, 39), Pair(-67, 8), Pair(-14, 6), Pair(-13, -109), Pair(18, 75), Pair(-14, -3),
        Pair(-39, 9), Pair(23, 8), Pair(5, 1), Pair(-25, 22), Pair(-36, 13), Pair(-43, -58), Pair(-5, -22), Pair(27, 23),
        Pair(-38, 37), Pair(7, 12), Pair(2, 25), Pair(12, -2), Pair(-284, 115), Pair(27, 36), Pair(-103, 51), Pair(-49, 10),
        Pair(9, -2), Pair(1, 5), Pair(3, 1), Pair(-5, 17), Pair(-25, 12), Pair(9, 38), Pair(-8, -7), Pair(-24, 10),
        Pair(3, -8), Pair(3, 23), Pair(8, 14), Pair(-5, 14), Pair(-17, 5), Pair(-9, 3), Pair(-7, 10), Pair(5, -4),
        Pair(10, 10), Pair(-3, 13), Pair(3, 16), Pair(-8, 3), Pair(3, 13), Pair(1, 1), Pair(-2, 13), Pair(-6, -3),
        Pair(-14, -37), Pair(-30, 6), Pair(8, 16), Pair(0, 10), Pair(-2, 11), Pair(7, 22), Pair(10, -10), Pair(-6, 10),
        Pair(-19, 7), Pair(5, 25), Pair(-14, 9), Pair(-5, 21), Pair(1, 4), Pair(8, 15), Pair(-1, 3), Pair(-6, -37)
      },
      { // Piece 2
        Pair(10, 42), Pair(28, 8), Pair(-112, 64), Pair(-44, 36), Pair(-97, 25), Pair(-16, -13), Pair(-57, -55), Pair(-30, 26),
        Pair(-24, 29), Pair(-21, 29), Pair(-9, 16), Pair(-91, 62), Pair(-8, 47), Pair(-88, 74), Pair(19, 20), Pair(7, -7),
        Pair(-9, 27), Pair(9, 35), Pair(-20, 12), Pair(5, 33), Pair(-74, -78), Pair(35, 37), Pair(-82, 85), Pair(9, 7),
        Pair(-1, 17), Pair(-5, 22), Pair(-12, 34), Pair(-6, 16), Pair(-24, 27), Pair(-6, 30), Pair(-14, 8), Pair(-8, -10),
        Pair(-1, 6), Pair(2, 20), Pair(-14, 12), Pair(2, 22), Pair(-23, 7), Pair(7, 28), Pair(-17, 12), Pair(3, 26),
        Pair(-3, 14), Pair(-1, 11), Pair(3, 15), Pair(-10, 7), Pair(0, 15), Pair(-4, 7), Pair(4, 21), Pair(-11, -11),
        Pair(-6, 15), Pair(3, 9), Pair(-17, 20), Pair(4, 14), Pair(-6, 6), Pair(1, 30), Pair(0, 1), Pair(-6, 35),
        Pair(3, 8), Pair(-21, 60), Pair(5, 14), Pair(-2, 19), Pair(-5, 19), Pair(-2, 20), Pair(-3, 54), Pair(-9, 39)
      },
      { // Piece 3
        Pair(-23, 10), Pair(-29, 23), Pair(-11, 23), Pair(-5, 17), Pair(-41, 20), Pair(-73, 9), Pair(22, 3), Pair(-24, 17),
        Pair(-5, 12), Pair(-16, 10), Pair(6, 4), Pair(6, 15), Pair(-27, 14), Pair(82, -56), Pair(-61, 12), Pair(4, 7),
        Pair(-8, 23), Pair(10, 14), Pair(-14, 15), Pair(13, 0), Pair(-72, 15), Pair(22, -7), Pair(174, -89), Pair(25, -2),
        Pair(-7, 10), Pair(-12, 9), Pair(-7, 22), Pair(-6, 20), Pair(-6, 17), Pair(19, -4), Pair(33, -15), Pair(0, -3),
        Pair(-1, 17), Pair(-2, 8), Pair(2, -7), Pair(-10, 17), Pair(-21, 14), Pair(-4, -2), Pair(-5, -17), Pair(-1, -4),
        Pair(20, -2), Pair(6, 13), Pair(-2, 27), Pair(21, 6), Pair(-3, 1), Pair(-1, 4), Pair(7, 6), Pair(10, -5),
        Pair(-13, 14), Pair(-9, 22), Pair(-16, 22), Pair(-3, 6), Pair(-3, 5), Pair(7, -3), Pair(16, -15), Pair(5, 27),
        Pair(4, 16), Pair(-1, 14), Pair(-1, 12), Pair(2, 5), Pair(3, 2), Pair(3, 10), Pair(10, 0), Pair(-2, -1)
      },
      { // Piece 4
        Pair(22, 12), Pair(14, -3), Pair(11, -16), Pair(-27, 6), Pair(-4, -41), Pair(-52, -27), Pair(-34, 55), Pair(68, -27),
        Pair(-4, -3), Pair(-5, -4), Pair(1, -39), Pair(60, -55), Pair(-15, -28), Pair(29, -63), Pair(-10, 54), Pair(-33, 26),
        Pair(1, 1), Pair(-15, 33), Pair(8, 7), Pair(3, -4), Pair(28, 31), Pair(34, -19), Pair(-63, -7), Pair(19, 22),
        Pair(-3, -23), Pair(0, 11), Pair(6, 21), Pair(2, 14), Pair(3, 18), Pair(31, -21), Pair(33, 5), Pair(17, -1),
        Pair(-11, -12), Pair(-10, -20), Pair(-11, 9), Pair(9, -3), Pair(-4, -1), Pair(10, 3), Pair(17, 19), Pair(15, 1),
        Pair(4, -40), Pair(-6, 3), Pair(-2, -3), Pair(-6, 13), Pair(-5, -14), Pair(7, -19), Pair(0, 11), Pair(9, -15),
        Pair(-13, 3), Pair(-1, -15), Pair(-1, -4), Pair(-3, -12), Pair(-4, -8), Pair(13, -36), Pair(10, 11), Pair(21, -64),
        Pair(-5, 8), Pair(-18, 23), Pair(5, -20), Pair(0, -9), Pair(2, -8), Pair(2, -1), Pair(6, -71), Pair(45, 76)
      },
      { // Piece 5
        Pair(88, -8), Pair(-32, -9), Pair(33, -18), Pair(-22, -32), Pair(-74, -65), Pair(13, -98), Pair(-35, -40), Pair(-16, -55),
        Pair(-5, -33), Pair(19, -63), Pair(87, -16), Pair(-22, -8), Pair(-17, -98), Pair(-16, -31), Pair(-2, -108), Pair(-26, -33),
        Pair(121, -18), Pair(-36, -32), Pair(23, -22), Pair(-52, -26), Pair(-22, -98), Pair(-122, -86), Pair(-20, -38), Pair(40, -65),
        Pair(36, -13), Pair(-10, -17), Pair(7, -21), Pair(-43, -42), Pair(-83, -38), Pair(-15, -52), Pair(-75, -23), Pair(-83, 0),
        Pair(-32, -44), Pair(-3, -14), Pair(75, -30), Pair(-24, -18), Pair(-53, -7), Pair(-28, -24), Pair(-26, -6), Pair(-29, -28),
        Pair(-31, -8), Pair(37, -19), Pair(7, -12), Pair(-12, -4), Pair(-3, 7), Pair(8, 3), Pair(8, 7), Pair(0, -6),
        Pair(26, -12), Pair(20, -7), Pair(0, 6), Pair(-4, 1), Pair(-6, 19), Pair(3, 6), Pair(-5, 16), Pair(6, -5),
        Pair(-4, -14), Pair(-4, 5), Pair(-1, -3), Pair(-8, -18), Pair(1, -13), Pair(-1, 25), Pair(1, -5), Pair(16, -13)
      }
    }},
    {{ // Bucket 54
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(50, 14), Pair(-9, 52), Pair(-28, 51), Pair(-33, 11), Pair(25, -40), Pair(-82, 7), Pair(60, 17), Pair(-66, -44),
        Pair(9, 11), Pair(4, 27), Pair(23, 16), Pair(-25, 24), Pair(11, 12), Pair(-43, 61), Pair(25, 4), Pair(43, 7),
        Pair(3, 0), Pair(6, 4), Pair(7, 0), Pair(1, 4), Pair(-11, 0), Pair(1, 8), Pair(13, -3), Pair(4, 9),
        Pair(-1, 0), Pair(-1, -2), Pair(0, 0), Pair(-4, 0), Pair(6, -2), Pair(0, 2), Pair(-7, -2), Pair(1, 0),
        Pair(-1, 0), Pair(0, 0), Pair(-1, 0), Pair(-1, -1), Pair(1, -1), Pair(0, 7), Pair(0, 3), Pair(-2, 2),
        Pair(-1, 2), Pair(0, 1), Pair(-2, 0), Pair(2, -4), Pair(0, 1), Pair(2, 6), Pair(-1, 1), Pair(-5, 4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-43, -9), Pair(-45, 35), Pair(-98, 34), Pair(-127, 82), Pair(-65, -25), Pair(36, 9), Pair(-22, 22), Pair(-6, 19),
        Pair(-8, -18), Pair(11, -6), Pair(5, -2), Pair(-4, -6), Pair(-9, 15), Pair(41, -24), Pair(-28, 54), Pair(-16, -29),
        Pair(-50, 9), Pair(-12, 15), Pair(3, 8), Pair(-7, 6), Pair(31, -14), Pair(-295, 249), Pair(11, 45), Pair(32, -15),
        Pair(1, -10), Pair(8, 1), Pair(-8, 13), Pair(21, 13), Pair(4, 12), Pair(-31, 11), Pair(2, 17), Pair(9, -18),
        Pair(-1, 2), Pair(0, 16), Pair(6, 2), Pair(2, 2), Pair(14, 8), Pair(-21, 0), Pair(27, -14), Pair(-13, 15),
        Pair(3, 8), Pair(0, 11), Pair(3, 6), Pair(-1, 6), Pair(-3, 1), Pair(2, 6), Pair(0, 4), Pair(-13, -13),
        Pair(-21, 6), Pair(10, 9), Pair(-2, -1), Pair(-1, 6), Pair(-3, 0), Pair(-9, -11), Pair(0, 2), Pair(-1, 32),
        Pair(5, -11), Pair(6, 7), Pair(-2, -27), Pair(12, 6), Pair(2, 3), Pair(4, -11), Pair(1, 32), Pair(-54, -69)
      },
      { // Piece 2
        Pair(-37, 48), Pair(23, 13), Pair(40, 2), Pair(-89, 70), Pair(-9, 21), Pair(-92, 3), Pair(45, 15), Pair(3, 7),
        Pair(-33, 11), Pair(-6, 34), Pair(5, 10), Pair(-58, 24), Pair(-41, 1), Pair(-8, 32), Pair(25, 43), Pair(-8, 1),
        Pair(14, 13), Pair(-64, 36), Pair(11, 27), Pair(-10, 20), Pair(-23, 45), Pair(-227, 143), Pair(11, 56), Pair(4, 30),
        Pair(-29, 27), Pair(5, 19), Pair(-17, 12), Pair(2, 29), Pair(0, 3), Pair(-45, 48), Pair(15, -1), Pair(-14, 1),
        Pair(0, 3), Pair(-14, -5), Pair(8, 33), Pair(-1, -2), Pair(2, 12), Pair(-14, -3), Pair(-8, 20), Pair(-19, -24),
        Pair(-18, 15), Pair(-1, 15), Pair(-8, -11), Pair(0, 14), Pair(-6, 8), Pair(6, 6), Pair(-4, 14), Pair(3, 27),
        Pair(-5, 37), Pair(-10, -2), Pair(9, 2), Pair(-7, 0), Pair(4, 12), Pair(-19, 20), Pair(7, 29), Pair(-9, 49),
        Pair(-16, -10), Pair(3, -6), Pair(-6, 6), Pair(-7, 11), Pair(-10, 2), Pair(7, 18), Pair(-17, 25), Pair(-11, 22)
      },
      { // Piece 3
        Pair(12, 17), Pair(-7, 31), Pair(-53, 39), Pair(16, 19), Pair(7, 12), Pair(-7, 11), Pair(103, -12), Pair(-70, 60),
        Pair(-13, 19), Pair(3, 26), Pair(-2, 33), Pair(-15, 23), Pair(-18, 32), Pair(-10, 3), Pair(17, -63), Pair(-43, -25),
        Pair(-10, 15), Pair(-24, 24), Pair(-12, 25), Pair(0, 9), Pair(16, 7), Pair(-15, 9), Pair(5, 1), Pair(251, -56),
        Pair(2, 10), Pair(-3, 25), Pair(1, 14), Pair(3, 9), Pair(4, 21), Pair(-11, 8), Pair(-32, 39), Pair(11, 10),
        Pair(-2, 12), Pair(-14, 16), Pair(4, 14), Pair(-9, 17), Pair(-2, 10), Pair(-16, 0), Pair(-9, 5), Pair(18, 3),
        Pair(4, 16), Pair(7, -4), Pair(-2, 11), Pair(-2, 12), Pair(4, 11), Pair(8, 8), Pair(-4, 4), Pair(1, 21),
        Pair(10, 17), Pair(-4, 30), Pair(7, 15), Pair(5, 8), Pair(17, 4), Pair(16, 9), Pair(-7, 1), Pair(19, -39),
        Pair(3, 16), Pair(1, 13), Pair(-2, 12), Pair(0, 12), Pair(1, 14), Pair(-1, 6), Pair(4, -1), Pair(-6, 12)
      },
      { // Piece 4
        Pair(-66, 14), Pair(-32, 21), Pair(-36, 36), Pair(-17, 30), Pair(10, 0), Pair(8, 22), Pair(19, -59), Pair(27, -57),
        Pair(-12, 15), Pair(-4, 14), Pair(-20, 22), Pair(-41, 16), Pair(-53, 26), Pair(7, -63), Pair(61, -8), Pair(48, -28),
        Pair(0, -12), Pair(5, -7), Pair(0, -21), Pair(-24, 21), Pair(26, -38), Pair(-23, -71), Pair(37, 32), Pair(14, -46),
        Pair(-10, 11), Pair(-8, 5), Pair(-7, 9), Pair(-5, 18), Pair(-8, 12), Pair(-23, 45), Pair(3, -20), Pair(4, 7),
        Pair(2, -1), Pair(-20, 34), Pair(-2, 5), Pair(-8, 14), Pair(-9, 13), Pair(11, -8), Pair(-2, -15), Pair(23, 0),
        Pair(2, -10), Pair(-4, -7), Pair(-3, -14), Pair(-7, 4), Pair(-11, 14), Pair(0, 13), Pair(8, 1), Pair(22, -37),
        Pair(-10, -27), Pair(-8, 2), Pair(-2, -7), Pair(-5, 13), Pair(-5, -8), Pair(-6, -5), Pair(3, -26), Pair(12, 25),
        Pair(2, -8), Pair(-14, -21), Pair(1, -11), Pair(-2, 4), Pair(-1, 17), Pair(-16, 22), Pair(41, -101), Pair(16, -57)
      },
      { // Piece 5
        Pair(59, 41), Pair(27, -62), Pair(1, -75), Pair(-9, 8), Pair(68, -45), Pair(65, -40), Pair(33, -24), Pair(5, -19),
        Pair(3, -17), Pair(18, -75), Pair(-15, -56), Pair(53, -21), Pair(-20, -37), Pair(64, -105), Pair(4, 14), Pair(-7, -119),
        Pair(-41, 20), Pair(48, -40), Pair(66, -42), Pair(-34, -10), Pair(2, -52), Pair(16, -20), Pair(39, -88), Pair(-27, -105),
        Pair(-65, -3), Pair(28, -26), Pair(23, -22), Pair(-10, -33), Pair(-157, -15), Pair(-67, -21), Pair(0, -59), Pair(-19, -39),
        Pair(-28, -2), Pair(-2, -14), Pair(21, -28), Pair(-44, -23), Pair(8, -21), Pair(-2, -9), Pair(-32, -10), Pair(-77, 10),
        Pair(5, -12), Pair(0, -10), Pair(-16, -24), Pair(10, -17), Pair(-4, -14), Pair(8, 0), Pair(-28, -1), Pair(-10, 9),
        Pair(-23, -11), Pair(21, -24), Pair(-14, -15), Pair(-20, -14), Pair(2, -7), Pair(-8, 7), Pair(-10, -2), Pair(-14, 2),
        Pair(12, 1), Pair(-6, -16), Pair(-15, -16), Pair(8, -27), Pair(2, -13), Pair(-9, 0), Pair(-1, 6), Pair(-4, -17)
      }
    }},
    {{ // Bucket 55
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(35, 33), Pair(8, 38), Pair(-14, 12), Pair(-18, 54), Pair(-30, -2), Pair(-2, 29), Pair(-51, -11), Pair(32, 120),
        Pair(18, 10), Pair(-2, 13), Pair(-4, 35), Pair(-4, 15), Pair(-22, -5), Pair(-27, -1), Pair(35, 21), Pair(50, -34),
        Pair(3, 4), Pair(1, 0), Pair(1, 8), Pair(-3, 1), Pair(-3, 1), Pair(-7, -10), Pair(3, 2), Pair(14, -14),
        Pair(1, 1), Pair(5, -8), Pair(-1, -4), Pair(2, -1), Pair(3, 4), Pair(3, 0), Pair(4, -4), Pair(-3, -1),
        Pair(1, -2), Pair(0, -6), Pair(-2, -2), Pair(-1, -2), Pair(3, 0), Pair(6, -4), Pair(4, -1), Pair(1, -1),
        Pair(0, -2), Pair(0, -2), Pair(-3, -4), Pair(1, -2), Pair(0, 3), Pair(5, -3), Pair(3, 0), Pair(-1, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-29, -13), Pair(25, -53), Pair(-5, -43), Pair(29, -17), Pair(-58, 21), Pair(-89, -24), Pair(-15, -16), Pair(-12, -29),
        Pair(-4, -16), Pair(-33, 21), Pair(-4, -14), Pair(53, -7), Pair(-41, 52), Pair(14, 32), Pair(26, 6), Pair(-19, -12),
        Pair(12, -20), Pair(0, -10), Pair(-2, 8), Pair(13, -7), Pair(-2, -13), Pair(-12, -15), Pair(-127, -119), Pair(-15, 64),
        Pair(7, 15), Pair(5, -8), Pair(20, 2), Pair(5, 7), Pair(5, -2), Pair(17, -2), Pair(-17, 2), Pair(1, 22),
        Pair(2, -12), Pair(-15, -13), Pair(1, -3), Pair(7, 0), Pair(7, 2), Pair(15, 6), Pair(-16, 2), Pair(1, -12),
        Pair(-3, -5), Pair(8, -23), Pair(4, -11), Pair(5, -9), Pair(10, 4), Pair(4, 2), Pair(6, 2), Pair(3, 45),
        Pair(-19, 5), Pair(-2, -30), Pair(-5, -15), Pair(0, -3), Pair(-6, 10), Pair(1, -4), Pair(11, 2), Pair(-6, 5),
        Pair(2, -39), Pair(-5, 13), Pair(-26, 2), Pair(9, -25), Pair(-3, -4), Pair(-11, 16), Pair(-10, -3), Pair(5, 78)
      },
      { // Piece 2
        Pair(21, 28), Pair(-11, 12), Pair(-21, 59), Pair(-11, 38), Pair(-43, 21), Pair(-67, 48), Pair(-14, 50), Pair(20, -32),
        Pair(-18, -2), Pair(3, 35), Pair(-17, 31), Pair(-34, 40), Pair(-11, 4), Pair(-5, 22), Pair(-42, 12), Pair(1, -6),
        Pair(-19, 14), Pair(8, 9), Pair(-37, 48), Pair(-1, 31), Pair(-11, 3), Pair(2, 12), Pair(19, -121), Pair(-5, 53),
        Pair(-6, 6), Pair(1, 13), Pair(-12, 28), Pair(8, 26), Pair(11, 15), Pair(-30, 49), Pair(-19, 19), Pair(-15, 44),
        Pair(6, 0), Pair(-5, -5), Pair(3, 13), Pair(-3, 18), Pair(-2, 9), Pair(8, 11), Pair(2, -20), Pair(2, 0),
        Pair(-5, 1), Pair(15, 22), Pair(4, 20), Pair(-5, 11), Pair(1, 12), Pair(3, 18), Pair(1, 21), Pair(7, 14),
        Pair(8, 15), Pair(2, 10), Pair(-5, 2), Pair(-8, 8), Pair(-2, 9), Pair(1, -1), Pair(10, 10), Pair(14, -6),
        Pair(-1, 8), Pair(10, 8), Pair(-4, 6), Pair(-5, 10), Pair(-10, 16), Pair(-3, 13), Pair(13, 3), Pair(-27, 89)
      },
      { // Piece 3
        Pair(24, 12), Pair(14, 32), Pair(10, 35), Pair(29, 17), Pair(-61, 43), Pair(-3, 20), Pair(24, 91), Pair(-164, 46),
        Pair(13, 20), Pair(-13, 30), Pair(4, 22), Pair(28, 10), Pair(3, 13), Pair(-15, 40), Pair(36, 38), Pair(4, -27),
        Pair(-14, 21), Pair(5, 28), Pair(10, 22), Pair(-8, 16), Pair(16, 9), Pair(-40, 29), Pair(-110, 16), Pair(-12, 45),
        Pair(-12, 31), Pair(-3, 26), Pair(-1, 12), Pair(5, 22), Pair(1, 23), Pair(9, 11), Pair(-8, 49), Pair(-9, 33),
        Pair(2, 20), Pair(-7, 9), Pair(0, 19), Pair(-3, 31), Pair(0, 36), Pair(-18, 32), Pair(-72, 22), Pair(-2, 4),
        Pair(-6, 29), Pair(2, 25), Pair(4, 20), Pair(6, 30), Pair(-5, 18), Pair(-3, 21), Pair(6, 15), Pair(-18, 17),
        Pair(30, -19), Pair(-16, 21), Pair(17, 11), Pair(-1, 28), Pair(-8, 23), Pair(-4, 27), Pair(-14, 33), Pair(3, 30),
        Pair(2, 19), Pair(0, 29), Pair(6, 14), Pair(7, 16), Pair(1, 15), Pair(3, 13), Pair(-11, 14), Pair(-2, 24)
      },
      { // Piece 4
        Pair(20, 26), Pair(-9, 66), Pair(57, 16), Pair(-14, 80), Pair(38, 22), Pair(-56, 99), Pair(41, -19), Pair(-59, 59),
        Pair(-16, 38), Pair(-4, 35), Pair(-7, 19), Pair(-32, 63), Pair(-10, 69), Pair(-33, 77), Pair(18, 35), Pair(-41, -117),
        Pair(4, 25), Pair(4, -3), Pair(-1, 35), Pair(1, 34), Pair(6, 75), Pair(-4, 64), Pair(64, 40), Pair(5, 20),
        Pair(3, 26), Pair(-16, 22), Pair(9, 38), Pair(-7, 59), Pair(1, 56), Pair(-7, 25), Pair(-17, 37), Pair(-13, 46),
        Pair(-5, 22), Pair(14, 11), Pair(5, 5), Pair(6, 25), Pair(-10, 48), Pair(-10, 25), Pair(-5, 8), Pair(-18, 5),
        Pair(-4, 33), Pair(-3, 13), Pair(4, 18), Pair(1, 23), Pair(-4, 36), Pair(2, 5), Pair(-13, 25), Pair(-11, 19),
        Pair(10, 3), Pair(-2, 8), Pair(3, 8), Pair(2, 4), Pair(0, 4), Pair(-1, 15), Pair(16, 6), Pair(-23, -37),
        Pair(5, 12), Pair(-2, -7), Pair(1, 13), Pair(1, 12), Pair(2, 9), Pair(-12, 1), Pair(-31, 39), Pair(39, 48)
      },
      { // Piece 5
        Pair(-3, -109), Pair(-17, -68), Pair(71, -61), Pair(-17, -80), Pair(1, 51), Pair(-37, -140), Pair(-16, -75), Pair(22, 13),
        Pair(5, -67), Pair(66, -85), Pair(28, -15), Pair(-42, -36), Pair(32, -6), Pair(-60, -111), Pair(-5, -78), Pair(-11, -69),
        Pair(92, -15), Pair(-35, 8), Pair(16, -30), Pair(15, -42), Pair(-64, -57), Pair(13, -42), Pair(23, -12), Pair(-36, -71),
        Pair(82, -64), Pair(15, -39), Pair(5, -14), Pair(-17, -10), Pair(43, -14), Pair(-6, -6), Pair(-6, -26), Pair(5, -27),
        Pair(-10, 5), Pair(-15, -33), Pair(43, -27), Pair(-13, -8), Pair(-8, -6), Pair(-56, 0), Pair(-57, 2), Pair(43, -39),
        Pair(-39, -31), Pair(17, -29), Pair(12, -30), Pair(56, -25), Pair(11, -18), Pair(-22, -8), Pair(3, 6), Pair(-46, 17),
        Pair(27, 5), Pair(-17, -18), Pair(-15, -24), Pair(4, -14), Pair(1, -17), Pair(5, -8), Pair(-17, 21), Pair(-13, 16),
        Pair(-9, 0), Pair(-12, -14), Pair(-2, -22), Pair(21, -19), Pair(7, -4), Pair(-11, 0), Pair(3, 8), Pair(-2, 31)
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
        Pair(2, -30), Pair(-10, 27), Pair(-58, 2), Pair(-15, 19), Pair(-4, 3), Pair(30, -25), Pair(-19, 9), Pair(-76, -2),
        Pair(-24, 61), Pair(-15, 14), Pair(-25, 21), Pair(15, -5), Pair(-2, -8), Pair(4, -8), Pair(-10, -6), Pair(-6, -11),
        Pair(-15, 10), Pair(-6, 2), Pair(0, 5), Pair(-7, 7), Pair(4, -2), Pair(2, 6), Pair(-2, 5), Pair(-3, 8),
        Pair(10, 7), Pair(-5, 12), Pair(3, 4), Pair(1, 7), Pair(2, 5), Pair(-1, 5), Pair(0, 9), Pair(0, 7),
        Pair(6, 10), Pair(0, 9), Pair(-1, 4), Pair(1, 5), Pair(-1, 6), Pair(3, 10), Pair(1, 8), Pair(-1, 12),
        Pair(3, 1), Pair(-2, 0), Pair(-2, 3), Pair(-1, 2), Pair(-3, 5), Pair(-1, 7), Pair(1, 11), Pair(0, 10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-96, -24), Pair(44, 42), Pair(-65, 21), Pair(3, 43), Pair(-15, 95), Pair(-3, 17), Pair(-91, -15), Pair(-64, -8),
        Pair(10, -22), Pair(-22, 48), Pair(-42, 37), Pair(-24, 12), Pair(-6, 46), Pair(-4, 41), Pair(-40, 31), Pair(7, 19),
        Pair(35, 43), Pair(-1, 19), Pair(-8, 22), Pair(-12, 26), Pair(18, -9), Pair(-41, 45), Pair(2, 44), Pair(6, -9),
        Pair(7, 14), Pair(6, 10), Pair(-11, 15), Pair(2, 14), Pair(-2, 26), Pair(-8, 15), Pair(1, 18), Pair(1, 24),
        Pair(-3, 8), Pair(8, 15), Pair(-5, 26), Pair(-1, 15), Pair(-3, 19), Pair(15, 12), Pair(-11, 23), Pair(5, 18),
        Pair(-14, -6), Pair(5, 13), Pair(2, 15), Pair(11, 2), Pair(14, 18), Pair(3, 10), Pair(0, 22), Pair(5, 37),
        Pair(-31, 21), Pair(8, 10), Pair(-10, 5), Pair(-2, 10), Pair(6, 9), Pair(-10, 10), Pair(-12, 13), Pair(-1, 6),
        Pair(3, 43), Pair(-7, -27), Pair(14, -36), Pair(6, 32), Pair(-3, 38), Pair(-7, 12), Pair(-4, -8), Pair(-22, 5)
      },
      { // Piece 2
        Pair(-56, 1), Pair(41, -19), Pair(63, 24), Pair(-16, -32), Pair(121, -33), Pair(-5, -12), Pair(31, 10), Pair(-11, -23),
        Pair(-48, -9), Pair(-10, 5), Pair(13, -3), Pair(23, -3), Pair(10, -1), Pair(-32, 5), Pair(0, 30), Pair(-30, -27),
        Pair(29, -6), Pair(-3, 29), Pair(42, -12), Pair(-3, -8), Pair(14, -29), Pair(7, -17), Pair(-19, -26), Pair(-8, -8),
        Pair(-13, 15), Pair(4, 15), Pair(11, -9), Pair(10, -24), Pair(6, 5), Pair(23, -11), Pair(7, 9), Pair(-2, 2),
        Pair(-9, 34), Pair(12, 2), Pair(-8, 13), Pair(4, -11), Pair(0, 3), Pair(4, -4), Pair(-8, -2), Pair(8, 21),
        Pair(-4, 10), Pair(17, 10), Pair(-1, 0), Pair(0, 5), Pair(6, 6), Pair(2, 17), Pair(5, 8), Pair(13, -1),
        Pair(53, -25), Pair(4, -1), Pair(3, 11), Pair(3, 5), Pair(0, 17), Pair(-3, 2), Pair(3, 14), Pair(7, -7),
        Pair(8, -45), Pair(-12, -24), Pair(-1, 15), Pair(14, 15), Pair(3, -10), Pair(-1, 9), Pair(19, -17), Pair(-5, 17)
      },
      { // Piece 3
        Pair(-8, -43), Pair(25, 2), Pair(-80, 31), Pair(-26, 34), Pair(-19, 13), Pair(-57, 17), Pair(-40, 14), Pair(-29, 8),
        Pair(-15, -6), Pair(-28, 29), Pair(-10, 14), Pair(-14, 16), Pair(-16, 12), Pair(-49, 24), Pair(-10, 14), Pair(28, 0),
        Pair(-17, 9), Pair(4, 12), Pair(0, -6), Pair(-19, 13), Pair(4, 9), Pair(-1, 21), Pair(28, -3), Pair(27, 14),
        Pair(-23, 13), Pair(8, -4), Pair(1, 26), Pair(-6, 19), Pair(-5, 3), Pair(-2, 38), Pair(16, -6), Pair(17, 2),
        Pair(0, 0), Pair(29, -6), Pair(2, 27), Pair(3, 13), Pair(-3, 5), Pair(3, 6), Pair(29, 1), Pair(-7, 18),
        Pair(-9, 2), Pair(5, -9), Pair(-14, 30), Pair(2, 12), Pair(5, -13), Pair(-8, 10), Pair(-13, 8), Pair(6, 12),
        Pair(89, -49), Pair(2, 22), Pair(-5, 17), Pair(-9, 21), Pair(0, 21), Pair(7, 4), Pair(0, -9), Pair(34, 4),
        Pair(-6, -4), Pair(2, -5), Pair(1, 7), Pair(4, 15), Pair(4, 4), Pair(-2, 7), Pair(3, 13), Pair(5, 5)
      },
      { // Piece 4
        Pair(-37, -21), Pair(25, -38), Pair(-9, -5), Pair(-66, 15), Pair(-15, 8), Pair(-1, 29), Pair(32, 54), Pair(17, 32),
        Pair(-5, 8), Pair(-13, 5), Pair(-28, 8), Pair(0, 28), Pair(-18, 17), Pair(-74, 18), Pair(-2, 4), Pair(37, -20),
        Pair(3, 3), Pair(-8, 0), Pair(-24, 21), Pair(16, -29), Pair(14, -14), Pair(-22, 36), Pair(-30, -21), Pair(-4, -59),
        Pair(10, -5), Pair(8, 45), Pair(-25, 4), Pair(-9, -12), Pair(35, -51), Pair(-2, -21), Pair(-13, 16), Pair(4, 45),
        Pair(-2, -14), Pair(7, -24), Pair(9, 0), Pair(0, 15), Pair(-9, 19), Pair(-3, -15), Pair(4, -10), Pair(6, -42),
        Pair(-27, 18), Pair(5, 9), Pair(11, -1), Pair(-1, 24), Pair(5, 6), Pair(0, 23), Pair(9, 31), Pair(-3, -15),
        Pair(4, -35), Pair(13, -7), Pair(5, 3), Pair(4, 13), Pair(3, 7), Pair(8, 2), Pair(9, -4), Pair(-13, -22),
        Pair(-30, 40), Pair(4, -7), Pair(7, 2), Pair(2, 15), Pair(-9, 1), Pair(4, 5), Pair(-18, 15), Pair(24, -6)
      },
      { // Piece 5
        Pair(-26, -12), Pair(-5, 117), Pair(34, 85), Pair(57, 95), Pair(5, 76), Pair(72, 194), Pair(-8, 42), Pair(-3, 38),
        Pair(7, 5), Pair(2, 138), Pair(-93, 99), Pair(62, 77), Pair(-99, 9), Pair(-33, -5), Pair(-9, -2), Pair(20, -25),
        Pair(-78, 35), Pair(44, 83), Pair(124, 50), Pair(-80, 62), Pair(30, 26), Pair(-61, 51), Pair(-32, 10), Pair(-55, -9),
        Pair(-68, 66), Pair(-135, 101), Pair(-59, 49), Pair(-75, 49), Pair(-8, 32), Pair(-51, 35), Pair(-139, 38), Pair(-131, 59),
        Pair(-13, 15), Pair(-11, 73), Pair(-95, 54), Pair(-24, 29), Pair(-90, 38), Pair(-28, 19), Pair(-77, 23), Pair(-93, 22),
        Pair(-22, 30), Pair(-29, 37), Pair(23, 0), Pair(-17, 18), Pair(-19, 30), Pair(-33, 20), Pair(-20, 8), Pair(-75, 18),
        Pair(-8, 45), Pair(17, -7), Pair(25, -13), Pair(0, -8), Pair(-2, 9), Pair(-10, 8), Pair(-1, 11), Pair(-2, -1),
        Pair(2, -76), Pair(39, -22), Pair(53, -15), Pair(-17, 19), Pair(2, -8), Pair(-9, 11), Pair(-1, 2), Pair(0, -11)
      }
    }},
    {{ // Bucket 9
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-52, 13), Pair(2, -7), Pair(-52, -12), Pair(-45, 5), Pair(-44, 13), Pair(-60, -61), Pair(52, -22), Pair(-40, -4),
        Pair(-16, 20), Pair(17, 15), Pair(-32, -19), Pair(-21, 10), Pair(-20, 6), Pair(-25, 16), Pair(-8, -10), Pair(-1, -5),
        Pair(-11, 3), Pair(8, 10), Pair(-7, 9), Pair(-2, 4), Pair(4, -3), Pair(1, 14), Pair(0, 4), Pair(-2, 6),
        Pair(-1, 2), Pair(3, 4), Pair(4, 3), Pair(5, 4), Pair(0, 8), Pair(2, 10), Pair(2, 10), Pair(1, 10),
        Pair(-1, 6), Pair(7, -4), Pair(8, 14), Pair(0, 0), Pair(2, 7), Pair(3, 6), Pair(-1, 11), Pair(1, 8),
        Pair(-2, 0), Pair(4, 8), Pair(7, 4), Pair(5, -42), Pair(0, 5), Pair(0, 8), Pair(0, 13), Pair(0, 12),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-47, 46), Pair(10, 70), Pair(-15, -6), Pair(-152, -14), Pair(-32, 16), Pair(-27, 79), Pair(-36, 62), Pair(-106, 93),
        Pair(-11, -1), Pair(-15, -19), Pair(17, 28), Pair(3, 31), Pair(-60, 44), Pair(-32, 21), Pair(-58, 28), Pair(-79, 106),
        Pair(-23, -28), Pair(6, 10), Pair(8, 10), Pair(-7, 13), Pair(-6, 19), Pair(-55, 60), Pair(-11, 39), Pair(-44, 25),
        Pair(-10, 11), Pair(0, 5), Pair(5, 15), Pair(4, 31), Pair(1, 28), Pair(-19, 11), Pair(-7, 19), Pair(-15, 42),
        Pair(-7, 26), Pair(8, -5), Pair(3, 12), Pair(-1, 25), Pair(-8, 12), Pair(6, 19), Pair(-19, 32), Pair(0, 13),
        Pair(0, 15), Pair(-2, 2), Pair(5, 8), Pair(13, 40), Pair(3, 21), Pair(3, 17), Pair(2, 13), Pair(6, -21),
        Pair(-4, 20), Pair(66, 30), Pair(5, 19), Pair(2, 20), Pair(1, 13), Pair(10, 21), Pair(8, 1), Pair(0, -3),
        Pair(8, 65), Pair(-3, 30), Pair(33, -14), Pair(-2, -6), Pair(6, 26), Pair(2, 33), Pair(1, -4), Pair(77, -60)
      },
      { // Piece 2
        Pair(29, -43), Pair(-71, -39), Pair(7, 6), Pair(-92, 16), Pair(-46, -24), Pair(105, -4), Pair(53, 32), Pair(6, -40),
        Pair(-4, 28), Pair(-19, 9), Pair(-28, 13), Pair(-56, 7), Pair(7, -11), Pair(20, -36), Pair(-3, -39), Pair(-22, -18),
        Pair(4, 13), Pair(16, -11), Pair(15, 5), Pair(9, -22), Pair(12, -36), Pair(-23, 15), Pair(-8, -28), Pair(-11, 1),
        Pair(18, 17), Pair(1, -9), Pair(4, 26), Pair(10, -24), Pair(2, -9), Pair(13, 1), Pair(2, -6), Pair(-3, -17),
        Pair(-3, 8), Pair(4, 19), Pair(-1, -5), Pair(12, -2), Pair(-2, 11), Pair(2, 4), Pair(0, -3), Pair(8, 3),
        Pair(16, 5), Pair(-5, -8), Pair(10, 24), Pair(3, 1), Pair(2, 4), Pair(0, 9), Pair(9, 7), Pair(-1, 11),
        Pair(-3, -20), Pair(-5, 62), Pair(13, 10), Pair(1, 17), Pair(0, 18), Pair(14, -5), Pair(1, 14), Pair(-1, 12),
        Pair(-80, 80), Pair(27, -4), Pair(-6, 6), Pair(2, 17), Pair(-5, 21), Pair(-8, 19), Pair(-27, 19), Pair(5, -23)
      },
      { // Piece 3
        Pair(-48, 28), Pair(1, -20), Pair(42, 1), Pair(-40, 8), Pair(54, -14), Pair(-82, 48), Pair(10, -7), Pair(-14, 13),
        Pair(8, -10), Pair(0, -11), Pair(-8, 15), Pair(-14, 8), Pair(29, -19), Pair(-44, 19), Pair(-50, 21), Pair(56, 1),
        Pair(7, -4), Pair(-18, 12), Pair(-12, 0), Pair(3, 6), Pair(-9, 32), Pair(-90, 27), Pair(-24, -9), Pair(-4, -6),
        Pair(10, -8), Pair(26, -18), Pair(2, -21), Pair(-9, -13), Pair(5, 8), Pair(6, 16), Pair(3, -31), Pair(18, 7),
        Pair(8, 5), Pair(-8, 15), Pair(17, -21), Pair(4, -6), Pair(-9, 14), Pair(-3, 24), Pair(20, -14), Pair(1, 12),
        Pair(0, 10), Pair(-7, -5), Pair(7, 0), Pair(10, 10), Pair(3, 8), Pair(-20, 34), Pair(3, -26), Pair(15, 12),
        Pair(-14, -14), Pair(-25, -40), Pair(-16, 8), Pair(12, -1), Pair(-5, 20), Pair(2, 3), Pair(14, -16), Pair(8, 19),
        Pair(-3, 2), Pair(-12, -13), Pair(-5, 7), Pair(0, 11), Pair(-1, -2), Pair(-2, 2), Pair(9, -3), Pair(4, 9)
      },
      { // Piece 4
        Pair(3, 35), Pair(-35, 41), Pair(-20, -15), Pair(-11, 37), Pair(-143, 57), Pair(-46, 70), Pair(5, -30), Pair(-58, -40),
        Pair(-4, -18), Pair(-14, 8), Pair(-20, 44), Pair(-50, 21), Pair(-30, -18), Pair(-6, -18), Pair(-38, 23), Pair(-3, -16),
        Pair(-1, 0), Pair(-27, 19), Pair(20, -35), Pair(-27, 6), Pair(-27, -15), Pair(-15, 6), Pair(-31, -21), Pair(-1, -5),
        Pair(9, -15), Pair(8, 3), Pair(-12, 18), Pair(-25, 18), Pair(3, -16), Pair(-6, -5), Pair(-6, -44), Pair(-15, -6),
        Pair(-5, -12), Pair(-16, 31), Pair(-4, -8), Pair(-17, 14), Pair(6, 12), Pair(1, 15), Pair(-9, 8), Pair(-9, -13),
        Pair(0, 3), Pair(-7, -10), Pair(-4, 25), Pair(4, 11), Pair(19, 4), Pair(8, 6), Pair(-6, -30), Pair(-5, 24),
        Pair(-5, -10), Pair(-156, 46), Pair(3, 10), Pair(9, 20), Pair(12, 23), Pair(6, 18), Pair(19, 3), Pair(9, 4),
        Pair(12, -41), Pair(17, -26), Pair(3, -5), Pair(1, 13), Pair(3, -1), Pair(17, 23), Pair(37, 58), Pair(32, 23)
      },
      { // Piece 5
        Pair(37, 106), Pair(56, 51), Pair(5, -7), Pair(38, 17), Pair(30, 21), Pair(-20, -20), Pair(21, 11), Pair(-26, -43),
        Pair(54, 65), Pair(-26, 111), Pair(51, 107), Pair(31, 71), Pair(36, 37), Pair(11, 50), Pair(-36, 76), Pair(-27, 58),
        Pair(-57, 106), Pair(9, 51), Pair(40, 60), Pair(-13, 86), Pair(77, -9), Pair(31, 53), Pair(15, 16), Pair(-70, -4),
        Pair(-11, 87), Pair(8, 99), Pair(102, 61), Pair(-15, 35), Pair(-56, 36), Pair(-87, 37), Pair(-84, 10), Pair(-67, -15),
        Pair(49, 30), Pair(-4, 27), Pair(0, 53), Pair(-169, 47), Pair(-93, 38), Pair(-20, 18), Pair(-23, 5), Pair(-35, 12),
        Pair(121, -5), Pair(21, 18), Pair(-53, 48), Pair(-50, 29), Pair(-35, 29), Pair(18, 3), Pair(-7, 9), Pair(-21, 15),
        Pair(105, -26), Pair(157, 66), Pair(12, 4), Pair(3, 26), Pair(8, 5), Pair(-2, 19), Pair(-3, 4), Pair(-7, 4),
        Pair(76, -22), Pair(33, -4), Pair(36, 0), Pair(-4, 17), Pair(11, 1), Pair(-4, 4), Pair(-1, -1), Pair(-1, -9)
      }
    }},
    {{ // Bucket 10
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(51, -4), Pair(-117, 60), Pair(4, 1), Pair(-54, -27), Pair(17, -51), Pair(-25, 17), Pair(22, -62), Pair(-7, 0),
        Pair(-8, 15), Pair(-39, 25), Pair(6, 20), Pair(-13, -30), Pair(25, -30), Pair(1, -21), Pair(29, 12), Pair(-7, 19),
        Pair(10, -8), Pair(-14, 11), Pair(-7, -4), Pair(-6, 1), Pair(6, -2), Pair(-5, 5), Pair(6, -6), Pair(-6, 4),
        Pair(-1, 5), Pair(4, 10), Pair(9, 1), Pair(4, 10), Pair(-1, 3), Pair(-1, 2), Pair(0, 10), Pair(0, 3),
        Pair(-3, 5), Pair(4, 10), Pair(1, -1), Pair(5, 15), Pair(-3, 0), Pair(-2, 8), Pair(-2, 8), Pair(1, 6),
        Pair(-2, 4), Pair(7, 3), Pair(0, 2), Pair(0, 9), Pair(-5, 4), Pair(-5, 9), Pair(-2, 9), Pair(0, 8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-27, -18), Pair(55, -34), Pair(41, -27), Pair(97, 17), Pair(-5, 51), Pair(-73, 23), Pair(-47, 110), Pair(63, -28),
        Pair(9, 34), Pair(23, 16), Pair(44, -29), Pair(-17, 0), Pair(50, 1), Pair(74, -30), Pair(50, 6), Pair(28, -42),
        Pair(2, -25), Pair(11, 28), Pair(-33, 21), Pair(19, 20), Pair(19, 22), Pair(14, -41), Pair(-45, 18), Pair(4, 0),
        Pair(10, -1), Pair(4, 18), Pair(-8, 19), Pair(5, 20), Pair(-2, 22), Pair(10, 30), Pair(-4, 0), Pair(9, 18),
        Pair(2, 32), Pair(17, 32), Pair(3, 7), Pair(0, 30), Pair(4, 25), Pair(-3, 25), Pair(-14, -3), Pair(0, -6),
        Pair(-3, 23), Pair(8, 3), Pair(-1, -1), Pair(-11, 54), Pair(14, 48), Pair(1, 11), Pair(9, 4), Pair(2, -6),
        Pair(13, 18), Pair(33, 11), Pair(-38, -45), Pair(4, 24), Pair(-1, 20), Pair(4, 14), Pair(30, 9), Pair(1, 11),
        Pair(29, -57), Pair(0, 1), Pair(-13, 59), Pair(1, 22), Pair(-2, 14), Pair(-8, 30), Pair(-7, 17), Pair(29, -152)
      },
      { // Piece 2
        Pair(-40, -8), Pair(-104, 52), Pair(20, 9), Pair(34, 32), Pair(50, -16), Pair(-2, 26), Pair(-125, 12), Pair(-73, 14),
        Pair(3, 6), Pair(19, -12), Pair(17, -11), Pair(-2, -14), Pair(39, -68), Pair(32, -9), Pair(14, -10), Pair(72, -42),
        Pair(10, 41), Pair(7, 9), Pair(-13, 7), Pair(7, -8), Pair(16, -2), Pair(25, -4), Pair(40, -8), Pair(-2, -22),
        Pair(18, -6), Pair(12, -13), Pair(-11, 9), Pair(12, -2), Pair(-1, 11), Pair(17, -9), Pair(9, -8), Pair(-6, 3),
        Pair(-6, -17), Pair(17, 10), Pair(8, 11), Pair(26, 3), Pair(6, 16), Pair(7, -1), Pair(6, -20), Pair(-2, 1),
        Pair(13, 8), Pair(2, -9), Pair(9, -22), Pair(1, 35), Pair(-1, 7), Pair(7, 4), Pair(2, 2), Pair(-8, -11),
        Pair(-10, -3), Pair(11, 15), Pair(-35, -42), Pair(8, 11), Pair(0, 9), Pair(5, 6), Pair(1, 14), Pair(-10, 22),
        Pair(4, 15), Pair(-35, -80), Pair(1, 34), Pair(-11, 8), Pair(-33, 51), Pair(-2, 17), Pair(31, 2), Pair(-6, 10)
      },
      { // Piece 3
        Pair(-12, 49), Pair(-54, 45), Pair(127, -45), Pair(-72, 42), Pair(-86, 47), Pair(37, -11), Pair(2, -23), Pair(17, -7),
        Pair(-16, 24), Pair(11, -14), Pair(-50, 29), Pair(9, -1), Pair(-21, -16), Pair(-10, 16), Pair(-3, 0), Pair(-29, 6),
        Pair(18, -5), Pair(6, 9), Pair(14, 20), Pair(1, -2), Pair(-22, 21), Pair(-2, 15), Pair(39, -21), Pair(-11, 4),
        Pair(1, 4), Pair(15, -9), Pair(-4, 28), Pair(13, 12), Pair(-16, 33), Pair(-16, 0), Pair(-44, 27), Pair(-20, 38),
        Pair(7, -9), Pair(8, 22), Pair(60, -1), Pair(-7, 16), Pair(12, 0), Pair(-7, 3), Pair(36, -3), Pair(-7, 39),
        Pair(2, 0), Pair(10, 14), Pair(19, -21), Pair(-2, 14), Pair(12, 9), Pair(-3, 6), Pair(-1, 16), Pair(0, -37),
        Pair(7, -18), Pair(2, -9), Pair(27, -18), Pair(-14, 1), Pair(-1, 5), Pair(-5, 18), Pair(-17, 5), Pair(14, 6),
        Pair(0, 9), Pair(-3, 1), Pair(-4, -23), Pair(-4, 10), Pair(-4, 4), Pair(0, -1), Pair(4, 0), Pair(-5, 17)
      },
      { // Piece 4
        Pair(39, -49), Pair(-72, 83), Pair(-18, 32), Pair(87, -12), Pair(-26, 38), Pair(37, 15), Pair(27, -77), Pair(-30, -2),
        Pair(13, -49), Pair(-8, 17), Pair(-24, -5), Pair(2, 15), Pair(0, -11), Pair(53, -115), Pair(-23, 84), Pair(-25, -21),
        Pair(17, 50), Pair(13, 8), Pair(36, -10), Pair(27, 33), Pair(3, -18), Pair(-20, 17), Pair(-37, 18), Pair(-8, -11),
        Pair(1, 10), Pair(21, -2), Pair(0, -30), Pair(-14, -12), Pair(-6, 7), Pair(-15, -31), Pair(-13, -4), Pair(-12, -19),
        Pair(-2, 14), Pair(20, 7), Pair(5, 29), Pair(-1, 19), Pair(-9, 17), Pair(-4, 31), Pair(-12, 2), Pair(16, -28),
        Pair(-21, 68), Pair(5, 14), Pair(2, 17), Pair(6, 10), Pair(6, -3), Pair(3, 17), Pair(-4, 15), Pair(-6, 43),
        Pair(11, -25), Pair(6, -35), Pair(-11, -20), Pair(4, 25), Pair(-3, 18), Pair(17, 11), Pair(5, 53), Pair(7, 73),
        Pair(1, 27), Pair(19, -7), Pair(4, -33), Pair(2, -2), Pair(-3, 16), Pair(11, 28), Pair(36, 56), Pair(9, 32)
      },
      { // Piece 5
        Pair(21, 81), Pair(62, 67), Pair(63, 103), Pair(-13, -102), Pair(9, 11), Pair(20, 38), Pair(24, 71), Pair(12, 46),
        Pair(26, 148), Pair(19, 120), Pair(45, 82), Pair(50, 143), Pair(40, 65), Pair(-32, -1), Pair(-58, 16), Pair(-42, -24),
        Pair(44, 132), Pair(22, 123), Pair(29, 98), Pair(76, 37), Pair(7, 60), Pair(22, 18), Pair(-4, -7), Pair(-32, 17),
        Pair(86, 45), Pair(-35, 26), Pair(71, 42), Pair(159, 29), Pair(5, 4), Pair(-136, 13), Pair(-14, -1), Pair(-61, -8),
        Pair(-11, 6), Pair(41, 4), Pair(-47, 36), Pair(4, 22), Pair(-80, 20), Pair(-50, 25), Pair(-29, 23), Pair(-47, 6),
        Pair(-33, -22), Pair(48, 14), Pair(27, 9), Pair(5, 16), Pair(-5, 10), Pair(-56, 22), Pair(-17, 17), Pair(21, -2),
        Pair(8, 16), Pair(68, -14), Pair(-21, 46), Pair(14, -15), Pair(17, 1), Pair(-1, 0), Pair(-7, 8), Pair(-6, 4),
        Pair(-12, 6), Pair(12, 10), Pair(9, 13), Pair(-16, 29), Pair(6, 4), Pair(4, -12), Pair(-3, -7), Pair(1, -14)
      }
    }},
    {{ // Bucket 11
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-128, -1), Pair(-15, 32), Pair(-66, -19), Pair(11, -13), Pair(-55, -74), Pair(0, 73), Pair(-57, 6), Pair(-122, 28),
        Pair(-22, 22), Pair(-14, -13), Pair(-7, 35), Pair(-8, -45), Pair(-63, 67), Pair(16, 28), Pair(16, 0), Pair(-4, -26),
        Pair(0, -2), Pair(-6, 11), Pair(-24, 53), Pair(15, 2), Pair(-21, 28), Pair(28, -9), Pair(15, -6), Pair(-23, 24),
        Pair(-2, 7), Pair(-4, 16), Pair(-3, 7), Pair(6, -8), Pair(11, 5), Pair(1, 13), Pair(-1, 1), Pair(-1, -1),
        Pair(4, 0), Pair(2, 9), Pair(1, 19), Pair(-5, 9), Pair(10, 18), Pair(-5, 10), Pair(3, 9), Pair(-1, 4),
        Pair(0, 1), Pair(9, -31), Pair(-1, 11), Pair(-3, 3), Pair(8, 17), Pair(-4, 14), Pair(0, 11), Pair(0, 6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(69, -38), Pair(38, -38), Pair(68, 11), Pair(-85, 56), Pair(-38, 7), Pair(59, 43), Pair(-24, -53), Pair(48, -20),
        Pair(1, 64), Pair(-18, 73), Pair(-76, 43), Pair(-236, 23), Pair(-66, 150), Pair(-70, 83), Pair(-170, 53), Pair(13, -19),
        Pair(-100, 70), Pair(18, -1), Pair(-14, 1), Pair(-30, 65), Pair(-9, 60), Pair(-18, 52), Pair(-64, 40), Pair(-44, 17),
        Pair(-27, -18), Pair(-19, 18), Pair(-18, 42), Pair(-6, 26), Pair(14, 18), Pair(-16, -3), Pair(-1, -11), Pair(-15, -26),
        Pair(-4, 42), Pair(-5, 2), Pair(-3, 2), Pair(-12, 29), Pair(-11, 58), Pair(2, 1), Pair(-48, 17), Pair(-11, 38),
        Pair(8, -2), Pair(-14, 9), Pair(-4, -1), Pair(-19, 56), Pair(-12, -8), Pair(3, 39), Pair(0, 44), Pair(-3, 16),
        Pair(7, 64), Pair(6, -15), Pair(6, -26), Pair(8, 96), Pair(-6, 15), Pair(-9, 28), Pair(-45, -38), Pair(-20, 43),
        Pair(36, 21), Pair(-4, -16), Pair(-30, 10), Pair(-24, 36), Pair(10, -27), Pair(23, -40), Pair(4, 1), Pair(86, -63)
      },
      { // Piece 2
        Pair(1, -37), Pair(-48, -17), Pair(-99, 19), Pair(-117, -114), Pair(-53, 8), Pair(-35, 72), Pair(-52, -131), Pair(-50, 32),
        Pair(11, -70), Pair(-14, -6), Pair(-55, -16), Pair(-33, 15), Pair(12, 19), Pair(32, -79), Pair(-2, -25), Pair(38, 13),
        Pair(6, -83), Pair(-26, 12), Pair(18, -12), Pair(39, 29), Pair(-83, 15), Pair(-81, 65), Pair(55, -60), Pair(-42, 12),
        Pair(25, 31), Pair(-4, -26), Pair(18, -9), Pair(26, 15), Pair(-18, -8), Pair(20, 1), Pair(-52, 10), Pair(-43, 84),
        Pair(-6, -35), Pair(17, 24), Pair(-7, 16), Pair(3, -14), Pair(10, -32), Pair(-56, 14), Pair(11, -22), Pair(-54, -27),
        Pair(4, -12), Pair(24, -2), Pair(20, 14), Pair(-4, 3), Pair(-45, 19), Pair(-1, 8), Pair(0, -43), Pair(25, -11),
        Pair(10, 1), Pair(2, 3), Pair(35, -48), Pair(-55, 97), Pair(3, 18), Pair(-3, -63), Pair(3, -5), Pair(-2, -70),
        Pair(-22, 30), Pair(0, -41), Pair(-16, -47), Pair(55, 23), Pair(-108, 20), Pair(-1, -22), Pair(-61, -85), Pair(7, 38)
      },
      { // Piece 3
        Pair(17, 51), Pair(8, 9), Pair(-23, 49), Pair(-17, 19), Pair(77, 1), Pair(28, 2), Pair(47, -23), Pair(14, 82),
        Pair(-18, 34), Pair(-33, 4), Pair(-12, 15), Pair(-74, 87), Pair(24, 53), Pair(-62, 16), Pair(-31, 73), Pair(59, 26),
        Pair(-13, 20), Pair(24, 43), Pair(8, 15), Pair(49, -17), Pair(-94, 58), Pair(-10, 35), Pair(-44, -18), Pair(-26, 43),
        Pair(6, 17), Pair(-23, 26), Pair(41, -33), Pair(82, -22), Pair(-5, 38), Pair(-32, 50), Pair(-23, 9), Pair(41, 29),
        Pair(-10, 1), Pair(42, -11), Pair(13, 40), Pair(11, 10), Pair(39, -18), Pair(-17, 38), Pair(45, 66), Pair(-20, -1),
        Pair(-36, 28), Pair(2, 54), Pair(31, 5), Pair(29, 12), Pair(-17, -21), Pair(18, -21), Pair(33, 32), Pair(-2, 40),
        Pair(31, -19), Pair(14, 39), Pair(-4, 36), Pair(3, 4), Pair(-30, 40), Pair(-13, 2), Pair(17, 31), Pair(9, 71),
        Pair(1, 11), Pair(11, 3), Pair(-8, 26), Pair(-10, 10), Pair(-17, 17), Pair(-4, -6), Pair(-3, 7), Pair(0, 29)
      },
      { // Piece 4
        Pair(-50, -28), Pair(101, 46), Pair(10, -27), Pair(-76, -26), Pair(-9, 21), Pair(88, 44), Pair(20, 66), Pair(-38, -18),
        Pair(-3, 22), Pair(-64, 108), Pair(24, 18), Pair(60, -91), Pair(-32, -18), Pair(-50, 124), Pair(-15, -35), Pair(-56, -34),
        Pair(26, -62), Pair(-32, 27), Pair(39, 12), Pair(18, -84), Pair(22, 52), Pair(-11, 49), Pair(-53, -5), Pair(-23, -37),
        Pair(43, -9), Pair(-18, 106), Pair(-3, -54), Pair(12, -48), Pair(-15, 21), Pair(-45, 22), Pair(-21, 39), Pair(-10, -11),
        Pair(-9, -36), Pair(-11, 21), Pair(-35, 90), Pair(-27, -20), Pair(4, 63), Pair(-56, 84), Pair(9, 54), Pair(-40, -7),
        Pair(-22, -61), Pair(-10, 33), Pair(8, -14), Pair(-20, -4), Pair(-4, -13), Pair(3, 29), Pair(-13, 14), Pair(-25, 51),
        Pair(-55, 8), Pair(-2, -20), Pair(-1, 2), Pair(-51, -28), Pair(8, -20), Pair(-4, 3), Pair(-27, 77), Pair(-36, 10),
        Pair(-17, 45), Pair(-5, -21), Pair(-6, -5), Pair(-2, -36), Pair(11, -60), Pair(30, -23), Pair(127, 123), Pair(-30, 72)
      },
      { // Piece 5
        Pair(13, 56), Pair(45, 122), Pair(46, 106), Pair(54, 147), Pair(14, 3), Pair(3, 71), Pair(-8, -20), Pair(5, 72),
        Pair(37, 104), Pair(11, 7), Pair(106, 159), Pair(-9, -29), Pair(71, 150), Pair(-7, 7), Pair(-39, -52), Pair(18, 52),
        Pair(3, 52), Pair(52, 32), Pair(42, 83), Pair(18, 47), Pair(-67, 127), Pair(46, 58), Pair(-12, 20), Pair(1, 12),
        Pair(85, -5), Pair(19, 10), Pair(4, 67), Pair(63, 29), Pair(42, 41), Pair(-9, -17), Pair(-34, 6), Pair(9, -44),
        Pair(-86, 37), Pair(4, 45), Pair(-40, 26), Pair(28, 46), Pair(136, -10), Pair(-35, 45), Pair(-60, 58), Pair(-34, -24),
        Pair(-5, 34), Pair(-16, 4), Pair(82, -10), Pair(31, -1), Pair(-19, 2), Pair(32, -22), Pair(-12, -2), Pair(-31, -4),
        Pair(63, 12), Pair(4, -11), Pair(23, 27), Pair(-75, 98), Pair(-34, 29), Pair(-34, 15), Pair(15, -46), Pair(8, -29),
        Pair(11, -88), Pair(-18, -5), Pair(18, 17), Pair(-36, 16), Pair(-9, -10), Pair(-21, -19), Pair(1, -4), Pair(-13, -18)
      }
    }},
    {{ // Bucket 12
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-32, 55), Pair(-33, -29), Pair(-67, 23), Pair(16, -121), Pair(-22, -13), Pair(-120, 11), Pair(-78, 44), Pair(-38, -11),
        Pair(-2, 47), Pair(-16, -1), Pair(16, -12), Pair(-16, 3), Pair(68, -34), Pair(-3, 14), Pair(-57, 48), Pair(-17, 23),
        Pair(4, -13), Pair(0, -5), Pair(-1, 3), Pair(-6, 19), Pair(3, 14), Pair(-26, 13), Pair(4, 1), Pair(-21, 5),
        Pair(-2, 8), Pair(-2, 8), Pair(-2, 14), Pair(2, 16), Pair(-8, 3), Pair(9, 5), Pair(7, 9), Pair(4, 5),
        Pair(0, 12), Pair(0, 12), Pair(-7, 2), Pair(7, 26), Pair(7, -15), Pair(5, 14), Pair(4, 9), Pair(5, 3),
        Pair(-4, 5), Pair(0, 5), Pair(-5, 7), Pair(1, 46), Pair(-1, -1), Pair(4, 14), Pair(7, -30), Pair(6, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(29, -73), Pair(60, 106), Pair(-115, 14), Pair(88, 3), Pair(-81, 2), Pair(127, -32), Pair(-1, -45), Pair(-70, 12),
        Pair(-17, -35), Pair(-67, 32), Pair(-7, 7), Pair(-36, 36), Pair(9, -20), Pair(-6, 50), Pair(98, -38), Pair(37, -123),
        Pair(14, 25), Pair(24, 45), Pair(12, -1), Pair(2, 29), Pair(3, -2), Pair(-13, 34), Pair(-48, 21), Pair(-7, -11),
        Pair(-34, 26), Pair(7, 45), Pair(-8, 37), Pair(-9, 21), Pair(-24, 6), Pair(4, 40), Pair(-17, 29), Pair(10, 55),
        Pair(9, -6), Pair(59, -2), Pair(4, 8), Pair(2, 13), Pair(6, 4), Pair(4, 24), Pair(-52, 73), Pair(-6, 32),
        Pair(11, 2), Pair(9, 4), Pair(7, 33), Pair(-2, 50), Pair(-10, 25), Pair(-2, 24), Pair(-21, 52), Pair(8, -25),
        Pair(55, 31), Pair(-47, 20), Pair(-8, 36), Pair(4, 10), Pair(73, 41), Pair(-11, 33), Pair(-4, 4), Pair(-16, -1),
        Pair(12, -32), Pair(5, 21), Pair(-1, -3), Pair(11, 32), Pair(12, 29), Pair(9, 42), Pair(-4, 47), Pair(-46, -78)
      },
      { // Piece 2
        Pair(-23, 11), Pair(-4, 27), Pair(103, -37), Pair(33, -16), Pair(-20, -11), Pair(77, -9), Pair(-26, -29), Pair(8, -110),
        Pair(17, -42), Pair(-30, -39), Pair(9, -8), Pair(14, 68), Pair(0, -39), Pair(95, -12), Pair(-44, 97), Pair(-34, 72),
        Pair(-60, 31), Pair(-28, 25), Pair(3, 4), Pair(-15, -4), Pair(16, -39), Pair(-35, 9), Pair(34, 18), Pair(5, 10),
        Pair(-1, -11), Pair(-7, -8), Pair(1, -6), Pair(-12, 15), Pair(0, 12), Pair(2, -15), Pair(2, 3), Pair(-21, -18),
        Pair(-68, -47), Pair(-1, -39), Pair(67, -30), Pair(-12, 54), Pair(9, -17), Pair(-2, -10), Pair(31, -51), Pair(14, -19),
        Pair(28, 21), Pair(52, -5), Pair(6, -10), Pair(11, 28), Pair(-9, -11), Pair(-1, 16), Pair(22, -6), Pair(1, 18),
        Pair(-68, 36), Pair(11, 1), Pair(24, 32), Pair(3, -10), Pair(73, 1), Pair(-6, -1), Pair(-2, -8), Pair(-15, -13),
        Pair(25, -40), Pair(53, 2), Pair(-2, 16), Pair(-11, 24), Pair(-31, 26), Pair(-23, -24), Pair(-22, -36), Pair(21, 6)
      },
      { // Piece 3
        Pair(67, 6), Pair(-22, 28), Pair(15, 38), Pair(30, 19), Pair(18, 11), Pair(-19, 19), Pair(-163, 64), Pair(79, 1),
        Pair(-68, 50), Pair(37, 11), Pair(42, 16), Pair(16, -15), Pair(-39, 60), Pair(-76, 39), Pair(-69, 28), Pair(-21, 55),
        Pair(6, 27), Pair(10, -5), Pair(-24, 28), Pair(-9, 25), Pair(-99, 9), Pair(28, 4), Pair(37, -19), Pair(-53, 18),
        Pair(-10, 12), Pair(13, -7), Pair(-7, 5), Pair(12, 24), Pair(-19, 35), Pair(-11, 62), Pair(8, 30), Pair(-19, 32),
        Pair(6, -9), Pair(14, 13), Pair(6, -2), Pair(-26, 27), Pair(61, -38), Pair(9, 4), Pair(3, 51), Pair(-9, -32),
        Pair(-7, 19), Pair(34, 5), Pair(-11, 41), Pair(25, 6), Pair(23, 14), Pair(-11, -7), Pair(-21, 49), Pair(-7, -7),
        Pair(-28, 17), Pair(15, -9), Pair(14, 14), Pair(3, 19), Pair(19, -35), Pair(16, 18), Pair(-15, -26), Pair(16, -98),
        Pair(0, 14), Pair(-1, 8), Pair(-2, 9), Pair(5, -7), Pair(-9, -1), Pair(-5, -1), Pair(-29, 24), Pair(-1, 4)
      },
      { // Piece 4
        Pair(4, -28), Pair(15, 32), Pair(58, -28), Pair(10, 20), Pair(-54, -64), Pair(-17, 53), Pair(17, 49), Pair(-157, 34),
        Pair(-12, 7), Pair(-8, 50), Pair(-36, -3), Pair(-65, 27), Pair(36, -82), Pair(10, 110), Pair(21, 72), Pair(-32, 9),
        Pair(17, 10), Pair(33, 40), Pair(-6, 15), Pair(9, 21), Pair(-64, 58), Pair(-83, 89), Pair(1, -17), Pair(-30, 36),
        Pair(-18, 26), Pair(17, -31), Pair(-17, -8), Pair(-17, 37), Pair(-47, 14), Pair(-13, -59), Pair(-17, -10), Pair(10, 24),
        Pair(2, 1), Pair(4, 1), Pair(-7, 31), Pair(-1, -22), Pair(0, 0), Pair(3, -40), Pair(29, 21), Pair(-10, 78),
        Pair(-3, -29), Pair(9, 12), Pair(-11, 8), Pair(-3, 50), Pair(-18, 8), Pair(16, 11), Pair(-29, 2), Pair(8, -23),
        Pair(-6, -22), Pair(-11, 20), Pair(-2, -25), Pair(-8, 11), Pair(-133, -1), Pair(-34, 64), Pair(39, 7), Pair(-47, 21),
        Pair(-9, 30), Pair(-9, 32), Pair(1, -38), Pair(-2, -21), Pair(-20, -13), Pair(-25, -15), Pair(13, 12), Pair(-3, -100)
      },
      { // Piece 5
        Pair(3, 34), Pair(-20, -55), Pair(18, 63), Pair(42, 126), Pair(36, 15), Pair(-2, 2), Pair(0, 21), Pair(0, 0),
        Pair(-38, 57), Pair(24, -10), Pair(79, 126), Pair(6, 194), Pair(-35, -47), Pair(23, 131), Pair(41, 16), Pair(16, 55),
        Pair(-4, -80), Pair(50, 73), Pair(62, 92), Pair(81, 65), Pair(115, 35), Pair(39, 47), Pair(31, 34), Pair(-20, 26),
        Pair(16, -17), Pair(67, 9), Pair(26, 93), Pair(21, 89), Pair(21, 20), Pair(-15, 21), Pair(72, -13), Pair(-33, -55),
        Pair(-44, 54), Pair(-25, -9), Pair(-26, 33), Pair(47, 20), Pair(-57, -11), Pair(-10, 14), Pair(-29, 3), Pair(-122, -2),
        Pair(57, -10), Pair(-37, 24), Pair(14, -6), Pair(60, 31), Pair(32, 13), Pair(-21, 10), Pair(75, -36), Pair(36, -34),
        Pair(-62, 9), Pair(4, -6), Pair(-28, 13), Pair(-61, 21), Pair(-59, -9), Pair(-28, 12), Pair(2, -7), Pair(26, -13),
        Pair(-32, 25), Pair(-20, 6), Pair(5, 13), Pair(35, 3), Pair(-20, 24), Pair(-32, 6), Pair(0, -10), Pair(3, -2)
      }
    }},
    {{ // Bucket 13
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(7, -26), Pair(-28, 15), Pair(8, -6), Pair(-13, -3), Pair(-63, 40), Pair(-15, 17), Pair(21, -16), Pair(-13, 26),
        Pair(8, -7), Pair(-6, 3), Pair(6, -4), Pair(10, -11), Pair(-22, -2), Pair(24, 14), Pair(-58, 18), Pair(-12, 29),
        Pair(-2, 6), Pair(1, 6), Pair(6, 5), Pair(0, 5), Pair(-16, 1), Pair(-4, 25), Pair(-16, 2), Pair(0, 11),
        Pair(-2, 9), Pair(2, 9), Pair(1, 7), Pair(2, 12), Pair(5, 12), Pair(13, 3), Pair(6, 7), Pair(4, 2),
        Pair(-1, 10), Pair(0, 8), Pair(-2, 6), Pair(-6, 5), Pair(7, 18), Pair(11, -2), Pair(12, 9), Pair(2, 3),
        Pair(-2, 7), Pair(2, 9), Pair(-5, 9), Pair(-4, 9), Pair(4, 15), Pair(6, 4), Pair(4, 3), Pair(1, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-17, -16), Pair(-24, 18), Pair(-20, 22), Pair(-20, 15), Pair(4, 7), Pair(-19, 40), Pair(-35, -2), Pair(2, -28),
        Pair(27, 10), Pair(1, 9), Pair(12, 15), Pair(-7, 10), Pair(11, 24), Pair(-11, 17), Pair(10, 34), Pair(22, 1),
        Pair(-19, 0), Pair(2, 25), Pair(6, 5), Pair(-1, 11), Pair(41, -13), Pair(-24, 7), Pair(3, 7), Pair(-27, 13),
        Pair(-17, 17), Pair(13, 16), Pair(4, 17), Pair(-6, 8), Pair(8, 23), Pair(-12, 7), Pair(2, 18), Pair(-23, 1),
        Pair(3, 14), Pair(6, 12), Pair(7, 18), Pair(9, 10), Pair(2, 12), Pair(0, 16), Pair(-5, 12), Pair(-8, 0),
        Pair(-2, 26), Pair(8, 21), Pair(3, 13), Pair(8, 11), Pair(5, 20), Pair(-1, -1), Pair(3, 18), Pair(-9, 25),
        Pair(-9, 40), Pair(0, 10), Pair(7, 5), Pair(4, 9), Pair(5, 20), Pair(-44, -39), Pair(-1, 0), Pair(-10, 0),
        Pair(-57, 27), Pair(1, 9), Pair(13, 0), Pair(8, 32), Pair(13, 19), Pair(1, 14), Pair(-6, 1), Pair(-39, -73)
      },
      { // Piece 2
        Pair(4, 8), Pair(-64, 24), Pair(7, -9), Pair(2, -38), Pair(-17, -11), Pair(-3, -41), Pair(47, -12), Pair(-3, 45),
        Pair(-41, -2), Pair(-3, 1), Pair(19, -11), Pair(52, -15), Pair(20, -37), Pair(-42, -7), Pair(-29, 9), Pair(3, 11),
        Pair(-5, -2), Pair(-5, -3), Pair(26, -7), Pair(-3, -13), Pair(7, 13), Pair(9, 0), Pair(-9, -10), Pair(-19, 5),
        Pair(-8, 0), Pair(8, -1), Pair(4, -11), Pair(6, 0), Pair(-2, -3), Pair(14, -18), Pair(-6, 21), Pair(-19, 11),
        Pair(14, 10), Pair(-6, -1), Pair(3, -3), Pair(-6, 3), Pair(14, 3), Pair(2, -1), Pair(11, -20), Pair(-13, -12),
        Pair(2, 2), Pair(-4, 13), Pair(1, 5), Pair(-2, -2), Pair(0, 18), Pair(4, 1), Pair(-11, -9), Pair(-7, 18),
        Pair(-3, 2), Pair(1, 5), Pair(0, 19), Pair(-7, 11), Pair(9, 1), Pair(-58, -26), Pair(4, 6), Pair(-7, -28),
        Pair(4, -4), Pair(-5, -18), Pair(2, 8), Pair(-13, 12), Pair(-6, 11), Pair(11, 9), Pair(-16, -49), Pair(-13, 0)
      },
      { // Piece 3
        Pair(34, 15), Pair(39, 2), Pair(36, 0), Pair(18, 0), Pair(30, -1), Pair(76, 3), Pair(19, 18), Pair(17, -7),
        Pair(5, 3), Pair(14, 12), Pair(5, 14), Pair(23, 3), Pair(-13, 18), Pair(29, 0), Pair(-52, 33), Pair(19, 11),
        Pair(8, 9), Pair(4, 10), Pair(24, 4), Pair(14, 19), Pair(-1, 4), Pair(96, -33), Pair(14, -4), Pair(3, 16),
        Pair(-3, 22), Pair(2, 13), Pair(11, -3), Pair(9, 6), Pair(-4, 19), Pair(56, 0), Pair(-11, 11), Pair(14, 2),
        Pair(11, 9), Pair(11, 12), Pair(2, 15), Pair(7, 9), Pair(4, 13), Pair(35, 2), Pair(-33, 37), Pair(9, 16),
        Pair(1, 4), Pair(10, 13), Pair(2, 22), Pair(-6, 17), Pair(4, 11), Pair(31, 6), Pair(-10, 25), Pair(-16, 29),
        Pair(6, 10), Pair(7, 22), Pair(-11, 11), Pair(8, -9), Pair(-6, 4), Pair(-70, 51), Pair(-3, 17), Pair(-34, -1),
        Pair(3, 9), Pair(5, 10), Pair(6, 9), Pair(5, 5), Pair(2, 0), Pair(-2, 0), Pair(-21, 6), Pair(-1, 4)
      },
      { // Piece 4
        Pair(26, 18), Pair(34, -7), Pair(17, -11), Pair(41, 10), Pair(33, -3), Pair(-83, 12), Pair(17, 17), Pair(-19, 20),
        Pair(-13, 5), Pair(-10, 29), Pair(-20, 22), Pair(4, 20), Pair(-6, 17), Pair(0, -46), Pair(-5, 21), Pair(-9, 35),
        Pair(-6, 20), Pair(-2, 14), Pair(-12, 29), Pair(-24, 47), Pair(-16, 55), Pair(-78, 49), Pair(4, 12), Pair(-35, 23),
        Pair(-1, 19), Pair(2, 33), Pair(-14, 5), Pair(-6, 24), Pair(-13, 2), Pair(-19, 21), Pair(0, 6), Pair(-14, 5),
        Pair(8, 28), Pair(8, 17), Pair(7, -3), Pair(-3, 23), Pair(4, 12), Pair(-3, 1), Pair(-1, -5), Pair(-21, 3),
        Pair(5, 6), Pair(6, 24), Pair(7, 19), Pair(5, -1), Pair(6, 11), Pair(1, 3), Pair(-7, 25), Pair(5, -31),
        Pair(8, 3), Pair(12, 11), Pair(4, 4), Pair(-1, 14), Pair(4, 19), Pair(22, 32), Pair(-15, -26), Pair(25, 27),
        Pair(-4, 24), Pair(8, 29), Pair(6, 16), Pair(4, 13), Pair(2, 12), Pair(-4, -9), Pair(55, -59), Pair(11, 11)
      },
      { // Piece 5
        Pair(12, 41), Pair(17, 4), Pair(-28, 33), Pair(48, 75), Pair(70, 11), Pair(-6, 66), Pair(14, 31), Pair(5, 110),
        Pair(-41, 18), Pair(1, 36), Pair(-12, 82), Pair(37, 93), Pair(36, 170), Pair(6, 121), Pair(-71, 87), Pair(-34, 8),
        Pair(72, -1), Pair(14, 23), Pair(18, -21), Pair(87, 57), Pair(3, 52), Pair(22, 47), Pair(-51, 79), Pair(-37, 24),
        Pair(-39, 3), Pair(-82, 12), Pair(-155, 47), Pair(14, 32), Pair(58, 35), Pair(-31, 55), Pair(59, 19), Pair(-49, 21),
        Pair(-30, -43), Pair(-68, 22), Pair(-33, 12), Pair(-41, 19), Pair(4, 16), Pair(-37, 29), Pair(69, -2), Pair(70, 15),
        Pair(91, -6), Pair(-7, 1), Pair(-29, 22), Pair(4, 14), Pair(-19, 27), Pair(15, 2), Pair(14, 13), Pair(46, -1),
        Pair(13, -2), Pair(-4, 5), Pair(-10, 16), Pair(-13, 2), Pair(-2, -1), Pair(-62, 25), Pair(22, -15), Pair(23, -2),
        Pair(-4, -19), Pair(-6, -9), Pair(-11, -4), Pair(13, -21), Pair(-4, -16), Pair(-43, 11), Pair(5, 3), Pair(16, -4)
      }
    }},
    {{ // Bucket 14
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-43, 29), Pair(-22, 0), Pair(-18, -20), Pair(34, -27), Pair(93, 4), Pair(-65, -5), Pair(-38, 1), Pair(-25, 1),
        Pair(8, -16), Pair(8, -18), Pair(-10, -4), Pair(1, -12), Pair(-17, 12), Pair(-17, 7), Pair(-12, 8), Pair(-2, 11),
        Pair(5, 4), Pair(-2, 1), Pair(2, -1), Pair(2, 5), Pair(-7, 4), Pair(-15, 15), Pair(10, 10), Pair(-10, 6),
        Pair(-1, 10), Pair(2, 8), Pair(0, 8), Pair(0, 6), Pair(2, 10), Pair(1, 9), Pair(23, -1), Pair(3, 2),
        Pair(1, 10), Pair(-1, 9), Pair(1, 5), Pair(1, 5), Pair(0, 6), Pair(8, 11), Pair(-2, 6), Pair(7, 5),
        Pair(1, 11), Pair(0, 12), Pair(-2, 11), Pair(0, 11), Pair(0, -32), Pair(4, 3), Pair(7, 4), Pair(1, -4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(74, 38), Pair(-171, 4), Pair(50, 24), Pair(18, -32), Pair(6, 31), Pair(12, 9), Pair(-3, -15), Pair(-11, 17),
        Pair(-7, 32), Pair(1, 13), Pair(-4, 0), Pair(-15, 48), Pair(31, -1), Pair(53, -7), Pair(22, -24), Pair(24, -33),
        Pair(-4, 8), Pair(-16, 15), Pair(-4, 5), Pair(-8, 9), Pair(-3, 10), Pair(23, 4), Pair(4, -11), Pair(41, -38),
        Pair(-5, 10), Pair(1, 15), Pair(-1, 26), Pair(9, 2), Pair(1, 12), Pair(-6, 3), Pair(2, -2), Pair(13, 5),
        Pair(-3, 4), Pair(7, 16), Pair(1, 7), Pair(7, 12), Pair(8, 1), Pair(3, 21), Pair(3, -9), Pair(-5, 7),
        Pair(-3, -1), Pair(3, 9), Pair(1, 20), Pair(4, 17), Pair(-7, 7), Pair(5, 10), Pair(-7, -6), Pair(-12, 0),
        Pair(-8, -9), Pair(-24, 15), Pair(-2, 30), Pair(0, 6), Pair(-5, -1), Pair(-11, 1), Pair(4, -20), Pair(-7, 4),
        Pair(-55, 68), Pair(-13, 14), Pair(17, 36), Pair(-4, -1), Pair(0, 27), Pair(2, 12), Pair(-8, 25), Pair(-96, 53)
      },
      { // Piece 2
        Pair(-32, -2), Pair(34, -18), Pair(-108, -4), Pair(-5, -5), Pair(3, -18), Pair(44, -18), Pair(42, -32), Pair(-23, 15),
        Pair(40, 2), Pair(-30, -16), Pair(17, -12), Pair(6, 1), Pair(-2, 5), Pair(6, -21), Pair(-32, -5), Pair(-13, 7),
        Pair(-18, -13), Pair(19, -15), Pair(13, -18), Pair(1, -4), Pair(-8, -28), Pair(28, -1), Pair(1, -26), Pair(7, -3),
        Pair(0, 12), Pair(-5, 9), Pair(9, -1), Pair(-30, 16), Pair(-3, -8), Pair(-5, -9), Pair(4, -4), Pair(-19, -15),
        Pair(7, 19), Pair(13, 5), Pair(-4, -7), Pair(9, 10), Pair(-4, 5), Pair(-2, 7), Pair(-1, -15), Pair(-21, 13),
        Pair(0, 9), Pair(2, -10), Pair(-1, 10), Pair(-1, 2), Pair(-5, 9), Pair(-1, 7), Pair(-1, -6), Pair(4, -57),
        Pair(4, 1), Pair(4, 8), Pair(2, 3), Pair(4, 14), Pair(-7, 9), Pair(11, -1), Pair(-8, 3), Pair(4, -13),
        Pair(17, 6), Pair(9, -6), Pair(5, 6), Pair(-21, 10), Pair(6, -2), Pair(-12, -8), Pair(47, -27), Pair(-97, 11)
      },
      { // Piece 3
        Pair(34, 3), Pair(-5, 7), Pair(-5, 6), Pair(30, -6), Pair(35, 16), Pair(69, 3), Pair(1, -13), Pair(8, -7),
        Pair(0, 10), Pair(4, 6), Pair(13, -9), Pair(10, 0), Pair(38, 7), Pair(0, 3), Pair(44, -25), Pair(-52, 17),
        Pair(24, 8), Pair(13, 0), Pair(12, 0), Pair(15, 9), Pair(-2, 21), Pair(26, 15), Pair(15, -15), Pair(11, -28),
        Pair(3, 2), Pair(11, 3), Pair(2, 10), Pair(3, 17), Pair(18, -3), Pair(1, 11), Pair(72, -35), Pair(1, 23),
        Pair(3, 12), Pair(2, 23), Pair(7, 14), Pair(15, 10), Pair(19, -7), Pair(1, 4), Pair(59, -24), Pair(-6, -15),
        Pair(-3, 19), Pair(1, -1), Pair(-10, 15), Pair(-7, 14), Pair(-4, 5), Pair(-7, 15), Pair(56, -31), Pair(-31, -13),
        Pair(-2, -6), Pair(-3, 4), Pair(-2, 18), Pair(9, 5), Pair(1, 4), Pair(1, 6), Pair(-77, -69), Pair(-78, -28),
        Pair(2, 9), Pair(5, 12), Pair(4, 9), Pair(3, 4), Pair(5, 9), Pair(2, 9), Pair(-16, -11), Pair(-12, -3)
      },
      { // Piece 4
        Pair(45, -41), Pair(-17, 35), Pair(5, 6), Pair(11, -19), Pair(24, 7), Pair(-6, 5), Pair(65, -17), Pair(-24, 23),
        Pair(12, -3), Pair(-1, 9), Pair(29, 7), Pair(-26, 26), Pair(12, -20), Pair(40, -25), Pair(-10, -20), Pair(12, -46),
        Pair(0, -3), Pair(11, 13), Pair(4, 4), Pair(4, 13), Pair(-36, 32), Pair(14, 1), Pair(18, -7), Pair(19, 1),
        Pair(8, 5), Pair(-15, 18), Pair(-10, 33), Pair(19, -2), Pair(-8, 17), Pair(-21, 27), Pair(-4, 52), Pair(9, 5),
        Pair(12, 0), Pair(14, 18), Pair(15, 11), Pair(2, 19), Pair(12, 5), Pair(0, 6), Pair(5, -3), Pair(-4, 6),
        Pair(7, 16), Pair(11, 23), Pair(3, 35), Pair(10, 8), Pair(-1, 14), Pair(1, 3), Pair(1, 12), Pair(-3, 13),
        Pair(12, -12), Pair(13, 25), Pair(5, 12), Pair(3, 28), Pair(8, 15), Pair(7, 6), Pair(-91, -102), Pair(-18, -27),
        Pair(-4, 19), Pair(8, 22), Pair(8, 17), Pair(5, 9), Pair(8, 2), Pair(5, -6), Pair(-4, 15), Pair(-64, -42)
      },
      { // Piece 5
        Pair(35, 76), Pair(13, 41), Pair(44, 9), Pair(-19, 55), Pair(9, 86), Pair(8, 87), Pair(27, 63), Pair(6, 89),
        Pair(23, -65), Pair(-7, 3), Pair(-3, 76), Pair(68, -18), Pair(-21, 1), Pair(-33, 75), Pair(-61, 49), Pair(61, 141),
        Pair(-122, 28), Pair(-33, 32), Pair(-73, 56), Pair(-54, -3), Pair(26, 60), Pair(-12, 53), Pair(58, 44), Pair(-72, 48),
        Pair(-27, 44), Pair(-28, -16), Pair(-71, 11), Pair(-11, 45), Pair(-63, 26), Pair(-29, 28), Pair(-98, 62), Pair(12, 44),
        Pair(-17, 16), Pair(-55, 20), Pair(-75, 28), Pair(18, 37), Pair(-20, 13), Pair(9, 17), Pair(17, 13), Pair(-16, 28),
        Pair(-53, 9), Pair(9, 13), Pair(22, -10), Pair(-57, 29), Pair(-26, 13), Pair(-11, 13), Pair(3, 11), Pair(47, 13),
        Pair(-62, 4), Pair(-25, -10), Pair(-14, 9), Pair(-15, 14), Pair(-8, 7), Pair(-18, -7), Pair(-13, 33), Pair(2, -9),
        Pair(-60, 3), Pair(-28, 3), Pair(-16, -9), Pair(10, 9), Pair(19, -3), Pair(-5, -7), Pair(6, 0), Pair(-8, -16)
      }
    }},
    {{ // Bucket 15
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-15, 8), Pair(3, 4), Pair(-10, 2), Pair(-12, -21), Pair(-89, 25), Pair(-20, 48), Pair(-54, 20), Pair(-18, -5),
        Pair(7, -3), Pair(-6, 7), Pair(11, -7), Pair(15, -5), Pair(7, 13), Pair(13, 9), Pair(-19, -8), Pair(10, 9),
        Pair(0, 5), Pair(-3, 0), Pair(-4, 4), Pair(4, 1), Pair(-3, -5), Pair(-3, -2), Pair(-18, 18), Pair(2, 25),
        Pair(0, 8), Pair(3, 12), Pair(-1, 8), Pair(3, 5), Pair(2, 5), Pair(-2, 1), Pair(4, 3), Pair(2, 6),
        Pair(2, 9), Pair(1, 9), Pair(1, 7), Pair(0, 6), Pair(4, 8), Pair(4, 2), Pair(1, 6), Pair(-9, 9),
        Pair(0, 9), Pair(1, 12), Pair(1, 9), Pair(-1, 4), Pair(6, 2), Pair(1, 1), Pair(0, -4), Pair(-2, -6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(39, 39), Pair(-59, 34), Pair(42, 13), Pair(-32, 11), Pair(27, -21), Pair(-9, 4), Pair(-48, -16), Pair(-21, -14),
        Pair(-5, -1), Pair(-4, 16), Pair(30, -14), Pair(-10, 3), Pair(1, 1), Pair(17, -37), Pair(14, 14), Pair(24, 17),
        Pair(-18, 21), Pair(-7, 3), Pair(3, 9), Pair(-4, 15), Pair(9, 30), Pair(61, -25), Pair(29, 5), Pair(58, -7),
        Pair(-13, -2), Pair(7, 4), Pair(5, 19), Pair(13, 10), Pair(9, 8), Pair(13, -3), Pair(7, 14), Pair(6, 4),
        Pair(-1, 15), Pair(3, 5), Pair(9, 8), Pair(8, 8), Pair(5, 8), Pair(-1, 5), Pair(20, 1), Pair(-4, -12),
        Pair(2, 12), Pair(-6, 4), Pair(0, 4), Pair(2, 7), Pair(-4, 17), Pair(2, 5), Pair(6, 9), Pair(-16, -21),
        Pair(21, 23), Pair(-14, 10), Pair(-1, -2), Pair(-3, 7), Pair(-5, 12), Pair(-5, -1), Pair(-12, -10), Pair(-232, -29),
        Pair(108, 37), Pair(-7, 11), Pair(-10, 34), Pair(7, 22), Pair(7, -3), Pair(-2, 6), Pair(0, -27), Pair(-42, -68)
      },
      { // Piece 2
        Pair(42, -10), Pair(80, -63), Pair(-49, 11), Pair(19, -15), Pair(86, -24), Pair(-4, -5), Pair(9, 10), Pair(-61, 20),
        Pair(-2, -2), Pair(13, -5), Pair(17, -23), Pair(47, -12), Pair(5, -22), Pair(0, 1), Pair(14, -1), Pair(-18, 25),
        Pair(-6, 0), Pair(-6, -3), Pair(9, -9), Pair(11, -16), Pair(0, 10), Pair(9, 2), Pair(-14, 5), Pair(-8, -4),
        Pair(-8, 8), Pair(-1, -3), Pair(4, -6), Pair(1, -3), Pair(5, 12), Pair(-9, -10), Pair(-13, 31), Pair(12, 5),
        Pair(-3, 1), Pair(-4, 1), Pair(8, -12), Pair(-5, 0), Pair(9, 9), Pair(-13, 8), Pair(22, 2), Pair(7, 28),
        Pair(-7, 9), Pair(3, -9), Pair(2, 0), Pair(0, 3), Pair(3, 8), Pair(-4, 10), Pair(3, -3), Pair(0, -18),
        Pair(4, -42), Pair(2, 7), Pair(-7, -4), Pair(-4, 2), Pair(-1, 14), Pair(18, -7), Pair(3, -3), Pair(-77, -168),
        Pair(20, 13), Pair(-8, -10), Pair(2, 0), Pair(-13, 10), Pair(1, 1), Pair(-3, 10), Pair(6, 36), Pair(21, -19)
      },
      { // Piece 3
        Pair(1, 11), Pair(5, 5), Pair(-5, 17), Pair(21, 13), Pair(33, 8), Pair(39, 6), Pair(-1, 36), Pair(-38, -19),
        Pair(14, 18), Pair(-1, 3), Pair(-15, 29), Pair(4, 0), Pair(24, -13), Pair(46, -1), Pair(8, 16), Pair(20, -21),
        Pair(12, 12), Pair(5, 17), Pair(16, 11), Pair(-1, 4), Pair(10, -6), Pair(14, -9), Pair(-2, 11), Pair(-12, 2),
        Pair(-4, 16), Pair(13, 16), Pair(4, 23), Pair(27, 2), Pair(0, 12), Pair(42, -9), Pair(2, 9), Pair(25, -6),
        Pair(12, 0), Pair(17, 21), Pair(-20, 21), Pair(-4, 14), Pair(12, -6), Pair(2, 14), Pair(-4, 21), Pair(16, -30),
        Pair(2, 10), Pair(-11, 39), Pair(14, -1), Pair(-16, 13), Pair(-2, 23), Pair(-8, 10), Pair(-21, 16), Pair(12, 5),
        Pair(6, 14), Pair(-18, 36), Pair(-7, 20), Pair(4, 13), Pair(6, 7), Pair(-8, 15), Pair(8, -8), Pair(-112, 25),
        Pair(2, 11), Pair(-3, 10), Pair(4, 7), Pair(3, 7), Pair(7, 10), Pair(5, 15), Pair(-14, 13), Pair(-17, -17)
      },
      { // Piece 4
        Pair(-34, -1), Pair(-19, -36), Pair(-56, 53), Pair(37, -53), Pair(-4, -34), Pair(90, -38), Pair(-19, -10), Pair(-73, 22),
        Pair(0, -9), Pair(1, -16), Pair(17, -20), Pair(13, 5), Pair(-19, -24), Pair(-3, -15), Pair(-15, 25), Pair(38, -40),
        Pair(-5, -34), Pair(-14, 4), Pair(26, -28), Pair(27, -40), Pair(-5, -3), Pair(23, -19), Pair(15, -5), Pair(-5, 6),
        Pair(-6, 10), Pair(28, -46), Pair(-11, -5), Pair(-5, -6), Pair(2, -13), Pair(5, -13), Pair(6, -6), Pair(19, -9),
        Pair(10, -1), Pair(7, 4), Pair(2, 3), Pair(3, 6), Pair(-1, -2), Pair(-3, 4), Pair(-4, -17), Pair(7, -6),
        Pair(3, -11), Pair(2, 11), Pair(-2, 4), Pair(-4, -9), Pair(-5, 8), Pair(-5, -3), Pair(6, -21), Pair(-3, -10),
        Pair(8, -14), Pair(-6, 22), Pair(0, 14), Pair(5, 14), Pair(-2, 7), Pair(-2, -14), Pair(1, -34), Pair(44, 84),
        Pair(8, -3), Pair(6, -39), Pair(2, 8), Pair(0, 10), Pair(4, -5), Pair(-10, -23), Pair(7, -16), Pair(0, -24)
      },
      { // Piece 5
        Pair(15, 30), Pair(-57, 106), Pair(-3, 34), Pair(-26, 58), Pair(40, 78), Pair(15, 96), Pair(34, 124), Pair(20, -136),
        Pair(13, 62), Pair(-48, 85), Pair(-4, 28), Pair(26, 110), Pair(-27, 72), Pair(-3, 88), Pair(62, 78), Pair(-14, -7),
        Pair(-125, 5), Pair(4, 20), Pair(-31, 61), Pair(9, -2), Pair(-33, 79), Pair(-80, 46), Pair(-27, 79), Pair(3, 97),
        Pair(-64, 59), Pair(-130, 39), Pair(67, 9), Pair(-82, 49), Pair(-78, 31), Pair(18, 35), Pair(9, 28), Pair(-38, 18),
        Pair(-42, -2), Pair(-58, 6), Pair(-63, 35), Pair(21, 42), Pair(6, 22), Pair(19, 13), Pair(-4, 37), Pair(-75, 47),
        Pair(0, 4), Pair(-42, 32), Pair(-8, 34), Pair(14, 24), Pair(18, 16), Pair(10, 6), Pair(7, 3), Pair(19, 2),
        Pair(-44, -30), Pair(-50, 2), Pair(-38, 29), Pair(-21, 25), Pair(-5, 9), Pair(-9, 7), Pair(-24, -16), Pair(-52, 35),
        Pair(-53, 13), Pair(-27, 23), Pair(-31, 21), Pair(-20, 22), Pair(5, -8), Pair(-7, 7), Pair(0, -13), Pair(14, -33)
      }
    }},
    {{ // Bucket 16
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(24, 27), Pair(-67, 42), Pair(50, 17), Pair(-23, 2), Pair(-22, -24), Pair(-35, 21), Pair(-7, -41), Pair(-96, 57),
        Pair(18, 65), Pair(-20, 8), Pair(-14, 16), Pair(18, -20), Pair(-6, 4), Pair(9, -23), Pair(-1, 8), Pair(-1, 24),
        Pair(6, 20), Pair(-2, 3), Pair(7, 4), Pair(-1, 6), Pair(2, 6), Pair(8, 3), Pair(-3, 8), Pair(-3, 15),
        Pair(15, 1), Pair(5, 5), Pair(2, 5), Pair(1, 2), Pair(-3, 3), Pair(2, 7), Pair(4, 7), Pair(1, 10),
        Pair(-1, -2), Pair(0, -1), Pair(-1, 0), Pair(3, 6), Pair(-1, 8), Pair(6, 7), Pair(-2, 9), Pair(2, 10),
        Pair(3, 13), Pair(-1, 6), Pair(-3, 4), Pair(2, 1), Pair(0, 10), Pair(-1, 11), Pair(1, 11), Pair(2, 9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(25, -29), Pair(-75, 1), Pair(41, 7), Pair(-41, 22), Pair(-68, 88), Pair(23, -7), Pair(56, 3), Pair(-27, -12),
        Pair(-6, -4), Pair(-28, -3), Pair(-18, 18), Pair(-1, 0), Pair(21, 17), Pair(-54, 26), Pair(-15, 24), Pair(-44, 58),
        Pair(47, -4), Pair(-14, 19), Pair(0, 7), Pair(-29, 24), Pair(36, -24), Pair(-14, 10), Pair(29, 22), Pair(26, -22),
        Pair(5, 22), Pair(6, 21), Pair(19, 16), Pair(5, 17), Pair(-3, 22), Pair(-5, 17), Pair(-5, 8), Pair(-6, 12),
        Pair(-7, -18), Pair(-10, 27), Pair(8, 15), Pair(2, 17), Pair(2, 13), Pair(11, 7), Pair(-17, 23), Pair(3, 10),
        Pair(24, -13), Pair(10, 3), Pair(-1, 6), Pair(3, 20), Pair(13, 25), Pair(2, 10), Pair(-3, 29), Pair(1, 9),
        Pair(18, 11), Pair(-26, 14), Pair(-6, 16), Pair(-4, 9), Pair(1, 21), Pair(0, 0), Pair(-7, -2), Pair(-3, 5),
        Pair(7, -14), Pair(-9, -20), Pair(0, 4), Pair(-11, 8), Pair(-2, 1), Pair(-5, 2), Pair(13, -2), Pair(42, 7)
      },
      { // Piece 2
        Pair(-21, 9), Pair(126, -19), Pair(-57, 12), Pair(-41, -13), Pair(-35, 5), Pair(-40, -5), Pair(60, -24), Pair(-30, -61),
        Pair(-2, -14), Pair(9, -9), Pair(-6, 1), Pair(21, -4), Pair(7, -12), Pair(-36, -16), Pair(-7, -14), Pair(-4, -23),
        Pair(-3, -13), Pair(3, 3), Pair(10, -9), Pair(6, -7), Pair(2, 4), Pair(3, -24), Pair(5, -17), Pair(-3, -8),
        Pair(-3, -2), Pair(16, 4), Pair(22, -19), Pair(10, -4), Pair(17, -20), Pair(0, 10), Pair(0, -1), Pair(4, 6),
        Pair(3, -19), Pair(-12, 10), Pair(11, -23), Pair(8, -8), Pair(-2, 10), Pair(-3, -3), Pair(-16, 26), Pair(-1, -2),
        Pair(-24, -24), Pair(10, 11), Pair(-3, -5), Pair(2, 18), Pair(0, 7), Pair(-2, 15), Pair(12, -14), Pair(16, -5),
        Pair(28, -16), Pair(3, -6), Pair(-7, 9), Pair(-1, 9), Pair(1, 14), Pair(-3, 2), Pair(3, 12), Pair(0, 22),
        Pair(-2, -15), Pair(-10, -5), Pair(-10, 2), Pair(5, 20), Pair(11, -14), Pair(2, 7), Pair(-20, 5), Pair(15, 19)
      },
      { // Piece 3
        Pair(65, -32), Pair(35, 25), Pair(-16, 20), Pair(-43, 35), Pair(-54, 35), Pair(-12, -6), Pair(42, -19), Pair(-42, 35),
        Pair(-22, -20), Pair(-19, 20), Pair(-7, 17), Pair(-3, 19), Pair(-33, 33), Pair(12, 17), Pair(-34, 10), Pair(-11, 6),
        Pair(-24, -3), Pair(-2, 22), Pair(-18, 2), Pair(4, 1), Pair(32, 11), Pair(42, 1), Pair(5, 15), Pair(19, 23),
        Pair(-28, 13), Pair(5, 6), Pair(-18, 33), Pair(-4, 22), Pair(3, 15), Pair(6, 20), Pair(-4, 0), Pair(9, 17),
        Pair(-3, 0), Pair(-8, 20), Pair(9, 20), Pair(-7, 18), Pair(-7, 21), Pair(2, -4), Pair(10, 21), Pair(-16, 3),
        Pair(-7, -33), Pair(6, 15), Pair(25, 13), Pair(1, 16), Pair(-9, 18), Pair(7, -3), Pair(-10, 16), Pair(-11, 5),
        Pair(-25, 24), Pair(-5, 17), Pair(3, 6), Pair(14, 2), Pair(-16, 24), Pair(5, 8), Pair(-5, 5), Pair(-11, 2),
        Pair(-7, -12), Pair(-4, 16), Pair(0, 5), Pair(3, 9), Pair(1, 12), Pair(-1, 10), Pair(19, -5), Pair(7, -9)
      },
      { // Piece 4
        Pair(-18, -25), Pair(-37, 14), Pair(-38, 40), Pair(-49, 57), Pair(-66, 52), Pair(-96, 82), Pair(-19, 75), Pair(39, 49),
        Pair(-21, 3), Pair(-7, -4), Pair(28, -2), Pair(-17, 49), Pair(22, -20), Pair(-8, -39), Pair(30, -36), Pair(3, 6),
        Pair(-24, 42), Pair(-22, 25), Pair(-25, -4), Pair(-21, 7), Pair(-1, -4), Pair(-6, -30), Pair(-10, 20), Pair(-24, -9),
        Pair(16, -28), Pair(-2, 30), Pair(-13, -31), Pair(-5, 19), Pair(-8, -17), Pair(-9, -25), Pair(14, -9), Pair(14, 4),
        Pair(-22, 38), Pair(25, 10), Pair(-6, 17), Pair(10, 21), Pair(-9, 6), Pair(1, 18), Pair(5, -14), Pair(5, -31),
        Pair(-21, 2), Pair(-5, 5), Pair(1, 25), Pair(4, -5), Pair(-5, 23), Pair(-1, 2), Pair(14, 6), Pair(13, -14),
        Pair(-15, -11), Pair(5, 27), Pair(1, 14), Pair(1, 19), Pair(-6, 12), Pair(9, 15), Pair(5, 15), Pair(38, -86),
        Pair(-16, 32), Pair(2, -23), Pair(-1, 14), Pair(2, 6), Pair(-1, -8), Pair(-7, 13), Pair(-46, 52), Pair(21, -55)
      },
      { // Piece 5
        Pair(1, 44), Pair(8, 87), Pair(-54, 113), Pair(27, 20), Pair(32, -10), Pair(67, 21), Pair(-4, -42), Pair(-12, -16),
        Pair(-84, 0), Pair(-178, 120), Pair(116, 59), Pair(69, 34), Pair(87, -16), Pair(38, -25), Pair(9, -57), Pair(-14, -27),
        Pair(-52, 16), Pair(8, 60), Pair(72, 53), Pair(67, 42), Pair(-96, -4), Pair(108, -19), Pair(-67, 14), Pair(-4, 16),
        Pair(35, 4), Pair(33, 43), Pair(90, 37), Pair(-82, 57), Pair(-21, 32), Pair(-28, 18), Pair(11, 6), Pair(75, -12),
        Pair(-55, 10), Pair(-19, 59), Pair(-10, 23), Pair(-51, 34), Pair(-40, 18), Pair(33, 4), Pair(-63, 11), Pair(-64, -1),
        Pair(-15, 0), Pair(-24, 21), Pair(21, 25), Pair(-31, 21), Pair(-5, 24), Pair(-30, 8), Pair(-48, 9), Pair(-55, 5),
        Pair(-13, -3), Pair(1, -4), Pair(16, 8), Pair(-8, 9), Pair(-10, 8), Pair(-2, 7), Pair(-11, 1), Pair(-9, -10),
        Pair(-21, -45), Pair(67, -11), Pair(36, 5), Pair(0, -16), Pair(-2, -13), Pair(-10, -3), Pair(-4, -2), Pair(-7, -14)
      }
    }},
    {{ // Bucket 17
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-69, 52), Pair(-12, -15), Pair(-147, -10), Pair(-47, -6), Pair(-13, 0), Pair(-25, -4), Pair(51, -27), Pair(22, -32),
        Pair(-11, 23), Pair(20, 31), Pair(-17, 4), Pair(1, -14), Pair(-21, -7), Pair(6, -1), Pair(-1, 13), Pair(-27, 8),
        Pair(-16, 9), Pair(13, 12), Pair(-8, 9), Pair(3, 1), Pair(0, -2), Pair(10, 5), Pair(0, 8), Pair(3, 1),
        Pair(-4, 0), Pair(-29, 18), Pair(4, 1), Pair(2, 0), Pair(-1, 6), Pair(1, 8), Pair(-1, 13), Pair(1, 11),
        Pair(0, -2), Pair(-2, 2), Pair(3, 4), Pair(-1, 6), Pair(2, 9), Pair(2, 8), Pair(1, 10), Pair(1, 10),
        Pair(1, 8), Pair(5, 8), Pair(3, 10), Pair(1, 9), Pair(0, 10), Pair(0, 10), Pair(0, 10), Pair(1, 10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-7, -16), Pair(-117, 63), Pair(-16, 34), Pair(-66, 14), Pair(-91, -12), Pair(-53, -15), Pair(-91, 72), Pair(-24, 34),
        Pair(-21, 11), Pair(-13, 32), Pair(11, 49), Pair(-1, 23), Pair(-32, 51), Pair(-1, 10), Pair(-92, 41), Pair(-105, 75),
        Pair(-25, -9), Pair(-15, 36), Pair(-9, 39), Pair(10, 2), Pair(-8, 25), Pair(-11, 35), Pair(-14, 48), Pair(-33, 0),
        Pair(-30, 40), Pair(-2, 10), Pair(8, 23), Pair(-8, 25), Pair(-2, 16), Pair(-15, 18), Pair(-4, 11), Pair(-11, 43),
        Pair(3, -2), Pair(-3, 3), Pair(0, 11), Pair(-1, 25), Pair(-6, 13), Pair(7, 22), Pair(1, 11), Pair(4, 37),
        Pair(-8, 9), Pair(26, 40), Pair(-1, 19), Pair(13, 22), Pair(-7, 25), Pair(3, 17), Pair(1, -2), Pair(4, 32),
        Pair(-12, -1), Pair(19, 19), Pair(7, 21), Pair(-3, 18), Pair(-1, 19), Pair(4, 28), Pair(-6, 17), Pair(-7, 25),
        Pair(91, -65), Pair(-2, -3), Pair(13, 8), Pair(-23, 28), Pair(3, 11), Pair(10, 26), Pair(13, -8), Pair(-25, 71)
      },
      { // Piece 2
        Pair(41, -25), Pair(-54, 37), Pair(-51, 20), Pair(-14, 13), Pair(-63, -28), Pair(-10, -1), Pair(-22, 3), Pair(1, -66),
        Pair(-62, 65), Pair(-18, -17), Pair(14, 9), Pair(-18, -20), Pair(44, -18), Pair(3, -11), Pair(-73, 21), Pair(15, -2),
        Pair(-9, 1), Pair(10, 2), Pair(14, -22), Pair(-10, -8), Pair(-1, -11), Pair(-7, -26), Pair(-13, -3), Pair(-17, 19),
        Pair(24, -2), Pair(8, -1), Pair(-2, 5), Pair(-8, -5), Pair(-1, -12), Pair(14, -21), Pair(3, 11), Pair(14, -26),
        Pair(-48, 14), Pair(-9, 2), Pair(-3, -1), Pair(3, -4), Pair(0, 8), Pair(-8, 25), Pair(-9, 8), Pair(6, 11),
        Pair(5, -9), Pair(-19, -61), Pair(10, -2), Pair(-2, 6), Pair(8, 5), Pair(-4, 0), Pair(7, 15), Pair(11, -12),
        Pair(-48, -24), Pair(6, 10), Pair(-6, -5), Pair(3, 15), Pair(-5, 10), Pair(1, 24), Pair(0, 5), Pair(1, 26),
        Pair(1, -26), Pair(26, -17), Pair(-2, 17), Pair(-10, 8), Pair(-10, -4), Pair(-5, 8), Pair(17, 18), Pair(-2, 16)
      },
      { // Piece 3
        Pair(-25, 43), Pair(21, -3), Pair(8, 16), Pair(-17, 7), Pair(-4, 12), Pair(-44, 22), Pair(8, 24), Pair(41, 4),
        Pair(-20, 23), Pair(7, -14), Pair(-29, 35), Pair(17, 4), Pair(21, 12), Pair(6, 18), Pair(-101, 54), Pair(22, 8),
        Pair(-3, 16), Pair(-21, 24), Pair(-13, 30), Pair(5, 21), Pair(15, 7), Pair(-33, 15), Pair(-24, 1), Pair(-40, 28),
        Pair(-9, 33), Pair(-1, 30), Pair(-9, 8), Pair(-14, 16), Pair(6, -2), Pair(12, 3), Pair(-5, 7), Pair(-24, 28),
        Pair(-18, 37), Pair(-29, 16), Pair(9, 20), Pair(-8, 19), Pair(-9, 26), Pair(15, -2), Pair(-35, 25), Pair(-30, 8),
        Pair(-2, -25), Pair(-51, 5), Pair(-3, 31), Pair(6, 14), Pair(-9, 29), Pair(-14, 17), Pair(-13, 2), Pair(-22, 35),
        Pair(8, -5), Pair(0, -4), Pair(17, 0), Pair(14, 16), Pair(-6, 14), Pair(9, 0), Pair(-21, 37), Pair(3, -1),
        Pair(-2, 7), Pair(-8, -1), Pair(-2, 12), Pair(1, 8), Pair(1, 12), Pair(-1, 12), Pair(2, 17), Pair(3, 0)
      },
      { // Piece 4
        Pair(-76, 84), Pair(-36, 13), Pair(-56, 4), Pair(-48, 36), Pair(-67, 20), Pair(-62, 67), Pair(-80, -12), Pair(-12, -31),
        Pair(18, 2), Pair(-27, 22), Pair(-21, 43), Pair(-6, -59), Pair(-33, 58), Pair(1, 33), Pair(-83, 43), Pair(-18, 32),
        Pair(-27, 41), Pair(-6, -15), Pair(4, 11), Pair(-15, 9), Pair(-25, 17), Pair(-14, 10), Pair(-43, -7), Pair(-17, 17),
        Pair(-9, 24), Pair(-24, 19), Pair(-9, 4), Pair(-22, 6), Pair(13, -10), Pair(-3, -3), Pair(-1, -12), Pair(-5, -16),
        Pair(-3, 20), Pair(-28, 22), Pair(-13, 16), Pair(-9, 3), Pair(-18, 16), Pair(-14, 13), Pair(-8, -11), Pair(-30, 38),
        Pair(-2, -43), Pair(60, -48), Pair(-4, 13), Pair(-5, 16), Pair(1, 6), Pair(2, 5), Pair(-21, -5), Pair(8, -16),
        Pair(-3, 3), Pair(-5, 3), Pair(-1, 1), Pair(1, 17), Pair(1, 15), Pair(0, 19), Pair(5, 4), Pair(-10, 16),
        Pair(16, -5), Pair(16, -28), Pair(-6, 3), Pair(-1, 2), Pair(-2, 18), Pair(20, -14), Pair(17, 12), Pair(67, -32)
      },
      { // Piece 5
        Pair(66, -16), Pair(17, 58), Pair(18, 145), Pair(-11, -41), Pair(26, 1), Pair(41, 45), Pair(-50, 45), Pair(-7, 33),
        Pair(100, 76), Pair(-41, 108), Pair(58, 86), Pair(66, 41), Pair(49, 26), Pair(5, 12), Pair(87, -3), Pair(-39, 5),
        Pair(41, 93), Pair(11, 4), Pair(100, 87), Pair(91, 15), Pair(-73, 14), Pair(-61, 32), Pair(76, -31), Pair(-51, -12),
        Pair(9, 64), Pair(111, 28), Pair(81, 37), Pair(53, 23), Pair(-104, 53), Pair(-106, 34), Pair(53, -1), Pair(-39, -22),
        Pair(-9, 32), Pair(96, -17), Pair(-9, 44), Pair(-5, 24), Pair(-55, 35), Pair(-76, 18), Pair(6, -1), Pair(-44, 1),
        Pair(3, 6), Pair(21, 2), Pair(-25, 27), Pair(-13, 31), Pair(13, 6), Pair(-8, 3), Pair(6, 2), Pair(-34, 9),
        Pair(53, -11), Pair(11, -4), Pair(10, 11), Pair(11, 1), Pair(-2, 4), Pair(-6, 6), Pair(-8, -3), Pair(-4, -3),
        Pair(43, -41), Pair(44, -3), Pair(28, 3), Pair(-7, 9), Pair(2, 3), Pair(-2, 3), Pair(-3, -2), Pair(-6, -7)
      }
    }},
    {{ // Bucket 18
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-53, 50), Pair(-90, 22), Pair(-58, 0), Pair(22, 21), Pair(-12, -9), Pair(-79, 49), Pair(-46, -14), Pair(-49, 3),
        Pair(-13, 6), Pair(-6, -13), Pair(0, 27), Pair(-33, -6), Pair(-10, 7), Pair(20, 4), Pair(24, -1), Pair(8, -6),
        Pair(-6, 10), Pair(-2, 6), Pair(10, 13), Pair(-18, 18), Pair(5, 7), Pair(2, -4), Pair(-13, 8), Pair(6, 0),
        Pair(1, 5), Pair(6, 9), Pair(-7, -1), Pair(10, 9), Pair(4, 1), Pair(4, -2), Pair(3, 12), Pair(1, 5),
        Pair(-1, 2), Pair(3, 6), Pair(-3, -3), Pair(1, 6), Pair(-4, 2), Pair(-1, 7), Pair(0, 5), Pair(0, 8),
        Pair(-1, 4), Pair(8, 14), Pair(3, 0), Pair(-2, 14), Pair(-6, 3), Pair(-2, 7), Pair(2, 10), Pair(1, 8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(15, -6), Pair(-141, 58), Pair(17, -6), Pair(-8, 101), Pair(-59, 52), Pair(2, -32), Pair(-14, -47), Pair(94, 8),
        Pair(-1, 49), Pair(26, 19), Pair(22, 15), Pair(0, -4), Pair(-42, -21), Pair(-24, 51), Pair(-3, 62), Pair(-26, -7),
        Pair(12, 21), Pair(24, 10), Pair(19, 17), Pair(-6, 31), Pair(-24, 51), Pair(-29, 27), Pair(-9, 44), Pair(63, 26),
        Pair(-5, 27), Pair(2, 32), Pair(-6, 40), Pair(23, 43), Pair(2, 7), Pair(5, 21), Pair(-6, 44), Pair(14, -11),
        Pair(-5, 12), Pair(20, 7), Pair(2, 19), Pair(4, 32), Pair(0, 21), Pair(7, 17), Pair(-13, 30), Pair(9, 6),
        Pair(-2, 20), Pair(6, 25), Pair(-8, 52), Pair(2, 19), Pair(8, 28), Pair(6, 18), Pair(7, -1), Pair(6, 15),
        Pair(8, -41), Pair(42, 2), Pair(9, 53), Pair(5, 15), Pair(-6, 27), Pair(4, 7), Pair(2, 51), Pair(20, -1),
        Pair(19, -7), Pair(0, 25), Pair(24, -5), Pair(2, 4), Pair(10, 20), Pair(11, -1), Pair(11, -4), Pair(2, 61)
      },
      { // Piece 2
        Pair(-9, 23), Pair(61, 4), Pair(-31, -17), Pair(3, -5), Pair(-52, 22), Pair(58, -7), Pair(21, -2), Pair(-35, 39),
        Pair(-8, 2), Pair(19, 4), Pair(39, -36), Pair(6, -16), Pair(-48, -35), Pair(88, -10), Pair(18, -43), Pair(61, -20),
        Pair(12, -24), Pair(32, -3), Pair(31, -15), Pair(8, -3), Pair(-5, 8), Pair(-14, -11), Pair(6, -17), Pair(7, 0),
        Pair(-8, 4), Pair(8, -7), Pair(0, -21), Pair(10, 19), Pair(-8, -5), Pair(-4, -15), Pair(-6, -11), Pair(9, -8),
        Pair(14, -5), Pair(-22, -6), Pair(12, -2), Pair(11, 7), Pair(6, 5), Pair(-5, 12), Pair(15, 5), Pair(1, -2),
        Pair(0, -33), Pair(16, -12), Pair(-38, -18), Pair(5, 16), Pair(-1, 2), Pair(14, 14), Pair(10, -4), Pair(5, -12),
        Pair(31, -50), Pair(-16, -26), Pair(27, 7), Pair(-2, -5), Pair(7, 12), Pair(-1, 21), Pair(11, 16), Pair(1, 32),
        Pair(-32, -34), Pair(16, -35), Pair(-4, -10), Pair(7, -11), Pair(-5, 1), Pair(5, 23), Pair(5, -13), Pair(14, 69)
      },
      { // Piece 3
        Pair(-27, 39), Pair(8, 0), Pair(-12, 21), Pair(-52, 25), Pair(29, 25), Pair(-23, -10), Pair(3, 31), Pair(44, 5),
        Pair(-3, 31), Pair(-7, 13), Pair(-22, -22), Pair(14, 25), Pair(-6, 9), Pair(-93, 54), Pair(-45, 28), Pair(-9, 10),
        Pair(-30, 39), Pair(-35, 23), Pair(-9, 20), Pair(8, 22), Pair(-17, 26), Pair(-5, 11), Pair(15, 29), Pair(-1, 12),
        Pair(-10, 36), Pair(16, 21), Pair(11, 7), Pair(15, 13), Pair(-12, 33), Pair(-15, 13), Pair(-1, 21), Pair(-7, 28),
        Pair(9, 26), Pair(6, 19), Pair(7, 14), Pair(3, 27), Pair(-19, 34), Pair(-2, -6), Pair(16, 17), Pair(-52, 45),
        Pair(1, 0), Pair(3, 39), Pair(-41, 38), Pair(-10, 12), Pair(-4, 23), Pair(8, -6), Pair(-25, 17), Pair(-16, 15),
        Pair(2, 26), Pair(-8, 44), Pair(0, -26), Pair(-16, 34), Pair(2, 1), Pair(2, 8), Pair(-24, 17), Pair(22, 8),
        Pair(3, 12), Pair(4, 10), Pair(-7, -4), Pair(-3, 5), Pair(3, 12), Pair(0, 6), Pair(-4, 25), Pair(1, 16)
      },
      { // Piece 4
        Pair(-30, 18), Pair(-70, 19), Pair(-18, -34), Pair(-84, 27), Pair(-52, 36), Pair(-11, 38), Pair(1, 23), Pair(11, -14),
        Pair(27, -35), Pair(-17, -16), Pair(-44, -38), Pair(-73, 61), Pair(-2, 23), Pair(-40, -5), Pair(4, -73), Pair(-12, 44),
        Pair(8, -23), Pair(7, 18), Pair(-49, 29), Pair(-21, 33), Pair(-60, 74), Pair(-9, 11), Pair(-3, -8), Pair(-11, 0),
        Pair(-21, 7), Pair(-11, -25), Pair(12, -44), Pair(-14, 34), Pair(-26, 2), Pair(-4, 12), Pair(-18, 25), Pair(-7, 12),
        Pair(-5, 3), Pair(14, -21), Pair(-13, 9), Pair(5, 16), Pair(-11, 3), Pair(0, -1), Pair(-12, -14), Pair(-8, 23),
        Pair(-13, 6), Pair(4, -20), Pair(-8, -4), Pair(-4, 15), Pair(-2, 17), Pair(0, 30), Pair(3, 7), Pair(-1, 44),
        Pair(17, -41), Pair(-2, -5), Pair(-1, -6), Pair(2, 18), Pair(2, 17), Pair(13, 8), Pair(-11, 8), Pair(21, 68),
        Pair(6, -44), Pair(-5, 23), Pair(-2, -4), Pair(-2, 20), Pair(-1, -7), Pair(14, -8), Pair(24, -95), Pair(-6, -65)
      },
      { // Piece 5
        Pair(-19, -123), Pair(46, 135), Pair(67, 112), Pair(-122, -4), Pair(8, -38), Pair(29, -11), Pair(-35, -53), Pair(19, -18),
        Pair(14, 122), Pair(-18, 97), Pair(129, 63), Pair(-60, 8), Pair(138, 96), Pair(44, 41), Pair(3, 2), Pair(24, -15),
        Pair(-97, 60), Pair(100, 119), Pair(-51, 78), Pair(-3, 59), Pair(16, 88), Pair(-97, 23), Pair(27, 14), Pair(6, -28),
        Pair(-42, 38), Pair(-60, 66), Pair(-79, 57), Pair(50, 59), Pair(96, 15), Pair(-90, 44), Pair(-46, -2), Pair(-51, 2),
        Pair(184, -20), Pair(-28, 21), Pair(-27, 46), Pair(98, 16), Pair(67, 7), Pair(-18, 15), Pair(-8, -11), Pair(-111, 17),
        Pair(7, 28), Pair(31, 14), Pair(30, -16), Pair(7, 25), Pair(-20, 14), Pair(-11, 1), Pair(-24, -3), Pair(22, -18),
        Pair(29, 7), Pair(17, 10), Pair(-25, 17), Pair(-15, 12), Pair(2, 3), Pair(12, -7), Pair(-9, 4), Pair(-3, -3),
        Pair(27, -18), Pair(-12, -4), Pair(-7, 6), Pair(-21, 14), Pair(-1, -5), Pair(-17, 4), Pair(-2, -12), Pair(-3, -22)
      }
    }},
    {{ // Bucket 19
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-51, 19), Pair(-50, 47), Pair(-16, 39), Pair(-87, 26), Pair(-7, -46), Pair(-72, 1), Pair(28, -40), Pair(-7, -53),
        Pair(-3, 12), Pair(-6, -4), Pair(-55, 55), Pair(28, 6), Pair(-60, 60), Pair(21, 2), Pair(-33, 21), Pair(-4, 6),
        Pair(3, -9), Pair(5, 10), Pair(-5, 15), Pair(12, 4), Pair(-2, 12), Pair(1, 14), Pair(-6, 6), Pair(-2, 14),
        Pair(2, 6), Pair(-1, 3), Pair(3, 8), Pair(-2, -3), Pair(7, 3), Pair(2, 0), Pair(-4, 3), Pair(-1, 4),
        Pair(3, 7), Pair(-1, 5), Pair(1, 6), Pair(-2, -6), Pair(1, 12), Pair(-6, 5), Pair(-1, 6), Pair(3, 5),
        Pair(1, 6), Pair(0, 0), Pair(5, 14), Pair(0, -9), Pair(7, 23), Pair(-6, 6), Pair(2, 5), Pair(1, 6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(18, -55), Pair(92, -14), Pair(-7, 9), Pair(-109, 71), Pair(36, -14), Pair(-94, 49), Pair(-54, 36), Pair(16, 13),
        Pair(7, 36), Pair(9, 8), Pair(-23, 26), Pair(30, 16), Pair(-42, 11), Pair(34, 28), Pair(-58, 58), Pair(64, 13),
        Pair(-24, -37), Pair(-19, 28), Pair(-17, 45), Pair(-39, 13), Pair(13, 5), Pair(-45, 46), Pair(20, 46), Pair(21, 3),
        Pair(23, 34), Pair(-6, 10), Pair(-1, 13), Pair(-15, 52), Pair(1, 24), Pair(-9, 13), Pair(-9, 34), Pair(-10, 44),
        Pair(1, 10), Pair(-2, 7), Pair(-5, 35), Pair(1, 30), Pair(3, 37), Pair(-4, 43), Pair(-18, 57), Pair(2, 18),
        Pair(10, 4), Pair(-4, 26), Pair(-2, 20), Pair(10, 10), Pair(-6, 22), Pair(7, 22), Pair(-9, 16), Pair(3, -17),
        Pair(24, 2), Pair(18, -36), Pair(5, 21), Pair(4, 45), Pair(2, 3), Pair(-3, 16), Pair(-1, 21), Pair(16, 6),
        Pair(-16, 8), Pair(3, 32), Pair(11, -20), Pair(8, -10), Pair(1, 33), Pair(4, 1), Pair(2, 37), Pair(-77, 130)
      },
      { // Piece 2
        Pair(-76, 23), Pair(38, 26), Pair(49, -27), Pair(-50, 18), Pair(12, -23), Pair(-94, -11), Pair(2, -94), Pair(-97, 44),
        Pair(12, 24), Pair(-13, 19), Pair(17, -2), Pair(16, -15), Pair(45, -16), Pair(-39, -12), Pair(9, 7), Pair(-4, 11),
        Pair(-48, 4), Pair(-2, 5), Pair(-19, 19), Pair(2, 6), Pair(-40, -9), Pair(-37, 24), Pair(14, -24), Pair(-18, 34),
        Pair(20, 1), Pair(-12, 18), Pair(5, -7), Pair(-21, 20), Pair(-14, -3), Pair(-5, -4), Pair(1, -1), Pair(13, 18),
        Pair(14, -44), Pair(3, 25), Pair(-7, 4), Pair(-5, -5), Pair(9, 11), Pair(2, 10), Pair(-11, -22), Pair(-5, 18),
        Pair(2, 5), Pair(-7, -11), Pair(3, 2), Pair(-28, 19), Pair(-1, 1), Pair(0, -4), Pair(5, 25), Pair(6, -17),
        Pair(16, -18), Pair(2, 9), Pair(-34, -19), Pair(14, 16), Pair(-7, -2), Pair(2, 0), Pair(4, 3), Pair(2, -8),
        Pair(16, -18), Pair(-108, -20), Pair(0, 3), Pair(4, -25), Pair(6, -8), Pair(-5, -24), Pair(-15, 32), Pair(11, -20)
      },
      { // Piece 3
        Pair(10, 42), Pair(41, 11), Pair(-38, 49), Pair(-2, 20), Pair(-45, 37), Pair(-16, 12), Pair(-103, 59), Pair(10, 32),
        Pair(6, 3), Pair(3, 16), Pair(-8, 15), Pair(-8, -4), Pair(3, 15), Pair(1, 6), Pair(20, 13), Pair(-11, 11),
        Pair(-12, 24), Pair(-20, 19), Pair(-20, 20), Pair(-30, 8), Pair(-27, 23), Pair(-32, 13), Pair(-24, 0), Pair(26, -14),
        Pair(-2, 31), Pair(-6, 42), Pair(-16, 33), Pair(8, 3), Pair(-10, 19), Pair(11, 7), Pair(4, 5), Pair(9, 11),
        Pair(-2, 20), Pair(-8, 40), Pair(-1, 28), Pair(18, 27), Pair(-9, 3), Pair(-9, 24), Pair(27, 5), Pair(-28, 16),
        Pair(1, 7), Pair(-14, 14), Pair(-4, 0), Pair(-19, 24), Pair(-5, 18), Pair(7, -14), Pair(-5, 16), Pair(-24, -5),
        Pair(-10, -13), Pair(1, 14), Pair(9, -11), Pair(-3, 0), Pair(11, -2), Pair(-12, 5), Pair(-2, 25), Pair(-35, 22),
        Pair(0, 13), Pair(2, 12), Pair(-3, 10), Pair(5, -4), Pair(-6, 17), Pair(3, 8), Pair(-4, 22), Pair(1, 1)
      },
      { // Piece 4
        Pair(-21, -42), Pair(-6, 47), Pair(-13, -7), Pair(-93, 15), Pair(-2, -36), Pair(15, 3), Pair(-8, -1), Pair(72, -75),
        Pair(9, -28), Pair(-23, 9), Pair(10, 8), Pair(-7, 0), Pair(-27, 30), Pair(16, -81), Pair(-87, 23), Pair(-84, -16),
        Pair(-2, -9), Pair(-6, -27), Pair(-8, 26), Pair(-11, -37), Pair(3, -6), Pair(15, 26), Pair(-53, 79), Pair(-16, -23),
        Pair(-17, 15), Pair(-17, 37), Pair(9, 13), Pair(21, -58), Pair(-14, 3), Pair(3, 14), Pair(-12, 26), Pair(-4, 8),
        Pair(11, -16), Pair(-7, 24), Pair(-20, 23), Pair(5, 26), Pair(10, -2), Pair(-11, -5), Pair(-14, 22), Pair(1, -13),
        Pair(-11, 11), Pair(-7, 1), Pair(-5, -5), Pair(-37, 2), Pair(-1, 26), Pair(-10, 23), Pair(8, -17), Pair(5, 10),
        Pair(20, -56), Pair(3, -1), Pair(1, -23), Pair(1, -1), Pair(-2, 8), Pair(-8, 9), Pair(8, 33), Pair(-1, -2),
        Pair(13, -43), Pair(-2, -42), Pair(-3, 15), Pair(-1, -2), Pair(-3, -1), Pair(-15, 6), Pair(5, 5), Pair(-16, 0)
      },
      { // Piece 5
        Pair(9, -60), Pair(6, 35), Pair(50, 202), Pair(39, 44), Pair(26, 46), Pair(1, -76), Pair(1, -42), Pair(-27, -93),
        Pair(6, 24), Pair(24, 55), Pair(109, 25), Pair(-1, 122), Pair(53, 95), Pair(36, 46), Pair(28, -46), Pair(-17, -22),
        Pair(-26, 17), Pair(66, 43), Pair(98, 57), Pair(-3, 98), Pair(43, 56), Pair(95, 8), Pair(36, 37), Pair(-40, -12),
        Pair(-53, 22), Pair(61, 1), Pair(49, 31), Pair(84, 36), Pair(49, 48), Pair(61, 18), Pair(-138, 8), Pair(22, -51),
        Pair(94, -59), Pair(-39, 49), Pair(15, 31), Pair(87, 14), Pair(-45, 19), Pair(8, 4), Pair(-32, 5), Pair(17, -15),
        Pair(-33, -3), Pair(81, -17), Pair(14, 2), Pair(10, 27), Pair(-17, 18), Pair(0, -6), Pair(-11, -17), Pair(16, -23),
        Pair(-9, -20), Pair(-2, -19), Pair(-4, -3), Pair(-78, 32), Pair(-20, 4), Pair(-5, -6), Pair(1, -7), Pair(3, -4),
        Pair(-11, -6), Pair(-14, -6), Pair(-28, 4), Pair(-59, 8), Pair(-2, -7), Pair(7, -14), Pair(0, -9), Pair(-1, -25)
      }
    }},
    {{ // Bucket 20
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-10, -17), Pair(-40, 1), Pair(18, -21), Pair(19, -68), Pair(17, -52), Pair(-123, 14), Pair(23, -5), Pair(-12, -18),
        Pair(-8, 16), Pair(-3, -5), Pair(15, -16), Pair(-9, 5), Pair(39, -9), Pair(-70, 24), Pair(-9, 18), Pair(-23, 4),
        Pair(-3, 5), Pair(2, -2), Pair(-2, 9), Pair(-13, 6), Pair(11, 13), Pair(-10, 9), Pair(-6, 15), Pair(-5, 5),
        Pair(0, 4), Pair(-1, 9), Pair(1, 4), Pair(6, 11), Pair(-3, -5), Pair(8, 0), Pair(2, 6), Pair(2, 4),
        Pair(0, 8), Pair(2, 10), Pair(-5, 5), Pair(1, 15), Pair(-2, -8), Pair(8, 4), Pair(1, 4), Pair(4, 8),
        Pair(-1, 5), Pair(1, 7), Pair(-3, 0), Pair(10, 20), Pair(6, -1), Pair(7, 17), Pair(0, 6), Pair(4, 7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-7, 34), Pair(138, -2), Pair(-38, 9), Pair(70, -22), Pair(-6, 48), Pair(-58, 20), Pair(112, -112), Pair(113, 81),
        Pair(8, 16), Pair(3, 27), Pair(-7, 15), Pair(-8, 19), Pair(-34, 26), Pair(-10, 32), Pair(-9, 1), Pair(33, -4),
        Pair(-8, 22), Pair(-17, 26), Pair(9, 8), Pair(-5, 39), Pair(-52, 49), Pair(-31, 24), Pair(-55, 28), Pair(17, 25),
        Pair(11, 2), Pair(11, 17), Pair(-2, 17), Pair(-1, 21), Pair(-9, 10), Pair(9, 19), Pair(-18, 12), Pair(-8, 21),
        Pair(3, 2), Pair(45, -22), Pair(6, 13), Pair(3, 24), Pair(1, 24), Pair(-2, 7), Pair(-3, 25), Pair(0, -23),
        Pair(8, -13), Pair(12, 22), Pair(8, 16), Pair(5, 10), Pair(-27, 28), Pair(0, 12), Pair(4, 22), Pair(7, -10),
        Pair(14, 2), Pair(11, 15), Pair(-5, -4), Pair(8, 16), Pair(5, 36), Pair(16, 16), Pair(-24, 3), Pair(-3, 13),
        Pair(40, -1), Pair(8, 1), Pair(17, -12), Pair(12, 1), Pair(-14, 24), Pair(12, 8), Pair(8, -2), Pair(-24, -27)
      },
      { // Piece 2
        Pair(30, -10), Pair(28, -52), Pair(10, -21), Pair(1, -49), Pair(59, -26), Pair(-7, 24), Pair(-48, -14), Pair(-3, -65),
        Pair(-25, 7), Pair(2, -8), Pair(-6, -11), Pair(54, -20), Pair(-9, -24), Pair(-52, -13), Pair(-7, -9), Pair(12, -29),
        Pair(8, 2), Pair(-13, -12), Pair(25, -24), Pair(-20, -21), Pair(-25, -22), Pair(-31, -18), Pair(6, -13), Pair(-29, -9),
        Pair(-1, -1), Pair(3, -9), Pair(-28, -8), Pair(2, -12), Pair(-20, 2), Pair(9, -32), Pair(-23, 3), Pair(-18, 8),
        Pair(-2, 3), Pair(-5, -11), Pair(3, -5), Pair(3, 2), Pair(-4, 2), Pair(-20, -4), Pair(12, 0), Pair(-12, -7),
        Pair(-10, -5), Pair(-7, 0), Pair(-9, 1), Pair(1, 1), Pair(-8, -35), Pair(6, -9), Pair(-10, 9), Pair(4, -13),
        Pair(14, -1), Pair(-4, -6), Pair(-1, 5), Pair(-15, -10), Pair(11, 19), Pair(-6, -16), Pair(-4, 12), Pair(-5, 10),
        Pair(3, 15), Pair(-4, -19), Pair(-24, -15), Pair(14, 15), Pair(0, -25), Pair(-6, -7), Pair(-78, -20), Pair(7, 17)
      },
      { // Piece 3
        Pair(-8, 8), Pair(-16, 9), Pair(-44, 24), Pair(-40, 18), Pair(-74, 33), Pair(-28, -1), Pair(-14, 22), Pair(35, -10),
        Pair(-1, 13), Pair(-26, 11), Pair(-12, 19), Pair(1, 6), Pair(38, -27), Pair(-24, 9), Pair(10, 4), Pair(-72, 21),
        Pair(-27, 25), Pair(-12, 17), Pair(9, -1), Pair(-13, 4), Pair(32, 13), Pair(-54, 27), Pair(27, -4), Pair(-18, 21),
        Pair(-6, 20), Pair(25, 20), Pair(7, 5), Pair(9, -3), Pair(39, -8), Pair(8, -16), Pair(-39, 17), Pair(-20, 12),
        Pair(4, 12), Pair(-6, 20), Pair(6, 20), Pair(11, 1), Pair(-14, 3), Pair(-8, 9), Pair(8, 9), Pair(-10, 41),
        Pair(12, 2), Pair(13, 7), Pair(0, 7), Pair(-6, 3), Pair(26, -69), Pair(-16, -16), Pair(-29, 28), Pair(-7, -18),
        Pair(-2, 10), Pair(3, -11), Pair(0, 18), Pair(8, 7), Pair(-11, -2), Pair(-11, 2), Pair(-10, -5), Pair(-28, 14),
        Pair(3, 5), Pair(1, 16), Pair(3, 5), Pair(2, 6), Pair(-1, -13), Pair(-4, 8), Pair(-3, 9), Pair(3, 8)
      },
      { // Piece 4
        Pair(0, 57), Pair(-20, 24), Pair(-25, 6), Pair(3, 19), Pair(-4, -13), Pair(-24, -24), Pair(-28, -33), Pair(-107, 46),
        Pair(-16, 9), Pair(-17, 17), Pair(-2, -17), Pair(-1, -21), Pair(24, -15), Pair(-24, 51), Pair(59, -2), Pair(-71, 35),
        Pair(7, 18), Pair(3, -7), Pair(-17, 32), Pair(-4, 27), Pair(-17, -33), Pair(-34, 49), Pair(-1, 20), Pair(-37, 46),
        Pair(1, 26), Pair(0, -10), Pair(-19, 1), Pair(-17, 33), Pair(-29, -12), Pair(20, -22), Pair(-4, 3), Pair(-24, -12),
        Pair(-6, 1), Pair(-1, 13), Pair(-6, 8), Pair(-8, 12), Pair(-2, 15), Pair(-21, 31), Pair(-4, 11), Pair(-18, -10),
        Pair(-4, 6), Pair(5, 5), Pair(5, -8), Pair(-2, 12), Pair(-15, 5), Pair(-6, -1), Pair(-10, 1), Pair(-26, 50),
        Pair(0, 13), Pair(-4, 1), Pair(4, 0), Pair(-3, 8), Pair(2, -6), Pair(-15, 11), Pair(9, -26), Pair(2, 78),
        Pair(12, -2), Pair(11, 18), Pair(-1, 19), Pair(-1, 2), Pair(1, 5), Pair(-3, -9), Pair(-40, 80), Pair(-8, -37)
      },
      { // Piece 5
        Pair(53, 109), Pair(-9, -18), Pair(0, 8), Pair(-10, -14), Pair(17, 39), Pair(14, 89), Pair(-54, 11), Pair(-15, 69),
        Pair(44, 68), Pair(-34, 59), Pair(58, 42), Pair(9, 111), Pair(61, 21), Pair(-73, 77), Pair(46, 7), Pair(-9, 6),
        Pair(5, 24), Pair(11, 33), Pair(36, 50), Pair(-2, 91), Pair(-71, 20), Pair(27, 64), Pair(8, 6), Pair(103, 20),
        Pair(50, 4), Pair(57, 21), Pair(-20, 47), Pair(166, 7), Pair(35, 47), Pair(79, 17), Pair(75, -15), Pair(-33, 31),
        Pair(111, -9), Pair(14, 12), Pair(27, 16), Pair(24, 34), Pair(45, 18), Pair(63, 3), Pair(23, 3), Pair(1, -3),
        Pair(-47, 28), Pair(-4, 8), Pair(-18, 26), Pair(-15, 25), Pair(-28, 26), Pair(-19, 3), Pair(25, -7), Pair(24, -11),
        Pair(-26, -22), Pair(6, -10), Pair(-3, -12), Pair(-33, 13), Pair(-45, 22), Pair(-6, 4), Pair(-7, -10), Pair(5, -10),
        Pair(8, -38), Pair(0, -8), Pair(-1, 8), Pair(16, -6), Pair(-22, 0), Pair(-24, -3), Pair(2, -10), Pair(-1, -19)
      }
    }},
    {{ // Bucket 21
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(11, -41), Pair(11, -21), Pair(-51, 4), Pair(11, -14), Pair(-28, -23), Pair(104, -25), Pair(-12, 9), Pair(11, -18),
        Pair(12, 6), Pair(4, 1), Pair(18, 5), Pair(11, -5), Pair(-44, 36), Pair(58, 10), Pair(-49, 16), Pair(-34, 16),
        Pair(5, 7), Pair(2, 3), Pair(1, 6), Pair(-4, 9), Pair(-7, -3), Pair(19, 11), Pair(-1, 7), Pair(-11, 6),
        Pair(3, 5), Pair(9, 5), Pair(3, 5), Pair(4, 1), Pair(13, 5), Pair(5, -1), Pair(7, 0), Pair(4, 2),
        Pair(6, 6), Pair(3, 8), Pair(0, 8), Pair(-7, 7), Pair(8, 4), Pair(-9, -2), Pair(6, 3), Pair(3, -1),
        Pair(3, 10), Pair(4, 6), Pair(0, 10), Pair(-10, 17), Pair(4, 13), Pair(9, -2), Pair(7, 11), Pair(4, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(48, -97), Pair(32, 38), Pair(-38, -22), Pair(-20, -13), Pair(-36, -40), Pair(-32, 39), Pair(13, 95), Pair(-49, -13),
        Pair(9, 11), Pair(13, 19), Pair(6, 54), Pair(23, 5), Pair(29, 1), Pair(32, -15), Pair(36, 75), Pair(-106, 22),
        Pair(42, 1), Pair(21, 8), Pair(15, -5), Pair(-3, 29), Pair(-17, 37), Pair(-32, 12), Pair(-12, 19), Pair(-59, 27),
        Pair(8, 7), Pair(4, 24), Pair(38, 16), Pair(19, 9), Pair(21, 33), Pair(5, 15), Pair(0, 28), Pair(-22, 23),
        Pair(5, 42), Pair(26, -4), Pair(21, 16), Pair(27, 11), Pair(14, 23), Pair(12, 11), Pair(18, 13), Pair(-17, 6),
        Pair(7, 5), Pair(9, 11), Pair(8, 19), Pair(9, 19), Pair(4, 11), Pair(-2, -2), Pair(-15, 32), Pair(-9, 6),
        Pair(33, 7), Pair(-19, 57), Pair(14, 5), Pair(1, 21), Pair(3, 25), Pair(18, 28), Pair(7, 9), Pair(9, 16),
        Pair(-69, 55), Pair(-13, 7), Pair(4, 11), Pair(-2, 13), Pair(-11, 18), Pair(-3, 6), Pair(-7, 18), Pair(31, -40)
      },
      { // Piece 2
        Pair(26, -40), Pair(14, -38), Pair(-48, -10), Pair(28, -1), Pair(22, -14), Pair(-9, 3), Pair(44, 41), Pair(115, -94),
        Pair(14, -39), Pair(49, -21), Pair(11, -23), Pair(-4, -51), Pair(-22, 25), Pair(5, -19), Pair(78, 13), Pair(48, -21),
        Pair(-33, 2), Pair(47, 6), Pair(-9, -1), Pair(39, -32), Pair(5, -5), Pair(0, -6), Pair(-14, -25), Pair(13, -26),
        Pair(6, 15), Pair(4, -13), Pair(18, -18), Pair(10, -6), Pair(27, -4), Pair(9, 3), Pair(17, 4), Pair(-73, 29),
        Pair(-3, 23), Pair(21, -8), Pair(-9, 12), Pair(14, 6), Pair(31, 10), Pair(14, 0), Pair(-24, 1), Pair(-23, 33),
        Pair(19, 0), Pair(-5, 15), Pair(24, 14), Pair(-1, 10), Pair(14, 8), Pair(-95, 47), Pair(10, -10), Pair(-11, -19),
        Pair(-8, 11), Pair(18, 1), Pair(11, -6), Pair(14, 14), Pair(-7, 5), Pair(23, 26), Pair(-21, -18), Pair(25, -38),
        Pair(13, 31), Pair(-21, -3), Pair(6, 20), Pair(-4, 25), Pair(28, 13), Pair(1, -11), Pair(12, -45), Pair(-43, -101)
      },
      { // Piece 3
        Pair(11, 14), Pair(14, 14), Pair(29, 5), Pair(28, 16), Pair(4, 29), Pair(117, -20), Pair(9, 26), Pair(71, -6),
        Pair(29, 8), Pair(2, 16), Pair(-6, 21), Pair(44, -7), Pair(24, 10), Pair(31, -24), Pair(-9, 12), Pair(13, 21),
        Pair(-30, 22), Pair(31, 13), Pair(1, 19), Pair(20, 8), Pair(24, 7), Pair(-19, 4), Pair(6, 2), Pair(20, 13),
        Pair(15, 19), Pair(15, 20), Pair(23, 8), Pair(6, 14), Pair(16, 4), Pair(31, -8), Pair(-24, -1), Pair(16, 20),
        Pair(18, 31), Pair(16, 13), Pair(30, 4), Pair(26, 4), Pair(7, 24), Pair(40, -22), Pair(3, 28), Pair(3, 24),
        Pair(13, 12), Pair(-14, 8), Pair(1, 20), Pair(7, 9), Pair(-36, 34), Pair(-13, -6), Pair(-26, 5), Pair(-25, 3),
        Pair(-2, 21), Pair(18, -4), Pair(20, -5), Pair(-1, 16), Pair(6, 13), Pair(10, -5), Pair(-2, 31), Pair(-36, 20),
        Pair(-1, 2), Pair(0, 16), Pair(2, 9), Pair(3, 10), Pair(-3, 7), Pair(3, -4), Pair(-16, 21), Pair(-1, 18)
      },
      { // Piece 4
        Pair(-77, 48), Pair(49, -9), Pair(12, -15), Pair(-20, 45), Pair(-35, 31), Pair(20, -4), Pair(-102, 45), Pair(-8, -3),
        Pair(1, -18), Pair(-16, 1), Pair(-8, 26), Pair(3, 14), Pair(3, 8), Pair(27, -16), Pair(3, -16), Pair(-50, 62),
        Pair(15, -18), Pair(19, 3), Pair(30, 7), Pair(15, -36), Pair(-33, 50), Pair(-34, 62), Pair(17, 30), Pair(-10, 4),
        Pair(-6, 27), Pair(-7, 68), Pair(27, 32), Pair(-6, 25), Pair(-19, 29), Pair(23, -41), Pair(-2, 17), Pair(-8, 2),
        Pair(-13, 17), Pair(-6, 21), Pair(3, 12), Pair(-21, 38), Pair(13, 47), Pair(-9, 36), Pair(0, 30), Pair(-14, -33),
        Pair(-24, 36), Pair(-5, 46), Pair(10, 19), Pair(3, 16), Pair(11, -7), Pair(45, -2), Pair(-27, 24), Pair(2, -69),
        Pair(-27, 15), Pair(-5, 19), Pair(-6, 18), Pair(-1, 6), Pair(5, 7), Pair(-18, 5), Pair(-18, -15), Pair(12, -31),
        Pair(-22, 15), Pair(9, 13), Pair(6, 7), Pair(0, -6), Pair(13, 1), Pair(27, -24), Pair(-41, -4), Pair(-36, -40)
      },
      { // Piece 5
        Pair(-12, 42), Pair(-7, -55), Pair(3, 62), Pair(-30, -20), Pair(45, 26), Pair(30, 56), Pair(-5, 147), Pair(-12, 14),
        Pair(30, 46), Pair(-45, 74), Pair(-33, -2), Pair(71, 73), Pair(27, 36), Pair(132, 24), Pair(67, 49), Pair(-55, 18),
        Pair(-32, -36), Pair(2, -4), Pair(-20, -4), Pair(-40, 85), Pair(-67, 75), Pair(76, 30), Pair(44, 58), Pair(93, 62),
        Pair(-2, -34), Pair(-7, -5), Pair(11, 2), Pair(-4, 26), Pair(-47, 44), Pair(-4, 34), Pair(-35, 32), Pair(35, 3),
        Pair(-156, 41), Pair(48, -21), Pair(5, -12), Pair(-19, 12), Pair(-26, 22), Pair(40, 4), Pair(1, 10), Pair(10, -3),
        Pair(-55, -20), Pair(-27, 10), Pair(1, 8), Pair(-20, 14), Pair(16, 6), Pair(4, 7), Pair(16, -9), Pair(4, -12),
        Pair(-29, -20), Pair(-20, -1), Pair(33, -2), Pair(-18, -5), Pair(2, 3), Pair(-29, 15), Pair(0, -2), Pair(20, -13),
        Pair(27, -10), Pair(-9, -25), Pair(-20, -14), Pair(-15, -7), Pair(-13, 3), Pair(-38, 2), Pair(0, -6), Pair(20, -21)
      }
    }},
    {{ // Bucket 22
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(18, -31), Pair(2, -10), Pair(-9, -10), Pair(17, -16), Pair(-14, -4), Pair(-148, 29), Pair(-16, 48), Pair(-113, 26),
        Pair(1, 3), Pair(13, 1), Pair(-19, -3), Pair(-16, 1), Pair(2, -1), Pair(-16, 27), Pair(30, 24), Pair(7, 17),
        Pair(1, 3), Pair(3, 1), Pair(2, 1), Pair(5, -3), Pair(3, 5), Pair(-28, 8), Pair(7, 14), Pair(-11, 12),
        Pair(0, 5), Pair(-2, 10), Pair(0, 7), Pair(0, 6), Pair(0, 5), Pair(8, 2), Pair(16, 0), Pair(3, -6),
        Pair(-1, 9), Pair(0, 10), Pair(0, 5), Pair(0, 7), Pair(1, 4), Pair(7, 4), Pair(0, 0), Pair(-3, -5),
        Pair(1, 8), Pair(0, 11), Pair(-2, 9), Pair(3, 10), Pair(3, 10), Pair(12, 9), Pair(-1, 6), Pair(1, 7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(68, 54), Pair(-17, 33), Pair(0, 5), Pair(49, -4), Pair(3, 35), Pair(51, 15), Pair(60, 45), Pair(72, -23),
        Pair(15, 29), Pair(-6, 5), Pair(2, 3), Pair(26, 18), Pair(12, 2), Pair(16, 1), Pair(-35, 10), Pair(-6, -32),
        Pair(-13, 20), Pair(-18, 27), Pair(-15, 18), Pair(-2, 8), Pair(1, 9), Pair(23, 8), Pair(-35, -3), Pair(4, -26),
        Pair(-2, 12), Pair(7, 8), Pair(0, 18), Pair(6, 14), Pair(4, 23), Pair(-4, 15), Pair(-4, 1), Pair(3, 11),
        Pair(-7, 9), Pair(-14, 12), Pair(9, 17), Pair(4, 16), Pair(6, 16), Pair(2, 6), Pair(19, -4), Pair(3, 14),
        Pair(-5, 3), Pair(-3, 6), Pair(0, 25), Pair(9, 18), Pair(7, 8), Pair(0, 14), Pair(30, -19), Pair(-16, 9),
        Pair(-33, 14), Pair(7, 41), Pair(0, 19), Pair(2, 14), Pair(-13, 11), Pair(9, 7), Pair(5, 25), Pair(-5, -33),
        Pair(-47, 6), Pair(-7, -7), Pair(2, -1), Pair(-19, 34), Pair(0, 18), Pair(-5, 5), Pair(-7, -15), Pair(-111, 31)
      },
      { // Piece 2
        Pair(-55, 1), Pair(-77, 38), Pair(-23, -1), Pair(76, -36), Pair(1, 13), Pair(20, -6), Pair(36, 5), Pair(-39, -32),
        Pair(32, -7), Pair(11, -9), Pair(-2, -5), Pair(37, -23), Pair(37, -11), Pair(77, -21), Pair(12, -19), Pair(-3, 36),
        Pair(18, -16), Pair(8, -26), Pair(35, -4), Pair(-11, -13), Pair(8, -13), Pair(-15, 22), Pair(6, 9), Pair(-5, -21),
        Pair(0, 11), Pair(16, -5), Pair(7, -6), Pair(1, 4), Pair(-15, -6), Pair(18, -18), Pair(-3, -12), Pair(-17, 0),
        Pair(-2, 7), Pair(-1, 1), Pair(-4, 22), Pair(9, 1), Pair(11, 7), Pair(-17, -4), Pair(-9, 14), Pair(0, 4),
        Pair(-8, -20), Pair(6, 14), Pair(-4, -3), Pair(2, 13), Pair(-4, 4), Pair(6, 5), Pair(-81, 74), Pair(1, -6),
        Pair(-5, 9), Pair(-4, 2), Pair(7, 13), Pair(-4, 12), Pair(-3, 21), Pair(17, -17), Pair(13, 18), Pair(-65, -65),
        Pair(-3, 3), Pair(-3, -1), Pair(-7, -1), Pair(0, 22), Pair(-5, 7), Pair(10, -2), Pair(45, -1), Pair(7, -6)
      },
      { // Piece 3
        Pair(0, 14), Pair(-18, 13), Pair(71, -19), Pair(-2, 5), Pair(23, 18), Pair(-24, 27), Pair(19, 0), Pair(25, 19),
        Pair(11, 9), Pair(0, 13), Pair(-7, 7), Pair(23, 7), Pair(20, 5), Pair(18, 11), Pair(79, -26), Pair(-22, 15),
        Pair(7, 19), Pair(39, -4), Pair(10, 5), Pair(27, -6), Pair(12, 7), Pair(4, -1), Pair(85, -29), Pair(14, 11),
        Pair(6, 3), Pair(12, 5), Pair(25, -1), Pair(2, 18), Pair(18, 0), Pair(-19, 14), Pair(37, 11), Pair(7, 10),
        Pair(-13, 36), Pair(-5, 23), Pair(12, 10), Pair(22, 8), Pair(-2, 10), Pair(12, 14), Pair(40, 1), Pair(1, 15),
        Pair(-1, 19), Pair(9, -10), Pair(-4, 8), Pair(-8, 10), Pair(7, -3), Pair(-13, 15), Pair(67, -68), Pair(-25, -7),
        Pair(-7, 30), Pair(9, -2), Pair(3, 10), Pair(8, 7), Pair(6, 7), Pair(-4, -2), Pair(-6, -8), Pair(-24, 31),
        Pair(1, 8), Pair(10, 2), Pair(7, 10), Pair(0, 5), Pair(1, 12), Pair(1, 4), Pair(-12, 2), Pair(-14, 7)
      },
      { // Piece 4
        Pair(-5, 28), Pair(40, -47), Pair(24, -41), Pair(-5, -10), Pair(15, -16), Pair(15, -39), Pair(93, -59), Pair(49, -62),
        Pair(-3, 16), Pair(-16, 15), Pair(29, -15), Pair(2, -7), Pair(24, -13), Pair(41, -10), Pair(91, -105), Pair(15, -49),
        Pair(-3, 11), Pair(4, 10), Pair(3, 5), Pair(16, -23), Pair(-22, 12), Pair(25, 1), Pair(-10, 23), Pair(20, -15),
        Pair(4, 10), Pair(-19, 20), Pair(-11, 27), Pair(-4, -1), Pair(4, -25), Pair(-9, -10), Pair(2, -5), Pair(-7, -21),
        Pair(3, 13), Pair(13, -19), Pair(8, 20), Pair(1, -8), Pair(-6, 23), Pair(-1, -6), Pair(-12, 12), Pair(-13, 6),
        Pair(19, -16), Pair(8, 19), Pair(7, 3), Pair(-4, 10), Pair(9, 5), Pair(-5, 7), Pair(-14, -42), Pair(-34, 9),
        Pair(8, 7), Pair(11, 8), Pair(5, 12), Pair(4, 11), Pair(8, 9), Pair(1, -4), Pair(2, -6), Pair(-6, -33),
        Pair(5, 11), Pair(13, 15), Pair(4, 15), Pair(1, 9), Pair(-1, 4), Pair(-2, 4), Pair(-29, 89), Pair(-24, 31)
      },
      { // Piece 5
        Pair(7, 66), Pair(17, -55), Pair(-27, 83), Pair(38, 22), Pair(-69, -9), Pair(24, 40), Pair(23, 39), Pair(11, 43),
        Pair(25, -42), Pair(-99, 29), Pair(-56, 23), Pair(-5, 57), Pair(-19, 78), Pair(66, 52), Pair(10, 70), Pair(13, 71),
        Pair(-51, -24), Pair(52, 17), Pair(-43, 14), Pair(-30, 33), Pair(30, 19), Pair(96, 45), Pair(20, 53), Pair(-44, 68),
        Pair(-79, -22), Pair(-158, 13), Pair(-74, 23), Pair(5, 16), Pair(-49, 27), Pair(64, 17), Pair(83, 16), Pair(29, 25),
        Pair(-104, 1), Pair(12, 14), Pair(23, 13), Pair(-20, 10), Pair(-13, 18), Pair(-30, 32), Pair(26, 19), Pair(21, 27),
        Pair(-34, -26), Pair(-55, 4), Pair(10, -12), Pair(7, 0), Pair(0, 3), Pair(-2, 0), Pair(38, -26), Pair(3, -12),
        Pair(-29, -26), Pair(-72, 19), Pair(-36, 3), Pair(-20, 10), Pair(0, 1), Pair(-18, 4), Pair(0, 5), Pair(-6, -11),
        Pair(-48, -3), Pair(-31, -17), Pair(-38, 2), Pair(4, -14), Pair(3, -9), Pair(7, -10), Pair(7, -5), Pair(-23, -8)
      }
    }},
    {{ // Bucket 23
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-13, -19), Pair(-5, -18), Pair(25, 23), Pair(30, -25), Pair(-4, -36), Pair(29, -24), Pair(-2, -2), Pair(-6, 11),
        Pair(5, -2), Pair(8, 2), Pair(14, -8), Pair(13, 8), Pair(3, 8), Pair(-9, 12), Pair(-8, 6), Pair(37, 22),
        Pair(0, 8), Pair(-3, 4), Pair(1, 3), Pair(4, -4), Pair(2, 0), Pair(-5, 0), Pair(-19, 16), Pair(6, 13),
        Pair(-2, 6), Pair(3, 8), Pair(4, 6), Pair(0, 5), Pair(0, 1), Pair(2, 5), Pair(4, -2), Pair(-9, 6),
        Pair(2, 10), Pair(1, 8), Pair(0, 8), Pair(2, 5), Pair(3, 9), Pair(2, 0), Pair(-4, -5), Pair(3, -5),
        Pair(-3, 12), Pair(1, 10), Pair(0, 6), Pair(0, 1), Pair(5, 4), Pair(2, 4), Pair(6, 6), Pair(-16, 7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-2, 4), Pair(-65, 116), Pair(-84, 49), Pair(42, 44), Pair(32, -6), Pair(-66, 41), Pair(-72, 62), Pair(-11, -7),
        Pair(-13, -7), Pair(1, 11), Pair(-11, 11), Pair(30, 2), Pair(46, -28), Pair(-3, 4), Pair(28, 47), Pair(-10, 2),
        Pair(-14, -3), Pair(-9, -3), Pair(13, 2), Pair(14, 6), Pair(13, 7), Pair(34, 0), Pair(15, 4), Pair(-3, -3),
        Pair(-32, 2), Pair(9, 1), Pair(4, 18), Pair(10, 14), Pair(4, 10), Pair(10, 1), Pair(12, 16), Pair(13, 1),
        Pair(-1, 3), Pair(-6, 13), Pair(4, 10), Pair(-4, 17), Pair(0, 15), Pair(3, 5), Pair(3, 7), Pair(-9, 16),
        Pair(-7, 27), Pair(7, -10), Pair(-2, 14), Pair(-10, 23), Pair(-10, 21), Pair(-3, 8), Pair(0, 13), Pair(-37, 38),
        Pair(19, 19), Pair(-7, 35), Pair(-11, -8), Pair(-6, 16), Pair(-2, 13), Pair(-5, 8), Pair(-11, -5), Pair(-5, 8),
        Pair(-9, 19), Pair(-15, 14), Pair(22, -4), Pair(-32, 48), Pair(2, -19), Pair(-3, -29), Pair(-10, 24), Pair(-31, 51)
      },
      { // Piece 2
        Pair(15, -65), Pair(3, 2), Pair(-13, -20), Pair(82, -24), Pair(47, -18), Pair(-32, -40), Pair(-13, -18), Pair(-5, 32),
        Pair(5, 10), Pair(15, -34), Pair(-7, -3), Pair(19, -43), Pair(-9, -5), Pair(9, -33), Pair(44, 15), Pair(8, -23),
        Pair(6, -29), Pair(7, 2), Pair(8, -14), Pair(4, -22), Pair(3, -17), Pair(14, 3), Pair(8, -2), Pair(-2, -13),
        Pair(2, 1), Pair(-4, -11), Pair(15, 0), Pair(15, -22), Pair(0, 10), Pair(6, -23), Pair(-9, 25), Pair(-8, 12),
        Pair(-16, 0), Pair(-4, 12), Pair(10, -8), Pair(-7, 10), Pair(10, -1), Pair(-9, 15), Pair(9, 19), Pair(1, 14),
        Pair(-9, 0), Pair(-3, -4), Pair(0, 8), Pair(3, 1), Pair(4, 13), Pair(-5, 0), Pair(8, -11), Pair(17, -22),
        Pair(-4, -24), Pair(1, 12), Pair(-1, -7), Pair(3, 12), Pair(-6, 3), Pair(3, 0), Pair(8, -2), Pair(-1, -3),
        Pair(10, 12), Pair(-10, -6), Pair(2, 6), Pair(-3, -8), Pair(5, 22), Pair(1, -4), Pair(18, 6), Pair(-15, -31)
      },
      { // Piece 3
        Pair(4, 8), Pair(6, 21), Pair(5, 12), Pair(-17, 14), Pair(-40, 26), Pair(-9, 17), Pair(66, -18), Pair(67, -17),
        Pair(-3, 23), Pair(7, 11), Pair(14, 17), Pair(28, 1), Pair(-8, 16), Pair(21, -10), Pair(1, 39), Pair(122, -52),
        Pair(9, 8), Pair(20, 8), Pair(23, 9), Pair(30, -8), Pair(4, -7), Pair(67, -15), Pair(-2, 22), Pair(-29, -1),
        Pair(9, 4), Pair(31, 4), Pair(4, 14), Pair(17, 2), Pair(7, 6), Pair(42, -17), Pair(-23, 12), Pair(3, -5),
        Pair(3, 7), Pair(8, 18), Pair(-10, 24), Pair(13, 7), Pair(4, 12), Pair(2, 4), Pair(-15, 37), Pair(-15, -8),
        Pair(2, 2), Pair(-2, 0), Pair(9, -9), Pair(7, -5), Pair(4, 16), Pair(2, 8), Pair(-18, 11), Pair(-13, -41),
        Pair(5, 9), Pair(4, -1), Pair(7, 9), Pair(-3, 5), Pair(7, 14), Pair(-6, 8), Pair(25, -22), Pair(-70, 8),
        Pair(0, 8), Pair(-1, 2), Pair(3, 1), Pair(0, 11), Pair(4, 9), Pair(4, 5), Pair(-10, 9), Pair(-21, -7)
      },
      { // Piece 4
        Pair(-15, -15), Pair(-1, -38), Pair(47, -59), Pair(47, -25), Pair(-2, 6), Pair(-33, 75), Pair(-74, -5), Pair(-21, 31),
        Pair(-7, 3), Pair(-15, -10), Pair(-11, 2), Pair(9, 7), Pair(-8, 27), Pair(-16, 16), Pair(7, -12), Pair(3, 12),
        Pair(0, -22), Pair(-15, 5), Pair(-3, 14), Pair(-2, 5), Pair(14, -38), Pair(36, -14), Pair(-3, 41), Pair(6, -2),
        Pair(0, -1), Pair(19, -4), Pair(9, -11), Pair(-12, -4), Pair(-6, 13), Pair(-1, -16), Pair(5, 3), Pair(14, -22),
        Pair(1, 30), Pair(1, 21), Pair(1, -1), Pair(4, 4), Pair(-8, 26), Pair(1, -5), Pair(0, -12), Pair(-6, 1),
        Pair(8, -15), Pair(-3, 20), Pair(-8, 7), Pair(1, -7), Pair(-2, 5), Pair(-2, 13), Pair(-2, -9), Pair(-23, -12),
        Pair(-8, 36), Pair(-5, 8), Pair(2, 6), Pair(3, 10), Pair(-1, 9), Pair(2, -18), Pair(3, -10), Pair(-50, -4),
        Pair(-3, -2), Pair(-1, 10), Pair(-7, 15), Pair(1, -1), Pair(3, -10), Pair(4, -37), Pair(-17, 35), Pair(-14, 39)
      },
      { // Piece 5
        Pair(24, -53), Pair(10, 73), Pair(102, 45), Pair(-40, -73), Pair(2, 3), Pair(16, 26), Pair(-30, 53), Pair(50, -42),
        Pair(43, -45), Pair(36, -29), Pair(45, 5), Pair(40, 55), Pair(-15, 51), Pair(44, 77), Pair(28, 96), Pair(-20, -30),
        Pair(-28, 36), Pair(-100, 24), Pair(14, 27), Pair(4, 21), Pair(65, 13), Pair(2, 43), Pair(8, 50), Pair(36, 26),
        Pair(-49, 19), Pair(-61, -2), Pair(-25, 35), Pair(-114, 36), Pair(-135, 32), Pair(109, 7), Pair(51, 20), Pair(18, 15),
        Pair(53, -36), Pair(-54, 16), Pair(-101, 30), Pair(-62, 32), Pair(13, 20), Pair(-27, 22), Pair(5, 21), Pair(-4, 14),
        Pair(-9, -28), Pair(-36, 24), Pair(-51, 37), Pair(-3, 12), Pair(-8, 15), Pair(-9, 10), Pair(-35, -9), Pair(-10, 14),
        Pair(-49, 18), Pair(-61, 5), Pair(-35, 17), Pair(-16, 10), Pair(-21, 4), Pair(-9, 7), Pair(-27, 0), Pair(-22, -16),
        Pair(-59, -9), Pair(-43, 19), Pair(-45, 12), Pair(-24, 6), Pair(-9, -6), Pair(0, 1), Pair(12, 0), Pair(1, -19)
      }
    }},
    {{ // Bucket 24
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-23, 13), Pair(23, 39), Pair(-24, 10), Pair(49, -28), Pair(-52, 3), Pair(0, -49), Pair(-16, 50), Pair(-63, 18),
        Pair(-5, -6), Pair(8, 35), Pair(-5, 19), Pair(-2, 12), Pair(-9, 4), Pair(-14, -4), Pair(8, -21), Pair(-14, 15),
        Pair(2, 13), Pair(2, 4), Pair(-2, 4), Pair(4, 0), Pair(0, -2), Pair(8, 7), Pair(-1, 8), Pair(-4, 13),
        Pair(-4, -1), Pair(-10, 1), Pair(3, 4), Pair(4, 2), Pair(2, 8), Pair(0, 6), Pair(1, 14), Pair(-1, 11),
        Pair(17, 12), Pair(-5, 0), Pair(0, 11), Pair(1, 4), Pair(0, 8), Pair(5, 7), Pair(-1, 10), Pair(3, 11),
        Pair(12, 14), Pair(-6, 3), Pair(0, 5), Pair(-1, 8), Pair(-3, 13), Pair(-3, 13), Pair(-1, 11), Pair(1, 11),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-83, -54), Pair(-34, -10), Pair(-46, 53), Pair(-59, 57), Pair(24, 34), Pair(-84, 5), Pair(-67, 16), Pair(42, 69),
        Pair(-7, 14), Pair(18, 15), Pair(0, 5), Pair(56, 7), Pair(9, -3), Pair(9, 21), Pair(-5, 5), Pair(-44, 25),
        Pair(9, -26), Pair(3, 2), Pair(-22, 27), Pair(-17, 22), Pair(27, 4), Pair(-35, 24), Pair(-12, 37), Pair(-10, -36),
        Pair(-12, -10), Pair(-2, 18), Pair(-11, 20), Pair(-2, 31), Pair(-5, 24), Pair(5, 17), Pair(-2, 14), Pair(-14, 30),
        Pair(9, 38), Pair(-14, 31), Pair(5, 21), Pair(-2, 18), Pair(-6, 22), Pair(3, 17), Pair(6, 14), Pair(-2, -5),
        Pair(-4, 22), Pair(1, 15), Pair(0, 8), Pair(7, 18), Pair(13, 16), Pair(2, 8), Pair(7, 8), Pair(2, -21),
        Pair(0, 5), Pair(18, -7), Pair(2, 7), Pair(-1, 16), Pair(-9, 25), Pair(-8, 28), Pair(-5, -8), Pair(-9, 32),
        Pair(16, -35), Pair(-11, -23), Pair(6, 21), Pair(3, 8), Pair(1, 17), Pair(-6, 4), Pair(-3, 32), Pair(55, -44)
      },
      { // Piece 2
        Pair(-70, 30), Pair(59, -14), Pair(30, -4), Pair(-28, 7), Pair(33, -17), Pair(-19, -16), Pair(6, -24), Pair(-89, 18),
        Pair(-18, 23), Pair(6, -7), Pair(25, -5), Pair(-3, 2), Pair(50, -30), Pair(-23, -7), Pair(-6, -10), Pair(-12, 22),
        Pair(1, -2), Pair(14, 1), Pair(23, -9), Pair(1, -13), Pair(10, -10), Pair(40, -19), Pair(-8, -21), Pair(-12, 12),
        Pair(9, -3), Pair(15, 25), Pair(6, 11), Pair(4, -8), Pair(15, -8), Pair(25, -14), Pair(-1, -3), Pair(10, 8),
        Pair(32, 33), Pair(6, 11), Pair(13, 8), Pair(4, 8), Pair(4, -6), Pair(0, -2), Pair(-7, 4), Pair(8, 41),
        Pair(9, 2), Pair(12, 0), Pair(4, 0), Pair(3, 9), Pair(2, 2), Pair(-4, 27), Pair(9, 17), Pair(-6, -15),
        Pair(24, -76), Pair(1, -2), Pair(-2, -3), Pair(2, 8), Pair(-3, 16), Pair(-1, 13), Pair(4, 10), Pair(13, 14),
        Pair(27, -40), Pair(-25, -35), Pair(-5, -10), Pair(13, -6), Pair(17, -5), Pair(1, 4), Pair(7, 15), Pair(-13, 4)
      },
      { // Piece 3
        Pair(-41, 17), Pair(37, 19), Pair(-37, 31), Pair(-8, 29), Pair(-26, 33), Pair(-44, 8), Pair(-83, 53), Pair(-79, 40),
        Pair(-7, -6), Pair(-5, 31), Pair(7, 16), Pair(-28, 26), Pair(4, 21), Pair(4, 27), Pair(-28, 24), Pair(68, 2),
        Pair(-14, -4), Pair(17, 14), Pair(12, 18), Pair(-1, 12), Pair(16, 27), Pair(37, -6), Pair(-35, 38), Pair(34, 21),
        Pair(-19, -18), Pair(1, 32), Pair(0, 32), Pair(7, 2), Pair(6, 17), Pair(-13, 36), Pair(-9, 25), Pair(20, 16),
        Pair(-19, 3), Pair(10, 29), Pair(5, 18), Pair(5, 11), Pair(-2, 22), Pair(-12, 16), Pair(49, 0), Pair(34, 13),
        Pair(-18, 30), Pair(-7, 14), Pair(5, 20), Pair(1, 19), Pair(3, 5), Pair(8, 0), Pair(7, 4), Pair(19, 7),
        Pair(-25, -1), Pair(18, -6), Pair(2, 8), Pair(4, 14), Pair(-2, 11), Pair(-5, 19), Pair(-12, 4), Pair(44, -20),
        Pair(-8, 0), Pair(2, 10), Pair(0, 17), Pair(4, 18), Pair(-2, 21), Pair(-1, 11), Pair(7, 0), Pair(7, 7)
      },
      { // Piece 4
        Pair(-25, 15), Pair(2, -14), Pair(-12, 28), Pair(-30, 33), Pair(5, 19), Pair(-16, -4), Pair(31, 2), Pair(27, -16),
        Pair(-11, -6), Pair(-13, 36), Pair(-20, 34), Pair(-3, -8), Pair(7, -22), Pair(-5, 45), Pair(-49, 33), Pair(-24, 2),
        Pair(-3, -39), Pair(6, 34), Pair(0, 24), Pair(-10, -2), Pair(7, 22), Pair(19, -62), Pair(10, -29), Pair(-43, 37),
        Pair(9, -10), Pair(-5, 38), Pair(-28, 48), Pair(-21, 26), Pair(-3, 2), Pair(16, 1), Pair(5, -2), Pair(2, 27),
        Pair(-14, 61), Pair(-8, 58), Pair(3, 10), Pair(-4, 47), Pair(-1, 28), Pair(5, -3), Pair(1, 27), Pair(7, -3),
        Pair(-13, 9), Pair(6, 17), Pair(11, 7), Pair(4, 25), Pair(8, 44), Pair(6, -2), Pair(10, 7), Pair(14, -33),
        Pair(-5, 43), Pair(6, 7), Pair(-1, 25), Pair(3, 32), Pair(8, -1), Pair(8, 8), Pair(0, 20), Pair(6, 12),
        Pair(-21, 5), Pair(3, -11), Pair(5, 13), Pair(2, 9), Pair(-8, 40), Pair(5, 42), Pair(-8, 73), Pair(-64, 73)
      },
      { // Piece 5
        Pair(-17, 1), Pair(35, 100), Pair(14, 7), Pair(69, 4), Pair(-1, 58), Pair(87, 7), Pair(-22, 51), Pair(30, 92),
        Pair(25, 57), Pair(113, 112), Pair(-17, 38), Pair(-8, -7), Pair(-28, 60), Pair(58, 37), Pair(47, 33), Pair(89, -52),
        Pair(30, 6), Pair(3, 121), Pair(-51, 74), Pair(3, 51), Pair(27, 69), Pair(-42, 32), Pair(-67, 22), Pair(-74, 48),
        Pair(69, -4), Pair(25, 64), Pair(-2, 66), Pair(59, 25), Pair(-14, 30), Pair(13, 11), Pair(36, 6), Pair(-3, 6),
        Pair(9, 38), Pair(4, 42), Pair(-49, 47), Pair(-10, 32), Pair(-26, 32), Pair(41, 8), Pair(-11, 16), Pair(28, -6),
        Pair(53, -3), Pair(9, 19), Pair(19, 18), Pair(26, 26), Pair(10, 21), Pair(-22, 15), Pair(-10, 2), Pair(-23, 6),
        Pair(52, -14), Pair(65, 12), Pair(30, 15), Pair(23, 9), Pair(-13, 15), Pair(-2, 11), Pair(2, 6), Pair(-7, 1),
        Pair(16, -38), Pair(84, -2), Pair(33, -9), Pair(-30, 26), Pair(-3, 0), Pair(-18, 7), Pair(1, 0), Pair(-8, -2)
      }
    }},
    {{ // Bucket 25
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(7, 20), Pair(19, 15), Pair(-5, 17), Pair(-40, 40), Pair(111, -27), Pair(-3, 25), Pair(13, 35), Pair(-30, -16),
        Pair(-23, 6), Pair(41, -19), Pair(0, 19), Pair(-28, 11), Pair(-13, 11), Pair(-2, 13), Pair(16, 16), Pair(8, 15),
        Pair(-14, 1), Pair(6, 7), Pair(12, 1), Pair(5, -5), Pair(5, 6), Pair(-2, 17), Pair(-4, 8), Pair(6, 12),
        Pair(-2, 2), Pair(-1, 3), Pair(-2, 1), Pair(2, 6), Pair(2, 15), Pair(4, 8), Pair(2, 15), Pair(-2, 16),
        Pair(4, 4), Pair(1, 30), Pair(2, 5), Pair(1, 16), Pair(1, 11), Pair(7, 11), Pair(2, 14), Pair(5, 13),
        Pair(-7, 13), Pair(8, 24), Pair(-2, 11), Pair(-2, 23), Pair(0, 7), Pair(-2, 13), Pair(2, 15), Pair(0, 15),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-43, 54), Pair(125, -25), Pair(-7, 43), Pair(-110, 18), Pair(2, 55), Pair(-6, 48), Pair(-25, -35), Pair(-38, -42),
        Pair(-10, 12), Pair(44, 18), Pair(14, 7), Pair(14, 63), Pair(-2, 34), Pair(12, 2), Pair(63, 18), Pair(-99, 74),
        Pair(27, 8), Pair(-28, 24), Pair(15, 29), Pair(-9, 47), Pair(-26, 52), Pair(-41, 47), Pair(0, 21), Pair(4, 20),
        Pair(25, 9), Pair(11, 17), Pair(7, 29), Pair(13, 32), Pair(10, 32), Pair(11, 35), Pair(15, 8), Pair(-11, 59),
        Pair(8, 36), Pair(28, 62), Pair(10, 41), Pair(12, 24), Pair(-5, 28), Pair(8, 45), Pair(-21, 58), Pair(2, 33),
        Pair(-5, 25), Pair(16, 28), Pair(-5, 33), Pair(-1, 35), Pair(0, 34), Pair(7, 27), Pair(-4, 10), Pair(16, 11),
        Pair(12, 14), Pair(6, 53), Pair(7, 36), Pair(4, 24), Pair(11, 21), Pair(5, 34), Pair(-9, 53), Pair(0, 37),
        Pair(68, -39), Pair(-6, -8), Pair(-2, -22), Pair(-12, 12), Pair(11, 19), Pair(-3, 21), Pair(1, 10), Pair(28, -67)
      },
      { // Piece 2
        Pair(49, 24), Pair(22, -13), Pair(-44, 30), Pair(57, -43), Pair(45, 7), Pair(52, -30), Pair(57, 13), Pair(-56, 81),
        Pair(14, 10), Pair(21, 8), Pair(39, -11), Pair(-65, 15), Pair(113, -9), Pair(20, 11), Pair(-21, -6), Pair(-2, -12),
        Pair(18, 29), Pair(20, -12), Pair(41, 31), Pair(0, 15), Pair(22, -2), Pair(-1, -19), Pair(-21, -23), Pair(-26, 16),
        Pair(-18, 53), Pair(-15, 14), Pair(22, 38), Pair(4, -4), Pair(8, 4), Pair(28, 4), Pair(5, 7), Pair(5, 19),
        Pair(26, 5), Pair(23, 46), Pair(6, 13), Pair(10, -5), Pair(30, 5), Pair(-6, 16), Pair(18, -9), Pair(16, 12),
        Pair(13, -20), Pair(9, 0), Pair(2, 18), Pair(5, 21), Pair(-8, 25), Pair(10, 18), Pair(8, 17), Pair(12, 28),
        Pair(10, -58), Pair(0, 7), Pair(-1, 20), Pair(-1, 17), Pair(1, 12), Pair(-6, 19), Pair(13, 29), Pair(13, 31),
        Pair(-8, -12), Pair(32, 14), Pair(-2, -5), Pair(8, -11), Pair(-1, 25), Pair(4, 22), Pair(22, 79), Pair(37, 1)
      },
      { // Piece 3
        Pair(-39, 55), Pair(-43, 48), Pair(-25, 37), Pair(-15, 45), Pair(-5, 35), Pair(-27, 45), Pair(-24, 62), Pair(44, 15),
        Pair(2, 25), Pair(-7, 32), Pair(-19, 47), Pair(15, 34), Pair(33, 14), Pair(-51, 70), Pair(29, 35), Pair(23, 36),
        Pair(-14, 44), Pair(-28, 14), Pair(-3, 46), Pair(19, 37), Pair(20, 6), Pair(24, 66), Pair(28, 39), Pair(20, 39),
        Pair(3, 32), Pair(-32, 19), Pair(-5, 36), Pair(-14, 39), Pair(-17, 38), Pair(11, 28), Pair(-7, 49), Pair(-6, 65),
        Pair(-13, 37), Pair(-46, 63), Pair(11, 35), Pair(-3, 44), Pair(1, 42), Pair(7, 30), Pair(-31, 75), Pair(21, 4),
        Pair(-5, 36), Pair(-3, 23), Pair(4, 22), Pair(11, 37), Pair(-1, 36), Pair(-7, 34), Pair(-23, 25), Pair(24, -19),
        Pair(21, 49), Pair(-24, 7), Pair(0, 32), Pair(0, 42), Pair(0, 23), Pair(10, 23), Pair(15, 30), Pair(4, 18),
        Pair(3, 24), Pair(-6, 29), Pair(1, 37), Pair(0, 40), Pair(5, 28), Pair(1, 23), Pair(-13, 39), Pair(6, 32)
      },
      { // Piece 4
        Pair(24, 57), Pair(-22, 44), Pair(7, -17), Pair(-84, 62), Pair(-48, 49), Pair(50, -35), Pair(-32, 81), Pair(-20, 19),
        Pair(-21, 39), Pair(-26, 15), Pair(-8, 26), Pair(53, -29), Pair(11, -16), Pair(-20, 58), Pair(40, -45), Pair(-29, 40),
        Pair(-3, -10), Pair(29, -46), Pair(0, 10), Pair(-8, 10), Pair(15, 20), Pair(32, 30), Pair(-33, -8), Pair(32, -24),
        Pair(-18, -9), Pair(5, 0), Pair(-13, 32), Pair(-13, 39), Pair(5, 6), Pair(10, 64), Pair(-21, 43), Pair(-5, 29),
        Pair(5, 19), Pair(-6, 26), Pair(19, 10), Pair(5, 29), Pair(-12, 36), Pair(-20, 42), Pair(13, -3), Pair(3, -61),
        Pair(-21, 46), Pair(0, 18), Pair(2, 32), Pair(5, 13), Pair(-4, 38), Pair(3, 38), Pair(-9, -10), Pair(18, -13),
        Pair(11, -14), Pair(-1, 18), Pair(4, 11), Pair(2, 33), Pair(2, 14), Pair(15, 2), Pair(-2, 27), Pair(-3, -31),
        Pair(0, 1), Pair(3, 7), Pair(-5, 28), Pair(-5, 46), Pair(-19, 63), Pair(-29, 54), Pair(-7, 47), Pair(24, 17)
      },
      { // Piece 5
        Pair(-6, -3), Pair(-9, 95), Pair(12, 190), Pair(69, 62), Pair(-23, 26), Pair(6, 6), Pair(-36, 75), Pair(27, 202),
        Pair(-67, 114), Pair(-131, 166), Pair(-11, 155), Pair(39, 50), Pair(121, 49), Pair(44, 16), Pair(54, 40), Pair(34, -16),
        Pair(-18, 104), Pair(46, 83), Pair(253, 55), Pair(-22, 83), Pair(-81, 66), Pair(93, 25), Pair(-78, 19), Pair(-21, 12),
        Pair(92, 83), Pair(45, 71), Pair(97, 62), Pair(71, 66), Pair(89, 15), Pair(-59, 19), Pair(47, 10), Pair(-27, 8),
        Pair(12, 47), Pair(47, 64), Pair(52, 44), Pair(-60, 51), Pair(30, 28), Pair(-19, 21), Pair(-17, 23), Pair(-19, -10),
        Pair(-6, 35), Pair(-11, 37), Pair(30, 31), Pair(23, 25), Pair(-39, 29), Pair(-20, 19), Pair(-42, 14), Pair(-30, 15),
        Pair(89, 35), Pair(24, 25), Pair(36, 20), Pair(14, 15), Pair(22, 7), Pair(-24, 21), Pair(-13, 8), Pair(-4, -1),
        Pair(36, -53), Pair(18, 4), Pair(26, 1), Pair(3, 23), Pair(-14, 17), Pair(-28, 8), Pair(-1, 0), Pair(-9, -8)
      }
    }},
    {{ // Bucket 26
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-7, -1), Pair(-35, 43), Pair(-51, 21), Pair(28, 17), Pair(-24, 40), Pair(6, 55), Pair(69, -25), Pair(-21, 3),
        Pair(1, 6), Pair(-2, 16), Pair(2, 27), Pair(-12, 23), Pair(1, 4), Pair(-5, 8), Pair(-22, -1), Pair(12, -1),
        Pair(0, 5), Pair(2, -1), Pair(-8, -1), Pair(2, -6), Pair(12, 1), Pair(11, 8), Pair(3, -3), Pair(1, 6),
        Pair(1, 1), Pair(8, 7), Pair(3, -3), Pair(1, 17), Pair(-4, 5), Pair(3, 5), Pair(3, 9), Pair(0, 10),
        Pair(3, 5), Pair(3, 0), Pair(-2, 0), Pair(2, 7), Pair(0, 7), Pair(2, 9), Pair(1, 6), Pair(4, 8),
        Pair(2, 5), Pair(2, 1), Pair(3, 8), Pair(-4, 5), Pair(-2, 16), Pair(-3, 9), Pair(-1, 5), Pair(2, 9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-65, 44), Pair(-23, 6), Pair(102, 33), Pair(-27, 33), Pair(48, 96), Pair(54, -36), Pair(-64, -8), Pair(-135, -12),
        Pair(-16, -7), Pair(-1, 39), Pair(27, -5), Pair(40, 13), Pair(-40, 49), Pair(22, -8), Pair(55, 49), Pair(2, 41),
        Pair(39, 32), Pair(-22, 6), Pair(-23, 15), Pair(-7, 25), Pair(31, 24), Pair(-5, 51), Pair(6, 57), Pair(29, 37),
        Pair(-42, 22), Pair(-5, 18), Pair(-2, -4), Pair(24, 20), Pair(-4, 23), Pair(11, 22), Pair(0, 24), Pair(-8, 17),
        Pair(-5, 37), Pair(4, 44), Pair(20, 55), Pair(4, 25), Pair(-2, 27), Pair(8, 32), Pair(-7, 35), Pair(7, 22),
        Pair(-7, -7), Pair(-1, 11), Pair(4, 38), Pair(10, 41), Pair(7, 24), Pair(5, 20), Pair(0, 16), Pair(8, -26),
        Pair(7, 16), Pair(-9, 13), Pair(0, 26), Pair(1, 18), Pair(4, 16), Pair(20, 22), Pair(5, 27), Pair(-3, 22),
        Pair(8, 14), Pair(-3, -4), Pair(-21, 13), Pair(-28, 30), Pair(9, 14), Pair(-3, 12), Pair(-3, 9), Pair(4, -7)
      },
      { // Piece 2
        Pair(28, 2), Pair(-11, -6), Pair(44, -36), Pair(15, 3), Pair(11, -32), Pair(16, 3), Pair(-17, -15), Pair(38, -47),
        Pair(-12, 32), Pair(-12, -20), Pair(13, -23), Pair(24, -9), Pair(23, -8), Pair(21, -2), Pair(8, -34), Pair(12, -10),
        Pair(-21, 4), Pair(9, 5), Pair(30, -33), Pair(23, 17), Pair(28, -2), Pair(-10, -10), Pair(16, -5), Pair(18, -19),
        Pair(9, 8), Pair(-8, 15), Pair(13, 3), Pair(18, 3), Pair(12, -5), Pair(12, -9), Pair(6, -13), Pair(-6, 2),
        Pair(12, -23), Pair(1, 6), Pair(25, 21), Pair(15, 8), Pair(-1, -2), Pair(5, 3), Pair(10, -6), Pair(13, -6),
        Pair(-11, 26), Pair(-27, 4), Pair(13, 4), Pair(-3, 7), Pair(3, 8), Pair(5, 1), Pair(10, 10), Pair(1, -5),
        Pair(-13, -65), Pair(0, 13), Pair(1, -4), Pair(6, 9), Pair(-1, 1), Pair(-7, 40), Pair(-1, 12), Pair(0, 28),
        Pair(-9, 14), Pair(11, -20), Pair(-2, -4), Pair(22, -7), Pair(7, 11), Pair(-5, -2), Pair(6, -16), Pair(14, 3)
      },
      { // Piece 3
        Pair(-8, 43), Pair(-34, 45), Pair(-74, 37), Pair(7, 20), Pair(-63, 67), Pair(-8, 42), Pair(-29, 42), Pair(4, 18),
        Pair(5, 25), Pair(-1, 23), Pair(9, 14), Pair(-4, 17), Pair(-21, 32), Pair(-5, 28), Pair(-41, 42), Pair(24, 8),
        Pair(-3, 20), Pair(18, 8), Pair(-53, 17), Pair(-30, 48), Pair(-16, 46), Pair(8, 36), Pair(57, -1), Pair(-30, 29),
        Pair(13, 17), Pair(3, 25), Pair(-19, 6), Pair(8, 29), Pair(7, 22), Pair(-28, 32), Pair(3, 3), Pair(-7, 34),
        Pair(-10, 25), Pair(9, 6), Pair(-6, 13), Pair(3, 9), Pair(11, 19), Pair(-1, 22), Pair(15, 19), Pair(6, 16),
        Pair(-8, 38), Pair(15, 27), Pair(14, 0), Pair(0, 28), Pair(10, 24), Pair(-11, 29), Pair(-18, 26), Pair(-11, 46),
        Pair(-5, 16), Pair(18, 9), Pair(-16, -3), Pair(-6, 13), Pair(5, 3), Pair(-12, 20), Pair(0, -13), Pair(-7, 58),
        Pair(-4, 17), Pair(4, 17), Pair(-1, -7), Pair(-1, 16), Pair(0, 10), Pair(1, 9), Pair(1, 3), Pair(6, 11)
      },
      { // Piece 4
        Pair(18, 16), Pair(-69, 44), Pair(-77, 65), Pair(-5, 11), Pair(-27, 8), Pair(-34, 35), Pair(18, 39), Pair(-4, -6),
        Pair(-10, -31), Pair(7, -31), Pair(-46, -16), Pair(16, -26), Pair(12, -16), Pair(-6, 15), Pair(-42, 62), Pair(20, -31),
        Pair(-17, -8), Pair(5, 3), Pair(-2, -44), Pair(-25, 8), Pair(1, -3), Pair(-27, 15), Pair(21, -24), Pair(-17, 22),
        Pair(-29, 48), Pair(-21, 31), Pair(25, -43), Pair(-33, 51), Pair(17, -13), Pair(-18, 19), Pair(3, 9), Pair(0, -16),
        Pair(-11, -9), Pair(-11, 42), Pair(-7, 20), Pair(-1, 3), Pair(-13, 19), Pair(13, -1), Pair(-6, 26), Pair(-7, 8),
        Pair(4, -14), Pair(1, -5), Pair(1, 2), Pair(0, 12), Pair(6, 3), Pair(3, 13), Pair(-11, 18), Pair(-7, 51),
        Pair(-10, 24), Pair(0, 9), Pair(-4, 0), Pair(4, 1), Pair(0, 5), Pair(9, -2), Pair(-2, 30), Pair(-31, -23),
        Pair(7, -20), Pair(9, 3), Pair(0, -21), Pair(-3, 7), Pair(-5, 46), Pair(10, -15), Pair(5, 11), Pair(-21, -21)
      },
      { // Piece 5
        Pair(8, -30), Pair(27, 158), Pair(39, 64), Pair(133, 148), Pair(67, 30), Pair(84, -40), Pair(-3, 1), Pair(-17, 80),
        Pair(11, 13), Pair(13, 78), Pair(12, 93), Pair(16, 103), Pair(116, -9), Pair(-30, 33), Pair(-35, 14), Pair(-63, 41),
        Pair(58, 63), Pair(94, 82), Pair(155, 73), Pair(33, 69), Pair(93, 49), Pair(116, 16), Pair(-42, 12), Pair(-125, 38),
        Pair(125, 66), Pair(105, 70), Pair(51, 64), Pair(113, 51), Pair(4, 44), Pair(7, 32), Pair(-71, 17), Pair(-11, 33),
        Pair(-72, 52), Pair(1, 42), Pair(9, 50), Pair(33, 44), Pair(-58, 35), Pair(-13, 13), Pair(-6, 19), Pair(-1, -7),
        Pair(65, -22), Pair(28, 25), Pair(9, 29), Pair(-8, 27), Pair(-10, 23), Pair(3, 5), Pair(23, 3), Pair(16, 0),
        Pair(45, -19), Pair(6, 12), Pair(4, 4), Pair(25, 10), Pair(25, -6), Pair(-11, 9), Pair(-1, -1), Pair(-9, 1),
        Pair(45, -50), Pair(21, -19), Pair(22, -9), Pair(16, -16), Pair(2, 4), Pair(-5, -9), Pair(0, -9), Pair(-3, -8)
      }
    }},
    {{ // Bucket 27
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-56, 9), Pair(-70, 48), Pair(-36, -22), Pair(45, 20), Pair(-5, 15), Pair(58, -15), Pair(26, -19), Pair(60, 13),
        Pair(-10, 18), Pair(1, 9), Pair(5, 22), Pair(31, -27), Pair(6, 29), Pair(14, 21), Pair(-43, 39), Pair(-3, 19),
        Pair(-1, 7), Pair(-1, -6), Pair(7, -7), Pair(2, -2), Pair(8, -3), Pair(11, 6), Pair(2, 2), Pair(-3, 4),
        Pair(-1, 1), Pair(2, 3), Pair(-1, 2), Pair(1, -3), Pair(0, 11), Pair(-2, 5), Pair(9, 6), Pair(-1, 2),
        Pair(-1, 4), Pair(4, 5), Pair(5, 8), Pair(15, -3), Pair(5, 13), Pair(1, 10), Pair(2, 7), Pair(0, 6),
        Pair(-1, 10), Pair(4, 3), Pair(-3, 9), Pair(19, 7), Pair(-3, 26), Pair(-1, 8), Pair(1, 4), Pair(-2, 9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(17, 19), Pair(-30, -2), Pair(36, 8), Pair(18, 61), Pair(-1, 41), Pair(14, 24), Pair(72, 51), Pair(-3, 78),
        Pair(20, -9), Pair(-14, 49), Pair(2, -20), Pair(-12, 21), Pair(-37, 54), Pair(41, 18), Pair(13, 26), Pair(13, 12),
        Pair(-5, 58), Pair(0, 33), Pair(-10, 28), Pair(2, 10), Pair(15, 26), Pair(-19, 27), Pair(-2, 22), Pair(-18, -9),
        Pair(2, 31), Pair(-3, 34), Pair(15, 31), Pair(-12, 3), Pair(5, 22), Pair(22, 20), Pair(3, 22), Pair(15, 20),
        Pair(2, 23), Pair(16, 25), Pair(13, 26), Pair(15, 57), Pair(-6, 44), Pair(1, 40), Pair(2, 17), Pair(4, 16),
        Pair(-8, 15), Pair(-7, 30), Pair(5, 20), Pair(21, 36), Pair(12, 23), Pair(3, 20), Pair(3, 23), Pair(8, 11),
        Pair(10, 70), Pair(23, 13), Pair(-10, 37), Pair(6, 15), Pair(5, 13), Pair(6, 22), Pair(2, 38), Pair(6, -1),
        Pair(-29, 85), Pair(2, 5), Pair(-2, 15), Pair(20, 24), Pair(8, 15), Pair(0, 15), Pair(-7, 14), Pair(39, 34)
      },
      { // Piece 2
        Pair(20, -22), Pair(2, 21), Pair(-29, -2), Pair(10, -4), Pair(-72, -18), Pair(-18, 4), Pair(-75, 42), Pair(27, -73),
        Pair(-12, -8), Pair(-44, 8), Pair(-3, -7), Pair(38, -37), Pair(8, -9), Pair(1, -1), Pair(29, -41), Pair(-23, 45),
        Pair(36, -17), Pair(30, -6), Pair(-6, 2), Pair(13, 1), Pair(15, 9), Pair(-17, 10), Pair(30, -23), Pair(11, -17),
        Pair(11, -5), Pair(6, -12), Pair(9, 8), Pair(-13, -6), Pair(-12, 9), Pair(14, 0), Pair(-3, -15), Pair(-4, 12),
        Pair(-1, 10), Pair(3, 10), Pair(2, 4), Pair(42, 39), Pair(-7, 8), Pair(2, 8), Pair(6, -12), Pair(-2, -25),
        Pair(-3, -1), Pair(4, -3), Pair(-8, -15), Pair(8, 13), Pair(-4, 1), Pair(6, -3), Pair(-1, 24), Pair(9, 5),
        Pair(-4, -2), Pair(-13, -22), Pair(12, 8), Pair(5, -5), Pair(1, 0), Pair(-9, 3), Pair(-4, 0), Pair(6, 15),
        Pair(-25, -29), Pair(21, -31), Pair(-5, -11), Pair(39, -8), Pair(16, -5), Pair(2, -5), Pair(-32, -34), Pair(-1, -58)
      },
      { // Piece 3
        Pair(13, 11), Pair(10, 15), Pair(-51, 60), Pair(16, 18), Pair(15, 12), Pair(19, 13), Pair(-11, 30), Pair(28, 18),
        Pair(10, 22), Pair(1, 30), Pair(-12, 20), Pair(-9, 23), Pair(-14, 23), Pair(-19, 32), Pair(-30, 21), Pair(32, 25),
        Pair(-9, 23), Pair(-11, 27), Pair(-14, 29), Pair(14, -1), Pair(-10, 19), Pair(13, 12), Pair(11, 31), Pair(5, 10),
        Pair(2, 23), Pair(3, 17), Pair(0, 8), Pair(3, -1), Pair(21, 11), Pair(-9, 30), Pair(-20, 9), Pair(10, 10),
        Pair(12, 6), Pair(5, 8), Pair(-4, 14), Pair(25, -34), Pair(-25, 23), Pair(19, -2), Pair(12, 9), Pair(-36, 25),
        Pair(0, 18), Pair(12, -6), Pair(5, 29), Pair(12, 1), Pair(1, 12), Pair(3, 4), Pair(5, 35), Pair(5, 13),
        Pair(-27, 43), Pair(0, 9), Pair(5, 0), Pair(-1, 18), Pair(-1, 0), Pair(-21, 31), Pair(-2, -2), Pair(-14, 14),
        Pair(2, 11), Pair(6, 9), Pair(-3, 12), Pair(8, 3), Pair(-2, 14), Pair(1, 16), Pair(5, 10), Pair(7, 7)
      },
      { // Piece 4
        Pair(-42, -23), Pair(11, 16), Pair(7, 32), Pair(-16, 26), Pair(-36, 31), Pair(-22, -19), Pair(-60, -1), Pair(61, 31),
        Pair(-20, 20), Pair(5, 18), Pair(23, 36), Pair(12, -37), Pair(-19, 22), Pair(15, 36), Pair(12, 3), Pair(-9, 21),
        Pair(2, 2), Pair(5, -7), Pair(4, -25), Pair(-29, 0), Pair(-20, 41), Pair(-2, 11), Pair(-23, 43), Pair(-3, 0),
        Pair(3, -10), Pair(-7, 11), Pair(-18, 44), Pair(-18, -17), Pair(-16, 22), Pair(-4, -25), Pair(20, -47), Pair(5, -20),
        Pair(-4, -3), Pair(-2, 8), Pair(-9, 14), Pair(14, 12), Pair(-10, 9), Pair(-3, 11), Pair(-3, 13), Pair(-13, -24),
        Pair(-5, -21), Pair(3, 1), Pair(11, 11), Pair(2, 24), Pair(0, 6), Pair(-5, 8), Pair(-13, 16), Pair(2, -13),
        Pair(1, 15), Pair(1, 9), Pair(5, 4), Pair(3, 0), Pair(-3, 14), Pair(2, -1), Pair(21, -21), Pair(-2, -45),
        Pair(2, 25), Pair(-5, -9), Pair(7, -1), Pair(1, 4), Pair(0, 13), Pair(-14, 31), Pair(-1, -56), Pair(12, 25)
      },
      { // Piece 5
        Pair(-8, -3), Pair(74, 94), Pair(-27, 85), Pair(-48, 119), Pair(52, 127), Pair(65, -53), Pair(-16, 18), Pair(41, 56),
        Pair(-16, -6), Pair(63, 127), Pair(30, 80), Pair(23, 83), Pair(-37, 31), Pair(59, 31), Pair(-39, 37), Pair(27, -16),
        Pair(-18, 84), Pair(-13, 36), Pair(107, 61), Pair(56, 28), Pair(-22, 37), Pair(-52, 44), Pair(-1, 32), Pair(5, 5),
        Pair(-6, 21), Pair(77, 27), Pair(70, 68), Pair(-6, 62), Pair(36, 47), Pair(46, 24), Pair(63, 11), Pair(-19, 4),
        Pair(-89, 10), Pair(-28, 15), Pair(28, 27), Pair(-34, 47), Pair(-2, 35), Pair(-7, 18), Pair(19, 9), Pair(-37, 8),
        Pair(74, -11), Pair(30, 8), Pair(57, -8), Pair(-32, 31), Pair(-45, 26), Pair(20, 0), Pair(-12, 2), Pair(-36, 10),
        Pair(27, -9), Pair(-20, 12), Pair(-8, 2), Pair(-20, 2), Pair(-24, -2), Pair(3, -4), Pair(-3, -8), Pair(7, -12),
        Pair(23, -36), Pair(-11, -5), Pair(7, -29), Pair(-39, 7), Pair(4, -22), Pair(-4, -10), Pair(-2, -13), Pair(6, -13)
      }
    }},
    {{ // Bucket 28
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-35, 31), Pair(-16, 3), Pair(44, 1), Pair(-111, 45), Pair(-50, -20), Pair(-16, 3), Pair(-7, 56), Pair(-33, 45),
        Pair(-6, 19), Pair(4, 5), Pair(7, -6), Pair(3, 11), Pair(15, -21), Pair(8, 7), Pair(32, -9), Pair(-7, 20),
        Pair(-3, 8), Pair(1, 7), Pair(-7, -8), Pair(4, 4), Pair(16, 0), Pair(7, -3), Pair(-9, 2), Pair(3, 12),
        Pair(1, 8), Pair(4, 8), Pair(-4, 1), Pair(4, 7), Pair(1, -6), Pair(3, 5), Pair(3, 7), Pair(-4, 5),
        Pair(4, 2), Pair(3, 10), Pair(0, 9), Pair(7, 6), Pair(12, 12), Pair(10, 6), Pair(0, 12), Pair(-1, 4),
        Pair(1, 2), Pair(2, 8), Pair(3, 5), Pair(12, 5), Pair(11, 25), Pair(-2, 11), Pair(1, 9), Pair(-4, 6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-1, 39), Pair(-53, -3), Pair(-97, 32), Pair(54, 14), Pair(99, 50), Pair(14, -63), Pair(-100, 22), Pair(-62, 57),
        Pair(32, 32), Pair(2, 15), Pair(-11, 22), Pair(-9, 34), Pair(-28, 52), Pair(10, 8), Pair(-8, 46), Pair(-48, 53),
        Pair(-22, 12), Pair(1, 31), Pair(6, 33), Pair(9, 26), Pair(-1, 7), Pair(19, 19), Pair(-9, 63), Pair(6, 57),
        Pair(-16, 34), Pair(7, 40), Pair(4, 34), Pair(5, 42), Pair(-9, 33), Pair(16, 33), Pair(3, 16), Pair(12, 8),
        Pair(4, 19), Pair(9, 31), Pair(3, 18), Pair(11, 39), Pair(24, 58), Pair(10, 40), Pair(21, 11), Pair(7, 47),
        Pair(11, -5), Pair(-2, 24), Pair(1, 22), Pair(25, 17), Pair(16, 37), Pair(7, 29), Pair(0, 22), Pair(2, 36),
        Pair(24, -3), Pair(15, -6), Pair(4, 17), Pair(1, 22), Pair(10, 6), Pair(6, 25), Pair(-11, 6), Pair(2, 39),
        Pair(-19, -12), Pair(-2, 0), Pair(14, 51), Pair(4, 20), Pair(7, 21), Pair(-8, 38), Pair(9, 12), Pair(-32, 26)
      },
      { // Piece 2
        Pair(31, -14), Pair(-37, -36), Pair(-51, -18), Pair(-23, 10), Pair(-6, -14), Pair(17, -28), Pair(54, -73), Pair(52, 8),
        Pair(14, -17), Pair(-24, -2), Pair(-39, 29), Pair(53, -23), Pair(16, -5), Pair(-2, -7), Pair(-4, 14), Pair(44, -30),
        Pair(6, -15), Pair(28, -14), Pair(-1, -7), Pair(12, 30), Pair(20, -29), Pair(12, -19), Pair(23, -23), Pair(-5, 20),
        Pair(11, 2), Pair(-5, 9), Pair(-9, 1), Pair(4, 15), Pair(-5, -6), Pair(31, 0), Pair(13, 7), Pair(-10, 8),
        Pair(-16, -1), Pair(15, -8), Pair(-4, 14), Pair(-3, 13), Pair(38, 23), Pair(10, 1), Pair(9, 11), Pair(10, 4),
        Pair(10, -11), Pair(-5, 10), Pair(-2, 6), Pair(3, 15), Pair(10, 15), Pair(-11, 1), Pair(-4, -4), Pair(-5, 2),
        Pair(10, 31), Pair(-2, 4), Pair(8, 2), Pair(3, -1), Pair(3, -1), Pair(4, -15), Pair(-19, 4), Pair(-14, -11),
        Pair(6, -2), Pair(-22, -14), Pair(-3, 4), Pair(9, -6), Pair(5, -15), Pair(-10, -7), Pair(9, -14), Pair(0, -66)
      },
      { // Piece 3
        Pair(5, 26), Pair(32, 24), Pair(16, 34), Pair(19, 18), Pair(4, 7), Pair(-52, 44), Pair(81, 25), Pair(19, 25),
        Pair(-11, 25), Pair(-11, 19), Pair(18, 20), Pair(17, 12), Pair(1, 26), Pair(6, 33), Pair(-6, 21), Pair(-28, 54),
        Pair(-10, 33), Pair(20, 19), Pair(-9, 25), Pair(2, 9), Pair(26, -26), Pair(0, 16), Pair(26, 10), Pair(1, 31),
        Pair(15, 36), Pair(6, 6), Pair(-6, 17), Pair(-2, 14), Pair(-12, 13), Pair(-1, 16), Pair(-10, 23), Pair(27, 14),
        Pair(16, 5), Pair(-2, 17), Pair(0, 10), Pair(2, 21), Pair(33, -5), Pair(-1, 22), Pair(3, 13), Pair(-24, 31),
        Pair(8, 4), Pair(12, 11), Pair(-1, 33), Pair(4, 9), Pair(23, -10), Pair(0, 3), Pair(3, 22), Pair(20, 7),
        Pair(2, -7), Pair(-2, 16), Pair(1, 17), Pair(-7, 26), Pair(17, -12), Pair(-8, 26), Pair(13, 8), Pair(32, -24),
        Pair(1, 14), Pair(4, 13), Pair(3, 14), Pair(1, 14), Pair(11, 7), Pair(-2, 12), Pair(-5, 23), Pair(10, 10)
      },
      { // Piece 4
        Pair(-49, 37), Pair(-8, -13), Pair(20, -5), Pair(6, 22), Pair(51, -13), Pair(88, 23), Pair(-6, 38), Pair(-1, 29),
        Pair(0, 6), Pair(11, 2), Pair(-32, 43), Pair(3, -13), Pair(27, 4), Pair(27, 69), Pair(38, -9), Pair(-31, 91),
        Pair(-10, 28), Pair(-16, 16), Pair(-29, 54), Pair(-9, 44), Pair(-8, -5), Pair(-5, 35), Pair(26, 14), Pair(-14, 61),
        Pair(-14, 11), Pair(5, -24), Pair(-31, 12), Pair(-5, 16), Pair(-42, 36), Pair(3, 27), Pair(-17, 26), Pair(-4, 19),
        Pair(-7, 20), Pair(3, -1), Pair(-18, 39), Pair(-3, 21), Pair(16, 3), Pair(11, 5), Pair(12, -4), Pair(-14, 56),
        Pair(9, 10), Pair(2, -7), Pair(-1, 12), Pair(7, 15), Pair(4, 6), Pair(5, 14), Pair(-1, -7), Pair(20, 30),
        Pair(-12, 35), Pair(0, -12), Pair(1, 13), Pair(7, -5), Pair(2, 11), Pair(-5, 25), Pair(-1, 38), Pair(38, -50),
        Pair(6, 21), Pair(7, 3), Pair(0, 7), Pair(4, 19), Pair(9, -13), Pair(-11, 31), Pair(25, 34), Pair(9, -44)
      },
      { // Piece 5
        Pair(2, 11), Pair(-88, 18), Pair(44, 45), Pair(-71, 63), Pair(77, 2), Pair(59, 126), Pair(7, 95), Pair(-5, -21),
        Pair(10, -23), Pair(70, 34), Pair(108, 57), Pair(49, 52), Pair(90, 88), Pair(15, 52), Pair(-24, 26), Pair(-32, 67),
        Pair(102, -29), Pair(60, 42), Pair(-73, 11), Pair(39, 18), Pair(34, 35), Pair(41, 52), Pair(-1, 46), Pair(0, 27),
        Pair(5, 21), Pair(21, -22), Pair(-69, 38), Pair(-42, 56), Pair(49, 36), Pair(56, 20), Pair(2, 14), Pair(-8, 4),
        Pair(-40, 10), Pair(-13, 10), Pair(19, 15), Pair(28, 27), Pair(-2, 36), Pair(-18, 28), Pair(17, 1), Pair(-1, 7),
        Pair(73, -24), Pair(-36, 18), Pair(-4, 0), Pair(-11, 16), Pair(-25, 27), Pair(-20, 15), Pair(9, -9), Pair(-10, -11),
        Pair(16, -3), Pair(9, -31), Pair(4, -24), Pair(-26, 8), Pair(-26, 16), Pair(-20, -3), Pair(2, -9), Pair(13, -13),
        Pair(-13, 4), Pair(-22, -3), Pair(0, -31), Pair(0, -20), Pair(0, -30), Pair(-1, -26), Pair(2, -17), Pair(2, -22)
      }
    }},
    {{ // Bucket 29
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-12, 1), Pair(-47, 4), Pair(12, -5), Pair(-51, -2), Pair(-15, 22), Pair(-50, 50), Pair(-43, 40), Pair(-54, 29),
        Pair(10, -1), Pair(-13, 8), Pair(19, 0), Pair(13, 7), Pair(-13, 30), Pair(-14, 32), Pair(-15, -5), Pair(-9, 15),
        Pair(-3, 10), Pair(2, 4), Pair(3, 3), Pair(5, 2), Pair(4, -2), Pair(15, -5), Pair(-14, 0), Pair(2, -4),
        Pair(2, 4), Pair(0, 9), Pair(5, 3), Pair(-2, 3), Pair(8, -1), Pair(4, -5), Pair(11, -5), Pair(3, -3),
        Pair(2, 9), Pair(5, 11), Pair(4, -1), Pair(2, 5), Pair(6, 0), Pair(11, 2), Pair(5, 3), Pair(1, -1),
        Pair(0, 11), Pair(3, 6), Pair(-2, 7), Pair(1, 14), Pair(10, 8), Pair(11, 13), Pair(-1, 10), Pair(-3, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(60, -76), Pair(-76, 32), Pair(-79, 33), Pair(-34, 8), Pair(64, 9), Pair(-3, -20), Pair(11, -1), Pair(53, 58),
        Pair(-1, 70), Pair(-20, 35), Pair(18, 41), Pair(19, 36), Pair(15, 21), Pair(-57, 11), Pair(15, 14), Pair(-86, 7),
        Pair(17, 20), Pair(30, 24), Pair(13, 20), Pair(-13, 26), Pair(35, 15), Pair(-72, 29), Pair(2, 6), Pair(-31, 17),
        Pair(-18, 51), Pair(8, 16), Pair(23, 7), Pair(11, 28), Pair(18, 23), Pair(0, 14), Pair(-5, 26), Pair(18, -6),
        Pair(1, 16), Pair(27, 20), Pair(8, 8), Pair(7, 18), Pair(6, 28), Pair(-1, 29), Pair(6, 29), Pair(-5, 8),
        Pair(-11, 15), Pair(4, 20), Pair(4, 27), Pair(10, 18), Pair(2, 22), Pair(6, 25), Pair(7, 15), Pair(-6, -1),
        Pair(-15, 15), Pair(2, -3), Pair(1, 9), Pair(0, 23), Pair(1, 22), Pair(-10, 1), Pair(6, 4), Pair(-15, -21),
        Pair(-84, -5), Pair(-6, -2), Pair(-7, 23), Pair(9, 5), Pair(7, 32), Pair(-2, 2), Pair(-5, -3), Pair(-24, 39)
      },
      { // Piece 2
        Pair(7, -4), Pair(-40, -35), Pair(47, -28), Pair(51, -35), Pair(113, -20), Pair(81, -47), Pair(-20, 28), Pair(11, -23),
        Pair(23, -25), Pair(11, -16), Pair(3, -12), Pair(3, -13), Pair(18, 4), Pair(10, -27), Pair(-7, -27), Pair(12, 6),
        Pair(15, -24), Pair(30, -20), Pair(14, -9), Pair(20, -21), Pair(7, 4), Pair(-26, 5), Pair(-36, 12), Pair(-24, -3),
        Pair(-10, -20), Pair(8, -1), Pair(-27, 3), Pair(23, -11), Pair(9, 9), Pair(37, -15), Pair(-5, 5), Pair(5, -4),
        Pair(13, 10), Pair(14, -9), Pair(11, 15), Pair(2, 7), Pair(11, 9), Pair(2, 32), Pair(12, -5), Pair(-13, 15),
        Pair(-3, -3), Pair(4, 2), Pair(7, -6), Pair(7, 6), Pair(1, -2), Pair(18, 11), Pair(-8, -25), Pair(-1, 15),
        Pair(-1, 22), Pair(1, 7), Pair(8, 4), Pair(-5, 3), Pair(0, 6), Pair(9, -29), Pair(0, -2), Pair(-32, -27),
        Pair(13, -3), Pair(-1, 4), Pair(-12, 2), Pair(2, 10), Pair(-7, 1), Pair(0, 10), Pair(-10, -5), Pair(29, -18)
      },
      { // Piece 3
        Pair(6, 26), Pair(-37, 23), Pair(22, 15), Pair(0, 16), Pair(45, 25), Pair(9, 37), Pair(47, -2), Pair(83, -5),
        Pair(7, 15), Pair(20, 6), Pair(48, 2), Pair(-12, 22), Pair(-22, 31), Pair(5, 26), Pair(-39, 19), Pair(20, 16),
        Pair(24, 8), Pair(12, 12), Pair(35, 8), Pair(33, 11), Pair(25, 18), Pair(95, -15), Pair(-7, 18), Pair(-1, 14),
        Pair(15, 15), Pair(5, 14), Pair(-6, 17), Pair(4, 25), Pair(12, 20), Pair(31, -21), Pair(17, 0), Pair(12, 12),
        Pair(3, 29), Pair(16, 3), Pair(13, 5), Pair(19, 1), Pair(21, 4), Pair(46, -32), Pair(3, 17), Pair(22, -4),
        Pair(14, -8), Pair(4, 23), Pair(-13, 18), Pair(-9, 3), Pair(3, 11), Pair(12, -3), Pair(-11, 13), Pair(-26, 16),
        Pair(-25, 1), Pair(5, -2), Pair(-2, 9), Pair(15, -8), Pair(-3, 13), Pair(-1, -3), Pair(14, 16), Pair(-34, 34),
        Pair(0, 10), Pair(5, 5), Pair(4, 9), Pair(9, 0), Pair(3, 9), Pair(10, -8), Pair(-4, 15), Pair(3, 9)
      },
      { // Piece 4
        Pair(3, 24), Pair(20, 16), Pair(-17, 31), Pair(42, -1), Pair(-11, 78), Pair(35, -15), Pair(37, -37), Pair(-9, 5),
        Pair(9, 0), Pair(23, -20), Pair(30, -20), Pair(10, 13), Pair(31, -38), Pair(-21, -29), Pair(-12, 115), Pair(11, -6),
        Pair(5, -16), Pair(-18, 36), Pair(-22, -24), Pair(-6, 37), Pair(-43, 72), Pair(-2, -27), Pair(18, 34), Pair(6, -2),
        Pair(-15, 3), Pair(8, 12), Pair(-9, 14), Pair(-13, 39), Pair(-2, 4), Pair(-16, -3), Pair(25, -22), Pair(-8, 23),
        Pair(-17, 17), Pair(6, 0), Pair(0, 1), Pair(-5, 14), Pair(16, -17), Pair(28, 2), Pair(-16, 15), Pair(2, -36),
        Pair(12, -15), Pair(7, 0), Pair(-2, 19), Pair(7, -9), Pair(-6, 19), Pair(1, 15), Pair(-9, 5), Pair(-1, -29),
        Pair(-15, -21), Pair(11, 0), Pair(2, -5), Pair(0, 2), Pair(-2, 9), Pair(7, -12), Pair(-5, 2), Pair(23, -103),
        Pair(3, -13), Pair(-9, 18), Pair(0, -16), Pair(-1, 9), Pair(12, -13), Pair(15, -53), Pair(20, -33), Pair(-4, -5)
      },
      { // Piece 5
        Pair(51, 51), Pair(-42, 25), Pair(-25, 44), Pair(78, 74), Pair(31, 83), Pair(0, 65), Pair(22, 134), Pair(-17, 64),
        Pair(24, 59), Pair(39, 16), Pair(91, 7), Pair(50, 78), Pair(-53, 40), Pair(-9, 60), Pair(57, 64), Pair(29, 34),
        Pair(-50, -7), Pair(17, 23), Pair(-55, 3), Pair(-87, 40), Pair(-19, 63), Pair(-17, 45), Pair(18, 55), Pair(-112, -8),
        Pair(-14, 24), Pair(69, 1), Pair(-16, 35), Pair(14, 31), Pair(108, 10), Pair(67, 10), Pair(55, 21), Pair(-3, 26),
        Pair(-48, -19), Pair(-1, 3), Pair(-33, 32), Pair(7, 20), Pair(48, 9), Pair(17, 39), Pair(29, 2), Pair(16, 10),
        Pair(-36, -12), Pair(-26, -1), Pair(-35, 0), Pair(-13, 9), Pair(-19, 21), Pair(-12, 18), Pair(5, 6), Pair(8, -3),
        Pair(-14, 6), Pair(18, -5), Pair(2, 5), Pair(-15, -1), Pair(9, -5), Pair(-43, 13), Pair(-13, -6), Pair(8, -5),
        Pair(6, -36), Pair(-23, -13), Pair(-21, -2), Pair(-37, -2), Pair(2, -38), Pair(-21, -20), Pair(6, -26), Pair(8, -24)
      }
    }},
    {{ // Bucket 30
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(38, -31), Pair(44, -18), Pair(-57, -9), Pair(28, 8), Pair(-18, 15), Pair(-35, 31), Pair(49, -51), Pair(-71, 78),
        Pair(-1, -2), Pair(9, -7), Pair(-14, -7), Pair(-11, 4), Pair(11, -16), Pair(-10, 21), Pair(82, 9), Pair(-35, 8),
        Pair(6, 7), Pair(6, 9), Pair(-10, 13), Pair(-2, 9), Pair(3, -4), Pair(-10, -2), Pair(29, -2), Pair(-6, -8),
        Pair(-4, 11), Pair(2, 15), Pair(2, 9), Pair(0, 6), Pair(-4, 6), Pair(0, -1), Pair(-4, 2), Pair(5, -10),
        Pair(1, 12), Pair(-1, 10), Pair(1, 12), Pair(0, 9), Pair(-1, 11), Pair(6, -1), Pair(0, 17), Pair(4, -5),
        Pair(-1, 15), Pair(-3, 14), Pair(-1, 13), Pair(-7, 19), Pair(6, 2), Pair(1, 14), Pair(15, 6), Pair(-7, 7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(1, -23), Pair(56, 3), Pair(-36, 71), Pair(-25, 6), Pair(-52, 28), Pair(-8, 46), Pair(-7, -4), Pair(-71, 5),
        Pair(2, 6), Pair(20, -25), Pair(17, -1), Pair(49, 20), Pair(55, 15), Pair(20, -1), Pair(40, 18), Pair(54, -23),
        Pair(-35, 3), Pair(-13, 27), Pair(5, 16), Pair(7, 16), Pair(-1, 16), Pair(59, 4), Pair(7, 17), Pair(28, -18),
        Pair(11, 19), Pair(12, 9), Pair(20, 26), Pair(36, 6), Pair(18, 23), Pair(16, 12), Pair(30, -5), Pair(45, 3),
        Pair(-12, 8), Pair(35, 6), Pair(1, 23), Pair(15, 31), Pair(16, 27), Pair(27, 0), Pair(49, 8), Pair(6, 34),
        Pair(-20, -24), Pair(-9, 23), Pair(1, 14), Pair(26, 19), Pair(12, 8), Pair(6, 16), Pair(1, 11), Pair(1, -9),
        Pair(-16, -1), Pair(-36, 27), Pair(-17, 23), Pair(-10, 26), Pair(-4, 23), Pair(18, 12), Pair(27, 3), Pair(-30, 8),
        Pair(57, -3), Pair(-22, 13), Pair(-39, 43), Pair(0, -8), Pair(0, 10), Pair(-13, 7), Pair(-8, -41), Pair(-47, 85)
      },
      { // Piece 2
        Pair(-84, -7), Pair(-98, 7), Pair(33, -17), Pair(99, 3), Pair(-8, -23), Pair(28, -16), Pair(-17, -8), Pair(-66, -6),
        Pair(0, 30), Pair(7, -25), Pair(-35, -12), Pair(51, -38), Pair(12, 0), Pair(69, -29), Pair(9, -3), Pair(26, -39),
        Pair(28, -2), Pair(17, -15), Pair(65, -29), Pair(7, -13), Pair(19, -12), Pair(84, -7), Pair(40, -31), Pair(35, -3),
        Pair(-17, 18), Pair(10, -9), Pair(47, 12), Pair(13, -1), Pair(21, 1), Pair(14, 10), Pair(16, 2), Pair(46, -36),
        Pair(15, 14), Pair(-7, 14), Pair(4, 4), Pair(38, -10), Pair(27, 0), Pair(-7, 24), Pair(16, 19), Pair(-2, -13),
        Pair(6, 2), Pair(35, 1), Pair(10, 4), Pair(12, 0), Pair(1, 12), Pair(8, -9), Pair(18, 2), Pair(-1, -24),
        Pair(-23, 19), Pair(4, 3), Pair(19, 7), Pair(17, -4), Pair(7, 2), Pair(20, -15), Pair(7, -5), Pair(-1, -20),
        Pair(-1, 53), Pair(-15, 11), Pair(-1, 16), Pair(-3, -6), Pair(-3, 8), Pair(9, -16), Pair(39, -12), Pair(-3, 12)
      },
      { // Piece 3
        Pair(23, 41), Pair(-1, 38), Pair(56, 13), Pair(7, 19), Pair(36, 28), Pair(-34, 55), Pair(109, -44), Pair(7, 9),
        Pair(57, 13), Pair(4, 15), Pair(-9, 19), Pair(33, 15), Pair(37, 11), Pair(48, 2), Pair(43, 0), Pair(-47, 35),
        Pair(23, 20), Pair(24, 9), Pair(-1, 16), Pair(28, 3), Pair(34, 9), Pair(-9, 26), Pair(21, 0), Pair(22, -7),
        Pair(-6, 21), Pair(-1, 21), Pair(-31, 39), Pair(-14, 27), Pair(8, 20), Pair(0, 23), Pair(2, 7), Pair(-19, 37),
        Pair(14, 7), Pair(7, 31), Pair(-8, 26), Pair(7, 12), Pair(18, 8), Pair(6, 18), Pair(36, -12), Pair(-9, 24),
        Pair(11, 10), Pair(-2, 26), Pair(-4, 20), Pair(-21, 23), Pair(12, -6), Pair(7, 25), Pair(5, -3), Pair(10, -1),
        Pair(-22, 26), Pair(1, 24), Pair(15, 3), Pair(-16, 19), Pair(-11, 17), Pair(10, -11), Pair(17, -15), Pair(-2, -12),
        Pair(-1, 12), Pair(1, 1), Pair(7, 3), Pair(-2, 17), Pair(4, 2), Pair(2, 7), Pair(2, -23), Pair(-7, 4)
      },
      { // Piece 4
        Pair(1, 34), Pair(11, -4), Pair(-10, -3), Pair(35, 9), Pair(21, 17), Pair(14, -58), Pair(77, 10), Pair(-16, 4),
        Pair(17, -25), Pair(-9, 12), Pair(13, -37), Pair(-7, -4), Pair(-45, 79), Pair(81, -71), Pair(9, -61), Pair(23, 8),
        Pair(-14, 17), Pair(12, 3), Pair(17, -31), Pair(5, -29), Pair(93, -81), Pair(33, -35), Pair(-18, 21), Pair(46, -50),
        Pair(4, 11), Pair(-2, -10), Pair(5, -1), Pair(-12, 12), Pair(12, -5), Pair(29, -10), Pair(-4, 5), Pair(23, -43),
        Pair(9, -59), Pair(-20, 9), Pair(-21, 58), Pair(7, -4), Pair(15, 21), Pair(13, -7), Pair(29, -6), Pair(6, 2),
        Pair(11, -42), Pair(-1, 13), Pair(22, -18), Pair(-8, -11), Pair(9, -22), Pair(-3, 6), Pair(-6, -23), Pair(-13, 6),
        Pair(-13, 11), Pair(7, 18), Pair(15, -50), Pair(-4, 24), Pair(14, -12), Pair(-7, 8), Pair(-26, 28), Pair(-18, 50),
        Pair(11, -64), Pair(-44, 34), Pair(-24, 24), Pair(-11, 18), Pair(-6, 11), Pair(-45, 11), Pair(-35, -33), Pair(-66, -23)
      },
      { // Piece 5
        Pair(-17, -13), Pair(3, 58), Pair(30, 113), Pair(-12, 40), Pair(25, -28), Pair(-1, 45), Pair(44, 47), Pair(34, 82),
        Pair(40, -20), Pair(-2, 43), Pair(-28, 52), Pair(-6, 30), Pair(61, 49), Pair(76, 112), Pair(135, 78), Pair(30, 87),
        Pair(-34, 37), Pair(-30, 9), Pair(-33, 36), Pair(-6, 55), Pair(67, 31), Pair(63, 43), Pair(6, 69), Pair(-49, 45),
        Pair(-94, 28), Pair(4, -5), Pair(14, 18), Pair(-75, 42), Pair(26, 25), Pair(19, 36), Pair(64, 37), Pair(-38, 47),
        Pair(-50, -2), Pair(-33, 22), Pair(-24, 20), Pair(-5, 16), Pair(-3, 25), Pair(-7, 21), Pair(41, 15), Pair(3, -1),
        Pair(-43, 0), Pair(14, 2), Pair(-55, 18), Pair(-69, 21), Pair(-16, 5), Pair(-8, 4), Pair(-1, 14), Pair(-30, 7),
        Pair(-30, -19), Pair(-38, -12), Pair(-56, 8), Pair(-52, 7), Pair(6, -5), Pair(-13, 2), Pair(2, 0), Pair(-19, 8),
        Pair(-21, -20), Pair(-6, -12), Pair(-27, -11), Pair(-38, 1), Pair(-10, -1), Pair(11, -27), Pair(8, -13), Pair(4, -23)
      }
    }},
    {{ // Bucket 31
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(13, -9), Pair(5, -13), Pair(63, -5), Pair(16, -18), Pair(38, -24), Pair(0, 14), Pair(-21, 34), Pair(47, 1),
        Pair(6, -3), Pair(-24, 8), Pair(3, -16), Pair(1, -9), Pair(35, 3), Pair(3, 5), Pair(-5, 8), Pair(69, 2),
        Pair(4, 8), Pair(3, -6), Pair(-7, 8), Pair(5, 10), Pair(4, -1), Pair(-5, -5), Pair(-4, -3), Pair(7, 8),
        Pair(-4, 10), Pair(2, 14), Pair(-1, 10), Pair(4, 7), Pair(1, 7), Pair(2, 1), Pair(8, -12), Pair(-1, 0),
        Pair(-1, 12), Pair(2, 11), Pair(1, 7), Pair(-2, 9), Pair(4, 7), Pair(5, 2), Pair(3, -5), Pair(20, 18),
        Pair(-4, 12), Pair(0, 11), Pair(-4, 7), Pair(-1, 1), Pair(3, 5), Pair(5, 3), Pair(2, 2), Pair(8, 7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(75, 38), Pair(30, -9), Pair(-4, 28), Pair(37, -4), Pair(5, 0), Pair(-29, 23), Pair(-10, -9), Pair(-84, -23),
        Pair(24, -30), Pair(-44, 40), Pair(-2, 1), Pair(19, 16), Pair(48, 3), Pair(38, -14), Pair(-13, 40), Pair(-66, -5),
        Pair(-51, 14), Pair(5, -8), Pair(1, 35), Pair(33, -3), Pair(30, 10), Pair(37, 5), Pair(16, 5), Pair(21, -25),
        Pair(-36, -6), Pair(3, 12), Pair(12, 5), Pair(53, 0), Pair(19, 6), Pair(21, 13), Pair(24, 9), Pair(19, 14),
        Pair(-7, 17), Pair(7, 17), Pair(3, 17), Pair(6, 16), Pair(17, 24), Pair(12, 11), Pair(35, -2), Pair(26, 17),
        Pair(3, -13), Pair(9, 13), Pair(1, 6), Pair(-1, 33), Pair(13, 19), Pair(4, 14), Pair(7, 10), Pair(-3, 30),
        Pair(-11, 18), Pair(2, -13), Pair(2, 17), Pair(-7, 18), Pair(3, 21), Pair(4, 16), Pair(1, 19), Pair(2, 5),
        Pair(-15, 27), Pair(-18, 9), Pair(-20, 21), Pair(9, 7), Pair(2, 17), Pair(-16, 15), Pair(-13, 25), Pair(36, -20)
      },
      { // Piece 2
        Pair(-45, 7), Pair(56, -29), Pair(77, -31), Pair(16, -26), Pair(86, -43), Pair(-118, 9), Pair(-1, -21), Pair(52, 15),
        Pair(13, -7), Pair(33, -29), Pair(24, -26), Pair(13, -21), Pair(4, -25), Pair(49, -22), Pair(-19, 15), Pair(32, 21),
        Pair(-8, 8), Pair(5, -6), Pair(9, -19), Pair(1, -12), Pair(29, -26), Pair(5, -14), Pair(16, -3), Pair(0, -15),
        Pair(0, -4), Pair(5, -2), Pair(23, -12), Pair(3, -1), Pair(30, 0), Pair(-13, -5), Pair(17, 33), Pair(27, -19),
        Pair(50, -13), Pair(6, 2), Pair(19, -17), Pair(14, -2), Pair(10, 9), Pair(9, -3), Pair(15, 12), Pair(21, 14),
        Pair(-19, 13), Pair(3, 6), Pair(2, 8), Pair(3, 3), Pair(13, 8), Pair(11, 5), Pair(15, 0), Pair(25, 10),
        Pair(34, -37), Pair(0, 17), Pair(-7, -3), Pair(-3, 14), Pair(2, 7), Pair(2, -15), Pair(10, -4), Pair(8, -19),
        Pair(-5, 21), Pair(11, 14), Pair(-7, 10), Pair(-8, -2), Pair(-17, -4), Pair(-6, -4), Pair(-7, -29), Pair(52, 2)
      },
      { // Piece 3
        Pair(-3, 17), Pair(2, 6), Pair(24, 14), Pair(21, 10), Pair(51, -8), Pair(71, 0), Pair(22, -5), Pair(37, -19),
        Pair(14, 12), Pair(-13, 14), Pair(25, 0), Pair(-7, 12), Pair(56, -15), Pair(7, 9), Pair(-42, 16), Pair(45, -14),
        Pair(-1, 18), Pair(-18, 17), Pair(-2, 16), Pair(20, -4), Pair(35, -14), Pair(36, 2), Pair(66, -13), Pair(59, -28),
        Pair(-11, 14), Pair(13, 15), Pair(14, 18), Pair(33, 8), Pair(10, 10), Pair(41, 7), Pair(35, -12), Pair(13, -39),
        Pair(-7, 18), Pair(5, 13), Pair(9, 6), Pair(9, 12), Pair(31, -7), Pair(3, 24), Pair(14, 11), Pair(-45, 24),
        Pair(-8, 12), Pair(-13, 21), Pair(0, 1), Pair(-5, 3), Pair(3, -12), Pair(25, -12), Pair(-5, -3), Pair(-43, 1),
        Pair(-22, 9), Pair(-19, 16), Pair(-8, -3), Pair(1, 14), Pair(7, 11), Pair(-13, 10), Pair(10, -5), Pair(-36, -14),
        Pair(-7, 2), Pair(-13, 14), Pair(1, -3), Pair(0, 7), Pair(2, -4), Pair(-2, -5), Pair(-11, 8), Pair(-21, -16)
      },
      { // Piece 4
        Pair(10, -8), Pair(-2, -9), Pair(25, -14), Pair(5, -20), Pair(49, 3), Pair(-6, 9), Pair(48, -36), Pair(-6, -27),
        Pair(16, -11), Pair(-1, -50), Pair(-7, 1), Pair(10, -8), Pair(16, -33), Pair(34, 6), Pair(22, -67), Pair(38, -79),
        Pair(-12, -10), Pair(-18, -16), Pair(-19, 18), Pair(32, -8), Pair(-20, 8), Pair(6, -20), Pair(6, -15), Pair(4, 10),
        Pair(31, -34), Pair(2, -22), Pair(-6, 9), Pair(-7, 23), Pair(23, -8), Pair(-7, 6), Pair(19, 10), Pair(12, -38),
        Pair(15, -28), Pair(-10, 17), Pair(-22, 24), Pair(-7, 8), Pair(0, -25), Pair(-1, 10), Pair(-7, -3), Pair(-12, -35),
        Pair(22, -13), Pair(5, -11), Pair(-11, 5), Pair(-3, -1), Pair(-11, 12), Pair(4, -23), Pair(11, -40), Pair(-2, -29),
        Pair(-9, 26), Pair(2, -4), Pair(0, -1), Pair(-1, 15), Pair(-10, 10), Pair(-5, -7), Pair(-9, -40), Pair(-25, -46),
        Pair(-14, 29), Pair(-1, 16), Pair(-16, 11), Pair(-4, 1), Pair(-5, 4), Pair(-1, -68), Pair(-28, 0), Pair(-12, -3)
      },
      { // Piece 5
        Pair(36, 82), Pair(11, 66), Pair(-76, 10), Pair(-27, -28), Pair(6, -17), Pair(-17, 100), Pair(-50, 59), Pair(46, 37),
        Pair(85, -15), Pair(15, -5), Pair(4, 3), Pair(-38, 100), Pair(-69, 69), Pair(-14, 33), Pair(-55, 86), Pair(-122, 49),
        Pair(-81, -14), Pair(-64, 3), Pair(-94, 37), Pair(-44, 41), Pair(-3, 23), Pair(69, 23), Pair(31, 53), Pair(-27, 34),
        Pair(20, 47), Pair(-3, 21), Pair(-51, 10), Pair(-34, 29), Pair(-43, 29), Pair(48, 14), Pair(15, 14), Pair(-74, 21),
        Pair(-25, -27), Pair(-59, 19), Pair(-13, 13), Pair(12, 26), Pair(-3, 18), Pair(27, 9), Pair(-13, 0), Pair(10, -36),
        Pair(-131, 52), Pair(-6, 16), Pair(-36, 26), Pair(-36, 20), Pair(-17, 10), Pair(17, 3), Pair(-2, -3), Pair(-17, -8),
        Pair(-89, 24), Pair(-45, 17), Pair(-47, 10), Pair(-20, 20), Pair(-16, -3), Pair(-6, -1), Pair(4, -5), Pair(-4, -19),
        Pair(-40, 0), Pair(-29, 3), Pair(-36, 9), Pair(-34, 25), Pair(-21, 3), Pair(-16, -6), Pair(10, -2), Pair(-14, -16)
      }
    }},
    {{ // Bucket 32
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(44, -8), Pair(-69, 95), Pair(-25, -8), Pair(-31, 17), Pair(2, 3), Pair(54, -16), Pair(-43, -6), Pair(9, -8),
        Pair(9, -5), Pair(-24, 19), Pair(3, 11), Pair(11, 3), Pair(-1, 5), Pair(-39, 7), Pair(15, 0), Pair(-16, 12),
        Pair(4, 17), Pair(-3, 3), Pair(3, 4), Pair(0, 10), Pair(1, 3), Pair(10, -1), Pair(-5, 5), Pair(-6, 9),
        Pair(-1, -3), Pair(-7, -3), Pair(1, 0), Pair(0, 10), Pair(4, 10), Pair(2, 5), Pair(1, 11), Pair(2, 8),
        Pair(10, 32), Pair(-5, 1), Pair(2, 4), Pair(2, 4), Pair(2, 10), Pair(6, 9), Pair(3, 10), Pair(0, 13),
        Pair(15, 5), Pair(-6, 9), Pair(1, 5), Pair(2, 12), Pair(-2, 13), Pair(-3, 10), Pair(-1, 14), Pair(3, 13),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-105, 25), Pair(-25, 27), Pair(2, 23), Pair(44, -27), Pair(-63, 6), Pair(-95, -6), Pair(15, 35), Pair(21, 19),
        Pair(6, 12), Pair(-29, 24), Pair(2, 28), Pair(13, 4), Pair(10, 22), Pair(25, 22), Pair(-62, 39), Pair(19, -16),
        Pair(-19, -12), Pair(-2, -9), Pair(3, 29), Pair(-10, 26), Pair(22, 10), Pair(-39, 34), Pair(23, 26), Pair(49, 4),
        Pair(0, -3), Pair(2, 0), Pair(5, 25), Pair(8, 20), Pair(4, 17), Pair(4, 17), Pair(4, 3), Pair(-7, 22),
        Pair(-23, 63), Pair(-5, 24), Pair(9, 20), Pair(1, 26), Pair(-3, 15), Pair(3, 20), Pair(12, 23), Pair(-8, -6),
        Pair(9, 10), Pair(3, 11), Pair(3, 0), Pair(-3, 28), Pair(10, 30), Pair(3, 12), Pair(-5, 12), Pair(7, 3),
        Pair(-20, 9), Pair(-7, -16), Pair(-7, 23), Pair(-2, 11), Pair(1, 4), Pair(-15, 17), Pair(-2, 9), Pair(-12, 34),
        Pair(-41, -1), Pair(-8, -40), Pair(16, -16), Pair(-8, 33), Pair(-17, 24), Pair(-7, 7), Pair(-7, -13), Pair(40, -12)
      },
      { // Piece 2
        Pair(-29, 41), Pair(-42, 9), Pair(1, 7), Pair(-6, 12), Pair(15, -1), Pair(-1, -26), Pair(-7, -35), Pair(22, -32),
        Pair(5, -2), Pair(7, 8), Pair(2, 18), Pair(52, -19), Pair(49, -31), Pair(6, 1), Pair(-13, -15), Pair(-16, 10),
        Pair(5, 4), Pair(12, 7), Pair(19, -8), Pair(18, -3), Pair(-1, -7), Pair(28, -31), Pair(-12, -28), Pair(3, 9),
        Pair(-7, 1), Pair(15, 29), Pair(-3, 10), Pair(8, 6), Pair(7, -6), Pair(17, -4), Pair(11, -7), Pair(36, -18),
        Pair(28, 3), Pair(7, 2), Pair(3, 10), Pair(10, 1), Pair(2, 18), Pair(3, 12), Pair(12, -8), Pair(2, 9),
        Pair(7, 11), Pair(5, 14), Pair(0, 6), Pair(2, 13), Pair(2, 17), Pair(3, 24), Pair(8, 10), Pair(3, -10),
        Pair(16, -84), Pair(0, -7), Pair(-9, 13), Pair(3, 0), Pair(4, 18), Pair(10, 13), Pair(2, 11), Pair(3, 43),
        Pair(-26, 6), Pair(8, -57), Pair(-3, -1), Pair(8, 3), Pair(1, 27), Pair(4, 10), Pair(10, 2), Pair(-36, 81)
      },
      { // Piece 3
        Pair(-13, 4), Pair(-28, 48), Pair(-8, 25), Pair(-10, 19), Pair(8, 35), Pair(-55, 17), Pair(-56, 24), Pair(-25, 26),
        Pair(-8, 2), Pair(-1, 31), Pair(22, 16), Pair(-8, 27), Pair(-2, 25), Pair(-36, 38), Pair(2, 5), Pair(14, 1),
        Pair(-26, 1), Pair(-6, 20), Pair(-21, 26), Pair(6, 21), Pair(-14, 44), Pair(-37, 12), Pair(12, 30), Pair(-1, 44),
        Pair(-61, 20), Pair(20, 25), Pair(10, 32), Pair(-4, 32), Pair(19, 32), Pair(8, 13), Pair(30, 19), Pair(23, 14),
        Pair(-8, -4), Pair(-5, 32), Pair(1, 24), Pair(0, 32), Pair(-3, 30), Pair(-17, 19), Pair(10, 29), Pair(-3, 26),
        Pair(0, -2), Pair(-4, 11), Pair(9, 17), Pair(14, 9), Pair(7, 10), Pair(2, 7), Pair(9, 31), Pair(31, -11),
        Pair(-14, -10), Pair(-14, 21), Pair(-11, 35), Pair(9, 18), Pair(2, 26), Pair(2, 13), Pair(4, 18), Pair(43, -18),
        Pair(-9, -3), Pair(-3, 21), Pair(1, 18), Pair(3, 21), Pair(3, 18), Pair(-1, 13), Pair(9, 26), Pair(12, 10)
      },
      { // Piece 4
        Pair(4, 33), Pair(-7, 13), Pair(20, 39), Pair(-101, 83), Pair(-35, 5), Pair(-10, 62), Pair(8, 31), Pair(-21, 34),
        Pair(-31, 33), Pair(-25, 51), Pair(-17, 23), Pair(11, -6), Pair(-13, 27), Pair(-31, -16), Pair(10, 17), Pair(11, -55),
        Pair(1, -22), Pair(10, 6), Pair(9, 23), Pair(-12, 33), Pair(-13, 43), Pair(-17, 31), Pair(0, 5), Pair(-23, 8),
        Pair(-25, 3), Pair(2, 38), Pair(12, 9), Pair(-7, 31), Pair(17, 4), Pair(11, -21), Pair(8, 14), Pair(-1, 4),
        Pair(4, -1), Pair(-3, 58), Pair(-1, 30), Pair(-8, 13), Pair(-2, 37), Pair(-3, 15), Pair(4, -8), Pair(1, 39),
        Pair(-12, 25), Pair(7, 18), Pair(3, 21), Pair(4, 18), Pair(-3, 40), Pair(-2, 24), Pair(7, 2), Pair(11, -49),
        Pair(2, 11), Pair(0, -14), Pair(2, 11), Pair(-2, 38), Pair(1, 27), Pair(9, 21), Pair(17, -12), Pair(32, -74),
        Pair(3, -30), Pair(-2, -6), Pair(-2, 19), Pair(1, 12), Pair(-1, 18), Pair(9, -3), Pair(20, 23), Pair(2, -38)
      },
      { // Piece 5
        Pair(11, 43), Pair(34, 117), Pair(-35, 91), Pair(-46, -29), Pair(-19, 40), Pair(-50, 20), Pair(-52, -60), Pair(-2, 45),
        Pair(-123, 107), Pair(95, 93), Pair(2, 60), Pair(70, 46), Pair(-22, 7), Pair(12, 34), Pair(6, 24), Pair(-7, -37),
        Pair(-58, 25), Pair(-58, 103), Pair(111, 71), Pair(-59, 62), Pair(18, 44), Pair(-67, 30), Pair(46, 11), Pair(-114, 25),
        Pair(-23, 22), Pair(15, 50), Pair(-16, 50), Pair(20, 47), Pair(4, 15), Pair(-63, 18), Pair(-41, 17), Pair(-49, 0),
        Pair(-21, 21), Pair(7, 64), Pair(8, 36), Pair(-21, 42), Pair(-58, 44), Pair(3, 19), Pair(-35, 17), Pair(-5, -5),
        Pair(-37, 19), Pair(12, 20), Pair(-1, 23), Pair(-1, 20), Pair(21, 15), Pair(-39, 21), Pair(-5, 5), Pair(-39, 5),
        Pair(46, -37), Pair(76, -8), Pair(23, 10), Pair(13, 5), Pair(-2, 17), Pair(-24, 20), Pair(-11, 8), Pair(-10, 1),
        Pair(22, -29), Pair(89, -16), Pair(27, 7), Pair(-29, 23), Pair(-7, -10), Pair(-23, 14), Pair(-1, -2), Pair(-5, -15)
      }
    }},
    {{ // Bucket 33
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-9, 63), Pair(-8, -21), Pair(-62, 27), Pair(-12, -3), Pair(15, 22), Pair(72, -53), Pair(28, -5), Pair(-11, 23),
        Pair(-36, 19), Pair(67, -21), Pair(-3, 36), Pair(-12, -6), Pair(6, 7), Pair(17, -8), Pair(10, -10), Pair(-38, 9),
        Pair(-13, -2), Pair(7, 12), Pair(9, 4), Pair(3, -6), Pair(14, -1), Pair(15, 1), Pair(2, 3), Pair(2, 6),
        Pair(1, -1), Pair(-4, 1), Pair(-1, 0), Pair(5, 6), Pair(3, 13), Pair(11, 7), Pair(-1, 9), Pair(1, 9),
        Pair(2, 7), Pair(7, 22), Pair(3, 9), Pair(3, 11), Pair(4, 10), Pair(8, 8), Pair(-2, 14), Pair(2, 13),
        Pair(-5, 12), Pair(12, 28), Pair(-3, 13), Pair(-2, 22), Pair(-9, 25), Pair(0, 14), Pair(-1, 12), Pair(3, 10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(2, 15), Pair(72, 2), Pair(105, 35), Pair(-20, 34), Pair(1, 68), Pair(-179, 94), Pair(58, 6), Pair(-53, -54),
        Pair(0, -2), Pair(21, 12), Pair(16, 8), Pair(-4, 67), Pair(61, 8), Pair(19, 51), Pair(18, 63), Pair(-17, 15),
        Pair(-32, 28), Pair(-23, 40), Pair(6, 33), Pair(12, 15), Pair(-11, 34), Pair(26, 47), Pair(28, 40), Pair(-15, 33),
        Pair(30, 58), Pair(4, 1), Pair(25, 34), Pair(8, 47), Pair(5, 33), Pair(-19, 58), Pair(3, 36), Pair(8, 30),
        Pair(-2, 43), Pair(29, 57), Pair(0, 22), Pair(9, 42), Pair(13, 32), Pair(21, 37), Pair(8, 36), Pair(0, 24),
        Pair(-5, 14), Pair(20, 45), Pair(1, 34), Pair(15, 36), Pair(22, 25), Pair(7, 31), Pair(2, 33), Pair(-10, 32),
        Pair(-47, 27), Pair(16, 0), Pair(16, 11), Pair(7, 29), Pair(4, 18), Pair(3, 41), Pair(23, 7), Pair(1, 19),
        Pair(-33, 18), Pair(-5, 25), Pair(40, 12), Pair(-13, 65), Pair(3, 25), Pair(10, 45), Pair(-1, 19), Pair(-24, -14)
      },
      { // Piece 2
        Pair(80, 48), Pair(75, -16), Pair(69, -8), Pair(37, 5), Pair(-133, 14), Pair(-22, 17), Pair(51, 20), Pair(56, -22),
        Pair(63, 20), Pair(1, 21), Pair(-11, -8), Pair(-50, 8), Pair(34, -14), Pair(-42, -12), Pair(-8, -17), Pair(-21, 34),
        Pair(34, 19), Pair(13, 1), Pair(49, 17), Pair(31, 14), Pair(-1, 2), Pair(41, -7), Pair(81, 6), Pair(-9, 39),
        Pair(-30, 61), Pair(-26, 15), Pair(46, 14), Pair(20, -5), Pair(5, 20), Pair(18, -9), Pair(11, 13), Pair(13, 11),
        Pair(21, 30), Pair(41, 24), Pair(7, 13), Pair(14, 8), Pair(-9, 29), Pair(18, 34), Pair(13, 11), Pair(-12, 16),
        Pair(11, -8), Pair(7, 38), Pair(17, 3), Pair(7, 20), Pair(1, 13), Pair(19, 20), Pair(15, 31), Pair(20, 40),
        Pair(-15, 24), Pair(7, 5), Pair(2, 14), Pair(-3, 27), Pair(2, 33), Pair(-2, 21), Pair(8, 28), Pair(16, -14),
        Pair(-1, -19), Pair(49, -27), Pair(0, -4), Pair(6, 22), Pair(-4, 25), Pair(-3, 37), Pair(28, 1), Pair(10, 12)
      },
      { // Piece 3
        Pair(25, 53), Pair(28, 26), Pair(-40, 49), Pair(-27, 58), Pair(-38, 44), Pair(-92, 72), Pair(-47, 76), Pair(-31, 53),
        Pair(-10, 43), Pair(-2, 24), Pair(-4, 55), Pair(28, 34), Pair(24, 23), Pair(12, 49), Pair(22, 20), Pair(-34, 63),
        Pair(15, 31), Pair(-22, 20), Pair(17, 33), Pair(6, 46), Pair(29, 21), Pair(-85, 83), Pair(83, -4), Pair(-8, 55),
        Pair(15, 35), Pair(-63, 28), Pair(5, 60), Pair(0, 42), Pair(25, 42), Pair(15, 31), Pair(11, 20), Pair(-35, 42),
        Pair(-24, 55), Pair(-3, 40), Pair(-34, 71), Pair(11, 54), Pair(-13, 67), Pair(36, 16), Pair(30, 48), Pair(-4, 43),
        Pair(6, 23), Pair(-3, 33), Pair(21, 10), Pair(23, 38), Pair(7, 29), Pair(-14, 48), Pair(15, 15), Pair(-1, 12),
        Pair(8, 30), Pair(-1, 22), Pair(-7, 43), Pair(10, 40), Pair(22, 21), Pair(-1, 44), Pair(-3, 66), Pair(-6, 16),
        Pair(2, 34), Pair(-3, 23), Pair(8, 36), Pair(7, 33), Pair(7, 32), Pair(0, 32), Pair(2, 26), Pair(6, 33)
      },
      { // Piece 4
        Pair(-24, 76), Pair(-17, 25), Pair(17, 66), Pair(-35, 70), Pair(59, -32), Pair(-110, 82), Pair(-63, 22), Pair(68, -20),
        Pair(2, 27), Pair(-1, -2), Pair(-13, 11), Pair(33, 53), Pair(-22, 27), Pair(30, -15), Pair(49, -17), Pair(20, -22),
        Pair(-30, 44), Pair(17, -61), Pair(21, 22), Pair(-25, 27), Pair(-16, 28), Pair(-65, 53), Pair(-12, 5), Pair(9, -22),
        Pair(-14, 63), Pair(10, -21), Pair(17, 12), Pair(-27, 41), Pair(-23, 24), Pair(9, 24), Pair(-10, 33), Pair(-15, 32),
        Pair(6, 13), Pair(-6, 54), Pair(-3, 34), Pair(-1, 40), Pair(-15, 73), Pair(-34, 78), Pair(-5, 36), Pair(-4, -27),
        Pair(18, 2), Pair(10, 8), Pair(13, 10), Pair(3, 33), Pair(7, 62), Pair(4, 2), Pair(-17, 57), Pair(-22, -11),
        Pair(-14, 19), Pair(3, 6), Pair(3, 19), Pair(-1, 36), Pair(-1, 33), Pair(7, 31), Pair(23, -50), Pair(21, -49),
        Pair(-4, 54), Pair(2, -10), Pair(-1, 21), Pair(6, 11), Pair(-1, 35), Pair(16, -14), Pair(-18, 14), Pair(-3, 29)
      },
      { // Piece 5
        Pair(5, 3), Pair(15, 106), Pair(28, 69), Pair(48, 70), Pair(21, 100), Pair(71, -10), Pair(37, -46), Pair(14, -39),
        Pair(-56, 134), Pair(-119, 79), Pair(57, 149), Pair(56, 68), Pair(9, -18), Pair(0, 74), Pair(-46, 71), Pair(70, -65),
        Pair(162, 74), Pair(71, 83), Pair(119, 77), Pair(-3, 63), Pair(44, 57), Pair(12, 38), Pair(79, -1), Pair(-28, -7),
        Pair(80, 63), Pair(-9, 60), Pair(56, 59), Pair(-104, 80), Pair(-73, 58), Pair(-41, 47), Pair(19, 21), Pair(-30, 36),
        Pair(16, 45), Pair(122, 26), Pair(-13, 49), Pair(-29, 49), Pair(-39, 33), Pair(-30, 31), Pair(-8, 10), Pair(-73, 20),
        Pair(-1, 35), Pair(17, 28), Pair(55, 15), Pair(18, 34), Pair(13, 14), Pair(-39, 23), Pair(-27, 20), Pair(-83, 31),
        Pair(102, 10), Pair(21, 15), Pair(-4, 17), Pair(-37, 22), Pair(-6, 15), Pair(-15, 16), Pair(-10, 10), Pair(-9, 0),
        Pair(61, -6), Pair(35, -5), Pair(-4, 23), Pair(-14, -12), Pair(-7, 2), Pair(-31, 14), Pair(-1, -2), Pair(-1, -7)
      }
    }},
    {{ // Bucket 34
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(1, 22), Pair(-9, 45), Pair(-105, 50), Pair(-16, 34), Pair(-9, -3), Pair(9, 25), Pair(-61, -5), Pair(-43, -6),
        Pair(-11, 7), Pair(-25, 15), Pair(-18, -16), Pair(-27, 40), Pair(11, 7), Pair(15, 7), Pair(-7, -10), Pair(-10, -13),
        Pair(-2, 3), Pair(-2, -1), Pair(-6, -5), Pair(5, -5), Pair(12, -3), Pair(11, 5), Pair(-1, 8), Pair(-6, 6),
        Pair(2, 2), Pair(2, 3), Pair(-1, -1), Pair(3, 11), Pair(-1, -1), Pair(8, 1), Pair(-1, 9), Pair(0, 9),
        Pair(2, 3), Pair(3, 2), Pair(0, 2), Pair(0, 5), Pair(0, 7), Pair(5, 5), Pair(0, 9), Pair(0, 10),
        Pair(0, 7), Pair(-1, 6), Pair(3, 6), Pair(4, 6), Pair(-2, 19), Pair(-1, 7), Pair(-2, 9), Pair(2, 9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-82, 101), Pair(47, 51), Pair(26, 49), Pair(174, -5), Pair(-36, 38), Pair(-52, 1), Pair(-89, 14), Pair(-23, -52),
        Pair(6, 23), Pair(19, 29), Pair(-17, 13), Pair(-11, 24), Pair(10, 11), Pair(51, 0), Pair(42, 69), Pair(-33, 65),
        Pair(31, 4), Pair(-4, 3), Pair(-19, 21), Pair(21, 13), Pair(-37, 51), Pair(-41, 41), Pair(-4, 7), Pair(-38, 64),
        Pair(-29, 70), Pair(-13, 23), Pair(10, -1), Pair(16, 29), Pair(-2, 34), Pair(19, 31), Pair(-7, 36), Pair(9, 24),
        Pair(-7, 13), Pair(-14, 41), Pair(6, 53), Pair(5, 24), Pair(7, 17), Pair(9, 18), Pair(9, 5), Pair(-3, 4),
        Pair(0, 5), Pair(7, 14), Pair(10, 39), Pair(10, 23), Pair(8, 13), Pair(4, 20), Pair(-2, 25), Pair(15, 13),
        Pair(-1, -7), Pair(1, -5), Pair(13, -1), Pair(1, 23), Pair(4, 8), Pair(6, 35), Pair(12, -4), Pair(6, 17),
        Pair(57, -67), Pair(-11, 22), Pair(11, 11), Pair(12, -13), Pair(11, 8), Pair(3, 14), Pair(7, 21), Pair(30, 33)
      },
      { // Piece 2
        Pair(52, -27), Pair(68, -7), Pair(10, 0), Pair(-26, 11), Pair(72, -22), Pair(9, -40), Pair(4, -36), Pair(28, -26),
        Pair(-1, -34), Pair(14, 1), Pair(3, -15), Pair(16, -12), Pair(4, -17), Pair(43, -19), Pair(29, -23), Pair(34, -45),
        Pair(-24, 1), Pair(24, -8), Pair(33, -45), Pair(7, 29), Pair(2, -15), Pair(41, -24), Pair(30, -8), Pair(-16, -18),
        Pair(-6, 20), Pair(3, 7), Pair(-26, 23), Pair(16, -4), Pair(9, 7), Pair(3, -2), Pair(6, 22), Pair(-7, 9),
        Pair(13, 14), Pair(1, 4), Pair(24, 26), Pair(1, 16), Pair(8, -1), Pair(16, 7), Pair(19, 3), Pair(3, 28),
        Pair(-9, 2), Pair(0, -14), Pair(14, 8), Pair(-2, -1), Pair(6, 8), Pair(10, -4), Pair(2, 20), Pair(-2, 9),
        Pair(-21, -43), Pair(-2, 9), Pair(6, -1), Pair(1, 10), Pair(1, 1), Pair(9, 2), Pair(-2, 16), Pair(13, 1),
        Pair(7, -4), Pair(4, -33), Pair(2, 9), Pair(-5, 3), Pair(3, 5), Pair(-9, 13), Pair(19, -5), Pair(18, 19)
      },
      { // Piece 3
        Pair(-23, 27), Pair(-36, 32), Pair(-14, 17), Pair(-71, 45), Pair(-36, 35), Pair(-55, 42), Pair(26, 32), Pair(-9, 27),
        Pair(-26, 44), Pair(-20, 24), Pair(-31, 18), Pair(-44, 40), Pair(-26, 27), Pair(-20, 32), Pair(44, -12), Pair(-19, 32),
        Pair(-20, 44), Pair(-15, 32), Pair(-5, 6), Pair(-9, 16), Pair(-5, 27), Pair(-4, 30), Pair(-7, 27), Pair(-6, 24),
        Pair(-2, 12), Pair(-12, 21), Pair(2, -19), Pair(4, 24), Pair(25, 3), Pair(-11, 47), Pair(-11, 40), Pair(2, 24),
        Pair(-10, 22), Pair(8, 6), Pair(27, -1), Pair(3, 14), Pair(-14, 25), Pair(2, 8), Pair(18, 21), Pair(14, -23),
        Pair(18, 20), Pair(2, 27), Pair(20, -2), Pair(13, 4), Pair(-17, 24), Pair(4, 17), Pair(-7, 30), Pair(36, -23),
        Pair(28, -22), Pair(-12, 24), Pair(-6, -7), Pair(-1, 7), Pair(10, -5), Pair(-11, 8), Pair(-17, 33), Pair(20, 6),
        Pair(0, 10), Pair(7, 14), Pair(4, -6), Pair(5, 11), Pair(-3, 15), Pair(-1, 16), Pair(7, 4), Pair(-2, 12)
      },
      { // Piece 4
        Pair(-12, -4), Pair(-45, 43), Pair(0, -34), Pair(8, -43), Pair(-13, 12), Pair(18, -63), Pair(41, 54), Pair(67, -6),
        Pair(-8, 11), Pair(33, -37), Pair(-17, -44), Pair(-23, 31), Pair(25, 1), Pair(2, 8), Pair(33, -30), Pair(-5, 9),
        Pair(-20, 33), Pair(-8, 35), Pair(-2, -38), Pair(-18, 17), Pair(-8, 43), Pair(12, 4), Pair(0, 0), Pair(-15, 42),
        Pair(-9, 48), Pair(-5, 22), Pair(-26, -12), Pair(-19, 18), Pair(-3, 16), Pair(-6, 1), Pair(-15, 37), Pair(-13, 12),
        Pair(-10, 32), Pair(-1, 5), Pair(-28, 55), Pair(-12, 23), Pair(-2, 9), Pair(-14, 19), Pair(-6, -21), Pair(7, 27),
        Pair(-24, -15), Pair(-1, 6), Pair(-3, -2), Pair(5, 0), Pair(-9, 16), Pair(4, 23), Pair(-9, 19), Pair(26, -4),
        Pair(8, -10), Pair(-8, -22), Pair(2, 2), Pair(3, -3), Pair(-2, 0), Pair(2, 10), Pair(13, -29), Pair(-35, 6),
        Pair(13, -32), Pair(-8, -3), Pair(-11, 23), Pair(-1, 4), Pair(5, -14), Pair(22, -12), Pair(-49, 49), Pair(-8, 40)
      },
      { // Piece 5
        Pair(-23, 32), Pair(21, 55), Pair(23, 96), Pair(-6, 149), Pair(29, 70), Pair(29, 1), Pair(-65, 7), Pair(17, -43),
        Pair(18, 68), Pair(148, 160), Pair(166, 103), Pair(55, 14), Pair(-19, 13), Pair(-38, 30), Pair(-108, 38), Pair(-69, 26),
        Pair(3, 72), Pair(69, 56), Pair(137, 30), Pair(73, 61), Pair(-8, 68), Pair(10, 39), Pair(11, 20), Pair(-42, 20),
        Pair(68, 98), Pair(92, 50), Pair(69, 52), Pair(66, 73), Pair(102, 39), Pair(-12, 50), Pair(-3, 20), Pair(29, 8),
        Pair(-138, 108), Pair(55, 18), Pair(69, 41), Pair(60, 38), Pair(-16, 23), Pair(0, 11), Pair(-48, 20), Pair(54, -28),
        Pair(69, 24), Pair(-9, 26), Pair(-37, 43), Pair(19, 24), Pair(12, 7), Pair(-32, 15), Pair(17, -3), Pair(-37, 16),
        Pair(30, 17), Pair(-21, 20), Pair(-4, 6), Pair(18, 6), Pair(-16, 15), Pair(-1, 4), Pair(-1, 2), Pair(-8, 2),
        Pair(39, -43), Pair(24, -7), Pair(15, -20), Pair(31, -37), Pair(1, -16), Pair(-19, 10), Pair(-2, -5), Pair(-13, -9)
      }
    }},
    {{ // Bucket 35
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-20, 44), Pair(-58, 7), Pair(-45, 7), Pair(-22, 2), Pair(-20, 20), Pair(-14, 50), Pair(46, -46), Pair(-5, 21),
        Pair(6, 15), Pair(3, 10), Pair(-6, 28), Pair(-8, -12), Pair(11, 9), Pair(-2, 17), Pair(-28, 32), Pair(-20, 33),
        Pair(8, 1), Pair(-2, 1), Pair(4, -2), Pair(-4, 0), Pair(11, -3), Pair(0, -1), Pair(-6, 11), Pair(-1, 1),
        Pair(1, 4), Pair(0, 4), Pair(-2, 9), Pair(-2, -5), Pair(1, 12), Pair(2, 3), Pair(4, 5), Pair(1, 9),
        Pair(0, 7), Pair(7, 8), Pair(5, 9), Pair(20, 5), Pair(4, 13), Pair(6, 13), Pair(3, 7), Pair(3, 6),
        Pair(-1, 9), Pair(3, 9), Pair(2, 5), Pair(14, 4), Pair(1, 15), Pair(0, 8), Pair(-1, 10), Pair(1, 6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-19, 39), Pair(9, 64), Pair(4, 30), Pair(21, 37), Pair(20, 38), Pair(-43, -27), Pair(12, 4), Pair(-74, 16),
        Pair(15, 21), Pair(-4, 17), Pair(-2, 23), Pair(13, 60), Pair(-19, 33), Pair(14, -9), Pair(0, 24), Pair(41, -6),
        Pair(9, 31), Pair(-2, 24), Pair(13, 11), Pair(-13, -1), Pair(-7, 51), Pair(-18, 45), Pair(-12, 43), Pair(-2, 22),
        Pair(29, 21), Pair(2, 36), Pair(30, 38), Pair(1, 1), Pair(5, 24), Pair(0, 42), Pair(6, 14), Pair(-39, 63),
        Pair(10, 38), Pair(7, 25), Pair(9, 26), Pair(15, 49), Pair(-2, 41), Pair(4, 34), Pair(-16, 33), Pair(13, 28),
        Pair(-5, 15), Pair(-4, 33), Pair(5, 28), Pair(8, 45), Pair(7, 20), Pair(7, 22), Pair(6, 32), Pair(4, 19),
        Pair(1, -13), Pair(27, 11), Pair(3, 30), Pair(9, 4), Pair(3, 22), Pair(-6, 26), Pair(28, 28), Pair(3, 24),
        Pair(21, 43), Pair(-2, 29), Pair(8, 31), Pair(3, 7), Pair(8, 15), Pair(-6, 23), Pair(11, 18), Pair(42, 13)
      },
      { // Piece 2
        Pair(-48, -17), Pair(-20, -59), Pair(127, 8), Pair(46, -25), Pair(-49, 10), Pair(11, -11), Pair(92, -8), Pair(43, -8),
        Pair(-15, -6), Pair(7, 19), Pair(-35, 18), Pair(6, 9), Pair(19, 0), Pair(18, -21), Pair(57, -59), Pair(1, -9),
        Pair(4, -1), Pair(-2, -11), Pair(35, -9), Pair(-2, -28), Pair(-17, 14), Pair(-37, -2), Pair(58, -40), Pair(1, 4),
        Pair(18, -15), Pair(8, -8), Pair(7, 4), Pair(-19, 13), Pair(6, 10), Pair(19, -8), Pair(-4, 11), Pair(-6, 2),
        Pair(14, -8), Pair(15, -12), Pair(-2, 15), Pair(22, 20), Pair(-9, 20), Pair(11, -6), Pair(15, -21), Pair(4, -15),
        Pair(2, -14), Pair(5, -15), Pair(-16, 0), Pair(11, 3), Pair(3, 5), Pair(6, 0), Pair(7, 5), Pair(1, 5),
        Pair(2, 4), Pair(-16, -1), Pair(13, -21), Pair(6, 3), Pair(2, 2), Pair(21, -9), Pair(-6, 15), Pair(15, -10),
        Pair(-25, -35), Pair(18, 5), Pair(0, -6), Pair(14, -4), Pair(24, -18), Pair(3, -3), Pair(-5, -28), Pair(6, -35)
      },
      { // Piece 3
        Pair(29, 23), Pair(7, 13), Pair(6, 25), Pair(7, 16), Pair(-5, 16), Pair(-57, 49), Pair(18, 21), Pair(49, 5),
        Pair(3, 24), Pair(-8, 36), Pair(-1, 17), Pair(11, 25), Pair(9, 32), Pair(21, 6), Pair(-26, 28), Pair(-22, 35),
        Pair(-23, 38), Pair(-17, 37), Pair(-18, 32), Pair(-47, 0), Pair(-6, 16), Pair(-21, 40), Pair(-11, 31), Pair(17, 34),
        Pair(1, 17), Pair(-21, 35), Pair(11, 6), Pair(-17, 15), Pair(5, 19), Pair(-19, 19), Pair(-5, 27), Pair(-8, 30),
        Pair(9, 10), Pair(4, 9), Pair(-16, 33), Pair(19, -12), Pair(1, -7), Pair(-8, 19), Pair(9, -2), Pair(-26, 22),
        Pair(2, 21), Pair(-5, 29), Pair(17, 16), Pair(8, -1), Pair(5, 9), Pair(3, 5), Pair(-11, 11), Pair(7, 5),
        Pair(3, 1), Pair(-5, 10), Pair(-2, 15), Pair(-9, 2), Pair(4, 3), Pair(-9, 13), Pair(5, 22), Pair(29, -21),
        Pair(1, 16), Pair(3, 10), Pair(-4, 20), Pair(6, 9), Pair(0, 15), Pair(-1, 13), Pair(2, 13), Pair(2, 1)
      },
      { // Piece 4
        Pair(-2, -22), Pair(63, -25), Pair(56, 16), Pair(-15, 20), Pair(-28, 20), Pair(15, -38), Pair(-3, 3), Pair(77, -22),
        Pair(4, -13), Pair(0, -1), Pair(-4, 12), Pair(1, 26), Pair(-26, 48), Pair(12, 1), Pair(40, -13), Pair(-28, 28),
        Pair(10, 1), Pair(1, 5), Pair(-3, 8), Pair(7, -26), Pair(-24, 32), Pair(3, 17), Pair(-16, 29), Pair(-4, 23),
        Pair(-5, 4), Pair(-4, 22), Pair(13, -15), Pair(-34, 14), Pair(-31, 29), Pair(22, 27), Pair(5, -13), Pair(-4, 16),
        Pair(-2, 26), Pair(11, 11), Pair(-4, 3), Pair(12, 19), Pair(-21, 33), Pair(-2, 26), Pair(-14, 40), Pair(9, -20),
        Pair(-9, 4), Pair(-1, 17), Pair(-9, 36), Pair(6, 1), Pair(9, 19), Pair(2, 22), Pair(17, 1), Pair(2, 33),
        Pair(15, -39), Pair(10, -6), Pair(-2, 20), Pair(5, -10), Pair(-1, 8), Pair(7, 5), Pair(1, 1), Pair(4, 17),
        Pair(9, -22), Pair(7, 35), Pair(-3, 21), Pair(3, 3), Pair(-7, 11), Pair(-17, 33), Pair(39, -53), Pair(18, 43)
      },
      { // Piece 5
        Pair(-14, 50), Pair(-26, 24), Pair(59, 9), Pair(-8, 21), Pair(12, 58), Pair(49, 211), Pair(3, 67), Pair(-23, -27),
        Pair(-45, 97), Pair(96, 71), Pair(1, 77), Pair(7, 68), Pair(-73, 43), Pair(57, 40), Pair(-6, 75), Pair(38, 17),
        Pair(-157, 64), Pair(24, 16), Pair(73, 46), Pair(-15, 42), Pair(111, 28), Pair(38, 10), Pair(43, -4), Pair(-23, -10),
        Pair(21, 59), Pair(25, 33), Pair(-101, 85), Pair(28, 39), Pair(-3, 65), Pair(-19, 18), Pair(-36, 30), Pair(54, -17),
        Pair(25, 16), Pair(2, 29), Pair(12, 32), Pair(-26, 54), Pair(6, 40), Pair(-15, 26), Pair(25, -2), Pair(-60, 14),
        Pair(-14, 8), Pair(26, 6), Pair(-8, 24), Pair(-66, 46), Pair(12, 11), Pair(6, 5), Pair(-17, -2), Pair(-12, -10),
        Pair(29, -16), Pair(18, -9), Pair(-6, 8), Pair(-18, 13), Pair(-16, -10), Pair(-2, -5), Pair(-3, -4), Pair(2, -12),
        Pair(10, -15), Pair(-17, 8), Pair(-4, -18), Pair(-44, 0), Pair(9, -37), Pair(8, -4), Pair(-2, -9), Pair(3, -18)
      }
    }},
    {{ // Bucket 36
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-47, 21), Pair(9, 25), Pair(-59, 23), Pair(-20, 26), Pair(-27, -18), Pair(46, 63), Pair(37, 61), Pair(9, 71),
        Pair(-8, 18), Pair(13, 8), Pair(21, 9), Pair(6, 23), Pair(36, -44), Pair(12, 21), Pair(-14, 3), Pair(-3, 17),
        Pair(2, 1), Pair(-3, 10), Pair(3, -3), Pair(7, 3), Pair(10, 1), Pair(9, 6), Pair(-6, 0), Pair(1, 2),
        Pair(0, 5), Pair(3, 7), Pair(1, 0), Pair(4, 3), Pair(-2, -7), Pair(7, -1), Pair(1, 6), Pair(1, 6),
        Pair(4, 5), Pair(4, 8), Pair(5, 10), Pair(6, 6), Pair(12, 9), Pair(8, 6), Pair(0, 10), Pair(-2, 8),
        Pair(5, 6), Pair(2, 8), Pair(2, 5), Pair(-3, 19), Pair(14, 16), Pair(-2, 15), Pair(0, 11), Pair(-3, 14),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-18, -39), Pair(11, 37), Pair(-11, -24), Pair(7, 51), Pair(21, 35), Pair(109, 21), Pair(15, 45), Pair(35, -10),
        Pair(-8, -5), Pair(10, 40), Pair(5, 33), Pair(5, 33), Pair(-26, 78), Pair(0, 37), Pair(17, 46), Pair(-12, 26),
        Pair(5, 43), Pair(34, 38), Pair(-26, 59), Pair(29, 29), Pair(-36, 38), Pair(-3, 39), Pair(-41, 22), Pair(-19, 11),
        Pair(15, 32), Pair(13, 36), Pair(15, 36), Pair(-7, 44), Pair(-19, 44), Pair(20, 36), Pair(-6, 28), Pair(-2, 38),
        Pair(9, 39), Pair(47, 30), Pair(11, 27), Pair(13, 28), Pair(23, 60), Pair(20, 12), Pair(0, 37), Pair(6, 36),
        Pair(11, 17), Pair(5, 23), Pair(0, 27), Pair(10, 31), Pair(13, 31), Pair(5, 29), Pair(11, 8), Pair(8, 22),
        Pair(-29, 63), Pair(33, 32), Pair(-5, 9), Pair(4, 25), Pair(9, 27), Pair(11, 23), Pair(-21, 49), Pair(-2, 24),
        Pair(23, 37), Pair(1, 7), Pair(-8, 53), Pair(-11, 28), Pair(13, 45), Pair(-4, 29), Pair(15, 8), Pair(38, 35)
      },
      { // Piece 2
        Pair(-50, 23), Pair(9, -30), Pair(69, 6), Pair(138, -6), Pair(30, -28), Pair(83, -9), Pair(27, -22), Pair(-21, -19),
        Pair(28, -27), Pair(-2, -12), Pair(-7, -2), Pair(30, -15), Pair(35, -13), Pair(41, -30), Pair(-75, 10), Pair(-14, -24),
        Pair(18, 13), Pair(1, 0), Pair(-11, 17), Pair(5, 6), Pair(16, -4), Pair(24, -15), Pair(20, 8), Pair(3, 5),
        Pair(7, -6), Pair(-6, 17), Pair(16, -7), Pair(5, 7), Pair(1, 19), Pair(46, -20), Pair(2, -1), Pair(-7, 32),
        Pair(12, -15), Pair(21, -8), Pair(9, 3), Pair(5, 0), Pair(17, 42), Pair(5, 1), Pair(-9, 4), Pair(1, -1),
        Pair(-4, 8), Pair(-5, 8), Pair(-4, 15), Pair(6, -4), Pair(4, 18), Pair(-6, -10), Pair(-8, 4), Pair(4, -1),
        Pair(22, -30), Pair(-3, 12), Pair(1, 4), Pair(3, 8), Pair(4, -1), Pair(-4, 11), Pair(-11, -1), Pair(-12, -18),
        Pair(-16, 4), Pair(-7, -19), Pair(-1, 9), Pair(13, 2), Pair(13, -12), Pair(-4, 11), Pair(26, -25), Pair(-11, -52)
      },
      { // Piece 3
        Pair(-34, 49), Pair(-9, 34), Pair(11, 15), Pair(9, 12), Pair(-11, 34), Pair(-42, 45), Pair(35, 10), Pair(4, 11),
        Pair(-11, 25), Pair(-10, 32), Pair(-16, 26), Pair(-34, 53), Pair(-7, 14), Pair(-15, 18), Pair(23, 7), Pair(16, 31),
        Pair(10, 24), Pair(14, 28), Pair(-21, 29), Pair(-1, 29), Pair(-51, 23), Pair(-5, 28), Pair(-15, 34), Pair(18, 11),
        Pair(4, 32), Pair(2, 27), Pair(-10, 34), Pair(14, 17), Pair(-7, 2), Pair(3, 3), Pair(19, 18), Pair(35, 19),
        Pair(-1, 29), Pair(5, 20), Pair(13, 5), Pair(20, -2), Pair(7, 25), Pair(-1, 27), Pair(-23, 43), Pair(-3, 30),
        Pair(11, 15), Pair(12, 5), Pair(15, 3), Pair(24, 2), Pair(1, 24), Pair(5, 6), Pair(15, 6), Pair(15, -7),
        Pair(2, 28), Pair(-8, 11), Pair(6, 2), Pair(1, 17), Pair(-7, 15), Pair(-9, 6), Pair(1, 16), Pair(10, 5),
        Pair(4, 17), Pair(3, 24), Pair(-1, 29), Pair(3, 22), Pair(11, 13), Pair(-2, 24), Pair(8, 10), Pair(13, 15)
      },
      { // Piece 4
        Pair(-17, 5), Pair(6, 37), Pair(9, -5), Pair(-1, 31), Pair(-34, -7), Pair(44, 26), Pair(-107, 78), Pair(52, -100),
        Pair(-16, 35), Pair(13, -10), Pair(8, 4), Pair(40, -25), Pair(-10, 21), Pair(49, 16), Pair(45, -6), Pair(-10, 70),
        Pair(9, 41), Pair(-5, 32), Pair(1, 15), Pair(-16, 57), Pair(16, -22), Pair(-2, 70), Pair(19, 40), Pair(-1, 41),
        Pair(0, -3), Pair(-21, 42), Pair(1, 19), Pair(-9, 26), Pair(9, 15), Pair(15, 14), Pair(-16, 53), Pair(0, 13),
        Pair(11, -14), Pair(7, 6), Pair(5, 7), Pair(-9, 3), Pair(4, 55), Pair(-5, 14), Pair(11, 34), Pair(-10, 46),
        Pair(15, -28), Pair(10, -4), Pair(2, 24), Pair(8, 15), Pair(3, 25), Pair(4, 21), Pair(-6, 7), Pair(-6, 68),
        Pair(16, -2), Pair(1, -3), Pair(8, -5), Pair(-1, 14), Pair(1, 11), Pair(4, 0), Pair(-14, 25), Pair(24, -41),
        Pair(9, -30), Pair(29, -18), Pair(9, -9), Pair(5, 20), Pair(3, 13), Pair(2, 15), Pair(-17, 24), Pair(31, -74)
      },
      { // Piece 5
        Pair(-19, -50), Pair(-7, -1), Pair(2, 81), Pair(-16, 87), Pair(-30, 93), Pair(15, 44), Pair(64, 144), Pair(-16, 3),
        Pair(-34, 50), Pair(-47, 30), Pair(-64, 22), Pair(60, 62), Pair(52, 65), Pair(38, 99), Pair(128, -29), Pair(-66, 9),
        Pair(80, 11), Pair(-18, 32), Pair(-84, 36), Pair(35, 76), Pair(27, 41), Pair(33, 54), Pair(43, -1), Pair(68, 6),
        Pair(-66, -9), Pair(-77, 17), Pair(48, 11), Pair(7, 51), Pair(32, 21), Pair(32, 33), Pair(13, 18), Pair(10, 2),
        Pair(-28, 6), Pair(-34, 2), Pair(-13, 23), Pair(-31, 36), Pair(40, 43), Pair(-45, 31), Pair(1, 8), Pair(-10, 1),
        Pair(-83, -35), Pair(-11, 20), Pair(44, -3), Pair(-46, 28), Pair(-1, 22), Pair(-5, 5), Pair(13, -5), Pair(0, -15),
        Pair(12, 1), Pair(-10, -13), Pair(-24, -3), Pair(-10, -5), Pair(-28, 4), Pair(-23, -1), Pair(2, -9), Pair(15, -19),
        Pair(0, -16), Pair(-14, -5), Pair(-6, -19), Pair(-25, -9), Pair(-6, -27), Pair(8, -31), Pair(3, -21), Pair(2, -25)
      }
    }},
    {{ // Bucket 37
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(31, 1), Pair(12, -18), Pair(9, -13), Pair(-5, 5), Pair(-8, -5), Pair(-2, -75), Pair(38, 10), Pair(-25, 7),
        Pair(4, 4), Pair(-13, 7), Pair(1, 11), Pair(17, 3), Pair(10, 17), Pair(-3, 8), Pair(-33, 22), Pair(-2, 17),
        Pair(9, 4), Pair(7, 0), Pair(6, 8), Pair(9, -1), Pair(3, 7), Pair(9, 4), Pair(-20, 3), Pair(-6, 2),
        Pair(2, 2), Pair(6, 6), Pair(6, 1), Pair(0, 0), Pair(1, 11), Pair(-3, -5), Pair(11, -4), Pair(-3, 0),
        Pair(2, 6), Pair(8, 8), Pair(5, 3), Pair(2, 8), Pair(8, 3), Pair(15, 0), Pair(2, 3), Pair(2, -1),
        Pair(0, 8), Pair(4, 8), Pair(0, 12), Pair(-1, 16), Pair(10, 7), Pair(12, 13), Pair(-2, 8), Pair(-1, 4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-13, -11), Pair(-84, 50), Pair(-14, 36), Pair(112, -32), Pair(75, -31), Pair(152, -9), Pair(-34, -10), Pair(52, -33),
        Pair(11, -10), Pair(-1, 15), Pair(-27, 32), Pair(19, 5), Pair(52, -13), Pair(-13, 17), Pair(-21, 43), Pair(34, -28),
        Pair(-35, -8), Pair(19, 15), Pair(32, 18), Pair(44, -7), Pair(19, 12), Pair(-7, 23), Pair(8, 4), Pair(-8, 21),
        Pair(-11, 14), Pair(10, 12), Pair(18, 22), Pair(16, 14), Pair(14, 23), Pair(-6, 14), Pair(0, 5), Pair(-12, 16),
        Pair(-5, 20), Pair(16, 15), Pair(10, 19), Pair(18, 13), Pair(-1, 34), Pair(50, 43), Pair(-2, 19), Pair(-4, 2),
        Pair(1, 9), Pair(12, 9), Pair(6, 23), Pair(2, 18), Pair(8, 13), Pair(6, 40), Pair(6, 11), Pair(0, -14),
        Pair(5, 9), Pair(12, -1), Pair(-2, 18), Pair(-1, 26), Pair(0, 29), Pair(5, -19), Pair(2, 0), Pair(-8, 3),
        Pair(-63, -1), Pair(3, 3), Pair(-30, 19), Pair(4, 14), Pair(1, 5), Pair(1, 6), Pair(-7, -14), Pair(11, -20)
      },
      { // Piece 2
        Pair(-61, -10), Pair(-57, 16), Pair(-42, 1), Pair(18, -41), Pair(-20, 8), Pair(-63, -2), Pair(6, -33), Pair(-28, 8),
        Pair(51, -48), Pair(-3, -1), Pair(-36, 8), Pair(14, -13), Pair(10, -18), Pair(60, -33), Pair(-2, -28), Pair(-57, 19),
        Pair(-1, -3), Pair(16, -11), Pair(2, 1), Pair(26, -15), Pair(45, -13), Pair(-10, -5), Pair(5, -6), Pair(-66, 48),
        Pair(-8, 5), Pair(27, -13), Pair(-15, -5), Pair(18, -2), Pair(-1, 12), Pair(34, -8), Pair(-15, 16), Pair(15, -4),
        Pair(6, -7), Pair(-3, 5), Pair(2, -6), Pair(12, 0), Pair(-1, 19), Pair(17, 14), Pair(14, -12), Pair(-34, 4),
        Pair(6, -11), Pair(13, 2), Pair(-2, -3), Pair(-1, 12), Pair(5, 7), Pair(12, 17), Pair(-13, -8), Pair(4, 10),
        Pair(9, 1), Pair(-1, 2), Pair(7, 0), Pair(-3, 4), Pair(5, 5), Pair(4, -18), Pair(4, -3), Pair(-11, 1),
        Pair(13, 20), Pair(-4, 3), Pair(-4, -2), Pair(-16, 5), Pair(0, -14), Pair(-1, -4), Pair(4, -44), Pair(16, -49)
      },
      { // Piece 3
        Pair(29, 1), Pair(23, 10), Pair(21, 13), Pair(56, -5), Pair(24, 13), Pair(112, -25), Pair(101, -31), Pair(31, 0),
        Pair(10, 11), Pair(12, 8), Pair(16, 9), Pair(39, -1), Pair(2, 5), Pair(-41, 11), Pair(13, 9), Pair(8, 15),
        Pair(19, -1), Pair(17, 8), Pair(17, 10), Pair(29, -8), Pair(-2, 21), Pair(23, -26), Pair(32, -3), Pair(17, 1),
        Pair(4, 17), Pair(21, 10), Pair(5, 6), Pair(22, 14), Pair(30, 13), Pair(32, -19), Pair(-17, 18), Pair(-6, 19),
        Pair(1, -2), Pair(28, -8), Pair(-2, 21), Pair(18, 12), Pair(0, 4), Pair(-1, -5), Pair(4, 6), Pair(32, -12),
        Pair(5, -7), Pair(-9, 13), Pair(-6, 12), Pair(6, 2), Pair(-8, 7), Pair(26, -12), Pair(-7, -8), Pair(22, -11),
        Pair(-36, 1), Pair(8, -3), Pair(-12, 8), Pair(-3, 7), Pair(-2, 17), Pair(7, -18), Pair(-2, 24), Pair(-31, 22),
        Pair(1, 12), Pair(5, 6), Pair(4, 7), Pair(6, 4), Pair(-1, 8), Pair(12, -7), Pair(0, 23), Pair(1, 4)
      },
      { // Piece 4
        Pair(9, -5), Pair(42, -19), Pair(-63, 37), Pair(-18, 45), Pair(7, 26), Pair(79, -19), Pair(-30, 52), Pair(13, 30),
        Pair(-15, 23), Pair(-1, -37), Pair(21, 11), Pair(44, -28), Pair(-6, -8), Pair(38, -44), Pair(-37, -43), Pair(7, 59),
        Pair(22, -40), Pair(9, -14), Pair(4, 14), Pair(-1, 65), Pair(5, -19), Pair(-12, 3), Pair(9, -19), Pair(12, 39),
        Pair(-7, 14), Pair(-9, 35), Pair(1, -3), Pair(0, 20), Pair(2, 20), Pair(4, -9), Pair(41, -63), Pair(-7, 25),
        Pair(-3, 31), Pair(11, -7), Pair(17, 6), Pair(-5, 27), Pair(9, 1), Pair(7, -21), Pair(-6, 9), Pair(33, -76),
        Pair(10, 8), Pair(-1, 17), Pair(9, 8), Pair(2, 20), Pair(-8, 6), Pair(15, -15), Pair(-3, -14), Pair(6, 5),
        Pair(9, -27), Pair(7, -6), Pair(1, 17), Pair(4, -9), Pair(8, -6), Pair(-10, -2), Pair(0, -5), Pair(-2, -36),
        Pair(15, 4), Pair(-14, 19), Pair(6, -6), Pair(-1, 4), Pair(6, -6), Pair(-21, -10), Pair(-3, 25), Pair(-19, -30)
      },
      { // Piece 5
        Pair(4, -71), Pair(-98, 44), Pair(-29, 85), Pair(-30, 36), Pair(-68, 91), Pair(-26, 26), Pair(-30, 67), Pair(24, 103),
        Pair(-31, 33), Pair(-14, 25), Pair(78, 23), Pair(-64, 17), Pair(-45, 59), Pair(15, 16), Pair(6, 95), Pair(42, 25),
        Pair(80, -24), Pair(31, 9), Pair(-29, 25), Pair(-36, 79), Pair(93, 45), Pair(31, 56), Pair(103, 9), Pair(31, 25),
        Pair(-141, 17), Pair(-102, 37), Pair(3, 16), Pair(-29, 31), Pair(126, 21), Pair(76, 28), Pair(26, 25), Pair(79, 19),
        Pair(-52, 2), Pair(6, -7), Pair(-64, 24), Pair(8, 28), Pair(36, 15), Pair(-16, 43), Pair(6, 14), Pair(51, 4),
        Pair(-31, -6), Pair(-21, -4), Pair(-2, 12), Pair(4, 10), Pair(-18, 18), Pair(-13, 19), Pair(-5, 7), Pair(5, 1),
        Pair(-38, 9), Pair(-10, 12), Pair(-35, 1), Pair(3, 8), Pair(-14, 6), Pair(-41, 12), Pair(-8, -2), Pair(9, 1),
        Pair(-27, 1), Pair(-18, -4), Pair(-28, 8), Pair(-33, -15), Pair(0, -41), Pair(-22, -16), Pair(6, -30), Pair(-4, -12)
      }
    }},
    {{ // Bucket 38
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-35, -14), Pair(34, -15), Pair(73, -29), Pair(79, -27), Pair(48, 27), Pair(24, 2), Pair(-39, 12), Pair(10, 17),
        Pair(4, -11), Pair(-2, 13), Pair(3, 4), Pair(13, 4), Pair(18, 6), Pair(-10, 14), Pair(88, -39), Pair(-34, 15),
        Pair(7, 2), Pair(3, -5), Pair(1, 4), Pair(12, 2), Pair(3, -4), Pair(-4, 3), Pair(18, -1), Pair(-17, -8),
        Pair(-2, 11), Pair(-8, 12), Pair(2, 5), Pair(7, 7), Pair(-6, 7), Pair(2, -3), Pair(-5, 2), Pair(10, -13),
        Pair(-2, 16), Pair(1, 11), Pair(1, 15), Pair(0, 8), Pair(7, 9), Pair(12, 2), Pair(9, 9), Pair(7, -5),
        Pair(0, 9), Pair(-1, 11), Pair(2, 10), Pair(6, 7), Pair(7, 18), Pair(7, 13), Pair(17, 13), Pair(2, 5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(41, 8), Pair(-11, 34), Pair(-68, 65), Pair(56, 16), Pair(62, -3), Pair(-42, -23), Pair(-9, 36), Pair(65, -26),
        Pair(-45, -3), Pair(-47, 22), Pair(-5, -4), Pair(87, 13), Pair(29, 12), Pair(50, -28), Pair(-6, 29), Pair(39, 15),
        Pair(66, 3), Pair(22, 13), Pair(8, 23), Pair(25, 33), Pair(-42, 28), Pair(39, 15), Pair(4, -5), Pair(11, 8),
        Pair(-27, 15), Pair(9, 10), Pair(3, 18), Pair(31, 12), Pair(23, 25), Pair(35, 14), Pair(25, -4), Pair(19, 11),
        Pair(0, 3), Pair(5, 17), Pair(6, 12), Pair(8, 17), Pair(23, 15), Pair(17, 35), Pair(68, 25), Pair(13, 17),
        Pair(-1, 18), Pair(-7, 24), Pair(0, 18), Pair(-7, 23), Pair(12, 17), Pair(9, 21), Pair(20, 19), Pair(-8, 2),
        Pair(-1, -12), Pair(13, 33), Pair(2, 19), Pair(10, 11), Pair(-2, 18), Pair(-13, 17), Pair(-1, -25), Pair(-6, -18),
        Pair(0, -18), Pair(-18, -6), Pair(-27, 4), Pair(8, 39), Pair(13, 31), Pair(-17, 19), Pair(0, -4), Pair(-64, -95)
      },
      { // Piece 2
        Pair(97, -65), Pair(90, -24), Pair(108, -24), Pair(30, -20), Pair(80, -31), Pair(-107, 23), Pair(184, -35), Pair(-123, 16),
        Pair(-27, 24), Pair(55, -39), Pair(-40, 7), Pair(27, -9), Pair(38, -3), Pair(-3, -18), Pair(-5, 16), Pair(-19, 24),
        Pair(-23, 12), Pair(8, -14), Pair(33, -28), Pair(44, -22), Pair(32, 3), Pair(63, 9), Pair(63, -24), Pair(32, -23),
        Pair(-11, 8), Pair(6, -15), Pair(-9, 18), Pair(44, -14), Pair(18, -1), Pair(41, -8), Pair(30, -29), Pair(13, -16),
        Pair(-23, 22), Pair(23, -4), Pair(16, 2), Pair(20, -1), Pair(11, 3), Pair(10, 9), Pair(34, 21), Pair(19, -17),
        Pair(-10, 16), Pair(36, -20), Pair(3, 11), Pair(-3, 9), Pair(9, 8), Pair(-5, 4), Pair(15, 23), Pair(-8, -27),
        Pair(13, -5), Pair(6, 9), Pair(1, -5), Pair(-2, 16), Pair(4, 11), Pair(-11, 9), Pair(9, -11), Pair(-7, -10),
        Pair(9, -12), Pair(18, -28), Pair(-3, 11), Pair(-8, 20), Pair(-6, 6), Pair(7, -18), Pair(-11, -26), Pair(12, -24)
      },
      { // Piece 3
        Pair(0, 25), Pair(15, 26), Pair(31, 2), Pair(39, 19), Pair(74, 7), Pair(26, 7), Pair(18, 25), Pair(15, 15),
        Pair(48, 15), Pair(40, 2), Pair(46, -1), Pair(46, 5), Pair(36, 3), Pair(-7, 23), Pair(79, -11), Pair(22, 8),
        Pair(12, 23), Pair(35, 11), Pair(46, -9), Pair(7, 12), Pair(-12, 5), Pair(13, 20), Pair(58, -24), Pair(-19, 43),
        Pair(27, 6), Pair(17, 18), Pair(-4, 12), Pair(52, 10), Pair(28, 8), Pair(15, 24), Pair(59, -32), Pair(10, 3),
        Pair(-13, 24), Pair(-29, 45), Pair(-17, 24), Pair(-1, 5), Pair(-25, 26), Pair(-3, 23), Pair(28, 3), Pair(-15, 12),
        Pair(-12, 17), Pair(2, -13), Pair(-25, 39), Pair(6, 18), Pair(17, 11), Pair(1, 18), Pair(-14, 29), Pair(-14, 19),
        Pair(-20, 20), Pair(4, 22), Pair(14, -9), Pair(5, 17), Pair(15, 10), Pair(16, -13), Pair(26, -46), Pair(-16, 38),
        Pair(-4, 18), Pair(6, 11), Pair(2, 19), Pair(4, 13), Pair(2, 13), Pair(5, 2), Pair(8, -6), Pair(0, 1)
      },
      { // Piece 4
        Pair(20, -3), Pair(24, 27), Pair(-71, 20), Pair(-34, 54), Pair(-19, 60), Pair(-46, 17), Pair(-6, -80), Pair(23, -82),
        Pair(-64, 58), Pair(2, 28), Pair(-21, 68), Pair(33, 31), Pair(39, 7), Pair(-8, -26), Pair(37, -96), Pair(16, -52),
        Pair(-12, 7), Pair(32, -38), Pair(-3, -13), Pair(23, 17), Pair(-51, 44), Pair(35, 7), Pair(44, -70), Pair(37, 0),
        Pair(-25, -35), Pair(-19, 31), Pair(-29, 47), Pair(50, -50), Pair(-10, 35), Pair(-2, 2), Pair(-38, 24), Pair(32, -49),
        Pair(1, -2), Pair(18, -23), Pair(-22, 21), Pair(6, 3), Pair(7, 19), Pair(-9, 56), Pair(22, -44), Pair(-7, -19),
        Pair(13, 33), Pair(-15, 4), Pair(-1, 12), Pair(2, -10), Pair(-5, 21), Pair(8, -1), Pair(-9, 10), Pair(-1, 22),
        Pair(0, 20), Pair(-3, 25), Pair(4, -6), Pair(3, 2), Pair(5, -15), Pair(8, -29), Pair(-7, 2), Pair(60, -55),
        Pair(20, 10), Pair(-22, 42), Pair(18, -24), Pair(-7, 16), Pair(19, -35), Pair(-15, -33), Pair(41, -64), Pair(3, 15)
      },
      { // Piece 5
        Pair(46, -43), Pair(-66, 31), Pair(2, 5), Pair(-24, -31), Pair(-18, 8), Pair(55, 60), Pair(-9, 69), Pair(20, 45),
        Pair(-83, 41), Pair(6, 7), Pair(-69, 51), Pair(9, 20), Pair(34, 74), Pair(24, 38), Pair(59, 83), Pair(22, 114),
        Pair(-36, -41), Pair(-64, 10), Pair(-34, 16), Pair(87, 46), Pair(62, 28), Pair(74, 53), Pair(179, 27), Pair(171, 14),
        Pair(-43, 19), Pair(-37, 29), Pair(-32, 9), Pair(-49, 51), Pair(-13, 28), Pair(130, 21), Pair(18, 56), Pair(-100, 76),
        Pair(-42, 34), Pair(28, 15), Pair(-12, 14), Pair(-83, 39), Pair(-79, 36), Pair(2, 15), Pair(47, 29), Pair(-42, 31),
        Pair(-69, 5), Pair(-51, 9), Pair(25, 8), Pair(15, 18), Pair(-21, 19), Pair(-31, 26), Pair(13, 20), Pair(-10, 8),
        Pair(-28, -9), Pair(-39, 8), Pair(-38, 17), Pair(-25, 7), Pair(-31, 11), Pair(-30, 15), Pair(6, 7), Pair(-14, 12),
        Pair(12, -46), Pair(-24, 9), Pair(-21, -17), Pair(-22, -3), Pair(-9, -6), Pair(-7, -13), Pair(7, -5), Pair(-9, -24)
      }
    }},
    {{ // Bucket 39
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(36, -28), Pair(42, 2), Pair(57, -37), Pair(-25, 16), Pair(39, 1), Pair(1, 12), Pair(-9, 42), Pair(14, 26),
        Pair(4, -5), Pair(-34, 4), Pair(0, 10), Pair(8, -8), Pair(1, 2), Pair(-5, 0), Pair(-6, -12), Pair(39, -14),
        Pair(1, 9), Pair(1, 5), Pair(7, 6), Pair(5, 0), Pair(4, 3), Pair(-7, -7), Pair(-9, -4), Pair(12, 6),
        Pair(-1, 8), Pair(2, 14), Pair(-1, 6), Pair(0, 7), Pair(-1, 9), Pair(-2, 2), Pair(2, -11), Pair(-2, 2),
        Pair(0, 10), Pair(3, 8), Pair(0, 12), Pair(2, 10), Pair(5, 3), Pair(9, 4), Pair(5, -3), Pair(-3, 13),
        Pair(-3, 11), Pair(0, 10), Pair(-2, 13), Pair(2, 6), Pair(-2, 15), Pair(6, 1), Pair(1, 4), Pair(7, 21),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-29, 15), Pair(185, 40), Pair(-44, 28), Pair(62, -45), Pair(56, 4), Pair(106, -54), Pair(11, 10), Pair(38, 16),
        Pair(15, 9), Pair(-55, 17), Pair(-16, 3), Pair(69, -14), Pair(-3, 45), Pair(19, 9), Pair(-31, -2), Pair(21, 34),
        Pair(-12, 26), Pair(5, 20), Pair(9, 8), Pair(16, 8), Pair(50, 2), Pair(39, 9), Pair(38, 9), Pair(-21, 38),
        Pair(2, 18), Pair(3, 1), Pair(16, -3), Pair(18, 13), Pair(20, 13), Pair(29, 12), Pair(20, 10), Pair(25, 0),
        Pair(-7, 7), Pair(14, 28), Pair(18, 2), Pair(3, 6), Pair(20, 7), Pair(12, 16), Pair(20, 2), Pair(29, 11),
        Pair(1, 6), Pair(5, -1), Pair(1, 18), Pair(2, 19), Pair(7, 19), Pair(8, 7), Pair(13, -2), Pair(-5, 22),
        Pair(-21, -38), Pair(-39, 6), Pair(-13, 27), Pair(0, 9), Pair(0, 5), Pair(-21, 1), Pair(17, -11), Pair(2, -4),
        Pair(-100, 61), Pair(-11, 10), Pair(-14, 39), Pair(-26, 20), Pair(-5, 10), Pair(-8, -6), Pair(-13, 17), Pair(-67, 17)
      },
      { // Piece 2
        Pair(33, -54), Pair(-35, -16), Pair(-22, -28), Pair(25, -11), Pair(22, -25), Pair(-27, -5), Pair(-39, 19), Pair(-18, -13),
        Pair(15, -43), Pair(36, -33), Pair(0, -13), Pair(16, -13), Pair(17, -7), Pair(2, -20), Pair(-11, 27), Pair(44, -34),
        Pair(3, -5), Pair(13, -14), Pair(9, -16), Pair(4, 0), Pair(38, -18), Pair(31, -2), Pair(10, 3), Pair(24, -24),
        Pair(-17, 7), Pair(5, 6), Pair(-2, -11), Pair(5, -6), Pair(8, 5), Pair(0, -1), Pair(13, 30), Pair(25, -18),
        Pair(22, -15), Pair(-2, 4), Pair(6, 2), Pair(5, 8), Pair(17, 5), Pair(2, 13), Pair(15, -7), Pair(0, 24),
        Pair(2, -13), Pair(9, -11), Pair(9, 5), Pair(8, 2), Pair(11, 4), Pair(3, -2), Pair(-1, 14), Pair(-2, -1),
        Pair(7, 6), Pair(-3, 10), Pair(20, -13), Pair(1, 8), Pair(-2, 12), Pair(-10, 2), Pair(9, 2), Pair(0, -1),
        Pair(-8, 28), Pair(-7, 12), Pair(-3, 3), Pair(10, -6), Pair(8, -4), Pair(-6, -1), Pair(15, 1), Pair(19, -13)
      },
      { // Piece 3
        Pair(21, 23), Pair(24, 10), Pair(19, 9), Pair(18, 3), Pair(46, 12), Pair(45, -24), Pair(26, 4), Pair(22, -8),
        Pair(5, 26), Pair(6, 2), Pair(52, -1), Pair(28, 5), Pair(29, 1), Pair(62, -7), Pair(-21, 16), Pair(68, -23),
        Pair(9, 13), Pair(4, 11), Pair(48, 0), Pair(4, 8), Pair(-23, 17), Pair(22, 0), Pair(-3, 3), Pair(32, -11),
        Pair(-11, 21), Pair(-8, 29), Pair(-13, 21), Pair(19, 10), Pair(5, -1), Pair(19, 11), Pair(54, -13), Pair(32, -26),
        Pair(17, 4), Pair(16, 6), Pair(6, 1), Pair(7, -10), Pair(-2, 15), Pair(13, 13), Pair(-5, 11), Pair(-66, -12),
        Pair(-6, 8), Pair(4, 0), Pair(-13, -11), Pair(-26, 26), Pair(1, 0), Pair(-9, 10), Pair(-15, 18), Pair(-17, -11),
        Pair(-28, 44), Pair(-9, 17), Pair(10, 9), Pair(5, 4), Pair(0, 4), Pair(0, 22), Pair(-4, -1), Pair(-47, -18),
        Pair(-3, 3), Pair(0, 15), Pair(-6, 12), Pair(1, 8), Pair(-1, 7), Pair(4, 8), Pair(-18, 5), Pair(-21, -8)
      },
      { // Piece 4
        Pair(36, -14), Pair(38, -50), Pair(24, -29), Pair(9, -23), Pair(63, -32), Pair(-5, -28), Pair(-30, 13), Pair(86, -38),
        Pair(-3, 6), Pair(-36, 5), Pair(1, -10), Pair(12, -13), Pair(6, -14), Pair(-30, 56), Pair(51, -63), Pair(7, -35),
        Pair(30, -23), Pair(-9, 16), Pair(32, -28), Pair(22, -29), Pair(38, -27), Pair(61, -71), Pair(36, -22), Pair(4, -13),
        Pair(-2, -19), Pair(-12, 16), Pair(9, -3), Pair(7, -4), Pair(22, -11), Pair(17, -7), Pair(7, -19), Pair(-23, -3),
        Pair(-7, -24), Pair(-4, 9), Pair(-17, -6), Pair(-5, -1), Pair(-9, 26), Pair(9, -16), Pair(2, -22), Pair(6, 6),
        Pair(20, -17), Pair(2, -29), Pair(4, -23), Pair(-8, 19), Pair(9, -21), Pair(-10, 9), Pair(5, -28), Pair(-41, -25),
        Pair(25, -45), Pair(-5, -13), Pair(-6, 8), Pair(3, 1), Pair(3, -17), Pair(-10, 20), Pair(-1, -7), Pair(-29, -40),
        Pair(12, 1), Pair(-12, 31), Pair(1, 10), Pair(-4, -6), Pair(4, -49), Pair(-2, -45), Pair(-2, 4), Pair(8, -75)
      },
      { // Piece 5
        Pair(-41, 63), Pair(-7, 22), Pair(10, -24), Pair(-78, 93), Pair(35, -11), Pair(-61, 29), Pair(19, 70), Pair(9, 26),
        Pair(-94, 11), Pair(6, 43), Pair(-121, 47), Pair(14, 4), Pair(76, -9), Pair(-79, 42), Pair(-65, 118), Pair(-17, 30),
        Pair(72, 43), Pair(14, 37), Pair(-40, 24), Pair(66, -1), Pair(121, 2), Pair(10, 24), Pair(27, 51), Pair(72, 11),
        Pair(-43, 27), Pair(-56, 1), Pair(-72, 24), Pair(-93, 32), Pair(16, 31), Pair(41, 24), Pair(11, 24), Pair(-33, 18),
        Pair(21, -8), Pair(-25, 30), Pair(-4, 11), Pair(-66, 36), Pair(-34, 23), Pair(-9, 16), Pair(-28, 3), Pair(-57, -9),
        Pair(-74, 9), Pair(-55, 11), Pair(-55, 32), Pair(-34, 10), Pair(-1, 15), Pair(17, 1), Pair(-3, -3), Pair(-28, 1),
        Pair(-46, -25), Pair(-43, 11), Pair(-39, 22), Pair(-33, 18), Pair(-28, 6), Pair(-13, 2), Pair(4, -4), Pair(-2, -18),
        Pair(-39, 8), Pair(-29, -3), Pair(-36, 12), Pair(-42, 0), Pair(-21, -16), Pair(-6, -8), Pair(6, -2), Pair(-2, -30)
      }
    }},
    {{ // Bucket 40
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(42, -27), Pair(-59, 61), Pair(-9, -20), Pair(8, 6), Pair(-60, 34), Pair(-21, 36), Pair(36, -40), Pair(-15, 49),
        Pair(8, 53), Pair(-11, 12), Pair(9, 18), Pair(-31, 2), Pair(-8, -11), Pair(14, -5), Pair(-4, -3), Pair(-16, -2),
        Pair(0, 12), Pair(-8, -2), Pair(-1, 6), Pair(-3, 2), Pair(3, -2), Pair(-2, 11), Pair(-6, 7), Pair(-10, 10),
        Pair(2, -1), Pair(2, 7), Pair(1, 1), Pair(-1, 1), Pair(3, 0), Pair(0, 7), Pair(0, 9), Pair(-1, 7),
        Pair(-7, -4), Pair(-2, 0), Pair(0, 1), Pair(0, 11), Pair(0, 8), Pair(-1, 9), Pair(-1, 8), Pair(-1, 8),
        Pair(4, 18), Pair(-1, 7), Pair(-1, 3), Pair(6, 17), Pair(-1, 11), Pair(0, 17), Pair(3, 12), Pair(-1, 10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(3, 0), Pair(-83, 31), Pair(-59, 23), Pair(-83, 24), Pair(-8, 45), Pair(32, -24), Pair(-64, 62), Pair(8, 97),
        Pair(15, 9), Pair(8, 28), Pair(-7, 22), Pair(17, 30), Pair(4, -15), Pair(-26, 25), Pair(-78, 5), Pair(-51, -21),
        Pair(17, 13), Pair(2, 25), Pair(-22, 30), Pair(-16, 33), Pair(12, -1), Pair(-25, 46), Pair(1, 19), Pair(6, 8),
        Pair(-15, -10), Pair(3, 10), Pair(11, -1), Pair(4, 16), Pair(-2, 18), Pair(0, 24), Pair(1, 10), Pair(-11, 30),
        Pair(-6, 6), Pair(9, 10), Pair(6, 25), Pair(4, 11), Pair(-7, 16), Pair(-4, 11), Pair(14, 13), Pair(-2, -4),
        Pair(56, 1), Pair(-3, 13), Pair(0, 11), Pair(-2, 13), Pair(14, 13), Pair(2, 9), Pair(2, 14), Pair(4, 18),
        Pair(29, 31), Pair(13, -19), Pair(2, 14), Pair(-5, 21), Pair(0, 16), Pair(-11, 19), Pair(-17, 22), Pair(2, 17),
        Pair(72, -31), Pair(-11, -2), Pair(12, 2), Pair(8, 13), Pair(-11, 20), Pair(-7, 17), Pair(-3, -1), Pair(55, -81)
      },
      { // Piece 2
        Pair(67, 26), Pair(-48, 29), Pair(-34, 16), Pair(49, -24), Pair(2, -26), Pair(55, -12), Pair(-59, 33), Pair(-58, 6),
        Pair(24, -20), Pair(8, 20), Pair(-21, 4), Pair(44, -43), Pair(-34, -15), Pair(44, -6), Pair(-11, -20), Pair(-10, 1),
        Pair(18, -8), Pair(-8, 4), Pair(16, 5), Pair(-13, -8), Pair(3, -15), Pair(-18, -5), Pair(-17, 0), Pair(0, -10),
        Pair(2, 2), Pair(12, 10), Pair(9, -13), Pair(9, -4), Pair(0, -20), Pair(17, 0), Pair(2, -20), Pair(4, 1),
        Pair(-12, -7), Pair(6, 7), Pair(6, 2), Pair(2, -5), Pair(0, 9), Pair(-5, 4), Pair(7, 5), Pair(-1, 5),
        Pair(46, -5), Pair(-2, 4), Pair(12, -3), Pair(2, 8), Pair(-2, 6), Pair(9, 9), Pair(4, -4), Pair(1, 11),
        Pair(6, -22), Pair(3, -7), Pair(-16, 11), Pair(2, 8), Pair(4, 22), Pair(1, 6), Pair(6, 13), Pair(-1, 21),
        Pair(8, -37), Pair(-2, -23), Pair(-7, -2), Pair(2, 17), Pair(12, 1), Pair(-7, 9), Pair(-2, 5), Pair(15, -1)
      },
      { // Piece 3
        Pair(-31, 0), Pair(-21, 40), Pair(-34, 24), Pair(-39, 30), Pair(4, 23), Pair(25, 0), Pair(-53, 45), Pair(-55, 37),
        Pair(4, -22), Pair(-8, 28), Pair(-8, 11), Pair(-16, 16), Pair(-6, 2), Pair(-41, 27), Pair(10, -16), Pair(4, 24),
        Pair(-25, 3), Pair(22, 6), Pair(-21, 27), Pair(30, 3), Pair(12, 19), Pair(6, 2), Pair(-10, 27), Pair(8, 9),
        Pair(-37, 12), Pair(3, 20), Pair(6, 15), Pair(-11, 34), Pair(11, 6), Pair(13, 11), Pair(-1, 16), Pair(-13, 29),
        Pair(-21, 18), Pair(-2, 19), Pair(-15, 50), Pair(1, 20), Pair(9, -11), Pair(-27, 22), Pair(-38, 36), Pair(-18, 11),
        Pair(27, -9), Pair(-3, 14), Pair(17, 19), Pair(14, -1), Pair(7, 6), Pair(4, 11), Pair(20, -5), Pair(8, 10),
        Pair(-25, 1), Pair(9, 6), Pair(-8, 9), Pair(11, 17), Pair(6, 12), Pair(-8, 20), Pair(7, 11), Pair(-1, -11),
        Pair(-7, -15), Pair(-1, 19), Pair(0, 18), Pair(2, 14), Pair(5, 11), Pair(0, 9), Pair(13, 8), Pair(6, 6)
      },
      { // Piece 4
        Pair(-13, -70), Pair(28, 35), Pair(-33, 10), Pair(-17, -9), Pair(-27, 29), Pair(58, -61), Pair(-49, 56), Pair(-68, 65),
        Pair(-25, -23), Pair(-34, 46), Pair(-15, 29), Pair(-7, 27), Pair(4, 29), Pair(-47, -8), Pair(-5, 13), Pair(35, -44),
        Pair(-25, 45), Pair(-12, 13), Pair(-31, 73), Pair(-17, 43), Pair(-17, -3), Pair(-17, 39), Pair(-6, -4), Pair(-7, 5),
        Pair(1, -20), Pair(-5, 23), Pair(-2, 25), Pair(1, -13), Pair(1, 0), Pair(-21, -14), Pair(1, -4), Pair(6, -13),
        Pair(-9, -17), Pair(9, 6), Pair(-6, 12), Pair(3, 1), Pair(-1, 12), Pair(0, 7), Pair(6, 1), Pair(6, -18),
        Pair(-17, 63), Pair(9, -2), Pair(7, 3), Pair(-4, 19), Pair(-2, 39), Pair(-2, 28), Pair(15, 5), Pair(-4, -31),
        Pair(3, 34), Pair(5, 3), Pair(6, 2), Pair(4, 21), Pair(0, 19), Pair(23, -21), Pair(10, -6), Pair(0, 42),
        Pair(-10, 19), Pair(-6, 54), Pair(5, 18), Pair(0, 13), Pair(-3, 9), Pair(10, -45), Pair(13, -68), Pair(34, -31)
      },
      { // Piece 5
        Pair(49, -1), Pair(20, 13), Pair(27, 64), Pair(-25, -92), Pair(-14, -8), Pair(-85, -28), Pair(-8, 41), Pair(-44, -56),
        Pair(-59, -46), Pair(2, 135), Pair(3, 61), Pair(-19, 5), Pair(30, -9), Pair(-71, 15), Pair(-16, 10), Pair(0, -9),
        Pair(0, 31), Pair(87, 68), Pair(22, 65), Pair(-18, 18), Pair(-44, 31), Pair(88, -7), Pair(67, 7), Pair(-5, 1),
        Pair(35, 23), Pair(12, 66), Pair(-28, 52), Pair(94, 7), Pair(-69, 31), Pair(-26, 14), Pair(-75, 14), Pair(-21, -7),
        Pair(-57, 38), Pair(29, 48), Pair(25, 25), Pair(-13, 52), Pair(-52, 24), Pair(-48, 18), Pair(-9, 6), Pair(-63, 29),
        Pair(85, 130), Pair(1, 31), Pair(1, 23), Pair(-19, 26), Pair(-43, 24), Pair(0, 12), Pair(-12, 4), Pair(-6, -11),
        Pair(9, -14), Pair(30, -11), Pair(-29, 21), Pair(-12, 8), Pair(-4, 20), Pair(-15, 20), Pair(-14, 3), Pair(-12, -7),
        Pair(35, -56), Pair(73, -4), Pair(41, 1), Pair(17, 0), Pair(1, -4), Pair(-21, 6), Pair(-8, -2), Pair(-7, -14)
      }
    }},
    {{ // Bucket 41
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-11, 32), Pair(24, -45), Pair(2, -8), Pair(45, -3), Pair(-17, 39), Pair(1, -31), Pair(-77, 34), Pair(-139, 15),
        Pair(-13, 16), Pair(28, 17), Pair(-25, 30), Pair(14, -10), Pair(-20, 8), Pair(20, 4), Pair(-2, -20), Pair(-10, -11),
        Pair(-10, 11), Pair(12, 18), Pair(-4, 6), Pair(6, 4), Pair(-1, -3), Pair(-1, 9), Pair(-2, 1), Pair(2, 2),
        Pair(-5, 0), Pair(-10, 5), Pair(2, 1), Pair(2, -1), Pair(1, 8), Pair(1, 6), Pair(-1, 6), Pair(0, 6),
        Pair(-2, -2), Pair(-3, -2), Pair(-1, 6), Pair(0, 4), Pair(0, 10), Pair(0, 10), Pair(1, 8), Pair(1, 5),
        Pair(1, 7), Pair(7, 8), Pair(4, 11), Pair(2, 7), Pair(-2, 14), Pair(0, 11), Pair(-2, 12), Pair(1, 7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-27, 19), Pair(-103, 5), Pair(11, 25), Pair(-43, -25), Pair(-34, 29), Pair(-15, 9), Pair(-97, 42), Pair(-54, 78),
        Pair(-12, 20), Pair(19, -8), Pair(-25, 37), Pair(11, 4), Pair(-21, -12), Pair(16, 39), Pair(-11, 66), Pair(38, -16),
        Pair(-62, 25), Pair(-16, -1), Pair(3, 17), Pair(-18, 22), Pair(-19, 22), Pair(-41, 35), Pair(-20, 26), Pair(-56, 36),
        Pair(-6, 28), Pair(1, -1), Pair(12, 0), Pair(3, 24), Pair(3, 24), Pair(-8, 23), Pair(-4, 14), Pair(3, 46),
        Pair(-7, 21), Pair(4, 25), Pair(-2, 26), Pair(2, 24), Pair(-9, 19), Pair(2, 26), Pair(-5, 22), Pair(-8, 29),
        Pair(-5, 14), Pair(35, 53), Pair(1, 8), Pair(2, 27), Pair(4, 13), Pair(0, 17), Pair(-3, 18), Pair(8, 18),
        Pair(-15, 30), Pair(22, 23), Pair(-1, 22), Pair(-2, 21), Pair(-4, 23), Pair(-4, 37), Pair(-7, 45), Pair(8, 13),
        Pair(-12, -73), Pair(-5, -18), Pair(-22, 52), Pair(-5, 10), Pair(-4, 23), Pair(2, 20), Pair(0, -15), Pair(94, -40)
      },
      { // Piece 2
        Pair(33, -39), Pair(-123, 62), Pair(6, -13), Pair(49, 4), Pair(32, -33), Pair(-39, -21), Pair(-72, 13), Pair(-69, -10),
        Pair(38, 1), Pair(-5, -10), Pair(-36, 16), Pair(-36, -27), Pair(20, -12), Pair(-1, 12), Pair(-27, -32), Pair(-50, 12),
        Pair(-22, 24), Pair(33, 3), Pair(9, -24), Pair(8, 4), Pair(-12, -8), Pair(-13, -4), Pair(-12, 24), Pair(-1, 3),
        Pair(-4, 17), Pair(-15, 3), Pair(-13, 7), Pair(-23, -8), Pair(14, -5), Pair(-5, -16), Pair(2, 8), Pair(-7, 23),
        Pair(-17, -7), Pair(5, 11), Pair(-1, 5), Pair(7, -3), Pair(-17, -7), Pair(2, 4), Pair(6, -7), Pair(-4, 41),
        Pair(1, -4), Pair(23, 38), Pair(2, -1), Pair(-5, 15), Pair(2, 11), Pair(7, -3), Pair(8, 21), Pair(1, 8),
        Pair(-38, 26), Pair(9, 17), Pair(1, -3), Pair(2, 20), Pair(-3, 14), Pair(17, 4), Pair(-5, 9), Pair(0, 49),
        Pair(14, -32), Pair(-7, -28), Pair(3, 2), Pair(8, -20), Pair(33, -18), Pair(1, 3), Pair(-20, -16), Pair(1, 10)
      },
      { // Piece 3
        Pair(-2, 23), Pair(-15, -1), Pair(-51, 32), Pair(-5, 13), Pair(-40, 14), Pair(38, 10), Pair(18, -13), Pair(-13, 17),
        Pair(-4, 7), Pair(-18, -1), Pair(-6, 19), Pair(21, 18), Pair(-37, 28), Pair(-57, 13), Pair(-44, 29), Pair(8, 5),
        Pair(1, 13), Pair(-1, 8), Pair(10, 14), Pair(-7, 12), Pair(-2, 24), Pair(-42, 43), Pair(24, -9), Pair(28, -8),
        Pair(-13, 24), Pair(-3, 25), Pair(-13, 26), Pair(-14, 14), Pair(-3, 19), Pair(-17, 28), Pair(-16, 4), Pair(-13, 24),
        Pair(-16, 19), Pair(-36, 26), Pair(4, 15), Pair(9, 14), Pair(-7, 22), Pair(-5, 12), Pair(25, 2), Pair(-23, 11),
        Pair(3, -6), Pair(-23, 33), Pair(-8, 23), Pair(7, 16), Pair(6, 14), Pair(-14, 31), Pair(2, -5), Pair(-18, 10),
        Pair(-14, 1), Pair(-21, 3), Pair(-2, 10), Pair(-1, 15), Pair(-2, 23), Pair(-7, 15), Pair(18, 7), Pair(-20, 20),
        Pair(-4, 8), Pair(-4, -10), Pair(0, 5), Pair(2, 9), Pair(0, 7), Pair(-1, 10), Pair(4, 0), Pair(7, 6)
      },
      { // Piece 4
        Pair(-36, 10), Pair(-60, 52), Pair(24, 17), Pair(6, -23), Pair(23, -24), Pair(28, 7), Pair(29, -62), Pair(24, 28),
        Pair(11, -25), Pair(-15, 3), Pair(-10, -27), Pair(-56, 21), Pair(-27, 11), Pair(13, 7), Pair(27, -47), Pair(23, 46),
        Pair(-23, 2), Pair(-22, 5), Pair(-23, 29), Pair(10, 6), Pair(10, -9), Pair(-26, 8), Pair(0, -13), Pair(-10, -27),
        Pair(-12, 4), Pair(7, -10), Pair(8, 34), Pair(-25, 12), Pair(2, 8), Pair(-6, -15), Pair(-28, -20), Pair(-6, 6),
        Pair(-22, 29), Pair(-21, -6), Pair(-3, -4), Pair(-11, 28), Pair(5, -20), Pair(-8, 30), Pair(2, -2), Pair(-10, 0),
        Pair(-13, -44), Pair(3, 26), Pair(1, 20), Pair(-12, 19), Pair(3, 13), Pair(-9, 3), Pair(-2, 18), Pair(8, -80),
        Pair(-36, 18), Pair(4, -10), Pair(0, -1), Pair(4, 1), Pair(4, 5), Pair(1, -3), Pair(-4, 37), Pair(16, -11),
        Pair(-11, 21), Pair(13, -9), Pair(3, -19), Pair(-1, 2), Pair(5, 11), Pair(15, 9), Pair(-1, -19), Pair(42, -11)
      },
      { // Piece 5
        Pair(-25, 31), Pair(63, 118), Pair(51, 124), Pair(-35, -1), Pair(-4, -76), Pair(-15, 14), Pair(-68, -28), Pair(9, -34),
        Pair(44, 62), Pair(186, 72), Pair(-4, 58), Pair(104, 90), Pair(13, 59), Pair(-11, 11), Pair(-52, 4), Pair(-101, -5),
        Pair(30, 63), Pair(39, 36), Pair(30, 59), Pair(62, 47), Pair(12, 15), Pair(32, 10), Pair(14, 25), Pair(-149, 26),
        Pair(50, 68), Pair(22, 49), Pair(106, 55), Pair(140, 33), Pair(-34, 27), Pair(-4, 33), Pair(5, -2), Pair(-63, 7),
        Pair(116, 18), Pair(26, 39), Pair(24, 32), Pair(-45, 37), Pair(-15, 24), Pair(-39, 26), Pair(-22, 11), Pair(-49, 7),
        Pair(-52, 35), Pair(15, 78), Pair(23, 18), Pair(-16, 23), Pair(7, 14), Pair(-7, 16), Pair(-10, 11), Pair(-36, 14),
        Pair(78, -15), Pair(27, -5), Pair(5, 12), Pair(8, 5), Pair(-2, 16), Pair(-16, 17), Pair(-13, 10), Pair(-9, 1),
        Pair(85, -24), Pair(42, -6), Pair(44, -5), Pair(7, 0), Pair(0, 5), Pair(-13, 5), Pair(-1, -2), Pair(-1, -1)
      }
    }},
    {{ // Bucket 42
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(17, 4), Pair(12, -39), Pair(-133, 27), Pair(72, 0), Pair(-5, -11), Pair(30, -19), Pair(-15, -55), Pair(66, 10),
        Pair(-1, -1), Pair(-44, 35), Pair(4, 16), Pair(-30, 0), Pair(22, -1), Pair(15, -1), Pair(5, 7), Pair(2, 5),
        Pair(-6, 4), Pair(-7, 7), Pair(10, 3), Pair(-17, 6), Pair(7, 13), Pair(5, 11), Pair(-7, 3), Pair(-2, 10),
        Pair(2, 1), Pair(3, 10), Pair(-6, -3), Pair(6, 10), Pair(3, 0), Pair(5, 5), Pair(5, 6), Pair(-1, 10),
        Pair(1, 2), Pair(-1, 7), Pair(-4, -5), Pair(-2, 13), Pair(-4, 1), Pair(4, 3), Pair(1, 10), Pair(0, 5),
        Pair(0, 3), Pair(4, 17), Pair(2, -4), Pair(-1, 11), Pair(-7, 13), Pair(0, 11), Pair(1, 11), Pair(0, 9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-1, 7), Pair(-33, 45), Pair(-61, 30), Pair(-113, 42), Pair(55, 22), Pair(-57, 74), Pair(-28, 54), Pair(24, 14),
        Pair(9, -1), Pair(13, 26), Pair(-31, 17), Pair(2, -6), Pair(-60, -16), Pair(16, 0), Pair(-34, 13), Pair(-92, 61),
        Pair(34, 9), Pair(-3, 37), Pair(5, 38), Pair(2, 36), Pair(-23, 46), Pair(-11, 44), Pair(6, 6), Pair(20, 47),
        Pair(1, 24), Pair(1, 28), Pair(-5, 17), Pair(8, 13), Pair(10, 12), Pair(-4, 10), Pair(-11, 13), Pair(18, -19),
        Pair(-9, 26), Pair(10, 27), Pair(-2, 27), Pair(0, 21), Pair(-4, 29), Pair(-5, 29), Pair(4, 27), Pair(-4, 3),
        Pair(4, 27), Pair(-4, 38), Pair(14, 5), Pair(5, 21), Pair(0, 28), Pair(3, 13), Pair(3, 34), Pair(0, 1),
        Pair(10, -31), Pair(9, 48), Pair(10, 43), Pair(4, 29), Pair(3, 14), Pair(5, 19), Pair(-3, 43), Pair(1, -9),
        Pair(96, 0), Pair(0, -14), Pair(0, 19), Pair(-7, 31), Pair(-9, 16), Pair(-2, 36), Pair(3, 19), Pair(95, -13)
      },
      { // Piece 2
        Pair(-18, -19), Pair(82, -48), Pair(165, -63), Pair(55, 5), Pair(26, -19), Pair(35, -18), Pair(79, -60), Pair(36, -22),
        Pair(23, -5), Pair(7, -13), Pair(65, -12), Pair(-14, -13), Pair(-2, 2), Pair(-4, 25), Pair(8, -24), Pair(11, -22),
        Pair(18, 5), Pair(11, 12), Pair(17, 0), Pair(27, -11), Pair(15, -11), Pair(-12, -15), Pair(33, -20), Pair(-30, -1),
        Pair(-41, 48), Pair(8, -1), Pair(7, -8), Pair(-11, -2), Pair(0, -4), Pair(15, -18), Pair(7, -4), Pair(14, 4),
        Pair(23, 12), Pair(-11, 1), Pair(1, 8), Pair(13, 2), Pair(-13, 10), Pair(8, -3), Pair(21, 16), Pair(15, -10),
        Pair(-6, -10), Pair(8, 11), Pair(-1, 44), Pair(12, -11), Pair(2, 11), Pair(18, -2), Pair(13, -11), Pair(10, 6),
        Pair(20, -49), Pair(-19, -43), Pair(18, 26), Pair(-2, 9), Pair(9, 8), Pair(11, -8), Pair(11, 11), Pair(7, 26),
        Pair(-25, -62), Pair(-9, -39), Pair(-4, -6), Pair(7, 12), Pair(-11, -10), Pair(8, 15), Pair(-21, 30), Pair(-15, -8)
      },
      { // Piece 3
        Pair(9, 7), Pair(-54, 45), Pair(-53, 23), Pair(-32, 21), Pair(2, 23), Pair(10, 10), Pair(-37, 29), Pair(-7, -9),
        Pair(18, 9), Pair(6, 2), Pair(-5, -14), Pair(6, 5), Pair(-20, 14), Pair(66, -13), Pair(12, -12), Pair(24, 18),
        Pair(-12, 19), Pair(-2, 16), Pair(-1, -3), Pair(5, 8), Pair(45, -4), Pair(-22, 20), Pair(-23, 26), Pair(-19, -3),
        Pair(-2, 26), Pair(-23, 17), Pair(16, 1), Pair(-22, 15), Pair(4, 8), Pair(-19, 19), Pair(-23, 18), Pair(3, 11),
        Pair(19, 14), Pair(3, -1), Pair(-31, 13), Pair(-17, 26), Pair(-9, 34), Pair(3, -14), Pair(0, 4), Pair(10, 15),
        Pair(-12, 17), Pair(-19, -1), Pair(-47, 47), Pair(16, -11), Pair(16, -4), Pair(13, -2), Pair(8, 6), Pair(-8, 5),
        Pair(-16, 14), Pair(-8, 27), Pair(-16, 6), Pair(-8, 30), Pair(8, 22), Pair(23, -17), Pair(-20, 54), Pair(36, 5),
        Pair(-3, 15), Pair(-2, 12), Pair(-1, -3), Pair(-2, 16), Pair(3, 16), Pair(1, 3), Pair(6, 13), Pair(4, 19)
      },
      { // Piece 4
        Pair(-1, 62), Pair(-37, 57), Pair(-64, 52), Pair(-79, 44), Pair(-4, 23), Pair(-22, 9), Pair(25, -9), Pair(81, -57),
        Pair(-21, 51), Pair(3, 14), Pair(-15, -19), Pair(9, -13), Pair(22, -58), Pair(23, 3), Pair(-24, -11), Pair(47, -71),
        Pair(-2, 9), Pair(-26, 36), Pair(10, 14), Pair(9, 46), Pair(-36, 46), Pair(-43, 39), Pair(17, -17), Pair(-7, 26),
        Pair(12, -24), Pair(2, -29), Pair(-5, 29), Pair(-23, -6), Pair(-7, 30), Pair(-1, -21), Pair(-19, 16), Pair(-16, 22),
        Pair(-9, 25), Pair(13, -8), Pair(-5, 41), Pair(-4, 1), Pair(-18, 12), Pair(2, -3), Pair(0, 3), Pair(-27, 2),
        Pair(-10, -26), Pair(2, -12), Pair(-9, -20), Pair(5, 11), Pair(3, 27), Pair(-3, 16), Pair(1, 18), Pair(-34, 48),
        Pair(6, -13), Pair(-2, 11), Pair(0, 17), Pair(7, -7), Pair(0, 28), Pair(7, 4), Pair(14, 6), Pair(1, -25),
        Pair(31, -60), Pair(2, -55), Pair(-3, -2), Pair(1, 11), Pair(17, 4), Pair(6, 13), Pair(30, 34), Pair(37, 50)
      },
      { // Piece 5
        Pair(16, 21), Pair(22, 132), Pair(17, 28), Pair(-88, 9), Pair(33, 73), Pair(-11, 9), Pair(16, -53), Pair(-4, -50),
        Pair(18, 46), Pair(186, 68), Pair(26, -16), Pair(15, 96), Pair(-43, 126), Pair(-10, 56), Pair(46, 39), Pair(-14, -62),
        Pair(20, 134), Pair(87, 102), Pair(-19, 44), Pair(78, 73), Pair(173, -14), Pair(33, 27), Pair(20, -67), Pair(75, 32),
        Pair(6, 19), Pair(62, 65), Pair(66, 59), Pair(-54, 81), Pair(87, -2), Pair(-23, 55), Pair(-7, 11), Pair(-34, 4),
        Pair(-15, 31), Pair(53, 27), Pair(24, 29), Pair(-60, 41), Pair(-31, 33), Pair(3, 9), Pair(38, 1), Pair(-62, 38),
        Pair(26, 42), Pair(27, 12), Pair(14, 9), Pair(-7, 28), Pair(6, 16), Pair(-22, 9), Pair(8, 2), Pair(-11, 1),
        Pair(33, -7), Pair(14, -6), Pair(-12, 14), Pair(-17, 20), Pair(-19, 14), Pair(5, 1), Pair(-4, -2), Pair(-11, 1),
        Pair(28, -8), Pair(-5, -7), Pair(-5, -23), Pair(21, -6), Pair(-1, 9), Pair(10, -11), Pair(-1, -8), Pair(-9, -9)
      }
    }},
    {{ // Bucket 43
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-19, 8), Pair(-26, 12), Pair(-18, 39), Pair(-45, 23), Pair(-45, 72), Pair(12, -23), Pair(21, -35), Pair(-18, 9),
        Pair(-3, 8), Pair(-27, 19), Pair(-21, 11), Pair(6, -2), Pair(-16, 0), Pair(-16, 11), Pair(-18, 17), Pair(-32, 19),
        Pair(-1, 0), Pair(-1, 6), Pair(0, 13), Pair(13, -1), Pair(-7, 12), Pair(7, 11), Pair(4, 13), Pair(-5, 17),
        Pair(-4, 5), Pair(2, -2), Pair(1, 7), Pair(-3, -16), Pair(6, 4), Pair(3, 0), Pair(3, 6), Pair(0, 4),
        Pair(0, 8), Pair(0, 5), Pair(-2, 10), Pair(-4, -10), Pair(0, 7), Pair(-11, 8), Pair(1, 8), Pair(0, 6),
        Pair(1, 2), Pair(-3, 5), Pair(4, 13), Pair(3, -19), Pair(3, 30), Pair(-5, 9), Pair(2, 5), Pair(0, 4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(63, -70), Pair(80, 56), Pair(107, 3), Pair(-2, 8), Pair(10, -24), Pair(107, -9), Pair(-116, 76), Pair(-28, 72),
        Pair(11, -1), Pair(34, -11), Pair(24, -13), Pair(-35, 24), Pair(-25, 4), Pair(-25, 44), Pair(-74, 44), Pair(47, -30),
        Pair(-31, 27), Pair(15, -2), Pair(23, 41), Pair(-9, 25), Pair(-29, 49), Pair(-25, 58), Pair(-22, 20), Pair(-41, 50),
        Pair(12, -14), Pair(-3, -4), Pair(1, 7), Pair(-10, 31), Pair(2, 19), Pair(-1, 28), Pair(-2, 59), Pair(-8, -5),
        Pair(-12, -32), Pair(9, 7), Pair(0, 21), Pair(5, 23), Pair(10, 22), Pair(-9, 20), Pair(-12, 22), Pair(-1, 15),
        Pair(2, 15), Pair(15, 5), Pair(-2, 18), Pair(26, 12), Pair(5, 2), Pair(7, 19), Pair(-5, 34), Pair(12, 8),
        Pair(15, -85), Pair(-14, 15), Pair(5, -4), Pair(9, 39), Pair(0, 24), Pair(-6, 7), Pair(7, 27), Pair(4, 9),
        Pair(-39, 49), Pair(5, 11), Pair(21, 0), Pair(3, 4), Pair(10, 10), Pair(-13, 21), Pair(-12, 18), Pair(4, -46)
      },
      { // Piece 2
        Pair(-13, -22), Pair(108, 6), Pair(6, -14), Pair(-144, -1), Pair(59, -59), Pair(-2, 29), Pair(-141, 11), Pair(36, -116),
        Pair(31, 14), Pair(14, -5), Pair(27, 5), Pair(14, -21), Pair(29, -22), Pair(45, -51), Pair(-36, 6), Pair(33, -11),
        Pair(47, -7), Pair(17, -39), Pair(0, 20), Pair(7, 3), Pair(24, -1), Pair(-25, 16), Pair(28, -22), Pair(-5, 20),
        Pair(12, 14), Pair(-11, -19), Pair(-20, -14), Pair(-9, -5), Pair(-1, 10), Pair(-7, -11), Pair(-5, -1), Pair(5, -5),
        Pair(-3, -14), Pair(10, -3), Pair(-5, -8), Pair(-7, 2), Pair(20, 28), Pair(6, 6), Pair(-2, -19), Pair(18, 16),
        Pair(11, 1), Pair(12, -6), Pair(8, -12), Pair(42, 5), Pair(3, 7), Pair(1, -8), Pair(9, 24), Pair(6, -5),
        Pair(-1, -15), Pair(-4, 6), Pair(-29, -15), Pair(14, 14), Pair(0, -16), Pair(0, 4), Pair(4, 7), Pair(2, -21),
        Pair(0, 16), Pair(-60, 22), Pair(4, 5), Pair(-6, -2), Pair(-16, 22), Pair(-5, -15), Pair(-13, -33), Pair(26, -13)
      },
      { // Piece 3
        Pair(4, 26), Pair(-3, -3), Pair(1, 7), Pair(75, -24), Pair(28, 8), Pair(-5, 4), Pair(51, 3), Pair(-32, 28),
        Pair(8, 14), Pair(-2, 7), Pair(-5, 5), Pair(-69, 5), Pair(31, 6), Pair(24, -14), Pair(20, 1), Pair(-13, -5),
        Pair(3, 28), Pair(20, 4), Pair(-28, 31), Pair(10, -3), Pair(-16, 16), Pair(-18, 20), Pair(19, 16), Pair(-51, 23),
        Pair(-4, 35), Pair(16, 6), Pair(-18, 20), Pair(24, -18), Pair(-14, 25), Pair(2, 23), Pair(-34, 14), Pair(30, 4),
        Pair(5, 1), Pair(-2, 0), Pair(5, 20), Pair(4, 21), Pair(-17, 41), Pair(-33, 14), Pair(-28, 41), Pair(7, 18),
        Pair(19, -18), Pair(8, 15), Pair(-17, 2), Pair(36, 1), Pair(-3, -19), Pair(-3, 4), Pair(8, 4), Pair(26, 12),
        Pair(4, -3), Pair(0, 23), Pair(11, 12), Pair(-4, -1), Pair(1, 6), Pair(-5, 7), Pair(-9, 1), Pair(25, -17),
        Pair(0, 2), Pair(2, 11), Pair(-3, 15), Pair(2, -13), Pair(-3, 13), Pair(-1, 15), Pair(-2, 2), Pair(4, 5)
      },
      { // Piece 4
        Pair(21, 31), Pair(-54, 21), Pair(-38, 4), Pair(5, 36), Pair(-55, 92), Pair(-17, -5), Pair(89, -8), Pair(-67, -54),
        Pair(-24, -10), Pair(-16, 31), Pair(6, -7), Pair(-15, -29), Pair(-20, 25), Pair(-29, 58), Pair(-24, 22), Pair(0, 12),
        Pair(-22, 4), Pair(-19, 23), Pair(3, 35), Pair(-32, 19), Pair(12, 27), Pair(-10, -9), Pair(-8, 56), Pair(-23, 14),
        Pair(-9, 23), Pair(-7, -4), Pair(-8, 41), Pair(-10, 12), Pair(-10, 32), Pair(-31, 60), Pair(-4, 0), Pair(-4, 14),
        Pair(10, -4), Pair(15, -34), Pair(11, 6), Pair(21, -1), Pair(11, 9), Pair(-18, 39), Pair(-7, 19), Pair(-13, 29),
        Pair(-17, 11), Pair(2, 2), Pair(-7, 20), Pair(21, -7), Pair(2, 21), Pair(3, 27), Pair(-3, 0), Pair(2, 8),
        Pair(-2, 16), Pair(5, -3), Pair(0, 19), Pair(4, -9), Pair(-8, 25), Pair(8, 6), Pair(3, 33), Pair(54, -85),
        Pair(-2, 17), Pair(0, -6), Pair(6, -32), Pair(1, -10), Pair(6, 0), Pair(9, 24), Pair(62, -65), Pair(0, 21)
      },
      { // Piece 5
        Pair(9, 37), Pair(36, 181), Pair(13, -18), Pair(68, 35), Pair(2, 17), Pair(-1, -4), Pair(8, -26), Pair(11, -40),
        Pair(2, 110), Pair(-51, 101), Pair(20, 75), Pair(-69, 78), Pair(-31, 92), Pair(-11, 100), Pair(74, 30), Pair(-32, 32),
        Pair(-23, 109), Pair(28, 54), Pair(74, 114), Pair(28, 61), Pair(109, 73), Pair(93, 8), Pair(-69, 32), Pair(71, 37),
        Pair(-38, 109), Pair(84, 13), Pair(4, 65), Pair(50, 74), Pair(124, 35), Pair(4, 30), Pair(-54, 3), Pair(-40, -8),
        Pair(73, -44), Pair(6, 34), Pair(100, 21), Pair(42, 30), Pair(18, 19), Pair(39, -2), Pair(29, -2), Pair(-49, 9),
        Pair(-6, 52), Pair(37, 5), Pair(-53, 43), Pair(-31, 43), Pair(6, 24), Pair(12, 9), Pair(-14, 2), Pair(6, -4),
        Pair(-14, 18), Pair(-7, 4), Pair(-46, 4), Pair(-12, 11), Pair(-15, 1), Pair(4, -12), Pair(-3, 2), Pair(-1, -9),
        Pair(-29, 15), Pair(-9, -4), Pair(-27, 6), Pair(-46, -8), Pair(-3, -13), Pair(-2, -15), Pair(2, -11), Pair(10, -16)
      }
    }},
    {{ // Bucket 44
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-32, -16), Pair(-5, 18), Pair(25, -26), Pair(-82, -25), Pair(-27, -15), Pair(-98, 8), Pair(-29, 10), Pair(-51, 11),
        Pair(-14, -3), Pair(-16, -6), Pair(13, -24), Pair(1, -30), Pair(25, -1), Pair(4, 7), Pair(0, -10), Pair(-27, 18),
        Pair(-1, 6), Pair(5, 4), Pair(7, 6), Pair(-10, 9), Pair(10, 11), Pair(-19, 25), Pair(-1, 15), Pair(-3, 7),
        Pair(-1, 4), Pair(-1, 9), Pair(2, -1), Pair(5, 11), Pair(4, -9), Pair(11, 6), Pair(5, 2), Pair(3, 3),
        Pair(0, 7), Pair(1, 10), Pair(-5, 1), Pair(0, 9), Pair(-7, -6), Pair(8, 8), Pair(1, 5), Pair(4, 8),
        Pair(-2, 9), Pair(0, 9), Pair(-3, 6), Pair(11, 28), Pair(11, 2), Pair(8, 18), Pair(2, 5), Pair(6, 5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(4, -17), Pair(32, -9), Pair(-42, 37), Pair(-18, 7), Pair(80, 8), Pair(-41, 11), Pair(28, -54), Pair(75, -7),
        Pair(-13, -18), Pair(-2, 14), Pair(4, 49), Pair(-15, 4), Pair(26, -3), Pair(-25, 20), Pair(13, 13), Pair(-46, 1),
        Pair(-8, 18), Pair(0, 23), Pair(11, 24), Pair(11, 15), Pair(-16, 29), Pair(-12, 9), Pair(-17, 4), Pair(-63, 4),
        Pair(-6, 1), Pair(2, 23), Pair(8, 6), Pair(2, 33), Pair(-7, 8), Pair(-11, 23), Pair(-11, 17), Pair(-2, 24),
        Pair(9, 34), Pair(-4, 3), Pair(-2, 13), Pair(12, 17), Pair(-4, 12), Pair(-1, 14), Pair(-8, 33), Pair(-10, -15),
        Pair(16, 19), Pair(0, 23), Pair(6, 19), Pair(3, 10), Pair(33, 19), Pair(2, 22), Pair(8, 20), Pair(1, 20),
        Pair(17, 63), Pair(13, 33), Pair(3, 13), Pair(5, 12), Pair(13, 43), Pair(3, 20), Pair(4, -23), Pair(-7, 20),
        Pair(50, -14), Pair(12, 25), Pair(-16, 32), Pair(-10, 9), Pair(2, 18), Pair(1, -2), Pair(8, 3), Pair(-40, 40)
      },
      { // Piece 2
        Pair(9, -30), Pair(56, -80), Pair(33, -22), Pair(31, -27), Pair(43, 7), Pair(21, 8), Pair(54, -32), Pair(-124, -12),
        Pair(-21, 18), Pair(5, -10), Pair(6, 1), Pair(5, -13), Pair(21, -28), Pair(16, 21), Pair(-23, 1), Pair(-13, -3),
        Pair(6, -13), Pair(-3, -11), Pair(-7, 1), Pair(3, -22), Pair(18, -7), Pair(-30, -20), Pair(-1, 15), Pair(-39, -3),
        Pair(-9, -8), Pair(6, -2), Pair(11, -13), Pair(-9, 8), Pair(-13, 6), Pair(19, -30), Pair(-2, -23), Pair(-3, -15),
        Pair(-1, -12), Pair(-7, 2), Pair(2, 4), Pair(3, 3), Pair(3, 9), Pair(-9, -10), Pair(-15, 8), Pair(3, 1),
        Pair(-9, 0), Pair(6, 10), Pair(-9, 2), Pair(2, 10), Pair(-12, 17), Pair(1, -1), Pair(0, -15), Pair(1, 17),
        Pair(-5, 9), Pair(-6, 5), Pair(5, 15), Pair(-13, -27), Pair(13, 25), Pair(-14, -30), Pair(0, 14), Pair(-3, -2),
        Pair(7, 4), Pair(-3, -16), Pair(-20, -19), Pair(0, 14), Pair(3, -26), Pair(1, -1), Pair(-48, 11), Pair(-12, -35)
      },
      { // Piece 3
        Pair(46, 1), Pair(29, -1), Pair(-36, 34), Pair(-13, 6), Pair(56, -18), Pair(-3, 0), Pair(34, -15), Pair(-69, 23),
        Pair(-1, 14), Pair(-14, 10), Pair(-14, 11), Pair(21, 1), Pair(56, -18), Pair(-24, 32), Pair(-20, 9), Pair(1, 16),
        Pair(-2, 19), Pair(26, 0), Pair(-17, 20), Pair(3, 11), Pair(-35, 5), Pair(-21, 31), Pair(9, 6), Pair(43, 3),
        Pair(1, 8), Pair(15, 4), Pair(12, 13), Pair(-1, 10), Pair(45, -21), Pair(-6, -6), Pair(-19, 21), Pair(11, -2),
        Pair(11, -17), Pair(0, 9), Pair(7, 9), Pair(14, -3), Pair(5, 11), Pair(11, -4), Pair(-12, 15), Pair(-13, 22),
        Pair(-1, 6), Pair(13, -11), Pair(-19, 17), Pair(-9, 24), Pair(-45, -30), Pair(-22, -3), Pair(-9, -4), Pair(-6, 7),
        Pair(5, 2), Pair(-14, 21), Pair(7, 2), Pair(8, -4), Pair(-6, -11), Pair(11, -10), Pair(-25, 11), Pair(-37, 12),
        Pair(2, 10), Pair(3, 6), Pair(2, 7), Pair(2, 2), Pair(3, -19), Pair(-6, 9), Pair(-8, 10), Pair(-2, 7)
      },
      { // Piece 4
        Pair(28, -3), Pair(-45, 39), Pair(24, -16), Pair(-5, -7), Pair(7, -8), Pair(67, -9), Pair(-78, 16), Pair(-72, -1),
        Pair(-29, 13), Pair(-16, 0), Pair(-21, 5), Pair(-19, 2), Pair(-7, 4), Pair(5, 47), Pair(5, -7), Pair(-27, 8),
        Pair(3, -20), Pair(-30, 13), Pair(-22, 34), Pair(-6, 29), Pair(-17, 12), Pair(-12, -37), Pair(-3, 1), Pair(8, 14),
        Pair(8, -6), Pair(13, -22), Pair(-14, -9), Pair(-31, 18), Pair(-13, 1), Pair(-18, 11), Pair(-17, 24), Pair(-19, 5),
        Pair(-1, 41), Pair(7, -22), Pair(-12, -22), Pair(-17, 20), Pair(-19, 8), Pair(-14, 20), Pair(-9, -8), Pair(-22, 29),
        Pair(9, 2), Pair(1, -1), Pair(7, -15), Pair(-5, 7), Pair(-23, 29), Pair(-6, 11), Pair(-26, 26), Pair(10, -48),
        Pair(-2, 39), Pair(10, -13), Pair(1, 8), Pair(-2, 10), Pair(4, -2), Pair(-4, -14), Pair(24, 4), Pair(-5, -40),
        Pair(-12, 5), Pair(1, -2), Pair(-4, -3), Pair(-2, 1), Pair(-3, -6), Pair(-4, 6), Pair(-42, 33), Pair(-1, -48)
      },
      { // Piece 5
        Pair(17, 23), Pair(-15, -41), Pair(-34, 81), Pair(0, 121), Pair(1, -10), Pair(-20, 63), Pair(25, 63), Pair(-3, -34),
        Pair(-11, -10), Pair(-72, 78), Pair(-200, 14), Pair(27, 45), Pair(23, 9), Pair(59, 71), Pair(-11, 8), Pair(22, 39),
        Pair(75, 69), Pair(28, -2), Pair(-32, 51), Pair(120, 17), Pair(89, 64), Pair(73, 40), Pair(56, 10), Pair(-23, -2),
        Pair(5, 10), Pair(-111, 48), Pair(98, 19), Pair(-3, 52), Pair(-46, 34), Pair(49, 34), Pair(-40, 23), Pair(-43, 37),
        Pair(40, -22), Pair(-164, 18), Pair(-91, 6), Pair(52, 27), Pair(13, 25), Pair(34, 13), Pair(30, -13), Pair(11, -2),
        Pair(11, 31), Pair(56, -10), Pair(8, 3), Pair(-66, 35), Pair(91, -24), Pair(-18, 1), Pair(0, -3), Pair(25, -13),
        Pair(1, -35), Pair(-12, -14), Pair(32, -16), Pair(-33, 3), Pair(-33, 18), Pair(-16, 6), Pair(9, -16), Pair(10, -9),
        Pair(-22, -2), Pair(5, -3), Pair(7, -14), Pair(11, -13), Pair(-21, -6), Pair(-8, 1), Pair(4, -7), Pair(8, -23)
      }
    }},
    {{ // Bucket 45
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-13, 3), Pair(-22, 9), Pair(-77, -6), Pair(-2, -31), Pair(-1, -13), Pair(-43, 23), Pair(2, 70), Pair(-11, 5),
        Pair(-3, 4), Pair(-33, 11), Pair(0, -14), Pair(12, -4), Pair(-22, 4), Pair(59, 3), Pair(-25, 29), Pair(-9, 9),
        Pair(2, 3), Pair(0, 4), Pair(-6, 14), Pair(-3, 13), Pair(-22, 9), Pair(18, 7), Pair(-7, 16), Pair(3, 8),
        Pair(1, 3), Pair(-4, 4), Pair(6, 4), Pair(2, 0), Pair(14, 6), Pair(5, 4), Pair(12, 3), Pair(7, 3),
        Pair(0, 7), Pair(0, 10), Pair(4, 3), Pair(-10, 10), Pair(7, 7), Pair(-9, -4), Pair(9, 3), Pair(4, 2),
        Pair(4, 5), Pair(1, 11), Pair(2, 5), Pair(-8, 11), Pair(0, 10), Pair(7, 1), Pair(7, 11), Pair(3, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(15, 82), Pair(36, -7), Pair(-2, 34), Pair(9, 44), Pair(3, 25), Pair(41, 17), Pair(-32, 30), Pair(-100, -2),
        Pair(-45, 40), Pair(-46, -3), Pair(17, -15), Pair(37, -10), Pair(40, -3), Pair(22, 4), Pair(67, -7), Pair(46, 47),
        Pair(37, 17), Pair(-36, 50), Pair(75, -11), Pair(35, 23), Pair(-14, 23), Pair(-23, 27), Pair(12, 16), Pair(32, 1),
        Pair(-13, 5), Pair(10, 16), Pair(30, 17), Pair(22, 15), Pair(24, 9), Pair(9, 22), Pair(26, -1), Pair(-34, 22),
        Pair(-6, 46), Pair(10, 19), Pair(12, 8), Pair(4, 32), Pair(20, 25), Pair(-1, 29), Pair(-2, 9), Pair(-10, 12),
        Pair(-10, 17), Pair(-6, 31), Pair(6, 21), Pair(16, 28), Pair(13, 13), Pair(-59, 111), Pair(-5, 27), Pair(-6, 19),
        Pair(18, 17), Pair(5, -28), Pair(-10, 13), Pair(-11, 31), Pair(16, 9), Pair(27, 20), Pair(14, -10), Pair(0, -9),
        Pair(-63, 11), Pair(-4, 30), Pair(-25, 86), Pair(-1, 25), Pair(3, 0), Pair(6, -13), Pair(-10, -13), Pair(35, 6)
      },
      { // Piece 2
        Pair(-71, 36), Pair(8, -10), Pair(-53, 28), Pair(63, -16), Pair(-75, -10), Pair(16, -9), Pair(1, -23), Pair(-30, 25),
        Pair(-1, -3), Pair(1, -25), Pair(2, -6), Pair(80, -39), Pair(46, -11), Pair(-60, 17), Pair(85, -11), Pair(55, -14),
        Pair(7, -16), Pair(2, -11), Pair(15, -18), Pair(-9, 7), Pair(7, 2), Pair(42, -16), Pair(-29, -14), Pair(-6, 11),
        Pair(31, 8), Pair(4, 2), Pair(24, -13), Pair(19, -6), Pair(31, 6), Pair(-1, -6), Pair(15, -20), Pair(-38, -8),
        Pair(9, 17), Pair(10, 6), Pair(-1, -4), Pair(18, 9), Pair(39, 4), Pair(11, -6), Pair(34, -22), Pair(3, -23),
        Pair(2, 19), Pair(3, 4), Pair(16, 10), Pair(5, -3), Pair(18, 14), Pair(6, -3), Pair(16, -15), Pair(-11, 10),
        Pair(-9, 23), Pair(17, 4), Pair(7, 10), Pair(16, 17), Pair(1, 3), Pair(22, 2), Pair(-25, -9), Pair(28, -15),
        Pair(25, -11), Pair(-18, -9), Pair(4, 21), Pair(10, -9), Pair(13, 3), Pair(-9, 1), Pair(32, -28), Pair(-37, -46)
      },
      { // Piece 3
        Pair(-26, 16), Pair(-28, 28), Pair(3, 5), Pair(26, 10), Pair(2, 34), Pair(60, -11), Pair(5, -2), Pair(82, -14),
        Pair(22, 5), Pair(-3, 20), Pair(20, 12), Pair(57, -6), Pair(12, -6), Pair(81, -31), Pair(60, 13), Pair(7, 11),
        Pair(-2, 19), Pair(41, -7), Pair(5, 15), Pair(40, 4), Pair(-14, 29), Pair(54, 5), Pair(2, 17), Pair(-10, 26),
        Pair(17, 15), Pair(26, 7), Pair(16, 3), Pair(-12, 26), Pair(9, 21), Pair(13, 9), Pair(-8, 11), Pair(15, 19),
        Pair(-9, 17), Pair(-14, 38), Pair(6, 11), Pair(25, 18), Pair(-1, 18), Pair(31, 9), Pair(5, 13), Pair(53, -10),
        Pair(19, -6), Pair(10, 9), Pair(28, -3), Pair(-11, 10), Pair(-6, 3), Pair(89, -89), Pair(2, 21), Pair(29, -32),
        Pair(3, 1), Pair(18, 1), Pair(12, 2), Pair(3, 16), Pair(6, 15), Pair(5, 10), Pair(-4, 14), Pair(-39, -2),
        Pair(4, 12), Pair(3, 9), Pair(7, 13), Pair(3, 12), Pair(2, 1), Pair(5, 2), Pair(-8, 18), Pair(3, 12)
      },
      { // Piece 4
        Pair(-1, -38), Pair(-28, 7), Pair(-27, 1), Pair(-36, 83), Pair(13, 0), Pair(-13, 37), Pair(67, -32), Pair(57, -52),
        Pair(-6, 0), Pair(-21, 30), Pair(14, -14), Pair(-1, 19), Pair(-45, 49), Pair(25, -64), Pair(8, 19), Pair(-5, -29),
        Pair(11, -14), Pair(13, -22), Pair(-1, -28), Pair(-22, 16), Pair(21, 48), Pair(-31, -1), Pair(-12, 67), Pair(5, -25),
        Pair(-24, 19), Pair(-15, 26), Pair(-16, 19), Pair(-11, 4), Pair(-17, 41), Pair(6, -17), Pair(11, -35), Pair(-5, 20),
        Pair(19, 3), Pair(-6, 9), Pair(24, -10), Pair(-8, 27), Pair(22, 2), Pair(-10, 12), Pair(-15, 7), Pair(-40, 48),
        Pair(11, -20), Pair(-1, 17), Pair(15, -18), Pair(-1, -22), Pair(-5, 32), Pair(12, -80), Pair(-1, -41), Pair(-9, 21),
        Pair(-37, 16), Pair(-5, 22), Pair(-2, 2), Pair(2, -6), Pair(-5, -12), Pair(-2, -29), Pair(5, -2), Pair(11, -97),
        Pair(13, -9), Pair(-13, 49), Pair(-10, 15), Pair(-7, -5), Pair(-5, 12), Pair(11, -45), Pair(52, -2), Pair(-47, -2)
      },
      { // Piece 5
        Pair(-19, 55), Pair(-26, -4), Pair(80, 75), Pair(63, 60), Pair(-1, 0), Pair(75, 37), Pair(-20, 3), Pair(30, -31),
        Pair(-45, -42), Pair(-10, 5), Pair(55, -11), Pair(72, 43), Pair(87, 51), Pair(6, 55), Pair(50, 69), Pair(-77, 56),
        Pair(28, -51), Pair(-51, 51), Pair(-54, 49), Pair(-90, 55), Pair(140, -4), Pair(75, 37), Pair(66, 21), Pair(53, -6),
        Pair(-124, 77), Pair(10, 36), Pair(-24, 14), Pair(-43, 18), Pair(80, 8), Pair(12, 18), Pair(103, 1), Pair(-15, 22),
        Pair(4, -24), Pair(52, -8), Pair(-25, 11), Pair(20, 12), Pair(53, 15), Pair(72, -7), Pair(42, 14), Pair(82, -13),
        Pair(-5, -40), Pair(-38, 6), Pair(21, 23), Pair(-9, 4), Pair(13, 2), Pair(9, 4), Pair(1, -7), Pair(-19, 6),
        Pair(-18, -5), Pair(-26, 4), Pair(20, -5), Pair(18, -6), Pair(-22, 4), Pair(-40, 17), Pair(-13, 5), Pair(17, -9),
        Pair(-31, -20), Pair(3, -7), Pair(-7, -5), Pair(-26, 0), Pair(-7, -5), Pair(-35, 5), Pair(4, -8), Pair(25, -23)
      }
    }},
    {{ // Bucket 46
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-1, -10), Pair(-3, -27), Pair(4, -38), Pair(-14, -5), Pair(7, -5), Pair(-70, 37), Pair(30, -14), Pair(3, 17),
        Pair(-5, 0), Pair(11, -6), Pair(12, 6), Pair(-12, -9), Pair(12, 1), Pair(-1, 5), Pair(18, 9), Pair(9, 24),
        Pair(-1, 3), Pair(3, 0), Pair(3, 4), Pair(2, -3), Pair(1, 0), Pair(-29, 1), Pair(2, 6), Pair(5, 13),
        Pair(-4, 8), Pair(-1, 10), Pair(-2, 8), Pair(-2, 3), Pair(0, 3), Pair(5, 1), Pair(10, -7), Pair(2, -6),
        Pair(1, 8), Pair(1, 7), Pair(1, 10), Pair(1, 8), Pair(0, 5), Pair(9, 2), Pair(0, -3), Pair(-2, -2),
        Pair(3, 10), Pair(0, 9), Pair(-2, 7), Pair(-1, 8), Pair(2, 8), Pair(10, 10), Pair(-8, 9), Pair(0, 5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(10, -4), Pair(67, 40), Pair(57, -7), Pair(95, 31), Pair(21, 16), Pair(-74, 39), Pair(26, 38), Pair(17, -56),
        Pair(-27, 31), Pair(15, 7), Pair(36, 22), Pair(8, 43), Pair(-30, 25), Pair(17, 37), Pair(-42, -18), Pair(12, 0),
        Pair(36, 25), Pair(-9, 27), Pair(4, 14), Pair(-14, 10), Pair(20, 15), Pair(-12, 16), Pair(-8, 17), Pair(-4, -33),
        Pair(-13, 16), Pair(6, 14), Pair(0, 26), Pair(17, 10), Pair(10, 11), Pair(9, 4), Pair(3, 5), Pair(-9, 28),
        Pair(10, 13), Pair(3, 38), Pair(1, 16), Pair(3, 17), Pair(10, 10), Pair(8, 8), Pair(2, 9), Pair(7, 2),
        Pair(-12, 13), Pair(-4, 14), Pair(2, 16), Pair(9, 10), Pair(3, 12), Pair(0, 18), Pair(15, 38), Pair(-4, 6),
        Pair(-3, 13), Pair(5, 17), Pair(-2, 13), Pair(-1, 18), Pair(-7, 19), Pair(-4, -2), Pair(-7, 20), Pair(-5, 14),
        Pair(35, 60), Pair(-7, 5), Pair(15, 14), Pair(-18, 39), Pair(-13, 18), Pair(-4, -2), Pair(5, 6), Pair(-36, 56)
      },
      { // Piece 2
        Pair(-32, 31), Pair(-29, -12), Pair(1, -14), Pair(27, -23), Pair(4, -3), Pair(29, -7), Pair(-62, 15), Pair(-13, 7),
        Pair(-16, 4), Pair(14, 4), Pair(-2, -7), Pair(62, -18), Pair(12, -25), Pair(-14, -8), Pair(-6, -23), Pair(-5, 32),
        Pair(13, -20), Pair(1, -13), Pair(16, -9), Pair(-11, -18), Pair(18, -17), Pair(-11, -1), Pair(-4, 5), Pair(-5, -16),
        Pair(-3, -25), Pair(7, -2), Pair(-5, 1), Pair(1, 1), Pair(1, -2), Pair(-19, 10), Pair(-1, -29), Pair(5, -11),
        Pair(13, -17), Pair(2, -10), Pair(13, 5), Pair(-6, -6), Pair(9, 2), Pair(-10, -7), Pair(7, -8), Pair(22, -18),
        Pair(0, 5), Pair(20, -2), Pair(-4, -8), Pair(7, 10), Pair(-1, 0), Pair(-2, -8), Pair(-24, -9), Pair(6, -11),
        Pair(10, 0), Pair(-2, -10), Pair(-9, 16), Pair(-4, 6), Pair(4, 8), Pair(0, -6), Pair(12, 23), Pair(-83, -67),
        Pair(17, -11), Pair(5, -17), Pair(-2, 4), Pair(-31, 27), Pair(-20, 12), Pair(16, -5), Pair(12, -39), Pair(-1, -26)
      },
      { // Piece 3
        Pair(-7, 23), Pair(-4, 17), Pair(5, 8), Pair(26, 11), Pair(-9, 19), Pair(22, -2), Pair(18, -5), Pair(47, 3),
        Pair(17, 11), Pair(19, 16), Pair(8, 11), Pair(30, -2), Pair(5, 9), Pair(29, 6), Pair(43, -19), Pair(-21, 28),
        Pair(28, 9), Pair(19, 12), Pair(6, 10), Pair(4, 10), Pair(18, 23), Pair(13, 4), Pair(100, -26), Pair(-4, 7),
        Pair(11, 5), Pair(4, 25), Pair(17, 6), Pair(12, 9), Pair(3, 14), Pair(-23, 11), Pair(-3, -3), Pair(-21, 21),
        Pair(6, 19), Pair(10, 9), Pair(6, 9), Pair(7, 14), Pair(-1, 25), Pair(2, 42), Pair(36, -17), Pair(15, 39),
        Pair(4, 19), Pair(-6, 8), Pair(4, 35), Pair(-2, 10), Pair(3, 11), Pair(0, 3), Pair(4, 23), Pair(-14, -41),
        Pair(21, 0), Pair(22, 10), Pair(1, 20), Pair(5, 7), Pair(6, 13), Pair(-5, -6), Pair(6, -12), Pair(-22, -7),
        Pair(1, 7), Pair(6, 6), Pair(9, 5), Pair(3, 8), Pair(3, 5), Pair(0, 3), Pair(-10, -14), Pair(-9, -6)
      },
      { // Piece 4
        Pair(11, -11), Pair(-7, -5), Pair(-15, 8), Pair(7, -23), Pair(18, 34), Pair(55, -10), Pair(17, -19), Pair(18, 8),
        Pair(20, -14), Pair(11, 24), Pair(-19, 13), Pair(13, 29), Pair(23, -13), Pair(67, -16), Pair(28, 42), Pair(10, 35),
        Pair(3, -13), Pair(23, -11), Pair(-4, 11), Pair(1, 10), Pair(5, -15), Pair(33, -48), Pair(0, -19), Pair(-7, 30),
        Pair(1, 15), Pair(12, -16), Pair(-5, 5), Pair(1, 35), Pair(-3, -1), Pair(-27, 6), Pair(-3, -10), Pair(-11, 8),
        Pair(11, -11), Pair(0, 7), Pair(-1, 11), Pair(-18, 9), Pair(-2, 8), Pair(-8, -7), Pair(8, -7), Pair(-24, 13),
        Pair(18, 2), Pair(3, 26), Pair(9, 16), Pair(-6, 17), Pair(2, 0), Pair(-2, 18), Pair(-9, 70), Pair(11, -33),
        Pair(1, 23), Pair(12, 24), Pair(6, 18), Pair(6, 11), Pair(4, 20), Pair(-6, -21), Pair(-4, -19), Pair(-21, -19),
        Pair(9, -2), Pair(5, 4), Pair(1, 18), Pair(3, 9), Pair(1, 15), Pair(3, 29), Pair(5, -9), Pair(-28, 20)
      },
      { // Piece 5
        Pair(-31, 86), Pair(-46, 38), Pair(1, 56), Pair(-54, 46), Pair(-48, -6), Pair(-83, 51), Pair(-31, 109), Pair(-88, 12),
        Pair(-66, -41), Pair(-72, 70), Pair(-50, 26), Pair(-112, 29), Pair(-65, 20), Pair(-118, 79), Pair(77, 69), Pair(-3, 67),
        Pair(-76, 24), Pair(11, -12), Pair(-47, 38), Pair(30, -2), Pair(49, 33), Pair(93, 66), Pair(-4, 48), Pair(-27, 39),
        Pair(137, 5), Pair(-82, 25), Pair(-45, 12), Pair(-37, 23), Pair(96, 20), Pair(0, 39), Pair(-6, 39), Pair(-52, 54),
        Pair(43, -9), Pair(-3, 42), Pair(17, 5), Pair(12, 27), Pair(59, 11), Pair(49, 21), Pair(26, 30), Pair(-46, 34),
        Pair(-54, 0), Pair(-31, 0), Pair(-27, 31), Pair(-9, 15), Pair(10, 15), Pair(-14, 10), Pair(25, 59), Pair(8, -2),
        Pair(-90, 14), Pair(-40, 6), Pair(-17, 12), Pair(-12, 11), Pair(12, 2), Pair(0, 2), Pair(1, 7), Pair(-2, -2),
        Pair(-58, -9), Pair(-32, 12), Pair(-37, 4), Pair(-3, -6), Pair(1, -5), Pair(-3, -8), Pair(10, -4), Pair(-15, -12)
      }
    }},
    {{ // Bucket 47
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-22, 24), Pair(19, -9), Pair(37, -6), Pair(-36, 14), Pair(-20, -8), Pair(70, -4), Pair(24, -32), Pair(-4, 36),
        Pair(-12, 12), Pair(15, -1), Pair(6, -17), Pair(-2, -10), Pair(5, -10), Pair(1, -9), Pair(-22, 11), Pair(9, 25),
        Pair(0, -1), Pair(2, 1), Pair(-2, 3), Pair(3, 2), Pair(-6, 11), Pair(-3, -3), Pair(-19, 11), Pair(34, 3),
        Pair(0, 5), Pair(2, 6), Pair(3, 6), Pair(-1, 6), Pair(-1, 5), Pair(4, 4), Pair(8, -4), Pair(1, 0),
        Pair(0, 9), Pair(2, 5), Pair(0, 5), Pair(0, 5), Pair(3, 8), Pair(3, 1), Pair(-2, -1), Pair(-3, -9),
        Pair(1, 12), Pair(1, 9), Pair(0, 6), Pair(-1, 9), Pair(0, 7), Pair(2, 2), Pair(4, 4), Pair(-3, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-33, 2), Pair(18, 10), Pair(-87, 32), Pair(-73, 35), Pair(108, -51), Pair(45, -66), Pair(-22, 23), Pair(103, -13),
        Pair(35, 14), Pair(-6, 10), Pair(-12, 39), Pair(27, -10), Pair(-1, 25), Pair(-30, 16), Pair(4, 49), Pair(-42, 39),
        Pair(4, 27), Pair(-6, 7), Pair(-3, 10), Pair(16, 1), Pair(-6, 8), Pair(32, -15), Pair(-14, 31), Pair(32, 4),
        Pair(-2, 10), Pair(4, 5), Pair(-2, 10), Pair(16, 3), Pair(3, 6), Pair(-4, 8), Pair(8, 5), Pair(-3, 21),
        Pair(-12, 6), Pair(15, 8), Pair(5, 0), Pair(9, 5), Pair(11, 10), Pair(11, 12), Pair(11, 5), Pair(-1, 0),
        Pair(0, 14), Pair(-4, 11), Pair(1, 6), Pair(4, 13), Pair(6, 17), Pair(-1, 9), Pair(6, 9), Pair(-30, 14),
        Pair(-44, 23), Pair(-11, 2), Pair(-12, 3), Pair(-2, 11), Pair(5, 1), Pair(-14, 8), Pair(-3, 1), Pair(-2, 6),
        Pair(-110, 32), Pair(-7, -2), Pair(-18, 34), Pair(-29, 1), Pair(-18, 30), Pair(-7, -12), Pair(-5, -8), Pair(-47, 21)
      },
      { // Piece 2
        Pair(-23, -19), Pair(-8, 19), Pair(-66, -14), Pair(-26, 14), Pair(29, -22), Pair(84, -2), Pair(-40, -5), Pair(-11, 6),
        Pair(-20, 6), Pair(-1, -13), Pair(-19, -6), Pair(57, -20), Pair(27, -20), Pair(4, 20), Pair(-1, 14), Pair(10, -26),
        Pair(0, -27), Pair(-5, 8), Pair(5, -25), Pair(-16, 2), Pair(6, -5), Pair(11, 10), Pair(29, -33), Pair(19, 0),
        Pair(20, 3), Pair(-1, -16), Pair(-7, -2), Pair(24, -22), Pair(7, 2), Pair(19, -8), Pair(6, 21), Pair(-7, 7),
        Pair(-13, 6), Pair(15, -2), Pair(2, -12), Pair(13, 5), Pair(7, 1), Pair(-5, 3), Pair(2, 26), Pair(3, -12),
        Pair(1, 8), Pair(4, -13), Pair(7, -4), Pair(1, -4), Pair(4, 6), Pair(-4, -4), Pair(-1, 4), Pair(20, 31),
        Pair(9, -14), Pair(3, 7), Pair(2, 4), Pair(-6, 21), Pair(-7, 12), Pair(4, 18), Pair(8, -2), Pair(17, 25),
        Pair(8, 21), Pair(-22, 1), Pair(-1, 9), Pair(-26, 4), Pair(20, 5), Pair(-9, 2), Pair(42, 10), Pair(42, -25)
      },
      { // Piece 3
        Pair(31, 4), Pair(-1, 13), Pair(42, 0), Pair(27, 1), Pair(-8, 17), Pair(75, -21), Pair(33, 18), Pair(55, -20),
        Pair(21, 13), Pair(10, 8), Pair(28, 8), Pair(11, 17), Pair(38, 0), Pair(18, 4), Pair(11, 31), Pair(113, -53),
        Pair(8, 11), Pair(6, 8), Pair(25, 8), Pair(24, 2), Pair(19, 17), Pair(3, 16), Pair(-2, -5), Pair(62, -37),
        Pair(-1, 18), Pair(1, 17), Pair(26, -15), Pair(22, 0), Pair(16, -11), Pair(20, 24), Pair(-20, 25), Pair(5, 3),
        Pair(-3, 17), Pair(-4, 12), Pair(5, 9), Pair(38, -16), Pair(6, 11), Pair(6, 12), Pair(8, 24), Pair(22, -15),
        Pair(13, -3), Pair(-7, 15), Pair(-3, 6), Pair(1, 5), Pair(-1, 14), Pair(9, 2), Pair(-21, 18), Pair(29, 7),
        Pair(-9, 20), Pair(-4, 20), Pair(8, 18), Pair(-2, 21), Pair(-9, 21), Pair(-6, 8), Pair(21, -1), Pair(-1, -28),
        Pair(3, 3), Pair(10, 4), Pair(6, 11), Pair(5, 8), Pair(3, 6), Pair(6, 8), Pair(-19, 11), Pair(-22, -16)
      },
      { // Piece 4
        Pair(17, -24), Pair(-10, -31), Pair(-26, 26), Pair(-28, 3), Pair(26, 10), Pair(17, 41), Pair(-30, -51), Pair(93, 6),
        Pair(4, 8), Pair(-16, 29), Pair(18, -8), Pair(-4, 11), Pair(20, -3), Pair(41, -17), Pair(-14, 25), Pair(-18, 17),
        Pair(0, -8), Pair(-14, 25), Pair(14, -9), Pair(35, -26), Pair(45, -6), Pair(7, -9), Pair(-4, -7), Pair(-1, -16),
        Pair(24, -17), Pair(1, 5), Pair(24, 8), Pair(-3, -14), Pair(0, 13), Pair(6, 16), Pair(12, 22), Pair(19, 2),
        Pair(9, -8), Pair(-8, 15), Pair(-3, -18), Pair(-1, 5), Pair(-4, 13), Pair(-3, -20), Pair(-6, 10), Pair(1, 0),
        Pair(9, -1), Pair(7, 7), Pair(-4, 24), Pair(-5, 6), Pair(0, 16), Pair(-6, 8), Pair(-1, 24), Pair(-34, -8),
        Pair(15, 16), Pair(-3, 17), Pair(1, 11), Pair(2, 6), Pair(5, 2), Pair(4, 9), Pair(4, -16), Pair(-21, -2),
        Pair(16, -9), Pair(-1, 4), Pair(8, 5), Pair(5, 15), Pair(-9, -3), Pair(4, -11), Pair(9, -62), Pair(-12, -81)
      },
      { // Piece 5
        Pair(-6, -45), Pair(-88, 53), Pair(-24, -14), Pair(-11, -81), Pair(-3, 26), Pair(48, 43), Pair(-29, -8), Pair(-6, -5),
        Pair(-88, 54), Pair(80, 11), Pair(7, 21), Pair(-20, 71), Pair(-20, 19), Pair(49, 63), Pair(4, 78), Pair(-24, -10),
        Pair(58, -31), Pair(-14, 13), Pair(2, 19), Pair(-13, 4), Pair(-14, 13), Pair(-13, 40), Pair(26, 42), Pair(-113, 55),
        Pair(-58, 5), Pair(-44, 20), Pair(-63, 19), Pair(-43, 22), Pair(-40, 33), Pair(10, 26), Pair(53, 25), Pair(10, 18),
        Pair(15, -47), Pair(-49, 19), Pair(-63, 25), Pair(-52, 31), Pair(-10, 27), Pair(23, 21), Pair(33, 26), Pair(-22, 5),
        Pair(-156, 0), Pair(-46, 25), Pair(-54, 18), Pair(-38, 21), Pair(-9, 18), Pair(2, 11), Pair(-37, -6), Pair(5, -9),
        Pair(-71, 38), Pair(-66, 25), Pair(-29, 17), Pair(-41, 21), Pair(-5, 7), Pair(-14, 5), Pair(-24, -7), Pair(-18, -16),
        Pair(-50, -14), Pair(-35, 0), Pair(-36, 4), Pair(-37, 11), Pair(-10, 1), Pair(9, -12), Pair(6, -1), Pair(-1, -19)
      }
    }},
    {{ // Bucket 48
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(14, -2), Pair(-45, 55), Pair(-59, 44), Pair(9, -29), Pair(-28, -4), Pair(-33, 19), Pair(79, 8), Pair(-69, -5),
        Pair(-26, 2), Pair(-19, 5), Pair(-3, 10), Pair(-7, -2), Pair(-12, -12), Pair(5, 8), Pair(-20, 10), Pair(-21, 8),
        Pair(-7, 21), Pair(-2, -4), Pair(-3, 1), Pair(-7, 5), Pair(-2, 8), Pair(7, 5), Pair(-1, 18), Pair(-17, 9),
        Pair(13, 10), Pair(-1, 6), Pair(0, 5), Pair(1, 0), Pair(2, 5), Pair(0, 6), Pair(-2, 3), Pair(0, 8),
        Pair(8, 8), Pair(1, 8), Pair(0, 3), Pair(2, 3), Pair(-2, 9), Pair(3, 3), Pair(0, 10), Pair(1, 10),
        Pair(1, 5), Pair(-3, 3), Pair(-3, 4), Pair(5, 4), Pair(-4, 7), Pair(-1, 9), Pair(0, 10), Pair(0, 8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-59, 15), Pair(-131, 32), Pair(-68, -28), Pair(-44, 38), Pair(-128, 80), Pair(-96, 41), Pair(-34, 75), Pair(13, -28),
        Pair(3, -28), Pair(8, -20), Pair(-16, 18), Pair(15, 24), Pair(-19, 17), Pair(-4, 36), Pair(10, 54), Pair(14, -36),
        Pair(70, -55), Pair(-10, 24), Pair(2, 21), Pair(-15, 12), Pair(22, 2), Pair(2, 25), Pair(-10, 38), Pair(6, 24),
        Pair(-7, 13), Pair(2, 21), Pair(2, 7), Pair(6, 20), Pair(-2, 9), Pair(-6, 31), Pair(2, 26), Pair(-7, -2),
        Pair(1, 21), Pair(0, 7), Pair(3, 30), Pair(2, 16), Pair(-10, 30), Pair(-1, 17), Pair(5, 15), Pair(1, 2),
        Pair(-10, 10), Pair(3, 20), Pair(3, 11), Pair(-4, 18), Pair(4, 21), Pair(1, 11), Pair(2, 19), Pair(16, 5),
        Pair(-37, -8), Pair(-23, 32), Pair(2, -4), Pair(-4, 10), Pair(2, 8), Pair(9, 14), Pair(-16, 21), Pair(2, 3),
        Pair(107, -87), Pair(-10, -11), Pair(0, 25), Pair(-3, 3), Pair(-6, 10), Pair(-4, 6), Pair(3, 13), Pair(8, 16)
      },
      { // Piece 2
        Pair(-34, 10), Pair(-83, 32), Pair(36, -21), Pair(4, -27), Pair(-33, 21), Pair(70, -44), Pair(-53, -41), Pair(32, -28),
        Pair(-14, 7), Pair(-13, 20), Pair(13, -9), Pair(-5, -12), Pair(26, -55), Pair(10, -48), Pair(-24, -5), Pair(-24, 36),
        Pair(-20, -8), Pair(2, 0), Pair(7, -12), Pair(19, -13), Pair(10, -18), Pair(67, -43), Pair(50, -43), Pair(-8, 21),
        Pair(5, -4), Pair(13, 2), Pair(-4, 15), Pair(6, -2), Pair(-1, -3), Pair(20, 2), Pair(1, 5), Pair(11, -4),
        Pair(9, -32), Pair(12, 21), Pair(15, -16), Pair(6, -22), Pair(11, 10), Pair(0, 5), Pair(4, 6), Pair(2, 28),
        Pair(3, -18), Pair(11, 8), Pair(0, 6), Pair(8, -6), Pair(4, 2), Pair(9, 18), Pair(11, 6), Pair(10, -4),
        Pair(-36, -20), Pair(0, 8), Pair(5, -9), Pair(0, 6), Pair(5, 10), Pair(15, 11), Pair(5, 11), Pair(-1, 19),
        Pair(-7, -34), Pair(12, -22), Pair(0, 16), Pair(17, 3), Pair(5, -4), Pair(-4, 9), Pair(-20, 12), Pair(13, 10)
      },
      { // Piece 3
        Pair(21, -64), Pair(14, 4), Pair(33, -3), Pair(7, 11), Pair(-29, 32), Pair(-83, 43), Pair(53, -19), Pair(20, 19),
        Pair(-22, -13), Pair(2, 20), Pair(-7, 9), Pair(3, 10), Pair(-42, 20), Pair(18, -10), Pair(-17, -3), Pair(-32, 25),
        Pair(-5, -11), Pair(21, 9), Pair(-20, 26), Pair(0, 9), Pair(-8, 27), Pair(-34, 26), Pair(0, -14), Pair(25, 2),
        Pair(-27, 22), Pair(11, 2), Pair(-3, 13), Pair(25, -5), Pair(6, 13), Pair(7, -1), Pair(-17, 24), Pair(7, 16),
        Pair(4, 18), Pair(12, 13), Pair(-17, 45), Pair(-5, 28), Pair(3, -8), Pair(1, 14), Pair(14, -5), Pair(6, -16),
        Pair(-14, -20), Pair(6, 10), Pair(7, 9), Pair(7, 22), Pair(4, 8), Pair(-8, 20), Pair(9, 15), Pair(19, 25),
        Pair(-12, -63), Pair(-6, 3), Pair(-5, 9), Pair(19, 8), Pair(11, 2), Pair(1, 3), Pair(13, -8), Pair(9, 3),
        Pair(-5, -7), Pair(0, 9), Pair(2, 18), Pair(6, 10), Pair(4, 6), Pair(0, 3), Pair(9, 7), Pair(11, 4)
      },
      { // Piece 4
        Pair(-54, -18), Pair(-14, 6), Pair(13, -34), Pair(10, -1), Pair(-69, 31), Pair(-38, 6), Pair(-23, 17), Pair(-62, 47),
        Pair(-10, -2), Pair(-19, -4), Pair(0, 34), Pair(-33, 9), Pair(-16, -33), Pair(-15, 22), Pair(30, -38), Pair(7, -65),
        Pair(-7, 24), Pair(4, -3), Pair(-38, 9), Pair(-28, -8), Pair(11, -31), Pair(-41, -9), Pair(1, -75), Pair(-37, 11),
        Pair(-5, 43), Pair(-5, 44), Pair(-20, -2), Pair(-9, -1), Pair(-1, 1), Pair(-7, -25), Pair(18, 11), Pair(-6, -7),
        Pair(-12, 24), Pair(13, -4), Pair(7, 12), Pair(-1, -4), Pair(-2, 18), Pair(-5, -1), Pair(0, -3), Pair(10, 12),
        Pair(-14, 11), Pair(12, 11), Pair(-4, 26), Pair(10, 1), Pair(0, 36), Pair(-2, 21), Pair(2, -3), Pair(-1, -49),
        Pair(19, -34), Pair(-1, 10), Pair(7, -1), Pair(6, 11), Pair(5, 15), Pair(20, -9), Pair(2, -4), Pair(-8, -54),
        Pair(2, 18), Pair(-19, 46), Pair(-1, 13), Pair(2, 14), Pair(5, -2), Pair(10, -27), Pair(73, -18), Pair(29, 51)
      },
      { // Piece 5
        Pair(11, -94), Pair(-27, 66), Pair(9, 113), Pair(-38, -54), Pair(23, -76), Pair(52, -134), Pair(-10, 70), Pair(-9, 22),
        Pair(62, 77), Pair(80, 116), Pair(-20, 38), Pair(-15, 57), Pair(29, 9), Pair(66, -6), Pair(-111, 62), Pair(-66, -26),
        Pair(-44, 83), Pair(-59, 97), Pair(-36, 90), Pair(-19, 68), Pair(-166, 73), Pair(-128, 46), Pair(-132, 25), Pair(-197, 43),
        Pair(-149, 71), Pair(-50, 96), Pair(-109, 94), Pair(-156, 46), Pair(-99, 29), Pair(-31, 16), Pair(-37, 6), Pair(-111, 13),
        Pair(-54, 61), Pair(-118, 67), Pair(-43, 45), Pair(-51, 39), Pair(-11, 27), Pair(-1, 8), Pair(-96, 17), Pair(-50, 5),
        Pair(14, 7), Pair(-8, 34), Pair(-18, 21), Pair(-25, 25), Pair(-33, 23), Pair(-32, 16), Pair(-17, 8), Pair(-43, 0),
        Pair(-31, 83), Pair(-3, -13), Pair(11, -24), Pair(-8, 7), Pair(-8, 12), Pair(-13, 20), Pair(-13, 9), Pair(-5, -2),
        Pair(7, -55), Pair(40, -29), Pair(44, -4), Pair(16, -4), Pair(1, -5), Pair(-5, 9), Pair(-1, 4), Pair(1, -9)
      }
    }},
    {{ // Bucket 49
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-23, 44), Pair(13, -30), Pair(-30, -43), Pair(28, 48), Pair(-31, -9), Pair(-6, 51), Pair(-93, 0), Pair(-75, -11),
        Pair(-5, 17), Pair(-12, 34), Pair(-11, -11), Pair(-16, 12), Pair(-31, -2), Pair(5, 0), Pair(-17, 0), Pair(-12, -18),
        Pair(-5, 12), Pair(1, 14), Pair(-9, 3), Pair(-6, 6), Pair(0, 5), Pair(3, 6), Pair(-9, 12), Pair(0, 2),
        Pair(0, 8), Pair(-6, 14), Pair(0, 2), Pair(2, 6), Pair(0, 10), Pair(4, 5), Pair(-1, 6), Pair(1, 8),
        Pair(-1, 5), Pair(2, 3), Pair(3, 16), Pair(-2, 3), Pair(-1, 8), Pair(2, 8), Pair(1, 8), Pair(0, 8),
        Pair(-2, 3), Pair(0, 4), Pair(3, 4), Pair(1, -26), Pair(-2, 8), Pair(1, 8), Pair(2, 9), Pair(2, 5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(4, 11), Pair(-16, 34), Pair(-54, 66), Pair(12, -34), Pair(-1, 14), Pair(-77, 2), Pair(58, -17), Pair(-12, 46),
        Pair(11, 1), Pair(3, 7), Pair(-8, -1), Pair(-41, 66), Pair(-39, 46), Pair(-18, 84), Pair(-13, 29), Pair(-49, 15),
        Pair(-41, 26), Pair(-16, 27), Pair(-5, 20), Pair(-11, 6), Pair(-10, 6), Pair(-67, 36), Pair(-17, 40), Pair(-46, -7),
        Pair(14, 5), Pair(0, 4), Pair(-2, 14), Pair(-5, 24), Pair(-4, 16), Pair(-9, 25), Pair(-8, 35), Pair(-7, 26),
        Pair(7, 37), Pair(21, -5), Pair(2, 18), Pair(-3, 28), Pair(1, 12), Pair(12, 9), Pair(7, 22), Pair(1, 14),
        Pair(14, -12), Pair(-2, 2), Pair(6, 12), Pair(13, 25), Pair(9, 30), Pair(1, 18), Pair(2, 21), Pair(7, 33),
        Pair(10, -4), Pair(13, -56), Pair(1, 15), Pair(3, 2), Pair(-2, 18), Pair(3, 31), Pair(1, 42), Pair(-3, 34),
        Pair(-37, 25), Pair(4, 34), Pair(28, 31), Pair(16, 8), Pair(1, 24), Pair(8, 25), Pair(-1, 5), Pair(-46, -19)
      },
      { // Piece 2
        Pair(6, -39), Pair(-28, 12), Pair(-29, 41), Pair(-3, 7), Pair(51, 10), Pair(-79, -20), Pair(-3, 16), Pair(-39, 2),
        Pair(3, 6), Pair(-9, 1), Pair(-20, -5), Pair(-25, -6), Pair(-17, 17), Pair(-17, -22), Pair(9, -35), Pair(-4, -15),
        Pair(-29, 29), Pair(6, 17), Pair(8, 5), Pair(3, 6), Pair(3, -8), Pair(7, -20), Pair(31, -39), Pair(-14, -10),
        Pair(12, 11), Pair(-10, -4), Pair(-4, 24), Pair(-7, 7), Pair(-1, 26), Pair(-2, -10), Pair(-6, 2), Pair(-10, 27),
        Pair(4, 0), Pair(4, 5), Pair(2, -11), Pair(1, 8), Pair(-1, 6), Pair(4, -6), Pair(10, -1), Pair(7, -6),
        Pair(-23, 12), Pair(-12, -15), Pair(6, 21), Pair(-2, 14), Pair(2, 3), Pair(7, 10), Pair(10, 9), Pair(-2, 17),
        Pair(-9, -14), Pair(-10, 35), Pair(1, -13), Pair(-1, 10), Pair(1, 11), Pair(7, 22), Pair(3, 12), Pair(-5, 30),
        Pair(-47, -40), Pair(17, -35), Pair(-6, 3), Pair(16, -14), Pair(-2, 11), Pair(1, 15), Pair(-1, 27), Pair(6, -1)
      },
      { // Piece 3
        Pair(-30, 39), Pair(74, -40), Pair(12, 26), Pair(-15, 23), Pair(-32, -2), Pair(22, 20), Pair(-24, -3), Pair(-55, 21),
        Pair(-11, 7), Pair(8, 2), Pair(-2, 5), Pair(14, -15), Pair(5, 4), Pair(-30, 25), Pair(5, 17), Pair(13, -24),
        Pair(-13, 13), Pair(-2, 6), Pair(-4, 8), Pair(-31, 28), Pair(-21, 3), Pair(-44, 22), Pair(5, -16), Pair(43, -13),
        Pair(5, 6), Pair(-8, 4), Pair(-10, 7), Pair(-25, 5), Pair(8, -12), Pair(17, -29), Pair(31, -15), Pair(4, -2),
        Pair(3, -9), Pair(-37, 25), Pair(8, 3), Pair(3, 13), Pair(-4, 22), Pair(-2, 29), Pair(6, 50), Pair(7, 1),
        Pair(12, -24), Pair(-5, 7), Pair(4, -7), Pair(9, 12), Pair(-2, 16), Pair(-16, 14), Pair(-14, 0), Pair(30, -6),
        Pair(7, -23), Pair(-11, 35), Pair(3, 3), Pair(6, 0), Pair(4, 17), Pair(-1, 9), Pair(19, 13), Pair(-7, 9),
        Pair(0, -6), Pair(-5, -19), Pair(0, -2), Pair(0, 6), Pair(-1, 4), Pair(-2, 3), Pair(6, -8), Pair(7, 12)
      },
      { // Piece 4
        Pair(-21, 25), Pair(5, -29), Pair(12, -9), Pair(61, -49), Pair(-16, -7), Pair(45, -39), Pair(66, -27), Pair(-39, 1),
        Pair(-4, 15), Pair(1, -17), Pair(-29, 40), Pair(-8, -10), Pair(-44, 43), Pair(22, 45), Pair(40, -56), Pair(-33, 29),
        Pair(-2, 7), Pair(-10, 31), Pair(7, -12), Pair(-6, 6), Pair(-8, 12), Pair(-45, 91), Pair(-18, 17), Pair(-27, -5),
        Pair(-4, 23), Pair(-12, 26), Pair(-6, 14), Pair(-9, 3), Pair(-4, -18), Pair(-15, -19), Pair(-3, 9), Pair(-5, 3),
        Pair(-1, 16), Pair(-19, 11), Pair(4, -11), Pair(1, 7), Pair(2, -7), Pair(-11, 5), Pair(-4, 24), Pair(16, -72),
        Pair(-17, 58), Pair(-4, 2), Pair(4, 11), Pair(-1, 25), Pair(0, 20), Pair(6, -8), Pair(-5, 13), Pair(16, 22),
        Pair(-14, 48), Pair(-46, 46), Pair(3, 16), Pair(6, 8), Pair(7, 10), Pair(5, 35), Pair(6, 51), Pair(-10, 43),
        Pair(-20, -18), Pair(10, -13), Pair(-5, 21), Pair(1, 11), Pair(1, 31), Pair(3, 14), Pair(3, -6), Pair(-25, 17)
      },
      { // Piece 5
        Pair(-21, 150), Pair(101, 154), Pair(7, 115), Pair(39, 141), Pair(7, -116), Pair(7, 85), Pair(-19, -97), Pair(9, -33),
        Pair(-13, 144), Pair(118, -21), Pair(109, 106), Pair(3, 66), Pair(19, -12), Pair(-93, 40), Pair(-17, 20), Pair(-84, -6),
        Pair(-163, 118), Pair(40, 42), Pair(51, 73), Pair(-149, 62), Pair(-83, 46), Pair(59, 10), Pair(-63, 31), Pair(17, 54),
        Pair(-1, 71), Pair(-5, 33), Pair(106, 27), Pair(-54, 93), Pair(-40, 47), Pair(-18, -2), Pair(-81, 24), Pair(-66, 34),
        Pair(3, 53), Pair(31, 12), Pair(9, 42), Pair(30, 25), Pair(-37, 36), Pair(-46, 14), Pair(-66, 14), Pair(-78, 20),
        Pair(30, -11), Pair(-15, 29), Pair(-30, 39), Pair(5, 10), Pair(3, 15), Pair(-10, 2), Pair(-4, 3), Pair(-7, 1),
        Pair(58, 7), Pair(173, 73), Pair(2, 6), Pair(-1, 7), Pair(17, 4), Pair(-25, 12), Pair(-10, 5), Pair(-3, -7),
        Pair(54, -7), Pair(20, 5), Pair(23, -2), Pair(1, -21), Pair(11, 4), Pair(-6, 2), Pair(-2, 0), Pair(-4, -15)
      }
    }},
    {{ // Bucket 50
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-51, 33), Pair(-57, 19), Pair(-10, -9), Pair(-4, 14), Pair(57, -49), Pair(-55, 17), Pair(-47, 13), Pair(86, -42),
        Pair(-3, -14), Pair(-24, 5), Pair(10, -25), Pair(-55, 2), Pair(9, -13), Pair(3, 0), Pair(-14, -15), Pair(-27, 4),
        Pair(3, 1), Pair(-6, 1), Pair(-16, 19), Pair(-1, 1), Pair(6, 2), Pair(0, 10), Pair(5, -3), Pair(-11, 13),
        Pair(-1, 2), Pair(0, 3), Pair(2, 11), Pair(2, 3), Pair(1, 6), Pair(0, 9), Pair(-1, 7), Pair(-2, 6),
        Pair(-1, 1), Pair(4, 10), Pair(-1, -6), Pair(3, 15), Pair(-4, 5), Pair(0, 5), Pair(-2, 6), Pair(0, 6),
        Pair(-3, 3), Pair(3, 4), Pair(-5, 3), Pair(1, 6), Pair(-2, -2), Pair(-4, 8), Pair(-1, 7), Pair(-2, 9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-11, 44), Pair(23, -21), Pair(34, 29), Pair(0, 25), Pair(-198, 106), Pair(86, -18), Pair(14, -13), Pair(-7, -14),
        Pair(16, 34), Pair(16, 31), Pair(-6, 35), Pair(22, 44), Pair(18, 12), Pair(-22, -1), Pair(48, -8), Pair(-38, 26),
        Pair(2, 6), Pair(-16, -25), Pair(-7, 39), Pair(-3, 24), Pair(17, 29), Pair(-9, 47), Pair(-7, 32), Pair(-17, 13),
        Pair(12, 12), Pair(1, 29), Pair(-10, 60), Pair(2, 12), Pair(4, 10), Pair(8, 5), Pair(-10, 34), Pair(22, -9),
        Pair(-1, -5), Pair(12, 16), Pair(4, -2), Pair(10, 22), Pair(-4, 20), Pair(-1, 30), Pair(-6, 41), Pair(10, 10),
        Pair(8, 28), Pair(9, 3), Pair(0, 0), Pair(5, 19), Pair(9, 32), Pair(-1, 19), Pair(14, 8), Pair(9, 5),
        Pair(-21, 29), Pair(35, -48), Pair(98, 58), Pair(1, 9), Pair(7, 8), Pair(4, 40), Pair(-14, 2), Pair(6, 14),
        Pair(-97, -50), Pair(1, 6), Pair(7, -1), Pair(25, 30), Pair(17, 17), Pair(23, 22), Pair(6, 14), Pair(12, 53)
      },
      { // Piece 2
        Pair(48, 24), Pair(-26, 42), Pair(-13, 51), Pair(0, 11), Pair(-51, 11), Pair(132, 38), Pair(100, 1), Pair(64, -41),
        Pair(16, -10), Pair(-7, -1), Pair(12, 28), Pair(9, -20), Pair(6, 13), Pair(62, -27), Pair(-13, -44), Pair(3, 36),
        Pair(-7, 16), Pair(5, -1), Pair(-32, 32), Pair(-1, 16), Pair(0, -43), Pair(26, -22), Pair(-12, -37), Pair(-10, -3),
        Pair(-20, 10), Pair(2, 2), Pair(3, -3), Pair(24, -15), Pair(7, 9), Pair(3, 3), Pair(14, -9), Pair(-19, -21),
        Pair(12, 27), Pair(30, -8), Pair(5, -1), Pair(13, 12), Pair(-10, 0), Pair(7, 29), Pair(22, -14), Pair(0, 18),
        Pair(3, -17), Pair(8, -8), Pair(6, 9), Pair(10, 31), Pair(3, 17), Pair(-6, 11), Pair(0, 6), Pair(0, 13),
        Pair(-19, -21), Pair(9, 16), Pair(21, -58), Pair(7, 26), Pair(-2, 17), Pair(1, 38), Pair(0, 16), Pair(13, 34),
        Pair(-3, -8), Pair(-55, -76), Pair(11, 9), Pair(-3, -13), Pair(-1, 30), Pair(-6, 22), Pair(1, 11), Pair(22, 0)
      },
      { // Piece 3
        Pair(-25, 26), Pair(30, 22), Pair(25, -29), Pair(91, -6), Pair(21, 3), Pair(-59, -8), Pair(-8, 18), Pair(30, -14),
        Pair(-21, 18), Pair(-9, 13), Pair(-17, 15), Pair(13, -7), Pair(-27, 1), Pair(33, 10), Pair(-32, 25), Pair(20, 5),
        Pair(6, -10), Pair(19, -8), Pair(-12, 3), Pair(-4, 4), Pair(39, -33), Pair(-2, 8), Pair(-14, 9), Pair(15, 16),
        Pair(5, 11), Pair(-3, -1), Pair(16, 9), Pair(-15, 7), Pair(2, 9), Pair(-9, 7), Pair(21, -7), Pair(17, 10),
        Pair(21, 0), Pair(10, -1), Pair(7, 21), Pair(-13, 29), Pair(-15, 19), Pair(-16, 7), Pair(56, -10), Pair(-3, 16),
        Pair(13, 17), Pair(17, -25), Pair(-18, 15), Pair(1, -5), Pair(6, 10), Pair(-2, -5), Pair(6, -5), Pair(27, -40),
        Pair(0, 7), Pair(3, -22), Pair(-44, 6), Pair(7, 8), Pair(2, 9), Pair(-4, -19), Pair(13, -53), Pair(-8, 9),
        Pair(-3, 14), Pair(6, -6), Pair(-2, -13), Pair(-3, 5), Pair(1, 12), Pair(2, 3), Pair(10, 8), Pair(-3, 17)
      },
      { // Piece 4
        Pair(-61, 28), Pair(66, -33), Pair(98, -71), Pair(-20, 21), Pair(-28, 6), Pair(39, -26), Pair(78, -73), Pair(-28, 69),
        Pair(-11, 54), Pair(-2, 2), Pair(-29, 20), Pair(-57, 83), Pair(-3, -60), Pair(-24, 92), Pair(-29, 68), Pair(-57, 54),
        Pair(-7, 5), Pair(4, -28), Pair(-10, 10), Pair(-57, 97), Pair(-35, 8), Pair(-24, 118), Pair(-45, 52), Pair(-24, 62),
        Pair(23, -33), Pair(-5, 50), Pair(29, -25), Pair(-15, 20), Pair(-10, 21), Pair(-3, 1), Pair(-6, 16), Pair(-29, 28),
        Pair(-27, 38), Pair(33, -37), Pair(-6, 36), Pair(-7, 33), Pair(-2, 6), Pair(-15, 28), Pair(-10, 1), Pair(-1, -17),
        Pair(-1, 5), Pair(-4, 24), Pair(-5, -8), Pair(16, -13), Pair(12, -19), Pair(15, -3), Pair(14, 5), Pair(-6, 35),
        Pair(-21, -49), Pair(-27, 16), Pair(28, -53), Pair(1, 19), Pair(9, 2), Pair(6, 7), Pair(26, 2), Pair(-7, 92),
        Pair(14, -28), Pair(-12, 29), Pair(-1, -17), Pair(0, 7), Pair(2, 21), Pair(7, -20), Pair(-2, -64), Pair(27, 90)
      },
      { // Piece 5
        Pair(16, 147), Pair(72, 143), Pair(35, 34), Pair(15, 100), Pair(52, 147), Pair(5, 112), Pair(38, 11), Pair(43, 41),
        Pair(-3, 117), Pair(9, 128), Pair(-134, 68), Pair(19, 89), Pair(15, 24), Pair(-22, 33), Pair(20, 72), Pair(-14, -59),
        Pair(-38, 85), Pair(86, 107), Pair(-68, 77), Pair(137, 96), Pair(79, 13), Pair(9, 27), Pair(-59, -24), Pair(68, -8),
        Pair(35, 68), Pair(-127, 101), Pair(162, 36), Pair(5, 69), Pair(-122, 45), Pair(-64, 17), Pair(-64, -7), Pair(-51, 33),
        Pair(36, 69), Pair(-94, 59), Pair(145, 18), Pair(18, -4), Pair(-11, 17), Pair(19, 25), Pair(-15, 18), Pair(7, 12),
        Pair(-12, 49), Pair(-59, 42), Pair(11, 21), Pair(65, 23), Pair(-8, 23), Pair(-1, 6), Pair(13, -10), Pair(-17, -4),
        Pair(33, 39), Pair(22, 11), Pair(92, 37), Pair(-19, 30), Pair(-9, 6), Pair(7, -9), Pair(-12, 0), Pair(1, -17),
        Pair(64, 1), Pair(20, 8), Pair(4, 17), Pair(2, 25), Pair(6, 13), Pair(6, -11), Pair(-5, -5), Pair(-5, -12)
      }
    }},
    {{ // Bucket 51
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-10, 39), Pair(-44, 20), Pair(-34, -43), Pair(11, 1), Pair(-197, 108), Pair(-97, -69), Pair(83, -71), Pair(64, 62),
        Pair(-2, -4), Pair(-53, 23), Pair(-34, -30), Pair(24, -31), Pair(-6, 34), Pair(-54, 15), Pair(-35, 61), Pair(-3, -5),
        Pair(3, 12), Pair(1, 1), Pair(-13, 31), Pair(4, 14), Pair(-8, 12), Pair(2, 5), Pair(2, 11), Pair(-8, 28),
        Pair(3, 7), Pair(4, 7), Pair(5, 0), Pair(-2, 14), Pair(14, 1), Pair(-5, 17), Pair(-5, 10), Pair(10, -9),
        Pair(6, 10), Pair(2, 7), Pair(1, 17), Pair(-9, 10), Pair(12, 24), Pair(-15, 5), Pair(-1, 3), Pair(0, 8),
        Pair(6, 4), Pair(0, -47), Pair(1, 6), Pair(0, 5), Pair(8, 29), Pair(-6, 8), Pair(-4, 13), Pair(-1, 10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-57, 46), Pair(-47, -34), Pair(-87, 70), Pair(12, -88), Pair(49, -30), Pair(-37, 3), Pair(-105, -52), Pair(-4, -12),
        Pair(18, -42), Pair(27, -25), Pair(-19, 48), Pair(30, 34), Pair(-7, 102), Pair(6, 21), Pair(-23, -37), Pair(-37, -1),
        Pair(42, 23), Pair(28, 37), Pair(-39, 1), Pair(-16, 17), Pair(65, -6), Pair(34, -10), Pair(113, -100), Pair(15, -19),
        Pair(18, 51), Pair(-10, 38), Pair(14, 12), Pair(2, 21), Pair(-2, 73), Pair(-20, -1), Pair(-6, -5), Pair(-46, 31),
        Pair(-6, -28), Pair(-22, 11), Pair(-9, 50), Pair(-4, -2), Pair(-2, 41), Pair(5, 8), Pair(30, 10), Pair(23, 14),
        Pair(-5, -18), Pair(2, 26), Pair(6, 19), Pair(16, -6), Pair(-3, -8), Pair(0, 24), Pair(9, 0), Pair(-14, 0),
        Pair(56, -96), Pair(26, 31), Pair(37, 4), Pair(-52, -35), Pair(-7, 33), Pair(1, -19), Pair(-45, 70), Pair(3, -9),
        Pair(-118, -69), Pair(1, -27), Pair(24, -40), Pair(19, 70), Pair(39, 10), Pair(12, -5), Pair(-4, 24), Pair(-36, -4)
      },
      { // Piece 2
        Pair(-16, -3), Pair(-42, -45), Pair(-60, -36), Pair(-144, 9), Pair(82, -52), Pair(-58, 4), Pair(30, -24), Pair(14, 7),
        Pair(28, -14), Pair(-20, 63), Pair(-10, 12), Pair(24, -32), Pair(177, -91), Pair(2, -56), Pair(4, 30), Pair(9, 14),
        Pair(47, -10), Pair(56, 16), Pair(4, -3), Pair(38, -2), Pair(54, -40), Pair(-19, 57), Pair(-23, 42), Pair(-26, 41),
        Pair(25, 22), Pair(23, -24), Pair(-30, 27), Pair(-11, 35), Pair(-4, -10), Pair(-47, -47), Pair(84, -1), Pair(-29, -57),
        Pair(-21, -46), Pair(-7, 14), Pair(3, 21), Pair(-16, 38), Pair(30, -15), Pair(41, 37), Pair(37, 51), Pair(25, 47),
        Pair(14, -6), Pair(-60, -23), Pair(-1, 28), Pair(-8, -10), Pair(-18, 3), Pair(7, 39), Pair(-13, 22), Pair(-22, -25),
        Pair(6, -7), Pair(2, -3), Pair(-5, -79), Pair(-160, 61), Pair(3, 19), Pair(-136, 8), Pair(0, 30), Pair(-126, -3),
        Pair(-20, -6), Pair(29, -4), Pair(-8, -46), Pair(-8, 7), Pair(34, 70), Pair(-7, 20), Pair(3, -31), Pair(-32, -16)
      },
      { // Piece 3
        Pair(35, 4), Pair(-24, 95), Pair(-2, 20), Pair(63, -53), Pair(108, 14), Pair(37, 48), Pair(23, 17), Pair(-43, 28),
        Pair(8, 29), Pair(-27, 32), Pair(-68, 68), Pair(1, 16), Pair(25, 6), Pair(-10, -54), Pair(-40, 49), Pair(53, -32),
        Pair(37, 29), Pair(22, -31), Pair(44, 9), Pair(-7, 17), Pair(-56, -15), Pair(-56, 33), Pair(45, -19), Pair(46, -4),
        Pair(3, 20), Pair(-3, 20), Pair(12, -15), Pair(-35, 2), Pair(3, 37), Pair(-9, 1), Pair(7, 16), Pair(-22, 17),
        Pair(36, 71), Pair(-3, 39), Pair(30, 35), Pair(34, -33), Pair(25, -7), Pair(7, 14), Pair(28, 41), Pair(1, 21),
        Pair(-13, 42), Pair(1, 38), Pair(-13, -13), Pair(37, -7), Pair(-10, 40), Pair(0, 11), Pair(-26, 9), Pair(12, 66),
        Pair(7, -49), Pair(25, 13), Pair(25, -35), Pair(-33, -37), Pair(5, 22), Pair(-3, 21), Pair(47, 12), Pair(13, -43),
        Pair(-3, 4), Pair(-5, 21), Pair(-3, 2), Pair(-12, 19), Pair(-5, -17), Pair(2, 9), Pair(-4, 17), Pair(2, 9)
      },
      { // Piece 4
        Pair(-123, 109), Pair(-9, 83), Pair(23, -58), Pair(3, -141), Pair(-71, 44), Pair(11, 4), Pair(-27, 15), Pair(-151, -89),
        Pair(-24, 8), Pair(-38, 31), Pair(3, 92), Pair(28, -40), Pair(31, 25), Pair(24, 28), Pair(-66, 47), Pair(-17, -81),
        Pair(6, -12), Pair(-41, 149), Pair(-2, 23), Pair(-54, 18), Pair(17, -20), Pair(32, 10), Pair(37, 102), Pair(-81, 108),
        Pair(18, -18), Pair(-34, 59), Pair(-8, -16), Pair(-1, 16), Pair(-21, -17), Pair(6, 9), Pair(-23, 23), Pair(16, -38),
        Pair(-24, -1), Pair(26, -62), Pair(27, -33), Pair(-18, 26), Pair(23, 36), Pair(-37, 53), Pair(-6, 27), Pair(-22, 65),
        Pair(11, 10), Pair(7, -38), Pair(45, -69), Pair(-15, 19), Pair(5, -55), Pair(4, 9), Pair(-1, 31), Pair(14, -37),
        Pair(-20, 42), Pair(-5, 11), Pair(2, 19), Pair(-72, 76), Pair(-5, 8), Pair(10, -27), Pair(-3, 2), Pair(-82, 206),
        Pair(17, -39), Pair(10, -6), Pair(16, -30), Pair(-5, -3), Pair(21, -3), Pair(66, -77), Pair(36, 44), Pair(61, -81)
      },
      { // Piece 5
        Pair(10, 36), Pair(7, 43), Pair(6, 94), Pair(80, 82), Pair(12, 31), Pair(-5, -75), Pair(-50, -47), Pair(-20, -68),
        Pair(-9, 37), Pair(-14, 0), Pair(87, 118), Pair(10, 22), Pair(33, 176), Pair(53, 54), Pair(-2, -33), Pair(0, 10),
        Pair(-4, 40), Pair(32, 59), Pair(107, 132), Pair(63, 37), Pair(83, 34), Pair(-6, 24), Pair(28, 17), Pair(13, 38),
        Pair(-3, 22), Pair(58, -40), Pair(97, 50), Pair(71, 14), Pair(113, 46), Pair(9, -21), Pair(-86, -1), Pair(57, -44),
        Pair(88, 39), Pair(-89, 69), Pair(47, 26), Pair(36, 24), Pair(69, 51), Pair(-50, 17), Pair(-11, -18), Pair(-88, 32),
        Pair(81, 1), Pair(76, -24), Pair(41, -18), Pair(-4, 24), Pair(-69, -1), Pair(-67, 32), Pair(22, -19), Pair(-55, -16),
        Pair(78, -7), Pair(-25, 54), Pair(-48, 22), Pair(-92, 42), Pair(-7, -2), Pair(15, -21), Pair(-4, -8), Pair(-7, -1),
        Pair(92, -8), Pair(3, 27), Pair(-5, -3), Pair(-61, 19), Pair(-1, -11), Pair(-5, -6), Pair(3, -10), Pair(1, -34)
      }
    }},
    {{ // Bucket 52
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-49, -15), Pair(0, 12), Pair(6, 20), Pair(37, -42), Pair(-40, 26), Pair(12, 113), Pair(-142, 69), Pair(-119, 53),
        Pair(-4, -9), Pair(5, -14), Pair(-9, 26), Pair(-49, -6), Pair(-25, 73), Pair(-91, 13), Pair(-54, 19), Pair(-12, -10),
        Pair(-4, 15), Pair(7, -2), Pair(0, 11), Pair(-19, 15), Pair(7, 8), Pair(-3, 10), Pair(4, -6), Pair(1, 3),
        Pair(-6, 12), Pair(-1, 16), Pair(-5, 15), Pair(0, 1), Pair(5, -14), Pair(11, 2), Pair(1, 14), Pair(0, 10),
        Pair(-2, 5), Pair(-2, 15), Pair(-8, 12), Pair(3, 27), Pair(-2, -2), Pair(-2, 17), Pair(2, 8), Pair(0, 4),
        Pair(-4, 5), Pair(-2, 12), Pair(-1, -3), Pair(6, 28), Pair(-1, 3), Pair(3, 13), Pair(-3, -27), Pair(5, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-43, 57), Pair(-49, 11), Pair(-10, -34), Pair(118, 1), Pair(-1, 18), Pair(-55, 2), Pair(35, 0), Pair(-133, 24),
        Pair(42, -53), Pair(47, -38), Pair(8, 12), Pair(-31, 32), Pair(45, 28), Pair(22, 4), Pair(0, -9), Pair(-23, 49),
        Pair(24, -34), Pair(26, 46), Pair(-4, 11), Pair(11, -3), Pair(-5, 57), Pair(-12, 22), Pair(0, 13), Pair(-43, -11),
        Pair(23, -7), Pair(15, 26), Pair(10, -5), Pair(11, 7), Pair(-15, 9), Pair(-3, 10), Pair(4, -3), Pair(0, -3),
        Pair(9, 41), Pair(-9, 57), Pair(3, 7), Pair(-5, 49), Pair(-4, 41), Pair(13, 23), Pair(-13, 20), Pair(-9, 8),
        Pair(26, 26), Pair(6, 36), Pair(7, 24), Pair(-8, 29), Pair(-1, 25), Pair(1, 35), Pair(2, 33), Pair(8, 9),
        Pair(-21, 57), Pair(-4, -2), Pair(-24, 44), Pair(6, 14), Pair(25, 5), Pair(-11, 43), Pair(-1, -1), Pair(3, -1),
        Pair(-68, 32), Pair(10, 42), Pair(-18, 33), Pair(-4, -4), Pair(-2, 58), Pair(-2, 8), Pair(4, 24), Pair(-103, -50)
      },
      { // Piece 2
        Pair(12, 0), Pair(-89, 52), Pair(-2, -2), Pair(-32, -18), Pair(-38, 15), Pair(36, -25), Pair(44, 49), Pair(106, 46),
        Pair(-21, 61), Pair(-5, 2), Pair(-48, 19), Pair(38, -14), Pair(37, -59), Pair(-124, 60), Pair(-1, 77), Pair(-45, -2),
        Pair(-24, 24), Pair(-8, -2), Pair(-6, -5), Pair(31, -37), Pair(-1, -23), Pair(-139, 13), Pair(-27, 6), Pair(4, -9),
        Pair(-23, 5), Pair(49, -10), Pair(-3, -12), Pair(0, -10), Pair(-2, 36), Pair(-8, 1), Pair(3, -13), Pair(-2, -29),
        Pair(-68, 19), Pair(9, -48), Pair(27, -2), Pair(-16, 10), Pair(-10, 11), Pair(10, -7), Pair(1, -25), Pair(-13, 7),
        Pair(9, 6), Pair(-19, 15), Pair(0, -2), Pair(-12, 18), Pair(-6, -21), Pair(-8, 49), Pair(-40, -2), Pair(-8, -11),
        Pair(-14, 53), Pair(5, -4), Pair(163, -46), Pair(1, -15), Pair(-27, -7), Pair(20, 35), Pair(-5, -6), Pair(-1, -13),
        Pair(11, -8), Pair(-29, 18), Pair(3, 3), Pair(42, -153), Pair(42, 17), Pair(-5, -31), Pair(31, -39), Pair(14, -2)
      },
      { // Piece 3
        Pair(39, -3), Pair(27, 10), Pair(-51, -5), Pair(15, -13), Pair(131, -21), Pair(-16, 92), Pair(-19, 17), Pair(19, -21),
        Pair(-1, 12), Pair(-11, 15), Pair(19, -34), Pair(-44, 42), Pair(3, 12), Pair(-24, 6), Pair(-43, 8), Pair(51, -10),
        Pair(19, 19), Pair(39, -11), Pair(-38, 39), Pair(25, 25), Pair(49, -17), Pair(-48, 8), Pair(16, -42), Pair(-7, 12),
        Pair(-14, 6), Pair(12, 52), Pair(34, 18), Pair(-34, 36), Pair(-24, 14), Pair(34, 1), Pair(-37, 66), Pair(-5, 2),
        Pair(-8, 44), Pair(21, 21), Pair(17, 23), Pair(2, -2), Pair(-8, -11), Pair(37, -41), Pair(-51, 32), Pair(-38, 18),
        Pair(33, -3), Pair(20, -28), Pair(10, 27), Pair(8, -2), Pair(-4, 24), Pair(10, -19), Pair(-54, 81), Pair(14, -11),
        Pair(-31, 44), Pair(-27, 37), Pair(19, -14), Pair(6, 8), Pair(-34, -21), Pair(-35, 29), Pair(13, -84), Pair(-49, 2),
        Pair(0, 3), Pair(-2, 3), Pair(-4, 8), Pair(-3, 1), Pair(-2, -10), Pair(-5, 8), Pair(12, -3), Pair(1, 10)
      },
      { // Piece 4
        Pair(-47, 39), Pair(-32, 50), Pair(-53, 33), Pair(4, -43), Pair(11, -15), Pair(40, -35), Pair(57, -5), Pair(-70, 47),
        Pair(-10, -12), Pair(-55, 87), Pair(14, 27), Pair(13, 10), Pair(-31, 42), Pair(32, 1), Pair(-58, 64), Pair(-62, -7),
        Pair(-13, 61), Pair(-51, 24), Pair(-16, -12), Pair(-6, 71), Pair(25, -76), Pair(-28, 30), Pair(-5, 31), Pair(-11, 5),
        Pair(1, -8), Pair(0, 18), Pair(14, -1), Pair(-9, 0), Pair(10, 1), Pair(7, 78), Pair(-17, 55), Pair(-2, -1),
        Pair(1, -4), Pair(12, -15), Pair(-6, -6), Pair(-5, 60), Pair(-13, 52), Pair(-9, 13), Pair(-12, 68), Pair(30, 31),
        Pair(18, 22), Pair(7, 20), Pair(-10, 25), Pair(-3, 27), Pair(-5, 19), Pair(29, 16), Pair(-2, -68), Pair(-35, 26),
        Pair(27, -24), Pair(-1, -16), Pair(7, 0), Pair(-4, 8), Pair(76, -63), Pair(17, 17), Pair(8, -33), Pair(-41, 96),
        Pair(-4, 26), Pair(29, 1), Pair(-2, -40), Pair(-3, -2), Pair(2, -13), Pair(-29, -14), Pair(0, 53), Pair(56, 45)
      },
      { // Piece 5
        Pair(19, 45), Pair(11, 32), Pair(10, 72), Pair(9, 116), Pair(-16, -21), Pair(23, 77), Pair(31, 68), Pair(-6, 2),
        Pair(-19, -52), Pair(-6, 53), Pair(-38, 76), Pair(-27, 45), Pair(12, -44), Pair(38, 131), Pair(38, 129), Pair(-12, -84),
        Pair(-29, 65), Pair(-23, -70), Pair(2, -15), Pair(-56, 30), Pair(33, 27), Pair(-61, 60), Pair(-4, 7), Pair(40, 31),
        Pair(-40, -82), Pair(6, -19), Pair(73, 32), Pair(-73, 79), Pair(-80, 53), Pair(22, -11), Pair(76, 32), Pair(-20, 23),
        Pair(71, 41), Pair(28, -10), Pair(-8, 60), Pair(33, -12), Pair(87, -9), Pair(87, -6), Pair(-66, 12), Pair(135, -48),
        Pair(-28, -16), Pair(-55, -1), Pair(52, -33), Pair(-44, 45), Pair(-23, 12), Pair(4, 0), Pair(13, 20), Pair(44, -30),
        Pair(-46, 2), Pair(-30, 30), Pair(42, 8), Pair(-42, 1), Pair(-189, 89), Pair(-55, 20), Pair(15, -11), Pair(13, 9),
        Pair(0, -12), Pair(-31, 7), Pair(-14, 12), Pair(-31, 35), Pair(-29, 16), Pair(-9, 5), Pair(4, -7), Pair(11, -15)
      }
    }},
    {{ // Bucket 53
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-7, -11), Pair(-19, -17), Pair(-6, -22), Pair(-26, 4), Pair(-4, -34), Pair(8, -4), Pair(-65, 64), Pair(-71, 77),
        Pair(0, 5), Pair(-14, 5), Pair(-10, -13), Pair(-7, -10), Pair(-22, -2), Pair(-16, 16), Pair(-65, 14), Pair(9, 3),
        Pair(-5, 10), Pair(6, -2), Pair(3, 6), Pair(1, -3), Pair(-14, 10), Pair(-2, 29), Pair(-17, 21), Pair(-4, 6),
        Pair(-2, 7), Pair(3, 7), Pair(0, 4), Pair(1, 6), Pair(4, 5), Pair(11, 8), Pair(8, 10), Pair(6, 1),
        Pair(-1, 6), Pair(0, 9), Pair(0, 8), Pair(-5, 6), Pair(8, 17), Pair(6, 1), Pair(9, 10), Pair(1, 2),
        Pair(0, 9), Pair(1, 8), Pair(-4, 8), Pair(-6, 9), Pair(3, 13), Pair(2, 2), Pair(3, 4), Pair(2, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(60, 9), Pair(8, -34), Pair(60, -14), Pair(65, 11), Pair(12, -21), Pair(22, -25), Pair(46, -17), Pair(-130, 35),
        Pair(8, 1), Pair(-28, 14), Pair(3, 7), Pair(5, 1), Pair(-25, 25), Pair(-2, 21), Pair(6, 32), Pair(-20, 6),
        Pair(-25, 12), Pair(14, 12), Pair(-7, 12), Pair(0, 10), Pair(0, -7), Pair(0, 28), Pair(4, 12), Pair(-9, 2),
        Pair(6, 3), Pair(7, 9), Pair(13, 10), Pair(-14, 20), Pair(4, 14), Pair(-8, 9), Pair(-3, 19), Pair(-27, 8),
        Pair(-4, 19), Pair(-11, 22), Pair(6, 11), Pair(12, 10), Pair(1, 8), Pair(-5, 21), Pair(-16, 32), Pair(-9, -4),
        Pair(1, 18), Pair(9, 5), Pair(3, 10), Pair(4, 18), Pair(6, 11), Pair(0, -1), Pair(3, 21), Pair(-17, -4),
        Pair(6, -5), Pair(20, 19), Pair(6, 17), Pair(3, 14), Pair(0, 12), Pair(-152, 73), Pair(-16, 18), Pair(-8, 3),
        Pair(23, -35), Pair(14, 13), Pair(13, 5), Pair(0, 2), Pair(13, 6), Pair(-7, 22), Pair(-4, -14), Pair(-131, 109)
      },
      { // Piece 2
        Pair(-8, -13), Pair(13, 27), Pair(74, 8), Pair(14, -14), Pair(68, -18), Pair(-30, -16), Pair(32, -21), Pair(-18, -34),
        Pair(7, -6), Pair(-3, -10), Pair(3, -12), Pair(-9, -26), Pair(-7, -14), Pair(-22, -14), Pair(-25, 9), Pair(6, -45),
        Pair(8, -7), Pair(0, 1), Pair(20, -21), Pair(29, -16), Pair(-6, -9), Pair(-32, -6), Pair(-1, -3), Pair(-33, 11),
        Pair(3, -18), Pair(11, -18), Pair(7, -3), Pair(11, -4), Pair(-10, -17), Pair(11, 4), Pair(-4, -11), Pair(-12, 13),
        Pair(5, 6), Pair(-9, -15), Pair(4, -2), Pair(3, 9), Pair(11, -12), Pair(-3, 0), Pair(7, 0), Pair(-19, -29),
        Pair(-4, 9), Pair(6, 6), Pair(-7, 1), Pair(-2, 5), Pair(3, 21), Pair(1, -5), Pair(-8, -1), Pair(1, -5),
        Pair(8, 1), Pair(-1, 8), Pair(1, 1), Pair(-5, 3), Pair(11, -4), Pair(-48, 112), Pair(5, 11), Pair(-16, -1),
        Pair(6, 8), Pair(5, 4), Pair(2, 7), Pair(14, -6), Pair(-9, 13), Pair(8, 9), Pair(-30, -72), Pair(25, -66)
      },
      { // Piece 3
        Pair(24, 10), Pair(15, 20), Pair(23, 0), Pair(7, 19), Pair(20, 17), Pair(87, -1), Pair(44, 7), Pair(67, -18),
        Pair(14, 10), Pair(-5, 8), Pair(10, 5), Pair(21, 7), Pair(-18, 13), Pair(-5, 5), Pair(-26, 34), Pair(15, 11),
        Pair(13, 7), Pair(22, 3), Pair(18, 4), Pair(21, 3), Pair(-5, 9), Pair(73, -10), Pair(-2, -11), Pair(11, 7),
        Pair(8, 13), Pair(17, 3), Pair(10, 9), Pair(9, 16), Pair(10, 15), Pair(59, 4), Pair(28, -5), Pair(20, 9),
        Pair(8, 7), Pair(15, 6), Pair(3, 15), Pair(6, 20), Pair(12, 10), Pair(19, 2), Pair(26, 3), Pair(29, -7),
        Pair(4, 6), Pair(9, 6), Pair(10, 1), Pair(7, 0), Pair(-5, 6), Pair(16, 6), Pair(-19, 21), Pair(-13, 30),
        Pair(-19, 19), Pair(15, -13), Pair(-3, -1), Pair(-1, -1), Pair(-3, 2), Pair(162, -71), Pair(-14, -44), Pair(-37, 20),
        Pair(3, 7), Pair(9, 13), Pair(8, 12), Pair(3, 6), Pair(0, 8), Pair(-2, 2), Pair(-3, -5), Pair(-4, 4)
      },
      { // Piece 4
        Pair(-1, 16), Pair(14, 34), Pair(-4, -13), Pair(25, -25), Pair(34, 0), Pair(12, -18), Pair(22, 17), Pair(6, -7),
        Pair(-13, 8), Pair(1, 4), Pair(-38, 24), Pair(34, 9), Pair(7, -8), Pair(-12, -27), Pair(8, 16), Pair(-15, 2),
        Pair(-13, 37), Pair(-9, -5), Pair(14, 31), Pair(-14, 7), Pair(-30, 26), Pair(-34, 30), Pair(0, 58), Pair(-27, 25),
        Pair(0, 34), Pair(1, 27), Pair(1, 34), Pair(3, 20), Pair(-12, 6), Pair(-11, 16), Pair(-28, 5), Pair(-16, 29),
        Pair(5, 31), Pair(-2, 23), Pair(9, 26), Pair(-1, 21), Pair(9, 6), Pair(-3, 14), Pair(-10, 17), Pair(-21, 0),
        Pair(14, 2), Pair(6, 32), Pair(5, 17), Pair(0, 20), Pair(6, 17), Pair(-3, 4), Pair(-15, 23), Pair(-12, 14),
        Pair(12, -3), Pair(8, 17), Pair(9, 17), Pair(3, 11), Pair(2, 14), Pair(31, 62), Pair(7, 1), Pair(-17, -39),
        Pair(12, 19), Pair(-1, 17), Pair(12, 12), Pair(3, 11), Pair(-1, 5), Pair(-5, -7), Pair(22, 31), Pair(-7, 15)
      },
      { // Piece 5
        Pair(-20, -76), Pair(22, 20), Pair(-25, 43), Pair(65, 96), Pair(10, -48), Pair(14, 113), Pair(-31, 41), Pair(-32, 31),
        Pair(-116, 12), Pair(56, 10), Pair(-81, 73), Pair(90, 43), Pair(-77, 70), Pair(-66, 56), Pair(-33, 72), Pair(-66, 21),
        Pair(-54, -36), Pair(31, -8), Pair(-53, 32), Pair(-58, 99), Pair(15, 36), Pair(-20, 43), Pair(103, 85), Pair(16, 35),
        Pair(-177, 55), Pair(-52, -1), Pair(-123, 33), Pair(-95, 45), Pair(-72, 29), Pair(-56, 45), Pair(8, 28), Pair(-3, 11),
        Pair(-104, 0), Pair(81, -7), Pair(-84, 28), Pair(15, 12), Pair(21, 7), Pair(-43, 23), Pair(41, 2), Pair(-7, 3),
        Pair(-140, 22), Pair(-35, -1), Pair(-38, 16), Pair(-38, 24), Pair(10, 20), Pair(5, 3), Pair(-23, 6), Pair(13, 2),
        Pair(-21, 8), Pair(-26, 21), Pair(-9, -2), Pair(-20, 10), Pair(9, -10), Pair(-12, 17), Pair(21, -10), Pair(16, 2),
        Pair(15, -28), Pair(-16, 3), Pair(7, -12), Pair(-4, 18), Pair(-6, -13), Pair(-39, 13), Pair(4, 4), Pair(10, 7)
      }
    }},
    {{ // Bucket 54
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-19, -11), Pair(-47, 15), Pair(-9, -33), Pair(-2, -5), Pair(53, 36), Pair(-18, 6), Pair(-35, -7), Pair(-85, 10),
        Pair(-5, 2), Pair(-3, -8), Pair(-7, 27), Pair(2, 2), Pair(8, 12), Pair(-22, 16), Pair(28, -24), Pair(-15, 28),
        Pair(1, 8), Pair(5, 1), Pair(6, 5), Pair(1, -4), Pair(-7, -2), Pair(-17, 11), Pair(-20, 20), Pair(-6, 4),
        Pair(-1, 9), Pair(0, 9), Pair(1, 5), Pair(-2, 7), Pair(5, 4), Pair(0, 4), Pair(8, 0), Pair(2, 3),
        Pair(-1, 9), Pair(-1, 11), Pair(1, 10), Pair(2, 5), Pair(3, 5), Pair(7, 10), Pair(-5, 9), Pair(6, 5),
        Pair(-1, 9), Pair(2, 9), Pair(-2, 7), Pair(-5, 13), Pair(-9, -22), Pair(4, 4), Pair(2, 0), Pair(-1, -5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-73, 72), Pair(59, 19), Pair(49, 16), Pair(33, 3), Pair(-85, -6), Pair(-36, 23), Pair(-21, 85), Pair(75, -91),
        Pair(-34, -16), Pair(-10, 18), Pair(9, 5), Pair(5, 34), Pair(-18, 7), Pair(53, -2), Pair(18, 7), Pair(95, -17),
        Pair(-51, 43), Pair(-3, 2), Pair(-2, 19), Pair(-7, 14), Pair(16, 13), Pair(-2, -3), Pair(-8, 17), Pair(1, -36),
        Pair(9, -7), Pair(6, 13), Pair(14, 0), Pair(6, 23), Pair(10, 7), Pair(19, 2), Pair(10, -12), Pair(-16, 20),
        Pair(3, 8), Pair(-4, 31), Pair(4, 17), Pair(1, 13), Pair(7, 16), Pair(8, 15), Pair(4, -19), Pair(6, 29),
        Pair(-9, 0), Pair(4, -2), Pair(3, 11), Pair(3, 13), Pair(-3, 9), Pair(5, 12), Pair(3, -9), Pair(-1, 8),
        Pair(-21, 9), Pair(-2, 28), Pair(-9, 20), Pair(0, 9), Pair(2, 6), Pair(-21, 10), Pair(75, 11), Pair(-3, -3),
        Pair(-36, 62), Pair(-13, -1), Pair(-7, 9), Pair(-9, 29), Pair(-1, 2), Pair(7, -16), Pair(-5, 18), Pair(29, 32)
      },
      { // Piece 2
        Pair(-39, -6), Pair(35, -13), Pair(-78, 1), Pair(-8, 4), Pair(41, -27), Pair(44, -22), Pair(43, -40), Pair(44, 16),
        Pair(-12, 13), Pair(8, -3), Pair(1, -1), Pair(18, -43), Pair(26, -23), Pair(30, -24), Pair(-19, 3), Pair(-14, 8),
        Pair(5, -3), Pair(13, -16), Pair(25, -13), Pair(27, -20), Pair(-3, -3), Pair(36, 6), Pair(1, -23), Pair(-2, 16),
        Pair(-16, -3), Pair(4, -10), Pair(14, -2), Pair(-27, 1), Pair(3, 6), Pair(-28, -15), Pair(-3, -19), Pair(-6, 4),
        Pair(1, 5), Pair(-5, -2), Pair(-4, 8), Pair(5, 0), Pair(-4, 14), Pair(1, -2), Pair(-8, 2), Pair(0, 7),
        Pair(9, 2), Pair(7, -1), Pair(-4, 14), Pair(-3, 10), Pair(2, 9), Pair(-5, 4), Pair(-3, -6), Pair(-44, -14),
        Pair(10, -10), Pair(1, 9), Pair(-10, -6), Pair(1, 10), Pair(-5, -1), Pair(9, -11), Pair(-85, 2), Pair(-3, -29),
        Pair(19, -7), Pair(13, -9), Pair(4, 16), Pair(-10, -4), Pair(2, -7), Pair(-12, 3), Pair(18, 13), Pair(82, 35)
      },
      { // Piece 3
        Pair(25, 21), Pair(37, -2), Pair(-2, 9), Pair(33, 10), Pair(-1, 5), Pair(-11, 24), Pair(4, 4), Pair(88, -11),
        Pair(13, 9), Pair(-4, 9), Pair(7, 10), Pair(12, 3), Pair(27, -2), Pair(23, 12), Pair(62, -47), Pair(-27, 30),
        Pair(17, 16), Pair(33, 5), Pair(25, 5), Pair(1, 5), Pair(4, 12), Pair(-11, 16), Pair(74, -25), Pair(-27, 24),
        Pair(4, 13), Pair(12, 19), Pair(8, 1), Pair(26, 4), Pair(10, 2), Pair(3, 7), Pair(5, 9), Pair(-18, 18),
        Pair(1, 15), Pair(13, 17), Pair(0, 14), Pair(2, 24), Pair(3, -1), Pair(10, 6), Pair(70, -27), Pair(29, 7),
        Pair(9, 21), Pair(-7, 6), Pair(10, 21), Pair(4, 4), Pair(10, -4), Pair(11, 12), Pair(26, 6), Pair(-27, -12),
        Pair(1, 17), Pair(16, 17), Pair(11, 12), Pair(-3, 7), Pair(9, 9), Pair(1, 1), Pair(125, -35), Pair(-35, 24),
        Pair(5, 14), Pair(7, 5), Pair(7, 7), Pair(5, 8), Pair(6, 6), Pair(0, 9), Pair(-16, -7), Pair(-15, -5)
      },
      { // Piece 4
        Pair(-11, 4), Pair(33, -15), Pair(-59, 35), Pair(18, -17), Pair(74, -36), Pair(64, -28), Pair(-20, -4), Pair(50, -26),
        Pair(-19, 28), Pair(6, 15), Pair(10, -12), Pair(7, 45), Pair(1, -12), Pair(1, 3), Pair(-31, 28), Pair(46, -9),
        Pair(-17, 22), Pair(21, 43), Pair(-1, 23), Pair(-17, 47), Pair(-8, -3), Pair(68, -37), Pair(-10, -2), Pair(7, 6),
        Pair(3, 18), Pair(-1, 30), Pair(13, -20), Pair(21, 13), Pair(-3, 30), Pair(-16, 6), Pair(13, -9), Pair(4, -23),
        Pair(-3, 16), Pair(-1, 28), Pair(0, 22), Pair(-2, 0), Pair(13, 11), Pair(-15, 30), Pair(9, 10), Pair(-10, 12),
        Pair(18, 3), Pair(13, 9), Pair(1, 30), Pair(6, 8), Pair(5, 10), Pair(5, 10), Pair(2, 18), Pair(-8, -3),
        Pair(14, 36), Pair(11, 19), Pair(7, 18), Pair(7, 18), Pair(7, 24), Pair(0, 1), Pair(1, -21), Pair(-14, 60),
        Pair(21, 27), Pair(15, 27), Pair(5, 11), Pair(5, 13), Pair(1, 19), Pair(24, -5), Pair(-29, 65), Pair(56, -21)
      },
      { // Piece 5
        Pair(-10, -9), Pair(-42, 55), Pair(-51, 22), Pair(-4, 27), Pair(19, 30), Pair(73, 86), Pair(9, 69), Pair(1, 26),
        Pair(-117, 8), Pair(77, -27), Pair(23, 77), Pair(-14, -25), Pair(-24, 46), Pair(18, 126), Pair(25, 74), Pair(-62, 111),
        Pair(-22, -21), Pair(26, -17), Pair(27, -3), Pair(-162, 88), Pair(-74, 52), Pair(-88, 76), Pair(-49, 43), Pair(-16, 34),
        Pair(-130, 41), Pair(-109, -9), Pair(-17, 22), Pair(-61, 49), Pair(-53, 44), Pair(-141, 45), Pair(-19, 52), Pair(-31, 22),
        Pair(18, 34), Pair(-76, 44), Pair(-52, 20), Pair(-43, 17), Pair(-75, 34), Pair(-56, 26), Pair(14, 30), Pair(-10, 30),
        Pair(-76, 30), Pair(-66, 8), Pair(-16, 12), Pair(19, 19), Pair(36, -3), Pair(0, 20), Pair(4, 16), Pair(-1, -3),
        Pair(-46, -9), Pair(-40, 2), Pair(-25, 3), Pair(-24, 16), Pair(-11, -1), Pair(0, -15), Pair(-2, 66), Pair(3, -5),
        Pair(-28, -43), Pair(-30, 5), Pair(-20, 12), Pair(13, 4), Pair(17, -3), Pair(-6, -5), Pair(3, 0), Pair(-9, -27)
      }
    }},
    {{ // Bucket 55
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-69, 24), Pair(-61, 10), Pair(-25, 0), Pair(-34, 17), Pair(-31, -21), Pair(-29, -38), Pair(46, -12), Pair(-43, 7),
        Pair(3, -2), Pair(1, 4), Pair(-1, -2), Pair(1, -17), Pair(-15, -21), Pair(-9, -6), Pair(26, -3), Pair(-7, 10),
        Pair(1, 8), Pair(3, 0), Pair(9, -7), Pair(3, 6), Pair(0, 1), Pair(-7, 2), Pair(-27, 19), Pair(35, 3),
        Pair(-1, 6), Pair(-2, 6), Pair(-1, 5), Pair(1, 3), Pair(1, 4), Pair(-1, 3), Pair(11, -1), Pair(5, 10),
        Pair(-2, 9), Pair(2, 7), Pair(0, 8), Pair(0, 4), Pair(4, 4), Pair(2, 1), Pair(0, 6), Pair(-3, 7),
        Pair(0, 8), Pair(2, 5), Pair(-1, 9), Pair(0, 13), Pair(5, 2), Pair(3, 1), Pair(-1, -5), Pair(-3, -7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(49, 47), Pair(-40, 18), Pair(-42, 23), Pair(26, -32), Pair(42, 16), Pair(-45, 15), Pair(51, 52), Pair(67, 21),
        Pair(-10, 1), Pair(-24, 44), Pair(-15, 9), Pair(-24, 4), Pair(4, 4), Pair(-13, 21), Pair(-23, 49), Pair(15, -11),
        Pair(-7, 12), Pair(0, 13), Pair(-6, -7), Pair(6, -11), Pair(2, 1), Pair(43, -34), Pair(1, -24), Pair(68, -41),
        Pair(6, 23), Pair(-2, 10), Pair(-3, 15), Pair(8, 13), Pair(2, 3), Pair(-2, 2), Pair(-3, 4), Pair(12, 3),
        Pair(-8, 1), Pair(2, -1), Pair(8, 6), Pair(8, 0), Pair(2, 22), Pair(1, 3), Pair(2, 27), Pair(1, -6),
        Pair(-4, 17), Pair(-1, 9), Pair(-1, 11), Pair(3, 12), Pair(6, 11), Pair(0, 7), Pair(3, 9), Pair(-17, -28),
        Pair(-29, 13), Pair(0, 12), Pair(-1, -3), Pair(2, 10), Pair(-5, 7), Pair(2, -21), Pair(0, -35), Pair(8, 18),
        Pair(-90, 40), Pair(-8, -4), Pair(-21, 30), Pair(-34, 21), Pair(-11, 16), Pair(-3, 2), Pair(-12, -6), Pair(-19, 16)
      },
      { // Piece 2
        Pair(35, -4), Pair(-54, 9), Pair(-19, 5), Pair(-119, 9), Pair(51, -24), Pair(-20, -1), Pair(-39, 16), Pair(37, -16),
        Pair(-2, -1), Pair(-4, -13), Pair(6, -7), Pair(44, -20), Pair(4, 9), Pair(-7, -14), Pair(54, -27), Pair(3, 13),
        Pair(6, -8), Pair(-12, 1), Pair(-3, -10), Pair(-14, -18), Pair(-3, 6), Pair(4, 7), Pair(-12, -11), Pair(17, -7),
        Pair(-6, 14), Pair(3, 6), Pair(-6, -8), Pair(11, -6), Pair(5, -17), Pair(14, -12), Pair(-4, 3), Pair(-3, -1),
        Pair(15, -3), Pair(10, 0), Pair(9, -9), Pair(6, 1), Pair(9, 4), Pair(-8, 9), Pair(-7, 12), Pair(-1, 6),
        Pair(-4, -3), Pair(-5, 11), Pair(2, 10), Pair(2, 10), Pair(-4, 16), Pair(-4, 2), Pair(-6, 15), Pair(-4, -5),
        Pair(11, 23), Pair(1, 11), Pair(4, -2), Pair(-3, 0), Pair(-3, 14), Pair(-13, 20), Pair(4, -1), Pair(35, -127),
        Pair(1, 14), Pair(10, -26), Pair(-3, 8), Pair(-3, 0), Pair(10, -9), Pair(1, 6), Pair(67, -4), Pair(19, -45)
      },
      { // Piece 3
        Pair(33, 25), Pair(9, 19), Pair(22, 19), Pair(-10, 25), Pair(4, 8), Pair(-39, 20), Pair(-20, 21), Pair(54, -22),
        Pair(7, 22), Pair(1, 4), Pair(17, 17), Pair(-12, 21), Pair(14, 5), Pair(2, 28), Pair(-59, 48), Pair(-38, 0),
        Pair(-4, 24), Pair(11, 13), Pair(9, 27), Pair(-1, 9), Pair(9, -3), Pair(-1, 10), Pair(24, 10), Pair(12, -9),
        Pair(-13, 33), Pair(4, 17), Pair(-5, 1), Pair(10, 13), Pair(7, -2), Pair(28, 2), Pair(-5, 36), Pair(2, 7),
        Pair(10, 11), Pair(-15, 13), Pair(-11, 16), Pair(10, -3), Pair(-2, 17), Pair(5, 6), Pair(-23, 7), Pair(7, -16),
        Pair(10, 6), Pair(-6, 15), Pair(4, 4), Pair(-14, 31), Pair(-11, 20), Pair(2, 7), Pair(-6, 6), Pair(0, -46),
        Pair(-11, 41), Pair(-10, 36), Pair(13, 19), Pair(11, 13), Pair(-24, 28), Pair(-3, 22), Pair(-2, 6), Pair(-102, 46),
        Pair(2, 12), Pair(5, 18), Pair(4, 13), Pair(1, 9), Pair(4, 10), Pair(8, 17), Pair(-16, 17), Pair(-10, -17)
      },
      { // Piece 4
        Pair(13, -4), Pair(25, 24), Pair(28, 14), Pair(3, -21), Pair(-34, 15), Pair(-46, 28), Pair(26, 38), Pair(-86, 48),
        Pair(13, 11), Pair(4, -25), Pair(31, -32), Pair(27, -2), Pair(-21, 30), Pair(1, 12), Pair(-13, 26), Pair(14, -10),
        Pair(-5, 12), Pair(4, -21), Pair(-2, 5), Pair(28, 0), Pair(29, -13), Pair(32, -19), Pair(20, 11), Pair(10, 2),
        Pair(-7, 13), Pair(10, -11), Pair(3, 15), Pair(-10, 17), Pair(-20, 30), Pair(17, 37), Pair(15, -3), Pair(1, -15),
        Pair(7, -3), Pair(-12, 29), Pair(-3, -6), Pair(-1, 10), Pair(-8, 9), Pair(-4, -11), Pair(-12, 14), Pair(8, 21),
        Pair(14, 3), Pair(1, 17), Pair(9, -2), Pair(3, 13), Pair(6, -9), Pair(-3, 8), Pair(4, -5), Pair(-5, -2),
        Pair(19, -57), Pair(-5, -5), Pair(2, 16), Pair(6, -1), Pair(1, -3), Pair(14, -17), Pair(-1, -3), Pair(-156, -85),
        Pair(3, 15), Pair(-4, 24), Pair(8, 7), Pair(2, 12), Pair(1, -8), Pair(-3, -40), Pair(-20, -30), Pair(-49, -36)
      },
      { // Piece 5
        Pair(-27, -35), Pair(-56, 60), Pair(-57, 35), Pair(-22, 138), Pair(-5, 65), Pair(37, 93), Pair(30, 46), Pair(3, -90),
        Pair(15, -32), Pair(-7, 45), Pair(83, 95), Pair(-86, 47), Pair(-69, 62), Pair(-8, 71), Pair(0, 105), Pair(-32, 60),
        Pair(-30, 26), Pair(12, 37), Pair(33, 30), Pair(-75, 21), Pair(-100, 96), Pair(-13, 62), Pair(-81, 75), Pair(-190, 30),
        Pair(120, 16), Pair(-37, 17), Pair(-120, 41), Pair(-68, 47), Pair(-100, 43), Pair(46, 27), Pair(51, 76), Pair(-25, 33),
        Pair(-54, 25), Pair(-25, 15), Pair(-116, 46), Pair(-38, 31), Pair(-80, 38), Pair(-14, 21), Pair(-25, 25), Pair(-83, 28),
        Pair(-137, 34), Pair(-49, 43), Pair(-60, 47), Pair(-15, 26), Pair(21, 24), Pair(24, 13), Pair(20, 13), Pair(4, 0),
        Pair(-25, 19), Pair(-20, 18), Pair(-15, 37), Pair(-6, 19), Pair(0, 17), Pair(3, 9), Pair(-12, -21), Pair(-11, 77),
        Pair(-32, -9), Pair(-21, 22), Pair(-22, 13), Pair(-18, 18), Pair(3, -7), Pair(7, 4), Pair(3, -8), Pair(16, -34)
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

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(7, 75), Pair(20, 47), Pair(22, 63), Pair(23, 76), Pair(26, 83), Pair(28, 95), Pair(31, 97), Pair(35, 96),
  Pair(37, 91)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-11, 32), Pair(-4, -8), Pair(0, 10), Pair(5, 25), Pair(7, 38), Pair(11, 49), Pair(13, 56), Pair(14, 60),
  Pair(17, 64), Pair(23, 64), Pair(30, 61), Pair(45, 57), Pair(45, 76), Pair(112, 34)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-33, -50), Pair(-23, -42), Pair(-19, -11), Pair(-17, 9), Pair(-15, 24), Pair(-11, 27), Pair(-6, 33), Pair(-1, 33),
  Pair(3, 37), Pair(8, 39), Pair(13, 42), Pair(16, 44), Pair(25, 42), Pair(41, 32), Pair(95, 4)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-64, 228), Pair(-42, 205), Pair(-1, 86), Pair(4, 80), Pair(4, 113), Pair(5, 125), Pair(6, 149), Pair(7, 154),
  Pair(9, 167), Pair(10, 172), Pair(10, 184), Pair(11, 187), Pair(14, 182), Pair(19, 181), Pair(19, 180), Pair(23, 176),
  Pair(21, 170), Pair(25, 168), Pair(28, 156), Pair(40, 136), Pair(51, 118), Pair(50, 111), Pair(103, 67), Pair(100, 63),
  Pair(-3, 125), Pair(159, 4), Pair(136, 6), Pair(203, 10)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-29, -100), Pair(-25, -84), Pair(-15, -52), Pair(8, -15), Pair(46, 43), Pair(202, 106), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(4, 8), Pair(15, 14), Pair(11, 38), Pair(38, 94), Pair(120, 156), Pair(31, 375), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(11, 1), Pair(9, 14), Pair(16, 30), Pair(75, 40), Pair(277, 45), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-36, -77), Pair(-22, -44), Pair(-9, -20), Pair(-28, -8), Pair(-24, -11), Pair(-30, -21), Pair(-18, -22), Pair(-21, -60)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-6, -2), Pair(-8, -12), Pair(-10, -8), Pair(-7, -11), Pair(-7, -12), Pair(-5, -11), Pair(-7, -6), Pair(0, -16)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(13, -7), Pair(22, -5), Pair(27, -3), Pair(27, 3), Pair(35, 0), Pair(63, -7), Pair(56, -12), Pair(28, -5)
  },
  {
      Pair(1, 16), Pair(5, 8), Pair(16, 2), Pair(20, 7), Pair(20, 5), Pair(26, 1), Pair(36, -11), Pair(-4, 9)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(16, -6), Pair(32, -10), Pair(17, -7),
  Pair(37, -16), Pair(37, -19), Pair(37, -16),
  Pair(52, -6), Pair(0, 0), Pair(51, -3),
  Pair(31, -5), Pair(5, 0), Pair(-4, -2)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-4, 6), Pair(-11, 31), Pair(-2, 7),
  Pair(-10, 19), Pair(-17, 18), Pair(-11, 17),
  Pair(3, 7), Pair(-11, 14), Pair(4, 10),
  Pair(14, 5), Pair(-2, -2), Pair(17, 3),
  Pair(54, -18), Pair(55, -28), Pair(47, -18),
  Pair(-11, 0), Pair(-23, -64), Pair(37, -28),
  Pair(54, -85), Pair(0, 0), Pair(65, -88)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(2, 90), Pair(0, 78), Pair(1, 64), Pair(8, 51), Pair(8, 42), Pair(13, 40), Pair(10, 32)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-26, -32), Pair(-17, 9), Pair(-5, 36), Pair(-1, 51), Pair(6, 60), Pair(10, 68), Pair(14, 79)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-701, 123);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-38, -50), Pair(1, -26), Pair(-33, -11), Pair(-60, -8), Pair(-29, -5), Pair(-37, -2), Pair(-14, -3), Pair(-21, -27)
  },
  {
      Pair(-55, 38), Pair(-12, 23), Pair(-10, 16), Pair(-40, 13), Pair(-9, 9), Pair(-19, 12), Pair(-8, 25), Pair(-20, 13)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(24, 1), Pair(39, -5), Pair(117, -23), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(12, 0), Pair(33, -1), Pair(75, -10), Pair(101, -37), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(24, -14), Pair(42, -13), Pair(68, -13), Pair(120, -24), Pair(167, -37), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(9, 20), Pair(24, 42), Pair(53, 49), Pair(108, 40), Pair(157, 46), Pair(260, 8), Pair(436, -86)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(35, 2), Pair(8, 9), Pair(32, -7), Pair(19, 19), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(8, 20), Pair(13, 27)
  },
  {
      Pair(-87, -52), Pair(-56, -72)
  },
  {
      Pair(-59, -69), Pair(-53, -77)
  },
  {
      Pair(-93, 5), Pair(-84, -15)
  },
  {
      Pair(-51, -21), Pair(-61, -36)
  },
  {
      Pair(17, 13), Pair(-11, 14)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(14, 29), Pair(7, 29), Pair(22, 26), Pair(9, 26), Pair(14, 3)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-7, -21), Pair(6, -5)
  },
  {
      Pair(-38, 1), Pair(-9, -11)
  },
  {
      Pair(-24, -36), Pair(-26, -50)
  },
  {
      Pair(-49, -23), Pair(-44, -25)
  },
  {
      Pair(-43, -13), Pair(-49, 9)
  },
  {
      Pair(-91, -7), Pair(-44, -45)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-9, -15), Pair(1, -1)
  },
  {
      Pair(-41, -30), Pair(-24, -45)
  },
  {
      Pair(-20, -37), Pair(-19, -44)
  },
  {
      Pair(-52, -19), Pair(-48, -30)
  },
  {
      Pair(-42, -14), Pair(-31, -37)
  },
  {
      Pair(-34, -32), Pair(5, -51)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-1, -20), Pair(8, -4)
  },
  {
      Pair(-31, -20), Pair(0, -5)
  },
  {
      Pair(-23, -20), Pair(-4, -5)
  },
  {
      Pair(0, -41), Pair(6, -43)
  },
  {
      Pair(-59, 7), Pair(-33, -20)
  },
  {
      Pair(16, -30), Pair(7, -53)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(-8, 76), Pair(37, 48), Pair(50, 21), Pair(44, 18), Pair(31, 23), Pair(22, 17), Pair(35, 25), Pair(61, 27),
  Pair(-2, -6), Pair(12, 25), Pair(2, 19), Pair(10, 20), Pair(2, 25), Pair(3, 16), Pair(1, 15), Pair(-17, 27),
  Pair(8, 11), Pair(-2, 16), Pair(8, 15), Pair(14, 20), Pair(-5, 8), Pair(4, 21), Pair(11, 8), Pair(-4, 20)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-1, -33), Pair(8, 10), Pair(19, -17), Pair(25, -19), Pair(55, -18), Pair(79, -26), Pair(37, 2), Pair(5, -46),
  Pair(-31, -48), Pair(5, -9), Pair(-3, -5), Pair(25, 2), Pair(8, 0), Pair(-16, 16), Pair(-7, -9), Pair(-25, 16),
  Pair(-7, -12), Pair(31, 0), Pair(9, 8), Pair(11, 12), Pair(-8, 5), Pair(8, 19), Pair(2, -5), Pair(-43, -3)
};

constexpr ScorePair kBishopPairBonus = Pair(22, 79);

constexpr ScorePair kTempoBonus = Pair(20, 19);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H