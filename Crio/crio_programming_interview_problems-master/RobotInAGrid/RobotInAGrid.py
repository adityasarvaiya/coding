import sys

class RobotInAGrid:
    def __init__(self, rows, columns):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        self.visited = [[0 for i in range(columns)] for j in range(rows)] 
        self.path = list()
        self.isPath = None
        self.pathString = list()

    def isValid(self,x, y, n, m, grid):
        if x<0 or x>=n or y<0 or y>=m:
            return False
        if grid[x][y] == 1 or self.visited[x][y] == 1:
            return False
        return True


    def dfs(self,x,y,grid,n,m):
        self.visited[x][y]=1
        self.path.extend([x,y])
        if x== n-1 and y== m-1:
            for i in range(0,len(self.path),2):
                self.pathString.append(' '.join([str(j+1) for j in self.path[i:i+2]]))
            self.isPath = True
            return 
        if self.isValid(x+1,y,n,m,grid):
            self.dfs(x+1,y,grid,n,m)
        if self.isValid(x,y+1,n,m,grid):
            self.dfs(x,y+1,grid,n,m)
        self.path = self.path[:-2]
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

    def robotInAGrid(self, grid, n, m):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        self.isPath = False
        self.path = list()
        self.pathString = list()
        if grid[0][0] == 1:
            return ["Not Possible"]
        self.dfs(0,0,grid,n,m)
        if self.isPath:
            return self.pathString
        else:
            return ["Not Possible"] 

# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    

def main():
    rows, columns = map(int,input().split())
    grid=list()
    for _ in range(rows):
        grid.append(list(map(int,input().split())))
    obj =  RobotInAGrid(rows,columns) # Any initialization if needed
    result = obj.robotInAGrid(grid,rows,columns)
    for elem in result:
        print(elem)


if __name__ == "__main__":
    sys.setrecursionlimit(10 * 1000)
    main()
