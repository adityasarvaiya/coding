from crio.ds.List.ListNode import *
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
def add_to_tail(hd, n):
    head = hd[0]
    tail = hd[1]
    new_node = ListNode(n)
    if head == None:
        return (new_node, new_node)
    tail.next = new_node
    return (head, new_node)
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def add(num1, num2):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    lst = (None, None) 
    carry = 0
 
    while num1 != None or num2 != None:
        n = carry
        if num1 != None:
            n += num1.val
            num1 = num1.next
        if num2 != None:
            n += num2.val
            num2 = num2.next
        carry = n // 10
        n = n % 10
        lst = add_to_tail(lst, n)

    if carry != 0:
        lst = add_to_tail(lst, carry) 

    return lst[0]
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
