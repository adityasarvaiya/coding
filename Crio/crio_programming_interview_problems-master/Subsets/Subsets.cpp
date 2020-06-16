#include "FastIO.hpp"
#include "PrintMatrix.hpp"
#include "ReadMatrix.hpp"
#include <bits/stdc++.h>
using namespace std;

class Subsets {
  public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        // TODO: CRIO_TASK_MODULE_L2_PROBLEMS
        // Your implementation goes here
        // CRIO_SOLUTION_START_MODULE_L2_PROBLEMS
        cout << pow(2, int(nums.size())) << "\n";
        res.push_back({});
        for (int i = 0; i < int(nums.size()); i++) {
            int x = res.size();
            for (int j = 0; j < x; j++) {
                vector<int> temp = res[j];
                temp.push_back(nums[i]);
                res.push_back(temp);
            }
        }
        // CRIO_SOLUTION_END_MODULE_L2_PROBLEMS
        return res;
    }
};

int main() {
    FastIO();
    int n;
    cin >> n;
    vector<int> nums;
    ReadMatrix<int>().OneDMatrix(n, nums);
    vector<vector<int>> result = Subsets().subsets(nums);
    PrintMatrix<int>().TwoDMatrix(result);
    return 0;
}
