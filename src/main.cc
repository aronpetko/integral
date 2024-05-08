#include "chess/uci.h"

#ifdef WIN32
#include <windows.h>
#endif

int main(int arg_count, char **args) {
#ifdef WIN32
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE),
                 ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
#endif

  uci::AcceptCommands(arg_count, args);
}