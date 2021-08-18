/*
This program tests if two values in a list sum to a target value
*/

#include <iostream>
#include <unordered_map>

// Function print indexes:
int printIndexes(int theList[], int theSize)
{
  for (int i = 0; i < theSize; i++)
  {
    std::cout << theList[i] << ", ";
  } // end for loop to print array

  std::cout << std::endl;

  return 1;
} // end function printIndexes

// find indexes of target sum:
int targetSum(int theList[], int theSize, int theTarget)
{
  std::unordered_map<int, int> theIndexes;

  for (int i = 0; i < theSize; i++)
  {
    //int matchIndex = theIndexes.find(theTarget - theList[i]);
    auto matchIndex = theIndexes.find(theTarget - theList[i]);
    if (matchIndex != theIndexes.end())
    {
      std::cout << "Indexes: " << i << ", " << matchIndex->second << std::endl;
      std::cout << "Values:  " << theList[i] << ", " << matchIndex->first << std::endl;
    } // end check list
    else
    {
      theIndexes.insert({theList[i], i});
    }

  } // iterate through the list

  return 1;

} // end function targetSum

int main (int argv, char *argc[])
{
  int theList[] = {-3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
  int theSize = sizeof(theList)/sizeof(theList[0]);

  //printIndexes(theList, theSize);

  std::cout << "Ten:" << std::endl;
  targetSum(theList, theSize, 10);

  std::cout << "Nine:" << std::endl;
  targetSum(theList, theSize, 9);

  std::cout << "Five:" << std::endl;
  targetSum(theList, theSize, 5);

  return 1;
}
