
'''
# Definition of TreeNode
class TreeNode:
	def __init__(self, val):
		self.val = val
		self.left = None
		self.right = None
'''

# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
from collections import deque

def dfs(results, node, level):
    if level >= len(results):
        results.append(deque([node.val]))
    else:
        if level % 2 == 0:
            results[level].append(node.val)
        else:
            results[level].appendleft(node.val)

    for next_node in [node.left, node.right]:
        if next_node is not None:
            dfs(results, next_node, level+1)
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def zigzagLevelOrder(root):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    results = list()
    if root is None:
        return results

    dfs(results,root, 0)
    return results
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
