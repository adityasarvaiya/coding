#include <algorithm>
#include "../crio/cpp/ds/ListNode/ListNode.hpp"


// TODO: CRIO_TASK_MODULE_LINKED_LIST_RANDOM_REVERSAL_WITH_BREAKDOWN
// Input:
//      Given a list head
// Task:
//      1. reverse the given list inplace
//
// return:
//      return reversed_list_head
//
// Edge Cases:
//      What do you do when there are less than k elements ?
//


// TODO: CRIO_TASK_MODULE_LINKED_LIST_RANDOM_REVERSAL_WITH_BREAKDOWN
//
// Input:
//      Given a list head and k
// Task:
//      1. split that given list into two lists
//           list1  -- first k elements
//           list2  -- all elements after k
//
// return:
//      return (list1_head, list2_head)
//
//
// Edge Cases:
//      What do you do when there are less than k elements ?


void print_list(ListNode * head)
{
    printf("List : ");

    while (head) {
        printf("%d->", head->val);
        head = head->next;
    }
    printf("null\n");
}



// TODO: CRIO_TASK_MODULE_LINKED_LIST_RANDOM_REVERSAL
// Input:
//      1. singly linked list
//      2. list of numbers
//
// Task:
//      for every `k` in numbers
//          reverse next k elements of the linked list (for first k start from head)
//          append the reversed list to result linked list
//
// Output:
//      Return the result list
//


ListNode * reverse (ListNode *head, const vector<int> & groups, int group_index)  
{  
    ListNode* current = head;  
    ListNode* next = NULL;  
    ListNode* prev = NULL;  
    int count = 0;  
      
    while (current != NULL && count < groups[group_index])  
    {  
        next = current->next;  
        current->next = prev;  
        prev = current;  
        current = next;  
        count++;  
    }  
      
    if (next != NULL && (group_index+1 < groups.size())) {
        head->next = reverse(next,groups, group_index+1);
    } else {
        head->next = next;
    }
    
    return prev;  
}  

ListNode * reverse1 (ListNode *head, const vector<int> & groups)  
{  

    ListNode* curr_tail = NULL;
    ListNode* prev_tail = NULL;
    ListNode* current = head;  
    ListNode* next = NULL;  
    ListNode* prev = NULL;  
        

    for (int i = 0; i < groups.size() && current != NULL; ++i) {
        int count = 0;  
        curr_tail = current;
        prev = NULL;
        next = NULL;

        while (current != NULL && count < groups[i])  
        {  
            next = current->next;  
            current->next = prev;  
            prev = current;  
            current = next;  
            count++;  
        }  
        
        if (i == 0) {
            head = prev;
        } else {
            prev_tail->next = prev;
        }
        
        prev_tail = curr_tail;    
    }
        
    return head;  
}  

ListNode * performRandomReversals(ListNode * head, const vector<int> & groups)
{
    if (groups.size()) {
        head = reverse(head, groups, 0);
    }

    // head = reverse1(head, groups);

    return head;
}

