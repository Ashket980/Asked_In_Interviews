# A class to store a binary tree node
class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right
 
 
# Recursive function to perform inorder traversal on a given binary tree
def inorderTraversal(root):
 
    if root is None:
        return
 
    inorderTraversal(root.left)
    print(root.data, end=' ')
    inorderTraversal(root.right)
 
 
# Recursive function to construct a binary tree from a given inorder and
# level order traversals
def buildTree(inorder, start, end, d):
 
    # base case
    if start > end:
        return None
 
    # find the root node index in sequence `inorder[]` to determine the
    # left and right subtree boundary
    index = start
    for j in range(start + 1, end + 1):
        # Find node with minimum index in level order traversal.
        # That would be the root node of the sequence inorder[start, end]
        if d.get(inorder[j]) < d.get(inorder[index]):
            index = j
 
    # construct the root node
    root = Node(inorder[index])
 
    # recursively construct the left subtree
    root.left = buildTree(inorder, start, index - 1, d)
 
    # recursively construct the right subtree
    root.right = buildTree(inorder, index + 1, end, d)
 
    # return the root node
    return root
 
 
# Construct a binary tree from inorder and level order traversals
def buildBT(inorder, level):
 
    # create a dictionary to efficiently find the index of an element in a
    # level order sequence
    d = {}
    for i, e in enumerate(level):
        d[e] = i
 
    # construct the tree and return it
    return buildTree(inorder, 0, len(inorder) - 1, d)
 
 
if __name__ == '__main__':
 
    inorder = [4, 2, 5, 1, 6, 3, 7]
    level = [1, 2, 3, 4, 5, 6, 7]
 
    root = buildBT(inorder, level)
 
    print('Inorder traversal of the constructed tree is ', end='')
    inorderTraversal(root)
