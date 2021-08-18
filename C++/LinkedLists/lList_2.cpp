#include <iostream>

struct node
{
  int x;
  node *next;
};

int main (int argc, char * argv[])
{
  node *root = new node;
  node *prev;
  node *cur;
  node *nex;

  root->x = 12;

  /*
  std::cout << "root: " << root->x << std::endl;
  root->next = new node;
  root->next->x = 13;
  std::cout << "root->next: " << root->next->x << std::endl;
  */

  // create a linked list:
  cur = root;
  for (int i = 0; i < 10; i++)
  {
    cur->x = i;
    if (i < 10)
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
    std::cout << cur->x << std::endl;
    cur = cur->next;
  } // end print out linked list

  // reverse the list:
  prev = root;
  cur = prev->next;

  //for (int i = 0; i < 9; i++)
  while (cur->next != 0)
  {
    nex = cur->next;
    cur->next = prev;
    prev = cur;
    cur = nex;
  } // end while loop to reverse list

  root->next = cur;

  root = prev;

  // Print the list (reverse):
  std::cout << "Reverse:" << std::endl;
  cur = root;
  while (cur->next != 0)
  //for (int i = 0; i < 10; i++)
  {
    std::cout << cur->x << std::endl;
    cur = cur->next;
  } // end print out linked list

}
