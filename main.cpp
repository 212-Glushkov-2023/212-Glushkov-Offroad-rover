#include "includes.h"


//Бездорожье 
//Глушков Василий 212 группа
int main() 
{
  srand(time(NULL));
  NoWay shrek(25, 25, 25, 10, 5);
  std::ofstream file1("hills.txt");
  std::ofstream file2("stouns.txt");
  std::ofstream file3("logs.txt");
  shrek.print(file1, file2, file3);
  file1.close();
  file2.close();
  file3.close();
  return 0;
}


