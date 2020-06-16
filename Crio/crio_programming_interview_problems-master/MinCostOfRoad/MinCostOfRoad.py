# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
parent= []
def init(n):
    for i in range(n+1):
        parent.append(i)
def findParent(x):
    while x!= parent[x]:
        x=parent[parent[x]]
    return x
def union(x,y):
    p=findParent(x)
    q=findParent(y)
    if p!= q:
        parent[p]=q
 # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
def minCostOfRoad(n,edges):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    edges=sorted(edges,key=lambda item: item[2])
    e=len(edges)
    cnt =0
    cost=0
    init(n)
    for i in range(e):
        x=findParent(edges[i][0])
        y=findParent(edges[i][1])
        if x != y:
            cnt+=1
            cost += edges[i][2]
            union(edges[i][0],edges[i][1])

    return cost
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    n,e=map(int,input().split())
    edges=[]
    for i in range(e):
        a,b,c= map(int,input().split())
        edges.append([a,b,c])
    ans = minCostOfRoad(n,edges)
    print(ans)
if __name__ == '__main__':
    main()
