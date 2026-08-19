#include "threat_accumulator.h"

#include "threats/threat_features.h"

namespace nnue {

std::optional<std::span<I8, ThreatFeaturePolicy::kWidth>>
ThreatFeaturePolicy::FeatureRow(Color perspective,
                                Square king_square,
                                PieceType attacker,
                                Color attacker_color,
                                PieceType victim,
                                Color victim_color,
                                Square from,
                                Square to) {
  if (perspective == Color::kBlack) {
    attacker_color = FlipColor(attacker_color);
    victim_color = FlipColor(victim_color);
    from = from ^ 0b111000;
    to = to ^ 0b111000;
  }

  // Horizontal mirroring
  if (king_square.File() >= kFileE) {
    from = from ^ 0b111;
    to = to ^ 0b111;
  }

  const auto feature_idx = threats::get_threat_feature_index(
      attacker, attacker_color, victim, victim_color, from, to);
  if (!feature_idx) {
    return std::nullopt;
  }
  return network->threat_weights[feature_idx.value()].as_array();
}

void ThreatPerspectiveAccumulator::ApplyChange(
    const ThreatPerspectiveAccumulator& previous,
    const ThreatAccumulatorChange& change,
    Color perspective,
    Square king_square) {
  std::array<Value const*, ThreatAccumulatorChange::kMaxThreatRows> add_rows;
  U16 num_add = 0;
  std::array<Value const*, ThreatAccumulatorChange::kMaxThreatRows> sub_rows;
  U16 num_sub = 0;

  for (int i = 0; i < change.adds.Size(); ++i) {
    const auto& add = change.adds[i];
    const auto row = ThreatFeaturePolicy::FeatureRow(perspective,
                                                     king_square,
                                                     add.attacker_type,
                                                     add.attacker_color,
                                                     add.victim_type,
                                                     add.victim_color,
                                                     add.attacker_square,
                                                     add.victim_square);
    if (row) {
      add_rows[num_add++] = row.value().data();
    }
  }
  for (int i = 0; i < change.subs.Size(); ++i) {
    const auto& sub = change.subs[i];
    const auto row = ThreatFeaturePolicy::FeatureRow(perspective,
                                                     king_square,
                                                     sub.attacker_type,
                                                     sub.attacker_color,
                                                     sub.victim_type,
                                                     sub.victim_color,
                                                     sub.attacker_square,
                                                     sub.victim_square);
    if (row) {
      sub_rows[num_sub++] = row.value().data();
    }
  }

  ApplyDeltas(previous, add_rows.data(), num_add, sub_rows.data(), num_sub);
}

}  // namespace nnue