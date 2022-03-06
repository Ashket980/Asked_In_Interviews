import java.util.ArrayList;
import java.util.List;
 
class Main
{
    // Function to find the longest bitonic subsequence in an array
    public static void LBS(int[] nums)
    {
        int n = nums.length;
 
        // base case
        if (n == 0) {
            return;
        }
 
        // `I[i]` stores the longest increasing subsequence, ending at `nums[i]`
        List<List<Integer>> I = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            I.add(new ArrayList<>());
        }
 
        I.get(0).add(nums[0]);
 
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (I.get(i).size() < I.get(j).size() && nums[i] > nums[j]) {
                    I.set(i, new ArrayList<>(I.get(j)));
                }
            }
            I.get(i).add(nums[i]);
        }
 
        // `D[i]` stores the longest decreasing subsequence, starting from `nums[i]`
        List<List<Integer>> D = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            D.add(new ArrayList<>());
        }
        D.get(n - 1).add(0, nums[n - 1]);
 
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = n - 1; j > i; j--)
            {
                if (D.get(i).size() < D.get(j).size() && nums[i] > nums[j]) {
                    D.set(i, new ArrayList<>(D.get(j)));
                }
            }
            D.get(i).add(0, nums[i]);
        }
 
        // find the peak element index
        int peak = 0;
        for (int i = 1; i < n; i++)
        {
            if ((I.get(i).size() + D.get(i).size()) >
                    (I.get(peak).size() + D.get(peak).size())) {
                peak = i;
            }
        }
 
        System.out.print("The longest bitonic subsequence is ");
 
        // print longest increasing subsequence ending at peak element
        System.out.print(I.get(peak));
 
        // pop the front element of LDS as it points to the same element as the
        // rear of LIS
        D.get(peak).remove(0);
 
        // print longest decreasing subsequence starting from the peak element
        System.out.println(D.get(peak));
    }
 
    public static void main(String[] args)
    {
        int[] nums = { 4, 2, 5, 9, 7, 6, 10, 3, 1 };
        LBS(nums);
    }
}
