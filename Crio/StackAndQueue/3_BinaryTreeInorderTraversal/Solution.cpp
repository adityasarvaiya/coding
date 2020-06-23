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
class BinaryTreeInorderTraversal {
public:
    //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    void dfs(TreeNode* vertex, vector<int>& inOrder) {
        if (vertex == NULL) {
            return;
        }
        dfs(vertex->left, inOrder);
        inOrder.push_back(vertex->val);
        dfs(vertex->right, inOrder);
    }
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

    vector<int> inorderTraversal(TreeNode* root) {
        //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        vector<int> inOrder;
        dfs(root, inOrder);
        return inOrder;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
};