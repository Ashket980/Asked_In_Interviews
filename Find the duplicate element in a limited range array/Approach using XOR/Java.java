class Main
{
    // Function to find a duplicate element in a limited range array
    public static int findDuplicate(int[] nums)
    {
        int xor = 0;
 
        // take xor of all array elements
        for (int value: nums) {
            xor ^= value;
        }
 
        // take xor of numbers from 1 to `n-1`
        for (int i = 1; i <= nums.length - 1; i++) {
            xor ^= i;
        }
 
        // same elements will cancel each other as a ^ a = 0,
        // 0 ^ 0 = 0 and a ^ 0 = a
 
        // `xor` will contain the missing number
        return xor;
    }
 
    public static void main(String[] args)
    {
        // input array contains `n` numbers between 1 and `n-1`
        // with one duplicate, where `n` is the array's length
        int[] nums = { 1, 2, 3, 4, 4 };
 
        System.out.println("The duplicate element is " + findDuplicate(nums));
    }
}
