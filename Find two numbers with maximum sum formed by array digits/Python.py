# Find two numbers with a maximum sum formed by digits of a list
def findMaximum(input):
 
    # base case
    if len(input) <= 1:
        return
 
    # sort the list in descending order
    input.sort(reverse=True)
 
    # fill `x` with digits at the odd indices of the sorted list
    x = 0
    for i in range (0, len(input), 2):
        x = x * 10 + input[i]
 
    # fill `y` with digits at the even indices of the sorted list
    y = 0
    for i in range (1, len(input), 2):
        y = y * 10 + input[i]
 
    # print `x` and `y`
    print(f'The two numbers with maximum sum are {x} and {y}')
 
 
if __name__ == '__main__':
 
    input = [4, 6, 2, 7, 9, 8]
    findMaximum(input)
