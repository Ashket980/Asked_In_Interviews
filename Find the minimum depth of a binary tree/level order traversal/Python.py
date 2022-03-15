from collections import deque
 
 
# Data structure to store a binary tree node
class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right
 
 
# Queue node for storing a pointer to a tree node and its current depth
class QueueNode:
    def __init__(self, node=None, depth=None):
        self.node = node
        self.depth = depth
 
 
# Returns true if the given tree node is a leaf, false otherwise
def isLeaf(node):
    return node.left is None and node.right is None
 
 
# Iterative function to find the minimum depth of a path starting
# from the given node in a binary tree
def findMinDepth(root):
 
    # base case
    if root is None:
        return 0
 
    # create an empty queue and push the root node with a depth of 1
    q = deque()
    q.append(QueueNode(root, 1))
 
    # run till queue is empty
    while q:
 
        # dequeue front node
        front = q.popleft()
        node = front.node
        depth = front.depth
 
        # if the popped node is a leaf node, return its depth
        if isLeaf(node):
            return depth
 
        # enqueue left child of the popped node with +1 depth
        if node.left:
            q.append(QueueNode(node.left, depth + 1))
 
        # enqueue right child of the popped node with +1 depth
        if node.right:
            q.append(QueueNode(node.right, depth + 1))
 
 
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
