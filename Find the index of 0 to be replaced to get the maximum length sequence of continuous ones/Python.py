# Find the index of 0 to replace with 1 to get the maximum sequence
# of continuous 1's
def findIndexofZero(A):
 
    max_count = 0           # stores maximum number of 1's (including 0)
    max_index = -1          # stores index of 0 to be replaced
 
    prev_zero_index = -1    # stores index of previous zero
    count = 0               # stores current count of zeros
 
    # consider each index `i` in the list
    for i in range(len(A)):
 
        # if the current element is 1
        if A[i] == 1:
            count = count + 1
 
        else:
            # if the current element is 0
            # reset count to 1 + number of ones to the left of current 0
            count = i - prev_zero_index
 
            # update `prev_zero_index` to the current index
            prev_zero_index = i
 
        # update maximum count and index of 0 to be replaced if required
        if count > max_count:
            max_count = count
            max_index = prev_zero_index
 
    # return index of 0 to be replaced or -1 if the list contains all 1's
    return max_index
 
 
if __name__ == '__main__':
 
    A = [0, 0, 1, 0, 1, 1, 1, 0, 1, 1]
 
    index = findIndexofZero(A)
    if index != -1:
        print("Index to be replaced is", index)
    else:
        print("Invalid input")
