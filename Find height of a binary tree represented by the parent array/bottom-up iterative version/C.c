#include <stdio.h>
 
// Function to calculate the height of a binary tree represented by
// parent array
int findHeight(int parent[], int n)
{
    // create an auxiliary array for storing the depth of each tree node
    int depth[n];
    for (int i = 0; i < n; i++) {
        depth[i] = 0;
    }
 
    // keep track of the height of a tree
    int height = -1;
 
    // iteratively calculate the depth of each tree node `i`
    for (int i = 0; i < n; i++)
    {
        // initialize the depth of i'th node with 0 (the depth of a single node)
        int depth_i = 0;
 
        // trace the path from the i'th node back to the root
        for (int k = i; parent[k] != -1; k = parent[k])
        {
            // if the depth of the k'th node is already calculated
            if (depth[k] != 0)
            {
                depth_i += depth[k];
                break;
            }
            depth_i++;
        }
 
        // save subproblem solution
        depth[i] = depth_i;
 
        // keep track of the maximum depth
        if (height < depth[i]) {
            height = depth[i];
        }
    }
 
    return height;
}
 
int main(void)
{
    int parent[] = {-1, 0, 0, 1, 2, 2, 4, 4};
    int n = sizeof(parent)/sizeof(parent[0]);
 
    printf("The height of the binary tree is %d", findHeight(parent, n));
 
    return 0;
}
