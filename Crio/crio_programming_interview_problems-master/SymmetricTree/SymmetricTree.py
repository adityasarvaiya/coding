from crio.ds.Tree import TreeNode

def isSymmetric(root):
    # TODO: CRIO_TASK_MODULE_L1_PROBLEMS
    # Your implementation goes here

    return True

if __name__ == '__main__':
    tree = input().split()
    root = None
    root = TreeNode.makeTreeFromArray(0, tree, root)
    result = isSymmetric(root)
    if result:
        print('true')
    else:
        print('false')
