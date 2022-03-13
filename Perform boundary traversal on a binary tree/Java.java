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
 
    // Utility function to check if a given node is a leaf node
    boolean isLeaf() {
        return this.left == null && this.right == null;
    }
}
 
class Main
{
    // Recursive function to print the left boundary of the given binary tree
    // in a top-down fashion, except for the leaf nodes
    public static void printLeftBoundary(Node root)
    {
        // base case: root is empty
        if (root == null) {
            return;
        }
 
        Node node = root;
 
        // do for all non-leaf nodes
        while (!node.isLeaf())
        {
            // print the current node
            System.out.print(node.data + " ");
 
            // next process, the left child of `root` if it exists;
            // otherwise, move to the right child
            node = (node.left != null) ? node.left: node.right;
        }
    }
 
    // Recursive function to print the right boundary of the given binary tree
    // in a bottom-up fashion, except for the leaf nodes
    public static void printRightBoundary(Node root)
    {
        // base case: root is empty, or root is a leaf node
        if (root == null || root.isLeaf()) {
            return;
        }
 
        // recur for the right child of `root` if it exists;
        // otherwise, recur for the left child
        printRightBoundary(root.right != null ? root.right: root.left);
 
        // To ensure bottom-up order, print the value of the nodes
        // after recursion unfolds
        System.out.print(root.data + " ");
    }
 
    // Recursive function to print the leaf nodes of the given
    // binary tree in an inorder fashion
    public static void printLeafNodes(Node root)
    {
        // base case
        if (root == null) {
            return;
        }
 
        // recur for the left subtree
        printLeafNodes(root.left);
 
        // print only leaf nodes
        if (root.isLeaf()) {
            System.out.print(root.data + " ");
        }
 
        // recur for the right subtree
        printLeafNodes(root.right);
    }
 
    // Function to perform the boundary traversal on a given tree
    public static void performBoundaryTraversal(Node root)
    {
        // base case
        if (root == null) {
            return;
        }
 
        // print the root node
        System.out.print(root.data + " ");
 
        // print the left boundary (except leaf nodes)
        printLeftBoundary(root.left);
 
        // print all leaf nodes
        if (!root.isLeaf()) {
            printLeafNodes(root);
        }
 
        // print the right boundary (except leaf nodes)
        printRightBoundary(root.right);
    }
 
    public static void main(String[] args)
    {
        // construct a binary tree as per the above diagram
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);
        root.left.left.left = new Node(8);
        root.left.left.right = new Node(9);
        root.left.right.right = new Node(10);
        root.right.right.left = new Node(11);
        root.left.left.right.left = new Node(12);
        root.left.left.right.right = new Node(13);
        root.right.right.left.left = new Node(14);
 
        performBoundaryTraversal(root);
    }
}
