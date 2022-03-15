#include <iostream>
#include <climits>
using namespace std;
 
// Data structure to store a BST node
struct Node
{
    int data;
    Node* left = nullptr, *right = nullptr;
 
    Node() {}
    Node(int data): data(data) {}
};
 
// Function to perform inorder traversal on the tree
void inorder(Node* root)
{
    if (root == nullptr) {
        return;
    }
 
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
 
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
 
// Recursive function to fix a binary tree that is only one swap
// away from becoming a BST. Here, `prev` is the previously processed node
// in inorder traversal, and `x` & `y` stores node to be swapped (if any).
void correctBST(Node* root, Node* &x, Node* &y, Node* &prev)
{
    // base case
    if (root == nullptr) {
        return;
    }
 
    // recur for the left subtree
    correctBST(root->left, x, y, prev);
 
    // if the current node is less than the previous node
    if (root->data < prev->data)
    {
        // if this is the first occurrence, update `x` and `y` to the previous
        // and current node, respectively
        if (x == nullptr) {
            x = prev;
        }
 
        // if this is a second occurrence, update `y` to the current node
        y = root;
    }
 
    // update the previous node and recur for the right subtree
    prev = root;
    correctBST(root->right, x, y, prev);
}
 
// Fix given binary tree that is only one swap away from becoming a BST
void correctBST(Node* root)
{
    // `x` and `y` stores node to be swapped
    Node *x = nullptr, *y = nullptr;
 
    // stores previously processed node in the inorder traversal
    // initialize it by -INFINITY
    Node* prev = new Node(INT_MIN);
 
    // fix the binary tree
    correctBST(root, x, y, prev);
 
    // swap the nodes
    if (x && y) {
        swap(x->data, y->data);
    }
}
 
int main()
{
    int keys[] = { 15, 10, 20, 8, 12, 16, 25 };
 
    /* Construct the following tree
              15
            /    \
           /      \
          10       20
         /  \     /  \
        /    \   /    \
       8     12 16    25
    */
 
    Node* root = nullptr;
    for (int key: keys) {
        root = insert(root, key);
    }
 
    // swap any two nodes' values
    swap(root->left->data, root->right->right->data);
 
    // fix the BST
    correctBST(root);
 
    // print the BST after fixing it
    inorder(root);
 
    return 0;
}
