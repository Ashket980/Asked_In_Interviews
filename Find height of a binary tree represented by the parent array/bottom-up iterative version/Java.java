class Main
{
    // Function to calculate the height of a binary tree represented by
    // parent array
    public static int findHeight(int[] parent)
    {
        // create an auxiliary array for storing the depth of each tree node
        int[] depth = new int[parent.length];
 
        // keep track of the height of a tree
        int height = -1;
 
        // iteratively calculate the depth of each tree node `i`
        for (int i = 0; i < parent.length; i++)
        {
            // initialize the depth of i'th node with 0 (the depth of a single node)
            int depth_i = 0;
 
            // trace the path from the i'th node back to the root
            for (int k = i; parent[k] != -1; k = parent[k])
            {
                // if the depth of the k'th node is already calculated
                if (depth[k] != 0)
                {
                    depth_i += depth[k];
                    break;
                }
                depth_i++;
            }
 
            // save subproblem solution
            depth[i] = depth_i;
 
            // keep track of the maximum depth
            height = Integer.max(height, depth[i]);
        }
 
        return height;
    }
 
    public static void main(String[] args)
    {
        int[] parent = {-1, 0, 0, 1, 2, 2, 4, 4};
        System.out.println("The height of the binary tree is " + findHeight(parent));
    }
}
