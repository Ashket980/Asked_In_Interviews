#include <stdio.h>
 
// Find the previous smaller element for every element in an array
void findPrevSmaller(int arr[], int n)
{
    // do for each element
    for (int i = 0; i < n; i++)
    {
        // keep track of the previous smaller element for element `arr[i]`
        int prev = -1;
 
        // process elements on the left of the element `arr[i]`
        for (int j = i - 1; j >= 0; j--)
        {
            // break the inner loop at the first smaller element on the
            // left of the element `arr[i]`
            if (arr[j] < arr[i])
            {
                prev = arr[j];
                break;
            }
        }
 
        printf("%d ", prev);
    }
}
 
int main(void)
{
    int arr[] = { 2, 5, 3, 7, 8, 1, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    findPrevSmaller(arr, n);
 
    return 0;
}
