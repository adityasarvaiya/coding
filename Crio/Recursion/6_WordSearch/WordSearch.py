# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS

def isValid(x, y, board):
    n = len(board)
    m = len(board[0])
    if x < 0 or x >= n or y < 0 or y >= m:
        return False
    return True
dp = {}

def findWord(boardX, boardY, wordI, board, word, visited):
    if wordI == len(word):
        return True
         
    if not isValid(boardX, boardY, board):
        return False

    if visited[boardX][boardY]:
        return False
    
    if board[boardX][boardY] != word[wordI]:
        return False

    visited[boardX][boardY] = True

    dx = [0, 0, -1, 1]
    dy = [-1, 1, 0, 0]

    for x, y in zip(dx, dy):
        newX = boardX + x
        newY = boardY + y
        if findWord(newX, newY, wordI + 1, board, word, visited):
            return True

    visited[boardX][boardY] = False
    return False
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def exist(board, word):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    rows = len(board)
    cols = len(board[0])
    if len(word) > rows * cols:
        return False

    visited = [[False for j in range(cols)] for i in range(rows)]
    for i in range(rows):
        for j in range(cols):
            if board[i][j] == word[0]:
                if findWord(i, j, 0, board, word, visited):
                    return True

    return False
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__ == '__main__':
    row = input().split()
    n = int(row[0])
    m = int(row[1])
    board = []
    for i in range(n):
        nums = input().split()
        board.append(nums)
    word = input()
    if exist(board, word):
        print('true')
    else:
        print('false')
