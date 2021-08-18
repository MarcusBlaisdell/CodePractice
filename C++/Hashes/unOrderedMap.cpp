#include <iostream>
#include <unordered_map>

// Function: iterateList
// Iterate through the hash table that is
// passed in as an argument by reference
// Returns 1 if good
int iterateList(std::unordered_map<std::string, int> &age)
{
  // Print a statement to let us know we are in the function:
  std::cout << "     *** Iterater called ***" << std::endl << std::endl;
  // Iterate:
  for (const std::pair<std::string, int>& tup : age)
  {
    std::cout << "Name: " << tup.first << ", Age: " << tup.second << std::endl;
  } // end for loop to iterate through list

  std::cout << std::endl;

  return 1;
} // end function iterateList

// FUnction checkList
// Checks a list to see if a key exists
int checkList(std::unordered_map<std::string, int> &age, std::string name)
{
  // Print a message to let us know we are in this function:
  std::cout << "     *** checkList called for key: " << name << " ***" << std::endl;
  // Check if key exists:
  if (age.find(name) == age.end())
  {
    std::cout << name << " is not in the list" << std::endl;
    return 0;
  } // end if name not found
  else
  {
    std::cout << name << " is in the list" << std::endl;
    return 1;
  } // end if query is found

  // If we get here, something went wrong, return an error
  return 0;
} // end function checkList

// Function deleteKey
int deleteKey(std::unordered_map<std::string, int> &age, std::string name)
{
  // Print a statement that we are in the function:
  std::cout << "     *** deleteKey called for " << name << " ***" << std::endl;

  // check if the key does in fact exist:
  if (age.find(name) == age.end())
  {
    std::cout << name << " is not in the list" << std::endl;

    return 0;
  } // end check if key exists
  else
  {
    age.erase(name);
    std::cout << name << " has been removed from the list" << std::endl;

    return 1;
  } // end if key is in list, remove it

  // If we get here, something went wrong, return error
  return 0;
} // end function deleteKey


int main(int argv, char *argc[])
{
  std::string query;
  std::unordered_map<std::string, int> age;

  // Insert, 3 ways:
  // way 1
  age["Michael"] = 16;
  // way 2
  age.insert(std::pair<std::string, int>{"Bill", 25});
  // way 3
  age.insert({"Chris", 30});

  // Update, 2 ways:
  // way 1:
  age["Michael"] = 18;
  // way 2:
  age.at("Chris") = 27;

  // test get value:
  //auto it = age.find("Michael");
  //std::cout << "Michael is " << it->second << " years old" << std::endl;

  std::string name = "Michael";
  auto it = age.find(name);
  if (it != age.end())
  {
    std::cout << "Found " << name << std::endl;
    std::cout << "Found " << it->second << std::endl;
  }
  else
  {
    std::cout << "Did not find " << name << std::endl;
  }

  name = "John";
  it = age.find(name);
  if (it != age.end())
  {
    std::cout << "Found" << std::endl;
  }
  else
  {
    std::cout << "Did not find " << name << std::endl;
  }
  //std::cout << "John is " << it->second << " years old" << std::endl;

  // test if exists/not-exists:
  if (checkList(age, "Eric") == 0)
  {
    std::cout << "Not exists works" << std::endl;
  } // end if not-exists works
  else
  {
    std::cout << "Not exists failed" << std::endl;
  } // end report error

  if (checkList(age, "Michael") == 1)
  {
    std::cout << "Exists works" << std::endl;
  } // end if not-exists works
  else
  {
    std::cout << "Exists failed" << std::endl;
  } // end report error

  // Delete a record:
  deleteKey(age, "Michael");

  // print the list:
  iterateList(age);

}
