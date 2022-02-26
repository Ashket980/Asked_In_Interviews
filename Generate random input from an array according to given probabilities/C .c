#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
 
// Function to generate random nums from an array according to
// given probabilities
int random(int *nums, int *probability, int n)
{
    // construct a sum array from the given probabilities
    int prob_sum[n];
    memset(prob_sum, 0, sizeof prob_sum);
 
    // `prob_sum[i]` holds sum of all `probability[j]` for `0 <= j <=i`
    prob_sum[0] = probability[0];
    for (int i = 1; i < n; i++) {
        prob_sum[i] = prob_sum[i-1] + probability[i];
    }
 
    // generate a random integer from 1 to 100 and check where it lies in `prob_sum[]`
    int r = (rand() % 100) + 1;
 
    // based on the comparison result, return the corresponding
    // element from the input array
 
    if (r <= prob_sum[0]) {         // handle 0th index separately
        return nums[0];
    }
 
    for (int i = 1; i < n; i++)
    {
        if (r > prob_sum[i - 1] && r <= prob_sum[i]) {
            return nums[i];
        }
    }
}
 
int main(void)
{
    // Input: integer array and their probabilities
    // Goal: generate `nums[i]` with probability equal to `probability[i]`
 
    int nums[] = {1, 2, 3, 4, 5};
    int probability[] = {30, 10, 20, 15, 25};
 
    int n = sizeof (nums) / sizeof (nums[0]);
 
    // initialize srand with a distinctive value
    srand(time(NULL));
 
    // maintain a count array to validate the results (assuming max nums is 1000)
    int count[1000];
    memset(count, 0, sizeof count);
 
    // make 1000000 calls to the `random()` function and store the results
    for (int i = 1; i <= 1000000; i++)
    {
        int val = random(nums, probability, n);
        count[val]++;
    }
 
    // print the results
    for (int i = 0; i < n; i++) {
        printf("%d ~ %0.2f%\n", nums[i], count[nums[i]]/10000.0);
    }
 
    return 0;
}
