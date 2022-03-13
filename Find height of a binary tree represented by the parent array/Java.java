class Main
{
    // Recursive function to calculate the depth of the i'th node in `parent[]`
    public static int findDepth(int[] parent, int i)
    {
        // A root node will have a depth of 0
        if (parent[i] == -1) {
            return 0;
        }
 
        // depth of the i'th node = 1 + depth of its parent
        return 1 + findDepth(parent, parent[i]);
    }
 
    // Function to calculate the height of a binary tree represented by
    // parent array
    public static int findHeight(int[] parent)
    {
        // keep track of the height of a tree
        int height = -1;
 
        // calculate the depth of each tree node `i` and keep track of
        // the maximum depth
        for (int i = 0; i < parent.length; i++) {
            height = Integer.max(height, findDepth(parent, i));
        }
 
        return height;
    }
 
    public static void main(String[] args)
    {
        int[] parent = {-1, 0, 0, 1, 2, 2, 4, 4};
        System.out.println("The height of the binary tree is " + findHeight(parent));
    }
}
