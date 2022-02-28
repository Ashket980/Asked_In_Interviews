#include <stdio.h>
#include <limits.h>
 
// Replace each element of the specified array with the
// least greater element on its right
void replace(int nums[], int n)
{
    // traverse the array from the beginning
    for (int i = 0; i < n; i++)
    {
        int successor = -1;
        int diff = INT_MAX;
 
        // check every element on the right for a successor
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] > nums[i] && (nums[j] - nums[i] < diff))
            {
                successor = nums[j];
                diff = nums[j] - nums[i];
            }
        }
        nums[i] = successor;
    }
 
    // print the resultant array
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
}
 
int main(void)
{
    int nums[] = { 10, 100, 93, 32, 35, 65, 80, 90, 94, 6};
    int n = sizeof(nums)/ sizeof(nums[0]);
 
    replace(nums, n);
 
    return 0;
}
