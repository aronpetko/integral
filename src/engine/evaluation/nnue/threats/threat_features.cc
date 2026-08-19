#include "threat_features.h"

namespace nnue::threats {

std::optional<U32> get_threat_feature_index(PieceType attacker,
                                            Color attacker_color,
                                            PieceType victim,
                                            Color victim_color,
                                            Square from,
                                            Square to) {
  const bool is_forward_move = from < to;
  const auto attack_index = kAttackTable[attacker][attacker_color][victim]
                                        [victim_color][is_forward_move];
  if (attack_index == nnue::arch::kThreatFeatureCount) {
    return std::nullopt;
  }

  const auto offset = kPieceOffsets.offsets[attacker][attacker_color][from];
  const auto piece_idx = kPieceIndex[attacker][attacker_color][from][to];
  return attack_index + offset + piece_idx;
}

}  // namespace nnue::threats