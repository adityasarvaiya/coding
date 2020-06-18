'''
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
'''
from crio.ds.List import ListNode

def hasCycle(head):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    if head == None or head.next == None:
        return "false"
    slow = head
    fast = head.next
    while slow != head:
        if fast == None or fast.next == None:
            return "false"
        slow = slow.next
        fast = fast.next.next
    return "true"
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__ == '__main__':
    nums = input().split()
    nums = [int(i) for i in nums]
    pos = int(input())
    head = ListNode.generateLinkedListWithCycle(nums, pos)
    result = hasCycle(head)
    print(result)

