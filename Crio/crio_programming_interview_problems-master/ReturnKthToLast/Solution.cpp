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
#include "../crio/cpp/ds/ListNode/ListNode.hpp"

// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
pair<int , int> findLastKth(ListNode* current , int k) {
    if(current == NULL) {
        return {INT_MAX , k-1};
    }
    int result , left;
    tie(result , left) = findLastKth(current->next , k);

    if(left == -1) {
        return {result , left};
    } else if(left == 0) {
        return {current->val , left - 1};
    }
    return {result , left - 1};
}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

int returnKthToLast(ListNode* head , int k) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    int result = findLastKth(head , k).first;
    return result;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
