#include <stdio.h>
 
// Recursive function to calculate the depth of the i'th node in `parent[]`
int findDepth(int parent[], int i)
{
    // A root node will have a depth of 0
    if (parent[i] == -1) {
        return 0;
    }
 
    // depth of the i'th node = 1 + depth of its parent
    return 1 + findDepth(parent, parent[i]);
}
 
// Function to calculate the height of a binary tree represented by
// parent array
int findHeight(int parent[], int n)
{
    // keep track of the height of a tree
    int height = -1;
 
    // calculate the depth of each tree node `i` and keep track of
    // the maximum depth
    for (int i = 0; i < n; i++)
    {
        int depth = findDepth(parent, i);
        if (height < depth) {
            height = depth;
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
