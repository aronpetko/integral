#ifndef INTEGRAL_CACHE_H
#define INTEGRAL_CACHE_H

#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

#include "types.h"

#if defined(__linux__)
#include <sys/mman.h>
#endif

inline void* alligned_alloc(size_t alignment, size_t bytes) {
  void* ptr;
#if defined(__MINGW32__)
  int offset = alignment - 1;
  void* p = reinterpret_cast<void*>(malloc(bytes + offset));
  ptr = reinterpret_cast<void*>((reinterpret_cast<std::size_t>(p) + offset) &
                                ~(alignment - 1));
#elif defined(__GNUC__)
  ptr = std::aligned_alloc(alignment, bytes);
#else
  ptr = std::malloc(bytes);
#endif

#if defined(__linux__)
  madvise(ptr, bytes, MADV_HUGEPAGE);
#endif

  return ptr;
}

template <typename T>
class AlignedHashTable {
 public:
  explicit AlignedHashTable(std::size_t mb_size) {
    Resize(mb_size);
  }

  AlignedHashTable() : table_(nullptr), table_size_(0) {}

  ~AlignedHashTable() {
    if (table_) {
      std::free(table_);
    }
  }

  void Resize(std::size_t mb_size) {
    assert(mb_size > 0);

    constexpr std::size_t kBytesInMegabyte = 1024 * 1024;
    mb_size *= kBytesInMegabyte;

    std::size_t num_elements = mb_size / sizeof(T);
    std::size_t alignment = sizeof(T);

    const auto new_table =
        static_cast<T*>(alligned_alloc(alignment, num_elements * sizeof(T)));

    if (table_) {
      std::free(table_);
    }

    table_ = new_table;
    table_size_ = num_elements;

    Clear();
  }

  void Clear() {
    std::fill_n(table_, table_size_, T{});
  }

  T& operator[](const U64& key) {
    return table_[Index(key)];
  }

  virtual void Prefetch(const U64& key) {
    auto& entry = (*this)[key];
    __builtin_prefetch(&entry);
  }

 private:
  [[nodiscard]] virtual U64 Index(const U64& key) const {
    return (static_cast<U128>(key) * static_cast<U128>(table_size_)) >> 64;
  }

 protected:
  T* table_ = nullptr;
  std::size_t table_size_ = 0;
};

template <typename T>
class UnalignedHashTable {
 public:
  explicit UnalignedHashTable(std::size_t mb_size) {
    Resize(mb_size);
  }

  UnalignedHashTable() : table_size_(0) {}

  void Resize(std::size_t mb_size) {
    assert(mb_size > 0);

    constexpr std::size_t kBytesInMegabyte = 1024 * 1024;
    mb_size *= kBytesInMegabyte;

    std::size_t num_elements = mb_size / sizeof(T);

    table_.resize(num_elements);
    table_size_ = num_elements;

    Clear();
  }

  void Clear() {
    std::fill(table_.begin(), table_.end(), T{});
  }

  T& operator[](const U64& key) {
    return table_[Index(key)];
  }

  virtual void Prefetch(const U64& key) {
    auto& entry = (*this)[key];
    __builtin_prefetch(&entry);
  }

 private:
  [[nodiscard]] virtual U64 Index(const U64& key) const {
    return (static_cast<U128>(key) * static_cast<U128>(table_size_)) >> 64;
  }

 private:
  std::vector<T> table_;
  std::size_t table_size_ = 0;
};

#endif  // INTEGRAL_CACHE_H