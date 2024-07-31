#include "engine/uci/uci.h"
#ifdef WIN32
#include <windows.h>
#endif

int main(int arg_count, char **args) {
  // Change output buffer size
  setvbuf(stdout, nullptr, _IONBF, 0);

#ifdef WIN32
  // Enable ANSI escape codes
  const auto stdout_handle = GetStdHandle(STD_OUTPUT_HANDLE);

  DWORD console_mode = 0;
  GetConsoleMode(stdout_handle, &console_mode);

  console_mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
  SetConsoleMode(stdout_handle, console_mode);
#endif

  uci::AcceptCommands(arg_count, args);
}