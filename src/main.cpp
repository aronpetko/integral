#include "uci.h"
#include "ascii_logo.h"

#ifdef WIN32
#include <windows.h>
#endif

int main() {
#ifdef WIN32
  SetConsoleOutputCP(CP_UTF8);
#endif

  print_ascii_logo();

  uci::accept_commands();
}