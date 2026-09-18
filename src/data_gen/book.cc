#include "book.h"

#include <stdexcept>

namespace data_gen {

Book::Book(const std::filesystem::path &path) : file_(path) {
  const auto data = file_.Data();
  for (std::size_t offset = 0; offset < data.size();) {
    const auto end = data.find('\n', offset);
    const auto next = end == std::string_view::npos ? data.size() : end + 1;
    const auto line = data.substr(offset, next - offset);
    if (line.find_first_not_of(" \t\r\n") != std::string_view::npos) {
      offsets_.push_back(offset);
    }
    offset = next;
  }
  if (!path.empty() && Empty()) {
    throw std::runtime_error("book is empty");
  }
}

}  // namespace data_gen
