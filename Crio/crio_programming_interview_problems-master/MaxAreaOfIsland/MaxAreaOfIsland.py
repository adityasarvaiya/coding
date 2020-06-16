
class Solution():
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    def dfs(self , grid, i , j):
        ans = 1
        if i>=0 and i+1<=self.n and j+1<=self.m and j>=0:
            if self.vis[i][j] == True or self.grid[i][j] == 0:
                return 0
        else:
            return 0
        self.vis[i][j]=True
        ans+=self.dfs(self.grid , i-1 ,j)
        ans+=self.dfs(self.grid , i+1 ,j)
        ans+=self.dfs(self.grid , i ,j+1)
        ans+=self.dfs(self.grid , i ,j-1)
        return ans
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS    

    def maxAreaOfIsland(self, n, m, grid):
        # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        self.vis = [[False for j in range(m+1)] for i in range(n+1)]
        self.grid = list()
        self.n= n
        self.m= m
        self.grid = grid
        n ,m = len(self.grid) , len(self.grid[0])
        ans =0 
        for i in range(self.n):
            for j in range(self.m):
                if(self.grid[i][j]==1 and not self.vis[i][j]):
                    ans = max(ans , self.dfs(grid , i, j))
        return ans
        # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    n, m  = map(int,input().split())
    grid = list()
    for _ in range(n):
        row = list(map(int,input().split()))
        grid.append(row)
    ans = Solution().maxAreaOfIsland(n, m, grid)
    print(ans)

if __name__ == "__main__":
    import sys
    sys.setrecursionlimit(50000)
    main()
