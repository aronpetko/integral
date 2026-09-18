#ifndef INTEGRAL_BOOK_H
#define INTEGRAL_BOOK_H

#include <cassert>
#include <vector>

#include "../utils/mapped_file.h"
#include "../utils/types.h"

namespace data_gen {

class Book {
 public:
  explicit Book(const std::filesystem::path &path);

  [[nodiscard]] bool Empty() const {
    return offsets_.empty();
  }

  [[nodiscard]] std::size_t Size() const {
    return offsets_.size();
  }

  [[nodiscard]] std::string_view operator[](std::size_t index) const {
    assert(index < Size());
    const auto tail = file_.Data().substr(offsets_[index]);
    auto line = tail.substr(0, tail.find('\n'));
    if (!line.empty() && line.back() == '\r') {
      line.remove_suffix(1);
    }
    return line;
  }

 private:
  MappedFile file_;
  std::vector<U64> offsets_;
};

}  // namespace data_gen

#endif  // INTEGRAL_BOOK_H
