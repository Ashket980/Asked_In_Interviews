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
 
 
# Iterative function to find an inorder successor for the given key in a BST
def findSuccessor(root, key):
 
    # base case
    if not root:
        return None
 
    succ = None
 
    while True:
 
        # if the given key is less than the root node, visit the left subtree
        if key < root.data:
            # update successor to the current node before visiting
            # left subtree
            succ = root
            root = root.left
 
        # if the given key is more than the root node, visit the right subtree
        elif key > root.data:
            root = root.right
 
        # if a node with the desired value is found, the successor is the minimum
        # value node in its right subtree (if any)
        else:
            if root.right:
                succ = findMinimum(root.right)
            break
 
        # if the key doesn't exist in the binary tree, return next greater node
        if root is None:
            return succ
 
    # return successor, if any
    return succ
 
 
if __name__ == '__main__':
 
    keys = [15, 10, 20, 8, 12, 16, 25]
 
    ''' Construct the following tree
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
        succ = findSuccessor(root, key)
        if succ:
            print(f'The successor of node {key} is {succ.data}')
        else:
            print(f'No Successor exists for node {key}')
