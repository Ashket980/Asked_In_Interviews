#include <stdio.h>
 
// Find odd occurring elements in a given array
void findRepeating(int nums[], int n)
{
    int xor = 0;
    for (int i = 0; i < n; i++) {
        xor ^= (1 << nums[i]);
    }
 
    printf("The odd occurring elements are ");
    for (int i = 0; i < n; i++)
    {
        if (xor & (1 << nums[i]))
        {
            printf("%d ", nums[i]);
            xor ^= (1 << nums[i]);     // to avoid printing duplicates
        }
    }
}
 
int main(void)
{
    int nums[] = { 5, 8, 2, 5, 8, 2, 8, 5, 1, 8, 2 };
    int n = sizeof(nums) / sizeof(nums[0]);
 
    findRepeating(nums, n);
 
    return 0;
}
