/*
Which are in?

Given two arrays of strings a1 and a2 return a sorted array r in
lexicographical order of the strings of a1 which are substrings
of strings of a2.

Example 1:

a1 = ["arp", "live", "strong"]

a2 = ["lively", "alive", "harp", "sharp", "armstrong"]

returns ["arp", "live", "strong"]
Example 2:

a1 = ["tarp", "mice", "bull"]

a2 = ["lively", "alive", "harp", "sharp", "armstrong"]

returns []
Notes:

    Arrays are written in "general" notation. See "Your Test Cases"
    for examples in your language.
    In Shell bash a1 and a2 are strings. The return is a string
    where words are separated by commas.

    Beware: r must be without duplicates.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function: bubbleSort
char ** bubbleSort(char ** returnArray, int size)
{
  if (size > 1)
  {
    int i = 0, j = 1;
    char * swap;

    for (i = 0; i < size - 1; i++)
    {
      for (j = i+1; j < size; j++)
      {
        // if word on right is less, alphabetically,
        // than the word on the left, swap them:
        if (strcmp(returnArray[j], returnArray[i]) < 0)
        {
          swap = returnArray[i];
          returnArray[i] = returnArray[j];
          returnArray[j] = swap;

        } // end if right less than left

      } // end inner loop

    } // end outer loop

  } // end only sort if more than one element
  else
  {
    return returnArray;
  } // if only one element, return array as-is

  return returnArray;

} // end function bubbleSort

// Function sortArray:
char** sortArray(char** returnArray, int size)
{
    if (size > 1)
    {
        int index1 = 0;
        int index2 = 1;
        char* temp;

        // Keep checking until we compare the last string
        while (index2 < size)
        {
            if (returnArray[index1][0] > returnArray[index2][0])
            {
                temp = returnArray[index1];
                returnArray[index1] = returnArray[index2];
                returnArray[index2] = temp;
            }
            index1++;
            index2++;
        } // end while loop

        return returnArray;
    } // end only sort if more than one

    return returnArray;
} // end sortArray

// Function: inArray
char** inArray(char* array1[], int sz1, char* array2[], int sz2, int* lg)
{
    *lg = 0;
    int i = 0, j = 0, k = 0, l = 0, m = 0;
    int inFlag = 0; // begin by assuming substring is not in string
    int found = 0;

    // create a dynamic array on the heap of max size strlen(array1):
    char ** returnArray;
    returnArray = malloc(sz1 * sizeof(char*));

    // Check each string in array 1 against each string in array 2:
    // for each substring:
    for (i = 0; i < sz1; i++)
    {
        // for each string:
        for (j = 0; j < sz2; j++)
        {
            // for each letter in string:
            for (k = 0; k < strlen(array2[j]); k++)
            {
                // If there are more characters to match than remain
                // in the string, stop evaluating, substring is obviously
                // not in string
                if ((strlen(array1[i]) - l) > (strlen(array2[j]) - k))
                {
                    inFlag = 0;
                    break;
                } // end stop evaluating
                if (array1[i][l] == array2[j][k])
                {
                    inFlag = 1;
                    if (l < (strlen(array1[i]) - 1))
                    {
                        l++;
                    } // end increment towards end of substring
                    else // if we get to end of substring with matches, set found flag
                    {
                        found = 1;
                        returnArray[m++] = array1[i];
                        *lg += 1;
                    } // end set found flag
                } // end if we have found a pattern match
                else
                {
                    if (found == 0)
                    {

                        inFlag = 0;
                    }
                    l = 0;
                } // end if pattern match fails, reset substring to beginning
            } // end for each letter in string
            if (found == 1)
            {
                l = 0;
                found = 0;
                inFlag = 0;
                break;
            } // end if we found a match, add substring to return array

        } // end for each string in array 2 loop

    } // end for each substring in array 1 loop

    //return sortArray(returnArray, *lg);
    return bubbleSort(returnArray, *lg);

} // end function inArray

// Function: joinStringsStringArray
char* joinStringsStringArray(char* strings[], int count)
{
    char* returnString = malloc(500);
    strcpy(returnString, "{");
    char buffer[50];

    for (int i = 0; i < count; i++)
    {
        sprintf(buffer, "'%s'", strings[i]);
        strcat(returnString, buffer);

        if (i < count - 1)
        {
            strcat(returnString, ",");
        } // end only add comma for not at end

    } // end for loop

    strcat(returnString, "}");

    return returnString;
} // end function joinStringsStringArray

// Function: joinStrings
char* joinStrings(char* strings[], int count)
{

} // end function joinStrings

// Function: dotest:
void dotest(char** u, int szu, char** v, int szv, char* expr)
{
    int lg;
    char** act = inArray(u, szu, v, szv, &lg);

    char* sact = joinStringsStringArray(act, lg);
    char* su = joinStrings(u, szu);
    char* sv = joinStrings(v, szv);

    if (strcmp(sact, expr) != 0)
    {
        printf("Error. Expected \n%s\n but got \n%s\n", expr, sact);
    } // end if
    else
    {
        printf("Pass\n");
    }

} // end function dotest


int main(int argv, char* argc[])
{
    // tests:
    char* arr1a[3] = { "arp", "live", "strong" };
    char* arr2a[5] = { "lively", "alive", "harp", "sharp", "armstrong" };
    dotest(arr1a, 3, arr2a, 5, "{'arp','live','strong'}");

    char* arr1b[7] = { "cod", "code", "wars", "ewar", "pillow", "bed", "phht" };
    char* arr2b[8] = { "lively", "alive", "harp", "sharp", "armstrong", "codewars", "cod", "code" };
    dotest(arr1b, 7, arr2b, 8, "{'cod','code','ewar','wars'}");

    char* arr1c[8] = { "cod", "code", "wars", "ewar", "pillow", "bed", "phht", "ar" };
    char* arr2c[8] = { "lively", "alive", "harp", "sharp", "armstrong", "codewars", "cod", "code" };
    dotest(arr1c, 8, arr2c, 8, "{'ar','cod','code','ewar','wars'}");

    return 1;
}

/*
Best Practices solution from site:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void * a, const void * b);

// sz1: size of array1, sz2: size of array2, lg: size of the returned array
char** inArray(char* array1[], int sz1, char* array2[], int sz2, int* lg) {
    char** result = (char **) malloc(0 * sizeof(char *));
    int cnt = 0;
    for (int i = 0; i < sz1; i++) {
        for (int j = 0; j < sz2; j++) {
            if (strstr(array2[j], array1[i])) {
                result = (char **) realloc(result, (cnt + 1) * sizeof(char *));
                result[cnt] = array1[i];
                cnt++;
                break;
            }
        }
    }
    *lg = cnt;
    qsort(result, cnt, sizeof(const char *), compare);
    return result;
}
*/
