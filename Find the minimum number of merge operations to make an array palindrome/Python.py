# Function to find the minimum number of merge operations to make a
# given array palindrome
def findMin(arr):
 
    # stores the minimum number of merge operations needed
    count = 0
 
    # `i` and `j` initially points to endpoints of the array
    i = 0
    j = len(arr) - 1
 
    # loop till the search space is exhausted
    while i < j:
        if arr[i] < arr[j]:
            # merge item at i'th index with the item at (i+1)'th index
            arr[i + 1] += arr[i]
            i = i + 1
            count = count + 1
        elif arr[i] > arr[j]:
            # merge item at (j-1)'th index with the item at j'th index
            arr[j - 1] += arr[j]
            j = j - 1
            count = count + 1
        # otherwise, ignore both the elements
        else:
            i = i + 1
            j = j - 1
 
    return count
 
if __name__ == '__main__':
 
    arr = [6, 1, 4, 3, 1, 7]
    min = findMin(arr)
    print("The minimum number of operations required:", min)
