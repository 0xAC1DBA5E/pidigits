#include "pidigits.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  unsigned long n = atol(argv[1]);
  std::cout << "pi16(" << n << "): " << std::hex << pi16(n) << std::endl;
}
