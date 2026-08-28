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
#elif defined(_WIN32)
// Keep the Win32 surface minimal, and NOMINMAX is required so its min/max
// macros don't shadow std::min/std::max in every file that reaches this header
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>

namespace large_pages {

inline std::size_t LargePageSize() {
  static const std::size_t size = []() -> std::size_t {
    HANDLE token;
    if (!OpenProcessToken(GetCurrentProcess(),
                          TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY,
                          &token)) {
      return 0;
    }

    TOKEN_PRIVILEGES privileges{};
    privileges.PrivilegeCount = 1;
    privileges.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

    bool enabled = false;
    if (LookupPrivilegeValueA(
            nullptr, "SeLockMemoryPrivilege", &privileges.Privileges[0].Luid)) {
      AdjustTokenPrivileges(token, FALSE, &privileges, 0, nullptr, nullptr);
      enabled = GetLastError() == ERROR_SUCCESS;
    }

    CloseHandle(token);
    return enabled ? GetLargePageMinimum() : 0;
  }();
  return size;
}

}  // namespace large_pages
#endif

[[nodiscard]] inline void* AlignedAlloc(std::size_t alignment,
                                        std::size_t size) {
#if defined(_WIN32)
  if (const std::size_t page_size = large_pages::LargePageSize()) {
    // Large-page allocations must be a multiple of the large page size
    const std::size_t rounded = (size + page_size - 1) & ~(page_size - 1);
    if (void* ptr = VirtualAlloc(nullptr,
                                 rounded,
                                 MEM_RESERVE | MEM_COMMIT | MEM_LARGE_PAGES,
                                 PAGE_READWRITE)) {
      return ptr;
    }
  }

  // Fall back to regular pages
  if (void* ptr = VirtualAlloc(
          nullptr, size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE)) {
    return ptr;
  }
  throw std::bad_alloc();
#else
  // aligned_alloc requires the size to be a multiple of the alignment
  if (size % alignment != 0) {
    size += alignment - (size % alignment);
  }

  void* ptr = nullptr;
#if defined(__APPLE__)
  if (posix_memalign(&ptr, alignment, size)) throw std::bad_alloc();
#else
  ptr = std::aligned_alloc(alignment, size);
  if (!ptr) throw std::bad_alloc();
#endif

#if defined(__linux__)
  madvise(ptr, size, MADV_HUGEPAGE);
#endif

  return ptr;
#endif
}

inline void AlignedFree(void* ptr) {
#if defined(_WIN32)
  VirtualFree(ptr, 0, MEM_RELEASE);
#else
  std::free(ptr);
#endif
}

template <typename T>
class AlignedHashTable {
 public:
  explicit AlignedHashTable(std::size_t mb_size) {
    Resize(mb_size);
  }

  AlignedHashTable() : table_(nullptr), table_size_(0) {}

  ~AlignedHashTable() {
    FreeTable();
  }

  void Resize(std::size_t mb_size) {
    assert(mb_size > 0);

    constexpr std::size_t kBytesInMegabyte = 1024 * 1024;
    mb_size *= kBytesInMegabyte;

    const std::size_t num_elements = mb_size / sizeof(T);
    const auto new_table =
        static_cast<T*>(AlignedAlloc(sizeof(T), num_elements * sizeof(T)));

    FreeTable();

    table_ = new_table;
    table_size_ = num_elements;
  }

  void Clear() {
    std::fill_n(table_, table_size_, T{});
  }

  T& operator[](const U64& key) {
    return table_[Index(key)];
  }

  void Prefetch(const U64& key) {
    auto& entry = (*this)[key];
    __builtin_prefetch(&entry);
  }

 private:
  [[nodiscard]] U64 Index(const U64& key) const {
    return (static_cast<U128>(key) * static_cast<U128>(table_size_)) >> 64;
  }

  void FreeTable() {
    if (table_) {
      AlignedFree(table_);
      table_ = nullptr;
    }
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

  void Prefetch(const U64& key) {
    auto& entry = (*this)[key];
    __builtin_prefetch(&entry);
  }

 private:
  [[nodiscard]] U64 Index(const U64& key) const {
    return (static_cast<U128>(key) * static_cast<U128>(table_size_)) >> 64;
  }

 private:
  std::vector<T> table_;
  std::size_t table_size_ = 0;
};

#endif  // INTEGRAL_CACHE_H