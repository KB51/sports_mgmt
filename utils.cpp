#include "utils.h"
#include <cstdlib>

  void clearScreen()
  {
    #if defined(_WIN32) || defined(_WIN64)
      system("cls");

    #endif;
  }
