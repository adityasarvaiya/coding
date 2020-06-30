from crio.ds.Tree.TreeNode import TreeNode
'''
# Definition for TreeNode
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
'''
def minimalTree(arr):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    if len(arr) == 0:
        return None
    
    if len(arr) == 1:
        return TreeNode(arr[0])
    
    mid = len(arr) // 2
    root = TreeNode(arr[mid])
    left = minimalTree(arr[:mid])
    right = minimalTree(arr[mid+1:])
    root.left = left
    root.right = right
    return root
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
