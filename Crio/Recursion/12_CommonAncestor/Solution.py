from crio.ds.Tree.TreeNode import TreeNode

'''
# Definition of TreeNode
class TreeNode:
	def __init__(self, val):
		self.val = val
		self.left = None
		self.right = None
'''
def commonAncestor(root, p, q):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    if not root:
        return None

    if root.val == p.val or root.val == q.val:
        return root

    l = commonAncestor(root.left, p, q)
    r = commonAncestor(root.right , p, q)

    if l and r:
        return root

    if l:
        return l

    if r:
        return r

    return None
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS% 