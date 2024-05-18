#include "transpo.h"

#include "eval.h"
#include "search.h"

// When saving a TT entry, we usually want to prefer newer entries only if
// they've been searched deeper. This lenience allows a maximum of four
constexpr int kDepthLenience = 4;

TranspositionTable::TranspositionTable(std::size_t mb_size)
    : table_size_(mb_size), used_entries_(0) {
  Resize(mb_size);
}

void TranspositionTable::Resize(std::size_t mb_size) {
  assert(mb_size > 0);

  const std::size_t kBytesInMegabyte = 1024 * 1024;
  mb_size *= kBytesInMegabyte;

  table_size_ = mb_size / sizeof(Entry);
  table_.resize(table_size_);
  table_.shrink_to_fit();

  Clear();
}

void TranspositionTable::Clear() {
  std::ranges::fill(table_, Entry{});
}

void TranspositionTable::Save(const U64 &key, const Entry &entry, U16 ply) {
  auto &tt_entry = table_[Index(key)];
  const bool tt_hit = tt_entry.CompareKey(key);

  if (!tt_hit || entry.depth + kDepthLenience >= tt_entry.depth ||
      entry.flag == Entry::kExact) {
    const auto old_move = tt_entry.move;
    tt_entry = entry;

    // Keep the old move if there is no best move being saved and if the key
    // matches
    if (!entry.move && tt_hit) {
      tt_entry.move = old_move;
    }

    // The ply is negated here since we're saving this entry
    tt_entry.score = CorrectScore(entry.score, -ply);
  }
}

void TranspositionTable::Prefetch(const U64 &key) const {
  __builtin_prefetch(&Probe(key));
}

int TranspositionTable::CorrectScore(Score score, U16 ply) const {
  constexpr int kRoughlyMate = kMateScore - kMaxPlyFromRoot;
  if (score >= kRoughlyMate) {
    score -= ply;
  } else if (score <= -kRoughlyMate) {
    score += ply;
  }
  return score;
}

const TranspositionTable::Entry &TranspositionTable::Probe(
    const U64 &key) const {
  return table_[Index(key)];
}

U64 TranspositionTable::Index(const U64 &key) const {
  return (static_cast<U128>(key) * static_cast<U128>(table_size_)) >> 64;
}

int TranspositionTable::HashFull() const {
  return static_cast<int>(used_entries_ * 1000 / table_size_);
}