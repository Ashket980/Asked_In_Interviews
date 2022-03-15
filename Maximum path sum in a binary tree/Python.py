import sys
 
 
# A class to store a binary tree node
class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right
 
 
# Recursive function to find the maximum path sum "starting" from the
# given node in a binary tree. The maximum path sum between two nodes
# in a binary tree is updated in the `result`
def findMaxPathSum(node, result=-sys.maxsize):
 
    # base case: empty tree
    if node is None:
        return 0, result
 
    # find maximum path sum "starting" from the left child
    left, result = findMaxPathSum(node.left, result)
 
    # find maximum path sum "starting" from the right child
    right, result = findMaxPathSum(node.right, result)
 
    # Try all possible combinations to get the optimal result
    result = max(result, node.data)
    result = max(result, node.data + left)
    result = max(result, node.data + right)
    result = max(result, node.data + left + right)
 
    # return the maximum path sum "starting" from the given node
    return max(node.data, node.data + max(left, right)), result
 
 
if __name__ == '__main__':
 
    root = None
 
    ''' Construct the following tree
            1
          /   \
         /     \
        2      10
       / \    /  \
     -1  -4  -5   -6
         /   / \
        3   7   4
             \
             -2
    '''
 
    root = Node(1)
    root.left = Node(2)
    root.right = Node(10)
    root.left.left = Node(-1)
    root.left.right = Node(-4)
    root.right.left = Node(-5)
    root.right.right = Node(-6)
    root.left.right.left = Node(4)
    root.right.left.left = Node(7)
    root.right.left.right = Node(4)
    root.right.left.left.right = Node(-2)
 
    print('The maximum path sum is', findMaxPathSum(root)[1])
