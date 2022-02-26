# Function to find the closest pair to `target` in given sorted lists `first` and `second`
def findClosestPair(first, second, target):
 
    # base case
    if not len(first) or not len(second):
        return ()
 
    # `x` and `y` points to the indexes of the closest pair found so far
    x = y = 0
 
    for i in range(len(first)):
        for j in range(len(second)):
            # update the closest pair if the current pair `(i, j)`
            # is more closer to `target`
            if abs(first[i] + second[j] - target) < abs(first[x] + second[y] - target):
                x = i
                y = j
 
    return first[x], second[y]
 
 
if __name__ == '__main__':
 
    first = [1, 8, 10, 12]
    second = [2, 4, 9, 15]
    target = 11
 
    pair = findClosestPair(first, second, target)
    print("The closest pair is", pair)
