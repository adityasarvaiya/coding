from queue import Queue
# CRIO_SOLUTION_AND_STUB_START_MODULE_L1_PROBLEMS
# CRIO_SOLUTION_AND_STUB_END_MODULE_L1_PROBLEMS

class TreeNode:
	def __init__(self, val):
		self.val = val
		self.left = None
		self.right = None
		self.next = None

def getTreeFromEdges(n, val, edges):
    nodes = []
    for i in range(n):
        nodes.append(TreeNode(val[i]))

    for edge in edges:
        parentIdx, leftChildIdx, rightChildIdx = edge

        if leftChildIdx >= 0:
            nodes[parentIdx-1].left = nodes[leftChildIdx-1]
        
        if rightChildIdx >= 0:
            nodes[parentIdx-1].right = nodes[rightChildIdx-1]

    return nodes

def readTree():
	n = int(input())
	if n==0:
		return []
	val = list(map(int, input().strip().split()))
	edges = []
	for i in range(n):
		edges.append(list(map(int, input().strip().split())))
	return getTreeFromEdges(n, val, edges)

def readTreeReturnAllNodes():
	nodes = readTree()
	return nodes

def readTreeReturnRoot():
	nodes = readTree()
	if len(nodes) == 0 :
		return None 
	root = nodes[0]
	return root

def isValidBST(root, low=-10**9, high=10**9):
    if root == None:
        return True
    if root.val < low or root.val > high:
        return False
    return isValidBST(root.left, low, root.val) and isValidBST(root.right, root.val, high)


def makeTreeFromArray(idx, tree, root):
	if idx >= len(tree):
		return None

	if tree[idx] == 'null':
		return None

	x = int(tree[idx])
	root = TreeNode(x)
	root.left = makeTreeFromArray(2*idx + 1, tree, root.left)
	root.right = makeTreeFromArray(2*idx + 2, tree, root.right)
	return root

def makeLevelOrderFromTree(root):
	answer = []
	if root == None:
		return answer
	q = Queue()
	q.put(root)
	while not q.empty():
		atThisLevel = []
		size = q.qsize()
		while size > 0:
			size -= 1
			temp = q.get()
			if temp == None:
				atThisLevel.append('null')
				continue
			else:
				q.put(temp.left)
				q.put(temp.right)
				atThisLevel.append(str(temp.val))
		answer.append(atThisLevel)
	return answer

def makePreOrderFromTree(root):
	preOrder = list()
	if root == None:
		return preOrder
	
	preOrder.extend([root.val])
	preOrder.extend(makePreOrderFromTree(root.left))
	preOrder.extend(makePreOrderFromTree(root.right))
	return preOrder

def makeInOrderFromTree(root):
	inOrder = list()
	if root == None:
		return inOrder
	
	inOrder.extend(makeInOrderFromTree(root.left))
	inOrder.extend([root.val])
	inOrder.extend(makeInOrderFromTree(root.right))
	return inOrder

def makeNextPointersFromTree(root, nextArray):
	if root == None:
		return nextArray
	q = Queue()
	q.put(root)
	while not q.empty():
		size = q.qsize()
		for _ in range(size):
			temp = q.get()
			if not temp.left:
				q.put(temp.left)
			if not temp.right:
				q.put(temp.right)
			if temp.next == None:
				nextArray.extend(['null'])
			else:
				nextArray.extend([temp.next.val])
	return nextArray

def treeNodeToString(root):
	arr = makeLevelOrderFromTree(root)
	s = " "
	for i in arr:
		for j in i:
			s += j
			s += " "
	return s
