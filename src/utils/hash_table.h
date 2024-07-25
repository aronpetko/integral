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

#include <iostream>

inline void* alignedAlloc(std::size_t alignment, std::size_t requiredBytes) {
  void* ptr = nullptr;

  // Check that alignment is a power of two and at least the size of a pointer
  if (alignment < sizeof(void*) || (alignment & (alignment - 1)) != 0) {
    std::cerr << "Invalid alignment: " << alignment << std::endl;
    throw std::invalid_argument("Alignment must be a power of two and at least the size of a pointer");
  }

#if defined(__GNUC__)
  int result = posix_memalign(&ptr, alignment, requiredBytes);
  if (result != 0) {
    std::cerr << "posix_memalign failed with error code: " << result << std::endl;
    ptr = nullptr;
  }
#else
  throw std::runtime_error("Compiler not supported");
#endif

  if (!ptr) {
    std::cerr << "Memory allocation failed!" << std::endl;
    throw std::bad_alloc();
  }

#if defined(__linux__)
  if (madvise(ptr, requiredBytes, MADV_HUGEPAGE) != 0) {
    std::cerr << "madvise failed!" << std::endl;
  }
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
