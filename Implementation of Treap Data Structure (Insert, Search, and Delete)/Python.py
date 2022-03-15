from random import randrange
 
 
# A Treap Node
class TreapNode:
    # constructor
    def __init__(self, data, priority=100, left=None, right=None):
        self.data = data
        self.priority = randrange(priority)
        self.left = left
        self.right = right
 
 
''' Function to left-rotate a given treap
 
      r                       R
     / \     Left Rotate     / \
    L   R       ———>        r   Y
       / \                     / \
      X   Y                   L   X
'''
 
 
def rotateLeft(root):
 
    R = root.right
    X = root.right.left
 
    # rotate
    R.left = root
    root.right = X
 
    # set a new root
    return R
 
 
''' Function to right-rotate a given treap
 
        r                        L
       / \     Right Rotate     / \
      L   R       ———>         X   r
     / \                          / \
    X   Y                        Y   R
'''
 
 
def rotateRight(root):
 
    L = root.left
    Y = root.left.right
 
    # rotate
    L.right = root
    root.left = Y
 
    # set a new root
    return L
 
 
# Recursive function to insert a given key with a priority into treap
def insertNode(root, data):
 
    # base case
    if root is None:
        return TreapNode(data)
 
    # if the given data is less than the root node, insert in the left subtree;
    # otherwise, insert in the right subtree
    if data < root.data:
        root.left = insertNode(root.left, data)
 
        # rotate right if heap property is violated
        if root.left and root.left.priority > root.priority:
            root = rotateRight(root)
    else:
        root.right = insertNode(root.right, data)
 
        # rotate left if heap property is violated
        if root.right and root.right.priority > root.priority:
            root = rotateLeft(root)
 
    return root
 
 
# Recursive function to search for a key in a given treap
def searchNode(root, key):
 
    # if the key is not present in the tree
    if root is None:
        return False
 
    # if the key is found
    if root.data == key:
        return True
 
    # if the key is less than the root node, search in the left subtree
    if key < root.data:
        return searchNode(root.left, key)
 
    # otherwise, search in the right subtree
    return searchNode(root.right, key)
 
 
# Recursive function to delete a key from a given treap
def deleteNode(root, key):
 
    # base case: the key is not found in the tree
    if root is None:
        return None
 
    # if the key is less than the root node, recur for the left subtree
    if key < root.data:
        root.left = deleteNode(root.left, key)
 
    # if the key is more than the root node, recur for the right subtree
    elif key > root.data:
        root.right = deleteNode(root.right, key)
 
    # if the key is found
    else:
 
        # Case 1: node to be deleted has no children (it is a leaf node)
        if root.left is None and root.right is None:
            # deallocate the memory and update root to None
            root = None
 
        # Case 2: node to be deleted has two children
        elif root.left and root.right:
            # if the left child has less priority than the right child
            if root.left.priority < root.right.priority:
                # call `rotateLeft()` on the root
                root = rotateLeft(root)
 
                # recursively delete the left child
                root.left = deleteNode(root.left, key)
            else:
                # call `rotateRight()` on the root
                root = rotateRight(root)
 
                # recursively delete the right child
                root.right = deleteNode(root.right, key)
 
        # Case 3: node to be deleted has only one child
        else:
            # choose a child node
            child = root.left if (root.left) else root.right
            root = child
 
    return root
 
 
# Utility function to print two-dimensional view of a treap using
# reverse inorder traversal
def printTreap(root, space):
 
    height = 10
 
    # Base case
    if root is None:
        return
 
    # increase distance between levels
    space += height
 
    # print the right child first
    printTreap(root.right, space)
 
    # print the current node after padding with spaces
    for i in range(height, space):
        print(' ', end='')
 
    print((root.data, root.priority))
 
    # print the left child
    printTreap(root.left, space)
 
 
if __name__ == '__main__':
 
    # Treap keys
    keys = [5, 2, 1, 4, 9, 8, 10]
 
    # construct a treap
    root = None
    for key in keys:
        root = insertNode(root, key)
 
    print("Constructed :\n\n")
    printTreap(root, 0)
 
    print("\nDeleting node 1:\n\n")
    root = deleteNode(root, 1)
    printTreap(root, 0)
 
    print("\nDeleting node 5:\n\n")
    root = deleteNode(root, 5)
    printTreap(root, 0)
 
    print("\nDeleting node 9:\n\n")
    root = deleteNode(root, 9)
 
    printTreap(root, 0)
