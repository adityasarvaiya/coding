# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
from collections import defaultdict 

class Graph: 
    def __init__(self, project): 
        self.graph = defaultdict(list) 
        self.V = project
    def addEdge(self, u, v): 
        self.graph[u].append(v) 
    def topologicalSort(self): 
        in_degree = defaultdict(lambda: 0)
        for i in self.graph: 
            for j in self.graph[i]: 
                in_degree[j] += 1
        queue = list()
        for i in self.V: 
            if in_degree[i] == 0: 
                queue.append(i) 
        cnt = 0
        top_order = list()
        while queue: 
            u = queue.pop(0) 
            top_order.append(u)
            for i in self.graph[u]: 
                in_degree[i] -= 1
                if in_degree[i] == 0: 
                    queue.append(i) 
            cnt += 1
        if cnt != len(self.V):
            return [-1]
        return top_order 
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def buildOrder(project , dependencies):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    n = len(project)
    g = Graph(project)
    for depend in dependencies:
        g.addEdge(depend[0],depend[1])
    return g.topologicalSort()
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    n,d = map(int,input().split())
    project = input().split()
    assert len(project) == n
    dependencies = list()
    for i in range(d):
        p,q = input().split()
        dependencies.append([p,q])

    ans = buildOrder(project,dependencies)
    print(' '.join(map(str,ans)))

if __name__ == "__main__":
    main()
