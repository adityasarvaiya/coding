from crio.ds.List.ListNode import *

def mergeTwoLists(l1, l2):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    prehead = ListNode(-1)
    prev = prehead
    while l1 and l2:
        if l1.val <= l2.val:
            prev.next = l1
            l1 = l1.next
        else:
            prev.next = l2
            l2 = l2.next            
        prev = prev.next

    prev.next = l1 if l1 is not None else l2
    return prehead.next
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

