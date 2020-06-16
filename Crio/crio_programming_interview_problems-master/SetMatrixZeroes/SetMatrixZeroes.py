def setMatrixZeroes(grid):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    n,m = len(grid),len(grid[0])
    r,c = set(),set()
    for i in range(n):
        for j in range(m):
            if(grid[i][j]==0):
                r.add(i)
                c.add(j)
    for i in range(n):
        for j in range(m):
            if(i in r or j in c):
                grid[i][j]=0
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__ == '__main__':
    row = input().split()
    n = int(row[0])
    m = int(row[1])
    grid = []
    for i in range(n):
        nums = input().split()
        nums = [int(i) for i in nums]
        grid.append(nums)
    setMatrixZeroes(grid)
    for row in grid:
        print(*row)