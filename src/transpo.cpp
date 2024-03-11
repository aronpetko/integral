#include "transpo.h"
#include "eval.h"

#include <cstring>

TranspositionTable::TranspositionTable(std::size_t mb_size) : table_(nullptr), table_size_(mb_size) {
  resize(mb_size);
}

void TranspositionTable::resize(std::size_t mb_size) {
  assert(mb_size > 0);

  std::free(table_);

  const std::size_t kBytesInMegabyte = 1024 * 1024;
  const std::size_t table_byte_size = mb_size * kBytesInMegabyte * sizeof(Entry);

  table_ = reinterpret_cast<Entry*>(std::malloc(table_byte_size));
  table_size_ = table_byte_size / sizeof(Entry) - 1;

  clear();
}

void TranspositionTable::clear() {
  std::memset(table_, 0, (table_size_ + 1) * sizeof(Entry));
}

void TranspositionTable::save(const Entry &entry, int ply) {
  auto &table_entry = table_[entry.key % table_size_];
  table_entry = entry;

  const int kRoughlyMate = -eval::kMateScore + 1000;
  if (entry.evaluation <= kRoughlyMate) {
    table_entry.evaluation += ply;
  } else if (entry.evaluation >= -kRoughlyMate) {
    table_entry.evaluation -= ply;
  }
}

const TranspositionTable::Entry *TranspositionTable::probe(U64 key) const {
  return &table_[key % table_size_];
}