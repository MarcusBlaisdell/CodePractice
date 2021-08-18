class Node:
    def __init__(self, name=''):
        self.name = name
        self.left = None
        self.right = None

def insertInOrder(Root, Node):
    if Node.name < Root.name:
        if Node.left != None:
            #Root = Node.left
            insertInOrder(Node.left, Node)
        else:
            Root.left = Node
            print("Root.name=", Root.name)
    else:
        if Node.right != None:
            Root = Node.right
            insertInOrder(Root, Node)
        else:
            Root.right = Node

def insertTest(Root, Node):
    print("Root.name: ", Root.name)
    print("Node.name: ", Node.name)
    if Root.left != None:
        print("Root.left.name: ", Root.left.name)
        insertTest(Root.left, Node)

def main():
    Root = Node('G')
    Root.left = Node('C')
    Root.left.left = Node('A')
    Root.right = Node('I')

    '''
    print("Root (G): ", Root.name)
    print("Root.left (C): ", Root.left.name)
    print("Root.right (I): ", Root.right.name)
    print("Root.left.left (A): ", Root.left.left.name)
    '''
    insertTest(Root, Root.left)

if __name__=="__main__":
    main()
