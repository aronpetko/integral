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
using PieceSquareTable = PieceTable<SquareTable<T>>;

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
  Pair(76, 103), Pair(359, 287), Pair(409, 362), Pair(534, 688), Pair(1146, 1164), Pair(0, 0)
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
        Pair(0, 0), Pair(20, -16), Pair(8, -3), Pair(-36, 4), Pair(3, -21), Pair(3, 10), Pair(-12, -11), Pair(35, 13),
        Pair(-2, 20), Pair(25, -28), Pair(15, -17), Pair(27, -30), Pair(-16, -14), Pair(-20, 2), Pair(24, -11), Pair(-51, 21),
        Pair(-58, -16), Pair(9, -15), Pair(-1, -15), Pair(34, -27), Pair(-35, 0), Pair(-21, -2), Pair(-40, 3), Pair(-5, 1),
        Pair(-35, 30), Pair(19, -22), Pair(11, -25), Pair(9, -11), Pair(6, -24), Pair(-19, -3), Pair(-26, -3), Pair(-9, -4),
        Pair(-87, 63), Pair(-8, -5), Pair(28, -20), Pair(23, -31), Pair(2, -17), Pair(-4, -21), Pair(-5, -16), Pair(2, -15),
        Pair(0, 0), Pair(-7, -31), Pair(-11, 6), Pair(4, -21), Pair(-19, -17), Pair(-7, -21), Pair(-18, -7), Pair(2, -18),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-89, -156), Pair(8, 2), Pair(133, -57), Pair(-38, -14), Pair(-87, -150), Pair(207, -78), Pair(68, -200), Pair(15, -93),
        Pair(44, 2), Pair(-10, -82), Pair(71, -122), Pair(113, -28), Pair(93, -59), Pair(-20, -41), Pair(14, -72), Pair(129, -19),
        Pair(65, -34), Pair(72, -63), Pair(23, -46), Pair(49, -78), Pair(81, -17), Pair(41, -60), Pair(39, -100), Pair(-20, -102),
        Pair(48, -50), Pair(37, -69), Pair(66, -43), Pair(82, -38), Pair(14, 26), Pair(109, -83), Pair(125, -103), Pair(-25, 3),
        Pair(95, -45), Pair(50, -6), Pair(6, -11), Pair(0, -18), Pair(62, -24), Pair(59, -73), Pair(60, -44), Pair(21, -28),
        Pair(-5, -49), Pair(-3, 54), Pair(66, -52), Pair(54, -64), Pair(27, -36), Pair(0, -107), Pair(76, -42), Pair(27, -97),
        Pair(0, 0), Pair(56, -113), Pair(13, 63), Pair(36, -57), Pair(53, -7), Pair(-4, -69), Pair(31, -143), Pair(38, 15),
        Pair(42, 76), Pair(34, -10), Pair(166, 63), Pair(36, -78), Pair(23, -6), Pair(32, -112), Pair(-43, 16), Pair(-2, -91)
      },
      { // Piece 2
        Pair(-40, -33), Pair(-94, 90), Pair(12, -44), Pair(-87, 108), Pair(29, 4), Pair(-122, 32), Pair(30, -66), Pair(-7, 188),
        Pair(3, 68), Pair(-87, 26), Pair(52, 56), Pair(38, -46), Pair(-70, 85), Pair(-108, 88), Pair(-175, 182), Pair(-80, 39),
        Pair(12, 14), Pair(-44, 76), Pair(-9, 8), Pair(-24, 55), Pair(59, -5), Pair(-116, 169), Pair(-10, -2), Pair(43, 5),
        Pair(30, 41), Pair(37, -51), Pair(27, 19), Pair(30, 10), Pair(-44, 172), Pair(46, -13), Pair(-67, 86), Pair(-94, 29),
        Pair(-4, -57), Pair(30, 20), Pair(-17, 55), Pair(-67, 178), Pair(123, -23), Pair(-7, 29), Pair(5, -12), Pair(-83, 23),
        Pair(-52, 82), Pair(191, -39), Pair(-58, 177), Pair(-48, 12), Pair(8, -4), Pair(2, -6), Pair(-8, 4), Pair(-35, 4),
        Pair(0, 0), Pair(-19, 193), Pair(19, 20), Pair(7, 53), Pair(-32, 5), Pair(-105, 17), Pair(39, -50), Pair(33, 13),
        Pair(125, 186), Pair(-15, 101), Pair(0, 88), Pair(-20, -4), Pair(-29, 38), Pair(-43, -25), Pair(-29, -38), Pair(-127, 12)
      },
      { // Piece 3
        Pair(129, 55), Pair(132, 4), Pair(102, -19), Pair(28, 99), Pair(-93, 72), Pair(94, -47), Pair(229, -1), Pair(187, 19),
        Pair(102, 53), Pair(156, -33), Pair(13, 60), Pair(151, 16), Pair(87, 40), Pair(231, -50), Pair(138, -58), Pair(65, 15),
        Pair(81, 59), Pair(66, -36), Pair(41, 20), Pair(-18, 71), Pair(30, 10), Pair(-67, 37), Pair(26, 38), Pair(75, 35),
        Pair(27, 83), Pair(-20, 23), Pair(-10, 52), Pair(64, 61), Pair(41, -7), Pair(30, 25), Pair(15, -22), Pair(13, 43),
        Pair(-2, 82), Pair(27, -3), Pair(-15, 11), Pair(74, -56), Pair(30, -30), Pair(50, -60), Pair(-119, 30), Pair(12, 36),
        Pair(7, 47), Pair(-26, 11), Pair(62, 32), Pair(-38, 34), Pair(80, -18), Pair(108, -11), Pair(91, -27), Pair(-28, -2),
        Pair(0, 0), Pair(-36, 45), Pair(29, 21), Pair(62, 41), Pair(-4, -10), Pair(22, 43), Pair(17, 33), Pair(22, 100),
        Pair(71, 130), Pair(7, 41), Pair(22, 63), Pair(53, 67), Pair(10, 75), Pair(9, 72), Pair(35, 87), Pair(5, 110)
      },
      { // Piece 4
        Pair(76, -47), Pair(16, 1), Pair(61, -55), Pair(88, -28), Pair(121, -23), Pair(17, 48), Pair(-84, -10), Pair(48, -84),
        Pair(-36, 37), Pair(-63, 126), Pair(-16, 56), Pair(45, 35), Pair(60, 74), Pair(103, -74), Pair(7, 50), Pair(46, -48),
        Pair(63, -96), Pair(68, -3), Pair(10, 63), Pair(-85, 122), Pair(24, 64), Pair(17, -4), Pair(-59, 95), Pair(51, 14),
        Pair(47, -67), Pair(-26, -90), Pair(-14, 121), Pair(-90, 73), Pair(-45, 36), Pair(-5, -49), Pair(82, -78), Pair(-22, 52),
        Pair(119, -184), Pair(-71, 47), Pair(-12, -36), Pair(-20, 52), Pair(-45, 32), Pair(12, -74), Pair(-14, -30), Pair(-31, 3),
        Pair(-75, -52), Pair(-15, 5), Pair(-4, 16), Pair(19, -47), Pair(-104, 106), Pair(4, -3), Pair(-74, 86), Pair(-12, -85),
        Pair(0, 0), Pair(-16, 70), Pair(3, -49), Pair(-21, -128), Pair(-41, -4), Pair(-19, -183), Pair(-44, -28), Pair(-151, -66),
        Pair(-81, 22), Pair(3, -39), Pair(-73, 82), Pair(-40, 73), Pair(-108, -35), Pair(-79, 34), Pair(-126, 37), Pair(-60, 35)
      },
      { // Piece 5
        Pair(-5, -21), Pair(-25, -12), Pair(11, -77), Pair(29, -18), Pair(105, -87), Pair(-28, -41), Pair(-56, -111), Pair(-6, -100),
        Pair(-94, -185), Pair(40, -9), Pair(-82, -68), Pair(-23, -15), Pair(-41, -22), Pair(133, -49), Pair(46, -57), Pair(4, -46),
        Pair(-52, -119), Pair(-54, 34), Pair(59, -11), Pair(-4, 31), Pair(80, -29), Pair(128, -37), Pair(166, -37), Pair(38, -61),
        Pair(-101, -23), Pair(-72, 54), Pair(-32, 49), Pair(41, 22), Pair(-1, 14), Pair(-60, 15), Pair(13, -11), Pair(77, -33),
        Pair(59, 2), Pair(-132, 54), Pair(114, 22), Pair(74, 5), Pair(61, 13), Pair(49, 4), Pair(13, -25), Pair(14, -71),
        Pair(-115, 103), Pair(-24, 114), Pair(90, 40), Pair(-16, 46), Pair(8, 23), Pair(19, 15), Pair(-20, -2), Pair(-33, -12),
        Pair(0, 0), Pair(-154, 210), Pair(-23, 57), Pair(14, 21), Pair(-11, 7), Pair(-26, 7), Pair(-40, 19), Pair(17, -28),
        Pair(192, 143), Pair(76, 109), Pair(-142, 136), Pair(-30, 24), Pair(-100, -4), Pair(-19, -94), Pair(1, -67), Pair(14, -106)
      }
    }},
    {{ // Bucket 9
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-20, 16), Pair(0, 0), Pair(-15, -9), Pair(53, -41), Pair(26, -7), Pair(-24, 16), Pair(-35, 16), Pair(19, -12),
        Pair(-20, 10), Pair(-35, 31), Pair(7, 1), Pair(30, -16), Pair(-18, 20), Pair(-16, -13), Pair(-4, 5), Pair(-27, 6),
        Pair(17, -29), Pair(4, -3), Pair(15, -11), Pair(3, -1), Pair(-4, -15), Pair(-27, -2), Pair(-9, -7), Pair(-16, 2),
        Pair(-6, -8), Pair(-82, 0), Pair(23, -19), Pair(14, -31), Pair(-4, -9), Pair(5, -16), Pair(-15, -8), Pair(-11, -9),
        Pair(1, -19), Pair(7, -47), Pair(-24, -14), Pair(-14, -20), Pair(-13, -4), Pair(-7, -16), Pair(-11, -22), Pair(-24, -4),
        Pair(7, -14), Pair(0, 0), Pair(2, -8), Pair(10, -37), Pair(-14, -3), Pair(5, -14), Pair(-21, -19), Pair(-21, 4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-6, 32), Pair(-49, -79), Pair(82, -83), Pair(-47, -66), Pair(-38, 5), Pair(97, -48), Pair(-10, -106), Pair(71, 10),
        Pair(17, -169), Pair(-86, -7), Pair(120, -19), Pair(54, -49), Pair(117, 5), Pair(-8, 30), Pair(-17, -77), Pair(43, -70),
        Pair(86, 40), Pair(58, 3), Pair(-24, 14), Pair(-58, -3), Pair(62, -43), Pair(121, -60), Pair(8, -3), Pair(3, -49),
        Pair(-142, 36), Pair(-14, -1), Pair(-27, 7), Pair(71, -23), Pair(107, -48), Pair(103, -16), Pair(30, -28), Pair(153, -74),
        Pair(102, -15), Pair(-37, 40), Pair(31, 40), Pair(16, -30), Pair(29, 9), Pair(-31, -18), Pair(-6, -38), Pair(-89, 7),
        Pair(-31, 95), Pair(17, -33), Pair(-52, 114), Pair(-90, 20), Pair(-14, 29), Pair(9, -17), Pair(-18, 66), Pair(-44, -63),
        Pair(-94, -124), Pair(0, 0), Pair(-6, 40), Pair(-85, 122), Pair(-16, -33), Pair(90, -126), Pair(-30, -59), Pair(-117, 11),
        Pair(-9, -19), Pair(-19, 139), Pair(-199, -63), Pair(40, 31), Pair(-34, -35), Pair(-82, 30), Pair(75, -113), Pair(-87, -21)
      },
      { // Piece 2
        Pair(-129, 98), Pair(-11, 28), Pair(-118, 141), Pair(-28, 30), Pair(-324, 141), Pair(30, 4), Pair(-40, 47), Pair(-32, 36),
        Pair(-58, 59), Pair(20, 62), Pair(21, 52), Pair(-160, 121), Pair(31, 47), Pair(13, 97), Pair(-13, 49), Pair(-104, 159),
        Pair(43, 25), Pair(-88, 59), Pair(-57, 55), Pair(55, -11), Pair(-53, 80), Pair(111, 55), Pair(31, 145), Pair(109, 16),
        Pair(-63, -24), Pair(-27, 78), Pair(-38, -21), Pair(-31, 75), Pair(85, -4), Pair(-29, 160), Pair(6, -26), Pair(12, 68),
        Pair(91, 41), Pair(14, -11), Pair(-14, 79), Pair(15, 42), Pair(-97, 164), Pair(-29, 6), Pair(30, 102), Pair(19, -70),
        Pair(-94, 44), Pair(-16, 146), Pair(6, 46), Pair(-27, 180), Pair(100, -98), Pair(12, -17), Pair(-9, -21), Pair(34, 8),
        Pair(-27, 173), Pair(0, 0), Pair(-8, 175), Pair(15, -13), Pair(-2, 4), Pair(-18, 21), Pair(-26, 30), Pair(70, -28),
        Pair(1, -19), Pair(4, 241), Pair(-129, 42), Pair(-70, 57), Pair(15, -61), Pair(-29, 59), Pair(-81, -69), Pair(-59, 113)
      },
      { // Piece 3
        Pair(118, -60), Pair(105, 30), Pair(-53, 40), Pair(113, -18), Pair(96, -51), Pair(65, 44), Pair(120, -11), Pair(243, -37),
        Pair(-58, 56), Pair(-23, 50), Pair(55, -28), Pair(97, 13), Pair(100, 21), Pair(138, -13), Pair(150, 24), Pair(-66, 82),
        Pair(17, -43), Pair(92, 46), Pair(11, 15), Pair(72, -28), Pair(84, -76), Pair(69, 23), Pair(72, 24), Pair(89, -7),
        Pair(65, -45), Pair(-5, 44), Pair(71, 6), Pair(-11, 42), Pair(4, 23), Pair(-37, 50), Pair(91, 7), Pair(120, -64),
        Pair(17, -6), Pair(-55, 23), Pair(-52, 10), Pair(-65, 52), Pair(-20, 49), Pair(31, -5), Pair(-112, 74), Pair(-60, 28),
        Pair(5, 6), Pair(-38, 4), Pair(-47, -47), Pair(20, -25), Pair(-31, 22), Pair(-40, 29), Pair(1, -122), Pair(60, -53),
        Pair(115, -27), Pair(0, 0), Pair(-21, 55), Pair(-91, 88), Pair(15, -54), Pair(127, -29), Pair(122, 56), Pair(137, -83),
        Pair(-39, 12), Pair(18, 105), Pair(-17, 17), Pair(-18, 76), Pair(-8, 59), Pair(7, 89), Pair(5, 61), Pair(-49, 73)
      },
      { // Piece 4
        Pair(66, 19), Pair(-9, 50), Pair(103, -38), Pair(28, 4), Pair(50, 37), Pair(-8, -76), Pair(-42, -12), Pair(135, -3),
        Pair(-31, -8), Pair(-169, 152), Pair(-15, 4), Pair(-98, 37), Pair(-1, 90), Pair(-49, 124), Pair(-7, -18), Pair(27, -24),
        Pair(-125, 129), Pair(-46, 64), Pair(-12, -26), Pair(-35, 93), Pair(1, 48), Pair(-13, 106), Pair(-54, 35), Pair(79, -93),
        Pair(-94, 72), Pair(-56, 94), Pair(-70, -3), Pair(62, 33), Pair(76, -2), Pair(25, 18), Pair(2, 12), Pair(91, -156),
        Pair(-4, 88), Pair(-3, -38), Pair(-99, 79), Pair(-40, 5), Pair(-71, 71), Pair(-25, 72), Pair(27, -66), Pair(31, -214),
        Pair(-52, -79), Pair(-62, 11), Pair(45, -80), Pair(-58, 60), Pair(10, -9), Pair(-32, 38), Pair(40, -132), Pair(6, -107),
        Pair(-45, -164), Pair(0, 0), Pair(72, -27), Pair(-19, -83), Pair(13, -69), Pair(15, 38), Pair(81, -1), Pair(-98, -25),
        Pair(-82, -52), Pair(-86, -26), Pair(-75, -119), Pair(-24, -47), Pair(50, -160), Pair(-25, 27), Pair(-149, -11), Pair(-122, 73)
      },
      { // Piece 5
        Pair(-26, -90), Pair(-9, -32), Pair(-2, 1), Pair(7, -84), Pair(43, -86), Pair(25, -64), Pair(-5, -22), Pair(12, -105),
        Pair(3, -9), Pair(-7, 61), Pair(22, -14), Pair(-14, -25), Pair(23, -3), Pair(-19, -79), Pair(70, -54), Pair(73, -17),
        Pair(-52, -83), Pair(8, -56), Pair(8, 28), Pair(29, -18), Pair(15, 9), Pair(40, -3), Pair(-8, -72), Pair(57, -53),
        Pair(-42, -6), Pair(-50, -9), Pair(-73, 16), Pair(100, 32), Pair(57, -5), Pair(-89, 27), Pair(-35, -40), Pair(-85, -7),
        Pair(-13, -66), Pair(-21, 16), Pair(79, 54), Pair(-87, 38), Pair(33, -14), Pair(116, -23), Pair(79, -43), Pair(58, -41),
        Pair(46, 91), Pair(82, 66), Pair(44, 102), Pair(-32, 9), Pair(-21, 24), Pair(39, 5), Pair(1, -20), Pair(43, -122),
        Pair(-56, 234), Pair(0, 0), Pair(-86, 148), Pair(-17, 51), Pair(-30, 47), Pair(30, -2), Pair(58, -42), Pair(35, -50),
        Pair(-5, 6), Pair(83, 130), Pair(3, 54), Pair(-299, 66), Pair(-77, 8), Pair(-31, -24), Pair(23, -73), Pair(50, -89)
      }
    }},
    {{ // Bucket 10
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-8, 3), Pair(15, 9), Pair(0, 0), Pair(-24, -16), Pair(-19, 4), Pair(58, -31), Pair(23, -25), Pair(7, 17),
        Pair(8, -7), Pair(-9, 8), Pair(26, -7), Pair(-5, -4), Pair(48, -32), Pair(12, -14), Pair(-43, 0), Pair(-7, 2),
        Pair(-9, -10), Pair(-7, -25), Pair(-8, -8), Pair(-17, 6), Pair(0, -12), Pair(-17, -11), Pair(-48, 14), Pair(6, -10),
        Pair(6, -11), Pair(22, -18), Pair(2, 4), Pair(-21, 12), Pair(-17, -6), Pair(1, -17), Pair(-45, 2), Pair(-49, 4),
        Pair(-5, -20), Pair(-7, 6), Pair(8, -5), Pair(-19, 0), Pair(-9, -7), Pair(-25, -12), Pair(-24, -3), Pair(-47, -4),
        Pair(23, -28), Pair(24, -22), Pair(0, 0), Pair(-8, -34), Pair(-10, 3), Pair(-19, -20), Pair(-21, -3), Pair(-37, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-70, -120), Pair(14, -34), Pair(63, 27), Pair(177, 66), Pair(-45, -117), Pair(-70, -58), Pair(-70, 36), Pair(-81, -171),
        Pair(-5, -76), Pair(-128, -21), Pair(-127, 19), Pair(-40, 74), Pair(-47, 9), Pair(71, -19), Pair(33, -62), Pair(-56, -23),
        Pair(-81, 43), Pair(60, 56), Pair(-62, 71), Pair(71, -44), Pair(-13, 58), Pair(125, -83), Pair(-14, -24), Pair(-84, 52),
        Pair(14, 35), Pair(27, 35), Pair(15, 37), Pair(-59, 89), Pair(55, 16), Pair(19, 24), Pair(19, 7), Pair(48, 27),
        Pair(-21, 36), Pair(115, -20), Pair(54, -23), Pair(-37, 65), Pair(71, -6), Pair(-8, 82), Pair(14, -41), Pair(-23, 38),
        Pair(32, -25), Pair(-128, 167), Pair(28, -43), Pair(-48, 130), Pair(-74, 48), Pair(-20, 60), Pair(-118, 121), Pair(-18, -41),
        Pair(-69, 135), Pair(-101, 44), Pair(0, 0), Pair(27, -11), Pair(-22, 119), Pair(67, -29), Pair(-89, -11), Pair(52, -52),
        Pair(-15, -10), Pair(37, -144), Pair(-33, 218), Pair(21, -68), Pair(39, 121), Pair(102, -72), Pair(20, -37), Pair(-23, 13)
      },
      { // Piece 2
        Pair(-34, 1), Pair(-3, 24), Pair(-141, 66), Pair(11, 19), Pair(-42, 74), Pair(-27, 101), Pair(9, -8), Pair(-70, 58),
        Pair(-38, 45), Pair(3, 0), Pair(-57, 135), Pair(-104, 73), Pair(-22, 125), Pair(-10, 21), Pair(-22, 86), Pair(179, -12),
        Pair(99, -12), Pair(61, 73), Pair(-96, 18), Pair(-95, 170), Pair(-39, 66), Pair(-93, 103), Pair(-46, 76), Pair(-35, 161),
        Pair(-158, 78), Pair(-10, 54), Pair(114, -36), Pair(53, -14), Pair(30, 74), Pair(115, 10), Pair(-39, 169), Pair(140, -82),
        Pair(31, 65), Pair(106, 35), Pair(-11, 40), Pair(58, 47), Pair(41, 10), Pair(-45, 200), Pair(-20, 44), Pair(-67, -14),
        Pair(-39, 216), Pair(-131, 76), Pair(-36, 119), Pair(156, 21), Pair(-48, 150), Pair(38, 9), Pair(-51, 57), Pair(-24, -78),
        Pair(-13, -68), Pair(-30, 170), Pair(0, 0), Pair(-22, 171), Pair(68, 41), Pair(-125, 60), Pair(-6, -2), Pair(-13, -73),
        Pair(38, 54), Pair(-6, -23), Pair(67, 240), Pair(-144, 65), Pair(82, -22), Pair(23, -40), Pair(38, 46), Pair(100, -20)
      },
      { // Piece 3
        Pair(-60, 66), Pair(42, -7), Pair(158, -1), Pair(75, 24), Pair(96, 21), Pair(33, -7), Pair(132, -48), Pair(94, -7),
        Pair(96, 14), Pair(-4, 49), Pair(120, 48), Pair(117, 24), Pair(7, 13), Pair(4, 78), Pair(25, 10), Pair(94, -17),
        Pair(77, -25), Pair(74, 18), Pair(75, 63), Pair(33, 41), Pair(82, -7), Pair(282, -150), Pair(23, -42), Pair(-78, 56),
        Pair(73, -5), Pair(85, 29), Pair(-13, 46), Pair(-28, 19), Pair(-100, 27), Pair(42, -5), Pair(-86, 71), Pair(-156, 59),
        Pair(-29, -3), Pair(108, -86), Pair(-51, 98), Pair(68, -31), Pair(85, -35), Pair(51, 46), Pair(79, -67), Pair(-111, 1),
        Pair(23, -19), Pair(102, -6), Pair(17, 8), Pair(32, 16), Pair(79, -56), Pair(-39, -13), Pair(10, 33), Pair(76, -43),
        Pair(-85, 56), Pair(2, 88), Pair(0, 0), Pair(71, -22), Pair(84, -42), Pair(108, -35), Pair(-109, 76), Pair(7, 0),
        Pair(-22, 85), Pair(-31, 55), Pair(72, 119), Pair(31, 8), Pair(-15, 74), Pair(9, 63), Pair(-23, 75), Pair(-40, 106)
      },
      { // Piece 4
        Pair(5, -38), Pair(105, -73), Pair(-150, 138), Pair(22, 1), Pair(78, 13), Pair(12, -31), Pair(17, 28), Pair(23, 149),
        Pair(-44, 52), Pair(1, 19), Pair(-54, 64), Pair(-49, 19), Pair(-33, 62), Pair(53, 76), Pair(-61, 83), Pair(-51, 5),
        Pair(-13, 7), Pair(27, 39), Pair(5, 29), Pair(-50, -11), Pair(-6, 115), Pair(-1, 68), Pair(-6, 57), Pair(-2, 6),
        Pair(-27, 131), Pair(105, -145), Pair(-16, 53), Pair(-170, 125), Pair(47, -9), Pair(-3, 26), Pair(103, -97), Pair(-1, -14),
        Pair(-58, -127), Pair(-134, 8), Pair(105, -122), Pair(-15, -38), Pair(-17, 131), Pair(-21, 50), Pair(16, -62), Pair(6, -176),
        Pair(-70, 20), Pair(9, -107), Pair(33, 24), Pair(1, -38), Pair(31, -48), Pair(14, -123), Pair(-108, 9), Pair(-47, -29),
        Pair(10, -69), Pair(-34, 3), Pair(0, 0), Pair(42, -112), Pair(-37, 67), Pair(36, 35), Pair(22, -196), Pair(-99, 36),
        Pair(-44, -54), Pair(52, -38), Pair(28, -69), Pair(-95, -107), Pair(-62, 61), Pair(75, -114), Pair(-18, -30), Pair(-20, -60)
      },
      { // Piece 5
        Pair(-4, 43), Pair(-5, -45), Pair(-33, -174), Pair(-16, -19), Pair(-4, -129), Pair(-17, -142), Pair(26, -241), Pair(0, -70),
        Pair(7, 1), Pair(-6, -53), Pair(-18, -5), Pair(0, -5), Pair(-32, -92), Pair(18, -44), Pair(-25, -74), Pair(-12, -83),
        Pair(-119, -85), Pair(15, -39), Pair(-101, -70), Pair(89, -8), Pair(12, -14), Pair(46, -37), Pair(-6, 8), Pair(78, -69),
        Pair(25, -25), Pair(26, 23), Pair(30, -54), Pair(64, 33), Pair(-16, 39), Pair(90, -6), Pair(39, -21), Pair(-93, -27),
        Pair(65, 90), Pair(36, -9), Pair(-33, 37), Pair(-58, 40), Pair(77, -2), Pair(85, -39), Pair(110, -20), Pair(-22, -21),
        Pair(-58, 57), Pair(26, 140), Pair(-90, 94), Pair(-25, 86), Pair(12, 11), Pair(12, 22), Pair(-51, -31), Pair(71, -85),
        Pair(131, -45), Pair(-109, 184), Pair(0, 0), Pair(-106, 139), Pair(-15, 35), Pair(38, -11), Pair(-13, -4), Pair(51, -66),
        Pair(-104, 103), Pair(105, -38), Pair(-183, 188), Pair(-4, -5), Pair(-17, 1), Pair(3, -24), Pair(17, -62), Pair(93, -125)
      }
    }},
    {{ // Bucket 11
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(36, -4), Pair(-53, 40), Pair(24, 16), Pair(0, 0), Pair(18, 33), Pair(9, -5), Pair(115, -39), Pair(32, 8),
        Pair(23, -16), Pair(-28, -2), Pair(-21, -13), Pair(-10, 3), Pair(-3, 9), Pair(21, 4), Pair(42, -24), Pair(-22, 4),
        Pair(19, -25), Pair(-6, -5), Pair(-28, -9), Pair(-3, 3), Pair(24, -1), Pair(-10, 1), Pair(5, -6), Pair(-27, -5),
        Pair(10, -13), Pair(-11, -24), Pair(-2, 0), Pair(-38, 11), Pair(32, -20), Pair(-10, -8), Pair(2, -19), Pair(1, -12),
        Pair(-3, -18), Pair(-4, -10), Pair(-8, 20), Pair(-7, 11), Pair(17, -11), Pair(10, -14), Pair(-12, -12), Pair(-1, -10),
        Pair(5, -19), Pair(-18, -5), Pair(-12, -13), Pair(0, 0), Pair(26, -9), Pair(17, -16), Pair(4, -17), Pair(-13, -9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-53, -57), Pair(2, -34), Pair(-5, 11), Pair(-129, -72), Pair(55, 60), Pair(34, -52), Pair(-36, -72), Pair(22, -14),
        Pair(55, -123), Pair(46, -11), Pair(-101, 0), Pair(-17, 24), Pair(69, -49), Pair(169, -46), Pair(9, 113), Pair(7, -14),
        Pair(-17, 76), Pair(26, -98), Pair(28, 39), Pair(53, -1), Pair(49, 7), Pair(22, 27), Pair(30, -21), Pair(-137, 115),
        Pair(-117, 96), Pair(5, -55), Pair(71, -21), Pair(61, -61), Pair(-54, 78), Pair(65, -55), Pair(177, -113), Pair(36, -92),
        Pair(-89, 20), Pair(114, 69), Pair(4, 65), Pair(78, 3), Pair(67, 36), Pair(85, -37), Pair(-71, 82), Pair(114, -32),
        Pair(-70, -32), Pair(52, -39), Pair(-24, 98), Pair(-126, 57), Pair(4, 74), Pair(27, 50), Pair(-6, 1), Pair(-33, 110),
        Pair(-145, -30), Pair(-132, 123), Pair(-83, 20), Pair(0, 0), Pair(-19, 55), Pair(-38, 132), Pair(63, -69), Pair(-33, 121),
        Pair(-65, -75), Pair(100, -41), Pair(-75, -3), Pair(12, 190), Pair(85, -92), Pair(-96, 109), Pair(-83, 1), Pair(19, -40)
      },
      { // Piece 2
        Pair(-9, 97), Pair(-58, 88), Pair(-106, 57), Pair(-18, -96), Pair(73, 85), Pair(21, -82), Pair(43, 66), Pair(82, -69),
        Pair(-53, 71), Pair(121, 36), Pair(68, -85), Pair(10, 74), Pair(-37, -14), Pair(-67, 100), Pair(97, -26), Pair(13, 78),
        Pair(-49, -21), Pair(8, 16), Pair(-87, 83), Pair(93, -2), Pair(-87, 65), Pair(166, -61), Pair(-32, 62), Pair(-52, 30),
        Pair(-8, 25), Pair(-109, 101), Pair(115, -32), Pair(-18, 75), Pair(-14, -15), Pair(-26, 76), Pair(30, 20), Pair(-68, 166),
        Pair(-48, 163), Pair(-81, 64), Pair(46, 52), Pair(93, -25), Pair(48, 42), Pair(26, 56), Pair(-87, 167), Pair(-28, 50),
        Pair(-5, -52), Pair(-7, 140), Pair(-43, 64), Pair(-72, 64), Pair(35, -3), Pair(-42, 146), Pair(-91, 93), Pair(-14, 63),
        Pair(-5, 7), Pair(-30, -46), Pair(-73, 187), Pair(0, 0), Pair(-37, 158), Pair(19, 26), Pair(15, 45), Pair(-72, -7),
        Pair(-22, -32), Pair(10, 51), Pair(-21, -31), Pair(57, 213), Pair(-20, 12), Pair(20, 7), Pair(-70, 48), Pair(-116, 82)
      },
      { // Piece 3
        Pair(101, -49), Pair(42, -49), Pair(49, 21), Pair(81, -20), Pair(35, 13), Pair(150, 6), Pair(103, 3), Pair(140, -9),
        Pair(6, 20), Pair(5, 5), Pair(57, 21), Pair(45, 32), Pair(-29, -17), Pair(174, -58), Pair(91, -24), Pair(56, -41),
        Pair(40, -9), Pair(-7, 7), Pair(85, -47), Pair(39, 10), Pair(-98, 53), Pair(173, -19), Pair(42, 51), Pair(292, -103),
        Pair(-38, 22), Pair(-22, 28), Pair(-62, 62), Pair(25, 46), Pair(21, -25), Pair(-72, 28), Pair(90, 0), Pair(120, 5),
        Pair(-92, 14), Pair(142, -94), Pair(72, -4), Pair(6, 26), Pair(75, -83), Pair(38, -55), Pair(-68, 12), Pair(-20, -54),
        Pair(-93, 80), Pair(-74, 80), Pair(79, 67), Pair(-115, 103), Pair(-12, -81), Pair(87, 2), Pair(-111, 53), Pair(41, -5),
        Pair(139, -36), Pair(-86, 40), Pair(64, -45), Pair(0, 0), Pair(-8, 11), Pair(120, -24), Pair(35, 16), Pair(18, -33),
        Pair(-24, 93), Pair(-3, 68), Pair(2, 6), Pair(36, 126), Pair(11, 24), Pair(5, 60), Pair(44, 71), Pair(-51, 73)
      },
      { // Piece 4
        Pair(96, -122), Pair(-25, 21), Pair(-33, -15), Pair(-20, 65), Pair(37, 0), Pair(71, -9), Pair(15, -71), Pair(42, 0),
        Pair(24, 1), Pair(-78, 25), Pair(-65, -39), Pair(6, 73), Pair(-53, 105), Pair(42, 129), Pair(42, -9), Pair(97, -63),
        Pair(17, -14), Pair(-62, 64), Pair(-74, -74), Pair(96, -41), Pair(-99, 47), Pair(50, 30), Pair(201, -143), Pair(-35, -42),
        Pair(20, 0), Pair(12, -129), Pair(-20, -37), Pair(44, -49), Pair(60, -92), Pair(106, -52), Pair(84, -86), Pair(-57, 91),
        Pair(6, -34), Pair(-56, -17), Pair(61, -91), Pair(-13, 13), Pair(58, -69), Pair(60, -116), Pair(13, -5), Pair(80, -70),
        Pair(-35, -41), Pair(-6, 6), Pair(-53, 28), Pair(56, 34), Pair(8, 4), Pair(-26, 75), Pair(79, -99), Pair(-41, -116),
        Pair(-3, -156), Pair(11, -90), Pair(-40, 65), Pair(0, 0), Pair(97, -56), Pair(-2, 31), Pair(-81, -2), Pair(-52, 22),
        Pair(-164, 97), Pair(-61, 32), Pair(-123, 23), Pair(59, -132), Pair(-129, -127), Pair(-40, -82), Pair(1, -46), Pair(-39, 15)
      },
      { // Piece 5
        Pair(-13, -76), Pair(-3, -74), Pair(13, 84), Pair(-6, -37), Pair(-5, -18), Pair(-60, -175), Pair(-11, -67), Pair(-7, -7),
        Pair(-2, -44), Pair(-51, -102), Pair(-5, -150), Pair(-6, 0), Pair(0, -35), Pair(-21, -72), Pair(-63, -78), Pair(-11, -125),
        Pair(13, -15), Pair(11, 9), Pair(46, -15), Pair(1, -29), Pair(67, -69), Pair(52, -14), Pair(41, -44), Pair(18, -2),
        Pair(-13, -78), Pair(57, 40), Pair(109, -35), Pair(-152, -16), Pair(-32, 6), Pair(56, 39), Pair(23, -21), Pair(70, -56),
        Pair(-68, -36), Pair(34, 1), Pair(5, 51), Pair(88, -12), Pair(-140, 20), Pair(-9, 13), Pair(35, -28), Pair(-8, -46),
        Pair(-2, -4), Pair(92, -9), Pair(-54, 87), Pair(-121, 87), Pair(-12, 74), Pair(97, -10), Pair(27, 23), Pair(48, -67),
        Pair(47, -12), Pair(-70, 72), Pair(-14, 114), Pair(0, 0), Pair(-54, 87), Pair(56, 26), Pair(-20, 21), Pair(-33, -18),
        Pair(-67, 17), Pair(-44, 3), Pair(-71, -113), Pair(-94, 153), Pair(49, 64), Pair(-33, 20), Pair(1, -14), Pair(47, -96)
      }
    }},
    {{ // Bucket 12
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-3, 21), Pair(-26, 7), Pair(19, -4), Pair(-18, -33), Pair(0, 0), Pair(24, -6), Pair(0, 7), Pair(-23, 20),
        Pair(33, -20), Pair(16, -17), Pair(-17, 6), Pair(47, -41), Pair(63, -79), Pair(7, 0), Pair(28, -10), Pair(-17, -4),
        Pair(5, -8), Pair(16, -33), Pair(3, -18), Pair(11, 1), Pair(8, -22), Pair(11, -17), Pair(4, -16), Pair(-29, 3),
        Pair(21, -23), Pair(-13, -12), Pair(-16, -14), Pair(17, -28), Pair(-12, -4), Pair(0, -5), Pair(12, -19), Pair(-42, -2),
        Pair(-7, -16), Pair(-12, -7), Pair(-23, 2), Pair(13, 0), Pair(-14, 0), Pair(28, -9), Pair(32, -29), Pair(2, -25),
        Pair(7, -21), Pair(5, 1), Pair(3, -21), Pair(-30, 23), Pair(0, 0), Pair(-21, -16), Pair(16, -12), Pair(-9, -8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-56, -178), Pair(55, -78), Pair(-13, -21), Pair(127, -90), Pair(18, 28), Pair(-37, -95), Pair(-12, -125), Pair(-22, 69),
        Pair(43, -35), Pair(14, 12), Pair(-25, -28), Pair(-57, 12), Pair(-206, 25), Pair(-18, 101), Pair(25, -67), Pair(22, -49),
        Pair(-182, -36), Pair(-25, -27), Pair(-21, -59), Pair(-58, -7), Pair(109, -66), Pair(93, 16), Pair(155, -24), Pair(125, -27),
        Pair(-61, -52), Pair(-1, -43), Pair(-12, -16), Pair(-41, 24), Pair(70, 10), Pair(96, 3), Pair(83, -38), Pair(-52, 42),
        Pair(-38, -16), Pair(-130, 7), Pair(-36, -27), Pair(92, 16), Pair(-35, 11), Pair(62, 27), Pair(110, 38), Pair(-44, 57),
        Pair(-18, -15), Pair(118, -36), Pair(-89, 57), Pair(-80, 114), Pair(15, 77), Pair(-75, 84), Pair(7, 39), Pair(98, -139),
        Pair(-105, -48), Pair(-17, 7), Pair(-184, 176), Pair(-45, 14), Pair(0, 0), Pair(-55, -63), Pair(-38, 187), Pair(46, 28),
        Pair(-10, -101), Pair(-105, 64), Pair(146, -113), Pair(-57, -107), Pair(-33, 184), Pair(21, -74), Pair(25, -17), Pair(14, 32)
      },
      { // Piece 2
        Pair(178, -45), Pair(-6, 91), Pair(3, 49), Pair(-82, 66), Pair(-46, -6), Pair(16, 85), Pair(-12, -13), Pair(62, 73),
        Pair(-86, 88), Pair(88, -36), Pair(-15, 52), Pair(50, -8), Pair(-106, 59), Pair(17, -19), Pair(-49, 73), Pair(-24, -15),
        Pair(58, -17), Pair(-30, 7), Pair(-2, 8), Pair(2, 51), Pair(-52, -27), Pair(-112, 140), Pair(-42, 62), Pair(-2, 42),
        Pair(-132, 146), Pair(-68, 60), Pair(-9, 44), Pair(142, -86), Pair(-21, 50), Pair(-165, 119), Pair(14, 76), Pair(-61, 74),
        Pair(-157, 33), Pair(-89, 156), Pair(-93, 99), Pair(131, 9), Pair(24, 29), Pair(63, 4), Pair(-2, 83), Pair(-16, 187),
        Pair(73, -69), Pair(91, 1), Pair(-7, 101), Pair(-14, 92), Pair(9, 15), Pair(26, 44), Pair(-21, 119), Pair(70, -42),
        Pair(217, -89), Pair(-4, 10), Pair(-8, 77), Pair(-58, 113), Pair(0, 0), Pair(-79, 157), Pair(64, -67), Pair(-103, 23),
        Pair(14, -23), Pair(165, -58), Pair(-63, 38), Pair(25, 50), Pair(0, 213), Pair(-107, -88), Pair(-11, 97), Pair(5, 55)
      },
      { // Piece 3
        Pair(-90, -15), Pair(-82, -13), Pair(112, -24), Pair(11, -51), Pair(89, 4), Pair(1, 14), Pair(21, 42), Pair(57, -3),
        Pair(62, -14), Pair(-15, 3), Pair(-72, 39), Pair(-144, 19), Pair(8, -12), Pair(-2, -4), Pair(-29, 24), Pair(-79, 48),
        Pair(41, -50), Pair(13, -14), Pair(-89, 33), Pair(34, -38), Pair(60, -19), Pair(208, -93), Pair(139, -37), Pair(-103, 25),
        Pair(191, -100), Pair(-21, -38), Pair(17, -34), Pair(-95, -21), Pair(109, 38), Pair(58, -56), Pair(-15, 16), Pair(15, -45),
        Pair(-22, 5), Pair(-29, 22), Pair(-21, -2), Pair(-41, -13), Pair(62, -14), Pair(-62, 21), Pair(145, -89), Pair(-67, 70),
        Pair(-118, 109), Pair(-100, 47), Pair(168, -35), Pair(31, -60), Pair(41, 46), Pair(71, -51), Pair(1, -16), Pair(152, -61),
        Pair(57, 19), Pair(69, -33), Pair(19, 12), Pair(137, 29), Pair(0, 0), Pair(-38, 108), Pair(47, -12), Pair(9, -75),
        Pair(-82, 51), Pair(-100, 78), Pair(-65, 76), Pair(-89, -44), Pair(38, 84), Pair(-26, 48), Pair(-15, 38), Pair(-55, 72)
      },
      { // Piece 4
        Pair(-38, 29), Pair(-33, -33), Pair(-2, 79), Pair(-17, 83), Pair(-57, -27), Pair(111, 10), Pair(-35, -70), Pair(86, -58),
        Pair(-85, 71), Pair(-31, -66), Pair(85, -27), Pair(-65, 87), Pair(96, 84), Pair(-13, 94), Pair(-9, 45), Pair(-37, 41),
        Pair(-2, -85), Pair(3, 22), Pair(-24, -3), Pair(-41, 42), Pair(3, 36), Pair(123, -26), Pair(109, -38), Pair(-16, -87),
        Pair(-93, 43), Pair(-109, 131), Pair(-24, -45), Pair(34, -152), Pair(137, -85), Pair(19, -6), Pair(130, -117), Pair(75, 17),
        Pair(-78, 124), Pair(5, -5), Pair(-8, 21), Pair(-13, -6), Pair(-43, 53), Pair(-15, -28), Pair(-8, -49), Pair(19, 21),
        Pair(-252, -97), Pair(16, -166), Pair(-27, -62), Pair(101, -220), Pair(83, -24), Pair(-106, 53), Pair(-13, 17), Pair(-91, -26),
        Pair(25, -61), Pair(-114, 69), Pair(58, -100), Pair(-26, 12), Pair(0, 0), Pair(-8, -7), Pair(-29, 21), Pair(-44, -89),
        Pair(38, -100), Pair(-126, -18), Pair(44, -212), Pair(-90, -44), Pair(11, -46), Pair(-19, 19), Pair(-116, -11), Pair(-37, 4)
      },
      { // Piece 5
        Pair(-47, -17), Pair(-15, -160), Pair(3, -46), Pair(-62, -181), Pair(32, 8), Pair(-20, -92), Pair(-3, 31), Pair(14, -7),
        Pair(12, -44), Pair(9, -52), Pair(-56, -101), Pair(31, -57), Pair(26, -10), Pair(25, -24), Pair(-73, 1), Pair(-2, 13),
        Pair(57, -59), Pair(-31, -30), Pair(-21, 4), Pair(-14, 17), Pair(17, 13), Pair(76, -64), Pair(45, -63), Pair(-74, 27),
        Pair(-49, -76), Pair(-15, 21), Pair(-52, 23), Pair(-24, 18), Pair(-68, 12), Pair(25, -3), Pair(47, -8), Pair(-49, 2),
        Pair(133, -96), Pair(62, -29), Pair(-9, 19), Pair(-70, 53), Pair(-70, 35), Pair(-71, 40), Pair(39, -18), Pair(-92, 8),
        Pair(-4, -36), Pair(22, -10), Pair(-91, 41), Pair(-48, 47), Pair(71, 114), Pair(1, 99), Pair(31, 46), Pair(98, -10),
        Pair(96, -57), Pair(21, 15), Pair(103, -14), Pair(-156, 118), Pair(0, 0), Pair(19, 105), Pair(43, 35), Pair(7, 22),
        Pair(57, -98), Pair(33, -33), Pair(-44, 55), Pair(-2, 11), Pair(-72, 179), Pair(26, 19), Pair(-12, 41), Pair(9, -18)
      }
    }},
    {{ // Bucket 13
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-3, -10), Pair(24, -16), Pair(-58, 31), Pair(-9, 5), Pair(-24, 6), Pair(0, 0), Pair(-130, 8), Pair(-90, 11),
        Pair(36, -7), Pair(-20, 24), Pair(-69, -17), Pair(-14, -29), Pair(-24, 16), Pair(-5, 41), Pair(7, 26), Pair(65, -19),
        Pair(-21, 3), Pair(10, -19), Pair(-13, -2), Pair(-6, 11), Pair(-4, -2), Pair(36, -39), Pair(-2, -24), Pair(-7, -12),
        Pair(-33, -6), Pair(-19, -21), Pair(6, -25), Pair(-3, 9), Pair(18, -3), Pair(5, 10), Pair(17, -24), Pair(-15, -7),
        Pair(10, -2), Pair(-29, -7), Pair(-11, -11), Pair(58, -38), Pair(-26, 5), Pair(17, 15), Pair(27, -19), Pair(11, -14),
        Pair(31, -32), Pair(6, -5), Pair(-6, -14), Pair(-73, 43), Pair(0, -28), Pair(0, 0), Pair(25, 4), Pair(-22, -4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-101, -37), Pair(-123, -252), Pair(-77, -20), Pair(100, 65), Pair(-21, 0), Pair(-4, -13), Pair(-31, -63), Pair(13, 66),
        Pair(-83, -202), Pair(-89, -13), Pair(139, 1), Pair(-27, -126), Pair(-4, 20), Pair(6, 22), Pair(-35, -196), Pair(-111, -107),
        Pair(108, -114), Pair(-167, 50), Pair(52, 2), Pair(-43, -17), Pair(36, 0), Pair(40, -22), Pair(127, 31), Pair(-19, 37),
        Pair(46, -106), Pair(0, -136), Pair(-7, -9), Pair(61, -107), Pair(72, 23), Pair(83, -3), Pair(107, -40), Pair(-29, -15),
        Pair(-50, -134), Pair(-183, 45), Pair(-97, 54), Pair(78, -31), Pair(59, 3), Pair(168, -34), Pair(132, -44), Pair(22, -85),
        Pair(8, -216), Pair(51, -31), Pair(-5, 22), Pair(-15, -20), Pair(-18, 83), Pair(70, -56), Pair(-29, 49), Pair(75, -35),
        Pair(-15, -71), Pair(-69, -169), Pair(-55, -30), Pair(-79, 101), Pair(79, -35), Pair(0, 0), Pair(-43, -6), Pair(-26, 140),
        Pair(17, 75), Pair(-18, -12), Pair(-28, -59), Pair(-140, -67), Pair(-58, -15), Pair(-51, 134), Pair(14, 18), Pair(98, 81)
      },
      { // Piece 2
        Pair(-64, -27), Pair(-41, -136), Pair(14, 32), Pair(-175, 20), Pair(-75, 81), Pair(-103, -209), Pair(45, 163), Pair(-38, -99),
        Pair(-7, 46), Pair(88, 16), Pair(-50, -5), Pair(-71, 105), Pair(62, -5), Pair(-66, 125), Pair(65, -24), Pair(35, -52),
        Pair(-152, 167), Pair(137, -57), Pair(-135, 101), Pair(94, -35), Pair(-205, 134), Pair(39, 15), Pair(47, 85), Pair(20, -66),
        Pair(-21, -30), Pair(-74, 150), Pair(-140, 81), Pair(-22, 46), Pair(64, -42), Pair(184, -28), Pair(117, -60), Pair(-50, 81),
        Pair(-10, 93), Pair(-60, -54), Pair(-65, 172), Pair(12, 10), Pair(129, 4), Pair(-6, -62), Pair(-20, 31), Pair(87, 67),
        Pair(17, 20), Pair(-85, 70), Pair(-46, -26), Pair(-49, 102), Pair(23, -46), Pair(163, -8), Pair(-59, -57), Pair(-206, 164),
        Pair(-226, -155), Pair(40, -53), Pair(-26, 75), Pair(-23, 47), Pair(-7, 137), Pair(0, 0), Pair(-8, 91), Pair(-76, -123),
        Pair(-32, 14), Pair(-1, -39), Pair(12, -127), Pair(65, 28), Pair(12, -61), Pair(-101, 245), Pair(3, -41), Pair(59, 22)
      },
      { // Piece 3
        Pair(33, -37), Pair(-42, 25), Pair(7, -8), Pair(25, -1), Pair(100, -99), Pair(115, 15), Pair(-24, -7), Pair(102, -35),
        Pair(-7, 10), Pair(-19, -15), Pair(39, -10), Pair(-31, 14), Pair(-5, -31), Pair(112, 24), Pair(-11, 44), Pair(105, -41),
        Pair(22, 30), Pair(-69, 19), Pair(-7, -27), Pair(152, -27), Pair(-17, -46), Pair(2, -15), Pair(49, 6), Pair(51, -19),
        Pair(37, -28), Pair(36, -34), Pair(-8, -75), Pair(-43, -38), Pair(0, -47), Pair(63, 12), Pair(65, -35), Pair(95, -100),
        Pair(18, -22), Pair(29, 10), Pair(-6, 19), Pair(-80, 84), Pair(73, -35), Pair(72, 18), Pair(-61, -28), Pair(-25, 12),
        Pair(37, -2), Pair(-154, 10), Pair(12, -44), Pair(85, -51), Pair(-6, -39), Pair(29, 20), Pair(-107, 74), Pair(7, 3),
        Pair(117, -64), Pair(-110, -2), Pair(-14, 15), Pair(-40, 5), Pair(63, 41), Pair(0, 0), Pair(269, -4), Pair(-80, 94),
        Pair(-52, 55), Pair(-13, 24), Pair(-36, 61), Pair(-14, 83), Pair(-25, -9), Pair(77, 82), Pair(-205, 102), Pair(-8, 75)
      },
      { // Piece 4
        Pair(1, -80), Pair(-32, -31), Pair(-133, -82), Pair(5, 87), Pair(111, -100), Pair(-4, -61), Pair(-21, -143), Pair(85, 88),
        Pair(-72, 116), Pair(-112, 17), Pair(0, 39), Pair(-39, 105), Pair(43, -12), Pair(107, -10), Pair(2, 16), Pair(7, -102),
        Pair(74, -78), Pair(34, -16), Pair(34, -82), Pair(16, -71), Pair(-77, 24), Pair(-133, 12), Pair(-42, 31), Pair(66, -115),
        Pair(-99, 37), Pair(9, -137), Pair(-6, -6), Pair(52, 12), Pair(-64, 49), Pair(56, -13), Pair(-41, 60), Pair(8, -149),
        Pair(-2, -132), Pair(-29, 36), Pair(-65, -93), Pair(52, 28), Pair(-83, 122), Pair(138, -6), Pair(1, 53), Pair(-44, 107),
        Pair(9, 35), Pair(-24, -81), Pair(-13, -41), Pair(-49, -17), Pair(-10, -62), Pair(-106, 29), Pair(119, 15), Pair(14, 25),
        Pair(5, -63), Pair(-53, 17), Pair(-4, -37), Pair(-41, 102), Pair(-77, 35), Pair(0, 0), Pair(-30, 27), Pair(-38, -30),
        Pair(-11, -79), Pair(-112, -79), Pair(-43, -7), Pair(-71, -167), Pair(-72, -66), Pair(-14, -62), Pair(-22, -62), Pair(-19, -47)
      },
      { // Piece 5
        Pair(-11, -71), Pair(-1, -83), Pair(24, -152), Pair(-17, -4), Pair(-41, -83), Pair(-28, -67), Pair(-3, -48), Pair(34, 111),
        Pair(-16, -124), Pair(-66, -114), Pair(60, -126), Pair(20, -77), Pair(-33, -80), Pair(38, -7), Pair(-38, -122), Pair(20, -48),
        Pair(-41, -112), Pair(39, -73), Pair(163, -25), Pair(125, -56), Pair(12, -40), Pair(-117, -1), Pair(46, 26), Pair(43, 23),
        Pair(6, -74), Pair(-94, -65), Pair(-11, -30), Pair(134, -24), Pair(-46, -18), Pair(2, 23), Pair(-58, -5), Pair(0, -1),
        Pair(-62, -28), Pair(-44, -16), Pair(43, 40), Pair(38, -3), Pair(168, 14), Pair(74, 10), Pair(196, -19), Pair(153, -51),
        Pair(-42, -32), Pair(-165, -17), Pair(67, -26), Pair(64, 4), Pair(-50, 58), Pair(-59, 87), Pair(-57, 118), Pair(-98, 45),
        Pair(-159, -25), Pair(39, -31), Pair(34, -19), Pair(-86, 75), Pair(-25, 111), Pair(0, 0), Pair(-92, 153), Pair(16, 47),
        Pair(-65, -14), Pair(-10, -62), Pair(-5, -29), Pair(62, -37), Pair(109, 135), Pair(-48, 173), Pair(81, 69), Pair(-93, 82)
      }
    }},
    {{ // Bucket 14
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(12, 11), Pair(35, -17), Pair(-23, 25), Pair(-115, 39), Pair(0, -7), Pair(130, -8), Pair(0, 0), Pair(77, 4),
        Pair(-18, -13), Pair(15, 6), Pair(-3, -14), Pair(22, -22), Pair(-3, -11), Pair(-8, 12), Pair(-10, -33), Pair(-39, 17),
        Pair(12, -9), Pair(-37, -4), Pair(-30, -4), Pair(-37, -5), Pair(-53, -2), Pair(46, -4), Pair(-13, -12), Pair(26, -19),
        Pair(33, -29), Pair(23, -18), Pair(-5, -27), Pair(-10, -14), Pair(19, -35), Pair(20, -25), Pair(3, -26), Pair(-21, -7),
        Pair(7, -14), Pair(-33, 0), Pair(14, -33), Pair(-19, 7), Pair(15, -17), Pair(-15, -19), Pair(6, 5), Pair(19, -13),
        Pair(11, -39), Pair(-3, -16), Pair(-7, -22), Pair(-35, 30), Pair(38, -22), Pair(41, -14), Pair(0, 0), Pair(46, -7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(60, 8), Pair(-163, -143), Pair(55, -71), Pair(4, -46), Pair(99, 75), Pair(126, -60), Pair(-12, -27), Pair(-3, 13),
        Pair(-68, -90), Pair(-152, -82), Pair(266, -205), Pair(-128, 13), Pair(-46, -17), Pair(-142, -47), Pair(-79, 45), Pair(-44, -53),
        Pair(19, -35), Pair(128, -125), Pair(-41, 16), Pair(126, -62), Pair(55, -33), Pair(62, -43), Pair(18, 47), Pair(86, -164),
        Pair(27, -53), Pair(-20, -37), Pair(-68, 7), Pair(121, 7), Pair(98, 11), Pair(30, 26), Pair(13, -21), Pair(106, -8),
        Pair(-35, -43), Pair(58, -49), Pair(-77, -26), Pair(-32, 33), Pair(44, -48), Pair(52, 15), Pair(-148, 103), Pair(-28, 111),
        Pair(65, 10), Pair(-42, -3), Pair(102, -65), Pair(-78, 8), Pair(26, -25), Pair(-18, 71), Pair(-26, 74), Pair(-110, 97),
        Pair(-72, -70), Pair(165, 89), Pair(29, -10), Pair(-42, 76), Pair(-74, 103), Pair(171, -86), Pair(0, 0), Pair(36, -22),
        Pair(-12, -10), Pair(54, -122), Pair(-83, -1), Pair(-87, -10), Pair(-58, 35), Pair(22, -29), Pair(-17, 137), Pair(-24, -48)
      },
      { // Piece 2
        Pair(17, 45), Pair(-130, 24), Pair(-67, -78), Pair(-49, 115), Pair(-4, 18), Pair(-82, 131), Pair(-42, -13), Pair(36, -30),
        Pair(-162, 139), Pair(-62, 49), Pair(-116, 96), Pair(-20, -15), Pair(-23, 98), Pair(-56, -88), Pair(-1, 43), Pair(69, -95),
        Pair(-39, -35), Pair(-233, 137), Pair(-86, 101), Pair(4, 136), Pair(108, -15), Pair(86, 51), Pair(31, -11), Pair(-50, 24),
        Pair(-180, 87), Pair(6, 6), Pair(-101, 148), Pair(59, 63), Pair(-32, 43), Pair(52, -11), Pair(-50, 79), Pair(155, -22),
        Pair(-64, -7), Pair(-173, 72), Pair(16, 30), Pair(-22, 143), Pair(21, 74), Pair(-60, 34), Pair(178, -35), Pair(22, 38),
        Pair(-60, 99), Pair(-15, -31), Pair(-69, 0), Pair(-4, -60), Pair(-110, 136), Pair(-24, 28), Pair(33, 67), Pair(47, -7),
        Pair(83, 55), Pair(-59, 36), Pair(-78, -52), Pair(-77, -5), Pair(-20, 18), Pair(70, 134), Pair(0, 0), Pair(-85, 149),
        Pair(105, 20), Pair(107, -7), Pair(-142, 82), Pair(11, -68), Pair(-163, 116), Pair(-54, -34), Pair(0, 219), Pair(14, 9)
      },
      { // Piece 3
        Pair(-200, 59), Pair(-47, 16), Pair(27, -2), Pair(-36, 3), Pair(238, -52), Pair(14, -1), Pair(99, 2), Pair(203, -39),
        Pair(8, -5), Pair(-67, -13), Pair(59, -38), Pair(125, -54), Pair(24, -15), Pair(88, -49), Pair(113, -4), Pair(-63, 33),
        Pair(-88, -42), Pair(22, -28), Pair(-125, 43), Pair(21, -67), Pair(2, 6), Pair(23, 0), Pair(-12, 24), Pair(11, -8),
        Pair(66, -26), Pair(91, -43), Pair(-58, 29), Pair(-26, -25), Pair(112, -26), Pair(-36, -9), Pair(82, -17), Pair(84, -42),
        Pair(-90, -32), Pair(31, -47), Pair(61, -87), Pair(-8, -72), Pair(18, -31), Pair(196, -60), Pair(116, -1), Pair(70, -21),
        Pair(-24, -58), Pair(136, -54), Pair(70, -51), Pair(31, -25), Pair(31, -48), Pair(62, -132), Pair(181, -71), Pair(-21, 19),
        Pair(-85, 9), Pair(-73, 31), Pair(-26, 13), Pair(-110, 6), Pair(-6, -23), Pair(129, -5), Pair(0, 0), Pair(41, -74),
        Pair(-33, 46), Pair(-9, 88), Pair(-54, 62), Pair(-44, 62), Pair(18, 23), Pair(-27, 26), Pair(-38, 120), Pair(-69, 46)
      },
      { // Piece 4
        Pair(-20, 105), Pair(-69, 24), Pair(-110, -15), Pair(-82, -15), Pair(-49, -49), Pair(-6, -17), Pair(-135, -149), Pair(-1, -65),
        Pair(27, -17), Pair(-71, -26), Pair(-101, 60), Pair(-26, 4), Pair(26, 41), Pair(45, 19), Pair(88, 87), Pair(-76, -13),
        Pair(-75, -192), Pair(55, -45), Pair(-25, -16), Pair(5, 52), Pair(9, 57), Pair(-60, -30), Pair(-27, 3), Pair(73, -83),
        Pair(47, 14), Pair(38, -67), Pair(40, -56), Pair(0, -11), Pair(-25, 45), Pair(58, -12), Pair(-138, 100), Pair(42, -6),
        Pair(-8, -122), Pair(-18, -59), Pair(23, -16), Pair(28, 8), Pair(-20, 81), Pair(-65, 26), Pair(47, -101), Pair(12, -65),
        Pair(-79, -88), Pair(-38, -74), Pair(-114, 109), Pair(-17, 10), Pair(54, -99), Pair(47, -99), Pair(-2, -4), Pair(-41, -79),
        Pair(55, 20), Pair(-21, -85), Pair(-51, -13), Pair(-48, 29), Pair(-149, 111), Pair(63, 137), Pair(0, 0), Pair(-152, -55),
        Pair(-66, -12), Pair(93, -1), Pair(-38, -137), Pair(52, -88), Pair(20, -71), Pair(-168, -87), Pair(54, -152), Pair(0, 0)
      },
      { // Piece 5
        Pair(15, -106), Pair(-22, -133), Pair(-25, -93), Pair(-4, -126), Pair(-20, -10), Pair(14, -2), Pair(-12, -90), Pair(-16, -10),
        Pair(-10, -128), Pair(-35, -14), Pair(84, -98), Pair(-3, -62), Pair(-24, -35), Pair(25, -20), Pair(-20, -73), Pair(6, -17),
        Pair(-29, -17), Pair(-3, -35), Pair(21, -15), Pair(-62, -40), Pair(152, -8), Pair(94, -3), Pair(-46, -39), Pair(-33, -108),
        Pair(21, -97), Pair(5, -47), Pair(6, -15), Pair(-12, 39), Pair(-9, 40), Pair(71, 11), Pair(92, -40), Pair(0, 0),
        Pair(-66, -40), Pair(-13, -37), Pair(76, -47), Pair(-35, 18), Pair(190, 30), Pair(46, 47), Pair(79, 3), Pair(5, -11),
        Pair(-3, -105), Pair(-42, 23), Pair(59, -46), Pair(-190, 48), Pair(-101, 8), Pair(-15, 87), Pair(-97, 86), Pair(17, 75),
        Pair(0, -51), Pair(-106, -15), Pair(-28, -21), Pair(-8, 28), Pair(30, 1), Pair(-16, 119), Pair(0, 0), Pair(-37, 166),
        Pair(-15, -69), Pair(-38, -53), Pair(88, -86), Pair(36, -74), Pair(-70, 10), Pair(20, 111), Pair(-13, 165), Pair(140, 22)
      }
    }},
    {{ // Bucket 15
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-35, -13), Pair(-19, 12), Pair(-7, -17), Pair(-32, -8), Pair(23, -20), Pair(90, -11), Pair(-77, -4), Pair(0, 0),
        Pair(14, -16), Pair(56, -29), Pair(-22, -1), Pair(-41, 5), Pair(25, -10), Pair(-7, -11), Pair(-15, 25), Pair(66, -2),
        Pair(28, -14), Pair(20, -15), Pair(20, -27), Pair(-9, -9), Pair(15, -14), Pair(-33, 0), Pair(24, -10), Pair(-82, 37),
        Pair(8, -20), Pair(-27, -17), Pair(-17, -3), Pair(-12, -27), Pair(21, -32), Pair(-26, -3), Pair(25, -28), Pair(64, -69),
        Pair(10, -21), Pair(5, -31), Pair(-5, -34), Pair(-9, -12), Pair(13, -22), Pair(29, -14), Pair(11, -5), Pair(-43, -25),
        Pair(-9, -15), Pair(1, -15), Pair(1, -1), Pair(3, -62), Pair(-16, -9), Pair(0, -13), Pair(13, 19), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-129, -134), Pair(4, -157), Pair(23, -154), Pair(-124, -61), Pair(45, 9), Pair(-24, -134), Pair(1, -87), Pair(1, -80),
        Pair(-30, -52), Pair(-1, -133), Pair(22, -115), Pair(30, -67), Pair(102, -42), Pair(-8, -69), Pair(219, 4), Pair(-63, -50),
        Pair(-75, -52), Pair(117, -144), Pair(-89, -30), Pair(-13, -9), Pair(-121, -7), Pair(-51, -27), Pair(-9, -64), Pair(-51, -104),
        Pair(-35, -84), Pair(118, -75), Pair(9, -74), Pair(31, -32), Pair(89, -48), Pair(149, -79), Pair(277, -115), Pair(120, -45),
        Pair(-76, -107), Pair(23, -50), Pair(-61, -10), Pair(48, -20), Pair(136, -106), Pair(4, 16), Pair(88, -58), Pair(178, -74),
        Pair(-91, -39), Pair(171, -123), Pair(-1, -74), Pair(-104, 22), Pair(-11, -11), Pair(21, 39), Pair(-47, 38), Pair(46, -60),
        Pair(-86, -89), Pair(-77, -37), Pair(-99, -159), Pair(3, -79), Pair(-14, 1), Pair(-34, 89), Pair(76, -65), Pair(0, 0),
        Pair(-5, -12), Pair(-66, -39), Pair(-247, -44), Pair(119, -149), Pair(-3, -37), Pair(-147, -2), Pair(-131, -169), Pair(-180, 168)
      },
      { // Piece 2
        Pair(-40, 137), Pair(-56, -29), Pair(42, 74), Pair(122, -5), Pair(23, 75), Pair(91, 26), Pair(6, 100), Pair(-112, -197),
        Pair(93, -98), Pair(-50, 174), Pair(-61, 31), Pair(-62, 87), Pair(-53, 1), Pair(-70, 111), Pair(7, 27), Pair(6, 28),
        Pair(24, 63), Pair(163, -55), Pair(-54, 160), Pair(-31, -10), Pair(-20, 45), Pair(49, -19), Pair(10, 14), Pair(-32, 55),
        Pair(104, -18), Pair(-29, 99), Pair(30, -35), Pair(43, 119), Pair(38, 42), Pair(-78, 45), Pair(19, -111), Pair(32, 13),
        Pair(-33, 20), Pair(-46, -88), Pair(70, 26), Pair(22, -9), Pair(-5, 131), Pair(8, -26), Pair(39, -78), Pair(172, 33),
        Pair(-23, -35), Pair(-19, 7), Pair(4, -39), Pair(91, -2), Pair(-33, -50), Pair(-29, 121), Pair(-111, 102), Pair(44, 27),
        Pair(45, 30), Pair(-2, 38), Pair(-1, 13), Pair(-13, -60), Pair(-63, 22), Pair(133, -114), Pair(44, 176), Pair(0, 0),
        Pair(-151, -22), Pair(66, -36), Pair(-72, 21), Pair(-61, 22), Pair(30, -92), Pair(11, 53), Pair(-25, -94), Pair(80, 209)
      },
      { // Piece 3
        Pair(131, -66), Pair(-7, -11), Pair(-74, 9), Pair(27, -57), Pair(-81, 8), Pair(12, 14), Pair(108, -28), Pair(133, 15),
        Pair(26, -13), Pair(-69, -16), Pair(109, -109), Pair(23, -92), Pair(-64, 41), Pair(-141, 3), Pair(40, -38), Pair(32, 32),
        Pair(91, -31), Pair(20, -52), Pair(82, -13), Pair(30, -33), Pair(90, -59), Pair(47, -86), Pair(32, 13), Pair(15, 11),
        Pair(41, -36), Pair(-50, -4), Pair(-15, 7), Pair(35, -17), Pair(-77, 31), Pair(85, 15), Pair(51, -45), Pair(-44, 71),
        Pair(107, -115), Pair(23, -47), Pair(181, -62), Pair(-56, 10), Pair(-4, 5), Pair(145, -35), Pair(-28, -17), Pair(14, -3),
        Pair(93, -42), Pair(-33, -50), Pair(223, -93), Pair(26, -27), Pair(-37, -11), Pair(-104, 58), Pair(76, -56), Pair(44, 83),
        Pair(33, -76), Pair(26, -19), Pair(-4, 30), Pair(-108, 15), Pair(-101, 68), Pair(78, -77), Pair(112, -10), Pair(0, 0),
        Pair(-69, 81), Pair(-32, 74), Pair(-24, 110), Pair(18, 73), Pair(22, 40), Pair(67, 54), Pair(203, 24), Pair(-21, 125)
      },
      { // Piece 4
        Pair(40, -47), Pair(-39, -26), Pair(-25, -38), Pair(-75, -19), Pair(32, -29), Pair(29, -83), Pair(-13, -46), Pair(34, 5),
        Pair(-11, 101), Pair(-78, 82), Pair(-72, 84), Pair(8, 168), Pair(-38, -16), Pair(77, 19), Pair(62, -25), Pair(-14, -38),
        Pair(63, -89), Pair(-36, 0), Pair(76, -155), Pair(23, -9), Pair(-111, 42), Pair(85, -27), Pair(106, 113), Pair(-84, 37),
        Pair(-134, -83), Pair(105, -35), Pair(12, 45), Pair(-43, 22), Pair(-53, -20), Pair(32, -95), Pair(7, 78), Pair(57, -102),
        Pair(62, -129), Pair(-26, -4), Pair(-89, 45), Pair(57, -89), Pair(39, 50), Pair(-26, -80), Pair(-49, -40), Pair(128, -24),
        Pair(67, 62), Pair(-39, -35), Pair(-97, -16), Pair(-52, 75), Pair(1, -61), Pair(-44, 9), Pair(4, -33), Pair(17, -78),
        Pair(126, -16), Pair(35, -12), Pair(-16, -144), Pair(-67, -125), Pair(-48, 41), Pair(-13, 99), Pair(27, -49), Pair(0, 0),
        Pair(28, -97), Pair(-232, 28), Pair(29, -73), Pair(-13, 8), Pair(-55, -79), Pair(-78, 32), Pair(-84, -50), Pair(-93, -44)
      },
      { // Piece 5
        Pair(9, -71), Pair(32, -168), Pair(6, -68), Pair(-7, -110), Pair(13, 114), Pair(-14, -64), Pair(10, 15), Pair(-18, -80),
        Pair(72, -107), Pair(1, -98), Pair(-32, -60), Pair(-32, -75), Pair(-38, -42), Pair(12, -17), Pair(-25, -79), Pair(-12, -95),
        Pair(-22, -74), Pair(-51, -5), Pair(10, -24), Pair(-20, -39), Pair(237, -72), Pair(127, -43), Pair(42, -34), Pair(-11, -47),
        Pair(98, -100), Pair(31, -54), Pair(-101, 22), Pair(80, -23), Pair(41, 5), Pair(88, 8), Pair(102, -14), Pair(3, -62),
        Pair(-13, -62), Pair(-76, -58), Pair(211, -60), Pair(14, 0), Pair(-40, 44), Pair(14, 22), Pair(-82, 41), Pair(19, 15),
        Pair(33, -6), Pair(-5, -40), Pair(-12, -64), Pair(59, -1), Pair(-64, 39), Pair(24, 40), Pair(-149, 145), Pair(-88, 106),
        Pair(-49, -40), Pair(-26, -37), Pair(-6, -47), Pair(-104, 23), Pair(-94, 53), Pair(-21, 75), Pair(-167, 193), Pair(0, 0),
        Pair(-59, -126), Pair(-74, -73), Pair(-51, -54), Pair(-44, 0), Pair(-111, 56), Pair(-241, 128), Pair(126, 93), Pair(112, 151)
      }
    }},
    {{ // Bucket 16
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(2, -20), Pair(20, -10), Pair(-8, 7), Pair(-23, 16), Pair(-34, 20), Pair(-36, 7), Pair(18, 13), Pair(-14, 17),
        Pair(0, 0), Pair(14, -20), Pair(2, 3), Pair(-3, -3), Pair(-3, -1), Pair(-29, 15), Pair(2, 3), Pair(12, 3),
        Pair(29, -5), Pair(-1, -5), Pair(6, -7), Pair(3, -12), Pair(-1, -3), Pair(-3, -1), Pair(-2, 3), Pair(-7, 6),
        Pair(-17, 1), Pair(2, -5), Pair(-4, -4), Pair(3, -16), Pair(-5, -1), Pair(1, -6), Pair(-7, -8), Pair(-9, -5),
        Pair(0, 0), Pair(2, -7), Pair(-2, -7), Pair(4, -14), Pair(-4, -6), Pair(-4, -6), Pair(-6, -10), Pair(-8, -9),
        Pair(33, 29), Pair(-3, 0), Pair(-4, -2), Pair(-7, 7), Pair(0, -20), Pair(-1, -10), Pair(-3, -8), Pair(-6, -10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(1, -48), Pair(-6, -45), Pair(67, -88), Pair(79, -104), Pair(174, -95), Pair(-7, -27), Pair(-50, -120), Pair(-151, -48),
        Pair(-60, 64), Pair(26, -56), Pair(120, -16), Pair(-43, 21), Pair(53, -23), Pair(49, -44), Pair(19, -85), Pair(114, -88),
        Pair(150, -2), Pair(60, -24), Pair(5, 17), Pair(56, -9), Pair(31, -15), Pair(46, -25), Pair(53, -35), Pair(43, -63),
        Pair(61, 9), Pair(31, -19), Pair(33, -7), Pair(41, -19), Pair(27, 7), Pair(25, -32), Pair(14, -12), Pair(48, -41),
        Pair(8, -28), Pair(-18, 55), Pair(29, -7), Pair(21, -1), Pair(33, -12), Pair(25, -27), Pair(84, -58), Pair(70, -44),
        Pair(0, 0), Pair(16, -11), Pair(7, 46), Pair(-3, -5), Pair(13, 12), Pair(24, -12), Pair(41, -53), Pair(16, -1),
        Pair(66, 91), Pair(30, -99), Pair(37, -5), Pair(33, -5), Pair(34, 15), Pair(5, -31), Pair(47, -39), Pair(47, -80),
        Pair(-164, 26), Pair(-28, 23), Pair(-65, 41), Pair(94, -97), Pair(17, -22), Pair(25, -65), Pair(21, -54), Pair(-50, -30)
      },
      { // Piece 2
        Pair(-159, 74), Pair(110, 44), Pair(-130, 71), Pair(-90, 67), Pair(90, 16), Pair(1, 45), Pair(-176, 154), Pair(83, 41),
        Pair(27, -9), Pair(-10, 28), Pair(52, 28), Pair(-58, 81), Pair(-1, 77), Pair(-42, 131), Pair(43, 75), Pair(-31, 17),
        Pair(-72, 33), Pair(-15, 39), Pair(-9, 16), Pair(13, 62), Pair(-70, 125), Pair(8, 62), Pair(-48, 60), Pair(40, 26),
        Pair(13, 73), Pair(-11, 25), Pair(45, 41), Pair(-42, 87), Pair(14, 59), Pair(-10, 9), Pair(25, 31), Pair(38, -3),
        Pair(11, 25), Pair(-3, 85), Pair(-40, 102), Pair(8, 64), Pair(-2, 13), Pair(27, 15), Pair(15, 21), Pair(-40, 44),
        Pair(0, 0), Pair(-21, 95), Pair(16, 56), Pair(6, 17), Pair(25, 19), Pair(5, 0), Pair(20, -2), Pair(2, 7),
        Pair(-24, 184), Pair(20, 46), Pair(17, 38), Pair(27, 26), Pair(-16, 17), Pair(21, -8), Pair(4, 7), Pair(28, 13),
        Pair(17, 6), Pair(-55, 82), Pair(19, 22), Pair(-8, -26), Pair(-7, 16), Pair(-13, -10), Pair(18, -10), Pair(-29, 11)
      },
      { // Piece 3
        Pair(28, 96), Pair(-9, 73), Pair(41, 65), Pair(20, 45), Pair(49, 63), Pair(189, 9), Pair(85, 8), Pair(115, 16),
        Pair(88, 89), Pair(-15, 73), Pair(44, 43), Pair(46, 60), Pair(65, 45), Pair(56, 30), Pair(-14, 58), Pair(89, 31),
        Pair(-12, 110), Pair(51, 19), Pair(0, 43), Pair(70, 23), Pair(29, 44), Pair(16, 69), Pair(54, 42), Pair(21, 28),
        Pair(-42, 117), Pair(14, 45), Pair(17, 58), Pair(2, 51), Pair(27, 39), Pair(63, 18), Pair(36, 28), Pair(11, 43),
        Pair(12, 88), Pair(27, 24), Pair(-11, 57), Pair(7, 45), Pair(24, 30), Pair(23, 20), Pair(48, 20), Pair(25, 28),
        Pair(0, 0), Pair(35, 92), Pair(-5, 65), Pair(35, 37), Pair(19, 71), Pair(5, 60), Pair(72, 15), Pair(16, 51),
        Pair(7, 95), Pair(41, -4), Pair(-20, 100), Pair(-15, 60), Pair(4, 59), Pair(11, 75), Pair(-29, 90), Pair(-62, 80),
        Pair(-16, 78), Pair(4, 55), Pair(4, 66), Pair(0, 50), Pair(10, 51), Pair(4, 53), Pair(48, 39), Pair(18, 44)
      },
      { // Piece 4
        Pair(92, 37), Pair(204, -45), Pair(38, 30), Pair(-13, 110), Pair(28, 101), Pair(98, 42), Pair(76, -30), Pair(28, 73),
        Pair(-7, 71), Pair(-1, 90), Pair(19, 79), Pair(-12, 150), Pair(-24, 109), Pair(105, 60), Pair(54, 80), Pair(75, 52),
        Pair(-52, 145), Pair(54, 23), Pair(-13, 90), Pair(23, 76), Pair(36, 118), Pair(20, 33), Pair(45, -31), Pair(30, 45),
        Pair(75, 58), Pair(11, 81), Pair(0, 75), Pair(4, 112), Pair(38, 71), Pair(42, 81), Pair(59, 41), Pair(55, 51),
        Pair(-39, 74), Pair(-6, 109), Pair(31, 56), Pair(26, 35), Pair(18, 60), Pair(31, 22), Pair(22, 60), Pair(29, 40),
        Pair(0, 0), Pair(-10, 90), Pair(4, 84), Pair(9, 48), Pair(12, 31), Pair(20, 58), Pair(10, 39), Pair(27, -18),
        Pair(-45, 90), Pair(-32, 22), Pair(-5, 68), Pair(7, 54), Pair(8, 24), Pair(15, 15), Pair(26, 8), Pair(35, -36),
        Pair(-5, 69), Pair(-25, 0), Pair(0, 47), Pair(4, 26), Pair(20, 42), Pair(-36, 67), Pair(-9, 100), Pair(-56, 100)
      },
      { // Piece 5
        Pair(-18, -11), Pair(-10, -71), Pair(-8, 1), Pair(73, -23), Pair(39, -79), Pair(2, -148), Pair(53, -56), Pair(73, -94),
        Pair(25, -104), Pair(-76, -78), Pair(-29, -56), Pair(-36, -44), Pair(95, -52), Pair(71, -111), Pair(92, -80), Pair(8, -44),
        Pair(20, -42), Pair(-6, -36), Pair(90, -25), Pair(49, 19), Pair(189, -63), Pair(40, -70), Pair(152, -83), Pair(-26, -54),
        Pair(13, -102), Pair(151, -1), Pair(-40, 19), Pair(78, -7), Pair(133, -40), Pair(175, -59), Pair(111, -59), Pair(37, -50),
        Pair(-47, 51), Pair(-145, 63), Pair(63, 11), Pair(31, -5), Pair(18, -5), Pair(75, -41), Pair(54, -51), Pair(88, -70),
        Pair(0, 0), Pair(-165, 126), Pair(-66, 49), Pair(1, 28), Pair(-12, -4), Pair(42, -31), Pair(-6, -36), Pair(2, -41),
        Pair(6, 92), Pair(31, -2), Pair(-74, 45), Pair(-45, 16), Pair(-11, -18), Pair(-28, -26), Pair(-3, -31), Pair(-2, -48),
        Pair(-34, 96), Pair(-35, 68), Pair(-51, 6), Pair(-26, -10), Pair(-17, -40), Pair(15, -47), Pair(-6, -52), Pair(16, -71)
      }
    }},
    {{ // Bucket 17
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-25, 28), Pair(35, -31), Pair(9, -7), Pair(28, 2), Pair(-16, 17), Pair(20, -22), Pair(-15, -6), Pair(-56, 29),
        Pair(-15, 19), Pair(0, 0), Pair(-12, 5), Pair(-11, -2), Pair(-1, 10), Pair(-20, 18), Pair(-13, 16), Pair(-4, 3),
        Pair(2, -5), Pair(-12, -12), Pair(3, -9), Pair(2, -6), Pair(-3, -4), Pair(6, -4), Pair(1, 2), Pair(9, -2),
        Pair(3, -10), Pair(-8, -16), Pair(-2, -5), Pair(-1, -3), Pair(-12, -9), Pair(-7, -4), Pair(-2, -6), Pair(6, -5),
        Pair(9, -5), Pair(0, 0), Pair(11, -6), Pair(-12, 0), Pair(-5, -12), Pair(-9, -5), Pair(-10, -4), Pair(-4, -5),
        Pair(12, 5), Pair(30, 35), Pair(0, -5), Pair(-5, 5), Pair(-12, -1), Pair(-8, -9), Pair(-17, 2), Pair(4, -12),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(51, -98), Pair(-70, -92), Pair(50, 4), Pair(6, -37), Pair(-69, -3), Pair(93, -7), Pair(-21, -65), Pair(-21, -49),
        Pair(198, -16), Pair(41, -41), Pair(48, 1), Pair(94, -7), Pair(82, -14), Pair(12, -35), Pair(-15, -21), Pair(85, -6),
        Pair(176, -62), Pair(46, -43), Pair(53, 26), Pair(41, 6), Pair(22, 18), Pair(38, 0), Pair(36, -37), Pair(69, -69),
        Pair(-21, 12), Pair(25, 37), Pair(28, 5), Pair(34, -26), Pair(45, 11), Pair(25, 0), Pair(42, 3), Pair(80, -39),
        Pair(-10, 48), Pair(15, 36), Pair(25, 64), Pair(13, 2), Pair(67, 31), Pair(26, -11), Pair(42, 21), Pair(33, -14),
        Pair(14, 7), Pair(0, 0), Pair(26, 28), Pair(-4, 80), Pair(22, -8), Pair(20, 29), Pair(39, -22), Pair(75, -39),
        Pair(3, -61), Pair(-8, 120), Pair(-77, 34), Pair(20, 11), Pair(30, -32), Pair(-11, 35), Pair(17, -43), Pair(6, 43),
        Pair(-137, -58), Pair(-18, 88), Pair(46, -47), Pair(-70, 97), Pair(26, -83), Pair(28, -15), Pair(-28, 38), Pair(-48, -105)
      },
      { // Piece 2
        Pair(36, -2), Pair(15, 33), Pair(-87, 43), Pair(5, 112), Pair(-101, 54), Pair(-30, -3), Pair(9, 82), Pair(-3, 100),
        Pair(83, -3), Pair(-63, 57), Pair(-2, 69), Pair(-99, 74), Pair(-29, 97), Pair(21, 128), Pair(-7, 127), Pair(55, 76),
        Pair(29, 32), Pair(-67, 10), Pair(72, -8), Pair(2, 50), Pair(52, 73), Pair(-9, 129), Pair(-78, 87), Pair(15, 0),
        Pair(36, 21), Pair(20, 29), Pair(-36, 55), Pair(-3, 60), Pair(-32, 105), Pair(-32, 72), Pair(-4, 45), Pair(49, 31),
        Pair(6, 53), Pair(3, -7), Pair(-36, 64), Pair(10, 105), Pair(19, 64), Pair(46, 0), Pair(1, 38), Pair(25, -11),
        Pair(12, 133), Pair(0, 0), Pair(-8, 91), Pair(-3, 65), Pair(-3, 35), Pair(-15, 49), Pair(47, -5), Pair(14, 1),
        Pair(-140, 124), Pair(8, 170), Pair(-4, 13), Pair(-8, 13), Pair(-10, 48), Pair(-4, 0), Pair(-6, 9), Pair(19, -8),
        Pair(-56, 141), Pair(-44, 45), Pair(-39, 74), Pair(-21, 27), Pair(-21, 28), Pair(-4, 40), Pair(-58, 51), Pair(19, 65)
      },
      { // Piece 3
        Pair(72, 22), Pair(-12, 93), Pair(23, 50), Pair(93, 14), Pair(88, 63), Pair(186, 3), Pair(-52, 72), Pair(139, 0),
        Pair(24, 24), Pair(11, 83), Pair(-12, 66), Pair(23, 48), Pair(47, 29), Pair(129, 18), Pair(120, 22), Pair(119, 8),
        Pair(24, 39), Pair(32, 89), Pair(26, 25), Pair(40, 48), Pair(52, 12), Pair(43, 21), Pair(113, -5), Pair(73, -1),
        Pair(0, 20), Pair(21, 87), Pair(12, 53), Pair(39, 46), Pair(-14, 51), Pair(23, 58), Pair(17, 32), Pair(72, 30),
        Pair(4, 26), Pair(-10, 64), Pair(6, 1), Pair(9, 41), Pair(24, 53), Pair(-55, 49), Pair(81, 19), Pair(82, -9),
        Pair(30, 3), Pair(0, 0), Pair(52, 8), Pair(1, 48), Pair(-34, 72), Pair(31, 45), Pair(51, -28), Pair(-27, 43),
        Pair(-91, 41), Pair(-9, 90), Pair(6, 78), Pair(13, 66), Pair(19, 52), Pair(36, 24), Pair(-25, 66), Pair(10, 67),
        Pair(-15, 51), Pair(-6, 77), Pair(7, 29), Pair(2, 31), Pair(10, 41), Pair(10, 63), Pair(47, 29), Pair(7, 48)
      },
      { // Piece 4
        Pair(137, -84), Pair(43, 89), Pair(-43, 106), Pair(26, 68), Pair(-12, 80), Pair(119, 47), Pair(31, 30), Pair(55, 76),
        Pair(75, -12), Pair(45, 32), Pair(54, 2), Pair(-64, 82), Pair(118, 23), Pair(60, 113), Pair(10, 74), Pair(-20, 63),
        Pair(-29, 34), Pair(59, 4), Pair(89, -58), Pair(15, 102), Pair(87, 84), Pair(54, 106), Pair(85, 47), Pair(52, -40),
        Pair(75, -62), Pair(23, 7), Pair(-43, 185), Pair(30, 32), Pair(76, 51), Pair(22, 78), Pair(72, 14), Pair(39, 21),
        Pair(-20, 78), Pair(45, -36), Pair(-63, 110), Pair(0, 83), Pair(14, 26), Pair(24, 11), Pair(28, 28), Pair(-8, 74),
        Pair(34, -54), Pair(0, 0), Pair(0, 70), Pair(-2, 66), Pair(23, 11), Pair(42, 17), Pair(47, 30), Pair(34, 117),
        Pair(-31, -14), Pair(32, 17), Pair(12, -16), Pair(7, 60), Pair(5, -2), Pair(-4, 18), Pair(-27, -25), Pair(39, 15),
        Pair(17, -8), Pair(-10, 9), Pair(-16, 62), Pair(21, -75), Pair(-4, 22), Pair(7, -60), Pair(93, -39), Pair(-31, -22)
      },
      { // Piece 5
        Pair(-44, -156), Pair(-62, -155), Pair(55, -9), Pair(-57, -86), Pair(-7, -29), Pair(-22, -117), Pair(-54, -70), Pair(2, -82),
        Pair(-16, -25), Pair(8, -23), Pair(-18, -45), Pair(-17, 7), Pair(110, -75), Pair(28, -65), Pair(43, -55), Pair(-10, -59),
        Pair(33, -14), Pair(71, -56), Pair(69, 12), Pair(70, -32), Pair(116, -16), Pair(104, -42), Pair(14, -55), Pair(52, -59),
        Pair(-30, -28), Pair(109, -45), Pair(176, -28), Pair(4, -10), Pair(60, -7), Pair(-37, -14), Pair(2, -35), Pair(120, -69),
        Pair(74, 52), Pair(-55, 24), Pair(-33, 42), Pair(33, 1), Pair(-66, 26), Pair(6, -28), Pair(0, -38), Pair(93, -88),
        Pair(-230, 112), Pair(0, 0), Pair(-76, 81), Pair(38, 14), Pair(-37, 2), Pair(-9, -20), Pair(50, -57), Pair(31, -67),
        Pair(80, 40), Pair(-109, 100), Pair(-2, 106), Pair(-71, 35), Pair(-22, -2), Pair(-8, -27), Pair(-7, -35), Pair(-5, -48),
        Pair(-96, 79), Pair(-82, 53), Pair(-57, 48), Pair(-59, -3), Pair(-53, -10), Pair(-5, -35), Pair(5, -62), Pair(-16, -63)
      }
    }},
    {{ // Bucket 18
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-14, 17), Pair(-7, -1), Pair(-27, 7), Pair(21, 13), Pair(17, -6), Pair(69, 18), Pair(3, 14), Pair(22, 1),
        Pair(-2, -1), Pair(11, -5), Pair(0, 0), Pair(-21, 0), Pair(-3, 2), Pair(-5, 9), Pair(17, 9), Pair(-5, 11),
        Pair(-8, 4), Pair(8, -12), Pair(21, -9), Pair(-1, -2), Pair(-6, 5), Pair(-15, 1), Pair(7, -6), Pair(2, 3),
        Pair(0, -8), Pair(7, -13), Pair(4, -12), Pair(-4, -11), Pair(-6, -3), Pair(-16, -3), Pair(-8, -8), Pair(-1, -9),
        Pair(8, -3), Pair(3, -5), Pair(0, 0), Pair(-4, -5), Pair(-4, -5), Pair(-21, 0), Pair(-19, -1), Pair(-3, -4),
        Pair(12, -7), Pair(10, -26), Pair(39, 27), Pair(-3, -26), Pair(5, -12), Pair(-19, -8), Pair(-17, -5), Pair(-3, -7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-43, -20), Pair(94, -51), Pair(-11, -13), Pair(-1, 5), Pair(102, -20), Pair(0, 40), Pair(59, -146), Pair(-101, -16),
        Pair(-50, 1), Pair(98, 2), Pair(-17, 6), Pair(27, -8), Pair(32, 17), Pair(47, 22), Pair(40, 25), Pair(52, -94),
        Pair(129, -27), Pair(24, -13), Pair(27, 16), Pair(23, 69), Pair(60, -5), Pair(75, 10), Pair(36, 24), Pair(68, -22),
        Pair(56, 25), Pair(38, 29), Pair(84, -10), Pair(10, 45), Pair(30, 18), Pair(40, 31), Pair(58, 25), Pair(66, -1),
        Pair(2, 37), Pair(-17, 121), Pair(28, 21), Pair(7, 96), Pair(-17, 32), Pair(0, 31), Pair(65, -6), Pair(14, 13),
        Pair(-60, 77), Pair(-2, 58), Pair(0, 0), Pair(-5, 60), Pair(18, 108), Pair(8, 30), Pair(21, 18), Pair(17, 13),
        Pair(49, 38), Pair(48, -241), Pair(3, 158), Pair(-9, -44), Pair(9, 41), Pair(42, -34), Pair(-8, 37), Pair(-4, -19),
        Pair(-5, 34), Pair(-11, -82), Pair(-9, 77), Pair(-24, 31), Pair(34, 70), Pair(-11, 39), Pair(-32, 35), Pair(133, -96)
      },
      { // Piece 2
        Pair(29, 75), Pair(-16, 11), Pair(54, -2), Pair(-40, 43), Pair(-50, 81), Pair(1, 55), Pair(46, 69), Pair(21, -29),
        Pair(-4, 38), Pair(19, 48), Pair(-28, 47), Pair(6, 70), Pair(-18, 56), Pair(-83, 84), Pair(-91, 90), Pair(68, 87),
        Pair(62, 34), Pair(-18, 35), Pair(61, 22), Pair(-30, 79), Pair(22, 33), Pair(62, 101), Pair(-4, 104), Pair(62, 39),
        Pair(-61, 46), Pair(26, 29), Pair(-33, 59), Pair(-3, 55), Pair(3, 61), Pair(-39, 144), Pair(19, 63), Pair(16, 1),
        Pair(-21, 142), Pair(33, 13), Pair(24, 38), Pair(40, 21), Pair(13, 97), Pair(32, 23), Pair(3, 58), Pair(23, -25),
        Pair(-20, 38), Pair(-23, 130), Pair(0, 0), Pair(-6, 114), Pair(22, 43), Pair(6, 34), Pair(11, 20), Pair(6, 7),
        Pair(1, 54), Pair(-10, -27), Pair(37, 170), Pair(-20, -57), Pair(-9, 61), Pair(-8, 29), Pair(-6, 14), Pair(43, -24),
        Pair(-114, -9), Pair(-15, 89), Pair(-7, 34), Pair(-14, 123), Pair(-12, 34), Pair(32, 19), Pair(5, 40), Pair(-1, 39)
      },
      { // Piece 3
        Pair(9, 56), Pair(74, 41), Pair(65, 46), Pair(102, 1), Pair(-3, 57), Pair(-17, 57), Pair(28, 66), Pair(-64, 84),
        Pair(-4, 24), Pair(4, 53), Pair(72, 59), Pair(39, 49), Pair(-22, 35), Pair(82, 22), Pair(209, -24), Pair(101, 28),
        Pair(4, 45), Pair(7, 25), Pair(30, 80), Pair(16, 48), Pair(14, 20), Pair(-13, 78), Pair(-8, 36), Pair(61, 21),
        Pair(12, 31), Pair(-17, 25), Pair(-20, 83), Pair(49, 38), Pair(-36, 59), Pair(-7, 10), Pair(68, 5), Pair(93, 0),
        Pair(-1, 34), Pair(-14, 13), Pair(75, 75), Pair(-2, 49), Pair(-12, 41), Pair(61, 12), Pair(12, 40), Pair(3, 34),
        Pair(-39, 95), Pair(-4, 40), Pair(0, 0), Pair(38, 34), Pair(58, 12), Pair(29, 15), Pair(-8, 60), Pair(10, 4),
        Pair(-40, 94), Pair(-58, 3), Pair(-21, 126), Pair(-68, 46), Pair(1, 64), Pair(12, 53), Pair(23, 24), Pair(-65, 55),
        Pair(-11, 57), Pair(4, 41), Pair(-38, 95), Pair(-13, 59), Pair(22, 22), Pair(13, 40), Pair(26, 12), Pair(55, 13)
      },
      { // Piece 4
        Pair(71, -4), Pair(127, 5), Pair(-15, 123), Pair(19, 71), Pair(91, 46), Pair(57, -11), Pair(45, -58), Pair(-25, 44),
        Pair(-14, 0), Pair(6, 60), Pair(-4, 61), Pair(13, 2), Pair(-45, 231), Pair(52, 53), Pair(98, -28), Pair(34, 12),
        Pair(-11, 25), Pair(75, 17), Pair(-22, 94), Pair(-25, 119), Pair(11, 31), Pair(22, 59), Pair(10, 102), Pair(128, -28),
        Pair(46, -72), Pair(-11, 24), Pair(34, 57), Pair(-29, 112), Pair(13, 63), Pair(34, 106), Pair(68, 7), Pair(26, 8),
        Pair(21, 82), Pair(-12, 55), Pair(93, 19), Pair(-15, 75), Pair(5, 70), Pair(29, 22), Pair(64, 1), Pair(-25, 73),
        Pair(-66, 29), Pair(43, 57), Pair(0, 0), Pair(-15, 81), Pair(14, 52), Pair(-20, 61), Pair(50, -6), Pair(9, 32),
        Pair(33, 44), Pair(-24, -30), Pair(9, 55), Pair(-8, 53), Pair(-3, 24), Pair(-5, 19), Pair(10, 25), Pair(47, 10),
        Pair(-31, 48), Pair(-19, 91), Pair(-52, 46), Pair(-5, -4), Pair(35, -26), Pair(1, 33), Pair(-10, -64), Pair(-19, 51)
      },
      { // Piece 5
        Pair(-15, -4), Pair(-99, -204), Pair(-38, -135), Pair(36, 85), Pair(-5, -65), Pair(-24, -103), Pair(22, -119), Pair(-26, -157),
        Pair(-18, -145), Pair(3, -37), Pair(-59, 4), Pair(8, -63), Pair(4, -82), Pair(-82, -70), Pair(94, -87), Pair(-46, -71),
        Pair(25, 0), Pair(-1, -40), Pair(82, -93), Pair(74, -68), Pair(100, -59), Pair(67, -32), Pair(121, -73), Pair(-28, -94),
        Pair(76, 4), Pair(76, -33), Pair(73, -14), Pair(167, -8), Pair(120, -29), Pair(90, -28), Pair(54, -46), Pair(-64, -46),
        Pair(174, 6), Pair(63, 10), Pair(38, 30), Pair(59, 16), Pair(17, 0), Pair(20, -6), Pair(-24, -6), Pair(-2, -37),
        Pair(-89, 29), Pair(-121, 109), Pair(0, 0), Pair(-85, 71), Pair(-5, 8), Pair(43, -5), Pair(8, -20), Pair(10, -47),
        Pair(-152, 90), Pair(32, 103), Pair(-212, 129), Pair(-31, 110), Pair(-71, 43), Pair(-38, 10), Pair(21, -31), Pair(23, -44),
        Pair(-73, 29), Pair(-107, 49), Pair(-173, 89), Pair(-64, 83), Pair(-74, 6), Pair(-28, 13), Pair(5, -39), Pair(17, -69)
      }
    }},
    {{ // Bucket 19
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-27, 30), Pair(-30, 16), Pair(5, 4), Pair(10, -3), Pair(-47, 41), Pair(13, 29), Pair(-22, 22), Pair(41, -5),
        Pair(2, 4), Pair(10, 2), Pair(21, 1), Pair(0, 0), Pair(38, -7), Pair(-20, 11), Pair(-11, 13), Pair(-11, 19),
        Pair(0, -5), Pair(-10, -2), Pair(-1, -4), Pair(1, -4), Pair(1, 7), Pair(2, -3), Pair(-2, 3), Pair(-4, 7),
        Pair(-5, 2), Pair(-1, -10), Pair(-7, 2), Pair(9, -15), Pair(-5, -5), Pair(-11, 4), Pair(-10, -2), Pair(-2, -1),
        Pair(0, -7), Pair(-8, 1), Pair(-3, 2), Pair(0, 0), Pair(-1, -1), Pair(-8, 2), Pair(-5, -3), Pair(-1, -6),
        Pair(-4, 0), Pair(-3, -4), Pair(-5, -23), Pair(4, 29), Pair(-4, -34), Pair(-13, 2), Pair(1, -4), Pair(-2, -4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-65, 13), Pair(-205, 142), Pair(120, -32), Pair(147, 3), Pair(-89, 41), Pair(113, -4), Pair(12, -81), Pair(56, -134),
        Pair(-23, 63), Pair(11, 16), Pair(10, -23), Pair(121, 21), Pair(29, 9), Pair(7, 29), Pair(148, -46), Pair(-24, 28),
        Pair(45, -23), Pair(15, 34), Pair(-8, 39), Pair(72, -10), Pair(41, 52), Pair(54, 42), Pair(37, -4), Pair(-30, -8),
        Pair(12, -3), Pair(-3, 66), Pair(16, 19), Pair(38, 30), Pair(43, 49), Pair(37, 31), Pair(37, 40), Pair(48, 5),
        Pair(37, 36), Pair(-78, 53), Pair(-8, 117), Pair(17, 27), Pair(16, 94), Pair(48, 15), Pair(19, 63), Pair(15, 17),
        Pair(-35, 10), Pair(-21, 106), Pair(-19, 69), Pair(0, 0), Pair(-10, 72), Pair(5, 108), Pair(10, 15), Pair(37, 8),
        Pair(27, 17), Pair(12, 17), Pair(9, -7), Pair(16, 166), Pair(-2, -15), Pair(39, 70), Pair(-13, 29), Pair(1, -38),
        Pair(-72, -92), Pair(-15, 16), Pair(-24, -63), Pair(8, 63), Pair(-20, 18), Pair(-14, 132), Pair(-2, -50), Pair(-66, -84)
      },
      { // Piece 2
        Pair(-60, 77), Pair(-196, 89), Pair(73, 29), Pair(-10, 25), Pair(24, 70), Pair(-10, 38), Pair(-29, 19), Pair(88, 87),
        Pair(40, 30), Pair(-8, 60), Pair(-23, 70), Pair(86, 69), Pair(-40, 90), Pair(-12, 69), Pair(-105, 68), Pair(-61, 92),
        Pair(25, 9), Pair(-32, 92), Pair(10, 66), Pair(39, 31), Pair(7, 49), Pair(-11, 63), Pair(-2, 81), Pair(14, 131),
        Pair(-23, 103), Pair(-42, 71), Pair(0, 27), Pair(2, 53), Pair(19, 46), Pair(-54, 96), Pair(-7, 106), Pair(14, 60),
        Pair(-14, 95), Pair(-32, 105), Pair(-15, 40), Pair(57, 53), Pair(-28, 79), Pair(13, 115), Pair(-47, 65), Pair(-13, 24),
        Pair(6, 41), Pair(-15, 66), Pair(16, 91), Pair(0, 0), Pair(17, 103), Pair(16, 72), Pair(-7, 11), Pair(23, -1),
        Pair(-56, 64), Pair(28, 48), Pair(-31, -5), Pair(24, 172), Pair(16, -47), Pair(7, 44), Pair(14, 9), Pair(7, -3),
        Pair(35, -16), Pair(-38, -5), Pair(-7, 90), Pair(-14, 44), Pair(-12, 97), Pair(21, -42), Pair(2, -34), Pair(1, -7)
      },
      { // Piece 3
        Pair(53, 17), Pair(15, 34), Pair(33, 72), Pair(48, 60), Pair(-15, 93), Pair(103, -7), Pair(119, 15), Pair(19, 51),
        Pair(-6, 39), Pair(-12, 52), Pair(-30, 63), Pair(-26, 81), Pair(4, 39), Pair(27, 22), Pair(-40, 63), Pair(42, 48),
        Pair(26, 23), Pair(9, 19), Pair(14, 59), Pair(53, 46), Pair(27, 4), Pair(133, 22), Pair(47, 29), Pair(-24, 63),
        Pair(37, 25), Pair(10, 20), Pair(37, 35), Pair(12, 45), Pair(21, 32), Pair(18, 30), Pair(26, 4), Pair(27, 46),
        Pair(-25, 24), Pair(-13, 5), Pair(4, 42), Pair(-26, 97), Pair(23, 35), Pair(23, 49), Pair(-36, 45), Pair(27, 0),
        Pair(31, 2), Pair(5, 43), Pair(12, 65), Pair(0, 0), Pair(4, 18), Pair(3, 26), Pair(80, -22), Pair(29, 32),
        Pair(-54, 86), Pair(-33, 125), Pair(66, -24), Pair(-6, 112), Pair(-6, 107), Pair(4, 80), Pair(0, 35), Pair(1, 58),
        Pair(-9, 58), Pair(11, 21), Pair(-11, 40), Pair(-31, 101), Pair(-21, 49), Pair(2, 50), Pair(19, 37), Pair(20, 20)
      },
      { // Piece 4
        Pair(65, 29), Pair(4, 81), Pair(68, 45), Pair(-17, 72), Pair(-14, 92), Pair(44, 65), Pair(9, 24), Pair(67, 26),
        Pair(32, 24), Pair(-18, 78), Pair(66, 29), Pair(41, 44), Pair(35, 76), Pair(-5, 86), Pair(83, -66), Pair(87, -4),
        Pair(75, -49), Pair(-19, 78), Pair(-1, -32), Pair(0, 95), Pair(12, 136), Pair(-64, 90), Pair(-13, 96), Pair(32, 100),
        Pair(-23, 69), Pair(-21, 14), Pair(16, 11), Pair(47, 56), Pair(7, 62), Pair(23, 111), Pair(-8, 88), Pair(20, 33),
        Pair(3, 28), Pair(-29, 92), Pair(64, -68), Pair(1, 95), Pair(36, 24), Pair(-4, 74), Pair(-12, 94), Pair(-20, 113),
        Pair(48, -81), Pair(21, -24), Pair(18, 49), Pair(0, 0), Pair(0, 49), Pair(-3, -8), Pair(45, -1), Pair(30, -18),
        Pair(-3, 9), Pair(-6, 29), Pair(27, -15), Pair(5, 62), Pair(-54, 3), Pair(27, -14), Pair(-28, 129), Pair(90, -53),
        Pair(7, 94), Pair(-25, -38), Pair(-19, 24), Pair(-10, 50), Pair(-22, 47), Pair(12, -22), Pair(34, -108), Pair(37, -47)
      },
      { // Piece 5
        Pair(-18, -108), Pair(-12, -62), Pair(1, -62), Pair(-2, -74), Pair(-16, -68), Pair(-7, -50), Pair(-60, -117), Pair(-117, -87),
        Pair(8, 4), Pair(-15, -48), Pair(17, -7), Pair(17, -77), Pair(-90, 12), Pair(-70, -70), Pair(-65, -43), Pair(9, -20),
        Pair(38, -108), Pair(-61, -61), Pair(-26, -31), Pair(-10, -80), Pair(94, -58), Pair(22, -11), Pair(-76, -35), Pair(-26, -18),
        Pair(48, -26), Pair(80, -32), Pair(212, -71), Pair(45, -32), Pair(3, 36), Pair(70, -10), Pair(-10, -30), Pair(-119, -19),
        Pair(-24, -69), Pair(15, -10), Pair(-12, 23), Pair(-69, 29), Pair(25, 29), Pair(102, -4), Pair(17, -15), Pair(-24, -26),
        Pair(-12, -29), Pair(-95, 67), Pair(-77, 62), Pair(0, 0), Pair(-27, 61), Pair(-37, 25), Pair(33, -28), Pair(0, -16),
        Pair(39, -6), Pair(-101, 49), Pair(-49, -72), Pair(-85, 88), Pair(119, -43), Pair(-39, 15), Pair(1, -5), Pair(24, -38),
        Pair(47, -44), Pair(-98, 45), Pair(-87, 78), Pair(-39, 75), Pair(-20, 69), Pair(-34, 9), Pair(21, -28), Pair(32, -47)
      }
    }},
    {{ // Bucket 20
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(17, 14), Pair(18, -21), Pair(-48, 32), Pair(4, -9), Pair(-63, 79), Pair(24, -16), Pair(3, 11), Pair(-25, 10),
        Pair(3, 1), Pair(1, -10), Pair(3, -2), Pair(-38, 7), Pair(0, 0), Pair(-5, 5), Pair(7, -5), Pair(19, -7),
        Pair(-5, -7), Pair(9, -20), Pair(-9, -2), Pair(3, -5), Pair(1, -9), Pair(-6, -2), Pair(9, -7), Pair(4, -3),
        Pair(2, -8), Pair(-1, -10), Pair(0, -8), Pair(-16, 2), Pair(14, -13), Pair(-6, -2), Pair(-11, 1), Pair(2, -2),
        Pair(3, -14), Pair(6, -18), Pair(-1, -6), Pair(-6, 4), Pair(0, 0), Pair(-17, 2), Pair(-4, 2), Pair(3, -9),
        Pair(-4, -9), Pair(8, -12), Pair(0, -7), Pair(17, -46), Pair(20, 13), Pair(-7, -38), Pair(-4, 2), Pair(3, -7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-79, -59), Pair(0, 51), Pair(105, -29), Pair(-90, 28), Pair(-158, 24), Pair(96, 17), Pair(64, 23), Pair(58, -162),
        Pair(97, -21), Pair(-30, -8), Pair(34, 21), Pair(102, 2), Pair(-80, 59), Pair(2, 47), Pair(-61, -25), Pair(200, -74),
        Pair(-141, 82), Pair(-62, 47), Pair(50, 19), Pair(27, -6), Pair(29, 15), Pair(82, 19), Pair(54, 3), Pair(120, 3),
        Pair(-57, -40), Pair(-13, 35), Pair(-4, 2), Pair(40, -19), Pair(15, 18), Pair(35, -17), Pair(28, -4), Pair(41, 3),
        Pair(-23, -11), Pair(-48, 64), Pair(-29, 55), Pair(-49, 102), Pair(-21, 48), Pair(-1, 75), Pair(-55, 43), Pair(43, 40),
        Pair(-15, -28), Pair(0, 5), Pair(-12, 63), Pair(6, 35), Pair(0, 0), Pair(4, 44), Pair(25, 77), Pair(-27, 22),
        Pair(-36, -39), Pair(-68, 13), Pair(-11, 14), Pair(-11, -83), Pair(15, 129), Pair(-58, 1), Pair(-3, 56), Pair(32, 11),
        Pair(-143, 102), Pair(-39, -15), Pair(-28, 96), Pair(-14, -46), Pair(15, 23), Pair(14, -10), Pair(-20, 39), Pair(-206, -22)
      },
      { // Piece 2
        Pair(-39, 43), Pair(-100, -1), Pair(40, 69), Pair(-30, 0), Pair(-207, 91), Pair(-144, 48), Pair(10, 27), Pair(181, 97),
        Pair(15, 44), Pair(-38, 65), Pair(36, 6), Pair(-15, 76), Pair(-8, 63), Pair(101, 77), Pair(-29, 81), Pair(20, 68),
        Pair(-30, 80), Pair(-40, 76), Pair(-16, 55), Pair(34, 0), Pair(-27, 61), Pair(4, 47), Pair(-35, 48), Pair(103, 2),
        Pair(-15, 28), Pair(-63, 124), Pair(-24, 21), Pair(39, 1), Pair(3, 25), Pair(-25, 27), Pair(-2, 63), Pair(11, 71),
        Pair(16, 15), Pair(-26, 64), Pair(11, 91), Pair(9, 62), Pair(21, 21), Pair(-29, 30), Pair(-18, 85), Pair(-43, 5),
        Pair(19, -52), Pair(-5, 9), Pair(-44, 84), Pair(-7, 107), Pair(0, 0), Pair(-7, 103), Pair(-5, 49), Pair(-17, 0),
        Pair(-11, -19), Pair(17, -15), Pair(-40, 17), Pair(-23, -26), Pair(10, 139), Pair(-20, -1), Pair(-2, 18), Pair(32, 2),
        Pair(4, -27), Pair(38, 4), Pair(-40, -13), Pair(6, 85), Pair(-28, 33), Pair(-81, 123), Pair(-46, -38), Pair(12, 19)
      },
      { // Piece 3
        Pair(14, 17), Pair(-21, -13), Pair(-42, 28), Pair(49, -10), Pair(-4, 16), Pair(118, -39), Pair(-113, 80), Pair(-24, 28),
        Pair(6, 30), Pair(37, -20), Pair(60, -23), Pair(59, -11), Pair(7, 10), Pair(70, 13), Pair(129, -59), Pair(41, 5),
        Pair(-51, 12), Pair(-7, 18), Pair(-20, 35), Pair(48, -13), Pair(20, 26), Pair(-13, 3), Pair(106, -38), Pair(36, -9),
        Pair(-38, 9), Pair(-12, 24), Pair(28, 8), Pair(7, 14), Pair(23, 30), Pair(48, -36), Pair(-2, 37), Pair(43, -16),
        Pair(-59, 21), Pair(10, -26), Pair(-40, 0), Pair(-56, 25), Pair(-40, 45), Pair(39, -21), Pair(42, 9), Pair(67, -8),
        Pair(-94, 19), Pair(-15, 17), Pair(28, -22), Pair(-24, 24), Pair(0, 0), Pair(12, -24), Pair(71, -30), Pair(18, -17),
        Pair(-46, 76), Pair(-11, 12), Pair(-13, 60), Pair(-72, 79), Pair(5, 83), Pair(-23, 10), Pair(-20, 57), Pair(5, 25),
        Pair(-14, 24), Pair(11, -1), Pair(-4, 3), Pair(-12, 5), Pair(-22, 56), Pair(-1, 13), Pair(11, 14), Pair(22, -15)
      },
      { // Piece 4
        Pair(-9, 67), Pair(-83, -8), Pair(-93, 163), Pair(79, -27), Pair(-61, 113), Pair(-104, 119), Pair(-52, 106), Pair(83, -49),
        Pair(-10, -6), Pair(-47, 41), Pair(-40, 6), Pair(-60, 95), Pair(-7, -1), Pair(88, -63), Pair(60, 17), Pair(66, -65),
        Pair(-22, 23), Pair(49, -4), Pair(62, -86), Pair(-16, 35), Pair(-23, 72), Pair(-1, 128), Pair(75, -39), Pair(31, 49),
        Pair(-25, 21), Pair(-39, 40), Pair(5, 73), Pair(9, 64), Pair(4, 20), Pair(10, 64), Pair(83, -79), Pair(-47, 113),
        Pair(-39, -24), Pair(-60, -14), Pair(-39, 86), Pair(6, -75), Pair(-26, -29), Pair(60, -111), Pair(7, 59), Pair(8, 15),
        Pair(-4, -23), Pair(-1, -68), Pair(13, -19), Pair(-5, -4), Pair(0, 0), Pair(-12, 49), Pair(-35, 54), Pair(-8, -10),
        Pair(28, -24), Pair(-2, 29), Pair(-29, 20), Pair(-11, -65), Pair(-17, 39), Pair(-11, -64), Pair(-59, 123), Pair(-57, 128),
        Pair(-19, -53), Pair(-73, 9), Pair(-28, -35), Pair(-13, -51), Pair(-23, -70), Pair(-22, 13), Pair(-9, -9), Pair(8, -60)
      },
      { // Piece 5
        Pair(-14, -146), Pair(18, -135), Pair(-33, -141), Pair(-81, -109), Pair(-63, -124), Pair(-14, 32), Pair(17, -74), Pair(6, -126),
        Pair(10, -167), Pair(36, -33), Pair(20, -52), Pair(7, -15), Pair(-15, -85), Pair(12, -83), Pair(-9, -62), Pair(-34, -109),
        Pair(-8, -46), Pair(-1, -19), Pair(80, -49), Pair(171, -56), Pair(67, -67), Pair(202, -68), Pair(-7, -38), Pair(51, 5),
        Pair(-69, -73), Pair(-39, -43), Pair(3, -21), Pair(6, -13), Pair(-20, 4), Pair(178, -50), Pair(51, -30), Pair(-5, -18),
        Pair(85, -88), Pair(-39, -31), Pair(-75, 4), Pair(-5, 5), Pair(-129, 62), Pair(62, 20), Pair(13, -13), Pair(74, 1),
        Pair(84, -103), Pair(3, -52), Pair(74, 12), Pair(-102, 66), Pair(0, 0), Pair(-3, 41), Pair(-10, 14), Pair(39, -21),
        Pair(48, -9), Pair(-38, -5), Pair(-6, -3), Pair(-54, 51), Pair(-125, 76), Pair(3, 36), Pair(-37, 24), Pair(-7, 8),
        Pair(15, -45), Pair(-19, -41), Pair(-28, 7), Pair(-57, 60), Pair(-10, 53), Pair(-73, 64), Pair(-30, 14), Pair(-1, -7)
      }
    }},
    {{ // Bucket 21
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(20, -2), Pair(16, 13), Pair(-13, 14), Pair(-21, -5), Pair(-7, 0), Pair(5, -41), Pair(8, -12), Pair(7, 11),
        Pair(29, -16), Pair(20, -18), Pair(6, -9), Pair(19, -11), Pair(5, -5), Pair(0, 0), Pair(45, -7), Pair(-8, 0),
        Pair(6, -10), Pair(-6, -10), Pair(-6, -9), Pair(0, -5), Pair(-7, 0), Pair(-19, 5), Pair(-11, -2), Pair(-7, 0),
        Pair(6, -13), Pair(-8, -14), Pair(-2, -18), Pair(0, -12), Pair(5, -13), Pair(1, -4), Pair(18, -8), Pair(-2, 0),
        Pair(4, -14), Pair(-5, -9), Pair(-1, -6), Pair(-10, 0), Pair(-2, -12), Pair(0, 0), Pair(15, -10), Pair(15, -5),
        Pair(1, -13), Pair(3, -11), Pair(-1, -13), Pair(11, -3), Pair(7, -23), Pair(17, -1), Pair(31, -37), Pair(12, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(14, -132), Pair(10, -30), Pair(70, -3), Pair(109, -28), Pair(-139, -9), Pair(-6, -21), Pair(-54, 6), Pair(62, 15),
        Pair(-52, 39), Pair(-2, -48), Pair(0, 27), Pair(-52, 24), Pair(73, -6), Pair(135, -34), Pair(-51, -29), Pair(-145, 28),
        Pair(14, -50), Pair(27, -32), Pair(-62, 31), Pair(41, 26), Pair(12, 16), Pair(105, -57), Pair(30, -8), Pair(-46, 34),
        Pair(-3, -3), Pair(-60, 8), Pair(6, -17), Pair(56, 12), Pair(56, 7), Pair(21, 1), Pair(110, -41), Pair(119, -58),
        Pair(-58, 33), Pair(-16, -3), Pair(-1, 10), Pair(73, -11), Pair(26, 23), Pair(49, -5), Pair(45, 51), Pair(36, 26),
        Pair(-45, -13), Pair(-34, 26), Pair(-36, 14), Pair(-43, 52), Pair(-17, 30), Pair(0, 0), Pair(1, 31), Pair(-31, -30),
        Pair(4, -41), Pair(-32, 48), Pair(2, 19), Pair(-4, 17), Pair(-76, -27), Pair(13, 105), Pair(-26, -24), Pair(23, -15),
        Pair(-41, -102), Pair(-41, 16), Pair(-21, 28), Pair(-56, 59), Pair(1, -25), Pair(-3, 14), Pair(-56, -104), Pair(-174, 127)
      },
      { // Piece 2
        Pair(-29, 90), Pair(-37, 6), Pair(46, 57), Pair(-53, 41), Pair(-92, 41), Pair(-70, 44), Pair(-14, 24), Pair(-130, 42),
        Pair(-93, 65), Pair(-18, 22), Pair(-70, 68), Pair(-72, 41), Pair(-80, 65), Pair(-23, 36), Pair(-72, 14), Pair(-22, 46),
        Pair(-8, 21), Pair(-87, 50), Pair(-11, 76), Pair(0, 39), Pair(-17, 54), Pair(23, 19), Pair(-71, 48), Pair(-13, -9),
        Pair(-65, 16), Pair(0, 25), Pair(-56, 58), Pair(-49, 57), Pair(38, 19), Pair(-5, 58), Pair(2, -30), Pair(-3, -5),
        Pair(-1, -13), Pair(-51, 20), Pair(7, 8), Pair(-4, 23), Pair(19, -7), Pair(15, 22), Pair(-8, 38), Pair(-39, 75),
        Pair(-19, -9), Pair(5, 19), Pair(-6, -7), Pair(34, -2), Pair(-5, 29), Pair(0, 0), Pair(-3, 59), Pair(28, 18),
        Pair(-16, 9), Pair(-24, 1), Pair(23, 11), Pair(-24, 11), Pair(38, -63), Pair(-8, 118), Pair(-17, -72), Pair(-41, 45),
        Pair(9, -23), Pair(12, 59), Pair(-29, -25), Pair(-5, 0), Pair(-40, 66), Pair(-7, -8), Pair(-186, 69), Pair(-89, -126)
      },
      { // Piece 3
        Pair(-34, 23), Pair(-35, 26), Pair(54, 18), Pair(-65, 29), Pair(35, -6), Pair(97, 9), Pair(6, 5), Pair(25, 5),
        Pair(-8, -2), Pair(23, -38), Pair(65, -33), Pair(5, -2), Pair(-64, 33), Pair(15, 16), Pair(3, -4), Pair(65, -20),
        Pair(-6, -17), Pair(-11, 0), Pair(51, -24), Pair(-19, 10), Pair(-9, 30), Pair(19, 3), Pair(-8, 5), Pair(100, -38),
        Pair(-47, 9), Pair(-3, -16), Pair(-9, -3), Pair(-22, 8), Pair(14, -6), Pair(86, 7), Pair(34, -37), Pair(89, -54),
        Pair(-41, 9), Pair(-37, -2), Pair(-15, 18), Pair(34, -24), Pair(-14, 12), Pair(54, 10), Pair(74, -42), Pair(23, 0),
        Pair(-1, 10), Pair(-8, -41), Pair(-1, -17), Pair(-40, 27), Pair(30, 0), Pair(0, 0), Pair(51, -22), Pair(24, -37),
        Pair(-4, 8), Pair(-51, 5), Pair(-32, 26), Pair(-5, 10), Pair(5, -68), Pair(-15, 63), Pair(78, -26), Pair(-21, 37),
        Pair(-21, -15), Pair(-1, -34), Pair(-24, -2), Pair(10, -33), Pair(-38, 33), Pair(-35, 5), Pair(12, -15), Pair(-17, -26)
      },
      { // Piece 4
        Pair(-17, -56), Pair(-20, -5), Pair(-22, 4), Pair(43, -38), Pair(-57, 75), Pair(-15, -20), Pair(42, 36), Pair(25, 51),
        Pair(-71, 20), Pair(-48, -22), Pair(-45, 47), Pair(-3, -35), Pair(-111, 82), Pair(50, 3), Pair(-39, 30), Pair(22, -128),
        Pair(-2, -68), Pair(-56, -14), Pair(-32, 28), Pair(-14, 31), Pair(-17, -53), Pair(131, -84), Pair(73, -66), Pair(35, -51),
        Pair(-34, -50), Pair(-1, -48), Pair(-55, 40), Pair(-59, 72), Pair(21, 1), Pair(-1, -25), Pair(25, -64), Pair(13, -7),
        Pair(8, -62), Pair(-21, 11), Pair(-44, -13), Pair(-45, 62), Pair(-68, 67), Pair(11, -11), Pair(-23, 52), Pair(-18, -6),
        Pair(-75, -15), Pair(-29, 4), Pair(-18, -8), Pair(-32, 10), Pair(-17, -24), Pair(0, 0), Pair(-38, -62), Pair(-9, -33),
        Pair(-21, -76), Pair(-73, 30), Pair(-44, -27), Pair(-40, -9), Pair(-85, 29), Pair(-67, 97), Pair(-121, 41), Pair(-101, 18),
        Pair(-56, 14), Pair(6, -78), Pair(-30, -8), Pair(-2, -79), Pair(-31, 33), Pair(-1, -85), Pair(-58, 104), Pair(-86, 48)
      },
      { // Piece 5
        Pair(30, -70), Pair(-22, -108), Pair(-26, -103), Pair(-115, -125), Pair(-73, -103), Pair(0, -102), Pair(-11, -167), Pair(-4, -44),
        Pair(-58, -180), Pair(25, -104), Pair(114, -104), Pair(86, -69), Pair(-18, -26), Pair(-15, -54), Pair(14, -73), Pair(56, 20),
        Pair(50, -83), Pair(-31, -68), Pair(34, -60), Pair(20, -21), Pair(-29, -56), Pair(62, -53), Pair(44, -56), Pair(21, -50),
        Pair(-98, -69), Pair(123, -70), Pair(51, -33), Pair(80, -49), Pair(233, -37), Pair(97, -6), Pair(33, -27), Pair(157, -67),
        Pair(-8, -53), Pair(79, -81), Pair(74, -27), Pair(99, -37), Pair(67, 16), Pair(-23, 43), Pair(77, 26), Pair(-6, 6),
        Pair(-20, -18), Pair(135, -96), Pair(46, 7), Pair(-74, 28), Pair(-83, 48), Pair(0, 0), Pair(-40, 51), Pair(-77, 65),
        Pair(18, -43), Pair(95, -38), Pair(125, -30), Pair(-28, 25), Pair(67, 92), Pair(-103, 80), Pair(-64, 60), Pair(-96, 58),
        Pair(59, -69), Pair(20, -24), Pair(-5, -6), Pair(-17, 2), Pair(6, 27), Pair(-110, 54), Pair(-44, 30), Pair(-59, 32)
      }
    }},
    {{ // Bucket 22
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-24, 12), Pair(5, -4), Pair(43, 2), Pair(-42, 23), Pair(-28, 11), Pair(-7, -26), Pair(10, 33), Pair(15, -25),
        Pair(-2, -2), Pair(13, -16), Pair(-18, -9), Pair(10, -13), Pair(-7, 6), Pair(-45, 7), Pair(0, 0), Pair(15, -5),
        Pair(4, -10), Pair(0, -9), Pair(11, -27), Pair(-1, -14), Pair(-14, 3), Pair(7, -14), Pair(-20, 3), Pair(-3, 8),
        Pair(16, -19), Pair(-15, -12), Pair(-3, -12), Pair(1, -18), Pair(5, -8), Pair(0, -12), Pair(-15, -11), Pair(1, -6),
        Pair(4, -20), Pair(-4, -13), Pair(4, -17), Pair(-2, -7), Pair(7, -1), Pair(-1, 4), Pair(0, 0), Pair(6, 0),
        Pair(12, -19), Pair(0, -6), Pair(-1, -10), Pair(9, -30), Pair(-23, -7), Pair(-10, -10), Pair(12, -3), Pair(-2, -4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(75, -88), Pair(115, -180), Pair(-27, -92), Pair(-118, -52), Pair(-15, 22), Pair(5, -31), Pair(12, -97), Pair(26, -31),
        Pair(-36, -26), Pair(45, -7), Pair(63, -16), Pair(22, 23), Pair(18, 10), Pair(-12, -35), Pair(23, -59), Pair(63, -68),
        Pair(-19, -18), Pair(-24, -35), Pair(50, -14), Pair(-3, -13), Pair(3, 7), Pair(11, -26), Pair(34, -44), Pair(64, -10),
        Pair(-2, -28), Pair(-32, -43), Pair(-18, -28), Pair(-2, 12), Pair(46, 1), Pair(33, -7), Pair(32, 29), Pair(39, -22),
        Pair(65, -54), Pair(-45, -14), Pair(-65, 3), Pair(18, 27), Pair(-10, -10), Pair(65, 56), Pair(35, -15), Pair(-15, 18),
        Pair(-65, 35), Pair(1, -54), Pair(1, -29), Pair(13, -9), Pair(-5, 32), Pair(13, 16), Pair(0, 0), Pair(6, -7),
        Pair(46, -34), Pair(-49, -12), Pair(-25, -20), Pair(-18, 17), Pair(20, -5), Pair(15, -83), Pair(13, 84), Pair(24, -81),
        Pair(-10, -45), Pair(-5, -81), Pair(-7, -54), Pair(62, -39), Pair(-51, -13), Pair(-82, -10), Pair(-10, -4), Pair(-119, -114)
      },
      { // Piece 2
        Pair(-82, 112), Pair(30, 74), Pair(-191, 35), Pair(-126, 2), Pair(-67, 55), Pair(56, -6), Pair(-116, 21), Pair(59, -80),
        Pair(-119, 77), Pair(-11, 72), Pair(50, -8), Pair(-98, 61), Pair(-56, 68), Pair(-187, 47), Pair(-176, 67), Pair(24, -32),
        Pair(-11, -25), Pair(-94, 42), Pair(-84, 83), Pair(31, 35), Pair(16, 12), Pair(-53, 24), Pair(17, -39), Pair(-14, 19),
        Pair(-80, 2), Pair(-8, -10), Pair(30, 9), Pair(5, 56), Pair(7, 34), Pair(24, 22), Pair(-7, 25), Pair(12, -3),
        Pair(-17, -17), Pair(-57, 16), Pair(-49, 10), Pair(-35, 22), Pair(-19, 47), Pair(2, 22), Pair(22, 10), Pair(35, -40),
        Pair(-14, 11), Pair(-57, 28), Pair(-17, 29), Pair(18, -28), Pair(-9, 45), Pair(6, 26), Pair(0, 0), Pair(22, 60),
        Pair(-5, -12), Pair(-4, 26), Pair(-13, 14), Pair(-20, 12), Pair(-14, 9), Pair(-80, -23), Pair(18, 117), Pair(17, 25),
        Pair(46, -39), Pair(-48, -14), Pair(-5, 7), Pair(-8, 3), Pair(-19, -12), Pair(-1, 31), Pair(-66, 29), Pair(-25, 115)
      },
      { // Piece 3
        Pair(-9, -14), Pair(85, -22), Pair(87, -49), Pair(52, -17), Pair(-68, 23), Pair(-73, 23), Pair(132, -26), Pair(-113, 40),
        Pair(110, -85), Pair(66, -31), Pair(32, -22), Pair(10, -26), Pair(67, 3), Pair(107, -60), Pair(152, -17), Pair(95, -14),
        Pair(-3, -39), Pair(18, -46), Pair(40, -17), Pair(91, -66), Pair(-1, -9), Pair(30, -44), Pair(74, -21), Pair(93, -36),
        Pair(79, -60), Pair(44, -44), Pair(7, -47), Pair(24, -20), Pair(86, -44), Pair(61, -37), Pair(-29, 12), Pair(-3, -28),
        Pair(-27, -21), Pair(-10, -1), Pair(110, -45), Pair(-58, 12), Pair(30, -22), Pair(66, -48), Pair(-2, -3), Pair(45, -21),
        Pair(-26, -28), Pair(8, -10), Pair(8, -2), Pair(71, -62), Pair(28, -10), Pair(97, -56), Pair(0, 0), Pair(9, 52),
        Pair(-53, 51), Pair(17, -15), Pair(-11, 18), Pair(28, 8), Pair(10, -27), Pair(7, -121), Pair(1, 26), Pair(163, -120),
        Pair(15, -9), Pair(33, -18), Pair(37, -37), Pair(0, 14), Pair(27, -19), Pair(47, -33), Pair(-56, 40), Pair(-14, -15)
      },
      { // Piece 4
        Pair(-59, 38), Pair(-52, -10), Pair(-10, 28), Pair(95, -60), Pair(25, -91), Pair(-114, 21), Pair(26, -43), Pair(75, -75),
        Pair(7, -73), Pair(-35, 18), Pair(-6, 47), Pair(-67, 1), Pair(-88, 77), Pair(-4, 25), Pair(92, -90), Pair(126, -165),
        Pair(11, -10), Pair(19, -99), Pair(-35, -13), Pair(-115, 33), Pair(-74, -2), Pair(21, -104), Pair(-31, 7), Pair(-23, -25),
        Pair(-52, 6), Pair(-64, -39), Pair(-84, 20), Pair(34, -37), Pair(28, 5), Pair(-57, 67), Pair(-3, 11), Pair(85, -83),
        Pair(-12, -55), Pair(-113, 85), Pair(8, -11), Pair(-91, 61), Pair(-3, 75), Pair(-134, 60), Pair(6, 14), Pair(-61, -32),
        Pair(-42, -97), Pair(-44, 10), Pair(-14, -18), Pair(-35, -64), Pair(-18, -24), Pair(-31, 65), Pair(0, 0), Pair(-26, -32),
        Pair(-26, -130), Pair(10, -42), Pair(-26, -63), Pair(-23, -17), Pair(-43, 2), Pair(-102, 65), Pair(-143, 139), Pair(-72, 13),
        Pair(-72, 13), Pair(16, -110), Pair(-62, -63), Pair(-26, -99), Pair(-6, -77), Pair(-28, -39), Pair(-21, -232), Pair(-128, -88)
      },
      { // Piece 5
        Pair(-11, -120), Pair(89, -97), Pair(6, -158), Pair(-10, 3), Pair(-15, -63), Pair(-15, -82), Pair(-80, -131), Pair(0, -1),
        Pair(20, -103), Pair(-12, -101), Pair(-13, -109), Pair(-78, -31), Pair(10, -20), Pair(49, -21), Pair(90, -36), Pair(21, 44),
        Pair(112, -115), Pair(67, -61), Pair(133, -40), Pair(85, -62), Pair(-1, -69), Pair(119, 14), Pair(72, -53), Pair(-42, -21),
        Pair(88, -79), Pair(226, -96), Pair(24, -34), Pair(61, -25), Pair(112, -23), Pair(149, -2), Pair(97, -54), Pair(110, -21),
        Pair(24, -65), Pair(155, -56), Pair(10, -30), Pair(105, -29), Pair(147, -20), Pair(119, 30), Pair(0, 31), Pair(5, 23),
        Pair(17, -36), Pair(65, -71), Pair(97, -27), Pair(-3, 11), Pair(-10, 21), Pair(-23, 61), Pair(0, 0), Pair(-71, 76),
        Pair(12, -62), Pair(32, -27), Pair(26, -21), Pair(3, 15), Pair(-100, 46), Pair(-14, 81), Pair(-99, 95), Pair(-94, 108),
        Pair(-62, -56), Pair(-47, -25), Pair(-41, -19), Pair(-69, -53), Pair(-100, 38), Pair(-81, 58), Pair(-77, 74), Pair(-78, 43)
      }
    }},
    {{ // Bucket 23
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(50, -21), Pair(27, -7), Pair(7, -2), Pair(22, -3), Pair(17, 4), Pair(-65, 19), Pair(39, -17), Pair(-66, 2),
        Pair(-12, -3), Pair(4, -4), Pair(5, -13), Pair(11, -18), Pair(-19, 7), Pair(8, -1), Pair(-15, 5), Pair(0, 0),
        Pair(2, -13), Pair(11, -17), Pair(15, -18), Pair(12, -17), Pair(1, -7), Pair(-5, -6), Pair(1, -5), Pair(-13, -17),
        Pair(4, -19), Pair(0, -18), Pair(5, -14), Pair(15, -14), Pair(17, -13), Pair(6, -4), Pair(3, -8), Pair(-37, 30),
        Pair(-1, -17), Pair(-2, -19), Pair(4, -10), Pair(10, -10), Pair(7, -15), Pair(-1, -8), Pair(-1, -11), Pair(0, 0),
        Pair(3, -18), Pair(4, -18), Pair(1, -10), Pair(19, -28), Pair(-13, -19), Pair(1, -8), Pair(-21, -9), Pair(-3, 11),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(47, -176), Pair(-39, -23), Pair(129, -135), Pair(-61, -33), Pair(53, -64), Pair(-16, -7), Pair(2, -111), Pair(-81, -110),
        Pair(-1, -73), Pair(3, -52), Pair(48, -68), Pair(173, -47), Pair(19, -20), Pair(134, -102), Pair(85, -102), Pair(88, -5),
        Pair(47, -105), Pair(57, -54), Pair(37, -46), Pair(34, -12), Pair(58, -35), Pair(36, -37), Pair(16, -38), Pair(9, 4),
        Pair(64, -51), Pair(3, -24), Pair(4, -22), Pair(34, -38), Pair(68, -34), Pair(87, -66), Pair(49, -48), Pair(39, 59),
        Pair(28, -49), Pair(25, -63), Pair(10, -19), Pair(65, -28), Pair(34, -25), Pair(64, -8), Pair(55, 28), Pair(24, 0),
        Pair(6, -93), Pair(13, -38), Pair(11, -17), Pair(-7, -18), Pair(29, -4), Pair(13, 35), Pair(95, -31), Pair(0, 0),
        Pair(-37, -108), Pair(-37, -35), Pair(41, -40), Pair(18, -14), Pair(-3, -11), Pair(7, 32), Pair(-83, -64), Pair(53, 91),
        Pair(26, -164), Pair(1, -88), Pair(3, -55), Pair(17, -34), Pair(-13, -4), Pair(2, 8), Pair(-38, -5), Pair(-6, 10)
      },
      { // Piece 2
        Pair(15, 37), Pair(-66, 87), Pair(24, 51), Pair(-89, 30), Pair(-198, 54), Pair(10, 10), Pair(-15, 19), Pair(-139, 54),
        Pair(-19, 22), Pair(15, 20), Pair(-82, 89), Pair(-61, 37), Pair(21, 48), Pair(49, -1), Pair(23, -5), Pair(18, -9),
        Pair(22, 24), Pair(-10, -3), Pair(6, 72), Pair(-59, 66), Pair(82, 9), Pair(15, -29), Pair(-3, 38), Pair(37, -63),
        Pair(-8, -14), Pair(57, 2), Pair(-48, 14), Pair(77, 5), Pair(24, 38), Pair(68, 17), Pair(19, 11), Pair(37, 17),
        Pair(62, -27), Pair(-1, -11), Pair(51, 12), Pair(3, -12), Pair(37, -5), Pair(17, 29), Pair(43, -9), Pair(-9, -10),
        Pair(9, 5), Pair(31, 11), Pair(-7, -14), Pair(35, 16), Pair(18, -8), Pair(63, -10), Pair(-11, 72), Pair(0, 0),
        Pair(53, -17), Pair(7, -10), Pair(50, -2), Pair(-4, 4), Pair(32, 24), Pair(-19, 21), Pair(26, 24), Pair(-11, 138),
        Pair(54, 39), Pair(38, -63), Pair(-18, 0), Pair(43, 9), Pair(-39, -28), Pair(40, -19), Pair(-68, 62), Pair(15, 19)
      },
      { // Piece 3
        Pair(17, -10), Pair(-16, 13), Pair(62, -13), Pair(-113, 41), Pair(66, -2), Pair(12, -5), Pair(13, 34), Pair(53, 17),
        Pair(29, -15), Pair(-3, 6), Pair(-35, -28), Pair(28, -6), Pair(13, -11), Pair(3, -2), Pair(48, -24), Pair(87, 10),
        Pair(49, -32), Pair(18, -10), Pair(6, -13), Pair(1, -14), Pair(39, -17), Pair(17, -20), Pair(-21, -6), Pair(29, 11),
        Pair(26, -11), Pair(60, -21), Pair(34, -24), Pair(27, -9), Pair(43, -9), Pair(22, -4), Pair(35, -14), Pair(2, 22),
        Pair(28, -43), Pair(17, -15), Pair(58, -47), Pair(0, 3), Pair(34, -15), Pair(-3, 18), Pair(15, -12), Pair(-33, 21),
        Pair(33, -52), Pair(16, 0), Pair(-16, 2), Pair(-12, -4), Pair(-36, 31), Pair(-5, 6), Pair(64, -4), Pair(0, 0),
        Pair(7, 16), Pair(13, 6), Pair(10, 7), Pair(-17, 30), Pair(2, -10), Pair(5, 35), Pair(-54, 38), Pair(8, 45),
        Pair(22, -20), Pair(9, 16), Pair(28, -24), Pair(21, 0), Pair(24, -22), Pair(12, -14), Pair(15, -7), Pair(-28, 32)
      },
      { // Piece 4
        Pair(-76, 37), Pair(-58, 92), Pair(-13, 46), Pair(-14, 9), Pair(-15, -6), Pair(74, -10), Pair(5, -18), Pair(41, -48),
        Pair(43, -6), Pair(48, -103), Pair(-4, 23), Pair(-51, 55), Pair(-16, 88), Pair(-118, 101), Pair(8, 35), Pair(9, 83),
        Pair(47, -92), Pair(-2, -21), Pair(8, -26), Pair(-55, 113), Pair(-59, 189), Pair(-9, 69), Pair(-76, 51), Pair(99, -100),
        Pair(66, -159), Pair(-20, -46), Pair(1, -83), Pair(-17, -26), Pair(-19, 70), Pair(-55, 66), Pair(-49, 64), Pair(-52, 84),
        Pair(75, -129), Pair(-60, -6), Pair(18, -51), Pair(-24, -3), Pair(19, -8), Pair(-21, 6), Pair(-55, 143), Pair(68, -34),
        Pair(21, -166), Pair(-36, -41), Pair(-12, -79), Pair(-22, 29), Pair(-26, -16), Pair(18, -10), Pair(-14, 5), Pair(0, 0),
        Pair(18, -36), Pair(-17, -62), Pair(-24, -52), Pair(-37, 40), Pair(4, -32), Pair(-8, -12), Pair(-128, -4), Pair(-64, 36),
        Pair(-39, -29), Pair(-32, -24), Pair(-53, 28), Pair(-17, -48), Pair(3, -48), Pair(-26, 16), Pair(-46, 78), Pair(-132, 91)
      },
      { // Piece 5
        Pair(-56, -123), Pair(21, -102), Pair(37, -97), Pair(7, -127), Pair(-17, -59), Pair(71, -125), Pair(-15, -7), Pair(11, 64),
        Pair(-59, -148), Pair(32, -119), Pair(143, -98), Pair(58, -63), Pair(17, -69), Pair(-58, -23), Pair(82, -29), Pair(47, -124),
        Pair(5, -80), Pair(151, -131), Pair(39, -53), Pair(224, -90), Pair(188, -62), Pair(175, -44), Pair(142, -43), Pair(66, -47),
        Pair(-8, -117), Pair(80, -76), Pair(139, -65), Pair(38, -47), Pair(105, -26), Pair(79, -12), Pair(163, -39), Pair(116, -14),
        Pair(71, -98), Pair(12, -82), Pair(87, -53), Pair(100, -29), Pair(12, 18), Pair(79, 19), Pair(11, 66), Pair(24, 35),
        Pair(16, -56), Pair(75, -74), Pair(51, -49), Pair(36, -16), Pair(28, 8), Pair(-73, 44), Pair(-18, 65), Pair(0, 0),
        Pair(-19, -37), Pair(-10, -43), Pair(-12, -33), Pair(-40, -10), Pair(-74, 26), Pair(-76, 47), Pair(14, 37), Pair(7, 91),
        Pair(-10, -96), Pair(-43, -40), Pair(-59, -28), Pair(6, -39), Pair(-56, -10), Pair(-70, 24), Pair(-38, 50), Pair(-26, 66)
      }
    }},
    {{ // Bucket 24
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(58, 16), Pair(-19, 28), Pair(9, 10), Pair(-19, 24), Pair(-5, 8), Pair(21, -3), Pair(-13, 8), Pair(-27, 14),
        Pair(-29, 5), Pair(-2, 4), Pair(9, -4), Pair(2, 7), Pair(6, 7), Pair(-7, 7), Pair(-5, 10), Pair(-2, 14),
        Pair(0, 0), Pair(-2, 2), Pair(3, -3), Pair(0, 0), Pair(2, 2), Pair(-6, 3), Pair(-8, 5), Pair(-9, 8),
        Pair(0, 0), Pair(3, -10), Pair(0, -3), Pair(1, -3), Pair(0, -5), Pair(-6, 1), Pair(-3, -2), Pair(-6, -1),
        Pair(9, 11), Pair(-3, -7), Pair(0, -3), Pair(4, -6), Pair(-1, -2), Pair(-5, -4), Pair(-1, -5), Pair(-5, -3),
        Pair(8, 6), Pair(-11, -6), Pair(-2, -4), Pair(0, -13), Pair(-2, -1), Pair(-6, -8), Pair(-1, -7), Pair(-4, -7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-35, 15), Pair(53, -81), Pair(60, -21), Pair(210, -49), Pair(56, 13), Pair(-11, 11), Pair(-38, -18), Pair(71, 20),
        Pair(55, 36), Pair(27, -7), Pair(44, -5), Pair(59, -1), Pair(57, 20), Pair(145, -37), Pair(19, -1), Pair(45, -39),
        Pair(76, 2), Pair(30, 22), Pair(13, 19), Pair(39, 3), Pair(43, 10), Pair(78, -2), Pair(53, -16), Pair(49, -3),
        Pair(-3, 1), Pair(18, 13), Pair(5, 22), Pair(28, 16), Pair(31, 10), Pair(29, 14), Pair(37, -14), Pair(34, -35),
        Pair(0, 0), Pair(22, 16), Pair(3, 33), Pair(14, 10), Pair(18, 17), Pair(15, 19), Pair(48, 2), Pair(27, -5),
        Pair(14, 74), Pair(-7, -63), Pair(8, 13), Pair(-1, 11), Pair(7, 13), Pair(8, 15), Pair(24, -8), Pair(1, -17),
        Pair(18, 25), Pair(23, 48), Pair(9, -3), Pair(0, 7), Pair(9, 5), Pair(20, -23), Pair(13, 5), Pair(9, 8),
        Pair(-84, 48), Pair(-7, 36), Pair(1, -18), Pair(14, -17), Pair(0, 6), Pair(5, 1), Pair(-5, 18), Pair(26, -100)
      },
      { // Piece 2
        Pair(-9, 8), Pair(-70, 55), Pair(-119, 74), Pair(-67, 59), Pair(-5, 65), Pair(38, 68), Pair(50, 47), Pair(36, 61),
        Pair(40, 47), Pair(-26, 50), Pair(-16, 58), Pair(-34, 87), Pair(-3, 88), Pair(-48, 69), Pair(14, 83), Pair(17, 44),
        Pair(-8, 51), Pair(-25, 45), Pair(17, 43), Pair(-13, 78), Pair(14, 74), Pair(48, 61), Pair(28, 37), Pair(7, 22),
        Pair(25, 45), Pair(12, 43), Pair(-27, 78), Pair(4, 55), Pair(3, 45), Pair(0, 45), Pair(15, 35), Pair(11, 38),
        Pair(0, 0), Pair(17, 30), Pair(-5, 47), Pair(9, 46), Pair(9, 34), Pair(4, 33), Pair(-2, 12), Pair(17, 38),
        Pair(12, 107), Pair(-13, 8), Pair(8, 46), Pair(0, 43), Pair(2, 32), Pair(2, 27), Pair(3, 4), Pair(11, 22),
        Pair(-2, 72), Pair(-2, 37), Pair(7, 36), Pair(6, 22), Pair(-3, 28), Pair(4, 10), Pair(3, 19), Pair(-4, 32),
        Pair(-9, 64), Pair(10, 39), Pair(2, 42), Pair(3, 13), Pair(14, 37), Pair(1, 14), Pair(-40, 28), Pair(43, 56)
      },
      { // Piece 3
        Pair(19, 88), Pair(16, 72), Pair(26, 82), Pair(-17, 81), Pair(1, 54), Pair(19, 75), Pair(35, 58), Pair(43, 60),
        Pair(37, 100), Pair(-6, 94), Pair(-3, 95), Pair(-18, 99), Pair(9, 77), Pair(55, 51), Pair(65, 43), Pair(39, 58),
        Pair(29, 101), Pair(22, 62), Pair(-10, 85), Pair(19, 63), Pair(19, 79), Pair(50, 64), Pair(59, 35), Pair(21, 60),
        Pair(-11, 104), Pair(-1, 78), Pair(-5, 88), Pair(16, 62), Pair(29, 65), Pair(-1, 63), Pair(37, 30), Pair(16, 64),
        Pair(0, 0), Pair(-14, 87), Pair(-1, 92), Pair(-19, 90), Pair(-7, 65), Pair(8, 53), Pair(39, 53), Pair(-5, 60),
        Pair(-5, 72), Pair(-21, 40), Pair(-24, 72), Pair(-1, 63), Pair(-11, 58), Pair(4, 51), Pair(9, 68), Pair(8, 46),
        Pair(-36, 61), Pair(-9, 67), Pair(-11, 59), Pair(-6, 39), Pair(-3, 50), Pair(7, 41), Pair(33, 44), Pair(1, 38),
        Pair(-10, 46), Pair(-5, 51), Pair(-5, 60), Pair(-6, 61), Pair(-1, 63), Pair(5, 53), Pair(17, 56), Pair(4, 56)
      },
      { // Piece 4
        Pair(13, 134), Pair(67, 53), Pair(35, 153), Pair(124, 37), Pair(-10, 171), Pair(-27, 176), Pair(-45, 219), Pair(109, 107),
        Pair(44, 120), Pair(11, 146), Pair(28, 110), Pair(-7, 164), Pair(76, 123), Pair(24, 131), Pair(41, 155), Pair(64, 120),
        Pair(50, 141), Pair(19, 96), Pair(18, 133), Pair(12, 127), Pair(59, 88), Pair(93, 104), Pair(65, 80), Pair(39, 116),
        Pair(29, 137), Pair(37, 95), Pair(23, 156), Pair(35, 124), Pair(24, 154), Pair(55, 137), Pair(55, 99), Pair(47, 79),
        Pair(0, 0), Pair(20, 131), Pair(18, 132), Pair(28, 129), Pair(40, 104), Pair(24, 104), Pair(37, 98), Pair(25, 89),
        Pair(0, 118), Pair(25, 72), Pair(29, 78), Pair(8, 102), Pair(24, 91), Pair(29, 115), Pair(30, 73), Pair(30, 101),
        Pair(3, 97), Pair(21, 65), Pair(17, 97), Pair(15, 116), Pair(24, 89), Pair(22, 99), Pair(4, 94), Pair(13, 134),
        Pair(20, 50), Pair(29, 101), Pair(6, 100), Pair(16, 81), Pair(4, 119), Pair(27, 46), Pair(57, 111), Pair(7, 115)
      },
      { // Piece 5
        Pair(-60, -12), Pair(-6, 8), Pair(30, 15), Pair(52, -28), Pair(23, -117), Pair(-30, -46), Pair(-22, -25), Pair(51, -46),
        Pair(64, 83), Pair(-34, -41), Pair(166, -13), Pair(-145, 17), Pair(-69, -17), Pair(-4, -25), Pair(35, -67), Pair(60, -60),
        Pair(-41, -94), Pair(101, -28), Pair(112, -37), Pair(62, -25), Pair(83, -43), Pair(14, -12), Pair(34, -11), Pair(81, -69),
        Pair(96, 4), Pair(-27, 39), Pair(58, 6), Pair(88, -11), Pair(94, -22), Pair(38, -11), Pair(83, -46), Pair(42, -34),
        Pair(0, 0), Pair(-51, 16), Pair(-13, 28), Pair(-36, 7), Pair(79, -18), Pair(32, -12), Pair(64, -37), Pair(74, -38),
        Pair(21, 21), Pair(-28, 37), Pair(-56, 12), Pair(17, 4), Pair(1, -6), Pair(20, -20), Pair(1, -16), Pair(56, -29),
        Pair(-5, 36), Pair(-17, 59), Pair(-49, 34), Pair(-43, 13), Pair(33, -20), Pair(4, -15), Pair(5, -21), Pair(-2, -20),
        Pair(11, -2), Pair(33, 14), Pair(-23, 18), Pair(10, -9), Pair(-10, -11), Pair(6, -19), Pair(-1, -25), Pair(9, -33)
      }
    }},
    {{ // Bucket 25
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-9, 15), Pair(-4, 2), Pair(7, 26), Pair(6, 5), Pair(-16, 33), Pair(-11, 18), Pair(37, 5), Pair(-20, 15),
        Pair(1, 5), Pair(12, 11), Pair(-8, 12), Pair(9, 2), Pair(-10, 20), Pair(6, 10), Pair(-1, 9), Pair(-11, 16),
        Pair(2, -1), Pair(0, 0), Pair(1, 0), Pair(3, 0), Pair(-2, 4), Pair(-2, 2), Pair(-6, 4), Pair(-8, 5),
        Pair(6, 0), Pair(0, 0), Pair(2, -3), Pair(-1, 1), Pair(-2, -1), Pair(-5, -1), Pair(-7, 1), Pair(-4, 3),
        Pair(3, -2), Pair(7, 12), Pair(2, -1), Pair(1, 0), Pair(-1, -4), Pair(-10, 0), Pair(-9, -2), Pair(-4, -1),
        Pair(1, -7), Pair(10, 8), Pair(-3, -8), Pair(-2, -7), Pair(-2, -7), Pair(-4, -7), Pair(-8, -5), Pair(-3, -3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-78, 7), Pair(77, -3), Pair(5, 60), Pair(27, 48), Pair(61, -14), Pair(140, -45), Pair(58, -50), Pair(-19, 29),
        Pair(4, 14), Pair(-30, 25), Pair(34, 38), Pair(21, 33), Pair(26, 55), Pair(69, 31), Pair(20, 9), Pair(15, -1),
        Pair(4, 65), Pair(15, 42), Pair(13, 37), Pair(20, 26), Pair(13, 27), Pair(45, 23), Pair(36, 28), Pair(40, -17),
        Pair(16, 22), Pair(-1, 2), Pair(15, 34), Pair(4, 38), Pair(23, 31), Pair(10, 21), Pair(31, 13), Pair(21, 33),
        Pair(-5, -7), Pair(0, 0), Pair(7, 58), Pair(9, 46), Pair(16, 29), Pair(14, 32), Pair(26, 22), Pair(20, 16),
        Pair(-16, -86), Pair(18, 91), Pair(-13, -58), Pair(7, 30), Pair(10, 28), Pair(9, 36), Pair(8, 20), Pair(6, 4),
        Pair(-31, 17), Pair(-10, 48), Pair(-1, 40), Pair(7, 31), Pair(0, 12), Pair(23, 14), Pair(-8, 9), Pair(14, -9),
        Pair(-140, 23), Pair(-22, -86), Pair(7, 41), Pair(-8, -9), Pair(-3, 34), Pair(16, -5), Pair(1, 26), Pair(4, 22)
      },
      { // Piece 2
        Pair(-18, 21), Pair(-37, 99), Pair(-84, 77), Pair(-131, 66), Pair(-97, 80), Pair(-78, 82), Pair(-33, 70), Pair(-21, 108),
        Pair(4, 26), Pair(-39, 73), Pair(4, 38), Pair(-96, 83), Pair(-71, 84), Pair(13, 95), Pair(-24, 80), Pair(38, 62),
        Pair(7, 48), Pair(-5, 51), Pair(-7, 47), Pair(-6, 67), Pair(-31, 89), Pair(-5, 66), Pair(-2, 55), Pair(16, 32),
        Pair(-13, 13), Pair(0, 54), Pair(16, 43), Pair(-11, 60), Pair(6, 44), Pair(0, 66), Pair(9, 46), Pair(-2, 43),
        Pair(-27, 103), Pair(0, 0), Pair(-6, 67), Pair(0, 32), Pair(4, 50), Pair(4, 32), Pair(-10, 39), Pair(15, 38),
        Pair(-20, -56), Pair(-8, 113), Pair(-23, 24), Pair(-4, 54), Pair(2, 40), Pair(-11, 42), Pair(0, 20), Pair(-4, 38),
        Pair(-38, 55), Pair(3, 19), Pair(-4, 56), Pair(-9, 27), Pair(-6, 38), Pair(10, 17), Pair(-1, 20), Pair(-6, 45),
        Pair(-11, 30), Pair(12, 21), Pair(-5, 35), Pair(-21, 63), Pair(-38, 37), Pair(-6, 37), Pair(43, 3), Pair(-17, 20)
      },
      { // Piece 3
        Pair(13, 53), Pair(27, 68), Pair(-22, 73), Pair(31, 55), Pair(-5, 95), Pair(20, 50), Pair(-19, 79), Pair(2, 69),
        Pair(15, 61), Pair(34, 79), Pair(28, 64), Pair(1, 75), Pair(7, 84), Pair(18, 49), Pair(68, 47), Pair(9, 45),
        Pair(9, 59), Pair(1, 82), Pair(21, 56), Pair(12, 64), Pair(-17, 60), Pair(19, 65), Pair(27, 39), Pair(22, 52),
        Pair(-2, 42), Pair(-9, 84), Pair(29, 39), Pair(-6, 55), Pair(4, 59), Pair(33, 30), Pair(7, 38), Pair(23, 58),
        Pair(4, 13), Pair(0, 0), Pair(-5, 73), Pair(-12, 69), Pair(13, 43), Pair(-18, 54), Pair(4, 39), Pair(23, 44),
        Pair(5, -4), Pair(-30, 80), Pair(43, -31), Pair(-13, 47), Pair(4, 45), Pair(-1, 47), Pair(36, 25), Pair(5, 45),
        Pair(-25, 36), Pair(-17, 43), Pair(-9, 54), Pair(-7, 33), Pair(-8, 49), Pair(-7, 43), Pair(-6, 72), Pair(-23, 40),
        Pair(-9, 44), Pair(-13, 41), Pair(-11, 50), Pair(-5, 51), Pair(-3, 56), Pair(0, 53), Pair(8, 41), Pair(10, 46)
      },
      { // Piece 4
        Pair(65, 30), Pair(-56, 110), Pair(42, 79), Pair(83, 30), Pair(47, 88), Pair(31, 76), Pair(18, 94), Pair(40, 47),
        Pair(37, 80), Pair(15, 74), Pair(32, 64), Pair(26, 75), Pair(39, 111), Pair(7, 132), Pair(-12, 138), Pair(9, 107),
        Pair(46, 61), Pair(29, 46), Pair(13, 92), Pair(17, 87), Pair(29, 83), Pair(59, 88), Pair(44, 70), Pair(55, 55),
        Pair(34, 50), Pair(40, 43), Pair(45, 88), Pair(19, 70), Pair(23, 70), Pair(26, 97), Pair(53, 68), Pair(36, 80),
        Pair(24, 13), Pair(0, 0), Pair(19, 89), Pair(8, 86), Pair(30, 58), Pair(23, 65), Pair(21, 83), Pair(40, 53),
        Pair(68, 12), Pair(20, 43), Pair(-20, 26), Pair(18, 61), Pair(29, 43), Pair(17, 64), Pair(29, 63), Pair(19, 109),
        Pair(4, 71), Pair(1, 49), Pair(10, 50), Pair(20, 50), Pair(13, 64), Pair(15, 31), Pair(33, -1), Pair(-28, 100),
        Pair(-1, 67), Pair(9, 75), Pair(2, 39), Pair(15, 54), Pair(12, 31), Pair(31, 39), Pair(50, -6), Pair(1, 77)
      },
      { // Piece 5
        Pair(-42, -183), Pair(-52, -101), Pair(19, -57), Pair(-5, 5), Pair(-29, 18), Pair(-76, -69), Pair(16, -80), Pair(-21, -127),
        Pair(85, -39), Pair(86, -82), Pair(9, 2), Pair(24, -46), Pair(-76, -16), Pair(-19, -7), Pair(-46, -44), Pair(-71, -15),
        Pair(30, -31), Pair(-10, -24), Pair(246, -35), Pair(97, -28), Pair(-4, -1), Pair(-39, -14), Pair(2, 12), Pair(47, -10),
        Pair(14, 2), Pair(7, -6), Pair(10, -1), Pair(99, -35), Pair(105, -24), Pair(61, -10), Pair(25, -21), Pair(53, -14),
        Pair(-13, 11), Pair(0, 0), Pair(18, 1), Pair(49, -12), Pair(28, 1), Pair(31, -2), Pair(-5, 6), Pair(29, -14),
        Pair(24, 14), Pair(-52, -11), Pair(-41, -31), Pair(-27, 12), Pair(10, 1), Pair(-2, 1), Pair(20, -15), Pair(32, -12),
        Pair(-41, 28), Pair(-66, 13), Pair(-11, 21), Pair(-30, 6), Pair(-21, 8), Pair(17, -14), Pair(4, -17), Pair(0, -9),
        Pair(-46, 23), Pair(11, -16), Pair(2, -2), Pair(-37, 32), Pair(-12, -8), Pair(4, -8), Pair(-1, -16), Pair(4, -23)
      }
    }},
    {{ // Bucket 26
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(1, 14), Pair(-15, 10), Pair(8, 8), Pair(26, 9), Pair(-2, 18), Pair(14, 1), Pair(29, 5), Pair(-20, 26),
        Pair(-7, 7), Pair(-3, 9), Pair(-21, 9), Pair(2, 4), Pair(9, 1), Pair(7, 10), Pair(-11, 28), Pair(-15, 17),
        Pair(-3, 2), Pair(0, -1), Pair(0, 0), Pair(-1, 2), Pair(3, 2), Pair(-2, 4), Pair(0, 3), Pair(-2, 2),
        Pair(0, -2), Pair(1, -6), Pair(0, 0), Pair(3, -4), Pair(-6, 2), Pair(-3, 0), Pair(-2, -3), Pair(-9, 2),
        Pair(1, 1), Pair(10, -30), Pair(9, 13), Pair(4, 1), Pair(0, -4), Pair(-9, 0), Pair(-7, -1), Pair(-8, -4),
        Pair(1, -2), Pair(0, -12), Pair(10, 4), Pair(-4, -14), Pair(0, -6), Pair(-6, -5), Pair(-10, -1), Pair(-3, -5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-38, 30), Pair(-10, 35), Pair(24, 2), Pair(37, 11), Pair(-47, 20), Pair(113, 45), Pair(61, 87), Pair(-96, 82),
        Pair(29, 53), Pair(-25, 53), Pair(-16, 25), Pair(52, 20), Pair(56, 44), Pair(35, 17), Pair(22, 38), Pair(39, 23),
        Pair(33, 48), Pair(1, 37), Pair(53, 35), Pair(12, 40), Pair(25, 33), Pair(-20, 47), Pair(18, 45), Pair(50, 72),
        Pair(-16, -16), Pair(9, 52), Pair(-9, 29), Pair(19, 48), Pair(14, 37), Pair(33, 29), Pair(12, 40), Pair(26, 43),
        Pair(-15, 56), Pair(-5, 45), Pair(0, 0), Pair(8, 55), Pair(13, 51), Pair(6, 38), Pair(13, 42), Pair(9, 25),
        Pair(6, 55), Pair(10, -16), Pair(14, 97), Pair(-1, -69), Pair(24, 41), Pair(9, 34), Pair(4, 57), Pair(18, 57),
        Pair(-33, 86), Pair(-37, 57), Pair(5, 50), Pair(9, 15), Pair(3, 54), Pair(-4, 17), Pair(-8, 48), Pair(23, 26),
        Pair(-62, 4), Pair(0, 54), Pair(-24, -66), Pair(-17, 33), Pair(3, 8), Pair(14, 26), Pair(-12, 60), Pair(52, -3)
      },
      { // Piece 2
        Pair(14, 23), Pair(11, 57), Pair(-1, 51), Pair(13, 50), Pair(-70, 38), Pair(32, 47), Pair(-125, 66), Pair(49, 89),
        Pair(-15, 51), Pair(-19, 66), Pair(-13, 68), Pair(-20, 41), Pair(28, 65), Pair(28, 49), Pair(36, 88), Pair(-34, 101),
        Pair(-13, 17), Pair(19, 27), Pair(-28, 50), Pair(25, 50), Pair(-7, 53), Pair(17, 79), Pair(-14, 57), Pair(30, 39),
        Pair(-31, 85), Pair(-8, 40), Pair(2, 39), Pair(-19, 60), Pair(1, 60), Pair(-8, 59), Pair(-5, 62), Pair(26, 14),
        Pair(14, 25), Pair(-4, 70), Pair(0, 0), Pair(10, 61), Pair(-1, 48), Pair(-3, 47), Pair(17, 19), Pair(3, 47),
        Pair(-17, 51), Pair(-80, -49), Pair(13, 104), Pair(-21, -3), Pair(-4, 46), Pair(6, 26), Pair(-5, 39), Pair(10, 14),
        Pair(-66, -28), Pair(-12, 41), Pair(6, 32), Pair(-3, 46), Pair(-3, 7), Pair(0, 42), Pair(1, 27), Pair(6, 15),
        Pair(-25, 61), Pair(12, 34), Pair(-1, 40), Pair(-10, 33), Pair(4, 52), Pair(0, -10), Pair(41, 23), Pair(15, 41)
      },
      { // Piece 3
        Pair(22, 55), Pair(47, 46), Pair(35, 57), Pair(-41, 77), Pair(29, 48), Pair(-30, 79), Pair(31, 59), Pair(44, 44),
        Pair(7, 52), Pair(14, 59), Pair(7, 70), Pair(39, 54), Pair(46, 54), Pair(54, 53), Pair(56, 35), Pair(60, 21),
        Pair(-4, 62), Pair(-7, 63), Pair(-22, 78), Pair(33, 53), Pair(32, 53), Pair(48, 45), Pair(64, 30), Pair(50, 25),
        Pair(8, 36), Pair(11, 47), Pair(-45, 76), Pair(3, 52), Pair(30, 50), Pair(32, 31), Pair(52, 30), Pair(38, 32),
        Pair(-35, 78), Pair(-45, 45), Pair(0, 0), Pair(10, 51), Pair(1, 54), Pair(17, 33), Pair(16, 37), Pair(58, 20),
        Pair(-24, 66), Pair(6, -29), Pair(-28, 71), Pair(43, -12), Pair(-2, 40), Pair(7, 42), Pair(-17, 60), Pair(-4, 55),
        Pair(4, 17), Pair(-9, 42), Pair(-3, 29), Pair(-14, 35), Pair(-10, 29), Pair(-3, 52), Pair(28, 38), Pair(1, 25),
        Pair(-6, 49), Pair(-2, 30), Pair(-20, 42), Pair(-2, 33), Pair(-2, 51), Pair(6, 45), Pair(13, 53), Pair(15, 38)
      },
      { // Piece 4
        Pair(25, 54), Pair(30, 58), Pair(7, 105), Pair(16, 79), Pair(51, 67), Pair(20, 29), Pair(61, 69), Pair(25, 85),
        Pair(24, 86), Pair(26, 92), Pair(18, 46), Pair(-7, 109), Pair(32, 154), Pair(94, 86), Pair(46, 70), Pair(44, 137),
        Pair(24, 44), Pair(10, 74), Pair(22, 74), Pair(44, 70), Pair(29, 110), Pair(6, 97), Pair(60, 75), Pair(40, 96),
        Pair(-1, 82), Pair(18, 16), Pair(0, 107), Pair(23, 84), Pair(36, 80), Pair(53, 95), Pair(82, 35), Pair(33, 91),
        Pair(1, 50), Pair(-17, 117), Pair(0, 0), Pair(40, 90), Pair(26, 78), Pair(33, 85), Pair(41, 57), Pair(44, 97),
        Pair(3, 78), Pair(29, -3), Pair(26, 43), Pair(31, -35), Pair(25, 59), Pair(22, 69), Pair(27, 81), Pair(34, 58),
        Pair(-19, 128), Pair(12, 44), Pair(24, 35), Pair(21, 44), Pair(11, 58), Pair(39, 20), Pair(16, 92), Pair(59, 62),
        Pair(21, 32), Pair(15, 21), Pair(18, 47), Pair(19, 51), Pair(16, 65), Pair(9, 67), Pair(-37, 91), Pair(32, 46)
      },
      { // Piece 5
        Pair(-30, -102), Pair(1, -9), Pair(-76, -95), Pair(0, -61), Pair(-84, -98), Pair(-27, -31), Pair(48, -98), Pair(-46, -70),
        Pair(7, -53), Pair(19, -13), Pair(-172, -65), Pair(17, 25), Pair(121, -99), Pair(60, -30), Pair(206, -91), Pair(-37, -14),
        Pair(-97, 39), Pair(-18, 4), Pair(25, 28), Pair(70, -22), Pair(70, -34), Pair(181, -37), Pair(-49, 12), Pair(90, -49),
        Pair(-3, -10), Pair(109, -12), Pair(108, -46), Pair(16, 32), Pair(56, -10), Pair(147, -20), Pair(52, -14), Pair(30, -9),
        Pair(-31, -20), Pair(-53, -2), Pair(0, 0), Pair(72, -12), Pair(53, 1), Pair(33, 2), Pair(14, -1), Pair(26, -34),
        Pair(-21, 23), Pair(56, 3), Pair(-73, 4), Pair(-125, 42), Pair(-42, 26), Pair(-11, 18), Pair(18, -1), Pair(26, -14),
        Pair(-64, 41), Pair(-59, 42), Pair(-43, 22), Pair(35, 4), Pair(-6, 7), Pair(-8, 13), Pair(-8, 5), Pair(11, -5),
        Pair(-40, 7), Pair(-35, 31), Pair(-33, 16), Pair(-20, 8), Pair(-5, -2), Pair(1, 16), Pair(3, -1), Pair(13, -16)
      }
    }},
    {{ // Bucket 27
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-34, 26), Pair(-4, 0), Pair(17, -6), Pair(2, -3), Pair(-11, -1), Pair(5, -11), Pair(36, 4), Pair(9, 8),
        Pair(-4, 12), Pair(-2, 6), Pair(1, 2), Pair(-2, 4), Pair(-2, 6), Pair(0, 5), Pair(0, 14), Pair(-12, 18),
        Pair(-1, 0), Pair(-2, 0), Pair(0, -2), Pair(0, 0), Pair(1, 1), Pair(0, 3), Pair(1, 5), Pair(4, 3),
        Pair(0, 1), Pair(1, -3), Pair(-1, -4), Pair(0, 0), Pair(-4, -4), Pair(-4, 4), Pair(0, -1), Pair(-1, 0),
        Pair(-1, -4), Pair(1, -5), Pair(-1, -32), Pair(12, 12), Pair(-2, -25), Pair(-8, 2), Pair(0, 0), Pair(-1, -5),
        Pair(-1, -2), Pair(-2, -6), Pair(-2, -16), Pair(0, -6), Pair(-14, -10), Pair(-3, -3), Pair(1, -2), Pair(4, -4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-57, 25), Pair(14, 23), Pair(-8, 67), Pair(-76, 40), Pair(34, 41), Pair(-79, 45), Pair(27, -90), Pair(-22, 2),
        Pair(-8, 84), Pair(-11, 24), Pair(29, 19), Pair(4, 63), Pair(43, 22), Pair(29, 22), Pair(9, -5), Pair(-51, 33),
        Pair(61, -10), Pair(-10, 36), Pair(-18, 34), Pair(19, 24), Pair(47, 21), Pair(50, 8), Pair(7, 53), Pair(12, 50),
        Pair(-10, 43), Pair(-9, -10), Pair(9, 55), Pair(-16, 49), Pair(9, 51), Pair(-2, 24), Pair(27, 42), Pair(21, 27),
        Pair(-15, -10), Pair(6, 49), Pair(2, 48), Pair(0, 0), Pair(2, 56), Pair(11, 46), Pair(-9, 35), Pair(11, 33),
        Pair(-1, 26), Pair(-14, 37), Pair(-21, -30), Pair(28, 101), Pair(-30, -15), Pair(6, 30), Pair(3, 33), Pair(16, 37),
        Pair(11, -40), Pair(0, 23), Pair(-10, 8), Pair(4, 52), Pair(-11, 4), Pair(15, 34), Pair(14, 5), Pair(13, 18),
        Pair(-82, 0), Pair(-15, -3), Pair(-31, 45), Pair(-33, -32), Pair(-12, 49), Pair(-17, 23), Pair(-1, 59), Pair(28, -2)
      },
      { // Piece 2
        Pair(-11, 25), Pair(-73, 57), Pair(-55, 37), Pair(-70, 67), Pair(-78, 62), Pair(-25, 35), Pair(-59, 83), Pair(-52, 27),
        Pair(-36, 76), Pair(-17, 42), Pair(9, 28), Pair(-37, 58), Pair(-22, 37), Pair(3, 65), Pair(-11, 88), Pair(0, 63),
        Pair(-23, 69), Pair(-12, 18), Pair(14, 39), Pair(-8, 27), Pair(7, 42), Pair(0, 28), Pair(0, 78), Pair(-5, 42),
        Pair(-16, 44), Pair(-4, 60), Pair(-14, 14), Pair(0, 39), Pair(6, 25), Pair(-27, 75), Pair(2, 43), Pair(18, 37),
        Pair(6, 56), Pair(-26, 60), Pair(4, 65), Pair(0, 0), Pair(-7, 64), Pair(7, 33), Pair(17, 40), Pair(-1, 34),
        Pair(-11, 22), Pair(0, 36), Pair(-34, -83), Pair(15, 108), Pair(-13, -37), Pair(-1, 48), Pair(4, 37), Pair(7, 46),
        Pair(-3, 54), Pair(-35, -49), Pair(-7, 33), Pair(-3, 21), Pair(-12, 45), Pair(-13, 18), Pair(4, 30), Pair(-7, 32),
        Pair(-74, -59), Pair(-19, 55), Pair(0, 10), Pair(3, 23), Pair(-10, 45), Pair(-1, 41), Pair(-54, -16), Pair(-13, 52)
      },
      { // Piece 3
        Pair(-4, 45), Pair(-1, 54), Pair(6, 51), Pair(-9, 58), Pair(-1, 40), Pair(1, 39), Pair(16, 45), Pair(-54, 80),
        Pair(16, 42), Pair(6, 38), Pair(23, 38), Pair(1, 59), Pair(-12, 65), Pair(-26, 70), Pair(17, 24), Pair(-20, 42),
        Pair(8, 39), Pair(-6, 48), Pair(-21, 60), Pair(28, 49), Pair(10, 21), Pair(49, 27), Pair(20, 22), Pair(23, 24),
        Pair(-6, 40), Pair(0, 38), Pair(-13, 52), Pair(-22, 56), Pair(-8, 36), Pair(8, 37), Pair(44, 7), Pair(1, 31),
        Pair(0, 18), Pair(-18, 39), Pair(-8, 14), Pair(0, 0), Pair(-18, 50), Pair(-23, 45), Pair(-6, 30), Pair(26, 13),
        Pair(-22, 45), Pair(-16, 57), Pair(-71, -3), Pair(-13, 56), Pair(-50, 11), Pair(-9, 36), Pair(2, 28), Pair(20, 32),
        Pair(14, 21), Pair(11, 18), Pair(5, 18), Pair(-32, 46), Pair(1, 22), Pair(0, 38), Pair(3, 24), Pair(18, 23),
        Pair(-3, 37), Pair(-7, 36), Pair(-5, 37), Pair(-25, 36), Pair(-6, 42), Pair(-1, 47), Pair(4, 39), Pair(13, 31)
      },
      { // Piece 4
        Pair(18, 93), Pair(10, 68), Pair(13, 96), Pair(58, 82), Pair(58, 50), Pair(28, 124), Pair(89, 123), Pair(37, 103),
        Pair(24, 60), Pair(3, 88), Pair(10, 121), Pair(27, 77), Pair(32, 108), Pair(10, 136), Pair(13, 136), Pair(53, 63),
        Pair(22, 98), Pair(33, 44), Pair(17, 78), Pair(23, 82), Pair(12, 157), Pair(38, 63), Pair(-2, 113), Pair(8, 101),
        Pair(21, 54), Pair(26, 28), Pair(0, 84), Pair(25, 47), Pair(38, 86), Pair(9, 106), Pair(8, 116), Pair(26, 80),
        Pair(26, 32), Pair(2, 71), Pair(12, 42), Pair(0, 0), Pair(18, 90), Pair(20, 77), Pair(24, 69), Pair(14, 79),
        Pair(3, 94), Pair(7, 47), Pair(1, 29), Pair(25, 65), Pair(18, -14), Pair(11, 79), Pair(22, 65), Pair(15, 108),
        Pair(16, 51), Pair(5, 52), Pair(5, 36), Pair(3, 68), Pair(12, 55), Pair(8, 79), Pair(19, 47), Pair(22, 43),
        Pair(11, 49), Pair(-5, 92), Pair(4, 61), Pair(13, 68), Pair(15, 37), Pair(-8, 89), Pair(-13, 3), Pair(46, 51)
      },
      { // Piece 5
        Pair(-30, -57), Pair(-46, -8), Pair(6, -45), Pair(-57, -29), Pair(23, -28), Pair(24, -61), Pair(17, -62), Pair(4, -71),
        Pair(11, -65), Pair(-39, -63), Pair(88, -65), Pair(-20, -76), Pair(22, -31), Pair(-80, -70), Pair(58, -37), Pair(-90, -31),
        Pair(-25, -15), Pair(91, -11), Pair(69, -57), Pair(91, -36), Pair(32, -4), Pair(167, -19), Pair(76, -12), Pair(34, -35),
        Pair(-22, -1), Pair(87, 17), Pair(145, 0), Pair(59, 7), Pair(33, 21), Pair(159, -20), Pair(93, -5), Pair(63, -13),
        Pair(60, 12), Pair(-36, 9), Pair(-1, -20), Pair(0, 0), Pair(70, -38), Pair(-13, 15), Pair(48, -4), Pair(69, -20),
        Pair(-63, 47), Pair(12, -2), Pair(84, 0), Pair(-84, -8), Pair(114, -45), Pair(-9, 15), Pair(15, 11), Pair(55, -16),
        Pair(-35, 58), Pair(-40, 26), Pair(-18, 13), Pair(-10, 4), Pair(15, 3), Pair(-4, 14), Pair(-2, 16), Pair(4, 9),
        Pair(-10, 21), Pair(-22, 32), Pair(-14, 19), Pair(-22, 5), Pair(-3, 9), Pair(-11, 15), Pair(-1, 14), Pair(1, -3)
      }
    }},
    {{ // Bucket 28
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(36, 1), Pair(4, 16), Pair(0, 13), Pair(-23, 1), Pair(-8, 21), Pair(4, 2), Pair(53, 3), Pair(-15, 14),
        Pair(2, 4), Pair(3, 2), Pair(6, -5), Pair(-3, -7), Pair(-1, 9), Pair(6, -2), Pair(14, -4), Pair(-2, 6),
        Pair(0, -2), Pair(3, -5), Pair(-4, -3), Pair(0, -1), Pair(0, 0), Pair(1, 3), Pair(3, 3), Pair(8, 2),
        Pair(5, -3), Pair(1, -7), Pair(2, -5), Pair(-2, -4), Pair(0, 0), Pair(-1, -1), Pair(7, -2), Pair(2, 1),
        Pair(0, -6), Pair(-2, -4), Pair(-3, -2), Pair(5, -18), Pair(10, 7), Pair(-5, -24), Pair(0, -3), Pair(2, 0),
        Pair(4, -7), Pair(-1, -7), Pair(1, -4), Pair(-6, -14), Pair(9, -3), Pair(-8, -12), Pair(4, 0), Pair(5, -2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-16, -34), Pair(-99, 71), Pair(-71, 44), Pair(32, 56), Pair(-25, 64), Pair(-13, 48), Pair(-42, 61), Pair(-22, -4),
        Pair(-9, 43), Pair(3, 12), Pair(5, 21), Pair(30, 38), Pair(-44, 56), Pair(-29, 68), Pair(28, 20), Pair(-6, 64),
        Pair(-18, 28), Pair(10, 35), Pair(-13, 43), Pair(11, 34), Pair(-5, 34), Pair(5, 38), Pair(13, 37), Pair(-5, 33),
        Pair(-11, 49), Pair(1, 30), Pair(-3, 9), Pair(-7, 53), Pair(-11, 44), Pair(-5, 51), Pair(1, -8), Pair(14, 37),
        Pair(7, 30), Pair(-16, 18), Pair(-9, 47), Pair(0, 50), Pair(0, 0), Pair(-10, 46), Pair(4, 33), Pair(-11, -14),
        Pair(2, 47), Pair(-11, 32), Pair(4, 27), Pair(-36, -18), Pair(11, 99), Pair(-14, -40), Pair(1, 21), Pair(0, 29),
        Pair(6, 54), Pair(-18, 35), Pair(-9, 32), Pair(-5, 2), Pair(-2, 36), Pair(-26, 32), Pair(-13, 32), Pair(-10, -30),
        Pair(21, 11), Pair(1, 9), Pair(-20, 20), Pair(-4, 29), Pair(-25, -29), Pair(-16, 46), Pair(-14, -30), Pair(-10, 35)
      },
      { // Piece 2
        Pair(-66, 33), Pair(-81, 67), Pair(-92, 58), Pair(-89, 62), Pair(-25, 50), Pair(-84, 44), Pair(-3, 27), Pair(-17, 14),
        Pair(26, 58), Pair(-11, 38), Pair(47, 40), Pair(-76, 70), Pair(14, 42), Pair(13, 45), Pair(13, 45), Pair(-11, 0),
        Pair(-12, 23), Pair(-31, 74), Pair(-46, 54), Pair(-1, 52), Pair(-37, 64), Pair(9, 33), Pair(-33, 50), Pair(20, 30),
        Pair(-3, 34), Pair(-11, 41), Pair(-15, 51), Pair(-34, 50), Pair(3, 35), Pair(-11, 46), Pair(0, 58), Pair(-4, 21),
        Pair(0, 41), Pair(-8, 31), Pair(-14, 44), Pair(12, 37), Pair(0, 0), Pair(6, 52), Pair(-13, 49), Pair(9, 45),
        Pair(-7, 30), Pair(-15, 41), Pair(-7, 35), Pair(-31, -45), Pair(12, 92), Pair(-41, -62), Pair(6, 36), Pair(2, 15),
        Pair(-19, 52), Pair(0, 28), Pair(-33, 20), Pair(-13, 27), Pair(-5, 20), Pair(-46, 57), Pair(-34, -23), Pair(8, 29),
        Pair(-4, 26), Pair(-27, -17), Pair(-4, 26), Pair(-18, 17), Pair(-12, 23), Pair(-1, 17), Pair(-31, 101), Pair(-91, -46)
      },
      { // Piece 3
        Pair(21, 35), Pair(2, 40), Pair(1, 43), Pair(2, 47), Pair(-36, 49), Pair(28, 44), Pair(26, 23), Pair(37, 23),
        Pair(14, 32), Pair(8, 25), Pair(6, 38), Pair(-30, 53), Pair(30, 41), Pair(12, 30), Pair(6, 35), Pair(17, 28),
        Pair(1, 39), Pair(-15, 38), Pair(0, 34), Pair(-2, 43), Pair(28, 37), Pair(44, 19), Pair(50, 28), Pair(28, 26),
        Pair(5, 31), Pair(0, 27), Pair(9, 28), Pair(-9, 32), Pair(-16, 33), Pair(6, 26), Pair(40, 13), Pair(3, 24),
        Pair(-2, 21), Pair(-11, 37), Pair(-26, 44), Pair(-17, 34), Pair(0, 0), Pair(7, 12), Pair(0, 17), Pair(21, -3),
        Pair(-9, 44), Pair(-14, 31), Pair(3, 23), Pair(15, 13), Pair(-12, 50), Pair(9, 1), Pair(-5, 29), Pair(20, -4),
        Pair(-7, 25), Pair(14, 17), Pair(-16, 39), Pair(-4, 30), Pair(-18, 28), Pair(6, 42), Pair(39, 9), Pair(64, -18),
        Pair(0, 32), Pair(-5, 34), Pair(-8, 38), Pair(-7, 25), Pair(-16, 32), Pair(-1, 24), Pair(22, 15), Pair(3, 31)
      },
      { // Piece 4
        Pair(-6, 73), Pair(43, 53), Pair(-16, 111), Pair(13, 80), Pair(5, 58), Pair(13, 100), Pair(32, 76), Pair(12, 72),
        Pair(6, 76), Pair(-6, 57), Pair(10, 67), Pair(-18, 99), Pair(25, 65), Pair(-7, 91), Pair(-21, 99), Pair(14, 7),
        Pair(-3, 51), Pair(2, 78), Pair(27, 8), Pair(6, 72), Pair(17, 55), Pair(30, 66), Pair(10, 52), Pair(-3, 103),
        Pair(-5, 76), Pair(22, 64), Pair(2, 74), Pair(19, 49), Pair(-5, 99), Pair(-9, 90), Pair(22, 86), Pair(11, 49),
        Pair(2, 43), Pair(5, 13), Pair(22, 32), Pair(5, 72), Pair(0, 0), Pair(18, 42), Pair(22, 50), Pair(8, 89),
        Pair(10, 54), Pair(4, 51), Pair(1, 76), Pair(12, -11), Pair(15, 59), Pair(31, -16), Pair(11, 65), Pair(12, 78),
        Pair(10, 61), Pair(2, 55), Pair(-3, 48), Pair(3, 48), Pair(9, 40), Pair(9, 39), Pair(-7, 53), Pair(6, 86),
        Pair(2, 36), Pair(4, 27), Pair(5, 25), Pair(5, 46), Pair(0, 61), Pair(3, 84), Pair(53, 43), Pair(35, -18)
      },
      { // Piece 5
        Pair(-70, -73), Pair(5, -17), Pair(181, -44), Pair(-14, 24), Pair(-3, -63), Pair(70, -59), Pair(-59, -25), Pair(6, -68),
        Pair(-71, -44), Pair(88, -53), Pair(-23, -50), Pair(84, -24), Pair(118, -90), Pair(55, -48), Pair(57, -40), Pair(-40, -11),
        Pair(-11, -51), Pair(32, -24), Pair(19, -23), Pair(99, -20), Pair(184, -88), Pair(206, -57), Pair(98, -51), Pair(-117, -5),
        Pair(87, -48), Pair(107, -25), Pair(123, -30), Pair(-53, 25), Pair(51, -26), Pair(103, -20), Pair(75, -25), Pair(120, -23),
        Pair(-14, -13), Pair(11, -6), Pair(13, 5), Pair(74, -39), Pair(0, 0), Pair(78, -36), Pair(-9, 16), Pair(27, 0),
        Pair(36, -15), Pair(-2, 3), Pair(60, -7), Pair(-127, 27), Pair(-26, -12), Pair(-49, -12), Pair(13, 15), Pair(-29, 33),
        Pair(29, -6), Pair(10, 6), Pair(9, 2), Pair(61, -12), Pair(13, -1), Pair(25, 2), Pair(-19, 26), Pair(-3, 24),
        Pair(24, -10), Pair(-1, 11), Pair(-4, 29), Pair(9, -7), Pair(-12, 6), Pair(1, 9), Pair(-10, 25), Pair(-7, 27)
      }
    }},
    {{ // Bucket 29
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(21, 2), Pair(27, 2), Pair(17, 11), Pair(10, -1), Pair(-11, 16), Pair(-36, 39), Pair(-46, 4), Pair(33, 0),
        Pair(3, 0), Pair(-5, 4), Pair(15, -2), Pair(-3, 3), Pair(7, 3), Pair(19, -6), Pair(-8, 13), Pair(4, 6),
        Pair(7, -3), Pair(2, -2), Pair(3, -3), Pair(1, -3), Pair(-2, -3), Pair(0, 0), Pair(12, -2), Pair(8, 1),
        Pair(7, -7), Pair(10, -9), Pair(-2, -7), Pair(-2, -3), Pair(2, -3), Pair(0, 0), Pair(5, -5), Pair(6, -4),
        Pair(3, -8), Pair(5, -8), Pair(-3, -6), Pair(2, -5), Pair(-4, 3), Pair(18, 4), Pair(-3, -21), Pair(8, -3),
        Pair(2, -8), Pair(3, -9), Pair(-3, -4), Pair(4, -15), Pair(-4, -6), Pair(8, -4), Pair(1, -13), Pair(6, -2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-45, -31), Pair(38, 25), Pair(-41, 42), Pair(-10, 17), Pair(13, 17), Pair(-86, 46), Pair(106, -77), Pair(-73, 70),
        Pair(22, 33), Pair(-13, 33), Pair(16, 7), Pair(3, 23), Pair(7, 22), Pair(-25, 28), Pair(36, -17), Pair(-18, 32),
        Pair(0, 20), Pair(-11, 21), Pair(15, 11), Pair(20, 5), Pair(64, 1), Pair(-35, 53), Pair(21, 42), Pair(-23, 24),
        Pair(0, 36), Pair(-16, 28), Pair(4, 33), Pair(10, 2), Pair(18, 39), Pair(16, 9), Pair(24, 16), Pair(0, -67),
        Pair(8, 9), Pair(38, 19), Pair(-3, 6), Pair(19, 31), Pair(3, 24), Pair(0, 0), Pair(3, 38), Pair(14, 14),
        Pair(-1, 52), Pair(-5, 25), Pair(5, 19), Pair(28, 3), Pair(-22, -10), Pair(23, 63), Pair(-15, -37), Pair(-3, -1),
        Pair(-4, -13), Pair(-12, 33), Pair(-7, 11), Pair(10, 12), Pair(-12, 16), Pair(1, 20), Pair(-12, -9), Pair(7, -6),
        Pair(-102, -14), Pair(-5, 8), Pair(6, -6), Pair(-28, 18), Pair(-11, 34), Pair(-15, -48), Pair(2, 49), Pair(-45, -43)
      },
      { // Piece 2
        Pair(-18, 57), Pair(37, -35), Pair(20, 56), Pair(-11, 35), Pair(-53, 66), Pair(-113, 79), Pair(-30, 30), Pair(56, -22),
        Pair(-13, 13), Pair(-4, 31), Pair(-37, 17), Pair(-16, 39), Pair(-22, 35), Pair(56, 2), Pair(-29, 33), Pair(25, 14),
        Pair(-28, 32), Pair(-39, 52), Pair(-1, 45), Pair(-29, 17), Pair(-12, 37), Pair(-58, 47), Pair(-24, 38), Pair(-41, -7),
        Pair(26, 9), Pair(2, 23), Pair(-2, 17), Pair(-12, 40), Pair(-17, 14), Pair(5, 35), Pair(-18, 10), Pair(22, 42),
        Pair(2, 13), Pair(5, 25), Pair(5, 19), Pair(-40, 46), Pair(-5, 43), Pair(0, 0), Pair(7, 38), Pair(-49, 40),
        Pair(-5, -6), Pair(-1, 40), Pair(-9, 11), Pair(-4, 52), Pair(-42, -42), Pair(14, 83), Pair(-53, -97), Pair(4, 36),
        Pair(-3, 3), Pair(-12, 32), Pair(-17, 21), Pair(-14, -9), Pair(4, 12), Pair(-15, 27), Pair(5, 10), Pair(-83, -83),
        Pair(-1, 16), Pair(-11, 70), Pair(-26, -13), Pair(-6, 28), Pair(-7, 27), Pair(7, 12), Pair(-40, 14), Pair(-5, 64)
      },
      { // Piece 3
        Pair(9, 27), Pair(35, 24), Pair(11, 33), Pair(6, 14), Pair(5, 41), Pair(-9, 47), Pair(23, 32), Pair(0, 35),
        Pair(35, -2), Pair(34, 13), Pair(35, 4), Pair(1, 30), Pair(49, 29), Pair(45, 26), Pair(20, 15), Pair(9, 25),
        Pair(0, 17), Pair(27, 17), Pair(38, 6), Pair(8, 26), Pair(8, 30), Pair(21, 8), Pair(16, 37), Pair(19, 6),
        Pair(15, 18), Pair(19, 16), Pair(34, 15), Pair(20, 16), Pair(63, 19), Pair(47, 26), Pair(-9, 27), Pair(47, 9),
        Pair(1, 16), Pair(-12, 41), Pair(12, 10), Pair(-17, 38), Pair(5, 28), Pair(0, 0), Pair(5, -1), Pair(-19, 43),
        Pair(19, 15), Pair(-2, 25), Pair(-14, 20), Pair(10, 6), Pair(48, -87), Pair(-27, 42), Pair(30, -17), Pair(-18, 40),
        Pair(25, -4), Pair(7, -2), Pair(5, 28), Pair(13, 9), Pair(-9, 32), Pair(-6, 20), Pair(28, -2), Pair(7, -5),
        Pair(15, 13), Pair(5, 27), Pair(6, 28), Pair(-3, 18), Pair(0, 23), Pair(-6, 14), Pair(11, 15), Pair(-4, 18)
      },
      { // Piece 4
        Pair(44, 28), Pair(-7, 61), Pair(32, 50), Pair(-35, 106), Pair(121, -38), Pair(-73, 75), Pair(-11, 35), Pair(23, 43),
        Pair(6, 40), Pair(-21, 93), Pair(46, 2), Pair(-29, 90), Pair(-17, 43), Pair(21, 50), Pair(-39, 74), Pair(-12, 80),
        Pair(-23, 43), Pair(-5, 39), Pair(-15, 58), Pair(4, 25), Pair(-15, 97), Pair(29, 34), Pair(27, -12), Pair(32, -61),
        Pair(-4, 92), Pair(-23, 66), Pair(2, 11), Pair(5, 31), Pair(2, 18), Pair(17, 53), Pair(-3, 8), Pair(-7, 26),
        Pair(-11, 40), Pair(14, 34), Pair(9, 10), Pair(13, 12), Pair(-19, 66), Pair(0, 0), Pair(-2, 37), Pair(-35, 39),
        Pair(-7, 37), Pair(-8, 55), Pair(7, 20), Pair(-20, 64), Pair(-10, -19), Pair(-1, 49), Pair(78, -183), Pair(-29, 51),
        Pair(5, 47), Pair(-1, 56), Pair(3, 15), Pair(-9, 40), Pair(-10, 15), Pair(7, -2), Pair(-1, 55), Pair(19, -5),
        Pair(8, 18), Pair(14, 33), Pair(-10, -29), Pair(-3, 12), Pair(13, -18), Pair(-23, 73), Pair(-15, -70), Pair(-27, 49)
      },
      { // Piece 5
        Pair(-16, -64), Pair(98, -45), Pair(-89, -101), Pair(2, -104), Pair(19, -66), Pair(-83, -37), Pair(-57, -45), Pair(46, -51),
        Pair(-64, -64), Pair(76, -46), Pair(56, -84), Pair(74, -44), Pair(19, 7), Pair(119, -78), Pair(1, 10), Pair(18, -82),
        Pair(-64, -33), Pair(-15, -18), Pair(17, -24), Pair(-40, -1), Pair(50, -49), Pair(258, -79), Pair(148, 6), Pair(69, -53),
        Pair(-119, 14), Pair(-16, -8), Pair(42, -23), Pair(74, -35), Pair(4, 5), Pair(130, -10), Pair(20, -12), Pair(-45, 31),
        Pair(95, 3), Pair(56, -15), Pair(18, -10), Pair(32, -3), Pair(47, -13), Pair(0, 0), Pair(11, -11), Pair(-25, 14),
        Pair(39, 13), Pair(10, -15), Pair(102, -8), Pair(-19, 13), Pair(87, -26), Pair(-67, 3), Pair(5, -27), Pair(-67, 33),
        Pair(34, -17), Pair(27, -9), Pair(-27, 23), Pair(-20, 7), Pair(36, 6), Pair(-4, 19), Pair(-2, 17), Pair(-36, 35),
        Pair(-5, 48), Pair(19, -27), Pair(9, 5), Pair(38, -1), Pair(0, 4), Pair(-34, 21), Pair(-15, 20), Pair(-10, 27)
      }
    }},
    {{ // Bucket 30
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(39, -3), Pair(9, 8), Pair(49, -13), Pair(-5, 6), Pair(-4, 16), Pair(2, 24), Pair(13, 12), Pair(-23, 10),
        Pair(3, -1), Pair(-1, -1), Pair(-6, 6), Pair(2, -3), Pair(-9, 6), Pair(11, 2), Pair(20, -3), Pair(1, 4),
        Pair(7, -6), Pair(5, -5), Pair(0, -3), Pair(-2, -5), Pair(-4, -3), Pair(-11, 2), Pair(0, 0), Pair(4, 1),
        Pair(10, -10), Pair(4, -10), Pair(0, -7), Pair(-5, -2), Pair(1, -4), Pair(-4, 0), Pair(0, 0), Pair(13, 0),
        Pair(3, -12), Pair(0, -6), Pair(0, -7), Pair(1, -7), Pair(-1, -2), Pair(-1, -3), Pair(6, 2), Pair(-3, 4),
        Pair(2, -10), Pair(2, -6), Pair(-3, -3), Pair(-4, -12), Pair(0, 0), Pair(-1, -10), Pair(1, 0), Pair(3, -7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-2, -81), Pair(-89, 6), Pair(-162, 44), Pair(80, 4), Pair(-28, 33), Pair(-52, 29), Pair(69, -2), Pair(97, -100),
        Pair(27, 1), Pair(56, -24), Pair(3, 3), Pair(-51, 25), Pair(48, -9), Pair(36, 5), Pair(25, 16), Pair(67, 6),
        Pair(-49, 4), Pair(25, 15), Pair(20, 17), Pair(14, 9), Pair(34, 19), Pair(-1, 42), Pair(4, 39), Pair(66, -1),
        Pair(8, 9), Pair(-3, 9), Pair(29, 3), Pair(49, 3), Pair(12, 19), Pair(30, 1), Pair(-2, 4), Pair(27, -8),
        Pair(3, -4), Pair(9, -5), Pair(9, 20), Pair(11, 17), Pair(18, 23), Pair(41, 17), Pair(0, 0), Pair(0, -3),
        Pair(8, -4), Pair(-5, 29), Pair(7, 11), Pair(15, 18), Pair(18, 1), Pair(-18, -8), Pair(13, 53), Pair(-13, -20),
        Pair(-24, 34), Pair(24, -13), Pair(-2, 6), Pair(-16, 19), Pair(-1, 16), Pair(-10, 2), Pair(-1, 37), Pair(-9, -35),
        Pair(-88, 20), Pair(-17, 10), Pair(1, 6), Pair(-14, 49), Pair(-6, -7), Pair(-2, 8), Pair(-34, -85), Pair(-8, -5)
      },
      { // Piece 2
        Pair(8, 43), Pair(-42, 56), Pair(-198, 83), Pair(-79, 45), Pair(-81, 45), Pair(11, 13), Pair(71, 19), Pair(25, 21),
        Pair(-49, 9), Pair(10, 32), Pair(-40, 44), Pair(-37, 67), Pair(11, 41), Pair(-31, 53), Pair(-3, 47), Pair(-6, 17),
        Pair(-5, 31), Pair(40, 18), Pair(-33, 52), Pair(-2, 55), Pair(-72, 53), Pair(-15, 38), Pair(-29, 45), Pair(19, 20),
        Pair(5, 24), Pair(3, 21), Pair(-13, 39), Pair(2, 33), Pair(9, 31), Pair(-12, 30), Pair(7, 31), Pair(-72, -9),
        Pair(-23, 24), Pair(2, 14), Pair(-8, 20), Pair(5, 36), Pair(-9, 32), Pair(-5, 35), Pair(0, 0), Pair(13, 53),
        Pair(-3, 16), Pair(7, 13), Pair(6, 15), Pair(-8, 33), Pair(1, 12), Pair(-4, -24), Pair(12, 78), Pair(-10, -93),
        Pair(-7, 17), Pair(12, 3), Pair(-20, 29), Pair(3, 13), Pair(-17, 14), Pair(9, 22), Pair(12, -1), Pair(-10, 16),
        Pair(13, -30), Pair(2, 12), Pair(-8, 5), Pair(-23, 20), Pair(9, 23), Pair(-6, 8), Pair(3, 40), Pair(-2, 21)
      },
      { // Piece 3
        Pair(22, 34), Pair(-40, 47), Pair(-48, 40), Pair(-30, 38), Pair(20, 22), Pair(-21, 48), Pair(1, 42), Pair(-47, 55),
        Pair(15, 11), Pair(37, -5), Pair(-9, 19), Pair(39, 16), Pair(-2, 23), Pair(85, -9), Pair(58, 24), Pair(39, 16),
        Pair(13, 7), Pair(21, 6), Pair(37, -1), Pair(36, 1), Pair(-22, 28), Pair(-48, 48), Pair(-12, 27), Pair(-12, 11),
        Pair(35, 9), Pair(1, 29), Pair(8, 19), Pair(18, 5), Pair(8, 23), Pair(-17, 28), Pair(66, 12), Pair(17, 7),
        Pair(14, -6), Pair(-20, 29), Pair(12, 8), Pair(-9, 23), Pair(-11, 23), Pair(26, -3), Pair(0, 0), Pair(-9, 21),
        Pair(-15, 28), Pair(25, 20), Pair(22, 8), Pair(3, 30), Pair(5, 25), Pair(38, -72), Pair(-18, 14), Pair(-3, 30),
        Pair(30, 1), Pair(8, 12), Pair(9, 13), Pair(5, 4), Pair(-8, 10), Pair(27, 13), Pair(2, -36), Pair(10, 8),
        Pair(7, 11), Pair(9, 27), Pair(10, 10), Pair(12, 18), Pair(0, 15), Pair(-1, 24), Pair(-27, 25), Pair(-3, 12)
      },
      { // Piece 4
        Pair(79, -31), Pair(17, -11), Pair(57, -21), Pair(96, 3), Pair(-1, 18), Pair(211, -116), Pair(-28, 58), Pair(-10, 38),
        Pair(-15, 3), Pair(-4, -4), Pair(23, 18), Pair(-14, 20), Pair(-11, 80), Pair(-11, 19), Pair(24, -21), Pair(29, 76),
        Pair(17, 12), Pair(18, -8), Pair(2, 35), Pair(7, 4), Pair(-11, 87), Pair(-41, 4), Pair(-22, 43), Pair(-10, 41),
        Pair(10, -14), Pair(-14, 46), Pair(3, 8), Pair(-14, 41), Pair(-20, 50), Pair(13, 6), Pair(-21, 55), Pair(-32, 46),
        Pair(9, -33), Pair(-11, -13), Pair(9, 20), Pair(-5, 30), Pair(-4, 49), Pair(-6, 48), Pair(0, 0), Pair(-19, -10),
        Pair(-15, 54), Pair(-5, 25), Pair(-16, 30), Pair(0, 15), Pair(2, 23), Pair(1, 21), Pair(-7, 9), Pair(43, -5),
        Pair(-48, 59), Pair(17, -19), Pair(4, -22), Pair(0, -3), Pair(-15, 16), Pair(-20, 33), Pair(-4, -56), Pair(-26, 31),
        Pair(25, -43), Pair(23, -61), Pair(13, 16), Pair(14, -55), Pair(-16, -2), Pair(8, -43), Pair(-68, 14), Pair(-1, -34)
      },
      { // Piece 5
        Pair(32, -57), Pair(24, -27), Pair(-19, -68), Pair(59, -15), Pair(112, 20), Pair(-29, -57), Pair(-76, -78), Pair(-18, -238),
        Pair(-77, -19), Pair(5, -20), Pair(133, -117), Pair(65, -36), Pair(-11, -47), Pair(97, -67), Pair(75, -81), Pair(-6, -31),
        Pair(225, -62), Pair(7, -26), Pair(-26, -28), Pair(34, -53), Pair(50, -29), Pair(197, -36), Pair(107, -59), Pair(216, -67),
        Pair(24, -20), Pair(58, -21), Pair(107, -31), Pair(-30, 2), Pair(21, -21), Pair(102, 1), Pair(4, 2), Pair(-28, 15),
        Pair(-109, -15), Pair(120, -24), Pair(33, -20), Pair(59, -13), Pair(20, 9), Pair(71, -10), Pair(0, 0), Pair(-25, -5),
        Pair(78, -26), Pair(52, -33), Pair(28, -20), Pair(26, 0), Pair(10, 9), Pair(143, -12), Pair(-21, -21), Pair(12, 33),
        Pair(8, -31), Pair(-9, -13), Pair(-13, -6), Pair(26, -10), Pair(-21, 17), Pair(31, 7), Pair(-13, 18), Pair(-5, 7),
        Pair(-23, -27), Pair(-28, -7), Pair(-16, -18), Pair(-13, 22), Pair(-26, 4), Pair(-11, 15), Pair(-6, 7), Pair(-16, 9)
      }
    }},
    {{ // Bucket 31
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(5, -1), Pair(15, -2), Pair(-6, 10), Pair(27, 6), Pair(30, -3), Pair(7, 12), Pair(-26, 19), Pair(82, -37),
        Pair(7, -6), Pair(-8, 3), Pair(-2, -3), Pair(3, -8), Pair(-4, 3), Pair(7, 0), Pair(3, -7), Pair(13, 17),
        Pair(9, -8), Pair(8, -5), Pair(1, -3), Pair(-4, -1), Pair(-7, 0), Pair(-7, -1), Pair(-5, -1), Pair(0, 0),
        Pair(6, -10), Pair(4, -8), Pair(0, -4), Pair(-5, -9), Pair(-2, -5), Pair(1, -6), Pair(3, -11), Pair(0, 0),
        Pair(1, -14), Pair(2, -8), Pair(-2, -9), Pair(3, -10), Pair(1, -6), Pair(1, -2), Pair(-14, -17), Pair(9, 6),
        Pair(3, -9), Pair(7, -12), Pair(-3, -7), Pair(1, -11), Pair(1, -4), Pair(2, -5), Pair(-7, -12), Pair(-5, 6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(75, -69), Pair(112, -12), Pair(46, -1), Pair(9, -33), Pair(-59, -5), Pair(-157, 36), Pair(88, -27), Pair(41, -74),
        Pair(39, 5), Pair(42, -13), Pair(34, -21), Pair(59, -10), Pair(102, 4), Pair(91, -50), Pair(-30, -6), Pair(-28, 35),
        Pair(3, 9), Pair(38, -24), Pair(63, -14), Pair(46, -1), Pair(20, 12), Pair(-19, 12), Pair(19, 8), Pair(-37, 71),
        Pair(15, -18), Pair(11, -18), Pair(28, -10), Pair(24, -10), Pair(44, -1), Pair(24, 7), Pair(19, 0), Pair(51, -31),
        Pair(-2, -24), Pair(2, -9), Pair(16, -13), Pair(31, -12), Pair(28, -3), Pair(35, 5), Pair(44, 11), Pair(0, 0),
        Pair(0, -14), Pair(14, -4), Pair(10, -1), Pair(-4, 14), Pair(2, 7), Pair(23, 1), Pair(13, -64), Pair(38, 64),
        Pair(-13, -37), Pair(29, -15), Pair(-18, -9), Pair(6, 20), Pair(3, 7), Pair(9, 6), Pair(-3, 14), Pair(38, -31),
        Pair(49, -60), Pair(8, -49), Pair(-3, -15), Pair(3, -8), Pair(-7, -13), Pair(11, 1), Pair(14, 9), Pair(14, -88)
      },
      { // Piece 2
        Pair(-12, 30), Pair(-94, 58), Pair(-151, 62), Pair(-24, 42), Pair(-189, 56), Pair(54, 30), Pair(-122, 26), Pair(-12, 67),
        Pair(-12, 10), Pair(-10, 33), Pair(-3, 32), Pair(-114, 70), Pair(-70, 53), Pair(-31, 47), Pair(-35, 51), Pair(44, 11),
        Pair(-26, 39), Pair(11, 9), Pair(-8, 42), Pair(37, 23), Pair(15, 52), Pair(-27, 39), Pair(-36, 24), Pair(-21, 39),
        Pair(-10, 11), Pair(12, 5), Pair(-29, 24), Pair(11, 23), Pair(16, 19), Pair(18, 31), Pair(30, 18), Pair(10, 21),
        Pair(15, 8), Pair(5, 16), Pair(-1, 9), Pair(7, 16), Pair(19, 6), Pair(27, 16), Pair(36, 14), Pair(0, 0),
        Pair(5, 8), Pair(-10, 20), Pair(9, 12), Pair(4, 11), Pair(8, 18), Pair(10, 26), Pair(-31, -4), Pair(21, 88),
        Pair(-32, 26), Pair(16, 3), Pair(-4, 17), Pair(7, 11), Pair(2, -2), Pair(27, 4), Pair(12, 5), Pair(21, -3),
        Pair(23, -2), Pair(-44, 26), Pair(7, -3), Pair(-22, 26), Pair(-4, 18), Pair(1, 5), Pair(17, 3), Pair(-18, 52)
      },
      { // Piece 3
        Pair(4, 24), Pair(51, -6), Pair(-13, 27), Pair(-12, 32), Pair(-36, 30), Pair(-14, 40), Pair(25, 22), Pair(31, 32),
        Pair(33, 8), Pair(31, 10), Pair(-4, 15), Pair(33, 6), Pair(-39, 21), Pair(26, 11), Pair(30, 23), Pair(88, 20),
        Pair(9, 2), Pair(15, 15), Pair(-10, 18), Pair(40, 9), Pair(25, 13), Pair(0, 23), Pair(29, 4), Pair(109, 15),
        Pair(9, 13), Pair(22, 9), Pair(20, 3), Pair(32, 6), Pair(-2, 17), Pair(40, 11), Pair(3, 14), Pair(50, 46),
        Pair(6, 12), Pair(26, 13), Pair(-6, 18), Pair(18, 12), Pair(-5, 13), Pair(31, 23), Pair(34, 16), Pair(0, 0),
        Pair(13, -7), Pair(19, 4), Pair(-16, 25), Pair(28, -3), Pair(6, 9), Pair(-6, 32), Pair(-69, -14), Pair(-36, 58),
        Pair(-20, 26), Pair(11, 15), Pair(19, -3), Pair(14, 4), Pair(7, 5), Pair(5, 9), Pair(3, 17), Pair(10, 8),
        Pair(14, 10), Pair(10, 13), Pair(9, 17), Pair(10, 17), Pair(10, 23), Pair(12, 14), Pair(-7, 25), Pair(-10, 13)
      },
      { // Piece 4
        Pair(18, -33), Pair(3, 9), Pair(37, -29), Pair(49, 2), Pair(72, -65), Pair(40, -30), Pair(-22, 24), Pair(12, 13),
        Pair(33, -17), Pair(13, 22), Pair(-2, 69), Pair(-21, 18), Pair(23, 5), Pair(31, 20), Pair(30, 29), Pair(22, 24),
        Pair(13, -13), Pair(17, -15), Pair(-5, 25), Pair(-37, 61), Pair(44, -17), Pair(19, 58), Pair(-48, 4), Pair(5, -13),
        Pair(12, 36), Pair(21, -24), Pair(28, 27), Pair(26, 12), Pair(-9, 61), Pair(40, -18), Pair(7, -19), Pair(-12, 55),
        Pair(-3, 7), Pair(-15, -9), Pair(15, -10), Pair(6, 24), Pair(7, 32), Pair(-7, 30), Pair(31, 11), Pair(0, 0),
        Pair(19, -14), Pair(4, 14), Pair(3, -3), Pair(3, 14), Pair(6, -1), Pair(-8, 31), Pair(23, -72), Pair(-14, 39),
        Pair(-17, 3), Pair(12, -26), Pair(-3, 19), Pair(5, 18), Pair(18, -12), Pair(8, -12), Pair(14, 6), Pair(-25, -25),
        Pair(-22, 16), Pair(-34, 13), Pair(12, 30), Pair(-2, 26), Pair(6, 22), Pair(-48, 81), Pair(26, -25), Pair(17, 78)
      },
      { // Piece 5
        Pair(-12, -91), Pair(10, -44), Pair(89, -138), Pair(44, -46), Pair(62, -13), Pair(58, -50), Pair(9, -90), Pair(-19, -112),
        Pair(139, -27), Pair(-8, -93), Pair(-18, -33), Pair(18, -37), Pair(0, -61), Pair(73, -42), Pair(-50, -60), Pair(10, -82),
        Pair(24, -69), Pair(2, -43), Pair(58, -53), Pair(27, -9), Pair(180, -63), Pair(108, -32), Pair(60, -49), Pair(172, -64),
        Pair(22, -57), Pair(57, -42), Pair(92, -40), Pair(118, -34), Pair(52, -13), Pair(114, -15), Pair(2, 16), Pair(74, -28),
        Pair(74, -54), Pair(67, -65), Pair(82, -47), Pair(67, -23), Pair(36, -6), Pair(18, 6), Pair(24, -11), Pair(0, 0),
        Pair(103, -42), Pair(53, -38), Pair(19, -30), Pair(20, -14), Pair(27, 4), Pair(-17, 17), Pair(-25, 1), Pair(63, -19),
        Pair(-71, 9), Pair(-26, -35), Pair(8, -18), Pair(-24, -2), Pair(-10, 9), Pair(-32, 21), Pair(4, 31), Pair(20, 22),
        Pair(-65, 18), Pair(-41, 4), Pair(-25, -27), Pair(-7, -18), Pair(-22, 17), Pair(-57, 36), Pair(5, 14), Pair(-5, 9)
      }
    }},
    {{ // Bucket 32
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(35, -30), Pair(6, 8), Pair(-7, 9), Pair(-9, 13), Pair(-20, 24), Pair(33, 6), Pair(-33, 28), Pair(-9, 21),
        Pair(17, -1), Pair(-3, 11), Pair(0, 8), Pair(1, -3), Pair(-3, 8), Pair(-6, 13), Pair(-18, 19), Pair(-4, 20),
        Pair(0, 0), Pair(-6, -1), Pair(-2, 0), Pair(-1, 1), Pair(-5, 3), Pair(-6, 7), Pair(-9, 10), Pair(-6, 10),
        Pair(0, 0), Pair(-9, -5), Pair(-2, -3), Pair(-3, 0), Pair(-3, 2), Pair(-5, 4), Pair(-5, 3), Pair(-4, 3),
        Pair(0, 7), Pair(-4, -2), Pair(-1, 0), Pair(0, -1), Pair(-2, 1), Pair(-7, 2), Pair(-5, 1), Pair(-7, -5),
        Pair(6, 3), Pair(-4, -5), Pair(2, -1), Pair(-3, -6), Pair(-2, 3), Pair(-4, -2), Pair(0, -1), Pair(-5, -1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-67, 43), Pair(2, 18), Pair(31, 8), Pair(10, 35), Pair(1, 38), Pair(-22, 66), Pair(-52, 64), Pair(-19, -27),
        Pair(42, 42), Pair(41, 30), Pair(21, 35), Pair(3, 36), Pair(8, 52), Pair(61, 18), Pair(10, -23), Pair(86, 5),
        Pair(-25, 48), Pair(-5, 31), Pair(-12, 42), Pair(17, 36), Pair(14, 36), Pair(46, 32), Pair(38, 25), Pair(44, 17),
        Pair(0, 0), Pair(4, 53), Pair(-5, 41), Pair(11, 32), Pair(14, 35), Pair(17, 34), Pair(15, 33), Pair(24, 16),
        Pair(9, 71), Pair(-80, -58), Pair(5, 41), Pair(0, 37), Pair(8, 35), Pair(12, 32), Pair(10, 33), Pair(10, 32),
        Pair(-6, 42), Pair(-8, 47), Pair(-4, 40), Pair(-12, 33), Pair(-2, 41), Pair(2, 35), Pair(5, 26), Pair(13, 22),
        Pair(-1, -18), Pair(-2, 35), Pair(-15, 29), Pair(1, 33), Pair(-2, 35), Pair(6, 23), Pair(-11, 44), Pair(-1, 17),
        Pair(-20, 10), Pair(5, 28), Pair(-4, 24), Pair(7, 22), Pair(-9, 29), Pair(-3, 29), Pair(4, 34), Pair(10, -4)
      },
      { // Piece 2
        Pair(-9, 37), Pair(-26, 98), Pair(5, 77), Pair(-69, 104), Pair(-33, 81), Pair(-1, 81), Pair(52, 53), Pair(-48, 62),
        Pair(12, 62), Pair(-22, 51), Pair(-8, 67), Pair(-23, 89), Pair(-25, 88), Pair(-39, 77), Pair(17, 82), Pair(-27, 59),
        Pair(-24, 61), Pair(-24, 78), Pair(-22, 63), Pair(-31, 89), Pair(-34, 86), Pair(18, 79), Pair(-16, 66), Pair(27, 50),
        Pair(0, 0), Pair(-14, 65), Pair(6, 55), Pair(-15, 62), Pair(3, 78), Pair(11, 49), Pair(2, 68), Pair(11, 32),
        Pair(-17, 108), Pair(-131, 48), Pair(-10, 58), Pair(-7, 70), Pair(0, 45), Pair(0, 58), Pair(-16, 63), Pair(9, 52),
        Pair(-4, 67), Pair(-13, 48), Pair(-2, 60), Pair(-9, 49), Pair(-2, 51), Pair(-14, 45), Pair(4, 47), Pair(-3, 27),
        Pair(-17, 55), Pair(3, 66), Pair(-9, 46), Pair(-4, 51), Pair(-15, 42), Pair(-14, 56), Pair(-5, 26), Pair(-12, 58),
        Pair(15, 47), Pair(-3, 52), Pair(2, 56), Pair(-8, 45), Pair(-4, 56), Pair(-14, 37), Pair(9, 27), Pair(9, 40)
      },
      { // Piece 3
        Pair(31, 83), Pair(9, 95), Pair(-39, 109), Pair(7, 85), Pair(-14, 95), Pair(-13, 100), Pair(38, 80), Pair(-9, 98),
        Pair(7, 101), Pair(-2, 87), Pair(-8, 97), Pair(-17, 99), Pair(12, 99), Pair(46, 82), Pair(87, 55), Pair(39, 67),
        Pair(21, 97), Pair(2, 77), Pair(-24, 104), Pair(7, 86), Pair(3, 82), Pair(1, 85), Pair(20, 79), Pair(13, 86),
        Pair(0, 0), Pair(-5, 103), Pair(-4, 111), Pair(10, 82), Pair(-6, 94), Pair(-2, 83), Pair(-3, 81), Pair(15, 74),
        Pair(-22, 96), Pair(51, -20), Pair(-22, 83), Pair(-26, 86), Pair(-6, 70), Pair(-10, 78), Pair(21, 71), Pair(4, 77),
        Pair(-33, 78), Pair(-27, 82), Pair(-32, 92), Pair(-13, 69), Pair(-20, 84), Pair(-13, 68), Pair(6, 83), Pair(10, 84),
        Pair(-20, 64), Pair(-25, 73), Pair(-10, 72), Pair(-12, 57), Pair(-15, 67), Pair(-15, 86), Pair(-1, 67), Pair(-2, 87),
        Pair(-22, 67), Pair(-21, 78), Pair(-18, 76), Pair(-13, 76), Pair(-9, 70), Pair(-10, 75), Pair(1, 80), Pair(-9, 85)
      },
      { // Piece 4
        Pair(-2, 194), Pair(68, 117), Pair(3, 193), Pair(-54, 228), Pair(51, 134), Pair(82, 116), Pair(113, 74), Pair(82, 107),
        Pair(18, 185), Pair(40, 119), Pair(42, 147), Pair(38, 135), Pair(32, 173), Pair(55, 121), Pair(61, 146), Pair(97, 102),
        Pair(26, 122), Pair(35, 137), Pair(12, 183), Pair(7, 183), Pair(51, 116), Pair(73, 152), Pair(58, 109), Pair(56, 111),
        Pair(0, 0), Pair(23, 145), Pair(40, 134), Pair(19, 157), Pair(19, 167), Pair(17, 199), Pair(45, 154), Pair(37, 150),
        Pair(25, 121), Pair(65, 2), Pair(34, 123), Pair(28, 129), Pair(28, 140), Pair(28, 140), Pair(31, 132), Pair(33, 148),
        Pair(-2, 183), Pair(16, 117), Pair(15, 129), Pair(22, 106), Pair(20, 141), Pair(27, 129), Pair(30, 119), Pair(44, 121),
        Pair(26, 150), Pair(13, 148), Pair(21, 114), Pair(22, 123), Pair(23, 116), Pair(18, 117), Pair(14, 110), Pair(54, 145),
        Pair(20, 121), Pair(23, 106), Pair(12, 140), Pair(18, 116), Pair(7, 129), Pair(6, 120), Pair(34, 122), Pair(35, 93)
      },
      { // Piece 5
        Pair(-22, 65), Pair(-60, -84), Pair(-44, 32), Pair(30, 14), Pair(-90, 7), Pair(-48, -41), Pair(-44, -9), Pair(-8, -17),
        Pair(43, 13), Pair(-118, -32), Pair(122, -25), Pair(158, -47), Pair(93, -22), Pair(73, -48), Pair(-44, -13), Pair(20, -61),
        Pair(-96, -20), Pair(85, -7), Pair(86, -11), Pair(10, -5), Pair(126, -31), Pair(-13, 20), Pair(43, -3), Pair(8, 8),
        Pair(0, 0), Pair(82, -42), Pair(10, -3), Pair(4, 10), Pair(76, -7), Pair(73, -14), Pair(48, -12), Pair(48, -15),
        Pair(25, -57), Pair(47, -87), Pair(25, -3), Pair(13, 3), Pair(42, -8), Pair(17, 1), Pair(4, -2), Pair(74, -23),
        Pair(60, -19), Pair(20, -7), Pair(-23, 3), Pair(21, 6), Pair(12, 0), Pair(18, -5), Pair(10, -2), Pair(35, -4),
        Pair(22, -14), Pair(-26, 23), Pair(-20, 24), Pair(20, 12), Pair(15, 0), Pair(11, -3), Pair(2, -5), Pair(1, -1),
        Pair(1, 6), Pair(16, 0), Pair(-2, 18), Pair(5, 1), Pair(11, 6), Pair(1, -3), Pair(2, -6), Pair(6, -11)
      }
    }},
    {{ // Bucket 33
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-19, 21), Pair(82, 0), Pair(-23, 18), Pair(12, 24), Pair(14, 13), Pair(18, 21), Pair(-21, 20), Pair(28, 16),
        Pair(-2, 5), Pair(8, 16), Pair(-6, 13), Pair(4, 11), Pair(2, 11), Pair(7, 13), Pair(14, 11), Pair(0, 17),
        Pair(-4, 9), Pair(0, 0), Pair(-2, 5), Pair(-2, 2), Pair(-2, 7), Pair(-9, 11), Pair(-3, 11), Pair(-2, 7),
        Pair(9, 6), Pair(0, 0), Pair(2, 10), Pair(-1, 2), Pair(-4, 2), Pair(-4, 4), Pair(-2, 5), Pair(-2, 7),
        Pair(6, -1), Pair(3, 4), Pair(-1, 7), Pair(0, 2), Pair(-3, 4), Pair(-9, 3), Pair(-8, 1), Pair(-3, 2),
        Pair(3, 2), Pair(8, 7), Pair(-1, 2), Pair(-1, -1), Pair(-1, 0), Pair(-7, -3), Pair(-5, -2), Pair(-3, 2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-24, 33), Pair(23, 33), Pair(-13, 24), Pair(-45, 65), Pair(4, 11), Pair(15, 67), Pair(-58, 70), Pair(5, 29),
        Pair(-46, 35), Pair(7, 51), Pair(46, 36), Pair(70, 2), Pair(32, 34), Pair(53, 41), Pair(65, 7), Pair(51, 22),
        Pair(35, 33), Pair(10, 2), Pair(-4, 70), Pair(35, 34), Pair(21, 48), Pair(38, 54), Pair(61, 16), Pair(6, 25),
        Pair(-21, 45), Pair(0, 0), Pair(4, 51), Pair(15, 55), Pair(21, 41), Pair(29, 51), Pair(30, 50), Pair(48, 18),
        Pair(-19, -38), Pair(9, 87), Pair(-28, 1), Pair(16, 43), Pair(22, 44), Pair(8, 47), Pair(39, 28), Pair(31, 39),
        Pair(-6, 11), Pair(5, 56), Pair(3, 30), Pair(7, 57), Pair(3, 33), Pair(13, 48), Pair(12, 40), Pair(13, 45),
        Pair(14, 38), Pair(-15, -27), Pair(4, 57), Pair(6, 39), Pair(17, 34), Pair(17, 36), Pair(9, 31), Pair(19, 21),
        Pair(7, 16), Pair(6, 41), Pair(5, 37), Pair(-1, 42), Pair(2, 35), Pair(14, 51), Pair(15, 54), Pair(-13, 66)
      },
      { // Piece 2
        Pair(3, 70), Pair(1, 54), Pair(-2, 74), Pair(-68, 94), Pair(-54, 78), Pair(-80, 104), Pair(-24, 109), Pair(-5, 79),
        Pair(-21, 65), Pair(-25, 80), Pair(-31, 89), Pair(-23, 87), Pair(9, 71), Pair(-8, 61), Pair(-25, 72), Pair(20, 77),
        Pair(-47, 46), Pair(-7, 64), Pair(0, 66), Pair(26, 68), Pair(23, 81), Pair(5, 89), Pair(0, 92), Pair(16, 61),
        Pair(13, 56), Pair(0, 0), Pair(6, 67), Pair(8, 76), Pair(19, 55), Pair(3, 77), Pair(14, 52), Pair(19, 56),
        Pair(-17, 13), Pair(3, 110), Pair(-8, -1), Pair(10, 57), Pair(10, 65), Pair(3, 60), Pair(15, 57), Pair(27, 41),
        Pair(-6, 40), Pair(-2, 73), Pair(-4, 55), Pair(7, 46), Pair(9, 53), Pair(0, 62), Pair(9, 32), Pair(3, 59),
        Pair(4, 54), Pair(9, 55), Pair(17, 48), Pair(8, 50), Pair(7, 34), Pair(7, 36), Pair(13, 43), Pair(-2, 40),
        Pair(2, 80), Pair(16, 83), Pair(8, 59), Pair(-3, 65), Pair(-5, 53), Pair(4, 45), Pair(5, 42), Pair(1, 57)
      },
      { // Piece 3
        Pair(3, 84), Pair(22, 91), Pair(-33, 95), Pair(35, 81), Pair(31, 88), Pair(-19, 102), Pair(-18, 97), Pair(34, 90),
        Pair(17, 88), Pair(40, 82), Pair(0, 91), Pair(-7, 99), Pair(33, 81), Pair(29, 76), Pair(6, 76), Pair(5, 88),
        Pair(9, 72), Pair(5, 86), Pair(1, 83), Pair(21, 76), Pair(3, 91), Pair(-23, 93), Pair(12, 85), Pair(54, 57),
        Pair(-6, 63), Pair(0, 0), Pair(14, 89), Pair(7, 89), Pair(9, 86), Pair(5, 89), Pair(-8, 89), Pair(15, 66),
        Pair(-22, -22), Pair(-2, 66), Pair(-11, 55), Pair(-5, 72), Pair(-8, 86), Pair(5, 73), Pair(35, 55), Pair(10, 80),
        Pair(-26, 76), Pair(-1, 71), Pair(-31, 76), Pair(-1, 75), Pair(14, 59), Pair(12, 62), Pair(-2, 83), Pair(36, 43),
        Pair(10, 55), Pair(-20, 57), Pair(-7, 76), Pair(10, 67), Pair(-3, 69), Pair(3, 70), Pair(18, 67), Pair(12, 47),
        Pair(-3, 69), Pair(-8, 60), Pair(-6, 73), Pair(2, 76), Pair(4, 73), Pair(1, 80), Pair(12, 75), Pair(9, 77)
      },
      { // Piece 4
        Pair(-2, 144), Pair(35, 108), Pair(8, 120), Pair(53, 131), Pair(31, 156), Pair(151, 48), Pair(4, 95), Pair(23, 168),
        Pair(46, 121), Pair(50, 131), Pair(43, 142), Pair(19, 132), Pair(66, 127), Pair(53, 103), Pair(-15, 142), Pair(50, 111),
        Pair(24, 112), Pair(18, 154), Pair(13, 152), Pair(39, 136), Pair(42, 138), Pair(74, 112), Pair(55, 101), Pair(52, 99),
        Pair(32, 88), Pair(0, 0), Pair(36, 140), Pair(36, 111), Pair(25, 143), Pair(33, 111), Pair(33, 125), Pair(29, 128),
        Pair(49, -23), Pair(25, 107), Pair(63, 83), Pair(9, 128), Pair(38, 102), Pair(30, 84), Pair(35, 95), Pair(47, 104),
        Pair(4, 134), Pair(17, 108), Pair(32, 83), Pair(24, 101), Pair(24, 111), Pair(33, 90), Pair(32, 129), Pair(36, 111),
        Pair(19, 102), Pair(11, 106), Pair(23, 81), Pair(26, 109), Pair(19, 118), Pair(30, 73), Pair(30, 65), Pair(20, 91),
        Pair(0, 129), Pair(31, 70), Pair(20, 106), Pair(25, 103), Pair(15, 117), Pair(39, 74), Pair(56, 74), Pair(17, 161)
      },
      { // Piece 5
        Pair(16, 9), Pair(79, -4), Pair(46, -52), Pair(55, -15), Pair(-40, 12), Pair(-102, 23), Pair(25, -7), Pair(27, -45),
        Pair(-12, -39), Pair(-27, -24), Pair(-48, -37), Pair(79, -46), Pair(26, -14), Pair(-63, 7), Pair(1, 5), Pair(3, 34),
        Pair(22, -16), Pair(-2, 19), Pair(136, -9), Pair(166, -26), Pair(200, -15), Pair(105, -10), Pair(103, -16), Pair(96, -9),
        Pair(-18, -24), Pair(0, 0), Pair(96, -39), Pair(49, -22), Pair(57, -1), Pair(19, 2), Pair(16, -4), Pair(10, -3),
        Pair(-17, 0), Pair(-9, -66), Pair(-20, 38), Pair(28, -18), Pair(6, 6), Pair(8, -1), Pair(39, -12), Pair(38, -13),
        Pair(-2, -14), Pair(6, -22), Pair(26, -20), Pair(8, -8), Pair(11, -4), Pair(32, -6), Pair(31, -9), Pair(15, -7),
        Pair(-40, 12), Pair(5, -13), Pair(1, -10), Pair(5, 1), Pair(20, -12), Pair(5, -2), Pair(17, -12), Pair(9, -5),
        Pair(2, 13), Pair(-4, 5), Pair(1, 4), Pair(44, -9), Pair(1, 7), Pair(33, -12), Pair(8, -11), Pair(13, -19)
      }
    }},
    {{ // Bucket 34
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-11, 24), Pair(-23, 18), Pair(-2, -4), Pair(1, -1), Pair(16, 13), Pair(-5, 24), Pair(5, 27), Pair(17, 2),
        Pair(3, 2), Pair(2, 3), Pair(-5, 12), Pair(8, -3), Pair(1, 9), Pair(2, 17), Pair(5, 15), Pair(-6, 13),
        Pair(2, 3), Pair(1, 3), Pair(0, 0), Pair(1, 2), Pair(-2, 1), Pair(2, 5), Pair(0, 6), Pair(1, 4),
        Pair(1, 2), Pair(-2, -10), Pair(0, 0), Pair(-1, -1), Pair(-1, -1), Pair(-4, 5), Pair(0, 2), Pair(-2, 4),
        Pair(2, 0), Pair(1, -6), Pair(2, 3), Pair(-1, 1), Pair(-1, 1), Pair(-8, 1), Pair(-3, -2), Pair(-2, 0),
        Pair(1, 0), Pair(-1, -8), Pair(8, 7), Pair(-9, -4), Pair(-1, -1), Pair(-6, -2), Pair(0, 0), Pair(1, -2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-36, 46), Pair(50, -30), Pair(54, 28), Pair(-6, 16), Pair(18, 44), Pair(-51, 73), Pair(-12, 64), Pair(21, 37),
        Pair(-1, 34), Pair(-22, 38), Pair(3, 53), Pair(-26, 61), Pair(16, 58), Pair(24, 52), Pair(-13, 57), Pair(70, 22),
        Pair(-44, 16), Pair(-15, 59), Pair(-14, 44), Pair(2, 65), Pair(-24, 48), Pair(16, 41), Pair(-14, 42), Pair(23, 50),
        Pair(-18, 70), Pair(-6, 39), Pair(0, 0), Pair(-4, 55), Pair(3, 50), Pair(-1, 40), Pair(8, 45), Pair(13, 37),
        Pair(-9, 44), Pair(-29, 28), Pair(6, 89), Pair(-51, 33), Pair(10, 39), Pair(-6, 49), Pair(11, 53), Pair(1, 67),
        Pair(3, 41), Pair(-22, 22), Pair(-1, 52), Pair(-13, 29), Pair(-14, 50), Pair(-5, 35), Pair(-4, 48), Pair(0, 31),
        Pair(-23, 20), Pair(-19, 77), Pair(-9, -1), Pair(-4, 53), Pair(-9, 28), Pair(4, 38), Pair(-6, 50), Pair(9, 52),
        Pair(-4, 36), Pair(2, 67), Pair(-27, 30), Pair(-9, 44), Pair(-4, 33), Pair(9, 44), Pair(4, 34), Pair(13, 32)
      },
      { // Piece 2
        Pair(-1, 52), Pair(3, 39), Pair(-46, 68), Pair(-31, 63), Pair(-41, 74), Pair(-8, 54), Pair(-25, 73), Pair(-7, 75),
        Pair(-43, 20), Pair(-9, 43), Pair(-29, 63), Pair(-42, 77), Pair(-1, 35), Pair(-7, 70), Pair(-12, 54), Pair(-16, 56),
        Pair(1, 58), Pair(-69, 57), Pair(-27, 56), Pair(-3, 49), Pair(-27, 67), Pair(-10, 55), Pair(9, 61), Pair(-5, 46),
        Pair(-17, 56), Pair(-15, 58), Pair(0, 0), Pair(-13, 60), Pair(-5, 53), Pair(-14, 61), Pair(-6, 48), Pair(-6, 56),
        Pair(-18, 56), Pair(-64, -61), Pair(4, 88), Pair(-59, 2), Pair(4, 40), Pair(-9, 50), Pair(1, 39), Pair(0, 47),
        Pair(-23, 3), Pair(-15, 49), Pair(-7, 33), Pair(-6, 38), Pair(-15, 22), Pair(-6, 42), Pair(-2, 38), Pair(-3, 48),
        Pair(-23, 44), Pair(-9, 16), Pair(-1, 47), Pair(-9, 34), Pair(-7, 37), Pair(-19, 28), Pair(-2, 36), Pair(1, 47),
        Pair(-9, 40), Pair(7, 66), Pair(-6, 31), Pair(-13, 41), Pair(-9, 32), Pair(-3, 37), Pair(-41, 33), Pair(14, 37)
      },
      { // Piece 3
        Pair(33, 59), Pair(4, 60), Pair(-44, 90), Pair(21, 51), Pair(14, 71), Pair(26, 49), Pair(53, 46), Pair(-7, 73),
        Pair(-8, 68), Pair(-20, 76), Pair(-28, 81), Pair(-11, 76), Pair(-2, 67), Pair(17, 67), Pair(33, 41), Pair(25, 56),
        Pair(5, 60), Pair(-26, 65), Pair(0, 67), Pair(9, 50), Pair(-19, 69), Pair(29, 56), Pair(7, 60), Pair(23, 50),
        Pair(-21, 67), Pair(-18, 51), Pair(0, 0), Pair(2, 62), Pair(-8, 57), Pair(-7, 59), Pair(-13, 46), Pair(5, 59),
        Pair(-16, 56), Pair(-16, -5), Pair(-29, 56), Pair(-4, -40), Pair(-31, 62), Pair(-26, 63), Pair(-39, 69), Pair(19, 48),
        Pair(-12, 56), Pair(-29, 57), Pair(-32, 59), Pair(-4, 39), Pair(-26, 62), Pair(-12, 62), Pair(3, 53), Pair(11, 43),
        Pair(-8, 67), Pair(-6, 49), Pair(-18, 42), Pair(-12, 45), Pair(-9, 50), Pair(1, 48), Pair(12, 42), Pair(-3, 68),
        Pair(-12, 58), Pair(-15, 54), Pair(-16, 49), Pair(-13, 49), Pair(-11, 56), Pair(-7, 52), Pair(-3, 55), Pair(1, 54)
      },
      { // Piece 4
        Pair(38, 92), Pair(48, 74), Pair(56, 61), Pair(21, 94), Pair(75, 67), Pair(82, 49), Pair(11, 86), Pair(67, 93),
        Pair(26, 99), Pair(14, 116), Pair(23, 133), Pair(-5, 127), Pair(11, 108), Pair(19, 145), Pair(14, 133), Pair(15, 127),
        Pair(20, 105), Pair(8, 78), Pair(1, 125), Pair(38, 96), Pair(41, 113), Pair(25, 120), Pair(19, 106), Pair(14, 133),
        Pair(17, 91), Pair(-3, 115), Pair(0, 0), Pair(30, 101), Pair(14, 120), Pair(22, 120), Pair(40, 92), Pair(27, 117),
        Pair(8, 88), Pair(15, 43), Pair(17, 86), Pair(30, 26), Pair(27, 101), Pair(25, 80), Pair(25, 110), Pair(35, 81),
        Pair(7, 91), Pair(11, 69), Pair(31, 54), Pair(16, 80), Pair(21, 60), Pair(13, 84), Pair(20, 87), Pair(25, 115),
        Pair(14, 99), Pair(1, 85), Pair(18, 74), Pair(12, 82), Pair(15, 82), Pair(13, 71), Pair(15, 97), Pair(33, 104),
        Pair(15, 85), Pair(12, 81), Pair(11, 78), Pair(15, 71), Pair(6, 88), Pair(29, 61), Pair(43, 29), Pair(28, 90)
      },
      { // Piece 5
        Pair(-4, -119), Pair(10, -73), Pair(82, -43), Pair(19, -12), Pair(28, -12), Pair(49, -64), Pair(17, -37), Pair(12, -67),
        Pair(-15, -27), Pair(-10, 22), Pair(-179, 25), Pair(-80, -8), Pair(40, -29), Pair(-13, -29), Pair(43, 6), Pair(-15, -4),
        Pair(54, -49), Pair(77, -9), Pair(-44, 47), Pair(120, -9), Pair(51, 3), Pair(3, 20), Pair(-35, 11), Pair(-32, -11),
        Pair(-186, 34), Pair(71, -42), Pair(0, 0), Pair(30, -45), Pair(71, -18), Pair(63, 2), Pair(21, 8), Pair(23, -14),
        Pair(-11, 22), Pair(-75, -27), Pair(-24, -37), Pair(-58, -72), Pair(13, -7), Pair(50, 6), Pair(10, 2), Pair(-3, 3),
        Pair(-97, 19), Pair(-4, -2), Pair(-1, -20), Pair(43, -24), Pair(-15, 3), Pair(12, 2), Pair(8, 4), Pair(7, 0),
        Pair(-27, 30), Pair(-7, -5), Pair(-22, 4), Pair(-2, -7), Pair(1, 14), Pair(16, 4), Pair(-1, 7), Pair(9, -1),
        Pair(-9, 14), Pair(-16, 2), Pair(-11, 17), Pair(5, 5), Pair(3, 7), Pair(16, 5), Pair(3, 5), Pair(2, 0)
      }
    }},
    {{ // Bucket 35
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-10, 9), Pair(-14, 30), Pair(22, -11), Pair(38, -11), Pair(-17, 27), Pair(3, -8), Pair(11, 15), Pair(13, 27),
        Pair(-2, 17), Pair(2, 3), Pair(3, 10), Pair(-9, 16), Pair(17, -2), Pair(-1, 11), Pair(-2, 19), Pair(-14, 12),
        Pair(-1, 2), Pair(5, 3), Pair(-4, 2), Pair(0, 0), Pair(3, 3), Pair(2, 2), Pair(3, 1), Pair(6, 9),
        Pair(2, -1), Pair(2, -4), Pair(1, 0), Pair(0, 0), Pair(-1, -3), Pair(-2, 2), Pair(5, 1), Pair(3, 3),
        Pair(2, -3), Pair(4, -3), Pair(1, -4), Pair(2, 5), Pair(-1, -1), Pair(-3, 3), Pair(1, -2), Pair(0, -1),
        Pair(4, -1), Pair(2, 0), Pair(-2, -4), Pair(3, 5), Pair(-3, -6), Pair(-2, 1), Pair(3, -3), Pair(5, -1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-50, 24), Pair(-16, 51), Pair(-25, 50), Pair(0, 52), Pair(-17, 57), Pair(33, 14), Pair(-44, 52), Pair(6, 47),
        Pair(-1, 65), Pair(-16, 53), Pair(8, 49), Pair(-5, 56), Pair(-12, 40), Pair(6, 28), Pair(4, 52), Pair(6, 47),
        Pair(-7, 43), Pair(-42, 21), Pair(-29, 67), Pair(-9, 41), Pair(16, 46), Pair(-4, 23), Pair(19, 49), Pair(25, 38),
        Pair(-27, 31), Pair(-5, 29), Pair(-2, 47), Pair(0, 0), Pair(-5, 55), Pair(1, 62), Pair(0, 34), Pair(-11, 48),
        Pair(-10, 33), Pair(7, 28), Pair(-27, -25), Pair(15, 81), Pair(-52, 38), Pair(-2, 37), Pair(4, 50), Pair(9, 46),
        Pair(-8, 13), Pair(-10, 37), Pair(-11, 16), Pair(-5, 54), Pair(-15, 25), Pair(1, 50), Pair(-3, 21), Pair(8, 39),
        Pair(13, 34), Pair(-5, 5), Pair(1, 44), Pair(-13, 7), Pair(-1, 43), Pair(-2, 32), Pair(-1, 42), Pair(-7, 71),
        Pair(-6, 67), Pair(-1, 16), Pair(17, 21), Pair(-2, 32), Pair(4, 31), Pair(5, 36), Pair(8, 47), Pair(-31, 74)
      },
      { // Piece 2
        Pair(-53, 4), Pair(-66, 57), Pair(-29, 50), Pair(-37, 38), Pair(-17, 71), Pair(-75, 62), Pair(-136, 85), Pair(-37, 42),
        Pair(-17, 53), Pair(-10, 34), Pair(7, 29), Pair(-84, 73), Pair(-35, 50), Pair(13, 39), Pair(-37, 79), Pair(-2, 44),
        Pair(-23, 41), Pair(-18, 54), Pair(-68, 25), Pair(-10, 44), Pair(-12, 37), Pair(-12, 42), Pair(-13, 53), Pair(2, 44),
        Pair(-22, 58), Pair(-16, 35), Pair(-8, 52), Pair(0, 0), Pair(-7, 54), Pair(-5, 43), Pair(2, 41), Pair(-14, 49),
        Pair(-26, 53), Pair(-6, 39), Pair(-39, -4), Pair(12, 79), Pair(-54, -113), Pair(-6, 43), Pair(-18, 46), Pair(7, 38),
        Pair(1, 29), Pair(-29, 11), Pair(-8, 39), Pair(-10, 35), Pair(-7, 26), Pair(-20, 22), Pair(0, 33), Pair(-14, 40),
        Pair(-34, -32), Pair(-2, 17), Pair(-14, 24), Pair(1, 31), Pair(-13, 24), Pair(3, 41), Pair(-16, 3), Pair(5, 24),
        Pair(-13, 35), Pair(0, 26), Pair(0, 32), Pair(-15, 31), Pair(-9, 44), Pair(-6, 22), Pair(-26, 64), Pair(-18, 30)
      },
      { // Piece 3
        Pair(24, 40), Pair(19, 51), Pair(32, 40), Pair(21, 48), Pair(-14, 60), Pair(26, 46), Pair(-29, 61), Pair(-41, 75),
        Pair(2, 54), Pair(-12, 63), Pair(4, 52), Pair(-37, 75), Pair(-18, 70), Pair(20, 50), Pair(-7, 59), Pair(14, 52),
        Pair(-10, 54), Pair(-4, 56), Pair(-12, 58), Pair(-30, 62), Pair(15, 45), Pair(42, 48), Pair(-2, 58), Pair(17, 40),
        Pair(-6, 42), Pair(-7, 51), Pair(0, 43), Pair(0, 0), Pair(3, 49), Pair(8, 48), Pair(32, 29), Pair(8, 48),
        Pair(-7, 46), Pair(-11, 36), Pair(16, 0), Pair(-4, 39), Pair(-26, -1), Pair(-17, 45), Pair(-22, 56), Pair(7, 29),
        Pair(-3, 47), Pair(-9, 31), Pair(-7, 41), Pair(-17, 43), Pair(-26, 40), Pair(-3, 36), Pair(1, 51), Pair(3, 50),
        Pair(-2, 50), Pair(-14, 58), Pair(-17, 47), Pair(-13, 24), Pair(-10, 30), Pair(-1, 38), Pair(-5, 37), Pair(15, 51),
        Pair(-6, 45), Pair(-9, 50), Pair(-9, 48), Pair(-13, 41), Pair(-11, 50), Pair(-6, 47), Pair(3, 42), Pair(7, 35)
      },
      { // Piece 4
        Pair(0, 73), Pair(45, 42), Pair(-4, 128), Pair(33, 83), Pair(-8, 96), Pair(-2, 158), Pair(40, 98), Pair(0, 111),
        Pair(-1, 117), Pair(15, 54), Pair(24, 95), Pair(35, 51), Pair(9, 113), Pair(-14, 147), Pair(8, 115), Pair(13, 92),
        Pair(17, 74), Pair(11, 95), Pair(-11, 78), Pair(16, 106), Pair(21, 109), Pair(36, 114), Pair(2, 123), Pair(10, 106),
        Pair(-1, 84), Pair(11, 86), Pair(-10, 116), Pair(0, 0), Pair(5, 92), Pair(2, 108), Pair(37, 98), Pair(9, 116),
        Pair(12, 66), Pair(3, 99), Pair(9, -54), Pair(28, 75), Pair(46, -25), Pair(11, 106), Pair(16, 71), Pair(22, 104),
        Pair(1, 99), Pair(3, 78), Pair(12, 77), Pair(16, 66), Pair(8, 87), Pair(13, 53), Pair(12, 88), Pair(15, 82),
        Pair(3, 66), Pair(2, 86), Pair(4, 73), Pair(16, 76), Pair(6, 67), Pair(7, 113), Pair(8, 58), Pair(31, 60),
        Pair(5, 72), Pair(1, 85), Pair(8, 79), Pair(14, 76), Pair(14, 66), Pair(10, 72), Pair(18, 46), Pair(23, 75)
      },
      { // Piece 5
        Pair(58, 132), Pair(-42, -48), Pair(-80, -43), Pair(-4, -35), Pair(45, 40), Pair(58, -59), Pair(19, -9), Pair(128, 6),
        Pair(22, 46), Pair(-50, 23), Pair(25, -27), Pair(61, -62), Pair(-28, 5), Pair(-7, -25), Pair(48, -21), Pair(20, -14),
        Pair(28, 72), Pair(-27, -20), Pair(71, -21), Pair(81, -34), Pair(23, -22), Pair(96, -34), Pair(-14, -2), Pair(48, -10),
        Pair(72, -9), Pair(56, -8), Pair(3, -47), Pair(0, 0), Pair(93, -61), Pair(16, -5), Pair(8, 2), Pair(-12, 13),
        Pair(25, 0), Pair(-6, 6), Pair(-42, 5), Pair(-39, -58), Pair(18, 9), Pair(28, -2), Pair(35, 9), Pair(51, -12),
        Pair(-10, 4), Pair(-3, -1), Pair(24, -27), Pair(34, -36), Pair(2, -15), Pair(-13, 2), Pair(-1, 12), Pair(16, 9),
        Pair(-19, 16), Pair(-14, 21), Pair(-5, -9), Pair(9, -12), Pair(0, -2), Pair(-9, 17), Pair(-3, 14), Pair(4, 13),
        Pair(-2, 18), Pair(-19, 31), Pair(-14, 10), Pair(-5, 8), Pair(-7, 3), Pair(-3, 12), Pair(-2, 15), Pair(2, 17)
      }
    }},
    {{ // Bucket 36
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-5, 25), Pair(3, 8), Pair(16, 7), Pair(-33, 19), Pair(12, 5), Pair(-18, 3), Pair(-19, 35), Pair(-20, 31),
        Pair(7, 3), Pair(11, 7), Pair(6, 3), Pair(3, 5), Pair(-12, 13), Pair(-4, 14), Pair(-4, 8), Pair(-16, 12),
        Pair(-1, 3), Pair(2, 1), Pair(5, -2), Pair(3, 4), Pair(0, 0), Pair(-1, 5), Pair(0, 6), Pair(1, 6),
        Pair(2, -1), Pair(3, -5), Pair(1, -1), Pair(1, 7), Pair(0, 0), Pair(-3, -6), Pair(1, 2), Pair(0, 3),
        Pair(2, -4), Pair(2, -2), Pair(-1, 0), Pair(0, 1), Pair(3, 1), Pair(-4, -2), Pair(-1, 2), Pair(1, 1),
        Pair(4, 0), Pair(3, -5), Pair(0, 0), Pair(-4, -7), Pair(2, 7), Pair(-5, -3), Pair(1, 6), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-54, 50), Pair(-109, 100), Pair(31, 59), Pair(65, 10), Pair(-44, 25), Pair(-44, 19), Pair(-122, 62), Pair(-21, 27),
        Pair(-7, 72), Pair(-10, 44), Pair(15, 31), Pair(25, 41), Pair(-20, 48), Pair(-59, 43), Pair(36, 28), Pair(-5, 61),
        Pair(-14, 55), Pair(2, 47), Pair(-18, 17), Pair(-1, 49), Pair(-54, 66), Pair(-11, 52), Pair(-23, 16), Pair(7, 36),
        Pair(-4, 40), Pair(0, 17), Pair(1, 45), Pair(-5, 36), Pair(0, 0), Pair(0, 44), Pair(-4, 41), Pair(-3, 31),
        Pair(0, 55), Pair(8, 13), Pair(-6, 36), Pair(-60, 4), Pair(10, 83), Pair(-15, -17), Pair(-7, 47), Pair(6, 18),
        Pair(4, 40), Pair(-12, 32), Pair(-4, 37), Pair(-8, 15), Pair(-6, 52), Pair(-10, 18), Pair(-1, 34), Pair(-7, 13),
        Pair(-12, 71), Pair(-2, 33), Pair(-10, 32), Pair(-1, 39), Pair(-21, 8), Pair(-4, 47), Pair(-5, -3), Pair(-6, 52),
        Pair(-33, 63), Pair(2, 38), Pair(-14, 41), Pair(-1, 41), Pair(-7, 28), Pair(7, 41), Pair(-5, 22), Pair(32, -23)
      },
      { // Piece 2
        Pair(-52, 70), Pair(-35, 9), Pair(-64, 69), Pair(-40, 66), Pair(-90, 89), Pair(-100, 43), Pair(58, 16), Pair(-1, 23),
        Pair(-14, 28), Pair(-12, 54), Pair(12, 44), Pair(-34, 50), Pair(-22, 34), Pair(-6, 46), Pair(82, -4), Pair(-5, 63),
        Pair(-6, 39), Pair(-33, 47), Pair(-20, 58), Pair(-24, 25), Pair(3, 40), Pair(-70, 18), Pair(-34, 60), Pair(-6, 33),
        Pair(-17, 44), Pair(-5, 50), Pair(-13, 41), Pair(-2, 49), Pair(0, 0), Pair(-16, 60), Pair(-8, 36), Pair(-16, 47),
        Pair(0, 38), Pair(-4, 29), Pair(-11, 52), Pair(-63, -14), Pair(9, 80), Pair(-21, 11), Pair(-13, 49), Pair(-16, 42),
        Pair(-1, 21), Pair(2, 37), Pair(-18, 22), Pair(-12, 31), Pair(-8, 27), Pair(-4, 25), Pair(-18, -16), Pair(-7, 40),
        Pair(-4, 47), Pair(-10, 1), Pair(-15, 41), Pair(-4, 25), Pair(1, 31), Pair(-8, 24), Pair(-5, 22), Pair(-9, -60),
        Pair(-25, -12), Pair(7, 32), Pair(1, 13), Pair(-9, 44), Pair(-2, 23), Pair(6, 33), Pair(-10, 9), Pair(9, 61)
      },
      { // Piece 3
        Pair(0, 56), Pair(51, 39), Pair(6, 49), Pair(-14, 64), Pair(-1, 35), Pair(-12, 67), Pair(-51, 67), Pair(-60, 68),
        Pair(22, 39), Pair(-5, 45), Pair(-11, 55), Pair(-8, 55), Pair(13, 46), Pair(-3, 60), Pair(-5, 57), Pair(-4, 60),
        Pair(13, 46), Pair(12, 53), Pair(-9, 56), Pair(-14, 59), Pair(18, 38), Pair(30, 45), Pair(-12, 48), Pair(8, 37),
        Pair(15, 39), Pair(5, 47), Pair(-8, 50), Pair(12, 43), Pair(0, 0), Pair(10, 40), Pair(10, 62), Pair(-1, 38),
        Pair(6, 34), Pair(3, 45), Pair(-17, 49), Pair(-53, 22), Pair(8, 37), Pair(-30, -33), Pair(-21, 51), Pair(-5, 46),
        Pair(18, 36), Pair(19, 26), Pair(4, 44), Pair(-10, 42), Pair(-4, 27), Pair(-14, 65), Pair(-1, 45), Pair(34, 10),
        Pair(5, 38), Pair(0, 44), Pair(5, 34), Pair(3, 30), Pair(-7, 24), Pair(-4, 39), Pair(16, 24), Pair(44, 6),
        Pair(5, 43), Pair(2, 39), Pair(1, 40), Pair(-5, 38), Pair(-2, 33), Pair(2, 43), Pair(5, 44), Pair(0, 47)
      },
      { // Piece 4
        Pair(-6, 110), Pair(-20, 122), Pair(-5, 142), Pair(-19, 103), Pair(-49, 140), Pair(-13, 131), Pair(29, 93), Pair(4, 57),
        Pair(31, 94), Pair(-12, 113), Pair(-3, 120), Pair(13, 87), Pair(39, 105), Pair(8, 163), Pair(10, 64), Pair(14, 104),
        Pair(9, 99), Pair(18, 73), Pair(-2, 90), Pair(18, 58), Pair(37, 75), Pair(7, 90), Pair(-3, 108), Pair(8, 95),
        Pair(-2, 98), Pair(21, 82), Pair(8, 96), Pair(19, 94), Pair(0, 0), Pair(7, 100), Pair(15, 74), Pair(19, 85),
        Pair(14, 79), Pair(9, 75), Pair(8, 108), Pair(10, 29), Pair(22, 90), Pair(76, -2), Pair(19, 85), Pair(15, 93),
        Pair(31, 87), Pair(6, 95), Pair(4, 79), Pair(5, 66), Pair(13, 66), Pair(9, 71), Pair(6, 66), Pair(22, 56),
        Pair(18, 86), Pair(13, 61), Pair(7, 85), Pair(6, 73), Pair(18, 71), Pair(22, 37), Pair(6, 73), Pair(-2, 44),
        Pair(7, 98), Pair(7, 106), Pair(3, 92), Pair(13, 73), Pair(20, 52), Pair(21, 78), Pair(5, 51), Pair(15, 71)
      },
      { // Piece 5
        Pair(-128, -63), Pair(-31, 41), Pair(-11, 18), Pair(-49, 35), Pair(38, -5), Pair(7, 50), Pair(20, -8), Pair(1, -54),
        Pair(-1, 23), Pair(9, 26), Pair(48, -2), Pair(53, -11), Pair(53, -13), Pair(2, 1), Pair(15, 0), Pair(120, -72),
        Pair(-19, 2), Pair(19, 10), Pair(-9, -3), Pair(103, -5), Pair(85, -24), Pair(177, -30), Pair(65, 1), Pair(39, -20),
        Pair(46, -11), Pair(60, -1), Pair(-27, 2), Pair(93, -53), Pair(0, 0), Pair(86, -58), Pair(82, -15), Pair(38, 14),
        Pair(-27, -7), Pair(-26, 24), Pair(-6, -4), Pair(73, -60), Pair(18, -48), Pair(7, -59), Pair(21, 1), Pair(18, 7),
        Pair(10, 17), Pair(10, 18), Pair(30, -14), Pair(76, -31), Pair(35, -24), Pair(58, -23), Pair(-8, 11), Pair(6, 18),
        Pair(-6, 20), Pair(14, 9), Pair(-1, 13), Pair(32, -9), Pair(16, -9), Pair(21, -3), Pair(-9, 22), Pair(0, 21),
        Pair(22, 0), Pair(0, 16), Pair(-4, 22), Pair(22, 4), Pair(7, 2), Pair(18, 2), Pair(-3, 21), Pair(4, 21)
      }
    }},
    {{ // Bucket 37
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(21, 6), Pair(-7, 15), Pair(-2, 16), Pair(10, 7), Pair(-1, 5), Pair(-5, -10), Pair(-19, 24), Pair(26, 2),
        Pair(-2, 7), Pair(7, 3), Pair(16, 2), Pair(13, -4), Pair(4, -1), Pair(0, 4), Pair(-1, 13), Pair(-5, 4),
        Pair(6, 0), Pair(4, -2), Pair(3, 3), Pair(1, -5), Pair(2, 2), Pair(0, 0), Pair(2, -1), Pair(-1, 5),
        Pair(6, -2), Pair(2, -4), Pair(4, -4), Pair(2, -4), Pair(3, 5), Pair(0, 0), Pair(-2, -1), Pair(2, 0),
        Pair(2, -3), Pair(6, -3), Pair(1, -3), Pair(6, -4), Pair(-1, 1), Pair(3, 1), Pair(-3, -4), Pair(1, 0),
        Pair(2, -4), Pair(3, -6), Pair(3, -6), Pair(0, -2), Pair(0, -3), Pair(8, 0), Pair(0, -5), Pair(1, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-28, 53), Pair(39, 16), Pair(-28, 58), Pair(-59, 43), Pair(16, 11), Pair(-14, 40), Pair(48, 15), Pair(-12, 84),
        Pair(-9, 46), Pair(-26, 37), Pair(-19, 46), Pair(3, 27), Pair(-67, 57), Pair(17, 42), Pair(-5, 30), Pair(15, 19),
        Pair(31, 28), Pair(17, 8), Pair(27, 29), Pair(18, 2), Pair(-9, 42), Pair(6, 33), Pair(-7, 38), Pair(-12, -11),
        Pair(24, 17), Pair(3, 26), Pair(-4, 32), Pair(14, 32), Pair(5, 38), Pair(0, 0), Pair(-10, 28), Pair(-8, 42),
        Pair(14, 31), Pair(18, 22), Pair(3, 30), Pair(10, 26), Pair(-51, -24), Pair(8, 68), Pair(-15, -31), Pair(2, 35),
        Pair(2, 29), Pair(5, 24), Pair(-2, 30), Pair(0, 39), Pair(-10, 24), Pair(11, 34), Pair(-14, 17), Pair(10, 20),
        Pair(2, 37), Pair(4, 37), Pair(4, 32), Pair(-6, 23), Pair(0, 39), Pair(-13, 13), Pair(14, 26), Pair(-11, -8),
        Pair(6, 20), Pair(-1, 31), Pair(0, 28), Pair(1, 32), Pair(-1, 40), Pair(-4, 26), Pair(0, 59), Pair(-9, 28)
      },
      { // Piece 2
        Pair(-60, 56), Pair(22, 38), Pair(14, 21), Pair(16, 22), Pair(-52, 72), Pair(-93, 69), Pair(-57, 46), Pair(70, 17),
        Pair(-6, 16), Pair(-3, 36), Pair(-1, 34), Pair(-49, 53), Pair(-46, 52), Pair(-20, 72), Pair(17, 46), Pair(-51, 28),
        Pair(-11, 36), Pair(-10, 38), Pair(-9, 43), Pair(7, 29), Pair(7, 44), Pair(-4, 43), Pair(-46, 30), Pair(-11, 51),
        Pair(10, 27), Pair(-13, 46), Pair(4, 35), Pair(-9, 42), Pair(0, 33), Pair(0, 0), Pair(-3, 42), Pair(-14, 37),
        Pair(3, 31), Pair(9, 30), Pair(-1, 33), Pair(5, 31), Pair(-83, -30), Pair(10, 65), Pair(-16, -28), Pair(-6, 29),
        Pair(3, 33), Pair(0, 32), Pair(1, 29), Pair(-7, 19), Pair(-6, 21), Pair(-5, 28), Pair(-10, 23), Pair(-30, -5),
        Pair(0, 38), Pair(7, 33), Pair(-16, 18), Pair(4, 32), Pair(-3, 19), Pair(0, 36), Pair(-11, 16), Pair(3, 17),
        Pair(6, 19), Pair(-37, 22), Pair(8, 28), Pair(10, 14), Pair(-1, 32), Pair(-2, 24), Pair(-32, 45), Pair(-2, 11)
      },
      { // Piece 3
        Pair(-1, 50), Pair(-3, 49), Pair(10, 39), Pair(5, 39), Pair(-5, 50), Pair(5, 42), Pair(-30, 52), Pair(29, 42),
        Pair(24, 25), Pair(7, 35), Pair(8, 36), Pair(5, 35), Pair(5, 44), Pair(12, 58), Pair(48, 30), Pair(14, 37),
        Pair(42, 16), Pair(7, 43), Pair(22, 30), Pair(19, 30), Pair(37, 21), Pair(83, 21), Pair(5, 29), Pair(-14, 40),
        Pair(13, 30), Pair(19, 29), Pair(3, 37), Pair(18, 30), Pair(27, 24), Pair(0, 0), Pair(21, 25), Pair(-2, 35),
        Pair(4, 34), Pair(5, 34), Pair(-1, 26), Pair(-7, 42), Pair(-28, -25), Pair(27, 26), Pair(23, -42), Pair(6, 37),
        Pair(3, 35), Pair(-3, 39), Pair(0, 15), Pair(2, 30), Pair(11, 24), Pair(2, 32), Pair(-5, 30), Pair(-2, 20),
        Pair(6, 34), Pair(3, 31), Pair(9, 26), Pair(14, 28), Pair(8, 20), Pair(9, 28), Pair(24, 31), Pair(18, 34),
        Pair(9, 35), Pair(8, 33), Pair(9, 35), Pair(7, 34), Pair(6, 33), Pair(2, 31), Pair(13, 29), Pair(1, 40)
      },
      { // Piece 4
        Pair(40, 40), Pair(34, 60), Pair(39, 8), Pair(16, 89), Pair(30, 80), Pair(11, 63), Pair(86, 53), Pair(57, 48),
        Pair(6, 73), Pair(-7, 60), Pair(36, 50), Pair(40, 60), Pair(-9, 83), Pair(5, 78), Pair(-22, 95), Pair(9, 73),
        Pair(27, 37), Pair(12, 74), Pair(13, 67), Pair(34, 73), Pair(15, 40), Pair(46, 54), Pair(-8, 30), Pair(6, 73),
        Pair(23, 42), Pair(12, 72), Pair(21, 61), Pair(34, 45), Pair(16, 54), Pair(0, 0), Pair(11, 67), Pair(6, 36),
        Pair(2, 42), Pair(1, 81), Pair(21, 37), Pair(13, 60), Pair(5, 32), Pair(31, 30), Pair(29, 7), Pair(9, 65),
        Pair(20, 58), Pair(8, 76), Pair(6, 56), Pair(0, 70), Pair(9, 51), Pair(16, 41), Pair(17, 39), Pair(7, 8),
        Pair(21, 63), Pair(4, 69), Pair(8, 59), Pair(8, 58), Pair(8, 57), Pair(17, 43), Pair(2, 59), Pair(13, 79),
        Pair(21, 39), Pair(25, 23), Pair(4, 50), Pair(12, 41), Pair(19, 55), Pair(16, -3), Pair(-7, 35), Pair(4, 50)
      },
      { // Piece 5
        Pair(108, -42), Pair(-4, -74), Pair(-78, 31), Pair(23, -48), Pair(-11, -15), Pair(49, -55), Pair(-123, -23), Pair(-83, -26),
        Pair(-78, 14), Pair(-16, 0), Pair(44, -10), Pair(-83, -19), Pair(58, -35), Pair(-59, -21), Pair(39, 7), Pair(-77, 23),
        Pair(-4, -2), Pair(120, -43), Pair(-62, 2), Pair(81, -26), Pair(-1, -8), Pair(173, -29), Pair(-5, 5), Pair(25, -7),
        Pair(-77, 4), Pair(-45, 10), Pair(95, -7), Pair(-28, -3), Pair(44, -46), Pair(0, 0), Pair(105, -49), Pair(27, -9),
        Pair(41, -16), Pair(74, -12), Pair(71, -8), Pair(6, -7), Pair(35, -44), Pair(-32, -34), Pair(-73, -72), Pair(-26, 24),
        Pair(57, -24), Pair(68, -22), Pair(34, -7), Pair(35, -3), Pair(38, -12), Pair(39, -11), Pair(13, -4), Pair(-48, 23),
        Pair(8, -7), Pair(-3, 3), Pair(35, -3), Pair(15, 7), Pair(0, 1), Pair(-6, 7), Pair(3, 8), Pair(-5, 26),
        Pair(4, 1), Pair(-14, 19), Pair(-5, 25), Pair(10, 14), Pair(-1, 6), Pair(-1, 6), Pair(-3, 9), Pair(-2, 23)
      }
    }},
    {{ // Bucket 38
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(28, 4), Pair(15, 9), Pair(44, -3), Pair(-3, 20), Pair(-11, 19), Pair(-17, 23), Pair(-3, 26), Pair(-24, 28),
        Pair(7, 6), Pair(2, 6), Pair(8, 9), Pair(10, 3), Pair(11, -1), Pair(-18, 8), Pair(15, 12), Pair(-4, 8),
        Pair(4, 3), Pair(3, -3), Pair(2, 1), Pair(-1, 1), Pair(-4, 2), Pair(-3, 6), Pair(0, 0), Pair(-1, 13),
        Pair(5, -4), Pair(5, -2), Pair(-2, 1), Pair(-4, -1), Pair(-3, -3), Pair(3, 2), Pair(0, 0), Pair(6, 5),
        Pair(2, -4), Pair(2, -6), Pair(-1, -2), Pair(0, -3), Pair(-3, 1), Pair(1, 3), Pair(-5, 5), Pair(-2, 2),
        Pair(2, -6), Pair(2, -5), Pair(0, -4), Pair(1, 0), Pair(-4, -1), Pair(1, 0), Pair(3, 2), Pair(-2, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, -21), Pair(-58, 50), Pair(-97, 55), Pair(-109, 61), Pair(29, 12), Pair(-71, 58), Pair(18, 45), Pair(-25, -53),
        Pair(50, 3), Pair(-32, 31), Pair(7, 14), Pair(29, 28), Pair(61, 5), Pair(34, -1), Pair(-49, 61), Pair(3, 4),
        Pair(2, 23), Pair(5, 36), Pair(34, 29), Pair(16, 27), Pair(17, 22), Pair(44, 20), Pair(-24, 21), Pair(34, 24),
        Pair(5, 11), Pair(14, 17), Pair(24, 32), Pair(15, 21), Pair(31, 31), Pair(26, 36), Pair(0, 0), Pair(-4, 25),
        Pair(9, 19), Pair(-2, 17), Pair(13, 18), Pair(16, 23), Pair(16, 21), Pair(-19, 7), Pair(28, 52), Pair(-38, -17),
        Pair(6, 2), Pair(-4, 33), Pair(2, 29), Pair(-3, 36), Pair(14, 22), Pair(3, 13), Pair(-4, 39), Pair(-31, 28),
        Pair(-9, 7), Pair(-5, 14), Pair(-7, 21), Pair(-1, 34), Pair(-15, 21), Pair(0, 43), Pair(-16, -13), Pair(18, 39),
        Pair(-47, 11), Pair(-4, 35), Pair(6, 25), Pair(11, 21), Pair(1, 17), Pair(-3, 46), Pair(-10, 35), Pair(-51, 63)
      },
      { // Piece 2
        Pair(-25, 57), Pair(-85, 66), Pair(-87, 86), Pair(-129, 65), Pair(-51, 66), Pair(-137, 56), Pair(78, 23), Pair(-6, 38),
        Pair(-15, 53), Pair(22, 35), Pair(-21, 55), Pair(-53, 72), Pair(-24, 54), Pair(-15, 58), Pair(9, 56), Pair(23, 23),
        Pair(-23, 52), Pair(-47, 62), Pair(-1, 52), Pair(-19, 51), Pair(-4, 45), Pair(-46, 50), Pair(2, 28), Pair(-51, 10),
        Pair(-12, 47), Pair(-3, 34), Pair(-6, 46), Pair(-3, 47), Pair(-12, 36), Pair(-16, 54), Pair(0, 0), Pair(-15, 54),
        Pair(2, 38), Pair(-4, 37), Pair(6, 30), Pair(3, 32), Pair(0, 34), Pair(-15, -8), Pair(7, 71), Pair(-55, -45),
        Pair(-4, 32), Pair(25, 36), Pair(13, 35), Pair(-4, 40), Pair(-7, 28), Pair(3, 35), Pair(-8, 22), Pair(8, 12),
        Pair(2, 34), Pair(11, 29), Pair(1, 30), Pair(-12, 26), Pair(-1, 31), Pair(-9, 39), Pair(18, 22), Pair(4, -18),
        Pair(14, 22), Pair(7, 16), Pair(-12, 10), Pair(-1, 34), Pair(-16, 26), Pair(6, 37), Pair(-5, 59), Pair(-4, 47)
      },
      { // Piece 3
        Pair(13, 55), Pair(8, 56), Pair(4, 56), Pair(43, 33), Pair(-3, 49), Pair(-54, 52), Pair(23, 49), Pair(-12, 64),
        Pair(23, 28), Pair(31, 27), Pair(1, 43), Pair(19, 38), Pair(1, 52), Pair(17, 48), Pair(123, 23), Pair(-13, 41),
        Pair(8, 38), Pair(13, 37), Pair(39, 30), Pair(37, 31), Pair(32, 27), Pair(10, 29), Pair(16, 45), Pair(-13, 44),
        Pair(28, 31), Pair(23, 34), Pair(19, 31), Pair(8, 39), Pair(45, 22), Pair(15, 33), Pair(0, 0), Pair(-33, 43),
        Pair(16, 22), Pair(5, 39), Pair(17, 37), Pair(21, 18), Pair(11, 31), Pair(0, -4), Pair(-1, 27), Pair(-34, -16),
        Pair(14, 23), Pair(16, 28), Pair(2, 39), Pair(22, 30), Pair(25, 16), Pair(3, 37), Pair(-6, 28), Pair(-42, 43),
        Pair(15, 40), Pair(12, 29), Pair(30, 29), Pair(14, 31), Pair(19, 20), Pair(17, 30), Pair(-5, 27), Pair(-3, 8),
        Pair(14, 38), Pair(13, 39), Pair(13, 38), Pair(18, 31), Pair(15, 28), Pair(14, 30), Pair(0, 34), Pair(6, 28)
      },
      { // Piece 4
        Pair(20, 35), Pair(59, 9), Pair(1, 40), Pair(24, 2), Pair(-61, 110), Pair(13, 88), Pair(19, 52), Pair(9, 48),
        Pair(31, 43), Pair(17, 60), Pair(60, 8), Pair(-26, 74), Pair(-22, 86), Pair(57, 33), Pair(-74, 125), Pair(35, 29),
        Pair(38, 30), Pair(42, 26), Pair(10, 72), Pair(32, 32), Pair(12, 50), Pair(-4, 31), Pair(3, 68), Pair(-55, 68),
        Pair(25, 18), Pair(21, 45), Pair(33, 14), Pair(29, 28), Pair(9, 80), Pair(-16, 57), Pair(0, 0), Pair(2, 37),
        Pair(9, 21), Pair(10, 38), Pair(3, 74), Pair(8, 67), Pair(0, 51), Pair(-7, 0), Pair(1, 55), Pair(46, 27),
        Pair(-6, 91), Pair(9, 52), Pair(-9, 95), Pair(-5, 62), Pair(10, 44), Pair(7, 58), Pair(3, 74), Pair(-34, 94),
        Pair(21, 51), Pair(13, 59), Pair(13, 42), Pair(6, 28), Pair(-2, 66), Pair(12, 44), Pair(-5, 30), Pair(8, 94),
        Pair(-19, 107), Pair(22, 17), Pair(26, -18), Pair(16, 14), Pair(19, 35), Pair(12, 61), Pair(-39, 35), Pair(-10, 45)
      },
      { // Piece 5
        Pair(-25, -4), Pair(-12, -53), Pair(84, -37), Pair(99, -53), Pair(47, -9), Pair(-12, -54), Pair(-52, -48), Pair(-33, -224),
        Pair(66, -41), Pair(10, -17), Pair(171, -74), Pair(148, -47), Pair(231, -71), Pair(76, -60), Pair(72, -52), Pair(40, -104),
        Pair(118, -57), Pair(30, -28), Pair(83, -35), Pair(51, -21), Pair(-12, -8), Pair(16, -11), Pair(200, -33), Pair(26, 1),
        Pair(75, -14), Pair(30, -22), Pair(85, -10), Pair(21, -8), Pair(48, -15), Pair(44, -35), Pair(0, 0), Pair(9, -44),
        Pair(90, -53), Pair(63, -23), Pair(3, -11), Pair(66, -13), Pair(-11, -9), Pair(-129, -52), Pair(-20, -50), Pair(-223, -78),
        Pair(93, -33), Pair(49, -30), Pair(38, -17), Pair(22, -11), Pair(-3, -6), Pair(44, -20), Pair(4, -12), Pair(-11, -17),
        Pair(3, -11), Pair(-29, -15), Pair(-14, -8), Pair(34, -12), Pair(-20, 7), Pair(18, 0), Pair(-13, 4), Pair(-8, 4),
        Pair(-12, -7), Pair(-22, -16), Pair(2, -24), Pair(4, -8), Pair(0, 2), Pair(-3, 3), Pair(-5, 1), Pair(-6, -7)
      }
    }},
    {{ // Bucket 39
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(9, 5), Pair(11, 8), Pair(47, -7), Pair(0, 12), Pair(41, 1), Pair(16, 7), Pair(21, 8), Pair(-64, 69),
        Pair(9, 8), Pair(-6, 5), Pair(1, 11), Pair(3, 1), Pair(1, 4), Pair(2, 1), Pair(-1, 6), Pair(37, -30),
        Pair(4, -2), Pair(4, 0), Pair(7, -1), Pair(2, -2), Pair(-5, -2), Pair(-9, 5), Pair(-10, -1), Pair(0, 0),
        Pair(5, -3), Pair(4, -3), Pair(4, -3), Pair(-2, -3), Pair(1, -3), Pair(-2, -1), Pair(-6, -5), Pair(0, 0),
        Pair(4, -5), Pair(3, -8), Pair(0, -5), Pair(0, -3), Pair(3, -4), Pair(3, -2), Pair(-2, -6), Pair(5, 1),
        Pair(3, -4), Pair(3, -6), Pair(-1, -7), Pair(4, -8), Pair(2, -7), Pair(3, -2), Pair(-1, -5), Pair(3, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-27, -31), Pair(-76, 37), Pair(-46, 9), Pair(76, -24), Pair(-44, 19), Pair(-47, 58), Pair(40, 5), Pair(-44, 60),
        Pair(-21, 9), Pair(-6, 11), Pair(39, 5), Pair(-2, 27), Pair(35, 22), Pair(13, 31), Pair(22, -1), Pair(25, 68),
        Pair(65, -13), Pair(20, 8), Pair(6, 22), Pair(40, 13), Pair(45, 22), Pair(2, 35), Pair(19, 20), Pair(-21, 17),
        Pair(-7, 23), Pair(12, 10), Pair(18, 22), Pair(21, 18), Pair(26, 14), Pair(27, 26), Pair(1, 32), Pair(0, 0),
        Pair(1, 11), Pair(12, 0), Pair(11, 13), Pair(17, 17), Pair(18, 21), Pair(20, 27), Pair(-5, -42), Pair(28, 55),
        Pair(-2, 27), Pair(5, 18), Pair(9, 9), Pair(4, 24), Pair(-2, 22), Pair(8, 27), Pair(4, 24), Pair(20, 6),
        Pair(20, -34), Pair(1, 18), Pair(-13, 13), Pair(1, 19), Pair(6, 21), Pair(4, 15), Pair(18, 3), Pair(0, -19),
        Pair(48, -62), Pair(-3, -11), Pair(-6, 17), Pair(-8, 28), Pair(-3, 23), Pair(7, 14), Pair(-3, 42), Pair(-6, -10)
      },
      { // Piece 2
        Pair(-20, 60), Pair(3, 34), Pair(-67, 71), Pair(-36, 52), Pair(-58, 75), Pair(-39, 32), Pair(-33, 61), Pair(-1, 29),
        Pair(-27, 56), Pair(-3, 56), Pair(-33, 51), Pair(-28, 64), Pair(-72, 65), Pair(-14, 66), Pair(-7, 48), Pair(-3, 82),
        Pair(-2, 44), Pair(-9, 32), Pair(-27, 59), Pair(1, 42), Pair(0, 51), Pair(-39, 46), Pair(-16, 63), Pair(3, 37),
        Pair(-5, 27), Pair(4, 43), Pair(-10, 35), Pair(12, 43), Pair(6, 41), Pair(15, 40), Pair(-4, 34), Pair(0, 0),
        Pair(-17, 37), Pair(5, 21), Pair(9, 38), Pair(2, 28), Pair(14, 42), Pair(4, 30), Pair(4, -52), Pair(9, 65),
        Pair(-9, 26), Pair(5, 38), Pair(5, 30), Pair(6, 44), Pair(3, 19), Pair(2, 40), Pair(-6, 35), Pair(12, 39),
        Pair(-3, 26), Pair(-3, 32), Pair(18, 23), Pair(-6, 29), Pair(2, 30), Pair(7, 26), Pair(14, 33), Pair(7, 14),
        Pair(5, 30), Pair(-1, 22), Pair(0, 23), Pair(13, 30), Pair(18, 21), Pair(3, 34), Pair(-20, 21), Pair(5, 80)
      },
      { // Piece 3
        Pair(28, 45), Pair(-2, 51), Pair(20, 48), Pair(-10, 56), Pair(6, 54), Pair(-24, 60), Pair(-7, 64), Pair(65, 55),
        Pair(28, 37), Pair(20, 40), Pair(31, 37), Pair(34, 39), Pair(11, 47), Pair(-11, 64), Pair(77, 23), Pair(133, 36),
        Pair(25, 34), Pair(18, 42), Pair(10, 48), Pair(14, 42), Pair(25, 29), Pair(-19, 58), Pair(-10, 37), Pair(47, 67),
        Pair(20, 44), Pair(12, 46), Pair(10, 42), Pair(5, 49), Pair(2, 42), Pair(33, 42), Pair(14, 55), Pair(0, 0),
        Pair(13, 38), Pair(-4, 49), Pair(13, 45), Pair(13, 38), Pair(-3, 35), Pair(1, 52), Pair(70, -52), Pair(-11, 56),
        Pair(5, 38), Pair(8, 40), Pair(13, 37), Pair(10, 33), Pair(9, 37), Pair(-3, 49), Pair(-3, 49), Pair(-21, 28),
        Pair(6, 43), Pair(8, 36), Pair(19, 34), Pair(4, 31), Pair(15, 29), Pair(4, 42), Pair(-5, 61), Pair(9, 18),
        Pair(10, 42), Pair(3, 48), Pair(10, 40), Pair(4, 41), Pair(12, 39), Pair(14, 30), Pair(-7, 58), Pair(-3, 43)
      },
      { // Piece 4
        Pair(-17, 36), Pair(20, 38), Pair(21, 38), Pair(13, 29), Pair(-5, 67), Pair(83, 27), Pair(5, 51), Pair(22, 51),
        Pair(9, 80), Pair(21, 52), Pair(11, 47), Pair(-39, 81), Pair(7, 82), Pair(28, 103), Pair(-45, 87), Pair(37, 69),
        Pair(48, 32), Pair(1, 63), Pair(1, 82), Pair(30, 75), Pair(2, 92), Pair(5, 74), Pair(-14, 100), Pair(21, 68),
        Pair(37, 35), Pair(11, 61), Pair(15, 59), Pair(9, 72), Pair(21, 59), Pair(31, 64), Pair(17, 59), Pair(0, 0),
        Pair(15, 67), Pair(7, 61), Pair(30, 32), Pair(17, 48), Pair(25, 57), Pair(27, 38), Pair(39, 23), Pair(13, 47),
        Pair(15, 12), Pair(13, 42), Pair(6, 51), Pair(4, 68), Pair(0, 71), Pair(4, 67), Pair(5, 42), Pair(-16, 66),
        Pair(12, 23), Pair(6, 24), Pair(17, 23), Pair(11, 28), Pair(13, 37), Pair(13, 38), Pair(29, 23), Pair(-11, 63),
        Pair(2, 13), Pair(-16, 49), Pair(15, 29), Pair(9, 39), Pair(15, 55), Pair(6, 89), Pair(-31, 78), Pair(-27, 65)
      },
      { // Piece 5
        Pair(-12, -14), Pair(87, -20), Pair(218, -53), Pair(-72, -16), Pair(16, -69), Pair(62, -44), Pair(-31, -16), Pair(38, 121),
        Pair(41, -36), Pair(42, 3), Pair(-20, -30), Pair(-42, -33), Pair(-100, -36), Pair(47, -47), Pair(22, -45), Pair(20, -19),
        Pair(-10, -31), Pair(126, -24), Pair(91, -28), Pair(33, -19), Pair(59, -27), Pair(132, -20), Pair(35, 5), Pair(8, 6),
        Pair(90, -18), Pair(86, -23), Pair(71, -18), Pair(57, -21), Pair(25, -3), Pair(-51, 8), Pair(37, -36), Pair(0, 0),
        Pair(42, -37), Pair(67, -38), Pair(77, -27), Pair(49, -11), Pair(48, -8), Pair(6, 1), Pair(-250, -24), Pair(106, -61),
        Pair(35, -9), Pair(38, -29), Pair(26, -17), Pair(40, -11), Pair(24, 0), Pair(-16, 3), Pair(31, 3), Pair(43, -3),
        Pair(-2, -16), Pair(4, -6), Pair(10, -12), Pair(5, -3), Pair(10, 2), Pair(-13, 17), Pair(5, 8), Pair(5, 3),
        Pair(-21, -3), Pair(-20, -3), Pair(-8, -5), Pair(15, 2), Pair(-10, 10), Pair(-6, 20), Pair(0, 7), Pair(-8, 4)
      }
    }},
    {{ // Bucket 40
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(87, -63), Pair(0, 19), Pair(5, 19), Pair(4, 18), Pair(8, 17), Pair(-9, 3), Pair(-8, 15), Pair(-10, 21),
        Pair(0, 0), Pair(-8, 4), Pair(-8, 4), Pair(1, 8), Pair(-2, 14), Pair(-5, 15), Pair(-2, 20), Pair(-2, 15),
        Pair(-8, -12), Pair(-5, 2), Pair(-3, -2), Pair(0, 3), Pair(-2, 5), Pair(-5, 7), Pair(-1, 9), Pair(-2, 14),
        Pair(-2, -5), Pair(-4, -2), Pair(-1, -1), Pair(-2, 1), Pair(-2, 2), Pair(-1, 4), Pair(-2, 5), Pair(-3, 5),
        Pair(0, 0), Pair(-3, 0), Pair(0, 0), Pair(0, -1), Pair(-1, 4), Pair(-6, 1), Pair(-4, -1), Pair(-3, 0),
        Pair(7, -5), Pair(0, -2), Pair(-1, 0), Pair(-3, -6), Pair(-1, -1), Pair(-5, -2), Pair(-3, -3), Pair(-4, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-3, 35), Pair(27, 67), Pair(-25, 46), Pair(121, 5), Pair(62, 19), Pair(-24, 47), Pair(133, 17), Pair(19, 5),
        Pair(-3, 2), Pair(29, 30), Pair(-14, 21), Pair(-2, 45), Pair(11, 39), Pair(57, 10), Pair(13, 25), Pair(32, 24),
        Pair(0, 0), Pair(6, 36), Pair(10, 39), Pair(10, 35), Pair(23, 39), Pair(56, 25), Pair(36, 20), Pair(53, 30),
        Pair(10, 73), Pair(-33, -40), Pair(4, 49), Pair(18, 34), Pair(20, 28), Pair(20, 32), Pair(31, 18), Pair(31, 34),
        Pair(10, 53), Pair(5, 32), Pair(10, 30), Pair(1, 37), Pair(12, 31), Pair(16, 29), Pair(24, 30), Pair(19, 22),
        Pair(-18, 0), Pair(4, 36), Pair(-8, 31), Pair(1, 34), Pair(7, 27), Pair(9, 24), Pair(15, 25), Pair(19, 17),
        Pair(23, 36), Pair(-1, 61), Pair(-4, 33), Pair(6, 24), Pair(7, 25), Pair(19, 14), Pair(-3, 44), Pair(3, 28),
        Pair(-90, 40), Pair(1, 22), Pair(-4, 23), Pair(9, 22), Pair(4, 26), Pair(8, 23), Pair(-2, 52), Pair(-26, 77)
      },
      { // Piece 2
        Pair(5, 62), Pair(-31, 61), Pair(30, 58), Pair(-53, 76), Pair(-58, 49), Pair(-66, 99), Pair(-2, 90), Pair(4, 18),
        Pair(1, 75), Pair(-6, 67), Pair(-2, 67), Pair(-54, 73), Pair(-23, 79), Pair(25, 54), Pair(27, 46), Pair(-4, 52),
        Pair(0, 0), Pair(-13, 56), Pair(-33, 82), Pair(-4, 59), Pair(-5, 70), Pair(-8, 79), Pair(11, 57), Pair(39, 34),
        Pair(25, 73), Pair(-13, -34), Pair(-2, 57), Pair(-1, 60), Pair(7, 62), Pair(8, 40), Pair(8, 47), Pair(7, 43),
        Pair(-8, 71), Pair(-17, 40), Pair(-6, 61), Pair(-4, 57), Pair(8, 49), Pair(7, 56), Pair(-18, 57), Pair(11, 52),
        Pair(-1, 70), Pair(2, 39), Pair(1, 52), Pair(-1, 42), Pair(2, 47), Pair(-5, 43), Pair(9, 31), Pair(2, 66),
        Pair(-16, 100), Pair(5, 57), Pair(0, 60), Pair(1, 51), Pair(-4, 47), Pair(-5, 58), Pair(7, 43), Pair(9, 20),
        Pair(8, 72), Pair(-5, 54), Pair(4, 53), Pair(-7, 50), Pair(5, 44), Pair(-2, 39), Pair(-4, 67), Pair(14, 90)
      },
      { // Piece 3
        Pair(19, 100), Pair(0, 97), Pair(-7, 100), Pair(-25, 96), Pair(9, 92), Pair(6, 79), Pair(52, 90), Pair(9, 98),
        Pair(17, 101), Pair(-12, 90), Pair(-7, 96), Pair(10, 89), Pair(-16, 104), Pair(15, 84), Pair(11, 82), Pair(-8, 99),
        Pair(0, 0), Pair(4, 103), Pair(5, 112), Pair(-2, 91), Pair(-3, 110), Pair(28, 86), Pair(-4, 89), Pair(2, 88),
        Pair(-16, 97), Pair(6, -71), Pair(-12, 97), Pair(3, 80), Pair(-22, 98), Pair(2, 82), Pair(6, 75), Pair(31, 77),
        Pair(-16, 75), Pair(-15, 83), Pair(-23, 91), Pair(-13, 85), Pair(-2, 78), Pair(-11, 82), Pair(-11, 90), Pair(27, 50),
        Pair(-23, 77), Pair(-14, 77), Pair(-32, 92), Pair(-8, 77), Pair(-14, 79), Pair(-6, 88), Pair(0, 86), Pair(13, 81),
        Pair(-15, 74), Pair(1, 68), Pair(-3, 85), Pair(-10, 67), Pair(-13, 78), Pair(4, 75), Pair(5, 101), Pair(-7, 90),
        Pair(-12, 71), Pair(-11, 79), Pair(-9, 77), Pair(-6, 79), Pair(-4, 74), Pair(-5, 78), Pair(4, 85), Pair(-2, 79)
      },
      { // Piece 4
        Pair(-52, 200), Pair(0, 181), Pair(-17, 198), Pair(-30, 182), Pair(-6, 176), Pair(-17, 187), Pair(67, 141), Pair(23, 169),
        Pair(46, 123), Pair(36, 137), Pair(9, 153), Pair(14, 160), Pair(28, 183), Pair(24, 136), Pair(28, 187), Pair(31, 170),
        Pair(0, 0), Pair(27, 164), Pair(6, 201), Pair(21, 169), Pair(34, 181), Pair(62, 130), Pair(45, 143), Pair(51, 125),
        Pair(32, 146), Pair(14, 12), Pair(27, 126), Pair(17, 159), Pair(5, 169), Pair(16, 176), Pair(37, 136), Pair(46, 107),
        Pair(13, 152), Pair(17, 100), Pair(27, 119), Pair(18, 140), Pair(22, 137), Pair(24, 123), Pair(24, 133), Pair(21, 160),
        Pair(12, 154), Pair(10, 119), Pair(15, 141), Pair(16, 129), Pair(6, 138), Pair(23, 120), Pair(26, 108), Pair(39, 137),
        Pair(18, 101), Pair(19, 109), Pair(15, 119), Pair(17, 123), Pair(21, 119), Pair(18, 117), Pair(10, 145), Pair(44, 148),
        Pair(19, 143), Pair(17, 120), Pair(6, 144), Pair(13, 126), Pair(5, 127), Pair(2, 105), Pair(32, 87), Pair(33, 72)
      },
      { // Piece 5
        Pair(-8, 48), Pair(37, 50), Pair(92, -80), Pair(113, 40), Pair(-5, -35), Pair(57, -81), Pair(44, -11), Pair(-41, -18),
        Pair(-46, -40), Pair(-45, 15), Pair(77, -19), Pair(86, -17), Pair(-53, 14), Pair(3, 5), Pair(-64, 36), Pair(-84, 27),
        Pair(0, 0), Pair(-56, -39), Pair(-24, 21), Pair(55, 8), Pair(0, 0), Pair(55, 1), Pair(-36, 20), Pair(-24, 29),
        Pair(-30, -92), Pair(-62, -60), Pair(-115, 28), Pair(71, 7), Pair(-13, -6), Pair(-37, 12), Pair(17, -4), Pair(23, 3),
        Pair(29, -53), Pair(1, -12), Pair(-42, 0), Pair(7, -2), Pair(-5, 10), Pair(20, 0), Pair(10, 6), Pair(53, -14),
        Pair(-55, -3), Pair(-19, -14), Pair(-18, -6), Pair(0, 5), Pair(8, -2), Pair(19, -6), Pair(-2, -1), Pair(22, 0),
        Pair(-6, -6), Pair(-21, -6), Pair(7, 11), Pair(15, 3), Pair(21, 1), Pair(4, 3), Pair(-1, -1), Pair(-2, 3),
        Pair(-18, 3), Pair(9, 6), Pair(8, 5), Pair(3, 13), Pair(3, -7), Pair(4, -1), Pair(-3, -2), Pair(-1, -5)
      }
    }},
    {{ // Bucket 41
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(9, 6), Pair(-7, 47), Pair(7, -6), Pair(5, 11), Pair(10, 7), Pair(30, 8), Pair(34, 1), Pair(-6, 31),
        Pair(-1, 7), Pair(0, 0), Pair(-3, 5), Pair(7, -1), Pair(-5, 19), Pair(6, 10), Pair(3, 15), Pair(0, 17),
        Pair(4, 8), Pair(-9, -14), Pair(-10, 30), Pair(-1, 5), Pair(3, 5), Pair(-4, 9), Pair(0, 8), Pair(0, 10),
        Pair(4, 3), Pair(-4, -5), Pair(1, 7), Pair(-1, 5), Pair(-1, 3), Pair(-4, 8), Pair(-3, 5), Pair(-4, 7),
        Pair(0, -1), Pair(0, 0), Pair(0, 3), Pair(0, 3), Pair(-2, 2), Pair(-5, 1), Pair(-6, 3), Pair(-3, 3),
        Pair(-1, -1), Pair(3, -1), Pair(0, 1), Pair(-3, 0), Pair(0, -1), Pair(-7, -2), Pair(-8, -2), Pair(-3, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-86, 21), Pair(-18, -27), Pair(-57, 19), Pair(15, 5), Pair(-2, 27), Pair(200, -7), Pair(63, -24), Pair(-5, 60),
        Pair(-3, 48), Pair(-60, -6), Pair(-4, 39), Pair(7, 35), Pair(43, 25), Pair(29, 44), Pair(-17, 31), Pair(30, 52),
        Pair(-27, 25), Pair(0, 0), Pair(0, 50), Pair(18, 40), Pair(13, 30), Pair(29, 33), Pair(41, 30), Pair(18, 43),
        Pair(-20, 25), Pair(1, 66), Pair(-42, 2), Pair(2, 29), Pair(8, 44), Pair(10, 45), Pair(14, 39), Pair(27, 39),
        Pair(-22, 20), Pair(2, 42), Pair(-24, 40), Pair(3, 43), Pair(1, 39), Pair(3, 34), Pair(19, 41), Pair(16, 33),
        Pair(5, 41), Pair(-20, 10), Pair(-2, 40), Pair(-14, 41), Pair(0, 44), Pair(2, 38), Pair(9, 31), Pair(6, 33),
        Pair(4, 22), Pair(-8, 49), Pair(6, 33), Pair(-1, 34), Pair(4, 35), Pair(1, 36), Pair(6, 37), Pair(9, 25),
        Pair(24, 57), Pair(8, 57), Pair(0, 31), Pair(9, 30), Pair(-16, 46), Pair(5, 49), Pair(7, 44), Pair(7, 39)
      },
      { // Piece 2
        Pair(-2, 71), Pair(-30, 40), Pair(-83, 78), Pair(-45, 70), Pair(-66, 94), Pair(-97, 47), Pair(45, 78), Pair(-26, 82),
        Pair(-141, 24), Pair(-22, 65), Pair(-13, 59), Pair(-53, 85), Pair(-17, 64), Pair(7, 72), Pair(-29, 64), Pair(28, 67),
        Pair(2, 50), Pair(0, 0), Pair(-11, 60), Pair(11, 53), Pair(-9, 70), Pair(4, 65), Pair(-5, 66), Pair(12, 42),
        Pair(-46, -64), Pair(-2, 77), Pair(-106, -18), Pair(-4, 56), Pair(3, 56), Pair(-5, 69), Pair(6, 60), Pair(5, 45),
        Pair(-18, 54), Pair(-10, 43), Pair(-24, 68), Pair(-16, 51), Pair(0, 51), Pair(-3, 45), Pair(6, 52), Pair(14, 49),
        Pair(-3, 31), Pair(-6, 55), Pair(-1, 43), Pair(-3, 52), Pair(-6, 39), Pair(-7, 54), Pair(6, 34), Pair(13, 43),
        Pair(-7, 63), Pair(4, 42), Pair(4, 53), Pair(-5, 45), Pair(-1, 41), Pair(-15, 40), Pair(4, 44), Pair(5, 30),
        Pair(1, 52), Pair(19, 54), Pair(0, 51), Pair(-8, 53), Pair(-13, 54), Pair(3, 45), Pair(0, 11), Pair(-3, 59)
      },
      { // Piece 3
        Pair(-22, 77), Pair(5, 69), Pair(-22, 76), Pair(7, 62), Pair(27, 62), Pair(13, 57), Pair(17, 71), Pair(7, 65),
        Pair(-8, 67), Pair(17, 68), Pair(-13, 67), Pair(-10, 71), Pair(7, 71), Pair(26, 60), Pair(18, 61), Pair(23, 59),
        Pair(2, 61), Pair(0, 0), Pair(0, 74), Pair(12, 66), Pair(-1, 74), Pair(15, 72), Pair(-10, 62), Pair(0, 68),
        Pair(-10, -29), Pair(-16, 57), Pair(20, -1), Pair(-11, 66), Pair(0, 61), Pair(2, 60), Pair(-4, 66), Pair(6, 47),
        Pair(-12, 48), Pair(-25, 48), Pair(-21, 67), Pair(-17, 60), Pair(-8, 46), Pair(-5, 67), Pair(1, 64), Pair(20, 50),
        Pair(-22, 64), Pair(-18, 53), Pair(-16, 60), Pair(-13, 59), Pair(-8, 63), Pair(5, 50), Pair(7, 51), Pair(2, 55),
        Pair(-3, 41), Pair(-8, 47), Pair(-11, 52), Pair(-6, 55), Pair(-15, 57), Pair(-2, 55), Pair(-1, 60), Pair(-7, 61),
        Pair(-13, 61), Pair(-12, 49), Pair(-13, 55), Pair(-10, 64), Pair(-7, 63), Pair(-6, 67), Pair(6, 58), Pair(5, 65)
      },
      { // Piece 4
        Pair(56, 75), Pair(-4, 108), Pair(-13, 122), Pair(52, 115), Pair(3, 123), Pair(44, 112), Pair(-15, 175), Pair(41, 71),
        Pair(33, 57), Pair(-17, 140), Pair(4, 128), Pair(42, 74), Pair(27, 111), Pair(29, 117), Pair(-17, 121), Pair(40, 69),
        Pair(43, 52), Pair(0, 0), Pair(15, 112), Pair(39, 114), Pair(35, 101), Pair(50, 111), Pair(35, 83), Pair(46, 87),
        Pair(-8, 223), Pair(30, 85), Pair(-10, 162), Pair(11, 108), Pair(11, 104), Pair(44, 99), Pair(30, 109), Pair(35, 98),
        Pair(9, 86), Pair(9, 109), Pair(13, 90), Pair(12, 101), Pair(26, 100), Pair(29, 79), Pair(31, 105), Pair(44, 101),
        Pair(18, 88), Pair(13, 107), Pair(17, 88), Pair(11, 94), Pair(27, 86), Pair(12, 110), Pair(21, 103), Pair(27, 103),
        Pair(14, 100), Pair(12, 107), Pair(14, 103), Pair(18, 89), Pair(14, 87), Pair(23, 73), Pair(4, 102), Pair(27, 56),
        Pair(11, 93), Pair(19, 85), Pair(16, 87), Pair(17, 93), Pair(17, 90), Pair(11, 103), Pair(22, 62), Pair(23, 137)
      },
      { // Piece 5
        Pair(-39, -316), Pair(-43, -45), Pair(-16, 12), Pair(-11, 35), Pair(91, 27), Pair(43, -22), Pair(-31, 71), Pair(34, -110),
        Pair(22, -48), Pair(63, -20), Pair(57, -67), Pair(111, -41), Pair(-213, 68), Pair(-38, -1), Pair(-40, 13), Pair(-39, 13),
        Pair(-92, -40), Pair(0, 0), Pair(15, -42), Pair(159, -34), Pair(0, -12), Pair(18, -17), Pair(30, 0), Pair(12, -12),
        Pair(2, 5), Pair(77, -92), Pair(4, 57), Pair(0, -18), Pair(-14, 21), Pair(25, -6), Pair(37, -3), Pair(29, -19),
        Pair(101, -53), Pair(-10, -62), Pair(30, -37), Pair(25, -20), Pair(21, -8), Pair(-1, 9), Pair(-23, 10), Pair(19, 4),
        Pair(40, -20), Pair(20, -39), Pair(12, -21), Pair(3, -1), Pair(19, -4), Pair(2, 2), Pair(10, -3), Pair(25, 6),
        Pair(-6, 4), Pair(-6, -17), Pair(-1, 2), Pair(1, 3), Pair(14, -2), Pair(5, 0), Pair(8, -4), Pair(4, 1),
        Pair(9, 12), Pair(14, -8), Pair(27, -13), Pair(19, -7), Pair(1, 8), Pair(2, -1), Pair(3, -4), Pair(-1, -3)
      }
    }},
    {{ // Bucket 42
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-28, 19), Pair(24, 13), Pair(-8, 5), Pair(8, -20), Pair(23, -3), Pair(10, 10), Pair(-14, 33), Pair(6, 34),
        Pair(3, 5), Pair(-11, 7), Pair(0, 0), Pair(2, -1), Pair(2, 5), Pair(0, 5), Pair(-3, 17), Pair(-4, 9),
        Pair(-2, 1), Pair(-4, 3), Pair(-10, -12), Pair(1, 32), Pair(2, 1), Pair(4, 7), Pair(-2, 6), Pair(2, 9),
        Pair(2, 0), Pair(2, -6), Pair(-4, -5), Pair(0, 5), Pair(0, 1), Pair(-1, 4), Pair(2, 3), Pair(-1, 5),
        Pair(0, 1), Pair(0, -3), Pair(0, 0), Pair(2, 2), Pair(-1, 1), Pair(-6, 3), Pair(-1, 0), Pair(-3, 2),
        Pair(1, 0), Pair(-3, -8), Pair(4, 1), Pair(-3, 2), Pair(0, 0), Pair(-5, -1), Pair(-1, 2), Pair(0, 4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-38, 39), Pair(77, 25), Pair(11, 12), Pair(-17, 87), Pair(48, -23), Pair(122, -9), Pair(58, 15), Pair(9, -33),
        Pair(-12, -34), Pair(-27, 46), Pair(11, 10), Pair(24, 59), Pair(31, 8), Pair(14, 67), Pair(27, 10), Pair(32, 56),
        Pair(25, 64), Pair(-15, 31), Pair(0, 0), Pair(10, 49), Pair(7, 52), Pair(10, 33), Pair(9, 37), Pair(25, 20),
        Pair(-8, 64), Pair(-16, -31), Pair(16, 64), Pair(-37, 8), Pair(12, 38), Pair(1, 45), Pair(14, 47), Pair(10, 33),
        Pair(6, 41), Pair(-11, 28), Pair(6, 43), Pair(-12, 37), Pair(11, 36), Pair(0, 25), Pair(5, 49), Pair(15, 12),
        Pair(-5, 11), Pair(3, 44), Pair(-10, 22), Pair(3, 44), Pair(-18, 38), Pair(9, 42), Pair(5, 41), Pair(10, 56),
        Pair(15, 33), Pair(-13, 57), Pair(0, 28), Pair(8, 39), Pair(5, 32), Pair(3, 39), Pair(10, 36), Pair(14, 10),
        Pair(53, 4), Pair(2, 20), Pair(6, 19), Pair(13, 28), Pair(6, 32), Pair(7, 27), Pair(7, 24), Pair(46, 28)
      },
      { // Piece 2
        Pair(-111, -60), Pair(-43, 59), Pair(27, 7), Pair(14, 59), Pair(40, 12), Pair(-4, 52), Pair(65, 0), Pair(63, 55),
        Pair(1, 59), Pair(-53, 6), Pair(14, 22), Pair(-3, 55), Pair(14, 44), Pair(-28, 69), Pair(4, 54), Pair(-44, 80),
        Pair(-21, 53), Pair(-18, 59), Pair(0, 0), Pair(-7, 53), Pair(-2, 37), Pair(9, 64), Pair(15, 53), Pair(10, 34),
        Pair(0, 36), Pair(-19, -61), Pair(10, 73), Pair(-43, -39), Pair(-3, 59), Pair(-12, 36), Pair(0, 50), Pair(4, 29),
        Pair(-16, 22), Pair(-13, 54), Pair(-6, 29), Pair(-20, 50), Pair(-5, 25), Pair(7, 49), Pair(1, 38), Pair(20, 18),
        Pair(5, 32), Pair(-3, 29), Pair(6, 48), Pair(2, 26), Pair(4, 45), Pair(-2, 25), Pair(8, 49), Pair(6, 29),
        Pair(-21, 57), Pair(10, 34), Pair(6, 40), Pair(8, 38), Pair(0, 26), Pair(8, 41), Pair(-3, 11), Pair(18, 31),
        Pair(10, 44), Pair(1, 43), Pair(13, 36), Pair(-22, 53), Pair(3, 43), Pair(6, 22), Pair(-9, 48), Pair(17, 14)
      },
      { // Piece 3
        Pair(19, 44), Pair(13, 53), Pair(-19, 59), Pair(-8, 56), Pair(62, 28), Pair(4, 55), Pair(21, 53), Pair(-63, 71),
        Pair(5, 46), Pair(-7, 47), Pair(-10, 58), Pair(32, 43), Pair(27, 49), Pair(-14, 67), Pair(23, 45), Pair(40, 32),
        Pair(3, 53), Pair(-15, 59), Pair(0, 0), Pair(-8, 56), Pair(24, 56), Pair(14, 58), Pair(8, 54), Pair(-14, 45),
        Pair(0, 40), Pair(84, -13), Pair(-10, 48), Pair(-13, -9), Pair(-5, 41), Pair(-7, 43), Pair(6, 56), Pair(2, 42),
        Pair(-6, 48), Pair(2, 37), Pair(-21, 60), Pair(-11, 52), Pair(-8, 46), Pair(-11, 51), Pair(1, 45), Pair(35, 26),
        Pair(-3, 34), Pair(-5, 47), Pair(-10, 40), Pair(-11, 52), Pair(14, 34), Pair(-11, 56), Pair(16, 38), Pair(3, 53),
        Pair(15, 27), Pair(4, 45), Pair(-5, 38), Pair(0, 31), Pair(8, 34), Pair(3, 44), Pair(15, 43), Pair(-8, 44),
        Pair(-2, 45), Pair(-5, 42), Pair(-3, 36), Pair(-4, 38), Pair(2, 43), Pair(3, 42), Pair(11, 36), Pair(13, 44)
      },
      { // Piece 4
        Pair(74, 12), Pair(-24, 126), Pair(35, 57), Pair(-29, 144), Pair(14, 63), Pair(-26, 86), Pair(64, 59), Pair(12, 60),
        Pair(33, 47), Pair(16, 67), Pair(6, 68), Pair(24, 105), Pair(24, 104), Pair(58, 65), Pair(8, 99), Pair(35, 65),
        Pair(20, 51), Pair(0, 75), Pair(0, 0), Pair(19, 74), Pair(28, 120), Pair(2, 109), Pair(34, 108), Pair(34, 94),
        Pair(20, 84), Pair(-11, 167), Pair(46, 36), Pair(-2, 194), Pair(14, 82), Pair(26, 66), Pair(10, 126), Pair(13, 95),
        Pair(19, 57), Pair(17, 51), Pair(23, 64), Pair(10, 73), Pair(19, 60), Pair(23, 71), Pair(19, 78), Pair(26, 73),
        Pair(20, 60), Pair(11, 60), Pair(25, 71), Pair(9, 80), Pair(23, 59), Pair(20, 55), Pair(21, 64), Pair(17, 83),
        Pair(24, 50), Pair(11, 65), Pair(20, 71), Pair(12, 70), Pair(12, 78), Pair(14, 57), Pair(14, 59), Pair(57, 70),
        Pair(-2, 69), Pair(16, 64), Pair(20, 65), Pair(13, 68), Pair(9, 74), Pair(38, 44), Pair(8, 91), Pair(4, 70)
      },
      { // Piece 5
        Pair(0, 31), Pair(12, 21), Pair(-124, -80), Pair(2, -97), Pair(52, -9), Pair(22, 4), Pair(-15, -46), Pair(53, -55),
        Pair(13, -37), Pair(27, -36), Pair(73, -48), Pair(131, -20), Pair(-5, 13), Pair(59, 20), Pair(18, 6), Pair(-64, 12),
        Pair(-100, -30), Pair(-33, -48), Pair(0, 0), Pair(190, -91), Pair(93, -13), Pair(24, 25), Pair(-97, 14), Pair(-51, 21),
        Pair(31, 0), Pair(1, 14), Pair(0, -62), Pair(-3, -12), Pair(-124, 12), Pair(9, 18), Pair(77, -5), Pair(27, -21),
        Pair(-14, -8), Pair(48, -19), Pair(51, -40), Pair(69, -29), Pair(22, -13), Pair(-39, 15), Pair(10, 6), Pair(-23, 6),
        Pair(71, -21), Pair(-2, -5), Pair(-52, -6), Pair(1, -11), Pair(-23, 15), Pair(-3, 3), Pair(-8, 9), Pair(18, -9),
        Pair(-2, 10), Pair(-31, 9), Pair(-10, -3), Pair(9, -8), Pair(2, 11), Pair(8, 7), Pair(7, 7), Pair(3, 8),
        Pair(12, 21), Pair(-6, 6), Pair(-3, 8), Pair(8, 4), Pair(-2, 14), Pair(15, 3), Pair(-1, 8), Pair(7, 4)
      }
    }},
    {{ // Bucket 43
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-25, 31), Pair(13, 19), Pair(18, 1), Pair(7, -11), Pair(-13, 1), Pair(-58, 37), Pair(21, -7), Pair(7, 12),
        Pair(-4, 11), Pair(11, 0), Pair(3, 6), Pair(0, 0), Pair(5, -5), Pair(9, 1), Pair(3, 6), Pair(-10, 11),
        Pair(-4, 8), Pair(0, 0), Pair(-4, -1), Pair(-12, -12), Pair(-8, 17), Pair(-3, 6), Pair(0, 7), Pair(-2, 10),
        Pair(-1, 3), Pair(-1, -4), Pair(1, -2), Pair(-6, -8), Pair(0, 0), Pair(-6, 3), Pair(1, 4), Pair(-1, 5),
        Pair(-1, -1), Pair(0, -2), Pair(-3, -3), Pair(0, 0), Pair(-1, 0), Pair(-3, 0), Pair(-4, 2), Pair(0, 4),
        Pair(0, -1), Pair(-2, -7), Pair(-4, -6), Pair(1, 0), Pair(-1, -7), Pair(-2, -2), Pair(0, -1), Pair(1, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-53, 80), Pair(38, 4), Pair(-103, 45), Pair(-51, 85), Pair(2, 25), Pair(-48, 47), Pair(-97, 14), Pair(-4, -77),
        Pair(1, 61), Pair(8, 9), Pair(12, 35), Pair(-34, 15), Pair(-43, 72), Pair(-63, 26), Pair(-24, 54), Pair(-15, 13),
        Pair(-3, 24), Pair(-3, 36), Pair(-32, 49), Pair(0, 0), Pair(-7, 39), Pair(-38, 70), Pair(-9, 38), Pair(9, 58),
        Pair(-9, 41), Pair(-4, 30), Pair(-67, 55), Pair(-4, 73), Pair(-77, 79), Pair(-16, 45), Pair(-3, 43), Pair(5, 29),
        Pair(-7, -8), Pair(-3, 41), Pair(-21, 14), Pair(1, 38), Pair(-12, 30), Pair(1, 45), Pair(-15, 24), Pair(-3, 61),
        Pair(5, 13), Pair(-14, 12), Pair(-3, 40), Pair(-25, 22), Pair(-8, 44), Pair(-13, 24), Pair(4, 40), Pair(2, 29),
        Pair(35, 31), Pair(6, 41), Pair(9, 17), Pair(-4, 28), Pair(5, 33), Pair(-11, 30), Pair(5, 30), Pair(2, 34),
        Pair(-19, 42), Pair(4, 30), Pair(8, 1), Pair(-11, 35), Pair(0, 33), Pair(3, 13), Pair(-6, 35), Pair(-34, 107)
      },
      { // Piece 2
        Pair(-32, 53), Pair(-52, 31), Pair(-47, 54), Pair(6, 42), Pair(-102, 72), Pair(-36, 44), Pair(-28, 62), Pair(3, 53),
        Pair(-11, 30), Pair(-21, 57), Pair(-54, -10), Pair(-82, 78), Pair(-68, 63), Pair(-20, 62), Pair(-18, 59), Pair(18, 44),
        Pair(-7, 57), Pair(-35, 41), Pair(-7, 45), Pair(0, 0), Pair(-9, 40), Pair(-12, 38), Pair(-44, 76), Pair(4, 26),
        Pair(-14, 27), Pair(-19, 58), Pair(-80, -62), Pair(-5, 83), Pair(-5, -82), Pair(-22, 48), Pair(-3, 32), Pair(-6, 48),
        Pair(-17, 51), Pair(-15, 17), Pair(-26, 41), Pair(-8, 45), Pair(-19, 33), Pair(-11, 14), Pair(-9, 46), Pair(1, 23),
        Pair(-3, 13), Pair(-17, 38), Pair(-11, 27), Pair(-2, 39), Pair(-5, 20), Pair(-4, 30), Pair(-7, -3), Pair(-1, 30),
        Pair(-21, 34), Pair(-4, 16), Pair(-13, 41), Pair(-4, 22), Pair(-7, 37), Pair(2, 4), Pair(0, 22), Pair(-11, -10),
        Pair(-24, 37), Pair(9, 28), Pair(1, 28), Pair(-9, 33), Pair(-12, 33), Pair(0, 33), Pair(-30, 65), Pair(15, 33)
      },
      { // Piece 3
        Pair(2, 50), Pair(-22, 40), Pair(48, 16), Pair(32, 13), Pair(0, 47), Pair(23, 30), Pair(3, 44), Pair(4, 41),
        Pair(-6, 38), Pair(-6, 48), Pair(5, 29), Pair(-38, 64), Pair(-6, 52), Pair(49, 21), Pair(5, 35), Pair(-25, 47),
        Pair(2, 26), Pair(-23, 53), Pair(-15, 53), Pair(0, 0), Pair(-9, 42), Pair(55, 28), Pair(-18, 37), Pair(25, 36),
        Pair(-7, 26), Pair(-7, 24), Pair(10, -84), Pair(-6, 38), Pair(-146, 103), Pair(-22, 46), Pair(-1, 31), Pair(-11, 54),
        Pair(-15, 26), Pair(2, 18), Pair(-7, 19), Pair(-1, 18), Pair(-16, 37), Pair(-24, 52), Pair(-1, 36), Pair(8, 39),
        Pair(-4, 51), Pair(4, 23), Pair(-2, 29), Pair(5, 19), Pair(-6, 31), Pair(1, 38), Pair(-1, 30), Pair(11, 36),
        Pair(12, 18), Pair(-5, 17), Pair(-4, 25), Pair(-5, 19), Pair(-15, 26), Pair(2, 31), Pair(-2, 30), Pair(38, 32),
        Pair(-6, 33), Pair(-4, 33), Pair(-10, 34), Pair(-10, 34), Pair(-4, 26), Pair(-3, 36), Pair(9, 22), Pair(8, 40)
      },
      { // Piece 4
        Pair(11, 76), Pair(20, 14), Pair(41, 78), Pair(-11, 97), Pair(34, 63), Pair(-96, 166), Pair(22, 39), Pair(50, 42),
        Pair(5, 81), Pair(15, 59), Pair(11, 47), Pair(-20, 90), Pair(4, 76), Pair(34, 84), Pair(-12, 129), Pair(-12, 111),
        Pair(16, 72), Pair(5, 46), Pair(-6, 68), Pair(0, 0), Pair(5, 86), Pair(-6, 94), Pair(0, 74), Pair(17, 66),
        Pair(20, 54), Pair(18, 51), Pair(46, -5), Pair(36, 40), Pair(-49, -24), Pair(23, 75), Pair(10, 94), Pair(22, 70),
        Pair(4, 73), Pair(4, 82), Pair(16, 41), Pair(24, 50), Pair(1, 90), Pair(29, 10), Pair(14, 72), Pair(13, 96),
        Pair(11, 49), Pair(4, 72), Pair(4, 72), Pair(18, 66), Pair(13, 52), Pair(-1, 75), Pair(16, 35), Pair(-7, 121),
        Pair(3, 68), Pair(4, 80), Pair(8, 53), Pair(18, 60), Pair(7, 57), Pair(-4, 85), Pair(1, 53), Pair(48, -5),
        Pair(12, 51), Pair(18, 54), Pair(7, 70), Pair(16, 54), Pair(13, 32), Pair(-2, 68), Pair(24, 32), Pair(61, 53)
      },
      { // Piece 5
        Pair(23, -1), Pair(-95, -54), Pair(-11, -119), Pair(27, -50), Pair(28, -51), Pair(-31, -67), Pair(-5, -28), Pair(25, -54),
        Pair(28, 59), Pair(29, -23), Pair(199, -46), Pair(-43, -72), Pair(-49, -35), Pair(41, 6), Pair(84, -26), Pair(40, -58),
        Pair(31, 15), Pair(-47, 19), Pair(83, -78), Pair(0, 0), Pair(98, -69), Pair(136, -2), Pair(-2, 14), Pair(69, -1),
        Pair(-13, -31), Pair(32, 3), Pair(-3, -22), Pair(78, -96), Pair(2, 11), Pair(-56, 13), Pair(79, -10), Pair(40, -8),
        Pair(-29, -18), Pair(-20, 2), Pair(33, -42), Pair(20, -57), Pair(19, -41), Pair(-11, -11), Pair(-62, 27), Pair(-37, 3),
        Pair(-62, 25), Pair(-19, -2), Pair(4, -18), Pair(-8, -22), Pair(-6, -9), Pair(-8, 1), Pair(12, -3), Pair(52, -15),
        Pair(-16, 43), Pair(-26, 12), Pair(-31, 14), Pair(-1, -14), Pair(-11, -9), Pair(-7, 11), Pair(2, 8), Pair(7, 10),
        Pair(-36, 30), Pair(-19, 28), Pair(0, 0), Pair(-20, -2), Pair(-1, -11), Pair(-2, 11), Pair(-2, 16), Pair(-1, 8)
      }
    }},
    {{ // Bucket 44
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-3, 16), Pair(15, 6), Pair(8, 6), Pair(-16, 11), Pair(14, 0), Pair(26, -5), Pair(-17, 18), Pair(-12, 23),
        Pair(2, 5), Pair(6, 13), Pair(2, 3), Pair(0, 2), Pair(0, 0), Pair(1, 13), Pair(-5, 5), Pair(-8, 11),
        Pair(0, 2), Pair(1, 3), Pair(1, 2), Pair(3, 26), Pair(-9, -6), Pair(4, -3), Pair(4, 3), Pair(0, 6),
        Pair(3, -3), Pair(3, -4), Pair(2, 1), Pair(3, 5), Pair(-2, 1), Pair(-1, 1), Pair(4, 2), Pair(-3, 4),
        Pair(3, 0), Pair(3, -1), Pair(0, 1), Pair(2, 0), Pair(0, 0), Pair(-1, 2), Pair(-1, 1), Pair(-4, 2),
        Pair(1, 0), Pair(2, -1), Pair(0, 1), Pair(2, -5), Pair(3, -2), Pair(-2, -3), Pair(-2, -1), Pair(-1, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-30, 8), Pair(-9, 39), Pair(39, 15), Pair(-58, 53), Pair(49, 11), Pair(-8, 6), Pair(-115, 1), Pair(38, 37),
        Pair(-2, 38), Pair(9, 57), Pair(1, -11), Pair(-23, 48), Pair(-90, 51), Pair(-49, 55), Pair(-44, -42), Pair(-25, 44),
        Pair(11, 23), Pair(-3, 9), Pair(-20, 43), Pair(-12, 31), Pair(0, 0), Pair(-14, 52), Pair(-8, 33), Pair(-40, 24),
        Pair(-6, 37), Pair(-9, 24), Pair(7, 19), Pair(-78, 17), Pair(-6, 70), Pair(-96, -2), Pair(5, 14), Pair(-12, 28),
        Pair(-3, 34), Pair(-17, 23), Pair(-8, 42), Pair(-28, 24), Pair(-12, 41), Pair(-23, 5), Pair(-14, 43), Pair(-4, 7),
        Pair(-3, 33), Pair(-6, 30), Pair(-16, 23), Pair(-10, 32), Pair(-32, 28), Pair(-7, 37), Pair(-13, 12), Pair(1, 20),
        Pair(6, 38), Pair(4, 38), Pair(-7, 22), Pair(-3, 35), Pair(-14, 19), Pair(-8, 32), Pair(-5, 23), Pair(-10, 26),
        Pair(3, 55), Pair(-2, 20), Pair(9, 6), Pair(-9, 20), Pair(-2, 22), Pair(2, 18), Pair(-7, 44), Pair(9, 3)
      },
      { // Piece 2
        Pair(-51, 25), Pair(-8, 43), Pair(-23, 12), Pair(-72, 68), Pair(18, 29), Pair(5, 49), Pair(2, 13), Pair(27, 24),
        Pair(1, 31), Pair(-29, 31), Pair(20, 44), Pair(-65, 43), Pair(-10, 54), Pair(-91, 36), Pair(5, 20), Pair(-29, 15),
        Pair(-15, 18), Pair(2, 43), Pair(-39, 39), Pair(-4, 43), Pair(0, 0), Pair(-14, 48), Pair(-36, 42), Pair(-8, 37),
        Pair(-5, 43), Pair(-19, 36), Pair(6, 43), Pair(-177, -60), Pair(-5, 75), Pair(-108, -17), Pair(-7, 37), Pair(-15, 27),
        Pair(-28, 31), Pair(12, 20), Pair(-33, 33), Pair(-24, 31), Pair(-23, 26), Pair(-7, 35), Pair(-23, 25), Pair(-5, 46),
        Pair(3, 40), Pair(-15, 12), Pair(-3, 35), Pair(-15, 24), Pair(-3, 38), Pair(-16, 18), Pair(-5, 37), Pair(-23, -1),
        Pair(-36, 9), Pair(1, 34), Pair(-15, 27), Pair(4, 33), Pair(-14, 19), Pair(-8, 44), Pair(-20, 11), Pair(-3, 19),
        Pair(-3, 21), Pair(-13, 15), Pair(7, 32), Pair(-26, 23), Pair(-3, 30), Pair(-10, 16), Pair(-1, 56), Pair(-6, 8)
      },
      { // Piece 3
        Pair(13, 41), Pair(-3, 45), Pair(4, 32), Pair(-57, 53), Pair(29, 28), Pair(10, 22), Pair(-2, 21), Pair(-3, 32),
        Pair(15, 34), Pair(2, 36), Pair(12, 34), Pair(-11, 35), Pair(-7, 48), Pair(-7, 26), Pair(-19, 39), Pair(2, 33),
        Pair(-5, 32), Pair(-10, 40), Pair(-3, 45), Pair(-17, 43), Pair(0, 0), Pair(14, 32), Pair(-3, 30), Pair(5, 14),
        Pair(0, 29), Pair(7, 20), Pair(0, 35), Pair(-50, -6), Pair(15, 14), Pair(33, -58), Pair(7, 21), Pair(-7, 28),
        Pair(4, 36), Pair(-8, 42), Pair(3, 30), Pair(-15, 30), Pair(-2, 10), Pair(-43, 54), Pair(-18, 29), Pair(0, 26),
        Pair(0, 24), Pair(12, 24), Pair(-6, 39), Pair(2, 24), Pair(7, 15), Pair(1, 13), Pair(3, 28), Pair(8, 29),
        Pair(-5, 29), Pair(-3, 28), Pair(4, 33), Pair(2, 14), Pair(3, 10), Pair(-1, 18), Pair(-10, 48), Pair(19, 8),
        Pair(-1, 33), Pair(-4, 35), Pair(-1, 31), Pair(-4, 19), Pair(1, 19), Pair(-2, 28), Pair(-7, 40), Pair(2, 35)
      },
      { // Piece 4
        Pair(2, 69), Pair(0, 87), Pair(5, 28), Pair(6, 79), Pair(40, 49), Pair(73, 79), Pair(72, 35), Pair(34, 43),
        Pair(30, 71), Pair(-7, 111), Pair(18, 89), Pair(-2, 56), Pair(18, 64), Pair(-6, 89), Pair(0, 73), Pair(14, 79),
        Pair(22, 75), Pair(35, 45), Pair(1, 59), Pair(24, 26), Pair(0, 0), Pair(-27, 82), Pair(31, 65), Pair(26, 75),
        Pair(20, 60), Pair(22, 74), Pair(12, 66), Pair(-2, -9), Pair(30, 62), Pair(96, -19), Pair(26, 54), Pair(14, 96),
        Pair(14, 81), Pair(12, 65), Pair(18, 69), Pair(5, 58), Pair(21, 47), Pair(10, 93), Pair(14, 49), Pair(26, 65),
        Pair(5, 110), Pair(11, 65), Pair(4, 78), Pair(10, 56), Pair(26, 61), Pair(9, 62), Pair(16, 50), Pair(31, 24),
        Pair(33, 36), Pair(9, 69), Pair(9, 73), Pair(8, 67), Pair(26, 51), Pair(17, 59), Pair(5, 73), Pair(34, 66),
        Pair(9, 84), Pair(14, 59), Pair(13, 70), Pair(14, 59), Pair(19, 40), Pair(14, 71), Pair(11, 73), Pair(-7, 67)
      },
      { // Piece 5
        Pair(-17, 19), Pair(9, -14), Pair(55, -28), Pair(69, -34), Pair(2, -69), Pair(-22, -66), Pair(-95, -16), Pair(-41, -12),
        Pair(97, 20), Pair(118, -3), Pair(1, 3), Pair(6, -26), Pair(55, -34), Pair(110, -66), Pair(-30, 0), Pair(-179, 21),
        Pair(-24, -11), Pair(156, -31), Pair(110, -20), Pair(41, -72), Pair(0, 0), Pair(100, -65), Pair(21, -7), Pair(35, -11),
        Pair(99, -7), Pair(76, 6), Pair(3, -1), Pair(5, 34), Pair(22, -71), Pair(-2, -49), Pair(6, -1), Pair(20, 11),
        Pair(20, -12), Pair(32, 3), Pair(10, 0), Pair(29, -30), Pair(8, -28), Pair(54, -34), Pair(-21, 6), Pair(8, 15),
        Pair(95, -13), Pair(32, 2), Pair(-14, 11), Pair(27, -10), Pair(3, -7), Pair(26, -8), Pair(-12, 15), Pair(-3, 11),
        Pair(-7, 29), Pair(-5, 20), Pair(-10, 26), Pair(3, -4), Pair(12, -3), Pair(8, 4), Pair(5, 19), Pair(2, 13),
        Pair(-7, 17), Pair(1, 13), Pair(-4, 24), Pair(16, 6), Pair(0, 1), Pair(17, 5), Pair(2, 19), Pair(6, 14)
      }
    }},
    {{ // Bucket 45
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(4, 22), Pair(6, 15), Pair(26, 13), Pair(-8, 16), Pair(-28, 9), Pair(-17, -15), Pair(16, 19), Pair(-29, 15),
        Pair(3, 5), Pair(10, 4), Pair(22, 0), Pair(7, -2), Pair(16, -2), Pair(0, 0), Pair(1, -5), Pair(-1, 7),
        Pair(5, 3), Pair(7, 0), Pair(10, 0), Pair(6, -4), Pair(7, 24), Pair(-16, -3), Pair(1, 3), Pair(-1, 3),
        Pair(6, 0), Pair(7, -4), Pair(7, -1), Pair(3, 0), Pair(3, 2), Pair(-1, 0), Pair(-2, -1), Pair(-1, 3),
        Pair(5, -1), Pair(6, 0), Pair(6, -1), Pair(4, 1), Pair(2, -1), Pair(0, 0), Pair(-4, -5), Pair(-4, 1),
        Pair(4, -1), Pair(5, -3), Pair(6, -4), Pair(3, -3), Pair(3, 0), Pair(5, -2), Pair(-1, -6), Pair(-3, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(36, -17), Pair(1, 57), Pair(19, 48), Pair(-29, 59), Pair(41, 30), Pair(66, 21), Pair(-143, 100), Pair(-21, 73),
        Pair(-27, 46), Pair(45, 2), Pair(33, 44), Pair(-13, 1), Pair(34, 32), Pair(-32, 22), Pair(-27, 64), Pair(-29, -35),
        Pair(30, 23), Pair(11, 36), Pair(4, 49), Pair(39, 36), Pair(24, 23), Pair(0, 0), Pair(11, 5), Pair(24, 63),
        Pair(28, 28), Pair(-1, 39), Pair(23, 27), Pair(31, 22), Pair(-8, -39), Pair(41, 54), Pair(7, -28), Pair(39, 18),
        Pair(23, 25), Pair(34, 37), Pair(15, 21), Pair(20, 38), Pair(-7, 39), Pair(21, 37), Pair(10, 13), Pair(13, 42),
        Pair(8, 38), Pair(15, 35), Pair(19, 35), Pair(3, 29), Pair(11, 42), Pair(4, 18), Pair(17, 36), Pair(-8, 22),
        Pair(33, 31), Pair(6, 42), Pair(24, 35), Pair(16, 22), Pair(7, 44), Pair(9, 23), Pair(38, 26), Pair(3, 48),
        Pair(32, 10), Pair(12, 43), Pair(-2, 29), Pair(26, 32), Pair(-3, 38), Pair(6, 35), Pair(2, 50), Pair(-13, 31)
      },
      { // Piece 2
        Pair(21, 95), Pair(2, 29), Pair(19, 55), Pair(-32, 5), Pair(-16, 55), Pair(-1, 46), Pair(-15, 25), Pair(-163, -21),
        Pair(30, 15), Pair(0, 53), Pair(13, 28), Pair(-4, 59), Pair(-37, 47), Pair(23, 63), Pair(-71, 4), Pair(-1, 55),
        Pair(39, 27), Pair(-2, 33), Pair(17, 44), Pair(0, 36), Pair(4, 49), Pair(0, 0), Pair(6, 42), Pair(-10, 32),
        Pair(4, 34), Pair(8, 35), Pair(-4, 46), Pair(10, 41), Pair(-7, -24), Pair(11, 70), Pair(-1, -13), Pair(11, 47),
        Pair(13, 46), Pair(6, 22), Pair(20, 40), Pair(8, 32), Pair(-2, 30), Pair(6, 22), Pair(10, 44), Pair(-4, 5),
        Pair(-1, 39), Pair(25, 42), Pair(7, 19), Pair(19, 33), Pair(1, 23), Pair(17, 36), Pair(-11, 23), Pair(23, 31),
        Pair(21, 50), Pair(8, 11), Pair(3, 49), Pair(2, 23), Pair(16, 36), Pair(3, 30), Pair(20, 33), Pair(-10, 12),
        Pair(-26, 42), Pair(26, 28), Pair(8, 23), Pair(15, 45), Pair(-9, 39), Pair(15, 50), Pair(1, 33), Pair(-4, 59)
      },
      { // Piece 3
        Pair(19, 38), Pair(-4, 54), Pair(31, 36), Pair(24, 44), Pair(36, 32), Pair(35, 42), Pair(-26, 41), Pair(26, 42),
        Pair(19, 39), Pair(14, 46), Pair(32, 35), Pair(40, 28), Pair(41, 27), Pair(19, 53), Pair(43, 13), Pair(70, 21),
        Pair(20, 23), Pair(5, 44), Pair(38, 26), Pair(24, 38), Pair(-2, 38), Pair(0, 0), Pair(18, 12), Pair(4, 42),
        Pair(20, 30), Pair(18, 36), Pair(12, 33), Pair(-3, 39), Pair(-8, -6), Pair(41, 25), Pair(25, -36), Pair(-7, 36),
        Pair(3, 41), Pair(12, 30), Pair(12, 32), Pair(-5, 41), Pair(10, 29), Pair(14, 32), Pair(11, 42), Pair(7, 47),
        Pair(5, 41), Pair(13, 40), Pair(1, 35), Pair(12, 34), Pair(8, 28), Pair(5, 40), Pair(25, 27), Pair(-8, 54),
        Pair(24, 34), Pair(-3, 52), Pair(21, 23), Pair(27, 27), Pair(18, 23), Pair(24, 31), Pair(9, 32), Pair(5, 32),
        Pair(14, 47), Pair(14, 44), Pair(14, 40), Pair(11, 36), Pair(14, 33), Pair(13, 38), Pair(15, 32), Pair(16, 42)
      },
      { // Piece 4
        Pair(16, 70), Pair(21, 68), Pair(12, 69), Pair(87, -15), Pair(-16, 93), Pair(38, 33), Pair(3, 129), Pair(75, -17),
        Pair(22, 67), Pair(20, 58), Pair(53, 62), Pair(38, 100), Pair(28, 56), Pair(22, 95), Pair(67, 39), Pair(54, 55),
        Pair(24, 69), Pair(17, 59), Pair(17, 51), Pair(61, 19), Pair(35, 22), Pair(0, 0), Pair(45, 24), Pair(39, -4),
        Pair(28, 47), Pair(33, 58), Pair(39, 74), Pair(23, 83), Pair(57, -37), Pair(63, -5), Pair(9, 85), Pair(27, 71),
        Pair(20, 53), Pair(33, 67), Pair(33, 51), Pair(22, 72), Pair(16, 68), Pair(38, 37), Pair(21, 71), Pair(37, 22),
        Pair(27, 66), Pair(22, 55), Pair(30, 46), Pair(16, 81), Pair(17, 59), Pair(46, 33), Pair(37, 38), Pair(40, 59),
        Pair(42, 64), Pair(28, 47), Pair(26, 47), Pair(20, 59), Pair(23, 66), Pair(35, 42), Pair(27, 53), Pair(71, 26),
        Pair(43, 3), Pair(33, 41), Pair(25, 43), Pair(26, 44), Pair(24, 53), Pair(42, 13), Pair(22, 53), Pair(33, 29)
      },
      { // Piece 5
        Pair(-84, -11), Pair(-21, -66), Pair(-52, -1), Pair(23, -15), Pair(1, -16), Pair(-16, -58), Pair(-52, -24), Pair(11, -106),
        Pair(-31, 4), Pair(-56, -11), Pair(-183, 5), Pair(-47, -6), Pair(27, -42), Pair(145, -72), Pair(-14, -38), Pair(118, -69),
        Pair(62, 37), Pair(101, -17), Pair(80, -6), Pair(-40, 1), Pair(-66, -50), Pair(0, 0), Pair(73, -52), Pair(50, -13),
        Pair(1, -1), Pair(102, -10), Pair(43, 3), Pair(16, -23), Pair(-152, -216), Pair(-27, -60), Pair(-7, -36), Pair(27, -2),
        Pair(26, -10), Pair(62, -14), Pair(22, -12), Pair(-18, -9), Pair(69, -28), Pair(27, -27), Pair(44, -28), Pair(-22, -4),
        Pair(44, -17), Pair(38, -19), Pair(20, -5), Pair(45, -6), Pair(24, -14), Pair(19, -12), Pair(14, -7), Pair(-4, 9),
        Pair(38, 0), Pair(10, -10), Pair(11, 11), Pair(0, 13), Pair(2, 1), Pair(15, -1), Pair(-2, 4), Pair(7, 15),
        Pair(4, 1), Pair(-1, 3), Pair(-4, 20), Pair(-21, 14), Pair(-3, 11), Pair(-25, 10), Pair(1, 4), Pair(7, 11)
      }
    }},
    {{ // Bucket 46
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(6, 17), Pair(10, 19), Pair(24, 3), Pair(13, 11), Pair(-31, 29), Pair(-29, 16), Pair(-7, -5), Pair(-11, 6),
        Pair(7, 7), Pair(11, 6), Pair(20, 2), Pair(6, 4), Pair(1, -2), Pair(-17, 8), Pair(0, 0), Pair(1, 11),
        Pair(3, 7), Pair(8, 2), Pair(9, 1), Pair(1, 2), Pair(-1, 2), Pair(3, 22), Pair(-5, -3), Pair(15, 17),
        Pair(5, 0), Pair(8, -4), Pair(0, 1), Pair(0, 0), Pair(-2, -1), Pair(3, 4), Pair(5, -3), Pair(7, 6),
        Pair(2, -3), Pair(6, -2), Pair(0, -1), Pair(1, -2), Pair(2, 1), Pair(4, 3), Pair(0, 0), Pair(0, 3),
        Pair(4, -2), Pair(3, -3), Pair(0, -2), Pair(2, 2), Pair(3, 0), Pair(6, 0), Pair(2, -2), Pair(-3, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-19, 18), Pair(-124, 67), Pair(-45, 32), Pair(-67, 74), Pair(46, 40), Pair(-120, 50), Pair(-85, 44), Pair(56, 15),
        Pair(10, 22), Pair(18, 14), Pair(6, 11), Pair(31, 21), Pair(12, -5), Pair(-1, 28), Pair(-59, 21), Pair(12, 53),
        Pair(-19, 33), Pair(6, 36), Pair(12, 30), Pair(3, 32), Pair(15, 46), Pair(23, 38), Pair(0, 0), Pair(-42, 28),
        Pair(0, 26), Pair(9, 26), Pair(10, 30), Pair(2, 37), Pair(22, 20), Pair(-53, 45), Pair(1, 70), Pair(-8, 10),
        Pair(6, 21), Pair(-3, 38), Pair(7, 31), Pair(3, 30), Pair(2, 43), Pair(-7, 14), Pair(-5, 53), Pair(-23, 5),
        Pair(6, 19), Pair(0, 31), Pair(1, 31), Pair(5, 33), Pair(-3, 30), Pair(4, 34), Pair(-30, 20), Pair(-4, 45),
        Pair(5, 41), Pair(-8, 24), Pair(-9, 28), Pair(-1, 36), Pair(-7, 28), Pair(-8, 36), Pair(19, 12), Pair(6, 47),
        Pair(-29, 13), Pair(0, 33), Pair(-1, 29), Pair(13, 28), Pair(-1, 29), Pair(1, 31), Pair(6, 33), Pair(-32, 39)
      },
      { // Piece 2
        Pair(-46, 56), Pair(3, 74), Pair(-56, 63), Pair(-34, 67), Pair(-92, 53), Pair(-44, 71), Pair(-24, 40), Pair(32, 34),
        Pair(6, 49), Pair(-12, 49), Pair(-11, 64), Pair(-30, 66), Pair(-39, 72), Pair(-70, 61), Pair(-70, 76), Pair(-120, -35),
        Pair(-11, 52), Pair(-3, 54), Pair(-11, 55), Pair(-15, 60), Pair(-23, 44), Pair(9, 50), Pair(0, 0), Pair(-1, 53),
        Pair(-8, 65), Pair(-14, 46), Pair(8, 49), Pair(-5, 50), Pair(6, 51), Pair(-52, -39), Pair(-7, 74), Pair(-9, -22),
        Pair(-8, 35), Pair(-1, 52), Pair(-5, 40), Pair(-1, 50), Pair(-10, 30), Pair(-17, 52), Pair(-6, 29), Pair(-13, 34),
        Pair(7, 36), Pair(10, 36), Pair(9, 46), Pair(-12, 33), Pair(-2, 47), Pair(2, 34), Pair(3, 47), Pair(-2, 17),
        Pair(6, 39), Pair(7, 41), Pair(-12, 22), Pair(-2, 45), Pair(-9, 29), Pair(8, 52), Pair(6, 31), Pair(10, 46),
        Pair(1, 41), Pair(-38, 20), Pair(3, 33), Pair(-3, 21), Pair(4, 48), Pair(4, 32), Pair(21, 70), Pair(-11, 61)
      },
      { // Piece 3
        Pair(4, 64), Pair(10, 56), Pair(-33, 70), Pair(-34, 64), Pair(13, 45), Pair(45, 41), Pair(-38, 68), Pair(30, 52),
        Pair(6, 55), Pair(34, 45), Pair(2, 55), Pair(-9, 61), Pair(8, 53), Pair(1, 44), Pair(116, 41), Pair(5, 45),
        Pair(1, 44), Pair(20, 48), Pair(25, 42), Pair(14, 49), Pair(32, 39), Pair(22, 42), Pair(0, 0), Pair(-34, 55),
        Pair(24, 40), Pair(2, 49), Pair(10, 41), Pair(-2, 51), Pair(5, 35), Pair(3, -82), Pair(-4, 45), Pair(52, -44),
        Pair(1, 52), Pair(0, 47), Pair(15, 38), Pair(-3, 42), Pair(2, 45), Pair(-12, 32), Pair(-22, 36), Pair(-23, 64),
        Pair(-2, 45), Pair(16, 43), Pair(-7, 48), Pair(9, 50), Pair(7, 42), Pair(4, 36), Pair(-21, 58), Pair(-14, 49),
        Pair(29, 39), Pair(7, 48), Pair(13, 44), Pair(19, 36), Pair(14, 35), Pair(10, 42), Pair(-4, 36), Pair(-19, 38),
        Pair(9, 44), Pair(10, 49), Pair(8, 43), Pair(7, 47), Pair(4, 44), Pair(2, 49), Pair(-1, 30), Pair(-2, 42)
      },
      { // Piece 4
        Pair(-40, 61), Pair(-38, 102), Pair(-19, 65), Pair(-1, 75), Pair(-8, 41), Pair(31, 103), Pair(-15, 79), Pair(41, 100),
        Pair(15, 35), Pair(5, 70), Pair(-5, 88), Pair(0, 76), Pair(-33, 112), Pair(4, 62), Pair(37, 66), Pair(6, 55),
        Pair(18, 36), Pair(23, 30), Pair(8, 58), Pair(21, 50), Pair(12, 23), Pair(-22, 72), Pair(0, 0), Pair(-41, 31),
        Pair(15, 43), Pair(8, 70), Pair(15, 51), Pair(4, 70), Pair(-6, 95), Pair(-26, 68), Pair(-9, 30), Pair(3, 26),
        Pair(7, 32), Pair(5, 67), Pair(0, 71), Pair(-15, 79), Pair(-3, 81), Pair(-6, 55), Pair(-5, 56), Pair(-9, 65),
        Pair(-5, 76), Pair(-1, 79), Pair(-4, 69), Pair(-2, 75), Pair(1, 59), Pair(-6, 75), Pair(25, 26), Pair(8, 60),
        Pair(7, 42), Pair(-2, 67), Pair(5, 41), Pair(-5, 52), Pair(-6, 67), Pair(-2, 66), Pair(10, 45), Pair(16, 65),
        Pair(-18, 73), Pair(-5, 34), Pair(4, 19), Pair(6, 38), Pair(4, 55), Pair(-2, 76), Pair(-27, 71), Pair(-4, 128)
      },
      { // Piece 5
        Pair(235, -87), Pair(67, -51), Pair(-43, -18), Pair(101, -29), Pair(-2, -19), Pair(25, -12), Pair(77, -53), Pair(-33, -116),
        Pair(88, -16), Pair(24, 4), Pair(167, -30), Pair(67, -32), Pair(125, -46), Pair(-1, -25), Pair(-19, -23), Pair(159, -44),
        Pair(138, 7), Pair(123, -19), Pair(17, -6), Pair(22, 8), Pair(23, -22), Pair(-1, -40), Pair(0, 0), Pair(124, -54),
        Pair(38, 12), Pair(126, -9), Pair(82, -3), Pair(76, -13), Pair(-13, -15), Pair(14, 47), Pair(-13, -68), Pair(-68, -261),
        Pair(115, -21), Pair(32, -3), Pair(41, -5), Pair(27, -7), Pair(-7, -5), Pair(78, -27), Pair(-28, -12), Pair(-28, -18),
        Pair(69, -15), Pair(56, -19), Pair(24, -5), Pair(32, 2), Pair(17, 2), Pair(11, 0), Pair(12, -8), Pair(-17, 6),
        Pair(-3, -13), Pair(-23, 8), Pair(18, -4), Pair(16, 2), Pair(-8, 13), Pair(14, 5), Pair(0, 5), Pair(-1, 4),
        Pair(-38, 11), Pair(-31, 8), Pair(-16, 6), Pair(-16, 16), Pair(-6, 16), Pair(-11, 13), Pair(-4, 6), Pair(0, -1)
      }
    }},
    {{ // Bucket 47
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-1, 16), Pair(21, 3), Pair(46, 2), Pair(2, 11), Pair(-2, 25), Pair(-11, 15), Pair(-20, 16), Pair(43, 25),
        Pair(8, 9), Pair(1, 4), Pair(2, 5), Pair(2, 6), Pair(-4, 9), Pair(-16, 3), Pair(-8, 1), Pair(0, 0),
        Pair(5, 6), Pair(5, 4), Pair(6, 3), Pair(1, 6), Pair(-4, 0), Pair(-9, 2), Pair(3, -6), Pair(-5, -2),
        Pair(3, -4), Pair(5, -2), Pair(3, 1), Pair(-3, -1), Pair(0, 4), Pair(1, 0), Pair(2, -4), Pair(-4, -1),
        Pair(1, -2), Pair(4, -3), Pair(1, -3), Pair(0, -4), Pair(3, -1), Pair(1, -1), Pair(1, -3), Pair(0, 0),
        Pair(0, -2), Pair(-2, -5), Pair(-1, -1), Pair(3, -2), Pair(0, -1), Pair(3, -3), Pair(3, -3), Pair(1, -2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-73, -2), Pair(-114, 58), Pair(-111, 34), Pair(-41, 27), Pair(-21, 23), Pair(22, 67), Pair(-1, 45), Pair(68, 70),
        Pair(-22, 31), Pair(0, 8), Pair(21, 8), Pair(-5, 46), Pair(15, 17), Pair(9, -5), Pair(26, -4), Pair(-29, 6),
        Pair(4, 14), Pair(4, 11), Pair(3, 27), Pair(8, 27), Pair(1, 32), Pair(-2, 52), Pair(-5, 50), Pair(0, 0),
        Pair(-8, 27), Pair(11, 10), Pair(9, 25), Pair(17, 27), Pair(19, 31), Pair(16, 27), Pair(-35, 11), Pair(28, 63),
        Pair(-5, 12), Pair(1, 9), Pair(2, 20), Pair(9, 24), Pair(4, 29), Pair(15, 24), Pair(2, 34), Pair(10, 38),
        Pair(-3, 10), Pair(-4, 24), Pair(5, 13), Pair(2, 20), Pair(0, 32), Pair(-2, 27), Pair(6, 35), Pair(-13, -24),
        Pair(3, -3), Pair(-20, 24), Pair(-16, 10), Pair(-5, 22), Pair(2, 24), Pair(-3, 25), Pair(6, 26), Pair(12, 32),
        Pair(-22, 13), Pair(-6, -7), Pair(-3, 10), Pair(-10, 27), Pair(-7, 12), Pair(2, 30), Pair(-5, 30), Pair(25, 16)
      },
      { // Piece 2
        Pair(-40, 79), Pair(-106, 73), Pair(-44, 66), Pair(-123, 67), Pair(-86, 83), Pair(-64, 65), Pair(-27, 42), Pair(15, 60),
        Pair(-46, 62), Pair(2, 63), Pair(-15, 59), Pair(-70, 76), Pair(-46, 60), Pair(-50, 68), Pair(-44, 74), Pair(2, 52),
        Pair(2, 45), Pair(-11, 50), Pair(-25, 71), Pair(-12, 52), Pair(2, 59), Pair(-20, 43), Pair(14, 53), Pair(0, 0),
        Pair(-5, 36), Pair(4, 46), Pair(-22, 48), Pair(12, 53), Pair(-1, 57), Pair(3, 50), Pair(-12, -14), Pair(21, 64),
        Pair(3, 32), Pair(-12, 28), Pair(8, 51), Pair(1, 39), Pair(12, 43), Pair(-3, 34), Pair(-9, 55), Pair(-13, 33),
        Pair(-10, 42), Pair(0, 46), Pair(5, 32), Pair(3, 50), Pair(-5, 32), Pair(11, 43), Pair(-8, 42), Pair(11, 50),
        Pair(-1, 68), Pair(4, 35), Pair(11, 38), Pair(-12, 34), Pair(-2, 40), Pair(-1, 41), Pair(11, 34), Pair(8, 34),
        Pair(2, 32), Pair(4, 30), Pair(-8, 23), Pair(-8, 46), Pair(-6, 41), Pair(8, 42), Pair(-18, 40), Pair(5, 52)
      },
      { // Piece 3
        Pair(27, 61), Pair(-10, 70), Pair(-41, 87), Pair(2, 75), Pair(20, 63), Pair(-24, 69), Pair(-2, 71), Pair(91, 50),
        Pair(20, 61), Pair(11, 65), Pair(10, 61), Pair(30, 58), Pair(20, 68), Pair(18, 64), Pair(23, 54), Pair(150, 47),
        Pair(26, 51), Pair(27, 55), Pair(13, 65), Pair(8, 67), Pair(22, 54), Pair(-5, 86), Pair(27, 69), Pair(0, 0),
        Pair(9, 65), Pair(8, 55), Pair(0, 65), Pair(6, 67), Pair(-6, 62), Pair(-5, 65), Pair(75, -5), Pair(-4, 76),
        Pair(1, 65), Pair(-4, 64), Pair(9, 59), Pair(-2, 65), Pair(11, 41), Pair(-4, 65), Pair(17, 53), Pair(-13, 64),
        Pair(-4, 53), Pair(20, 54), Pair(7, 56), Pair(9, 59), Pair(10, 54), Pair(10, 48), Pair(7, 64), Pair(-2, 51),
        Pair(8, 61), Pair(2, 62), Pair(11, 57), Pair(11, 46), Pair(11, 43), Pair(9, 56), Pair(-3, 71), Pair(5, 53),
        Pair(9, 56), Pair(6, 68), Pair(7, 59), Pair(3, 59), Pair(10, 52), Pair(9, 48), Pair(4, 57), Pair(-3, 61)
      },
      { // Piece 4
        Pair(-20, 77), Pair(-45, 111), Pair(7, 100), Pair(3, 93), Pair(15, 76), Pair(34, 113), Pair(108, 58), Pair(-20, 111),
        Pair(10, 105), Pair(9, 90), Pair(22, 84), Pair(-50, 155), Pair(8, 133), Pair(-39, 173), Pair(35, 131), Pair(20, 100),
        Pair(19, 90), Pair(0, 95), Pair(10, 106), Pair(16, 94), Pair(10, 111), Pair(10, 124), Pair(-33, 135), Pair(0, 0),
        Pair(33, 71), Pair(-2, 116), Pair(15, 99), Pair(1, 138), Pair(12, 94), Pair(7, 125), Pair(54, 33), Pair(20, 74),
        Pair(8, 100), Pair(19, 75), Pair(14, 88), Pair(10, 95), Pair(0, 128), Pair(20, 103), Pair(21, 81), Pair(4, 93),
        Pair(12, 73), Pair(7, 88), Pair(9, 92), Pair(2, 100), Pair(5, 90), Pair(9, 92), Pair(13, 73), Pair(8, 74),
        Pair(-9, 101), Pair(3, 76), Pair(9, 61), Pair(6, 84), Pair(11, 80), Pair(11, 70), Pair(22, 75), Pair(4, 51),
        Pair(3, 66), Pair(-3, 74), Pair(5, 83), Pair(9, 66), Pair(21, 59), Pair(3, 105), Pair(1, 80), Pair(25, 27)
      },
      { // Piece 5
        Pair(-34, -46), Pair(3, -30), Pair(-125, -9), Pair(-66, -36), Pair(97, -66), Pair(-184, -25), Pair(90, -63), Pair(13, -52),
        Pair(74, 8), Pair(42, 0), Pair(-60, -6), Pair(-117, 24), Pair(-153, 42), Pair(68, -28), Pair(-86, 17), Pair(56, -29),
        Pair(1, -26), Pair(-17, 16), Pair(30, 2), Pair(106, -40), Pair(-56, 4), Pair(-1, -23), Pair(-56, -42), Pair(0, 0),
        Pair(125, -19), Pair(88, -15), Pair(46, -18), Pair(-7, -1), Pair(65, -19), Pair(-43, -8), Pair(-77, -97), Pair(135, -81),
        Pair(-11, -24), Pair(98, -20), Pair(79, -20), Pair(34, -2), Pair(37, -2), Pair(10, -8), Pair(35, -12), Pair(51, -33),
        Pair(33, 0), Pair(23, -5), Pair(8, -3), Pair(32, -8), Pair(26, -3), Pair(-6, 6), Pair(21, -6), Pair(-2, -2),
        Pair(-34, 18), Pair(13, -16), Pair(17, 1), Pair(33, -15), Pair(2, 2), Pair(12, 5), Pair(-1, 7), Pair(2, 3),
        Pair(-12, 5), Pair(-24, -4), Pair(-13, 7), Pair(22, 3), Pair(0, 12), Pair(-10, 16), Pair(5, 7), Pair(-9, 1)
      }
    }},
    {{ // Bucket 48
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(0, 0), Pair(-7, 15), Pair(-22, 30), Pair(-4, 20), Pair(-6, 23), Pair(-31, 31), Pair(-11, 39), Pair(9, 14),
        Pair(-33, -29), Pair(-11, -5), Pair(-13, 4), Pair(7, 0), Pair(1, 6), Pair(-1, 13), Pair(-10, 18), Pair(-4, 17),
        Pair(-9, -8), Pair(-3, 6), Pair(-3, 2), Pair(3, 0), Pair(-2, 10), Pair(-3, 6), Pair(-3, 7), Pair(-2, 12),
        Pair(-3, 0), Pair(-2, 3), Pair(-3, 0), Pair(-1, 3), Pair(3, 5), Pair(-1, 4), Pair(-2, 4), Pair(1, 4),
        Pair(-3, 3), Pair(0, 4), Pair(1, 1), Pair(1, -1), Pair(0, 4), Pair(-3, 1), Pair(-3, 2), Pair(-3, 0),
        Pair(0, 0), Pair(3, 4), Pair(-1, 3), Pair(-3, -4), Pair(2, -1), Pair(-4, 1), Pair(-1, 3), Pair(0, 4),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-91, -15), Pair(90, 28), Pair(-94, 69), Pair(-7, 79), Pair(20, 12), Pair(-37, 51), Pair(51, 20), Pair(33, -64),
        Pair(0, 0), Pair(24, 31), Pair(15, 50), Pair(33, -9), Pair(43, 2), Pair(49, 29), Pair(3, 31), Pair(49, -25),
        Pair(9, 68), Pair(-141, 81), Pair(-4, 56), Pair(9, 48), Pair(30, 43), Pair(46, 24), Pair(31, 20), Pair(48, 18),
        Pair(17, 69), Pair(-12, 56), Pair(-1, 55), Pair(14, 44), Pair(17, 37), Pair(21, 35), Pair(21, 37), Pair(23, 20),
        Pair(-5, 33), Pair(-15, 41), Pair(-2, 51), Pair(5, 51), Pair(12, 32), Pair(20, 27), Pair(26, 33), Pair(19, 33),
        Pair(-6, 59), Pair(-3, 56), Pair(-2, 45), Pair(-5, 44), Pair(8, 29), Pair(7, 43), Pair(9, 31), Pair(19, 35),
        Pair(14, 59), Pair(-8, 47), Pair(4, 24), Pair(5, 37), Pair(5, 32), Pair(15, 26), Pair(-2, 28), Pair(4, 41),
        Pair(-131, 90), Pair(1, 25), Pair(-20, 58), Pair(10, 33), Pair(5, 24), Pair(4, 32), Pair(-1, 51), Pair(-4, 82)
      },
      { // Piece 2
        Pair(-11, 75), Pair(-59, 91), Pair(-17, 72), Pair(-46, 97), Pair(-75, 110), Pair(-19, 96), Pair(1, 87), Pair(-36, 67),
        Pair(0, 0), Pair(-7, 62), Pair(-10, 59), Pair(-19, 72), Pair(-30, 107), Pair(5, 83), Pair(9, 61), Pair(-6, 67),
        Pair(9, 77), Pair(-225, 239), Pair(-10, 65), Pair(-12, 78), Pair(-17, 78), Pair(13, 79), Pair(0, 83), Pair(30, 46),
        Pair(-3, 70), Pair(-25, 73), Pair(7, 70), Pair(-4, 72), Pair(-3, 77), Pair(7, 53), Pair(6, 65), Pair(8, 48),
        Pair(-5, 78), Pair(-17, 48), Pair(-8, 70), Pair(-3, 70), Pair(4, 51), Pair(3, 68), Pair(-10, 53), Pair(9, 59),
        Pair(-4, 89), Pair(-4, 62), Pair(2, 68), Pair(-2, 53), Pair(3, 54), Pair(-6, 56), Pair(10, 53), Pair(6, 59),
        Pair(-14, 71), Pair(6, 67), Pair(-3, 63), Pair(2, 55), Pair(-5, 53), Pair(3, 49), Pair(7, 46), Pair(10, 64),
        Pair(10, 60), Pair(-3, 73), Pair(7, 62), Pair(-6, 62), Pair(-4, 59), Pair(-3, 51), Pair(-11, 56), Pair(26, 36)
      },
      { // Piece 3
        Pair(-3, 100), Pair(-11, 115), Pair(-31, 115), Pair(-4, 114), Pair(-17, 99), Pair(4, 101), Pair(-21, 112), Pair(21, 103),
        Pair(0, 0), Pair(-14, 121), Pair(-12, 136), Pair(-21, 135), Pair(-10, 129), Pair(-8, 114), Pair(37, 103), Pair(10, 105),
        Pair(-7, 117), Pair(30, -215), Pair(-10, 103), Pair(-21, 111), Pair(-8, 106), Pair(6, 101), Pair(13, 89), Pair(14, 96),
        Pair(-22, 119), Pair(-34, 111), Pair(-11, 114), Pair(-15, 106), Pair(-10, 96), Pair(-18, 100), Pair(10, 76), Pair(15, 97),
        Pair(-27, 95), Pair(-15, 79), Pair(-10, 99), Pair(-6, 95), Pair(-1, 95), Pair(-12, 87), Pair(10, 90), Pair(-3, 104),
        Pair(-21, 97), Pair(-22, 102), Pair(-20, 97), Pair(-12, 98), Pair(-12, 97), Pair(-2, 95), Pair(-2, 87), Pair(19, 88),
        Pair(0, 87), Pair(-17, 78), Pair(-19, 107), Pair(-14, 80), Pair(-11, 83), Pair(-5, 89), Pair(-10, 111), Pair(6, 92),
        Pair(-16, 95), Pair(-17, 93), Pair(-13, 92), Pair(-11, 93), Pair(-7, 89), Pair(-7, 87), Pair(-2, 108), Pair(-6, 98)
      },
      { // Piece 4
        Pair(-60, 237), Pair(24, 173), Pair(-2, 193), Pair(-5, 172), Pair(38, 173), Pair(-17, 174), Pair(49, 164), Pair(4, 180),
        Pair(0, 0), Pair(26, 172), Pair(7, 201), Pair(-8, 220), Pair(-2, 246), Pair(11, 232), Pair(31, 199), Pair(50, 182),
        Pair(32, 192), Pair(-119, -49), Pair(8, 205), Pair(22, 177), Pair(32, 165), Pair(45, 157), Pair(22, 159), Pair(29, 188),
        Pair(25, 143), Pair(12, 170), Pair(23, 178), Pair(9, 181), Pair(13, 194), Pair(16, 193), Pair(25, 176), Pair(29, 179),
        Pair(25, 160), Pair(9, 142), Pair(14, 166), Pair(9, 189), Pair(18, 169), Pair(7, 185), Pair(23, 152), Pair(23, 173),
        Pair(12, 178), Pair(5, 156), Pair(14, 154), Pair(8, 158), Pair(6, 175), Pair(15, 162), Pair(14, 169), Pair(38, 148),
        Pair(10, 132), Pair(9, 160), Pair(9, 160), Pair(11, 161), Pair(12, 162), Pair(7, 161), Pair(5, 124), Pair(67, 135),
        Pair(22, 152), Pair(10, 141), Pair(0, 170), Pair(7, 156), Pair(0, 152), Pair(-4, 192), Pair(47, 95), Pair(47, 129)
      },
      { // Piece 5
        Pair(31, 18), Pair(-33, 24), Pair(-20, 17), Pair(43, -9), Pair(37, -41), Pair(89, -4), Pair(31, -21), Pair(61, 72),
        Pair(0, 0), Pair(22, -71), Pair(-66, 28), Pair(-35, -5), Pair(1, -12), Pair(34, 3), Pair(129, -45), Pair(68, -59),
        Pair(-3, -80), Pair(0, 0), Pair(-119, 3), Pair(-52, 11), Pair(-113, 20), Pair(21, 14), Pair(54, -6), Pair(-39, 7),
        Pair(-120, -56), Pair(-19, -18), Pair(-61, -8), Pair(15, 1), Pair(28, -9), Pair(23, -17), Pair(-38, 1), Pair(-23, -7),
        Pair(9, -32), Pair(-80, -17), Pair(-14, -2), Pair(-62, -1), Pair(35, -13), Pair(-9, -3), Pair(-23, 2), Pair(-9, 2),
        Pair(-22, -34), Pair(-60, -3), Pair(1, -10), Pair(11, -13), Pair(-8, -7), Pair(5, -10), Pair(2, -3), Pair(10, -7),
        Pair(6, -18), Pair(-35, 7), Pair(7, -7), Pair(6, -1), Pair(2, -3), Pair(3, -4), Pair(0, -5), Pair(5, -5),
        Pair(-34, 29), Pair(12, 3), Pair(10, -1), Pair(18, -9), Pair(10, -10), Pair(6, -11), Pair(2, -9), Pair(7, -6)
      }
    }},
    {{ // Bucket 49
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(7, 31), Pair(0, 0), Pair(-24, 24), Pair(19, 5), Pair(-4, 0), Pair(-7, 5), Pair(0, 16), Pair(-3, 15),
        Pair(4, 1), Pair(-27, -32), Pair(-9, 25), Pair(3, 5), Pair(-7, 10), Pair(-1, 13), Pair(1, 6), Pair(-4, 19),
        Pair(10, 2), Pair(-8, -9), Pair(1, 15), Pair(0, 4), Pair(-4, 9), Pair(-2, 10), Pair(-2, 8), Pair(-5, 12),
        Pair(5, 2), Pair(-7, -7), Pair(4, 6), Pair(-2, 3), Pair(-1, 3), Pair(-3, 5), Pair(0, 5), Pair(-2, 9),
        Pair(4, 0), Pair(-3, 0), Pair(0, 6), Pair(-2, 0), Pair(-2, 4), Pair(-6, 1), Pair(-5, 2), Pair(-8, 3),
        Pair(2, -2), Pair(0, 0), Pair(3, 1), Pair(-1, 0), Pair(-1, -2), Pair(-5, 0), Pair(-5, 0), Pair(-2, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-23, 22), Pair(-137, -105), Pair(12, 70), Pair(-49, 28), Pair(69, 27), Pair(-1, 33), Pair(-158, 44), Pair(-56, 64),
        Pair(-36, 10), Pair(0, 0), Pair(-7, 52), Pair(-34, 52), Pair(-37, 30), Pair(6, 25), Pair(3, 44), Pair(20, 56),
        Pair(75, -43), Pair(7, 83), Pair(-278, 160), Pair(0, 53), Pair(-8, 45), Pair(26, 16), Pair(12, 31), Pair(2, 5),
        Pair(-20, 45), Pair(-6, 40), Pair(-27, 45), Pair(-1, 40), Pair(-1, 36), Pair(17, 36), Pair(11, 41), Pair(19, 18),
        Pair(-11, 47), Pair(-9, 12), Pair(-21, 37), Pair(-8, 39), Pair(4, 37), Pair(4, 37), Pair(23, 40), Pair(4, 40),
        Pair(6, 45), Pair(-11, 52), Pair(-3, 44), Pair(-3, 36), Pair(5, 36), Pair(3, 39), Pair(8, 29), Pair(3, 55),
        Pair(-18, 70), Pair(7, 33), Pair(4, 32), Pair(-2, 46), Pair(6, 38), Pair(5, 40), Pair(4, 24), Pair(2, 41),
        Pair(37, -10), Pair(6, 47), Pair(8, 22), Pair(8, 11), Pair(-5, 46), Pair(2, 71), Pair(5, 54), Pair(-35, 72)
      },
      { // Piece 2
        Pair(0, 0), Pair(-20, 68), Pair(-79, 82), Pair(5, 62), Pair(-1, 78), Pair(-13, 47), Pair(-33, 77), Pair(-65, 92),
        Pair(-25, 45), Pair(0, 0), Pair(-23, 54), Pair(-68, 99), Pair(-32, 89), Pair(-15, 71), Pair(-4, 70), Pair(9, 51),
        Pair(-31, 9), Pair(-7, 72), Pair(-167, -35), Pair(-2, 73), Pair(-32, 88), Pair(-13, 69), Pair(-6, 55), Pair(1, 44),
        Pair(-27, 64), Pair(-11, 53), Pair(-32, 72), Pair(-9, 71), Pair(-1, 56), Pair(-21, 77), Pair(5, 68), Pair(-1, 52),
        Pair(-30, 54), Pair(-7, 52), Pair(-30, 63), Pair(-9, 58), Pair(1, 54), Pair(-3, 49), Pair(1, 58), Pair(10, 59),
        Pair(1, 46), Pair(-9, 64), Pair(-4, 59), Pair(-8, 48), Pair(1, 44), Pair(-7, 51), Pair(9, 39), Pair(1, 38),
        Pair(-6, 85), Pair(4, 50), Pair(-8, 60), Pair(-2, 52), Pair(-6, 45), Pair(3, 43), Pair(0, 47), Pair(-2, 50),
        Pair(6, 62), Pair(2, 59), Pair(1, 69), Pair(-19, 57), Pair(-1, 50), Pair(-6, 53), Pair(22, 41), Pair(-13, 34)
      },
      { // Piece 3
        Pair(-9, 71), Pair(-62, 87), Pair(-15, 74), Pair(39, 57), Pair(7, 67), Pair(-58, 86), Pair(-66, 81), Pair(18, 54),
        Pair(-12, 53), Pair(0, 0), Pair(9, 68), Pair(5, 79), Pair(6, 75), Pair(-10, 85), Pair(-29, 72), Pair(-45, 100),
        Pair(-191, -30), Pair(-15, 72), Pair(-97, 34), Pair(22, 59), Pair(-14, 63), Pair(-3, 69), Pair(4, 58), Pair(-1, 72),
        Pair(-26, 62), Pair(-6, 77), Pair(-17, 55), Pair(-15, 79), Pair(-28, 84), Pair(-2, 63), Pair(-16, 60), Pair(-12, 65),
        Pair(-7, 31), Pair(-19, 62), Pair(-19, 56), Pair(-19, 67), Pair(-8, 69), Pair(-13, 73), Pair(-13, 63), Pair(-8, 70),
        Pair(-19, 67), Pair(-11, 59), Pair(-23, 71), Pair(-1, 60), Pair(-9, 69), Pair(7, 57), Pair(9, 56), Pair(-1, 63),
        Pair(-3, 55), Pair(6, 44), Pair(-21, 66), Pair(-4, 58), Pair(-20, 65), Pair(-3, 59), Pair(6, 53), Pair(-16, 59),
        Pair(-11, 62), Pair(-5, 58), Pair(-16, 59), Pair(-9, 64), Pair(-5, 60), Pair(-5, 67), Pair(-2, 71), Pair(7, 68)
      },
      { // Piece 4
        Pair(21, 110), Pair(-5, 120), Pair(-6, 116), Pair(-9, 156), Pair(44, 138), Pair(33, 147), Pair(-30, 173), Pair(33, 77),
        Pair(43, 83), Pair(0, 0), Pair(-1, 134), Pair(16, 122), Pair(8, 144), Pair(-12, 143), Pair(-19, 89), Pair(3, 125),
        Pair(-183, -13), Pair(40, 106), Pair(-198, -117), Pair(26, 102), Pair(33, 129), Pair(33, 116), Pair(12, 104), Pair(13, 140),
        Pair(18, 85), Pair(35, 96), Pair(22, 120), Pair(29, 103), Pair(27, 104), Pair(24, 143), Pair(27, 133), Pair(20, 130),
        Pair(7, 98), Pair(5, 122), Pair(9, 96), Pair(8, 126), Pair(22, 121), Pair(22, 84), Pair(12, 119), Pair(22, 162),
        Pair(18, 115), Pair(13, 112), Pair(15, 99), Pair(6, 116), Pair(14, 112), Pair(16, 100), Pair(11, 126), Pair(11, 145),
        Pair(5, 101), Pair(10, 109), Pair(13, 90), Pair(11, 105), Pair(8, 103), Pair(12, 87), Pair(14, 72), Pair(-8, 141),
        Pair(2, 108), Pair(16, 108), Pair(15, 92), Pair(12, 100), Pair(11, 98), Pair(27, 82), Pair(15, 91), Pair(4, 99)
      },
      { // Piece 5
        Pair(-5, 6), Pair(43, -72), Pair(-69, -45), Pair(21, -9), Pair(-33, -24), Pair(94, -36), Pair(-44, -49), Pair(36, -97),
        Pair(-64, -52), Pair(0, 0), Pair(-37, -43), Pair(71, -17), Pair(-28, -26), Pair(-21, -24), Pair(-15, 25), Pair(44, -4),
        Pair(0, 0), Pair(-107, -54), Pair(0, 0), Pair(-111, -22), Pair(-175, 24), Pair(57, -4), Pair(-18, 5), Pair(36, -7),
        Pair(-66, -11), Pair(-49, -64), Pair(-44, -27), Pair(-154, -6), Pair(22, -3), Pair(6, 1), Pair(-35, 15), Pair(19, 0),
        Pair(-15, -27), Pair(-67, -16), Pair(-32, -26), Pair(-14, -13), Pair(8, -8), Pair(43, -6), Pair(11, 1), Pair(50, -11),
        Pair(-36, -23), Pair(-13, -28), Pair(-36, -8), Pair(-2, -4), Pair(-8, 2), Pair(-4, 2), Pair(23, -1), Pair(16, -1),
        Pair(-23, 5), Pair(-17, -20), Pair(-1, -10), Pair(11, -3), Pair(3, 0), Pair(-4, 3), Pair(7, -3), Pair(2, -3),
        Pair(1, 33), Pair(2, 0), Pair(23, -19), Pair(30, 1), Pair(3, -8), Pair(17, -9), Pair(0, -5), Pair(1, 1)
      }
    }},
    {{ // Bucket 50
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(11, -6), Pair(-3, 8), Pair(0, 0), Pair(12, 13), Pair(-3, 20), Pair(6, 15), Pair(7, 21), Pair(-2, 0),
        Pair(5, 6), Pair(0, 5), Pair(-38, -27), Pair(5, 23), Pair(2, 8), Pair(3, 16), Pair(2, 13), Pair(-3, 8),
        Pair(1, 4), Pair(4, 9), Pair(-8, -4), Pair(1, 16), Pair(-3, 4), Pair(5, 4), Pair(5, 4), Pair(2, 7),
        Pair(-1, 1), Pair(2, -4), Pair(-10, -6), Pair(1, 5), Pair(-4, 0), Pair(0, 9), Pair(1, 4), Pair(-1, 6),
        Pair(1, 2), Pair(-2, -2), Pair(-4, -1), Pair(2, 4), Pair(-2, 1), Pair(-7, 5), Pair(-1, 4), Pair(-1, 1),
        Pair(-1, 1), Pair(-5, -2), Pair(0, 0), Pair(-5, 3), Pair(0, 0), Pair(-6, -2), Pair(2, 3), Pair(4, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-110, 17), Pair(8, 80), Pair(-70, -38), Pair(-17, 45), Pair(51, -24), Pair(-77, 39), Pair(-17, 27), Pair(25, 12),
        Pair(0, 37), Pair(-33, 15), Pair(0, 0), Pair(-30, 35), Pair(27, 23), Pair(-18, 12), Pair(-29, 5), Pair(33, 21),
        Pair(-6, 21), Pair(83, -122), Pair(5, 68), Pair(-322, 204), Pair(19, 18), Pair(-23, 44), Pair(32, 12), Pair(-10, 50),
        Pair(-6, 36), Pair(-28, 18), Pair(5, 42), Pair(-28, 33), Pair(-5, 55), Pair(1, 36), Pair(6, 36), Pair(8, 26),
        Pair(-23, 26), Pair(-6, 44), Pair(-11, 27), Pair(-29, 46), Pair(2, 25), Pair(-8, 46), Pair(6, 32), Pair(-3, 35),
        Pair(-6, 46), Pair(-4, 54), Pair(-7, 41), Pair(-3, 49), Pair(-7, 27), Pair(-2, 35), Pair(-11, 46), Pair(-10, 61),
        Pair(3, 21), Pair(-15, 51), Pair(-7, 33), Pair(-3, 37), Pair(-3, 36), Pair(7, 30), Pair(13, 17), Pair(5, 18),
        Pair(32, 14), Pair(-7, 53), Pair(10, 21), Pair(-20, 42), Pair(10, 23), Pair(4, 15), Pair(-5, 46), Pair(28, 3)
      },
      { // Piece 2
        Pair(-47, 16), Pair(-35, 3), Pair(-21, 108), Pair(-39, 27), Pair(-24, 48), Pair(-55, 67), Pair(-140, 44), Pair(-12, 59),
        Pair(3, 6), Pair(-26, 59), Pair(0, 0), Pair(-43, 44), Pair(-18, 32), Pair(-42, 95), Pair(-18, 63), Pair(-7, 49),
        Pair(-3, 36), Pair(25, -50), Pair(-8, 83), Pair(-381, 75), Pair(-19, 66), Pair(18, 46), Pair(-5, 73), Pair(-5, 43),
        Pair(-4, 45), Pair(-30, 52), Pair(-12, 42), Pair(-39, 47), Pair(-13, 51), Pair(-17, 60), Pair(-5, 43), Pair(14, 37),
        Pair(10, 29), Pair(-11, 20), Pair(-7, 42), Pair(-32, 49), Pair(0, 47), Pair(-13, 47), Pair(1, 36), Pair(-4, 48),
        Pair(-7, 29), Pair(-8, 48), Pair(-5, 36), Pair(-5, 49), Pair(-11, 39), Pair(-7, 46), Pair(-5, 50), Pair(-5, 46),
        Pair(-12, 63), Pair(-2, 40), Pair(-2, 59), Pair(-7, 41), Pair(-1, 48), Pair(6, 40), Pair(4, 40), Pair(4, 50),
        Pair(-7, 63), Pair(-3, 35), Pair(-4, 43), Pair(-19, 65), Pair(-2, 52), Pair(-1, 62), Pair(23, 37), Pair(2, 47)
      },
      { // Piece 3
        Pair(7, 45), Pair(-52, 51), Pair(-22, 59), Pair(-36, 52), Pair(-2, 53), Pair(7, 66), Pair(-11, 65), Pair(-14, 67),
        Pair(-14, 51), Pair(-43, 48), Pair(0, 0), Pair(-34, 71), Pair(-15, 66), Pair(-55, 84), Pair(-52, 55), Pair(-1, 51),
        Pair(-24, 53), Pair(92, -135), Pair(5, 52), Pair(-68, 32), Pair(5, 39), Pair(16, 46), Pair(-36, 84), Pair(1, 40),
        Pair(-16, 47), Pair(-29, 46), Pair(-20, 65), Pair(-33, 47), Pair(-27, 68), Pair(6, 38), Pair(6, 47), Pair(-14, 54),
        Pair(-18, 49), Pair(-9, 33), Pair(-25, 49), Pair(-28, 51), Pair(-11, 45), Pair(-16, 50), Pair(-19, 55), Pair(3, 53),
        Pair(-16, 51), Pair(-22, 58), Pair(-16, 46), Pair(-18, 61), Pair(-10, 55), Pair(-21, 67), Pair(-16, 65), Pair(-16, 63),
        Pair(-27, 79), Pair(-3, 40), Pair(-31, 66), Pair(-19, 42), Pair(-16, 51), Pair(-1, 46), Pair(-20, 66), Pair(-4, 48),
        Pair(-19, 49), Pair(-23, 46), Pair(-18, 49), Pair(-18, 43), Pair(-16, 50), Pair(-14, 55), Pair(-8, 56), Pair(-8, 57)
      },
      { // Piece 4
        Pair(42, 45), Pair(-44, 79), Pair(114, 9), Pair(-53, 74), Pair(-21, 107), Pair(-145, 187), Pair(-23, 76), Pair(-21, 78),
        Pair(11, 87), Pair(1, 96), Pair(0, 0), Pair(-2, 65), Pair(-1, 114), Pair(-24, 101), Pair(-23, 42), Pair(9, 70),
        Pair(31, 57), Pair(-163, -2), Pair(19, 90), Pair(-144, -35), Pair(27, 61), Pair(39, 64), Pair(33, 86), Pair(16, 61),
        Pair(21, 63), Pair(1, 119), Pair(36, 62), Pair(13, 75), Pair(1, 98), Pair(-2, 128), Pair(15, 100), Pair(11, 72),
        Pair(2, 98), Pair(5, 74), Pair(8, 91), Pair(-6, 96), Pair(10, 85), Pair(24, 67), Pair(8, 74), Pair(17, 64),
        Pair(20, 66), Pair(3, 82), Pair(27, 43), Pair(0, 94), Pair(12, 70), Pair(7, 74), Pair(13, 44), Pair(12, 69),
        Pair(8, 93), Pair(1, 73), Pair(13, 60), Pair(5, 72), Pair(-2, 81), Pair(7, 62), Pair(1, 85), Pair(8, 81),
        Pair(5, 88), Pair(9, 62), Pair(14, 50), Pair(4, 65), Pair(4, 66), Pair(22, 50), Pair(9, 21), Pair(-8, 97)
      },
      { // Piece 5
        Pair(22, 123), Pair(-20, -45), Pair(39, -92), Pair(-18, -56), Pair(54, 69), Pair(-24, 32), Pair(57, 2), Pair(-53, 23),
        Pair(-62, -92), Pair(51, -125), Pair(0, 0), Pair(92, -87), Pair(-15, 40), Pair(-128, -16), Pair(-125, -15), Pair(16, 7),
        Pair(10, -35), Pair(0, 0), Pair(-169, -20), Pair(0, 0), Pair(5, -27), Pair(-1, -7), Pair(11, 1), Pair(-96, 39),
        Pair(-167, 22), Pair(-154, 10), Pair(-164, -7), Pair(-31, -14), Pair(-75, -7), Pair(5, 0), Pair(-60, 12), Pair(-35, 17),
        Pair(2, -5), Pair(-56, -24), Pair(-99, -6), Pair(-33, -11), Pair(10, 8), Pair(-14, 15), Pair(15, 7), Pair(-9, -8),
        Pair(-12, -13), Pair(10, -15), Pair(3, -28), Pair(-34, -3), Pair(-36, 7), Pair(0, 4), Pair(-9, 10), Pair(-5, 3),
        Pair(-21, -1), Pair(-14, 7), Pair(-17, -14), Pair(0, 0), Pair(5, 2), Pair(8, 2), Pair(0, -3), Pair(11, -5),
        Pair(-8, 26), Pair(8, -24), Pair(-2, 6), Pair(25, -18), Pair(7, -4), Pair(10, -5), Pair(0, 1), Pair(5, -10)
      }
    }},
    {{ // Bucket 51
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-5, 21), Pair(-10, 37), Pair(8, 35), Pair(0, 0), Pair(30, -23), Pair(73, -43), Pair(35, -31), Pair(-3, 62),
        Pair(6, -5), Pair(4, -5), Pair(3, 26), Pair(-2, -28), Pair(-18, 46), Pair(-11, 3), Pair(-9, 30), Pair(-19, 27),
        Pair(0, 13), Pair(2, 7), Pair(3, 15), Pair(-2, 4), Pair(5, 13), Pair(-3, 16), Pair(4, 11), Pair(-2, 12),
        Pair(3, 9), Pair(0, 0), Pair(8, 3), Pair(-2, -4), Pair(3, 8), Pair(-2, 2), Pair(-1, 1), Pair(-4, 8),
        Pair(4, 8), Pair(1, 1), Pair(2, -1), Pair(-2, -1), Pair(-3, 4), Pair(-2, 2), Pair(-3, -2), Pair(-3, 1),
        Pair(2, 3), Pair(2, 0), Pair(4, -4), Pair(0, 0), Pair(-6, 15), Pair(-1, 0), Pair(-3, 1), Pair(-3, 7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-51, 63), Pair(-23, -184), Pair(-36, 58), Pair(-16, -106), Pair(4, 28), Pair(-14, -53), Pair(-34, 16), Pair(84, -1),
        Pair(-36, -13), Pair(-56, 50), Pair(-13, -2), Pair(0, 0), Pair(33, -11), Pair(1, 34), Pair(28, -38), Pair(48, -21),
        Pair(-58, 112), Pair(-11, 7), Pair(-261, -16), Pair(11, 46), Pair(-33, 17), Pair(14, 27), Pair(-46, 11), Pair(54, 27),
        Pair(-39, 23), Pair(1, 7), Pair(-39, 30), Pair(-12, 55), Pair(-21, 8), Pair(-4, 15), Pair(3, -8), Pair(-17, 25),
        Pair(7, -2), Pair(-1, 24), Pair(-7, -9), Pair(-10, 9), Pair(-6, 44), Pair(-5, 24), Pair(-16, 49), Pair(-2, 25),
        Pair(16, 23), Pair(-10, 16), Pair(-7, 29), Pair(-10, 16), Pair(-18, 31), Pair(-3, 2), Pair(-8, -12), Pair(-5, 40),
        Pair(31, 11), Pair(31, 6), Pair(1, -18), Pair(-6, 24), Pair(2, 17), Pair(-11, 26), Pair(11, 20), Pair(-16, 22),
        Pair(-3, 13), Pair(2, 29), Pair(37, 63), Pair(25, -22), Pair(-6, 25), Pair(-9, 45), Pair(-8, 32), Pair(-45, 104)
      },
      { // Piece 2
        Pair(57, -14), Pair(-120, 20), Pair(-19, -55), Pair(25, 14), Pair(-81, -34), Pair(159, -66), Pair(119, -6), Pair(-15, -65),
        Pair(-34, 28), Pair(-39, 71), Pair(-31, 51), Pair(0, 0), Pair(-16, 58), Pair(1, 66), Pair(-41, 68), Pair(-16, 8),
        Pair(-34, 12), Pair(-8, 32), Pair(-95, -202), Pair(6, 57), Pair(-28, 10), Pair(-68, 56), Pair(4, 57), Pair(3, 35),
        Pair(-33, 114), Pair(-28, 27), Pair(-44, 48), Pair(-19, 62), Pair(-15, 46), Pair(-4, 8), Pair(2, 47), Pair(-6, 57),
        Pair(-22, -14), Pair(-17, 55), Pair(-17, 30), Pair(5, 35), Pair(-8, 37), Pair(-19, 27), Pair(-32, 44), Pair(-6, 21),
        Pair(11, 38), Pair(-15, 5), Pair(-7, 38), Pair(-9, 16), Pair(7, 5), Pair(-9, 4), Pair(5, -8), Pair(-7, -11),
        Pair(-31, 2), Pair(-3, 46), Pair(-13, 16), Pair(-3, -5), Pair(-9, 5), Pair(-1, 4), Pair(7, 12), Pair(-10, 97),
        Pair(-1, 32), Pair(18, 28), Pair(-8, 25), Pair(-17, 57), Pair(-19, 14), Pair(-12, 34), Pair(-26, 20), Pair(-6, 3)
      },
      { // Piece 3
        Pair(-29, 60), Pair(-31, 19), Pair(90, -29), Pair(-88, 29), Pair(42, 37), Pair(76, -23), Pair(-143, 75), Pair(17, 40),
        Pair(-26, 42), Pair(-22, 7), Pair(11, 17), Pair(0, 0), Pair(18, 40), Pair(36, 55), Pair(-34, 45), Pair(-16, 23),
        Pair(12, 25), Pair(5, 18), Pair(-9, 41), Pair(52, -18), Pair(53, 61), Pair(47, -18), Pair(19, 14), Pair(35, -41),
        Pair(-18, 12), Pair(-24, -1), Pair(3, 18), Pair(2, 35), Pair(-8, -23), Pair(-14, -18), Pair(27, 22), Pair(1, 54),
        Pair(-13, 22), Pair(-29, 36), Pair(-31, 34), Pair(-4, -6), Pair(21, -21), Pair(4, 26), Pair(-17, 46), Pair(68, 6),
        Pair(-8, 28), Pair(3, 36), Pair(-34, 29), Pair(5, 11), Pair(-43, 29), Pair(-31, 50), Pair(16, 6), Pair(-2, 16),
        Pair(-1, -16), Pair(-4, -35), Pair(3, -32), Pair(-7, -26), Pair(-16, 1), Pair(0, 39), Pair(-6, 18), Pair(13, 10),
        Pair(-9, 12), Pair(-10, 15), Pair(-12, 6), Pair(-17, 17), Pair(-7, 20), Pair(-12, 16), Pair(-10, 15), Pair(-3, 8)
      },
      { // Piece 4
        Pair(46, 39), Pair(20, -45), Pair(130, -50), Pair(63, -44), Pair(-73, 148), Pair(-43, 69), Pair(16, 2), Pair(36, -23),
        Pair(30, -13), Pair(-29, 59), Pair(3, -49), Pair(0, 0), Pair(1, 52), Pair(37, 118), Pair(-25, 69), Pair(-26, 88),
        Pair(-26, 42), Pair(43, -19), Pair(54, 11), Pair(45, 43), Pair(-2, -7), Pair(41, 43), Pair(40, 29), Pair(-3, 43),
        Pair(-9, 10), Pair(1, 19), Pair(11, 64), Pair(33, 8), Pair(-9, 72), Pair(1, 30), Pair(26, -4), Pair(23, 62),
        Pair(8, 53), Pair(19, 12), Pair(22, 3), Pair(15, 38), Pair(23, 46), Pair(24, -31), Pair(8, 48), Pair(-4, 61),
        Pair(-7, 29), Pair(11, 21), Pair(12, -23), Pair(7, 28), Pair(8, -6), Pair(1, 53), Pair(-15, 60), Pair(41, 40),
        Pair(-7, -17), Pair(-2, 52), Pair(5, 5), Pair(10, 2), Pair(8, -3), Pair(0, 0), Pair(-19, 26), Pair(48, -135),
        Pair(0, 19), Pair(16, 10), Pair(9, -20), Pair(10, 13), Pair(8, 21), Pair(9, 42), Pair(-24, 6), Pair(-21, 15)
      },
      { // Piece 5
        Pair(-3, 30), Pair(7, -68), Pair(14, 56), Pair(-10, -11), Pair(-4, 33), Pair(5, 39), Pair(-5, -67), Pair(-42, -80),
        Pair(8, -25), Pair(-28, -30), Pair(54, -6), Pair(0, 0), Pair(-28, -40), Pair(3, 13), Pair(-13, -6), Pair(-75, -149),
        Pair(-37, -71), Pair(2, -2), Pair(0, 0), Pair(11, -112), Pair(0, 0), Pair(28, -22), Pair(111, -39), Pair(-20, -4),
        Pair(-34, 17), Pair(-66, 14), Pair(-116, 31), Pair(32, -62), Pair(41, -20), Pair(151, -11), Pair(-70, 48), Pair(-32, 1),
        Pair(-73, 1), Pair(-23, -25), Pair(77, -40), Pair(-19, 1), Pair(-52, 11), Pair(-83, 43), Pair(39, -9), Pair(126, -31),
        Pair(-173, 51), Pair(-17, 13), Pair(-40, 3), Pair(-1, -39), Pair(-40, 3), Pair(10, -2), Pair(-9, 12), Pair(-2, 15),
        Pair(25, 3), Pair(8, -6), Pair(11, -29), Pair(-1, -7), Pair(-2, -4), Pair(-23, 27), Pair(19, 2), Pair(5, 6),
        Pair(3, 20), Pair(1, 6), Pair(7, 20), Pair(7, -30), Pair(-1, -24), Pair(13, 3), Pair(2, 9), Pair(11, 10)
      }
    }},
    {{ // Bucket 52
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(19, 16), Pair(14, 3), Pair(11, -3), Pair(-26, 9), Pair(0, 0), Pair(0, 28), Pair(-39, 22), Pair(16, 9),
        Pair(-1, 18), Pair(13, 2), Pair(-6, 10), Pair(3, 36), Pair(-21, -12), Pair(-7, 23), Pair(23, 7), Pair(14, 21),
        Pair(2, 2), Pair(2, 8), Pair(0, 9), Pair(14, 9), Pair(-7, 4), Pair(4, 7), Pair(1, 0), Pair(-1, 3),
        Pair(5, 1), Pair(0, 0), Pair(0, 3), Pair(2, 7), Pair(-3, -8), Pair(-2, 2), Pair(5, 0), Pair(-2, 5),
        Pair(2, 1), Pair(2, 5), Pair(0, -1), Pair(1, 7), Pair(-5, 3), Pair(-6, 0), Pair(-3, 1), Pair(0, 1),
        Pair(0, 0), Pair(0, 4), Pair(1, 1), Pair(8, -15), Pair(0, 0), Pair(-5, 0), Pair(0, -1), Pair(0, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-10, 23), Pair(50, 36), Pair(-16, 9), Pair(-77, 83), Pair(-31, -47), Pair(-43, 49), Pair(-12, 22), Pair(31, -130),
        Pair(23, 29), Pair(-34, 25), Pair(-2, 7), Pair(19, 28), Pair(0, 0), Pair(-46, 79), Pair(-22, -27), Pair(-38, 22),
        Pair(1, 33), Pair(5, 16), Pair(-12, 32), Pair(-77, -8), Pair(21, 69), Pair(-443, 272), Pair(-3, 24), Pair(-31, -13),
        Pair(-8, 49), Pair(-8, 12), Pair(18, 13), Pair(-30, 10), Pair(-12, 42), Pair(-64, 48), Pair(3, 11), Pair(-13, 48),
        Pair(2, 10), Pair(-17, 16), Pair(-8, 27), Pair(-30, 23), Pair(1, 4), Pair(-26, 9), Pair(-5, 51), Pair(10, -2),
        Pair(-7, 27), Pair(-9, 18), Pair(-7, 13), Pair(-4, 15), Pair(-19, 43), Pair(-6, 21), Pair(-8, 27), Pair(-10, 19),
        Pair(6, 16), Pair(18, 6), Pair(-7, 32), Pair(-2, 4), Pair(-10, 18), Pair(8, 3), Pair(12, 6), Pair(6, -18),
        Pair(12, -33), Pair(1, 27), Pair(18, 11), Pair(14, 8), Pair(1, 0), Pair(3, 4), Pair(-2, 10), Pair(51, -45)
      },
      { // Piece 2
        Pair(-37, 34), Pair(61, -1), Pair(-61, 57), Pair(-19, 2), Pair(-101, 45), Pair(-117, -21), Pair(19, 22), Pair(-55, 74),
        Pair(-16, 57), Pair(-17, 36), Pair(-13, 20), Pair(-72, 46), Pair(0, 0), Pair(14, 41), Pair(-36, -16), Pair(7, -5),
        Pair(-3, 19), Pair(-29, 48), Pair(-12, 56), Pair(-296, 149), Pair(21, 83), Pair(-270, 209), Pair(-6, 28), Pair(-13, 30),
        Pair(-10, 25), Pair(-9, 39), Pair(9, 29), Pair(-68, 39), Pair(2, 23), Pair(-52, 67), Pair(3, 17), Pair(-7, 40),
        Pair(-17, 39), Pair(9, 8), Pair(-16, 47), Pair(-25, 15), Pair(-1, 33), Pair(-22, 13), Pair(-7, 41), Pair(-9, -3),
        Pair(0, 24), Pair(-12, 25), Pair(-9, 29), Pair(-10, 46), Pair(-14, 28), Pair(-15, 32), Pair(-16, -2), Pair(-7, 35),
        Pair(-12, 49), Pair(-8, 19), Pair(-6, 33), Pair(-6, 18), Pair(-4, 40), Pair(-16, 16), Pair(-4, 23), Pair(-5, -41),
        Pair(-14, 14), Pair(-6, 75), Pair(-7, 26), Pair(-19, 55), Pair(4, 3), Pair(1, 37), Pair(-44, 43), Pair(-18, 16)
      },
      { // Piece 3
        Pair(-4, 25), Pair(-20, 28), Pair(-45, 51), Pair(-40, 47), Pair(-11, 48), Pair(33, -7), Pair(45, 20), Pair(-66, 42),
        Pair(-20, 50), Pair(-24, 33), Pair(-16, 39), Pair(7, 40), Pair(0, 0), Pair(42, 23), Pair(-52, 34), Pair(16, -15),
        Pair(-6, 29), Pair(-10, 31), Pair(36, 19), Pair(-163, -10), Pair(49, -7), Pair(59, -50), Pair(-10, 9), Pair(-23, 18),
        Pair(-5, 20), Pair(-13, 44), Pair(26, 14), Pair(-33, 12), Pair(39, 13), Pair(-13, 9), Pair(3, 13), Pair(7, 7),
        Pair(7, 12), Pair(6, -3), Pair(-7, 34), Pair(-31, 36), Pair(-1, 16), Pair(16, -6), Pair(-40, 69), Pair(1, 40),
        Pair(3, 20), Pair(6, 21), Pair(-5, 20), Pair(-21, 46), Pair(15, -9), Pair(20, 6), Pair(-6, 36), Pair(6, 12),
        Pair(-12, 28), Pair(5, 16), Pair(2, 22), Pair(-4, 22), Pair(8, 18), Pair(14, 4), Pair(-8, 37), Pair(28, 20),
        Pair(0, 15), Pair(-3, 21), Pair(4, 17), Pair(-3, 10), Pair(4, 15), Pair(4, 21), Pair(-4, 16), Pair(1, 35)
      },
      { // Piece 4
        Pair(47, -15), Pair(12, 44), Pair(52, -3), Pair(-4, -46), Pair(23, 39), Pair(1, 60), Pair(141, -19), Pair(-39, 162),
        Pair(37, 7), Pair(-6, 65), Pair(25, -22), Pair(11, -24), Pair(0, 0), Pair(-22, 26), Pair(83, -65), Pair(-9, 31),
        Pair(29, 13), Pair(5, 57), Pair(-4, 10), Pair(27, 8), Pair(56, 5), Pair(-3, -4), Pair(33, 46), Pair(2, 71),
        Pair(28, 3), Pair(19, 22), Pair(17, 23), Pair(2, 47), Pair(33, 6), Pair(-5, 67), Pair(42, -2), Pair(-6, 60),
        Pair(4, 13), Pair(3, 13), Pair(-8, 44), Pair(-5, 36), Pair(19, 26), Pair(36, -1), Pair(-16, 65), Pair(7, 38),
        Pair(13, -23), Pair(-9, 57), Pair(3, 26), Pair(5, 6), Pair(13, 24), Pair(10, 18), Pair(-5, -2), Pair(11, -29),
        Pair(19, 16), Pair(-10, 72), Pair(-6, 38), Pair(-4, 26), Pair(20, -7), Pair(5, 17), Pair(0, 47), Pair(5, -20),
        Pair(18, 10), Pair(10, 25), Pair(3, 13), Pair(-1, 23), Pair(4, 13), Pair(20, 16), Pair(16, -36), Pair(22, -64)
      },
      { // Piece 5
        Pair(4, 119), Pair(-5, 4), Pair(-13, -37), Pair(9, 72), Pair(-5, -32), Pair(-12, -129), Pair(19, 86), Pair(-2, 18),
        Pair(19, 102), Pair(-43, 6), Pair(9, -105), Pair(-35, -123), Pair(0, 0), Pair(61, -53), Pair(-82, -49), Pair(-21, -16),
        Pair(-49, -18), Pair(-25, 28), Pair(-30, 11), Pair(0, 0), Pair(137, -106), Pair(0, 0), Pair(4, 3), Pair(172, -17),
        Pair(76, 28), Pair(-63, 35), Pair(-135, 36), Pair(-47, -13), Pair(35, -64), Pair(99, -53), Pair(-158, 5), Pair(-104, 3),
        Pair(-87, 1), Pair(-31, 18), Pair(2, 23), Pair(-62, -7), Pair(-27, -17), Pair(-22, -13), Pair(-21, 7), Pair(-101, 19),
        Pair(54, -24), Pair(-17, 22), Pair(-9, 4), Pair(33, -15), Pair(9, 1), Pair(-9, 0), Pair(-17, 16), Pair(-6, 25),
        Pair(-36, 31), Pair(-5, 15), Pair(-18, 24), Pair(18, -10), Pair(2, -10), Pair(18, -12), Pair(-7, 14), Pair(8, -3),
        Pair(3, -18), Pair(-15, 27), Pair(-15, 20), Pair(50, -39), Pair(2, -22), Pair(19, -9), Pair(3, 1), Pair(3, 6)
      }
    }},
    {{ // Bucket 53
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(9, 21), Pair(-5, 15), Pair(20, 19), Pair(-15, 17), Pair(22, 16), Pair(0, 0), Pair(-40, 15), Pair(0, 13),
        Pair(1, 8), Pair(7, 11), Pair(18, 9), Pair(13, -4), Pair(9, 40), Pair(-18, 1), Pair(9, 9), Pair(-1, 8),
        Pair(3, 5), Pair(4, 5), Pair(7, 7), Pair(4, 3), Pair(7, 12), Pair(-9, 3), Pair(-1, 7), Pair(-2, 6),
        Pair(9, 5), Pair(6, 3), Pair(5, 3), Pair(1, -1), Pair(4, 5), Pair(-7, -1), Pair(0, 1), Pair(-2, 7),
        Pair(4, -1), Pair(7, 1), Pair(4, 0), Pair(5, 3), Pair(2, 4), Pair(-6, 2), Pair(-5, 2), Pair(-4, 3),
        Pair(4, 4), Pair(6, 1), Pair(4, -1), Pair(0, -1), Pair(5, 2), Pair(0, 0), Pair(-6, -1), Pair(-4, 5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-37, 49), Pair(-32, 49), Pair(-83, 81), Pair(-82, 36), Pair(13, 39), Pair(-57, 1), Pair(29, 91), Pair(-29, -24),
        Pair(-6, 63), Pair(-12, 36), Pair(-13, 47), Pair(-40, 64), Pair(-7, 45), Pair(0, 0), Pair(-26, 59), Pair(-8, 43),
        Pair(-1, 61), Pair(-11, 45), Pair(-10, 61), Pair(-1, 26), Pair(-252, 129), Pair(12, 73), Pair(-112, 104), Pair(-28, 23),
        Pair(16, 37), Pair(-3, 42), Pair(-10, 46), Pair(1, 53), Pair(-32, 35), Pair(10, 55), Pair(-25, 16), Pair(20, 49),
        Pair(4, 49), Pair(20, 46), Pair(-3, 53), Pair(-9, 53), Pair(-26, 45), Pair(-12, 48), Pair(4, 47), Pair(-2, 36),
        Pair(11, 41), Pair(0, 38), Pair(0, 49), Pair(-14, 50), Pair(-2, 56), Pair(-2, 42), Pair(-11, 56), Pair(-6, 44),
        Pair(2, 48), Pair(-11, 52), Pair(6, 35), Pair(-2, 46), Pair(-6, 45), Pair(-7, 47), Pair(9, 20), Pair(-7, 63),
        Pair(-17, 52), Pair(4, 43), Pair(-13, 49), Pair(1, 61), Pair(-2, 47), Pair(-2, 58), Pair(-12, 58), Pair(34, 1)
      },
      { // Piece 2
        Pair(-38, 76), Pair(29, 78), Pair(-84, 61), Pair(-82, 102), Pair(-135, 78), Pair(-109, 77), Pair(-186, 62), Pair(23, 92),
        Pair(0, 48), Pair(-16, 51), Pair(-4, 74), Pair(-81, 71), Pair(-64, 94), Pair(0, 0), Pair(-48, 97), Pair(-12, 53),
        Pair(-30, 58), Pair(-12, 66), Pair(-29, 72), Pair(-9, 78), Pair(-155, -79), Pair(15, 90), Pair(-56, -34), Pair(6, 56),
        Pair(6, 51), Pair(-26, 62), Pair(-8, 65), Pair(-16, 45), Pair(-35, 63), Pair(-26, 61), Pair(-14, 58), Pair(-16, 28),
        Pair(-14, 51), Pair(-3, 69), Pair(-17, 52), Pair(-6, 59), Pair(-42, 43), Pair(-2, 62), Pair(-32, 49), Pair(14, 57),
        Pair(-8, 63), Pair(-18, 54), Pair(-3, 61), Pair(-16, 48), Pair(-4, 59), Pair(-11, 44), Pair(-7, 62), Pair(-26, 37),
        Pair(-27, 51), Pair(3, 46), Pair(-28, 57), Pair(0, 58), Pair(-15, 44), Pair(0, 60), Pair(-16, 45), Pair(-16, 64),
        Pair(1, 51), Pair(-13, 51), Pair(5, 52), Pair(0, 41), Pair(2, 67), Pair(-13, 47), Pair(-25, 60), Pair(-28, 70)
      },
      { // Piece 3
        Pair(-34, 77), Pair(-39, 87), Pair(-41, 84), Pair(-15, 77), Pair(-4, 60), Pair(-40, 86), Pair(19, 63), Pair(-3, 63),
        Pair(1, 61), Pair(1, 66), Pair(-13, 74), Pair(-1, 70), Pair(-29, 81), Pair(0, 0), Pair(1, 58), Pair(-18, 64),
        Pair(18, 55), Pair(-1, 63), Pair(9, 62), Pair(-2, 66), Pair(-211, 48), Pair(30, 55), Pair(36, -55), Pair(-30, 71),
        Pair(12, 55), Pair(4, 70), Pair(0, 65), Pair(-3, 66), Pair(6, 59), Pair(12, 55), Pair(14, 54), Pair(5, 54),
        Pair(5, 61), Pair(15, 58), Pair(-17, 72), Pair(3, 60), Pair(-7, 51), Pair(5, 49), Pair(-10, 56), Pair(12, 57),
        Pair(9, 65), Pair(-3, 77), Pair(-2, 59), Pair(-4, 68), Pair(-5, 59), Pair(5, 54), Pair(21, 38), Pair(3, 70),
        Pair(16, 62), Pair(5, 57), Pair(-1, 59), Pair(4, 63), Pair(-1, 55), Pair(14, 49), Pair(13, 53), Pair(-8, 69),
        Pair(7, 64), Pair(5, 62), Pair(4, 63), Pair(4, 57), Pair(4, 54), Pair(4, 61), Pair(5, 62), Pair(4, 57)
      },
      { // Piece 4
        Pair(1, 94), Pair(18, 94), Pair(-39, 112), Pair(-12, 106), Pair(13, 51), Pair(63, -26), Pair(-23, 131), Pair(-9, 109),
        Pair(15, 92), Pair(2, 90), Pair(37, 65), Pair(27, 42), Pair(-9, 56), Pair(0, 0), Pair(-34, 169), Pair(13, 84),
        Pair(25, 48), Pair(9, 82), Pair(12, 76), Pair(19, 92), Pair(-72, 1), Pair(48, 36), Pair(15, 112), Pair(36, 67),
        Pair(11, 72), Pair(4, 91), Pair(9, 108), Pair(22, 69), Pair(10, 93), Pair(25, 58), Pair(24, 120), Pair(28, 73),
        Pair(8, 68), Pair(11, 86), Pair(14, 88), Pair(14, 109), Pair(-4, 116), Pair(32, 62), Pair(12, 115), Pair(26, 110),
        Pair(14, 76), Pair(9, 79), Pair(18, 67), Pair(3, 106), Pair(8, 87), Pair(20, 78), Pair(19, 111), Pair(42, 13),
        Pair(13, 77), Pair(12, 67), Pair(11, 81), Pair(9, 82), Pair(7, 97), Pair(18, 80), Pair(10, 106), Pair(52, 64),
        Pair(13, 77), Pair(26, 53), Pair(15, 58), Pair(11, 78), Pair(23, 62), Pair(10, 70), Pair(4, 105), Pair(15, 61)
      },
      { // Piece 5
        Pair(2, -30), Pair(51, -55), Pair(56, 33), Pair(26, -50), Pair(-112, -30), Pair(55, -86), Pair(-55, -41), Pair(-42, -49),
        Pair(122, -11), Pair(19, -29), Pair(-77, 1), Pair(97, -38), Pair(-59, -77), Pair(0, 0), Pair(47, -61), Pair(-33, -8),
        Pair(23, 1), Pair(-50, 16), Pair(19, -1), Pair(-90, 0), Pair(0, 0), Pair(-103, -50), Pair(0, 0), Pair(-45, -29),
        Pair(33, 8), Pair(-30, 11), Pair(-2, -17), Pair(-24, -31), Pair(-26, -40), Pair(19, -39), Pair(-68, -19), Pair(-101, -8),
        Pair(26, -23), Pair(-2, 2), Pair(29, -15), Pair(14, -12), Pair(-14, -21), Pair(-30, -15), Pair(7, -16), Pair(-43, 3),
        Pair(-27, -16), Pair(31, -14), Pair(6, -1), Pair(17, -1), Pair(-12, -5), Pair(11, -10), Pair(-7, -8), Pair(-21, 5),
        Pair(4, -11), Pair(-11, 1), Pair(2, 1), Pair(-3, 12), Pair(-6, 4), Pair(7, 3), Pair(-9, 3), Pair(0, 5),
        Pair(0, 0), Pair(-14, 7), Pair(-9, 13), Pair(4, -6), Pair(0, -14), Pair(-14, 8), Pair(-7, -10), Pair(9, -2)
      }
    }},
    {{ // Bucket 54
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(23, 11), Pair(21, 19), Pair(21, 2), Pair(-2, 19), Pair(-14, 13), Pair(-25, -4), Pair(0, 0), Pair(-13, -19),
        Pair(5, 10), Pair(18, 1), Pair(13, 6), Pair(-3, 2), Pair(3, -1), Pair(-32, 36), Pair(-10, 3), Pair(21, 8),
        Pair(2, 7), Pair(8, 3), Pair(10, 3), Pair(-3, 4), Pair(-4, 4), Pair(-3, 12), Pair(-3, -3), Pair(9, 13),
        Pair(6, 4), Pair(6, 3), Pair(2, 3), Pair(-2, 1), Pair(1, 3), Pair(1, 7), Pair(-4, -4), Pair(-1, 6),
        Pair(0, -2), Pair(3, -2), Pair(1, 0), Pair(1, 2), Pair(-2, 1), Pair(1, 6), Pair(-4, 2), Pair(-4, 5),
        Pair(1, 3), Pair(3, -1), Pair(0, -1), Pair(2, -1), Pair(0, 1), Pair(3, 0), Pair(0, 0), Pair(-7, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-47, 41), Pair(-110, 53), Pair(-24, 34), Pair(-150, 92), Pair(-80, 18), Pair(-16, 73), Pair(-25, -18), Pair(-13, 97),
        Pair(6, 33), Pair(-7, 22), Pair(-4, 24), Pair(6, 23), Pair(-15, 72), Pair(6, 27), Pair(0, 0), Pair(-59, -17),
        Pair(1, 19), Pair(2, 36), Pair(4, 34), Pair(-8, 32), Pair(3, 20), Pair(-410, 294), Pair(23, 65), Pair(-19, 113),
        Pair(-3, 21), Pair(-1, 28), Pair(2, 43), Pair(10, 30), Pair(8, 38), Pair(-32, 21), Pair(-6, 56), Pair(-5, 2),
        Pair(10, 22), Pair(-5, 28), Pair(8, 22), Pair(-2, 36), Pair(12, 29), Pair(-28, 43), Pair(18, 14), Pair(-16, 35),
        Pair(-2, 45), Pair(-4, 31), Pair(-1, 32), Pair(3, 36), Pair(-1, 28), Pair(-1, 33), Pair(-15, 38), Pair(-2, 43),
        Pair(-2, 30), Pair(-1, 29), Pair(-7, 25), Pair(-4, 31), Pair(-7, 28), Pair(-8, 26), Pair(13, 29), Pair(11, 17),
        Pair(-28, 64), Pair(0, 44), Pair(-4, 31), Pair(15, 21), Pair(-5, 37), Pair(1, 20), Pair(3, 45), Pair(-20, 20)
      },
      { // Piece 2
        Pair(-7, 62), Pair(-20, 68), Pair(-31, 79), Pair(-70, 67), Pair(-142, 107), Pair(-98, 84), Pair(157, 36), Pair(1, 0),
        Pair(-27, 59), Pair(-12, 80), Pair(-26, 47), Pair(-20, 83), Pair(-82, 68), Pair(-28, 89), Pair(0, 0), Pair(11, 27),
        Pair(4, 69), Pair(-51, 58), Pair(0, 58), Pair(-34, 50), Pair(-16, 79), Pair(-210, 16), Pair(14, 71), Pair(-8, -71),
        Pair(-22, 44), Pair(-5, 61), Pair(-27, 43), Pair(-10, 69), Pair(-7, 26), Pair(-56, 63), Pair(-4, 47), Pair(-13, 62),
        Pair(-6, 58), Pair(-20, 41), Pair(3, 48), Pair(-19, 33), Pair(-5, 54), Pair(-33, 38), Pair(4, 52), Pair(-21, 19),
        Pair(-14, 28), Pair(13, 57), Pair(-13, 34), Pair(-6, 53), Pair(-19, 39), Pair(3, 57), Pair(-5, 25), Pair(6, 55),
        Pair(10, 62), Pair(-12, 20), Pair(1, 56), Pair(-17, 36), Pair(-2, 56), Pair(-17, 49), Pair(11, 53), Pair(-11, 23),
        Pair(-20, 26), Pair(-19, 70), Pair(-14, 31), Pair(3, 46), Pair(-8, 32), Pair(11, 51), Pair(-12, 74), Pair(2, 71)
      },
      { // Piece 3
        Pair(7, 71), Pair(-23, 83), Pair(-29, 75), Pair(-46, 73), Pair(-35, 68), Pair(-44, 83), Pair(28, 60), Pair(-17, 66),
        Pair(1, 61), Pair(0, 59), Pair(0, 63), Pair(-24, 72), Pair(-8, 62), Pair(-24, 53), Pair(0, 0), Pair(-27, 67),
        Pair(-9, 58), Pair(-2, 67), Pair(17, 53), Pair(5, 65), Pair(37, 31), Pair(-31, 15), Pair(15, 48), Pair(257, -165),
        Pair(5, 58), Pair(9, 55), Pair(14, 47), Pair(-16, 65), Pair(-5, 62), Pair(-3, 47), Pair(-15, 59), Pair(1, 49),
        Pair(2, 57), Pair(-2, 51), Pair(6, 45), Pair(-4, 52), Pair(-9, 55), Pair(-7, 28), Pair(-18, 56), Pair(4, 28),
        Pair(4, 52), Pair(13, 52), Pair(-9, 59), Pair(0, 65), Pair(8, 45), Pair(7, 47), Pair(-14, 61), Pair(10, 26),
        Pair(15, 51), Pair(11, 46), Pair(15, 52), Pair(14, 47), Pair(16, 44), Pair(9, 46), Pair(13, 46), Pair(21, 31),
        Pair(11, 54), Pair(6, 58), Pair(4, 53), Pair(5, 54), Pair(3, 53), Pair(5, 49), Pair(-2, 41), Pair(-3, 51)
      },
      { // Piece 4
        Pair(-86, 140), Pair(-33, 120), Pair(-30, 120), Pair(42, 51), Pair(-18, 115), Pair(27, 28), Pair(-10, 96), Pair(24, 77),
        Pair(7, 59), Pair(0, 78), Pair(-4, 81), Pair(-29, 104), Pair(-12, 94), Pair(53, -34), Pair(0, 0), Pair(9, 55),
        Pair(10, 57), Pair(12, 62), Pair(-6, 83), Pair(6, 99), Pair(23, 55), Pair(-8, -123), Pair(41, 32), Pair(41, -43),
        Pair(13, 38), Pair(0, 78), Pair(-1, 77), Pair(-26, 122), Pair(6, 78), Pair(-9, 83), Pair(9, 42), Pair(8, 76),
        Pair(-2, 61), Pair(-18, 95), Pair(-5, 77), Pair(-10, 79), Pair(0, 84), Pair(7, 68), Pair(-1, 63), Pair(4, 79),
        Pair(2, 64), Pair(-5, 79), Pair(-1, 73), Pair(-4, 75), Pair(-4, 82), Pair(0, 83), Pair(29, 31), Pair(19, 39),
        Pair(-5, 58), Pair(-5, 81), Pair(-4, 61), Pair(-9, 81), Pair(-9, 71), Pair(-5, 80), Pair(7, 53), Pair(12, 66),
        Pair(-10, 56), Pair(-13, 56), Pair(2, 39), Pair(-1, 56), Pair(-1, 70), Pair(-13, 89), Pair(-1, 17), Pair(1, 101)
      },
      { // Piece 5
        Pair(-73, -48), Pair(59, -55), Pair(34, -26), Pair(-17, 9), Pair(48, -7), Pair(84, 13), Pair(123, 7), Pair(14, 43),
        Pair(-144, 39), Pair(121, -30), Pair(18, 41), Pair(65, 0), Pair(61, -26), Pair(-31, -74), Pair(0, 0), Pair(24, -44),
        Pair(53, 3), Pair(77, -8), Pair(16, 9), Pair(26, 2), Pair(-71, -8), Pair(0, 0), Pair(-22, -58), Pair(0, 0),
        Pair(-50, 12), Pair(25, 1), Pair(22, -17), Pair(13, -13), Pair(-76, -11), Pair(-51, -8), Pair(-37, -27), Pair(-66, -25),
        Pair(61, -42), Pair(64, -12), Pair(55, -13), Pair(29, -7), Pair(-11, -4), Pair(-4, -11), Pair(-35, -1), Pair(-90, 0),
        Pair(40, -8), Pair(23, -25), Pair(-2, -3), Pair(7, 2), Pair(2, 2), Pair(4, -4), Pair(-14, -4), Pair(-14, -1),
        Pair(1, 7), Pair(2, -4), Pair(18, -5), Pair(20, -3), Pair(-6, 8), Pair(14, -2), Pair(-11, 0), Pair(-6, 0),
        Pair(-10, 13), Pair(-15, 6), Pair(-8, 2), Pair(3, 4), Pair(6, -4), Pair(-4, 3), Pair(-7, 8), Pair(-2, -3)
      }
    }},
    {{ // Bucket 55
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-3, 18), Pair(24, 0), Pair(38, 0), Pair(10, 6), Pair(11, 9), Pair(21, 5), Pair(-46, 7), Pair(0, 0),
        Pair(6, 10), Pair(-2, 14), Pair(5, 7), Pair(1, 6), Pair(-3, 5), Pair(-11, 1), Pair(2, 4), Pair(1, -12),
        Pair(4, 7), Pair(4, 4), Pair(4, 7), Pair(-3, 4), Pair(-7, 1), Pair(-6, 0), Pair(-2, 6), Pair(4, -7),
        Pair(6, 3), Pair(4, -2), Pair(0, -1), Pair(-3, 2), Pair(-2, 5), Pair(1, 0), Pair(1, -1), Pair(-4, -1),
        Pair(1, -2), Pair(1, -5), Pair(-1, -1), Pair(-4, 0), Pair(3, -1), Pair(4, 1), Pair(2, 3), Pair(-1, 1),
        Pair(3, 3), Pair(1, -5), Pair(-1, -1), Pair(3, -5), Pair(0, 0), Pair(8, -1), Pair(2, 0), Pair(0, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-66, 48), Pair(29, 6), Pair(2, 1), Pair(33, 10), Pair(-87, 55), Pair(-97, 2), Pair(-30, 47), Pair(-47, -61),
        Pair(-25, 38), Pair(-2, 20), Pair(11, 23), Pair(9, 30), Pair(29, 25), Pair(28, 11), Pair(75, 4), Pair(0, 0),
        Pair(37, 3), Pair(6, 26), Pair(11, 35), Pair(0, 36), Pair(-9, 35), Pair(11, 29), Pair(-149, -38), Pair(6, 80),
        Pair(-11, 28), Pair(12, 21), Pair(8, 26), Pair(10, 32), Pair(8, 40), Pair(12, 48), Pair(-20, 31), Pair(17, 58),
        Pair(-6, 29), Pair(7, 10), Pair(6, 29), Pair(10, 31), Pair(9, 41), Pair(24, 36), Pair(-6, 34), Pair(4, 33),
        Pair(3, 20), Pair(4, 24), Pair(6, 23), Pair(2, 31), Pair(0, 34), Pair(3, 33), Pair(4, 46), Pair(-2, 47),
        Pair(2, 6), Pair(1, 14), Pair(-7, 26), Pair(-2, 30), Pair(1, 35), Pair(3, 34), Pair(-3, 36), Pair(5, 46),
        Pair(26, 9), Pair(-5, 16), Pair(2, 3), Pair(-7, 25), Pair(1, 21), Pair(-5, 36), Pair(-8, 24), Pair(21, 24)
      },
      { // Piece 2
        Pair(-50, 76), Pair(-39, 64), Pair(-47, 77), Pair(-63, 71), Pair(-140, 90), Pair(-76, 85), Pair(-57, 70), Pair(-12, 71),
        Pair(-38, 63), Pair(8, 53), Pair(3, 57), Pair(-69, 88), Pair(-22, 44), Pair(-15, 53), Pair(-36, 72), Pair(0, 0),
        Pair(-7, 62), Pair(-4, 57), Pair(-32, 76), Pair(-4, 66), Pair(1, 62), Pair(-21, 70), Pair(-19, -47), Pair(15, 85),
        Pair(2, 44), Pair(0, 48), Pair(-15, 56), Pair(10, 55), Pair(0, 60), Pair(-12, 48), Pair(-17, 57), Pair(-2, 53),
        Pair(-11, 44), Pair(-5, 50), Pair(-1, 61), Pair(3, 56), Pair(-2, 58), Pair(1, 53), Pair(-22, 67), Pair(-6, 68),
        Pair(-7, 54), Pair(0, 55), Pair(6, 46), Pair(-8, 54), Pair(1, 51), Pair(7, 58), Pair(-3, 46), Pair(4, 61),
        Pair(5, 48), Pair(7, 48), Pair(-3, 39), Pair(-5, 44), Pair(-5, 53), Pair(4, 42), Pair(8, 52), Pair(15, 33),
        Pair(6, 42), Pair(-22, 43), Pair(0, 44), Pair(0, 48), Pair(4, 56), Pair(-2, 55), Pair(-19, 51), Pair(-9, 82)
      },
      { // Piece 3
        Pair(10, 91), Pair(-11, 87), Pair(-27, 97), Pair(20, 84), Pair(-29, 96), Pair(-6, 71), Pair(10, 82), Pair(-91, 133),
        Pair(9, 80), Pair(6, 78), Pair(-2, 89), Pair(16, 88), Pair(0, 94), Pair(25, 85), Pair(12, 86), Pair(0, 0),
        Pair(19, 78), Pair(13, 76), Pair(-11, 89), Pair(4, 91), Pair(8, 78), Pair(-39, 93), Pair(11, -75), Pair(-44, 130),
        Pair(4, 85), Pair(5, 84), Pair(5, 77), Pair(17, 78), Pair(-9, 86), Pair(3, 87), Pair(-4, 81), Pair(-13, 96),
        Pair(17, 73), Pair(-6, 90), Pair(10, 79), Pair(9, 76), Pair(2, 72), Pair(12, 75), Pair(0, 54), Pair(-13, 64),
        Pair(7, 82), Pair(19, 70), Pair(9, 80), Pair(8, 76), Pair(-1, 68), Pair(8, 61), Pair(22, 64), Pair(1, 55),
        Pair(25, 73), Pair(3, 84), Pair(22, 71), Pair(8, 65), Pair(7, 69), Pair(17, 67), Pair(-14, 95), Pair(1, 68),
        Pair(13, 76), Pair(9, 81), Pair(9, 79), Pair(5, 76), Pair(10, 72), Pair(9, 66), Pair(-17, 86), Pair(-4, 77)
      },
      { // Piece 4
        Pair(-60, 173), Pair(-24, 164), Pair(34, 123), Pair(0, 172), Pair(-12, 165), Pair(-40, 213), Pair(141, 14), Pair(-114, 181),
        Pair(13, 136), Pair(7, 138), Pair(-2, 165), Pair(-39, 162), Pair(-12, 199), Pair(-22, 205), Pair(34, 182), Pair(0, 0),
        Pair(22, 138), Pair(-2, 163), Pair(-6, 152), Pair(6, 161), Pair(-7, 184), Pair(-46, 204), Pair(-68, 26), Pair(28, 89),
        Pair(18, 134), Pair(-4, 148), Pair(-2, 160), Pair(-16, 182), Pair(5, 154), Pair(-5, 163), Pair(-6, 152), Pair(1, 129),
        Pair(4, 153), Pair(4, 153), Pair(0, 158), Pair(1, 149), Pair(-1, 152), Pair(10, 144), Pair(4, 128), Pair(7, 108),
        Pair(1, 139), Pair(7, 127), Pair(8, 128), Pair(2, 126), Pair(2, 125), Pair(0, 145), Pair(5, 123), Pair(-10, 137),
        Pair(-5, 137), Pair(-2, 120), Pair(5, 114), Pair(5, 127), Pair(8, 120), Pair(5, 127), Pair(27, 83), Pair(8, 88),
        Pair(11, 80), Pair(1, 96), Pair(9, 117), Pair(6, 114), Pair(17, 111), Pair(2, 129), Pair(-26, 141), Pair(-44, 148)
      },
      { // Piece 5
        Pair(-41, 38), Pair(50, -28), Pair(134, -93), Pair(-48, -23), Pair(-96, 6), Pair(50, -69), Pair(-32, -31), Pair(7, 39),
        Pair(-128, 45), Pair(103, 6), Pair(-108, 6), Pair(-77, 9), Pair(35, 1), Pair(-141, -43), Pair(-71, -32), Pair(0, 0),
        Pair(-35, -45), Pair(-13, -8), Pair(-8, 7), Pair(9, -14), Pair(-44, -1), Pair(-86, 0), Pair(0, 0), Pair(78, -55),
        Pair(94, -35), Pair(47, -12), Pair(33, -17), Pair(0, -1), Pair(-3, -1), Pair(-63, -7), Pair(-53, 5), Pair(-46, -15),
        Pair(-7, -36), Pair(22, -11), Pair(53, -18), Pair(80, -20), Pair(-11, 0), Pair(-6, 5), Pair(-20, -15), Pair(-48, -4),
        Pair(55, -3), Pair(65, -23), Pair(11, -10), Pair(20, -2), Pair(21, -4), Pair(-2, 2), Pair(17, -5), Pair(-24, 0),
        Pair(11, 9), Pair(8, -9), Pair(5, 0), Pair(12, -7), Pair(6, -4), Pair(23, 2), Pair(2, 6), Pair(-4, 8),
        Pair(-2, -6), Pair(-13, 7), Pair(-1, -4), Pair(20, 1), Pair(10, -5), Pair(3, 10), Pair(2, 17), Pair(-12, 24)
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
        Pair(-19, 19), Pair(-81, 28), Pair(4, 0), Pair(-6, 51), Pair(66, 45), Pair(-79, 37), Pair(-37, 37), Pair(46, -30),
        Pair(-12, -76), Pair(-86, 16), Pair(10, 22), Pair(-13, 44), Pair(-91, 55), Pair(-34, 5), Pair(5, 26), Pair(-40, 15),
        Pair(-17, 34), Pair(8, 24), Pair(22, 10), Pair(1, 21), Pair(-25, 9), Pair(-44, 19), Pair(-17, 22), Pair(41, -4),
        Pair(-31, 5), Pair(4, 24), Pair(-7, 15), Pair(-32, 19), Pair(10, 4), Pair(27, 8), Pair(15, 6), Pair(8, 4),
        Pair(-41, 49), Pair(-28, 35), Pair(10, 11), Pair(7, 24), Pair(-11, 14), Pair(29, -1), Pair(-6, 8), Pair(13, 3),
        Pair(-21, 26), Pair(-3, 15), Pair(-42, 33), Pair(-12, -38), Pair(-40, 46), Pair(5, 11), Pair(-11, 21), Pair(-2, 24),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-41, 50), Pair(-3, 44), Pair(112, -19), Pair(7, 74), Pair(45, -8), Pair(-43, 1), Pair(7, 79), Pair(-3, -21),
        Pair(0, 0), Pair(10, -9), Pair(-56, 46), Pair(16, -22), Pair(-50, 40), Pair(-46, 22), Pair(25, 112), Pair(-98, -37),
        Pair(96, 52), Pair(-59, 57), Pair(94, 20), Pair(83, -24), Pair(121, -69), Pair(133, -28), Pair(119, 68), Pair(-8, 13),
        Pair(-66, 7), Pair(46, 22), Pair(85, 9), Pair(4, 96), Pair(9, -21), Pair(24, -14), Pair(13, 10), Pair(110, -51),
        Pair(-63, 96), Pair(-8, 35), Pair(36, 15), Pair(15, -7), Pair(49, 11), Pair(4, -8), Pair(33, -40), Pair(15, -30),
        Pair(21, -60), Pair(-6, -2), Pair(-48, 43), Pair(92, -47), Pair(-36, 63), Pair(3, -10), Pair(19, -6), Pair(31, -4),
        Pair(-28, 13), Pair(-70, -10), Pair(75, -76), Pair(-23, -44), Pair(-1, 15), Pair(51, -39), Pair(-24, -13), Pair(62, -52),
        Pair(-78, -18), Pair(-49, 2), Pair(-7, -12), Pair(-76, 30), Pair(10, -45), Pair(-15, -44), Pair(-143, 4), Pair(71, -71)
      },
      { // Piece 2
        Pair(-19, -85), Pair(186, -9), Pair(-7, -28), Pair(87, -64), Pair(12, -1), Pair(-33, -87), Pair(80, 6), Pair(-52, -153),
        Pair(0, 0), Pair(38, 65), Pair(200, -57), Pair(11, -6), Pair(62, -101), Pair(41, -9), Pair(249, -103), Pair(53, -51),
        Pair(142, -6), Pair(115, -22), Pair(19, 58), Pair(152, -26), Pair(2, 11), Pair(147, -52), Pair(124, -22), Pair(-17, -16),
        Pair(-25, -12), Pair(-5, 8), Pair(148, -21), Pair(-13, 19), Pair(188, -33), Pair(-55, 13), Pair(77, -61), Pair(27, -31),
        Pair(-58, 62), Pair(102, -56), Pair(9, 4), Pair(58, -13), Pair(30, 77), Pair(-5, -21), Pair(9, 38), Pair(59, -61),
        Pair(51, -40), Pair(46, -34), Pair(18, -55), Pair(-1, 18), Pair(33, 6), Pair(48, 8), Pair(76, -24), Pair(32, 49),
        Pair(14, -98), Pair(70, -49), Pair(-74, 8), Pair(47, -43), Pair(10, 14), Pair(124, -19), Pair(14, 28), Pair(-120, -14),
        Pair(83, -74), Pair(5, -11), Pair(34, -11), Pair(65, -70), Pair(37, -4), Pair(-6, 10), Pair(93, -38), Pair(-93, 79)
      },
      { // Piece 3
        Pair(59, -172), Pair(13, 89), Pair(-15, 45), Pair(-50, 53), Pair(-63, 73), Pair(-47, -13), Pair(-12, 49), Pair(-14, 32),
        Pair(0, 0), Pair(187, -9), Pair(117, -20), Pair(110, -18), Pair(170, -19), Pair(140, -18), Pair(42, 11), Pair(118, 2),
        Pair(-19, 19), Pair(6, 17), Pair(-31, 59), Pair(-32, 33), Pair(-91, 61), Pair(25, 42), Pair(70, 27), Pair(58, 49),
        Pair(10, 37), Pair(-22, 85), Pair(90, 46), Pair(117, 66), Pair(143, -37), Pair(-12, 41), Pair(-173, 113), Pair(-223, 100),
        Pair(-20, 47), Pair(41, 52), Pair(-51, 100), Pair(113, -15), Pair(-68, 53), Pair(65, -14), Pair(79, 134), Pair(30, -23),
        Pair(-2, 30), Pair(-8, 59), Pair(98, 9), Pair(-56, 52), Pair(-111, 64), Pair(5, 53), Pair(13, 49), Pair(71, 8),
        Pair(98, -19), Pair(34, 13), Pair(-102, 66), Pair(-25, -11), Pair(15, 48), Pair(-74, 25), Pair(1, -23), Pair(-2, 0),
        Pair(10, -2), Pair(34, 23), Pair(51, 25), Pair(27, 3), Pair(-21, 68), Pair(-14, 32), Pair(23, -2), Pair(-61, 69)
      },
      { // Piece 4
        Pair(-82, -209), Pair(100, -43), Pair(8, 30), Pair(-38, -31), Pair(29, 71), Pair(-58, -53), Pair(91, 18), Pair(-73, -43),
        Pair(0, 0), Pair(-33, 80), Pair(-47, 38), Pair(190, -102), Pair(-8, -31), Pair(-156, 26), Pair(-35, -34), Pair(47, -55),
        Pair(25, -2), Pair(-46, 83), Pair(40, -25), Pair(-73, 36), Pair(43, -35), Pair(-18, 40), Pair(117, -37), Pair(36, -14),
        Pair(-38, 18), Pair(13, 48), Pair(-12, 20), Pair(-102, 66), Pair(13, 27), Pair(48, -104), Pair(2, -51), Pair(-35, -138),
        Pair(-33, 12), Pair(-41, 124), Pair(-66, 4), Pair(23, -20), Pair(80, -212), Pair(24, -38), Pair(-73, 101), Pair(48, -14),
        Pair(-120, 37), Pair(-28, -57), Pair(-30, -5), Pair(-13, -52), Pair(-25, 28), Pair(-19, 67), Pair(50, -68), Pair(70, -55),
        Pair(41, -101), Pair(45, -107), Pair(31, -71), Pair(-32, -75), Pair(2, -37), Pair(61, -69), Pair(-105, 3), Pair(-10, -117),
        Pair(10, -42), Pair(-81, -52), Pair(-35, -8), Pair(-69, 28), Pair(106, -99), Pair(117, -114), Pair(-28, -27), Pair(-56, -30)
      },
      { // Piece 5
        Pair(-81, -197), Pair(-45, 81), Pair(61, 75), Pair(17, 49), Pair(11, -7), Pair(12, -26), Pair(-9, 28), Pair(20, 90),
        Pair(0, 0), Pair(0, 91), Pair(-40, 39), Pair(61, 2), Pair(71, 12), Pair(-85, -21), Pair(39, -43), Pair(2, -1),
        Pair(-48, 39), Pair(52, 47), Pair(71, 41), Pair(-127, 55), Pair(-122, 39), Pair(30, -68), Pair(-35, -9), Pair(-15, 10),
        Pair(53, -5), Pair(12, 59), Pair(16, 39), Pair(-47, 61), Pair(125, -36), Pair(12, 26), Pair(-17, -28), Pair(-158, 37),
        Pair(-155, 17), Pair(45, 63), Pair(48, 22), Pair(55, -23), Pair(87, -6), Pair(11, -18), Pair(29, -24), Pair(-71, -16),
        Pair(-219, 34), Pair(-11, 28), Pair(104, -21), Pair(-44, 13), Pair(78, -18), Pair(35, -20), Pair(8, -32), Pair(-41, -10),
        Pair(-36, 86), Pair(103, -14), Pair(50, 5), Pair(-73, 31), Pair(-46, -17), Pair(-15, -19), Pair(-11, -29), Pair(-8, -21),
        Pair(-124, 7), Pair(138, -12), Pair(-32, 3), Pair(-66, -2), Pair(-42, -33), Pair(-25, -29), Pair(33, -45), Pair(-19, -64)
      }
    }},
    {{ // Bucket 9
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-81, 28), Pair(1, 33), Pair(79, -1), Pair(-60, 28), Pair(-24, 49), Pair(-17, 55), Pair(-7, 22), Pair(40, 34),
        Pair(30, -22), Pair(-17, -58), Pair(-9, 1), Pair(-3, 38), Pair(-22, 8), Pair(14, 44), Pair(22, 15), Pair(41, 23),
        Pair(34, 14), Pair(13, -10), Pair(16, 30), Pair(-18, 29), Pair(1, 12), Pair(-23, 13), Pair(-36, 20), Pair(5, -3),
        Pair(-20, 35), Pair(-30, 17), Pair(-21, 24), Pair(-17, 10), Pair(-39, 32), Pair(-12, 23), Pair(-20, 26), Pair(-13, 15),
        Pair(2, -11), Pair(-38, 20), Pair(-62, 34), Pair(-7, 4), Pair(-1, 9), Pair(5, 4), Pair(7, 8), Pair(-4, 5),
        Pair(8, 19), Pair(-35, 4), Pair(-31, 19), Pair(-49, 12), Pair(2, 25), Pair(7, 8), Pair(-5, 20), Pair(-5, 15),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-28, -46), Pair(23, 120), Pair(-33, 23), Pair(18, -18), Pair(-24, -103), Pair(-19, 18), Pair(-60, -141), Pair(-12, -40),
        Pair(-16, 33), Pair(0, 0), Pair(130, -5), Pair(78, 62), Pair(56, 23), Pair(-9, 55), Pair(7, 72), Pair(52, 52),
        Pair(23, 60), Pair(23, 10), Pair(203, -23), Pair(31, 7), Pair(157, 12), Pair(10, -35), Pair(-171, 80), Pair(98, -6),
        Pair(56, 17), Pair(-21, -4), Pair(105, 17), Pair(36, 51), Pair(43, 61), Pair(-147, 93), Pair(-78, 33), Pair(96, 35),
        Pair(-11, 55), Pair(146, 54), Pair(21, 32), Pair(-36, 49), Pair(118, 3), Pair(-44, 43), Pair(15, -11), Pair(4, 28),
        Pair(-21, -23), Pair(-28, -6), Pair(27, -3), Pair(52, 21), Pair(62, -26), Pair(-2, 12), Pair(-21, 39), Pair(-22, 85),
        Pair(20, -15), Pair(120, -6), Pair(-116, 18), Pair(-5, -21), Pair(-11, -5), Pair(9, 28), Pair(-70, -35), Pair(51, -81),
        Pair(-47, -42), Pair(-97, 123), Pair(-18, -2), Pair(67, -33), Pair(-112, 23), Pair(30, -13), Pair(9, -89), Pair(9, -8)
      },
      { // Piece 2
        Pair(-95, -112), Pair(49, -98), Pair(149, -24), Pair(-16, 56), Pair(35, -87), Pair(22, 83), Pair(18, -66), Pair(56, 71),
        Pair(135, 42), Pair(0, 0), Pair(-10, 72), Pair(-6, -85), Pair(53, 20), Pair(34, -72), Pair(-84, 76), Pair(-68, -53),
        Pair(25, -12), Pair(92, 12), Pair(163, -53), Pair(-52, 96), Pair(128, -80), Pair(152, 36), Pair(116, -108), Pair(-25, 80),
        Pair(39, -1), Pair(92, -71), Pair(8, 56), Pair(121, -9), Pair(88, -27), Pair(245, -94), Pair(-26, 41), Pair(187, -85),
        Pair(133, -54), Pair(54, -18), Pair(113, -74), Pair(-65, 38), Pair(132, -32), Pair(22, 98), Pair(32, -6), Pair(29, 17),
        Pair(14, 67), Pair(3, -107), Pair(-29, 40), Pair(101, -100), Pair(12, 29), Pair(94, -13), Pair(137, -17), Pair(53, -67),
        Pair(109, -133), Pair(7, 37), Pair(-15, -33), Pair(-41, 10), Pair(4, -9), Pair(65, -52), Pair(57, -44), Pair(-50, 113),
        Pair(-75, 46), Pair(66, -132), Pair(23, 49), Pair(31, -71), Pair(34, 29), Pair(63, -13), Pair(135, -88), Pair(104, -26)
      },
      { // Piece 3
        Pair(26, 98), Pair(32, -178), Pair(180, 35), Pair(-59, 32), Pair(-59, 44), Pair(-26, 4), Pair(94, 5), Pair(8, 37),
        Pair(13, 41), Pair(0, 0), Pair(37, 10), Pair(111, -31), Pair(229, -34), Pair(-38, -8), Pair(-110, 27), Pair(38, 8),
        Pair(-20, 62), Pair(22, -8), Pair(71, 51), Pair(104, -32), Pair(-80, 39), Pair(4, -13), Pair(99, 23), Pair(34, 30),
        Pair(62, 21), Pair(116, -11), Pair(3, 56), Pair(11, 62), Pair(-58, 70), Pair(-21, 5), Pair(80, -3), Pair(8, 18),
        Pair(-67, 144), Pair(75, 0), Pair(18, 25), Pair(-47, 21), Pair(108, -45), Pair(42, 23), Pair(-15, 30), Pair(-72, 66),
        Pair(-64, 88), Pair(-25, 30), Pair(57, 3), Pair(132, -15), Pair(-64, 43), Pair(-56, 55), Pair(-61, 125), Pair(-54, -25),
        Pair(71, 7), Pair(-28, 2), Pair(19, 45), Pair(79, 10), Pair(75, -18), Pair(4, 11), Pair(107, -40), Pair(23, -20),
        Pair(18, 18), Pair(10, 5), Pair(-28, 20), Pair(-22, 52), Pair(9, 15), Pair(2, 3), Pair(-41, 46), Pair(-29, 29)
      },
      { // Piece 4
        Pair(59, -171), Pair(-77, -73), Pair(67, -78), Pair(147, 31), Pair(-26, -24), Pair(-35, -89), Pair(-63, -102), Pair(38, -21),
        Pair(23, -15), Pair(0, 0), Pair(-12, 32), Pair(-36, -8), Pair(29, -46), Pair(55, -120), Pair(-81, -107), Pair(25, -95),
        Pair(64, -23), Pair(40, 2), Pair(-62, 20), Pair(93, 46), Pair(-61, 17), Pair(-25, -5), Pair(-64, -21), Pair(-84, -12),
        Pair(74, -54), Pair(-96, 155), Pair(-65, 61), Pair(-62, 60), Pair(0, 8), Pair(113, -23), Pair(-52, -12), Pair(61, -125),
        Pair(18, -51), Pair(-36, 11), Pair(8, 78), Pair(50, -36), Pair(-3, 49), Pair(-25, -9), Pair(35, -39), Pair(-101, -22),
        Pair(174, -245), Pair(-44, 52), Pair(-2, 52), Pair(8, -37), Pair(66, -92), Pair(-72, -15), Pair(-32, 131), Pair(-81, 10),
        Pair(-30, 41), Pair(-60, 96), Pair(-50, 63), Pair(-6, 0), Pair(41, -26), Pair(62, -76), Pair(-46, 45), Pair(-42, -41),
        Pair(31, -171), Pair(-59, 54), Pair(58, -193), Pair(-62, 67), Pair(-102, 54), Pair(-99, 12), Pair(32, -35), Pair(95, 10)
      },
      { // Piece 5
        Pair(30, 205), Pair(34, -20), Pair(64, 33), Pair(97, 123), Pair(-17, -63), Pair(-5, -1), Pair(-10, -73), Pair(1, 18),
        Pair(3, 139), Pair(0, 0), Pair(92, 69), Pair(-30, 81), Pair(83, -54), Pair(4, -1), Pair(-34, -5), Pair(-8, -56),
        Pair(23, 109), Pair(31, 23), Pair(104, 6), Pair(20, 52), Pair(66, -20), Pair(22, -33), Pair(-26, -41), Pair(-26, 31),
        Pair(41, 116), Pair(86, -10), Pair(71, 19), Pair(112, -46), Pair(57, -41), Pair(132, -55), Pair(-48, -29), Pair(-46, 3),
        Pair(-12, 46), Pair(114, -35), Pair(56, 35), Pair(100, -10), Pair(70, -15), Pair(-123, -17), Pair(-86, -12), Pair(-8, -26),
        Pair(10, 28), Pair(-74, -26), Pair(18, 4), Pair(-12, -19), Pair(-93, -5), Pair(-25, -37), Pair(-102, 0), Pair(-146, -57),
        Pair(96, 35), Pair(96, 7), Pair(0, 16), Pair(-57, -12), Pair(-5, -34), Pair(-162, -8), Pair(-3, -47), Pair(-67, -41),
        Pair(-15, 97), Pair(16, -3), Pair(39, 42), Pair(23, -15), Pair(-67, -53), Pair(-151, -21), Pair(-70, -19), Pair(-122, -31)
      }
    }},
    {{ // Bucket 10
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(4, 0), Pair(79, -1), Pair(-26, 29), Pair(96, -37), Pair(-62, 25), Pair(42, 48), Pair(-6, 37), Pair(2, -5),
        Pair(-28, 17), Pair(-1, -3), Pair(-42, -73), Pair(-30, 9), Pair(-39, 38), Pair(-64, 62), Pair(-171, 35), Pair(76, -21),
        Pair(2, 0), Pair(-12, 30), Pair(-64, -5), Pair(0, 42), Pair(1, 14), Pair(19, 4), Pair(7, 2), Pair(11, 14),
        Pair(-10, 20), Pair(-4, 11), Pair(-41, 17), Pair(-14, 19), Pair(-56, 25), Pair(-5, 14), Pair(-34, 19), Pair(-5, 5),
        Pair(-4, 16), Pair(-24, 14), Pair(-16, 13), Pair(-48, 14), Pair(-15, 7), Pair(5, 2), Pair(-8, 16), Pair(11, 3),
        Pair(-22, 17), Pair(-20, 18), Pair(-2, -19), Pair(14, -18), Pair(-10, 11), Pair(-9, 18), Pair(-21, 16), Pair(-2, 12),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(158, -18), Pair(44, 64), Pair(-4, -16), Pair(19, 78), Pair(123, 28), Pair(24, 28), Pair(-10, -83), Pair(3, 7),
        Pair(-4, 68), Pair(35, -20), Pair(0, 0), Pair(81, -32), Pair(74, 115), Pair(-60, 62), Pair(13, -51), Pair(-123, -126),
        Pair(11, 23), Pair(-39, 67), Pair(103, 31), Pair(8, 75), Pair(47, 49), Pair(61, 2), Pair(89, 11), Pair(11, 23),
        Pair(85, -12), Pair(-19, 73), Pair(-57, 115), Pair(183, 7), Pair(-23, 85), Pair(-81, 56), Pair(-32, 40), Pair(-16, 41),
        Pair(19, 57), Pair(-35, 75), Pair(3, 32), Pair(52, 43), Pair(10, 83), Pair(124, 31), Pair(11, 48), Pair(-9, 103),
        Pair(16, 4), Pair(-7, 7), Pair(88, 26), Pair(-19, 79), Pair(-10, 47), Pair(44, 1), Pair(86, -76), Pair(-39, 32),
        Pair(92, 10), Pair(-63, 51), Pair(104, -25), Pair(-13, 40), Pair(29, 71), Pair(108, -46), Pair(-26, -31), Pair(-13, -2),
        Pair(-79, -32), Pair(-34, 0), Pair(-83, 78), Pair(25, -39), Pair(-76, 0), Pair(-71, -17), Pair(37, -102), Pair(1, 45)
      },
      { // Piece 2
        Pair(-15, 70), Pair(23, -21), Pair(-16, -10), Pair(256, -17), Pair(-4, 22), Pair(105, -14), Pair(-17, -24), Pair(-26, -91),
        Pair(161, -31), Pair(-147, 194), Pair(0, 0), Pair(28, 14), Pair(124, -35), Pair(24, 52), Pair(37, -54), Pair(95, 55),
        Pair(176, -6), Pair(151, -44), Pair(0, 101), Pair(152, 27), Pair(66, 44), Pair(131, -61), Pair(87, -4), Pair(47, -33),
        Pair(7, 17), Pair(36, 49), Pair(154, 4), Pair(90, 33), Pair(193, -11), Pair(241, -27), Pair(122, 2), Pair(-34, 74),
        Pair(-4, 23), Pair(117, 20), Pair(0, 82), Pair(128, -49), Pair(56, 84), Pair(121, 6), Pair(-13, 65), Pair(49, -40),
        Pair(13, -7), Pair(20, -10), Pair(63, -7), Pair(3, 56), Pair(56, -57), Pair(91, 37), Pair(123, -24), Pair(94, -2),
        Pair(57, -29), Pair(78, -82), Pair(-15, -4), Pair(-34, -44), Pair(32, 48), Pair(45, 20), Pair(60, 2), Pair(-21, 47),
        Pair(-77, -16), Pair(-62, -26), Pair(1, -25), Pair(5, 8), Pair(76, -41), Pair(-37, 67), Pair(62, -17), Pair(106, 25)
      },
      { // Piece 3
        Pair(34, 65), Pair(-79, 131), Pair(127, -139), Pair(210, 56), Pair(30, 10), Pair(50, -13), Pair(51, 60), Pair(97, 9),
        Pair(-4, 57), Pair(39, 38), Pair(0, 0), Pair(25, 30), Pair(-27, 32), Pair(43, 28), Pair(135, -3), Pair(89, 5),
        Pair(28, 60), Pair(-11, 49), Pair(78, -7), Pair(53, 22), Pair(-114, 76), Pair(33, 51), Pair(-31, 63), Pair(-49, 140),
        Pair(-36, 72), Pair(-14, 46), Pair(79, 4), Pair(17, 40), Pair(-32, 87), Pair(-100, 34), Pair(56, -10), Pair(19, -1),
        Pair(35, 25), Pair(67, 28), Pair(28, 16), Pair(-39, 86), Pair(53, 56), Pair(28, 43), Pair(69, 76), Pair(33, 59),
        Pair(3, 22), Pair(62, 19), Pair(71, 10), Pair(63, 15), Pair(38, -44), Pair(40, 25), Pair(-24, 2), Pair(-13, 127),
        Pair(-88, 50), Pair(26, 16), Pair(28, 25), Pair(-61, 69), Pair(100, -47), Pair(-93, 87), Pair(-28, 91), Pair(-92, 29),
        Pair(-48, 45), Pair(44, 1), Pair(27, 6), Pair(-3, 86), Pair(58, 32), Pair(-20, 33), Pair(-28, -11), Pair(-5, 16)
      },
      { // Piece 4
        Pair(-82, -47), Pair(-18, -56), Pair(-121, -156), Pair(20, -28), Pair(82, 42), Pair(60, 31), Pair(-71, -109), Pair(10, -23),
        Pair(39, -87), Pair(-66, 72), Pair(0, 0), Pair(-22, -19), Pair(-26, -3), Pair(45, -97), Pair(31, 51), Pair(17, -49),
        Pair(60, -106), Pair(13, 5), Pair(-6, 30), Pair(-4, 114), Pair(37, -17), Pair(68, -9), Pair(-51, -31), Pair(-35, -105),
        Pair(40, -60), Pair(-118, 148), Pair(0, 13), Pair(-17, 0), Pair(11, 50), Pair(72, -58), Pair(82, -78), Pair(-35, -36),
        Pair(26, -138), Pair(4, -13), Pair(23, -42), Pair(-69, 50), Pair(-91, 66), Pair(79, -71), Pair(-28, 15), Pair(9, 86),
        Pair(-37, 98), Pair(-83, -46), Pair(33, -62), Pair(-8, -101), Pair(-4, 29), Pair(-3, -46), Pair(82, -123), Pair(108, 46),
        Pair(-84, -35), Pair(2, -27), Pair(45, -99), Pair(-51, -27), Pair(-5, 38), Pair(30, -51), Pair(48, -93), Pair(80, -9),
        Pair(-14, -1), Pair(-26, 18), Pair(-3, -65), Pair(-34, -11), Pair(8, -126), Pair(-161, -16), Pair(-59, 50), Pair(-28, -19)
      },
      { // Piece 5
        Pair(13, 163), Pair(102, 86), Pair(-11, 39), Pair(-36, 67), Pair(-21, 75), Pair(29, 30), Pair(27, 83), Pair(6, 70),
        Pair(-12, 190), Pair(16, 129), Pair(0, 0), Pair(34, 95), Pair(-21, -1), Pair(-7, 13), Pair(-36, -57), Pair(14, -6),
        Pair(60, 65), Pair(-10, 103), Pair(21, 27), Pair(204, 23), Pair(-19, 20), Pair(146, -29), Pair(92, -11), Pair(24, -23),
        Pair(119, 38), Pair(158, 60), Pair(65, 11), Pair(140, 7), Pair(87, -25), Pair(55, -47), Pair(-107, -18), Pair(8, -43),
        Pair(23, 14), Pair(44, 47), Pair(11, -23), Pair(-99, 18), Pair(-85, -17), Pair(31, -39), Pair(-7, -29), Pair(-17, -49),
        Pair(-226, 42), Pair(-24, 56), Pair(44, -47), Pair(1, -15), Pair(8, -26), Pair(-110, -20), Pair(-9, -25), Pair(-136, -62),
        Pair(-84, 71), Pair(145, -39), Pair(4, -13), Pair(-17, -10), Pair(-11, -54), Pair(-39, -22), Pair(-25, -37), Pair(-55, -21),
        Pair(-17, -50), Pair(16, 30), Pair(-100, -53), Pair(-72, 24), Pair(-76, -15), Pair(-94, -55), Pair(-38, -51), Pair(-34, -45)
      }
    }},
    {{ // Bucket 11
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-6, 51), Pair(-60, 28), Pair(96, -37), Pair(54, -12), Pair(-67, 8), Pair(-27, 23), Pair(74, -13), Pair(-149, 78),
        Pair(46, 11), Pair(-106, 42), Pair(43, -2), Pair(-37, -42), Pair(0, -14), Pair(58, 28), Pair(-14, 60), Pair(-43, 36),
        Pair(-13, 22), Pair(23, 2), Pair(28, 24), Pair(-1, 7), Pair(5, 26), Pair(-10, 18), Pair(-20, 23), Pair(11, -1),
        Pair(5, 21), Pair(-5, 7), Pair(20, 13), Pair(10, -17), Pair(-26, 20), Pair(19, -4), Pair(-20, 5), Pair(-12, 14),
        Pair(19, 9), Pair(-21, 20), Pair(16, -17), Pair(-36, 31), Pair(-8, 11), Pair(-6, 14), Pair(9, 6), Pair(7, -4),
        Pair(25, 0), Pair(0, -3), Pair(-1, -13), Pair(-59, -2), Pair(-3, 4), Pair(-2, 6), Pair(-7, 11), Pair(7, 0),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-81, -61), Pair(22, 6), Pair(19, 75), Pair(-64, -86), Pair(35, 32), Pair(64, 113), Pair(-17, -65), Pair(-1, -2),
        Pair(18, 76), Pair(31, 88), Pair(-106, 28), Pair(0, 0), Pair(23, 26), Pair(-44, 63), Pair(31, 79), Pair(-72, 66),
        Pair(-33, 6), Pair(89, 25), Pair(29, 52), Pair(128, 26), Pair(120, 75), Pair(136, -45), Pair(77, 100), Pair(71, -21),
        Pair(-76, 70), Pair(3, 31), Pair(105, 60), Pair(157, 4), Pair(75, 55), Pair(102, 14), Pair(28, 6), Pair(7, 29),
        Pair(55, 72), Pair(59, 86), Pair(29, 43), Pair(96, 72), Pair(56, 48), Pair(32, 37), Pair(81, 22), Pair(82, 30),
        Pair(-39, 101), Pair(-24, -13), Pair(24, -37), Pair(71, 49), Pair(3, -2), Pair(18, -5), Pair(35, 21), Pair(9, 44),
        Pair(-15, -56), Pair(-4, -72), Pair(10, 14), Pair(-16, 8), Pair(-2, 63), Pair(72, 9), Pair(-39, 22), Pair(16, 82),
        Pair(-10, -8), Pair(-16, -63), Pair(113, 88), Pair(-72, 37), Pair(-10, -10), Pair(-36, 6), Pair(37, -39), Pair(6, -59)
      },
      { // Piece 2
        Pair(110, -12), Pair(-20, -14), Pair(32, 5), Pair(-195, -74), Pair(-4, -17), Pair(-62, 2), Pair(11, -85), Pair(-56, -91),
        Pair(-55, 83), Pair(90, -49), Pair(-62, 36), Pair(0, 0), Pair(141, 25), Pair(83, -93), Pair(91, 44), Pair(-42, -79),
        Pair(22, -14), Pair(42, 93), Pair(109, -33), Pair(195, 33), Pair(114, -36), Pair(110, 54), Pair(39, -16), Pair(223, -22),
        Pair(81, 92), Pair(106, -9), Pair(7, 97), Pair(26, -54), Pair(2, 87), Pair(111, -23), Pair(58, 78), Pair(93, -30),
        Pair(83, -23), Pair(57, -12), Pair(41, -24), Pair(27, 31), Pair(59, -51), Pair(-36, 85), Pair(52, -13), Pair(102, 103),
        Pair(131, -25), Pair(-17, -7), Pair(110, 6), Pair(32, -30), Pair(-27, 23), Pair(-18, -11), Pair(80, 25), Pair(84, -23),
        Pair(-107, 11), Pair(88, -27), Pair(-6, -25), Pair(-37, 102), Pair(11, -18), Pair(-36, 10), Pair(21, -22), Pair(32, 8),
        Pair(21, -25), Pair(-6, -25), Pair(24, 16), Pair(116, -45), Pair(-16, 41), Pair(68, -38), Pair(31, -130), Pair(113, -72)
      },
      { // Piece 3
        Pair(14, 79), Pair(-35, 71), Pair(36, 41), Pair(-30, -77), Pair(116, 115), Pair(-68, 75), Pair(62, 51), Pair(83, 73),
        Pair(18, 38), Pair(56, 40), Pair(13, 42), Pair(0, 0), Pair(65, 8), Pair(5, 16), Pair(-135, 55), Pair(46, 51),
        Pair(40, 12), Pair(12, 55), Pair(17, 81), Pair(80, -10), Pair(-38, 67), Pair(36, 53), Pair(43, 52), Pair(-10, 41),
        Pair(29, 54), Pair(206, 24), Pair(116, 2), Pair(-26, 63), Pair(-88, 71), Pair(39, 76), Pair(88, 10), Pair(116, 26),
        Pair(60, 9), Pair(-92, 38), Pair(58, 89), Pair(8, 11), Pair(-88, 60), Pair(15, 54), Pair(99, 87), Pair(-11, 75),
        Pair(-26, 64), Pair(-214, 140), Pair(-31, 76), Pair(15, 16), Pair(16, 52), Pair(17, 9), Pair(-26, 78), Pair(-143, 110),
        Pair(35, -21), Pair(-40, 28), Pair(-138, 68), Pair(58, -2), Pair(-4, 47), Pair(-70, 42), Pair(-108, 79), Pair(-18, 39),
        Pair(-33, 57), Pair(-25, 20), Pair(18, 33), Pair(1, 50), Pair(39, 29), Pair(-38, 60), Pair(5, 65), Pair(-128, -2)
      },
      { // Piece 4
        Pair(11, 105), Pair(-46, -6), Pair(-55, 24), Pair(-134, -151), Pair(15, -20), Pair(-17, -16), Pair(-42, -33), Pair(-64, -59),
        Pair(-5, 82), Pair(-57, -22), Pair(-64, 56), Pair(0, 0), Pair(67, -40), Pair(49, 49), Pair(-37, -85), Pair(54, -78),
        Pair(57, 2), Pair(-76, 25), Pair(132, -69), Pair(8, -64), Pair(-5, -6), Pair(100, -1), Pair(38, 51), Pair(-66, -53),
        Pair(78, -51), Pair(-1, 19), Pair(57, -54), Pair(21, -5), Pair(-44, 27), Pair(58, -67), Pair(-12, 87), Pair(37, 94),
        Pair(-79, 26), Pair(-66, 45), Pair(26, 11), Pair(38, -6), Pair(0, 84), Pair(-107, 132), Pair(18, -56), Pair(18, -26),
        Pair(-78, -6), Pair(-81, 37), Pair(39, -17), Pair(-46, 74), Pair(-4, 63), Pair(-6, 39), Pair(12, 18), Pair(-46, -26),
        Pair(12, -120), Pair(-101, 62), Pair(-28, 24), Pair(-82, 108), Pair(-76, 67), Pair(-12, 57), Pair(-26, -86), Pair(29, -33),
        Pair(81, -47), Pair(130, -42), Pair(-14, 43), Pair(46, -109), Pair(-12, -44), Pair(-79, -110), Pair(-17, -71), Pair(12, -23)
      },
      { // Piece 5
        Pair(6, 94), Pair(41, 150), Pair(-1, 54), Pair(96, -56), Pair(-12, 54), Pair(-2, 85), Pair(-6, -46), Pair(7, 108),
        Pair(-4, -3), Pair(-11, 34), Pair(166, 67), Pair(0, 0), Pair(-27, 100), Pair(1, 31), Pair(0, -45), Pair(21, 66),
        Pair(-8, 68), Pair(9, 27), Pair(74, 41), Pair(68, 57), Pair(78, 28), Pair(21, 3), Pair(-10, -17), Pair(-15, 4),
        Pair(94, -3), Pair(89, -20), Pair(131, 13), Pair(88, 29), Pair(180, -24), Pair(19, -35), Pair(59, -6), Pair(61, -56),
        Pair(-58, 53), Pair(-30, 27), Pair(-20, 44), Pair(36, 34), Pair(194, -39), Pair(65, -29), Pair(-102, 24), Pair(-132, -17),
        Pair(49, -40), Pair(63, -41), Pair(44, -25), Pair(-3, -36), Pair(-68, -30), Pair(-23, -18), Pair(-76, -31), Pair(-76, -34),
        Pair(80, -66), Pair(-56, -41), Pair(-51, 35), Pair(-140, 19), Pair(-100, 3), Pair(-50, -27), Pair(-17, -33), Pair(10, -68),
        Pair(131, -130), Pair(-11, -15), Pair(-63, 19), Pair(-14, -41), Pair(-195, 36), Pair(-35, -46), Pair(-68, -42), Pair(-23, -43)
      }
    }},
    {{ // Bucket 12
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(66, 45), Pair(-24, 49), Pair(-62, 25), Pair(-67, 8), Pair(21, 11), Pair(51, -2), Pair(-45, 49), Pair(91, 11),
        Pair(-70, 62), Pair(-33, 19), Pair(-120, 72), Pair(-12, 23), Pair(113, -70), Pair(83, 1), Pair(19, 39), Pair(0, 14),
        Pair(-14, -5), Pair(-16, 4), Pair(-16, 36), Pair(26, 27), Pair(14, -8), Pair(5, 34), Pair(41, -13), Pair(-6, 9),
        Pair(22, 5), Pair(26, 15), Pair(4, 18), Pair(18, 4), Pair(-33, 15), Pair(-12, 10), Pair(8, 0), Pair(-20, 11),
        Pair(36, -22), Pair(11, -9), Pair(7, 15), Pair(-11, 3), Pair(-8, 4), Pair(-11, 14), Pair(6, -1), Pair(0, 2),
        Pair(-3, 5), Pair(-1, -3), Pair(-31, 24), Pair(-93, 63), Pair(-6, -11), Pair(-18, 18), Pair(-24, 17), Pair(-14, 1),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(33, 12), Pair(-73, 72), Pair(54, -26), Pair(118, 59), Pair(-9, 35), Pair(146, 41), Pair(20, 45), Pair(-5, -7),
        Pair(-184, -40), Pair(-127, 170), Pair(128, -31), Pair(100, 82), Pair(0, 0), Pair(-45, 78), Pair(51, 72), Pair(9, -43),
        Pair(83, 112), Pair(10, 29), Pair(51, 34), Pair(-2, 52), Pair(58, 48), Pair(63, 27), Pair(75, -45), Pair(14, 5),
        Pair(-132, 55), Pair(154, -21), Pair(-81, 90), Pair(73, 69), Pair(174, 1), Pair(40, 36), Pair(-3, 21), Pair(173, -10),
        Pair(-101, -92), Pair(-35, -79), Pair(92, 0), Pair(11, 43), Pair(-69, 97), Pair(-7, 27), Pair(-24, 22), Pair(77, 24),
        Pair(-48, -25), Pair(-128, 5), Pair(-64, 2), Pair(27, 9), Pair(164, -60), Pair(-26, 2), Pair(118, 15), Pair(140, -109),
        Pair(27, -5), Pair(-79, -49), Pair(81, -61), Pair(-45, -4), Pair(37, -13), Pair(34, 39), Pair(117, 49), Pair(-16, -51),
        Pair(-42, -26), Pair(-40, -71), Pair(-4, 88), Pair(159, -54), Pair(-122, -12), Pair(-2, -43), Pair(95, 43), Pair(-7, -2)
      },
      { // Piece 2
        Pair(92, 29), Pair(-75, -65), Pair(-20, -5), Pair(133, -49), Pair(26, 22), Pair(70, -48), Pair(-27, -64), Pair(5, -12),
        Pair(27, -1), Pair(21, 45), Pair(-8, -26), Pair(148, 94), Pair(0, 0), Pair(-27, 80), Pair(-17, -6), Pair(125, 28),
        Pair(-111, 73), Pair(21, -35), Pair(-16, 68), Pair(132, -43), Pair(-42, 52), Pair(-38, -11), Pair(42, 27), Pair(-1, -53),
        Pair(24, -9), Pair(-85, 87), Pair(73, -26), Pair(-118, 64), Pair(129, -63), Pair(64, -29), Pair(96, -46), Pair(12, 49),
        Pair(-33, 52), Pair(130, -36), Pair(52, 46), Pair(40, -6), Pair(115, -13), Pair(49, -13), Pair(92, -27), Pair(-5, 1),
        Pair(106, -26), Pair(14, -43), Pair(46, -66), Pair(3, -44), Pair(97, -5), Pair(120, -17), Pair(72, -65), Pair(23, 35),
        Pair(-121, 110), Pair(-22, -14), Pair(199, -87), Pair(-28, -33), Pair(33, -40), Pair(10, 7), Pair(41, 0), Pair(-116, -10),
        Pair(171, -104), Pair(77, -11), Pair(-14, -60), Pair(-112, -29), Pair(-62, -35), Pair(-7, -67), Pair(139, -118), Pair(-135, 24)
      },
      { // Piece 3
        Pair(-105, 64), Pair(37, -17), Pair(-4, 26), Pair(30, 52), Pair(-91, -83), Pair(123, 7), Pair(65, -18), Pair(41, 33),
        Pair(-6, 14), Pair(-69, 18), Pair(-25, 1), Pair(62, -18), Pair(0, 0), Pair(110, -20), Pair(68, 13), Pair(8, -6),
        Pair(32, 64), Pair(15, -20), Pair(-2, -10), Pair(80, -42), Pair(103, -27), Pair(-21, -16), Pair(-79, -2), Pair(-15, 85),
        Pair(-24, 7), Pair(67, -20), Pair(4, 53), Pair(84, 30), Pair(95, -27), Pair(16, 63), Pair(-50, 58), Pair(33, 65),
        Pair(132, -37), Pair(10, 48), Pair(-41, 9), Pair(-87, -17), Pair(0, 33), Pair(75, -46), Pair(-41, 101), Pair(-122, 59),
        Pair(68, -47), Pair(77, 17), Pair(53, 82), Pair(91, 35), Pair(-13, 34), Pair(-65, 30), Pair(-6, 14), Pair(-35, -24),
        Pair(109, -9), Pair(49, -1), Pair(-31, 0), Pair(19, -48), Pair(55, -7), Pair(2, 92), Pair(-70, -4), Pair(-37, 24),
        Pair(-30, 27), Pair(7, -23), Pair(61, -14), Pair(44, -37), Pair(-22, 5), Pair(-33, 8), Pair(21, 36), Pair(29, -26)
      },
      { // Piece 4
        Pair(-30, -52), Pair(72, 61), Pair(40, 78), Pair(-8, -19), Pair(-163, -109), Pair(-18, -65), Pair(-63, -97), Pair(-31, -38),
        Pair(2, -30), Pair(-35, 35), Pair(46, -63), Pair(34, -104), Pair(0, 0), Pair(133, -104), Pair(-60, -61), Pair(-58, 36),
        Pair(-54, 62), Pair(67, 29), Pair(-28, 16), Pair(-37, -38), Pair(-16, -24), Pair(29, 4), Pair(108, 58), Pair(29, 13),
        Pair(-91, -104), Pair(-9, 41), Pair(63, -7), Pair(30, -12), Pair(-7, 12), Pair(-7, -60), Pair(-3, 35), Pair(-4, 24),
        Pair(-126, 60), Pair(45, -49), Pair(31, 29), Pair(124, -100), Pair(133, -90), Pair(23, 55), Pair(112, -119), Pair(51, -139),
        Pair(-38, -76), Pair(-96, 52), Pair(-13, 27), Pair(97, -39), Pair(-91, 75), Pair(-70, -7), Pair(19, -86), Pair(-80, -47),
        Pair(-98, -42), Pair(16, -92), Pair(-15, -60), Pair(31, -27), Pair(-61, -33), Pair(-54, 60), Pair(-16, -47), Pair(-12, -24),
        Pair(-128, -32), Pair(94, -98), Pair(-79, -130), Pair(-116, 66), Pair(-14, -47), Pair(-55, -13), Pair(-23, -48), Pair(15, 9)
      },
      { // Piece 5
        Pair(15, -9), Pair(-31, -143), Pair(-9, 67), Pair(-35, 22), Pair(-9, -69), Pair(28, 35), Pair(59, 86), Pair(11, 75),
        Pair(-62, -28), Pair(18, -50), Pair(-1, 36), Pair(-46, 71), Pair(0, 0), Pair(47, 122), Pair(77, 67), Pair(39, 60),
        Pair(-1, 8), Pair(88, -66), Pair(15, 44), Pair(13, 46), Pair(63, 70), Pair(38, 42), Pair(98, 17), Pair(43, -38),
        Pair(-64, -15), Pair(-15, 32), Pair(103, -20), Pair(-15, 10), Pair(-36, 12), Pair(74, -7), Pair(86, -62), Pair(-54, -16),
        Pair(-43, 14), Pair(50, -28), Pair(-23, 37), Pair(124, -18), Pair(-121, 9), Pair(71, -19), Pair(-13, -10), Pair(-36, -85),
        Pair(-54, 2), Pair(-54, 2), Pair(127, -49), Pair(-144, 17), Pair(-106, 10), Pair(-43, -45), Pair(10, -30), Pair(-12, -50),
        Pair(-191, 46), Pair(19, -38), Pair(28, 25), Pair(52, -46), Pair(-181, 77), Pair(-55, -51), Pair(31, -62), Pair(60, -63),
        Pair(-49, 91), Pair(-7, -9), Pair(-135, 8), Pair(11, 40), Pair(-35, -63), Pair(-58, -18), Pair(53, -72), Pair(59, -62)
      }
    }},
    {{ // Bucket 13
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-79, 37), Pair(-17, 55), Pair(42, 48), Pair(-27, 23), Pair(51, -2), Pair(44, 2), Pair(38, 23), Pair(43, 25),
        Pair(57, -16), Pair(-26, 39), Pair(-25, 38), Pair(-23, 64), Pair(-34, -7), Pair(30, -45), Pair(36, 0), Pair(13, -28),
        Pair(9, 23), Pair(-13, 16), Pair(-78, 57), Pair(48, -11), Pair(-51, 7), Pair(27, 9), Pair(29, 1), Pair(-34, 3),
        Pair(-21, 10), Pair(16, 15), Pair(3, 26), Pair(-17, 18), Pair(-3, 19), Pair(-35, 18), Pair(29, 8), Pair(-19, 2),
        Pair(15, 22), Pair(-5, 11), Pair(23, -12), Pair(31, 1), Pair(-2, 26), Pair(-11, 15), Pair(25, 19), Pair(18, -4),
        Pair(-7, 29), Pair(-44, 19), Pair(-16, 18), Pair(4, -12), Pair(-53, 42), Pair(-20, 7), Pair(-1, 14), Pair(5, 7),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(4, 49), Pair(-3, -23), Pair(-18, 32), Pair(94, -59), Pair(64, 98), Pair(68, -4), Pair(80, 46), Pair(-8, -59),
        Pair(8, 59), Pair(-1, -21), Pair(-11, -31), Pair(-49, 23), Pair(-151, -33), Pair(0, 0), Pair(44, 10), Pair(9, 79),
        Pair(28, 79), Pair(-26, 12), Pair(-96, 99), Pair(117, -51), Pair(110, -105), Pair(-2, -4), Pair(127, 109), Pair(61, -50),
        Pair(-65, -94), Pair(-153, 27), Pair(-89, 47), Pair(33, 21), Pair(125, -1), Pair(25, 8), Pair(72, -36), Pair(155, -35),
        Pair(33, -25), Pair(-67, -15), Pair(45, -65), Pair(4, 16), Pair(1, -2), Pair(109, -45), Pair(-34, 64), Pair(76, -93),
        Pair(-57, -63), Pair(33, -23), Pair(8, -75), Pair(-20, 51), Pair(-48, 51), Pair(-27, 57), Pair(33, -85), Pair(-3, 12),
        Pair(-4, 86), Pair(30, -3), Pair(79, -159), Pair(-19, -45), Pair(46, -38), Pair(-156, 13), Pair(114, -112), Pair(12, -92),
        Pair(-6, -32), Pair(-17, 61), Pair(-104, 73), Pair(94, -8), Pair(-226, -54), Pair(-130, 49), Pair(24, 89), Pair(34, -24)
      },
      { // Piece 2
        Pair(-45, -80), Pair(-29, 84), Pair(-52, -10), Pair(7, 49), Pair(51, -40), Pair(-51, 94), Pair(66, -22), Pair(0, 17),
        Pair(-28, -26), Pair(100, -43), Pair(81, 137), Pair(58, -105), Pair(-120, 64), Pair(0, 0), Pair(73, 11), Pair(87, -78),
        Pair(-149, -123), Pair(-71, -19), Pair(42, -89), Pair(120, 60), Pair(148, -57), Pair(120, 48), Pair(58, -51), Pair(82, -13),
        Pair(-50, 20), Pair(-44, -58), Pair(-59, -3), Pair(57, -25), Pair(63, -11), Pair(12, -55), Pair(-31, 27), Pair(64, -23),
        Pair(-37, -71), Pair(-93, 1), Pair(23, -11), Pair(218, -4), Pair(-33, -36), Pair(127, 21), Pair(84, -93), Pair(23, 34),
        Pair(32, 31), Pair(86, -21), Pair(1, -5), Pair(-8, -55), Pair(23, 32), Pair(89, -35), Pair(50, 61), Pair(87, -28),
        Pair(-178, -18), Pair(-17, 33), Pair(38, -25), Pair(56, 0), Pair(9, 26), Pair(-19, 97), Pair(3, -85), Pair(124, -18),
        Pair(35, 11), Pair(-12, -44), Pair(-66, 8), Pair(-124, 42), Pair(111, -26), Pair(18, -44), Pair(93, 34), Pair(95, -116)
      },
      { // Piece 3
        Pair(57, 76), Pair(-34, 0), Pair(131, 60), Pair(122, 76), Pair(39, 31), Pair(-29, -143), Pair(-91, 63), Pair(112, 75),
        Pair(-7, 9), Pair(8, 37), Pair(50, -36), Pair(53, -8), Pair(29, -49), Pair(0, 0), Pair(-7, 11), Pair(-63, 27),
        Pair(-79, 31), Pair(66, 6), Pair(65, -32), Pair(-52, -52), Pair(-47, 85), Pair(103, -47), Pair(87, 35), Pair(-30, -17),
        Pair(113, -48), Pair(154, -41), Pair(23, -5), Pair(113, 29), Pair(14, 76), Pair(101, 35), Pair(34, -21), Pair(17, 29),
        Pair(80, -40), Pair(61, -5), Pair(-61, -8), Pair(44, 11), Pair(55, 31), Pair(39, -30), Pair(-20, 65), Pair(-37, 59),
        Pair(29, -19), Pair(-98, 15), Pair(-21, -41), Pair(-47, 63), Pair(-91, 84), Pair(-16, 23), Pair(-52, 51), Pair(53, -56),
        Pair(-24, -52), Pair(-93, 43), Pair(-17, 25), Pair(-166, 95), Pair(6, 74), Pair(-20, -20), Pair(68, -31), Pair(104, -53),
        Pair(-69, 44), Pair(-20, -23), Pair(-40, 30), Pair(-69, -23), Pair(9, -30), Pair(33, -7), Pair(-18, -8), Pair(42, 29)
      },
      { // Piece 4
        Pair(-20, -4), Pair(-32, -44), Pair(-69, -126), Pair(40, 77), Pair(47, -48), Pair(-94, -136), Pair(-72, -88), Pair(-49, -70),
        Pair(70, -16), Pair(37, 73), Pair(-99, 4), Pair(25, 133), Pair(98, -90), Pair(0, 0), Pair(-4, -55), Pair(25, 107),
        Pair(23, -57), Pair(88, -267), Pair(130, 62), Pair(-7, -58), Pair(19, 119), Pair(82, -42), Pair(-66, 51), Pair(-72, -77),
        Pair(-31, -116), Pair(-57, -68), Pair(21, -42), Pair(-13, -104), Pair(79, 33), Pair(-10, -111), Pair(69, -146), Pair(-12, 77),
        Pair(-67, -38), Pair(-99, -64), Pair(27, -61), Pair(3, 38), Pair(-16, -142), Pair(69, 77), Pair(-37, 64), Pair(51, 34),
        Pair(-61, -57), Pair(-91, -7), Pair(-9, -23), Pair(66, -17), Pair(-22, -63), Pair(-21, -46), Pair(-14, -9), Pair(-60, 34),
        Pair(-16, -94), Pair(-17, -13), Pair(-54, -69), Pair(80, -59), Pair(1, -21), Pair(0, -31), Pair(-132, 134), Pair(-70, -32),
        Pair(192, 56), Pair(-81, 7), Pair(-124, 22), Pair(-37, -106), Pair(28, -22), Pair(-61, 5), Pair(-68, -73), Pair(-98, -47)
      },
      { // Piece 5
        Pair(-9, -50), Pair(-1, -12), Pair(-24, -127), Pair(42, 2), Pair(50, 26), Pair(-1, -35), Pair(25, 59), Pair(-7, 78),
        Pair(15, 75), Pair(-26, -41), Pair(4, -8), Pair(72, 62), Pair(34, 113), Pair(0, 0), Pair(49, 78), Pair(-15, 108),
        Pair(10, -5), Pair(36, -19), Pair(-19, 34), Pair(-58, 53), Pair(6, 50), Pair(18, 65), Pair(155, 36), Pair(13, 37),
        Pair(-2, 89), Pair(-62, -1), Pair(-8, -17), Pair(88, -27), Pair(31, 44), Pair(148, 8), Pair(41, 39), Pair(-4, 42),
        Pair(-35, -2), Pair(-54, 22), Pair(-78, -10), Pair(10, 5), Pair(-24, 9), Pair(47, 14), Pair(131, 3), Pair(-14, -35),
        Pair(-67, 1), Pair(-61, -73), Pair(72, -73), Pair(230, -44), Pair(-13, -20), Pair(47, -21), Pair(-138, -19), Pair(50, -38),
        Pair(17, -34), Pair(-193, 41), Pair(112, -29), Pair(-130, 3), Pair(-53, -34), Pair(-29, -34), Pair(26, -36), Pair(66, -48),
        Pair(-166, -31), Pair(-16, 8), Pair(44, -10), Pair(-79, -40), Pair(-67, -2), Pair(-87, 60), Pair(-11, -21), Pair(-27, 17)
      }
    }},
    {{ // Bucket 14
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-37, 37), Pair(-7, 22), Pair(-6, 37), Pair(74, -13), Pair(-45, 49), Pair(38, 23), Pair(-32, 21), Pair(4, -45),
        Pair(-22, 24), Pair(12, 41), Pair(-65, 22), Pair(89, -54), Pair(-14, 42), Pair(1, -26), Pair(153, -109), Pair(55, -25),
        Pair(35, -14), Pair(-40, 40), Pair(57, 9), Pair(-29, 28), Pair(1, 11), Pair(-2, 47), Pair(2, -26), Pair(-46, 11),
        Pair(21, -5), Pair(8, 2), Pair(4, 5), Pair(2, 10), Pair(1, -3), Pair(2, 18), Pair(35, -22), Pair(-12, 14),
        Pair(-1, 5), Pair(-15, 6), Pair(18, -24), Pair(25, -9), Pair(-15, -4), Pair(35, 12), Pair(2, -21), Pair(-7, 8),
        Pair(-30, 26), Pair(-1, -6), Pair(-19, 15), Pair(-14, 2), Pair(-48, 21), Pair(-24, 45), Pair(21, -24), Pair(-14, 8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-6, 17), Pair(5, 10), Pair(-33, -108), Pair(-38, 36), Pair(89, 6), Pair(-150, 29), Pair(28, -22), Pair(6, 18),
        Pair(-72, -46), Pair(-89, 0), Pair(4, -5), Pair(78, 1), Pair(106, 79), Pair(196, -63), Pair(0, 0), Pair(244, -45),
        Pair(10, -28), Pair(-17, -11), Pair(-37, 6), Pair(60, -5), Pair(104, -59), Pair(89, 11), Pair(110, -46), Pair(46, 57),
        Pair(4, -100), Pair(113, 53), Pair(-10, 15), Pair(96, 82), Pair(5, -9), Pair(143, -12), Pair(3, -24), Pair(11, 7),
        Pair(-117, 45), Pair(138, 28), Pair(79, -45), Pair(-8, 0), Pair(62, 32), Pair(-23, -4), Pair(49, 83), Pair(70, -56),
        Pair(-51, 22), Pair(-60, 55), Pair(108, -64), Pair(-17, 31), Pair(-26, 47), Pair(11, 24), Pair(26, 48), Pair(125, -179),
        Pair(161, -23), Pair(82, -45), Pair(-112, 13), Pair(-56, 26), Pair(-73, 2), Pair(-26, -39), Pair(40, -82), Pair(45, 23),
        Pair(-87, -103), Pair(-14, -38), Pair(-153, 74), Pair(-114, 63), Pair(112, -23), Pair(-138, -44), Pair(-44, -19), Pair(6, 30)
      },
      { // Piece 2
        Pair(-39, -1), Pair(31, 18), Pair(-36, 6), Pair(16, -157), Pair(-9, -57), Pair(-41, 11), Pair(-134, -93), Pair(-62, -126),
        Pair(-69, -54), Pair(9, 37), Pair(99, -71), Pair(90, -49), Pair(173, -28), Pair(-10, 64), Pair(0, 0), Pair(-38, 18),
        Pair(98, 4), Pair(131, -133), Pair(-22, -8), Pair(33, -105), Pair(95, 93), Pair(103, -58), Pair(35, 118), Pair(-31, -58),
        Pair(-124, -74), Pair(17, 36), Pair(16, -68), Pair(117, -94), Pair(154, -43), Pair(38, 31), Pair(63, -44), Pair(-5, 5),
        Pair(-120, 17), Pair(92, -97), Pair(27, -1), Pair(149, -52), Pair(-55, 81), Pair(29, 2), Pair(112, -54), Pair(67, -109),
        Pair(-20, -10), Pair(150, -24), Pair(81, -39), Pair(70, -78), Pair(69, -89), Pair(58, 25), Pair(-18, -41), Pair(21, -48),
        Pair(52, -70), Pair(43, -5), Pair(-94, 19), Pair(-24, -22), Pair(58, -32), Pair(-35, -16), Pair(-13, 25), Pair(-117, 112),
        Pair(95, -12), Pair(53, -54), Pair(5, -55), Pair(-42, 36), Pair(-48, -45), Pair(-62, 12), Pair(-8, -103), Pair(27, -35)
      },
      { // Piece 3
        Pair(-108, -7), Pair(99, 0), Pair(54, -16), Pair(24, 50), Pair(18, 50), Pair(77, 34), Pair(-86, -135), Pair(160, 50),
        Pair(234, -82), Pair(75, -43), Pair(37, -23), Pair(101, -66), Pair(-23, 1), Pair(3, 20), Pair(0, 0), Pair(-32, 13),
        Pair(23, -6), Pair(63, -32), Pair(53, -52), Pair(128, -69), Pair(95, -23), Pair(4, 35), Pair(53, 16), Pair(152, -73),
        Pair(-197, 87), Pair(86, -44), Pair(-82, 45), Pair(-99, -37), Pair(-15, -21), Pair(10, 22), Pair(-16, -8), Pair(-45, 32),
        Pair(-84, 85), Pair(57, -39), Pair(15, -84), Pair(0, 26), Pair(37, 4), Pair(25, -11), Pair(180, -107), Pair(-104, 102),
        Pair(-238, 59), Pair(-77, 41), Pair(-203, 180), Pair(-15, 101), Pair(23, 17), Pair(71, -19), Pair(61, -14), Pair(-145, 39),
        Pair(-64, -19), Pair(-71, -33), Pair(23, -16), Pair(24, -42), Pair(90, -50), Pair(-77, 52), Pair(82, -3), Pair(-19, -8),
        Pair(10, -61), Pair(-105, -23), Pair(-24, 8), Pair(-6, -34), Pair(-12, -9), Pair(-50, -27), Pair(46, 8), Pair(42, 22)
      },
      { // Piece 4
        Pair(136, 11), Pair(-194, -176), Pair(-5, 15), Pair(-56, -53), Pair(-46, -40), Pair(117, -67), Pair(-9, -19), Pair(103, -190),
        Pair(-42, -87), Pair(41, -57), Pair(-90, -43), Pair(48, 45), Pair(13, -208), Pair(63, -42), Pair(0, 0), Pair(-56, -120),
        Pair(84, 18), Pair(-135, -151), Pair(103, 32), Pair(-6, 99), Pair(46, -21), Pair(86, -142), Pair(-32, 46), Pair(37, 82),
        Pair(165, 11), Pair(-54, -17), Pair(82, -12), Pair(48, 13), Pair(-27, -82), Pair(34, 54), Pair(-11, 25), Pair(48, 44),
        Pair(12, -45), Pair(-118, -81), Pair(-67, -67), Pair(-19, 3), Pair(-5, 22), Pair(-128, 65), Pair(-106, 95), Pair(-36, -107),
        Pair(-17, -131), Pair(-156, -61), Pair(-9, -37), Pair(89, -33), Pair(-152, 99), Pair(-12, 94), Pair(-16, -42), Pair(119, 108),
        Pair(36, 26), Pair(-52, -83), Pair(29, 47), Pair(-90, 53), Pair(-33, -64), Pair(-29, -19), Pair(-68, -64), Pair(81, -28),
        Pair(-45, -137), Pair(-61, -56), Pair(-110, 31), Pair(-94, 122), Pair(-8, -92), Pair(-19, -14), Pair(-207, 30), Pair(214, 87)
      },
      { // Piece 5
        Pair(-1, -33), Pair(-12, -131), Pair(17, 50), Pair(26, 137), Pair(6, 124), Pair(-41, 25), Pair(-36, 14), Pair(10, 32),
        Pair(-15, 12), Pair(-2, 13), Pair(-24, -59), Pair(0, -103), Pair(12, 9), Pair(-98, 111), Pair(0, 0), Pair(-106, 90),
        Pair(-104, -40), Pair(-23, -5), Pair(-31, 21), Pair(-20, -16), Pair(24, 54), Pair(50, 22), Pair(105, 58), Pair(-68, 87),
        Pair(-39, -54), Pair(15, 5), Pair(-5, -3), Pair(116, -34), Pair(6, -28), Pair(70, 19), Pair(38, 45), Pair(104, 28),
        Pair(23, -44), Pair(68, -24), Pair(-63, 8), Pair(-6, -40), Pair(9, 3), Pair(75, -11), Pair(44, 59), Pair(-104, 28),
        Pair(-80, -9), Pair(-17, -17), Pair(48, -35), Pair(2, 46), Pair(89, -12), Pair(-30, 37), Pair(46, -4), Pair(-59, 28),
        Pair(42, -36), Pair(37, -12), Pair(-7, 2), Pair(-44, -14), Pair(-85, -7), Pair(19, 21), Pair(46, 11), Pair(25, 31),
        Pair(49, -76), Pair(-81, 0), Pair(-65, 17), Pair(-114, -2), Pair(-30, -39), Pair(0, 5), Pair(46, -63), Pair(63, -16)
      }
    }},
    {{ // Bucket 15
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(46, -30), Pair(40, 34), Pair(2, -5), Pair(-149, 78), Pair(91, 11), Pair(43, 25), Pair(4, -45), Pair(-57, -2),
        Pair(-49, 29), Pair(-59, 60), Pair(-57, 31), Pair(59, 10), Pair(36, -1), Pair(36, -7), Pair(-32, -23), Pair(56, -100),
        Pair(-31, 41), Pair(23, 1), Pair(-37, 9), Pair(8, 12), Pair(-4, 8), Pair(0, 7), Pair(23, 31), Pair(49, 6),
        Pair(-19, 13), Pair(-7, 15), Pair(4, 3), Pair(21, -19), Pair(15, 12), Pair(0, 13), Pair(-6, 16), Pair(42, 5),
        Pair(-25, 31), Pair(5, 6), Pair(-3, 5), Pair(17, 2), Pair(-1, 7), Pair(-37, 8), Pair(-6, 17), Pair(43, -17),
        Pair(-16, 15), Pair(-10, 12), Pair(-10, 13), Pair(-29, -13), Pair(-20, 5), Pair(-6, 15), Pair(-51, 31), Pair(7, 3),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(15, 97), Pair(3, 11), Pair(-18, -42), Pair(-8, -44), Pair(21, 84), Pair(-7, -4), Pair(-18, 25), Pair(71, 105),
        Pair(74, 36), Pair(44, 63), Pair(7, -63), Pair(12, 1), Pair(82, -24), Pair(93, 34), Pair(-70, 24), Pair(0, 0),
        Pair(-129, 8), Pair(59, 21), Pair(38, -13), Pair(66, 9), Pair(189, 51), Pair(46, -20), Pair(34, 46), Pair(3, -2),
        Pair(-70, -20), Pair(-47, 23), Pair(44, -23), Pair(25, 49), Pair(94, 12), Pair(105, 1), Pair(120, 6), Pair(137, 56),
        Pair(-28, 35), Pair(-131, -14), Pair(10, -53), Pair(35, -72), Pair(196, -10), Pair(100, -26), Pair(32, -15), Pair(98, -72),
        Pair(-53, -94), Pair(1, -53), Pair(73, -85), Pair(101, -11), Pair(-34, -23), Pair(35, 12), Pair(54, -55), Pair(2, 92),
        Pair(34, 15), Pair(-3, -26), Pair(-57, -34), Pair(-16, -16), Pair(19, 13), Pair(-3, -14), Pair(-21, -8), Pair(-76, -13),
        Pair(-64, -28), Pair(-82, 1), Pair(-16, -32), Pair(-51, -16), Pair(-201, -33), Pair(-102, 18), Pair(-19, -89), Pair(-69, -35)
      },
      { // Piece 2
        Pair(27, -109), Pair(-7, -16), Pair(56, -49), Pair(-12, -50), Pair(20, -63), Pair(48, 84), Pair(80, -49), Pair(8, -75),
        Pair(-103, 25), Pair(40, -105), Pair(16, -29), Pair(-79, -102), Pair(163, 13), Pair(181, -70), Pair(47, 54), Pair(0, 0),
        Pair(20, -95), Pair(16, 12), Pair(-89, -41), Pair(-3, 17), Pair(152, -69), Pair(4, 52), Pair(104, 2), Pair(140, 98),
        Pair(32, 16), Pair(166, -64), Pair(-37, 25), Pair(77, -56), Pair(160, -13), Pair(77, 0), Pair(23, 35), Pair(-61, 42),
        Pair(79, -10), Pair(-132, -16), Pair(60, -75), Pair(69, 5), Pair(156, -38), Pair(86, 67), Pair(-60, -4), Pair(23, -35),
        Pair(-10, 50), Pair(-19, -77), Pair(124, -29), Pair(102, 1), Pair(6, 5), Pair(23, -57), Pair(70, -54), Pair(161, -76),
        Pair(-108, -31), Pair(38, -13), Pair(71, -38), Pair(-28, -2), Pair(19, -78), Pair(9, -36), Pair(1, -67), Pair(15, -241),
        Pair(-26, 65), Pair(105, -18), Pair(28, -16), Pair(104, -88), Pair(-247, 34), Pair(-44, -67), Pair(14, -83), Pair(75, -27)
      },
      { // Piece 3
        Pair(-52, 36), Pair(-16, 58), Pair(-85, 77), Pair(41, 19), Pair(84, 28), Pair(55, 4), Pair(19, 68), Pair(146, -185),
        Pair(63, 4), Pair(150, -13), Pair(-29, 36), Pair(51, 4), Pair(221, -48), Pair(68, -13), Pair(18, -10), Pair(0, 0),
        Pair(183, -41), Pair(109, -43), Pair(148, -19), Pair(19, -17), Pair(172, -98), Pair(8, 11), Pair(-4, 12), Pair(-90, 55),
        Pair(-22, 6), Pair(132, -9), Pair(130, -76), Pair(77, -4), Pair(93, -99), Pair(156, -11), Pair(-4, 43), Pair(-33, 21),
        Pair(-86, 53), Pair(-52, 52), Pair(-43, 71), Pair(113, -54), Pair(29, -8), Pair(-45, -7), Pair(87, 19), Pair(-97, 28),
        Pair(16, 4), Pair(-47, 0), Pair(95, 62), Pair(-51, 44), Pair(-29, -20), Pair(-110, -20), Pair(33, 12), Pair(-132, 7),
        Pair(-111, 42), Pair(42, 11), Pair(3, -4), Pair(-42, -13), Pair(32, 18), Pair(2, -4), Pair(2, -12), Pair(-58, 43),
        Pair(-34, -4), Pair(8, 12), Pair(-62, 4), Pair(-11, -21), Pair(23, -32), Pair(32, -40), Pair(-70, 14), Pair(12, -41)
      },
      { // Piece 4
        Pair(-47, -34), Pair(-96, -90), Pair(52, 58), Pair(-51, -84), Pair(104, 88), Pair(-14, -30), Pair(-55, -24), Pair(-88, -182),
        Pair(107, 43), Pair(64, -128), Pair(-7, -67), Pair(70, -114), Pair(38, -12), Pair(-15, -34), Pair(52, -23), Pair(0, 0),
        Pair(-47, -103), Pair(55, -20), Pair(4, -48), Pair(-8, 24), Pair(15, -24), Pair(-34, -46), Pair(-50, -84), Pair(41, 214),
        Pair(-1, -9), Pair(69, -24), Pair(100, 18), Pair(4, 0), Pair(87, -16), Pair(16, 42), Pair(25, -88), Pair(8, -13),
        Pair(58, -143), Pair(-197, -30), Pair(-97, -44), Pair(34, 25), Pair(69, -93), Pair(-26, 26), Pair(-19, 76), Pair(114, -115),
        Pair(-102, -22), Pair(-43, 53), Pair(-34, -65), Pair(31, -73), Pair(-53, 168), Pair(-58, 96), Pair(41, -115), Pair(-9, -168),
        Pair(-47, -5), Pair(-96, -10), Pair(-7, 91), Pair(-54, -7), Pair(-32, -130), Pair(-58, -74), Pair(-105, 61), Pair(-102, -47),
        Pair(9, -29), Pair(-43, 61), Pair(2, -48), Pair(-37, 62), Pair(-104, -38), Pair(-79, 10), Pair(-55, -64), Pair(-36, -12)
      },
      { // Piece 5
        Pair(16, 58), Pair(-15, 126), Pair(13, 63), Pair(4, 13), Pair(11, 13), Pair(-38, 57), Pair(27, 46), Pair(32, -230),
        Pair(34, 80), Pair(34, -39), Pair(-80, 8), Pair(-58, 20), Pair(49, 9), Pair(-37, 45), Pair(98, 87), Pair(0, 0),
        Pair(28, 89), Pair(45, 36), Pair(53, -3), Pair(-27, 18), Pair(45, 1), Pair(-48, 38), Pair(80, 14), Pair(-36, 37),
        Pair(166, 109), Pair(-51, 7), Pair(80, 47), Pair(54, -14), Pair(4, 25), Pair(63, 13), Pair(84, 18), Pair(86, 14),
        Pair(-11, -59), Pair(-21, -17), Pair(43, -15), Pair(75, -12), Pair(-26, 19), Pair(-116, 37), Pair(11, 30), Pair(-10, -4),
        Pair(-91, -26), Pair(-10, -2), Pair(62, -28), Pair(108, -34), Pair(-24, -15), Pair(2, 15), Pair(-29, 10), Pair(59, -31),
        Pair(-126, 0), Pair(-15, 3), Pair(-22, 15), Pair(88, -59), Pair(-129, 18), Pair(-53, 6), Pair(9, 6), Pair(-11, -11),
        Pair(-64, -78), Pair(23, -47), Pair(-98, 17), Pair(-81, -13), Pair(-50, -10), Pair(22, -37), Pair(-13, 22), Pair(-11, -37)
      }
    }},
    {{ // Bucket 16
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-12, -76), Pair(30, -22), Pair(-28, 17), Pair(46, 10), Pair(-70, 62), Pair(57, -16), Pair(-21, 24), Pair(-49, 29),
        Pair(4, 49), Pair(-44, 3), Pair(-7, 8), Pair(21, 19), Pair(-1, 20), Pair(-8, 16), Pair(-1, 3), Pair(-33, 31),
        Pair(3, -27), Pair(-12, -1), Pair(1, 9), Pair(4, 12), Pair(5, 10), Pair(-4, 15), Pair(-2, 16), Pair(4, 10),
        Pair(-9, 14), Pair(-1, 20), Pair(-4, 12), Pair(2, 7), Pair(-4, 9), Pair(6, 7), Pair(6, 8), Pair(-2, 13),
        Pair(-1, 19), Pair(-15, 20), Pair(-2, 10), Pair(-2, 8), Pair(-3, 9), Pair(14, 8), Pair(4, 11), Pair(-4, 16),
        Pair(6, 29), Pair(-3, 17), Pair(-1, 1), Pair(10, 2), Pair(-14, 22), Pair(2, 15), Pair(0, 14), Pair(-4, 17),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(142, -43), Pair(-154, 93), Pair(66, -1), Pair(47, 16), Pair(-20, 70), Pair(75, 2), Pair(58, 52), Pair(108, 40),
        Pair(4, -90), Pair(72, -1), Pair(88, 17), Pair(-17, 18), Pair(67, -17), Pair(186, -29), Pair(-66, 106), Pair(-104, 54),
        Pair(0, 0), Pair(51, 9), Pair(64, 19), Pair(29, 58), Pair(-14, 32), Pair(36, -4), Pair(-13, 57), Pair(-1, -6),
        Pair(-13, 56), Pair(32, 56), Pair(17, 11), Pair(17, 37), Pair(23, 52), Pair(48, 13), Pair(-18, 2), Pair(-14, 28),
        Pair(5, 42), Pair(23, 30), Pair(-5, 13), Pair(22, 19), Pair(-13, 16), Pair(43, -10), Pair(21, 22), Pair(3, 2),
        Pair(73, 2), Pair(11, 28), Pair(16, 7), Pair(37, 1), Pair(6, 31), Pair(16, 10), Pair(30, -34), Pair(-11, -20),
        Pair(28, 20), Pair(-11, 24), Pair(-14, 41), Pair(11, -19), Pair(5, 26), Pair(2, 1), Pair(-11, 10), Pair(-10, 43),
        Pair(-157, -59), Pair(11, -4), Pair(-32, -9), Pair(-18, 22), Pair(8, 24), Pair(1, 10), Pair(4, -3), Pair(-54, -38)
      },
      { // Piece 2
        Pair(59, -21), Pair(198, -19), Pair(99, -21), Pair(26, 8), Pair(65, -76), Pair(-12, 24), Pair(75, -20), Pair(31, -23),
        Pair(56, -86), Pair(95, 10), Pair(95, -41), Pair(127, -58), Pair(55, -47), Pair(-26, -22), Pair(86, -15), Pair(81, -24),
        Pair(0, 0), Pair(45, 30), Pair(99, -21), Pair(47, 26), Pair(58, -23), Pair(-20, 24), Pair(47, -76), Pair(-22, 87),
        Pair(36, 47), Pair(67, -19), Pair(80, 22), Pair(95, -19), Pair(5, 29), Pair(51, -40), Pair(15, 48), Pair(70, -5),
        Pair(26, 10), Pair(44, 7), Pair(49, -10), Pair(28, 32), Pair(16, 3), Pair(23, 31), Pair(66, -22), Pair(-26, -8),
        Pair(15, 2), Pair(21, -26), Pair(12, 12), Pair(30, 8), Pair(19, 48), Pair(67, -12), Pair(53, 20), Pair(39, -16),
        Pair(24, -59), Pair(13, -29), Pair(49, -53), Pair(23, -2), Pair(43, -10), Pair(41, -8), Pair(41, 17), Pair(32, -27),
        Pair(-38, -40), Pair(4, -35), Pair(-5, -7), Pair(16, -19), Pair(36, 1), Pair(44, 9), Pair(46, -17), Pair(59, 1)
      },
      { // Piece 3
        Pair(51, -20), Pair(24, 69), Pair(-28, 55), Pair(64, 32), Pair(19, 18), Pair(-27, 46), Pair(12, 44), Pair(-28, 84),
        Pair(27, -88), Pair(43, 73), Pair(3, 82), Pair(70, 21), Pair(82, 48), Pair(79, 44), Pair(-15, 55), Pair(97, 6),
        Pair(0, 0), Pair(53, 23), Pair(48, 29), Pair(67, 31), Pair(112, 7), Pair(37, 35), Pair(30, 32), Pair(16, 43),
        Pair(-35, 42), Pair(18, 51), Pair(13, 67), Pair(31, 41), Pair(58, 20), Pair(77, 22), Pair(8, 42), Pair(-8, 51),
        Pair(-7, 34), Pair(-20, 92), Pair(42, 33), Pair(9, 45), Pair(63, 35), Pair(35, 40), Pair(9, 39), Pair(-35, 67),
        Pair(-19, 18), Pair(-3, 57), Pair(-6, 48), Pair(68, 10), Pair(30, 45), Pair(-29, 50), Pair(14, 18), Pair(11, 45),
        Pair(-49, 32), Pair(24, 28), Pair(25, 19), Pair(6, 47), Pair(31, 4), Pair(2, 27), Pair(5, 40), Pair(9, 71),
        Pair(-11, 7), Pair(19, 53), Pair(23, 39), Pair(21, 25), Pair(11, 41), Pair(14, 32), Pair(28, 33), Pair(14, 14)
      },
      { // Piece 4
        Pair(76, -48), Pair(-1, 29), Pair(14, 40), Pair(2, 45), Pair(121, -15), Pair(-23, -10), Pair(-50, 37), Pair(-2, 79),
        Pair(23, -112), Pair(16, 51), Pair(51, 10), Pair(-30, 83), Pair(38, -18), Pair(100, -66), Pair(-36, 134), Pair(31, 29),
        Pair(0, 0), Pair(7, 108), Pair(25, 60), Pair(-17, 77), Pair(-2, 39), Pair(68, 8), Pair(-48, 11), Pair(13, 0),
        Pair(72, 13), Pair(44, 38), Pair(16, 17), Pair(50, 34), Pair(6, 55), Pair(33, 38), Pair(-3, 5), Pair(8, 4),
        Pair(8, 60), Pair(10, 65), Pair(16, 48), Pair(14, 57), Pair(8, 97), Pair(21, 78), Pair(37, 24), Pair(19, 17),
        Pair(-6, 65), Pair(28, 8), Pair(-5, 72), Pair(40, -8), Pair(16, 24), Pair(2, 60), Pair(29, -2), Pair(23, -44),
        Pair(10, 32), Pair(9, 32), Pair(7, 15), Pair(12, 41), Pair(7, 40), Pair(40, -32), Pair(28, 27), Pair(20, -56),
        Pair(-28, 31), Pair(0, 12), Pair(-2, 13), Pair(20, 5), Pair(26, 3), Pair(25, 14), Pair(43, 8), Pair(40, -134)
      },
      { // Piece 5
        Pair(25, 29), Pair(-56, 68), Pair(-102, 99), Pair(25, 8), Pair(-23, -42), Pair(-8, -15), Pair(1, 24), Pair(4, -38),
        Pair(-32, -77), Pair(-89, 122), Pair(-26, 122), Pair(32, 69), Pair(80, 22), Pair(69, 52), Pair(118, 18), Pair(109, -18),
        Pair(0, 0), Pair(45, 85), Pair(123, 48), Pair(151, 32), Pair(89, 11), Pair(67, 19), Pair(79, -14), Pair(-67, 37),
        Pair(111, 15), Pair(153, 34), Pair(73, 58), Pair(257, 8), Pair(-66, 47), Pair(61, 6), Pair(-44, 30), Pair(-15, 12),
        Pair(-11, 23), Pair(107, 51), Pair(147, 12), Pair(97, 23), Pair(-4, 34), Pair(54, 17), Pair(-61, 12), Pair(-81, -6),
        Pair(26, 51), Pair(50, 60), Pair(53, 31), Pair(-12, 39), Pair(-34, 26), Pair(-41, 30), Pair(-48, 17), Pair(-50, 4),
        Pair(17, 30), Pair(90, 30), Pair(28, 42), Pair(-14, 32), Pair(-6, 9), Pair(11, 6), Pair(-23, 9), Pair(-25, 0),
        Pair(101, 36), Pair(43, 42), Pair(47, -5), Pair(14, -4), Pair(-22, 12), Pair(-55, 10), Pair(-9, -5), Pair(-19, -12)
      }
    }},
    {{ // Bucket 17
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-85, 16), Pair(-17, -58), Pair(-1, -3), Pair(-106, 42), Pair(-33, 19), Pair(-26, 39), Pair(12, 41), Pair(-59, 60),
        Pair(-45, 3), Pair(-1, 51), Pair(-4, 6), Pair(-23, 23), Pair(-3, 18), Pair(-7, 20), Pair(44, 18), Pair(21, 19),
        Pair(6, 8), Pair(-11, -19), Pair(-7, 10), Pair(-14, 22), Pair(4, 4), Pair(2, 21), Pair(20, 12), Pair(-17, 13),
        Pair(6, 21), Pair(-7, 7), Pair(-10, 18), Pair(1, 14), Pair(-7, 11), Pair(3, 7), Pair(-5, 19), Pair(-7, 14),
        Pair(-10, 23), Pair(3, 10), Pair(-12, 15), Pair(-5, 13), Pair(-6, 8), Pair(12, 6), Pair(1, 13), Pair(-3, 12),
        Pair(-24, 41), Pair(5, -7), Pair(-17, 14), Pair(-7, 21), Pair(-11, 4), Pair(-6, 18), Pair(7, 12), Pair(-6, 20),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-13, 0), Pair(-210, 77), Pair(58, 26), Pair(37, 42), Pair(-105, 65), Pair(45, 29), Pair(-63, 54), Pair(26, 202),
        Pair(52, 5), Pair(11, -8), Pair(29, 57), Pair(59, 32), Pair(15, 60), Pair(-23, 16), Pair(81, -30), Pair(39, -30),
        Pair(-104, 78), Pair(0, 0), Pair(27, 30), Pair(32, 5), Pair(28, 44), Pair(49, 44), Pair(134, -13), Pair(-16, 33),
        Pair(54, 37), Pair(12, 50), Pair(51, 26), Pair(39, 27), Pair(52, 36), Pair(34, 14), Pair(11, 38), Pair(-29, 48),
        Pair(26, 30), Pair(50, 7), Pair(50, 9), Pair(27, 51), Pair(11, 33), Pair(51, 31), Pair(25, 31), Pair(2, 15),
        Pair(-18, -18), Pair(19, 58), Pair(22, 14), Pair(20, 16), Pair(4, 36), Pair(28, 11), Pair(11, 47), Pair(-31, -2),
        Pair(-38, 43), Pair(16, 8), Pair(33, 11), Pair(9, 22), Pair(26, 2), Pair(21, -2), Pair(17, 38), Pair(-12, 57),
        Pair(67, -96), Pair(-32, 6), Pair(-50, 16), Pair(-28, 51), Pair(16, 6), Pair(28, 22), Pair(9, -19), Pair(10, 47)
      },
      { // Piece 2
        Pair(100, 14), Pair(11, -56), Pair(-21, 2), Pair(76, -12), Pair(-9, 28), Pair(125, -33), Pair(-49, -12), Pair(17, -39),
        Pair(-26, 42), Pair(-6, -84), Pair(113, -8), Pair(80, -3), Pair(205, -84), Pair(-97, -4), Pair(87, -48), Pair(33, 26),
        Pair(26, 85), Pair(0, 0), Pair(166, -2), Pair(61, -40), Pair(99, -1), Pair(158, -62), Pair(23, -12), Pair(-1, -20),
        Pair(27, -12), Pair(78, 40), Pair(90, -14), Pair(102, 16), Pair(89, -20), Pair(132, -5), Pair(37, -41), Pair(7, 51),
        Pair(22, 62), Pair(37, 3), Pair(36, 11), Pair(71, -8), Pair(37, 30), Pair(82, -12), Pair(47, -2), Pair(-2, -11),
        Pair(35, 13), Pair(22, -34), Pair(27, -2), Pair(16, 19), Pair(48, -8), Pair(49, 21), Pair(43, 7), Pair(42, 24),
        Pair(63, -38), Pair(31, -56), Pair(44, -22), Pair(12, 12), Pair(25, 35), Pair(39, -8), Pair(50, 22), Pair(40, 6),
        Pair(12, -1), Pair(42, 2), Pair(2, 2), Pair(16, 15), Pair(33, -28), Pair(31, 26), Pair(8, 2), Pair(28, -44)
      },
      { // Piece 3
        Pair(-6, 93), Pair(10, 9), Pair(-27, 84), Pair(-18, 69), Pair(64, 39), Pair(41, 28), Pair(50, 41), Pair(140, 37),
        Pair(-7, 84), Pair(-6, -62), Pair(-11, 86), Pair(69, 32), Pair(68, 39), Pair(92, 9), Pair(28, 45), Pair(18, 56),
        Pair(44, 54), Pair(0, 0), Pair(64, 38), Pair(22, 52), Pair(-3, 72), Pair(55, 52), Pair(23, 62), Pair(87, 24),
        Pair(2, 62), Pair(-17, 52), Pair(16, 85), Pair(54, 22), Pair(35, 62), Pair(145, -9), Pair(-15, 39), Pair(46, 67),
        Pair(70, 21), Pair(3, 66), Pair(30, 57), Pair(49, 47), Pair(65, 10), Pair(40, 10), Pair(-16, 41), Pair(-9, 68),
        Pair(50, 52), Pair(8, 32), Pair(39, 25), Pair(-1, 55), Pair(0, 57), Pair(7, -2), Pair(26, 21), Pair(51, 49),
        Pair(-17, 64), Pair(0, 80), Pair(28, 55), Pair(16, 53), Pair(32, 47), Pair(58, -6), Pair(53, 4), Pair(25, 73),
        Pair(5, 39), Pair(8, 18), Pair(19, 40), Pair(17, 35), Pair(18, 25), Pair(8, 40), Pair(45, 14), Pair(14, 43)
      },
      { // Piece 4
        Pair(-34, 66), Pair(4, -22), Pair(9, 40), Pair(-16, 33), Pair(47, -29), Pair(9, -8), Pair(36, -8), Pair(55, 18),
        Pair(-26, 61), Pair(7, -56), Pair(-9, 66), Pair(39, -9), Pair(6, 55), Pair(42, 45), Pair(-62, 99), Pair(-30, 27),
        Pair(21, 103), Pair(0, 0), Pair(36, 31), Pair(6, 66), Pair(117, -43), Pair(-69, 138), Pair(74, -10), Pair(-1, 19),
        Pair(48, 34), Pair(11, 66), Pair(58, 71), Pair(6, 73), Pair(10, 14), Pair(-7, 49), Pair(4, -32), Pair(-52, 128),
        Pair(19, 48), Pair(56, 5), Pair(7, 22), Pair(77, 29), Pair(-15, 91), Pair(-9, 88), Pair(-1, 77), Pair(57, 2),
        Pair(10, 73), Pair(10, 41), Pair(-8, 73), Pair(-13, 47), Pair(-6, 49), Pair(41, -28), Pair(15, 45), Pair(28, 19),
        Pair(-12, 3), Pair(12, 58), Pair(2, 72), Pair(-13, 57), Pair(34, 32), Pair(-2, 69), Pair(-11, 20), Pair(9, -28),
        Pair(22, 73), Pair(-20, 57), Pair(4, 29), Pair(-2, 26), Pair(28, -4), Pair(16, -13), Pair(-20, -16), Pair(42, -20)
      },
      { // Piece 5
        Pair(-3, 224), Pair(84, 119), Pair(15, 206), Pair(4, 28), Pair(-4, -26), Pair(14, 21), Pair(-69, -2), Pair(-33, -26),
        Pair(45, 139), Pair(132, 34), Pair(123, 44), Pair(28, 98), Pair(79, -23), Pair(-65, 3), Pair(62, 7), Pair(-22, 17),
        Pair(73, 116), Pair(0, 0), Pair(153, 71), Pair(2, 81), Pair(61, 28), Pair(14, -14), Pair(-65, 43), Pair(-112, 6),
        Pair(9, 102), Pair(101, 38), Pair(187, 39), Pair(88, 55), Pair(104, -1), Pair(-15, 18), Pair(166, -27), Pair(-94, 11),
        Pair(127, 56), Pair(81, 54), Pair(93, 47), Pair(110, 21), Pair(62, 16), Pair(-11, 6), Pair(-147, 30), Pair(-62, -27),
        Pair(18, 65), Pair(55, 13), Pair(13, 35), Pair(-3, 37), Pair(-46, 5), Pair(-11, -14), Pair(-33, 4), Pair(-152, 13),
        Pair(67, 70), Pair(57, 9), Pair(32, 10), Pair(-16, 12), Pair(11, -7), Pair(-49, 13), Pair(-4, -28), Pair(-27, -1),
        Pair(-44, 53), Pair(34, 39), Pair(-16, 76), Pair(-35, 0), Pair(-34, -6), Pair(-25, -19), Pair(-14, -18), Pair(-33, -3)
      }
    }},
    {{ // Bucket 18
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(10, 22), Pair(-8, 3), Pair(-42, -73), Pair(43, -1), Pair(-120, 72), Pair(-25, 38), Pair(-65, 22), Pair(-57, 31),
        Pair(-7, 7), Pair(-4, 6), Pair(10, 33), Pair(2, 44), Pair(4, -21), Pair(-9, 4), Pair(9, 1), Pair(-32, 35),
        Pair(18, -3), Pair(7, 20), Pair(0, -42), Pair(4, 18), Pair(8, 18), Pair(7, 19), Pair(-19, 18), Pair(-11, 20),
        Pair(-2, 12), Pair(0, 21), Pair(0, -9), Pair(2, 11), Pair(7, 15), Pair(2, 11), Pair(5, 9), Pair(-1, 9),
        Pair(-6, 15), Pair(1, 7), Pair(-5, -3), Pair(-8, 11), Pair(1, 8), Pair(8, 5), Pair(4, 2), Pair(5, 10),
        Pair(-10, 15), Pair(-5, 12), Pair(-6, 6), Pair(-1, 0), Pair(0, 13), Pair(-4, 17), Pair(1, 8), Pair(5, 10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-60, 95), Pair(95, 28), Pair(26, 60), Pair(-69, 87), Pair(-16, 9), Pair(-59, -48), Pair(18, 73), Pair(29, 68),
        Pair(-43, 88), Pair(14, 49), Pair(0, -53), Pair(3, 57), Pair(106, 32), Pair(56, -14), Pair(135, 26), Pair(26, 28),
        Pair(61, 65), Pair(90, 21), Pair(0, 0), Pair(98, 73), Pair(105, 6), Pair(72, -21), Pair(72, 16), Pair(11, 97),
        Pair(-14, 29), Pair(-3, 110), Pair(47, 85), Pair(64, 90), Pair(42, 29), Pair(42, 55), Pair(52, 49), Pair(57, 27),
        Pair(-8, 41), Pair(22, 25), Pair(-5, 58), Pair(22, 53), Pair(63, 19), Pair(15, 53), Pair(69, -5), Pair(19, 23),
        Pair(37, 7), Pair(-4, 8), Pair(24, 46), Pair(32, 42), Pair(40, 56), Pair(23, 15), Pair(19, -19), Pair(-49, 43),
        Pair(8, -54), Pair(64, -45), Pair(81, 23), Pair(11, 24), Pair(38, 11), Pair(27, 14), Pair(-56, 68), Pair(-2, -26),
        Pair(3, -33), Pair(-16, 17), Pair(-60, 41), Pair(6, 38), Pair(13, -11), Pair(-16, 30), Pair(3, 4), Pair(-3, 29)
      },
      { // Piece 2
        Pair(-54, -85), Pair(44, 32), Pair(110, -64), Pair(94, 26), Pair(-19, 5), Pair(144, -10), Pair(68, -35), Pair(140, -9),
        Pair(-18, 34), Pair(55, -33), Pair(73, -36), Pair(97, 5), Pair(99, -18), Pair(116, -45), Pair(-2, 9), Pair(-34, 10),
        Pair(67, 17), Pair(96, 8), Pair(0, 0), Pair(136, 0), Pair(84, -35), Pair(93, -29), Pair(48, -31), Pair(73, -5),
        Pair(16, 68), Pair(39, 1), Pair(44, 66), Pair(76, -3), Pair(111, 58), Pair(113, -12), Pair(60, -29), Pair(40, -39),
        Pair(31, -30), Pair(58, 44), Pair(78, 0), Pair(48, 34), Pair(51, 11), Pair(32, 28), Pair(41, -17), Pair(134, -24),
        Pair(9, 12), Pair(4, -23), Pair(6, 29), Pair(20, -5), Pair(39, 53), Pair(50, 1), Pair(-11, 14), Pair(71, -8),
        Pair(21, -16), Pair(17, 8), Pair(12, -5), Pair(-6, 77), Pair(30, 5), Pair(14, 12), Pair(28, 26), Pair(18, 64),
        Pair(87, -21), Pair(-14, 39), Pair(2, 33), Pair(-4, 5), Pair(9, 14), Pair(16, 3), Pair(75, -62), Pair(46, 17)
      },
      { // Piece 3
        Pair(12, 73), Pair(123, 53), Pair(29, 0), Pair(-108, 98), Pair(123, 65), Pair(-29, 73), Pair(-136, 95), Pair(32, 74),
        Pair(-15, 46), Pair(27, 76), Pair(-36, -48), Pair(67, 48), Pair(45, 63), Pair(59, 76), Pair(-35, 45), Pair(65, 62),
        Pair(20, 66), Pair(-15, 45), Pair(0, 0), Pair(49, 49), Pair(40, 50), Pair(53, 25), Pair(65, 58), Pair(80, 53),
        Pair(47, 36), Pair(35, 64), Pair(11, 29), Pair(-30, 90), Pair(68, 47), Pair(32, 65), Pair(-57, 103), Pair(-9, 75),
        Pair(0, 53), Pair(-23, 64), Pair(64, 36), Pair(-7, 74), Pair(-1, 60), Pair(-6, 59), Pair(36, 49), Pair(-14, 35),
        Pair(-14, 86), Pair(44, 26), Pair(-17, 35), Pair(-25, 39), Pair(18, 27), Pair(26, 26), Pair(30, 31), Pair(-30, 99),
        Pair(-34, 57), Pair(16, 32), Pair(-37, 59), Pair(-17, 69), Pair(24, 33), Pair(-9, 63), Pair(29, 25), Pair(-21, 46),
        Pair(8, 39), Pair(27, 48), Pair(6, 28), Pair(-3, 62), Pair(2, 46), Pair(-10, 48), Pair(-54, 67), Pair(-7, 33)
      },
      { // Piece 4
        Pair(21, 49), Pair(14, 99), Pair(11, -28), Pair(82, -54), Pair(93, -63), Pair(-26, 33), Pair(-18, -26), Pair(175, -56),
        Pair(40, -31), Pair(26, 37), Pair(40, -133), Pair(37, 76), Pair(145, -43), Pair(86, -78), Pair(6, 170), Pair(74, -2),
        Pair(55, 52), Pair(40, 23), Pair(0, 0), Pair(-47, 90), Pair(14, 83), Pair(63, -1), Pair(0, 106), Pair(40, -17),
        Pair(-9, 34), Pair(12, 41), Pair(-24, 80), Pair(-11, 95), Pair(2, 20), Pair(48, 164), Pair(0, 31), Pair(-22, 79),
        Pair(32, -33), Pair(-8, 46), Pair(9, 23), Pair(30, 63), Pair(55, 6), Pair(-26, 99), Pair(-3, 109), Pair(60, 55),
        Pair(13, -65), Pair(23, 30), Pair(27, 5), Pair(36, 27), Pair(-9, 116), Pair(-7, 51), Pair(13, 81), Pair(-16, 98),
        Pair(17, -58), Pair(30, -31), Pair(4, 22), Pair(19, -31), Pair(-5, 56), Pair(31, 24), Pair(26, 5), Pair(-17, 67),
        Pair(26, -26), Pair(49, -9), Pair(19, 23), Pair(-8, 63), Pair(-16, 30), Pair(17, -73), Pair(103, -92), Pair(-37, 52)
      },
      { // Piece 5
        Pair(13, 19), Pair(35, 197), Pair(114, 76), Pair(3, 90), Pair(11, 25), Pair(2, -7), Pair(-14, 27), Pair(3, 20),
        Pair(-16, 128), Pair(130, 87), Pair(152, 31), Pair(79, 54), Pair(170, 83), Pair(-12, 63), Pair(12, 4), Pair(19, -81),
        Pair(132, 151), Pair(166, 91), Pair(0, 0), Pair(73, 76), Pair(108, 52), Pair(-116, 39), Pair(35, 37), Pair(56, 27),
        Pair(-87, 110), Pair(143, 49), Pair(61, 77), Pair(85, 54), Pair(107, 34), Pair(-18, 33), Pair(-63, 20), Pair(-100, -1),
        Pair(107, 74), Pair(47, 57), Pair(50, 34), Pair(62, 56), Pair(77, 6), Pair(6, -9), Pair(2, -3), Pair(-172, 16),
        Pair(60, 42), Pair(-10, 34), Pair(19, 7), Pair(-21, 33), Pair(-15, 12), Pair(-48, 3), Pair(-26, 2), Pair(-44, -15),
        Pair(24, 36), Pair(-60, 10), Pair(24, 37), Pair(-63, 25), Pair(-13, 14), Pair(-55, -11), Pair(-32, 1), Pair(-32, -11),
        Pair(59, -1), Pair(-7, 4), Pair(-37, 40), Pair(-77, 56), Pair(-18, -13), Pair(-27, -13), Pair(-38, -11), Pair(-9, -39)
      }
    }},
    {{ // Bucket 19
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-12, 44), Pair(-3, 38), Pair(-30, 9), Pair(-37, -42), Pair(-12, 23), Pair(-23, 64), Pair(89, -54), Pair(59, 10),
        Pair(21, 19), Pair(-23, 24), Pair(3, 44), Pair(17, 23), Pair(17, 46), Pair(0, 15), Pair(-57, 45), Pair(48, 10),
        Pair(6, 10), Pair(-13, 27), Pair(8, 33), Pair(-6, -36), Pair(8, 27), Pair(-12, 6), Pair(7, 13), Pair(15, 10),
        Pair(1, 21), Pair(-1, 13), Pair(-20, 25), Pair(1, 6), Pair(-10, 24), Pair(11, 9), Pair(-12, 16), Pair(4, 10),
        Pair(-7, 14), Pair(-3, 13), Pair(-16, 17), Pair(3, -2), Pair(-3, 20), Pair(5, 11), Pair(-5, 9), Pair(0, 8),
        Pair(-4, 14), Pair(-9, 13), Pair(-22, 15), Pair(-15, 4), Pair(-9, 17), Pair(-9, 17), Pair(-10, 12), Pair(-3, 13),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(25, -9), Pair(0, 34), Pair(-31, 10), Pair(50, -1), Pair(-91, 69), Pair(-106, 29), Pair(-129, 60), Pair(51, 152),
        Pair(78, 32), Pair(20, 70), Pair(58, 29), Pair(24, -21), Pair(101, 30), Pair(-39, 72), Pair(-35, 63), Pair(78, 52),
        Pair(-4, 53), Pair(18, 70), Pair(15, 32), Pair(0, 0), Pair(64, 59), Pair(103, 38), Pair(42, 67), Pair(26, 95),
        Pair(-1, 98), Pair(28, 36), Pair(33, 77), Pair(10, 86), Pair(22, 84), Pair(34, 56), Pair(3, 55), Pair(0, 47),
        Pair(62, -8), Pair(74, 13), Pair(37, 57), Pair(25, 77), Pair(45, 53), Pair(19, 40), Pair(30, 23), Pair(47, 47),
        Pair(-25, 11), Pair(10, 23), Pair(-1, 72), Pair(1, 29), Pair(17, 41), Pair(12, 55), Pair(-14, 97), Pair(-6, 25),
        Pair(36, 47), Pair(-13, 18), Pair(30, -9), Pair(17, 36), Pair(-11, 61), Pair(31, 13), Pair(-9, -44), Pair(-1, 26),
        Pair(60, -8), Pair(26, -11), Pair(35, 33), Pair(-12, 29), Pair(-11, 30), Pair(-17, 29), Pair(-16, 29), Pair(-21, -68)
      },
      { // Piece 2
        Pair(102, 20), Pair(-43, 11), Pair(238, -30), Pair(-16, -42), Pair(-34, 70), Pair(-68, 52), Pair(-78, 65), Pair(57, -31),
        Pair(67, -13), Pair(29, 41), Pair(65, 17), Pair(5, -36), Pair(152, -29), Pair(128, 8), Pair(-2, 49), Pair(9, 76),
        Pair(55, -37), Pair(114, 6), Pair(63, 31), Pair(0, 0), Pair(105, -24), Pair(75, -22), Pair(88, 60), Pair(40, -2),
        Pair(67, 19), Pair(28, 76), Pair(25, 21), Pair(16, 41), Pair(71, 1), Pair(88, 32), Pair(43, 8), Pair(77, 21),
        Pair(72, 24), Pair(30, 16), Pair(17, 45), Pair(73, -22), Pair(36, 27), Pair(56, 2), Pair(6, 40), Pair(41, 31),
        Pair(-2, 27), Pair(19, -6), Pair(57, 12), Pair(41, 16), Pair(33, -8), Pair(38, 32), Pair(41, 18), Pair(20, 71),
        Pair(18, 3), Pair(1, 42), Pair(45, 14), Pair(20, 12), Pair(19, 36), Pair(32, 4), Pair(27, 40), Pair(37, 17),
        Pair(32, 12), Pair(67, 30), Pair(22, 19), Pair(29, 7), Pair(54, 13), Pair(-5, 49), Pair(13, -10), Pair(45, 23)
      },
      { // Piece 3
        Pair(42, 70), Pair(-53, 110), Pair(25, 80), Pair(-8, 20), Pair(101, 68), Pair(85, 36), Pair(-68, 71), Pair(-71, 95),
        Pair(52, 68), Pair(-11, 104), Pair(8, 93), Pair(-26, 3), Pair(100, 56), Pair(75, 48), Pair(98, 66), Pair(54, 67),
        Pair(4, 76), Pair(10, 63), Pair(16, 50), Pair(0, 0), Pair(63, 38), Pair(34, 78), Pair(71, 64), Pair(53, 53),
        Pair(22, 74), Pair(57, 31), Pair(47, 62), Pair(20, 41), Pair(24, 87), Pair(42, 76), Pair(6, 64), Pair(41, 62),
        Pair(-59, 100), Pair(22, 66), Pair(65, 55), Pair(63, 37), Pair(-28, 101), Pair(44, 24), Pair(30, 57), Pair(-33, 44),
        Pair(-28, 44), Pair(2, 63), Pair(-1, 53), Pair(-6, 38), Pair(6, 65), Pair(9, 44), Pair(28, 69), Pair(71, -18),
        Pair(37, 60), Pair(29, 47), Pair(28, 45), Pair(6, 40), Pair(24, 52), Pair(2, 52), Pair(-42, 47), Pair(-73, 75),
        Pair(6, 47), Pair(14, 45), Pair(10, 59), Pair(24, 47), Pair(12, 54), Pair(19, 39), Pair(-6, 50), Pair(33, 32)
      },
      { // Piece 4
        Pair(-48, 25), Pair(-52, 28), Pair(126, -20), Pair(36, 45), Pair(-42, 104), Pair(-41, -36), Pair(94, 22), Pair(133, -31),
        Pair(31, 57), Pair(33, 10), Pair(38, 34), Pair(-44, -13), Pair(75, 5), Pair(156, -11), Pair(59, 43), Pair(-20, 108),
        Pair(40, 38), Pair(81, 11), Pair(-14, 86), Pair(0, 0), Pair(10, 57), Pair(33, 166), Pair(22, 177), Pair(87, 11),
        Pair(67, 79), Pair(-17, 98), Pair(-7, 94), Pair(12, 56), Pair(35, 68), Pair(48, -31), Pair(66, 73), Pair(34, 55),
        Pair(29, -13), Pair(50, 52), Pair(12, 43), Pair(43, 85), Pair(-46, 104), Pair(33, 37), Pair(75, 37), Pair(64, -4),
        Pair(47, 8), Pair(26, 50), Pair(22, 38), Pair(27, 55), Pair(36, 62), Pair(-3, 67), Pair(46, -39), Pair(87, -80),
        Pair(-5, -6), Pair(1, 43), Pair(22, 43), Pair(31, 15), Pair(6, 65), Pair(5, 82), Pair(6, 44), Pair(33, 53),
        Pair(20, -104), Pair(58, -60), Pair(-1, 3), Pair(16, 59), Pair(55, -60), Pair(20, -9), Pair(-16, -30), Pair(-20, -69)
      },
      { // Piece 5
        Pair(30, -9), Pair(-14, 122), Pair(44, 157), Pair(62, 61), Pair(4, 136), Pair(24, -44), Pair(4, -1), Pair(-4, -17),
        Pair(26, 37), Pair(25, 73), Pair(62, 93), Pair(-61, 31), Pair(57, 61), Pair(22, 87), Pair(49, 12), Pair(18, -69),
        Pair(32, 107), Pair(86, 22), Pair(169, 81), Pair(0, 0), Pair(80, 105), Pair(99, -18), Pair(43, -6), Pair(-35, 42),
        Pair(-57, 1), Pair(62, 35), Pair(108, 50), Pair(27, 79), Pair(95, 42), Pair(-26, 44), Pair(-18, 19), Pair(11, -26),
        Pair(37, 29), Pair(53, 28), Pair(105, 8), Pair(-6, 36), Pair(-20, 32), Pair(48, -17), Pair(-42, 13), Pair(-115, 17),
        Pair(-96, 0), Pair(24, -10), Pair(17, 18), Pair(-58, 47), Pair(-10, 0), Pair(18, -11), Pair(24, -12), Pair(-21, -25),
        Pair(-42, -15), Pair(58, -29), Pair(-12, -21), Pair(-72, 15), Pair(-45, 7), Pair(-8, -18), Pair(13, -31), Pair(9, -31),
        Pair(19, 26), Pair(8, 13), Pair(-24, -16), Pair(-109, 25), Pair(-29, -56), Pair(-38, -20), Pair(1, -32), Pair(13, -41)
      }
    }},
    {{ // Bucket 20
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-91, 55), Pair(-22, 7), Pair(-39, 38), Pair(0, -14), Pair(113, -70), Pair(-34, -7), Pair(-14, 42), Pair(36, -1),
        Pair(-1, 20), Pair(-3, 18), Pair(4, -21), Pair(17, 46), Pair(10, 22), Pair(16, -13), Pair(7, -5), Pair(-21, 22),
        Pair(6, 11), Pair(9, 5), Pair(11, 5), Pair(-2, 33), Pair(23, -49), Pair(18, 15), Pair(-10, 11), Pair(0, 8),
        Pair(6, 7), Pair(13, 10), Pair(14, 7), Pair(-4, 25), Pair(6, 1), Pair(1, 7), Pair(-11, 14), Pair(-7, 11),
        Pair(9, 13), Pair(3, 3), Pair(0, 6), Pair(-5, 1), Pair(-3, 7), Pair(1, 11), Pair(-10, 7), Pair(-5, 7),
        Pair(8, 7), Pair(3, 6), Pair(-9, 7), Pair(10, 10), Pair(-8, 19), Pair(-5, 9), Pair(-16, 7), Pair(-11, 6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(50, 99), Pair(-54, 89), Pair(-7, 74), Pair(-9, -16), Pair(23, 43), Pair(34, -3), Pair(118, 25), Pair(-84, 168),
        Pair(-17, 19), Pair(-122, 81), Pair(14, 74), Pair(90, 38), Pair(-41, -46), Pair(-11, 20), Pair(141, 36), Pair(75, 78),
        Pair(109, 31), Pair(41, 72), Pair(67, 18), Pair(87, 31), Pair(0, 0), Pair(-5, 37), Pair(-18, 54), Pair(34, 31),
        Pair(-24, 50), Pair(2, 43), Pair(23, 7), Pair(53, 53), Pair(40, 76), Pair(106, 45), Pair(-9, 58), Pair(43, 38),
        Pair(-44, 49), Pair(120, -23), Pair(-22, 72), Pair(49, 18), Pair(57, 20), Pair(40, 34), Pair(81, 36), Pair(83, -28),
        Pair(-5, -29), Pair(-5, -7), Pair(5, 23), Pair(8, 52), Pair(8, 68), Pair(-16, 50), Pair(-7, 19), Pair(-26, 2),
        Pair(-54, 44), Pair(-4, 25), Pair(-24, 35), Pair(-26, 16), Pair(10, 33), Pair(16, 2), Pair(-39, 41), Pair(-21, 2),
        Pair(-58, -8), Pair(-8, -4), Pair(40, -78), Pair(27, -2), Pair(-63, 21), Pair(23, 48), Pair(1, -4), Pair(-33, -2)
      },
      { // Piece 2
        Pair(125, -106), Pair(22, -38), Pair(69, -26), Pair(217, -76), Pair(108, -125), Pair(59, 3), Pair(30, -25), Pair(24, 25),
        Pair(0, 20), Pair(54, -13), Pair(6, 21), Pair(46, -1), Pair(24, -46), Pair(94, -15), Pair(57, -9), Pair(77, -60),
        Pair(35, -11), Pair(144, -21), Pair(108, -31), Pair(102, 20), Pair(0, 0), Pair(126, -8), Pair(36, -36), Pair(56, 18),
        Pair(32, 62), Pair(93, -39), Pair(94, 27), Pair(23, 16), Pair(25, 69), Pair(54, -15), Pair(22, 46), Pair(39, -20),
        Pair(59, -47), Pair(-30, 39), Pair(21, -1), Pair(63, 12), Pair(44, -20), Pair(25, 27), Pair(37, -29), Pair(64, 8),
        Pair(23, 21), Pair(-7, -3), Pair(35, 21), Pair(59, -63), Pair(33, 24), Pair(54, -12), Pair(36, 5), Pair(23, -5),
        Pair(36, 1), Pair(9, 17), Pair(29, -52), Pair(-2, -2), Pair(28, -17), Pair(38, 8), Pair(11, -9), Pair(-6, 67),
        Pair(20, -12), Pair(19, -88), Pair(-1, 18), Pair(16, -23), Pair(-17, 17), Pair(14, -12), Pair(12, 18), Pair(44, -30)
      },
      { // Piece 3
        Pair(-22, 88), Pair(2, 44), Pair(4, 57), Pair(-18, 36), Pair(-72, -21), Pair(22, 35), Pair(-221, 96), Pair(-73, 77),
        Pair(27, 49), Pair(-15, 41), Pair(52, 37), Pair(16, 47), Pair(16, -86), Pair(39, 46), Pair(73, 6), Pair(96, 53),
        Pair(73, 1), Pair(6, 25), Pair(39, 19), Pair(66, -9), Pair(0, 0), Pair(-12, 43), Pair(19, 17), Pair(-21, 19),
        Pair(22, 49), Pair(46, 38), Pair(70, -1), Pair(-29, 77), Pair(81, 6), Pair(0, 12), Pair(42, 2), Pair(-11, 47),
        Pair(39, 57), Pair(38, 5), Pair(-24, 41), Pair(20, 11), Pair(-16, 12), Pair(2, 10), Pair(62, 26), Pair(-23, 6),
        Pair(3, -6), Pair(40, 6), Pair(-13, 22), Pair(-21, 22), Pair(69, 8), Pair(-25, 42), Pair(-8, 32), Pair(13, -9),
        Pair(-42, 9), Pair(-36, -10), Pair(-4, 21), Pair(-31, 46), Pair(-3, 28), Pair(-5, 38), Pair(-19, -9), Pair(-66, 42),
        Pair(-1, 29), Pair(-32, 52), Pair(-20, 36), Pair(-15, 32), Pair(9, 11), Pair(-15, 47), Pair(27, -1), Pair(25, -23)
      },
      { // Piece 4
        Pair(-31, 22), Pair(-47, 65), Pair(50, 37), Pair(147, -85), Pair(4, -20), Pair(108, 1), Pair(-33, 6), Pair(1, 38),
        Pair(-8, -48), Pair(-26, 36), Pair(114, -75), Pair(5, 75), Pair(-76, -7), Pair(58, 27), Pair(61, 37), Pair(33, -12),
        Pair(-32, -78), Pair(61, -20), Pair(55, -82), Pair(48, 0), Pair(0, 0), Pair(104, -32), Pair(107, -1), Pair(50, 14),
        Pair(42, 71), Pair(48, -3), Pair(34, -8), Pair(6, 26), Pair(46, 37), Pair(71, -16), Pair(51, 65), Pair(28, 45),
        Pair(-7, 41), Pair(132, -118), Pair(54, -42), Pair(-36, 46), Pair(18, 53), Pair(58, 43), Pair(1, 43), Pair(14, 60),
        Pair(76, -58), Pair(24, -13), Pair(8, -39), Pair(25, 9), Pair(9, 4), Pair(-6, -45), Pair(70, -72), Pair(-5, 37),
        Pair(28, -40), Pair(16, 73), Pair(21, 32), Pair(10, -3), Pair(-10, 30), Pair(-4, -6), Pair(1, 5), Pair(-18, -11),
        Pair(3, -20), Pair(57, -31), Pair(36, -109), Pair(-17, 68), Pair(1, -21), Pair(-27, 53), Pair(29, -46), Pair(98, -72)
      },
      { // Piece 5
        Pair(40, 63), Pair(21, -10), Pair(-1, 6), Pair(28, 63), Pair(73, 54), Pair(-3, 144), Pair(-5, 50), Pair(-6, 76),
        Pair(-1, -1), Pair(15, -5), Pair(18, 50), Pair(-13, 30), Pair(26, -19), Pair(25, 31), Pair(19, 58), Pair(-15, 6),
        Pair(53, -23), Pair(-44, 35), Pair(126, -37), Pair(67, 40), Pair(0, 0), Pair(99, 27), Pair(95, -2), Pair(-7, 44),
        Pair(93, 3), Pair(118, -25), Pair(-42, 57), Pair(161, 26), Pair(-67, 74), Pair(96, 20), Pair(13, 38), Pair(-46, 49),
        Pair(103, -20), Pair(-169, 42), Pair(-46, 15), Pair(1, 19), Pair(29, 25), Pair(30, 7), Pair(72, -23), Pair(-74, -9),
        Pair(-161, 42), Pair(68, -9), Pair(-3, -7), Pair(15, -13), Pair(24, 10), Pair(32, -1), Pair(-16, -12), Pair(22, -21),
        Pair(-8, -12), Pair(39, -23), Pair(4, 10), Pair(-20, -23), Pair(4, -19), Pair(7, -32), Pair(9, -17), Pair(-5, -13),
        Pair(-22, -27), Pair(27, -57), Pair(-41, 3), Pair(0, -39), Pair(-53, -3), Pair(-19, -30), Pair(22, -34), Pair(14, -26)
      }
    }},
    {{ // Bucket 21
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-34, 5), Pair(14, 44), Pair(-64, 62), Pair(58, 28), Pair(83, 0), Pair(30, -45), Pair(0, -26), Pair(36, -7),
        Pair(-8, 16), Pair(-7, 20), Pair(-9, 4), Pair(0, 15), Pair(15, -13), Pair(34, 9), Pair(6, -17), Pair(-74, 16),
        Pair(-1, 10), Pair(-4, 10), Pair(17, 17), Pair(-2, 11), Pair(17, -1), Pair(25, -31), Pair(7, 6), Pair(-22, 2),
        Pair(2, 6), Pair(9, 6), Pair(9, 3), Pair(7, 18), Pair(4, 13), Pair(-13, 12), Pair(-15, 18), Pair(-19, 7),
        Pair(-2, 9), Pair(-9, 13), Pair(-7, 9), Pair(-2, 10), Pair(3, 12), Pair(-15, 10), Pair(-5, 13), Pair(-17, 14),
        Pair(2, 7), Pair(-2, 6), Pair(3, -1), Pair(12, 0), Pair(-26, 30), Pair(-13, 14), Pair(-6, 17), Pair(-12, 5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-2, -29), Pair(8, 56), Pair(-21, -44), Pair(59, -18), Pair(-31, -3), Pair(-30, 39), Pair(-76, 71), Pair(-86, -51),
        Pair(-64, 24), Pair(128, -23), Pair(38, 23), Pair(67, -21), Pair(71, 47), Pair(-114, 2), Pair(15, -10), Pair(24, 55),
        Pair(-93, 48), Pair(-45, 47), Pair(29, 5), Pair(-10, 46), Pair(56, 16), Pair(0, 0), Pair(219, -31), Pair(18, 13),
        Pair(-82, 33), Pair(-26, 18), Pair(15, 28), Pair(53, 2), Pair(125, 58), Pair(35, 30), Pair(44, 65), Pair(-69, 3),
        Pair(-49, 34), Pair(-27, 60), Pair(-14, 25), Pair(13, 23), Pair(55, 24), Pair(-8, 1), Pair(56, 4), Pair(-2, 13),
        Pair(-66, 49), Pair(-6, 31), Pair(-25, 14), Pair(-16, 31), Pair(31, 12), Pair(22, 6), Pair(-17, 39), Pair(-14, 41),
        Pair(-61, 10), Pair(29, -93), Pair(-77, -2), Pair(-36, -3), Pair(-34, 22), Pair(-19, 34), Pair(-19, -5), Pair(-6, 39),
        Pair(-49, 4), Pair(-52, 4), Pair(-48, 21), Pair(11, 16), Pair(23, -20), Pair(-35, 54), Pair(32, -71), Pair(60, -16)
      },
      { // Piece 2
        Pair(11, -22), Pair(116, -117), Pair(83, -29), Pair(42, -30), Pair(-78, -14), Pair(37, -36), Pair(9, -6), Pair(-16, -25),
        Pair(121, -123), Pair(126, -36), Pair(9, -107), Pair(181, -17), Pair(80, -72), Pair(140, -91), Pair(159, -66), Pair(7, 38),
        Pair(12, -38), Pair(110, -71), Pair(42, 10), Pair(51, -25), Pair(107, -27), Pair(0, 0), Pair(225, -10), Pair(-30, 30),
        Pair(-56, 5), Pair(7, 56), Pair(90, -45), Pair(66, 10), Pair(30, -20), Pair(48, 43), Pair(40, -44), Pair(33, 51),
        Pair(13, 21), Pair(17, -21), Pair(50, 32), Pair(40, -22), Pair(56, 35), Pair(23, -36), Pair(61, -7), Pair(-22, -5),
        Pair(23, -36), Pair(15, -12), Pair(26, -35), Pair(30, -19), Pair(22, -35), Pair(20, -2), Pair(-27, 3), Pair(21, 35),
        Pair(74, -49), Pair(5, 10), Pair(72, -5), Pair(15, -43), Pair(3, 0), Pair(14, -17), Pair(-5, 15), Pair(44, -35),
        Pair(-12, -13), Pair(43, -19), Pair(25, -45), Pair(19, 30), Pair(-23, -20), Pair(-15, 37), Pair(131, -74), Pair(-3, -50)
      },
      { // Piece 3
        Pair(36, 21), Pair(-18, 57), Pair(37, 53), Pair(-15, 77), Pair(76, 31), Pair(66, 14), Pair(13, 26), Pair(20, 56),
        Pair(52, 10), Pair(42, 33), Pair(6, 10), Pair(56, 12), Pair(61, -7), Pair(35, -87), Pair(30, 32), Pair(107, -24),
        Pair(-9, 17), Pair(42, 23), Pair(22, -5), Pair(39, 12), Pair(-8, 45), Pair(0, 0), Pair(81, -16), Pair(8, 24),
        Pair(-21, 54), Pair(28, 16), Pair(14, -5), Pair(41, 8), Pair(10, 24), Pair(7, 20), Pair(39, 9), Pair(27, -1),
        Pair(-56, 73), Pair(1, 13), Pair(-59, -11), Pair(1, 43), Pair(40, 46), Pair(13, -8), Pair(80, 14), Pair(75, -51),
        Pair(-45, 23), Pair(-5, 7), Pair(-32, 20), Pair(-81, 47), Pair(2, 44), Pair(37, -24), Pair(-13, 34), Pair(45, -12),
        Pair(9, -9), Pair(19, 1), Pair(-74, 32), Pair(-21, 19), Pair(-35, 53), Pair(11, 3), Pair(34, 13), Pair(-52, 46),
        Pair(-27, 19), Pair(-40, 50), Pair(-28, 16), Pair(8, -3), Pair(-1, 4), Pair(29, -24), Pair(-44, 45), Pair(-3, 16)
      },
      { // Piece 4
        Pair(53, -22), Pair(61, -16), Pair(-127, 139), Pair(74, -27), Pair(115, -45), Pair(-5, -47), Pair(69, -91), Pair(129, -176),
        Pair(8, 23), Pair(-27, 104), Pair(44, -103), Pair(98, -47), Pair(88, 3), Pair(146, -247), Pair(40, 48), Pair(125, -39),
        Pair(-8, 34), Pair(41, 43), Pair(7, -13), Pair(-22, 5), Pair(-125, 162), Pair(0, 0), Pair(73, -35), Pair(117, -23),
        Pair(-36, 34), Pair(-19, 17), Pair(35, -35), Pair(-4, 20), Pair(-3, -12), Pair(83, -114), Pair(66, 27), Pair(130, -16),
        Pair(1, -20), Pair(35, -59), Pair(-55, 50), Pair(-34, 90), Pair(-16, -8), Pair(33, 16), Pair(52, -35), Pair(-8, 33),
        Pair(-63, -45), Pair(-40, 136), Pair(31, -39), Pair(22, -71), Pair(-25, 11), Pair(17, -38), Pair(-22, 30), Pair(-7, 39),
        Pair(84, -15), Pair(-18, 13), Pair(4, 11), Pair(19, -66), Pair(-55, 52), Pair(16, -81), Pair(-26, -20), Pair(101, -141),
        Pair(6, -23), Pair(2, -2), Pair(13, 38), Pair(-27, 2), Pair(-19, 14), Pair(-24, 18), Pair(-4, -89), Pair(-42, 25)
      },
      { // Piece 5
        Pair(-2, 55), Pair(24, 17), Pair(-6, 97), Pair(38, 53), Pair(-54, 55), Pair(66, 74), Pair(-1, 129), Pair(-42, -34),
        Pair(25, -20), Pair(-67, 7), Pair(-7, 63), Pair(38, 28), Pair(107, 14), Pair(21, 37), Pair(59, 26), Pair(45, 57),
        Pair(14, 50), Pair(93, -23), Pair(27, 27), Pair(99, 14), Pair(-23, 78), Pair(0, 0), Pair(219, 30), Pair(38, 50),
        Pair(14, 12), Pair(-123, 26), Pair(62, -2), Pair(0, 32), Pair(143, 15), Pair(2, 55), Pair(8, 25), Pair(41, 28),
        Pair(-152, 15), Pair(19, 22), Pair(-67, -14), Pair(-3, 6), Pair(19, 39), Pair(-14, 30), Pair(22, 11), Pair(-4, 10),
        Pair(53, -17), Pair(-89, 15), Pair(-13, -3), Pair(61, -14), Pair(55, -34), Pair(10, 0), Pair(37, -27), Pair(19, 3),
        Pair(-2, -15), Pair(48, -51), Pair(-32, 1), Pair(-40, -15), Pair(-17, -20), Pair(-29, 1), Pair(-7, -21), Pair(28, -19),
        Pair(4, -60), Pair(-12, -30), Pair(-37, -31), Pair(-44, 11), Pair(-7, -48), Pair(-57, -33), Pair(16, -43), Pair(-2, -16)
      }
    }},
    {{ // Bucket 22
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(5, 26), Pair(22, 15), Pair(-171, 35), Pair(-14, 60), Pair(19, 39), Pair(36, 0), Pair(153, -109), Pair(-31, -24),
        Pair(-1, 3), Pair(44, 19), Pair(9, 0), Pair(-57, 44), Pair(8, -5), Pair(6, -18), Pair(29, 22), Pair(-8, -49),
        Pair(14, 1), Pair(-13, 13), Pair(4, 12), Pair(2, 12), Pair(-5, 15), Pair(4, -2), Pair(-5, -46), Pair(-9, -4),
        Pair(14, 5), Pair(6, 9), Pair(1, 3), Pair(7, 10), Pair(-9, 19), Pair(-19, 22), Pair(-2, -9), Pair(-26, 22),
        Pair(2, 11), Pair(-1, 2), Pair(-2, 1), Pair(-7, 7), Pair(-3, 5), Pair(-5, 9), Pair(4, -13), Pair(-28, 18),
        Pair(7, 15), Pair(5, 1), Pair(-6, 12), Pair(10, -3), Pair(-1, 17), Pair(-13, 21), Pair(-4, -18), Pair(-25, 18),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-17, -127), Pair(-9, 70), Pair(-133, 36), Pair(99, -15), Pair(0, -20), Pair(-12, 51), Pair(-47, -9), Pair(-3, -59),
        Pair(-166, 48), Pair(-121, -2), Pair(-37, 67), Pair(-14, 77), Pair(116, 8), Pair(104, 8), Pair(-23, -56), Pair(-25, 66),
        Pair(58, -88), Pair(-73, -2), Pair(-12, -13), Pair(5, 3), Pair(52, -1), Pair(66, 3), Pair(0, 0), Pair(78, -45),
        Pair(-105, 7), Pair(-42, 40), Pair(50, -18), Pair(42, 29), Pair(45, 34), Pair(47, 28), Pair(40, 10), Pair(57, 12),
        Pair(14, -4), Pair(4, 25), Pair(-21, -10), Pair(-11, 9), Pair(17, 6), Pair(55, -6), Pair(-2, -3), Pair(-3, 27),
        Pair(-26, -17), Pair(-97, 22), Pair(-23, 16), Pair(-71, 25), Pair(-36, 9), Pair(6, 5), Pair(-12, 18), Pair(-15, -51),
        Pair(-34, -40), Pair(-101, -41), Pair(-36, -11), Pair(-26, -14), Pair(0, -5), Pair(-13, -18), Pair(-102, 18), Pair(35, -54),
        Pair(-57, 10), Pair(-40, -16), Pair(51, -34), Pair(-122, 71), Pair(-33, 29), Pair(-74, 38), Pair(-31, -19), Pair(-102, -82)
      },
      { // Piece 2
        Pair(-84, -64), Pair(59, -64), Pair(-98, -57), Pair(-6, -31), Pair(31, -55), Pair(81, -26), Pair(-24, -24), Pair(7, 13),
        Pair(-10, -48), Pair(43, -47), Pair(-11, -59), Pair(84, -64), Pair(95, 28), Pair(122, -17), Pair(-122, -30), Pair(-68, -43),
        Pair(62, -89), Pair(107, -57), Pair(-38, -55), Pair(84, -28), Pair(144, -96), Pair(97, 1), Pair(0, 0), Pair(57, -29),
        Pair(-47, -5), Pair(30, -58), Pair(-23, 24), Pair(139, -79), Pair(53, 9), Pair(95, -50), Pair(1, 28), Pair(-20, -15),
        Pair(-25, -44), Pair(-48, 11), Pair(64, -32), Pair(62, 1), Pair(14, -27), Pair(29, 28), Pair(-15, -39), Pair(5, -32),
        Pair(-22, 45), Pair(12, -43), Pair(7, 6), Pair(37, -52), Pair(-3, 42), Pair(-29, -38), Pair(61, 16), Pair(-23, -28),
        Pair(39, -79), Pair(-30, 12), Pair(-7, -31), Pair(-36, 35), Pair(-26, -55), Pair(-41, -2), Pair(-20, -33), Pair(25, 0),
        Pair(7, -20), Pair(8, -31), Pair(-25, 2), Pair(-23, -34), Pair(-29, 23), Pair(-9, -57), Pair(-32, -35), Pair(13, -95)
      },
      { // Piece 3
        Pair(27, -9), Pair(107, 29), Pair(14, 16), Pair(130, 17), Pair(127, 11), Pair(-27, 71), Pair(76, -45), Pair(36, 38),
        Pair(72, -1), Pair(51, 11), Pair(85, 15), Pair(167, -42), Pair(-25, 8), Pair(98, 8), Pair(-59, -27), Pair(23, 4),
        Pair(-5, 1), Pair(-6, 31), Pair(56, 5), Pair(5, 23), Pair(65, -10), Pair(92, -30), Pair(0, 0), Pair(-71, 51),
        Pair(17, 30), Pair(26, -27), Pair(39, 36), Pair(-25, 57), Pair(57, -29), Pair(-42, 36), Pair(-10, 12), Pair(11, -8),
        Pair(-61, 57), Pair(-56, 85), Pair(-71, 3), Pair(-12, 2), Pair(-28, 34), Pair(-11, -1), Pair(-29, -11), Pair(31, -4),
        Pair(17, -18), Pair(-18, 20), Pair(-19, 22), Pair(-39, 67), Pair(-65, 32), Pair(2, 10), Pair(2, 3), Pair(-78, 29),
        Pair(11, 27), Pair(23, 6), Pair(-68, 10), Pair(-23, 35), Pair(-15, 2), Pair(58, -58), Pair(22, -23), Pair(-55, -2),
        Pair(-6, -30), Pair(-17, 13), Pair(-36, 15), Pair(-2, -4), Pair(15, 3), Pair(14, -6), Pair(53, -36), Pair(11, 27)
      },
      { // Piece 4
        Pair(-36, -90), Pair(-98, 30), Pair(-17, -42), Pair(21, -71), Pair(-26, 35), Pair(60, -10), Pair(22, -44), Pair(-15, 2),
        Pair(-81, 210), Pair(7, 40), Pair(57, -53), Pair(-36, 22), Pair(97, -46), Pair(1, 11), Pair(132, -301), Pair(71, -79),
        Pair(27, -24), Pair(34, -92), Pair(-7, 78), Pair(39, -12), Pair(51, -21), Pair(164, -107), Pair(0, 0), Pair(100, -124),
        Pair(17, -100), Pair(-37, -44), Pair(38, -7), Pair(81, -16), Pair(75, -56), Pair(60, -1), Pair(-3, -68), Pair(63, -35),
        Pair(-7, -6), Pair(-67, 207), Pair(49, -27), Pair(-6, 3), Pair(-38, -6), Pair(-54, 19), Pair(-30, -68), Pair(1, -36),
        Pair(-58, -7), Pair(-47, 46), Pair(-7, -122), Pair(-14, -32), Pair(11, -7), Pair(6, -3), Pair(13, 12), Pair(81, -169),
        Pair(71, -81), Pair(-48, -30), Pair(-17, 15), Pair(22, -36), Pair(-7, -64), Pair(-23, 8), Pair(-13, 13), Pair(-54, 22),
        Pair(11, -87), Pair(-40, -107), Pair(-56, -25), Pair(-14, -55), Pair(-16, -108), Pair(-61, -27), Pair(-24, -55), Pair(67, -46)
      },
      { // Piece 5
        Pair(9, 202), Pair(45, 50), Pair(25, 156), Pair(-25, -1), Pair(-8, -45), Pair(47, 167), Pair(3, 59), Pair(-27, 82),
        Pair(-4, 28), Pair(51, -44), Pair(-24, -2), Pair(39, -15), Pair(-125, 33), Pair(107, 13), Pair(27, 22), Pair(78, 64),
        Pair(-117, 16), Pair(55, 44), Pair(111, -52), Pair(33, -28), Pair(110, -44), Pair(135, 37), Pair(0, 0), Pair(53, 29),
        Pair(46, 2), Pair(-17, -2), Pair(-42, 28), Pair(169, -54), Pair(22, 14), Pair(19, 25), Pair(55, 31), Pair(-20, 38),
        Pair(-153, -27), Pair(-54, -3), Pair(137, -41), Pair(-6, -3), Pair(37, -7), Pair(-18, 21), Pair(5, 19), Pair(68, 41),
        Pair(-106, -32), Pair(-44, -32), Pair(-99, 5), Pair(32, 3), Pair(-22, 15), Pair(24, 0), Pair(7, 3), Pair(21, 10),
        Pair(4, -24), Pair(-17, -30), Pair(-62, -11), Pair(-32, -18), Pair(-21, 8), Pair(3, -9), Pair(24, 3), Pair(-1, 30),
        Pair(-71, -28), Pair(6, -31), Pair(-37, 19), Pair(0, -11), Pair(-6, -26), Pair(7, -9), Pair(46, -8), Pair(49, -36)
      }
    }},
    {{ // Bucket 23
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-40, 15), Pair(41, 23), Pair(76, -21), Pair(-43, 35), Pair(0, 14), Pair(13, -28), Pair(55, -25), Pair(56, -100),
        Pair(-33, 32), Pair(21, 20), Pair(-32, 35), Pair(48, 10), Pair(-21, 22), Pair(-74, 17), Pair(-8, -48), Pair(3, 23),
        Pair(5, -1), Pair(0, 16), Pair(7, 14), Pair(-9, 19), Pair(-1, 3), Pair(-12, 8), Pair(-9, -11), Pair(46, -44),
        Pair(-17, 11), Pair(-5, 14), Pair(-5, 15), Pair(-5, 13), Pair(5, 5), Pair(-3, 9), Pair(11, 16), Pair(23, -17),
        Pair(-9, 9), Pair(-7, 12), Pair(2, 1), Pair(-4, -2), Pair(-3, 3), Pair(-2, 5), Pair(7, 13), Pair(3, 5),
        Pair(-8, 19), Pair(-8, 11), Pair(-6, 14), Pair(-18, 3), Pair(2, -11), Pair(-1, 7), Pair(-3, 13), Pair(9, -2),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(23, -76), Pair(12, 81), Pair(29, 27), Pair(-135, 20), Pair(12, 18), Pair(193, -27), Pair(13, 85), Pair(48, -26),
        Pair(3, -38), Pair(-57, -6), Pair(-66, 26), Pair(19, 30), Pair(63, 9), Pair(-10, 16), Pair(53, 42), Pair(34, -85),
        Pair(28, 2), Pair(50, -12), Pair(53, -30), Pair(67, -9), Pair(95, 23), Pair(29, 34), Pair(71, 25), Pair(0, 0),
        Pair(14, 12), Pair(10, 15), Pair(21, 19), Pair(24, 17), Pair(16, 19), Pair(36, 13), Pair(44, 54), Pair(49, 19),
        Pair(3, 0), Pair(58, 25), Pair(35, -13), Pair(44, -19), Pair(39, -6), Pair(13, 9), Pair(116, -3), Pair(50, -26),
        Pair(-4, 22), Pair(-10, 19), Pair(24, 6), Pair(-2, 20), Pair(-15, 12), Pair(12, 8), Pair(22, -2), Pair(48, -10),
        Pair(-48, 34), Pair(59, -24), Pair(21, -22), Pair(19, -7), Pair(44, -29), Pair(44, -17), Pair(-20, -41), Pair(13, -2),
        Pair(64, -110), Pair(2, -13), Pair(-45, -10), Pair(-4, -49), Pair(12, -38), Pair(43, -77), Pair(-7, -34), Pair(-99, 39)
      },
      { // Piece 2
        Pair(135, -8), Pair(87, -74), Pair(5, -46), Pair(114, -28), Pair(174, -18), Pair(78, -20), Pair(-30, 14), Pair(-111, 24),
        Pair(35, -37), Pair(77, -28), Pair(-33, -42), Pair(34, -55), Pair(51, -38), Pair(9, -13), Pair(117, -38), Pair(-60, -20),
        Pair(-5, -40), Pair(74, -64), Pair(76, -24), Pair(57, -54), Pair(68, -25), Pair(89, -43), Pair(127, -51), Pair(0, 0),
        Pair(-31, 4), Pair(74, -46), Pair(37, -29), Pair(58, -10), Pair(54, -43), Pair(100, 4), Pair(72, -23), Pair(85, -16),
        Pair(-20, 17), Pair(86, -59), Pair(51, -28), Pair(79, -43), Pair(15, -13), Pair(6, -5), Pair(27, -9), Pair(67, -18),
        Pair(25, -61), Pair(10, -14), Pair(3, -44), Pair(40, -22), Pair(31, -18), Pair(25, -3), Pair(30, -41), Pair(62, -11),
        Pair(83, -37), Pair(24, -33), Pair(58, -39), Pair(22, -26), Pair(24, -18), Pair(6, -11), Pair(20, -38), Pair(-57, 59),
        Pair(20, -49), Pair(74, -31), Pair(14, -11), Pair(32, -30), Pair(28, -56), Pair(22, -37), Pair(26, -14), Pair(82, -86)
      },
      { // Piece 3
        Pair(-31, 41), Pair(23, -31), Pair(-8, 47), Pair(177, -61), Pair(76, 12), Pair(44, 31), Pair(158, -21), Pair(73, -26),
        Pair(31, 25), Pair(40, 5), Pair(43, 16), Pair(94, -18), Pair(33, 10), Pair(48, -1), Pair(70, 35), Pair(136, -125),
        Pair(-4, 36), Pair(76, -4), Pair(10, 13), Pair(45, -22), Pair(89, -13), Pair(91, -16), Pair(104, 1), Pair(0, 0),
        Pair(-5, 32), Pair(-26, 26), Pair(13, 1), Pair(19, 7), Pair(36, -24), Pair(-9, -22), Pair(-16, 33), Pair(-26, -34),
        Pair(-29, 5), Pair(-3, -12), Pair(37, 22), Pair(-5, 17), Pair(45, -7), Pair(-33, 17), Pair(-57, 46), Pair(-54, -15),
        Pair(27, -8), Pair(-21, 13), Pair(-8, -24), Pair(-4, -8), Pair(-16, 53), Pair(-38, 13), Pair(-30, 30), Pair(-47, 4),
        Pair(-14, -25), Pair(51, -38), Pair(-10, 4), Pair(-21, -8), Pair(-2, 13), Pair(-23, 29), Pair(-41, 18), Pair(-59, -4),
        Pair(22, -27), Pair(6, 11), Pair(5, -1), Pair(19, -31), Pair(29, -17), Pair(12, -19), Pair(14, -31), Pair(-24, -11)
      },
      { // Piece 4
        Pair(-4, 20), Pair(-44, 71), Pair(78, -15), Pair(18, -57), Pair(92, -73), Pair(54, 0), Pair(54, -108), Pair(39, -4),
        Pair(-19, 93), Pair(-8, 23), Pair(51, -83), Pair(-51, 81), Pair(115, -58), Pair(21, -14), Pair(-4, 50), Pair(-61, -83),
        Pair(-45, 119), Pair(-32, 5), Pair(21, 31), Pair(7, 9), Pair(37, -21), Pair(114, -42), Pair(33, -64), Pair(0, 0),
        Pair(-39, 57), Pair(-19, 61), Pair(14, -5), Pair(-48, 67), Pair(102, -4), Pair(54, -1), Pair(13, -8), Pair(59, -121),
        Pair(-3, -7), Pair(18, -41), Pair(-16, 92), Pair(31, -6), Pair(15, 28), Pair(30, -49), Pair(32, -72), Pair(21, 45),
        Pair(23, -196), Pair(-24, -3), Pair(-35, 44), Pair(7, -22), Pair(-14, 16), Pair(15, -37), Pair(21, -20), Pair(-30, -20),
        Pair(-68, 24), Pair(0, -39), Pair(5, -72), Pair(1, 4), Pair(13, -64), Pair(-13, -59), Pair(-6, -12), Pair(-29, -63),
        Pair(-14, 69), Pair(-62, -70), Pair(2, -28), Pair(-4, -35), Pair(-45, 71), Pair(-30, -62), Pair(56, -68), Pair(2, -70)
      },
      { // Piece 5
        Pair(-14, -41), Pair(-43, 25), Pair(13, 27), Pair(-12, -95), Pair(54, 22), Pair(1, 60), Pair(-147, 89), Pair(99, -60),
        Pair(-34, 1), Pair(71, 52), Pair(99, 34), Pair(-25, 45), Pair(125, -68), Pair(-21, 82), Pair(13, 60), Pair(34, -86),
        Pair(-36, 37), Pair(3, -33), Pair(21, 2), Pair(24, 7), Pair(67, 48), Pair(115, 18), Pair(133, 17), Pair(0, 0),
        Pair(-74, 36), Pair(-21, -4), Pair(125, -17), Pair(-95, 25), Pair(51, -3), Pair(103, 18), Pair(73, 3), Pair(97, 3),
        Pair(61, -30), Pair(-25, 11), Pair(-114, 33), Pair(1, 10), Pair(17, 3), Pair(87, 0), Pair(13, 22), Pair(-15, -18),
        Pair(-200, 14), Pair(-55, 27), Pair(21, 10), Pair(-22, -2), Pair(30, 3), Pair(-3, -2), Pair(10, 18), Pair(-1, -9),
        Pair(7, -13), Pair(-41, 20), Pair(-40, 2), Pair(-7, 0), Pair(-15, 9), Pair(-36, 14), Pair(-5, 4), Pair(9, 24),
        Pair(-35, 13), Pair(-1, -7), Pair(-35, -1), Pair(-19, -20), Pair(-11, 1), Pair(22, -15), Pair(16, 18), Pair(25, -20)
      }
    }},
    {{ // Bucket 24
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-17, 34), Pair(34, 14), Pair(1, -1), Pair(-13, 22), Pair(-14, -5), Pair(9, 23), Pair(35, -14), Pair(-31, 41),
        Pair(4, -28), Pair(6, 8), Pair(18, -2), Pair(6, 10), Pair(6, 11), Pair(0, 11), Pair(14, 1), Pair(6, -1),
        Pair(-5, 16), Pair(-14, 3), Pair(-4, 5), Pair(9, 4), Pair(5, 5), Pair(1, 11), Pair(-4, 11), Pair(2, 10),
        Pair(6, -19), Pair(-7, 1), Pair(2, 9), Pair(2, 9), Pair(3, 8), Pair(0, 10), Pair(1, 12), Pair(0, 12),
        Pair(5, 12), Pair(-6, 12), Pair(1, 12), Pair(-3, 6), Pair(-2, 9), Pair(3, 8), Pair(3, 10), Pair(-1, 12),
        Pair(2, 14), Pair(-6, 8), Pair(-1, 8), Pair(-3, 15), Pair(-5, 12), Pair(-2, 12), Pair(-4, 13), Pair(-1, 11),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-11, 14), Pair(-111, 62), Pair(-54, 43), Pair(74, 15), Pair(-29, 22), Pair(-5, 31), Pair(75, 3), Pair(74, -21),
        Pair(-19, 32), Pair(1, 14), Pair(42, 28), Pair(55, 19), Pair(62, 13), Pair(-5, 40), Pair(-49, 83), Pair(10, 61),
        Pair(-76, 7), Pair(6, 27), Pair(40, 27), Pair(11, 35), Pair(4, 29), Pair(2, 44), Pair(-6, 26), Pair(-21, 2),
        Pair(0, 0), Pair(6, 43), Pair(0, 30), Pair(20, 18), Pair(22, 41), Pair(0, 28), Pair(2, 38), Pair(-27, 52),
        Pair(27, 42), Pair(-5, 53), Pair(20, 27), Pair(8, 30), Pair(14, 30), Pair(7, 26), Pair(-7, 26), Pair(10, 12),
        Pair(1, 13), Pair(3, 8), Pair(8, 32), Pair(14, 21), Pair(11, 27), Pair(8, 22), Pair(8, 19), Pair(0, 4),
        Pair(17, -41), Pair(23, -6), Pair(18, 32), Pair(5, 16), Pair(3, 16), Pair(0, 30), Pair(2, 17), Pair(-1, 33),
        Pair(-25, -27), Pair(-5, -1), Pair(-8, -3), Pair(-7, 29), Pair(18, 17), Pair(-2, 22), Pair(1, 17), Pair(88, -108)
      },
      { // Piece 2
        Pair(-53, 64), Pair(85, -3), Pair(-104, 71), Pair(68, -20), Pair(-6, 20), Pair(84, -28), Pair(52, -38), Pair(-35, -24),
        Pair(29, 12), Pair(28, 44), Pair(22, -1), Pair(66, 13), Pair(49, -17), Pair(43, 2), Pair(45, -19), Pair(-6, 34),
        Pair(5, 3), Pair(39, 18), Pair(35, 24), Pair(26, -1), Pair(24, 20), Pair(34, -10), Pair(2, 15), Pair(-1, 4),
        Pair(0, 0), Pair(28, 17), Pair(26, 5), Pair(13, 33), Pair(32, -5), Pair(47, 18), Pair(13, -7), Pair(8, 23),
        Pair(23, 40), Pair(29, 18), Pair(24, 27), Pair(21, 6), Pair(25, 32), Pair(8, -7), Pair(22, 18), Pair(7, -28),
        Pair(16, -8), Pair(19, 18), Pair(14, 4), Pair(8, 27), Pair(17, 10), Pair(11, 32), Pair(4, 16), Pair(16, 11),
        Pair(44, -61), Pair(5, 6), Pair(12, 9), Pair(11, 8), Pair(14, 26), Pair(8, 18), Pair(10, 36), Pair(20, -8),
        Pair(50, -49), Pair(13, 21), Pair(8, -8), Pair(31, 8), Pair(22, -1), Pair(8, 29), Pair(1, 10), Pair(21, 4)
      },
      { // Piece 3
        Pair(4, 15), Pair(-33, 67), Pair(-40, 74), Pair(-6, 59), Pair(-78, 76), Pair(40, 52), Pair(-42, 82), Pair(16, 55),
        Pair(-18, 30), Pair(4, 59), Pair(11, 55), Pair(-22, 67), Pair(-2, 59), Pair(-16, 46), Pair(-5, 59), Pair(70, 36),
        Pair(-32, 8), Pair(27, 55), Pair(36, 53), Pair(-30, 75), Pair(11, 62), Pair(1, 73), Pair(83, 40), Pair(23, 41),
        Pair(0, 0), Pair(15, 71), Pair(11, 56), Pair(38, 45), Pair(33, 47), Pair(19, 52), Pair(22, 51), Pair(40, 50),
        Pair(-27, 48), Pair(3, 62), Pair(7, 67), Pair(-3, 60), Pair(9, 52), Pair(-4, 55), Pair(8, 57), Pair(-14, 84),
        Pair(-20, 34), Pair(0, 64), Pair(11, 38), Pair(-3, 60), Pair(9, 41), Pair(12, 42), Pair(-16, 72), Pair(23, 25),
        Pair(-50, 52), Pair(5, 47), Pair(-5, 54), Pair(-5, 59), Pair(13, 39), Pair(-7, 32), Pair(12, 13), Pair(-5, 67),
        Pair(-24, 33), Pair(1, 58), Pair(8, 53), Pair(4, 46), Pair(-2, 52), Pair(8, 41), Pair(-4, 53), Pair(13, 24)
      },
      { // Piece 4
        Pair(17, 81), Pair(36, 34), Pair(-4, 86), Pair(-55, 126), Pair(-51, 108), Pair(61, 45), Pair(136, -35), Pair(-9, 156),
        Pair(-37, 100), Pair(-3, 106), Pair(29, 90), Pair(19, 84), Pair(31, 39), Pair(25, 82), Pair(-3, 84), Pair(58, -30),
        Pair(-9, 36), Pair(-2, 133), Pair(-6, 120), Pair(21, 60), Pair(2, 58), Pair(3, 101), Pair(52, 55), Pair(9, 71),
        Pair(0, 0), Pair(17, 98), Pair(16, 91), Pair(12, 67), Pair(-9, 110), Pair(13, 88), Pair(-5, 77), Pair(19, 61),
        Pair(14, 106), Pair(27, 82), Pair(15, 101), Pair(28, 54), Pair(9, 76), Pair(18, 101), Pair(0, 123), Pair(47, 23),
        Pair(-5, 106), Pair(21, 96), Pair(17, 79), Pair(25, 75), Pair(32, 68), Pair(22, 80), Pair(27, 52), Pair(46, 33),
        Pair(22, 70), Pair(21, 56), Pair(16, 85), Pair(25, 86), Pair(22, 89), Pair(29, 50), Pair(6, 41), Pair(7, 31),
        Pair(8, 52), Pair(28, 58), Pair(12, 67), Pair(18, 87), Pair(30, 88), Pair(45, 46), Pair(-56, 110), Pair(-27, 94)
      },
      { // Piece 5
        Pair(-4, -36), Pair(63, 63), Pair(-44, 50), Pair(73, 22), Pair(-12, 104), Pair(-20, 30), Pair(55, -18), Pair(51, -15),
        Pair(-119, 105), Pair(10, 105), Pair(-31, 60), Pair(4, 75), Pair(-32, 25), Pair(6, 43), Pair(77, -34), Pair(118, -7),
        Pair(0, 6), Pair(55, 73), Pair(101, 78), Pair(26, 47), Pair(76, 26), Pair(56, 6), Pair(-68, 46), Pair(-76, 6),
        Pair(0, 0), Pair(13, 67), Pair(25, 54), Pair(20, 52), Pair(77, 36), Pair(-28, 51), Pair(-6, 2), Pair(-76, 25),
        Pair(-48, 19), Pair(17, 40), Pair(11, 66), Pair(25, 48), Pair(32, 20), Pair(-46, 25), Pair(-30, 10), Pair(-80, 13),
        Pair(37, -10), Pair(43, 43), Pair(56, 29), Pair(26, 16), Pair(4, 26), Pair(-25, 21), Pair(-32, 10), Pair(-32, -3),
        Pair(18, 11), Pair(83, 34), Pair(5, 18), Pair(-12, 23), Pair(-32, 20), Pair(-11, 15), Pair(-14, 10), Pair(-10, -2),
        Pair(81, -39), Pair(94, 0), Pair(5, 40), Pair(-24, 2), Pair(-11, 12), Pair(-25, 16), Pair(-3, -1), Pair(-6, -11)
      }
    }},
    {{ // Bucket 25
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(8, 24), Pair(13, -10), Pair(-12, 30), Pair(23, 0), Pair(-16, 4), Pair(-13, 16), Pair(-40, 40), Pair(23, 1),
        Pair(-12, -1), Pair(-11, -19), Pair(6, 20), Pair(-13, 25), Pair(9, 5), Pair(-5, 10), Pair(-12, 14), Pair(1, 16),
        Pair(-13, 3), Pair(-1, 19), Pair(-5, 11), Pair(-5, 2), Pair(8, 10), Pair(8, 10), Pair(0, 14), Pair(-7, 14),
        Pair(1, 6), Pair(4, -10), Pair(1, 7), Pair(3, 6), Pair(5, 10), Pair(6, 7), Pair(2, 9), Pair(2, 10),
        Pair(-3, 11), Pair(5, 6), Pair(-1, 11), Pair(3, 8), Pair(3, 6), Pair(2, 10), Pair(5, 13), Pair(5, 10),
        Pair(-7, 14), Pair(3, 2), Pair(-6, 15), Pair(5, 7), Pair(-2, 16), Pair(1, 12), Pair(-2, 11), Pair(3, 14),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(22, 31), Pair(141, -9), Pair(-11, 23), Pair(46, 76), Pair(-51, 9), Pair(-154, 86), Pair(66, -19), Pair(74, -78),
        Pair(34, 18), Pair(2, 23), Pair(10, 32), Pair(47, 36), Pair(6, 59), Pair(16, 53), Pair(-9, 46), Pair(-62, 36),
        Pair(7, 13), Pair(5, 10), Pair(53, 26), Pair(-20, 52), Pair(-6, 65), Pair(65, 17), Pair(-4, 36), Pair(-8, 42),
        Pair(3, 30), Pair(0, 0), Pair(14, 52), Pair(8, 63), Pair(5, 45), Pair(-3, 50), Pair(10, 24), Pair(19, 5),
        Pair(2, 71), Pair(29, 56), Pair(27, 54), Pair(8, 40), Pair(10, 42), Pair(8, 50), Pair(-10, 62), Pair(7, 21),
        Pair(-20, 2), Pair(12, 33), Pair(-3, 46), Pair(23, 33), Pair(9, 31), Pair(10, 30), Pair(6, 45), Pair(13, 0),
        Pair(-18, 20), Pair(21, 20), Pair(-5, 37), Pair(2, 29), Pair(1, 32), Pair(7, 19), Pair(15, 20), Pair(-10, 40),
        Pair(-32, 53), Pair(-23, 32), Pair(9, 15), Pair(-13, 28), Pair(2, 37), Pair(5, 24), Pair(6, -18), Pair(16, -33)
      },
      { // Piece 2
        Pair(70, -14), Pair(9, 66), Pair(81, -54), Pair(-33, 43), Pair(-30, 4), Pair(-12, 30), Pair(81, -49), Pair(1, 35),
        Pair(-13, 43), Pair(35, -17), Pair(2, 38), Pair(-12, 9), Pair(9, 20), Pair(12, -8), Pair(86, -11), Pair(49, -33),
        Pair(-18, 15), Pair(36, -2), Pair(76, -6), Pair(-7, 26), Pair(38, -8), Pair(-3, 25), Pair(62, -33), Pair(-9, 21),
        Pair(-7, 42), Pair(0, 0), Pair(15, 23), Pair(34, 2), Pair(-1, 34), Pair(17, -2), Pair(-2, 7), Pair(26, 2),
        Pair(-2, 3), Pair(17, 55), Pair(26, 0), Pair(17, 29), Pair(17, 0), Pair(7, 26), Pair(9, 17), Pair(16, 5),
        Pair(7, 21), Pair(-8, 14), Pair(1, 31), Pair(9, 10), Pair(8, 43), Pair(6, 18), Pair(1, 39), Pair(6, 15),
        Pair(-6, 4), Pair(7, 21), Pair(-1, 8), Pair(7, 23), Pair(3, 22), Pair(7, 40), Pair(5, 34), Pair(7, 49),
        Pair(2, 18), Pair(-5, 30), Pair(3, 27), Pair(7, 8), Pair(15, 22), Pair(-1, 12), Pair(37, 43), Pair(-8, 11)
      },
      { // Piece 3
        Pair(37, 14), Pair(-34, 28), Pair(-3, 50), Pair(22, 49), Pair(-62, 96), Pair(-41, 89), Pair(22, 49), Pair(-3, 43),
        Pair(-4, 48), Pair(-68, 54), Pair(9, 51), Pair(12, 57), Pair(-10, 42), Pair(-19, 49), Pair(49, 52), Pair(2, 52),
        Pair(-23, 68), Pair(-51, 17), Pair(10, 61), Pair(-13, 68), Pair(-13, 69), Pair(4, 62), Pair(38, 50), Pair(23, 47),
        Pair(-8, 78), Pair(0, 0), Pair(4, 64), Pair(-1, 60), Pair(12, 66), Pair(-17, 49), Pair(-13, 62), Pair(-41, 79),
        Pair(-7, 76), Pair(-1, 42), Pair(10, 68), Pair(1, 60), Pair(-4, 57), Pair(-8, 48), Pair(-10, 54), Pair(-14, 51),
        Pair(12, 37), Pair(-23, 39), Pair(0, 57), Pair(-14, 57), Pair(10, 29), Pair(-11, 49), Pair(-6, 60), Pair(-22, 69),
        Pair(-11, 51), Pair(-22, 30), Pair(-2, 48), Pair(-14, 63), Pair(6, 40), Pair(-4, 27), Pair(-11, 56), Pair(-69, 75),
        Pair(0, 40), Pair(-15, 27), Pair(-3, 52), Pair(6, 48), Pair(-2, 50), Pair(0, 35), Pair(-19, 56), Pair(3, 27)
      },
      { // Piece 4
        Pair(41, 39), Pair(32, -10), Pair(-20, 40), Pair(-68, 76), Pair(13, 28), Pair(96, -33), Pair(36, 13), Pair(58, -25),
        Pair(10, 3), Pair(4, 38), Pair(18, 5), Pair(23, 50), Pair(-36, 74), Pair(-16, 21), Pair(53, 30), Pair(-5, 89),
        Pair(-33, 46), Pair(-9, -17), Pair(-10, 68), Pair(-20, 33), Pair(-8, 102), Pair(-44, 124), Pair(9, 86), Pair(-35, 46),
        Pair(1, 48), Pair(0, 0), Pair(-39, 100), Pair(-27, 76), Pair(10, 27), Pair(-15, 80), Pair(0, 44), Pair(-5, 40),
        Pair(-11, 43), Pair(11, 11), Pair(4, 66), Pair(2, 71), Pair(-16, 58), Pair(-6, 57), Pair(-20, 82), Pair(32, -12),
        Pair(6, 41), Pair(9, 29), Pair(-5, 58), Pair(4, 52), Pair(-9, 64), Pair(20, 40), Pair(5, 45), Pair(15, 26),
        Pair(-1, 32), Pair(7, 3), Pair(1, 40), Pair(6, 45), Pair(9, 62), Pair(8, 45), Pair(16, 27), Pair(33, -12),
        Pair(4, 33), Pair(-9, -16), Pair(-5, 74), Pair(2, 33), Pair(-3, 34), Pair(-19, 54), Pair(18, 7), Pair(31, -9)
      },
      { // Piece 5
        Pair(2, 94), Pair(30, 72), Pair(23, 117), Pair(68, 71), Pair(-17, 121), Pair(38, -12), Pair(38, -20), Pair(11, 18),
        Pair(-179, 163), Pair(-213, 124), Pair(14, 85), Pair(85, 36), Pair(186, 27), Pair(35, 63), Pair(56, -4), Pair(88, 37),
        Pair(109, 72), Pair(-7, 54), Pair(202, 35), Pair(-95, 81), Pair(87, 55), Pair(16, 17), Pair(44, 17), Pair(-63, 24),
        Pair(74, 74), Pair(0, 0), Pair(86, 57), Pair(39, 39), Pair(15, 25), Pair(-42, 26), Pair(-57, 19), Pair(-84, 17),
        Pair(14, 65), Pair(72, 25), Pair(67, 38), Pair(28, 44), Pair(-7, 36), Pair(-72, 36), Pair(0, 12), Pair(30, -19),
        Pair(-39, 54), Pair(65, 16), Pair(12, 39), Pair(-26, 40), Pair(-12, 15), Pair(-40, 22), Pair(-16, 6), Pair(-94, 21),
        Pair(39, 47), Pair(38, 11), Pair(18, 18), Pair(-2, 14), Pair(-29, 25), Pair(-29, 11), Pair(-10, 6), Pair(-11, -7),
        Pair(68, -24), Pair(53, -45), Pair(28, 6), Pair(-30, 15), Pair(-8, -6), Pair(-3, -1), Pair(-4, -4), Pair(-7, -24)
      }
    }},
    {{ // Bucket 26
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(21, 9), Pair(17, 32), Pair(-64, -5), Pair(28, 24), Pair(-16, 36), Pair(-78, 57), Pair(57, 9), Pair(-37, 9),
        Pair(2, 9), Pair(-6, 11), Pair(0, -43), Pair(8, 33), Pair(11, 5), Pair(17, 16), Pair(4, 11), Pair(6, 13),
        Pair(-4, 6), Pair(-6, 12), Pair(-2, 12), Pair(6, 6), Pair(4, -2), Pair(4, 14), Pair(3, 11), Pair(9, 4),
        Pair(1, 6), Pair(7, 11), Pair(-4, -23), Pair(11, 10), Pair(-1, 9), Pair(7, 8), Pair(2, 9), Pair(-1, 10),
        Pair(3, 9), Pair(-3, 10), Pair(0, -4), Pair(-3, 14), Pair(1, 11), Pair(3, 6), Pair(4, 11), Pair(2, 8),
        Pair(0, 10), Pair(-5, 8), Pair(-1, -6), Pair(-4, 28), Pair(-1, 6), Pair(0, 13), Pair(2, 9), Pair(0, 11),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-63, 127), Pair(0, 59), Pair(111, 22), Pair(69, 23), Pair(-27, 77), Pair(103, -24), Pair(-54, 5), Pair(26, 33),
        Pair(-10, 53), Pair(-35, 57), Pair(62, 53), Pair(46, 23), Pair(65, 27), Pair(60, 2), Pair(-19, 58), Pair(88, 12),
        Pair(-40, 24), Pair(-23, 52), Pair(-26, 31), Pair(55, 43), Pair(31, 23), Pair(16, 31), Pair(14, 48), Pair(-18, 23),
        Pair(-2, 50), Pair(1, 49), Pair(0, 0), Pair(24, 54), Pair(11, 48), Pair(31, 54), Pair(17, 42), Pair(40, 36),
        Pair(-2, 13), Pair(32, 54), Pair(22, 76), Pair(31, 50), Pair(3, 58), Pair(19, 38), Pair(-6, 33), Pair(-3, 51),
        Pair(-3, 48), Pair(6, 35), Pair(15, 34), Pair(13, 38), Pair(22, 37), Pair(3, 53), Pair(3, 36), Pair(18, 25),
        Pair(-2, 85), Pair(4, 27), Pair(16, 57), Pair(7, 47), Pair(7, 38), Pair(19, 45), Pair(14, 19), Pair(21, 38),
        Pair(21, 33), Pair(3, 14), Pair(-31, 28), Pair(10, 19), Pair(8, 37), Pair(0, 45), Pair(7, 23), Pair(25, -12)
      },
      { // Piece 2
        Pair(-7, 74), Pair(51, -10), Pair(102, 39), Pair(-29, 9), Pair(1, 42), Pair(18, -25), Pair(66, -14), Pair(118, -37),
        Pair(20, -9), Pair(53, 45), Pair(0, 3), Pair(29, 8), Pair(71, -39), Pair(-17, 17), Pair(10, -13), Pair(29, 2),
        Pair(34, 9), Pair(-32, 7), Pair(7, -10), Pair(71, 10), Pair(-21, 10), Pair(36, -6), Pair(47, 3), Pair(25, 37),
        Pair(4, 6), Pair(18, 17), Pair(0, 0), Pair(21, 16), Pair(24, -10), Pair(24, 43), Pair(5, 15), Pair(26, 26),
        Pair(37, 14), Pair(-9, -1), Pair(32, 52), Pair(13, 6), Pair(37, 34), Pair(11, 21), Pair(14, 30), Pair(18, 28),
        Pair(-1, -29), Pair(12, 30), Pair(3, 8), Pair(9, 45), Pair(2, 8), Pair(11, 52), Pair(16, -4), Pair(6, 25),
        Pair(27, -9), Pair(-5, 23), Pair(29, 13), Pair(6, 16), Pair(11, 35), Pair(9, -5), Pair(15, 43), Pair(49, 10),
        Pair(-2, 29), Pair(40, 17), Pair(0, 15), Pair(26, 25), Pair(-12, 34), Pair(3, 30), Pair(17, -2), Pair(46, -17)
      },
      { // Piece 3
        Pair(-32, 75), Pair(-4, 51), Pair(-14, 42), Pair(16, 48), Pair(-46, 73), Pair(-64, 91), Pair(19, 47), Pair(45, 46),
        Pair(-16, 70), Pair(-7, 59), Pair(-29, 37), Pair(-28, 57), Pair(-25, 71), Pair(-45, 82), Pair(21, 58), Pair(36, 55),
        Pair(4, 62), Pair(7, 52), Pair(18, -10), Pair(-2, 60), Pair(3, 46), Pair(-6, 44), Pair(40, 67), Pair(25, 68),
        Pair(14, 22), Pair(8, 46), Pair(0, 0), Pair(35, 34), Pair(17, 34), Pair(-13, 48), Pair(14, 39), Pair(-10, 50),
        Pair(2, 50), Pair(21, 38), Pair(8, 18), Pair(5, 39), Pair(-8, 48), Pair(-4, 43), Pair(-9, 62), Pair(8, 35),
        Pair(26, 32), Pair(-1, 42), Pair(8, 24), Pair(-11, 56), Pair(5, 48), Pair(11, 32), Pair(-23, 52), Pair(-2, 44),
        Pair(-2, 43), Pair(12, 29), Pair(-11, 19), Pair(-19, 60), Pair(5, 49), Pair(13, 28), Pair(-10, 42), Pair(18, 29),
        Pair(2, 37), Pair(2, 36), Pair(-7, 17), Pair(5, 38), Pair(-1, 42), Pair(-1, 40), Pair(11, 32), Pair(1, 22)
      },
      { // Piece 4
        Pair(67, -24), Pair(-8, 60), Pair(-8, 36), Pair(-5, 45), Pair(-6, 53), Pair(49, 23), Pair(47, 1), Pair(44, 36),
        Pair(-3, 39), Pair(16, 43), Pair(-10, 22), Pair(-29, 90), Pair(0, 26), Pair(11, 29), Pair(79, 88), Pair(20, 47),
        Pair(12, 57), Pair(-32, 24), Pair(22, -40), Pair(-2, 61), Pair(-26, 75), Pair(-22, 135), Pair(24, 66), Pair(0, 38),
        Pair(-11, 56), Pair(-2, 46), Pair(0, 0), Pair(-15, 71), Pair(9, 69), Pair(-16, 95), Pair(-5, 48), Pair(-34, 82),
        Pair(20, 54), Pair(7, 55), Pair(0, 59), Pair(5, 65), Pair(9, 40), Pair(0, 80), Pair(-14, 54), Pair(-27, 70),
        Pair(10, 19), Pair(10, 23), Pair(-1, 49), Pair(0, 57), Pair(-5, 55), Pair(-5, 49), Pair(1, 78), Pair(24, 59),
        Pair(-15, 92), Pair(4, 56), Pair(4, 38), Pair(5, 43), Pair(-3, 57), Pair(4, 5), Pair(33, 29), Pair(6, -4),
        Pair(14, 20), Pair(-11, 59), Pair(2, 43), Pair(-2, 66), Pair(-6, 66), Pair(15, 30), Pair(14, -10), Pair(13, 54)
      },
      { // Piece 5
        Pair(-18, 35), Pair(31, 70), Pair(38, 56), Pair(39, 144), Pair(3, 13), Pair(209, -54), Pair(-18, 41), Pair(-40, 5),
        Pair(48, 59), Pair(52, 138), Pair(142, 96), Pair(4, 132), Pair(81, 23), Pair(-46, 49), Pair(-183, 41), Pair(-76, -12),
        Pair(92, 54), Pair(178, 28), Pair(103, 7), Pair(134, 12), Pair(7, 65), Pair(56, -10), Pair(10, 26), Pair(-76, 27),
        Pair(118, 56), Pair(35, 88), Pair(0, 0), Pair(116, 44), Pair(104, 16), Pair(108, -4), Pair(-32, 17), Pair(-50, -1),
        Pair(-61, 49), Pair(105, 16), Pair(30, 34), Pair(8, 34), Pair(-55, 30), Pair(-62, 21), Pair(-85, 5), Pair(-40, -3),
        Pair(4, 24), Pair(-28, 38), Pair(48, 25), Pair(5, 31), Pair(-1, 5), Pair(-11, 8), Pair(-17, -6), Pair(-25, -10),
        Pair(43, -6), Pair(60, 2), Pair(20, 0), Pair(33, -3), Pair(-6, 8), Pair(0, -8), Pair(-5, -10), Pair(-10, -19),
        Pair(-15, 28), Pair(32, -39), Pair(21, 6), Pair(-6, 9), Pair(-2, -1), Pair(-1, -11), Pair(0, -18), Pair(-6, -26)
      }
    }},
    {{ // Bucket 27
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(1, 21), Pair(-19, 29), Pair(1, 42), Pair(-1, 7), Pair(26, 27), Pair(48, -12), Pair(-29, 28), Pair(9, 13),
        Pair(3, 12), Pair(-14, 22), Pair(3, 17), Pair(-5, -36), Pair(-3, 33), Pair(-2, 11), Pair(1, 12), Pair(-8, 20),
        Pair(7, 3), Pair(-4, 1), Pair(7, 5), Pair(2, -10), Pair(1, 17), Pair(2, -3), Pair(7, 8), Pair(6, 5),
        Pair(2, 9), Pair(1, 9), Pair(3, 7), Pair(-5, 0), Pair(8, 13), Pair(9, 7), Pair(4, 6), Pair(2, 9),
        Pair(-2, 11), Pair(3, 12), Pair(-4, 10), Pair(4, 6), Pair(0, 13), Pair(4, 11), Pair(3, 11), Pair(2, 8),
        Pair(-2, 13), Pair(2, 6), Pair(-4, 18), Pair(8, 16), Pair(2, 15), Pair(-2, 12), Pair(2, 8), Pair(1, 10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(10, 52), Pair(-38, 71), Pair(1, 68), Pair(-13, 65), Pair(-54, 29), Pair(-57, 68), Pair(157, 10), Pair(-106, 51),
        Pair(-33, 68), Pair(-3, 74), Pair(-15, 43), Pair(13, 41), Pair(8, 56), Pair(43, 76), Pair(47, 31), Pair(-24, 99),
        Pair(71, 34), Pair(5, 30), Pair(49, 17), Pair(-22, 27), Pair(41, 52), Pair(28, 39), Pair(2, 47), Pair(42, 40),
        Pair(27, 43), Pair(1, 63), Pair(21, 55), Pair(0, 0), Pair(5, 64), Pair(25, 46), Pair(-7, 74), Pair(-7, 57),
        Pair(4, 38), Pair(-1, 38), Pair(22, 80), Pair(24, 74), Pair(10, 63), Pair(8, 42), Pair(-4, 50), Pair(5, 27),
        Pair(2, 38), Pair(10, 12), Pair(0, 40), Pair(14, 49), Pair(-1, 36), Pair(3, 58), Pair(4, 47), Pair(18, 45),
        Pair(-1, 30), Pair(14, 43), Pair(-17, 49), Pair(9, 47), Pair(5, 40), Pair(13, 49), Pair(-2, 40), Pair(7, 13),
        Pair(-8, 48), Pair(-8, 42), Pair(-8, 21), Pair(18, 13), Pair(6, 43), Pair(-4, 58), Pair(0, -14), Pair(68, -86)
      },
      { // Piece 2
        Pair(-92, -18), Pair(-28, 44), Pair(104, -34), Pair(25, 10), Pair(62, -6), Pair(31, 16), Pair(-2, 49), Pair(-61, -33),
        Pair(2, 27), Pair(-6, -38), Pair(52, 38), Pair(32, -27), Pair(70, -11), Pair(-7, -23), Pair(-8, 13), Pair(-4, 14),
        Pair(-1, -1), Pair(40, 40), Pair(-4, -15), Pair(-26, 23), Pair(39, 19), Pair(13, 23), Pair(15, -17), Pair(-5, 63),
        Pair(28, 23), Pair(15, -9), Pair(44, 23), Pair(0, 0), Pair(15, 37), Pair(19, -18), Pair(16, 22), Pair(-1, 7),
        Pair(13, 5), Pair(34, 32), Pair(3, -12), Pair(35, 55), Pair(1, 4), Pair(21, 43), Pair(8, -27), Pair(27, 7),
        Pair(16, 33), Pair(-16, -10), Pair(14, 53), Pair(7, -1), Pair(18, 26), Pair(-1, -3), Pair(16, 55), Pair(16, -6),
        Pair(-15, -21), Pair(12, 25), Pair(15, -13), Pair(19, 27), Pair(1, 7), Pair(4, 46), Pair(-8, 1), Pair(13, 56),
        Pair(16, 13), Pair(-4, -19), Pair(3, 39), Pair(4, 12), Pair(3, 29), Pair(-4, 7), Pair(13, 21), Pair(13, -60)
      },
      { // Piece 3
        Pair(-28, 49), Pair(8, 48), Pair(-45, 65), Pair(4, 43), Pair(22, 58), Pair(1, 62), Pair(-20, 61), Pair(45, 34),
        Pair(2, 49), Pair(-8, 57), Pair(-15, 58), Pair(-11, 43), Pair(0, 43), Pair(29, 42), Pair(-28, 89), Pair(15, 59),
        Pair(-5, 55), Pair(-7, 56), Pair(4, 59), Pair(-57, -3), Pair(-4, 80), Pair(4, 53), Pair(20, 67), Pair(-32, 59),
        Pair(8, 52), Pair(-16, 58), Pair(6, 29), Pair(0, 0), Pair(-1, 50), Pair(3, 35), Pair(46, 20), Pair(44, 23),
        Pair(16, 39), Pair(-4, 68), Pair(17, 47), Pair(11, 35), Pair(-10, 56), Pair(1, 39), Pair(3, 48), Pair(9, 29),
        Pair(23, 8), Pair(6, 42), Pair(1, 47), Pair(-24, 25), Pair(7, 40), Pair(-8, 40), Pair(3, 31), Pair(4, 42),
        Pair(-4, 26), Pair(-9, 53), Pair(-2, 39), Pair(-6, 25), Pair(9, 39), Pair(-14, 49), Pair(-7, 44), Pair(5, 51),
        Pair(1, 41), Pair(-1, 39), Pair(2, 35), Pair(8, 15), Pair(-2, 46), Pair(-3, 40), Pair(-12, 46), Pair(7, 28)
      },
      { // Piece 4
        Pair(-44, 59), Pair(-3, 102), Pair(26, 50), Pair(-45, 61), Pair(-62, 136), Pair(103, 2), Pair(107, 15), Pair(38, 39),
        Pair(11, 54), Pair(6, 35), Pair(19, 48), Pair(21, 24), Pair(20, 39), Pair(6, 16), Pair(105, 25), Pair(14, 78),
        Pair(16, 34), Pair(8, 57), Pair(12, 47), Pair(9, -49), Pair(-38, 92), Pair(8, 73), Pair(12, 109), Pair(-7, 68),
        Pair(6, 37), Pair(-21, 79), Pair(-5, 47), Pair(0, 0), Pair(8, 67), Pair(7, 61), Pair(-6, 71), Pair(7, 46),
        Pair(-10, 94), Pair(13, 40), Pair(-11, 83), Pair(18, 45), Pair(-20, 85), Pair(-5, 90), Pair(1, 66), Pair(19, 1),
        Pair(-4, 33), Pair(10, 30), Pair(19, 50), Pair(10, 28), Pair(2, 74), Pair(0, 52), Pair(6, 56), Pair(24, 23),
        Pair(6, 41), Pair(-8, 67), Pair(6, 50), Pair(7, 45), Pair(1, 72), Pair(9, 33), Pair(12, 50), Pair(1, 49),
        Pair(-10, 64), Pair(-23, 83), Pair(17, 38), Pair(4, 43), Pair(3, 67), Pair(15, 64), Pair(-9, 3), Pair(-61, 58)
      },
      { // Piece 5
        Pair(6, 83), Pair(74, 114), Pair(28, 113), Pair(-97, 66), Pair(55, 50), Pair(83, 6), Pair(-20, 16), Pair(-20, 8),
        Pair(50, 16), Pair(135, 52), Pair(39, 102), Pair(60, 68), Pair(-94, 80), Pair(-19, 11), Pair(0, 26), Pair(76, -23),
        Pair(-106, 42), Pair(57, 45), Pair(141, 4), Pair(-13, 27), Pair(109, 30), Pair(65, 29), Pair(73, 14), Pair(-132, 20),
        Pair(53, 29), Pair(81, 16), Pair(-31, 78), Pair(0, 0), Pair(-65, 77), Pair(9, 10), Pair(-66, 35), Pair(-42, 15),
        Pair(-13, 56), Pair(34, 43), Pair(-52, 45), Pair(-80, 72), Pair(-7, 27), Pair(-57, 30), Pair(-19, 6), Pair(-17, -16),
        Pair(41, 1), Pair(31, 8), Pair(19, 21), Pair(-48, 47), Pair(-11, 11), Pair(-37, 12), Pair(-9, 2), Pair(-26, -9),
        Pair(11, -20), Pair(25, -3), Pair(-17, 1), Pair(-27, 11), Pair(-15, -10), Pair(0, -10), Pair(-11, -5), Pair(10, -24),
        Pair(0, -47), Pair(-6, -18), Pair(-13, -27), Pair(-61, -2), Pair(4, -44), Pair(-20, -4), Pair(3, -21), Pair(8, -28)
      }
    }},
    {{ // Bucket 28
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-25, 10), Pair(1, 11), Pair(1, 15), Pair(6, 26), Pair(14, -8), Pair(-49, 7), Pair(1, 11), Pair(-4, 9),
        Pair(5, 9), Pair(2, 3), Pair(7, 17), Pair(9, 28), Pair(23, -49), Pair(18, 0), Pair(-6, 15), Pair(0, 4),
        Pair(6, 7), Pair(8, 9), Pair(4, -2), Pair(0, 18), Pair(6, -9), Pair(14, 6), Pair(-14, 1), Pair(0, 9),
        Pair(1, 10), Pair(6, 5), Pair(5, 11), Pair(10, 8), Pair(-3, -3), Pair(9, 8), Pair(3, 9), Pair(-2, 9),
        Pair(4, 8), Pair(6, 9), Pair(6, 8), Pair(3, 9), Pair(10, 10), Pair(0, 10), Pair(-2, 11), Pair(-5, 10),
        Pair(1, 10), Pair(4, 10), Pair(1, 6), Pair(-1, 14), Pair(7, 11), Pair(-5, 16), Pair(-6, 11), Pair(-6, 9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(39, 13), Pair(-43, 102), Pair(8, 60), Pair(33, 56), Pair(123, 55), Pair(24, 14), Pair(-118, 83), Pair(-68, 34),
        Pair(6, 61), Pair(66, 27), Pair(7, 18), Pair(11, 31), Pair(27, 46), Pair(21, 13), Pair(17, 54), Pair(19, 50),
        Pair(18, 52), Pair(-19, 72), Pair(12, 40), Pair(41, 49), Pair(10, 17), Pair(-18, 54), Pair(-9, 38), Pair(51, 11),
        Pair(-15, 61), Pair(13, 62), Pair(11, 53), Pair(33, 54), Pair(0, 0), Pair(22, 48), Pair(16, 52), Pair(26, 51),
        Pair(9, 44), Pair(15, 39), Pair(13, 35), Pair(18, 68), Pair(26, 89), Pair(28, 72), Pair(14, 27), Pair(21, 38),
        Pair(-7, 49), Pair(15, 37), Pair(4, 44), Pair(6, 39), Pair(17, 41), Pair(-3, 39), Pair(10, 43), Pair(0, 49),
        Pair(-15, 20), Pair(-2, 12), Pair(2, 59), Pair(5, 35), Pair(8, 52), Pair(-11, 48), Pair(11, 46), Pair(-3, 34),
        Pair(80, -38), Pair(-8, 43), Pair(8, 28), Pair(4, 28), Pair(-9, 40), Pair(3, 24), Pair(-10, 3), Pair(-20, 88)
      },
      { // Piece 2
        Pair(-23, 22), Pair(-78, -31), Pair(7, 36), Pair(47, -20), Pair(41, 49), Pair(48, -21), Pair(116, -22), Pair(79, -6),
        Pair(-13, 2), Pair(-14, 35), Pair(23, -6), Pair(20, 10), Pair(28, -12), Pair(49, 17), Pair(42, -16), Pair(33, 9),
        Pair(20, 17), Pair(5, -5), Pair(32, 19), Pair(14, 18), Pair(-4, -2), Pair(21, 17), Pair(50, 29), Pair(13, 10),
        Pair(-6, 4), Pair(19, 34), Pair(3, 3), Pair(16, 33), Pair(0, 0), Pair(36, 8), Pair(15, 5), Pair(6, 36),
        Pair(43, 7), Pair(20, -13), Pair(15, 38), Pair(-10, 15), Pair(33, 56), Pair(-6, -3), Pair(29, 23), Pair(9, -11),
        Pair(-6, 14), Pair(11, 26), Pair(-5, 4), Pair(23, 26), Pair(7, 2), Pair(5, 33), Pair(-20, -6), Pair(4, 40),
        Pair(33, 12), Pair(-14, -2), Pair(19, 8), Pair(-3, 10), Pair(10, 35), Pair(1, -2), Pair(3, 36), Pair(-36, 6),
        Pair(-32, 21), Pair(15, 17), Pair(-8, 7), Pair(13, 37), Pair(4, -1), Pair(1, 32), Pair(17, -12), Pair(5, -3)
      },
      { // Piece 3
        Pair(43, 20), Pair(64, 36), Pair(19, 40), Pair(39, 33), Pair(-82, 60), Pair(-26, 66), Pair(79, 32), Pair(75, 37),
        Pair(-13, 52), Pair(12, 45), Pair(16, 37), Pair(16, 42), Pair(-4, 29), Pair(26, 35), Pair(4, 47), Pair(-47, 70),
        Pair(-3, 65), Pair(26, 37), Pair(-24, 70), Pair(5, 51), Pair(-22, -23), Pair(40, 39), Pair(32, 57), Pair(37, 49),
        Pair(9, 36), Pair(6, 48), Pair(3, 37), Pair(-13, 50), Pair(0, 0), Pair(26, 21), Pair(8, 25), Pair(9, 42),
        Pair(12, 19), Pair(0, 36), Pair(6, 45), Pair(-8, 59), Pair(24, 29), Pair(27, 44), Pair(32, 53), Pair(-1, 59),
        Pair(8, 24), Pair(-6, 46), Pair(30, 27), Pair(11, 17), Pair(0, 13), Pair(-21, 67), Pair(25, 37), Pair(15, 40),
        Pair(-13, 46), Pair(-2, 31), Pair(-3, 26), Pair(0, 40), Pair(-3, 25), Pair(-11, 45), Pair(-27, 48), Pair(20, 39),
        Pair(2, 33), Pair(-1, 35), Pair(-2, 40), Pair(0, 36), Pair(6, 16), Pair(-1, 32), Pair(10, 23), Pair(18, 27)
      },
      { // Piece 4
        Pair(0, 54), Pair(-15, 36), Pair(45, 33), Pair(-18, 84), Pair(-30, 58), Pair(112, 13), Pair(-36, 65), Pair(103, -16),
        Pair(-12, 51), Pair(19, 47), Pair(-25, 27), Pair(22, 24), Pair(22, 18), Pair(66, 20), Pair(13, 64), Pair(-22, 124),
        Pair(-4, 61), Pair(7, 26), Pair(26, 49), Pair(-17, 54), Pair(-12, 3), Pair(79, 57), Pair(8, 118), Pair(22, 99),
        Pair(-26, 68), Pair(24, -7), Pair(6, 24), Pair(0, 44), Pair(0, 0), Pair(35, 36), Pair(-5, 95), Pair(24, 13),
        Pair(7, 64), Pair(33, 25), Pair(8, 51), Pair(-1, 66), Pair(26, 53), Pair(16, 38), Pair(26, 44), Pair(4, 81),
        Pair(9, 36), Pair(0, 66), Pair(9, 39), Pair(20, 44), Pair(8, 49), Pair(10, 56), Pair(17, 23), Pair(-1, 78),
        Pair(16, 23), Pair(16, 21), Pair(13, 39), Pair(18, 46), Pair(15, 23), Pair(18, 40), Pair(30, -5), Pair(1, -10),
        Pair(17, 63), Pair(-1, 51), Pair(26, 15), Pair(10, 43), Pair(23, 8), Pair(31, -14), Pair(32, 12), Pair(65, -63)
      },
      { // Piece 5
        Pair(-13, 37), Pair(-79, 26), Pair(22, 87), Pair(-14, 52), Pair(-107, 66), Pair(38, 102), Pair(13, 24), Pair(-52, -8),
        Pair(-39, 9), Pair(96, -20), Pair(56, -1), Pair(131, 62), Pair(83, 36), Pair(12, 92), Pair(89, 14), Pair(-16, -2),
        Pair(156, -6), Pair(12, 35), Pair(-29, 47), Pair(-27, 36), Pair(-13, 26), Pair(33, 6), Pair(41, 12), Pair(71, 16),
        Pair(-15, 13), Pair(25, 1), Pair(-8, 27), Pair(-47, 42), Pair(0, 0), Pair(29, 10), Pair(46, -2), Pair(18, 7),
        Pair(-91, 30), Pair(-15, 17), Pair(-51, 22), Pair(-52, 32), Pair(-32, 44), Pair(-36, 15), Pair(-18, 9), Pair(23, -10),
        Pair(-79, 19), Pair(-38, 19), Pair(1, 9), Pair(-47, 20), Pair(-25, 15), Pair(-34, 5), Pair(35, -24), Pair(38, -23),
        Pair(15, -18), Pair(-3, -6), Pair(10, -26), Pair(-12, -7), Pair(-4, -15), Pair(-1, -16), Pair(6, -22), Pair(14, -21),
        Pair(-8, -8), Pair(-19, -17), Pair(-9, -32), Pair(-16, -48), Pair(-18, -42), Pair(3, -41), Pair(8, -32), Pair(13, -37)
      }
    }},
    {{ // Bucket 29
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-44, 19), Pair(-22, 14), Pair(19, 5), Pair(-10, 18), Pair(5, 33), Pair(27, 9), Pair(-2, 47), Pair(1, 7),
        Pair(-5, 14), Pair(1, 22), Pair(7, 19), Pair(-12, 6), Pair(18, 15), Pair(26, -31), Pair(4, -3), Pair(-14, 8),
        Pair(0, 9), Pair(10, 10), Pair(4, 13), Pair(2, -3), Pair(15, 8), Pair(5, -4), Pair(-11, 2), Pair(-20, -1),
        Pair(-1, 5), Pair(5, 10), Pair(8, 9), Pair(4, 9), Pair(12, 5), Pair(-1, -6), Pair(3, 1), Pair(-4, 2),
        Pair(1, 6), Pair(5, 12), Pair(6, 7), Pair(7, 5), Pair(2, 14), Pair(7, 3), Pair(-8, 9), Pair(-10, 10),
        Pair(0, 11), Pair(2, 9), Pair(3, 12), Pair(-2, 18), Pair(4, 14), Pair(3, 13), Pair(-6, 13), Pair(-16, 12),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(9, -102), Pair(119, -52), Pair(-113, 39), Pair(-2, -4), Pair(101, -37), Pair(42, 31), Pair(-95, 44), Pair(40, 2),
        Pair(-16, -3), Pair(36, 24), Pair(44, 35), Pair(20, 28), Pair(101, -27), Pair(2, 34), Pair(14, 28), Pair(10, 31),
        Pair(18, 21), Pair(39, 17), Pair(45, 18), Pair(42, 28), Pair(66, 45), Pair(37, 15), Pair(22, 13), Pair(-1, 39),
        Pair(4, 23), Pair(16, 24), Pair(35, 24), Pair(24, 39), Pair(29, 37), Pair(0, 0), Pair(18, 19), Pair(-2, 43),
        Pair(-16, 44), Pair(62, -6), Pair(18, 34), Pair(1, 33), Pair(39, 45), Pair(19, 64), Pair(17, 57), Pair(-18, 23),
        Pair(-26, 25), Pair(1, 28), Pair(3, 27), Pair(27, 2), Pair(15, 41), Pair(4, 44), Pair(13, 13), Pair(2, -5),
        Pair(-10, 13), Pair(17, -15), Pair(-7, 34), Pair(-4, 19), Pair(-2, 14), Pair(7, 52), Pair(-3, 2), Pair(-2, 13),
        Pair(-129, -30), Pair(-15, 10), Pair(3, 50), Pair(14, 13), Pair(7, -2), Pair(-20, 20), Pair(11, 60), Pair(-40, -44)
      },
      { // Piece 2
        Pair(-10, -33), Pair(-14, -31), Pair(-19, -44), Pair(45, 24), Pair(54, -49), Pair(-54, 26), Pair(117, -58), Pair(48, 29),
        Pair(27, 13), Pair(56, -68), Pair(22, 30), Pair(54, -34), Pair(69, -2), Pair(18, -27), Pair(100, 14), Pair(-34, 24),
        Pair(-4, -32), Pair(19, 3), Pair(32, -24), Pair(-4, 25), Pair(78, 5), Pair(78, -16), Pair(-46, -16), Pair(-15, 24),
        Pair(19, 30), Pair(31, -18), Pair(54, 15), Pair(40, -24), Pair(3, 20), Pair(0, 0), Pair(21, 10), Pair(-5, -1),
        Pair(-5, -24), Pair(18, 30), Pair(18, -15), Pair(31, 21), Pair(15, 0), Pair(23, 45), Pair(5, -30), Pair(50, -10),
        Pair(16, -7), Pair(16, -24), Pair(22, 26), Pair(1, -3), Pair(17, 18), Pair(10, -12), Pair(9, 35), Pair(-23, -34),
        Pair(12, -41), Pair(13, 21), Pair(10, -21), Pair(11, 24), Pair(0, -18), Pair(25, -1), Pair(-1, 0), Pair(-10, 49),
        Pair(-1, 8), Pair(-6, 0), Pair(12, 23), Pair(16, -12), Pair(21, 22), Pair(-4, -15), Pair(3, 42), Pair(-28, -23)
      },
      { // Piece 3
        Pair(61, 49), Pair(65, 27), Pair(39, 39), Pair(49, 31), Pair(35, 46), Pair(15, 15), Pair(115, 23), Pair(48, 51),
        Pair(37, 44), Pair(65, 23), Pair(66, 30), Pair(60, 29), Pair(25, 40), Pair(-80, 38), Pair(13, 45), Pair(-9, 45),
        Pair(16, 50), Pair(67, 13), Pair(49, 32), Pair(37, 28), Pair(82, 13), Pair(95, -36), Pair(74, 15), Pair(37, 40),
        Pair(-1, 35), Pair(11, 43), Pair(21, 41), Pair(13, 35), Pair(16, 49), Pair(0, 0), Pair(-16, 34), Pair(-1, 25),
        Pair(23, 33), Pair(-26, 50), Pair(27, 21), Pair(-1, 52), Pair(13, 44), Pair(31, 18), Pair(17, 38), Pair(-13, 44),
        Pair(20, 10), Pair(21, 24), Pair(19, 46), Pair(27, 19), Pair(19, 24), Pair(26, -4), Pair(29, 23), Pair(34, 27),
        Pair(-24, 55), Pair(16, 25), Pair(13, 19), Pair(15, 24), Pair(-17, 49), Pair(23, -9), Pair(38, 15), Pair(26, 13),
        Pair(14, 16), Pair(9, 30), Pair(14, 27), Pair(8, 30), Pair(13, 30), Pair(24, -8), Pair(16, 28), Pair(13, 30)
      },
      { // Piece 4
        Pair(67, -72), Pair(13, 24), Pair(17, -35), Pair(75, 17), Pair(64, 73), Pair(66, -54), Pair(104, 26), Pair(45, -45),
        Pair(-1, 33), Pair(1, 48), Pair(29, -12), Pair(98, -44), Pair(13, 6), Pair(15, -47), Pair(-31, 48), Pair(9, -12),
        Pair(9, -8), Pair(-12, 53), Pair(16, 62), Pair(82, -4), Pair(4, 73), Pair(85, -96), Pair(15, 54), Pair(20, 7),
        Pair(22, 21), Pair(13, 19), Pair(16, 0), Pair(-18, 60), Pair(33, 43), Pair(0, 0), Pair(29, 74), Pair(15, 58),
        Pair(-2, 28), Pair(39, -35), Pair(10, 45), Pair(-1, 32), Pair(4, 28), Pair(4, 19), Pair(22, 13), Pair(47, -7),
        Pair(16, -2), Pair(28, 33), Pair(23, -3), Pair(17, 38), Pair(16, 40), Pair(14, 28), Pair(11, 62), Pair(23, -32),
        Pair(23, 6), Pair(22, 12), Pair(25, -11), Pair(10, 54), Pair(15, 35), Pair(22, -7), Pair(13, 16), Pair(16, 24),
        Pair(18, 20), Pair(18, 6), Pair(14, 49), Pair(15, 25), Pair(29, -5), Pair(16, -20), Pair(35, -9), Pair(76, -37)
      },
      { // Piece 5
        Pair(-28, -3), Pair(-120, 98), Pair(-76, 13), Pair(-26, 16), Pair(-69, 33), Pair(23, 24), Pair(-23, 41), Pair(49, 84),
        Pair(11, 54), Pair(-120, 57), Pair(101, -10), Pair(30, 18), Pair(-57, 85), Pair(87, 75), Pair(-124, 62), Pair(137, 70),
        Pair(145, -39), Pair(48, -10), Pair(5, -1), Pair(-101, 62), Pair(23, 33), Pair(-20, 22), Pair(99, -27), Pair(57, 46),
        Pair(-145, 44), Pair(4, 6), Pair(-33, 41), Pair(82, 8), Pair(70, 12), Pair(0, 0), Pair(7, 22), Pair(63, 30),
        Pair(15, -41), Pair(-38, -12), Pair(-4, 10), Pair(-10, 23), Pair(-11, 20), Pair(-47, 40), Pair(0, 7), Pair(46, -5),
        Pair(-92, 25), Pair(-26, 3), Pair(19, -20), Pair(-14, 3), Pair(-31, 16), Pair(-39, 22), Pair(-32, 7), Pair(16, -11),
        Pair(-40, 5), Pair(-36, 4), Pair(-40, -1), Pair(-52, 3), Pair(14, -26), Pair(-21, -6), Pair(19, -34), Pair(12, -20),
        Pair(-1, -28), Pair(-26, -16), Pair(-21, -24), Pair(-50, -22), Pair(0, -50), Pair(-16, -30), Pair(12, -44), Pair(11, -27)
      }
    }},
    {{ // Bucket 30
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-17, 22), Pair(-36, 21), Pair(7, 1), Pair(-20, 23), Pair(41, -12), Pair(29, 0), Pair(2, -26), Pair(23, 32),
        Pair(-2, 17), Pair(22, 13), Pair(-20, 17), Pair(6, 12), Pair(-9, 10), Pair(5, 5), Pair(-5, -46), Pair(-10, -11),
        Pair(-4, 11), Pair(0, 14), Pair(3, 11), Pair(7, 9), Pair(-14, 1), Pair(-12, 2), Pair(10, -2), Pair(-9, -9),
        Pair(0, 14), Pair(2, 12), Pair(2, 9), Pair(1, 10), Pair(2, 7), Pair(6, 1), Pair(9, -16), Pair(3, 1),
        Pair(1, 9), Pair(3, 10), Pair(7, 10), Pair(5, 14), Pair(4, 12), Pair(8, 8), Pair(9, -2), Pair(0, 11),
        Pair(0, 12), Pair(-1, 13), Pair(2, 10), Pair(3, 9), Pair(-8, 19), Pair(1, 13), Pair(7, -2), Pair(-6, 17),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(101, -86), Pair(94, -44), Pair(-45, 54), Pair(71, -17), Pair(79, 26), Pair(-180, 53), Pair(9, 3), Pair(-57, -46),
        Pair(7, 6), Pair(-60, 8), Pair(37, 26), Pair(63, 28), Pair(44, 25), Pair(34, -25), Pair(56, -19), Pair(49, -22),
        Pair(-10, 17), Pair(-5, 56), Pair(31, 4), Pair(14, 27), Pair(38, 14), Pair(15, 38), Pair(104, -2), Pair(-13, -14),
        Pair(-16, 24), Pair(1, 19), Pair(28, 26), Pair(40, 35), Pair(51, 25), Pair(56, 30), Pair(0, 0), Pair(73, -8),
        Pair(-2, 11), Pair(-10, 31), Pair(10, 17), Pair(6, 26), Pair(52, 25), Pair(16, 39), Pair(46, 48), Pair(24, 40),
        Pair(-13, -20), Pair(-5, 42), Pair(10, 17), Pair(-6, 30), Pair(21, 11), Pair(-1, 17), Pair(35, 12), Pair(-38, -2),
        Pair(-33, 33), Pair(11, 15), Pair(21, -5), Pair(-1, 22), Pair(-2, 14), Pair(-5, 15), Pair(27, 12), Pair(9, -22),
        Pair(126, -42), Pair(-13, -10), Pair(-11, 0), Pair(-23, 48), Pair(-1, 9), Pair(12, -3), Pair(-7, 12), Pair(-46, -17)
      },
      { // Piece 2
        Pair(-33, -18), Pair(-17, -50), Pair(105, -40), Pair(56, -9), Pair(170, -50), Pair(74, -24), Pair(-1, -14), Pair(-41, 63),
        Pair(58, -40), Pair(33, -15), Pair(14, -21), Pair(74, -20), Pair(41, -11), Pair(84, -16), Pair(54, -37), Pair(43, 24),
        Pair(12, -13), Pair(9, -12), Pair(37, -12), Pair(39, -13), Pair(29, 16), Pair(71, 11), Pair(100, 2), Pair(-11, -8),
        Pair(24, -37), Pair(23, 19), Pair(40, -9), Pair(51, -2), Pair(55, -12), Pair(27, 24), Pair(0, 0), Pair(-7, 11),
        Pair(14, 8), Pair(19, 2), Pair(19, 9), Pair(18, -4), Pair(29, 25), Pair(22, -2), Pair(9, 36), Pair(-52, -23),
        Pair(32, -7), Pair(17, 0), Pair(14, 8), Pair(21, 24), Pair(10, 0), Pair(2, 14), Pair(16, -19), Pair(0, 11),
        Pair(23, 25), Pair(12, 13), Pair(21, 15), Pair(-1, -4), Pair(1, 23), Pair(1, -23), Pair(12, 18), Pair(5, -20),
        Pair(64, -35), Pair(27, 16), Pair(-8, 0), Pair(-4, 18), Pair(8, -14), Pair(3, 1), Pair(41, -51), Pair(-3, -33)
      },
      { // Piece 3
        Pair(7, 45), Pair(-27, 58), Pair(57, 28), Pair(44, 33), Pair(70, 30), Pair(21, 43), Pair(63, 19), Pair(-35, 57),
        Pair(42, 24), Pair(-16, 49), Pair(85, 11), Pair(64, 23), Pair(70, 22), Pair(22, 33), Pair(2, 31), Pair(-25, 31),
        Pair(29, 38), Pair(26, 24), Pair(5, 31), Pair(78, 0), Pair(34, 27), Pair(21, 28), Pair(26, -20), Pair(10, 35),
        Pair(-11, 42), Pair(13, 30), Pair(-31, 48), Pair(25, 15), Pair(23, 31), Pair(2, 37), Pair(0, 0), Pair(-25, 28),
        Pair(3, 39), Pair(-9, 32), Pair(25, 13), Pair(11, 27), Pair(5, 34), Pair(35, 33), Pair(-13, 21), Pair(2, 41),
        Pair(-12, 25), Pair(7, 23), Pair(20, 12), Pair(2, 30), Pair(6, 25), Pair(6, 42), Pair(15, -18), Pair(-20, 35),
        Pair(-50, 49), Pair(10, 19), Pair(5, 24), Pair(-1, 26), Pair(-6, 32), Pair(-4, 29), Pair(27, -21), Pair(-26, 39),
        Pair(5, 21), Pair(12, 16), Pair(9, 23), Pair(13, 5), Pair(5, 21), Pair(6, 13), Pair(17, -26), Pair(-5, 8)
      },
      { // Piece 4
        Pair(7, 25), Pair(-105, 55), Pair(-57, 81), Pair(37, 45), Pair(68, -12), Pair(-42, 66), Pair(65, -135), Pair(27, -68),
        Pair(5, 13), Pair(-27, 46), Pair(-24, 68), Pair(23, 54), Pair(4, -3), Pair(79, 6), Pair(27, -97), Pair(17, 5),
        Pair(-13, 27), Pair(26, -6), Pair(7, 27), Pair(1, 32), Pair(35, 27), Pair(97, -27), Pair(67, -32), Pair(78, 5),
        Pair(-8, -24), Pair(-18, 31), Pair(-15, 29), Pair(25, -8), Pair(43, -17), Pair(45, -6), Pair(0, 0), Pair(36, -75),
        Pair(21, -48), Pair(-10, 12), Pair(-8, 42), Pair(-12, 35), Pair(7, 11), Pair(2, 50), Pair(10, -43), Pair(3, 3),
        Pair(23, -56), Pair(3, -8), Pair(-6, 21), Pair(2, 3), Pair(-13, 10), Pair(4, -14), Pair(-27, 44), Pair(42, -8),
        Pair(-15, 18), Pair(1, 24), Pair(-6, 5), Pair(-6, 8), Pair(-9, 1), Pair(-3, -29), Pair(-7, -18), Pair(25, 9),
        Pair(-5, 12), Pair(-24, 29), Pair(-33, 30), Pair(0, -7), Pair(8, -42), Pair(-15, -4), Pair(14, -33), Pair(-20, 40)
      },
      { // Piece 5
        Pair(61, -55), Pair(-90, 32), Pair(-2, 38), Pair(43, 32), Pair(22, 12), Pair(-69, 22), Pair(-28, 13), Pair(51, -6),
        Pair(-40, 5), Pair(-18, 4), Pair(-149, 11), Pair(-2, 5), Pair(72, 33), Pair(47, 45), Pair(67, 77), Pair(49, 93),
        Pair(-44, -1), Pair(-78, 27), Pair(-28, 20), Pair(176, 14), Pair(73, 7), Pair(95, 4), Pair(89, 35), Pair(59, 12),
        Pair(-151, 32), Pair(-37, 14), Pair(-14, 5), Pair(-98, 49), Pair(58, 16), Pair(42, 14), Pair(0, 0), Pair(-70, 36),
        Pair(-112, 17), Pair(-83, 12), Pair(-49, 15), Pair(-92, 27), Pair(4, 16), Pair(20, 1), Pair(50, 6), Pair(-27, 25),
        Pair(-47, -7), Pair(-46, 2), Pair(-40, 7), Pair(14, -2), Pair(9, -1), Pair(-5, 8), Pair(10, 3), Pair(0, 7),
        Pair(-47, 7), Pair(-20, 9), Pair(-58, 14), Pair(-27, -1), Pair(-18, -2), Pair(0, -16), Pair(18, -14), Pair(3, -5),
        Pair(-25, -16), Pair(-17, -26), Pair(-8, -33), Pair(-55, -19), Pair(-9, -19), Pair(-14, -29), Pair(12, -21), Pair(-10, -20)
      }
    }},
    {{ // Bucket 31
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(41, -3), Pair(4, -3), Pair(11, 14), Pair(11, -1), Pair(-6, 9), Pair(-34, 2), Pair(-46, 12), Pair(50, 6),
        Pair(3, 9), Pair(-16, 13), Pair(-12, 21), Pair(14, 11), Pair(1, 9), Pair(-22, 3), Pair(-9, -5), Pair(45, -43),
        Pair(1, 11), Pair(-7, 14), Pair(9, 2), Pair(5, 4), Pair(-1, 8), Pair(-20, -1), Pair(-9, -9), Pair(4, 0),
        Pair(-6, 13), Pair(-2, 15), Pair(1, 11), Pair(-2, 9), Pair(4, 6), Pair(0, 6), Pair(0, -4), Pair(9, -5),
        Pair(-5, 14), Pair(-2, 15), Pair(2, 9), Pair(0, 8), Pair(2, 4), Pair(3, 4), Pair(6, 7), Pair(21, 3),
        Pair(-4, 12), Pair(-5, 13), Pair(-1, 7), Pair(-5, 19), Pair(-1, 3), Pair(1, 8), Pair(-5, 13), Pair(10, 11),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-40, 67), Pair(119, -47), Pair(116, -15), Pair(78, -2), Pair(144, -33), Pair(-2, 13), Pair(77, -9), Pair(-150, 46),
        Pair(42, 20), Pair(-36, 40), Pair(47, -17), Pair(66, -2), Pair(32, 25), Pair(53, 0), Pair(-17, 38), Pair(-17, 33),
        Pair(15, 37), Pair(-54, 40), Pair(24, 4), Pair(25, 25), Pair(35, 19), Pair(28, 19), Pair(8, -6), Pair(-13, -21),
        Pair(-16, 23), Pair(0, 29), Pair(34, 2), Pair(42, 6), Pair(29, 9), Pair(16, 25), Pair(53, -5), Pair(0, 0),
        Pair(-28, 8), Pair(-17, 34), Pair(13, 15), Pair(-2, 26), Pair(35, 10), Pair(23, 20), Pair(15, 36), Pair(23, 35),
        Pair(-2, -6), Pair(10, 5), Pair(6, 7), Pair(19, 15), Pair(11, 4), Pair(13, 12), Pair(20, 12), Pair(-8, 12),
        Pair(-16, -10), Pair(-7, -21), Pair(1, -6), Pair(-4, 14), Pair(1, 15), Pair(16, 13), Pair(34, -1), Pair(-13, 29),
        Pair(-84, -7), Pair(-3, -5), Pair(-5, -23), Pair(8, -4), Pair(17, 25), Pair(6, -24), Pair(-6, -37), Pair(-6, -26)
      },
      { // Piece 2
        Pair(57, -44), Pair(27, -14), Pair(130, -65), Pair(9, -19), Pair(59, -66), Pair(-34, -22), Pair(108, -44), Pair(-18, -8),
        Pair(44, -6), Pair(21, -33), Pair(-36, -20), Pair(3, -45), Pair(24, -3), Pair(83, -43), Pair(43, -14), Pair(24, -10),
        Pair(7, -13), Pair(29, 9), Pair(93, -39), Pair(48, 1), Pair(92, -35), Pair(103, 1), Pair(0, -19), Pair(22, -6),
        Pair(34, 9), Pair(3, -28), Pair(0, 5), Pair(49, -29), Pair(59, 0), Pair(33, -17), Pair(24, 5), Pair(0, 0),
        Pair(24, -15), Pair(-2, 15), Pair(38, -24), Pair(28, 20), Pair(52, -34), Pair(24, 24), Pair(15, -23), Pair(63, 3),
        Pair(9, -3), Pair(22, -22), Pair(4, 14), Pair(27, -17), Pair(26, 13), Pair(18, -18), Pair(10, 19), Pair(23, -15),
        Pair(-25, -17), Pair(7, 8), Pair(47, -29), Pair(6, 12), Pair(8, -6), Pair(-4, 12), Pair(10, -20), Pair(0, -9),
        Pair(41, -8), Pair(47, -20), Pair(2, 9), Pair(32, -29), Pair(6, 9), Pair(2, -34), Pair(17, -55), Pair(82, -55)
      },
      { // Piece 3
        Pair(64, 8), Pair(-6, 25), Pair(85, -6), Pair(-5, 18), Pair(50, -3), Pair(98, -13), Pair(5, 38), Pair(60, -22),
        Pair(2, 31), Pair(26, 21), Pair(82, 3), Pair(59, 2), Pair(70, -4), Pair(51, 6), Pair(-9, 14), Pair(-33, 4),
        Pair(27, 15), Pair(-17, 27), Pair(23, 14), Pair(47, -12), Pair(72, -5), Pair(62, 10), Pair(26, 6), Pair(11, -33),
        Pair(2, 11), Pair(4, 17), Pair(24, 9), Pair(39, 5), Pair(15, 12), Pair(46, 7), Pair(17, 20), Pair(0, 0),
        Pair(-18, 14), Pair(19, 23), Pair(-6, 30), Pair(8, -1), Pair(14, 22), Pair(12, 24), Pair(-13, 15), Pair(-70, 30),
        Pair(0, 13), Pair(1, 6), Pair(-2, 12), Pair(-1, 22), Pair(5, 9), Pair(3, -4), Pair(-28, 33), Pair(-47, -19),
        Pair(-1, -9), Pair(-8, 9), Pair(9, -4), Pair(-17, 16), Pair(-8, 28), Pair(-12, 21), Pair(5, 15), Pair(-50, 9),
        Pair(10, -5), Pair(7, -7), Pair(9, 14), Pair(13, 9), Pair(6, -4), Pair(8, 1), Pair(-15, 20), Pair(-20, -26)
      },
      { // Piece 4
        Pair(76, 12), Pair(-18, 8), Pair(56, -28), Pair(6, -41), Pair(97, -11), Pair(-22, 6), Pair(-83, 52), Pair(82, -94),
        Pair(-14, -12), Pair(-24, 38), Pair(17, -11), Pair(-11, -3), Pair(24, -22), Pair(33, -6), Pair(91, -149), Pair(-38, -41),
        Pair(-13, -3), Pair(-34, 35), Pair(-3, 29), Pair(60, -50), Pair(90, -21), Pair(52, -21), Pair(11, 41), Pair(23, -93),
        Pair(-5, 2), Pair(-7, -26), Pair(-11, 7), Pair(-8, 8), Pair(-12, 7), Pair(50, -17), Pair(29, -47), Pair(0, 0),
        Pair(-15, -12), Pair(-8, 4), Pair(-5, 15), Pair(22, -49), Pair(15, 7), Pair(21, -9), Pair(3, -21), Pair(0, -64),
        Pair(9, -71), Pair(-16, 1), Pair(16, 2), Pair(7, 16), Pair(-7, 11), Pair(10, -5), Pair(9, -22), Pair(-24, -2),
        Pair(8, -31), Pair(10, -5), Pair(12, -1), Pair(9, -7), Pair(4, -22), Pair(-18, -6), Pair(28, -62), Pair(7, -31),
        Pair(22, -20), Pair(9, 25), Pair(7, -2), Pair(-3, 13), Pair(-1, 16), Pair(0, -30), Pair(12, -67), Pair(-19, 18)
      },
      { // Piece 5
        Pair(19, -4), Pair(62, 2), Pair(-65, -19), Pair(27, -3), Pair(101, -13), Pair(-78, 49), Pair(-27, 80), Pair(34, 27),
        Pair(67, -84), Pair(-24, -33), Pair(-20, 25), Pair(-20, 2), Pair(-44, -27), Pair(-14, 18), Pair(-97, 47), Pair(-113, 51),
        Pair(17, 52), Pair(29, 2), Pair(22, -9), Pair(0, 19), Pair(119, -8), Pair(89, 54), Pair(49, 17), Pair(-62, -10),
        Pair(-30, 10), Pair(-80, 10), Pair(-108, 50), Pair(-76, 22), Pair(12, 21), Pair(96, 2), Pair(9, 5), Pair(0, 0),
        Pair(-91, 20), Pair(-101, 12), Pair(-58, 16), Pair(-76, 27), Pair(-36, 13), Pair(29, 7), Pair(-3, -4), Pair(23, -33),
        Pair(-121, 4), Pair(-23, 17), Pair(-15, 6), Pair(-14, 5), Pair(6, 4), Pair(30, -5), Pair(10, 0), Pair(1, -20),
        Pair(-53, -6), Pair(-36, 1), Pair(-82, 25), Pair(-61, 10), Pair(-43, 10), Pair(-32, 5), Pair(9, -2), Pair(2, -10),
        Pair(-68, 21), Pair(-30, 0), Pair(-16, -10), Pair(-16, -12), Pair(-13, -1), Pair(5, -3), Pair(16, -19), Pair(2, -23)
      }
    }},
    {{ // Bucket 32
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-31, 6), Pair(-20, 34), Pair(-10, 20), Pair(4, 20), Pair(22, 5), Pair(-21, 11), Pair(22, -4), Pair(-19, 13),
        Pair(-10, 14), Pair(5, 20), Pair(-3, 12), Pair(-3, 18), Pair(8, 8), Pair(2, 6), Pair(12, 4), Pair(-16, 13),
        Pair(6, -17), Pair(0, 5), Pair(0, 7), Pair(-1, 9), Pair(0, 9), Pair(0, 6), Pair(-1, 15), Pair(-7, 14),
        Pair(-3, 12), Pair(-9, 2), Pair(-2, 7), Pair(-1, 13), Pair(3, 14), Pair(0, 13), Pair(-2, 14), Pair(-3, 13),
        Pair(1, 9), Pair(-1, 4), Pair(0, 10), Pair(-4, 11), Pair(-3, 8), Pair(1, 11), Pair(-3, 13), Pair(-3, 17),
        Pair(8, 7), Pair(-4, 11), Pair(-3, 9), Pair(-2, 13), Pair(-6, 13), Pair(-3, 18), Pair(-5, 15), Pair(-4, 14),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-3, 25), Pair(-37, 41), Pair(-41, 44), Pair(-76, 31), Pair(-53, 43), Pair(-54, 16), Pair(0, 19), Pair(6, 65),
        Pair(3, 35), Pair(-24, 56), Pair(-29, 54), Pair(5, 55), Pair(37, 15), Pair(-15, 68), Pair(-1, 44), Pair(-8, 23),
        Pair(-5, 28), Pair(17, 41), Pair(-12, 47), Pair(-3, 41), Pair(-22, 65), Pair(4, 45), Pair(0, 46), Pair(-20, 60),
        Pair(-18, 27), Pair(6, 48), Pair(-8, 49), Pair(-1, 54), Pair(0, 54), Pair(5, 49), Pair(-8, 53), Pair(-3, 31),
        Pair(0, 0), Pair(-18, 50), Pair(2, 53), Pair(-1, 45), Pair(-3, 52), Pair(1, 47), Pair(-7, 50), Pair(0, 29),
        Pair(0, 53), Pair(-1, 43), Pair(-4, 37), Pair(1, 56), Pair(-3, 57), Pair(1, 43), Pair(-2, 42), Pair(-7, 51),
        Pair(-16, 29), Pair(5, 51), Pair(5, 42), Pair(-4, 41), Pair(-4, 48), Pair(3, 36), Pair(-2, 40), Pair(-13, 68),
        Pair(55, -19), Pair(-10, 23), Pair(-5, 60), Pair(-21, 61), Pair(2, 49), Pair(-15, 52), Pair(-14, 42), Pair(18, -8)
      },
      { // Piece 2
        Pair(8, 27), Pair(50, 18), Pair(51, -4), Pair(-20, 43), Pair(7, 5), Pair(-59, 40), Pair(-19, 10), Pair(-35, 35),
        Pair(3, 47), Pair(26, 27), Pair(7, 41), Pair(47, -3), Pair(33, 6), Pair(-13, 17), Pair(5, 24), Pair(23, 26),
        Pair(8, 37), Pair(25, 45), Pair(5, 21), Pair(8, 31), Pair(33, -2), Pair(7, 28), Pair(23, 15), Pair(-20, 46),
        Pair(2, 24), Pair(11, 37), Pair(-10, 38), Pair(13, 20), Pair(-1, 42), Pair(4, 14), Pair(-4, 34), Pair(-1, 18),
        Pair(0, 0), Pair(-14, 49), Pair(15, 26), Pair(5, 41), Pair(1, 42), Pair(2, 36), Pair(11, 27), Pair(-14, 39),
        Pair(8, 40), Pair(17, 19), Pair(-3, 42), Pair(1, 34), Pair(-1, 53), Pair(8, 33), Pair(1, 41), Pair(8, 33),
        Pair(29, -18), Pair(-4, 35), Pair(0, 32), Pair(-2, 38), Pair(4, 35), Pair(3, 39), Pair(3, 40), Pair(8, 27),
        Pair(-9, 11), Pair(8, 20), Pair(-10, 27), Pair(3, 27), Pair(-5, 36), Pair(-1, 39), Pair(-25, 69), Pair(-14, 31)
      },
      { // Piece 3
        Pair(-77, 61), Pair(-10, 73), Pair(-11, 68), Pair(-11, 69), Pair(-47, 84), Pair(-25, 76), Pair(-37, 84), Pair(-36, 64),
        Pair(-44, 48), Pair(-6, 68), Pair(-25, 76), Pair(1, 72), Pair(-18, 71), Pair(-24, 71), Pair(-24, 79), Pair(-23, 87),
        Pair(-30, 55), Pair(-6, 72), Pair(8, 65), Pair(-25, 71), Pair(-8, 64), Pair(-33, 80), Pair(-18, 83), Pair(-3, 65),
        Pair(-53, 43), Pair(-9, 85), Pair(-2, 76), Pair(-12, 70), Pair(-7, 80), Pair(-21, 75), Pair(-21, 91), Pair(9, 68),
        Pair(0, 0), Pair(1, 85), Pair(-3, 68), Pair(5, 66), Pair(-6, 80), Pair(-14, 78), Pair(-12, 73), Pair(-7, 77),
        Pair(-38, 34), Pair(-8, 72), Pair(-18, 69), Pair(-6, 69), Pair(-10, 75), Pair(-10, 68), Pair(-1, 52), Pair(-8, 61),
        Pair(-56, 48), Pair(-14, 70), Pair(-13, 65), Pair(-4, 64), Pair(-1, 69), Pair(-13, 61), Pair(-5, 66), Pair(24, 31),
        Pair(-31, 32), Pair(-14, 67), Pair(-10, 66), Pair(-7, 63), Pair(-11, 64), Pair(-10, 63), Pair(1, 48), Pair(-2, 49)
      },
      { // Piece 4
        Pair(-34, 122), Pair(-8, 119), Pair(23, 75), Pair(-15, 107), Pair(-46, 148), Pair(-31, 120), Pair(-40, 170), Pair(46, 86),
        Pair(-2, 99), Pair(-16, 107), Pair(22, 55), Pair(17, 97), Pair(7, 90), Pair(-9, 84), Pair(31, 87), Pair(-19, 97),
        Pair(-17, 110), Pair(-6, 113), Pair(0, 104), Pair(12, 96), Pair(-24, 145), Pair(13, 103), Pair(3, 122), Pair(3, 82),
        Pair(0, 67), Pair(-4, 129), Pair(5, 115), Pair(-1, 126), Pair(16, 102), Pair(5, 72), Pair(2, 111), Pair(14, 89),
        Pair(0, 0), Pair(5, 144), Pair(14, 110), Pair(4, 119), Pair(7, 115), Pair(4, 119), Pair(10, 111), Pair(15, 74),
        Pair(-14, 122), Pair(18, 108), Pair(8, 124), Pair(19, 115), Pair(10, 112), Pair(11, 111), Pair(24, 88), Pair(29, 69),
        Pair(9, 70), Pair(18, 88), Pair(14, 102), Pair(12, 120), Pair(19, 112), Pair(11, 116), Pair(31, 83), Pair(18, 17),
        Pair(3, 86), Pair(7, 111), Pair(6, 108), Pair(12, 116), Pair(10, 137), Pair(25, 92), Pair(-13, 161), Pair(12, 88)
      },
      { // Piece 5
        Pair(17, 93), Pair(-14, 158), Pair(-30, 20), Pair(-4, 20), Pair(-112, -35), Pair(23, 2), Pair(-115, -2), Pair(-31, 3),
        Pair(-18, 37), Pair(125, 77), Pair(23, 61), Pair(25, 45), Pair(-4, -17), Pair(106, 15), Pair(54, 9), Pair(11, -33),
        Pair(-53, 23), Pair(-126, 96), Pair(105, 34), Pair(-143, 75), Pair(9, 31), Pair(-97, 20), Pair(41, -9), Pair(-81, 2),
        Pair(44, -3), Pair(-2, 31), Pair(-16, 49), Pair(-11, 40), Pair(-15, 28), Pair(15, 27), Pair(-46, 18), Pair(-75, 18),
        Pair(0, 0), Pair(6, 38), Pair(15, 42), Pair(-50, 44), Pair(-61, 39), Pair(-31, 17), Pair(-7, 4), Pair(-45, -12),
        Pair(-14, -22), Pair(42, -8), Pair(-36, 24), Pair(-22, 23), Pair(-21, 12), Pair(-21, 13), Pair(-22, 1), Pair(-43, 0),
        Pair(27, -32), Pair(84, -5), Pair(32, -3), Pair(-7, -1), Pair(-17, 6), Pair(-11, 2), Pair(-17, 1), Pair(-10, -12),
        Pair(-10, -14), Pair(97, -7), Pair(21, -6), Pair(-19, 2), Pair(-8, -8), Pair(-17, 7), Pair(-8, -9), Pair(-5, -19)
      }
    }},
    {{ // Bucket 33
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(6, 26), Pair(-29, 18), Pair(-4, 11), Pair(-5, 6), Pair(25, 15), Pair(16, 15), Pair(8, 3), Pair(-6, 14),
        Pair(-2, 20), Pair(-8, 7), Pair(2, 21), Pair(-3, 13), Pair(13, 9), Pair(10, 4), Pair(7, 10), Pair(-4, 17),
        Pair(-6, 4), Pair(4, -10), Pair(7, 9), Pair(2, 11), Pair(8, 5), Pair(5, 11), Pair(2, 12), Pair(-2, 14),
        Pair(-7, 3), Pair(-3, 15), Pair(-4, 6), Pair(-3, 7), Pair(1, 12), Pair(3, 12), Pair(1, 15), Pair(1, 16),
        Pair(6, 11), Pair(-8, 3), Pair(8, 11), Pair(0, 12), Pair(-1, 12), Pair(6, 10), Pair(6, 14), Pair(1, 16),
        Pair(-2, 14), Pair(0, 10), Pair(-1, 19), Pair(6, 17), Pair(-5, 19), Pair(0, 17), Pair(5, 18), Pair(1, 16),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-75, 84), Pair(94, -6), Pair(43, 0), Pair(-40, 36), Pair(-14, 61), Pair(-97, 15), Pair(-31, 54), Pair(-59, 19),
        Pair(8, 43), Pair(13, 57), Pair(-13, 46), Pair(4, 51), Pair(2, 75), Pair(9, 29), Pair(1, 36), Pair(-49, 79),
        Pair(-21, 43), Pair(-14, 70), Pair(15, 42), Pair(4, 62), Pair(-3, 65), Pair(-27, 59), Pair(-3, 46), Pair(-13, 43),
        Pair(15, 22), Pair(-1, 48), Pair(18, 29), Pair(14, 56), Pair(21, 49), Pair(3, 55), Pair(0, 60), Pair(-3, 75),
        Pair(9, 33), Pair(0, 0), Pair(17, 50), Pair(12, 61), Pair(12, 53), Pair(17, 70), Pair(18, 50), Pair(14, 45),
        Pair(6, 59), Pair(23, 71), Pair(14, 56), Pair(25, 37), Pair(18, 50), Pair(13, 52), Pair(19, 48), Pair(21, 20),
        Pair(-21, -6), Pair(7, 59), Pair(12, 56), Pair(10, 43), Pair(10, 61), Pair(4, 55), Pair(5, 55), Pair(11, 22),
        Pair(28, 54), Pair(-3, 22), Pair(21, 44), Pair(2, 56), Pair(13, 66), Pair(3, 51), Pair(1, 49), Pair(13, -33)
      },
      { // Piece 2
        Pair(70, -19), Pair(25, 21), Pair(0, 32), Pair(7, 12), Pair(43, 16), Pair(93, -20), Pair(-12, 28), Pair(-6, 16),
        Pair(35, -1), Pair(15, 37), Pair(58, 15), Pair(7, 42), Pair(43, 5), Pair(14, 14), Pair(-40, 26), Pair(0, 27),
        Pair(-13, 48), Pair(18, 30), Pair(31, 30), Pair(10, 15), Pair(27, 33), Pair(24, -11), Pair(35, 7), Pair(6, 39),
        Pair(1, -3), Pair(8, 35), Pair(52, 5), Pair(1, 43), Pair(29, 20), Pair(20, 29), Pair(14, 22), Pair(8, 37),
        Pair(15, 24), Pair(0, 0), Pair(22, 50), Pair(18, 22), Pair(15, 51), Pair(31, 22), Pair(36, 34), Pair(4, 52),
        Pair(-5, -21), Pair(20, 49), Pair(9, 27), Pair(14, 45), Pair(18, 37), Pair(21, 40), Pair(32, 29), Pair(12, 60),
        Pair(-7, 44), Pair(9, 34), Pair(7, 37), Pair(10, 30), Pair(10, 60), Pair(20, 23), Pair(13, 59), Pair(19, 53),
        Pair(24, -25), Pair(18, 23), Pair(6, 13), Pair(23, 44), Pair(12, 21), Pair(10, 40), Pair(13, -9), Pair(-7, 14)
      },
      { // Piece 3
        Pair(-9, 86), Pair(-20, 51), Pair(1, 64), Pair(-1, 61), Pair(-15, 87), Pair(-39, 93), Pair(-39, 82), Pair(26, 67),
        Pair(-21, 84), Pair(-20, 54), Pair(-24, 86), Pair(17, 64), Pair(13, 53), Pair(-22, 89), Pair(-36, 79), Pair(14, 68),
        Pair(-19, 84), Pair(7, 50), Pair(-15, 78), Pair(-2, 88), Pair(14, 64), Pair(-22, 76), Pair(23, 72), Pair(-39, 91),
        Pair(-9, 85), Pair(-43, 40), Pair(14, 70), Pair(10, 64), Pair(0, 79), Pair(2, 82), Pair(20, 73), Pair(30, 82),
        Pair(6, 61), Pair(0, 0), Pair(5, 61), Pair(33, 60), Pair(3, 80), Pair(-3, 77), Pair(-18, 89), Pair(-13, 83),
        Pair(-3, 73), Pair(-21, 48), Pair(4, 90), Pair(-12, 83), Pair(-5, 77), Pair(0, 74), Pair(14, 54), Pair(5, 78),
        Pair(-5, 73), Pair(-15, 51), Pair(5, 59), Pair(-3, 73), Pair(13, 67), Pair(11, 54), Pair(-6, 75), Pair(-28, 81),
        Pair(0, 63), Pair(-10, 39), Pair(4, 76), Pair(11, 60), Pair(4, 71), Pair(1, 70), Pair(6, 59), Pair(9, 58)
      },
      { // Piece 4
        Pair(15, 89), Pair(-28, 120), Pair(18, 86), Pair(-53, 124), Pair(-7, 81), Pair(-40, 113), Pair(-3, 86), Pair(-31, 100),
        Pair(-19, 105), Pair(-2, 75), Pair(13, 60), Pair(42, 77), Pair(23, 66), Pair(41, 82), Pair(12, 86), Pair(1, 70),
        Pair(-23, 120), Pair(2, 73), Pair(-1, 86), Pair(8, 61), Pair(-3, 94), Pair(40, 46), Pair(43, 50), Pair(10, 64),
        Pair(-9, 86), Pair(-1, 45), Pair(-18, 114), Pair(11, 87), Pair(19, 84), Pair(-19, 111), Pair(20, 50), Pair(-27, 106),
        Pair(21, 39), Pair(0, 0), Pair(12, 76), Pair(11, 93), Pair(5, 87), Pair(12, 111), Pair(4, 109), Pair(20, 68),
        Pair(0, 66), Pair(16, 64), Pair(1, 109), Pair(2, 112), Pair(10, 99), Pair(12, 83), Pair(9, 103), Pair(-6, 91),
        Pair(26, 84), Pair(6, 83), Pair(10, 94), Pair(7, 102), Pair(10, 98), Pair(8, 124), Pair(14, 94), Pair(29, 34),
        Pair(4, 113), Pair(6, 39), Pair(9, 98), Pair(11, 88), Pair(11, 95), Pair(-4, 81), Pair(-12, 110), Pair(20, 104)
      },
      { // Piece 5
        Pair(-5, 118), Pair(-55, 29), Pair(-25, 155), Pair(116, 28), Pair(29, 22), Pair(-14, -10), Pair(-45, -43), Pair(42, -24),
        Pair(-54, 106), Pair(-62, 76), Pair(7, 105), Pair(78, 54), Pair(55, -19), Pair(112, -19), Pair(0, 11), Pair(67, -56),
        Pair(18, 93), Pair(77, 47), Pair(200, 36), Pair(32, 58), Pair(71, 39), Pair(-5, 42), Pair(-38, 24), Pair(-41, -22),
        Pair(81, 36), Pair(36, 28), Pair(29, 31), Pair(-22, 56), Pair(6, 44), Pair(-8, 17), Pair(42, 3), Pair(-55, 4),
        Pair(-77, 80), Pair(0, 0), Pair(7, 50), Pair(-15, 45), Pair(-41, 27), Pair(-35, 23), Pair(-13, 10), Pair(-93, 13),
        Pair(74, 12), Pair(21, 26), Pair(40, 24), Pair(-3, 26), Pair(10, 18), Pair(-18, 14), Pair(-20, 10), Pair(-63, 16),
        Pair(83, 22), Pair(52, 14), Pair(13, 27), Pair(-4, 11), Pair(-14, 17), Pair(-16, 10), Pair(-18, 6), Pair(-13, -7),
        Pair(54, -5), Pair(48, -29), Pair(15, -3), Pair(-5, 5), Pair(-7, 2), Pair(-18, 4), Pair(-4, -8), Pair(-8, -12)
      }
    }},
    {{ // Bucket 34
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-8, 15), Pair(-21, 23), Pair(-41, 16), Pair(22, 12), Pair(3, 17), Pair(3, 26), Pair(4, 6), Pair(4, 5),
        Pair(-4, 12), Pair(-9, 20), Pair(2, -9), Pair(-20, 25), Pair(14, 8), Pair(9, 3), Pair(2, 4), Pair(-5, 13),
        Pair(-1, 9), Pair(-1, 6), Pair(-3, -23), Pair(3, 6), Pair(3, 10), Pair(7, 8), Pair(3, 10), Pair(-1, 9),
        Pair(-3, 7), Pair(-5, 6), Pair(8, -2), Pair(-5, 17), Pair(-3, 6), Pair(5, 7), Pair(3, 8), Pair(1, 12),
        Pair(1, 7), Pair(7, 8), Pair(-10, -13), Pair(2, 15), Pair(0, 12), Pair(2, 9), Pair(0, 9), Pair(-1, 9),
        Pair(0, 9), Pair(2, 10), Pair(-2, -4), Pair(1, 24), Pair(-1, 12), Pair(1, 14), Pair(1, 11), Pair(0, 15),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-50, 104), Pair(21, 76), Pair(33, 56), Pair(69, 0), Pair(-46, 31), Pair(-93, 51), Pair(-49, 8), Pair(-43, 2),
        Pair(-7, 26), Pair(-8, 59), Pair(-24, 42), Pair(12, 51), Pair(-47, 72), Pair(-5, 34), Pair(-7, 56), Pair(-35, 84),
        Pair(-51, 48), Pair(-27, 35), Pair(-25, 59), Pair(10, 39), Pair(-7, 50), Pair(-13, 64), Pair(-4, 38), Pair(-15, 32),
        Pair(-33, 25), Pair(0, 42), Pair(-18, 44), Pair(13, 50), Pair(-10, 54), Pair(-8, 58), Pair(-10, 49), Pair(-15, 77),
        Pair(-4, 41), Pair(-12, 53), Pair(0, 0), Pair(0, 47), Pair(-8, 53), Pair(-2, 56), Pair(4, 34), Pair(-4, 52),
        Pair(-18, 18), Pair(1, 44), Pair(6, 67), Pair(11, 58), Pair(2, 40), Pair(-3, 51), Pair(-4, 49), Pair(8, 33),
        Pair(-19, 2), Pair(-6, 11), Pair(9, 46), Pair(-3, 38), Pair(0, 42), Pair(4, 54), Pair(-3, 29), Pair(-1, 48),
        Pair(25, 53), Pair(-5, 4), Pair(-7, 74), Pair(14, 31), Pair(3, 61), Pair(5, 34), Pair(-5, 49), Pair(-14, 23)
      },
      { // Piece 2
        Pair(23, 10), Pair(3, 48), Pair(63, -20), Pair(23, 29), Pair(31, -8), Pair(-19, 36), Pair(-25, 4), Pair(53, 0),
        Pair(-3, 47), Pair(23, 22), Pair(15, 32), Pair(35, -16), Pair(30, 18), Pair(64, -24), Pair(-41, 45), Pair(12, 2),
        Pair(-18, -15), Pair(27, 18), Pair(-16, 13), Pair(13, 36), Pair(42, -17), Pair(-18, 53), Pair(27, -17), Pair(-7, 22),
        Pair(-4, 40), Pair(-33, 0), Pair(-7, 13), Pair(23, -14), Pair(8, 31), Pair(26, 7), Pair(7, 29), Pair(1, 7),
        Pair(-18, 0), Pair(4, 39), Pair(0, 0), Pair(7, 33), Pair(1, 17), Pair(6, 43), Pair(0, 11), Pair(-8, 58),
        Pair(-7, 30), Pair(-26, -8), Pair(10, 53), Pair(-8, 9), Pair(3, 44), Pair(1, 16), Pair(7, 42), Pair(-7, 27),
        Pair(-23, 5), Pair(1, 39), Pair(-3, 13), Pair(7, 38), Pair(-6, 10), Pair(1, 50), Pair(-8, 39), Pair(8, 29),
        Pair(3, 48), Pair(-7, 2), Pair(2, 44), Pair(7, 12), Pair(0, 27), Pair(-15, 14), Pair(11, 34), Pair(-6, 1)
      },
      { // Piece 3
        Pair(-24, 65), Pair(-32, 78), Pair(6, 37), Pair(-45, 65), Pair(11, 46), Pair(-3, 57), Pair(-38, 58), Pair(-64, 82),
        Pair(-11, 63), Pair(-1, 62), Pair(-11, 30), Pair(14, 44), Pair(11, 51), Pair(-58, 73), Pair(4, 40), Pair(5, 52),
        Pair(-26, 71), Pair(-4, 51), Pair(-49, 62), Pair(-37, 68), Pair(18, 53), Pair(-26, 59), Pair(-24, 56), Pair(-10, 70),
        Pair(-8, 66), Pair(-2, 65), Pair(-39, 33), Pair(-2, 61), Pair(-5, 65), Pair(-2, 65), Pair(-5, 68), Pair(-5, 67),
        Pair(5, 46), Pair(-7, 39), Pair(0, 0), Pair(-16, 57), Pair(-1, 61), Pair(1, 45), Pair(-2, 49), Pair(-15, 55),
        Pair(-6, 54), Pair(3, 58), Pair(-11, 26), Pair(-3, 66), Pair(-4, 52), Pair(-15, 59), Pair(-4, 64), Pair(-3, 46),
        Pair(-10, 50), Pair(-5, 63), Pair(-19, 19), Pair(-11, 66), Pair(-4, 59), Pair(-1, 45), Pair(-17, 47), Pair(-5, 57),
        Pair(-9, 57), Pair(-7, 56), Pair(-9, 25), Pair(-4, 57), Pair(-5, 56), Pair(-3, 49), Pair(-2, 51), Pair(3, 42)
      },
      { // Piece 4
        Pair(29, 59), Pair(-16, 117), Pair(2, 60), Pair(34, 35), Pair(-23, 92), Pair(23, 77), Pair(48, 66), Pair(-20, 103),
        Pair(-18, 77), Pair(17, 74), Pair(-13, 57), Pair(12, 94), Pair(3, 75), Pair(45, 16), Pair(-8, 53), Pair(22, 53),
        Pair(-13, 27), Pair(1, 90), Pair(3, 55), Pair(-28, 96), Pair(-26, 90), Pair(0, 71), Pair(15, 67), Pair(8, 79),
        Pair(-7, 78), Pair(9, 41), Pair(-15, 61), Pair(-2, 76), Pair(-29, 119), Pair(-18, 83), Pair(-5, 82), Pair(-6, 85),
        Pair(14, 46), Pair(-2, 80), Pair(0, 0), Pair(-7, 84), Pair(-7, 77), Pair(-12, 105), Pair(4, 59), Pair(-2, 75),
        Pair(-3, 62), Pair(12, 55), Pair(10, 63), Pair(5, 67), Pair(7, 81), Pair(8, 82), Pair(6, 58), Pair(-10, 77),
        Pair(-4, 45), Pair(10, 71), Pair(6, 58), Pair(9, 79), Pair(3, 76), Pair(22, 51), Pair(16, 54), Pair(-14, 97),
        Pair(-3, 66), Pair(11, 30), Pair(13, 48), Pair(6, 76), Pair(1, 78), Pair(0, 72), Pair(12, 52), Pair(4, 71)
      },
      { // Piece 5
        Pair(2, 43), Pair(-34, 105), Pair(30, 21), Pair(103, 138), Pair(99, -15), Pair(-73, -18), Pair(-22, -13), Pair(-10, 24),
        Pair(37, 63), Pair(106, 53), Pair(49, 110), Pair(71, 84), Pair(163, 16), Pair(-40, 52), Pair(2, 12), Pair(-123, 48),
        Pair(3, 61), Pair(42, 76), Pair(152, 23), Pair(30, 43), Pair(81, 21), Pair(92, 10), Pair(10, 12), Pair(-73, 26),
        Pair(140, 17), Pair(44, 18), Pair(79, 13), Pair(28, 27), Pair(-1, 38), Pair(-37, 20), Pair(-20, 0), Pair(-36, 17),
        Pair(-79, 57), Pair(56, 27), Pair(0, 0), Pair(-5, 46), Pair(-46, 31), Pair(13, 9), Pair(0, 13), Pair(1, -3),
        Pair(70, 16), Pair(-37, 34), Pair(4, 27), Pair(-23, 22), Pair(-9, 19), Pair(-8, 7), Pair(-15, 0), Pair(-21, 1),
        Pair(18, 16), Pair(-2, 33), Pair(-4, 1), Pair(-8, 17), Pair(10, -7), Pair(-9, 1), Pair(-9, -2), Pair(-7, -7),
        Pair(35, -26), Pair(13, -15), Pair(18, -37), Pair(3, -27), Pair(3, -17), Pair(-5, -10), Pair(-4, -16), Pair(-2, -18)
      }
    }},
    {{ // Bucket 35
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-32, 20), Pair(-17, 10), Pair(-14, 19), Pair(11, -17), Pair(17, 3), Pair(-17, 18), Pair(2, 10), Pair(21, -19),
        Pair(2, 8), Pair(-1, 12), Pair(-1, 10), Pair(1, 3), Pair(-5, 22), Pair(5, 18), Pair(6, 10), Pair(-3, 17),
        Pair(2, 9), Pair(4, 6), Pair(12, 8), Pair(-5, 0), Pair(9, 6), Pair(3, 9), Pair(3, 10), Pair(-4, 8),
        Pair(0, 13), Pair(-1, 11), Pair(-5, 16), Pair(6, -13), Pair(-1, 19), Pair(-1, 3), Pair(3, 9), Pair(0, 8),
        Pair(0, 12), Pair(2, 8), Pair(10, 14), Pair(3, -6), Pair(5, 15), Pair(0, 9), Pair(3, 10), Pair(2, 10),
        Pair(2, 11), Pair(3, 12), Pair(1, 17), Pair(15, -4), Pair(5, 14), Pair(-1, 13), Pair(0, 13), Pair(2, 11),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-53, 0), Pair(-82, 56), Pair(28, 44), Pair(-25, 42), Pair(-56, 16), Pair(-49, 95), Pair(-8, 72), Pair(-56, 107),
        Pair(-14, 22), Pair(1, 34), Pair(1, 40), Pair(-27, 69), Pair(9, 35), Pair(-1, 62), Pair(27, 40), Pair(23, 1),
        Pair(7, 45), Pair(-12, 68), Pair(12, 34), Pair(-21, 66), Pair(-5, 44), Pair(-17, 61), Pair(-4, 52), Pair(10, 57),
        Pair(6, 29), Pair(-6, 48), Pair(1, 34), Pair(-15, 35), Pair(-1, 51), Pair(-8, 54), Pair(-13, 56), Pair(-12, 51),
        Pair(5, 54), Pair(1, 43), Pair(2, 49), Pair(0, 0), Pair(-12, 55), Pair(1, 65), Pair(2, 43), Pair(-1, 46),
        Pair(-8, 40), Pair(-5, 31), Pair(5, 57), Pair(22, 68), Pair(7, 53), Pair(-1, 36), Pair(0, 49), Pair(-2, 42),
        Pair(-9, 30), Pair(22, 4), Pair(-7, 35), Pair(4, 41), Pair(6, 37), Pair(10, 40), Pair(-10, 40), Pair(11, 38),
        Pair(-31, 42), Pair(2, 28), Pair(-26, 74), Pair(22, 11), Pair(2, 55), Pair(2, 43), Pair(6, 37), Pair(14, 65)
      },
      { // Piece 2
        Pair(25, 3), Pair(36, -3), Pair(13, 6), Pair(-19, -11), Pair(13, 17), Pair(4, -6), Pair(-2, 24), Pair(-5, -53),
        Pair(-59, 4), Pair(-5, 45), Pair(-9, 14), Pair(28, 20), Pair(9, -4), Pair(22, 22), Pair(36, -57), Pair(10, 29),
        Pair(9, 35), Pair(-15, -20), Pair(26, 34), Pair(-11, -1), Pair(-5, 32), Pair(-39, 1), Pair(-1, 23), Pair(-1, 5),
        Pair(-7, 6), Pair(7, 37), Pair(8, -24), Pair(0, 26), Pair(-5, 11), Pair(12, 27), Pair(-5, 2), Pair(0, 25),
        Pair(12, 13), Pair(-7, 8), Pair(6, 33), Pair(0, 0), Pair(1, 30), Pair(-4, 15), Pair(4, 17), Pair(-6, 10),
        Pair(-11, 8), Pair(7, 26), Pair(-33, -13), Pair(15, 50), Pair(-7, -4), Pair(7, 40), Pair(-2, 21), Pair(-2, 48),
        Pair(21, 28), Pair(-31, -29), Pair(12, 40), Pair(0, 11), Pair(6, 34), Pair(-16, 0), Pair(-3, 46), Pair(-8, 28),
        Pair(-42, -32), Pair(8, 22), Pair(-12, 14), Pair(2, 41), Pair(-6, 4), Pair(6, 33), Pair(-23, -8), Pair(-4, 5)
      },
      { // Piece 3
        Pair(-19, 65), Pair(-24, 61), Pair(-20, 69), Pair(-25, 47), Pair(-18, 66), Pair(0, 51), Pair(23, 54), Pair(4, 41),
        Pair(-18, 76), Pair(-21, 74), Pair(-29, 72), Pair(10, 52), Pair(-28, 55), Pair(-24, 65), Pair(-17, 60), Pair(-1, 61),
        Pair(3, 62), Pair(2, 53), Pair(-14, 68), Pair(-25, 50), Pair(-18, 69), Pair(9, 53), Pair(-4, 33), Pair(3, 46),
        Pair(3, 66), Pair(-13, 57), Pair(-6, 59), Pair(-1, 6), Pair(1, 57), Pair(-5, 63), Pair(-7, 45), Pair(13, 51),
        Pair(5, 40), Pair(-1, 51), Pair(-9, 56), Pair(0, 0), Pair(-11, 50), Pair(-10, 48), Pair(10, 32), Pair(-1, 42),
        Pair(8, 48), Pair(-2, 59), Pair(13, 51), Pair(10, 15), Pair(0, 53), Pair(0, 51), Pair(-4, 58), Pair(11, 23),
        Pair(13, 39), Pair(-5, 57), Pair(5, 50), Pair(-15, 43), Pair(3, 53), Pair(-3, 62), Pair(-12, 43), Pair(-3, 60),
        Pair(2, 50), Pair(1, 47), Pair(-2, 53), Pair(6, 25), Pair(-3, 52), Pair(-5, 57), Pair(3, 43), Pair(6, 45)
      },
      { // Piece 4
        Pair(-8, 68), Pair(10, 96), Pair(19, 70), Pair(52, 19), Pair(40, 67), Pair(25, 52), Pair(-19, 144), Pair(56, 41),
        Pair(11, 29), Pair(6, 67), Pair(-8, 97), Pair(-5, 79), Pair(6, 55), Pair(-13, 136), Pair(30, 25), Pair(19, 84),
        Pair(-10, 100), Pair(0, 64), Pair(-3, 87), Pair(-15, 76), Pair(-12, 88), Pair(-8, 60), Pair(5, 121), Pair(-14, 108),
        Pair(16, 57), Pair(0, 75), Pair(5, 63), Pair(3, 26), Pair(-5, 107), Pair(-2, 98), Pair(-1, 79), Pair(5, 84),
        Pair(10, 56), Pair(25, 31), Pair(-2, 65), Pair(0, 0), Pair(-1, 66), Pair(7, 68), Pair(3, 104), Pair(1, 69),
        Pair(19, 38), Pair(15, 71), Pair(3, 82), Pair(19, 45), Pair(11, 77), Pair(10, 84), Pair(1, 101), Pair(16, 38),
        Pair(20, 62), Pair(11, 73), Pair(10, 77), Pair(8, 72), Pair(10, 79), Pair(17, 56), Pair(12, 61), Pair(-15, 112),
        Pair(23, 25), Pair(10, 53), Pair(13, 69), Pair(12, 54), Pair(4, 78), Pair(8, 79), Pair(9, 38), Pair(32, 63)
      },
      { // Piece 5
        Pair(-50, -45), Pair(-23, 83), Pair(-74, 69), Pair(-7, 141), Pair(-48, 25), Pair(45, 74), Pair(-13, 51), Pair(63, -8),
        Pair(-146, 48), Pair(18, 69), Pair(18, 52), Pair(57, 78), Pair(43, 29), Pair(124, 0), Pair(-40, 26), Pair(27, -8),
        Pair(-209, 79), Pair(21, 51), Pair(100, 45), Pair(28, 41), Pair(-37, 71), Pair(-97, 57), Pair(-16, 43), Pair(73, 12),
        Pair(-67, 19), Pair(-36, 23), Pair(-55, 17), Pair(-42, 26), Pair(-35, 14), Pair(88, 4), Pair(2, 21), Pair(-32, -6),
        Pair(12, 47), Pair(42, 5), Pair(-21, 40), Pair(0, 0), Pair(-35, 38), Pair(-34, 18), Pair(21, -9), Pair(-44, 14),
        Pair(-42, 16), Pair(-37, 20), Pair(-24, 20), Pair(-93, 45), Pair(-39, 12), Pair(-5, 2), Pair(7, -13), Pair(24, -22),
        Pair(27, -14), Pair(-1, 0), Pair(-27, 6), Pair(-69, 27), Pair(-19, -2), Pair(19, -21), Pair(-1, -16), Pair(6, -22),
        Pair(6, 2), Pair(-5, 0), Pair(-6, -18), Pair(-33, -8), Pair(3, -36), Pair(14, -25), Pair(2, -22), Pair(6, -33)
      }
    }},
    {{ // Bucket 36
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(10, 3), Pair(-40, 30), Pair(-56, 26), Pair(-25, 21), Pair(-33, 15), Pair(-4, 19), Pair(2, -3), Pair(16, 11),
        Pair(-2, 11), Pair(-6, 11), Pair(8, 13), Pair(-13, 22), Pair(5, 2), Pair(2, 12), Pair(-11, 16), Pair(5, 8),
        Pair(0, 5), Pair(5, 10), Pair(-1, 8), Pair(7, 12), Pair(-1, -2), Pair(12, 8), Pair(1, 6), Pair(1, 5),
        Pair(1, 12), Pair(2, 13), Pair(-4, 7), Pair(-1, 21), Pair(-4, -5), Pair(5, 6), Pair(-1, 8), Pair(3, 9),
        Pair(2, 9), Pair(4, 10), Pair(1, 9), Pair(10, 11), Pair(-1, -2), Pair(18, 12), Pair(0, 7), Pair(4, 9),
        Pair(3, 12), Pair(3, 12), Pair(1, 10), Pair(5, 17), Pair(5, 0), Pair(6, 22), Pair(3, 11), Pair(3, 12),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-17, 33), Pair(15, 14), Pair(-15, 28), Pair(74, 32), Pair(60, 63), Pair(57, 3), Pair(60, 36), Pair(-56, 9),
        Pair(6, 46), Pair(16, 35), Pair(-12, 55), Pair(-3, 59), Pair(-45, 86), Pair(57, 25), Pair(47, 54), Pair(-11, 44),
        Pair(14, 22), Pair(15, 42), Pair(10, 44), Pair(-13, 43), Pair(-10, 47), Pair(25, 38), Pair(-19, 46), Pair(8, 46),
        Pair(-7, 43), Pair(3, 49), Pair(-7, 46), Pair(6, 53), Pair(-24, 40), Pair(-8, 55), Pair(-6, 33), Pair(-16, 16),
        Pair(-4, 42), Pair(-4, 62), Pair(8, 52), Pair(6, 48), Pair(0, 0), Pair(-1, 55), Pair(-6, 41), Pair(-9, 70),
        Pair(-5, 33), Pair(2, 36), Pair(-1, 34), Pair(8, 52), Pair(11, 68), Pair(3, 57), Pair(2, 24), Pair(2, 25),
        Pair(4, 51), Pair(-2, 44), Pair(-1, 28), Pair(-1, 38), Pair(7, 46), Pair(5, 50), Pair(-15, 62), Pair(2, 24),
        Pair(103, 16), Pair(-1, 43), Pair(42, 21), Pair(10, 35), Pair(6, 36), Pair(-3, 42), Pair(-2, 39), Pair(-13, 52)
      },
      { // Piece 2
        Pair(27, -13), Pair(-13, 22), Pair(76, -46), Pair(68, 6), Pair(82, -30), Pair(26, 1), Pair(-58, 6), Pair(80, -8),
        Pair(-13, 38), Pair(-27, -13), Pair(32, 15), Pair(42, -2), Pair(23, 20), Pair(5, -21), Pair(0, 18), Pair(-117, -2),
        Pair(16, -6), Pair(30, 10), Pair(6, -9), Pair(9, 36), Pair(3, 1), Pair(32, 37), Pair(12, -17), Pair(-13, 39),
        Pair(-4, 29), Pair(10, 10), Pair(9, 30), Pair(10, -11), Pair(-4, 8), Pair(27, -15), Pair(1, 23), Pair(-7, -3),
        Pair(12, 2), Pair(11, 29), Pair(-4, 9), Pair(14, 15), Pair(0, 0), Pair(3, 34), Pair(-3, 5), Pair(-10, 40),
        Pair(-1, 46), Pair(3, 11), Pair(5, 31), Pair(-2, -4), Pair(11, 55), Pair(-25, -7), Pair(-3, 33), Pair(-11, 12),
        Pair(16, -37), Pair(-3, 46), Pair(-11, -12), Pair(6, 34), Pair(-2, 16), Pair(-3, 29), Pair(-29, -15), Pair(0, 30),
        Pair(12, 16), Pair(-39, 10), Pair(1, 39), Pair(-1, -1), Pair(-8, 41), Pair(-10, 14), Pair(2, 6), Pair(-51, -36)
      },
      { // Piece 3
        Pair(2, 52), Pair(13, 41), Pair(-7, 56), Pair(22, 42), Pair(27, 33), Pair(-6, 51), Pair(48, 43), Pair(90, 30),
        Pair(-9, 61), Pair(11, 50), Pair(-11, 69), Pair(0, 43), Pair(-3, 28), Pair(-39, 63), Pair(16, 59), Pair(6, 50),
        Pair(-5, 58), Pair(4, 54), Pair(6, 50), Pair(-1, 44), Pair(0, 42), Pair(-21, 57), Pair(-13, 66), Pair(13, 48),
        Pair(3, 55), Pair(6, 52), Pair(26, 37), Pair(0, 66), Pair(4, 11), Pair(5, 55), Pair(-14, 56), Pair(13, 47),
        Pair(1, 43), Pair(7, 36), Pair(2, 47), Pair(2, 36), Pair(0, 0), Pair(-7, 24), Pair(7, 35), Pair(11, 29),
        Pair(0, 59), Pair(9, 46), Pair(9, 47), Pair(14, 33), Pair(-7, 32), Pair(8, 39), Pair(13, 42), Pair(6, 42),
        Pair(11, 41), Pair(-2, 54), Pair(4, 43), Pair(-4, 52), Pair(-1, 22), Pair(-12, 59), Pair(9, 45), Pair(6, 55),
        Pair(6, 44), Pair(5, 49), Pair(6, 47), Pair(5, 45), Pair(5, 18), Pair(-4, 47), Pair(-1, 54), Pair(19, 32)
      },
      { // Piece 4
        Pair(21, 44), Pair(41, 65), Pair(-1, 85), Pair(-7, 119), Pair(-26, 71), Pair(-8, 100), Pair(-84, 180), Pair(-25, 122),
        Pair(-16, 92), Pair(6, 54), Pair(28, 43), Pair(-3, 71), Pair(45, 15), Pair(-15, 74), Pair(-10, 87), Pair(-41, 113),
        Pair(-7, 95), Pair(4, 81), Pair(9, 47), Pair(-9, 80), Pair(-7, 49), Pair(17, 108), Pair(-4, 79), Pair(-12, 82),
        Pair(-3, 80), Pair(10, 44), Pair(14, 54), Pair(-13, 98), Pair(-11, 41), Pair(-2, 94), Pair(1, 88), Pair(-15, 65),
        Pair(11, 59), Pair(1, 64), Pair(-10, 82), Pair(11, 54), Pair(0, 0), Pair(-23, 109), Pair(7, 64), Pair(-5, 70),
        Pair(10, 57), Pair(4, 81), Pair(6, 76), Pair(8, 67), Pair(7, 67), Pair(8, 55), Pair(10, 38), Pair(6, 68),
        Pair(11, 83), Pair(9, 90), Pair(10, 60), Pair(10, 77), Pair(15, 46), Pair(10, 72), Pair(3, 77), Pair(23, 0),
        Pair(13, 82), Pair(2, 68), Pair(12, 78), Pair(10, 73), Pair(17, 54), Pair(20, 38), Pair(-18, 111), Pair(38, 32)
      },
      { // Piece 5
        Pair(-65, -28), Pair(-81, 13), Pair(44, 32), Pair(-164, 88), Pair(140, 10), Pair(80, 43), Pair(9, 101), Pair(56, -57),
        Pair(55, 0), Pair(-59, 36), Pair(-19, 39), Pair(0, 67), Pair(73, 73), Pair(14, 88), Pair(70, 32), Pair(-76, 36),
        Pair(20, 13), Pair(-16, 11), Pair(-56, 33), Pair(36, 21), Pair(-10, 56), Pair(-10, 45), Pair(26, -1), Pair(-103, 56),
        Pair(-71, -2), Pair(-103, 25), Pair(-23, 11), Pair(-28, 6), Pair(19, 0), Pair(-22, -2), Pair(36, 1), Pair(-25, 14),
        Pair(-21, 7), Pair(-54, 9), Pair(17, 5), Pair(-26, 26), Pair(0, 0), Pair(-21, 15), Pair(-11, 7), Pair(6, 10),
        Pair(50, -32), Pair(-13, 1), Pair(27, 6), Pair(-23, 18), Pair(-39, 29), Pair(-28, 8), Pair(13, -9), Pair(4, -6),
        Pair(29, -43), Pair(-2, -6), Pair(20, -18), Pair(-43, 15), Pair(-33, 13), Pair(-31, 2), Pair(8, -12), Pair(10, -16),
        Pair(8, -42), Pair(-17, -7), Pair(-23, -6), Pair(-2, -5), Pair(-12, -13), Pair(3, -19), Pair(4, -22), Pair(8, -29)
      }
    }},
    {{ // Bucket 37
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(27, 8), Pair(-12, 20), Pair(-6, 14), Pair(20, -3), Pair(-11, 10), Pair(-35, 18), Pair(4, 20), Pair(0, 13),
        Pair(8, 10), Pair(3, 7), Pair(1, 10), Pair(13, 12), Pair(0, 5), Pair(-13, 12), Pair(-20, 22), Pair(-2, 10),
        Pair(-1, 10), Pair(4, 6), Pair(5, 4), Pair(9, 9), Pair(9, 5), Pair(-2, -8), Pair(4, 0), Pair(0, 4),
        Pair(2, 11), Pair(6, 12), Pair(7, 7), Pair(-2, 4), Pair(5, 8), Pair(-4, -5), Pair(5, -3), Pair(-1, 0),
        Pair(0, 11), Pair(2, 11), Pair(3, 8), Pair(2, 6), Pair(16, 9), Pair(0, 0), Pair(11, 1), Pair(0, 6),
        Pair(3, 12), Pair(5, 11), Pair(1, 9), Pair(-3, 17), Pair(14, 14), Pair(3, 6), Pair(7, 13), Pair(-4, 10),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(12, -8), Pair(-134, 39), Pair(-33, 18), Pair(73, 13), Pair(56, 37), Pair(84, 22), Pair(142, 34), Pair(-17, 40),
        Pair(-5, 10), Pair(-6, 30), Pair(28, 29), Pair(4, 50), Pair(52, 26), Pair(-28, 46), Pair(34, 60), Pair(-38, 42),
        Pair(9, 12), Pair(-2, 53), Pair(12, 38), Pair(-1, 56), Pair(9, 36), Pair(-31, 42), Pair(3, 35), Pair(38, 3),
        Pair(17, 34), Pair(7, 45), Pair(5, 52), Pair(7, 60), Pair(17, 44), Pair(-13, 44), Pair(-4, 33), Pair(-9, 13),
        Pair(0, 27), Pair(13, 45), Pair(8, 47), Pair(18, 36), Pair(2, 38), Pair(0, 0), Pair(-18, 47), Pair(-9, 43),
        Pair(0, 33), Pair(4, 50), Pair(9, 36), Pair(7, 39), Pair(25, 40), Pair(10, 58), Pair(13, 41), Pair(-13, 15),
        Pair(-1, 48), Pair(3, 28), Pair(10, 37), Pair(6, 29), Pair(0, 38), Pair(7, 25), Pair(6, 24), Pair(-4, 11),
        Pair(2, 50), Pair(0, 25), Pair(17, 35), Pair(5, 36), Pair(9, 24), Pair(-11, 30), Pair(3, 35), Pair(12, 61)
      },
      { // Piece 2
        Pair(-4, 7), Pair(17, -33), Pair(60, 20), Pair(36, -13), Pair(-2, 17), Pair(33, -29), Pair(120, 19), Pair(-21, 14),
        Pair(-10, 11), Pair(14, 13), Pair(6, -9), Pair(18, 11), Pair(30, -18), Pair(2, 4), Pair(56, -17), Pair(-8, 18),
        Pair(23, 29), Pair(3, -2), Pair(25, 12), Pair(23, -5), Pair(36, 17), Pair(-4, 3), Pair(15, 14), Pair(-10, -35),
        Pair(6, -2), Pair(27, 12), Pair(6, 6), Pair(13, 28), Pair(21, 3), Pair(2, 13), Pair(-23, 14), Pair(-7, 36),
        Pair(17, 17), Pair(16, 6), Pair(13, 29), Pair(8, 6), Pair(13, 30), Pair(0, 0), Pair(18, 15), Pair(-10, 9),
        Pair(0, 8), Pair(12, 34), Pair(-3, 16), Pair(18, 29), Pair(-1, 16), Pair(25, 40), Pair(-7, -12), Pair(7, 35),
        Pair(17, 4), Pair(-3, 23), Pair(9, 31), Pair(-10, 7), Pair(19, 21), Pair(12, -7), Pair(13, 28), Pair(-18, -65),
        Pair(-20, 18), Pair(19, 11), Pair(-16, 8), Pair(14, 25), Pair(-6, 5), Pair(14, 22), Pair(9, -7), Pair(27, 23)
      },
      { // Piece 3
        Pair(46, 31), Pair(56, 29), Pair(23, 42), Pair(46, 35), Pair(13, 44), Pair(98, 4), Pair(43, 22), Pair(35, 33),
        Pair(37, 37), Pair(20, 40), Pair(33, 37), Pair(32, 33), Pair(28, 32), Pair(11, 23), Pair(-11, 40), Pair(49, 35),
        Pair(21, 39), Pair(45, 25), Pair(38, 29), Pair(37, 26), Pair(8, 44), Pair(72, 11), Pair(20, 43), Pair(25, 39),
        Pair(17, 37), Pair(19, 43), Pair(19, 42), Pair(28, 37), Pair(37, 50), Pair(3, 18), Pair(-6, 57), Pair(1, 46),
        Pair(9, 45), Pair(19, 43), Pair(15, 46), Pair(29, 29), Pair(12, 42), Pair(0, 0), Pair(12, 27), Pair(-12, 29),
        Pair(25, 32), Pair(8, 44), Pair(14, 45), Pair(20, 35), Pair(17, 33), Pair(26, 12), Pair(23, 19), Pair(24, 30),
        Pair(-11, 39), Pair(16, 29), Pair(15, 29), Pair(21, 27), Pair(12, 42), Pair(9, 15), Pair(27, 11), Pair(40, 30),
        Pair(16, 30), Pair(18, 31), Pair(20, 26), Pair(15, 40), Pair(14, 35), Pair(14, 19), Pair(13, 34), Pair(8, 33)
      },
      { // Piece 4
        Pair(24, 65), Pair(34, 49), Pair(-19, 92), Pair(60, 25), Pair(-3, 98), Pair(30, 14), Pair(-80, 95), Pair(27, 46),
        Pair(6, 67), Pair(-5, 53), Pair(-4, 57), Pair(39, 25), Pair(-7, 79), Pair(-28, 47), Pair(-45, 86), Pair(-16, 56),
        Pair(-23, 86), Pair(-32, 110), Pair(29, 62), Pair(10, 52), Pair(-6, 82), Pair(-1, 51), Pair(-7, 31), Pair(17, 31),
        Pair(-7, 73), Pair(-13, 94), Pair(4, 65), Pair(9, 69), Pair(4, 76), Pair(1, 29), Pair(17, 62), Pair(-18, 80),
        Pair(19, 34), Pair(25, 49), Pair(-6, 87), Pair(9, 69), Pair(-1, 75), Pair(0, 0), Pair(-2, 68), Pair(8, 31),
        Pair(11, 86), Pair(9, 76), Pair(2, 79), Pair(7, 77), Pair(0, 74), Pair(10, 64), Pair(6, 33), Pair(16, 35),
        Pair(7, 52), Pair(14, 85), Pair(16, 49), Pair(3, 69), Pair(9, 75), Pair(15, 38), Pair(4, 97), Pair(-14, 36),
        Pair(8, 102), Pair(9, 89), Pair(9, 55), Pair(8, 79), Pair(20, 42), Pair(17, 49), Pair(22, 25), Pair(4, 46)
      },
      { // Piece 5
        Pair(68, -70), Pair(-49, 28), Pair(-50, 12), Pair(86, 27), Pair(-107, 73), Pair(-44, 73), Pair(-36, 73), Pair(-26, 23),
        Pair(-18, 18), Pair(52, 1), Pair(54, -8), Pair(-22, 30), Pair(-58, 60), Pair(-53, 60), Pair(167, 25), Pair(-31, 65),
        Pair(-112, 35), Pair(22, 26), Pair(11, 11), Pair(-77, 42), Pair(77, 41), Pair(23, 43), Pair(-10, 39), Pair(-52, 28),
        Pair(-71, 29), Pair(-45, 3), Pair(-51, 23), Pair(-47, 24), Pair(-3, 8), Pair(74, -6), Pair(39, -2), Pair(-20, 19),
        Pair(-53, -1), Pair(61, -2), Pair(-32, 22), Pair(3, 28), Pair(33, 8), Pair(0, 0), Pair(10, 0), Pair(16, 13),
        Pair(-16, 23), Pair(-34, 7), Pair(14, 1), Pair(2, 15), Pair(-21, 15), Pair(-46, 29), Pair(-21, 9), Pair(25, -4),
        Pair(-7, -13), Pair(-21, 0), Pair(13, -16), Pair(-18, 5), Pair(-22, 15), Pair(-53, 23), Pair(-17, 5), Pair(13, -3),
        Pair(-5, -27), Pair(-12, -12), Pair(-8, -17), Pair(-1, -16), Pair(1, -20), Pair(-31, -8), Pair(6, -27), Pair(6, -28)
      }
    }},
    {{ // Bucket 38
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(14, 6), Pair(-19, 28), Pair(-34, 21), Pair(-19, 5), Pair(8, 0), Pair(29, 8), Pair(35, -22), Pair(-7, 15),
        Pair(6, 8), Pair(-5, 19), Pair(6, 9), Pair(-11, 18), Pair(-12, 14), Pair(-14, 18), Pair(-2, -8), Pair(11, 13),
        Pair(0, 12), Pair(2, 10), Pair(1, 9), Pair(5, 6), Pair(4, 9), Pair(4, 4), Pair(9, -16), Pair(1, -4),
        Pair(-5, 12), Pair(2, 14), Pair(3, 8), Pair(2, 9), Pair(-2, 6), Pair(5, -4), Pair(4, 8), Pair(8, -6),
        Pair(-3, 17), Pair(1, 12), Pair(1, 13), Pair(4, 10), Pair(-2, 10), Pair(22, 4), Pair(5, -8), Pair(14, 4),
        Pair(-4, 16), Pair(1, 12), Pair(-2, 11), Pair(6, 10), Pair(-1, 14), Pair(9, 19), Pair(4, -1), Pair(5, 17),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-16, 17), Pair(80, -1), Pair(9, 24), Pair(90, -10), Pair(-34, 53), Pair(42, 34), Pair(-41, 30), Pair(36, -30),
        Pair(-3, 19), Pair(4, 37), Pair(46, 26), Pair(76, 24), Pair(12, 33), Pair(-7, 18), Pair(-44, 57), Pair(54, -5),
        Pair(-11, 4), Pair(0, 33), Pair(6, 30), Pair(18, 34), Pair(16, 35), Pair(19, 33), Pair(33, 11), Pair(39, 0),
        Pair(-4, 24), Pair(13, 32), Pair(12, 37), Pair(22, 38), Pair(14, 32), Pair(27, 23), Pair(29, 11), Pair(-29, -18),
        Pair(0, 43), Pair(-4, 28), Pair(13, 30), Pair(7, 32), Pair(27, 37), Pair(14, 32), Pair(0, 0), Pair(6, 27),
        Pair(-17, 30), Pair(-4, 36), Pair(8, 27), Pair(14, 33), Pair(5, 30), Pair(10, 39), Pair(21, 46), Pair(-2, 27),
        Pair(8, 52), Pair(-20, 44), Pair(-28, 55), Pair(-6, 47), Pair(1, 31), Pair(12, 15), Pair(20, 28), Pair(-13, -14),
        Pair(-64, -14), Pair(-16, 17), Pair(31, 15), Pair(-1, 25), Pair(-10, 18), Pair(-6, 21), Pair(-2, 8), Pair(-37, 34)
      },
      { // Piece 2
        Pair(-32, -10), Pair(-44, -2), Pair(61, -14), Pair(61, -5), Pair(31, -27), Pair(79, -1), Pair(147, -17), Pair(-68, 31),
        Pair(38, -11), Pair(20, -18), Pair(-28, 14), Pair(66, -27), Pair(38, 11), Pair(44, -30), Pair(41, 7), Pair(-15, 7),
        Pair(9, 0), Pair(22, 14), Pair(42, -19), Pair(19, 18), Pair(-5, 5), Pair(36, 7), Pair(19, 2), Pair(4, 3),
        Pair(19, 13), Pair(8, -3), Pair(41, 24), Pair(46, -11), Pair(25, 14), Pair(64, -12), Pair(27, 0), Pair(-73, -13),
        Pair(16, -3), Pair(6, 39), Pair(18, -1), Pair(11, 29), Pair(11, 15), Pair(12, 23), Pair(0, 0), Pair(11, 25),
        Pair(6, 38), Pair(22, -5), Pair(3, 29), Pair(15, 0), Pair(13, 26), Pair(2, 12), Pair(30, 25), Pair(-15, -31),
        Pair(29, -29), Pair(3, 32), Pair(-1, 22), Pair(13, 24), Pair(-4, 12), Pair(18, 16), Pair(7, 11), Pair(16, 20),
        Pair(3, 32), Pair(24, 7), Pair(-2, 40), Pair(-19, 13), Pair(16, 8), Pair(-7, -6), Pair(-1, 28), Pair(-4, -8)
      },
      { // Piece 3
        Pair(38, 32), Pair(51, 22), Pair(55, 22), Pair(39, 25), Pair(30, 19), Pair(13, 55), Pair(147, -27), Pair(12, 37),
        Pair(20, 34), Pair(7, 36), Pair(40, 20), Pair(29, 22), Pair(79, 8), Pair(51, 22), Pair(49, 2), Pair(8, 42),
        Pair(4, 40), Pair(8, 37), Pair(40, 21), Pair(60, 13), Pair(31, 24), Pair(32, 26), Pair(40, 2), Pair(11, 29),
        Pair(13, 44), Pair(6, 41), Pair(12, 39), Pair(44, 20), Pair(24, 34), Pair(17, 50), Pair(27, 3), Pair(-20, 51),
        Pair(16, 34), Pair(40, 18), Pair(19, 27), Pair(10, 28), Pair(27, 37), Pair(-6, 56), Pair(0, 0), Pair(2, -1),
        Pair(8, 40), Pair(13, 29), Pair(13, 24), Pair(-2, 36), Pair(23, 31), Pair(13, 35), Pair(9, 13), Pair(-32, 71),
        Pair(-10, 30), Pair(30, 32), Pair(26, 23), Pair(7, 30), Pair(18, 23), Pair(2, 30), Pair(-2, 13), Pair(17, 19),
        Pair(13, 32), Pair(16, 18), Pair(14, 26), Pair(14, 26), Pair(15, 23), Pair(13, 28), Pair(2, 7), Pair(-3, 17)
      },
      { // Piece 4
        Pair(49, 14), Pair(59, -3), Pair(18, -1), Pair(44, 37), Pair(2, 63), Pair(93, 10), Pair(78, -22), Pair(62, 32),
        Pair(-4, 34), Pair(21, -6), Pair(5, 31), Pair(17, 27), Pair(51, 9), Pair(-1, 34), Pair(16, -24), Pair(85, -62),
        Pair(5, 40), Pair(19, 36), Pair(4, 24), Pair(37, 23), Pair(5, 34), Pair(22, 33), Pair(27, -8), Pair(58, -18),
        Pair(17, 35), Pair(-1, 68), Pair(-6, 72), Pair(16, 32), Pair(32, 23), Pair(-3, 42), Pair(5, 12), Pair(8, 21),
        Pair(17, 14), Pair(4, 60), Pair(16, 15), Pair(-8, 57), Pair(5, 31), Pair(14, 21), Pair(0, 0), Pair(7, -25),
        Pair(-3, 41), Pair(17, 32), Pair(-1, 58), Pair(16, 26), Pair(19, 34), Pair(6, 37), Pair(10, -1), Pair(6, 2),
        Pair(3, -2), Pair(10, 12), Pair(4, 42), Pair(12, 52), Pair(13, 15), Pair(0, 45), Pair(13, 22), Pair(14, 33),
        Pair(12, 3), Pair(21, 36), Pair(0, 63), Pair(1, 65), Pair(5, 31), Pair(9, 26), Pair(22, -54), Pair(-28, 41)
      },
      { // Piece 5
        Pair(-54, -17), Pair(-38, 51), Pair(-10, -10), Pair(7, 43), Pair(-24, 57), Pair(106, 50), Pair(11, 52), Pair(51, 212),
        Pair(-71, 10), Pair(4, -6), Pair(2, 11), Pair(-12, -29), Pair(37, 10), Pair(30, 55), Pair(228, 32), Pair(41, 67),
        Pair(-95, 15), Pair(-122, 44), Pair(-80, 16), Pair(-60, 22), Pair(30, 10), Pair(102, 43), Pair(89, 57), Pair(48, 40),
        Pair(-94, -1), Pair(-30, 14), Pair(-17, 21), Pair(-54, 33), Pair(-17, 35), Pair(25, 0), Pair(50, 16), Pair(-66, 24),
        Pair(-48, 25), Pair(17, 5), Pair(-39, 14), Pair(-45, 29), Pair(-23, 28), Pair(18, 6), Pair(0, 0), Pair(-2, 6),
        Pair(-62, -1), Pair(-58, 14), Pair(-23, 8), Pair(-39, 17), Pair(-9, 13), Pair(-34, 15), Pair(-9, 10), Pair(-30, 7),
        Pair(-25, -4), Pair(-29, 12), Pair(-19, -5), Pair(-31, 7), Pair(-2, 5), Pair(-37, 14), Pair(8, -1), Pair(-26, 16),
        Pair(-38, -14), Pair(-16, -12), Pair(-16, -1), Pair(-32, 4), Pair(-6, -3), Pair(-8, -24), Pair(17, -18), Pair(-9, -20)
      }
    }},
    {{ // Bucket 39
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(8, 4), Pair(-14, 15), Pair(-3, 5), Pair(-13, 12), Pair(-21, 11), Pair(-19, 2), Pair(-12, 14), Pair(42, 6),
        Pair(-3, 14), Pair(-5, 15), Pair(0, 7), Pair(4, 11), Pair(-6, 11), Pair(-20, 7), Pair(-27, 23), Pair(22, -17),
        Pair(0, 12), Pair(3, 11), Pair(1, 7), Pair(3, 9), Pair(-4, 6), Pair(-5, 4), Pair(3, 1), Pair(8, -6),
        Pair(-2, 14), Pair(-1, 11), Pair(-2, 10), Pair(1, 9), Pair(4, 8), Pair(-1, 0), Pair(8, -5), Pair(9, 3),
        Pair(-3, 16), Pair(-1, 15), Pair(1, 11), Pair(0, 10), Pair(3, 11), Pair(6, 4), Pair(10, 2), Pair(-1, 9),
        Pair(2, 13), Pair(-1, 13), Pair(-3, 11), Pair(2, 9), Pair(-1, 9), Pair(4, 10), Pair(4, 11), Pair(2, 9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(81, 6), Pair(175, -27), Pair(-112, 44), Pair(-3, 26), Pair(38, 18), Pair(52, 26), Pair(110, -25), Pair(6, 7),
        Pair(12, 17), Pair(-15, 41), Pair(3, 18), Pair(44, 9), Pair(29, 26), Pair(36, 13), Pair(-31, 54), Pair(-25, -4),
        Pair(5, 32), Pair(-4, 22), Pair(27, 17), Pair(25, 23), Pair(40, 22), Pair(58, 1), Pair(12, 22), Pair(7, 13),
        Pair(-1, 16), Pair(0, 36), Pair(15, 26), Pair(15, 28), Pair(15, 26), Pair(31, 22), Pair(32, 6), Pair(-8, 21),
        Pair(-9, 18), Pair(-6, 43), Pair(17, 26), Pair(9, 33), Pair(22, 17), Pair(13, 26), Pair(31, 20), Pair(0, 0),
        Pair(-11, 20), Pair(-7, 36), Pair(1, 36), Pair(6, 27), Pair(9, 32), Pair(5, 28), Pair(10, 25), Pair(2, 63),
        Pair(-24, 38), Pair(-3, 40), Pair(2, 22), Pair(-1, 31), Pair(-1, 35), Pair(4, 25), Pair(-27, 55), Pair(-7, 21),
        Pair(-38, 58), Pair(-13, 28), Pair(-13, 13), Pair(-14, 19), Pair(12, 15), Pair(-1, 15), Pair(7, -13), Pair(-34, 0)
      },
      { // Piece 2
        Pair(54, -4), Pair(18, -1), Pair(-20, 17), Pair(48, -7), Pair(118, -23), Pair(6, 25), Pair(-76, 40), Pair(-31, 4),
        Pair(21, -24), Pair(-4, 8), Pair(-10, -6), Pair(41, -17), Pair(23, -2), Pair(5, 15), Pair(13, 16), Pair(0, 23),
        Pair(-1, 9), Pair(9, 1), Pair(22, 9), Pair(38, -6), Pair(41, 7), Pair(33, 11), Pair(28, 19), Pair(13, 12),
        Pair(-1, -1), Pair(16, 7), Pair(20, 6), Pair(23, 13), Pair(19, -2), Pair(27, 16), Pair(-5, 44), Pair(1, 13),
        Pair(8, 24), Pair(10, 7), Pair(22, 10), Pair(12, 9), Pair(24, 19), Pair(11, 11), Pair(1, 18), Pair(0, 0),
        Pair(-2, 25), Pair(9, 7), Pair(10, -1), Pair(19, 11), Pair(13, 15), Pair(11, 21), Pair(17, 19), Pair(20, 25),
        Pair(12, -5), Pair(6, 11), Pair(14, 17), Pair(7, 8), Pair(4, 28), Pair(13, 8), Pair(14, 11), Pair(-6, 0),
        Pair(27, 16), Pair(42, 13), Pair(-1, 19), Pair(-8, 28), Pair(10, 12), Pair(-1, 15), Pair(14, -11), Pair(19, -4)
      },
      { // Piece 3
        Pair(-3, 39), Pair(39, 29), Pair(35, 26), Pair(-8, 43), Pair(51, 18), Pair(50, 20), Pair(55, 13), Pair(37, 1),
        Pair(27, 30), Pair(6, 38), Pair(-4, 40), Pair(17, 28), Pair(-3, 44), Pair(51, 9), Pair(-34, 46), Pair(82, -9),
        Pair(10, 46), Pair(8, 35), Pair(15, 28), Pair(23, 29), Pair(4, 33), Pair(33, 19), Pair(38, 25), Pair(14, 14),
        Pair(9, 37), Pair(35, 25), Pair(20, 40), Pair(25, 39), Pair(0, 43), Pair(16, 41), Pair(27, 41), Pair(19, -2),
        Pair(16, 31), Pair(7, 37), Pair(-1, 40), Pair(1, 38), Pair(18, 40), Pair(21, 33), Pair(9, 38), Pair(0, 0),
        Pair(0, 33), Pair(7, 27), Pair(9, 40), Pair(-1, 34), Pair(4, 37), Pair(-5, 29), Pair(-3, 36), Pair(-64, 30),
        Pair(4, 23), Pair(-1, 37), Pair(2, 37), Pair(-2, 32), Pair(0, 39), Pair(7, 23), Pair(-18, 24), Pair(-36, 4),
        Pair(7, 30), Pair(10, 20), Pair(11, 30), Pair(10, 25), Pair(6, 25), Pair(7, 32), Pair(-7, 27), Pair(-27, -3)
      },
      { // Piece 4
        Pair(10, 43), Pair(55, -10), Pair(60, -7), Pair(40, -2), Pair(54, 12), Pair(30, 36), Pair(17, 21), Pair(40, 0),
        Pair(19, 25), Pair(12, 29), Pair(-3, 50), Pair(35, -11), Pair(11, 34), Pair(25, 44), Pair(13, 30), Pair(30, 10),
        Pair(23, 2), Pair(7, 48), Pair(18, 17), Pair(32, -8), Pair(44, 38), Pair(18, 9), Pair(42, -28), Pair(6, -5),
        Pair(21, 8), Pair(28, -3), Pair(11, 21), Pair(22, 16), Pair(8, 33), Pair(0, 30), Pair(1, 40), Pair(-7, 11),
        Pair(7, 13), Pair(11, 34), Pair(9, 40), Pair(5, 43), Pair(12, 29), Pair(9, 44), Pair(11, 37), Pair(0, 0),
        Pair(14, 21), Pair(14, 16), Pair(15, 29), Pair(9, 28), Pair(10, 30), Pair(19, 22), Pair(4, 41), Pair(-6, 6),
        Pair(-7, 41), Pair(5, 50), Pair(7, 55), Pair(11, 53), Pair(-3, 58), Pair(7, 26), Pair(13, 3), Pair(10, -41),
        Pair(4, 63), Pair(6, 73), Pair(0, 65), Pair(12, 43), Pair(6, 38), Pair(12, -23), Pair(-4, 88), Pair(6, -54)
      },
      { // Piece 5
        Pair(-33, 23), Pair(-88, -16), Pair(-47, 1), Pair(-139, 17), Pair(-44, 6), Pair(-11, 25), Pair(-62, 55), Pair(26, -8),
        Pair(-26, -32), Pair(-7, -6), Pair(-121, 4), Pair(0, 46), Pair(-18, 45), Pair(-125, 90), Pair(-123, 63), Pair(-40, 34),
        Pair(30, 24), Pair(-71, 17), Pair(-65, 47), Pair(-50, 10), Pair(-28, 34), Pair(2, 31), Pair(-18, 44), Pair(-10, 8),
        Pair(-59, 11), Pair(-70, 2), Pair(-120, 32), Pair(-86, 38), Pair(-69, 35), Pair(-18, 26), Pair(-18, 7), Pair(-49, -7),
        Pair(5, 7), Pair(-59, 22), Pair(-50, 18), Pair(-44, 27), Pair(-51, 22), Pair(21, 9), Pair(-4, -15), Pair(0, 0),
        Pair(-75, 8), Pair(-50, 13), Pair(-62, 24), Pair(-44, 11), Pair(-27, 11), Pair(9, 0), Pair(-40, -5), Pair(-66, -15),
        Pair(-55, 14), Pair(-42, 2), Pair(-61, 21), Pair(-47, 12), Pair(-18, 3), Pair(-26, 5), Pair(-5, -5), Pair(-1, -27),
        Pair(-50, 5), Pair(-28, -5), Pair(-32, 2), Pair(-27, -8), Pair(-12, -6), Pair(-6, -12), Pair(17, -13), Pair(7, -38)
      }
    }},
    {{ // Bucket 40
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-41, 49), Pair(3, -11), Pair(-4, 16), Pair(21, 11), Pair(37, -20), Pair(15, 20), Pair(-1, 5), Pair(-24, 33),
        Pair(-2, 19), Pair(-11, 21), Pair(-6, 14), Pair(-9, 11), Pair(8, 10), Pair(-1, 9), Pair(1, 10), Pair(-8, 9),
        Pair(5, 11), Pair(-1, 14), Pair(2, 9), Pair(1, 11), Pair(2, 8), Pair(2, 8), Pair(2, 8), Pair(-5, 12),
        Pair(1, 10), Pair(5, 11), Pair(0, 6), Pair(0, 9), Pair(2, 9), Pair(4, 12), Pair(-5, 13), Pair(-4, 15),
        Pair(-4, 4), Pair(-2, 4), Pair(-3, 10), Pair(3, 14), Pair(0, 11), Pair(2, 12), Pair(-4, 14), Pair(-6, 17),
        Pair(10, -4), Pair(6, 21), Pair(-5, 13), Pair(2, 12), Pair(-2, 12), Pair(2, 18), Pair(-1, 19), Pair(-1, 20),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(11, -24), Pair(-113, 69), Pair(-13, 61), Pair(-48, 42), Pair(-97, 62), Pair(24, 41), Pair(-3, 43), Pair(-27, 41),
        Pair(-27, 34), Pair(-8, 45), Pair(13, 34), Pair(-5, 63), Pair(-18, 58), Pair(1, 74), Pair(-2, 29), Pair(-31, 35),
        Pair(-10, 33), Pair(13, 31), Pair(-1, 48), Pair(-9, 41), Pair(-9, 40), Pair(1, 36), Pair(-35, 66), Pair(-39, 62),
        Pair(-3, 40), Pair(6, 46), Pair(4, 35), Pair(2, 42), Pair(2, 57), Pair(-3, 54), Pair(-5, 44), Pair(-11, 52),
        Pair(-5, 29), Pair(21, 46), Pair(6, 45), Pair(3, 50), Pair(0, 49), Pair(6, 45), Pair(-12, 42), Pair(-4, 44),
        Pair(0, 0), Pair(2, 34), Pair(4, 35), Pair(5, 43), Pair(4, 56), Pair(3, 42), Pair(-1, 50), Pair(2, 36),
        Pair(-15, 66), Pair(3, 37), Pair(-2, 40), Pair(-1, 51), Pair(-4, 54), Pair(-1, 48), Pair(6, 48), Pair(-9, 45),
        Pair(95, -23), Pair(-6, 17), Pair(-6, 56), Pair(-12, 67), Pair(3, 39), Pair(-4, 44), Pair(-2, 36), Pair(1, 30)
      },
      { // Piece 2
        Pair(0, 24), Pair(48, 11), Pair(-4, 37), Pair(-13, 0), Pair(-24, 27), Pair(90, -18), Pair(-74, 26), Pair(-31, -2),
        Pair(-5, 31), Pair(5, 35), Pair(2, 23), Pair(52, 4), Pair(38, -22), Pair(-13, 45), Pair(9, -1), Pair(-19, 34),
        Pair(10, 37), Pair(42, 9), Pair(1, 45), Pair(-2, 11), Pair(21, 9), Pair(39, 2), Pair(17, 32), Pair(-9, 29),
        Pair(1, 28), Pair(16, 38), Pair(12, 12), Pair(19, 30), Pair(15, 18), Pair(28, 32), Pair(3, 22), Pair(-2, 46),
        Pair(1, 36), Pair(16, 24), Pair(6, 36), Pair(6, 25), Pair(10, 34), Pair(6, 27), Pair(-3, 55), Pair(-8, 24),
        Pair(0, 0), Pair(12, 28), Pair(6, 24), Pair(5, 45), Pair(2, 33), Pair(9, 40), Pair(5, 37), Pair(16, 28),
        Pair(23, 31), Pair(5, 24), Pair(3, 39), Pair(0, 36), Pair(7, 43), Pair(-2, 35), Pair(5, 44), Pair(4, 31),
        Pair(-3, 4), Pair(4, 41), Pair(-8, 24), Pair(4, 38), Pair(1, 26), Pair(-8, 57), Pair(-14, 9), Pair(-10, 44)
      },
      { // Piece 3
        Pair(14, 18), Pair(-24, 67), Pair(2, 57), Pair(-27, 81), Pair(-65, 82), Pair(52, 36), Pair(-34, 76), Pair(-3, 60),
        Pair(-35, 44), Pair(-25, 78), Pair(9, 59), Pair(-3, 63), Pair(-27, 72), Pair(-38, 73), Pair(-28, 75), Pair(-1, 66),
        Pair(-19, 48), Pair(-3, 64), Pair(1, 63), Pair(-16, 72), Pair(4, 49), Pair(7, 60), Pair(-25, 75), Pair(0, 65),
        Pair(-50, 62), Pair(-3, 64), Pair(16, 53), Pair(14, 56), Pair(8, 64), Pair(-17, 74), Pair(20, 59), Pair(5, 70),
        Pair(-25, 47), Pair(4, 67), Pair(-10, 81), Pair(14, 57), Pair(6, 62), Pair(-5, 70), Pair(-12, 80), Pair(-1, 71),
        Pair(0, 0), Pair(-4, 61), Pair(-1, 61), Pair(4, 66), Pair(4, 69), Pair(-3, 67), Pair(0, 65), Pair(5, 64),
        Pair(-38, 40), Pair(-4, 54), Pair(-1, 54), Pair(-8, 71), Pair(8, 63), Pair(-9, 65), Pair(-14, 59), Pair(-3, 74),
        Pair(-26, 32), Pair(-5, 61), Pair(-2, 67), Pair(0, 66), Pair(0, 60), Pair(-1, 57), Pair(0, 67), Pair(6, 50)
      },
      { // Piece 4
        Pair(24, 86), Pair(-21, 106), Pair(-9, 122), Pair(-48, 159), Pair(-16, 116), Pair(28, 136), Pair(-31, 78), Pair(-6, 122),
        Pair(-19, 94), Pair(4, 66), Pair(19, 95), Pair(54, 66), Pair(-18, 94), Pair(28, 60), Pair(30, 124), Pair(5, 64),
        Pair(-12, 108), Pair(4, 95), Pair(12, 116), Pair(3, 94), Pair(-12, 91), Pair(0, 119), Pair(-1, 100), Pair(-3, 136),
        Pair(-6, 100), Pair(9, 95), Pair(-2, 104), Pair(-2, 109), Pair(32, 54), Pair(-5, 93), Pair(4, 93), Pair(9, 108),
        Pair(-9, 121), Pair(12, 119), Pair(12, 94), Pair(13, 99), Pair(4, 117), Pair(10, 114), Pair(10, 107), Pair(4, 107),
        Pair(0, 0), Pair(14, 106), Pair(14, 96), Pair(14, 120), Pair(11, 115), Pair(2, 121), Pair(18, 102), Pair(25, 67),
        Pair(11, 48), Pair(13, 93), Pair(12, 101), Pair(10, 109), Pair(11, 115), Pair(1, 119), Pair(18, 115), Pair(7, 62),
        Pair(13, 63), Pair(8, 108), Pair(3, 112), Pair(11, 103), Pair(8, 135), Pair(21, 103), Pair(7, 91), Pair(13, 63)
      },
      { // Piece 5
        Pair(-33, 36), Pair(108, 75), Pair(22, 31), Pair(27, 22), Pair(-51, 10), Pair(-84, 15), Pair(19, 17), Pair(-115, -77),
        Pair(-109, 42), Pair(-71, 81), Pair(103, 19), Pair(-19, 29), Pair(26, -18), Pair(-23, 2), Pair(-36, 4), Pair(-71, -42),
        Pair(-66, -10), Pair(-23, 58), Pair(12, 59), Pair(-74, 49), Pair(-212, 83), Pair(49, -16), Pair(-73, 10), Pair(-71, 38),
        Pair(-63, 21), Pair(8, 24), Pair(10, 24), Pair(-48, 51), Pair(-66, 20), Pair(-48, 31), Pair(-55, 26), Pair(-105, 24),
        Pair(-35, -3), Pair(-47, 8), Pair(-14, 15), Pair(-51, 33), Pair(-56, 23), Pair(32, 4), Pair(-34, 14), Pair(-53, 15),
        Pair(0, 0), Pair(-19, 21), Pair(4, 15), Pair(-14, 16), Pair(-13, 14), Pair(-29, 17), Pair(-20, 5), Pair(-29, -5),
        Pair(6, -56), Pair(27, -16), Pair(42, -11), Pair(19, 4), Pair(-16, 16), Pair(-14, 13), Pair(-16, 6), Pair(-8, -2),
        Pair(53, -72), Pair(88, -23), Pair(42, -8), Pair(-4, 0), Pair(3, -13), Pair(-13, 0), Pair(-6, -1), Pair(-1, -17)
      }
    }},
    {{ // Bucket 41
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-29, 34), Pair(-38, 20), Pair(-23, 16), Pair(-20, 20), Pair(11, -8), Pair(-5, 10), Pair(-16, 5), Pair(7, 6),
        Pair(-14, 21), Pair(2, 9), Pair(0, 6), Pair(-5, 13), Pair(2, 0), Pair(-8, 12), Pair(-2, 2), Pair(-7, 9),
        Pair(-4, 14), Pair(6, 8), Pair(-2, 11), Pair(1, 14), Pair(3, 6), Pair(3, 11), Pair(1, 9), Pair(-5, 13),
        Pair(0, 5), Pair(-7, 2), Pair(4, 6), Pair(4, 8), Pair(4, 8), Pair(6, 12), Pair(2, 13), Pair(-2, 12),
        Pair(-2, 5), Pair(-6, 3), Pair(0, 10), Pair(-4, 11), Pair(-1, 13), Pair(3, 12), Pair(3, 11), Pair(0, 13),
        Pair(3, 18), Pair(5, -5), Pair(7, 24), Pair(3, 15), Pair(-2, 18), Pair(-1, 16), Pair(1, 19), Pair(1, 19),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-40, 31), Pair(-58, 78), Pair(2, 49), Pair(-13, 64), Pair(-39, 70), Pair(-79, 52), Pair(-104, 37), Pair(-124, 59),
        Pair(-9, 44), Pair(-3, 46), Pair(-15, 38), Pair(10, 37), Pair(-48, 64), Pair(32, 21), Pair(10, 51), Pair(-53, 46),
        Pair(-37, 46), Pair(-7, 42), Pair(6, 47), Pair(-16, 49), Pair(-15, 51), Pair(-3, 30), Pair(-20, 53), Pair(-58, 68),
        Pair(-23, 45), Pair(-4, 43), Pair(-1, 55), Pair(-10, 57), Pair(-2, 53), Pair(-7, 45), Pair(-9, 49), Pair(-14, 52),
        Pair(1, 33), Pair(1, 38), Pair(5, 36), Pair(0, 53), Pair(-5, 49), Pair(1, 58), Pair(-8, 42), Pair(0, 25),
        Pair(-6, 43), Pair(0, 0), Pair(0, 46), Pair(14, 47), Pair(10, 45), Pair(-2, 49), Pair(3, 45), Pair(0, 53),
        Pair(-14, 80), Pair(12, 53), Pair(3, 49), Pair(-5, 44), Pair(0, 54), Pair(-5, 54), Pair(3, 46), Pair(-4, 54),
        Pair(24, -53), Pair(-10, 38), Pair(-6, 30), Pair(-5, 46), Pair(3, 57), Pair(-2, 44), Pair(-6, 45), Pair(60, -18)
      },
      { // Piece 2
        Pair(31, -11), Pair(-39, 41), Pair(-27, 21), Pair(21, 37), Pair(-48, 9), Pair(17, 21), Pair(-30, 19), Pair(-33, 77),
        Pair(9, 35), Pair(6, 14), Pair(-4, 52), Pair(60, -6), Pair(19, 25), Pair(30, 6), Pair(-22, 25), Pair(-11, 14),
        Pair(-24, 28), Pair(12, 38), Pair(11, 24), Pair(10, 33), Pair(16, 14), Pair(15, 20), Pair(-6, 13), Pair(-15, 37),
        Pair(-4, 41), Pair(-2, 11), Pair(-12, 56), Pair(-8, 20), Pair(1, 25), Pair(9, 9), Pair(-7, 34), Pair(-18, 41),
        Pair(-60, -11), Pair(-15, 41), Pair(-2, 25), Pair(4, 32), Pair(5, 20), Pair(4, 45), Pair(20, 17), Pair(-14, 52),
        Pair(-3, 31), Pair(0, 0), Pair(2, 40), Pair(-2, 30), Pair(3, 49), Pair(2, 34), Pair(4, 46), Pair(-2, 38),
        Pair(-46, -49), Pair(4, 51), Pair(-1, 15), Pair(3, 48), Pair(-6, 48), Pair(9, 40), Pair(-5, 43), Pair(2, 43),
        Pair(7, 16), Pair(-7, 21), Pair(-1, 32), Pair(-5, 25), Pair(7, 41), Pair(-4, 40), Pair(-10, 41), Pair(-9, 45)
      },
      { // Piece 3
        Pair(-47, 73), Pair(-30, 42), Pair(-56, 69), Pair(-30, 69), Pair(-42, 68), Pair(-25, 58), Pair(-19, 57), Pair(43, 38),
        Pair(-23, 59), Pair(-25, 44), Pair(-32, 66), Pair(-8, 57), Pair(16, 38), Pair(-24, 59), Pair(-78, 92), Pair(-13, 52),
        Pair(-26, 68), Pair(-22, 42), Pair(-26, 67), Pair(1, 61), Pair(-9, 56), Pair(-23, 67), Pair(-4, 56), Pair(22, 34),
        Pair(-20, 63), Pair(-6, 36), Pair(-11, 55), Pair(12, 46), Pair(6, 48), Pair(-10, 52), Pair(6, 47), Pair(-12, 58),
        Pair(-4, 57), Pair(-35, 52), Pair(4, 64), Pair(6, 65), Pair(-10, 64), Pair(3, 49), Pair(19, 52), Pair(-20, 61),
        Pair(-23, 44), Pair(0, 0), Pair(-7, 64), Pair(-11, 62), Pair(10, 46), Pair(-3, 58), Pair(-31, 78), Pair(9, 50),
        Pair(16, 29), Pair(-20, 19), Pair(-6, 52), Pair(-2, 61), Pair(2, 60), Pair(3, 43), Pair(-5, 49), Pair(-15, 54),
        Pair(-8, 46), Pair(-16, 15), Pair(-7, 58), Pair(-1, 52), Pair(-6, 56), Pair(-3, 47), Pair(-6, 55), Pair(-6, 55)
      },
      { // Piece 4
        Pair(-26, 119), Pair(10, 65), Pair(-15, 80), Pair(-35, 89), Pair(-63, 113), Pair(-26, 130), Pair(2, 78), Pair(-6, 106),
        Pair(-17, 69), Pair(-6, 84), Pair(-14, 78), Pair(14, 86), Pair(-8, 81), Pair(31, 79), Pair(42, 21), Pair(13, 75),
        Pair(-27, 95), Pair(-4, 76), Pair(7, 68), Pair(-2, 72), Pair(-14, 66), Pair(-50, 115), Pair(-1, 94), Pair(-15, 86),
        Pair(-4, 77), Pair(0, 70), Pair(-11, 74), Pair(-1, 91), Pair(-9, 91), Pair(13, 56), Pair(-1, 43), Pair(-2, 62),
        Pair(-23, 106), Pair(8, 53), Pair(2, 81), Pair(0, 88), Pair(-3, 75), Pair(4, 83), Pair(4, 74), Pair(-3, 72),
        Pair(-6, 40), Pair(0, 0), Pair(1, 91), Pair(-2, 108), Pair(-2, 97), Pair(3, 92), Pair(-4, 105), Pair(-4, 69),
        Pair(-24, 132), Pair(5, 52), Pair(2, 90), Pair(6, 84), Pair(7, 96), Pair(4, 104), Pair(4, 110), Pair(-3, 105),
        Pair(14, 45), Pair(1, 66), Pair(7, 103), Pair(4, 78), Pair(1, 104), Pair(4, 63), Pair(9, 65), Pair(23, 44)
      },
      { // Piece 5
        Pair(51, 64), Pair(18, 35), Pair(43, 80), Pair(-24, 1), Pair(34, -24), Pair(1, 9), Pair(-79, -41), Pair(-27, 26),
        Pair(101, 23), Pair(49, 65), Pair(-37, 55), Pair(162, 12), Pair(62, 56), Pair(15, 33), Pair(-14, 8), Pair(-133, 10),
        Pair(-80, 90), Pair(48, 35), Pair(29, 28), Pair(76, 22), Pair(-116, 25), Pair(-43, 38), Pair(80, -9), Pair(-52, 14),
        Pair(70, 44), Pair(101, 3), Pair(32, 37), Pair(21, 34), Pair(-77, 42), Pair(-45, 21), Pair(-16, 22), Pair(-57, 19),
        Pair(11, 4), Pair(10, 17), Pair(-6, 12), Pair(-14, 35), Pair(-15, 24), Pair(-3, 14), Pair(-4, 1), Pair(-54, 8),
        Pair(23, 11), Pair(0, 0), Pair(2, 23), Pair(-6, 22), Pair(6, 16), Pair(-13, 18), Pair(-27, 11), Pair(-62, 15),
        Pair(43, 9), Pair(38, -11), Pair(1, 7), Pair(10, 4), Pair(1, 12), Pair(-28, 15), Pair(-15, 11), Pair(-10, -4),
        Pair(59, -26), Pair(65, -28), Pair(33, 2), Pair(10, -5), Pair(10, -5), Pair(-19, 10), Pair(-8, -2), Pair(-9, -11)
      }
    }},
    {{ // Bucket 42
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(10, 11), Pair(-63, 34), Pair(-16, 13), Pair(15, -18), Pair(8, 16), Pair(23, -12), Pair(17, -23), Pair(-2, 5),
        Pair(-3, 11), Pair(-11, 16), Pair(-6, -4), Pair(-14, 18), Pair(-2, 5), Pair(-8, 10), Pair(-3, 2), Pair(2, 1),
        Pair(1, 11), Pair(-1, 13), Pair(-1, -4), Pair(-3, 12), Pair(7, 8), Pair(9, 6), Pair(4, 7), Pair(2, 8),
        Pair(0, 9), Pair(7, 10), Pair(-11, -15), Pair(10, 15), Pair(1, 9), Pair(4, 7), Pair(1, 12), Pair(0, 10),
        Pair(-4, 8), Pair(0, 11), Pair(-4, -5), Pair(-1, 18), Pair(-7, 9), Pair(3, 10), Pair(3, 11), Pair(2, 10),
        Pair(0, 9), Pair(12, 26), Pair(-8, -19), Pair(4, 28), Pair(-4, 12), Pair(-3, 12), Pair(1, 12), Pair(1, 13),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(0, -8), Pair(-139, 95), Pair(-12, 57), Pair(-22, 47), Pair(0, 33), Pair(-15, -13), Pair(-3, 24), Pair(18, -28),
        Pair(-30, 29), Pair(10, 36), Pair(-12, 45), Pair(-20, 49), Pair(-29, 47), Pair(13, 59), Pair(-18, 24), Pair(-16, 14),
        Pair(22, 34), Pair(-4, 38), Pair(-20, 41), Pair(-14, 60), Pair(2, 24), Pair(28, 35), Pair(-27, 50), Pair(-20, 35),
        Pair(-2, 31), Pair(5, 48), Pair(-6, 49), Pair(12, 43), Pair(-3, 49), Pair(-2, 46), Pair(2, 48), Pair(-4, 37),
        Pair(-17, 28), Pair(39, 41), Pair(8, 34), Pair(6, 44), Pair(-2, 46), Pair(7, 41), Pair(-5, 40), Pair(4, 44),
        Pair(3, 29), Pair(6, 50), Pair(0, 0), Pair(6, 46), Pair(12, 52), Pair(3, 45), Pair(10, 32), Pair(12, 27),
        Pair(-19, -43), Pair(23, 13), Pair(6, 78), Pair(9, 52), Pair(4, 31), Pair(5, 48), Pair(1, 60), Pair(10, 39),
        Pair(-28, 10), Pair(-4, 17), Pair(10, 25), Pair(-7, 37), Pair(19, 43), Pair(0, 40), Pair(3, 25), Pair(22, 65)
      },
      { // Piece 2
        Pair(62, 11), Pair(-40, 17), Pair(19, 3), Pair(49, -14), Pair(33, 23), Pair(23, -8), Pair(60, -1), Pair(-85, 44),
        Pair(-15, 33), Pair(-7, 41), Pair(27, -3), Pair(50, 15), Pair(-5, 11), Pair(11, 23), Pair(-60, -20), Pair(23, 5),
        Pair(17, 28), Pair(24, 2), Pair(11, 28), Pair(10, 2), Pair(6, 27), Pair(13, 0), Pair(48, -4), Pair(12, 7),
        Pair(-17, -3), Pair(16, 16), Pair(-8, 3), Pair(22, 28), Pair(10, 5), Pair(6, 18), Pair(2, 8), Pair(19, 33),
        Pair(12, 34), Pair(-2, 5), Pair(9, 25), Pair(33, 9), Pair(5, 39), Pair(10, 21), Pair(16, 29), Pair(3, 22),
        Pair(0, 5), Pair(4, 37), Pair(0, 0), Pair(14, 25), Pair(6, 25), Pair(17, 31), Pair(15, 18), Pair(8, 41),
        Pair(29, -24), Pair(-14, -53), Pair(18, 47), Pair(-2, 9), Pair(11, 42), Pair(1, 29), Pair(11, 39), Pair(8, 52),
        Pair(-45, -70), Pair(26, -10), Pair(0, 15), Pair(25, 14), Pair(-11, -4), Pair(4, 50), Pair(4, 30), Pair(2, 62)
      },
      { // Piece 3
        Pair(-22, 49), Pair(-32, 56), Pair(6, 33), Pair(-9, 50), Pair(-27, 48), Pair(-27, 68), Pair(-27, 57), Pair(44, 24),
        Pair(-6, 58), Pair(9, 40), Pair(-36, 43), Pair(-11, 54), Pair(27, 40), Pair(-17, 54), Pair(27, 47), Pair(25, 26),
        Pair(-9, 61), Pair(-15, 52), Pair(26, 27), Pair(-9, 51), Pair(13, 41), Pair(-50, 59), Pair(18, 48), Pair(14, 42),
        Pair(1, 52), Pair(5, 43), Pair(1, 46), Pair(-17, 57), Pair(-3, 44), Pair(-13, 57), Pair(-9, 52), Pair(30, 35),
        Pair(13, 52), Pair(11, 63), Pair(13, 30), Pair(-12, 63), Pair(2, 58), Pair(2, 41), Pair(-24, 60), Pair(-15, 53),
        Pair(0, 34), Pair(-13, 43), Pair(0, 0), Pair(-6, 47), Pair(2, 51), Pair(-16, 46), Pair(-1, 57), Pair(20, 26),
        Pair(-25, 66), Pair(1, 51), Pair(-8, 5), Pair(-1, 51), Pair(11, 56), Pair(11, 39), Pair(3, 33), Pair(-4, 51),
        Pair(-1, 47), Pair(-4, 49), Pair(-9, 12), Pair(-3, 51), Pair(5, 46), Pair(0, 45), Pair(1, 40), Pair(9, 44)
      },
      { // Piece 4
        Pair(22, 48), Pair(-41, 111), Pair(-27, 75), Pair(-43, 81), Pair(-63, 105), Pair(58, 22), Pair(13, 16), Pair(-20, 62),
        Pair(-19, 69), Pair(7, 47), Pair(-29, 68), Pair(7, 84), Pair(-5, 47), Pair(-3, 78), Pair(-15, 69), Pair(-13, 57),
        Pair(-8, 73), Pair(-21, 75), Pair(-14, 79), Pair(-10, 61), Pair(-13, 84), Pair(-28, 80), Pair(-9, 62), Pair(-20, 118),
        Pair(-28, 94), Pair(10, 72), Pair(17, 2), Pair(-3, 50), Pair(-13, 84), Pair(7, 47), Pair(-16, 88), Pair(-4, 75),
        Pair(3, 58), Pair(-10, 68), Pair(-10, 62), Pair(0, 73), Pair(-17, 90), Pair(-19, 91), Pair(4, 80), Pair(-5, 75),
        Pair(10, 16), Pair(10, 11), Pair(0, 0), Pair(-2, 69), Pair(7, 60), Pair(5, 79), Pair(0, 82), Pair(-15, 111),
        Pair(5, 73), Pair(6, 25), Pair(3, 52), Pair(3, 67), Pair(8, 70), Pair(2, 84), Pair(9, 69), Pair(-15, 49),
        Pair(2, 42), Pair(0, 84), Pair(9, 56), Pair(3, 75), Pair(10, 55), Pair(16, 55), Pair(30, 72), Pair(30, -4)
      },
      { // Piece 5
        Pair(-59, -82), Pair(38, 126), Pair(-69, 73), Pair(-171, 0), Pair(44, 95), Pair(8, 34), Pair(-28, -86), Pair(22, -80),
        Pair(85, 7), Pair(40, 46), Pair(81, 15), Pair(-30, 54), Pair(-20, 30), Pair(-5, -13), Pair(34, 1), Pair(73, -14),
        Pair(-107, 66), Pair(4, 32), Pair(-133, 40), Pair(-41, 61), Pair(55, 5), Pair(-57, 22), Pair(97, -36), Pair(18, -13),
        Pair(98, 59), Pair(-86, 57), Pair(2, 28), Pair(29, 27), Pair(20, 17), Pair(-70, 23), Pair(-41, 14), Pair(-51, 0),
        Pair(44, 43), Pair(-72, -1), Pair(9, -1), Pair(-3, -1), Pair(-38, 16), Pair(-49, 15), Pair(26, -11), Pair(-49, 2),
        Pair(-30, 35), Pair(1, 16), Pair(0, 0), Pair(16, 12), Pair(-3, 3), Pair(23, -5), Pair(-16, -1), Pair(-28, 6),
        Pair(12, 5), Pair(1, -5), Pair(-23, 9), Pair(-24, 8), Pair(0, -3), Pair(-4, -9), Pair(-2, -10), Pair(-2, -11),
        Pair(26, -17), Pair(-14, 6), Pair(-17, -4), Pair(-20, 3), Pair(6, -8), Pair(-22, -1), Pair(0, -14), Pair(1, -26)
      }
    }},
    {{ // Bucket 43
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(8, 25), Pair(-7, 4), Pair(-48, 14), Pair(-35, 32), Pair(-11, 3), Pair(32, 1), Pair(24, -10), Pair(17, 3),
        Pair(-4, 7), Pair(-8, 11), Pair(-9, 12), Pair(3, -1), Pair(-6, 1), Pair(0, 11), Pair(-8, 7), Pair(-4, -3),
        Pair(-3, 7), Pair(3, 9), Pair(0, 15), Pair(7, 8), Pair(5, 11), Pair(9, 7), Pair(3, 12), Pair(-1, 9),
        Pair(-2, 10), Pair(0, 10), Pair(4, 18), Pair(3, -2), Pair(11, 11), Pair(3, 8), Pair(3, 7), Pair(-2, 7),
        Pair(-4, 9), Pair(-4, 9), Pair(-2, 18), Pair(2, -13), Pair(1, 16), Pair(-5, 5), Pair(2, 11), Pair(-3, 10),
        Pair(-1, 10), Pair(-5, 6), Pair(7, 30), Pair(4, -25), Pair(11, 34), Pair(-7, 12), Pair(-2, 7), Pair(1, 15),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(57, -27), Pair(2, 51), Pair(-20, 44), Pair(-93, 47), Pair(52, 23), Pair(-61, 91), Pair(-51, 102), Pair(-54, 42),
        Pair(-16, 7), Pair(0, 30), Pair(-34, 43), Pair(28, 21), Pair(-69, 41), Pair(-18, 47), Pair(-8, 52), Pair(1, 15),
        Pair(-39, 35), Pair(-14, 42), Pair(22, 34), Pair(-26, 48), Pair(-3, 61), Pair(-44, 77), Pair(-8, 33), Pair(-4, 18),
        Pair(4, 32), Pair(-14, 63), Pair(-3, 35), Pair(-22, 52), Pair(-6, 48), Pair(-4, 49), Pair(-22, 51), Pair(-32, 52),
        Pair(-4, 33), Pair(-4, 29), Pair(-1, 41), Pair(2, 32), Pair(2, 51), Pair(-8, 42), Pair(-15, 41), Pair(-1, 36),
        Pair(-8, 29), Pair(4, 29), Pair(-5, 40), Pair(0, 0), Pair(0, 39), Pair(4, 36), Pair(-15, 63), Pair(-4, 59),
        Pair(-21, 8), Pair(-8, 7), Pair(1, 43), Pair(1, 63), Pair(4, 51), Pair(-12, 36), Pair(-19, 49), Pair(3, 15),
        Pair(42, 50), Pair(1, 1), Pair(-21, 32), Pair(-8, 31), Pair(1, 23), Pair(-14, 46), Pair(-1, 47), Pair(-10, 40)
      },
      { // Piece 2
        Pair(-43, 17), Pair(1, 12), Pair(-27, 35), Pair(-36, 20), Pair(84, -15), Pair(-2, 0), Pair(25, -11), Pair(-99, 44),
        Pair(13, 18), Pair(-8, 21), Pair(0, 53), Pair(27, 1), Pair(-17, 16), Pair(-10, -5), Pair(20, 10), Pair(-1, -26),
        Pair(-9, -23), Pair(7, 32), Pair(-19, 20), Pair(-1, 21), Pair(12, 12), Pair(-18, 30), Pair(31, -29), Pair(-6, 39),
        Pair(7, 24), Pair(-14, 14), Pair(-5, 29), Pair(-7, 17), Pair(-1, 25), Pair(24, -16), Pair(-5, 22), Pair(0, 11),
        Pair(-15, 3), Pair(15, 14), Pair(-17, 12), Pair(-9, 24), Pair(30, 29), Pair(-3, 35), Pair(-4, 10), Pair(6, 4),
        Pair(2, 17), Pair(-9, 26), Pair(3, 21), Pair(0, 0), Pair(3, 19), Pair(-3, 15), Pair(-2, 37), Pair(-7, 10),
        Pair(0, 45), Pair(-2, 31), Pair(-13, -14), Pair(10, 42), Pair(-6, -11), Pair(-1, 32), Pair(-6, 19), Pair(1, 50),
        Pair(-3, 18), Pair(-18, -37), Pair(-1, 23), Pair(2, -1), Pair(-10, 22), Pair(-13, -13), Pair(28, 2), Pair(-9, 12)
      },
      { // Piece 3
        Pair(-30, 52), Pair(-29, 34), Pair(-4, 46), Pair(48, 11), Pair(25, 15), Pair(-52, 69), Pair(-15, 46), Pair(8, 30),
        Pair(-14, 43), Pair(-13, 55), Pair(-23, 56), Pair(5, 23), Pair(-13, 36), Pair(29, 22), Pair(-46, 67), Pair(11, 34),
        Pair(-10, 45), Pair(-2, 46), Pair(-13, 51), Pair(1, 31), Pair(-36, 72), Pair(15, 32), Pair(-13, 63), Pair(-10, 44),
        Pair(1, 50), Pair(-11, 47), Pair(-7, 39), Pair(30, 38), Pair(-14, 47), Pair(0, 28), Pair(1, 49), Pair(28, 25),
        Pair(3, 47), Pair(-2, 44), Pair(7, 66), Pair(15, 26), Pair(18, 30), Pair(11, 40), Pair(4, 49), Pair(7, 24),
        Pair(2, 37), Pair(-16, 32), Pair(-7, 37), Pair(0, 0), Pair(-4, 34), Pair(7, 12), Pair(-20, 45), Pair(-19, 30),
        Pair(-14, 43), Pair(-7, 47), Pair(-13, 50), Pair(-11, 12), Pair(-3, 40), Pair(0, 27), Pair(4, 13), Pair(-13, 30),
        Pair(-2, 31), Pair(2, 37), Pair(-6, 35), Pair(2, -1), Pair(-6, 32), Pair(-6, 41), Pair(-6, 41), Pair(-3, 46)
      },
      { // Piece 4
        Pair(-31, 69), Pair(-32, 76), Pair(-22, 60), Pair(-33, 77), Pair(-46, 82), Pair(-1, 54), Pair(3, 1), Pair(-8, 50),
        Pair(-16, 79), Pair(-7, 56), Pair(-15, 27), Pair(-46, 102), Pair(-44, 78), Pair(-28, 87), Pair(-7, 62), Pair(0, 64),
        Pair(-34, 83), Pair(-14, 63), Pair(0, 64), Pair(-15, 69), Pair(-4, 30), Pair(-7, 42), Pair(-2, 94), Pair(-6, 53),
        Pair(-7, 56), Pair(-6, 78), Pair(-3, 53), Pair(6, 40), Pair(-11, 87), Pair(5, 49), Pair(-11, 30), Pair(-1, 51),
        Pair(4, 39), Pair(10, 48), Pair(7, 32), Pair(-3, 98), Pair(-4, 65), Pair(-10, 86), Pair(-6, 68), Pair(4, 60),
        Pair(6, 16), Pair(3, 38), Pair(-5, 56), Pair(0, 0), Pair(-5, 61), Pair(6, 56), Pair(-5, 84), Pair(-1, 62),
        Pair(7, 29), Pair(8, 41), Pair(1, 57), Pair(6, 33), Pair(-1, 69), Pair(14, 55), Pair(2, 78), Pair(7, 138),
        Pair(8, 43), Pair(1, 17), Pair(10, 53), Pair(5, 39), Pair(4, 67), Pair(7, 43), Pair(8, 108), Pair(-37, 70)
      },
      { // Piece 5
        Pair(-6, -3), Pair(45, 174), Pair(2, -5), Pair(41, 78), Pair(24, -23), Pair(18, -23), Pair(7, -57), Pair(5, 1),
        Pair(15, 87), Pair(-103, 103), Pair(20, 43), Pair(-43, 95), Pair(-29, 74), Pair(35, 11), Pair(95, -20), Pair(-88, 23),
        Pair(-80, 27), Pair(63, 36), Pair(-47, 22), Pair(-14, 21), Pair(86, -8), Pair(88, -17), Pair(-64, 23), Pair(-36, -21),
        Pair(-139, 49), Pair(99, -3), Pair(-110, 45), Pair(-39, 14), Pair(29, 18), Pair(33, -7), Pair(-78, 8), Pair(-24, -2),
        Pair(104, 11), Pair(-17, 17), Pair(-57, -12), Pair(4, 6), Pair(1, -20), Pair(-22, -3), Pair(24, -14), Pair(-44, 2),
        Pair(25, -45), Pair(-13, 13), Pair(-6, 16), Pair(0, 0), Pair(-35, 11), Pair(2, -15), Pair(0, -14), Pair(-21, -5),
        Pair(-2, -1), Pair(-9, -8), Pair(-33, -5), Pair(-87, 33), Pair(-47, -5), Pair(-6, -10), Pair(-6, -16), Pair(-3, -12),
        Pair(10, -57), Pair(-17, -4), Pair(-37, 6), Pair(-76, 12), Pair(-18, -29), Pair(-6, -15), Pair(-3, -18), Pair(3, -22)
      }
    }},
    {{ // Bucket 44
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-10, 14), Pair(-1, 9), Pair(-15, 8), Pair(-9, 12), Pair(-7, 4), Pair(-3, 25), Pair(-15, -3), Pair(-2, 6),
        Pair(-3, 10), Pair(-5, 8), Pair(2, 8), Pair(-5, 19), Pair(-5, 8), Pair(2, 12), Pair(-2, 5), Pair(-3, 3),
        Pair(-1, 8), Pair(2, 6), Pair(1, 13), Pair(1, 15), Pair(5, 7), Pair(0, 13), Pair(3, 10), Pair(2, 3),
        Pair(-1, 16), Pair(1, 13), Pair(0, 13), Pair(13, 18), Pair(-1, -3), Pair(15, 6), Pair(0, 12), Pair(-2, 5),
        Pair(0, 11), Pair(1, 14), Pair(-7, 7), Pair(1, 20), Pair(2, -9), Pair(12, 11), Pair(-2, 5), Pair(6, 10),
        Pair(0, 16), Pair(-1, 13), Pair(-5, 10), Pair(15, 29), Pair(2, -9), Pair(17, 32), Pair(3, 9), Pair(6, 12),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(3, 28), Pair(88, 24), Pair(-41, 27), Pair(40, 25), Pair(-16, 42), Pair(-20, 33), Pair(172, -42), Pair(21, 23),
        Pair(13, 25), Pair(9, 48), Pair(-12, 35), Pair(-16, 44), Pair(8, 38), Pair(-24, 40), Pair(-18, 39), Pair(-5, 3),
        Pair(15, 11), Pair(-5, 36), Pair(-11, 35), Pair(-14, 42), Pair(-5, 39), Pair(-10, 29), Pair(-33, 36), Pair(-30, 50),
        Pair(-2, 20), Pair(-1, 46), Pair(2, 46), Pair(-9, 38), Pair(-20, 47), Pair(-17, 40), Pair(-8, 24), Pair(-15, 28),
        Pair(-1, 44), Pair(3, 41), Pair(0, 33), Pair(4, 40), Pair(-8, 34), Pair(-2, 31), Pair(-26, 35), Pair(-15, 28),
        Pair(-7, 16), Pair(4, 37), Pair(0, 40), Pair(0, 40), Pair(0, 0), Pair(-5, 40), Pair(0, 34), Pair(-5, 30),
        Pair(1, 32), Pair(4, 27), Pair(-16, 34), Pair(1, 49), Pair(1, 71), Pair(11, 35), Pair(-22, 19), Pair(-4, 26),
        Pair(12, 22), Pair(2, 38), Pair(10, 43), Pair(-17, 35), Pair(-6, 43), Pair(-12, 43), Pair(-10, 37), Pair(4, 17)
      },
      { // Piece 2
        Pair(-21, 43), Pair(26, -25), Pair(13, 33), Pair(30, -10), Pair(23, -5), Pair(30, -9), Pair(16, 13), Pair(-47, 5),
        Pair(-21, 12), Pair(-13, 17), Pair(-16, 10), Pair(32, -8), Pair(4, -1), Pair(15, 4), Pair(-44, 4), Pair(-4, 33),
        Pair(13, 19), Pair(6, 4), Pair(27, 4), Pair(-4, 5), Pair(-4, 4), Pair(-24, 14), Pair(17, 19), Pair(-56, 11),
        Pair(-5, 10), Pair(7, 8), Pair(-7, 5), Pair(6, 10), Pair(-19, 9), Pair(12, 9), Pair(-23, 0), Pair(9, 9),
        Pair(3, 18), Pair(-9, 17), Pair(0, 12), Pair(22, 4), Pair(-3, 16), Pair(-21, -4), Pair(10, 23), Pair(-9, -8),
        Pair(-17, 16), Pair(5, 30), Pair(-14, 20), Pair(2, 25), Pair(0, 0), Pair(5, 25), Pair(-21, 20), Pair(-5, 40),
        Pair(4, 17), Pair(-20, 25), Pair(5, 12), Pair(-23, -3), Pair(9, 47), Pair(-25, -9), Pair(0, 36), Pair(-15, 36),
        Pair(-13, 18), Pair(4, 38), Pair(-30, -16), Pair(15, 19), Pair(-9, 14), Pair(-8, 23), Pair(-26, -25), Pair(-11, 5)
      },
      { // Piece 3
        Pair(-30, 49), Pair(11, 38), Pair(4, 39), Pair(1, 37), Pair(-36, 46), Pair(-29, 37), Pair(21, 42), Pair(38, 29),
        Pair(-20, 52), Pair(8, 36), Pair(-2, 32), Pair(12, 32), Pair(-4, 24), Pair(0, 21), Pair(9, 45), Pair(-28, 50),
        Pair(-18, 55), Pair(0, 40), Pair(-5, 48), Pair(-17, 40), Pair(-5, 38), Pair(-59, 59), Pair(26, 20), Pair(35, 35),
        Pair(-7, 49), Pair(11, 39), Pair(13, 42), Pair(-7, 37), Pair(22, 7), Pair(-9, 38), Pair(-8, 35), Pair(5, 36),
        Pair(-2, 52), Pair(14, 37), Pair(12, 34), Pair(11, 37), Pair(7, 8), Pair(0, 42), Pair(-2, 51), Pair(-11, 45),
        Pair(13, 23), Pair(2, 28), Pair(7, 20), Pair(-13, 35), Pair(0, 0), Pair(-15, 15), Pair(-19, 26), Pair(1, 18),
        Pair(-8, 41), Pair(1, 41), Pair(5, 37), Pair(7, 26), Pair(-11, 12), Pair(-7, 30), Pair(-17, 37), Pair(-4, 35),
        Pair(2, 32), Pair(1, 38), Pair(1, 36), Pair(-1, 35), Pair(-4, -10), Pair(-11, 34), Pair(-7, 34), Pair(2, 30)
      },
      { // Piece 4
        Pair(23, 51), Pair(-52, 91), Pair(-59, 117), Pair(-23, 64), Pair(0, 71), Pair(42, 0), Pair(-88, 135), Pair(-73, 130),
        Pair(-21, 71), Pair(-16, 83), Pair(-15, 89), Pair(14, 53), Pair(23, 19), Pair(11, 56), Pair(-29, 60), Pair(-23, 80),
        Pair(-4, 74), Pair(15, 38), Pair(1, 69), Pair(-31, 112), Pair(-24, 40), Pair(-37, 106), Pair(-33, 104), Pair(-36, 76),
        Pair(-12, 84), Pair(-6, 65), Pair(-1, 44), Pair(-16, 84), Pair(8, 40), Pair(-10, 78), Pair(-20, 63), Pair(-11, 46),
        Pair(5, 78), Pair(3, 69), Pair(-11, 75), Pair(0, 81), Pair(-2, 55), Pair(-21, 76), Pair(-14, 71), Pair(-27, 86),
        Pair(0, 75), Pair(0, 53), Pair(5, 45), Pair(3, 57), Pair(0, 0), Pair(-7, 64), Pair(-13, 65), Pair(-32, 77),
        Pair(1, 74), Pair(12, 51), Pair(4, 69), Pair(-2, 59), Pair(2, 55), Pair(4, 51), Pair(11, 52), Pair(3, 88),
        Pair(9, 48), Pair(6, 66), Pair(6, 34), Pair(-1, 72), Pair(9, 32), Pair(1, 47), Pair(-3, 101), Pair(-11, 70)
      },
      { // Piece 5
        Pair(48, 18), Pair(-40, -39), Pair(-67, 43), Pair(10, 84), Pair(-71, -31), Pair(-33, 69), Pair(-46, 3), Pair(23, -43),
        Pair(0, -43), Pair(-94, -10), Pair(-212, 28), Pair(-47, 60), Pair(76, 32), Pair(14, 27), Pair(43, 3), Pair(6, 51),
        Pair(-36, -7), Pair(32, 26), Pair(-35, 41), Pair(100, 14), Pair(-7, 55), Pair(-3, 35), Pair(-99, 30), Pair(97, 6),
        Pair(26, 4), Pair(-117, 2), Pair(-2, 2), Pair(19, 17), Pair(-36, 45), Pair(21, 22), Pair(-19, 9), Pair(-40, 8),
        Pair(58, 2), Pair(-43, 10), Pair(25, 5), Pair(27, -13), Pair(2, 6), Pair(15, -26), Pair(24, 2), Pair(-7, 8),
        Pair(-67, 22), Pair(-32, 16), Pair(-38, 19), Pair(-56, 22), Pair(0, 0), Pair(-36, 3), Pair(4, -2), Pair(23, -16),
        Pair(13, -21), Pair(2, -9), Pair(-18, 4), Pair(-42, 13), Pair(-50, 20), Pair(-14, -5), Pair(3, -16), Pair(9, -14),
        Pair(-12, -8), Pair(-5, -16), Pair(4, -20), Pair(-32, 5), Pair(-31, -2), Pair(-39, 0), Pair(6, -17), Pair(10, -29)
      }
    }},
    {{ // Bucket 45
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(31, 0), Pair(5, 5), Pair(5, 1), Pair(-6, 14), Pair(-11, 14), Pair(-11, 15), Pair(35, 12), Pair(-36, 7),
        Pair(14, 8), Pair(11, 7), Pair(8, 4), Pair(2, 8), Pair(2, 12), Pair(-16, 9), Pair(-3, 10), Pair(-2, 5),
        Pair(4, 10), Pair(3, 11), Pair(5, 7), Pair(2, 11), Pair(1, 12), Pair(6, 4), Pair(7, 9), Pair(4, 5),
        Pair(0, 12), Pair(6, 11), Pair(1, 11), Pair(4, 11), Pair(18, 11), Pair(0, -2), Pair(22, 2), Pair(6, 3),
        Pair(3, 13), Pair(5, 13), Pair(2, 10), Pair(-5, 4), Pair(12, 12), Pair(1, 0), Pair(16, 4), Pair(0, 5),
        Pair(4, 14), Pair(3, 12), Pair(0, 11), Pair(-3, 13), Pair(18, 23), Pair(6, -5), Pair(18, 18), Pair(0, 8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-6, -21), Pair(42, -37), Pair(-31, 53), Pair(80, 7), Pair(22, 62), Pair(45, 19), Pair(8, 53), Pair(-74, 17),
        Pair(-21, 28), Pair(-13, 39), Pair(-14, 43), Pair(13, 38), Pair(-1, 33), Pair(-4, 26), Pair(34, 19), Pair(0, -6),
        Pair(-40, 37), Pair(20, 28), Pair(34, 32), Pair(0, 46), Pair(42, 24), Pair(23, 39), Pair(12, 51), Pair(-24, 37),
        Pair(24, 24), Pair(16, 42), Pair(13, 34), Pair(12, 41), Pair(31, 29), Pair(12, 43), Pair(7, 35), Pair(-6, 43),
        Pair(9, 24), Pair(12, 40), Pair(15, 41), Pair(22, 38), Pair(24, 39), Pair(8, 44), Pair(7, 40), Pair(-41, 41),
        Pair(11, 22), Pair(20, 38), Pair(18, 42), Pair(12, 37), Pair(33, 28), Pair(0, 0), Pair(11, 38), Pair(1, 49),
        Pair(12, 34), Pair(5, 33), Pair(8, 42), Pair(9, 32), Pair(11, 40), Pair(10, 60), Pair(3, 47), Pair(-13, 5),
        Pair(-10, 28), Pair(2, 52), Pair(28, 51), Pair(0, 45), Pair(4, 41), Pair(-9, 25), Pair(-4, 15), Pair(20, -22)
      },
      { // Piece 2
        Pair(41, 1), Pair(-3, 17), Pair(-84, 18), Pair(58, -7), Pair(54, -23), Pair(44, 29), Pair(-15, 1), Pair(-34, 16),
        Pair(-4, 12), Pair(-18, 10), Pair(64, 5), Pair(58, -24), Pair(37, 5), Pair(3, 4), Pair(32, -1), Pair(-5, 1),
        Pair(27, -15), Pair(38, 17), Pair(34, -4), Pair(39, 11), Pair(22, 12), Pair(-10, 9), Pair(28, 5), Pair(13, 16),
        Pair(36, 19), Pair(22, -2), Pair(28, 21), Pair(7, 14), Pair(41, 26), Pair(21, -2), Pair(23, 23), Pair(-22, 7),
        Pair(9, 3), Pair(28, 18), Pair(17, 8), Pair(25, 14), Pair(35, 27), Pair(25, 19), Pair(8, 38), Pair(6, 10),
        Pair(11, 42), Pair(-3, 23), Pair(15, 36), Pair(15, 12), Pair(23, 31), Pair(0, 0), Pair(5, 52), Pair(5, 2),
        Pair(17, -12), Pair(14, 32), Pair(10, 17), Pair(16, 34), Pair(13, 12), Pair(27, 37), Pair(-16, -13), Pair(15, 11),
        Pair(-7, 56), Pair(1, 21), Pair(11, 34), Pair(-24, 18), Pair(35, 20), Pair(3, 3), Pair(-8, 28), Pair(-13, -90)
      },
      { // Piece 3
        Pair(44, 26), Pair(55, 18), Pair(14, 32), Pair(92, 13), Pair(12, 40), Pair(30, 22), Pair(66, 23), Pair(48, 26),
        Pair(28, 30), Pair(21, 34), Pair(37, 22), Pair(14, 29), Pair(15, 34), Pair(56, -13), Pair(4, 37), Pair(19, 28),
        Pair(28, 41), Pair(44, 20), Pair(25, 34), Pair(27, 30), Pair(14, 36), Pair(41, 24), Pair(14, 38), Pair(26, 48),
        Pair(26, 42), Pair(2, 43), Pair(14, 37), Pair(36, 27), Pair(27, 30), Pair(26, 24), Pair(2, 41), Pair(0, 60),
        Pair(15, 49), Pair(32, 28), Pair(8, 33), Pair(16, 40), Pair(36, 41), Pair(76, 6), Pair(23, 38), Pair(20, 38),
        Pair(16, 24), Pair(11, 40), Pair(33, 21), Pair(25, 22), Pair(2, 46), Pair(0, 0), Pair(6, 4), Pair(28, 6),
        Pair(-16, 47), Pair(12, 31), Pair(9, 33), Pair(21, 39), Pair(16, 31), Pair(12, 14), Pair(-3, 42), Pair(19, 36),
        Pair(15, 39), Pair(16, 36), Pair(17, 37), Pair(16, 37), Pair(14, 33), Pair(13, 9), Pair(11, 24), Pair(20, 32)
      },
      { // Piece 4
        Pair(-4, 57), Pair(19, 51), Pair(44, 53), Pair(-15, 78), Pair(-2, 92), Pair(14, 75), Pair(39, 35), Pair(9, 50),
        Pair(-17, 79), Pair(-19, 74), Pair(-56, 125), Pair(16, 42), Pair(-34, 104), Pair(-9, 23), Pair(-4, 88), Pair(-5, 64),
        Pair(-12, 68), Pair(2, 74), Pair(10, 56), Pair(-15, 75), Pair(2, 85), Pair(-15, 78), Pair(11, 29), Pair(-11, 62),
        Pair(-1, 81), Pair(-3, 93), Pair(-30, 86), Pair(10, 54), Pair(-11, 91), Pair(-1, 53), Pair(11, 54), Pair(-23, 79),
        Pair(4, 78), Pair(3, 89), Pair(8, 71), Pair(-4, 91), Pair(-4, 69), Pair(-18, 76), Pair(2, 56), Pair(-11, 60),
        Pair(-11, 84), Pair(7, 95), Pair(1, 87), Pair(7, 59), Pair(6, 63), Pair(0, 0), Pair(-13, 72), Pair(-13, 46),
        Pair(0, 42), Pair(11, 65), Pair(9, 67), Pair(4, 71), Pair(12, 47), Pair(7, 42), Pair(17, 16), Pair(-28, 54),
        Pair(15, 66), Pair(18, 58), Pair(6, 70), Pair(11, 48), Pair(3, 73), Pair(13, 16), Pair(29, 69), Pair(-2, 36)
      },
      { // Piece 5
        Pair(-86, -31), Pair(-26, 8), Pair(143, 26), Pair(43, 69), Pair(82, 30), Pair(83, 28), Pair(-60, 8), Pair(66, -29),
        Pair(-23, 0), Pair(-70, 7), Pair(55, 21), Pair(137, -10), Pair(13, 45), Pair(101, 45), Pair(1, 59), Pair(-176, 1),
        Pair(-4, 3), Pair(-38, 14), Pair(-76, 20), Pair(-127, 40), Pair(135, 36), Pair(61, 35), Pair(-62, 25), Pair(75, -21),
        Pair(-40, -4), Pair(-39, 11), Pair(-92, 43), Pair(-63, 29), Pair(-59, 25), Pair(14, 21), Pair(6, 13), Pair(-12, -12),
        Pair(-118, 19), Pair(-57, 14), Pair(-68, 28), Pair(-46, 17), Pair(-59, -1), Pair(-13, -1), Pair(-11, -19), Pair(36, -8),
        Pair(-37, -8), Pair(-44, -1), Pair(-53, 16), Pair(-8, 7), Pair(15, -5), Pair(0, 0), Pair(10, -12), Pair(12, 2),
        Pair(-1, -6), Pair(-7, -11), Pair(22, -8), Pair(3, -4), Pair(-23, 3), Pair(-62, 20), Pair(-3, -6), Pair(20, -10),
        Pair(18, -51), Pair(-5, -6), Pair(0, -12), Pair(4, -16), Pair(-13, -5), Pair(-31, 8), Pair(0, -5), Pair(30, -20)
      }
    }},
    {{ // Bucket 46
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-4, 10), Pair(6, 7), Pair(-10, 13), Pair(7, 3), Pair(6, -3), Pair(24, 18), Pair(2, -20), Pair(-6, 16),
        Pair(2, 10), Pair(3, 14), Pair(8, 6), Pair(-1, 11), Pair(-9, 8), Pair(-6, 11), Pair(5, -12), Pair(7, 11),
        Pair(2, 10), Pair(3, 8), Pair(2, 8), Pair(0, 7), Pair(2, 11), Pair(-8, 10), Pair(8, -1), Pair(8, 6),
        Pair(0, 13), Pair(6, 14), Pair(5, 11), Pair(2, 8), Pair(7, 12), Pair(15, 7), Pair(5, -9), Pair(10, -1),
        Pair(-1, 18), Pair(3, 16), Pair(3, 10), Pair(2, 11), Pair(1, 9), Pair(16, 4), Pair(0, 3), Pair(3, 5),
        Pair(-2, 16), Pair(2, 17), Pair(0, 12), Pair(3, 16), Pair(1, 12), Pair(17, 21), Pair(-10, -3), Pair(5, 18),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(37, 6), Pair(28, 28), Pair(54, 28), Pair(48, 27), Pair(-39, 48), Pair(45, 29), Pair(23, 65), Pair(94, -50),
        Pair(7, 11), Pair(10, 42), Pair(30, 37), Pair(2, 52), Pair(15, 40), Pair(24, 18), Pair(-43, 35), Pair(11, 22),
        Pair(-27, 36), Pair(7, 48), Pair(7, 36), Pair(3, 52), Pair(-2, 41), Pair(31, 20), Pair(-7, 35), Pair(8, 27),
        Pair(-1, 36), Pair(9, 42), Pair(10, 42), Pair(10, 46), Pair(5, 40), Pair(8, 39), Pair(11, 34), Pair(-26, 37),
        Pair(-5, 46), Pair(0, 37), Pair(6, 45), Pair(5, 39), Pair(11, 37), Pair(10, 29), Pair(2, 33), Pair(3, 18),
        Pair(0, 26), Pair(5, 32), Pair(1, 43), Pair(5, 43), Pair(7, 43), Pair(5, 40), Pair(0, 0), Pair(-13, 52),
        Pair(-29, 48), Pair(-20, 48), Pair(-3, 49), Pair(-2, 51), Pair(-10, 43), Pair(13, 36), Pair(-1, 59), Pair(-10, 33),
        Pair(-58, 64), Pair(-7, 50), Pair(-12, 44), Pair(-7, 43), Pair(-14, 48), Pair(-4, 33), Pair(9, 18), Pair(-37, 38)
      },
      { // Piece 2
        Pair(19, 7), Pair(-1, 6), Pair(-4, 16), Pair(49, 3), Pair(38, 14), Pair(20, 13), Pair(48, 31), Pair(41, -16),
        Pair(19, 6), Pair(-1, 26), Pair(-23, 9), Pair(55, 8), Pair(24, 0), Pair(42, 9), Pair(-12, 4), Pair(15, 30),
        Pair(8, 13), Pair(27, 7), Pair(33, 12), Pair(-4, 18), Pair(1, 24), Pair(-2, 17), Pair(-4, 31), Pair(-4, 8),
        Pair(-19, 22), Pair(12, 28), Pair(17, 8), Pair(29, 21), Pair(-9, 22), Pair(21, 26), Pair(5, 6), Pair(3, 33),
        Pair(-11, 24), Pair(2, 17), Pair(14, 25), Pair(7, 22), Pair(19, 31), Pair(-7, 17), Pair(22, 14), Pair(-21, -43),
        Pair(5, 19), Pair(12, 33), Pair(1, 26), Pair(9, 34), Pair(0, 31), Pair(12, 32), Pair(0, 0), Pair(7, 38),
        Pair(11, 14), Pair(-5, 28), Pair(1, 52), Pair(-2, 29), Pair(6, 43), Pair(4, 4), Pair(19, 49), Pair(-54, -48),
        Pair(12, 20), Pair(-9, 47), Pair(-6, 20), Pair(-8, 47), Pair(-16, 22), Pair(9, 21), Pair(-6, 23), Pair(15, -4)
      },
      { // Piece 3
        Pair(8, 47), Pair(29, 44), Pair(37, 44), Pair(55, 32), Pair(12, 49), Pair(19, 51), Pair(58, 28), Pair(51, 40),
        Pair(18, 50), Pair(11, 55), Pair(39, 38), Pair(42, 39), Pair(55, 29), Pair(-8, 44), Pair(73, 15), Pair(-13, 51),
        Pair(0, 57), Pair(15, 45), Pair(1, 52), Pair(26, 43), Pair(6, 51), Pair(9, 46), Pair(30, 26), Pair(0, 52),
        Pair(15, 50), Pair(28, 38), Pair(12, 54), Pair(20, 48), Pair(34, 42), Pair(10, 49), Pair(41, 20), Pair(-30, 63),
        Pair(10, 45), Pair(27, 44), Pair(12, 52), Pair(16, 44), Pair(12, 46), Pair(23, 57), Pair(20, 19), Pair(1, 56),
        Pair(17, 45), Pair(1, 45), Pair(11, 45), Pair(10, 40), Pair(13, 51), Pair(0, 55), Pair(0, 0), Pair(-25, 34),
        Pair(7, 44), Pair(15, 42), Pair(12, 50), Pair(4, 60), Pair(14, 50), Pair(-1, 52), Pair(6, 1), Pair(-23, 56),
        Pair(11, 46), Pair(15, 41), Pair(16, 43), Pair(13, 41), Pair(12, 47), Pair(9, 46), Pair(-10, 11), Pair(-8, 36)
      },
      { // Piece 4
        Pair(12, 83), Pair(4, 57), Pair(-5, 62), Pair(41, 45), Pair(47, 55), Pair(-11, 67), Pair(57, -4), Pair(84, 0),
        Pair(9, 65), Pair(8, 49), Pair(9, 55), Pair(14, 89), Pair(11, 65), Pair(33, 33), Pair(12, 30), Pair(34, 44),
        Pair(-8, 94), Pair(10, 57), Pair(7, 59), Pair(12, 44), Pair(17, 62), Pair(23, 45), Pair(24, 55), Pair(-4, 111),
        Pair(3, 73), Pair(11, 84), Pair(11, 68), Pair(9, 74), Pair(15, 44), Pair(1, 76), Pair(11, 68), Pair(5, 76),
        Pair(19, 67), Pair(17, 70), Pair(14, 77), Pair(12, 67), Pair(5, 73), Pair(-6, 80), Pair(-5, 68), Pair(-11, 56),
        Pair(26, 31), Pair(26, 72), Pair(12, 86), Pair(13, 72), Pair(22, 63), Pair(9, 76), Pair(0, 0), Pair(7, 25),
        Pair(11, 102), Pair(22, 70), Pair(16, 82), Pair(20, 65), Pair(22, 59), Pair(12, 45), Pair(5, 47), Pair(-9, 56),
        Pair(20, 88), Pair(11, 102), Pair(10, 88), Pair(12, 97), Pair(2, 73), Pair(4, 94), Pair(34, 52), Pair(-20, 106)
      },
      { // Piece 5
        Pair(-37, 70), Pair(-10, -28), Pair(-57, -4), Pair(-5, -5), Pair(-84, 31), Pair(-192, 56), Pair(-48, 29), Pair(-100, 55),
        Pair(-90, -17), Pair(-168, 9), Pair(-111, 58), Pair(-113, 55), Pair(-72, 57), Pair(-133, 78), Pair(46, 71), Pair(-42, 28),
        Pair(-93, 16), Pair(17, 11), Pair(-29, 9), Pair(-66, 41), Pair(-56, 39), Pair(-2, 38), Pair(43, 42), Pair(-108, 48),
        Pair(-12, -2), Pair(-112, 40), Pair(-103, 34), Pair(-86, 46), Pair(-34, 34), Pair(16, 35), Pair(-8, 37), Pair(10, 39),
        Pair(-55, 14), Pair(1, 23), Pair(-22, 16), Pair(-51, 28), Pair(-32, 24), Pair(-8, -6), Pair(11, 11), Pair(-34, -6),
        Pair(-85, 6), Pair(-32, 16), Pair(-23, 24), Pair(5, 14), Pair(-18, 22), Pair(-16, 3), Pair(0, 0), Pair(19, -18),
        Pair(-20, 7), Pair(-42, 10), Pair(-16, 11), Pair(-21, 19), Pair(0, 6), Pair(-32, 0), Pair(-1, -2), Pair(-15, -6),
        Pair(-38, -16), Pair(-35, -11), Pair(-33, 6), Pair(-32, -4), Pair(5, -13), Pair(-10, -4), Pair(12, -6), Pair(-24, -8)
      }
    }},
    {{ // Bucket 47
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(13, 5), Pair(-1, 6), Pair(12, 4), Pair(8, -4), Pair(1, 2), Pair(16, -6), Pair(-6, 8), Pair(42, -16),
        Pair(-5, 16), Pair(-2, 13), Pair(4, 7), Pair(2, 9), Pair(-5, 7), Pair(-16, 14), Pair(-27, 19), Pair(3, 5),
        Pair(-1, 13), Pair(4, 10), Pair(2, 7), Pair(4, 8), Pair(-3, 8), Pair(-11, 10), Pair(-1, 11), Pair(19, 2),
        Pair(-4, 14), Pair(2, 14), Pair(2, 13), Pair(0, 8), Pair(3, 8), Pair(0, 6), Pair(12, 3), Pair(-2, 11),
        Pair(0, 16), Pair(1, 15), Pair(2, 10), Pair(1, 13), Pair(5, 10), Pair(4, 5), Pair(0, 2), Pair(-4, -11),
        Pair(-1, 15), Pair(-2, 12), Pair(-2, 15), Pair(-1, 7), Pair(3, 11), Pair(-7, 9), Pair(8, 20), Pair(-12, 6),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(75, 18), Pair(44, -4), Pair(-24, 41), Pair(-19, 43), Pair(64, -1), Pair(29, 24), Pair(106, -9), Pair(8, 3),
        Pair(-3, 24), Pair(-13, 51), Pair(-12, 45), Pair(-5, 42), Pair(-6, 47), Pair(-14, 51), Pair(9, 48), Pair(28, -13),
        Pair(-8, 48), Pair(-4, 45), Pair(19, 31), Pair(16, 33), Pair(30, 34), Pair(-1, 27), Pair(12, 18), Pair(20, 4),
        Pair(-14, 35), Pair(1, 44), Pair(15, 30), Pair(9, 35), Pair(5, 34), Pair(7, 36), Pair(17, 41), Pair(1, 25),
        Pair(-14, 31), Pair(-12, 59), Pair(7, 41), Pair(3, 40), Pair(13, 39), Pair(2, 38), Pair(18, 33), Pair(-2, 25),
        Pair(-11, 26), Pair(-6, 40), Pair(1, 41), Pair(1, 41), Pair(2, 38), Pair(-2, 38), Pair(11, 28), Pair(0, 0),
        Pair(-21, 13), Pair(-7, 33), Pair(0, 33), Pair(-6, 42), Pair(-1, 36), Pair(-25, 39), Pair(-22, 55), Pair(-21, 43),
        Pair(-69, 67), Pair(-13, 43), Pair(-31, 36), Pair(-13, 39), Pair(-8, 42), Pair(0, 18), Pair(3, 0), Pair(-54, 30)
      },
      { // Piece 2
        Pair(29, -18), Pair(42, 8), Pair(-28, -16), Pair(-14, 31), Pair(59, -8), Pair(-44, 24), Pair(-78, 48), Pair(-49, 43),
        Pair(-2, 26), Pair(-5, 15), Pair(-4, 14), Pair(50, -10), Pair(34, 2), Pair(48, -13), Pair(-11, 21), Pair(-13, 9),
        Pair(-2, 14), Pair(17, 32), Pair(23, 9), Pair(10, 17), Pair(-6, 6), Pair(32, 30), Pair(-11, 30), Pair(3, 37),
        Pair(-2, 20), Pair(7, 14), Pair(12, 27), Pair(18, 4), Pair(7, 32), Pair(21, 11), Pair(8, 41), Pair(5, 16),
        Pair(9, 20), Pair(6, 33), Pair(9, 21), Pair(7, 34), Pair(9, 25), Pair(-4, 28), Pair(2, 54), Pair(-4, 31),
        Pair(-2, 41), Pair(-4, 5), Pair(3, 33), Pair(6, 24), Pair(7, 38), Pair(-5, 25), Pair(5, 36), Pair(0, 0),
        Pair(-8, 19), Pair(4, 28), Pair(6, 21), Pair(2, 28), Pair(-6, 32), Pair(4, 33), Pair(6, 22), Pair(7, 49),
        Pair(29, 33), Pair(24, 7), Pair(-2, 41), Pair(-6, 20), Pair(11, 37), Pair(-3, 30), Pair(51, -1), Pair(-3, 1)
      },
      { // Piece 3
        Pair(14, 50), Pair(7, 59), Pair(46, 42), Pair(14, 51), Pair(22, 52), Pair(79, 35), Pair(64, 41), Pair(81, 18),
        Pair(12, 55), Pair(8, 57), Pair(13, 57), Pair(14, 52), Pair(9, 53), Pair(26, 42), Pair(4, 60), Pair(64, 15),
        Pair(11, 60), Pair(25, 45), Pair(15, 51), Pair(32, 41), Pair(11, 59), Pair(18, 59), Pair(22, 49), Pair(41, 22),
        Pair(4, 54), Pair(20, 54), Pair(9, 59), Pair(31, 46), Pair(7, 54), Pair(33, 45), Pair(16, 49), Pair(17, 30),
        Pair(15, 42), Pair(1, 52), Pair(5, 56), Pair(10, 56), Pair(17, 55), Pair(4, 54), Pair(16, 63), Pair(13, 17),
        Pair(8, 57), Pair(19, 51), Pair(23, 45), Pair(11, 50), Pair(7, 58), Pair(4, 59), Pair(6, 52), Pair(0, 0),
        Pair(2, 42), Pair(10, 48), Pair(7, 48), Pair(12, 53), Pair(1, 62), Pair(-3, 55), Pair(8, 39), Pair(-77, 45),
        Pair(14, 47), Pair(17, 45), Pair(18, 47), Pair(16, 46), Pair(13, 48), Pair(17, 49), Pair(-9, 52), Pair(-29, 14)
      },
      { // Piece 4
        Pair(32, 66), Pair(44, 49), Pair(49, 51), Pair(49, 55), Pair(27, 94), Pair(-5, 83), Pair(-4, 88), Pair(6, 80),
        Pair(14, 65), Pair(-2, 87), Pair(30, 61), Pair(7, 72), Pair(-2, 79), Pair(57, 65), Pair(33, 52), Pair(43, 80),
        Pair(16, 63), Pair(14, 70), Pair(29, 49), Pair(8, 66), Pair(3, 77), Pair(18, 91), Pair(6, 85), Pair(6, 73),
        Pair(4, 90), Pair(22, 66), Pair(-6, 78), Pair(14, 72), Pair(2, 87), Pair(24, 67), Pair(15, 71), Pair(22, 53),
        Pair(9, 72), Pair(3, 101), Pair(7, 91), Pair(11, 89), Pair(9, 97), Pair(5, 83), Pair(19, 71), Pair(-2, 80),
        Pair(22, 38), Pair(15, 77), Pair(8, 100), Pair(17, 75), Pair(10, 80), Pair(19, 72), Pair(10, 88), Pair(0, 0),
        Pair(7, 93), Pair(21, 72), Pair(17, 81), Pair(19, 84), Pair(10, 76), Pair(15, 65), Pair(15, 74), Pair(-20, 42),
        Pair(27, 74), Pair(16, 94), Pair(14, 87), Pair(17, 88), Pair(13, 80), Pair(14, 68), Pair(2, 103), Pair(17, 11)
      },
      { // Piece 5
        Pair(-15, -35), Pair(-145, -7), Pair(58, 50), Pair(-62, 14), Pair(-80, 45), Pair(47, 95), Pair(10, 68), Pair(-59, 6),
        Pair(-6, -10), Pair(3, 16), Pair(-36, 52), Pair(-8, 7), Pair(-125, 82), Pair(134, 37), Pair(9, 75), Pair(-187, 11),
        Pair(11, 13), Pair(-15, 19), Pair(-82, 52), Pair(26, 15), Pair(-9, 31), Pair(-55, 59), Pair(-55, 49), Pair(-16, 21),
        Pair(-68, 55), Pair(-36, 21), Pair(-97, 31), Pair(-104, 39), Pair(-121, 51), Pair(-14, 27), Pair(18, 20), Pair(-24, 24),
        Pair(-42, 32), Pair(-109, 35), Pair(-94, 43), Pair(-52, 40), Pair(-29, 31), Pair(-6, 26), Pair(-13, -7), Pair(-31, -9),
        Pair(-66, 17), Pair(-67, 35), Pair(-32, 26), Pair(-41, 27), Pair(-4, 14), Pair(-13, 15), Pair(-62, -3), Pair(0, 0),
        Pair(-46, 20), Pair(-62, 32), Pair(-32, 32), Pair(-46, 22), Pair(-11, 9), Pair(-26, 8), Pair(-38, -7), Pair(-17, -33),
        Pair(-32, -39), Pair(-28, 15), Pair(-42, 21), Pair(-34, 9), Pair(3, -11), Pair(-4, 2), Pair(12, -7), Pair(10, -34)
      }
    }},
    {{ // Bucket 48
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-21, 28), Pair(6, 17), Pair(-20, 18), Pair(27, 0), Pair(-2, 5), Pair(-6, 30), Pair(-29, 24), Pair(-17, 14),
        Pair(6, 31), Pair(-26, 37), Pair(-9, 16), Pair(-5, 13), Pair(6, 7), Pair(5, 9), Pair(5, 12), Pair(-8, 18),
        Pair(1, 13), Pair(-6, 14), Pair(1, 10), Pair(-3, 14), Pair(2, 10), Pair(1, 13), Pair(0, 12), Pair(-3, 12),
        Pair(10, 4), Pair(-2, 16), Pair(1, 12), Pair(-3, 9), Pair(1, 10), Pair(1, 10), Pair(-2, 16), Pair(-1, 14),
        Pair(7, -4), Pair(6, 23), Pair(-1, 9), Pair(1, 9), Pair(-1, 7), Pair(1, 13), Pair(0, 18), Pair(-1, 17),
        Pair(0, 4), Pair(-3, 7), Pair(-6, 9), Pair(0, 15), Pair(-3, 13), Pair(-4, 18), Pair(-1, 18), Pair(0, 19),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(16, -34), Pair(-65, 40), Pair(-9, 70), Pair(-69, 65), Pair(-37, 71), Pair(-16, 22), Pair(-97, 19), Pair(3, 13),
        Pair(2, 19), Pair(-19, 45), Pair(4, 58), Pair(7, 56), Pair(-12, 60), Pair(1, 66), Pair(-15, 94), Pair(-17, 55),
        Pair(-41, 32), Pair(2, 48), Pair(-7, 42), Pair(-15, 60), Pair(-22, 63), Pair(-21, 62), Pair(-8, 49), Pair(-25, 43),
        Pair(-5, 52), Pair(4, 56), Pair(-1, 55), Pair(2, 59), Pair(0, 60), Pair(7, 65), Pair(-4, 54), Pair(-5, 62),
        Pair(2, 50), Pair(-9, 57), Pair(1, 51), Pair(0, 53), Pair(1, 62), Pair(3, 59), Pair(-7, 59), Pair(-4, 62),
        Pair(-13, 51), Pair(3, 50), Pair(4, 53), Pair(4, 55), Pair(1, 61), Pair(1, 54), Pair(3, 58), Pair(-1, 51),
        Pair(0, 0), Pair(1, 43), Pair(-1, 58), Pair(-5, 55), Pair(1, 59), Pair(5, 58), Pair(-9, 66), Pair(-8, 65),
        Pair(45, 57), Pair(-6, 14), Pair(-3, 57), Pair(-13, 70), Pair(-1, 48), Pair(-1, 46), Pair(-8, 37), Pair(-47, 46)
      },
      { // Piece 2
        Pair(0, 54), Pair(61, 23), Pair(-30, 39), Pair(-72, 43), Pair(31, 6), Pair(25, -4), Pair(-32, 5), Pair(-26, 23),
        Pair(-6, 35), Pair(13, 37), Pair(14, 35), Pair(67, 6), Pair(13, 18), Pair(16, 2), Pair(39, 3), Pair(-11, 23),
        Pair(1, 41), Pair(17, 39), Pair(16, 33), Pair(12, 34), Pair(29, 18), Pair(39, 0), Pair(20, 12), Pair(-8, 29),
        Pair(12, 38), Pair(15, 40), Pair(2, 37), Pair(15, 32), Pair(13, 30), Pair(19, 39), Pair(-1, 38), Pair(-7, 49),
        Pair(-5, 34), Pair(14, 34), Pair(11, 28), Pair(7, 34), Pair(8, 47), Pair(7, 38), Pair(0, 42), Pair(-1, 33),
        Pair(3, 15), Pair(25, 48), Pair(1, 39), Pair(2, 55), Pair(1, 48), Pair(8, 54), Pair(-2, 64), Pair(7, 53),
        Pair(0, 0), Pair(2, 40), Pair(7, 41), Pair(-1, 54), Pair(7, 47), Pair(-2, 52), Pair(5, 55), Pair(9, 51),
        Pair(2, 27), Pair(2, 29), Pair(-6, 54), Pair(17, 37), Pair(5, 49), Pair(-4, 50), Pair(-4, 43), Pair(-3, 41)
      },
      { // Piece 3
        Pair(-35, 61), Pair(-19, 79), Pair(5, 66), Pair(10, 71), Pair(-54, 104), Pair(-63, 92), Pair(-44, 94), Pair(-18, 76),
        Pair(-34, 59), Pair(-21, 79), Pair(-23, 85), Pair(2, 66), Pair(-31, 87), Pair(-14, 76), Pair(-14, 85), Pair(7, 71),
        Pair(-57, 77), Pair(-18, 93), Pair(-11, 80), Pair(-23, 81), Pair(-5, 67), Pair(-26, 90), Pair(-17, 80), Pair(-4, 73),
        Pair(-31, 76), Pair(-14, 85), Pair(-1, 73), Pair(-13, 86), Pair(-7, 84), Pair(-18, 83), Pair(-5, 91), Pair(14, 60),
        Pair(-52, 88), Pair(-15, 95), Pair(-3, 79), Pair(6, 74), Pair(4, 72), Pair(-10, 81), Pair(-19, 72), Pair(-3, 76),
        Pair(-33, 51), Pair(-10, 71), Pair(-12, 98), Pair(-3, 71), Pair(-13, 87), Pair(-9, 76), Pair(-11, 72), Pair(3, 79),
        Pair(0, 0), Pair(-3, 71), Pair(-8, 78), Pair(-7, 88), Pair(0, 83), Pair(-13, 75), Pair(-4, 76), Pair(7, 61),
        Pair(-26, 43), Pair(-8, 73), Pair(-6, 77), Pair(-2, 77), Pair(-8, 75), Pair(-6, 74), Pair(0, 70), Pair(-6, 72)
      },
      { // Piece 4
        Pair(-24, 125), Pair(14, 109), Pair(12, 111), Pair(-5, 121), Pair(-29, 123), Pair(-27, 123), Pair(-38, 166), Pair(-36, 145),
        Pair(3, 111), Pair(-7, 119), Pair(25, 79), Pair(40, 66), Pair(-3, 139), Pair(-40, 143), Pair(24, 95), Pair(0, 112),
        Pair(-3, 118), Pair(-6, 132), Pair(10, 113), Pair(-8, 125), Pair(-12, 112), Pair(-8, 136), Pair(0, 117), Pair(12, 105),
        Pair(-15, 150), Pair(2, 119), Pair(-7, 139), Pair(-6, 144), Pair(27, 109), Pair(-1, 135), Pair(17, 96), Pair(6, 125),
        Pair(2, 126), Pair(5, 148), Pair(12, 128), Pair(9, 135), Pair(0, 158), Pair(20, 123), Pair(2, 151), Pair(2, 137),
        Pair(-18, 137), Pair(19, 127), Pair(12, 131), Pair(17, 140), Pair(13, 130), Pair(9, 143), Pair(16, 120), Pair(26, 102),
        Pair(0, 0), Pair(20, 119), Pair(13, 135), Pair(13, 138), Pair(13, 152), Pair(11, 135), Pair(25, 130), Pair(4, 74),
        Pair(9, 101), Pair(15, 117), Pair(8, 105), Pair(10, 133), Pair(11, 155), Pair(16, 122), Pair(-1, 139), Pair(0, 131)
      },
      { // Piece 5
        Pair(-47, 17), Pair(-57, 42), Pair(-66, 50), Pair(51, 15), Pair(57, -16), Pair(85, 33), Pair(-25, 75), Pair(-48, 34),
        Pair(35, 4), Pair(6, 63), Pair(-155, 110), Pair(73, 96), Pair(-114, 40), Pair(109, 0), Pair(-156, 41), Pair(-38, 26),
        Pair(-110, 81), Pair(-51, 84), Pair(6, 53), Pair(-133, 74), Pair(-75, 43), Pair(-202, 37), Pair(-103, 8), Pair(-157, 33),
        Pair(-88, 26), Pair(-77, 53), Pair(-103, 62), Pair(-137, 58), Pair(-104, 53), Pair(-53, 44), Pair(-77, 31), Pair(-125, 24),
        Pair(-5, 0), Pair(-89, 62), Pair(-52, 26), Pair(-38, 42), Pair(-114, 45), Pair(-61, 24), Pair(-33, 22), Pair(-78, 16),
        Pair(-35, -17), Pair(-57, 9), Pair(-13, 28), Pair(-59, 32), Pair(-16, 19), Pair(-19, 20), Pair(-28, 17), Pair(-40, 2),
        Pair(0, 0), Pair(7, -10), Pair(25, 1), Pair(18, 0), Pair(-14, 16), Pair(-2, 7), Pair(-15, 15), Pair(-12, 4),
        Pair(18, -67), Pair(62, -54), Pair(49, -10), Pair(-6, 10), Pair(3, 1), Pair(-4, 7), Pair(-9, 8), Pair(-7, 0)
      }
    }},
    {{ // Bucket 49
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-4, 13), Pair(-34, 5), Pair(-20, 20), Pair(4, -1), Pair(-2, -3), Pair(-43, 18), Pair(-1, -6), Pair(-9, 13),
        Pair(-2, 15), Pair(6, -5), Pair(-3, 14), Pair(-10, 10), Pair(1, 3), Pair(-1, 8), Pair(6, 1), Pair(-11, 9),
        Pair(-5, 10), Pair(5, 4), Pair(-4, 7), Pair(4, 6), Pair(3, 11), Pair(3, 11), Pair(-1, 12), Pair(-3, 12),
        Pair(-3, 14), Pair(4, 11), Pair(0, 11), Pair(1, 9), Pair(2, 10), Pair(2, 12), Pair(2, 15), Pair(-2, 12),
        Pair(-1, 15), Pair(2, -9), Pair(9, 24), Pair(1, 11), Pair(-2, 11), Pair(3, 12), Pair(1, 13), Pair(2, 14),
        Pair(-4, 7), Pair(1, 15), Pair(2, 12), Pair(-4, -18), Pair(-4, 14), Pair(1, 16), Pair(0, 18), Pair(0, 15),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-6, 43), Pair(-6, 23), Pair(-30, 79), Pair(-19, 56), Pair(-19, 21), Pair(-90, 54), Pair(-20, -3), Pair(-82, 61),
        Pair(6, 20), Pair(6, 50), Pair(-9, 34), Pair(-43, 54), Pair(-39, 71), Pair(-11, 43), Pair(-14, 75), Pair(-41, 79),
        Pair(-16, 38), Pair(-18, 47), Pair(0, 43), Pair(-25, 59), Pair(-26, 66), Pair(-24, 56), Pair(-11, 44), Pair(-47, 74),
        Pair(4, 29), Pair(-2, 42), Pair(-2, 61), Pair(-17, 62), Pair(-2, 48), Pair(-13, 48), Pair(-11, 62), Pair(-6, 42),
        Pair(-7, 50), Pair(-3, 40), Pair(4, 43), Pair(0, 55), Pair(-6, 50), Pair(0, 53), Pair(-12, 45), Pair(-6, 41),
        Pair(-2, 34), Pair(-1, 30), Pair(7, 53), Pair(14, 47), Pair(6, 45), Pair(-1, 51), Pair(0, 38), Pair(4, 38),
        Pair(-2, 46), Pair(0, 0), Pair(11, 37), Pair(-1, 43), Pair(0, 55), Pair(-6, 54), Pair(-2, 55), Pair(-8, 46),
        Pair(17, 58), Pair(-8, 83), Pair(-13, 45), Pair(4, 52), Pair(2, 64), Pair(-2, 54), Pair(-6, 33), Pair(18, 66)
      },
      { // Piece 2
        Pair(4, 21), Pair(-24, 25), Pair(-20, 35), Pair(-19, 33), Pair(3, 28), Pair(-6, 28), Pair(17, 0), Pair(30, 48),
        Pair(2, 21), Pair(18, 14), Pair(-6, 37), Pair(19, 24), Pair(8, 18), Pair(40, 1), Pair(-23, 17), Pair(4, -9),
        Pair(0, 31), Pair(5, 35), Pair(34, 22), Pair(11, 6), Pair(15, 7), Pair(-3, 6), Pair(-12, 22), Pair(-13, 30),
        Pair(-3, 23), Pair(4, 32), Pair(6, 26), Pair(-2, 30), Pair(0, 39), Pair(8, 33), Pair(-1, 26), Pair(-19, 43),
        Pair(16, 34), Pair(-16, 41), Pair(6, 30), Pair(-2, 37), Pair(5, 33), Pair(5, 30), Pair(17, 36), Pair(-2, 23),
        Pair(-26, 24), Pair(3, 16), Pair(5, 53), Pair(1, 42), Pair(0, 41), Pair(1, 48), Pair(5, 42), Pair(2, 41),
        Pair(-6, 51), Pair(0, 0), Pair(8, 30), Pair(2, 42), Pair(1, 48), Pair(1, 50), Pair(3, 45), Pair(8, 51),
        Pair(0, 0), Pair(-3, 51), Pair(-8, 27), Pair(12, 42), Pair(-5, 41), Pair(-1, 49), Pair(-5, 60), Pair(-3, 8)
      },
      { // Piece 3
        Pair(-45, 77), Pair(-10, 50), Pair(-42, 71), Pair(-24, 66), Pair(-17, 50), Pair(5, 50), Pair(25, 48), Pair(14, 61),
        Pair(-39, 74), Pair(-47, 58), Pair(-25, 66), Pair(-13, 49), Pair(-31, 63), Pair(-13, 54), Pair(-50, 70), Pair(-38, 69),
        Pair(-18, 56), Pair(-21, 51), Pair(-14, 55), Pair(-14, 57), Pair(-23, 54), Pair(-22, 55), Pair(-18, 53), Pair(-13, 54),
        Pair(-14, 57), Pair(-18, 58), Pair(1, 50), Pair(-2, 50), Pair(-9, 57), Pair(-8, 64), Pair(-10, 63), Pair(-3, 57),
        Pair(-3, 50), Pair(-17, 57), Pair(-5, 46), Pair(11, 53), Pair(-12, 61), Pair(-6, 57), Pair(-3, 62), Pair(-18, 58),
        Pair(-11, 60), Pair(-12, 33), Pair(1, 54), Pair(-7, 55), Pair(1, 49), Pair(-10, 62), Pair(-11, 43), Pair(0, 58),
        Pair(-19, 48), Pair(0, 0), Pair(-3, 57), Pair(-7, 73), Pair(0, 67), Pair(0, 49), Pair(-3, 64), Pair(-21, 60),
        Pair(-7, 53), Pair(-17, 27), Pair(-7, 63), Pair(-2, 52), Pair(-7, 58), Pair(-7, 50), Pair(-6, 51), Pair(-6, 68)
      },
      { // Piece 4
        Pair(-24, 80), Pair(6, 88), Pair(9, 69), Pair(-22, 87), Pair(-33, 102), Pair(7, 54), Pair(-5, 75), Pair(-32, 137),
        Pair(-23, 91), Pair(-2, 90), Pair(-22, 102), Pair(-11, 92), Pair(-3, 69), Pair(-4, 106), Pair(9, 81), Pair(-48, 146),
        Pair(-12, 76), Pair(3, 89), Pair(7, 62), Pair(-22, 114), Pair(-24, 70), Pair(-32, 101), Pair(-2, 124), Pair(-6, 58),
        Pair(-15, 109), Pair(3, 83), Pair(-23, 116), Pair(6, 77), Pair(-10, 79), Pair(2, 47), Pair(-25, 98), Pair(-5, 69),
        Pair(2, 87), Pair(8, 67), Pair(8, 83), Pair(-3, 88), Pair(-5, 86), Pair(1, 87), Pair(-4, 76), Pair(3, 72),
        Pair(-5, 97), Pair(-5, 81), Pair(3, 97), Pair(-1, 110), Pair(-6, 112), Pair(13, 58), Pair(-1, 98), Pair(-16, 93),
        Pair(-2, 44), Pair(0, 0), Pair(3, 95), Pair(7, 94), Pair(9, 109), Pair(14, 94), Pair(14, 97), Pair(1, 97),
        Pair(-1, 76), Pair(-3, 72), Pair(1, 94), Pair(3, 93), Pair(3, 103), Pair(-4, 93), Pair(-19, 143), Pair(33, 123)
      },
      { // Piece 5
        Pair(-121, 25), Pair(75, 37), Pair(-117, 25), Pair(-45, 4), Pair(45, -81), Pair(-21, 6), Pair(9, 5), Pair(-30, -27),
        Pair(-5, 47), Pair(94, 41), Pair(-62, 40), Pair(49, 32), Pair(54, 66), Pair(-125, 54), Pair(-101, 77), Pair(-139, 40),
        Pair(-252, 107), Pair(-52, 54), Pair(23, 29), Pair(-203, 57), Pair(-42, 41), Pair(-23, 5), Pair(-55, 19), Pair(-1, 21),
        Pair(8, 51), Pair(27, 36), Pair(26, 45), Pair(-82, 71), Pair(-114, 25), Pair(-89, 33), Pair(-149, 35), Pair(-46, 21),
        Pair(56, 51), Pair(42, 0), Pair(-65, 41), Pair(-65, 48), Pair(-62, 30), Pair(-38, 22), Pair(-10, 15), Pair(-107, 36),
        Pair(15, 2), Pair(25, -2), Pair(-12, 4), Pair(-22, 28), Pair(-9, 24), Pair(-15, 14), Pair(-22, 10), Pair(-63, 11),
        Pair(83, -10), Pair(0, 0), Pair(-8, -2), Pair(7, 5), Pair(3, 14), Pair(-12, 15), Pair(-10, 4), Pair(-11, -1),
        Pair(72, -28), Pair(46, -20), Pair(29, -14), Pair(20, -3), Pair(14, 1), Pair(-1, 5), Pair(-7, 1), Pair(-9, 2)
      }
    }},
    {{ // Bucket 50
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-41, 32), Pair(-29, 19), Pair(-2, -18), Pair(-2, -14), Pair(-31, 23), Pair(-15, 18), Pair(-20, 15), Pair(-11, 12),
        Pair(-1, 1), Pair(-17, 16), Pair(-6, 5), Pair(-21, 16), Pair(-9, 6), Pair(4, -1), Pair(-4, 13), Pair(-5, 17),
        Pair(0, 8), Pair(-8, 16), Pair(-2, -5), Pair(-4, 15), Pair(1, 8), Pair(4, 13), Pair(-1, 9), Pair(-2, 9),
        Pair(-2, 12), Pair(-1, 17), Pair(-6, -8), Pair(0, 17), Pair(0, 8), Pair(3, 14), Pair(0, 15), Pair(0, 15),
        Pair(-5, 12), Pair(3, 24), Pair(-4, -16), Pair(5, 30), Pair(-7, 10), Pair(1, 13), Pair(0, 13), Pair(-3, 12),
        Pair(-5, 9), Pair(2, 11), Pair(0, 1), Pair(0, 26), Pair(-5, 10), Pair(-4, 15), Pair(-1, 14), Pair(-4, 16),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(6, -33), Pair(55, -12), Pair(-45, 61), Pair(84, -7), Pair(-114, 60), Pair(-83, 60), Pair(-124, 68), Pair(19, -21),
        Pair(-8, 19), Pair(5, 68), Pair(4, 24), Pair(-33, 45), Pair(-4, 32), Pair(25, 21), Pair(-63, 66), Pair(-6, 63),
        Pair(-28, 45), Pair(-15, 52), Pair(-19, 43), Pair(0, 31), Pair(-17, 15), Pair(-14, 60), Pair(-15, 45), Pair(-8, 18),
        Pair(9, 29), Pair(4, 43), Pair(-16, 43), Pair(3, 47), Pair(-14, 45), Pair(-13, 64), Pair(-17, 55), Pair(-19, 56),
        Pair(-1, 41), Pair(16, 32), Pair(0, 38), Pair(2, 48), Pair(-7, 46), Pair(3, 41), Pair(-5, 44), Pair(-2, 53),
        Pair(-3, 35), Pair(10, 41), Pair(-4, 33), Pair(-1, 53), Pair(5, 49), Pair(-7, 46), Pair(4, 50), Pair(2, 37),
        Pair(-11, 17), Pair(6, 23), Pair(0, 0), Pair(3, 40), Pair(3, 48), Pair(-5, 46), Pair(-8, 34), Pair(-6, 74),
        Pair(29, -35), Pair(-10, 45), Pair(20, 44), Pair(3, 52), Pair(1, 35), Pair(5, 41), Pair(-9, 55), Pair(-13, 34)
      },
      { // Piece 2
        Pair(25, 22), Pair(-51, 63), Pair(-12, 31), Pair(51, 22), Pair(32, 14), Pair(48, 17), Pair(-90, 72), Pair(64, -23),
        Pair(-16, 27), Pair(-2, 43), Pair(21, 12), Pair(1, 2), Pair(56, 26), Pair(25, -10), Pair(8, -4), Pair(21, 3),
        Pair(2, 31), Pair(15, 36), Pair(13, 21), Pair(5, 27), Pair(2, -1), Pair(-11, 16), Pair(3, 12), Pair(1, 24),
        Pair(5, 31), Pair(0, 30), Pair(-6, 29), Pair(5, 22), Pair(1, 22), Pair(21, 16), Pair(0, 34), Pair(-1, 35),
        Pair(1, 20), Pair(8, 29), Pair(2, 11), Pair(12, 29), Pair(3, 25), Pair(13, 24), Pair(-9, 34), Pair(-2, 45),
        Pair(-3, 31), Pair(5, 13), Pair(-6, 32), Pair(2, 58), Pair(2, 36), Pair(-3, 34), Pair(-4, 54), Pair(-6, 24),
        Pair(19, -29), Pair(2, 48), Pair(0, 0), Pair(3, 33), Pair(-3, 26), Pair(-6, 45), Pair(-4, 37), Pair(-5, 51),
        Pair(-8, 50), Pair(-40, -109), Pair(1, 58), Pair(4, 2), Pair(-24, 23), Pair(-11, 41), Pair(8, 17), Pair(21, 20)
      },
      { // Piece 3
        Pair(-35, 61), Pair(-24, 51), Pair(33, 32), Pair(12, 50), Pair(-17, 75), Pair(66, 21), Pair(29, 49), Pair(-12, 55),
        Pair(-25, 64), Pair(-11, 59), Pair(4, 36), Pair(-2, 57), Pair(-17, 59), Pair(-22, 62), Pair(-46, 58), Pair(31, 25),
        Pair(-7, 53), Pair(-11, 46), Pair(30, 27), Pair(-34, 59), Pair(-37, 89), Pair(-45, 51), Pair(22, 38), Pair(13, 53),
        Pair(3, 58), Pair(-26, 62), Pair(-24, 52), Pair(-46, 65), Pair(-10, 63), Pair(-14, 60), Pair(-12, 62), Pair(-1, 51),
        Pair(-2, 50), Pair(11, 25), Pair(6, 32), Pair(-15, 48), Pair(-14, 51), Pair(-3, 37), Pair(5, 43), Pair(-8, 52),
        Pair(0, 43), Pair(0, 37), Pair(2, 18), Pair(-1, 38), Pair(-5, 57), Pair(-26, 51), Pair(-3, 34), Pair(13, 52),
        Pair(-30, 43), Pair(-18, 48), Pair(0, 0), Pair(-16, 60), Pair(-4, 49), Pair(-12, 50), Pair(-16, 44), Pair(-15, 54),
        Pair(-11, 43), Pair(-15, 54), Pair(-18, -4), Pair(-15, 50), Pair(-14, 57), Pair(-12, 52), Pair(-9, 59), Pair(-7, 47)
      },
      { // Piece 4
        Pair(19, 51), Pair(-25, 105), Pair(80, 25), Pair(14, 67), Pair(-31, 75), Pair(-14, 41), Pair(76, -8), Pair(-5, 67),
        Pair(6, 51), Pair(12, 79), Pair(6, 70), Pair(16, 31), Pair(36, 22), Pair(47, -21), Pair(-22, 70), Pair(-8, 69),
        Pair(4, 52), Pair(-15, 92), Pair(9, 60), Pair(-25, 118), Pair(-17, 92), Pair(-25, 98), Pair(-19, 94), Pair(-16, 96),
        Pair(13, 45), Pair(0, 51), Pair(9, 66), Pair(-13, 95), Pair(9, 60), Pair(3, 30), Pair(-10, 72), Pair(-10, 78),
        Pair(7, 79), Pair(12, 51), Pair(2, 81), Pair(7, 73), Pair(-3, 90), Pair(-5, 63), Pair(5, 64), Pair(-7, 61),
        Pair(-3, 73), Pair(2, 76), Pair(-1, 80), Pair(11, 87), Pair(4, 86), Pair(-3, 103), Pair(2, 90), Pair(-8, 94),
        Pair(2, 26), Pair(-4, 24), Pair(0, 0), Pair(5, 77), Pair(1, 88), Pair(5, 72), Pair(12, 58), Pair(-32, 96),
        Pair(3, 49), Pair(2, 47), Pair(7, 17), Pair(0, 74), Pair(9, 78), Pair(11, 92), Pair(45, 80), Pair(-1, 40)
      },
      { // Piece 5
        Pair(24, 125), Pair(50, 105), Pair(21, -58), Pair(-13, -73), Pair(53, -4), Pair(-1, 78), Pair(55, 17), Pair(37, 42),
        Pair(16, 38), Pair(-53, 62), Pair(-150, 64), Pair(-20, 71), Pair(68, 49), Pair(-57, 50), Pair(-36, 53), Pair(-64, 12),
        Pair(-98, 23), Pair(124, 57), Pair(-118, 53), Pair(39, 52), Pair(24, 43), Pair(-65, 43), Pair(-121, 26), Pair(-28, -19),
        Pair(68, 38), Pair(-108, 55), Pair(165, -18), Pair(39, 28), Pair(-110, 50), Pair(-142, 34), Pair(-70, 23), Pair(-57, 14),
        Pair(-50, -11), Pair(4, 27), Pair(20, 9), Pair(-7, 25), Pair(-78, 16), Pair(-39, 21), Pair(-25, 17), Pair(-48, 17),
        Pair(42, 31), Pair(10, -29), Pair(-25, -3), Pair(-46, -2), Pair(1, 6), Pair(-2, 1), Pair(-10, 4), Pair(-41, 10),
        Pair(68, -22), Pair(37, -13), Pair(0, 0), Pair(-39, 22), Pair(-1, 3), Pair(2, -2), Pair(-14, 0), Pair(-8, -3),
        Pair(34, 25), Pair(9, -2), Pair(6, -4), Pair(-30, 4), Pair(4, 14), Pair(-4, -1), Pair(-3, -11), Pair(-1, -11)
      }
    }},
    {{ // Bucket 51
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-11, -38), Pair(-49, 12), Pair(13, -18), Pair(-59, -2), Pair(-93, 64), Pair(4, -12), Pair(-13, 3), Pair(-29, -13),
        Pair(11, 2), Pair(-6, 21), Pair(-1, 1), Pair(-16, 3), Pair(10, 10), Pair(12, -2), Pair(10, -3), Pair(-17, 3),
        Pair(-3, 15), Pair(4, 5), Pair(-4, 27), Pair(8, 15), Pair(-3, 12), Pair(-2, 19), Pair(0, 8), Pair(-5, 22),
        Pair(0, 16), Pair(3, 15), Pair(0, 23), Pair(16, -2), Pair(5, 18), Pair(-2, 17), Pair(5, 10), Pair(2, 7),
        Pair(2, 11), Pair(3, 15), Pair(5, 32), Pair(4, -25), Pair(16, 30), Pair(-5, 11), Pair(2, 16), Pair(-1, 6),
        Pair(-2, 13), Pair(-2, -18), Pair(-1, 25), Pair(-5, -6), Pair(6, 25), Pair(-7, 7), Pair(-1, 20), Pair(-2, 17),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(42, -12), Pair(-112, -93), Pair(8, -9), Pair(-39, 46), Pair(1, 12), Pair(-17, -38), Pair(-123, 25), Pair(1, -41),
        Pair(-12, 21), Pair(15, 39), Pair(-18, 30), Pair(-121, 93), Pair(-68, 106), Pair(-66, 51), Pair(-15, -1), Pair(-77, -49),
        Pair(1, 82), Pair(-3, 34), Pair(-20, 57), Pair(-21, 51), Pair(-25, 30), Pair(-45, 38), Pair(-26, 32), Pair(-29, 9),
        Pair(-31, -3), Pair(-8, 37), Pair(-1, 31), Pair(-33, 52), Pair(4, 20), Pair(-29, 80), Pair(-2, 35), Pair(-16, 26),
        Pair(-7, 36), Pair(-18, 16), Pair(-15, 24), Pair(6, 8), Pair(-16, 68), Pair(-1, 42), Pair(-14, 45), Pair(6, 31),
        Pair(-8, 8), Pair(12, 2), Pair(2, 36), Pair(-7, 15), Pair(-2, 10), Pair(-4, 23), Pair(-12, 56), Pair(5, 18),
        Pair(-29, 25), Pair(22, 19), Pair(-14, 26), Pair(0, 0), Pair(-6, 29), Pair(0, 39), Pair(-18, 36), Pair(9, 17),
        Pair(6, 59), Pair(-20, 18), Pair(-29, 3), Pair(21, 21), Pair(24, 22), Pair(25, 17), Pair(-10, -8), Pair(10, -33)
      },
      { // Piece 2
        Pair(-16, 5), Pair(-10, -9), Pair(-107, 46), Pair(-99, 41), Pair(-21, -22), Pair(-6, -19), Pair(-60, -7), Pair(22, 62),
        Pair(-46, -19), Pair(-11, -5), Pair(-52, 27), Pair(16, 7), Pair(-2, -8), Pair(34, 19), Pair(1, 15), Pair(17, -11),
        Pair(-11, 14), Pair(-39, 38), Pair(10, -1), Pair(23, -1), Pair(-4, -6), Pair(-35, 8), Pair(38, -42), Pair(-48, -44),
        Pair(27, 44), Pair(10, 38), Pair(11, 30), Pair(-13, 35), Pair(8, 3), Pair(-3, 15), Pair(-19, -20), Pair(-18, 10),
        Pair(3, -18), Pair(9, 4), Pair(-5, 19), Pair(-14, 7), Pair(-2, 27), Pair(8, 18), Pair(8, 31), Pair(-9, -6),
        Pair(-15, 9), Pair(10, 25), Pair(3, 24), Pair(-19, 22), Pair(8, 29), Pair(4, 33), Pair(-11, -4), Pair(15, -10),
        Pair(20, 32), Pair(-6, 3), Pair(5, -7), Pair(0, 0), Pair(3, 16), Pair(-7, -43), Pair(3, 7), Pair(-34, -85),
        Pair(-15, 28), Pair(-30, 53), Pair(-9, -58), Pair(32, -27), Pair(48, -136), Pair(0, -10), Pair(-98, -11), Pair(-13, 60)
      },
      { // Piece 3
        Pair(4, 22), Pair(21, 29), Pair(-16, 39), Pair(-94, 26), Pair(-11, 21), Pair(76, -7), Pair(-18, 49), Pair(25, 24),
        Pair(-36, 45), Pair(21, 24), Pair(6, 20), Pair(-70, 51), Pair(-15, 55), Pair(-17, 31), Pair(-31, 51), Pair(1, 56),
        Pair(0, 16), Pair(2, 59), Pair(-16, 33), Pair(45, -17), Pair(-18, -8), Pair(-63, 31), Pair(1, 54), Pair(-25, 45),
        Pair(16, 29), Pair(-5, 36), Pair(-20, 41), Pair(83, 9), Pair(21, 17), Pair(-18, 45), Pair(3, 24), Pair(-32, 27),
        Pair(3, 44), Pair(-41, 49), Pair(24, 33), Pair(24, -11), Pair(-14, 47), Pair(4, 15), Pair(27, 26), Pair(16, 45),
        Pair(-6, 9), Pair(27, 13), Pair(1, 67), Pair(9, -17), Pair(10, 11), Pair(3, -23), Pair(0, 53), Pair(-8, 21),
        Pair(-15, -5), Pair(-32, 36), Pair(-12, 14), Pair(0, 0), Pair(18, 0), Pair(-35, 20), Pair(3, 11), Pair(-52, 21),
        Pair(-6, 4), Pair(-7, 43), Pair(-14, 32), Pair(-4, -32), Pair(-17, 32), Pair(-12, 15), Pair(0, 12), Pair(-4, 41)
      },
      { // Piece 4
        Pair(-11, 70), Pair(36, 69), Pair(81, -28), Pair(35, 4), Pair(-74, 111), Pair(103, 87), Pair(-3, 27), Pair(-43, 25),
        Pair(-40, 54), Pair(-25, 99), Pair(-39, 17), Pair(64, -61), Pair(14, 15), Pair(-39, 34), Pair(2, 62), Pair(-20, -18),
        Pair(-53, 72), Pair(10, 76), Pair(-17, 11), Pair(-10, -3), Pair(2, 19), Pair(-58, 42), Pair(-10, 147), Pair(-31, 104),
        Pair(-4, 14), Pair(7, -2), Pair(-37, 48), Pair(-16, 26), Pair(-23, 38), Pair(8, 5), Pair(-18, 65), Pair(-8, 54),
        Pair(-9, 39), Pair(29, -19), Pair(-7, 23), Pair(7, 7), Pair(-8, 36), Pair(-2, 68), Pair(-25, 56), Pair(-12, 53),
        Pair(-41, -6), Pair(0, 9), Pair(15, 33), Pair(-8, 56), Pair(-15, 14), Pair(-9, 41), Pair(-6, 45), Pair(-13, 110),
        Pair(-13, 29), Pair(5, 9), Pair(11, 21), Pair(0, 0), Pair(-4, 34), Pair(1, 39), Pair(5, 49), Pair(-64, 136),
        Pair(13, 13), Pair(5, 20), Pair(9, -9), Pair(-2, -9), Pair(-1, 16), Pair(29, 4), Pair(-30, 99), Pair(5, 32)
      },
      { // Piece 5
        Pair(0, 0), Pair(9, 1), Pair(5, 25), Pair(30, 97), Pair(-16, -94), Pair(-27, -122), Pair(-54, -51), Pair(-22, 2),
        Pair(4, 114), Pair(13, 170), Pair(-5, 44), Pair(11, 1), Pair(64, 98), Pair(-3, 48), Pair(-11, 15), Pair(-12, 13),
        Pair(-37, 5), Pair(71, -5), Pair(-11, 15), Pair(0, 30), Pair(-77, 64), Pair(-16, 7), Pair(-22, -9), Pair(48, 68),
        Pair(44, -46), Pair(7, 67), Pair(-69, 53), Pair(3, 23), Pair(57, 65), Pair(-9, 50), Pair(-154, 60), Pair(24, -35),
        Pair(-84, 2), Pair(-21, 36), Pair(5, 1), Pair(-14, -7), Pair(-23, 24), Pair(-104, -3), Pair(29, 22), Pair(-35, 27),
        Pair(-36, 34), Pair(-78, 15), Pair(27, -46), Pair(-121, 8), Pair(-28, -21), Pair(-37, 21), Pair(-30, 17), Pair(-7, 13),
        Pair(43, -54), Pair(22, -5), Pair(-53, 29), Pair(0, 0), Pair(-57, 19), Pair(-12, 1), Pair(18, -17), Pair(-2, -7),
        Pair(29, -24), Pair(17, 13), Pair(-10, 4), Pair(-64, 38), Pair(-22, -6), Pair(-11, 2), Pair(9, -12), Pair(5, -29)
      }
    }},
    {{ // Bucket 52
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-41, 46), Pair(2, 25), Pair(-10, 11), Pair(-4, 4), Pair(-6, -10), Pair(-53, 42), Pair(-48, 21), Pair(-20, 5),
        Pair(-13, 25), Pair(-10, 4), Pair(0, 14), Pair(-8, 17), Pair(-7, 19), Pair(-27, 30), Pair(-2, 17), Pair(4, -10),
        Pair(-6, 11), Pair(-2, 14), Pair(-3, 6), Pair(1, 17), Pair(5, 9), Pair(4, 14), Pair(-9, 17), Pair(0, 4),
        Pair(-6, 15), Pair(-5, 19), Pair(-2, 10), Pair(4, 16), Pair(6, -2), Pair(9, 15), Pair(-1, 12), Pair(2, 9),
        Pair(-3, 14), Pair(-5, 16), Pair(-5, 13), Pair(10, 35), Pair(0, -7), Pair(19, 25), Pair(2, 13), Pair(0, 9),
        Pair(-4, 14), Pair(-2, 13), Pair(-5, 9), Pair(7, 26), Pair(-4, -1), Pair(5, 17), Pair(-3, -23), Pair(3, 9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-13, 45), Pair(17, 55), Pair(28, 29), Pair(60, 7), Pair(-62, 85), Pair(9, 29), Pair(36, -43), Pair(-105, 64),
        Pair(-5, 0), Pair(-1, 20), Pair(-35, 18), Pair(-21, 83), Pair(26, -12), Pair(-73, 66), Pair(44, 66), Pair(-56, 3),
        Pair(9, -26), Pair(21, 3), Pair(6, 10), Pair(1, 20), Pair(-36, 29), Pair(-26, 29), Pair(-16, 0), Pair(-92, 16),
        Pair(5, 25), Pair(0, 25), Pair(-1, 19), Pair(-5, 37), Pair(-27, 34), Pair(-22, 51), Pair(-12, -10), Pair(1, 7),
        Pair(3, 47), Pair(-3, 33), Pair(-2, 21), Pair(1, 34), Pair(-12, 11), Pair(-4, 36), Pair(-20, 52), Pair(-11, 38),
        Pair(-3, 6), Pair(2, 41), Pair(3, 35), Pair(-3, 34), Pair(-11, 31), Pair(-8, 38), Pair(-14, 14), Pair(-6, -49),
        Pair(42, 1), Pair(13, 38), Pair(-15, 51), Pair(1, 9), Pair(0, 0), Pair(-10, 13), Pair(-9, 20), Pair(-3, 16),
        Pair(-48, 51), Pair(4, 17), Pair(19, 1), Pair(-1, 1), Pair(-10, 37), Pair(-20, 59), Pair(-2, 19), Pair(-36, -8)
      },
      { // Piece 2
        Pair(-12, 22), Pair(-69, 6), Pair(93, -48), Pair(-23, 29), Pair(-86, 29), Pair(18, 25), Pair(42, 93), Pair(8, -4),
        Pair(38, -11), Pair(1, -6), Pair(24, -11), Pair(39, -16), Pair(43, 15), Pair(-50, -22), Pair(-63, 44), Pair(2, -3),
        Pair(-2, 40), Pair(-15, -1), Pair(-4, 17), Pair(11, 6), Pair(20, -15), Pair(-97, 76), Pair(-20, 16), Pair(-18, -5),
        Pair(-6, 4), Pair(12, 7), Pair(-8, 18), Pair(0, 4), Pair(-10, 23), Pair(-27, 21), Pair(-13, 10), Pair(-11, 26),
        Pair(8, 34), Pair(1, -8), Pair(6, -1), Pair(6, 14), Pair(-11, 21), Pair(-2, 12), Pair(1, 12), Pair(-13, 34),
        Pair(-4, 41), Pair(-3, -14), Pair(4, 1), Pair(11, -5), Pair(-11, -2), Pair(0, 17), Pair(-19, 17), Pair(-11, 15),
        Pair(-16, 10), Pair(-3, 23), Pair(49, -39), Pair(-5, 9), Pair(0, 0), Pair(-3, -29), Pair(-9, 9), Pair(-13, -14),
        Pair(4, 31), Pair(-7, 8), Pair(-9, 36), Pair(113, -127), Pair(10, 26), Pair(-11, -37), Pair(1, 4), Pair(17, -1)
      },
      { // Piece 3
        Pair(12, 33), Pair(80, -6), Pair(19, 22), Pair(-29, 48), Pair(37, 11), Pair(-59, 44), Pair(-69, 81), Pair(84, 23),
        Pair(-8, 38), Pair(4, 20), Pair(-20, 44), Pair(1, 27), Pair(20, 1), Pair(-55, 63), Pair(-3, 67), Pair(-26, 49),
        Pair(13, 18), Pair(26, 45), Pair(1, 41), Pair(-21, 28), Pair(-19, 38), Pair(37, 18), Pair(26, 23), Pair(5, 40),
        Pair(5, 40), Pair(0, 25), Pair(-18, 65), Pair(1, 32), Pair(46, -7), Pair(20, 19), Pair(-19, 55), Pair(8, 42),
        Pair(-11, 42), Pair(-12, 40), Pair(5, 31), Pair(17, 27), Pair(9, 27), Pair(-2, 30), Pair(-2, 30), Pair(16, 38),
        Pair(23, -5), Pair(0, 30), Pair(26, 22), Pair(-11, 44), Pair(-3, 12), Pair(-24, 68), Pair(-54, 77), Pair(-34, 80),
        Pair(-10, 55), Pair(1, 14), Pair(19, 12), Pair(-15, 23), Pair(0, 0), Pair(-24, 24), Pair(3, 10), Pair(12, 28),
        Pair(0, 24), Pair(-1, 28), Pair(0, 28), Pair(-8, 33), Pair(-7, -5), Pair(-12, 30), Pair(-19, 44), Pair(-1, 31)
      },
      { // Piece 4
        Pair(11, 36), Pair(-17, 73), Pair(-34, 38), Pair(94, -7), Pair(52, -9), Pair(57, 35), Pair(51, 76), Pair(-119, 120),
        Pair(-16, 53), Pair(-27, 82), Pair(-25, 83), Pair(27, 12), Pair(4, 22), Pair(-14, 37), Pair(9, 105), Pair(-41, 33),
        Pair(-19, 46), Pair(19, 36), Pair(-11, 85), Pair(-31, 68), Pair(-6, 51), Pair(-23, 75), Pair(-48, 74), Pair(-64, 109),
        Pair(-1, 41), Pair(-6, 58), Pair(21, 14), Pair(-18, 49), Pair(8, 30), Pair(-14, 33), Pair(-27, 48), Pair(-15, 60),
        Pair(-3, 43), Pair(-5, 34), Pair(-10, 40), Pair(-7, 34), Pair(8, 47), Pair(-12, 73), Pair(18, 35), Pair(-23, 37),
        Pair(-12, 51), Pair(-2, 31), Pair(-5, 33), Pair(-1, 31), Pair(-19, 47), Pair(5, 31), Pair(-5, 41), Pair(-54, 41),
        Pair(22, 0), Pair(10, 4), Pair(7, 21), Pair(-7, 33), Pair(0, 0), Pair(3, 66), Pair(-3, 31), Pair(22, 116),
        Pair(5, 64), Pair(4, 62), Pair(3, 22), Pair(-2, -1), Pair(2, 4), Pair(15, 42), Pair(-3, 88), Pair(32, 2)
      },
      { // Piece 5
        Pair(13, 94), Pair(-18, -43), Pair(60, 163), Pair(34, 133), Pair(-23, -75), Pair(-6, 38), Pair(-11, -54), Pair(-18, -37),
        Pair(-36, 25), Pair(16, -14), Pair(-1, 41), Pair(-39, -15), Pair(0, -12), Pair(-60, 50), Pair(-16, 75), Pair(-7, -65),
        Pair(-47, -28), Pair(-76, 66), Pair(59, 2), Pair(-136, 44), Pair(-3, 22), Pair(-83, 72), Pair(-50, -21), Pair(-11, 2),
        Pair(-25, 3), Pair(48, -5), Pair(-48, -4), Pair(-130, 41), Pair(-19, 64), Pair(-3, 30), Pair(-27, 18), Pair(1, 4),
        Pair(11, 4), Pair(34, -1), Pair(-8, 21), Pair(9, 25), Pair(40, 17), Pair(-3, 7), Pair(-26, 25), Pair(-19, 36),
        Pair(-55, 5), Pair(-9, -3), Pair(7, -7), Pair(-41, -2), Pair(-9, -10), Pair(21, -21), Pair(6, 4), Pair(16, -3),
        Pair(-36, 7), Pair(-41, 9), Pair(-4, -18), Pair(-59, 22), Pair(0, 0), Pair(-53, 16), Pair(15, -10), Pair(14, -7),
        Pair(-45, -12), Pair(-11, -7), Pair(-10, -12), Pair(-27, 12), Pair(-49, 26), Pair(-23, 8), Pair(8, -8), Pair(16, -23)
      }
    }},
    {{ // Bucket 53
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(3, 9), Pair(9, 8), Pair(-12, 16), Pair(-1, 9), Pair(-15, 19), Pair(-19, 6), Pair(-26, 45), Pair(-5, 14),
        Pair(2, 16), Pair(-6, 19), Pair(-3, 20), Pair(-8, 19), Pair(-5, 9), Pair(-14, 17), Pair(-14, 23), Pair(1, 9),
        Pair(-1, 12), Pair(-1, 13), Pair(-2, 10), Pair(1, 12), Pair(-5, 14), Pair(3, 12), Pair(1, 15), Pair(2, 10),
        Pair(-3, 16), Pair(0, 15), Pair(-1, 11), Pair(-2, 14), Pair(0, 14), Pair(6, 7), Pair(10, 19), Pair(4, 7),
        Pair(-3, 15), Pair(3, 17), Pair(0, 12), Pair(-2, 12), Pair(10, 30), Pair(3, -6), Pair(19, 21), Pair(2, 12),
        Pair(3, 17), Pair(0, 15), Pair(-4, 15), Pair(-8, 8), Pair(5, 17), Pair(6, -2), Pair(5, 7), Pair(-1, 8),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(-23, 29), Pair(33, -5), Pair(-10, 47), Pair(-20, 31), Pair(52, 59), Pair(-17, 32), Pair(27, 2), Pair(-120, 22),
        Pair(-22, 21), Pair(-27, 54), Pair(-15, 63), Pair(5, 41), Pair(-10, 50), Pair(-20, 49), Pair(-26, 54), Pair(-21, 27),
        Pair(-7, 34), Pair(-2, 45), Pair(-1, 43), Pair(-8, 48), Pair(5, 33), Pair(-33, 68), Pair(-24, 59), Pair(4, 22),
        Pair(9, 33), Pair(-2, 56), Pair(7, 46), Pair(-17, 59), Pair(-4, 56), Pair(-22, 56), Pair(-10, 61), Pair(-25, 54),
        Pair(-3, 36), Pair(-2, 51), Pair(-5, 56), Pair(5, 51), Pair(-7, 52), Pair(-5, 48), Pair(-21, 49), Pair(-19, 45),
        Pair(-7, 49), Pair(6, 43), Pair(0, 54), Pair(1, 45), Pair(11, 49), Pair(-6, 35), Pair(0, 56), Pair(-21, 25),
        Pair(-16, 43), Pair(-8, 46), Pair(-1, 53), Pair(3, 46), Pair(-2, 45), Pair(0, 0), Pair(-15, 61), Pair(-12, 41),
        Pair(-38, 22), Pair(-4, 56), Pair(6, 42), Pair(-11, 57), Pair(5, 38), Pair(-11, 60), Pair(-13, 35), Pair(0, 14)
      },
      { // Piece 2
        Pair(23, 22), Pair(-47, 34), Pair(39, 16), Pair(26, 5), Pair(85, 12), Pair(16, 27), Pair(14, 48), Pair(5, 33),
        Pair(-27, 33), Pair(-1, 27), Pair(-2, 33), Pair(24, 20), Pair(1, 31), Pair(-24, 28), Pair(2, 30), Pair(4, 25),
        Pair(11, 16), Pair(0, 22), Pair(26, 21), Pair(-3, 24), Pair(22, 21), Pair(-31, 46), Pair(14, 28), Pair(-27, 48),
        Pair(4, 30), Pair(13, 33), Pair(-4, 40), Pair(-1, 43), Pair(4, 32), Pair(6, 27), Pair(-11, 41), Pair(-11, 32),
        Pair(13, 27), Pair(3, 31), Pair(4, 35), Pair(-9, 35), Pair(9, 39), Pair(-2, 27), Pair(6, 32), Pair(-22, 12),
        Pair(-5, 35), Pair(0, 45), Pair(-7, 39), Pair(3, 36), Pair(-2, 48), Pair(2, 29), Pair(-7, 30), Pair(-4, 34),
        Pair(3, 17), Pair(-9, 41), Pair(4, 33), Pair(-15, 49), Pair(11, 37), Pair(0, 0), Pair(4, 43), Pair(-23, 22),
        Pair(-30, 45), Pair(1, 35), Pair(-11, 49), Pair(12, 30), Pair(-22, 30), Pair(5, 50), Pair(-21, -21), Pair(22, 26)
      },
      { // Piece 3
        Pair(46, 48), Pair(45, 46), Pair(56, 39), Pair(24, 50), Pair(-10, 67), Pair(72, 32), Pair(25, 52), Pair(18, 48),
        Pair(16, 59), Pair(3, 64), Pair(26, 51), Pair(28, 47), Pair(13, 46), Pair(25, 33), Pair(3, 53), Pair(38, 48),
        Pair(7, 61), Pair(31, 49), Pair(10, 54), Pair(25, 46), Pair(4, 60), Pair(35, 37), Pair(0, 56), Pair(41, 49),
        Pair(9, 59), Pair(12, 53), Pair(10, 59), Pair(15, 57), Pair(16, 55), Pair(21, 35), Pair(-32, 75), Pair(-5, 63),
        Pair(4, 70), Pair(11, 62), Pair(16, 60), Pair(18, 60), Pair(2, 62), Pair(33, 45), Pair(2, 70), Pair(6, 54),
        Pair(7, 66), Pair(10, 56), Pair(16, 58), Pair(12, 58), Pair(7, 60), Pair(20, 22), Pair(7, 40), Pair(-6, 74),
        Pair(-11, 59), Pair(1, 55), Pair(1, 57), Pair(-1, 57), Pair(-7, 64), Pair(0, 0), Pair(-26, 26), Pair(-24, 32),
        Pair(4, 59), Pair(3, 57), Pair(8, 55), Pair(3, 59), Pair(1, 57), Pair(-6, 36), Pair(-9, 38), Pair(4, 48)
      },
      { // Piece 4
        Pair(38, 100), Pair(42, 74), Pair(44, 111), Pair(27, 112), Pair(4, 114), Pair(-22, 102), Pair(-28, 102), Pair(27, 85),
        Pair(-2, 92), Pair(-18, 144), Pair(-28, 120), Pair(-14, 131), Pair(-26, 118), Pair(-18, 94), Pair(-10, 93), Pair(-8, 130),
        Pair(-23, 136), Pair(-11, 111), Pair(-4, 129), Pair(-19, 122), Pair(-17, 137), Pair(-32, 119), Pair(-6, 136), Pair(-8, 115),
        Pair(-1, 120), Pair(-11, 133), Pair(-18, 108), Pair(-12, 130), Pair(-3, 109), Pair(4, 104), Pair(3, 112), Pair(-15, 108),
        Pair(16, 121), Pair(11, 108), Pair(1, 123), Pair(11, 104), Pair(6, 99), Pair(-9, 105), Pair(2, 99), Pair(-12, 94),
        Pair(16, 104), Pair(17, 106), Pair(7, 106), Pair(14, 98), Pair(15, 97), Pair(2, 89), Pair(-6, 108), Pair(-16, 128),
        Pair(10, 88), Pair(24, 89), Pair(19, 90), Pair(10, 95), Pair(9, 105), Pair(0, 0), Pair(9, 80), Pair(-11, 48),
        Pair(14, 113), Pair(19, 112), Pair(10, 111), Pair(13, 105), Pair(6, 82), Pair(1, 66), Pair(-13, 66), Pair(3, 116)
      },
      { // Piece 5
        Pair(-31, -22), Pair(107, 13), Pair(-81, 34), Pair(42, 24), Pair(21, 8), Pair(-38, 18), Pair(-108, -5), Pair(-66, 22),
        Pair(-162, -2), Pair(57, 59), Pair(-125, 55), Pair(33, 31), Pair(-138, 118), Pair(3, 81), Pair(-146, 89), Pair(-70, 40),
        Pair(-21, 44), Pair(15, 22), Pair(-26, 26), Pair(-92, 55), Pair(-87, 92), Pair(-49, 71), Pair(-88, 64), Pair(-3, 9),
        Pair(-190, 46), Pair(-63, 30), Pair(-208, 56), Pair(-47, 46), Pair(-40, 43), Pair(-105, 57), Pair(18, 32), Pair(-26, 29),
        Pair(-81, 20), Pair(-25, 21), Pair(-72, 41), Pair(-77, 25), Pair(-10, 29), Pair(-26, 27), Pair(37, 6), Pair(26, 16),
        Pair(-54, 10), Pair(-57, 29), Pair(-32, 26), Pair(10, 18), Pair(-31, -3), Pair(-13, -4), Pair(-17, -14), Pair(52, -1),
        Pair(-25, 12), Pair(-11, 20), Pair(8, 12), Pair(-8, 13), Pair(-2, -8), Pair(0, 0), Pair(25, -13), Pair(37, -1),
        Pair(-1, -17), Pair(-8, 7), Pair(7, -3), Pair(4, 0), Pair(-6, 1), Pair(-43, 26), Pair(7, 3), Pair(25, 3)
      }
    }},
    {{ // Bucket 54
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-13, 19), Pair(-5, 17), Pair(-22, 17), Pair(-7, 10), Pair(-24, 16), Pair(-1, 13), Pair(22, -24), Pair(-50, 31),
        Pair(1, 15), Pair(5, 9), Pair(-1, 9), Pair(-8, 16), Pair(-14, 12), Pair(-6, 15), Pair(-3, -19), Pair(-2, 12),
        Pair(0, 17), Pair(0, 13), Pair(2, 10), Pair(2, 8), Pair(0, 15), Pair(-8, 12), Pair(7, -3), Pair(-3, 13),
        Pair(1, 18), Pair(3, 16), Pair(2, 12), Pair(2, 13), Pair(-2, 9), Pair(2, 16), Pair(6, -2), Pair(3, 14),
        Pair(-2, 14), Pair(-3, 16), Pair(4, 14), Pair(2, 11), Pair(0, 14), Pair(17, 19), Pair(-10, 2), Pair(12, 20),
        Pair(-2, 17), Pair(2, 15), Pair(-1, 13), Pair(-1, 22), Pair(-5, -23), Pair(7, 9), Pair(10, 1), Pair(-3, 5),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(19, 25), Pair(-2, 55), Pair(16, 28), Pair(91, -7), Pair(17, 17), Pair(-30, 40), Pair(7, 38), Pair(93, -76),
        Pair(-1, 15), Pair(-15, 45), Pair(11, 53), Pair(24, 35), Pair(28, 18), Pair(11, 17), Pair(13, 19), Pair(-6, 39),
        Pair(-13, 25), Pair(4, 37), Pair(3, 34), Pair(5, 37), Pair(-7, 36), Pair(34, 23), Pair(-3, 36), Pair(22, 12),
        Pair(-3, 45), Pair(5, 40), Pair(0, 44), Pair(-3, 51), Pair(-2, 38), Pair(20, 30), Pair(4, 35), Pair(-18, 40),
        Pair(-8, 41), Pair(-8, 32), Pair(2, 45), Pair(1, 38), Pair(5, 41), Pair(8, 37), Pair(-2, 37), Pair(-13, 42),
        Pair(-7, 28), Pair(1, 31), Pair(-2, 37), Pair(-1, 42), Pair(-2, 41), Pair(5, 39), Pair(-4, 26), Pair(-15, 38),
        Pair(-23, 68), Pair(-31, 52), Pair(-17, 57), Pair(-5, 46), Pair(-7, 41), Pair(-1, 28), Pair(0, 0), Pair(-11, 35),
        Pair(-50, 45), Pair(-9, 35), Pair(-6, 45), Pair(-10, 45), Pair(-10, 35), Pair(-3, 31), Pair(5, 47), Pair(-41, 48)
      },
      { // Piece 2
        Pair(-43, 18), Pair(12, -5), Pair(1, 5), Pair(72, 21), Pair(59, -16), Pair(127, 12), Pair(61, -1), Pair(27, 36),
        Pair(21, 7), Pair(-26, 30), Pair(-3, 27), Pair(22, -5), Pair(46, 18), Pair(1, 9), Pair(-2, 30), Pair(-12, 38),
        Pair(-9, 22), Pair(17, 27), Pair(18, -5), Pair(11, 23), Pair(1, 18), Pair(23, 25), Pair(-31, 40), Pair(0, 30),
        Pair(-17, 31), Pair(-3, 28), Pair(18, 24), Pair(3, 23), Pair(6, 30), Pair(4, 20), Pair(12, 19), Pair(-19, 46),
        Pair(-4, 14), Pair(8, 33), Pair(4, 22), Pair(12, 28), Pair(-3, 30), Pair(10, 32), Pair(-2, 14), Pair(8, 35),
        Pair(10, 29), Pair(-1, 28), Pair(2, 33), Pair(-5, 27), Pair(2, 36), Pair(-7, 35), Pair(-4, 23), Pair(-23, 28),
        Pair(10, 24), Pair(2, 36), Pair(-5, 36), Pair(4, 39), Pair(-8, 34), Pair(19, 13), Pair(0, 0), Pair(7, 10),
        Pair(21, 30), Pair(6, 18), Pair(-1, 41), Pair(-20, 41), Pair(4, 26), Pair(-19, 21), Pair(18, 30), Pair(0, 0)
      },
      { // Piece 3
        Pair(26, 47), Pair(33, 39), Pair(51, 36), Pair(28, 42), Pair(19, 47), Pair(74, 23), Pair(33, 32), Pair(47, 33),
        Pair(17, 46), Pair(6, 54), Pair(27, 44), Pair(22, 45), Pair(28, 44), Pair(29, 32), Pair(40, 21), Pair(6, 46),
        Pair(7, 49), Pair(10, 49), Pair(0, 52), Pair(17, 41), Pair(-4, 57), Pair(14, 42), Pair(22, 40), Pair(-5, 49),
        Pair(20, 45), Pair(17, 43), Pair(18, 53), Pair(12, 51), Pair(22, 52), Pair(16, 40), Pair(39, 25), Pair(-14, 53),
        Pair(4, 53), Pair(10, 61), Pair(10, 54), Pair(15, 47), Pair(11, 54), Pair(28, 54), Pair(39, 23), Pair(-3, 47),
        Pair(20, 48), Pair(-2, 58), Pair(15, 49), Pair(3, 46), Pair(14, 51), Pair(14, 48), Pair(29, 12), Pair(-18, 47),
        Pair(7, 52), Pair(5, 55), Pair(5, 56), Pair(-5, 60), Pair(4, 54), Pair(0, 53), Pair(0, 0), Pair(-44, 30),
        Pair(9, 52), Pair(13, 43), Pair(13, 49), Pair(9, 49), Pair(8, 55), Pair(6, 55), Pair(-12, 16), Pair(-18, 40)
      },
      { // Piece 4
        Pair(25, 77), Pair(38, 80), Pair(-24, 74), Pair(48, 47), Pair(26, 68), Pair(84, 37), Pair(32, 51), Pair(39, 44),
        Pair(7, 94), Pair(6, 65), Pair(7, 81), Pair(20, 72), Pair(8, 71), Pair(5, 64), Pair(4, 103), Pair(34, 49),
        Pair(5, 83), Pair(-1, 97), Pair(25, 55), Pair(8, 104), Pair(6, 101), Pair(36, 62), Pair(19, 100), Pair(4, 122),
        Pair(4, 81), Pair(18, 85), Pair(17, 86), Pair(20, 58), Pair(14, 87), Pair(1, 83), Pair(6, 109), Pair(9, 85),
        Pair(16, 85), Pair(25, 74), Pair(19, 76), Pair(13, 75), Pair(19, 62), Pair(4, 96), Pair(21, 57), Pair(9, 74),
        Pair(33, 61), Pair(29, 81), Pair(6, 108), Pair(18, 80), Pair(21, 84), Pair(10, 93), Pair(0, 86), Pair(0, 88),
        Pair(29, 66), Pair(15, 94), Pair(16, 103), Pair(19, 87), Pair(21, 83), Pair(6, 106), Pair(0, 0), Pair(-28, 119),
        Pair(23, 102), Pair(17, 113), Pair(17, 100), Pair(16, 99), Pair(4, 111), Pair(18, 64), Pair(52, 79), Pair(-1, -14)
      },
      { // Piece 5
        Pair(8, 41), Pair(-129, 73), Pair(-53, 57), Pair(-51, 42), Pair(-5, 51), Pair(58, 70), Pair(13, 82), Pair(-5, 82),
        Pair(-125, 9), Pair(-17, 20), Pair(-38, 28), Pair(-4, -1), Pair(-45, 55), Pair(-50, 80), Pair(-57, 71), Pair(57, 58),
        Pair(-108, 56), Pair(-40, 4), Pair(-40, 21), Pair(-214, 74), Pair(-149, 64), Pair(-124, 64), Pair(-38, 83), Pair(-69, 55),
        Pair(-134, 26), Pair(-55, 39), Pair(-90, 50), Pair(-150, 72), Pair(-95, 41), Pair(-56, 44), Pair(-47, 61), Pair(-56, 48),
        Pair(-61, 1), Pair(-97, 24), Pair(-46, 41), Pair(-53, 37), Pair(-63, 38), Pair(-17, 28), Pair(28, 19), Pair(-16, 19),
        Pair(-80, 13), Pair(-70, 39), Pair(-16, 19), Pair(-23, 34), Pair(-1, 16), Pair(-31, 0), Pair(-19, 0), Pair(-3, -22),
        Pair(-45, 14), Pair(-38, 27), Pair(-19, 22), Pair(-12, 11), Pair(7, 13), Pair(-18, -10), Pair(0, 0), Pair(1, -3),
        Pair(-35, 8), Pair(-21, -7), Pair(-8, 4), Pair(-21, 14), Pair(28, -5), Pair(-5, -9), Pair(10, -3), Pair(-13, -8)
      }
    }},
    {{ // Bucket 55
      { // Piece 0
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
        Pair(-2, 25), Pair(-6, 15), Pair(-1, 13), Pair(7, 1), Pair(-12, 2), Pair(5, 6), Pair(-14, 9), Pair(8, 3),
        Pair(-3, 17), Pair(-9, 17), Pair(4, 9), Pair(-7, 11), Pair(-10, 7), Pair(-13, 6), Pair(-25, 18), Pair(8, -5),
        Pair(-1, 13), Pair(3, 10), Pair(-1, 9), Pair(0, 7), Pair(-5, 11), Pair(-15, 13), Pair(-7, 16), Pair(10, 13),
        Pair(-2, 18), Pair(0, 16), Pair(-3, 11), Pair(-1, 11), Pair(0, 7), Pair(-4, 5), Pair(5, 10), Pair(0, 9),
        Pair(-5, 11), Pair(1, 15), Pair(0, 14), Pair(-3, 12), Pair(4, 7), Pair(0, 8), Pair(6, 22), Pair(-11, 6),
        Pair(-2, 15), Pair(-1, 17), Pair(-2, 16), Pair(-1, 17), Pair(3, 11), Pair(-5, 8), Pair(-4, 7), Pair(4, -9),
        Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
      },
      { // Piece 1
        Pair(24, 38), Pair(27, 38), Pair(-40, 46), Pair(18, 13), Pair(28, 15), Pair(61, 24), Pair(-21, 19), Pair(6, 10),
        Pair(13, 21), Pair(-21, 48), Pair(-4, 51), Pair(-4, 28), Pair(-22, 37), Pair(-30, 47), Pair(-5, 35), Pair(30, 1),
        Pair(-31, 77), Pair(-9, 52), Pair(12, 39), Pair(16, 43), Pair(8, 44), Pair(2, 37), Pair(-10, 19), Pair(19, 28),
        Pair(-1, 26), Pair(-4, 54), Pair(8, 52), Pair(8, 42), Pair(0, 43), Pair(2, 42), Pair(13, 39), Pair(3, 36),
        Pair(-6, 34), Pair(-4, 59), Pair(6, 47), Pair(3, 48), Pair(9, 45), Pair(-10, 43), Pair(8, 39), Pair(-4, 17),
        Pair(-13, 39), Pair(-5, 47), Pair(-2, 52), Pair(-1, 51), Pair(2, 47), Pair(-4, 47), Pair(11, 34), Pair(-17, 7),
        Pair(-18, 29), Pair(-6, 31), Pair(-4, 42), Pair(-6, 51), Pair(-8, 51), Pair(-16, 40), Pair(-10, 39), Pair(0, 0),
        Pair(5, 45), Pair(-13, 44), Pair(-39, 71), Pair(-11, 43), Pair(-5, 40), Pair(1, 27), Pair(-3, 9), Pair(-59, -16)
      },
      { // Piece 2
        Pair(36, 9), Pair(43, 12), Pair(8, 4), Pair(22, 19), Pair(83, -11), Pair(-44, 3), Pair(34, 11), Pair(-25, 42),
        Pair(10, 10), Pair(-9, 29), Pair(-12, 32), Pair(62, -8), Pair(0, 17), Pair(10, 10), Pair(20, 19), Pair(-25, 26),
        Pair(2, 25), Pair(-2, 40), Pair(18, 27), Pair(30, 13), Pair(0, 24), Pair(32, 32), Pair(-20, 39), Pair(-6, 39),
        Pair(-1, 20), Pair(11, 33), Pair(8, 33), Pair(8, 31), Pair(7, 24), Pair(4, 29), Pair(2, 42), Pair(15, 21),
        Pair(24, 13), Pair(2, 34), Pair(8, 35), Pair(7, 38), Pair(11, 34), Pair(-7, 35), Pair(-2, 35), Pair(-18, 31),
        Pair(-1, 36), Pair(-10, 46), Pair(1, 37), Pair(11, 36), Pair(4, 44), Pair(-3, 35), Pair(6, 44), Pair(2, 17),
        Pair(-1, 25), Pair(1, 39), Pair(8, 25), Pair(-2, 41), Pair(0, 42), Pair(6, 38), Pair(2, 29), Pair(0, 0),
        Pair(27, 30), Pair(14, 25), Pair(-5, 45), Pair(-12, 34), Pair(3, 34), Pair(0, 41), Pair(44, 8), Pair(18, 23)
      },
      { // Piece 3
        Pair(16, 64), Pair(18, 60), Pair(15, 58), Pair(-18, 70), Pair(63, 46), Pair(58, 59), Pair(35, 49), Pair(45, 27),
        Pair(14, 67), Pair(9, 69), Pair(13, 72), Pair(-13, 77), Pair(-19, 80), Pair(6, 71), Pair(10, 63), Pair(-9, 44),
        Pair(10, 73), Pair(12, 64), Pair(1, 65), Pair(23, 52), Pair(8, 62), Pair(-3, 56), Pair(28, 64), Pair(28, 28),
        Pair(9, 65), Pair(19, 64), Pair(8, 63), Pair(26, 60), Pair(4, 67), Pair(16, 60), Pair(1, 63), Pair(-17, 68),
        Pair(13, 68), Pair(9, 67), Pair(5, 61), Pair(0, 77), Pair(4, 79), Pair(6, 68), Pair(14, 63), Pair(3, 47),
        Pair(7, 58), Pair(14, 59), Pair(12, 61), Pair(3, 63), Pair(2, 64), Pair(-1, 71), Pair(-2, 68), Pair(-14, 36),
        Pair(-2, 69), Pair(14, 71), Pair(3, 66), Pair(12, 64), Pair(-8, 73), Pair(-5, 72), Pair(15, 46), Pair(0, 0),
        Pair(14, 68), Pair(16, 61), Pair(14, 65), Pair(13, 64), Pair(14, 61), Pair(18, 68), Pair(3, 58), Pair(-18, 27)
      },
      { // Piece 4
        Pair(43, 90), Pair(2, 102), Pair(38, 80), Pair(-14, 106), Pair(18, 87), Pair(-2, 76), Pair(17, 105), Pair(-19, 128),
        Pair(4, 111), Pair(1, 106), Pair(22, 80), Pair(-1, 109), Pair(-5, 94), Pair(42, 84), Pair(-13, 52), Pair(46, 62),
        Pair(-1, 123), Pair(8, 107), Pair(15, 102), Pair(14, 74), Pair(36, 74), Pair(43, 79), Pair(30, 108), Pair(13, 96),
        Pair(1, 139), Pair(18, 90), Pair(14, 85), Pair(25, 84), Pair(-6, 122), Pair(6, 96), Pair(13, 82), Pair(21, 88),
        Pair(1, 121), Pair(12, 103), Pair(10, 98), Pair(16, 101), Pair(22, 86), Pair(4, 103), Pair(15, 95), Pair(5, 89),
        Pair(4, 120), Pair(16, 100), Pair(12, 109), Pair(18, 98), Pair(8, 101), Pair(16, 94), Pair(10, 103), Pair(3, 91),
        Pair(16, 89), Pair(18, 98), Pair(15, 107), Pair(19, 109), Pair(8, 106), Pair(9, 106), Pair(13, 93), Pair(0, 0),
        Pair(27, 93), Pair(15, 100), Pair(11, 128), Pair(15, 114), Pair(10, 98), Pair(1, 89), Pair(24, 60), Pair(55, 23)
      },
      { // Piece 5
        Pair(-40, -53), Pair(-178, 52), Pair(-76, 52), Pair(-22, 34), Pair(-12, 54), Pair(26, 119), Pair(38, 60), Pair(-26, 64),
        Pair(1, 24), Pair(-121, 62), Pair(89, 21), Pair(-79, 101), Pair(-100, 90), Pair(15, 75), Pair(-69, 60), Pair(-42, 52),
        Pair(-171, 40), Pair(-19, 43), Pair(18, 60), Pair(-49, 48), Pair(-167, 88), Pair(-59, 69), Pair(-83, 86), Pair(-144, 50),
        Pair(-37, 26), Pair(-95, 38), Pair(-21, 49), Pair(-69, 55), Pair(-117, 53), Pair(-48, 38), Pair(-13, 52), Pair(-18, 27),
        Pair(-91, 68), Pair(-44, 35), Pair(-157, 61), Pair(-57, 47), Pair(-15, 27), Pair(-1, 19), Pair(47, 4), Pair(-18, 19),
        Pair(-37, 41), Pair(-43, 43), Pair(-7, 35), Pair(-15, 26), Pair(4, 23), Pair(8, 15), Pair(0, -19), Pair(-11, -13),
        Pair(-25, 3), Pair(-45, 50), Pair(-18, 32), Pair(-30, 38), Pair(7, 15), Pair(-8, 9), Pair(-29, -21), Pair(0, 0),
        Pair(-32, 6), Pair(-20, 17), Pair(-22, 26), Pair(-21, 9), Pair(15, -2), Pair(13, 2), Pair(8, -27), Pair(17, -53)
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
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0),
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(-20, -109), Pair(-42, -208), Pair(-24, -173), Pair(-42, -184), Pair(-45, -201), Pair(-30, -198), Pair(-9, -180), Pair(-19, -143),
      Pair(-22, -165), Pair(-21, -205), Pair(4, -222), Pair(-51, -145), Pair(-58, -198), Pair(-64, -234), Pair(-35, -205), Pair(-57, -217),
      Pair(-22, -222), Pair(-43, -210), Pair(8, -197), Pair(-14, -205), Pair(-36, -220), Pair(-4, -203), Pair(-37, -211), Pair(-9, -245),
      Pair(-14, -196), Pair(2, -215), Pair(22, -216), Pair(-32, -208), Pair(23, -219), Pair(18, -213), Pair(4, -222), Pair(4, -215),
      Pair(-13, -218), Pair(-32, -257), Pair(15, -205), Pair(14, -215), Pair(42, -202), Pair(24, -212), Pair(24, -249), Pair(28, -244),
      Pair(-13, -232), Pair(-26, -210), Pair(-15, -218), Pair(-14, -228), Pair(-8, -218), Pair(52, -226), Pair(37, -223), Pair(-33, -228),
      Pair(-19, -228), Pair(-2, -218), Pair(-72, -240), Pair(1, -221), Pair(-21, -207), Pair(-9, -219), Pair(-16, -244), Pair(-22, -251),
      Pair(-23, -205), Pair(-18, -205), Pair(-21, -205), Pair(-20, -173), Pair(0, -206), Pair(-33, -203), Pair(-36, -236), Pair(-11, -159)
  },
  {
      Pair(-20, -137), Pair(-8, -168), Pair(-42, -179), Pair(-40, -151), Pair(-56, -168), Pair(-51, -193), Pair(-70, -233), Pair(-51, -167),
      Pair(-11, -197), Pair(-53, -204), Pair(-58, -210), Pair(-60, -195), Pair(-88, -201), Pair(-48, -242), Pair(-61, -165), Pair(-34, -187),
      Pair(-43, -233), Pair(-49, -232), Pair(-60, -242), Pair(-26, -231), Pair(-35, -232), Pair(-33, -236), Pair(-68, -219), Pair(-42, -241),
      Pair(-49, -200), Pair(-38, -272), Pair(-29, -235), Pair(-48, -253), Pair(-46, -221), Pair(27, -237), Pair(-65, -242), Pair(-35, -252),
      Pair(-11, -272), Pair(-18, -258), Pair(-25, -248), Pair(-25, -242), Pair(-27, -240), Pair(36, -267), Pair(-21, -271), Pair(-50, -229),
      Pair(-13, -257), Pair(-58, -240), Pair(-66, -253), Pair(-68, -219), Pair(22, -248), Pair(-46, -255), Pair(-15, -279), Pair(-42, -242),
      Pair(39, -297), Pair(-40, -260), Pair(-61, -269), Pair(-29, -245), Pair(-22, -259), Pair(-28, -260), Pair(-14, -287), Pair(-24, -322),
      Pair(4, -274), Pair(-31, -302), Pair(-53, -248), Pair(-49, -276), Pair(-26, -249), Pair(-38, -273), Pair(-24, -241), Pair(-22, -291)
  },
  {
      Pair(-47, -311), Pair(15, -328), Pair(-21, -322), Pair(79, -360), Pair(9, -358), Pair(-29, -337), Pair(53, -351), Pair(-28, -340),
      Pair(-75, -307), Pair(-98, -316), Pair(-83, -307), Pair(-55, -320), Pair(-103, -304), Pair(-75, -311), Pair(-57, -331), Pair(-78, -324),
      Pair(5, -334), Pair(-32, -312), Pair(36, -349), Pair(-56, -312), Pair(-47, -325), Pair(-5, -331), Pair(-106, -302), Pair(-47, -347),
      Pair(-11, -329), Pair(-79, -314), Pair(-60, -313), Pair(-38, -311), Pair(-51, -315), Pair(19, -355), Pair(-64, -343), Pair(-58, -346),
      Pair(-52, -314), Pair(-72, -310), Pair(-113, -311), Pair(-83, -320), Pair(-69, -342), Pair(-75, -328), Pair(-45, -323), Pair(-75, -322),
      Pair(-97, -305), Pair(-129, -286), Pair(-74, -313), Pair(-85, -316), Pair(-88, -296), Pair(-43, -342), Pair(-95, -313), Pair(-62, -316),
      Pair(-115, -295), Pair(-111, -302), Pair(-77, -299), Pair(-69, -293), Pair(-105, -303), Pair(-112, -310), Pair(-79, -293), Pair(-95, -290),
      Pair(-100, -286), Pair(-90, -316), Pair(-55, -305), Pair(-75, -299), Pair(-80, -310), Pair(-66, -319), Pair(-136, -308), Pair(-85, -316)
  },
  {
      Pair(-1, -39), Pair(-55, -84), Pair(-21, -86), Pair(29, -50), Pair(-61, -72), Pair(1, -81), Pair(-50, -3), Pair(-65, -68),
      Pair(-19, -41), Pair(-50, -65), Pair(-19, -51), Pair(-5, 3), Pair(0, -4), Pair(-56, -56), Pair(-1, -5), Pair(-35, -66),
      Pair(-28, -47), Pair(-25, -44), Pair(-11, -26), Pair(-57, -110), Pair(13, 7), Pair(19, 23), Pair(9, 3), Pair(-27, -49),
      Pair(-44, -82), Pair(-10, -4), Pair(-26, -47), Pair(-30, -60), Pair(-46, -25), Pair(-4, -38), Pair(-13, -71), Pair(-9, -28),
      Pair(-25, -41), Pair(-8, -10), Pair(-13, -31), Pair(8, 3), Pair(-21, -47), Pair(-6, -24), Pair(-50, -94), Pair(-57, -85),
      Pair(-20, -36), Pair(-19, -31), Pair(-16, -34), Pair(30, 44), Pair(-21, -31), Pair(16, 25), Pair(0, 6), Pair(0, -3),
      Pair(-28, -59), Pair(-56, -95), Pair(-40, -64), Pair(-3, -7), Pair(1, -1), Pair(9, 20), Pair(-7, -17), Pair(-2, -2),
      Pair(-6, -12), Pair(-12, -28), Pair(-30, -56), Pair(-26, -54), Pair(6, 7), Pair(-27, -53), Pair(-1, -2), Pair(-4, -10)
  },
  {
      Pair(46, 52), Pair(-33, 4), Pair(2, -10), Pair(-35, -2), Pair(12, -15), Pair(-32, -1), Pair(-39, -30), Pair(-24, 40),
      Pair(-3, 33), Pair(-23, -8), Pair(-22, 3), Pair(-12, -8), Pair(-6, -14), Pair(0, -5), Pair(17, 7), Pair(-27, 5),
      Pair(-28, 33), Pair(20, 14), Pair(2, 9), Pair(85, -23), Pair(42, -21), Pair(82, -6), Pair(87, -8), Pair(-73, 33),
      Pair(24, 17), Pair(11, 21), Pair(17, 29), Pair(54, -23), Pair(17, -10), Pair(31, -18), Pair(-25, -4), Pair(-41, 1),
      Pair(14, 45), Pair(-57, 22), Pair(-25, 11), Pair(32, -11), Pair(5, -21), Pair(35, -13), Pair(-3, -12), Pair(-53, 9),
      Pair(-42, 36), Pair(-31, 1), Pair(60, -9), Pair(16, -18), Pair(28, -14), Pair(54, -26), Pair(-8, -25), Pair(-55, 6),
      Pair(6, 31), Pair(-13, 1), Pair(42, -8), Pair(-13, -3), Pair(4, -21), Pair(50, -27), Pair(40, -42), Pair(-22, 12),
      Pair(1, 20), Pair(-62, 3), Pair(-11, -9), Pair(1, -27), Pair(-15, -11), Pair(8, -14), Pair(-63, -18), Pair(-50, 11)
  }
}};

constexpr KnightMobilityTable<ScorePair> kKnightMobility = {
  Pair(10, 47), Pair(20, 30), Pair(22, 36), Pair(23, 44), Pair(24, 50), Pair(24, 57), Pair(27, 57), Pair(30, 58),
  Pair(35, 52)
};

constexpr BishopMobilityTable<ScorePair> kBishopMobility = {
  Pair(-5, 4), Pair(1, -26), Pair(6, -11), Pair(9, 2), Pair(12, 13), Pair(13, 21), Pair(13, 25), Pair(15, 26),
  Pair(14, 32), Pair(18, 28), Pair(30, 27), Pair(50, 16), Pair(34, 38), Pair(58, 12)
};

constexpr RookMobilityTable<ScorePair> kRookMobility = {
  Pair(-48, -92), Pair(-32, -91), Pair(-30, -49), Pair(-29, -19), Pair(-28, -6), Pair(-24, -1), Pair(-20, 7), Pair(-15, 11),
  Pair(-11, 16), Pair(-6, 18), Pair(-2, 23), Pair(1, 26), Pair(8, 24), Pair(32, 11), Pair(72, -12)
};

constexpr QueenMobilityTable<ScorePair> kQueenMobility = {
  Pair(-73, 253), Pair(-11, 141), Pair(-7, 100), Pair(-2, 80), Pair(-3, 119), Pair(-2, 120), Pair(-1, 146), Pair(-1, 164),
  Pair(0, 175), Pair(2, 179), Pair(4, 180), Pair(5, 183), Pair(8, 181), Pair(9, 179), Pair(13, 173), Pair(13, 170),
  Pair(13, 163), Pair(21, 143), Pair(21, 143), Pair(37, 121), Pair(57, 98), Pair(83, 63), Pair(58, 66), Pair(93, 45),
  Pair(61, 57), Pair(160, -14), Pair(168, -14), Pair(223, -12)
};

constexpr RankTable<ScorePair> kPassedPawnBonus = {
  Pair(0, 0), Pair(-26, -102), Pair(-22, -85), Pair(-8, -55), Pair(13, -18), Pair(6, 40), Pair(165, 162), Pair(0, 0)
};

constexpr RankTable<ScorePair> kPawnPhalanxBonus = {
  Pair(0, 0), Pair(8, 12), Pair(19, 17), Pair(22, 43), Pair(46, 100), Pair(141, 174), Pair(89, 280), Pair(0, 0)
};

constexpr RankTable<ScorePair> kDefendedPawnBonus = {
  Pair(0, 0), Pair(0, 0), Pair(5, -8), Pair(3, 19), Pair(18, 33), Pair(61, 67), Pair(184, 125), Pair(0, 0)
};

constexpr FileTable<ScorePair> kDoubledPawnPenalty = {
  Pair(-34, -58), Pair(-17, -17), Pair(5, 6), Pair(-13, -12), Pair(-14, -7), Pair(-8, -10), Pair(-23, -1), Pair(-19, -48)
};

constexpr FileTable<ScorePair> kIsolatedPawnPenalty = {
  Pair(-4, -4), Pair(-10, -12), Pair(-12, -5), Pair(-6, -7), Pair(-1, -9), Pair(-1, -10), Pair(-9, -7), Pair(8, -8)
};

constexpr std::array<FileTable<ScorePair>, 2> kRookOnFileBonus = {{
  {
      Pair(2, -16), Pair(18, -17), Pair(24, -15), Pair(34, -13), Pair(39, -16), Pair(62, -19), Pair(49, -19), Pair(16, -12)
  },
  {
      Pair(-11, 3), Pair(-2, 1), Pair(8, -8), Pair(23, -7), Pair(15, -9), Pair(28, -18), Pair(39, -19), Pair(-10, -5)
  }
}};

constexpr std::array<ScorePair, 12> kPawnShelterTable = {
  Pair(21, -9), Pair(37, -10), Pair(28, -9),
  Pair(44, -11), Pair(48, -16), Pair(45, -14),
  Pair(63, -1), Pair(0, 0), Pair(57, 0),
  Pair(37, 24), Pair(17, 17), Pair(45, 22)
};

constexpr std::array<ScorePair, 21> kPawnStormTable = {
  Pair(-6, -3), Pair(-17, 9), Pair(-5, -2),
  Pair(-5, -4), Pair(-19, 1), Pair(-4, -5),
  Pair(-2, -11), Pair(-7, -8), Pair(4, -14),
  Pair(15, -15), Pair(4, -13), Pair(24, -17),
  Pair(69, -25), Pair(71, -24), Pair(71, -28),
  Pair(71, -30), Pair(-27, -62), Pair(12, -32),
  Pair(58, -79), Pair(0, 0), Pair(76, -84)
};

constexpr std::array<ScorePair, 8> kKingPPDistanceTable = {
  Pair(0, 0), Pair(1, 85), Pair(-13, 76), Pair(-3, 60), Pair(4, 50), Pair(3, 41), Pair(11, 35), Pair(12, 30)
};

constexpr std::array<ScorePair, 8> kEnemyKingPPDistanceTable = {
  Pair(0, 0), Pair(-11, 0), Pair(-21, 26), Pair(-4, 50), Pair(-2, 62), Pair(12, 66), Pair(11, 76), Pair(10, 85)
};

constexpr ScorePair kKingCantReachPPBonus = Pair(-482, 106);

constexpr std::array<FileTable<ScorePair>, 2> kKingOnFilePenalty = {{
  {
      Pair(-43, -58), Pair(-7, -30), Pair(-20, -17), Pair(-66, -4), Pair(-38, 0), Pair(-41, 1), Pair(-16, -2), Pair(-28, -28)
  },
  {
      Pair(-37, 14), Pair(5, 17), Pair(-4, 14), Pair(-46, 25), Pair(-20, 19), Pair(-32, 20), Pair(4, 19), Pair(-18, 7)
  }
}};

constexpr PieceTable<std::array<ScorePair, 8>> kAttackPower = {{
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(25, 2), Pair(43, -5), Pair(111, -28), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(12, 1), Pair(37, -3), Pair(73, -13), Pair(94, -23), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(26, -11), Pair(45, -12), Pair(71, -11), Pair(124, -22), Pair(176, -40), Pair(0, 0), Pair(0, 0)
  },
  {
      Pair(0, 0), Pair(9, 23), Pair(27, 53), Pair(51, 69), Pair(121, 54), Pair(167, 59), Pair(291, 10), Pair(371, 10)
  },
  {
      Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0), Pair(0, 0)
  }
}};

constexpr PieceTable<ScorePair> kSafeCheckBonus = {
  Pair(0, 0), Pair(37, 2), Pair(9, 2), Pair(32, -3), Pair(19, 19), Pair(0, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByPawnPenalty = {{
  {
      Pair(5, 30), Pair(13, 35)
  },
  {
      Pair(-44, 4), Pair(-33, -19)
  },
  {
      Pair(-42, -18), Pair(-47, -38)
  },
  {
      Pair(-77, 59), Pair(-57, 22)
  },
  {
      Pair(-51, 48), Pair(-55, 1)
  },
  {
      Pair(2, 27), Pair(-34, 30)
  }
}};

constexpr PieceTable<ScorePair> kPawnPushThreat = {
  Pair(0, 0), Pair(13, 30), Pair(7, 34), Pair(15, 30), Pair(11, 13), Pair(11, 0)
};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByKnightPenalty = {{
  {
      Pair(-8, -30), Pair(2, -11)
  },
  {
      Pair(-22, -23), Pair(-11, -39)
  },
  {
      Pair(-28, -41), Pair(-28, -60)
  },
  {
      Pair(-61, -19), Pair(-46, -43)
  },
  {
      Pair(-45, -38), Pair(-44, -29)
  },
  {
      Pair(-73, -23), Pair(-25, -62)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByBishopPenalty = {{
  {
      Pair(-9, -20), Pair(1, -2)
  },
  {
      Pair(-36, -32), Pair(-21, -51)
  },
  {
      Pair(-5, -40), Pair(-8, -43)
  },
  {
      Pair(-61, -19), Pair(-42, -43)
  },
  {
      Pair(-50, -14), Pair(-33, -59)
  },
  {
      Pair(11, -16), Pair(-4, -18)
  }
}};

constexpr PieceTable<std::array<ScorePair, 2>> kThreatenedByRookPenalty = {{
  {
      Pair(-3, -16), Pair(4, 4)
  },
  {
      Pair(-31, -21), Pair(-1, -10)
  },
  {
      Pair(-24, -22), Pair(-5, -4)
  },
  {
      Pair(7, -41), Pair(5, -43)
  },
  {
      Pair(-51, -13), Pair(-33, -34)
  },
  {
      Pair(15, -39), Pair(-25, -37)
  }
}};

constexpr OutpostTable<ScorePair> kKnightOutpostTable = {
  Pair(3, 49), Pair(51, 7), Pair(10, 43), Pair(4, 30), Pair(20, 24), Pair(46, 19), Pair(60, 33), Pair(77, 58),
  Pair(14, 19), Pair(10, 14), Pair(18, 47), Pair(20, 30), Pair(8, 26), Pair(15, 26), Pair(4, 36), Pair(48, 50),
  Pair(-3, 28), Pair(-21, 19), Pair(2, 25), Pair(11, 23), Pair(-9, 27), Pair(5, 29), Pair(-9, 13), Pair(-5, 36)
};

constexpr OutpostTable<ScorePair> kBishopOutpostTable = {
  Pair(-35, 14), Pair(33, -6), Pair(7, 14), Pair(23, -5), Pair(14, -19), Pair(40, -23), Pair(73, 10), Pair(-39, -14),
  Pair(-32, 21), Pair(25, 6), Pair(-3, 30), Pair(18, 39), Pair(7, 18), Pair(-6, 24), Pair(27, -8), Pair(43, 11),
  Pair(34, 26), Pair(2, 20), Pair(17, 11), Pair(-9, 23), Pair(-25, 4), Pair(12, 20), Pair(0, -24), Pair(-2, 37)
};

constexpr ScorePair kBishopPairBonus = Pair(23, 83);

constexpr ScorePair kTempoBonus = Pair(22, 22);

constexpr std::array<int, kNumPieceTypes> kPhaseIncrements = {0, 1, 1, 2, 4, 0};
// clang-format on

}  // namespace eval

#endif  // INTEGRAL_TERMS_H