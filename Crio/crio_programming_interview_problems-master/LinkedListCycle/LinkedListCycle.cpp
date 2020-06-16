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
#include "ListNode.hpp"

using namespace std;

class LinkedListCycle {
public:
    bool hasCycle(ListNode* head) {
    	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        map<ListNode*, bool> mp;
        while(head != NULL) {
            if(mp[head])
            	return true;
            mp[head] = true;
            head = head->next;
        }
        return false;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
};

int main() {
	FastIO();
	int x, pos;
	vector<int> list;
	while(cin >> x) {
		list.push_back(x);
	}
	pos = list[int(list.size())-1];
	list.pop_back();
	ListNode* head = ListNode().generateLinkedListWithCycle(list, pos);
    bool result = LinkedListCycle().hasCycle(head);
    cout << boolalpha << result;
	return 0;
}
