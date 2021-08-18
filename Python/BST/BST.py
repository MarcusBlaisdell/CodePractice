'''
Test a Binary Search Tree in Python
'''

### Create a class for our Nodes:
class Node:
    """
    Node class
    Contains a name that can be any type
    Contains empty left and right branches to attach new nodes to
    """
    def __init__(self, name=''):
        self.name = name
        self.left = None
        self.right = None

### insert new nodes in order, lower values go to the left,
### higher values go to the right:
def insertInOrder(Root, name):
    """
    insertInOrder function
    inserts new nodes in order
    lower values go to the left,
    higher values go to the right

    """
    ### Enforce new nodes must be of the same type as the root node:
    if type(name) != type(Root.name):
        print("name: ", name, " : name type: ", type(name), "   Root type: ", type(Root.name))
        print("The value to be added to the tree must match root type: ", type(Root.name))
        return 0

    if name < Root.name:
        if Root.left != None:
            insertInOrder(Root.left, name)
        else:
            Root.left = Node(name)
    else:
        if Root.right != None:
            insertInOrder(Root.right, name)
        else:
            Root.right = Node(name)

    ### If everything went well, return True
    return 1

### Use depth-first-search to find a given node:
def depthFirst(Root, name):
    """
    depthFirst function
    searches for a given node using depth-first search
    """

    if Root == None:
        return 0, name + " was not found in this tree"
    elif Root.name == name:
        return 1, name + " has been found by depthFirst"
    elif Root.left == None and Root.right == None:
        return 0, name + " was not found in this tree"
    elif name < Root.name:
        return depthFirst(Root.left, name)
    elif name > Root.name:
        return depthFirst(Root.right, name)
    else:
        return 0, name + " was not found in this tree"

### Use breadth-first search to find a given node
def breadthFirst(Root, name):
    """
    breadthFirst function
    Searches for a given node using breadth-first search
    """
    ### Use a flag to indicate the pattern has been found:
    ### 0 indicates it has not been found,
    ### 1 indicates it has been found
    Found = 0
    ### Initialize a list with the Root Node:
    List = [Root]

    ### While the list is not empty, continue searching for the pattern
    ### Check all nodes in the list, add child nodes to the list
    ### as we traverse it, once we finish iterating through the list,
    ### pop off the node we just checked
    while List != [] and Found != 1:
        j = len(List)
        for i in range(j):
            if List[i].name == name:
                Found = 1
            else:
                if List[i].left != None:
                    List.append(List[i].left)
                if List[i].right != None:
                    List.append(List[i].right)

        for i in range(j):
            List.pop(0)

    if Found == 1:
        print(name + " has been found by breadthFirst")
        return 1

    else:
        print(name + " Was not found")
        return 0

### Traversals:
###      1
###    /  \
###   2   3
###  / \
### 4  5
### Depth First Traversals:
### (a) Inorder (Left, Root, Right) : 4 2 5 1 3
### (b) Preorder (Root, Left, Right) : 1 2 4 5 3
### (c) Postorder (Left, Right, Root) : 4 5 2 3 1
### Breadth First or Level Order Traversal : 1 2 3 4 5

### (a) Inorder (Left, Root, Right) : 4 2 5 1 3
def inOrder(Root, inList):
    """
    Print the tree using in-order traversal:
     - left node, root node, right node
     Requires that an empty list be passed in to
     track all nodes
     returns a list with all node names in the in-order
    """

    if Root.left != None:
        inList = inOrder(Root.left, inList)
        inList.append(Root.name)
        if Root.right != None:
            inList = inOrder(Root.right, inList)
            return inList
    else:
        inList.append(Root.name)
        return inList

    return inList


### (b) Preorder (Root, Left, Right) : 1 2 4 5 3
def preOrder(Root, preList):
    """
    Print the tree using in-order traversal:
     - root node, left node, right node
     Requires that an empty list be passed in to
     track all nodes
     returns a list with all node names in the pre-order
    """

    preList.append(Root.name)

    if Root.left != None:
        preList = preOrder(Root.left, preList)
        if Root.right != None:
            preList = preOrder(Root.right, preList)
    else:
        return preList

    return preList

### (c) Postorder (Left, Right, Root) : 4 5 2 3 1
def postOrder(Root, postList):
    """
    Print the tree using post-order traversal:
     - left node, right node, root node
     Requires that an empty list be passed in to
     track all nodes
     returns a list with all node names in the post-order
    """

    if Root.left != None:
        postList = postOrder(Root.left, postList)
        if Root.right != None:
            postList = postOrder(Root.right, postList)
    postList.append(Root.name)
    return postList

### Print the tree using level-order or breadth-first ordering:
def levelOrder(Root):
    """
    Breadth First / Level Order Traversal
    Print the Tree by level, Root down, left to right
    """
    ### Initialize a list with the Root Node:
    List = [Root]
    levelList = []

    ### While the list is not empty, continue printing node names
    ### Check all nodes in the list, add child nodes to the list
    ### as we traverse it, once we finish iterating through the list,
    ### pop off the node we just checked
    while List != []:
        j = len(List)
        for i in range(j):
            levelList.append(List[i].name)
            if List[i].left != None:
                List.append(List[i].left)
            if List[i].right != None:
                List.append(List[i].right)

        for i in range(j):
            List.pop(0)

    return levelList

### "Invert" the tree (Actually a reflection about the root but whatever)
def invertTree(Root):
    """
    "Invert" (Reflect about root) a given BST
    """

    temp = Root.left
    Root.left = Root.right
    Root.right = temp

    if Root.left != None:
        invertTree(Root.left)
    if Root.right != None:
        invertTree(Root.right)

### Main function:
def main():
    pass


if __name__=="__main__":
    main()
