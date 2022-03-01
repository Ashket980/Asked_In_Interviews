#include <stdio.h>
 
// Function to find the maximum profit earned by buying and
// selling shares any number of times
int findMaxProfit(int price[], int n)
{
    // keep track of the maximum profit gained
    int profit = 0;
 
    // initialize the local minimum to the first element's index
    int j = 0;
 
    // start from the second element
    for (int i = 1; i < n; i++)
    {
        // update the local minimum if a decreasing sequence is found
        if (price[i - 1] > price[i]) {
            j = i;
        }
 
        // sell shares if the current element is the peak,
        // i.e., (`previous <= current > next`)
        if (price[i - 1] <= price[i] &&
            (i + 1 == n || price[i] > price[i + 1]))
        {
            profit += (price[i] - price[j]);
            printf("Buy on day %d and sell on day %d\n", j + 1, i + 1);
        }
    }
 
    return profit;
}
 
int main()
{
    int price[] = { 1, 5, 2, 3, 7, 6, 4, 5 };
    int n = sizeof(price) / sizeof(price[0]);
 
    printf("\nTotal profit earned is %d", findMaxProfit(price, n));
 
    return 0;
}
