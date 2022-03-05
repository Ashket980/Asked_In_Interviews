# Partition set `S` into two subsets, `S1` and `S2`, such that the
# difference between the sum of elements in `S1` and the sum
# of elements in `S2` is minimized
def findMinAbsDiff(S, n, S1, S2, lookup):
 
    # Base case: if the list becomes empty, return the absolute
    # difference between both sets
    if n < 0:
        return abs(S1 - S2)
 
    # Construct a unique key from dynamic elements of the input.
    # Note that we can uniquely identify the subproblem with `n` and `S1` only,
    # as `S2` is nothing but `S-S1`, where `S` is the sum of all elements
    key = (n, S1)
 
    # If the subproblem is seen for the first time, solve it and
    # store its result in a dictionary
    if key not in lookup:
 
        # Case 1. Include the current item in subset `S1` and recur
        # for the remaining items `n-1`
        inc = findMinAbsDiff(S, n - 1, S1 + S[n], S2, lookup)
 
        # Case 2. Exclude the current item from subset `S1` and recur for
        # the remaining items `n-1`
        exc = findMinAbsDiff(S, n - 1, S1, S2 + S[n], lookup)
 
        lookup[key] = min(inc, exc)
 
    return lookup[key]
 
 
if __name__ == '__main__':
 
    # Input: a set of items
    S = [10, 20, 15, 5, 25]
 
    # create a dictionary to store solutions to subproblems
    lookup = {}
 
    print('The minimum difference is', findMinAbsDiff(S, len(S) - 1, 0, 0, lookup))
