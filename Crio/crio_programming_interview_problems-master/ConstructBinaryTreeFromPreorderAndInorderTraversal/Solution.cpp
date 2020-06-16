#include "../crio/cpp/ds/TreeNode/TreeNode.hpp"

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
TreeNode* construct(int start, int end, vector<int> const &preorder,
				int &pIndex, unordered_map<int,int> &map)
{
	if (start > end)
		return NULL;

	TreeNode *root = new TreeNode(preorder[pIndex++]);

	int index = map[root->val];

	root->left = construct(start, index - 1, preorder, pIndex, map);

	root->right = construct(index + 1, end, preorder, pIndex, map);

	return root;
}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

/*
// Definition of TreeNode
class TreeNode {
public:
    long val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() {}

    TreeNode (long x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};
*/
TreeNode* constructBinaryTreeFromPreorderAndInorderTraversal(vector<int> &preorder, vector<int> &inorder) {
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	int n = inorder.size();

	unordered_map<int,int> map;
	for (int i = 0; i < n; i++)
		map[inorder[i]] = i;

	int pIndex = 0;

	return construct(0, n - 1, preorder, pIndex, map);
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
