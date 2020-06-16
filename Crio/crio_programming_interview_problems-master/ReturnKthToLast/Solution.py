from crio.ds.List.ListNode import *
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS

def get_kth_element(head, k):
    for i in range(k):
        head = head.next

    return head 

def length(head):
    l = 0
    while head != None:
        head = head.next
        l += 1

    return l
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def kth_element_from_end(head, k):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS

    l = length(head)
    return get_kth_element(head, l - k)
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
 
