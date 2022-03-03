# Function to print all distinct combinations of length `k`, where the
# repetition of elements is allowed
def findCombinations(A, k, i=0, out=[]):
 
    # base case: if the combination size is `k`, print it
    if len(out) == k:
        print(out)
        return
 
    # start from the previous element in the current combination
    # till the last element
    j = i
    while j < len(A):
 
        # add current element `A[j]` to the solution and recur with the
        # same index `j` (as repeated elements are allowed in combinations)
        out.append(A[j])
        findCombinations(A, k, j, out)
 
        # backtrack: remove the current element from the solution
        out.pop()
 
        # code to handle duplicates – skip adjacent duplicates
        while j < len(A) - 1 and A[j] == A[j + 1]:
            j = j + 1
 
        j = j + 1
 
 
if __name__ == '__main__':
 
    A = [1, 2, 1]
    k = 2
 
    # if the list contains repeated elements, sort the list to
    # handle duplicates combinations
    A.sort()
 
    findCombinations(A, k)
