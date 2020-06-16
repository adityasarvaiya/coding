#include <bits/stdc++.h>
#include "Solution.cpp"
using namespace std;

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

int main() {
    
    int n, target;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0 ; i < n ; i++) {
        cin >> nums[i];
    }
    int q;
    cin >> q;
    for(int i = 0 ;i < q ; i++) {
        int target;
        cin >> target;
        vector<int> result = Solution().searchRange(nums,target);
        cout << result[0] << " " << result[1] << "\n";
    }
    return 0;
}
