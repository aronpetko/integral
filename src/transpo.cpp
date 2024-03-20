#include "transpo.h"
#include "eval.h"

#include <cstring>

TranspositionTable::TranspositionTable(std::size_t mb_size) : table_size_(mb_size) {
  resize(mb_size);
}

void TranspositionTable::resize(std::size_t mb_size) {
  assert(mb_size > 0);

  const std::size_t kBytesInMegabyte = 1024 * 1024;

  table_size_ = (mb_size * kBytesInMegabyte) / sizeof(Entry);
  table_.resize(table_size_);

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
    if (entry.evaluation <= kRoughlyMate) {
      table_entry.evaluation -= ply;
    } else if (entry.evaluation >= -kRoughlyMate) {
      table_entry.evaluation += ply;
    }
  }
}

int TranspositionTable::correct_eval(int evaluation, int ply) const {
  const int kRoughlyMate = -eval::kMateScore + 1000;
  if (evaluation <= kRoughlyMate) {
    evaluation += ply;
  } else if (evaluation >= -kRoughlyMate) {
    evaluation -= ply;
  }

  return evaluation;
}

const TranspositionTable::Entry &TranspositionTable::probe(const U64 &key) const {
  return table_[key % table_size_];
}