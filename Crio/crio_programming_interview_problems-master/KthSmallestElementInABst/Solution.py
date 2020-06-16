from crio.ds.Tree.TreeNode import TreeNode
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
def getInorder(root, inorder):
    if not root:
        return
    getInorder(root.left, inorder)
    inorder.append(root.val)
    getInorder(root.right, inorder)
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
'''
# Definition of TreeNode
class TreeNode:
	def __init__(self, val):
		self.val = val
		self.left = None
		self.right = None
'''
def kthSmallest(root, k):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    inorder = []
    getInorder(root, inorder)
    return inorder[k-1]
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS