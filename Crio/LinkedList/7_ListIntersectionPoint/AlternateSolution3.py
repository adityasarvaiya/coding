def find_meeting_point(head):
    if head == None:
        return None
    fast = head.next
    if fast:
        fast = fast.next
    slow = head.next

    while fast and slow:
        if fast == slow:
            return fast
        slow = slow.next
        fast = fast.next
        if not fast:
            return None
        fast = fast.next
    return None

def find_intersection_point(meetingPoint, lst2):
    iterator1 = lst2
    iterator2 = meetingPoint

    while(iterator1 != iterator2):
        iterator1 = iterator1.next
        iterator2 = iterator2.next
    
    return iterator1

def get_intersection_node(lst1, lst2):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    iterator = lst1

    if not iterator:
        return None

    while (iterator.next != None):
        iterator = iterator.next

    iterator.next = lst1

    meetingPoint = find_meeting_point(lst2)
    
    if not meetingPoint:
        return None

    return find_intersection_point(meetingPoint, lst2)

# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS            
