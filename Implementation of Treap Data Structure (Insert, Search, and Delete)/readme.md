#Implementation of Treap Data Structure (Insert, Search, and Delete)

**This post will implement treap data structure and perform basic operations like insert, search, and delete on it.**

**In the previous post, we have discussed treap data structure, a combination of a binary search tree and a heap. 
This post will implement it and perform basic operations like insert, search, and delete on it. Following are the algorithms for basic operations on treap:**

1. Insertion in Treap
To insert a new key x into the treap, generate a random priority y for x. Binary search for x in the tree, and create a 
new node at the leaf position where the binary search determines a node for x should exist. Then as long as x is not the 
root of the tree and has a larger priority number than its parent z, perform a tree rotation that reverses the parent-child
relation between x and z.

2. Deletion in Treap
To delete a node x from the treap, remove it if it is a leaf of the tree. If x has a single child, z, remove x from the tree 
and make z be the child of the parent of x (or make z the root of the tree if x had no parent). Finally, if x has two children,
swap its position in the tree with its immediate successor z in the sorted order, resulting in one of the previous cases. In this 
last case, the swap may violate the heap-ordering property for z, so additional rotations may need to be performed to restore this property.

3. Searching in Treap
To search for a given key value, apply a standard search algorithm in a binary search tree, ignoring the priorities.

 
**Following is the implementation of a treap data structure in C++, Java, and Python demonstrating the above operations:**
