import java.util.Arrays;
import java.util.stream.Collectors;
 
class Main
{
    public static int log(int x, int base) {
        return (int) (Math.log(x) / Math.log(base));
    }
 
    // Function to find the missing number and duplicate element
    // using XOR operator in an array of size `n` and range of
    // elements from 1 to `n`
    public static void findMissingAndDuplicate(int[] arr)
    {
        int n = arr.length;
 
        // take XOR of all array elements from index 0 to `n-1`
        // all numbers in range 1 to `n`
        int result = n;
        for (int i = 0; i < n; i++) {
            result = result ^ arr[i] ^ i;
        }
 
        // `x` and `y` stores the duplicate element and missing number
        int x = 0, y = 0;
 
        // `result` stores `x ^ y`
 
        // find the position of the rightmost set bit in result
        int k = log(result & -result, 2);
 
        // split the array into two subarrays
        for (int value: arr)
        {
            // array elements that have k'th bit 1
            if ((value & (1 << k)) != 0) {
                x = x ^ value;
            }
 
            // array elements that have k'th bit 0
            else {
                y = y ^ value;
            }
        }
 
        // split range [1, n] into two subranges
        for (int i = 1; i <= n; i++)
        {
            // number `i` has k'th bit 1
            if ((i & (1 << k)) != 0) {
                x = x ^ i;
            }
 
            // number `i` has k'th bit 0
            else {
                y = y ^ i;
            }
        }
 
        // linear search for the missing element
        System.out.print("The duplicate and missing elements are ");
 
        if (Arrays.stream(arr).boxed().collect(Collectors.toList()).contains(x)) {
            System.out.println(x + " and " + y);
        }
        else {
            System.out.println(y + " and " + x);
        }
    }
 
    public static void main(String[] args)
    {
        int[] arr = { 4, 3, 6, 5, 2, 4 };
 
        findMissingAndDuplicate(arr);
    }
}
