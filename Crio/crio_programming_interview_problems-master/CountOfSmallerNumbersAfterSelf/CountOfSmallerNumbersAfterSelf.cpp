#include<bits/stdc++.h>
#include "Solution.cpp"
using namespace std;
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
int main() {
    int n;
    cin >> n;
    vector<int>nums(n);
    for(int i = 0 ; i < n ; i++) {
        cin >> nums[i];
    }
    Solution answer;
    vector<int> result = answer.countSmaller(nums);
    for(int i = 0 ; i < result.size() ; i++) {
        cout << result[i] <<" ";
    }
}
