from Solution import *
from crio.ds.List.ListNode import *

# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
def isCircularLinkedList(head):
    if head == None:
        return True
    slow = head
    fast = head
    while True:
        if slow.next == None:
            return False
        slow = slow.next
        if fast.next == None or fast.next.next == None:
            return False
        fast = fast.next.next
        if fast == slow:
            return slow == head

    return False


def printNode(node):
    if node == None:
        print("null", end = "")
        return
    print(node.val, end="")

def printDoublyLinkedCircularList(head):
    if head == None:
        return
    current = head
    while True:
        printNode(head.prev)
        print("",end = " ")
        printNode(head)
        print("",end = " ")
        printNode(head.next)
        print("")
        head = head.next
        if head == current:
            break

def main():
    n=int(input())
    if n==0:
        return
    lis = list(map(int,input().split()))

    head  =  createList(lis)
    result = doublyLinkedCircularList(head)
    if not isCircularLinkedList(result):
        print("Not a circular list")
        return
    printDoublyLinkedCircularList(result)
if __name__ == "__main__":
    main()
