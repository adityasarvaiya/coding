# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
def append_list(lst, lst1):

    if lst[0] == None:
        return lst1
    else:
        lst[1].next = lst1[0]
        return (lst[0], lst1[1])

def add_to_tail(lst, head):

    if lst[0] == None:
        return (head, head)
    else:
        lst[1].next = head
        return (lst[0], head)

def reverse_list(head):
    res = None
    tail = head
    while head != None:
       rest = head.next
       if res == None:
           res = head
           res.next= None
       else:
           head.next = res
           res = head
       head = rest
    
    return (res, tail)
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def reverse_continuous_even_elements(head):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS 
    res = (None, None)
    while head != None:
        even_list = (None, None) 
        while head != None and head.val % 2 == 0:
            rest = head.next
            head.next = None
            even_list = add_to_tail(even_list, head)
            head = rest       

        #print(even_list)
        if even_list[0] != None:
            reverese_even_elements_list = reverse_list(even_list[0])
            res = append_list(res, reverese_even_elements_list)
        if head != None:
            rest = head.next
            head.next = None
            res = add_to_tail(res, head)
       
        head = rest
 
    return res[0]
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS            
