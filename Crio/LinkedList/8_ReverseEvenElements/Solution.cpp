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

ListNode * reverseEvenElements(ListNode *head , ListNode *prev) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	ListNode* nxt = NULL , * cur = NULL;
	if (head == NULL) return head;
	cur = head;
	while (cur != NULL && cur->val % 2 == 0   ) {
		nxt = cur->next;
		cur->next = prev;
		prev = cur;
		cur = nxt;
	}
	if ( cur != head) {
		head->next = cur;
		cur = reverseEvenElements(cur , NULL);
		return prev;
	}
	else {
		head->next = reverseEvenElements(head->next , head);
		return head;
	}
	//CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
