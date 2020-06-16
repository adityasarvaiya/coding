# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
def length(lst):
    c = 0
    while lst != None:
        lst = lst.next
        c += 1
    return c
    
def get_node_at_index(head, index):
    l = index
    while l > 0 and head != None:
       head = head.next
       l -= 1
       if l == 0:
           return head

    return head
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

'''
# Definition for ListNode
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
'''
def delete_kth_to_last(head, k):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    l = length(head)
    idx = l - k

    node = get_node_at_index(head, max(0, idx - 1))
    
    if idx <= 0:
       return head.next
    
    middle = node.next
    if middle != None:
        node.next = middle.next
    else:
        node.next = None
    return head
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
