import fileinput, traceback
from math import sqrt, ceil
from typing import List
import sys
 
class YoungTableau:
 
    # Recursive function to fix the tableau property in an `N × N` Young tableau.
    # An infinite value is initially placed at the first cell `(0, 0)` of the tableau.
    # The function works by swapping the smallest of `[i+i, j]` and `[i, j+1]` with
    # `[i, j]` and recur for the smaller value.
    def __fixTableau(self, tableau, i=0, j=0):
        N = len(tableau)
 
        # get the values present at the bottom and right cell of the current cell
        bottom = tableau[i + 1][j] if (i + 1 < N) else sys.maxsize
        right = tableau[i][j + 1] if (j + 1 < N) else sys.maxsize
 
        if bottom == sys.maxsize and right == sys.maxsize:
            return
 
        if bottom < right:  # go down
 
            # swap `tableau[i][j]` and `tableau[i + 1][j]`
 
            temp = tableau[i][j]
            tableau[i][j] = tableau[i + 1][j]
            tableau[i + 1][j] = temp
 
            self.__fixTableau(tableau, i + 1, j)
 
        else:  # go right
 
            # swap `tableau[i][j]` and `tableau[i][j + 1]`
 
            temp = tableau[i][j]
            tableau[i][j] = tableau[i][j + 1]
            tableau[i][j + 1] = temp
 
            self.__fixTableau(tableau, i, j + 1)
 
    # Recursive function to insert a new element into a non-full `N × N` Young tableau.
    # The new element is initially placed at the bottom-right corner of the tableau.
    # The function works by swapping the smallest of `[i-i, j]` and `[i, j-1]` with
    # `[i, j]` and recur for the smaller value.
    def __insert(self, tableau, i, j):
        # base case
        if i == 0 and j == 0:
            return
 
        # handle separately for the first row
        if i == 0:
            if tableau[i][j] < tableau[i][j - 1]:
                # swap `tableau[i][j]` and `tableau[i][j-1]`
                temp = tableau[i][j]
                tableau[i][j] = tableau[i][j - 1]
                tableau[i][j - 1] = temp
 
                self.__insert(tableau, i, j - 1)
            return
 
        # handle separately for the first column
        if j == 0:
            if tableau[i][j] < tableau[i - 1][j]:
                # swap `tableau[i][j]` and `tableau[i-1][j]`
 
                temp = tableau[i][j]
                tableau[i][j] = tableau[i - 1][j]
                tableau[i - 1][j] = temp
 
                self.__insert(tableau, i - 1, j)
            return
 
        if tableau[i][j] < tableau[i - 1][j]:  # go up
 
            # swap `tableau[i][j]` and `tableau[i-1][j]`
 
            temp = tableau[i][j]
            tableau[i][j] = tableau[i - 1][j]
            tableau[i - 1][j] = temp
 
            self.__insert(tableau, i - 1, j)
 
        if tableau[i][j] < tableau[i][j - 1]:  # go left
 
            # swap `tableau[i][j]` and `tableau[i][j-1]`
 
            temp = tableau[i][j]
            tableau[i][j] = tableau[i][j - 1]
            tableau[i][j - 1] = temp
 
            self.__insert(tableau, i, j - 1)
 
    # Function to extract the next minimum element from the Young tableau
    def extractMin(self, tableau):
        # the first cell of the tableau stores the minimum element
        min = tableau[0][0]
 
        # make the first element as infinity
        tableau[0][0] = sys.maxsize
 
        # fix the Young tableau property
        self.__fixTableau(tableau)
 
        return min
 
    # Function construct an `N × N` Young tableau from the given keys
    def construct(self, keys):
        N = ceil(sqrt(len(keys)))
        tableau = [[sys.maxsize for x in range(N)] for y in range(N)]
 
        # do for each key
        for key in keys:
            # check for overflow
            if tableau[N - 1][N - 1] != sys.maxsize:
                break
 
            # place the key at the bottom-right corner of the tableau
            tableau[N - 1][N - 1] = key
 
            # move the key to its correct position in the tableau
            self.__insert(tableau, N - 1, N - 1)
 
        return tableau
 
 
def sort(keys: List[int]) -> None:
 
    if not keys or not len(keys):
        return
 
    obj = YoungTableau()
 
    # construct a Young tableau from the above keys
    tableau = obj.construct(keys)
 
    # repeatedly call `extractMin()` and fill `keys[]` with the returned values
    for i in range(len(keys)):
        keys[i] = obj.extractMin(tableau)
 
 
if __name__ == '__main__':
 
    N = 3
 
    # unsorted input
    keys = [6, 4, 8, 7, 2, 3, 1, 5]
 
    # sort the input keys
    sort(keys)
 
    # print the sorted input
    print(keys)
