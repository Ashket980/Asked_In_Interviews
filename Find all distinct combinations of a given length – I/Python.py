# Function to print all distinct combinations of length `k`
def findCombinations(A, k, subarrays, out=(), i=0):
 
    # invalid input
    if len(A) == 0 or k > len(A):
        return
 
    # base case: combination size is `k`
    if k == 0:
        subarrays.add(out)
        return
 
    # start from the next index till the last index
    for j in range(i, len(A)):
        # add current element `A[j]` to the solution and recur for next index
        # `j+1` with one less element `k-1`
        findCombinations(A, k - 1, subarrays, out + (A[j],), j + 1)
 
 
if __name__ == '__main__':
 
    A = [1, 2, 3]
    k = 2
 
    subarrays = set()
 
    # process elements from left to right
    findCombinations(A, k, subarrays)
    print(subarrays)
