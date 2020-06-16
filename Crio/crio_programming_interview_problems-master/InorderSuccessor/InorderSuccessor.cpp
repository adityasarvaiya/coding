#include <bits/stdc++.h>
#include "../crio/cpp/ds/TreeNode/TreeNode.hpp"
#include "Solution.cpp"

using namespace std;
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
int main()
{
    vector<TreeNode* > nodes = TreeNode().readTreeReturnAllNodes();
    TreeNode* root = nodes[0];
    assert(TreeNode().isValidateBST(root) == true);
    int queries;
    cin>>queries;
    while(queries--)
    {
        int index;
        cin>>index;
        TreeNode* temp = nodes[index];
        TreeNode* succ =  Solution().inOrderSuccessor(root, temp); 
        if(succ !=  NULL) 
            cout<<succ->val<<"\n";
        else
            cout<<"-1\n";
    }
    return 0;
}
