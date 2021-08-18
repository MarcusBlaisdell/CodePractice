import unittest
from targetIndexes import findIndexes

### Use debug levels for printing,
### debug value of 1 means print information level 1, etc.
debug = 0

class testFindIndexes(unittest.TestCase):
    """
    Test the findIndexes function of the targetIndexes program
    """
    def testListOne(self):
        """
        Create one list and test it with three targets
        Passes if certain things we know should be true are true
        """
        myList = [-3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13]

        newList = findIndexes(myList, 10)
        self.assertTrue(len(newList) == 8)
        self.assertTrue(newList[0] == [9, 7])
        self.assertTrue(newList[-1] == [16, 0])
        
        if debug == 1:
            print("--")

        newList = findIndexes(myList, 9)
        self.assertTrue(len(newList) == 8)
        self.assertTrue(newList[0] == [8, 7])
        self.assertTrue(newList[-1] == [15, 0])

        if debug == 1:
            print("--")

        newList = findIndexes(myList, 5)
        self.assertTrue(len(newList) == 6)
        self.assertTrue(newList[0] == [6, 5])
        self.assertTrue(newList[-1] == [11, 0])
