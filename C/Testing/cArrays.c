#include <stdio.h>
#include <string.h>

// Function: printInt
// Accepts an array of integers,
// prints them in order:
void printInt(int *intArray)
{
  for (int i = 0; i < 10; i++)
  {
    printf("intArray[%d]: %d\n", i, *(intArray + i));
  } // end for loop

} // end function printInt

// Function: modifyInt
// Reverse an integer array
void modifyInt(int *intArray)
{
  int temp;
  int i = 0, j = 9;
  // Reverse the array
  while (i < j)
  {
    temp = *(intArray + i);
    *(intArray + i) = *(intArray + j);
    *(intArray + j) = temp;
    i++;
    j--;
  } // end for loop to reverse array

} // end function modifyInt

// Function: printChar
// Accepts an array of chars,
// prints them in order:
void printChar(char *charArray)
{
  for (int i = 0; i < 10; i++)
  {
    printf("charArray[%d]: %c\n", i, *(charArray + i));
  } // end for loop

} // end function printChar

// Function: modifyChar
// Reverse a char array
void modifyChar(char *charArray)
{
  char temp;
  int i = 0, j = 9;
  // Reverse the array
  while (i < j)
  {
    temp = *(charArray + i);
    *(charArray + i) = *(charArray + j);
    *(charArray + j) = temp;
    i++;
    j--;
  } // end for loop to reverse array

} // end function modifyChar

// Function: printString
// Accepts an array of strings,
// prints them in order:
void printString(char ** stringArray)
{
  for (int i = 0; i < 10; i++)
  {
    printf("stringArray[%d]: %s\n", i, *(stringArray + i));
  } // end for loop

} // end function printString

// Function: modifyString
// Reverse a string array
void modifyString(char **stringArray)
{
  char *temp;
  int i = 0, j = 9;
  // Reverse the array
  while (i < j)
  {
    temp = *(stringArray + i);
    *(stringArray + i) = *(stringArray + j);
    *(stringArray + j) = temp;
    i++;
    j--;
  } // end for loop to reverse array

} // end function modifyString

int main (int argv, char *argc[])
{
  int intArray[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  char charArray[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
  char * stringArray[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

  // Test int array:
  printInt(intArray);
  modifyInt(intArray);
  printInt(intArray);

  // Test char array:
  printChar(charArray);
  modifyChar(charArray);
  printChar(charArray);

  // Test string array:
  printString(stringArray);
  modifyString(stringArray);
  printString(stringArray);

  return 1;
}
