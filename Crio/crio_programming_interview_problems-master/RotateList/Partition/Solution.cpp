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


ListNode* partition(ListNode* head , int x) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    if(head == NULL || head->next == NULL) {
        return head;
    }
    ListNode *lesser_head, *lesser, 
            *greater_head, *greater,
            *equal_head, *equal;
    lesser_head = new ListNode(-1);
    lesser = lesser_head;

    greater_head = new ListNode(-1);
    greater = greater_head;

    equal_head = new ListNode(-1);
    equal = equal_head;

    while(head != NULL) {
        if(head->val < x) {
            lesser->next = head;
            lesser = lesser->next;
        } else if(head->val == x) {
            equal->next = head;
            equal = equal->next;
        } else {
            greater->next = head;
            greater = greater->next;
        }
        head = head->next;
    }

    greater->next = NULL;
    equal->next = greater_head->next;
    lesser->next = equal_head->next;
    return lesser_head->next;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
