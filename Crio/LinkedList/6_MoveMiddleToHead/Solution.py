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

def move_middle_to_head(head):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    l = length(head)
    idx = l // 2 - 1
    node = get_node_at_index(head, idx)
    if idx < 0:
        return head
    middle = node.next
    if  middle != None:
        node.next = middle.next
    else: 
        node.next = None

    middle.next = head
    return middle
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
