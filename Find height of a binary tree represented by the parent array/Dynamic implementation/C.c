#include <stdio.h>
 
// Recursive function to calculate the depth of the i'th node in `parent[]`
int findDepth(int parent[], int depth[], int i)
{
    // A root node will have a depth of 0
    if (parent[i] == -1) {
        return 0;
    }
 
    // If the depth of the i'th node is already calculated, return it
    if (depth[i] != 0) {
        return depth[i];
    }
 
    // depth of the i'th node = 1 + depth of its parent
    return 1 + findDepth(parent, depth, parent[i]);
}
 
// Function to calculate the height of a binary tree represented by
// parent array
int findHeight(int parent[], int n)
{
    // keep track of the height of a tree
    int height = -1;
 
    // create an auxiliary array for storing the depth of each tree node
    int depth[n];
    for (int i = 0; i < n; i++) {
        depth[i] = 0;
    }
 
    // calculate the depth of each tree node `i` and keep track of
    // the maximum depth
    for (int i = 0; i < n; i++)
    {
        depth[i] = findDepth(parent, depth, i);
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
