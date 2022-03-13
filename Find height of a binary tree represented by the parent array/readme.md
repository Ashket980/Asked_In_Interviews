## Find height of a binary tree represented by the parent array ## 

**Given an array representing the parent-child relationship in a binary tree, find the tree’s height 
without building it. The parent-child relationship is defined by (A[i], i) for every index i in array A. 
The root node’s value will be i if -1 is present at index i in the array.**


**The depth of a “node” is the total number of edges from the node to the tree’s root node.
The root is the only node whose depth is 0.**


**The height of a “node” is the total number of edges on the longest path from the node to a leaf. 
The height of a “tree” would be the height of its root node, or equivalently, the depth of its deepest node.
A leaf node will have a height of 0.**

    For example,

      Parent: [-1, 0, 0, 1, 2, 2, 4, 4]
      Index:  [0, 1, 2, 3, 4, 5, 6, 7]

      -1 is present at index 0, which implies that the binary tree root is node 0.
      0 is present at index 1 and 2, which implies that the left and right children of node 0 are 1 and 2.
      1 is present at index 3, which implies that the left or the right child of node 1 is 3.
      2 is present at index 4 and 5, which implies that the left and right children of node 2 are 4 and 5.
      4 is present at index 6 and 7, which implies that the left and right children of node 4 are 6 and 7.
