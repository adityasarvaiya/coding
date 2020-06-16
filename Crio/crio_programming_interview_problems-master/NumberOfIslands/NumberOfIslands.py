
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
def dfs(grid , i , j , n, m, vis):
    if ( i>= n or j>=m or i<0 or j<0 or grid[i][j] == "0" or vis[i][j]):
        pass
    elif grid[i][j] == "1":
        vis[i][j] = True
        dfs(grid, i + 1, j, n, m, vis)
        dfs(grid, i - 1, j, n, m, vis)
        dfs(grid, i, j + 1, n, m, vis)
        dfs(grid, i, j - 1, n, m, vis)

# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def numIslands(grid):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    island = 0
    n = len(grid)
    if n == 0:
        return 0
    m  = len(grid[0])
    vis = [[False for i in range(m)] for i in range(n)]        
    for i in range(n):
        for j in range(m):
            if grid[i][j] != '0' and not vis[i][j]:
                island+=1
                dfs(grid,i,j,n,m,vis)
    return island
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS


def main():
    row = input().split()
    n = int(row[0])
    m = int(row[1])
    grid = []
    for i in range(n):
        r = input()
        grid.append(r)
    result = numIslands(grid)
    print(result)

if __name__ == '__main__':
    import sys
    sys.setrecursionlimit(10000)
    main()

