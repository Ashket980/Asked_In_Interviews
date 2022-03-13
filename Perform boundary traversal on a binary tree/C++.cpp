#include <iostream>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
public:
    // Utility function to check if a given node is a leaf node
    bool isLeaf() {
        return this->left == nullptr && this->right == nullptr;
    }
};
 
// Recursive function to print the left boundary of the given binary tree
// in a top-down fashion, except for the leaf nodes
void printLeftBoundary(Node* root)
{
    // base case: root is empty
    if (!root) {
        return;
    }
 
    Node* node = root;
 
    // do for all non-leaf nodes
    while (!node->isLeaf())
    {
        // print the current node
        cout << node->data << ' ';
 
        // next process, the left child of `root` if it exists;
        // otherwise, move to the right child
        node = (node->left) ? node->left: node->right;
    }
}
 
// Recursive function to print the right boundary of the given binary tree
// in a bottom-up fashion, except for the leaf nodes
void printRightBoundary(Node* root)
{
    // base case: root is empty, or root is a leaf node
    if (!root || root->isLeaf()) {
        return;
    }
 
    // recur for the right child of `root` if it exists;
    // otherwise, recur for the left child
    printRightBoundary(root->right ? root->right: root->left);
 
    // To ensure bottom-up order, print the value of the nodes
    // after recursion unfolds
    cout << root->data << ' ';
}
 
// Recursive function to print the leaf nodes of the given
// binary tree in an inorder fashion
void printLeafNodes(Node* root)
{
    // base case
    if (root == nullptr) {
        return;
    }
 
    // recur for the left subtree
    printLeafNodes(root->left);
 
    // print only leaf nodes
    if (root->isLeaf()) {
        cout << root->data << ' ';
    }
 
    // recur for the right subtree
    printLeafNodes(root->right);
}
 
// Function to perform the boundary traversal on a given tree
void performBoundaryTraversal(Node* root)
{
    // base case
    if (root == nullptr) {
        return;
    }
 
    // print the root node
    cout << root->data << ' ';
 
    // print the left boundary (except leaf nodes)
    printLeftBoundary(root->left);
 
    // print all leaf nodes
    if (!root->isLeaf()) {
        printLeafNodes(root);
    }
 
    // print the right boundary (except leaf nodes)
    printRightBoundary(root->right);
}
 
int main()
{
    // construct a binary tree as per the above diagram
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->right = new Node(10);
    root->right->right->left = new Node(11);
    root->left->left->right->left = new Node(12);
    root->left->left->right->right = new Node(13);
    root->right->right->left->left = new Node(14);
 
    performBoundaryTraversal(root);
 
    return 0;
}
