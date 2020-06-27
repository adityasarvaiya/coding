from crio.ds.List.ListNode import *
def is_palindrome_list(head):
    if(head==None):
        return True
    middle=findMiddle(head)
    reverseHead=doReverse(middle.next)
    x=True
    first=head
    second=reverseHead
    while(second!=None):
        if(first.val!=second.val):
            x=False
            break
        first=first.next
        second=second.next
    middle.next=doReverse(reverseHead)
    return x

def findMiddle(head):
    if(head==None):
        return head
    start=head
    end=head
    while(end.next!=None and end.next.next!=None):
        start=start.next
        end=end.next.next
    return start

def doReverse(head):
    prev=None
    temp=None
    current=head
    while(current!=None):
        temp=current.next
        current.next=prev
        prev=current
        current=temp
    return prev
