#include<bits/stdc++.h>
using namespace std;
#include "Solution.cpp"

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

ListNode* getKthNode(ListNode* head, int k) {
    if(k == 1) {
        return head;
    }
    return getKthNode(head->next , k - 1);
}

int main() {
    int n;
    cin >> n;
    vector<int> list(n);
    for(int i = 0 ; i < n ; ++i) {
        cin >> list[i];
    }
    int k;
    cin >> k;

    ListNode* head = ListNode().createList(list);
    ListNode* nodeToDelete = getKthNode(head , k);
    deleteMiddleNode(nodeToDelete);
    vector<int> resultList = ListNode().extractList(head);
    for(int i = 0 ; i < resultList.size() ; ++i) {
        cout << resultList[i] << " ";
    }
    cout << "\n";
    return 0;
}
