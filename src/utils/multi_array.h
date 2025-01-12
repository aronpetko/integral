#ifndef INTEGRAL_MULTI_ARRAY_H
#define INTEGRAL_MULTI_ARRAY_H

#include <array>
#include <type_traits>

template <typename T, std::size_t Size, std::size_t... Sizes>
class MultiArray;

namespace Detail {

template <typename T, std::size_t Size, std::size_t... Sizes>
struct MultiArrayHelper {
  using ChildType = MultiArray<T, Sizes...>;
};

template <typename T, std::size_t Size>
struct MultiArrayHelper<T, Size> {
  using ChildType = T;
};

}  // namespace Detail

// MultiArray is a generic N-dimensional array.
// The template parameters (Size and Sizes) encode the dimensions of the array.
template <typename T, std::size_t Size, std::size_t... Sizes>
class MultiArray {
  using ChildType =
      typename Detail::MultiArrayHelper<T, Size, Sizes...>::ChildType;
  using ArrayType = std::array<ChildType, Size>;
  ArrayType data_;

 public:
  using value_type = typename ArrayType::value_type;
  using size_type = typename ArrayType::size_type;
  using difference_type = typename ArrayType::difference_type;
  using reference = typename ArrayType::reference;
  using const_reference = typename ArrayType::const_reference;
  using pointer = typename ArrayType::pointer;
  using const_pointer = typename ArrayType::const_pointer;
  using iterator = typename ArrayType::iterator;
  using const_iterator = typename ArrayType::const_iterator;
  using reverse_iterator = typename ArrayType::reverse_iterator;
  using const_reverse_iterator = typename ArrayType::const_reverse_iterator;

  constexpr auto& at(size_type index) noexcept {
    return data_.at(index);
  }
  constexpr const auto& at(size_type index) const noexcept {
    return data_.at(index);
  }

  constexpr auto& operator[](size_type index) noexcept {
    return data_[index];
  }
  constexpr const auto& operator[](size_type index) const noexcept {
    return data_[index];
  }

  constexpr auto& front() noexcept {
    return data_.front();
  }
  constexpr const auto& front() const noexcept {
    return data_.front();
  }
  constexpr auto& back() noexcept {
    return data_.back();
  }
  constexpr const auto& back() const noexcept {
    return data_.back();
  }

  auto* data() {
    return data_.data();
  }
  const auto* data() const {
    return data_.data();
  }

  constexpr auto begin() noexcept {
    return data_.begin();
  }
  constexpr auto end() noexcept {
    return data_.end();
  }
  constexpr auto begin() const noexcept {
    return data_.begin();
  }
  constexpr auto end() const noexcept {
    return data_.end();
  }
  constexpr auto cbegin() const noexcept {
    return data_.cbegin();
  }
  constexpr auto cend() const noexcept {
    return data_.cend();
  }

  constexpr auto rbegin() noexcept {
    return data_.rbegin();
  }
  constexpr auto rend() noexcept {
    return data_.rend();
  }
  constexpr auto rbegin() const noexcept {
    return data_.rbegin();
  }
  constexpr auto rend() const noexcept {
    return data_.rend();
  }
  constexpr auto crbegin() const noexcept {
    return data_.crbegin();
  }
  constexpr auto crend() const noexcept {
    return data_.crend();
  }

  [[nodiscard]] constexpr bool empty() const noexcept {
    return data_.empty();
  }
  constexpr size_type size() const noexcept {
    return data_.size();
  }
  constexpr size_type max_size() const noexcept {
    return data_.max_size();
  }

  constexpr MultiArray<T, Size, Sizes...>& operator=(
      const MultiArray<T, Size, Sizes...>& other) = default;

  template <bool NoExtraDimension = sizeof...(Sizes) == 0,
            typename = typename std::enable_if_t<NoExtraDimension, bool>>
  constexpr MultiArray<T, Size, Sizes...>& operator=(
      const std::array<T, Size>& other) noexcept {
    data_ = other;
    return *this;
  }

  template <bool NoExtraDimension = sizeof...(Sizes) == 0,
            typename = typename std::enable_if_t<NoExtraDimension, bool>>
  constexpr std::array<T, Size>& as_array() noexcept {
    return data_;
  }

  template <bool NoExtraDimension = sizeof...(Sizes) == 0,
            typename = typename std::enable_if_t<NoExtraDimension, bool>>
  constexpr const std::array<T, Size>& as_array() const noexcept {
    return data_;
  }

  template <typename U>
  void fill(const U& v) {
    for (auto& ele : data_) {
      if constexpr (sizeof...(Sizes) == 0)
        ele = v;
      else
        ele.fill(v);
    }
  }

  constexpr void swap(MultiArray<T, Size, Sizes...>& other) noexcept {
    data_.swap(other.data_);
  }
};

#endif  // INTEGRAL_MULTI_ARRAY_H
