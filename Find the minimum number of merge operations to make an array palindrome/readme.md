## Find the minimum number of merge operations to make an array palindrome ##

**Given a list of non-negative integers, find the minimum number of merge operations to make it a palindrome. A merge operation can only be performed on two adjacent elements. The result of a merge operation is that the two adjacent elements are replaced with their sum.**


**For example,**

      Input:  [6, 1, 3, 7]
      Output: 1
      Explanation: [6, 1, 3, 7] —> Merge 6 and 1 —> [7, 3, 7]


      Input:  [6, 1, 4, 3, 1, 7]
      Output: 2
      Explanation: [6, 1, 4, 3, 1, 7] —> Merge 6 and 1 —> [7, 4, 3, 1, 7] —> Merge 3 and 1 —> [7, 4, 4, 7]


      Input:  [1, 3, 3, 1]
      Output: 0
      Explanation: The list is already a palindrome
