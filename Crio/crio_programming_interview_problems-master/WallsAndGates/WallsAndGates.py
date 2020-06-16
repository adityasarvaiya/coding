# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
from queue import Queue
INF = 2147483647
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def wallsAndGates(n,m,grid):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    dis = [[INF]*m for _ in range(n)]
    q = Queue(maxsize=0)
    for i in range(n):
        for j in range(m):
            if(grid[i][j]==0):
                q.put([i,j])
                dis[i][j]=0
            if(grid[i][j]==-1):
                dis[i][j]=-1
    while(not q.empty()):
        i,j = q.get()
        for r,c in [[i-1,j], [i+1,j], [i,j-1], [i,j+1]]:
            if(r>=0 and r<n and c>=0 and c<m):
                if(dis[r][c] > dis[i][j]+1):
                    dis[r][c] = dis[i][j]+1
                    q.put([r,c])

    return dis
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__=="__main__":
    n,m = map(int,input().split())
    adj = []
    for i in range(n):
        adj.append(list(map(int,input().split())))
    ans = wallsAndGates(n,m,adj)
    for row in ans:
        print(*row)
