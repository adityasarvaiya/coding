#include <bits/stdc++.h>
#include "FastIO.hpp"
#include "ReadMatrix.hpp"

using namespace std;

class MaximumSubArray {
    public:
        int maxSubArray(vector<int>& nums) {
            int ans = 0;
            // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
            int n=nums.size();
            if(n==0) return 0;
            if(n==1) return  nums[0];
            int dp[n];
            dp[0]=nums[0];
            ans=dp[0];
            for(int i=1;i<n;i++)
            {
                int x=dp[i-1]+nums[i];
                dp[i]=max(nums[i],x);
                ans=max(ans,dp[i]);
            }
            // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
            return ans;
        }
};

int main() {
    FastIO();
    int n;
    cin >> n;
    vector<int> nums;
    ReadMatrix<int>().OneDMatrix(n, nums);
    int result = MaximumSubArray().maxSubArray(nums);
    cout << result;
    return 0;
}
