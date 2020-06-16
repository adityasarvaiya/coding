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

class MaximumDepthOfBinaryTree {
public:
    int maxDepth(TreeNode* root) {
    	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        if (root == NULL)
			return 0;

		int l = maxDepth(root->left) + 1;
		int r = maxDepth(root->right) + 1;

		if (l < r)
			return r;
		return l;
		// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
};

int main() {
	FastIO();
	string s, num;

	getline(cin, s);
	vector<string> list;
	stringstream Str(s);
	while(getline(Str, num, ' ')) {
		list.push_back(num);
	}

	TreeNode* root = NULL;
	root = TreeNode().makeTreeFromArray(0, list, root);
	int result = MaximumDepthOfBinaryTree().maxDepth(root);
	cout << result;
	return 0;
}
