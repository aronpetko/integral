#ifndef INTEGRAL_CACHE_H
#define INTEGRAL_CACHE_H

#include <cassert>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <stdexcept>
#include <new>
#include "types.h"

#if defined(__linux__)
#include <sys/mman.h>
#endif

inline void* alignedAlloc(std::size_t alignment, std::size_t requiredBytes) {
  void* ptr = nullptr;
#if defined(__MINGW32__)
  int offset = alignment - 1;
  void* p = std::malloc(requiredBytes + offset);
  if (p) {
    ptr = reinterpret_cast<void*>((reinterpret_cast<std::size_t>(p) + offset) & ~(alignment - 1));
  }
#elif defined(__GNUC__)
  int result = posix_memalign(&ptr, alignment, requiredBytes);
  if (result != 0) {
    ptr = nullptr;
  }
#else
  throw std::runtime_error("Compiler not supported");
#endif

  if (!ptr) {
    throw std::bad_alloc();
  }

#if defined(__linux__)
  madvise(ptr, requiredBytes, MADV_HUGEPAGE);
#endif

  return ptr;
}

template <typename T>
class HashTable {
 public:
  explicit HashTable(std::size_t mb_size) {
    Resize(mb_size);
  }

  HashTable() = default;

  ~HashTable() {
    std::free(table_);
  }

  void Resize(std::size_t mb_size) {
    assert(mb_size > 0);

    constexpr std::size_t kBytesInMegabyte = 1024 * 1024;
    mb_size *= kBytesInMegabyte;

    std::size_t num_elements = mb_size / sizeof(T);
    std::size_t alignment = alignof(T);

    T* new_table = static_cast<T*>(alignedAlloc(alignment, num_elements * sizeof(T)));

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

 private:
  T* table_ = nullptr;
  std::size_t table_size_ = 0;
};

#endif  // INTEGRAL_CACHE_H
