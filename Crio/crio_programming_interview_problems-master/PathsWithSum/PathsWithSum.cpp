#include<bits/stdc++.h>
#include "../crio/cpp/ds/TreeNode/TreeNode.hpp"
using namespace std;
#include "Solution.cpp"

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

int main() {
    TreeNode* root = TreeNode().readTreeReturnRoot();
    int k;
    cin >> k;
    long long result = Solution().pathsWithSum(root, k);
    cout << result << "\n";
}
