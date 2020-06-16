from crio.ds.Tree.TreeNode import *
from Solution import countTreePathsThatSumsToK

# CRIO_SOLUTION_START_MODULE_TREE_PATH_SUM
# CRIO_SOLUTION_END_MODULE_TREE_PATH_SUM


# CRIO_SOLUTION_START_MODULE_TREE_PATH_SUM_WITH_BREAKDOWN
def test():
    assert True
# CRIO_SOLUTION_END_MODULE_TREE_PATH_SUM_WITH_BREAKDOWN


def main():

# CRIO_SOLUTION_START_MODULE_TREE_PATH_SUM_WITH_BREAKDOWN
    test()
# CRIO_SOLUTION_END_MODULE_TREE_PATH_SUM_WITH_BREAKDOWN

    root = readTreeReturnRoot()
    k = int(input())
    print(countTreePathsThatSumsToK(root, k))

if __name__ == '__main__':
    import sys
    sys.setrecursionlimit(100000)
    main()
