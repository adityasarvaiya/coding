class Solution {
public:
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    unordered_map<long long,long long> prefSum;
    long long result;
    Solution() {
        result = 0;
    }
    void countPaths(TreeNode* cur, long long k, long long sum) {
        if(cur) {
            if((cur->val + sum) == k) {
                result++;
            }     
            result += prefSum[sum + cur->val - k];

            prefSum[sum + cur->val]++;
            countPaths(cur->left, k , sum + cur->val);
            countPaths(cur->right, k , sum + cur->val);
            prefSum[sum + cur->val]--;
        }
    }
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

    long long pathsWithSum(TreeNode* root, long long k) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        countPaths(root, k, 0);
        return result;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
};
