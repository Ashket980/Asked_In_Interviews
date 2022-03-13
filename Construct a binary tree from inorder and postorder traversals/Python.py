# A class to store a binary tree node
class Node:
    def __init__(self, key):
        self.key = key
 
 
# Recursive function to perform inorder traversal on a given binary tree
def inorderTraversal(root):
 
    if root is None:
        return
 
    inorderTraversal(root.left)
    print(root.key, end=' ')
    inorderTraversal(root.right)
 
 
# Recursive function to perform postorder traversal on a given binary tree
def postorderTraversal(root):
 
    if root is None:
        return
 
    postorderTraversal(root.left)
    postorderTraversal(root.right)
    print(root.key, end=' ')
 
 
# Recursive function to construct a binary tree from a given
# inorder and postorder traversals
def construct(start, end, postorder, pIndex, d):
 
    # base case
    if start > end:
        return None, pIndex
 
    # Consider the next item from the end of a given postorder sequence.
    # This value would be the root node of a subtree formed by sequence
    # inorder[start, end].
    root = Node(postorder[pIndex])
    pIndex = pIndex - 1
 
    # search the current node index in inorder sequence to determine
    # the boundary of the left and right subtree of the current node
    index = d[root.key]
 
    # recursively construct the right subtree
    root.right, pIndex = construct(index + 1, end, postorder, pIndex, d)
 
    # recursively construct the left subtree
    root.left, pIndex = construct(start, index - 1, postorder, pIndex, d)
 
    # return the root node
    return root, pIndex
 
 
# Construct a binary tree from inorder and postorder traversals.
# This function assumes that the input is valid, i.e., given
# inorder and postorder sequences forming a binary tree.
def constructTree(inorder, postorder):
 
    # get size
    n = len(inorder)
 
    # dictionary is used to efficiently find the index of any element in
    # a given inorder sequence
    d = {}
    for i, e in enumerate(inorder):
        d[e] = i
 
    # `pIndex` stores the index of the next unprocessed node from the end
    # of the postorder sequence
    pIndex = n - 1
    return construct(0, n - 1, postorder, pIndex, d)[0]
 
 
if __name__ == '__main__':
 
    ''' Construct the following tree
               1
             /   \
            /     \
           2       3
          /       / \
         /       /   \
        4       5     6
               / \
              /   \
             7     8
        '''
 
    inorder = [4, 2, 1, 7, 5, 8, 3, 6]
    postorder = [4, 2, 7, 8, 5, 6, 3, 1]
 
    root = constructTree(inorder, postorder)
 
    # traverse the constructed tree
    print('Inorder traversal is ', end='')
    inorderTraversal(root)
 
    print('\nPostorder traversal is ', end='')
    postorderTraversal(root)
