from crio.ds.Tree.TreeNode import TreeNode

# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
def getLevelOrder(root, level, levelOrder):
    if not root:
        return
    levelOrder[level].append(root)
    getLevelOrder(root.left, level+1, levelOrder)
    getLevelOrder(root.right, level+1, levelOrder)
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

'''
# Definition of TreeNode
class TreeNode:
	def __init__(self, val):
		self.val = val
		self.left = None
		self.right = None
        self.next = None
'''
def populatingNextRightPointersInEachNode(root):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    levelOrder = [[] for i in range(20)]

    getLevelOrder(root, 0, levelOrder)
    for level in levelOrder:
        for i in range(len(level)-1):
            level[i].next = level[i+1]

    return root
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
