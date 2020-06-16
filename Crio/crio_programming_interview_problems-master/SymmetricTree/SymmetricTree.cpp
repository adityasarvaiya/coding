/*
class ListNode {
    public:
	int val;
	ListNode* next;

	ListNode() {}

	ListNode(int x) {                      
	    val = x;                       
	    next = NULL;
	}
};
*/
#include <bits/stdc++.h>
#include "FastIO.hpp"
#include "ReadMatrix.hpp"
#include "PrintMatrix.hpp"
#include "ListNode.hpp"
#include "TreeNode.hpp"

using namespace std;

class SymmetricTree {
public:
	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    bool check(TreeNode* p,TreeNode* q)
    {
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
        if(p->val!=q->val) return false;
        if(!check(p->left,q->right)) return false;
        if(!check(p->right,q->left)) return false;
        return true;
    }
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

    bool isSymmetric(TreeNode* root) {
    	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        if(root==NULL) return true;
        if(check(root->left,root->right)) return true;
        return false;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
};

int main() {
	FastIO();
	string s, num;

	getline(cin, s);
	vector<string> tree;
	stringstream Str(s);
	while(getline(Str, num, ' ')) {
		tree.push_back(num);
	}

	TreeNode* root = NULL;
	root = TreeNode().makeTreeFromArray(0, tree, root);
    bool result = SymmetricTree().isSymmetric(root);
    cout << boolalpha << result;
	return 0;
}
