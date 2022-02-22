## Find the previous smaller element for each array element ##

**Given an integer array, find the previous smaller element for every array element. The previous smaller element of a number x is the first smaller number to the left of x in 
the array.**


**In other words, for each element A[i] in the array A, find an element A[j] such that j < i and A[j] < A[i] and value of j should be as maximum as possible. If the previous 
smaller element doesn't in the array for any element, consider it -1.**

**Example:**

    Input:  [2, 5, 3, 7, 8, 1, 9]
    Output: [-1, 2, 2, 3, 7, -1, 1]


    Input:  [5, 7, 4, 9, 8, 10]
    Output: [-1, 5, -1, 4, 4, 8]
    
    Note that the first element always has a previous smaller element as -1.
