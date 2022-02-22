# Find the next greater element for every element in a list
def findNextGreaterElements(input):
 
    # base case
    if not input:
        return
 
    result = [-1] * len(input)
 
    # create an empty stack
    s = deque()
 
    # do for each element
    for i in range(len(input)):
 
        # loop till we have a greater element on top or stack becomes empty.
 
        # Keep popping elements from the stack smaller than the current
        # element, and set their next greater element to the current element
        while s and input[s[-1]] < input[i]:
            result[s[-1]] = input[i]
            s.pop()
 
        # push current "index" into the stack
        s.append(i)
 
    return result
 
 
if __name__ == '__main__':
 
    input = [2, 7, 3, 5, 4, 6, 8]
    print(findNextGreaterElements(input))
