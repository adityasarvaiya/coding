#include<bits/stdc++.h>
using namespace std;
#include "Solution.cpp"

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

int main() {
    int n;
    cin >> n;
    vector<int> preorder(n);
    for(int i = 0 ; i < n ; ++i) {
        cin >> preorder[i];
    }

    vector<int> inorder(n);
    for(int i = 0 ; i < n ; ++i) {
        cin >> inorder[i];
    }

    TreeNode* result = constructBinaryTreeFromPreorderAndInorderTraversal(preorder, inorder);
    
    vector<int> preOrder;
    TreeNode().makePreOrderFromTree(result, preOrder);
    for(int i = 0 ; i < preOrder.size(); ++i) {
        cout << preOrder[i] << " ";
    }
    cout << "\n";

    vector<int> inOrder;
    TreeNode().makeInOrderFromTree(result, inOrder);
    for(int i = 0 ; i < inOrder.size(); ++i) {
        cout << inOrder[i] << " ";
    }
    cout << "\n";
}