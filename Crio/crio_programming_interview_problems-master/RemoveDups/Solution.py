from crio.ds.List.ListNode import *
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
def add_to_tail(hd, new_node):
    head = hd[0]
    tail = hd[1]
    if head == None:
        return (new_node, new_node)
    tail.next = new_node
    return (head, new_node)
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS


def remove_duplicates(head):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    res = (None, None)

    dict = {}
    while head != None:
        rest = head.next
        if head.val not in dict:
            dict[head.val] = 1
            head.next = None
            res = add_to_tail(res, head)
        head = rest
    return res[0]
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

