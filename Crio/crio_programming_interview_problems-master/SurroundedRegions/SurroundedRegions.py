# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
def dfs(grid,vis,i,j):
    vis[i][j] = True
    grid[i][j]='-'
    for r,c in [[i-1,j],[i+1,j],[i,j+1],[i,j-1]]:
        if(r>=0 and r<n and c>=0 and c<m and grid[r][c]=='O'):
            dfs(grid,vis,r,c)
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def surroundedRegions(grid):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    vis = [[False]*m for i in range(n)]
    for i in range(n):
        for j in range(m):
            if((i==n-1 or j==m-1 or i*j==0) and grid[i][j]=='O'):
                dfs(grid,vis,i,j)
    
    for i in range(n):
        for j in range(m):
            if(grid[i][j]=='-'):
                grid[i][j]='O'
            else:
                grid[i][j]='X'
    return grid
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__ == '__main__':
    row = input().split()
    n = int(row[0])
    m = int(row[1])
    grid = []
    for i in range(n):
        nums = input().split()
        grid.append(nums)
    grid = surroundedRegions(grid)
    for row in grid:
        print(*row)
