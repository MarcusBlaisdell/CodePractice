import unittest
from BST import Node, insertInOrder, depthFirst, breadthFirst
from BST import levelOrder, inOrder, preOrder, postOrder
from BST import invertTree

class testDepthFirst(unittest.TestCase):
    def testDepth(self):
        Root = Node('G')
        insertInOrder(Root, 'C')
        insertInOrder(Root, 'A')
        insertInOrder(Root, 'I')
        insertInOrder(Root, 'H')
        insertInOrder(Root, 'D')
        '''
        Should build this tree:

                      G
                    /   \
                   C     I
                  / \   /
                 A  D  H
        '''

        ### Test that tree was built as expected:
        self.assertTrue('G' == Root.name)
        self.assertTrue('C' == Root.left.name)
        self.assertTrue('I' == Root.right.name)
        self.assertTrue('A' == Root.left.left.name)
        self.assertTrue('D' == Root.left.right.name)
        self.assertTrue('H' == Root.right.left.name)

        ### Test that depthFirst search function works:
        self.assertTrue(depthFirst(Root, 'A')[0])
        self.assertTrue(depthFirst(Root, 'H')[0])
        self.assertTrue(depthFirst(Root, 'G')[0])
        self.assertFalse(depthFirst(Root, 'Z')[0])

    def testManualBuild(self):
        '''
        Should build:
                 A
               /   \
              B     C
             / \   /
            D  E  F
        '''
        Root = Node('A')
        Root.left = Node('B')
        Root.right = Node('C')
        Root.left.left = Node('D')
        Root.left.right = Node('E')
        Root.right.left = Node('F')

        self.assertTrue(Root.name == 'A')
        self.assertTrue(Root.left.name == 'B')
        self.assertTrue(Root.right.name == 'C')
        self.assertTrue(Root.left.left.name == 'D')
        self.assertTrue(Root.left.right.name == 'E')
        self.assertTrue(Root.right.left.name == 'F')
        self.assertTrue(Root.right.right == None)

    def testTypeDiff(self):
        """
        Verify that you cannot create a tree with multiple data types
        """

        # String and Integer:
        Root = Node('A')
        self.assertFalse(insertInOrder(Root, 2))

        # Integer and String
        Root = Node(5)
        self.assertFalse(insertInOrder(Root, 'D'))

        # Integer and Float
        Root = Node(5)
        self.assertFalse(insertInOrder(Root, 3.0))

        # Float and Integer
        Root = Node(5.0)
        self.assertFalse(insertInOrder(Root, 3))

        ### Verify that same types do work for most common types:
        Root = Node("Aardvark")
        self.assertTrue(insertInOrder(Root, "Ant"))

        ### <int>
        Root = Node(3)
        self.assertTrue(insertInOrder(Root, 2))

        ### <float>
        Root = Node(3.0)
        self.assertTrue(insertInOrder(Root, 2.1))

        ### I'm satisfied

    def testTypeSame(self):
        """
        Verify that you can create a tree of any data type
        """

        ### String: <str>
        Root = Node("Aardvark")
        self.assertTrue(insertInOrder(Root, "Ant"))

        ### Integer: <int>
        Root = Node(3)
        self.assertTrue(insertInOrder(Root, 2))

        ### Float: <float>
        Root = Node(3.0)
        self.assertTrue(insertInOrder(Root, 2.1))

        ### Boolean: <bool>
        Root = Node(True)
        self.assertTrue(insertInOrder(Root, False))

        ### I'm satisfied

    def testBreadth(self):
        Root = Node('G')
        insertInOrder(Root, 'C')
        insertInOrder(Root, 'A')
        insertInOrder(Root, 'I')
        insertInOrder(Root, 'H')
        insertInOrder(Root, 'D')
        '''
        Should build this tree:

                      G
                    /   \
                   C     I
                  / \   /
                 A  D  H
        '''

        ### Test that tree was built as expected:
        self.assertTrue('G' == Root.name)
        self.assertTrue('C' == Root.left.name)
        self.assertTrue('I' == Root.right.name)
        self.assertTrue('A' == Root.left.left.name)
        self.assertTrue('D' == Root.left.right.name)
        self.assertTrue('H' == Root.right.left.name)

        ### Test that breadthFirst search function works:
        self.assertTrue(breadthFirst(Root, 'G'))
        self.assertTrue(breadthFirst(Root, 'A'))
        self.assertTrue(breadthFirst(Root, 'H'))
        self.assertTrue(breadthFirst(Root, 'G'))
        self.assertFalse(breadthFirst(Root, 'Z'))

    def testInOrderTraversal(self):
        Root = Node('G')
        insertInOrder(Root, 'C')
        insertInOrder(Root, 'A')
        insertInOrder(Root, 'I')
        insertInOrder(Root, 'H')
        insertInOrder(Root, 'D')
        '''
        Should build this tree:

                      G
                    /   \
                   C     I
                  / \   /
                 A  D  H
        '''

        ### Test that tree was built as expected:
        self.assertTrue('G' == Root.name)
        self.assertTrue('C' == Root.left.name)
        self.assertTrue('I' == Root.right.name)
        self.assertTrue('A' == Root.left.left.name)
        self.assertTrue('D' == Root.left.right.name)
        self.assertTrue('H' == Root.right.left.name)

        ### Test that in-order traversal function works:
        ### Should be: A, C, D, G, H, I
        correct = ['A', 'C', 'D', 'G', 'H', 'I']
        evaluate = []
        evaluate = inOrder(Root, evaluate)

        for i in range(len(correct)):
            self.assertTrue(correct[i] == evaluate[i])
        print("in order works")

    def testPreOrderTraversal(self):
        Root = Node('G')
        insertInOrder(Root, 'C')
        insertInOrder(Root, 'A')
        insertInOrder(Root, 'I')
        insertInOrder(Root, 'H')
        insertInOrder(Root, 'D')
        '''
        Should build this tree:

                      G
                    /   \
                   C     I
                  / \   /
                 A  D  H
        '''

        ### Test that tree was built as expected:
        self.assertTrue('G' == Root.name)
        self.assertTrue('C' == Root.left.name)
        self.assertTrue('I' == Root.right.name)
        self.assertTrue('A' == Root.left.left.name)
        self.assertTrue('D' == Root.left.right.name)
        self.assertTrue('H' == Root.right.left.name)

        ### Test that in-order traversal function works:
        ### Should be: A, C, D, G, H, I
        correct = ['G', 'C', 'A', 'D', 'I', 'H']
        evaluate = []
        evaluate = preOrder(Root, evaluate)

        for i in range(len(correct)):
            self.assertTrue(correct[i] == evaluate[i])

    def testPostOrderTraversal(self):
        Root = Node('G')
        insertInOrder(Root, 'C')
        insertInOrder(Root, 'A')
        insertInOrder(Root, 'I')
        insertInOrder(Root, 'H')
        insertInOrder(Root, 'D')
        '''
        Should build this tree:

                      G
                    /   \
                   C     I
                  / \   /
                 A  D  H
        '''

        ### Test that tree was built as expected:
        self.assertTrue('G' == Root.name)
        self.assertTrue('C' == Root.left.name)
        self.assertTrue('I' == Root.right.name)
        self.assertTrue('A' == Root.left.left.name)
        self.assertTrue('D' == Root.left.right.name)
        self.assertTrue('H' == Root.right.left.name)

        ### Test that in-order traversal function works:
        ### Should be: A, D, C, H, I, G
        correct = ['A', 'D', 'C', 'H', 'I', 'G']
        evaluate = []
        evaluate = postOrder(Root, evaluate)

        for i in range(len(correct)):
            self.assertTrue(correct[i] == evaluate[i])

    def testLevelOrderTraversal(self):
        Root = Node('G')
        insertInOrder(Root, 'C')
        insertInOrder(Root, 'A')
        insertInOrder(Root, 'I')
        insertInOrder(Root, 'H')
        insertInOrder(Root, 'D')
        '''
        Should build this tree:

                      G
                    /   \
                   C     I
                  / \   /
                 A  D  H
        '''

        ### Test that tree was built as expected:
        self.assertTrue('G' == Root.name)
        self.assertTrue('C' == Root.left.name)
        self.assertTrue('I' == Root.right.name)
        self.assertTrue('A' == Root.left.left.name)
        self.assertTrue('D' == Root.left.right.name)
        self.assertTrue('H' == Root.right.left.name)

        ### Test that breadthFirst traversal function works:
        ### Should print in order: G, C, I, A, D, H
        correct = ['G', 'C', 'I', 'A', 'D', 'H']
        evaluate = levelOrder(Root)

        for i in range(len(correct)):
            self.assertTrue(correct[i] == evaluate[i])

    def testInvert(self):
        Root = Node('G')
        insertInOrder(Root, 'C')
        insertInOrder(Root, 'A')
        insertInOrder(Root, 'I')
        insertInOrder(Root, 'H')
        insertInOrder(Root, 'D')
        '''
        Should build this tree:

                      G
                    /   \
                   C     I
                  / \   /
                 A  D  H
        '''

        ### Test that tree was built as expected:
        self.assertTrue('G' == Root.name)
        self.assertTrue('C' == Root.left.name)
        self.assertTrue('I' == Root.right.name)
        self.assertTrue('A' == Root.left.left.name)
        self.assertTrue('D' == Root.left.right.name)
        self.assertTrue('H' == Root.right.left.name)

        invertTree(Root)

        ### Test that tree was inverted:
        '''

                      G
                    /   \
                   I     C
                    \   / \
                     H D   A
        '''
        self.assertTrue('G' == Root.name)
        self.assertTrue('I' == Root.left.name)
        self.assertTrue('C' == Root.right.name)
        self.assertTrue('H' == Root.left.right.name)
        self.assertTrue('D' == Root.right.left.name)
        self.assertTrue('A' == Root.right.right.name)
