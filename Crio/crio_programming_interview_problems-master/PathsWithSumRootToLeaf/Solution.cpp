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

class Solution {
public:
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    long long result;
    Solution() {
        result = 0;
    }
    void countPaths(TreeNode* cur, long long sum, long long k) {
        if(cur && cur->left==NULL && cur->right == NULL) {
            if((cur->val + sum) == k)
                result++;
        }
        else if(cur) {
            countPaths(cur->left, (sum + cur->val) , k);
            countPaths(cur->right, (sum + cur->val) , k );
        }
    }
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

    long long pathsWithSumRootToLeaf(TreeNode* root, long long k) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        countPaths(root,0,k);
        return result;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
};
