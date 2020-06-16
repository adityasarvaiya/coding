from crio.ds.Tree.TreeNode import TreeNode
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
def countPaths(root, curr, k):
    if not root:
        return 0
    if not root.left and not root.right:
        curr += root.val
        return int(curr == k)

    leftCount = countPaths(root.left, curr + root.val, k)
    rightCount = countPaths(root.right, curr + root.val, k)

    return leftCount + rightCount
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
'''
# Definition of TreeNode
class TreeNode:
	def __init__(self, val):
		self.val = val
		self.left = None
		self.right = None
'''
def pathsWithSumRootToLeaf(root, k):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    return countPaths(root, 0, k)
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
