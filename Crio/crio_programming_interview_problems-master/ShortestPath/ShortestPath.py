# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
from queue import Queue
def createAdjList(n ,edges ):
    adjList = [[] for _ in range(n+1)]
    for i in range(len(edges)):
        adjList[edges[i][0]].append(edges[i][1])
        adjList[edges[i][1]].append(edges[i][0])
    return adjList
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def shortestPath(nodes, edges, source, destination):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    adj = createAdjList(nodes, edges)
    vis = [False]*(nodes+1)
    vis[source]=True
    parent = [None]*(nodes+1)
    q = Queue(maxsize=0)
    q.put(source)
    while(not q.empty() and not vis[destination]):
        node = q.get()
        for child in adj[node]:
            if(not vis[child]):
                q.put(child)
                vis[child]=True
                parent[child]=node
            if(vis[destination]):
                break
    node = destination
    ans = [destination]
    while(node != source):
        node = parent[node]
        ans.append(node)
    ans.reverse()
    return ans
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__=="__main__":
    n,e = map(int,input().split())
    edges = [[] for _ in range(e)]
    for i in range(e):
        u,v = map(int,input().split())
        edges[i].append(v)
        edges[i].append(u)
    s,d = map(int,input().split())
    ans = shortestPath(n,edges,s,d)
    for node in ans:
        print(node)
