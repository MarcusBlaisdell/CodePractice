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

#include <stdio.h>
#include <string.h>

// Function: isValid
// Accepts a string and tests if it is in a valid phone number format
// returns a bool, valid or invalid
int isValid(char theNum[])
{
  int digits[10] = {1,2,3,6,7,8,10,11,12,13};
  int i = 0;

  // first test, length:
  if (strlen(theNum) > 14)
  {
    return 0;
  }

  // second, test for parentheses, space, and dash:
  if (theNum[0] == '(' && theNum[4] == ')' && theNum[5] == ' ' && theNum[9] == '-')
  {
    // third, test if numbers are valid digits, 0-9:
    for (i = 0; i < 10; i++)
    {
      if (theNum[digits[i]] < '0' || theNum[digits[i]] > '9')
      {
        return 0;
      } // check numbers are between 0 and 9
    } // end for loop to verify numbers are valid digits
  } // end check for parentheses, space, and dash
  else // if we get here, we fail the parentheses, space, dash test
  {
    return 0;
  }

  // If we get here, all tests passed
  return 1;

} // end function isValid

// Function testValid
// If a number is valid, state that,
// if it is not valid, state that
void testValid(char theNum[])
{
  printf ("%s is ", theNum);

  if (isValid(theNum) == 1)
  {
    printf ("a valid number");
  } // end if valid
  else
  {
    printf ("not a valid number");
  } // end, else, is not valid

  printf ("\n");
} // end function testValid

int main (int argv, char *argc[])
{
  int i = 0;
  //char theNum[6][15] = {"(123) 456-7890\0","(123)456-7890\0","123 456-7890\0","(123) 456.7890\0","(a23) 456-7890\0","(1b3) 456-7890\0"};
  char * theNum[] = {"(123) 456-7890", "(1111)555 2345", "(098) 123 4567", "(123)456-7890", "abc(123)456-7890", "(123)456-7890abc", "abc(123)456-7890abc", "abc(123) 456-7890", "(123) 456-7890abc", "abc(123) 456-7890abc"};

  /*
  ,
  */

  for (i = 0; i < 10; i++)
  {
    testValid(theNum[i]);
  } // end for loop to test multiple examples of phone numbers

  return 1;
}
