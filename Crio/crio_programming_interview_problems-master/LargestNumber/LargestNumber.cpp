#include "../crio/cpp/io/FastIO.hpp"
#include "../crio/cpp/io/ReadMatrix.hpp"
#include <bits/stdc++.h>
using namespace std;

class LargestNumber {
  public:
    // TODO: CRIO_TASK_MODULE_L2_PROBLEMS
    // Your implementation goes here
    // CRIO_SOLUTION_START_MODULE_L2_PROBLEMS
    struct StringComp {
        bool operator()(const string s1, const string s2) {
            string one2 = s1 + s2;
            string two1 = s2 + s1;

            return one2 > two1;
        }
    };
    // CRIO_SOLUTION_END_MODULE_L2_PROBLEMS

    string largestNumber(vector<int>& nums) {
        // TODO: CRIO_TASK_MODULE_L2_PROBLEMS
        // Your implementation goes here
        // CRIO_SOLUTION_START_MODULE_L2_PROBLEMS
        vector<string> nstr;
        for (int i = 0; i < int(nums.size()); i++) {
            nstr.push_back(to_string(nums[i]));
        }

        sort(nstr.begin(), nstr.end(), StringComp());
        string result = "";
        for (int i = 0; i < int(nstr.size()); i++) {
            result += nstr[i];
        }
        int i = 0;
        while (result[i] == '0')
            i++;
        if (i == int(result.size()))
            return "0";

        return result;
        // CRIO_SOLUTION_END_MODULE_L2_PROBLEMS
    }
};

int main() {
    FastIO();
    int n;
    cin >> n;
    vector<int> nums;
    ReadMatrix<int>().OneDMatrix(n, nums);
    string result = LargestNumber().largestNumber(nums);
    cout << result;
    return 0;
}
