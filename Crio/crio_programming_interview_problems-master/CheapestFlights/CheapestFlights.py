# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
from queue import PriorityQueue
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
def cheapestFlights(n,edges,source,des,k):
	# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    graph=[[] for _ in range(n+1)] 
    for i in range(len(edges)):
        a=edges[i][0]
        b=edges[i][1]
        c= edges[i][2]
        graph[a].append([b,c])
    q = PriorityQueue()

    q.put((0,source,0))

    while not q.empty():
        dis,node,steps=q.get()
        if des == node:
        	return dis
        if steps <= (k):
	        for b,c in graph[node]:
	            q.put((dis+c,b,steps+1))
         
    cost=-1
    return cost
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    n,e=map(int,input().split())
    edges=[]
    for i in range(e):
        a,b,c= map(int,input().split())
        edges.append([a,b,c])
    s,des,k=map(int,input().split())
    ans = cheapestFlights(n,edges,s,des,k)
    print(ans)
if __name__ == '__main__':
    main()