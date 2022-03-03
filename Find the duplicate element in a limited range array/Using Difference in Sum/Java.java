import java.util.stream.IntStream;
 
class Main
{
    public static int findDuplicate(int[] nums)
    {
        int actual_sum = IntStream.of(nums).sum();
        int expected_sum = nums.length * (nums.length - 1) / 2;
 
        return actual_sum - expected_sum;
    }
 
    public static void main(String[] args)
    {
        int[] nums = { 1, 2, 3, 4, 4 };
        System.out.println("The duplicate element is " + findDuplicate(nums));
    }
}
