from Solution import commonAncestor
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

def getNode(root, val):
    if not root:
        return None
    if root.val == val:
        return root
    left = getNode(root.left, val)
    if left:
        return left
    return getNode(root.right, val)

if __name__ == '__main__':
    import sys
    sys.setrecursionlimit(100000)

    testCases = int(input())
    for _t in range(testCases):
        n = int(input())
        val = list(map(int, input().strip().split()))
        assert(sorted(list(set(val))) == sorted(val))

        edges = []
        for i in range(n):
            edges.append(list(map(int, input().strip().split())))
        pVal, qVal = map(int, input().split())

        root = getTreeFromInput(n, val, edges)
        
        p = getNode(root, pVal)
        q = getNode(root, qVal)

        assert p and q

        result = commonAncestor(root, p, q)
        print(result.val)