#ifndef INTEGRAL_CACHE_H
#define INTEGRAL_CACHE_H

#include "types.h"

template <typename T>
class HashTable {
 public:
  explicit HashTable(std::size_t mb_size) {
    Resize(mb_size);
  }

  HashTable() = default;

  void Resize(std::size_t mb_size) {
    assert(mb_size > 0);

    constexpr std::size_t kBytesInMegabyte = 1024 * 1024;
    mb_size *= kBytesInMegabyte;

    table_.resize(mb_size / sizeof(T));

    Clear();
  }

  void Clear() {
    std::ranges::fill(table_, T{});
  }

  T &operator[](const U64 &key) {
    return table_[Index(key)];
  }

  void Prefetch(const U64 &key) {
    auto &entry = (*this)[key];
    __builtin_prefetch(&entry);
  }

 private:
  [[nodiscard]] virtual U64 Index(const U64 &key) const {
    return (static_cast<U128>(key) * static_cast<U128>(table_.size())) >> 64;
  }

 private:
  std::vector<T> table_;
};

#endif  // INTEGRAL_CACHE_H