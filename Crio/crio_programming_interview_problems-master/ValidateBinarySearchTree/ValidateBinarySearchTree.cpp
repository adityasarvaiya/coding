#include <bits/stdc++.h>
#include "../crio/cpp/ds/TreeNode/TreeNode.hpp"
#include "Solution.cpp"
using namespace std;

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

TreeNode *makeTreeFromEdges(vector<long> parent , vector<pair<long, long> > edges)
{
    unordered_map<int, TreeNode*> nodebyIndex;
    int n = parent.size();
    for (long i = 1; i <= n; i++)
        nodebyIndex[i] = new TreeNode(i);

    TreeNode *root = nodebyIndex[1];
    for (int i = 1; i <= n; i++)
    {

        TreeNode *ptr = nodebyIndex[i];
        if (edges[i].first != -1) {
            ptr->left = nodebyIndex[edges[i].first];
        }

        if (edges[i].second != -1) {
            ptr->right = nodebyIndex[edges[i ].second];
        }
    }
    for ( int i = 1; i < n + 1; i++) {
        TreeNode *ptr = nodebyIndex[i];
        ptr->val = parent[i ];
    }

    return root;
}
void printTree( TreeNode *root) {

    if ( root == NULL) return;
    cout << root->val <<  " " ;
    if ( root->left != NULL) {
        printTree(root->left);
    }
    if (root->right != NULL) {
        printTree(root->right);
    }
}

int main()
{

    int tests;
    cin >> tests;
    while (tests--)
    {
        int n, a, b;
        cin >> n;
        vector<long > parent(n + 1, 0);
        for (int i = 1; i <= n; i++)
            cin >> parent[i];
        vector<pair<long, long> > edges;
        edges.push_back({0, 0});
        for ( int i = 0; i < n; i++) {
            int x;
            cin >> x; cin >> a >> b;
            edges.push_back({a, b});
        }

        TreeNode *root = makeTreeFromEdges(parent, edges);
        bool answer = ValidateBinarySearchTree().validateBinarySearchTree(root);
        if (answer)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
