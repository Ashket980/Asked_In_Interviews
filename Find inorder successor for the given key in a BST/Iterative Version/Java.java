// A class to store a BST node
class Node
{
    int data;
    Node left = null, right = null;
 
    Node(int data) {
        this.data = data;
    }
}
 
class Main
{
    // Recursive function to insert a key into a BST
    public static Node insert(Node root, int key)
    {
        // if the root is null, create a new node and return it
        if (root == null) {
            return new Node(key);
        }
 
        // if the given key is less than the root node, recur for the left subtree
        if (key < root.data) {
            root.left = insert(root.left, key);
        }
 
        // if the given key is more than the root node, recur for the right subtree
        else {
            root.right = insert(root.right, key);
        }
 
        return root;
    }
 
 
    // Helper function to find minimum value node in a given BST
    public static Node findMinimum(Node root)
    {
        while (root.left != null) {
            root = root.left;
        }
 
        return root;
    }
 
    // Iterative function to find an inorder successor for the given key in the BST
    public static Node findSuccessor(Node root, int key)
    {
        // base case
        if (root == null) {
            return null;
        }
 
        Node succ = null;
 
        while (true)
        {
            // if the given key is less than the root node, visit the left subtree
            if (key < root.data)
            {
                // update successor to the current node before visiting
                // left subtree
                succ = root;
                root = root.left;
            }
 
            // if the given key is more than the root node, visit the right subtree
            else if (key > root.data) {
                root = root.right;
            }
 
            // if a node with the desired value is found, the successor is the minimum
            // value node in its right subtree (if any)
            else {
                if (root.right != null) {
                    succ = findMinimum(root.right);
                }
                break;
            }
 
            // if the key doesn't exist in the binary tree, return next greater node
            if (root == null) {
                return succ;
            }
        }
 
        // return successor, if any
        return succ;
    }
 
    public static void main(String[] args)
    {
        int[] keys = { 15, 10, 20, 8, 12, 16, 25 };
 
        /* Construct the following tree
                   15
                 /    \
                /      \
               10       20
              / \      /  \
             /   \    /    \
            8    12  16    25
        */
 
        Node root = null;
        for (int key: keys) {
            root = insert(root, key);
        }
 
        // find inorder successor for each key
        for (int key: keys)
        {
            Node succ = findSuccessor(root, key);
 
            if (succ != null)
            {
                System.out.println("The successor of node " + key + " is "
                                    + succ.data);
            }
            else {
                System.out.println("No Successor exists for node " + key);
            }
        }
    }
}
