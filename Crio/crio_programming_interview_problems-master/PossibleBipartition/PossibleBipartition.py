# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
def createAdjList(n ,edges ):
	adjList = [[] for _ in range(n+1)]
	for i in range(len(edges)):
		adjList[edges[i][0]].append(edges[i][1])
		adjList[edges[i][1]].append(edges[i][0])
	return adjList
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def possibleBipartition(n ,edges ):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	vec = createAdjList(n,edges)
	queue = list()
	level =  [0 for _ in range(n+1)]
	queue.append(1)
	level[1] = 1;
	flag = 0
	while len(queue) > 0:
		front = queue.pop(0)
		for node in vec[front]:
			if level[node] == 0:
				level[node] = level[front]+1
				queue.append(node)
			elif (level[node]%2==0 and (level[front]+1)%2==1) or (level[node]%2==1 and (level[front]+1)%2==0):
				flag=1
	if flag == 0:
		return "Possible"
	else:
		return "Not Possible"
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    t = int(input())
    for tests in range(t):
    	n ,m = map(int, input().strip().split())

    	edges = list()
    	for i in range(m):
    		edge = list(map(int,input().strip().split()))
    		edges.append(edge)
    	print(possibleBipartition(n,edges))

if __name__ == '__main__':
    main()
