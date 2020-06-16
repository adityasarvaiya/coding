#include "../crio/cpp/io/PrintMatrix.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
#include <bits/stdc++.h>
using namespace std;

class SortColors {
  public:
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    void swap(int i, int j, vector<int>& nums) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

    void sortColors(vector<int>& nums) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int n = nums.size();
        int start = 0, end = n - 1;
        for (int i = 0; i < n;) {
            if (nums[i] == 2 && end > i) {
                swap(i, end, nums);
                end--;
            } else if (nums[i] == 0 && start < i) {
                swap(i, start, nums);
                start++;
            } else {
                i++;
            }
        }
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    ReadMatrix<int>().OneDMatrix(n, nums);
    SortColors().sortColors(nums);
    PrintMatrix<int>().OneDMatrix(nums, " ");
    return 0;
}
