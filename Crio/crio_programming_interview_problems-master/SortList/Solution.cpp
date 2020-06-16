#include "../crio/cpp/ds/ListNode/ListNode.hpp"
/**
 * Definition for singly-linked list.
 * class ListNode {
 *   int val;
 *   ListNode* next;
 *   ListNode(int x) { val = x, next(NULL)}
 * }
 */

class SortList {
  public:
    // TODO: CRIO_TASK_MODULE_L1_PROBLEMS
    // Your implementation goes here
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    ListNode* merge(ListNode* left, ListNode* right) {
        if (not left)
            return right;
        if (not right)
            return left;
        if (left->val > right->val) {
            swap(left, right);
        }
        ListNode* dummy = left;
        ListNode* pre = left;
        left = left->next;
        while (left && right) {
            if (left->val > right->val) {
                pre->next = right;
                right = right->next;
            } else {
                pre->next = left;
                left = left->next;
            }
            pre = pre->next;
        }
        if (left)
            pre->next = left;
        if (right)
            pre->next = right;
        return dummy;
    }
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

    ListNode* sortList(ListNode* head) {
        // TODO: CRIO_TASK_MODULE_L1_PROBLEMS
        // Your implementation goes here
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        if (not head or not head->next)
            return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = slow->next;
        slow->next = NULL;
        return merge(sortList(head), sortList(head2));
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
};


