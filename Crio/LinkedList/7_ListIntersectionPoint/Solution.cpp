#include "../crio/cpp/ds/ListNode/ListNode.hpp"

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
int length(ListNode* head) {
    int len = 0;
    while(head != NULL) {
        len++;
        head = head->next;
    }
    return len;
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
ListNode* listIntersectionPoint(ListNode* head1, ListNode* head2) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    int len1 = length(head1);
    int len2 = length(head2);
    
    while(len1 > len2) {
        head1 = head1->next;
        len1--;        
    }

    while(len1 < len2) {
        head2 = head2->next;
        len2--;
    }

    while(head1 != head2) {
        head1 = head1->next;
        head2 = head2->next;
    } 
    return head1;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}