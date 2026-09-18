#include "mapped_file.h"

#include <limits>
#include <stdexcept>
#include <system_error>

#if defined(_WIN32)
#ifndef NOMINMAX
#define NOMINMAX
#endif
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#else
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#endif

MappedFile::MappedFile(const std::filesystem::path &path) {
  if (path.empty()) {
    return;
  }
#if defined(_WIN32)
  const HANDLE file = CreateFileW(path.c_str(),
                                  GENERIC_READ,
                                  FILE_SHARE_READ,
                                  nullptr,
                                  OPEN_EXISTING,
                                  FILE_ATTRIBUTE_NORMAL,
                                  nullptr);
  if (file == INVALID_HANDLE_VALUE) {
    throw std::system_error(
        GetLastError(), std::system_category(), "open file");
  }
  LARGE_INTEGER length;
  if (!GetFileSizeEx(file, &length)) {
    const auto error = GetLastError();
    CloseHandle(file);
    throw std::system_error(error, std::system_category(), "file size");
  }
  if (length.QuadPart == 0) {
    CloseHandle(file);
    return;
  }
  if (static_cast<unsigned long long>(length.QuadPart) >
      std::numeric_limits<std::size_t>::max()) {
    CloseHandle(file);
    throw std::length_error("file exceeds address space");
  }
  const HANDLE mapping =
      CreateFileMappingW(file, nullptr, PAGE_READONLY, 0, 0, nullptr);
  const auto mapping_error = GetLastError();
  CloseHandle(file);
  if (!mapping) {
    throw std::system_error(mapping_error, std::system_category(), "map file");
  }
  const auto size = static_cast<std::size_t>(length.QuadPart);
  const auto view = static_cast<const char *>(
      MapViewOfFile(mapping, FILE_MAP_READ, 0, 0, size));
  const auto view_error = GetLastError();
  CloseHandle(mapping);
  if (!view) {
    throw std::system_error(view_error, std::system_category(), "map view");
  }
#else
  const int file = open(path.c_str(), O_RDONLY);
  if (file == -1) {
    throw std::system_error(errno, std::generic_category(), "open file");
  }
  struct stat info;
  if (fstat(file, &info) == -1) {
    const int error = errno;
    close(file);
    throw std::system_error(error, std::generic_category(), "file size");
  }
  if (info.st_size == 0) {
    close(file);
    return;
  }
  if (static_cast<unsigned long long>(info.st_size) >
      std::numeric_limits<std::size_t>::max()) {
    close(file);
    throw std::length_error("file exceeds address space");
  }
  const auto size = static_cast<std::size_t>(info.st_size);
  const auto view = static_cast<const char *>(
      mmap(nullptr, size, PROT_READ, MAP_PRIVATE, file, 0));
  const int error = errno;
  close(file);
  if (view == MAP_FAILED) {
    throw std::system_error(error, std::generic_category(), "map file");
  }
#endif
  data_ = {view, size};
}

MappedFile::~MappedFile() {
  if (data_.empty()) {
    return;
  }
#if defined(_WIN32)
  UnmapViewOfFile(data_.data());
#else
  munmap(const_cast<char *>(data_.data()), data_.size());
#endif
}
