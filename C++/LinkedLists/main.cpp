#include <iostream>
#include <stdlib.h>
#include <time.h>

struct node
{
  int x;
  node *next;
};

int main (int argc, char * argv[])
{
  int maxVal = 52;
  srand(time(NULL));
  int randOne = 0;
  int randTwo = 0;

  node *root = new node;
  node *prev;
  node *cur;
  node *nex;

  // create a linked list:
  cur = root;
  for (int i = 0; i < maxVal; i++)
  {
    cur->x = i;
    if (i < maxVal)
    {
      cur->next = new node;
      cur = cur->next;
    } // end check we are not at last node

  } // end for loop to create linked list
  cur->next = 0;

  // Print the list (forward):
  std::cout << "Forward:" << std::endl;
  cur = root;
  while (cur->next != 0)
  //for (int i = 0; i < 10; i++)
  {
    std::cout << cur->x << ", ";
    cur = cur->next;
  } // end print out linked list
  std::cout << std::endl;


  // randomize the list:
  for (int i = 0; i < 10*maxVal; i++)
  {
    randOne = rand() % (maxVal - 2);
    randTwo = rand() % (maxVal - randOne - 1);
    while (randTwo == 0)
    {
      randTwo = rand() % (maxVal - randOne - 1);
    } // end keep picking numbers until not zero


    std::cout << "randOne: " << randOne;
    std::cout << " randTwo: " << randTwo;
    std::cout << " = " << randOne + randTwo << std::endl;

    cur = root;

    // Move to position one:

    prev = cur;
    cur = cur->next;

    if (randOne == 0)
    {
      root = cur;
      nex = prev;
    } // end if randOne is zero
    else
    {
      for (int j = 1; j < randOne; j++)
      {
        prev = cur;
        cur = cur->next;
      } // end move to first position to grab

      nex = cur;
      prev->next = cur->next;
    } // end else randOne is not zero

    cur = cur->next;

    // move to position two:

    for (int j = 0; j < randTwo - 1; j++)
    {
      prev = cur;
      cur = cur->next;
    } // end move to position two

    if (cur->next == 0)
    {
      nex->next = cur->next;
      cur->next = nex;
      std::cout << "at end" << std::endl;
    }
    else
    {
      nex->next = cur;
      prev->next = nex;
      std::cout << "amid" << std::endl;
    }

    // Print the list (randomized):
    std::cout << "Randomized:" << std::endl;
    cur = root;
    for (int i = 0; i < maxVal; i++)
    //while (cur->next != 0)
    //for (int i = 0; i < 10; i++)
    {
      std::cout << cur->x << ", ";
      cur = cur->next;
    } // end print out linked list

    std::cout << std::endl;


  } // end randomize for loop


  // Print the list (randomized):
  std::cout << "Randomized:" << std::endl;
  cur = root;
  for (int i = 0; i < maxVal; i++)
  //while (cur->next != 0)
  //for (int i = 0; i < 10; i++)
  {
    std::cout << cur->x << ", ";
    cur = cur->next;
  } // end print out linked list

  std::cout << std::endl;


}
