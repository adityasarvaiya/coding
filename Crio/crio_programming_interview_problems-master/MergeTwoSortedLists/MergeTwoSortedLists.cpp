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
using namespace std;
#include "Solution.cpp"

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

int main() {
	int m, n;
	cin >> m;
	vector<int> nums1(m);

	for(int i = 0 ; i < m ; ++i) {
            cin >> nums1[i];
        }
    	cin >> n;
	vector<int> nums2(n);
	for(int i = 0 ; i < n ; ++i) {
            cin >> nums2[i];
        }

	ListNode* l1 = ListNode().createList(nums1);
    	ListNode* l2 = ListNode().createList(nums2);

    	ListNode* resultHead = mergeTwoLists(l1, l2);

	vector<int> resultList = ListNode().extractList(resultHead);
        for(int i = 0 ; i < resultList.size() ; ++i) {
            cout << resultList[i] << " ";
        }
	return 0;
}
