from crio.ds.List.ListNode import ListNode

'''
# Definition for ListNode
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
'''
def insertIntoSortedCircularList(head, insertVal):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    newNode = ListNode(insertVal)

    if head == None:
        newNode.next = newNode
        return newNode

    prev, curr = head, head.next
    toInsert = False

    while True:
        
        if prev.val <= insertVal and insertVal <= curr.val:
            toInsert = True
        elif prev.val > curr.val:
            if insertVal >= prev.val or insertVal <= curr.val:
                toInsert = True

        if toInsert:
            prev.next = newNode
            newNode.next = curr
            return head

        prev, curr = curr, curr.next
        if prev == head:
            break

    prev.next = newNode
    newNode.next = curr
    return head
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS