# Find the previous smaller element for every array element
def findPrevSmaller(arr):
 
    # base case
    if not arr:
        return
 
    # do for each element
    for i in range(len(arr)):
        # keep track of the previous smaller element for element `arr[i]`
        prev = -1
        # process elements on the left of the element `arr[i]`
        for j in reversed(range(0, i)):
            # break the inner loop at the first smaller element on the
            # left of the element `arr[i]`
            if arr[j] < arr[i]:
                prev = arr[j]
                break
 
        print(prev, end=' ')
 
 
if __name__ == '__main__':
 
    arr = [2, 5, 3, 7, 8, 1, 9]
    findPrevSmaller(arr)
