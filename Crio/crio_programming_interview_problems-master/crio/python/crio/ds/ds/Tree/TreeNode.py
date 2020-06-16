from queue import Queue
# CRIO_SOLUTION_AND_STUB_START_MODULE_L1_PROBLEMS
# CRIO_SOLUTION_AND_STUB_END_MODULE_L1_PROBLEMS

class TreeNode:
	def __init__(self, val):
		self.val = val
		self.left = None
		self.right = None
		self.next = None

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
