from crio.io import PrintMatrix
from crio.ds.Tree import TreeNode

def levelOrder(root):
    answer = []
    # TODO: CRIO_TASK_MODULE_L2_PROBLEMS
    # Your implementation goes here

    return answer

if __name__ == '__main__':
    n = int(input())
    tree = input().split()
    root = None
    root = TreeNode.makeTreeFromArray(0, tree, root)
    result = levelOrder(root)
    PrintMatrix.TwoDMatrix(result)
