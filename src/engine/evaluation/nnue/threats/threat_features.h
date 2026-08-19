#ifndef INTEGRAL_THREAT_FEATURES_H
#define INTEGRAL_THREAT_FEATURES_H

#include <optional>
#include <utility>
#include <vector>

#include "../../../../../shared/multi_array.h"
#include "../../../../../shared/nnue/definitions.h"
#include "../../../../chess/bitboard.h"
#include "../../../../utils/types.h"

namespace nnue::threats {

// Empty-board attack sets, generated here rather than through move_gen so that
// the tables below can be constexpr. move_gen's slider attacks read the magic
// tables, which are dynamically initialised in another translation unit; using
// them here would make these tables depend on static initialisation order and
// silently leave the slider entries zeroed.
namespace detail {

constexpr std::array<std::pair<int, int>, 8> kKnightDeltas = {
    {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}}};
constexpr std::array<std::pair<int, int>, 4> kDiagonalDeltas = {
    {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}}};
constexpr std::array<std::pair<int, int>, 4> kOrthogonalDeltas = {
    {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}};

[[nodiscard]] constexpr BitBoard AttacksOnEmptyBoard(Square square,
                                                     PieceType piece_type,
                                                     Color side) {
  const int rank = square.Rank(), file = square.File();
  BitBoard attacks;

  const auto step = [&](int rank_delta, int file_delta) {
    const int to_rank = rank + rank_delta, to_file = file + file_delta;
    if (to_rank >= 0 && to_rank < 8 && to_file >= 0 && to_file < 8) {
      attacks.SetBit(to_rank * 8 + to_file);
    }
  };
  const auto ray = [&](int rank_delta, int file_delta) {
    for (int to_rank = rank + rank_delta, to_file = file + file_delta;
         to_rank >= 0 && to_rank < 8 && to_file >= 0 && to_file < 8;
         to_rank += rank_delta, to_file += file_delta) {
      attacks.SetBit(to_rank * 8 + to_file);
    }
  };

  switch (piece_type) {
    case PieceType::kPawn: {
      const int forward = side == Color::kWhite ? 1 : -1;
      step(forward, -1), step(forward, 1);
      break;
    }
    case PieceType::kKnight:
      for (const auto [rank_delta, file_delta] : kKnightDeltas) {
        step(rank_delta, file_delta);
      }
      break;
    case PieceType::kBishop:
      for (const auto [rank_delta, file_delta] : kDiagonalDeltas) {
        ray(rank_delta, file_delta);
      }
      break;
    case PieceType::kRook:
      for (const auto [rank_delta, file_delta] : kOrthogonalDeltas) {
        ray(rank_delta, file_delta);
      }
      break;
    case PieceType::kQueen:
      for (const auto [rank_delta, file_delta] : kDiagonalDeltas) {
        ray(rank_delta, file_delta);
      }
      for (const auto [rank_delta, file_delta] : kOrthogonalDeltas) {
        ray(rank_delta, file_delta);
      }
      break;
    case PieceType::kKing:
      for (const auto [rank_delta, file_delta] : kDiagonalDeltas) {
        step(rank_delta, file_delta);
      }
      for (const auto [rank_delta, file_delta] : kOrthogonalDeltas) {
        step(rank_delta, file_delta);
      }
      break;
    default:
      break;
  }

  return attacks;
}

}  // namespace detail

// The index of each (attacker x victim) into the threat features
// Some pieces are excluded from each other to avoid duplicates (a value of -1),
// e.g. Queen x Rook
constexpr std::array kPieceTypeTargetMap = {
    std::array<I8, 6>{0, 1, -1, 2, -1, -1},
    std::array<I8, 6>{0, 1, 2, 3, 4, -1},
    std::array<I8, 6>{0, 1, 2, 3, -1, -1},
    std::array<I8, 6>{0, 1, 2, 3, -1, -1},
    std::array<I8, 6>{0, 1, 2, 3, 4, -1},
    std::array<I8, 6>{-1, -1, -1, -1, -1, -1},
};

// The total count of attacker x (victim x side) combinations for a certain
// piece type
constexpr auto kPieceTypeTargetCount = ([]() {
  std::array<U8, PieceType::kNumPieceTypes> piece_target_count{};
  for (int piece_type_idx = 0; piece_type_idx < 6; ++piece_type_idx) {
    int count = 0;
    for (int target_idx = 0; target_idx < 6; ++target_idx) {
      count += kPieceTypeTargetMap[piece_type_idx][target_idx] != -1;
    }
    piece_target_count[piece_type_idx] = count * Color::kNumColors;
  }
  return piece_target_count;
})();

inline constexpr auto kPieceIndex = ([]() {
  MultiArray<U8, kNumPieces, Squares::kSquareCount, Squares::kSquareCount>
      piece_indices{};
  for (int piece = 0; piece < kNumPieces; ++piece) {
    const auto piece_type = TypeOf(static_cast<Piece>(piece));
    const auto side = ColorOf(static_cast<Piece>(piece));
    for (int from = 0; from < 64; ++from) {
      const BitBoard attack_bb =
          detail::AttacksOnEmptyBoard(from, piece_type, side);
      for (int to = 0; to < 64; ++to) {
        const BitBoard to_backward_bb = BitBoard::FromSquare(to) - 1;
        const U8 num_backward_attacks = (attack_bb & to_backward_bb).PopCount();
        piece_indices[piece][from][to] = num_backward_attacks;
      }
    }
  }
  return piece_indices;
})();

struct PieceOffsets {
  MultiArray<U32, kNumPieces, 2> indices;
  MultiArray<U32, kNumPieces, Squares::kSquareCount> offsets;
};

inline constexpr auto kPieceOffsets = ([]() {
  PieceOffsets piece_offsets{};
  U32 offset = 0;
  for (const auto side : {Color::kWhite, Color::kBlack}) {
    for (int piece_idx = 0; piece_idx < 6; ++piece_idx) {
      const auto piece_type = static_cast<PieceType>(piece_idx);
      // For each colored piece's possible square, we sum up all possible
      // attacked squares (assuming an empty occupancy). This gives us the
      // offset into the threat features of each attacking piece.
      U32 cur_piece_offset = 0;
      for (Square square = 0; square < 64; ++square) {
        piece_offsets.offsets[MakePiece(piece_type, side)][square] =
            cur_piece_offset;
        // Exclude pawns on first/last rank
        if (piece_type != PieceType::kPawn ||
            (square.Rank() != Rank::kRank1 && square.Rank() != Rank::kRank8)) {
          cur_piece_offset +=
              detail::AttacksOnEmptyBoard(square, piece_type, side).PopCount();
        }
      }

      // At this point, 'cur_piece_offset' is the sum of all attacks from all
      // squares for this colored piece.
      piece_offsets.indices[MakePiece(piece_type, side)] = {cur_piece_offset,
                                                            offset};
      // 'offset' is a global index into the threat features array, based on
      // the number of allowed (attacker x victim) combinations multiplied by
      // the summed attacking squares.
      offset += kPieceTypeTargetCount[piece_idx] * cur_piece_offset;
    }
  }
  return piece_offsets;
})();

inline constexpr auto kAttackTable = ([]() {
  MultiArray<U32, kNumPieces, kNumPieces, 2> attack_table;
  attack_table.fill(nnue::arch::kThreatFeatureCount);
  for (int attacker = 0; attacker < kNumPieces; ++attacker) {
    const auto attacker_piece_idx = TypeOf(static_cast<Piece>(attacker));
    const auto attacker_side = ColorOf(static_cast<Piece>(attacker));
    for (int victim = 0; victim < kNumPieces; ++victim) {
      const auto victim_piece_idx = TypeOf(static_cast<Piece>(victim));
      const auto victim_side = ColorOf(static_cast<Piece>(victim));

      const bool is_opposed = attacker_side != victim_side;
      const auto target_map =
          kPieceTypeTargetMap[attacker_piece_idx][victim_piece_idx];
      const bool is_semi_excluded =
          attacker_piece_idx == victim_piece_idx &&
          (is_opposed || attacker_piece_idx != PieceType::kPawn);
      const bool is_fully_excluded = target_map == -1;

      const auto [piece_offset, offset] =
          kPieceOffsets.indices[attacker].as_array();
      const auto color_stride =
          kPieceTypeTargetCount[attacker_piece_idx] / 2 * victim_side;

      const auto feature = offset + (color_stride + target_map) * piece_offset;
      if (!is_fully_excluded) {
        attack_table[attacker][victim][0] = feature;
        if (!is_semi_excluded) {
          attack_table[attacker][victim][1] = feature;
        }
      }
    }
  }
  return attack_table;
})();

// The row this threat maps to. A pair with no feature lands at or above
// kThreatFeatureCount rather than reporting failure separately, so callers can
// test the result instead of branching inside the lookup.
[[nodiscard]] inline U32 get_threat_feature_index(Piece attacker,
                                                  Piece victim,
                                                  Square from,
                                                  Square to) {
  const bool is_forward_move = from < to;
  const auto attack_index = kAttackTable[attacker][victim][is_forward_move];
  const auto offset = kPieceOffsets.offsets[attacker][from];
  const auto piece_idx = kPieceIndex[attacker][from][to];
  return attack_index + offset + piece_idx;
}

}  // namespace nnue::threats

#endif  // INTEGRAL_THREAT_FEATURES_H
