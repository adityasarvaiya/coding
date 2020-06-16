from crio.ds.List.ListNode import ListNode

class DoublyLinkedListNode:
    def __init__(self, x, p= None,n= None):
        self.val = x
        self.prev = p
        self.next = n

# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
def convertToDoublyLinkedList(head):
    result = None
    current = None
    if head == None:
        return result
    while head != None:
        if result == None:
            result = DoublyLinkedListNode(head.val)
            current = result
        else:
            current.next = DoublyLinkedListNode(head.val, current, None)
            current = current.next
        head = head.next
    current.next = result
    result.prev  = current
    return result
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
'''
# Definition for ListNode
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
'''
def doublyLinkedCircularList(head):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    result = convertToDoublyLinkedList(head)
    return result

# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS