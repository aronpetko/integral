#include "transpo.h"
#include <iostream>

TranspositionTable::TranspositionTable(int mb_size) : table_(nullptr), table_size_(mb_size) {
  resize(mb_size);
}

void TranspositionTable::resize(std::size_t mb_size) {
  assert(mb_size >= 0);

  std::free(table_);

  const std::size_t kBytesInMegabyte = 1048576;
  table_ = reinterpret_cast<Entry*>(std::malloc(mb_size * kBytesInMegabyte));
  std::memset(table_, 0, mb_size * kBytesInMegabyte);
  table_size_ = mb_size * kBytesInMegabyte / sizeof(Entry) - 1;
}

void TranspositionTable::clear() {
  std::memset(table_, 0, (table_size_ + 1) * sizeof(Entry));
}

void TranspositionTable::save(const Entry &entry) {
  auto &table_entry = table_[entry.key % table_size_];

  if (table_entry.key == 0ULL ||
      entry.key == table_entry.key && entry.depth >= table_entry.depth ||
      entry.flag == Entry::kExact && table_entry.flag != Entry::kExact) {
    table_entry = entry;
  }
}

const TranspositionTable::Entry *TranspositionTable::probe(U64 key) const {
  return &table_[key % table_size_];
}