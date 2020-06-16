import sys

#CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
board = []
res = ''
def checkValid(i, j):
    global board, res
    n = len(board)
    for x in range(n):
        if board[x][j]:
            return False
        if board[i][x]:
            return False
    
    for k in range(n):
        x = i + k
        y = j + k
        if x >= n or x < 0 or y >= n or y < 0:
            continue
        if board[x][y]:
            return False
    
    for k in range(n):
        x = i - k
        y = j + k
        if x >= n or x < 0 or y >= n or y < 0:
            continue
        if board[x][y]:
            return False

    for k in range(n):
        x = i + k
        y = j - k
        if x >= n or x < 0 or y >= n or y < 0:
            continue
        if board[x][y]:
            return False
    
    for k in range(n):
        x = i - k
        y = j - k
        if x >= n or x < 0 or y >= n or y < 0:
            continue
        if board[x][y]:
            return False
            
    return True
                
def to_string():
    global board, res
    return '\n'.join((''.join(str(element) for element in row) for row in board))

def getAllSolutions(i, j, left):
    # print(to_string(board))
    global board, res

    if i == len(board)-1 and j == len(board):
        if left > 0:
            return
        res += to_string() + '\n\n'
        return
    
    if j == len(board):
        return getAllSolutions(i + 1, 0, left)
    getAllSolutions(i, j + 1, left)
    if left > 0 and checkValid(i, j):
        board[i][j] = 1
        getAllSolutions(i, j + 1, left - 1)
        board[i][j] = 0

#CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def nQueens(n):
    #CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    global board, res

    board = [[0 for i in range(n)] for j in range(n)]
    getAllSolutions(0, 0, n)

    if res:
        return res
    return "No Solution Exists"
    #CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    n = int(input())
    result = nQueens(n)
    print(result)

if __name__ == '__main__':
    sys.setrecursionlimit(100000)
    main()

