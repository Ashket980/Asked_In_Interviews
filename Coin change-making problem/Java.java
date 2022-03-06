class Main
{
    // Function to find the minimum number of coins required
    // to get a total of `target` from set `S`
    public static int findMinCoins(int[] S, int target)
    {
        // `T[i]` stores the minimum number of coins needed to get a total of `i`
        int[] T = new int[target + 1];
 
        for (int i = 1; i <= target; i++)
        {
            // initialize the minimum number of coins needed to infinity
            T[i] = Integer.MAX_VALUE;
            int result = Integer.MAX_VALUE;
 
            // do for each coin
            for (int c: S)
            {
                // check if the index doesn't become negative by including
                // current coin `c`
                if (i - c >= 0) {
                    result = T[i - c];
                }
 
                // if total can be reached by including current coin `c`,
                // update the minimum number of coins needed `T[i]`
                if (result != Integer.MAX_VALUE) {
                    T[i] = Integer.min(T[i], result + 1);
                }
            }
        }
 
        // `T[target]` stores the minimum number of coins needed to
        // get a total of `target`
        return T[target];
    }
 
    public static void main(String[] args)
    {
        // coins of given denominations
        int[] S = { 1, 2, 3, 4 };
 
        // total change required
        int target = 15;
 
        int coins = findMinCoins(S, target);
        if (coins != Integer.MAX_VALUE)
        {
            System.out.print("The minimum number of coins required to get the " +
                "desired change is " + coins);
        }
    }
}
