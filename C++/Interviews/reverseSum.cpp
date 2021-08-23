#include <iostream>
#include <string.h>

// Function: reverseString:
// accepts a string, reverses it, returns reversed string:
std::string reverseString(std::string theString)
{
  std::string returnString;
  int removeLeading = 0;

  int endIndex = theString.length() - 1;

  while (endIndex > -1)
  {
    if (theString[endIndex] != '0')
    {
      removeLeading = 1;
    } // end if we found a nonzero

    if (removeLeading == 1)
    {
      returnString += theString[endIndex];
    } // end append if no more leading zeros

    endIndex--;
  }  // end while loop to reverse string

  return returnString;

} // end function reverseString, second version

// Function sumStrings
// Accepts two strings
// Sums them as integers, one significant digit at a time,
// returns sum as a reversed string
std::string sumStrings(std::string string1, std::string string2)
{
  std::string returnString = "";

  int endIndex1 = string1.length() - 1;
  int endIndex2 = string2.length() - 1;

  int carry = 0;

  while (endIndex2 > -1)
  {
    int theSum = int(string1[endIndex1] - '0') + int(string2[endIndex2] - '0') + carry;

    carry = 0;

    if (theSum > 9)
    {
      carry = 1;
    }

    returnString += char(theSum%10 + '0');

    endIndex1--;
    endIndex2--;

  } // end small while loop

  while (endIndex1 > -1)
  {
    int theSum = int(string1[endIndex1] - '0') + carry;

    carry = 0;

    if (theSum > 9)
    {
      carry = 1;
    }

    returnString += char(theSum%10 + '0');

    endIndex1--;
  } // end while we still have values in first string

  if (carry == 1)
  {
    returnString += '1';
  }

  return reverseString(returnString);

} // end function sumStrings

// Function reverseSum
// Accepts two strings,
// Reverses each, then sums them:
std::string reverseSum(std::string string1, std::string string2)
{
  string1 = reverseString(string1);
  string2 = reverseString(string2);

  return sumStrings(string1, string2);
} // end function reverseSum

int main (int argv, char *argc[])
{
  std::string string1 = "123";
  std::string string2 = "12";

  std::string theSum;

  theSum = reverseSum(string1, string2);

  std::cout << "theSum should be 243: " << theSum << std::endl;
  std::cout << "theSummedSum should be 585: " << sumStrings(theSum, reverseString(theSum)) << std::endl;

  string1 = "60";
  string2 = "40";

  theSum = reverseSum(string1, string2);

  std::cout << "theSum should be 10: " << theSum << std::endl;
  std::cout << "theSummedSum should be 11: " << sumStrings(theSum, reverseString(theSum)) << std::endl;

  return 1;
}
