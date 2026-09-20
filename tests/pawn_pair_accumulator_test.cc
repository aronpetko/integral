// Standalone regression test; compile with the engine's threat, pawn-pair,
// move_gen and magics/attacks translation units (no trained network needed).
#include "src/engine/evaluation/nnue/threat_accumulator.h"
#include "src/engine/evaluation/nnue/threats/threat_features.h"
#include <cassert>
#include <iostream>
#include <memory>
#include <random>
#include <set>
#include <string_view>

BoardState Parse(std::string_view fen) {
  BoardState state;
  int rank = 7, file = 0;
  for (char ch : fen) {
    if (ch == '/') { --rank; file = 0; continue; }
    if (ch >= '1' && ch <= '8') { file += ch - '0'; continue; }
    const bool white = ch >= 'A' && ch <= 'Z';
    const char lower = white ? ch + 'a' - 'A' : ch;
    const auto type = static_cast<PieceType>(std::string_view("pnbrqk").find(lower));
    state.PlacePiece<false>(rank * 8 + file++, type, white ? kWhite : kBlack);
  }
  return state;
}

std::size_t OracleIndex(Square a, Color ca, Square b, Color cb, Color view, Square king) {
  const auto id = [&](Square sq, Color color) {
    int rank = sq.Rank(), file = sq.File();
    if (view == kBlack) rank = 7 - rank;
    if (king.File() >= kFileE) file = 7 - file;
    return (color == view ? 0 : 48) + 8 * rank + file - 8;
  };
  const int x = id(a, ca), y = id(b, cb);
  return std::max(x, y) * (std::max(x, y) - 1) / 2 + std::min(x, y);
}

std::set<std::size_t> Pairs(const BoardState& state, Color view, Square king) {
  std::set<std::size_t> result;
  for (Square a : state.Pawns()) for (Square b : state.Pawns()) {
    if (a < b && std::abs(int(a.File()) - int(b.File())) <= 1)
      result.insert(OracleIndex(a, state.GetPieceColor(a), b, state.GetPieceColor(b), view, king));
  }
  return result;
}

void Check(const BoardState& before, const BoardState& after) {
  BitBoard changed;
  for (Square sq = 0; sq < 64; ++sq) {
    if (before.GetPieceType(sq) != after.GetPieceType(sq) ||
        (before.GetPieceType(sq) != kNone && before.GetPieceColor(sq) != after.GetPieceColor(sq)))
      changed |= BitBoard::FromSquare(sq);
  }
  nnue::ThreatAccumulatorChange change;
  change.UpdateThreatsForSquares<false>(before, changed);
  change.UpdateThreatsForSquares<true>(after, changed);
  // Threat discovery must no longer generate pawn pairs.
  assert(change.pawn_pair_adds.Empty() && change.pawn_pair_subs.Empty());
  change.UpdatePawnPairsForSquares<false>(before, changed);
  change.UpdatePawnPairsForSquares<true>(after, changed);
  for (Color view : {kWhite, kBlack}) {
    const Square old_king = (before.Kings() & before.side_bbs[view]).GetLsb();
    const Square king = (after.Kings() & after.side_bbs[view]).GetLsb();
    std::set<std::size_t> actual;
    nnue::ThreatFeaturePolicy::ForEachActiveFeature(after, view, king, [&](const I8* row, bool valid) {
      if (!valid) return;
      const auto idx = (row - nnue::network->threat_weights[0].as_array().data()) / nnue::arch::kL1Size;
      if (idx < nnue::arch::kPawnPairFeatureCount) assert(actual.insert(idx).second);
    });
    assert(actual == Pairs(after, view, king));
    // Verify pair deltas independently, including capture deduplication.
    auto pairs = Pairs(before, view, king);
    for (int i = 0; i < change.pawn_pair_subs.Size(); ++i) {
      auto p = change.pawn_pair_subs[i];
      assert(pairs.erase(OracleIndex(p.pawn_square, p.pawn_color, p.paired_pawn_square, p.paired_pawn_color, view, king)) == 1);
    }
    for (int i = 0; i < change.pawn_pair_adds.Size(); ++i) {
      auto p = change.pawn_pair_adds[i];
      assert(pairs.insert(OracleIndex(p.pawn_square, p.pawn_color, p.paired_pawn_square, p.paired_pawn_color, view, king)).second);
    }
    assert(pairs == actual);
    nnue::ThreatPerspectiveAccumulator old, updated, refreshed;
    old.Refresh(before, view, old_king);
    refreshed.Refresh(after, view, king);
    if ((old_king.File() >= kFileE) != (king.File() >= kFileE)) {
      updated.Refresh(after, view, king);
    } else {
      updated.ApplyChange(old, change, view, king);
    }
    for (int i = 0; i < nnue::arch::kL1Size; ++i) assert(updated[i] == refreshed[i]);
  }
}

int main() {
  static_assert(nnue::threats::kPieceOffsets.indices[kKing][kBlack][1] == nnue::arch::kThreatFeatureCount);
  auto net = std::make_unique<nnue::Network>();
  nnue::network = net.get();
  const auto [threat, valid] = nnue::ThreatFeaturePolicy::FeatureRow(
      kWhite, Squares::kC1, kKnight, kWhite, kPawn, kBlack, Squares::kB1, Squares::kC3);
  const auto [index, expected_valid] = nnue::threats::GetThreatFeatureIndex(
      kKnight, kWhite, kPawn, kBlack, Squares::kB1, Squares::kC3);
  assert(valid && expected_valid);
  assert(threat == net->threat_weights[nnue::arch::kPawnPairFeatureCount + index].as_array().data());
  std::mt19937 rng(12345);
  for (std::size_t row = 0; row < nnue::arch::kThreatPawnPairFeatureCount; ++row)
    for (auto& weight : net->threat_weights[row].as_array()) weight = int(rng() % 15) - 7;
  for (Color view : {kWhite, kBlack}) for (Square king : {Squares::kC1, Squares::kF8})
    for (Color ca : {kWhite, kBlack}) for (Color cb : {kWhite, kBlack})
      for (Square a = 8; a < 56; ++a) for (Square b = 8; b < 56; ++b) {
        if (a == b) continue;
        assert(nnue::pawn_pair::GetPawnPairIndex(a, ca, b, cb, view, king) == OracleIndex(a, ca, b, cb, view, king));
      }
  const std::pair<std::string_view, std::string_view> cases[] = {
    // Double push, capture, en passant, promotion, capture-promotion.
    {"4k3/pp6/8/8/8/8/PP6/4K3", "4k3/pp6/8/8/P7/8/1P6/4K3"},
    {"4k3/8/2p5/3p4/4P3/5P2/8/4K3", "4k3/8/2p5/3P4/8/5P2/8/4K3"},
    {"4k3/8/2p5/3pP3/8/5P2/8/4K3", "4k3/8/2pP4/8/8/5P2/8/4K3"},
    {"4k3/Pp6/8/8/8/8/1P6/4K3", "Q3k3/1p6/8/8/8/8/1P6/4K3"},
    {"1r2k3/Pp6/8/8/8/8/1P6/4K3", "1N2k3/1p6/8/8/8/8/1P6/4K3"},
    // Non-pawn capture of pawn; knight move; king mirror crossing; castling.
    {"4k3/8/8/8/R2p4/2P5/8/4K3", "4k3/8/8/8/3R4/2P5/8/4K3"},
    {"4k3/pp6/8/8/8/8/PP6/1N2K3", "4k3/pp6/8/8/8/2N5/PP6/4K3"},
    {"4k3/pp6/8/8/8/8/PP6/3K4", "4k3/pp6/8/8/8/8/PP6/4K3"},
    {"4k3/pp6/8/8/8/8/PP6/R3K2R", "4k3/pp6/8/8/8/8/PP6/R4RK1"},
    {"4k3/8/8/8/8/8/8/4K3", "4k3/8/8/8/8/8/8/4K3"},
  };
  for (auto [a, b] : cases) {
    Check(Parse(a), Parse(b));
    Check(Parse(b), Parse(a)); // reverse deltas
  }
  std::cout << "Pawn indices, pair refresh, and forward/reverse accumulator deltas passed (10 cases, both perspectives).\n";
}
