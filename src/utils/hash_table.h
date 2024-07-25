#ifndef INTEGRAL_CACHE_H
#define INTEGRAL_CACHE_H

#include <cassert>
#include <cstdlib>
#include <cstring>

#include "types.h"

#if defined(__linux__)
#include <sys/mman.h>
#endif

inline void* aligned_alloc(std::size_t alignment, std::size_t bytes) {
  void* ptr = nullptr;
#if defined(__MINGW32__)
  int offset = alignment - 1;
  void* p = std::malloc(bytes + offset);
  if (p) {
    ptr = reinterpret_cast<void*>((reinterpret_cast<std::size_t>(p) + offset) &
                                  ~(alignment - 1));
  }
#elif defined(__GNUC__)
  ptr = std::aligned_alloc(alignment, bytes);
#else
  throw std::runtime_error("Compiler not supported");
#endif

  if (!ptr) {
    throw std::bad_alloc();
  }

#if defined(__linux__)
  madvise(ptr, bytes, MADV_HUGEPAGE);
#endif

  return ptr;
}

template <typename T>
class HashTable {
 public:
  explicit HashTable(std::size_t mb_size) : table_(nullptr), table_size_(0) {
    Resize(mb_size);
  }

  HashTable() : table_(nullptr), table_size_(0) {}

  ~HashTable() {
    if (table_) {
      std::free(table_);
    }
  }

  void Resize(std::size_t mb_size) {
    assert(mb_size > 0);

    constexpr std::size_t kBytesInMegabyte = 1024 * 1024;
    mb_size *= kBytesInMegabyte;

    // Calculate the number of elements and the alignment requirement
    size_t num_elements = mb_size / sizeof(T);
    size_t alignment = alignof(T);

    // Free the old memory if allocated
    if (table_) {
      std::free(table_);
    }

    // Allocate aligned memory
    table_ =
        static_cast<T*>(aligned_alloc(alignment, num_elements * sizeof(T)));
    if (!table_) {
      throw std::bad_alloc();
    }

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

 private:
  T* table_;
  std::size_t table_size_;
};

#endif  // INTEGRAL_CACHE_H
