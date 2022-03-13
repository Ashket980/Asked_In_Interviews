import java.util.HashMap;
import java.util.Map;
 
// A class to store a binary tree node
class Node
{
    int data;
    Node left, right;
 
    Node(int data) {
        this.data = data;
    }
}
 
class Main
{
    // Recursive function to perform inorder traversal on a given binary tree
    public static void inorderTraversal(Node root)
    {
        if (root == null) {
            return;
        }
 
        inorderTraversal(root.left);
        System.out.print(root.data + " ");
        inorderTraversal(root.right);
    }
 
    // Recursive function to construct a binary tree from a given inorder and
    // level order traversals
    public static Node buildTree(int[] inorder, int start, int end,
                                Map<Integer, Integer> map)
    {
        // base case
        if (start > end) {
            return null;
        }
 
        // find the root node index in sequence `inorder[]` to determine the
        // left and right subtree boundary
        int index = start;
        for (int j = start + 1; j <= end; j++)
        {
            // Find node with minimum index in level order traversal.
            // That would be the root node of the sequence inorder[start, end]
            if (map.get(inorder[j]) < map.get(inorder[index])) {
                index = j;
            }
        }
 
        // construct the root node
        Node root = new Node(inorder[index]);
 
        // recursively construct the left subtree
        root.left = buildTree(inorder, start, index - 1, map);
 
        // recursively construct the right subtree
        root.right = buildTree(inorder, index + 1, end, map);
 
        // return the root node
        return root;
    }
 
    // Construct a binary tree from inorder and level order traversals
    public static Node buildTree(int[] in, int[] level)
    {
        // create a map to efficiently find the index of an element in a
        // level order sequence
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < in.length; i++) {
            map.put(level[i], i);
        }
 
        // construct the tree and return it
        return buildTree(in, 0, in.length - 1, map);
    }
 
    public static void main(String[] args)
    {
        int[] inorder = { 4, 2, 5, 1, 6, 3, 7 };
        int[] level    = { 1, 2, 3, 4, 5, 6, 7 };
 
        Node root = buildTree(inorder, level);
 
        System.out.print("Inorder traversal of the constructed tree is ");
        inorderTraversal(root);
    }
}
