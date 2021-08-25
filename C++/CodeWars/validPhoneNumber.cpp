/*
Write a function that accepts a string, and returns true if it is in the form of a phone number.
Assume that any integer from 0-9 in any of the spots will produce a valid phone number.

Only worry about the following format:
(123) 456-7890 (don't forget the space after the close parentheses)

Examples:

"(123) 456-7890"  => true
"(1111)555 2345"  => false
"(098) 123 4567"  => false
*/

#include <iostream>
#include <string.h>

// Function isValid
int isValid (std::string theNum)
{
  int digits[10] = {1,2,3,6,7,8,10,11,12,13};
  int validFlag = 1;

  // first, test for parentheses, space, and dash in the correct positions:
  if (theNum[0] == '(' && theNum[4] == ')' && theNum[5] == ' ' && theNum[9] == '-')
  {
    // second, verify digits are integers 0-9:
    for (int i = 0; i < 10; i++)
    {
      // if we encounter a non-integer 0-9, return fail,
      if (theNum[digits[i]] > '9' || theNum[digits[i]] < '0')
      {
        return 0;
      }
    } // end for loop to check digits

    // if we did not fail the for loop, we pass the tests, return pass:
    return 1;

  } // end if parentheses, space, dash
  else
  {
    return 0;
  }
} // end function isValid

int main (int argv, char *argc[])
{
  std::string theNum[6] = {"(123) 456-7890","(123)456-7890","123 456-7890","(123) 456.7890","(a23) 456-7890","(1b3) 456-7890"};

  for (int i = 0; i < 6; i++)
  {
    if (isValid(theNum[i]) == 1)
    {
      std::cout << theNum[i] << " is a valid phone number" << std::endl;
    }
    else
    {
      std::cout << theNum[i] << " is not a valid phone number" << std::endl;
    }
  } // end for loop



  return 1;
}
