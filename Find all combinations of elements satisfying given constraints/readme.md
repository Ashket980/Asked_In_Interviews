## Find all combinations of elements satisfying given constraints ##

**Given a positive number n, find all combinations of 2×n elements such that every element from 1 to n appears exactly twice and the distance between its two 
appearances is exactly equal to the value of the element.**

    For example,

      Input: n = 3
      Output:
      3 1 2 1 3 2
      2 3 1 2 1 3

      Input: n = 4
      Output:
      4 1 3 1 2 4 3 2
      2 3 4 2 1 3 1 4

      Input: n = 7
      Output:
      1 7 1 2 5 6 2 3 4 7 5 3 6 4
      5 1 7 1 6 2 5 4 2 3 7 6 4 3
      4 1 7 1 6 4 2 5 3 2 7 6 3 5
      …
      …
      Total 52 configurations possible.

      Note that no combination of elements is possible for some values of n like 2, 5, 6, etc.
