# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
def createAdjList(n ,edges ):
    adjList = [[] for _ in range(n+1)]
    for i in range(len(edges)):
        adjList[edges[i][0]].append(edges[i][1])
        adjList[edges[i][1]].append(edges[i][0])
    return adjList

def DFSUtil(adj, v, parent, visited):
    visited[v] = True
    flag = False
    for i in adj[v]:
        if(visited[i] == False): 
            flag = DFSUtil(adj, i, v, visited)
    
        elif (i != parent):
            return True
        if(flag):
            return True
    return flag
def DFS(adj, v, visited):
    return DFSUtil(adj, v, -1, visited)
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def detectCycle(nodes, edges):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    flag = False
    visited = [False] * (nodes+1)
    adj = createAdjList(nodes, edges)
    for node in range(1,nodes+1):
        if(not visited[node] and not flag):
            flag = DFS(adj, node,visited)
    if(flag):
        return "Yes"
    else:
        return "No"
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS


if __name__ == '__main__':
    tests = int(input())
    while(tests>0):
        tests-=1
        n,e = map(int,input().split())
        edges = []
        
        for i in range(e):
            u,v = map(int,input().split())
            edges.append([u,v])
        ans = detectCycle(n,edges)
        print(ans)
