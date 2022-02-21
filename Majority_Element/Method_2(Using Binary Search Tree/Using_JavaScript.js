<script>
// javascript program to demonstrate insert
// operation in binary search tree.
class Node {
    constructor(){
    this.key = 0;
    this.c = 0;
    this.left = null,
    this.right = null;
    }
 
}
    var ma = 0;
 
    // A utility function to create a
    // new BST node
    function newNode(item)
    {
        var temp = new Node();
        temp.key = item;
        temp.c = 1;
        temp.left = temp.right = null;
        return temp;
    }
 
    // A utility function to insert a new node
    // with given key in BST
    function insert(node , key) {
 
        // If the tree is empty,
        // return a new node
        if (node == null) {
            if (ma == 0)
                ma = 1;
 
            return newNode(key);
        }
 
        // Otherwise, recur down the tree
        if (key < node.key)
            node.left = insert(node.left, key);
        else if (key > node.key)
            node.right = insert(node.right, key);
        else
            node.c++;
 
        // Find the max count
        ma = Math.max(ma, node.c);
 
        // Return the (unchanged) node pointer
        return node;
    }
 
    // A utility function to do inorder
    // traversal of BST
    function inorder(root , s) {
        if (root != null) {
            inorder(root.left, s);
 
            if (root.c > (s / 2))
                document.write(root.key + "\n");
 
            inorder(root.right, s);
        }
    }
 
    // Driver Code
     
        var a = [ 1, 3, 3, 3, 2 ];
        var size = a.length;
        var root = null;
 
        for (i = 0; i < size; i++) {
            root = insert(root, a[i]);
        }
 
        // Function call
        if (ma > (size / 2))
            inorder(root, size);
        else
            document.write("No majority element\n");
 
// This code is contributed by gauravrajput1
</script>
