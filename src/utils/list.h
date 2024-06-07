#ifndef INTEGRAL_LIST_H
#define INTEGRAL_LIST_H

#include <algorithm>
#include <array>
#include <cassert>

template <class T, std::size_t length>
class List {
 public:
  List() : count_(0) {}

  inline T &operator[](int i) {
    assert(i >= 0 && i < count_);
    return container_[i];
  }

  inline T &Back() {
    return container_[count_ - 1];
  }

  inline const T &At(int i) {
    return container_[i];
  }

  inline void Push(const T &object) {
    assert(count_ < length);
    container_[count_++] = object;
  }

  inline void Push(T &&object) {
    assert(count_ < length);
    container_[count_++] = std::move(object);
  }
  
  inline void Sort() {
    std::ranges::stable_sort(container_.begin(), container_.begin() + (count_ - 1), [](const auto &a, const auto &b)
                             {
                               return a.score > b.score;
                             });
  }

  inline void Heapify() {
    std::make_heap(container_.begin(), container_.begin() + count_);
  }

  inline T &HeapPop() {
    std::pop_heap(container_.begin(), container_.begin() + count_--);
    return container_[count_];
  }

  inline T &PopBack() {
    assert(count_ > 0);
    return container_[--count_];
  }

  inline void Erase(int i) {
    std::swap(Back(), container_[i]);
    --count_;
  }

  [[nodiscard]] inline int Size() const {
    return count_;
  }

  [[nodiscard]] inline bool Empty() const {
    return count_ == 0;
  }

  [[nodiscard]] inline std::array<T, length> &Data() {
    return container_;
  }

  inline void Clear() {
    count_ = 0;
  }

 private:
  std::array<T, length> container_;
  int count_ = 0;
};

#endif  // INTEGRAL_LIST_H