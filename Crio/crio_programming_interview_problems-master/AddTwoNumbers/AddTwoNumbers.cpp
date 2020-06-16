/*
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
#include "FastIO.hpp"
#include "ListNode.hpp"
#include "PrintMatrix.hpp"
#include "ReadMatrix.hpp"
#include <bits/stdc++.h>
using namespace std;

class AddTwoNumbers {
  public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // TODO: CRIO_TASK_MODULE_L2_PROBLEMS
        // Your implementation goes here
        // CRIO_SOLUTION_START_MODULE_L2_PROBLEMS
        ListNode* l = new ListNode(0);
        int carry = 0;
        ListNode* head = l;
        while (l1 != NULL && l2 != NULL) {
            int z = carry + l1->val + l2->val;
            l->next = new ListNode(z % 10);
            carry = z / 10;
            l1 = l1->next;
            l2 = l2->next;
            l = l->next;
        }
        while (l1 != NULL) {
            int z = carry + l1->val;
            l->next = new ListNode(z % 10);
            carry = z / 10;
            l1 = l1->next;
            l = l->next;
        }
        while (l2 != NULL) {
            int z = carry + l2->val;
            l->next = new ListNode(z % 10);
            carry = z / 10;
            l2 = l2->next;
            l = l->next;
        }
        if (carry > 0)
            l->next = new ListNode(carry);
        return head->next;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
};

int main() {
    FastIO();
    int n, m;
    cin >> n;
    vector<int> firstNumber;
    ReadMatrix<int>().OneDMatrix(n, firstNumber);
    cin >> m;
    vector<int> secondNumber;
    ReadMatrix<int>().OneDMatrix(m, secondNumber);
    ListNode* firstNumberList = ListNode().createList(firstNumber);
    ListNode* secondNumberList = ListNode().createList(secondNumber);
    ListNode* result =
        AddTwoNumbers().addTwoNumbers(firstNumberList, secondNumberList);
    vector<int> resultList = ListNode().extractList(result);
    PrintMatrix<int>().OneDMatrix(resultList, " ");
    return 0;
}
