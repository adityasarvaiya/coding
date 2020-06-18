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
int sizeOfList (ListNode *head) {
	int size = 0;
	while (head != NULL) {
		head = head->next;
		size++;
	}
	return size;
}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

ListNode * rotateList(ListNode * head , int k) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	ListNode *prevHead = head , *temp = head;
	ListNode *lastNode = head;

	int size = sizeOfList(head);
	if (size == 0) return head;

	k = k % size;
	int moves = size - k;
	if (k == 0) return head;

	while (lastNode->next != NULL  ) {
		lastNode = lastNode->next;
	}

	prevHead = head->next;
	while (moves > 1 ) {
		moves--;
		head = head->next;
		prevHead = head->next;

	}
	head->next = NULL;
	lastNode->next = temp;

	return prevHead;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
