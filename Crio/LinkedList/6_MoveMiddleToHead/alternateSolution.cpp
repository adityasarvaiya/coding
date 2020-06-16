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

ListNode * moveMiddleToHead(ListNode * head) {

	if (head == NULL || head->next == NULL)  
	return head;  
  
    ListNode* one_node = head;  
    ListNode* two_node = head;   
    ListNode* prev = NULL;  

    while (two_node != NULL && two_node->next != NULL)  
    {    
        prev = one_node;  
        two_node = two_node->next->next;  
        one_node = one_node->next;  
    }
  
    prev->next = prev->next->next;  
    one_node->next = head;  
    head = one_node;
	return head;
}
