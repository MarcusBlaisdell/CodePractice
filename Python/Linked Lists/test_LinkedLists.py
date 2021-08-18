import unittest
import random

from linkedList import Node, addNode, insertInOrder
### Create some unit tests:
class QuickTestLinkedList(unittest.TestCase):
    """
    Check that insertInOrder works as we expect it to
    by inserting new items that should go at the beginning,
    in the middle, and at the end
    """
    def testAllCases(self):
        ### Manually test all three cases:
        ### Create a Head Node:
        Head = Node("C")
        ### Insert in front:
        Head = insertInOrder(Head, "B")
        ### Insert at end:
        Head = insertInOrder(Head, "F")
        ### Insert at Front again:
        Head = insertInOrder(Head, "A")
        ### Insert in middle:
        Head = insertInOrder(Head, "E")
        ### Insert at end:
        Head = insertInOrder(Head, "G")
        ### Insert in middle:
        Head = insertInOrder(Head, "D")

        theList = ["A", "B", "C", "D", "E", "F", "G"]
        i = 0
        while Head.next != None:
            self.assertTrue(Head.value == theList[i])
            Head = Head.next
            i += 1

        self.assertTrue(Head.value == theList[i])

class TestLinkedListRandom(unittest.TestCase):
    """
    Test the linked list functions by generating one ordered list,
    and one random list, each with the same values, insert in order
    the items from the random list and verify that they match the
    ordered list after insertion
    Test with both char and with integers
    """
    def testRandomChar(self):
        ### Use two lists, one ordered, one randomized,
        ### Random list will be used to create the linked list,
        ### using insertInOrder, the ordered list will be used
        ### to test:
        theList = []
        randomList = []

        ### Fill both lists with all uppercase letters of alphabet:
        for i in range(ord("A"),ord("Z") + 1):
            theList.append(chr(i))
            randomList.append(chr(i))

        ### shuffle the random list:
        random.shuffle(randomList)

        ### test insertInOrder:

        ### Create Head Node:
        Head = Node(randomList[0])

        for i in range(1,26):
            Head = insertInOrder(Head, randomList[i])

        ### Run comparison:

        for i in theList:
            self.assertTrue(Head.value == i)
            Head = Head.next

    def testRandomInt(self):
        ### Use two lists, one ordered, one randomized,
        ### Random list will be used to create the linked list,
        ### using insertInOrder, the ordered list will be used
        ### to test:
        theList = []
        randomList = []

        ### Fill both lists with all uppercase letters of alphabet:
        for i in range(1,101):
            theList.append(i)
            randomList.append(i)

        ### shuffle the random list:
        random.shuffle(randomList)

        ### test insertInOrder:

        ### Create Head Node:
        Head = Node(randomList[0])

        for i in range(1,100):
            Head = insertInOrder(Head, randomList[i])

        ### Run comparison:

        for i in theList:
            self.assertTrue(Head.value == i)
            Head = Head.next

class testTypeMixing(unittest.TestCase):
    """
    Test that the functions will not allow a user to mix data types
    """

    def testMix1(self):
        Head = Node("A")
        self.assertFalse(addNode(Head, 1))
        self.assertTrue(addNode(Head, "B"))

    def testMix2(self):
        Head = Node(1)
        self.assertFalse(addNode(Head, "A"))
        self.assertTrue(addNode(Head, 2))

    def testMix3(self):
        Head = Node("A")
        self.assertFalse(insertInOrder(Head, 1))
        self.assertTrue(insertInOrder(Head, "B"))

    def testMix4(self):
        Head = Node(1)
        self.assertFalse(insertInOrder(Head, "A"))
        self.assertTrue(insertInOrder(Head, 2))

    def testMix5(self):
        Head = Node(1.0)
        self.assertFalse(insertInOrder(Head, 2))
        self.assertTrue(insertInOrder(Head, 2.0))

    def testMix6(self):
        Head = Node(1)
        self.assertFalse(insertInOrder(Head, 2.0))
        self.assertTrue(insertInOrder(Head, 2))

class testNegativeNumbers(unittest.TestCase):
    """
    Test that negative numbers are inserted correctly
    """

    def testNegatives(self):
        ### Build the lists:
        theList = []
        randomList = []

        for i in range(-49, 50):
            theList.append(i)
            randomList.append(i)

        random.shuffle(randomList)

        ### Build the Linked List:
        Head = Node(randomList[0])
        for i in range(1, len(randomList)):
            Head = insertInOrder(Head, randomList[i])

        ### Test the Linked List:
        for i in theList:
            self.assertTrue(i == Head.value)
            Head = Head.next
