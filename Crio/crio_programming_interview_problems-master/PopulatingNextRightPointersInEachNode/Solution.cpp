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

class PopulatingNextRightPointersInEachNode {
public:
    TreeNode* populatingNextRightPointersInEachNode(TreeNode* root ) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        if ( root == NULL) return NULL;
        queue <TreeNode*> Q ;
        Q.push(root);
        while (!Q.empty()) {
            int size = Q.size();
            for ( int i = 0; i < size; i++) {
                TreeNode *node = Q.front();
                Q.pop();
                if (node->left != NULL) {
                    Q.push(node->left);
                }
                if (node->right != NULL) {
                    Q.push(node->right);
                }
                if (i < size - 1) {
                    node->next = Q.front();
                }
                else {
                    node->next = NULL;
                }
            }
        }
        return root;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
};
