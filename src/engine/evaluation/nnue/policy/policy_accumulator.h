#ifndef INTEGRAL_POLICY_ACCUMULATOR_H
#define INTEGRAL_POLICY_ACCUMULATOR_H

#include "../../../../../shared/nnue/definitions.h"
#include "../../../../../shared/simd.h"
#include "../../../../chess/board.h"
#include "../nnue.h"

namespace nnue::policy {

class PolicyAccumulator {
 public:
  static constexpr int kWidth = arch::policy::kL1Size;
  using Vector = simd::Vector<I16, kWidth>;

  void Refresh(const BoardState& state);

  [[nodiscard]] int UpdateCost(const BoardState& state) const;

  void Update(const BoardState& state);

  [[nodiscard]] bool IsAt(const BoardState& state) const {
    return valid_ && key_ == state.zobrist_key;
  }

  [[nodiscard]] const Vector& Values() const {
    return values_;
  }

 private:
  [[nodiscard]] BitBoard ChangedSquares(const BoardState& state) const;

  Vector values_;
  std::array<BitBoard, kNumPieceTypes> piece_bbs_;
  std::array<BitBoard, 2> side_bbs_;
  std::array<BitBoard, 2> threats_;
  U64 key_ = 0;
  Color turn_ = Color::kWhite;
  bool mirror_ = false;
  bool valid_ = false;
};

}  // namespace nnue::policy

#endif  // INTEGRAL_POLICY_ACCUMULATOR_H
