"""
This is a coding question I was given in a Facebook interview:

Given two inputs, e.g. 123, 12
Reverse the numbers (e.g. 123 -> 321, 12 -> 21)

Another example:
60, 40 => 06, 04 => 6, 4 => 6 + 4 = 10

Sum the reverse numbers, then,
calculate the sum of that number with its reverse:
    321 + 21 = 341 + 143 = 484

Full: 123, 12 => 321 + 21 = 342 + 243 = 585

The values will be given as strings, not integers.
The values will always be integers, they will not contain decimals.
The values will always be positive, and always greater than zero.

***
This is attempt two.
I want to see if I can do better than the naive solution I
originally came up with.
***
"""

def reverseString(theString):
    """
    Reverse a string.
    Strings are immutable in Python so create a new string that
    is the reverse of the given string, and return it.
    """

    returnString = ""
    stringSize = len(theString)

    leading = 0
    for i in range(stringSize):
        ### eliminate leading zeros:
        ### do not add any characters until we
        ### encounter a non-zero character:
        if theString[stringSize - 1 - i] != '0':
            leading = 1
        if leading == 1:
            returnString = returnString + theString[stringSize - 1 - i]

    return returnString

def reverseSum(string1, string2):
    """
    Sum the strings.
    Return the solutions.
    """

    string1 = reverseString(string1)
    string2 = reverseString(string2)

    print("string1: ", string1)
    print("string2: ", string2)

    

def main():
    reverseSum("123", "12")
    pass

if __name__=="__main__":
    main()
