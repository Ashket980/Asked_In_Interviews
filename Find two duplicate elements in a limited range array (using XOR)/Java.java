class Main
{
    public static int log(int x, int base) {
        return (int) (Math.log(x) / Math.log(base));
    }
 
    // Function to find two repeating elements in an array of size `n+2`
    // having a range of elements from 1 to `n` using XOR operator
    public static void findDuplicates(int[] arr, int n)
    {
        // take XOR of all array elements index 0 to `n-1` and
        // elements from 1 to `n`
        int result = arr[0] ^ arr[n + 1];
        for (int i = 1; i <= n; i++) {
            result = result ^ arr[i] ^ i;
        }
 
        // `x` and `y` are two odd appearing elements
        int x = 0, y = 0;
 
        // `result` stores `x ^ y`
 
        // find the position of the rightmost set bit in `result`
        int k = log(result & -result, 2);
 
        // split the array into two subarrays
        for (int i = 0; i < n + 2; i++)
        {
            // array elements that have k'th bit 1
            if ((arr[i] & (1 << k)) != 0) {
                x = x ^ arr[i];
            }
            // array elements that have k'th bit 0
            else {
                y = y ^ arr[i];
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
 
        System.out.println("The duplicate elements are " + x + " and " + y);
    }
 
    public static void main(String[] args)
    {
        int[] arr = { 4, 3, 6, 5, 2, 4, 1, 1 };
        int n = 6;        // array size is `n+2`
 
        findDuplicates(arr, n);
    }
}
