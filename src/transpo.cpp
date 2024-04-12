#include "transpo.h"
#include "eval.h"

TranspositionTable::TranspositionTable(std::size_t mb_size) : table_size_(mb_size) {
  resize(mb_size);
}

void TranspositionTable::resize(std::size_t mb_size) {
  assert(mb_size > 0);

  const std::size_t kBytesInMegabyte = 1024 * 1024;
  table_size_ = mb_size * kBytesInMegabyte / sizeof(Entry);
  table_.resize(table_size_);

  clear();
}

void TranspositionTable::clear() {
  std::ranges::fill(table_, Entry{});
}

void TranspositionTable::save(const U64 &key, const Entry &entry, int ply) {
  // typically as the search progresses, other factors that influence the move ordering like counter moves, history, killers, etc are improved
  // therefore, we cannot simply trust a higher depth search as being a better reflection of the evaluation, and we give some lenience for the replacement strategy
  const int kDepthLenience = 4;

  auto &table_entry = table_[index(key)];
  if (table_entry.key != entry.key || table_entry.depth <= entry.depth + kDepthLenience || entry.flag == Entry::kExact) {
    const auto old_tt_move = table_entry.move;
    table_entry = entry;

    // restore the tt move if we're saving a tt entry from a null move
    if (!entry.move) {
      table_entry.move = old_tt_move;
    }

    const int kRoughlyMate = -eval::kMateScore + kMaxPlyFromRoot;
    if (entry.score <= kRoughlyMate) {
      table_entry.score -= ply;
    } else if (entry.score >= -kRoughlyMate) {
      table_entry.score += ply;
    }
  }
}

void TranspositionTable::prefetch(const U64 &key) const {
  __builtin_prefetch(&probe(key));
}

int TranspositionTable::correct_score(int score, int ply) const {
  const int kRoughlyMate = -eval::kMateScore + kMaxPlyFromRoot;
  if (score <= kRoughlyMate) {
    score += ply;
  } else if (score >= -kRoughlyMate) {
    score -= ply;
  }

  return score;
}

const TranspositionTable::Entry &TranspositionTable::probe(const U64 &key) const {
  return table_[index(key)];
}

U64 TranspositionTable::index(const U64 &key) const {
  return (static_cast<U128>(key) * static_cast<U128>(table_size_)) >> 64;
}