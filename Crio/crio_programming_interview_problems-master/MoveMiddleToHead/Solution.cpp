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

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
int sizeOfListNode(ListNode* head) {
	int size = 0;
	while (head != NULL) head = head->next , size++;
	return size;
}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

ListNode * moveMiddleToHead(ListNode * head) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	ListNode * temp = head;
	int size = sizeOfListNode(head);
	ListNode *slow = head , *prev = NULL , *nxt = NULL;
	if (size == 0 || size == 1) return head;
	int mid = size / 2;

	while (mid > 0) {
		prev = slow;
		slow = slow->next;
		nxt = slow->next;
		mid--;
	}

	prev->next = nxt;
	slow->next = head;
	return slow;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
