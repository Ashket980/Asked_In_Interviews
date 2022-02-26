#include <stdio.h>
#include <stdlib.h>
 
// Function to find the closest pair to `target` in given sorted arrays
// `first` and `second`
void findClosestPair(int first[], int second[], int m, int n, int target)
{
    // base case
    if (m == 0 || n == 0) {
        return;
    }
 
    // `x` and `y` points to the indexes of the closest pair found so far
    int x = 0, y = 0;
 
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // update the closest pair if the current pair `(i, j)` is more
            // closer to `target`
            if (abs(first[i] + second[j] - target) < abs(first[x] + second[y] - target))
            {
                x = i;
                y = j;
            }
        }
    }
 
    printf("The closest pair is [%d, %d]", first[x], second[y]);
}
 
int main(void)
{
    int first[] = { 1, 8, 10, 12 };
    int second[] = { 2, 4, 9, 15 };
    int target = 11;
 
    int m = sizeof(first) / sizeof(first[0]);
    int n = sizeof(second) / sizeof(second[0]);
 
    findClosestPair(first, second, m, n, target);
 
    return 0;
}
