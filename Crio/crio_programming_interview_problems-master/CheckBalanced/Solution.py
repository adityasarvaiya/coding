from crio.ds.Tree.TreeNode import *
'''
# Definition for TreeNode
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
'''
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS

depth_dict = {

}

def depth(tree):
    if tree == None:
        return 0
    if tree not in depth_dict:
        depth_dict[tree] = 1 + max(depth(tree.left), depth(tree.right))

    return depth_dict[tree]

# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def check_balanced(tree):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS

    if tree == None:
        return True
    
    left_tree_depth = depth(tree.left)
    right_tree_depth = depth(tree.right)

    return (abs(left_tree_depth - right_tree_depth) < 2) and check_balanced(tree.left) and check_balanced(tree.right)
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

