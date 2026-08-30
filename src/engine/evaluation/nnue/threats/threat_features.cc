#include "threat_features.h"

namespace nnue::threats {

std::pair<U32, bool> get_threat_feature_index(PieceType attacker,
                                              Color attacker_color,
                                              PieceType victim,
                                              Color victim_color,
                                              Square from,
                                              Square to) {
  const bool is_forward_move = from < to;
  const auto attack_index = kAttackTable[attacker][attacker_color][victim]
                                        [victim_color][is_forward_move];
  const auto offset = kPieceOffsets.offsets[attacker][attacker_color][from];
  const auto piece_idx = kPieceIndex[attacker][attacker_color][from][to];
  return {attack_index + offset + piece_idx,
          attack_index != nnue::arch::kThreatFeatureCount};
}

}  // namespace nnue::threats
