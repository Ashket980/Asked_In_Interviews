# Recursive function to calculate the depth of the i'th node in `parent[]`
def findDepth(parent, i):
 
    # A root node will have a depth of 0
    if parent[i] == -1:
        return 0
 
    # depth of the i'th node = 1 + depth of its parent
    return 1 + findDepth(parent, parent[i])
 
 
# Function to calculate the height of a binary tree represented by
# parent array
def findHeight(parent):
 
    # keep track of the height of a tree
    height = -1
 
    # calculate the depth of each tree node `i` and keep track of
    # the maximum depth
    for i in range(len(parent)):
        height = max(height, findDepth(parent, i))
 
    return height
 
 
if __name__ == '__main__':
 
    parent = [-1, 0, 0, 1, 2, 2, 4, 4]
    print('The height of the binary tree is', findHeight(parent))
