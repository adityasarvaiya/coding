class TreeNode:
	def __init__(self, val):
		self.val = val
		self.left = None
		self.right = None
		self.next = None

def constructBinaryTreeFromPreorderAndInorderTraversal(preorder, inorder):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    if len(preorder)==0:
        return None
    root = TreeNode(preorder[0])
    middle = inorder.index(preorder[0])
    root.left = constructBinaryTreeFromPreorderAndInorderTraversal(preorder[1:middle+1],inorder[:middle])
    root.right = constructBinaryTreeFromPreorderAndInorderTraversal(preorder[middle+1:],inorder[middle+1:])
    return root
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS