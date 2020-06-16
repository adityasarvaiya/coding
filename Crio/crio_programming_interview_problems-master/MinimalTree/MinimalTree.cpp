#include <bits/stdc++.h>
#include "Solution.cpp"

using namespace std;

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

int preorderTraversal(TreeNode* node,set<int >& elements) 
{
    if (node == NULL) 
        return 0;  
    int count=1;
    elements.insert(node->val);
    count += preorderTraversal(node->left, elements);  
    count += preorderTraversal(node->right, elements); 
    return count;
} 
pair< set<int >,int> getElements(TreeNode* root)
{
    set<int > elements;
    int count = preorderTraversal(root,elements);
    return {elements,count};
}

int height(TreeNode* node)
{
    if(node == NULL)
        return 0;
    int lDepth = height(node->left);
    int rDepth = height(node->right);
    return max(lDepth,rDepth)+1;
}

bool validNode(TreeNode* node,int lower,int upper)
{
    if(node == NULL)
        return true;
    int val = node->val;
    if(val <= lower or val >= upper)
        return false;
    if(!validNode(node->right,val,upper))
        return false;
    if(!validNode(node->left,lower,val))
        return false;
    return true;
}
bool isValidateBST(TreeNode* root)
{
    return validNode(root,-1e9,1e9);
}

int main()
{
    int n;
    cin>>n;
    vector<int > arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    TreeNode* root = MinimalTree().findMinimalTree(arr);
    // checking part
    set<int > elements;
    for(auto i:arr)
        elements.insert(i);
    int depth;
    pair<set<int > ,int> checks= getElements(root);
    if(elements != checks.first)
        depth = -1;
    else if (elements.size() != checks.second)
        depth = -1;
    else if(!isValidateBST(root))
        depth = -1;
    else
        depth = height(root); 
    cout<<depth<<"\n";
    return 0;
}
