/*
Write a function that accepts an array of 10 integers (between 0 and 9), that returns a string of those numbers in the form of a phone number.
Example

create_phone_number(phnum, (const unsigned char[]){1,2,3,4,5,6,7,8,9,0});
     phnum <- "(123) 456-7890"

The returned format must be correct in order to complete this challenge.
Don't forget the space after the closing parentheses!

*/

#include <iostream>

// Function: create_phone_number:
// They are being tricky by passing the digits in as integers
// so I have to add 48 to them to get them to be the correct ASCII values:
void create_phone_number(unsigned char phnum[], const unsigned char theNum[])
{
  phnum[0] = '(';
  phnum[1] = theNum[0] + 48;
  phnum[2] = theNum[1] + 48;
  phnum[3] = theNum[2] + 48;
  phnum[4] = ')';
  phnum[5] = ' ';
  phnum[6] = theNum[3] + 48;
  phnum[7] = theNum[4] + 48;
  phnum[8] = theNum[5] + 48;
  phnum[9] = '-';
  phnum[10] = theNum[6] + 48;
  phnum[11] = theNum[7] + 48;
  phnum[12] = theNum[8] + 48;
  phnum[13] = theNum[9] + 48;
  phnum[14] = '\0';
} // end function create_phone_number

int main(int argv, char *argc[])
{
  unsigned char phnum[15];

  create_phone_number(phnum, (const unsigned char[]){1,2,3,4,5,6,7,8,9,0});
  std::cout << phnum << std::endl;
}
