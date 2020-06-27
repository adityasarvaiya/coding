from crio.ds.List.ListNode import *

def middle(head):
    slow=fast=head
    while fast.next!=None and fast.next.next!=None:
        slow=slow.next
        fast=fast.next.next
    return slow

def reverse_list(head):
    previous=None
    current=head
    while current:
        temp=current.next
        current.next=previous
        previous=current
        current=temp
    return previous

def is_palindrome_list(head):
    middle_node=middle(head)
    second=rev=reverse_list(middle_node.next)
    first=head
    palindrome=True
    while second:
        if first.val!=second.val:
            palindrome=False
            break
        first=first.next
        second=second.next
    middle_node.next=reverse_list(rev)
    return palindrome