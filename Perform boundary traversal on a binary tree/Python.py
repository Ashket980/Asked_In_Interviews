# A class to store a binary tree node
class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right
 
    # Utility function to check if a given node is a leaf node
    def isLeaf(self):
        return self.left is None and self.right is None
 
 
# Recursive function to print the left boundary of the given binary tree
# in a top-down fashion, except for the leaf nodes
def printLeftBoundary(root):
 
    # base case: root is empty
    if root is None:
        return
 
    node = root
 
    # do for all non-leaf nodes
    while not node.isLeaf():
        # print the current node
        print(node.data, end=' ')
 
        # next process, the left child of `root` if it exists;
        # otherwise, move to the right child
        node = node.left if node.left else node.right
 
 
# Recursive function to print the right boundary of the given binary tree
# in a bottom-up fashion, except for the leaf nodes
def printRightBoundary(root):
 
    # base case: root is empty, or root is a leaf node
    if root is None or root.isLeaf():
        return
 
    # recur for the right child of `root` if it exists;
    # otherwise, recur for the left child
    printRightBoundary(root.right if root.right else root.left)
 
    # To ensure bottom-up order, print the value of the nodes
    # after recursion unfolds
    print(root.data, end=' ')
 
 
# Recursive function to print the leaf nodes of the given
# binary tree in an inorder fashion
def printLeafNodes(root):
 
    # base case
    if root is None:
        return
 
    # recur for the left subtree
    printLeafNodes(root.left)
 
    # print only leaf nodes
    if root.isLeaf():
        print(root.data, end=' ')
 
    # recur for the right subtree
    printLeafNodes(root.right)
 
 
# Function to perform the boundary traversal on a given tree
def performBoundaryTraversal(root):
 
    # base case
    if root is None:
        return
 
    # print the root node
    print(root.data, end=' ')
 
    # print the left boundary (except leaf nodes)
    printLeftBoundary(root.left)
 
    # print all leaf nodes
    if not root.isLeaf():
        printLeafNodes(root)
 
    # print the right boundary (except leaf nodes)
    printRightBoundary(root.right)
 
 
if __name__ == '__main__':
 
    # construct a binary tree as per the above diagram
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)
    root.right.left = Node(6)
    root.right.right = Node(7)
    root.left.left.left = Node(8)
    root.left.left.right = Node(9)
    root.left.right.right = Node(10)
    root.right.right.left = Node(11)
    root.left.left.right.left = Node(12)
    root.left.left.right.right = Node(13)
    root.right.right.left.left = Node(14)
 
    performBoundaryTraversal(root)
