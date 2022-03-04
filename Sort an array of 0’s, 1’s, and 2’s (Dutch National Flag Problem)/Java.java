import java.util.Arrays;
 
class Main
{
    // Linear time partition routine to sort an array containing 0, 1, and 2.
    // It is similar to 3–way partitioning for the Dutch national flag problem.
    public static void threeWayPartition(int[] A)
    {
        int start = 0, mid = 0;
        int pivot = 1;
        int end = A.length - 1;
 
        while (mid <= end)
        {
            if (A[mid] < pivot)         // current element is 0
            {
                swap(A, start, mid);
                ++start;
                ++mid;
            }
            else if (A[mid] > pivot)    // current element is 2
            {
                swap(A, mid, end);
                --end;
            }
            else {                      // current element is 1
                ++mid;
            }
        }
    }
 
    // Utility function to swap elements `A[i]` and `A[j]` in the array
    private static void swap(int[] A, int i, int j)
    {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
 
    public static void main (String[] args)
    {
        int[] A = { 0, 1, 2, 2, 1, 0, 0, 2, 0, 1, 1, 0 };
 
        threeWayPartition(A);
        System.out.println(Arrays.toString(A));
    }
}
