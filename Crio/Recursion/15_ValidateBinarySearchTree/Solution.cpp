/*
// Definition for TreeNode
class TreeNode {
public:
    long val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* next;
    TreeNode (long x) {
        val = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
*/
class ValidateBinarySearchTree {
public:
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    bool util(TreeNode * root ,  long long min ,   long long max) {
        if ( root == NULL) return 1;


        if ( root->val >= max || root->val <= min)
            return 0;
        if ( root->left != NULL && !(util(root->left, min , root->val ))) {
            return 0;
        }
        if ( root->right != NULL && !(util(root->right, root->val , max))) {
            return 0;
        }

        return 1;
    }
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    bool validateBinarySearchTree(TreeNode* root) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS

        long long min = -1e10 - 2 ;
        long long max = 1e10 + 2 ;
        bool flag = util(root, min, max);
        return flag;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
};
