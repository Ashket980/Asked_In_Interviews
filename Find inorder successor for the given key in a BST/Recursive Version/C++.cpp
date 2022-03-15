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
 
// Recursive function to find an inorder successor for the given key in a BST.
// Note that successor `succ` is passed by reference to the function
Node* findSuccessor(Node* root, Node* succ, int key)
{
    // base case
    if (root == nullptr) {
        return succ;
    }
 
    // if a node with the desired value is found, the successor is the minimum value
    // node in its right subtree (if any)
    if (root->data == key)
    {
        if (root->right != nullptr) {
            return findMinimum(root->right);
        }
    }
    // if the given key is less than the root node, recur for the left subtree
    else if (key < root->data)
    {
        // update successor to the current node before recursing in the left subtree
        succ = root;
        return findSuccessor(root->left, succ, key);
    }
 
    // if the given key is more than the root node, recur for the right subtree
    else {
        return findSuccessor(root->right, succ, key);
    }
 
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
        Node* succ = findSuccessor(root, nullptr, key);
 
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
