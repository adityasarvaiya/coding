import sys

def routeBetweenNode(start, end, n, edges):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    graph = [set() for i in range(n + 1)]
    for edge in edges:
        graph[edge[0]].add(edge[1])
    vis = [False for i in range(len(graph))]
    queue = [start]
    vis[start] = True

    while queue:
        current_vartex = queue[-1]
        queue.pop()
        
        for child in graph[current_vartex]:
            if end == child:
                return True
            if not vis[child]:
                vis[child] = True
                queue.append(child)
                
    return False
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS


T = int(input())
sys.setrecursionlimit(20 * 1000)
for _t in range(T):
    n, m = map(int, input().strip().split())
    edges = list()
    for i in range(m):
        edge = list(map(int, input().strip().split()))
        edges.append(edge)
    start, end = map(int, input().strip().split())
    result = routeBetweenNode(start, end, n, edges)
    print('yes' if result else 'no')
