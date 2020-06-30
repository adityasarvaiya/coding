// Definition for TreeNode
/*
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

class CommonAncestor {
public:
    TreeNode* commonAncestor(TreeNode* root, TreeNode * p , TreeNode* q) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        if ( root == NULL) return NULL;
        if (root->val == p->val ||  root->val == q->val) return root;

        TreeNode *l = commonAncestor(root->left, p, q);
        TreeNode *r = commonAncestor(root->right , p, q);
        if (l != NULL && r != NULL) return root;
        if ( l != NULL) return l;
        else if (r != NULL) return r;
        return NULL;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
};
