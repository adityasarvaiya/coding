from Solution import populatingNextRightPointersInEachNode
from crio.ds.Tree.TreeNode import *
from queue import Queue

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

    return nodes[0], nodes

def getNextPointersString(root):
    queue = Queue()
    queue.put(root)
    nextPointers = []
    while queue.qsize() > 0:
        curr = queue.get()
        if curr.next:
            nextPointers.append(curr.next.val)
        else:
            nextPointers.append('null')
        if curr.left:
            queue.put(curr.left)
        if curr.right:
            queue.put(curr.right)
    return nextPointers

if __name__ == '__main__':
    testCases = int(input())
    for _t in range(testCases):
        n = int(input())
        val = list(map(int, input().strip().split()))
        edges = []
        for i in range(n):
            edges.append(list(map(int, input().strip().split())))

        root, nodes = getTreeFromInput(n, val, edges)

        result = populatingNextRightPointersInEachNode(root)

        nextPointers = getNextPointersString(result)
        print(*nextPointers)
        