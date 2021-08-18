import unittest
from reverseSum import reverseString, reverseSum

debug = 0

class testReverseSum(unittest.TestCase):
    def testReverse1(self):
        string1 = "123"
        string2 = "12"

        if debug == 1:
            print("String1: ", string1, ", String2: ", string2)

        string1 = reverseString(string1)
        string2 = reverseString(string2)

        if debug == 1:
            print("String1: ", string1, ", String2: ", string2)

        theSum = reverseSum(string1, string2)
        theSummedSum = reverseSum(theSum, reverseString(theSum))

        if debug == 1:
            print("theSum: ", theSum)
            print("theSummedSum: ", theSummedSum)

        self.assertTrue(theSum == "342")
        self.assertTrue(theSummedSum == "585")

    def testReverse2(self):
        string1 = "40"
        string2 = "60"

        if debug == 1:
            print("String1: ", string1, ", String2: ", string2)

        string1 = reverseString(string1)
        string2 = reverseString(string2)

        if debug == 1:
            print("String1: ", string1, ", String2: ", string2)

        theSum = reverseSum(string1, string2)
        theSummedSum = reverseSum(theSum, reverseString(theSum))

        if debug == 1:
            print("theSum: ", theSum)
            print("theSummedSum: ", theSummedSum)

        self.assertTrue(theSum == "10")
        self.assertTrue(theSummedSum == "11")

    def testReverse3(self):
        string1 = "10"
        string2 = "20"

        if debug == 1:
            print("String1: ", string1, ", String2: ", string2)

        string1 = reverseString(string1)
        string2 = reverseString(string2)

        if debug == 1:
            print("String1: ", string1, ", String2: ", string2)

        theSum = reverseSum(string1, string2)
        theSummedSum = reverseSum(theSum, reverseString(theSum))

        if debug == 1:
            print("theSum: ", theSum)
            print("theSummedSum: ", theSummedSum)

        self.assertTrue(theSum == "3")
        self.assertTrue(theSummedSum == "6")
