#include<bits/stdc++.h>
#include "../crio/cpp/ds/TreeNode/TreeNode.hpp"
using namespace std;
#include "Solution.cpp"

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

TreeNode *makeTreeFromEdges(vector<long> val , vector<pair<long, long> > edges)
{
    unordered_map<int, TreeNode*> nodebyIndex;
    int n = val.size();
    for (long i = 0; i < n; i++)
        nodebyIndex[i] = new TreeNode(val[i]);
    TreeNode *root = nodebyIndex[0];
    for (int i = 0; i < n; i++)
    {
        TreeNode *ptr = nodebyIndex[i];
        if (edges[i].first != -1) {

            ptr->left = nodebyIndex[edges[i].first];
        }
        if (edges[i].second != -1) {
            ptr->right = nodebyIndex[edges[i].second];
        }
    }
    return root;
}
int main()
{
    int tests;
    cin >> tests;
    while (tests--)
    {
        int n, a, b;
        cin >> n;
        vector<long > val(n, 0);
        for (int i = 0; i < n; i++)
            cin >> val[i];
        vector<pair<long, long> > edges;
        for ( int i = 0; i < n; i++) {
            int x;
            cin >> x; cin >> a >> b;
            edges.push_back({a-1, b-1});
        }
        TreeNode *root = makeTreeFromEdges(val, edges);
        long long sum;
        cin >> sum;
        long long answer = Solution().pathsWithSumRootToLeaf(root,sum);
        cout << answer << endl;
    }
}
