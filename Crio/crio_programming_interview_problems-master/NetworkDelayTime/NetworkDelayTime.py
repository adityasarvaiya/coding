
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
from queue import PriorityQueue
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def networkDelayTime(n,edges,source):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    
    graph=[[] for _ in range(n+1)] 
    for i in range(len(edges)):
        a=edges[i][0]
        b=edges[i][1]
        c= edges[i][2]
        graph[a].append([b,c])
    q = PriorityQueue()

    distance=[2**60-1]*(n+1)
    distance[source]=0
    for b,c in graph[source]:
        q.put((c,b))
        distance[b]=c

    while not q.empty():
        dis,node=q.get()
        distance[node] = min(distance[node],dis)
        for b,c in graph[node]:
            if distance[b] > distance[node]+c:
                distance[b]= distance[node]+c
                q.put((distance[b],b))

    cost=-1
    for i in range(1,n+1):
        cost= max(cost,distance[i])
    if cost == (2**60-1):
        cost=-1
    return cost
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    n,e=map(int,input().split())
    edges=[]
    for i in range(e):
        a,b,c= map(int,input().split())
        edges.append([a,b,c])
    s=int(input())
    ans = networkDelayTime(n,edges,s)
    print(ans)
if __name__ == '__main__':
    main()
