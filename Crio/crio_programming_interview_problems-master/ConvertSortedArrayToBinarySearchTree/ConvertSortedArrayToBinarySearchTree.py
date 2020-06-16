from crio.ds.Tree import TreeNode

def sortedArrayToBST(nums):
    # TODO: CRIO_TASK_MODULE_L1_PROBLEMS
    # Your implementation goes here

    return None

if __name__ == '__main__':
    n = int(input())
    nums = input().split()
    nums = [int(i) for i in nums]
    root = sortedArrayToBST(nums)
    result = TreeNode.treeNodeToString(root)
    print(result)
