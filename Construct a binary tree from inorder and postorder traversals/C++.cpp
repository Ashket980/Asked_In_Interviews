#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int key;
    Node *left, *right;
 
    Node(int key)
    {
        this->key = key;
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
    cout << root->key << ' ';
    inorderTraversal(root->right);
}
 
// Recursive function to perform postorder traversal on a given binary tree
void postorderTraversal(Node* root)
{
    if (root == nullptr) {
        return;
    }
 
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->key << ' ';
}
 
// Recursive function to construct a binary tree from a given
// inorder and postorder traversals
Node* construct(int start, int end,
                vector<int> const &postorder, int &pIndex,
                unordered_map<int, int> &map)
{
    // base case
    if (start > end) {
        return nullptr;
    }
 
    // Consider the next item from the end of a given postorder sequence.
    // This value would be the root node of a subtree formed by sequence
    // inorder[start, end].
    Node* root = new Node(postorder[pIndex--]);
 
    // search the current node index in inorder sequence to determine
    // the boundary of the left and right subtree of the current node
    int index = map[root->key];
 
    // recursively construct the right subtree
    root->right = construct(index + 1, end, postorder, pIndex, map);
 
    // recursively construct the left subtree
    root->left = construct(start, index - 1, postorder, pIndex, map);
 
    // return the root node
    return root;
}
 
// Construct a binary tree from inorder and postorder traversals.
// This function assumes that the input is valid, i.e., given
// inorder and postorder sequences forming a binary tree.
Node* construct(vector<int> const &inorder, vector<int> const &postorder)
{
    int n = inorder.size();
 
    // map is used to efficiently find the index of any element in
    // a given inorder sequence
    unordered_map<int, int> map;
    for (int i = 0; i < inorder.size(); i++) {
        map[inorder[i]] = i;
    }
 
    // `pIndex` stores the index of the next unprocessed node from the end
    // of the postorder sequence
    int pIndex = n - 1;
    return construct(0, n - 1, postorder, pIndex, map);
}
 
int main()
{
    /* Construct the following tree
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
    */
 
    vector<int> inorder = { 4, 2, 1, 7, 5, 8, 3, 6 };
    vector<int> postorder = { 4, 2, 7, 8, 5, 6, 3, 1 };
 
    Node* root = construct(inorder, postorder);
 
    // traverse the constructed tree
    cout << "Inorder traversal is "; inorderTraversal(root);
    cout << "\nPostorder traversal is "; postorderTraversal(root);
 
    return 0;
}
