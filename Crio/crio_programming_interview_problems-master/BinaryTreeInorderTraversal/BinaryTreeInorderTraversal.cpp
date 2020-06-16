#include <bits/stdc++.h>
#include "../crio/cpp/ds/TreeNode/TreeNode.hpp"
#include "Solution.cpp"
using namespace std;

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

int main()
{
    int tests;
    cin >> tests;
    while (tests--)
    {
        TreeNode* root  = TreeNode().readTreeReturnRoot();
        vector<int> result = BinaryTreeInorderTraversal().inorderTraversal(root);
        for ( auto it : result) {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}
