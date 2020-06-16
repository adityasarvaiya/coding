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

def rotate_list_by_k(head, k):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    l = length(head)
    if l == 0 or k % l == 0 or l == 1:
        return head
    k = k % l
    idx = l - k - 1
    tail = get_node_at_index(head, l - 1)
    node = get_node_at_index(head, idx)
    new_head = node.next
    node.next = None
    tail.next = head
    
    return new_head
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

