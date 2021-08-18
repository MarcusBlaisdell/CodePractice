#include <iostream>

struct lList
{
  int a;
  lList *next;
};

int main (int argc, char * argv[])
{
  lList *root;
  lList *cur = new lList;
  lList *prev = new lList;
  lList *nex = new lList;

  root = new lList;

  cur = root;
  for (int i = 0; i < 10; i++)
  {
    cur->a = i;
    if (i < 9)
    {
      cur->next = new lList;
      cur = cur->next;
    }

  } // end for loop to build linked list of size 10
  cur->next = 0;

  // print before reversing:
  std::cout << "forward" << std::endl;

  cur = root;
  while (cur->next != 0)
  {
    std::cout << cur->a << std::endl;
    cur = cur->next;
  } // end while loop to print our linked list
  std::cout << cur->a << std::endl;

  //root->a = 5;
  //root->next->a = 6;

  //std::cout << cur->a << std::endl;
  //cur = cur->next;
  //std::cout << cur->a << std::endl;

  //std::cout << root->a << std::endl;
  //std::cout << root->next->a << std::endl;

  // reverse the list:

  prev = root;
  cur = prev->next;
  nex = cur->next;

  while (cur->next != 0)
  {
    std::cout << "prev: " << prev->a << std::endl;
    std::cout << "cur: " << cur->a << std::endl;
    std::cout << "nex: " << nex->a << std::endl;
    cur->next = prev;
    prev = cur;
    cur = nex;
    nex = cur->next;
  }
  cur->next = prev;
  // set root to the current node
  root->next = cur;
  root = prev;

  // print after reversing:
  std::cout << "Reversed" << std::endl;

  cur = root;
  while (cur->next != 0)
  {
    std::cout << cur->a << std::endl;
    cur = cur->next;
  } // end while loop to print our linked list
  //std::cout << cur->a << std::endl;

}
