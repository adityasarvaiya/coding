import sys
from Solution import minimalTree
from crio.ds.Tree.TreeNode import *

# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def isValidBST(root, low=-10**9, high=10**9):
    if root == None:
        return True
    if root.val < low or root.val > high:
        return False
    return isValidBST(root.left, low, root.val) and isValidBST(root.right, root.val, high)

def getTreeHeight(root):
    if root == None:
        return 0
    return max(1 + getTreeHeight(root.left),1 + getTreeHeight(root.right))

def getInorderFromTree(root, inorder):
    if root == None:
        return
    getInorderFromTree(root.left, inorder)
    inorder.append(root.val)
    getInorderFromTree(root.right, inorder)


def main():
    n = int(sys.stdin.readline())
    arr = list(map(int, sys.stdin.readline().strip().split()))
    root = minimalTree(arr)
    result = getTreeHeight(root)
    inorder = []
    getInorderFromTree(root, inorder)
    if inorder != arr:
        result = -1
    if not isValidBST(root):
       result = -1

    print(result)

if __name__ == '__main__':
    sys.setrecursionlimit(100000)
    main()
