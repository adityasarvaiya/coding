# Definition of ListNode
class ListNode:
	def __init__(self, x):
		self.val = x
		self.next = None

def addTwoNumbers(l1, l2):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    node = ListNode((l1.val+l2.val)%10)
    head = node
    c=(l1.val+l2.val)//10
    l1 = l1.next
    l2 = l2.next
    while(l1!=None or l2!=None):
        val = c
        if(l1!=None):
            val+=l1.val
            l1 = l1.next
        if(l2!=None):
            val+=l2.val
            l2 = l2.next

        node.next = ListNode((val)%10)
        node = node.next
        c=(val)//10
    if(c):
        node.next = ListNode(c)
    return head
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS