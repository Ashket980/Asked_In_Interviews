# Function to find the count of distinct elements in every sublist
# of size `k` in a list
def findDistinctCount(A, k):
 
    # dictionary to store the frequency of elements in the current window of size `k`
    freq = {}
 
    # maintains the count of distinct elements in every sublist of size `k`
    distinct = 0
 
    # loop through the list
    for i in range(len(A)):
 
        # ignore the first `k` elements
        if i >= k:
            # remove the first element from the sublist by reducing its
            # frequency in the dictionary
            freq[A[i - k]] -= 1
 
            # reduce the distinct count if we are left with 0
            if freq.get(A[i - k]) == 0:
                distinct = distinct - 1
 
        # add the current element to the sublist by incrementing its
        # count in the dictionary
        freq[A[i]] = freq.get(A[i], 0) + 1
 
        # increment distinct count by 1 if element occurs for the first
        # time in the current window
        if freq.get(A[i]) == 1:
            distinct = distinct + 1
 
        # print count of distinct elements in the current sublist
        if i >= k - 1:
            print("The count of distinct elements in sublist",
                f"[{(i - k + 1)}, {i}] is {distinct}")
 
 
if __name__ == '__main__':
 
    input = [1, 1, 2, 1, 3]
    k = 3
 
    findDistinctCount(input, k)
