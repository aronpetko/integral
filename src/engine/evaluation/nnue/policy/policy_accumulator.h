#ifndef INTEGRAL_POLICY_ACCUMULATOR_H
#define INTEGRAL_POLICY_ACCUMULATOR_H

#include "../../../../../shared/nnue/definitions.h"
#include "../../../../../shared/simd.h"
#include "../../../../chess/board.h"
#include "../nnue.h"
#include "../psqt_accumulator.h"

namespace nnue::policy {

class PolicyAccumulator {
 public:
  static constexpr int kWidth = arch::policy::kL1Size;
  using Vector = simd::Vector<I16, kWidth>;

  void Refresh(const BoardState& state, Color perspective);

  void ApplyChange(const PolicyAccumulator& previous,
                   const PsqtAccumulatorChange& change,
                   Color perspective,
                   Square king_square);

  [[nodiscard]] const Vector& Values() const {
    return values_;
  }

 private:
  [[nodiscard]] static Vector Row(const FeatureData& feature,
                                  Color perspective,
                                  Square king_square);

  Vector values_;
};

}  // namespace nnue::policy

#endif  // INTEGRAL_POLICY_ACCUMULATOR_H
