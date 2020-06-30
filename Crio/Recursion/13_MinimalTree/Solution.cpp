/*
// Definition for TreeNode
class TreeNode {
public:
    long val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* next;
    TreeNode (long x) {
        val = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
*/
#include "../crio/cpp/ds/TreeNode/TreeNode.hpp"

class MinimalTree{
    public:
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        TreeNode* sortedArraytoBST(vector<int > &arr,int start,int end)
        {
            if(start>end)
                return NULL;
            int  mid =(start+end)/2;
            TreeNode* root= new TreeNode(arr[mid]);
            root->left = sortedArraytoBST(arr,start,mid-1);
            root->right = sortedArraytoBST(arr,mid+1,end); 
            return root;
        }
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
        TreeNode* findMinimalTree(vector<int > &arr)
        {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS

            int start = 0;
            int end = arr.size() - 1;
            TreeNode *root =sortedArraytoBST(arr,start,end);
            return root;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
        }
};