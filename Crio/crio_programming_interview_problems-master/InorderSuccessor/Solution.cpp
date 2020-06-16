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
class Solution {
    public:
        TreeNode * inOrderSuccessor(TreeNode *root, TreeNode *givenNode) 
        {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
            if (givenNode->right != NULL) {
                givenNode = givenNode->right;
                while (givenNode->left != NULL)
                    givenNode = givenNode->left;
                return givenNode;
            }
            stack< TreeNode* > st;
            int inorder = -1e9;
            while ( !st.empty() || root != NULL)
            {
                while(root != NULL)
                {
                    st.push(root);
                    root =root ->left; 
                }

                root = st.top();
                st.pop();
                if ( inorder == givenNode->val )
                    return root;
                inorder = root -> val;
                root = root -> right;
            }

        return NULL;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
        } 
};