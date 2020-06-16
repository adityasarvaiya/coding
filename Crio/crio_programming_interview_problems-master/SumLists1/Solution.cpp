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

ListNode* sumLists(ListNode* head1 , ListNode* head2) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    int carry = 0;
    ListNode* result = new ListNode(0);
    ListNode* current = result;
    ListNode* prev = current;
    while (head1 != NULL && head2 != NULL) {
        current->val = (head1->val + head2->val + carry) % 10;
        carry = (head1->val + head2->val + carry) / 10;
        current->next = new ListNode(0);
        prev = current;
        current = current->next;
        head1 = head1->next;
        head2 = head2->next;
    }

    while (head1 != NULL) {
        current->val = (head1->val + carry) % 10;
        carry = (head1->val + carry) / 10;
        current->next = new ListNode(0);
        prev = current;
        current = current->next;
        head1 = head1->next;
    }

    while (head2 != NULL) {
        current->val = (head2->val + carry) % 10;
        carry = (head2->val + carry) / 10;
        current->next = new ListNode(0);
        prev = current;
        current = current->next;
        head2 = head2->next;
    }

    if (carry > 0) {
        current->val = carry;
    } else {
        prev->next = NULL;
    }
    return result;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
    
