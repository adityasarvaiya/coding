#include <bits/stdc++.h>
using namespace std;

class FirstMissingPositive {
  public:
    int firstMissingPositive(vector<int> nums) {
        int res = 0;
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        map<int, int> positiveIntegers;
        for (int i = 0; i < int(nums.size()); ++i) {
            if (nums[i] > 0) {
                positiveIntegers[nums[i]] = 1;
            }
        }
        res = 1;
        while (positiveIntegers[res] == 1) {
            res++;
        }
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    int result = FirstMissingPositive().firstMissingPositive(nums);
    cout << result;
    return 0;
}
