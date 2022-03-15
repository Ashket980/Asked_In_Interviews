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
 
    // Recursive function to find an inorder successor for the given key in the BST
    public static Node findSuccessor(Node root, Node succ, int key)
    {
        // base case
        if (root == null) {
            return succ;
        }
 
        // if a node with the desired value is found, the successor is the minimum
        // value node in its right subtree (if any)
        if (root.data == key)
        {
            if (root.right != null) {
                return findMinimum(root.right);
            }
        }
 
        // if the given key is less than the root node, recur for the left subtree
        else if (key < root.data)
        {
            // update successor to the current node before recursing in the
            // left subtree
            succ = root;
            return findSuccessor(root.left, succ, key);
        }
 
        // if the given key is more than the root node, recur for the right subtree
        else {
            return findSuccessor(root.right, succ, key);
        }
 
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
            Node succ = findSuccessor(root, null, key);
 
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
