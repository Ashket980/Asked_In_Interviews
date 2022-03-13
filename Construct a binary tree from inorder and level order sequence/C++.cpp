#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int data;
    Node* left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
// Recursive function to perform inorder traversal on a given binary tree
void inorderTraversal(Node* root)
{
    if (root == nullptr) {
        return;
    }
 
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
 
// Recursive function to construct a binary tree from a given inorder and
// level order traversals
Node* buildTree(vector<int> const &inorder, int start, int end,
                unordered_map<int, int> map)
{
    // base case
    if (start > end) {
        return nullptr;
    }
 
    // find the root node index in sequence `inorder[]` to determine the
    // left and right subtree boundary
    int index = start;
    for (int j = start + 1; j <= end; j++)
    {
        // Find node with minimum index in level order traversal.
        // That would be the root node of the sequence inorder[start, end]
        if (map[inorder[j]] < map[inorder[index]]) {
            index = j;
        }
    }
 
    // construct the root node
    Node* root = new Node(inorder[index]);
 
    // recursively construct the left subtree
    root->left = buildTree(inorder, start, index - 1, map);
 
    // recursively construct the right subtree
    root->right = buildTree(inorder, index + 1, end, map);
 
    // return the root node
    return root;
}
 
// Construct a binary tree from inorder and level order traversals
Node* buildTree(vector<int> const &inorder, vector<int> const &level)
{
    int n = inorder.size();
 
    // create a map to efficiently find the index of an element in a
    // level order sequence
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++) {
        map[level[i]] = i;
    }
 
    // construct the tree and return it
    return buildTree(inorder, 0, n - 1, map);
}
 
int main()
{
    vector<int> inorder = { 4, 2, 5, 1, 6, 3, 7 };
    vector<int> level    = { 1, 2, 3, 4, 5, 6, 7 };
 
    Node* root = buildTree(inorder, level);
 
    cout << "Inorder traversal of the constructed tree is ";
    inorderTraversal(root);
 
    return 0;
}
