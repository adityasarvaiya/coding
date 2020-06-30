#include "../crio/cpp/ds/TreeNode/TreeNode.hpp"

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
void fun(TreeNode* root, vector<int>& arr) {
    if (root == NULL)
        return;
    fun(root->left, arr);
    arr.push_back(root->val);
    fun(root->right, arr);
}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

/*
// Definition for TreeNode
class TreeNode {
public:
    long val;
    TreeNode* left;
    TreeNode* right;
    TreeNode (long x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};
*/
int kthSmallestElementInABst(TreeNode* root, int k) {
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    vector<int> arr;
    fun(root, arr);
    return arr[k - 1];
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
