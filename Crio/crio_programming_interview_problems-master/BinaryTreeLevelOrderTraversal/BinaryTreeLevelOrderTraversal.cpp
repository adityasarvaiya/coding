#include "FastIO.hpp"
#include "PrintMatrix.hpp"
#include "ReadMatrix.hpp"
#include "TreeNode.hpp"
#include <bits/stdc++.h>
using namespace std;

/*
//Definition of TreeNode
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

class BinaryTreeLevelOrderTraversal {
  public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        // TODO: CRIO_TASK_MODULE_L2_PROBLEMS
        // Your implementation goes here
        // CRIO_SOLUTION_START_MODULE_L2_PROBLEMS
        queue<TreeNode*> q;
        if (root == NULL)
            return answer;
        q.push(root);
        vector<int> atThisLevel;
        while (!q.empty()) {
            atThisLevel.clear();
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
            answer.push_back(atThisLevel);
        }
        // CRIO_SOLUTION_END_MODULE_L2_PROBLEMS
        return answer;
    }
};

int main() {
    FastIO();
    int n;
    cin >> n;
    vector<string> tree;
    ReadMatrix<string>().OneDMatrix(n, tree);
    TreeNode* root = NULL;
    root = TreeNode().makeTreeFromArray(0, tree, root);
    vector<vector<int>> result =
        BinaryTreeLevelOrderTraversal().levelOrder(root);
    PrintMatrix<int>().TwoDMatrix(result);
    return 0;
}
