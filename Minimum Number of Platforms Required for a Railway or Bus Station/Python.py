# Program to find minimum number of platforms
# required on a railway station
 
def findPlatform(arr, dep, n):
    '''
    Accepts two arrays with arrival and departure time
    and the size of the array
    Returns minimum number of platforms required
    '''
 
    # plat_needed indicates number of platforms
    # needed at a time
    plat_needed = 1
    result = 1
 
    # run a nested loop to find overlap
    for i in range(n):
        # minimum platform needed
        plat_needed = 1
 
        for j in range(i+1, n):
            # check for overlap
            if ((arr[i] >= arr[j] and arr[i] <= dep[j]) or
                    (arr[j] >= arr[i] and arr[j] <= dep[i])):
                plat_needed += 1
 
        # update result
        result = max(result, plat_needed)
 
    return result
 
# Driver code
 
 
def main():
    arr = [900, 940, 950, 1100, 1500, 1800]
    dep = [910, 1200, 1120, 1130, 1900, 2000]
 
    n = len(arr)
 
    print("Minimum Number of Platforms Required = {}".format(
        findPlatform(arr, dep, n)))
 
 
if __name__ == '__main__':
    main()
