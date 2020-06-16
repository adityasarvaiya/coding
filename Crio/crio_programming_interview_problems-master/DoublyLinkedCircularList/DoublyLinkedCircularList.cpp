#include<bits/stdc++.h>
using namespace std;
#include "Solution.cpp"
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

bool isCircularLinkedList(DoublyLinkedListNode* head) {
    if(head == NULL) {
        return true;
    }
    DoublyLinkedListNode* slow = head;
    DoublyLinkedListNode* fast = head;

    while(true) {
        if(slow->next == NULL) {
            return false;
        }
        slow = slow->next;
        if(fast->next == NULL || fast->next->next == NULL) {
            return false;
        }
        fast = fast->next->next;
        if(fast == slow) {
            return slow == head;
        }
    }
    return false;
}

void printNode(DoublyLinkedListNode* node) {
    if(node == NULL) {
        cout << "null";
        return;
    }
    cout << node->val;
}

void printDoublyLinkedCircularList(DoublyLinkedListNode* head) {
    if(head == NULL) {
        return;
    }
    DoublyLinkedListNode* current = head;
    do {
        printNode(head->prev);
        cout << " ";
        printNode(head);
        cout << " ";
        printNode(head->next);
        cout << "\n";
        head = head->next;
    } while(head != current);
}

int main() {
    int n;
    cin >> n;
    vector<int> list(n);
    for(int i = 0 ; i < n ; ++i) {
        cin >> list[i];
    }
    ListNode* head = ListNode().createList(list);

    DoublyLinkedListNode* result = doublyLinkedCircularList(head);
    if(!isCircularLinkedList(result)) {
        cout << "Not a circular list\n";
        return 0;
    }
    printDoublyLinkedCircularList(result);
    return 0;
}