## Truncate an integer array such that `2×min` becomes more than `max` ##

**Given an array of positive integers, truncate it such that 2×min becomes more than max, and the total number of removals is minimal. The min and max are the minimum and the maximum elements in the array, respectively. The elements can be removed either from the start or end of the array if the above condition does not meet.**

**For example,**

    Input:  [4, 6, 1, 7, 5, 9, 2]
    Output: The minimum number of removals is 4
    The truncated array is [7, 5, 9] where 9 < 2 × 5.


    Input:  [4, 2, 6, 4, 9]
    Output: The minimum number of removals is 3
    The truncated array is [6, 4] where 6 < 2 × 4.
