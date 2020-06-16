#include "FastIO.hpp"
#include "ReadMatrix.hpp"
#include <bits/stdc++.h>
using namespace std;

class FindPeakElement {
  public:
    int findPeakElement(vector<int>& nums) {
        // TODO: CRIO_TASK_MODULE_L2_PROBLEMS
        // Your implementation goes here
        // CRIO_SOLUTION_START_MODULE_L2_PROBLEMS
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[mid + 1])
                r = mid;
            else
                l = mid + 1;
        }
        return l;
        // CRIO_SOLUTION_END_MODULE_L2_PROBLEMS
    }
};

int main() {
    FastIO();
    int n;
    cin >> n;
    vector<int> nums;
    ReadMatrix<int>().OneDMatrix(n, nums);
    int result = FindPeakElement().findPeakElement(nums);
    cout << result;
    return 0;
}