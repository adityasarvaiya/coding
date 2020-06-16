#include "../crio/cpp/ds/ListNode/ListNode.hpp"

class DoublyLinkedListNode {
public:
    int val;
    DoublyLinkedListNode *prev;
    DoublyLinkedListNode *next;

    DoublyLinkedListNode(int x, DoublyLinkedListNode* p=NULL, DoublyLinkedListNode* n=NULL) {
        val = x;
        prev = p;
        next = n;
    }
};

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
DoublyLinkedListNode* convertToDoublyLinkedList(ListNode* head) {

    DoublyLinkedListNode* result = NULL;
    DoublyLinkedListNode* current = NULL;
    if (head == NULL) {
        return result;
    }
    while (head) {
        if (result == NULL) {
            result = new DoublyLinkedListNode(head->val);
            current = result;
        } else {
            current->next = new DoublyLinkedListNode(head->val, current, NULL);
            current = current->next;
        }
        head = head->next;
    }
    current->next = result;
    result->prev = current;
    return result;
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
DoublyLinkedListNode* doublyLinkedCircularList(ListNode* head) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    DoublyLinkedListNode* result = convertToDoublyLinkedList(head);
    return result;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
