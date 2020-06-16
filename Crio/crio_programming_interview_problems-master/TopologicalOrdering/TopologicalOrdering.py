# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
def go(i,ans,vis,adj):
    if vis[i]==1:
        return 
    vis[i]=1
    for node in adj[i]:
        go(node,ans,vis,adj)
    ans.append(i)

# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def topologicalOrdering(n,edges):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    adj = [[] for i in range(n+1)]
    for edge in edges:
        adj[edge[0]].append(edge[1])
    
    ans = []
    vis = [0 for i in range(n+1)]
    for i in range(1,n+1):
        if vis[i]==0:
            go(i,ans,vis,adj)

    ans = reversed(ans)

    return ans
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS




def main():
    n,m = map(int,input().strip().split())
    edges = []
    for i in range(m):
        u,v = map(int,input().strip().split())
        edges.append([u,v])

    ans = topologicalOrdering(n,edges)
    print(*ans,' ')

if __name__=="__main__":
    main()
