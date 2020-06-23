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
class BinaryTreeZigzagLevelOrderTraversal {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        vector<vector<int>> answer;
        queue<TreeNode*> q;
        if (root == NULL)
            return answer;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            vector<int> atThisLevel;
            int size = q.size();
            while (size > 0) {
                size--;
                TreeNode* temp = q.front();
                q.pop();
                if (temp->left != NULL) {
                    q.push(temp->left);
                }
                if (temp->right != NULL) {
                    q.push(temp->right);
                }
                atThisLevel.push_back(temp->val);
            }
            level++;
            if (level % 2 == 0) {
                reverse(atThisLevel.begin(), atThisLevel.end());
            }
            answer.push_back(atThisLevel);
        }
        return answer;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
};