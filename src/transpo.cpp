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
  std::fill(table_.begin(), table_.end(), Entry{});
}

void TranspositionTable::save(const Entry &entry, int ply) {
  auto &table_entry = table_[entry.key % table_size_];

  if (table_entry.depth <= entry.depth) {
    table_entry = entry;

    const int kRoughlyMate = -eval::kMateScore + 1000;
    if (entry.score <= kRoughlyMate) {
      table_entry.score -= ply;
    } else if (entry.score >= -kRoughlyMate) {
      table_entry.score += ply;
    }
  }
}

int TranspositionTable::correct_score(int score, int ply) const {
  const int kRoughlyMate = -eval::kMateScore + 1000;
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