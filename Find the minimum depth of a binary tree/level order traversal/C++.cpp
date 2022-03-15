#include <iostream>
#include <queue>
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
};
 
// Queue node for storing a pointer to a tree node and its current depth
struct QueueNode
{
    Node* node;
    int depth;
};
 
// Returns true if the given tree node is a leaf, false otherwise
bool isLeaf(Node* node) {
    return node->left == nullptr && node->right == nullptr;
}
 
// Iterative function to find the minimum depth of a path starting
// from the given node in a binary tree
int findMinDepth(Node* root)
{
    // base case
    if (root == nullptr) {
        return 0;
    }
 
    // create an empty queue and push the root node with a depth of 1
    queue<QueueNode> q;
    q.push({root, 1});
 
    // run till queue is empty
    while (!q.empty())
    {
        // dequeue front node
        Node* node = q.front().node;
        int depth = q.front().depth;
 
        q.pop();
 
        // if the popped node is a leaf node, return its depth
        if (isLeaf(node)) {
            return depth;
        }
 
        // enqueue left child of the popped node with +1 depth
        if (node->left) {
            q.push({node->left, depth + 1});
        }
 
        // enqueue right child of the popped node with +1 depth
        if (node->right) {
            q.push({node->right, depth + 1});
        }
    }
}
 
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->right = new Node(8);
    root->left->right->right = new Node(9);
    root->right->right->left = new Node(10);
    root->right->right->left = new Node(11);
    root->left->left->right->right = new Node(12);
 
    cout << "The minimum depth is " << findMinDepth(root);
 
    return 0;
}
