#include "FastIO.hpp"
#include "ReadMatrix.hpp"
#include <bits/stdc++.h>
using namespace std;

class FindTheDuplicateNumber {
  public:
    int findDuplicate(vector<int> nums) {
        int ans = 0;
        // TODO: CRIO_TASK_MODULE_L2_PROBLEMS
        // Your implementation goes here
        // CRIO_SOLUTION_START_MODULE_L2_PROBLEMS
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                ans = nums[i];
            }
        }
        // CRIO_SOLUTION_END_MODULE_L2_PROBLEMS
        return ans;
    }
};

int main() {
    FastIO();
    int n;
    cin >> n;
    vector<int> nums;
    ReadMatrix<int>().OneDMatrix(n + 1, nums);
    int result = FindTheDuplicateNumber().findDuplicate(nums);
    cout << result;
    return 0;
}
