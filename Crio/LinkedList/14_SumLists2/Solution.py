from crio.ds.List.ListNode import *
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
def reverse_list(head):
    res = None
    while head != None:
       rest = head.next
       if res == None:
           res = head
           res.next= None
       else:
           head.next = res
           res = head
       head = rest

    return res


def add_to_tail(head, n):
    new_node = ListNode(n)
    if head != None:
        new_node.next = head
    return new_node
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def add(n1, n2):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS

    head = None
    carry = 0
    num1 = reverse_list(n1)
    num2 = reverse_list(n2)
 
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
        head = add_to_tail(head, n)

    if carry != 0:
        head = add_to_tail(head, carry) 

    return head
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
