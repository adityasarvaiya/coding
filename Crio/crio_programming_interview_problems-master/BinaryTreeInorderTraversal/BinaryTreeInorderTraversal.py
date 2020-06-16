from crio.io import PrintMatrix
from crio.ds.Tree.TreeNode import TreeNode, readTreeReturnRoot
from Solution import inorderTraversal 

# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS


def main():
    tests = int(input())
    for _ in range(tests):
        root  = readTreeReturnRoot()
        result = inorderTraversal(root)
        PrintMatrix.OneDMatrix(result, " ")
        print()

if __name__ == '__main__':
    import sys
    sys.setrecursionlimit(30 * 1000)
    main()
