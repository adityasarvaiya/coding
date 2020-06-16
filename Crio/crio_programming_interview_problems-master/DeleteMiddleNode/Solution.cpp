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
void deleteNode(ListNode* node, ListNode* prev=NULL) {
    if(node == NULL) {
        return;
    }
    if(node->next == NULL) {
        prev->next = NULL;
        return;
    }
    swap(node->val , node->next->val);
    deleteNode(node->next , node);
}
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

void deleteMiddleNode(ListNode* node) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    deleteNode(node, NULL);
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
}
