# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
from collections import defaultdict 

class Graph:
  
    def __init__(self,vertices,edges): 
        self.V= vertices 
        self.graph = edges
        self.parent = [i for i in range(vertices+1)]

    def addEdge(self,u,v,w): 
        self.graph.append([u,v,w]) 

    def find(self, i, parent): 
        while parent[i] != i: 
            parent[i] = parent[parent[i]]
            i = parent[i]
        return i

    def union(self, parent, x, y): 
        xroot = self.find(x , parent) 
        yroot = self.find(y , parent) 
        self.parent[xroot] = yroot
        
    def KruskalMST(self): 
        result = list()
        cost = 0 
        self.graph =  sorted(self.graph,key=lambda item: item[2])
        for edge in self.graph:
            p1 = self.find(edge[0],self.parent)
            p2 = self.find(edge[1],self.parent)
            if p1==p2:
                continue
            cost += edge[2] 
            self.union(self.parent, p1,p2)
        return cost
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def cobbledStreets(n, p ,edges):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    edges = sorted(edges)
    graph = Graph(n,edges)
    cost = graph.KruskalMST()
    return cost*p
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    t = int(input())
    for i in range(t):
        p,n,m = map(int,input().strip().split())
        edges = list()
        for _ in range(m):
            edge = list(map(int,input().split()))
            edges.append(edge)
        ans = cobbledStreets(n,p,edges)
        print(ans)


if __name__ == "__main__":
    main()
