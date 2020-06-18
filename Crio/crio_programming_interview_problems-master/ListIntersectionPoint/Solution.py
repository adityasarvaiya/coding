# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
def length(head):
    
    l = 0
    while head != None:
       head = head.next
       l += 1 
    return l

def get_node_at_index(head, index):
    l = index
    while l > 0 and head != None:
       head = head.next
       l -= 1
       if l == 0:
           return head

    return head

def intersection(l1, l2):
    while l1 != l2:
       l1 = l1.next
       l2 = l2.next
    return l1
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS


def get_intersection_node(lst1, lst2):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    l1 = length(lst1)    
    l2 = length(lst2)
    
    if l1 > l2:
       return intersection(get_node_at_index(lst1, l1-l2), lst2)
    return intersection(lst1, get_node_at_index(lst2, l2-l1))
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS            
