# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
def createAdjList(n ,edges ):
    adjList = [[] for _ in range(n+1)]
    for i in range(len(edges)):
        adjList[edges[i][0]].append(edges[i][1])
        adjList[edges[i][1]].append(edges[i][0])
    return adjList

def bfs(n ,source ,vec):
    queue = list()
    level =  [0 for _ in range(n+1)]
    queue.append(source)
    level[source] = 1;
    while len(queue) > 0:
        front = queue.pop(0)
        for node in vec[front]:
            if level[node] == 0:
                level[node] = level[front]+1
                queue.append(node)
    ans = list()
    maxLev=-1
    index=-1
    for i in range(1,n+1):
        if maxLev<level[i]:
            maxLev=level[i]
            index= i
    ans.append(maxLev)
    ans.append(index)
    return ans;
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def diameterOfTree(n ,edges ):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    vec = createAdjList(n ,edges)
    source = bfs(n,1,vec)
    answer = bfs(n,source[1],vec)
    return answer[0]-1;
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS


def main():
    t = int(input())
    for tests in range(t):
    	n ,m = map(int, input().strip().split())
    	edges = list()
    	for i in range(m):
    		edge = list(map(int,input().strip().split()))
    		edges.append(edge)
    	print(diameterOfTree(n,edges))

if __name__ == '__main__':
    main()
