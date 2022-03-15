#include <iostream>
#include <vector>
using namespace std;
 
// Data structure to store a Doubly Linked List / BST node
struct Node
{
    // value of node
    int data;
 
    // The `prev` and `next` pointer of the doubly linked list can act as
    // left and right child pointer for the BST, respectively
    Node *prev, *next;
 
    // Constructor
    Node(int data)
    {
        this->data = data;
        this->prev = this->next = nullptr;
    }
};
 
// Function to insert a new node at the beginning of the doubly linked list.
// It takes a reference to the head node of the doubly linked list.
void push(Node* &headRef, int data)
{
    // allocate a new node and link it at the beginning
    Node* node = new Node(data);
    node->next = headRef;
 
    // change `prev` of the existing head node to point to the new node
    if (headRef) {
        headRef->prev = node;
    }
 
    // update head pointer
    headRef = node;
}
 
// Function to print nodes of a doubly linked list
void printListNodes(Node* node)
{
    while (node)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}
 
// Function to print preorder traversal of the BST
void preorder(Node* root)
{
    if (root == nullptr) {
        return;
    }
 
    cout << root->data << " ";
    preorder(root->prev);
    preorder(root->next);
}
 
// Function to push nodes of a given doubly linked list in a vector
void pushDDLNodes(Node* node, vector<Node*> &nodes)
{
    while (node)
    {
        nodes.push_back(node);
        node = node->next;
    }
}
 
// Recursive function to construct a height-balanced BST from
// given nodes in sorted order
Node* buildBalancedBST(vector<Node*> &nodes, int start, int end)
{
    // base case
    if (start > end) {
        return nullptr;
    }
 
    // find the middle index
    int mid = (start + end) / 2;
 
    // The root node will be a node present at the mid-index
    Node* root = nodes[mid];
 
    // recursively construct left and right subtree
    root->prev = buildBalancedBST(nodes, start, mid - 1);
    root->next = buildBalancedBST(nodes, mid + 1, end);
 
    // return root node
    return root;
}
 
// Function to construct a height-balanced BST from a sorted doubly linked list.
// It takes a reference to the head node of the doubly linked list.
Node* convertSortedDLLToBalancedBST(Node*& headRef)
{
    // Push nodes of a given doubly linked list into a vector in the original order
    vector<Node*> nodes;
    pushDDLNodes(headRef, nodes);
 
    // Construct a height-balanced BST from sorted BST nodes
    return buildBalancedBST(nodes, 0, nodes.size() - 1);
}
 
int main()
{
    // points to the head of a doubly linked list
    Node* head = nullptr;
 
    // construct a doubly linked list from sorted keys
    int keys[] = { 25, 20, 18, 15, 12, 10, 8 };
    for (int key: keys) {
        push(head, key);
    }
 
    cout << "Doubly Linked List: ";
    printListNodes(head);
 
    // construct a height-balanced BST from a sorted doubly linked list
    Node* root = convertSortedDLLToBalancedBST(head);
 
    cout << "Preorder traversal of the constructed BST: ";
    preorder(root);
 
    return 0;
}
