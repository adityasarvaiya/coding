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
class CheckBalanced {
public:
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    bool isBalanced(TreeNode *root,int* height) {
        int lh = 0, rh = 0; 
        int l = 0, r = 0; 
        if (root == NULL) { 
            *height = 0; 
            return true; 
        } 
        l = isBalanced(root->left, &lh); 
        r = isBalanced(root->right, &rh); 
        *height = (lh > rh ? lh : rh) + 1; 
        if (abs(lh-rh)>1) 
            return false; 
        else
            return l && r;
    }
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    bool checkBalanced(TreeNode *root)
    {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int height =0;
        return isBalanced(root,&height);
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
};
