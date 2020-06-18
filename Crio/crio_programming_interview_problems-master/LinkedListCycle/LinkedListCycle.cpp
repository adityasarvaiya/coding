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
<<<<<<< HEAD
=======
#include "../crio/cpp/io/FastIO.hpp"
>>>>>>> 71606988ddaa09ebfa4cdb246874509207baa3f5
#include "../crio/cpp/ds/ListNode/ListNode.hpp"

using namespace std;

class LinkedListCycle {
public:
<<<<<<< HEAD
    string hasCycle(ListNode* head) {
    	// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        map<ListNode*, bool> mp;
        while(head != NULL) {
            if(mp[head])
            	return "true";
            mp[head] = true;
            head = head->next;
        }
        return "false";
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
=======
	bool hasCycle(ListNode* head) {
		// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
		map<ListNode*, bool> mp;
		while (head != NULL) {
			if (mp[head])
				return true;
			mp[head] = true;
			head = head->next;
		}
		return false;
		// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
	}
>>>>>>> 71606988ddaa09ebfa4cdb246874509207baa3f5
};

int main() {
	int x, pos;
	vector<int> list;
	while (cin >> x) {
		list.push_back(x);
	}
	pos = list[int(list.size()) - 1];
	list.pop_back();
	ListNode* head = ListNode().generateLinkedListWithCycle(list, pos);
<<<<<<< HEAD
    string result = LinkedListCycle().hasCycle(head);
    cout << result;
=======
	bool result = LinkedListCycle().hasCycle(head);
	if (result)
		cout << "true" << endl;
	else {
		cout << "false" << endl;
	}
>>>>>>> 71606988ddaa09ebfa4cdb246874509207baa3f5
	return 0;
}
