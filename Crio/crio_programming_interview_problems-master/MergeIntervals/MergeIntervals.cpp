#include <bits/stdc++.h>
#include "../crio/cpp/io/PrintMatrix.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"

using namespace std;

class MergeIntervals {
  public:
    vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        vector<vector<int>> res;
        if (intervals.empty())
            return intervals;
        sort(intervals.begin(), intervals.end(),
             [](const auto& a, const auto& b) { return b[0] > a[0]; });
        int i = 0;

        while (i < int(intervals.size()) - 1) {
            if (intervals[i][1] >= intervals[i + 1][0]) {
                intervals[i + 1][0] = intervals[i][0];
                intervals[i + 1][1] = max(intervals[i][1], intervals[i + 1][1]);
            } else {
                res.push_back(intervals[i]);
            }
            i++;
        }
        res.push_back(intervals[i]);
        return res;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> nums;
    ReadMatrix<int>().TwoDMatrix(n, 2, nums);
    vector<vector<int>> result = MergeIntervals().mergeIntervals(nums);
    PrintMatrix<int>().TwoDMatrix(result);
    return 0;
}
