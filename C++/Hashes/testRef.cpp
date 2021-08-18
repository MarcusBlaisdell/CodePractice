#include<iostream>

// update myInt by reference:
int updateInt(int &myInt)
{
  myInt++;

  return 1;
} // end function updateInt

int main(int argv, char *argc[])
{
  int myInt = 0;
  std::string myString = "Name";

  std::cout << "myInt = " << myInt << std::endl;
  std::cout << "myString = " << myString << std::endl;

  updateInt(myInt);

  std::cout << "myInt = " << myInt << std::endl;
  std::cout << "myString = " << myString << std::endl;

  return 1;
}
