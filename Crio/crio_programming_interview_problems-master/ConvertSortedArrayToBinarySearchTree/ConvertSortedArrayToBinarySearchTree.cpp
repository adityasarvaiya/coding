#include <bits/stdc++.h>
#include "FastIO.hpp"
#include "ReadMatrix.hpp"
#include "PrintMatrix.hpp"
#include "TreeNode.hpp"

using namespace std;

class ConvertSortedArrayToBinarySearchTree {
    public:
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        TreeNode* tree(vector<int>& nums, int l, int r) {
            if (l > r) return nullptr;
            int mid = (l + r) / 2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = tree(nums, l, mid - 1);
            root->right = tree(nums, mid + 1, r);
            return root;
        }
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

        TreeNode* sortedArrayToBST(vector<int>& nums) {
            // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
            return tree(nums,0,nums.size()-1);
            // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
        }
};

int main() {
    FastIO();
    int n;
    cin >> n;
    vector<int> nums;
    ReadMatrix<int>().OneDMatrix(n, nums);
    TreeNode* root = ConvertSortedArrayToBinarySearchTree().sortedArrayToBST(nums);
    string result = TreeNode().treeNodeToString(root);
    cout << result;
    return 0;
}
