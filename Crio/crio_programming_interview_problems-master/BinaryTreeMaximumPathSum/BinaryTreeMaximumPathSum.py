from crio.ds.Tree import TreeNode

def maxPathSum(root):
    # TODO: CRIO_TASK_MODULE_L2_PROBLEMS
    # Your implementation goes here

    return 0

if __name__ == '__main__':
    n = int(input())
    tree = input().split()
    root = None
    root = TreeNode.makeTreeFromArray(0, tree, root)
    result = maxPathSum(root)
    print(result)
