/*
A bookseller has lots of books classified in 26 categories
labeled A, B, ... Z. Each book has a code c of 3, 4, 5 or
more characters. The 1st character of a code is a capital
letter which defines the book category.

In the bookseller's stocklist each code c is followed by a
space and by a positive integer n (int n >= 0) which indicates
the quantity of books of this code in stock.

For example an extract of a stocklist could be:

L = {"ABART 20", "CDXEF 50", "BKWRK 25", "BTSQZ 89", "DRTYM 60"}.
or
L = ["ABART 20", "CDXEF 50", "BKWRK 25", "BTSQZ 89", "DRTYM 60"] or ....

You will be given a stocklist (e.g. : L) and a list of categories
in capital letters e.g :

M = {"A", "B", "C", "W"}
or
M = ["A", "B", "C", "W"] or ...

and your task is to find all the books of L with codes belonging
to each category of M and to sum their quantity according to each
category.

For the lists L and M of example you have to return the string
(in Haskell/Clojure/Racket a list of pairs):

(A : 20) - (B : 114) - (C : 50) - (W : 0)

where A, B, C, W are the categories, 20 is the sum of the unique
book of category A, 114 the sum corresponding to "BKWRK" and "BTSQZ",
50 corresponding to "CDXEF" and 0 to category 'W' since there are
no code beginning with W.

If L or M are empty return string is "" (Clojure and Racket should
return an empty array/list instead).

Note:
In the result codes and their values are in the same order as in M.

// szlst is lstOfArt size, szcat is categories size
char* stockSummary(char** lstOfArt, int szlst, char** categories, int szcat) {
  // your code
}

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <criterion/criterion.h>

int getVal(char * theString)
{
  int i = 0;
  int theVal = 0;

  // move to correct position:
  while(theString[i] != ' ')
  {
    i++;
  } // end move to correct position
  i++;
  while(theString[i] != '\0')
  {
    printf(""); // I don't know why but this fixes a bug
    //printf("theString[%d]: %c\n", i, theString[i]);
    theVal *= 10;
    theVal += theString[i] - '0';
    i++;
  } // end while to get value

  return theVal;
}

// Function: getInventory
char * getInventory(char ** L, int sizeL, char ** M, int sizeM)
{
  // If there is no list to consider, return empty string
  // and be done with it
  if (sizeL == 0)
  {
    return "";
  } // end don't bother

  int theVal = 0;
  int counts[26] = {0}; // each position corresponds to a letter of the alphabet
  //char static theList[500] = "";
  char theList[500] = "";

  for (int i = 0; i < sizeL; i++)
  {
    theVal = 0;
    theVal = getVal(*L);
    counts[*L[0] - 'A'] += theVal;
    *L++;
  } // end for loop through L

  for (int i = 0; i < sizeM; i++)
  {
    char buffer[50];
    sprintf(buffer, "(%s : %d)", *M, counts[*M[0] - 'A']);
    //sprintf(theList, "(%s : %d)", *M, counts[*M[0] - 'A']);
    /*
    strcat(theList, "(");
    strcat(theList, *M);
    strcat(theList, " : ");
    //sprintf(buffer, "%d", counts[*M[0] - 'A']);
    strcat(buffer, counts[*M[0] - 'A']);
    */
    strcat(theList, buffer);

    if (i < sizeM - 1)
    {
      strcat(theList, " - ");
    }

    *M++;
  }

  return theList;

} // end function getInventory

// Function stockSummary
// szlst is lstOfArt size, szcat is categories size
char* stockSummary(char** lstOfArt, int szlst, char** categories, int szcat)
{
  int theVal = 0;
  int counts[26] = {0}; // each position corresponds to a letter of the alphabet
  char static theList[500] = "";
  //char theList[500] = "";

  for (int i = 0; i < szlst; i++)
  {
    theVal = 0;
    theVal = getVal(*lstOfArt);
    counts[*lstOfArt[0] - 'A'] += theVal;
    *lstOfArt++;
  } // end for loop through lstOfArt

  for (int i = 0; i < szcat; i++)
  {
    char buffer[50];
    sprintf(buffer, "(%s : %d)", *categories, counts[*categories[0] - 'A']);
    strcat(theList, buffer);

    if (i < szcat - 1)
    {
      strcat(theList, " - ");
    }

    *categories++;
  }

  return theList;
} // end function stockSummary

void dotest(char** lstOfArt, int szlst, char** categories, int szcat, char* expr)
{
    //char* sact = stockSummary(lstOfArt, szlst, categories, szcat);
    //char* sact = getInventory(lstOfArt, szlst, categories, szcat);
    char* sact = getInventory(lstOfArt, szlst, categories, szcat);

    printf("before comp - sact:%s:\n", sact);
    printf("before comp - expr:%s:\n", expr);
    //int theComp = strcmp("(A : 200) - (B : 1140)", expr);
    //printf("theComp: %d\n", theComp);

    //printf("strcmp(sact, expr) = %d\n", strcmp(sact, expr));
    //printf("strcmp(expr, sact) = %d\n", strcmp(sact, expr));

    //if(strcmp(sact, expr) != 0)
    if(strcmp(sact, expr) != 0)
    {
      printf("Error. Expected \n%s\n but got \n%s\n", expr, sact);
    }

    printf("after comp - sact:%s:\n", sact);
    printf("after comp - expr:%s:\n", expr);

    //cr_assert_str_eq(sact, expr, "");
    //if (strcmp(sact, "") != 0) {free(sact); sact = NULL;}
}

int main (int argv, char *argc[])
{
  char * L[] = {"ABART 20", "CDXEF 50", "BKWRK 25", "BTSQZ 89", "DRTYM 60"};
  char * M[] = {"A", "B", "C", "W"};

  //char* sact = stockSummary(lstOfArt, szlst, categories, szcat);
  char *theList1 = getInventory(L, 5, M, 4);
  //const char *theList1 = stockSummary(L, 5, M, 4);

  printf("main - theList1: %s\n", theList1);

  char* art[5] = {"ABAR 200", "CDXE 500", "BKWR 250", "BTSQ 890", "DRTY 600"};
  char* cd[2] = {"A", "B"};
  dotest(art, 5, cd, 2, "(A : 200) - (B : 1140)");
  /*
  char* art[5] = {"ABAR 200", "CDXE 500", "BKWR 250", "BTSQ 890", "DRTY 600"};
  char* cd[2] = {"A", "B"};

  char *theList2 = getInventory(art, 5, cd, 2);
  //const char *theList2 = stockSummary(art, 5, cd, 2);

  printf("main - theList2: %s\n", theList2);
  */

  char* art2[0] = {};
  char* cd2[4] = {"B", "R", "D", "X"};

  char *theList3 = getInventory(art2, 0, cd2, 4);
  printf("main - theList3: %s\n", theList3);

  return 1;
}
