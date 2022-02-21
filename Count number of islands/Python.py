from collections import deque
 
 
# Below lists detail all eight possible movements from a cell
# (top, right, bottom, left, and four diagonal moves)
row = [-1, -1, -1, 0, 1, 0, 1, 1]
col = [-1, 1, 0, -1, -1, 1, 0, 1]
 
 
# Function to check if it is safe to go to position (x, y)
# from the current position. The function returns false if (x, y)
# is not valid matrix coordinates or (x, y) represents water or
# position (x, y) is already processed.
 
def isSafe(mat, x, y, processed):
    return (x >= 0 and x < len(processed)) and (y >= 0 and y < len(processed[0])) and \
           mat[x][y] == 1 and not processed[x][y]
 
 
def BFS(mat, processed, i, j):
 
    # create an empty queue and enqueue source node
    q = deque()
    q.append((i, j))
 
    # mark source node as processed
    processed[i][j] = True
 
    # loop till queue is empty
    while q:
        # dequeue front node and process it
        x, y = q.popleft()
 
        # check for all eight possible movements from the current cell
        # and enqueue each valid movement
        for k in range(len(row)):
            # skip if the location is invalid, or already processed, or has water
            if isSafe(mat, x + row[k], y + col[k], processed):
                # skip if the location is invalid, or it is already
                # processed, or consists of water
                processed[x + row[k]][y + col[k]] = True
                q.append((x + row[k], y + col[k]))
 
 
def countIslands(mat):
 
    # base case
    if not mat or not len(mat):
        return 0
 
    # `M × N` matrix
    (M, N) = (len(mat), len(mat[0]))
 
    # stores if a cell is processed or not
    processed = [[False for x in range(N)] for y in range(M)]
 
    island = 0
    for i in range(M):
        for j in range(N):
            # start BFS from each unprocessed node and increment island count
            if mat[i][j] == 1 and not processed[i][j]:
                BFS(mat, processed, i, j)
                island = island + 1
 
    return island
 
 
 
if __name__ == '__main__':
 
    mat = [
        [1, 0, 1, 0, 0, 0, 1, 1, 1, 1],
        [0, 0, 1, 0, 1, 0, 1, 0, 0, 0],
        [1, 1, 1, 1, 0, 0, 1, 0, 0, 0],
        [1, 0, 0, 1, 0, 1, 0, 0, 0, 0],
        [1, 1, 1, 1, 0, 0, 0, 1, 1, 1],
        [0, 1, 0, 1, 0, 0, 1, 1, 1, 1],
        [0, 0, 0, 0, 0, 1, 1, 1, 0, 0],
        [0, 0, 0, 1, 0, 0, 1, 1, 1, 0],
        [1, 0, 1, 0, 1, 0, 0, 1, 0, 0],
        [1, 1, 1, 1, 0, 0, 0, 1, 1, 1]
    ]
 
    print('The total number of islands is', countIslands(mat))
