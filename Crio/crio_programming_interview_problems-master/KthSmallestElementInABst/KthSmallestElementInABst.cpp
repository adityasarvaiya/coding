#include <bits/stdc++.h>
#include "Solution.cpp"
using namespace std;

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

bool util(TreeNode * root ,  long long min ,   long long max) {
    if ( root == NULL) return 1;

    if ( root->val >= max || root->val <= min)
        return 0;
    if ( root->left != NULL && !(util(root->left, min , root->val ))) {
        return 0;
    }
    if ( root->right != NULL && !(util(root->right, root->val , max))) {
        return 0;
    }

    return 1;
}

bool validateBinarySearchTree(TreeNode* root) {
    long long min = -1e10 - 2 ;
    long long max = 1e10 + 2 ;
    bool flag = util(root, min, max);
    return flag;
}

TreeNode* getTreeFromInput(int n, vector<int> &val, vector<vector<int> > &edges) {
    vector<TreeNode*> nodes(n);
    for(int i = 0; i < n ; ++i) {
        nodes[i] = new TreeNode(val[i]);
    }

    for(auto &edge: edges) {
        int parentIdx = edge[0] - 1;
        int leftChildIdx = edge[1] - 1;
        int rightChildIdx = edge[2] - 1;

        if(leftChildIdx >= 0) {
            nodes[parentIdx]->left = nodes[leftChildIdx];
        }
        if(rightChildIdx >= 0) {
            nodes[parentIdx]->right = nodes[rightChildIdx];
        }
    }
    return nodes[0];
}
int main() {
    int n;
    cin >> n;
    assert(n >= 1 && n <= 1e5);

    vector<int> val(n);
    set<int> check;
    for(int i = 0 ; i < n ; ++i) {
        cin >> val[i];
        assert(check.find(val[i]) == check.end());
        check.insert(val[i]); 
        assert(val[i] >= 1 && val[i] <= 1e9);
    }
    vector<vector<int> > edges(n);
    for(int i = 0 ; i < n ; ++i) {
        int p, l, r;
        cin >> p >> l >> r;
        assert( (p >= 1 && p <= n));
        assert( (l >= 1 && l <= n) || l == -1);
        assert( (r >= 1 && r <= n) || r == -1);
        edges[i] = {p, l, r};
    }
    int k;
    cin >> k;
    assert(k >= 1 && k <= n);

    TreeNode* root = getTreeFromInput(n, val, edges);
    assert(validateBinarySearchTree(root));
    int result = kthSmallest(root, k);
    cout << result << "\n";
    return 0;
}