import java.util.Arrays;
import java.util.Comparator;
 
class Main
{
    // Find two numbers with a maximum sum formed by digits of an array
    public static void findMaximum(Integer[] input)
    {
        // base case
        if (input.length <= 1) {
            return;
        }
 
        // sort the array in descending order
        Arrays.sort(input, Comparator.reverseOrder());
 
        // fill `x` with digits at the odd indices of the sorted array
        int x = 0;
        for (int i = 0; i < input.length; i = i + 2) {
            x = x * 10 + input[i];
        }
 
        // fill `y` with digits at the even indices of the sorted array
        int y = 0;
        for (int i = 1; i < input.length; i = i + 2) {
            y = y * 10 + input[i];
        }
 
        // print `x` and `y`
        System.out.println("The two numbers with maximum sum are "
                + x + " and " + y);
    }
 
    public static void main(String[] args)
    {
        Integer[] input = { 4, 6, 2, 7, 9, 8 };
 
        findMaximum(input);
    }
}
