from crio.ds.List.ListNode import *

   
def delete_middle_node(head, node):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    temp = node.next.val
    node.next = node.next.next
    node.val = temp
    return head
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
