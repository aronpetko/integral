#include "engine/evaluation/nnue/nnue.h"
#include "engine/search/cuckoo.h"
#include "engine/uci/uci.h"
#ifdef _WIN32
#include <windows.h>
#endif
#ifdef __GLIBC__
#include <malloc.h>
#endif

int main(int arg_count, char **args) {
#ifdef __GLIBC__
  // glibc raises this threshold as large blocks are freed, after which large
  // allocations can reuse pages first touched on another NUMA node. Fixing it
  // keeps them as fresh mappings placed by the pinned thread that touches them
  mallopt(M_MMAP_THRESHOLD, 128 * 1024);
#endif

  // Change output buffer size
  setvbuf(stdout, nullptr, _IONBF, 0);

#ifdef _WIN32
  // Enable ANSI escape codes
  const auto stdout_handle = GetStdHandle(STD_OUTPUT_HANDLE);

  DWORD console_mode = 0;
  GetConsoleMode(stdout_handle, &console_mode);

  console_mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
  SetConsoleMode(stdout_handle, console_mode);
#endif

  nnue::LoadFromIncBin();

  search::cuckoo::Initialize();

  uci::AcceptCommands(arg_count, args);
}