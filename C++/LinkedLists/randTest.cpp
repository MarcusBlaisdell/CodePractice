#include <iostream>
#include <stdlib.h>
#include <time.h>

int main (int argc, char * argv[])
{
  int maxVal = 52;
  srand(time(NULL));
  int randOne = 0;
  int randTwo = 0;

  for (int i = 0; i < 52; i++)
  {
    randOne = rand() % (maxVal - 1);
    randTwo = rand() % (maxVal - randOne - 1);
    while (randTwo == 0)
    {
      randTwo = rand() % (maxVal - randOne - 1);
      std::cout << "rerun randTwo: " << randTwo << ", ";
    }
    std::cout << std::endl;

    std::cout << "rand: " << randOne << ", " << randTwo;
    std::cout << " = " << randOne + randTwo << std::endl;
  }


}
