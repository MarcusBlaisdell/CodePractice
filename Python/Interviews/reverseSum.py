"""
This is a coding question I was given in a Facebook interview:

Given two inputs, e.g. 123, 12
Reverse the numbers (e.g. 123 -> 321, 12 -> 21)

Another example:
60, 40 => 06, 04 => 6, 4 => 6 + 4 = 10
Sum the reverse numbers,
Then, calculate the sum of that number with its reverse:
    321 + 21 = 341 + 143 = 484
The values will be given as strings, not integers.
The values will always be integers, they will not contain decimals.
The values will always be positive, and always greater than zero.
"""

def reverseString(theString):
    """
    A function to reverse a string.
    Strings are immutable in Python so it creates a new string,
    and returns it.
    """

    ### Create empty string, we will append new values to this
    returnString = ""

    ### Use a for loop to loop through all positions,
    ### begin at the end and append each character to the string

    for i in range(len(theString)):
        returnString = returnString + theString[len(theString) - i - 1]

    returnString = removeLeading(returnString)
    return returnString


def reverseSum(string1, string2):
    """
    This function will sum integers from two strings.
    It will begin at the least-significant-digit and
    work backwards.
    Results are appended to a string.
    The string is reversed at the end to get the solution in the correct order.
    """

    ### Create an empty string:

    returnString = ""

    ### We need to know the size of each string:
    size1 = len(string1)
    size2 = len(string2)

    ### We will begin at the last index of each string:
    index1 = size1 - 1
    index2 = size2 - 1

    carry = 0

    ### assume string 1 is the longer string
    while index2 > -1:
        theSum = int(string1[index1]) + int(string2[index2]) + carry

        if theSum > 9:
            carry = 1
        else:
            carry = 0

        returnString = returnString + str(theSum%10)

        index1-=1
        index2-=1

    while index1 > -1:
        theSum = int(string1[index1]) + carry

        if theSum > 9:
            carry = 1
        else:
            carry = 0

        returnString = returnString + str(theSum%10)

        index1-=1

    ### Catch if both strings were of equal size and have a carry:
    if carry == 1:
        returnString = returnString + str(carry)

    returnString = reverseString(returnString)
    return returnString

def removeLeading(theString):
    """
    This function removes leading zeros from a string that
    is representing an integer. E.g. "02" -> "2"
    """
    returnString = ""
    leading = 1
    for i in range(len(theString)):
        if theString[i] != '0':
            leading = 0
        if leading == 0:
            returnString = returnString + theString[i]

    return returnString

def main():
    pass

if __name__=="__main__":
    main()
