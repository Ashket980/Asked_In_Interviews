import java.util.ArrayList;
import java.util.List;
 
// A class to store a Doubly Linked List / BST node
class Node
{
    // value of node
    int data;
 
    // The `prev` and `next` pointer of the doubly linked list can act as
    // left and right child for the BST, respectively
    Node prev, next;
 
    // Constructor
    Node(int data)
    {
        this.data = data;
        this.prev = this.next = null;
    }
}
 
class Main
{
    // Function to insert a new node at the beginning of the doubly linked list.
    public static Node push(Node head, int data)
    {
        // allocate a new node and link it at the beginning
        Node node = new Node(data);
        node.next = head;
 
        // change `prev` of the existing head node to point to the new node
        if (head != null) {
            head.prev = node;
        }
 
        // update head pointer
        head = node;
        return head;
    }
 
    // Function to print nodes of a doubly linked list
    public static void printListNodes(Node node)
    {
        while (node != null)
        {
            System.out.print(node.data + " ");
            node = node.next;
        }
 
        System.out.println();
    }
 
    // Function to print preorder traversal of the BST
    public static void preorder(Node root)
    {
        if (root == null) {
            return;
        }
 
        System.out.print(root.data + " ");
        preorder(root.prev);
        preorder(root.next);
    }
 
    // Function to push nodes of a given BST in a list
    public static void pushDDLNodes(Node node, List<Node> nodes)
    {
        while (node != null)
        {
            nodes.add(node);
            node = node.next;
        }
    }
 
    // Recursive function to construct a height-balanced BST from
    // given nodes in sorted order
    public static Node buildBalancedBST(List<Node> nodes, int start, int end)
    {
        // base case
        if (start > end) {
            return null;
        }
 
        // find the middle index
        int mid = (start + end) / 2;
 
        // The root node will be a node present at the mid-index
        Node root = nodes.get(mid);
 
        // recursively construct left and right subtree
        root.prev = buildBalancedBST(nodes, start, mid - 1);
        root.next = buildBalancedBST(nodes, mid + 1, end);
 
        // return root node
        return root;
    }
 
    // Function to construct a height-balanced BST from a sorted doubly linked list.
    public static Node convertSortedDLLToBalancedBST(Node head)
    {
        // Push nodes of a given BST into a list in the original order
        List<Node> nodes = new ArrayList<>();
        pushDDLNodes(head, nodes);
 
        // Construct a height-balanced BST from sorted BST nodes
        return buildBalancedBST(nodes, 0, nodes.size() - 1);
    }
 
    public static void main(String[] args)
    {
        // points to the head of a doubly linked list
        Node head = null;
 
        // construct a doubly linked list from sorted keys
        int[] keys = { 25, 20, 18, 15, 12, 10, 8 };
        for (int key: keys) {
            head = push(head, key);
        }
 
        System.out.print("Doubly Linked List: ");
        printListNodes(head);
 
        // construct a height-balanced BST from a sorted doubly linked list
        Node root = convertSortedDLLToBalancedBST(head);
 
        System.out.print("Preorder traversal of the constructed BST: ");
        preorder(root);
    }
}
