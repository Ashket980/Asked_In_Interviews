class Main
{
    // Function to find the minimum number of merge operations to make a
    // given array palindrome
    private static int findMin(int[] arr)
    {
        // stores the minimum number of merge operations needed
        int count = 0;
 
        // `i` and `j` initially points to endpoints of the array
        int i = 0, j = arr.length - 1;
 
        // loop till the search space is exhausted
        while (i < j)
        {
            if (arr[i] < arr[j])
            {
                // merge item at i'th index with the item at (i+1)'th index
                arr[i + 1] += arr[i];
                i++;
                count++;
            }
            else if (arr[i] > arr[j])
            {
                // merge item at (j-1)'th index with the item at j'th index
                arr[j - 1] += arr[j];
                j--;
                count++;
            }
            // otherwise, ignore both the elements
            else {
                i++;
                j--;
            }
        }
 
        return count;
    }
 
    public static void main(String[] args)
    {
        int[] arr = { 6, 1, 4, 3, 1, 7 };
 
        int min = findMin(arr);
        System.out.println("The minimum number of operations required is " + min);
    }
}
