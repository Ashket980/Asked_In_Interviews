import sys
 
 
# A class to store a binary tree node
class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right
 
 
# Function to perform inorder traversal on the tree
def inorder(root):
 
    if root is None:
        return
 
    inorder(root.left)
    print(root.data, end=' ')
    inorder(root.right)
 
 
# Function to exchange data of given tree nodes
def swapData(first, second):
 
    data = first.data
    first.data = second.data
    second.data = data
 
 
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
 
 
# Recursive function to fix a binary tree that is only one swap
# away from becoming a BST. Here, `prev` is the previously processed node
# in inorder traversal, and `x` & `y` stores node to be swapped (if any).
def correctBST(root, x, y, prev):
 
    # base case
    if root is None:
        return x, y, prev
 
    # recur for the left subtree
    x, y, prev = correctBST(root.left, x, y, prev)
 
    # if the current node is less than the previous node
    if root.data < prev.data:
        # if this is the first occurrence, update `x` and `y` to the previous
        # and current node, respectively
        if x is None:
            x = prev
 
        # if this is a second occurrence, update `y` to the current node
        y = root
 
    # update the previous node and recur for the right subtree
    prev = root
    return correctBST(root.right, x, y, prev)
 
 
# Fix given binary tree that is only one swap away from becoming a BST
def fixBST(root):
 
    # `x` and `y` stores node to be swapped
 
    # stores previously processed node in the inorder traversal
    # initialize it by -INFINITY
    prev = Node(-sys.maxsize)
 
    # fix the binary tree
    x, y, prev = correctBST(root, None, None, prev)
 
    # swap the nodes' data
    if x and y:
        swapData(x, y)
 
 
if __name__ == '__main__':
 
    keys = [15, 10, 20, 8, 12, 16, 25]
 
    ''' Construct the following BST
              15
            /    \
           /      \
          10       20
         /  \     /  \
        /    \   /    \
       8     12 16    25
    '''
 
    root = None
    for key in keys:
        root = insert(root, key)
 
    # swap any two nodes' values
    swapData(root.left, root.right.right)
 
    # fix the BST
    fixBST(root)
 
    # print the BST after fixing it
    inorder(root)
