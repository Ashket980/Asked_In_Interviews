// A class to store a binary tree node
class Node
{
    int data;
    Node left, right;
 
    Node(int data)
    {
        this.data = data;
        this.left = this.right = null;
    }
}
 
class Main
{
    // Wrapper over `Node` class
    static class NodeWrapper
    {
        public Node node;
 
        NodeWrapper() {
            this.node = null;
        }
 
        NodeWrapper(int data) {
            this.node = new Node(data);
        }
    }
 
    // Function to perform inorder traversal on the tree
    public static void inorder(Node root)
    {
        if (root == null) {
            return;
        }
 
        inorder(root.left);
        System.out.print(root.data + " ");
        inorder(root.right);
    }
 
    // Function to exchange data of given tree nodes
    public static void swapData(Node first, Node second)
    {
        int data = first.data;
        first.data = second.data;
        second.data = data;
    }
 
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
 
    // Recursive function to fix a binary tree that is only one swap
    // away from becoming a BST. Here, `prev` is the previously processed node
    // in inorder traversal, and `x` & `y` stores node to be swapped (if any).
    public static void correctBST(Node root, NodeWrapper x, NodeWrapper y,
            NodeWrapper prev)
    {
        // base case
        if (root == null) {
            return;
        }
 
        // recur for the left subtree
        correctBST(root.left, x, y, prev);
 
        // if the current node is less than the previous node
        if (root.data < prev.node.data)
        {
            // if this is the first occurrence, update `x` and `y` to the previous
            // and current node, respectively
            if (x.node == null) {
                x.node = prev.node;
            }
 
            // if this is a second occurrence, update `y` to the current node
            y.node = root;
        }
 
        // update the previous node and recur for the right subtree
        prev.node = root;
        correctBST(root.right, x, y, prev);
    }
 
    // Fix given binary tree that is only one swap away from becoming a BST
    public static void correctBST(Node root)
    {
        // wrap `x`, `y`, and `prev` nodes, so their reference can be changed
        // inside the `correctBST()` method
 
        // `x` and `y` stores node to be swapped
        NodeWrapper x = new NodeWrapper();
        NodeWrapper y = new NodeWrapper();
 
        // stores previously processed node in the inorder traversal
        // initialize it by -INFINITY
        NodeWrapper prev = new NodeWrapper(Integer.MIN_VALUE);
 
        // fix the binary tree
        correctBST(root, x, y, prev);
 
        // swap the nodes
        if (x.node != null && y.node != null ) {
            swapData(x.node, y.node);
        }
    }
 
    public static void main(String[] args)
    {
        int[] keys = {15, 10, 20, 8, 12, 16, 25};
 
        /* Construct the following BST
                  15
                /    \
               /      \
              10       20
             /  \     /  \
            /    \   /    \
           8     12 16    25
        */
 
        Node root = null;
        for (int key: keys) {
            root = insert(root, key);
        }
 
        // swap any two nodes' values
        swapData(root.left, root.right.right);
 
        // fix the BST
        correctBST(root);
 
        // print the BST after fixing it
        inorder(root);
    }
}
