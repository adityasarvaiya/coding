#include <bits/stdc++.h>
using namespace std;
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
class Solution {
    public:
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        void makePreOrderFromTree(TreeNode* root, vector<int>& preOrder) {
            if(root == NULL) {
                preOrder.push_back(-1);
                return ;
            }
            preOrder.push_back(root->val);
            makePreOrderFromTree(root->left, preOrder);
            makePreOrderFromTree(root->right, preOrder);
        }
        void makeInOrderFromTree(TreeNode* root, vector<int>& inOrder) {
            if(root == NULL) {
                inOrder.push_back(-1);
                return ;
            }
            makeInOrderFromTree(root->left, inOrder);
            inOrder.push_back(root->val);
            makeInOrderFromTree(root->right, inOrder);
        }
        void computeLPSArray(vector<int > &pattern, int M, vector<int > &lps) 
        { 
            int len = 0; 
            lps[0] = 0;
            int i = 1; 
            while (i < M) 
            { 
                if (pattern[i] == pattern[len]) 
                { 
                    len++; 
                    lps[i] = len; 
                    i++; 
                } 
                else 
                {
                    if (len != 0)
                        len = lps[len - 1];
                    else
                    { 
                        lps[i] = 0; 
                        i++; 
                    } 
                } 
            } 
        } 
        bool KMPSearch(vector<int > pattern, vector<int > str) 
        { 
            int M = pattern.size(); 
            int N = str.size(); 
            vector<int > lps(M);
            computeLPSArray(pattern, M, lps); 
            int i = 0; 
            int j = 0;
            while (i < N)
            { 
                if (pattern[j] == str[i])
                { 
                    j++; 
                    i++; 
                }
                if (j == M) { 
                    return true;
                    j = lps[j-1]; 
                } 
                else if (i < N && pattern[j] != str[i]) 
                { 
                    if (j != 0) 
                        j = lps[j-1]; 
                    else
                        i=i+1; 
                } 
            }
            return false;
        } 
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
        bool checkSubTree(TreeNode *root,TreeNode *root2){
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        vector<int > preOrder1,preOrder2,inOrder1,inOrder2;
        makePreOrderFromTree(root,preOrder1);
        makePreOrderFromTree(root2,preOrder2);
        makeInOrderFromTree(root,inOrder1);
        makeInOrderFromTree(root2,inOrder2);
        bool check1 = KMPSearch(preOrder2,preOrder1);
        bool check2 = KMPSearch(inOrder2,inOrder1);
        return check1 & check2 ;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
        }
};