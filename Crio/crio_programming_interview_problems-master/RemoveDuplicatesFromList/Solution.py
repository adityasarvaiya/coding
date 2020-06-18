from crio.ds.List.ListNode import *

def remove_duplicates(head):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    curr = head 
    head = prev = ListNode(None) 
    head.next = curr 

    while curr and curr.next: 
        if curr.val == curr.next.val: 
            while(curr and curr.next and curr.val == curr.next.val): 
                curr = curr.next
            curr = curr.next
            prev.next = curr 
        else:
            prev = prev.next
            curr = curr.next
    return head.next
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
