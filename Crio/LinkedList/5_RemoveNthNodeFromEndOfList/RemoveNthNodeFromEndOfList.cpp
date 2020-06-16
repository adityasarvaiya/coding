#include <bits/stdc++.h>
#include "../crio/cpp/ds/ListNode/ListNode.hpp"

using namespace std;

/*
//Definition of ListNode
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

class RemoveNthNodeFromEndOfList {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        ListNode* hd = head;

        int count = 0;
        while (hd != NULL) {
            hd = hd->next;
            ++count;
        }

        if (count < n)
            return head;

        if (count == n) {
            ListNode* rest = head->next;
            head = NULL;
            return rest;
        }

        ListNode* node = head;
        for (int i = 1; i < count - n; ++i) {
            node = node->next;
        }

        ListNode* removed = node->next;
        node->next = removed->next;

        removed = NULL;

        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
        return head;
    }
};

int main() {

    int n, k;
    cin >> n >> k;
    vector<int> numbers(n);
    for (int i = 0 ; i < n ; ++i) {
        cin >> numbers[i];
    }
    ListNode* list = ListNode().createList(numbers);
    ListNode* result = RemoveNthNodeFromEndOfList().removeNthFromEnd(list, k);

    vector<int> res = ListNode().extractList(result);
    for ( auto it : res) {
        cout << it << " ";
    }

    return 0;
}
