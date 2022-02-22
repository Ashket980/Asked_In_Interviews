import java.util.Stack;
 
class Main
{
    // Find the previous smaller element for every array element
    public static void findPrevSmaller(int[] arr)
    {
        // base case
        if (arr == null || arr.length == 0) {
            return;
        }
 
        // create an empty stack
        Stack<Integer> s = new Stack<>();
 
        // do for each element
        for (int i = 0; i < arr.length; i++)
        {
            // loop till stack is empty
            while (!s.empty())
            {
                // If the stack's top element is less than the current element,
                // it is the previous smaller element
                if (s.peek() < arr[i])
                {
                    System.out.print(s.peek() + " ");
                    break;
                }
                // remove the stack's top element is less if it is greater or equal
                // to the current element
                else {
                    s.pop();
                }
            }
 
            // If the stack becomes empty, all elements to the left
            // of the current element are greater
            if (s.empty()) {
                System.out.print(-1 + " ");
            }
 
            // push current element into the stack
            s.push(arr[i]);
        }
    }
 
    public static void main(String[] args)
    {
        int[] arr = { 2, 5, 3, 7, 8, 1, 9 };
        findPrevSmaller(arr);
    }
}
