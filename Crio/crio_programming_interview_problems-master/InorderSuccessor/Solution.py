from crio.ds.Tree.TreeNode import TreeNode

'''
# Definition for TreeNode
class TreeNode:
	def __init__(self, val):
		self.val = val
		self.left = None
		self.right = None
'''
def inorderSuccessor(root, node):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    if not root:
        return None

    if node.right:
        node = node.right
        while node.left:
            node = node.left
        return node
    
    result = [None]
    
    while root and root != node:
        if root.val > node.val:
            result.append(root)
            root = root.left
        else:
            root = root.right
    
    return result[-1]
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
