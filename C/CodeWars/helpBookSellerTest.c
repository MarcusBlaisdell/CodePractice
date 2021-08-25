#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <criterion/criterion.h>

char* stockSummary(char** lstOfArt, int szlst, char** categories, int szcat);

void dotest(char** lstOfArt, int szlst, char** categories, int szcat, char* expr)
{
    char* sact = stockSummary(lstOfArt, szlst, categories, szcat);

    if(strcmp(sact, expr) != 0)
    {
      printf("Error. Expected \n%s\n but got \n%s\n", expr, sact);
    }

    cr_assert_str_eq(sact, expr, "");

    if (strcmp(sact, "") != 0)
    {
      free(sact); sact = NULL;
    }
}

Test(kata, ShouldPassAllTheTestsProvided)
{
    {
        char* art[5] = {"ABAR 200", "CDXE 500", "BKWR 250", "BTSQ 890", "DRTY 600"};
        char* cd[2] = {"A", "B"};
        dotest(art, 5, cd, 2, "(A : 200) - (B : 1140)");
    }
    {
        char* art[0] = {};
        char* cd[4] = {"B", "R", "D", "X"};
        dotest(art, 0, cd, 4, "");
    }
}
