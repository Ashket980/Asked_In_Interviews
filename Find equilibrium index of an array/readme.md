## Find equilibrium index of an array ##

**Given an integer array, find the equilibrium index in it.**

    For an array A consisting n elements, index i is an equilibrium index if the sum of elements of subarray A[0…i-1] is equal 
    to the sum of elements of subarray A[i+1…n-1]. i.e.
    (A[0] + A[1] + … + A[i-1]) = (A[i+1] + A[i+2] + … + A[n-1]), where 0 < i < n-1

    Similarly, 0 is an equilibrium index if A[1] + A[2] + … + A[n-1] sums to 0 and n-1 is an equilibrium index if A[0] + A[1] + … + A[n-2] sums to 0.

    To illustrate, consider the array {0, -3, 5, -4, -2, 3, 1, 0}. The equilibrium index is found at index 0, 3, and 7.
