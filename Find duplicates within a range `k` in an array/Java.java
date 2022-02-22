import java.util.HashMap;
import java.util.Map;
 
class Main
{
    public static boolean hasDuplicate(int[] nums, int k)
    {
        // stores (element, index) pairs as (key, value) pairs
        Map<Integer, Integer> map = new HashMap<>();
 
        // traverse the array
        for (int i = 0; i < nums.length; i++)
        {
            // if the current element already exists in the map
            if (map.containsKey(nums[i]))
            {
                // return true if the current element repeats within range of `k`
                if (i - map.get(nums[i]) <= k) {
                    return true;
                }
            }
 
            // store elements along with their indices
            map.put(nums[i], i);
        }
 
        // we reach here when no element repeats within range `k`
        return false;
    }
 
    public static void main(String[] args)
    {
        int[] nums = { 5, 6, 8, 2, 4, 6, 9 };
        int k = 4;
 
        if (hasDuplicate(nums, k)) {
            System.out.println("Duplicates found");
        }
        else {
            System.out.println("No duplicates were found");
        }
    }
}
