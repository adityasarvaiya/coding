from crio.ds.Tree.TreeNode import TreeNode

# CRIO_SOLUTION_START_MODULE_TREE_PATH_SUM
def mergeChildPathSums(leftPaths, rightPaths, root):
    currPaths = [root.val]
    for value in leftPaths:
        currPaths.append(value + root.val)
    
    for value in rightPaths:
        currPaths.append(value + root.val)
    
    return currPaths

def countPaths(root, k):
    if not root:
        return 0, []
    
    leftCount, leftPaths = countPaths(root.left, k)
    rightCount, rightPaths = countPaths(root.right, k)
    
    currCount = leftCount + rightCount

    for leftSum in leftPaths:
        for rightSum in rightPaths:
            if (leftSum + rightSum + root.val) == k:
                currCount += 1

    currPaths = mergeChildPathSums(leftPaths, rightPaths, root)

    for pathSum in currPaths:
        if pathSum == k:
            currCount += 1

    return currCount, currPaths
# CRIO_SOLUTION_END_MODULE_TREE_PATH_SUM

def countTreePathsThatSumsToK(root, k):
# CRIO_SOLUTION_START_MODULE_TREE_PATH_SUM
    return countPaths(root, k)[0]
# CRIO_SOLUTION_END_MODULE_TREE_PATH_SUM

    
