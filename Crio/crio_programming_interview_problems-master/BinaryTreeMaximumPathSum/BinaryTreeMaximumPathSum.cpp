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

class BinaryTreeMaximumPathSum {
    // TODO: CRIO_TASK_MODULE_L2_PROBLEMS
    // Your implementation goes here
    // CRIO_SOLUTION_START_MODULE_L2_PROBLEMS
    // long answer;
  public:
    long maxSum(TreeNode* root) {
        if (root == NULL)
            return 0;

        long maxSumLeft = maxSum(root->left);
        long maxSumRight = maxSum(root->right);
        long maxWithNode = root->val;

        if (maxWithNode < root->val + maxSumLeft)
            maxWithNode = root->val + maxSumLeft;

        if (maxWithNode < root->val + maxSumRight)
            maxWithNode = root->val + maxSumRight;

        // if(answer < maxWithNode)
        //   answer = maxWithNode;

        if (maxWithNode < maxSumLeft + maxSumRight + root->val)
            maxWithNode = maxSumLeft + maxSumRight + root->val;

        return maxWithNode;
    }
    // CRIO_SOLUTION_END_MODULE_L2_PROBLEMS

    long maxPathSum(TreeNode* root) {
        // TODO: CRIO_TASK_MODULE_L2_PROBLEMS
        // Your implementation goes here
        // CRIO_SOLUTION_START_MODULE_L2_PROBLEMS
        // answer = root->val;
        long answer = maxSum(root);
        return answer;
        // CRIO_SOLUTION_END_MODULE_L2_PROBLEMS

        // CRIO_UNCOMMENT_START_MODULE_L2_PROBLEMS
        // return 0;
        // CRIO_UNCOMMENT_END_MODULE_L2_PROBLEMS
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
    long result = BinaryTreeMaximumPathSum().maxPathSum(root);
    cout << result;
    return 0;
}
