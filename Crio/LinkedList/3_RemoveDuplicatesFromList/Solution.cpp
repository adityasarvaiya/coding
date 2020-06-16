#include "../crio/cpp/ds/ListNode/ListNode.hpp"

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
ListNode* removeDuplicates(ListNode* head) {
    if(head == NULL) {
        return head;
    }
    if(head->next == NULL) {
        return head;
    }
    ListNode* next = head->next;
    if(next->val == head->val) {
        while(next != NULL && next->val == head->val) {
            next = next->next;
        }
        return removeDuplicates(next);
    }
    head->next = removeDuplicates(next);

    return head;
}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
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
ListNode* removeDuplicatesFromList(ListNode* head)
{
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    return removeDuplicates(head);
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
