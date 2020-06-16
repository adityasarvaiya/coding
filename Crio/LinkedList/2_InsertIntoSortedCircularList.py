from crio.ds.List.ListNode import ListNode

'''
# Definition for ListNode
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
'''
def insertIntoSortedCircularList(head, insertVal):
    newNode = ListNode(insertVal)
    if head == None :
        head = newNode
        head.next = head
        return head
    currNode = head
    nextNode = currNode.next
    while nextNode != head :
        #Case 1 : should be at the beginning
        if currNode.val>nextNode.val and insertVal <= nextNode.val :
                currNode.next = newNode
                newNode.next = nextNode
                return head
        #Case 2 : should be between stuff
        if insertVal >=currNode.val and insertVal<=nextNode.val:
                currNode.next = newNode
                newNode.next = nextNode
                return head
        #Case 3 : should be at the end
        if currNode.val>nextNode.val and insertVal > currNode.val :
                currNode.next = newNode
                newNode.next = nextNode
                return head
        currNode = nextNode
        nextNode = nextNode.next
    #end of traversal
    currNode.next = newNode
    newNode.next = head
    return head
