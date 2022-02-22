## Find minimum jumps required to reach the destination ##

**Given an array of non-negative integers, where each array element represents the maximum number of positions one can move forward from that element. Find the minimum number of 
jumps required to reach a given destination from a given source within the array.**


**If any element has value zero in the array, the destination cannot be reached through that element. If the source itself has value zero, return infinity as the destination 
cannot be reached at all. To make the problem simpler, let’s assume the source and destination to be the start and end of the array.**

**Example :**

    Input:  nums[] = { 4, 2, 0, 3, 2, 0, 1, 8 }
    Output: Minimum jumps required to reach the destination are 3.
    3 jumps: (4 —> 3 —> 1 —> 8) or (4 —> 2 —> 1 —> 8)
    4 jumps: (4 —> 2 —> 3 —> 1 —> 8) or (4 —> 3 —> 2 —> 1 —> 8)
    5 jumps: (4 —> 2 —> 3 —> 2 —> 1 —> 8)


    Input:  nums[] = { 4, 2, 2, 1, 0, 8, 1 }
    Output: Minimum jumps required to reach the destination are infinity. This is because no matter what path we choose, we will always end up in a dead cell.
    4 —> 2 —> 2 —> 1 —> 0
    4 —> 2 —> 1 —> 0
    4 —> 1 —> 0
    4 —> 0
