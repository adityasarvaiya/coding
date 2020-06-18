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

ListNode* reverseLinkedList(ListNode* head) {
    ListNode* node = head;
    ListNode* rev = NULL;
    while(node != NULL) {
        ListNode* temp = new ListNode(node->val);
        node = node->next;
        temp->next = rev;
        rev = temp;
    }
    return rev;
}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

bool isPalindrome(ListNode* head) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    ListNode* rev = reverseLinkedList(head);
    while(rev != NULL && head != NULL) {
        if(rev->val != head->val) {
            return false;
        }
        rev = rev->next;
        head = head->next;
    }
    assert(rev == NULL && head == NULL);
    return true;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
