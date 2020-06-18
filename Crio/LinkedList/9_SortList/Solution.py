from crio.ds.List.ListNode import *

def print_list(head):
    while head != None:
        print(head.val, end = " ")
        head = head.next

# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
def add_to_tail(hd, new_node):
    head = hd[0]
    tail = hd[1]
    new_node.next = None
    if head == None:
        return (new_node, new_node)
    tail.next = new_node
    return (head, new_node)

def split(lst, k):

    #print("Split list @ {}".format(k))
    head = lst
    for i in range(k-1):
       lst = lst.next
    
    rest = lst.next
    lst.next = None
    #print("@split {} {}\n".format(head.val, rest.val))
    return (head, rest)

def merge(left, right):
    res = (None, None) 
    while left != None and right != None:
       if left.val < right.val:
          rest = left.next
          res = add_to_tail(res, left)
          left = rest
       else:
          rest = right.next
          res = add_to_tail(res, right)
          right = rest
 
    if left != None:
       res[1].next = left
    
    if right != None:
       res[1].next = right
    
    return res[0]

   
def sort_linked_list(lst, n):
    if n < 2:
       return lst
    (left, right) = split(lst, n//2)
    left = sort_linked_list(left, n//2)
    right = sort_linked_list(right, n - n//2)
    return merge(left, right)

def length(lst):
    l = 0
    while lst != None:
       lst = lst.next
       l += 1
    return l
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS


def sort_list(lst):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    return sort_linked_list(lst, length(lst))    
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
