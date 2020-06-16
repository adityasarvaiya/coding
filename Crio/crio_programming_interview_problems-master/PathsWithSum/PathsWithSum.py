from crio.ds.Tree.TreeNode import readTreeReturnRoot
from Solution import *

# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    root = readTreeReturnRoot()
    k = int(input())
    print(count_paths_that_adds_to_given_sum(root, k))

if __name__ == '__main__':
    import sys
    sys.setrecursionlimit(100000)
    main()

