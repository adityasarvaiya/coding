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
#include <unordered_set>
#include "../crio/cpp/ds/ListNode/ListNode.hpp"

ListNode* removeDups(ListNode* head)
{
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    if(head == NULL) {
        return head;
    }
    if(head->next == NULL) {
        return head;
    }
    unordered_set<int> seen;
    ListNode* cur = head->next;
    ListNode* prev = head;

    seen.insert(head->val);

    while(cur != NULL) {
        if(seen.find(cur->val) != seen.end()) {
            cur = cur->next;
            prev->next = cur;
        } else {
            prev = cur;
            seen.insert(cur->val);
            cur = cur->next;
        }
    }
    return head;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
