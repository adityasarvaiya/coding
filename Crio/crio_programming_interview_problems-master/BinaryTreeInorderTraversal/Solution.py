'''
# Definition of TreeNode
class TreeNode:
	def __init__(self, val):
		self.val = val
		self.left = None
		self.right = None
'''

def inorderTraversal(root):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    current = root
    stack = list()
    values = list()
    while True:
        if current is not None:
            stack.append(current)
            current = current.left
        elif stack:
            current = stack.pop()
            values.append(current.val)
            current = current.right
        else:
            break
    return values
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
