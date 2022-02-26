import java.util.Arrays;
import java.util.Map;
import java.util.TreeMap;
 
class Main
{
    public static void countSort(int[] nums)
    {
        // create a `TreeMap` to store the frequency of array elements
        Map<Integer, Integer> freq = new TreeMap<>();
 
        // store distinct values in the input array as key and
        // their respective counts as values in the `TreeMap`
        for (int num: nums) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }
 
        // traverse the map (based on the sorted order of keys) and
        // overwrite the input array with sorted elements
        int i = 0;
        for (var entry: freq.entrySet())
        {
            int value = entry.getValue();
            while (value-- > 0) {
                nums[i++] = entry.getKey();
            }
        }
    }
 
    public static void main(String[] args)
    {
        int[] nums = { 4, 2, 1, 4, 1, 4, 2, 1, 10 };
 
        countSort(nums);
        System.out.println(Arrays.toString(nums));
    }
}
