from crio.ds.Tree import TreeNode

def maxDepth(root):
    # TODO: CRIO_TASK_MODULE_L1_PROBLEMS
    # Your implementation goes here

    return 0

if __name__ == '__main__':
    tree = input().split()
    root = None
    root = TreeNode.makeTreeFromArray(0, tree, root)
    result = maxDepth(root)
    print(result)
