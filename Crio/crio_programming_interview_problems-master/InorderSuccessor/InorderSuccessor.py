from crio.ds.Tree.TreeNode import TreeNode,readTreeReturnAllNodes,isValidBST
from Solution import inorderSuccessor

# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    nodes = readTreeReturnAllNodes()
    root = nodes[0]
    assert(isValidBST(root))
    q = int(input())
    for _q in range(q):
        idx = int(input())
        node = nodes[idx]
        result = inorderSuccessor(root, node)
        if result:
            print(result.val)
        else:
            print(-1)

if __name__ == '__main__':
    import sys
    sys.setrecursionlimit(10 * 1000)
    main()
