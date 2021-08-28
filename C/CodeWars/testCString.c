#include <stdio.h>
#include <string.h>

char * testString(char * theString)
{
  char static newString[10] = "";
  //char *newString = "Tset";
  strcat(newString, theString);

  printf("newString: %s\n", newString);
  printf("(char *) newString: %s\n", (char *) newString);
  char * returnString = (char *) newString;
  printf("returnString: %s\n", returnString);
  //char * returnString = "Fail";
  return newString;
}

void testInitialize()
{
  int count[26] = {0};
  char testString[10] = "ABC";
  char indexMe[10] = "abcdef";
  char justChar[2] = "1";
  printf("indexMe before: %s\n", indexMe);
  strcat(indexMe, "gh");
  strcat(indexMe, justChar);
  printf("indexMe after: %s\n", indexMe);

  for (int i = 0; i < 26; i++)
  {
    printf("%d: %d\n", i, count[i]);
  }

  printf("A = %d\n", testString[1] - testString[0]);
}

// Function: testReturn
// test returning a char array from a function
// Should go out of scope and be unavailable
char * testReturn()
{
  char buildString[100] = "";
  char * returnString = "I have returned";
  //strcat(buildString, returnString);
  sprintf(buildString, "%s", returnString);

  return buildString;
} // end function testReturn

// Function testReturn2
// test returning the string that was passed to the function
char * testReturn2(char * theString)
{
  return theString;
} // end function testReturn2

// Function: testTest
// a function to test the testReturn function
// which returns a char array that was created inside
// the function, should fail since memory is out of scope
char * testTest(char * expr)
{
  char * sact = testReturn();
  if (strcmp(sact, expr) != 0)
  {
    printf("[testTest] - Expected %s, got %s\n", expr, sact);
  }
  else
  {
    printf("[testTest] - Match!\n");
  }
  return "Fail";
} // end function testTest

/*
*** Main ***
*/

int main(int argv, char *argc[])
{
  char * myFirst = "z";
  char myString[4] = "b";
  char mySecond[] = "a";
  //myString = myString + 'A';
  strcat(myString, mySecond);
  //strcat(myString, "0" + 1);
  //strcat(myFirst, mySecond);

  printf("myString: %s\n", myString);
  //puts(myString);
  printf("testString s/b Test: %s\n", testString("Test"));

  testInitialize();
  char * returnString = testReturn();
  printf("returnString, s/b \"I have returned\": %s\n", returnString);

  char * string1 = testReturn();
  char * string2 = "I have returned";
  printf("string1: %s\n", string1);
  printf("string2: %s\n", string2);
  printf("strcmp(string1, string2): %d\n", strcmp(string1, string2));
  printf("string1: %s\n", string1);
  printf("string2: %s\n", string2);

  char * string3 = "I have returned";
  testTest(string3);

  char * string4 = "I have returned!";
  testTest(string4);

  //char * spellCheck1 = "alpha";
  //char * spellCheck2 = "beta";
  char * spellCheck1 = "wars";
  char * spellCheck2 = "ar";
  // ar, cod, code, ewar, wars
  printf("alpha, beta: %d, beta, alpha: %d\n", strcmp(spellCheck1, spellCheck2), strcmp(spellCheck2, spellCheck1));

  return 1;
}
