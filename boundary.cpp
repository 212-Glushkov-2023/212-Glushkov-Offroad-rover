#include "includes.h"

void Boundary::console_read()
{
  getline(std::cin, message);
  int t = message.find(' ');
  std::string comand = message.substr(0, t);
  
}
