import java.util.Arrays;
import java.util.Stack;
 
class Main
{
    public static int[] findNextGreaterElements(int[] input)
    {
        // base case
        if (input == null) {
            return input;
        }
 
        int n = input.length;
        int[] result = new int[n];
        Arrays.fill(result, -1);
 
        // create an empty stack
        Stack<Integer> s = new Stack<>();
 
        // process each element from right to left
        for (int i = n - 1; i >= 0; i--)
        {
            // loop till we have a greater element on top or stack becomes empty.
            while (!s.empty())
            {
                // pop elements that aren't greater than the current element
                if (s.peek() <= input[i]) {
                    s.pop();
                }
                // the next greater element is now on the top of the stack
                else {
                    result[i] = s.peek();
                    break;
                }
            }
 
            // push current element into the stack
            s.push(input[i]);
        }
 
        return result;
    }
 
    public static void main(String[] args)
    {
        int[] input = { 2, 7, 3, 5, 4, 6, 8 };
 
        int[] result = findNextGreaterElements(input);
        System.out.println(Arrays.toString(result));
    }
}
