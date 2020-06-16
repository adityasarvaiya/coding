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
def tree_compare(large_tree, small_tree):
    if large_tree != None and small_tree != None:
        return large_tree.val == small_tree.val and tree_compare(large_tree.left, small_tree.left) and tree_compare(large_tree.right, small_tree.right)
    else:
       return large_tree == small_tree

size_dict = {
    None : 0
}

def tree_size(tree):
    if tree == None:
       return 0

    if tree not in size_dict:
       size_dict[tree] = 1 + tree_size(tree.left) + tree_size(tree.right)

    return size_dict[tree]

def is_subtree(large_tree, small_tree, small_tree_sz):

    large_tree_sz = size_dict[large_tree]
    
    if large_tree_sz == small_tree_sz:
       return tree_compare(large_tree, small_tree)
   
    elif large_tree_sz > small_tree_sz:
       return is_subtree(large_tree.left, small_tree, small_tree_sz) or is_subtree(large_tree.right, small_tree, small_tree_sz) 
    else:
       return False
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def check_subtree(large_tree, small_tree):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    tree_size(large_tree)
    return is_subtree(large_tree, small_tree, tree_size(small_tree))
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
