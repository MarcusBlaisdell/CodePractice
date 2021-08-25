/*
Given a positive number n > 1 find the prime factor decomposition of n. The result will be a string with the following form :

 "(p1**n1)(p2**n2)...(pk**nk)"

with the p(i) in increasing order and n(i) empty if n(i) is 1.

Example: n = 86240 should return "(2**5)(5)(7**2)(11)"
*/

#include <stdio.h>
#include <math.h>

// Function: isPrime
int isPrime(int theNum)
{
  int i = 2;

  for (i = 2; i < theNum - 1; i++)
  {
    if (theNum % i == 0)
    {
      return 0;
    }
  } // end for loop

  // if we get here, no factor was found, number is prime
  return 1;

} // end function isPrime

// Function findRoot
void findRoot(int theNum)
{
  int i = 2, j = 2;
  int product = 0;
  int flag = 0;

  for (i = 2; i < 10; i++)
  {
    j = 2;
    product = 0;
    while (product < theNum)
    {
      if (pow(i,j) == theNum)
      {
        flag = 1;
        printf ("%d**%d, ", i, j);
      } // end print all roots and exponents

      product = pow(i,j);
      j++;

    } // end while to find exponent

  } // end for loop to find root

  if (flag == 0)
  {
    printf ("%d, ", theNum);
  }

}

// Function: listPrimeFactors
void listPrimeFactors(int theNum)
{
  int i = 2;

  printf ("Factors for %d\n", theNum);

  for (i = 2; i < theNum - 1; i++)
  {
    if (theNum % i == 0)
    {
      if (isPrime(i) == 1)
      {
        printf("%d, ", i);
        findRoot(theNum/i);
        printf("\n");
      } // end only print prime factors
    } // end if
  } // end for loop to find all factors

  printf ("\n");

} // end function listPrimeFactors

// Function: findFactors:
void findFactors(int theNum)
{
  printf ("Factors for %d:\n", theNum);
  int i = 2;

  while (i < (theNum/2))
  {
    if (theNum % i == 0)
    {
      printf ("%d, %d\n", i, theNum/i);
    } // end if factor found
    i++;
  } // end while

} // end function findFactors

int main (int argv, char *argc[])
{
  int theNum[] = {86240, 16, 100, 18, 50};

  for (int i = 0; i < 5; i++)
  {
    listPrimeFactors(theNum[i]);
  }

  for (int i = 0; i < 5; i++)
  {
    findFactors(theNum[i]);
  }

  return 1;
}
