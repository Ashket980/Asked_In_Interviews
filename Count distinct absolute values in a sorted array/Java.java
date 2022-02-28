class Main
{
    // Returns the total number of distinct absolute values in a given input
    public static int findDistinctCount(int[] A)
    {
        // initialize the distinct count as input size
        int distinct_count = A.length;
 
        // points to the left and right boundary of the current window,
        // i.e., the current window is formed by `A[left, right]`
        int left = 0;
        int right = A.length - 1;
 
        // loop until the left index of the current window is
        // less than the right index
        while (left < right)
        {
            // remove any duplicate elements from the left and right
            // of the current window and decrease the distinct count
            // for each duplicate found
            while (left < right && A[left] == A[left+1])
            {
                distinct_count--;
                left++;
            }
            while (right > left && A[right] == A[right-1])
            {
                distinct_count--;
                right--;
            }
 
            // if only one element is left, break the loop
            if (left == right) {
                break;
            }
 
            int sum = A[left] + A[right];
 
            // decrease the distinct count if the zero-sum pair is encountered
            if (sum == 0)
            {
                distinct_count--;
                left++;
                right--;
            }
            // if the sum is negative, incrementing the left index might still lead
            // to a zero-sum pair
            else if (sum < 0) {
                left++;
            }
            // if the sum is positive, decrementing the right index might still lead
            // to a zero-sum pair
            else {
                right--;
            }
        }
 
        return distinct_count;
    }
 
    public static void main(String[] args)
    {
        int[] input = { -1, -1, 0, 1, 1, 1 };
 
        System.out.println("The total number of distinct absolute values is "
                                + findDistinctCount(input));
    }
}
