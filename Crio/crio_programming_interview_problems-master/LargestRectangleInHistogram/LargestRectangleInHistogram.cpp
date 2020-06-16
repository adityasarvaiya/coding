#include "FastIO.hpp"
#include "ReadMatrix.hpp"
#include <bits/stdc++.h>
using namespace std;

class LargestRectangleInHistogram {
  public:
    int largestRectangleArea(vector<int> heights) {
        int ans = 0;
        // TODO: CRIO_TASK_MODULE_L3_PROBLEMS
        // Your implementation goes here
        // CRIO_SOLUTION_START_MODULE_L3_PROBLEMS
        int n = heights.size();
        if (n == 0) {
            return 0;
        }

        for (int i = 0; i < (int) heights.size(); i++) {
            int t = heights[i], left = i - 1, right = i + 1;
            while (left >= 0 && heights[left] >= t) {
                left--;
            }
            while (right < (int) heights.size() && heights[right] >= t) {
                right++;
            }
            ans = max(ans, t * (right - left - 1));
        }
        // CRIO_SOLUTION_END_MODULE_L3_PROBLEMS
        return ans;
    }
};

int main() {
    FastIO();
    int n;
    cin >> n;
    vector<int> heights;
    ReadMatrix<int>().OneDMatrix(n, heights);
    int result = LargestRectangleInHistogram().largestRectangleArea(heights);
    cout << result;
    return 0;
}
