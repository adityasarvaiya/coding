class ListNode:
	def __init__(self, x):
		self.val = x
		self.next = None

def removeNthNodeFromEndOflist(head, k):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    n=1
    node = head

    while(node.next!=None):
        node = node.next
        n+=1
    
    node = head
    for i in range(n-k-1):
        node = node.next
    
    if(k==n):
        head = head.next
    elif(k==1):
        node.next = None
    else:
        node.next = node.next.next

    return head
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS