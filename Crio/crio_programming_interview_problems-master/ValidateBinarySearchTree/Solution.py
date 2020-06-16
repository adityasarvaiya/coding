from crio.ds.Tree.TreeNode import TreeNode

# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
def validateBST(root, mn, mx):
    if not root:
        return True
    if root.val > mx or root.val < mn:
        return False
    
    leftCheck = validateBST(root.left, mn, root.val)
    rightCheck = validateBST(root.right, root.val, mx)
    return leftCheck and rightCheck
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
'''
# Definition of TreeNode
class TreeNode:
	def __init__(self, val):
		self.val = val
		self.left = None
		self.right = None
'''
def validateBinarySearchTree(root):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    return validateBST(root, -10**9, 10**9)
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
