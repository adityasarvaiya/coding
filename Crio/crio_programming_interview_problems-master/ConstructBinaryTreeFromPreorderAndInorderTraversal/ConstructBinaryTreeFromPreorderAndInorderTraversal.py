from Solution import constructBinaryTreeFromPreorderAndInorderTraversal

# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
import sys
sys.setrecursionlimit(100000)

def makePreOrderFromTree(root):
	preOrder = list()
	if root == None:
		return preOrder
	
	preOrder.extend([root.val])
	preOrder.extend(makePreOrderFromTree(root.left))
	preOrder.extend(makePreOrderFromTree(root.right))
	return preOrder

def makeInOrderFromTree(root):
	inOrder = list()
	if root == None:
		return inOrder
	
	inOrder.extend(makeInOrderFromTree(root.left))
	inOrder.extend([root.val])
	inOrder.extend(makeInOrderFromTree(root.right))
	return inOrder

if __name__ == '__main__':
    n = int(input())
    preorder = list(map(int, input().strip().split()))
    inorder = list(map(int, input().strip().split()))

    result = constructBinaryTreeFromPreorderAndInorderTraversal(preorder, inorder)

    preOrder = makePreOrderFromTree(result)
    print(*preOrder)

    inOrder = makeInOrderFromTree(result)
    print(*inOrder)
