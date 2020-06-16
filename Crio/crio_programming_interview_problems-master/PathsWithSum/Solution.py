from crio.ds.Tree.TreeNode import *

# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
def count_one_tree_with_sum(one_tree, tbl, sum_so_far, sum_expected):
    #print(tbl)
    if one_tree == None:
       return 0
       
    cnt = 0
    sum_so_far = sum_so_far + one_tree.val
    val = sum_so_far - sum_expected

    if val in tbl:
       cnt += tbl[val]
 
    #tbl = {**{}, **tbl}
    if sum_so_far not in tbl:
        tbl[sum_so_far] = 0

    tbl[sum_so_far] += 1 
    
    left_count = count_one_tree_with_sum(one_tree.left, tbl, sum_so_far, sum_expected)
    right_count = count_one_tree_with_sum(one_tree.right, tbl, sum_so_far, sum_expected)
    tbl[sum_so_far] -= 1
    return cnt + left_count + right_count
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
            
def count_paths_that_adds_to_given_sum(one_tree, sum_expected):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    if one_tree != None:
        tbl = {0 : 1}
        return count_one_tree_with_sum(one_tree, tbl, 0, sum_expected)
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    return 0
