from queue import Queue
def connectedComponentsInGraph(n,edges):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    adj =[]
    for i in range(n+1):
        adj.append([])

    for edge in edges:
        adj[edge[0]].append(edge[1])
        adj[edge[1]].append(edge[0])
    
    vis = [0]*(n+1) 
    ans =0

    for i in range(1,n+1):
        if vis[i]!=1:
            ans = ans+1
            vis[i]=1;
            q= Queue()
            q.put(i)

            while q.qsize():
                top = q.get()
                for node in adj[top]:
                    if vis[node]!=1:
                        vis[node]=1
                        q.put(node)
    return ans
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    
def main():
    n,m = map(int,input().split())
    
    edges = [];
    for i in range(m):
        pair = list(map(int,input().strip().split()))
        edges.append(pair)

    ans = connectedComponentsInGraph(n,edges)

    print(ans)

if __name__ == "__main__":
    main()
