# A class to store a BST node
class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right
 
 
# Recursive function to insert a key into a BST
def insert(root, key):
 
    # if the root is None, create a new node and return it
    if root is None:
        return Node(key)
 
    # if the given key is less than the root node, recur for the left subtree
    if key < root.data:
        root.left = insert(root.left, key)
 
    # if the given key is more than the root node, recur for the right subtree
    else:
        root.right = insert(root.right, key)
 
    return root
 
 
# Helper function to find minimum value node in a given BST
def findMinimum(root):
    while root.left:
        root = root.left
    return root
 
 
# Recursive function to find an inorder successor for a given key in a BST
def findSuccessor(root, succ, key):
 
    # base case
    if root is None:
        return succ
 
    # if a node with the desired value is found, the successor is the minimum value
    # node in its right subtree (if any)
    if root.data == key:
        if root.right:
            return findMinimum(root.right)
 
    # if the given key is less than the root node, recur for the left subtree
    elif key < root.data:
 
        # update successor to the current node before recursing in the left subtree
        succ = root
        return findSuccessor(root.left, succ, key)
 
    # if the given key is more than the root node, recur for the right subtree
    else:
        return findSuccessor(root.right, succ, key)
 
    return succ
 
 
if __name__ == '__main__':
 
    keys = [15, 10, 20, 8, 12, 16, 25]
 
    ''' Construct the following BST
               15
             /    \
            /      \
           10       20
          / \      /  \
         /   \    /    \
        8    12  16    25
    '''
 
    root = None
    for key in keys:
        root = insert(root, key)
 
    # find inorder successor for each key
    for key in keys:
        succ = findSuccessor(root, None, key)
 
        if succ:
            print(f'The successor of node {key} is {succ.data}')
        else:
            print(f'No Successor exists for node {key}')
