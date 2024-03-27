#include "transpo.h"
#include "eval.h"

TranspositionTable::TranspositionTable(std::size_t mb_size) : table_size_(mb_size) {
  resize(mb_size);
}

void TranspositionTable::resize(std::size_t mb_size) {
  assert(mb_size > 0);

  const std::size_t kBytesInMegabyte = 1024 * 1024;

  table_size_ = (mb_size * kBytesInMegabyte) / sizeof(Entry);
  table_.resize(table_size_ + 1);

  clear();
}

void TranspositionTable::clear() {
  std::ranges::fill(table_, Entry{});
}

void TranspositionTable::save(const Entry &entry, int ply) {
  // typically as the search progresses, other factors that influence the move ordering like counter moves, history, killers, etc are improved
  // therefore, we cannot simply trust a higher depth search as being a better reflection of the evaluation, and we give some lenience for the replacement strategy
  const int kDepthLenience = 4;

  auto &table_entry = table_[entry.key % table_size_];
  if (table_entry.key != entry.key || table_entry.depth <= entry.depth + kDepthLenience || entry.flag == Entry::kExact) {
    table_entry = entry;

    const int kRoughlyMate = -eval::kMateScore + kMaxGameMoves;
    if (entry.score <= kRoughlyMate) {
      table_entry.score -= ply;
    } else if (entry.score >= -kRoughlyMate) {
      table_entry.score += ply;
    }
  }
}

int TranspositionTable::correct_score(int score, int ply) const {
  const int kRoughlyMate = -eval::kMateScore + kMaxGameMoves;
  if (score <= kRoughlyMate) {
    score += ply;
  } else if (score >= -kRoughlyMate) {
    score -= ply;
  }

  return score;
}

const TranspositionTable::Entry &TranspositionTable::probe(const U64 &key) const {
  return table_[key % table_size_];
}