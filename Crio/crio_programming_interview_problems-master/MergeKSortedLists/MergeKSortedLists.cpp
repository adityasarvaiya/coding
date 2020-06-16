#include<bits/stdc++.h>
using namespace std;
#include "../crio/cpp/ds/ListNode/ListNode.hpp"
#include "Solution.cpp"

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

int main()
{
	int k;
	cin>>k;
	vector<ListNode*> list;
	for(int i=0;i<k;i++)
	{
		int n;
		cin>>n;
		vector<int> values;
		for(int j=0;j<n;j++)
		{
			int x;
			cin>>x;
			values.push_back(x);
		}
		ListNode* head = ListNode().createList(values);
		list.push_back(head);
	}

	ListNode* ans = Solution().mergeKSortedList(list);
	while(ans!=NULL)
	{
		cout<<ans->val<<" ";
		ans=ans->next;
	}
}
