// Data structure to store a binary tree node
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
    // Recursive function to find the minimum depth of a path starting
    // from the given node in a binary tree
    public static int findMinDepth(Node root)
    {
        // base case
        if (root == null) {
            return 0;
        }
 
        // find the minimum depth of the left subtree
        int l = findMinDepth(root.left);
 
        // find the minimum depth of the right subtree
        int r = findMinDepth(root.right);
 
        // if the left child does not exist, consider the depth
        // returned by the right subtree
        if (root.left == null) {
            return 1 + r;
        }
 
        // if the right child does not exist, consider the depth
        // returned by the left subtree
        if (root.right == null) {
            return 1 + l;
        }
 
        // otherwise, choose the minimum depth returned by the
        // left and right subtree
        return Integer.min(l, r) + 1;
    }
 
    public static void main(String[] args)
    {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);
        root.left.left.right = new Node(8);
        root.left.right.right = new Node(9);
        root.right.right.left = new Node(10);
        root.right.right.left = new Node(11);
        root.left.left.right.right = new Node(12);
 
        System.out.println("The minimum depth is " + findMinDepth(root));
    }
}
