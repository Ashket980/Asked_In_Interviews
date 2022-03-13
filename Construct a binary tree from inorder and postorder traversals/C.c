#include <stdio.h>
#include <stdlib.h>
 
// Data structure to store a binary tree node
struct Node
{
    int key;
    struct Node *left, *right;
};
 
// Function to create a new binary tree node having a given key
struct Node* newNode(int key)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
 
    return node;
}
 
// Recursive function to perform inorder traversal on a given binary tree
void inorderTraversal(struct Node* root)
{
    if (root == NULL) {
        return;
    }
 
    inorderTraversal(root->left);
    printf("%d ", root->key);
    inorderTraversal(root->right);
}
 
// Recursive function to perform postorder traversal on a given binary tree
void postorderTraversal(struct Node* root)
{
    if (root == NULL) {
        return;
    }
 
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->key);
}
 
// Recursive function to construct a binary tree from a given
// inorder and postorder traversals
struct Node* construct(int inorder[], int start, int end,
                    int postorder[], int *pIndex)
{
    // base case
    if (start > end) {
        return NULL;
    }
 
    // Consider the next item from the end of a given postorder sequence.
    // This value would be the root node of the subtree formed by the sequence
    // inorder[start, end].
    struct Node* node = newNode(postorder[(*pIndex)--]);
 
    // search the current node index in inorder sequence to determine
    // the boundary of the left and right subtree of the current node
    int i;
    for (i = start; i <= end; i++)
    {
        if (inorder[i] == node->key) {
            break;
        }
    }
 
    // recursively construct the right subtree
    node->right= construct(inorder, i + 1, end, postorder, pIndex);
 
    // recursively construct the left subtree
    node->left = construct(inorder, start, i - 1, postorder, pIndex);
 
    // return the current node
    return node;
}
 
// Construct a binary tree from inorder and postorder traversals.
// This function assumes that the input is valid, i.e., given
// inorder and postorder sequences forming a binary tree.
struct Node* constructTree(int inorder[], int postorder[], int n)
{
    // `pIndex` stores the index of the next unprocessed node from the end
    // of the postorder sequence
    int *pIndex = &n;
    return construct(inorder, 0, n, postorder, pIndex);
}
 
int main(void)
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
 
    int inorder[]    = { 4, 2, 1, 7, 5, 8, 3, 6 };
    int postorder[] = { 4, 2, 7, 8, 5, 6, 3, 1 };
    int n = sizeof(inorder)/sizeof(inorder[0]);
 
    struct Node* root = constructTree(inorder, postorder, n - 1);
 
    // traverse the constructed tree
    printf("Inorder traversal is "); inorderTraversal(root);
    printf("\nPostorder traversal is "); postorderTraversal(root);
 
    return 0;
}
