from crio.ds.List.ListNode import *

# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
def find_first_meeting_point(head):
    slow = head.next 
    fast = head.next.next

    while (fast != None) and (fast.next != None):
        if slow == fast:
            break
        fast = fast.next.next
        slow = slow.next

    if slow != fast:
        return None
   
    return slow

def get_next_meeting_point(slow, fast):
    while fast != slow:
        fast = fast.next
        slow = slow.next

    return fast 
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def get_loop_start(head):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    if head == None or head.next == None:
       return None

    first_meeting_point = find_first_meeting_point(head) 
    
    return get_next_meeting_point(head, first_meeting_point)
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS


