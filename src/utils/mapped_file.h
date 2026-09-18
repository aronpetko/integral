#ifndef INTEGRAL_MAPPED_FILE_H
#define INTEGRAL_MAPPED_FILE_H

#include <filesystem>
#include <string_view>

class MappedFile {
 public:
  explicit MappedFile(const std::filesystem::path &path);
  ~MappedFile();
  MappedFile(const MappedFile &) = delete;
  MappedFile &operator=(const MappedFile &) = delete;

  [[nodiscard]] std::string_view Data() const {
    return data_;
  }

 private:
  std::string_view data_;
};

#endif  // INTEGRAL_MAPPED_FILE_H
