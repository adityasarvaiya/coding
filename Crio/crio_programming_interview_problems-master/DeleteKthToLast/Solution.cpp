#include "../crio/cpp/ds/ListNode/ListNode.hpp"
/*
// Definition for ListNode
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
ListNode* deleteKthToLast(ListNode* head , int k) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
	ListNode* end = head;
	for (int i = 0 ; i < k ; ++i) {
		end = end->next;
	}
	if (end == NULL) {
		return head->next;
	}
	ListNode* current = head;
	ListNode* prev = NULL;

	while (end != NULL) {
		end = end->next;
		prev = current;
		current = current->next;
	}

	prev->next = current->next;
	return head;

// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
