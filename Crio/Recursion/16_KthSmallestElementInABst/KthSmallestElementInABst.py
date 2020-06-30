from Solution import *
from crio.ds.Tree.TreeNode import *

# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def getTreeFromInput(n, val, edges):
    nodes = []
    for i in range(n):
        nodes.append(TreeNode(val[i]))

    for edge in edges:
        parentIdx, leftChildIdx, rightChildIdx = edge

        if leftChildIdx >= 0:
            nodes[parentIdx-1].left = nodes[leftChildIdx-1]
        
        if rightChildIdx >= 0:
            nodes[parentIdx-1].right = nodes[rightChildIdx-1]

    return nodes[0]

if __name__ == '__main__':
    import sys
    sys.setrecursionlimit(15000)

    n = int(input())
    val = list(map(int, input().strip().split()))
    edges = []
    for i in range(n):
        edges.append(list(map(int, input().strip().split())))
    k = int(input())

    root = getTreeFromInput(n, val, edges)
    result = kthSmallestElementInABst(root, k)
    print(result)
    