'''
This is a program to test Linked Lists in Python
'''

### Create a class for our nodes
class Node:
    """
    Node contains any value and a pointer to a next Node:
    """
    def __init__(self, value):
        self.value = value
        self.next = None

### Print the list from head to end:
def printList(Head):
    """
    Print the linked list, starting at the head
    Requires the Head of the list be passed in
    as an argument
    """
    ### While there is another, node,
    ### Print current node and
    ### shift head to next Node:

    while Head.next != None:
        print(Head.value)
        Head = Head.next

    ### Print the last node:
    print(Head.value)

### Provide a function to add a node to the end of
### the list for testing purposes:
def addNode(Head, value):
    """
    Add a Node to an existing Linked List
    New Node value type must match Head Node value type
    """
    if type(Head.value) != type(value):
        print("New Node value type must match existing Node type")
        return 0
    else:
        while Head.next != None:
            Head = Head.next

        Head.next = Node(value)

    return 1

### Insert the node in order, be it alphabetical, or numerical:
### Handle three cases:
### Case 1: insert at beginning,
### Case 2: insert at end,
### Case 3: insert in middle
def insertInOrder(Head, value):
    """
    Insert a new node into the linked list in order
    """
    if type(Head.value) != type(value):
        print("New Node value type must match existing Node type")
        return 0
    else:
        previous = Head
        current = Head
        insert = Node(value)

        ### Case 1: value to insert is less than value at head:
        ### Insert new value at head and return new Node as Head:
        if insert.value < Head.value:
            insert.next = Head
            Head = insert
            return Head
        else:
            while current.value < insert.value:
                if current.next != None:
                    previous = current
                    current = current.next
                elif current.next == None: ### Case 2: current.next == None, insert at end:
                    current.next = insert
                    return Head
                else: ### Case 3: current.next != None, Head.value > insert.value, insert in middle
                    previous.next = insert
                    insert.next = current
                    return Head

        insert.next = current
        previous.next = insert

        return Head

### Use main function:
def main():
    pass

### Check for and run main:
if __name__=="__main__":
    main()
