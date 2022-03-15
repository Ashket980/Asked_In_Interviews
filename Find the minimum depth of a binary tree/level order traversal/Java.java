import java.util.ArrayDeque;
import java.util.Queue;
 
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
 
// Queue node for storing a pointer to a tree node and its current depth
class QueueNode
{
    Node node;
    int depth;
 
    public QueueNode(Node node, int depth)
    {
        this.node = node;
        this.depth = depth;
    }
}
 
class Main
{
    // Returns true if the given tree node is a leaf, false otherwise
    public static boolean isLeaf(Node node) {
        return node.left == null && node.right == null;
    }
 
    // Iterative function to find the minimum depth of a path starting
    // from the given node in a binary tree
    public static int findMinDepth(Node root)
    {
        // base case
        if (root == null) {
            return 0;
        }
 
        // create an empty queue and push the root node with a depth of 1
        Queue<QueueNode> q = new ArrayDeque<>();
        q.add(new QueueNode(root, 1));
 
        // run till queue is empty
        while (!q.isEmpty())
        {
            // dequeue front node
            Node node = q.peek().node;
            int depth = q.peek().depth;
 
            q.poll();
 
            // if the popped node is a leaf node, return its depth
            if (isLeaf(node)) {
                return depth;
            }
 
            // enqueue left child of the popped node with +1 depth
            if (node.left != null) {
                q.add(new QueueNode(node.left, depth + 1));
            }
 
            // enqueue right child of the popped node with +1 depth
            if (node.right != null) {
                q.add(new QueueNode(node.right, depth + 1));
            }
        }
        return 0;
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
