#include<bits/stdc++.h>
using namespace std;
#include "Solution.cpp"
#include "../crio/cpp/io/FastIO.hpp"
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

ListNode* addListAtEnd(ListNode* head, ListNode* headToAdd) {
    if(head == NULL) {
        return headToAdd;
    }
    ListNode* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = headToAdd;
    return head;
}


int main() {
    FastIO();
    int n;
    cin >> n;
    vector<int> list1(n);
    for(int i = 0 ; i < n; ++i) {
        cin >> list1[i];
    }
    ListNode* head1 = ListNode().createList(list1);

    int m;
    cin >> m;
    vector<int> list2(m);
    for(int i = 0 ; i < m; ++i) {
        cin >> list2[i];
    }
    ListNode* head2 = ListNode().createList(list2);
    
    int k;
    cin >> k;
    vector<int> commonList(k);
    for(int i = 0 ; i < k; ++i) {
        cin >> commonList[i];
    }
    ListNode* commonHead = ListNode().createList(commonList);
    head1 = addListAtEnd(head1, commonHead);
    head2 = addListAtEnd(head2, commonHead);

    ListNode* result = listIntersectionPoint(head1, head2);
    if(result == NULL) {
        cout << "-1\n";
        return 0;
    }
    cout << result->val << "\n";
}