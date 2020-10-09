#include <iostream>
#include <cstdlib>
#include "RGBA.h"

int main()
{
  std::cout<<"RGBA \n";
  RGBA p1(0, 64, 128, 255);
  p1.print();
  return EXIT_SUCCESS;
}