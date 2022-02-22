class Main
{
    // Find the previous smaller element for every array element
    public static void findPrevSmaller(int[] arr)
    {
        // base case
        if (arr == null || arr.length == 0) {
            return;
        }
 
        // do for each element
        for (int i = 0; i < arr.length; i++)
        {
            // keep track of the previous smaller element for element `arr[i]`
            int prev = -1;
 
            // process elements on the left of the element `arr[i]`
            for (int j = i - 1; j >= 0; j--)
            {
                // break the inner loop at the first smaller element on the
                // left of the element `arr[i]`
                if (arr[j] < arr[i])
                {
                    prev = arr[j];
                    break;
                }
            }
 
            System.out.print(prev + " ");
        }
    }
 
    public static void main(String[] args)
    {
        int[] arr = { 2, 5, 3, 7, 8, 1, 9 };
        findPrevSmaller(arr);
    }
}
