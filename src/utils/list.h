#ifndef INTEGRAL_SRC_LIST_H
#define INTEGRAL_SRC_LIST_H

#include <cassert>
#include <array>

template<class T, std::size_t length>
class List {
 public:
  List() : count_(0) {}

  inline T &operator[](int i) {
    assert(i >= 0 && i < count_);
    return container_[i];
  }

  inline T &back() {
    return container_[count_ - 1];
  }

  inline const T &at(int i) {
    return container_[i];
  }

  inline void push(const T& object) {
    assert(count_ < length);
    container_[count_++] = object;
  }

  inline void push(T&& object) {
    assert(count_ < length);
    container_[count_++] = std::move(object);
  }

  inline T &pop_back() {
    assert(count_ > 0);
    return container_[--count_];
  }

  inline void erase(int i) {
    std::swap(back(), container_[i]);
    --count_;
  }

  [[nodiscard]] inline int size() const {
    return count_;
  }

  [[nodiscard]] inline bool empty() const {
    return count_ == 0;
  }

  [[nodiscard]] inline std::array<T, length> &data() {
    return container_;
  }

  inline void clear() {
    count_ = 0;
  }

 private:
  std::array<T, length> container_;
  int count_ = 0;
};

#endif  // INTEGRAL_SRC_LIST_H