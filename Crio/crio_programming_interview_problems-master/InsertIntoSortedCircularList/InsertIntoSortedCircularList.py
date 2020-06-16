from crio.ds.List.ListNode import *
from Solution import insertIntoSortedCircularList

# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def isCircularList(head):
    if not head:
        return False
    fast = head
    slow = head

    while True:
        if not slow.next:
            return False
        slow = slow.next
        if not fast.next or not fast.next.next:
            return False
        fast = fast.next.next

        if fast == slow:
            return head == slow
    

def main():
    n = int(input())
    if n > 0:
        lst = list(map(int,input().strip().split()))
    insertVal = int(input())


    head = None
    if n > 0:
        head = generateLinkedListWithCycle(lst, 0)

    result = insertIntoSortedCircularList(head, insertVal)

    if not isCircularList(result):
        print("Not a circular linked list")
        return

    head = result
    while head.next != result:
        head = head.next
    head.next = None

    result_list = extractList(result)
    print(*result_list)

if __name__ == '__main__':
    main()