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
ListNode* reverseLinkedList(ListNode* node) {
    ListNode* rev = NULL;
    while(node != NULL) {
        ListNode* temp = node;
        node = node->next;
        temp->next = rev;
        rev = temp;
    }
    return rev;
}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

ListNode* sumLists2(ListNode* head1 , ListNode* head2) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    int carry = 0;
    head1 = reverseLinkedList(head1);
    head2 = reverseLinkedList(head2);
    ListNode* result = new ListNode(0);
    ListNode* current = result;
    ListNode* prev = current;
    while(head1 != NULL && head2 != NULL) {
        current->val = (head1->val + head2->val + carry) % 10;
        carry = (head1->val + head2->val + carry) / 10;
        current->next = new ListNode(0);
        prev = current;
        current = current->next;
        head1 = head1->next;
        head2 = head2->next;
    }

    while(head1 != NULL) {
        current->val = (head1->val + carry) % 10;
        carry = (head1->val + carry) / 10;
        current->next = new ListNode(0);
        prev = current;
        current = current->next;
        head1 = head1->next;
    }

    while(head2 != NULL) {
        current->val = (head2->val + carry) % 10;
        carry = (head2->val + carry) / 10;
        current->next = new ListNode(0);
        prev = current;
        current = current->next;
        head2 = head2->next;
    }

    if(carry > 0) {
        current->val = carry;
    } else {
        prev->next = NULL;
    }
    return reverseLinkedList(result);

// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
