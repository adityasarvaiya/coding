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
#include "../crio/cpp/ds/ListNode/ListNode.hpp"

ListNode* loopDetection(ListNode* head) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    ListNode* slow = head->next;
    ListNode* fast = head->next->next;
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = head;
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
