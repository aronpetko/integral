#include "transpo.h"

#include "eval.h"

TranspositionTable::TranspositionTable(std::size_t mb_size) : table_size_(mb_size), used_entries_(0) {
  resize(mb_size);
}

void TranspositionTable::resize(std::size_t mb_size) {
  assert(mb_size > 0);

  const std::size_t kBytesInMegabyte = 1024 * 1024;
  mb_size *= kBytesInMegabyte;

  table_size_ = mb_size / sizeof(Entry);
  table_.resize(table_size_);
  table_.shrink_to_fit();

  clear();
}

void TranspositionTable::clear() {
  std::ranges::fill(table_, Entry{});
}

void TranspositionTable::save(const U64 &key, const Entry &entry, int ply) {
  auto &tt_entry = table_[index(key)];
  if (!tt_entry.compare_key(key) || entry.depth >= tt_entry.depth || entry.flag == Entry::kExact) {
    const auto old_move = tt_entry.move;
    tt_entry = entry;

    // keep the old move if there is no best move being saved
    if (old_move && !entry.move) {
      tt_entry.move = old_move;
    }

    const int kRoughlyMate = eval::kMateScore - kMaxPlyFromRoot;
    if (tt_entry.score >= kRoughlyMate) {
      tt_entry.score += ply;
    } else if (tt_entry.score <= -kRoughlyMate) {
      tt_entry.score -= ply;
    }
  }
}

void TranspositionTable::prefetch(const U64 &key) const {
  __builtin_prefetch(&probe(key));
}

int TranspositionTable::correct_score(int score, int ply) const {
  const int kRoughlyMate = eval::kMateScore - kMaxPlyFromRoot;
  if (score >= kRoughlyMate) {
    score -= ply;
  } else if (score <= -kRoughlyMate) {
    score += ply;
  }
  return score;
}

const TranspositionTable::Entry &TranspositionTable::probe(const U64 &key) const {
  return table_[index(key)];
}

U64 TranspositionTable::index(const U64 &key) const {
  return (static_cast<U128>(key) * static_cast<U128>(table_size_)) >> 64;
}

int TranspositionTable::hash_full() const {
  return static_cast<int>(static_cast<double>(used_entries_) / table_size_ * 1000);
}