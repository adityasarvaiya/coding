
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
from queue import Queue
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
def townsAndPoliceStations(n,edges,sources):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    adj = [[] for i in range(n)]
    
    for edge in edges:
        x,y = edge
        x-=1
        y-=1
        adj[x].append(y)
        adj[y].append(x)

    distance=[-1]*n
    q = Queue()

    for source in sources:
        q.put(source-1)
        distance[source-1]=0

    while q.qsize()>0:
        top = q.get()
        for node in adj[top]:
            if distance[node]==-1:
                distance[node]=distance[top]+1
                q.put(node) 
    return distance
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    n,m = map(int,input().strip().split())
    edges = []
    for i in range(m):
        edges.append(list(map(int,input().strip().split())))    
    s = int(input())
    sources = list(map(int,input().strip().split()))
    ans = townsAndPoliceStations(n,edges,sources)
    print(*ans,sep='\n')


if __name__ == '__main__':
    main()
