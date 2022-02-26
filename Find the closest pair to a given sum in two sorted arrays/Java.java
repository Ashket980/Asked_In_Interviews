class Main
{
    // Function to find the closest pair to `target` in given sorted arrays
    // `first` and `second`
    private static void findClosestPair(int[] first, int[] second, int target)
    {
        // base case
        if (first.length == 0 || second.length == 0) {
            return;
        }
 
        // `x` and `y` points to the indexes of the closest pair found so far
        int x = 0, y = 0;
 
        for (int i = 0; i < first.length; i++)
        {
            for (int j = 0; j < second.length; j++)
            {
                // update the closest pair if the current pair `(i, j)`
                // is more closer to `target`
                if (Math.abs(first[i] + second[j] - target) <
                        Math.abs(first[x] + second[y] - target)) {
                    x = i;
                    y = j;
                }
            }
        }
 
        System.out.printf("The closest pair is [%d, %d]", first[x], second[y]);
    }
 
    public static void main(String[] args)
    {
        int[] first = { 1, 8, 10, 12 };
        int[] second = { 2, 4, 9, 15 };
        int target = 11;
 
        findClosestPair(first, second, target);
    }
}
