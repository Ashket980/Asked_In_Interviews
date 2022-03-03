#include <stdio.h>
 
// Function to find a duplicate element in a limited range array
int findDuplicate(int nums[], int n)
{
    int xor = 0;
 
    // take xor of all array elements
    for (int i = 0; i < n; i++) {
        xor ^= nums[i];
    }
 
    // take xor of numbers from 1 to `n-1`
    for (int i = 1; i <= n-1; i++) {
        xor ^= i;
    }
 
    // same elements will cancel each other as a ^ a = 0,
    // 0 ^ 0 = 0 and a ^ 0 = a
 
    // `xor` will contain the missing number
    return xor;
}
 
int main()
{
    // input array contains `n` numbers between 1 and `n-1` with one duplicate
    int nums[] = { 1, 2, 3, 4, 2 };
    int n = sizeof(nums) / sizeof(nums[0]);
 
    printf("The duplicate element is %d", findDuplicate(nums, n));
 
    return 0;
}
