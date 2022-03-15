#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
 
// A Treap Node
struct TreapNode
{
    int data;
    int priority;
    TreapNode* left, *right;
 
    // Constructor
    TreapNode(int data)
    {
        this->data = data;
        this->priority = rand() % 100;
        this->left = this->right = nullptr;
    }
};
 
/* Function to left-rotate a given treap
 
      r                         R
     / \      Left Rotate      / \
    L   R        ———>         r   Y
       / \                   / \
      X   Y                 L   X
*/
 
void rotateLeft(TreapNode* &root)
{
    TreapNode* R = root->right;
    TreapNode* X = root->right->left;
 
    // rotate
    R->left = root;
    root->right = X;
 
    // set a new root
    root = R;
}
 
/* Function to right-rotate a given treap
 
        r                        L
       / \     Right Rotate     / \
      L   R       ———>         X   r
     / \                          / \
    X   Y                        Y   R
*/
 
void rotateRight(TreapNode* &root)
{
    TreapNode* L = root->left;
    TreapNode* Y = root->left->right;
 
    // rotate
    L->right = root;
    root->left = Y;
 
    // set a new root
    root = L;
}
 
// Recursive function to insert a given key with a priority into treap
// using a reference parameter
void insertNode(TreapNode* &root, int data)
{
    // base case
    if (root == nullptr)
    {
        root = new TreapNode(data);
        return;
    }
 
    // if the given data is less than the root node, insert in the left subtree;
    // otherwise, insert in the right subtree
    if (data < root->data)
    {
        insertNode(root->left, data);
 
        // rotate right if heap property is violated
        if (root->left != nullptr && root->left->priority > root->priority) {
            rotateRight(root);
        }
    }
    else {
        insertNode(root->right, data);
 
        // rotate left if heap property is violated
        if (root->right != nullptr && root->right->priority > root->priority) {
            rotateLeft(root);
        }
    }
}
 
// Recursive function to search for a key in a given treap
bool searchNode(TreapNode* root, int key)
{
    // if the key is not present in the tree
    if (root == nullptr) {
        return false;
    }
 
    // if the key is found
    if (root->data == key) {
        return true;
    }
 
    // if the key is less than the root node, search in the left subtree
    if (key < root->data) {
        return searchNode(root->left, key);
    }
 
    // otherwise, search in the right subtree
    return searchNode(root->right, key);
}
 
// Recursive function to delete a key from a given treap
void deleteNode(TreapNode* &root, int key)
{
    // base case: the key is not found in the tree
    if (root == nullptr) {
        return;
    }
 
    // if the key is less than the root node, recur for the left subtree
    if (key < root->data) {
        deleteNode(root->left, key);
    }
 
    // if the key is more than the root node, recur for the right subtree
    else if (key > root->data) {
        deleteNode(root->right, key);
    }
 
    // if the key is found
    else {
        // Case 1: node to be deleted has no children (it is a leaf node)
        if (root->left == nullptr && root->right == nullptr)
        {
            // deallocate the memory and update root to null
            delete root;
            root = nullptr;
        }
 
        // Case 2: node to be deleted has two children
        else if (root->left && root->right)
        {
            // if the left child has less priority than the right child
            if (root->left->priority < root->right->priority)
            {
                // call `rotateLeft()` on the root
                rotateLeft(root);
 
                // recursively delete the left child
                deleteNode(root->left, key);
            }
            else {
                // call `rotateRight()` on the root
                rotateRight(root);
 
                // recursively delete the right child
                deleteNode(root->right, key);
            }
        }
 
        // Case 3: node to be deleted has only one child
        else {
            // choose a child node
            TreapNode* child = (root->left)? root->left: root->right;
            TreapNode* curr = root;
 
            root = child;
 
            // deallocate the memory
            delete curr;
        }
    }
}
 
// Utility function to print two-dimensional view of a treap using
// reverse inorder traversal
void printTreap(TreapNode *root, int space = 0, int height = 10)
{
    // Base case
    if (root == nullptr) {
        return;
    }
 
    // increase distance between levels
    space += height;
 
    // print the right child first
    printTreap(root->right, space);
    cout << endl;
 
    // print the current node after padding with spaces
    for (int i = height; i < space; i++) {
        cout << ' ';
    }
    cout << root->data << "(" << root->priority << ")\n";
 
    // print the left child
    cout << endl;
    printTreap(root->left, space);
}
 
int main()
{
    // Treap keys
    int keys[] = { 5, 2, 1, 4, 9, 8, 10 };
 
    int n = sizeof(keys)/sizeof(int);
 
    // Construct a treap
    TreapNode* root = nullptr;
    srand(time(nullptr));
 
    for (int key: keys) {
        insertNode(root, key);
    }
 
    cout << "Constructed treap:\n\n";
    printTreap(root);
 
    cout << "\nDeleting node 1:\n\n";
    deleteNode(root, 1);
    printTreap(root);
 
    cout << "\nDeleting node 5:\n\n";
    deleteNode(root, 5);
    printTreap(root);
 
    cout << "\nDeleting node 9:\n\n";
    deleteNode(root, 9);
    printTreap(root);
 
    return 0;
}
