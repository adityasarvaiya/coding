#include <algorithm>
#include "../crio/cpp/ds/ListNode/ListNode.hpp"

// TODO: CRIO_TASK_MODULE_LINKED_LIST_ODD_EVEN_SPLIT
// Input:
//      1. given linked list head pointer
//      2. node where loop starts
//
// Task:
//      break the loop
// TODO: CRIO_TASK_MODULE_LINKED_LIST_ODD_EVEN_SPLIT
// Input:
//      head of a singly linked list
// Task:
//      1. slow runner traverse the linked list one node at a time
//      2. fast runner traverse the linked list two node at a time
//      3. If slow runner and fast runner meet at some node then return that node
//      4. Else return null(they don't meet and linked list ends).
// Output:
//      return the node they both meet. null if the list has is null terminated
            //printf("step count = %d, slow ->data = %d\n", step_count, slow->val);
// TODO: CRIO_TASK_MODULE_LINKED_LIST_ODD_EVEN_SPLIT
// Input:
//      1. given pointer to result list head
//      2. given pointer to result list tail
//      3. given head and tail of list to be appended
//
// Task:
//      append the given list to the result list
//
// TODO: CRIO_TASK_MODULE_LINKED_LIST_ODD_EVEN_SPLIT
// Input:
//      1. given node in a the linked list
//      2. node position in given linked list(1 based indexing)
// Task:
//      split the elements in odd position and even position into two seperate list
//  Output:
//      1. head of linked list of all nodes in odd positions
//      2. head of linked list of all nodes in even positions

void printlist(ListNode * head)
{
    ListNode node;
    vector<int> res = node.extractList(head);

    cout << res.size() << "\n";
    for (size_t i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << "\n";
}

// TODO: CRIO_TASK_MODULE_LINKED_LIST_ODD_EVEN_SPLIT
// Input:
//      1. head of linked list
// Task:
//      1. if linked list has no loop just split odd position and even position elements
//      2. if linked list has loop then return all odd position elements in the loop
//          and even positions elements in the loop
//  Output:
//      1. head of linked list of all nodes in odd positions
//      2. head of linked list of all nodes in even positions

ListNode* removeLoop(struct ListNode* loop_node, struct ListNode* head) 
{ 
    struct ListNode* ptr1 = loop_node; 
    struct ListNode* ptr2 = loop_node; 
  
    unsigned int k = 1, i; 
    while (ptr1->next != ptr2) { 
        ptr1 = ptr1->next; 
        k++; 
    } 
  
    ptr1 = head; 
  
    ptr2 = head; 
    for (i = 0; i < k; i++) 
        ptr2 = ptr2->next; 
  
    while (ptr2 != ptr1) { 
        ptr1 = ptr1->next; 
        ptr2 = ptr2->next; 
    } 
  
    while (ptr2->next != ptr1) 
        ptr2 = ptr2->next; 

    ptr2->next = NULL; 
    
    return ptr1;
} 


vector<ListNode *> split_list_by_odd_or_even(ListNode * head)
{

    struct ListNode *slow_p = head, *fast_p = head, *tmp_head = head;   
    
    while (slow_p && fast_p && fast_p->next) { 
        slow_p = slow_p->next; 
        fast_p = fast_p->next->next; 
  
        if (slow_p == fast_p) { 
            head = removeLoop(slow_p, head); 
        } 
    }

    int f = 1;
    while (tmp_head != head) {
        if (f) {
            f = 0;
        } else {
            f = 1;
        }

        tmp_head = tmp_head->next;
    }

    struct ListNode *res1_head = NULL, *res1_tail = NULL, *res2_head = NULL; 
    struct ListNode *res2_tail = NULL, *tmp = head;
    
    while (tmp != NULL) {
        if (f) {
            if (res1_head == NULL) {
                res1_head = tmp;
                res1_tail = tmp;
            } else {
                res1_tail->next = tmp;
                res1_tail = tmp;
            }

            f = 0;
        } else {
            if (res2_head == NULL) {
                res2_head = tmp;
                res2_tail = tmp;
            } else {
                res2_tail->next = tmp;
                res2_tail = tmp;
            }

            f = 1;
        }

        tmp = tmp->next;
    }
    
    if (res1_tail) {
        res1_tail->next = NULL;
    }

    if (res2_tail) {
        res2_tail->next = NULL;
    }
    
    vector<ListNode *> results;
    results.push_back(res1_head);
    results.push_back(res2_head);
    
    return results;
}
