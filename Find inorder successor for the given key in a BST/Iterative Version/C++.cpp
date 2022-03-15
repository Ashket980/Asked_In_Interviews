#include <iostream>
using namespace std;
 
// Data structure to store a BST node
struct Node
{
    int data;
    Node* left = nullptr, *right = nullptr;
 
    Node() {}
    Node(int data): data(data) {}
};
 
// Recursive function to insert a key into a BST
Node* insert(Node* root, int key)
{
    // if the root is null, create a new node and return it
    if (root == nullptr) {
        return new Node(key);
    }
 
    // if the given key is less than the root node, recur for the left subtree
    if (key < root->data) {
        root->left = insert(root->left, key);
    }
 
    // if the given key is more than the root node, recur for the right subtree
    else {
        root->right = insert(root->right, key);
    }
 
    return root;
}
 
// Helper function to find minimum value node in a given BST
Node* findMinimum(Node* root)
{
    while (root->left) {
        root = root->left;
    }
 
    return root;
}
 
// Iterative function to find an inorder successor for the given key in a BST
Node* findSuccessor(Node* root, int key)
{
    // base case
    if (root == nullptr) {
        return nullptr;
    }
 
    Node* succ = nullptr;
 
    while (1)
    {
        // if the given key is less than the root node, visit the left subtree
        if (key < root->data)
        {
            // update successor to the current node before visiting left subtree
            succ = root;
            root = root->left;
        }
 
        // if the given key is more than the root node, visit the right subtree
        else if (key > root->data) {
            root = root->right;
        }
 
        // if a node with the desired value is found, the successor is the minimum
        // value node in its right subtree (if any)
        else {
            if (root->right) {
                succ = findMinimum(root->right);
            }
            break;
        }
 
        // if the key doesn't exist in the binary tree, return next greater node
        if (!root) {
            return succ;
        }
    }
 
    // return successor, if any
    return succ;
}
 
int main()
{
    int keys[] = { 15, 10, 20, 8, 12, 16, 25 };
 
    /* Construct the following tree
               15
             /    \
            /      \
           10       20
          / \      /  \
         /   \    /    \
        8    12  16    25
    */
 
    Node* root = nullptr;
    for (int key: keys) {
        root = insert(root, key);
    }
 
    // find inorder successor for each key
    for (int key: keys)
    {
        Node* succ = findSuccessor(root, key);
 
        if (succ != nullptr) {
            cout << "The successor of node " << key << " is " << succ->data;
        }
        else {
            cout << "No Successor exists for node " << key;
        }
 
        cout << endl;
    }
 
    return 0;
}
