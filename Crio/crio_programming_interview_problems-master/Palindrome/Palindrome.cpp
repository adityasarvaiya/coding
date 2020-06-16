#include<bits/stdc++.h>
using namespace std;
#include "Solution.cpp"

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

bool isEqual(ListNode* head1, ListNode* head2) {
    while(head1 && head2) {
        if(head1->val != head2->val) {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return head1 == NULL && head2 == NULL;
}

int main() {
    int testCases;
    cin >> testCases;
    for(int _t = 0 ; _t < testCases ; ++_t) {
        int n;
        cin >> n;
        vector<int> list(n);
        for(int i = 0 ; i < n ; ++i) {
            cin >> list[i];
        }
        ListNode* head = ListNode().createList(list);
        ListNode* originalHead = ListNode().createList(list);

        bool result = isPalindrome(head);

        if(!isEqual(head, originalHead)) {
            cout << "Linked List has been modified\n";
            continue;
        }

        cout << (result ? "Yes\n": "No\n");
    }
    return 0;
}
