#include "psqt_accumulator.h"

namespace nnue {

std::span<PsqtFeaturePolicy::Weight, PsqtFeaturePolicy::kWidth>
PsqtFeaturePolicy::FeatureRow(Square square,
                              Square king_square,
                              PieceType piece,
                              Color piece_color,
                              Color perspective) {
  if (king_square.File() >= kFileE) {
    square = square ^ 0b111;
  }
  const int relative_king_square = king_square ^ (0b111000 * perspective);
  const int king_bucket_idx = kKingBucketMap[relative_king_square];
  const int square_idx = square ^ 0b111000 * perspective;
  const int color_idx = perspective != piece_color;
  const int piece_idx = piece;
  return network
      ->feature_weights[king_bucket_idx][color_idx][piece_idx][square_idx]
      .as_array();
}

PsqtPerspectiveAccumulator::Weight const*
PsqtPerspectiveAccumulator::GetFeaturePointer(Square square,
                                              Square king_square,
                                              PieceType piece,
                                              Color piece_color,
                                              Color perspective) {
  return PsqtFeaturePolicy::FeatureRow(
             square, king_square, piece, piece_color, perspective)
      .data();
}

void PsqtPerspectiveAccumulator::ApplyChange(
    const PsqtPerspectiveAccumulator& previous,
    const PsqtAccumulatorChange& change,
    Color perspective,
    Square king_square) {
  switch (change.type) {
    case PsqtAccumulatorChange::kNormal:
      ApplyChange<kAdd, kSub>(
          previous, perspective, king_square, change.add_0, change.sub_0);
      break;
    case PsqtAccumulatorChange::kCapture:
      ApplyChange<kAdd, kSub, kSub>(previous,
                                    perspective,
                                    king_square,
                                    change.add_0,
                                    change.sub_0,
                                    change.sub_1);
      break;
    case PsqtAccumulatorChange::kCastle:
      ApplyChange<kAdd, kAdd, kSub, kSub>(previous,
                                          perspective,
                                          king_square,
                                          change.add_0,
                                          change.add_1,
                                          change.sub_0,
                                          change.sub_1);
      break;
  }
}

}  // namespace nnue