# Data structure to store a binary tree node
class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right
 
 
# Recursive function to find the minimum depth of a path starting
# from the given node in a binary tree
def findMinDepth(root):
 
    # base case
    if root is None:
        return 0
 
    # find the minimum depth of the left subtree
    l = findMinDepth(root.left)
 
    # find the minimum depth of the right subtree
    r = findMinDepth(root.right)
 
    # if the left child does not exist, consider the depth
    # returned by the right subtree
    if root.left is None:
        return 1 + r
 
    # if the right child does not exist, consider the depth
    # returned by the left subtree
    if root.right is None:
        return 1 + l
 
    # otherwise, choose the minimum depth returned by the
    # left and right subtree
    return min(l, r) + 1
 
 
if __name__ == '__main__':
 
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)
    root.right.left = Node(6)
    root.right.right = Node(7)
    root.left.left.right = Node(8)
    root.left.right.right = Node(9)
    root.right.right.left = Node(10)
    root.right.right.left = Node(11)
    root.left.left.right.right = Node(12)
 
    print('The minimum depth is', findMinDepth(root))
