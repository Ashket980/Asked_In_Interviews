# Function to calculate the height of a binary tree represented by
# parent array
def findHeight(parent):
 
    # create an auxiliary array for storing the depth of each tree node
    depth = [0] * len(parent)
 
    # keep track of the height of a tree
    height = -1
 
    # iteratively calculate the depth of each tree node `i`
    for i in range(len(parent)):
 
        # initialize the depth of i'th node with 0 (the depth of a single node)
        depth_i = 0
 
        # trace the path from the i'th node back to the root
        k = i
        while parent[k] != -1:
            # if the depth of the k'th node is already calculated
            if depth[k] != 0:
                depth_i += depth[k]
                break
 
            depth_i += 1
            k = parent[k]
 
        # save subproblem solution
        depth[i] = depth_i
 
        # keep track of the maximum depth
        height = max(height, depth[i])
 
    return height
 
 
if __name__ == '__main__':
 
    parent = [-1, 0, 0, 1, 2, 2, 4, 4]
    print('The height of the binary tree is', findHeight(parent))
