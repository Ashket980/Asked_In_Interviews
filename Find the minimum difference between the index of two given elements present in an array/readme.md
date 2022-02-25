## Find the minimum difference between the index of two given elements present in an array ##

**Given an integer array nums and two integers x and y present in it, find the minimum absolute difference between indices of x and y in a single traversal of the array.**


    For Example :
    
      Input:
      arr = { 1, 3, 5, 4, 8, 2, 4, 3, 6, 5 }
      x = 3, y = 2

      Output: 2
      
      Explanation: Element 3 is present at index 1 and 7, and element 2 is present at index 5. Their minimum absolute difference is min(abs(1-5), abs(7-5)) = 2


      Input:
      arr = { 1, 3, 5, 4, 8, 2, 4, 3, 6, 5 }
      x = 2, y = 5

      Output: 3
      
      Explanation: Element 2 is present at index 5, and element 5 is present at index 2 and 9. Their minimum absolute difference is min(abs(5-2), abs(5-9)) = 3
