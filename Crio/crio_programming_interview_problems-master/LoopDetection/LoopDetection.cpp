#include<bits/stdc++.h>
#include "Solution.cpp"
#include "../crio/cpp/io/FastIO.hpp"

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

ListNode* getKthNode(ListNode* head, int k) {
    if(k == 1) {
        return head;
    }
    return getKthNode(head->next , k - 1);
}

ListNode* addNodeAtEnd(ListNode* head, ListNode* node) {
    ListNode* current = head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = node;
    return head;
}
int main() {
    FastIO();
    int n;
    cin >> n;
    vector<int> list(n);
    for(int i = 0 ; i < n ; ++i) {
        cin >> list[i];
    }
    int k;
    cin >> k;

    ListNode* head = ListNode().createList(list);
    ListNode* loopStartNode = getKthNode(head , k);
    head = addNodeAtEnd(head , loopStartNode);

    ListNode* result = loopDetection(head);
    cout << result->val << "\n";
}
