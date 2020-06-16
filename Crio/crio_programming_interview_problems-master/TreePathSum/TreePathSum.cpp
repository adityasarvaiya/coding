#include <bits/stdc++.h>
#include "Solution.cpp"
using namespace std;

// CRIO_SOLUTION_START_MODULE_TREE_PATH_SUM
// CRIO_SOLUTION_END_MODULE_TREE_PATH_SUM

// CRIO_SOLUTION_START_MODULE_TREE_PATH_SUM_WITH_BREAKDOWN
void test()
{
    assert(true);
}
// CRIO_SOLUTION_END_MODULE_TREE_PATH_SUM_WITH_BREAKDOWN

int main()
{
// CRIO_SOLUTION_START_MODULE_TREE_PATH_SUM_WITH_BREAKDOWN
    test();
// CRIO_SOLUTION_END_MODULE_TREE_PATH_SUM_WITH_BREAKDOWN

    TreeNode* root  = TreeNode().readTreeReturnRoot();
    int k;
    cin >> k;
    printf("%d\n", CountTreePathSumToK(root, k));
    return 0;
}
