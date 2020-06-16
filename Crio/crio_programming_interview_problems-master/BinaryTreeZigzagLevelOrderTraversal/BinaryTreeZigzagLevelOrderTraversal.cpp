#include <bits/stdc++.h>
#include "../crio/cpp/ds/TreeNode/TreeNode.hpp"
#include "../crio/cpp/io/PrintMatrix.hpp"
#include "Solution.cpp"
using namespace std;

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

int main()
{
	int tests;
	cin >> tests;
	while (tests--)
	{
		TreeNode* root  = TreeNode().readTreeReturnRoot();
		vector<vector<int>> result =
		                     BinaryTreeZigzagLevelOrderTraversal().zigzagLevelOrder(root);
		PrintMatrix<int>().TwoDMatrix(result);


	}
	return 0;
}
