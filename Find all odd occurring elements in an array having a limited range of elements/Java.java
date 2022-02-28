class Main
{
    // Find odd occurring elements in a given array
    public static void findRepeating(int[] nums)
    {
        int xor = 0;
        for (int i: nums) {
            xor ^= (1 << i);
        }
 
        System.out.print("The odd occurring elements are ");
        for (int i: nums)
        {
            if ((xor & (1 << i)) != 0)
            {
                System.out.print(i + " ");
                xor ^= (1 << i);    // to avoid printing duplicates
            }
        }
    }
 
    public static void main(String[] args)
    {
        int[] nums = { 5, 8, 2, 5, 8, 2, 8, 5, 1, 8, 2 };
        findRepeating(nums);
    }
}
