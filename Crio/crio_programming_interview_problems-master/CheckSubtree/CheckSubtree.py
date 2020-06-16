from crio.ds.Tree.TreeNode import readTreeReturnRoot
from Solution import *

# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    testCases = int(input())
    for _t in range(testCases):
        root = readTreeReturnRoot()
        root2 = readTreeReturnRoot()
        if check_subtree(root, root2): 
           print("Yes")
        else: 
           print("No")

if __name__ == '__main__':
    import sys
    sys.setrecursionlimit(10 * 1000)
    main()

