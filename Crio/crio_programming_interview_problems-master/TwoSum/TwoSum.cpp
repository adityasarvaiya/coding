#include <bits/stdc++.h>
#include "FastIO.hpp"
#include "ReadMatrix.hpp"
#include "PrintMatrix.hpp"

using namespace std;

class TwoSum {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> v(2,0);
            // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
            map<int,int> mp;
            int n = nums.size();
            for(int i = 0; i < n; i++) {
                int x = target - nums[i];
                auto itr = mp.find(x);
                if(itr != mp.end()) {
                    v[0] = itr->second;
                    v[1] = i;
                    return v;
                }
                mp[nums[i]] = i;
            }
            // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
            return v;
        }
};

int main() {
    FastIO();
    int n, target;
    cin >> n;
    vector<int> nums;
    ReadMatrix<int>().OneDMatrix(n, nums);
    cin >> target;
    vector<int> result = TwoSum().twoSum(nums, target);
    PrintMatrix<int>().OneDMatrix(result, " ");
    return 0;
}
